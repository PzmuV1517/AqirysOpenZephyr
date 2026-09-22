#!/usr/bin/env python3
"""AQIRYS Zephyr (Beken BLE mouse) firmware container tool.

Container layout of the image embedded in Update.exe (RCDATA type "BIN", id 129):

    offset 0   : 16-byte OAD-style image header (little-endian)
                   u16 crc0, u16 crc1, u16 ver, u16 len, u8 uid[4], u8 res[4]
                 `len` counts the WHOLE resource in 4-byte units.
    offset 16  : repeating records of [32 bytes payload][2 bytes CRC-16 big-endian]
                 CRC-16: poly 0x8005, init 0xFFFF, no reflection, xorout 0x0000
                 (Beken's flash-controller block CRC; the XIP engine strips it,
                 so the CPU-visible image is the concatenated 32-byte payloads)
    tail       : a final short payload run with no CRC (image is not a multiple of 32)

The de-CRC'd image is ARM (ARMv5TE, ARM+Thumb) linked at 0x000287A0.
"""
import argparse, struct, sys, pathlib, zlib

BLOCK, CRC_LEN, HDR_LEN = 32, 2, 16
POLY = 0x8005

_TBL = []
for _n in range(256):
    _c = _n << 8
    for _ in range(8):
        _c = ((_c << 1) ^ POLY) & 0xFFFF if _c & 0x8000 else (_c << 1) & 0xFFFF
    _TBL.append(_c)


def crc16(data: bytes, init: int = 0xFFFF) -> int:
    c = init
    for b in data:
        c = ((c << 8) & 0xFFFF) ^ _TBL[((c >> 8) ^ b) & 0xFF]
    return c


def parse_header(raw: bytes) -> dict:
    crc0, crc1, ver, ln = struct.unpack_from("<HHHH", raw, 0)
    return {"crc0": crc0, "crc1": crc1, "ver": ver, "len_units": ln,
            "len_bytes": ln * 4, "uid": raw[8:12], "res": raw[12:16]}


