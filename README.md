# OpenZephyr

Open tooling for the **AQIRYS Zephyr 2** gaming mouse: an image format decoder, a
macOS/Linux firmware flasher, and a compile-and-inject patch toolchain — all built
from reverse engineering the vendor's Windows updater and the firmware it ships.

The vendor supplies a Windows-only `Update.exe`. This repo replaces it, and goes
further: it documents the image format, the flashing protocol, the on-device
configuration surface, and how to compile your own code into the firmware.

> **Nothing here has been tested on hardware yet.** Everything is verified
> statically or against the vendor tool's captured traffic. See
> [Status](#status) before flashing anything.

---

## The hardware

| Part | Detail |
|---|---|
| MCU | Beken **BK3633QN48**, ARMv5TE (ARM968-class), ARM + Thumb |
| Flash | 512 KB **internal** — no external chip, so no clip-on recovery |
| RAM | SRAM at `0x00400000` |
| Sensor | PixArt **PAW3395DM-T6QU** on SPI, 26,000 DPI ceiling |
| Display | 120×32 mono OLED, SSD1306-family, I²C address `0x78` |
| Clock | 16.000 MHz |
| USB | VID `0x1D57` PID `0xFA61`, 4 interfaces, 1000 Hz (Full-Speed max) |
| Bootloader | VID `0xA745` PID `0x0033` |

The BLE stack is **RivieraWaves in mask ROM**, not in the flash image. 71 ROM entry
points are called by the application and their code is not available to us — which
is why the firmware cannot simply be recompiled.

---

## What's been worked out

### Image format

The updater carries the firmware as an `RCDATA` resource (`BIN`, id 129):

```
+0x00   16-byte header: crc0, crc1, ver, len(×4), uid[4], res[4]
+0x10   repeating [32 bytes payload][2 bytes CRC-16 big-endian]
```

- **Block CRC-16** — poly `0x8005`, init `0xFFFF`, no reflection. Beken's
  flash-block CRC; the XIP engine strips it in hardware.
- **Header `crc0`/`crc1`** — not two checksums. Together they're one little-endian
  **CRC-32/JAMCRC** over everything after the header (`~zlib.crc32(body)`).
- **Load address `0x000287A0`**, confirmed two independent ways.

`pack(unpack(x)) == x` byte-for-byte.

### Flash map

```
0x00000-0x287A0   mask ROM / bootloader (BLE stack lives here)
0x2B00A-0x4B70E   application image
0x4B70E-0x52000   free — 26 KB of headroom for injected code
0x52000-0x53000   macro scratch sector (erased on every macro save)
0x7C000           5 profiles, 0x80 apart, 117 bytes each
0x7D000           32 macro slots, 0x80 each
0x7E000           BLE MAC address
```

### Update protocol

Beken vendor HCI (opcode `0xFCE0`) tunnelled over 65-byte HID reports.

| Step | Packet |
|---|---|
| Enter bootloader | Feature report `10 08 00 …` |
| Erase | `01 E0 FC FF F4 06 00 0F <op> <addr32>` — `0x20` 4K, `0xD8` 64K |
| Write 4K | `01 E0 FC FF F4 05 10 07 <addr32> <4096 B>` |
| CRC | `01 E0 FC 09 10 <start32> <end32>` |
| Reboot | `01 E0 FC 02 0E A5` ×3 |

Replies are `04 0E FF 01 E0 FC F4 <len16> <cmd> <status> <params>` — note the
**status byte** between the command echo and the parameters.

Confirmed by driving the vendor's own `Update.exe` against a fake device and
capturing all 45 commands ([`analysis/vendor_trace.log`](analysis/vendor_trace.log)).

### Configuration surface

The vendor HID collection (usage page `0x0B`, usage `0x00`) exposes 24 feature
reports. Nine are identified, from the firmware's own debug tags:

| ID | Size | Purpose |
|---|---|---|
| `0x04` | 51 B | sensor / DPI stages |
| `0x05` | 12 B | lighting |
| `0x06` | 8 B | polling rate |
| `0x07` | 7 B | RF transmit power |
| `0x08` | 58 B | button mapping |
| `0x09` | 63 B | macro data |
| `0x0B` | 7 B | firmware version |
| `0x0C` | 5 B | active profile |
| `0x10` | 7 B | reboot to bootloader |

### Profile records (117 bytes, ×5)

```
+0x00  mode byte (1/2/4/8)      +0x02  SensorSet  47 B   +0x31  checksum
+0x01  its complement           +0x33  LightSet    8 B   +0x3B  checksum
                                +0x3D  ButtonSet  54 B   +0x73  checksum
```

Each section is checksummed with a **plain 16-bit byte sum**, stored big-endian,
and **falls back to defaults silently** if it doesn't match. A tool that rewrites a
section without recomputing its checksum sees the change vanish with no error.

**DPI:** 8 stages, low bytes at `+0x06`, high at `+0x0E`, active stage at `+0x17`.

```
DPI = (stored + 1) × 50
```

Stock stages decode to 100 / 800 / 1200 / 1600 / 3200 / 5600 / 26000 / 50, active
stage 2. Stage 6 landing exactly on the sensor's 26,000 ceiling is what confirms
the formula.

---

## Repo layout

```
tools/       fwtool  fwpatch  mkpatch  patchdiff  zephyr_flash  test_protocol
include/     zephyr.h  zephyr_hid.h  firmware_globals.h
src/         785 decompiled functions in 13 subsystem files
analysis/    decompilation, symbol map, strings, captured vendor trace
examples/    hello_patch.c  memdump.c
firmware/    container and flat images
```

`include/*.h` is hand-written and contains **no guesses** — anything unproven is
marked as such. `src/` is Ghidra output: a map for finding things, not buildable code.

---

## Usage

```bash
python3 tools/test_protocol.py                              # 21 offline checks
python3 tools/fwtool.py info firmware/zephyr2_container.bin  # validate an image

python3 tools/zephyr_flash.py info                          # read-only probe
python3 tools/zephyr_flash.py verify  <container>           # read back flash CRC
python3 tools/zephyr_flash.py flash   <container>           # erase, write, verify, reboot
```

### Writing a patch

Firmware functions are called by address, Thumb bit set:

```c
typedef void (*printf_fn)(const char *, ...);
#define dbg_printf ((printf_fn)(0x0003B77Eu | 1))

void my_hook(void) { dbg_printf("hello from a patch\r\n"); }
```

```bash
python3 tools/mkpatch.py <container> patch.c -o out.bin --hook 0x38f5a=my_hook
python3 tools/patchdiff.py <container> out.bin     # what actually changed?
```

`patchdiff` reports `OVERLAP CLEAN` when a patch only appends — proof that no
existing instruction can behave differently. Run it on every patch.

---

## Status

| | |
|---|---|
| Container format, both CRCs | proven, byte-exact round trip |
| Update protocol | verified against captured vendor traffic |
| Compile-and-inject | works offline; untested on silicon |
| Profile layout, DPI scale | decoded and cross-checked |
| ROM boot validation | **unknown** |
| Recovery from a bad flash | **unknown** |
| Device CRC-32 flavour | **unconfirmed** |

Not achievable: recompiling the firmware from `src/`. The ROM bodies are absent,
types are inferred, and there's no linker script. Modification happens by patching
and hooking instead — which can go as deep as you like.

---

## Safety

Read this before connecting anything.

- **`info` writes nothing.** Everything else does.
- **`verify` is not read-only.** Reaching the bootloader makes the firmware stamp
  16 bytes at `0x7D000`, which is **macro slot 0**. The vendor updater does the
  same on every update.
- **`verify` leaves the mouse in DFU.** It won't work as a mouse until you flash
  it. Always follow with a stock reflash in the same session.
- **There is no external flash to clip onto.** If a patched image doesn't boot and
  the ROM doesn't fall back, the mouse may be unrecoverable. The flasher compares
  the device CRC against ours and **refuses to reboot on mismatch**, so a failed
  write leaves the device in the bootloader where it's still reachable.
- **Fallback:** the vendor `Update.exe` speaks the same protocol. Any Windows
  machine can recover a device this repo's tools can't reach.

Use a direct USB port, not a hub. Don't start without time to finish.

---

## Licence and provenance

The tools, headers and examples here are original work — use them however you like.

`firmware/`, `analysis/` and the vendor updater are **not**: they are AQIRYS's
copyrighted firmware, verbatim or derived from it. Copyright in software is
automatic and doesn't depend on registration, so these can't be relicensed. They're
kept here as working material. Anyone can regenerate them from their own copy of
`Update.exe` using `tools/fwtool.py extract`.

Reverse engineering for interoperability — which is what this is — is a
well-established use. Publishing the tools and the documented protocol is fine;
redistributing the vendor's firmware image is a different question, and one worth
deciding deliberately before making this repo public.
