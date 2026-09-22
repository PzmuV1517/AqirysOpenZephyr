/* Flash and NVM storage
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * flash_sub_29988   @ 0x00029988   (68 bytes)
 * called by : app_ble_address_update, app_ble_to_ble_mode
 * calls     : ble_sub_3e552, dbg_printf, dbg_printf_2, rom_24F9C
 * string    : " An error has occurred during access to the NVDS_TAG_BLE_ADDRESS1 \r\n"
 * string    : "ble addr:"
 * string    : " An error has occurred during access to the NVDS_TAG_BLE_ADDRESS0 \r\n"
 */

void flash_sub_29988(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8 [2];
  
  local_8[0] = CONCAT31((int3)((uint)param_4 >> 8),7);
  uStack_10 = param_2;
  uStack_c = param_3;
  if (param_1 == 1) {
    iVar2 = ble_sub_3e552(0xa5,local_8);
    puVar1 = flash_ro_29d50;
  }
  else {
    iVar2 = ble_sub_3e552(0xa6,local_8);
    puVar1 = flash_ro_29d40;
  }
  if (iVar2 != 0) {
    dbg_printf(puVar1);
  }
  rom_24F9C(ble_ro_29ce0,(int)&uStack_10 + 1,6);
  dbg_printf_2(str_ble_addr,ble_ro_29ce0,6);
  return;
}

/* ==========================================================================
 * flash_sub_29a04   @ 0x00029a04   (62 bytes)
 * called by : app_ble_to_ble_mode
 * calls     : flash_sub_2cbc8, ble_sub_3e552, KEY_piaring_cnt, dbg_printf
 * string    : "not NVDS_TAG_PEER%d_IRK\r\n"
 * string    : "====================================================\r\n"
 */

void flash_sub_29a04(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_r3;
  undefined4 local_10;
  
  local_10 = in_r3;
  KEY_piaring_cnt();
  puVar1 = shared_ro_29d70;
  local_10 = CONCAT31(local_10._1_3_,0x17);
  iVar2 = ble_sub_3e552(shared_ro_29d70[6] + 'C',&local_10,shared_ro_29d74);
  if (iVar2 != 0) {
    dbg_printf(str_not_NVDS_TAG_PEER_d_IRK,puVar1[6]);
  }
  flash_sub_2cbc8(iVar2 == 0);
  dbg_printf(str_s_2);
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * flash_sub_2cbc8   @ 0x0002cbc8   (18 bytes)
 * called by : flash_sub_29a04, app_sec_init
 */

void flash_sub_2cbc8(undefined1 param_1)

{
  if (*shared_ro_2cfc4 != '\x01') {
    shared_ro_2cfc8[1] = param_1;
    return;
  }
  *shared_ro_2cfc8 = param_1;
  return;
}

/* ==========================================================================
 * flash_sub_2fef0   @ 0x0002fef0   (40 bytes)
 * calls     : usb_sub_369b8, flash_sub_36cbe, flash_sub_36cee, set_pairing_led_flash
 */

void flash_sub_2fef0(void)

{
  flash_sub_36cee();
  flash_sub_36cbe();
  usb_sub_369b8();
  *shared_ro_301f0 = *shared_ro_301f0 + '\x01';
  *shared_ro_30144 = 1;
  *flash_ro_301f4 = 0;
  set_pairing_led_flash();
  return;
}

/* ==========================================================================
 * FLASH_wr_Global   @ 0x0003023c   (248 bytes)
 * called by : ble_sub_28c66, _saveC_GM_ProfileMax
 * calls     : flash_sub_392b8, flash_sub_3932e, flash_sub_396da, flash_sub_39708, flash_sub_3976e, dbg_printf, ... (+3 more)
 * string    : "FLASH_wr_Global:"
 * string    : "address&0x3ff = %x\r\n"
 */

void FLASH_wr_Global(void)

{
  undefined *puVar1;
  undefined *puVar2;
  byte bVar3;
  undefined1 auStack_414 [1024];
  
  rom_24FEC(flash_ro_30640,0xff);
  rom_24FEC(auStack_414,0x400);
  flash_sub_392b8();
  flash_sub_396da(0,0x7c000,0x400,auStack_414,0);
  flash_sub_3976e(0,0x7c000,0x1000);
  flash_sub_3932e();
  puVar2 = flash_ro_30644;
  if (2 < (byte)*flash_ro_30644) {
    *flash_ro_30644 = 0;
  }
  puVar1 = flash_ro_30640;
  bVar3 = *puVar2;
  *flash_ro_30640 = bVar3;
  puVar1[1] = ~bVar3;
  bVar3 = puVar2[2];
  puVar1[2] = bVar3;
  puVar1[3] = ~bVar3;
  bVar3 = puVar2[4];
  puVar1[4] = bVar3;
  puVar1[5] = ~bVar3;
  if (2 < (byte)puVar2[6]) {
    puVar2[6] = 0;
  }
  bVar3 = puVar2[6];
  puVar1[6] = bVar3;
  puVar1[7] = ~bVar3;
  if (0xe < (byte)puVar2[8]) {
    puVar2[8] = 0;
  }
  bVar3 = puVar2[8];
  puVar1[8] = bVar3;
  puVar1[9] = ~bVar3;
  bVar3 = puVar2[10];
  if (0xf < bVar3) {
    bVar3 = 8;
    puVar2[10] = 8;
  }
  puVar1[10] = bVar3;
  puVar1[0xb] = ~bVar3;
  if (4 < (byte)puVar2[0xc]) {
    puVar2[0xc] = 0;
  }
  bVar3 = puVar2[0xc];
  puVar1[0xc] = bVar3;
  puVar1[0xd] = ~bVar3;
  bVar3 = puVar2[0xe];
  if (4 < bVar3) {
    bVar3 = 4;
    puVar2[0xe] = 4;
  }
  puVar1[0xe] = bVar3;
  puVar1[0xf] = ~bVar3;
  dbg_printf_2(str_FLASH_wr_Global,flash_ro_30640,0x10);
  rom_24F9C(auStack_414,flash_ro_30640,0x10);
  dbg_printf(str_address_0x3ff_x,0);
  *(undefined4 *)flash_ro_30674 = 0x7c000;
  flash_sub_39708(0,0x7c000,0x400,auStack_414,0);
  return;
}

/* ==========================================================================
 * FLASH_RD_Global   @ 0x00030334   (314 bytes)
 * called by : profile_mem_init
 * calls     : flash_sub_396da, dbg_printf_2, rom_24FEC
 * string    : "FLASH_RD_Global:"
 * string    : "Global_DATA:"
 */

void FLASH_RD_Global(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  rom_24FEC(flash_ro_30640,0xff,param_3,param_4,param_4);
  flash_sub_396da(0,0x7c000,0x10,flash_ro_30640,0);
  dbg_printf_2(str_FLASH_RD_Global,flash_ro_30640,0x10);
  puVar6 = flash_ro_3068c;
  puVar4 = flash_ro_30644;
  puVar2 = flash_ro_30640;
  bVar1 = flash_ro_30640[1];
  if (*flash_ro_30640 == (byte)~bVar1) {
    *flash_ro_30644 = *flash_ro_30640;
    puVar4[1] = bVar1;
  }
  else {
    *(undefined2 *)flash_ro_30644 = *(undefined2 *)flash_ro_3068c;
  }
  if (2 < (byte)*puVar4) {
    *puVar4 = 0;
    puVar4[1] = 0xff;
  }
  puVar5 = flash_ro_30644;
  puVar3 = flash_ro_30640;
  flash_ro_30644[2] = flash_ro_30640[2];
  puVar5[3] = puVar3[3];
  puVar4[4] = puVar2[4];
  puVar4[5] = puVar2[5];
  puVar3 = flash_ro_30644;
  bVar1 = puVar2[7];
  if (puVar2[6] == (byte)~bVar1) {
    flash_ro_30644[6] = puVar2[6];
    puVar3[7] = bVar1;
  }
  else {
    *(undefined2 *)(flash_ro_30644 + 6) = *(undefined2 *)(flash_ro_3068c + 6);
  }
  if (2 < (byte)puVar4[6]) {
    puVar4[6] = 0;
    puVar4[7] = 0xff;
  }
  bVar1 = puVar2[9];
  if (puVar2[8] == (byte)~bVar1) {
    puVar4[8] = puVar2[8];
    puVar4[9] = bVar1;
  }
  else {
    *(undefined2 *)(puVar4 + 8) = *(undefined2 *)(puVar6 + 8);
  }
  if (0xe < (byte)puVar4[8]) {
    puVar4[8] = 0;
    puVar4[9] = 0xff;
  }
  puVar3 = flash_ro_30644;
  bVar1 = puVar2[0xb];
  if (puVar2[10] == (byte)~bVar1) {
    flash_ro_30644[10] = puVar2[10];
    puVar3[0xb] = bVar1;
  }
  else {
    *(undefined2 *)(flash_ro_30644 + 10) = *(undefined2 *)(flash_ro_3068c + 10);
  }
  if (0xf < (byte)puVar4[10]) {
    puVar4[10] = 8;
    puVar4[0xb] = 0xf7;
  }
  bVar1 = puVar2[0xd];
  if (puVar2[0xc] == (byte)~bVar1) {
    puVar4[0xc] = puVar2[0xc];
    puVar4[0xd] = bVar1;
  }
  else {
    *(undefined2 *)(puVar4 + 0xc) = *(undefined2 *)(puVar6 + 0xc);
  }
  if (4 < (byte)puVar4[0xc]) {
    puVar4[0xc] = 0;
    puVar4[0xd] = 0xff;
  }
  *flash_ro_30690 = puVar4[0xc];
  puVar6 = flash_ro_30644;
  bVar1 = puVar2[0xf];
  if (puVar2[0xe] == (byte)~bVar1) {
    flash_ro_30644[0xe] = puVar2[0xe];
    puVar6[0xf] = bVar1;
  }
  else {
    *(undefined2 *)(flash_ro_30644 + 0xe) = *(undefined2 *)(flash_ro_43fae);
  }
  if (4 < (byte)puVar4[0xe]) {
    puVar4[0xe] = 4;
    puVar4[0xf] = 0xfb;
  }
  dbg_printf_2(str_Global_DATA,flash_ro_30644,0x10);
  return;
}

/* ==========================================================================
 * read   @ 0x0003049c   (112 bytes)
 * called by : profile_mem_init
 * calls     : flash_sub_396da, dbg_printf_2, rom_24F9C
 * string    : "read id_code:"
 */

void read(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  flash_sub_396da(0,shared_ro_306a4,6,flash_ro_30640,0);
  puVar3 = flash_ro_30644 + 0x10;
  if (((*flash_ro_30640 != (undefined)~flash_ro_30640[3]) || (flash_ro_30640[1] != (undefined)~flash_ro_30640[4])) ||
     (puVar2 = flash_ro_30640, flash_ro_30640[2] != (undefined)~flash_ro_30640[5])) {
    puVar2 = flash_ro_43fb0;
  }
  rom_24F9C(puVar3,puVar2,6);
  puVar1 = flash_ro_306b8;
  puVar2 = flash_ro_30644;
  *(uint *)flash_ro_306b8 = (uint)(byte)flash_ro_30644[0x10];
  *(uint *)(puVar1 + 4) = (uint)(byte)puVar2[0x11];
  *(uint *)(puVar1 + 8) = (uint)(byte)puVar2[0x12];
  dbg_printf_2(str_read_id_code,puVar3,3);
  return;
}

/* ==========================================================================
 * flash_sub_3050c   @ 0x0003050c   (32 bytes)
 * called by : Default_Profile, FLASH_RD_Profile, FLASH_WR_Profile
 */

short flash_sub_3050c(byte *param_1,uint param_2)

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
 * called by : FLASH_WR_Profile, flash_sub_333f0, Set_Report_Data, _saveC_GM_ProfileMax, profile_mem_init
 * calls     : flash_sub_3050c, flash_sub_396da, dbg_printf, dbg_printf_2, rom_24F9C
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
  undefined2 uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  if (4 < param_1) {
    param_1 = 0;
  }
  flash_sub_396da(0,*(undefined4 *)(flash_ro_3068c + param_1 * 4 + 0x8c),0x75,flash_ro_30640,0);
  dbg_printf_2(str_FLASH_RD_Profile,flash_ro_30640,0x75);
  puVar6 = flash_ro_30644;
  puVar5 = flash_ro_30640;
  bVar1 = flash_ro_30640[1];
  if (*flash_ro_30640 == (byte)~bVar1) {
    flash_ro_30644[0x16] = *flash_ro_30640;
    puVar6[0x17] = bVar1;
  }
  else {
    *(undefined2 *)(flash_ro_30644 + 0x16) = *(undefined2 *)(flash_ro_43fb6);
  }
  puVar6 = flash_ro_30644;
  cVar2 = flash_ro_30644[0x16];
  if ((((cVar2 != '\x01') && (cVar2 != '\x02')) && (cVar2 != '\x04')) && (cVar2 != '\b')) {
    flash_ro_30644[0x16] = 1;
    puVar6[0x17] = 0xfe;
  }
  dbg_printf(flash_ro_306e0,puVar6[0x16]);
  puVar7 = flash_ro_30644;
  puVar6 = flash_ro_30640;
  *(ushort *)(flash_ro_30644 + 0x48) = (ushort)(byte)flash_ro_30640[0x31] * 0x100 + (ushort)(byte)flash_ro_30640[0x32]
  ;
  uVar4 = flash_sub_3050c(puVar5 + 2,0x2f);
  puVar8 = puVar7 + 0x18;
  if (uVar4 == *(ushort *)(puVar7 + 0x48)) {
    rom_24F9C(puVar8,puVar5 + 2,0x2f);
  }
  else {
    rom_24F9C(puVar8,flash_ro_43fb8,0x2f);
    uVar3 = flash_sub_3050c(puVar8,0x2f);
    *(undefined2 *)(puVar7 + 0x48) = uVar3;
  }
  dbg_printf_2(str_SensorSet,puVar8,0x2f);
  *(ushort *)(puVar7 + 0x52) = (ushort)(byte)puVar6[0x3b] * 0x100 + (ushort)(byte)puVar6[0x3c];
  puVar5 = flash_ro_30640 + 0x33;
  uVar4 = flash_sub_3050c(puVar5,8);
  puVar6 = flash_ro_30644 + 0x4a;
  if (uVar4 == *(ushort *)(puVar7 + 0x52)) {
    rom_24F9C(puVar6,puVar5,8);
  }
  else {
    rom_24F9C(puVar6,flash_ro_43fe9,8);
    uVar3 = flash_sub_3050c(puVar6,8);
    *(undefined2 *)(puVar7 + 0x52) = uVar3;
  }
  dbg_printf_2(str_LightSet,puVar6,8);
  puVar5 = flash_ro_30af8;
  *(ushort *)(flash_ro_30af8 + 10) = (ushort)(byte)flash_ro_30640[0x73] * 0x100 + (ushort)(byte)flash_ro_30640[0x74];
  puVar6 = flash_ro_30afc;
  uVar4 = flash_sub_3050c(flash_ro_30afc,0x36);
  puVar7 = puVar5 + -0x2c;
  if (uVar4 == *(ushort *)(puVar5 + 10)) {
    rom_24F9C(puVar7,puVar6,0x36);
  }
  else {
    rom_24F9C(puVar7,flash_ro_30b00,0x36);
    uVar3 = flash_sub_3050c(puVar7,0x36);
    *(undefined2 *)(puVar5 + 10) = uVar3;
  }
  dbg_printf_2(str_ButtonSet,puVar7,0x36);
  return;
}

