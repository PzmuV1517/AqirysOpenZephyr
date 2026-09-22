#!/usr/bin/env python3
"""macOS/Linux firmware flasher for the AQIRYS Zephyr (Beken BLE mouse).

Speaks the same protocol as the vendor's Windows Update.exe: Beken vendor HCI
commands (opcode 0xFCE0) tunnelled over 65-byte USB HID reports. See
include/zephyr.h for the wire format.

Safer than the vendor tool in three ways:

  * it erases only the range it is about to write. The vendor tool erases to
    0x30000 + image_length, overshooting the image end by ~21 KB;
  * it verifies the flash with the bootloader's own CRC command BEFORE
    rebooting, and refuses to commit on a mismatch. The vendor tool reads the
    CRC back and never compares it to anything;
  * `verify` performs that check on its own and writes nothing at all.

Commands
    info                 enumerate and report. Genuinely read-only.
    verify  <container>  read back the flash CRC and compare.
    flash   <container>  erase, write, verify, then reboot

What each one writes
    info    nothing at all.
    verify  nothing to the application image, but reaching the bootloader means
            asking the running firmware to reboot into it, and that handler
            (app_usb_upgrade_start) stamps 16 bytes at flash 0x7D000 first. It
            is exactly what the vendor tool does on every update, and it is
            skipped entirely if the device is already in the bootloader - but
            it is a flash write, so verify is not "read-only".
    flash   erases and rewrites the application region.
"""
import argparse, struct, sys, time, zlib, pathlib

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import fwtool

try:
    import hid
except ImportError:
    sys.exit("needs hidapi bindings:  pip install hid   (or: brew install hidapi)")

APP_VID, APP_PID = 0x1D57, 0xFA61
BOOT_VID, BOOT_PID = 0xA745, 0x0033
CFG_USAGE_PAGE, CFG_USAGE = 0x0B, 0x00

FLASH_APP = 0x2B00A
FLASH_MACRO_BAK = 0x52000

REPORT_ENTER_BL = 0x10
ENTER_BL_ARG = 0x08

CMD_WRITE_4K, CMD_REBOOT, CMD_ERASE, CMD_CRC = 0x07, 0x0E, 0x0F, 0x10
ERASE_4K, ERASE_64K = 0x20, 0xD8
REBOOT_MAGIC = 0xA5
CHUNK = 64

_ECHO_OFF: dict[int, int] = {}   # cmd -> observed address-echo offset


# ---------------------------------------------------------------- framing
def cmd_short(cmd: int, payload: bytes) -> bytes:
    return bytes([0x01, 0xE0, 0xFC, len(payload) + 1, cmd]) + payload


def cmd_long(cmd: int, payload: bytes) -> bytes:
    n = len(payload) + 1
    return bytes([0x01, 0xE0, 0xFC, 0xFF, 0xF4]) + struct.pack("<H", n) + bytes([cmd]) + payload


def send(dev, stream: bytes, gap: float) -> None:
    """Split across 65-byte output reports: [0x00 report id][64 bytes], 0xFF padded."""
    for off in range(0, len(stream), CHUNK):
        part = stream[off:off + CHUNK]
        dev.write(bytes([0x00]) + part + b"\xff" * (CHUNK - len(part)))
        if gap:
            time.sleep(gap)


def read_resp(dev, timeout_ms: int = 2000) -> bytes:
    data = bytes(dev.read(CHUNK + 1, timeout_ms))
    # hidapi prepends the report id only for numbered reports; tolerate both
    if data[:2] != b"\x04\x0e" and data[1:3] == b"\x04\x0e":
        data = data[1:]
    return data


