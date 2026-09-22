/* zephyr.h - AQIRYS Zephyr 2 (Beken BLE mouse): verified platform description.
 *
 * Everything in this file was derived from the shipping firmware image and the
 * vendor's Update.exe and cross-checked. It contains no guesses; anything not
 * yet established is absent rather than invented.
 */
#ifndef ZEPHYR_H
#define ZEPHYR_H

#include <stdint.h>

/* ------------------------------------------------------------------ *
 * Core
 * ------------------------------------------------------------------ *
 * Beken BLE SoC, ARMv5TE (ARM968-class), ARM + Thumb interworking.
 * The BLE stack is RivieraWaves and lives in mask ROM, not in this image -
 * 71 call targets resolve below ZEPHYR_APP_BASE. That is also why the image
 * header carries a ROM version field.
 */

/* ------------------------------------------------------------------ *
 * Memory map
 * ------------------------------------------------------------------ */
#define ZEPHYR_ROM_BASE        0x00000000u  /* mask ROM / bootloader, BLE stack */
#define ZEPHYR_ROM_SIZE        0x000287A0u
#define ZEPHYR_APP_BASE        0x000287A0u  /* this application image, XIP      */
#define ZEPHYR_APP_SIZE        0x0001E866u  /* 125030 bytes                     */
#define ZEPHYR_SRAM_BASE       0x00400000u
#define ZEPHYR_PERIPH_BASE     0x00800000u

/* ------------------------------------------------------------------ *
 * SPI-NOR flash layout (physical offsets, i.e. CRC bytes included)
 * ------------------------------------------------------------------ *
 * The flash controller stores a 2-byte CRC after every 32 bytes of payload
 * and the XIP engine strips it, so CPU-visible and flash offsets differ:
 *
 *     cpu_addr = (flash_off / 34) * 32
 *     flash_off = (cpu_addr / 32) * 34
 *
 * ZEPHYR_FLASH_APP + 16 == 0x2B01A, and (0x2B01A / 34) * 32 == 0x287A0,
 * which is exactly ZEPHYR_APP_BASE - the two derivations agree.
 */
#define ZEPHYR_FLASH_APP       0x0002B00Au  /* OAD header, then the image body  */
#define ZEPHYR_FLASH_MACRO_BAK 0x00052000u  /* scratch sector: FLASH_WR_Macro erases
                                             * 0x52000..0x53000 and stages the
                                             * 0x7D000 config there during a
                                             * read-modify-write. A grown image
                                             * MUST NOT reach this address.      */
#define ZEPHYR_FLASH_CFG_B     0x0007C000u  /* configuration                    */
#define ZEPHYR_FLASH_UPD_FLAG  0x0007D000u  /* config sector; first 16 bytes are
                                             * the "enter bootloader" mark      */
/* app_usb_upgrade_start writes exactly these 16 bytes to ZEPHYR_FLASH_UPD_FLAG
 * and then resets; the mask ROM sees them and comes up as the bootloader
 * (VID 0xA745) instead of running the application. This is the only known way
 * into the bootloader, and it is issued BY the application - so an application
 * that does not boot cannot ask for it. Writing this mark from the bootloader
 * before committing a new image is therefore the recovery lever. */
#define ZEPHYR_UPD_FLAG_BYTES  { 0x12,0x34,0xAA,0x00, 0x00,0x20,0x00,0x00, \
                                 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00 }

/* The largest container that cannot collide with the macro scratch sector. */
#define ZEPHYR_MAX_IMAGE_BYTES (ZEPHYR_FLASH_MACRO_BAK - ZEPHYR_FLASH_APP)  /* 159734 */
#define ZEPHYR_FLASH_MAC       0x0007E000u  /* BLE MAC address                  */
#define ZEPHYR_FLASH_SUMADDR   0x0007E100u  /* checksum/config block            */

#define ZEPHYR_FLASH_BLOCK     32u          /* payload bytes per stored CRC     */
#define ZEPHYR_FLASH_STRIDE    34u          /* payload + 2-byte CRC             */

