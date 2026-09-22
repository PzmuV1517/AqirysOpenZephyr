/* Firmware update (OAD/OTA)
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

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
  puVar1 = (undefined1 *)rom_06EF4(ota_ro_2cb64,7,3,0xe);
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
 * called by : usb_sub_33a7e
 * calls     : rf24_sub_31784, flash_sub_392b8, rf24_sub_3b130, dbg_printf, flash_write_some_data
 * string    : "app_usb_upgrade_start"
 * string    : "%s \r\n"
 */

void app_usb_upgrade_start(void)

{
  dbg_printf(str_s_13,str_app_usb_upgrade_start);
  flash_sub_392b8();
  rf24_sub_31784(shared_ro_390a8 + 7);
  flash_write_some_data(ota_ro_39194,0x7d000,0x10);
  rf24_sub_3b130();
  return;
}

/* ==========================================================================
 * ota_sub_3e7d2   @ 0x0003e7d2   (46 bytes)
 * calls     : ota_sub_3ee1a, rom_06EF4, rom_06F26
 */

void ota_sub_3e7d2(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = ota_sub_3ee1a();
  puVar2 = (undefined1 *)rom_06EF4(ota_ro_3ebc0,param_2 * 0x100 + 6,uVar1,10);
  *puVar2 = 8;
  puVar2[1] = 1;
  *(undefined2 *)(puVar2 + 6) = 0;
  *(undefined2 *)(puVar2 + 8) = 0;
  *(undefined2 *)(puVar2 + 4) = param_5;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ota_sub_3e854   @ 0x0003e854   (52 bytes)
 * calls     : ota_sub_3ee1a, rom_06EF4, rom_06F26
 */

void ota_sub_3e854(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (*(short *)(param_3 + 0x14) != 0) {
    uVar1 = ota_sub_3ee1a(param_1,param_2);
    puVar2 = (undefined1 *)rom_06EF4(ota_ro_3ebc0 + 7,param_2 * 0x100 + 6,uVar1,8);
    *puVar2 = 0x11;
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(param_3 + 0x14);
    *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_3 + 0x16);
    rom_06F26();
  }
  return;
}

/* ==========================================================================
 * ota_sub_3e888   @ 0x0003e888   (58 bytes)
 * calls     : ota_sub_3ee1a, rom_06EF4, rom_06F26
 */

