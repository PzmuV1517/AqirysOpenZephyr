#!/usr/bin/env python3
"""Build a modified, flashable AQIRYS Zephyr image.

Takes the original container, applies edits to the CPU-visible image, recomputes
every block CRC and the header, and writes a container ready for tools/fwtool.py
and the USB bootloader.

Edits available
---------------
  set    <addr> <hex|@file>   overwrite bytes at a CPU address
  append <@file>              append a blob (code or data); prints its address
  hook   <addr> <target>      redirect a Thumb function entry to <target>
  ver    <value>              set the header version field

The hook emits this Thumb-1 trampoline, which preserves every AAPCS
argument register and clobbers only IP, which is call-clobbered anyway:

    01b4        push {r0}
    0248        ldr  r0, [pc, #8]
    8446        mov  ip, r0
    01bc        pop  {r0}
    6047        bx   ip
    c046        nop                (alignment)
    <word>      target | 1         (Thumb bit set)

14 bytes. Whatever it overwrites is gone, so hook a function entry, not the
middle of one, and keep a copy of the original bytes if you need to chain.
"""
import argparse, pathlib, struct, sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import fwtool

BASE = 0x287A0
FLASH_APP = 0x2B00A
FLASH_MACRO_BAK = 0x52000      # scratch sector FLASH_WR_Macro erases
MAX_IMAGE_BYTES = FLASH_MACRO_BAK - FLASH_APP
OAD_MAX_BLK_APP = 0x2A00