/* ==========================================================================
 * FLASH_WR_Profile   @ 0x00030740   (298 bytes)
 * called by : ble_sub_28c66
 * calls     : FLASH_RD_Profile, flash_sub_3050c, flash_sub_392b8, flash_sub_3932e, flash_sub_396da, flash_sub_39708, ... (+6 more)
 * string    : "FLASH_WR_Profile:"
 * string    : "address&0x3ff = %x\r\n"
 */

void FLASH_WR_Profile(uint param_1)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined *puVar6;
  uint uVar7;
  byte *pbVar8;
  undefined1 auStack_414 [1024];
  
  uVar7 = *(uint *)(flash_ro_30b00 + param_1 * 4 + 0x39);
  rom_24FEC(flash_ro_30afc + -0x3d,0xff);
  rom_24FEC(auStack_414,0x400);
  flash_sub_392b8();
  flash_sub_396da(0,uVar7 & 0xfffffc00,0x400,auStack_414,0);
  flash_sub_3976e(0,uVar7,0x1000);
  flash_sub_3932e();
  puVar3 = flash_ro_30afc;
  puVar2 = flash_ro_30af8;
  pbVar1 = flash_ro_30af8 + -0x6a;
  pbVar8 = flash_ro_30afc + -0x3d;
  bVar4 = ~*pbVar1;
  flash_ro_30af8[-0x69] = bVar4;
  *pbVar8 = *pbVar1;
  puVar3[-0x3c] = bVar4;
  rom_24F9C(puVar3 + -0x3b,puVar2 + -0x68,0x2f);
  uVar5 = flash_sub_3050c(puVar3 + -0x3b,0x2f);
  *(undefined2 *)(puVar2 + -0x38) = uVar5;
  puVar3[-0xc] = (char)((ushort)uVar5 >> 8);
  puVar3[-0xb] = (char)uVar5;
  puVar6 = puVar3 + -10;
  rom_24F9C(puVar6,puVar2 + -0x36,8);
  uVar5 = flash_sub_3050c(puVar6,8);
  *(undefined2 *)(puVar2 + -0x2e) = uVar5;
  puVar3[-2] = (char)((ushort)uVar5 >> 8);
  puVar3[-1] = (char)uVar5;
  puVar3 = flash_ro_30afc;
  rom_24F9C(flash_ro_30afc,puVar2 + -0x2c,0x36);
  uVar5 = flash_sub_3050c(puVar3,0x36);
  *(undefined2 *)(flash_ro_30af8 + 10) = uVar5;
  puVar3 = flash_ro_30afc;
  flash_ro_30afc[0x36] = (char)((ushort)uVar5 >> 8);
  puVar3[0x37] = (char)uVar5;
  dbg_printf_2(str_FLASH_WR_Profile,puVar3 + -0x3d,0x75);
  if (4 < param_1) {
    param_1 = 0;
  }
  rom_24F9C(auStack_414 + (*(ushort *)(flash_ro_30b00 + param_1 * 4 + 0x39) & 0x3ff),flash_ro_30afc + -0x3d,0x75
           );
  dbg_printf(flash_ro_30b24,*(ushort *)(flash_ro_30b00 + param_1 * 4 + 0x39) & 0x3ff);
  *(undefined4 *)flash_ro_30b28 = 0x7c000;
  flash_sub_39708(0,0x7c000,0x400,auStack_414,0);
  if ((byte)puVar2[-0x74] != param_1) {
    *flash_ro_30b2c = puVar2[-0x74];
    FLASH_RD_Profile();
  }
  input_sub_3ce00();
  return;
}

