/* zephyr_hid.h - the vendor HID configuration surface and the profile store.
 *
 * Derived from the firmware image and cross-checked. Anything still unproven is
 * marked; nothing here is guessed.
 */
#ifndef ZEPHYR_HID_H
#define ZEPHYR_HID_H

#include <stdint.h>

/* ------------------------------------------------------------------ *
 * Feature reports on the vendor collection (usage page 0x0B, usage 0)
 * ------------------------------------------------------------------ *
 * Sizes are the HID report descriptor's Report Count, excluding the report ID.
 * The names come from the firmware's own debug logging, which prints a tag per
 * report - "_GM04_sensit get", "_GM05_LightSet set" and so on. That is what
 * ties each ID to its purpose; the mapping is the firmware's, not a guess.
 */
#define ZHID_RPT_SENSIT     0x04u   /*  51 B  sensor / DPI stages            */
#define ZHID_RPT_LIGHT      0x05u   /*  12 B  lighting                       */
#define ZHID_RPT_POLLING    0x06u   /*   8 B  polling rate                   */
#define ZHID_RPT_RFPOWER    0x07u   /*   7 B  radio transmit power           */
#define ZHID_RPT_BUTTON     0x08u   /*  58 B  button mapping                 */
#define ZHID_RPT_MACRO      0x09u   /*  63 B  macro data, indexed            */
#define ZHID_RPT_VERSION    0x0Bu   /*   7 B  firmware version               */
#define ZHID_RPT_PROFILE    0x0Cu   /*   5 B  active profile select          */
#define ZHID_RPT_ENTER_BL   0x10u   /*   7 B  reboot to bootloader, arg 0x08 */

/* Present in the descriptor, purpose not yet established:
 *   0x0A(7) 0xA0(7) 0x22(131) 0x23(131) 0x24(7) 0x25(12) 0x26(8) 0x27(7)
 *   0x28(131) 0x29(128) 0x2A(130) 0x2B(7) 0x2C(3) 0x2D(102) 0x2E(4)
 * The 0x22..0x2E block mirrors several sizes from 0x04..0x0C, so it is likely
 * a second access path (get vs set, or a second profile bank). Unconfirmed. */

/* ------------------------------------------------------------------ *
 * Set_Report_Data @ 0x0003353C - how an incoming report is routed
 * ------------------------------------------------------------------ *
 * For reports 0x04, 0x05, 0x06 and 0x08 the FIRST payload byte is a 1-based
 * profile index: the handler stores (byte - 1) and advances past it, so the
 * report body proper starts at payload[1]. Report 0x09 (macro) is routed
 * separately and carries its own macro index. Anything else is logged as
 * "N0N0 report_id" and ignored.
 *
 * For 0x04, 0x05 and 0x08 - but deliberately NOT 0x06 - the handler reloads
 * the profile from flash first when the requested index differs from the one
 * currently cached.
 */
#define ZHID_PROFILE_INDEX_IS_1_BASED 1

/* ------------------------------------------------------------------ *
 * Profile store in flash
 * ------------------------------------------------------------------ *
 * FLASH_RD_Profile @ 0x0003052C reads 0x75 bytes for a profile index clamped
 * to 0..4. FLASH_WR_Profile @ 0x00030740 writes it back, staging the enclosing
 * 1 KB (addr & 0xFFFFFC00, 0x400 bytes) before erasing the 4 KB sector.
 *
 * Both functions resolve the same address table, reached from different
 * literals, and they agree - which is the cross-check that these addresses are
 * right rather than a misread pointer.
 */
#define ZHID_PROFILE_COUNT   5u
#define ZHID_PROFILE_SIZE    0x75u   /* 117 bytes read per profile */
#define ZHID_PROFILE_STRIDE  0x80u   /* 128 bytes apart in flash   */
#define ZHID_PROFILE_BASE    0x0007C080u

#define ZHID_PROFILE_ADDR(i) (ZHID_PROFILE_BASE + (i) * ZHID_PROFILE_STRIDE)
/* profile 0 0x7C080   1 0x7C100   2 0x7C180   3 0x7C200   4 0x7C280 */

/* A profile is considered valid when the first byte equals the complement of
 * the second; FLASH_RD_Profile falls back to defaults otherwise. Any tool that
 * writes a profile has to maintain this pair or the firmware discards it. */
#define ZHID_PROFILE_VALID(buf) ((uint8_t)(buf)[0] == (uint8_t)~(uint8_t)(buf)[1])

/* Record layout, from FLASH_RD_Profile @0x3052C. Every one of the 117 bytes is
 * accounted for: 2 + 47 + 2 + 8 + 2 + 54 + 2 = 117.
 *
 *   +0x00        mode byte, must be one of 1, 2, 4, 8 (a bitmask; anything
 *                else is replaced with 1 and the record treated as invalid)
 *   +0x01        complement of +0x00
 *   +0x02..0x30  SensorSet, 47 bytes
 *   +0x31..0x32  SensorSet checksum, BIG-endian u16
 *   +0x33..0x3A  LightSet, 8 bytes
 *   +0x3B..0x3C  LightSet checksum, BIG-endian u16
 *   +0x3D..0x72  ButtonSet, 54 bytes
 *   +0x73..0x74  ButtonSet checksum, BIG-endian u16
 *
 * Each section is checksummed independently and each falls back to its own
 * built-in defaults when the checksum does not match - silently. So a tool that
 * rewrites one section must recompute that section's checksum, or the change
 * simply disappears with no error.
 *
 * The checksum is flash_sub_3050c(buf, len) @0x3050C - a plain 16-bit sum of
 * bytes, nothing more:
 *
 *     uint16_t sum = 0;
 *     for (i = 0; i < len; i++) sum += buf[i];
 *
 * Stored BIG-endian. One quirk worth knowing: the loop counter is masked to 8
 * bits (i = i + 1 & 0xFF), so the routine cannot checksum more than 255 bytes -
 * it would never terminate. The three sections are 47, 8 and 54 bytes, so this
 * never bites in practice, but do not reuse the routine for anything larger.
 *
 * Read from the decompiled body, which is unambiguous. It has NOT been checked
 * against a stored value, because the image contains default section DATA but
 * no default checksums - FLASH_RD_Profile recomputes them after copying the
 * defaults in. The first profile read off a device confirms it in one step.
 */
