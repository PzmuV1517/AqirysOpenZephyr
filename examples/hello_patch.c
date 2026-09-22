/* Minimal worked example: code compiled on the host, injected into the stock
 * image, calling a function that already exists in the firmware.
 *
 * dbg_printf lives at 0x0003B77E and is the routine the firmware itself uses
 * for all of its logging - 513 call sites. Firmware functions are Thumb, so
 * the low bit is set in the pointer to keep the core in Thumb state.
 *
 * Build:
 *   python3 tools/mkpatch.py firmware/zephyr2_container.bin \
 *           examples/hello_patch.c -o /tmp/patched.bin --ver 0x0026
 */
typedef void (*printf_fn)(const char *fmt, ...);

#define dbg_printf ((printf_fn)(0x0003B77Eu | 1u))

void patch_hello(void)
{
    dbg_printf("hello from a compiled patch\r\n");
}

/* Something with a little arithmetic, so the disassembly is worth reading. */
unsigned patch_sum(const unsigned char *p, unsigned n)
{
    unsigned s = 0;
    while (n--)
        s += *p++;
    return s;
}
