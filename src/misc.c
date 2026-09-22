/* Unclassified
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * thunk_FUN_000289f0   @ 0x000287e0   (4 bytes)
 */

void thunk_FUN_000289f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_289f4)();
  return;
}

/* ==========================================================================
 * thunk_FUN_000289f8   @ 0x000287e4   (4 bytes)
 */

void thunk_FUN_000289f8(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_289fc)();
  return;
}

/* ==========================================================================
 * thunk_FUN_00028a00   @ 0x000287e8   (4 bytes)
 */

void thunk_FUN_00028a00(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_28a04)();
  return;
}

/* ==========================================================================
 * thunk_FUN_00028a08   @ 0x000287ec   (4 bytes)
 */

void thunk_FUN_00028a08(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_28a0c)();
  return;
}

/* ==========================================================================
 * thunk_FUN_00028ac0   @ 0x000287f0   (4 bytes)
 */

void thunk_FUN_00028ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  ble_sub_3c008();
                    /* WARNING: Could not recover jumptable at 0x00028acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + -4))(param_1,param_2,param_3,param_4);
  return;
}

/* ==========================================================================
 * thunk_FUN_00028aa0   @ 0x000287f4   (4 bytes)
 */

void thunk_FUN_00028aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  rf24_sub_3c0a8();
                    /* WARNING: Could not recover jumptable at 0x00028aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + -4))(param_1,param_2,param_3,param_4);
  return;
}

/* ==========================================================================
 * thunk_FUN_00028a10   @ 0x000287f8   (4 bytes)
 */

void thunk_FUN_00028a10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_28a14)();
  return;
}

/* ==========================================================================
 * misc_sub_289f0   @ 0x000289f0   (4 bytes)
 */

void misc_sub_289f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_289f4)();
  return;
}

/* ==========================================================================
 * misc_sub_289f8   @ 0x000289f8   (4 bytes)
 */

void misc_sub_289f8(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_289fc)();
  return;
}

/* ==========================================================================
 * misc_sub_28a00   @ 0x00028a00   (4 bytes)
 */

void misc_sub_28a00(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_28a04)();
  return;
}

/* ==========================================================================
 * misc_sub_28a08   @ 0x00028a08   (4 bytes)
 */

void misc_sub_28a08(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_28a0c)();
  return;
}

/* ==========================================================================
 * misc_sub_28a10   @ 0x00028a10   (4 bytes)
 */

void misc_sub_28a10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*misc_ro_28a14)();
  return;
}

/* ==========================================================================
 * misc_sub_294f8   @ 0x000294f8   (56 bytes)
 * calls     : rom_06EF4, rom_06F26, rom_24F9C
 */

void misc_sub_294f8(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(shared_ro_297c8 + 5,7,3,0x23);
  puVar1 = shared_ro_2977c;
  *puVar2 = 0xaa;
  puVar2[1] = puVar1[3];
  *(undefined2 *)(puVar2 + 2) = 10;
  rom_24F9C(puVar2 + 4,&misc_ro_297e4,10);
  rom_06F26(puVar2);
  puVar1[4] = 3;
  puVar1[5] = 0xaa;
  return;
}

/* ==========================================================================
 * misc_sub_29764   @ 0x00029764   (18 bytes)
 * calls     : rom_24F9C
 */

undefined1 misc_sub_29764(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_2977c;
  rom_24F9C(param_1,shared_ro_2977c + 10,shared_ro_2977c[9]);
  return puVar1[9];
}

/* ==========================================================================
 * misc_sub_2a9d0   @ 0x0002a9d0   (116 bytes)
 */

void misc_sub_2a9d0(void)

{
  char cVar1;
  short sVar2;
  undefined *puVar3;
  
  puVar3 = misc_ro_2ada4;
  cVar1 = *misc_ro_2ada4;
  *misc_ro_2ada4 = cVar1 + 1U;
  if ((byte)(cVar1 + 1U) < 100) goto LAB_0002aa30;
  *puVar3 = 0;
  sVar2 = *(short *)(puVar3 + 4);
  if (sVar2 == 0) {
    if (*(short *)(puVar3 + 6) == 4) goto LAB_0002aa0c;
LAB_0002aa02:
    if (*(short *)(puVar3 + 6) != -4) goto LAB_0002aa16;
    *(undefined2 *)(puVar3 + 4) = 0xfffc;
  }
  else {
    if (sVar2 == 4) {
      if (*(short *)(puVar3 + 6) == 0) {
        *(undefined2 *)(puVar3 + 4) = 0;
        *(undefined2 *)(puVar3 + 6) = 0xfffc;
        goto LAB_0002aa30;
      }
    }
    else if (sVar2 == 0) goto LAB_0002aa02;
LAB_0002aa16:
    if ((sVar2 == -4) && (*(short *)(puVar3 + 6) == 0)) {
      *(undefined2 *)(puVar3 + 4) = 0;
      *(undefined2 *)(puVar3 + 6) = 4;
      goto LAB_0002aa30;
    }
LAB_0002aa0c:
    *(undefined2 *)(puVar3 + 4) = 4;
  }
  *(undefined2 *)(puVar3 + 6) = 0;
LAB_0002aa30:
  *(undefined2 *)misc_ro_2ada8 = *(undefined2 *)(puVar3 + 4);
  *(undefined2 *)misc_ro_2adac = *(undefined2 *)(puVar3 + 6);
  *misc_ro_2adb0 = 1;
  return;
}

/* ==========================================================================
 * misc_sub_2af72   @ 0x0002af72   (192 bytes)
 */

void misc_sub_2af72(void)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  if (*misc_ro_2b0dc != '\0') {
    *misc_ro_2b0dc = *misc_ro_2b0dc + -1;
  }
  if (*misc_ro_2b0e0 != '\0') {
    *misc_ro_2b0e0 = *misc_ro_2b0e0 + -1;
  }
  if (*misc_ro_2b0e4 != '\0') {
    *misc_ro_2b0e4 = *misc_ro_2b0e4 + -1;
  }
  if (*misc_ro_2b0e8 != '\0') {
    *misc_ro_2b0e8 = *misc_ro_2b0e8 + -1;
  }
  puVar3 = misc_ro_2b0f0;
  bVar1 = misc_ro_2b0ec[0x16];
  cVar2 = *misc_ro_2b0f0;
  *misc_ro_2b0f0 = cVar2 + 1U;
  if (bVar1 <= (byte)(cVar2 + 1U)) {
    *puVar3 = 0;
    *misc_ro_2b0f4 = 1;
    *misc_ro_2b0f8 = 1;
  }
  puVar4 = misc_ro_2b100;
  puVar3 = misc_ro_2b0fc;
  cVar2 = *misc_ro_2b0fc;
  *misc_ro_2b0fc = cVar2 + 1U;
  *puVar4 = 1;
  if (1 < (byte)(cVar2 + 1U)) {
    *puVar3 = 0;
    *misc_ro_2b104 = 1;
    if (*(short *)misc_ro_2b108 != 0) {
      *(short *)misc_ro_2b108 = *(short *)misc_ro_2b108 + -1;
    }
    if ((*misc_ro_2b10c != '\0') && (*misc_ro_2b110 != '\0')) {
      *misc_ro_2b10c = *misc_ro_2b10c + -1;
    }
    puVar3 = misc_ro_2b114;
    cVar2 = *misc_ro_2b114;
    *misc_ro_2b114 = cVar2 + 1U;
    if (4 < (byte)(cVar2 + 1U)) {
      *puVar3 = 0;
      *misc_ro_2b118 = 1;
      *misc_ro_2b11c = 1;
    }
    puVar3 = misc_ro_2b120;
    cVar2 = *misc_ro_2b120;
    *misc_ro_2b120 = cVar2 + 1U;
    if (0x18 < (byte)(cVar2 + 1U)) {
      *puVar3 = 0;
      *misc_ro_2b124 = 1;
    }
  }
  return;
}

/* ==========================================================================
 * WDT_REG0X0   @ 0x0002b334   (78 bytes)
 * calls     : dbg_printf
 * string    : "WDT_REG0X0 = %x\r\n"
 * string    : "reg30=%x"
 * string    : " /reg31=%x"
 * string    : " /reg33=%x"
 * string    : " /reg35=%x\r\n"
 * string    : "reg03=%x"
 * string    : " /reg04=%x"
 * string    : " /reg10=%x\r\n"
 */

void WDT_REG0X0(void)

{
  undefined *puVar1;
  
  dbg_printf(str_WDT_REG0X0_x,*(undefined4 *)misc_ro_2b5ec);
  puVar1 = shared_ro_2b524;
  dbg_printf(str_reg30_x,*(undefined4 *)(shared_ro_2b524 + 0x80));
  dbg_printf(str_reg31_x,*(undefined4 *)(puVar1 + 0x84));
  dbg_printf(str_reg33_x,*(undefined4 *)(puVar1 + 0x8c));
  dbg_printf(str_reg35_x,*(undefined4 *)(puVar1 + 0x94));
  puVar1 = shared_ro_2b638;
  dbg_printf(str_reg03_x,*(undefined4 *)(shared_ro_2b638 + 0xc));
  dbg_printf(str_reg04_x,*(undefined4 *)(puVar1 + 0x10));
  dbg_printf(str_reg10_x,*(undefined4 *)shared_ro_2b654);
  return;
}

/* ==========================================================================
 * misc_sub_2be06   @ 0x0002be06   (22 bytes)
 * calls     : dbg_printf
 */

void misc_sub_2be06(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_2be68;
  shared_ro_2be68[0x10] = 0;
  dbg_printf(str_free_d,puVar1[0x11]);
  puVar1[0x11] = 0;
  return;
}

