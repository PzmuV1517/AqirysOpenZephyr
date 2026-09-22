#!/usr/bin/env python3
"""Regroup the raw Ghidra dump into a subsystem-ordered, navigable C file."""
import csv, re, sys, pathlib

SUBSYS = [
 ("Boot, vectors and reset",   r"reset_handler|_vector|_exc_stub|stack_integrity|reset_reason"),
 ("Firmware update (OAD/OTA)", r"oad|upgrade|imghdr|\bboot"),
 ("Flash and NVM storage",     r"flash|eeprom|nvds|erase|sector|save_|_save|macro|profile"),
 ("USB and HID",               r"usb|hid|report|descript|endpoint|\bep\d"),
 ("2.4 GHz RF link",           r"rf_mode|_24g|24_|\b24g|dongle|channel|hop|rssi|simu"),
 ("Bluetooth LE",              r"appm|app_ble|gap|gatt|ble_|adv|pair|bond|app_sec|ancs|prf_|hogpd|rwble|rwip|l2c|link"),
 ("Mouse input (sensor, keys)",r"sensor|dpi|button|key_|_key|wheel|click|debounce|mouse"),
 ("LED and OLED",              r"led|oled|light|rgb|breath|bright"),
 ("Power and battery",         r"batt|charg|power|sleep|wake|_adc|pmu|volt|chrg"),
 ("Timers and scheduling",     r"timer|ke_msg|ke_task|sched|delay|tick"),
 ("Debug output",              r"dbg_printf|printf|uart"),
 ("ROM entry points",          r"^rom_"),
]

def classify(name, strings):
    hay = (name + " " + strings).lower()
    for label, pat in SUBSYS:
        if re.search(pat, hay):
            return label
    return "Unclassified"

def main(indir, outfile):
    indir = pathlib.Path(indir)
    meta = {}
    with open(indir / "meta.tsv") as f:
        for r in csv.DictReader(f, delimiter="\t"):
            meta[r["addr"].lower()] = r

    src = (indir / "firmware.c").read_text(errors="replace")
    # split on the banner we emitted
    parts = re.split(r"(?m)^/\* ={70,}\n", src)
    blocks = []
    for p in parts[1:]:
        m = re.match(r" \* (\S+)\s+@ 0x([0-9a-fA-F]+)", p)
        if not m:
            continue
        name, addr = m.group(1), m.group(2).lower()
        blocks.append((addr, name, "/* " + "=" * 74 + "\n" + p.rstrip() + "\n"))

    # --- seed from name + own debug strings ---
    sub = {}
    for addr, name, text in blocks:
        r = meta.get(addr, {})
        g = classify(name, r.get("strings", ""))
        if g != "Unclassified":
            sub[name] = g

    # --- propagate along the call graph: a helper belongs where its callers live ---
    by_name = {}
    for addr, name, text in blocks:
        by_name[name] = meta.get(addr, {})
    FIXED = {"ROM entry points", "Debug output"}
    for _ in range(12):
        changed = 0
        for name, r in by_name.items():
            if name in sub:
                continue
            votes = {}
            for rel, w in (("callers", 3), ("callees", 1)):
                for other in filter(None, r.get(rel, "").split(";")):
                    g = sub.get(other)
                    if g and g not in FIXED:
                        votes[g] = votes.get(g, 0) + w
            if votes:
                sub[name] = max(votes, key=votes.get)
                changed += 1
        if not changed:
            break

    groups = {}
    for addr, name, text in blocks:
        r = meta.get(addr, {})
        g = sub.get(name) or classify(name, r.get("strings", ""))
        groups.setdefault(g, []).append((addr, name, int(r.get("size", 0)), text))
    for g in groups:
        groups[g].sort()

    order = [s[0] for s in SUBSYS] + ["Unclassified"]
    order = [g for g in order if g in groups]

    out = []
    out.append("/*" + "=" * 76)
    out.append(" * AQIRYS Zephyr 2 - decompiled application firmware")
    out.append(" *")
    out.append(" * Chip      : Beken BLE SoC, ARMv5TE (ARM968-class), ARM + Thumb")
    out.append(" * Image     : 125030 bytes, linked at 0x000287A0")
    out.append(" * In flash  : container written at 0x0002B00A; the XIP engine strips a")
    out.append(" *             2-byte CRC every 32 bytes, so flash 0x2B01A -> CPU 0x287A0")
    out.append(" * Memory    : 0x00000000 mask ROM / bootloader (BLE stack lives here)")
    out.append(" *             0x000287A0 this image")
    out.append(" *             0x00400000 SRAM")
    out.append(" *")
    out.append(" * Reading this file")
    out.append(" * -----------------")
    out.append(" *   Functions are grouped by subsystem, then sorted by address.")
    out.append(" *   Each function carries its callers, callees and any debug strings it")
    out.append(" *   references - those strings are the firmware's own and are usually the")
    out.append(" *   fastest way to work out what a function does.")
    out.append(" *")
    out.append(" *   name()      - recovered from the firmware's debug strings")
    out.append(" *   rom_XXXXX() - call into mask ROM; body is not in this image")
    out.append(" *   FUN_xxxxx() - no name recoverable")
    out.append(" *   str_...     - a string literal, named after its own contents")
    out.append(" *   dbg_printf  - the firmware's debug print routine")
    out.append(" *")
    out.append(" *   Types are Ghidra's inference, not the original source. undefined/uVar")
    out.append(" *   names mean the decompiler could not deduce anything better.")
    out.append(" */")
    out.append("")
    out.append("/*" + "=" * 76)
    out.append(" * CONTENTS")
    out.append(" *")
    tot = sum(len(groups[g]) for g in order)
    for g in order:
        out.append(f" *   {g:<32} {len(groups[g]):>4} functions")
    out.append(f" *   {'TOTAL':<32} {tot:>4}")
    out.append(" */")
    out.append("")

    for g in order:
        out.append("")
        out.append("/*" + "#" * 76)
        out.append(f" * {g.upper()}  ({len(groups[g])} functions)")
        out.append(" *")
        for addr, name, size, _ in groups[g]:
            out.append(f" *   0x{addr.upper():>8}  {name}" + (f"  ({size} B)" if size else ""))
        out.append(" " + "#" * 76 + "*/")
        out.append("")
        for _, _, _, text in groups[g]:
            out.append(text)

    pathlib.Path(outfile).write_text("\n".join(out))
    print(f"{tot} functions in {len(order)} sections -> {outfile}")
    for g in order:
        print(f"  {g:<32} {len(groups[g]):>4}")

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