class Image:
    def __init__(self, container: bytes):
        self.hdr = fwtool.parse_header(container)
        self.data = bytearray(fwtool.unpack(container))
        self.orig_len = len(self.data)

    # --- address helpers -------------------------------------------------
    def off(self, addr: int) -> int:
        o = addr - BASE
        if not 0 <= o < len(self.data):
            raise ValueError(f"0x{addr:X} is outside the image "
                             f"(0x{BASE:X}..0x{BASE + len(self.data):X})")
        return o

    # --- edits -----------------------------------------------------------
    def set_bytes(self, addr: int, blob: bytes) -> None:
        o = self.off(addr)
        if o + len(blob) > len(self.data):
            raise ValueError("write runs past the end of the image")
        self.data[o:o + len(blob)] = blob

    def append(self, blob: bytes, align: int = 4) -> int:
        while len(self.data) % align:
            self.data.append(0xFF)
        addr = BASE + len(self.data)
        self.data += blob
        while len(self.data) % 4:
            self.data.append(0xFF)
        return addr

    def hook(self, addr: int, target: int) -> None:
        # Byte sequence verified against arm-none-eabi-as (-mthumb -mcpu=arm9e);
        # do not hand-edit. The ldr offset is #8, not #4: Thumb LDR(literal)
        # uses Align(PC,4) and PC already reads two instructions ahead.
        tramp = bytes.fromhex("01b4"   # push {r0}
                              "0248"   # ldr  r0, [pc, #8]
                              "8446"   # mov  ip, r0
                              "01bc"   # pop  {r0}
                              "6047"   # bx   ip
                              "c046")  # nop           (alignment)
        tramp += struct.pack("<I", target | 1)
        self.set_bytes(addr, tramp)

    # --- output ----------------------------------------------------------
    @staticmethod
    def _packed_size(flat_len: int) -> int:
        full, tail = divmod(flat_len, fwtool.BLOCK)
        return fwtool.HDR_LEN + full * (fwtool.BLOCK + fwtool.CRC_LEN) + tail

    def _aligned(self) -> bytes:
        """Pad with 0xFF until the packed container is a multiple of 4 bytes.

        The header stores the total in 4-byte units, so a container that is not
        a multiple of 4 cannot be described. Padding is minimal, and an image
        that already lands correctly (the stock one does) is left untouched so
        an unmodified rebuild stays byte-identical.
        """
        data = bytes(self.data)
        while self._packed_size(len(data)) % 4:
            data += b"\xff"
        return data

    def container(self, ver: int) -> bytes:
        # crc0/crc1 are recomputed from the new body; copying the originals
        # over would leave a modified image with a checksum for the old one.
        return fwtool.pack(self._aligned(), ver, self.hdr["uid"], self.hdr["res"])

    def check(self, ver: int, installed_ver: int | None) -> list[str]:
        """Re-apply the device's own acceptance rules (see include/zephyr.h)."""
        warn = []
        out = self.container(ver)
        blk = (len(out) // 4) >> 2
        if not 0 < blk < OAD_MAX_BLK_APP + 1:
            warn.append(f"block count {blk} outside the device's 1..{OAD_MAX_BLK_APP} range")
        if self.hdr["uid"] != b"BBBB":
            warn.append(f"uid is {self.hdr['uid']!r}, not b'BBBB' (app-only upgrade)")
        if installed_ver is not None and ver == installed_ver:
            warn.append(f"ver 0x{ver:04X} equals the installed version; "
                        "the device requires them to differ")
        end = FLASH_APP + len(out)
        if end > FLASH_MACRO_BAK:
            raise SystemExit(
                f"REFUSING: the image would occupy 0x{FLASH_APP:X}..0x{end:X} and run into "
                f"the macro scratch sector at 0x{FLASH_MACRO_BAK:X}. FLASH_WR_Macro erases "
                f"that sector whenever a macro is saved, which would corrupt the firmware "
                f"on first use. Maximum container size is {MAX_IMAGE_BYTES} bytes.")
        if end > FLASH_MACRO_BAK - 0x1000:
            warn.append(f"image ends at 0x{end:X}, within 4K of the macro scratch sector "
                        f"at 0x{FLASH_MACRO_BAK:X}")
        if len(self.data) != self.orig_len:
            warn.append(f"image grew {self.orig_len} -> {len(self.data)} bytes "
                        "(fine, but the flash write range changes)")
        return warn


def blob(spec: str) -> bytes:
    if spec.startswith("@"):
        return pathlib.Path(spec[1:]).read_bytes()
    return bytes.fromhex(spec.replace(" ", ""))


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("container", help="original container (see fwtool.py extract)")
    ap.add_argument("-o", "--out", required=True)
    ap.add_argument("--ver", type=lambda s: int(s, 0),
                    help="header version to stamp (must differ from installed)")
    ap.add_argument("--installed-ver", type=lambda s: int(s, 0),
                    help="version currently on the device, for the accept check")
    ap.add_argument("--set", nargs=2, action="append", metavar=("ADDR", "BYTES"), default=[])
    ap.add_argument("--append", action="append", metavar="@FILE", default=[])
    ap.add_argument("--hook", nargs=2, action="append", metavar=("ADDR", "TARGET"), default=[])
    a = ap.parse_args()

    img = Image(pathlib.Path(a.container).read_bytes())
    print(f"loaded {img.orig_len} bytes, base 0x{BASE:06X}, "
          f"ver 0x{img.hdr['ver']:04X}, uid {img.hdr['uid']!r}")

    for spec in a.append:
        addr = img.append(blob(spec))
        print(f"  append {spec} -> 0x{addr:06X}")
    for addr, data in a.set:
        b = blob(data)
        img.set_bytes(int(addr, 0), b)
        print(f"  set    0x{int(addr, 0):06X} += {len(b)} bytes")
    for addr, target in a.hook:
        img.hook(int(addr, 0), int(target, 0))
        print(f"  hook   0x{int(addr, 0):06X} -> 0x{int(target, 0):06X}")

    ver = a.ver if a.ver is not None else img.hdr["ver"]
    for w in img.check(ver, a.installed_ver):
        print(f"  warning: {w}", file=sys.stderr)

    out = img.container(ver)
    pathlib.Path(a.out).write_bytes(out)
    print(f"wrote {len(out)} bytes -> {a.out}  (ver 0x{ver:04X})")
    print(f"flash at 0x{0x2B00A:X}, occupies 0x{0x2B00A:X}..0x{0x2B00A + len(out):X}")


if __name__ == "__main__":
    main()