/* ==========================================================================
 * misc_sub_2bf04   @ 0x0002bf04   (44 bytes)
 * calls     : rom_06EF4, rom_06F26
 */

void misc_sub_2bf04(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(misc_ro_2bfc0,7,3,0x20);
  *puVar1 = 0x1b;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0x24;
  *(undefined2 *)(puVar1 + 4) = 3;
  *(undefined2 *)(puVar1 + 6) = 0;
  puVar1[0xc] = 1;
  puVar1[0xd] = 1;
  rom_06F26();
  return;
}

/* ==========================================================================
 * misc_sub_2c046   @ 0x0002c046   (44 bytes)
 * calls     : rom_06EF4, rom_06F26
 */

void misc_sub_2c046(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(misc_ro_2c0d8,7,3,0xe);
  *puVar1 = 0x1b;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0x14;
  *(undefined2 *)(puVar1 + 4) = 3;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 0xc) = 0x143;
  rom_06F26();
  return;
}

/* ==========================================================================
 * misc_sub_2c0dc   @ 0x0002c0dc   (12 bytes)
 * calls     : rom_24FEC
 */

void misc_sub_2c0dc(void)

{
  rom_24FEC(misc_ro_2c2b8,3);
  return;
}

/* ==========================================================================
 * fee4   @ 0x0002c18e   (14 bytes)
 * calls     : dbg_printf
 * string    : "fee4->param->ntf_cfg = %x\r\n"
 */

undefined4 fee4(undefined4 param_1,int param_2)

{
  dbg_printf(str_fee4_param_ntf_cfg_x,*(undefined2 *)(param_2 + 2));
  return 0;
}

/* ==========================================================================
 * misc_sub_2cda6   @ 0x0002cda6   (28 bytes)
 * calls     : dbg_printf, rom_06F26
 * string    : "0x%x "
 */

undefined4 misc_sub_2cda6(void)