#define ZHID_PROF_OFF_MODE        0x00u
#define ZHID_PROF_OFF_MODE_INV    0x01u
#define ZHID_PROF_OFF_SENSOR      0x02u
#define ZHID_PROF_LEN_SENSOR      0x2Fu   /* 47 */
#define ZHID_PROF_OFF_SENSOR_CK   0x31u
#define ZHID_PROF_OFF_LIGHT       0x33u
#define ZHID_PROF_LEN_LIGHT       0x08u
#define ZHID_PROF_OFF_LIGHT_CK    0x3Bu
#define ZHID_PROF_OFF_BUTTON      0x3Du
#define ZHID_PROF_LEN_BUTTON      0x36u   /* 54 */
#define ZHID_PROF_OFF_BUTTON_CK   0x73u

/* The DPI stage table, in flash-record coordinates.
 *
 * The offsets recorded above for the sensor block (+0x1C low, +0x24 high,
 * +0x2D stage) are relative to the RAM copy of the profile, which lives at
 * 0x00401000. FLASH_RD_Profile lands SensorSet at RAM +0x18, and the record
 * holds it at +0x02, so a RAM offset maps to the record by -0x16. Verified:
 * the DPI code's base literal and the profile struct literal both resolve to
 * 0x00401000, and the ButtonSet source resolves to raw+0x3D exactly.
 */
#define ZHID_RAM_PROFILE_BASE     0x00401000u
#define ZHID_RAM_TO_RECORD        0x16u    /* record_off = ram_off - 0x16 */
#define ZHID_PROF_OFF_DPI_LO      0x06u    /* 8 bytes, one per stage */
#define ZHID_PROF_OFF_DPI_HI      0x0Eu    /* 8 bytes, one per stage */
#define ZHID_PROF_OFF_DPI_STAGE   0x17u    /* active stage index      */

/* ------------------------------------------------------------------ *
 * Sensor and DPI  (PixArt PAW3395DM, on SPI)
 * ------------------------------------------------------------------ *
 * Board photo confirms the sensor is a PAW3395DM-T6QU, and the firmware talks
 * to it over SPI with named helpers: sensor_init @0x33DEE, sensor_pwdn
 * @0x33DCA, set_dpi @0x33E0A, spi_waitbusying @0x3A978.
 *
 * The register write is in rf24_sub_34538 @0x34538:
 *
 *     v = (hi << 8) | lo;          from the config block, see offsets below
 *     if (v > 1) v -= 2;           firmware biases the stored value by 2
 *     write(0x48, v & 0xFF);       X resolution, low
 *     write(0x49, v >> 8);         X resolution, high
 *     write(0x4A, v & 0xFF);       Y resolution, low
 *     write(0x4B, v >> 8);         Y resolution, high
 *     write(0x47, 1);              apply
 *
 * X and Y are always written the same value, so this firmware has no
 * independent per-axis DPI even though the sensor supports it.
 *
 * The stage table lives in the sensor config block:
 *
 *     +0x1C .. +0x23   8 low  bytes, one per DPI stage
 *     +0x24 .. +0x2B   8 high bytes, one per DPI stage
 *     +0x2D            index of the active stage
 *
 * So there are 8 DPI stages, stored little-endian split across two arrays.
 * The stored-value-to-DPI scale is:
 *
 *     DPI = (stored + 1) * 50
 *
 * Decoded from the default profile held in the image at 0x43FB6, whose eight
 * stages come out as 100, 800, 1200, 1600, 3200, 5600, 26000, 50 with an active
 * stage index of 2 (so 1200 DPI out of the box). Those are ordinary preset
 * values, and stage 6 lands on exactly 26000 - the PAW3395's maximum - which is
 * the corroboration: a wrong scale does not put a stage on the sensor ceiling
 * and the rest on round numbers.
 *
 * Note the firmware writes (stored - 2) to the resolution registers, so the
 * sensor-side encoding is offset from the stored one. The stored encoding above
 * is what a config tool needs; the -2 is internal to set_dpi.
 */
#define ZHID_DPI_FROM_STORED(v)  (((v) + 1) * 50)
#define ZHID_DPI_TO_STORED(dpi)  (((dpi) / 50) - 1)
#define ZHID_DPI_MAX             26000u
#define ZHID_DPI_STAGES          8u
#define ZHID_SENSOR_OFF_DPI_LO   0x1Cu
#define ZHID_SENSOR_OFF_DPI_HI   0x24u
#define ZHID_SENSOR_OFF_STAGE    0x2Du
#define ZHID_SENSOR_DPI_BIAS     2u     /* written value = stored - 2 */

/* PAW3395 registers the firmware touches */
#define PAW3395_REG_SET_RES      0x47u
#define PAW3395_REG_RES_X_LO     0x48u
#define PAW3395_REG_RES_X_HI     0x49u
#define PAW3395_REG_RES_Y_LO     0x4Au
#define PAW3395_REG_RES_Y_HI     0x4Bu

#endif /* ZEPHYR_HID_H */