/* Block CRC: CRC-16, poly 0x8005, init 0xFFFF, no reflection, xorout 0x0000,
 * stored big-endian after each 32-byte payload run. */
#define ZEPHYR_BLOCK_CRC_POLY  0x8005u
#define ZEPHYR_BLOCK_CRC_INIT  0xFFFFu

/* ------------------------------------------------------------------ *
 * Image header - 16 bytes, TI-OAD shaped, at ZEPHYR_FLASH_APP
 * ------------------------------------------------------------------ */
/* crc0 and crc1 are not two checksums: together they are ONE little-endian
 * 32-bit CRC over the container body (everything after this 16-byte header).
 *
 *   value = ~zlib.crc32(body)          i.e. CRC-32/JAMCRC
 *           poly 0xEDB88320, init 0xFFFFFFFF, reflected in and out, xorout 0
 *   crc0  = value & 0xFFFF             crc1 = value >> 16
 *
 * Verified on the shipping image: zlib.crc32(body) = 0x0B06814C, complement
 * 0xF4F97EB3, and the header holds b3 7e f9 f4. The same computation over the
 * whole container, or from offset 4 or 8, gives unrelated values, so the range
 * is definitely "after the header".
 *
 * Note this is a different algorithm from the per-32-byte block CRC-16 above;
 * the two coexist. No CRC-32 table or polynomial constant appears anywhere in
 * the application image, so this one is computed by the mask ROM, which is
 * consistent with the bootloader exposing a CRC-32 over a flash range as
 * command 0x10.
 */
typedef struct {
    uint16_t crc0;      /* low  half of the body CRC-32/JAMCRC                 */
    uint16_t crc1;      /* high half of the body CRC-32/JAMCRC                 */
    uint16_t ver;       /* bit0 = image slot, bits 1..15 = user version        */
    uint16_t len;       /* whole container in 4-byte units (x4 = total bytes)  */
    uint8_t  uid[4];    /* "BBBB" on the shipping image                        */
    uint8_t  res[4];    /* res[0..1] = rom_ver                                 */
} zephyr_img_hdr_t;

/* Shipping "version 2.0" image, for reference. */
#define ZEPHYR_V2_TOTAL_BYTES  132860u      /* == hdr.len * 4                   */
#define ZEPHYR_V2_VER          0x0024u
#define ZEPHYR_V2_UID          "BBBB"

/* ------------------------------------------------------------------ *
 * USB identity
 * ------------------------------------------------------------------ */
#define ZEPHYR_APP_VID         0x1D57u      /* manufacturer string "Beken"      */
#define ZEPHYR_APP_PID         0xFA61u      /* product "USB Gaming Mouse"       */
#define ZEPHYR_APP_BCD_DEVICE  0x0114u      /* shown by the updater as version  */
#define ZEPHYR_BOOT_VID        0xA745u      /* bootloader / DFU identity        */
#define ZEPHYR_BOOT_PID        0x0033u

/* Vendor configuration interface: HID usage page 0x0B, usage 0x00. */
#define ZEPHYR_CFG_USAGE_PAGE  0x0Bu
#define ZEPHYR_CFG_USAGE       0x00u

/* Feature reports on that interface: {report id, payload bytes}. */
#define ZEPHYR_FEATURE_REPORTS { \
    {0x04,0x33},{0x05,0x0C},{0x06,0x08},{0x07,0x07},{0x08,0x3A},{0x09,0x3F}, \
    {0x0A,0x07},{0x0B,0x07},{0x0C,0x05},{0x10,0x07},{0xA0,0x07},{0x22,0x83}, \
    {0x23,0x83},{0x24,0x07},{0x25,0x0C},{0x26,0x08},{0x27,0x07},{0x28,0x83}, \
    {0x29,0x80},{0x2A,0x82},{0x2B,0x07},{0x2C,0x03},{0x2D,0x66},{0x2E,0x04}  \
}

/* Report 0x10 with payload byte 0x08 asks the running firmware to reboot into
 * the bootloader; it stamps 16 bytes at ZEPHYR_FLASH_UPD_FLAG, then resets. */
