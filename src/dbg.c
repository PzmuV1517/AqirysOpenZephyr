/* Debug output
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * dbg_printf_2   @ 0x00036f84   (2 bytes)
 * called by : Default_Profile, FLASH_RD_Global, FLASH_RD_Macro, FLASH_RD_Profile, FLASH_WR_Profile, FLASH_wr_Global, ... (+23 more)
 */

void dbg_printf_2(void)

{
  return;
}

/* ==========================================================================
 * dbg_printf   @ 0x0003b77e   (4 bytes)
 * called by : APP_PARAM_UPDATE_REQ_IN, APP_PARAM_UPDATE_REQ_IND, APP_PARAM_UPDATE_REQ_IND_2, APP_PARAM_UPDATE_REQ_IND_3, BLE_PAIR, Default_Profile, ... (+167 more)
 */

undefined4 dbg_printf(void)

{
  return 0;
}

/* ==========================================================================
 * uart2_isr   @ 0x0003b836   (76 bytes)
 * called by : ble_sub_3c008
 * calls     : misc_sub_3b7d4, dbg_printf
 * string    : "uart2_isr"
 */

void uart2_isr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  puVar1 = shared_ro_3b8c0;
  uVar4 = *(uint *)(shared_ro_3b8c0 + 0x14);
  dbg_printf(&dbg_ro_3b8d8,dbg_ro_3b8d4,param_3,param_4,param_4);
  puVar3 = shared_ro_3b8cc;
  puVar2 = shared_ro_3b8c8;
  if ((uVar4 & 0x42) != 0) {
    while (*(int *)(puVar1 + 8) << 10 < 0) {
      puVar3[*(int *)(puVar2 + 8)] = (char)((uint)*(undefined4 *)(puVar1 + 0xc) >> 8);
      misc_sub_3b7d4(puVar3[*(int *)(puVar2 + 8)]);
      *(int *)(puVar2 + 8) = *(int *)(puVar2 + 8) + 1;
      if (*(int *)(puVar2 + 8) == 0x80) {
        *(undefined4 *)(puVar2 + 8) = 0;
      }
    }
    if ((int)(uVar4 << 0x19) < 0) {
      *puVar2 = 1;
    }
  }
  *(uint *)(puVar1 + 0x14) = uVar4;
  return;
}