def expect(resp: bytes, cmd: int, addr: int | None, what: str) -> None:
    if len(resp) < 10:
        raise RuntimeError(f"{what}: reply too short ({len(resp)} bytes): {resp.hex()}")
    if resp[:2] != b"\x04\x0e":
        raise RuntimeError(f"{what}: not an HCI Command Complete: {resp[:12].hex()}")
    if resp[2] == 0xFF:                       # long form
        # ... F4 <len16> <cmd> <status> <echoed params>
        got_cmd, body = resp[9], resp[10:]
    else:                                     # short form
        got_cmd, body = resp[6], resp[7:]
    if got_cmd != cmd:
        raise RuntimeError(f"{what}: expected cmd 0x{cmd:02X}, got 0x{got_cmd:02X}")
    if addr is not None:
        # body[0] is a status byte. Erase then echoes <opcode><addr32>, write
        # echoes <addr32>. Confirmed by running the vendor Update.exe against a
        # logging hidapi shim: it rejects the reply if the address sits anywhere
        # else. See tools/shim/.
        # Expected layout is <status><params>, so the address echo sits at +2
        # for erase and +1 for write. That was confirmed negatively (the vendor
        # tool rejects a reply with it anywhere else) but never positively, so
        # rather than bet on it we search the first few offsets and latch onto
        # whichever one the device actually uses. Self-calibrating on the first
        # reply, strict from then on.
        global _ECHO_OFF
        want = struct.pack("<I", addr)
        expected = 2 if cmd == CMD_ERASE else 1
        known = _ECHO_OFF.get(cmd)
        order = [known] if known is not None else [expected] + [o for o in range(5) if o != expected]
        for off in order:
            if off is None or len(body) < off + 4:
                continue
            if body[off:off + 4] == want:
                if known is None:
                    _ECHO_OFF[cmd] = off
                    if off != expected:
                        print(f"  note: cmd 0x{cmd:02X} echoes its address at +{off}, "
                              f"not +{expected}; using +{off} from here on")
                return
        raise RuntimeError(
            f"{what}: no echo of 0x{addr:X} anywhere in the reply body "
            f"{body[:8].hex()} - refusing to continue")


# ---------------------------------------------------------------- device
def find(vid, pid, need_cfg_iface):
    for d in hid.enumerate(vid, pid):
        if need_cfg_iface and not (d.get("usage_page") == CFG_USAGE_PAGE
                                   and d.get("usage") == CFG_USAGE):
            continue
        return d
    return None


def open_bootloader(timeout=15.0, assume_yes=False):
    """Return an open handle to the bootloader, asking the app to reboot if needed."""
    d = find(BOOT_VID, BOOT_PID, False)
    if not d:
        app = find(APP_VID, APP_PID, True)
        if not app:
            sys.exit("no Zephyr found (neither application nor bootloader)")
        print(f"application present, bcdDevice 0x{app['release_number']:04X}")
        print("\nTo reach the bootloader the running firmware has to be asked to reboot")
        print("into it. That handler stamps 16 bytes at flash 0x7D000 before resetting -")
        print("the same thing the vendor updater does every time. It does not touch the")
        print("application image, but it is a flash write, and note:")
        print()
        print("  * macros live at 0x7D000 as 0x80-byte records (FLASH_RD_Macro), so the")
        print("    mark lands on the first 16 bytes of MACRO SLOT 0. If you have a macro")
        print("    recorded there it will be corrupted. The vendor updater does this too.")
        print("  * the write is read-modify-write over a 4 KB sector, so losing power")
        print("    part-way can corrupt macro storage. Use a direct port, not a hub.")
        if not assume_yes and input("proceed? type 'yes': ").strip() != "yes":
            sys.exit("aborted - nothing was written")
        h = hid.device()
        h.open_path(app["path"])
        h.send_feature_report(bytes([REPORT_ENTER_BL, ENTER_BL_ARG] + [0] * 6))
        h.close()
        deadline = time.time() + timeout
        while time.time() < deadline:
            time.sleep(0.3)
            d = find(BOOT_VID, BOOT_PID, False)
            if d:
                break
        else:
            sys.exit(
                "\nDevice never reappeared as the bootloader.\n\n"
                "IMPORTANT: the mark at 0x7D000 has already been written and the device\n"
                "has already reset, so it is most likely sitting in DFU right now even\n"
                "though this machine cannot see it.\n\n"
                "Try, in order:\n"
                "  1. re-run this command - it will pick up a bootloader that is already\n"
                "     present and skip the enter step entirely;\n"
                "  2. unplug, replug, wait a few seconds, re-run;\n"
                "  3. a different USB port, directly on the machine rather than a hub;\n"
                "  4. grant Input Monitoring to your terminal and re-run;\n"
                "  5. the vendor Update.exe on a Windows machine. It speaks the same\n"
                "     protocol and is in this repo under 'Firmware update AQIRYS...'.\n"
                "     That is the fallback if macOS will not enumerate the bootloader.\n")
    h = hid.device()
    h.open_path(d["path"])
    print(f"bootloader open (VID 0x{BOOT_VID:04X} PID 0x{BOOT_PID:04X})")
    return h


