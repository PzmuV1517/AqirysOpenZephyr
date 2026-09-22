/* Boot, vectors and reset
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * _vector_table   @ 0x000287a0   (4 bytes)
 */

void _vector_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000287a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)boot_ro_287c0)();
  return;
}

/* ==========================================================================
 * Reset_Handler   @ 0x00028824   (352 bytes)
 * calls     : boot_sub_28980, boot_sub_289a8
 */

void Reset_Handler(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = boot_ro_289cc;
  puVar3 = (undefined4 *)(boot_ro_28804 + boot_ro_28808);
  for (puVar4 = (undefined4 *)boot_ro_28804; uVar2 = boot_ro_289cc, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar1;
  }
  puVar3 = (undefined4 *)(boot_ro_28804 + boot_ro_28808);
  for (puVar4 = (undefined4 *)boot_ro_28804; uVar1 = boot_ro_289cc, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar2;
  }
  puVar3 = (undefined4 *)(boot_ro_28804 + boot_ro_28808);
  for (puVar4 = (undefined4 *)boot_ro_28804; uVar2 = boot_ro_289d0, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar1;
  }
  puVar3 = (undefined4 *)(boot_ro_2880c + boot_ro_28810);
  for (puVar4 = (undefined4 *)boot_ro_2880c; uVar1 = boot_ro_289d4, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar2;
  }
  puVar3 = (undefined4 *)(boot_ro_2881c + boot_ro_28820);
  for (puVar4 = (undefined4 *)boot_ro_2881c; uVar2 = boot_ro_289d8, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar1;
  }
  puVar3 = (undefined4 *)(boot_ro_28814 + boot_ro_28818);
  for (puVar4 = (undefined4 *)boot_ro_28814; puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar2;
  }
  boot_sub_28980();
  boot_sub_289a8();
                    /* WARNING: Could not recover jumptable at 0x00028a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)boot_ro_28a1c)(0,0,0,0);
  return;
}

/* ==========================================================================
 * boot_sub_28980   @ 0x00028980   (40 bytes)
 * called by : Reset_Handler
 */

void boot_sub_28980(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(boot_ro_289e0 + boot_ro_289e4);
  puVar1 = (undefined4 *)boot_ro_289dc;
  for (puVar2 = (undefined4 *)boot_ro_289e0; puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
  }
  return;
}

/* ==========================================================================
 * boot_sub_289a8   @ 0x000289a8   (36 bytes)
 * called by : Reset_Handler
 */

void boot_sub_289a8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(boot_ro_289e8 + boot_ro_289ec);
  for (puVar2 = (undefined4 *)boot_ro_289e8; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  return;
}

/* ==========================================================================
 * Stack_Integrity_Check   @ 0x00029170   (84 bytes)
 * called by : ble_sub_28c66
 * calls     : dbg_printf
 * string    : "Stack_Integrity_Check STACK_BASE_UNUSED fail!\r\n"
 * string    : "Stack_Integrity_Check STACK_BASE_SVC fail!\r\n"
 * string    : "Stack_Integrity_Check STACK_BASE_FIQ fail!\r\n"
 * string    : "Stack_Integrity_Check STACK_BASE_IRQ fail!\r\n"
 */

void Stack_Integrity_Check(void)

{
  if (**(int **)boot_ro_292a4 != boot_ro_292a8) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_UNUSED_fail);
    } while( true );
  }
  if (**(int **)boot_ro_292dc != boot_ro_292e0) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_SVC_fail);
    } while( true );
  }
  if (**(int **)boot_ro_29314 != boot_ro_29318) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_FIQ_fail);
    } while( true );
  }
  if (**(int **)boot_ro_2934c != boot_ro_29350) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_IRQ_fail);
    } while( true );
  }
  return;
}
