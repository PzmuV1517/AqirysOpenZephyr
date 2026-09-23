#!/usr/bin/env python3
"""Replace the Zephyr's startup splash with your own text or bitmap.

The splash lives at 0x045F1D as 480 contiguous bytes: four 120-byte pages, one
per 8-pixel band of the 120x32 display. usb_sub_3d8da @0x3D8DA copies those four
pages into a staging buffer and blits them, so changing them changes what the
mouse shows at boot.

This is a DATA-ONLY patch. It adds no code and hooks nothing - the same
instructions run, over different bytes - so it carries none of the execution
risk that an injected-code patch does.

    # see it first, touch nothing
    mksplash.py --text "OpenZephyr" --preview

    # build a patched image
    mksplash.py --text "OpenZephyr" --in firmware/zephyr2_container.bin \
                -o /tmp/splash.bin --ver 0x0026

    # or supply your own 480-byte page-major blob
    mksplash.py --raw my.bin --in <container> -o /tmp/splash.bin

Pixel format, if you are generating the blob yourself: page-major, LSB at the
top. Byte b of page p is column b; its bit n is the pixel at (b, 8*p + n).
"""
import argparse, pathlib, sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import fwtool, fwpatch

SPLASH_ADDR = 0x045F1D
WIDTH, HEIGHT, PAGES = 120, 32, 4
SPLASH_LEN = WIDTH * PAGES          # 480

