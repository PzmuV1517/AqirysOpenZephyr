/* Timers and scheduling
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * app_user_ke_timer_stop   @ 0x00029c6c   (106 bytes)
 * called by : Disconnected, app_mutli_link_change, disconnect, f_usb_isConnected, switch_rf_mode_loop
 * calls     : dbg_printf, rom_073D4
 * string    : "%s \r\n"
 * string    : "app_user_ke_timer_stop"
 */

void app_user_ke_timer_stop(void)

{
  dbg_printf(shared_ro_29cdc,str_app_user_ke_timer_stop);
  *timer_ro_29ed0 = *timer_ro_29ed0 & 0xfc;
  *(uint *)shared_ro_29dd4 = *(uint *)shared_ro_29dd4 & 0xfffffdff;
  rom_073D4(timer_ro_29ed4,3);
  rom_073D4(timer_ro_29ed4 + -3,3);
  rom_073D4(timer_ro_29ed4 + -5,3);
  rom_073D4(timer_ro_29ed4 + -7,3);
  rom_073D4(timer_ro_29ed4 + -2,3);
  rom_073D4(timer_ro_29ed4 + 1,3);
  shared_ro_29ecc[0x10] = 0;
  return;
}

/* ==========================================================================
 * rtc_timer_start   @ 0x0002f37e   (68 bytes)
 * calls     : dbg_printf
 * string    : "rtc_timer_start"
 * string    : "%s \r\n"
 */

void rtc_timer_start(uint param_1)

{
  undefined *puVar1;
  
  dbg_printf(str_s_7,str_rtc_timer_start);
  puVar1 = timer_ro_2f3e0;
  reg_80000c = reg_80000c & 0xfffffeff;
  *(uint *)(timer_ro_2f3e0 + 0xc) = (param_1 & 0x3ff) << 0x11;
  *(undefined **)timer_ro_2f3e8 = timer_ro_2f3e4;
  *(uint *)puVar1 = *(uint *)puVar1 & 3 | 0xd;
  *(undefined4 *)(puVar1 + 4) = timer_ro_2f3ec;
  *(uint *)timer_ro_2f3f0 = *(uint *)timer_ro_2f3f0 | (int)timer_ro_2f3f0 >> 0xd;
  return;
}