/* ==========================================================================
 * flash_erase   @ 0x0003086a   (330 bytes)
 * called by : ble_sub_28c66
 * calls     : flash_sub_392b8, flash_sub_3932e, flash_sub_396da, flash_sub_39708, flash_sub_3976e, dbg_printf, ... (+2 more)
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
  flash_sub_392b8();
  flash_sub_3976e(0,0x52000,0x1000);
  dbg_printf(str_flash_erase_FLASHADDR_BACKUP);
  do {
    flash_sub_396da(0,uVar1 * 0x400 + 0x7d000,0x400,auStack_418,0);
    flash_sub_39708(0,uVar1 * 0x400 + 0x52000,0x400,auStack_418,0);
    dbg_printf_2(str_backup,auStack_418,0x10);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 4);
  flash_sub_3976e(0,0x7d000,0x1000);
  dbg_printf(str_flash_erase_FLASHADDR_MACRO);
  uVar1 = 0;
  do {
    if (uVar1 != uVar2) {
      flash_sub_396da(0,uVar1 * 0x400 + 0x52000,0x400,auStack_418,0);
      flash_sub_39708(0,uVar1 * 0x400 + 0x7d000,0x400,auStack_418,0);
    }
    dbg_printf_2(str_restore,auStack_418,0x10);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 4);
  flash_sub_396da(0,uVar2 * 0x400 + 0x52000,0x400,auStack_418,0);
  rom_24F9C(auStack_418 + (param_1 & 7) * 0x80,flash_ro_30afc + -0x3d,0x80);
  dbg_printf_2(str_Flashmem_buff,flash_ro_30afc + -0x3d,0x80);
  flash_sub_39708(0,uVar2 * 0x400 + 0x7d000,0x400,auStack_418,0);
  flash_sub_3932e();
  dbg_printf(str_flash_wp_ALL);
  return;
}

/* ==========================================================================
 * FLASH_RD_Macro   @ 0x000309b4   (68 bytes)
 * called by : _saveC_GM_ProfileMax
 * calls     : flash_sub_396da, dbg_printf, dbg_printf_2, rom_24F9C
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
  flash_sub_396da(0,iVar1,0x80,flash_ro_30afc + -0x3d,0);
  rom_24F9C(flash_ro_30c14,flash_ro_30afc + -0x3d,0x80);
  dbg_printf_2(str_read_macro,flash_ro_30afc + -0x3d,0x80);
  return;
}

/* ==========================================================================
 * Default_Profile   @ 0x000309f8   (462 bytes)
 * called by : ble_sub_28c66
 * calls     : flash_sub_3050c, ble_sub_31406, flash_sub_392b8, flash_sub_3932e, flash_sub_396da, flash_sub_39708, ... (+9 more)
 * string    : "address&0x3ff = %x\r\n"
 * string    : "Default_Profile:"
 * string    : "Polling0:"
 * string    : "Sensor:"
 * string    : "Light:"
 * string    : "ButtonSet:"
 */

void Default_Profile(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_414 [128];
  undefined1 auStack_394 [128];
  undefined1 auStack_314 [128];
  undefined1 auStack_294 [128];
  undefined1 auStack_214 [128];
  undefined1 auStack_194 [384];
  
  rom_24FEC(flash_ro_30afc + -0x3d,0xff);
  rom_24FEC(auStack_414,0x400);
  flash_sub_392b8();
  flash_sub_396da(0,0x7c000,0x400,auStack_414,0);
  flash_sub_3976e(0,0x7c000,0x1000);
  flash_sub_3932e();
  rom_24F9C(flash_ro_30af8 + -0x80,flash_ro_30b00 + -0x53,0x10);
  rom_24F9C(flash_ro_30afc + -0x3d,flash_ro_30b00 + -0x53,0x10);
  rom_24F9C(auStack_414,flash_ro_30afc + -0x3d,0x10);
  dbg_printf(flash_ro_30b24,0);
  rom_24F9C(flash_ro_30afc + -0x3d,flash_ro_30b00 + -0x3d,0x75);
  dbg_printf_2(str_Default_Profile,flash_ro_30afc + -0x3d,0x75);
  puVar2 = flash_ro_30afc;
  puVar1 = flash_ro_30af8;
  puVar5 = flash_ro_30afc + -0x3d;
  flash_ro_30af8[-0x6a] = *puVar5;
  puVar1[-0x69] = puVar2[-0x3c];
  dbg_printf_2(str_Polling0,puVar5,2);
  rom_24F9C(flash_ro_30af8 + -0x68,puVar2 + -0x3b,0x2f);
  uVar3 = flash_sub_3050c(puVar2 + -0x3b,0x2f);
  puVar1 = flash_ro_30af8;
  *(undefined2 *)(flash_ro_30af8 + -0x38) = uVar3;
  puVar2[-0xc] = (char)((ushort)uVar3 >> 8);
  puVar2[-0xb] = (char)uVar3;
  dbg_printf_2(str_Sensor,puVar2 + -0x3b,0x31);
  puVar4 = puVar2 + -10;
  rom_24F9C(puVar1 + -0x36,puVar4,8);
  uVar3 = flash_sub_3050c(puVar4,8);
  *(undefined2 *)(puVar1 + -0x2e) = uVar3;
  puVar2[-2] = (char)((ushort)uVar3 >> 8);
  puVar2[-1] = (char)uVar3;
  dbg_printf_2(str_Light,puVar4,10);
  rom_24F9C(puVar1 + -0x2c,puVar2,0x36);
  uVar3 = flash_sub_3050c(puVar2,0x36);
  *(undefined2 *)(puVar1 + 10) = uVar3;
  puVar2[0x36] = (char)((ushort)uVar3 >> 8);
  puVar2[0x37] = (char)uVar3;
  dbg_printf_2(flash_ro_30ff8,puVar2,0x38);
  rom_24F9C(auStack_394,puVar2 + -0x3d,0x75);
  dbg_printf(flash_ro_30ffc,0x80);
  rom_24F9C(auStack_314,puVar2 + -0x3d,0x75);
  dbg_printf(flash_ro_30ffc,0x80);
  rom_24F9C(auStack_294,puVar2 + -0x3d,0x75);
  dbg_printf(flash_ro_30ffc,0x80);
  rom_24F9C(auStack_214,puVar2 + -0x3d,0x75);
  dbg_printf(flash_ro_30ffc,0x80);
  rom_24F9C(auStack_194,puVar2 + -0x3d,0x75);
  dbg_printf(flash_ro_30ffc,0x80);
  *(undefined4 *)flash_ro_31000 = 0x7c000;
  flash_sub_39708(0,0x7c000,0x400,auStack_414,0);
  flash_sub_3c2c6();
  set_dpi();
  ble_sub_31406();
  *flash_ro_31004 = 0;
  OLED_Clear();
  flash_sub_3cf7c();
  return;
}