{
  int unaff_r4;
  int unaff_r5;
  
  do {
    dbg_printf(str_s0x_x,*(undefined1 *)(unaff_r4 + unaff_r5 + 2));
    unaff_r5 = unaff_r5 + 1;
  } while (unaff_r5 < 0x10);
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * misc_sub_2d4a0   @ 0x0002d4a0   (68 bytes)
 */

ulonglong misc_sub_2d4a0(int *param_1,undefined *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined *local_20;
  
  uVar2 = (uint)*(byte *)(param_1 + 1);
  local_20 = param_2;
  while( true ) {
    if (uVar2 == 0) {
      return ZEXT48(local_20) << 0x20;
    }
    puVar3 = (undefined4 *)(*param_1 + uVar2 * 8 + -8);
    local_20 = (undefined *)*puVar3;
    if (((undefined *)((uint)local_20 & 0xffff) == param_2) ||
       ((undefined *)((uint)local_20 & 0xffff) == misc_ro_2d8a4)) break;
    uVar2 = uVar2 - 1 & 0xff;
  }
  uVar1 = (*(code *)puVar3[1])(param_2,param_3,3);
  return CONCAT44(local_20,uVar1) & 0xffffffff000000ff;
}

/* ==========================================================================
 * misc_sub_2da7e   @ 0x0002da7e   (128 bytes)
 * calls     : dbg_printf, rom_06EF4, rom_06F26, rom_24F9C
 */

void misc_sub_2da7e(void)

{
  undefined1 *puVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  dbg_printf(misc_ro_2de5c,misc_ro_2de58);
  puVar1 = (undefined1 *)rom_06EF4(misc_ro_2de60,7,3,0x18);
  *puVar1 = 0x17;
  puVar1[1] = 1;
  rom_24F9C(puVar1 + 2,&stack0x00000000,6);
  dbg_printf(str_addr);
  uVar2 = 0;
  do {
    dbg_printf(0x2de6c,puVar1[uVar2 + 2]);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  dbg_printf(&ro_2de70);
  rom_24F9C(puVar1 + 8,&stack0x00000008,0x10);
  dbg_printf(0x2de74);
  uVar2 = 0;
  do {
    dbg_printf(0x2de6c,puVar1[uVar2 + 8]);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  dbg_printf(&ro_2de70);
  rom_06F26(puVar1);
                    /* WARNING: Could not recover jumptable at 0x0002dafc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ==========================================================================
 * APP_PARAM_UPDATE_REQ_IND_2   @ 0x0002e4cc   (38 bytes)
 * calls     : dbg_printf, rom_07342
 * string    : "APP_PARAM_UPDATE_REQ_IND--8  update param.... = %d\r\n"
 */

undefined4 APP_PARAM_UPDATE_REQ_IND_2(void)

{
  undefined *puVar1;
  undefined1 unaff_r5;
  undefined1 *unaff_r6;
  char *unaff_r7;
  
  puVar1 = misc_ro_2e804;
  if (*unaff_r7 != '\0') {
    *unaff_r6 = unaff_r5;
    *puVar1 = unaff_r5;
    dbg_printf(str_APP_PARAM_UPDATE_REQ_IND_8_update_param_d,*misc_ro_2e7b8);
    rom_07342(misc_ro_2e634,3,2);
  }
  return 0;
}

/* ==========================================================================
 * misc_sub_2f4da   @ 0x0002f4da   (36 bytes)
 * calls     : dbg_printf, rom_25078
 */

void misc_sub_2f4da(void)

{
  int extraout_r1;
  
  rom_25078();
  dbg_printf(&misc_ro_2f6c8,(extraout_r1 >> 0xc) + 0x2d);
  return;
}

/* ==========================================================================
 * misc_sub_2f61c   @ 0x0002f61c   (46 bytes)
 * calls     : dbg_printf
 */

void misc_sub_2f61c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar1 = 0x2f854;
    }
    else if (param_1 == 2) {
      uVar1 = 0x2f878;
    }
    else {
      uVar1 = 0x2f81c;
    }
    dbg_printf(uVar1);
    return;
  }
  dbg_printf(0x2f838);
  func_0x0002f64a(param_4);
  return;
}

/* ==========================================================================
 * misc_sub_2f9e4   @ 0x0002f9e4   (4 bytes)
 */

void misc_sub_2f9e4(void)

{
  undefined *puVar1;
  undefined *puVar2;
  char *pcVar3;
  
  if (*shared_ro_2fd00 == '\0' && *PTR_var_400b22_0002fd04 == '\0') {
    pcVar3 = shared_ro_2fcdc + 9;
    rom_24FEC(pcVar3,0x84);
    puVar2 = shared_ro_2fd08;
    puVar1 = shared_ro_2fcdc;
    *(char **)(shared_ro_2fcdc + 4) = pcVar3;
    if (*puVar2 != '\0') {
      *pcVar3 = *puVar2;
      *(undefined **)(puVar1 + 4) = puVar1 + 10;
    }
    flash_sub_333f0();
    *rf24_ro_2fca0 = 0xd;
  }
  return;
}

/* ==========================================================================
 * misc_sub_30f34   @ 0x00030f34   (22 bytes)
 */

void misc_sub_30f34(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uStack_10;
  undefined1 uStack_c;
  undefined3 uStack_b;
  
  _uStack_c = CONCAT31((int3)((uint)param_4 >> 8),1);
  uVar3 = param_1 + 0x15 & 0xff;
  if (4 < param_1) {
    uVar3 = 0x15;
  }
  uStack_10 = param_3;
  KEY_piaring_cnt();
  iVar2 = ble_sub_3e552(uVar3,&uStack_c,&uStack_10);
  puVar1 = flash_ro_31008;
  if (iVar2 == 0) {
    if ((uStack_10 & 0xff) < 9) {
      flash_ro_31008[0x16] = (byte)uStack_10;
      puVar1[0x17] = ~(byte)uStack_10;
    }
  }
  flash_sub_3c2c6();
  dbg_printf(str_s_read_data_x_Polling_x,flash_ro_310c4,uStack_10 & 0xff,puVar1[0x16]);
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * misc_sub_324a4   @ 0x000324a4   (118 bytes)
 */

void misc_sub_324a4(int param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined *puVar9;
  uint uVar10;
  
  puVar6 = misc_ro_325e4;
  puVar9 = misc_ro_325d8;
  *misc_ro_325d8 = 0;
  puVar5 = misc_ro_325e0;
  puVar4 = misc_ro_325dc;
  bVar1 = puVar6[0x19];
  while( true ) {
    bVar3 = *puVar9;
    uVar10 = (uint)bVar3;
    if (bVar1 <= uVar10) {
      return;
    }
    *puVar4 = puVar6[uVar10 * 2 + 0x1a];
    cVar2 = puVar6[uVar10 * 2 + 0x1b];
    *puVar5 = cVar2;
    if (cVar2 == -10) break;
    *puVar9 = bVar3 + 1;
  }
  uVar8 = uVar10 + 2 & 0xff;
  *puVar9 = (char)(uVar10 + 2);
  uVar7 = puVar6[uVar8 * 2 + 0x1a];
  *puVar4 = uVar7;
  param_1 = (uint)CONCAT11(uVar7,puVar6[uVar8 * 2 + 0x1b]) + param_1;
  *puVar5 = puVar6[uVar8 * 2 + 0x1b];
  puVar6[uVar8 * 2 + 0x1b] = (char)param_1;
  puVar6[uVar8 * 2 + 0x1a] = (char)((uint)param_1 >> 8);
  if (((*misc_ro_3258c == '\x01') || (*misc_ro_3258c == '\x02')) && (*shared_ro_32598 == '\0')) {
    uVar7 = 1;
    puVar9 = misc_ro_325e8;
  }
  else {
    uVar7 = 9;
    puVar9 = misc_ro_32554;
  }
  *puVar9 = uVar7;
  return;
}

/* ==========================================================================
 * misc_sub_32eae   @ 0x00032eae   (102 bytes)
 */

void misc_sub_32eae(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = misc_ro_32fcc;
  iVar6 = 9 - ((byte)misc_ro_32fcc[0xc] & 0xf);
  iVar1 = (uint)(byte)misc_ro_32fcc[-0x13] * 3;
  uVar3 = func_0x00024f50(misc_ro_32fcc[iVar1 + -0x15],iVar6,param_3,param_4,param_4);
  uVar4 = func_0x00024f50(puVar2[iVar1 + -0x14],iVar6);
  uVar5 = func_0x00024f50(puVar2[iVar1 + -0x13],iVar6);
  *misc_ro_32fbc = (char)((uVar3 & 0xff) >> 2);
  puVar2 = misc_ro_32fc4;
  *misc_ro_32fc0 = (char)((uVar4 & 0xff) >> 2);
  *puVar2 = (char)((uVar5 & 0xff) >> 2);
  puVar2 = misc_ro_32fd4;
  *misc_ro_32fd0 = 1;
  *puVar2 = 0;
  *misc_ro_32fd8 = 1;
  return;
}

/* ==========================================================================
 * misc_sub_32f40   @ 0x00032f40   (120 bytes)
 */

byte misc_sub_32f40(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  uint uVar5;
  
  puVar1 = misc_ro_32fbc;
  uVar5 = (uint)(byte)*misc_ro_32fc8;
  bVar4 = *misc_ro_32fe0;
  if (((*misc_ro_32fc8 & 1) != 0) && ((byte)*misc_ro_32fbc < bVar4)) {
    *misc_ro_32fbc = *misc_ro_32fbc + 1;
  }
  puVar2 = misc_ro_32fc0;
  if (((int)(uVar5 << 0x1e) < 0) && ((byte)*misc_ro_32fc0 < bVar4)) {
    *misc_ro_32fc0 = *misc_ro_32fc0 + 1;
  }
  puVar3 = misc_ro_32fc4;
  if (((int)(uVar5 << 0x1d) < 0) && ((byte)*misc_ro_32fc4 < bVar4)) {
    *misc_ro_32fc4 = *misc_ro_32fc4 + 1;
  }
  if (((int)(uVar5 << 0x1b) < 0) && (*puVar1 != '\0')) {
    *puVar1 = *puVar1 + -1;
  }
  if (((int)(uVar5 << 0x1a) < 0) && (*puVar2 != '\0')) {
    *puVar2 = *puVar2 + -1;
  }
  if (((int)(uVar5 << 0x19) < 0) && (*puVar3 != '\0')) {
    *puVar3 = *puVar3 + -1;
  }
  bVar4 = *puVar1;
  if ((byte)*puVar1 <= (byte)*puVar2) {
    bVar4 = *puVar2;
  }
  if (bVar4 <= (byte)*puVar3) {
    bVar4 = *puVar3;
  }
  return bVar4;
}

/* ==========================================================================
 * misc_sub_32fe6   @ 0x00032fe6   (40 bytes)
 * calls     : rom_24F24
 */

void misc_sub_32fe6(char *param_1)

{
  undefined *puVar1;
  short sVar2;
  
  puVar1 = shared_ro_33364;
  if (((*param_1 == '\x01') || (*param_1 == '\x02')) && (*shared_ro_33360 == '\0')) {
    if (*(short *)shared_ro_33364 != 0) {
      sVar2 = rom_24F24(*(short *)shared_ro_33364,10);
      *(short *)puVar1 = sVar2 + 1;
    }
  }
  return;
}

/* ==========================================================================
 * misc_sub_36b14   @ 0x00036b14   (34 bytes)
 */

void misc_sub_36b14(int param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_36d84;
  *(int *)(shared_ro_36d84 + 0xd8) = param_3 + 0x68;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(uint *)(puVar1 + 0xdc) = (uint)*(byte *)(param_1 + uVar2);
  }
  *(undefined4 *)(puVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * misc_sub_36f34   @ 0x00036f34   (34 bytes)
 * calls     : misc_sub_3b73e
 */

void misc_sub_36f34(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  for (uVar3 = 0; uVar3 < param_1; uVar3 = uVar3 + 1 & 0xff) {
    if (param_3 == 0) {
      cVar2 = *(char *)(param_2 + uVar3);
    }
    else {
      misc_sub_3b73e(0x20);
      bVar1 = *(byte *)(param_2 + uVar3) >> 4;
      if (bVar1 < 10) {
        cVar2 = '0';
      }
      else {
        cVar2 = '7';
      }
      misc_sub_3b73e(cVar2 + bVar1);
      bVar1 = *(byte *)(param_2 + uVar3) & 0xf;
      if (bVar1 < 10) {
        cVar2 = '0';
      }
      else {
        cVar2 = '7';
      }
      cVar2 = cVar2 + bVar1;
    }
    misc_sub_3b73e(cVar2);
  }
  return;
}

/* ==========================================================================
 * misc_sub_36f56   @ 0x00036f56   (46 bytes)
 * calls     : misc_sub_3b73e
 */

void misc_sub_36f56(uint param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint unaff_r4;
  int unaff_r5;
  uint unaff_r6;
  int unaff_r7;
  
  do {
    iVar3 = 0x30;
    while( true ) {
      misc_sub_3b73e(iVar3 + param_1);
      bVar1 = *(byte *)(unaff_r5 + unaff_r4) & 0xf;
      if (bVar1 < 10) {
        cVar2 = '0';
      }
      else {
        cVar2 = '7';
      }
      cVar2 = cVar2 + bVar1;
      while( true ) {
        misc_sub_3b73e(cVar2);
        unaff_r4 = unaff_r4 + 1 & 0xff;
        if (unaff_r6 <= unaff_r4) {
          return;
        }
        if (unaff_r7 != 0) break;
        cVar2 = *(char *)(unaff_r5 + unaff_r4);
      }
      misc_sub_3b73e(0x20);
      param_1 = (uint)(*(byte *)(unaff_r5 + unaff_r4) >> 4);
      if (param_1 < 10) break;
      iVar3 = 0x37;
    }
  } while( true );
}

/* ==========================================================================
 * misc_sub_3779a   @ 0x0003779a   (42 bytes)
 */

byte * misc_sub_3779a(byte *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  
  pbVar1 = param_1;
  while( true ) {
    if (param_2 <= (int)pbVar1 - (int)param_1) {
      return (byte *)0x0;
    }
    if ((pbVar1[1] == 4) && (pbVar1[2] == param_3)) break;
    pbVar1 = pbVar1 + *pbVar1;
  }
  return pbVar1 + *pbVar1;
}

/* ==========================================================================
 * misc_sub_377d6   @ 0x000377d6   (40 bytes)
 */

byte * misc_sub_377d6(byte *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  
  pbVar1 = param_1;
  while( true ) {
    if (param_2 <= (int)pbVar1 - (int)param_1) {
      return (byte *)0x0;
    }
    if ((pbVar1[1] == 5) && ((pbVar1[2] & 0xf) == param_3)) break;
    pbVar1 = pbVar1 + *pbVar1;
  }
  return pbVar1;
}

/* ==========================================================================
 * misc_sub_382ec   @ 0x000382ec   (34 bytes)
 * calls     : dbg_printf
 * string    : "%.2x "
 */

void misc_sub_382ec(void)

{
  uint unaff_r4;
  int unaff_r5;
  int unaff_r6;
  
  do {
    dbg_printf(str_s2x,*(undefined1 *)(unaff_r6 + unaff_r4));
    if ((~unaff_r4 & 7) == 0) {
      dbg_printf(&misc_ro_38340);
    }
    unaff_r4 = unaff_r4 + 1;
  } while ((int)unaff_r4 < unaff_r5);
  dbg_printf(misc_ro_38344);
  return;
}

/* ==========================================================================
 * misc_sub_3838c   @ 0x0003838c   (8 bytes)
 */

undefined * misc_sub_3838c(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = shared_ro_38394;
  iVar3 = 0;
  while( true ) {
    if (2 < iVar3) {
      return (undefined *)0x0;
    }
    iVar2 = usb_sub_4245e(puVar1 + iVar3 * 0xc + 0x40);
    if (iVar2 == param_1) break;
    iVar3 = iVar3 + 1;
  }
  return puVar1 + iVar3 * 0xc + 0x44;
}

/* ==========================================================================
 * misc_sub_39696   @ 0x00039696   (68 bytes)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void misc_sub_39696(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = _ro_399ac;
  puVar1 = misc_ro_399a0;
  do {
  } while (*(int *)misc_ro_399a0 < 0);
  iVar3 = *(int *)(shared_ro_3999c + 8);
  if (iVar3 != misc_ro_399a4) {
    if ((iVar3 == misc_ro_399a8) || (iVar3 == misc_ro_399a8 + -1)) {
      uVar4 = 0x10000;
    }
    else {
      uVar4 = 0x80000;
    }
    *(uint *)(misc_ro_399a0 + 0x1c) = *(uint *)(misc_ro_399a0 + 0x1c) & 0x7ffffff | uVar4;
    *(undefined4 *)puVar1 = uVar2;
    do {
    } while (*(int *)puVar1 < 0);
  }
  return;
}

/* ==========================================================================
 * misc_sub_39b36   @ 0x00039b36   (76 bytes)
 */

void misc_sub_39b36(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar1 = shared_ro_39c04;
  uVar3 = param_4 * 2;
  puVar2 = (uint *)(shared_ro_39c04 + 0xc0);
  if (param_4 < 0x10) {
    *puVar2 = *puVar2 & ~(3 << (uVar3 & 0xff));
    *puVar2 = *puVar2 | param_2 << (uVar3 & 0xff);
  }
  else {
    *(uint *)(shared_ro_39c04 + 0xc4) = *(uint *)(shared_ro_39c04 + 0xc4) & ~(3 << (uVar3 - 0x20 & 0xff));
    *(uint *)(puVar1 + 0xc4) = param_2 << (uVar3 - 0x20 & 0xff) | *(uint *)(puVar1 + 0xc4);
  }
  uVar3 = 1 << (param_4 & 0xff);
  *(uint *)(puVar1 + 0xcc) = *(uint *)(puVar1 + 0xcc) | uVar3;
  *(uint *)(puVar1 + 0xd4) = *(uint *)(puVar1 + 0xd4) | uVar3;
  *(uint *)(misc_ro_39c08 + 0xc) = *(uint *)(misc_ro_39c08 + 0xc) | uVar3;
  return;
}

/* ==========================================================================
 * misc_sub_39c1e   @ 0x00039c1e   (38 bytes)
 */

uint misc_sub_39c1e(uint param_1,int param_2,int param_3,int param_4)

{
  do {
    if (param_3 <= *(char *)(param_4 + param_1)) break;
    param_1 = param_1 + 1 & 0xff;
  } while (param_1 < 0xd);
  if (((*(char *)(param_4 + param_1) != param_3) && (param_2 == 0)) && (1 < param_1)) {
    param_1 = param_1 - 1 & 0xff;
  }
  return param_1;
}

/* ==========================================================================
 * misc_sub_3a776   @ 0x0003a776   (46 bytes)
 */

void misc_sub_3a776(int param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_3a8e0;
  uVar2 = *(uint *)(param_2 + 0x10);
  *(uint *)(shared_ro_3a8e0 + 0x90) = *(uint *)(shared_ro_3a8e0 + 0x90) & 0xffefffff;
  *(uint *)(shared_ro_3a8e0 + 0x10) = uVar2 | 0x20000000;
  *(uint *)(puVar1 + 0x90) = *(uint *)(puVar1 + 0x90) & 0xfffff87f;
  *(uint *)(puVar1 + 0x90) = *(uint *)(puVar1 + 0x90) | param_1 << 7;
  return;
}

/* ==========================================================================
 * misc_sub_3a7a4   @ 0x0003a7a4   (316 bytes)
 */

void misc_sub_3a7a4(int param_1)

{
  undefined *puVar1;
  
  puVar1 = misc_ro_3a8fc;
  if (param_1 == 0) {
    uRam00800030 = uRam00800030 & 0xffffffdf | 0x10;
    *(uint *)(misc_ro_3a8fc + 0x20) = (*(uint *)(misc_ro_3a8fc + 0x20) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x24) = (*(uint *)(puVar1 + 0x24) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x28) = (*(uint *)(puVar1 + 0x28) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x2c) = (*(uint *)(puVar1 + 0x2c) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x30) = (*(uint *)(puVar1 + 0x30) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x34) = (*(uint *)(puVar1 + 0x34) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x38) = (*(uint *)(puVar1 + 0x38) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x3c) = (*(uint *)(puVar1 + 0x3c) & 0xfffffc00) + 0x40;
  }
  else {
    if (param_1 != 1) {
      uRam00800030 = uRam00800030 | 0x10;
      if (param_1 == 2) {
        uRam00800030 = 0x34;
        *(uint *)misc_ro_3a8fc = (*(uint *)misc_ro_3a8fc & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 4) = (*(uint *)(puVar1 + 4) & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 8) = (*(uint *)(puVar1 + 8) & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 0xc) = (*(uint *)(puVar1 + 0xc) & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 0x10) = (*(uint *)(puVar1 + 0x10) & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 0x14) = (*(uint *)(puVar1 + 0x14) & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 0x18) = (*(uint *)(puVar1 + 0x18) & 0xfffffc00) + 0x40;
        *(uint *)(puVar1 + 0x1c) = (*(uint *)(puVar1 + 0x1c) & 0xfffffc00) + 0x40;
      }
      return;
    }
    uRam00800030 = uRam00800030 | 0x30;
    *(uint *)misc_ro_3a8fc = (*(uint *)misc_ro_3a8fc & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 4) = (*(uint *)(puVar1 + 4) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 8) = (*(uint *)(puVar1 + 8) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0xc) = (*(uint *)(puVar1 + 0xc) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x10) = (*(uint *)(puVar1 + 0x10) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x14) = (*(uint *)(puVar1 + 0x14) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x18) = (*(uint *)(puVar1 + 0x18) & 0xfffffc00) + 0x40;
    *(uint *)(puVar1 + 0x1c) = (*(uint *)(puVar1 + 0x1c) & 0xfffffc00) + 0x40;
  }
  uRam00800030 = uRam00800030 & 0xfffffff8 | 0xf;
  return;
}

/* ==========================================================================
 * spi_waitbusying   @ 0x0003a978   (24 bytes)
 * called by : misc_sub_3a990, misc_sub_3ab30, misc_sub_3ab60
 * calls     : dbg_printf
 * string    : "spi_waitbusying\n"
 */

void spi_waitbusying(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3ad0c;
  while (puVar1[1] == '\0') {
    dbg_printf(str_spi_waitbusying);
  }
  puVar1[1] = 0;
  return;
}

/* ==========================================================================
 * misc_sub_3a990   @ 0x0003a990   (138 bytes)
 * called by : misc_sub_3aba4
 * calls     : spi_waitbusying
 */

void misc_sub_3a990(byte *param_1,uint param_2,undefined1 *param_3,uint param_4)

{
  undefined *puVar1;
  uint uVar2;
  bool bVar3;
  byte *local_24;
  
  uVar2 = param_4;
  if (param_4 < param_2) {
    uVar2 = param_2;
  }
  if (uVar2 < 0x41) {
    spi_waitbusying();
    puVar1 = shared_ro_3ad08;
    *(uint *)(shared_ro_3ad08 + 8) = *(uint *)(shared_ro_3ad08 + 8) | 0x2000;
    *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x4000;
    *(uint *)shared_ro_3ad24 = *(uint *)shared_ro_3ad24 | 0x40;
    *(uint *)(puVar1 + 4) = uVar2 << 0x14 | uVar2 << 8;
    do {
      local_24 = param_1;
    } while (-1 < *(int *)(puVar1 + 8) << 0x1e);
    while (bVar3 = uVar2 != 0, uVar2 = uVar2 - 1, bVar3) {
      if (param_2 == 0) {
        *(undefined4 *)(puVar1 + 0xc) = 0;
      }
      else {
        *(uint *)(puVar1 + 0xc) = (uint)*local_24;
        local_24 = local_24 + 1;
        param_2 = param_2 - 1;
      }
    }
    *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 0xf;
    if (param_4 != 0) {
      do {
      } while (shared_ro_3ad0c[1] == '\0');
      while (bVar3 = param_4 != 0, param_4 = param_4 - 1, bVar3) {
        *param_3 = (char)*(undefined4 *)(puVar1 + 0xc);
        param_3 = param_3 + 1;
      }
    }
  }
  return;
}

/* ==========================================================================
 * misc_sub_3aa88   @ 0x0003aa88   (38 bytes)
 * called by : misc_sub_3ab30
 */

void misc_sub_3aa88(int param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3ad08;
  *(uint *)(shared_ro_3ad08 + 8) = *(uint *)(shared_ro_3ad08 + 8) | 0x2000;
  *(uint *)shared_ro_3ad24 = *(uint *)shared_ro_3ad24 | 0x40;
  *(int *)(puVar1 + 4) = param_1 << 8;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 5;
  return;
}

/* ==========================================================================
 * misc_sub_3aaae   @ 0x0003aaae   (38 bytes)
 * called by : misc_sub_3ab60
 */

void misc_sub_3aaae(int param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3ad08;
  *(uint *)(shared_ro_3ad08 + 8) = *(uint *)(shared_ro_3ad08 + 8) | 0x2000;
  *(uint *)shared_ro_3ad24 = *(uint *)shared_ro_3ad24 | 0x40;
  *(int *)(puVar1 + 4) = param_1 << 0x14;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 10;
  return;
}

/* ==========================================================================
 * misc_sub_3ab30   @ 0x0003ab30   (48 bytes)
 * calls     : misc_sub_3aa88, misc_sub_3c0e4, spi_waitbusying
 */

void misc_sub_3ab30(undefined4 param_1,uint param_2,undefined4 param_3)

{
  if (misc_ro_3ad2c < param_2) {
    param_2 = misc_ro_3ad2c;
  }
  *(undefined4 *)(shared_ro_3ad0c + 4) = param_3;
  spi_waitbusying();
  misc_sub_3c0e4(0,4,param_1,shared_ro_3ad08 + 0xc,param_2,0);
  misc_sub_3aa88(param_2);
  return;
}

/* ==========================================================================
 * misc_sub_3ab60   @ 0x0003ab60   (48 bytes)
 * calls     : misc_sub_3aaae, misc_sub_3c114, spi_waitbusying
 */

void misc_sub_3ab60(undefined4 param_1,uint param_2,undefined4 param_3)

{
  if (misc_ro_3ad2c < param_2) {
    param_2 = misc_ro_3ad2c;
  }
  *(undefined4 *)(shared_ro_3ad0c + 8) = param_3;
  spi_waitbusying();
  misc_sub_3c114(0,4,shared_ro_3ad08 + 0xc,param_1,param_2,0);
  misc_sub_3aaae(param_2);
  return;
}

/* ==========================================================================
 * write_2   @ 0x0003ab90   (10 bytes)
 * calls     : dbg_printf
 * string    : "write complete\r\n"
 */

void write_2(void)

{
  dbg_printf(str_write_complete);
  return;
}

/* ==========================================================================
 * read_2   @ 0x0003ab9a   (10 bytes)
 * calls     : dbg_printf
 * string    : "read complete\r\n"
 */

void read_2(void)

{
  dbg_printf(str_read_complete);
  return;
}

/* ==========================================================================
 * misc_sub_3aba4   @ 0x0003aba4   (78 bytes)
 * calls     : misc_sub_3a990, dbg_printf, rom_24FEC
 */

void misc_sub_3aba4(void)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_90 [64];
  char acStack_50 [68];
  
  cVar1 = shared_ro_3ad54[1];
  shared_ro_3ad54[1] = cVar1 + '\x01';
  iVar2 = 0;
  do {
    acStack_50[iVar2] = (char)iVar2 + cVar1 + '\x01';
    auStack_90[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  misc_sub_3a990(acStack_50,0x40,auStack_90);
  iVar2 = 0;
  do {
    dbg_printf(str_spi_rbuf_d_x,iVar2,auStack_90[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  rom_24FEC(auStack_90,0x40);
  return;
}

/* ==========================================================================
 * misc_sub_3ac82   @ 0x0003ac82   (34 bytes)
 */

void misc_sub_3ac82(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3ad08;
  *(undefined4 *)shared_ro_3ad08 = 0;
  reg_80000c = reg_80000c | 0x2000;
  *(uint *)shared_ro_3ad24 = *(uint *)shared_ro_3ad24 & 0xffffffbf;
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}

/* ==========================================================================
 * misc_sub_3aca4   @ 0x0003aca4   (94 bytes)
 * calls     : dbg_printf, rom_24FEC
 * string    : "spi len=%x:"
 */

void misc_sub_3aca4(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  
  puVar3 = shared_ro_3ad54;
  if (*shared_ro_3ad54 == '\x01') {
    dbg_printf(str_spi_len_x,shared_ro_3ad54[2]);
    puVar6 = shared_ro_3ad0c + 0x5c;
    for (iVar5 = 0; iVar5 < (int)(uint)(byte)puVar3[2]; iVar5 = iVar5 + 1) {
      dbg_printf(&misc_ro_3ad94,puVar6[iVar5]);
    }
    dbg_printf(&misc_ro_3ad98);
    rom_24FEC(shared_ro_3ad0c + 0x5c,0x50);
    puVar2 = shared_ro_3ad08;
    iVar5 = 0;
    puVar4 = shared_ro_3ad0c + 0xc;
    do {
      cVar1 = puVar4[iVar5];
      puVar4[iVar5] = cVar1 + 1U;
      *(uint *)(puVar2 + 0xc) = (uint)(byte)(cVar1 + 1U);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 10);
    *(undefined **)(puVar3 + 8) = puVar6;
    *(undefined **)(puVar3 + 4) = puVar4;
    *puVar3 = 0;
  }
  return;
}

/* ==========================================================================
 * misc_sub_3ad9c   @ 0x0003ad9c   (68 bytes)
 */

void misc_sub_3ad9c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char cVar6;
  
  puVar2 = misc_ro_3ae38;
  puVar1 = misc_ro_3ae34;
  uVar3 = *(uint *)(misc_ro_3ae34 + 8);
  if ((uVar3 & 0x600) != 0) {
    cVar6 = '\0';
    uVar4 = *(uint *)(misc_ro_3ae34 + 8);
    while (puVar2[2] = cVar6, (uVar4 & 4) != 0) {
      puVar5 = *(undefined1 **)(puVar2 + 8);
      *puVar5 = (char)*(undefined4 *)(puVar1 + 0xc);
      *(undefined1 **)(puVar2 + 8) = puVar5 + 1;
      cVar6 = puVar2[2] + '\x01';
      uVar4 = *(uint *)(puVar1 + 8);
    }
    if ((uVar3 & 0x600) != 0) {
      *puVar2 = 1;
    }
    *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x600;
  }
  return;
}

/* ==========================================================================
 * misc_sub_3b73e   @ 0x0003b73e   (12 bytes)
 * called by : misc_sub_36f34, misc_sub_36f56, misc_sub_3b74a
 */

void misc_sub_3b73e(undefined4 param_1)

{
  do {
  } while (-1 < *(int *)(shared_ro_3b8c0 + 8) << 0xb);
  *(undefined4 *)(shared_ro_3b8c0 + 0xc) = param_1;
  return;
}

/* ==========================================================================
 * misc_sub_3b74a   @ 0x0003b74a   (22 bytes)
 * called by : misc_sub_3b882
 * calls     : misc_sub_3b73e
 */

void misc_sub_3b74a(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  bool bVar2;
  
  while (bVar2 = param_2 != 0, param_2 = param_2 + -1, bVar2) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    misc_sub_3b73e(uVar1);
  }
  return;
}

/* ==========================================================================
 * misc_sub_3b760   @ 0x0003b760   (30 bytes)
 * calls     : rom_24FEC
 */

void misc_sub_3b760(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3b8c8;
  *(undefined4 *)(shared_ro_3b8c8 + 8) = 0;
  *puVar1 = 0;
  rom_24FEC(shared_ro_3b8cc,0x80);
  rom_24FEC(shared_ro_3b8cc + 0x80,0x80);
  return;
}

/* ==========================================================================
 * misc_sub_3b7ce   @ 0x0003b7ce   (6 bytes)
 */

void misc_sub_3b7ce(void)

{
  int unaff_r4;
  
  *(undefined1 *)(unaff_r4 + 1) = 0;
  return;
}

/* ==========================================================================
 * misc_sub_3b7d4   @ 0x0003b7d4   (32 bytes)
 * called by : uart2_isr
 * calls     : rom_25078
 */

void misc_sub_3b7d4(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = shared_ro_3b8c8;
  iVar2 = rom_25078();
  if (iVar2 != 1) {
    return;
  }
  puVar1[2] = 1;
  return;
}

/* ==========================================================================
 * misc_sub_3b882   @ 0x0003b882   (58 bytes)
 * calls     : misc_sub_3b74a, rom_24F9C
 */

void misc_sub_3b882(undefined4 param_1,int param_2)

{
  undefined1 local_28;
  undefined1 local_27;
  char local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  char local_22;
  undefined1 auStack_21 [25];
  
  local_28 = 4;
  local_27 = 0xe;
  local_22 = (char)param_2;
  local_26 = local_22 + '\x04';
  local_25 = 1;
  local_24 = 0xe0;
  local_23 = 0xfc;
  rom_24F9C(auStack_21,param_1,param_2);
  misc_sub_3b74a(&local_28,param_2 + 7);
  return;
}

/* ==========================================================================
 * misc_sub_3b9dc   @ 0x0003b9dc   (22 bytes)
 */

void misc_sub_3b9dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3bd10;
  *(undefined4 *)(shared_ro_3bd10 + 8) = param_3;
  *(undefined4 *)(puVar1 + 0xc) = param_4;
  *(undefined4 *)(puVar1 + 0x18) = param_1;
  *(undefined4 *)(puVar1 + 0x20) = param_2;
  puVar1[0x25] = 1;
  return;
}

/* ==========================================================================
 * misc_sub_3b9f2   @ 0x0003b9f2   (22 bytes)
 */

void misc_sub_3b9f2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3bd10;
  *(undefined4 *)shared_ro_3bd10 = param_3;
  *(undefined4 *)(puVar1 + 4) = param_4;
  *(undefined4 *)(puVar1 + 0x14) = param_1;
  *(undefined4 *)(puVar1 + 0x1c) = param_2;
  puVar1[0x24] = 1;
  return;
}

/* ==========================================================================
 * misc_sub_3c0e4   @ 0x0003c0e4   (48 bytes)
 * called by : misc_sub_3ab30
 */

void misc_sub_3c0e4(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint *puVar1;
  
  puVar1 = (uint *)(misc_ro_3c164 + param_1 * 0x20);
  puVar1[1] = param_4;
  puVar1[2] = param_3;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = param_2 << 5;
  *puVar1 = (param_5 + -1) * 0x10000 | param_6 << 6 | 0x121;
  return;
}

/* ==========================================================================
 * misc_sub_3c114   @ 0x0003c114   (48 bytes)
 * called by : misc_sub_3ab60
 */

void misc_sub_3c114(int param_1,uint param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint *puVar1;
  
  puVar1 = (uint *)(misc_ro_3c164 + param_1 * 0x20);
  puVar1[1] = param_4;
  puVar1[2] = param_3;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = param_2;
  *puVar1 = param_5 * 0x10000 - 0xfe00U | param_6 << 4 | misc_ro_3c168;
  return;
}

/* ==========================================================================
 * misc_sub_3c2e6   @ 0x0003c2e6   (82 bytes)
 * calls     : rom_24F24
 */

void misc_sub_3c2e6(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = rom_24F24(param_3,1000);
  puVar1 = shared_ro_3c4e4;
  if (param_1 == 0) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xfe;
    *(undefined4 *)puVar1 = uVar2;
    uVar3 = *(uint *)(puVar1 + 0xc);
    uVar4 = 1;
  }
  else if (param_1 == 1) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xfd;
    *(undefined4 *)(puVar1 + 4) = uVar2;
    uVar3 = *(uint *)(puVar1 + 0xc);
    uVar4 = 2;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xfb;
    *(undefined4 *)(puVar1 + 8) = uVar2;
    uVar3 = *(uint *)(puVar1 + 0xc);
    uVar4 = 4;
  }
  *(uint *)(puVar1 + 0xc) = uVar3 | uVar4;
  return;
}

/* ==========================================================================
 * misc_sub_3c338   @ 0x0003c338   (100 bytes)
 * calls     : rom_24F24
 */

void misc_sub_3c338(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = rom_24F24(param_2 << 5,1000);
  puVar2 = shared_ro_3c4e8;
  puVar1 = shared_ro_3c4e0;
  if (param_1 == 0) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xef;
    *(undefined4 *)puVar2 = uVar3;
    *(undefined4 *)(puVar1 + 0x24) = uVar3;
    uVar4 = *(uint *)(puVar2 + 0xc);
    uVar5 = 1;
  }
  else if (param_1 == 1) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xdf;
    *(undefined4 *)(puVar2 + 4) = uVar3;
    *(undefined4 *)(puVar1 + 0x28) = uVar3;
    uVar4 = *(uint *)(puVar2 + 0xc);
    uVar5 = 2;
  }
  else {
    if (param_1 != 2) goto LAB_0003c37e;
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xbf;
    *(undefined4 *)(puVar2 + 8) = uVar3;
    *(undefined4 *)(puVar1 + 0x2c) = uVar3;
    uVar4 = *(uint *)(puVar2 + 0xc);
    uVar5 = 4;
  }
  *(uint *)(puVar2 + 0xc) = uVar4 | uVar5;
