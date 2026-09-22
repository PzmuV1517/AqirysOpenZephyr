#!/usr/bin/env python3
"""Turn the Ghidra dump into a subsystem-split source tree.

Reads the firmware.c / meta.tsv / globals.tsv produced by CodebaseFw.java and
writes src/<subsystem>.c plus include/firmware_globals.h.

Naming policy
-------------
Every symbol keeps its address as a suffix. That is deliberate: this is
reverse-engineered source, and a name like `ble_g_40d0cc` stays checkable
against the binary, whereas inventing `ble_conn_state` would assert a meaning
nobody has verified. Prefixes come from the call graph, suffixes from the
image; neither is a guess.
"""
import collections, csv, re, struct, sys, pathlib

SUBSYS = [
 ("boot",  "Boot, vectors and reset",    r"reset_handler|_vector|_exc_stub|stack_integrity|reset_reason"),
 ("ota",   "Firmware update (OAD/OTA)",  r"oad|upgrade|imghdr|\bboot"),
 ("flash", "Flash and NVM storage",      r"flash|eeprom|nvds|erase|sector|save_|_save|macro|profile"),
 ("usb",   "USB and HID",                r"usb|hid|report|descript|endpoint|\bep\d"),
 ("rf24",  "2.4 GHz RF link",            r"rf_mode|_24g|24_|\b24g|dongle|channel|hop|rssi|simu"),
 ("ble",   "Bluetooth LE",               r"appm|app_ble|gap|gatt|ble_|adv|pair|bond|app_sec|ancs|prf_|hogpd|rwble|rwip|l2c|link"),
 ("input", "Mouse input (sensor, keys)", r"sensor|dpi|button|key_|_key|wheel|click|debounce|mouse"),
 ("led",   "LED and OLED",               r"led|oled|light|rgb|breath|bright"),
 ("power", "Power and battery",          r"batt|charg|power|sleep|wake|_adc|pmu|volt|chrg"),
 ("timer", "Timers and scheduling",      r"timer|ke_msg|ke_task|sched|delay|tick"),
 ("dbg",   "Debug output",               r"dbg_printf|printf|uart"),
 ("rom",   "ROM entry points",           r"^rom_"),
]
PREFIX = {s[0]: s[0] for s in SUBSYS}
TITLE  = {s[0]: s[1] for s in SUBSYS}
MISC   = "misc"
TITLE[MISC] = "Unclassified"


def seed(name, strings):
    hay = (name + " " + strings).lower()
    for pre, _t, pat in SUBSYS:
        if re.search(pat, hay):
            return pre
    return None


def classify(meta):
    """Seed from names/strings, then propagate along the call graph."""
    sub = {}
    for r in meta.values():
        g = seed(r["name"], r.get("strings") or "")
        if g:
            sub[r["name"]] = g
    fixed = {"rom", "dbg"}
    for _ in range(12):
        changed = 0
        for r in meta.values():
            if r["name"] in sub:
                continue
            votes = collections.Counter()
            for rel, w in (("callers", 3), ("callees", 1)):
                for other in filter(None, r.get(rel, "").split(";")):
                    g = sub.get(other)
                    if g and g not in fixed:
                        votes[g] += w
            if votes:
                sub[r["name"]] = votes.most_common(1)[0][0]
                changed += 1
        if not changed:
            break
    return sub