/* ==========================================================================
 * _saveC_GM_ProfileMax   @ 0x00030d32   (400 bytes)
 * called by : system_mode
 * calls     : FLASH_RD_Macro, FLASH_RD_Profile, FLASH_wr_Global, flash_sub_3c2c6, dbg_printf, dbg_printf_2, ... (+2 more)
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
  undefined *puVar4;
  undefined *puVar5;
  char cVar6;
  int extraout_r1;
  undefined *puVar7;
  undefined4 in_r3;
  undefined1 uVar8;
  
  puVar4 = flash_ro_31018;
  puVar5 = flash_ro_31010;
  uVar8 = 0;
  bVar1 = *flash_ro_31010;
  if (bVar1 == 0) {
LAB_00030d66:
    puVar4 = flash_ro_31020;
    if (*flash_ro_31020 != '\0') {
      *puVar5 = *flash_ro_31020;
      *puVar4 = uVar8;
    }
    return;
  }
  flash_ro_31014[1] = 0;
  puVar7 = flash_ro_3100c;
  cVar2 = *flash_ro_3100c;
  if (bVar1 == 10) {
    if (((*flash_ro_3101c == '\x01') || (*flash_ro_3101c == '\x02')) && (*flash_ro_31064 == '\0')) {
      *flash_ro_31054 = 1;
    }
    else {
      FLASH_wr_Global();
    }
    goto LAB_00030e9e;
  }
  if (bVar1 < 0xb) {
    rom_25078();
    *(undefined **)(extraout_r1 * 2) = puVar5;
    uVar8 = puVar5[0x19];
    goto LAB_00030d66;
  }
  cVar3 = flash_ro_31008[0xc];
  cVar6 = cVar3;
  if (bVar1 != 0x25) {
    if (bVar1 < 0x26) {
      if (bVar1 == 0xc) {
        puVar7 = flash_ro_31008 + 0xc;
        dbg_printf_2(str_saveC_GM_ProfileMax,puVar7,4);
        puVar4 = flash_ro_31008;
        dbg_printf(str_Current_Profile_x_x_MaxProfile_x_x,flash_ro_31008[0xc],flash_ro_31008[0xd],flash_ro_31008[0xe],
                   flash_ro_31008[0xf]);
        if ((puVar4[0xd] != (undefined)~puVar4[0xc]) || (puVar4[0xf] != (undefined)~puVar4[0xe])) {
          if (puVar4[0xd] == (undefined)~puVar4[0xc]) {
            *puVar5 = 0;
          }
          else {
            *puVar5 = 0x23;
            dbg_printf_2(str_RD_Profile,puVar7,4);
          }
          puVar4[0xd] = ~puVar4[0xc];
          puVar4[0xf] = ~puVar4[0xe];
          if (((*flash_ro_3101c == '\x01') || (*flash_ro_3101c == '\x02')) && (*flash_ro_31064 == '\0')) {
            *flash_ro_31054 = 1;
          }
          else {
            FLASH_wr_Global();
          }
          dbg_printf_2(str_WR_Profile,puVar7,4);
          return;
        }
        goto LAB_00030e9e;
      }
      cVar6 = cVar2;
      if (bVar1 != 0x22) {
        if (bVar1 == 0x23) {
          if (*flash_ro_31054 != '\0') {
            return;
          }
          if (*flash_ro_31058 != '\0') {
            return;
          }
          if (*flash_ro_3105c != '\0') {
            return;
          }
          if (*flash_ro_31060 != '\0') {
            return;
          }
          if (cVar3 != cVar2) {
            *flash_ro_3100c = cVar3;
            FLASH_RD_Profile(cVar3);
            set_dpi();
            flash_sub_3c2c6();
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
      cVar6 = flash_ro_31008[0xc];
      if (cVar6 == *puVar7) goto LAB_00030e9e;
      *puVar7 = cVar6;
    }
    else if (bVar1 != 0x28) {
      if (bVar1 != 0x29) {
        return;
      }
      dbg_printf(str_read9_GM_macro_report_id_x_macro_index_x,flash_ro_31014[2],*puVar4,puVar4,in_r3);
      FLASH_RD_Macro(*puVar4);
      goto LAB_00030e9e;
    }
  }
  FLASH_RD_Profile(cVar6);
LAB_00030e9e:
  *puVar5 = 0;
  return;
}

/* ==========================================================================
 * nvds_Polling_read   @ 0x00030f4a   (58 bytes)
 * calls     : flash_sub_3c2c6, ble_sub_3e552, KEY_piaring_cnt, dbg_printf
 * string    : "nvds_Polling_read"
 * string    : "%s read_data= %x, Polling=%x\r\n"
 */

void nvds_Polling_read(void)