LAB_0003c37e:
  *(uint *)shared_ro_3c4ec = *(uint *)shared_ro_3c4ec | 8;
  return;
}

/* ==========================================================================
 * misc_sub_3c39c   @ 0x0003c39c   (82 bytes)
 * calls     : rom_24F24
 */

void misc_sub_3c39c(int param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = rom_24F24(param_2 << 5,1000);
  puVar1 = shared_ro_3c4e8;
  if (param_1 == 0) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xef;
    *(undefined4 *)puVar1 = uVar2;
    uVar3 = *(uint *)(puVar1 + 0xc);
    uVar4 = 1;
  }
  else if (param_1 == 1) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xdf;
    *(undefined4 *)(puVar1 + 4) = uVar2;
    uVar3 = *(uint *)(puVar1 + 0xc);
    uVar4 = 2;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xbf;
    *(undefined4 *)(puVar1 + 8) = uVar2;
    uVar3 = *(uint *)(puVar1 + 0xc);
    uVar4 = 4;
  }
  *(uint *)(puVar1 + 0xc) = uVar3 | uVar4;
  return;
}

/* ==========================================================================
 * misc_sub_3c51a   @ 0x0003c51a   (20 bytes)
 */

void misc_sub_3c51a(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_2 + 4) = param_1 << 0x1f;
  do {
    iVar1 = func_0x0003c4fc();
  } while (iVar1 != 0);
  func_0x0003c50c();
  return;
}

