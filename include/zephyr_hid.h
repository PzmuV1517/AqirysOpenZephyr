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

/* Sections inside the record, named by the firmware's own dump labels
 * ("SensorSet:", "LightSet:", "ButtonSet:", and an _offset_Polling index).
 * The byte offsets are NOT yet established - only that these sections exist
 * and that polling is reached through a named offset into the same record. */

#endif /* ZEPHYR_HID_H */
