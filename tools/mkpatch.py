#!/usr/bin/env python3
"""Compile C into the Zephyr firmware image.

    mkpatch.py <container> <patch.c> -o <new container> [--hook ADDR=SYMBOL] [--ver V]

Compiles patch.c for the Beken core (ARMv5TE, Thumb), links it at the address
it will actually occupy, appends it to the image, optionally redirects existing
functions to symbols in it, and recomputes every checksum.

Writing a patch
---------------
Firmware functions are called by address. Declare them with their Thumb bit set:

    typedef void (*printf_fn)(const char *, ...);
    #define dbg_printf ((printf_fn)(0x0003B77Eu | 1))

    void my_hook(void) { dbg_printf("hello from a patch\\r\\n"); }

Constraints, all enforced here rather than discovered on the device:
  * freestanding, no libc, no static initialisers that need a startup runtime;
  * the image may not reach the macro scratch sector at 0x52000;
  * a hook overwrites 14 bytes at a function entry, so hook entries only.
"""
import argparse, pathlib, re, shutil, struct, subprocess, sys, tempfile

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import fwtool, fwpatch

CC = "arm-none-eabi-gcc"
OBJCOPY = "arm-none-eabi-objcopy"
NM = "arm-none-eabi-nm"
OBJDUMP = "arm-none-eabi-objdump"
CFLAGS = ["-mcpu=arm9e", "-mthumb", "-Os", "-ffreestanding", "-nostdlib",
          "-fno-builtin", "-fomit-frame-pointer", "-Wall", "-Wextra"]


def need(tool):
    if not shutil.which(tool):
        sys.exit(f"{tool} not found - install with: brew install arm-none-eabi-gcc")


def align4(n):
    return (n + 3) & ~3


def compile_at(src: pathlib.Path, load_addr: int, workdir: pathlib.Path):
    """Compile and link so the code runs from load_addr; return (blob, symbols)."""
    obj, elf, binf = workdir / "p.o", workdir / "p.elf", workdir / "p.bin"
    subprocess.run([CC, *CFLAGS, "-c", str(src), "-o", str(obj)], check=True)
    subprocess.run([CC, *CFLAGS, "-Wl,-Ttext,0x%X" % load_addr, "-Wl,--entry,0",
                    "-Wl,--build-id=none", "-Wl,-n",
                    str(obj), "-o", str(elf)], check=True)
    subprocess.run([OBJCOPY, "-O", "binary", str(elf), str(binf)], check=True)
    syms = {}
    out = subprocess.run([NM, str(elf)], check=True, capture_output=True, text=True).stdout
    for line in out.splitlines():
        m = re.match(r"([0-9a-f]+)\s+([tTwW])\s+(\S+)", line)
        if m:
            syms[m.group(3)] = int(m.group(1), 16)
    return binf.read_bytes(), syms, elf


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("container")
    ap.add_argument("source")
    ap.add_argument("-o", "--out", required=True)
    ap.add_argument("--hook", action="append", default=[], metavar="ADDR=SYMBOL",
                    help="redirect the function at ADDR to SYMBOL in the patch")
    ap.add_argument("--ver", type=lambda s: int(s, 0), help="header version to stamp")
    ap.add_argument("--keep", action="store_true", help="keep the build directory")
    a = ap.parse_args()

    for t in (CC, OBJCOPY, NM):
        need(t)

    img = fwpatch.Image(pathlib.Path(a.container).read_bytes())
    load_addr = fwpatch.BASE + align4(len(img.data))
    print(f"image ends at 0x{fwpatch.BASE + len(img.data):06X}, "
          f"patch will load at 0x{load_addr:06X}")

    work = pathlib.Path(tempfile.mkdtemp(prefix="zephyr-patch-"))
    try:
        blob, syms, elf = compile_at(pathlib.Path(a.source), load_addr, work)
        print(f"compiled {len(blob)} bytes")
        if not blob:
            sys.exit("patch compiled to nothing - is anything in it reachable?")

        actual = img.append(blob)
        if actual != load_addr:
            sys.exit(f"internal error: linked at 0x{load_addr:X} but landed at 0x{actual:X}")

        print("symbols:")
        for n, v in sorted(syms.items(), key=lambda kv: kv[1]):
            print(f"  0x{v:06X}  {n}{'  (thumb)' if v & 1 else ''}")

        for h in a.hook:
            addr_s, _, sym = h.partition("=")
            if sym not in syms:
                sys.exit(f"--hook {h}: no symbol '{sym}' in the patch "
                         f"(have: {', '.join(sorted(syms)) or 'none'})")
            addr, target = int(addr_s, 0), syms[sym] & ~1
            img.hook(addr, target)
            print(f"hook 0x{addr:06X} -> {sym} @ 0x{target:06X}")

        ver = a.ver if a.ver is not None else img.hdr["ver"]
        for w in img.check(ver, None):
            print(f"warning: {w}", file=sys.stderr)
        out = img.container(ver)
        pathlib.Path(a.out).write_bytes(out)
        print(f"\nwrote {len(out)} bytes -> {a.out} (ver 0x{ver:04X})")
        print(f"disassemble the patch with:\n  {OBJDUMP} -d {elf}"
              if a.keep else "  (re-run with --keep to inspect the ELF)")
    finally:
        if not a.keep:
            shutil.rmtree(work, ignore_errors=True)


if __name__ == "__main__":
    main()