/* ==========================================================================
 * misc_sub_3c534   @ 0x0003c534   (64 bytes)
 * calls     : misc_sub_3c75a
 */

void misc_sub_3c534(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_10;
  undefined3 local_f;
  undefined2 local_c;
  short local_a;
  
  _local_c = CONCAT22(*(short *)(param_1 + 6) + 2000,param_4);
  cVar1 = param_1[4];
  if (cVar1 != '\0') {
    cVar1 = cVar1 + -1;
  }
  _local_c = CONCAT31(stack0xfffffff5,cVar1);
  cVar1 = param_1[3];
  if (cVar1 != '\0') {
    cVar1 = cVar1 + -1;
  }
  _local_10 = CONCAT31(CONCAT21(CONCAT11(cVar1,param_1[2]),param_1[1]),*param_1);
  uVar2 = misc_sub_3c75a(&local_10);
  *(undefined4 *)(shared_ro_3c804 + 0x10) = uVar2;
  return;
}

/* ==========================================================================
 * misc_sub_3c57a   @ 0x0003c57a   (264 bytes)
 * calls     : misc_sub_3c738, rom_24F24
 */

void misc_sub_3c57a(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 extraout_r1;
  undefined4 extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int extraout_r1_07;
  uint uVar6;
  undefined8 uVar7;
  
  uVar7 = rom_24F24(param_2,misc_ro_3c808,param_2,param_4,param_4);
  uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar6 = (uint)uVar7;
  uVar2 = rom_24F24(uVar5,0xe10);
  param_1[2] = uVar2;
  rom_24F24(uVar5,0x3c);
  *param_1 = extraout_r1;
  uVar2 = rom_24F24(extraout_r1_00,0x3c);
  param_1[1] = uVar2;
  *(undefined2 *)(param_1 + 6) = 2000;
  while( true ) {
    uVar6 = uVar6 & 0xffff;
    uVar1 = *(ushort *)(param_1 + 6);
    rom_24F24(uVar1,400);
    if ((extraout_r1_02 == 0) || ((rom_24F24(uVar1,100), extraout_r1_03 != 0 && ((uVar1 & 3) == 0)))
       ) {
      uVar3 = 0x16e;
    }
    else {
      uVar3 = 0x16d;
    }
    if (uVar6 < uVar3) break;
    if ((extraout_r1_02 == 0) || ((rom_24F24(uVar1,100), extraout_r1_01 != 0 && ((uVar1 & 3) == 0)))
       ) {
      iVar4 = 0x16e;
    }
    else {
      iVar4 = 0x16d;
    }
    uVar6 = uVar6 - iVar4;
    *(ushort *)(param_1 + 6) = uVar1 + 1;
  }
  param_1[4] = 0;
  while( true ) {
    uVar1 = *(ushort *)(param_1 + 6);
    rom_24F24(uVar1,400);
    if ((extraout_r1_06 == 0) || ((rom_24F24(uVar1,100), extraout_r1_07 != 0 && ((uVar1 & 3) == 0)))
       ) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    uVar3 = misc_sub_3c738(uVar5,param_1[4]);
    if (uVar6 < uVar3) break;
    uVar1 = *(ushort *)(param_1 + 6);
    rom_24F24(uVar1,400);
    if ((extraout_r1_04 == 0) || ((rom_24F24(uVar1,100), extraout_r1_05 != 0 && ((uVar1 & 3) == 0)))
       ) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    iVar4 = misc_sub_3c738(uVar5,param_1[4]);
    uVar6 = uVar6 - iVar4 & 0xffff;
    param_1[4] = param_1[4] + '\x01';
  }
  param_1[3] = (char)uVar6;
  return;
}

