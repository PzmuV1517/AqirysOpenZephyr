/* memdump - read device memory out of a running Zephyr.
 *
 * Purpose: the 71 mask-ROM entry points the application calls have no bodies in
 * the flash image. Reading 0x0..0x287A0 off a live device would turn all of them
 * into readable code, and would also show the real SRAM layout, which nothing so
 * far has measured.
 *
 * STAGED ROLLOUT. This file is written to be injected FIRST WITH NO HOOK, so not
 * one instruction of it ever executes. That flash proves the pipeline - image
 * growth, checksums, erase extent, write, and that the device still boots - with
 * zero execution risk. The hook comes only after that has succeeded.
 *
 *   stage 1:  mkpatch.py ... examples/memdump.c -o patched.bin        (no --hook)
 *   stage 2:  mkpatch.py ... --hook <addr>=memdump_service
 *
 * Design rules, all of them chosen to keep a failure cheap:
 *
 *   - nothing here runs at boot. The eventual hook goes on a request path that
 *     is only reached when a specific feature report arrives, so a bug costs a
 *     replug rather than the device;
 *   - reads are bounds-checked against regions known to be plain memory;
 *   - PERIPHERALS ARE NOT READABLE. Registers at 0x00800000+ can have read side
 *     effects - clear-on-read flags, FIFO pops - so dumping them blindly could
 *     disturb a running radio or USB engine. Explicitly excluded;
 *   - byte-wise copy only. This is ARMv5TE; unaligned word loads do not fault
 *     but they rotate rather than load what you asked for;
 *   - no writes to device state, no allocation, no loops that can run away.
 */

#include <stdint.h>

/* Memory map, from include/zephyr.h. */
#define ROM_BASE    0x00000000u
#define ROM_END     0x000287A0u   /* mask ROM: the BLE stack and bootloader   */
#define APP_BASE    0x000287A0u
#define APP_END     0x00047006u   /* the application image as shipped         */
#define SRAM_BASE   0x00400000u
#define SRAM_END    0x00420000u   /* upper bound is a guess; see note below   */
#define PERIPH_BASE 0x00800000u   /* never read: side effects                 */

/* SRAM_END is not established. The copy tables at reset touch up to ~0x410000,
 * so 0x420000 is a deliberately loose ceiling. One of the things a dump answers
 * is where RAM actually stops - which is why reads are clamped rather than
 * trusted, and why a caller should walk upward and watch for the refusal. */

#define DUMP_MAX 64u              /* bytes per request, fits a feature report */

typedef struct {
    uint32_t addr;                /* where to read from                       */
    uint8_t  len;                 /* how many bytes, clamped to DUMP_MAX      */
    uint8_t  status;              /* 0 = ok, see below                        */
    uint8_t  data[DUMP_MAX];
} memdump_req_t;

#define DUMP_OK          0u
#define DUMP_BAD_RANGE   1u       /* not inside a readable region             */
#define DUMP_PERIPHERAL  2u       /* refused: register space                  */
#define DUMP_BAD_LEN     3u       /* zero length                              */

/* True only for regions that are plain memory and safe to read repeatedly. */
static int readable(uint32_t a, uint32_t n)
{
    uint32_t end = a + n;

    if (end < a)                                   /* wrapped */
        return 0;
    if (a >= PERIPH_BASE)
        return 0;
    if (end <= ROM_END)               /* ROM_BASE is 0, so no lower test */
        return 1;
    if (a >= APP_BASE  && end <= APP_END)
        return 1;
    if (a >= SRAM_BASE && end <= SRAM_END)
        return 1;
    return 0;
}

/* Fill req->data from req->addr. Returns the status it also stores. */
uint8_t memdump_read(memdump_req_t *req)
{
    const volatile uint8_t *src;
    uint8_t i, n;

    if (req->len == 0u) {
        req->status = DUMP_BAD_LEN;
        return DUMP_BAD_LEN;
    }

    n = req->len > DUMP_MAX ? (uint8_t)DUMP_MAX : req->len;

    if (req->addr >= PERIPH_BASE) {
        req->status = DUMP_PERIPHERAL;
        return DUMP_PERIPHERAL;
    }
    if (!readable(req->addr, n)) {
        req->status = DUMP_BAD_RANGE;
        return DUMP_BAD_RANGE;
    }

    src = (const volatile uint8_t *)req->addr;
    for (i = 0u; i < n; i++)
        req->data[i] = src[i];

    req->len = n;
    req->status = DUMP_OK;
    return DUMP_OK;
}

/* Hook entry point for stage 2.
 *
 * Deliberately left as the smallest possible shim: it does the read and returns.
 * Wiring it to an actual feature report needs the GET path mapped, which has not
 * been done yet - Set_Report_Data @0x3353C covers SET and logs unknown report
 * IDs as "N0N0 report_id" before dropping them, which is the natural place to
 * intercept, but the response buffer it would write into is not identified.
 *
 * Until that is known this stays unhooked, and the patch is dead code. */
uint8_t memdump_service(memdump_req_t *req)
{
    return memdump_read(req);
}