void ota_sub_3e888(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = ota_sub_3ee1a();
  puVar2 = (undefined1 *)rom_06EF4(ota_ro_3ebc0 + 0x11,param_2 * 0x100 + 6,uVar1,0x1a);
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
 * ota_sub_3e8c2   @ 0x0003e8c2   (64 bytes)
 * calls     : ota_sub_3ee1a, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_3e8c2(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = ota_sub_3ee1a();
  puVar2 = (undefined1 *)rom_06EF4(ota_ro_3ebc0 + 0x11,param_2 * 0x100 + 6,uVar1,0x28);
  *puVar2 = 0x15;
  *(undefined2 *)(puVar2 + 4) = 1;
  *(undefined2 *)(puVar2 + 6) = 0xffff;
  puVar2[1] = 0x10;
  rom_24F9C(puVar2 + 8,param_3,0x10);
  rom_06F26(puVar2);
  return;
}

/* ==========================================================================
 * ota_sub_3e902   @ 0x0003e902   (86 bytes)
 * called by : ble_sub_3e958
 * calls     : ota_sub_3ee1a, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_3e902(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined1 param_6,undefined2 param_7)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    uVar1 = ota_sub_3ee1a();
    puVar2 = (undefined1 *)rom_06EF4(ota_ro_3ebc0 + 2,param_2 * 0x100 + 6,uVar1,param_5 + 0xcU & 0xffff)
    ;
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
 * ota_sub_3eb28   @ 0x0003eb28   (86 bytes)
 * calls     : ota_sub_3ee1a, ota_sub_3ee2a, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_3eb28(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
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
  uVar1 = ota_sub_3ee1a(param_1,param_2);
  uVar2 = ota_sub_3ee2a(param_1,param_2);
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
 * ota_sub_3ee1a   @ 0x0003ee1a   (16 bytes)
 * called by : ota_sub_3e7d2, ota_sub_3e854, ota_sub_3e888, ota_sub_3e8c2, ota_sub_3e902, ota_sub_3eb28, ... (+11 more)
 */

uint ota_sub_3ee1a(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(ushort *)(param_1 + 2) & 0x7fff;
  if ((short)*(ushort *)(param_1 + 2) < 0) {
    uVar1 = uVar1 | param_2 << 8;
  }
  return uVar1;
}

/* ==========================================================================
 * ota_sub_3ee2a   @ 0x0003ee2a   (16 bytes)
 * called by : ota_sub_3eb28, ble_sub_41798, ota_sub_41f62
 */

uint ota_sub_3ee2a(ushort *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *param_1 & 0x7fff;
  if ((short)*param_1 < 0) {
    uVar1 = uVar1 | param_2 << 8;
  }
  return uVar1;
}

/* ==========================================================================
 * ota_sub_3f3cc   @ 0x0003f3cc   (76 bytes)
 * calls     : ota_sub_3ee1a, ble_sub_3f3b0, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_3f3cc(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = ota_sub_3ee1a(param_2,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,*(short *)(param_3 + 2) + 8);
  *puVar3 = 0x12;
  uVar1 = ble_sub_3f3b0(9);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_3 + 2);
  rom_24F9C(puVar3 + 8,param_3 + 4,*(undefined2 *)(param_3 + 2));
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * ota_sub_3f418   @ 0x0003f418   (76 bytes)
 * calls     : ota_sub_3ee1a, ble_sub_3f3b0, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_3f418(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = ota_sub_3ee1a(param_2,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,*(short *)(param_3 + 2) + 8);
  *puVar3 = 0x13;
  uVar1 = ble_sub_3f3b0(0xc);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_3 + 2);
  rom_24F9C(puVar3 + 8,param_3 + 4,*(undefined2 *)(param_3 + 2));
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * ota_sub_3fb24   @ 0x0003fb24   (64 bytes)
 * called by : ota_sub_3fbda
 * calls     : ota_sub_3ee1a, ble_sub_3faaa, rom_06EF4, rom_06F26
 */

void ota_sub_3fb24(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = ota_sub_3ee1a(param_1,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_2 * 0x100 + 6,uVar2,9);
  *puVar3 = 0x12;
  uVar1 = ble_sub_3faaa(param_3,2);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = 1;
  puVar3[8] = *(undefined1 *)(param_1 + param_3 + 0x1a);
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * ota_sub_3fbda   @ 0x0003fbda   (238 bytes)
 * called by : ble_sub_3fd6e
 * calls     : ble_sub_3edee, ota_sub_3ee1a, ota_sub_3fb24, rom_06DF6, rom_06EF4, rom_06F26, ... (+1 more)
 */

void ota_sub_3fbda(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  
  iVar2 = ble_sub_3edee(0x24);
  uVar1 = 0xff;
  iVar3 = *(int *)(iVar2 + 0x14);
  if ((undefined *)(uint)*(ushort *)(iVar3 + 4) == &rom_ro_2400) {
    uVar1 = *(undefined1 *)(iVar3 + 0xc);
    while( true ) {
      bVar6 = *(byte *)(iVar2 + 0x20);
      uVar7 = (uint)bVar6;
      if (1 < uVar7) break;
      if ((((uint)*(byte *)((uint)*(byte *)(iVar3 + 0xc) + iVar2 + 0x1d) & 1 << uVar7) != 0) &&
         (*(char *)(uVar7 + iVar3 + 0xe) != *(char *)(uVar7 + iVar2 + 0x1a))) {
        bVar6 = *(byte *)(iVar3 + 0xc);
LAB_0003fc5c:
        ota_sub_3fb24(iVar2,bVar6,uVar7);
        *(char *)(iVar2 + 0x20) = *(char *)(iVar2 + 0x20) + '\x01';
        return;
      }
      *(byte *)(iVar2 + 0x20) = bVar6 + 1;
    }
  }
  else if ((undefined *)(uint)*(ushort *)(iVar3 + 4) == ota_ro_3fcf0) {
    while (*(char *)(iVar2 + 0x20) == '\0') {
      uVar7 = (uint)*(byte *)(iVar3 + 0xc);
      if (((uint)*(byte *)(iVar2 + 0x1d) & 1 << uVar7) != 0) {
        bVar6 = 0;
        goto LAB_0003fc5c;
      }
      *(char *)(iVar2 + 0x20) = '\x01';
    }
  }
  if ((undefined *)(uint)*(ushort *)(iVar3 + 4) == &rom_ro_2400) {
    puVar4 = (undefined1 *)
             rom_06EF4(ota_ro_3fcf0 + -1,*(undefined2 *)(iVar3 + 8),*(undefined2 *)(iVar3 + 6),2);
    *puVar4 = uVar1;
    puVar4[1] = 0;
  }
  else {
    if ((undefined *)(uint)*(ushort *)(iVar3 + 4) != ota_ro_3fcf0) goto LAB_0003fcb0;
    puVar4 = (undefined1 *)
             rom_06EF4(ota_ro_3fcf0 + 1,*(undefined2 *)(iVar3 + 8),*(undefined2 *)(iVar3 + 6),1);
    *puVar4 = 0;
  }
  rom_06F26();
LAB_0003fcb0:
  rom_06DF6(*(undefined4 *)(iVar2 + 0x14));
  *(undefined4 *)(iVar2 + 0x14) = 0;
  uVar5 = ota_sub_3ee1a(iVar2,0);
  rom_07180(uVar5,0);
  return;
}

/* ==========================================================================
 * ota_sub_400e2   @ 0x000400e2   (76 bytes)
 * calls     : ota_sub_3ee1a, ble_sub_400c6, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_400e2(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = ota_sub_3ee1a(param_2,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,*(short *)(param_3 + 2) + 8);
  *puVar3 = 0x12;
  uVar1 = ble_sub_400c6(4);
  *(undefined2 *)(puVar3 + 4) = uVar1;
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_3 + 2);
  rom_24F9C(puVar3 + 8,param_3 + 4,*(undefined2 *)(param_3 + 2));
  rom_06F26(puVar3);
  return;
}

/* ==========================================================================
 * ota_sub_40568   @ 0x00040568   (32 bytes)
 * called by : ImgHdr
 * calls     : rom_24F9C
 */

void ota_sub_40568(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = shared_ro_40884;
  iVar2 = *(int *)(shared_ro_40884 + 0x18);
  *(int *)(shared_ro_40884 + 0x18) = iVar2 + 1;
  rom_24F9C(puVar1 + (iVar2 + 1) * 0x10 + 0xe,param_1 + 2,0x10);
  puVar1[0x1c] = 1;
  return;
}

/* ==========================================================================
 * oad_updating_user_section_begin   @ 0x00040588   (38 bytes)
 * called by : ImgHdr
 * calls     : dbg_printf
 * string    : "oad_updating_user_section_begin"
 */

void oad_updating_user_section_begin(undefined2 param_1,undefined2 param_2)

{
  undefined *puVar1;
  
  dbg_printf(&ota_ro_40888,str_oad_updating_user_section_begin);
  puVar1 = shared_ro_40884;
  *(undefined2 *)(shared_ro_40884 + 6) = param_2;
  *(undefined2 *)(puVar1 + 4) = param_1;
  *(undefined4 *)(puVar1 + 0x14) = 0;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  puVar1[0x1d] = 1;
  return;
}

/* ==========================================================================
 * ota_sub_406c0   @ 0x000406c0   (18 bytes)
 * called by : ImgHdr
 */

undefined4 ota_sub_406c0(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_40884;
  shared_ro_40884[0x1d] = 0;
  puVar1[0x1c] = 2;
  shared_ro_40890[2] = 0;
  return 0;
}

/* ==========================================================================
 * oadImgIdentifyReq   @ 0x000406d2   (150 bytes)
 * called by : ImgHdr_2
 * calls     : ble_sub_3edee, ota_sub_3ee1a, dbg_printf, rom_06EF4, rom_06F26
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
  dbg_printf(&ota_ro_40888,str_oadImgIdentifyReq);
  iVar1 = ble_sub_3edee(0x49);
  dbg_printf(str_noti_0x_x,&local_18);
  local_18 = CONCAT13((char)((ushort)*(undefined2 *)(param_2 + 6) >> 8),*(undefined3 *)(param_2 + 4)
                     );
  local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)(param_2 + 0xe));
  uVar2 = ota_sub_3ee1a(iVar1,0);
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
 * ota_sub_40768   @ 0x00040768   (76 bytes)
 * called by : ImgHdr, ImgHdr_2
 * calls     : ble_sub_3edee, ota_sub_3ee1a, rom_06EF4, rom_06F26
 */

void ota_sub_40768(short param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = ble_sub_3edee(0x49);
  uVar2 = ota_sub_3ee1a(iVar1,0);
  puVar3 = (undefined1 *)rom_06EF4(0xc10,param_1 * 0x100 + 6,uVar2,10);
  *puVar3 = 0x12;
  *(short *)(puVar3 + 4) = *(short *)(iVar1 + 8) + 6;
  *(undefined2 *)(puVar3 + 6) = 2;
  *(undefined2 *)(puVar3 + 8) = param_2;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ImgHdr_2   @ 0x000407b4   (424 bytes)
 * calls     : flash_sub_396da, ota_sub_40768, appm_update_param, dbg_printf, oadImgIdentifyReq
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

undefined4 ImgHdr_2(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  undefined *puVar5;
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
  dbg_printf(&ota_ro_40888,str_oadImgIdentifyWrite);
  puVar5 = shared_ro_40890;
  sVar1 = *(short *)(param_3 + 4);
  uVar2 = *(ushort *)(param_3 + 6);
  iVar4 = *(int *)(param_3 + 8);
  sVar3 = *(short *)(param_3 + 0xe);
  *(int *)(shared_ro_40890 + 0xc) = iVar4;
  dbg_printf(str_rxHdr_ver_x,sVar1);
  dbg_printf(str_rxHdr_len_x,uVar2);
  dbg_printf(str_rxHdr_uid_x,iVar4);
  dbg_printf(str_rxHdr_rom_ver_x,sVar3);
  if (iVar4 == str_BBBBwait_for_reset._0_4_) {
    puVar5[1] = 1;
    dbg_printf(str_app_part_upgrade);
    flash_sub_396da(0,ota_ro_40954,0x10,auStack_30);
    dbg_printf(str_ImgHdr_rom_ver_x,local_22);
    dbg_printf(str_ImgHdr_uid_x,local_28);
    dbg_printf(str_ImgHdr_ver_x,local_2c);
    *(ushort *)(puVar5 + 6) = uVar2 >> 2;
    dbg_printf(str_oadBlkTot_x);
    if (((local_2c != sVar1) && (*(ushort *)(puVar5 + 6) < 0x2a01)) &&
       ((*(ushort *)(puVar5 + 6) != 0 && (sVar3 == local_22)))) {
LAB_000409b8:
      *puVar5 = 1;
      goto LAB_00040a56;
    }
  }
  else if (iVar4 == str_SSSSapp_and_stack_upgrade._0_4_) {
    puVar5[1] = 2;
    dbg_printf(str_SSSSapp_and_stack_upgrade + 4);
    flash_sub_396da(0,ota_ro_40c30,0x10,auStack_30);
    dbg_printf(ota_ro_40c34,local_28);
    dbg_printf(str_ImgHdr_ver_x,local_2c);
    *(ushort *)(puVar5 + 6) = uVar2 >> 2;
    dbg_printf(str_oadBlkTot_x);
    if (((sVar3 != local_22) && (*(ushort *)(puVar5 + 6) < 0x3e01)) &&
       (*(ushort *)(puVar5 + 6) != 0)) goto LAB_000409b8;
  }
  else {
    puVar5[1] = 0;
    flash_sub_396da(0,ota_ro_40c38,0x10,auStack_30);
    dbg_printf(ota_ro_40c34 + -0x18,local_22);
    dbg_printf(ota_ro_40c34,local_28);
    dbg_printf(str_ImgHdr_ver_x,local_2c);
  }
  if (*puVar5 != '\x01') {
    oadImgIdentifyReq(local_20,auStack_30);
    return 0;
  }
LAB_00040a56:
  *(undefined2 *)(puVar5 + 4) = 0;
  puVar5[2] = 1;
  *puVar5 = 0;
  appm_update_param();
  ota_sub_40768(local_20,0);
  return 0;
}

/* ==========================================================================
 * ImgHdr   @ 0x00040a7c   (364 bytes)
 * calls     : flash_sub_396da, ota_sub_40568, ota_sub_406c0, ota_sub_40768, dbg_printf, oad_updating_user_section_begin
 * string    : "oadImgBlockWrite: UNKNOWN UID\r\n"
 * string    : "uid = %x\r\n"
 * string    : "blkNum = %x ,oadBlkNum %x,oadBlkTot %x,ver %x \r\n"
 * string    : "ImgHdr.ver = %x, ver = %x\r\n"
 * string    : "last block \r\n"
 * string    : "update down!\r\n"
 */

undefined4 ImgHdr(undefined4 param_1,short *param_2)

{
  short sVar1;
  undefined *puVar2;
  undefined4 uVar3;
  short sVar4;
  undefined1 auStack_3c [4];
  short local_38;
  ushort local_2e;
  uint local_28;
  undefined4 local_1c;
  short *psStack_18;
  
  puVar2 = ota_ro_40c3c;
  sVar1 = *param_2;
  local_1c = param_1;
  psStack_18 = param_2;
  if (sVar1 == 0) {
    if (ota_ro_40c3c[1] == '\x01') {
      flash_sub_396da(0,ota_ro_40c38,0x10,auStack_3c);
      sVar4 = param_2[3];
      local_28 = (uint)(ushort)param_2[8];
      uVar3 = *(undefined4 *)(param_2 + 5);
      local_38 = sVar4 + 1;
      *(undefined2 *)(puVar2 + 8) = 0;
      dbg_printf(str_uid_x,uVar3);
      dbg_printf(str_blkNum_x_oadBlkNum_x_oadBlkTot_x_ver_x,0,*(undefined2 *)(puVar2 + 4),
                 *(undefined2 *)(puVar2 + 6));
      dbg_printf(str_ImgHdr_ver_x_ver_x,local_38,sVar4);
      if ((*(short *)(puVar2 + 4) == 0) && (local_2e == local_28)) {
LAB_00040b84:
        oad_updating_user_section_begin(sVar4,(uint)*(ushort *)(puVar2 + 6) * 4 + -0x10);
        ota_sub_40568(param_2);
        goto LAB_00040b96;
      }
    }
    else if (ota_ro_40c3c[1] == '\x02') {
      flash_sub_396da(0,ota_ro_40c30,0x10,auStack_3c);
      sVar4 = param_2[3];
      local_28 = (uint)(ushort)param_2[8];
      uVar3 = *(undefined4 *)(param_2 + 5);
      local_38 = sVar4 + 1;
      *(undefined2 *)(puVar2 + 8) = 0;
      dbg_printf(str_uid_x,uVar3);
      dbg_printf(str_blkNum_x_oadBlkNum_x_oadBlkTot_x_ver_x,0,*(undefined2 *)(puVar2 + 4),
                 *(undefined2 *)(puVar2 + 6));
      dbg_printf(str_ImgHdr_ver_x_ver_x,local_38,sVar4);
      if ((*(short *)(puVar2 + 4) == 0) && (local_2e != local_28)) goto LAB_00040b84;
    }
    else {
      dbg_printf(str_oadImgBlockWrite_UNKNOWN_UID);
    }
    uVar3 = 3;
  }
  else {
LAB_00040b96:
    if (*(short *)(puVar2 + 4) == sVar1) {
      if (*(short *)(puVar2 + 4) != 0) {
        *(short *)(puVar2 + 8) = *(short *)(puVar2 + 8) + 1;
        ota_sub_40568(param_2);
        if ((uint)*(ushort *)(puVar2 + 8) == *(ushort *)(puVar2 + 6) - 1) {
          dbg_printf(str_last_block);
          ota_sub_40768(local_1c,*(undefined2 *)(puVar2 + 4));
        }
      }
      *(short *)(puVar2 + 4) = *(short *)(puVar2 + 4) + 1;
    }
    else {
      ota_sub_40768(local_1c);
    }
    if (*(short *)(puVar2 + 4) == *(short *)(puVar2 + 6)) {
      dbg_printf(str_update_down);
      ota_sub_406c0();
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* ==========================================================================
 * ota_sub_41f62   @ 0x00041f62   (78 bytes)
 * calls     : ota_sub_3ee1a, ota_sub_3ee2a, prf_register_atthdl2gatt, rom_06EF4, rom_06F26, rom_24F9C
 */

void ota_sub_41f62(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar1 = ota_sub_3ee1a();
  uVar2 = ota_sub_3ee2a(param_1,param_2);
  puVar3 = (undefined1 *)rom_06EF4(ota_ro_41fb8,uVar2,uVar1,0x8a,param_4);
  *puVar3 = (char)param_3;
  if (param_3 == 0) {
    iVar4 = param_2 * 4 + param_1;
    rom_24F9C(puVar3 + 2,*(int *)(iVar4 + 4) + 4,0x88);
    prf_register_atthdl2gatt(param_1,param_2,*(int *)(iVar4 + 4) + 4);
  }
  rom_06F26(puVar3);
  return;
}