/* ==========================================================================
 * misc_sub_3c738   @ 0x0003c738   (34 bytes)
 * called by : misc_sub_3c57a, misc_sub_3c75a
 */

char misc_sub_3c738(char param_1,uint param_2)

{
  char cVar1;
  
  cVar1 = '\x1f';
  if (param_2 != 1) {
    if (6 < param_2) {
      param_2 = param_2 - 1 & 0xff;
    }
    if ((param_2 & 1) != 0) {
      cVar1 = '\x1e';
    }
    return cVar1;
  }
  return param_1 + '\x1c';
}

/* ==========================================================================
 * misc_sub_3c75a   @ 0x0003c75a   (164 bytes)
 * called by : misc_sub_3c534
 * calls     : misc_sub_3c738, rom_24F24
 */

int misc_sub_3c75a(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  
  bVar1 = param_1[2];
  uVar7 = (uint)param_1[3];
  bVar2 = param_1[1];
  bVar3 = *param_1;
  uVar8 = (uint)(char)param_1[4];
  while (uVar8 = (int)((uVar8 - 1) * 0x1000000) >> 0x18, -1 < (int)uVar8) {
    uVar6 = *(ushort *)(param_1 + 6);
    rom_24F24(uVar6,400);
    if ((extraout_r1 == 0) || ((rom_24F24(uVar6,100), extraout_r1_00 != 0 && ((uVar6 & 3) == 0)))) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    iVar5 = misc_sub_3c738(uVar4,uVar8 & 0xff);
    uVar7 = iVar5 + uVar7 & 0xffff;
  }
  uVar6 = *(ushort *)(param_1 + 6);
  while( true ) {
    uVar6 = uVar6 - 1;
    if (uVar6 < 2000) break;
    rom_24F24(uVar6,400);
    if ((extraout_r1_01 == 0) || ((rom_24F24(uVar6,100), extraout_r1_02 != 0 && ((uVar6 & 3) == 0)))
       ) {
      iVar5 = 0x16e;
    }
    else {
      iVar5 = 0x16d;
    }
    uVar7 = iVar5 + uVar7 & 0xffff;
  }
  return misc_ro_3c808 * uVar7 + ((uint)bVar1 * 0x3c + (uint)bVar2) * 0x3c + (uint)bVar3;
}

/* ==========================================================================
 * misc_sub_3dd56   @ 0x0003dd56   (28 bytes)
 * calls     : rom_06B5A, rom_16D94, rom_24F9C
 */

undefined8 misc_sub_3dd56(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  rom_06B5A(1);
  rom_24F9C(&uStack_18,misc_ro_3e104,0x10);
  rom_16D94(0,&uStack_18);
  return CONCAT44(uStack_14,uStack_18);
}

/* ==========================================================================
 * misc_sub_3e7b4   @ 0x0003e7b4   (30 bytes)
 */

