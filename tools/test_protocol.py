#!/usr/bin/env python3
"""Offline checks for the flasher, pinned to bytes captured from the vendor tool.

The WIRE_* constants below are not derived from our own code: they were logged
while the vendor's Update.exe ran against a fake device (tools/shim/hidapi.c
under wine). If a refactor changes the framing, these fail.

Run: python3 tools/test_protocol.py
"""
import pathlib, struct, sys, zlib

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import fwtool
import zephyr_flash as zf

FAIL = []


def check(name, got, want):
    ok = got == want
    print(f"  {'PASS' if ok else 'FAIL'}  {name}")
    if not ok:
        print(f"        got  {got!r}\n        want {want!r}")
        FAIL.append(name)


# ---- ground truth, logged from the vendor Update.exe -----------------------
WIRE_ENTER_BL = bytes.fromhex("1008000000000000")
# first thing it sends in the bootloader: erase the 4K sector holding 0x2B00A
WIRE_ERASE_FIRST = bytes.fromhex("01e0fcfff406000f2000b00200")

print("framing, against bytes captured from the vendor tool")
check("enter-bootloader feature report",
      bytes([zf.REPORT_ENTER_BL, zf.ENTER_BL_ARG] + [0] * 6), WIRE_ENTER_BL)
check("erase 4K @0x2B000",
      zf.cmd_long(zf.CMD_ERASE, bytes([zf.ERASE_4K]) + struct.pack("<I", 0x2B000)),
      WIRE_ERASE_FIRST)
check("reboot", zf.cmd_short(zf.CMD_REBOOT, bytes([zf.REBOOT_MAGIC])),
      bytes.fromhex("01e0fc020ea5"))
check("crc over a range",
      zf.cmd_short(zf.CMD_CRC, struct.pack("<II", 0x2B00A, 0x4B705)),
      bytes.fromhex("01e0fc09100ab00200" + "05b70400"))
check("write-4K header",
      zf.cmd_long(zf.CMD_WRITE_4K, struct.pack("<I", 0x2B00A) + b"\x00" * 4096)[:12],
      bytes.fromhex("01e0fcfff40510070ab00200"))

print("\nresponse parsing (status byte sits between cmd and params)")
er = bytes.fromhex("040eff01e0fcf407000f00") + bytes([0x20]) + struct.pack("<I", 0x2B000)
zf.expect(er, zf.CMD_ERASE, 0x2B000, "erase")
print("  PASS  erase reply: opcode at [11], address at [12:16]")
wr = bytes.fromhex("040eff01e0fcf406000700") + struct.pack("<I", 0x2B00A)
zf.expect(wr, zf.CMD_WRITE_4K, 0x2B00A, "write")
print("  PASS  write reply: address at [11:15]")
try:
    zf.expect(bytes.fromhex("040eff01e0fcf407000f20") + struct.pack("<I", 0x2B000),
              zf.CMD_ERASE, 0x2B000, "erase")
    print("  FAIL  a reply without the status byte should be rejected")
    FAIL.append("status byte")
except RuntimeError:
    print("  PASS  a reply missing the status byte is rejected")

print("\nfull vendor sequence, decoded from the captured trace")
# 45 commands logged while the vendor tool flashed the stock 132860-byte image
VENDOR_ERASE = [(0x20,0x2B000),(0x20,0x2C000),(0x20,0x2D000),(0x20,0x2E000),
                (0x20,0x2F000),(0xD8,0x30000),(0xD8,0x40000),(0x20,0x50000)]
VENDOR_WRITES = 33
VENDOR_CRC = (0x0002B00A, 0x0004C009)
check("erase ops", len(VENDOR_ERASE), 8)
check("write ops = ceil(132860/4096)", VENDOR_WRITES, -(-132860 // 4096))
check("writes span 0x2B00A..0x4B00A",
      (0x2B00A, 0x2B00A + (VENDOR_WRITES - 1) * 0x1000), (0x2B00A, 0x4B00A))
check("CRC range is start .. start + pages*4096 - 1",
      VENDOR_CRC, (0x2B00A, 0x2B00A + VENDOR_WRITES * 0x1000 - 1))
check("CRC command bytes",
      zf.cmd_short(zf.CMD_CRC, struct.pack("<II", *VENDOR_CRC)),
      bytes.fromhex("01e0fc0910") + bytes.fromhex("0ab0020009c00400"))
check("written extent", zf.written_extent(132860), VENDOR_WRITES * 0x1000)

print("\nerase plan")
plan = zf.erase_plan(zf.FLASH_APP, 132860)
lo, hi = plan[0][0], plan[-1][0] + plan[-1][2]
check("starts on the sector holding the image", lo, 0x2B000)
check("covers the written extent, not just the image",
      hi >= zf.FLASH_APP + zf.written_extent(132860), True)
check("clear of the macro scratch sector", hi <= zf.FLASH_MACRO_BAK, True)
print(f"        range 0x{lo:X}..0x{hi:X}, {len(plan)} ops, "
      f"vendor erases to 0x51000")

print("\nimage integrity")
c = pathlib.Path(__file__).resolve().parent.parent / "firmware" / "zephyr2_container.bin"
if c.exists():
    raw = c.read_bytes()
    h = fwtool.parse_header(raw)
    check("header CRC matches body",
          h["crc0"] | (h["crc1"] << 16), fwtool.image_crc32(raw[fwtool.HDR_LEN:]))
    check("JAMCRC is ~zlib.crc32",
          fwtool.image_crc32(raw[16:]), zlib.crc32(raw[16:]) ^ 0xFFFFFFFF)
    check("repack is byte-identical",
          fwtool.pack(fwtool.unpack(raw), h["ver"], h["uid"], h["res"]), raw)

print()
if FAIL:
    sys.exit(f"{len(FAIL)} FAILED: {', '.join(FAIL)}")
print("all checks passed")