# A 5x7 font, written out as pictures so it can be read and corrected by eye
# rather than trusted as hex. Original, drawn for this tool.
F = {
    ' ': ["     "] * 7,
    'A': ["..#..", ".#.#.", "#...#", "#...#", "#####", "#...#", "#...#"],
    'B': ["####.", "#...#", "#...#", "####.", "#...#", "#...#", "####."],
    'C': [".###.", "#...#", "#....", "#....", "#....", "#...#", ".###."],
    'D': ["####.", "#...#", "#...#", "#...#", "#...#", "#...#", "####."],
    'E': ["#####", "#....", "#....", "####.", "#....", "#....", "#####"],
    'F': ["#####", "#....", "#....", "####.", "#....", "#....", "#...."],
    'G': [".###.", "#...#", "#....", "#.###", "#...#", "#...#", ".###."],
    'H': ["#...#", "#...#", "#...#", "#####", "#...#", "#...#", "#...#"],
    'I': ["#####", "..#..", "..#..", "..#..", "..#..", "..#..", "#####"],
    'J': ["....#", "....#", "....#", "....#", "#...#", "#...#", ".###."],
    'K': ["#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#"],
    'L': ["#....", "#....", "#....", "#....", "#....", "#....", "#####"],
    'M': ["#...#", "##.##", "#.#.#", "#...#", "#...#", "#...#", "#...#"],
    'N': ["#...#", "##..#", "#.#.#", "#..##", "#...#", "#...#", "#...#"],
    'O': [".###.", "#...#", "#...#", "#...#", "#...#", "#...#", ".###."],
    'P': ["####.", "#...#", "#...#", "####.", "#....", "#....", "#...."],
    'Q': [".###.", "#...#", "#...#", "#...#", "#.#.#", "#..#.", ".##.#"],
    'R': ["####.", "#...#", "#...#", "####.", "#.#..", "#..#.", "#...#"],
    'S': [".####", "#....", "#....", ".###.", "....#", "....#", "####."],
    'T': ["#####", "..#..", "..#..", "..#..", "..#..", "..#..", "..#.."],
    'U': ["#...#", "#...#", "#...#", "#...#", "#...#", "#...#", ".###."],
    'V': ["#...#", "#...#", "#...#", "#...#", "#...#", ".#.#.", "..#.."],
    'W': ["#...#", "#...#", "#...#", "#...#", "#.#.#", "##.##", "#...#"],
    'X': ["#...#", "#...#", ".#.#.", "..#..", ".#.#.", "#...#", "#...#"],
    'Y': ["#...#", "#...#", ".#.#.", "..#..", "..#..", "..#..", "..#.."],
    'Z': ["#####", "....#", "...#.", "..#..", ".#...", "#....", "#####"],
    'a': ["     ", "     ", ".###.", "....#", ".####", "#...#", ".####"],
    'b': ["#....", "#....", "####.", "#...#", "#...#", "#...#", "####."],
    'c': ["     ", "     ", ".###.", "#....", "#....", "#...#", ".###."],
    'd': ["....#", "....#", ".####", "#...#", "#...#", "#...#", ".####"],
    'e': ["     ", "     ", ".###.", "#...#", "#####", "#....", ".###."],
    'f': ["..##.", ".#...", "####.", ".#...", ".#...", ".#...", ".#..."],
    'g': ["     ", ".####", "#...#", "#...#", ".####", "....#", ".###."],
    'h': ["#....", "#....", "####.", "#...#", "#...#", "#...#", "#...#"],
    'i': ["..#..", "     ", ".##..", "..#..", "..#..", "..#..", ".###."],
    'j': ["...#.", "     ", "..##.", "...#.", "...#.", "#..#.", ".##.."],
    'k': ["#....", "#....", "#..#.", "#.#..", "##...", "#.#..", "#..#."],
    'l': [".##..", "..#..", "..#..", "..#..", "..#..", "..#..", ".###."],
    'm': ["     ", "     ", "##.#.", "#.#.#", "#.#.#", "#...#", "#...#"],
    'n': ["     ", "     ", "####.", "#...#", "#...#", "#...#", "#...#"],
    'o': ["     ", "     ", ".###.", "#...#", "#...#", "#...#", ".###."],
    'p': ["     ", "####.", "#...#", "#...#", "####.", "#....", "#...."],
    'q': ["     ", ".####", "#...#", "#...#", ".####", "....#", "....#"],
    'r': ["     ", "     ", "#.##.", "##...", "#....", "#....", "#...."],
    's': ["     ", "     ", ".####", "#....", ".###.", "....#", "####."],
    't': [".#...", ".#...", "####.", ".#...", ".#...", ".#..#", "..##."],
    'u': ["     ", "     ", "#...#", "#...#", "#...#", "#...#", ".####"],
    'v': ["     ", "     ", "#...#", "#...#", "#...#", ".#.#.", "..#.."],
    'w': ["     ", "     ", "#...#", "#...#", "#.#.#", "#.#.#", ".#.#."],
    'x': ["     ", "     ", "#...#", ".#.#.", "..#..", ".#.#.", "#...#"],
    'y': ["     ", "#...#", "#...#", "#...#", ".####", "....#", ".###."],
    'z': ["     ", "     ", "#####", "...#.", "..#..", ".#...", "#####"],
    '0': [".###.", "#...#", "#..##", "#.#.#", "##..#", "#...#", ".###."],
    '1': ["..#..", ".##..", "..#..", "..#..", "..#..", "..#..", ".###."],
    '2': [".###.", "#...#", "....#", "...#.", "..#..", ".#...", "#####"],
    '3': ["#####", "...#.", "..#..", "...#.", "....#", "#...#", ".###."],
    '4': ["...#.", "..##.", ".#.#.", "#..#.", "#####", "...#.", "...#."],
    '5': ["#####", "#....", "####.", "....#", "....#", "#...#", ".###."],
    '6': ["..##.", ".#...", "#....", "####.", "#...#", "#...#", ".###."],
    '7': ["#####", "....#", "...#.", "..#..", ".#...", ".#...", ".#..."],
    '8': [".###.", "#...#", "#...#", ".###.", "#...#", "#...#", ".###."],
    '9': [".###.", "#...#", "#...#", ".####", "....#", "...#.", ".##.."],
    '-': ["     ", "     ", "     ", "#####", "     ", "     ", "     "],
    '.': ["     ", "     ", "     ", "     ", "     ", ".##..", ".##.."],
    ':': ["     ", ".##..", ".##..", "     ", ".##..", ".##..", "     "],
    '!': ["..#..", "..#..", "..#..", "..#..", "..#..", "     ", "..#.."],
    '?': [".###.", "#...#", "....#", "...#.", "..#..", "     ", "..#.."],
    '/': ["....#", "...#.", "...#.", "..#..", ".#...", ".#...", "#...."],
    '+': ["     ", "..#..", "..#..", "#####", "..#..", "..#..", "     "],
    '*': ["     ", "#.#.#", ".###.", "#####", ".###.", "#.#.#", "     "],
}

GLYPH_W, GLYPH_H, GAP = 5, 7, 1


def text_width(s, scale):
    return sum((GLYPH_W + GAP) * scale for _ in s) - GAP * scale if s else 0


