/*============================================================================
 * AQIRYS Zephyr 2 - decompiled application firmware
 *
 * Chip      : Beken BLE SoC, ARMv5TE (ARM968-class), ARM + Thumb
 * Image     : 125030 bytes, linked at 0x000287A0
 * In flash  : container written at 0x0002B00A; the XIP engine strips a
 *             2-byte CRC every 32 bytes, so flash 0x2B01A -> CPU 0x287A0
 * Memory    : 0x00000000 mask ROM / bootloader (BLE stack lives here)
 *             0x000287A0 this image
 *             0x00400000 SRAM
 *
 * Reading this file
 * -----------------
 *   Functions are grouped by subsystem, then sorted by address.
 *   Each function carries its callers, callees and any debug strings it
 *   references - those strings are the firmware's own and are usually the
 *   fastest way to work out what a function does.
 *
 *   name()      - recovered from the firmware's debug strings
 *   rom_XXXXX() - call into mask ROM; body is not in this image
 *   FUN_xxxxx() - no name recoverable
 *   str_...     - a string literal, named after its own contents
 *   dbg_printf  - the firmware's debug print routine
 *
 *   Types are Ghidra's inference, not the original source. undefined/uVar
 *   names mean the decompiler could not deduce anything better.
 */

/*============================================================================
 * CONTENTS
 *
 *   Boot, vectors and reset             5 functions
 *   Firmware update (OAD/OTA)          23 functions
 *   Flash and NVM storage              56 functions
 *   USB and HID                       128 functions
 *   2.4 GHz RF link                    57 functions
 *   Bluetooth LE                      214 functions
 *   Mouse input (sensor, keys)         36 functions
 *   LED and OLED                       43 functions
 *   Power and battery                  37 functions
 *   Timers and scheduling               2 functions
 *   Debug output                        3 functions
 *   ROM entry points                   71 functions
 *   Unclassified                      110 functions
 *   TOTAL                             785
 */


/*############################################################################
 * BOOT, VECTORS AND RESET  (5 functions)
 *
 *   0x000287A0  _vector_table  (4 B)
 *   0x00028824  Reset_Handler  (352 B)
 *   0x00028980  FUN_00028980  (40 B)
 *   0x000289A8  FUN_000289a8  (36 B)
 *   0x00029170  Stack_Integrity_Check  (84 B)
 ############################################################################*/

/* ==========================================================================
 * _vector_table   @ 0x000287a0   (4 bytes)
 */

void _vector_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000287a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_Reset_Handler_000287c0)();
  return;
}

/* ==========================================================================
 * Reset_Handler   @ 0x00028824   (352 bytes)
 * calls     : FUN_00028980, FUN_000289a8
 */

void Reset_Handler(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = DAT_000289cc;
  puVar3 = (undefined4 *)(DAT_00028808 + (int)DAT_00028804);
  for (puVar4 = DAT_00028804; uVar2 = DAT_000289cc, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar1;
  }
  puVar3 = (undefined4 *)(DAT_00028808 + (int)DAT_00028804);
  for (puVar4 = DAT_00028804; uVar1 = DAT_000289cc, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar2;
  }
  puVar3 = (undefined4 *)(DAT_00028808 + (int)DAT_00028804);
  for (puVar4 = DAT_00028804; uVar2 = DAT_000289d0, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar1;
  }
  puVar3 = (undefined4 *)(DAT_00028810 + (int)DAT_0002880c);
  for (puVar4 = DAT_0002880c; uVar1 = DAT_000289d4, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar2;
  }
  puVar3 = (undefined4 *)(DAT_00028820 + (int)DAT_0002881c);
  for (puVar4 = DAT_0002881c; uVar2 = DAT_000289d8, puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar1;
  }
  puVar3 = (undefined4 *)(DAT_00028818 + (int)DAT_00028814);
  for (puVar4 = DAT_00028814; puVar4 < puVar3; puVar4 = puVar4 + 1) {
    *puVar4 = uVar2;
  }
  FUN_00028980();
  FUN_000289a8();
                    /* WARNING: Could not recover jumptable at 0x00028a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00028a1c)(0,0,0,0);
  return;
}

/* ==========================================================================
 * FUN_00028980   @ 0x00028980   (40 bytes)
 * called by : Reset_Handler
 */

void FUN_00028980(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)((int)DAT_000289e0 + DAT_000289e4);
  puVar1 = DAT_000289dc;
  for (puVar2 = DAT_000289e0; puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
  }
  return;
}

/* ==========================================================================
 * FUN_000289a8   @ 0x000289a8   (36 bytes)
 * called by : Reset_Handler
 */

void FUN_000289a8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(DAT_000289ec + (int)DAT_000289e8);
  for (puVar2 = DAT_000289e8; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  return;
}

/* ==========================================================================
 * Stack_Integrity_Check   @ 0x00029170   (84 bytes)
 * called by : FUN_00028c66
 * calls     : dbg_printf
 * string    : "Stack_Integrity_Check STACK_BASE_UNUSED fail!\r\n"
 * string    : "Stack_Integrity_Check STACK_BASE_SVC fail!\r\n"
 * string    : "Stack_Integrity_Check STACK_BASE_FIQ fail!\r\n"
 * string    : "Stack_Integrity_Check STACK_BASE_IRQ fail!\r\n"
 */

void Stack_Integrity_Check(void)

{
  if (*(int *)*DAT_000292a4 != DAT_000292a8) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_UNUSED_fail);
    } while( true );
  }
  if (*(int *)*DAT_000292dc != DAT_000292e0) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_SVC_fail);
    } while( true );
  }
  if (*(int *)*DAT_00029314 != DAT_00029318) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_FIQ_fail);
    } while( true );
  }
  if (*(int *)*DAT_0002934c != DAT_00029350) {
    do {
      dbg_printf(str_Stack_Integrity_Check_STACK_BASE_IRQ_fail);
    } while( true );
  }
  return;
}


/*############################################################################
 * FIRMWARE UPDATE (OAD/OTA)  (23 functions)
 *
 *   0x0002CA18  app_oad_add_oads  (62 B)
 *   0x00038F5A  app_usb_upgrade_start  (42 B)
 *   0x0003E7D2  FUN_0003e7d2  (46 B)
 *   0x0003E854  FUN_0003e854  (52 B)
 *   0x0003E888  FUN_0003e888  (58 B)
 *   0x0003E8C2  FUN_0003e8c2  (64 B)
 *   0x0003E902  FUN_0003e902  (86 B)
 *   0x0003EB28  FUN_0003eb28  (86 B)
 *   0x0003EE1A  FUN_0003ee1a  (16 B)
 *   0x0003EE2A  FUN_0003ee2a  (16 B)
 *   0x0003F3CC  FUN_0003f3cc  (76 B)
 *   0x0003F418  FUN_0003f418  (76 B)
 *   0x0003FB24  FUN_0003fb24  (64 B)
 *   0x0003FBDA  FUN_0003fbda  (238 B)
 *   0x000400E2  FUN_000400e2  (76 B)
 *   0x00040568  FUN_00040568  (32 B)
 *   0x00040588  oad_updating_user_section_begin  (38 B)
 *   0x000406C0  FUN_000406c0  (18 B)
 *   0x000406D2  oadImgIdentifyReq  (150 B)
 *   0x00040768  FUN_00040768  (76 B)
 *   0x000407B4  ImgHdr  (424 B)
 *   0x00040A7C  ImgHdr_2  (364 B)
 *   0x00041F62  FUN_00041f62  (78 B)
 ############################################################################*/

/* ==========================================================================
 * app_oad_add_oads   @ 0x0002ca18   (62 bytes)
 * calls     : dbg_printf, rom_06EF4, rom_06F26
 * string    : "app_oad_add_oads\r\n"
 * string    : "app_oad_add_oads d = %x,s = %x\r\n"
 */

void app_oad_add_oads(void)

{
  undefined1 *puVar1;
  
  dbg_printf(str_app_oad_add_oads);
  puVar1 = (undefined1 *)rom_06EF4(DAT_0002cb64,7,3,0xe);
  *puVar1 = 0x1b;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0x49;
  *(undefined2 *)(puVar1 + 4) = 3;
  *(undefined2 *)(puVar1 + 6) = 0;
  puVar1[0xd] = 1;
  dbg_printf(str_app_oad_add_oads_d_x_s_x,7,3);
  rom_06F26(puVar1);
  return;
}

/* ==========================================================================
 * app_usb_upgrade_start   @ 0x00038f5a   (42 bytes)
 * called by : FUN_00033a7e
 * calls     : FUN_00031784, FUN_000392b8, FUN_0003b130, dbg_printf, flash_write_some_data
 * string    : "app_usb_upgrade_start"
 * string    : "%s \r\n"
 */

void app_usb_upgrade_start(void)

{
  dbg_printf(str_s_13,DAT_00038ff0 + 0x2d);
  FUN_000392b8();
  FUN_00031784(DAT_000390a8 + 7);
  flash_write_some_data(DAT_00039194,0x7d000,0x10);
  FUN_0003b130();
  return;
}

/* ==========================================================================
 * FUN_0003e7d2   @ 0x0003e7d2   (46 bytes)
 * calls     : FUN_0003ee1a, rom_06EF4, rom_06F26
 */

void FUN_0003e7d2(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_0003ee1a();
  puVar2 = (undefined1 *)rom_06EF4(DAT_0003ebc0,param_2 * 0x100 + 6,uVar1,10);
  *puVar2 = 8;
  puVar2[1] = 1;
  *(undefined2 *)(puVar2 + 6) = 0;
  *(undefined2 *)(puVar2 + 8) = 0;
  *(undefined2 *)(puVar2 + 4) = param_5;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0003e854   @ 0x0003e854   (52 bytes)
 * calls     : FUN_0003ee1a, rom_06EF4, rom_06F26
 */

void FUN_0003e854(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (*(short *)(param_3 + 0x14) != 0) {
    uVar1 = FUN_0003ee1a(param_1,param_2);
    puVar2 = (undefined1 *)rom_06EF4(DAT_0003ebc0 + 7,param_2 * 0x100 + 6,uVar1,8);
    *puVar2 = 0x11;
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(param_3 + 0x14);
    *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_3 + 0x16);
    rom_06F26();
  }
  return;
}

/* ==========================================================================
 * FUN_0003e888   @ 0x0003e888   (58 bytes)
 * calls     : FUN_0003ee1a, rom_06EF4, rom_06F26
 */

void FUN_0003e888(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_0003ee1a();
  puVar2 = (undefined1 *)rom_06EF4(DAT_0003ebc0 + 0x11,param_2 * 0x100 + 6,uVar1,0x1a);
  *puVar2 = 0x15;
  *(undefined2 *)(puVar2 + 4) = 1;
  *(undefined2 *)(puVar2 + 6) = 0xffff;
  puVar2[1] = 2;
  puVar2[8] = (char)param_3;
  puVar2[9] = (char)((uint)param_3 >> 8);
  rom_06F26(puVar2);
  return;
}

/* ==========================================================================
 * FUN_0003e8c2   @ 0x0003e8c2   (64 bytes)
 * calls     : FUN_0003ee1a, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0003e8c2(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_0003ee1a();
  puVar2 = (undefined1 *)rom_06EF4(DAT_0003ebc0 + 0x11,param_2 * 0x100 + 6,uVar1,0x28);
  *puVar2 = 0x15;
  *(undefined2 *)(puVar2 + 4) = 1;
  *(undefined2 *)(puVar2 + 6) = 0xffff;
  puVar2[1] = 0x10;
  rom_24F9C(puVar2 + 8,param_3,0x10);
  rom_06F26(puVar2);
  return;
}

/* ==========================================================================
 * FUN_0003e902   @ 0x0003e902   (86 bytes)
 * called by : FUN_0003e958
 * calls     : FUN_0003ee1a, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0003e902(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined1 param_6,undefined2 param_7)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    uVar1 = FUN_0003ee1a();
    puVar2 = (undefined1 *)
             rom_06EF4(DAT_0003ebc0 + 2,param_2 * 0x100 + 6,uVar1,param_5 + 0xcU & 0xffff);
    *(undefined2 *)(puVar2 + 6) = 0;
    *(undefined2 *)(puVar2 + 10) = 0;
    *puVar2 = param_6;
    *(short *)(puVar2 + 4) = (short)param_3;
    *(short *)(puVar2 + 8) = (short)param_5;
    *(undefined2 *)(puVar2 + 2) = param_7;
    puVar2[1] = 1;
    rom_24F9C(puVar2 + 0xc,param_4,param_5);
    rom_06F26(puVar2);
  }
  return;
}

/* ==========================================================================
 * FUN_0003eb28   @ 0x0003eb28   (86 bytes)
 * calls     : FUN_0003ee1a, FUN_0003ee2a, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0003eb28(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined2 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  short sVar4;
  
  sVar4 = 0;
  if (param_4 == 0) {
    sVar4 = param_5[2];
  }
  uVar1 = FUN_0003ee1a(param_1,param_2);
  uVar2 = FUN_0003ee2a(param_1,param_2);
  puVar3 = (undefined2 *)rom_06EF4(param_3,uVar2,uVar1,sVar4 + 6);
  *(char *)(puVar3 + 2) = (char)param_4;
  *puVar3 = 0;
  puVar3[1] = sVar4;
  if (param_5 != (undefined2 *)0x0) {
    *puVar3 = *param_5;
    rom_24F9C((int)puVar3 + 5,param_5 + 3,sVar4);
  }
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * FUN_0003ee1a   @ 0x0003ee1a   (16 bytes)
 * called by : FUN_0003e7d2, FUN_0003e854, FUN_0003e888, FUN_0003e8c2, FUN_0003e902, FUN_0003eb28, ... (+11 more)
 */

uint FUN_0003ee1a(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(ushort *)(param_1 + 2) & 0x7fff;
  if ((short)*(ushort *)(param_1 + 2) < 0) {
    uVar1 = uVar1 | param_2 << 8;
  }
  return uVar1;
}

/* ==========================================================================
 * FUN_0003ee2a   @ 0x0003ee2a   (16 bytes)
 * called by : FUN_0003eb28, FUN_00041798, FUN_00041f62
 */

uint FUN_0003ee2a(ushort *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *param_1 & 0x7fff;
  if ((short)*param_1 < 0) {
    uVar1 = uVar1 | param_2 << 8;
  }
  return uVar1;
}

/* ==========================================================================
 * FUN_0003f3cc   @ 0x0003f3cc   (76 bytes)
 * calls     : FUN_0003ee1a, FUN_0003f3b0, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0003f3cc(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = FUN_0003ee1a(param_2,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,*(short *)(param_3 + 2) + 8);
  *puVar3 = 0x12;
  uVar1 = FUN_0003f3b0(9);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_3 + 2);
  rom_24F9C(puVar3 + 8,param_3 + 4,*(undefined2 *)(param_3 + 2));
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * FUN_0003f418   @ 0x0003f418   (76 bytes)
 * calls     : FUN_0003ee1a, FUN_0003f3b0, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0003f418(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = FUN_0003ee1a(param_2,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,*(short *)(param_3 + 2) + 8);
  *puVar3 = 0x13;
  uVar1 = FUN_0003f3b0(0xc);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_3 + 2);
  rom_24F9C(puVar3 + 8,param_3 + 4,*(undefined2 *)(param_3 + 2));
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * FUN_0003fb24   @ 0x0003fb24   (64 bytes)
 * called by : FUN_0003fbda
 * calls     : FUN_0003ee1a, FUN_0003faaa, rom_06EF4, rom_06F26
 */

void FUN_0003fb24(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = FUN_0003ee1a(param_1,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_2 * 0x100 + 6,uVar2,9);
  *puVar3 = 0x12;
  uVar1 = FUN_0003faaa(param_3,2);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = 1;
  puVar3[8] = *(undefined1 *)(param_1 + param_3 + 0x1a);
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * FUN_0003fbda   @ 0x0003fbda   (238 bytes)
 * called by : FUN_0003fd6e
 * calls     : FUN_0003edee, FUN_0003ee1a, FUN_0003fb24, rom_06DF6, rom_06EF4, rom_06F26, ... (+1 more)
 */

void FUN_0003fbda(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  
  iVar2 = FUN_0003edee(0x24);
  uVar1 = 0xff;
  iVar3 = *(int *)(iVar2 + 0x14);
  if ((undefined *)(uint)*(ushort *)(iVar3 + 4) == &DAT_00002400) {
    uVar1 = *(undefined1 *)(iVar3 + 0xc);
    while( true ) {
      bVar6 = *(byte *)(iVar2 + 0x20);
      uVar7 = (uint)bVar6;
      if (1 < uVar7) break;
      if ((((uint)*(byte *)((uint)*(byte *)(iVar3 + 0xc) + iVar2 + 0x1d) & 1 << uVar7) != 0) &&
         (*(char *)(uVar7 + iVar3 + 0xe) != *(char *)(uVar7 + iVar2 + 0x1a))) {
        bVar6 = *(byte *)(iVar3 + 0xc);
LAB_0003fc5c:
        FUN_0003fb24(iVar2,bVar6,uVar7);
        *(char *)(iVar2 + 0x20) = *(char *)(iVar2 + 0x20) + '\x01';
        return;
      }
      *(byte *)(iVar2 + 0x20) = bVar6 + 1;
    }
  }
  else if ((undefined *)(uint)*(ushort *)(iVar3 + 4) == DAT_0003fcf0) {
    while (*(char *)(iVar2 + 0x20) == '\0') {
      uVar7 = (uint)*(byte *)(iVar3 + 0xc);
      if (((uint)*(byte *)(iVar2 + 0x1d) & 1 << uVar7) != 0) {
        bVar6 = 0;
        goto LAB_0003fc5c;
      }
      *(char *)(iVar2 + 0x20) = '\x01';
    }
  }
  if ((undefined *)(uint)*(ushort *)(iVar3 + 4) == &DAT_00002400) {
    puVar4 = (undefined1 *)
             rom_06EF4(DAT_0003fcf0 + -1,*(undefined2 *)(iVar3 + 8),*(undefined2 *)(iVar3 + 6),2);
    *puVar4 = uVar1;
    puVar4[1] = 0;
  }
  else {
    if ((undefined *)(uint)*(ushort *)(iVar3 + 4) != DAT_0003fcf0) goto LAB_0003fcb0;
    puVar4 = (undefined1 *)
             rom_06EF4(DAT_0003fcf0 + 1,*(undefined2 *)(iVar3 + 8),*(undefined2 *)(iVar3 + 6),1);
    *puVar4 = 0;
  }
  rom_06F26();
LAB_0003fcb0:
  rom_06DF6(*(undefined4 *)(iVar2 + 0x14));
  *(undefined4 *)(iVar2 + 0x14) = 0;
  uVar5 = FUN_0003ee1a(iVar2,0);
  rom_07180(uVar5,0);
  return;
}

/* ==========================================================================
 * FUN_000400e2   @ 0x000400e2   (76 bytes)
 * calls     : FUN_0003ee1a, FUN_000400c6, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_000400e2(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = FUN_0003ee1a(param_2,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,*(short *)(param_3 + 2) + 8);
  *puVar3 = 0x12;
  uVar1 = FUN_000400c6(4);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_3 + 2);
  rom_24F9C(puVar3 + 8,param_3 + 4,*(undefined2 *)(param_3 + 2));
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * FUN_00040568   @ 0x00040568   (32 bytes)
 * called by : ImgHdr_2
 * calls     : rom_24F9C
 */

void FUN_00040568(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00040884;
  iVar2 = *(int *)(DAT_00040884 + 0x18) + 1;
  *(int *)(DAT_00040884 + 0x18) = iVar2;
  rom_24F9C(iVar2 * 0x10 + iVar1 + 0xe,param_1 + 2,0x10);
  *(undefined1 *)(iVar1 + 0x1c) = 1;
  return;
}

/* ==========================================================================
 * oad_updating_user_section_begin   @ 0x00040588   (38 bytes)
 * called by : ImgHdr_2
 * calls     : dbg_printf
 * string    : "oad_updating_user_section_begin"
 */

void oad_updating_user_section_begin(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  dbg_printf(&DAT_00040888,PTR_DAT_00040864 + 0x58);
  iVar1 = DAT_00040884;
  *(undefined2 *)(DAT_00040884 + 6) = param_2;
  *(undefined2 *)(iVar1 + 4) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  return;
}

/* ==========================================================================
 * FUN_000406c0   @ 0x000406c0   (18 bytes)
 * called by : ImgHdr_2
 */

undefined4 FUN_000406c0(void)

{
  int iVar1;
  
  iVar1 = DAT_00040884;
  *(undefined1 *)(DAT_00040884 + 0x1d) = 0;
  *(undefined1 *)(iVar1 + 0x1c) = 2;
  *(undefined1 *)(DAT_00040890 + 2) = 0;
  return 0;
}

/* ==========================================================================
 * oadImgIdentifyReq   @ 0x000406d2   (150 bytes)
 * called by : ImgHdr
 * calls     : FUN_0003edee, FUN_0003ee1a, dbg_printf, rom_06EF4, rom_06F26
 * string    : "oadImgIdentifyReq"
 * string    : "noti  = 0x%x\r\n"
 * string    : "KE_MSG_ALLOC_DYN GATTC_SEND_EVT_CMD  == NULL \r\n"
 */

void oadImgIdentifyReq(short param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  short sVar4;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  dbg_printf(&DAT_00040888,PTR_DAT_00040864 + 0x8c);
  iVar1 = FUN_0003edee(0x49);
  dbg_printf(str_noti_0x_x,&local_18);
  local_18 = CONCAT13((char)((ushort)*(undefined2 *)(param_2 + 6) >> 8),*(undefined3 *)(param_2 + 4)
                     );
  local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)(param_2 + 0xe));
  uVar2 = FUN_0003ee1a(iVar1,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,0x12);
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 0x12;
    sVar4 = *(short *)(iVar1 + 8) + 2;
    *(short *)(puVar3 + 4) = sVar4;
    *(short *)(puVar3 + 2) = sVar4;
    *(undefined2 *)(puVar3 + 6) = 10;
    *(undefined2 *)(puVar3 + 8) = (undefined2)local_18;
    *(undefined2 *)(puVar3 + 10) = local_18._2_2_;
    *(undefined2 *)(puVar3 + 0xc) = *(undefined2 *)(param_2 + 8);
    *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(param_2 + 10);
    *(undefined2 *)(puVar3 + 0x10) = (undefined2)local_14;
    rom_06F26();
    return;
  }
  do {
    dbg_printf(str_KE_MSG_ALLOC_DYN_GATTC_SEND_EVT_CMD_NULL);
  } while( true );
}

/* ==========================================================================
 * FUN_00040768   @ 0x00040768   (76 bytes)
 * called by : ImgHdr, ImgHdr_2
 * calls     : FUN_0003edee, FUN_0003ee1a, rom_06EF4, rom_06F26
 */

void FUN_00040768(short param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_0003edee(0x49);
  uVar2 = FUN_0003ee1a(iVar1,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,10);
  *puVar3 = 0x12;
  *(short *)(puVar3 + 4) = *(short *)(iVar1 + 8) + 6;
  *(undefined2 *)(puVar3 + 6) = 2;
  *(undefined2 *)(puVar3 + 8) = param_2;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ImgHdr   @ 0x000407b4   (424 bytes)
 * calls     : FUN_000396da, FUN_00040768, appm_update_param, dbg_printf, oadImgIdentifyReq
 * string    : "oadImgIdentifyWrite"
 * string    : "rxHdr.ver = %x \r\n"
 * string    : "rxHdr.len = %x \r\n"
 * string    : "rxHdr.uid = %x \r\n"
 * string    : "rxHdr.rom_ver = %x \r\n"
 * string    : "BBBBwait for reset!!!\r\n"
 * string    : "app part upgrade\r\n"
 * string    : "ImgHdr.rom_ver = %x \r\n"
 * string    : "ImgHdr.uid = %x \r\n"
 * string    : "ImgHdr.ver = %x \r\n"
 * string    : "oadBlkTot = %x \r\n"
 * string    : "SSSSapp and stack upgrade\r\n"
 */

undefined4 ImgHdr(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_30 [4];
  short local_2c;
  undefined4 local_28;
  short local_22;
  undefined4 local_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  local_20 = param_1;
  uStack_1c = param_2;
  iStack_18 = param_3;
  dbg_printf(&DAT_00040888,PTR_DAT_00040864 + 0x78);
  pcVar5 = DAT_00040890;
  sVar1 = *(short *)(param_3 + 4);
  uVar2 = *(ushort *)(param_3 + 6);
  iVar4 = *(int *)(param_3 + 8);
  sVar3 = *(short *)(param_3 + 0xe);
  *(int *)(DAT_00040890 + 0xc) = iVar4;
  dbg_printf(str_rxHdr_ver_x,sVar1);
  dbg_printf(str_rxHdr_len_x,uVar2);
  dbg_printf(str_rxHdr_uid_x,iVar4);
  dbg_printf(str_rxHdr_rom_ver_x,sVar3);
  if (iVar4 == str_BBBBwait_for_reset._0_4_) {
    pcVar5[1] = '\x01';
    dbg_printf(str_app_part_upgrade);
    FUN_000396da(0,DAT_00040954,0x10,auStack_30);
    dbg_printf(str_ImgHdr_rom_ver_x,local_22);
    dbg_printf(str_ImgHdr_uid_x,local_28);
    dbg_printf(str_ImgHdr_ver_x,local_2c);
    *(ushort *)(pcVar5 + 6) = uVar2 >> 2;
    dbg_printf(str_oadBlkTot_x);
    if (((local_2c != sVar1) && (*(ushort *)(pcVar5 + 6) < 0x2a01)) &&
       ((*(ushort *)(pcVar5 + 6) != 0 && (sVar3 == local_22)))) {
LAB_000409b8:
      *pcVar5 = '\x01';
      goto LAB_00040a56;
    }
  }
  else if (iVar4 == str_SSSSapp_and_stack_upgrade._0_4_) {
    pcVar5[1] = '\x02';
    dbg_printf(str_SSSSapp_and_stack_upgrade + 4);
    FUN_000396da(0,PTR_DAT_00040c30,0x10,auStack_30);
    dbg_printf(PTR_str_ImgHdr_uid_x_00040c34,local_28);
    dbg_printf(str_ImgHdr_ver_x,local_2c);
    *(ushort *)(pcVar5 + 6) = uVar2 >> 2;
    dbg_printf(str_oadBlkTot_x);
    if (((sVar3 != local_22) && (*(ushort *)(pcVar5 + 6) < 0x3e01)) &&
       (*(ushort *)(pcVar5 + 6) != 0)) goto LAB_000409b8;
  }
  else {
    pcVar5[1] = '\0';
    FUN_000396da(0,DAT_00040c38,0x10,auStack_30);
    dbg_printf(PTR_str_ImgHdr_uid_x_00040c34 + -0x18,local_22);
    dbg_printf(PTR_str_ImgHdr_uid_x_00040c34,local_28);
    dbg_printf(str_ImgHdr_ver_x,local_2c);
  }
  if (*pcVar5 != '\x01') {
    oadImgIdentifyReq(local_20,auStack_30);
    return 0;
  }
LAB_00040a56:
  pcVar5[4] = '\0';
  pcVar5[5] = '\0';
  pcVar5[2] = '\x01';
  *pcVar5 = '\0';
  appm_update_param();
  FUN_00040768(local_20,0);
  return 0;
}

/* ==========================================================================
 * ImgHdr_2   @ 0x00040a7c   (364 bytes)
 * calls     : FUN_000396da, FUN_00040568, FUN_000406c0, FUN_00040768, dbg_printf, oad_updating_user_section_begin
 * string    : "oadImgBlockWrite: UNKNOWN UID\r\n"
 * string    : "uid = %x\r\n"
 * string    : "blkNum = %x ,oadBlkNum %x,oadBlkTot %x,ver %x \r\n"
 * string    : "ImgHdr.ver = %x, ver = %x\r\n"
 * string    : "last block \r\n"
 * string    : "update down!\r\n"
 */

undefined4 ImgHdr_2(undefined4 param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  undefined1 auStack_3c [4];
  short local_38;
  ushort local_2e;
  uint local_28;
  undefined4 local_1c;
  short *psStack_18;
  
  iVar2 = DAT_00040c3c;
  sVar1 = *param_2;
  local_1c = param_1;
  psStack_18 = param_2;
  if (sVar1 == 0) {
    if (*(char *)(DAT_00040c3c + 1) == '\x01') {
      FUN_000396da(0,DAT_00040c38,0x10,auStack_3c);
      sVar4 = param_2[3];
      local_28 = (uint)(ushort)param_2[8];
      uVar3 = *(undefined4 *)(param_2 + 5);
      local_38 = sVar4 + 1;
      *(undefined2 *)(iVar2 + 8) = 0;
      dbg_printf(str_uid_x,uVar3);
      dbg_printf(str_blkNum_x_oadBlkNum_x_oadBlkTot_x_ver_x,0,*(undefined2 *)(iVar2 + 4),
                 *(undefined2 *)(iVar2 + 6));
      dbg_printf(str_ImgHdr_ver_x_ver_x,local_38,sVar4);
      if ((*(short *)(iVar2 + 4) == 0) && (local_2e == local_28)) {
LAB_00040b84:
        oad_updating_user_section_begin(sVar4,(uint)*(ushort *)(iVar2 + 6) * 4 + -0x10);
        FUN_00040568(param_2);
        goto LAB_00040b96;
      }
    }
    else if (*(char *)(DAT_00040c3c + 1) == '\x02') {
      FUN_000396da(0,PTR_DAT_00040c30,0x10,auStack_3c);
      sVar4 = param_2[3];
      local_28 = (uint)(ushort)param_2[8];
      uVar3 = *(undefined4 *)(param_2 + 5);
      local_38 = sVar4 + 1;
      *(undefined2 *)(iVar2 + 8) = 0;
      dbg_printf(str_uid_x,uVar3);
      dbg_printf(str_blkNum_x_oadBlkNum_x_oadBlkTot_x_ver_x,0,*(undefined2 *)(iVar2 + 4),
                 *(undefined2 *)(iVar2 + 6));
      dbg_printf(str_ImgHdr_ver_x_ver_x,local_38,sVar4);
      if ((*(short *)(iVar2 + 4) == 0) && (local_2e != local_28)) goto LAB_00040b84;
    }
    else {
      dbg_printf(str_oadImgBlockWrite_UNKNOWN_UID);
    }
    uVar3 = 3;
  }
  else {
LAB_00040b96:
    if (*(short *)(iVar2 + 4) == sVar1) {
      if (*(short *)(iVar2 + 4) != 0) {
        *(short *)(iVar2 + 8) = *(short *)(iVar2 + 8) + 1;
        FUN_00040568(param_2);
        if ((uint)*(ushort *)(iVar2 + 8) == *(ushort *)(iVar2 + 6) - 1) {
          dbg_printf(str_last_block);
          FUN_00040768(local_1c,*(undefined2 *)(iVar2 + 4));
        }
      }
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + 1;
    }
    else {
      FUN_00040768(local_1c);
    }
    if (*(short *)(iVar2 + 4) == *(short *)(iVar2 + 6)) {
      dbg_printf(str_update_down);
      FUN_000406c0();
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* ==========================================================================
 * FUN_00041f62   @ 0x00041f62   (78 bytes)
 * calls     : FUN_0003ee1a, FUN_0003ee2a, prf_register_atthdl2gatt, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_00041f62(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar1 = FUN_0003ee1a();
  uVar2 = FUN_0003ee2a(param_1,param_2);
  puVar3 = (undefined1 *)rom_06EF4(DAT_00041fb8,uVar2,uVar1,0x8a,param_4);
  *puVar3 = (char)param_3;
  if (param_3 == 0) {
    iVar4 = param_2 * 4 + param_1;
    rom_24F9C(puVar3 + 2,*(int *)(iVar4 + 4) + 4,0x88);
    prf_register_atthdl2gatt(param_1,param_2,*(int *)(iVar4 + 4) + 4);
  }
  rom_06F26(puVar3);
  return;
}


/*############################################################################
 * FLASH AND NVM STORAGE  (56 functions)
 *
 *   0x00029988  FUN_00029988  (68 B)
 *   0x00029A04  FUN_00029a04  (62 B)
 *   0x0002CBC8  FUN_0002cbc8  (18 B)
 *   0x0002FEF0  FUN_0002fef0  (40 B)
 *   0x0003023C  FLASH_wr_Global  (248 B)
 *   0x00030334  FLASH_RD_Global  (314 B)
 *   0x0003049C  read  (112 B)
 *   0x0003050C  FUN_0003050c  (32 B)
 *   0x0003052C  FLASH_RD_Profile  (344 B)
 *   0x00030740  FLASH_WR_Profile  (298 B)
 *   0x0003086A  flash_erase  (330 B)
 *   0x000309B4  FLASH_RD_Macro  (68 B)
 *   0x000309F8  Default_Profile  (462 B)
 *   0x00030D32  _saveC_GM_ProfileMax  (400 B)
 *   0x00030F4A  nvds_Polling_read  (58 B)
 *   0x00030F96  nvds_Polling_write  (48 B)
 *   0x00030FC6  profile_mem_init  (42 B)
 *   0x00031808  FUN_00031808  (102 B)
 *   0x0003262C  FUN_0003262c  (44 B)
 *   0x00032658  FUN_00032658  (46 B)
 *   0x00032766  set_USB_led_flash  (100 B)
 *   0x000327CA  set_pairing_led_flash  (86 B)
 *   0x00032820  set_bonded_led_flash  (102 B)
 *   0x00032E82  FUN_00032e82  (2 B)
 *   0x00032F16  FUN_00032f16  (12 B)
 *   0x000333F0  FUN_000333f0  (116 B)
 *   0x00036CBE  FUN_00036cbe  (20 B)
 *   0x00036CEE  FUN_00036cee  (32 B)
 *   0x00036F88  FUN_00036f88  (26 B)
 *   0x00036FEC  FUN_00036fec  (12 B)
 *   0x00036FF8  FUN_00036ff8  (12 B)
 *   0x00037004  FUN_00037004  (116 B)
 *   0x0003726A  _USB_macro2  (560 B)
 *   0x00037B02  FUN_00037b02  (8 B)
 *   0x00038068  FUN_00038068  (10 B)
 *   0x00038072  FUN_00038072  (52 B)
 *   0x00038144  FUN_00038144  (40 B)
 *   0x000391C0  FUN_000391c0  (34 B)
 *   0x000391E2  FUN_000391e2  (26 B)
 *   0x000391FC  FUN_000391fc  (188 B)
 *   0x000392B8  FUN_000392b8  (118 B)
 *   0x0003932E  FUN_0003932e  (118 B)
 *   0x000393A4  flash_mid  (24 B)
 *   0x0003943C  FUN_0003943c  (78 B)
 *   0x00039526  FUN_00039526  (268 B)
 *   0x000396DA  FUN_000396da  (46 B)
 *   0x00039708  FUN_00039708  (102 B)
 *   0x0003976E  FUN_0003976e  (90 B)
 *   0x000397C8  flash_write_some_data  (146 B)
 *   0x0003985A  flash_read  (128 B)
 *   0x000398DA  r_temp1  (194 B)
 *   0x0003C2C6  FUN_0003c2c6  (30 B)
 *   0x0003C8B6  FUN_0003c8b6  (38 B)
 *   0x0003CF7C  FUN_0003cf7c  (60 B)
 *   0x0003E4D2  FUN_0003e4d2  (24 B)
 *   0x0003E4EA  FUN_0003e4ea  (24 B)
 ############################################################################*/

/* ==========================================================================
 * FUN_00029988   @ 0x00029988   (68 bytes)
 * called by : app_ble_address_update, app_ble_to_ble_mode
 * calls     : FUN_0003e552, dbg_printf, dbg_printf_2, rom_24F9C
 * string    : " An error has occurred during access to the NVDS_TAG_BLE_ADDRESS1 \r\n"
 * string    : "ble addr:"
 * string    : " An error has occurred during access to the NVDS_TAG_BLE_ADDRESS0 \r\n"
 */

void FUN_00029988(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8 [2];
  
  local_8[0] = CONCAT31((int3)((uint)param_4 >> 8),7);
  uStack_10 = param_2;
  uStack_c = param_3;
  if (param_1 == 1) {
    iVar2 = FUN_0003e552(0xa5,local_8);
    uVar1 = DAT_00029d50;
  }
  else {
    iVar2 = FUN_0003e552(0xa6,local_8);
    uVar1 = DAT_00029d40;
  }
  if (iVar2 != 0) {
    dbg_printf(uVar1);
  }
  rom_24F9C(DAT_00029ce0,(int)&uStack_10 + 1,6);
  dbg_printf_2(str_ble_addr,DAT_00029ce0,6);
  return;
}

/* ==========================================================================
 * FUN_00029a04   @ 0x00029a04   (62 bytes)
 * called by : app_ble_to_ble_mode
 * calls     : FUN_0002cbc8, FUN_0003e552, KEY_piaring_cnt, dbg_printf
 * string    : "not NVDS_TAG_PEER%d_IRK\r\n"
 * string    : "====================================================\r\n"
 */

void FUN_00029a04(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  undefined4 local_10;
  
  local_10 = in_r3;
  KEY_piaring_cnt();
  iVar1 = DAT_00029d70;
  local_10 = CONCAT31(local_10._1_3_,0x17);
  iVar2 = FUN_0003e552(*(char *)(DAT_00029d70 + 6) + 'C',&local_10,DAT_00029d74);
  if (iVar2 != 0) {
    dbg_printf(str_not_NVDS_TAG_PEER_d_IRK,*(undefined1 *)(iVar1 + 6));
  }
  FUN_0002cbc8(iVar2 == 0);
  dbg_printf(str_s_2);
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * FUN_0002cbc8   @ 0x0002cbc8   (18 bytes)
 * called by : FUN_00029a04, app_sec_init
 */

void FUN_0002cbc8(undefined1 param_1)

{
  if (*DAT_0002cfc4 != '\x01') {
    DAT_0002cfc8[1] = param_1;
    return;
  }
  *DAT_0002cfc8 = param_1;
  return;
}

/* ==========================================================================
 * FUN_0002fef0   @ 0x0002fef0   (40 bytes)
 * calls     : FUN_000369b8, FUN_00036cbe, FUN_00036cee, set_pairing_led_flash
 */

void FUN_0002fef0(void)

{
  FUN_00036cee();
  FUN_00036cbe();
  FUN_000369b8();
  *PTR_DAT_000301f0 = *PTR_DAT_000301f0 + '\x01';
  *PTR_DAT_00030144 = 1;
  *PTR_DAT_000301f4 = 0;
  set_pairing_led_flash();
  return;
}

/* ==========================================================================
 * FLASH_wr_Global   @ 0x0003023c   (248 bytes)
 * called by : FUN_00028c66, _saveC_GM_ProfileMax
 * calls     : FUN_000392b8, FUN_0003932e, FUN_000396da, FUN_00039708, FUN_0003976e, dbg_printf, ... (+3 more)
 * string    : "FLASH_wr_Global:"
 * string    : "address&0x3ff = %x\r\n"
 */

void FLASH_wr_Global(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 auStack_414 [1024];
  
  rom_24FEC(DAT_00030640,0xff);
  rom_24FEC(auStack_414,0x400);
  FUN_000392b8();
  FUN_000396da(0,0x7c000,0x400,auStack_414,0);
  FUN_0003976e(0,0x7c000,0x1000);
  FUN_0003932e();
  pbVar2 = DAT_00030644;
  if (2 < *DAT_00030644) {
    *DAT_00030644 = 0;
  }
  pbVar1 = DAT_00030640;
  bVar3 = *pbVar2;
  *DAT_00030640 = bVar3;
  pbVar1[1] = ~bVar3;
  bVar3 = pbVar2[2];
  pbVar1[2] = bVar3;
  pbVar1[3] = ~bVar3;
  bVar3 = pbVar2[4];
  pbVar1[4] = bVar3;
  pbVar1[5] = ~bVar3;
  if (2 < pbVar2[6]) {
    pbVar2[6] = 0;
  }
  bVar3 = pbVar2[6];
  pbVar1[6] = bVar3;
  pbVar1[7] = ~bVar3;
  if (0xe < pbVar2[8]) {
    pbVar2[8] = 0;
  }
  bVar3 = pbVar2[8];
  pbVar1[8] = bVar3;
  pbVar1[9] = ~bVar3;
  bVar3 = pbVar2[10];
  if (0xf < bVar3) {
    bVar3 = 8;
    pbVar2[10] = 8;
  }
  pbVar1[10] = bVar3;
  pbVar1[0xb] = ~bVar3;
  if (4 < pbVar2[0xc]) {
    pbVar2[0xc] = 0;
  }
  bVar3 = pbVar2[0xc];
  pbVar1[0xc] = bVar3;
  pbVar1[0xd] = ~bVar3;
  bVar3 = pbVar2[0xe];
  if (4 < bVar3) {
    bVar3 = 4;
    pbVar2[0xe] = 4;
  }
  pbVar1[0xe] = bVar3;
  pbVar1[0xf] = ~bVar3;
  dbg_printf_2(str_FLASH_wr_Global,DAT_00030640,0x10);
  rom_24F9C(auStack_414,DAT_00030640,0x10);
  dbg_printf(str_address_0x3ff_x,0);
  *DAT_00030674 = 0x7c000;
  FUN_00039708(0,0x7c000,0x400,auStack_414,0);
  return;
}

/* ==========================================================================
 * FLASH_RD_Global   @ 0x00030334   (314 bytes)
 * called by : profile_mem_init
 * calls     : FUN_000396da, dbg_printf_2, rom_24FEC
 * string    : "FLASH_RD_Global:"
 * string    : "Global_DATA:"
 */

void FLASH_RD_Global(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined2 *puVar6;
  
  rom_24FEC(DAT_00030640,0xff,param_3,param_4,param_4);
  FUN_000396da(0,0x7c000,0x10,DAT_00030640,0);
  dbg_printf_2(str_FLASH_RD_Global,DAT_00030640,0x10);
  puVar6 = DAT_0003068c;
  pbVar4 = DAT_00030644;
  pbVar2 = DAT_00030640;
  bVar1 = DAT_00030640[1];
  if (*DAT_00030640 == (byte)~bVar1) {
    *DAT_00030644 = *DAT_00030640;
    pbVar4[1] = bVar1;
  }
  else {
    *(undefined2 *)DAT_00030644 = *DAT_0003068c;
  }
  if (2 < *pbVar4) {
    *pbVar4 = 0;
    pbVar4[1] = 0xff;
  }
  pbVar5 = DAT_00030644;
  pbVar3 = DAT_00030640;
  DAT_00030644[2] = DAT_00030640[2];
  pbVar5[3] = pbVar3[3];
  pbVar4[4] = pbVar2[4];
  pbVar4[5] = pbVar2[5];
  pbVar3 = DAT_00030644;
  bVar1 = pbVar2[7];
  if (pbVar2[6] == (byte)~bVar1) {
    DAT_00030644[6] = pbVar2[6];
    pbVar3[7] = bVar1;
  }
  else {
    *(undefined2 *)(DAT_00030644 + 6) = DAT_0003068c[3];
  }
  if (2 < pbVar4[6]) {
    pbVar4[6] = 0;
    pbVar4[7] = 0xff;
  }
  bVar1 = pbVar2[9];
  if (pbVar2[8] == (byte)~bVar1) {
    pbVar4[8] = pbVar2[8];
    pbVar4[9] = bVar1;
  }
  else {
    *(undefined2 *)(pbVar4 + 8) = puVar6[4];
  }
  if (0xe < pbVar4[8]) {
    pbVar4[8] = 0;
    pbVar4[9] = 0xff;
  }
  pbVar3 = DAT_00030644;
  bVar1 = pbVar2[0xb];
  if (pbVar2[10] == (byte)~bVar1) {
    DAT_00030644[10] = pbVar2[10];
    pbVar3[0xb] = bVar1;
  }
  else {
    *(undefined2 *)(DAT_00030644 + 10) = DAT_0003068c[5];
  }
  if (0xf < pbVar4[10]) {
    pbVar4[10] = 8;
    pbVar4[0xb] = 0xf7;
  }
  bVar1 = pbVar2[0xd];
  if (pbVar2[0xc] == (byte)~bVar1) {
    pbVar4[0xc] = pbVar2[0xc];
    pbVar4[0xd] = bVar1;
  }
  else {
    *(undefined2 *)(pbVar4 + 0xc) = puVar6[6];
  }
  if (4 < pbVar4[0xc]) {
    pbVar4[0xc] = 0;
    pbVar4[0xd] = 0xff;
  }
  *DAT_00030690 = pbVar4[0xc];
  pbVar3 = DAT_00030644;
  bVar1 = pbVar2[0xf];
  if (pbVar2[0xe] == (byte)~bVar1) {
    DAT_00030644[0xe] = pbVar2[0xe];
    pbVar3[0xf] = bVar1;
  }
  else {
    *(undefined2 *)(DAT_00030644 + 0xe) = DAT_0003068c[7];
  }
  if (4 < pbVar4[0xe]) {
    pbVar4[0xe] = 4;
    pbVar4[0xf] = 0xfb;
  }
  dbg_printf_2(str_Global_DATA,DAT_00030644,0x10);
  return;
}

/* ==========================================================================
 * read   @ 0x0003049c   (112 bytes)
 * called by : profile_mem_init
 * calls     : FUN_000396da, dbg_printf_2, rom_24F9C
 * string    : "read id_code:"
 */

void read(void)

{
  int iVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  
  FUN_000396da(0,DAT_000306a4,6,DAT_00030640,0);
  iVar4 = DAT_00030644 + 0x10;
  if (((*DAT_00030640 != (byte)~DAT_00030640[3]) || (DAT_00030640[1] != (byte)~DAT_00030640[4])) ||
     (pbVar3 = DAT_00030640, DAT_00030640[2] != (byte)~DAT_00030640[5])) {
    pbVar3 = (byte *)(DAT_0003068c + 0x10);
  }
  rom_24F9C(iVar4,pbVar3,6);
  puVar2 = DAT_000306b8;
  iVar1 = DAT_00030644;
  *DAT_000306b8 = (uint)*(byte *)(DAT_00030644 + 0x10);
  puVar2[1] = (uint)*(byte *)(iVar1 + 0x11);
  puVar2[2] = (uint)*(byte *)(iVar1 + 0x12);
  dbg_printf_2(str_read_id_code,iVar4,3);
  return;
}

/* ==========================================================================
 * FUN_0003050c   @ 0x0003050c   (32 bytes)
 * called by : Default_Profile, FLASH_RD_Profile, FLASH_WR_Profile
 */

short FUN_0003050c(byte *param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = 0;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    sVar1 = (ushort)*param_1 + sVar1;
    param_1 = param_1 + 1;
  }
  return sVar1;
}

/* ==========================================================================
 * FLASH_RD_Profile   @ 0x0003052c   (344 bytes)
 * called by : FLASH_WR_Profile, FUN_000333f0, Set_Report_Data, _saveC_GM_ProfileMax, profile_mem_init
 * calls     : FUN_0003050c, FUN_000396da, dbg_printf, dbg_printf_2, rom_24F9C
 * string    : "FLASH_RD_Profile:"
 * string    : "Polling = %x,Flashmem_buff[_offset_Polling] = %x,Flashmem_buff[_offset_Polling +1] = %x\r\n"
 * string    : "SensorSet:"
 * string    : "LightSet:"
 * string    : "ButtonSet:"
 */

void FLASH_RD_Profile(uint param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  
  if (4 < param_1) {
    param_1 = 0;
  }
  FUN_000396da(0,*(undefined4 *)(DAT_0003068c + 0x8c + param_1 * 4),0x75,DAT_00030640,0);
  dbg_printf_2(str_FLASH_RD_Profile,DAT_00030640,0x75);
  iVar4 = DAT_00030644;
  pbVar8 = DAT_00030640;
  bVar1 = DAT_00030640[1];
  if (*DAT_00030640 == (byte)~bVar1) {
    *(byte *)(DAT_00030644 + 0x16) = *DAT_00030640;
    *(byte *)(iVar4 + 0x17) = bVar1;
  }
  else {
    *(undefined2 *)(DAT_00030644 + 0x16) = *(undefined2 *)(DAT_0003068c + 0x16);
  }
  iVar4 = DAT_00030644;
  cVar2 = *(char *)(DAT_00030644 + 0x16);
  if ((((cVar2 != '\x01') && (cVar2 != '\x02')) && (cVar2 != '\x04')) && (cVar2 != '\b')) {
    *(undefined1 *)(DAT_00030644 + 0x16) = 1;
    *(undefined1 *)(iVar4 + 0x17) = 0xfe;
  }
  dbg_printf(DAT_000306e0,*(undefined1 *)(iVar4 + 0x16));
  iVar4 = DAT_00030644;
  pbVar3 = DAT_00030640;
  *(ushort *)(DAT_00030644 + 0x48) = (ushort)DAT_00030640[0x31] * 0x100 + (ushort)DAT_00030640[0x32]
  ;
  uVar7 = FUN_0003050c(pbVar8 + 2,0x2f);
  iVar9 = iVar4 + 0x18;
  if (uVar7 == *(ushort *)(iVar4 + 0x48)) {
    rom_24F9C(iVar9,pbVar8 + 2,0x2f);
  }
  else {
    rom_24F9C(iVar9,DAT_0003068c + 0x18,0x2f);
    uVar6 = FUN_0003050c(iVar9,0x2f);
    *(undefined2 *)(iVar4 + 0x48) = uVar6;
  }
  dbg_printf_2(str_SensorSet,iVar9,0x2f);
  *(ushort *)(iVar4 + 0x52) = (ushort)pbVar3[0x3b] * 0x100 + (ushort)pbVar3[0x3c];
  pbVar8 = DAT_00030640 + 0x33;
  uVar7 = FUN_0003050c(pbVar8,8);
  iVar9 = DAT_00030644 + 0x4a;
  if (uVar7 == *(ushort *)(iVar4 + 0x52)) {
    rom_24F9C(iVar9,pbVar8,8);
  }
  else {
    rom_24F9C(iVar9,DAT_0003068c + 0x49,8);
    uVar6 = FUN_0003050c(iVar9,8);
    *(undefined2 *)(iVar4 + 0x52) = uVar6;
  }
  dbg_printf_2(str_LightSet,iVar9,8);
  iVar4 = DAT_00030af8;
  *(ushort *)(DAT_00030af8 + 10) = (ushort)DAT_00030640[0x73] * 0x100 + (ushort)DAT_00030640[0x74];
  uVar5 = DAT_00030afc;
  uVar7 = FUN_0003050c(DAT_00030afc,0x36);
  iVar9 = iVar4 + -0x2c;
  if (uVar7 == *(ushort *)(iVar4 + 10)) {
    rom_24F9C(iVar9,uVar5,0x36);
  }
  else {
    rom_24F9C(iVar9,DAT_00030b00,0x36);
    uVar6 = FUN_0003050c(iVar9,0x36);
    *(undefined2 *)(iVar4 + 10) = uVar6;
  }
  dbg_printf_2(str_ButtonSet,iVar9,0x36);
  return;
}

/* ==========================================================================
 * FLASH_WR_Profile   @ 0x00030740   (298 bytes)
 * called by : FUN_00028c66
 * calls     : FLASH_RD_Profile, FUN_0003050c, FUN_000392b8, FUN_0003932e, FUN_000396da, FUN_00039708, ... (+6 more)
 * string    : "FLASH_WR_Profile:"
 * string    : "address&0x3ff = %x\r\n"
 */

void FLASH_WR_Profile(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  undefined1 auStack_414 [1024];
  
  uVar7 = *(uint *)(DAT_00030b00 + 0x39 + param_1 * 4);
  rom_24FEC(DAT_00030afc + -0x3d,0xff);
  rom_24FEC(auStack_414,0x400);
  FUN_000392b8();
  FUN_000396da(0,uVar7 & 0xfffffc00,0x400,auStack_414,0);
  FUN_0003976e(0,uVar7,0x1000);
  FUN_0003932e();
  iVar3 = DAT_00030afc;
  iVar2 = DAT_00030af8;
  pbVar1 = (byte *)(DAT_00030af8 + -0x6a);
  pbVar8 = (byte *)(DAT_00030afc + -0x3d);
  bVar4 = ~*pbVar1;
  *(byte *)(DAT_00030af8 + -0x69) = bVar4;
  *pbVar8 = *pbVar1;
  *(byte *)(iVar3 + -0x3c) = bVar4;
  rom_24F9C(iVar3 + -0x3b,iVar2 + -0x68,0x2f);
  uVar5 = FUN_0003050c(iVar3 + -0x3b,0x2f);
  *(undefined2 *)(iVar2 + -0x38) = uVar5;
  *(char *)(iVar3 + -0xc) = (char)((ushort)uVar5 >> 8);
  *(char *)(iVar3 + -0xb) = (char)uVar5;
  iVar6 = iVar3 + -10;
  rom_24F9C(iVar6,iVar2 + -0x36,8);
  uVar5 = FUN_0003050c(iVar6,8);
  *(undefined2 *)(iVar2 + -0x2e) = uVar5;
  *(char *)(iVar3 + -2) = (char)((ushort)uVar5 >> 8);
  *(char *)(iVar3 + -1) = (char)uVar5;
  iVar3 = DAT_00030afc;
  rom_24F9C(DAT_00030afc,iVar2 + -0x2c,0x36);
  uVar5 = FUN_0003050c(iVar3,0x36);
  *(undefined2 *)(DAT_00030af8 + 10) = uVar5;
  iVar3 = DAT_00030afc;
  *(char *)(DAT_00030afc + 0x36) = (char)((ushort)uVar5 >> 8);
  *(char *)(iVar3 + 0x37) = (char)uVar5;
  dbg_printf_2(str_FLASH_WR_Profile,iVar3 + -0x3d,0x75);
  if (4 < param_1) {
    param_1 = 0;
  }
  rom_24F9C(auStack_414 + (*(ushort *)(DAT_00030b00 + 0x39 + param_1 * 4) & 0x3ff),
            DAT_00030afc + -0x3d,0x75);
  dbg_printf(DAT_00030b24,*(ushort *)(DAT_00030b00 + 0x39 + param_1 * 4) & 0x3ff);
  *DAT_00030b28 = 0x7c000;
  FUN_00039708(0,0x7c000,0x400,auStack_414,0);
  if (*(byte *)(iVar2 + -0x74) != param_1) {
    *DAT_00030b2c = *(byte *)(iVar2 + -0x74);
    FLASH_RD_Profile();
  }
  FUN_0003ce00();
  return;
}

/* ==========================================================================
 * flash_erase   @ 0x0003086a   (330 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_000392b8, FUN_0003932e, FUN_000396da, FUN_00039708, FUN_0003976e, dbg_printf, ... (+2 more)
 * string    : "FLASH_WR_Macro  macro_id =%x,page =%x,offset =%x\r\n"
 * string    : "flash_erase: FLASHADDR_BACKUP\r\n"
 * string    : "backup:"
 * string    : "flash_erase: FLASHADDR_MACRO\r\n"
 * string    : "restore:"
 * string    : "Flashmem_buff:"
 * string    : "flash_wp_ALL: \r\n"
 */

void flash_erase(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_418 [1028];
  
  uVar1 = 0;
  if (0x1f < param_1) {
    param_1 = 0;
  }
  uVar2 = param_1 >> 3;
  dbg_printf(str_FLASH_WR_Macro_macro_id_x_page_x_offset_x,param_1,uVar2,param_1 & 7);
  FUN_000392b8();
  FUN_0003976e(0,0x52000,0x1000);
  dbg_printf(str_flash_erase_FLASHADDR_BACKUP);
  do {
    FUN_000396da(0,uVar1 * 0x400 + 0x7d000,0x400,auStack_418,0);
    FUN_00039708(0,uVar1 * 0x400 + 0x52000,0x400,auStack_418,0);
    dbg_printf_2(str_backup,auStack_418,0x10);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 4);
  FUN_0003976e(0,0x7d000,0x1000);
  dbg_printf(str_flash_erase_FLASHADDR_MACRO);
  uVar1 = 0;
  do {
    if (uVar1 != uVar2) {
      FUN_000396da(0,uVar1 * 0x400 + 0x52000,0x400,auStack_418,0);
      FUN_00039708(0,uVar1 * 0x400 + 0x7d000,0x400,auStack_418,0);
    }
    dbg_printf_2(str_restore,auStack_418,0x10);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 4);
  FUN_000396da(0,uVar2 * 0x400 + 0x52000,0x400,auStack_418,0);
  rom_24F9C(auStack_418 + (param_1 & 7) * 0x80,DAT_00030afc + -0x3d,0x80);
  dbg_printf_2(str_Flashmem_buff,DAT_00030afc + -0x3d,0x80);
  FUN_00039708(0,uVar2 * 0x400 + 0x7d000,0x400,auStack_418,0);
  FUN_0003932e();
  dbg_printf(str_flash_wp_ALL);
  return;
}

/* ==========================================================================
 * FLASH_RD_Macro   @ 0x000309b4   (68 bytes)
 * called by : _saveC_GM_ProfileMax
 * calls     : FUN_000396da, dbg_printf, dbg_printf_2, rom_24F9C
 * string    : "FLASH_RD_Macro  macro_id = %x,Flash_Macro_Addr = %x\r\n"
 * string    : "read macro:"
 */

void FLASH_RD_Macro(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (0x1f < param_1) {
    param_1 = 0;
  }
  iVar1 = param_1 * 0x80 + 0x7d000;
  dbg_printf(str_FLASH_RD_Macro_macro_id_x_Flash_Macro_Addr_x,param_1,iVar1,param_4,param_4);
  FUN_000396da(0,iVar1,0x80,DAT_00030afc + -0x3d,0);
  rom_24F9C(DAT_00030c14,DAT_00030afc + -0x3d,0x80);
  dbg_printf_2(str_read_macro,DAT_00030afc + -0x3d,0x80);
  return;
}

/* ==========================================================================
 * Default_Profile   @ 0x000309f8   (462 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_0003050c, FUN_00031406, FUN_000392b8, FUN_0003932e, FUN_000396da, FUN_00039708, ... (+9 more)
 * string    : "address&0x3ff = %x\r\n"
 * string    : "Default_Profile:"
 * string    : "Polling0:"
 * string    : "Sensor:"
 * string    : "Light:"
 * string    : "ButtonSet:"
 */

void Default_Profile(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 auStack_414 [128];
  undefined1 auStack_394 [128];
  undefined1 auStack_314 [128];
  undefined1 auStack_294 [128];
  undefined1 auStack_214 [128];
  undefined1 auStack_194 [384];
  
  rom_24FEC(DAT_00030afc + -0x3d,0xff);
  rom_24FEC(auStack_414,0x400);
  FUN_000392b8();
  FUN_000396da(0,0x7c000,0x400,auStack_414,0);
  FUN_0003976e(0,0x7c000,0x1000);
  FUN_0003932e();
  rom_24F9C(DAT_00030af8 + -0x80,DAT_00030b00 + -0x53,0x10);
  rom_24F9C(DAT_00030afc + -0x3d,DAT_00030b00 + -0x53,0x10);
  rom_24F9C(auStack_414,DAT_00030afc + -0x3d,0x10);
  dbg_printf(DAT_00030b24,0);
  rom_24F9C(DAT_00030afc + -0x3d,DAT_00030b00 + -0x3d,0x75);
  dbg_printf_2(str_Default_Profile,DAT_00030afc + -0x3d,0x75);
  iVar2 = DAT_00030afc;
  iVar1 = DAT_00030af8;
  puVar5 = (undefined1 *)(DAT_00030afc + -0x3d);
  *(undefined1 *)(DAT_00030af8 + -0x6a) = *puVar5;
  *(undefined1 *)(iVar1 + -0x69) = *(undefined1 *)(iVar2 + -0x3c);
  dbg_printf_2(str_Polling0,puVar5,2);
  rom_24F9C(DAT_00030af8 + -0x68,iVar2 + -0x3b,0x2f);
  uVar3 = FUN_0003050c(iVar2 + -0x3b,0x2f);
  iVar1 = DAT_00030af8;
  *(undefined2 *)(DAT_00030af8 + -0x38) = uVar3;
  *(char *)(iVar2 + -0xc) = (char)((ushort)uVar3 >> 8);
  *(char *)(iVar2 + -0xb) = (char)uVar3;
  dbg_printf_2(str_Sensor,iVar2 + -0x3b,0x31);
  iVar4 = iVar2 + -10;
  rom_24F9C(iVar1 + -0x36,iVar4,8);
  uVar3 = FUN_0003050c(iVar4,8);
  *(undefined2 *)(iVar1 + -0x2e) = uVar3;
  *(char *)(iVar2 + -2) = (char)((ushort)uVar3 >> 8);
  *(char *)(iVar2 + -1) = (char)uVar3;
  dbg_printf_2(str_Light,iVar4,10);
  rom_24F9C(iVar1 + -0x2c,iVar2,0x36);
  uVar3 = FUN_0003050c(iVar2,0x36);
  *(undefined2 *)(iVar1 + 10) = uVar3;
  *(char *)(iVar2 + 0x36) = (char)((ushort)uVar3 >> 8);
  *(char *)(iVar2 + 0x37) = (char)uVar3;
  dbg_printf_2(DAT_00030ff8,iVar2,0x38);
  rom_24F9C(auStack_394,iVar2 + -0x3d,0x75);
  dbg_printf(DAT_00030ffc,0x80);
  rom_24F9C(auStack_314,iVar2 + -0x3d,0x75);
  dbg_printf(DAT_00030ffc,0x80);
  rom_24F9C(auStack_294,iVar2 + -0x3d,0x75);
  dbg_printf(DAT_00030ffc,0x80);
  rom_24F9C(auStack_214,iVar2 + -0x3d,0x75);
  dbg_printf(DAT_00030ffc,0x80);
  rom_24F9C(auStack_194,iVar2 + -0x3d,0x75);
  dbg_printf(DAT_00030ffc,0x80);
  *DAT_00031000 = 0x7c000;
  FUN_00039708(0,0x7c000,0x400,auStack_414,0);
  FUN_0003c2c6();
  set_dpi();
  FUN_00031406();
  *DAT_00031004 = 0;
  OLED_Clear();
  FUN_0003cf7c();
  return;
}

/* ==========================================================================
 * _saveC_GM_ProfileMax   @ 0x00030d32   (400 bytes)
 * called by : system_mode
 * calls     : FLASH_RD_Macro, FLASH_RD_Profile, FLASH_wr_Global, FUN_0003c2c6, dbg_printf, dbg_printf_2, ... (+2 more)
 * string    : "_read9_GM_macro  report_id =%x,macro_index=%x\r\n"
 * string    : "_saveC_GM_ProfileMax:"
 * string    : "Current_Profile=%x, %x, MaxProfile=%x, %x\r\n"
 * string    : "RD Profile:"
 * string    : "WR Profile:"
 */

void _saveC_GM_ProfileMax(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  char cVar9;
  int extraout_r1;
  int iVar10;
  undefined4 in_r3;
  byte bVar11;
  
  puVar7 = DAT_00031018;
  pbVar6 = DAT_00031010;
  bVar11 = 0;
  bVar1 = *DAT_00031010;
  if (bVar1 == 0) {
LAB_00030d66:
    pbVar8 = DAT_00031020;
    if (*DAT_00031020 != 0) {
      *pbVar6 = *DAT_00031020;
      *pbVar8 = bVar11;
    }
    return;
  }
  *(undefined1 *)(DAT_00031014 + 1) = 0;
  pcVar5 = DAT_0003100c;
  cVar2 = *DAT_0003100c;
  if (bVar1 == 10) {
    if (((*DAT_0003101c == '\x01') || (*DAT_0003101c == '\x02')) && (*DAT_00031064 == '\0')) {
      *DAT_00031054 = '\x01';
    }
    else {
      FLASH_wr_Global();
    }
    goto LAB_00030e9e;
  }
  if (bVar1 < 0xb) {
    rom_25078();
    *(byte **)(extraout_r1 * 2) = pbVar6;
    bVar11 = pbVar6[0x19];
    goto LAB_00030d66;
  }
  cVar3 = *(char *)(DAT_00031008 + 0xc);
  cVar9 = cVar3;
  if (bVar1 != 0x25) {
    if (bVar1 < 0x26) {
      if (bVar1 == 0xc) {
        iVar10 = DAT_00031008 + 0xc;
        dbg_printf_2(str_saveC_GM_ProfileMax,iVar10,4);
        iVar4 = DAT_00031008;
        dbg_printf(str_Current_Profile_x_x_MaxProfile_x_x,*(undefined1 *)(DAT_00031008 + 0xc),
                   *(undefined1 *)(DAT_00031008 + 0xd),*(undefined1 *)(DAT_00031008 + 0xe),
                   *(undefined1 *)(DAT_00031008 + 0xf));
        if ((*(byte *)(iVar4 + 0xd) != (byte)~*(byte *)(iVar4 + 0xc)) ||
           (*(byte *)(iVar4 + 0xf) != (byte)~*(byte *)(iVar4 + 0xe))) {
          if (*(byte *)(iVar4 + 0xd) == (byte)~*(byte *)(iVar4 + 0xc)) {
            *pbVar6 = 0;
          }
          else {
            *pbVar6 = 0x23;
            dbg_printf_2(str_RD_Profile,iVar10,4);
          }
          *(byte *)(iVar4 + 0xd) = ~*(byte *)(iVar4 + 0xc);
          *(byte *)(iVar4 + 0xf) = ~*(byte *)(iVar4 + 0xe);
          if (((*DAT_0003101c == '\x01') || (*DAT_0003101c == '\x02')) && (*DAT_00031064 == '\0')) {
            *DAT_00031054 = '\x01';
          }
          else {
            FLASH_wr_Global();
          }
          dbg_printf_2(str_WR_Profile,iVar10,4);
          return;
        }
        goto LAB_00030e9e;
      }
      cVar9 = cVar2;
      if (bVar1 != 0x22) {
        if (bVar1 == 0x23) {
          if (*DAT_00031054 != '\0') {
            return;
          }
          if (*DAT_00031058 != '\0') {
            return;
          }
          if (*DAT_0003105c != '\0') {
            return;
          }
          if (*DAT_00031060 != '\0') {
            return;
          }
          if (cVar3 != cVar2) {
            *DAT_0003100c = cVar3;
            FLASH_RD_Profile(cVar3);
            set_dpi();
            FUN_0003c2c6();
          }
        }
        else {
          if (bVar1 != 0x24) {
            return;
          }
          FLASH_RD_Profile(cVar3);
          set_dpi();
        }
        goto LAB_00030e9e;
      }
    }
    else if (bVar1 == 0x26) {
      FLASH_RD_Profile(cVar2);
      cVar9 = *(char *)(DAT_00031008 + 0xc);
      if (cVar9 == *pcVar5) goto LAB_00030e9e;
      *pcVar5 = cVar9;
    }
    else if (bVar1 != 0x28) {
      if (bVar1 != 0x29) {
        return;
      }
      dbg_printf(str_read9_GM_macro_report_id_x_macro_index_x,*(undefined1 *)(DAT_00031014 + 2),
                 *puVar7,puVar7,in_r3);
      FLASH_RD_Macro(*puVar7);
      goto LAB_00030e9e;
    }
  }
  FLASH_RD_Profile(cVar9);
LAB_00030e9e:
  *pbVar6 = 0;
  return;
}

/* ==========================================================================
 * nvds_Polling_read   @ 0x00030f4a   (58 bytes)
 * calls     : FUN_0003c2c6, FUN_0003e552, KEY_piaring_cnt, dbg_printf
 * string    : "nvds_Polling_read"
 * string    : "%s read_data= %x, Polling=%x\r\n"
 */

void nvds_Polling_read(void)

{
  int iVar1;
  int iVar2;
  byte in_stack_00000000;
  
  KEY_piaring_cnt();
  iVar2 = FUN_0003e552();
  iVar1 = DAT_00031008;
  if (iVar2 == 0) {
    if (in_stack_00000000 < 9) {
      *(byte *)(DAT_00031008 + 0x16) = in_stack_00000000;
      *(byte *)(iVar1 + 0x17) = ~in_stack_00000000;
    }
  }
  FUN_0003c2c6();
  dbg_printf(str_s_read_data_x_Polling_x,DAT_000310c4,in_stack_00000000,
             *(undefined1 *)(iVar1 + 0x16));
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * nvds_Polling_write   @ 0x00030f96   (48 bytes)
 * calls     : FUN_0003c2c6, FUN_0003e5f0, KEY_piaring_cnt, dbg_printf
 * string    : "nvds_Polling_write"
 * string    : "%s Profile= %x, rgb_disp_type=%x\r\n"
 */

void nvds_Polling_write(void)

{
  int iVar1;
  
  KEY_piaring_cnt();
  iVar1 = DAT_00031008;
  if (*(byte *)(DAT_00031008 + 0x16) < 9) {
    FUN_0003e5f0();
  }
  FUN_0003c2c6();
  dbg_printf(str_s_Profile_x_rgb_disp_type_x,DAT_000310c4 + 0x12,*(undefined1 *)(iVar1 + 0xc),
             *(undefined1 *)(iVar1 + 0x16));
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * profile_mem_init   @ 0x00030fc6   (42 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FLASH_RD_Global, FLASH_RD_Profile, KEY_piaring_cnt, dbg_printf, read
 * string    : "profile_mem_init"
 * string    : "%s \r\n"
 */

void profile_mem_init(void)

{
  dbg_printf(str_s_9,DAT_000310c4 + 0x25);
  KEY_piaring_cnt();
  FLASH_RD_Global();
  KEY_piaring_cnt();
  FLASH_RD_Profile(*(undefined1 *)(DAT_00031008 + 0xc));
  KEY_piaring_cnt();
  read();
  return;
}

/* ==========================================================================
 * FUN_00031808   @ 0x00031808   (102 bytes)
 * calls     : FUN_0003c2c6, FUN_0003cf24
 */

void FUN_00031808(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  
  iVar2 = DAT_00031c00;
  cVar1 = *(char *)(DAT_00031c00 + 0x16);
  if (cVar1 == '\x01') {
    uVar4 = 8;
  }
  else {
    if (cVar1 == '\x02') {
      *(undefined1 *)(DAT_00031c00 + 0x16) = 1;
      goto LAB_00031820;
    }
    if (cVar1 == '\b') {
      uVar4 = 4;
    }
    else {
      uVar4 = 2;
    }
  }
  *(undefined1 *)(DAT_00031c00 + 0x16) = uVar4;
LAB_00031820:
  FUN_0003c2c6();
  FUN_0003cf24();
  if (((*DAT_00031c04 == '\x01') || (*DAT_00031c04 == '\x02')) && (*DAT_00031c08 == '\0')) {
    *DAT_00031c18 = 1;
  }
  else {
    *DAT_00031c0c = 6;
  }
  puVar3 = DAT_00031c10;
  *DAT_00031c10 = 0x10;
  puVar3[1] = 0x20;
  puVar3[2] = *(undefined1 *)(iVar2 + 0x16);
  puVar3[3] = 0;
  *DAT_00031c14 = 1;
  return;
}

/* ==========================================================================
 * FUN_0003262c   @ 0x0003262c   (44 bytes)
 * called by : Success_led_2second, Success_led_2second_2, enter_BLE_normal_app_mode, f_usb_isConnected, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 */

void FUN_0003262c(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  puVar2 = DAT_000329e4;
  *DAT_000329e4 = 0;
  if (*DAT_000329ec == '\0') {
    cVar1 = *DAT_000329f0;
    if (cVar1 == '\0') {
      uVar3 = 1;
    }
    else if (cVar1 == '\x01') {
      uVar3 = 2;
    }
    else {
      if (cVar1 != '\x02') {
        return;
      }
      uVar3 = 4;
    }
    *puVar2 = uVar3;
  }
  return;
}

/* ==========================================================================
 * FUN_00032658   @ 0x00032658   (46 bytes)
 * called by : FUN_00032942, Set_SIMU_mode_LightUp_Led, Success_led_2second, Success_led_2second_2, enter_BLE_normal_app_mode, f_usb_isConnected, ... (+4 more)
 */

void FUN_00032658(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = DAT_000329e8;
  bVar1 = *DAT_000329e4;
  if ((bVar1 & 1) == 0) {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 2;
  }
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    *(undefined4 *)(iVar2 + 0x24) = 2;
  }
  else {
    *(undefined4 *)(iVar2 + 0x24) = 0;
  }
  if ((int)((uint)bVar1 << 0x1d) < 0) {
    *(undefined4 *)(iVar2 + 0x28) = 2;
    return;
  }
  *(undefined4 *)(iVar2 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * set_USB_led_flash   @ 0x00032766   (100 bytes)
 * calls     : FUN_0003262c, FUN_00032658, FUN_00032e82, FUN_00032f16, FUN_0003c8b6, FUN_0003cf7c, ... (+2 more)
 * string    : "set_USB_led_flash"
 * string    : "%s ,%x\r\n"
 * string    : "%s, Ind_Led_STEP=%d\r\n"
 */

void set_USB_led_flash(void)

{
  undefined1 *puVar1;
  
  dbg_printf(str_s_x,DAT_000329f8 + 0x30,*DAT_000329f0);
  *DAT_00032a48 = 0;
  *DAT_00032a4c = 0;
  *DAT_00032a50 = 1;
  *DAT_00032a54 = 0;
  *DAT_00032a58 = 0x10;
  *DAT_00032a5c = 1;
  *DAT_00032a60 = 0x20;
  FUN_0003262c();
  FUN_00032658();
  puVar1 = DAT_00032a64;
  *DAT_00032a64 = 0x3d;
  FUN_00032f16();
  FUN_00032e82();
  dbg_printf(str_s_Ind_Led_STEP_d,DAT_000329f8 + 0x30,*puVar1);
  FUN_0003c8b6();
  OLED_Clear();
  FUN_0003cf7c();
  return;
}

/* ==========================================================================
 * set_pairing_led_flash   @ 0x000327ca   (86 bytes)
 * called by : FUN_0002fef0
 * calls     : FUN_0003262c, FUN_00032658, FUN_00032e82, FUN_00032f16, FUN_0003c8b6, FUN_0003cf7c, ... (+2 more)
 * string    : "set_pairing_led_flash"
 * string    : "%s, Ind_Led_STEP=%d\r\n"
 */

void set_pairing_led_flash(void)

{
  undefined1 *puVar1;
  
  *DAT_00032a48 = 0;
  *DAT_00032a4c = 0;
  *DAT_00032a58 = 0x3c;
  *DAT_00032a5c = 1;
  *DAT_00032a50 = 1;
  *DAT_00032a54 = 0;
  *DAT_00032a60 = 0x78;
  FUN_0003262c();
  FUN_00032658();
  puVar1 = DAT_00032a64;
  *DAT_00032a64 = 0x3d;
  FUN_00032f16();
  FUN_00032e82();
  dbg_printf(str_s_Ind_Led_STEP_d,DAT_000329f8 + 0x42,*puVar1);
  FUN_0003c8b6();
  OLED_Clear();
  FUN_0003cf7c();
  return;
}

/* ==========================================================================
 * set_bonded_led_flash   @ 0x00032820   (102 bytes)
 * called by : LightUp_Mode_Led, SLEEP, fWorkModeInit, f_reconnect_24G
 * calls     : FUN_0003262c, FUN_00032658, FUN_00032e82, FUN_00032f16, FUN_0003c8b6, FUN_0003cf7c, ... (+2 more)
 * string    : "set_bonded_led_flash"
 * string    : "%s, %x \r\n"
 * string    : "%s, Ind_Led_STEP=%d\r\n"
 */

void set_bonded_led_flash(void)

{
  undefined1 *puVar1;
  
  dbg_printf(str_s_x_2,DAT_000329f8 + 0x58,*DAT_000329f0);
  *DAT_00032a48 = 0;
  *DAT_00032a4c = 0;
  *DAT_00032a58 = 10;
  *DAT_00032a5c = 1;
  *DAT_00032a50 = 2;
  *DAT_00032a54 = 0;
  *DAT_00032a60 = 0x28;
  FUN_0003262c();
  FUN_00032658();
  puVar1 = DAT_00032a64;
  *DAT_00032a64 = 0x3d;
  FUN_00032f16();
  FUN_00032e82();
  dbg_printf(str_s_Ind_Led_STEP_d,DAT_000329f8 + 0x58,*puVar1);
  FUN_0003c8b6();
  OLED_Clear();
  FUN_0003cf7c();
  return;
}

/* ==========================================================================
 * FUN_00032e82   @ 0x00032e82   (2 bytes)
 * called by : FUN_0003297e, SLEEP, app_mutli_link_change, force_ble_sleep_2, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 */

void FUN_00032e82(void)

{
  return;
}

/* ==========================================================================
 * FUN_00032f16   @ 0x00032f16   (12 bytes)
 * called by : FUN_0003297e, SLEEP, app_mutli_link_change, force_ble_sleep_2, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 * calls     : rom_24FEC
 */

void FUN_00032f16(void)

{
  rom_24FEC(PTR_DAT_00032fdc,0x18);
  return;
}

/* ==========================================================================
 * FUN_000333f0   @ 0x000333f0   (116 bytes)
 * calls     : FLASH_RD_Profile, OLED_Init, dbg_printf_2, rom_24F9C, rom_24FEC, rom_25078
 */

void FUN_000333f0(void)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined2 unaff_r7;
  
  OLED_Init();
  iVar3 = DAT_000337dc;
  rom_24FEC(*(undefined4 *)(DAT_000337dc + 4),0x84);
  iVar4 = DAT_000337e4;
  iVar6 = DAT_000337e0 + 0x20;
  rom_25078();
  iVar6 = iVar6 + iVar4;
  *(undefined2 *)(iVar6 + 0x12) = unaff_r7;
  rom_24F9C(DAT_000337e0,DAT_000337e4 + 0x18,0x2f);
  uVar2 = *(undefined2 *)(DAT_000337e4 + 0x48);
  *(char *)(iVar6 + 0xf) = (char)((ushort)uVar2 >> 8);
  *(char *)(iVar6 + 0x10) = (char)uVar2;
  rom_24F9C(*(undefined4 *)(iVar3 + 4),DAT_000337e0,0x31);
  dbg_printf_2(str_GM04_sensit_get,*(undefined4 *)(iVar3 + 4),0x31);
  pcVar5 = DAT_00033810;
  *(int *)(iVar3 + 4) = DAT_000337dc + 9;
  cVar1 = *(char *)(iVar4 + 0xc);
  if (cVar1 != *pcVar5) {
    *pcVar5 = cVar1;
    FLASH_RD_Profile();
  }
  return;
}

/* ==========================================================================
 * FUN_00036cbe   @ 0x00036cbe   (20 bytes)
 * called by : FUN_0002fef0
 */

void FUN_00036cbe(void)

{
  int iVar1;
  
  iVar1 = DAT_00036d84;
  *(undefined4 *)(DAT_00036d84 + 0xd4) = 0;
  *(undefined4 *)(DAT_00036d84 + 0x14) = 0x8a;
  *(undefined4 *)(iVar1 + 0xd4) = 1;
  return;
}

/* ==========================================================================
 * FUN_00036cee   @ 0x00036cee   (32 bytes)
 * called by : FUN_0002fef0
 * calls     : FUN_000369fa
 */

void FUN_00036cee(void)

{
  FUN_000369fa(DAT_00036d84 + 0x1c,DAT_00036d88 + 0x18,3);
  FUN_000369fa(DAT_00036d84 + 0x54,DAT_00036d88 + 0x18,3);
  return;
}

/* ==========================================================================
 * FUN_00036f88   @ 0x00036f88   (26 bytes)
 * called by : FUN_000371c2, FUN_00038072, FUN_00038144, _USB_macro2
 */

void FUN_00036f88(int param_1)

{
  bool bVar1;
  undefined4 local_8;
  
  local_8 = param_1;
  if (*DAT_00037380 == '\x05') {
    local_8 = param_1 << 2;
  }
  do {
    bVar1 = local_8 != 0;
    local_8 = local_8 + -1;
  } while (bVar1);
  return;
}

/* ==========================================================================
 * FUN_00036fec   @ 0x00036fec   (12 bytes)
 * called by : FUN_000374e2, _USB_macro2
 */

undefined2 FUN_00036fec(void)

{
  return *(undefined2 *)(DAT_00037384 + 0x11);
}

/* ==========================================================================
 * FUN_00036ff8   @ 0x00036ff8   (12 bytes)
 * called by : FUN_00037004
 */

undefined2 FUN_00036ff8(void)

{
  return *(undefined2 *)(DAT_00037384 + 0x16);
}

/* ==========================================================================
 * FUN_00037004   @ 0x00037004   (116 bytes)
 * called by : FUN_00037508, _USB_macro2
 * calls     : FUN_00036ff8, rom_24F9C
 */

uint FUN_00037004(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_20;
  uint local_1c;
  
  *(char *)(DAT_00037384 + 0xe) = (char)param_1;
  uVar4 = param_2;
  uVar2 = FUN_00036ff8();
  if ((uVar4 & 3) == 0) {
    local_1c = uVar2 >> 2;
  }
  else {
    local_1c = 0;
  }
  uVar4 = 0;
  puVar3 = (undefined4 *)((param_1 * 4 + 0x20U & 0xff) + DAT_00037384);
  for (uVar5 = 0; iVar1 = DAT_00037384, uVar5 < local_1c; uVar5 = uVar5 + 1) {
    local_20 = *puVar3;
    rom_24F9C(param_2 + uVar4,&local_20,4);
    uVar4 = uVar4 + 4;
  }
  for (; uVar4 < uVar2; uVar4 = uVar4 + 1) {
    *(undefined1 *)(param_2 + uVar4) = *(undefined1 *)puVar3;
  }
  if (param_1 == 0) {
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  else {
    *(undefined1 *)(iVar1 + 0x14) = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * _USB_macro2   @ 0x0003726a   (560 bytes)
 * called by : FUN_00037534
 * calls     : FUN_00036f88, FUN_00036fec, FUN_00037004, FUN_000370d0, FUN_00037104, FUN_00038072, ... (+4 more)
 * string    : "set report rd:"
 * string    : "usb set report:"
 * string    : "_USB_macro0:"
 * string    : "_USB_macro1:"
 * string    : "_USB_macro2:"
 * string    : "_USB_macro:"
 */

void _USB_macro2(void)

{
  ushort uVar1;
  byte *pbVar2;
  byte *pbVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  char *pcVar12;
  char local_a8;
  byte local_a7;
  byte local_a6;
  char local_a5;
  byte local_a4 [132];
  undefined1 auStack_20 [12];
  
  pcVar12 = &local_a8;
  rom_24FEC(&local_a8,0x88);
  pbVar2 = DAT_00037384;
  DAT_00037384[0xe] = 0;
  uVar6 = FUN_00036fec();
  FUN_00036f88(100);
  piVar4 = DAT_0003769c;
  pcVar11 = DAT_00037698;
  pbVar3 = DAT_00037394;
  iVar9 = DAT_00037388;
  if ((uVar6 & 1) == 0) {
    if ((int)(uVar6 << 0x1b) < 0) {
      pbVar2[0x11] = 0x80;
    }
    else {
      if (*(char *)(DAT_00037388 + 0xe) == '\x01') {
        if (*DAT_00037394 < 0x40) {
          rom_24F9C(*DAT_0003769c,&local_a8);
          bVar5 = 0;
        }
        else {
          rom_24F9C(*DAT_0003769c,&local_a8,0x40);
          *piVar4 = *piVar4 + 0x40;
          bVar5 = *pbVar3 - 0x40;
        }
        *pbVar3 = bVar5;
        goto LAB_00037480;
      }
      if (*DAT_00037698 == '\x04') {
        *pbVar2 = *DAT_000376a0 & 0x7f;
        *pcVar11 = '\b';
      }
    }
    *(undefined1 *)(iVar9 + 0xe) = 5;
  }
  else {
    if (*(char *)(DAT_00037388 + 0xe) == '\x02') {
      iVar8 = FUN_00037004(0,&local_a8);
      iVar7 = DAT_00037388;
      uVar1 = *(ushort *)(iVar9 + 10);
      if (iVar8 < (int)(uint)uVar1) {
        uVar10 = FUN_0004245e(iVar9 + 4);
        rom_24F9C(uVar10,&local_a8,iVar8);
        iVar8 = (uint)*(ushort *)(iVar9 + 10) - iVar8;
        *(char *)(iVar9 + 10) = (char)iVar8;
        *(char *)(iVar9 + 0xb) = (char)((uint)iVar8 >> 8);
        return;
      }
      iVar9 = DAT_00037388 + 4;
      *(undefined1 *)(DAT_00037388 + 0xe) = 5;
      uVar10 = FUN_0004245e(iVar9);
      rom_24F9C(uVar10,&local_a8,(uint)uVar1);
      pbVar2 = DAT_0003739c;
      iVar9 = DAT_00037398;
      if (*(short *)(iVar7 + 10) != 0) {
        if (*(short *)(iVar7 + 10) == 1) {
          *DAT_000373a0 = local_a8;
          *DAT_000373a4 = 1;
          *(undefined1 *)(iVar9 + 1) = 0;
        }
        else {
          if (local_a8 == -0x60) {
            *(byte *)(DAT_00037398 + 2) = local_a7;
            *pbVar3 = local_a6;
            *pbVar2 = local_a4[0];
            if (*(char *)(iVar9 + 1) == '\x02') {
              *DAT_000373c0 = 1;
            }
            else {
              *DAT_000373a8 = 0;
              *DAT_000373ac = 0;
            }
            bVar5 = 8;
            pcVar11 = str_set_report_rd;
          }
          else {
            *(char *)(DAT_00037398 + 2) = local_a8;
            uVar6 = (uint)local_a7;
            *DAT_00037394 = local_a7;
            iVar7 = iVar9 + 9;
            *pbVar2 = local_a6;
            if (local_a8 == '\t') {
              *DAT_00037644 = local_a5;
              iVar8 = DAT_0003765c;
              pbVar2 = DAT_00037648;
              if (local_a5 == '\0') {
                rom_24FEC(iVar7,0x84);
                *(int *)(iVar9 + 4) = iVar7;
                pbVar2 = DAT_00037648;
                rom_24F9C(iVar7,&local_a8,uVar6);
                bVar5 = *pbVar2;
                pcVar12 = *(char **)(iVar9 + 4);
                pcVar11 = str_USB_macro0;
              }
              else {
                if (local_a5 != '\x01') {
                  if (local_a5 == '\x02') {
                    iVar8 = DAT_0003765c + 0x3c;
                    *(int *)(iVar9 + 4) = iVar8;
                    rom_24F9C(iVar8,local_a4,8);
                    dbg_printf_2(str_USB_macro2,iVar8,8);
                    *(int *)(iVar9 + 4) = iVar7;
                    dbg_printf_2(str_USB_macro,iVar7,0x84);
                    if (*(char *)(iVar9 + 1) == '\x01') {
                      *DAT_0003768c = 1;
                    }
                    *DAT_00037690 = 1;
                  }
                  goto LAB_00037450;
                }
                *(int *)(iVar9 + 4) = DAT_0003765c;
                rom_24F9C(iVar8,local_a4,uVar6 - 4);
                bVar5 = *pbVar2;
                pcVar12 = *(char **)(iVar9 + 4);
                pcVar11 = str_USB_macro1;
              }
            }
            else {
              if (*(char *)(iVar9 + 1) == '\x01') {
                *DAT_000373c0 = 1;
              }
              *(int *)(iVar9 + 4) = iVar7;
              pbVar2 = DAT_00037394;
              rom_24F9C(iVar7,&local_a8,uVar6);
              *DAT_000373c4 = 1;
              bVar5 = *pbVar2;
              pcVar11 = str_usb_set_report;
              pcVar12 = &local_a8;
            }
          }
          dbg_printf_2(pcVar11,pcVar12,bVar5);
        }
      }
LAB_00037450:
      iVar9 = DAT_00037694;
      *(undefined1 *)(DAT_00037694 + 10) = 0;
      *(undefined1 *)(iVar9 + 0xb) = 0;
      FUN_000370d0();
      return;
    }
    iVar7 = FUN_00037004(0,&local_a8);
    if (0 < iVar7) {
      rom_24F9C(auStack_20,&local_a8);
      FUN_00038072(auStack_20,iVar9);
      return;
    }
LAB_00037480:
    FUN_00037104(0,DAT_00037694);
  }
  return;
}

/* ==========================================================================
 * FUN_00037b02   @ 0x00037b02   (8 bytes)
 * called by : FUN_00038072
 */

uint FUN_00037b02(byte *param_1)

{
  return (*param_1 & 0x7f) >> 5;
}

/* ==========================================================================
 * FUN_00038068   @ 0x00038068   (10 bytes)
 * called by : FUN_00038072
 */

void FUN_00038068(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00038070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_00038230 + (uint)*(byte *)(param_1 + 1) * 4))();
  return;
}

/* ==========================================================================
 * FUN_00038072   @ 0x00038072   (52 bytes)
 * called by : _USB_macro2
 * calls     : FUN_00036f88, FUN_000370c6, FUN_00037b02, FUN_00038068, HID_RQT_Get_Protocol
 */

void FUN_00038072(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00037b02(param_1,param_2,param_1);
  if (uVar1 == 0) {
    FUN_00038068(param_1);
    FUN_00036f88(300);
    return;
  }
  if (uVar1 != 1) {
    if (1 < uVar1) {
      FUN_000370c6(0);
    }
    return;
  }
  HID_RQT_Get_Protocol(param_1);
  return;
}

/* ==========================================================================
 * FUN_00038144   @ 0x00038144   (40 bytes)
 * calls     : FUN_00036f88
 */

void FUN_00038144(int param_1)

{
  if (param_1 == 0) {
    DAT_0080000c = DAT_0080000c | 0x800;
  }
  else {
    DAT_0080000c = DAT_0080000c | 0x800;
    FUN_00036f88(500);
    DAT_0080000c = DAT_0080000c & 0xfffff7ff;
  }
  return;
}

/* ==========================================================================
 * FUN_000391c0   @ 0x000391c0   (34 bytes)
 * called by : FUN_000391fc, FUN_00039708, FUN_0003976e, flash_mid
 */

int FUN_000391c0(void)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = DAT_0003958c;
  do {
  } while (*DAT_0003958c < 0);
  *DAT_0003958c = DAT_00039594;
  do {
  } while (*piVar1 < 0);
  uVar2 = 0;
  do {
    piVar1[1] = -1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return piVar1[4];
}

/* ==========================================================================
 * FUN_000391e2   @ 0x000391e2   (26 bytes)
 * called by : FUN_000392b8, FUN_0003932e
 */

uint FUN_000391e2(void)

{
  int *piVar1;
  
  piVar1 = DAT_0003958c;
  do {
  } while (*DAT_0003958c < 0);
  *DAT_0003958c = DAT_00039598;
  do {
  } while (*piVar1 < 0);
  return piVar1[5] & 0xff;
}

/* ==========================================================================
 * FUN_000391fc   @ 0x000391fc   (188 bytes)
 * called by : FUN_000392b8, FUN_0003932e
 * calls     : FUN_000391c0
 */

void FUN_000391fc(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  iVar1 = FUN_000391c0();
  iVar5 = DAT_0003959c;
  piVar6 = DAT_0003958c;
  iVar2 = *(int *)(DAT_0003959c + 8);
  if (iVar1 != iVar2) {
    return;
  }
  if (iVar2 == DAT_000395a0) {
LAB_0003925e:
    uVar3 = DAT_0003958c[7];
    uVar4 = DAT_000395b8;
LAB_00039262:
    uVar3 = uVar3 & uVar4;
  }
  else {
    if (iVar2 < DAT_000395a0) {
      if (iVar2 + DAT_000395a4 != 0) {
        iVar1 = iVar2 + DAT_000395a4 + DAT_000395a8;
        if (iVar1 == 0) {
LAB_00039296:
          uVar3 = DAT_0003958c[7];
          uVar4 = DAT_000395bc;
          goto LAB_00039262;
        }
        iVar1 = iVar1 + DAT_000395ac;
        if ((iVar1 == 0) || (iVar1 == 1)) {
          uVar3 = DAT_0003958c[7];
          uVar4 = DAT_000395b4;
          goto LAB_00039262;
        }
      }
    }
    else {
      iVar1 = (iVar2 - DAT_000395a0) + -0x2400;
      if (iVar1 != 0) {
        iVar1 = iVar1 + DAT_000395b0;
        if (iVar1 == 0) goto LAB_00039296;
        if ((iVar1 == 0x12e000) || (iVar1 == 0x12e001)) goto LAB_0003925e;
      }
    }
    uVar3 = DAT_0003958c[7] & 0xffff0fff;
  }
  DAT_0003958c[7] = uVar3;
  if ((param_1 != 0) && (param_1 < 3)) {
    piVar6[7] = piVar6[7] | param_2 << 10 | 0x200U;
    do {
    } while (*piVar6 < 0);
    iVar1 = FUN_000391c0();
    if (iVar1 == *(int *)(iVar5 + 8)) {
      iVar5 = DAT_000395c0;
      if ((param_1 == 1) || (iVar5 = DAT_000395c4, param_1 == 2)) {
        *piVar6 = iVar5;
      }
      do {
      } while (*piVar6 < 0);
      *piVar6 = 0x7d000;
      do {
      } while (*piVar6 < 0);
    }
  }
  return;
}

/* ==========================================================================
 * FUN_000392b8   @ 0x000392b8   (118 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, FUN_0003943c, FUN_00039526, app_usb_upgrade_start, ... (+4 more)
 * calls     : FUN_000391e2, FUN_000391fc
 */

void FUN_000392b8(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_000391e2();
  iVar3 = *(int *)(DAT_0003959c + 8);
  if (iVar3 == DAT_000395a0) {
LAB_0003931e:
    if (iVar1 == 0xac) {
      return;
    }
    iVar3 = 0xac;
LAB_00039312:
    uVar2 = 2;
  }
  else {
    if (iVar3 < DAT_000395a0) {
      if (iVar3 + DAT_000395c8 != 0) {
        iVar3 = iVar3 + DAT_000395c8 + DAT_000395cc;
        if (iVar3 == 0) {
LAB_00039326:
          if (iVar1 == 0x2c) {
            return;
          }
          iVar3 = 0x2c;
        }
        else {
          iVar3 = iVar3 + DAT_000395ac;
          if ((iVar3 != 0) && (iVar3 != 1)) goto LAB_000392fe;
          iVar3 = DAT_000395d0;
          if (iVar1 == DAT_000395d0) {
            return;
          }
        }
        goto LAB_00039312;
      }
      if (iVar1 == 0xac) {
        return;
      }
      iVar3 = 0xac;
    }
    else {
      iVar3 = (iVar3 - DAT_000395a0) + -0x2400;
      if (iVar3 != 0) {
        iVar3 = iVar3 + DAT_000395b0;
        if (iVar3 == 0) goto LAB_00039326;
        if ((iVar3 == 0x12e000) || (iVar3 == 0x12e001)) goto LAB_0003931e;
      }
LAB_000392fe:
      if (iVar1 == 0x98) {
        return;
      }
      iVar3 = 0x98;
    }
    uVar2 = 1;
  }
  FUN_000391fc(uVar2,iVar3);
  return;
}

/* ==========================================================================
 * FUN_0003932e   @ 0x0003932e   (118 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, FUN_0003943c, FUN_00039526, flash_erase, ... (+3 more)
 * calls     : FUN_000391e2, FUN_000391fc
 */

void FUN_0003932e(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_000391e2();
  iVar3 = *(int *)(DAT_0003959c + 8);
  if (iVar3 == DAT_000395a0) {
LAB_00039392:
    if (iVar1 == 0x94) {
      return;
    }
    uVar4 = 0x94;
LAB_00039398:
    uVar2 = 2;
  }
  else {
    if (iVar3 < DAT_000395a0) {
      if (iVar3 + DAT_000395c8 != 0) {
        iVar3 = iVar3 + DAT_000395c8 + DAT_000395cc;
        if (iVar3 == 0) {
LAB_0003939c:
          if (iVar1 == 0x10) {
            return;
          }
          uVar4 = 0x10;
        }
        else {
          iVar3 = iVar3 + DAT_000395ac;
          if ((iVar3 != 0) && (iVar3 != 1)) goto LAB_00039374;
          if (iVar1 == 0xbc) {
            return;
          }
          uVar4 = 0xbc;
        }
        goto LAB_00039398;
      }
      if (iVar1 == 0xbc) {
        return;
      }
      uVar4 = 0xbc;
    }
    else {
      iVar3 = (iVar3 - DAT_000395a0) + -0x2400;
      if (iVar3 != 0) {
        iVar3 = iVar3 + DAT_000395b0;
        if (iVar3 == 0) goto LAB_0003939c;
        if ((iVar3 == 0x12e000) || (iVar3 == 0x12e001)) goto LAB_00039392;
      }
LAB_00039374:
      if (iVar1 == 0x9c) {
        return;
      }
      uVar4 = 0x9c;
    }
    uVar2 = 1;
  }
  FUN_000391fc(uVar2,uVar4);
  return;
}

/* ==========================================================================
 * flash_mid   @ 0x000393a4   (24 bytes)
 * called by : FUN_00039428
 * calls     : FUN_000391c0, FUN_0003932e, dbg_printf
 * string    : "flash_mid=%x\n"
 */

void flash_mid(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_000391c0();
  iVar1 = DAT_0003959c;
  *(undefined4 *)(DAT_0003959c + 8) = uVar2;
  FUN_0003932e();
  dbg_printf(str_flash_mid_x,*(undefined4 *)(iVar1 + 8));
  return;
}

/* ==========================================================================
 * FUN_0003943c   @ 0x0003943c   (78 bytes)
 * called by : FUN_0003976e
 * calls     : FUN_000392b8, FUN_0003932e, rom_25024, rom_25038, rom_2504C, rom_2505C
 */

void FUN_0003943c(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = rom_25024();
  iVar3 = rom_25038();
  if ((*(char *)(DAT_0003959c + 4) == -0x55) && (*(char *)(DAT_0003959c + 5) == -0x44)) {
    FUN_000392b8();
    puVar1 = DAT_0003958c;
    do {
    } while ((int)*DAT_0003958c < 0);
    *DAT_0003958c = param_1 | 0x2d000000;
    do {
    } while ((int)*puVar1 < 0);
    FUN_0003932e();
  }
  if (iVar2 == 0) {
    rom_2504C();
  }
  if (iVar3 == 0) {
    rom_2505C();
  }
  return;
}

/* ==========================================================================
 * FUN_00039526   @ 0x00039526   (268 bytes)
 * called by : FUN_00039708
 * calls     : FUN_000392b8, FUN_0003932e, FUN_0003948a, rom_24FEC, rom_25024, rom_25038, ... (+2 more)
 */

void FUN_00039526(undefined1 *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  uint *puVar2;
  char *pcVar3;
  uint uVar4;
  uint local_48;
  uint local_44;
  undefined1 auStack_40 [32];
  int local_20;
  int local_1c;
  
  local_48 = param_2 & 0xffffffe0;
  rom_24FEC(auStack_40,0x1c);
  local_44 = *DAT_000395ec;
  if ((param_3 != 0) && (0x3ffff < param_2)) {
    local_1c = rom_25024();
    local_20 = rom_25038();
    puVar2 = DAT_0003958c;
    do {
    } while ((int)*DAT_0003958c < 0);
    *(undefined1 *)(DAT_0003959c + 2) = 0xc2;
    FUN_000392b8();
    while (param_3 != 0) {
      if (((param_2 & 0x1f) != 0) || (param_3 < 0x20)) {
        FUN_0003948a(&local_44,local_48,0x20);
      }
      for (uVar4 = param_2 & 0x1f; uVar4 < 0x20; uVar4 = uVar4 + 1) {
        if (param_3 != 0) {
          uVar1 = *param_1;
          param_3 = param_3 - 1;
          param_2 = param_2 + 1;
          param_1 = param_1 + 1;
          *(undefined1 *)((int)&local_44 + uVar4) = uVar1;
        }
      }
      DAT_0003999c[3] = -0x2f;
      uVar4 = 0;
      do {
        puVar2[1] = *(uint *)(auStack_40 + uVar4 * 4 + -4);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 8);
      if ((*DAT_0003999c == -0x5a) && (DAT_0003999c[1] == -0x4d)) {
        do {
        } while ((int)*puVar2 < 0);
        if (DAT_0003999c[2] == -0x3e) {
          if (local_48 < 0x40000) {
            return;
          }
          *puVar2 = local_48 | 0x2c000000;
        }
        do {
        } while ((int)*puVar2 < 0);
      }
      local_48 = local_48 + 0x20;
    }
    FUN_0003932e();
    *puVar2 = 0x7d000;
    pcVar3 = DAT_0003999c;
    DAT_0003999c[2] = '\0';
    pcVar3[3] = '\0';
    uVar4 = 0;
    do {
      puVar2[1] = 0xffffffff;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
    if (local_1c == 0) {
      rom_2504C();
    }
    if (local_20 == 0) {
      rom_2505C();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_000396da   @ 0x000396da   (46 bytes)
 * called by : Default_Profile, FLASH_RD_Global, FLASH_RD_Macro, FLASH_RD_Profile, FLASH_WR_Profile, FLASH_wr_Global, ... (+8 more)
 * calls     : FUN_0003948a
 */

undefined4 FUN_000396da(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_2 + param_3 & 0xffffff00;
  if ((param_2 & 0xffffff00) != uVar1) {
    FUN_0003948a(param_4,param_2,uVar1 - param_2,param_4,param_4);
    param_3 = (param_2 + param_3) - uVar1;
    param_4 = param_4 + (uVar1 - param_2);
    param_2 = uVar1;
  }
  FUN_0003948a(param_4,param_2,param_3);
  return 0;
}

/* ==========================================================================
 * FUN_00039708   @ 0x00039708   (102 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, FUN_0003e4ea, FUN_000405ae, flash_erase, ... (+3 more)
 * calls     : FUN_000391c0, FUN_00039526, dbg_printf
 */

undefined4 FUN_00039708(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = FUN_000391c0();
  puVar1 = DAT_0003999c;
  if (iVar2 == *(int *)(DAT_0003999c + 8)) {
    *DAT_0003999c = 0xa6;
    uVar4 = param_2 + param_3 & 0xffffff00;
    if ((param_2 & 0xffffff00) == uVar4) {
      puVar1[1] = 0xb3;
    }
    else {
      puVar1[1] = 0xb3;
      FUN_00039526(param_4,param_2,uVar4 - param_2);
      param_3 = (param_2 + param_3) - uVar4;
      param_4 = param_4 + (uVar4 - param_2);
      param_2 = uVar4;
    }
    FUN_00039526(param_4,param_2,param_3);
    uVar3 = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  else {
    uVar3 = FUN_000391c0();
    dbg_printf(str_flash_0x_x + 1,uVar3);
    uVar3 = 0xff;
  }
  return uVar3;
}

/* ==========================================================================
 * FUN_0003976e   @ 0x0003976e   (90 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, flash_erase, flash_read, flash_write_some_data, ... (+1 more)
 * calls     : FUN_000391c0, FUN_0003943c
 */

undefined4 FUN_0003976e(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0003999c;
  *(undefined1 *)(DAT_0003999c + 4) = 0xab;
  iVar2 = FUN_000391c0();
  if (iVar2 != *(int *)(iVar1 + 8)) {
    return 0xff;
  }
  param_2 = param_2 & 0xfffff000;
  *(undefined1 *)(iVar1 + 5) = 0xbc;
  for (iVar2 = 0;
      iVar2 < (int)((uint)(0 < param_3 % 0x1000) +
                   ((int)(((uint)(param_3 >> 0x1f) >> 0x14) + param_3) >> 0xc)); iVar2 = iVar2 + 1)
  {
    FUN_0003943c(param_2);
    param_2 = param_2 + 0x1000;
  }
  *(undefined1 *)(iVar1 + 4) = 0;
  *(undefined1 *)(iVar1 + 5) = 0;
  return 0;
}

/* ==========================================================================
 * flash_write_some_data   @ 0x000397c8   (146 bytes)
 * called by : app_usb_upgrade_start, write_2
 * calls     : FUN_000392b8, FUN_0003932e, FUN_000396da, FUN_00039708, FUN_0003976e, dbg_printf, ... (+2 more)
 * string    : "flash_write_some_data"
 * string    : "back flash_read:"
 * string    : "flash_erase: "
 * string    : "memcpy:"
 * string    : "flash_write:"
 * string    : "flash_wp_ALL: "
 */

void flash_write_some_data(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined1 auStack_424 [1028];
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  dbg_printf(str_flash_write_some_data);
  FUN_000392b8();
  FUN_000396da(0,param_2 & 0xfffffc00,0x400,auStack_424,0);
  dbg_printf_2(str_back_flash_read,auStack_424,0x10);
  FUN_0003976e(0,param_2,0x1000);
  dbg_printf(str_flash_erase);
  puVar1 = auStack_424 + (param_2 & 0x3ff);
  rom_24F9C(puVar1,local_20,local_18);
  dbg_printf_2(str_memcpy,puVar1,0x10);
  FUN_00039708(0,param_2 & 0xfffffc00,0x400,auStack_424,0);
  dbg_printf_2(str_flash_write,puVar1,0x80);
  FUN_0003932e();
  dbg_printf(str_flash_wp_ALL_2);
  return;
}

/* ==========================================================================
 * flash_read   @ 0x0003985a   (128 bytes)
 * calls     : FUN_000392b8, FUN_0003932e, FUN_000396da, FUN_00039708, FUN_0003976e, dbg_printf, ... (+1 more)
 * string    : "flash_wp_256k: "
 * string    : "flash_read: "
 * string    : "flash_erase: "
 * string    : "flash_write: "
 * string    : "flash_wp_ALL: "
 */

void flash_read(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  undefined4 *puVar4;
  
  iVar1 = DAT_00039a24;
  iVar2 = DAT_00039a24 + -0x20;
  puVar3 = (undefined4 *)((int)&local_20 + DAT_00039a24);
  puVar4 = (undefined4 *)((int)&local_20 + DAT_00039a24);
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  dbg_printf(str_flash_wp_256k);
  FUN_000392b8();
  dbg_printf(str_flash_read);
  iVar1 = (int)&uStack_1c + iVar1;
  *puVar3 = 0;
  FUN_000396da(0,param_2 & 0xfffff000,0x1000,iVar1);
  dbg_printf(str_flash_read);
  iVar2 = DAT_00039a48 + iVar2;
  rom_24F9C((param_2 & 0xfff) + iVar1,*(undefined4 *)((int)&local_18 + iVar2 + 0x20),
            *(undefined4 *)(&stack0xfffffff0 + iVar2 + 0x20));
  FUN_0003976e(0,param_2,DAT_00039a48);
  dbg_printf(str_flash_erase);
  *puVar4 = 0;
  FUN_00039708(0,param_2 & 0xfffff000,DAT_00039a48,iVar1);
  dbg_printf(str_flash_write_2);
  FUN_0003932e();
  dbg_printf(str_flash_wp_ALL_2);
  return;
}

/* ==========================================================================
 * r_temp1   @ 0x000398da   (194 bytes)
 * calls     : FUN_000392b8, FUN_000396da, FUN_00039708, FUN_0003976e, dbg_printf
 * string    : "flash_test\n "
 * string    : "r_temp1: "
 */

void r_temp1(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_214 [256];
  undefined1 local_114 [256];
  
  FUN_000392b8();
  dbg_printf(str_flash_test);
  uVar1 = DAT_00039a6c;
  FUN_000396da(0,DAT_00039a6c,0xff,local_214,0);
  dbg_printf(str_r_temp1);
  iVar2 = 0;
  do {
    dbg_printf(&DAT_00039a7c,local_214[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  dbg_printf(&DAT_00039a80);
  iVar2 = 0;
  do {
    local_114[iVar2] = (char)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  FUN_00039708(0,uVar1,0xff,local_114,0);
  FUN_000396da(0,uVar1,0xff,local_214,0);
  dbg_printf(str_r_temp1);
  iVar2 = 0;
  do {
    dbg_printf(&DAT_00039a7c,local_214[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  dbg_printf(&DAT_00039a80);
  FUN_0003976e(0,uVar1,DAT_00039a48);
  FUN_000396da(0,uVar1,0xff,local_214,0);
  dbg_printf(str_r_temp1);
  iVar2 = 0;
  do {
    dbg_printf(&DAT_00039a7c,local_214[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  dbg_printf(&DAT_00039a80);
  return;
}

/* ==========================================================================
 * FUN_0003c2c6   @ 0x0003c2c6   (30 bytes)
 * called by : Default_Profile, FUN_00031808, FUN_00035c9c, SLEEP, _saveC_GM_ProfileMax, exist, ... (+2 more)
 * calls     : FUN_0003c21e, FUN_0003c286
 */

void FUN_0003c2c6(void)

{
  undefined4 uVar1;
  
  FUN_0003c286(1);
  uVar1 = DAT_0003c4f8;
  if (*(char *)(DAT_0003c4f0 + 0x16) != '\x01') {
    uVar1 = DAT_0003c4f4;
  }
  FUN_0003c21e(1,uVar1);
  return;
}

/* ==========================================================================
 * FUN_0003c8b6   @ 0x0003c8b6   (38 bytes)
 * called by : BLE_PAIR, OLED_Init, Success_led_2second, enter_BLE_normal_app_mode, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 * calls     : FUN_0003b54e, FUN_0003c818, FUN_0003c896
 */

void FUN_0003c8b6(void)

{
  int iVar1;
  uint uVar2;
  
  FUN_0003c818();
  FUN_0003b54e();
  iVar1 = DAT_0003cc1c;
  uVar2 = 0;
  do {
    FUN_0003c896(*(undefined1 *)(iVar1 + uVar2));
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x1b);
  FUN_0003c896(0xaf);
  return;
}

/* ==========================================================================
 * FUN_0003cf7c   @ 0x0003cf7c   (60 bytes)
 * called by : BLE_PAIR, Default_Profile, Detect_FULL_IN, FUN_0002b8a2, FUN_0003d2b0, OLED_Init, ... (+8 more)
 * calls     : FUN_0003cdb6, FUN_0003ce00, FUN_0003ce52, FUN_0003ce5c, FUN_0003cf24, delta_none
 */

void FUN_0003cf7c(void)

{
  FUN_0003cf24();
  FUN_0003ce5c();
  FUN_0003ce52();
  FUN_0003ce00();
  FUN_0003cdb6();
  *DAT_0003d194 = 0;
  *DAT_0003d198 = 0;
  *DAT_0003d19c = 0;
  *DAT_0003d1a0 = 0;
  *DAT_0003d1a4 = 0;
  if (*DAT_0003d0b4 != '\0') {
    *DAT_0003d0b4 = '\0';
    delta_none();
  }
  return;
}

/* ==========================================================================
 * FUN_0003e4d2   @ 0x0003e4d2   (24 bytes)
 * called by : FUN_0003e516
 * calls     : FUN_000396da
 */

void FUN_0003e4d2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_000396da(*(undefined1 *)(DAT_0003e794 + 0x14),param_1,param_2,param_3,0);
  return;
}

/* ==========================================================================
 * FUN_0003e4ea   @ 0x0003e4ea   (24 bytes)
 * calls     : FUN_00039708
 */

void FUN_0003e4ea(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00039708(*(undefined1 *)(DAT_0003e794 + 0x14),param_1,param_2,param_3,0);
  return;
}


/*############################################################################
 * USB AND HID  (128 functions)
 *
 *   0x00029464  FUN_00029464  (44 B)
 *   0x0002B18E  FUN_0002b18e  (70 B)
 *   0x0002B382  FUN_0002b382  (42 B)
 *   0x0002B3C2  gpio  (208 B)
 *   0x0002BD62  FUN_0002bd62  (98 B)
 *   0x0002C41A  app_hid_enable_prf  (60 B)
 *   0x0002C456  update  (400 B)
 *   0x0002E958  APP_PARAM_UPDATE_REQ_IND_2  (24 B)
 *   0x00030094  FUN_00030094  (74 B)
 *   0x00031230  FUN_00031230  (20 B)
 *   0x000312DE  FUN_000312de  (86 B)
 *   0x000317C2  FUN_000317c2  (40 B)
 *   0x0003236A  FUN_0003236a  (94 B)
 *   0x000323C8  FUN_000323c8  (38 B)
 *   0x000323EE  FUN_000323ee  (66 B)
 *   0x00032430  FUN_00032430  (116 B)
 *   0x00032614  FUN_00032614  (12 B)
 *   0x0003271A  Set_SIMU_mode_LightUp_Led  (76 B)
 *   0x0003300E  FUN_0003300e  (180 B)
 *   0x0003353C  Set_Report_Data  (192 B)
 *   0x00033A7E  FUN_00033a7e  (172 B)
 *   0x00033D2A  FUN_00033d2a  (1 B)
 *   0x00033D2C  FUN_00033d2c  (64 B)
 *   0x00034044  single_wave  (184 B)
 *   0x000345D2  FUN_000345d2  (58 B)
 *   0x00034E4C  FUN_00034e4c  (2 B)
 *   0x00034EEA  Detect_FULL_IN  (166 B)
 *   0x00034F90  f_usb_isConnected  (1122 B)
 *   0x000358B6  FUN_000358b6  (424 B)
 *   0x00035DBE  fn24main  (106 B)
 *   0x00035EB8  system_mode  (282 B)
 *   0x00036024  FUN_00036024  (32 B)
 *   0x00036044  FUN_00036044  (102 B)
 *   0x000360AA  FUN_000360aa  (226 B)
 *   0x000361A8  FUN_000361a8  (50 B)
 *   0x000361DA  FUN_000361da  (22 B)
 *   0x000361F0  get_scan_Rvalue  (68 B)
 *   0x00036274  TEST_SINGLE_WAVE  (836 B)
 *   0x00036754  TEST_SINGLE_WAVE_2  (422 B)
 *   0x000369A0  FUN_000369a0  (12 B)
 *   0x000369AC  FUN_000369ac  (12 B)
 *   0x000369B8  FUN_000369b8  (32 B)
 *   0x000369D8  FUN_000369d8  (34 B)
 *   0x000369FA  FUN_000369fa  (24 B)
 *   0x00036A12  FUN_00036a12  (66 B)
 *   0x00036AF2  FUN_00036af2  (34 B)
 *   0x00036B36  FUN_00036b36  (174 B)
 *   0x00036BE4  FUN_00036be4  (146 B)
 *   0x00036DD4  FUN_00036dd4  (56 B)
 *   0x00036E0C  FUN_00036e0c  (124 B)
 *   0x00036EEE  FUN_00036eee  (44 B)
 *   0x00036FE6  FUN_00036fe6  (6 B)
 *   0x00037078  FUN_00037078  (78 B)
 *   0x000370C6  FUN_000370c6  (10 B)
 *   0x000370D0  FUN_000370d0  (14 B)
 *   0x000370EC  FUN_000370ec  (14 B)
 *   0x00037104  FUN_00037104  (130 B)
 *   0x00037186  FUN_00037186  (28 B)
 *   0x0003725E  FUN_0003725e  (12 B)
 *   0x000374E2  FUN_000374e2  (38 B)
 *   0x00037508  FUN_00037508  (44 B)
 *   0x00037534  FUN_00037534  (202 B)
 *   0x00037774  FUN_00037774  (38 B)
 *   0x0003781E  FUN_0003781e  (18 B)
 *   0x00037830  FUN_00037830  (20 B)
 *   0x00037844  FUN_00037844  (20 B)
 *   0x00037858  FUN_00037858  (20 B)
 *   0x00037878  FUN_00037878  (66 B)
 *   0x000378BA  FUN_000378ba  (64 B)
 *   0x000378FA  rxcsr2  (360 B)
 *   0x00037A62  pcfg  (38 B)
 *   0x00037AB6  FUN_00037ab6  (16 B)
 *   0x00037AC6  FUN_00037ac6  (52 B)
 *   0x00037AFA  FUN_00037afa  (8 B)
 *   0x00037B0A  FUN_00037b0a  (92 B)
 *   0x00037B66  f_usb_remote_wakeup  (138 B)
 *   0x000380A6  usb_suspend  (116 B)
 *   0x0003811A  usb_suspend_wakeup  (42 B)
 *   0x00038296  FUN_00038296  (20 B)
 *   0x00038350  FUN_00038350  (6 B)
 *   0x00038384  FUN_00038384  (54 B)
 *   0x00038398  FUN_00038398  (40 B)
 *   0x000383C0  HID_RQT_Get_Protocol  (482 B)
 *   0x0003870A  FUN_0003870a  (556 B)
 *   0x00038936  FUN_00038936  (56 B)
 *   0x0003896E  exist  (488 B)
 *   0x00038CB6  test  (26 B)
 *   0x00038CD0  get_usb_insert_status  (78 B)
 *   0x00038D1E  USNDP_status  (134 B)
 *   0x00039AD8  FUN_00039ad8  (24 B)
 *   0x00039C84  FUN_00039c84  (60 B)
 *   0x00039CFC  FUN_00039cfc  (42 B)
 *   0x00039D26  FUN_00039d26  (22 B)
 *   0x00039D3C  FUN_00039d3c  (24 B)
 *   0x00039DFE  FUN_00039dfe  (40 B)
 *   0x00039E26  value_kcal_result  (444 B)
 *   0x00039FE2  cal_data  (496 B)
 *   0x0003A31E  kmod_calibration_2M  (390 B)
 *   0x0003AA42  FUN_0003aa42  (70 B)
 *   0x0003AFA2  FUN_0003afa2  (86 B)
 *   0x0003B528  FUN_0003b528  (16 B)
 *   0x0003B54E  FUN_0003b54e  (12 B)
 *   0x0003C21E  FUN_0003c21e  (104 B)
 *   0x0003C286  FUN_0003c286  (64 B)
 *   0x0003C6A8  FUN_0003c6a8  (12 B)
 *   0x0003C818  FUN_0003c818  (42 B)
 *   0x0003C996  FUN_0003c996  (40 B)
 *   0x0003C9BE  FUN_0003c9be  (52 B)
 *   0x0003C9F2  FUN_0003c9f2  (422 B)
 *   0x0003CB9A  FUN_0003cb9a  (370 B)
 *   0x0003CDB6  FUN_0003cdb6  (74 B)
 *   0x0003CE5C  FUN_0003ce5c  (200 B)
 *   0x0003CF24  FUN_0003cf24  (88 B)
 *   0x0003D082  FUN_0003d082  (42 B)
 *   0x0003D2B0  FUN_0003d2b0  (210 B)
 *   0x0003D55C  FUN_0003d55c  (32 B)
 *   0x0003D63A  FUN_0003d63a  (268 B)
 *   0x0003D7EE  FUN_0003d7ee  (236 B)
 *   0x0003D8DA  FUN_0003d8da  (148 B)
 *   0x0003D96E  FUN_0003d96e  (212 B)
 *   0x0003DA42  FUN_0003da42  (214 B)
 *   0x0003DB3A  FUN_0003db3a  (82 B)
 *   0x0004169A  FUN_0004169a  (254 B)
 *   0x000418AE  hogpd_report_upd_req_handler  (116 B)
 *   0x0004245E  FUN_0004245e  (20 B)
 *   0x00042472  FUN_00042472  (18 B)
 *   0x00042A20  FUN_00042a20  (80 B)
 *   0x00042A74  FUN_00042a74  (92 B)
 ############################################################################*/

/* ==========================================================================
 * FUN_00029464   @ 0x00029464   (44 bytes)
 * called by : gpio
 * calls     : rom_06EF4, rom_06F26
 */

void FUN_00029464(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(DAT_000297c8,7,3,0x3a);
  iVar1 = DAT_0002977c;
  *puVar2 = 0xa4;
  puVar2[1] = *(undefined1 *)(iVar1 + 3);
  *(short *)(puVar2 + 2) = (short)DAT_000297cc;
  puVar2[4] = 0;
  rom_06F26();
  *(undefined1 *)(iVar1 + 4) = 5;
  *(undefined1 *)(iVar1 + 5) = 0xa4;
  return;
}

/* ==========================================================================
 * FUN_0002b18e   @ 0x0002b18e   (70 bytes)
 * called by : FUN_0003cf24, f_usb_isConnected
 * calls     : rom_071EA
 */

undefined4 FUN_0002b18e(void)

{
  char cVar1;
  int iVar2;
  
  if ((*DAT_0002b548 != '\0') && (*DAT_0002b520 != '\0')) {
    return 1;
  }
  cVar1 = *DAT_0002b54c;
  if (cVar1 == '\0') {
    if (*DAT_0002b550 == '\0') {
      return 1;
    }
  }
  else if ((((cVar1 == '\x01') || (cVar1 == '\x02')) && (*DAT_0002b520 == '\0')) &&
          (iVar2 = rom_071EA(3), iVar2 == 3)) {
    return 1;
  }
  return 0;
}

/* ==========================================================================
 * FUN_0002b382   @ 0x0002b382   (42 bytes)
 * called by : FUN_0002b4c8, exist, gpio
 */

void FUN_0002b382(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  *DAT_0002b654 = *DAT_0002b654 & ~((int)DAT_0002b654 >> 0xe);
  iVar1 = DAT_0002b524;
  puVar2 = (undefined4 *)(DAT_0002b524 + 0x80);
  *(undefined4 *)(DAT_0002b524 + 0x8c) = 0;
  *(undefined4 *)(DAT_0002b638 + 0xc) = *(undefined4 *)(iVar1 + 0x8c);
  *puVar2 = 0;
  *(undefined4 *)(iVar1 + 0x84) = 0;
  *(undefined4 *)(iVar1 + 0x94) = 0xffffffff;
  iVar1 = DAT_0002b524;
  *(undefined4 *)(DAT_0002b524 + 0x18) = 0xc;
  *(undefined4 *)(iVar1 + 0x1c) = 0xc;
  return;
}

/* ==========================================================================
 * gpio   @ 0x0002b3c2   (208 bytes)
 * calls     : FUN_00029464, FUN_0002b382, FUN_0002b3ac, FUN_000317c2, FUN_00033cfe, FUN_0003c6a8, ... (+6 more)
 * string    : "gpio int1\r\n"
 * string    : "adv start =%d\r\n"
 */

void gpio(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  dbg_printf(str_gpio_int1);
  *DAT_0002b544 = 1;
  pcVar4 = DAT_0002b590;
  if (*DAT_0002b590 != '\0') {
    iVar6 = get_usb_insert_status();
    pcVar1 = DAT_0002b548;
    *DAT_0002b548 = iVar6 != 0;
    if (*pcVar1 != '\0') {
      *DAT_0002b678 = 0;
      *pcVar4 = '\0';
      OLED_Init();
    }
  }
  *DAT_0002b67c = *(undefined4 *)(DAT_0002b524 + 0x94);
  *DAT_0002b530 = 0xf;
  if (((*DAT_0002b54c == '\x01') || (*DAT_0002b54c == '\x02')) && (*DAT_0002b520 == '\0')) {
    FUN_0002b382();
    FUN_00033cfe();
    iVar6 = DAT_0002b598;
    puVar3 = DAT_0002b588;
    *(undefined1 *)(DAT_0002b598 + 0xb) = 1;
    *puVar3 = 0;
    *DAT_0002b680 = 0;
    FUN_0003c6a8();
    FUN_0002b3ac();
    iVar5 = DAT_0002b59c;
    if ((*(char *)(DAT_0002b59c + 4) == '\x04') &&
       (iVar7 = rom_071EA(3), puVar3 = DAT_0002b684, iVar7 == 2)) {
      *(byte *)(iVar6 + 4) = *(byte *)(iVar6 + 4) | 2;
      *puVar3 = 4;
      FUN_000317c2(2);
      dbg_printf(str_adv_start_d,*(undefined1 *)(iVar5 + 4));
      FUN_00029464();
    }
    uVar2 = DAT_0002b564;
    iVar6 = rom_07434(DAT_0002b564,3);
    if (iVar6 == 0) {
      rom_06F58(uVar2,3);
      return;
    }
  }
  else {
    *DAT_0002b570 = 0;
    FUN_0002b382();
  }
  return;
}

/* ==========================================================================
 * FUN_0002bd62   @ 0x0002bd62   (98 bytes)
 * called by : FUN_0002f31c
 * calls     : rom_071EA, rom_24FEC, update
 */

void FUN_0002bd62(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = DAT_0002be6c;
  iVar1 = DAT_0002be68;
  if ((((*(char *)(DAT_0002be68 + 3) != '\0') && (*DAT_0002be6c == '\0')) &&
      (iVar3 = rom_071EA(3), iVar3 == 3)) && (*(char *)(DAT_0002be70 + 4) == '\x03')) {
    *pcVar2 = '\x01';
    iVar3 = DAT_0002be74;
    update((uint)*(byte *)(iVar1 + 2) * 8 + DAT_0002be74,
           *(undefined1 *)(iVar1 + 0x18 + (uint)*(byte *)(iVar1 + 2)));
    rom_24FEC((uint)*(byte *)(iVar1 + 2) * 8 + iVar3,8);
    *(byte *)(iVar1 + 2) = *(char *)(iVar1 + 2) + 1U & 7;
    *(char *)(iVar1 + 3) = *(char *)(iVar1 + 3) + -1;
    if (*(char *)(iVar1 + 10) != '\0') {
      *(char *)(iVar1 + 10) = *(char *)(iVar1 + 10) + -1;
    }
  }
  return;
}

/* ==========================================================================
 * app_hid_enable_prf   @ 0x0002c41a   (60 bytes)
 * called by : ble_update_param_failed_cnt
 * calls     : FUN_0003ee6e, dbg_printf, rom_06EF4, rom_06F26
 * string    : "app_hid_enable_prf"
 * string    : "%s conidx =d%\r\n"
 */

void app_hid_enable_prf(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  iVar2 = DAT_0002c784;
  puVar1 = PTR_DAT_0002c77c;
  *PTR_DAT_0002c77c = (char)param_1;
  dbg_printf(str_s_conidx_d,iVar2 + 0x11,param_1);
  uVar3 = FUN_0003ee6e(0x26);
  puVar4 = (undefined1 *)rom_06EF4(&DAT_00002600,uVar3,3,6);
  *puVar4 = (char)param_1;
  puVar1[4] = 3;
  *(short *)(puVar4 + param_1 * 2 + 2) = (short)DAT_0002c7a0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * update   @ 0x0002c456   (400 bytes)
 * called by : FUN_0002bd62
 * calls     : FUN_0003ee6e, appm_update_param, dbg_printf, rom_06EF4, rom_06F26, rom_06F80, ... (+1 more)
 * string    : "update para  APP_HID_WAIT_REP---------------\r\n"
 * string    : "hid :ke_msg_free\r\n"
 * string    : "kb len= %d\r\n"
 * string    : "media len= %d\r\n"
 * string    : "user len= %d\r\n"
 * string    : "power len= %d\r\n"
 * string    : "idle len= %d\r\n"
 */

void update(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int local_20;
  int local_1c;
  undefined4 uStack_18;
  
  puVar4 = PTR_DAT_0002c77c;
  cVar1 = PTR_DAT_0002c77c[4];
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  if (cVar1 == '\x01') {
    dbg_printf(str_idle_len_d);
    return;
  }
  if (cVar1 != '\x03') {
    if (cVar1 == '\x04') {
      dbg_printf(str_update_para_APP_HID_WAIT_REP);
      local_20 = 0x80008;
      local_1c = 0xc80019;
      appm_update_param(&local_20);
      puVar4[4] = 3;
    }
    return;
  }
  uVar5 = FUN_0003ee6e(0x26);
  puVar6 = (undefined1 *)rom_06EF4(DAT_0002c7d4,uVar5,3,0x24);
  local_20 = 0;
  local_1c = 0;
  if (((param_2 == 5) || (param_2 == 6)) || (param_2 == 7)) {
    local_20 = *param_1;
    local_1c = param_1[1];
    *puVar6 = *puVar4;
    puVar6[2] = *puVar4;
    puVar6[3] = 0;
    puVar6[6] = 2;
    *(short *)(puVar6 + 4) = (short)param_2;
  }
  else if (param_2 == 8) {
    dbg_printf(str_kb_len_d,8);
    local_20 = *param_1;
    local_1c = param_1[1];
    *puVar6 = *puVar4;
    puVar6[2] = *puVar4;
    puVar6[3] = 0;
    puVar6[6] = 0;
    param_2 = 8;
    *(undefined2 *)(puVar6 + 4) = 8;
  }
  else {
    if (param_2 == 2) {
      dbg_printf(str_media_len_d,2);
      iVar3 = *param_1;
      uVar2 = *(undefined1 *)((int)param_1 + 1);
      local_20 = CONCAT22(local_20._2_2_,(short)*param_1);
      *puVar6 = *puVar4;
      puVar6[2] = *puVar4;
      puVar6[3] = 0;
      puVar6[6] = 6;
      *(undefined2 *)(puVar6 + 4) = 2;
      puVar6[7] = (char)iVar3;
      puVar6[8] = uVar2;
      goto LAB_0002c5d8;
    }
    if (param_2 != 4) {
      if (param_2 != 1) {
        dbg_printf(str_hid_ke_msg_free);
        rom_06F80(puVar6 + -0xc);
        return;
      }
      dbg_printf(str_power_len_d,1);
      iVar3 = *param_1;
      local_20 = CONCAT31(local_20._1_3_,(char)iVar3);
      *puVar6 = *puVar4;
      puVar6[2] = *puVar4;
      puVar6[3] = 0;
      puVar6[6] = 8;
      *(undefined2 *)(puVar6 + 4) = 1;
      puVar6[7] = (char)iVar3;
      goto LAB_0002c5d8;
    }
    dbg_printf(str_user_len_d,4);
    local_20 = *param_1;
    *puVar6 = *puVar4;
    puVar6[2] = *puVar4;
    puVar6[3] = 0;
    puVar6[6] = 4;
    param_2 = 4;
    *(undefined2 *)(puVar6 + 4) = 4;
  }
  rom_24F9C(puVar6 + 7,&local_20,param_2);
LAB_0002c5d8:
  rom_06F26(puVar6);
  return;
}

/* ==========================================================================
 * APP_PARAM_UPDATE_REQ_IND_2   @ 0x0002e958   (24 bytes)
 * calls     : dbg_printf, rom_07342
 * string    : "APP_PARAM_UPDATE_REQ_IND--9 hid not ready,   app_update_conn_param_.............%d,%d \r\n"
 */

undefined4
APP_PARAM_UPDATE_REQ_IND_2
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  dbg_printf(PTR_str_APP_PARAM_UPDATE_REQ_IND_9_hid_not_ready_app_0002ed18,*param_4,*param_1);
  rom_07342(PTR_DAT_0002ed1c,3,100);
  return 0;
}

/* ==========================================================================
 * FUN_00030094   @ 0x00030094   (74 bytes)
 * called by : system_mode
 * calls     : FUN_000369a0, FUN_000369d8, rom_25078
 */

undefined8 FUN_00030094(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar1 = PTR_DAT_000301f0;
  uVar2 = (uint)(byte)*PTR_DAT_000301f0;
  if ((*DAT_00030238 == '\0') && (4 < uVar2)) {
    FUN_000369a0();
    puVar4 = PTR_DAT_000301f8;
    *(undefined4 *)(PTR_DAT_000301f8 + -0x28) = 0xa0;
    *(undefined4 *)(puVar4 + -0x28) = 0x80;
    FUN_000369d8();
    puVar4 = PTR_DAT_00030174;
    iVar3 = 0;
    *PTR_DAT_00030174 = 0;
    *puVar1 = 0;
  }
  else {
    rom_25078();
    iVar3 = uVar2 - (int)puVar1;
    puVar4 = (undefined *)0x1e;
  }
  return CONCAT44(puVar4,iVar3);
}

/* ==========================================================================
 * FUN_00031230   @ 0x00031230   (20 bytes)
 * called by : FUN_00031334, FUN_00031406, exist
 */

void FUN_00031230(void)

{
  *DAT_0003156c = 0;
  *DAT_00031570 = 0;
  *DAT_00031574 = 0;
  *DAT_00031578 = 0;
  return;
}

/* ==========================================================================
 * FUN_000312de   @ 0x000312de   (86 bytes)
 * called by : FUN_00031334, FUN_00031406, exist, f_usb_isConnected
 * calls     : rom_24FEC
 */

void FUN_000312de(void)

{
  *DAT_000315b0 = 0;
  *DAT_000315b4 = 0;
  *DAT_000315b8 = 0;
  *DAT_000315bc = 0;
  *DAT_000315c0 = 0;
  rom_24FEC(DAT_000315c4,0xc);
  rom_24FEC(DAT_000315c8,0x20);
  rom_24FEC(DAT_000315cc,0x40);
  rom_24FEC(DAT_000315d0,8);
  rom_24FEC(DAT_000315d4,0x10);
  rom_24FEC(DAT_000315d8,5);
  rom_24FEC(DAT_000315dc,4);
  *DAT_000315e0 = 0;
  return;
}

/* ==========================================================================
 * FUN_000317c2   @ 0x000317c2   (40 bytes)
 * called by : FUN_00034414, FUN_000345d2, FUN_00035cd2, FUN_00039dfe, FUN_0003c818, LightUp_Mode_Led, ... (+13 more)
 * calls     : FUN_0003b54e
 */

void FUN_000317c2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_00031804;
  if (*DAT_00031800 == '\x05') {
    param_1 = param_1 << 2;
  }
  for (iVar3 = 0; iVar3 < param_1; iVar3 = iVar3 + 1) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
    FUN_0003b54e();
  }
  return;
}

/* ==========================================================================
 * FUN_0003236a   @ 0x0003236a   (94 bytes)
 * called by : system_mode
 * calls     : FUN_000319c0, FUN_00031b3e, FUN_000332be
 */

void FUN_0003236a(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = DAT_000325a8;
  pcVar1 = DAT_000325a4;
  if (*DAT_00032598 == '\0') {
    if (*DAT_000325a0 != '\0') {
      return;
    }
  }
  else if (*DAT_0003259c == '\0') {
    return;
  }
  uVar4 = 0;
  do {
    if ((int)((uint)*(byte *)(iVar2 + uVar4) << 0x1e) < 0) {
      if ((*(byte *)(iVar2 + uVar4) & 1) == 0) {
        FUN_000319c0(uVar4);
      }
      else if ((*pcVar1 == '\x02') || (iVar3 = FUN_000332be(), iVar3 != 0)) {
        FUN_00031b3e(uVar4);
      }
      else {
        *(byte *)(iVar2 + uVar4) = *(byte *)(iVar2 + uVar4) & 0xfd;
      }
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0xc);
  return;
}

/* ==========================================================================
 * FUN_000323c8   @ 0x000323c8   (38 bytes)
 * called by : FUN_000323ee
 */

undefined4 FUN_000323c8(uint param_1)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    if (*(byte *)(DAT_000325ac + uVar1) == 0) {
      *(char *)(DAT_000325ac + uVar1) = (char)param_1;
      return 1;
    }
  } while ((*(byte *)(DAT_000325ac + uVar1) != param_1) && (uVar1 = uVar1 + 1 & 0xff, uVar1 < 7));
  return 0;
}

/* ==========================================================================
 * FUN_000323ee   @ 0x000323ee   (66 bytes)
 * called by : system_mode
 * calls     : FUN_000323c8
 */

void FUN_000323ee(void)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  pcVar2 = DAT_000325b4;
  pcVar1 = DAT_000325b0;
  cVar3 = *DAT_000325b0;
  if (cVar3 != '\0') {
    if (cVar3 == '\x01') {
      *DAT_000325ac = *DAT_000325ac | *DAT_000325bc;
      *pcVar2 = '\x01';
      cVar3 = '\x02';
    }
    else {
      if (cVar3 != '\x02') {
        return;
      }
      if (*DAT_000325b4 != '\0') {
        return;
      }
      iVar4 = FUN_000323c8(*DAT_000325b8);
      if (iVar4 != 0) {
        *pcVar2 = '\x01';
      }
      cVar3 = '\0';
    }
    *pcVar1 = cVar3;
  }
  return;
}

/* ==========================================================================
 * FUN_00032430   @ 0x00032430   (116 bytes)
 * called by : system_mode
 */

void FUN_00032430(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  char *pcVar5;
  byte *pbVar6;
  char cVar7;
  
  pcVar5 = DAT_000325c0;
  cVar1 = *DAT_000325c0;
  if (cVar1 != '\0') {
    *DAT_000325c4 = 0xf;
    pbVar6 = DAT_000325cc;
    cVar2 = *DAT_000325c8;
    cVar3 = *DAT_000325d0;
    bVar4 = *DAT_000325cc;
    cVar7 = '\x01';
    if (cVar1 == '\x01') {
      if (cVar3 == '\0') {
        *DAT_000325d0 = cVar2;
        *pbVar6 = bVar4 | 1;
        *PTR_DAT_00032590 = 1;
        cVar7 = '\x02';
LAB_000324a0:
        *pcVar5 = cVar7;
        return;
      }
    }
    else if (cVar1 == '\x02') {
      if (cVar3 == '\0') {
        *DAT_000325d0 = cVar2;
        *pbVar6 = bVar4 & 0xfe;
        *PTR_DAT_00032590 = 1;
        cVar1 = *DAT_000325d4;
        if ((cVar1 == '\0') || (*DAT_000325d4 = cVar1 + -1, cVar1 == '\x01')) {
          cVar7 = '\0';
        }
        goto LAB_000324a0;
      }
    }
    else if ((cVar1 == '\x05') && (cVar3 == '\0')) {
      *DAT_000325d0 = cVar2;
      *pbVar6 = bVar4 ^ 1;
      *PTR_DAT_00032590 = 1;
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00032614   @ 0x00032614   (12 bytes)
 * called by : Set_SIMU_mode_LightUp_Led
 */

void FUN_00032614(void)

{
  int iVar1;
  
  iVar1 = DAT_000329e8;
  *(undefined4 *)(DAT_000329e8 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return;
}

/* ==========================================================================
 * Set_SIMU_mode_LightUp_Led   @ 0x0003271a   (76 bytes)
 * called by : Disconnected, app_mutli_link_change
 * calls     : FUN_00032614, FUN_00032658, dbg_printf
 * string    : "usb to 24 mode \r\n"
 * string    : "Set_SIMU_mode_LightUp_Led"
 * string    : "%s, Simu_RF_MODE=%x,Mode_Indicator_BIT=%x\r\n"
 */

void Set_SIMU_mode_LightUp_Led(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  undefined1 uVar3;
  
  puVar1 = DAT_000329e4;
  *DAT_000329e4 = 0;
  pcVar2 = DAT_000329f4;
  if (*DAT_000329ec == '\0') {
    uVar3 = 2;
    if (*DAT_000329f4 == '\x01') {
      *DAT_000329f4 = '\x02';
      uVar3 = 4;
    }
    else {
      if (*DAT_000329f4 != '\x02') goto LAB_00032752;
      *DAT_000329f4 = '\x01';
    }
    *puVar1 = uVar3;
  }
  else {
    dbg_printf(str_usb_to_24_mode);
    FUN_00032614();
  }
LAB_00032752:
  FUN_00032658();
  dbg_printf(str_s_Simu_RF_MODE_x_Mode_Indicator_BIT_x,DAT_000329f8 + 0x16,*pcVar2,*puVar1);
  return;
}

/* ==========================================================================
 * FUN_0003300e   @ 0x0003300e   (180 bytes)
 * called by : system_mode
 * calls     : rom_071EA, rom_25078
 */

void FUN_0003300e(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_r3;
  
  pcVar2 = DAT_00033368;
  if ((((*DAT_00033368 == '\0') || (*DAT_0003336c == '\0')) ||
      ((((cVar1 = *DAT_0003335c, cVar1 == '\0' && (*DAT_00033370 == '\0')) &&
        ((1 < *DAT_00033374 || (*DAT_00033378 != '\0')))) ||
       ((*DAT_0003337c != '\0' &&
        ((*DAT_00033360 != '\0' &&
         ((((*DAT_00033380 != '\0' || (*DAT_00033384 != '\0')) || (*DAT_00033388 != '\0')) ||
          ((*DAT_0003338c != '\0' || (*DAT_00033390 != '\0')))))))))))) ||
     (((cVar1 == '\x01' || (cVar1 == '\x02')) &&
      (((*DAT_00033360 == '\0' && (iVar3 = rom_071EA(3), iVar3 == 3)) &&
       (*DAT_00033394 != '\0' || *DAT_00033398 != '\0')))))) {
    return;
  }
  if (*DAT_00033364 != 0) {
    *DAT_00033364 = *DAT_00033364 + -1;
  }
  uVar4 = rom_25078(PTR_DAT_000333a0,DAT_0003339c,*pcVar2,*pcVar2,in_r3);
  *DAT_00032b04 = 400;
  if ((uVar4 & 1) == 0) {
    FUN_00032620();
    FUN_0003ce52();
    return;
  }
  FUN_00032658();
  if (*DAT_00032b08 == '\x02') {
    ReLinking();
    return;
  }
  Pairing();
  return;
}

/* ==========================================================================
 * Set_Report_Data   @ 0x0003353c   (192 bytes)
 * called by : FUN_00033a7e, RPT_STEP
 * calls     : FLASH_RD_Profile, FUN_00033d2a, OLED_Init, dbg_printf, dbg_printf_2, rom_24FEC, ... (+1 more)
 * string    : "Set_Report_Data"
 * string    : "N0N0 report_id =%x\r\n"
 * string    : "macro report_id =%x,macro_index=%x\r\n"
 * string    : "Profile report_id =%x,Update_Profile=%x,%x\r\n"
 */

void Set_Report_Data(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined8 uVar7;
  
  OLED_Init();
  iVar2 = DAT_000337dc;
  dbg_printf_2(str_Set_Report_Data,*(undefined4 *)(DAT_000337dc + 4),0x20);
  pcVar3 = DAT_00033888;
  pcVar4 = DAT_00033810;
  cVar1 = *(char *)(iVar2 + 2);
  if (cVar1 == '\t') goto LAB_0003359a;
  if ((((cVar1 == '\x06') || (cVar1 == '\x04')) || (cVar1 == '\x05')) || (cVar1 == '\b')) {
    pcVar5 = *(char **)(iVar2 + 4);
    *DAT_00033810 = *pcVar5 + -1;
    *(char **)(iVar2 + 4) = pcVar5 + 1;
    dbg_printf(str_Profile_report_id_x_Update_Profile_x_x);
    if (*(char *)(iVar2 + 2) != '\x06') {
      if (*(char *)(DAT_000337e4 + 0xc) != *pcVar4) {
        FLASH_RD_Profile();
      }
    }
  }
  else {
    dbg_printf(str_N0N0_report_id_x);
  }
  do {
    rom_24FEC(DAT_000337e0,0xff);
    iVar6 = 0x3358b;
    uVar7 = rom_25078();
    (*(code *)(iVar6 + 0x7a0))((int)uVar7,(int)((ulonglong)uVar7 >> 0x20) + -0xd);
    func_0xffb2af7e();
LAB_0003359a:
    pcVar4 = *(char **)(iVar2 + 4);
    *DAT_000338a8 = *pcVar4 + -1;
    *(char **)(iVar2 + 4) = pcVar4 + 1;
    if ((*pcVar3 == '\0') || ((*DAT_000338ac != '\0' && (*DAT_000338b0 != '\0')))) {
      *(char **)(iVar2 + 4) = pcVar4 + 2;
    }
    dbg_printf(str_macro_report_id_x_macro_index_x);
  } while( true );
}

/* ==========================================================================
 * FUN_00033a7e   @ 0x00033a7e   (172 bytes)
 * called by : system_mode
 * calls     : Set_Report_Data, app_usb_upgrade_start, rom_25078
 */

void FUN_00033a7e(void)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 extraout_r1;
  uint uVar6;
  undefined4 in_r3;
  int iVar7;
  
  puVar2 = DAT_00033c40;
  if (*DAT_00033c3c != '\0') {
    uVar6 = (uint)*DAT_00033c44;
    iVar5 = rom_25078(*DAT_00033c48,*(undefined1 *)(DAT_00033c4c + 2),uVar6,*DAT_00033c40,in_r3);
    *(undefined1 **)(iVar5 + 0x34) = puVar2;
    DAT_00000006 = extraout_r1;
    if (*DAT_00033c50 != '\0') {
      *DAT_00033c50 = '\0';
      pcVar3 = DAT_00033c54;
      iVar5 = DAT_00033c4c;
      if (*(char *)(DAT_00033c4c + 9) != '\x10') {
        iVar7 = DAT_00033c4c + 0xb;
        if (*(char *)(DAT_00033c4c + 1) == '\x02') {
          *DAT_00033c5c = 0;
          *(undefined1 *)(iVar5 + 9) = extraout_r1;
          *(undefined1 *)(iVar5 + 10) = *DAT_00033c60;
          *(char *)(iVar5 + 0xb) = (char)uVar6;
          if (uVar6 != 0) {
            *(int *)(iVar5 + 4) = DAT_00033c4c + 0xc;
            *puVar2 = 1;
            return;
          }
          *DAT_00033c64 = 0;
          *DAT_00033c68 = 0;
          *(int *)(iVar5 + 4) = iVar7;
          uVar4 = 3;
        }
        else {
          if (*(char *)(DAT_00033c4c + 1) != '\x01') {
            return;
          }
          *(char *)(DAT_00033c4c + 2) = *(char *)(DAT_00033c4c + 9);
          *(int *)(iVar5 + 4) = iVar7;
          Set_Report_Data();
          uVar4 = 5;
        }
        *puVar2 = uVar4;
        return;
      }
      if (*(char *)(DAT_00033c4c + 0xb) == -0x6a) {
        cVar1 = *DAT_00033c54;
        *DAT_00033c54 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\t') {
          *pcVar3 = '\x01';
        }
        *DAT_00033c58 = 1;
        return;
      }
      app_usb_upgrade_start();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00033d2a   @ 0x00033d2a   (1 bytes)
 * called by : Set_Report_Data
 */

void FUN_00033d2a(void)

{
  return;
}

/* ==========================================================================
 * FUN_00033d2c   @ 0x00033d2c   (64 bytes)
 * called by : FUN_000342b4, FUN_00034352, FUN_00034426, f_usb_isConnected
 * calls     : FUN_00031784, FUN_0003aa1a, FUN_0003aa42
 */

undefined1 FUN_00033d2c(byte param_1)

{
  int iVar1;
  
  iVar1 = DAT_00033f70;
  *(undefined4 *)(DAT_00033f70 + 0x1c) = 0;
  *PTR_DAT_00033f74 = param_1 & 0x7f;
  FUN_0003aa1a(PTR_DAT_00033f74,1);
  FUN_00031784(3);
  FUN_0003aa42(PTR_DAT_00033f74 + 0xc,1);
  FUN_00031784(1);
  *(undefined4 *)(iVar1 + 0x1c) = 2;
  FUN_00031784(5);
  return PTR_DAT_00033f74[0xc];
}

/* ==========================================================================
 * single_wave   @ 0x00034044   (184 bytes)
 * called by : system_mode
 * calls     : FUN_000361a8, FUN_000369a0, FUN_000369ac, FUN_000369d8, FUN_00036eee, dbg_printf, ... (+1 more)
 * string    : "single_wave 123============== %x,%x,%x,%x,%x,\r\n"
 */

void single_wave(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 uVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  
  puVar7 = DAT_00034224;
  pbVar2 = DAT_00034220;
  bVar1 = *DAT_00034220;
  if (((bVar1 != 0) && (*DAT_00034228 != '\0')) && (*DAT_00034228 = '\0', *DAT_0003422c == 4)) {
    *pbVar2 = bVar1 + 1;
    if (bVar1 == 8) {
      *pbVar2 = 1;
    }
    *puVar7 = 1;
  }
  iVar3 = DAT_00034230;
  uVar6 = (uint)*DAT_00034220;
  uVar8 = rom_25078();
  pcVar5 = (char *)((int)uVar8 + -0x3e);
  puVar7 = (undefined1 *)(iVar3 * 2);
  if (*pcVar5 == '\0') {
    return;
  }
  *pcVar5 = (char)*(undefined4 *)((int)((ulonglong)uVar8 >> 0x20) + 0x40);
  pbVar2 = DAT_00034220;
  *puVar7 = 2;
  if (uVar6 == 2) {
    uVar4 = 0x27;
  }
  else {
    if (uVar6 != 3) goto LAB_000340b2;
    uVar4 = 0x4f;
  }
  *puVar7 = uVar4;
LAB_000340b2:
  FUN_00036eee(8);
  FUN_000369ac();
  FUN_000369a0();
  *(int *)(iVar3 + 0x18) = (int)uVar8 << 0x18;
  *(undefined4 *)(iVar3 + 0x18) = 0x80;
  *(undefined4 *)(DAT_00034230 + -0xb0) = 3;
  FUN_00036eee(8);
  FUN_000369d8();
  FUN_000361a8(*puVar7);
  dbg_printf(str_single_wave_123_x_x_x_x_x,*DAT_00034240,*pbVar2,*puVar7,*DAT_0003423c,*DAT_00034238
            );
  return;
}

/* ==========================================================================
 * FUN_000345d2   @ 0x000345d2   (58 bytes)
 * called by : f_usb_isConnected, sensor_init
 * calls     : FUN_000317c2, FUN_000342b4, FUN_00034352, FUN_00034408, FUN_00034538
 */

void FUN_000345d2(void)

{
  int iVar1;
  undefined1 uVar2;
  
  FUN_000317c2(0x3c);
  iVar1 = DAT_00034618;
  *(undefined4 *)(DAT_00034618 + 0x1c) = 2;
  FUN_000317c2(1);
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  FUN_00034408();
  FUN_000317c2(5);
  FUN_00034352();
  uVar2 = 0;
  if (*DAT_00034638 != '\0') {
    uVar2 = 3;
  }
  FUN_000342b4(uVar2);
  FUN_00034538();
  return;
}

/* ==========================================================================
 * FUN_00034e4c   @ 0x00034e4c   (2 bytes)
 * called by : system_mode
 */

void FUN_00034e4c(void)

{
  return;
}

/* ==========================================================================
 * Detect_FULL_IN   @ 0x00034eea   (166 bytes)
 * called by : system_mode
 * calls     : Charging, FUN_0003cf7c, OLED_Init, dbg_printf
 * string    : "Detect_FULL_IN ==FULL !\r\n"
 * string    : "Detect_FULL_IN ==CHANRGing !\r\n"
 */

void Detect_FULL_IN(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  
  iVar2 = DAT_0003502c;
  if (((*DAT_00035024 != '\0') &&
      (*(undefined4 *)(DAT_0003502c + 0x30) = 0x2c, (*(uint *)(iVar2 + 0x30) & 1) != 0)) &&
     (*(char *)(DAT_00035190 + 2) == '\0')) {
    OLED_Init();
    pcVar5 = DAT_00035198;
    pcVar4 = DAT_00035194;
    pcVar3 = DAT_00035070;
    if (((*(uint *)(iVar2 + 0x14) & 1) == 0) || (*DAT_00035194 != '\0')) {
      if (((*(uint *)(iVar2 + 0x14) & 1) == 0) && (*DAT_00035194 == '\x01')) {
        cVar1 = *DAT_00035198;
        *DAT_00035198 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          *pcVar5 = '\x0f';
          *pcVar4 = '\0';
          FUN_0003cf7c();
          dbg_printf(str_Detect_FULL_IN_CHANRGing);
          *DAT_000351dc = 400;
          *DAT_000351e0 = 0xf;
          OLED_Init();
          return;
        }
      }
      else {
        *DAT_00035198 = '\x0f';
      }
      return;
    }
    cVar1 = *DAT_00035198;
    *DAT_00035198 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      *pcVar4 = '\x01';
      *pcVar5 = '\x0f';
      if (*pcVar3 != '\x02') {
        Charging();
        puVar6 = DAT_0003519c;
        *pcVar3 = '\x02';
        *puVar6 = 0x14;
        dbg_printf(str_Detect_FULL_IN_FULL);
      }
    }
  }
  return;
}

/* ==========================================================================
 * f_usb_isConnected   @ 0x00034f90   (1122 bytes)
 * called by : system_mode
 * calls     : CHRG, FUN_000295aa, FUN_0002b18e, FUN_000312aa, FUN_000312de, FUN_00031784, ... (+26 more)
 * string    : "INSERT USNDP_status------charging   %x\r\n"
 * string    : "INSERT USNDP_status------usb insert   %x\r\n"
 * string    : "usb_chk ----IN-------------- %x,%x,%x,%x\r\n"
 * string    : "Disconnected by mouse...\r\n"
 * string    : "usb_chk ----PULL OUT-------------- %x,%x,%x,%x\r\n"
 * string    : "f_usb_isConnected=1  %x,%x,%x,%x\r\n"
 * string    : "f_usb_isConnected fail  %x,%x,%x,%x\r\n"
 */

void f_usb_isConnected(void)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  short *psVar4;
  byte *pbVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  short sVar11;
  byte bVar12;
  
  iVar8 = DAT_00035604;
  psVar4 = DAT_000351e4;
  pcVar3 = DAT_0003514c;
  if (*(char *)(DAT_00035190 + 2) == '\0') {
    *(undefined4 *)(DAT_00035604 + 0x30) = 0x2c;
    FUN_00031784(3);
    pcVar10 = DAT_0003560c;
    uVar9 = *(uint *)(iVar8 + 0x30) & 1;
    if (uVar9 == *DAT_00035608) {
      if ((((*(uint *)(iVar8 + 0x30) & 1) == 0) || (*psVar4 != 0)) || (*pcVar3 != '\0')) {
        *DAT_0003560c = '\n';
      }
      else {
        iVar7 = USNDP_status();
        pcVar10 = DAT_00035610;
        *DAT_00035610 = iVar7 != 0;
        if (*pcVar10 == '\0') goto LAB_00035296;
      }
    }
    else {
      cVar1 = *DAT_0003560c;
      *DAT_0003560c = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        *DAT_00035608 = (byte)uVar9;
        *pcVar10 = '\n';
LAB_00035296:
        pbVar5 = DAT_00035608;
        if (*DAT_00035608 == 0) {
          dbg_printf(str_usb_chk_PULL_OUT_x_x_x_x,*DAT_00035678,*(uint *)(iVar8 + 0x30) & 1,
                     *DAT_00035608,*DAT_00035610);
          FUN_0003afa2(1);
          if (*pcVar3 != '\0') {
            FUN_0003b130();
          }
          *DAT_00035610 = '\0';
          *pbVar5 = 0;
          bVar12 = 0;
          *DAT_00035640 = 0;
          *DAT_0003570c = 0;
          do {
            *DAT_00035710 = 0;
            set_Update_OLED();
            FUN_000317c2(10);
            bVar12 = bVar12 + 1;
          } while (bVar12 < 0x1e);
          *DAT_00035714 = 400;
          *DAT_00035718 = '\0';
          *DAT_0003571c = 1;
          FUN_0003ce00();
          *DAT_00035720 = 0;
        }
        else {
          iVar7 = USNDP_status();
          pcVar10 = DAT_00035610;
          *DAT_00035610 = iVar7 != 0;
          cVar1 = *pcVar10;
          if (*pcVar10 == '\0') {
            dbg_printf(str_INSERT_USNDP_status_usb_insert_x,cVar1);
            FUN_00032892();
            ble_alert_led_stop();
            FUN_000312aa();
            *DAT_00035670 = 0;
            pcVar10 = DAT_00035678;
            dbg_printf(str_usb_chk_IN_x_x_x_x,*DAT_00035678,*(uint *)(iVar8 + 0x30) & 1,
                       *DAT_00035608,*DAT_00035674);
            if (*pcVar10 == '\0') {
              *DAT_000356a8 = 0;
              *DAT_000356ac = 0;
              *DAT_000356b0 = 0;
            }
            else {
              app_user_ke_timer_stop();
              iVar8 = rom_071EA(3);
              if (iVar8 == 3) {
                dbg_printf(DAT_000356b4);
                *DAT_000356b8 = *DAT_000356b8 | 0x100;
                FUN_000295aa();
                FUN_000317c2(0x32);
              }
            }
            *psVar4 = (short)DAT_000356bc;
          }
          else {
            dbg_printf(str_INSERT_USNDP_status_charging_x,cVar1);
            *psVar4 = 1000;
            *DAT_00035640 = 0;
          }
          FUN_000317c2(500);
          FUN_000371c2(DAT_000356c4,DAT_000356c0);
          FUN_000377fe(1,DAT_000356c8);
          FUN_000377fe(2,DAT_000356cc);
          FUN_000377fe(3,DAT_000356d0);
          FUN_000377fe(4,DAT_000356d4);
        }
      }
    }
  }
  else {
    *DAT_000351e8 = 10;
  }
  *DAT_000351ec = 1;
  if (*DAT_000351f0 != '\0') {
    *DAT_000351f0 = *DAT_000351f0 + -1;
  }
  if (*DAT_000355f4 != '\0') {
    *DAT_000355f4 = *DAT_000355f4 + -1;
  }
  if (*DAT_000355f8 != '\0') {
    *DAT_000355f8 = *DAT_000355f8 + -1;
  }
  if (*DAT_000355fc != '\0') {
    *DAT_000355fc = *DAT_000355fc + -1;
  }
  cVar1 = *DAT_00035600;
  if ((cVar1 != '\0') && (*DAT_00035600 = cVar1 + -1, cVar1 == '\x01')) {
    if ((*DAT_00035724 != '\0') && (*DAT_00035728 != '\0')) {
      iVar8 = FUN_00033d2c(0x5b);
      *DAT_00035600 = (char)iVar8;
      if (iVar8 != 0x40) {
        FUN_000345d2();
      }
    }
    *DAT_00035600 = '\x1e';
  }
  if (*DAT_0003572c != 0) {
    *DAT_0003572c = *DAT_0003572c + -1;
  }
  if (1 < *DAT_00035730) {
    *DAT_00035730 = *DAT_00035730 - 1;
  }
  if (*DAT_00035734 != '\0') {
    *DAT_00035734 = *DAT_00035734 + -1;
  }
  if (*DAT_00035738 != '\0') {
    *DAT_00035738 = *DAT_00035738 + -1;
  }
  cVar1 = *DAT_0003573c;
  if ((cVar1 != '\0') && (*DAT_0003573c = cVar1 + -1, cVar1 == '\x01')) {
    FUN_0003d2b0();
  }
  if (*DAT_00035740 != '\0') {
    *DAT_00035740 = *DAT_00035740 + -1;
  }
  if (*DAT_00035744 != '\0') {
    *DAT_00035744 = *DAT_00035744 + -1;
  }
  if (*DAT_00035748 != '\0') {
    *DAT_00035748 = *DAT_00035748 + -1;
  }
  if (*DAT_0003574c != '\0') {
    *DAT_0003574c = *DAT_0003574c + -1;
  }
  sVar11 = *psVar4;
  if (sVar11 != 0) {
    *psVar4 = sVar11 + -1;
    if (*pcVar3 == '\0') {
      if (sVar11 != 1) goto LAB_00035534;
      uVar2 = *DAT_00035674;
      uVar9 = *(uint *)(DAT_00035604 + 0x30);
      bVar12 = *DAT_00035608;
      pcVar10 = str_f_usb_isConnected_fail_x_x_x_x;
      sVar11 = 0;
    }
    else {
      *psVar4 = 0;
      OLED_Clear();
      FUN_0003cf7c();
      *DAT_00035750 = 0;
      FUN_0003afa2(5);
      ble_alert_led_stop();
      FUN_000312aa();
      FUN_000312de();
      if (((*DAT_00035678 == '\x01') || (*DAT_00035678 == '\x02')) && (*pcVar3 == '\0')) {
        app_user_ke_timer_stop();
        iVar8 = rom_071EA(3);
        if (iVar8 == 3) {
          dbg_printf(DAT_000356b4);
          *DAT_000356b8 = *DAT_000356b8 | 0x100;
          FUN_000295aa();
        }
      }
      FUN_0003262c();
      FUN_00032658();
      Success_led_2second();
      CHRG();
      OLED_Init();
      uVar2 = *DAT_00035674;
      uVar9 = *(uint *)(DAT_00035604 + 0x30);
      bVar12 = *DAT_00035608;
      sVar11 = *psVar4;
      pcVar10 = str_f_usb_isConnected_1_x_x_x_x;
    }
    dbg_printf(pcVar10,sVar11,uVar9 & 1,bVar12,uVar2);
  }
LAB_00035534:
  if (*DAT_000357a0 != '\0') {
    *DAT_000357a0 = *DAT_000357a0 + -1;
    *DAT_000357a4 = 0;
    *DAT_000357a8 = 1;
    rom_24FEC(DAT_000357ac,8);
    *DAT_000357b0 = 1;
  }
  if (*DAT_000357b4 != '\0') {
    *DAT_000357b4 = *DAT_000357b4 + -1;
    return;
  }
  *DAT_000357b4 = '\x05';
  if (*DAT_000357b8 != '\0') {
    *DAT_000357b8 = *DAT_000357b8 + -1;
  }
  iVar8 = FUN_0002b18e();
  if (iVar8 == 0) {
    *DAT_00035728 = '\0';
  }
  else {
    *DAT_00035728 = '\x01';
    if ((*DAT_00035724 == '\0') && ((*DAT_0003572c == 0 || (*pcVar3 == '\0')))) {
      sensor_init();
      set_dpi();
    }
  }
  psVar6 = DAT_000357bc;
  psVar4 = DAT_00035714;
  if (*DAT_00035714 == 0) {
    if (*DAT_000357bc == 0) {
      *DAT_00035b54 = 1;
      pcVar3 = DAT_00035b58;
      cVar1 = *DAT_00035b58;
      *DAT_00035b58 = cVar1 + '\x01';
      if (cVar1 != '\0') {
        if (0xef < (byte)(cVar1 + 1U)) {
          *pcVar3 = '\0';
        }
        FUN_0003d8da(*pcVar3);
        return;
      }
    }
  }
  else {
    if ((*DAT_00035714 == 400) && (*DAT_00035718 != '\0')) {
      *DAT_00035718 = '\0';
      OLED_Clear();
      *DAT_0003573c = '\0';
      *DAT_000357c0 = 1;
      FUN_0003d2b0();
    }
    sVar11 = *psVar4;
    *psVar4 = sVar11 + -1;
    if (((short)(sVar11 + -1) == 0x118) && (*psVar6 == 0)) {
      *DAT_00035718 = '\x01';
      OLED_Clear();
      FUN_0003d8da(0x78);
    }
    if (*psVar4 != 0 || *psVar6 != 0) {
      return;
    }
    OLED_Clear();
  }
  return;
}

/* ==========================================================================
 * FUN_000358b6   @ 0x000358b6   (424 bytes)
 * called by : system_mode
 * calls     : FUN_00031244, FUN_000312aa, FUN_0003143c, rom_24F9C, rom_24FEC, time_sensor_invalid
 */

void FUN_000358b6(void)

{
  undefined2 uVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char cVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  pcVar2 = DAT_00035b98;
  if (*DAT_00035b98 != '\0') {
    return;
  }
  if (1 < *DAT_00035b9c) {
    return;
  }
  if (*DAT_00035ba0 == '\0') {
    return;
  }
  *DAT_00035ba0 = '\0';
  if (*DAT_00035ba4 != '\0') {
    return;
  }
  if (*DAT_00035ba8 != '\0') {
    return;
  }
  time_sensor_invalid();
  pcVar5 = DAT_00035c0c;
  puVar3 = DAT_00035bb0;
  if (*DAT_00035bac == '\0') {
    if (*DAT_00035bb8 == '\0') {
      if (*DAT_00035bc0 == '\0') {
        if (*DAT_00035bc8 == '\0') {
          if (*DAT_00035bd0 == '\0') {
            if (*DAT_00035bd8 == '\0') {
              if ((((*DAT_00035be0 == '\0') && (*DAT_00035be4 == '\0')) && (*DAT_00035be8 == '\0'))
                 && ((*DAT_00035bec == '\0' && (*DAT_00035bf0 == '\0')))) {
                if (*DAT_00035c0c != '\0') {
                  return;
                }
                FUN_0003143c();
                if (*DAT_00035c08 == '\0') {
                  cVar6 = -0x38;
                }
                else {
                  cVar6 = '\x04';
                }
                *pcVar5 = cVar6;
                return;
              }
              FUN_00031244();
              *puVar3 = 0x30;
              puVar3[1] = *DAT_00035bf4;
              uVar1 = *DAT_00035bf8;
              puVar3[2] = (char)uVar1;
              puVar3[3] = (char)((ushort)uVar1 >> 8);
              uVar1 = *DAT_00035bfc;
              puVar3[4] = (char)uVar1;
              puVar3[5] = (char)((ushort)uVar1 >> 8);
              puVar3[6] = *DAT_00035c00;
              puVar3[7] = *DAT_00035c04;
              if ((*DAT_00035be4 == '\0') || (*DAT_00035be8 == '\0')) {
                *DAT_00035be8 = '\0';
              }
              FUN_000312aa();
              *DAT_00035c08 = -0x38;
              *DAT_00035c0c = '\x04';
              goto LAB_00035928;
            }
            *DAT_00035bd8 = '\0';
            rom_24FEC(DAT_00035bb0,0x20);
            *puVar3 = 0x35;
            rom_24F9C(puVar3 + 1,DAT_00035bdc,4);
            uVar7 = DAT_00035bdc;
          }
          else {
            *DAT_00035bd0 = '\0';
            rom_24FEC(DAT_00035bb0,0x20);
            *puVar3 = 0x35;
            rom_24F9C(puVar3 + 1,DAT_00035bd4,4);
            uVar7 = DAT_00035bd4;
          }
          rom_24FEC(uVar7,4);
        }
        else {
          *DAT_00035bc8 = '\0';
          rom_24FEC(DAT_00035bb0,0x20);
          *puVar3 = 0x34;
          puVar3 = DAT_00035bcc;
          DAT_00035bb0[1] = *DAT_00035bcc;
          *puVar3 = 0;
        }
      }
      else {
        *DAT_00035bc0 = '\0';
        rom_24FEC(DAT_00035bb0,0x20);
        puVar4 = DAT_00035bc4;
        *puVar3 = 0x33;
        puVar3 = DAT_00035bb0;
        DAT_00035bb0[1] = *puVar4;
        puVar3[2] = puVar4[1];
      }
      goto LAB_00035928;
    }
    *DAT_00035bb8 = '\0';
    rom_24FEC(DAT_00035bb0,0x20);
    uVar7 = DAT_00035bbc;
    uVar8 = 0xe;
    *puVar3 = 0x32;
  }
  else {
    *DAT_00035bac = '\0';
    rom_24FEC(puVar3,0x20);
    uVar7 = DAT_00035bb4;
    uVar8 = 8;
    *puVar3 = 0x31;
  }
  rom_24F9C(puVar3 + 1,uVar7,uVar8);
LAB_00035928:
  *pcVar2 = '\x01';
  return;
}

/* ==========================================================================
 * fn24main   @ 0x00035dbe   (106 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_00035c9c, FUN_000360aa, FUN_00036b36, FUN_00036be4, FUN_00039c84, TEST_SINGLE_WAVE, ... (+4 more)
 * string    : "fn24main  RF_MODE USB %x, %x, %x\r\n"
 */

void fn24main(void)

{
  char cVar1;
  short *psVar2;
  char *pcVar3;
  
  FUN_00039c84();
  FUN_00035c9c();
  if (*DAT_00035e8c == '\0' && *DAT_00035e90 == 0) {
    fWorkModeInit();
  }
  FUN_00036b36();
  FUN_00036be4(2);
  pcVar3 = DAT_00035e54;
  psVar2 = DAT_00035e38;
  dbg_printf(str_fn24main_RF_MODE_USB_x_x_x,*DAT_00035e54,*DAT_00035e30,*DAT_00035e38);
  cVar1 = *pcVar3;
  if (cVar1 == '\0') {
    system_mode();
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 == '\x04') {
      if (*psVar2 == 7) {
        TEST_SINGLE_WAVE();
        return;
      }
      if (*psVar2 != 10) {
        return;
      }
      TEST_SINGLE_WAVE_2();
      return;
    }
    if (cVar1 == '\x05') {
      FUN_000360aa();
    }
  }
  return;
}

/* ==========================================================================
 * system_mode   @ 0x00035eb8   (282 bytes)
 * called by : fn24main
 * calls     : Detect_FULL_IN, FUN_0002aa5c, FUN_0002ac0e, FUN_0002b8a2, FUN_00030094, FUN_0003186e, ... (+27 more)
 * string    : "system_mode usb24 RF_MODE %x, %x\r\n"
 */

void system_mode(void)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 in_r3;
  
  pcVar2 = DAT_00035fd8;
  pcVar1 = DAT_00035fd4;
  dbg_printf(str_system_mode_usb24_RF_MODE_x_x,*DAT_00035fd8,*DAT_00035fd4,in_r3,in_r3);
  pcVar3 = DAT_00036000;
  if (*DAT_00036000 == '\0') {
    FUN_000369a0();
    iVar4 = DAT_00036004;
    *(undefined4 *)(DAT_00036004 + 0x18) = 0xa0;
    *(undefined4 *)(iVar4 + 0x18) = 0x80;
    FUN_000369d8();
    rom_24FEC(DAT_00036008,0x20);
  }
  FUN_0003cdb6();
  FUN_00036eee(8);
LAB_00035fbe:
  while( true ) {
    if ((*pcVar2 != '\0') || ((*pcVar1 != '\0' && (*pcVar3 == '\0')))) {
      return;
    }
    FUN_0003b54e();
    if (*DAT_0003600c != '\0') {
      *DAT_0003600c = '\0';
      FUN_0003300e();
    }
    if ((*DAT_00036010 != '\0') && (*DAT_00036014 == 0)) {
      *DAT_00036010 = '\0';
      FUN_0002ac0e();
    }
    if (*DAT_00036018 != '\0') break;
    FUN_0002aa5c();
    if (*pcVar3 == '\0') {
      if (*pcVar1 == '\0') goto code_r0x00035f5e;
      goto LAB_00035f80;
    }
    FUN_0003870a();
    FUN_00033a7e();
    usb_suspend();
    exist();
    test();
    FUN_0003186e();
    FUN_0003236a();
    if (*DAT_0003601c != '\0') goto LAB_00035f7e;
  }
  goto LAB_00035f94;
code_r0x00035f5e:
  FUN_0003186e();
  FUN_0003236a();
  FUN_000358b6();
  FUN_00030094();
  if ((*DAT_0003601c != '\0') && (*DAT_00036014 < 2)) {
LAB_00035f7e:
    *DAT_0003601c = '\0';
LAB_00035f80:
    FUN_000323ee();
    FUN_00032430();
    _saveC_GM_ProfileMax();
    set_Update_OLED();
    Led_OLED();
LAB_00035f94:
    set_Update_OLED_2();
    single_wave();
    if (*pcVar3 == '\0') {
      f_reconnect_24G();
    }
    f_usb_isConnected();
    FUN_00034e4c();
    mode_sw();
    Detect_FULL_IN();
    app_mutli_link_change();
    FUN_0002b8a2();
  }
  goto LAB_00035fbe;
}

/* ==========================================================================
 * FUN_00036024   @ 0x00036024   (32 bytes)
 * called by : FUN_000360aa
 * calls     : FUN_000369d8, FUN_0003c21e, FUN_0003c286
 */

void FUN_00036024(void)

{
  int iVar1;
  
  FUN_000369d8();
  FUN_0003c286(1);
  FUN_0003c21e(1,DAT_0003618c);
  iVar1 = DAT_00036190;
  *(undefined1 *)(DAT_00036190 + 1) = 0;
  *(undefined1 *)(iVar1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_00036044   @ 0x00036044   (102 bytes)
 * called by : FUN_000360aa
 */

void FUN_00036044(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint *puVar3;
  int iVar4;
  undefined1 *puVar5;
  byte bVar6;
  
  puVar3 = DAT_00036194;
  bVar6 = 0;
  uVar1 = DAT_00036190[1];
  uVar2 = DAT_00036190[2];
  do {
    iVar4 = DAT_00036198;
    do {
    } while (-1 < (int)(*puVar3 << 0x11));
    *puVar3 = *puVar3 & 0xffffbfff;
    *(undefined4 *)(iVar4 + 0x18) = 0xa0;
    *(undefined4 *)(iVar4 + 0x18) = 0x80;
    *(undefined4 *)(iVar4 + 0x14) = 1;
    puVar5 = DAT_0003619c;
    *DAT_0003619c = 0x55;
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    *(undefined4 *)(iVar4 + 0x14) = 0;
    bVar6 = bVar6 + 1;
  } while (bVar6 < 100);
  *DAT_00036190 = 0x55;
  bVar6 = 0;
  do {
    do {
    } while (-1 < (int)(*puVar3 << 0x11));
    bVar6 = bVar6 + 1;
    *puVar3 = *puVar3 & 0xffffbfff;
  } while (bVar6 < 0x2a);
  return;
}

/* ==========================================================================
 * FUN_000360aa   @ 0x000360aa   (226 bytes)
 * called by : fn24main
 * calls     : FUN_0002bcac, FUN_00031784, FUN_00036024, FUN_00036044, FUN_000361a8, FUN_000369a0, ... (+8 more)
 */

void FUN_000360aa(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  
  FUN_0003b528();
  FUN_00036024();
  iVar3 = DAT_00036198;
  *(undefined4 *)(DAT_00036198 + -0xb4) = 1;
  *(undefined4 *)(iVar3 + -0xb0) = 5;
  *(undefined4 *)(iVar3 + -0xac) = 0x8a;
  *(undefined4 *)(iVar3 + -0xa8) = 3;
  FUN_000369a0();
  puVar2 = DAT_00036194;
  bVar5 = 0;
  do {
    bVar5 = bVar5 + 1;
  } while (bVar5 < 0x14);
  *DAT_00036194 = *DAT_00036194 & 0xffffbfff;
  bVar5 = 0;
  do {
    do {
    } while (-1 < (int)(*puVar2 << 0x11));
    bVar5 = bVar5 + 1;
    *puVar2 = *puVar2 & 0xffffbfff;
    iVar1 = DAT_00036190;
  } while (bVar5 < 0x44);
  if (*(char *)(DAT_00036190 + 2) != -1) {
    FUN_00036044();
    FUN_000361a8(*(undefined1 *)(iVar1 + 1));
    bVar5 = *(byte *)(iVar1 + 2);
    for (uVar6 = 0; (int)uVar6 < (int)(bVar5 - 1); uVar6 = uVar6 + 1 & 0xff) {
      bVar7 = 0;
      do {
        do {
        } while (-1 < (int)(*puVar2 << 0x11));
        bVar7 = bVar7 + 1;
        *puVar2 = *puVar2 & 0xffffbfff;
      } while (bVar7 < 0x96);
    }
    FUN_00036b36();
    FUN_00036be4(2);
    FUN_000369a0();
    iVar1 = DAT_00036198;
    *(undefined4 *)(DAT_00036198 + 0x18) = 0xa0;
    *(undefined4 *)(iVar1 + 0x18) = 0x80;
    *(undefined4 *)(iVar3 + -0xb4) = 1;
    *(undefined4 *)(iVar3 + -0xb0) = 5;
    *(uint *)(iVar3 + -0xac) = *(byte *)(DAT_00036190 + 1) + 0x80;
    *(undefined4 *)(iVar3 + -0xa8) = 3;
    FUN_000369d8();
    FUN_00031784(DAT_000361a0);
    sensor_pwdn();
    FUN_000369ac();
    FUN_0003c286(1);
    FUN_0002bcac();
    puVar4 = DAT_000361a4;
    do {
      *puVar4 = 0;
      FUN_0003ae82();
    } while( true );
  }
  do {
    FUN_00036044();
  } while( true );
}

/* ==========================================================================
 * FUN_000361a8   @ 0x000361a8   (50 bytes)
 * called by : FUN_000360aa, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, single_wave
 */

void FUN_000361a8(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_000365a0;
  *(uint *)(DAT_000365a0 + 0x10) = *(uint *)(DAT_000365a0 + 0x10) | 0x20000000;
  *(undefined4 *)(DAT_000365a4 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = DAT_000365a4;
  uVar2 = *(uint *)(DAT_000365a4 + 0x90);
  *DAT_000365a8 = uVar2;
  *(uint *)(iVar1 + 0x90) = uVar2 & 0x780 | param_1;
  *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x3000;
  return;
}

/* ==========================================================================
 * FUN_000361da   @ 0x000361da   (22 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2
 */

void FUN_000361da(void)

{
  int iVar1;
  
  iVar1 = DAT_000365a4;
  *(undefined4 *)(DAT_000365a4 + 0x90) = *DAT_000365a8;
  *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) & 0xffffcfff;
  return;
}

/* ==========================================================================
 * get_scan_Rvalue   @ 0x000361f0   (68 bytes)
 * calls     : FUN_0002abd4, FUN_000317c2, dbg_printf
 * string    : "get_scan_Rvalue 2============== %x,%x,%x,%x,%x,\r\n"
 */

void get_scan_Rvalue(void)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = DAT_000365ac;
  if ((*DAT_000365ac == '\0') && (iVar2 = FUN_0002abd4(), iVar2 == 3)) {
    FUN_000317c2(10);
    iVar2 = FUN_0002abd4();
    dbg_printf(str_get_scan_Rvalue_2_x_x_x_x_x,*pcVar1,iVar2,*DAT_000365b8,*DAT_000365b4,
               *DAT_000365b0);
    if (iVar2 == 3) {
      *DAT_000365f0 = 1;
    }
  }
  return;
}

/* ==========================================================================
 * TEST_SINGLE_WAVE   @ 0x00036274   (836 bytes)
 * called by : fn24main
 * calls     : FUN_0002ac0e, FUN_00031784, FUN_00032686, FUN_000361a8, FUN_000361da, FUN_000369a0, ... (+10 more)
 * string    : "%s \r\n"
 * string    : "-Kapplication_test_mode"
 * string    : "TEST_SINGLE_WAVE ch==%d, mode=%x, mode=cal_data%x\n"
 * string    : "TEST_RF_DATA...\r\n"
 * string    : "TEST_CD...\r\n"
 * string    : "flag_revice...\r\n"
 * string    : "Key_CurrentStatus:=%x\n"
 * string    : "RB press...\r\n"
 * string    : "LB press...SW mode\r\n"
 * string    : "TEST_SINGLE_WAVE:=%x\n"
 * string    : "TEST_RF_DATA:=%x\n"
 * string    : "TEST_CD\n"
 * string    : "MB press...SW channel\r\n"
 * string    : "switch ch==%d, mode=%x\n"
 * string    : "TEST_SINGLE_WAVE ch==%d, mode=%x\n"
 */

void TEST_SINGLE_WAVE(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  short *psVar4;
  undefined1 *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char cVar12;
  bool bVar13;
  
  uVar10 = 1;
  bVar2 = false;
  dbg_printf(str_s_12,DAT_0003660c);
  FUN_0003b528();
  iVar11 = 0;
  *(undefined4 *)(DAT_00036618 + 0x10) = 3;
  FUN_00036eee(8);
  FUN_000369ac();
  FUN_000369a0();
  FUN_000369d8();
  FUN_000361a8(*(undefined1 *)(DAT_0003660c + -2));
  *DAT_000365f0 = '\x01';
  FUN_00032686(7);
  while (*DAT_00036620 != 0) {
    if (*DAT_0003661c != '\0') {
      *DAT_0003661c = '\0';
      FUN_0002ac0e();
    }
  }
  *DAT_00036624 = '\0';
  FUN_00032686(2);
  uVar7 = FUN_00039cfc();
  *DAT_00036628 = (char)uVar7;
  dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x_mode_cal_data_x,*(undefined1 *)(DAT_0003660c + -2),0,
             uVar7);
LAB_000362f4:
  while( true ) {
    do {
      do {
      } while (*DAT_0003661c == '\0');
      *DAT_0003661c = '\0';
      if (iVar11 == 2) {
        dbg_printf(str_TEST_RF_DATA);
        puVar5 = DAT_00036674;
        *DAT_00036674 = 1;
        puVar5[1] = 1;
        puVar5[2] = 2;
        puVar5[3] = 3;
        puVar5[4] = 4;
        cVar12 = '\x04';
        do {
          FUN_00036dd4(5);
          FUN_00031784(DAT_00036678);
          bVar13 = cVar12 != '\0';
          cVar12 = cVar12 + -1;
        } while (bVar13);
      }
      else if (iVar11 == 1) {
        dbg_printf(str_TEST_CD);
        puVar5 = DAT_00036674;
        *DAT_00036674 = 0xcc;
        puVar5[1] = 0xcc;
        puVar5[2] = 0xcc;
        puVar5[3] = 0xcc;
        puVar5[4] = 0xcc;
        puVar5[5] = 0xcc;
        puVar5[6] = 0xcc;
        puVar5[7] = 0xcc;
        puVar5[8] = 0xcc;
        puVar5[9] = 0xcc;
        puVar5[10] = 0xcc;
        puVar5[0xb] = 0xcc;
        puVar5[0xc] = 0xcc;
        puVar5[0xd] = 0xcc;
        puVar5[0xe] = 0xcc;
        puVar5[0xf] = 0xcc;
        puVar5[0x10] = 0xcc;
        puVar5[0x11] = 0xcc;
        puVar5[0x12] = 0xcc;
        puVar5[0x13] = 0xcc;
        puVar5[0x14] = 0xcc;
        puVar5[0x15] = 0xcc;
        puVar5[0x16] = 0xcc;
        puVar5[0x17] = 0xcc;
        puVar5[0x18] = 0xcc;
        FUN_00036b36();
        FUN_00036be4(2);
        FUN_000369a0();
        iVar3 = DAT_00036618;
        *(undefined4 *)(DAT_00036618 + 0xd8) = 0xa0;
        *(undefined4 *)(iVar3 + 0xd8) = 0x80;
        *(undefined4 *)(DAT_00036618 + 0x10) = 3;
        FUN_000361da();
        FUN_00036eee(8);
        FUN_000369d8();
        *(undefined4 *)(iVar3 + 0xd4) = 0;
        *(uint *)(DAT_00036618 + 0x14) = DAT_0003668c[uVar10] + 0x80;
        *(undefined4 *)(iVar3 + 0xd4) = 1;
        uVar10 = uVar10 + 1 & 0xf;
        cVar12 = '\x04';
        do {
          FUN_00036dd4(0x19);
          FUN_00031784(DAT_00036678);
          bVar13 = cVar12 != '\0';
          cVar12 = cVar12 + -1;
        } while (bVar13);
      }
      if (bVar2) {
        dbg_printf(str_flag_revice);
        puVar6 = DAT_000366a4;
        uVar9 = *DAT_000366a4;
        if ((int)(uVar9 << 0x19) < 0) {
          DAT_000366a4[-10] = 0x80;
          *puVar6 = uVar9 & 0xff;
        }
      }
      FUN_0002ac0e();
    } while ((*DAT_000365f0 == '\0') || (*DAT_00036624 == '\0'));
    *DAT_00036624 = '\0';
    psVar4 = DAT_00036620;
    dbg_printf(str_Key_CurrentStatus_x_2,*DAT_00036620);
    sVar1 = *psVar4;
    if (sVar1 == 1) break;
    if (sVar1 == 4) {
      dbg_printf(str_MB_press_SW_channel);
      bVar2 = false;
      uVar10 = uVar10 + 1 & 0xff;
      if (uVar10 < 3) {
        if (uVar10 == 0) goto LAB_00036536;
        if (uVar10 == 1) {
          uVar7 = 2;
          goto LAB_00036540;
        }
        if (uVar10 == 2) {
          uVar7 = 4;
          goto LAB_00036540;
        }
      }
      else {
        uVar10 = 0;
LAB_00036536:
        uVar7 = 1;
LAB_00036540:
        FUN_00032686(uVar7);
      }
      FUN_00036b36();
      FUN_00036be4(2);
      FUN_000369a0();
      puVar6 = DAT_000366a4;
      DAT_000366a4[-10] = 0xa0;
      puVar6[-10] = 0x80;
      *(undefined4 *)(DAT_00036618 + 0x10) = 3;
      FUN_000361da();
      FUN_00031784(300);
      FUN_00036eee(8);
      FUN_000369d8();
      iVar3 = DAT_00036914;
      if (iVar11 == 0) {
        FUN_000361a8(*(undefined1 *)(DAT_00036914 + uVar10));
        dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x,*(undefined1 *)(iVar3 + uVar10),0);
      }
      else {
        *(uint *)(DAT_00036618 + 0x14) = *(byte *)(DAT_0003660c + -3 + uVar10) + 0x80;
        puVar6[-0xb] = 0;
        puVar6[-0xb] = 1;
      }
      dbg_printf(str_switch_ch_d_mode_x,*(undefined1 *)(DAT_0003660c + -3 + uVar10),iVar11);
    }
    else if (sVar1 == 2) {
      dbg_printf(str_RB_press);
      bVar2 = true;
      iVar11 = 3;
      FUN_00036b36();
      FUN_00036be4(2);
      FUN_000369a0();
      puVar6 = DAT_000366a4;
      DAT_000366a4[-10] = 0xa0;
      puVar6[-10] = 0x80;
      iVar3 = DAT_00036618;
      *(undefined4 *)(DAT_00036618 + 0x10) = 3;
      *(uint *)(iVar3 + 0x14) = *(byte *)(DAT_0003660c + -3 + uVar10) + 0x80;
      FUN_00036eee(8);
      FUN_000369b8();
      *(uint *)(iVar3 + 0x14) = *(byte *)(DAT_0003660c + -3 + uVar10) + 0x80;
    }
  }
  dbg_printf(str_LB_press_SW_mode);
  bVar2 = false;
  FUN_00036b36();
  FUN_00036be4(2);
  FUN_000369a0();
  puVar6 = DAT_000366a4;
  DAT_000366a4[-10] = 0xa0;
  puVar6[-10] = 0x80;
  iVar3 = DAT_00036618;
  *(undefined4 *)(DAT_00036618 + 0x10) = 3;
  FUN_00036eee(8);
  if (iVar11 == 0) {
    iVar11 = 2;
    *(uint *)(iVar3 + 0x14) = *(byte *)(DAT_0003660c + -3 + uVar10) + 0x80;
    FUN_000369d8();
    FUN_00032686(4);
    uVar7 = *DAT_000365a8;
    pcVar8 = str_TEST_RF_DATA_x;
  }
  else {
    if (iVar11 == 2) {
      iVar11 = 1;
      uVar10 = 0;
      *(uint *)(iVar3 + 0x14) = *DAT_0003668c + 0x80;
      FUN_000369d8();
      FUN_00032686(2);
      dbg_printf(str_TEST_CD_2);
      goto LAB_000362f4;
    }
    if ((iVar11 != 1) && (iVar11 != 3)) goto LAB_000362f4;
    iVar11 = 0;
    FUN_000361a8(*(undefined1 *)(DAT_0003660c + -3 + uVar10));
    FUN_00032686(1);
    uVar7 = *DAT_000365a8;
    pcVar8 = str_TEST_SINGLE_WAVE_x;
  }
  dbg_printf(pcVar8,uVar7);
  goto LAB_000362f4;
}

/* ==========================================================================
 * TEST_SINGLE_WAVE_2   @ 0x00036754   (422 bytes)
 * called by : fn24main
 * calls     : FUN_00028b00, FUN_0002ac0e, FUN_00031784, FUN_00032686, FUN_000361a8, FUN_000361da, ... (+12 more)
 * string    : "%s \r\n"
 * string    : "application_cal_data_mode"
 * string    : "-Kapplication_test_mode"
 * string    : "TEST_SINGLE_WAVE ch==%d, mode=%x, mode=cal_data%x\n"
 * string    : "Key_CurrentStatus:=%x\n"
 * string    : "DPILOOP SURE: --:=%x\n"
 * string    : "B4: CAL_DATA++:=%x\n"
 * string    : "B5: CAL_DATA--:=%x\n"
 * string    : "TEST_SINGLE_WAVE ch==%d, mode=%x\n"
 */

void TEST_SINGLE_WAVE_2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  dbg_printf(DAT_0003693c,DAT_00036914 + 0x19,param_3,param_4,param_3);
  FUN_0003b528();
  uVar6 = 0;
  *(undefined4 *)(DAT_00036940 + 0x10) = 3;
  FUN_00036eee(8);
  FUN_000369ac();
  FUN_000369a0();
  FUN_000369d8();
  FUN_000361a8(*(undefined1 *)(DAT_00036914 + 1));
  *DAT_00036944 = '\x01';
  FUN_00032686(7);
  psVar3 = DAT_00036948;
  while (pcVar4 = DAT_00036950, *psVar3 != 0) {
    if (*DAT_0003694c != '\0') {
      *DAT_0003694c = '\0';
      FUN_0002ac0e();
    }
  }
  *DAT_00036950 = '\0';
  FUN_00032686(2);
  uVar5 = FUN_00039cfc();
  iVar2 = DAT_00036914;
  *DAT_00036954 = (char)uVar5;
  dbg_printf(DAT_0003693c + 0x1c,*(undefined1 *)(iVar2 + 1),uVar6,uVar5);
LAB_000367d8:
  do {
    do {
      do {
      } while (*DAT_0003694c == '\0');
      *DAT_0003694c = '\0';
      FUN_0002ac0e();
    } while ((*DAT_00036944 == '\0') || (*pcVar4 == '\0'));
    *pcVar4 = '\0';
    dbg_printf(DAT_0003693c + 0x98,*psVar3);
    sVar1 = *psVar3;
    if (sVar1 == 0x10) {
      *DAT_00036958 = 1;
      *DAT_00036954 = *DAT_00036954 + '\x01';
      rgb_24g_test_cal();
      dbg_printf(str_B4_CAL_DATA_x,*DAT_00036954);
      FUN_00028b00(DAT_00036988);
      rwip_driver_init(0);
      FUN_00036b36();
      FUN_00036be4(2);
      FUN_000369a0();
      iVar2 = DAT_00036940;
      *(undefined4 *)(DAT_00036940 + 0xd8) = 0xa0;
      *(undefined4 *)(iVar2 + 0xd8) = 0x80;
    }
    else {
      if (sVar1 != 0x20) {
        if (sVar1 == 0x100) {
          *DAT_00036958 = 1;
          FUN_00039d26(*DAT_00036954);
          FUN_00032686(0);
          uVar5 = FUN_00039cfc();
          *DAT_00036954 = (char)uVar5;
          dbg_printf(str_DPILOOP_SURE_x,uVar5);
        }
        goto LAB_000367d8;
      }
      *DAT_00036958 = 1;
      *DAT_00036954 = *DAT_00036954 + -1;
      rgb_24g_test_cal();
      dbg_printf(str_B5_CAL_DATA_x,*DAT_00036954);
      FUN_00028b00(DAT_00036988);
      rwip_driver_init(0);
      FUN_00036b36();
      FUN_00036be4(2);
      FUN_000369a0();
      iVar2 = DAT_00036940;
      *(undefined4 *)(DAT_00036940 + 0xd8) = 0xa0;
      *(undefined4 *)(iVar2 + 0xd8) = 0x80;
    }
    *(undefined4 *)(DAT_00036940 + 0x10) = 3;
    FUN_000361da();
    FUN_00031784(300);
    FUN_00036eee(8);
    FUN_000369d8();
    FUN_000361a8(*(undefined1 *)(DAT_00036914 + 1));
    dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x,*(undefined1 *)(DAT_00036914 + 1),uVar6);
  } while( true );
}

/* ==========================================================================
 * FUN_000369a0   @ 0x000369a0   (12 bytes)
 * called by : FUN_0002ff18, FUN_00030094, FUN_000360aa, FUN_000369b8, FUN_000369d8, FUN_00036e0c, ... (+8 more)
 */

void FUN_000369a0(void)

{
  *DAT_00036d84 = *DAT_00036d84 | 2;
  return;
}

/* ==========================================================================
 * FUN_000369ac   @ 0x000369ac   (12 bytes)
 * called by : FUN_0002ff18, FUN_000360aa, FUN_00036b36, FUN_00036e0c, SLEEP, TEST_SINGLE_WAVE, ... (+4 more)
 */

void FUN_000369ac(void)

{
  *DAT_00036d84 = *DAT_00036d84 & 0xfd;
  return;
}

/* ==========================================================================
 * FUN_000369b8   @ 0x000369b8   (32 bytes)
 * called by : FUN_0002fef0, TEST_SINGLE_WAVE, ch_frequency
 * calls     : FUN_000369a0
 */

void FUN_000369b8(void)

{
  uint *puVar1;
  
  FUN_000369a0();
  puVar1 = DAT_00036d84;
  DAT_00036d84[0x36] = 0x80;
  puVar1[0x35] = 0;
  *DAT_00036d84 = *DAT_00036d84 | 1;
  puVar1[0x35] = 1;
  return;
}

/* ==========================================================================
 * FUN_000369d8   @ 0x000369d8   (34 bytes)
 * called by : FUN_0002fa6c, FUN_00030094, FUN_00036024, FUN_000360aa, LightUp_Mode_Led, TEST_SINGLE_WAVE, ... (+4 more)
 * calls     : FUN_000369a0
 */

void FUN_000369d8(void)

{
  uint *puVar1;
  
  FUN_000369a0();
  puVar1 = DAT_00036d84;
  DAT_00036d84[0x36] = 0xa0;
  puVar1[0x35] = 0;
  *DAT_00036d84 = *DAT_00036d84 & 0xfe;
  puVar1[0x35] = 1;
  return;
}

/* ==========================================================================
 * FUN_000369fa   @ 0x000369fa   (24 bytes)
 * called by : FUN_00036a12, FUN_00036b36, FUN_00036cd2, FUN_00036cee
 */

void FUN_000369fa(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    *(undefined4 *)(param_1 + uVar1 * 4) = *(undefined4 *)(param_2 + uVar1 * 4);
  }
  return;
}

/* ==========================================================================
 * FUN_00036a12   @ 0x00036a12   (66 bytes)
 * calls     : FUN_000369fa, rom_25078
 */

void FUN_00036a12(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00036d84 + 0x1c;
  iVar3 = DAT_00036d84 + 0x30;
  iVar1 = rom_25078();
  FUN_000369fa(iVar2,DAT_00036d88,3);
  FUN_000369fa(iVar1 << 0x10,DAT_00036d88,3);
  FUN_000369fa(iVar3,DAT_00036d88 + 0xc,3);
  return;
}

/* ==========================================================================
 * FUN_00036af2   @ 0x00036af2   (34 bytes)
 * called by : FUN_00036dd4
 */

void FUN_00036af2(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00036d84;
  *(undefined4 *)(DAT_00036d84 + 0xd8) = 0x68;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(uint *)(iVar1 + 0xdc) = (uint)*(byte *)(param_1 + uVar2);
  }
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * FUN_00036b36   @ 0x00036b36   (174 bytes)
 * called by : FUN_000360aa, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, fn24main
 * calls     : FUN_000369ac, FUN_000369fa
 */

void FUN_00036b36(void)

{
  undefined4 *puVar1;
  
  DAT_0080000c = DAT_0080000c & 0xfffeffff;
  FUN_000369fa(DAT_00036d84 + 0x22,DAT_00036d88 + -0x20,4);
  FUN_000369fa(DAT_00036d84 + 0x26,DAT_00036d88 + -0x10,4);
  puVar1 = DAT_00036d84;
  *DAT_00036d84 = 0xc;
  puVar1[1] = 3;
  puVar1[2] = 3;
  puVar1[3] = 1;
  puVar1[4] = 2;
  puVar1[5] = 0x85;
  puVar1[6] = 0xf;
  FUN_000369fa(DAT_00036d84 + 7,DAT_00036d88,3);
  FUN_000369fa(DAT_00036d84 + 0xc,DAT_00036d88 + 0xc,3);
  puVar1 = DAT_00036d84;
  DAT_00036d84[0x11] = 0x11;
  puVar1[0x12] = 0x12;
  puVar1[0x13] = 0x13;
  puVar1[0x14] = 0x14;
  FUN_000369fa(DAT_00036d84 + 0x15,DAT_00036d88,3);
  puVar1[0x1a] = 0x20;
  puVar1[0x1b] = 0x20;
  puVar1[0x1c] = 0x20;
  puVar1[0x1d] = 0x20;
  puVar1[0x1e] = 0x20;
  puVar1[0x1f] = 0x20;
  puVar1 = DAT_00036d84;
  DAT_00036d84[0x20] = 0x3f;
  puVar1[0x21] = 7;
  FUN_000369ac();
  *(undefined4 *)(DAT_00036d90 + 0x10) = DAT_00036d8c;
  *(undefined4 *)(DAT_00036d90 + 0x6c) = DAT_00036d94;
  return;
}

/* ==========================================================================
 * FUN_00036be4   @ 0x00036be4   (146 bytes)
 * called by : FUN_000360aa, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, fn24main
 */

void FUN_00036be4(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar3 = DAT_00036d98;
  iVar2 = DAT_00036d90;
  iVar1 = DAT_00036d84;
  if (param_1 == 0) {
    *(uint *)(DAT_00036d90 + 0x38) = *(uint *)(DAT_00036d90 + 0x38) & 0xfffffe00;
    *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | 100;
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & uVar3;
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 0x4080000;
    puVar5 = (uint *)(DAT_00036d90 + 0x40);
    *puVar5 = *puVar5 & DAT_00036d9c;
    *puVar5 = *puVar5 | 0x2800;
    uVar4 = 0x27;
  }
  else {
    uVar6 = DAT_00036d90 >> 0xf;
    if (param_1 == 1) {
      *(uint *)(DAT_00036d90 + 0x38) = *(uint *)(DAT_00036d90 + 0x38) & 0xfffffe00;
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | uVar6;
      *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & uVar3;
      *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 0x10200000;
      uVar4 = 7;
    }
    else {
      if (param_1 != 2) {
        return;
      }
      *(uint *)(DAT_00036d90 + 0x38) = *(uint *)(DAT_00036d90 + 0x38) & 0xfffffe00;
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | uVar6;
      *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & uVar3;
      *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 0x10200000;
      uVar4 = 0xf;
    }
  }
  *(undefined4 *)(iVar1 + 0x18) = uVar4;
  return;
}

/* ==========================================================================
 * FUN_00036dd4   @ 0x00036dd4   (56 bytes)
 * called by : TEST_SINGLE_WAVE
 * calls     : FUN_00036af2
 */

undefined4 FUN_00036dd4(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00036f1c;
  *(undefined4 *)(DAT_00036f1c + 0x18) = 0x80;
  *(undefined4 *)(iVar1 + 0x18) = 0xa0;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  FUN_00036af2(DAT_00036f20,param_1);
  do {
    uVar2 = *(uint *)(DAT_00036f1c + 0x40);
  } while ((uVar2 & 0x3f) >> 4 == 0);
  if ((int)(uVar2 << 0x1a) < 0) {
    *(uint *)(DAT_00036f1c + 0x40) = 0x20;
  }
  *(undefined4 *)(iVar1 + 0x14) = 0;
  return 1;
}

/* ==========================================================================
 * FUN_00036e0c   @ 0x00036e0c   (124 bytes)
 * calls     : FUN_000369a0, FUN_000369ac, FUN_00036ad0
 */

undefined4 FUN_00036e0c(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  iVar2 = DAT_00036f1c;
  uVar5 = 0;
  *(undefined4 *)(DAT_00036f1c + 0x18) = 0x80;
  *(undefined4 *)(iVar2 + 0x18) = 0xa0;
  *(undefined4 *)(DAT_00036f1c + 0x40) = 0x7e;
  *(undefined4 *)(iVar2 + 0x14) = 1;
  FUN_00036ad0(DAT_00036f20,param_1);
  bVar1 = false;
  *DAT_00036f24 = 0;
  puVar4 = (uint *)(DAT_00036f1c + 0x40);
  do {
    uVar3 = *puVar4;
    if (5 < *DAT_00036f24) {
      bVar1 = true;
      break;
    }
  } while ((uVar3 & 0x3f) >> 4 == 0);
  if ((int)(uVar3 << 0x19) < 0) {
    *(undefined4 *)(iVar2 + 0x18) = 0x80;
    *puVar4 = 0x40;
    uVar5 = 2;
  }
  if ((int)(uVar3 << 0x1a) < 0) {
    *(undefined4 *)(iVar2 + 0x18) = 0xa0;
    *puVar4 = 0x20;
    uVar5 = 1;
  }
  if ((uVar3 & 0x10) != 0 || bVar1) {
    *(undefined4 *)(iVar2 + 0x18) = 0x80;
    *(undefined4 *)(iVar2 + 0x18) = 0xa0;
    FUN_000369ac();
    FUN_000369a0();
    *puVar4 = 0x10;
  }
  *(undefined4 *)(iVar2 + 0x14) = 0;
  return uVar5;
}

/* ==========================================================================
 * FUN_00036eee   @ 0x00036eee   (44 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, fWorkModeInit, single_wave, system_mode
 */

void FUN_00036eee(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00036f28;
  *(uint *)(DAT_00036f28 + 0x10) = *(uint *)(DAT_00036f28 + 0x10) | 0x20000000;
  *(undefined4 *)(DAT_00036f2c + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = DAT_00036f2c;
  *(uint *)(DAT_00036f2c + 0x90) = param_1 << 7 | *(uint *)(DAT_00036f2c + 0x90) & 0xfffff87f;
  *DAT_00036f30 = *(undefined4 *)(iVar1 + 0x90);
  return;
}

/* ==========================================================================
 * FUN_00036fe6   @ 0x00036fe6   (6 bytes)
 * called by : rxcsr2
 */

void FUN_00036fe6(undefined1 param_1)

{
  *(undefined1 *)(DAT_00037384 + 0xe) = param_1;
  return;
}

/* ==========================================================================
 * FUN_00037078   @ 0x00037078   (78 bytes)
 * called by : FUN_00037104, FUN_00037186
 * calls     : rom_24F9C
 */

void FUN_00037078(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_28;
  uint local_24;
  int iStack_20;
  uint uStack_1c;
  uint local_18;
  
  if ((param_2 & 3) == 0) {
    local_24 = (int)param_3 >> 2;
  }
  else {
    local_24 = 0;
  }
  uVar1 = 0;
  puVar3 = (undefined4 *)((param_1 * 4 + 0x20U & 0xff) + DAT_00037384);
  iStack_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  for (uVar2 = 0; uVar2 < local_24; uVar2 = uVar2 + 1) {
    rom_24F9C(&local_28,param_2 + uVar1,4);
    *puVar3 = local_28;
    uVar1 = uVar1 + 4;
  }
  for (; uVar1 < local_18; uVar1 = uVar1 + 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)(param_2 + uVar1);
  }
  return;
}

/* ==========================================================================
 * FUN_000370c6   @ 0x000370c6   (10 bytes)
 * called by : FUN_00037ab6, FUN_00037b0a, FUN_00038072, HID_RQT_Get_Protocol
 */

void FUN_000370c6(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00037384;
  *(undefined1 *)(DAT_00037384 + 0xe) = param_1;
  *(undefined1 *)(iVar1 + 0x11) = 0x20;
  return;
}

/* ==========================================================================
 * FUN_000370d0   @ 0x000370d0   (14 bytes)
 * called by : FUN_00037104, HID_RQT_Get_Protocol, _USB_macro2, f_usb_remote_wakeup
 */

void FUN_000370d0(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00037384;
  *(undefined1 *)(DAT_00037384 + 0xe) = param_1;
  *(undefined1 *)(iVar1 + 0x12) = 1;
  *(undefined1 *)(iVar1 + 0x11) = 10;
  return;
}

/* ==========================================================================
 * FUN_000370ec   @ 0x000370ec   (14 bytes)
 * called by : HID_RQT_Get_Protocol
 */

void FUN_000370ec(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00037384;
  *(undefined1 *)(DAT_00037384 + 0xe) = param_1;
  *(undefined1 *)(iVar1 + 0x12) = 1;
  *(undefined1 *)(iVar1 + 0x11) = 0x40;
  return;
}

/* ==========================================================================
 * FUN_00037104   @ 0x00037104   (130 bytes)
 * called by : FUN_00037b0a, HID_RQT_Get_Protocol, _USB_macro2
 * calls     : FUN_00037078, FUN_000370d0, FUN_0004245e, FUN_00042472
 */

void FUN_00037104(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*(byte *)(param_2 + 0xf) & 1) != 0) {
    uVar3 = (uint)*(ushort *)(param_2 + 8);
    if (uVar3 != 0) {
      iVar1 = FUN_0004245e(param_2);
      uVar4 = (uint)*(ushort *)(param_2 + 0xc);
      if (uVar3 < uVar4) {
        *(undefined1 *)(param_2 + 8) = 0;
        *(undefined1 *)(param_2 + 9) = 0;
        *(undefined1 *)(param_2 + 0xe) = 3;
        FUN_00042472(iVar1 + uVar3,param_2);
        FUN_00037078(param_1,iVar1,uVar3);
        uVar2 = 10;
      }
      else {
        *(char *)(param_2 + 8) = (char)(uVar3 - uVar4);
        *(char *)(param_2 + 9) = (char)(uVar3 - uVar4 >> 8);
        *(undefined1 *)(param_2 + 0xe) = 1;
        FUN_00042472(iVar1 + uVar4,param_2);
        FUN_00037078(param_1,iVar1,uVar4);
        uVar2 = 2;
      }
      *(undefined1 *)(DAT_00037384 + 0x11) = uVar2;
      return;
    }
    *(byte *)(param_2 + 0xf) = *(byte *)(param_2 + 0xf) ^ 1;
    FUN_000370d0(param_1);
    *(undefined1 *)(param_2 + 0xe) = 3;
  }
  return;
}

/* ==========================================================================
 * FUN_00037186   @ 0x00037186   (28 bytes)
 * called by : FUN_0003870a, exist
 * calls     : FUN_00037078
 */

void FUN_00037186(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00037384;
  *(undefined1 *)(DAT_00037384 + 0xe) = param_1;
  *(undefined1 *)(iVar1 + 0x11) = 8;
  FUN_00037078();
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 0x20;
  return;
}

/* ==========================================================================
 * FUN_0003725e   @ 0x0003725e   (12 bytes)
 * called by : exist
 */

int FUN_0003725e(void)

{
  return (uint)*(byte *)(DAT_00037384 + 0xc) + (uint)*(byte *)(DAT_00037384 + 0xd) * 0x100;
}

/* ==========================================================================
 * FUN_000374e2   @ 0x000374e2   (38 bytes)
 * called by : FUN_00037534
 * calls     : FUN_00036fec, FUN_00037830, FUN_00037844
 */

void FUN_000374e2(undefined4 param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  *(char *)(DAT_000376a4 + 0xe) = (char)param_1;
  FUN_00036fec();
  uVar1 = FUN_00037830(param_1);
  pcVar2 = (code *)FUN_00037844(param_1);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(uVar1,0);
  }
  return;
}

/* ==========================================================================
 * FUN_00037508   @ 0x00037508   (44 bytes)
 * called by : FUN_00037534
 * calls     : FUN_00037004, FUN_0003781e, FUN_00037858
 */

void FUN_00037508(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  *(char *)(DAT_000376a4 + 0xe) = (char)param_1;
  uVar1 = FUN_0003781e(param_1);
  uVar2 = FUN_00037004(param_1,uVar1);
  pcVar3 = (code *)FUN_00037858(param_1);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(uVar1,uVar2);
  }
  return;
}

/* ==========================================================================
 * FUN_00037534   @ 0x00037534   (202 bytes)
 * called by : FUN_000375fe
 * calls     : FUN_000374e2, FUN_00037508, _USB_macro2, dbg_printf
 * string    : "BIT(0) f_usb_suspend =1------------\r\n"
 * string    : "BIT(1) f_usb_suspend =0------------\r\n"
 * string    : "BIT(2)bus reset ------------f_usb_isConnected ==%d\r\n"
 */

void FUN_00037534(uint param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_2 & 1) == 0) {
    uVar4 = 1;
    do {
      uVar3 = 1 << (uVar4 & 0xff);
      if ((uVar3 & param_2) != 0) {
        FUN_000374e2(uVar4);
      }
      if ((uVar3 & param_1) != 0) {
        FUN_00037508(uVar4);
      }
      puVar2 = DAT_000376b0;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x10);
    if (param_3 != 0) {
      if ((param_3 & 1) != 0) {
        *DAT_000376b0 = 1;
        dbg_printf(str_BIT_0_f_usb_suspend_1);
        puVar1 = DAT_000376a4;
        DAT_000376a4[1] = 1;
        puVar1[0xf] = 0;
        (*(code *)*DAT_000376dc)();
      }
      if ((int)(param_3 << 0x1e) < 0) {
        *puVar2 = 0;
        dbg_printf(str_BIT_1_f_usb_suspend_0);
        puVar1 = DAT_000376a4;
        DAT_000376a4[1] = 0;
        puVar1[0xf] = 1;
      }
      if ((int)(param_3 << 0x1d) < 0) {
        *DAT_00037708 = 0;
        *DAT_0003770c = 0;
        *DAT_00037710 = 1;
        dbg_printf(str_BIT_2_bus_reset_f_usb_isConnected_d,*DAT_00037714);
        *DAT_00037750 = 1;
        *DAT_00037754 = 1;
        *DAT_00037758 = 0;
        *DAT_0003775c = 0;
        *DAT_00037760 = 0;
        *DAT_00037764 = 0;
        *puVar2 = 0;
        *DAT_00037768 = 0;
        *DAT_000376a4 = 0;
        *DAT_0003776c = 0;
        *DAT_00037770 = 0;
        return;
      }
    }
  }
  else {
    _USB_macro2();
    if (*DAT_000376a8 != 0) {
      *DAT_000376a8 = 0x41;
    }
    if (*DAT_000376ac != '\0') {
      *DAT_000376ac = '\n';
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00037774   @ 0x00037774   (38 bytes)
 * called by : rxcsr2
 */

byte * FUN_00037774(byte *param_1,int param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  pbVar1 = param_1;
  while( true ) {
    if (param_2 <= (int)pbVar1 - (int)param_1) {
      return (byte *)0x0;
    }
    if ((pbVar1[1] == param_3) && (iVar2 = iVar2 + 1, param_4 == iVar2)) break;
    pbVar1 = pbVar1 + *pbVar1;
  }
  return pbVar1;
}

/* ==========================================================================
 * FUN_0003781e   @ 0x0003781e   (18 bytes)
 * called by : FUN_00037508
 */

undefined4 FUN_0003781e(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(DAT_00037bf0 + param_1 * 0x18);
}

/* ==========================================================================
 * FUN_00037830   @ 0x00037830   (20 bytes)
 * called by : FUN_000374e2
 */

undefined4 FUN_00037830(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(param_1 * 0x18 + DAT_00037bf0 + 8);
}

/* ==========================================================================
 * FUN_00037844   @ 0x00037844   (20 bytes)
 * called by : FUN_000374e2
 */

undefined4 FUN_00037844(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(param_1 * 0x18 + DAT_00037bf0 + 0x10);
}

/* ==========================================================================
 * FUN_00037858   @ 0x00037858   (20 bytes)
 * called by : FUN_00037508
 */

undefined4 FUN_00037858(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(param_1 * 0x18 + DAT_00037bf0 + 0x14);
}

/* ==========================================================================
 * FUN_00037878   @ 0x00037878   (66 bytes)
 * called by : rxcsr2
 * calls     : FUN_00042a20, FUN_00042a74, dbg_printf
 * string    : "ep%d RX Buf=0x%.8x\r\n"
 * string    : "Can't malloc RX Buf\r\n"
 */

void FUN_00037878(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_00037bf0;
  if (param_1 < 6) {
    iVar3 = param_1 * 0x18;
    *(undefined4 *)(iVar3 + DAT_00037bf0 + 4) = 0;
    if (*(int *)(iVar1 + iVar3) != 0) {
      FUN_00042a20();
      *(undefined4 *)(iVar1 + iVar3) = 0;
    }
    iVar2 = FUN_00042a74(param_2);
    *(int *)(iVar1 + iVar3) = iVar2;
    if (iVar2 == 0) {
      dbg_printf(str_Can_t_malloc_RX_Buf);
      return;
    }
    dbg_printf(str_ep_d_RX_Buf_0x_8x,param_1);
  }
  return;
}

/* ==========================================================================
 * FUN_000378ba   @ 0x000378ba   (64 bytes)
 * called by : rxcsr2
 * calls     : FUN_00042a20, FUN_00042a74, dbg_printf
 * string    : "ep%d TX Buf=0x%.8x\r\n"
 * string    : "Can't malloc TX Buf\r\n"
 */

void FUN_000378ba(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 6) {
    iVar2 = param_1 * 0x18 + DAT_00037bf0;
    if (*(int *)(iVar2 + 8) != 0) {
      FUN_00042a20();
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
    iVar1 = FUN_00042a74(param_2);
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 == 0) {
      dbg_printf(str_Can_t_malloc_TX_Buf);
      return;
    }
    dbg_printf(str_ep_d_TX_Buf_0x_8x,param_1);
  }
  return;
}

/* ==========================================================================
 * rxcsr2   @ 0x000378fa   (360 bytes)
 * called by : pcfg
 * calls     : FUN_00036fe6, FUN_00037774, FUN_00037878, FUN_000378ba, dbg_printf
 * string    : "endp=%.2x\r\n"
 * string    : "rxp=%.2x\r\n"
 * string    : "txp=%.2x\r\n"
 * string    : "maxp=%.2x\r\n"
 * string    : "csr0=%.2x\r\n"
 * string    : "csr02=%.2x\r\n"
 * string    : "rxcsr1=%.2x\r\n"
 * string    : "rxcsr2=%.2x\r\n"
 * string    : "rxie1=%.2x\r\n"
 * string    : "rxie2=%.2x\r\n"
 * string    : "txie1=%.2x\r\n"
 * string    : "txie2=%.2x\r\n"
 */

undefined8 rxcsr2(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_20;
  
  iVar1 = DAT_00037c58;
  iVar5 = 1;
  iVar4 = 0;
  while (iVar2 = FUN_00037774(param_1,param_2,5,iVar5), iVar2 != 0) {
    iVar4 = iVar4 + 1;
    FUN_00036fe6(*(byte *)(iVar2 + 2) & 0xf);
    if ((int)((uint)*(byte *)(iVar2 + 2) << 0x18) < 0) {
      *(char *)(iVar1 + 0x10) = (char)(*(ushort *)(iVar2 + 4) >> 3);
      *(undefined1 *)(iVar1 + 0x12) = 0x20;
      *(undefined1 *)(iVar1 + 0x11) = 8;
      if ((*(byte *)(iVar2 + 3) & 3) == 1) {
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 0x40;
      }
      uVar3 = (uint)*(byte *)(iVar2 + 2);
      if ((int)(uVar3 << 0x1c) < 0) {
        *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) | (byte)(1 << (uVar3 & 7));
      }
      else {
        *(byte *)(iVar1 + 7) = *(byte *)(iVar1 + 7) | (byte)(1 << (uVar3 & 7));
      }
      FUN_000378ba(*(byte *)(iVar2 + 2) & 0xf,*(undefined2 *)(iVar2 + 4));
    }
    else {
      *(char *)(iVar1 + 0x13) = (char)(*(ushort *)(iVar2 + 4) >> 3);
      *(undefined1 *)(iVar1 + 0x12) = 0;
      *(undefined1 *)(iVar1 + 0x15) = 0;
      if ((*(byte *)(iVar2 + 3) & 3) == 1) {
        *(byte *)(iVar1 + 0x15) = *(byte *)(iVar1 + 0x15) | 0x40;
      }
      *(undefined1 *)(iVar1 + 0x14) = 0x80;
      uVar3 = (uint)*(byte *)(iVar2 + 2);
      if ((int)(uVar3 << 0x1c) < 0) {
        *(byte *)(iVar1 + 10) = *(byte *)(iVar1 + 10) | (byte)(1 << (uVar3 & 7));
      }
      else {
        *(byte *)(iVar1 + 9) = *(byte *)(iVar1 + 9) | (byte)(1 << (uVar3 & 7));
      }
      FUN_00037878(*(byte *)(iVar2 + 2) & 0xf,*(undefined2 *)(iVar2 + 4));
    }
    iVar5 = iVar5 + 1;
    dbg_printf(str_endp_2x,*(undefined1 *)(iVar2 + 2));
    dbg_printf(str_rxp_2x,*(undefined1 *)(iVar1 + 0x13));
    dbg_printf(str_txp_2x,*(undefined1 *)(iVar1 + 0x10));
    dbg_printf(str_maxp_2x,*(undefined2 *)(iVar2 + 4));
    dbg_printf(str_csr0_2x,*(undefined1 *)(iVar1 + 0x11));
    dbg_printf(str_csr02_2x,*(undefined1 *)(iVar1 + 0x12));
    dbg_printf(str_rxcsr1_2x,*(undefined1 *)(iVar1 + 0x14));
    dbg_printf(str_rxcsr2_2x,*(undefined1 *)(iVar1 + 0x15));
  }
  dbg_printf(str_rxie1_2x,*(undefined1 *)(iVar1 + 9));
  dbg_printf(str_rxie2_2x,*(undefined1 *)(iVar1 + 10));
  dbg_printf(str_txie1_2x,*(undefined1 *)(iVar1 + 7));
  dbg_printf(str_txie2_2x,*(undefined1 *)(iVar1 + 8));
  *PTR_DAT_00037d08 = 1;
  *PTR_DAT_00037d0c = 1;
  *PTR_DAT_00037d10 = 1;
  *PTR_DAT_00037d14 = 1;
  return CONCAT44(uStack_20,iVar4);
}

/* ==========================================================================
 * pcfg   @ 0x00037a62   (38 bytes)
 * calls     : FUN_00038350, FUN_0004245e, dbg_printf, rxcsr2
 * string    : "pcfg=0x%.8x\r\n"
 */

void pcfg(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00038350();
  dbg_printf(str_pcfg_0x_8x,iVar1);
  uVar2 = FUN_0004245e(iVar1 + 4);
  uVar3 = FUN_0004245e(iVar1);
  rxcsr2(uVar3,uVar2);
  return;
}

/* ==========================================================================
 * FUN_00037ab6   @ 0x00037ab6   (16 bytes)
 * calls     : FUN_000370c6
 */

void FUN_00037ab6(undefined4 param_1,int param_2)

{
  FUN_000370c6(0);
  *(undefined1 *)(param_2 + 0xe) = 5;
  return;
}

/* ==========================================================================
 * FUN_00037ac6   @ 0x00037ac6   (52 bytes)
 * called by : FUN_00037b0a, HID_RQT_Get_Protocol
 * calls     : FUN_00042472
 */

void FUN_00037ac6(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = *(ushort *)(param_2 + 6);
  *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(DAT_00037bf4 + 1);
  *(undefined1 *)(param_1 + 0xd) = 0;
  FUN_00042472(param_3,param_1);
  if (uVar1 < param_4) {
    uVar2 = (undefined1)(uVar1 >> 8);
    *(char *)(param_1 + 8) = (char)uVar1;
  }
  else {
    uVar2 = (undefined1)(param_4 >> 8);
    *(char *)(param_1 + 8) = (char)param_4;
  }
  *(undefined1 *)(param_1 + 9) = uVar2;
  *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 1;
  return;
}

/* ==========================================================================
 * FUN_00037afa   @ 0x00037afa   (8 bytes)
 * called by : HID_RQT_Get_Protocol
 */

byte FUN_00037afa(byte *param_1)

{
  return *param_1 & 0x1f;
}

/* ==========================================================================
 * FUN_00037b0a   @ 0x00037b0a   (92 bytes)
 * calls     : FUN_000370c6, FUN_00037104, FUN_00037ac6
 */

void FUN_00037b0a(byte *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1 & 0x1f;
  if ((*param_1 & 0x1f) == 0) {
    iVar2 = DAT_00037bf4 + 0xc;
  }
  else if (bVar1 == 1) {
    iVar2 = DAT_00037bf4 + 0xe;
  }
  else {
    if (bVar1 != 2) goto LAB_00037b5a;
    iVar2 = (param_1[4] & 0xf) * 2 + DAT_00037bf0 + -0xc;
  }
  if (iVar2 != 0) {
    FUN_00037ac6(param_2,param_1,iVar2,2);
    *(undefined1 *)(param_2 + 0xe) = 1;
    FUN_00037104(0,param_2);
    return;
  }
LAB_00037b5a:
  *(undefined1 *)(param_2 + 0xe) = 5;
  FUN_000370c6(0);
  return;
}

/* ==========================================================================
 * f_usb_remote_wakeup   @ 0x00037b66   (138 bytes)
 * calls     : FUN_000370d0, dbg_printf
 * string    : "CLEAR_FEATURE rcp=%x\r\n"
 * string    : "f_usb_remote_wakeup =========0 clear %x,%x,%x,%x\r\n"
 */

void f_usb_remote_wakeup(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  
  bVar1 = *param_1;
  bVar3 = bVar1 & 0x1f;
  dbg_printf(str_CLEAR_FEATURE_rcp_x,bVar3,param_3,param_4,param_4);
  if ((bVar1 & 0x1f) == 0) {
    if (*(short *)(param_1 + 2) == 1) {
      *(byte *)(DAT_00037bf4 + 0xc) = *(byte *)(DAT_00037bf4 + 0xc) & 0xfd;
      *DAT_00037d40 = 0;
      dbg_printf(str_f_usb_remote_wakeup_0_clear_x_x_x_x,*DAT_00037d50,*DAT_00037d4c,*DAT_00037d48,
                 *DAT_00037d44);
    }
  }
  else if ((bVar3 != 1) && (bVar3 == 2)) {
    pbVar2 = (byte *)((param_1[4] & 0xf) * 2 + DAT_00037bf0 + -0xc);
    if (*(short *)(param_1 + 2) == 0) {
      *pbVar2 = *pbVar2 & 0xfe;
    }
  }
  FUN_000370d0(0);
  *(undefined1 *)(param_2 + 0xe) = 5;
  return;
}

/* ==========================================================================
 * usb_suspend   @ 0x000380a6   (116 bytes)
 * called by : system_mode
 * calls     : FUN_0004245e, FUN_00042472, dbg_printf
 * string    : "usb_suspend =1-----usb_frame_stop_cnt =%d\r\n"
 */

void usb_suspend(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = DAT_00038168;
  cVar1 = *(char *)(DAT_00038234 + 0xc);
  *(char *)(DAT_00038168 + 6) = cVar1;
  if (cVar1 == *(char *)(iVar2 + 7)) {
    if (*DAT_00038238 == 0) {
      iVar3 = FUN_0004245e(iVar2 + 8);
      FUN_00042472(iVar3 + 1,iVar2 + 8);
    }
  }
  else {
    *(char *)(iVar2 + 7) = cVar1;
    FUN_00042472(0,iVar2 + 8);
    *(undefined1 *)(iVar2 + 0xc) = 0;
  }
  uVar4 = FUN_0004245e(iVar2 + 8);
  if ((DAT_0003823c < uVar4) &&
     (((DAT_00038240 < uVar4 || (*PTR_DAT_0003816c != '\0')) || (*DAT_00038244 != '\0')))) {
    dbg_printf(str_usb_suspend_1_usb_frame_stop_cnt_d,uVar4);
    *DAT_00038274 = 1;
    *(undefined1 *)(iVar2 + 0xc) = 1;
    FUN_00042472(0,iVar2 + 8);
  }
  return;
}

/* ==========================================================================
 * usb_suspend_wakeup   @ 0x0003811a   (42 bytes)
 * called by : exist
 * calls     : FUN_000317c2, FUN_00042472, dbg_printf
 * string    : "usb_suspend_wakeup\r\n"
 */

void usb_suspend_wakeup(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = DAT_00038168;
  *(undefined1 *)(DAT_00038168 + 0xc) = 0;
  FUN_00042472(0,iVar1 + 8);
  dbg_printf(str_usb_suspend_wakeup);
  puVar2 = (undefined1 *)(DAT_00038234 + 0x80);
  *puVar2 = 0x21;
  FUN_000317c2(0xd);
  *puVar2 = 9;
  return;
}

/* ==========================================================================
 * FUN_00038296   @ 0x00038296   (20 bytes)
 * called by : exist
 */

void FUN_00038296(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *DAT_00038310 & ~((int)DAT_00038310 << 0xb);
  }
  else {
    uVar1 = *DAT_00038310 | (int)DAT_00038310 << 0xb;
  }
  *DAT_00038310 = uVar1;
  return;
}

/* ==========================================================================
 * FUN_00038350   @ 0x00038350   (6 bytes)
 * called by : pcfg
 */

int FUN_00038350(void)

{
  return DAT_00038394 + 8;
}

/* ==========================================================================
 * FUN_00038384   @ 0x00038384   (54 bytes)
 * calls     : FUN_0004245e
 */

int FUN_00038384(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00038394 + 0x10;
  iVar3 = 0;
  while( true ) {
    if (3 < iVar3) {
      return 0;
    }
    iVar1 = FUN_0004245e(iVar3 * 0xc + iVar2);
    if (iVar1 == param_1) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3 * 0xc + iVar2 + 4;
}

/* ==========================================================================
 * FUN_00038398   @ 0x00038398   (40 bytes)
 * called by : HID_RQT_Get_Protocol
 * calls     : FUN_00042472
 */

void FUN_00038398(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)(param_2 + 6);
  *(undefined1 *)(param_1 + 0xc) = *DAT_000385a4;
  *(undefined1 *)(param_1 + 0xd) = 0;
  FUN_00042472(param_3,param_1 + 4);
  *(char *)(param_1 + 10) = (char)uVar1;
  *(char *)(param_1 + 0xb) = (char)((ushort)uVar1 >> 8);
  *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 2;
  return;
}

/* ==========================================================================
 * HID_RQT_Get_Protocol   @ 0x000383c0   (482 bytes)
 * called by : FUN_00038072
 * calls     : FUN_000370c6, FUN_000370d0, FUN_000370ec, FUN_00037104, FUN_00037ac6, FUN_00037afa, ... (+5 more)
 * string    : "set idle! %x,%x\r\n"
 * string    : "Get_idle_length %x,%x\rin"
 * string    : "HID_RQT_Get_Report:"
 * string    : "HID_RQT_Set_Report:"
 * string    : "HID_RQT_Set_Protocol:"
 * string    : "HID_RQT_Get_Protocol:"
 */

void HID_RQT_Get_Protocol(int param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 uVar10;
  
  uVar8 = FUN_00037afa(param_1);
  pbVar5 = DAT_000385b4;
  iVar3 = DAT_000385b0;
  pbVar9 = DAT_000385ac;
  puVar2 = DAT_000385a8;
  if ((uVar8 < 3) && (uVar8 != 0)) {
    if (uVar8 == 1) {
      cVar1 = *(char *)(param_1 + 4);
      if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
        cVar1 = *(char *)(param_1 + 1);
        if (cVar1 == '\n') {
          *DAT_000385a8 = 1;
          *pbVar9 = *(byte *)(param_1 + 3);
          dbg_printf(str_set_idle_x_x,*(undefined1 *)(param_1 + 2));
        }
        else {
          if (cVar1 == '\x02') {
            dbg_printf(str_Get_idle_length_x_x_in,*(undefined1 *)(param_1 + 6),*DAT_000385ac);
            pbVar9 = DAT_000385ac;
            uVar10 = 1;
            *puVar2 = 1;
LAB_00038490:
            FUN_00037ac6(param_2,param_1,pbVar9,uVar10);
            *(undefined1 *)(param_2 + 0xe) = 1;
            FUN_00037104(0,param_2);
            return;
          }
          if (cVar1 == '\x01') {
            dbg_printf_2(str_HID_RQT_Get_Report,param_1,8);
            pbVar9 = DAT_0003860c;
            pcVar6 = DAT_000385fc;
            cVar1 = *(char *)(param_1 + 2);
            if (cVar1 == -0x60) {
              *DAT_0003860c = 0xa0;
              if (*pcVar6 == '\0') {
                pbVar9[1] = 0;
              }
              else {
                pbVar9[1] = 1;
              }
              pbVar9[2] = 0;
              pbVar9[3] = 0;
              pbVar9[4] = 0;
              pbVar9[5] = 0;
              pbVar9[6] = 0;
              uVar10 = 8;
              pbVar9[7] = 0;
              pbVar9 = DAT_0003860c;
            }
            else {
              if (*DAT_000385fc == '\0') {
                return;
              }
              *DAT_000385fc = '\0';
              *DAT_00038600 = 1;
              iVar4 = DAT_000385b0;
              *(char *)(DAT_000385b0 + -7) = cVar1;
              *DAT_00038604 = *(undefined1 *)(param_1 + 4);
              puVar2 = DAT_00038608;
              *DAT_00038608 = *(undefined1 *)(param_1 + 6);
              *(int *)(iVar4 + -5) = iVar3;
              rom_24F9C(DAT_0003860c,iVar3);
              uVar10 = *puVar2;
              pbVar9 = DAT_0003860c;
            }
            goto LAB_00038490;
          }
          if (cVar1 == '\t') {
            dbg_printf_2(str_HID_RQT_Set_Report,param_1,8);
            iVar4 = DAT_000385b0;
            if ((*(char *)(param_1 + 3) == '\x03') && (*(char *)(param_1 + 4) == '\x02')) {
              if (*(char *)(param_1 + 2) == -0x60) {
                *(undefined1 *)(DAT_000385b0 + -8) = 2;
                *DAT_00038608 = *(undefined1 *)(param_1 + 6);
                *DAT_00038628 = iVar3;
              }
              else {
                *(undefined1 *)(DAT_000385b0 + -8) = 1;
                *(undefined1 *)(iVar4 + -7) = *(undefined1 *)(param_1 + 2);
                *(undefined1 *)(iVar4 + -6) = *(undefined1 *)(param_1 + 6);
                if (*DAT_00038624 == '\0') {
                  *(int *)(iVar4 + -5) = iVar3;
                }
              }
              *DAT_0003862c = 0x3c;
            }
            *DAT_00038630 = 0xf;
            OLED_Init();
            FUN_00038398(param_2,param_1,DAT_0003860c + -0x85,*DAT_00038608);
            FUN_000370ec(0);
            *(undefined1 *)(param_2 + 0xe) = 2;
            return;
          }
          if (cVar1 != '\v') {
            if (cVar1 == '\x03') {
              dbg_printf_2(str_HID_RQT_Get_Protocol,param_1,8);
              pbVar9 = DAT_000385b4;
              if (*DAT_00038650 == '\0') {
                bVar7 = *pbVar5 & 0xfe;
              }
              else {
                bVar7 = *pbVar5 | 1;
              }
              uVar10 = 1;
              *pbVar5 = bVar7;
              goto LAB_00038490;
            }
            goto LAB_00038576;
          }
          dbg_printf_2(str_HID_RQT_Set_Protocol,param_1,8);
          *DAT_0003864c = 1;
          bVar7 = *(byte *)(param_1 + 2);
          *pbVar5 = bVar7;
          if ((bVar7 & 1) == 0) {
            *DAT_00038650 = '\0';
          }
          else {
            *DAT_00038650 = '\x01';
          }
        }
        *(undefined1 *)(param_2 + 0xe) = 4;
LAB_00038576:
        FUN_000370d0(0);
        return;
      }
    }
    else if (uVar8 != 2) {
      return;
    }
    *(undefined1 *)(param_2 + 0xe) = 5;
  }
  FUN_000370c6(0);
  return;
}

/* ==========================================================================
 * FUN_0003870a   @ 0x0003870a   (556 bytes)
 * called by : system_mode
 * calls     : FUN_00031244, FUN_000312aa, FUN_00037186, rom_24F9C, rom_24FEC, time_sensor_invalid
 */

void FUN_0003870a(void)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  short *psVar11;
  short *psVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined4 uVar16;
  undefined4 in_r3;
  
  pcVar3 = DAT_00038aa0;
  if (*DAT_00038a8c == '\0') {
    return;
  }
  if (*DAT_00038a90 != 0) {
    return;
  }
  if (*DAT_00038a94 != '\0') {
    return;
  }
  if (*DAT_00038a98 != '\0') {
    return;
  }
  if (*DAT_00038a9c == '\b') {
    *DAT_00038a9c = '\a';
    *DAT_00038aa4 = '\x01';
    pcVar4 = DAT_00038aa8;
    *pcVar3 = '\x01';
    *pcVar4 = '\x01';
    *DAT_00038aac = '\x01';
  }
  if (*(char *)(DAT_00038ab0 + 0x16) != '\x01') {
    if (*DAT_00038ab4 == '\0') {
      return;
    }
    *DAT_00038ab4 = '\0';
  }
  pbVar5 = DAT_00038ab8;
  if ((*pcVar3 - 1U & *DAT_00038ab8) == 0) {
    time_sensor_invalid();
  }
  pcVar10 = DAT_00038b04;
  pcVar9 = DAT_00038ae0;
  pcVar8 = DAT_00038adc;
  pcVar7 = DAT_00038ad8;
  pcVar6 = DAT_00038acc;
  puVar15 = DAT_00038ac0;
  pcVar4 = DAT_00038abc;
  if (*DAT_00038abc == '\0') {
    if ((*DAT_00038aac == '\0') || (*DAT_00038acc == '\0')) {
      if ((*DAT_00038aa8 == '\0') ||
         ((((*DAT_00038ad4 == '\0' && (*DAT_00038ad8 == '\0')) && (*DAT_00038adc == '\0')) &&
          (*DAT_00038ae0 == '\0')))) {
        if ((((*DAT_00038af4 == '\0') && (*DAT_00038af8 == '\0')) && (*DAT_00038afc == '\0')) &&
           (*DAT_00038b00 == '\0')) {
          return;
        }
        if ((*pcVar3 == '\0') && (*pbVar5 != 0)) {
          return;
        }
        *pcVar3 = '\0';
        psVar12 = DAT_00038b10;
        psVar11 = DAT_00038b0c;
        puVar14 = DAT_00038b08;
        if (*pcVar10 == '\0') {
          if ((-1 < *DAT_00038b0c * 0x10000) && ((int)*DAT_00038b0c << 0x18 < 0)) {
            *DAT_00038b0c = 0x7f;
          }
          if ((-1 < (int)*psVar12 << 0x10) && ((int)*psVar12 << 0x18 < 0)) {
            *psVar12 = 0x7f;
          }
          uVar16 = 3;
          *puVar15 = *puVar14;
          puVar15[1] = (char)*psVar11;
          puVar15[2] = (char)*psVar12;
        }
        else {
          FUN_00031244();
          *puVar15 = *puVar14;
          sVar2 = *psVar11;
          puVar15[1] = (char)sVar2;
          puVar15[2] = (char)((ushort)sVar2 >> 8);
          sVar2 = *psVar12;
          puVar15[3] = (char)sVar2;
          puVar15[4] = (char)((ushort)sVar2 >> 8);
          uVar16 = 7;
          puVar15[5] = *DAT_00038b14;
          puVar15[6] = *DAT_00038b18;
        }
        FUN_00037186(2,DAT_00038ac0,uVar16);
        FUN_000312aa();
        return;
      }
      *DAT_00038aa8 = '\0';
      if (*DAT_00038ad4 == '\0') {
        if (*pcVar7 == '\0') {
          cVar1 = *pcVar8;
          if (cVar1 == '\0') {
            if (*pcVar9 == '\0') {
              return;
            }
            *pcVar9 = '\0';
            *puVar15 = 3;
            rom_24F9C(puVar15 + 1,DAT_00038af0,4,0,in_r3);
            FUN_00037186(3,DAT_00038ac0,5);
            uVar16 = DAT_00038af0;
          }
          else {
            *pcVar8 = '\0';
            *puVar15 = 3;
            rom_24F9C(puVar15 + 1,DAT_00038aec,4,cVar1,in_r3);
            FUN_00037186(3,DAT_00038ac0,5);
            uVar16 = DAT_00038aec;
          }
          rom_24FEC(uVar16,4);
        }
        else {
          *pcVar7 = '\0';
          *puVar15 = 1;
          puVar14 = DAT_00038ae8;
          puVar15 = DAT_00038ac0;
          DAT_00038ac0[1] = *DAT_00038ae8;
          FUN_00037186(3,puVar15,2);
          *puVar14 = 0;
        }
        goto LAB_000387ce;
      }
      *DAT_00038ad4 = '\0';
      puVar14 = DAT_00038ae4;
      *puVar15 = 2;
      puVar15 = DAT_00038ac0;
      DAT_00038ac0[1] = *puVar14;
      uVar13 = 3;
      puVar15[2] = puVar14[1];
      uVar16 = uVar13;
    }
    else {
      *DAT_00038aac = '\0';
      *pcVar6 = '\0';
      rom_24F9C(DAT_00038ac0,DAT_00038ad0,0xe);
      uVar13 = 4;
      puVar15 = DAT_00038ac0;
      uVar16 = 0xe;
    }
  }
  else {
    if ((*DAT_00038aa4 == '\0') && (*DAT_00038ac4 != '\0')) {
      return;
    }
    *DAT_00038aa4 = '\0';
    *pcVar4 = '\0';
    puVar14 = DAT_00038ac8 + 1;
    *puVar15 = *DAT_00038ac8;
    puVar15[1] = 0;
    rom_24F9C(puVar15 + 2,puVar14,6);
    uVar13 = 1;
    puVar15 = DAT_00038ac0;
    uVar16 = 8;
  }
  FUN_00037186(uVar13,puVar15,uVar16);
LAB_000387ce:
  rom_24FEC(DAT_00038ac0,0x40);
  return;
}

/* ==========================================================================
 * FUN_00038936   @ 0x00038936   (56 bytes)
 * called by : exist
 * calls     : FUN_00031784
 */

undefined4 FUN_00038936(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  
  iVar1 = DAT_00038b1c;
  bVar3 = 0;
  cVar2 = '\n';
  while (cVar2 != '\0') {
    if ((*(uint *)(iVar1 + 0x30) & 1) == 0) {
      bVar3 = bVar3 + 1;
    }
    FUN_00031784(500);
    cVar2 = cVar2 + -1;
  }
  if (5 < bVar3) {
    return 1;
  }
  return 0;
}

/* ==========================================================================
 * exist   @ 0x0003896e   (488 bytes)
 * called by : system_mode
 * calls     : FUN_0002b128, FUN_0002b382, FUN_0002bcac, FUN_00031230, FUN_000312aa, FUN_000312de, ... (+22 more)
 * string    : "USB sleep_wakeup  f_usb_suspend=%x, f_usb_idle=%x,%x\r\n"
 * string    : "enter sleep........%x,%x,%x,%x,%x\r\n"
 * string    : "exist sleep........%x,%x,%x,%x,%x\r\n"
 */

void exist(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  byte bVar10;
  
  if (((*DAT_00038a8c != '\0') && (iVar6 = FUN_0002b128(), iVar6 == 0)) && (*DAT_00038b20 != '\0'))
  {
    *DAT_00038b20 = '\0';
    dbg_printf(str_USB_sleep_wakeup_f_usb_suspend_x_f_usb_idle,*DAT_00038a98,*DAT_00038b24,
               *DAT_00038a9c,param_2,param_3,param_4);
    FUN_0003afa2(1);
    FUN_000317c2(10);
    *DAT_00038b08 = 0;
    FUN_000312aa();
    FUN_000312de();
    FUN_00031230();
    FUN_0003297e();
    *DAT_00038b60 = 1;
    if (*(char *)(DAT_00038ab0 + 8) == '\0') {
      sensor_pwdn();
    }
    FUN_00033cfc();
    FUN_0003bf0a();
    FUN_0003c286(1);
    FUN_0003b528();
    *DAT_00038b68 = *DAT_00038b64;
    *DAT_00038b6c = '\0';
    do {
      puVar4 = DAT_00038b64;
      puVar3 = DAT_00038b24;
      puVar2 = DAT_00038a98;
      puVar1 = PTR_DAT_00038a68;
      dbg_printf(str_enter_sleep_x_x_x_x_x,*DAT_00038b64,*DAT_00038a98,*DAT_00038b24,*DAT_00038b70,
                 *PTR_DAT_00038a68);
      FUN_00038296(0);
      *DAT_00038b98 = 1;
      FUN_0002bcac();
      FUN_0003af8a();
      FUN_0003bf0a();
      FUN_0002b382();
      FUN_00038296(1);
      dbg_printf(str_exist_sleep_x_x_x_x_x,*puVar4,*puVar2,*puVar3,*DAT_00038b70,*puVar1);
      FUN_00031784(200);
      sVar9 = 400;
      uVar7 = FUN_0003725e();
      pcVar5 = DAT_00038b6c;
      uVar7 = uVar7 & 0xffff;
      bVar10 = 0x97;
      while (sVar9 = sVar9 + -1, sVar9 != 0) {
        if (((*DAT_00038f84 << 3 < 0) || ((*(uint *)(DAT_00038f88 + 0x30) & 1) == 0)) &&
           (iVar6 = FUN_00038936(), iVar6 != 0)) {
          FUN_0003b130();
        }
        if (*pcVar5 != '\0') break;
        FUN_000317c2(0x24);
        uVar8 = FUN_0003725e();
        if (uVar8 == uVar7) {
          if (*DAT_00038f90 != '\0') {
            if (bVar10 < 0x95) {
              sVar9 = 0;
              break;
            }
            usb_suspend_wakeup();
            *DAT_00038f94 = 0x50;
            FUN_000317c2(100);
            rom_24FEC(DAT_00038f98,0x40);
            FUN_00037186(2,DAT_00038f98,7);
          }
        }
        else {
          uVar7 = FUN_0003725e();
          bVar10 = bVar10 - 1;
          uVar7 = uVar7 & 0xffff;
          if ((bVar10 == 0) || ((*DAT_00038f8c != '\0' && (bVar10 < 0x8d)))) break;
        }
      }
      if (*pcVar5 != '\0') {
        *DAT_00038f94 = 300;
        *DAT_00038f9c = 200;
        break;
      }
    } while (sVar9 == 0);
    FUN_0003afa2(5);
    FUN_000317c2(5);
    *DAT_00038fa0 = 0;
    FUN_0003c2c6();
    FUN_000317c2(1);
    FUN_0003beb4();
    FUN_0003b538(DAT_00038fa4);
    *DAT_00038fa8 = 0;
    *DAT_00038fac = 0;
    OLED_Init();
    *DAT_00038fb0 = 8;
    pcVar5 = DAT_00038fb4;
    if (*DAT_00038fb4 == '\0') {
      *DAT_00038fb8 = 1;
      *DAT_00038fbc = 1;
      *DAT_00038fc0 = 1;
    }
    *pcVar5 = '\0';
  }
  return;
}

/* ==========================================================================
 * test   @ 0x00038cb6   (26 bytes)
 * called by : system_mode
 * calls     : FUN_0003b130, dbg_printf
 * string    : "test-zzl usb soft pull out then insert in\r\n"
 */

void test(void)

{
  if (*DAT_00038f9c == 1) {
    *DAT_00038f9c = 0;
    dbg_printf(str_test_zzl_usb_soft_pull_out_then_insert_in);
    FUN_0003b130();
  }
  return;
}

/* ==========================================================================
 * get_usb_insert_status   @ 0x00038cd0   (78 bytes)
 * called by : SLEEP, USNDP_status_2, enter_BLE_normal_app_mode, gpio
 * calls     : FUN_00031784, dbg_printf
 * string    : "get_usb_insert_status"
 * string    : "%s,USB_In =%x\r\n"
 */

undefined4 get_usb_insert_status(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00038f88;
  uVar2 = 0;
  *(undefined4 *)(DAT_00038f88 + 0x30) = 0x2c;
  FUN_00031784(0xfa);
  if (((((*(uint *)(iVar1 + 0x30) & 1) != 0) &&
       (FUN_00031784(0xfa), (*(uint *)(iVar1 + 0x30) & 1) != 0)) &&
      (FUN_00031784(0xfa), (*(uint *)(iVar1 + 0x30) & 1) != 0)) &&
     (FUN_00031784(0xfa), (*(uint *)(iVar1 + 0x30) & 1) != 0)) {
    uVar2 = 1;
    dbg_printf(str_s_USB_In_x,DAT_00038ff0,*(uint *)(iVar1 + 0x30) & 1);
  }
  return uVar2;
}

/* ==========================================================================
 * USNDP_status   @ 0x00038d1e   (134 bytes)
 * called by : SLEEP, USNDP_status_2, f_usb_isConnected
 * calls     : FUN_00031784, FUN_00039a84, FUN_00039ad8, dbg_printf
 * string    : "USBDN=:%x\r\n"
 * string    : "USNDP_status=:%x,USB_OTG_CFG=:%x,%x\r\n"
 */

undefined4 USNDP_status(void)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  byte bVar5;
  
  puVar1 = DAT_00039004;
  bVar5 = 0;
  *DAT_00039004 = 0;
  dbg_printf(str_USBDN_x);
  FUN_00039a84(0,0);
  FUN_00031784(5);
  do {
    uVar2 = FUN_00039ad8(0);
    puVar4 = (uint *)(DAT_00038f88 + -0x40);
    if (((((*puVar4 & 1) == 0) || ((*puVar4 & 1) == 0)) || ((*puVar4 & 1) == 0)) ||
       ((*puVar4 & 1) == 0)) {
      uVar2 = 0;
      FUN_00031784(5);
    }
    FUN_00031784(5);
    uVar3 = *puVar4;
    dbg_printf(str_USNDP_status_x_USB_OTG_CFG_x_x,uVar2,*puVar1,bVar5);
    bVar5 = bVar5 + 1;
  } while ((uVar2 != (uVar3 & 1)) && (bVar5 < 10));
  FUN_00039a84(0,0,1);
  if (uVar2 != 0) {
    return 1;
  }
  return 0;
}

/* ==========================================================================
 * FUN_00039ad8   @ 0x00039ad8   (24 bytes)
 * called by : USNDP_status
 */

uint FUN_00039ad8(uint param_1)

{
  return *(uint *)(PTR_DAT_00039c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4) & 1;
}

/* ==========================================================================
 * FUN_00039c84   @ 0x00039c84   (60 bytes)
 * called by : fn24main
 */

void FUN_00039c84(void)

{
  int iVar1;
  
  iVar1 = DAT_0003a008;
  *(uint *)(DAT_0003a008 + 8) = *(uint *)(DAT_0003a008 + 8) & 0xf7ffffff;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x4000;
  *(undefined4 *)(DAT_0003a00c + 8) = *(undefined4 *)(iVar1 + 8);
  iVar1 = DAT_0003a00c;
  *(undefined4 *)(DAT_0003a00c + 0xb0) = DAT_0003a010;
  *(undefined4 *)(iVar1 + 0xb4) = DAT_0003a014;
  iVar1 = DAT_0003a00c;
  *(uint *)(DAT_0003a00c + 0xe8) = *(uint *)(DAT_0003a00c + 0xe8) | 0x4000;
  *(uint *)(iVar1 + 0xec) = *(uint *)(iVar1 + 0xec) & 0xfffffff3;
  return;
}

/* ==========================================================================
 * FUN_00039cfc   @ 0x00039cfc   (42 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, cal_data
 * calls     : FUN_0003e552
 */

uint FUN_00039cfc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),1);
  local_10 = param_3;
  iVar1 = FUN_0003e552(10,&local_c,&local_10);
  uVar2 = 0x35;
  if ((iVar1 == 0) && ((local_10 & 0xff) - 0x16 < 0x3f)) {
    uVar2 = local_10 & 0xff;
  }
  return uVar2;
}

/* ==========================================================================
 * FUN_00039d26   @ 0x00039d26   (22 bytes)
 * called by : TEST_SINGLE_WAVE_2
 * calls     : FUN_0003e5f0
 */

void FUN_00039d26(int param_1)

{
  if (param_1 - 0x16U < 0x3f) {
    FUN_0003e5f0(10,1);
  }
  return;
}

/* ==========================================================================
 * FUN_00039d3c   @ 0x00039d3c   (24 bytes)
 * called by : cal_data
 */

void FUN_00039d3c(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_0003a008;
  if (0x7f < param_1) {
    param_1 = 0x7f;
  }
  *(uint *)(DAT_0003a008 + 0xc) = param_1 << 0xc | DAT_0003a020;
  *(undefined4 *)(DAT_0003a00c + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  return;
}

/* ==========================================================================
 * FUN_00039dfe   @ 0x00039dfe   (40 bytes)
 * called by : cal_data
 * calls     : FUN_000317c2
 */

void FUN_00039dfe(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0003a008;
  *(uint *)(DAT_0003a008 + 0x78) = *(uint *)(DAT_0003a008 + 0x78) | 0x20000;
  iVar2 = DAT_0003a00c;
  *(undefined4 *)(DAT_0003a00c + 0x78) = *(undefined4 *)(iVar1 + 0x78);
  FUN_000317c2(2);
  *(uint *)(iVar1 + 0x78) = *(uint *)(iVar1 + 0x78) & 0xfffdffff;
  *(undefined4 *)(iVar2 + 0x78) = *(undefined4 *)(iVar1 + 0x78);
  return;
}

/* ==========================================================================
 * value_kcal_result   @ 0x00039e26   (444 bytes)
 * called by : cal_data
 * calls     : FUN_000317c2, KEY_piaring_cnt, dbg_printf, rom_24F24
 * string    : "value_kcal_result=%x\r\n"
 */

void value_kcal_result(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(DAT_0003a00c + 0xc0);
  *puVar4 = *puVar4 & 0xfffffffc;
  *puVar4 = *puVar4 | 8;
  iVar2 = DAT_0003a00c;
  *(uint *)(DAT_0003a00c + 0x90) = *(uint *)(DAT_0003a00c + 0x90) | 0x40000000;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) | 0x80000000;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) & 0xfffdffff;
  FUN_000317c2(10);
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) & 0xffffff80;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) | 2;
  FUN_000317c2(10);
  KEY_piaring_cnt();
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) | 0x1000;
  FUN_000317c2(10);
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) | 0x2000;
  FUN_000317c2(10);
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) | 0x800;
  FUN_000317c2(10);
  KEY_piaring_cnt();
  iVar1 = DAT_0003a008;
  *(uint *)(DAT_0003a008 + 0xc) = *(uint *)(DAT_0003a008 + 0xc) & 0xffffffbf;
  *(undefined4 *)(DAT_0003a00c + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  FUN_000317c2(10);
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x80;
  *(undefined4 *)(DAT_0003a00c + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  FUN_000317c2(10);
  KEY_piaring_cnt();
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) | 0x10000;
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  uVar3 = rom_24F24(&DAT_0001f400,(*(uint *)(DAT_0003a00c + 0x48) & 0x1fffffff) >> 0x10);
  uVar3 = uVar3 & 0x1ff;
  dbg_printf(str_value_kcal_result_x,uVar3);
  *puVar4 = *puVar4 & DAT_0003a05c;
  *puVar4 = *puVar4 | uVar3 << 8;
  *DAT_0003a060 = uVar3;
  FUN_000317c2(10);
  FUN_000317c2(10);
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  FUN_000317c2(10);
  KEY_piaring_cnt();
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) & 0xfffeffff;
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xffffff7f;
  *(undefined4 *)(DAT_0003a00c + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  FUN_000317c2(10);
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x40;
  *(undefined4 *)(DAT_0003a00c + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) & 0xfffff7ff;
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) & 0xffffdfff;
  *(uint *)(iVar2 + 0x94) = *(uint *)(iVar2 + 0x94) & 0xffffefff;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) | 0x20000;
  *puVar4 = *puVar4 | 1;
  *puVar4 = *puVar4 & 0xfffffff7;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) & 0xbfffffff;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) & 0x7fffffff;
  return;
}

/* ==========================================================================
 * cal_data   @ 0x00039fe2   (496 bytes)
 * called by : FUN_0003a244
 * calls     : FUN_00028c48, FUN_000317c2, FUN_00039cfc, FUN_00039d3c, FUN_00039dfe, KEY_piaring_cnt, ... (+3 more)
 * string    : "cal_data============================ %x\r\n"
 */

void cal_data(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  uVar9 = DAT_0003a064;
  puVar2 = DAT_0003a00c;
  *DAT_0003a00c = DAT_0003a064;
  puVar1 = DAT_0003a008;
  *DAT_0003a008 = uVar9;
  iVar8 = FUN_00028c48();
  uVar9 = DAT_0003a468;
  if (iVar8 != 1) {
    uVar9 = DAT_0003a068;
  }
  puVar2[1] = uVar9;
  puVar1[1] = uVar9;
  uVar9 = DAT_0003a46c;
  puVar2[2] = DAT_0003a46c;
  puVar1[2] = uVar9;
  uVar9 = DAT_0003a470;
  puVar2[3] = DAT_0003a470;
  puVar1[3] = uVar9;
  iVar8 = FUN_00028c48();
  uVar9 = DAT_0003a478;
  if (iVar8 != 1) {
    uVar9 = DAT_0003a474;
  }
  puVar2[4] = uVar9;
  puVar1[4] = uVar9;
  uVar9 = DAT_0003a47c;
  puVar2[5] = DAT_0003a47c;
  puVar1[5] = uVar9;
  uVar9 = DAT_0003a480;
  puVar2[6] = DAT_0003a480;
  puVar1[6] = uVar9;
  uVar9 = DAT_0003a484;
  puVar2[7] = DAT_0003a484;
  puVar1[7] = uVar9;
  uVar9 = DAT_0003a488;
  puVar2[8] = DAT_0003a488;
  puVar1[8] = uVar9;
  uVar9 = DAT_0003a48c;
  puVar2[9] = DAT_0003a48c;
  puVar1[9] = uVar9;
  uVar9 = DAT_0003a490;
  puVar2[10] = DAT_0003a490;
  puVar1[10] = uVar9;
  uVar9 = DAT_0003a494;
  puVar2[0xb] = DAT_0003a494;
  puVar1[0xb] = uVar9;
  uVar9 = DAT_0003a498;
  puVar2[0xc] = DAT_0003a498;
  puVar1[0xc] = uVar9;
  uVar9 = DAT_0003a49c;
  puVar2[0xd] = DAT_0003a49c;
  puVar1[0xd] = uVar9;
  uVar9 = DAT_0003a4a0;
  puVar2[0xe] = DAT_0003a4a0;
  puVar1[0xe] = uVar9;
  uVar9 = DAT_0003a4a4;
  puVar2[0xf] = DAT_0003a4a4;
  puVar1[0xf] = uVar9;
  iVar8 = DAT_0003a4ac;
  uVar9 = DAT_0003a4a8;
  *(undefined4 *)(DAT_0003a4ac + 0x30) = DAT_0003a4a8;
  puVar1[0x1c] = uVar9;
  uVar9 = DAT_0003a4b0;
  *(undefined4 *)(iVar8 + 0x34) = DAT_0003a4b0;
  puVar1[0x1d] = uVar9;
  uVar9 = DAT_0003a4b4;
  *(undefined4 *)(iVar8 + 0x38) = DAT_0003a4b4;
  puVar1[0x1e] = uVar9;
  *(undefined4 *)(iVar8 + 0x3c) = 0;
  puVar1[0x1f] = 0;
  iVar3 = DAT_0003a4ac;
  puVar10 = (undefined4 *)(DAT_0003a4ac + 0x40);
  *puVar10 = DAT_0003a4b8;
  *(undefined4 *)(iVar3 + 0x44) = 0x96000000;
  *(undefined4 *)(iVar3 + 0x48) = 0x78000000;
  *(int *)(iVar3 + 0x4c) = (int)puVar10 * 0x400000;
  *(undefined4 *)(iVar3 + 0x50) = DAT_0003a4bc;
  *(undefined4 *)(iVar3 + 0x54) = 0x200000;
  *(undefined4 *)(iVar3 + 0x58) = DAT_0003a4c0;
  *(undefined4 *)(iVar3 + 0x5c) = DAT_0003a4c4;
  *(undefined4 *)(iVar3 + 0x60) = DAT_0003a4c8;
  *(undefined4 *)(iVar3 + 100) = DAT_0003a4cc;
  *(undefined4 *)(iVar3 + 0x68) = DAT_0003a4d0;
  *(undefined4 *)(iVar3 + 0x6c) = 0x408;
  *(undefined4 *)(iVar3 + 0x74) = DAT_0003a4d4;
  uVar11 = (int)puVar10 >> 0xf;
  *(uint *)(iVar3 + 0x78) = uVar11;
  *(undefined4 *)(iVar3 + 0x7c) = 0;
  iVar3 = DAT_0003a4ac;
  *(undefined4 *)(DAT_0003a4ac + 0x80) = DAT_0003a4d8;
  *(undefined4 *)(iVar3 + 0x84) = 0;
  *(undefined4 *)(iVar3 + 0x88) = 0;
  *(undefined4 *)(iVar3 + 0x8c) = 0;
  *(undefined4 *)(iVar3 + 0x90) = 0;
  *(undefined4 *)(iVar3 + 0x94) = 0;
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x9c) = 0;
  *(undefined4 *)(iVar3 + 0xa0) = 0;
  *(undefined4 *)(iVar3 + 0xa4) = 0;
  *(undefined4 *)(iVar3 + 0xa8) = 0x128000;
  *(undefined4 *)(iVar3 + 0xac) = DAT_0003a4dc;
  *(undefined4 *)(iVar3 + 0xb0) = DAT_0003a4e0;
  *(undefined4 *)(iVar3 + 0xb4) = 0;
  *(undefined4 *)(iVar3 + 0xb8) = DAT_0003a4e4;
  *(undefined4 *)(iVar3 + 0xbc) = 0;
  iVar3 = DAT_0003a4ac;
  *(uint *)(DAT_0003a4ac + 0xc0) = uVar11 << 0x10;
  *(undefined4 *)(iVar3 + 0xc4) = DAT_0003a4e8;
  *(undefined4 *)(iVar3 + 200) = DAT_0003a4ec;
  *(undefined4 *)(iVar3 + 0xcc) = DAT_0003a4f0;
  *(undefined4 *)(iVar3 + 0xd0) = DAT_0003a4f4;
  *(undefined4 *)(iVar3 + 0xd4) = DAT_0003a4f8;
  *(undefined4 *)(iVar3 + 0xd8) = DAT_0003a4fc;
  *(undefined4 *)(iVar3 + 0xdc) = DAT_0003a500;
  *(undefined4 *)(iVar3 + 0xe0) = DAT_0003a504;
  *(undefined4 *)(iVar3 + 0xe4) = DAT_0003a508;
  *(undefined4 *)(iVar3 + 0xe8) = DAT_0003a50c;
  *(undefined4 *)(iVar3 + 0xec) = DAT_0003a510;
  *(undefined4 *)(iVar3 + 0xf0) = DAT_0003a514;
  *(undefined4 *)(iVar3 + 0xf4) = DAT_0003a518;
  iVar4 = DAT_0003a51c;
  *(int *)(iVar3 + 0xf8) = DAT_0003a51c;
  *(int *)(iVar3 + 0xfc) = iVar4 >> 0x19;
  puVar5 = DAT_0003a520;
  *DAT_0003a520 = *DAT_0003a520 | uVar11;
  puVar5[2] = puVar5[2] & ~uVar11;
  puVar5[3] = 0xffffff80;
  KEY_piaring_cnt();
  value_kcal_result();
  KEY_piaring_cnt();
  FUN_00039dfe();
  puVar1[9] = puVar1[9] & 0xfbffffff;
  puVar2[9] = puVar1[9];
  puVar1[0x1e] = puVar1[0x1e] | 0x80000000;
  *(undefined4 *)(iVar8 + 0x38) = puVar1[0x1e];
  KEY_piaring_cnt();
  addPMU_Reg0x5_2();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  FUN_000317c2(10);
  KEY_piaring_cnt();
  puVar6 = DAT_0003a528;
  if (*DAT_0003a524 == '\0') {
    uVar7 = FUN_00039cfc();
    *puVar6 = uVar7;
  }
  FUN_00039d3c(*puVar6);
  dbg_printf(str_cal_data_x,*puVar6);
  return;
}

/* ==========================================================================
 * kmod_calibration_2M   @ 0x0003a31e   (390 bytes)
 * calls     : FUN_000317c2, dbg_printf, rom_24F24
 * string    : "kmod_calibration_2M"
 * string    : "read xvr_reg0x12:0x%x\r\n"
 * string    : "cal value:0x%x\r\n"
 * string    : "value_kcal_resulte:0x%x\r\n"
 */

void kmod_calibration_2M(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  
  dbg_printf(&DAT_0003a5b8,DAT_0003a5b4,param_3,param_4,param_4);
  puVar4 = (uint *)(DAT_0003a4ac + 0x80);
  *puVar4 = *puVar4 | 8;
  *puVar4 = *puVar4 & 0xfffffffc;
  *puVar4 = *puVar4 & DAT_0003a5c0;
  *puVar4 = *puVar4 | 0x10000;
  *puVar4 = *puVar4 & DAT_0003a5c4;
  *puVar4 = *puVar4 | 0x10000000;
  iVar1 = DAT_0003a4ac;
  iVar3 = DAT_0003a4ac + 0x40;
  *(uint *)(DAT_0003a4ac + 0x50) = *(uint *)(DAT_0003a4ac + 0x50) | 0x40000000;
  *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x80000000;
  *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffdffff;
  *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xffffff80;
  FUN_000317c2(10);
  *(uint *)(iVar1 + 0x54) = *(uint *)(iVar1 + 0x54) | 0x1000;
  FUN_000317c2(10);
  *(uint *)(iVar1 + 0x54) = *(uint *)(iVar1 + 0x54) | 0x2000;
  FUN_000317c2(10);
  *(uint *)(iVar1 + 0x54) = *(uint *)(iVar1 + 0x54) | 0x800;
  FUN_000317c2(10);
  iVar2 = DAT_0003a5c8;
  *(uint *)(DAT_0003a5c8 + 0xc) = *(uint *)(DAT_0003a5c8 + 0xc) | 0x80;
  *(undefined4 *)(DAT_0003a4ac + -0x34) = *(undefined4 *)(iVar2 + 0xc);
  FUN_000317c2(10);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xffffffbf;
  *(undefined4 *)(DAT_0003a4ac + -0x34) = *(undefined4 *)(iVar2 + 0xc);
  FUN_000317c2(10);
  *(uint *)(iVar1 + 0x54) = *(uint *)(iVar1 + 0x54) | 0x10000;
  FUN_000317c2(200);
  uVar5 = *(uint *)(DAT_0003a4ac + 8);
  dbg_printf(str_read_xvr_reg0x12_0x_x,uVar5);
  uVar5 = (uVar5 & 0x1fffffff) >> 0x10;
  dbg_printf(str_cal_value_0x_x,uVar5);
  uVar5 = rom_24F24(&DAT_0001f400,uVar5);
  uVar5 = uVar5 & 0x1ff;
  *puVar4 = *puVar4 & DAT_0003a5c0;
  *puVar4 = *puVar4 | uVar5 << 8;
  dbg_printf(str_value_kcal_resulte_0x_x,uVar5);
  *(uint *)(DAT_0003a614 + 4) = uVar5;
  *(uint *)(iVar1 + 0x54) = *(uint *)(iVar1 + 0x54) & 0xfffeffff;
  *(uint *)(iVar1 + 0x54) = *(uint *)(iVar1 + 0x54) & 0xffffc7ff;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xffffff7f;
  *(undefined4 *)(DAT_0003a4ac + -0x34) = *(undefined4 *)(iVar2 + 0xc);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x40;
  *(undefined4 *)(DAT_0003a8e0 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *puVar4 = *puVar4 & 0xfffffff7;
  *puVar4 = *puVar4 & 0xfffffffc;
  *puVar4 = *puVar4 | 1;
  *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & ~(iVar3 * 0x800000);
  *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0x7fffffff;
  *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x20000;
  return;
}

/* ==========================================================================
 * FUN_0003aa42   @ 0x0003aa42   (70 bytes)
 * called by : FUN_00033d2c, FUN_0003443a
 */

void FUN_0003aa42(undefined1 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_0003ad08;
  do {
  } while (*(int *)(DAT_0003ad08 + 8) << 0x1d < 0);
  *(uint *)(DAT_0003ad08 + 4) = param_2 * 0x100000 + 2;
  uVar2 = DAT_0003ad28;
  uVar3 = 0;
  do {
    while (*(int *)(iVar1 + 8) << 0x1d < 0) {
      param_2 = param_2 - 1 & 0xff;
      *param_1 = (char)*(undefined4 *)(iVar1 + 0xc);
      if (param_2 == 0) goto LAB_0003aa7a;
      param_1 = param_1 + 1;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 <= uVar2);
LAB_0003aa7a:
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfffffffd;
  return;
}

/* ==========================================================================
 * FUN_0003afa2   @ 0x0003afa2   (86 bytes)
 * called by : USNDP_status_2, enter_BLE_normal_app_mode, exist, f_usb_isConnected
 * calls     : rom_25078
 */

void FUN_0003afa2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  cVar1 = *(char *)(DAT_0003b258 + 1);
  iVar3 = DAT_0003b258;
  if ((cVar1 == '\x03') || (cVar1 == '\x02')) {
    if (param_1 == 5) {
      return;
    }
  }
  else {
    if (cVar1 == '\x05') goto LAB_0003aff0;
    if ((cVar1 != '\x03') && (cVar1 != '\x02')) {
      if (cVar1 == '\x04') goto LAB_0003aff0;
      goto LAB_0003afd0;
    }
  }
  if (param_1 == 4) {
    return;
  }
LAB_0003afd0:
  do {
    *(char *)(iVar3 + 1) = (char)param_1;
    iVar3 = 0x100000;
    uVar4 = rom_25078(param_1,DAT_0003b264,0x100000,param_1,param_4);
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    param_1 = (int)uVar4;
    *(undefined4 *)(param_1 + 0x70) = 0x180;
    *(int *)(iVar2 + 0x74) = iVar2;
LAB_0003aff0:
  } while ((param_1 != 3) && (param_1 != 2));
  return;
}

/* ==========================================================================
 * FUN_0003b528   @ 0x0003b528   (16 bytes)
 * called by : FUN_000360aa, SLEEP, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, enter_BLE_normal_app_mode, exist, ... (+2 more)
 */

void FUN_0003b528(void)

{
  int iVar1;
  
  iVar1 = DAT_0003b564;
  *(undefined4 *)(DAT_0003b564 + 8) = 0;
  *(undefined4 *)(iVar1 + 4) = 0x5a;
  *(undefined4 *)(iVar1 + 4) = 0xa5;
  return;
}

/* ==========================================================================
 * FUN_0003b54e   @ 0x0003b54e   (12 bytes)
 * called by : FUN_00028c66, FUN_000317c2, FUN_0003c8b6, FUN_0003c996, FUN_0003cd24, OLED_Clear, ... (+3 more)
 */

void FUN_0003b54e(void)

{
  int iVar1;
  
  iVar1 = DAT_0003b564;
  *(undefined4 *)(DAT_0003b564 + 4) = 0x5a;
  *(undefined4 *)(iVar1 + 4) = 0xa5;
  return;
}

/* ==========================================================================
 * FUN_0003c21e   @ 0x0003c21e   (104 bytes)
 * called by : FUN_00036024, FUN_0003c2c6
 * calls     : rom_24F24
 */

void FUN_0003c21e(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = rom_24F24(param_2,1000);
  puVar2 = DAT_0003c4e4;
  pbVar1 = DAT_0003c4e0;
  if (param_1 == 0) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xfe;
    *puVar2 = uVar3;
    *(undefined4 *)(pbVar1 + 0x1c) = uVar3;
    uVar4 = puVar2[3];
    uVar5 = 1;
LAB_0003c266:
    uVar4 = uVar4 | uVar5;
  }
  else {
    if (param_1 == 1) {
      *DAT_0003c4e0 = *DAT_0003c4e0 & 0xfd;
      puVar2[1] = uVar3;
      *(undefined4 *)(pbVar1 + 0x20) = uVar3;
      uVar4 = puVar2[3];
      uVar5 = 2;
      goto LAB_0003c266;
    }
    if (param_1 != 2) goto LAB_0003c26a;
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xfb;
    puVar2[2] = uVar3;
    *(undefined4 *)(pbVar1 + 0x2c) = uVar3;
    uVar4 = puVar2[3] | 4;
  }
  puVar2[3] = uVar4;
LAB_0003c26a:
  *DAT_0003c4ec = *DAT_0003c4ec | 4;
  return;
}

/* ==========================================================================
 * FUN_0003c286   @ 0x0003c286   (64 bytes)
 * called by : FUN_00036024, FUN_000360aa, FUN_0003c2c6, SLEEP, exist
 */

void FUN_0003c286(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  
  pbVar1 = DAT_0003c4e0;
  if (param_1 == 0) {
    *(uint *)(DAT_0003c4e4 + 0xc) = *(uint *)(DAT_0003c4e4 + 0xc) & 0xfffffffe;
    bVar2 = *pbVar1 & 0xfe;
  }
  else {
    if (param_1 == 1) {
      *(uint *)(DAT_0003c4e4 + 0xc) = *(uint *)(DAT_0003c4e4 + 0xc) & 0xfffffffd;
      bVar2 = *pbVar1;
      bVar3 = 0xfd;
    }
    else {
      if (param_1 != 2) {
        return;
      }
      *(uint *)(DAT_0003c4e4 + 0xc) = *(uint *)(DAT_0003c4e4 + 0xc) & 0xfffffffb;
      bVar2 = *pbVar1;
      bVar3 = 0xfb;
    }
    bVar2 = bVar2 & bVar3;
  }
  *pbVar1 = bVar2;
  return;
}

/* ==========================================================================
 * FUN_0003c6a8   @ 0x0003c6a8   (12 bytes)
 * called by : gpio
 */

void FUN_0003c6a8(void)

{
  int iVar1;
  
  iVar1 = DAT_0003c804;
  *(undefined4 *)(DAT_0003c804 + 0x10) = 1;
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}

/* ==========================================================================
 * FUN_0003c818   @ 0x0003c818   (42 bytes)
 * called by : FUN_0003c8b6
 * calls     : FUN_000317c2
 */

void FUN_0003c818(void)

{
  int iVar1;
  
  iVar1 = DAT_0003cc18;
  *(undefined4 *)(DAT_0003cc18 + 8) = 2;
  FUN_000317c2(1);
  *(undefined4 *)(iVar1 + 0xc) = 2;
  FUN_000317c2(1);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_000317c2(1);
  *(undefined4 *)(iVar1 + 0xc) = 2;
  FUN_000317c2(1);
  return;
}

/* ==========================================================================
 * FUN_0003c996   @ 0x0003c996   (40 bytes)
 * called by : FUN_0003c9be, FUN_0003d24a, FUN_0003d55c
 * calls     : FUN_0003b54e, FUN_0003c896
 */

void FUN_0003c996(uint param_1,char param_2)

{
  FUN_0003c896(param_2 + -0x50);
  FUN_0003c896((param_1 >> 4) + 0x10);
  FUN_0003c896(param_1 & 0xf);
  FUN_0003b54e();
  return;
}

/* ==========================================================================
 * FUN_0003c9be   @ 0x0003c9be   (52 bytes)
 * called by : FUN_0003c9f2, FUN_0003cb9a, FUN_0003ce5c, FUN_0003d63a, FUN_0003d7ee, FUN_0003d8da, ... (+3 more)
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886, FUN_0003c996
 */

void FUN_0003c9be(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  FUN_0003c996();
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    FUN_0003c852(*(undefined1 *)(param_4 + uVar1));
  }
  FUN_0003c842();
  return;
}

/* ==========================================================================
 * FUN_0003c9f2   @ 0x0003c9f2   (422 bytes)
 * called by : FUN_0003cd24
 * calls     : FUN_0003c9be
 */

void FUN_0003c9f2(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte local_38 [12];
  uint local_2c;
  uint local_28;
  uint local_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  iVar5 = DAT_0003cc28;
  iVar6 = DAT_0003cc20;
  uVar1 = 0;
  uVar4 = param_4 - 0x20U & 0xff;
  uStack_20 = param_2;
  iStack_1c = param_3;
  iStack_18 = param_4;
  if (param_1 < 0x78) {
    local_24 = param_1;
    if (param_3 == 0) goto LAB_0003cafc;
    if (param_3 == 1) goto LAB_0003cb1a;
    if (param_3 != 2) {
      return;
    }
  }
  else {
    local_24 = 0;
    if (param_3 == 0) {
      param_2 = param_2 + 1 & 0xff;
LAB_0003cafc:
      do {
        local_38[uVar1] = *(byte *)(DAT_0003cc24 + uVar4 * 6 + uVar1);
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 6);
      uVar3 = 6;
      goto LAB_0003cb90;
    }
    if (param_3 == 1) {
      param_2 = param_2 + 2 & 0xff;
LAB_0003cb1a:
      iVar6 = uVar4 * 0x10;
      do {
        local_38[uVar1] = *(char *)(DAT_0003cc28 + iVar6 + uVar1) << 4;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 8);
      FUN_0003c9be(local_24,param_2,8,local_38);
      uVar1 = 0;
      do {
        local_38[uVar1] =
             *(byte *)(iVar5 + iVar6 + uVar1) >> 4 | *(char *)(iVar6 + uVar1 + iVar5 + 8) << 4;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 8);
      FUN_0003c9be(local_24,param_2 + 1 & 0xff,8,local_38);
      uVar1 = 0;
      do {
        local_38[uVar1] = *(byte *)(iVar6 + uVar1 + iVar5 + 8) >> 4;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 8);
      param_2 = param_2 + 2 & 0xff;
      uVar3 = 8;
      goto LAB_0003cb90;
    }
    if (param_3 != 2) {
      return;
    }
    param_2 = param_2 + 3 & 0xff;
  }
  iVar5 = uVar4 * 0x24;
  local_28 = 0;
  local_2c = 0;
  do {
    bVar2 = *(byte *)(iVar5 + uVar1 + DAT_0003cc20 + 0x18);
    if (param_2 != 0) {
      if ((bVar2 & 1) != 0) {
        local_28 = 1 << uVar1 & 0xffffU | local_28;
      }
      bVar2 = bVar2 >> 1;
    }
    local_38[uVar1] = bVar2;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0xc);
  FUN_0003c9be(local_24,param_2 + 2 & 0xff,0xc,local_38);
  uVar1 = 0;
  do {
    bVar2 = *(byte *)(iVar5 + uVar1 + iVar6 + 0xc);
    if (param_2 != 0) {
      if ((bVar2 & 1) != 0) {
        local_2c = (1 << uVar1 | local_2c) & 0xffff;
      }
      bVar2 = bVar2 >> 1;
      if ((1 << uVar1 & local_28) != 0) {
        bVar2 = bVar2 | 0x80;
      }
    }
    local_38[uVar1] = bVar2;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0xc);
  FUN_0003c9be(local_24,param_2 + 1 & 0xff,0xc,local_38);
  uVar1 = 0;
  do {
    bVar2 = *(byte *)(iVar6 + iVar5 + uVar1);
    if ((param_2 != 0) && (bVar2 = bVar2 >> 1, (1 << uVar1 & local_2c) != 0)) {
      bVar2 = bVar2 | 0x80;
    }
    local_38[uVar1] = bVar2;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0xc);
  uVar3 = 0xc;
LAB_0003cb90:
  FUN_0003c9be(local_24,param_2,uVar3,local_38);
  return;
}

/* ==========================================================================
 * FUN_0003cb9a   @ 0x0003cb9a   (370 bytes)
 * called by : FUN_0003cd24
 * calls     : FUN_0003c9be
 */

void FUN_0003cb9a(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  byte local_38 [12];
  uint local_2c;
  uint local_28;
  uint local_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  iVar1 = DAT_0003cc20;
  uVar2 = 0;
  uVar5 = param_4 - 0x20U & 0xff;
  uStack_20 = param_2;
  iStack_1c = param_3;
  iStack_18 = param_4;
  if (param_1 < 0x78) {
    local_24 = param_1;
    if (param_3 == 0) goto LAB_0003ccbe;
    if (param_3 == 1) goto LAB_0003ccda;
    if (param_3 != 2) {
      return;
    }
  }
  else {
    local_24 = 0;
    if (param_3 == 0) {
      param_2 = param_2 + 1 & 0xff;
LAB_0003ccbe:
      do {
        local_38[uVar2] = *(byte *)(DAT_0003d0ac + uVar5 * 6 + uVar2);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 6);
      uVar4 = 6;
      goto LAB_0003cd1c;
    }
    if (param_3 == 1) {
      param_2 = param_2 + 2 & 0xff;
LAB_0003ccda:
      do {
        bVar3 = *(byte *)(DAT_0003d0b0 + uVar5 * 0x10 + uVar2);
        local_38[uVar2] = bVar3;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 8);
      FUN_0003c9be(local_24,param_2,8,local_38);
      uVar2 = 0;
      do {
        local_38[uVar2] = *(byte *)(uVar5 * 0x10 + uVar2 + DAT_0003d0b0 + 8) | bVar3;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 8);
      param_2 = param_2 + 1 & 0xff;
      uVar4 = 8;
      goto LAB_0003cd1c;
    }
    if (param_3 != 2) {
      return;
    }
    param_2 = param_2 + 3 & 0xff;
  }
  iVar6 = uVar5 * 0x24;
  local_28 = 0;
  local_2c = 0;
  do {
    bVar3 = *(byte *)(iVar6 + uVar2 + DAT_0003cc20 + 0x18);
    if (param_2 != 0) {
      if ((bVar3 & 1) != 0) {
        local_28 = 1 << uVar2 & 0xffffU | local_28;
      }
      bVar3 = bVar3 >> 1;
    }
    local_38[uVar2] = bVar3;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0xc);
  FUN_0003c9be(local_24,param_2 + 2 & 0xff,0xc,local_38);
  uVar2 = 0;
  do {
    bVar3 = *(byte *)(iVar6 + uVar2 + iVar1 + 0xc);
    if (param_2 != 0) {
      if ((bVar3 & 1) != 0) {
        local_2c = (1 << uVar2 | local_2c) & 0xffff;
      }
      bVar3 = bVar3 >> 1;
      if ((1 << uVar2 & local_28) != 0) {
        bVar3 = bVar3 | 0x80;
      }
    }
    local_38[uVar2] = bVar3;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0xc);
  FUN_0003c9be(local_24,param_2 + 1 & 0xff,0xc,local_38);
  uVar2 = 0;
  do {
    bVar3 = *(byte *)(iVar1 + iVar6 + uVar2);
    if ((param_2 != 0) && (bVar3 = bVar3 >> 1, (1 << uVar2 & local_2c) != 0)) {
      bVar3 = bVar3 | 0x80;
    }
    local_38[uVar2] = bVar3;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0xc);
  uVar4 = 0xc;
LAB_0003cd1c:
  FUN_0003c9be(local_24,param_2,uVar4,local_38);
  return;
}

/* ==========================================================================
 * FUN_0003cdb6   @ 0x0003cdb6   (74 bytes)
 * called by : FUN_0003cf7c, FUN_0003d2b0, system_mode
 * calls     : FUN_0003cd24
 */

void FUN_0003cdb6(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (*DAT_0003d0bc == '\0') {
    cVar1 = *DAT_0003d0c8;
    if (cVar1 == '\0') {
      FUN_0003cd24(0x4c,1,2,&DAT_0003d0d4);
      uVar2 = 0x5e;
      puVar3 = &DAT_0003d0d8;
      goto LAB_0003cddc;
    }
    if (cVar1 == '\x01') {
      puVar3 = &DAT_0003d0dc;
    }
    else if (cVar1 == '\x02') {
      puVar3 = &DAT_0003d0e4;
    }
    else {
      puVar3 = &DAT_0003d0cc;
    }
  }
  else {
    puVar3 = &DAT_0003d0c0;
  }
  uVar2 = 0x48;
LAB_0003cddc:
  FUN_0003cd24(uVar2,1,2,puVar3);
  return;
}

/* ==========================================================================
 * FUN_0003ce5c   @ 0x0003ce5c   (200 bytes)
 * called by : FUN_0003cf7c, FUN_0003d2b0
 * calls     : FUN_0003c9be, FUN_0003cd24, FUN_000429d4
 * string    : "  %d%%"
 * string    : " %d%%"
 */

void FUN_0003ce5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar4 = 100 - *DAT_0003d128 & 0xff;
  if (*DAT_0003d12c == '\0') {
    uStack_18 = param_2;
    uStack_14 = param_3;
    uStack_10 = param_4;
    if (*DAT_0003d130 == '\0') {
      if (uVar4 < 10) {
        pcVar1 = str_d_2;
      }
      else if (uVar4 < 100) {
        pcVar1 = str_d_3;
      }
      else {
        pcVar1 = &DAT_0003d15c;
      }
      FUN_000429d4(&uStack_18,pcVar1,uVar4);
      FUN_0003cd24(0x4a,0,0,&uStack_18);
      if (uVar4 < 0x14) {
        iVar3 = DAT_0003d138 + 0x78;
      }
      else if (uVar4 - 0x14 < 0x14) {
        iVar3 = DAT_0003d138 + 100;
      }
      else if (uVar4 - 0x28 < 0x14) {
        iVar3 = DAT_0003d138 + 0x50;
      }
      else if (uVar4 - 0x3c < 0x14) {
        iVar3 = DAT_0003d138 + 0x3c;
      }
      else if (uVar4 - 0x50 < 0x14) {
        iVar3 = DAT_0003d138 + 0x28;
      }
      else {
        iVar3 = DAT_0003d138 + 0x14;
      }
      FUN_0003c9be(100,0,0x14,iVar3);
      return;
    }
    if (*DAT_0003d134 == '\0') {
      FUN_0003c9be(100,0,0x14,DAT_0003d138);
      puVar2 = &DAT_0003d144;
    }
    else {
      FUN_0003c9be(100,0,0x14,DAT_0003d138);
      puVar2 = &DAT_0003d13c;
    }
    FUN_0003cd24(0x4a,0,0,puVar2);
  }
  return;
}

/* ==========================================================================
 * FUN_0003cf24   @ 0x0003cf24   (88 bytes)
 * called by : FUN_00031808, FUN_0003cf7c
 * calls     : FUN_0002b18e, FUN_0003cd24
 * string    : "125 Hz "
 * string    : "133 Hz "
 * string    : "1000 Hz"
 * string    : "500 Hz "
 * string    : "250 Hz "
 */

void FUN_0003cf24(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = FUN_0002b18e();
  if (iVar2 == 0) {
    pcVar3 = s__0003d164;
  }
  else if (((*DAT_0003d0c8 == '\x01') || (*DAT_0003d0c8 == '\x02')) && (*DAT_0003d0bc == '\0')) {
    pcVar3 = str_s133_Hz;
  }
  else {
    cVar1 = *(char *)(DAT_0003d0ec + -10);
    if (cVar1 == '\x01') {
      pcVar3 = str_s1000_Hz;
    }
    else if (cVar1 == '\x02') {
      pcVar3 = str_s500_Hz;
    }
    else if (cVar1 == '\x04') {
      pcVar3 = str_s250_Hz;
    }
    else {
      if (cVar1 != '\b') {
        return;
      }
      pcVar3 = str_s125_Hz;
    }
  }
  FUN_0003cd24(0,0,0,pcVar3);
  return;
}

/* ==========================================================================
 * FUN_0003d082   @ 0x0003d082   (42 bytes)
 * called by : FUN_0003d2b0
 * string    : "BAT OVER!"
 * string    : "BAT LOW! "
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void FUN_0003d082(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if (*DAT_0003d130 != '\0') {
    return;
  }
  if (*DAT_0003d228 == '\0') {
    if (*DAT_0003d238 == '\0') {
      return;
    }
    pcVar2 = str_BAT_LOW;
  }
  else {
    pcVar2 = str_BAT_OVER;
  }
  cVar1 = '\x01';
  bVar3 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  for (uVar4 = 0; pcVar2[uVar4] != '\0'; uVar4 = uVar4 + 1 & 0xff) {
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(bVar3,cVar1,1);
    }
    else {
      FUN_0003cb9a(bVar3,cVar1,1);
    }
    bVar3 = bVar3 + 8;
    if (0x70 < bVar3) {
      bVar3 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *DAT_0003d0b8 = '\0';
  return;
}

/* ==========================================================================
 * FUN_0003d2b0   @ 0x0003d2b0   (210 bytes)
 * called by : SLEEP, f_usb_isConnected
 * calls     : CHRG, Charging, FUN_0003cdb6, FUN_0003ce00, FUN_0003ce52, FUN_0003ce5c, ... (+7 more)
 */

void FUN_0003d2b0(void)

{
  if ((*DAT_0003d684 == '\0') && (*DAT_0003d688 != 0)) {
    if (*DAT_0003d68c != '\0') {
      *DAT_0003d68c = '\0';
      if (*DAT_0003d690 != '\0') {
        *DAT_0003d690 = '\0';
        OLED_Clear();
      }
      *(undefined4 *)(DAT_0003d694 + 8) = 2;
      FUN_0003cf7c();
    }
    if (*DAT_0003d698 != '\0') {
      *DAT_0003d698 = '\0';
      FUN_0003ce5c();
    }
    if (*DAT_0003d69c != '\0') {
      *DAT_0003d69c = '\0';
      FUN_0003ce00();
    }
    if (*DAT_0003d6a0 != '\0') {
      *DAT_0003d6a0 = '\0';
      FUN_0003d082();
    }
    if (*DAT_0003d6a4 != '\0') {
      *DAT_0003d6a4 = '\0';
      FUN_0003ce52();
    }
    if (*DAT_0003d6a8 != '\0') {
      *DAT_0003d6a8 = '\0';
      Charging();
    }
    if (*DAT_0003d6ac != '\0') {
      *DAT_0003d6ac = '\0';
      Pairing();
    }
    if (*DAT_0003d6b0 != '\0') {
      *DAT_0003d6b0 = '\0';
      ReLinking();
    }
    if (*DAT_0003d6b4 != '\0') {
      *DAT_0003d6b4 = '\0';
      ReLink();
    }
    if (*DAT_0003d6b8 != '\0') {
      *DAT_0003d6b8 = '\0';
      CHRG();
    }
    if (*DAT_0003d6bc != '\0') {
      *DAT_0003d6bc = '\0';
      FUN_0003cdb6();
    }
    if (*PTR_DAT_0003d6c0 != '\0') {
      *PTR_DAT_0003d6c0 = 0;
      delta_none();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0003d55c   @ 0x0003d55c   (32 bytes)
 * calls     : FUN_0003c90c, FUN_0003c996
 */

void FUN_0003d55c(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  FUN_0003c996();
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    FUN_0003c90c(*(undefined1 *)(param_4 + uVar1));
  }
  return;
}

/* ==========================================================================
 * FUN_0003d63a   @ 0x0003d63a   (268 bytes)
 * calls     : FUN_0003c9be, rom_24F9C, rom_24FEC
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003d63a(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char acStack_98 [21];
  byte abStack_83 [21];
  byte abStack_6e [22];
  byte abStack_58 [21];
  byte abStack_43 [23];
  byte *pbStack_2c;
  undefined4 uStack_1c;
  int iStack_18;
  
  uStack_1c = param_1;
  iStack_18 = param_2;
  rom_24FEC(abStack_58,0x15);
  cVar1 = *_DAT_0003d708;
  iVar4 = _DAT_0003d70c;
  if ((*_DAT_0003d704 == '\0') && (iVar4 = DAT_0003daf8, cVar1 != '\0')) {
    if (cVar1 == '\x01') {
      iVar4 = DAT_0003daf8 + 0x3f;
      goto LAB_0003d724;
    }
    if (cVar1 == '\x02') {
      iVar4 = DAT_0003daf8 + 0x69;
      goto LAB_0003d724;
    }
  }
  else {
LAB_0003d724:
    rom_24F9C(abStack_58,iVar4,0x15);
  }
  uVar2 = 0;
  do {
    acStack_98[uVar2] = abStack_58[uVar2] << 4;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x15);
  pbStack_2c = abStack_43;
  rom_24FEC();
  if (*DAT_0003dafc == '\0') {
    if (cVar1 == '\0') {
      iVar4 = DAT_0003daf8 + 0x15;
    }
    else if (cVar1 == '\x01') {
      iVar4 = DAT_0003daf8 + 0x54;
    }
    else {
      if (cVar1 != '\x02') goto LAB_0003d784;
      iVar4 = DAT_0003daf8 + 0x7e;
    }
  }
  else {
    iVar4 = DAT_0003daf8 + -0x15;
  }
  rom_24F9C(pbStack_2c,iVar4,0x15);
LAB_0003d784:
  uVar2 = 0;
  do {
    abStack_83[uVar2] = abStack_58[uVar2] >> 4;
    uVar3 = uVar2 + 1 & 0xff;
    abStack_83[uVar2] = abStack_58[uVar2] >> 4 | abStack_43[uVar2] << 4;
    uVar2 = uVar3;
  } while (uVar3 < 0x15);
  uVar2 = 0;
  do {
    uVar3 = uVar2 + 1 & 0xff;
    abStack_6e[uVar2] = abStack_43[uVar2] >> 4;
    uVar2 = uVar3;
  } while (uVar3 < 0x15);
  FUN_0003c9be(uStack_1c,param_2,0x15,acStack_98);
  FUN_0003c9be(uStack_1c,param_2 + 1U & 0xff,0x15,abStack_83);
  FUN_0003c9be(uStack_1c,param_2 + 2U & 0xff,0x15,abStack_6e);
  return;
}

/* ==========================================================================
 * FUN_0003d7ee   @ 0x0003d7ee   (236 bytes)
 * calls     : FUN_0003c9be, rom_24F9C, rom_24FEC
 */

void FUN_0003d7ee(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char acStack_98 [21];
  byte abStack_83 [21];
  byte abStack_6e [22];
  byte abStack_58 [21];
  byte abStack_43 [23];
  byte *pbStack_2c;
  undefined4 uStack_1c;
  int iStack_18;
  
  uStack_1c = param_1;
  iStack_18 = param_2;
  rom_24FEC(abStack_58,0x15);
  cVar1 = *DAT_0003db00;
  iVar4 = DAT_0003daf8;
  if (cVar1 == '\0') {
LAB_0003d822:
    rom_24F9C(abStack_58,iVar4,0x15);
  }
  else {
    if (cVar1 == '\x01') {
      iVar4 = DAT_0003daf8 + 0x3f;
      goto LAB_0003d822;
    }
    if (cVar1 == '\x02') {
      iVar4 = DAT_0003daf8 + 0x69;
      goto LAB_0003d822;
    }
  }
  uVar2 = 0;
  do {
    acStack_98[uVar2] = abStack_58[uVar2] << 4;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x15);
  pbStack_2c = abStack_43;
  rom_24FEC();
  if (cVar1 == '\0') {
    iVar4 = DAT_0003daf8 + 0x15;
  }
  else if (cVar1 == '\x01') {
    iVar4 = DAT_0003daf8 + 0x54;
  }
  else {
    if (cVar1 != '\x02') goto LAB_0003d872;
    iVar4 = DAT_0003daf8 + 0x7e;
  }
  rom_24F9C(pbStack_2c,iVar4,0x15);
LAB_0003d872:
  uVar2 = 0;
  do {
    abStack_83[uVar2] = abStack_58[uVar2] >> 4;
    uVar3 = uVar2 + 1 & 0xff;
    abStack_83[uVar2] = abStack_58[uVar2] >> 4 | abStack_43[uVar2] << 4;
    uVar2 = uVar3;
  } while (uVar3 < 0x15);
  uVar2 = 0;
  do {
    uVar3 = uVar2 + 1 & 0xff;
    abStack_6e[uVar2] = abStack_43[uVar2] >> 4;
    uVar2 = uVar3;
  } while (uVar3 < 0x15);
  FUN_0003c9be(uStack_1c,param_2,0x15,acStack_98);
  FUN_0003c9be(uStack_1c,param_2 + 1U & 0xff,0x15,abStack_83);
  FUN_0003c9be(uStack_1c,param_2 + 2U & 0xff,0x15,abStack_6e);
  return;
}

/* ==========================================================================
 * FUN_0003d8da   @ 0x0003d8da   (148 bytes)
 * called by : enter_BLE_normal_app_mode, f_usb_isConnected
 * calls     : FUN_0003c9be, rom_24F9C, rom_24FEC
 */

void FUN_0003d8da(int param_1)

{
  undefined1 *puVar1;
  undefined1 auStack_178 [120];
  undefined1 auStack_100 [240];
  
  *DAT_0003db04 = 1;
  rom_24FEC(auStack_178,0x168);
  puVar1 = auStack_178 + param_1;
  rom_24F9C(puVar1,DAT_0003db08,0x78);
  FUN_0003c9be(0,0,0x78,auStack_100);
  rom_24FEC(auStack_178,0x168);
  rom_24F9C(puVar1,DAT_0003db08 + 0x78,0x78);
  FUN_0003c9be(0,1,0x78,auStack_100);
  rom_24FEC(auStack_178,0x168);
  rom_24F9C(puVar1,DAT_0003db08 + 0xf0,0x78);
  FUN_0003c9be(0,2,0x78,auStack_100);
  rom_24FEC(auStack_178,0x168);
  rom_24F9C(puVar1,DAT_0003db0c,0x78);
  FUN_0003c9be(0,3,0x78,auStack_100);
  return;
}

/* ==========================================================================
 * FUN_0003d96e   @ 0x0003d96e   (212 bytes)
 * calls     : FUN_0003c9be, rom_24F9C, rom_24FEC
 */

void FUN_0003d96e(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined1 auStack_134 [21];
  undefined1 auStack_11f [60];
  undefined1 auStack_e3 [207];
  
  rom_24FEC(auStack_134,0x11c);
  pcVar3 = DAT_0003db10;
  pcVar2 = DAT_0003dafc;
  if (*DAT_0003dafc == '\0') {
    cVar1 = *DAT_0003db10;
    iVar4 = DAT_0003daf8;
    if (cVar1 == '\0') goto LAB_0003d9c0;
    if (cVar1 == '\x01') {
      iVar4 = DAT_0003daf8 + 0x3f;
      goto LAB_0003d9c0;
    }
    if (cVar1 == '\x02') {
      iVar4 = DAT_0003daf8 + 0x69;
      goto LAB_0003d9c0;
    }
  }
  else {
    iVar4 = DAT_0003daf8 + -0x2a;
LAB_0003d9c0:
    rom_24F9C(auStack_134 + param_1,iVar4,0x15);
  }
  rom_24F9C(auStack_11f + param_1,DAT_0003db14,0x3c);
  FUN_0003c9be(0,1,0x78);
  rom_24FEC(auStack_134,0x11c);
  if (*pcVar2 == '\0') {
    if (*pcVar3 == '\0') {
      iVar4 = DAT_0003daf8 + 0x15;
    }
    else {
      if ((*DAT_0003db00 != '\x01') && (*DAT_0003db00 != '\x02')) goto LAB_0003da26;
      iVar4 = DAT_0003daf8 + 0x2a;
    }
  }
  else {
    iVar4 = DAT_0003daf8 + -0x15;
  }
  rom_24F9C(auStack_134 + param_1,iVar4,0x15);
LAB_0003da26:
  rom_24F9C(auStack_11f + param_1,DAT_0003db14 + 0x3c,0x3c);
  FUN_0003c9be(0,2,0x78,auStack_e3);
  return;
}

/* ==========================================================================
 * FUN_0003da42   @ 0x0003da42   (214 bytes)
 * calls     : FUN_0003c9be, rom_24F9C, rom_24FEC
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003da42(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined1 auStack_134 [21];
  undefined1 auStack_11f [60];
  undefined1 auStack_e3 [207];
  
  rom_24FEC(auStack_134,0x11c);
  pcVar3 = DAT_0003db10;
  pcVar2 = DAT_0003dafc;
  if (*DAT_0003dafc == '\0') {
    cVar1 = *DAT_0003db10;
    iVar4 = DAT_0003daf8;
    if (cVar1 == '\0') goto LAB_0003da94;
    if (cVar1 == '\x01') {
      iVar4 = DAT_0003daf8 + 0x3f;
      goto LAB_0003da94;
    }
    if (cVar1 == '\x02') {
      iVar4 = DAT_0003daf8 + 0x69;
      goto LAB_0003da94;
    }
  }
  else {
    iVar4 = DAT_0003daf8 + -0x2a;
LAB_0003da94:
    rom_24F9C(auStack_134 + param_1,iVar4,0x15);
  }
  rom_24F9C(auStack_11f + param_1,DAT_0003db14 + 0x78,0x3c);
  FUN_0003c9be(0,1,0x78);
  rom_24FEC(auStack_134,0x11c);
  if (*pcVar2 == '\0') {
    cVar1 = *pcVar3;
    if (cVar1 == '\0') {
      iVar4 = DAT_0003daf8 + 0x15;
    }
    else if (cVar1 == '\x01') {
      iVar4 = DAT_0003daf8 + 0x54;
    }
    else {
      iVar4 = _DAT_0003dc18;
      if (cVar1 != '\x02') goto LAB_0003da3e;
    }
  }
  else {
    iVar4 = DAT_0003daf8 + -0x15;
  }
  rom_24F9C(auStack_134 + param_1,iVar4,0x15);
LAB_0003da3e:
  rom_24F9C(auStack_11f + param_1,PTR_DAT_0003dc1c,0x3c);
  FUN_0003c9be(0,2,0x78,auStack_e3);
  return;
}

/* ==========================================================================
 * FUN_0003db3a   @ 0x0003db3a   (82 bytes)
 * calls     : FUN_0003c9be, FUN_0003cd24, rom_25078
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003db3a(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int extraout_r1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 unaff_r7;
  
  puVar3 = _DAT_0003dc24;
  uVar2 = 1;
  if (param_1 < 5) {
    uVar1 = rom_25078(param_1,100 - (uint)*_DAT_0003dc20,100,param_1,param_2,param_3,param_4);
    puVar3 = puVar3 + -0x18;
    *(undefined2 *)(extraout_r1 * 2) = uVar1;
    uVar2 = unaff_r7;
  }
  FUN_0003c9be(0x14,1,0x1d,_DAT_0003dc18 + 0x15);
  FUN_0003c9be(0x14,2,0x1d,_DAT_0003dc18 + 0x32);
  *puVar3 = uVar2;
  FUN_0003cd24(0x32,1,1,_DAT_0003dc28);
  return;
}

/* ==========================================================================
 * FUN_0004169a   @ 0x0004169a   (254 bytes)
 * called by : hogpd_report_upd_req_handler
 * calls     : FUN_0003edee, FUN_0003ee1a, FUN_00041034, rom_06EF4, rom_06F26, rom_24F9C
 */

undefined4 FUN_0004169a(int param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  ushort uVar10;
  
  iVar3 = FUN_0003edee(0x26);
  uVar8 = 0;
  cVar2 = '\0';
  bVar1 = param_2[1];
  uVar7 = 0x17;
  uVar10 = 0;
  uVar9 = 0;
  if (bVar1 == 0) {
    uVar7 = 0x14;
    uVar10 = 0x2d;
    uVar9 = 0x40 << param_2[4] & 0xffff;
    cVar2 = '\x01';
  }
  else if (bVar1 == 2) {
    uVar7 = 0xc;
    uVar10 = 8;
    uVar9 = 1;
  }
  else if (bVar1 == 4) {
    uVar7 = 0x11;
    uVar10 = 8;
    uVar9 = 2;
  }
  iVar4 = FUN_00041034(iVar3,*param_2,uVar7,param_2[4]);
  if (iVar4 == 0) {
    if ((((uVar9 == 0) || ((uint)*(byte *)(iVar3 + 0x1b) <= (uint)*param_2)) ||
        (iVar3 = (uint)*param_2 * 8 + iVar3, *(byte *)(iVar3 + 9) <= param_2[4])) ||
       ((*(ushort *)(iVar3 + 4) & uVar9) != 0)) {
      uVar8 = 0x81;
    }
    else {
      uVar8 = 0x8c;
    }
  }
  else if (uVar10 < *(ushort *)(param_2 + 2)) {
    uVar8 = 0x8d;
  }
  else {
    iVar5 = (uint)*param_2 * 8 + iVar3;
    if ((*(ushort *)(iVar5 + param_1 * 2 + 6) & uVar9) == 0) {
      uVar8 = 0x8a;
    }
    else if ((*(char *)(iVar5 + 0xb) == cVar2) || (-1 < (int)((uint)*(byte *)(iVar5 + 4) << 0x1d)))
    {
      uVar7 = FUN_0003ee1a(iVar3,param_1);
      puVar6 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar7,*(short *)(param_2 + 2) + 8);
      *puVar6 = 0x12;
      *(short *)(puVar6 + 4) = (short)iVar4;
      *(undefined2 *)(puVar6 + 6) = *(undefined2 *)(param_2 + 2);
      rom_24F9C(puVar6 + 8,param_2 + 5,*(undefined2 *)(param_2 + 2));
      rom_06F26(puVar6);
    }
    else {
      uVar8 = 0x89;
    }
  }
  return uVar8;
}

/* ==========================================================================
 * hogpd_report_upd_req_handler   @ 0x000418ae   (116 bytes)
 * calls     : FUN_0004169a, dbg_printf, rom_06EF4, rom_06F26, rom_07180, rom_071EA, ... (+1 more)
 * string    : "hogpd_report_upd_req_handler"
 * string    : "%s error status: %d\r\n"
 */

undefined4
hogpd_report_upd_req_handler(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  uVar1 = rom_071EA(param_3);
  if ((uVar1 & 1) != 0) {
    return 2;
  }
  if (*param_2 < 2) {
    iVar2 = rom_1855C();
    if (iVar2 != DAT_00041c48) {
      iVar2 = FUN_0004169a(*param_2,param_2 + 2);
      if (iVar2 == 0) {
        rom_07180(param_3,uVar1 | 1);
        return 0;
      }
      goto LAB_000418f0;
    }
    if (*param_2 < 2) {
      iVar2 = 0x89;
      goto LAB_000418f0;
    }
  }
  iVar2 = 0x40;
LAB_000418f0:
  pbVar3 = (byte *)rom_06EF4(DAT_00041c4c + 2,param_4,param_3,2);
  *pbVar3 = *param_2;
  pbVar3[1] = (byte)iVar2;
  rom_06F26();
  dbg_printf(str_s_error_status_d,DAT_00041c50,iVar2);
  return 0;
}

/* ==========================================================================
 * FUN_0004245e   @ 0x0004245e   (20 bytes)
 * called by : FUN_00037104, FUN_00037a94, FUN_00038384, _USB_macro2, pcfg, usb_suspend
 */

uint FUN_0004245e(int param_1,undefined4 param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 3;
  pbVar1 = (byte *)(param_1 + 4);
  do {
    pbVar1 = pbVar1 + -1;
    param_3 = param_3 << 8 | (uint)*pbVar1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_3;
}

/* ==========================================================================
 * FUN_00042472   @ 0x00042472   (18 bytes)
 * called by : FUN_00037104, FUN_00037ac6, FUN_00038398, usb_suspend, usb_suspend_wakeup
 */

uint FUN_00042472(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 3;
  uVar1 = param_1;
  do {
    *param_2 = (char)uVar1;
    uVar1 = uVar1 >> 8;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_1;
}

/* ==========================================================================
 * FUN_00042a20   @ 0x00042a20   (80 bytes)
 * called by : FUN_00037878, FUN_000378ba
 */

void FUN_00042a20(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 - 4);
    piVar1 = (int *)*DAT_00042a70;
    piVar4 = (int *)0x0;
    while ((piVar3 = piVar1, piVar3 != (int *)0x0 && (piVar3 <= piVar2))) {
      piVar4 = piVar3;
      piVar1 = (int *)piVar3[1];
    }
    if (piVar4 == (int *)0x0) {
      *DAT_00042a70 = (uint)piVar2;
    }
    else if ((int)piVar2 - (int)piVar4 == *piVar4) {
      *piVar4 = *piVar4 + *piVar2;
      piVar2 = piVar4;
    }
    else {
      piVar4[1] = (int)piVar2;
    }
    if ((piVar3 != (int *)0x0) && ((int)piVar3 - (int)piVar2 == *piVar2)) {
      *piVar2 = *piVar2 + *piVar3;
      piVar3 = (int *)piVar3[1];
    }
    piVar2[1] = (int)piVar3;
  }
  return;
}

/* ==========================================================================
 * FUN_00042a74   @ 0x00042a74   (92 bytes)
 * called by : FUN_00037878, FUN_000378ba
 */

uint * FUN_00042a74(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  
  puVar1 = PTR_DAT_00042ad0;
  uVar4 = param_1 + 0xbU & 0xfffffff8;
  puVar5 = (uint *)PTR_DAT_00042ad4;
  do {
    while (puVar3 = (uint *)*puVar5, puVar3 == (uint *)0x0) {
      puVar3 = (uint *)0x0;
LAB_00042aac:
      puVar2 = PTR_DAT_00042ad8;
      if (puVar3 != (uint *)0x0) {
        return puVar3;
      }
      if (*(int *)puVar1 != 0) {
        return (uint *)0x0;
      }
      *(undefined **)PTR_DAT_00042ad4 = PTR_DAT_00042ad8;
      *(uint *)puVar2 = (int)PTR_DAT_00042adc - (int)puVar2 & 0xfffffff8;
      *(undefined4 *)(puVar2 + 4) = 0;
      *(undefined4 *)puVar1 = 1;
      puVar5 = (uint *)PTR_DAT_00042ad4;
    }
    uVar6 = *puVar3;
    if (uVar4 <= uVar6) {
      if (uVar4 < uVar6) {
        uVar8 = puVar3[1];
        piVar7 = (int *)((int)puVar3 + uVar4);
        *piVar7 = uVar6 - uVar4;
        piVar7[1] = uVar8;
      }
      else {
        piVar7 = (int *)puVar3[1];
      }
      *puVar5 = (uint)piVar7;
      *puVar3 = uVar4;
      puVar3 = puVar3 + 1;
      goto LAB_00042aac;
    }
    puVar5 = puVar3 + 1;
  } while( true );
}


/*############################################################################
 * 2.4 GHZ RF LINK  (57 functions)
 *
 *   0x00028AA0  FUN_00028aa0  (16 B)
 *   0x00029AB0  FUN_00029ab0  (28 B)
 *   0x00029ED8  FUN_00029ed8  (26 B)
 *   0x00029EF2  FUN_00029ef2  (38 B)
 *   0x00029F18  app_24_to_ble_force_pair_reset  (42 B)
 *   0x00029F42  app_24_to_ble_reset  (84 B)
 *   0x00029F96  switch_rf_mode_loop  (226 B)
 *   0x0002A0EC  app_start_led  (90 B)
 *   0x0002B24E  force_24g_sleep  (68 B)
 *   0x0002D2CE  APP_PARAM_UPDATE_REQ_IN  (146 B)
 *   0x0002F92A  FUN_0002f92a  (186 B)
 *   0x0002FA6C  FUN_0002fa6c  (34 B)
 *   0x0002FB36  ch_frequency  (232 B)
 *   0x0002FC1E  FUN_0002fc1e  (52 B)
 *   0x0002FC52  LightUp_Mode_Led  (368 B)
 *   0x0003046E  write_2  (46 B)
 *   0x0003143C  FUN_0003143c  (24 B)
 *   0x00031784  FUN_00031784  (32 B)
 *   0x000326B0  FUN_000326b0  (58 B)
 *   0x00032886  FUN_00032886  (12 B)
 *   0x00033D00  FUN_00033d00  (42 B)
 *   0x00033E24  FUN_00033e24  (16 B)
 *   0x000342B4  FUN_000342b4  (158 B)
 *   0x00034352  FUN_00034352  (182 B)
 *   0x00034408  FUN_00034408  (12 B)
 *   0x00034490  FUN_00034490  (32 B)
 *   0x000344B0  FUN_000344b0  (40 B)
 *   0x000344D8  FUN_000344d8  (24 B)
 *   0x000344F0  FUN_000344f0  (24 B)
 *   0x00034508  FUN_00034508  (48 B)
 *   0x00034538  FUN_00034538  (108 B)
 *   0x000345A4  FUN_000345a4  (46 B)
 *   0x00034D68  f_reconnect_24G  (228 B)
 *   0x00034E4E  mode_sw  (156 B)
 *   0x00035CFE  fWorkModeInit  (192 B)
 *   0x00036234  rgb_24g_test_cal  (42 B)
 *   0x00036C8E  FUN_00036c8e  (52 B)
 *   0x00036CD2  FUN_00036cd2  (28 B)
 *   0x00036D3A  FUN_00036d3a  (78 B)
 *   0x00036FB8  FUN_00036fb8  (12 B)
 *   0x00036FCE  FUN_00036fce  (12 B)
 *   0x000375FE  FUN_000375fe  (54 B)
 *   0x0003AA1A  FUN_0003aa1a  (40 B)
 *   0x0003AE7C  FUN_0003ae7c  (6 B)
 *   0x0003B130  FUN_0003b130  (34 B)
 *   0x0003B1DE  FUN_0003b1de  (26 B)
 *   0x0003BA88  FUN_0003ba88  (78 B)
 *   0x0003C0A8  FUN_0003c0a8  (50 B)
 *   0x0003C150  FUN_0003c150  (20 B)
 *   0x0003DC7E  FUN_0003dc7e  (50 B)
 *   0x0003DD00  FUN_0003dd00  (28 B)
 *   0x0003DD1C  FUN_0003dd1c  (30 B)
 *   0x0003DD3A  FUN_0003dd3a  (28 B)
 *   0x0003DD72  FUN_0003dd72  (28 B)
 *   0x0003E04E  FUN_0003e04e  (110 B)
 *   0x0003E0BC  FUN_0003e0bc  (94 B)
 *   0x0003E1EC  FUN_0003e1ec  (124 B)
 ############################################################################*/

/* ==========================================================================
 * FUN_00028aa0   @ 0x00028aa0   (16 bytes)
 * calls     : FUN_0003c0a8
 */

void FUN_00028aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  FUN_0003c0a8();
                    /* WARNING: Could not recover jumptable at 0x00028aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + -4))(param_1,param_2,param_3,param_4);
  return;
}

/* ==========================================================================
 * FUN_00029ab0   @ 0x00029ab0   (28 bytes)
 * called by : app_24_to_ble_force_pair_reset, app_24_to_ble_reset, app_ble_address_update, app_ble_to_ble_mode
 * calls     : FUN_0003e5f0
 */

void FUN_00029ab0(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00029d70;
  *(bool *)(DAT_00029d70 + 6) = param_1 != 1;
  FUN_0003e5f0(0x80,1,iVar1 + 6);
  return;
}

/* ==========================================================================
 * FUN_00029ed8   @ 0x00029ed8   (26 bytes)
 * called by : app_24_to_ble_force_pair_reset, force_pair_en
 * calls     : FUN_0003e5f0
 */

void FUN_00029ed8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = (undefined1)param_1;
  uStack_7 = (undefined3)((uint)param_4 >> 8);
  if (1 < param_1) {
    local_8 = 0;
  }
  FUN_0003e5f0(0x39,1,&local_8);
  return;
}

/* ==========================================================================
 * FUN_00029ef2   @ 0x00029ef2   (38 bytes)
 * called by : app_24_to_ble_force_pair_reset, app_24_to_ble_reset
 * calls     : FUN_0003e5f0
 */

void FUN_00029ef2(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_8;
  undefined3 uStack_7;
  
  _local_8 = CONCAT31((int3)((uint)param_4 >> 8),param_1);
  if (((*DAT_0002a2ec == '\x01') || (*DAT_0002a2ec == '\x02')) && (*DAT_0002a2f0 == '\0')) {
    FUN_0003e5f0(0x38,1,&local_8);
  }
  return;
}

/* ==========================================================================
 * app_24_to_ble_force_pair_reset   @ 0x00029f18   (42 bytes)
 * called by : FUN_0002b8a2, switch_rf_mode_loop
 * calls     : FUN_00029ab0, FUN_00029ed8, FUN_00029ef2, FUN_0003b130, FUN_0003b1de, dbg_printf
 * string    : "app_24_to_ble_force_pair_reset"
 * string    : "%s \r\n"
 */

void app_24_to_ble_force_pair_reset(void)

{
  undefined1 *puVar1;
  
  dbg_printf(DAT_0002a2f8,DAT_0002a2f4);
  puVar1 = DAT_0002a2ec;
  FUN_00029ab0(*DAT_0002a2ec);
  FUN_00029ef2(*puVar1);
  FUN_00029ed8(1);
  FUN_0003b1de(0);
  FUN_0003b130();
  return;
}

/* ==========================================================================
 * app_24_to_ble_reset   @ 0x00029f42   (84 bytes)
 * called by : switch_rf_mode_loop
 * calls     : FUN_00029ab0, FUN_00029ef2, FUN_0003b130, KEY_piaring_cnt, dbg_printf
 * string    : "%s \r\n"
 * string    : "app_24_to_ble_reset"
 * string    : "key press before cpu reset = %d,%d\r\n"
 */

undefined4 app_24_to_ble_reset(void)

{
  byte bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  
  dbg_printf(DAT_0002a2f8,DAT_0002a2f4 + -0x14);
  KEY_piaring_cnt();
  puVar2 = DAT_0002a2ec;
  FUN_00029ab0(*DAT_0002a2ec);
  KEY_piaring_cnt();
  FUN_00029ef2(*puVar2);
  KEY_piaring_cnt();
  pbVar3 = DAT_0002a2fc;
  if (*DAT_0002a2fc < 5) {
    FUN_0003b130();
  }
  *puVar2 = 0;
  *DAT_0002a300 = *DAT_0002a300 & 0xfd;
  bVar1 = *pbVar3;
  *DAT_0002a304 = bVar1;
  dbg_printf(str_key_press_before_cpu_reset_d_d,bVar1,*DAT_0002a308);
  return 1;
}

/* ==========================================================================
 * switch_rf_mode_loop   @ 0x00029f96   (226 bytes)
 * called by : Disconnected, app_mutli_link_change
 * calls     : FUN_0002cbda, FUN_00032886, FUN_0003e5f0, OLED_Clear, app_24_to_ble_force_pair_reset, app_24_to_ble_reset, ... (+4 more)
 * string    : "switch_rf_mode_loop"
 * string    : "%s : RF_MODE**********Simu_RF_MODE[%x to %x]\r\n"
 * string    : "force_pair_en 4========%x\r\n"
 * string    : "bonded0===========%x, bonded1========%x\r\n"
 * string    : " An error has occurred during access to the NVDS_TAG_RF_MODE \r\n"
 */

undefined4 switch_rf_mode_loop(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 local_18;
  
  pcVar4 = DAT_0002a334;
  pcVar2 = DAT_0002a2ec;
  local_18 = 0;
  dbg_printf(str_s_RF_MODE_Simu_RF_MODE_x_to_x,DAT_0002a2f4 + -0x28,*DAT_0002a2ec,*DAT_0002a334);
  puVar5 = DAT_0002a388;
  pcVar3 = DAT_0002a2f0;
  if (*DAT_0002a368 != '\0') {
    *DAT_0002a368 = '\0';
    dbg_printf(str_force_pair_en_4_x,0);
    return 0;
  }
  *DAT_0002a300 = *DAT_0002a300 | 2;
  if (*pcVar2 == '\0') {
    cVar1 = *pcVar4;
    *pcVar2 = cVar1;
    if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*pcVar3 == '\0')) {
      *puVar5 = 200;
      app_24_to_ble_reset();
      local_18 = 1;
      goto LAB_0002a040;
    }
  }
  else {
    dbg_printf(str_bonded0_x_bonded1_x,*DAT_0002a38c,DAT_0002a38c[1]);
    cVar1 = *pcVar4;
    *pcVar2 = cVar1;
    if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*pcVar3 == '\0')) {
      iVar6 = FUN_0002cbda();
      if (iVar6 == 0) {
        app_24_to_ble_force_pair_reset();
      }
      *puVar5 = 0x50;
      local_18 = app_ble_to_ble_mode();
      goto LAB_0002a040;
    }
    if (cVar1 != '\0') goto LAB_0002a040;
    *puVar5 = 0x32;
    app_user_ke_timer_stop();
  }
  FUN_00032886(0);
  fWorkModeInit();
LAB_0002a040:
  OLED_Clear();
  if (((*pcVar2 == '\x01') || (*pcVar2 == '\x02')) &&
     ((*pcVar3 == '\0' && (iVar6 = FUN_0003e5f0(0x38,1,DAT_0002a2ec), iVar6 != 0)))) {
    dbg_printf(str_An_error_has_occurred_during_access_to_the_N);
  }
  return local_18;
}

/* ==========================================================================
 * app_start_led   @ 0x0002a0ec   (90 bytes)
 * called by : APP_PARAM_UPDATE_REQ_IN, APP_PARAM_UPDATE_REQ_IND, BLE_PAIR
 * calls     : FUN_00032886, dbg_printf, rom_07342, rom_25078
 * string    : "app_start_led"
 * string    : "%s RF_MODE[%d]\r\n"
 */

void app_start_led(void)

{
  undefined1 *puVar1;
  undefined1 extraout_r1;
  
  dbg_printf(str_s_RF_MODE_d,DAT_0002a2f4 + 0x61,*DAT_0002a2ec);
  *DAT_0002a428 = 0;
  puVar1 = DAT_0002a430;
  *DAT_0002a42c = 0;
  *puVar1 = 1;
  FUN_00032886(*DAT_0002a434 == '\0');
  puVar1 = (undefined1 *)rom_25078(DAT_0002a430 + -0x10,0x13,DAT_0002a430[-7],DAT_0002a430[-7]);
  *(undefined1 *)(((uint)puVar1 >> 0x14) + 3) = extraout_r1;
  *(char *)(((uint)puVar1 >> 0x14) + 2) = (char)puVar1;
  *puVar1 = (char)puVar1;
  rom_07342(DAT_0002a438,3,0x19);
  return;
}

/* ==========================================================================
 * force_24g_sleep   @ 0x0002b24e   (68 bytes)
 * called by : SLEEP, set_Update_OLED
 * calls     : FUN_0003b528, dbg_printf, set_force_sleep
 * string    : "%s \r\n"
 * string    : "force_24g_sleep"
 */

void force_24g_sleep(void)

{
  int iVar1;
  
  *DAT_0002b570 = 1;
  dbg_printf(str_s_3,DAT_0002b554 + 0x20);
  iVar1 = DAT_0002b574;
  *(undefined4 *)(DAT_0002b574 + 0x18) = 0x80;
  *(undefined4 *)(iVar1 + 0x18) = 0xa0;
  *(undefined4 *)(DAT_0002b574 + 0x40) = 0x7e;
  set_force_sleep();
  *DAT_0002b578 = 200;
  *DAT_0002b57c = 0;
  *DAT_0002b580 = 0;
  *DAT_0002b584 = 3;
  FUN_0003b528();
  return;
}

/* ==========================================================================
 * APP_PARAM_UPDATE_REQ_IN   @ 0x0002d2ce   (146 bytes)
 * calls     : app_start_led, dbg_printf, rom_06F26, rom_07342, rom_073D4
 * string    : "0x%x "
 * string    : "encrypt_req_ind121\n"
 * string    : "APP_PARAM_UPDATE_REQ_IN-1  need update param after encryp \r\n"
 */

undefined4 APP_PARAM_UPDATE_REQ_IN(void)

{
  undefined1 unaff_r4;
  int unaff_r6;
  int unaff_r7;
  
  do {
    dbg_printf(PTR_str_s0x_x_0002d3f8,*(undefined1 *)(unaff_r7 + unaff_r6));
    unaff_r6 = unaff_r6 + 1;
  } while (unaff_r6 < 0x10);
  dbg_printf(&PTR_DAT_0002d3fc);
  dbg_printf(str_encrypt_req_ind121);
  rom_06F26();
  *DAT_0002d414 = *DAT_0002d414 | 0x200;
  *DAT_0002d418 = 0;
  *DAT_0002d41c = unaff_r4;
  dbg_printf(&DAT_0002d420);
  *PTR_DAT_0002d434 = unaff_r4;
  rom_073D4(PTR_DAT_0002d3a4 + 0xf3,3);
  if ((*PTR_DAT_0002d438 == '\0') || (6 < (byte)*PTR_DAT_0002d43c)) {
    *PTR_DAT_0002d438 = unaff_r4;
    rom_07342(PTR_DAT_0002d3a4 + 0xea,3,2);
    dbg_printf(str_APP_PARAM_UPDATE_REQ_IN_1_need_update_param);
  }
  else {
    *DAT_0002d480 = unaff_r4;
  }
  if (*DAT_0002d484 == '\0') {
    app_start_led();
  }
  rom_07342(PTR_DAT_0002d3a4 + 0xf7,3,200);
  return 0;
}

/* ==========================================================================
 * FUN_0002f92a   @ 0x0002f92a   (186 bytes)
 * calls     : FUN_00036c8e, FUN_00036caa, FUN_00036d3a, dbg_printf_2, rom_24F9C, rom_24FEC
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f92a(void)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  int iVar6;
  
  pcVar3 = DAT_0002fc9c;
  if (*DAT_0002fc9c == '\0') {
    FUN_00036caa();
    *_DAT_0002fcd0 = '\x01';
  }
  bVar1 = *DAT_0002fcd4;
  if ((bVar1 != 0) && (*PTR_DAT_0002fccc == '\0')) {
    cVar2 = *DAT_0002fcd8;
    *DAT_0002fcd8 = cVar2 + '\x01';
    rom_24FEC(DAT_0002fca4,0x20);
    puVar4 = DAT_0002fca4;
    *DAT_0002fca4 = 0x39;
    iVar6 = DAT_0002fcdc;
    puVar4[1] = cVar2 + '\x01';
    pbVar5 = DAT_0002fcd4;
    if (bVar1 < 0x1e) {
      rom_24F9C(puVar4 + 2,*(undefined4 *)(iVar6 + 4),bVar1);
      dbg_printf_2(str_RPT_STEP_13S,DAT_0002fca4,*pbVar5 + 2);
      *pbVar5 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 4);
      rom_24F9C(puVar4 + 2,iVar6,0x1e);
      *(int *)(DAT_0002fcdc + 4) = iVar6 + 0x1e;
      *DAT_0002fcd4 = bVar1 - 0x1e;
      dbg_printf_2(str_RPT_STEP_13L,DAT_0002fca4,0x20);
    }
    if (*_DAT_0002fcd0 != '\0') {
      *_DAT_0002fcd0 = '\0';
      FUN_00036c8e();
    }
    FUN_00036d3a(0x20);
    *DAT_0002fcb8 = 500;
    *pcVar3 = '\x06';
    *DAT_0002fca0 = *DAT_0002fca0 + '\x01';
    return;
  }
  *pcVar3 = '\x06';
  *DAT_0002fca0 = '\0';
  return;
}

/* ==========================================================================
 * FUN_0002fa6c   @ 0x0002fa6c   (34 bytes)
 * calls     : FUN_00031784, FUN_000369d8
 */

void FUN_0002fa6c(void)

{
  if (*PTR_DAT_0002fd00 == '\0') {
    FUN_00031784(200);
    FUN_000369d8();
    *DAT_0002fc9c = 6;
    *DAT_0002fca0 = 0;
  }
  return;
}

/* ==========================================================================
 * ch_frequency   @ 0x0002fb36   (232 bytes)
 * calls     : FUN_00031784, FUN_000369a0, FUN_000369ac, FUN_000369b8, FUN_00036c8e, FUN_00036caa, ... (+2 more)
 * string    : "SEND_ACK57 ok  RF24_STEP=%d,%d,%d\r\n"
 * string    : "ch_frequency 10=%x\r\n"
 * string    : "retr_time 57 ACK %x\r\n"
 */

void ch_frequency(void)

{
  undefined *puVar1;
  char *pcVar2;
  short *psVar3;
  int iVar4;
  undefined *puVar5;
  char cVar6;
  uint uVar7;
  undefined4 in_r3;
  
  uVar7 = *(uint *)PTR_DAT_0002fc94 & 0x70;
  *(uint *)PTR_DAT_0002fc94 = uVar7;
  iVar4 = DAT_0002fcdc;
  pcVar2 = DAT_0002fca0;
  puVar1 = PTR_DAT_0002fc94;
  if ((int)(uVar7 * 0x4000000) < 0) {
    *(int *)(DAT_0002fcdc + 4) = DAT_0002fcdc + 9;
    *DAT_0002fcd4 = *(char *)(iVar4 + 3) + -2;
    *DAT_0002fcd8 = 0;
    *PTR_DAT_0002fccc = 0;
    puVar5 = PTR_DAT_0002fd08;
    if (*pcVar2 == '\x06') {
      FUN_000369b8();
      FUN_00031784(200);
      cVar6 = '\t';
    }
    else if (*PTR_DAT_0002fd08 == '\0') {
      cVar6 = '\f';
    }
    else {
      cVar6 = '\v';
    }
    *pcVar2 = cVar6;
    dbg_printf(str_SEND_ACK57_ok_RF24_STEP_d_d_d,*pcVar2,*DAT_0002fd38,*puVar5,in_r3);
    *(undefined4 *)(puVar1 + -0x28) = 0xa0;
    *(undefined4 *)(puVar1 + -0x28) = 0x80;
  }
  else if ((int)(uVar7 << 0x1b) < 0) {
    *(undefined4 *)(PTR_DAT_0002fc94 + -0x28) = 0xa0;
    *(undefined4 *)(puVar1 + -0x28) = 0x80;
    FUN_000369ac();
    FUN_000369a0();
    puVar5 = PTR_DAT_0002fd94;
    psVar3 = DAT_0002fcb8;
    puVar1 = PTR_DAT_0002fc98;
    if (*DAT_0002fcb8 == 0) {
      *pcVar2 = '\0';
      *puVar5 = 0;
      *PTR_DAT_0002fd98 = 200;
      *PTR_DAT_0002fccc = 1;
      *(undefined2 *)PTR_DAT_0002fd9c = 0;
      if (*PTR_DAT_0002fda0 == '\0') {
        *PTR_DAT_0002fda4 = 3;
        return;
      }
    }
    else {
      cVar6 = *PTR_DAT_0002fc98;
      *PTR_DAT_0002fc98 = cVar6 + 1U;
      if (3 < (byte)(cVar6 + 1U)) {
        *puVar1 = 0;
        FUN_00036caa();
        FUN_00036c8e();
        dbg_printf(str_ch_frequency_10_x,*DAT_0002fd60);
      }
      FUN_00031784(0x5a);
      FUN_00036d3a(8);
      dbg_printf(str_retr_time_57_ACK_x,*psVar3);
    }
    return;
  }
  return;
}

/* ==========================================================================
 * FUN_0002fc1e   @ 0x0002fc1e   (52 bytes)
 * calls     : FUN_00036c8e, FUN_00036caa, FUN_00036d3a, dbg_printf_2
 */

void FUN_0002fc1e(void)

{
  if (*DAT_0002fc9c == '\0') {
    FUN_00036caa();
    FUN_00036c8e();
  }
  FUN_00036d3a(8);
  dbg_printf_2(&DAT_0002fda8,DAT_0002fca4,5);
  *DAT_0002fcb8 = 500;
  *DAT_0002fca0 = *DAT_0002fca0 + '\x01';
  return;
}

/* ==========================================================================
 * LightUp_Mode_Led   @ 0x0002fc52   (368 bytes)
 * calls     : CHRG, FUN_000312aa, FUN_0003143c, FUN_00031784, FUN_000317c2, FUN_00032892, ... (+10 more)
 * string    : "RF24_piar id_code:"
 * string    : "LightUp_Mode_Led============== %x,%x,%x,%x,%x,\r\n"
 * string    : "NO DONGLE %x,%x,%x,\r\n"
 */

void LightUp_Mode_Led(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined *puVar9;
  uint uVar10;
  
  puVar5 = PTR_DAT_0002fc94;
  if (*PTR_DAT_0002fdb8 != '\0') {
    *PTR_DAT_0002fdb8 = 0;
    *(undefined4 *)(puVar5 + -0x2c) = 1;
    FUN_000317c2(4);
    uVar10 = *(uint *)PTR_DAT_0002fc94;
    *(uint *)PTR_DAT_0002fc94 = uVar10 & 0x70;
    puVar5 = PTR_DAT_0002fdbc;
    puVar7 = DAT_0002fca0;
    puVar6 = DAT_0002fc9c;
    if ((int)((uVar10 & 0x70) << 0x19) < 0) {
      FUN_00036e88();
      pcVar8 = DAT_0002fca4;
      if (*DAT_0002fca4 == ';') {
        bVar1 = DAT_0002fca4[1];
        *(uint *)puVar5 = (uint)bVar1;
        bVar2 = pcVar8[2];
        *(uint *)(puVar5 + 4) = (uint)bVar2;
        bVar3 = pcVar8[3];
        *(uint *)(puVar5 + 8) = (uint)bVar3;
        puVar5 = PTR_DAT_0003012c;
        PTR_DAT_0003012c[0x10] = bVar1;
        puVar5[0x11] = bVar2;
        puVar5[0x12] = bVar3;
        dbg_printf(&DAT_00030130);
        write_2();
        *PTR_DAT_00030144 = 0;
        *PTR_DAT_00030148 = 0;
        *(undefined2 *)PTR_DAT_0003014c = 0;
        *PTR_DAT_00030150 = puVar5[0x12] & 3;
        FUN_00036c8e();
        FUN_00036cd2();
        FUN_00031784(200);
        FUN_000369d8();
        *PTR_DAT_00030154 = 200;
        FUN_0003143c();
        *puVar6 = 6;
        OLED_Init();
        puVar9 = PTR_DAT_00030158;
        *puVar7 = 0;
        *puVar9 = 0;
        *PTR_DAT_0003015c = 0;
        FUN_000312aa();
        dbg_printf_2(str_RF24_piar_id_code,puVar5 + 0x10,3);
        uVar4 = *PTR_DAT_00030174;
        *(undefined2 *)PTR_DAT_00030178 = 500;
        dbg_printf(str_LightUp_Mode_Led_x_x_x_x_x,*PTR_DAT_00030184,*PTR_DAT_00030180,
                   *(undefined2 *)PTR_DAT_0003017c,500,uVar4);
        FUN_00032892();
        *(undefined2 *)PTR_DAT_000301bc = 0;
        *PTR_DAT_000301c0 = 0;
        *PTR_DAT_000301c4 = 0;
        Success_led_2second();
        CHRG();
      }
    }
    else if (*(short *)PTR_DAT_000301bc == 0) {
      *PTR_DAT_00030150 = PTR_DAT_0003012c[0x12] & 3;
      FUN_00036c8e();
      FUN_00036cd2();
      FUN_000369d8();
      FUN_0003143c();
      *puVar6 = 6;
      puVar9 = PTR_DAT_000301c8;
      *puVar7 = 0;
      *(undefined2 *)puVar9 = 0;
      *PTR_DAT_000301c0 = 0;
      *PTR_DAT_000301cc = 0;
      puVar9 = PTR_DAT_000301d4;
      if (*PTR_DAT_00030158 == '\0') {
        if (*(short *)PTR_DAT_0003014c == 0) {
          if ((*PTR_DAT_000301d4 == '\0') && (*(undefined2 *)PTR_DAT_0003017c = 0, *puVar9 == '\0'))
          {
            *PTR_DAT_00030180 = 3;
          }
        }
        else {
          *puVar7 = 2;
        }
      }
      else {
        *PTR_DAT_00030158 = 0;
        *PTR_DAT_00030174 = 0;
        set_bonded_led_flash();
        *PTR_DAT_000301d0 = 1;
      }
      dbg_printf(str_NO_DONGLE_x_x_x,*(undefined4 *)puVar5,*(undefined4 *)(puVar5 + 4),
                 *(undefined4 *)(puVar5 + 8));
      return;
    }
  }
  return;
}

/* ==========================================================================
 * write_2   @ 0x0003046e   (46 bytes)
 * called by : LightUp_Mode_Led
 * calls     : dbg_printf_2, flash_write_some_data
 * string    : "write id_code:"
 */

void write_2(void)

{
  int iVar1;
  
  iVar1 = DAT_00030644;
  *(byte *)(DAT_00030644 + 0x13) = ~*(byte *)(DAT_00030644 + 0x10);
  *(byte *)(iVar1 + 0x14) = ~*(byte *)(iVar1 + 0x11);
  *(byte *)(iVar1 + 0x15) = ~*(byte *)(iVar1 + 0x12);
  flash_write_some_data(iVar1 + 0x10,DAT_000306a4,6);
  dbg_printf_2(str_write_id_code,iVar1 + 0x10,3);
  return;
}

/* ==========================================================================
 * FUN_0003143c   @ 0x0003143c   (24 bytes)
 * called by : FUN_000358b6, LightUp_Mode_Led, fWorkModeInit
 * calls     : rom_24FEC
 */

void FUN_0003143c(void)

{
  rom_24FEC(DAT_000315c8,0x20);
  *DAT_000315c8 = 0x3c;
  *DAT_000315a8 = 1;
  return;
}

/* ==========================================================================
 * FUN_00031784   @ 0x00031784   (32 bytes)
 * called by : FUN_0002abd4, FUN_0002fa6c, FUN_0002ff18, FUN_00033d00, FUN_00033d2c, FUN_00034352, ... (+21 more)
 */

void FUN_00031784(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*DAT_00031800 == '\x05') {
    param_1 = param_1 << 2;
  }
  for (iVar1 = 0; iVar1 < param_1; iVar1 = iVar1 + 1) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  }
  return;
}

/* ==========================================================================
 * FUN_000326b0   @ 0x000326b0   (58 bytes)
 * calls     : dbg_printf
 * string    : "%s, Simu_RF_MODE=%x,Mode_Indicator_BIT=%x\r\n"
 */

void FUN_000326b0(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  puVar2 = DAT_000329e4;
  *DAT_000329e4 = 0;
  cVar1 = *DAT_000329f4;
  if (*DAT_000329ec == '\0') {
    if (cVar1 == '\0') {
      uVar3 = 1;
    }
    else if (cVar1 == '\x01') {
      uVar3 = 2;
    }
    else {
      if (cVar1 != '\x02') goto LAB_000326de;
      uVar3 = 4;
    }
    *puVar2 = uVar3;
  }
LAB_000326de:
  dbg_printf(str_s_Simu_RF_MODE_x_Mode_Indicator_BIT_x,DAT_000329f8,cVar1,*puVar2);
  return;
}

/* ==========================================================================
 * FUN_00032886   @ 0x00032886   (12 bytes)
 * called by : FUN_00028c66, FUN_00031172, FUN_00032892, FUN_00035c9c, app_start_led, set_force_sleep, ... (+1 more)
 */

void FUN_00032886(byte param_1)

{
  byte bVar1;
  int iVar2;
  
  *DAT_00032a8c = param_1;
  iVar2 = DAT_000329e8;
  if ((param_1 & 1) == 0) {
    *(undefined4 *)(DAT_000329e8 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0x24) = 0;
    *(undefined4 *)(iVar2 + 0x20) = 0;
    return;
  }
  bVar1 = *DAT_000329e4;
  if ((bVar1 & 1) == 0) {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 2;
  }
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    *(undefined4 *)(iVar2 + 0x24) = 2;
  }
  else {
    *(undefined4 *)(iVar2 + 0x24) = 0;
  }
  if ((int)((uint)bVar1 << 0x1d) < 0) {
    *(undefined4 *)(iVar2 + 0x28) = 2;
    return;
  }
  *(undefined4 *)(iVar2 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * FUN_00033d00   @ 0x00033d00   (42 bytes)
 * called by : FUN_000342b4, FUN_00034352, FUN_00034408, FUN_00034414, FUN_00034490, FUN_000344b0, ... (+5 more)
 * calls     : FUN_00031784, FUN_0003aa1a
 */

void FUN_00033d00(byte param_1,undefined1 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = DAT_00033f70;
  *(undefined4 *)(DAT_00033f70 + 0x1c) = 0;
  puVar2 = PTR_DAT_00033f74;
  *PTR_DAT_00033f74 = param_1 | 0x80;
  puVar2[1] = param_2;
  FUN_0003aa1a(puVar2,2);
  FUN_00031784(0xc);
  *(undefined4 *)(iVar1 + 0x1c) = 2;
  FUN_00031784(5);
  return;
}

/* ==========================================================================
 * FUN_00033e24   @ 0x00033e24   (16 bytes)
 * calls     : FUN_000345a4
 */

void FUN_00033e24(void)

{
  if (*DAT_00033fb4 != '\0') {
    FUN_000345a4();
  }
  return;
}

/* ==========================================================================
 * FUN_000342b4   @ 0x000342b4   (158 bytes)
 * called by : FUN_000345d2
 * calls     : FUN_00033d00, FUN_00033d2c
 */

void FUN_000342b4(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_0003460c;
  if (param_1 == 0) {
    uVar1 = 0;
    do {
      FUN_00033d00(*(undefined1 *)(iVar2 + uVar1 * 2),*(undefined1 *)(uVar1 * 2 + iVar2 + 1));
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 0x15);
  }
  else if (param_1 == 1) {
    uVar1 = 0;
    iVar2 = DAT_0003460c + 0x2a;
    do {
      FUN_00033d00(*(undefined1 *)(iVar2 + uVar1 * 2),*(undefined1 *)(uVar1 * 2 + iVar2 + 1));
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 0x15);
  }
  else if (param_1 == 2) {
    uVar1 = 0;
    iVar2 = DAT_0003460c + 0x54;
    do {
      FUN_00033d00(*(undefined1 *)(iVar2 + uVar1 * 2),*(undefined1 *)(uVar1 * 2 + iVar2 + 1));
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 0x15);
  }
  else {
    if (param_1 == 3) {
      uVar1 = 0;
      iVar2 = DAT_0003460c + 0x7e;
      do {
        FUN_00033d00(*(undefined1 *)(iVar2 + uVar1 * 2),*(undefined1 *)(uVar1 * 2 + iVar2 + 1));
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 0x14);
      return;
    }
    if (2 < param_1) {
      return;
    }
  }
  uVar1 = FUN_00033d2c(0x40);
  FUN_00033d00(0x40,uVar1 & 0xfffffffc | param_1);
  return;
}

/* ==========================================================================
 * FUN_00034352   @ 0x00034352   (182 bytes)
 * called by : FUN_000345d2
 * calls     : FUN_00031784, FUN_00033d00, FUN_00033d2c
 */

void FUN_00034352(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = DAT_00034610;
  uVar4 = 0;
  do {
    FUN_00033d00(*(undefined1 *)(iVar5 + uVar4 * 2),*(undefined1 *)(uVar4 * 2 + iVar5 + 1));
    iVar1 = DAT_00034614;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x8c);
  FUN_00031784(DAT_00034614);
  bVar3 = 0;
  iVar5 = DAT_00034614 + 0xd;
  do {
    iVar2 = FUN_00033d2c(0x6c);
    if (iVar2 == 0x80) break;
    FUN_00031784(iVar5);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x3c);
  FUN_00031784(iVar1);
  if (bVar3 == 0x3c) {
    FUN_00033d00(0x7f,0x14);
    FUN_00033d00(0x6c,0);
    FUN_00033d00(0x7f,0);
  }
  FUN_00033d00(0x22,0);
  FUN_00033d00(0x55,0);
  FUN_00033d00(0x7f,7);
  FUN_00033d00(0x40);
  FUN_00033d00(0x7f,0);
  FUN_00033d00(0x68,1);
  FUN_00033d2c(2);
  FUN_00033d2c(3);
  FUN_00033d2c(4);
  FUN_00033d2c(5);
  FUN_00033d2c(6);
  return;
}

/* ==========================================================================
 * FUN_00034408   @ 0x00034408   (12 bytes)
 * called by : FUN_000345d2
 * calls     : FUN_00033d00
 */

void FUN_00034408(void)

{
  FUN_00033d00(0x3a,0x5a);
  return;
}

/* ==========================================================================
 * FUN_00034490   @ 0x00034490   (32 bytes)
 * calls     : FUN_00033d00
 */

void FUN_00034490(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = DAT_0003460c + 0xa6;
  do {
    FUN_00033d00(*(undefined1 *)(iVar2 + uVar1 * 2),*(undefined1 *)(uVar1 * 2 + iVar2 + 1));
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x16);
  return;
}

/* ==========================================================================
 * FUN_000344b0   @ 0x000344b0   (40 bytes)
 * called by : FUN_00034538
 * calls     : FUN_00033d00
 */

void FUN_000344b0(void)

{
  undefined4 uVar1;
  
  FUN_00033d00(0x7f,0xc);
  if (*(char *)(DAT_0003462c + 0x18) == '\0') {
    uVar1 = 8;
  }
  else {
    uVar1 = 10;
  }
  FUN_00033d00(0x4e,uVar1);
  FUN_00033d00(0x7f,0);
  return;
}

/* ==========================================================================
 * FUN_000344d8   @ 0x000344d8   (24 bytes)
 * called by : FUN_00034538
 * calls     : FUN_00033d00
 */

void FUN_000344d8(void)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_0003462c + 0x19) == '\0') {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x90;
  }
  FUN_00033d00(0x5a,uVar1);
  return;
}

/* ==========================================================================
 * FUN_000344f0   @ 0x000344f0   (24 bytes)
 * called by : FUN_00034538
 * calls     : FUN_00033d00
 */

void FUN_000344f0(void)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_0003462c + 0x1b) == '\0') {
    uVar1 = 0xd;
  }
  else {
    uVar1 = 0x8d;
  }
  FUN_00033d00(0x56,uVar1);
  return;
}

/* ==========================================================================
 * FUN_00034508   @ 0x00034508   (48 bytes)
 * called by : FUN_00034538
 * calls     : FUN_00033d00
 */

void FUN_00034508(void)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_0003462c + 0x1c) == '\0') {
    FUN_00033d00(0x7f,0xd);
    uVar1 = 0xdc;
  }
  else {
    FUN_00033d00(0x7f,0xd);
    uVar1 = 0xdd;
  }
  FUN_00033d00(0x48,uVar1);
  FUN_00033d00(0x7f,0);
  return;
}

/* ==========================================================================
 * FUN_00034538   @ 0x00034538   (108 bytes)
 * called by : FUN_000345d2, set_dpi
 * calls     : FUN_00033d00, FUN_000344b0, FUN_000344d8, FUN_000344f0, FUN_00034508
 */

void FUN_00034538(void)

{
  uint uVar1;
  
  *DAT_00034630 = 0;
  *DAT_00034634 = 0;
  uVar1 = (uint)CONCAT11(*(undefined1 *)((uint)*(byte *)(DAT_0003462c + 0x2d) + DAT_0003462c + 0x24)
                         ,*(undefined1 *)
                           ((uint)*(byte *)(DAT_0003462c + 0x2d) + DAT_0003462c + 0x1c));
  if (1 < uVar1) {
    uVar1 = uVar1 - 2 & 0xffff;
  }
  FUN_00033d00(0x48,uVar1 & 0xff);
  FUN_00033d00(0x49,uVar1 >> 8);
  FUN_00033d00(0x4a,uVar1 & 0xff);
  FUN_00033d00(0x4b,uVar1 >> 8);
  FUN_00033d00(0x47,1);
  FUN_000344d8();
  FUN_000344b0();
  FUN_000344f0();
  FUN_00034508();
  return;
}

/* ==========================================================================
 * FUN_000345a4   @ 0x000345a4   (46 bytes)
 * called by : FUN_00033e24
 * calls     : FUN_00033d00
 */

void FUN_000345a4(undefined4 param_1)

{
  FUN_00033d00(0x48,param_1);
  FUN_00033d00(0x49,0);
  FUN_00033d00(0x4a,param_1);
  FUN_00033d00(0x4b,0);
  FUN_00033d00(0x47,1);
  return;
}

/* ==========================================================================
 * f_reconnect_24G   @ 0x00034d68   (228 bytes)
 * called by : system_mode
 * calls     : FUN_0002b128, FUN_00031784, FUN_00033dc2, FUN_000369a0, FUN_000369ac, FUN_00036c8e, ... (+8 more)
 * string    : "24G reconnecting =%x \r\n"
 * string    : "f_reconnect_24G = OK \r\n"
 * string    : "f_reconnect_24G  overtime \r\n"
 * string    : "Time_24G_Piaring = 0 \r\n"
 */

void f_reconnect_24G(void)

{
  char *pcVar1;
  short *psVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  
  pcVar1 = DAT_0003508c;
  iVar5 = DAT_00034fb8;
  if (*DAT_0003508c != '\0') {
    *(undefined4 *)(DAT_00034fb8 + 0x14) = 1;
    cVar6 = '\x04';
    do {
      *(undefined4 *)(iVar5 + 0x18) = 0x80;
      *(undefined4 *)(iVar5 + 0x18) = 0xa0;
      FUN_000369ac();
      FUN_000369a0();
      *(undefined4 *)(DAT_00034fb8 + 0x40) = 0x10;
      FUN_00036caa();
      FUN_00036c8e();
      FUN_00031784(0x5a);
      rom_24FEC(DAT_000350cc,0x20);
      *DAT_000350cc = 0x3c;
      iVar4 = FUN_00036d3a(8);
      if (iVar4 != 0) break;
      bVar7 = cVar6 != '\0';
      cVar6 = cVar6 + -1;
    } while (bVar7);
    dbg_printf(str_s24G_reconnecting_x,*DAT_000350d0);
    psVar2 = DAT_000350ec;
    if (iVar4 == 0) {
      if (*DAT_000350d0 != 0) {
        *(undefined4 *)(iVar5 + 0x14) = 0;
        return;
      }
      *pcVar1 = '\0';
      dbg_printf(str_f_reconnect_24G_overtime);
      if (*psVar2 == 0) {
        *DAT_0003512c = 0;
        dbg_printf(str_Time_24G_Piaring_0);
        if (*DAT_00035024 == '\0') {
          *DAT_00035148 = 3;
        }
        iVar5 = FUN_0002b128();
        if ((iVar5 != 0) && ((*(uint *)(DAT_0003502c + 0x2c) & 1) == 0)) {
          FUN_00033dc2();
          return;
        }
      }
      else {
        set_bonded_led_flash();
        *pcVar1 = '\x01';
      }
      return;
    }
    dbg_printf(str_f_reconnect_24G_OK);
    Success_led_2second();
    ReLink();
    *pcVar1 = '\0';
    *DAT_00034fc4 = 0;
    puVar3 = DAT_00035108;
    *psVar2 = 0;
    *puVar3 = 6;
    OLED_Init();
  }
  return;
}

/* ==========================================================================
 * mode_sw   @ 0x00034e4e   (156 bytes)
 * called by : system_mode
 * calls     : FUN_0003b130, FUN_0003e552, dbg_printf
 * string    : " mode_sw to RF_24G_MODE\r\n"
 * string    : "mode_sw to RF_BLE_MODE1\r\n"
 */

void mode_sw(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  uint local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iVar5 = DAT_0003502c;
  if ((*DAT_00035024 != '\0') && (*DAT_0003514c != '\0')) {
    return;
  }
  *(undefined4 *)(DAT_0003502c + 0x10) = 0xc;
  pcVar6 = DAT_00035154;
  pcVar3 = DAT_00035150;
  cVar4 = *DAT_00035150 + -1;
  cVar1 = *DAT_00035154;
  local_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  if (((*(uint *)(iVar5 + 0x10) & 1) == 0) &&
     (((cVar1 == '\x01' || (cVar1 == '\x02')) && (*DAT_0003514c == '\0')))) {
    *DAT_00035150 = cVar4;
    puVar2 = DAT_00035064;
    if (cVar4 != '\0') {
      return;
    }
    *pcVar6 = '\0';
    *puVar2 = 0;
    pcVar6 = str_mode_sw_to_RF_24G_MODE;
    *pcVar3 = '\x05';
    goto LAB_00034edc;
  }
  if (((*(uint *)(iVar5 + 0x10) & 1) == 0) || (cVar1 != '\0')) {
    *DAT_00035150 = '\x05';
    return;
  }
  *DAT_00035150 = cVar4;
  if (cVar4 != '\0') {
    return;
  }
  iVar5 = FUN_0003e552(0x38,&uStack_1c,&local_20);
  if (iVar5 == 0) {
    if (((local_20 & 0xff) != 1) && ((local_20 & 0xff) != 2)) goto LAB_00034ed2;
    *pcVar6 = (char)local_20;
  }
  else {
LAB_00034ed2:
    *pcVar6 = '\x01';
  }
  *DAT_00035064 = 0;
  pcVar6 = str_mode_sw_to_RF_BLE_MODE1;
  *pcVar3 = '\x05';
LAB_00034edc:
  dbg_printf(pcVar6);
  FUN_0003b130();
  return;
}

/* ==========================================================================
 * fWorkModeInit   @ 0x00035cfe   (192 bytes)
 * called by : fn24main, switch_rf_mode_loop
 * calls     : FUN_0003143c, FUN_00031784, FUN_000369a0, FUN_000369d8, FUN_00036c8e, FUN_00036cd2, ... (+4 more)
 * string    : "RF24_STEP id:"
 * string    : "fWorkModeInit  RF24_STEP=%x, f_reconnect_24G=%x, Key_CurrentStatus=%x\r\n"
 */

void fWorkModeInit(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  *DAT_00035e48 = 0;
  *DAT_00035e4c = 0;
  FUN_000369a0();
  iVar1 = DAT_00035e50;
  *(undefined4 *)(DAT_00035e50 + 0x18) = 0xa0;
  *(undefined4 *)(iVar1 + 0x18) = 0x80;
  FUN_000369d8();
  puVar2 = DAT_00035e54;
  if (*DAT_00035e34 != '\0') {
    *DAT_00035e34 = '\0';
    *puVar2 = 4;
    return;
  }
  *DAT_00035e54 = 0;
  FUN_00036eee(8);
  puVar4 = DAT_00035e60;
  puVar2 = DAT_00035e5c;
  pcVar3 = DAT_00035e58;
  if (*DAT_00035e58 == '\0') {
    if ((((*DAT_00035e64 == '\x05') || (*DAT_00035e6c != '\0')) ||
        (*(char *)(DAT_00035e68 + 0x10) != '\x04')) ||
       ((*(char *)(DAT_00035e68 + 0x11) != '\0' || (*(char *)(DAT_00035e68 + 0x12) != '\0')))) {
      *DAT_00035e70 = *(byte *)(DAT_00035e68 + 0x12) & 3;
      FUN_00036c8e();
      FUN_00036cd2();
      FUN_00031784(200);
      FUN_000369d8();
      FUN_0003143c();
      *DAT_00035e74 = 6;
      *puVar2 = 0;
      set_bonded_led_flash();
      *puVar4 = 1;
    }
    else {
      *DAT_00035e5c = 2;
    }
  }
  else {
    *DAT_00035e5c = 2;
    *pcVar3 = '\0';
  }
  dbg_printf_2(str_RF24_STEP_id,DAT_00035e68 + 0x10,3);
  dbg_printf(DAT_00035e88,*puVar2,*puVar4,*DAT_00035e38);
  return;
}

/* ==========================================================================
 * rgb_24g_test_cal   @ 0x00036234   (42 bytes)
 * called by : TEST_SINGLE_WAVE_2
 * calls     : FUN_00032686, dbg_printf, rom_24F24, rom_25078
 * string    : "rgb_24g_test_cal:=%x\n"
 */

void rgb_24g_test_cal(undefined4 param_1)

{
  rom_24F24(param_1,3);
  dbg_printf(str_rgb_24g_test_cal_x);
  rom_25078();
  FUN_00032686(1);
  return;
}

/* ==========================================================================
 * FUN_00036c8e   @ 0x00036c8e   (52 bytes)
 * called by : FUN_0002f92a, FUN_0002fc1e, FUN_0002ff18, LightUp_Mode_Led, RPT_STEP, SLEEP, ... (+3 more)
 */

void FUN_00036c8e(void)

{
  int iVar1;
  
  *DAT_00036da0 =
       *(byte *)(DAT_00036dac +
                ((*(byte *)(DAT_00036da4 + 0x12) & 3) * 4 + (uint)*DAT_00036da8 & 0xff));
  iVar1 = DAT_00036d84;
  *(undefined4 *)(DAT_00036d84 + 0xd4) = 0;
  *(uint *)(DAT_00036d84 + 0x14) = *DAT_00036da0 + 0x80;
  *(undefined4 *)(iVar1 + 0xd4) = 1;
  return;
}

/* ==========================================================================
 * FUN_00036cd2   @ 0x00036cd2   (28 bytes)
 * called by : LightUp_Mode_Led, fWorkModeInit
 * calls     : FUN_000369fa
 */

void FUN_00036cd2(void)

{
  FUN_000369fa(DAT_00036d84 + 0x1c,DAT_00036d88,3);
  FUN_000369fa(DAT_00036d84 + 0x54,DAT_00036d88,3);
  return;
}

/* ==========================================================================
 * FUN_00036d3a   @ 0x00036d3a   (78 bytes)
 * called by : FUN_0002f92a, FUN_0002fc1e, ch_frequency, f_reconnect_24G
 * calls     : FUN_00031784, FUN_00036ad0
 */

bool FUN_00036d3a(undefined4 param_1)

{
  uint *puVar1;
  byte bVar2;
  
  puVar1 = DAT_00036db4;
  bVar2 = 0;
  DAT_00036db4[-10] = 0xa0;
  puVar1[-10] = 0x80;
  puVar1 = DAT_00036db4;
  *DAT_00036db4 = 0x7e;
  FUN_00036ad0(DAT_00036db8,param_1);
  FUN_00031784(0x15e);
  do {
    FUN_00031784(10);
    bVar2 = bVar2 + 1;
    if (5 < bVar2) break;
  } while ((*puVar1 & 0x7f) >> 4 == 0);
  return (int)(*puVar1 << 0x1a) < 0;
}

/* ==========================================================================
 * FUN_00036fb8   @ 0x00036fb8   (12 bytes)
 * called by : FUN_000375fe
 */

undefined2 FUN_00036fb8(void)

{
  return *(undefined2 *)(DAT_00037384 + 4);
}

/* ==========================================================================
 * FUN_00036fce   @ 0x00036fce   (12 bytes)
 * called by : FUN_000375fe
 */

undefined2 FUN_00036fce(void)

{
  return *(undefined2 *)(DAT_00037384 + 2);
}

/* ==========================================================================
 * FUN_000375fe   @ 0x000375fe   (54 bytes)
 * called by : FUN_0003c008
 * calls     : FUN_00031784, FUN_00036fb8, FUN_00036fce, FUN_00037534
 */

void FUN_000375fe(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  iVar3 = DAT_000376a4;
  uVar1 = *(undefined1 *)(DAT_000376a4 + 6);
  uVar2 = *(undefined1 *)(DAT_000376a4 + 0xe);
  uVar4 = FUN_00036fce();
  uVar5 = FUN_00036fb8();
  if (*DAT_000376a8 != 0) {
    FUN_00031784(0x3c);
  }
  FUN_00037534(uVar5,uVar4,uVar1);
  *(undefined1 *)(iVar3 + 0xe) = uVar2;
  return;
}

/* ==========================================================================
 * FUN_0003aa1a   @ 0x0003aa1a   (40 bytes)
 * called by : FUN_00033d00, FUN_00033d2c, FUN_0003443a
 */

void FUN_0003aa1a(byte *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DAT_0003ad08;
  do {
  } while (-1 < *(int *)(DAT_0003ad08 + 8) << 0x1e);
  *(uint *)(DAT_0003ad08 + 4) = param_2 << 8;
  for (; param_2 != 0; param_2 = param_2 - 1 & 0xff) {
    *(uint *)(iVar1 + 0xc) = (uint)*param_1;
    param_1 = param_1 + 1;
  }
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 1;
  return;
}

/* ==========================================================================
 * FUN_0003ae7c   @ 0x0003ae7c   (6 bytes)
 * called by : FUN_0003ba88
 */

void FUN_0003ae7c(undefined1 param_1)

{
  *DAT_0003b258 = param_1;
  return;
}

/* ==========================================================================
 * FUN_0003b130   @ 0x0003b130   (34 bytes)
 * called by : FUN_0003ba88, FUN_0003dc7e, SLEEP, This, USNDP_status_2, app_24_to_ble_force_pair_reset, ... (+7 more)
 * calls     : FUN_00031784
 */

void FUN_0003b130(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)(DAT_0003b254 + -0x40);
  *(uint *)(DAT_0003b254 + -0x3c) = *(uint *)(DAT_0003b254 + -0x3c) | 0x8000;
  FUN_00031784(2000);
  *puVar1 = *puVar1 | 1;
  return;
}

/* ==========================================================================
 * FUN_0003b1de   @ 0x0003b1de   (26 bytes)
 * called by : app_24_to_ble_force_pair_reset
 * calls     : dbg_printf
 * string    : "set reset reason=%x\r\n"
 */

void FUN_0003b1de(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_0003b254;
  *(uint *)(DAT_0003b254 + -0x3c) = *(uint *)(DAT_0003b254 + -0x3c) | 8;
  *(undefined4 *)(iVar1 + -0x34) = param_1;
  dbg_printf(str_set_reset_reason_x,*(undefined4 *)(iVar1 + -0x34));
  return;
}

/* ==========================================================================
 * FUN_0003ba88   @ 0x0003ba88   (78 bytes)
 * calls     : FUN_0003ae7c, FUN_0003b130
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003ba88(char *param_1,int param_2)

{
  byte bVar1;
  
  if (*param_1 == '\0') {
    if (param_2 == 1) {
      bVar1 = *(byte *)(DAT_0003bd0c + 2);
      *(byte *)(DAT_0003bd0c + 2) = bVar1 + 1;
      if (2 < bVar1) {
        FUN_0003ae7c(0);
      }
      param_1[1] = '\0';
      return;
    }
  }
  else if ((*param_1 == -2) && (param_2 == 5)) {
    if (((uint)(byte)param_1[4] | (uint)(byte)param_1[1] << 0x18 |
        (uint)(byte)param_1[2] << 0x10 | (uint)(byte)param_1[3] << 8) == _LAB_0003bd1c) {
      FUN_0003b130();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0003c0a8   @ 0x0003c0a8   (50 bytes)
 * called by : FUN_00028aa0
 * calls     : FUN_0003c150, FUN_0003dc7e, FUN_0003e1ec
 */

void FUN_0003c0a8(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_0003c0dc;
  uVar2 = 0;
  iVar3 = *(int *)(DAT_0003c0dc + 8);
  if (iVar3 << 9 < 0) {
    uVar2 = DAT_0003c0dc << 0x10;
    FUN_0003e1ec();
  }
  if (iVar3 << 0xb < 0) {
    uVar2 = uVar2 | 0x100000;
    FUN_0003dc7e();
  }
  if (iVar3 << 0xd < 0) {
    uVar2 = uVar2 | 0x40000;
    FUN_0003c150();
  }
  *(uint *)(iVar1 + 8) = uVar2;
  return;
}

/* ==========================================================================
 * FUN_0003c150   @ 0x0003c150   (20 bytes)
 * called by : FUN_0003c0a8
 */

void FUN_0003c150(void)

{
  *(undefined4 *)(DAT_0003c16c + 4) = 0xffffffff;
  if (*(code **)(DAT_0003c170 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0003c160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_0003c170 + 8))();
    return;
  }
  return;
}

/* ==========================================================================
 * FUN_0003dc7e   @ 0x0003dc7e   (50 bytes)
 * called by : FUN_0003c0a8
 * calls     : FUN_0003b130, dbg_printf
 * string    : "%s irq_stat(%x) \r\n"
 * string    : "err:%x \r\n"
 */

void FUN_0003dc7e(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0003dccc;
  while( true ) {
    iVar2 = *(int *)(iVar1 + 0x10);
    dbg_printf(str_s_irq_stat_x,DAT_0003dcd0,iVar2);
    if (iVar2 == 0) break;
    if (iVar2 << 0xf < 0) {
      *(undefined4 *)(iVar1 + 0x14) = 0x10000;
      dbg_printf(str_err_x,*(undefined4 *)(iVar1 + 0x60));
      FUN_0003b130();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0003dd00   @ 0x0003dd00   (28 bytes)
 * called by : FUN_0003e0bc, FUN_0003e1ec
 * calls     : rom_15C40
 */

void FUN_0003dd00(void)

{
  *DAT_0003e100 = 0xffffffff;
  DAT_00820018 = DAT_00820018 & 0xffffffef;
  rom_15C40();
  return;
}

/* ==========================================================================
 * FUN_0003dd1c   @ 0x0003dd1c   (30 bytes)
 * called by : FUN_0003e0bc, FUN_0003e1ec
 * calls     : rom_06B28
 */

void FUN_0003dd1c(void)

{
  *(undefined4 *)(DAT_0003e100 + 8) = 0xffffffff;
  DAT_00820018 = DAT_00820018 & 0xffffffbf;
  rom_06B28(3);
  return;
}

/* ==========================================================================
 * FUN_0003dd3a   @ 0x0003dd3a   (28 bytes)
 * called by : FUN_0003e0bc, FUN_0003e1ec
 * calls     : rom_16216
 */

void FUN_0003dd3a(void)

{
  *(undefined4 *)(DAT_0003e100 + 4) = 0xffffffff;
  DAT_00820018 = DAT_00820018 & 0xffffffdf;
  rom_16216();
  return;
}

/* ==========================================================================
 * FUN_0003dd72   @ 0x0003dd72   (28 bytes)
 * called by : FUN_0003e1ec
 * calls     : rom_06B28, rom_1809E
 */

void FUN_0003dd72(void)

{
  rom_1809E(0x10);
  DAT_00820018 = DAT_00820018 & 0xfffffffb;
  rom_06B28(1);
  return;
}

/* ==========================================================================
 * FUN_0003e04e   @ 0x0003e04e   (110 bytes)
 * called by : FUN_0003e1ec
 * calls     : rom_069C4, rom_18074, rom_24F24
 */

void FUN_0003e04e(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = DAT_00820038;
  rom_18074(1);
  DAT_00820030 = DAT_00820030 & 0x7fffffff;
  uVar4 = *(int *)(DAT_0003e100 + 0xc) + iVar3;
  uVar2 = uVar4 >> 1;
  *(uint *)(DAT_0003e100 + 0xc) = uVar4 + uVar2 * -2;
  iVar5 = iVar3 * 0x3e + uVar2;
  uVar2 = rom_24F24(iVar5,DAT_0003e1c4);
  puVar1 = DAT_0003e1c8;
  iVar3 = uVar2 * DAT_0003e1c4;
  DAT_0003e1c8[1] = uVar2 | 0x80000000;
  *puVar1 = 0x270U - (iVar5 - iVar3) & 0xffff;
  DAT_00820030 = DAT_00820030 & 0xfffffff7 | 8;
  DAT_00820018 = 1;
  DAT_00820020 = 0xffffffff;
  rom_069C4();
  return;
}

/* ==========================================================================
 * FUN_0003e0bc   @ 0x0003e0bc   (94 bytes)
 * called by : FUN_0003e1ec
 * calls     : FUN_0003dd00, FUN_0003dd1c, FUN_0003dd3a, rom_1804C, rom_1809E
 */

void FUN_0003e0bc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  uint local_18;
  undefined4 uStack_14;
  
  local_18 = param_3;
  uStack_14 = param_4;
  rom_1804C(&local_18);
  DAT_00820018 = DAT_00820018 & 0xfffffffe;
  if (*(code **)(DAT_0003e1cc + 0x20) != (code *)0x0) {
    (**(code **)(DAT_0003e1cc + 0x20))();
  }
  piVar1 = DAT_0003e100;
  DAT_00820018 = DAT_0003e10c;
  if (*DAT_0003e100 != -1) {
    FUN_0003dd00();
  }
  if (piVar1[1] != -1) {
    FUN_0003dd3a();
  }
  uVar2 = piVar1[2];
  if (uVar2 != 0xffffffff) {
    if (local_18 < uVar2) {
      DAT_00820018 = DAT_00820018 & 0xffffffbf | 0x40;
    }
    else {
      FUN_0003dd1c();
    }
  }
  rom_1809E(1);
  return;
}

/* ==========================================================================
 * FUN_0003e1ec   @ 0x0003e1ec   (124 bytes)
 * called by : FUN_0003c0a8
 * calls     : FUN_0003dd00, FUN_0003dd1c, FUN_0003dd3a, FUN_0003dd72, FUN_0003e04e, FUN_0003e0bc, ... (+3 more)
 */

void FUN_0003e1ec(void)

{
  uint uVar1;
  
  uVar1 = DAT_0082001c;
  if ((int)(DAT_0082001c << 0x1b) < 0) {
    DAT_00820020 = 0x10;
    FUN_0003dd00();
  }
  if ((int)(uVar1 << 0x1a) < 0) {
    DAT_00820020 = 0x20;
    FUN_0003dd3a();
  }
  if ((uVar1 & 1) != 0) {
    DAT_00820020 = 1;
    if ((*(byte *)(DAT_0003e444 + 0x16) & 1) != 0) {
      FUN_0003e0bc();
    }
  }
  if ((int)(uVar1 << 0x10) < 0) {
    rom_1695E();
    DAT_00820020 = 0x8000;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    DAT_00820020 = 2;
    FUN_0003e04e();
    rom_1809E(0x1000);
  }
  if ((int)(uVar1 << 0x19) < 0) {
    DAT_00820020 = 0x40;
    FUN_0003dd1c();
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    DAT_00820020 = 4;
    FUN_0003dd72();
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    DAT_00820020 = 8;
    rom_18038();
  }
  return;
}


/*############################################################################
 * BLUETOOTH LE  (214 functions)
 *
 *   0x00028AC0  FUN_00028ac0  (16 B)
 *   0x00028B00  FUN_00028b00  (54 B)
 *   0x00028B36  force_pair_en  (268 B)
 *   0x00028C48  FUN_00028c48  (6 B)
 *   0x00028C4E  FUN_00028c4e  (24 B)
 *   0x00028C66  FUN_00028c66  (242 B)
 *   0x00028D58  enter_BLE_normal_app_mode  (572 B)
 *   0x00029164  FUN_00029164  (12 B)
 *   0x00029392  FUN_00029392  (46 B)
 *   0x000293C0  limit  (164 B)
 *   0x00029490  FUN_00029490  (38 B)
 *   0x000294B6  adv_data  (66 B)
 *   0x00029530  FUN_00029530  (78 B)
 *   0x0002957E  appm_add_svc  (44 B)
 *   0x000295AA  FUN_000295aa  (36 B)
 *   0x000295CE  appm_create_advertising  (198 B)
 *   0x00029694  appm_delete_advertising  (36 B)
 *   0x000296B8  adv_state  (42 B)
 *   0x00029704  appm_update_param  (96 B)
 *   0x000298E8  app_ble_addr_tabl_init  (160 B)
 *   0x000299CC  save  (56 B)
 *   0x00029A42  FUN_00029a42  (26 B)
 *   0x00029A5C  app_env  (84 B)
 *   0x00029ACC  app_ble_address_update  (84 B)
 *   0x00029B20  sys_flag  (264 B)
 *   0x00029C28  app_ble_to_ble_mode  (68 B)
 *   0x0002A078  force  (50 B)
 *   0x0002A0AA  FUN_0002a0aa  (22 B)
 *   0x0002A0C0  FUN_0002a0c0  (44 B)
 *   0x0002A152  BLE_PAIR  (484 B)
 *   0x0002A4E2  app_bond_status_initial  (152 B)
 *   0x0002A57A  APP_PARAM_UPDATE_REQ_IND  (106 B)
 *   0x0002A5E4  FUN_0002a5e4  (20 B)
 *   0x0002A5F8  FUN_0002a5f8  (28 B)
 *   0x0002A614  there  (96 B)
 *   0x0002A674  FUN_0002a674  (42 B)
 *   0x0002A70E  ble_alert_led_start  (98 B)
 *   0x0002A770  ble_alert_led_stop  (28 B)
 *   0x0002A78C  FUN_0002a78c  (26 B)
 *   0x0002AA5C  FUN_0002aa5c  (276 B)
 *   0x0002AB70  FUN_0002ab70  (56 B)
 *   0x0002ABBA  FUN_0002abba  (14 B)
 *   0x0002ABD4  FUN_0002abd4  (58 B)
 *   0x0002AC0E  FUN_0002ac0e  (210 B)
 *   0x0002B292  force_ble_sleep  (162 B)
 *   0x0002B3AC  FUN_0002b3ac  (22 B)
 *   0x0002B4C8  FUN_0002b4c8  (22 B)
 *   0x0002B4DE  FUN_0002b4de  (16 B)
 *   0x0002B4EE  app_mutli_link_change  (516 B)
 *   0x0002B8A2  FUN_0002b8a2  (148 B)
 *   0x0002BDC4  FUN_0002bdc4  (18 B)
 *   0x0002BEF8  FUN_0002bef8  (12 B)
 *   0x0002BF30  FUN_0002bf30  (44 B)
 *   0x0002BF5C  FUN_0002bf5c  (44 B)
 *   0x0002BF88  FUN_0002bf88  (34 B)
 *   0x0002C044  FUN_0002c044  (2 B)
 *   0x0002C158  FUN_0002c158  (54 B)
 *   0x0002C378  FUN_0002c378  (44 B)
 *   0x0002C5E8  hogpd_ctnl_pt_ind_handler  (80 B)
 *   0x0002C638  hogpd_ntf_cfg_ind_handler  (92 B)
 *   0x0002CA10  FUN_0002ca10  (8 B)
 *   0x0002CA56  FUN_0002ca56  (42 B)
 *   0x0002CAD2  FUN_0002cad2  (42 B)
 *   0x0002CAFE  FUN_0002cafe  (44 B)
 *   0x0002CBDA  FUN_0002cbda  (18 B)
 *   0x0002CBEC  app_sec_init  (148 B)
 *   0x0002CC82  app_sec_send_security_req  (66 B)
 *   0x0002D4E4  gapm_activity_created_ind_handler  (26 B)
 *   0x0002D4FE  gapm_activity_stopped_ind_handler  (30 B)
 *   0x0002D53C  FUN_0002d53c  (530 B)
 *   0x0002DD92  ble_update_param_failed_cnt  (94 B)
 *   0x0002E398  loc_irk  (78 B)
 *   0x0002EBF8  force_ble_sleep_2  (150 B)
 *   0x0002F31C  FUN_0002f31c  (84 B)
 *   0x0002F3F4  app_ancsc_init  (18 B)
 *   0x0002F406  app_ancs_add_ancsc  (50 B)
 *   0x0002F438  FUN_0002f438  (40 B)
 *   0x0002F460  app_ancsc_msg_dflt_handler  (16 B)
 *   0x0002F58A  app_ancsc_delete_call  (74 B)
 *   0x0002F5D4  FUN_0002f5d4  (72 B)
 *   0x00031114  FUN_00031114  (94 B)
 *   0x00031172  FUN_00031172  (66 B)
 *   0x000311DE  FUN_000311de  (50 B)
 *   0x00031210  FUN_00031210  (32 B)
 *   0x000312AA  FUN_000312aa  (52 B)
 *   0x00031334  FUN_00031334  (210 B)
 *   0x00031406  FUN_00031406  (54 B)
 *   0x0003186E  FUN_0003186e  (262 B)
 *   0x00031974  FUN_00031974  (12 B)
 *   0x00031980  FUN_00031980  (64 B)
 *   0x000319C0  FUN_000319c0  (194 B)
 *   0x00031B3E  FUN_00031b3e  (112 B)
 *   0x00031F7C  FUN_00031f7c  (24 B)
 *   0x00032620  FUN_00032620  (12 B)
 *   0x00032686  FUN_00032686  (42 B)
 *   0x000326EA  FUN_000326ea  (48 B)
 *   0x000332BE  FUN_000332be  (156 B)
 *   0x00033DC2  FUN_00033dc2  (8 B)
 *   0x0003443A  FUN_0003443a  (86 B)
 *   0x00035800  FUN_00035800  (122 B)
 *   0x00035A5E  disconnect  (94 B)
 *   0x00035ABC  FUN_00035abc  (76 B)
 *   0x00035B08  FUN_00035b08  (74 B)
 *   0x00035CD2  FUN_00035cd2  (44 B)
 *   0x0003723E  FUN_0003723e  (32 B)
 *   0x00038DA4  Get_MODE_Switch_status  (82 B)
 *   0x00038F4E  FUN_00038f4e  (12 B)
 *   0x00039198  FUN_00039198  (40 B)
 *   0x000393BC  FUN_000393bc  (76 B)
 *   0x00039408  FUN_00039408  (32 B)
 *   0x00039428  FUN_00039428  (18 B)
 *   0x0003948A  FUN_0003948a  (156 B)
 *   0x00039A84  FUN_00039a84  (84 B)
 *   0x00039B82  FUN_00039b82  (44 B)
 *   0x00039BC2  FUN_00039bc2  (10 B)
 *   0x00039BCC  FUN_00039bcc  (22 B)
 *   0x00039C02  FUN_00039c02  (2 B)
 *   0x0003A244  FUN_0003a244  (218 B)
 *   0x0003A688  FUN_0003a688  (68 B)
 *   0x0003AAD4  FUN_0003aad4  (92 B)
 *   0x0003ABF2  FUN_0003abf2  (132 B)
 *   0x0003AE40  FUN_0003ae40  (54 B)
 *   0x0003AE82  FUN_0003ae82  (170 B)
 *   0x0003AF2C  FUN_0003af2c  (64 B)
 *   0x0003AF8A  FUN_0003af8a  (24 B)
 *   0x0003B0B8  FUN_0003b0b8  (102 B)
 *   0x0003B152  reset  (140 B)
 *   0x0003B34C  FUN_0003b34c  (166 B)
 *   0x0003B47E  FUN_0003b47e  (106 B)
 *   0x0003B512  FUN_0003b512  (22 B)
 *   0x0003B538  FUN_0003b538  (22 B)
 *   0x0003B5E6  FUN_0003b5e6  (18 B)
 *   0x0003B6F6  FUN_0003b6f6  (72 B)
 *   0x0003B8E0  FUN_0003b8e0  (30 B)
 *   0x0003B904  FUN_0003b904  (46 B)
 *   0x0003B932  FUN_0003b932  (124 B)
 *   0x0003BA0A  FUN_0003ba0a  (40 B)
 *   0x0003BA28  FUN_0003ba28  (30 B)
 *   0x0003BA46  FUN_0003ba46  (40 B)
 *   0x0003BA6E  FUN_0003ba6e  (26 B)
 *   0x0003BAD6  FUN_0003bad6  (32 B)
 *   0x0003BB38  FUN_0003bb38  (498 B)
 *   0x0003BD90  FUN_0003bd90  (58 B)
 *   0x0003BDCA  FUN_0003bdca  (28 B)
 *   0x0003BDE6  FUN_0003bde6  (178 B)
 *   0x0003BE98  FUN_0003be98  (12 B)
 *   0x0003BF40  FUN_0003bf40  (88 B)
 *   0x0003BFC2  FUN_0003bfc2  (70 B)
 *   0x0003C008  FUN_0003c008  (160 B)
 *   0x0003C438  FUN_0003c438  (84 B)
 *   0x0003C48C  FUN_0003c48c  (84 B)
 *   0x0003C52E  FUN_0003c52e  (6 B)
 *   0x0003C574  FUN_0003c574  (6 B)
 *   0x0003C6CE  FUN_0003c6ce  (106 B)
 *   0x0003CFB8  CHRG  (46 B)
 *   0x0003CFE6  ReLink  (38 B)
 *   0x0003D00C  ReLinking  (38 B)
 *   0x0003D032  Pairing  (48 B)
 *   0x0003D5BE  Linking  (30 B)
 *   0x0003DC3C  FUN_0003dc3c  (66 B)
 *   0x0003DCB0  FUN_0003dcb0  (18 B)
 *   0x0003DCF8  FUN_0003dcf8  (8 B)
 *   0x0003DD8E  FUN_0003dd8e  (350 B)
 *   0x0003DEEE  rwip_driver_init  (228 B)
 *   0x0003DFD2  FUN_0003dfd2  (108 B)
 *   0x0003E03E  FUN_0003e03e  (16 B)
 *   0x0003E268  FUN_0003e268  (44 B)
 *   0x0003E294  RC32K  (24 B)
 *   0x0003E304  FUN_0003e304  (300 B)
 *   0x0003E432  FUN_0003e432  (16 B)
 *   0x0003E498  FUN_0003e498  (58 B)
 *   0x0003E516  FUN_0003e516  (60 B)
 *   0x0003E552  FUN_0003e552  (62 B)
 *   0x0003E590  FUN_0003e590  (52 B)
 *   0x0003E5C4  FUN_0003e5c4  (44 B)
 *   0x0003E5F0  FUN_0003e5f0  (242 B)
 *   0x0003E6E2  FUN_0003e6e2  (52 B)
 *   0x0003E716  FUN_0003e716  (28 B)
 *   0x0003E732  FUN_0003e732  (96 B)
 *   0x0003E800  prf_register_atthdl2gatt  (84 B)
 *   0x0003E958  FUN_0003e958  (30 B)
 *   0x0003EDEE  FUN_0003edee  (44 B)
 *   0x0003EE6E  FUN_0003ee6e  (52 B)
 *   0x0003EF20  FUN_0003ef20  (40 B)
 *   0x0003EF48  FUN_0003ef48  (126 B)
 *   0x0003F25E  FUN_0003f25e  (26 B)
 *   0x0003F3B0  FUN_0003f3b0  (28 B)
 *   0x0003F46A  FUN_0003f46a  (32 B)
 *   0x0003F53A  gattc_att_info_req_ind_handler_2  (106 B)
 *   0x0003F86C  FUN_0003f86c  (32 B)
 *   0x0003F9A0  FUN_0003f9a0  (286 B)
 *   0x0003FAAA  FUN_0003faaa  (122 B)
 *   0x0003FB6A  FUN_0003fb6a  (112 B)
 *   0x0003FD6E  FUN_0003fd6e  (102 B)
 *   0x0003FDD4  FUN_0003fdd4  (78 B)
 *   0x0003FF92  FUN_0003ff92  (26 B)
 *   0x000400C6  FUN_000400c6  (28 B)
 *   0x00040134  FUN_00040134  (30 B)
 *   0x000401AA  gattc_att_info_req_ind_handler  (98 B)
 *   0x00040400  FUN_00040400  (32 B)
 *   0x000405AE  FUN_000405ae  (274 B)
 *   0x00040F64  gattc_cmp_evt_handler  (16 B)
 *   0x00040F74  FUN_00040f74  (30 B)
 *   0x00041034  FUN_00041034  (244 B)
 *   0x00041160  FUN_00041160  (992 B)
 *   0x00041798  FUN_00041798  (164 B)
 *   0x00041922  FUN_00041922  (224 B)
 *   0x00041A10  hogpd_proto_mode_cfm_handler  (176 B)
 *   0x00041E78  FUN_00041e78  (28 B)
 *   0x000420EE  FUN_000420ee  (64 B)
 *   0x00042132  FUN_00042132  (130 B)
 *   0x00042430  FUN_00042430  (28 B)
 *   0x00042450  FUN_00042450  (14 B)
 *   0x000429FC  FUN_000429fc  (28 B)
 ############################################################################*/

/* ==========================================================================
 * FUN_00028ac0   @ 0x00028ac0   (16 bytes)
 * calls     : FUN_0003c008
 */

void FUN_00028ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  FUN_0003c008();
                    /* WARNING: Could not recover jumptable at 0x00028acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + -4))(param_1,param_2,param_3,param_4);
  return;
}

/* ==========================================================================
 * FUN_00028b00   @ 0x00028b00   (54 bytes)
 * called by : TEST_SINGLE_WAVE_2, enter_BLE_normal_app_mode
 * calls     : rom_24FEC
 */

void FUN_00028b00(void)

{
  undefined4 *puVar1;
  
  rom_24FEC(DAT_00028efc,0x28);
  puVar1 = DAT_00028efc;
  *DAT_00028efc = DAT_00028f00;
  puVar1[1] = DAT_00028f04;
  puVar1[2] = DAT_00028f08;
  puVar1[3] = DAT_00028f0c;
  puVar1[4] = DAT_00028f10;
  puVar1[5] = DAT_00028f14;
  puVar1[6] = DAT_00028f18;
  puVar1[7] = DAT_00028f1c;
  puVar1[8] = DAT_00028f20;
  puVar1[9] = DAT_00028f24;
  return;
}

/* ==========================================================================
 * force_pair_en   @ 0x00028b36   (268 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_00029ed8, FUN_0003948a, FUN_0003e552, FUN_0003e5f0, Get_MODE_Switch_status, app_ble_addr_tabl_init, ... (+7 more)
 * string    : "Rf mode  =  %x,\r\n"
 * string    : "flash7E000 mac addr:"
 * string    : "force_pair_en ========%x\r\n"
 * string    : "ble address set:"
 * string    : "flash7E100 SumAddr:"
 */

undefined8 force_pair_en(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 *puVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined1 uVar4;
  int iVar5;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  char local_1c;
  char local_1b;
  undefined2 uStack_1a;
  undefined1 local_18;
  undefined3 uStack_17;
  uint local_14;
  
  local_1c = (char)param_2;
  local_1b = (char)((uint)param_2 >> 8);
  uStack_1a = (undefined2)((uint)param_2 >> 0x10);
  local_20 = (char)param_1;
  local_1f = (char)((uint)param_1 >> 8);
  local_1e = (char)((uint)param_1 >> 0x10);
  local_1d = (char)((uint)param_1 >> 0x18);
  _local_18 = CONCAT31((int3)((uint)param_3 >> 8),1);
  local_14 = param_4;
  iVar5 = Get_MODE_Switch_status();
  puVar1 = DAT_00028f28;
  uVar4 = 0;
  if (iVar5 != 0) {
    *DAT_00028f28 = 1;
    iVar5 = FUN_0003e552(0x38,&local_18,&local_14);
    if (iVar5 != 0) {
      FUN_0003e5f0(0x38,1,puVar1);
      goto LAB_00028b62;
    }
    uVar4 = (undefined1)local_14;
    if (((local_14 & 0xff) != 1) && ((local_14 & 0xff) != 2)) {
      *puVar1 = 1;
      goto LAB_00028b62;
    }
  }
  *puVar1 = uVar4;
LAB_00028b62:
  dbg_printf(str_Rf_mode_x,*puVar1);
  FUN_0003948a(&local_20,0x7e000,6);
  if ((((local_20 != -1) || (local_1f != -1)) || (local_1e != -1)) ||
     (((local_1d != -1 || (local_1c != -1)) || (local_1b != -1)))) {
    rom_24F9C(DAT_00028f40,&local_20,6);
  }
  dbg_printf_2(str_flash7E000_mac_addr,&local_20,6);
  app_ble_addr_tabl_init();
  app_bond_status_initial();
  puVar2 = DAT_00028f5c;
  *DAT_00028f5c = *DAT_00028f5c & 0xfffffffa;
  pbVar3 = DAT_00028f60;
  *DAT_00028f60 = *DAT_00028f60 | 2;
  iVar5 = force();
  *DAT_00028f64 = (char)iVar5;
  if (iVar5 == 0) {
    sys_flag();
  }
  else {
    dbg_printf(str_force_pair_en_x);
    FUN_00029ed8(0);
    rom_11550();
    *pbVar3 = *pbVar3 & 0xfd | 1;
    *DAT_00028f84 = 1;
    *puVar2 = *puVar2 | 1;
    dbg_printf_2(str_ble_address_set,DAT_00028f40,6);
  }
  FUN_0003948a(DAT_00028fa0,DAT_00028f9c,4);
  dbg_printf_2(str_flash7E100_SumAddr,DAT_00028fa0,4);
  return CONCAT26(uStack_1a,
                  CONCAT15(local_1b,CONCAT14(local_1c,CONCAT13(local_1d,CONCAT12(local_1e,CONCAT11(
                                                  local_1f,local_20))))));
}

/* ==========================================================================
 * FUN_00028c48   @ 0x00028c48   (6 bytes)
 * called by : FUN_0003b932, FUN_0003bb38, cal_data, rwip_driver_init
 */

undefined1 FUN_00028c48(void)

{
  return *DAT_00028fb8;
}

/* ==========================================================================
 * FUN_00028c4e   @ 0x00028c4e   (24 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_00032686, FUN_0003b932, FUN_0003bde6, FUN_0003e03e
 */

void FUN_00028c4e(void)

{
  FUN_0003b932(&DAT_0001c200);
  FUN_00032686(3);
  do {
    FUN_0003e03e();
    FUN_0003bde6();
  } while( true );
}

/* ==========================================================================
 * FUN_00028c66   @ 0x00028c66   (242 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : BLE_PAIR, Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, FUN_0002aa5c, FUN_0002f31c, ... (+16 more)
 */

void FUN_00028c66(void)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_00032886(1);
  pcVar3 = DAT_00028fc0;
  pcVar2 = DAT_00028fbc;
  pcVar1 = DAT_00028f28;
  do {
    if ((((*pcVar1 != '\x01') && (*pcVar1 != '\x02')) || (*pcVar3 != '\0')) || (*pcVar3 != '\0')) {
      return;
    }
    FUN_0003e03e();
    FUN_0003b54e();
    FUN_000405ae();
    BLE_PAIR();
    if ((*(uint *)(DAT_00028fc4 + 0x2c) & 1) != 1 || *DAT_00028fc8 != '\0') {
      FUN_0002f31c();
    }
    there();
    iVar4 = rom_25024();
    iVar5 = rom_25038();
    if (*DAT_00028fcc != '\0') {
      *DAT_00028fcc = '\0';
      FLASH_wr_Global();
    }
    if (*DAT_00028fd0 != '\0') {
      *DAT_00028fd0 = '\0';
      FLASH_WR_Profile(*DAT_00028fd4);
    }
    if (*pcVar2 != '\0') {
      *pcVar2 = '\0';
      flash_erase(*DAT_00028fd8);
    }
    if (*DAT_00028fdc != '\0') {
      *DAT_00028fdc = '\0';
      Default_Profile();
    }
    iVar6 = rom_071EA(3);
    if (iVar6 == 3) {
      FUN_0002aa5c();
    }
    if (*DAT_00028fe0 == '\0' && *DAT_00028fe4 == '\0') {
      iVar6 = FUN_0003e304();
      if (iVar6 == 1) {
LAB_00028d24:
        FUN_0003af8a();
      }
      else if (iVar6 == 2) {
        if (*DAT_00028fe8 == '\0') goto LAB_00028d24;
        FUN_0003ae82();
        FUN_0003af2c();
      }
    }
    if (iVar4 == 0) {
      rom_2504C();
    }
    if (iVar5 == 0) {
      rom_2505C();
    }
    Stack_Integrity_Check();
  } while( true );
}

/* ==========================================================================
 * enter_BLE_normal_app_mode   @ 0x00028d58   (572 bytes)
 * calls     : FUN_00028b00, FUN_00028c4e, FUN_00028c66, FUN_0002a5e4, FUN_0002a78c, FUN_0002aa44, ... (+36 more)
 * string    : "OLED_Init 0\r\n"
 * string    : "Mouse reset_reason************************ %x \r\n"
 * string    : "Key_CurrentStatus = %x\r\n"
 * string    : "system power on RF_MODE = %x\r\n"
 * string    : "enter_dut_fcc_mode \r\n"
 * string    : "f_usb_ena================= %x,%x,%x,%x,%x,\r\n"
 * string    : "RF_MODE 24G================= %x,%x,%x,%x,%x,\r\n"
 * string    : "system_mode0  RF_MODE %x, %x, %x\r\n"
 * string    : "enter_BLE_normal_app_mode RF_MODE================%x\r\n"
 */

void enter_BLE_normal_app_mode(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  short sVar5;
  char *pcVar6;
  byte *pbVar7;
  char *pcVar8;
  short *psVar9;
  uint *puVar10;
  undefined1 uVar11;
  int iVar12;
  char *pcVar13;
  byte bVar14;
  
  *DAT_00028fec = 0;
  FUN_0003ae40();
  FUN_000311de();
  FUN_0003b528();
  FUN_0002a5e4();
  FUN_00031334();
  FUN_0003bfc2();
  pbVar7 = DAT_00028fb8;
  *DAT_00028fb8 = 0;
  FUN_00039428();
  FUN_0003e516();
  KEY_piaring_cnt();
  iVar12 = get_usb_insert_status();
  *DAT_00028ff0 = iVar12 != 0;
  force_pair_en();
  FUN_0003262c();
  FUN_00032658();
  rom_24F8A((uint)*DAT_00028f40 + (uint)DAT_00028f40[5]);
  FUN_00028b00(DAT_00028efc);
  KEY_piaring_cnt();
  rwip_driver_init(0);
  uVar11 = FUN_0002aa44();
  *DAT_00028ff4 = uVar11;
  dbg_printf(str_OLED_Init_0);
  FUN_0003c8b6();
  iVar12 = FUN_0002a78c();
  pcVar8 = DAT_00029008;
  *DAT_00029008 = (char)iVar12;
  if (iVar12 == 5) {
    FUN_0003d8da(0x78);
    FUN_000317c2(2000);
  }
  FUN_00032620();
  rom_2504C();
  rom_2505C();
  dbg_printf(str_Mouse_reset_reason_x,*pcVar8);
  pcVar6 = DAT_00028f28;
  if (*pcVar8 == '\x05') {
    FUN_0002ac0e();
    psVar9 = DAT_00029040;
    dbg_printf(str_Key_CurrentStatus_x,*DAT_00029040);
    sVar5 = *psVar9;
    if (sVar5 == 6) {
      *DAT_00029060 = 1;
      *pcVar6 = '\0';
      *pbVar7 = 0;
    }
    else if ((sVar5 == 7) || (sVar5 == 10)) {
      *pcVar6 = '\0';
      FUN_00035cd2();
    }
  }
  dbg_printf(str_system_power_on_RF_MODE_x,*pcVar6);
  OLED_Init();
  if ((*pbVar7 & 1) != 0) {
    dbg_printf(str_enter_dut_fcc_mode);
    rom_2504C();
    rom_2505C();
    FUN_0003afa2(3);
    FUN_00028c4e();
  }
  profile_mem_init();
  FUN_0003262c();
  *DAT_0002909c = *pcVar6;
  sensor_init();
  FUN_0002b4c8();
  if (*DAT_00028ff0 != '\0') {
    Linking();
    FUN_0003b512(DAT_000290a0);
    USNDP_status_2();
    FUN_0003b528();
  }
  bVar14 = 0;
  do {
    *DAT_000290a4 = 0;
    set_Update_OLED();
    FUN_000317c2(10);
    bVar14 = bVar14 + 1;
  } while (bVar14 < 0x1e);
  OLED_Clear();
  FUN_0003cf7c();
  pcVar8 = DAT_00028fc0;
  do {
    do {
      while ((cVar1 = *pcVar6, cVar1 == '\0' || (*pcVar8 != '\0'))) {
        if (*pcVar8 == '\0') {
          FUN_0003afa2(1);
          uVar11 = *DAT_000291f4;
          uVar2 = *DAT_000291f8;
          cVar1 = *pcVar6;
          uVar3 = *(undefined1 *)(DAT_000291fc + 6);
          uVar4 = *DAT_00029200;
          pcVar13 = str_RF_MODE_24G_x_x_x_x_x;
        }
        else {
          FUN_0003afa2(5);
          uVar11 = *DAT_000290a8;
          uVar2 = *DAT_000290ac;
          uVar3 = *(undefined1 *)(DAT_000290b0 + 6);
          uVar4 = *DAT_000290b4;
          cVar1 = *pcVar6;
          pcVar13 = str_f_usb_ena_x_x_x_x_x;
        }
        dbg_printf(pcVar13,cVar1,uVar3,uVar4,uVar2,uVar11);
        puVar10 = DAT_00029234;
        DAT_0080000c = DAT_0080000c | 0x20000;
        *DAT_00029234 = *DAT_00029234 & ~((int)DAT_00029234 << 0xe);
        *puVar10 = *puVar10 & ~((int)puVar10 << 0x10);
        *puVar10 = *puVar10 & ~((int)puVar10 << 0xf);
        FUN_0003b512(DAT_00029238);
        FUN_0003beb4();
        *DAT_0002923c = 0;
        dbg_printf(str_system_mode0_RF_MODE_x_x_x,*pbVar7,*pcVar6,*DAT_00029240);
        fn24main();
      }
    } while ((((cVar1 != '\x01') && (cVar1 != '\x02')) || (*pcVar8 != '\0')) || (*pcVar8 != '\0'));
    FUN_0003afa2(1);
    dbg_printf(str_enter_BLE_normal_app_mode_RF_MODE_x,*pcVar6);
    FUN_0003b512(DAT_00029238);
    FUN_0003beb4();
    KEY_piaring_cnt();
    *DAT_0002923c = 0;
    FUN_00028c66();
  } while( true );
}

/* ==========================================================================
 * FUN_00029164   @ 0x00029164   (12 bytes)
 * called by : rwip_driver_init
 */

undefined4 FUN_00029164(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 0) {
    uVar1 = DAT_000292a0;
  }
  return uVar1;
}

/* ==========================================================================
 * FUN_00029392   @ 0x00029392   (46 bytes)
 * called by : FUN_00029530, limit
 * calls     : rom_24F9C
 * string    : "AQIRYS Zephyr 2"
 * string    : "AQIRYS Zephyr"
 */

void FUN_00029392(void)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_0002977c;
  if (*DAT_00029778 == '\x01') {
    rom_24F9C(DAT_0002977c + 10,str_AQIRYS_Zephyr,0xe);
    uVar2 = 0xe;
  }
  else {
    if (*DAT_00029778 != '\x02') {
      return;
    }
    rom_24F9C(DAT_0002977c + 10,str_AQIRYS_Zephyr_2,0x10);
    uVar2 = 0x10;
  }
  *(undefined1 *)(iVar1 + 9) = uVar2;
  return;
}

/* ==========================================================================
 * limit   @ 0x000293c0   (164 bytes)
 * called by : adv_data
 * calls     : FUN_00029392, dbg_printf, rom_24F9C
 * string    : "limit\r\n"
 * string    : "no limit\r\n"
 */

void limit(uint param_1,ushort *param_2,undefined1 *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_00029392();
  *param_3 = 2;
  param_3[1] = 1;
  if ((*DAT_000297a0 & 1) == 0) {
    dbg_printf(str_no_limit);
    uVar3 = 4;
  }
  else {
    dbg_printf(str_limit);
    uVar3 = 5;
  }
  param_3[2] = uVar3;
  *param_2 = *param_2 + 3;
  rom_24F9C(param_3 + 3,&DAT_000297b8,4);
  *param_2 = *param_2 + 4;
  rom_24F9C(param_3 + 7,&DAT_000297c0,4);
  uVar1 = *param_2;
  *param_2 = (ushort)(uVar1 + 4);
  iVar2 = DAT_0002977c;
  uVar4 = (param_1 & 0xff) - (uVar1 + 4) & 0xff;
  if (2 < uVar4) {
    uVar5 = (uint)*(byte *)(DAT_0002977c + 9);
    if (uVar4 - 2 <= uVar5) {
      uVar5 = uVar4 - 2;
    }
    uVar4 = uVar5 & 0xff;
    param_3[0xb] = (char)uVar5 + '\x01';
    if (*(byte *)(iVar2 + 9) == uVar4) {
      uVar3 = 9;
    }
    else {
      uVar3 = 8;
    }
    param_3[0xc] = uVar3;
    rom_24F9C(param_3 + 0xd,DAT_0002977c + 10,uVar4);
    *param_2 = *param_2 + (short)uVar4 + 2;
  }
  return;
}

/* ==========================================================================
 * FUN_00029490   @ 0x00029490   (38 bytes)
 * called by : app_ble_address_update, app_env, app_mutli_link_change, disconnect, force_ble_sleep
 * calls     : rom_06EF4, rom_06F26
 */

void FUN_00029490(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(DAT_000297c8 + 1,7,3,2);
  iVar1 = DAT_0002977c;
  *puVar2 = 0xa5;
  puVar2[1] = *(undefined1 *)(iVar1 + 3);
  rom_06F26();
  *(undefined1 *)(iVar1 + 4) = 7;
  *(undefined1 *)(iVar1 + 5) = 0xa5;
  return;
}

/* ==========================================================================
 * adv_data   @ 0x000294b6   (66 bytes)
 * called by : FUN_0002d53c
 * calls     : dbg_printf_2, limit, rom_06EF4, rom_06F26
 * string    : "adv_data--------"
 */

void adv_data(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(DAT_000297c8 + 5,7,3,0x23);
  iVar1 = DAT_0002977c;
  *puVar2 = 0xa9;
  puVar2[1] = *(undefined1 *)(iVar1 + 3);
  *(undefined2 *)(puVar2 + 2) = 0;
  limit(0x1f,puVar2 + 2,puVar2 + 4);
  dbg_printf_2(str_adv_data,puVar2 + 4,0x1f);
  rom_06F26(puVar2);
  *(undefined1 *)(iVar1 + 4) = 2;
  *(undefined1 *)(iVar1 + 5) = 0xa9;
  return;
}

/* ==========================================================================
 * FUN_00029530   @ 0x00029530   (78 bytes)
 * called by : rwip_driver_init
 * calls     : FUN_00029392, FUN_0002bef8, FUN_0002c044, FUN_0002c378, FUN_0002ca10, app_ancsc_init, ... (+6 more)
 */

void FUN_00029530(void)

{
  undefined1 *puVar1;
  
  rom_24FEC(DAT_0002977c,0x46);
  rom_07108(3,DAT_000297f0);
  rom_07180(3,0);
  FUN_00029392();
  app_sec_init();
  FUN_0002c044();
  FUN_0002c378();
  FUN_0002bef8();
  app_ancsc_init();
  FUN_0002ca10();
  puVar1 = (undefined1 *)rom_06EF4(DAT_000297c8 + -0x9f,7,3,1);
  *puVar1 = 1;
  rom_06F26();
  return;
}

/* ==========================================================================
 * appm_add_svc   @ 0x0002957e   (44 bytes)
 * called by : FUN_0002d53c
 * calls     : dbg_printf
 * string    : "appm_add_svc"
 * string    : "%s more_svc:%d\r\n"
 */

bool appm_add_svc(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = DAT_0002977c;
  bVar2 = *(byte *)(DAT_0002977c + 7) != 6;
  if (bVar2) {
    (**(code **)(DAT_000297f4 + (uint)*(byte *)(DAT_0002977c + 7) * 4))();
    *(char *)(iVar1 + 7) = *(char *)(iVar1 + 7) + '\x01';
  }
  dbg_printf(str_s_more_svc_d,DAT_000297f4 + 0x18,bVar2);
  return bVar2;
}

/* ==========================================================================
 * FUN_000295aa   @ 0x000295aa   (36 bytes)
 * called by : Disconnected, FUN_0002b8a2, FUN_0002d53c, app_env, app_mutli_link_change, disconnect, ... (+2 more)
 * calls     : rom_06EF4, rom_06F26
 */

void FUN_000295aa(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           rom_06EF4(DAT_000297c8 + 99,(uint)*(byte *)(DAT_0002977c + 2) * 0x100 + 8,3,2);
  *puVar1 = 1;
  puVar1[1] = 0x13;
  rom_06F26();
  return;
}

/* ==========================================================================
 * appm_create_advertising   @ 0x000295ce   (198 bytes)
 * called by : FUN_0002d53c, adv_state
 * calls     : FUN_0003e552, dbg_printf, dbg_printf_2, rom_06EF4, rom_06F26, rom_24F9C
 * string    : "disc_mode  =%x,\r\n"
 * string    : "appm_create_advertising direct\r\n"
 * string    : "peeraddr2:"
 * string    : "appm_create_advertising nonderect \r\n"
 */

void appm_create_advertising(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 *local_1c;
  
  iVar1 = DAT_0002977c;
  if (*(char *)(DAT_0002977c + 4) == '\0') {
    puVar2 = (undefined1 *)rom_06EF4(0xda0,7,3,0x2c);
    *puVar2 = 0xa0;
    puVar2[1] = 0;
    puVar2[4] = 0;
    *(undefined2 *)(puVar2 + 6) = 3;
    puVar2[9] = 0;
    puVar2[0x1c] = 7;
    puVar2[0x1d] = 1;
    if ((*DAT_000297a0 & 1) == 0) {
      puVar2[5] = 0;
    }
    else {
      puVar2[5] = 1;
    }
    *(undefined4 *)(puVar2 + 0x14) = 0x20;
    *(undefined4 *)(puVar2 + 0x18) = 0x20;
    dbg_printf(str_disc_mode_x,puVar2[5]);
    if ((int)(*DAT_000297a0 << 0x1d) < 0) {
      local_20[0] = 7;
      dbg_printf(str_appm_create_advertising_direct);
      if (*DAT_00029778 == '\x02') {
        uVar3 = 0x3c;
      }
      else {
        uVar3 = 0x3b;
      }
      FUN_0003e552(uVar3,local_20,auStack_28);
      local_1c = puVar2 + 10;
      rom_24F9C(local_1c,auStack_28,7);
      *(undefined4 *)(puVar2 + 0x14) = 0x20;
      *(undefined4 *)(puVar2 + 0x18) = 0x20;
      dbg_printf_2(str_peeraddr2,local_1c,6);
      dbg_printf_2(str_peeraddr2,auStack_28,6);
      *(undefined1 *)(iVar1 + 6) = 1;
      *(undefined2 *)(puVar2 + 6) = 5;
    }
    else {
      dbg_printf(str_appm_create_advertising_nonderect);
      *(undefined1 *)(iVar1 + 6) = 0;
    }
    rom_06F26(puVar2);
    *(undefined1 *)(iVar1 + 4) = 1;
    *(undefined1 *)(iVar1 + 5) = 0xa0;
  }
  return;
}

/* ==========================================================================
 * appm_delete_advertising   @ 0x00029694   (36 bytes)
 * called by : FUN_0002d53c, app_ble_address_update, app_env
 * calls     : dbg_printf, rom_06EF4, rom_06F26
 * string    : "appm_delete_advertising \r\n"
 */

void appm_delete_advertising(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(DAT_000297c8 + 2,7,3,2);
  *puVar1 = 0xa8;
  rom_06F26();
  dbg_printf(str_appm_delete_advertising);
  *(undefined1 *)(DAT_0002977c + 5) = 0xa8;
  return;
}

/* ==========================================================================
 * adv_state   @ 0x000296b8   (42 bytes)
 * calls     : FUN_000317c2, appm_create_advertising, dbg_printf, rom_25078
 * string    : "adv_state:%x\r\n"
 */

void adv_state(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint extraout_r1;
  
  dbg_printf(str_adv_state_x,*(undefined1 *)(DAT_0002977c + 4));
  FUN_000317c2(2);
  rom_25078();
  appm_create_advertising(extraout_r1 >> 0xc,param_3 >> 0xc);
  return;
}

/* ==========================================================================
 * appm_update_param   @ 0x00029704   (96 bytes)
 * called by : ImgHdr, update
 * calls     : dbg_printf, rom_06EF4, rom_06F26
 * string    : "appm_update_param"
 * string    : "%s \r\n"
 * string    : "intv_min:%d ,%d\r\n"
 * string    : "con_latency:%d \r\n"
 * string    : "time_out:%d \r\n"
 */

void appm_update_param(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           rom_06EF4(DAT_000297c8 + 0x6d,(uint)*(byte *)(DAT_0002977c + 2) * 0x100 + 8,3,0xe);
  dbg_printf(str_s,DAT_000297f4 + 0x25);
  *puVar2 = 9;
  *(undefined2 *)(puVar2 + 2) = *param_1;
  *(undefined2 *)(puVar2 + 4) = param_1[1];
  *(undefined2 *)(puVar2 + 6) = param_1[2];
  *(undefined2 *)(puVar2 + 8) = param_1[3];
  dbg_printf(str_intv_min_d_d,*param_1,param_1[1]);
  dbg_printf(str_con_latency_d,param_1[2]);
  dbg_printf(str_time_out_d,param_1[3]);
  uVar1 = (undefined2)DAT_000298e4;
  *(undefined2 *)(puVar2 + 10) = uVar1;
  *(undefined2 *)(puVar2 + 0xc) = uVar1;
  rom_06F26(puVar2);
  return;
}

/* ==========================================================================
 * app_ble_addr_tabl_init   @ 0x000298e8   (160 bytes)
 * called by : force_pair_en
 * calls     : FUN_0003e552, FUN_0003e5f0, dbg_printf, dbg_printf_2, rom_24F9C
 * string    : "app_ble_addr_tabl_init"
 * string    : "%s \r\n"
 * string    : "wr ble--1 addr :"
 * string    : "wr ble--2 addr :"
 * string    : "NVDS_TAG_BLE_ADDRESS0:"
 * string    : "NVDS_TAG_BLE_ADDRESS1:"
 */

void app_ble_addr_tabl_init
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  
  _local_10 = CONCAT31((int3)((uint)param_4 >> 8),7);
  local_18 = param_2;
  local_14 = param_3;
  dbg_printf(DAT_00029cdc,DAT_00029cd8);
  FUN_0003e552(0xa5,&local_10,&local_18);
  if ((char)local_18 != 'U') {
    local_18 = CONCAT31(local_18._1_3_,0x55);
    rom_24F9C((int)&local_18 + 1,DAT_00029ce0,6);
    FUN_0003e5f0(0xa5,7,&local_18);
    dbg_printf_2(str_wr_ble_1_addr,&local_18,7);
    local_14 = CONCAT31(local_14._1_3_,(char)local_14 + '\x01');
    FUN_0003e5f0(0xa6,7,&local_18);
    dbg_printf_2(str_wr_ble_2_addr,&local_18,7);
    return;
  }
  if (*DAT_00029d0c == '\x02') {
    FUN_0003e552(0xa6,&local_10,&local_18);
    pcVar1 = str_NVDS_TAG_BLE_ADDRESS1;
  }
  else {
    FUN_0003e552(0xa5,&local_10,&local_18);
    pcVar1 = str_NVDS_TAG_BLE_ADDRESS0;
  }
  dbg_printf_2(pcVar1,&local_18,7);
  rom_24F9C(DAT_00029ce0,(int)&local_18 + 1,6);
  return;
}

/* ==========================================================================
 * save   @ 0x000299cc   (56 bytes)
 * calls     : FUN_0003e5f0, dbg_printf_2, rom_24F9C
 * string    : "save co_default_bdaddr :"
 */

void save(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_18;
  undefined3 uStack_17;
  undefined4 uStack_14;
  
  _local_18 = CONCAT31((int3)((uint)param_3 >> 8),0x55);
  uStack_14 = param_4;
  rom_24F9C(&uStack_17,DAT_00029ce0,6);
  if (param_1 == 1) {
    uVar1 = 0xa5;
  }
  else {
    uVar1 = 0xa6;
  }
  FUN_0003e5f0(uVar1,7,&local_18);
  dbg_printf_2(str_save_co_default_bdaddr,DAT_00029ce0,6);
  return;
}

/* ==========================================================================
 * FUN_00029a42   @ 0x00029a42   (26 bytes)
 * called by : app_ble_address_update, app_env
 * calls     : rom_24F9C
 */

void FUN_00029a42(undefined4 param_1)

{
  rom_24F9C(DAT_00029dcc,param_1,6);
  rom_24F9C(DAT_00029dd0,param_1,6);
  return;
}

/* ==========================================================================
 * app_env   @ 0x00029a5c   (84 bytes)
 * called by : app_ble_to_ble_mode
 * calls     : FUN_00029490, FUN_000295aa, FUN_00029a42, appm_delete_advertising, dbg_printf, rom_071EA
 * string    : "appm disconn..................\r\n"
 * string    : "app_env.adv_state = %x \r\n"
 */

void app_env(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  FUN_00029a42(DAT_00029ce0);
  iVar3 = rom_071EA(3);
  puVar2 = DAT_00029dd4;
  iVar1 = DAT_00029d74;
  if ((iVar3 == 3) && (-1 < (int)(*DAT_00029dd4 << 0x17))) {
    dbg_printf(str_appm_disconn);
    FUN_000295aa();
  }
  else {
    dbg_printf(str_app_env_adv_state_x,*(undefined1 *)(DAT_00029d74 + -0x2a));
    if (*(char *)(iVar1 + -0x2a) == '\x06') {
      FUN_00029490();
      *DAT_00029e18 = 1;
    }
    else {
      appm_delete_advertising();
    }
  }
  *puVar2 = *puVar2 & 0xfffffeff;
  return;
}

/* ==========================================================================
 * app_ble_address_update   @ 0x00029acc   (84 bytes)
 * called by : FUN_0002b8a2
 * calls     : FUN_00029490, FUN_00029988, FUN_00029a42, FUN_00029ab0, appm_delete_advertising, dbg_printf, ... (+2 more)
 * string    : "app_ble_address_update"
 * string    : "app_sec_env.key_index = %x \r\n"
 * string    : "update ble addr:"
 */

void app_ble_address_update(void)

{
  undefined1 *puVar1;
  
  dbg_printf(&DAT_00029e1c,DAT_00029cd8 + 0x17);
  puVar1 = DAT_00029e24;
  FUN_00029ab0(*DAT_00029e24);
  dbg_printf(str_app_sec_env_key_index_x,*(undefined1 *)(DAT_00029d70 + 6));
  FUN_00029988(*puVar1);
  rom_11550();
  FUN_00029a42(DAT_00029ce0);
  dbg_printf_2(str_update_ble_addr,DAT_00029ce0,6);
  if (*(char *)(DAT_00029d74 + -0x2a) == '\x06') {
    FUN_00029490();
    *DAT_00029e18 = 1;
  }
  else {
    appm_delete_advertising();
  }
  return;
}

/* ==========================================================================
 * sys_flag   @ 0x00029b20   (264 bytes)
 * called by : app_ble_to_ble_mode, force_pair_en
 * calls     : FUN_0003e552, dbg_printf
 * string    : "%s \r\n"
 * string    : "appm_get_peer_type"
 * string    : "sys_flag = %x\r\n"
 * string    : "peer addr type0 = %x\r\n"
 * string    : "bond0  =  %x\r\n"
 * string    : "peer addr type1 is PUBLIC_ADDR=%x\r\n"
 * string    : "bond1  =  %x\r\n"
 */

void sys_flag(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  char cVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  dbg_printf(DAT_00029cdc,DAT_00029cd8 + 0xb8);
  puVar3 = DAT_00029dd4;
  *DAT_00029dd4 = *DAT_00029dd4 & 0xfffffffa;
  pcVar5 = DAT_00029d70;
  local_20 = CONCAT31(local_20._1_3_,1);
  if (*DAT_00029d0c == '\x01') {
    iVar4 = FUN_0003e552(0x35,&local_20,&local_1c);
    if (iVar4 == 0) {
      if ((local_1c & 0xff) < 2) {
        if ((local_1c & 0xff) == 0) goto LAB_00029b7a;
        bVar2 = true;
      }
      else {
        local_1c = local_1c & 0xffffff00;
LAB_00029b7a:
        bVar2 = false;
      }
      *pcVar5 = bVar2;
      if (!bVar2) {
        *puVar3 = *puVar3 | 1;
        dbg_printf(str_sys_flag_x,*puVar3);
      }
    }
    local_20 = CONCAT31(local_20._1_3_,1);
    if (((*pcVar5 != '\0') && (iVar4 = FUN_0003e552(0xa2,&local_20,&local_18), iVar4 == 0)) &&
       ((local_18 & 0xff) == 0)) {
      *puVar3 = *puVar3 | 4;
      dbg_printf(str_peer_addr_type0_x);
    }
    cVar1 = *pcVar5;
    pcVar5 = str_bond0_x;
    goto LAB_00029c22;
  }
  iVar4 = FUN_0003e552(0x36,&local_20,&local_1c);
  if (iVar4 == 0) {
    if ((local_1c & 0xff) < 2) {
      if ((local_1c & 0xff) == 0) goto LAB_00029bda;
      bVar2 = true;
    }
    else {
      local_1c = local_1c & 0xffffff00;
LAB_00029bda:
      bVar2 = false;
    }
    pcVar5[1] = bVar2;
    if (!bVar2) {
      *puVar3 = *puVar3 | 1;
      dbg_printf(str_sys_flag_x,*puVar3);
    }
  }
  local_20 = CONCAT31(local_20._1_3_,1);
  if (((pcVar5[1] != '\0') && (iVar4 = FUN_0003e552(0xa3,&local_20,&local_18), iVar4 == 0)) &&
     ((local_18 & 0xff) == 0)) {
    *puVar3 = *puVar3 | 4;
    dbg_printf(str_peer_addr_type1_is_PUBLIC_ADDR_x);
  }
  cVar1 = pcVar5[1];
  pcVar5 = str_bond1_x;
LAB_00029c22:
  dbg_printf(pcVar5,cVar1);
  return;
}

/* ==========================================================================
 * app_ble_to_ble_mode   @ 0x00029c28   (68 bytes)
 * called by : switch_rf_mode_loop
 * calls     : FUN_00029988, FUN_00029a04, FUN_00029ab0, KEY_piaring_cnt, app_env, dbg_printf, ... (+1 more)
 * string    : "app_ble_to_ble_mode"
 */

bool app_ble_to_ble_mode(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  int iVar3;
  
  dbg_printf(&DAT_00029e1c,DAT_00029cd8 + 0x2e);
  iVar3 = DAT_00029ecc;
  pbVar2 = DAT_00029ec8;
  *DAT_00029ec8 = 0;
  *(undefined1 *)(iVar3 + 9) = 2;
  KEY_piaring_cnt();
  puVar1 = DAT_00029d0c;
  FUN_00029ab0(*DAT_00029d0c);
  FUN_00029988(*puVar1);
  FUN_00029a04();
  sys_flag();
  app_env();
  return 5 < *pbVar2;
}

/* ==========================================================================
 * force   @ 0x0002a078   (50 bytes)
 * called by : force_pair_en
 * calls     : FUN_0003e552, dbg_printf
 * string    : "force pair mode : %d \r\n"
 */

uint force(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  local_10 = param_3 & 0xffffff00;
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),1);
  FUN_0003e552(0x39,&local_c,&local_10);
  if (1 < (byte)local_10) {
    local_10 = local_10 & 0xffffff00;
  }
  dbg_printf(str_force_pair_mode_d,local_10 & 0xff);
  return local_10 & 0xff;
}

/* ==========================================================================
 * FUN_0002a0aa   @ 0x0002a0aa   (22 bytes)
 * calls     : FUN_0003e5f0
 */

void FUN_0002a0aa(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_c;
  
  if (param_1 == 1) {
    uVar1 = 0xa8;
  }
  else {
    uVar1 = 0xa9;
  }
  uStack_c = param_2;
  FUN_0003e5f0(uVar1,2,&uStack_c,param_4,param_1);
  return;
}

/* ==========================================================================
 * FUN_0002a0c0   @ 0x0002a0c0   (44 bytes)
 * calls     : FUN_0003e552
 */

uint FUN_0002a0c0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  local_10 = param_3 & 0xffffff00;
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),2);
  if (param_1 == 1) {
    uVar1 = 0xa8;
  }
  else if (param_1 == 2) {
    uVar1 = 0xa9;
  }
  else {
    uVar1 = 0xaa;
  }
  FUN_0003e552(uVar1,&local_c,&local_10);
  return local_10 & 0xff;
}

/* ==========================================================================
 * BLE_PAIR   @ 0x0002a152   (484 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_0002cbda, FUN_0003b538, FUN_0003c8b6, FUN_0003cf7c, OLED_Clear, app_start_led, ... (+3 more)
 * string    : "app adv timer run.... %d\r\n"
 * string    : "BLE_PAIR OLED_Init 1\r\n"
 * string    : "start reconnect advertising = %d \r\n"
 * string    : "start nondir advertising = %d \r\n"
 * string    : "BLE_PAIR BLE_RECONNECTED OLED_Init 2\r\n"
 */

void BLE_PAIR(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint *puVar5;
  undefined1 *puVar6;
  ushort uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  pbVar1 = DAT_0002a300;
  if ((*DAT_0002a300 & 1) != 0) {
    FUN_0003b538(DAT_0002a43c);
  }
  iVar8 = DAT_0002a444;
  iVar2 = DAT_0002a430;
  if (*DAT_0002a440 == '\0') {
    if ((*pbVar1 & 1) != 0) {
      if (*(char *)(DAT_0002a448 + 4) == '\x06') {
        *pbVar1 = *pbVar1 & 0xfe;
        dbg_printf(str_app_adv_timer_run_d,DAT_0002a44c);
        *(undefined1 *)(iVar2 + -0xb) = 1;
        *DAT_0002a46c = 0;
        puVar4 = DAT_0002a470;
        *(undefined1 *)(iVar2 + -0xf) = 0;
        *puVar4 = 0;
        *DAT_0002a388 = 0;
        app_start_led();
        puVar5 = DAT_0002a474;
        *DAT_0002a474 = *DAT_0002a474 & 0xfffffdff;
        *puVar5 = *puVar5 | 1;
        rom_073D4(DAT_0002a438 + 7,3);
        rom_073D4(DAT_0002a438 + 4,3);
        rom_073D4(DAT_0002a438 + 5,3);
        rom_073D4(DAT_0002a438 + 8,3);
        uVar7 = (ushort)(*(byte *)(iVar8 + 0xb) >> 4) << 4 | (ushort)(*(byte *)(iVar8 + 0xc) >> 4);
        if (uVar7 == 0) {
          uVar7 = 1;
        }
        *DAT_0002a478 = uVar7 * 0xef + (ushort)*(byte *)(iVar8 + 0x10) * 0x7e;
        rom_07342(DAT_0002a438 + 6,3,0x19);
        rom_07342(DAT_0002a438 + 2,3,DAT_0002a44c);
      }
      FUN_0003c8b6();
      OLED_Clear();
      dbg_printf(str_BLE_PAIR_OLED_Init_1);
      FUN_0003cf7c();
    }
    if (((*DAT_0002a494 == '\0') && ((int)((uint)*pbVar1 << 0x1e) < 0)) &&
       (*(char *)(DAT_0002a448 + 4) == '\x06')) {
      *pbVar1 = *pbVar1 & 0xfd;
      *DAT_0002a474 = *DAT_0002a474 & 0xfffffdff;
      iVar3 = DAT_0002a438;
      iVar10 = DAT_0002a438 + 4;
      rom_073D4(iVar10,3);
      rom_073D4(iVar3 + 2,3);
      rom_073D4(iVar3 + 7,3);
      rom_073D4(iVar3 + 5,3);
      rom_073D4(iVar3 + 8,3);
      uVar7 = (ushort)(*(byte *)(iVar8 + 0xb) >> 4) << 4 | (ushort)(*(byte *)(iVar8 + 0xc) >> 4);
      if (uVar7 == 0) {
        uVar7 = 1;
      }
      *DAT_0002a478 = uVar7 * 0xef + (ushort)*(byte *)(iVar8 + 0x10) * 0x7e;
      rom_07342(DAT_0002a438 + 6,3,0x19);
      iVar8 = FUN_0002cbda();
      puVar6 = DAT_0002a7d0;
      puVar4 = DAT_0002a46c;
      if (iVar8 == 0) {
        *(undefined1 *)(iVar2 + -0xf) = 0;
        *puVar6 = 0;
        *DAT_0002a7d4 = 0;
        *(undefined1 *)(iVar2 + -0xb) = 1;
        *DAT_0002a7d8 = 0;
        uVar9 = DAT_0002a7dc;
        rom_07342(DAT_0002a7e0,3,DAT_0002a7dc);
        dbg_printf(str_start_nondir_advertising_d,uVar9);
        app_start_led();
      }
      else {
        *(undefined1 *)(iVar2 + -0xb) = 2;
        *puVar4 = 1;
        *DAT_0002a470 = 0;
        *DAT_0002a388 = 0;
        app_start_led();
        uVar9 = DAT_0002a7cc;
        if (*(char *)(DAT_0002a430 + 3) != '\x14') {
          uVar9 = 1000;
        }
        rom_07342(iVar10,3,uVar9);
        dbg_printf(str_start_reconnect_advertising_d,uVar9);
      }
      FUN_0003c8b6();
      OLED_Clear();
      dbg_printf(str_BLE_PAIR_BLE_RECONNECTED_OLED_Init_2);
      FUN_0003cf7c();
    }
  }
  return;
}

/* ==========================================================================
 * app_bond_status_initial   @ 0x0002a4e2   (152 bytes)
 * called by : force_pair_en
 * calls     : FUN_0003e552, FUN_0003e5f0, dbg_printf
 * string    : "app_bond_status_initial"
 * string    : "%s \r\n"
 * string    : "write error  NVDS_TAG_PERIPH_BONDED0= %x\r\n"
 * string    : "app_bond_status_initial  bonded0=%x, bonded1========%x\r\n"
 */

void app_bond_status_initial(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  uint local_18;
  undefined4 local_14;
  
  local_18 = param_3 & 0xffffff00;
  local_14 = param_4;
  dbg_printf(DAT_0002a834,DAT_0002a830);
  local_14 = CONCAT31(local_14._1_3_,1);
  iVar2 = FUN_0003e552(0x35,&local_14,&local_18);
  if ((iVar2 != 0) || (1 < (byte)local_18)) {
    local_18 = local_18 & 0xffffff00;
    iVar2 = FUN_0003e5f0(0x35,1,&local_18);
    if (iVar2 != 0) {
      dbg_printf(str_write_error_NVDS_TAG_PERIPH_BONDED0_x,local_18 & 0xff);
    }
  }
  puVar1 = DAT_0002a864;
  *DAT_0002a864 = (byte)local_18 != '\0';
  local_14 = CONCAT31(local_14._1_3_,1);
  iVar2 = FUN_0003e552(0x36,&local_14,&local_18);
  if ((iVar2 != 0) || (1 < (byte)local_18)) {
    local_18 = local_18 & 0xffffff00;
    FUN_0003e5f0(0x36,1,&local_18);
  }
  puVar1[1] = (byte)local_18 != '\0';
  dbg_printf(str_app_bond_status_initial_bonded0_x_bonded1_x,*puVar1);
  return;
}

/* ==========================================================================
 * APP_PARAM_UPDATE_REQ_IND   @ 0x0002a57a   (106 bytes)
 * called by : ble_update_param_failed_cnt, hogpd_ntf_cfg_ind_handler
 * calls     : app_start_led, dbg_printf, rom_07342
 * string    : "app_ble_pair_successed"
 * string    : "%s ble_pairing_successed_cfm=[%d]\r\n"
 * string    : "APP_PARAM_UPDATE_REQ_IND-2 start update param....\r\n"
 * string    : "pair successed ,start led on....\r\n"
 */

void APP_PARAM_UPDATE_REQ_IND(void)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = DAT_0002a8a4;
  dbg_printf(str_s_ble_pairing_successed_cfm_d,DAT_0002a830 + 0x39,*(undefined1 *)(DAT_0002a8a4 + 7)
            );
  puVar2 = DAT_0002a8cc;
  if (*(char *)(iVar1 + 7) != '\0') {
    *(undefined1 *)(iVar1 + 7) = 0;
    *(undefined1 *)(iVar1 + 3) = 0;
    *puVar2 = *puVar2 | 0x200;
    *(undefined1 *)(iVar1 + 2) = 0;
    if (6 < *(byte *)(iVar1 + 8)) {
      rom_07342(DAT_0002a7e0 + -7,3,2);
      dbg_printf(str_APP_PARAM_UPDATE_REQ_IND_2_start_update_para);
    }
    *(undefined1 *)(iVar1 + 6) = 1;
    rom_07342(DAT_0002a7e0 + 6,3,300);
    dbg_printf(str_pair_successed_start_led_on);
    if (*(char *)(DAT_0002a8a4 + 0x10) == '\0') {
      app_start_led();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0002a5e4   @ 0x0002a5e4   (20 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void FUN_0002a5e4(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = DAT_0002a8a4;
  puVar2 = DAT_0002a8a4 + 0x10;
  DAT_0002a8a4[0x12] = 0;
  *puVar2 = 0;
  puVar1[0x13] = 0x14;
  *puVar1 = 0;
  return;
}

/* ==========================================================================
 * FUN_0002a5f8   @ 0x0002a5f8   (28 bytes)
 * called by : there
 */

short FUN_0002a5f8(int param_1)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = 0;
  uVar2 = 0;
  do {
    sVar1 = *(short *)(param_1 + uVar2 * 2) + sVar1;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 5);
  return sVar1;
}

/* ==========================================================================
 * there   @ 0x0002a614   (96 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_0002a5f8, FUN_0003b130, dbg_printf
 * string    : "ble lost pkt sum:%d \r\n"
 * string    : "there is a serious lost pkt occur,need execute cpu reset!!!!!!!!\r\n"
 */

void there(void)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  puVar5 = DAT_0002a92c;
  iVar4 = DAT_0002a8a4;
  sVar3 = *DAT_0002a928;
  if (sVar3 != 0) {
    if (sVar3 != *(short *)(DAT_0002a8a4 + 0xe)) {
      bVar1 = *(byte *)(DAT_0002a8a4 + 0xd);
      if (bVar1 < 5) {
        *(short *)(DAT_0002a92c + (uint)bVar1 * 2 + 4) = sVar3;
        *(byte *)(iVar4 + 0xd) = bVar1 + 1;
      }
      *(short *)(iVar4 + 0xe) = sVar3;
    }
    if (4 < *(byte *)(iVar4 + 0xd)) {
      uVar6 = FUN_0002a5f8(puVar5 + 4);
      if (0x16 < uVar6) {
        dbg_printf(str_ble_lost_pkt_sum_d,uVar6);
        *puVar5 = 1;
        cVar2 = puVar5[1];
        puVar5[1] = cVar2 + 1U;
        if (4 < (byte)(cVar2 + 1U)) {
          dbg_printf(DAT_0002a948);
          FUN_0003b130();
        }
      }
      *(undefined1 *)(iVar4 + 0xd) = 0;
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0002a674   @ 0x0002a674   (42 bytes)
 * called by : FUN_0002f31c
 * calls     : dbg_printf
 * string    : "ble lost pkt accumulate free\r\n"
 */

void FUN_0002a674(void)

{
  short sVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = DAT_0002a94c;
  pcVar2 = DAT_0002a92c;
  if (*DAT_0002a92c != '\0') {
    sVar1 = *(short *)(DAT_0002a92c + 2);
    *(ushort *)(DAT_0002a92c + 2) = sVar1 + 1U;
    if (uVar3 < (ushort)(sVar1 + 1U)) {
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      *pcVar2 = '\0';
      pcVar2[1] = '\0';
      dbg_printf(str_ble_lost_pkt_accumulate_free);
    }
  }
  return;
}

/* ==========================================================================
 * ble_alert_led_start   @ 0x0002a70e   (98 bytes)
 * calls     : dbg_printf, rom_07342
 * string    : "%s \r\n"
 * string    : "ble_alert_led_start"
 */

void ble_alert_led_start(void)

{
  int iVar1;
  ushort uVar2;
  
  iVar1 = DAT_0002a8a4;
  if ((*DAT_0002a9a4 != '\0') && (*DAT_0002a9a8 == '\0')) {
    uVar2 = (ushort)(*(byte *)(DAT_0002a9ac + 0xb) >> 4) << 4 |
            (ushort)(*(byte *)(DAT_0002a9ac + 0xc) >> 4);
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    if ((((ushort)(uVar2 * 0xef) < *DAT_0002a9b0) && (*DAT_0002a9b4 != '\0')) &&
       (*(char *)(DAT_0002a8a4 + 10) == '\0')) {
      *(undefined1 *)(DAT_0002a8a4 + 10) = 1;
      *(undefined1 *)(iVar1 + 0xb) = 0;
      *(undefined1 *)(iVar1 + 0xc) = 0;
      dbg_printf(DAT_0002a834,DAT_0002a830 + 0x50);
      rom_07342(DAT_0002a7e0 + -1,3,10);
    }
  }
  return;
}

/* ==========================================================================
 * ble_alert_led_stop   @ 0x0002a770   (28 bytes)
 * called by : Disconnected, FUN_000328c2, app_mutli_link_change, disconnect, f_usb_isConnected
 * calls     : dbg_printf, rom_073D4
 * string    : "ble_alert_led_stop\r\n"
 */

void ble_alert_led_stop(void)

{
  int iVar1;
  
  iVar1 = DAT_0002a8a4;
  *(undefined1 *)(DAT_0002a8a4 + 0xc) = 0;
  *(undefined1 *)(iVar1 + 10) = 0;
  rom_073D4(DAT_0002a7e0 + -1,3);
  dbg_printf(str_ble_alert_led_stop);
  return;
}

/* ==========================================================================
 * FUN_0002a78c   @ 0x0002a78c   (26 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : reset
 */

void FUN_0002a78c(void)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = reset();
  if (iVar1 == 5) {
    uVar2 = 0;
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    uVar2 = 3;
  }
  *(undefined1 *)(DAT_0002a8a4 + 9) = uVar2;
  return;
}

/* ==========================================================================
 * FUN_0002aa5c   @ 0x0002aa5c   (276 bytes)
 * called by : FUN_00028c66, system_mode
 * calls     : FUN_0002aa44, FUN_000319c0, FUN_00031b3e, OLED_Init
 */

void FUN_0002aa5c(void)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  byte bVar8;
  
  pcVar3 = DAT_0002adc4;
  iVar2 = DAT_0002adc0;
  pcVar1 = DAT_0002adbc;
  if (*DAT_0002adb8 == '\0') {
    return;
  }
  if (*DAT_0002adbc == '\f') {
    *DAT_0002adbc = '\v';
    if ((*(char *)(iVar2 + 4) != '\0') && (*pcVar3 == '\x10')) {
      FUN_000319c0();
    }
    if ((*(char *)(iVar2 + 7) != '\0') && (*pcVar3 == '\x11')) {
      FUN_000319c0();
    }
    *pcVar3 = '\0';
  }
  iVar7 = FUN_0002aa44();
  if (iVar7 == 0x40) {
    if (*DAT_0002add4 == -0x40) {
      bVar5 = 0x81;
    }
    else {
      if (*DAT_0002add4 != '\0') goto LAB_0002ab6a;
      bVar5 = 0x82;
    }
  }
  else {
    if (iVar7 != 0x80) {
      bVar5 = *DAT_0002adc8;
      if (-1 < (int)((uint)bVar5 << 0x18)) goto LAB_0002ab6a;
      bVar8 = bVar5 & 0x7f;
      *DAT_0002adc8 = bVar8;
      puVar4 = DAT_0002add0;
      if ((bVar5 & 0x7f) == 0) {
        if (iVar7 != 0xc0) goto LAB_0002ab6a;
LAB_0002ab06:
        if (*(char *)(iVar2 + 4) == '\0') {
          *DAT_0002adcc = *DAT_0002adcc + '\x01';
          *puVar4 = 1;
        }
        else {
          FUN_00031b3e(0x10);
        }
        *DAT_0002add8 = 400;
        *DAT_0002addc = 0xf;
        *pcVar1 = '\x0f';
        cVar6 = '\x10';
      }
      else {
        if (bVar8 == 1) {
          if (iVar7 != 0) goto LAB_0002ab6a;
          goto LAB_0002ab06;
        }
        if (bVar8 == 2) {
          if (iVar7 != 0xc0) goto LAB_0002ab6a;
        }
        else if ((bVar8 != 3) || (iVar7 != 0)) goto LAB_0002ab6a;
        if (*(char *)(iVar2 + 7) == '\0') {
          *DAT_0002adcc = *DAT_0002adcc + -1;
          *puVar4 = 1;
        }
        else {
          FUN_00031b3e(0x11);
        }
        *DAT_0002add8 = 400;
        *DAT_0002addc = 0xf;
        *pcVar1 = '\x0f';
        cVar6 = '\x11';
      }
      *pcVar3 = cVar6;
      OLED_Init();
      goto LAB_0002ab6a;
    }
    if (*DAT_0002add4 == -0x40) {
      bVar5 = 0x83;
    }
    else {
      if (*DAT_0002add4 != '\0') goto LAB_0002ab6a;
      bVar5 = 0x80;
    }
  }
  *DAT_0002adc8 = bVar5;
LAB_0002ab6a:
  *DAT_0002add4 = (char)iVar7;
  return;
}

/* ==========================================================================
 * FUN_0002ab70   @ 0x0002ab70   (56 bytes)
 * called by : FUN_0002ac0e
 */

undefined4 FUN_0002ab70(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  
  uVar4 = 0;
  bVar3 = 0;
  while( true ) {
    pbVar1 = (byte *)(DAT_0002ade0 + uVar4);
    bVar5 = 0;
    for (bVar2 = bVar3 & *pbVar1; bVar2 != 0; bVar2 = bVar2 & bVar2 - 1) {
      bVar5 = bVar5 + 1;
    }
    if (1 < bVar5) break;
    uVar4 = uVar4 + 1 & 0xff;
    bVar3 = bVar3 | *pbVar1;
    if (2 < uVar4) {
      return 0;
    }
  }
  return 1;
}

/* ==========================================================================
 * FUN_0002abba   @ 0x0002abba   (14 bytes)
 * called by : FUN_0002ac0e
 */

void FUN_0002abba(void)

{
  int iVar1;
  
  iVar1 = DAT_0002adb4;
  *(undefined4 *)(DAT_0002adb4 + 0x20) = 0x3c;
  *(undefined4 *)(iVar1 + 0x24) = 0x3c;
  *(undefined4 *)(iVar1 + 0x30) = 0xc;
  return;
}

/* ==========================================================================
 * FUN_0002abd4   @ 0x0002abd4   (58 bytes)
 * called by : FUN_0002ac0e, FUN_0002b128, get_scan_Rvalue
 * calls     : FUN_00031784
 */

byte FUN_0002abd4(void)

{
  byte bVar1;
  
  FUN_00031784(1);
  bVar1 = (*(uint *)(DAT_0002adb4 + -0x3c) & 1) == 0;
  if ((*(uint *)(DAT_0002adb4 + -0x38) & 1) == 0) {
    bVar1 = bVar1 | 2;
  }
  if ((*(uint *)(DAT_0002adb4 + -0x34) & 1) == 0) {
    bVar1 = bVar1 | 4;
  }
  if ((*(uint *)(DAT_0002adb4 + 0x3c) & 1) == 0) {
    bVar1 = bVar1 | 8;
  }
  return bVar1;
}

/* ==========================================================================
 * FUN_0002ac0e   @ 0x0002ac0e   (210 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, enter_BLE_normal_app_mode, system_mode
 * calls     : FUN_0002ab70, FUN_0002abba, FUN_0002abd4, OLED_Init
 */

void FUN_0002ac0e(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  char *pcVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  
  FUN_0002abba();
  iVar9 = DAT_0002ade4;
  pbVar4 = DAT_0002ade0;
  uVar10 = 0;
  do {
    **(undefined4 **)(iVar9 + uVar10 * 4) = 0;
    bVar8 = FUN_0002abd4();
    pbVar4[uVar10] = bVar8;
    **(undefined4 **)(iVar9 + uVar10 * 4) = 0xc;
    pcVar7 = DAT_0002adf4;
    pcVar6 = DAT_0002adf0;
    pbVar5 = DAT_0002adec;
    iVar2 = DAT_0002adc0;
    uVar10 = uVar10 + 1 & 0xff;
  } while (uVar10 < 3);
  uVar11 = (ushort)pbVar4[1] << 4 | (ushort)pbVar4[2] << 8 | (ushort)*pbVar4;
  if (uVar11 == *DAT_0002ade8) {
    if (*DAT_0002adf4 == '\0') {
      bVar8 = *DAT_0002adec;
      *DAT_0002adec = bVar8 - 1;
      if ((byte)(bVar8 - 1) == 0) {
        *pcVar7 = '\x01';
        puVar3 = DAT_0002addc;
        cVar1 = *pcVar6;
        if ((((cVar1 == '\x01') || (cVar1 == '\x02')) && (*DAT_0002adf8 == '\0')) ||
           (bVar8 = *(byte *)(iVar2 + -0x2f), bVar8 < 3)) {
          bVar8 = 2;
        }
        *pbVar5 = bVar8;
        *puVar3 = 0xf;
        OLED_Init();
        puVar3 = DAT_0002ae00;
        *DAT_0002adfc = uVar11;
        *puVar3 = 1;
      }
      goto LAB_0002acd6;
    }
  }
  else {
    OLED_Init();
    iVar9 = FUN_0002ab70();
    pcVar7 = DAT_0002adf4;
    if (iVar9 != 0) goto LAB_0002acd6;
    *DAT_0002ade8 = uVar11;
    *pcVar7 = '\0';
  }
  cVar1 = *pcVar6;
  if ((((cVar1 == '\x01') || (cVar1 == '\x02')) && (*DAT_0002adf8 == '\0')) ||
     (bVar8 = *(byte *)(iVar2 + -0x2f), bVar8 < 3)) {
    bVar8 = 2;
  }
  *pbVar5 = bVar8;
LAB_0002acd6:
  *DAT_0002ae08 = *DAT_0002ae04;
  return;
}

/* ==========================================================================
 * force_ble_sleep   @ 0x0002b292   (162 bytes)
 * called by : force_ble_sleep_2, set_Update_OLED
 * calls     : FUN_00029490, FUN_000295aa, FUN_00033cfc, FUN_00033dc2, FUN_00039a84, FUN_0003b528, ... (+6 more)
 * string    : "force_ble_sleep"
 * string    : "%s \r\n"
 * string    : "app_env.adv_state...= %d\r\n"
 * string    : "disconnect start \r\n"
 * string    : "appm  need stop adv...\r\n"
 */

void force_ble_sleep(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_0002b554;
  if (*DAT_0002b588 == '\0') {
    *DAT_0002b588 = '\x01';
    dbg_printf(str_s_3,iVar1 + 0x30);
    set_force_sleep();
    if ((*(uint *)(DAT_0002b524 + 0x2c) & 1) == 0) {
      FUN_00033dc2();
    }
    if ((*(char *)(DAT_0002b58c + 8) == '\0') || (*DAT_0002b590 != '\0')) {
      sensor_pwdn();
      FUN_00033cfc();
    }
    rom_073D4(DAT_0002b564 + 8,3);
    rom_07342(DAT_0002b564,3,0x14);
    *DAT_0002b594 = 0;
    FUN_00039a84(0x32,0,0);
    iVar3 = rom_071EA(3);
    iVar2 = DAT_0002b59c;
    iVar1 = DAT_0002b598;
    if (iVar3 == 3) {
      dbg_printf(str_disconnect_start);
      FUN_000295aa();
      *(undefined1 *)(iVar1 + 9) = 1;
    }
    else {
      dbg_printf(str_app_env_adv_state_d,*(undefined1 *)(DAT_0002b59c + 4));
      if (*(char *)(iVar2 + 4) == '\x06') {
        dbg_printf(str_appm_need_stop_adv);
        FUN_00029490();
        *(undefined1 *)(iVar1 + 8) = 0;
      }
    }
    FUN_0003b528();
  }
  return;
}

/* ==========================================================================
 * FUN_0002b3ac   @ 0x0002b3ac   (22 bytes)
 * called by : FUN_0002bdc4, app_mutli_link_change, gpio, tx_failed_cnt
 * calls     : rom_24FEC
 */

void FUN_0002b3ac(void)

{
  int iVar1;
  
  iVar1 = DAT_0002b598;
  *(undefined1 *)(DAT_0002b598 + 3) = 0;
  *(undefined1 *)(iVar1 + 2) = 0;
  *(undefined1 *)(iVar1 + 1) = 0;
  rom_24FEC(DAT_0002b668,0x40);
  return;
}

/* ==========================================================================
 * FUN_0002b4c8   @ 0x0002b4c8   (22 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_0002b382, FUN_000311de, FUN_00039bc2, KEY_piaring_cnt
 */

void FUN_0002b4c8(void)

{
  FUN_00039bc2(DAT_0002b6c4);
  FUN_000311de();
  FUN_0002b382();
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * FUN_0002b4de   @ 0x0002b4de   (16 bytes)
 * called by : app_mutli_link_change
 * calls     : FUN_00031406, rom_24FEC
 */

void FUN_0002b4de(void)

{
  rom_24FEC(DAT_0002b668,0x40);
  FUN_00031406();
  return;
}

/* ==========================================================================
 * app_mutli_link_change   @ 0x0002b4ee   (516 bytes)
 * called by : system_mode
 * calls     : FUN_00029490, FUN_000295aa, FUN_0002b3ac, FUN_0002b4de, FUN_000312aa, FUN_00032892, ... (+9 more)
 * string    : "long_press..[Rmode %d -> Smode %d] \r\n"
 * string    : "app_mutli_link_change"
 * string    : "%s,RF_MODE:%x\r\n"
 * string    : "key free LongPress\r\n"
 * string    : "force_pair_en 5========%x\r\n"
 * string    : "short_press..[Rmode %d -> Smode %d] \r\n"
 * string    : "Disconnected by mouse...\r\n"
 * string    : "appm  need stop adv...\r\n"
 * string    : "short press time=%d\r\n"
 * string    : "time_Simu_mode = %d,%d \r\n"
 * string    : "*****sw_num = %d \r\n"
 */

void app_mutli_link_change(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 in_r3;
  
  pcVar5 = DAT_0002bb18;
  pcVar4 = DAT_0002b6c8;
  pcVar3 = DAT_0002b598;
  pcVar1 = DAT_0002b598 + 6;
  cVar2 = *DAT_0002b54c;
  uVar8 = (uint)(byte)DAT_0002b598[5];
  if ((*DAT_0002b51c != '\0') && (*DAT_0002b520 == '\0')) {
    if (uVar8 < 0xff) {
      uVar8 = uVar8 + 1;
      DAT_0002b598[5] = (char)uVar8;
    }
    pcVar5 = DAT_0002babc;
    if ((0xfa < (uVar8 & 0xff)) && (*pcVar1 == '\0')) {
      pcVar3[6] = '\x01';
      dbg_printf(str_long_press_Rmode_d_Smode_d,cVar2,*pcVar5,0,in_r3);
      if (*DAT_0002bae8 == '\0') {
        FUN_00032f16();
        FUN_00032e82();
        *DAT_0002bae8 = '\x01';
        dbg_printf(str_s_RF_MODE_x,DAT_0002baf0,*DAT_0002baec);
      }
      ble_alert_led_stop();
      puVar6 = DAT_0002bb10;
      cVar2 = *DAT_0002baec;
      if ((cVar2 == *DAT_0002babc) && (cVar2 == '\0')) {
        pcVar3[7] = '\0';
        *puVar6 = 0;
        *DAT_0002bb14 = 1;
      }
      else {
        pcVar3[7] = '\x01';
        if (cVar2 != '\0') {
          FUN_0002b3ac();
          FUN_0002b4de();
        }
      }
      pcVar1 = DAT_0002bb04;
      *pcVar4 = '\0';
      *pcVar1 = '\0';
      if (*DAT_0002bb08 != '\0') {
        *DAT_0002bb0c = '\x05';
      }
    }
    return;
  }
  if (((cVar2 == '\x01') || (cVar2 == '\x02')) && (*DAT_0002bb18 == '\0')) {
    if (*pcVar1 == '\0') {
      if ((uVar8 - 5 < 0xc3) && (DAT_0002b598[0xc] == '\0')) {
        DAT_0002b598[0xc] = '\x01';
        if (*DAT_0002bb38 != '\0') {
          *DAT_0002bb38 = '\0';
          dbg_printf(str_force_pair_en_5_x,0,uVar8 - 5,0,in_r3);
          pcVar3[5] = '\0';
        }
        *DAT_0002bb08 = '\x01';
        dbg_printf(str_s_RF_MODE_x,DAT_0002baf0,*DAT_0002baec);
        if (*DAT_0002bae8 == '\0') {
          FUN_00032f16();
          FUN_00032e82();
          *DAT_0002bae8 = '\x01';
          FUN_0003bf0a();
        }
        if (((*DAT_0002baec == '\x01') || (*DAT_0002baec == '\x02')) && (*pcVar5 == '\0')) {
          app_user_ke_timer_stop();
        }
        FUN_00032892();
        ble_alert_led_stop();
        FUN_000312aa();
        *DAT_0002bb58 = 0;
        Set_SIMU_mode_LightUp_Led();
        dbg_printf(str_short_press_Rmode_d_Smode_d,*DAT_0002baec,*DAT_0002babc);
        if ((*pcVar4 == '\0') &&
           (((*DAT_0002baec == '\x01' || (*DAT_0002baec == '\x02')) && (*pcVar5 == '\0')))) {
          iVar7 = rom_071EA(3);
          if (iVar7 == 3) {
            dbg_printf(str_Disconnected_by_mouse);
            *(uint *)(pcVar3 + 0x14) = *(uint *)(pcVar3 + 0x14) | 0x100;
            FUN_000295aa();
          }
          else if (*(char *)(DAT_0002bb84 + 4) == '\x06') {
            dbg_printf(DAT_0002bba4);
            FUN_00029490();
            pcVar3[8] = '\0';
          }
        }
        *pcVar4 = 'P';
      }
      if (pcVar3[5] != '\0') {
        dbg_printf(str_short_press_time_d);
      }
      if (*DAT_0002bb04 != '\0') {
        *DAT_0002bb04 = *DAT_0002bb04 + -1;
      }
      pcVar1 = DAT_0002bb0c;
      cVar2 = *pcVar4;
      if (cVar2 != '\0') {
        *pcVar4 = cVar2 + -1;
        *pcVar1 = cVar2 + -1;
        dbg_printf(str_time_Simu_mode_d_d,cVar2 + -1,cVar2 + -1);
        if (*pcVar4 == '\0') {
          *DAT_0002bb08 = '\0';
          *pcVar3 = *pcVar3 + '\x01';
          dbg_printf(str_sw_num_d);
          iVar7 = switch_rf_mode_loop();
          if (iVar7 != 0) {
            return;
          }
        }
      }
    }
    else {
      dbg_printf(str_key_free_LongPress);
    }
  }
  puVar6 = DAT_0002bb34;
  pcVar3[6] = '\0';
  pcVar3[5] = '\0';
  *puVar6 = 0;
  pcVar3[0xc] = '\0';
  return;
}

/* ==========================================================================
 * FUN_0002b8a2   @ 0x0002b8a2   (148 bytes)
 * called by : FUN_0003186e, system_mode
 * calls     : FUN_000295aa, FUN_0003cf7c, FUN_0003e5f0, app_24_to_ble_force_pair_reset, app_ble_address_update, dbg_printf, ... (+1 more)
 * string    : "Entry pair mode---RFMODE :[ %x  to  %x ]\r\n"
 */

void FUN_0002b8a2(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 in_r3;
  
  iVar5 = DAT_0002bbf0;
  pcVar4 = DAT_0002baec;
  pcVar3 = DAT_0002babc;
  if (*(char *)(DAT_0002bbf0 + 7) != '\0') {
    *(undefined1 *)(DAT_0002bbf0 + 7) = 0;
    dbg_printf(str_Entry_pair_mode_RFMODE_x_to_x,*pcVar4,*pcVar3,in_r3,in_r3);
    cVar1 = *pcVar3;
    if (cVar1 == '\0') {
      *pcVar4 = '\0';
      *DAT_0002bb10 = 0;
      *DAT_0002bb14 = 1;
    }
    else {
      cVar2 = *pcVar4;
      *pcVar4 = cVar1;
      if (cVar2 == '\0') {
        app_24_to_ble_force_pair_reset();
      }
      else {
        *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) & 0xfffffffb;
        *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 1;
        iVar6 = rom_071EA(3);
        if (iVar6 == 3) {
          *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x40;
          FUN_000295aa();
        }
        else {
          app_ble_address_update();
        }
        *(byte *)(iVar5 + 4) = *(byte *)(iVar5 + 4) & 0xfd | 1;
      }
    }
    FUN_0003cf7c();
    if (((*pcVar4 == '\x01') || (*pcVar4 == '\x02')) && (*DAT_0002bb18 == '\0')) {
      FUN_0003e5f0(0x38,1,DAT_0002baec);
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0002bdc4   @ 0x0002bdc4   (18 bytes)
 * calls     : FUN_0002b3ac
 */

void FUN_0002bdc4(void)

{
  FUN_0002b3ac();
  *DAT_0002be78 = 0;
  *PTR_DAT_0002be7c = 0;
  return;
}

/* ==========================================================================
 * FUN_0002bef8   @ 0x0002bef8   (12 bytes)
 * called by : FUN_00029530
 */

void FUN_0002bef8(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0002bfbc;
  *DAT_0002bfbc = 0;
  puVar1[1] = 100;
  return;
}

/* ==========================================================================
 * FUN_0002bf30   @ 0x0002bf30   (44 bytes)
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26
 */

void FUN_0002bf30(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  *DAT_0002bfbc = param_1;
  uVar1 = FUN_0003ee6e(0x24);
  puVar2 = (undefined1 *)rom_06EF4(&DAT_00002400,uVar1,3,4);
  *puVar2 = param_1;
  puVar2[1] = 0;
  puVar2[2] = 0x32;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002bf5c   @ 0x0002bf5c   (44 bytes)
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26
 */

void FUN_0002bf5c(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  *DAT_0002bfbc = param_1;
  uVar1 = FUN_0003ee6e(0x24);
  puVar2 = (undefined1 *)rom_06EF4(&DAT_00002400,uVar1,3,4);
  *puVar2 = param_1;
  puVar2[1] = 1;
  puVar2[2] = 0x32;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002bf88   @ 0x0002bf88   (34 bytes)
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26
 */

void FUN_0002bf88(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_0003ee6e(0x24);
  puVar2 = (undefined1 *)rom_06EF4(PTR_DAT_0002bfc4,uVar1,3,2);
  *puVar2 = 0;
  puVar2[1] = param_1;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002c044   @ 0x0002c044   (2 bytes)
 * called by : FUN_00029530
 */

void FUN_0002c044(void)

{
  return;
}

/* ==========================================================================
 * FUN_0002c158   @ 0x0002c158   (54 bytes)
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0002c158(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0003ee6e(0x47);
  iVar2 = rom_06EF4(DAT_0002c2d0 + 3,uVar1,param_1 * 0x100 + 3,0x278);
  *(short *)(iVar2 + 2) = (short)param_2;
  rom_24F9C(iVar2 + 4,param_3,param_2);
  rom_06F26(iVar2);
  return;
}

/* ==========================================================================
 * FUN_0002c378   @ 0x0002c378   (44 bytes)
 * called by : FUN_00029530
 * calls     : FUN_0003e552, rom_24FEC
 */

void FUN_0002c378(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_r3;
  undefined1 local_10;
  undefined3 uStack_f;
  
  _local_10 = CONCAT31((int3)((uint)in_r3 >> 8),2);
  rom_24FEC(PTR_DAT_0002c77c,8);
  puVar1 = PTR_DAT_0002c77c;
  PTR_DAT_0002c77c[6] = 10;
  iVar2 = FUN_0003e552(0x3a,&local_10,puVar1 + 2);
  if (iVar2 != 0) {
    *(undefined2 *)(puVar1 + 2) = 2000;
  }
  return;
}

/* ==========================================================================
 * hogpd_ctnl_pt_ind_handler   @ 0x0002c5e8   (80 bytes)
 * calls     : FUN_0003ee6e, dbg_printf, rom_06EF4, rom_06F26
 * string    : "hogpd_ctnl_pt_ind_handler"
 * string    : "%s,(%d) \r\n"
 */

undefined4 hogpd_ctnl_pt_ind_handler(undefined4 param_1,char *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  dbg_printf(str_s_d,DAT_0002c784 + 0x24,0x2e4);
  puVar1 = PTR_DAT_0002c77c;
  if (*param_2 == *PTR_DAT_0002c77c) {
    uVar2 = FUN_0003ee6e(0x26);
    pcVar3 = (char *)rom_06EF4(DAT_0002c7d4 + 3,uVar2,3,0x1e);
    *pcVar3 = *param_2;
    pcVar3[1] = '\x02';
    pcVar3[2] = '\0';
    pcVar3[4] = *puVar1;
    pcVar3[5] = -2;
    pcVar3[6] = '\0';
    pcVar3[7] = '\0';
    pcVar3[8] = '\0';
    rom_06F26();
  }
  return 0;
}

/* ==========================================================================
 * hogpd_ntf_cfg_ind_handler   @ 0x0002c638   (92 bytes)
 * calls     : APP_PARAM_UPDATE_REQ_IND, dbg_printf
 * string    : "hogpd_ntf_cfg_ind_handler"
 * string    : "%s,(%d) \r\n"
 */

undefined4 hogpd_ntf_cfg_ind_handler(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  
  dbg_printf(str_s_d,DAT_0002c784 + 0x3e,DAT_0002c848);
  *DAT_0002c84c = 1;
  dbg_printf(&DAT_0002c850);
  if ((uint)(byte)*PTR_DAT_0002c77c == (uint)*param_2) {
    if ((int)((uint)param_2[(uint)*param_2 * 2 + 2] << 0x19) < 0) {
      PTR_DAT_0002c77c[4] = 3;
      bVar1 = *PTR_DAT_0002c864;
      if (bVar1 < 10) {
        bVar1 = bVar1 + 1;
        *PTR_DAT_0002c864 = bVar1;
      }
      if (bVar1 == 6) {
        APP_PARAM_UPDATE_REQ_IND();
      }
    }
    else if (PTR_DAT_0002c77c[4] == '\x03') {
      PTR_DAT_0002c77c[4] = 2;
    }
  }
  return 0;
}

/* ==========================================================================
 * FUN_0002ca10   @ 0x0002ca10   (8 bytes)
 * called by : FUN_00029530
 */

void FUN_0002ca10(void)

{
  *DAT_0002cb4c = 0;
  return;
}

/* ==========================================================================
 * FUN_0002ca56   @ 0x0002ca56   (42 bytes)
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26
 */

void FUN_0002ca56(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  *DAT_0002cb4c = param_1;
  uVar1 = FUN_0003ee6e(0x49);
  puVar2 = (undefined1 *)rom_06EF4(&DAT_00004900,uVar1,3,6);
  *puVar2 = param_1;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined2 *)(puVar2 + 4) = 0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002cad2   @ 0x0002cad2   (42 bytes)
 * calls     : FUN_0003ee6e, dbg_printf, rom_06EF4, rom_06F26
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002cad2(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  dbg_printf(&DAT_0002cb90,param_2 + 0x52);
  uVar1 = FUN_0003ee6e(0x49);
  iVar2 = rom_06EF4(_DAT_0002cbc4,uVar1,3,0x1b);
  *(undefined1 *)(iVar2 + 1) = 0x14;
  *(undefined1 *)(iVar2 + 2) = 100;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002cafe   @ 0x0002cafe   (44 bytes)
 * calls     : FUN_0003ee6e, dbg_printf, rom_06EF4, rom_06F26
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002cafe(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  dbg_printf(&DAT_0002cb90,param_2 + 99);
  uVar1 = FUN_0003ee6e(0x49);
  iVar2 = rom_06EF4(_DAT_0002cbc4 + 4,uVar1,3,0x1b);
  *(undefined1 *)(iVar2 + 1) = 0x14;
  *(undefined1 *)(iVar2 + 2) = 0x32;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002cbda   @ 0x0002cbda   (18 bytes)
 * called by : BLE_PAIR, FUN_0002d53c, app_sec_init, switch_rf_mode_loop
 */

undefined1 FUN_0002cbda(void)

{
  if (*DAT_0002cfc4 != '\x01') {
    return DAT_0002cfc8[1];
  }
  return *DAT_0002cfc8;
}

/* ==========================================================================
 * app_sec_init   @ 0x0002cbec   (148 bytes)
 * called by : FUN_00029530
 * calls     : FUN_0002cbc8, FUN_0002cbda, FUN_0003e552, dbg_printf
 * string    : "app_sec_init().   bonded0=%x, bonded1========%x\r\n"
 * string    : "not NVDS_TAG_IRK = %x\r\n"
 * string    : "get NVDS_TAG_IRK ok= %x\r\n"
 */

void app_sec_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 local_18;
  undefined3 uStack_17;
  undefined1 local_14;
  undefined3 uStack_13;
  undefined4 local_10;
  
  puVar1 = DAT_0002cfc8;
  _local_18 = CONCAT31((int3)((uint)param_2 >> 8),1);
  _local_14 = CONCAT31((int3)((uint)param_3 >> 8),0x17);
  uVar2 = 0x35;
  if (*DAT_0002cfc4 == '\x02') {
    uVar2 = 0x36;
  }
  puVar5 = DAT_0002cfc8;
  if (*DAT_0002cfc4 != '\x01') {
    puVar5 = DAT_0002cfc8 + 1;
  }
  local_10 = param_4;
  iVar3 = FUN_0003e552(uVar2,&local_18,puVar5);
  if (iVar3 != 0) {
    FUN_0002cbc8(0);
  }
  iVar3 = FUN_0002cbda();
  if ((iVar3 == 0) && (iVar3 = FUN_0002cbda(), iVar3 != 0)) {
    FUN_0002cbc8(0);
  }
  dbg_printf(str_app_sec_init_bonded0_x_bonded1_x,*puVar1,puVar1[1]);
  local_10 = CONCAT31(local_10._1_3_,1);
  iVar3 = FUN_0003e552(0x80,&local_10,puVar1 + 6);
  if (iVar3 != 0) {
    puVar1[6] = 0;
  }
  iVar3 = FUN_0003e552(puVar1[6] + 'C',&local_14,DAT_0002d000);
  if (iVar3 == 0) {
    pcVar4 = str_get_NVDS_TAG_IRK_ok_x;
  }
  else {
    pcVar4 = str_not_NVDS_TAG_IRK_x;
  }
  dbg_printf(pcVar4,puVar1[6]);
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  return;
}

/* ==========================================================================
 * app_sec_send_security_req   @ 0x0002cc82   (66 bytes)
 * calls     : dbg_printf, rom_06EF4, rom_06F26, rom_073D4
 * string    : "app_sec_send_security_req"
 */

void app_sec_send_security_req(int param_1)

{
  undefined1 *puVar1;
  
  dbg_printf(&DAT_0002d03c,DAT_0002d038);
  if ((*(char *)(DAT_0002cfc8 + 3) == '\0') && (*(char *)(DAT_0002cfc8 + 2) == '\0')) {
    puVar1 = (undefined1 *)rom_06EF4(DAT_0002d044 + -0xe9,param_1 * 0x100 + 8,3,2);
    *puVar1 = 0xc;
    puVar1[1] = 1;
    rom_06F26();
    return;
  }
  rom_073D4(DAT_0002d044,3);
  return;
}

/* ==========================================================================
 * gapm_activity_created_ind_handler   @ 0x0002d4e4   (26 bytes)
 * calls     : dbg_printf
 * string    : "gapm_activity_created_ind_handler"
 * string    : "%s app_env.adv_actv_idx = %x   \r\n"
 */

undefined4 gapm_activity_created_ind_handler(undefined4 param_1,undefined1 *param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_str_gapm_activity_created_ind_handler_0002d8ac;
  if (PTR_DAT_0002d8a8[4] == '\x01') {
    PTR_DAT_0002d8a8[3] = *param_2;
    dbg_printf(str_s_app_env_adv_actv_idx_x,puVar1);
  }
  return 0;
}

/* ==========================================================================
 * gapm_activity_stopped_ind_handler   @ 0x0002d4fe   (30 bytes)
 * calls     : dbg_printf
 * string    : "gapm_activity_stopped_ind_handler"
 * string    : "%s app_env.adv_state = %x   \r\n"
 */

undefined4 gapm_activity_stopped_ind_handler(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0002d8a8;
  dbg_printf(str_s_app_env_adv_state_x,PTR_str_gapm_activity_created_ind_handler_0002d8ac + 0x22,
             PTR_DAT_0002d8a8[4]);
  if (puVar1[4] == '\x06') {
    puVar1[4] = 4;
  }
  return 0;
}

/* ==========================================================================
 * FUN_0002d53c   @ 0x0002d53c   (530 bytes)
 * calls     : FUN_000295aa, FUN_0002cbda, FUN_0003e552, FUN_0003e5f0, KEY_piaring_cnt, adv_data, ... (+11 more)
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_0002d53c(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  bool bVar8;
  byte *pbStack_20;
  undefined1 uStack_1c;
  undefined3 uStack_1b;
  undefined4 uStack_18;
  
  _uStack_1c = CONCAT31((int3)((uint)param_3 >> 8),0x10);
  uStack_18 = param_4;
  dbg_printf(str_s_operation_x_status_x,PTR_str_gapm_activity_created_ind_handler_0002d8ac + 99,
             *param_2,param_2[1]);
  puVar2 = PTR_DAT_0002d8a8;
  bVar1 = *param_2;
  if (bVar1 == 0xa0) {
    dbg_printf(str_GAPM_CREATE_ADV_ACTIVITY);
    KEY_piaring_cnt();
    adv_data();
    pbStack_20 = param_2;
    goto LAB_0002d7ca;
  }
  if (0xa0 < bVar1) {
    rom_25078();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pbStack_20 = PTR_DAT_0002d8a8 + 0x1c;
  if (bVar1 == 0x1a) {
    if (PTR_DAT_0002d8a8[0x2d] == '\x01') {
      PTR_DAT_0002d8a8[0x2d] = 2;
      puVar7 = (undefined1 *)rom_06EF4(PTR_DAT_0002d940 + 0x15,7,3,1);
      *puVar7 = 0x1a;
    }
    else {
      puVar7 = (undefined1 *)rom_06EF4(PTR_DAT_0002d940 + 0x1f,7,3,0x11);
      puVar2[0x2d] = 0;
      *puVar7 = 0x28;
      rom_24F9C(puVar7 + 1,pbStack_20,0x10);
    }
    goto LAB_0002d706;
  }
  if (bVar1 < 0x1b) {
    if (bVar1 == 1) {
      bVar8 = param_2[1] == 0;
      if (!bVar8) goto LAB_0002d57a;
      puVar7 = (undefined1 *)rom_06EF4(PTR_DAT_0002d940,7,3,0x34);
      *puVar7 = 3;
      puVar7[1] = 10;
      puVar7[0x1b] = 1;
      *(undefined2 *)(puVar7 + 0x22) = 0xfb;
      uVar3 = _DAT_0002d94c;
      *(short *)(puVar7 + 0x24) = (short)PTR_DAT_0002d944;
      *(short *)(puVar7 + 0x26) = (short)_DAT_0002d948;
      *(undefined2 *)(puVar7 + 0x20) = 0x40;
      puVar7[0x1a] = 0;
      rom_24F9C(puVar7 + 4,uVar3,6);
      if ((byte)puVar7[9] >> 6 == 3) {
        puVar7[0x1a] = puVar7[0x1a] | 1;
      }
      iVar5 = FUN_0002cbda();
      if ((iVar5 != 0) && (iVar5 = FUN_0003e552(0xa0,&uStack_1c,pbStack_20), iVar5 == 0)) {
        puVar6 = puVar7 + 10;
        goto LAB_0002d6ea;
      }
      rom_24FEC(puVar7 + 10,0x10);
    }
    else {
      if (bVar1 != 3) {
        bVar8 = bVar1 == 0x17;
        goto LAB_0002d57a;
      }
      iVar5 = FUN_0002cbda();
      if (iVar5 == 0) {
        puVar7 = (undefined1 *)rom_06EF4(PTR_DAT_0002d940 + 0x15,7,3,1);
        *puVar7 = 0x1a;
        puVar2[0x2d] = 1;
      }
      else {
        iVar5 = FUN_0003e552(0xa0,&uStack_1c,pbStack_20);
        if (iVar5 != 0) goto LAB_0002d7ca;
        puVar7 = (undefined1 *)rom_06EF4(PTR_DAT_0002d940 + 0x1f,7,3,0x11);
        *puVar7 = 0x28;
        puVar6 = puVar7 + 1;
LAB_0002d6ea:
        rom_24F9C(puVar6,pbStack_20,0x10);
      }
    }
  }
  else {
    if (bVar1 == 0x1b) {
      iVar5 = appm_add_svc();
      bVar8 = false;
      if (iVar5 == 0) {
        rom_07180(3,2);
        dbg_printf(0x2d950,puVar2[4]);
        if (puVar2[4] == '\0') {
          appm_create_advertising();
        }
        else {
          appm_delete_advertising();
        }
        KEY_piaring_cnt();
        rom_07342(PTR_DAT_0002d958,3,1);
        goto LAB_0002d7ca;
      }
    }
    else {
      bVar8 = false;
      if (bVar1 == 0x28) {
        iVar5 = FUN_0003e552(0xa0,&uStack_1c,pbStack_20);
        if (iVar5 != 0) {
          FUN_0003e5f0(0xa0,0x10,pbStack_20);
        }
        puVar2[0x2d] = 0;
        rom_07180(3,1);
        appm_add_svc();
        goto LAB_0002d7ca;
      }
    }
LAB_0002d57a:
    if (!bVar8) goto LAB_0002d7ca;
    dbg_printf(str_GAPM_RESOLV_ADDR_CMP_STATUS_x,param_2[1]);
    if (param_2[1] != 0) {
      dbg_printf(str_appm_disconnect_1_1);
      FUN_000295aa();
      goto LAB_0002d7ca;
    }
    puVar7 = (undefined1 *)
             rom_06EF4(PTR_DAT_0002d940 + 0xfe,(uint)(byte)puVar2[2] * 0x100 + 8,3,0x34);
    uVar4 = FUN_0002cbda();
    puVar7[0x28] = uVar4;
  }
LAB_0002d706:
  rom_06F26(puVar7);
LAB_0002d7ca:
  return ZEXT48(pbStack_20) << 0x20;
}

/* ==========================================================================
 * ble_update_param_failed_cnt   @ 0x0002dd92   (94 bytes)
 * calls     : APP_PARAM_UPDATE_REQ_IND, app_hid_enable_prf, dbg_printf, rom_07342
 * string    : "APP_PARAM_UPDATE_REQ_IND-3  ble_update_param_failed_cnt++ =%x\r\n"
 * string    : "ble_app_hogpd_report_ready not ready...\r\n"
 * string    : "ble_update_param_failed_cnt >=3  %x\r\n"
 * string    : "GAPC_UPDATE_PARAMS fail !  %d\r\n"
 */

undefined4 ble_update_param_failed_cnt(undefined4 param_1)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  byte *unaff_r4;
  byte unaff_r5;
  char *unaff_r6;
  char *unaff_r7;
  
  if (*unaff_r6 == '\0') {
    if (*unaff_r4 < 3) {
      *unaff_r4 = *unaff_r4 + 1;
      rom_07342(param_1,3,0x1e);
      bVar1 = *unaff_r4;
      pcVar3 = str_APP_PARAM_UPDATE_REQ_IND_3_ble_update_param;
    }
    else {
      if (*unaff_r7 == '\0') {
        if (*DAT_0002dfa0 == '\0') {
          dbg_printf(str_ble_app_hogpd_report_ready_not_ready);
        }
        *unaff_r7 = '\x01';
        pbVar2 = DAT_0002dfc4;
        *unaff_r4 = unaff_r5;
        *pbVar2 = unaff_r5;
        app_hid_enable_prf(PTR_DAT_0002de7c[2]);
        APP_PARAM_UPDATE_REQ_IND();
      }
      bVar1 = *unaff_r4;
      pcVar3 = str_ble_update_param_failed_cnt_3_x;
    }
    dbg_printf(pcVar3,bVar1);
  }
  dbg_printf(str_GAPC_UPDATE_PARAMS_fail_d,*unaff_r4);
  return 0;
}

/* ==========================================================================
 * loc_irk   @ 0x0002e398   (78 bytes)
 * calls     : dbg_printf, dbg_printf_2, rom_24F9C
 * string    : "gapm_gen_rand_nb_ind_handler"
 * string    : "%s app_env.rand_cnt = %x   \r\n"
 * string    : "loc_irk[0]:"
 * string    : "loc_irk[8]:"
 */

undefined4 loc_irk(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  char *pcVar2;
  
  puVar1 = PTR_DAT_0002e6f8;
  dbg_printf(str_s_app_env_rand_cnt_x,PTR_str_gapm_gen_rand_nb_ind_handler_0002e6fc,
             PTR_DAT_0002e6f8[0xd]);
  if (puVar1[0xd] == '\x01') {
    puVar1 = PTR_DAT_0002e6f8 + -4;
    rom_24F9C(puVar1,param_2,8);
    pcVar2 = str_loc_irk_0;
  }
  else {
    if (puVar1[0xd] != '\x02') {
      return 0;
    }
    puVar1 = PTR_DAT_0002e6f8 + 4;
    rom_24F9C(puVar1,param_2,8);
    pcVar2 = str_loc_irk_8;
  }
  dbg_printf_2(pcVar2,puVar1,8);
  return 0;
}

/* ==========================================================================
 * force_ble_sleep_2   @ 0x0002ebf8   (150 bytes)
 * calls     : FUN_0003186e, FUN_00032620, FUN_00032e82, FUN_00032f16, FUN_00035800, FUN_00039a84, ... (+6 more)
 * string    : "force_ble_sleep....3  Time_Entry_Sdeep =0\r\n"
 */

undefined4 force_ble_sleep_2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = PTR_DAT_0002ee68;
  puVar1 = PTR_DAT_0002eda8;
  if (*(short *)PTR_DAT_0002ee68 == 0) {
    if (*PTR_DAT_0002eda8 == '\0') {
      force_ble_sleep();
      dbg_printf(str_force_ble_sleep_3_Time_Entry_Sdeep_0);
    }
  }
  else {
    *(short *)PTR_DAT_0002ee68 = *(short *)PTR_DAT_0002ee68 + -1;
    FUN_00035800();
    FUN_0003186e();
    uVar3 = (uint)((byte)PTR_DAT_0002ee6c[0xb] >> 4) << 4 | (uint)((byte)PTR_DAT_0002ee6c[0xc] >> 4)
    ;
    if (uVar3 == 0) {
      uVar3 = 1;
    }
    if (((uVar3 * 0xef - (uint)*(ushort *)puVar2 == 0) && (*PTR_DAT_0002ee70 != '\0')) &&
       (*puVar1 == '\0')) {
      *(undefined2 *)PTR_DAT_0002ee74 = 0;
      FUN_00032f16();
      FUN_00032e82();
      puVar1 = PTR_DAT_0002ee30;
      *PTR_DAT_0002ee30 = 1;
      FUN_0003bf0a();
      FUN_0003d508();
      FUN_0003d546();
      *puVar1 = 1;
      FUN_00032620();
      FUN_00039a84(0x32,0);
    }
    rom_07342(PTR_DAT_0002ed1c + 0xb,3,0x19);
  }
  return 0;
}

/* ==========================================================================
 * FUN_0002f31c   @ 0x0002f31c   (84 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_0002a674, FUN_0002bd62, FUN_0002be1c, FUN_00033dc2, FUN_0003c52e, FUN_0003c574, ... (+4 more)
 */

void FUN_0002f31c(void)

{
  int iVar1;
  
  FUN_0003c6ce();
  iVar1 = FUN_0003c574();
  if (iVar1 != 0) {
    FUN_0003c52e(0);
    FUN_0002a674();
    FUN_0002be1c();
    if ((*DAT_0002f3c4 == '\0') && (*DAT_0002f3c8 != '\0')) {
      if (*DAT_0002f3cc == '\0') {
        sensor_init();
      }
      time_sensor_invalid();
      tx_failed_cnt();
      FUN_0002bd62();
    }
    else if ((*(uint *)(PTR_DAT_0002f3d0 + 0x2c) & 1) == 0) {
      FUN_00033dc2();
      return;
    }
  }
  return;
}

/* ==========================================================================
 * app_ancsc_init   @ 0x0002f3f4   (18 bytes)
 * called by : FUN_00029530
 * calls     : dbg_printf
 * string    : "app_ancsc_init"
 * string    : "%s \r\n"
 */

void app_ancsc_init(void)

{
  dbg_printf(str_s_8,DAT_0002f69c);
  *DAT_0002f6a8 = 0;
  return;
}

/* ==========================================================================
 * app_ancs_add_ancsc   @ 0x0002f406   (50 bytes)
 * calls     : dbg_printf, rom_06EF4, rom_06F26
 * string    : "app_ancs_add_ancsc"
 * string    : "%s \r\n"
 */

void app_ancs_add_ancsc(void)

{
  undefined1 *puVar1;
  
  dbg_printf(str_s_8,DAT_0002f69c + 0xf);
  puVar1 = (undefined1 *)rom_06EF4(PTR_DAT_0002f6ac,7,3,0xc);
  *puVar1 = 0x1b;
  puVar1[1] = 4;
  *(undefined2 *)(puVar1 + 2) = 0x4b;
  *(undefined2 *)(puVar1 + 4) = 3;
  *(undefined2 *)(puVar1 + 6) = 0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * FUN_0002f438   @ 0x0002f438   (40 bytes)
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26
 */

void FUN_0002f438(undefined2 param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  *DAT_0002f6a8 = param_1;
  uVar1 = FUN_0003ee6e(0x4b);
  puVar2 = (undefined2 *)rom_06EF4(&DAT_00004b00,uVar1,3,0x8c);
  *puVar2 = param_1;
  *(undefined1 *)(puVar2 + 1) = 0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * app_ancsc_msg_dflt_handler   @ 0x0002f460   (16 bytes)
 * calls     : dbg_printf
 * string    : "app_ancsc_msg_dflt_handler"
 * string    : "%s \r\n"
 */

undefined4 app_ancsc_msg_dflt_handler(void)

{
  dbg_printf(str_s_8,DAT_0002f69c + 0x22);
  return 0;
}

/* ==========================================================================
 * app_ancsc_delete_call   @ 0x0002f58a   (74 bytes)
 * calls     : FUN_0003ee6e, dbg_printf, rom_06EF4, rom_06F26
 * string    : "app_ancsc_delete_call"
 */

void app_ancsc_delete_call(undefined4 param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  dbg_printf(&LAB_0002f80c,DAT_0002f69c + 0xde);
  uVar1 = FUN_0003ee6e(0x4b);
  puVar2 = (undefined2 *)rom_06EF4(PTR_DAT_0002f6b0 + 4,uVar1,3,10);
  *(undefined1 *)(puVar2 + 1) = 2;
  *(char *)((int)puVar2 + 3) = (char)param_1;
  *(char *)(puVar2 + 2) = (char)((uint)param_1 >> 8);
  *(char *)((int)puVar2 + 5) = (char)((uint)param_1 >> 0x10);
  *(char *)(puVar2 + 3) = (char)((uint)param_1 >> 0x18);
  *(undefined1 *)((int)puVar2 + 7) = 1;
  *puVar2 = 6;
  rom_06F26(puVar2);
  return;
}

/* ==========================================================================
 * FUN_0002f5d4   @ 0x0002f5d4   (72 bytes)
 * calls     : FUN_0003ee6e, dbg_printf, rom_06EF4, rom_06F26
 */

void FUN_0002f5d4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  dbg_printf(0x2f814,DAT_0002f69c + 0xf4);
  uVar1 = FUN_0003ee6e(0x4b);
  iVar2 = rom_06EF4(PTR_DAT_0002f6b0 + 4,uVar1,3,10);
  *(undefined1 *)(iVar2 + 2) = 0;
  *(char *)(iVar2 + 3) = (char)param_1;
  *(char *)(iVar2 + 4) = (char)((uint)param_1 >> 8);
  *(char *)(iVar2 + 5) = (char)((uint)param_1 >> 0x10);
  *(char *)(iVar2 + 6) = (char)((uint)param_1 >> 0x18);
  *(undefined1 *)(iVar2 + 7) = 0;
  *(undefined1 *)(iVar2 + 8) = 0x32;
  *(undefined1 *)(iVar2 + 9) = 0;
  rom_06F26(iVar2);
  return;
}

/* ==========================================================================
 * FUN_00031114   @ 0x00031114   (94 bytes)
 * called by : FUN_000311de, FUN_00031210
 * calls     : FUN_00039a84
 */

void FUN_00031114(void)

{
  FUN_00039a84(0x26,0,2);
  FUN_00039a84(0x27,0,2);
  FUN_00039a84(1,0);
  FUN_00039a84(2,0);
  FUN_00039a84(3,0);
  FUN_00039a84(0x37,0);
  FUN_00039a84(0x30,1,2);
  FUN_00039a84(0x31,1,2);
  FUN_00039a84(0x34,1,2);
  return;
}

/* ==========================================================================
 * FUN_00031172   @ 0x00031172   (66 bytes)
 * called by : FUN_000311de, FUN_00031210
 * calls     : FUN_00032886, FUN_00039a84
 */

void FUN_00031172(void)

{
  int iVar1;
  
  FUN_00039a84(0x12,1,2);
  iVar1 = DAT_00031568;
  *(undefined4 *)(DAT_00031568 + 0x28) = 0;
  FUN_00039a84(0x11,1,2);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  FUN_00039a84(0x10,1,2);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  FUN_00039a84(0x22,1,2);
  *(undefined4 *)(DAT_00031568 + 0x48) = 0;
  FUN_00032886(0);
  return;
}

/* ==========================================================================
 * FUN_000311de   @ 0x000311de   (50 bytes)
 * called by : FUN_0002b4c8, enter_BLE_normal_app_mode
 * calls     : FUN_00031114, FUN_00031172, FUN_00039a84
 */

void FUN_000311de(void)

{
  FUN_00031114();
  FUN_00031172();
  FUN_00039a84(0x34,0,1);
  FUN_00039a84(0x24,0,2);
  *(undefined4 *)(DAT_00031568 + 0x54) = 0x3c;
  FUN_00039a84(0,0,1);
  return;
}

/* ==========================================================================
 * FUN_00031210   @ 0x00031210   (32 bytes)
 * calls     : FUN_00031114, FUN_00031172, FUN_00039a84
 */

void FUN_00031210(void)

{
  FUN_00031114();
  FUN_00039a84(0x34,0,1);
  FUN_00039a84(0x24,0,2);
  FUN_00031172();
  return;
}

/* ==========================================================================
 * FUN_000312aa   @ 0x000312aa   (52 bytes)
 * called by : Disconnected, FUN_00031334, FUN_00031406, FUN_000358b6, FUN_00035abc, FUN_00035b08, ... (+7 more)
 */

void FUN_000312aa(void)

{
  *DAT_00031588 = 0;
  *DAT_0003158c = 0;
  *DAT_00031590 = 0;
  *DAT_00031594 = 0;
  *DAT_00031598 = 0;
  *DAT_0003159c = 0;
  *DAT_0003157c = 0;
  *DAT_00031580 = 0;
  *DAT_000315a0 = 0;
  *DAT_000315a4 = 0;
  *DAT_000315a8 = 0;
  *DAT_000315ac = 0;
  return;
}

/* ==========================================================================
 * FUN_00031334   @ 0x00031334   (210 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_00031230, FUN_000312aa, FUN_000312de, rom_24FEC
 */

void FUN_00031334(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  *DAT_000315e4 = 0;
  *DAT_000315e8 = 0;
  *DAT_000315ec = 0;
  *DAT_000315f0 = 0;
  *DAT_00031584 = 0;
  *DAT_000315f4 = 0;
  *DAT_000315f8 = 0;
  *DAT_000315fc = 0;
  *DAT_00031600 = 0;
  *DAT_00031604 = 0;
  FUN_000312aa();
  FUN_000312de();
  FUN_00031230();
  rom_24FEC(DAT_00031608,0x7e);
  rom_24FEC(DAT_0003160c,0x91);
  *DAT_00031610 = 0;
  *DAT_00031614 = 0;
  *DAT_00031618 = 0;
  *DAT_0003161c = 0;
  *DAT_00031620 = 0;
  *DAT_00031624 = 0;
  *DAT_00031628 = 1;
  *DAT_0003162c = 0;
  *DAT_00031630 = 0;
  *DAT_000315a8 = 0;
  *DAT_00031634 = 1;
  *DAT_00031638 = 0;
  *DAT_0003163c = 0;
  *DAT_00031640 = 0;
  *DAT_00031644 = 0;
  *DAT_00031648 = 0;
  *DAT_0003164c = 0;
  *DAT_00031650 = 0;
  puVar1 = DAT_0003165c;
  *DAT_00031654 = 0;
  puVar2 = DAT_00031660;
  *DAT_00031658 = 0;
  *puVar1 = 5;
  *puVar2 = 4;
  *DAT_00031664 = 5;
  *DAT_00031668 = 5;
  *DAT_0003166c = 5;
  *DAT_00031670 = 8;
  *DAT_00031674 = 0;
  *DAT_00031678 = 0;
  *DAT_0003167c = 0;
  *DAT_00031680 = 0;
  *DAT_00031684 = 0;
  *DAT_00031688 = 0;
  return;
}

/* ==========================================================================
 * FUN_00031406   @ 0x00031406   (54 bytes)
 * called by : Default_Profile, FUN_0002b4de
 * calls     : FUN_00031230, FUN_000312aa, FUN_000312de, rom_24FEC
 */

void FUN_00031406(void)

{
  *DAT_00031584 = 0;
  *DAT_00031654 = 0;
  *DAT_000315f0 = 0;
  *DAT_000315ec = 0;
  *DAT_00031604 = 0;
  FUN_000312aa();
  FUN_00031230();
  FUN_000312de();
  rom_24FEC(DAT_00031608,0x7e);
  *DAT_00031684 = 0;
  *DAT_00031688 = 0;
  return;
}

/* ==========================================================================
 * FUN_0003186e   @ 0x0003186e   (262 bytes)
 * called by : force_ble_sleep_2, system_mode
 * calls     : Disconnected, FUN_0002b8a2, dbg_printf
 * string    : "RB +MB  f_k_pair------------  f_hld=%x f_k_pair=%d\r\n"
 * string    : "RB +MB  f_k_pair------------  RF_MODE=%x\r\n"
 */

void FUN_0003186e(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  undefined4 in_r3;
  
  pcVar7 = DAT_00031ca8;
  pcVar6 = DAT_00031ca4;
  pcVar11 = DAT_00031c9c;
  pcVar5 = DAT_00031c20;
  pcVar4 = DAT_00031c1c;
  if (*DAT_00031c1c != '\0') {
    dbg_printf(str_RB_MB_f_k_pair_f_hld_x_f_k_pair_d,*DAT_00031c20,*DAT_00031c1c,in_r3,in_r3);
    if (*pcVar5 == '\0') {
      *pcVar4 = '\0';
      return;
    }
    if (*DAT_00031c5c == '\0') {
      *pcVar4 = '\0';
      *DAT_00031c60 = 0;
      *DAT_00031c64 = 1;
      puVar3 = DAT_00031c04;
      *DAT_00031c68 = 1;
      *DAT_00031c6c = *puVar3;
      FUN_0002b8a2();
      dbg_printf(str_RB_MB_f_k_pair_RF_MODE_x,*puVar3);
    }
    return;
  }
  if (*DAT_00031c9c == '\0') {
    if (*DAT_00031ca4 == '\0') {
      if (*DAT_00031cb0 == '\0') {
        return;
      }
      *DAT_00031cb0 = '\0';
      puVar8 = DAT_00031cb4;
      uVar1 = *DAT_00031cb4;
      if ((uVar1 == 0x83) && (*pcVar7 != '\0')) {
        *pcVar6 = '\x01';
        *DAT_00031c5c = '\x14';
      }
      uVar2 = *DAT_00031cb8;
      *DAT_00031cb8 = uVar1;
      iVar9 = DAT_00031cbc;
      uVar12 = (uint)(uVar2 ^ uVar1);
      uVar10 = 0;
      do {
        if ((uVar12 & 1) != 0) {
          if ((*puVar8 & 1) == 0) {
            *(byte *)(iVar9 + uVar10) = *(byte *)(iVar9 + uVar10) & 0xfe | 2;
          }
          else {
            *(undefined1 *)(iVar9 + uVar10) = 3;
          }
        }
        uVar12 = uVar12 >> 1;
        uVar10 = uVar10 + 1 & 0xff;
        *puVar8 = *puVar8 >> 1;
      } while (uVar10 < 0xc);
      return;
    }
    pcVar11 = DAT_00031ca4;
    if (*DAT_00031c20 != '\0') {
      if (*DAT_00031c5c != '\0') {
        return;
      }
      *DAT_00031ca4 = '\0';
      *DAT_00031c60 = 0;
      *DAT_00031c64 = 1;
      if (1 < *DAT_00031cac) {
        return;
      }
      if (*pcVar7 == '\0') {
        return;
      }
      *DAT_00031c0c = 2;
      return;
    }
  }
  else {
    if (*DAT_00031c20 != '\0') {
      if (*DAT_00031c5c != '\0') {
        return;
      }
      *DAT_00031c9c = '\0';
      Disconnected();
      return;
    }
    *DAT_00031ca0 = 0;
  }
  *pcVar11 = '\0';
  return;
}

/* ==========================================================================
 * FUN_00031974   @ 0x00031974   (12 bytes)
 * called by : FUN_000319c0
 */

void FUN_00031974(int param_1)

{
  *(byte *)(DAT_00031cbc + param_1) = *(byte *)(DAT_00031cbc + param_1) & 0xfd;
  return;
}

/* ==========================================================================
 * FUN_00031980   @ 0x00031980   (64 bytes)
 * called by : FUN_000332be
 */

undefined4 FUN_00031980(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_00031cc0;
  uVar3 = 1;
  while( true ) {
    if (*(byte *)(DAT_00031cc0 + uVar3) == 0) {
      return 0;
    }
    if (*(byte *)(DAT_00031cc0 + uVar3) == param_1) break;
    uVar3 = uVar3 + 1 & 0xff;
    if (6 < uVar3) {
LAB_000319a2:
      if (uVar3 == 7) {
        return 0;
      }
      for (; uVar3 < 6; uVar3 = uVar3 + 1 & 0xff) {
        iVar2 = iVar1 + uVar3;
        *(undefined1 *)(iVar1 + uVar3) = *(undefined1 *)(iVar2 + 1);
        *(undefined1 *)(iVar2 + 1) = 0;
      }
      return 1;
    }
  }
  *(undefined1 *)(DAT_00031cc0 + uVar3) = 0;
  goto LAB_000319a2;
}

/* ==========================================================================
 * FUN_000319c0   @ 0x000319c0   (194 bytes)
 * called by : FUN_0002aa5c, FUN_0003236a
 * calls     : FUN_00031974, FUN_000332be, rom_25078
 */

void FUN_000319c0(int param_1)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  iVar4 = DAT_00031c64;
  cVar1 = *DAT_00031cc4;
  uVar5 = (uint)*(byte *)(param_1 * 3 + DAT_00031c00 + 0x54);
  bVar2 = *DAT_00031c60;
  uVar6 = uVar5;
  rom_25078();
  pcVar7 = (char *)(iVar4 + -99);
  pcVar7[0] = '\x01';
  pcVar7[1] = '\0';
  cVar3 = *(char *)(uVar6 + 0x1d);
  uRam0000003c = 0;
  if (*DAT_00031cc8 == '\0') {
    if ((*PTR_DAT_00031ccc == '\0') || (param_1 != 0)) {
      Reset = bVar2 & 0xfe;
      *pcVar7 = cVar3;
    }
    else if (cVar1 == '\x02') {
      FUN_000332be();
      *PTR_DAT_00031cd8 = 5;
    }
  }
  if ((*DAT_00031c04 == '\0') && (*pcVar7 != '\0')) {
    *DAT_00031d04 = cVar3;
  }
  if ((uVar5 & 0x3fffffff) != 0) {
    FUN_00031974(param_1);
  }
  return;
}

/* ==========================================================================
 * FUN_00031b3e   @ 0x00031b3e   (112 bytes)
 * called by : FUN_0002aa5c, FUN_0003236a
 * calls     : FUN_00031f7c, rom_25078
 */

/* WARNING: Removing unreachable block (ram,0x00031ba6) */

void FUN_00031b3e(void)

{
  do {
    rom_25078(*DAT_00031c04);
  } while( true );
}

/* ==========================================================================
 * FUN_00031f7c   @ 0x00031f7c   (24 bytes)
 * called by : FUN_00031b3e
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00031f84) */

void FUN_00031f7c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r11;
  undefined4 in_lr;
  bool in_CY;
  bool in_OV;
  
  if (in_CY) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!in_OV) {
    *param_1 = in_lr;
    param_1[-1] = unaff_r11;
    param_1[-2] = unaff_r6;
    param_1[-3] = unaff_r5;
    param_1[-4] = unaff_r4;
    param_1[-5] = param_4;
    param_1[-6] = param_2;
    param_1[-7] = param_1;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * FUN_00032620   @ 0x00032620   (12 bytes)
 * called by : FUN_000326ea, FUN_00032942, FUN_0003297e, SLEEP, enter_BLE_normal_app_mode, force_ble_sleep_2, ... (+1 more)
 */

void FUN_00032620(void)

{
  int iVar1;
  
  iVar1 = DAT_000329e8;
  *(undefined4 *)(DAT_000329e8 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return;
}

/* ==========================================================================
 * FUN_00032686   @ 0x00032686   (42 bytes)
 * called by : FUN_00028c4e, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, rgb_24g_test_cal
 */

void FUN_00032686(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_000329e8;
  if ((param_1 & 1) == 0) {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 2;
  }
  if ((int)(param_1 << 0x1e) < 0) {
    *(undefined4 *)(iVar1 + 0x24) = 2;
  }
  else {
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  if ((int)(param_1 << 0x1d) < 0) {
    *(undefined4 *)(iVar1 + 0x28) = 2;
    return;
  }
  *(undefined4 *)(iVar1 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * FUN_000326ea   @ 0x000326ea   (48 bytes)
 * calls     : FUN_00032620
 */

void FUN_000326ea(void)

{
  char cVar1;
  int iVar2;
  
  FUN_00032620();
  iVar2 = DAT_000329e8;
  cVar1 = *DAT_000329f4;
  if (cVar1 == '\0') {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 2;
  }
  else {
    *(undefined4 *)(DAT_000329e8 + 0x20) = 0;
    if (cVar1 == '\x01') {
      *(undefined4 *)(iVar2 + 0x24) = 2;
      goto LAB_00032712;
    }
  }
  *(undefined4 *)(iVar2 + 0x24) = 0;
  if (cVar1 == '\x02') {
    *(undefined4 *)(iVar2 + 0x28) = 2;
    return;
  }
LAB_00032712:
  *(undefined4 *)(iVar2 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * FUN_000332be   @ 0x000332be   (156 bytes)
 * called by : FUN_000319c0, FUN_0003236a
 * calls     : FUN_00031980, rom_24FEC
 */

undefined4 FUN_000332be(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  puVar5 = PTR_DAT_000333c4;
  puVar3 = DAT_00033380;
  pbVar2 = DAT_00033368;
  if (*DAT_00033368 == 0) {
    return 1;
  }
  if ((*DAT_00033368 < 3) || (*PTR_DAT_000333c4 == '\0')) {
    rom_24FEC(PTR_DAT_000333e8,8,param_3,param_4,param_4);
    *puVar3 = 1;
    *pbVar2 = 0;
  }
  else {
    *DAT_00033368 = 0;
    for (uVar9 = 0; puVar4 = PTR_DAT_000333b0, uVar9 < (byte)*puVar5; uVar9 = uVar9 + 1 & 0xff) {
      bVar1 = PTR_DAT_000333b0[uVar9 * 2 + 0x1a];
      *DAT_000333d4 = bVar1;
      pbVar2 = DAT_000333d8;
      uVar7 = (uint)(byte)puVar4[uVar9 * 2 + 0x1b];
      *DAT_000333d8 = puVar4[uVar9 * 2 + 0x1b];
      puVar6 = PTR_DAT_000333e8;
      puVar4 = PTR_DAT_000333dc;
      if ((uVar7 - 4 < 0xf2) && (-1 < (int)((uint)bVar1 << 0x18))) {
        if (uVar7 < 0xf1) {
          if (uVar7 < 0xe0) {
            iVar8 = FUN_00031980();
            if (iVar8 == 0) goto LAB_0003334a;
          }
          else {
            bVar1 = (byte)(1 << (uVar7 - 0xe0 & 0xff));
            *pbVar2 = bVar1;
            *puVar6 = *puVar6 & ~bVar1;
          }
          *puVar3 = 1;
        }
        else {
          bVar1 = (byte)(1 << (uVar7 - 0xf1 & 0xff));
          *pbVar2 = bVar1;
          *puVar4 = *puVar4 & ~bVar1;
          *DAT_00033388 = 1;
        }
      }
LAB_0003334a:
    }
  }
  return 0;
}

/* ==========================================================================
 * FUN_00033dc2   @ 0x00033dc2   (8 bytes)
 * called by : FUN_0002f31c, SLEEP, f_reconnect_24G, force_ble_sleep
 * calls     : FUN_0003443a
 */

void FUN_00033dc2(void)

{
  FUN_0003443a();
  return;
}

/* ==========================================================================
 * FUN_0003443a   @ 0x0003443a   (86 bytes)
 * called by : FUN_00033dc2, delta_none, time_sensor_invalid
 * calls     : FUN_00031784, FUN_0003aa1a, FUN_0003aa42
 */

void FUN_0003443a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = DAT_00034618;
  *(undefined4 *)(DAT_00034618 + 0x1c) = 0;
  *DAT_0003461c = 0x16;
  FUN_0003aa1a(DAT_0003461c,1,param_3,param_4,param_4);
  FUN_00031784(3);
  FUN_0003aa42(DAT_00034620,6);
  FUN_00031784(1);
  *(undefined4 *)(iVar2 + 0x1c) = 2;
  puVar3 = DAT_00034628;
  uVar1 = *(undefined2 *)(DAT_00034620 + 4);
  if (*DAT_00034620 < '\0') {
    *DAT_00034624 = *(undefined2 *)(DAT_00034620 + 2);
    *puVar3 = uVar1;
    return;
  }
  *DAT_00034624 = 0;
  *puVar3 = 0;
  return;
}

/* ==========================================================================
 * FUN_00035800   @ 0x00035800   (122 bytes)
 * called by : FUN_0003bf40, force_ble_sleep_2
 */

void FUN_00035800(void)

{
  if (*DAT_00035b5c != '\0') {
    *DAT_00035b5c = *DAT_00035b5c + -1;
  }
  if (*DAT_00035b60 != '\0') {
    *DAT_00035b60 = *DAT_00035b60 + -1;
  }
  if (*DAT_00035b64 != '\0') {
    *DAT_00035b64 = *DAT_00035b64 + -1;
  }
  if (*DAT_00035b68 != 0) {
    *DAT_00035b68 = *DAT_00035b68 + -1;
  }
  if (*DAT_00035b6c != '\0') {
    *DAT_00035b6c = *DAT_00035b6c + -1;
  }
  if (*DAT_00035b70 != '\0') {
    *DAT_00035b70 = *DAT_00035b70 + -1;
  }
  if (*DAT_00035b74 != '\0') {
    *DAT_00035b74 = *DAT_00035b74 + -1;
  }
  if (*DAT_00035b78 != '\0') {
    *DAT_00035b78 = *DAT_00035b78 + -1;
  }
  if (*DAT_00035b7c != '\0') {
    *DAT_00035b7c = *DAT_00035b7c + -1;
  }
  if (*DAT_00035b80 != '\0') {
    *DAT_00035b80 = *DAT_00035b80 + -1;
  }
  return;
}

/* ==========================================================================
 * disconnect   @ 0x00035a5e   (94 bytes)
 * calls     : FUN_00029490, FUN_000295aa, FUN_000312aa, app_user_ke_timer_stop, ble_alert_led_stop, dbg_printf, ... (+1 more)
 * string    : "app_env.adv_state...= %d\r\n"
 * string    : "disconnect start \r\n"
 * string    : "appm  need stop adv...\r\n"
 */

void disconnect(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = rom_071EA(3);
  iVar1 = DAT_00035c10;
  if (iVar2 == 3) {
    dbg_printf(str_disconnect_start_2);
    *DAT_00035c44 = *DAT_00035c44 | 0x100;
    FUN_000295aa();
    *DAT_00035c48 = 1;
  }
  else {
    dbg_printf(str_app_env_adv_state_d_3,*(undefined1 *)(DAT_00035c10 + 4));
    if (*(char *)(iVar1 + 4) == '\x06') {
      dbg_printf(str_appm_need_stop_adv_2);
      FUN_00029490();
      *DAT_00035c68 = 0;
    }
  }
  app_user_ke_timer_stop();
  ble_alert_led_stop();
  FUN_000312aa();
  *PTR_DAT_00035c6c = 0;
  return;
}

/* ==========================================================================
 * FUN_00035abc   @ 0x00035abc   (76 bytes)
 * calls     : FUN_000312aa, FUN_00032892
 */

void FUN_00035abc(void)

{
  FUN_00032892();
  *DAT_00035ba4 = 1;
  *(undefined2 *)PTR_DAT_00035c70 = 0;
  *PTR_DAT_00035c74 = 0;
  *DAT_00035b70 = 0;
  *PTR_DAT_00035c78 = 0;
  *PTR_DAT_00035c7c = 0;
  *DAT_00035b68 = 0;
  *PTR_DAT_00035c80 = 0;
  *DAT_00035b6c = 0;
  *PTR_DAT_00035c84 = 0;
  *DAT_00035b9c = 0;
  *DAT_00035b98 = 0;
  *PTR_DAT_00035c88 = 0;
  *PTR_DAT_00035c8c = 0;
  FUN_000312aa();
  *PTR_DAT_00035c6c = 0;
  return;
}

/* ==========================================================================
 * FUN_00035b08   @ 0x00035b08   (74 bytes)
 * calls     : FUN_000312aa, FUN_00032892, FUN_0003723e
 */

void FUN_00035b08(void)

{
  FUN_0003723e(PTR_FUN_00038144_1_00035c94,PTR_FUN_00038296_1_00035c90);
  FUN_00032892();
  *PTR_DAT_00035c98 = 0;
  *(undefined2 *)PTR_DAT_00035c70 = 0;
  *PTR_DAT_00035c74 = 0;
  *DAT_00035b70 = 0;
  *PTR_DAT_00035c78 = 0;
  *PTR_DAT_00035c7c = 0;
  *DAT_00035b68 = 0;
  *PTR_DAT_00035c80 = 0;
  *DAT_00035b6c = 0;
  *PTR_DAT_00035c84 = 0;
  *DAT_00035b9c = 0;
  *DAT_00035b98 = 0;
  FUN_000312aa();
  *PTR_DAT_00035c6c = 0;
  return;
}

/* ==========================================================================
 * FUN_00035cd2   @ 0x00035cd2   (44 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_000317c2, dbg_printf
 * string    : "in 24 \r\n"
 */

void FUN_00035cd2(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_00035e34;
  if (*DAT_00035e30 == '\0') {
    *DAT_00035e34 = 0;
    if ((*DAT_00035e38 == 7) || (*DAT_00035e38 == 10)) {
      dbg_printf(str_in_24);
      *puVar1 = 1;
      FUN_000317c2(5);
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0003723e   @ 0x0003723e   (32 bytes)
 * called by : FUN_00035b08, FUN_00038f4e
 */

void FUN_0003723e(code *param_1,code *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = DAT_00037384;
  *(undefined1 *)(DAT_00037384 + 9) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  *(undefined1 *)(iVar1 + 0xb) = 0;
  (*param_2)(0);
  puVar2 = (undefined1 *)(DAT_00037384 + 0x80);
  *(undefined1 *)(DAT_00037384 + 0x8c) = 0;
  *puVar2 = 0;
  (*param_1)(0);
  return;
}

/* ==========================================================================
 * Get_MODE_Switch_status   @ 0x00038da4   (82 bytes)
 * called by : force_pair_en
 * calls     : FUN_00031784, dbg_printf
 * string    : "Get_MODE_Switch_status"
 * string    : "%s,Get_MODE_Switch=:%x\r\n"
 */

undefined4 Get_MODE_Switch_status(void)

{
  int iVar1;
  
  iVar1 = DAT_00038f88;
  *(undefined4 *)(DAT_00038f88 + 0x10) = 0xc;
  FUN_00031784(0xfa);
  dbg_printf(str_s_Get_MODE_Switch_x,DAT_00038ff0 + 0x16,*(uint *)(iVar1 + 0x10) & 1);
  if (((((*(uint *)(iVar1 + 0x10) & 1) == 0) &&
       (FUN_00031784(0xfa), (*(uint *)(iVar1 + 0x10) & 1) == 0)) &&
      (FUN_00031784(0xfa), (*(uint *)(iVar1 + 0x10) & 1) == 0)) &&
     (FUN_00031784(0xfa), (*(uint *)(iVar1 + 0x10) & 1) == 0)) {
    return 0;
  }
  return 1;
}

/* ==========================================================================
 * FUN_00038f4e   @ 0x00038f4e   (12 bytes)
 * calls     : FUN_0003723e
 */

void FUN_00038f4e(void)

{
  FUN_0003723e(DAT_000390ec,DAT_000390e8);
  return;
}

/* ==========================================================================
 * FUN_00039198   @ 0x00039198   (40 bytes)
 * called by : FUN_00039428, FUN_0003b34c, FUN_0003b3f2, FUN_0003b47e
 */

void FUN_00039198(uint param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = DAT_0003958c;
  uVar2 = DAT_0003958c[7];
  DAT_0003958c[7] =
       uVar2 & 0x1f0 | param_1 | (int)DAT_0003958c >> 0xe & uVar2 | DAT_00039590 & uVar2 |
       uVar2 & (int)DAT_0003958c << 0xd;
  do {
  } while (*piVar1 < 0);
  return;
}

/* ==========================================================================
 * FUN_000393bc   @ 0x000393bc   (76 bytes)
 * called by : FUN_00039408
 */

void FUN_000393bc(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = DAT_0003958c;
  uVar2 = DAT_0003958c[7];
  do {
  } while (*DAT_0003958c < 0);
  DAT_0003958c[7] =
       uVar2 & 0xf | uVar2 & 0xc0 | 0x10 | uVar2 & 0x200 | DAT_00039590 & uVar2 | uVar2 & 0x4000000;
  iVar3 = DAT_000395e8;
  if (*(int *)(DAT_0003959c + 8) == -DAT_000395c8) {
    iVar3 = DAT_000395e4;
  }
  *piVar1 = iVar3;
  do {
  } while (*piVar1 < 0);
  return;
}

/* ==========================================================================
 * FUN_00039408   @ 0x00039408   (32 bytes)
 * called by : FUN_00039428
 * calls     : FUN_000393bc
 */

void FUN_00039408(void)

{
  int *piVar1;
  
  FUN_000393bc();
  piVar1 = DAT_0003958c;
  DAT_0003958c[7] = DAT_0003958c[7] & 0xffffff8f;
  piVar1[7] = piVar1[7] | 0x10;
  do {
  } while (*piVar1 < 0);
  return;
}

/* ==========================================================================
 * FUN_00039428   @ 0x00039428   (18 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_00039198, FUN_00039408, flash_mid
 */

void FUN_00039428(void)

{
  flash_mid();
  FUN_00039408();
  FUN_00039198(8);
  return;
}

/* ==========================================================================
 * FUN_0003948a   @ 0x0003948a   (156 bytes)
 * called by : FUN_00039526, FUN_000396da, force_pair_en
 * calls     : rom_25024, rom_25038, rom_2504C, rom_2505C
 */

void FUN_0003948a(undefined1 *param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_44 [8];
  uint *local_24;
  int local_1c;
  int local_18;
  
  uVar4 = param_2 & 0xffffffe0;
  local_24 = local_44;
  if (param_3 != 0) {
    local_18 = rom_25024();
    local_1c = rom_25038();
    do {
    } while ((int)*DAT_0003958c < 0);
    while (puVar1 = DAT_0003958c, param_3 != 0) {
      *DAT_0003958c = uVar4 | 0x25000000;
      do {
      } while ((int)*puVar1 < 0);
      uVar4 = uVar4 + 0x20;
      uVar3 = 0;
      do {
        uVar2 = uVar3 + 1;
        local_44[uVar3] = DAT_0003958c[2];
        uVar3 = uVar2;
      } while (uVar2 < 8);
      for (uVar3 = param_2 & 0x1f; uVar3 < 0x20; uVar3 = uVar3 + 1) {
        param_3 = param_3 + -1;
        param_2 = param_2 + 1;
        *param_1 = *(undefined1 *)((int)local_24 + uVar3);
        param_1 = param_1 + 1;
        if (param_3 == 0) goto LAB_000394fa;
      }
    }
LAB_000394fa:
    puVar1 = DAT_0003958c;
    *DAT_0003958c = 0x7d000;
    uVar4 = 0;
    do {
      puVar1[1] = 0xffffffff;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
    if (local_18 == 0) {
      rom_2504C();
    }
    if (local_1c == 0) {
      rom_2505C();
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00039a84   @ 0x00039a84   (84 bytes)
 * called by : FUN_00031114, FUN_00031172, FUN_000311b4, FUN_000311de, FUN_00031210, FUN_00039b82, ... (+13 more)
 */

void FUN_00039a84(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 == 0) {
    uVar1 = 0xc;
  }
  else if (param_2 != 1) {
    if (param_2 == 2) {
      uVar1 = 8;
    }
    else if (param_2 == 3) {
      uVar1 = 0x40;
    }
  }
  if (param_3 == 0) {
    uVar1 = uVar1 | 0x30;
  }
  else if (param_3 == 1) {
    uVar1 = uVar1 | 0x20;
  }
  *(uint *)(PTR_DAT_00039c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4) = uVar1;
  return;
}

/* ==========================================================================
 * FUN_00039b82   @ 0x00039b82   (44 bytes)
 * calls     : FUN_00039a84
 */

void FUN_00039b82(void)

{
  FUN_00039a84(4,1,2);
  FUN_00039a84(5,1,2);
  FUN_00039a84(6,1,2);
  FUN_00039a84(7,1,2);
  return;
}

/* ==========================================================================
 * FUN_00039bc2   @ 0x00039bc2   (10 bytes)
 * called by : FUN_0002b4c8
 */

void FUN_00039bc2(int param_1)

{
  if (param_1 != 0) {
    *DAT_00039c0c = param_1;
  }
  return;
}

/* ==========================================================================
 * FUN_00039bcc   @ 0x00039bcc   (22 bytes)
 * called by : FUN_0003c008
 */

void FUN_00039bcc(void)

{
  *DAT_00039c10 = *DAT_00039c10 & ~((int)DAT_00039c10 >> 0xe);
  if ((code *)*DAT_00039c0c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00039bde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*DAT_00039c0c)();
    return;
  }
  return;
}

/* ==========================================================================
 * FUN_00039c02   @ 0x00039c02   (2 bytes)
 * called by : FUN_0003c008
 */

void FUN_00039c02(void)

{
  return;
}

/* ==========================================================================
 * FUN_0003a244   @ 0x0003a244   (218 bytes)
 * called by : rwip_driver_init
 * calls     : cal_data, rom_24F9C
 */

void FUN_0003a244(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 local_30 [48];
  
  param_1[8] = DAT_0003a558;
  param_1[9] = DAT_0003a55c;
  param_1[5] = DAT_0003a560;
  *(undefined1 *)(param_1 + 0xb) = 1;
  *(undefined1 *)((int)param_1 + 0x2d) = 0xc;
  param_1[10] = DAT_0003a564;
  *param_1 = DAT_0003a568;
  param_1[1] = DAT_0003a56c;
  param_1[7] = DAT_0003a570;
  param_1[6] = DAT_0003a574;
  uVar6 = 0;
  do {
    local_30[uVar6] = (char)(uVar6 << 1);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0x28);
  rom_24F9C(DAT_0003a578,local_30,0x28);
  cal_data();
  iVar1 = DAT_0003a57c;
  *(undefined4 *)(DAT_0003a57c + 0x34) = 0x20;
  *(undefined4 *)(iVar1 + 0x34) = 0x20;
  *(undefined4 *)(DAT_0003a57c + 0xa0) = DAT_0003a580;
  iVar1 = DAT_0003a588;
  *(undefined4 *)(DAT_0003a588 + 0x38) = DAT_0003a584;
  *(undefined4 *)(iVar1 + 0x38) = DAT_0003a58c;
  uVar3 = DAT_0003a590;
  *(undefined4 *)(DAT_0003a588 + 0x40) = DAT_0003a590;
  uVar4 = DAT_0003a594;
  *(undefined4 *)(DAT_0003a588 + 0x40) = DAT_0003a594;
  uVar5 = DAT_0003a598;
  iVar1 = DAT_0003a588;
  *(undefined4 *)(DAT_0003a588 + 0x44) = DAT_0003a598;
  *(undefined4 *)(iVar1 + 0x44) = uVar5;
  *(undefined4 *)(iVar1 + 0x48) = uVar3;
  *(undefined4 *)(iVar1 + 0x48) = uVar4;
  *(undefined4 *)(iVar1 + 0x4c) = DAT_0003a59c;
  *(undefined4 *)(iVar1 + 0x4c) = 0x65;
  uVar3 = DAT_0003a5a0;
  *(undefined4 *)(iVar1 + 0x50) = DAT_0003a5a0;
  *(undefined4 *)(iVar1 + 0x50) = uVar3;
  uVar3 = DAT_0003a5a4;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0003a5a4;
  *(undefined4 *)(iVar1 + 0x54) = uVar3;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0003a5a8;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0003a5ac;
  *(undefined4 *)(iVar1 + 0x5c) = DAT_0003a5b0;
  *(undefined4 *)(iVar1 + 0x5c) = 0x20;
  iVar1 = DAT_0003a57c;
  uVar6 = DAT_0003a57c << 0x18;
  *(uint *)(DAT_0003a57c + 0x34) = *(uint *)(DAT_0003a57c + 0x34) & ~uVar6 | uVar6;
  iVar2 = DAT_0003a57c;
  *(uint *)(DAT_0003a57c + 0x34) = *(uint *)(iVar1 + 0x34) & ~((int)uVar6 >> 0x11);
  *(uint *)(iVar2 + 0x34) = *(uint *)(iVar2 + 0x34) & ~uVar6 | uVar6;
  return;
}

/* ==========================================================================
 * FUN_0003a688   @ 0x0003a688   (68 bytes)
 * called by : RC32K
 */

void FUN_0003a688(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0003a8ec;
  *(uint *)(DAT_0003a8ec + 0x30) = *(uint *)(DAT_0003a8ec + 0x30) & 0xffffdfff;
  iVar1 = DAT_0003a8e0;
  *(undefined4 *)(DAT_0003a8e0 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xffff7fff;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xffffffbf;
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xffff7fff;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 0x8000;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  return;
}

/* ==========================================================================
 * FUN_0003aad4   @ 0x0003aad4   (92 bytes)
 * called by : FUN_0003c008
 */

void FUN_0003aad4(void)

{
  int iVar1;
  int iVar2;
  
  *DAT_0003ad24 = *DAT_0003ad24 & 0xffffffbf;
  iVar2 = DAT_0003ad0c;
  *(undefined1 *)(DAT_0003ad0c + 1) = 1;
  iVar1 = DAT_0003ad08;
  if (*(int *)(DAT_0003ad08 + 8) << 0x12 < 0) {
    *(uint *)(DAT_0003ad08 + 8) = *(uint *)(DAT_0003ad08 + 8) | 0x2000;
    if (*(code **)(iVar2 + 4) != (code *)0x0) {
      (**(code **)(iVar2 + 4))();
    }
  }
  if (*(int *)(iVar1 + 8) << 0x11 < 0) {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x4000;
  }
  if (*(int *)(iVar1 + 8) << 0x13 < 0) {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x1000;
  }
  if (*(int *)(iVar1 + 8) << 0x16 < 0) {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x200;
  }
  return;
}

/* ==========================================================================
 * FUN_0003abf2   @ 0x0003abf2   (132 bytes)
 * calls     : FUN_00039a84, dbg_printf
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003abf2(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  DAT_0080000c = DAT_0080000c & 0xffffdfff;
  *DAT_0003ad24 = *DAT_0003ad24 | 0x40;
  FUN_00039a84(4,3,2);
  FUN_00039a84(5,3,2);
  FUN_00039a84(6,3,2);
  FUN_00039a84(7,3,2);
  puVar1 = DAT_0003ad08;
  *DAT_0003ad08 = 0;
  *puVar1 = _DAT_0003ad6c;
  puVar1[1] = 0xf;
  DAT_00800010 = DAT_00800010 | 0x800;
  *puVar1 = *puVar1 | 0x800000;
  puVar1[2] = puVar1[2] | 0x30000;
  iVar2 = DAT_0003ad54;
  iVar3 = 0;
  do {
    pbVar4 = *(byte **)(iVar2 + 4);
    puVar1[3] = (uint)*pbVar4;
    iVar3 = iVar3 + 1;
    *(byte **)(iVar2 + 4) = pbVar4 + 1;
  } while (iVar3 < 10);
  dbg_printf(str_SPI_CTRL_1_slave_x,*puVar1);
  return;
}

/* ==========================================================================
 * FUN_0003ae40   @ 0x0003ae40   (54 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void FUN_0003ae40(void)

{
  DAT_00800000 = DAT_00800000 & 0xfffffdff;
  DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  *(undefined4 *)(DAT_0003b24c + 0x1c) = 0x80;
  DAT_00800034 = DAT_00800034 | 0x40;
  *(undefined4 *)(DAT_0003b254 + 0x10) = DAT_0003b250;
  return;
}

/* ==========================================================================
 * FUN_0003ae82   @ 0x0003ae82   (170 bytes)
 * called by : FUN_00028c66, FUN_000360aa
 */

void FUN_0003ae82(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = DAT_0003b260;
  uVar2 = DAT_0003b25c;
  DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  *(undefined4 *)(DAT_0003b260 + 0x18) = DAT_0003b25c;
  iVar4 = DAT_0003b264;
  *(undefined4 *)(DAT_0003b264 + 0x18) = uVar2;
  iVar5 = DAT_0003b268;
  *(int *)(iVar3 + 0x28) = DAT_0003b268;
  *(int *)(iVar4 + 0x28) = iVar5;
  iVar5 = DAT_0003b24c;
  *(uint *)(DAT_0003b24c + 0x1c) = *(uint *)(DAT_0003b24c + 0x1c) | 0x80;
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 2;
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 4;
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 1;
  *(undefined1 *)(DAT_0003b258 + 2) = 1;
  iVar1 = DAT_0003b254;
  uVar6 = *(uint *)(iVar5 + 0x1c);
  *(uint *)(DAT_0003b254 + 0x10) = (*(uint *)(DAT_0003b254 + 0x10) & 0xffff0fff) + 0x7000;
  *(uint *)(iVar1 + 0x10) = (*(uint *)(iVar1 + 0x10) & 0xffffff0f) + 0x70;
  DAT_00800008 = DAT_00800008 & 0xfffffe7f;
  *(uint *)(iVar5 + 0x1c) = uVar6 | 8;
  DAT_00800004 = DAT_00800004 | 1;
  *(undefined4 *)(iVar5 + 0x1c) = 0x80;
  *(undefined4 *)(iVar1 + 0x10) = DAT_0003b26c;
  uVar2 = DAT_0003b270;
  DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80;
  *(undefined4 *)(iVar3 + 0x18) = DAT_0003b270;
  *(undefined4 *)(iVar4 + 0x18) = uVar2;
  iVar5 = DAT_0003b268 + 4;
  *(int *)(iVar3 + 0x28) = iVar5;
  *(int *)(iVar4 + 0x28) = iVar5;
  return;
}

/* ==========================================================================
 * FUN_0003af2c   @ 0x0003af2c   (64 bytes)
 * called by : FUN_00028c66, FUN_0003c008
 * calls     : rom_25078
 */

void FUN_0003af2c(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = DAT_0003b24c;
  if (*(char *)(DAT_0003b258 + 2) != '\0') {
    *(undefined4 *)(DAT_0003b24c + 0x1c) = 0x80;
    iVar1 = iVar1 * 0x20000;
    uVar2 = rom_25078();
    *(uint *)(iVar1 + 8) = (*(uint *)(iVar1 + 8) & 0xffffff80) + 2;
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | (uint)((longlong)uVar2 >> 0x34);
    *(undefined1 *)(((int)uVar2 >> 0x14) + 2) = 0;
  }
  return;
}

/* ==========================================================================
 * FUN_0003af8a   @ 0x0003af8a   (24 bytes)
 * called by : FUN_00028c66, SLEEP, exist
 */

void FUN_0003af8a(void)

{
  *(uint *)(DAT_0003b254 + 0x10) = *(uint *)(DAT_0003b254 + 0x10) & 0xfffeffff;
  DAT_00800004 = DAT_00800004 | 1;
  return;
}

/* ==========================================================================
 * FUN_0003b0b8   @ 0x0003b0b8   (102 bytes)
 * calls     : FUN_00039a84
 */

void FUN_0003b0b8(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  FUN_00039a84(param_1,0);
  uVar2 = (param_1 >> 4) * 8 + (param_1 & 0xf);
  *(uint *)(DAT_0003b254 + -0x34) = 1 << (uVar2 & 0xff) | *(uint *)(DAT_0003b254 + -0x34);
  puVar1 = DAT_0003b274;
  if (0xf < uVar2) {
    DAT_0003b274[1] = 3 << (uVar2 * 2 - 0x20 & 0xff) | DAT_0003b274[1];
  }
  else {
    *DAT_0003b274 = 3 << (uVar2 * 2 & 0xff) | *DAT_0003b274;
  }
  puVar1[3] = 1 << (uint)(0xf >= uVar2) | puVar1[3];
  puVar1[5] = 1 << (uint)(uVar2 < 0x10) | puVar1[5];
  return;
}

/* ==========================================================================
 * reset   @ 0x0003b152   (140 bytes)
 * called by : FUN_0002a78c
 * calls     : dbg_printf
 * string    : "reset 0 err\r\n"
 * string    : "wdt reset\r\n"
 * string    : "reset 1 err\r\n"
 * string    : "force all reset\r\n"
 * string    : "force digital reset\r\n"
 * string    : "reset 3 err\r\n"
 * string    : "deep sleep reset\r\n"
 * string    : "power on reset\r\n"
 */

undefined4 reset(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint *puVar5;
  
  iVar1 = DAT_0003b254;
  puVar5 = (uint *)(DAT_0003b254 + -0x40);
  dbg_printf(str_s36reset_reason_x_x + 2,*puVar5,*(undefined4 *)(DAT_0003b254 + -0x34));
  uVar4 = (*puVar5 & 0x7ff) >> 8;
  uVar2 = *(uint *)(iVar1 + -0x34) & 0xffff;
  *puVar5 = *puVar5 & 0xfffff8ff;
  if (uVar4 == 1) {
    if (uVar2 == 0) {
      dbg_printf(str_force_all_reset);
      return 2;
    }
    if (uVar2 + DAT_0003b2a4 == 0) {
      dbg_printf(str_wdt_reset);
      return 1;
    }
    pcVar3 = str_reset_1_err;
  }
  else if (uVar4 == 3) {
    if (uVar2 == 0) {
      dbg_printf(str_power_on_reset);
      return 5;
    }
    if (uVar2 + DAT_0003b2d8 == 0) {
      dbg_printf(str_deep_sleep_reset);
      return 3;
    }
    if (uVar2 + DAT_0003b2d8 + DAT_0003b2dc == 0) {
      dbg_printf(str_force_digital_reset);
      return 4;
    }
    pcVar3 = str_reset_3_err;
  }
  else {
    pcVar3 = str_reset_0_err;
  }
  dbg_printf(pcVar3);
  return 0;
}

/* ==========================================================================
 * FUN_0003b34c   @ 0x0003b34c   (166 bytes)
 * calls     : FUN_00039198, FUN_0003b214
 */

void FUN_0003b34c(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_00039198(8);
  puVar1 = PTR_DAT_0003b4e8;
  *(uint *)(PTR_DAT_0003b4e8 + 0xc) = *(uint *)(PTR_DAT_0003b4e8 + 0xc) | 0x80000000;
  *(undefined4 *)(PTR_DAT_0003b4ec + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  FUN_0003b214();
  iVar2 = DAT_0003b4f0;
  DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  *(uint *)(DAT_0003b4f0 + 0x1c) = *(uint *)(DAT_0003b4f0 + 0x1c) | 0x80;
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 4;
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 1;
  iVar3 = DAT_0003b4f4;
  uVar4 = *(uint *)(iVar2 + 0x1c);
  *(uint *)(DAT_0003b4f4 + 0x10) = (*(uint *)(DAT_0003b4f4 + 0x10) & 0xffff0fff) + 0x5000;
  *(uint *)(iVar3 + 0x10) = (*(uint *)(iVar3 + 0x10) & 0xffffff0f) + 0x50;
  DAT_00800008 = DAT_00800008 & 0xfffffe7f;
  *(uint *)(iVar2 + 0x1c) = uVar4 | 8;
  DAT_00800004 = DAT_00800004 | 1;
  *(undefined4 *)(iVar2 + 0x1c) = 0x80;
  *(undefined4 *)(iVar3 + 0x10) = DAT_0003b4f8;
  DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80;
  return;
}

/* ==========================================================================
 * FUN_0003b47e   @ 0x0003b47e   (106 bytes)
 * called by : FUN_0003c008
 * calls     : FUN_00039198
 */

void FUN_0003b47e(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_0003b4fc;
  if (*(char *)(DAT_0003b4fc + 3) != '\x01') {
    return;
  }
  *(undefined4 *)(DAT_0003b4f0 + 0x1c) = 0x80;
  *(undefined4 *)(DAT_0003b4f4 + 0x10) = DAT_0003b4f8;
  cVar1 = *(char *)(iVar2 + 1);
  if (cVar1 == '\x01') {
    DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
    goto LAB_0003b4d2;
  }
  if (cVar1 == '\x03') {
LAB_0003b4de:
    uVar3 = (DAT_00800008 & 0xffffff80) + 1;
  }
  else {
    if (cVar1 != '\x04') {
      if (cVar1 != '\x05') goto LAB_0003b4d2;
      goto LAB_0003b4de;
    }
    uVar3 = (DAT_00800008 & 0xffffff80) + 2;
  }
  DAT_00800008 = uVar3 | 0x180;
LAB_0003b4d2:
  FUN_00039198(8);
  *(undefined1 *)(iVar2 + 3) = 0;
  return;
}

/* ==========================================================================
 * FUN_0003b512   @ 0x0003b512   (22 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void FUN_0003b512(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0003b564;
  *DAT_0003b564 = 3;
  puVar1[1] = 0;
  puVar1[2] = param_1;
  puVar1[1] = 0x5a;
  puVar1[1] = 0xa5;
  return;
}

/* ==========================================================================
 * FUN_0003b538   @ 0x0003b538   (22 bytes)
 * called by : BLE_PAIR, FUN_0003bb38, FUN_000405ae, SLEEP, exist
 */

void FUN_0003b538(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0003b564;
  *DAT_0003b564 = 3;
  puVar1[1] = 0;
  puVar1[2] = param_1;
  puVar1[1] = 0x5a;
  puVar1[1] = 0xa5;
  return;
}

/* ==========================================================================
 * FUN_0003b5e6   @ 0x0003b5e6   (18 bytes)
 * called by : FUN_0003c008
 */

void FUN_0003b5e6(void)

{
  *DAT_0003b6bc = *DAT_0003b6bc | (int)DAT_0003b6bc >> 0xf;
  *DAT_0003b6c8 = 1;
  return;
}

/* ==========================================================================
 * FUN_0003b6f6   @ 0x0003b6f6   (72 bytes)
 * calls     : FUN_00039a84, rom_24F24
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003b6f6(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  *(uint *)(param_3 * 0x800000 + 0xc) = *(uint *)(param_3 * 0x800000 + 0xc) & 0xfffffffd;
  iVar3 = rom_24F24(_DAT_0003b8bc,param_1);
  FUN_00039a84(0x16,3,0);
  FUN_00039a84(0x17,3,0);
  puVar1 = PTR_DAT_0003b8c0;
  *(int *)PTR_DAT_0003b8c0 = (iVar3 + -1) * 0x100 + 0x19;
  *(undefined4 *)(puVar1 + 4) = _DAT_0003b8c4;
  *(undefined4 *)(puVar1 + 0x10) = 0x42;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  puVar2 = DAT_0003b8c8;
  *DAT_0003b8c8 = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  return;
}

/* ==========================================================================
 * FUN_0003b8e0   @ 0x0003b8e0   (30 bytes)
 * called by : FUN_0003ba0a, FUN_0003bb38, FUN_0003bd90
 * calls     : FUN_0003be98
 */

void FUN_0003b8e0(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  
  while (param_2 != 0) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_0003be98(uVar1);
    param_2 = param_2 - 1 & 0xffff;
  }
  return;
}

/* ==========================================================================
 * FUN_0003b904   @ 0x0003b904   (46 bytes)
 * called by : FUN_0003b932, FUN_0003bdca, FUN_0003bde6
 * calls     : rom_24FEC
 */

void FUN_0003b904(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_0003bcf8;
  if ((param_1 & 1) != 0) {
    *(undefined4 *)(DAT_0003bcf8 + -0x48) = 0;
    rom_24FEC(iVar1 + -0x44,0x40);
    *(undefined4 *)(iVar1 + -4) = 0;
  }
  iVar1 = DAT_0003bcf8;
  if ((int)(param_1 << 0x1e) < 0) {
    rom_24FEC(DAT_0003bcf8 + 4,0x40);
    *(undefined4 *)(iVar1 + 0x44) = 0;
  }
  return;
}

/* ==========================================================================
 * FUN_0003b932   @ 0x0003b932   (124 bytes)
 * called by : FUN_00028c4e
 * calls     : FUN_00028c48, FUN_00039a84, FUN_0003b904, rom_24F24
 */

void FUN_0003b932(undefined4 param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  DAT_0080000c = DAT_0080000c & 0xfffffffe;
  iVar4 = rom_24F24(DAT_0003bcfc,param_1);
  FUN_00039a84(0,3);
  FUN_00039a84(1,3,0);
  piVar1 = DAT_0003bd00;
  *DAT_0003bd00 = (iVar4 + -1) * 0x100 + 0x1b;
  piVar1[1] = DAT_0003bd04;
  piVar1[4] = 0x42;
  piVar1[6] = 0;
  piVar1[7] = 0;
  *DAT_0003bd08 = *DAT_0003bd08 | 0x10;
  puVar2 = DAT_0003bd0c;
  *DAT_0003bd0c = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  puVar3 = DAT_0003bd10;
  DAT_0003bd10[2] = 0;
  *puVar3 = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[8] = 0;
  *(undefined1 *)(puVar3 + 9) = 0;
  *(undefined1 *)((int)puVar3 + 0x25) = 0;
  iVar4 = FUN_00028c48();
  if (iVar4 == 1) {
    FUN_0003b904(3);
    *DAT_0003bcf8 = PTR_FUN_0003b8e0_1_0003bd14;
  }
  return;
}

/* ==========================================================================
 * FUN_0003ba0a   @ 0x0003ba0a   (40 bytes)
 * calls     : FUN_0003b8e0, FUN_000429fc
 */

uint FUN_0003ba0a(void)

{
  uint uVar1;
  undefined4 in_stack_00000000;
  undefined1 auStack_88 [128];
  
  uVar1 = FUN_000429fc(auStack_88,in_stack_00000000,&stack0x00000004);
  FUN_0003b8e0(auStack_88,uVar1 & 0xffff);
  return uVar1;
}

/* ==========================================================================
 * FUN_0003ba28   @ 0x0003ba28   (30 bytes)
 * calls     : FUN_0003be98
 */

char FUN_0003ba28(char *param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    FUN_0003be98();
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}

/* ==========================================================================
 * FUN_0003ba46   @ 0x0003ba46   (40 bytes)
 * called by : FUN_0003bb38
 */

void FUN_0003ba46(undefined1 *param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_str_s0123456789ABCDEF_2_0003bd18;
  for (uVar2 = 3; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xff) {
    *param_1 = puVar1[*(byte *)(param_2 + uVar2) >> 4];
    param_1[1] = puVar1[*(byte *)(param_2 + uVar2) & 0xf];
    param_1 = param_1 + 2;
  }
  return;
}

/* ==========================================================================
 * FUN_0003ba6e   @ 0x0003ba6e   (26 bytes)
 * called by : FUN_0003bb38
 * calls     : rom_24F9C
 */

void FUN_0003ba6e(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_0003bcf8;
  *(undefined4 *)(DAT_0003bcf8 + -0x48) = 0;
  rom_24F9C(iVar1 + -0x44,param_1,param_2);
  *(undefined4 *)(iVar1 + -4) = param_2;
  return;
}

/* ==========================================================================
 * FUN_0003bad6   @ 0x0003bad6   (32 bytes)
 * called by : FUN_0003bb38
 * calls     : rom_25078
 */

void FUN_0003bad6(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0003bd0c;
  iVar2 = rom_25078();
  if (iVar2 != 1) {
    return;
  }
  *(undefined1 *)(iVar1 + 3) = 1;
  return;
}

/* ==========================================================================
 * FUN_0003bb38   @ 0x0003bb38   (498 bytes)
 * calls     : FUN_00028c48, FUN_0003b538, FUN_0003b8e0, FUN_0003ba46, FUN_0003ba6e, FUN_0003bad6, ... (+2 more)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003bb38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  puVar2 = DAT_0003bd0c;
  uVar8 = *(uint *)(DAT_0003bd00 + 0x14);
  if ((uVar8 & 0x42) == 0) goto LAB_0003bd7a;
  iVar6 = DAT_0003bd10 + 0x28;
  *_LAB_0003bd20 = 1;
  while (*(int *)(DAT_0003bd00 + 8) << 10 < 0) {
    *(char *)(iVar6 + *(int *)(puVar2 + 8)) = (char)((uint)*(undefined4 *)(DAT_0003bd00 + 0xc) >> 8)
    ;
    FUN_0003bad6(*(undefined1 *)(iVar6 + *(int *)(puVar2 + 8)));
    *(int *)(puVar2 + 8) = *(int *)(puVar2 + 8) + 1;
    if (*(int *)(puVar2 + 8) == 0x80) {
      *(undefined4 *)(puVar2 + 8) = 0;
    }
  }
  if (-1 < (int)(uVar8 << 0x19)) goto LAB_0003bd7a;
  iVar4 = FUN_00028c48();
  iVar6 = DAT_0003bd10;
  if (iVar4 == 1) {
    if (*(char *)(DAT_0003bd10 + 0x28) == '\x01') {
      if (*(byte *)(DAT_0003bd10 + 0x2b) + 4 == *(int *)(puVar2 + 8)) {
        cVar1 = *(char *)(DAT_0003bd10 + 0x29);
        if ((cVar1 == -0x20) || (*(char *)(DAT_0003bd10 + 0x2a) == -4)) {
          if ((puVar2[1] != '\x01') ||
             ((((cVar1 != -0x20 || (*(char *)(DAT_0003bd10 + 0x2a) != -4)) ||
               (*(byte *)(DAT_0003bd10 + 0x2b) != 2)) ||
              ((*(char *)(DAT_0003bd10 + 0x2c) != '\x0e' ||
               (*(char *)(DAT_0003bd10 + 0x2d) != -0x60)))))) goto LAB_0003bc5e;
          uVar3 = FUN_00042450(DAT_0003bd0c + 0x33);
          FUN_0003b8e0(DAT_0003bd0c + 0x33,uVar3);
        }
        else {
          if ((cVar1 == '\x1e') && (puVar2[1] == '\x01')) {
            puVar7 = (undefined1 *)(DAT_0003bd10 + 0xa8);
            *puVar7 = 0x73;
            *(undefined1 *)(iVar6 + 0xa9) = 0x65;
            *(undefined1 *)(iVar6 + 0xaa) = 0x74;
            *(undefined1 *)(iVar6 + 0xab) = 0x20;
            *(undefined1 *)(iVar6 + 0xac) = 0x70;
            *(undefined1 *)(iVar6 + 0xad) = 0x77;
            *(undefined1 *)(iVar6 + 0xae) = 0x72;
            *(undefined1 *)(iVar6 + 0xaf) = 0x3a;
            *(undefined1 *)(iVar6 + 0xb0) = 0x39;
            *(undefined1 *)(iVar6 + 0xb1) = 0x20;
            *(undefined1 *)(iVar6 + 0xb2) = 0x2d;
            *(undefined1 *)(iVar6 + 0xb3) = 0x20;
            *(undefined1 *)(iVar6 + 0xb4) = 99;
            *(undefined1 *)(iVar6 + 0xb5) = 0x3a;
            FUN_0003ba46(iVar6 + 0xb6,iVar6 + 0x2c,1,0x2d,param_2,param_3,param_4);
            *(undefined1 *)(iVar6 + 0xb8) = 0xd;
            *(undefined1 *)(iVar6 + 0xb9) = 10;
            FUN_0003b8e0(puVar7,0x12);
          }
          FUN_0003ba6e(DAT_0003bd10 + 0x28,*(uint *)(puVar2 + 8) & 0xffff);
        }
        goto LAB_0003bc4e;
      }
LAB_0003bc5e:
      uVar5 = FUN_00042450(DAT_0003bd0c + 0xc);
      iVar6 = rom_25002(DAT_0003bd10 + 0x28,DAT_0003bd0c + 0xc,uVar5);
      if (iVar6 == 0) {
        func_0x0003ba08(0x3bd34,*_LAB_0003bd30,_LAB_0003bd30[1],_LAB_0003bd30[2],_LAB_0003bd30[3],
                        _LAB_0003bd30[4],_LAB_0003bd30[5]);
        func_0x0003ba08(0x3bd24);
        *(undefined4 *)(puVar2 + 8) = 0;
      }
      else {
        uVar5 = FUN_00042450(DAT_0003bd0c + 0x19);
        iVar6 = rom_25002(DAT_0003bd10 + 0x28,DAT_0003bd0c + 0x19,uVar5);
        if (iVar6 == 0) {
          uVar3 = FUN_00042450(DAT_0003bea4);
          FUN_0003b8e0(DAT_0003bea4,uVar3);
          *(undefined4 *)(puVar2 + 8) = 0;
          goto LAB_0003bd6e;
        }
        uVar5 = FUN_00042450(DAT_0003bd0c + 0x42);
        iVar6 = rom_25002(DAT_0003bd10 + 0x28,DAT_0003bd0c + 0x42,uVar5);
        if (iVar6 == 0) {
          FUN_0003b538(0x10);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uVar5 = FUN_00042450(DAT_0003bd0c + 0x4b);
        iVar6 = rom_25002(DAT_0003bd10 + 0x28,DAT_0003bd0c + 0x4b,uVar5);
        if (iVar6 == 0) {
          FUN_0003b538(0x10);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
    }
    else {
LAB_0003bc4e:
      if ((*(char *)(DAT_0003bd10 + 0x28) != '\r') || (*(char *)(DAT_0003bd10 + 0x29) != '\n'))
      goto LAB_0003bc5e;
      func_0x0003ba08(0x3bd24);
LAB_0003bd6e:
      puVar2[1] = 1;
    }
  }
  *(undefined4 *)(puVar2 + 8) = 0;
  *puVar2 = 1;
LAB_0003bd7a:
  *(uint *)(DAT_0003bea8 + 0x14) = uVar8;
  return;
}

/* ==========================================================================
 * FUN_0003bd90   @ 0x0003bd90   (58 bytes)
 * calls     : FUN_0003b8e0, rom_24F9C
 */

void FUN_0003bd90(undefined4 param_1,int param_2)

{
  undefined1 uStack_28;
  undefined1 uStack_27;
  char cStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  char cStack_22;
  undefined1 auStack_21 [25];
  
  uStack_28 = 4;
  uStack_27 = 0xe;
  cStack_22 = (char)param_2;
  cStack_26 = cStack_22 + '\x04';
  uStack_25 = 1;
  uStack_24 = 0xe0;
  uStack_23 = 0xfc;
  rom_24F9C(auStack_21,param_1,param_2);
  FUN_0003b8e0(&uStack_28,param_2 + 7);
  return;
}

/* ==========================================================================
 * FUN_0003bdca   @ 0x0003bdca   (28 bytes)
 * called by : FUN_0003bde6
 * calls     : FUN_0003b904
 */

void FUN_0003bdca(void)

{
  if (*DAT_0003beac != 0) {
    (*(code *)*DAT_0003beac)(DAT_0003beac + 1,DAT_0003beac[0x11] & 0xffff);
  }
  FUN_0003b904(2);
  return;
}

/* ==========================================================================
 * FUN_0003bde6   @ 0x0003bde6   (178 bytes)
 * called by : FUN_00028c4e
 * calls     : FUN_0003b904, FUN_0003bdca, rom_24F9C
 */

void FUN_0003bde6(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  
  puVar1 = DAT_0003beb0;
  uVar3 = 0;
  while (*(char *)(puVar1 + 9) == '\x01') {
    pcVar4 = (code *)*puVar1;
    uVar2 = puVar1[1];
    *(undefined1 *)(puVar1 + 9) = 0;
    rom_24F9C(DAT_0003beac + uVar3 + 4,puVar1[5],puVar1[7]);
    uVar3 = puVar1[7] + uVar3 & 0xffff;
    *(int *)(DAT_0003beac + 0x44) = *(int *)(DAT_0003beac + 0x44) + puVar1[7];
    if (pcVar4 != (code *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      (*pcVar4)(uVar2,0);
    }
  }
  if (*(int *)(DAT_0003beac + 0x44) != 0) {
    FUN_0003bdca();
  }
  uVar3 = 0;
  if (*(int *)(DAT_0003beac + -4) == 0) {
    return;
  }
  do {
    if (*(char *)((int)puVar1 + 0x25) != '\x01') break;
    pcVar4 = (code *)puVar1[2];
    uVar2 = puVar1[3];
    *(undefined1 *)((int)puVar1 + 0x25) = 0;
    rom_24F9C(puVar1[6],DAT_0003beac + uVar3 + -0x44,puVar1[8]);
    uVar3 = puVar1[8] + uVar3 & 0xffff;
    if (pcVar4 != (code *)0x0) {
      puVar1[2] = 0;
      puVar1[3] = 0;
      (*pcVar4)(uVar2,0);
    }
  } while (uVar3 < *(uint *)(DAT_0003beac + -4));
  FUN_0003b904(1);
  return;
}

/* ==========================================================================
 * FUN_0003be98   @ 0x0003be98   (12 bytes)
 * called by : FUN_0003b8e0, FUN_0003ba28
 */

void FUN_0003be98(undefined4 param_1)

{
  do {
  } while (-1 < *(int *)(DAT_0003bea8 + 8) << 0xb);
  *(undefined4 *)(DAT_0003bea8 + 0xc) = param_1;
  return;
}

/* ==========================================================================
 * FUN_0003bf40   @ 0x0003bf40   (88 bytes)
 * called by : FUN_0003c008
 * calls     : FUN_00035800
 */

void FUN_0003bf40(void)

{
  *DAT_0003bf98 = *DAT_0003bf98 | 0x20;
  if ((((*DAT_0003bf9c != '\x01') && (*DAT_0003bf9c != '\x02')) || (*DAT_0003bfa0 != '\0')) ||
     (*DAT_0003bfa0 != '\0')) {
    if (*DAT_0003bfac == 0) {
      if ((*DAT_0003bfb0 == '\0') && (*DAT_0003bfa0 == '\0')) {
        *DAT_0003bfb4 = 3;
      }
    }
    else {
      *DAT_0003bfac = *DAT_0003bfac + -1;
    }
    *DAT_0003bfb8 = 1;
    *DAT_0003bfbc = 1;
    FUN_00035800();
  }
  return;
}

/* ==========================================================================
 * FUN_0003bfc2   @ 0x0003bfc2   (70 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void FUN_0003bfc2(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0003c0dc;
  *DAT_0003c0dc = 0;
  puVar1[1] = 0;
  *puVar1 = *puVar1 & 0xfffffffb;
  *puVar1 = *puVar1 | (int)puVar1 << 0xe;
  *puVar1 = *puVar1 | (int)puVar1 << 0x10;
  *puVar1 = *puVar1 | (int)puVar1 << 0xf;
  puVar1[1] = puVar1[1] | (int)puVar1 << 0xe;
  puVar1[1] = puVar1[1] | (int)puVar1 << 0x10;
  puVar1[1] = puVar1[1] | (int)puVar1 << 0xf;
  *puVar1 = *puVar1 | (int)puVar1 << 0xc;
  return;
}

/* ==========================================================================
 * FUN_0003c008   @ 0x0003c008   (160 bytes)
 * called by : FUN_00028ac0
 * calls     : FUN_000375fe, FUN_00039bcc, FUN_00039c02, FUN_0003aad4, FUN_0003af2c, FUN_0003b47e, ... (+5 more)
 */

void FUN_0003c008(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (*DAT_0003c0e0 == '\0') {
    FUN_0003b47e();
  }
  else {
    FUN_0003af2c();
  }
  iVar1 = DAT_0003c0dc;
  uVar3 = *(uint *)(DAT_0003c0dc + 8);
  FUN_00039c02(0x13);
  if ((int)(uVar3 << 0x1d) < 0) {
    uVar2 = 4;
    FUN_0003c438();
  }
  if ((int)(uVar3 << 0x1c) < 0) {
    uVar2 = uVar2 | 8;
    FUN_0003c48c();
  }
  if ((int)(uVar3 << 0x1a) < 0) {
    uVar2 = uVar2 | 0x20;
    uart2_isr();
  }
  if ((int)(uVar3 << 0x17) < 0) {
    uVar2 = uVar2 | 0x100;
    FUN_0003b5e6();
  }
  if ((int)(uVar3 << 0x13) < 0) {
    uVar2 = uVar2 | 0x1000;
    FUN_0003bf40();
  }
  if ((int)(uVar3 << 0x16) < 0) {
    uVar2 = uVar2 | 0x200;
    FUN_00039bcc();
  }
  if ((int)(uVar3 << 0x19) < 0) {
    uVar2 = uVar2 | 0x40;
    FUN_0003aad4();
  }
  if ((uVar3 & 1) != 0) {
    uVar2 = uVar2 | 1;
  }
  if ((int)(uVar3 << 0x1e) < 0) {
    uVar2 = uVar2 | 2;
  }
  if ((int)(uVar3 << 0xe) < 0) {
    uVar2 = uVar2 | 0x20000;
    FUN_000375fe();
  }
  *(uint *)(iVar1 + 8) = uVar2;
  FUN_00039c02(0x14);
  return;
}

/* ==========================================================================
 * FUN_0003c438   @ 0x0003c438   (84 bytes)
 * called by : FUN_0003c008
 */

void FUN_0003c438(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_0003c4e4;
  pbVar1 = DAT_0003c4e0;
  iVar3 = DAT_0003c4e4[3];
  if (iVar3 << 0x18 < 0) {
    *DAT_0003c4e0 = *DAT_0003c4e0 | 1;
    *puVar2 = *(undefined4 *)(pbVar1 + 0x1c);
    if (*(code **)(pbVar1 + 4) != (code *)0x0) {
      (**(code **)(pbVar1 + 4))();
    }
  }
  if (iVar3 << 0x17 < 0) {
    *pbVar1 = *pbVar1 | 2;
    puVar2[1] = *(undefined4 *)(pbVar1 + 0x20);
    if (*(code **)(pbVar1 + 8) != (code *)0x0) {
      (**(code **)(pbVar1 + 8))();
    }
  }
  if (iVar3 << 0x16 < 0) {
    *pbVar1 = *pbVar1 | 4;
    puVar2[2] = *(undefined4 *)(pbVar1 + 0x2c);
    if (*(code **)(pbVar1 + 0xc) != (code *)0x0) {
      (**(code **)(pbVar1 + 0xc))();
    }
  }
  puVar2[3] = iVar3;
  return;
}

/* ==========================================================================
 * FUN_0003c48c   @ 0x0003c48c   (84 bytes)
 * called by : FUN_0003c008
 */

void FUN_0003c48c(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_0003c4e8;
  pbVar1 = DAT_0003c4e0;
  iVar3 = DAT_0003c4e8[3];
  if (iVar3 << 0x18 < 0) {
    *DAT_0003c4e0 = *DAT_0003c4e0 | 0x10;
    *puVar2 = *(undefined4 *)(pbVar1 + 0x24);
    if (*(code **)(pbVar1 + 0x10) != (code *)0x0) {
      (**(code **)(pbVar1 + 0x10))();
    }
  }
  if (iVar3 << 0x17 < 0) {
    *pbVar1 = *pbVar1 | 0x20;
    puVar2[1] = *(undefined4 *)(pbVar1 + 0x28);
    if (*(code **)(pbVar1 + 0x14) != (code *)0x0) {
      (**(code **)(pbVar1 + 0x14))();
    }
  }
  if (iVar3 << 0x16 < 0) {
    *pbVar1 = *pbVar1 | 0x40;
    puVar2[2] = *(undefined4 *)(pbVar1 + 0x30);
    if (*(code **)(pbVar1 + 0x18) != (code *)0x0) {
      (**(code **)(pbVar1 + 0x18))();
    }
  }
  puVar2[3] = iVar3;
  return;
}

/* ==========================================================================
 * FUN_0003c52e   @ 0x0003c52e   (6 bytes)
 * called by : FUN_0002f31c
 */

void FUN_0003c52e(undefined4 param_1)

{
  *(undefined4 *)(DAT_0003c804 + 0x10) = param_1;
  return;
}

/* ==========================================================================
 * FUN_0003c574   @ 0x0003c574   (6 bytes)
 * called by : FUN_0002f31c
 */

undefined4 FUN_0003c574(void)

{
  return *(undefined4 *)(DAT_0003c804 + 0x10);
}

/* ==========================================================================
 * FUN_0003c6ce   @ 0x0003c6ce   (106 bytes)
 * called by : FUN_0002f31c
 * calls     : rom_1804C, rom_24F24
 */

void FUN_0003c6ce(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint local_18;
  undefined4 uStack_14;
  
  iVar5 = 0;
  local_18 = param_3;
  uStack_14 = param_4;
  rom_1804C(&local_18);
  iVar2 = DAT_0003c810;
  puVar1 = DAT_0003c804;
  uVar4 = local_18 >> 1;
  uVar3 = *DAT_0003c804;
  if (uVar4 != uVar3) {
    if (uVar3 < uVar4) {
      uVar3 = uVar4 - uVar3;
    }
    else {
      uVar3 = (uVar4 - uVar3) + DAT_0003c80c;
    }
    *DAT_0003c804 = uVar4;
    for (; (uint)-iVar2 < uVar3; uVar3 = uVar3 + iVar2) {
      iVar5 = iVar5 + DAT_0003c814;
    }
    uVar3 = uVar3 * 5 + puVar1[1];
    iVar5 = (uVar3 >> 3) + iVar5;
    puVar1[1] = uVar3 & 7;
    if (iVar5 != 0) {
      uVar3 = iVar5 * 100 + puVar1[2];
      puVar1[2] = uVar3;
      if (puVar1[5] <= uVar3) {
        uVar6 = rom_24F24();
        puVar1[2] = (uint)((ulonglong)uVar6 >> 0x20);
        puVar1[4] = (int)uVar6 + puVar1[4];
      }
    }
  }
  return;
}

/* ==========================================================================
 * CHRG   @ 0x0003cfb8   (46 bytes)
 * called by : FUN_0003d2b0, LightUp_Mode_Led, Success_led_2second_2, f_usb_isConnected
 * string    : "Link OK! "
 * string    : "CHRG     "
 * string    : "Pair OK! "
 * string    : "Conn OK! "
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void CHRG(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if (*DAT_0003d0bc == '\0') {
    cVar1 = *DAT_0003d0c8;
    if (cVar1 == '\0') {
      pcVar2 = str_Pair_OK;
    }
    else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
      pcVar2 = str_Conn_OK;
    }
    else {
      pcVar2 = str_CHRG;
    }
  }
  else {
    pcVar2 = str_Link_OK;
  }
  cVar1 = '\x01';
  bVar3 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  for (uVar4 = 0; pcVar2[uVar4] != '\0'; uVar4 = uVar4 + 1 & 0xff) {
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(bVar3,cVar1,1);
    }
    else {
      FUN_0003cb9a(bVar3,cVar1,1);
    }
    bVar3 = bVar3 + 8;
    if (0x70 < bVar3) {
      bVar3 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *DAT_0003d0b8 = '\0';
  return;
}

/* ==========================================================================
 * ReLink   @ 0x0003cfe6   (38 bytes)
 * called by : FUN_0003d2b0, Success_led_2second_2, f_reconnect_24G
 * string    : "ReLink OK"
 * string    : "CHRG   "
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void ReLink(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if ((((*DAT_0003d0bc == '\0') && (cVar1 = *DAT_0003d0c8, cVar1 != '\0')) && (cVar1 != '\x01')) &&
     (cVar1 != '\x02')) {
    pcVar2 = str_CHRG_2;
  }
  else {
    pcVar2 = str_ReLink_OK;
  }
  cVar1 = '\x01';
  bVar3 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  for (uVar4 = 0; pcVar2[uVar4] != '\0'; uVar4 = uVar4 + 1 & 0xff) {
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(bVar3,cVar1,1);
    }
    else {
      FUN_0003cb9a(bVar3,cVar1,1);
    }
    bVar3 = bVar3 + 8;
    if (0x70 < bVar3) {
      bVar3 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *DAT_0003d0b8 = '\0';
  return;
}

/* ==========================================================================
 * ReLinking   @ 0x0003d00c   (38 bytes)
 * called by : FUN_00032942, FUN_0003d2b0, set_Update_OLED_2
 * string    : "ReLinking"
 * string    : "CHRG     "
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void ReLinking(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if ((((*DAT_0003d0bc == '\0') && (cVar1 = *DAT_0003d0c8, cVar1 != '\0')) && (cVar1 != '\x01')) &&
     (cVar1 != '\x02')) {
    pcVar2 = str_CHRG;
  }
  else {
    pcVar2 = str_ReLinking;
  }
  cVar1 = '\x01';
  bVar3 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  for (uVar4 = 0; pcVar2[uVar4] != '\0'; uVar4 = uVar4 + 1 & 0xff) {
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(bVar3,cVar1,1);
    }
    else {
      FUN_0003cb9a(bVar3,cVar1,1);
    }
    bVar3 = bVar3 + 8;
    if (0x70 < bVar3) {
      bVar3 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *DAT_0003d0b8 = '\0';
  return;
}

/* ==========================================================================
 * Pairing   @ 0x0003d032   (48 bytes)
 * called by : FUN_00032942, FUN_0003d2b0, set_Update_OLED_2
 * calls     : FUN_0003cd24
 * string    : "CHRG     "
 * string    : "Pairing  "
 * string    : "Linking  "
 */

void Pairing(void)

{
  char cVar1;
  char *pcVar2;
  
  if (*DAT_0003d0bc == '\0') {
    cVar1 = *DAT_0003d0c8;
    if (cVar1 == '\0') {
      pcVar2 = str_Pairing;
      goto LAB_0003d052;
    }
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      pcVar2 = str_CHRG;
      goto LAB_0003d052;
    }
  }
  pcVar2 = str_Linking;
LAB_0003d052:
  FUN_0003cd24(0,1,1,pcVar2);
  return;
}

/* ==========================================================================
 * Linking   @ 0x0003d5be   (30 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_0003cd24
 * string    : "Linking  "
 */

void Linking(void)

{
  FUN_0003cd24(0x48,1,2,PTR_DAT_0003d6c8 + -0xc);
  FUN_0003cd24(0,1,1,DAT_0003d6d4);
  return;
}

/* ==========================================================================
 * FUN_0003dc3c   @ 0x0003dc3c   (66 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 * calls     : rom_074A0, rom_07806, rom_0C1CA, rom_1169A, rom_1804C, rom_24F8A
 */

void FUN_0003dc3c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int local_10;
  int local_c;
  
  local_10 = param_3;
  local_c = param_4;
  if (param_1 == 0) {
    rom_1804C(&local_10);
    rom_24F8A(local_c + local_10);
  }
  rom_074A0(param_1);
  rom_0C1CA(param_1);
  rom_07806(param_1);
  rom_1169A(param_1);
  if (param_1 != 0) {
    *DAT_0003dccc = *DAT_0003dccc & 0xfffffeff | 0x100;
  }
  return;
}

/* ==========================================================================
 * FUN_0003dcb0   @ 0x0003dcb0   (18 bytes)
 * called by : FUN_0003e304
 */

void FUN_0003dcb0(void)

{
  int iVar1;
  
  iVar1 = DAT_0003dccc;
  *DAT_0003dcf4 = *(undefined4 *)(DAT_0003dccc + 0xc);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
  return;
}

/* ==========================================================================
 * FUN_0003dcf8   @ 0x0003dcf8   (8 bytes)
 * called by : FUN_0003e304
 */

int FUN_0003dcf8(int param_1)

{
  return param_1 * 10 + -1;
}

/* ==========================================================================
 * FUN_0003dd8e   @ 0x0003dd8e   (350 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 * calls     : FUN_0003e432, rom_06B14, rom_18074
 */

/* WARNING: Removing unreachable block (ram,0x0003dee4) */
/* WARNING: Removing unreachable block (ram,0x0003ddde) */

void FUN_0003dd8e(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 local_40 [6];
  ushort local_34 [4];
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined1 local_24 [8];
  ushort local_1c [4];
  
  local_28 = 0;
  if (param_1 == 0) {
    rom_06B14(1,DAT_0003e108);
  }
  puVar1 = DAT_0003e100;
  *(undefined2 *)((int)DAT_0003e100 + 0x16) = 0;
  puVar1[2] = 0xffffffff;
  *puVar1 = 0xffffffff;
  puVar1[1] = 0xffffffff;
  puVar1 = DAT_0003e110;
  if (param_1 != 0) {
    do {
    } while( true );
  }
  local_2c[0] = 1;
  DAT_00820018 = DAT_0003e10c;
  local_28 = 1;
  (*(code *)*DAT_0003e110)(0x12,local_2c,local_24);
  puVar2 = DAT_0003e100;
  local_24[0] = 1;
  *(undefined1 *)(DAT_0003e100 + 6) = 1;
  local_2c[0] = 2;
  iVar3 = (*(code *)*puVar1)(0x2e,local_2c,puVar2 + 5);
  if (iVar3 != 0) {
    *(undefined2 *)(puVar2 + 5) = 400;
  }
  puVar2[3] = 0;
  local_2c[0] = 2;
  iVar3 = (*(code *)*puVar1)(0xf,local_2c,local_34);
  if (iVar3 != 0) {
    local_34[0] = (ushort)DAT_0003e114;
  }
  local_2c[0] = 2;
  iVar3 = (*(code *)*puVar1)(0xe,local_2c,local_1c);
  if (iVar3 != 0) {
    local_1c[0] = 2000;
  }
  local_2c[0] = 2;
  iVar3 = (*(code *)*puVar1)(0xd,local_2c,local_40);
  if (iVar3 != 0) {
    local_40[0] = (undefined2)DAT_0003e114;
  }
  local_34[0] = FUN_0003e432(local_34[0]);
  local_1c[0] = FUN_0003e432(local_1c[0]);
  uVar4 = FUN_0003e432(local_40[0]);
  uVar5 = uVar4 & 0xffff;
  uVar6 = (uint)local_1c[0];
  DAT_0082003c = uVar4 << 0x15 | uVar6 << 10 | uVar5;
  if (uVar5 <= local_34[0]) {
    uVar5 = (uint)local_34[0];
  }
  if (uVar6 < uVar5) {
    uVar6 = uVar5;
  }
  puVar2[4] = uVar6;
  DAT_00820030 = DAT_00820030 & 0x7fffffff | (uint)(*(char *)(puVar2 + 6) == '\0') << 0x1f;
  return;
}

/* ==========================================================================
 * rwip_driver_init   @ 0x0003deee   (228 bytes)
 * called by : TEST_SINGLE_WAVE_2, enter_BLE_normal_app_mode
 * calls     : FUN_00028c48, FUN_00029164, FUN_00029530, FUN_0003a244, FUN_0003dc3c, FUN_0003dd8e, ... (+14 more)
 * string    : "h4tl_init-1 ok\r\n"
 * string    : "hci_init ok\r\n"
 * string    : "rwble_hl_init ok\r\n"
 * string    : "rwble_init ok\r\n"
 * string    : "aes_init ok\r\n"
 * string    : "rwip_driver_init ok\r\n"
 * string    : "appm_init ok\r\n"
 */

void rwip_driver_init(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  DAT_0080000c = DAT_0080000c & 0xfffdffff;
  *(undefined1 *)(DAT_0003e118 + 1) = 0;
  puVar1 = DAT_0003e110;
  *DAT_0003e110 = DAT_0003e11c;
  puVar1[1] = DAT_0003e120;
  puVar1[2] = DAT_0003e124;
  rom_06A88();
  rom_06BF8(0,DAT_0003e128,0x314);
  rom_06BF8(1,DAT_0003e130,DAT_0003e12c);
  rom_06BF8(2,DAT_0003e138,DAT_0003e134);
  rom_06BF8(3,DAT_0003e13c,0x29c);
  FUN_0003a244(DAT_0003e140);
  rom_0626C(0);
  uVar2 = FUN_00029164(0);
  rom_0692C(0,uVar2);
  dbg_printf(str_h4tl_init_1_ok);
  rom_1477C(0);
  dbg_printf(str_hci_init_ok);
  rom_24F08(0);
  dbg_printf(str_rwble_hl_init_ok);
  FUN_0003dc3c(0);
  dbg_printf(str_rwble_init_ok);
  rom_16CAC(0);
  dbg_printf(str_aes_init_ok);
  rom_15F90(0);
  rom_16930(0);
  rom_16508(0);
  rom_15C36(0);
  rom_16BCE(0);
  FUN_0003dd8e(0);
  dbg_printf(str_rwip_driver_init_ok);
  iVar3 = FUN_00028c48();
  if (iVar3 == 0) {
    FUN_00029530();
    dbg_printf(str_appm_init_ok);
  }
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * FUN_0003dfd2   @ 0x0003dfd2   (108 bytes)
 * calls     : FUN_0003dc3c, FUN_0003dd8e, rom_0626C, rom_06AB4, rom_1477C, rom_15C36, ... (+10 more)
 */

void FUN_0003dfd2(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = rom_25024();
  iVar2 = rom_25038();
  rom_06AB4();
  rom_0626C(1);
  rom_1477C(1);
  rom_24F08(1);
  FUN_0003dc3c(1);
  rom_16CAC(1);
  rom_15F90(1);
  rom_16930(1);
  rom_16508(1);
  rom_15C36(1);
  rom_16BCE(1);
  FUN_0003dd8e(1);
  (*(code *)*DAT_0003e140)();
  if (iVar1 == 0) {
    rom_2504C();
  }
  if (iVar2 == 0) {
    rom_2505C();
  }
  return;
}

/* ==========================================================================
 * FUN_0003e03e   @ 0x0003e03e   (16 bytes)
 * called by : FUN_00028c4e, FUN_00028c66
 * calls     : rom_06BCE
 */

void FUN_0003e03e(void)

{
  if ((*(byte *)(DAT_0003e100 + 0x16) & 1) == 0) {
    rom_06BCE();
  }
  return;
}

/* ==========================================================================
 * FUN_0003e268   @ 0x0003e268   (44 bytes)
 * called by : FUN_0003e304
 * calls     : rom_1804C
 */

undefined4 FUN_0003e268(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint local_10;
  undefined4 uStack_c;
  
  local_10 = param_3;
  uStack_c = param_4;
  rom_1804C(&local_10);
  uVar1 = *(uint *)(DAT_0003e448 + 4);
  if (uVar1 < local_10) {
    if (&DAT_00004b00 < (undefined *)(local_10 - uVar1)) {
      *(uint *)(DAT_0003e448 + 4) = local_10;
      return 1;
    }
  }
  else if (local_10 < uVar1) {
    *(uint *)(DAT_0003e448 + 4) = local_10;
  }
  return 0;
}

/* ==========================================================================
 * RC32K   @ 0x0003e294   (24 bytes)
 * called by : FUN_0003e304
 * calls     : FUN_0003a688, dbg_printf
 * string    : "RC32K-Cali.Start\n"
 */

void RC32K(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0003e448;
  *DAT_0003e448 = 1;
  dbg_printf(str_RC32K_Cali_Start);
  FUN_0003a688();
  *puVar1 = 2;
  return;
}

/* ==========================================================================
 * FUN_0003e304   @ 0x0003e304   (300 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_0003dcb0, FUN_0003dcf8, FUN_0003e268, RC32K, RC32K_2, rom_069DC, ... (+3 more)
 */

undefined8 FUN_0003e304(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int local_20;
  int local_1c;
  undefined4 uStack_18;
  
  piVar2 = DAT_0003e444;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  if (((*(byte *)((int)DAT_0003e444 + 0x16) & 1) == 0) && (iVar3 = rom_06AF0(), iVar3 == 0)) {
LAB_0003e3e6:
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
    uVar1 = (ushort)DAT_0003e484;
    if ((int)((uint)*(ushort *)((int)piVar2 + 0x16) << 0x12) < 0) {
      iVar3 = RC32K_2();
      if (iVar3 != 0) {
        *(ushort *)((int)piVar2 + 0x16) = *(ushort *)((int)piVar2 + 0x16) & ~uVar1;
        goto LAB_0003e330;
      }
    }
    else {
LAB_0003e330:
      if (*(short *)((int)piVar2 + 0x16) != 0) goto LAB_0003e42e;
      rom_1804C(&local_20);
      uVar4 = local_20 + 1;
      if (0x270U - local_1c < (uint)*(ushort *)(piVar2 + 5)) {
        uVar4 = local_20 + 2;
      }
      uVar4 = uVar4 & 0xfffffff;
      uVar5 = DAT_0003e488;
      if ((char)piVar2[6] == '\0') {
        uVar5 = 0x12c0;
      }
      iVar3 = piVar2[2];
      if (iVar3 != -1) {
        uVar6 = iVar3 - uVar4 & 0xfffffff;
        if (DAT_0003e48c < uVar6) {
          uVar6 = -(uVar4 - iVar3 & 0xfffffff);
        }
        if ((int)uVar6 <= (int)uVar5) {
          uVar5 = uVar6;
        }
      }
      iVar3 = *piVar2;
      if (iVar3 != -1) {
        uVar6 = iVar3 - uVar4 & 0xfffffff;
        if (DAT_0003e48c < uVar6) {
          uVar6 = -(uVar4 - iVar3 & 0xfffffff);
        }
        if ((int)uVar6 <= (int)uVar5) {
          uVar5 = uVar6;
        }
      }
      iVar3 = piVar2[1];
      if (iVar3 != -1) {
        uVar6 = iVar3 - uVar4 & 0xfffffff;
        if (DAT_0003e48c < uVar6) {
          uVar6 = -(uVar4 - iVar3 & 0xfffffff);
        }
        if ((int)uVar6 <= (int)uVar5) {
          uVar5 = uVar6;
        }
      }
      if (((int)uVar5 < 9) ||
         (uVar4 = FUN_0003dcf8(uVar5 - 8),
         uVar4 <= (uint)(piVar2[4] * 2) && piVar2[4] * 2 - uVar4 != 0)) goto LAB_0003e42e;
      iVar3 = FUN_0003e268();
      if (iVar3 != 0) {
        *(ushort *)((int)piVar2 + 0x16) = *(ushort *)((int)piVar2 + 0x16) | uVar1;
        RC32K();
        goto LAB_0003e3e6;
      }
      iVar3 = rom_069DC();
      if (iVar3 != 0) {
        uVar7 = 2;
        FUN_0003dcb0();
        DAT_00820018 = 2;
        DAT_00820020 = 0xffffffff;
        if ((char)piVar2[6] == '\0') {
          DAT_00820030 = DAT_00820030 & 0x7fffffff | 0x80000000;
        }
        DAT_00820034 = uVar4;
        (**(code **)(DAT_0003e490 + 0x28))();
        rom_18074(0x1000);
        goto LAB_0003e42e;
      }
    }
    uVar7 = 0;
  }
LAB_0003e42e:
  return CONCAT44(local_20,uVar7);
}

/* ==========================================================================
 * FUN_0003e432   @ 0x0003e432   (16 bytes)
 * called by : FUN_0003dd8e
 * calls     : rom_24F24
 */

void FUN_0003e432(int param_1)

{
  rom_24F24(param_1 * 0x20 + DAT_0003e494,DAT_0003e494 + 1);
  return;
}

/* ==========================================================================
 * FUN_0003e498   @ 0x0003e498   (58 bytes)
 * called by : FUN_0003e5f0, FUN_0003e6e2, FUN_0003e732
 */

undefined8 FUN_0003e498(int param_1,char *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = DAT_0003e794;
  uVar3 = 0;
  iVar4 = param_1;
  (*(code *)*DAT_0003e794)(param_1,3,param_2,(code *)*DAT_0003e794,param_1,param_2);
  if (*param_2 == -1) {
    uVar3 = 2;
  }
  else {
    iVar2 = (uint)(byte)param_2[2] + param_1 + 3;
    *param_3 = iVar2;
    if (puVar1[4] - 1 < iVar2 - 0x7f000U) {
      uVar3 = 6;
    }
  }
  return CONCAT44(iVar4,uVar3);
}

/* ==========================================================================
 * FUN_0003e516   @ 0x0003e516   (60 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_0003e4d2, FUN_0003e716, rom_25002
 */

undefined4 FUN_0003e516(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r3;
  undefined4 uStack_10;
  
  uVar2 = DAT_0003e798;
  puVar1 = DAT_0003e794;
  DAT_0003e794[3] = 0;
  *puVar1 = uVar2;
  puVar1[1] = DAT_0003e79c;
  puVar1[2] = DAT_0003e7a0;
  puVar1[4] = 0x438;
  uStack_10 = in_r3;
  FUN_0003e4d2(0x7f000,4,&uStack_10);
  iVar3 = rom_25002(&uStack_10,DAT_0003e7a4,4);
  if (iVar3 != 0) {
    FUN_0003e716();
  }
  return 0;
}

/* ==========================================================================
 * FUN_0003e552   @ 0x0003e552   (62 bytes)
 * called by : FUN_00029988, FUN_00029a04, FUN_0002a0c0, FUN_0002c378, FUN_0002d53c, FUN_00039cfc, ... (+9 more)
 * calls     : FUN_0003e6e2
 */

int FUN_0003e552(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  int local_28 [3];
  undefined1 auStack_1c [2];
  byte local_1a;
  
  iVar1 = FUN_0003e6e2(param_1,auStack_1c,local_28);
  if (iVar1 == 0) {
    if (*param_2 < local_1a) {
      return 4;
    }
    (*(code *)*DAT_0003e794)(local_28[0] + 3,local_1a,param_3);
  }
  else {
    local_1a = 0;
  }
  *param_2 = local_1a;
  return iVar1;
}

/* ==========================================================================
 * FUN_0003e590   @ 0x0003e590   (52 bytes)
 * calls     : FUN_0003e6e2
 */

undefined8 FUN_0003e590(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uStack_18;
  int local_14;
  uint local_10;
  
  uStack_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  iVar1 = FUN_0003e6e2(param_1,&uStack_18,&local_14);
  if (iVar1 == 0) {
    if ((int)((uint)uStack_18._1_1_ << 0x1e) < 0) {
      local_10 = CONCAT31(local_10._1_3_,uStack_18._1_1_) & 0xfffffffb;
      (**(code **)(DAT_0003e794 + 4))(local_14 + 1,1,&local_10);
    }
    else {
      iVar1 = 5;
    }
  }
  return CONCAT44(uStack_18,iVar1);
}

/* ==========================================================================
 * FUN_0003e5c4   @ 0x0003e5c4   (44 bytes)
 * calls     : FUN_0003e6e2
 */

undefined8 FUN_0003e5c4(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  
  uStack_18 = param_2;
  iStack_14 = param_3;
  uStack_10 = param_4;
  iVar1 = FUN_0003e6e2(param_1,&uStack_18,&iStack_14);
  if (iVar1 == 0) {
    uStack_10 = CONCAT31(uStack_10._1_3_,uStack_18._1_1_) & 0xfffffffd;
    (**(code **)(DAT_0003e794 + 4))(iStack_14 + 1,1,&uStack_10);
  }
  return CONCAT44(uStack_18,iVar1);
}

/* ==========================================================================
 * FUN_0003e5f0   @ 0x0003e5f0   (242 bytes)
 * called by : FUN_00029ab0, FUN_00029ed8, FUN_00029ef2, FUN_0002a0aa, FUN_0002b8a2, FUN_0002d53c, ... (+7 more)
 * calls     : FUN_0003e498, FUN_0003e732, KEY_piaring_cnt, rom_25002
 */

undefined4 FUN_0003e5f0(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_568;
  byte local_567;
  byte local_566;
  int local_564;
  byte local_560 [4];
  undefined1 auStack_55c [60];
  uint auStack_520 [255];
  undefined1 auStack_124 [260];
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  
  puVar1 = DAT_0003e794;
  iVar4 = 0;
  local_564 = DAT_0003e7a8;
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  while( true ) {
    while( true ) {
      do {
        KEY_piaring_cnt();
        iVar3 = local_564;
        iVar2 = FUN_0003e498(local_564,&local_568,&local_564);
        if (iVar2 != 0) {
          if (puVar1[4] - 1 < iVar3 + param_2 + DAT_0003e7ac) {
            FUN_0003e732(iVar4,auStack_55c);
            iVar3 = iVar4 + DAT_0003e7a8;
            if (puVar1[4] - 1 < iVar3 + param_2 + DAT_0003e7ac + -3) {
              return 3;
            }
          }
          (*(code *)puVar1[1])
                    (iVar3 + 3,param_2,*(undefined4 *)((int)auStack_520 + DAT_0003e7b0 + 8));
          local_568 = (byte)*(undefined4 *)((int)auStack_520 + DAT_0003e7b0);
          local_567 = 6;
          local_566 = (byte)param_2;
          (*(code *)puVar1[1])(iVar3,3,&local_568);
          return 0;
        }
      } while ((local_567 & 5) != 4);
      if ((uint)local_568 == *(uint *)((int)auStack_520 + DAT_0003e7b0)) break;
      iVar4 = (uint)local_566 + iVar4 + 3;
    }
    if (-1 < (int)((uint)local_567 << 0x1e)) break;
    (*(code *)*puVar1)(iVar3 + 3,local_566,auStack_124);
    if ((local_566 == param_2) && (iVar2 = rom_25002(local_18), iVar2 == 0)) {
      return 0;
    }
    local_560[0] = local_567 & 0xfb;
    (*(code *)puVar1[1])(iVar3 + 1,1,local_560);
  }
  return 5;
}

/* ==========================================================================
 * FUN_0003e6e2   @ 0x0003e6e2   (52 bytes)
 * called by : FUN_0003e552, FUN_0003e590, FUN_0003e5c4
 * calls     : FUN_0003e498
 */

void FUN_0003e6e2(uint param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28 [2];
  uint uStack_20;
  byte *pbStack_1c;
  undefined4 *local_18;
  
  local_28[0] = DAT_0003e7a8;
  uStack_20 = param_1;
  pbStack_1c = param_2;
  local_18 = param_3;
  do {
    uVar1 = local_28[0];
    iVar2 = FUN_0003e498(local_28[0],param_2,local_28);
    if (iVar2 != 0) break;
  } while ((*param_2 != param_1) || ((param_2[1] & 5) != 4));
  *local_18 = uVar1;
  return;
}

/* ==========================================================================
 * FUN_0003e716   @ 0x0003e716   (28 bytes)
 * called by : FUN_0003e516, FUN_0003e732
 */

void FUN_0003e716(void)

{
  int iVar1;
  
  iVar1 = DAT_0003e794;
  (**(code **)(DAT_0003e794 + 8))(0x7f000,*(undefined4 *)(DAT_0003e794 + 0x10));
  (**(code **)(iVar1 + 4))(0x7f000,4,DAT_0003e7a4);
  return;
}

/* ==========================================================================
 * FUN_0003e732   @ 0x0003e732   (96 bytes)
 * called by : FUN_0003e5f0
 * calls     : FUN_0003e498, FUN_0003e716, rom_24F9C
 */

void FUN_0003e732(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack_28;
  byte local_27;
  byte local_26;
  int local_24 [2];
  undefined4 uStack_1c;
  int local_18;
  
  puVar1 = DAT_0003e794;
  iVar4 = 0;
  local_24[0] = DAT_0003e7a8;
  uStack_1c = param_1;
  local_18 = param_2;
  while( true ) {
    iVar2 = local_24[0];
    iVar3 = FUN_0003e498(local_24[0],&uStack_28,local_24);
    if (iVar3 != 0) break;
    if ((local_27 & 5) == 4) {
      iVar4 = (uint)local_26 + iVar4 + 3;
      rom_24F9C(param_2,&uStack_28,3);
      (*(code *)*puVar1)(iVar2 + 3,local_26,param_2 + 3);
      param_2 = (uint)local_26 + param_2 + 3;
    }
  }
  FUN_0003e716();
  (*(code *)puVar1[1])(DAT_0003e7a8,iVar4,local_18);
  return;
}

/* ==========================================================================
 * prf_register_atthdl2gatt   @ 0x0003e800   (84 bytes)
 * called by : FUN_00041f62
 * calls     : FUN_0003ee1a, dbg_printf, rom_06EF4, rom_06F26
 * string    : "prf_register_atthdl2gatt,svc->shdl=%x,%x\n"
 * string    : "~~~~~~~~~dest=%x,~~~~~~~~~src=%x,%x\n"
 */

void prf_register_atthdl2gatt(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  dbg_printf(str_prf_register_atthdl2gatt_svc_shdl_x_x,*(undefined2 *)(param_3 + 0x14),
             *(undefined2 *)(param_3 + 0x16),param_4,param_4);
  uVar1 = FUN_0003ee1a(param_1,param_2);
  dbg_printf(str_dest_x_src_x_x,param_2 * 0x100 + 6,uVar1);
  if (*(short *)(param_3 + 0x14) != 0) {
    uVar1 = FUN_0003ee1a(param_1,param_2);
    puVar2 = (undefined1 *)rom_06EF4(DAT_0003ebc0 + 7,param_2 * 0x100 + 6,uVar1,8);
    *puVar2 = 0x10;
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(param_3 + 0x14);
    *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_3 + 0x16);
    rom_06F26();
  }
  return;
}

/* ==========================================================================
 * FUN_0003e958   @ 0x0003e958   (30 bytes)
 * called by : FUN_000420ee, FUN_00042132
 * calls     : FUN_0003e902
 */

undefined8 FUN_0003e958(void)

{
  FUN_0003e902();
  return 0xc00000002;
}

/* ==========================================================================
 * FUN_0003edee   @ 0x0003edee   (44 bytes)
 * called by : FUN_0003f25e, FUN_0003f3b0, FUN_0003f46a, FUN_0003f86c, FUN_0003faaa, FUN_0003fb6a, ... (+16 more)
 */

undefined4 FUN_0003edee(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(ushort *)(uVar1 * 0x18 + DAT_0003eeb8 + 0x12) == param_1) {
      return *(undefined4 *)(uVar1 * 0x18 + DAT_0003eeb8 + 0xc);
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return 0;
}

/* ==========================================================================
 * FUN_0003ee6e   @ 0x0003ee6e   (52 bytes)
 * called by : FUN_0002bf30, FUN_0002bf5c, FUN_0002bf88, FUN_0002c124, FUN_0002c158, FUN_0002ca56, ... (+8 more)
 */

uint FUN_0003ee6e(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  uVar1 = 0;
  do {
    if ((uint)*(ushort *)(uVar1 * 0x18 + DAT_0003eeb8 + 0x12) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(uVar1 * 0x18 + DAT_0003eeb8 + 0x10);
      break;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return param_1 & 0xffffff00 | uVar2;
}

/* ==========================================================================
 * FUN_0003ef20   @ 0x0003ef20   (40 bytes)
 * called by : FUN_0003ef48
 */

uint FUN_0003ef20(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1;
  uVar2 = 0;
  do {
    if ((param_1 >> uVar2 & 1) != 0) {
      uVar1 = uVar1 | 3 << (uVar2 * 2 + 1 & 0xff);
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 9);
  return uVar1;
}

/* ==========================================================================
 * FUN_0003ef48   @ 0x0003ef48   (126 bytes)
 * calls     : FUN_0003ef20, FUN_0003f25e, rom_06D2C, rom_07180, rom_179A0, rom_1F06A
 */

int FUN_0003ef48(int param_1,ushort *param_2,undefined4 param_3,uint param_4,ushort *param_5)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 local_28;
  int iStack_24;
  ushort *local_20;
  undefined4 local_1c;
  uint uStack_18;
  
  iStack_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  local_28 = FUN_0003ef20(*param_5);
  iVar2 = rom_1F06A(local_20,PTR_DAT_0003f094,&local_28,0x13,0,*(undefined2 *)(param_1 + 0x10),
                    PTR_DAT_0003f090,param_4 & 0x1e);
  if (iVar2 == 0) {
    puVar3 = (ushort *)rom_06D2C(0x14,1);
    *(ushort **)(param_1 + 0xc) = puVar3;
    puVar3[6] = *local_20;
    puVar3[7] = *param_5;
    uVar1 = 0;
    if ((param_4 & 1) != 0) {
      uVar1 = 0x8000;
    }
    *puVar3 = uVar1 | (ushort)local_1c;
    puVar3[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x14;
    FUN_0003f25e(param_1);
    rom_179A0(puVar3 + 2);
    rom_07180(*(undefined2 *)(param_1 + 0x10),0);
  }
  return iVar2;
}

/* ==========================================================================
 * FUN_0003f25e   @ 0x0003f25e   (26 bytes)
 * called by : FUN_0003ef48
 * calls     : FUN_0003edee
 */

void FUN_0003f25e(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x14);
  *param_1 = PTR_PTR_0003f284;
  *(undefined2 *)((int)param_1 + 10) = 3;
  param_1[1] = iVar1 + 0x12;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_0003f3b0   @ 0x0003f3b0   (28 bytes)
 * called by : FUN_0003f3cc, FUN_0003f418
 * calls     : FUN_0003edee
 */

uint FUN_0003f3b0(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x47);
  if (param_1 < 0xe) {
    return *(ushort *)(iVar1 + 0x10) + param_1 & 0xffff;
  }
  return 0;
}

/* ==========================================================================
 * FUN_0003f46a   @ 0x0003f46a   (32 bytes)
 * called by : gattc_att_info_req_ind_handler_2
 * calls     : FUN_0003edee
 */

undefined4 FUN_0003f46a(uint param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0003edee(0x47);
  uVar2 = 0x80;
  if (param_1 <= *(ushort *)(iVar1 + 0x10) + 0xd) {
    *param_2 = (char)param_1 - (char)*(ushort *)(iVar1 + 0x10);
    uVar2 = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * gattc_att_info_req_ind_handler_2   @ 0x0003f53a   (106 bytes)
 * calls     : FUN_0003f46a, dbg_printf, rom_06EF4, rom_06F26
 * string    : "gattc_att_info_req_ind_handler"
 * string    : "%s,conidx:%d\r\n"
 */

undefined4
gattc_att_info_req_ind_handler_2
          (undefined4 param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined2 *puVar2;
  char local_28 [4];
  undefined4 uStack_24;
  undefined2 *puStack_20;
  undefined4 local_1c;
  uint local_18;
  
  local_28[0] = '\0';
  uStack_24 = param_1;
  puStack_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  iVar1 = FUN_0003f46a(*param_2,local_28);
  dbg_printf(str_s_conidx_d_3,DAT_0003f88c + 0x1f,param_4 >> 8);
  puVar2 = (undefined2 *)rom_06EF4(DAT_0003f8a0,local_18,local_1c,6);
  *puVar2 = *param_2;
  if (iVar1 == 0) {
    if ((local_28[0] == '\n') || (local_28[0] == '\r')) {
      puVar2[1] = 2;
    }
    else if (local_28[0] == '\a') {
      puVar2[1] = 0x274;
    }
    else {
      iVar1 = 3;
      puVar2[1] = 0;
    }
  }
  *(char *)(puVar2 + 2) = (char)iVar1;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_0003f86c   @ 0x0003f86c   (32 bytes)
 * calls     : FUN_0003edee
 */

void FUN_0003f86c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x47);
  *param_1 = DAT_0003f88c + -0x30;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + DAT_0003f920;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_0003f9a0   @ 0x0003f9a0   (286 bytes)
 * calls     : FUN_0003ff92, rom_06DF6, rom_07180, rom_1F06A, rom_1F61C, rom_24F9C
 */

int FUN_0003f9a0(void)

{
  ushort uVar1;
  int iVar2;
  ushort *unaff_r4;
  uint unaff_r5;
  byte *unaff_r7;
  undefined4 uStack00000000;
  uint uStack00000004;
  undefined *puStack00000008;
  uint uStack0000000c;
  byte *in_stack_00000014;
  byte in_stack_00000018;
  int iStack0000001c;
  ushort in_stack_00000024;
  int in_stack_0000002c;
  ushort *in_stack_00000030;
  undefined4 in_stack_00000034;
  uint in_stack_00000038;
  
  while( true ) {
    iStack0000001c = unaff_r5 * 2;
    (&stack0x00000024)[unaff_r5] = *in_stack_00000030;
    uStack0000000c = in_stack_00000038 & 0x1e;
    uStack00000004 = (uint)*(ushort *)(in_stack_0000002c + 0x10);
    uStack00000000 = 0;
    puStack00000008 = PTR_DAT_0003fce8;
    iVar2 = rom_1F06A(&stack0x00000024 + unaff_r5,PTR_DAT_0003fcec,&stack0x00000018,5);
    if ((iVar2 == 0) &&
       (*in_stack_00000030 =
             (*(short *)((int)&stack0x00000024 + iStack0000001c) -
             (ushort)(in_stack_00000014[1] != 1)) + 5, in_stack_00000014[1] == 1)) {
      rom_1F61C(*(short *)((int)&stack0x00000024 + iStack0000001c) + 2,&DAT_00001200,0);
    }
    unaff_r5 = unaff_r5 + 1 & 0xff;
    in_stack_00000018 = 7;
    if (*unaff_r7 <= unaff_r5) break;
    if (iVar2 != 0) goto LAB_0003fa2e;
    in_stack_00000018 = 7;
    in_stack_00000014 = unaff_r7 + unaff_r5;
    *(byte *)(unaff_r4 + 0xf) = (byte)unaff_r4[0xf] | in_stack_00000014[1] << unaff_r5;
    rom_24F9C(unaff_r4 + unaff_r5 * 4 + 2,unaff_r7 + unaff_r5 * 8 + 4,8);
    if (in_stack_00000014[1] == 1) {
      in_stack_00000018 = in_stack_00000018 | 8;
    }
    if (1 < *(byte *)((int)unaff_r4 + 0x1f)) {
      in_stack_00000018 = in_stack_00000018 | 0x10;
    }
  }
  if (iVar2 == 0) {
    *(ushort **)(in_stack_0000002c + 0xc) = unaff_r4;
    *in_stack_00000030 = in_stack_00000024;
    unaff_r4[0xc] = in_stack_00000024;
    uVar1 = 0;
    if ((in_stack_00000038 & 1) != 0) {
      uVar1 = 0x8000;
    }
    *unaff_r4 = uVar1 | (ushort)in_stack_00000034;
    unaff_r4[1] = *(ushort *)(in_stack_0000002c + 0x10);
    *(undefined2 *)(in_stack_0000002c + 0x12) = 0x24;
    FUN_0003ff92(in_stack_0000002c);
    rom_07180(*(undefined2 *)(in_stack_0000002c + 0x10),0);
    return 0;
  }
LAB_0003fa2e:
  if (unaff_r4 != (ushort *)0x0) {
    rom_06DF6();
  }
  return iVar2;
}

/* ==========================================================================
 * FUN_0003faaa   @ 0x0003faaa   (122 bytes)
 * called by : FUN_0003fb24
 * calls     : FUN_0003edee
 */

uint FUN_0003faaa(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_0003edee(0x24);
  uVar3 = 0;
  if (*(byte *)(iVar1 + 0x1f) <= param_1) {
    return 0;
  }
  uVar2 = (uint)*(ushort *)(iVar1 + 0x18);
  for (; uVar3 < param_1; uVar3 = uVar3 + 1 & 0xff) {
    uVar2 = (uVar2 - ((int)((uint)(*(byte *)(iVar1 + 0x1e) >> uVar3) << 0x1f) >> 0x1f)) + 4 & 0xffff
    ;
  }
  if (param_2 < 3) {
    uVar2 = uVar2 + param_2;
LAB_0003fb18:
    uVar2 = uVar2 & 0xffff;
  }
  else {
    if (param_2 == 3) {
      if ((*(byte *)(iVar1 + 0x1e) >> uVar3 & 1) != 0) {
        return uVar2 + 3 & 0xffff;
      }
    }
    else if ((param_2 == 4) && (1 < *(byte *)(iVar1 + 0x1f))) {
      uVar2 = (uVar2 - ((int)((uint)(*(byte *)(iVar1 + 0x1e) >> uVar3) << 0x1f) >> 0x1f)) + 3;
      goto LAB_0003fb18;
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * FUN_0003fb6a   @ 0x0003fb6a   (112 bytes)
 * called by : FUN_0003fdd4
 * calls     : FUN_0003edee
 */

undefined4 FUN_0003fb6a(uint param_1,undefined1 *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0003edee(0x24);
  uVar4 = (uint)*(ushort *)(iVar2 + 0x18);
  uVar3 = 0;
  while( true ) {
    *param_2 = (char)uVar3;
    uVar3 = uVar3 & 0xff;
    if (*(byte *)(iVar2 + 0x1f) <= uVar3) {
      return 0x80;
    }
    if (param_1 < uVar4) {
      return 0x80;
    }
    if (param_1 <= uVar4 + 2) break;
    uVar4 = uVar4 + 2 & 0xffff;
    if (((*(byte *)(iVar2 + 0x1e) >> uVar3 & 1) != 0) &&
       (uVar4 = uVar4 + 1 & 0xffff, param_1 == uVar4)) {
      cVar1 = '\x03';
      goto LAB_0003fbb8;
    }
    if ((1 < *(byte *)(iVar2 + 0x1f)) && (uVar4 = uVar4 + 1 & 0xffff, param_1 == uVar4)) {
      cVar1 = '\x04';
      goto LAB_0003fbb8;
    }
    uVar4 = uVar4 + 1 & 0xffff;
    uVar3 = uVar3 + 1;
  }
  cVar1 = (char)param_1 - (char)uVar4;
LAB_0003fbb8:
  *param_3 = cVar1;
  return 0;
}

/* ==========================================================================
 * FUN_0003fd6e   @ 0x0003fd6e   (102 bytes)
 * calls     : FUN_0003edee, FUN_0003fbda, rom_06EF4, rom_06F26, rom_07180, rom_071EA
 */

undefined4 FUN_0003fd6e(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 2;
  iVar1 = rom_071EA(param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_0003edee(0x24);
    if (((uint)*param_2 < (uint)*(byte *)(iVar1 + 0x1f)) && (param_2[1] < 0x65)) {
      *(byte *)((uint)*param_2 + iVar1 + 0x1a) = param_2[1];
      uVar3 = 1;
      rom_07180(param_3,1);
      *(byte **)(iVar1 + 0x14) = param_2 + -0xc;
      *(undefined1 *)(iVar1 + 0x20) = 0;
      FUN_0003fbda();
    }
    else {
      puVar2 = (undefined1 *)rom_06EF4(DAT_0003ffb4 + 2,param_4,param_3,1);
      *puVar2 = 0x81;
      rom_06F26();
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ==========================================================================
 * FUN_0003fdd4   @ 0x0003fdd4   (78 bytes)
 * calls     : FUN_0003fb6a, rom_06EF4, rom_06F26
 */

undefined4
FUN_0003fdd4(undefined4 param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  char local_30 [4];
  undefined1 local_2c [8];
  undefined4 uStack_24;
  undefined2 *puStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  local_2c[0] = 0;
  local_30[0] = '\0';
  uStack_24 = param_1;
  puStack_20 = param_2;
  uStack_1c = param_3;
  local_18 = param_4;
  iVar1 = FUN_0003fb6a(*param_2,local_2c,local_30);
  puVar2 = (undefined2 *)rom_06EF4(PTR_DAT_0003ffb8,local_18,param_3,6);
  *puVar2 = *param_2;
  if (iVar1 == 0) {
    if (local_30[0] == '\x03') {
      puVar2[1] = 2;
    }
    else {
      iVar1 = 3;
      puVar2[1] = 0;
    }
  }
  *(char *)(puVar2 + 2) = (char)iVar1;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_0003ff92   @ 0x0003ff92   (26 bytes)
 * called by : FUN_0003f9a0
 * calls     : FUN_0003edee
 */

void FUN_0003ff92(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x24);
  *param_1 = PTR_PTR_0003ffbc;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + 0x1c;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_000400c6   @ 0x000400c6   (28 bytes)
 * called by : FUN_000400e2
 * calls     : FUN_0003edee
 */

uint FUN_000400c6(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x48);
  if (param_1 < 6) {
    return *(ushort *)(iVar1 + 0x10) + param_1 & 0xffff;
  }
  return 0;
}

/* ==========================================================================
 * FUN_00040134   @ 0x00040134   (30 bytes)
 * called by : gattc_att_info_req_ind_handler
 * calls     : FUN_0003edee
 */

undefined4 FUN_00040134(uint param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0003edee(0x48);
  uVar2 = 0x80;
  if (param_1 <= *(ushort *)(iVar1 + 0x10) + 5) {
    *param_2 = (char)param_1 - (char)*(ushort *)(iVar1 + 0x10);
    uVar2 = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * gattc_att_info_req_ind_handler   @ 0x000401aa   (98 bytes)
 * calls     : FUN_00040134, dbg_printf, rom_06EF4, rom_06F26
 * string    : "gattc_att_info_req_ind_handler"
 * string    : "%s,conidx:%d\r\n"
 */

undefined4
gattc_att_info_req_ind_handler
          (undefined4 param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  char local_28 [4];
  undefined4 uStack_24;
  undefined2 *puStack_20;
  undefined4 local_1c;
  uint local_18;
  
  local_28[0] = '\0';
  uStack_24 = param_1;
  puStack_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  iVar1 = FUN_00040134(*param_2,local_28);
  dbg_printf(str_s_conidx_d_4,DAT_00040420 + 0x1f,param_4 >> 8);
  puVar2 = (undefined2 *)rom_06EF4(PTR_DAT_00040434,local_18,local_1c,6);
  *puVar2 = *param_2;
  if (iVar1 == 0) {
    if (local_28[0] == '\x05') {
      uVar3 = 2;
    }
    else {
      if (local_28[0] != '\x04') {
        iVar1 = 3;
        puVar2[1] = 0;
        goto LAB_000401a6;
      }
      uVar3 = 0x80;
    }
    puVar2[1] = uVar3;
  }
LAB_000401a6:
  *(char *)(puVar2 + 2) = (char)iVar1;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_00040400   @ 0x00040400   (32 bytes)
 * calls     : FUN_0003edee
 */

void FUN_00040400(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x48);
  *param_1 = DAT_00040420 + -0x28;
  *(undefined2 *)((int)param_1 + 10) = 5;
  param_1[1] = iVar1 + 0x112;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_000405ae   @ 0x000405ae   (274 bytes)
 * called by : FUN_00028c66
 * calls     : FUN_00039708, FUN_0003b538, dbg_printf, rom_24F24
 * string    : "BBBBwait for reset!!!\r\n"
 */

longlong FUN_000405ae(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  iVar4 = DAT_00040884;
  pcVar6 = (char *)(*(int *)(DAT_00040884 + 0x14) + 0x52000);
  uVar3 = 0;
  iVar1 = *(int *)(DAT_00040884 + 0x18) * 0x10;
  if (*(char *)(DAT_00040884 + 0x1c) == '\x01') {
    pcVar5 = str_Img_Identify + *(int *)(DAT_00040884 + 0x14) + 4;
    if (*(int *)(DAT_00040890 + 0xc) == str_BBBBwait_for_reset._0_4_) {
      pcVar5 = pcVar6;
    }
    uVar7 = rom_24F24(iVar1,0x60);
    iVar2 = (int)((ulonglong)uVar7 >> 0x20);
    for (; uVar3 < (uint)uVar7; uVar3 = uVar3 + 1 & 0xff) {
      param_2 = 0;
      FUN_00039708(0,pcVar5 + uVar3 * 0x60,0x60,uVar3 * 0x60 + iVar4 + 0x1e);
    }
    if (iVar2 != 0) {
      param_2 = 0;
      FUN_00039708(0,pcVar5 + uVar3 * 0x60,iVar2,uVar3 * 0x60 + iVar4 + 0x1e);
    }
    iVar2 = DAT_00040884;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar1;
    *(undefined4 *)(iVar4 + 0x18) = 0;
    *(undefined1 *)(iVar2 + 0x1c) = 0;
  }
  else if (*(char *)(DAT_00040884 + 0x1c) == '\x02') {
    pcVar5 = str_Img_Identify + *(int *)(DAT_00040884 + 0x14) + 4;
    if (*(int *)(DAT_00040890 + 0xc) == str_BBBBwait_for_reset._0_4_) {
      pcVar5 = pcVar6;
    }
    uVar7 = rom_24F24(iVar1,0x60);
    iVar2 = (int)((ulonglong)uVar7 >> 0x20);
    for (uVar3 = 0; uVar3 < (uint)uVar7; uVar3 = uVar3 + 1 & 0xff) {
      FUN_00039708(0,pcVar5 + uVar3 * 0x60,0x60,uVar3 * 0x60 + iVar4 + 0x1e,0);
    }
    if (iVar2 != 0) {
      FUN_00039708(0,pcVar5 + uVar3 * 0x60,iVar2,uVar3 * 0x60 + iVar4 + 0x1e,0);
    }
    *(undefined4 *)(iVar4 + 0x18) = 0;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar1;
    iVar4 = 0;
    do {
      dbg_printf(str_BBBBwait_for_reset + 4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 10);
    *(undefined1 *)(DAT_00040884 + 0x1c) = 0;
    FUN_0003b538(10);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return (ulonglong)param_2 << 0x20;
}

/* ==========================================================================
 * gattc_cmp_evt_handler   @ 0x00040f64   (16 bytes)
 * calls     : dbg_printf
 * string    : "gattc_cmp_evt_handler"
 */

undefined4 gattc_cmp_evt_handler(void)

{
  dbg_printf(&DAT_0004102c,DAT_00040f94 + 0x32);
  return 0;
}

/* ==========================================================================
 * FUN_00040f74   @ 0x00040f74   (30 bytes)
 * calls     : FUN_0003edee
 */

void FUN_00040f74(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x49);
  *param_1 = DAT_00040f94 + -0x30;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + 0x3c;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_00041034   @ 0x00041034   (244 bytes)
 * called by : FUN_00041160, FUN_0004169a, FUN_00041922, hogpd_proto_mode_cfm_handler
 */

uint FUN_00041034(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  if (((param_2 < *(byte *)(param_1 + 0x1b)) && (param_3 < 0x17)) &&
     ((iVar3 = param_2 * 8 + param_1, param_3 < 0x13 || (param_4 < *(byte *)(iVar3 + 9))))) {
    uVar1 = (uint)*(ushort *)(param_1 + 0x14);
    for (; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
      uVar1 = *(byte *)(uVar2 * 8 + param_1 + 8) + uVar1 & 0xffff;
    }
    if (param_3 < 0x13) {
      uVar2 = (uint)*(ushort *)(iVar3 + 4);
      uVar1 = uVar1 + param_3 & 0xffff;
      if ((*(ushort *)(iVar3 + 4) & 1) == 0) {
        if (param_3 < 0x10) {
          if (param_3 - 0xb < 5) {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = uVar1 - 5 & 0xffff;
        }
      }
      if (-1 < (int)(uVar2 << 0x1e)) {
        if (param_3 < 0x13) {
          if (param_3 - 0x10 < 3) {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = uVar1 - 3 & 0xffff;
        }
      }
      if (-1 < (int)(uVar2 << 0x1d)) {
        if (param_3 < 0xb) {
          if (param_3 - 9 < 2) {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = uVar1 - 2 & 0xffff;
        }
      }
      if ((int)(uVar2 << 0x1c) < 0) {
        return uVar1;
      }
      if (param_3 < 9) {
        if (param_3 < 2) {
          if (param_3 != 1) {
            return uVar1;
          }
          return 0;
        }
        uVar1 = uVar1 - 1;
      }
      else {
        uVar1 = uVar1 - 2;
      }
    }
    else {
      uVar1 = *(byte *)(iVar3 + 10) + uVar1 & 0xffff;
      for (uVar2 = 0; uVar2 < param_4; uVar2 = uVar2 + 1 & 0xff) {
        uVar1 = uVar1 + 3 & 0xffff;
        if (((uint)*(ushort *)(iVar3 + 4) & 0x40 << uVar2) != 0) {
          uVar1 = uVar1 + 1 & 0xffff;
        }
      }
      if ((param_3 == 0x16) && (((uint)*(ushort *)(iVar3 + 4) & 0x40 << (param_4 & 0xff)) != 0)) {
        return 0;
      }
      uVar1 = (uVar1 + param_3) - 0x13;
    }
    uVar1 = uVar1 & 0xffff;
  }
  return uVar1;
}

/* ==========================================================================
 * FUN_00041160   @ 0x00041160   (992 bytes)
 * calls     : FUN_00041034, FUN_00041e78, rom_06D2C, rom_06DF6, rom_07180, rom_1F06A, ... (+3 more)
 */

int FUN_00041160(void)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  byte bVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  int unaff_r5;
  uint uVar10;
  byte *unaff_r7;
  byte bStack00000010;
  byte bStack00000011;
  ushort in_stack_00000024;
  ushort *in_stack_00000028;
  uint uStack0000002c;
  byte *in_stack_00000030;
  int in_stack_00000034;
  undefined *in_stack_00000038;
  undefined1 *in_stack_0000003c;
  int in_stack_0000004c;
  uint in_stack_00000054;
  int in_stack_0000005c;
  ushort *in_stack_00000060;
  undefined4 in_stack_00000064;
  uint in_stack_00000068;
  
  uVar3 = 0;
  while (puVar1 = in_stack_00000028, uStack0000002c = uVar3, uVar3 < *unaff_r7) {
    if (unaff_r5 != 0) goto LAB_000413d6;
    in_stack_00000030 = unaff_r7 + uVar3 * 0x1a;
    if (8 < in_stack_00000030[3]) {
      unaff_r5 = 0x81;
      goto LAB_000413d6;
    }
    iVar9 = uVar3 * 8;
    in_stack_00000028[uVar3 * 4 + 2] = in_stack_00000030[2] & 0x3f;
    *(byte *)((int)in_stack_00000028 + iVar9 + 9) = in_stack_00000030[3];
    in_stack_00000034 = iVar9;
    uVar5 = rom_06D2C(0x198,3);
    iVar8 = uStack0000002c * 4;
    in_stack_0000004c = iVar8;
    *(undefined4 *)(&stack0x00000044 + iVar8) = uVar5;
    *(undefined4 *)(&stack0x00000014 + iVar9) = 0xfd;
    *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\a';
    rom_24F9C(*(undefined4 *)(&stack0x00000044 + iVar8),PTR_DAT_000415b0,0x98);
    if ((int)((uint)in_stack_00000030[2] << 0x1c) < 0) {
      *(uint *)(&stack0x00000014 + in_stack_00000034) =
           *(uint *)(&stack0x00000014 + in_stack_00000034) | 0x102;
      *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\x02';
      *(undefined2 *)(*(int *)(&stack0x00000044 + in_stack_0000004c) + 0xe) =
           *(undefined2 *)(in_stack_00000030 + 0x18);
    }
    if ((int)((uint)in_stack_00000030[2] << 0x1d) < 0) {
      *(uint *)(&stack0x00000014 + in_stack_00000034) =
           *(uint *)(&stack0x00000014 + in_stack_00000034) | 0x600;
      *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\x02';
    }
    if ((in_stack_00000030[2] & 1) != 0) {
      *(uint *)(&stack0x00000014 + in_stack_00000034) =
           *(uint *)(&stack0x00000014 + in_stack_00000034) | 0xf800;
      *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\x05';
      if ((int)((uint)in_stack_00000030[2] << 0x1b) < 0) {
        *(ushort *)(*(int *)(&stack0x00000044 + in_stack_0000004c) + 0x62) =
             *(ushort *)(*(int *)(&stack0x00000044 + in_stack_0000004c) + 0x62) | 0x800;
      }
    }
    if ((int)((uint)in_stack_00000030[2] << 0x1e) < 0) {
      *(uint *)(&stack0x00000014 + in_stack_00000034) =
           *(uint *)(&stack0x00000014 + in_stack_00000034) | 0x70000;
      *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\x03';
      if ((int)((uint)in_stack_00000030[2] << 0x1a) < 0) {
        *(ushort *)(*(int *)(&stack0x00000044 + in_stack_0000004c) + 0x8a) =
             *(ushort *)(*(int *)(&stack0x00000044 + in_stack_0000004c) + 0x8a) | 0x800;
      }
    }
    *(char *)(puVar1 + uVar3 * 4 + 5) = (char)puVar1[uVar3 * 4 + 4];
    for (uVar10 = 0; uVar10 < in_stack_00000030[3]; uVar10 = uVar10 + 1 & 0xff) {
      in_stack_00000038 = (undefined *)0x0;
      puVar4 = &stack0x00000014 + in_stack_00000034;
      iVar9 = uVar10 * 4;
      iVar8 = (iVar9 + 0x13U >> 5) * 4;
      in_stack_0000003c = puVar4;
      *(uint *)(puVar4 + iVar8) = *(uint *)(puVar4 + iVar8) | 1 << (iVar9 + 0x13U & 0x1f);
      iVar8 = (iVar9 + 0x14U >> 5) * 4;
      *(uint *)(puVar4 + iVar8) = *(uint *)(puVar4 + iVar8) | 1 << (iVar9 + 0x14U & 0x1f);
      iVar8 = (iVar9 + 0x15U >> 5) * 4;
      *(uint *)(puVar4 + iVar8) = *(uint *)(puVar4 + iVar8) | 1 << (iVar9 + 0x15U & 0x1f);
      *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\x03';
      rom_24F9C(*(int *)(&stack0x00000044 + in_stack_0000004c) + uVar10 * 0x20 + 0x98,
                PTR_DAT_000415b0 + 0x98,0x20);
      bVar6 = in_stack_00000030[uVar10 + 4] & 3;
      if (bVar6 == 1) {
        if (*PTR_DAT_000415b4 == '\0') {
          puVar7 = &DAT_00001200;
        }
        else {
          puVar7 = &DAT_00001a00;
        }
        in_stack_00000038 = puVar7;
        iVar8 = (iVar9 + 0x16U >> 5) * 4;
        *(uint *)(in_stack_0000003c + iVar8) =
             *(uint *)(in_stack_0000003c + iVar8) | 1 << (iVar9 + 0x16U & 0x1f);
        *(char *)(puVar1 + uVar3 * 4 + 4) = (char)puVar1[uVar3 * 4 + 4] + '\x01';
        puVar1[uVar3 * 4 + 2] = puVar1[uVar3 * 4 + 2] | (ushort)(0x40 << uVar10);
        if ((int)((uint)in_stack_00000030[uVar10 + 4] << 0x1b) < 0) {
          in_stack_00000038 = (undefined *)((uint)puVar7 | 0x800);
          goto LAB_000413b8;
        }
      }
      else {
        if (bVar6 == 2) {
          in_stack_00000038 = (undefined *)0xe00;
        }
        else {
          if (bVar6 != 3) {
            unaff_r5 = 0x81;
            goto LAB_00041324;
          }
          in_stack_00000038 = (undefined *)0xa00;
        }
LAB_000413b8:
      }
LAB_00041324:
      *(short *)(*(int *)(&stack0x00000044 + in_stack_0000004c) + uVar10 * 0x20 + 0xa2) =
           (short)in_stack_00000038;
    }
    in_stack_00000054 = (byte)puVar1[uVar3 * 4 + 4] + in_stack_00000054 & 0xff;
    uVar3 = uStack0000002c + 1 & 0xff;
  }
  if (unaff_r5 == 0) {
    unaff_r5 = rom_1F3D4(in_stack_00000060,in_stack_00000054);
  }
LAB_000413d6:
  in_stack_00000024 = *in_stack_00000060;
  in_stack_00000028[10] = *in_stack_00000060;
  *(byte *)((int)in_stack_00000028 + 0x1b) = *unaff_r7;
  bStack00000010 = 0;
  for (uVar3 = 0; uVar3 < *unaff_r7; uVar3 = uVar3 + 1 & 0xff) {
    if (unaff_r5 != 0) goto LAB_000414de;
    unaff_r5 = rom_1F06A(&stack0x00000024,PTR_DAT_000415b8,&stack0x00000014 + uVar3 * 8,0x33);
    puVar1 = in_stack_00000028;
    in_stack_00000024 = (byte)in_stack_00000028[uVar3 * 4 + 4] + in_stack_00000024;
    if (unaff_r5 == 0) {
      uVar5 = FUN_00041034(in_stack_00000028,uVar3,3,0);
      unaff_r5 = rom_1F3F6(uVar5,4,0,unaff_r7 + uVar3 * 0x1a + 0x14);
      if (unaff_r5 == 0) {
        if (-1 < (int)((uint)unaff_r7[uVar3 * 0x1a + 2] << 0x1c)) {
          uVar10 = 0;
          goto LAB_000414b6;
        }
        uVar5 = FUN_00041034(in_stack_00000028,uVar3,8,0);
        unaff_r5 = rom_1F3F6(uVar5,2,0,unaff_r7 + uVar3 * 0x1a + 0x1a);
      }
    }
    uVar10 = 0;
    while (unaff_r5 == 0) {
LAB_000414b6:
      if (unaff_r7[uVar3 * 0x1a + 3] <= uVar10) break;
      bStack00000010 = unaff_r7[uVar10 + 0xc + uVar3 * 0x1a];
      bStack00000011 = unaff_r7[uVar10 + 4 + uVar3 * 0x1a] & 3;
      uVar5 = FUN_00041034(in_stack_00000028,uVar3,0x15,uVar10);
      unaff_r5 = rom_1F3F6(uVar5,2,0,&stack0x00000010);
      uVar10 = uVar10 + 1 & 0xff;
    }
    *(undefined1 *)((int)puVar1 + uVar3 * 8 + 0xb) = 1;
  }
  if (unaff_r5 == 0) {
    *(ushort **)(in_stack_0000005c + 0xc) = in_stack_00000028;
    uVar2 = 0;
    if ((in_stack_00000068 & 1) != 0) {
      uVar2 = 0x8000;
    }
    *in_stack_00000028 = uVar2 | (ushort)in_stack_00000064;
    in_stack_00000028[1] = *(ushort *)(in_stack_0000005c + 0x10);
    *(undefined2 *)(in_stack_0000005c + 0x12) = 0x26;
    FUN_00041e78(in_stack_0000005c);
    rom_07180(*(undefined2 *)(in_stack_0000005c + 0x10),0);
  }
  else {
LAB_000414de:
    if (in_stack_00000028 != (ushort *)0x0) {
      rom_06DF6();
    }
  }
  uVar3 = 0;
  do {
    if (*(int *)(&stack0x00000044 + uVar3 * 4) != 0) {
      rom_06DF6();
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 2);
  return unaff_r5;
}

/* ==========================================================================
 * FUN_00041798   @ 0x00041798   (164 bytes)
 * calls     : FUN_0003edee, FUN_0003ee1a, FUN_0003ee2a, rom_06EF4, rom_06F26
 */

undefined4 FUN_00041798(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  
  uVar7 = 0;
  uVar11 = 0;
  iVar8 = param_1;
  iVar9 = param_3;
  iVar1 = FUN_0003edee(0x26);
  if (param_3 == 0xd) {
    uVar7 = 1;
  }
  else if (param_3 == 0x12) {
    uVar7 = 2;
  }
  else if (param_3 == 0x16) {
    uVar7 = (ushort)(0x40 << (param_4 & 0xff));
  }
  iVar10 = param_1 * 2;
  if (param_5 == 0) {
    iVar2 = param_2 * 8 + iVar1 + iVar10;
    uVar7 = *(ushort *)(iVar2 + 6) & ~uVar7;
  }
  else {
    if (param_5 != 1) {
      return 0x80;
    }
    iVar2 = param_2 * 8 + iVar1 + iVar10;
    uVar7 = *(ushort *)(iVar2 + 6) | uVar7;
  }
  *(ushort *)(iVar2 + 6) = uVar7;
  uVar3 = FUN_0003ee1a(iVar1,param_1);
  uVar4 = FUN_0003ee2a(iVar1,param_1);
  puVar5 = (undefined1 *)rom_06EF4(DAT_0004183c,uVar4,uVar3,6,uVar11,iVar8,param_2,iVar9);
  *puVar5 = (char)param_1;
  uVar6 = 0;
  do {
    iVar8 = uVar6 * 8;
    iVar9 = uVar6 * 2;
    uVar6 = uVar6 + 1 & 0xff;
    *(undefined2 *)(puVar5 + iVar9 + 2) = *(undefined2 *)(iVar8 + iVar1 + iVar10 + 6);
  } while (uVar6 < 2);
  rom_06F26(puVar5);
  return uVar11;
}

/* ==========================================================================
 * FUN_00041922   @ 0x00041922   (224 bytes)
 * calls     : FUN_0003edee, FUN_00041034, rom_06EF4, rom_06F26, rom_07180, rom_071EA, ... (+2 more)
 */

undefined4 FUN_00041922(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  char *extraout_r1;
  char cVar7;
  char cVar8;
  
  uVar3 = rom_071EA(param_3);
  if (-1 < (int)(uVar3 << 0x1e)) {
    return 0;
  }
  cVar8 = -0x80;
  iVar4 = FUN_0003edee(0x26);
  cVar7 = param_2[2];
  if (cVar7 == '\0') {
    cVar1 = *(char *)(iVar4 + 0x17);
    if ((param_2[1] != cVar1) || (*param_2 != *(char *)(iVar4 + 0x16))) goto LAB_00041998;
    rom_25078(param_2[5],*param_2,0,param_2[5]);
    cVar7 = '\0';
    uVar5 = FUN_00041034(iVar4,extraout_r1[4],0x14,extraout_r1[8]);
    param_2 = extraout_r1;
    if (*(ushort *)(iVar4 + 0x18) != uVar5) goto LAB_00041996;
    cVar8 = '\0';
    if (*(char *)(iVar4 + 0x17) == '\x01') {
      sVar2 = *(short *)(extraout_r1 + 6);
      goto LAB_000419ba;
    }
  }
  else {
LAB_00041996:
    cVar1 = *(char *)(iVar4 + 0x17);
    cVar8 = cVar7;
LAB_00041998:
    if (cVar1 == '\x01') {
      sVar2 = 0;
LAB_000419ba:
      puVar6 = (undefined2 *)
               rom_06EF4(DAT_00041c6c + -2,(uint)*(byte *)(iVar4 + 0x16) * 0x100 + 6,param_3,
                         sVar2 + 6);
      *puVar6 = *(undefined2 *)(iVar4 + 0x18);
      *(char *)(puVar6 + 2) = cVar8;
      puVar6[1] = sVar2;
      if (cVar8 == '\0') {
        rom_24F9C((int)puVar6 + 5,param_2 + 9,sVar2);
      }
      goto LAB_000419f0;
    }
  }
  puVar6 = (undefined2 *)rom_06EF4(DAT_00041c6c,(uint)*(byte *)(iVar4 + 0x16) * 0x100 + 6,param_3,4)
  ;
  *puVar6 = *(undefined2 *)(iVar4 + 0x18);
  *(char *)(puVar6 + 1) = cVar8;
LAB_000419f0:
  rom_06F26(puVar6);
  *(undefined1 *)(iVar4 + 0x17) = 0;
  *(undefined2 *)(iVar4 + 0x18) = 0;
  *(undefined1 *)(iVar4 + 0x16) = 0xff;
  rom_07180(param_3,uVar3 & 0xfd);
  return 0;
}

/* ==========================================================================
 * hogpd_proto_mode_cfm_handler   @ 0x00041a10   (176 bytes)
 * calls     : FUN_0003edee, FUN_00041034, dbg_printf, rom_06EF4, rom_06F26, rom_07180, ... (+1 more)
 * string    : "hogpd_proto_mode_cfm_handler"
 */

undefined4 hogpd_proto_mode_cfm_handler(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  char cVar6;
  
  uVar2 = rom_071EA(param_3);
  dbg_printf(&LAB_00041c70,DAT_00041c50 + 0x1d);
  if (-1 < (int)(uVar2 << 0x1e)) {
    return 0;
  }
  cVar6 = -0x80;
  iVar3 = FUN_0003edee(0x26);
  cVar1 = param_2[1];
  if ((param_2[1] == '\0') && (cVar1 = -0x80, *(char *)(iVar3 + 0x17) == '\x03')) {
    if (*param_2 == *(char *)(iVar3 + 0x16)) {
      uVar4 = FUN_00041034(iVar3,param_2[2],10,0);
      if (*(ushort *)(iVar3 + 0x18) == uVar4) {
        *(char *)((uint)(byte)param_2[2] * 8 + iVar3 + 0xb) = param_2[3];
        cVar1 = '\0';
      }
      goto LAB_00041a6c;
    }
  }
  else {
LAB_00041a6c:
    cVar6 = cVar1;
    if (*(char *)(iVar3 + 0x17) == '\x01') {
      puVar5 = (undefined2 *)
               rom_06EF4(DAT_00041c6c + -2,(uint)*(byte *)(iVar3 + 0x16) * 0x100 + 6,param_3,6);
      *puVar5 = *(undefined2 *)(iVar3 + 0x18);
      *(char *)(puVar5 + 2) = cVar6;
      goto LAB_00041a88;
    }
  }
  puVar5 = (undefined2 *)rom_06EF4(DAT_00041c6c,(uint)*(byte *)(iVar3 + 0x16) * 0x100 + 6,param_3,4)
  ;
  *puVar5 = *(undefined2 *)(iVar3 + 0x18);
  *(char *)(puVar5 + 1) = cVar6;
LAB_00041a88:
  rom_06F26();
  *(undefined1 *)(iVar3 + 0x17) = 0;
  *(undefined2 *)(iVar3 + 0x18) = 0;
  *(undefined1 *)(iVar3 + 0x16) = 0xff;
  rom_07180(param_3,uVar2 & 0xfd);
  return 0;
}

/* ==========================================================================
 * FUN_00041e78   @ 0x00041e78   (28 bytes)
 * called by : FUN_00041160
 * calls     : FUN_0003edee
 */

void FUN_00041e78(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x26);
  *param_1 = PTR_PTR_00041e9c;
  *(undefined2 *)((int)param_1 + 10) = 8;
  param_1[1] = iVar1 + 0x1a;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_000420ee   @ 0x000420ee   (64 bytes)
 * calls     : FUN_0003e958, rom_06EF4, rom_06F26, rom_07180
 */

undefined4 FUN_000420ee(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  int unaff_r4;
  undefined4 unaff_r6;
  int in_stack_00000004;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  
  if (*(short *)(param_2 + 0x76) == 0) {
    puVar1 = (undefined1 *)rom_06EF4(DAT_000423d4,in_stack_00000018,in_stack_00000014,1);
    *puVar1 = 0x82;
    rom_06F26();
  }
  else {
    FUN_0003e958();
    **(int **)(in_stack_00000004 + 4) = unaff_r4 + -0xc;
    rom_07180(in_stack_00000014,5);
    unaff_r6 = 1;
  }
  return unaff_r6;
}

/* ==========================================================================
 * FUN_00042132   @ 0x00042132   (130 bytes)
 * calls     : FUN_0003e958, FUN_0003edee, rom_06EF4, rom_06F26, rom_07180, rom_071EA
 */

undefined4 FUN_00042132(undefined4 param_1,ushort *param_2,uint param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  
  iVar2 = rom_071EA(param_3);
  uVar6 = 0x89;
  if (iVar2 == 1) {
    iVar2 = FUN_0003edee(0x4b);
    iVar4 = (param_3 >> 8) * 4 + iVar2;
    iVar5 = *(int *)(iVar4 + 4);
    if (iVar5 == 0) {
      uVar6 = 0x80;
    }
    else if (*param_2 < 2) {
      sVar1 = *(short *)(iVar5 + 0x8a);
      uVar6 = 0x82;
      if (sVar1 != 0) {
        FUN_0003e958(iVar2,param_3 >> 8,sVar1,*param_2,0);
        **(undefined4 **)(iVar4 + 4) = param_2 + -6;
        rom_07180(param_3,5);
        return 1;
      }
    }
    else {
      uVar6 = 0x81;
    }
  }
  else if (iVar2 == 5) {
    return 2;
  }
  puVar3 = (undefined1 *)rom_06EF4(DAT_000423d4 + 2,param_4,param_3,1);
  *puVar3 = uVar6;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_00042430   @ 0x00042430   (28 bytes)
 * calls     : FUN_0003edee
 */

void FUN_00042430(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0003edee(0x4b);
  *param_1 = DAT_0004244c;
  *(undefined2 *)((int)param_1 + 10) = 8;
  param_1[1] = iVar1 + 8;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_00042450   @ 0x00042450   (14 bytes)
 * called by : FUN_0003bb38
 */

int FUN_00042450(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + 1;
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (int)param_1 - (int)pcVar2;
}

/* ==========================================================================
 * FUN_000429fc   @ 0x000429fc   (28 bytes)
 * called by : FUN_0003ba0a
 * calls     : FUN_00042c70, FUN_000433b0
 */

undefined8 FUN_000429fc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uVar1 = FUN_00042c70(param_2,param_3,&uStack_18,DAT_00042a1c);
  FUN_000433b0(0,&uStack_18);
  return CONCAT44(uStack_18,uVar1);
}


/*############################################################################
 * MOUSE INPUT (SENSOR, KEYS)  (36 functions)
 *
 *   0x0002B492  KEY_piaring_cnt  (54 B)
 *   0x000311B4  FUN_000311b4  (42 B)
 *   0x0003299C  set_Update_OLED_2  (366 B)
 *   0x00033DB8  FUN_00033db8  (8 B)
 *   0x00033DCA  sensor_pwdn  (36 B)
 *   0x00033DEE  sensor_init  (28 B)
 *   0x00033E0A  set_dpi  (26 B)
 *   0x00033E34  time_sensor_invalid  (264 B)
 *   0x00034414  FUN_00034414  (18 B)
 *   0x00034426  FUN_00034426  (20 B)
 *   0x0003463C  Disconnected  (80 B)
 *   0x00039AF0  FUN_00039af0  (34 B)
 *   0x00039BAE  FUN_00039bae  (20 B)
 *   0x0003A900  FUN_0003a900  (114 B)
 *   0x0003CD24  FUN_0003cd24  (146 B)
 *   0x0003CE00  FUN_0003ce00  (82 B)
 *   0x0003D57C  FUN_0003d57c  (66 B)
 *   0x0003D5DC  FUN_0003d5dc  (94 B)
 *   0x00042484  FUN_00042484  (202 B)
 *   0x00042554  FUN_00042554  (24 B)
 *   0x00042570  FUN_00042570  (96 B)
 *   0x000425D0  FUN_000425d0  (26 B)
 *   0x000425EA  FUN_000425ea  (164 B)
 *   0x00042690  FUN_00042690  (326 B)
 *   0x000427F4  FUN_000427f4  (234 B)
 *   0x000428E4  FUN_000428e4  (54 B)
 *   0x00042924  FUN_00042924  (38 B)
 *   0x0004296C  FUN_0004296c  (32 B)
 *   0x0004298C  FUN_0004298c  (34 B)
 *   0x000429AE  FUN_000429ae  (38 B)
 *   0x000429D4  FUN_000429d4  (36 B)
 *   0x00042B18  FUN_00042b18  (316 B)
 *   0x00042C70  FUN_00042c70  (1720 B)
 *   0x00043364  FUN_00043364  (32 B)
 *   0x00043384  FUN_00043384  (44 B)
 *   0x000433B0  FUN_000433b0  (10 B)
 ############################################################################*/

/* ==========================================================================
 * KEY_piaring_cnt   @ 0x0002b492   (54 bytes)
 * called by : FUN_00029a04, FUN_0002b4c8, FUN_0002d53c, FUN_0003e5f0, app_24_to_ble_reset, app_ble_to_ble_mode, ... (+7 more)
 * calls     : dbg_printf
 * string    : "KEY_piaring_cnt :[ %x  to  %x ] %x\r\n"
 */

void KEY_piaring_cnt(void)

{
  int iVar1;
  char cVar2;
  
  iVar1 = DAT_0002b598;
  if (((*DAT_0002b51c != '\0') && (*DAT_0002b520 == '\0')) && (*(char *)(DAT_0002b598 + 6) == '\0'))
  {
    cVar2 = *DAT_0002b698 + '\x01';
    *DAT_0002b698 = cVar2;
    *(char *)(iVar1 + 5) = cVar2;
    dbg_printf(str_KEY_piaring_cnt_x_to_x_x,*DAT_0002b54c,cVar2);
  }
  return;
}

/* ==========================================================================
 * FUN_000311b4   @ 0x000311b4   (42 bytes)
 * called by : sensor_init, sensor_pwdn
 * calls     : FUN_00039a84, FUN_00039af0, FUN_0003a900
 */

void FUN_000311b4(void)

{
  FUN_00039a84(0x33,0);
  FUN_0003a900(0,5);
  FUN_00039a84(7,1,2);
  FUN_00039af0(7,1);
  return;
}

/* ==========================================================================
 * set_Update_OLED_2   @ 0x0003299c   (366 bytes)
 * called by : system_mode
 * calls     : FUN_00032620, FUN_00032658, FUN_0003ce52, FUN_0003cf7c, FUN_0003d508, FUN_0003d546, ... (+3 more)
 * string    : "Dpi_Indicat_process= %x\r\n"
 * string    : "set_Update_OLED--Set_Loop_process \r\n"
 * string    : "set_Update_OLED--Flash_Linking_process \r\n"
 * string    : "set_Update_OLED--Flash_Ind_Fast_process0 \r\n"
 * string    : "set_Update_OLED--Flash_Ind_Fast_process1 \r\n"
 */

undefined1 * set_Update_OLED_2(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  byte *pbVar4;
  char *pcVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  short sVar9;
  
  bVar1 = *DAT_00032a64;
  if (bVar1 == 0) {
    puVar7 = (undefined1 *)0x0;
    if (*DAT_00032d5c != '\0') {
      return (undefined1 *)(uint)*DAT_00032d60;
    }
  }
  else {
    *DAT_00032b04 = 400;
    pcVar8 = DAT_00032d54;
    pbVar4 = DAT_00032a54;
    sVar3 = *DAT_00032a58;
    puVar7 = (undefined1 *)(uint)*DAT_00032a54;
    sVar9 = sVar3 + -1;
    bVar2 = *DAT_00032a50;
    if (bVar1 == 0x3c) {
      if (puVar7 != (undefined1 *)0x0) {
        return puVar7;
      }
      *DAT_00032a54 = bVar2;
      if (*pcVar8 == '\0') {
        if (sVar3 == 0) {
          *DAT_00032d58 = 0;
          puVar6 = DAT_00032d9c;
          *pbVar4 = 0;
          *puVar6 = 0;
        }
        else {
          *DAT_00032d98 = sVar9;
          *pcVar8 = '\x01';
        }
        puVar7 = (undefined1 *)FUN_00032620();
        return puVar7;
      }
      *pcVar8 = '\0';
      puVar7 = (undefined1 *)FUN_00032658();
      return puVar7;
    }
    if (0x3c < bVar1) {
      if (bVar1 == 0x3d) {
        if (puVar7 != (undefined1 *)0x0) {
          return puVar7;
        }
        *DAT_00032a54 = bVar2;
        pcVar5 = DAT_00032d50;
        if (*pcVar8 == '\0') {
          if (sVar3 == 0) {
            *DAT_00032d58 = 0;
            puVar6 = DAT_00032d9c;
            *pbVar4 = 0;
            *puVar6 = 0;
            FUN_00032620();
            puVar7 = (undefined1 *)FUN_0003cf7c();
            return puVar7;
          }
          *DAT_00032d98 = sVar9;
          *pcVar8 = '\x01';
          FUN_00032620();
          FUN_0003ce52();
          pcVar8 = str_set_Update_OLED_Flash_Ind_Fast_process0;
        }
        else {
          *pcVar8 = '\0';
          FUN_00032658();
          if (*pcVar5 == '\x01') {
            Pairing();
          }
          else if (*pcVar5 == '\x02') {
            ReLinking();
          }
          pcVar8 = str_set_Update_OLED_Flash_Linking_process;
        }
      }
      else {
        if (bVar1 != 0x3e) {
          return puVar7;
        }
        if (puVar7 != (undefined1 *)0x0) {
          return puVar7;
        }
        if ((undefined1 *)(uint)*DAT_00032d64 != (undefined1 *)0x0) {
          return (undefined1 *)(uint)*DAT_00032d64;
        }
        *DAT_00032a54 = bVar2;
        if (*pcVar8 == '\0') {
          if (sVar3 == 0) {
            *DAT_00032d58 = 0;
            puVar6 = DAT_00032d9c;
            *pbVar4 = 0;
            *puVar6 = 0;
          }
          else {
            *DAT_00032d98 = sVar9;
            *pcVar8 = '\x01';
          }
          *DAT_00032dfc = 2;
          puVar7 = DAT_00032e2c;
          *DAT_00032e2c = 1;
          return puVar7;
        }
        *pcVar8 = '\0';
        puVar7 = DAT_00032df8;
        if (*DAT_00032d68 != '\0') {
          puVar7 = DAT_00032d6c;
        }
        *puVar7 = 1;
        *DAT_00032dfc = 2;
        pcVar8 = str_set_Update_OLED_Flash_Ind_Fast_process1;
      }
      puVar7 = (undefined1 *)dbg_printf(pcVar8);
      return puVar7;
    }
    if (bVar1 != 0) {
      if (bVar1 == 2) {
        if (puVar7 == (undefined1 *)0x0) {
          FUN_0003d508();
          FUN_0003d546();
          dbg_printf(str_set_Update_OLED_Set_Loop_process);
          puVar7 = DAT_00032d58;
          *DAT_00032d58 = 0;
          return puVar7;
        }
        return puVar7;
      }
      if (bVar1 == 0x32) {
        dbg_printf(str_Dpi_Indicat_process_x);
        *DAT_00032d50 = '\x01';
        pcVar8 = DAT_00032d54;
        *pbVar4 = 1;
        *pcVar8 = '\x01';
        puVar7 = DAT_00032d58;
        *DAT_00032d58 = 0x3c;
      }
    }
  }
  return puVar7;
}

/* ==========================================================================
 * FUN_00033db8   @ 0x00033db8   (8 bytes)
 * calls     : FUN_00034426
 */

void FUN_00033db8(void)

{
  FUN_00034426();
  return;
}

/* ==========================================================================
 * sensor_pwdn   @ 0x00033dca   (36 bytes)
 * called by : FUN_000360aa, SLEEP, exist, force_ble_sleep
 * calls     : FUN_000311b4, FUN_00034414, FUN_00039a84, dbg_printf
 * string    : "sensor_pwdn"
 * string    : "%s \r\n"
 */

void sensor_pwdn(void)

{
  *DAT_00033fb4 = 0;
  FUN_00039a84(0x32,0,0);
  FUN_000311b4();
  FUN_00034414();
  dbg_printf(str_s_10,DAT_00033fb8);
  return;
}

/* ==========================================================================
 * sensor_init   @ 0x00033dee   (28 bytes)
 * called by : FUN_0002f31c, enter_BLE_normal_app_mode, f_usb_isConnected, time_sensor_invalid
 * calls     : FUN_000311b4, FUN_000345d2, dbg_printf
 * string    : "%s \r\n"
 * string    : "sensor_init"
 */

void sensor_init(void)

{
  FUN_000311b4();
  FUN_000345d2();
  dbg_printf(str_s_11,DAT_00033fb8 + 0xc);
  *DAT_00033fb4 = 1;
  return;
}

/* ==========================================================================
 * set_dpi   @ 0x00033e0a   (26 bytes)
 * called by : Default_Profile, _saveC_GM_ProfileMax, f_usb_isConnected, time_sensor_invalid
 * calls     : FUN_00034538, dbg_printf
 * string    : "%s \r\n"
 * string    : "set_dpi"
 */

void set_dpi(void)

{
  if (*DAT_00033fb4 != '\0') {
    FUN_00034538();
    dbg_printf(str_s_11,DAT_00033fb8 + -8);
  }
  return;
}

/* ==========================================================================
 * time_sensor_invalid   @ 0x00033e34   (264 bytes)
 * called by : FUN_0002f31c, FUN_0002ff18, FUN_000358b6, FUN_0003870a
 * calls     : FUN_00034426, FUN_0003443a, OLED_Init, dbg_printf, sensor_init, set_dpi
 * string    : "time_sensor_invalid=0\r\n"
 */

void time_sensor_invalid(void)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  char *pcVar4;
  short *psVar5;
  undefined1 *puVar6;
  int iVar7;
  byte bVar8;
  
  psVar2 = DAT_00033fd4;
  psVar1 = DAT_00033fd0;
  if (*DAT_00033fcc == '\0') {
    *DAT_00033fd0 = 0;
    *psVar2 = 0;
  }
  pcVar4 = DAT_00033fec;
  if ((*DAT_00033fd8 != '\0') &&
     ((((*DAT_00033fdc == 0 || (*DAT_00033fe0 == '\0')) && (*DAT_00033fb4 != '\0')) &&
      ((*DAT_00033fe4 == '\0' || (*DAT_00033fe8 != '\0')))))) {
    if ((*(uint *)(DAT_00033f70 + 0x6c) & 1) == 0) {
      FUN_0003443a();
      psVar5 = DAT_00033ff8;
      psVar2 = DAT_00033ff4;
      if (*DAT_00033ff4 != 0 || *DAT_00033ff8 != 0) {
        *DAT_00033ffc = 1;
        OLED_Init();
        puVar6 = DAT_00034000;
        *pcVar4 = '\b';
        *puVar6 = 0xf;
        *DAT_00034004 = 0x14;
        if (*DAT_00034008 != '\0') {
          *psVar2 = *psVar2 << 1;
        }
        if (*DAT_0003400c != '\0') {
          *psVar5 = *psVar5 << 1;
        }
        psVar3 = DAT_00033fd4;
        *psVar1 = *psVar1 + *psVar2;
        *psVar3 = *psVar3 + *psVar5;
        if (*DAT_00034010 != '\0') {
          *psVar2 = 0;
          *psVar5 = 0;
          *psVar1 = 0;
          *psVar3 = 0;
          *DAT_00033ffc = 0;
          dbg_printf(str_time_sensor_invalid_0);
        }
        *DAT_0003402c = 400;
        return;
      }
    }
    else if ((*DAT_00033fec == '\0') && (*DAT_00033fb4 == '\0')) {
      bVar8 = 0;
      *DAT_00033fec = '\b';
      do {
        iVar7 = FUN_00034426();
        if (iVar7 != 0) {
          return;
        }
        bVar8 = bVar8 + 1;
      } while (bVar8 < 4);
      *DAT_00033ff0 = 1;
      sensor_init();
      set_dpi();
      *pcVar4 = '\x02';
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00034414   @ 0x00034414   (18 bytes)
 * called by : sensor_pwdn
 * calls     : FUN_000317c2, FUN_00033d00
 */

void FUN_00034414(void)

{
  FUN_00033d00(0x3b,0xb6);
  FUN_000317c2(0x3c);
  return;
}

/* ==========================================================================
 * FUN_00034426   @ 0x00034426   (20 bytes)
 * called by : FUN_00033db8, time_sensor_invalid
 * calls     : FUN_00033d2c
 */

undefined4 FUN_00034426(void)

{
  int iVar1;
  
  iVar1 = FUN_00033d2c(0);
  if (iVar1 != 0x51) {
    return 0;
  }
  return 1;
}

/* ==========================================================================
 * Disconnected   @ 0x0003463c   (80 bytes)
 * called by : FUN_0003186e
 * calls     : FUN_000295aa, FUN_000312aa, Set_SIMU_mode_LightUp_Led, app_user_ke_timer_stop, ble_alert_led_stop, dbg_printf, ... (+2 more)
 * string    : "Disconnected by mouse...\r\n"
 */

void Disconnected(void)

{
  int iVar1;
  
  if (*DAT_00034a34 == '\0') {
    app_user_ke_timer_stop();
    ble_alert_led_stop();
    FUN_000312aa();
    *DAT_00034a38 = 0;
    iVar1 = rom_071EA(3);
    if (iVar1 == 3) {
      dbg_printf(str_Disconnected_by_mouse_2);
      *DAT_00034a58 = *DAT_00034a58 | 0x100;
      FUN_000295aa();
    }
    *DAT_00034a5c = 0;
    Set_SIMU_mode_LightUp_Led();
    switch_rf_mode_loop();
    *DAT_00034a60 = 1;
  }
  return;
}

/* ==========================================================================
 * FUN_00039af0   @ 0x00039af0   (34 bytes)
 * called by : FUN_000311b4, FUN_00039bae
 */

void FUN_00039af0(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(PTR_DAT_00039c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4);
  if (param_2 == 0) {
    uVar1 = uVar1 & 0xfffffffd;
  }
  else {
    uVar1 = uVar1 | 2;
  }
  *(uint *)(PTR_DAT_00039c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4) = uVar1;
  return;
}

/* ==========================================================================
 * FUN_00039bae   @ 0x00039bae   (20 bytes)
 * calls     : FUN_00039af0
 */

void FUN_00039bae(undefined4 param_1)

{
  FUN_00039af0(param_1,1);
  FUN_00039af0(param_1,0);
  return;
}

/* ==========================================================================
 * FUN_0003a900   @ 0x0003a900   (114 bytes)
 * called by : FUN_000311b4
 * calls     : FUN_00039a84
 */

void FUN_0003a900(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  DAT_0080000c = DAT_0080000c & 0xffffdfff;
  *(undefined4 *)(DAT_0003ad04 + 0x1c) = 2;
  FUN_00039a84(4,3,2,param_4,param_4);
  FUN_00039a84(5,3,2);
  FUN_00039a84(6,3,2);
  puVar1 = DAT_0003ad08;
  *DAT_0003ad08 = param_3 << 0x12 | param_2 << 8 | 0xb00000;
  if (param_1 == 0) {
    uVar3 = 0x400000;
  }
  else {
    uVar3 = 0x10000;
  }
  *puVar1 = *puVar1 | uVar3;
  iVar2 = DAT_0003ad0c;
  DAT_00800010 = DAT_00800010 & 0xfffff7ff;
  *(undefined1 *)(DAT_0003ad0c + 1) = 1;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  return;
}

/* ==========================================================================
 * FUN_0003cd24   @ 0x0003cd24   (146 bytes)
 * called by : FUN_0003cdb6, FUN_0003ce00, FUN_0003ce5c, FUN_0003cf24, FUN_0003d57c, FUN_0003d5dc, ... (+3 more)
 * calls     : FUN_0003b54e, FUN_0003c9f2, FUN_0003cb9a
 */

void FUN_0003cd24(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 local_20;
  
  uVar1 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  local_20 = param_2;
  do {
    if (*(char *)(param_4 + uVar1) == '\0') {
      *DAT_0003d0b8 = '\0';
      return;
    }
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(param_1,local_20,param_3);
    }
    else {
      FUN_0003cb9a(param_1,local_20,param_3);
    }
    if (param_3 == 0) {
      param_1 = param_1 + 6;
LAB_0003cd72:
      param_1 = param_1 & 0xff;
    }
    else {
      if (param_3 == 1) {
        param_1 = param_1 + 8;
        goto LAB_0003cd72;
      }
      if (param_3 == 2) {
        param_1 = param_1 + 0xc;
        goto LAB_0003cd72;
      }
    }
    if (0x70 < param_1) {
      param_1 = 0;
      if (param_3 == 0) {
        local_20 = local_20 + 1;
      }
      else if (param_3 == 1) {
        local_20 = local_20 + 2;
      }
      else {
        if (param_3 != 2) goto LAB_0003cda0;
        local_20 = local_20 + 3;
      }
      local_20 = local_20 & 0xff;
    }
LAB_0003cda0:
    uVar1 = uVar1 + 1 & 0xff;
  } while( true );
}

/* ==========================================================================
 * FUN_0003ce00   @ 0x0003ce00   (82 bytes)
 * called by : FLASH_WR_Profile, FUN_0003cf7c, FUN_0003d2b0, f_usb_isConnected
 * calls     : FUN_0003cd24, FUN_000429d4
 * string    : "%d dpi   "
 * string    : "%d dpi  "
 * string    : "%d dpi "
 * string    : "%d dpi"
 */

void FUN_0003ce00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar2 = ((uint)*(byte *)((uint)*(byte *)(DAT_0003d0ec + 0xd) + DAT_0003d0ec + 4) << 8 |
          *(byte *)((uint)*(byte *)(DAT_0003d0ec + 0xd) + DAT_0003d0ec + -4) + 1) * 0x32 & 0xffff;
  if (uVar2 < 100) {
    pcVar1 = str_d_dpi;
  }
  else if (uVar2 < 1000) {
    pcVar1 = str_d_dpi_2;
  }
  else if (uVar2 < DAT_0003d108) {
    pcVar1 = str_d_dpi_3;
  }
  else {
    pcVar1 = str_d_dpi_4;
  }
  uStack_10 = param_2;
  uStack_c = param_3;
  uStack_8 = param_4;
  FUN_000429d4(&uStack_10,pcVar1);
  FUN_0003cd24(0,1,1,&uStack_10);
  return;
}

/* ==========================================================================
 * FUN_0003d57c   @ 0x0003d57c   (66 bytes)
 * calls     : FUN_0003cd24
 */

void FUN_0003d57c(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  
  cVar1 = *PTR_DAT_0003d6c4;
  if (cVar1 == '\0') {
    FUN_0003cd24(0x4c,1,2,&PTR_DAT_0003d6cc);
    uVar2 = 0x5e;
    ppuVar3 = &PTR_DAT_0003d6d0;
  }
  else {
    if (cVar1 == '\x01') {
      ppuVar3 = (undefined **)(PTR_DAT_0003d6c8 + 0x10);
    }
    else {
      ppuVar3 = (undefined **)PTR_DAT_0003d6c8;
      if (cVar1 == '\x02') {
        ppuVar3 = (undefined **)(PTR_DAT_0003d6c8 + 0x18);
      }
    }
    uVar2 = 0x48;
  }
  FUN_0003cd24(uVar2,1,2,ppuVar3);
  return;
}

/* ==========================================================================
 * FUN_0003d5dc   @ 0x0003d5dc   (94 bytes)
 * calls     : FUN_0003cd24, FUN_000429d4
 * string    : "%d   "
 * string    : "DPI        "
 */

void FUN_0003d5dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar2 = ((uint)*(byte *)((uint)*(byte *)(DAT_0003d6d8 + 0xd) + DAT_0003d6d8 + 4) << 8 |
          *(byte *)((uint)*(byte *)(DAT_0003d6d8 + 0xd) + DAT_0003d6d8 + -4) + 1) * 0x32 & 0xffff;
  if (uVar2 < 100) {
    pcVar1 = str_d_4;
  }
  else if (uVar2 < 1000) {
    pcVar1 = &DAT_0003d6e4;
  }
  else if (uVar2 < DAT_0003d6ec) {
    pcVar1 = &DAT_0003d6f0;
  }
  else {
    pcVar1 = &DAT_0003d6f4;
  }
  uStack_10 = param_2;
  uStack_c = param_3;
  uStack_8 = param_4;
  FUN_000429d4(&uStack_10,pcVar1);
  FUN_0003cd24(0,0,0,str_DPI);
  FUN_0003cd24(0x19,0,0,&uStack_10);
  return;
}

/* ==========================================================================
 * FUN_00042484   @ 0x00042484   (202 bytes)
 * called by : FUN_00042b18
 * calls     : FUN_000425ea
 */

void FUN_00042484(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  
  local_20 = param_3;
  local_28 = param_1;
  if ((param_1 != 0 || (param_2 & 0x7fffffff) != 0) && (param_3 != 0 || (param_4 & 0x7fffffff) != 0)
     ) {
    local_24 = param_2 & 0xfffff | 0x100000;
    local_1c = param_4 & 0xfffff | 0x100000;
    uVar3 = 0;
    uVar6 = 0;
    iVar1 = 0;
    iVar4 = iVar1;
    while( true ) {
      iVar5 = iVar4;
      for (iVar2 = iVar1 - iVar4; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
        uVar7 = (uint)*(ushort *)((int)&local_20 + iVar2 * 2) *
                (uint)*(ushort *)((int)&local_28 + iVar5 * 2);
        bVar8 = CARRY4(uVar7,uVar3);
        uVar3 = uVar7 + uVar3;
        uVar6 = uVar6 + bVar8;
        iVar5 = iVar5 + -1;
      }
      *(short *)((int)&local_38 + iVar1 * 2) = (short)uVar3;
      uVar3 = uVar3 >> 0x10 | uVar6 << 0x10;
      uVar6 = uVar6 >> 0x10;
      iVar1 = iVar1 + 1;
      if (7 < iVar1) break;
      iVar4 = iVar1;
      if (2 < iVar1) {
        iVar4 = 3;
      }
    }
    FUN_000425ea(local_30,local_2c,local_38,local_34,0,(param_2 ^ param_4) & 0x80000000,
                 ((param_2 & 0x7fffffff) >> 0x14) + ((param_4 & 0x7fffffff) >> 0x14) + DAT_00042550)
    ;
  }
  return;
}

/* ==========================================================================
 * FUN_00042554   @ 0x00042554   (24 bytes)
 * calls     : FUN_000425ea
 */

void FUN_00042554(undefined4 param_1)

{
  FUN_000425ea(param_1,0,0,0,0,0,DAT_0004256c);
  return;
}

/* ==========================================================================
 * FUN_00042570   @ 0x00042570   (96 bytes)
 * called by : FUN_00042b18, FUN_00042c70
 * calls     : FUN_0004296c, FUN_0004298c
 */

longlong FUN_00042570(uint param_1,int param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  longlong lVar7;
  int local_2c;
  
  lVar1 = 0;
  iVar3 = 0x40;
  local_2c = param_2;
  while (iVar4 = iVar3 + -1, 0 < iVar3) {
    uVar6 = FUN_0004298c(param_1,local_2c,iVar4);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = iVar4;
    if (param_4 < uVar2 || uVar2 - param_4 < (uint)(param_3 <= (uint)uVar6)) {
      uVar6 = FUN_0004296c(param_3,param_4,iVar4);
      bVar5 = param_1 < (uint)uVar6;
      param_1 = param_1 - (uint)uVar6;
      local_2c = (local_2c - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;
      lVar7 = FUN_0004296c(1,0,iVar4);
      lVar1 = lVar7 + lVar1;
    }
  }
  return lVar1;
}

/* ==========================================================================
 * FUN_000425d0   @ 0x000425d0   (26 bytes)
 * called by : FUN_000425ea, FUN_00042690, FUN_000427f4
 */

undefined8 FUN_000425d0(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if (param_4 < 0) {
    bVar1 = 0xfffffffe < param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + (uint)bVar1;
    if ((param_3 & 0x7fffffff) == 0 && param_4 * 2 + (uint)CARRY4(param_3,param_3) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return CONCAT44(param_2,param_1);
}

/* ==========================================================================
 * FUN_000425ea   @ 0x000425ea   (164 bytes)
 * called by : FUN_00042484, FUN_00042554, FUN_00042690
 * calls     : FUN_000425d0, FUN_0004296c, FUN_0004298c, rom_2501C
 */

uint FUN_000425ea(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  if (param_2 == 0) {
    iVar1 = rom_2501C();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = rom_2501C(param_2);
  }
  uVar4 = FUN_0004296c(param_1,param_2,iVar1);
  uVar2 = (uint)(uVar4 >> 0x20);
  uVar3 = (uint)uVar4;
  if ((uVar3 != 0 || param_3 != 0) || (uVar2 != 0 || param_4 != 0)) {
    if (param_3 != 0 || param_4 != 0) {
      uVar5 = FUN_0004298c(param_3,param_4,0x40 - iVar1);
      lVar6 = FUN_0004296c(param_3,param_4,iVar1);
      uVar4 = CONCAT44(uVar2 | (uint)((ulonglong)uVar5 >> 0x20),
                       uVar3 | (uint)uVar5 | (uint)(lVar6 != 0));
    }
    uVar3 = (uint)(uVar4 >> 0xb);
    iVar1 = (param_7 - iVar1) + 10;
    if (iVar1 < 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_000425d0(uVar3 + param_5,
                           iVar1 * 0x100000 + (int)((uVar4 >> 0xb) >> 0x20) + param_6 +
                           (uint)CARRY4(uVar3,param_5),0,(int)uVar4 << 0x15);
    }
  }
  return uVar3;
}

/* ==========================================================================
 * FUN_00042690   @ 0x00042690   (326 bytes)
 * called by : FUN_00042b18
 * calls     : FUN_000425d0, FUN_000425ea, FUN_0004296c, FUN_000429ae
 */

uint FUN_00042690(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar1 = (int)(param_2 ^ param_4) >> 0x1f;
  local_20 = -iVar1;
  uVar5 = param_3;
  uVar3 = param_4;
  if ((param_2 & 0x7fffffff) <= (param_4 & 0x7fffffff) &&
      (uint)(param_3 <= param_1) <= (param_2 & 0x7fffffff) - (param_4 & 0x7fffffff)) {
    uVar5 = param_1;
    uVar3 = param_2;
    param_2 = param_4;
    param_1 = param_3;
  }
  if ((uVar3 & 0x7fffffff) != 0 || uVar5 != 0) {
    local_24 = param_2 >> 0x14;
    local_1c = local_24 & 0x7ff;
    iVar2 = local_1c - ((uVar3 & 0x7fffffff) >> 0x14);
    if (iVar2 < 0x40) {
      uVar3 = uVar3 & 0xfffff | 0x100000;
      if (local_20 != 0) {
        bVar7 = uVar5 != 0;
        uVar5 = -uVar5;
        uVar3 = -(uint)bVar7 - uVar3;
      }
      uVar8 = FUN_0004296c(uVar5,uVar3,0x40 - iVar2);
      uVar6 = (uint)(uVar8 >> 0x20);
      uVar4 = (uint)uVar8;
      lVar9 = FUN_000429ae(uVar5,uVar3,iVar2,&local_24);
      lVar9 = lVar9 + CONCAT44(param_2,param_1);
      uVar5 = (uint)lVar9;
      uVar3 = (uint)((ulonglong)lVar9 >> 0x20);
      if (uVar3 >> 0x14 != local_24 || (int)local_24 < 0) {
        if (local_20 == 0) {
          uVar8 = CONCAT44((uint)((uVar8 >> 1) >> 0x20) | uVar5 * -0x80000000,(int)(uVar8 >> 1));
          lVar9 = CONCAT44((uVar3 + local_24 * -0x100000 + 0x100000 >> 1) + local_24 * 0x100000,
                           uVar5 >> 1 | uVar3 * -0x80000000);
        }
        else {
          if (iVar2 < 2) {
            uVar5 = FUN_000425ea(uVar5,uVar3 + local_24 * -0x100000 + 0x100000,uVar4,uVar6,0,
                                 ((local_24 & 0xfff) >> 0xb) << 0x1f,local_1c);
            return uVar5;
          }
          lVar9 = CONCAT44(local_24 * -0x100000 + DAT_000427f0 +
                           uVar3 * 2 + 0x200000 + (uint)CARRY4(uVar5,uVar5),
                           uVar5 * 2 | uVar6 >> 0x1f);
          uVar8 = CONCAT44(uVar6 * 2 + (uint)CARRY4(uVar4,uVar4),uVar4 * 2);
        }
      }
    }
    else {
      uVar8 = CONCAT44(-(uint)(1 < (uint)(iVar1 * -2)),iVar1 * 2 + 1);
      lVar9 = CONCAT44(param_2 - (param_1 < local_20),param_1 + iVar1);
    }
    param_1 = FUN_000425d0((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),(int)uVar8,
                           (int)(uVar8 >> 0x20));
  }
  return param_1;
}

/* ==========================================================================
 * FUN_000427f4   @ 0x000427f4   (234 bytes)
 * called by : FUN_00042b18
 * calls     : FUN_000425d0
 */

void FUN_000427f4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  if ((param_1 != 0 || (param_2 & 0x7fffffff) != 0) && (param_3 != 0 || (param_4 & 0x7fffffff) != 0)
     ) {
    iVar1 = (((param_2 & 0x7fffffff) >> 0x14) - ((param_4 & 0x7fffffff) >> 0x14)) + DAT_000428e0;
    uVar4 = param_2 & 0xfffff | 0x100000;
    uVar6 = param_4 & 0xfffff | 0x100000;
    if (uVar6 < uVar4 || uVar4 - uVar6 < (uint)(param_3 <= param_1)) {
      iVar1 = iVar1 + 1;
    }
    else {
      bVar9 = CARRY4(param_1,param_1);
      param_1 = param_1 * 2;
      uVar4 = uVar4 * 2 + (uint)bVar9;
    }
    if (-1 < iVar1) {
      uVar3 = 0x100000;
      uVar7 = 0;
      uVar8 = 0;
      for (uVar2 = 0; uVar2 != 0 || uVar3 != 0; uVar2 = uVar2 >> 1 | uVar5) {
        if (uVar6 < uVar4 || uVar4 - uVar6 < (uint)(param_3 <= param_1)) {
          bVar9 = param_1 < param_3;
          param_1 = param_1 - param_3;
          uVar4 = (uVar4 - uVar6) - (uint)bVar9;
          uVar7 = uVar7 | uVar2;
          uVar8 = uVar8 | uVar3;
        }
        uVar5 = uVar3 << 0x1f;
        uVar3 = uVar3 >> 1;
        bVar9 = CARRY4(param_1,param_1);
        param_1 = param_1 * 2;
        uVar4 = uVar4 * 2 + (uint)bVar9;
      }
      if (param_1 != 0 || uVar4 != 0) {
        if (param_3 == param_1 && uVar4 == uVar6) {
          param_1 = 0;
          uVar4 = 0x80000000;
        }
        else if (uVar6 < uVar4 || uVar4 - uVar6 < (uint)(param_3 <= param_1)) {
          param_1 = 0xfffffffe;
          uVar4 = 0xffffffff;
        }
        else {
          param_1 = 1;
          uVar4 = 0;
        }
      }
      FUN_000425d0(uVar7,iVar1 * 0x100000 + uVar8 + ((param_2 ^ param_4) & 0x80000000),param_1,uVar4
                  );
    }
  }
  return;
}

/* ==========================================================================
 * FUN_000428e4   @ 0x000428e4   (54 bytes)
 * called by : FUN_00042b18
 * calls     : FUN_0004296c, FUN_0004298c
 */

void FUN_000428e4(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 & 0xfffff | 0x100000;
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  if ((int)uVar2 < DAT_0004291c) {
    return;
  }
  if ((int)uVar2 <= DAT_0004291c + 0x34) {
    FUN_0004298c(param_1,uVar1,(DAT_0004291c + 0x34) - uVar2);
    return;
  }
  FUN_0004296c(param_1,uVar1,uVar2 + DAT_00042920);
  return;
}

/* ==========================================================================
 * FUN_00042924   @ 0x00042924   (38 bytes)
 * called by : FUN_00042b18
 */

int FUN_00042924(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}

/* ==========================================================================
 * FUN_0004296c   @ 0x0004296c   (32 bytes)
 * called by : FUN_00042570, FUN_000425ea, FUN_00042690, FUN_000428e4
 */

longlong FUN_0004296c(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}

/* ==========================================================================
 * FUN_0004298c   @ 0x0004298c   (34 bytes)
 * called by : FUN_00042570, FUN_000425ea, FUN_000428e4
 */

ulonglong FUN_0004298c(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}

/* ==========================================================================
 * FUN_000429ae   @ 0x000429ae   (38 bytes)
 * called by : FUN_00042690
 */

undefined8 FUN_000429ae(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((int)param_3 < 0x20) {
    iVar2 = (int)param_2 >> (param_3 & 0xff);
    uVar1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
  }
  else {
    uVar1 = (int)param_2 >> (param_3 - 0x20 & 0xff);
    iVar2 = (int)(param_2 | uVar1) >> 0x1f;
  }
  return CONCAT44(iVar2,uVar1);
}

/* ==========================================================================
 * FUN_000429d4   @ 0x000429d4   (36 bytes)
 * called by : FUN_0003ce00, FUN_0003ce5c, FUN_0003d5dc
 * calls     : FUN_00042c70, FUN_000433b0
 */

undefined4 FUN_000429d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_00042c70(param_2,&uStack_8,&uStack_10,DAT_000429f8);
  FUN_000433b0(0,&uStack_10);
  return uVar1;
}

/* ==========================================================================
 * FUN_00042b18   @ 0x00042b18   (316 bytes)
 * called by : FUN_00042c70
 * calls     : FUN_00042484, FUN_00042570, FUN_00042690, FUN_000427f4, FUN_000428e4, FUN_00042924
 */

int * FUN_00042b18(int *param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 uVar8;
  bool bVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined4 local_38;
  undefined4 local_34;
  
  if (param_3 == 0 && param_4 == 0) {
    if (param_6 == 1) {
      param_5 = ~param_5;
    }
    else {
      param_5 = 0;
    }
    param_1[2] = 1;
    *param_1 = (int)&DAT_00042c64;
    param_1[3] = param_6;
    param_1[1] = param_5;
  }
  else {
    iVar5 = (int)(DAT_00042c58 * ((param_4 >> 0x14) + DAT_00042c54)) >> 0x10;
    do {
      while( true ) {
        if (param_6 == 1) {
          uVar1 = -param_5;
        }
        else {
          uVar1 = (iVar5 - param_5) + 1;
        }
        lVar10 = (ulonglong)DAT_00042c5c << 0x20;
        lVar12 = (ulonglong)DAT_00042c60 << 0x20;
        uVar7 = uVar1;
        if ((int)uVar1 < 0) {
          uVar7 = -uVar1;
          lVar12 = (ulonglong)DAT_00042c60 << 0x20;
          lVar10 = (ulonglong)DAT_00042c5c << 0x20;
        }
        while( true ) {
          uVar6 = (undefined4)((ulonglong)lVar10 >> 0x20);
          local_34 = (undefined4)((ulonglong)lVar12 >> 0x20);
          local_38 = (undefined4)lVar12;
          if (uVar7 == 0) break;
          if ((uVar7 & 1) != 0) {
            lVar12 = FUN_00042484(local_38,local_34,(int)lVar10,uVar6);
          }
          lVar10 = FUN_00042484((int)lVar10,uVar6);
          uVar7 = (int)uVar7 >> 1;
        }
        uVar8 = 1;
        if ((int)uVar1 < 0) {
          uVar11 = FUN_00042484();
        }
        else {
          uVar11 = FUN_000427f4(param_3,param_4,local_38,local_34);
        }
        bVar9 = true;
        FUN_00042924();
        if ((bool)uVar8 && !bVar9) {
          FUN_00042690((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_00042c6c);
          lVar12 = FUN_000428e4();
        }
        else {
          lVar12 = -1;
        }
        for (iVar4 = 0x10; (lVar12 != 0 && (-1 < iVar4)); iVar4 = iVar4 + -1) {
          cVar2 = '\n';
          lVar12 = FUN_00042570();
          *(char *)(param_2 + iVar4) = cVar2 + '0';
        }
        iVar3 = 0x11 - (iVar4 + 1);
        if (param_6 != 1) break;
        if (lVar12 == 0) {
          iVar5 = (iVar3 - param_5) + -1;
          goto LAB_00042c48;
        }
        param_5 = 0x11;
        param_6 = 0;
      }
      bVar9 = true;
      if ((lVar12 == 0) && (iVar3 <= (int)param_5)) {
        if (iVar3 < (int)param_5) {
          bVar9 = false;
          iVar5 = iVar5 + -1;
        }
      }
      else {
        bVar9 = false;
        iVar5 = iVar5 + 1;
      }
    } while (!bVar9);
LAB_00042c48:
    param_1[2] = iVar3;
    param_1[3] = param_6;
    *param_1 = param_2 + iVar4 + 1;
    param_1[1] = iVar5;
    param_1 = param_1 + 2;
  }
  return param_1;
}

/* ==========================================================================
 * FUN_00042c70   @ 0x00042c70   (1720 bytes)
 * called by : FUN_000429d4, FUN_000429fc
 * calls     : FUN_00042570, FUN_00042b18, FUN_00043364, FUN_00043384, rom_24F24
 * string    : "0123456789abcdef"
 * string    : "0123456789ABCDEF"
 */

/* WARNING: Type propagation algorithm not settling */

int FUN_00042c70(byte *param_1,uint *param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined1 **ppuVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  char extraout_r1;
  int *piVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  byte *pbVar17;
  undefined1 *puVar18;
  char *pcVar19;
  uint uVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  longlong lVar24;
  undefined1 **in_stack_ffffff80;
  undefined1 *in_stack_ffffff84;
  undefined1 *local_78;
  undefined4 local_74;
  uint local_70;
  undefined1 *local_6c;
  char local_63 [2];
  undefined4 local_61;
  undefined4 *******local_4c;
  char *local_48;
  char *local_40;
  uint local_3c;
  undefined1 **local_38;
  undefined1 *local_34;
  int local_30;
  uint local_2c;
  byte *pbStack_24;
  uint *local_20;
  undefined4 local_1c;
  code *local_18;
  
  local_18 = param_4;
  local_1c = param_3;
  pbStack_24 = param_1;
  iVar16 = 0;
  local_20 = param_2;
LAB_000430b6:
  uVar5 = (uint)*param_1;
  if (uVar5 == 0) {
    return iVar16;
  }
  if (uVar5 == 0x25) {
    uVar15 = 0;
    puVar18 = (undefined1 *)0x0;
    local_70 = 0;
    pbVar17 = param_1;
    while( true ) {
      param_1 = pbVar17 + 1;
      uVar5 = 1 << (*param_1 - 0x20 & 0xff);
      if ((uVar5 & DAT_00043064) == 0) break;
      uVar15 = uVar15 | uVar5;
      pbVar17 = param_1;
    }
    if (*param_1 == 0x2a) {
      local_70 = *local_20;
      local_20 = local_20 + 1;
      if ((int)local_70 < 0) {
        uVar15 = uVar15 | 0x2000;
        local_70 = -local_70;
      }
      uVar15 = uVar15 | 2;
      param_1 = pbVar17 + 2;
    }
    else {
      for (; *param_1 - 0x30 < 10; param_1 = param_1 + 1) {
        uVar15 = uVar15 | 2;
        local_70 = (uint)*param_1 + local_70 * 10 + -0x30;
      }
    }
    if (*param_1 == 0x2e) {
      uVar15 = uVar15 | 4;
      if (param_1[1] == 0x2a) {
        param_1 = param_1 + 2;
        puVar18 = (undefined1 *)*local_20;
        local_20 = local_20 + 1;
      }
      else {
        while( true ) {
          param_1 = param_1 + 1;
          if (9 < *param_1 - 0x30) break;
          puVar18 = (undefined1 *)((uint)*param_1 + (int)puVar18 * 10 + -0x30);
        }
      }
    }
    bVar1 = *param_1;
    if (bVar1 == 0x6c) {
      uVar5 = 0x100000;
LAB_00042d3a:
      uVar15 = uVar15 | uVar5;
      if (param_1[1] == bVar1) {
        uVar15 = uVar15 + 0x100000;
        param_1 = param_1 + 1;
      }
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 != 0x4c) {
        if (bVar1 == 0x68) {
          uVar5 = 0x300000;
          goto LAB_00042d3a;
        }
        if (bVar1 != 0x6a) goto LAB_00042d4c;
        uVar15 = uVar15 | 0x200000;
      }
    }
    else if ((bVar1 != 0x74) && (bVar1 != 0x7a)) goto LAB_00042d4c;
    param_1 = param_1 + 1;
LAB_00042d4c:
    uVar5 = (uint)*param_1;
    local_3c = uVar5;
    bVar23 = SBORROW4(uVar5,0x66);
    bVar21 = (int)(uVar5 - 0x66) < 0;
    bVar22 = uVar5 == 0x66;
LAB_00042d52:
    while (!bVar22) {
      if (bVar21 == bVar23) {
        if (uVar5 == 0x70) {
          iVar6 = 0x10;
          uVar15 = uVar15 | 4;
          puVar18 = &SupervisorCall;
        }
        else if (uVar5 < 0x71) {
          if (uVar5 == 0x67) break;
          if (uVar5 == 0x69) goto LAB_00042e86;
          if (uVar5 == 0x6e) {
            uVar5 = (uVar15 & 0x7fffff) >> 0x14;
            if (uVar5 == 2) {
              piVar8 = (int *)*local_20;
              *piVar8 = iVar16;
              piVar8[1] = iVar16 >> 0x1f;
            }
            else if (uVar5 == 3) {
              *(short *)*local_20 = (short)iVar16;
            }
            else if (uVar5 == 4) {
              *(char *)*local_20 = (char)iVar16;
            }
            else {
              *(int *)*local_20 = iVar16;
            }
            local_20 = local_20 + 1;
            goto LAB_000430b4;
          }
          if (uVar5 != 0x6f) goto LAB_00042da2;
          iVar6 = 8;
        }
        else {
          if (uVar5 == 0x73) {
            in_stack_ffffff80 = (undefined1 **)*local_20;
            iVar6 = -1;
            goto LAB_00042e04;
          }
          if (uVar5 != 0x75) {
            if (uVar5 == 0x78) goto LAB_00042efe;
            goto LAB_00042da2;
          }
          iVar6 = 10;
        }
LAB_00042f1a:
        uVar14 = (uVar15 & 0x7fffff) >> 0x14;
        if (uVar14 == 2) {
          puVar10 = (uint *)((uint)((int)local_20 + 7) & 0xfffffff8);
          uVar3 = *puVar10;
          uVar20 = puVar10[1];
          local_20 = puVar10 + 2;
        }
        else {
          uVar3 = *local_20;
          local_20 = local_20 + 1;
          uVar20 = 0;
          if (uVar14 == 3) {
            uVar3 = uVar3 & 0xffff;
          }
          if (uVar14 == 4) {
            uVar3 = uVar3 & 0xff;
          }
        }
        local_78 = (undefined1 *)0x0;
        if ((int)(uVar15 << 0x1c) < 0) {
          if (uVar5 == 0x70) {
            local_74 = (undefined1 **)CONCAT31(local_74._1_3_,0x40);
            local_78 = (undefined1 *)0x1;
LAB_00042f86:
          }
          else if ((iVar6 == 0x10) && (uVar20 != 0 || uVar3 != 0)) {
            local_74._0_2_ = CONCAT11(*param_1,0x30);
            local_78 = (undefined1 *)0x2;
            goto LAB_00042f86;
          }
          if ((iVar6 == 8) && ((uVar20 != 0 || uVar3 != 0 || ((int)(uVar15 << 0x1d) < 0)))) {
            local_74 = (undefined1 **)CONCAT31(local_74._1_3_,0x30);
            puVar18 = puVar18 + -1;
            local_78 = (undefined1 *)0x1;
          }
        }
LAB_00042faa:
        lVar24 = CONCAT44(uVar20,uVar3);
        uVar13 = 0;
        if (uVar5 == 0x58) {
          local_48 = str_s0123456789ABCDEF;
        }
        else {
          local_48 = str_s0123456789abcdef;
        }
        local_4c = &local_4c;
        while( true ) {
          if (lVar24 == 0) break;
          iVar9 = iVar6;
          lVar24 = FUN_00042570((int)lVar24,(int)((ulonglong)lVar24 >> 0x20),iVar6,uVar13);
          local_4c = (undefined4 *******)((int)local_4c + -1);
          *(char *)local_4c = local_48[iVar6];
          iVar6 = iVar9;
        }
        puVar12 = (undefined1 *)((int)&local_4c - (int)local_4c);
        if ((int)(uVar15 << 0x1d) < 0) {
          uVar15 = uVar15 & 0xfffeffff;
        }
        else {
          puVar18 = (undefined1 *)0x1;
        }
        if ((int)puVar12 < (int)puVar18) {
          ppuVar4 = (undefined1 **)(puVar18 + -(int)puVar12);
        }
        else {
          ppuVar4 = (undefined1 **)0x0;
        }
        local_70 = local_70 - (int)((undefined1 *)((int)ppuVar4 + (int)puVar12) + (int)local_78);
        if (-1 < (int)(uVar15 << 0xf)) {
          iVar6 = FUN_00043384(local_70,uVar15,local_1c,local_18);
          iVar16 = iVar6 + iVar16;
        }
        for (iVar6 = 0; iVar6 < (int)local_78; iVar6 = iVar6 + 1) {
          (*local_18)(*(undefined1 *)((int)&local_74 + iVar6),local_1c);
          iVar16 = iVar16 + 1;
        }
        if ((int)(uVar15 << 0xf) < 0) {
          iVar6 = FUN_00043384(local_70,uVar15,local_1c,local_18);
          iVar16 = iVar6 + iVar16;
        }
        while (in_stack_ffffff80 = (undefined1 **)((int)ppuVar4 + -1), 0 < (int)ppuVar4) {
          (*local_18)(0x30,local_1c);
          iVar16 = iVar16 + 1;
          ppuVar4 = in_stack_ffffff80;
        }
        while (in_stack_ffffff84 = puVar12 + -1, uVar5 = local_70, 0 < (int)puVar12) {
          cVar2 = *(char *)local_4c;
          local_4c = (undefined4 *******)((int)local_4c + 1);
          (*local_18)(cVar2,local_1c);
          iVar16 = iVar16 + 1;
          puVar12 = in_stack_ffffff84;
        }
        goto LAB_000430ae;
      }
      if (uVar5 == 0x58) {
LAB_00042efe:
        iVar6 = 0x10;
        goto LAB_00042f1a;
      }
      if (0x58 < uVar5) {
        if (uVar5 == 99) {
          local_78._0_2_ = (ushort)(byte)*local_20;
          in_stack_ffffff80 = &local_78;
          iVar6 = 1;
LAB_00042e04:
          local_20 = local_20 + 1;
          if ((int)(uVar15 << 0x1d) < 0) {
            for (iVar9 = 0;
                (iVar9 < (int)puVar18 &&
                ((iVar9 < iVar6 || (*(char *)((int)in_stack_ffffff80 + iVar9) != '\0'))));
                iVar9 = iVar9 + 1) {
            }
          }
          else {
            for (iVar9 = 0; (iVar9 < iVar6 || (*(char *)((int)in_stack_ffffff80 + iVar9) != '\0'));
                iVar9 = iVar9 + 1) {
            }
          }
          uVar5 = local_70 - iVar9;
          iVar6 = FUN_00043384(uVar5,uVar15,local_1c,local_18);
          iVar16 = iVar6 + iVar16 + iVar9;
          while (iVar9 = iVar9 + -1, iVar9 != -1) {
            uVar7 = *(undefined1 *)in_stack_ffffff80;
            in_stack_ffffff80 = (undefined1 **)((int)in_stack_ffffff80 + 1);
            (*local_18)(uVar7,local_1c);
          }
          in_stack_ffffff84 = (undefined1 *)0xffffffff;
          goto LAB_000430ae;
        }
        if (uVar5 == 100) {
LAB_00042e86:
          iVar6 = 10;
          uVar14 = (uVar15 & 0x7fffff) >> 0x14;
          if (uVar14 == 2) {
            puVar10 = (uint *)((uint)((int)local_20 + 7) & 0xfffffff8);
            uVar3 = *puVar10;
            uVar20 = puVar10[1];
            local_20 = puVar10 + 2;
          }
          else {
            uVar3 = *local_20;
            local_20 = local_20 + 1;
            if (uVar14 == 3) {
              uVar3 = (uint)(short)uVar3;
            }
            uVar20 = (int)uVar3 >> 0x1f;
            if (uVar14 == 4) {
              uVar3 = (uint)(char)uVar3;
              uVar20 = (int)uVar3 >> 0x1f;
            }
          }
          if ((int)uVar20 < 0) {
            bVar22 = uVar3 != 0;
            uVar3 = -uVar3;
            uVar20 = -(uint)bVar22 - uVar20;
            uVar7 = 0x2d;
LAB_00042ee6:
            local_74 = (undefined1 **)CONCAT31(local_74._1_3_,uVar7);
            local_78 = (undefined1 *)0x1;
          }
          else {
            if ((int)(uVar15 << 0x14) < 0) {
              uVar7 = 0x2b;
              goto LAB_00042ee6;
            }
            local_78 = (undefined1 *)0x0;
            if ((uVar15 & 1) != 0) {
              uVar7 = 0x20;
              goto LAB_00042ee6;
            }
          }
          goto LAB_00042faa;
        }
        if (uVar5 == 0x65) break;
        goto LAB_00042da2;
      }
      if (uVar5 == 0) {
        return iVar16;
      }
      bVar23 = SBORROW4(uVar5,0x45);
      bVar21 = (int)(uVar5 - 0x45) < 0;
      bVar22 = uVar5 == 0x45;
      if (!bVar22) goto code_r0x00042d64;
    }
    goto LAB_000430c4;
  }
  goto LAB_00042da2;
code_r0x00042d64:
  bVar23 = SBORROW4(uVar5,0x46);
  bVar21 = (int)(uVar5 - 0x46) < 0;
  bVar22 = uVar5 == 0x46;
  if (!bVar22) goto code_r0x00042d68;
  goto LAB_00042d52;
code_r0x00042d68:
  if (uVar5 != 0x47) {
LAB_00042da2:
    (*local_18)(uVar5,local_1c);
    iVar16 = iVar16 + 1;
    goto LAB_000430b4;
  }
LAB_000430c4:
  if (-1 < (int)(uVar15 << 0x1d)) {
    puVar18 = &DAT_00000006;
  }
  puVar11 = (undefined4 *)((uint)((int)local_20 + 7) & 0xfffffff8);
  uVar13 = *puVar11;
  local_20 = puVar11 + 2;
  if ((puVar11[1] & 0x80000000) == 0) {
    if ((int)(uVar15 << 0x14) < 0) {
      local_40 = &DAT_00043358;
    }
    else if ((uVar15 & 1) == 0) {
      local_40 = &DAT_00043360;
    }
    else {
      local_40 = &DAT_0004335c;
    }
  }
  else {
    local_40 = &DAT_00043354;
  }
  uVar14 = puVar11[1] & 0x7fffffff;
  if (uVar5 == 0x65) {
LAB_0004311e:
    if ((int)puVar18 < 0x11) {
      puVar12 = puVar18 + 1;
    }
    else {
      puVar12 = (undefined1 *)0x11;
    }
    FUN_00042b18(&local_3c,local_63 + 3,uVar13,uVar14,puVar12,0);
    local_6c = local_34;
    in_stack_ffffff84 = puVar18 + 1;
    local_2c = local_3c;
LAB_000431ec:
    in_stack_ffffff80 = (undefined1 **)0x0;
    local_78 = (undefined1 *)0x1;
    local_74 = local_38;
    local_6c = local_34;
    local_3c = local_2c;
  }
  else {
    if (uVar5 < 0x66) {
      if (uVar5 == 0x45) goto LAB_0004311e;
      if (uVar5 != 0x46) {
        if (uVar5 == 0x47) goto LAB_00043198;
        goto LAB_00043220;
      }
    }
    else if (uVar5 != 0x66) {
      if (uVar5 != 0x67) goto LAB_00043220;
LAB_00043198:
      if ((int)puVar18 < 1) {
        puVar18 = (undefined1 *)0x1;
      }
      puVar12 = puVar18;
      if (0x11 < (int)puVar18) {
        puVar12 = (undefined1 *)0x11;
      }
      FUN_00042b18(&local_3c,local_63 + 3,uVar13,uVar14,puVar12,0);
      local_6c = local_34;
      local_2c = local_3c;
      in_stack_ffffff80 = (undefined1 **)0x0;
      in_stack_ffffff84 = puVar18;
      if (-1 < (int)(uVar15 << 0x1c)) {
        puVar12 = local_34;
        if ((int)local_34 < (int)puVar18) goto LAB_000431d4;
        while ((1 < (int)in_stack_ffffff84 && (in_stack_ffffff84[local_3c - 1] == '0'))) {
          puVar12 = in_stack_ffffff84 + -1;
LAB_000431d4:
          in_stack_ffffff84 = puVar12;
        }
      }
      if (((int)puVar18 <= (int)local_38) || ((int)local_38 < -4)) goto LAB_000431ec;
      if ((int)local_38 < 1) {
        puVar18 = in_stack_ffffff84 + -(int)local_38;
        in_stack_ffffff80 = local_38;
LAB_00043210:
        in_stack_ffffff84 = puVar18;
      }
      else {
        puVar18 = (undefined1 *)((int)local_38 + 1);
        if ((int)in_stack_ffffff84 < (int)puVar18) goto LAB_00043210;
      }
      local_78 = (undefined1 *)((int)local_38 + (1 - (int)in_stack_ffffff80));
      local_74 = (undefined1 **)0x80000000;
      local_3c = local_2c;
      goto LAB_00043220;
    }
    local_74 = (undefined1 **)0x80000000;
    FUN_00042b18(&local_3c,local_63 + 3,uVar13,uVar14,puVar18,1);
    local_6c = local_34;
    in_stack_ffffff80 = (undefined1 **)0x0;
    local_2c = local_3c;
    in_stack_ffffff84 = local_34;
    if (local_30 == 0) {
      in_stack_ffffff84 = (undefined1 *)((int)local_38 + (int)(puVar18 + 1));
    }
    if (-1 < (int)puVar18 - (int)in_stack_ffffff84) {
      in_stack_ffffff80 = (undefined1 **)(-1 - ((int)puVar18 - (int)in_stack_ffffff84));
      in_stack_ffffff84 = puVar18 + 1;
    }
    local_78 = in_stack_ffffff84 + -(int)puVar18;
  }
LAB_00043220:
  if ((-1 < (int)(uVar15 << 0x1c)) && ((int)in_stack_ffffff84 <= (int)local_78)) {
    local_78 = (undefined1 *)0xffffffff;
  }
  local_61._0_1_ = 0;
  pcVar19 = local_63 + 2;
  if (local_74 != (undefined1 **)0x80000000) {
    local_3c = 2;
    local_38 = (undefined1 **)0x2b;
    if ((int)local_74 < 0) {
      local_74 = (undefined1 **)-(int)local_74;
      local_38 = (undefined1 **)0x2d;
    }
    while ((uVar5 = local_3c, local_3c = local_3c - 1, 0 < (int)uVar5 ||
           (local_74 != (undefined1 **)0x0))) {
      local_74 = (undefined1 **)rom_24F24(local_74,10);
      pcVar19 = pcVar19 + -1;
      *pcVar19 = extraout_r1 + '0';
    }
    pcVar19[-1] = (char)local_38;
    pcVar19 = pcVar19 + -2;
    *pcVar19 = (*param_1 & 0x20) + 0x45;
  }
  local_74 = (undefined1 **)(local_63 + (2 - (int)pcVar19));
  local_70 = (local_70 -
             (int)(in_stack_ffffff84 + ((int)local_78 >> 0x1f) + (uint)(*local_40 != '\0') +
                  (int)local_74)) - 1;
  if (-1 < (int)(uVar15 << 0xf)) {
    iVar6 = FUN_00043384(local_70,uVar15,local_1c,local_18);
    iVar16 = iVar6 + iVar16;
  }
  if (*local_40 != '\0') {
    (*local_18)(*local_40,local_1c);
    iVar16 = iVar16 + 1;
  }
  iVar6 = iVar16;
  puVar18 = in_stack_ffffff84;
  if ((int)(uVar15 << 0xf) < 0) {
    iVar6 = FUN_00043384(local_70,uVar15,local_1c,local_18);
    iVar6 = iVar6 + iVar16;
    puVar18 = in_stack_ffffff84;
  }
  while (iVar16 = iVar6, in_stack_ffffff84 = puVar18 + -1, 0 < (int)puVar18) {
    if (((int)in_stack_ffffff80 < 0) || ((int)local_6c <= (int)in_stack_ffffff80)) {
      uVar7 = 0x30;
    }
    else {
      uVar7 = *(undefined1 *)(local_2c + (int)in_stack_ffffff80);
    }
    (*local_18)(uVar7,local_1c);
    in_stack_ffffff80 = (undefined1 **)((int)in_stack_ffffff80 + 1);
    local_78 = local_78 + -1;
    iVar6 = iVar16 + 1;
    puVar18 = in_stack_ffffff84;
    if (local_78 == (undefined1 *)0x0) {
      (*local_18)(0x2e,local_1c);
      iVar6 = iVar16 + 2;
      puVar18 = in_stack_ffffff84;
    }
  }
  while (ppuVar4 = local_74, local_74 = (undefined1 **)((int)local_74 + -1), uVar5 = local_70,
        0 < (int)ppuVar4) {
    cVar2 = *pcVar19;
    pcVar19 = pcVar19 + 1;
    (*local_18)(cVar2,local_1c);
    iVar16 = iVar16 + 1;
  }
LAB_000430ae:
  iVar6 = FUN_00043364(uVar5,uVar15,local_1c,local_18);
  iVar16 = iVar6 + iVar16;
LAB_000430b4:
  param_1 = param_1 + 1;
  goto LAB_000430b6;
}

/* ==========================================================================
 * FUN_00043364   @ 0x00043364   (32 bytes)
 * called by : FUN_00042c70
 */

int FUN_00043364(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 << 0x12 < 0) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(0x20,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

/* ==========================================================================
 * FUN_00043384   @ 0x00043384   (44 bytes)
 * called by : FUN_00042c70
 */

int FUN_00043384(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (param_2 << 0xf < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if (-1 < param_2 << 0x12) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(uVar2,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

/* ==========================================================================
 * FUN_000433b0   @ 0x000433b0   (10 bytes)
 * called by : FUN_000429d4, FUN_000429fc
 */

void FUN_000433b0(undefined1 param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *param_2 = puVar1 + 1;
  *puVar1 = param_1;
  return;
}


/*############################################################################
 * LED AND OLED  (43 functions)
 *
 *   0x0002A69E  FUN_0002a69e  (112 B)
 *   0x0002ACE0  set_Update_OLED  (514 B)
 *   0x0002B1D4  set_Update_OLED_3  (58 B)
 *   0x0002B936  tx_failed_cnt  (402 B)
 *   0x0002C124  FUN_0002c124  (52 B)
 *   0x0002EAAC  Success_led_2second_2  (212 B)
 *   0x0002FA8E  RPT_STEP  (168 B)
 *   0x0002FF18  FUN_0002ff18  (380 B)
 *   0x00031244  FUN_00031244  (102 B)
 *   0x00031454  FUN_00031454  (62 B)
 *   0x00031492  FUN_00031492  (64 B)
 *   0x000314D2  FUN_000314d2  (46 B)
 *   0x00031500  FUN_00031500  (36 B)
 *   0x00031524  FUN_00031524  (68 B)
 *   0x00032892  FUN_00032892  (48 B)
 *   0x000328C2  FUN_000328c2  (46 B)
 *   0x000328F0  Success_led_2second  (82 B)
 *   0x00032942  FUN_00032942  (58 B)
 *   0x00032C34  Led_OLED  (254 B)
 *   0x00033F3C  delta_none  (52 B)
 *   0x0003468C  OLED_Init  (134 B)
 *   0x00036AAE  FUN_00036aae  (34 B)
 *   0x00036AD0  FUN_00036ad0  (34 B)
 *   0x00036CAA  FUN_00036caa  (20 B)
 *   0x00036D0E  FUN_00036d0e  (44 B)
 *   0x00036E88  FUN_00036e88  (48 B)
 *   0x00036EB8  FUN_00036eb8  (54 B)
 *   0x0003B5B6  FUN_0003b5b6  (48 B)
 *   0x0003BEB4  FUN_0003beb4  (86 B)
 *   0x0003C842  FUN_0003c842  (16 B)
 *   0x0003C852  FUN_0003c852  (52 B)
 *   0x0003C886  FUN_0003c886  (16 B)
 *   0x0003C896  FUN_0003c896  (32 B)
 *   0x0003C8DC  FUN_0003c8dc  (34 B)
 *   0x0003C90C  FUN_0003c90c  (32 B)
 *   0x0003C92C  FUN_0003c92c  (106 B)
 *   0x0003CE52  FUN_0003ce52  (10 B)
 *   0x0003D24A  FUN_0003d24a  (52 B)
 *   0x0003D27E  OLED_Clear  (50 B)
 *   0x0003D382  FUN_0003d382  (114 B)
 *   0x0003D3F4  FUN_0003d3f4  (276 B)
 *   0x0003D51E  FUN_0003d51e  (18 B)
 *   0x0003D530  FUN_0003d530  (22 B)
 ############################################################################*/

/* ==========================================================================
 * FUN_0002a69e   @ 0x0002a69e   (112 bytes)
 * called by : tx_failed_cnt
 * calls     : dbg_printf
 * string    : "try high rate............%d ,%d\r\n"
 */

void FUN_0002a69e(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = *DAT_0002a970;
  if (uVar2 < 500) {
    uVar2 = uVar2 + 1;
    *DAT_0002a970 = uVar2;
  }
  if (uVar2 == 100) {
    cVar1 = *(char *)(DAT_0002a8a4 + 4);
    if (cVar1 == '\x06') {
      iVar3 = DAT_0002a94c + 0x54;
    }
    else if (cVar1 == '\a') {
      iVar3 = DAT_0002a7cc + -0x9b;
    }
    else if (cVar1 == '\b') {
      iVar3 = 1000;
    }
    else if (cVar1 == '\t') {
      iVar3 = DAT_0002a7cc + 0x5f;
    }
    else if (cVar1 == '\n') {
      iVar3 = DAT_0002a7cc + 0xdc;
    }
    else {
      iVar3 = DAT_0002a9a0;
      if ((cVar1 != '\v') && (iVar3 = DAT_0002a978, cVar1 == '\f')) {
        iVar3 = DAT_0002a9a0 + 0x7d;
      }
    }
    *DAT_0002a974 = iVar3;
    dbg_printf(str_try_high_rate_d_d);
  }
  return;
}

/* ==========================================================================
 * set_Update_OLED   @ 0x0002ace0   (514 bytes)
 * called by : SLEEP, enter_BLE_normal_app_mode, f_usb_isConnected, system_mode
 * calls     : FUN_000328c2, FUN_0003b568, FUN_0003b5b6, FUN_0003b5f8, dbg_printf, force_24g_sleep, ... (+1 more)
 * string    : "set_Update_OLED--f_bat_low 1\r\n"
 * string    : "set_Update_OLED--f_bat_low 2\r\n"
 * string    : "f_bat_ll_low _ process ..\r\n"
 */

void set_Update_OLED(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort *puVar2;
  ushort *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  
  if ((*DAT_0002ae0c != '\0') && (*DAT_0002ae10 == '\0')) {
    return;
  }
  *DAT_0002ae0c = '\x04';
  FUN_0003b568(2,1,param_3,param_4,param_4);
  iVar8 = FUN_0003b5f8(2,1);
  FUN_0003b5b6(2);
  pcVar10 = DAT_0002ae1c;
  puVar2 = DAT_0002ae18;
  if (iVar8 == DAT_0002ae14) {
    iVar8 = 0;
  }
  uVar9 = (uint)*DAT_0002ae18 + iVar8 & 0xffff;
  *DAT_0002ae18 = (ushort)((uint)*DAT_0002ae18 + iVar8);
  cVar7 = *pcVar10;
  if ((cVar7 != '\0') && (*DAT_0002ae1c = cVar7 + -1, cVar7 != '\x01')) {
    return;
  }
  puVar3 = DAT_0002ae20;
  uVar11 = (uint)*DAT_0002ae20;
  if (uVar11 < uVar9) {
    uVar12 = uVar9 - uVar11;
  }
  else {
    uVar12 = uVar11 - uVar9;
  }
  if ((uVar12 & 0xffff) < 0x1e) {
    uVar9 = (uVar9 + uVar11 & 0xffff) >> 1;
    *puVar2 = (ushort)uVar9;
  }
  pbVar4 = DAT_0002ae24;
  uVar11 = 0;
  iVar8 = DAT_0002ade4 + -0xdc;
  *puVar3 = (ushort)uVar9;
  do {
    puVar6 = DAT_0002b050;
    pbVar5 = DAT_0002ae28;
    if ((int)(*(ushort *)(iVar8 + uVar11 * 2) - 0xf) <= (int)uVar9) {
      if (uVar11 < *pbVar4) {
        *DAT_0002ae28 = 0;
      }
      else {
        *pbVar4 = (byte)uVar11;
        if (99 < uVar11) {
          *pbVar4 = 100;
        }
        bVar1 = *pbVar5;
        *pbVar5 = bVar1 + 1;
        if (2 < (byte)(bVar1 + 1)) {
          *pbVar5 = 0;
          *DAT_0002ae2c = 1;
          *DAT_0002ae30 = 0x14;
        }
        dbg_printf(str_pGUpdate_OLED_Batt_vol_d + 2,*pbVar4);
        *DAT_0002b050 = 1;
      }
      break;
    }
    if ((uVar11 == 0x6e) && (*pbVar4 < 0x6f)) {
      *pbVar4 = 100;
      *puVar6 = 1;
    }
    uVar11 = uVar11 + 1 & 0xff;
  } while (uVar11 < 0x6f);
  iVar8 = DAT_0002b05c;
  if (*DAT_0002b054 == '\0') {
    if ((*DAT_0002b058 == '\0') && (0x4f < *pbVar4)) {
      cVar7 = *(char *)(DAT_0002b05c + 1) + -1;
      *(char *)(DAT_0002b05c + 1) = cVar7;
      if (cVar7 == '\0') {
        FUN_000328c2();
        *DAT_0002b058 = '\x01';
        puVar6 = DAT_0002b064;
        *(undefined1 *)(iVar8 + 1) = 3;
        *puVar6 = 1;
        *DAT_0002b068 = 0x14;
        pcVar10 = str_set_Update_OLED_f_bat_low_1;
LAB_0002aee4:
        dbg_printf(pcVar10);
      }
    }
    else if ((*DAT_0002b058 == '\0') || (0x4f < *pbVar4)) {
      *(undefined1 *)(DAT_0002b05c + 1) = 3;
    }
    else {
      cVar7 = *(char *)(DAT_0002b05c + 1) + -1;
      *(char *)(DAT_0002b05c + 1) = cVar7;
      if (cVar7 == '\0') {
        FUN_000328c2();
        *DAT_0002b058 = '\0';
        *DAT_0002b060 = '\0';
        puVar6 = DAT_0002b064;
        *(undefined1 *)(iVar8 + 1) = 3;
        *(undefined1 *)(iVar8 + 2) = 3;
        *puVar6 = 1;
        *DAT_0002b068 = 0x14;
        pcVar10 = str_set_Update_OLED_f_bat_low_2;
        goto LAB_0002aee4;
      }
    }
    pcVar10 = DAT_0002b060;
    if ((*DAT_0002b060 == '\0') && (99 < *pbVar4)) {
      cVar7 = *(char *)(iVar8 + 2) + -1;
      *(char *)(iVar8 + 2) = cVar7;
      if (cVar7 != '\0') goto LAB_0002af36;
      FUN_000328c2();
      *DAT_0002b060 = '\x01';
      *DAT_0002b058 = '\x01';
      goto LAB_0002af14;
    }
    if ((*DAT_0002b060 != '\0') && (*pbVar4 < 100)) {
      cVar7 = *(char *)(iVar8 + 2) + -1;
      *(char *)(iVar8 + 2) = cVar7;
      if (cVar7 != '\0') goto LAB_0002af36;
      *pcVar10 = '\0';
    }
  }
  else {
    *DAT_0002b058 = '\0';
    *DAT_0002b060 = '\0';
LAB_0002af14:
    *(undefined1 *)(iVar8 + 1) = 3;
  }
  *(undefined1 *)(iVar8 + 2) = 3;
LAB_0002af36:
  puVar6 = DAT_0002b0b4;
  *DAT_0002b0ac = 3;
  *DAT_0002b0b0 = 0;
  *puVar6 = 4;
  if (*DAT_0002b060 != '\0') {
    dbg_printf(str_f_bat_ll_low_process);
    *DAT_0002b0d4 = 0;
    cVar7 = *DAT_0002b0d8;
    if (cVar7 == '\0') {
      force_24g_sleep();
      return;
    }
    if ((cVar7 == '\x01') || (cVar7 == '\x02')) {
      force_ble_sleep();
    }
  }
  return;
}

/* ==========================================================================
 * set_Update_OLED_3   @ 0x0002b1d4   (58 bytes)
 * calls     : OLED_Init, dbg_printf, rom_07342
 * string    : "set_Update_OLED"
 * string    : "%s \r\n"
 */

void set_Update_OLED_3(void)

{
  dbg_printf(str_s_3,DAT_0002b554);
  OLED_Init();
  *DAT_0002b560 = 1;
  if (((*DAT_0002b54c == '\x01') || (*DAT_0002b54c == '\x02')) && (*DAT_0002b520 == '\0')) {
    *DAT_0002b530 = 0xfa;
    rom_07342(DAT_0002b564,3,1);
  }
  return;
}

/* ==========================================================================
 * tx_failed_cnt   @ 0x0002b936   (402 bytes)
 * called by : FUN_0002f31c
 * calls     : FUN_0002a69e, FUN_0002b3ac, FUN_00031244, FUN_000312aa, dbg_printf, rom_24F9C
 * string    : "tx_failed_cnt =%d,%d,Utc_Poll=%d,%d\r\n"
 */

void tx_failed_cnt(void)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined1 uVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  
  if (*DAT_0002bc20 != '\0') {
    FUN_0002b3ac();
    return;
  }
  if (*DAT_0002bc24 != '\0') {
    return;
  }
  bVar5 = *DAT_0002bc28;
  if ((bVar5 < 0x10) && (*DAT_0002bc28 = bVar5 + 1, (byte)(bVar5 + 1) < 0xb)) {
LAB_0002bca6:
    FUN_000312aa();
  }
  else {
    pcVar3 = DAT_0002bc34;
    iVar2 = DAT_0002bbf0;
    if (((*DAT_0002bc2c == '\0') &&
        (((*DAT_0002bc30 == '\0' && (*DAT_0002bc38 == '\0')) && (*DAT_0002bc3c == '\0')))) &&
       (((*DAT_0002bc34 == '\0' && (*DAT_0002bc40 == '\0')) && (*DAT_0002bc44 == '\0')))) {
      *(undefined1 *)(DAT_0002bbf0 + 10) = 0;
      bVar5 = *(byte *)(iVar2 + 0xd);
      if (bVar5 != 0xff) {
        bVar5 = bVar5 + 1;
        *(byte *)(iVar2 + 0xd) = bVar5;
      }
      if (3 < bVar5) {
        return;
      }
    }
    else {
      *(undefined1 *)(DAT_0002bbf0 + 0xd) = 0;
    }
    puVar10 = DAT_0002bc54;
    piVar4 = DAT_0002bc4c;
    bVar5 = *(byte *)(DAT_0002bbf0 + 3);
    if (((*DAT_0002bc30 != '\0') && (5 < bVar5)) || (7 < bVar5)) {
      iVar9 = DAT_0002bc50;
      if (*DAT_0002bc48 == '\x01') {
        iVar9 = DAT_0002bc50 + 0xfa;
      }
      *DAT_0002bc4c = iVar9;
      dbg_printf(str_tx_failed_cnt_d_d_Utc_Poll_d_d,*(undefined1 *)(iVar2 + 10),bVar5,*piVar4,
                 *puVar10);
      *puVar10 = 0;
      *(undefined2 *)(iVar2 + 0xe) = 0;
      *(undefined1 *)(iVar2 + 10) = 0;
      return;
    }
    FUN_0002a69e();
    iVar9 = DAT_0002bc80;
    iVar11 = DAT_0002bbf0 + 0x18;
    if (*pcVar3 == '\0') {
      if (*DAT_0002bc44 == '\0') {
        if ((((*DAT_0002bc2c == '\0') && (*DAT_0002bc30 == '\0')) && (*DAT_0002bc38 == '\0')) &&
           (*DAT_0002bc3c == '\0')) {
          return;
        }
        FUN_00031244();
        bVar5 = *(byte *)(iVar2 + 1);
        iVar6 = (uint)bVar5 * 8;
        *(undefined1 *)(iVar9 + iVar6) = *DAT_0002bc8c;
        iVar6 = iVar6 + iVar9;
        uVar1 = *DAT_0002bc90;
        *(char *)(iVar6 + 1) = (char)uVar1;
        *(char *)(iVar6 + 2) = (char)((ushort)uVar1 >> 8);
        uVar1 = *DAT_0002bc94;
        *(char *)(iVar6 + 3) = (char)uVar1;
        *(char *)(iVar6 + 4) = (char)((ushort)uVar1 >> 8);
        *(undefined1 *)(iVar6 + 5) = *DAT_0002bc98;
        *(undefined1 *)(iVar6 + 6) = *DAT_0002bc9c;
        *(undefined1 *)(iVar11 + (uint)bVar5) = 7;
        *(byte *)(iVar2 + 1) = bVar5 + 1 & 7;
        *(char *)(iVar2 + 3) = *(char *)(iVar2 + 3) + '\x01';
        if (*(byte *)(iVar2 + 10) < 0xfa) {
          *(byte *)(iVar2 + 10) = *(byte *)(iVar2 + 10) + 1;
        }
        goto LAB_0002bca6;
      }
      *DAT_0002bc44 = '\0';
      puVar10 = DAT_0002bc88;
      uVar7 = (uint)*(byte *)(iVar2 + 1);
      *(undefined1 *)(iVar9 + uVar7 * 8) = *DAT_0002bc88;
      *(undefined1 *)(uVar7 * 8 + iVar9 + 1) = puVar10[1];
      uVar8 = 2;
    }
    else {
      *pcVar3 = '\0';
      puVar10 = DAT_0002bc84 + 1;
      iVar6 = (uint)*(byte *)(iVar2 + 1) * 8;
      *(undefined1 *)(iVar9 + iVar6) = *DAT_0002bc84;
      rom_24F9C(iVar6 + iVar9 + 2,puVar10,6);
      uVar7 = (uint)*(byte *)(iVar2 + 1);
      uVar8 = 8;
    }
    *(undefined1 *)(iVar11 + uVar7) = uVar8;
    *(char *)(iVar2 + 3) = *(char *)(iVar2 + 3) + '\x01';
    *(byte *)(iVar2 + 1) = (char)uVar7 + 1U & 7;
  }
  return;
}

/* ==========================================================================
 * FUN_0002c124   @ 0x0002c124   (52 bytes)
 * called by : FUN_00031454, FUN_00031500, FUN_00031524
 * calls     : FUN_0003ee6e, rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_0002c124(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0003ee6e(0x47);
  iVar2 = rom_06EF4(DAT_0002c2d0,uVar1,param_1 * 0x100 + 3,0x278);
  *(short *)(iVar2 + 2) = (short)param_2;
  rom_24F9C(iVar2 + 4,param_3,param_2);
  rom_06F26(iVar2);
  return;
}

/* ==========================================================================
 * Success_led_2second_2   @ 0x0002eaac   (212 bytes)
 * calls     : CHRG, FUN_0003262c, FUN_00032658, FUN_00032942, FUN_0003beb4, ReLink, ... (+4 more)
 * string    : "Success_led_2second 1=  %x,\r\n"
 * string    : "set_Update_OLED--Success_led_2second \r\n"
 */

undefined4 Success_led_2second_2(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = PTR_DAT_0002ed1c;
  puVar3 = PTR_DAT_0002ed1c + 5;
  if (*(int *)PTR_DAT_0002edd8 * 0x400000 < 0) {
    *(uint *)PTR_DAT_0002edd8 = *(uint *)PTR_DAT_0002edd8 & 0xfffffdff;
    dbg_printf(str_Success_led_2second_1_x,*PTR_DAT_0002eddc);
    rom_07342(puVar2 + 0xc,3,200);
    FUN_00032658();
    rom_073D4(puVar3,3);
    if (*DAT_0002ee00 == '\0') {
      CHRG();
    }
    else {
      ReLink();
    }
    delta_none();
    dbg_printf(str_set_Update_OLED_Success_led_2second);
    *PTR_DAT_0002ee2c = 0;
    *PTR_DAT_0002ee30 = 0;
    FUN_0003beb4();
    goto LAB_0002eb66;
  }
  rom_07342(puVar3,3,0x19);
  if (*PTR_DAT_0002ee34 != '\0' || *PTR_DAT_0002ee38 != '\0') {
    return 0;
  }
  FUN_0003262c();
  puVar2 = PTR_DAT_0002ee44;
  if (*DAT_0002ee3c == '\x02') {
    cVar1 = *PTR_DAT_0002ee44;
    *PTR_DAT_0002ee44 = cVar1 + 1U;
    if ((byte)(cVar1 + 1U) < 2) goto LAB_0002eb66;
    *puVar2 = 0;
    puVar2 = PTR_DAT_0002ee48;
    cVar1 = PTR_DAT_0002ee48[2];
    PTR_DAT_0002ee48[2] = cVar1 + 1U;
    if ((byte)puVar2[3] < (byte)(cVar1 + 1U)) goto LAB_0002eb66;
  }
  else if (*DAT_0002ee40 != '\0') goto LAB_0002eb66;
  FUN_00032942();
LAB_0002eb66:
  if (*PTR_DAT_0002ee4c != '\0') {
    *PTR_DAT_0002ee50 = 0;
    rom_073D4(PTR_DAT_0002ed1c + 6,3);
  }
  return 0;
}

/* ==========================================================================
 * RPT_STEP   @ 0x0002fa8e   (168 bytes)
 * calls     : FUN_00036c8e, FUN_00036caa, FUN_00036e88, OLED_Init, Set_Report_Data, dbg_printf_2, ... (+1 more)
 * string    : "RPT_STEP-9L:"
 * string    : "RPT_STEP-9S:"
 */

void RPT_STEP(void)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)PTR_DAT_0002fc94;
  *(uint *)PTR_DAT_0002fc94 = uVar5 & 0x70;
  pcVar1 = DAT_0002fc9c;
  if (-1 < (int)((uVar5 & 0x70) << 0x19)) {
    if (*DAT_0002fc9c != '\0') {
      return;
    }
    FUN_00036caa();
    FUN_00036c8e();
    return;
  }
  FUN_00036e88();
  pcVar2 = DAT_0002fca4;
  *pcVar1 = '\x06';
  pbVar3 = DAT_0002fcd4;
  if ((*pcVar2 == '8') && ((uint)(byte)pcVar2[1] == *DAT_0002fcd8 + 1)) {
    *DAT_0002fcd8 = (byte)(*DAT_0002fcd8 + 1);
    iVar4 = DAT_0002fcdc;
    if (*pbVar3 < 0x1e) {
      rom_24F9C(*(undefined4 *)(DAT_0002fcdc + 4),pcVar2 + 2);
      dbg_printf_2(str_RPT_STEP_9S,DAT_0002fca4,*pbVar3 + 2);
      *pbVar3 = 0;
    }
    else {
      rom_24F9C(*(undefined4 *)(DAT_0002fcdc + 4),pcVar2 + 2,0x1e);
      pcVar1 = DAT_0002fca4;
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + 0x1e;
      *pbVar3 = *pbVar3 - 0x1e;
      dbg_printf_2(str_RPT_STEP_9L,pcVar1,0x20);
      if (*pbVar3 != 0) {
        return;
      }
    }
    OLED_Init();
    *PTR_DAT_0002fd08 = *(undefined1 *)(iVar4 + 9);
    *(int *)(iVar4 + 4) = DAT_0002fcdc + 9;
    Set_Report_Data();
    *DAT_0002fca0 = 10;
    return;
  }
  return;
}

/* ==========================================================================
 * FUN_0002ff18   @ 0x0002ff18   (380 bytes)
 * calls     : FUN_00031784, FUN_000369a0, FUN_000369ac, FUN_00036c8e, FUN_00036caa, FUN_00036d0e, ... (+5 more)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ff18(void)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  char *pcVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  char *pcVar14;
  
  puVar4 = PTR_DAT_000301f8;
  puVar5 = PTR_DAT_000301f0;
  iVar13 = *(int *)PTR_DAT_000301f8;
  if (iVar13 * 0x2000000 < 0) {
    FUN_00036e88();
    pcVar8 = _DAT_00030204;
    pcVar14 = _DAT_00030200;
    pcVar7 = _DAT_000301fc;
    if (*_DAT_000301fc == '6') {
      *puVar5 = 5;
      *pcVar7 = 'F';
      cVar1 = pcVar7[4];
    }
    else {
      if (*_DAT_000301fc != '7') {
        if (*_DAT_00030204 != '\0') {
          *puVar5 = 0;
          *pcVar8 = '\0';
        }
        *(undefined4 *)(PTR_DAT_000301f8 + -0x28) = 0x80;
        *(undefined4 *)puVar4 = 0x40;
        goto LAB_0002ff56;
      }
      *puVar5 = 7;
      *pcVar7 = 'G';
      cVar1 = pcVar7[4];
      *_DAT_0003021c = cVar1;
    }
    if (cVar1 != '\0') {
      if (pcVar7[1] != '\t') {
        *pcVar14 = '\0';
        pcVar14 = _DAT_00030210;
      }
      *pcVar14 = cVar1 + -1;
    }
    *_DAT_00030214 = 8;
    rom_24FEC(pcVar7 + 5,3);
    iVar13 = _DAT_00030218;
    *(char *)(_DAT_00030218 + 2) = pcVar7[1];
    *(char *)(iVar13 + 3) = pcVar7[2];
    *(char *)(iVar13 + 8) = pcVar7[3];
    OLED_Init();
    *_DAT_0003020c = 6;
    *PTR_DAT_00030154 = 200;
    puVar5 = PTR_DAT_000301f8;
    *(undefined4 *)(PTR_DAT_000301f8 + -0x28) = 0x80;
    *(undefined4 *)puVar4 = 0x40;
    *PTR_DAT_00030174 = 0;
    *_DAT_00030204 = '\0';
    *(undefined4 *)(puVar5 + -0x2c) = 1;
  }
  else {
LAB_0002ff56:
    puVar6 = PTR_DAT_000301f8;
    if (iVar13 * 0x4000000 < 0) {
      *(undefined4 *)(PTR_DAT_000301f8 + -0x28) = 0xa0;
      *(undefined4 *)puVar4 = 0x20;
      puVar4 = PTR_DAT_00030174;
      *puVar5 = 0;
      *puVar4 = 0;
      *PTR_DAT_00030144 = 0;
      puVar10 = _DAT_0003020c;
      *_DAT_00030208 = 0;
      *puVar10 = 6;
      return;
    }
    if (iVar13 << 0x1b < 0) {
      *(undefined4 *)(PTR_DAT_000301f8 + -0x28) = 0x80;
      *(undefined4 *)(puVar6 + -0x28) = 0xa0;
      FUN_000369ac();
      FUN_00031784(3);
      FUN_000369a0();
      *(undefined4 *)puVar4 = 0x10;
      pbVar9 = _DAT_00030208;
      if (*(short *)PTR_DAT_00030178 != 0) {
        if (*_DAT_00030208 < 4) {
          if ((PTR_DAT_0003012c[0x16] == '\x01') || (PTR_DAT_0003012c[0x16] == '\x02')) {
            time_sensor_invalid();
          }
          if (*_DAT_00030220 != '\0') {
            *_DAT_00030220 = '\0';
            puVar12 = _DAT_00030228;
            puVar11 = _DAT_00030224;
            pcVar7 = _DAT_000301fc;
            uVar3 = *_DAT_00030224;
            _DAT_000301fc[2] = (char)uVar3;
            pcVar7[3] = (char)((ushort)uVar3 >> 8);
            uVar3 = *puVar12;
            pcVar7[4] = (char)uVar3;
            pcVar7[5] = (char)((ushort)uVar3 >> 8);
            *puVar11 = 0;
            *puVar12 = 0;
          }
        }
        bVar2 = *pbVar9;
        if ((bVar2 == 0) || (*pbVar9 = bVar2 - 1, bVar2 == 1)) {
          FUN_00036caa();
          FUN_00036c8e();
        }
        FUN_00031784(0x14);
        FUN_00036d0e(8);
        return;
      }
      dbg_printf_2(str_RETR_fail,_DAT_000301fc,8);
      *(undefined2 *)PTR_DAT_0003017c = 0;
      puVar4 = PTR_DAT_00030174;
      *puVar5 = 0;
      *puVar4 = 0;
      return;
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00031244   @ 0x00031244   (102 bytes)
 * called by : FUN_000358b6, FUN_0003870a, tx_failed_cnt
 */

void FUN_00031244(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  
  puVar5 = DAT_00031580;
  puVar4 = DAT_0003157c;
  puVar3 = DAT_00031574;
  uVar1 = *DAT_00031580;
  if ((*DAT_0003157c != 0 || uVar1 != 0) && (*DAT_00031584 == '\0')) {
    iVar6 = (((int)(short)*DAT_0003157c + (uint)*DAT_0003156c) - (uint)*DAT_00031574) * 0x10000;
    uVar2 = (ushort)((uint)iVar6 >> 0x10);
    *DAT_0003156c = uVar2;
    iVar6 = (iVar6 >> 0x10) - (iVar6 >> 0x1f);
    uVar2 = (short)(iVar6 >> 1) + (uVar2 - ((ushort)iVar6 & 0xfffe));
    *puVar4 = uVar2;
    *puVar3 = uVar2;
    puVar3 = DAT_00031578;
    iVar6 = (((int)(short)uVar1 + (uint)*DAT_00031570) - (uint)*DAT_00031578) * 0x10000;
    uVar1 = (ushort)((uint)iVar6 >> 0x10);
    *DAT_00031570 = uVar1;
    iVar6 = (iVar6 >> 0x10) - (iVar6 >> 0x1f);
    uVar1 = (short)(iVar6 >> 1) + (uVar1 - ((ushort)iVar6 & 0xfffe));
    *puVar5 = uVar1;
    *puVar3 = uVar1;
  }
  return;
}

/* ==========================================================================
 * FUN_00031454   @ 0x00031454   (62 bytes)
 * calls     : FUN_0002c124
 */

void FUN_00031454(undefined1 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  
  puVar1 = DAT_0003168c;
  *DAT_0003168c = 0x10;
  puVar1[1] = 0x50;
  puVar1[2] = param_1;
  pcVar2 = DAT_00031690;
  puVar1[3] = param_2;
  if ((*pcVar2 == '\0') || (*DAT_00031614 != '\0')) {
    *DAT_00031694 = 1;
    *DAT_00031698 = 1;
  }
  else {
    FUN_0002c124(0,4,DAT_0003168c);
  }
  *DAT_0003169c = 8;
  return;
}

/* ==========================================================================
 * FUN_00031492   @ 0x00031492   (64 bytes)
 * called by : Led_OLED
 */

void FUN_00031492(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = DAT_000316a4;
  pcVar3 = DAT_000316a0;
  pcVar2 = DAT_000315dc;
  cVar1 = *DAT_000316a0;
  *DAT_000315dc = *DAT_000316a0;
  pcVar2[1] = '1';
  if (cVar1 == '\0') {
    pcVar2[2] = pcVar4[3];
    pcVar2[3] = pcVar4[2];
    *pcVar3 = '\x01';
  }
  else {
    pcVar2[2] = pcVar4[1];
    pcVar2[3] = *pcVar4;
    *pcVar3 = '\0';
  }
  *DAT_0003169c = 8;
  *DAT_000315c0 = 1;
  *DAT_00031698 = 1;
  return;
}

/* ==========================================================================
 * FUN_000314d2   @ 0x000314d2   (46 bytes)
 * called by : Led_OLED, SLEEP
 */

void FUN_000314d2(undefined1 param_1)

{
  undefined1 *puVar1;
  char *pcVar2;
  undefined1 *puVar3;
  
  pcVar2 = DAT_00031694;
  puVar1 = DAT_0003168c;
  puVar3 = DAT_0003169c;
  if (*DAT_00031694 == '\0') {
    *DAT_0003168c = 0x10;
    puVar1[1] = 0x40;
    puVar1[2] = param_1;
    puVar1[3] = 'd' - *DAT_000316a8;
    *pcVar2 = '\x01';
    puVar3 = DAT_00031698;
  }
  *puVar3 = 1;
  return;
}

/* ==========================================================================
 * FUN_00031500   @ 0x00031500   (36 bytes)
 * called by : Led_OLED
 * calls     : FUN_0002c124
 */

void FUN_00031500(undefined1 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_000315dc;
  *DAT_000315dc = 0x10;
  puVar1[1] = 0x40;
  puVar1[2] = param_1;
  puVar1[3] = 'd' - *DAT_000316a8;
  FUN_0002c124(0,4,puVar1);
  return;
}

/* ==========================================================================
 * FUN_00031524   @ 0x00031524   (68 bytes)
 * calls     : FUN_0002c124
 */

void FUN_00031524(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  puVar2 = DAT_000315dc;
  *DAT_000315dc = 0x10;
  puVar2[1] = 0x10;
  puVar2[2] = *(undefined1 *)(DAT_000316ac + 0xd);
  puVar2[3] = 0;
  cVar1 = *DAT_00031690;
  if ((cVar1 == '\0') || (*DAT_00031614 != '\0')) {
    *DAT_000315c0 = 1;
  }
  else if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*DAT_00031614 == '\0')) {
    FUN_0002c124(0,4,DAT_000315dc);
    return;
  }
  return;
}

/* ==========================================================================
 * FUN_00032892   @ 0x00032892   (48 bytes)
 * called by : FUN_000328c2, FUN_00035abc, FUN_00035b08, LightUp_Mode_Led, SLEEP, Success_led_2second, ... (+2 more)
 * calls     : FUN_00032886
 */

void FUN_00032892(void)

{
  *DAT_000329e4 = 0;
  FUN_00032886(0);
  *DAT_00032a48 = 0;
  *DAT_00032a90 = 0;
  *DAT_00032a58 = 0;
  *DAT_00032a60 = 0;
  *DAT_00032a94 = 0;
  *DAT_00032a98 = 0;
  *DAT_00032a64 = 0;
  *DAT_00032a9c = 0;
  return;
}

/* ==========================================================================
 * FUN_000328c2   @ 0x000328c2   (46 bytes)
 * called by : set_Update_OLED
 * calls     : FUN_00032892, ble_alert_led_stop, dbg_printf
 * string    : "alert led stopping\r\n"
 */

void FUN_000328c2(void)

{
  if (((*DAT_000329f0 == '\x01') || (*DAT_000329f0 == '\x02')) && (*DAT_000329ec == '\0')) {
    ble_alert_led_stop();
  }
  else {
    FUN_00032892();
  }
  *DAT_00032a64 = 0;
  dbg_printf(str_alert_led_stopping);
  return;
}

/* ==========================================================================
 * Success_led_2second   @ 0x000328f0   (82 bytes)
 * called by : LightUp_Mode_Led, USNDP_status_2, f_reconnect_24G, f_usb_isConnected
 * calls     : FUN_0003262c, FUN_00032658, FUN_00032892, FUN_0003c8b6, FUN_0003cf7c, OLED_Clear, ... (+3 more)
 * string    : "Success_led_2second---Led_Mode\r\n"
 * string    : "set_Update_OLED--Success_led_2second \r\n"
 */

void Success_led_2second(void)

{
  FUN_00032892();
  *DAT_00032a58 = 0;
  *DAT_00032a5c = 0;
  *DAT_00032a50 = 8;
  *DAT_00032a54 = 8;
  FUN_0003262c();
  FUN_00032658();
  *DAT_00032a64 = 0x3d;
  dbg_printf(str_Success_led_2second_Led_Mode);
  FUN_0003c8b6();
  OLED_Clear();
  FUN_0003cf7c();
  dbg_printf(str_set_Update_OLED_Success_led_2second_2);
  delta_none();
  *DAT_00032b04 = 400;
  OLED_Init();
  return;
}

/* ==========================================================================
 * FUN_00032942   @ 0x00032942   (58 bytes)
 * called by : Success_led_2second_2
 * calls     : FUN_00032620, FUN_00032658, FUN_0003ce52, Pairing, ReLinking
 */

void FUN_00032942(void)

{
  byte bVar1;
  
  bVar1 = *DAT_00032a8c;
  *DAT_00032a8c = bVar1 ^ 1;
  *DAT_00032b04 = 400;
  if (((bVar1 ^ 1) & 1) == 0) {
    FUN_00032620();
    FUN_0003ce52();
    return;
  }
  FUN_00032658();
  if (*DAT_00032b08 != '\x02') {
    Pairing();
    return;
  }
  ReLinking();
  return;
}

/* ==========================================================================
 * Led_OLED   @ 0x00032c34   (254 bytes)
 * called by : system_mode
 * calls     : FUN_00031492, FUN_000314d2, FUN_00031500, dbg_printf
 * string    : "Led_OLED ==5 !\r\n"
 * string    : "Led_OLED ==changing !\r\n"
 */

void Led_OLED(void)

{
  undefined2 *puVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  char cVar7;
  
  if (*DAT_00032e30 != '\0') {
    return;
  }
  if ((*DAT_00032d5c == '\0') || (*DAT_00032d60 != '\0')) {
    cVar7 = '\b';
  }
  else {
    cVar7 = '\x10';
  }
  *DAT_00032e30 = cVar7;
  pcVar5 = DAT_00032e48;
  pcVar4 = DAT_00032e40;
  pcVar3 = DAT_00032e3c;
  pcVar2 = DAT_00032e38;
  if (*DAT_00032e34 != '\0') {
    FUN_00031492();
    return;
  }
  if ((*DAT_00032e38 == '\0') && (*DAT_00032e44 == '\0')) {
    if (*DAT_00032e40 == '\0') {
      FUN_000314d2(1);
    }
    puVar1 = DAT_00032d98;
    if (*DAT_00032d5c == '\0') {
      return;
    }
    if (*DAT_00032d60 != '\0') {
      return;
    }
    if (*DAT_00032e4c == '\0') {
      return;
    }
    if (*DAT_00032e50 == '\0') {
      return;
    }
    *DAT_00032d50 = 1;
    *pcVar3 = '\0';
    *puVar1 = 3;
    *DAT_00032d54 = 1;
    dbg_printf(str_Led_OLED_5);
    *DAT_00032d58 = 0x3e;
    return;
  }
  if (*DAT_00032e3c != '\0') {
    return;
  }
  if (*DAT_00032e48 == '\0') {
    *DAT_00032d50 = 3;
    *DAT_00032d98 = 2;
    *DAT_00032d54 = 1;
    dbg_printf(str_Led_OLED_changing);
    *DAT_00032d58 = 0x3e;
    if (*pcVar5 == '\0') {
      cVar7 = *pcVar4;
      if (((cVar7 == '\x01') || (cVar7 == '\x02')) && (*pcVar2 == '\0')) {
        uVar6 = 3;
        goto LAB_00032d2c;
      }
      uVar6 = 3;
      goto LAB_00032d24;
    }
  }
  cVar7 = *pcVar4;
  if (((cVar7 == '\x01') || (cVar7 == '\x02')) && (*pcVar2 == '\0')) {
    uVar6 = 2;
LAB_00032d2c:
    FUN_00031500(uVar6);
    return;
  }
  uVar6 = 2;
LAB_00032d24:
  FUN_000314d2(uVar6);
  return;
}

/* ==========================================================================
 * delta_none   @ 0x00033f3c   (52 bytes)
 * called by : FUN_0003cf7c, FUN_0003d2b0, Success_led_2second, Success_led_2second_2
 * calls     : FUN_0003443a, dbg_printf
 * string    : "delta_none =%x\r\n"
 */

void delta_none(void)

{
  if ((*DAT_00033fd8 != '\0') && (*DAT_00033fb4 != '\0')) {
    if ((*(uint *)(DAT_00033f70 + 0x6c) & 1) == 0) {
      FUN_0003443a();
    }
    dbg_printf(str_delta_none_x);
    *DAT_00033ff4 = 0;
    *DAT_00033ff8 = 0;
  }
  return;
}

/* ==========================================================================
 * OLED_Init   @ 0x0003468c   (134 bytes)
 * called by : Detect_FULL_IN, FUN_0002aa5c, FUN_0002ac0e, FUN_0002ff18, FUN_000333f0, HID_RQT_Get_Protocol, ... (+12 more)
 * calls     : FUN_00039a84, FUN_0003beb4, FUN_0003c8b6, FUN_0003cf7c, OLED_Clear, dbg_printf
 * string    : "OLED_Init 3\r\n"
 */

void OLED_Init(void)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  short sVar4;
  ushort uVar5;
  
  if (*DAT_00034a64 != '\0') {
    *DAT_00034a64 = '\0';
    FUN_0003c8b6();
    OLED_Clear();
    dbg_printf(str_OLED_Init_3);
    FUN_0003cf7c();
    FUN_0003beb4();
    *DAT_00034a78 = 0;
  }
  *DAT_00034a7c = 0x78;
  *DAT_00034a80 = 5;
  *DAT_00034a84 = 400;
  FUN_00039a84(0x32,2);
  psVar2 = DAT_00034a8c;
  iVar1 = DAT_00034a88;
  sVar4 = (ushort)*(byte *)(DAT_00034a88 + 0x10) * 0x7e;
  if (sVar4 == 0) {
    sVar4 = 2;
  }
  *DAT_00034a8c = sVar4;
  psVar3 = DAT_00034a94;
  if (*DAT_00034a90 == '\0') {
    *DAT_00034a98 = 0;
  }
  uVar5 = (ushort)(*(byte *)(iVar1 + 0xb) >> 4) << 4 | (ushort)(*(byte *)(iVar1 + 0xc) >> 4);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  *psVar3 = uVar5 * 0xef + *psVar2;
  return;
}

/* ==========================================================================
 * FUN_00036aae   @ 0x00036aae   (34 bytes)
 * called by : FUN_00036e88, FUN_00036eb8
 */

void FUN_00036aae(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00036d84;
  *(undefined4 *)(DAT_00036d84 + 0xd8) = 0x40;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(char *)(param_1 + uVar2) = (char)*(undefined4 *)(iVar1 + 0xdc);
  }
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * FUN_00036ad0   @ 0x00036ad0   (34 bytes)
 * called by : FUN_00036d0e, FUN_00036d3a, FUN_00036e0c
 */

void FUN_00036ad0(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00036d84;
  *(undefined4 *)(DAT_00036d84 + 0xd8) = 0x60;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(uint *)(iVar1 + 0xdc) = (uint)*(byte *)(param_1 + uVar2);
  }
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * FUN_00036caa   @ 0x00036caa   (20 bytes)
 * called by : FUN_0002f92a, FUN_0002fc1e, FUN_0002ff18, RPT_STEP, SLEEP, ch_frequency, ... (+1 more)
 */

void FUN_00036caa(void)

{
  *DAT_00036da8 = *DAT_00036da8 + 1 & 3;
  *DAT_00036db0 = 6;
  return;
}

/* ==========================================================================
 * FUN_00036d0e   @ 0x00036d0e   (44 bytes)
 * called by : FUN_0002ff18, SLEEP
 * calls     : FUN_00031784, FUN_00036ad0
 */

void FUN_00036d0e(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00036d84;
  *(undefined4 *)(DAT_00036d84 + 0xd4) = 1;
  *(undefined4 *)(iVar1 + 0xd8) = 0xa0;
  *(undefined4 *)(iVar1 + 0xd8) = 0x80;
  *DAT_00036db4 = 0x7e;
  FUN_00036ad0(DAT_00036db8,param_1);
  FUN_00031784(10);
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  return;
}

/* ==========================================================================
 * FUN_00036e88   @ 0x00036e88   (48 bytes)
 * called by : FUN_0002ff18, LightUp_Mode_Led, RPT_STEP
 * calls     : FUN_00036aae
 */

void FUN_00036e88(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  iVar1 = DAT_00036f1c;
  puVar3 = (uint *)(DAT_00036f1c + 0x40);
  do {
    if (0x20 < (*(uint *)(iVar1 + 0x50) & 0xff)) {
      *(undefined4 *)(DAT_00036f1c + 0x18) = 0x80;
      break;
    }
    FUN_00036aae(DAT_00036f20);
    uVar2 = *puVar3;
    param_1 = uVar2 & 0xff;
  } while ((uVar2 & 0xf) >> 1 != 7);
  *puVar3 = param_1;
  return;
}

/* ==========================================================================
 * FUN_00036eb8   @ 0x00036eb8   (54 bytes)
 * calls     : FUN_00036aae
 */

void FUN_00036eb8(uint param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = DAT_00036f1c;
  puVar2 = (uint *)(DAT_00036f1c + 0x40);
  if ((int)(*puVar2 << 0x19) < 0) {
    do {
      if (0x20 < (*(uint *)(iVar1 + 0x50) & 0xff)) {
        *(undefined4 *)(DAT_00036f1c + 0x18) = 0x80;
        break;
      }
      FUN_00036aae(DAT_00036f20);
      param_1 = *puVar2 & 0xff;
    } while ((*puVar2 & 0xf) >> 1 != 7);
    *puVar2 = param_1;
  }
  return;
}

/* ==========================================================================
 * FUN_0003b5b6   @ 0x0003b5b6   (48 bytes)
 * called by : set_Update_OLED
 * calls     : FUN_00039a84
 */

void FUN_0003b5b6(char param_1)

{
  uint *puVar1;
  int iVar2;
  
  FUN_00039a84(param_1 + '0',0,2);
  *DAT_0003b6bc = *DAT_0003b6bc & 0xfffffff8;
  puVar1 = DAT_0003b6c4;
  *DAT_0003b6c4 = *DAT_0003b6c4 & ~((int)DAT_0003b6c4 >> 0xf);
  iVar2 = (int)puVar1 * 0x20000;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | iVar2 >> 0xd;
  return;
}

/* ==========================================================================
 * FUN_0003beb4   @ 0x0003beb4   (86 bytes)
 * called by : OLED_Init, SLEEP, Success_led_2second_2, enter_BLE_normal_app_mode, exist
 */

void FUN_0003beb4(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0003bf98;
  *DAT_0003bf98 = *DAT_0003bf98 | 0x40;
  if ((((*DAT_0003bf9c != '\x01') && (*DAT_0003bf9c != '\x02')) || (*DAT_0003bfa0 != '\0')) ||
     (uVar2 = 0x40, *DAT_0003bfa0 != '\0')) {
    uVar2 = DAT_0003bfa4;
  }
  puVar1[1] = uVar2;
  puVar1[2] = uVar2;
  *puVar1 = *puVar1 | 0x10;
  *puVar1 = *puVar1 | 0x20;
  *puVar1 = *puVar1 | 8;
  *puVar1 = *puVar1 | 4;
  *DAT_0003bfa8 = *DAT_0003bfa8 | (int)DAT_0003bfa8 >> 0xb;
  return;
}

/* ==========================================================================
 * FUN_0003c842   @ 0x0003c842   (16 bytes)
 * called by : FUN_0003c896, FUN_0003c90c, FUN_0003c92c, FUN_0003c9be, FUN_0003d24a, FUN_0003d382, ... (+1 more)
 */

void FUN_0003c842(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0003cc18;
  DAT_0003cc18[1] = 0;
  *puVar1 = 0;
  puVar1[1] = 2;
  *puVar1 = 2;
  return;
}

/* ==========================================================================
 * FUN_0003c852   @ 0x0003c852   (52 bytes)
 * called by : FUN_0003c896, FUN_0003c90c, FUN_0003c92c, FUN_0003c9be, FUN_0003d24a, FUN_0003d382, ... (+1 more)
 */

void FUN_0003c852(uint param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  
  puVar1 = DAT_0003cc18;
  bVar2 = 0;
  do {
    puVar1[1] = 0;
    if ((param_1 & 0xffffff80) == 0x80) {
      *puVar1 = 2;
    }
    else {
      *puVar1 = 0;
    }
    puVar1[1] = 2;
    puVar1[1] = 0;
    bVar2 = bVar2 + 1;
    param_1 = (param_1 & 0x7f) << 1;
  } while (bVar2 < 8);
  *puVar1 = 2;
  puVar1[1] = 0;
  puVar1[1] = 2;
  return;
}

/* ==========================================================================
 * FUN_0003c886   @ 0x0003c886   (16 bytes)
 * called by : FUN_0003c896, FUN_0003c90c, FUN_0003c92c, FUN_0003c9be, FUN_0003d24a, FUN_0003d382, ... (+1 more)
 */

void FUN_0003c886(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0003cc18;
  DAT_0003cc18[1] = 2;
  *puVar1 = 2;
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}

/* ==========================================================================
 * FUN_0003c896   @ 0x0003c896   (32 bytes)
 * called by : FUN_0003c8b6, FUN_0003c8dc, FUN_0003c92c, FUN_0003c996, FUN_0003d382, FUN_0003d3f4, ... (+4 more)
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886
 */

void FUN_0003c896(undefined4 param_1)

{
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0);
  FUN_0003c852(param_1);
  FUN_0003c842();
  return;
}

/* ==========================================================================
 * FUN_0003c8dc   @ 0x0003c8dc   (34 bytes)
 * calls     : FUN_0003c896, rom_25078
 */

void FUN_0003c8dc(void)

{
  rom_25078();
  FUN_0003c896(0x81);
  FUN_0003c896(5);
  return;
}

/* ==========================================================================
 * FUN_0003c90c   @ 0x0003c90c   (32 bytes)
 * called by : FUN_0003d3f4, FUN_0003d51e, FUN_0003d55c
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886
 */

void FUN_0003c90c(undefined4 param_1)

{
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  FUN_0003c852(param_1);
  FUN_0003c842();
  return;
}

/* ==========================================================================
 * FUN_0003c92c   @ 0x0003c92c   (106 bytes)
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886, FUN_0003c896
 */

void FUN_0003c92c(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  FUN_0003c896(0xb0);
  bVar1 = 3;
  do {
    FUN_0003c896(0);
    FUN_0003c896(0x10);
    FUN_0003c896(bVar1 + 0xb0);
    FUN_0003c886();
    FUN_0003c852(0x78);
    FUN_0003c852(0x40);
    bVar2 = 0;
    do {
      FUN_0003c852(param_1);
      FUN_0003c852(param_2);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x3c);
    FUN_0003c842();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

/* ==========================================================================
 * FUN_0003ce52   @ 0x0003ce52   (10 bytes)
 * called by : FUN_00032942, FUN_0003cf7c, FUN_0003d2b0, set_Update_OLED_2
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void FUN_0003ce52(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  
  cVar1 = '\x01';
  bVar2 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  for (uVar3 = 0; s__0003d11c[uVar3] != '\0'; uVar3 = uVar3 + 1 & 0xff) {
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(bVar2,cVar1,1);
    }
    else {
      FUN_0003cb9a(bVar2,cVar1,1);
    }
    bVar2 = bVar2 + 8;
    if (0x70 < bVar2) {
      bVar2 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *DAT_0003d0b8 = '\0';
  return;
}

/* ==========================================================================
 * FUN_0003d24a   @ 0x0003d24a   (52 bytes)
 * called by : OLED_Clear
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886, FUN_0003c996
 */

void FUN_0003d24a(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  FUN_0003c996();
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    FUN_0003c852(param_4);
  }
  FUN_0003c842();
  return;
}

/* ==========================================================================
 * OLED_Clear   @ 0x0003d27e   (50 bytes)
 * called by : BLE_PAIR, Default_Profile, FUN_0003d2b0, FUN_0003d508, OLED_Init, Success_led_2second, ... (+6 more)
 * calls     : FUN_0003b54e, FUN_0003c896, FUN_0003d24a, dbg_printf
 * string    : "OLED_Clear---------------\r\n"
 */

void OLED_Clear(void)

{
  byte bVar1;
  
  dbg_printf(str_OLED_Clear);
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  bVar1 = 0;
  do {
    FUN_0003b54e();
    FUN_0003d24a(0,bVar1,0x78);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

/* ==========================================================================
 * FUN_0003d382   @ 0x0003d382   (114 bytes)
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886, FUN_0003c896
 */

void FUN_0003d382(void)

{
  byte bVar1;
  byte bVar2;
  
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  FUN_0003c896(0xb0);
  bVar1 = 0;
  do {
    FUN_0003c896(0);
    FUN_0003c896(0x10);
    FUN_0003c896(bVar1 + 0xb0);
    FUN_0003c886();
    FUN_0003c852(0x78);
    FUN_0003c852(0x40);
    bVar2 = 0;
    do {
      FUN_0003c852(0);
      FUN_0003c852(0);
      FUN_0003c852(0);
      FUN_0003c852(0);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x1e);
    FUN_0003c842();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

/* ==========================================================================
 * FUN_0003d3f4   @ 0x0003d3f4   (276 bytes)
 * calls     : FUN_0003c842, FUN_0003c852, FUN_0003c886, FUN_0003c896, FUN_0003c90c
 */

void FUN_0003d3f4(void)

{
  byte bVar1;
  
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  FUN_0003c896(0xb0);
  FUN_0003c90c(0xff);
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  bVar1 = 0;
  do {
    FUN_0003c852(1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  FUN_0003c842();
  FUN_0003c90c(0xff);
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  FUN_0003c896(0xb0);
  FUN_0003c90c(0xff);
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  bVar1 = 0;
  do {
    FUN_0003c852(0);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  FUN_0003c842();
  FUN_0003c90c(0xff);
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  FUN_0003c896(0xb0);
  FUN_0003c90c(0xff);
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  bVar1 = 0;
  do {
    FUN_0003c852(0);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  FUN_0003c842();
  FUN_0003c90c(0xff);
  FUN_0003c896(0);
  FUN_0003c896(0x10);
  FUN_0003c896(0xb1);
  FUN_0003c90c(0xf);
  FUN_0003c886();
  FUN_0003c852(0x78);
  FUN_0003c852(0x40);
  bVar1 = 0;
  do {
    FUN_0003c852(8);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  FUN_0003c842();
  FUN_0003c90c(0xf);
  return;
}

/* ==========================================================================
 * FUN_0003d51e   @ 0x0003d51e   (18 bytes)
 * calls     : FUN_0003c896, FUN_0003c90c
 */

void FUN_0003d51e(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0003c90c();
    return;
  }
  FUN_0003c896();
  return;
}

/* ==========================================================================
 * FUN_0003d530   @ 0x0003d530   (22 bytes)
 * calls     : FUN_0003c896
 */

void FUN_0003d530(void)

{
  FUN_0003c896(0x8d);
  FUN_0003c896(0x72);
  FUN_0003c896(0xaf);
  return;
}


/*############################################################################
 * POWER AND BATTERY  (37 functions)
 *
 *   0x0002AA44  FUN_0002aa44  (24 B)
 *   0x0002B128  FUN_0002b128  (62 B)
 *   0x0002B166  FUN_0002b166  (40 B)
 *   0x0002B20E  set_force_sleep  (64 B)
 *   0x0002BCAC  FUN_0002bcac  (156 B)
 *   0x0002BD48  FUN_0002bd48  (26 B)
 *   0x0002BDD6  This  (34 B)
 *   0x0002BE1C  FUN_0002be1c  (44 B)
 *   0x0003297E  FUN_0003297e  (30 B)
 *   0x00033CFC  FUN_00033cfc  (2 B)
 *   0x00033CFE  FUN_00033cfe  (2 B)
 *   0x00034712  SLEEP  (1250 B)
 *   0x0003587A  FUN_0003587a  (60 B)
 *   0x00035C9C  FUN_00035c9c  (54 B)
 *   0x00036FA2  FUN_00036fa2  (10 B)
 *   0x00036FC4  FUN_00036fc4  (10 B)
 *   0x000371AC  FUN_000371ac  (22 B)
 *   0x000371C2  FUN_000371c2  (124 B)
 *   0x000377FE  FUN_000377fe  (16 B)
 *   0x00037A88  FUN_00037a88  (12 B)
 *   0x00037A94  FUN_00037a94  (34 B)
 *   0x0003834C  FUN_0003834c  (4 B)
 *   0x00038DF6  USNDP_status_2  (344 B)
 *   0x00039D54  addPMU_Reg0x5_2  (170 B)
 *   0x0003A6CC  addPMU_Reg0x5  (132 B)
 *   0x0003B214  FUN_0003b214  (54 B)
 *   0x0003B3F2  FUN_0003b3f2  (140 B)
 *   0x0003B568  FUN_0003b568  (78 B)
 *   0x0003B5F8  FUN_0003b5f8  (88 B)
 *   0x0003B650  referance_voltage  (102 B)
 *   0x0003BF0A  FUN_0003bf0a  (54 B)
 *   0x0003C174  FUN_0003c174  (82 B)
 *   0x0003C1C6  FUN_0003c1c6  (88 B)
 *   0x0003D062  Charging  (32 B)
 *   0x0003D508  FUN_0003d508  (22 B)
 *   0x0003D546  FUN_0003d546  (22 B)
 *   0x0003E2AC  RC32K_2  (88 B)
 ############################################################################*/

/* ==========================================================================
 * FUN_0002aa44   @ 0x0002aa44   (24 bytes)
 * called by : FUN_0002aa5c, SLEEP, enter_BLE_normal_app_mode
 */

uint FUN_0002aa44(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(DAT_0002adb4 + 0x18) & 1) != 0) {
    uVar1 = 0x40;
  }
  if ((*(uint *)(DAT_0002adb4 + 0x1c) & 1) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  return uVar1;
}

/* ==========================================================================
 * FUN_0002b128   @ 0x0002b128   (62 bytes)
 * called by : FUN_0002bd48, SLEEP, exist, f_reconnect_24G
 * calls     : FUN_0002abd4
 */

undefined1 FUN_0002b128(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_0002abd4();
  if (((iVar2 != 0) ||
      (((*DAT_0002b51c != '\0' && (*DAT_0002b520 == '\0')) ||
       ((*(uint *)(DAT_0002b524 + 0x2c) & 1) == 0)))) ||
     (((*DAT_0002b528 != 0 || (*DAT_0002b52c != '\0')) || (uVar1 = 0, *DAT_0002b530 != '\0')))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* ==========================================================================
 * FUN_0002b166   @ 0x0002b166   (40 bytes)
 * called by : FUN_0002bd48
 */

undefined4 FUN_0002b166(void)

{
  if ((((*DAT_0002b534 == '\0' && *DAT_0002b538 == '\0') && *DAT_0002b53c == '\0') &&
       *DAT_0002b540 == '\0') && (*DAT_0002b544 != '\0')) {
    return 0;
  }
  return 1;
}

/* ==========================================================================
 * set_force_sleep   @ 0x0002b20e   (64 bytes)
 * called by : force_24g_sleep, force_ble_sleep
 * calls     : FUN_00032886, FUN_0003587a, FUN_0003bf0a, FUN_0003d508, FUN_0003d546, dbg_printf
 * string    : "set_force_sleep"
 * string    : "%s \r\n"
 */

void set_force_sleep(void)

{
  dbg_printf(str_s_3,DAT_0002b554 + 0x10);
  *DAT_0002b544 = 1;
  FUN_0003bf0a();
  FUN_0003d508();
  FUN_0003d546();
  FUN_00032886(0);
  FUN_0003587a();
  *DAT_0002b534 = 0;
  *DAT_0002b538 = 0;
  *DAT_0002b568 = 0;
  *DAT_0002b53c = 0;
  *DAT_0002b56c = 0;
  return;
}

/* ==========================================================================
 * FUN_0002bcac   @ 0x0002bcac   (156 bytes)
 * called by : FUN_0002be1c, FUN_000360aa, SLEEP, exist
 */

void FUN_0002bcac(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar2 = DAT_0002be48;
  uVar6 = 0;
  *(undefined4 *)(DAT_0002be48 + 0x20) = 0;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x30) = 0x2c;
  uVar5 = DAT_0002be58;
  pcVar4 = DAT_0002be4c;
  iVar3 = DAT_0002be48;
  if (*DAT_0002be4c != '\0') {
    uVar6 = 2;
  }
  uVar7 = DAT_0002be54;
  if ((*(uint *)(iVar2 + 0x1c) & 1) != 0) {
    uVar7 = DAT_0002be50;
  }
  if ((*(uint *)(iVar2 + 0x18) & 1) == 0) {
    uVar8 = 0x2000;
  }
  else {
    uVar8 = 0x3000;
  }
  if ((*(uint *)(iVar2 + 0x30) & 1) == 0) {
    uVar9 = 0x2000000;
  }
  else {
    uVar9 = 0x3000000;
  }
  uVar1 = DAT_0002be58;
  if ((*(uint *)(iVar2 + 0x10) & 1) != 0) {
    uVar1 = 0x300;
  }
  *(uint *)(DAT_0002be48 + 0x80) = uVar6 | 0xfc;
  *(uint *)(iVar3 + 0x84) = uVar7 | uVar8 | uVar9 | uVar1;
  *(undefined4 *)(iVar3 + 0x8c) = DAT_0002be5c;
  *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) | 0x10000000;
  if (*pcVar4 != '\0') {
    *pcVar4 = '\0';
    *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) | 1;
  }
  *(undefined4 *)(DAT_0002be60 + 0xc) = *(undefined4 *)(iVar3 + 0x8c);
  *(undefined4 *)(iVar3 + 0x94) = 0xffffffff;
  *DAT_0002be64 = *DAT_0002be64 | uVar5;
  return;
}

/* ==========================================================================
 * FUN_0002bd48   @ 0x0002bd48   (26 bytes)
 * calls     : FUN_0002b128, FUN_0002b166
 */

undefined4 FUN_0002bd48(void)

{
  int iVar1;
  
  iVar1 = FUN_0002b128();
  if ((iVar1 == 0) && (iVar1 = FUN_0002b166(), iVar1 == 0)) {
    return 2;
  }
  return 1;
}

/* ==========================================================================
 * This   @ 0x0002bdd6   (34 bytes)
 * calls     : FUN_0003b130, dbg_printf
 * string    : "This is the function key wakeup,start cpu reset...\r\n"
 */

void This(void)

{
  if ((*PTR_DAT_0002be80 != '\0') && (*PTR_DAT_0002be80 = 0, *PTR_DAT_0002be84 == '\0')) {
    dbg_printf(str_This_is_the_function_key_wakeup_start_cpu_re);
    FUN_0003b130();
  }
  return;
}

/* ==========================================================================
 * FUN_0002be1c   @ 0x0002be1c   (44 bytes)
 * called by : FUN_0002f31c
 * calls     : FUN_0002bcac, dbg_printf
 * string    : "key wakeup timeout, need key wakeconfig\r\n"
 */

void FUN_0002be1c(void)

{
  int iVar1;
  char *pcVar2;
  byte bVar3;
  
  iVar1 = DAT_0002be68;
  pcVar2 = (char *)(DAT_0002be68 + 0x10);
  if ((*pcVar2 != '\0') &&
     (bVar3 = *(char *)(DAT_0002be68 + 0x11) + 1, *(byte *)(DAT_0002be68 + 0x11) = bVar3,
     100 < bVar3)) {
    *pcVar2 = '\0';
    *(undefined1 *)(iVar1 + 0x11) = 0;
    dbg_printf(str_key_wakeup_timeout_need_key_wakeconfig);
    FUN_0002bcac();
  }
  return;
}

/* ==========================================================================
 * FUN_0003297e   @ 0x0003297e   (30 bytes)
 * called by : SLEEP, exist
 * calls     : FUN_00032620, FUN_00032e82, FUN_00032f16
 */

void FUN_0003297e(void)

{
  *DAT_000329e4 = 0;
  FUN_00032f16();
  FUN_00032e82();
  FUN_00032620();
  *DAT_00032a98 = 0;
  *DAT_00032a64 = 0;
  return;
}

/* ==========================================================================
 * FUN_00033cfc   @ 0x00033cfc   (2 bytes)
 * called by : SLEEP, exist, force_ble_sleep
 */

void FUN_00033cfc(void)

{
  return;
}

/* ==========================================================================
 * FUN_00033cfe   @ 0x00033cfe   (2 bytes)
 * called by : SLEEP, gpio
 */

void FUN_00033cfe(void)

{
  return;
}

/* ==========================================================================
 * SLEEP   @ 0x00034712   (1250 bytes)
 * calls     : FUN_0002aa44, FUN_0002b128, FUN_0002bcac, FUN_000314d2, FUN_000317c2, FUN_00032620, ... (+34 more)
 * string    : "(Time_Entry_Sdeep ==0)  %x,%x\r\n"
 * string    : "entry force 24g sleep 1 \r\n"
 * string    : "in sleep_status =%d,%d\n"
 * string    : "enter 24g idle_status \r\n"
 * string    : "cpu_reset()  MODE_Switch\n"
 * string    : "USNDP_status------usb insert   %x\r\n"
 * string    : "sleep_status 24G===========%d,%d\r\n"
 * string    : "enter sleep_status\n"
 * string    : "wake form sleep_status\n"
 * string    : "wakeup Key_Mot_Activ  USB===================%d,%d\r\n"
 * string    : "SLEEP wakeup KEY_PAIR\n"
 * string    : "SLEEP wakeup RECONN\n"
 * string    : "SLEEP wakeup id_code\n"
 */

void SLEEP(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  short *psVar4;
  undefined1 *puVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  
  psVar4 = DAT_00034aa4;
  pbVar3 = DAT_00034aa0;
  uVar13 = 0;
  if (*DAT_00034a34 != '\0') {
    return;
  }
  if ((*DAT_00034a94 == 0) && (*DAT_00034a9c == '\0')) {
    dbg_printf(str_Time_Entry_Sdeep_0_x_x,*DAT_00034aa0 ^ 1,*DAT_00034aa4,param_4,param_2,param_3,
               param_4);
    if (*pbVar3 == 0 && *psVar4 == 0) {
      dbg_printf(str_entry_force_24g_sleep_1);
      force_24g_sleep();
    }
    else {
      OLED_Init();
    }
  }
  puVar2 = DAT_00034afc;
  pcVar12 = DAT_00034ae8;
  if (*DAT_00034ae4 != '\0') {
    *DAT_00034ae8 = '\0';
    *DAT_00034aec = '\x02';
    return;
  }
  if (*DAT_00034af0 != '\0') {
    return;
  }
  if ((*DAT_00034af4 != '\0') || (*DAT_00034af8 != '\0')) {
LAB_00034804:
    *pcVar12 = '\0';
    return;
  }
  *DAT_00034afc = 0;
  if (*DAT_00034b00 << 0x19 < 0) {
    *DAT_00034aec = *DAT_00034aec + '\x01';
    *puVar2 = 1;
    return;
  }
  if (*DAT_00034b04 == '\0') {
    FUN_00036caa();
    *DAT_00034b08 = '\x01';
  }
  if (*pcVar12 != '\0') {
    if (*DAT_00034b08 != '\0') {
      *DAT_00034b08 = '\0';
      FUN_00036c8e();
    }
    FUN_00036d0e(8);
    *DAT_00034b04 = '\x06';
    *DAT_00034b0c = 500;
    *DAT_00034aec = *DAT_00034aec + '\x01';
    *DAT_00034b10 = 5;
    *DAT_00034b14 = 0;
    return;
  }
  if (((*DAT_00034b18 != '\0') && (*DAT_00034b1c == '\0')) &&
     (pcVar12 = DAT_00034a98, *DAT_00034a7c != '\0')) goto LAB_00034804;
  if ((*DAT_00034b1c != '\0') && (*DAT_00034a9c == '\0')) {
    force_24g_sleep();
  }
  iVar11 = DAT_00034a88;
  cVar1 = *DAT_00034a98;
  if (cVar1 == '\0') {
    iVar8 = FUN_0002aa44();
    do {
      FUN_0003af8a();
      iVar10 = FUN_0002b128();
      if ((iVar10 != 0) || (iVar10 = FUN_0002aa44(), iVar10 != iVar8)) goto LAB_00034874;
    } while (*DAT_00034b3c == '\0');
    *DAT_00034b3c = '\0';
LAB_00034874:
    if (*DAT_00034b40 == '\0') {
      return;
    }
    *DAT_00034b40 = '\0';
    uVar6 = (ushort)(*(byte *)(iVar11 + 0xb) >> 4) << 4 | (ushort)(*(byte *)(iVar11 + 0xc) >> 4);
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    if ((ushort)(uVar6 * 0xef) < *DAT_00034a94) {
      return;
    }
    if (*DAT_00034a9c != '\0') {
      return;
    }
    *DAT_00034a8c = 0;
    FUN_00032f16();
    FUN_00032e82();
    puVar2 = DAT_00034a64;
    *DAT_00034a64 = 1;
    FUN_00032620();
    FUN_0003d508();
    FUN_0003d546();
    *puVar2 = 1;
    dbg_printf(str_enter_24g_idle_status);
    *DAT_00034a98 = '\x02';
    FUN_00033cfc();
    FUN_00039a84(0x32,0);
    return;
  }
  if (cVar1 == '\x02') {
    FUN_00032e82();
    iVar8 = FUN_0002aa44();
    uVar14 = *(uint *)(DAT_00034b38 + 0x10) & 1;
    FUN_00032e82();
    FUN_0003c286(1);
    do {
      do {
        iVar10 = FUN_0002b128();
        if (iVar10 == 0) {
          FUN_0002bcac();
          uVar13 = *(uint *)(DAT_00034b38 + 0x30) & 1;
          FUN_0003b3f2();
        }
        iVar10 = FUN_0002b128();
        if ((((iVar10 != 0) || (iVar10 = FUN_0002aa44(), iVar10 != iVar8)) ||
            ((*(uint *)(DAT_00034b38 + 0x30) & 1) != uVar13)) ||
           ((*(uint *)(DAT_00034b38 + 0x10) & 1) != uVar14)) {
          if ((*(uint *)(DAT_00034b38 + 0x10) & 1) != uVar14) {
            dbg_printf(str_cpu_reset_MODE_Switch);
            FUN_0003b130();
          }
          iVar11 = get_usb_insert_status();
          pcVar12 = DAT_00034a9c;
          *DAT_00034a9c = iVar11 != 0;
          if (*pcVar12 != '\0') {
            iVar11 = USNDP_status();
            pcVar12 = DAT_00034b7c;
            *DAT_00034b7c = iVar11 != 0;
            if (*pcVar12 == '\0') {
              dbg_printf(str_USNDP_status_usb_insert_x,*pcVar12);
              FUN_0003b130();
            }
          }
          OLED_Init();
          *DAT_00034a78 = 0;
          FUN_00033cfe();
          goto LAB_00034bba;
        }
      } while (*DAT_00034b40 == '\0');
      *DAT_00034b40 = '\0';
      uVar7 = (uint)(*(byte *)(iVar11 + 0xb) >> 4) << 4 | (uint)(*(byte *)(iVar11 + 0xc) >> 4);
      if (uVar7 == 0) {
        uVar7 = 1;
      }
      if ((uVar7 * 0xef - (uint)*DAT_00034a94 == 0) && (*DAT_00034a9c == '\0')) {
        FUN_0003d508();
        FUN_0003d546();
      }
      if (0x31 < *DAT_00034a78) goto LAB_00034bba;
      if (*DAT_00034a94 == 0) {
        force_24g_sleep();
        goto LAB_00034bba;
      }
    } while ((*DAT_00034a94 & 1) == 0);
    FUN_0003b54e();
    pcVar12 = DAT_00034ba4;
    uVar6 = (ushort)(*(byte *)(iVar11 + 0xb) >> 4) << 4 | (ushort)(*(byte *)(iVar11 + 0xc) >> 4);
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    if ((ushort)(uVar6 * 0xef) < *DAT_00034a94) {
      if (*DAT_00034ba4 == '\0') {
        FUN_000314d2(1);
        *pcVar12 = '\b';
      }
      set_Update_OLED();
    }
    else {
      if (*DAT_00034ba4 == '\0') {
        FUN_000314d2(1);
        *pcVar12 = '\x10';
      }
      FUN_00039a84(0x32,0);
    }
    goto LAB_00034bba;
  }
  if (cVar1 != '\x03') {
    return;
  }
  dbg_printf(str_in_sleep_status_d_d,3,*DAT_00034a94);
  FUN_0003d508();
  FUN_0003d546();
  FUN_00032e82();
  iVar11 = DAT_00034b38;
  if ((*(uint *)(DAT_00034b38 + 0x2c) & 1) == 0) {
    FUN_00033dc2();
  }
  if (((*(char *)(DAT_00034fbc + 8) == '\0') || (*DAT_00034fc0 != '\0')) || (*DAT_00034fc4 != '\0'))
  {
    sensor_pwdn();
  }
  FUN_00033cfc();
  FUN_00032892();
  FUN_0003297e();
  *DAT_00034fc8 = 1;
  FUN_000369ac();
  *(undefined4 *)(DAT_00034fb8 + 0x14) = 0;
  FUN_0003bf0a();
  FUN_0003b528();
  FUN_0003c286(1);
  do {
    iVar8 = FUN_0002aa44();
    uVar14 = *(uint *)(iVar11 + 0x10) & 1;
    uVar9 = FUN_0002b128();
    dbg_printf(str_sleep_status_24G_d_d,uVar13,uVar9);
    iVar10 = FUN_0002b128();
    if (iVar10 == 0) {
      dbg_printf(str_enter_sleep_status);
      FUN_000317c2(0x32);
      FUN_0002bcac();
      uVar13 = *(uint *)(iVar11 + 0x30) & 1;
      FUN_0003b3f2();
      dbg_printf(str_wake_form_sleep_status);
    }
    *DAT_0003501c = 0;
    FUN_000369a0();
    iVar10 = FUN_0002b128();
  } while ((((iVar10 == 0) && (iVar10 = FUN_0002aa44(), iVar10 == iVar8)) &&
           ((*(uint *)(iVar11 + 0x30) & 1) == uVar13)) && ((*(uint *)(iVar11 + 0x10) & 1) == uVar14)
          );
  if ((*(uint *)(iVar11 + 0x10) & 1) != uVar14) {
    dbg_printf(DAT_00035020);
    FUN_0003b130();
  }
  iVar11 = get_usb_insert_status();
  pcVar12 = DAT_00035024;
  *DAT_00035024 = iVar11 != 0;
  if (*pcVar12 != '\0') {
    iVar11 = USNDP_status();
    pcVar12 = DAT_00035028;
    *DAT_00035028 = iVar11 != 0;
    if (*pcVar12 == '\0') {
      dbg_printf(DAT_00035020 + 0x20,*pcVar12);
      FUN_0003b130();
    }
  }
  uVar9 = FUN_0002aa44();
  dbg_printf(str_wakeup_Key_Mot_Activ_USB_d_d,*(uint *)(DAT_0003502c + 0x30) & 1,uVar9);
  pcVar12 = DAT_00035068;
  puVar2 = DAT_00035064;
  *DAT_00035064 = 0;
  if (*pcVar12 == '\0') {
    *DAT_00034fc4 = '\x01';
  }
  FUN_0003beb4();
  FUN_0003b538(DAT_0003506c);
  puVar5 = DAT_00035070;
  *puVar2 = 0;
  *puVar5 = 0;
  FUN_00032f16();
  FUN_00032e82();
  OLED_Init();
  if (*pcVar12 == '\0') {
    if (((*(char *)(DAT_00034fbc + 0x10) == '\x04') && (*(char *)(DAT_00034fbc + 0x11) == '\x04'))
       && (*(char *)(DAT_00034fbc + 0x12) == '\x04')) {
      *DAT_000350b0 = 2;
      pcVar12 = str_SLEEP_wakeup_id_code;
      goto LAB_00034d4c;
    }
    if ((*(uint *)(DAT_0003502c + 0x30) & 1) == uVar13) {
      set_bonded_led_flash();
      *DAT_0003508c = 1;
      pcVar12 = str_SLEEP_wakeup_RECONN;
      goto LAB_00034d4c;
    }
  }
  else {
    pcVar12 = str_SLEEP_wakeup_KEY_PAIR;
LAB_00034d4c:
    dbg_printf(pcVar12);
  }
  *DAT_000350a8 = 1;
  FUN_0003d2b0();
  *DAT_000350ac = 1;
LAB_00034bba:
  FUN_000369a0();
  *(undefined4 *)(DAT_00034fb8 + 0x14) = 1;
  FUN_0003c2c6();
  return;
}

/* ==========================================================================
 * FUN_0003587a   @ 0x0003587a   (60 bytes)
 * called by : set_force_sleep
 */

void FUN_0003587a(void)

{
  *DAT_00035b84 = 0;
  *DAT_00035b88 = 0;
  *DAT_00035b5c = 0;
  *DAT_00035b60 = 0;
  *DAT_00035b64 = 0;
  *DAT_00035b68 = 0;
  *DAT_00035b6c = 0;
  *DAT_00035b74 = 0;
  *DAT_00035b8c = 0;
  *DAT_00035b78 = 0;
  *DAT_00035b7c = 0;
  *DAT_00035b80 = 0;
  *DAT_00035b90 = 0;
  *DAT_00035b94 = 0;
  return;
}

/* ==========================================================================
 * FUN_00035c9c   @ 0x00035c9c   (54 bytes)
 * called by : USNDP_status_2, fn24main
 * calls     : FUN_00032886, FUN_0003c174, FUN_0003c1c6, FUN_0003c2c6
 */

void FUN_00035c9c(void)

{
  FUN_0003c1c6(0,1,0xf);
  FUN_0003c1c6(1,0);
  FUN_0003c2c6();
  FUN_0003c174(0,1,DAT_00035e28);
  FUN_00032886(0);
  *DAT_00035e2c = *DAT_00035e2c | 0xb;
  return;
}

/* ==========================================================================
 * FUN_00036fa2   @ 0x00036fa2   (10 bytes)
 * called by : FUN_000371c2
 */

void FUN_00036fa2(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00037384;
  *(char *)(DAT_00037384 + 9) = (char)param_1;
  *(char *)(iVar1 + 10) = (char)((uint)param_1 >> 8);
  return;
}

/* ==========================================================================
 * FUN_00036fc4   @ 0x00036fc4   (10 bytes)
 * called by : FUN_000371c2
 */

void FUN_00036fc4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00037384;
  *(char *)(DAT_00037384 + 7) = (char)param_1;
  *(char *)(iVar1 + 8) = (char)((uint)param_1 >> 8);
  return;
}

/* ==========================================================================
 * FUN_000371ac   @ 0x000371ac   (22 bytes)
 * called by : FUN_000371c2
 * calls     : FUN_00037a94, rom_24FEC
 */

void FUN_000371ac(void)

{
  rom_24FEC(DAT_00037388,0x10);
  *DAT_0003738c = 0;
  FUN_00037a94();
  return;
}

/* ==========================================================================
 * FUN_000371c2   @ 0x000371c2   (124 bytes)
 * called by : USNDP_status_2, f_usb_isConnected
 * calls     : FUN_00036f88, FUN_00036fa2, FUN_00036fc4, FUN_000371ac
 */

void FUN_000371c2(code *param_1,code *param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  
  (*param_1)(1);
  puVar2 = DAT_00037384;
  DAT_00037384[0xb] = 0;
  FUN_00036fa2(0);
  FUN_00036fc4(0);
  pbVar3 = DAT_00037384 + 0x80;
  DAT_00037384[0x88] = DAT_00037384[0x88] & 0x7f;
  FUN_00036fa2(7);
  FUN_00036fc4(7);
  puVar2[0xb] = 0x3f;
  pbVar3[4] = 0;
  *pbVar3 = 8;
  pbVar3[0x1c] = 0xf4;
  *pbVar3 = *pbVar3 | 1;
  FUN_00036f88(500);
  bVar1 = pbVar3[0x14];
  FUN_00036f88(500);
  pbVar3[0x14] = bVar1;
  FUN_00036f88(500);
  pbVar3[0xc] = 0x77;
  FUN_000371ac();
  *puVar2 = 0;
  puVar2[0xf] = 1;
  (*param_2)();
  *(undefined1 *)(DAT_00037390 + 1) = 0;
  return;
}

/* ==========================================================================
 * FUN_000377fe   @ 0x000377fe   (16 bytes)
 * called by : USNDP_status_2, f_usb_isConnected
 */

void FUN_000377fe(int param_1,undefined4 param_2)

{
  if (param_1 < 6) {
    *(undefined4 *)(param_1 * 0x18 + DAT_00037bf0 + 0x10) = param_2;
  }
  return;
}

/* ==========================================================================
 * FUN_00037a88   @ 0x00037a88   (12 bytes)
 * called by : FUN_00037a94
 */

void FUN_00037a88(void)

{
  int iVar1;
  
  iVar1 = DAT_00037bf4;
  *(undefined2 *)(DAT_00037bf4 + 2) = 0;
  *(undefined2 *)(iVar1 + 4) = 0;
  return;
}

/* ==========================================================================
 * FUN_00037a94   @ 0x00037a94   (34 bytes)
 * called by : FUN_000371ac
 * calls     : FUN_00037a88, FUN_0003834c, FUN_0004245e, rom_24FEC
 */

void FUN_00037a94(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0003834c();
  uVar2 = (undefined4)uVar3;
  FUN_00037a88(uVar2,(int)((ulonglong)uVar3 >> 0x20),uVar2);
  iVar1 = FUN_0004245e(uVar2);
  *(undefined1 *)(DAT_00037bf4 + 1) = *(undefined1 *)(iVar1 + 7);
  rom_24FEC(DAT_00037bf0,0x90);
  return;
}

/* ==========================================================================
 * FUN_0003834c   @ 0x0003834c   (4 bytes)
 * called by : FUN_00037a94
 */

undefined4 FUN_0003834c(void)

{
  return DAT_00038394;
}

/* ==========================================================================
 * USNDP_status_2   @ 0x00038df6   (344 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : FUN_000317c2, FUN_00035c9c, FUN_000371c2, FUN_000377fe, FUN_0003afa2, FUN_0003b130, ... (+6 more)
 * string    : "USNDP_status------charging   %x\r\n"
 * string    : "USNDP_status------usb insert  %x\r\n"
 * string    : "usb mode..................\r\n"
 * string    : "usb_init  wait_usb_time=%x, %x\r\n"
 * string    : "wait_usb_time=%d, USB_OTG_CFG=%d,Get_USBDN=%x\r\n"
 * string    : "usb_mode_check  RF_MODE USB %x, %x, %x\r\n"
 */

void USNDP_status_2(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = DAT_00039058;
  iVar4 = USNDP_status();
  pcVar1 = DAT_0003905c;
  *DAT_0003905c = iVar4 != 0;
  if (*pcVar1 == '\0') {
    dbg_printf(str_USNDP_status_usb_insert_x_2,*pcVar1);
  }
  else {
    iVar4 = USNDP_status();
    *pcVar1 = iVar4 != 0;
    if (*pcVar1 == '\0') {
      dbg_printf(str_USNDP_status_usb_insert_x_2,*pcVar1);
      uVar5 = DAT_000390a8;
    }
    else {
      dbg_printf(str_USNDP_status_charging_x,*pcVar1);
      uVar5 = 0x1fe;
    }
  }
  if (*DAT_000390ac != '\0') {
    dbg_printf(str_usb_mode);
    *DAT_000390d0 = 1;
    FUN_00035c9c();
    pcVar1 = DAT_000390d8;
    puVar3 = DAT_000390d4;
    do {
      uVar6 = 0;
      if (uVar5 == 0) goto LAB_00038f30;
      uVar6 = DAT_00039058 - 10;
      do {
        if ((((uVar5 == uVar6) || (uVar5 == DAT_000390dc)) || (uVar5 == DAT_000390e0)) ||
           (((uVar5 == 4000 || (uVar5 == DAT_000390e4)) || ((uVar5 == 2000 || (uVar5 == 1000)))))) {
          FUN_000371c2(DAT_000390ec,DAT_000390e8);
          FUN_000377fe(1,DAT_000390f0);
          FUN_000377fe(2,DAT_000390f4);
          FUN_000377fe(3,DAT_000390f8);
          FUN_000377fe(4,DAT_000390fc);
          uVar5 = uVar5 - 1 & 0xffff;
          dbg_printf(str_usb_init_wait_usb_time_x_x,uVar5,*puVar3);
        }
        FUN_0003b54e();
        if (uVar5 == 0) {
          FUN_0003afa2(1);
          uVar6 = 0;
          goto LAB_00038f30;
        }
      } while (*pcVar1 == '\0');
      *pcVar1 = '\0';
      uVar6 = uVar5 - 1 & 0xffff;
      dbg_printf(str_wait_usb_time_d_USB_OTG_CFG_d_Get_USBDN_x,uVar6,*DAT_00039004,
                 *(uint *)(DAT_00038f88 + -0x40) & 1);
      if (*DAT_00039154 != '\0') {
        uVar6 = 0;
        *DAT_00039158 = 0;
        Success_led_2second();
        FUN_0003cf7c();
        FUN_000317c2(200);
        goto LAB_00038f30;
      }
      iVar4 = get_usb_insert_status();
      pcVar2 = DAT_000390ac;
      *DAT_000390ac = iVar4 != 0;
      uVar5 = uVar6;
    } while (*pcVar2 != '\0');
    FUN_0003b130();
LAB_00038f30:
    dbg_printf(str_usb_mode_check_RF_MODE_USB_x_x_x,uVar6,*puVar3,*DAT_0003915c);
  }
  return;
}

/* ==========================================================================
 * addPMU_Reg0x5_2   @ 0x00039d54   (170 bytes)
 * called by : cal_data
 * calls     : FUN_000317c2, dbg_printf
 * string    : "addPMU_Reg0x5 = 0x%x\n"
 */

void addPMU_Reg0x5_2(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_0003a008;
  *(uint *)(DAT_0003a008 + 0x24) = *(uint *)(DAT_0003a008 + 0x24) & 0xffffffbf;
  iVar2 = DAT_0003a00c;
  *(undefined4 *)(DAT_0003a00c + 0x24) = *(undefined4 *)(iVar1 + 0x24);
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xffff7fff;
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | 0x8000;
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  FUN_000317c2(100);
  uVar3 = *(uint *)(DAT_0003a024 + 0x14);
  dbg_printf(str_addPMU_Reg0x5_0x_x,*(undefined4 *)(DAT_0003a024 + 0x14));
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & DAT_0003a040;
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | ((uVar3 & 0x3ffff) >> 9) << 4;
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xfffffff0;
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | (uVar3 & 0x3fffff) >> 0x12;
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xffffffc7;
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | ((uVar3 & 0x1ffffff) >> 0x16) << 3;
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | 0x2000;
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xffff7fff;
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | 0x8000;
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  return;
}

/* ==========================================================================
 * addPMU_Reg0x5   @ 0x0003a6cc   (132 bytes)
 * called by : RC32K_2
 * calls     : dbg_printf
 * string    : "addPMU_Reg0x5 = 0x%x\n"
 */

void addPMU_Reg0x5(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0003a8f0 + 0x14);
  dbg_printf(DAT_0003a8f4,*(undefined4 *)(DAT_0003a8f0 + 0x14));
  iVar2 = DAT_0003a8ec;
  *(uint *)(DAT_0003a8ec + 0x30) = *(uint *)(DAT_0003a8ec + 0x30) & DAT_0003a8f8;
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | ((uVar3 & 0x3ffff) >> 9) << 4;
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xfffffff0;
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | (uVar3 & 0x3fffff) >> 0x12;
  *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xffffffc7;
  *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | ((uVar3 & 0x1ffffff) >> 0x16) << 3;
  iVar1 = DAT_0003a8e0;
  *(undefined4 *)(DAT_0003a8e0 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 0x2000;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xffff7fff;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 0x8000;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  return;
}

/* ==========================================================================
 * FUN_0003b214   @ 0x0003b214   (54 bytes)
 * called by : FUN_0003b34c, FUN_0003b3f2
 */

void FUN_0003b214(void)

{
  DAT_0080000c = DAT_0080000c & 0xfffdffff;
  DAT_00800034 = DAT_00800034 | 0x80;
  *(uint *)(DAT_0003b24c + 0x38) = (*(uint *)(DAT_0003b24c + 0x38) & 0xffffff) + 0xf000000;
  DAT_00820034 = 0;
  DAT_0082003c = DAT_0003b348;
  DAT_00820030 = 7;
  return;
}

/* ==========================================================================
 * FUN_0003b3f2   @ 0x0003b3f2   (140 bytes)
 * called by : SLEEP
 * calls     : FUN_00039198, FUN_0003b214
 */

void FUN_0003b3f2(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_00039198(8);
  iVar3 = 0x800000;
  DAT_00800008 = (DAT_00800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  FUN_0003b214();
  iVar1 = DAT_0003b4f0;
  *(uint *)(DAT_0003b4f0 + 0x1c) = *(uint *)(DAT_0003b4f0 + 0x1c) | 0x80;
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 2;
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 4;
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 1;
  uVar4 = *(uint *)(iVar1 + 0x1c);
  *(undefined1 *)(DAT_0003b4fc + 3) = 1;
  iVar2 = DAT_0003b4f4;
  *(uint *)(DAT_0003b4f4 + 0x10) = (*(uint *)(DAT_0003b4f4 + 0x10) & 0xffff0fff) + 0x5000;
  *(uint *)(iVar2 + 0x10) = (*(uint *)(iVar2 + 0x10) & 0xffffff0f) + 0x50;
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffe7f;
  *(uint *)(iVar1 + 0x1c) = uVar4 | 8;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 1;
  *(undefined4 *)(iVar1 + 0x1c) = 0x80;
  *(undefined4 *)(iVar2 + 0x10) = DAT_0003b4f8;
  *(uint *)(iVar3 + 8) = (*(uint *)(iVar3 + 8) & 0xfffffe7f) + 0x80;
  return;
}

/* ==========================================================================
 * FUN_0003b568   @ 0x0003b568   (78 bytes)
 * called by : referance_voltage, set_Update_OLED
 * calls     : FUN_00039a84
 */

void FUN_0003b568(int param_1,uint param_2)

{
  uint *puVar1;
  
  DAT_0080000c = DAT_0080000c & 0xfffffbff;
  FUN_00039a84(param_1 + 0x30U & 0xff,2);
  puVar1 = DAT_0003b6bc;
  *DAT_0003b6bc = param_1 << 3 | param_2 | DAT_0003b6b8;
  puVar1[2] = DAT_0003b6c0;
  puVar1[3] = 3;
  *DAT_0003b6c4 = *DAT_0003b6c4 | (int)puVar1 >> 0xf;
  if (param_2 == 3) {
    *puVar1 = *puVar1 | 4;
  }
  return;
}

/* ==========================================================================
 * FUN_0003b5f8   @ 0x0003b5f8   (88 bytes)
 * called by : referance_voltage, set_Update_OLED
 * calls     : FUN_00031784
 */

undefined2 FUN_0003b5f8(int param_1,int param_2)

{
  uint *puVar1;
  char *pcVar2;
  ushort uVar3;
  
  pcVar2 = DAT_0003b6c8;
  puVar1 = DAT_0003b6bc;
  uVar3 = 0;
  *DAT_0003b6c8 = '\0';
  if ((~*puVar1 & 3) == 0) {
    return 0;
  }
  *puVar1 = *puVar1 | param_1 * 8 + param_2 + 4U;
  do {
    uVar3 = uVar3 + 1;
    if (300 < uVar3) break;
    FUN_00031784(1);
  } while (*pcVar2 == '\0');
  if (*pcVar2 == '\x01') {
    *(short *)(pcVar2 + 4) = (short)((puVar1[4] & 0x3ffff) >> 2);
  }
  *puVar1 = *puVar1 & 0xffffff80;
  return *(undefined2 *)(pcVar2 + 4);
}

/* ==========================================================================
 * referance_voltage   @ 0x0003b650   (102 bytes)
 * calls     : FUN_00031784, FUN_0003b568, FUN_0003b5f8, dbg_printf, rom_24F24
 * string    : "referance_voltage=%d\r\n"
 */

void referance_voltage(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  short sVar3;
  undefined4 uVar4;
  byte bVar5;
  
  iVar2 = DAT_0003b6cc;
  *(uint *)(DAT_0003b6cc + 0x1c) = *(uint *)(DAT_0003b6cc + 0x1c) | 0x80000;
  *(undefined4 *)(DAT_0003b6d0 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
  FUN_0003b568(7,1,param_3,param_4,param_4);
  iVar1 = DAT_0003b6c8;
  bVar5 = 0;
  do {
    sVar3 = FUN_0003b5f8(7,1);
    *(short *)(iVar1 + 2) = sVar3 + *(short *)(iVar1 + 2);
    FUN_00031784(DAT_0003b6d4);
    bVar5 = bVar5 + 1;
  } while (bVar5 < 6);
  uVar4 = rom_24F24(*(undefined2 *)(iVar1 + 2),6);
  uVar4 = rom_24F24(DAT_0003b6d8,uVar4);
  *(short *)(iVar1 + 6) = (short)uVar4;
  dbg_printf(str_referance_voltage_d,uVar4);
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfff7ffff;
  *(undefined4 *)(DAT_0003b6d0 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
  return;
}

/* ==========================================================================
 * FUN_0003bf0a   @ 0x0003bf0a   (54 bytes)
 * called by : SLEEP, app_mutli_link_change, exist, force_ble_sleep_2, set_force_sleep
 */

void FUN_0003bf0a(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0003bf98;
  *DAT_0003bf98 = *DAT_0003bf98 & 0xffffffbf;
  *puVar1 = *puVar1 & 0xffffffef;
  *puVar1 = *puVar1 & 0xffffffdf;
  *puVar1 = *puVar1 & 0xfffffff7;
  *puVar1 = *puVar1 & 0xfffffffb;
  *DAT_0003bfa8 = *DAT_0003bfa8 & ~((int)DAT_0003bfa8 >> 0xb);
  return;
}

/* ==========================================================================
 * FUN_0003c174   @ 0x0003c174   (82 bytes)
 * called by : FUN_00035c9c
 */

void FUN_0003c174(int param_1,int param_2,int param_3)

{
  if (param_1 != 0) {
    if (param_1 != 1) {
      return;
    }
    if (param_2 == 0) {
      if (param_3 == 0) {
        return;
      }
      *(int *)(DAT_0003c4e0 + 0x10) = param_3;
    }
    else {
      if (param_2 != 1) {
        if (param_2 != 2) {
          return;
        }
        if (param_3 == 0) {
          return;
        }
        *(int *)(DAT_0003c4e0 + 0x18) = param_3;
        return;
      }
      if (param_3 != 0) {
        *(int *)(DAT_0003c4e0 + 0x14) = param_3;
        return;
      }
    }
    return;
  }
  if (param_2 == 0) {
    if (param_3 != 0) {
      *(int *)(DAT_0003c4e0 + 4) = param_3;
      return;
    }
  }
  else {
    if (param_2 == 1) {
      if (param_3 == 0) {
        return;
      }
      *(int *)(DAT_0003c4e0 + 8) = param_3;
      return;
    }
    if (param_2 != 2) {
      return;
    }
    if (param_3 == 0) {
      return;
    }
    *(int *)(DAT_0003c4e0 + 0xc) = param_3;
  }
  return;
}

/* ==========================================================================
 * FUN_0003c1c6   @ 0x0003c1c6   (88 bytes)
 * called by : FUN_00035c9c
 */

void FUN_0003c1c6(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    uVar2 = 4;
    puVar1 = DAT_0003c4e4;
    if (param_2 == 0) {
      DAT_00800010 = DAT_00800010 & 0xfffffffb;
    }
    else {
      DAT_00800010 = DAT_00800010 | 4;
    }
  }
  else {
    if (param_1 != 1) goto LAB_0003c214;
    uVar2 = 8;
    puVar1 = DAT_0003c4e8;
    if (param_2 == 0) {
      DAT_00800010 = DAT_00800010 & 0xfffffff7;
    }
    else {
      DAT_00800010 = DAT_00800010 | 8;
    }
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[3] = puVar1[3] & 0xffffff87 | param_3 << 3;
  DAT_0080000c = DAT_0080000c & ~uVar2;
LAB_0003c214:
  *DAT_0003c4e0 = 0;
  return;
}

/* ==========================================================================
 * Charging   @ 0x0003d062   (32 bytes)
 * called by : Detect_FULL_IN, FUN_0003d2b0
 * string    : "BAT FULL"
 * string    : "Charging"
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void Charging(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if (*DAT_0003d130 == '\0') {
    return;
  }
  if (*DAT_0003d134 == '\0') {
    pcVar2 = str_Charging;
  }
  else {
    pcVar2 = str_BAT_FULL;
  }
  cVar1 = '\x01';
  bVar3 = 0;
  FUN_0003b54e();
  *DAT_0003d0b4 = 1;
  for (uVar4 = 0; pcVar2[uVar4] != '\0'; uVar4 = uVar4 + 1 & 0xff) {
    if (*DAT_0003d0b8 == '\0') {
      FUN_0003c9f2(bVar3,cVar1,1);
    }
    else {
      FUN_0003cb9a(bVar3,cVar1,1);
    }
    bVar3 = bVar3 + 8;
    if (0x70 < bVar3) {
      bVar3 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *DAT_0003d0b8 = '\0';
  return;
}

/* ==========================================================================
 * FUN_0003d508   @ 0x0003d508   (22 bytes)
 * called by : SLEEP, force_ble_sleep_2, set_Update_OLED_2, set_force_sleep
 * calls     : OLED_Clear
 */

void FUN_0003d508(void)

{
  undefined4 *puVar1;
  
  OLED_Clear();
  puVar1 = DAT_0003d694;
  *DAT_0003d694 = 0x3c;
  puVar1[1] = 0x3c;
  puVar1[2] = 0;
  puVar1[3] = 0x3c;
  return;
}

/* ==========================================================================
 * FUN_0003d546   @ 0x0003d546   (22 bytes)
 * called by : SLEEP, force_ble_sleep_2, set_Update_OLED_2, set_force_sleep
 * calls     : FUN_0003c896
 */

void FUN_0003d546(void)

{
  FUN_0003c896(0xae);
  FUN_0003c896(0x8d);
  FUN_0003c896(0x10);
  return;
}

/* ==========================================================================
 * RC32K_2   @ 0x0003e2ac   (88 bytes)
 * called by : FUN_0003e304
 * calls     : addPMU_Reg0x5, dbg_printf, rom_1804C
 * string    : "RC32K-Cali.Compl\n"
 * string    : "RC32K-Cali.End\n"
 */

undefined4 RC32K_2(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  int local_18;
  undefined4 uStack_14;
  
  pcVar1 = DAT_0003e448;
  local_18 = param_3;
  uStack_14 = param_4;
  if (*DAT_0003e448 == '\x02') {
    rom_1804C(&local_18);
    iVar2 = local_18;
    if (99 < (uint)(local_18 - *(int *)(pcVar1 + 4))) {
      dbg_printf(str_RC32K_Cali_Compl);
      addPMU_Reg0x5();
      *(int *)(pcVar1 + 4) = iVar2;
      *pcVar1 = '\x03';
    }
    return 0;
  }
  if (*DAT_0003e448 == '\x03') {
    rom_1804C(&local_18);
    iVar2 = local_18;
    if ((uint)(local_18 - *(int *)(pcVar1 + 4)) < 100) {
      return 0;
    }
    *(int *)(pcVar1 + 4) = local_18;
    dbg_printf(str_RC32K_Cali_End);
    *(int *)(pcVar1 + 4) = iVar2;
  }
  *pcVar1 = '\0';
  return 1;
}


/*############################################################################
 * TIMERS AND SCHEDULING  (2 functions)
 *
 *   0x00029C6C  app_user_ke_timer_stop  (106 B)
 *   0x0002F37E  rtc_timer_start  (68 B)
 ############################################################################*/

/* ==========================================================================
 * app_user_ke_timer_stop   @ 0x00029c6c   (106 bytes)
 * called by : Disconnected, app_mutli_link_change, disconnect, f_usb_isConnected, switch_rf_mode_loop
 * calls     : dbg_printf, rom_073D4
 * string    : "%s \r\n"
 * string    : "app_user_ke_timer_stop"
 */

void app_user_ke_timer_stop(void)

{
  dbg_printf(DAT_00029cdc,DAT_00029cd8 + 0x89);
  *DAT_00029ed0 = *DAT_00029ed0 & 0xfc;
  *DAT_00029dd4 = *DAT_00029dd4 & 0xfffffdff;
  rom_073D4(DAT_00029ed4,3);
  rom_073D4(DAT_00029ed4 + -3,3);
  rom_073D4(DAT_00029ed4 + -5,3);
  rom_073D4(DAT_00029ed4 + -7,3);
  rom_073D4(DAT_00029ed4 + -2,3);
  rom_073D4(DAT_00029ed4 + 1,3);
  *(undefined1 *)(DAT_00029ecc + 0x10) = 0;
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
  
  dbg_printf(str_s_7,PTR_str_rtc_timer_handler_0002f3d4 + 0x12);
  puVar1 = PTR_DAT_0002f3e0;
  DAT_0080000c = DAT_0080000c & 0xfffffeff;
  *(uint *)(PTR_DAT_0002f3e0 + 0xc) = (param_1 & 0x3ff) << 0x11;
  *(undefined **)PTR_DAT_0002f3e8 = PTR_LAB_0002f372_1_0002f3e4;
  *(uint *)puVar1 = *(uint *)puVar1 & 3 | 0xd;
  *(undefined4 *)(puVar1 + 4) = DAT_0002f3ec;
  *DAT_0002f3f0 = *DAT_0002f3f0 | (int)DAT_0002f3f0 >> 0xd;
  return;
}


/*############################################################################
 * DEBUG OUTPUT  (3 functions)
 *
 *   0x00036F84  dbg_printf_2  (2 B)
 *   0x0003B77E  dbg_printf  (4 B)
 *   0x0003B836  uart2_isr  (76 B)
 ############################################################################*/

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
 * called by : FUN_0003c008
 * calls     : FUN_0003b7d4, dbg_printf
 * string    : "uart2_isr"
 */

void uart2_isr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_0003b8c0;
  uVar4 = *(uint *)(PTR_DAT_0003b8c0 + 0x14);
  dbg_printf(&DAT_0003b8d8,DAT_0003b8d4,param_3,param_4,param_4);
  iVar3 = DAT_0003b8cc;
  puVar2 = DAT_0003b8c8;
  if ((uVar4 & 0x42) != 0) {
    while (*(int *)(puVar1 + 8) << 10 < 0) {
      *(char *)(iVar3 + *(int *)(puVar2 + 8)) = (char)((uint)*(undefined4 *)(puVar1 + 0xc) >> 8);
      FUN_0003b7d4(*(undefined1 *)(iVar3 + *(int *)(puVar2 + 8)));
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


/*############################################################################
 * ROM ENTRY POINTS  (71 functions)
 *
 *   0x0000626C  rom_0626C  (1 B)
 *   0x0000692C  rom_0692C  (1 B)
 *   0x000069C4  rom_069C4  (1 B)
 *   0x000069DC  rom_069DC  (1 B)
 *   0x00006A88  rom_06A88  (1 B)
 *   0x00006AB4  rom_06AB4  (1 B)
 *   0x00006AF0  rom_06AF0  (1 B)
 *   0x00006B14  rom_06B14  (1 B)
 *   0x00006B28  rom_06B28  (1 B)
 *   0x00006B5A  rom_06B5A  (1 B)
 *   0x00006BCE  rom_06BCE  (1 B)
 *   0x00006BF8  rom_06BF8  (1 B)
 *   0x00006D2C  rom_06D2C  (1 B)
 *   0x00006DF6  rom_06DF6  (1 B)
 *   0x00006EF4  rom_06EF4  (1 B)
 *   0x00006F26  rom_06F26  (1 B)
 *   0x00006F58  rom_06F58  (1 B)
 *   0x00006F80  rom_06F80  (1 B)
 *   0x00007108  rom_07108  (1 B)
 *   0x00007180  rom_07180  (1 B)
 *   0x000071EA  rom_071EA  (1 B)
 *   0x00007212  rom_07212  (1 B)
 *   0x00007342  rom_07342  (1 B)
 *   0x000073D4  rom_073D4  (1 B)
 *   0x00007434  rom_07434  (1 B)
 *   0x000074A0  rom_074A0  (1 B)
 *   0x00007806  rom_07806  (1 B)
 *   0x0000C1CA  rom_0C1CA  (1 B)
 *   0x00011550  rom_11550  (1 B)
 *   0x0001169A  rom_1169A  (1 B)
 *   0x0001477C  rom_1477C  (1 B)
 *   0x00015C36  rom_15C36  (1 B)
 *   0x00015C40  rom_15C40  (1 B)
 *   0x00015F90  rom_15F90  (1 B)
 *   0x00016216  rom_16216  (1 B)
 *   0x00016508  rom_16508  (1 B)
 *   0x00016930  rom_16930  (1 B)
 *   0x0001695E  rom_1695E  (1 B)
 *   0x00016BCE  rom_16BCE  (1 B)
 *   0x00016CAC  rom_16CAC  (1 B)
 *   0x00016D94  rom_16D94  (1 B)
 *   0x000179A0  rom_179A0  (1 B)
 *   0x000179C6  rom_179C6  (1 B)
 *   0x00017A12  rom_17A12  (1 B)
 *   0x00017A26  rom_17A26  (1 B)
 *   0x00018038  rom_18038  (1 B)
 *   0x0001804C  rom_1804C  (1 B)
 *   0x00018074  rom_18074  (1 B)
 *   0x0001809E  rom_1809E  (1 B)
 *   0x0001855C  rom_1855C  (1 B)
 *   0x000185A6  rom_185A6  (1 B)
 *   0x0001EFCC  rom_1EFCC  (1 B)
 *   0x0001F06A  rom_1F06A  (1 B)
 *   0x0001F16A  rom_1F16A  (1 B)
 *   0x0001F296  rom_1F296  (1 B)
 *   0x0001F3D4  rom_1F3D4  (1 B)
 *   0x0001F3F6  rom_1F3F6  (1 B)
 *   0x0001F61C  rom_1F61C  (1 B)
 *   0x00024F08  rom_24F08  (1 B)
 *   0x00024F24  rom_24F24  (1 B)
 *   0x00024F78  rom_24F78  (1 B)
 *   0x00024F8A  rom_24F8A  (1 B)
 *   0x00024F9C  rom_24F9C  (1 B)
 *   0x00024FEC  rom_24FEC  (1 B)
 *   0x00025002  rom_25002  (1 B)
 *   0x0002501C  rom_2501C  (1 B)
 *   0x00025024  rom_25024  (1 B)
 *   0x00025038  rom_25038  (1 B)
 *   0x0002504C  rom_2504C  (1 B)
 *   0x0002505C  rom_2505C  (1 B)
 *   0x00025078  rom_25078  (1 B)
 ############################################################################*/

/* ==========================================================================
 * rom_0626C   @ 0x0000626c   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_0626C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_0692C   @ 0x0000692c   (1 bytes)
 * called by : rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_0692C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_069C4   @ 0x000069c4   (1 bytes)
 * called by : FUN_0003e04e
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_069C4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_069DC   @ 0x000069dc   (1 bytes)
 * called by : FUN_0003e304
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_069DC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06A88   @ 0x00006a88   (1 bytes)
 * called by : rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06A88(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06AB4   @ 0x00006ab4   (1 bytes)
 * called by : FUN_0003dfd2
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06AB4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06AF0   @ 0x00006af0   (1 bytes)
 * called by : FUN_0003e304
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06AF0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06B14   @ 0x00006b14   (1 bytes)
 * called by : FUN_0003dd8e
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06B14(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06B28   @ 0x00006b28   (1 bytes)
 * called by : FUN_0003dd1c, FUN_0003dd72
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06B28(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06B5A   @ 0x00006b5a   (1 bytes)
 * called by : FUN_0003dd56
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06B5A(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06BCE   @ 0x00006bce   (1 bytes)
 * called by : FUN_0003e03e
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06BCE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06BF8   @ 0x00006bf8   (1 bytes)
 * called by : rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06BF8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06D2C   @ 0x00006d2c   (1 bytes)
 * called by : FUN_0003ef48, FUN_00041160
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06D2C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06DF6   @ 0x00006df6   (1 bytes)
 * called by : FUN_0003efc6, FUN_0003f370, FUN_0003f9a0, FUN_0003fa7a, FUN_0003fbda, FUN_0004008a, ... (+4 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06DF6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06EF4   @ 0x00006ef4   (1 bytes)
 * called by : FUN_00029464, FUN_00029490, FUN_000294f8, FUN_00029530, FUN_000295aa, FUN_0002bf04, ... (+51 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06EF4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06F26   @ 0x00006f26   (1 bytes)
 * called by : APP_PARAM_UPDATE_REQ_IN, FUN_00029464, FUN_00029490, FUN_000294f8, FUN_00029530, FUN_000295aa, ... (+55 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06F26(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06F58   @ 0x00006f58   (1 bytes)
 * called by : gpio
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06F58(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_06F80   @ 0x00006f80   (1 bytes)
 * called by : update
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_06F80(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_07108   @ 0x00007108   (1 bytes)
 * called by : FUN_00029530, FUN_0003ec6a
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_07108(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_07180   @ 0x00007180   (1 bytes)
 * called by : FUN_00029530, FUN_0002d53c, FUN_0003ef48, FUN_0003f9a0, FUN_0003fbda, FUN_0003fd6e, ... (+6 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_07180(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_071EA   @ 0x000071ea   (1 bytes)
 * called by : Disconnected, FUN_00028c66, FUN_0002b18e, FUN_0002b8a2, FUN_0002bd62, FUN_0003300e, ... (+11 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_071EA(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_07212   @ 0x00007212   (1 bytes)
 * called by : FUN_0003ec6a
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_07212(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_07342   @ 0x00007342   (1 bytes)
 * called by : APP_PARAM_UPDATE_REQ_IN, APP_PARAM_UPDATE_REQ_IND, APP_PARAM_UPDATE_REQ_IND_2, APP_PARAM_UPDATE_REQ_IND_3, BLE_PAIR, FUN_0002d53c, ... (+7 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_07342(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_073D4   @ 0x000073d4   (1 bytes)
 * called by : APP_PARAM_UPDATE_REQ_IN, BLE_PAIR, Success_led_2second_2, app_sec_send_security_req, app_user_ke_timer_stop, ble_alert_led_stop, ... (+1 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_073D4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_07434   @ 0x00007434   (1 bytes)
 * called by : gpio
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_07434(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_074A0   @ 0x000074a0   (1 bytes)
 * called by : FUN_0003dc3c
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_074A0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_07806   @ 0x00007806   (1 bytes)
 * called by : FUN_0003dc3c
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_07806(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_0C1CA   @ 0x0000c1ca   (1 bytes)
 * called by : FUN_0003dc3c
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_0C1CA(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_11550   @ 0x00011550   (1 bytes)
 * called by : app_ble_address_update, force_pair_en
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_11550(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1169A   @ 0x0001169a   (1 bytes)
 * called by : FUN_0003dc3c
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1169A(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1477C   @ 0x0001477c   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1477C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_15C36   @ 0x00015c36   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_15C36(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_15C40   @ 0x00015c40   (1 bytes)
 * called by : FUN_0003dd00
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_15C40(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_15F90   @ 0x00015f90   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_15F90(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_16216   @ 0x00016216   (1 bytes)
 * called by : FUN_0003dd3a
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_16216(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_16508   @ 0x00016508   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_16508(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_16930   @ 0x00016930   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_16930(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1695E   @ 0x0001695e   (1 bytes)
 * called by : FUN_0003e1ec
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1695E(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_16BCE   @ 0x00016bce   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_16BCE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_16CAC   @ 0x00016cac   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_16CAC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_16D94   @ 0x00016d94   (1 bytes)
 * called by : FUN_0003dd56
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_16D94(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_179A0   @ 0x000179a0   (1 bytes)
 * called by : FUN_0003ef48
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_179A0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_179C6   @ 0x000179c6   (1 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_179C6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_17A12   @ 0x00017a12   (1 bytes)
 * called by : FUN_0003efc6
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_17A12(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_17A26   @ 0x00017a26   (1 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_17A26(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_18038   @ 0x00018038   (1 bytes)
 * called by : FUN_0003e1ec
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_18038(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1804C   @ 0x0001804c   (1 bytes)
 * called by : FUN_0003c6ce, FUN_0003dc3c, FUN_0003e0bc, FUN_0003e268, FUN_0003e304, RC32K_2
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1804C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_18074   @ 0x00018074   (1 bytes)
 * called by : FUN_0003dd8e, FUN_0003e04e, FUN_0003e304
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_18074(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1809E   @ 0x0001809e   (1 bytes)
 * called by : FUN_0003dd72, FUN_0003e0bc, FUN_0003e1ec
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1809E(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1855C   @ 0x0001855c   (1 bytes)
 * called by : hogpd_report_upd_req_handler
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1855C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_185A6   @ 0x000185a6   (1 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_185A6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1EFCC   @ 0x0001efcc   (1 bytes)
 * called by : FUN_0003e9f8
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1EFCC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1F06A   @ 0x0001f06a   (1 bytes)
 * called by : FUN_0003ef48, FUN_0003f9a0, FUN_00041160
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1F06A(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1F16A   @ 0x0001f16a   (1 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1F16A(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1F296   @ 0x0001f296   (1 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1F296(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1F3D4   @ 0x0001f3d4   (1 bytes)
 * called by : FUN_00041160
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1F3D4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1F3F6   @ 0x0001f3f6   (1 bytes)
 * called by : FUN_00041160
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1F3F6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_1F61C   @ 0x0001f61c   (1 bytes)
 * called by : FUN_0003f9a0
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_1F61C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_24F08   @ 0x00024f08   (1 bytes)
 * called by : FUN_0003dfd2, rwip_driver_init
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_24F08(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_24F24   @ 0x00024f24   (1 bytes)
 * called by : FUN_00032fe6, FUN_0003b6f6, FUN_0003b932, FUN_0003c21e, FUN_0003c2e6, FUN_0003c338, ... (+12 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_24F24(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_24F78   @ 0x00024f78   (1 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_24F78(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_24F8A   @ 0x00024f8a   (1 bytes)
 * called by : FUN_0003dc3c, enter_BLE_normal_app_mode
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_24F8A(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_24F9C   @ 0x00024f9c   (1 bytes)
 * called by : Default_Profile, FLASH_RD_Macro, FLASH_RD_Profile, FLASH_WR_Profile, FLASH_wr_Global, FUN_00029392, ... (+53 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_24F9C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_24FEC   @ 0x00024fec   (1 bytes)
 * called by : Default_Profile, FLASH_RD_Global, FLASH_WR_Profile, FLASH_wr_Global, FUN_00028b00, FUN_00029530, ... (+35 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_24FEC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_25002   @ 0x00025002   (1 bytes)
 * called by : FUN_0003bb38, FUN_0003e516, FUN_0003e5f0
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_25002(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_2501C   @ 0x0002501c   (1 bytes)
 * called by : FUN_000425ea
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_2501C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_25024   @ 0x00025024   (1 bytes)
 * called by : FUN_00028c66, FUN_0003943c, FUN_0003948a, FUN_00039526, FUN_0003dfd2
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_25024(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_25038   @ 0x00025038   (1 bytes)
 * called by : FUN_00028c66, FUN_0003943c, FUN_0003948a, FUN_00039526, FUN_0003dfd2
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_25038(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_2504C   @ 0x0002504c   (1 bytes)
 * called by : FUN_00028c66, FUN_0003943c, FUN_0003948a, FUN_00039526, FUN_0003dfd2, enter_BLE_normal_app_mode
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_2504C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_2505C   @ 0x0002505c   (1 bytes)
 * called by : FUN_00028c66, FUN_0003943c, FUN_0003948a, FUN_00039526, FUN_0003dfd2, enter_BLE_normal_app_mode
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_2505C(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * rom_25078   @ 0x00025078   (1 bytes)
 * called by : FUN_0002d53c, FUN_0002f4da, FUN_00030094, FUN_000319c0, FUN_00031b3e, FUN_0003300e, ... (+16 more)
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_25078(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/*############################################################################
 * UNCLASSIFIED  (110 functions)
 *
 *   0x000287E0  thunk_FUN_000289f0  (4 B)
 *   0x000287E4  thunk_FUN_000289f8  (4 B)
 *   0x000287E8  thunk_FUN_00028a00  (4 B)
 *   0x000287EC  thunk_FUN_00028a08  (4 B)
 *   0x000287F0  thunk_FUN_00028ac0  (4 B)
 *   0x000287F4  thunk_FUN_00028aa0  (4 B)
 *   0x000287F8  thunk_FUN_00028a10  (4 B)
 *   0x000289F0  FUN_000289f0  (4 B)
 *   0x000289F8  FUN_000289f8  (4 B)
 *   0x00028A00  FUN_00028a00  (4 B)
 *   0x00028A08  FUN_00028a08  (4 B)
 *   0x00028A10  FUN_00028a10  (4 B)
 *   0x000294F8  FUN_000294f8  (56 B)
 *   0x00029764  FUN_00029764  (18 B)
 *   0x0002A9D0  FUN_0002a9d0  (116 B)
 *   0x0002AF72  FUN_0002af72  (192 B)
 *   0x0002B334  WDT_REG0X0  (78 B)
 *   0x0002BE06  FUN_0002be06  (22 B)
 *   0x0002BF04  FUN_0002bf04  (44 B)
 *   0x0002C046  FUN_0002c046  (44 B)
 *   0x0002C0DC  FUN_0002c0dc  (12 B)
 *   0x0002C18E  fee4  (14 B)
 *   0x0002CDA6  FUN_0002cda6  (28 B)
 *   0x0002D4A0  FUN_0002d4a0  (68 B)
 *   0x0002DA7E  FUN_0002da7e  (128 B)
 *   0x0002E4CC  APP_PARAM_UPDATE_REQ_IND_3  (38 B)
 *   0x0002F4DA  FUN_0002f4da  (36 B)
 *   0x0002F61C  FUN_0002f61c  (46 B)
 *   0x0002F9E4  FUN_0002f9e4  (4 B)
 *   0x00030F34  FUN_00030f34  (22 B)
 *   0x000324A4  FUN_000324a4  (118 B)
 *   0x00032EAE  FUN_00032eae  (102 B)
 *   0x00032F40  FUN_00032f40  (120 B)
 *   0x00032FE6  FUN_00032fe6  (40 B)
 *   0x00036B14  FUN_00036b14  (34 B)
 *   0x00036F34  FUN_00036f34  (34 B)
 *   0x00036F56  FUN_00036f56  (46 B)
 *   0x0003779A  FUN_0003779a  (42 B)
 *   0x000377D6  FUN_000377d6  (40 B)
 *   0x000382EC  FUN_000382ec  (34 B)
 *   0x0003838C  FUN_0003838c  (8 B)
 *   0x00039696  FUN_00039696  (68 B)
 *   0x00039B36  FUN_00039b36  (76 B)
 *   0x00039C1E  FUN_00039c1e  (38 B)
 *   0x0003A776  FUN_0003a776  (46 B)
 *   0x0003A7A4  FUN_0003a7a4  (316 B)
 *   0x0003A978  spi_waitbusying  (24 B)
 *   0x0003A990  FUN_0003a990  (138 B)
 *   0x0003AA88  FUN_0003aa88  (38 B)
 *   0x0003AAAE  FUN_0003aaae  (38 B)
 *   0x0003AB30  FUN_0003ab30  (48 B)
 *   0x0003AB60  FUN_0003ab60  (48 B)
 *   0x0003AB90  write  (10 B)
 *   0x0003AB9A  read_2  (10 B)
 *   0x0003ABA4  FUN_0003aba4  (78 B)
 *   0x0003AC82  FUN_0003ac82  (34 B)
 *   0x0003ACA4  FUN_0003aca4  (94 B)
 *   0x0003AD9C  FUN_0003ad9c  (68 B)
 *   0x0003B73E  FUN_0003b73e  (12 B)
 *   0x0003B74A  FUN_0003b74a  (22 B)
 *   0x0003B760  FUN_0003b760  (30 B)
 *   0x0003B7CE  FUN_0003b7ce  (6 B)
 *   0x0003B7D4  FUN_0003b7d4  (32 B)
 *   0x0003B882  FUN_0003b882  (58 B)
 *   0x0003B9DC  FUN_0003b9dc  (22 B)
 *   0x0003B9F2  FUN_0003b9f2  (22 B)
 *   0x0003C0E4  FUN_0003c0e4  (48 B)
 *   0x0003C114  FUN_0003c114  (48 B)
 *   0x0003C2E6  FUN_0003c2e6  (82 B)
 *   0x0003C338  FUN_0003c338  (100 B)
 *   0x0003C39C  FUN_0003c39c  (82 B)
 *   0x0003C51A  FUN_0003c51a  (20 B)
 *   0x0003C534  FUN_0003c534  (64 B)
 *   0x0003C57A  FUN_0003c57a  (264 B)
 *   0x0003C738  FUN_0003c738  (34 B)
 *   0x0003C75A  FUN_0003c75a  (164 B)
 *   0x0003DD56  FUN_0003dd56  (28 B)
 *   0x0003E7B4  FUN_0003e7b4  (30 B)
 *   0x0003E976  FUN_0003e976  (66 B)
 *   0x0003E9B8  FUN_0003e9b8  (64 B)
 *   0x0003E9F8  FUN_0003e9f8  (304 B)
 *   0x0003EC18  FUN_0003ec18  (82 B)
 *   0x0003EC6A  FUN_0003ec6a  (116 B)
 *   0x0003EE3A  FUN_0003ee3a  (52 B)
 *   0x0003EFC6  FUN_0003efc6  (36 B)
 *   0x0003EFEE  FUN_0003efee  (6 B)
 *   0x0003EFF4  FUN_0003eff4  (54 B)
 *   0x0003F02A  FUN_0003f02a  (60 B)
 *   0x0003F066  FUN_0003f066  (42 B)
 *   0x0003F370  FUN_0003f370  (28 B)
 *   0x0003F464  FUN_0003f464  (6 B)
 *   0x0003FA7A  FUN_0003fa7a  (28 B)
 *   0x0003FB64  FUN_0003fb64  (6 B)
 *   0x0003FD3A  FUN_0003fd3a  (18 B)
 *   0x0004008A  FUN_0004008a  (28 B)
 *   0x0004012E  FUN_0004012e  (6 B)
 *   0x00040528  FUN_00040528  (28 B)
 *   0x00040BE8  FUN_00040be8  (4 B)
 *   0x00040D28  FUN_00040d28  (12 B)
 *   0x00041540  FUN_00041540  (16 B)
 *   0x00041552  FUN_00041552  (34 B)
 *   0x00041574  FUN_00041574  (6 B)
 *   0x0004157A  FUN_0004157a  (276 B)
 *   0x0004186C  FUN_0004186c  (32 B)
 *   0x00041EFC  FUN_00041efc  (42 B)
 *   0x00041F5E  FUN_00041f5e  (4 B)
 *   0x0004294C  FUN_0004294c  (18 B)
 *   0x00042AE0  thunk_FUN_00042af0  (4 B)
 *   0x00042AF0  FUN_00042af0  (24 B)
 *   0x0004407A  FUN_0004407a  (4 B)
 ############################################################################*/

/* ==========================================================================
 * thunk_FUN_000289f0   @ 0x000287e0   (4 bytes)
 */

void thunk_FUN_000289f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_000289f4)();
  return;
}

/* ==========================================================================
 * thunk_FUN_000289f8   @ 0x000287e4   (4 bytes)
 */

void thunk_FUN_000289f8(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_000289fc)();
  return;
}

/* ==========================================================================
 * thunk_FUN_00028a00   @ 0x000287e8   (4 bytes)
 */

void thunk_FUN_00028a00(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00028a04)();
  return;
}

/* ==========================================================================
 * thunk_FUN_00028a08   @ 0x000287ec   (4 bytes)
 */

void thunk_FUN_00028a08(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00028a0c)();
  return;
}

/* ==========================================================================
 * thunk_FUN_00028ac0   @ 0x000287f0   (4 bytes)
 */

void thunk_FUN_00028ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  FUN_0003c008();
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
  
  FUN_0003c0a8();
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
  (*DAT_00028a14)();
  return;
}

/* ==========================================================================
 * FUN_000289f0   @ 0x000289f0   (4 bytes)
 */

void FUN_000289f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_000289f4)();
  return;
}

/* ==========================================================================
 * FUN_000289f8   @ 0x000289f8   (4 bytes)
 */

void FUN_000289f8(void)

{
                    /* WARNING: Could not recover jumptable at 0x000289f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_000289fc)();
  return;
}

/* ==========================================================================
 * FUN_00028a00   @ 0x00028a00   (4 bytes)
 */

void FUN_00028a00(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00028a04)();
  return;
}

/* ==========================================================================
 * FUN_00028a08   @ 0x00028a08   (4 bytes)
 */

void FUN_00028a08(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00028a0c)();
  return;
}

/* ==========================================================================
 * FUN_00028a10   @ 0x00028a10   (4 bytes)
 */

void FUN_00028a10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00028a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00028a14)();
  return;
}

/* ==========================================================================
 * FUN_000294f8   @ 0x000294f8   (56 bytes)
 * calls     : rom_06EF4, rom_06F26, rom_24F9C
 */

void FUN_000294f8(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(DAT_000297c8 + 5,7,3,0x23);
  iVar1 = DAT_0002977c;
  *puVar2 = 0xaa;
  puVar2[1] = *(undefined1 *)(iVar1 + 3);
  *(undefined2 *)(puVar2 + 2) = 10;
  rom_24F9C(puVar2 + 4,&DAT_000297e4,10);
  rom_06F26(puVar2);
  *(undefined1 *)(iVar1 + 4) = 3;
  *(undefined1 *)(iVar1 + 5) = 0xaa;
  return;
}

/* ==========================================================================
 * FUN_00029764   @ 0x00029764   (18 bytes)
 * calls     : rom_24F9C
 */

undefined1 FUN_00029764(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_0002977c;
  rom_24F9C(param_1,DAT_0002977c + 10,*(undefined1 *)(DAT_0002977c + 9));
  return *(undefined1 *)(iVar1 + 9);
}

/* ==========================================================================
 * FUN_0002a9d0   @ 0x0002a9d0   (116 bytes)
 */

void FUN_0002a9d0(void)

{
  char cVar1;
  short sVar2;
  undefined *puVar3;
  
  puVar3 = PTR_DAT_0002ada4;
  cVar1 = *PTR_DAT_0002ada4;
  *PTR_DAT_0002ada4 = cVar1 + 1U;
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
  *(undefined2 *)PTR_DAT_0002ada8 = *(undefined2 *)(puVar3 + 4);
  *(undefined2 *)PTR_DAT_0002adac = *(undefined2 *)(puVar3 + 6);
  *PTR_DAT_0002adb0 = 1;
  return;
}

/* ==========================================================================
 * FUN_0002af72   @ 0x0002af72   (192 bytes)
 */

void FUN_0002af72(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  
  if (*DAT_0002b0dc != '\0') {
    *DAT_0002b0dc = *DAT_0002b0dc + -1;
  }
  if (*DAT_0002b0e0 != '\0') {
    *DAT_0002b0e0 = *DAT_0002b0e0 + -1;
  }
  if (*DAT_0002b0e4 != '\0') {
    *DAT_0002b0e4 = *DAT_0002b0e4 + -1;
  }
  if (*DAT_0002b0e8 != '\0') {
    *DAT_0002b0e8 = *DAT_0002b0e8 + -1;
  }
  pbVar3 = DAT_0002b0f0;
  bVar1 = *(byte *)(DAT_0002b0ec + 0x16);
  bVar2 = *DAT_0002b0f0;
  *DAT_0002b0f0 = bVar2 + 1;
  if (bVar1 <= (byte)(bVar2 + 1)) {
    *pbVar3 = 0;
    *DAT_0002b0f4 = 1;
    *DAT_0002b0f8 = 1;
  }
  puVar4 = DAT_0002b100;
  pbVar3 = DAT_0002b0fc;
  bVar1 = *DAT_0002b0fc;
  *DAT_0002b0fc = bVar1 + 1;
  *puVar4 = 1;
  if (1 < (byte)(bVar1 + 1)) {
    *pbVar3 = 0;
    *DAT_0002b104 = 1;
    if (*DAT_0002b108 != 0) {
      *DAT_0002b108 = *DAT_0002b108 + -1;
    }
    if ((*DAT_0002b10c != '\0') && (*DAT_0002b110 != '\0')) {
      *DAT_0002b10c = *DAT_0002b10c + -1;
    }
    pbVar3 = DAT_0002b114;
    bVar1 = *DAT_0002b114;
    *DAT_0002b114 = bVar1 + 1;
    if (4 < (byte)(bVar1 + 1)) {
      *pbVar3 = 0;
      *DAT_0002b118 = 1;
      *DAT_0002b11c = 1;
    }
    pbVar3 = DAT_0002b120;
    bVar1 = *DAT_0002b120;
    *DAT_0002b120 = bVar1 + 1;
    if (0x18 < (byte)(bVar1 + 1)) {
      *pbVar3 = 0;
      *DAT_0002b124 = 1;
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
  int iVar1;
  
  dbg_printf(str_WDT_REG0X0_x,*DAT_0002b5ec);
  iVar1 = DAT_0002b524;
  dbg_printf(str_reg30_x,*(undefined4 *)(DAT_0002b524 + 0x80));
  dbg_printf(str_reg31_x,*(undefined4 *)(iVar1 + 0x84));
  dbg_printf(str_reg33_x,*(undefined4 *)(iVar1 + 0x8c));
  dbg_printf(str_reg35_x,*(undefined4 *)(iVar1 + 0x94));
  iVar1 = DAT_0002b638;
  dbg_printf(str_reg03_x,*(undefined4 *)(DAT_0002b638 + 0xc));
  dbg_printf(str_reg04_x,*(undefined4 *)(iVar1 + 0x10));
  dbg_printf(str_reg10_x,*DAT_0002b654);
  return;
}

/* ==========================================================================
 * FUN_0002be06   @ 0x0002be06   (22 bytes)
 * calls     : dbg_printf
 */

void FUN_0002be06(void)

{
  int iVar1;
  
  iVar1 = DAT_0002be68;
  *(undefined1 *)(DAT_0002be68 + 0x10) = 0;
  dbg_printf(str_free_d,*(undefined1 *)(iVar1 + 0x11));
  *(undefined1 *)(iVar1 + 0x11) = 0;
  return;
}

/* ==========================================================================
 * FUN_0002bf04   @ 0x0002bf04   (44 bytes)
 * calls     : rom_06EF4, rom_06F26
 */

void FUN_0002bf04(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(PTR_DAT_0002bfc0,7,3,0x20);
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
 * FUN_0002c046   @ 0x0002c046   (44 bytes)
 * calls     : rom_06EF4, rom_06F26
 */

void FUN_0002c046(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(DAT_0002c0d8,7,3,0xe);
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
 * FUN_0002c0dc   @ 0x0002c0dc   (12 bytes)
 * calls     : rom_24FEC
 */

void FUN_0002c0dc(void)

{
  rom_24FEC(DAT_0002c2b8,3);
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
 * FUN_0002cda6   @ 0x0002cda6   (28 bytes)
 * calls     : dbg_printf, rom_06F26
 * string    : "0x%x "
 */

undefined4 FUN_0002cda6(void)

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
 * FUN_0002d4a0   @ 0x0002d4a0   (68 bytes)
 */

ulonglong FUN_0002d4a0(int *param_1,undefined *param_2,undefined4 param_3)

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
       ((undefined *)((uint)local_20 & 0xffff) == PTR_DAT_0002d8a4)) break;
    uVar2 = uVar2 - 1 & 0xff;
  }
  uVar1 = (*(code *)puVar3[1])(param_2,param_3,3);
  return CONCAT44(local_20,uVar1) & 0xffffffff000000ff;
}

/* ==========================================================================
 * FUN_0002da7e   @ 0x0002da7e   (128 bytes)
 * calls     : dbg_printf, rom_06EF4, rom_06F26, rom_24F9C
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002da7e(void)

{
  undefined1 *puVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  dbg_printf(_DAT_0002de5c,PTR_str_appm_gapm_resolv_dev_addr_0002de58);
  puVar1 = (undefined1 *)rom_06EF4(PTR_DAT_0002de60,7,3,0x18);
  *puVar1 = 0x17;
  puVar1[1] = 1;
  rom_24F9C(puVar1 + 2,&stack0x00000000,6);
  dbg_printf(str_addr);
  uVar2 = 0;
  do {
    dbg_printf(0x2de6c,puVar1[uVar2 + 2]);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  dbg_printf(&DAT_0002de70);
  rom_24F9C(puVar1 + 8,&stack0x00000008,0x10);
  dbg_printf(0x2de74);
  uVar2 = 0;
  do {
    dbg_printf(0x2de6c,puVar1[uVar2 + 8]);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  dbg_printf(&DAT_0002de70);
  rom_06F26(puVar1);
                    /* WARNING: Could not recover jumptable at 0x0002dafc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* ==========================================================================
 * APP_PARAM_UPDATE_REQ_IND_3   @ 0x0002e4cc   (38 bytes)
 * calls     : dbg_printf, rom_07342
 * string    : "APP_PARAM_UPDATE_REQ_IND--8  update param.... = %d\r\n"
 */

undefined4 APP_PARAM_UPDATE_REQ_IND_3(void)

{
  undefined1 *puVar1;
  undefined1 unaff_r5;
  undefined1 *unaff_r6;
  char *unaff_r7;
  
  puVar1 = DAT_0002e804;
  if (*unaff_r7 != '\0') {
    *unaff_r6 = unaff_r5;
    *puVar1 = unaff_r5;
    dbg_printf(str_APP_PARAM_UPDATE_REQ_IND_8_update_param_d,*PTR_DAT_0002e7b8);
    rom_07342(PTR_DAT_0002e634,3,2);
  }
  return 0;
}

/* ==========================================================================
 * FUN_0002f4da   @ 0x0002f4da   (36 bytes)
 * calls     : dbg_printf, rom_25078
 */

void FUN_0002f4da(void)

{
  int extraout_r1;
  
  rom_25078();
  dbg_printf(&LAB_0002f6c8,(extraout_r1 >> 0xc) + 0x2d);
  return;
}

/* ==========================================================================
 * FUN_0002f61c   @ 0x0002f61c   (46 bytes)
 * calls     : dbg_printf
 */

void FUN_0002f61c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
 * FUN_0002f9e4   @ 0x0002f9e4   (4 bytes)
 */

void FUN_0002f9e4(void)

{
  int iVar1;
  undefined *puVar2;
  char *pcVar3;
  
  if (*PTR_DAT_0002fd00 == '\0' && *PTR_DAT_0002fd04 == '\0') {
    pcVar3 = (char *)(DAT_0002fcdc + 9);
    rom_24FEC(pcVar3,0x84);
    puVar2 = PTR_DAT_0002fd08;
    iVar1 = DAT_0002fcdc;
    *(char **)(DAT_0002fcdc + 4) = pcVar3;
    if (*puVar2 != '\0') {
      *pcVar3 = *puVar2;
      *(int *)(iVar1 + 4) = iVar1 + 10;
    }
    FUN_000333f0();
    *DAT_0002fca0 = 0xd;
  }
  return;
}

/* ==========================================================================
 * FUN_00030f34   @ 0x00030f34   (22 bytes)
 */

void FUN_00030f34(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
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
  iVar2 = FUN_0003e552(uVar3,&uStack_c,&uStack_10);
  iVar1 = DAT_00031008;
  if (iVar2 == 0) {
    if ((uStack_10 & 0xff) < 9) {
      *(byte *)(DAT_00031008 + 0x16) = (byte)uStack_10;
      *(byte *)(iVar1 + 0x17) = ~(byte)uStack_10;
    }
  }
  FUN_0003c2c6();
  dbg_printf(str_s_read_data_x_Polling_x,DAT_000310c4,uStack_10 & 0xff,*(undefined1 *)(iVar1 + 0x16)
            );
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * FUN_000324a4   @ 0x000324a4   (118 bytes)
 */

void FUN_000324a4(int param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined1 uVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  
  iVar8 = DAT_000325e4;
  pbVar4 = DAT_000325d8;
  *DAT_000325d8 = 0;
  pcVar6 = DAT_000325e0;
  puVar5 = DAT_000325dc;
  bVar1 = *(byte *)(iVar8 + 0x19);
  while( true ) {
    bVar3 = *pbVar4;
    uVar10 = (uint)bVar3;
    if (bVar1 <= uVar10) {
      return;
    }
    iVar11 = uVar10 * 2 + iVar8;
    *puVar5 = *(undefined1 *)(iVar11 + 0x1a);
    cVar2 = *(char *)(iVar11 + 0x1b);
    *pcVar6 = cVar2;
    if (cVar2 == -10) break;
    *pbVar4 = bVar3 + 1;
  }
  *pbVar4 = (byte)(uVar10 + 2);
  iVar8 = (uVar10 + 2 & 0xff) * 2 + iVar8;
  uVar7 = *(undefined1 *)(iVar8 + 0x1a);
  *puVar5 = uVar7;
  param_1 = (uint)CONCAT11(uVar7,*(char *)(iVar8 + 0x1b)) + param_1;
  *pcVar6 = *(char *)(iVar8 + 0x1b);
  *(char *)(iVar8 + 0x1b) = (char)param_1;
  *(char *)(iVar8 + 0x1a) = (char)((uint)param_1 >> 8);
  if (((*DAT_0003258c == '\x01') || (*DAT_0003258c == '\x02')) && (*DAT_00032598 == '\0')) {
    uVar7 = 1;
    puVar9 = DAT_000325e8;
  }
  else {
    uVar7 = 9;
    puVar9 = PTR_DAT_00032554;
  }
  *puVar9 = uVar7;
  return;
}

/* ==========================================================================
 * FUN_00032eae   @ 0x00032eae   (102 bytes)
 */

void FUN_00032eae(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = PTR_DAT_00032fcc;
  iVar6 = 9 - ((byte)PTR_DAT_00032fcc[0xc] & 0xf);
  iVar1 = (uint)(byte)PTR_DAT_00032fcc[-0x13] * 3;
  uVar3 = func_0x00024f50(PTR_DAT_00032fcc[iVar1 + -0x15],iVar6,param_3,param_4,param_4);
  uVar4 = func_0x00024f50(puVar2[iVar1 + -0x14],iVar6);
  uVar5 = func_0x00024f50(puVar2[iVar1 + -0x13],iVar6);
  *PTR_DAT_00032fbc = (char)((uVar3 & 0xff) >> 2);
  puVar2 = PTR_DAT_00032fc4;
  *PTR_DAT_00032fc0 = (char)((uVar4 & 0xff) >> 2);
  *puVar2 = (char)((uVar5 & 0xff) >> 2);
  puVar2 = PTR_DAT_00032fd4;
  *PTR_DAT_00032fd0 = 1;
  *puVar2 = 0;
  *PTR_DAT_00032fd8 = 1;
  return;
}

/* ==========================================================================
 * FUN_00032f40   @ 0x00032f40   (120 bytes)
 */

byte FUN_00032f40(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  uint uVar5;
  
  puVar1 = PTR_DAT_00032fbc;
  uVar5 = (uint)(byte)*PTR_DAT_00032fc8;
  bVar4 = *PTR_DAT_00032fe0;
  if (((*PTR_DAT_00032fc8 & 1) != 0) && ((byte)*PTR_DAT_00032fbc < bVar4)) {
    *PTR_DAT_00032fbc = *PTR_DAT_00032fbc + 1;
  }
  puVar2 = PTR_DAT_00032fc0;
  if (((int)(uVar5 << 0x1e) < 0) && ((byte)*PTR_DAT_00032fc0 < bVar4)) {
    *PTR_DAT_00032fc0 = *PTR_DAT_00032fc0 + 1;
  }
  puVar3 = PTR_DAT_00032fc4;
  if (((int)(uVar5 << 0x1d) < 0) && ((byte)*PTR_DAT_00032fc4 < bVar4)) {
    *PTR_DAT_00032fc4 = *PTR_DAT_00032fc4 + 1;
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
 * FUN_00032fe6   @ 0x00032fe6   (40 bytes)
 * calls     : rom_24F24
 */

void FUN_00032fe6(char *param_1)

{
  short *psVar1;
  short sVar2;
  
  psVar1 = DAT_00033364;
  if (((*param_1 == '\x01') || (*param_1 == '\x02')) && (*DAT_00033360 == '\0')) {
    if (*DAT_00033364 != 0) {
      sVar2 = rom_24F24(*DAT_00033364,10);
      *psVar1 = sVar2 + 1;
    }
  }
  return;
}

/* ==========================================================================
 * FUN_00036b14   @ 0x00036b14   (34 bytes)
 */

void FUN_00036b14(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00036d84;
  *(int *)(DAT_00036d84 + 0xd8) = param_3 + 0x68;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(uint *)(iVar1 + 0xdc) = (uint)*(byte *)(param_1 + uVar2);
  }
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * FUN_00036f34   @ 0x00036f34   (34 bytes)
 * calls     : FUN_0003b73e
 */

void FUN_00036f34(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  for (uVar3 = 0; uVar3 < param_1; uVar3 = uVar3 + 1 & 0xff) {
    if (param_3 == 0) {
      cVar2 = *(char *)(param_2 + uVar3);
    }
    else {
      FUN_0003b73e(0x20);
      bVar1 = *(byte *)(param_2 + uVar3) >> 4;
      if (bVar1 < 10) {
        cVar2 = '0';
      }
      else {
        cVar2 = '7';
      }
      FUN_0003b73e(cVar2 + bVar1);
      bVar1 = *(byte *)(param_2 + uVar3) & 0xf;
      if (bVar1 < 10) {
        cVar2 = '0';
      }
      else {
        cVar2 = '7';
      }
      cVar2 = cVar2 + bVar1;
    }
    FUN_0003b73e(cVar2);
  }
  return;
}

/* ==========================================================================
 * FUN_00036f56   @ 0x00036f56   (46 bytes)
 * calls     : FUN_0003b73e
 */

void FUN_00036f56(uint param_1)

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
      FUN_0003b73e(iVar3 + param_1);
      bVar1 = *(byte *)(unaff_r5 + unaff_r4) & 0xf;
      if (bVar1 < 10) {
        cVar2 = '0';
      }
      else {
        cVar2 = '7';
      }
      cVar2 = cVar2 + bVar1;
      while( true ) {
        FUN_0003b73e(cVar2);
        unaff_r4 = unaff_r4 + 1 & 0xff;
        if (unaff_r6 <= unaff_r4) {
          return;
        }
        if (unaff_r7 != 0) break;
        cVar2 = *(char *)(unaff_r5 + unaff_r4);
      }
      FUN_0003b73e(0x20);
      param_1 = (uint)(*(byte *)(unaff_r5 + unaff_r4) >> 4);
      if (param_1 < 10) break;
      iVar3 = 0x37;
    }
  } while( true );
}

/* ==========================================================================
 * FUN_0003779a   @ 0x0003779a   (42 bytes)
 */

byte * FUN_0003779a(byte *param_1,int param_2,uint param_3)

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
 * FUN_000377d6   @ 0x000377d6   (40 bytes)
 */

byte * FUN_000377d6(byte *param_1,int param_2,uint param_3)

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
 * FUN_000382ec   @ 0x000382ec   (34 bytes)
 * calls     : dbg_printf
 * string    : "%.2x "
 */

void FUN_000382ec(void)

{
  uint unaff_r4;
  int unaff_r5;
  int unaff_r6;
  
  do {
    dbg_printf(str_s2x,*(undefined1 *)(unaff_r6 + unaff_r4));
    if ((~unaff_r4 & 7) == 0) {
      dbg_printf(&DAT_00038340);
    }
    unaff_r4 = unaff_r4 + 1;
  } while ((int)unaff_r4 < unaff_r5);
  dbg_printf(s___00038344);
  return;
}

/* ==========================================================================
 * FUN_0003838c   @ 0x0003838c   (8 bytes)
 */

int FUN_0003838c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00038394 + 0x40;
  iVar3 = 0;
  while( true ) {
    if (2 < iVar3) {
      return 0;
    }
    iVar1 = FUN_0004245e(iVar3 * 0xc + iVar2);
    if (iVar1 == param_1) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3 * 0xc + iVar2 + 4;
}

/* ==========================================================================
 * FUN_00039696   @ 0x00039696   (68 bytes)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00039696(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = _DAT_000399ac;
  piVar1 = DAT_000399a0;
  do {
  } while (*DAT_000399a0 < 0);
  iVar3 = *(int *)(DAT_0003999c + 8);
  if (iVar3 != DAT_000399a4) {
    if ((iVar3 == DAT_000399a8) || (iVar3 == DAT_000399a8 + -1)) {
      uVar4 = 0x10000;
    }
    else {
      uVar4 = 0x80000;
    }
    DAT_000399a0[7] = DAT_000399a0[7] & 0x7ffffffU | uVar4;
    *piVar1 = iVar2;
    do {
    } while (*piVar1 < 0);
  }
  return;
}

/* ==========================================================================
 * FUN_00039b36   @ 0x00039b36   (76 bytes)
 */

void FUN_00039b36(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar1 = PTR_DAT_00039c04;
  uVar3 = param_4 * 2;
  puVar2 = (uint *)(PTR_DAT_00039c04 + 0xc0);
  if (param_4 < 0x10) {
    *puVar2 = *puVar2 & ~(3 << (uVar3 & 0xff));
    *puVar2 = *puVar2 | param_2 << (uVar3 & 0xff);
  }
  else {
    *(uint *)(PTR_DAT_00039c04 + 0xc4) =
         *(uint *)(PTR_DAT_00039c04 + 0xc4) & ~(3 << (uVar3 - 0x20 & 0xff));
    *(uint *)(puVar1 + 0xc4) = param_2 << (uVar3 - 0x20 & 0xff) | *(uint *)(puVar1 + 0xc4);
  }
  uVar3 = 1 << (param_4 & 0xff);
  *(uint *)(puVar1 + 0xcc) = *(uint *)(puVar1 + 0xcc) | uVar3;
  *(uint *)(puVar1 + 0xd4) = *(uint *)(puVar1 + 0xd4) | uVar3;
  *(uint *)(PTR_DAT_00039c08 + 0xc) = *(uint *)(PTR_DAT_00039c08 + 0xc) | uVar3;
  return;
}

/* ==========================================================================
 * FUN_00039c1e   @ 0x00039c1e   (38 bytes)
 */

uint FUN_00039c1e(uint param_1,int param_2,int param_3,int param_4)

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
 * FUN_0003a776   @ 0x0003a776   (46 bytes)
 */

void FUN_0003a776(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0003a8e0;
  uVar2 = *(uint *)(param_2 + 0x10);
  *(uint *)(DAT_0003a8e0 + 0x90) = *(uint *)(DAT_0003a8e0 + 0x90) & 0xffefffff;
  *(uint *)(DAT_0003a8e0 + 0x10) = uVar2 | 0x20000000;
  *(uint *)(iVar1 + 0x90) = *(uint *)(iVar1 + 0x90) & 0xfffff87f;
  *(uint *)(iVar1 + 0x90) = *(uint *)(iVar1 + 0x90) | param_1 << 7;
  return;
}

/* ==========================================================================
 * FUN_0003a7a4   @ 0x0003a7a4   (316 bytes)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003a7a4(int param_1)

{
  uint *puVar1;
  
  puVar1 = _DAT_0003a8fc;
  if (param_1 == 0) {
    uRam00800030 = uRam00800030 & 0xffffffdf | 0x10;
    _DAT_0003a8fc[8] = (_DAT_0003a8fc[8] & 0xfffffc00) + 0x40;
    puVar1[9] = (puVar1[9] & 0xfffffc00) + 0x40;
    puVar1[10] = (puVar1[10] & 0xfffffc00) + 0x40;
    puVar1[0xb] = (puVar1[0xb] & 0xfffffc00) + 0x40;
    puVar1[0xc] = (puVar1[0xc] & 0xfffffc00) + 0x40;
    puVar1[0xd] = (puVar1[0xd] & 0xfffffc00) + 0x40;
    puVar1[0xe] = (puVar1[0xe] & 0xfffffc00) + 0x40;
    puVar1[0xf] = (puVar1[0xf] & 0xfffffc00) + 0x40;
  }
  else {
    if (param_1 != 1) {
      uRam00800030 = uRam00800030 | 0x10;
      if (param_1 == 2) {
        uRam00800030 = 0x34;
        *_DAT_0003a8fc = (*_DAT_0003a8fc & 0xfffffc00) + 0x40;
        puVar1[1] = (puVar1[1] & 0xfffffc00) + 0x40;
        puVar1[2] = (puVar1[2] & 0xfffffc00) + 0x40;
        puVar1[3] = (puVar1[3] & 0xfffffc00) + 0x40;
        puVar1[4] = (puVar1[4] & 0xfffffc00) + 0x40;
        puVar1[5] = (puVar1[5] & 0xfffffc00) + 0x40;
        puVar1[6] = (puVar1[6] & 0xfffffc00) + 0x40;
        puVar1[7] = (puVar1[7] & 0xfffffc00) + 0x40;
      }
      return;
    }
    uRam00800030 = uRam00800030 | 0x30;
    *_DAT_0003a8fc = (*_DAT_0003a8fc & 0xfffffc00) + 0x40;
    puVar1[1] = (puVar1[1] & 0xfffffc00) + 0x40;
    puVar1[2] = (puVar1[2] & 0xfffffc00) + 0x40;
    puVar1[3] = (puVar1[3] & 0xfffffc00) + 0x40;
    puVar1[4] = (puVar1[4] & 0xfffffc00) + 0x40;
    puVar1[5] = (puVar1[5] & 0xfffffc00) + 0x40;
    puVar1[6] = (puVar1[6] & 0xfffffc00) + 0x40;
    puVar1[7] = (puVar1[7] & 0xfffffc00) + 0x40;
  }
  uRam00800030 = uRam00800030 & 0xfffffff8 | 0xf;
  return;
}

/* ==========================================================================
 * spi_waitbusying   @ 0x0003a978   (24 bytes)
 * called by : FUN_0003a990, FUN_0003ab30, FUN_0003ab60
 * calls     : dbg_printf
 * string    : "spi_waitbusying\n"
 */

void spi_waitbusying(void)

{
  int iVar1;
  
  iVar1 = DAT_0003ad0c;
  while (*(char *)(iVar1 + 1) == '\0') {
    dbg_printf(str_spi_waitbusying);
  }
  *(undefined1 *)(iVar1 + 1) = 0;
  return;
}

/* ==========================================================================
 * FUN_0003a990   @ 0x0003a990   (138 bytes)
 * called by : FUN_0003aba4
 * calls     : spi_waitbusying
 */

void FUN_0003a990(byte *param_1,uint param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  byte *local_24;
  
  uVar2 = param_4;
  if (param_4 < param_2) {
    uVar2 = param_2;
  }
  if (uVar2 < 0x41) {
    spi_waitbusying();
    iVar1 = DAT_0003ad08;
    *(uint *)(DAT_0003ad08 + 8) = *(uint *)(DAT_0003ad08 + 8) | 0x2000;
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x4000;
    *DAT_0003ad24 = *DAT_0003ad24 | 0x40;
    *(uint *)(iVar1 + 4) = uVar2 << 0x14 | uVar2 << 8;
    do {
      local_24 = param_1;
    } while (-1 < *(int *)(iVar1 + 8) << 0x1e);
    while (bVar3 = uVar2 != 0, uVar2 = uVar2 - 1, bVar3) {
      if (param_2 == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      else {
        *(uint *)(iVar1 + 0xc) = (uint)*local_24;
        local_24 = local_24 + 1;
        param_2 = param_2 - 1;
      }
    }
    *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 0xf;
    if (param_4 != 0) {
      do {
      } while (*(char *)(DAT_0003ad0c + 1) == '\0');
      while (bVar3 = param_4 != 0, param_4 = param_4 - 1, bVar3) {
        *param_3 = (char)*(undefined4 *)(iVar1 + 0xc);
        param_3 = param_3 + 1;
      }
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0003aa88   @ 0x0003aa88   (38 bytes)
 * called by : FUN_0003ab30
 */

void FUN_0003aa88(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0003ad08;
  *(uint *)(DAT_0003ad08 + 8) = *(uint *)(DAT_0003ad08 + 8) | 0x2000;
  *DAT_0003ad24 = *DAT_0003ad24 | 0x40;
  *(int *)(iVar1 + 4) = param_1 << 8;
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 5;
  return;
}

/* ==========================================================================
 * FUN_0003aaae   @ 0x0003aaae   (38 bytes)
 * called by : FUN_0003ab60
 */

void FUN_0003aaae(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0003ad08;
  *(uint *)(DAT_0003ad08 + 8) = *(uint *)(DAT_0003ad08 + 8) | 0x2000;
  *DAT_0003ad24 = *DAT_0003ad24 | 0x40;
  *(int *)(iVar1 + 4) = param_1 << 0x14;
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 10;
  return;
}

/* ==========================================================================
 * FUN_0003ab30   @ 0x0003ab30   (48 bytes)
 * calls     : FUN_0003aa88, FUN_0003c0e4, spi_waitbusying
 */

void FUN_0003ab30(undefined4 param_1,uint param_2,undefined4 param_3)

{
  if (DAT_0003ad2c < param_2) {
    param_2 = DAT_0003ad2c;
  }
  *(undefined4 *)(DAT_0003ad0c + 4) = param_3;
  spi_waitbusying();
  FUN_0003c0e4(0,4,param_1,DAT_0003ad08 + 0xc,param_2,0);
  FUN_0003aa88(param_2);
  return;
}

/* ==========================================================================
 * FUN_0003ab60   @ 0x0003ab60   (48 bytes)
 * calls     : FUN_0003aaae, FUN_0003c114, spi_waitbusying
 */

void FUN_0003ab60(undefined4 param_1,uint param_2,undefined4 param_3)

{
  if (DAT_0003ad2c < param_2) {
    param_2 = DAT_0003ad2c;
  }
  *(undefined4 *)(DAT_0003ad0c + 8) = param_3;
  spi_waitbusying();
  FUN_0003c114(0,4,DAT_0003ad08 + 0xc,param_1,param_2,0);
  FUN_0003aaae(param_2);
  return;
}

/* ==========================================================================
 * write   @ 0x0003ab90   (10 bytes)
 * calls     : dbg_printf
 * string    : "write complete\r\n"
 */

void write(void)

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
 * FUN_0003aba4   @ 0x0003aba4   (78 bytes)
 * calls     : FUN_0003a990, dbg_printf, rom_24FEC
 */

void FUN_0003aba4(void)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_90 [64];
  char acStack_50 [68];
  
  cVar1 = *(char *)(DAT_0003ad54 + 1);
  *(char *)(DAT_0003ad54 + 1) = cVar1 + '\x01';
  iVar2 = 0;
  do {
    acStack_50[iVar2] = (char)iVar2 + cVar1 + '\x01';
    auStack_90[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  FUN_0003a990(acStack_50,0x40,auStack_90);
  iVar2 = 0;
  do {
    dbg_printf(str_spi_rbuf_d_x,iVar2,auStack_90[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  rom_24FEC(auStack_90,0x40);
  return;
}

/* ==========================================================================
 * FUN_0003ac82   @ 0x0003ac82   (34 bytes)
 */

void FUN_0003ac82(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0003ad08;
  *DAT_0003ad08 = 0;
  DAT_0080000c = DAT_0080000c | 0x2000;
  *DAT_0003ad24 = *DAT_0003ad24 & 0xffffffbf;
  puVar1[2] = 0;
  return;
}

/* ==========================================================================
 * FUN_0003aca4   @ 0x0003aca4   (94 bytes)
 * calls     : dbg_printf, rom_24FEC
 * string    : "spi len=%x:"
 */

void FUN_0003aca4(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  
  pcVar1 = DAT_0003ad54;
  if (*DAT_0003ad54 == '\x01') {
    dbg_printf(str_spi_len_x,DAT_0003ad54[2]);
    iVar6 = DAT_0003ad0c + 0x5c;
    for (iVar5 = 0; iVar5 < (int)(uint)(byte)pcVar1[2]; iVar5 = iVar5 + 1) {
      dbg_printf(&DAT_0003ad94,*(undefined1 *)(iVar6 + iVar5));
    }
    dbg_printf(&DAT_0003ad98);
    rom_24FEC(DAT_0003ad0c + 0x5c,0x50);
    iVar5 = DAT_0003ad08;
    iVar2 = 0;
    iVar3 = DAT_0003ad0c + 0xc;
    do {
      bVar4 = *(char *)(iVar3 + iVar2) + 1;
      *(byte *)(iVar3 + iVar2) = bVar4;
      *(uint *)(iVar5 + 0xc) = (uint)bVar4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10);
    *(int *)(pcVar1 + 8) = iVar6;
    *(int *)(pcVar1 + 4) = iVar3;
    *pcVar1 = '\0';
  }
  return;
}

/* ==========================================================================
 * FUN_0003ad9c   @ 0x0003ad9c   (68 bytes)
 */

void FUN_0003ad9c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char cVar6;
  
  puVar2 = PTR_DAT_0003ae38;
  puVar1 = PTR_DAT_0003ae34;
  uVar3 = *(uint *)(PTR_DAT_0003ae34 + 8);
  if ((uVar3 & 0x600) != 0) {
    cVar6 = '\0';
    uVar4 = *(uint *)(PTR_DAT_0003ae34 + 8);
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
 * FUN_0003b73e   @ 0x0003b73e   (12 bytes)
 * called by : FUN_00036f34, FUN_00036f56, FUN_0003b74a
 */

void FUN_0003b73e(undefined4 param_1)

{
  do {
  } while (-1 < *(int *)(PTR_DAT_0003b8c0 + 8) << 0xb);
  *(undefined4 *)(PTR_DAT_0003b8c0 + 0xc) = param_1;
  return;
}

/* ==========================================================================
 * FUN_0003b74a   @ 0x0003b74a   (22 bytes)
 * called by : FUN_0003b882
 * calls     : FUN_0003b73e
 */

void FUN_0003b74a(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  bool bVar2;
  
  while (bVar2 = param_2 != 0, param_2 = param_2 + -1, bVar2) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_0003b73e(uVar1);
  }
  return;
}

/* ==========================================================================
 * FUN_0003b760   @ 0x0003b760   (30 bytes)
 * calls     : rom_24FEC
 */

void FUN_0003b760(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0003b8c8;
  *(undefined4 *)(DAT_0003b8c8 + 8) = 0;
  *puVar1 = 0;
  rom_24FEC(DAT_0003b8cc,0x80);
  rom_24FEC(DAT_0003b8cc + 0x80,0x80);
  return;
}

/* ==========================================================================
 * FUN_0003b7ce   @ 0x0003b7ce   (6 bytes)
 */

void FUN_0003b7ce(void)

{
  int unaff_r4;
  
  *(undefined1 *)(unaff_r4 + 1) = 0;
  return;
}

/* ==========================================================================
 * FUN_0003b7d4   @ 0x0003b7d4   (32 bytes)
 * called by : uart2_isr
 * calls     : rom_25078
 */

void FUN_0003b7d4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0003b8c8;
  iVar2 = rom_25078();
  if (iVar2 != 1) {
    return;
  }
  *(undefined1 *)(iVar1 + 2) = 1;
  return;
}

/* ==========================================================================
 * FUN_0003b882   @ 0x0003b882   (58 bytes)
 * calls     : FUN_0003b74a, rom_24F9C
 */

void FUN_0003b882(undefined4 param_1,int param_2)

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
  FUN_0003b74a(&local_28,param_2 + 7);
  return;
}

/* ==========================================================================
 * FUN_0003b9dc   @ 0x0003b9dc   (22 bytes)
 */

void FUN_0003b9dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = DAT_0003bd10;
  *(undefined4 *)(DAT_0003bd10 + 8) = param_3;
  *(undefined4 *)(iVar1 + 0xc) = param_4;
  *(undefined4 *)(iVar1 + 0x18) = param_1;
  *(undefined4 *)(iVar1 + 0x20) = param_2;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  return;
}

/* ==========================================================================
 * FUN_0003b9f2   @ 0x0003b9f2   (22 bytes)
 */

void FUN_0003b9f2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0003bd10;
  *DAT_0003bd10 = param_3;
  puVar1[1] = param_4;
  puVar1[5] = param_1;
  puVar1[7] = param_2;
  *(undefined1 *)(puVar1 + 9) = 1;
  return;
}

/* ==========================================================================
 * FUN_0003c0e4   @ 0x0003c0e4   (48 bytes)
 * called by : FUN_0003ab30
 */

void FUN_0003c0e4(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 0x20 + DAT_0003c164);
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
 * FUN_0003c114   @ 0x0003c114   (48 bytes)
 * called by : FUN_0003ab60
 */

void FUN_0003c114(int param_1,uint param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 0x20 + DAT_0003c164);
  puVar1[1] = param_4;
  puVar1[2] = param_3;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = param_2;
  *puVar1 = param_5 * 0x10000 - 0xfe00U | param_6 << 4 | DAT_0003c168;
  return;
}

/* ==========================================================================
 * FUN_0003c2e6   @ 0x0003c2e6   (82 bytes)
 * calls     : rom_24F24
 */

void FUN_0003c2e6(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = rom_24F24(param_3,1000);
  puVar1 = DAT_0003c4e4;
  if (param_1 == 0) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xfe;
    *puVar1 = uVar2;
    uVar3 = puVar1[3];
    uVar4 = 1;
  }
  else if (param_1 == 1) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xfd;
    puVar1[1] = uVar2;
    uVar3 = puVar1[3];
    uVar4 = 2;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xfb;
    puVar1[2] = uVar2;
    uVar3 = puVar1[3];
    uVar4 = 4;
  }
  puVar1[3] = uVar3 | uVar4;
  return;
}

/* ==========================================================================
 * FUN_0003c338   @ 0x0003c338   (100 bytes)
 * calls     : rom_24F24
 */

void FUN_0003c338(int param_1,int param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = rom_24F24(param_2 << 5,1000);
  puVar2 = DAT_0003c4e8;
  pbVar1 = DAT_0003c4e0;
  if (param_1 == 0) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xef;
    *puVar2 = uVar3;
    *(undefined4 *)(pbVar1 + 0x24) = uVar3;
    uVar4 = puVar2[3];
    uVar5 = 1;
  }
  else if (param_1 == 1) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xdf;
    puVar2[1] = uVar3;
    *(undefined4 *)(pbVar1 + 0x28) = uVar3;
    uVar4 = puVar2[3];
    uVar5 = 2;
  }
  else {
    if (param_1 != 2) goto LAB_0003c37e;
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xbf;
    puVar2[2] = uVar3;
    *(undefined4 *)(pbVar1 + 0x2c) = uVar3;
    uVar4 = puVar2[3];
    uVar5 = 4;
  }
  puVar2[3] = uVar4 | uVar5;
LAB_0003c37e:
  *DAT_0003c4ec = *DAT_0003c4ec | 8;
  return;
}

/* ==========================================================================
 * FUN_0003c39c   @ 0x0003c39c   (82 bytes)
 * calls     : rom_24F24
 */

void FUN_0003c39c(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = rom_24F24(param_2 << 5,1000);
  puVar1 = DAT_0003c4e8;
  if (param_1 == 0) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xef;
    *puVar1 = uVar2;
    uVar3 = puVar1[3];
    uVar4 = 1;
  }
  else if (param_1 == 1) {
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xdf;
    puVar1[1] = uVar2;
    uVar3 = puVar1[3];
    uVar4 = 2;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    *DAT_0003c4e0 = *DAT_0003c4e0 & 0xbf;
    puVar1[2] = uVar2;
    uVar3 = puVar1[3];
    uVar4 = 4;
  }
  puVar1[3] = uVar3 | uVar4;
  return;
}

/* ==========================================================================
 * FUN_0003c51a   @ 0x0003c51a   (20 bytes)
 */

void FUN_0003c51a(int param_1,int param_2)

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
 * FUN_0003c534   @ 0x0003c534   (64 bytes)
 * calls     : FUN_0003c75a
 */

void FUN_0003c534(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

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
  uVar2 = FUN_0003c75a(&local_10);
  *(undefined4 *)(DAT_0003c804 + 0x10) = uVar2;
  return;
}

/* ==========================================================================
 * FUN_0003c57a   @ 0x0003c57a   (264 bytes)
 * calls     : FUN_0003c738, rom_24F24
 */

void FUN_0003c57a(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  
  uVar7 = rom_24F24(param_2,DAT_0003c808,param_2,param_4,param_4);
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
    uVar3 = FUN_0003c738(uVar5,param_1[4]);
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
    iVar4 = FUN_0003c738(uVar5,param_1[4]);
    uVar6 = uVar6 - iVar4 & 0xffff;
    param_1[4] = param_1[4] + '\x01';
  }
  param_1[3] = (char)uVar6;
  return;
}

/* ==========================================================================
 * FUN_0003c738   @ 0x0003c738   (34 bytes)
 * called by : FUN_0003c57a, FUN_0003c75a
 */

char FUN_0003c738(char param_1,uint param_2)

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
 * FUN_0003c75a   @ 0x0003c75a   (164 bytes)
 * called by : FUN_0003c534
 * calls     : FUN_0003c738, rom_24F24
 */

int FUN_0003c75a(byte *param_1)

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
    iVar5 = FUN_0003c738(uVar4,uVar8 & 0xff);
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
  return DAT_0003c808 * uVar7 + ((uint)bVar1 * 0x3c + (uint)bVar2) * 0x3c + (uint)bVar3;
}

/* ==========================================================================
 * FUN_0003dd56   @ 0x0003dd56   (28 bytes)
 * calls     : rom_06B5A, rom_16D94, rom_24F9C
 */

undefined8 FUN_0003dd56(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  rom_24F9C(&uStack_18,DAT_0003e104,0x10);
  rom_16D94(0,&uStack_18);
  return CONCAT44(uStack_14,uStack_18);
}

/* ==========================================================================
 * FUN_0003e7b4   @ 0x0003e7b4   (30 bytes)
 */

void FUN_0003e7b4(undefined1 *param_1,undefined2 *param_2)

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
 * FUN_0003e976   @ 0x0003e976   (66 bytes)
 */

void FUN_0003e976(uint param_1,int param_2,int param_3)

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
 * FUN_0003e9b8   @ 0x0003e9b8   (64 bytes)
 */

void FUN_0003e9b8(uint param_1,int param_2,int param_3,int param_4)

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
 * FUN_0003e9f8   @ 0x0003e9f8   (304 bytes)
 * calls     : rom_1EFCC
 */

void FUN_0003e9f8(int param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6,
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
 * FUN_0003ec18   @ 0x0003ec18   (82 bytes)
 * called by : FUN_0003ec6a
 * calls     : FUN_0003efee, FUN_0003f464, FUN_0003fb64, FUN_0004012e, FUN_00040be8, FUN_00041574, ... (+1 more)
 */

void FUN_0003ec18(byte param_1)

{
  if (param_1 == 0x47) {
    FUN_0003f464(0);
    return;
  }
  if (param_1 < 0x48) {
    if (param_1 == 0x14) {
      FUN_0003efee();
      return;
    }
    if (param_1 == 0x24) {
      FUN_0003fb64();
      return;
    }
    if (param_1 == 0x26) {
      FUN_00041574();
    }
  }
  else {
    if (param_1 == 0x48) {
      FUN_0004012e();
      return;
    }
    if (param_1 == 0x49) {
      FUN_00040be8();
      return;
    }
    if (param_1 == 0x4b) {
      FUN_00041f5e();
      return;
    }
  }
  return;
}

/* ==========================================================================
 * FUN_0003ec6a   @ 0x0003ec6a   (116 bytes)
 * calls     : FUN_0003ec18, dbg_printf, rom_07108, rom_07212
 * string    : "!!!!!!init_type=%x\n"
 */

void FUN_0003ec6a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  dbg_printf(str_init_type_x,param_1,param_3,param_4,param_4);
  iVar1 = DAT_0003eeb8;
  uVar3 = 0;
  do {
    if (param_1 == 0) {
      *(short *)(uVar3 * 0x18 + iVar1 + 0x10) = (short)(uVar3 + 9);
      rom_07108(uVar3 + 9 & 0xff);
    }
    else {
      if (param_1 != 1) {
        if (param_1 != 2) goto LAB_0003ecd2;
        iVar4 = uVar3 * 0x18 + iVar1;
        iVar2 = FUN_0003ec18(*(undefined2 *)(iVar4 + 0x12));
        if (iVar2 != 0) {
          (**(code **)(iVar2 + 4))(iVar4);
        }
        rom_07212(*(undefined1 *)(iVar4 + 0x10));
      }
      iVar2 = uVar3 * 0x18 + iVar1;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined2 *)(iVar2 + 0x12) = 0xff;
      *(undefined4 *)(iVar1 + uVar3 * 0x18) = 0;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(undefined2 *)(iVar2 + 8) = 0;
      *(undefined2 *)(iVar2 + 10) = 0;
    }
LAB_0003ecd2:
    uVar3 = uVar3 + 1 & 0xff;
    if (9 < uVar3) {
      return;
    }
  } while( true );
}

/* ==========================================================================
 * FUN_0003ee3a   @ 0x0003ee3a   (52 bytes)
 */

uint FUN_0003ee3a(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  uVar1 = 0;
  do {
    if ((uint)*(ushort *)(uVar1 * 0x18 + DAT_0003eeb8 + 0x10) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(uVar1 * 0x18 + DAT_0003eeb8 + 0x12);
      break;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return param_1 & 0xffffff00 | uVar2;
}

/* ==========================================================================
 * FUN_0003efc6   @ 0x0003efc6   (36 bytes)
 * calls     : rom_06DF6, rom_17A12
 */

void FUN_0003efc6(int param_1)

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
 * FUN_0003efee   @ 0x0003efee   (6 bytes)
 * called by : FUN_0003ec18
 */

undefined * FUN_0003efee(void)

{
  return PTR_DAT_0003f090 + 0x98;
}

/* ==========================================================================
 * FUN_0003eff4   @ 0x0003eff4   (54 bytes)
 */

uint FUN_0003eff4(int param_1,int param_2)

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
 * FUN_0003f02a   @ 0x0003f02a   (60 bytes)
 */

short FUN_0003f02a(int param_1,uint param_2)

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
 * FUN_0003f066   @ 0x0003f066   (42 bytes)
 */

undefined4 FUN_0003f066(int param_1,uint param_2)

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
 * FUN_0003f370   @ 0x0003f370   (28 bytes)
 * calls     : rom_06DF6
 */

void FUN_0003f370(int param_1)

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
 * FUN_0003f464   @ 0x0003f464   (6 bytes)
 * called by : FUN_0003ec18
 */

undefined * FUN_0003f464(void)

{
  return PTR_DAT_0003f498 + 0x70;
}

/* ==========================================================================
 * FUN_0003fa7a   @ 0x0003fa7a   (28 bytes)
 * calls     : rom_06DF6
 */

void FUN_0003fa7a(int param_1)

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
 * FUN_0003fb64   @ 0x0003fb64   (6 bytes)
 * called by : FUN_0003ec18
 */

undefined * FUN_0003fb64(void)

{
  return PTR_DAT_0003fce8 + 0x28;
}

/* ==========================================================================
 * FUN_0003fd3a   @ 0x0003fd3a   (18 bytes)
 * calls     : rom_06F26
 */

undefined4 FUN_0003fd3a(int param_1)

{
  *(undefined1 *)(param_1 + 1) = 0x89;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_0004008a   @ 0x0004008a   (28 bytes)
 * calls     : rom_06DF6
 */

void FUN_0004008a(int param_1)

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
 * FUN_0004012e   @ 0x0004012e   (6 bytes)
 * called by : FUN_0003ec18
 */

int FUN_0004012e(void)

{
  return DAT_00040154 + 0x84;
}

/* ==========================================================================
 * FUN_00040528   @ 0x00040528   (28 bytes)
 * calls     : rom_06DF6
 */

void FUN_00040528(int param_1)

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
 * FUN_00040be8   @ 0x00040be8   (4 bytes)
 * called by : FUN_0003ec18
 */

undefined4 FUN_00040be8(void)

{
  return DAT_00040cdc;
}

/* ==========================================================================
 * FUN_00040d28   @ 0x00040d28   (12 bytes)
 * calls     : rom_06F26
 */

undefined4 FUN_00040d28(int param_1)

{
  *(undefined1 *)(param_1 + 1) = 0x89;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_00041540   @ 0x00041540   (16 bytes)
 * calls     : rom_06DF6
 */

void FUN_00041540(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  rom_06DF6(uVar1);
  return;
}

/* ==========================================================================
 * FUN_00041552   @ 0x00041552   (34 bytes)
 */

void FUN_00041552(int param_1,int param_2)

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
 * FUN_00041574   @ 0x00041574   (6 bytes)
 * called by : FUN_0003ec18
 */

undefined * FUN_00041574(void)

{
  return PTR_DAT_000415b0 + 0xb8;
}

/* ==========================================================================
 * FUN_0004157a   @ 0x0004157a   (276 bytes)
 */

undefined4 FUN_0004157a(int param_1,uint param_2,byte *param_3,char *param_4,byte *param_5)

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
 * FUN_0004186c   @ 0x0004186c   (32 bytes)
 * calls     : rom_06EF4, rom_06F26
 */

undefined4 FUN_0004186c(void)

{
  undefined1 *puVar1;
  undefined1 *unaff_r4;
  
  puVar1 = (undefined1 *)rom_06EF4(DAT_00041c4c);
  *puVar1 = *unaff_r4;
  puVar1[1] = 0x89;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * FUN_00041efc   @ 0x00041efc   (42 bytes)
 * calls     : rom_06DF6
 */

void FUN_00041efc(int param_1)

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
 * FUN_00041f5e   @ 0x00041f5e   (4 bytes)
 * called by : FUN_0003ec18
 */

undefined4 FUN_00041f5e(void)

{
  return DAT_00041fb4;
}

/* ==========================================================================
 * FUN_0004294c   @ 0x0004294c   (18 bytes)
 * calls     : thunk_FUN_00042af0
 */

longlong FUN_0004294c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  puVar1 = DAT_00042968;
  for (puVar3 = DAT_00042964; puVar3 < puVar1; puVar3 = puVar3 + 4) {
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
 * called by : FUN_0004294c
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
 * FUN_00042af0   @ 0x00042af0   (24 bytes)
 */

void FUN_00042af0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -4) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

/* ==========================================================================
 * FUN_0004407a   @ 0x0004407a   (4 bytes)
 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0004407a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
