#!/usr/bin/env python3
"""Measure the bootloader's CRC over ranges whose contents we know exactly.

Why this exists: the first CRC we read back covered 0x2B00A..0x4C009, which runs
2308 bytes past the end of the image. The content of that tail is whatever the
factory left in flash, so that measurement had two unknowns - the algorithm and
the data - and one equation. No candidate matched, and none could have been
trusted if it had.

Every range here lies entirely inside the installed image, so the bytes are
known from firmware/zephyr2_container.bin. That turns each reading into a clean
equation in one unknown.

Reads only. It issues the bootloader's CRC command and nothing else - no erase,
no write. Reaching the bootloader still costs the usual 16-byte mark at 0x7D000,
and on this hardware the device has been observed returning to the application
on its own afterwards.

    python3 tools/crcprobe.py firmware/zephyr2_container.bin
    python3 tools/crcprobe.py firmware/zephyr2_container.bin -o probe.json
"""
import argparse, json, pathlib, sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import zephyr_flash as zf

FLASH_APP = zf.FLASH_APP


def ranges(n):
    """(name, offset, length) - all inside the image, so contents are known."""
    r = [
        ("header only",        0,      16),
        ("one block",          0,      34),
        ("two blocks",         0,      68),
        ("header + 1 byte",    0,      17),
        ("header + 2 bytes",   0,      18),
        ("header + 3 bytes",   0,      19),
        ("256 bytes",          0,      256),
        ("4 KB",               0,      4096),
        ("offset 16, 16 bytes", 16,    16),
        ("offset 32, 16 bytes", 32,    16),
        ("whole image",        0,      n),
    ]
    return [(nm, o, ln) for nm, o, ln in r if o + ln <= n]


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("container")
    ap.add_argument("-o", "--out", help="write results as JSON for offline analysis")
    ap.add_argument("--gap", type=float, default=0.015)
    ap.add_argument("--yes", action="store_true")
    a = ap.parse_args()

    raw = pathlib.Path(a.container).read_bytes()
    print(f"container {len(raw)} bytes; every probe below is inside it, "
          f"so the bytes are known\n")

    dev = zf.open_bootloader(assume_yes=a.yes)
    out = []
    for name, off, ln in ranges(len(raw)):
        start = FLASH_APP + off
        end = start + ln - 1
        try:
            crc = zf.device_crc(dev, start, end, a.gap)
        except Exception as e:
            print(f"  {name:22} 0x{start:06X}..0x{end:06X} {ln:>7}B  ERROR {e}")
            continue
        print(f"  {name:22} 0x{start:06X}..0x{end:06X} {ln:>7}B  -> 0x{crc:08X}")
        out.append({"name": name, "offset": off, "length": ln,
                    "start": start, "end": end, "crc": crc,
                    "data": raw[off:off + ln].hex()})

    if a.out:
        pathlib.Path(a.out).write_text(json.dumps(out, indent=1))
        print(f"\nwrote {len(out)} readings -> {a.out}")

    print("\nThe device is in the bootloader. Restore it with:")
    print(f"    python3 tools/zephyr_flash.py flash {a.container}")
    print("(on this hardware it has also been seen returning to the application "
          "on its own)")


if __name__ == "__main__":
    main()
