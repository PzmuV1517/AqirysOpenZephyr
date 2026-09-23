#!/usr/bin/env python3
"""Show exactly what a patch changed, and whether it touched existing code.

    patchdiff.py <stock container> <patched container>

A dead-code patch must only APPEND. If this reports any change below the
original image end, the patch modified running firmware and is not the
zero-execution-risk case it was supposed to be.
"""
import pathlib, sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import fwtool

BASE = 0x287A0


def main(a, b):
    ra, rb = pathlib.Path(a).read_bytes(), pathlib.Path(b).read_bytes()
    ha, hb = fwtool.parse_header(ra), fwtool.parse_header(rb)
    fa, fb = fwtool.unpack(ra, strict=False), fwtool.unpack(rb, strict=False)

    print(f"stock   {len(ra):>7} bytes container, {len(fa):>7} flat, ver 0x{ha['ver']:04X}")
    print(f"patched {len(rb):>7} bytes container, {len(fb):>7} flat, ver 0x{hb['ver']:04X}")
    print(f"grew by {len(fb) - len(fa)} bytes of image "
          f"({len(rb) - len(ra)} of container)\n")

    common = min(len(fa), len(fb))
    diffs = [i for i in range(common) if fa[i] != fb[i]]

    if not diffs:
        print(f"OVERLAP CLEAN: the first {common} bytes are byte-identical.")
        print("Nothing that already existed was modified - this is append-only,")
        print("so no existing instruction can behave differently.")
    else:
        lo, hi = min(diffs), max(diffs)
        print(f"*** {len(diffs)} byte(s) CHANGED inside the original image ***")
        print(f"    range 0x{BASE + lo:06X}..0x{BASE + hi:06X}")
        for i in diffs[:12]:
            print(f"      0x{BASE + i:06X}: {fa[i]:02x} -> {fb[i]:02x}")
        if len(diffs) > 12:
            print(f"      ... and {len(diffs) - 12} more")
        print("\n    This patch modifies running firmware. It is NOT dead code.")

    if len(fb) > len(fa):
        print(f"\nappended 0x{BASE + len(fa):06X}..0x{BASE + len(fb):06X} "
              f"({len(fb) - len(fa)} bytes)")
        print(f"  first 32: {fb[len(fa):len(fa) + 32].hex(' ')}")

    print(f"\nheader crc0/crc1 0x{ha['crc0'] | (ha['crc1'] << 16):08X} "
          f"-> 0x{hb['crc0'] | (hb['crc1'] << 16):08X}  (expected to differ)")
    return 0 if not diffs else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1], sys.argv[2]))