{
  undefined *puVar1;
  int iVar2;
  byte in_stack_00000000;
  
  KEY_piaring_cnt();
  iVar2 = ble_sub_3e552();
  puVar1 = flash_ro_31008;
  if (iVar2 == 0) {
    if (in_stack_00000000 < 9) {
      flash_ro_31008[0x16] = in_stack_00000000;
      puVar1[0x17] = ~in_stack_00000000;
    }
  }
  flash_sub_3c2c6();
  dbg_printf(str_s_read_data_x_Polling_x,flash_ro_310c4,in_stack_00000000,puVar1[0x16]);
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * nvds_Polling_write   @ 0x00030f96   (48 bytes)
 * calls     : flash_sub_3c2c6, ble_sub_3e5f0, KEY_piaring_cnt, dbg_printf
 * string    : "nvds_Polling_write"
 * string    : "%s Profile= %x, rgb_disp_type=%x\r\n"
 */

void nvds_Polling_write(void)

{
  undefined *puVar1;
  
  KEY_piaring_cnt();
  puVar1 = flash_ro_31008;
  if ((byte)flash_ro_31008[0x16] < 9) {
    ble_sub_3e5f0();
  }
  flash_sub_3c2c6();
  dbg_printf(str_s_Profile_x_rgb_disp_type_x,str_nvds_Polling_write,puVar1[0xc],puVar1[0x16]);
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
  dbg_printf(str_s_9,str_profile_mem_init);
  KEY_piaring_cnt();
  FLASH_RD_Global();
  KEY_piaring_cnt();
  FLASH_RD_Profile(flash_ro_31008[0xc]);
  KEY_piaring_cnt();
  read();
  return;
}

/* ==========================================================================
 * flash_sub_31808   @ 0x00031808   (102 bytes)
 * calls     : flash_sub_3c2c6, usb_sub_3cf24
 */

void flash_sub_31808(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  
  puVar2 = shared_ro_31c00;
  cVar1 = shared_ro_31c00[0x16];
  if (cVar1 == '\x01') {
    uVar4 = 8;
  }
  else {
    if (cVar1 == '\x02') {
      shared_ro_31c00[0x16] = 1;
      goto LAB_00031820;
    }
    if (cVar1 == '\b') {
      uVar4 = 4;
    }
    else {
      uVar4 = 2;
    }
  }
  shared_ro_31c00[0x16] = uVar4;
LAB_00031820:
  flash_sub_3c2c6();
  usb_sub_3cf24();
  if (((*shared_ro_31c04 == '\x01') || (*shared_ro_31c04 == '\x02')) && (*flash_ro_31c08 == '\0')) {
    *flash_ro_31c18 = 1;
  }
  else {
    *shared_ro_31c0c = 6;
  }
  puVar3 = flash_ro_31c10;
  *flash_ro_31c10 = 0x10;
  puVar3[1] = 0x20;
  puVar3[2] = puVar2[0x16];
  puVar3[3] = 0;
  *flash_ro_31c14 = 1;
  return;
}

/* ==========================================================================
 * flash_sub_3262c   @ 0x0003262c   (44 bytes)
 * called by : Success_led_2second, Success_led_2second_2, enter_BLE_normal_app_mode, f_usb_isConnected, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 */

void flash_sub_3262c(void)

{
  char cVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
  puVar2 = shared_ro_329e4;
  *shared_ro_329e4 = 0;
  if (*shared_ro_329ec == '\0') {
    cVar1 = *shared_ro_329f0;
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
 * flash_sub_32658   @ 0x00032658   (46 bytes)
 * called by : led_sub_32942, Set_SIMU_mode_LightUp_Led, Success_led_2second, Success_led_2second_2, enter_BLE_normal_app_mode, f_usb_isConnected, ... (+4 more)
 */

void flash_sub_32658(void)

{
  byte bVar1;
  undefined *puVar2;
  
  puVar2 = shared_ro_329e8;
  bVar1 = *shared_ro_329e4;
  if ((bVar1 & 1) == 0) {
    *(undefined4 *)(shared_ro_329e8 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(shared_ro_329e8 + 0x20) = 2;
  }
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    *(undefined4 *)(puVar2 + 0x24) = 2;
  }
  else {
    *(undefined4 *)(puVar2 + 0x24) = 0;
  }
  if ((int)((uint)bVar1 << 0x1d) < 0) {
    *(undefined4 *)(puVar2 + 0x28) = 2;
    return;
  }
  *(undefined4 *)(puVar2 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * set_USB_led_flash   @ 0x00032766   (100 bytes)
 * calls     : flash_sub_3262c, flash_sub_32658, flash_sub_32e82, flash_sub_32f16, flash_sub_3c8b6, flash_sub_3cf7c, ... (+2 more)
 * string    : "set_USB_led_flash"
 * string    : "%s ,%x\r\n"
 * string    : "%s, Ind_Led_STEP=%d\r\n"
 */

void set_USB_led_flash(void)

{
  undefined *puVar1;
  
  dbg_printf(str_s_x,str_set_USB_led_flash,*shared_ro_329f0);
  *shared_ro_32a48 = 0;
  *flash_ro_32a4c = 0;
  *shared_ro_32a50 = 1;
  *shared_ro_32a54 = 0;
  *(undefined2 *)shared_ro_32a58 = 0x10;
  *shared_ro_32a5c = 1;
  *(undefined2 *)shared_ro_32a60 = 0x20;
  flash_sub_3262c();
  flash_sub_32658();
  puVar1 = shared_ro_32a64;
  *shared_ro_32a64 = 0x3d;
  flash_sub_32f16();
  flash_sub_32e82();
  dbg_printf(str_s_Ind_Led_STEP_d,str_set_USB_led_flash,*puVar1);
  flash_sub_3c8b6();
  OLED_Clear();
  flash_sub_3cf7c();
  return;
}

/* ==========================================================================
 * set_pairing_led_flash   @ 0x000327ca   (86 bytes)
 * called by : flash_sub_2fef0
 * calls     : flash_sub_3262c, flash_sub_32658, flash_sub_32e82, flash_sub_32f16, flash_sub_3c8b6, flash_sub_3cf7c, ... (+2 more)
 * string    : "set_pairing_led_flash"
 * string    : "%s, Ind_Led_STEP=%d\r\n"
 */

void set_pairing_led_flash(void)

{
  undefined *puVar1;
  
  *shared_ro_32a48 = 0;
  *flash_ro_32a4c = 0;
  *(undefined2 *)shared_ro_32a58 = 0x3c;
  *shared_ro_32a5c = 1;
  *shared_ro_32a50 = 1;
  *shared_ro_32a54 = 0;
  *(undefined2 *)shared_ro_32a60 = 0x78;
  flash_sub_3262c();
  flash_sub_32658();
  puVar1 = shared_ro_32a64;
  *shared_ro_32a64 = 0x3d;
  flash_sub_32f16();
  flash_sub_32e82();
  dbg_printf(str_s_Ind_Led_STEP_d,str_set_pairing_led_flash,*puVar1);
  flash_sub_3c8b6();
  OLED_Clear();
  flash_sub_3cf7c();
  return;
}

/* ==========================================================================
 * set_bonded_led_flash   @ 0x00032820   (102 bytes)
 * called by : LightUp_Mode_Led, SLEEP, fWorkModeInit, f_reconnect_24G
 * calls     : flash_sub_3262c, flash_sub_32658, flash_sub_32e82, flash_sub_32f16, flash_sub_3c8b6, flash_sub_3cf7c, ... (+2 more)
 * string    : "set_bonded_led_flash"
 * string    : "%s, %x \r\n"
 * string    : "%s, Ind_Led_STEP=%d\r\n"
 */

void set_bonded_led_flash(void)

{
  undefined *puVar1;
  
  dbg_printf(str_s_x_2,str_set_bonded_led_flash,*shared_ro_329f0);
  *shared_ro_32a48 = 0;
  *flash_ro_32a4c = 0;
  *(undefined2 *)shared_ro_32a58 = 10;
  *shared_ro_32a5c = 1;
  *shared_ro_32a50 = 2;
  *shared_ro_32a54 = 0;
  *(undefined2 *)shared_ro_32a60 = 0x28;
  flash_sub_3262c();
  flash_sub_32658();
  puVar1 = shared_ro_32a64;
  *shared_ro_32a64 = 0x3d;
  flash_sub_32f16();
  flash_sub_32e82();
  dbg_printf(str_s_Ind_Led_STEP_d,str_set_bonded_led_flash,*puVar1);
  flash_sub_3c8b6();
  OLED_Clear();
  flash_sub_3cf7c();
  return;
}

/* ==========================================================================
 * flash_sub_32e82   @ 0x00032e82   (2 bytes)
 * called by : power_sub_3297e, SLEEP, app_mutli_link_change, force_ble_sleep, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 */

void flash_sub_32e82(void)

{
  return;
}

/* ==========================================================================
 * flash_sub_32f16   @ 0x00032f16   (12 bytes)
 * called by : power_sub_3297e, SLEEP, app_mutli_link_change, force_ble_sleep, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 * calls     : rom_24FEC
 */

void flash_sub_32f16(void)

{
  rom_24FEC(flash_ro_32fdc,0x18);
  return;
}

/* ==========================================================================
 * flash_sub_333f0   @ 0x000333f0   (116 bytes)
 * calls     : FLASH_RD_Profile, OLED_Init, dbg_printf_2, rom_24F9C, rom_24FEC, rom_25078
 */

void flash_sub_333f0(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined2 unaff_r7;
  
  OLED_Init();
  puVar3 = shared_ro_337dc;
  rom_24FEC(*(undefined4 *)(shared_ro_337dc + 4),0x84);
  puVar4 = shared_ro_337e4;
  puVar5 = shared_ro_337e0 + 0x20;
  rom_25078();
  puVar5 = puVar5 + (int)puVar4;
  *(undefined2 *)(puVar5 + 0x12) = unaff_r7;
  rom_24F9C(shared_ro_337e0,shared_ro_337e4 + 0x18,0x2f);
  uVar2 = *(undefined2 *)(shared_ro_337e4 + 0x48);
  puVar5[0xf] = (char)((ushort)uVar2 >> 8);
  puVar5[0x10] = (char)uVar2;
  rom_24F9C(*(undefined4 *)(puVar3 + 4),shared_ro_337e0,0x31);
  dbg_printf_2(str_GM04_sensit_get,*(undefined4 *)(puVar3 + 4),0x31);
  puVar5 = shared_ro_33810;
  *(undefined **)(puVar3 + 4) = shared_ro_337dc + 9;
  cVar1 = puVar4[0xc];
  if (cVar1 != *puVar5) {
    *puVar5 = cVar1;
    FLASH_RD_Profile();
  }
  return;
}

/* ==========================================================================
 * flash_sub_36cbe   @ 0x00036cbe   (20 bytes)
 * called by : flash_sub_2fef0
 */

void flash_sub_36cbe(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd4) = 0;
  *(undefined4 *)(shared_ro_36d84 + 0x14) = 0x8a;
  *(undefined4 *)(puVar1 + 0xd4) = 1;
  return;
}

/* ==========================================================================
 * flash_sub_36cee   @ 0x00036cee   (32 bytes)
 * called by : flash_sub_2fef0
 * calls     : usb_sub_369fa
 */

void flash_sub_36cee(void)

{
  usb_sub_369fa(shared_ro_36d84 + 0x1c,shared_ro_36d88 + 0x18,3);
  usb_sub_369fa(shared_ro_36d84 + 0x54,shared_ro_36d88 + 0x18,3);
  return;
}

/* ==========================================================================
 * flash_sub_36f88   @ 0x00036f88   (26 bytes)
 * called by : power_sub_371c2, flash_sub_38072, flash_sub_38144, _USB_macro2
 */

void flash_sub_36f88(int param_1)

{
  bool bVar1;
  undefined4 local_8;
  
  local_8 = param_1;
  if (*flash_ro_37380 == '\x05') {
    local_8 = param_1 << 2;
  }
  do {
    bVar1 = local_8 != 0;
    local_8 = local_8 + -1;
  } while (bVar1);
  return;
}

/* ==========================================================================
 * flash_sub_36fec   @ 0x00036fec   (12 bytes)
 * called by : usb_sub_374e2, _USB_macro2
 */

undefined2 flash_sub_36fec(void)

{
  return *(undefined2 *)(shared_ro_37384 + 0x11);
}

/* ==========================================================================
 * flash_sub_36ff8   @ 0x00036ff8   (12 bytes)
 * called by : flash_sub_37004
 */

undefined2 flash_sub_36ff8(void)

{
  return *(undefined2 *)(shared_ro_37384 + 0x16);
}

/* ==========================================================================
 * flash_sub_37004   @ 0x00037004   (116 bytes)
 * called by : usb_sub_37508, _USB_macro2
 * calls     : flash_sub_36ff8, rom_24F9C
 */

uint flash_sub_37004(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_20;
  uint local_1c;
  
  shared_ro_37384[0xe] = (char)param_1;
  uVar4 = param_2;
  uVar2 = flash_sub_36ff8();
  if ((uVar4 & 3) == 0) {
    local_1c = uVar2 >> 2;
  }
  else {
    local_1c = 0;
  }
  uVar4 = 0;
  puVar3 = (undefined4 *)(shared_ro_37384 + (param_1 * 4 + 0x20U & 0xff));
  for (uVar5 = 0; puVar1 = shared_ro_37384, uVar5 < local_1c; uVar5 = uVar5 + 1) {
    local_20 = *puVar3;
    rom_24F9C(param_2 + uVar4,&local_20,4);
    uVar4 = uVar4 + 4;
  }
  for (; uVar4 < uVar2; uVar4 = uVar4 + 1) {
    *(undefined1 *)(param_2 + uVar4) = *(undefined1 *)puVar3;
  }
  if (param_1 == 0) {
    puVar1[0x11] = 0;
  }
  else {
    puVar1[0x14] = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * _USB_macro2   @ 0x0003726a   (560 bytes)
 * called by : usb_sub_37534
 * calls     : flash_sub_36f88, flash_sub_36fec, flash_sub_37004, usb_sub_370d0, usb_sub_37104, flash_sub_38072, ... (+4 more)
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
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined1 uVar11;
  undefined *puVar12;
  undefined *puVar13;
  char local_a8;
  byte local_a7;
  undefined1 local_a6;
  char local_a5;
  undefined1 local_a4 [132];
  undefined1 auStack_20 [12];
  
  pcVar10 = &local_a8;
  rom_24FEC(&local_a8,0x88);
  puVar12 = shared_ro_37384;
  shared_ro_37384[0xe] = 0;
  uVar5 = flash_sub_36fec();
  flash_sub_36f88(100);
  puVar3 = flash_ro_3769c;
  puVar2 = flash_ro_37698;
  puVar13 = flash_ro_37394;
  puVar7 = shared_ro_37388;
  if ((uVar5 & 1) == 0) {
    if ((int)(uVar5 << 0x1b) < 0) {
      puVar12[0x11] = 0x80;
    }
    else {
      if (shared_ro_37388[0xe] == '\x01') {
        if ((byte)*flash_ro_37394 < 0x40) {
          rom_24F9C(*(undefined4 *)flash_ro_3769c,&local_a8);
          cVar4 = '\0';
        }
        else {
          rom_24F9C(*(undefined4 *)flash_ro_3769c,&local_a8,0x40);
          *(int *)puVar3 = *(int *)puVar3 + 0x40;
          cVar4 = *puVar13 + -0x40;
        }
        *puVar13 = cVar4;
        goto LAB_00037480;
      }
      if (*flash_ro_37698 == '\x04') {
        *puVar12 = *flash_ro_376a0 & 0x7f;
        *puVar2 = 8;
      }
    }
    puVar7[0xe] = 5;
  }
  else {
    if (shared_ro_37388[0xe] == '\x02') {
      iVar6 = flash_sub_37004(0,&local_a8);
      puVar12 = shared_ro_37388;
      uVar1 = *(ushort *)(puVar7 + 10);
      if (iVar6 < (int)(uint)uVar1) {
        uVar8 = usb_sub_4245e(puVar7 + 4);
        rom_24F9C(uVar8,&local_a8,iVar6);
        uVar1 = *(ushort *)(puVar7 + 10);
        puVar7[10] = (char)((uint)uVar1 - iVar6);
        puVar7[0xb] = (char)((uint)uVar1 - iVar6 >> 8);
        return;
      }
      puVar7 = shared_ro_37388 + 4;
      shared_ro_37388[0xe] = 5;
      uVar8 = usb_sub_4245e(puVar7);
      rom_24F9C(uVar8,&local_a8,(uint)uVar1);
      puVar2 = flash_ro_3739c;
      puVar7 = flash_ro_37398;
      if (*(short *)(puVar12 + 10) != 0) {
        if (*(short *)(puVar12 + 10) == 1) {
          *flash_ro_373a0 = local_a8;
          *flash_ro_373a4 = 1;
          puVar7[1] = 0;
        }
        else {
          if (local_a8 == -0x60) {
            flash_ro_37398[2] = local_a7;
            *puVar13 = local_a6;
            *puVar2 = local_a4[0];
            if (puVar7[1] == '\x02') {
              *flash_ro_373c0 = 1;
            }
            else {
              *flash_ro_373a8 = 0;
              *flash_ro_373ac = 0;
            }
            uVar11 = 8;
            pcVar9 = str_set_report_rd;
          }
          else {
            flash_ro_37398[2] = local_a8;
            uVar5 = (uint)local_a7;
            *flash_ro_37394 = local_a7;
            puVar12 = puVar7 + 9;
            *puVar2 = local_a6;
            if (local_a8 == '\t') {
              *flash_ro_37644 = local_a5;
              puVar2 = flash_ro_3765c;
              puVar13 = flash_ro_37648;
              if (local_a5 == '\0') {
                rom_24FEC(puVar12,0x84);
                *(undefined **)(puVar7 + 4) = puVar12;
                puVar13 = flash_ro_37648;
                rom_24F9C(puVar12,&local_a8,uVar5);
                uVar11 = *puVar13;
                pcVar10 = *(char **)(puVar7 + 4);
                pcVar9 = str_USB_macro0;
              }
              else {
                if (local_a5 != '\x01') {
                  if (local_a5 == '\x02') {
                    puVar13 = flash_ro_3765c + 0x3c;
                    *(undefined **)(puVar7 + 4) = puVar13;
                    rom_24F9C(puVar13,local_a4,8);
                    dbg_printf_2(str_USB_macro2,puVar13,8);
                    *(undefined **)(puVar7 + 4) = puVar12;
                    dbg_printf_2(str_USB_macro,puVar12,0x84);
                    if (puVar7[1] == '\x01') {
                      *flash_ro_3768c = 1;
                    }
                    *flash_ro_37690 = 1;
                  }
                  goto LAB_00037450;
                }
                *(undefined **)(puVar7 + 4) = flash_ro_3765c;
                rom_24F9C(puVar2,local_a4,uVar5 - 4);
                uVar11 = *puVar13;
                pcVar10 = *(char **)(puVar7 + 4);
                pcVar9 = str_USB_macro1;
              }
            }
            else {
              if (puVar7[1] == '\x01') {
                *flash_ro_373c0 = 1;
              }
              *(undefined **)(puVar7 + 4) = puVar12;
              puVar7 = flash_ro_37394;
              rom_24F9C(puVar12,&local_a8,uVar5);
              *flash_ro_373c4 = 1;
              uVar11 = *puVar7;
              pcVar9 = str_usb_set_report;
              pcVar10 = &local_a8;
            }
          }
          dbg_printf_2(pcVar9,pcVar10,uVar11);
        }
      }
LAB_00037450:
      puVar12 = flash_ro_37694;
      flash_ro_37694[10] = 0;
      puVar12[0xb] = 0;
      usb_sub_370d0();
      return;
    }
    iVar6 = flash_sub_37004(0,&local_a8);
    if (0 < iVar6) {
      rom_24F9C(auStack_20,&local_a8);
      flash_sub_38072(auStack_20,puVar7);
      return;
    }
LAB_00037480:
    usb_sub_37104(0,flash_ro_37694);
  }
  return;
}

/* ==========================================================================
 * flash_sub_37b02   @ 0x00037b02   (8 bytes)
 * called by : flash_sub_38072
 */

uint flash_sub_37b02(byte *param_1)

{
  return (*param_1 & 0x7f) >> 5;
}

/* ==========================================================================
 * flash_sub_38068   @ 0x00038068   (10 bytes)
 * called by : flash_sub_38072
 */

void flash_sub_38068(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00038070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(flash_ro_38230 + (uint)*(byte *)(param_1 + 1) * 4))();
  return;
}

/* ==========================================================================
 * flash_sub_38072   @ 0x00038072   (52 bytes)
 * called by : _USB_macro2
 * calls     : flash_sub_36f88, usb_sub_370c6, flash_sub_37b02, flash_sub_38068, HID_RQT_Get_Protocol
 */

void flash_sub_38072(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = flash_sub_37b02(param_1,param_2,param_1);
  if (uVar1 == 0) {
    flash_sub_38068(param_1);
    flash_sub_36f88(300);
    return;
  }
  if (uVar1 != 1) {
    if (1 < uVar1) {
      usb_sub_370c6(0);
    }
    return;
  }
  HID_RQT_Get_Protocol(param_1);
  return;
}

/* ==========================================================================
 * flash_sub_38144   @ 0x00038144   (40 bytes)
 * calls     : flash_sub_36f88
 */

void flash_sub_38144(int param_1)

{
  if (param_1 == 0) {
    reg_80000c = reg_80000c | 0x800;
  }
  else {
    reg_80000c = reg_80000c | 0x800;
    flash_sub_36f88(500);
    reg_80000c = reg_80000c & 0xfffff7ff;
  }
  return;
}

/* ==========================================================================
 * flash_sub_391c0   @ 0x000391c0   (34 bytes)
 * called by : flash_sub_391fc, flash_sub_39708, flash_sub_3976e, flash_mid
 */

undefined4 flash_sub_391c0(void)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_3958c;
  do {
  } while (*(int *)shared_ro_3958c < 0);
  *(undefined4 *)shared_ro_3958c = flash_ro_39594;
  do {
  } while (*(int *)puVar1 < 0);
  uVar2 = 0;
  do {
    *(undefined4 *)(puVar1 + 4) = 0xffffffff;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return *(undefined4 *)(puVar1 + 0x10);
}

/* ==========================================================================
 * flash_sub_391e2   @ 0x000391e2   (26 bytes)
 * called by : flash_sub_392b8, flash_sub_3932e
 */

uint flash_sub_391e2(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3958c;
  do {
  } while (*(int *)shared_ro_3958c < 0);
  *(undefined4 *)shared_ro_3958c = flash_ro_39598;
  do {
  } while (*(int *)puVar1 < 0);
  return *(uint *)(puVar1 + 0x14) & 0xff;
}

/* ==========================================================================
 * flash_sub_391fc   @ 0x000391fc   (188 bytes)
 * called by : flash_sub_392b8, flash_sub_3932e
 * calls     : flash_sub_391c0
 */

void flash_sub_391fc(uint param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  
  iVar2 = flash_sub_391c0();
  puVar1 = flash_ro_3959c;
  piVar6 = (int *)shared_ro_3958c;
  iVar3 = *(int *)(flash_ro_3959c + 8);
  if (iVar2 != iVar3) {
    return;
  }
  if (iVar3 == flash_ro_395a0) {
LAB_0003925e:
    uVar4 = *(uint *)(shared_ro_3958c + 0x1c);
    uVar5 = flash_ro_395b8;
LAB_00039262:
    uVar4 = uVar4 & uVar5;
  }
  else {
    if (iVar3 < flash_ro_395a0) {
      if (iVar3 + flash_ro_395a4 != 0) {
        iVar2 = iVar3 + flash_ro_395a4 + flash_ro_395a8;
        if (iVar2 == 0) {
LAB_00039296:
          uVar4 = *(uint *)(shared_ro_3958c + 0x1c);
          uVar5 = flash_ro_395bc;
          goto LAB_00039262;
        }
        iVar2 = iVar2 + flash_ro_395ac;
        if ((iVar2 == 0) || (iVar2 == 1)) {
          uVar4 = *(uint *)(shared_ro_3958c + 0x1c);
          uVar5 = flash_ro_395b4;
          goto LAB_00039262;
        }
      }
    }
    else {
      iVar2 = (iVar3 - flash_ro_395a0) + -0x2400;
      if (iVar2 != 0) {
        iVar2 = iVar2 + flash_ro_395b0;
        if (iVar2 == 0) goto LAB_00039296;
        if ((iVar2 == 0x12e000) || (iVar2 == 0x12e001)) goto LAB_0003925e;
      }
    }
    uVar4 = *(uint *)(shared_ro_3958c + 0x1c) & 0xffff0fff;
  }
  *(uint *)(shared_ro_3958c + 0x1c) = uVar4;
  if ((param_1 != 0) && (param_1 < 3)) {
    *(uint *)((int)piVar6 + 0x1c) = *(uint *)((int)piVar6 + 0x1c) | param_2 << 10 | 0x200U;
    do {
    } while (*piVar6 < 0);
    iVar2 = flash_sub_391c0();
    if (iVar2 == *(int *)(puVar1 + 8)) {
      iVar2 = flash_ro_395c0;
      if ((param_1 == 1) || (iVar2 = flash_ro_395c4, param_1 == 2)) {
        *piVar6 = iVar2;
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
 * flash_sub_392b8   @ 0x000392b8   (118 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, flash_sub_3943c, flash_sub_39526, app_usb_upgrade_start, ... (+4 more)
 * calls     : flash_sub_391e2, flash_sub_391fc
 */

void flash_sub_392b8(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = flash_sub_391e2();
  iVar3 = *(int *)(flash_ro_3959c + 8);
  if (iVar3 == flash_ro_395a0) {
LAB_0003931e:
    if (iVar1 == 0xac) {
      return;
    }
    iVar3 = 0xac;
LAB_00039312:
    uVar2 = 2;
  }
  else {
    if (iVar3 < flash_ro_395a0) {
      if (iVar3 + shared_ro_395c8 != 0) {
        iVar3 = iVar3 + shared_ro_395c8 + flash_ro_395cc;
        if (iVar3 == 0) {
LAB_00039326:
          if (iVar1 == 0x2c) {
            return;
          }
          iVar3 = 0x2c;
        }
        else {
          iVar3 = iVar3 + flash_ro_395ac;
          if ((iVar3 != 0) && (iVar3 != 1)) goto LAB_000392fe;
          iVar3 = flash_ro_395d0;
          if (iVar1 == flash_ro_395d0) {
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
      iVar3 = (iVar3 - flash_ro_395a0) + -0x2400;
      if (iVar3 != 0) {
        iVar3 = iVar3 + flash_ro_395b0;
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
  flash_sub_391fc(uVar2,iVar3);
  return;
}

/* ==========================================================================
 * flash_sub_3932e   @ 0x0003932e   (118 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, flash_sub_3943c, flash_sub_39526, flash_erase, ... (+3 more)
 * calls     : flash_sub_391e2, flash_sub_391fc
 */

void flash_sub_3932e(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = flash_sub_391e2();
  iVar3 = *(int *)(flash_ro_3959c + 8);
  if (iVar3 == flash_ro_395a0) {
LAB_00039392:
    if (iVar1 == 0x94) {
      return;
    }
    uVar4 = 0x94;
LAB_00039398:
    uVar2 = 2;
  }
  else {
    if (iVar3 < flash_ro_395a0) {
      if (iVar3 + shared_ro_395c8 != 0) {
        iVar3 = iVar3 + shared_ro_395c8 + flash_ro_395cc;
        if (iVar3 == 0) {
LAB_0003939c:
          if (iVar1 == 0x10) {
            return;
          }
          uVar4 = 0x10;
        }
        else {
          iVar3 = iVar3 + flash_ro_395ac;
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
      iVar3 = (iVar3 - flash_ro_395a0) + -0x2400;
      if (iVar3 != 0) {
        iVar3 = iVar3 + flash_ro_395b0;
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
  flash_sub_391fc(uVar2,uVar4);
  return;
}

/* ==========================================================================
 * flash_mid   @ 0x000393a4   (24 bytes)
 * called by : ble_sub_39428
 * calls     : flash_sub_391c0, flash_sub_3932e, dbg_printf
 * string    : "flash_mid=%x\n"
 */

void flash_mid(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  uVar2 = flash_sub_391c0();
  puVar1 = flash_ro_3959c;
  *(undefined4 *)(flash_ro_3959c + 8) = uVar2;
  flash_sub_3932e();
  dbg_printf(str_flash_mid_x,*(undefined4 *)(puVar1 + 8));
  return;
}

/* ==========================================================================
 * flash_sub_3943c   @ 0x0003943c   (78 bytes)
 * called by : flash_sub_3976e
 * calls     : flash_sub_392b8, flash_sub_3932e, rom_25024, rom_25038, rom_2504C, rom_2505C
 */

void flash_sub_3943c(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = rom_25024();
  iVar3 = rom_25038();
  if ((flash_ro_3959c[4] == -0x55) && (flash_ro_3959c[5] == -0x44)) {
    flash_sub_392b8();
    puVar1 = shared_ro_3958c;
    do {
    } while (*(int *)shared_ro_3958c < 0);
    *(uint *)shared_ro_3958c = param_1 | 0x2d000000;
    do {
    } while (*(int *)puVar1 < 0);
    flash_sub_3932e();
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
 * flash_sub_39526   @ 0x00039526   (268 bytes)
 * called by : flash_sub_39708
 * calls     : flash_sub_392b8, flash_sub_3932e, ble_sub_3948a, rom_24FEC, rom_25024, rom_25038, ... (+2 more)
 */

void flash_sub_39526(undefined1 *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  uint local_48;
  undefined4 local_44;
  undefined1 auStack_40 [32];
  int local_20;
  int local_1c;
  
  local_48 = param_2 & 0xffffffe0;
  rom_24FEC(auStack_40,0x1c);
  local_44 = *(undefined4 *)flash_ro_395ec;
  if ((param_3 != 0) && (0x3ffff < param_2)) {
    local_1c = rom_25024();
    local_20 = rom_25038();
    puVar2 = shared_ro_3958c;
    do {
    } while (*(int *)shared_ro_3958c < 0);
    flash_ro_3959c[2] = 0xc2;
    flash_sub_392b8();
    while (param_3 != 0) {
      if (((param_2 & 0x1f) != 0) || (param_3 < 0x20)) {
        ble_sub_3948a(&local_44,local_48,0x20);
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
      shared_ro_3999c[3] = 0xd1;
      uVar4 = 0;
      do {
        *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(auStack_40 + uVar4 * 4 + -4);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 8);
      if ((*shared_ro_3999c == -0x5a) && (shared_ro_3999c[1] == -0x4d)) {
        do {
        } while (*(int *)puVar2 < 0);
        if (shared_ro_3999c[2] == -0x3e) {
          if (local_48 < 0x40000) {
            return;
          }
          *(uint *)puVar2 = local_48 | 0x2c000000;
        }
        do {
        } while (*(int *)puVar2 < 0);
      }
      local_48 = local_48 + 0x20;
    }
    flash_sub_3932e();
    *(undefined4 *)puVar2 = 0x7d000;
    puVar3 = shared_ro_3999c;
    shared_ro_3999c[2] = 0;
    puVar3[3] = 0;
    uVar4 = 0;
    do {
      *(undefined4 *)(puVar2 + 4) = 0xffffffff;
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
 * flash_sub_396da   @ 0x000396da   (46 bytes)
 * called by : Default_Profile, FLASH_RD_Global, FLASH_RD_Macro, FLASH_RD_Profile, FLASH_WR_Profile, FLASH_wr_Global, ... (+8 more)
 * calls     : ble_sub_3948a
 */

undefined4 flash_sub_396da(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_2 + param_3 & 0xffffff00;
  if ((param_2 & 0xffffff00) != uVar1) {
    ble_sub_3948a(param_4,param_2,uVar1 - param_2,param_4,param_4);
    param_3 = (param_2 + param_3) - uVar1;
    param_4 = param_4 + (uVar1 - param_2);
    param_2 = uVar1;
  }
  ble_sub_3948a(param_4,param_2,param_3);
  return 0;
}

/* ==========================================================================
 * flash_sub_39708   @ 0x00039708   (102 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, flash_sub_3e4ea, ble_sub_405ae, flash_erase, ... (+3 more)
 * calls     : flash_sub_391c0, flash_sub_39526, dbg_printf
 */

undefined4 flash_sub_39708(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = flash_sub_391c0();
  puVar1 = shared_ro_3999c;
  if (iVar2 == *(int *)(shared_ro_3999c + 8)) {
    *shared_ro_3999c = 0xa6;
    uVar4 = param_2 + param_3 & 0xffffff00;
    if ((param_2 & 0xffffff00) == uVar4) {
      puVar1[1] = 0xb3;
    }
    else {
      puVar1[1] = 0xb3;
      flash_sub_39526(param_4,param_2,uVar4 - param_2);
      param_3 = (param_2 + param_3) - uVar4;
      param_4 = param_4 + (uVar4 - param_2);
      param_2 = uVar4;
    }
    flash_sub_39526(param_4,param_2,param_3);
    uVar3 = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  else {
    uVar3 = flash_sub_391c0();
    dbg_printf(str_flash_0x_x + 1,uVar3);
    uVar3 = 0xff;
  }
  return uVar3;
}

/* ==========================================================================
 * flash_sub_3976e   @ 0x0003976e   (90 bytes)
 * called by : Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, flash_erase, flash_read, flash_write_some_data, ... (+1 more)
 * calls     : flash_sub_391c0, flash_sub_3943c
 */

undefined4 flash_sub_3976e(undefined4 param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = shared_ro_3999c;
  shared_ro_3999c[4] = 0xab;
  iVar2 = flash_sub_391c0();
  if (iVar2 != *(int *)(puVar1 + 8)) {
    return 0xff;
  }
  param_2 = param_2 & 0xfffff000;
  puVar1[5] = 0xbc;
  for (iVar2 = 0;
      iVar2 < (int)((uint)(0 < param_3 % 0x1000) +
                   ((int)(((uint)(param_3 >> 0x1f) >> 0x14) + param_3) >> 0xc)); iVar2 = iVar2 + 1)
  {
    flash_sub_3943c(param_2);
    param_2 = param_2 + 0x1000;
  }
  puVar1[4] = 0;
  puVar1[5] = 0;
  return 0;
}

/* ==========================================================================
 * flash_write_some_data   @ 0x000397c8   (146 bytes)
 * called by : app_usb_upgrade_start, write
 * calls     : flash_sub_392b8, flash_sub_3932e, flash_sub_396da, flash_sub_39708, flash_sub_3976e, dbg_printf, ... (+2 more)
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
  flash_sub_392b8();
  flash_sub_396da(0,param_2 & 0xfffffc00,0x400,auStack_424,0);
  dbg_printf_2(str_back_flash_read,auStack_424,0x10);
  flash_sub_3976e(0,param_2,0x1000);
  dbg_printf(str_flash_erase);
  puVar1 = auStack_424 + (param_2 & 0x3ff);
  rom_24F9C(puVar1,local_20,local_18);
  dbg_printf_2(str_memcpy,puVar1,0x10);
  flash_sub_39708(0,param_2 & 0xfffffc00,0x400,auStack_424,0);
  dbg_printf_2(str_flash_write,puVar1,0x80);
  flash_sub_3932e();
  dbg_printf(str_flash_wp_ALL_2);
  return;
}

/* ==========================================================================
 * flash_read   @ 0x0003985a   (128 bytes)
 * calls     : flash_sub_392b8, flash_sub_3932e, flash_sub_396da, flash_sub_39708, flash_sub_3976e, dbg_printf, ... (+1 more)
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
  
  iVar1 = flash_ro_39a24;
  iVar2 = flash_ro_39a24 + -0x20;
  puVar3 = (undefined4 *)((int)&local_20 + flash_ro_39a24);
  puVar4 = (undefined4 *)((int)&local_20 + flash_ro_39a24);
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  dbg_printf(str_flash_wp_256k);
  flash_sub_392b8();
  dbg_printf(str_flash_read);
  iVar1 = (int)&uStack_1c + iVar1;
  *puVar3 = 0;
  flash_sub_396da(0,param_2 & 0xfffff000,0x1000,iVar1);
  dbg_printf(str_flash_read);
  iVar2 = flash_ro_39a48 + iVar2;
  rom_24F9C((param_2 & 0xfff) + iVar1,*(undefined4 *)((int)&local_18 + iVar2 + 0x20),
            *(undefined4 *)(&stack0xfffffff0 + iVar2 + 0x20));
  flash_sub_3976e(0,param_2,flash_ro_39a48);
  dbg_printf(str_flash_erase);
  *puVar4 = 0;
  flash_sub_39708(0,param_2 & 0xfffff000,flash_ro_39a48,iVar1);
  dbg_printf(str_flash_write_2);
  flash_sub_3932e();
  dbg_printf(str_flash_wp_ALL_2);
  return;
}

/* ==========================================================================
 * r_temp1   @ 0x000398da   (194 bytes)
 * calls     : flash_sub_392b8, flash_sub_396da, flash_sub_39708, flash_sub_3976e, dbg_printf
 * string    : "flash_test\n "
 * string    : "r_temp1: "
 */

void r_temp1(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_214 [256];
  undefined1 local_114 [256];
  
  flash_sub_392b8();
  dbg_printf(str_flash_test);
  uVar1 = flash_ro_39a6c;
  flash_sub_396da(0,flash_ro_39a6c,0xff,local_214,0);
  dbg_printf(str_r_temp1);
  iVar2 = 0;
  do {
    dbg_printf(&flash_ro_39a7c,local_214[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  dbg_printf(&flash_ro_39a80);
  iVar2 = 0;
  do {
    local_114[iVar2] = (char)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  flash_sub_39708(0,uVar1,0xff,local_114,0);
  flash_sub_396da(0,uVar1,0xff,local_214,0);
  dbg_printf(str_r_temp1);
  iVar2 = 0;
  do {
    dbg_printf(&flash_ro_39a7c,local_214[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  dbg_printf(&flash_ro_39a80);
  flash_sub_3976e(0,uVar1,flash_ro_39a48);
  flash_sub_396da(0,uVar1,0xff,local_214,0);
  dbg_printf(str_r_temp1);
  iVar2 = 0;
  do {
    dbg_printf(&flash_ro_39a7c,local_214[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  dbg_printf(&flash_ro_39a80);
  return;
}

/* ==========================================================================
 * flash_sub_3c2c6   @ 0x0003c2c6   (30 bytes)
 * called by : Default_Profile, flash_sub_31808, power_sub_35c9c, SLEEP, _saveC_GM_ProfileMax, exist, ... (+2 more)
 * calls     : usb_sub_3c21e, usb_sub_3c286
 */

void flash_sub_3c2c6(void)

{
  undefined4 uVar1;
  
  usb_sub_3c286(1);
  uVar1 = flash_ro_3c4f8;
  if (flash_ro_3c4f0[0x16] != '\x01') {
    uVar1 = flash_ro_3c4f4;
  }
  usb_sub_3c21e(1,uVar1);
  return;
}

/* ==========================================================================
 * flash_sub_3c8b6   @ 0x0003c8b6   (38 bytes)
 * called by : BLE_PAIR, OLED_Init, Success_led_2second_2, enter_BLE_normal_app_mode, set_USB_led_flash, set_bonded_led_flash, ... (+1 more)
 * calls     : usb_sub_3b54e, usb_sub_3c818, led_sub_3c896
 */

void flash_sub_3c8b6(void)

{
  undefined *puVar1;
  uint uVar2;
  
  usb_sub_3c818();
  usb_sub_3b54e();
  puVar1 = flash_ro_3cc1c;
  uVar2 = 0;
  do {
    led_sub_3c896(puVar1[uVar2]);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x1b);
  led_sub_3c896(0xaf);
  return;
}

/* ==========================================================================
 * flash_sub_3cf7c   @ 0x0003cf7c   (60 bytes)
 * called by : BLE_PAIR, Default_Profile, Detect_FULL_IN, ble_sub_2b8a2, usb_sub_3d2b0, OLED_Init, ... (+8 more)
 * calls     : usb_sub_3cdb6, input_sub_3ce00, led_sub_3ce52, usb_sub_3ce5c, usb_sub_3cf24, delta_none
 */

void flash_sub_3cf7c(void)

{
  usb_sub_3cf24();
  usb_sub_3ce5c();
  led_sub_3ce52();
  input_sub_3ce00();
  usb_sub_3cdb6();
  *flash_ro_3d194 = 0;
  *flash_ro_3d198 = 0;
  *flash_ro_3d19c = 0;
  *flash_ro_3d1a0 = 0;
  *flash_ro_3d1a4 = 0;
  if (*shared_ro_3d0b4 != '\0') {
    *shared_ro_3d0b4 = 0;
    delta_none();
  }
  return;
}

/* ==========================================================================
 * flash_sub_3e4d2   @ 0x0003e4d2   (24 bytes)
 * called by : ble_sub_3e516
 * calls     : flash_sub_396da
 */

void flash_sub_3e4d2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  flash_sub_396da(ble_ro_3e794[0x14],param_1,param_2,param_3,0);
  return;
}

/* ==========================================================================
 * flash_sub_3e4ea   @ 0x0003e4ea   (24 bytes)
 * calls     : flash_sub_39708
 */

void flash_sub_3e4ea(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  flash_sub_39708(ble_ro_3e794[0x14],param_1,param_2,param_3,0);
  return;
}