void misc_sub_3e7b4(undefined1 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  *param_1 = *(undefined1 *)(param_2 + 2);
  param_1[1] = *(undefined1 *)((int)param_2 + 5);
  uVar1 = *param_2;
  param_1[2] = (char)uVar1;
  param_1[3] = (char)((ushort)uVar1 >> 8);
  param_1[4] = *(undefined1 *)(param_2 + 3);
  uVar1 = param_2[1];
  param_1[5] = (char)uVar1;
  param_1[6] = (char)((ushort)uVar1 >> 8);
  return;
}

/* ==========================================================================
 * misc_sub_3e976   @ 0x0003e976   (66 bytes)
 */

void misc_sub_3e976(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  while ((uVar2 < param_1 && (iVar1 == 0))) {
    iVar3 = uVar2 * 0x18 + param_2;
    if (*(short *)(iVar3 + 0x12) == 0) {
      if (*(char *)(uVar2 * 4 + param_3 + 2) == -1) {
        iVar1 = 0x83;
      }
    }
    else if ((*(byte *)(uVar2 * 4 + param_3 + 3) & ~*(byte *)(iVar3 + 0x16)) != 0) {
      iVar1 = 0x85;
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  return;
}

/* ==========================================================================
 * misc_sub_3e9b8   @ 0x0003e9b8   (64 bytes)
 */

void misc_sub_3e9b8(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  while ((uVar2 < param_1 && (iVar1 == 0))) {
    if ((*(short *)(uVar2 * 0x14 + param_2 + 0x12) == 0) &&
       ((iVar3 = uVar2 * 4 + param_3, *(char *)(iVar3 + 2) == -1 &&
        (*(short *)((uint)*(byte *)(iVar3 + 3) * 0x18 + param_4 + 0x12) != 0)))) {
      iVar1 = 0x83;
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  return;
}

/* ==========================================================================
 * misc_sub_3e9f8   @ 0x0003e9f8   (304 bytes)
 * calls     : rom_1EFCC
 */

void misc_sub_3e9f8(int param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar9 = 0;
  do {
    uVar3 = *(ushort *)(param_1 + 0x12);
    uVar6 = (uint)uVar3;
    if ((int)(*(ushort *)(param_1 + 0x14) - uVar6) <= (int)uVar9) {
      return;
    }
    iVar7 = uVar9 * 0x16 + param_1;
    uVar11 = uVar9;
    if (*(char *)(iVar7 + 0x16) == '\x02') {
      uVar2 = *(ushort *)(iVar7 + 0x18);
      uVar8 = (uint)uVar2;
      uVar1 = *(undefined1 *)(iVar7 + 0x17);
      if ((uVar8 <= *(ushort *)(param_1 + 0x14)) && (uVar6 + uVar9 < uVar8)) {
        uVar10 = 0;
LAB_0003eb0c:
        if (uVar10 < param_2) {
          if ((*(short *)(uVar10 * 0x18 + param_4 + 0x12) != 0) ||
             (iVar7 = rom_1EFCC(((uVar8 - uVar6) - 1 & 0xff) * 0x16 + param_1 + 0x18,2,
                                *(undefined2 *)(param_3 + uVar10 * 4)), iVar7 == 0)) break;
          iVar7 = uVar10 * 0x18 + param_4;
          *(ushort *)(iVar7 + 0x12) = uVar3 + (short)uVar9 + 1;
          *(ushort *)(iVar7 + 0x14) = uVar2;
          *(undefined1 *)(iVar7 + 0x16) = uVar1;
          uVar6 = uVar9;
          do {
            uVar6 = uVar6 + 1 & 0xff;
            iVar4 = uVar6 * 0x16 + param_1;
            if (*(char *)(iVar4 + 0x16) == '\x04') {
              for (uVar11 = 0; uVar11 < param_5; uVar11 = uVar11 + 1 & 0xff) {
                if (((*(short *)(uVar11 * 0x14 + param_7 + 0x12) == 0) &&
                    (*(byte *)(uVar11 * 4 + param_6 + 3) == uVar10)) &&
                   (iVar5 = rom_1EFCC(iVar4 + 0x18,*(undefined1 *)(iVar4 + 0x17),
                                      *(undefined2 *)(param_6 + uVar11 * 4)), iVar5 != 0)) {
                  *(short *)(uVar11 * 0x14 + param_7 + 0x12) =
                       *(short *)(param_1 + 0x12) + (short)uVar6 + 1;
                  break;
                }
              }
            }
          } while ((((uint)*(ushort *)(param_1 + 0x12) + uVar6 + 1 <=
                     (uint)*(ushort *)(param_1 + 0x14)) && (*(char *)(iVar4 + 0x16) != '\x02')) &&
                  (*(char *)(iVar4 + 0x16) != '\x01'));
          uVar11 = uVar6 - 1 & 0xff;
          *(char *)(iVar7 + 0x17) = (char)(uVar6 - 1) - (char)uVar9;
        }
      }
    }
    uVar9 = uVar11 + 1 & 0xff;
  } while( true );
  uVar10 = uVar10 + 1 & 0xff;
  goto LAB_0003eb0c;
}

/* ==========================================================================
 * misc_sub_3ec18   @ 0x0003ec18   (82 bytes)
 * called by : misc_sub_3ec6a
 * calls     : misc_sub_3efee, misc_sub_3f464, misc_sub_3fb64, misc_sub_4012e, misc_sub_40be8, misc_sub_41574, ... (+1 more)
 */

void misc_sub_3ec18(byte param_1)

{
  if (param_1 == 0x47) {
    misc_sub_3f464(0);
    return;
  }
  if (param_1 < 0x48) {
    if (param_1 == 0x14) {
      misc_sub_3efee();
      return;
    }
    if (param_1 == 0x24) {
      misc_sub_3fb64();
      return;
    }
    if (param_1 == 0x26) {
      misc_sub_41574();
    }
  }
  else {
    if (param_1 == 0x48) {
      misc_sub_4012e();
      return;
    }
    if (param_1 == 0x49) {
      misc_sub_40be8();
      return;
    }
    if (param_1 == 0x4b) {
      misc_sub_41f5e();
      return;
    }
  }
  return;
}

/* ==========================================================================
 * misc_sub_3ec6a   @ 0x0003ec6a   (116 bytes)
 * calls     : misc_sub_3ec18, dbg_printf, rom_07108, rom_07212
 * string    : "!!!!!!init_type=%x\n"
 */

void misc_sub_3ec6a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  dbg_printf(str_init_type_x,param_1,param_3,param_4,param_4);
  puVar1 = shared_ro_3eeb8;
  uVar3 = 0;
  do {
    if (param_1 == 0) {
      *(short *)(puVar1 + uVar3 * 0x18 + 0x10) = (short)(uVar3 + 9);
      rom_07108(uVar3 + 9 & 0xff);
    }
    else {
      if (param_1 != 1) {
        if (param_1 != 2) goto LAB_0003ecd2;
        puVar4 = puVar1 + uVar3 * 0x18;
        iVar2 = misc_sub_3ec18(*(undefined2 *)(puVar4 + 0x12));
        if (iVar2 != 0) {
          (**(code **)(iVar2 + 4))(puVar4);
        }
        rom_07212(puVar4[0x10]);
      }
      iVar2 = uVar3 * 0x18;
      *(undefined4 *)(puVar1 + iVar2 + 0xc) = 0;
      *(undefined2 *)(puVar1 + iVar2 + 0x12) = 0xff;
      *(undefined4 *)(puVar1 + iVar2) = 0;
      *(undefined4 *)(puVar1 + iVar2 + 4) = 0;
      *(undefined2 *)(puVar1 + iVar2 + 8) = 0;
      *(undefined2 *)(puVar1 + iVar2 + 10) = 0;
    }
LAB_0003ecd2:
    uVar3 = uVar3 + 1 & 0xff;
    if (9 < uVar3) {
      return;
    }
  } while( true );
}

/* ==========================================================================
 * misc_sub_3ee3a   @ 0x0003ee3a   (52 bytes)
 */

uint misc_sub_3ee3a(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  uVar1 = 0;
  do {
    if ((uint)*(ushort *)(shared_ro_3eeb8 + uVar1 * 0x18 + 0x10) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(shared_ro_3eeb8 + uVar1 * 0x18 + 0x12);
      break;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return param_1 & 0xffffff00 | uVar2;
}

/* ==========================================================================
 * misc_sub_3efc6   @ 0x0003efc6   (36 bytes)
 * calls     : rom_06DF6, rom_17A12
 */

void misc_sub_3efc6(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (*(int *)(iVar1 + 4) != 0) {
    rom_17A12(iVar1 + 4);
    rom_06DF6();
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(iVar1);
  return;
}

/* ==========================================================================
 * misc_sub_3efee   @ 0x0003efee   (6 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_3efee(void)

{
  return misc_ro_4624c;
}

/* ==========================================================================
 * misc_sub_3eff4   @ 0x0003eff4   (54 bytes)
 */

uint misc_sub_3eff4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(ushort *)(param_1 + 0xc) + 1 & 0xffff;
  uVar1 = 0;
  do {
    if ((*(ushort *)(param_1 + 0xe) >> uVar1 & 1) != 0) {
      if (uVar2 + 1 == param_2) {
        return uVar1;
      }
      uVar2 = uVar2 + 2 & 0xffff;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 9);
  return 9;
}

/* ==========================================================================
 * misc_sub_3f02a   @ 0x0003f02a   (60 bytes)
 */

short misc_sub_3f02a(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = *(short *)(param_1 + 0xc) + 1;
  uVar2 = 0;
  do {
    if ((*(ushort *)(param_1 + 0xe) >> (uVar2 & 0xff) & 1) != 0) {
      if (param_2 == uVar2) {
        sVar1 = sVar1 + 1;
        break;
      }
      sVar1 = sVar1 + 2;
    }
    uVar2 = (int)((uVar2 + 1) * 0x1000000) >> 0x18;
  } while ((int)uVar2 < 9);
  if (uVar2 == 9) {
    sVar1 = 0;
  }
  return sVar1;
}

/* ==========================================================================
 * misc_sub_3f066   @ 0x0003f066   (42 bytes)
 */

undefined4 misc_sub_3f066(int param_1,uint param_2)

{
  if (param_2 < 0x81) {
    if (param_1 == 6) {
      if (param_2 == 8) {
        return 0;
      }
    }
    else if (param_1 == 7) {
      if (5 < param_2) {
        return 0;
      }
    }
    else {
      if (param_1 != 8) {
        return 0;
      }
      if (param_2 == 7) {
        return 0;
      }
    }
  }
  return 0x8d;
}

/* ==========================================================================
 * misc_sub_3f370   @ 0x0003f370   (28 bytes)
 * calls     : rom_06DF6
 */

void misc_sub_3f370(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 4) != 0) {
    rom_06DF6();
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(iVar1);
  return;
}

/* ==========================================================================
 * misc_sub_3f464   @ 0x0003f464   (6 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_3f464(void)

{
  return misc_ro_462e4;
}

/* ==========================================================================
 * misc_sub_3fa7a   @ 0x0003fa7a   (28 bytes)
 * calls     : rom_06DF6
 */

void misc_sub_3fa7a(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0x14) != 0) {
    rom_06DF6();
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(iVar1);
  return;
}

/* ==========================================================================
 * misc_sub_3fb64   @ 0x0003fb64   (6 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_3fb64(void)

{
  return misc_ro_463d8;
}

/* ==========================================================================
 * misc_sub_3fd3a   @ 0x0003fd3a   (18 bytes)
 * calls     : rom_06F26
 */

undefined4 misc_sub_3fd3a(int param_1)

{
  *(undefined1 *)(param_1 + 1) = 0x89;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * misc_sub_4008a   @ 0x0004008a   (28 bytes)
 * calls     : rom_06DF6
 */

void misc_sub_4008a(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 4) != 0) {
    rom_06DF6();
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(iVar1);
  return;
}

/* ==========================================================================
 * misc_sub_4012e   @ 0x0004012e   (6 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_4012e(void)

{
  return misc_ro_464ac;
}

/* ==========================================================================
 * misc_sub_40528   @ 0x00040528   (28 bytes)
 * calls     : rom_06DF6
 */

void misc_sub_40528(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 4) != 0) {
    rom_06DF6();
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(iVar1);
  return;
}

/* ==========================================================================
 * misc_sub_40be8   @ 0x00040be8   (4 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_40be8(void)

{
  return misc_ro_40cdc;
}

/* ==========================================================================
 * misc_sub_40d28   @ 0x00040d28   (12 bytes)
 * calls     : rom_06F26
 */

undefined4 misc_sub_40d28(int param_1)

{
  *(undefined1 *)(param_1 + 1) = 0x89;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * misc_sub_41540   @ 0x00041540   (16 bytes)
 * calls     : rom_06DF6
 */

void misc_sub_41540(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(uVar1);
  return;
}

/* ==========================================================================
 * misc_sub_41552   @ 0x00041552   (34 bytes)
 */

void misc_sub_41552(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  for (uVar1 = 0; uVar1 < *(byte *)(iVar2 + 0x1b); uVar1 = uVar1 + 1 & 0xff) {
    *(undefined2 *)(uVar1 * 8 + iVar2 + param_2 * 2 + 6) = 0;
  }
  return;
}

/* ==========================================================================
 * misc_sub_41574   @ 0x00041574   (6 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_41574(void)

{
  return misc_ro_46740;
}

/* ==========================================================================
 * misc_sub_4157a   @ 0x0004157a   (276 bytes)
 */

undefined4 misc_sub_4157a(int param_1,uint param_2,byte *param_3,char *param_4,byte *param_5)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x14);
  *param_4 = '\x17';
  *param_3 = 0;
  while( true ) {
    bVar1 = *param_3;
    if ((uint)*(byte *)(param_1 + 0x1b) <= (uint)bVar1) {
      return 0x80;
    }
    if (param_2 < uVar5) {
      return 0x80;
    }
    uVar6 = *(byte *)((uint)bVar1 * 8 + param_1 + 8) + uVar5;
    if (param_2 < uVar6) break;
    uVar5 = uVar6 & 0xffff;
    *param_3 = bVar1 + 1;
  }
  *param_5 = 0;
  iVar7 = (uint)*param_3 * 8 + param_1;
  uVar6 = *(byte *)(iVar7 + 10) + uVar5;
  cVar4 = (char)param_2;
  if (param_2 < uVar6) {
    if (param_2 == uVar5) {
      *param_4 = '\0';
      return 0;
    }
    uVar2 = *(ushort *)(iVar7 + 4);
    uVar6 = (uint)uVar2;
    if (((int)(uVar6 << 0x1c) < 0) && (uVar5 = uVar5 + 1 & 0xffff, param_2 == uVar5)) {
      cVar3 = '\x01';
    }
    else {
      uVar5 = uVar5 + 7 & 0xffff;
      if (uVar5 < param_2) {
        if (((int)(uVar6 << 0x1c) < 0) && (uVar5 = uVar5 + 1 & 0xffff, param_2 == uVar5)) {
          *param_4 = '\b';
          return 0;
        }
        if (((int)(uVar6 << 0x1d) < 0) && (uVar5 = uVar5 + 2 & 0xffff, param_2 <= uVar5)) {
          cVar4 = (char)uVar5 - cVar4;
          cVar3 = '\v';
        }
        else if (((uVar2 & 1) == 0) || (uVar5 = uVar5 + 5 & 0xffff, uVar5 < param_2)) {
          if (-1 < (int)(uVar6 << 0x1e)) {
            return 0;
          }
          uVar5 = uVar5 + 3 & 0xffff;
          if (uVar5 < param_2) {
            return 0;
          }
          cVar4 = (char)uVar5 - cVar4;
          cVar3 = '\x13';
        }
        else {
          cVar4 = (char)uVar5 - cVar4;
          cVar3 = '\x10';
        }
        cVar3 = cVar3 - cVar4;
      }
      else {
        cVar3 = '\b' - ((char)uVar5 - cVar4);
      }
    }
  }
  else {
    uVar6 = uVar6 & 0xffff;
    while( true ) {
      iVar7 = (uint)*param_3 * 8 + param_1;
      bVar1 = *param_5;
      if ((uint)*(byte *)(iVar7 + 9) <= (uint)bVar1) {
        return 0;
      }
      uVar6 = uVar6 + 3 & 0xffff;
      if (param_2 <= uVar6) break;
      if ((((uint)*(ushort *)(iVar7 + 4) & 0x40 << (uint)bVar1) != 0) &&
         (uVar6 = uVar6 + 1 & 0xffff, param_2 == uVar6)) {
        cVar3 = '\x16';
        goto LAB_0004167e;
      }
      *param_5 = bVar1 + 1;
    }
    cVar3 = '\x16' - ((char)uVar6 - cVar4);
  }
LAB_0004167e:
  *param_4 = cVar3;
  return 0;
}

/* ==========================================================================
 * misc_sub_4186c   @ 0x0004186c   (32 bytes)
 * calls     : rom_06EF4, rom_06F26
 */

undefined4 misc_sub_4186c(void)

{
  undefined1 *puVar1;
  undefined1 *unaff_r4;
  
  puVar1 = (undefined1 *)rom_06EF4(shared_ro_41c4c);
  *puVar1 = *unaff_r4;
  puVar1[1] = 0x89;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * misc_sub_41efc   @ 0x00041efc   (42 bytes)
 * calls     : rom_06DF6
 */

void misc_sub_41efc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 4) != 0) {
    rom_06DF6();
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(iVar1);
  return;
}

/* ==========================================================================
 * misc_sub_41f5e   @ 0x00041f5e   (4 bytes)
 * called by : misc_sub_3ec18
 */

undefined * misc_sub_41f5e(void)

{
  return misc_ro_41fb4;
}

/* ==========================================================================
 * misc_sub_4294c   @ 0x0004294c   (18 bytes)
 * calls     : thunk_FUN_00042af0
 */

longlong misc_sub_4294c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  puVar1 = misc_ro_42968;
  for (puVar3 = (undefined4 *)misc_ro_42964; puVar3 < puVar1; puVar3 = puVar3 + 4) {
    param_3 = puVar3[2];
    (*(code *)puVar3[3])(*puVar3,puVar3[1]);
  }
  uVar4 = func_0x00028ad8();
  uVar2 = (uint)uVar4;
  if (0x1f < (int)param_3) {
    return (ulonglong)(uVar2 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44((int)((ulonglong)uVar4 >> 0x20) << (param_3 & 0xff) |
                  uVar2 >> (0x20 - param_3 & 0xff),uVar2 << (param_3 & 0xff));
}

/* ==========================================================================
 * thunk_FUN_00042af0   @ 0x00042ae0   (4 bytes)
 * called by : misc_sub_4294c
 */

void thunk_FUN_00042af0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -4) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

/* ==========================================================================
 * misc_sub_42af0   @ 0x00042af0   (24 bytes)
 */

void misc_sub_42af0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -4) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

/* ==========================================================================
 * misc_sub_4407a   @ 0x0004407a   (4 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void misc_sub_4407a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