def main(indir, root):
    indir, root = pathlib.Path(indir), pathlib.Path(root)
    meta = {}
    with open(indir / "meta.tsv") as f:
        for r in csv.DictReader(f, delimiter="\t"):
            if r.get("name"):                      # skip rows broken by embedded tabs
                r["strings"] = r.get("strings") or ""
                r["callers"] = r.get("callers") or ""
                r["callees"] = r.get("callees") or ""
                meta[r["name"]] = r
    HEX = re.compile(r"^[0-9a-fA-F]+$")
    globs = []
    with open(indir / "globals.tsv") as f:
        for r in csv.DictReader(f, delimiter="\t"):
            # Ghidra also reports stack-frame refs like "Stack[-0x218]"; not globals.
            if HEX.match(r["addr"]):
                globs.append(r)

    # address -> symbol, used to fold "ro_38ff0 + 0x2d" back into a real name
    symmap, strspan = {}, []
    sp = indir / "strings.tsv"
    if sp.exists():
        with open(sp) as f:
            for r in csv.DictReader(f, delimiter="\t"):
                a = int(r["addr"], 16)
                if r["label"]:
                    symmap[a] = r["label"]
                    strspan.append((a, a + len(r["content"]), r["label"]))
    for r in globs:
        symmap.setdefault(int(r["addr"], 16), r["name"])
    strspan.sort()

    sub = classify(meta)

    # ---- rename map -------------------------------------------------
    ren = {}
    for name, r in meta.items():
        g = sub.get(name, MISC)
        if name.startswith("FUN_"):
            ren[name] = f"{g}_sub_{name[4:].lstrip('0') or '0'}"

    gsub = {}
    for r in globs:
        users = [u for u in r["users"].split(";") if u]
        votes = collections.Counter(sub.get(u, MISC) for u in users)
        if not votes:
            continue
        top, cnt = votes.most_common(1)[0]
        tot = sum(votes.values())
        g = top if cnt / tot >= 0.8 else "shared"
        gsub[r["name"]] = g
        old, region = r["name"], r["region"]
        addr = old.split("_")[-1]
        if region == "periph":
            ren[old] = f"reg_{addr}"                 # peripherals are global by nature
        elif region == "romdata":
            ren[old] = f"rom_ro_{addr}"
        elif region == "sram":
            ren[old] = f"{g}_g_{addr}"
        else:
            ren[old] = f"{g}_ro_{addr}"

    # ---- fold literal-pool arithmetic into real symbols ----------------
    # In Ghidra's C a data symbol denotes its VALUE, so "ro_38ff0 + 0x2d" means
    # (word stored at 0x38ff0) + 0x2d. ARM reaches far data that way: the literal
    # pool holds a base and the code indexes off it. Resolving therefore has to
    # read the stored word, never the literal's own address.
    src = (indir / "firmware.c").read_text(errors="replace")

    img = (root / "firmware" / "zephyr2_flat.bin").read_bytes()
    BASE = 0x287A0

    def u32(a):
        o = a - BASE
        return struct.unpack_from("<I", img, o)[0] if 0 <= o <= len(img) - 4 else None

    stats = collections.Counter()

    def fold(m):
        lit, off = int(m.group(1), 16), int(m.group(2), 16)
        v = u32(lit)
        if v is None or not (BASE <= v < BASE + len(img)):
            stats["not-a-pointer"] += 1          # genuine arithmetic on a value
            return m.group(0)
        tgt = v + off
        if tgt in symmap:
            stats["exact"] += 1
            return symmap[tgt]
        for s0, s1, lab in strspan:
            if s0 < tgt < s1:
                stats["interior"] += 1
                return f"({lab} + {tgt - s0})"
        stats["unresolved"] += 1
        return m.group(0)

    src = re.sub(r"\b(?:ro|romdata)_([0-9a-f]+) \+ (0x[0-9a-f]+)\b", fold, src)
    print("literal-pool folding:", dict(stats))

    # ---- apply the subsystem rename map --------------------------------
    if ren:
        pat = re.compile(r"\b(" + "|".join(sorted(map(re.escape, ren), key=len, reverse=True)) + r")\b")
        src = pat.sub(lambda m: ren[m.group(1)], src)

    # ---- split into per-subsystem blocks ---------------------------
    parts = re.split(r"(?m)^/\* ={70,}\n", src)
    blocks = collections.defaultdict(list)
    for p in parts[1:]:
        m = re.match(r" \* (\S+)\s+@ 0x([0-9a-fA-F]+)", p)
        if not m:
            continue
        name, addr = m.group(1), m.group(2).lower()
        orig = next((o for o, n in ren.items() if n == name), name)
        g = sub.get(orig, sub.get(name, MISC))
        blocks[g].append((addr, name, "/* " + "=" * 74 + "\n" + p.rstrip() + "\n"))

    (root / "src").mkdir(parents=True, exist_ok=True)
    (root / "include").mkdir(parents=True, exist_ok=True)

    order = [s[0] for s in SUBSYS] + [MISC]
    written = []
    for g in order:
        if g not in blocks:
            continue
        blocks[g].sort()
        out = [f"/* {TITLE[g]}",
               " *",
               " * Recovered from the AQIRYS Zephyr 2 application image.",
               " * This is reverse-engineered reference source: it documents behaviour,",
               " * it is not a buildable translation unit. Types are Ghidra inference.",
               " */",
               '#include "zephyr.h"',
               '#include "firmware_globals.h"',
               ""]
        for _a, _n, text in blocks[g]:
            out.append(text)
        path = root / "src" / f"{g}.c"
        path.write_text("\n".join(out))
        written.append((g, len(blocks[g]), path))

    # ---- globals header --------------------------------------------
    h = ["/* firmware_globals.h - globals recovered from the image.",
         " *",
         " * Address suffixes are kept on purpose so every symbol stays checkable",
         " * against the binary. Prefixes come from which subsystem uses them.",
         " * Types are placeholders: width is known, meaning mostly is not.",
         " */",
         "#ifndef FIRMWARE_GLOBALS_H",
         "#define FIRMWARE_GLOBALS_H",
         "",
         '#include <stdint.h>',
         ""]
    byreg = collections.defaultdict(list)
    for r in globs:
        byreg[r["region"]].append(r)
    REG_DOC = {
        "sram":    "SRAM (0x00400000+) - mutable state",
        "rodata":  "read-only data inside the application image",
        "periph":  "peripheral registers (0x00800000+)",
        "romdata": "data owned by mask ROM, below the image",
    }
    for region in ("periph", "sram", "rodata", "romdata"):
        rows = byreg.get(region, [])
        if not rows:
            continue
        h += ["", f"/* ---- {REG_DOC[region]}  ({len(rows)} symbols) ---- */"]
        for r in sorted(rows, key=lambda x: x["addr"]):
            nm = ren.get(r["name"], r["name"])
            rw = f"r{r['reads']}/w{r['writes']}"
            kind = "volatile uint32_t" if region == "periph" else "uint32_t"
            h.append(f"extern {kind} {nm};".ljust(52) + f"/* 0x{r['addr'].upper()}  {rw} */")
    h += ["", "#endif /* FIRMWARE_GLOBALS_H */"]
    (root / "include" / "firmware_globals.h").write_text("\n".join(h))

    # ---- symbol map -------------------------------------------------
    with open(root / "analysis" / "symbol_map.tsv", "w") as f:
        f.write("new_name\told_name\tkind\tsubsystem\n")
        for old, new in sorted(ren.items(), key=lambda kv: kv[1]):
            kind = "function" if old.startswith("FUN_") else "global"
            f.write(f"{new}\t{old}\t{kind}\t{gsub.get(old, sub.get(old, ''))}\n")

    print(f"renamed {len(ren)} symbols")
    for g, n, p in written:
        print(f"  {p.relative_to(root)!s:<28} {n:>4} functions   {TITLE[g]}")


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