def unpack(raw: bytes, strict: bool = True) -> bytes:
    """Strip the 16-byte header and every per-32-byte CRC -> CPU-visible image."""
    hdr = parse_header(raw)
    if strict and hdr["len_bytes"] != len(raw):
        raise ValueError(f"header len {hdr['len_bytes']} != file size {len(raw)}")
    body, out, bad = raw[HDR_LEN:], bytearray(), []
    i = 0
    while i < len(body):
        chunk = body[i:i + BLOCK]
        if len(chunk) < BLOCK:           # trailing short run, no CRC
            out += chunk
            break
        want = int.from_bytes(body[i + BLOCK:i + BLOCK + CRC_LEN], "big")
        got = crc16(chunk)
        if got != want:
            bad.append((i // (BLOCK + CRC_LEN), want, got))
        out += chunk
        i += BLOCK + CRC_LEN
    if bad:
        msg = f"{len(bad)} block CRC mismatches, first: idx={bad[0][0]} want=0x{bad[0][1]:04x} got=0x{bad[0][2]:04x}"
        if strict:
            raise ValueError(msg)
        print("warning:", msg, file=sys.stderr)
    return bytes(out)


def image_crc32(body: bytes) -> int:
    """The header's crc0/crc1 pair, as one 32-bit value.

    CRC-32/JAMCRC over the container body, i.e. everything after the 16-byte
    header: the standard CRC-32 with the final complement left off, which is
    just ~zlib.crc32(). Stored little-endian at header offset 0, so crc0 is the
    low half and crc1 the high half.

    Verified against the shipping image: zlib.crc32(body) = 0x0B06814C, its
    complement 0xF4F97EB3, and the header holds b3 7e f9 f4.
    """
    return (zlib.crc32(body) ^ 0xFFFFFFFF) & 0xFFFFFFFF


def pack(image: bytes, ver: int, uid: bytes, res: bytes,
         crc0: int | None = None, crc1: int | None = None) -> bytes:
    """Re-insert per-block CRCs and prepend the header.

    crc0/crc1 are computed from the packed body unless explicitly supplied.
    """
    body = bytearray()
    for i in range(0, len(image), BLOCK):
        chunk = image[i:i + BLOCK]
        body += chunk
        if len(chunk) == BLOCK:
            body += crc16(chunk).to_bytes(CRC_LEN, "big")
    total = HDR_LEN + len(body)
    if total % 4:
        raise ValueError(f"packed size {total} is not a multiple of 4")
    if crc0 is None or crc1 is None:
        c = image_crc32(bytes(body))
        crc0, crc1 = c & 0xFFFF, c >> 16
    hdr = struct.pack("<HHHH", crc0, crc1, ver, total // 4) + uid[:4] + res[:4]
    return hdr + bytes(body)


def extract_from_exe(exe: pathlib.Path) -> bytes:
    """Pull the 'BIN'/129 resource out of Update.exe without needing pefile."""
    import pefile
    pe = pefile.PE(str(exe))
    for e in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        name = e.name.string.decode() if e.name else str(e.struct.Id)
        if name != "BIN":
            continue
        for e2 in e.directory.entries:
            for e3 in e2.directory.entries:
                d = e3.data.struct
                off = pe.get_offset_from_rva(d.OffsetToData)
                return pe.__data__[off:off + d.Size]
    raise SystemExit("no BIN resource found in " + str(exe))


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("extract", help="pull the raw container out of Update.exe")
    p.add_argument("exe"); p.add_argument("-o", "--out", required=True)

    p = sub.add_parser("info", help="print header + CRC verification")
    p.add_argument("container")

    p = sub.add_parser("unpack", help="container -> flat CPU-visible image")
    p.add_argument("container"); p.add_argument("-o", "--out", required=True)
    p.add_argument("--loose", action="store_true", help="tolerate CRC errors")

    p = sub.add_parser("pack", help="flat image -> container (CRCs recomputed)")
    p.add_argument("image"); p.add_argument("-o", "--out", required=True)
    p.add_argument("--like", help="copy ver/uid/res/crc0/crc1 from this container")
    p.add_argument("--ver", type=lambda s: int(s, 0), default=0x0024)
    p.add_argument("--uid", default="BBBB")

    a = ap.parse_args()

    if a.cmd == "extract":
        data = extract_from_exe(pathlib.Path(a.exe))
        pathlib.Path(a.out).write_bytes(data)
        print(f"extracted {len(data)} bytes -> {a.out}")
        return

    if a.cmd == "info":
        raw = pathlib.Path(a.container).read_bytes()
        h = parse_header(raw)
        nblk = (len(raw) - HDR_LEN) // (BLOCK + CRC_LEN)
        tail = (len(raw) - HDR_LEN) % (BLOCK + CRC_LEN)
        print(f"file size   : {len(raw)} (0x{len(raw):x})")
        want = image_crc32(raw[HDR_LEN:])
        got = h["crc0"] | (h["crc1"] << 16)
        print(f"crc0 / crc1 : 0x{h['crc0']:04x} / 0x{h['crc1']:04x}"
              f"  -> 0x{got:08x} [{'OK' if got == want else f'BAD, expected 0x{want:08x}'}]")
        print(f"ver         : 0x{h['ver']:04x}  (imgType={'B' if h['ver'] & 1 else 'A'}, userVer={h['ver'] >> 1})")
        print(f"len         : {h['len_units']} x4 = {h['len_bytes']} bytes  "
              f"[{'OK' if h['len_bytes'] == len(raw) else 'MISMATCH'}]")
        print(f"uid / res   : {h['uid']!r} / {h['res'].hex()}")
        print(f"blocks      : {nblk} x 32B (+2B CRC), tail {tail}B")
        img = unpack(raw, strict=False)
        print(f"flat image  : {len(img)} (0x{len(img):x}) bytes, load base 0x000287A0")
        return

    if a.cmd == "unpack":
        raw = pathlib.Path(a.container).read_bytes()
        img = unpack(raw, strict=not a.loose)
        pathlib.Path(a.out).write_bytes(img)
        print(f"unpacked {len(raw)} -> {len(img)} bytes ({a.out})")
        return

    if a.cmd == "pack":
        img = pathlib.Path(a.image).read_bytes()
        ver, uid, res, c0, c1 = a.ver, a.uid.encode()[:4], b"\xff\xff\xcc\x6e", 0x7EB3, 0xF4F9
        if a.like:
            h = parse_header(pathlib.Path(a.like).read_bytes())
            ver, uid, res, c0, c1 = h["ver"], h["uid"], h["res"], h["crc0"], h["crc1"]
        out = pack(img, ver, uid, res, c0, c1)
        pathlib.Path(a.out).write_bytes(out)
        print(f"packed {len(img)} -> {len(out)} bytes ({a.out})")
        return


if __name__ == "__main__":
    main()