def render(text, scale=1, y=None):
    """Draw text into a WIDTH x HEIGHT pixel grid, horizontally centred."""
    for ch in text:
        if ch not in F:
            raise SystemExit(f"no glyph for {ch!r}. Available: "
                             f"{''.join(sorted(k for k in F if k != ' '))}")
    w = text_width(text, scale)
    if w > WIDTH:
        raise SystemExit(f"{text!r} is {w}px wide at scale {scale}; "
                         f"the display is only {WIDTH}px. Shorten it or use scale 1.")
    grid = [[0] * WIDTH for _ in range(HEIGHT)]
    x0 = (WIDTH - w) // 2
    y0 = (HEIGHT - GLYPH_H * scale) // 2 if y is None else y
    x = x0
    for ch in text:
        g = F[ch]
        for row in range(GLYPH_H):
            for col in range(GLYPH_W):
                if g[row][col] == '#':
                    for dy in range(scale):
                        for dx in range(scale):
                            px, py = x + col * scale + dx, y0 + row * scale + dy
                            if 0 <= px < WIDTH and 0 <= py < HEIGHT:
                                grid[py][px] = 1
        x += (GLYPH_W + GAP) * scale
    return grid


def to_pages(grid):
    """Pixel grid -> the device's page-major bytes, LSB at the top."""
    out = bytearray()
    for page in range(PAGES):
        for col in range(WIDTH):
            b = 0
            for bit in range(8):
                if grid[page * 8 + bit][col]:
                    b |= 1 << bit
            out.append(b)
    return bytes(out)


def preview(blob):
    print("+" + "-" * WIDTH + "+")
    for page in range(PAGES):
        for bit in range(8):
            row = "".join("#" if blob[page * WIDTH + c] & (1 << bit) else " "
                          for c in range(WIDTH))
            print("|" + row + "|")
    print("+" + "-" * WIDTH + "+")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    src = ap.add_mutually_exclusive_group(required=True)
    src.add_argument("--text")
    src.add_argument("--raw", help=f"a {SPLASH_LEN}-byte page-major blob")
    ap.add_argument("--scale", type=int, default=1, choices=(1, 2, 3, 4))
    ap.add_argument("--y", type=int, help="top row; default centres vertically")
    ap.add_argument("--preview", action="store_true", help="draw it and stop")
    ap.add_argument("--in", dest="inp", help="container to patch")
    ap.add_argument("-o", "--out")
    ap.add_argument("--ver", type=lambda s: int(s, 0),
                    help="header version to stamp; must differ from what is installed")
    a = ap.parse_args()

    if a.raw:
        blob = pathlib.Path(a.raw).read_bytes()
        if len(blob) != SPLASH_LEN:
            raise SystemExit(f"{a.raw} is {len(blob)} bytes, need exactly {SPLASH_LEN}")
    else:
        blob = to_pages(render(a.text, a.scale, a.y))

    if a.preview or not a.inp:
        preview(blob)
        lit = sum(bin(b).count("1") for b in blob)
        print(f"{lit} lit pixels of {WIDTH * HEIGHT}")
        if not a.inp:
            print("\n(no --in given, so nothing was patched)")
        return

    if not a.out:
        raise SystemExit("--in needs -o")
    preview(blob)

    img = fwpatch.Image(pathlib.Path(a.inp).read_bytes())
    before = bytes(img.data[SPLASH_ADDR - fwpatch.BASE:
                            SPLASH_ADDR - fwpatch.BASE + SPLASH_LEN])
    img.set_bytes(SPLASH_ADDR, blob)
    ver = a.ver if a.ver is not None else img.hdr["ver"]
    for w in img.check(ver, None):
        print(f"warning: {w}", file=sys.stderr)
    out = img.container(ver)
    pathlib.Path(a.out).write_bytes(out)

    changed = sum(1 for x, y in zip(before, blob) if x != y)
    print(f"\npatched {SPLASH_LEN} bytes at 0x{SPLASH_ADDR:06X} ({changed} differ)")
    print(f"wrote {len(out)} bytes -> {a.out}  (ver 0x{ver:04X})")
    print(f"image size unchanged: {len(out) == len(pathlib.Path(a.inp).read_bytes())}")
    print("\nThis replaces data in place - no code was added and nothing is hooked.")


if __name__ == "__main__":
    main()