# ---------------------------------------------------------------- ops
def device_crc(dev, start, end, gap):
    send(dev, cmd_short(CMD_CRC, struct.pack("<II", start, end)), gap)
    time.sleep(0.05)
    r = read_resp(dev, 8000)
    expect(r, CMD_CRC, None, "crc")
    return struct.unpack_from("<I", r, 7)[0]


def written_extent(length):
    """Bytes actually written: writes are whole 4K pages, 0xFF padded."""
    return -(-length // 0x1000) * 0x1000


def erase_plan(start, length):
    """4K sectors, using 64K blocks where one lies wholly inside the range.

    The range must cover the WRITTEN extent, not the image length: the last
    write is a full 4096-byte page, so it can run past the image end. Confirmed
    on the captured trace - the vendor writes 33 pages ending at 0x4C009 for a
    132860-byte image whose last byte is at 0x4B705.
    """
    lo = start & ~0xFFF
    hi = (start + written_extent(length) + 0xFFF) & ~0xFFF
    plan, a = [], lo
    while a < hi:
        if a % 0x10000 == 0 and a + 0x10000 <= hi:
            plan.append((a, ERASE_64K, 0x10000))
            a += 0x10000
        else:
            plan.append((a, ERASE_4K, 0x1000))
            a += 0x1000
    return plan


def preflight(container: bytes) -> None:
    hdr = fwtool.parse_header(container)
    if hdr["len_bytes"] != len(container):
        sys.exit(f"header length {hdr['len_bytes']} != file size {len(container)}")
    want = fwtool.image_crc32(container[fwtool.HDR_LEN:])
    got = hdr["crc0"] | (hdr["crc1"] << 16)
    if got != want:
        sys.exit(f"header CRC 0x{got:08X} != computed 0x{want:08X} - rebuild with fwtool/fwpatch")
    fwtool.unpack(container, strict=True)      # every block CRC-16 must verify
    end = FLASH_APP + len(container)
    if end > FLASH_MACRO_BAK:
        sys.exit(f"image would reach 0x{end:X}, past the macro scratch sector "
                 f"at 0x{FLASH_MACRO_BAK:X}")
    print(f"preflight OK: {len(container)} bytes, ver 0x{hdr['ver']:04X}, "
          f"uid {hdr['uid'].decode('latin1')}, header CRC 0x{got:08X}")
    print(f"  occupies 0x{FLASH_APP:X}..0x{end:X}, "
          f"{FLASH_MACRO_BAK - end} bytes clear of 0x{FLASH_MACRO_BAK:X}")


def do_verify(dev, container, gap):
    """Compare the bootloader's CRC against what the flash should now hold.

    The range is the written extent starting at FLASH_APP, so it spans header +
    body + 0xFF padding to the page boundary - not the body alone. Taken from
    the captured vendor trace: 0x0002B00A..0x0004C009 for a 132860-byte image,
    which is start + 33*4096 - 1.
    """
    ext = written_extent(len(container))
    start, end = FLASH_APP, FLASH_APP + ext - 1
    blob = container.ljust(ext, b"\xff")
    print(f"reading device CRC over 0x{start:X}..0x{end:X} ({ext} bytes) ...")
    got = device_crc(dev, start, end, gap)
    want = fwtool.image_crc32(blob)
    print(f"  device                        0x{got:08X}")
    print(f"  JAMCRC of header+body+padding 0x{want:08X}")
    if got == want:
        print("  MATCH - the flash holds this exact image")
        return True
    # the ROM's CRC32 flavour is not directly observable; say so rather than guess
    alt = {
        "CRC-32 (zlib)": zlib.crc32(blob) & 0xFFFFFFFF,
        "JAMCRC of body only": fwtool.image_crc32(container[fwtool.HDR_LEN:]),
    }
    print("  no match. Other candidates over the same bytes:")
    for k, v in alt.items():
        print(f"    {k:28} 0x{v:08X}{'   <== device' if v == got else ''}")
    print("  Do not trust the flash until one of these is established.")
    return False


def do_flash(dev, container, gap, assume_yes):
    preflight(container)
    if not assume_yes:
        if input("proceed to erase and write? type 'yes': ").strip() != "yes":
            sys.exit("aborted")
    plan = erase_plan(FLASH_APP, len(container))
    print(f"write extent {written_extent(len(container))} bytes "
          f"({-(-len(container) // 0x1000)} pages of 4K)")
    print(f"erasing {len(plan)} regions 0x{plan[0][0]:X}..0x{plan[-1][0] + plan[-1][2]:X}")
    for addr, op, _sz in plan:
        send(dev, cmd_long(CMD_ERASE, bytes([op]) + struct.pack("<I", addr)), gap)
        time.sleep(0.05)
        expect(read_resp(dev, 8000), CMD_ERASE, addr, f"erase 0x{addr:X}")
    print("writing ...")
    for off in range(0, len(container), 0x1000):
        addr = FLASH_APP + off
        page = container[off:off + 0x1000].ljust(0x1000, b"\xff")
        send(dev, cmd_long(CMD_WRITE_4K, struct.pack("<I", addr) + page), gap)
        time.sleep(0.02)
        expect(read_resp(dev, 8000), CMD_WRITE_4K, addr, f"write 0x{addr:X}")
        print(f"\r  {off + len(page)}/{len(container)}", end="", flush=True)
    print()
    if not do_verify(dev, container, gap):
        sys.exit("VERIFY FAILED - NOT rebooting. The device is still in the bootloader; "
                 "re-run flash to try again.")
    print("rebooting")
    for _ in range(3):
        send(dev, cmd_short(CMD_REBOOT, bytes([REBOOT_MAGIC])), gap)
        time.sleep(0.1)
    print("done")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["info", "verify", "flash"])
    ap.add_argument("container", nargs="?")
    ap.add_argument("--gap", type=float, default=0.015, help="inter-report delay (vendor uses 15 ms)")
    ap.add_argument("--yes", action="store_true")
    a = ap.parse_args()

    if a.command == "info":
        print("read-only: this enumerates USB descriptors and writes nothing.\n")
        any_found = False
        for label, (v, p) in {"application": (APP_VID, APP_PID),
                              "bootloader": (BOOT_VID, BOOT_PID)}.items():
            ds = hid.enumerate(v, p)
            print(f"{label} (VID 0x{v:04X} PID 0x{p:04X}): "
                  f"{len(ds)} interface(s)" if ds else
                  f"{label} (VID 0x{v:04X} PID 0x{p:04X}): not present")
            any_found = any_found or bool(ds)
            for d in ds:
                up, us = d.get("usage_page"), d.get("usage")
                tag = "  <-- config interface" if (up == CFG_USAGE_PAGE and us == CFG_USAGE) else ""
                print(f"    usage_page 0x{up:04X} usage 0x{us:04X} "
                      f"iface {d.get('interface_number')}{tag}")
                print(f"      bcdDevice 0x{d['release_number']:04X}  "
                      f"mfr={d.get('manufacturer_string')!r}  prod={d.get('product_string')!r}")
                print(f"      path {d['path'].decode(errors='replace')}")
        if not any_found:
            print("\nNothing matched. If the mouse is plugged in and this still prints")
            print("nothing, macOS may be withholding HID access - grant Terminal (or your")
            print("IDE) Input Monitoring under System Settings > Privacy & Security.")
        return

    if not a.container:
        sys.exit(f"{a.command} needs a container file")
    container = pathlib.Path(a.container).read_bytes()

    if a.command == "verify":
        preflight(container)
        dev = open_bootloader(assume_yes=a.yes)
        do_verify(dev, container, a.gap)
        print()
        print("=" * 68)
        print("The device is now sitting in the BOOTLOADER and will not work as a")
        print("mouse until it is flashed. Whether it returns to the application on")
        print("its own depends on when the ROM clears the mark at 0x7D000, which we")
        print("do not know - it may come back up in the bootloader again.")
        print()
        print("To restore it, flash the stock image - same bytes it already holds:")
        print(f"    python3 {pathlib.Path(__file__).name} flash {a.container}")
        print("=" * 68)
    else:
        dev = open_bootloader(assume_yes=a.yes)
        do_flash(dev, container, a.gap, a.yes)


if __name__ == "__main__":
    main()