#define ZEPHYR_REPORT_ENTER_BOOTLOADER   0x10u
#define ZEPHYR_ENTER_BOOTLOADER_ARG      0x08u

/* ------------------------------------------------------------------ *
 * Bootloader protocol - Beken vendor HCI tunnelled over 65-byte HID reports
 * ------------------------------------------------------------------ *
 * Output reports are [0x00 report id][64 bytes]; a command longer than 64
 * bytes is split across consecutive reports and the last one is 0xFF padded.
 *
 *   short form  01 E0 FC <len8>            <cmd> <payload>
 *   long form   01 E0 FC FF F4 <len16 LE>  <cmd> <payload>
 *   response    04 0E FF 01 E0 FC F4 <len16 LE> <cmd> <status> <echoed params>
 *
 * Note the status byte between <cmd> and the echoed parameters. An erase reply
 * therefore carries its opcode at byte 11 and the address at 12..15, a write
 * reply the address at 11..14. Confirmed by driving the vendor Update.exe
 * against a logging hidapi shim: it rejects a reply with the address anywhere
 * else and restarts the whole update.
 *
 * <len> counts the command byte plus its payload.
 */
#define HCI_PKT_COMMAND        0x01u
#define HCI_PKT_EVENT          0x04u
#define HCI_EVT_CMD_COMPLETE   0x0Eu
#define HCI_VENDOR_OPCODE      0xFCE0u      /* wire order: E0 FC               */
#define HCI_LONG_MARKER        0xFFu
#define HCI_LONG_MAGIC         0xF4u

#define BK_CMD_WRITE_4K        0x07u  /* <addr32 LE><4096 bytes>, long form    */
#define BK_CMD_REBOOT          0x0Eu  /* <0xA5>, short form, no response       */
#define BK_CMD_ERASE           0x0Fu  /* <spi_opcode><addr32 LE>, long form    */
#define BK_CMD_CHECK_CRC       0x10u  /* <start32 LE><end32 LE> -> crc32       */

#define BK_ERASE_SECTOR_4K     0x20u  /* SPI-NOR sector erase opcode           */
#define BK_ERASE_BLOCK_64K     0xD8u  /* SPI-NOR block erase opcode            */

#define BK_REBOOT_MAGIC        0xA5u
#define BK_HID_REPORT_LEN      64u    /* payload bytes per report, id excluded */


/* ------------------------------------------------------------------ *
 * BLE OAD acceptance rules
 * ------------------------------------------------------------------ *
 * Recovered from oadImgIdentifyWrite (ImgHdr_2 @ 0x000407B4). The device
 * reads its currently installed 16-byte header from flash and compares it
 * against the incoming one. uid selects the mode:
 *
 *   uid "BBBB"  application-only upgrade. Accepted when
 *                 incoming.ver     != installed.ver      (differ, not newer)
 *                 incoming.rom_ver == installed.rom_ver
 *                 0 < (len >> 2)   <  0x2A01
 *
 *   uid "SSSS"  application + stack upgrade. Accepted when
 *                 incoming.rom_ver != installed.rom_ver
 *                 0 < (len >> 2)   <  0x3E01
 *
 *   anything else -> rejected, "oadImgBlockWrite: UNKNOWN UID"
 *
 * Two things worth knowing before building a modified image:
 *   - the version test is inequality, not monotonic, so there is no rollback
 *     protection: any version that differs from the installed one is taken;
 *   - no CRC over the image body is consulted in this decision. crc0/crc1 in
 *     the header are not checked here, and their algorithm is still unknown.
 *
 * This is the Bluetooth path only. The USB path goes through the mask-ROM
 * bootloader, which writes raw flash and performs none of these checks.
 */
#define OAD_UID_APP_ONLY       "BBBB"
#define OAD_UID_APP_AND_STACK  "SSSS"
#define OAD_BLK_UNIT           16u      /* len>>2 counts 16-byte OAD blocks   */
#define OAD_MAX_BLK_APP        0x2A00u  /* 172032 bytes of application        */
#define OAD_MAX_BLK_APP_STACK  0x3E00u  /* 253952 bytes app + stack           */

#endif /* ZEPHYR_H */
