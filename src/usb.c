/* USB and HID
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * usb_sub_29464   @ 0x00029464   (44 bytes)
 * called by : gpio
 * calls     : rom_06EF4, rom_06F26
 */

void usb_sub_29464(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(shared_ro_297c8,7,3,0x3a);
  puVar1 = shared_ro_2977c;
  *puVar2 = 0xa4;
  puVar2[1] = puVar1[3];
  *(short *)(puVar2 + 2) = (short)usb_ro_297cc;
  puVar2[4] = 0;
  rom_06F26();
  puVar1[4] = 5;
  puVar1[5] = 0xa4;
  return;
}

/* ==========================================================================
 * usb_sub_2b18e   @ 0x0002b18e   (70 bytes)
 * called by : usb_sub_3cf24, f_usb_isConnected
 * calls     : rom_071EA
 */

undefined4 usb_sub_2b18e(void)

{
  char cVar1;
  int iVar2;
  
  if ((*usb_ro_2b548 != '\0') && (*shared_ro_2b520 != '\0')) {
    return 1;
  }
  cVar1 = *shared_ro_2b54c;
  if (cVar1 == '\0') {
    if (*usb_ro_2b550 == '\0') {
      return 1;
    }
  }
  else if ((((cVar1 == '\x01') || (cVar1 == '\x02')) && (*shared_ro_2b520 == '\0')) &&
          (iVar2 = rom_071EA(3), iVar2 == 3)) {
    return 1;
  }
  return 0;
}

/* ==========================================================================
 * usb_sub_2b382   @ 0x0002b382   (42 bytes)
 * called by : ble_sub_2b4c8, exist, gpio
 */

void usb_sub_2b382(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  *(uint *)shared_ro_2b654 = *(uint *)shared_ro_2b654 & ~((int)shared_ro_2b654 >> 0xe);
  puVar1 = shared_ro_2b524;
  puVar2 = (undefined4 *)(shared_ro_2b524 + 0x80);
  *(undefined4 *)(shared_ro_2b524 + 0x8c) = 0;
  *(undefined4 *)(shared_ro_2b638 + 0xc) = *(undefined4 *)(puVar1 + 0x8c);
  *puVar2 = 0;
  *(undefined4 *)(puVar1 + 0x84) = 0;
  *(undefined4 *)(puVar1 + 0x94) = 0xffffffff;
  puVar1 = shared_ro_2b524;
  *(undefined4 *)(shared_ro_2b524 + 0x18) = 0xc;
  *(undefined4 *)(puVar1 + 0x1c) = 0xc;
  return;
}

/* ==========================================================================
 * gpio   @ 0x0002b3c2   (208 bytes)
 * calls     : usb_sub_29464, usb_sub_2b382, ble_sub_2b3ac, usb_sub_317c2, power_sub_33cfe, usb_sub_3c6a8, ... (+6 more)
 * string    : "gpio int1\r\n"
 * string    : "adv start =%d\r\n"
 */

void gpio(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  
  dbg_printf(str_gpio_int1);
  *shared_ro_2b544 = 1;
  puVar3 = shared_ro_2b590;
  if (*shared_ro_2b590 != '\0') {
    iVar5 = get_usb_insert_status();
    puVar1 = usb_ro_2b548;
    *usb_ro_2b548 = iVar5 != 0;
    if (*puVar1 != '\0') {
      *usb_ro_2b678 = 0;
      *puVar3 = 0;
      OLED_Init();
    }
  }
  *(undefined4 *)usb_ro_2b67c = *(undefined4 *)(shared_ro_2b524 + 0x94);
  *shared_ro_2b530 = 0xf;
  if (((*shared_ro_2b54c == '\x01') || (*shared_ro_2b54c == '\x02')) && (*shared_ro_2b520 == '\0')) {
    usb_sub_2b382();
    power_sub_33cfe();
    puVar1 = shared_ro_2b598;
    puVar3 = shared_ro_2b588;
    shared_ro_2b598[0xb] = 1;
    *puVar3 = 0;
    *usb_ro_2b680 = 0;
    usb_sub_3c6a8();
    ble_sub_2b3ac();
    puVar3 = shared_ro_2b59c;
    if ((shared_ro_2b59c[4] == '\x04') && (iVar5 = rom_071EA(3), puVar4 = usb_ro_2b684, iVar5 == 2)) {
      puVar1[4] = puVar1[4] | 2;
      *puVar4 = 4;
      usb_sub_317c2(2);
      dbg_printf(str_adv_start_d,puVar3[4]);
      usb_sub_29464();
    }
    uVar2 = shared_ro_2b564;
    iVar5 = rom_07434(shared_ro_2b564,3);
    if (iVar5 == 0) {
      rom_06F58(uVar2,3);
      return;
    }
  }
  else {
    *shared_ro_2b570 = 0;
    usb_sub_2b382();
  }
  return;
}

/* ==========================================================================
 * usb_sub_2bd62   @ 0x0002bd62   (98 bytes)
 * called by : ble_sub_2f31c
 * calls     : rom_071EA, rom_24FEC, update
 */

void usb_sub_2bd62(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = usb_ro_2be6c;
  puVar1 = shared_ro_2be68;
  if ((((shared_ro_2be68[3] != '\0') && (*usb_ro_2be6c == '\0')) && (iVar3 = rom_071EA(3), iVar3 == 3)) &&
     (usb_ro_2be70[4] == '\x03')) {
    *puVar2 = 1;
    puVar2 = usb_ro_2be74;
    update(usb_ro_2be74 + (uint)(byte)puVar1[2] * 8,puVar1[(byte)puVar1[2] + 0x18]);
    rom_24FEC(puVar2 + (uint)(byte)puVar1[2] * 8,8);
    puVar1[2] = puVar1[2] + 1 & 7;
    puVar1[3] = puVar1[3] + -1;
    if (puVar1[10] != '\0') {
      puVar1[10] = puVar1[10] + -1;
    }
  }
  return;
}

/* ==========================================================================
 * app_hid_enable_prf   @ 0x0002c41a   (60 bytes)
 * called by : ble_update_param_failed_cnt
 * calls     : ble_sub_3ee6e, dbg_printf, rom_06EF4, rom_06F26
 * string    : "app_hid_enable_prf"
 * string    : "%s conidx =d%\r\n"
 */

void app_hid_enable_prf(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  puVar2 = shared_ro_2c784;
  puVar1 = shared_ro_2c77c;
  *shared_ro_2c77c = (char)param_1;
  dbg_printf(str_s_conidx_d,puVar2 + 0x11,param_1);
  uVar3 = ble_sub_3ee6e(0x26);
  puVar4 = (undefined1 *)rom_06EF4(&rom_ro_2600,uVar3,3,6);
  *puVar4 = (char)param_1;
  puVar1[4] = 3;
  *(short *)(puVar4 + param_1 * 2 + 2) = (short)usb_ro_2c7a0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * update   @ 0x0002c456   (400 bytes)
 * called by : usb_sub_2bd62
 * calls     : ble_sub_3ee6e, appm_update_param, dbg_printf, rom_06EF4, rom_06F26, rom_06F80, ... (+1 more)
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
  
  puVar4 = shared_ro_2c77c;
  cVar1 = shared_ro_2c77c[4];
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
  uVar5 = ble_sub_3ee6e(0x26);
  puVar6 = (undefined1 *)rom_06EF4(shared_ro_2c7d4,uVar5,3,0x24);
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
 * APP_PARAM_UPDATE_REQ_IND_3   @ 0x0002e958   (24 bytes)
 * calls     : dbg_printf, rom_07342
 * string    : "APP_PARAM_UPDATE_REQ_IND--9 hid not ready,   app_update_conn_param_.............%d,%d \r\n"
 */

undefined4
APP_PARAM_UPDATE_REQ_IND_3
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  dbg_printf(usb_ro_2ed18,*param_4,*param_1);
  rom_07342(shared_ro_2ed1c,3,100);
  return 0;
}

/* ==========================================================================
 * usb_sub_30094   @ 0x00030094   (74 bytes)
 * called by : system_mode
 * calls     : usb_sub_369a0, usb_sub_369d8, rom_25078
 */

undefined8 usb_sub_30094(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar1 = shared_ro_301f0;
  uVar2 = (uint)(byte)*shared_ro_301f0;
  if ((*usb_ro_30238 == '\0') && (4 < uVar2)) {
    usb_sub_369a0();
    puVar4 = shared_ro_301f8;
    *(undefined4 *)(shared_ro_301f8 + -0x28) = 0xa0;
    *(undefined4 *)(puVar4 + -0x28) = 0x80;
    usb_sub_369d8();
    puVar4 = shared_ro_30174;
    iVar3 = 0;
    *shared_ro_30174 = 0;
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
 * usb_sub_31230   @ 0x00031230   (20 bytes)
 * called by : ble_sub_31334, ble_sub_31406, exist
 */

void usb_sub_31230(void)

{
  *(undefined2 *)shared_ro_3156c = 0;
  *(undefined2 *)shared_ro_31570 = 0;
  *(undefined2 *)shared_ro_31574 = 0;
  *(undefined2 *)shared_ro_31578 = 0;
  return;
}

/* ==========================================================================
 * usb_sub_312de   @ 0x000312de   (86 bytes)
 * called by : ble_sub_31334, ble_sub_31406, exist, f_usb_isConnected
 * calls     : rom_24FEC
 */

void usb_sub_312de(void)

{
  *usb_ro_315b0 = 0;
  *usb_ro_315b4 = 0;
  *usb_ro_315b8 = 0;
  *usb_ro_315bc = 0;
  *shared_ro_315c0 = 0;
  rom_24FEC(usb_ro_315c4,0xc);
  rom_24FEC(shared_ro_315c8,0x20);
  rom_24FEC(usb_ro_315cc,0x40);
  rom_24FEC(usb_ro_315d0,8);
  rom_24FEC(usb_ro_315d4,0x10);
  rom_24FEC(usb_ro_315d8,5);
  rom_24FEC(shared_ro_315dc,4);
  *usb_ro_315e0 = 0;
  return;
}

/* ==========================================================================
 * usb_sub_317c2   @ 0x000317c2   (40 bytes)
 * called by : input_sub_34414, usb_sub_345d2, ble_sub_35cd2, usb_sub_39dfe, usb_sub_3c818, LightUp_Mode_Led, ... (+13 more)
 * calls     : usb_sub_3b54e
 */

void usb_sub_317c2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = usb_ro_31804;
  if (*shared_ro_31800 == '\x05') {
    param_1 = param_1 << 2;
  }
  for (iVar3 = 0; iVar3 < param_1; iVar3 = iVar3 + 1) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
    usb_sub_3b54e();
  }
  return;
}

/* ==========================================================================
 * usb_sub_3236a   @ 0x0003236a   (94 bytes)
 * called by : system_mode
 * calls     : ble_sub_319c0, ble_sub_31b3e, ble_sub_332be
 */

void usb_sub_3236a(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = usb_ro_325a8;
  puVar1 = usb_ro_325a4;
  if (*shared_ro_32598 == '\0') {
    if (*usb_ro_325a0 != '\0') {
      return;
    }
  }
  else if (*usb_ro_3259c == '\0') {
    return;
  }
  uVar4 = 0;
  do {
    if ((int)((uint)(byte)puVar2[uVar4] << 0x1e) < 0) {
      if ((puVar2[uVar4] & 1) == 0) {
        ble_sub_319c0(uVar4);
      }
      else if ((*puVar1 == '\x02') || (iVar3 = ble_sub_332be(), iVar3 != 0)) {
        ble_sub_31b3e(uVar4);
      }
      else {
        puVar2[uVar4] = puVar2[uVar4] & 0xfd;
      }
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0xc);
  return;
}

/* ==========================================================================
 * usb_sub_323c8   @ 0x000323c8   (38 bytes)
 * called by : usb_sub_323ee
 */

undefined4 usb_sub_323c8(uint param_1)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    if ((byte)usb_ro_325ac[uVar1] == 0) {
      usb_ro_325ac[uVar1] = (char)param_1;
      return 1;
    }
  } while (((byte)usb_ro_325ac[uVar1] != param_1) && (uVar1 = uVar1 + 1 & 0xff, uVar1 < 7));
  return 0;
}

/* ==========================================================================
 * usb_sub_323ee   @ 0x000323ee   (66 bytes)
 * called by : system_mode
 * calls     : usb_sub_323c8
 */

void usb_sub_323ee(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  int iVar5;
  
  puVar3 = usb_ro_325b4;
  puVar2 = usb_ro_325b0;
  cVar1 = *usb_ro_325b0;
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      *usb_ro_325ac = *usb_ro_325ac | *usb_ro_325bc;
      *puVar3 = 1;
      uVar4 = 2;
    }
    else {
      if (cVar1 != '\x02') {
        return;
      }
      if (*usb_ro_325b4 != '\0') {
        return;
      }
      iVar5 = usb_sub_323c8(*usb_ro_325b8);
      if (iVar5 != 0) {
        *puVar3 = 1;
      }
      uVar4 = 0;
    }
    *puVar2 = uVar4;
  }
  return;
}

/* ==========================================================================
 * usb_sub_32430   @ 0x00032430   (116 bytes)
 * called by : system_mode
 */

void usb_sub_32430(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined1 uVar7;
  
  puVar5 = usb_ro_325c0;
  cVar1 = *usb_ro_325c0;
  if (cVar1 != '\0') {
    *usb_ro_325c4 = 0xf;
    puVar6 = usb_ro_325cc;
    uVar2 = *usb_ro_325c8;
    cVar3 = *usb_ro_325d0;
    bVar4 = *usb_ro_325cc;
    uVar7 = 1;
    if (cVar1 == '\x01') {
      if (cVar3 == '\0') {
        *usb_ro_325d0 = uVar2;
        *puVar6 = bVar4 | 1;
        *usb_ro_32590 = 1;
        uVar7 = 2;
LAB_000324a0:
        *puVar5 = uVar7;
        return;
      }
    }
    else if (cVar1 == '\x02') {
      if (cVar3 == '\0') {
        *usb_ro_325d0 = uVar2;
        *puVar6 = bVar4 & 0xfe;
        *usb_ro_32590 = 1;
        cVar1 = *usb_ro_325d4;
        if ((cVar1 == '\0') || (*usb_ro_325d4 = cVar1 + -1, cVar1 == '\x01')) {
          uVar7 = 0;
        }
        goto LAB_000324a0;
      }
    }
    else if ((cVar1 == '\x05') && (cVar3 == '\0')) {
      *usb_ro_325d0 = uVar2;
      *puVar6 = bVar4 ^ 1;
      *usb_ro_32590 = 1;
    }
  }
  return;
}

/* ==========================================================================
 * usb_sub_32614   @ 0x00032614   (12 bytes)
 * called by : Set_SIMU_mode_LightUp_Led
 */

void usb_sub_32614(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_329e8;
  *(undefined4 *)(shared_ro_329e8 + 0x28) = 0;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *(undefined4 *)(puVar1 + 0x20) = 0;
  return;
}

/* ==========================================================================
 * Set_SIMU_mode_LightUp_Led   @ 0x0003271a   (76 bytes)
 * called by : Disconnected, app_mutli_link_change
 * calls     : usb_sub_32614, flash_sub_32658, dbg_printf
 * string    : "usb to 24 mode \r\n"
 * string    : "Set_SIMU_mode_LightUp_Led"
 * string    : "%s, Simu_RF_MODE=%x,Mode_Indicator_BIT=%x\r\n"
 */

void Set_SIMU_mode_LightUp_Led(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
  puVar1 = shared_ro_329e4;
  *shared_ro_329e4 = 0;
  puVar2 = shared_ro_329f4;
  if (*shared_ro_329ec == '\0') {
    uVar3 = 2;
    if (*shared_ro_329f4 == '\x01') {
      *shared_ro_329f4 = 2;
      uVar3 = 4;
    }
    else {
      if (*shared_ro_329f4 != '\x02') goto LAB_00032752;
      *shared_ro_329f4 = 1;
    }
    *puVar1 = uVar3;
  }
  else {
    dbg_printf(str_usb_to_24_mode);
    usb_sub_32614();
  }
LAB_00032752:
  flash_sub_32658();
  dbg_printf(str_s_Simu_RF_MODE_x_Mode_Indicator_BIT_x,str_Set_SIMU_mode_LightUp_Led,*puVar2,*puVar1);
  return;
}

/* ==========================================================================
 * usb_sub_3300e   @ 0x0003300e   (180 bytes)
 * called by : system_mode
 * calls     : rom_071EA, rom_25078
 */

void usb_sub_3300e(void)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_r3;
  
  puVar2 = shared_ro_33368;
  if ((((*shared_ro_33368 == '\0') || (*usb_ro_3336c == '\0')) ||
      ((((cVar1 = *usb_ro_3335c, cVar1 == '\0' && (*usb_ro_33370 == '\0')) &&
        ((1 < (byte)*usb_ro_33374 || (*usb_ro_33378 != '\0')))) ||
       ((*usb_ro_3337c != '\0' &&
        ((*shared_ro_33360 != '\0' &&
         ((((*shared_ro_33380 != '\0' || (*usb_ro_33384 != '\0')) || (*shared_ro_33388 != '\0')) ||
          ((*usb_ro_3338c != '\0' || (*usb_ro_33390 != '\0')))))))))))) ||
     (((cVar1 == '\x01' || (cVar1 == '\x02')) &&
      (((*shared_ro_33360 == '\0' && (iVar3 = rom_071EA(3), iVar3 == 3)) &&
       (*usb_ro_33394 != '\0' || *usb_ro_33398 != '\0')))))) {
    return;
  }
  if (*(short *)shared_ro_33364 != 0) {
    *(short *)shared_ro_33364 = *(short *)shared_ro_33364 + -1;
  }
  uVar4 = rom_25078(usb_ro_333a0,usb_ro_3339c,*puVar2,*puVar2,in_r3);
  *(undefined2 *)shared_ro_32b04 = 400;
  if ((uVar4 & 1) == 0) {
    ble_sub_32620();
    led_sub_3ce52();
    return;
  }
  flash_sub_32658();
  if (*led_ro_32b08 == '\x02') {
    ReLinking();
    return;
  }
  Pairing();
  return;
}

/* ==========================================================================
 * Set_Report_Data   @ 0x0003353c   (192 bytes)
 * called by : usb_sub_33a7e, RPT_STEP
 * calls     : FLASH_RD_Profile, usb_sub_33d2a, OLED_Init, dbg_printf, dbg_printf_2, rom_24FEC, ... (+1 more)
 * string    : "Set_Report_Data"
 * string    : "N0N0 report_id =%x\r\n"
 * string    : "macro report_id =%x,macro_index=%x\r\n"
 * string    : "Profile report_id =%x,Update_Profile=%x,%x\r\n"
 */

void Set_Report_Data(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  char *pcVar5;
  int iVar6;
  undefined8 uVar7;
  
  OLED_Init();
  puVar2 = shared_ro_337dc;
  dbg_printf_2(str_Set_Report_Data,*(undefined4 *)(shared_ro_337dc + 4),0x20);
  puVar4 = usb_ro_33888;
  puVar3 = shared_ro_33810;
  cVar1 = puVar2[2];
  if (cVar1 == '\t') goto LAB_0003359a;
  if ((((cVar1 == '\x06') || (cVar1 == '\x04')) || (cVar1 == '\x05')) || (cVar1 == '\b')) {
    pcVar5 = *(char **)(puVar2 + 4);
    *shared_ro_33810 = *pcVar5 + -1;
    *(char **)(puVar2 + 4) = pcVar5 + 1;
    dbg_printf(str_Profile_report_id_x_Update_Profile_x_x);
    if (puVar2[2] != '\x06') {
      if (shared_ro_337e4[0xc] != *puVar3) {
        FLASH_RD_Profile();
      }
    }
  }
  else {
    dbg_printf(str_N0N0_report_id_x);
  }
  do {
    rom_24FEC(shared_ro_337e0,0xff);
    iVar6 = 0x3358b;
    uVar7 = rom_25078();
    (*(code *)(iVar6 + 0x7a0))((int)uVar7,(int)((ulonglong)uVar7 >> 0x20) + -0xd);
    func_0xffb2af7e();
LAB_0003359a:
    pcVar5 = *(char **)(puVar2 + 4);
    *usb_ro_338a8 = *pcVar5 + -1;
    *(char **)(puVar2 + 4) = pcVar5 + 1;
    if ((*puVar4 == '\0') || ((*usb_ro_338ac != '\0' && (*usb_ro_338b0 != '\0')))) {
      *(char **)(puVar2 + 4) = pcVar5 + 2;
    }
    dbg_printf(str_macro_report_id_x_macro_index_x);
  } while( true );
}

/* ==========================================================================
 * usb_sub_33a7e   @ 0x00033a7e   (172 bytes)
 * called by : system_mode
 * calls     : Set_Report_Data, app_usb_upgrade_start, rom_25078
 */

void usb_sub_33a7e(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 extraout_r1;
  uint uVar6;
  undefined4 in_r3;
  undefined *puVar7;
  
  puVar2 = usb_ro_33c40;
  if (*usb_ro_33c3c != '\0') {
    uVar6 = (uint)(byte)*usb_ro_33c44;
    iVar5 = rom_25078(*usb_ro_33c48,usb_ro_33c4c[2],uVar6,*usb_ro_33c40,in_r3);
    *(undefined **)(iVar5 + 0x34) = puVar2;
    rom_ro_6 = extraout_r1;
    if (*usb_ro_33c50 != '\0') {
      *usb_ro_33c50 = 0;
      puVar7 = usb_ro_33c54;
      puVar3 = usb_ro_33c4c;
      if (usb_ro_33c4c[9] != '\x10') {
        puVar7 = usb_ro_33c4c + 0xb;
        if (usb_ro_33c4c[1] == '\x02') {
          *usb_ro_33c5c = 0;
          puVar3[9] = extraout_r1;
          puVar3[10] = *usb_ro_33c60;
          puVar3[0xb] = (char)uVar6;
          if (uVar6 != 0) {
            *(undefined **)(puVar3 + 4) = usb_ro_33c4c + 0xc;
            *puVar2 = 1;
            return;
          }
          *usb_ro_33c64 = 0;
          *usb_ro_33c68 = 0;
          *(undefined **)(puVar3 + 4) = puVar7;
          uVar4 = 3;
        }
        else {
          if (usb_ro_33c4c[1] != '\x01') {
            return;
          }
          usb_ro_33c4c[2] = usb_ro_33c4c[9];
          *(undefined **)(puVar3 + 4) = puVar7;
          Set_Report_Data();
          uVar4 = 5;
        }
        *puVar2 = uVar4;
        return;
      }
      if (usb_ro_33c4c[0xb] == -0x6a) {
        cVar1 = *usb_ro_33c54;
        *usb_ro_33c54 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\t') {
          *puVar7 = 1;
        }
        *usb_ro_33c58 = 1;
        return;
      }
      app_usb_upgrade_start();
    }
  }
  return;
}

/* ==========================================================================
 * usb_sub_33d2a   @ 0x00033d2a   (1 bytes)
 * called by : Set_Report_Data
 */

void usb_sub_33d2a(void)

{
  return;
}

/* ==========================================================================
 * usb_sub_33d2c   @ 0x00033d2c   (64 bytes)
 * called by : rf24_sub_342b4, rf24_sub_34352, input_sub_34426, f_usb_isConnected
 * calls     : rf24_sub_31784, rf24_sub_3aa1a, usb_sub_3aa42
 */

undefined1 usb_sub_33d2c(byte param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_33f70;
  *(undefined4 *)(shared_ro_33f70 + 0x1c) = 0;
  *shared_ro_33f74 = param_1 & 0x7f;
  rf24_sub_3aa1a(shared_ro_33f74,1);
  rf24_sub_31784(3);
  usb_sub_3aa42(shared_ro_33f74 + 0xc,1);
  rf24_sub_31784(1);
  *(undefined4 *)(puVar1 + 0x1c) = 2;
  rf24_sub_31784(5);
  return shared_ro_33f74[0xc];
}

/* ==========================================================================
 * single_wave   @ 0x00034044   (184 bytes)
 * called by : system_mode
 * calls     : usb_sub_361a8, usb_sub_369a0, usb_sub_369ac, usb_sub_369d8, usb_sub_36eee, dbg_printf, ... (+1 more)
 * string    : "single_wave 123============== %x,%x,%x,%x,%x,\r\n"
 */

void single_wave(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 uVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  
  puVar3 = usb_ro_34224;
  puVar2 = usb_ro_34220;
  cVar1 = *usb_ro_34220;
  if (((cVar1 != '\0') && (*usb_ro_34228 != '\0')) && (*usb_ro_34228 = 0, *(short *)usb_ro_3422c == 4)) {
    *puVar2 = cVar1 + '\x01';
    if (cVar1 == '\b') {
      *puVar2 = 1;
    }
    *puVar3 = 1;
  }
  puVar2 = usb_ro_34230;
  uVar6 = (uint)(byte)*usb_ro_34220;
  uVar8 = rom_25078();
  pcVar5 = (char *)((int)uVar8 + -0x3e);
  puVar7 = (undefined1 *)((int)puVar2 * 2);
  if (*pcVar5 == '\0') {
    return;
  }
  *pcVar5 = (char)*(undefined4 *)((int)((ulonglong)uVar8 >> 0x20) + 0x40);
  puVar3 = usb_ro_34220;
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
  usb_sub_36eee(8);
  usb_sub_369ac();
  usb_sub_369a0();
  *(int *)(puVar2 + 0x18) = (int)uVar8 << 0x18;
  *(undefined4 *)(puVar2 + 0x18) = 0x80;
  *(undefined4 *)(usb_ro_34230 + -0xb0) = 3;
  usb_sub_36eee(8);
  usb_sub_369d8();
  usb_sub_361a8(*puVar7);
  dbg_printf(str_single_wave_123_x_x_x_x_x,*usb_ro_34240,*puVar3,*puVar7,*usb_ro_3423c,*usb_ro_34238);
  return;
}

/* ==========================================================================
 * usb_sub_345d2   @ 0x000345d2   (58 bytes)
 * called by : f_usb_isConnected, sensor_init
 * calls     : usb_sub_317c2, rf24_sub_342b4, rf24_sub_34352, rf24_sub_34408, rf24_sub_34538
 */

void usb_sub_345d2(void)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  usb_sub_317c2(0x3c);
  puVar1 = shared_ro_34618;
  *(undefined4 *)(shared_ro_34618 + 0x1c) = 2;
  usb_sub_317c2(1);
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  rf24_sub_34408();
  usb_sub_317c2(5);
  rf24_sub_34352();
  uVar2 = 0;
  if (*usb_ro_34638 != '\0') {
    uVar2 = 3;
  }
  rf24_sub_342b4(uVar2);
  rf24_sub_34538();
  return;
}

/* ==========================================================================
 * usb_sub_34e4c   @ 0x00034e4c   (2 bytes)
 * called by : system_mode
 */

void usb_sub_34e4c(void)

{
  return;
}

/* ==========================================================================
 * Detect_FULL_IN   @ 0x00034eea   (166 bytes)
 * called by : system_mode
 * calls     : Charging, flash_sub_3cf7c, OLED_Init, dbg_printf
 * string    : "Detect_FULL_IN ==FULL !\r\n"
 * string    : "Detect_FULL_IN ==CHANRGing !\r\n"
 */

void Detect_FULL_IN(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  puVar2 = shared_ro_3502c;
  if (((*shared_ro_35024 != '\0') &&
      (*(undefined4 *)(shared_ro_3502c + 0x30) = 0x2c, (*(uint *)(puVar2 + 0x30) & 1) != 0)) &&
     (usb_ro_35190[2] == '\0')) {
    OLED_Init();
    puVar5 = usb_ro_35198;
    puVar4 = usb_ro_35194;
    puVar3 = shared_ro_35070;
    if (((*(uint *)(puVar2 + 0x14) & 1) == 0) || (*usb_ro_35194 != '\0')) {
      if (((*(uint *)(puVar2 + 0x14) & 1) == 0) && (*usb_ro_35194 == '\x01')) {
        cVar1 = *usb_ro_35198;
        *usb_ro_35198 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          *puVar5 = 0xf;
          *puVar4 = 0;
          flash_sub_3cf7c();
          dbg_printf(str_Detect_FULL_IN_CHANRGing);
          *(undefined2 *)usb_ro_351dc = 400;
          *usb_ro_351e0 = 0xf;
          OLED_Init();
          return;
        }
      }
      else {
        *usb_ro_35198 = 0xf;
      }
      return;
    }
    cVar1 = *usb_ro_35198;
    *usb_ro_35198 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      *puVar4 = 1;
      *puVar5 = 0xf;
      if (*puVar3 != '\x02') {
        Charging();
        puVar2 = usb_ro_3519c;
        *puVar3 = 2;
        *puVar2 = 0x14;
        dbg_printf(str_Detect_FULL_IN_FULL);
      }
    }
  }
  return;
}

/* ==========================================================================
 * f_usb_isConnected   @ 0x00034f90   (1122 bytes)
 * called by : system_mode
 * calls     : CHRG, ble_sub_295aa, usb_sub_2b18e, ble_sub_312aa, usb_sub_312de, rf24_sub_31784, ... (+26 more)
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
  undefined1 uVar3;
  short sVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  undefined2 uVar12;
  byte bVar13;
  
  puVar7 = usb_ro_35604;
  puVar6 = usb_ro_351e4;
  puVar5 = shared_ro_3514c;
  if (usb_ro_35190[2] == '\0') {
    *(undefined4 *)(usb_ro_35604 + 0x30) = 0x2c;
    rf24_sub_31784(3);
    puVar8 = usb_ro_3560c;
    uVar10 = *(uint *)(puVar7 + 0x30);
    if ((uVar10 & 1) == (uint)(byte)*usb_ro_35608) {
      if ((((*(uint *)(puVar7 + 0x30) & 1) == 0) || (*(short *)puVar6 != 0)) || (*puVar5 != '\0')) {
        *usb_ro_3560c = 10;
      }
      else {
        iVar9 = USNDP_status();
        puVar8 = usb_ro_35610;
        *usb_ro_35610 = iVar9 != 0;
        if (*puVar8 == '\0') goto LAB_00035296;
      }
    }
    else {
      cVar1 = *usb_ro_3560c;
      *usb_ro_3560c = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        *usb_ro_35608 = (char)(uVar10 & 1);
        *puVar8 = 10;
LAB_00035296:
        puVar8 = usb_ro_35608;
        if (*usb_ro_35608 == '\0') {
          dbg_printf(str_usb_chk_PULL_OUT_x_x_x_x,*usb_ro_35678,*(uint *)(puVar7 + 0x30) & 1,*usb_ro_35608,
                     *usb_ro_35610);
          usb_sub_3afa2(1);
          if (*puVar5 != '\0') {
            rf24_sub_3b130();
          }
          *usb_ro_35610 = 0;
          *puVar8 = 0;
          bVar13 = 0;
          *usb_ro_35640 = 0;
          *usb_ro_3570c = 0;
          do {
            *usb_ro_35710 = 0;
            set_Update_OLED_2();
            usb_sub_317c2(10);
            bVar13 = bVar13 + 1;
          } while (bVar13 < 0x1e);
          *(undefined2 *)usb_ro_35714 = 400;
          *usb_ro_35718 = 0;
          *usb_ro_3571c = 1;
          input_sub_3ce00();
          *usb_ro_35720 = 0;
        }
        else {
          iVar9 = USNDP_status();
          puVar8 = usb_ro_35610;
          *usb_ro_35610 = iVar9 != 0;
          uVar2 = *puVar8;
          if (*puVar8 == '\0') {
            dbg_printf(str_INSERT_USNDP_status_usb_insert_x,uVar2);
            led_sub_32892();
            ble_alert_led_stop();
            ble_sub_312aa();
            *usb_ro_35670 = 0;
            puVar8 = usb_ro_35678;
            dbg_printf(str_usb_chk_IN_x_x_x_x,*usb_ro_35678,*(uint *)(puVar7 + 0x30) & 1,*usb_ro_35608,
                       *usb_ro_35674);
            if (*puVar8 == '\0') {
              *usb_ro_356a8 = 0;
              *(undefined2 *)usb_ro_356ac = 0;
              *usb_ro_356b0 = 0;
            }
            else {
              app_user_ke_timer_stop();
              iVar9 = rom_071EA(3);
              if (iVar9 == 3) {
                dbg_printf(usb_ro_356b4);
                *(uint *)usb_ro_356b8 = *(uint *)usb_ro_356b8 | 0x100;
                ble_sub_295aa();
                usb_sub_317c2(0x32);
              }
            }
            *(short *)puVar6 = (short)usb_ro_356bc;
          }
          else {
            dbg_printf(str_INSERT_USNDP_status_charging_x,uVar2);
            *(undefined2 *)puVar6 = 1000;
            *usb_ro_35640 = 0;
          }
          usb_sub_317c2(500);
          power_sub_371c2(usb_ro_356c4,usb_ro_356c0);
          power_sub_377fe(1,usb_ro_356c8);
          power_sub_377fe(2,usb_ro_356cc);
          power_sub_377fe(3,usb_ro_356d0);
          power_sub_377fe(4,usb_ro_356d4);
        }
      }
    }
  }
  else {
    *usb_ro_351e8 = 10;
  }
  *usb_ro_351ec = 1;
  if (*usb_ro_351f0 != '\0') {
    *usb_ro_351f0 = *usb_ro_351f0 + -1;
  }
  if (*usb_ro_355f4 != '\0') {
    *usb_ro_355f4 = *usb_ro_355f4 + -1;
  }
  if (*usb_ro_355f8 != '\0') {
    *usb_ro_355f8 = *usb_ro_355f8 + -1;
  }
  if (*usb_ro_355fc != '\0') {
    *usb_ro_355fc = *usb_ro_355fc + -1;
  }
  cVar1 = *usb_ro_35600;
  if ((cVar1 != '\0') && (*usb_ro_35600 = cVar1 + -1, cVar1 == '\x01')) {
    if ((*usb_ro_35724 != '\0') && (*usb_ro_35728 != '\0')) {
      iVar9 = usb_sub_33d2c(0x5b);
      *usb_ro_35600 = (char)iVar9;
      if (iVar9 != 0x40) {
        usb_sub_345d2();
      }
    }
    *usb_ro_35600 = 0x1e;
  }
  if (*(short *)usb_ro_3572c != 0) {
    *(short *)usb_ro_3572c = *(short *)usb_ro_3572c + -1;
  }
  if (1 < *(ushort *)usb_ro_35730) {
    *(ushort *)usb_ro_35730 = *(ushort *)usb_ro_35730 - 1;
  }
  if (*usb_ro_35734 != '\0') {
    *usb_ro_35734 = *usb_ro_35734 + -1;
  }
  if (*usb_ro_35738 != '\0') {
    *usb_ro_35738 = *usb_ro_35738 + -1;
  }
  cVar1 = *usb_ro_3573c;
  if ((cVar1 != '\0') && (*usb_ro_3573c = cVar1 + -1, cVar1 == '\x01')) {
    usb_sub_3d2b0();
  }
  if (*usb_ro_35740 != '\0') {
    *usb_ro_35740 = *usb_ro_35740 + -1;
  }
  if (*usb_ro_35744 != '\0') {
    *usb_ro_35744 = *usb_ro_35744 + -1;
  }
  if (*usb_ro_35748 != '\0') {
    *usb_ro_35748 = *usb_ro_35748 + -1;
  }
  if (*usb_ro_3574c != '\0') {
    *usb_ro_3574c = *usb_ro_3574c + -1;
  }
  sVar4 = *(short *)puVar6;
  if (sVar4 != 0) {
    *(short *)puVar6 = sVar4 + -1;
    if (*puVar5 == '\0') {
      if (sVar4 != 1) goto LAB_00035534;
      uVar2 = *usb_ro_35674;
      uVar10 = *(uint *)(usb_ro_35604 + 0x30);
      uVar3 = *usb_ro_35608;
      pcVar11 = str_f_usb_isConnected_fail_x_x_x_x;
      uVar12 = 0;
    }
    else {
      *(undefined2 *)puVar6 = 0;
      OLED_Clear();
      flash_sub_3cf7c();
      *usb_ro_35750 = 0;
      usb_sub_3afa2(5);
      ble_alert_led_stop();
      ble_sub_312aa();
      usb_sub_312de();
      if (((*usb_ro_35678 == '\x01') || (*usb_ro_35678 == '\x02')) && (*puVar5 == '\0')) {
        app_user_ke_timer_stop();
        iVar9 = rom_071EA(3);
        if (iVar9 == 3) {
          dbg_printf(usb_ro_356b4);
          *(uint *)usb_ro_356b8 = *(uint *)usb_ro_356b8 | 0x100;
          ble_sub_295aa();
        }
      }
      flash_sub_3262c();
      flash_sub_32658();
      Success_led_2second_2();
      CHRG();
      OLED_Init();
      uVar2 = *usb_ro_35674;
      uVar10 = *(uint *)(usb_ro_35604 + 0x30);
      uVar3 = *usb_ro_35608;
      uVar12 = *(undefined2 *)puVar6;
      pcVar11 = str_f_usb_isConnected_1_x_x_x_x;
    }
    dbg_printf(pcVar11,uVar12,uVar10 & 1,uVar3,uVar2);
  }
LAB_00035534:
  if (*usb_ro_357a0 != '\0') {
    *usb_ro_357a0 = *usb_ro_357a0 + -1;
    *usb_ro_357a4 = 0;
    *usb_ro_357a8 = 1;
    rom_24FEC(usb_ro_357ac,8);
    *usb_ro_357b0 = 1;
  }
  if (*usb_ro_357b4 != '\0') {
    *usb_ro_357b4 = *usb_ro_357b4 + -1;
    return;
  }
  *usb_ro_357b4 = 5;
  if (*usb_ro_357b8 != '\0') {
    *usb_ro_357b8 = *usb_ro_357b8 + -1;
  }
  iVar9 = usb_sub_2b18e();
  if (iVar9 == 0) {
    *usb_ro_35728 = 0;
  }
  else {
    *usb_ro_35728 = 1;
    if ((*usb_ro_35724 == '\0') && ((*(short *)usb_ro_3572c == 0 || (*puVar5 == '\0')))) {
      sensor_init();
      set_dpi();
    }
  }
  puVar6 = usb_ro_357bc;
  puVar5 = usb_ro_35714;
  if (*(short *)usb_ro_35714 == 0) {
    if (*(short *)usb_ro_357bc == 0) {
      *usb_ro_35b54 = 1;
      puVar5 = usb_ro_35b58;
      cVar1 = *usb_ro_35b58;
      *usb_ro_35b58 = cVar1 + '\x01';
      if (cVar1 != '\0') {
        if (0xef < (byte)(cVar1 + 1U)) {
          *puVar5 = 0;
        }
        usb_sub_3d8da(*puVar5);
        return;
      }
    }
  }
  else {
    if ((*(short *)usb_ro_35714 == 400) && (*usb_ro_35718 != '\0')) {
      *usb_ro_35718 = 0;
      OLED_Clear();
      *usb_ro_3573c = 0;
      *usb_ro_357c0 = 1;
      usb_sub_3d2b0();
    }
    sVar4 = *(short *)puVar5;
    *(short *)puVar5 = sVar4 + -1;
    if (((short)(sVar4 + -1) == 0x118) && (*(short *)puVar6 == 0)) {
      *usb_ro_35718 = 1;
      OLED_Clear();
      usb_sub_3d8da(0x78);
    }
    if (*(short *)puVar5 != 0 || *(short *)puVar6 != 0) {
      return;
    }
    OLED_Clear();
  }
  return;
}

/* ==========================================================================
 * usb_sub_358b6   @ 0x000358b6   (424 bytes)
 * called by : system_mode
 * calls     : led_sub_31244, ble_sub_312aa, rf24_sub_3143c, rom_24F9C, rom_24FEC, time_sensor_invalid
 */

void usb_sub_358b6(void)

{
  undefined2 uVar1;
  undefined *puVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  puVar2 = shared_ro_35b98;
  if (*shared_ro_35b98 != '\0') {
    return;
  }
  if (1 < (byte)*shared_ro_35b9c) {
    return;
  }
  if (*usb_ro_35ba0 == '\0') {
    return;
  }
  *usb_ro_35ba0 = 0;
  if (*shared_ro_35ba4 != '\0') {
    return;
  }
  if (*usb_ro_35ba8 != '\0') {
    return;
  }
  time_sensor_invalid();
  puVar5 = usb_ro_35c0c;
  puVar4 = usb_ro_35bb0;
  if (*usb_ro_35bac == '\0') {
    if (*usb_ro_35bb8 == '\0') {
      if (*usb_ro_35bc0 == '\0') {
        if (*usb_ro_35bc8 == '\0') {
          if (*usb_ro_35bd0 == '\0') {
            if (*usb_ro_35bd8 == '\0') {
              if ((((*usb_ro_35be0 == '\0') && (*usb_ro_35be4 == '\0')) && (*usb_ro_35be8 == '\0')) &&
                 ((*usb_ro_35bec == '\0' && (*usb_ro_35bf0 == '\0')))) {
                if (*usb_ro_35c0c != '\0') {
                  return;
                }
                rf24_sub_3143c();
                if (*usb_ro_35c08 == '\0') {
                  uVar3 = 200;
                }
                else {
                  uVar3 = 4;
                }
                *puVar5 = uVar3;
                return;
              }
              led_sub_31244();
              *puVar4 = 0x30;
              puVar4[1] = *usb_ro_35bf4;
              uVar1 = *(undefined2 *)usb_ro_35bf8;
              puVar4[2] = (char)uVar1;
              puVar4[3] = (char)((ushort)uVar1 >> 8);
              uVar1 = *(undefined2 *)usb_ro_35bfc;
              puVar4[4] = (char)uVar1;
              puVar4[5] = (char)((ushort)uVar1 >> 8);
              puVar4[6] = *usb_ro_35c00;
              puVar4[7] = *usb_ro_35c04;
              if ((*usb_ro_35be4 == '\0') || (*usb_ro_35be8 == '\0')) {
                *usb_ro_35be8 = 0;
              }
              ble_sub_312aa();
              *usb_ro_35c08 = 200;
              *usb_ro_35c0c = 4;
              goto LAB_00035928;
            }
            *usb_ro_35bd8 = 0;
            rom_24FEC(usb_ro_35bb0,0x20);
            *puVar4 = 0x35;
            rom_24F9C(puVar4 + 1,usb_ro_35bdc,4);
            puVar4 = usb_ro_35bdc;
          }
          else {
            *usb_ro_35bd0 = 0;
            rom_24FEC(usb_ro_35bb0,0x20);
            *puVar4 = 0x35;
            rom_24F9C(puVar4 + 1,usb_ro_35bd4,4);
            puVar4 = usb_ro_35bd4;
          }
          rom_24FEC(puVar4,4);
        }
        else {
          *usb_ro_35bc8 = 0;
          rom_24FEC(usb_ro_35bb0,0x20);
          *puVar4 = 0x34;
          puVar4 = usb_ro_35bcc;
          usb_ro_35bb0[1] = *usb_ro_35bcc;
          *puVar4 = 0;
        }
      }
      else {
        *usb_ro_35bc0 = 0;
        rom_24FEC(usb_ro_35bb0,0x20);
        puVar5 = usb_ro_35bc4;
        *puVar4 = 0x33;
        puVar4 = usb_ro_35bb0;
        usb_ro_35bb0[1] = *puVar5;
        puVar4[2] = puVar5[1];
      }
      goto LAB_00035928;
    }
    *usb_ro_35bb8 = 0;
    rom_24FEC(usb_ro_35bb0,0x20);
    puVar5 = usb_ro_35bbc;
    uVar6 = 0xe;
    *puVar4 = 0x32;
  }
  else {
    *usb_ro_35bac = 0;
    rom_24FEC(puVar4,0x20);
    puVar5 = usb_ro_35bb4;
    uVar6 = 8;
    *puVar4 = 0x31;
  }
  rom_24F9C(puVar4 + 1,puVar5,uVar6);
LAB_00035928:
  *puVar2 = 1;
  return;
}

/* ==========================================================================
 * fn24main   @ 0x00035dbe   (106 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : power_sub_35c9c, usb_sub_360aa, usb_sub_36b36, usb_sub_36be4, usb_sub_39c84, TEST_SINGLE_WAVE, ... (+4 more)
 * string    : "fn24main  RF_MODE USB %x, %x, %x\r\n"
 */

void fn24main(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  usb_sub_39c84();
  power_sub_35c9c();
  if (*usb_ro_35e8c == '\0' && *(short *)usb_ro_35e90 == 0) {
    fWorkModeInit();
  }
  usb_sub_36b36();
  usb_sub_36be4(2);
  puVar3 = shared_ro_35e54;
  puVar2 = shared_ro_35e38;
  dbg_printf(str_fn24main_RF_MODE_USB_x_x_x,*shared_ro_35e54,*shared_ro_35e30,*(undefined2 *)shared_ro_35e38);
  cVar1 = *puVar3;
  if (cVar1 == '\0') {
    system_mode();
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 == '\x04') {
      if (*(short *)puVar2 == 7) {
        TEST_SINGLE_WAVE_2();
        return;
      }
      if (*(short *)puVar2 != 10) {
        return;
      }
      TEST_SINGLE_WAVE();
      return;
    }
    if (cVar1 == '\x05') {
      usb_sub_360aa();
    }
  }
  return;
}

/* ==========================================================================
 * system_mode   @ 0x00035eb8   (282 bytes)
 * called by : fn24main
 * calls     : Detect_FULL_IN, ble_sub_2aa5c, ble_sub_2ac0e, ble_sub_2b8a2, usb_sub_30094, ble_sub_3186e, ... (+27 more)
 * string    : "system_mode usb24 RF_MODE %x, %x\r\n"
 */

void system_mode(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 in_r3;
  
  puVar2 = usb_ro_35fd8;
  puVar1 = usb_ro_35fd4;
  dbg_printf(str_system_mode_usb24_RF_MODE_x_x,*usb_ro_35fd8,*usb_ro_35fd4,in_r3,in_r3);
  puVar3 = usb_ro_36000;
  if (*usb_ro_36000 == '\0') {
    usb_sub_369a0();
    puVar4 = usb_ro_36004;
    *(undefined4 *)(usb_ro_36004 + 0x18) = 0xa0;
    *(undefined4 *)(puVar4 + 0x18) = 0x80;
    usb_sub_369d8();
    rom_24FEC(usb_ro_36008,0x20);
  }
  usb_sub_3cdb6();
  usb_sub_36eee(8);
LAB_00035fbe:
  while( true ) {
    if ((*puVar2 != '\0') || ((*puVar1 != '\0' && (*puVar3 == '\0')))) {
      return;
    }
    usb_sub_3b54e();
    if (*usb_ro_3600c != '\0') {
      *usb_ro_3600c = 0;
      usb_sub_3300e();
    }
    if ((*usb_ro_36010 != '\0') && (*usb_ro_36014 == '\0')) {
      *usb_ro_36010 = 0;
      ble_sub_2ac0e();
    }
    if (*usb_ro_36018 != '\0') break;
    ble_sub_2aa5c();
    if (*puVar3 == '\0') {
      if (*puVar1 == '\0') goto code_r0x00035f5e;
      goto LAB_00035f80;
    }
    usb_sub_3870a();
    usb_sub_33a7e();
    usb_suspend();
    exist();
    test();
    ble_sub_3186e();
    usb_sub_3236a();
    if (*usb_ro_3601c != '\0') goto LAB_00035f7e;
  }
  goto LAB_00035f94;
code_r0x00035f5e:
  ble_sub_3186e();
  usb_sub_3236a();
  usb_sub_358b6();
  usb_sub_30094();
  if ((*usb_ro_3601c != '\0') && ((byte)*usb_ro_36014 < 2)) {
LAB_00035f7e:
    *usb_ro_3601c = 0;
LAB_00035f80:
    usb_sub_323ee();
    usb_sub_32430();
    _saveC_GM_ProfileMax();
    set_Update_OLED_2();
    Led_OLED();
LAB_00035f94:
    set_Update_OLED();
    single_wave();
    if (*puVar3 == '\0') {
      f_reconnect_24G();
    }
    f_usb_isConnected();
    usb_sub_34e4c();
    mode_sw();
    Detect_FULL_IN();
    app_mutli_link_change();
    ble_sub_2b8a2();
  }
  goto LAB_00035fbe;
}

/* ==========================================================================
 * usb_sub_36024   @ 0x00036024   (32 bytes)
 * called by : usb_sub_360aa
 * calls     : usb_sub_369d8, usb_sub_3c21e, usb_sub_3c286
 */

void usb_sub_36024(void)

{
  undefined *puVar1;
  
  usb_sub_369d8();
  usb_sub_3c286(1);
  usb_sub_3c21e(1,usb_ro_3618c);
  puVar1 = usb_ro_36190;
  usb_ro_36190[1] = 0;
  puVar1[2] = 1;
  return;
}

/* ==========================================================================
 * usb_sub_36044   @ 0x00036044   (102 bytes)
 * called by : usb_sub_360aa
 */

void usb_sub_36044(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  byte bVar6;
  
  puVar3 = usb_ro_36194;
  bVar6 = 0;
  uVar1 = usb_ro_36190[1];
  uVar2 = usb_ro_36190[2];
  do {
    puVar4 = usb_ro_36198;
    do {
    } while (-1 < (int)(*(uint *)puVar3 << 0x11));
    *(uint *)puVar3 = *(uint *)puVar3 & 0xffffbfff;
    *(undefined4 *)(puVar4 + 0x18) = 0xa0;
    *(undefined4 *)(puVar4 + 0x18) = 0x80;
    *(undefined4 *)(puVar4 + 0x14) = 1;
    puVar5 = usb_ro_3619c;
    *usb_ro_3619c = 0x55;
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    *(undefined4 *)(puVar4 + 0x14) = 0;
    bVar6 = bVar6 + 1;
  } while (bVar6 < 100);
  *usb_ro_36190 = 0x55;
  bVar6 = 0;
  do {
    do {
    } while (-1 < (int)(*(uint *)puVar3 << 0x11));
    bVar6 = bVar6 + 1;
    *(uint *)puVar3 = *(uint *)puVar3 & 0xffffbfff;
  } while (bVar6 < 0x2a);
  return;
}

/* ==========================================================================
 * usb_sub_360aa   @ 0x000360aa   (226 bytes)
 * called by : fn24main
 * calls     : power_sub_2bcac, rf24_sub_31784, usb_sub_36024, usb_sub_36044, usb_sub_361a8, usb_sub_369a0, ... (+8 more)
 */

void usb_sub_360aa(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  
  usb_sub_3b528();
  usb_sub_36024();
  puVar3 = usb_ro_36198;
  *(undefined4 *)(usb_ro_36198 + -0xb4) = 1;
  *(undefined4 *)(puVar3 + -0xb0) = 5;
  *(undefined4 *)(puVar3 + -0xac) = 0x8a;
  *(undefined4 *)(puVar3 + -0xa8) = 3;
  usb_sub_369a0();
  puVar2 = usb_ro_36194;
  bVar4 = 0;
  do {
    bVar4 = bVar4 + 1;
  } while (bVar4 < 0x14);
  *(uint *)usb_ro_36194 = *(uint *)usb_ro_36194 & 0xffffbfff;
  bVar4 = 0;
  do {
    do {
    } while (-1 < (int)(*(uint *)puVar2 << 0x11));
    bVar4 = bVar4 + 1;
    *(uint *)puVar2 = *(uint *)puVar2 & 0xffffbfff;
    puVar1 = usb_ro_36190;
  } while (bVar4 < 0x44);
  if (usb_ro_36190[2] != -1) {
    usb_sub_36044();
    usb_sub_361a8(puVar1[1]);
    bVar4 = puVar1[2];
    for (uVar5 = 0; (int)uVar5 < (int)(bVar4 - 1); uVar5 = uVar5 + 1 & 0xff) {
      bVar6 = 0;
      do {
        do {
        } while (-1 < (int)(*(uint *)puVar2 << 0x11));
        bVar6 = bVar6 + 1;
        *(uint *)puVar2 = *(uint *)puVar2 & 0xffffbfff;
      } while (bVar6 < 0x96);
    }
    usb_sub_36b36();
    usb_sub_36be4(2);
    usb_sub_369a0();
    puVar2 = usb_ro_36198;
    *(undefined4 *)(usb_ro_36198 + 0x18) = 0xa0;
    *(undefined4 *)(puVar2 + 0x18) = 0x80;
    *(undefined4 *)(puVar3 + -0xb4) = 1;
    *(undefined4 *)(puVar3 + -0xb0) = 5;
    *(uint *)(puVar3 + -0xac) = (byte)usb_ro_36190[1] + 0x80;
    *(undefined4 *)(puVar3 + -0xa8) = 3;
    usb_sub_369d8();
    rf24_sub_31784(usb_ro_361a0);
    sensor_pwdn();
    usb_sub_369ac();
    usb_sub_3c286(1);
    power_sub_2bcac();
    puVar2 = usb_ro_361a4;
    do {
      *(undefined4 *)puVar2 = 0;
      ble_sub_3ae82();
    } while( true );
  }
  do {
    usb_sub_36044();
  } while( true );
}

/* ==========================================================================
 * usb_sub_361a8   @ 0x000361a8   (50 bytes)
 * called by : usb_sub_360aa, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, single_wave
 */

void usb_sub_361a8(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = usb_ro_365a0;
  *(uint *)(usb_ro_365a0 + 0x10) = *(uint *)(usb_ro_365a0 + 0x10) | 0x20000000;
  *(undefined4 *)(usb_ro_365a4 + 0x10) = *(undefined4 *)(puVar1 + 0x10);
  puVar1 = usb_ro_365a4;
  uVar2 = *(uint *)(usb_ro_365a4 + 0x90);
  *(uint *)usb_ro_365a8 = uVar2;
  *(uint *)(puVar1 + 0x90) = uVar2 & 0x780 | param_1;
  *(uint *)(puVar1 + 0x94) = *(uint *)(puVar1 + 0x94) | 0x3000;
  return;
}

/* ==========================================================================
 * usb_sub_361da   @ 0x000361da   (22 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2
 */

void usb_sub_361da(void)

{
  undefined *puVar1;
  
  puVar1 = usb_ro_365a4;
  *(undefined4 *)(usb_ro_365a4 + 0x90) = *(undefined4 *)usb_ro_365a8;
  *(uint *)(puVar1 + 0x94) = *(uint *)(puVar1 + 0x94) & 0xffffcfff;
  return;
}

/* ==========================================================================
 * get_scan_Rvalue   @ 0x000361f0   (68 bytes)
 * calls     : ble_sub_2abd4, usb_sub_317c2, dbg_printf
 * string    : "get_scan_Rvalue 2============== %x,%x,%x,%x,%x,\r\n"
 */

void get_scan_Rvalue(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = usb_ro_365ac;
  if ((*usb_ro_365ac == '\0') && (iVar2 = ble_sub_2abd4(), iVar2 == 3)) {
    usb_sub_317c2(10);
    iVar2 = ble_sub_2abd4();
    dbg_printf(str_get_scan_Rvalue_2_x_x_x_x_x,*puVar1,iVar2,*usb_ro_365b8,*usb_ro_365b4,*usb_ro_365b0);
    if (iVar2 == 3) {
      *usb_ro_365f0 = 1;
    }
  }
  return;
}

/* ==========================================================================
 * TEST_SINGLE_WAVE_2   @ 0x00036274   (836 bytes)
 * called by : fn24main
 * calls     : ble_sub_2ac0e, rf24_sub_31784, ble_sub_32686, usb_sub_361a8, usb_sub_361da, usb_sub_369a0, ... (+10 more)
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

void TEST_SINGLE_WAVE_2(void)

{
  short sVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  bool bVar11;
  
  uVar8 = 1;
  bVar2 = false;
  dbg_printf(str_s_12,usb_ro_3660c);
  usb_sub_3b528();
  iVar9 = 0;
  *(undefined4 *)(usb_ro_36618 + 0x10) = 3;
  usb_sub_36eee(8);
  usb_sub_369ac();
  usb_sub_369a0();
  usb_sub_369d8();
  usb_sub_361a8(usb_ro_3660c[-2]);
  *usb_ro_365f0 = 1;
  ble_sub_32686(7);
  while (*(short *)usb_ro_36620 != 0) {
    if (*usb_ro_3661c != '\0') {
      *usb_ro_3661c = 0;
      ble_sub_2ac0e();
    }
  }
  *usb_ro_36624 = 0;
  ble_sub_32686(2);
  uVar5 = usb_sub_39cfc();
  *usb_ro_36628 = (char)uVar5;
  dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x_mode_cal_data_x,usb_ro_3660c[-2],0,uVar5);
LAB_000362f4:
  while( true ) {
    do {
      do {
      } while (*usb_ro_3661c == '\0');
      *usb_ro_3661c = 0;
      if (iVar9 == 2) {
        dbg_printf(str_TEST_RF_DATA);
        puVar3 = usb_ro_36674;
        *usb_ro_36674 = 1;
        puVar3[1] = 1;
        puVar3[2] = 2;
        puVar3[3] = 3;
        puVar3[4] = 4;
        cVar10 = '\x04';
        do {
          usb_sub_36dd4(5);
          rf24_sub_31784(usb_ro_36678);
          bVar11 = cVar10 != '\0';
          cVar10 = cVar10 + -1;
        } while (bVar11);
      }
      else if (iVar9 == 1) {
        dbg_printf(str_TEST_CD);
        puVar3 = usb_ro_36674;
        *usb_ro_36674 = 0xcc;
        puVar3[1] = 0xcc;
        puVar3[2] = 0xcc;
        puVar3[3] = 0xcc;
        puVar3[4] = 0xcc;
        puVar3[5] = 0xcc;
        puVar3[6] = 0xcc;
        puVar3[7] = 0xcc;
        puVar3[8] = 0xcc;
        puVar3[9] = 0xcc;
        puVar3[10] = 0xcc;
        puVar3[0xb] = 0xcc;
        puVar3[0xc] = 0xcc;
        puVar3[0xd] = 0xcc;
        puVar3[0xe] = 0xcc;
        puVar3[0xf] = 0xcc;
        puVar3[0x10] = 0xcc;
        puVar3[0x11] = 0xcc;
        puVar3[0x12] = 0xcc;
        puVar3[0x13] = 0xcc;
        puVar3[0x14] = 0xcc;
        puVar3[0x15] = 0xcc;
        puVar3[0x16] = 0xcc;
        puVar3[0x17] = 0xcc;
        puVar3[0x18] = 0xcc;
        usb_sub_36b36();
        usb_sub_36be4(2);
        usb_sub_369a0();
        puVar3 = usb_ro_36618;
        *(undefined4 *)(usb_ro_36618 + 0xd8) = 0xa0;
        *(undefined4 *)(puVar3 + 0xd8) = 0x80;
        *(undefined4 *)(usb_ro_36618 + 0x10) = 3;
        usb_sub_361da();
        usb_sub_36eee(8);
        usb_sub_369d8();
        *(undefined4 *)(puVar3 + 0xd4) = 0;
        *(uint *)(usb_ro_36618 + 0x14) = (byte)usb_ro_3668c[uVar8] + 0x80;
        *(undefined4 *)(puVar3 + 0xd4) = 1;
        uVar8 = uVar8 + 1 & 0xf;
        cVar10 = '\x04';
        do {
          usb_sub_36dd4(0x19);
          rf24_sub_31784(usb_ro_36678);
          bVar11 = cVar10 != '\0';
          cVar10 = cVar10 + -1;
        } while (bVar11);
      }
      if (bVar2) {
        dbg_printf(str_flag_revice);
        puVar3 = usb_ro_366a4;
        uVar7 = *(uint *)usb_ro_366a4;
        if ((int)(uVar7 << 0x19) < 0) {
          *(undefined4 *)(usb_ro_366a4 + -0x28) = 0x80;
          *(uint *)puVar3 = uVar7 & 0xff;
        }
      }
      ble_sub_2ac0e();
    } while ((*usb_ro_365f0 == '\0') || (*usb_ro_36624 == '\0'));
    *usb_ro_36624 = 0;
    puVar3 = usb_ro_36620;
    dbg_printf(str_Key_CurrentStatus_x_2,*(undefined2 *)usb_ro_36620);
    sVar1 = *(short *)puVar3;
    if (sVar1 == 1) break;
    if (sVar1 == 4) {
      dbg_printf(str_MB_press_SW_channel);
      bVar2 = false;
      uVar8 = uVar8 + 1 & 0xff;
      if (uVar8 < 3) {
        if (uVar8 == 0) goto LAB_00036536;
        if (uVar8 == 1) {
          uVar5 = 2;
          goto LAB_00036540;
        }
        if (uVar8 == 2) {
          uVar5 = 4;
          goto LAB_00036540;
        }
      }
      else {
        uVar8 = 0;
LAB_00036536:
        uVar5 = 1;
LAB_00036540:
        ble_sub_32686(uVar5);
      }
      usb_sub_36b36();
      usb_sub_36be4(2);
      usb_sub_369a0();
      puVar3 = usb_ro_366a4;
      *(undefined4 *)(usb_ro_366a4 + -0x28) = 0xa0;
      *(undefined4 *)(puVar3 + -0x28) = 0x80;
      *(undefined4 *)(usb_ro_36618 + 0x10) = 3;
      usb_sub_361da();
      rf24_sub_31784(300);
      usb_sub_36eee(8);
      usb_sub_369d8();
      puVar4 = usb_ro_36914;
      if (iVar9 == 0) {
        usb_sub_361a8(usb_ro_36914[uVar8]);
        dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x,puVar4[uVar8],0);
      }
      else {
        *(uint *)(usb_ro_36618 + 0x14) = (byte)usb_ro_3660c[uVar8 - 3] + 0x80;
        *(undefined4 *)(puVar3 + -0x2c) = 0;
        *(undefined4 *)(puVar3 + -0x2c) = 1;
      }
      dbg_printf(str_switch_ch_d_mode_x,usb_ro_3660c[uVar8 - 3],iVar9);
    }
    else if (sVar1 == 2) {
      dbg_printf(str_RB_press);
      bVar2 = true;
      iVar9 = 3;
      usb_sub_36b36();
      usb_sub_36be4(2);
      usb_sub_369a0();
      puVar3 = usb_ro_366a4;
      *(undefined4 *)(usb_ro_366a4 + -0x28) = 0xa0;
      *(undefined4 *)(puVar3 + -0x28) = 0x80;
      puVar3 = usb_ro_36618;
      *(undefined4 *)(usb_ro_36618 + 0x10) = 3;
      *(uint *)(puVar3 + 0x14) = (byte)usb_ro_3660c[uVar8 - 3] + 0x80;
      usb_sub_36eee(8);
      usb_sub_369b8();
      *(uint *)(puVar3 + 0x14) = (byte)usb_ro_3660c[uVar8 - 3] + 0x80;
    }
  }
  dbg_printf(str_LB_press_SW_mode);
  bVar2 = false;
  usb_sub_36b36();
  usb_sub_36be4(2);
  usb_sub_369a0();
  puVar3 = usb_ro_366a4;
  *(undefined4 *)(usb_ro_366a4 + -0x28) = 0xa0;
  *(undefined4 *)(puVar3 + -0x28) = 0x80;
  puVar3 = usb_ro_36618;
  *(undefined4 *)(usb_ro_36618 + 0x10) = 3;
  usb_sub_36eee(8);
  if (iVar9 == 0) {
    iVar9 = 2;
    *(uint *)(puVar3 + 0x14) = (byte)usb_ro_3660c[uVar8 - 3] + 0x80;
    usb_sub_369d8();
    ble_sub_32686(4);
    uVar5 = *(undefined4 *)usb_ro_365a8;
    pcVar6 = str_TEST_RF_DATA_x;
  }
  else {
    if (iVar9 == 2) {
      iVar9 = 1;
      uVar8 = 0;
      *(uint *)(puVar3 + 0x14) = (byte)*usb_ro_3668c + 0x80;
      usb_sub_369d8();
      ble_sub_32686(2);
      dbg_printf(str_TEST_CD_2);
      goto LAB_000362f4;
    }
    if ((iVar9 != 1) && (iVar9 != 3)) goto LAB_000362f4;
    iVar9 = 0;
    usb_sub_361a8(usb_ro_3660c[uVar8 - 3]);
    ble_sub_32686(1);
    uVar5 = *(undefined4 *)usb_ro_365a8;
    pcVar6 = str_TEST_SINGLE_WAVE_x;
  }
  dbg_printf(pcVar6,uVar5);
  goto LAB_000362f4;
}

/* ==========================================================================
 * TEST_SINGLE_WAVE   @ 0x00036754   (422 bytes)
 * called by : fn24main
 * calls     : ble_sub_28b00, ble_sub_2ac0e, rf24_sub_31784, ble_sub_32686, usb_sub_361a8, usb_sub_361da, ... (+12 more)
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

void TEST_SINGLE_WAVE(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  dbg_printf(usb_ro_3693c,str_application_cal_data_mode,param_3,param_4,param_3);
  usb_sub_3b528();
  uVar6 = 0;
  *(undefined4 *)(usb_ro_36940 + 0x10) = 3;
  usb_sub_36eee(8);
  usb_sub_369ac();
  usb_sub_369a0();
  usb_sub_369d8();
  usb_sub_361a8(usb_ro_36914[1]);
  *usb_ro_36944 = 1;
  ble_sub_32686(7);
  puVar3 = usb_ro_36948;
  while (puVar4 = usb_ro_36950, *(short *)puVar3 != 0) {
    if (*usb_ro_3694c != '\0') {
      *usb_ro_3694c = 0;
      ble_sub_2ac0e();
    }
  }
  *usb_ro_36950 = 0;
  ble_sub_32686(2);
  uVar5 = usb_sub_39cfc();
  puVar2 = usb_ro_36914;
  *usb_ro_36954 = (char)uVar5;
  dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x_mode_cal_data_x,puVar2[1],uVar6,uVar5);
LAB_000367d8:
  do {
    do {
      do {
      } while (*usb_ro_3694c == '\0');
      *usb_ro_3694c = 0;
      ble_sub_2ac0e();
    } while ((*usb_ro_36944 == '\0') || (*puVar4 == '\0'));
    *puVar4 = 0;
    dbg_printf(str_Key_CurrentStatus_x_2,*(undefined2 *)puVar3);
    sVar1 = *(short *)puVar3;
    if (sVar1 == 0x10) {
      *usb_ro_36958 = 1;
      *usb_ro_36954 = *usb_ro_36954 + '\x01';
      rgb_24g_test_cal();
      dbg_printf(str_B4_CAL_DATA_x,*usb_ro_36954);
      ble_sub_28b00(usb_ro_36988);
      rwip_driver_init(0);
      usb_sub_36b36();
      usb_sub_36be4(2);
      usb_sub_369a0();
      puVar2 = usb_ro_36940;
      *(undefined4 *)(usb_ro_36940 + 0xd8) = 0xa0;
      *(undefined4 *)(puVar2 + 0xd8) = 0x80;
    }
    else {
      if (sVar1 != 0x20) {
        if (sVar1 == 0x100) {
          *usb_ro_36958 = 1;
          usb_sub_39d26(*usb_ro_36954);
          ble_sub_32686(0);
          uVar5 = usb_sub_39cfc();
          *usb_ro_36954 = (char)uVar5;
          dbg_printf(str_DPILOOP_SURE_x,uVar5);
        }
        goto LAB_000367d8;
      }
      *usb_ro_36958 = 1;
      *usb_ro_36954 = *usb_ro_36954 + -1;
      rgb_24g_test_cal();
      dbg_printf(str_B5_CAL_DATA_x,*usb_ro_36954);
      ble_sub_28b00(usb_ro_36988);
      rwip_driver_init(0);
      usb_sub_36b36();
      usb_sub_36be4(2);
      usb_sub_369a0();
      puVar2 = usb_ro_36940;
      *(undefined4 *)(usb_ro_36940 + 0xd8) = 0xa0;
      *(undefined4 *)(puVar2 + 0xd8) = 0x80;
    }
    *(undefined4 *)(usb_ro_36940 + 0x10) = 3;
    usb_sub_361da();
    rf24_sub_31784(300);
    usb_sub_36eee(8);
    usb_sub_369d8();
    usb_sub_361a8(usb_ro_36914[1]);
    dbg_printf(str_TEST_SINGLE_WAVE_ch_d_mode_x,usb_ro_36914[1],uVar6);
  } while( true );
}

/* ==========================================================================
 * usb_sub_369a0   @ 0x000369a0   (12 bytes)
 * called by : led_sub_2ff18, usb_sub_30094, usb_sub_360aa, usb_sub_369b8, usb_sub_369d8, usb_sub_36e0c, ... (+8 more)
 */

void usb_sub_369a0(void)

{
  *(uint *)shared_ro_36d84 = *(uint *)shared_ro_36d84 | 2;
  return;
}

/* ==========================================================================
 * usb_sub_369ac   @ 0x000369ac   (12 bytes)
 * called by : led_sub_2ff18, usb_sub_360aa, usb_sub_36b36, usb_sub_36e0c, SLEEP, TEST_SINGLE_WAVE, ... (+4 more)
 */

void usb_sub_369ac(void)

{
  *(uint *)shared_ro_36d84 = *(uint *)shared_ro_36d84 & 0xfd;
  return;
}

/* ==========================================================================
 * usb_sub_369b8   @ 0x000369b8   (32 bytes)
 * called by : flash_sub_2fef0, TEST_SINGLE_WAVE_2, ch_frequency
 * calls     : usb_sub_369a0
 */

void usb_sub_369b8(void)

{
  undefined *puVar1;
  
  usb_sub_369a0();
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd8) = 0x80;
  *(undefined4 *)(puVar1 + 0xd4) = 0;
  *(uint *)shared_ro_36d84 = *(uint *)shared_ro_36d84 | 1;
  *(undefined4 *)(puVar1 + 0xd4) = 1;
  return;
}

/* ==========================================================================
 * usb_sub_369d8   @ 0x000369d8   (34 bytes)
 * called by : rf24_sub_2fa6c, usb_sub_30094, usb_sub_36024, usb_sub_360aa, LightUp_Mode_Led, TEST_SINGLE_WAVE, ... (+4 more)
 * calls     : usb_sub_369a0
 */

void usb_sub_369d8(void)

{
  undefined *puVar1;
  
  usb_sub_369a0();
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd8) = 0xa0;
  *(undefined4 *)(puVar1 + 0xd4) = 0;
  *(uint *)shared_ro_36d84 = *(uint *)shared_ro_36d84 & 0xfe;
  *(undefined4 *)(puVar1 + 0xd4) = 1;
  return;
}

/* ==========================================================================
 * usb_sub_369fa   @ 0x000369fa   (24 bytes)
 * called by : usb_sub_36a12, usb_sub_36b36, rf24_sub_36cd2, flash_sub_36cee
 */

void usb_sub_369fa(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    *(undefined4 *)(param_1 + uVar1 * 4) = *(undefined4 *)(param_2 + uVar1 * 4);
  }
  return;
}

/* ==========================================================================
 * usb_sub_36a12   @ 0x00036a12   (66 bytes)
 * calls     : usb_sub_369fa, rom_25078
 */

void usb_sub_36a12(void)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = shared_ro_36d84 + 0x1c;
  puVar3 = shared_ro_36d84 + 0x30;
  iVar1 = rom_25078();
  usb_sub_369fa(puVar2,shared_ro_36d88,3);
  usb_sub_369fa(iVar1 << 0x10,shared_ro_36d88,3);
  usb_sub_369fa(puVar3,shared_ro_36d88 + 0xc,3);
  return;
}

/* ==========================================================================
 * usb_sub_36af2   @ 0x00036af2   (34 bytes)
 * called by : usb_sub_36dd4
 */

void usb_sub_36af2(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd8) = 0x68;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(uint *)(puVar1 + 0xdc) = (uint)*(byte *)(param_1 + uVar2);
  }
  *(undefined4 *)(puVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * usb_sub_36b36   @ 0x00036b36   (174 bytes)
 * called by : usb_sub_360aa, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, fn24main
 * calls     : usb_sub_369ac, usb_sub_369fa
 */

void usb_sub_36b36(void)

{
  undefined *puVar1;
  
  reg_80000c = reg_80000c & 0xfffeffff;
  usb_sub_369fa(shared_ro_36d84 + 0x88,shared_ro_36d88 + -0x20,4);
  usb_sub_369fa(shared_ro_36d84 + 0x98,shared_ro_36d88 + -0x10,4);
  puVar1 = shared_ro_36d84;
  *(undefined4 *)shared_ro_36d84 = 0xc;
  *(undefined4 *)(puVar1 + 4) = 3;
  *(undefined4 *)(puVar1 + 8) = 3;
  *(undefined4 *)(puVar1 + 0xc) = 1;
  *(undefined4 *)(puVar1 + 0x10) = 2;
  *(undefined4 *)(puVar1 + 0x14) = 0x85;
  *(undefined4 *)(puVar1 + 0x18) = 0xf;
  usb_sub_369fa(shared_ro_36d84 + 0x1c,shared_ro_36d88,3);
  usb_sub_369fa(shared_ro_36d84 + 0x30,shared_ro_36d88 + 0xc,3);
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0x44) = 0x11;
  *(undefined4 *)(puVar1 + 0x48) = 0x12;
  *(undefined4 *)(puVar1 + 0x4c) = 0x13;
  *(undefined4 *)(puVar1 + 0x50) = 0x14;
  usb_sub_369fa(shared_ro_36d84 + 0x54,shared_ro_36d88,3);
  *(undefined4 *)(puVar1 + 0x68) = 0x20;
  *(undefined4 *)(puVar1 + 0x6c) = 0x20;
  *(undefined4 *)(puVar1 + 0x70) = 0x20;
  *(undefined4 *)(puVar1 + 0x74) = 0x20;
  *(undefined4 *)(puVar1 + 0x78) = 0x20;
  *(undefined4 *)(puVar1 + 0x7c) = 0x20;
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0x80) = 0x3f;
  *(undefined4 *)(puVar1 + 0x84) = 7;
  usb_sub_369ac();
  *(undefined4 *)(usb_ro_36d90 + 0x10) = usb_ro_36d8c;
  *(undefined4 *)(usb_ro_36d90 + 0x6c) = usb_ro_36d94;
  return;
}

/* ==========================================================================
 * usb_sub_36be4   @ 0x00036be4   (146 bytes)
 * called by : usb_sub_360aa, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, fn24main
 */

void usb_sub_36be4(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar3 = usb_ro_36d98;
  puVar2 = usb_ro_36d90;
  puVar1 = shared_ro_36d84;
  if (param_1 == 0) {
    *(uint *)(usb_ro_36d90 + 0x38) = *(uint *)(usb_ro_36d90 + 0x38) & 0xfffffe00;
    *(uint *)(puVar2 + 0x38) = *(uint *)(puVar2 + 0x38) | 100;
    *(uint *)(puVar2 + 0x18) = *(uint *)(puVar2 + 0x18) & uVar3;
    *(uint *)(puVar2 + 0x18) = *(uint *)(puVar2 + 0x18) | 0x4080000;
    puVar5 = (uint *)(usb_ro_36d90 + 0x40);
    *puVar5 = *puVar5 & usb_ro_36d9c;
    *puVar5 = *puVar5 | 0x2800;
    uVar4 = 0x27;
  }
  else {
    uVar6 = (int)usb_ro_36d90 >> 0xf;
    if (param_1 == 1) {
      *(uint *)(usb_ro_36d90 + 0x38) = *(uint *)(usb_ro_36d90 + 0x38) & 0xfffffe00;
      *(uint *)(puVar2 + 0x38) = *(uint *)(puVar2 + 0x38) | uVar6;
      *(uint *)(puVar2 + 0x18) = *(uint *)(puVar2 + 0x18) & uVar3;
      *(uint *)(puVar2 + 0x18) = *(uint *)(puVar2 + 0x18) | 0x10200000;
      uVar4 = 7;
    }
    else {
      if (param_1 != 2) {
        return;
      }
      *(uint *)(usb_ro_36d90 + 0x38) = *(uint *)(usb_ro_36d90 + 0x38) & 0xfffffe00;
      *(uint *)(puVar2 + 0x38) = *(uint *)(puVar2 + 0x38) | uVar6;
      *(uint *)(puVar2 + 0x18) = *(uint *)(puVar2 + 0x18) & uVar3;
      *(uint *)(puVar2 + 0x18) = *(uint *)(puVar2 + 0x18) | 0x10200000;
      uVar4 = 0xf;
    }
  }
  *(undefined4 *)(puVar1 + 0x18) = uVar4;
  return;
}

/* ==========================================================================
 * usb_sub_36dd4   @ 0x00036dd4   (56 bytes)
 * called by : TEST_SINGLE_WAVE_2
 * calls     : usb_sub_36af2
 */

undefined4 usb_sub_36dd4(undefined4 param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_36f1c;
  *(undefined4 *)(shared_ro_36f1c + 0x18) = 0x80;
  *(undefined4 *)(puVar1 + 0x18) = 0xa0;
  *(undefined4 *)(puVar1 + 0x14) = 1;
  usb_sub_36af2(shared_ro_36f20,param_1);
  do {
    uVar2 = *(uint *)(shared_ro_36f1c + 0x40);
  } while ((uVar2 & 0x3f) >> 4 == 0);
  if ((int)(uVar2 << 0x1a) < 0) {
    *(uint *)(shared_ro_36f1c + 0x40) = 0x20;
  }
  *(undefined4 *)(puVar1 + 0x14) = 0;
  return 1;
}

/* ==========================================================================
 * usb_sub_36e0c   @ 0x00036e0c   (124 bytes)
 * calls     : usb_sub_369a0, usb_sub_369ac, led_sub_36ad0
 */

undefined4 usb_sub_36e0c(undefined4 param_1)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  puVar2 = shared_ro_36f1c;
  uVar5 = 0;
  *(undefined4 *)(shared_ro_36f1c + 0x18) = 0x80;
  *(undefined4 *)(puVar2 + 0x18) = 0xa0;
  *(undefined4 *)(shared_ro_36f1c + 0x40) = 0x7e;
  *(undefined4 *)(puVar2 + 0x14) = 1;
  led_sub_36ad0(shared_ro_36f20,param_1);
  bVar1 = false;
  *usb_ro_36f24 = 0;
  puVar4 = (uint *)(shared_ro_36f1c + 0x40);
  do {
    uVar3 = *puVar4;
    if (5 < (byte)*usb_ro_36f24) {
      bVar1 = true;
      break;
    }
  } while ((uVar3 & 0x3f) >> 4 == 0);
  if ((int)(uVar3 << 0x19) < 0) {
    *(undefined4 *)(puVar2 + 0x18) = 0x80;
    *puVar4 = 0x40;
    uVar5 = 2;
  }
  if ((int)(uVar3 << 0x1a) < 0) {
    *(undefined4 *)(puVar2 + 0x18) = 0xa0;
    *puVar4 = 0x20;
    uVar5 = 1;
  }
  if ((uVar3 & 0x10) != 0 || bVar1) {
    *(undefined4 *)(puVar2 + 0x18) = 0x80;
    *(undefined4 *)(puVar2 + 0x18) = 0xa0;
    usb_sub_369ac();
    usb_sub_369a0();
    *puVar4 = 0x10;
  }
  *(undefined4 *)(puVar2 + 0x14) = 0;
  return uVar5;
}

/* ==========================================================================
 * usb_sub_36eee   @ 0x00036eee   (44 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, fWorkModeInit, single_wave, system_mode
 */

void usb_sub_36eee(int param_1)

{
  undefined *puVar1;
  
  puVar1 = usb_ro_36f28;
  *(uint *)(usb_ro_36f28 + 0x10) = *(uint *)(usb_ro_36f28 + 0x10) | 0x20000000;
  *(undefined4 *)(usb_ro_36f2c + 0x10) = *(undefined4 *)(puVar1 + 0x10);
  puVar1 = usb_ro_36f2c;
  *(uint *)(usb_ro_36f2c + 0x90) = param_1 << 7 | *(uint *)(usb_ro_36f2c + 0x90) & 0xfffff87f;
  *(undefined4 *)usb_ro_36f30 = *(undefined4 *)(puVar1 + 0x90);
  return;
}

/* ==========================================================================
 * usb_sub_36fe6   @ 0x00036fe6   (6 bytes)
 * called by : rxcsr2
 */

void usb_sub_36fe6(undefined1 param_1)

{
  shared_ro_37384[0xe] = param_1;
  return;
}

/* ==========================================================================
 * usb_sub_37078   @ 0x00037078   (78 bytes)
 * called by : usb_sub_37104, usb_sub_37186
 * calls     : rom_24F9C
 */

void usb_sub_37078(int param_1,uint param_2,uint param_3)

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
  puVar3 = (undefined4 *)(shared_ro_37384 + (param_1 * 4 + 0x20U & 0xff));
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
 * usb_sub_370c6   @ 0x000370c6   (10 bytes)
 * called by : usb_sub_37ab6, usb_sub_37b0a, flash_sub_38072, HID_RQT_Get_Protocol
 */

void usb_sub_370c6(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[0xe] = param_1;
  puVar1[0x11] = 0x20;
  return;
}

/* ==========================================================================
 * usb_sub_370d0   @ 0x000370d0   (14 bytes)
 * called by : usb_sub_37104, HID_RQT_Get_Protocol, _USB_macro2, f_usb_remote_wakeup
 */

void usb_sub_370d0(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[0xe] = param_1;
  puVar1[0x12] = 1;
  puVar1[0x11] = 10;
  return;
}

/* ==========================================================================
 * usb_sub_370ec   @ 0x000370ec   (14 bytes)
 * called by : HID_RQT_Get_Protocol
 */

void usb_sub_370ec(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[0xe] = param_1;
  puVar1[0x12] = 1;
  puVar1[0x11] = 0x40;
  return;
}

/* ==========================================================================
 * usb_sub_37104   @ 0x00037104   (130 bytes)
 * called by : usb_sub_37b0a, HID_RQT_Get_Protocol, _USB_macro2
 * calls     : usb_sub_37078, usb_sub_370d0, usb_sub_4245e, usb_sub_42472
 */

void usb_sub_37104(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*(byte *)(param_2 + 0xf) & 1) != 0) {
    uVar3 = (uint)*(ushort *)(param_2 + 8);
    if (uVar3 != 0) {
      iVar1 = usb_sub_4245e(param_2);
      uVar4 = (uint)*(ushort *)(param_2 + 0xc);
      if (uVar3 < uVar4) {
        *(undefined1 *)(param_2 + 8) = 0;
        *(undefined1 *)(param_2 + 9) = 0;
        *(undefined1 *)(param_2 + 0xe) = 3;
        usb_sub_42472(iVar1 + uVar3,param_2);
        usb_sub_37078(param_1,iVar1,uVar3);
        uVar2 = 10;
      }
      else {
        *(char *)(param_2 + 8) = (char)(uVar3 - uVar4);
        *(char *)(param_2 + 9) = (char)(uVar3 - uVar4 >> 8);
        *(undefined1 *)(param_2 + 0xe) = 1;
        usb_sub_42472(iVar1 + uVar4,param_2);
        usb_sub_37078(param_1,iVar1,uVar4);
        uVar2 = 2;
      }
      shared_ro_37384[0x11] = uVar2;
      return;
    }
    *(byte *)(param_2 + 0xf) = *(byte *)(param_2 + 0xf) ^ 1;
    usb_sub_370d0(param_1);
    *(undefined1 *)(param_2 + 0xe) = 3;
  }
  return;
}

/* ==========================================================================
 * usb_sub_37186   @ 0x00037186   (28 bytes)
 * called by : usb_sub_3870a, exist
 * calls     : usb_sub_37078
 */

void usb_sub_37186(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[0xe] = param_1;
  puVar1[0x11] = 8;
  usb_sub_37078();
  puVar1[0x11] = 1;
  puVar1[0x12] = puVar1[0x12] | 0x20;
  return;
}

/* ==========================================================================
 * usb_sub_3725e   @ 0x0003725e   (12 bytes)
 * called by : exist
 */

int usb_sub_3725e(void)

{
  return (uint)(byte)shared_ro_37384[0xc] + (uint)(byte)shared_ro_37384[0xd] * 0x100;
}

/* ==========================================================================
 * usb_sub_374e2   @ 0x000374e2   (38 bytes)
 * called by : usb_sub_37534
 * calls     : flash_sub_36fec, usb_sub_37830, usb_sub_37844
 */

void usb_sub_374e2(undefined4 param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  shared_ro_376a4[0xe] = (char)param_1;
  flash_sub_36fec();
  uVar1 = usb_sub_37830(param_1);
  pcVar2 = (code *)usb_sub_37844(param_1);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(uVar1,0);
  }
  return;
}

/* ==========================================================================
 * usb_sub_37508   @ 0x00037508   (44 bytes)
 * called by : usb_sub_37534
 * calls     : flash_sub_37004, usb_sub_3781e, usb_sub_37858
 */

void usb_sub_37508(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  shared_ro_376a4[0xe] = (char)param_1;
  uVar1 = usb_sub_3781e(param_1);
  uVar2 = flash_sub_37004(param_1,uVar1);
  pcVar3 = (code *)usb_sub_37858(param_1);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(uVar1,uVar2);
  }
  return;
}

/* ==========================================================================
 * usb_sub_37534   @ 0x00037534   (202 bytes)
 * called by : rf24_sub_375fe
 * calls     : usb_sub_374e2, usb_sub_37508, _USB_macro2, dbg_printf
 * string    : "BIT(0) f_usb_suspend =1------------\r\n"
 * string    : "BIT(1) f_usb_suspend =0------------\r\n"
 * string    : "BIT(2)bus reset ------------f_usb_isConnected ==%d\r\n"
 */

void usb_sub_37534(uint param_1,uint param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_2 & 1) == 0) {
    uVar4 = 1;
    do {
      uVar3 = 1 << (uVar4 & 0xff);
      if ((uVar3 & param_2) != 0) {
        usb_sub_374e2(uVar4);
      }
      if ((uVar3 & param_1) != 0) {
        usb_sub_37508(uVar4);
      }
      puVar2 = usb_ro_376b0;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x10);
    if (param_3 != 0) {
      if ((param_3 & 1) != 0) {
        *usb_ro_376b0 = 1;
        dbg_printf(str_BIT_0_f_usb_suspend_1);
        puVar1 = shared_ro_376a4;
        shared_ro_376a4[1] = 1;
        puVar1[0xf] = 0;
        (**(code **)usb_ro_376dc)();
      }
      if ((int)(param_3 << 0x1e) < 0) {
        *puVar2 = 0;
        dbg_printf(str_BIT_1_f_usb_suspend_0);
        puVar1 = shared_ro_376a4;
        shared_ro_376a4[1] = 0;
        puVar1[0xf] = 1;
      }
      if ((int)(param_3 << 0x1d) < 0) {
        *usb_ro_37708 = 0;
        *usb_ro_3770c = 0;
        *usb_ro_37710 = 1;
        dbg_printf(str_BIT_2_bus_reset_f_usb_isConnected_d,*usb_ro_37714);
        *usb_ro_37750 = 1;
        *usb_ro_37754 = 1;
        *usb_ro_37758 = 0;
        *usb_ro_3775c = 0;
        *usb_ro_37760 = 0;
        *usb_ro_37764 = 0;
        *puVar2 = 0;
        *usb_ro_37768 = 0;
        *shared_ro_376a4 = 0;
        *usb_ro_3776c = 0;
        *usb_ro_37770 = 0;
        return;
      }
    }
  }
  else {
    _USB_macro2();
    if (*(short *)shared_ro_376a8 != 0) {
      *(undefined2 *)shared_ro_376a8 = 0x41;
    }
    if (*usb_ro_376ac != '\0') {
      *usb_ro_376ac = 10;
    }
  }
  return;
}

/* ==========================================================================
 * usb_sub_37774   @ 0x00037774   (38 bytes)
 * called by : rxcsr2
 */

byte * usb_sub_37774(byte *param_1,int param_2,uint param_3,int param_4)

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
 * usb_sub_3781e   @ 0x0003781e   (18 bytes)
 * called by : usb_sub_37508
 */

undefined4 usb_sub_3781e(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(usb_ro_37bf0 + param_1 * 0x18);
}

/* ==========================================================================
 * usb_sub_37830   @ 0x00037830   (20 bytes)
 * called by : usb_sub_374e2
 */

undefined4 usb_sub_37830(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(usb_ro_37bf0 + param_1 * 0x18 + 8);
}

/* ==========================================================================
 * usb_sub_37844   @ 0x00037844   (20 bytes)
 * called by : usb_sub_374e2
 */

undefined4 usb_sub_37844(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(usb_ro_37bf0 + param_1 * 0x18 + 0x10);
}

/* ==========================================================================
 * usb_sub_37858   @ 0x00037858   (20 bytes)
 * called by : usb_sub_37508
 */

undefined4 usb_sub_37858(int param_1)

{
  if (5 < param_1) {
    return 0;
  }
  return *(undefined4 *)(usb_ro_37bf0 + param_1 * 0x18 + 0x14);
}

/* ==========================================================================
 * usb_sub_37878   @ 0x00037878   (66 bytes)
 * called by : rxcsr2
 * calls     : usb_sub_42a20, usb_sub_42a74, dbg_printf
 * string    : "ep%d RX Buf=0x%.8x\r\n"
 * string    : "Can't malloc RX Buf\r\n"
 */

void usb_sub_37878(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = usb_ro_37bf0;
  if (param_1 < 6) {
    iVar3 = param_1 * 0x18;
    *(undefined4 *)(usb_ro_37bf0 + iVar3 + 4) = 0;
    if (*(int *)(puVar1 + iVar3) != 0) {
      usb_sub_42a20();
      *(undefined4 *)(puVar1 + iVar3) = 0;
    }
    iVar2 = usb_sub_42a74(param_2);
    *(int *)(puVar1 + iVar3) = iVar2;
    if (iVar2 == 0) {
      dbg_printf(str_Can_t_malloc_RX_Buf);
      return;
    }
    dbg_printf(str_ep_d_RX_Buf_0x_8x,param_1);
  }
  return;
}

/* ==========================================================================
 * usb_sub_378ba   @ 0x000378ba   (64 bytes)
 * called by : rxcsr2
 * calls     : usb_sub_42a20, usb_sub_42a74, dbg_printf
 * string    : "ep%d TX Buf=0x%.8x\r\n"
 * string    : "Can't malloc TX Buf\r\n"
 */

void usb_sub_378ba(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = usb_ro_37bf0;
  if (param_1 < 6) {
    if (*(int *)(usb_ro_37bf0 + param_1 * 0x18 + 8) != 0) {
      usb_sub_42a20();
      *(undefined4 *)(puVar1 + param_1 * 0x18 + 8) = 0;
    }
    *(undefined4 *)(puVar1 + param_1 * 0x18 + 0xc) = 0;
    iVar2 = usb_sub_42a74(param_2);
    *(int *)(puVar1 + param_1 * 0x18 + 8) = iVar2;
    if (iVar2 == 0) {
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
 * calls     : usb_sub_36fe6, usb_sub_37774, usb_sub_37878, usb_sub_378ba, dbg_printf
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
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_20;
  
  puVar1 = usb_ro_37c58;
  iVar5 = 1;
  iVar4 = 0;
  while (iVar2 = usb_sub_37774(param_1,param_2,5,iVar5), iVar2 != 0) {
    iVar4 = iVar4 + 1;
    usb_sub_36fe6(*(byte *)(iVar2 + 2) & 0xf);
    if ((int)((uint)*(byte *)(iVar2 + 2) << 0x18) < 0) {
      puVar1[0x10] = (char)(*(ushort *)(iVar2 + 4) >> 3);
      puVar1[0x12] = 0x20;
      puVar1[0x11] = 8;
      if ((*(byte *)(iVar2 + 3) & 3) == 1) {
        puVar1[0x12] = puVar1[0x12] | 0x40;
      }
      uVar3 = (uint)*(byte *)(iVar2 + 2);
      if ((int)(uVar3 << 0x1c) < 0) {
        puVar1[8] = puVar1[8] | (byte)(1 << (uVar3 & 7));
      }
      else {
        puVar1[7] = puVar1[7] | (byte)(1 << (uVar3 & 7));
      }
      usb_sub_378ba(*(byte *)(iVar2 + 2) & 0xf,*(undefined2 *)(iVar2 + 4));
    }
    else {
      puVar1[0x13] = (char)(*(ushort *)(iVar2 + 4) >> 3);
      puVar1[0x12] = 0;
      puVar1[0x15] = 0;
      if ((*(byte *)(iVar2 + 3) & 3) == 1) {
        puVar1[0x15] = puVar1[0x15] | 0x40;
      }
      puVar1[0x14] = 0x80;
      uVar3 = (uint)*(byte *)(iVar2 + 2);
      if ((int)(uVar3 << 0x1c) < 0) {
        puVar1[10] = puVar1[10] | (byte)(1 << (uVar3 & 7));
      }
      else {
        puVar1[9] = puVar1[9] | (byte)(1 << (uVar3 & 7));
      }
      usb_sub_37878(*(byte *)(iVar2 + 2) & 0xf,*(undefined2 *)(iVar2 + 4));
    }
    iVar5 = iVar5 + 1;
    dbg_printf(str_endp_2x,*(undefined1 *)(iVar2 + 2));
    dbg_printf(str_rxp_2x,puVar1[0x13]);
    dbg_printf(str_txp_2x,puVar1[0x10]);
    dbg_printf(str_maxp_2x,*(undefined2 *)(iVar2 + 4));
    dbg_printf(str_csr0_2x,puVar1[0x11]);
    dbg_printf(str_csr02_2x,puVar1[0x12]);
    dbg_printf(str_rxcsr1_2x,puVar1[0x14]);
    dbg_printf(str_rxcsr2_2x,puVar1[0x15]);
  }
  dbg_printf(str_rxie1_2x,puVar1[9]);
  dbg_printf(str_rxie2_2x,puVar1[10]);
  dbg_printf(str_txie1_2x,puVar1[7]);
  dbg_printf(str_txie2_2x,puVar1[8]);
  *usb_ro_37d08 = 1;
  *usb_ro_37d0c = 1;
  *usb_ro_37d10 = 1;
  *usb_ro_37d14 = 1;
  return CONCAT44(uStack_20,iVar4);
}

/* ==========================================================================
 * pcfg   @ 0x00037a62   (38 bytes)
 * calls     : usb_sub_38350, usb_sub_4245e, dbg_printf, rxcsr2
 * string    : "pcfg=0x%.8x\r\n"
 */

void pcfg(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = usb_sub_38350();
  dbg_printf(str_pcfg_0x_8x,iVar1);
  uVar2 = usb_sub_4245e(iVar1 + 4);
  uVar3 = usb_sub_4245e(iVar1);
  rxcsr2(uVar3,uVar2);
  return;
}

/* ==========================================================================
 * usb_sub_37ab6   @ 0x00037ab6   (16 bytes)
 * calls     : usb_sub_370c6
 */

void usb_sub_37ab6(undefined4 param_1,int param_2)

{
  usb_sub_370c6(0);
  *(undefined1 *)(param_2 + 0xe) = 5;
  return;
}

/* ==========================================================================
 * usb_sub_37ac6   @ 0x00037ac6   (52 bytes)
 * called by : usb_sub_37b0a, HID_RQT_Get_Protocol
 * calls     : usb_sub_42472
 */

void usb_sub_37ac6(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = *(ushort *)(param_2 + 6);
  *(undefined *)(param_1 + 0xc) = shared_ro_37bf4[1];
  *(undefined1 *)(param_1 + 0xd) = 0;
  usb_sub_42472(param_3,param_1);
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
 * usb_sub_37afa   @ 0x00037afa   (8 bytes)
 * called by : HID_RQT_Get_Protocol
 */

byte usb_sub_37afa(byte *param_1)

{
  return *param_1 & 0x1f;
}

/* ==========================================================================
 * usb_sub_37b0a   @ 0x00037b0a   (92 bytes)
 * calls     : usb_sub_370c6, usb_sub_37104, usb_sub_37ac6
 */

void usb_sub_37b0a(byte *param_1,int param_2)

{
  byte bVar1;
  undefined *puVar2;
  
  bVar1 = *param_1 & 0x1f;
  if ((*param_1 & 0x1f) == 0) {
    puVar2 = shared_ro_37bf4 + 0xc;
  }
  else if (bVar1 == 1) {
    puVar2 = shared_ro_37bf4 + 0xe;
  }
  else {
    if (bVar1 != 2) goto LAB_00037b5a;
    puVar2 = usb_ro_37bf0 + (param_1[4] & 0xf) * 2 + -0xc;
  }
  if (puVar2 != (undefined *)0x0) {
    usb_sub_37ac6(param_2,param_1,puVar2,2);
    *(undefined1 *)(param_2 + 0xe) = 1;
    usb_sub_37104(0,param_2);
    return;
  }
LAB_00037b5a:
  *(undefined1 *)(param_2 + 0xe) = 5;
  usb_sub_370c6(0);
  return;
}

/* ==========================================================================
 * f_usb_remote_wakeup   @ 0x00037b66   (138 bytes)
 * calls     : usb_sub_370d0, dbg_printf
 * string    : "CLEAR_FEATURE rcp=%x\r\n"
 * string    : "f_usb_remote_wakeup =========0 clear %x,%x,%x,%x\r\n"
 */

void f_usb_remote_wakeup(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *param_1;
  bVar2 = bVar1 & 0x1f;
  dbg_printf(str_CLEAR_FEATURE_rcp_x,bVar2,param_3,param_4,param_4);
  if ((bVar1 & 0x1f) == 0) {
    if (*(short *)(param_1 + 2) == 1) {
      shared_ro_37bf4[0xc] = shared_ro_37bf4[0xc] & 0xfd;
      *usb_ro_37d40 = 0;
      dbg_printf(str_f_usb_remote_wakeup_0_clear_x_x_x_x,*usb_ro_37d50,*usb_ro_37d4c,*usb_ro_37d48,*usb_ro_37d44);
    }
  }
  else if ((bVar2 != 1) && (bVar2 == 2)) {
    if (*(short *)(param_1 + 2) == 0) {
      usb_ro_37bf0[(param_1[4] & 0xf) * 2 + -0xc] = usb_ro_37bf0[(param_1[4] & 0xf) * 2 + -0xc] & 0xfe;
    }
  }
  usb_sub_370d0(0);
  *(undefined1 *)(param_2 + 0xe) = 5;
  return;
}

/* ==========================================================================
 * usb_suspend   @ 0x000380a6   (116 bytes)
 * called by : system_mode
 * calls     : usb_sub_4245e, usb_sub_42472, dbg_printf
 * string    : "usb_suspend =1-----usb_frame_stop_cnt =%d\r\n"
 */

void usb_suspend(void)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar2 = usb_ro_38168;
  cVar1 = usb_ro_38234[0xc];
  usb_ro_38168[6] = cVar1;
  if (cVar1 == puVar2[7]) {
    if (*(short *)usb_ro_38238 == 0) {
      iVar3 = usb_sub_4245e(puVar2 + 8);
      usb_sub_42472(iVar3 + 1,puVar2 + 8);
    }
  }
  else {
    puVar2[7] = cVar1;
    usb_sub_42472(0,puVar2 + 8);
    puVar2[0xc] = 0;
  }
  puVar4 = (undefined *)usb_sub_4245e(puVar2 + 8);
  if ((usb_ro_3823c < puVar4) && (((usb_ro_38240 < puVar4 || (*usb_ro_3816c != '\0')) || (*usb_ro_38244 != '\0'))))
  {
    dbg_printf(str_usb_suspend_1_usb_frame_stop_cnt_d,puVar4);
    *usb_ro_38274 = 1;
    puVar2[0xc] = 1;
    usb_sub_42472(0,puVar2 + 8);
  }
  return;
}

/* ==========================================================================
 * usb_suspend_wakeup   @ 0x0003811a   (42 bytes)
 * called by : exist
 * calls     : usb_sub_317c2, usb_sub_42472, dbg_printf
 * string    : "usb_suspend_wakeup\r\n"
 */

void usb_suspend_wakeup(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar1 = usb_ro_38168;
  usb_ro_38168[0xc] = 0;
  usb_sub_42472(0,puVar1 + 8);
  dbg_printf(str_usb_suspend_wakeup);
  puVar2 = usb_ro_38234 + 0x80;
  *puVar2 = 0x21;
  usb_sub_317c2(0xd);
  *puVar2 = 9;
  return;
}

/* ==========================================================================
 * usb_sub_38296   @ 0x00038296   (20 bytes)
 * called by : exist
 */

void usb_sub_38296(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)usb_ro_38310 & ~((int)usb_ro_38310 << 0xb);
  }
  else {
    uVar1 = *(uint *)usb_ro_38310 | (int)usb_ro_38310 << 0xb;
  }
  *(uint *)usb_ro_38310 = uVar1;
  return;
}

/* ==========================================================================
 * usb_sub_38350   @ 0x00038350   (6 bytes)
 * called by : pcfg
 */

undefined * usb_sub_38350(void)

{
  return shared_ro_38394 + 8;
}

/* ==========================================================================
 * usb_sub_38384   @ 0x00038384   (54 bytes)
 * calls     : usb_sub_4245e
 */

undefined * usb_sub_38384(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = shared_ro_38394;
  iVar3 = 0;
  while( true ) {
    if (3 < iVar3) {
      return (undefined *)0x0;
    }
    iVar2 = usb_sub_4245e(puVar1 + iVar3 * 0xc + 0x10);
    if (iVar2 == param_1) break;
    iVar3 = iVar3 + 1;
  }
  return puVar1 + iVar3 * 0xc + 0x14;
}

/* ==========================================================================
 * usb_sub_38398   @ 0x00038398   (40 bytes)
 * called by : HID_RQT_Get_Protocol
 * calls     : usb_sub_42472
 */

void usb_sub_38398(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)(param_2 + 6);
  *(undefined *)(param_1 + 0xc) = *usb_ro_385a4;
  *(undefined1 *)(param_1 + 0xd) = 0;
  usb_sub_42472(param_3,param_1 + 4);
  *(char *)(param_1 + 10) = (char)uVar1;
  *(char *)(param_1 + 0xb) = (char)((ushort)uVar1 >> 8);
  *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 2;
  return;
}

/* ==========================================================================
 * HID_RQT_Get_Protocol   @ 0x000383c0   (482 bytes)
 * called by : flash_sub_38072
 * calls     : usb_sub_370c6, usb_sub_370d0, usb_sub_370ec, usb_sub_37104, usb_sub_37ac6, usb_sub_37afa, ... (+5 more)
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
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte bVar5;
  uint uVar6;
  undefined *puVar7;
  undefined1 uVar8;
  
  uVar6 = usb_sub_37afa(param_1);
  puVar4 = usb_ro_385b4;
  puVar3 = usb_ro_385b0;
  puVar7 = usb_ro_385ac;
  puVar2 = usb_ro_385a8;
  if ((uVar6 < 3) && (uVar6 != 0)) {
    if (uVar6 == 1) {
      cVar1 = *(char *)(param_1 + 4);
      if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
        cVar1 = *(char *)(param_1 + 1);
        if (cVar1 == '\n') {
          *usb_ro_385a8 = 1;
          *puVar7 = *(undefined1 *)(param_1 + 3);
          dbg_printf(str_set_idle_x_x,*(undefined1 *)(param_1 + 2));
        }
        else {
          if (cVar1 == '\x02') {
            dbg_printf(str_Get_idle_length_x_x_in,*(undefined1 *)(param_1 + 6),*usb_ro_385ac);
            puVar7 = usb_ro_385ac;
            uVar8 = 1;
            *puVar2 = 1;
LAB_00038490:
            usb_sub_37ac6(param_2,param_1,puVar7,uVar8);
            *(undefined1 *)(param_2 + 0xe) = 1;
            usb_sub_37104(0,param_2);
            return;
          }
          if (cVar1 == '\x01') {
            dbg_printf_2(str_HID_RQT_Get_Report,param_1,8);
            puVar7 = usb_ro_3860c;
            puVar2 = usb_ro_385fc;
            cVar1 = *(char *)(param_1 + 2);
            if (cVar1 == -0x60) {
              *usb_ro_3860c = 0xa0;
              if (*puVar2 == '\0') {
                puVar7[1] = 0;
              }
              else {
                puVar7[1] = 1;
              }
              puVar7[2] = 0;
              puVar7[3] = 0;
              puVar7[4] = 0;
              puVar7[5] = 0;
              puVar7[6] = 0;
              uVar8 = 8;
              puVar7[7] = 0;
              puVar7 = usb_ro_3860c;
            }
            else {
              if (*usb_ro_385fc == '\0') {
                return;
              }
              *usb_ro_385fc = 0;
              *usb_ro_38600 = 1;
              puVar2 = usb_ro_385b0;
              usb_ro_385b0[-7] = cVar1;
              *usb_ro_38604 = *(undefined1 *)(param_1 + 4);
              puVar7 = usb_ro_38608;
              *usb_ro_38608 = *(undefined1 *)(param_1 + 6);
              *(undefined **)(puVar2 + -5) = puVar3;
              rom_24F9C(usb_ro_3860c,puVar3);
              uVar8 = *puVar7;
              puVar7 = usb_ro_3860c;
            }
            goto LAB_00038490;
          }
          if (cVar1 == '\t') {
            dbg_printf_2(str_HID_RQT_Set_Report,param_1,8);
            puVar2 = usb_ro_385b0;
            if ((*(char *)(param_1 + 3) == '\x03') && (*(char *)(param_1 + 4) == '\x02')) {
              if (*(char *)(param_1 + 2) == -0x60) {
                usb_ro_385b0[-8] = 2;
                *usb_ro_38608 = *(undefined1 *)(param_1 + 6);
                *(undefined **)usb_ro_38628 = puVar3;
              }
              else {
                usb_ro_385b0[-8] = 1;
                puVar2[-7] = *(undefined1 *)(param_1 + 2);
                puVar2[-6] = *(undefined1 *)(param_1 + 6);
                if (*usb_ro_38624 == '\0') {
                  *(undefined **)(puVar2 + -5) = puVar3;
                }
              }
              *usb_ro_3862c = 0x3c;
            }
            *usb_ro_38630 = 0xf;
            OLED_Init();
            usb_sub_38398(param_2,param_1,usb_ro_3860c + -0x85,*usb_ro_38608);
            usb_sub_370ec(0);
            *(undefined1 *)(param_2 + 0xe) = 2;
            return;
          }
          if (cVar1 != '\v') {
            if (cVar1 == '\x03') {
              dbg_printf_2(str_HID_RQT_Get_Protocol,param_1,8);
              puVar7 = usb_ro_385b4;
              if (*usb_ro_38650 == '\0') {
                bVar5 = *puVar4 & 0xfe;
              }
              else {
                bVar5 = *puVar4 | 1;
              }
              uVar8 = 1;
              *puVar4 = bVar5;
              goto LAB_00038490;
            }
            goto LAB_00038576;
          }
          dbg_printf_2(str_HID_RQT_Set_Protocol,param_1,8);
          *usb_ro_3864c = 1;
          bVar5 = *(byte *)(param_1 + 2);
          *puVar4 = bVar5;
          if ((bVar5 & 1) == 0) {
            *usb_ro_38650 = 0;
          }
          else {
            *usb_ro_38650 = 1;
          }
        }
        *(undefined1 *)(param_2 + 0xe) = 4;
LAB_00038576:
        usb_sub_370d0(0);
        return;
      }
    }
    else if (uVar6 != 2) {
      return;
    }
    *(undefined1 *)(param_2 + 0xe) = 5;
  }
  usb_sub_370c6(0);
  return;
}

/* ==========================================================================
 * usb_sub_3870a   @ 0x0003870a   (556 bytes)
 * called by : system_mode
 * calls     : led_sub_31244, ble_sub_312aa, usb_sub_37186, rom_24F9C, rom_24FEC, time_sensor_invalid
 */

void usb_sub_3870a(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined4 in_r3;
  
  puVar12 = usb_ro_38aa0;
  if (*usb_ro_38a8c == '\0') {
    return;
  }
  if (*(short *)usb_ro_38a90 != 0) {
    return;
  }
  if (*usb_ro_38a94 != '\0') {
    return;
  }
  if (*usb_ro_38a98 != '\0') {
    return;
  }
  if (*usb_ro_38a9c == '\b') {
    *usb_ro_38a9c = 7;
    *usb_ro_38aa4 = 1;
    puVar3 = usb_ro_38aa8;
    *puVar12 = 1;
    *puVar3 = 1;
    *usb_ro_38aac = 1;
  }
  if (usb_ro_38ab0[0x16] != '\x01') {
    if (*usb_ro_38ab4 == '\0') {
      return;
    }
    *usb_ro_38ab4 = 0;
  }
  puVar3 = usb_ro_38ab8;
  if ((*puVar12 - 1 & *usb_ro_38ab8) == 0) {
    time_sensor_invalid();
  }
  puVar10 = usb_ro_38b04;
  puVar9 = usb_ro_38ae0;
  puVar8 = usb_ro_38adc;
  puVar7 = usb_ro_38ad8;
  puVar6 = usb_ro_38acc;
  puVar5 = usb_ro_38ac0;
  puVar4 = usb_ro_38abc;
  if (*usb_ro_38abc == '\0') {
    if ((*usb_ro_38aac == '\0') || (*usb_ro_38acc == '\0')) {
      if ((*usb_ro_38aa8 == '\0') ||
         ((((*usb_ro_38ad4 == '\0' && (*usb_ro_38ad8 == '\0')) && (*usb_ro_38adc == '\0')) &&
          (*usb_ro_38ae0 == '\0')))) {
        if ((((*usb_ro_38af4 == '\0') && (*usb_ro_38af8 == '\0')) && (*usb_ro_38afc == '\0')) &&
           (*usb_ro_38b00 == '\0')) {
          return;
        }
        if ((*puVar12 == '\0') && (*puVar3 != '\0')) {
          return;
        }
        *puVar12 = 0;
        puVar4 = usb_ro_38b10;
        puVar3 = usb_ro_38b0c;
        puVar12 = usb_ro_38b08;
        if (*puVar10 == '\0') {
          if ((-1 < *(short *)usb_ro_38b0c * 0x10000) && ((int)*(short *)usb_ro_38b0c << 0x18 < 0)) {
            *(undefined2 *)usb_ro_38b0c = 0x7f;
          }
          if ((-1 < (int)*(short *)puVar4 << 0x10) && ((int)*(short *)puVar4 << 0x18 < 0)) {
            *(undefined2 *)puVar4 = 0x7f;
          }
          uVar13 = 3;
          *puVar5 = *puVar12;
          puVar5[1] = *puVar3;
          puVar5[2] = *puVar4;
        }
        else {
          led_sub_31244();
          *puVar5 = *puVar12;
          uVar2 = *(undefined2 *)puVar3;
          puVar5[1] = (char)uVar2;
          puVar5[2] = (char)((ushort)uVar2 >> 8);
          uVar2 = *(undefined2 *)puVar4;
          puVar5[3] = (char)uVar2;
          puVar5[4] = (char)((ushort)uVar2 >> 8);
          uVar13 = 7;
          puVar5[5] = *usb_ro_38b14;
          puVar5[6] = *usb_ro_38b18;
        }
        usb_sub_37186(2,usb_ro_38ac0,uVar13);
        ble_sub_312aa();
        return;
      }
      *usb_ro_38aa8 = 0;
      if (*usb_ro_38ad4 == '\0') {
        if (*puVar7 == '\0') {
          cVar1 = *puVar8;
          if (cVar1 == '\0') {
            if (*puVar9 == '\0') {
              return;
            }
            *puVar9 = 0;
            *puVar5 = 3;
            rom_24F9C(puVar5 + 1,usb_ro_38af0,4,0,in_r3);
            usb_sub_37186(3,usb_ro_38ac0,5);
            puVar12 = usb_ro_38af0;
          }
          else {
            *puVar8 = 0;
            *puVar5 = 3;
            rom_24F9C(puVar5 + 1,usb_ro_38aec,4,cVar1,in_r3);
            usb_sub_37186(3,usb_ro_38ac0,5);
            puVar12 = usb_ro_38aec;
          }
          rom_24FEC(puVar12,4);
        }
        else {
          *puVar7 = 0;
          *puVar5 = 1;
          puVar3 = usb_ro_38ae8;
          puVar12 = usb_ro_38ac0;
          usb_ro_38ac0[1] = *usb_ro_38ae8;
          usb_sub_37186(3,puVar12,2);
          *puVar3 = 0;
        }
        goto LAB_000387ce;
      }
      *usb_ro_38ad4 = 0;
      puVar3 = usb_ro_38ae4;
      *puVar5 = 2;
      puVar12 = usb_ro_38ac0;
      usb_ro_38ac0[1] = *puVar3;
      uVar11 = 3;
      puVar12[2] = puVar3[1];
      uVar13 = uVar11;
    }
    else {
      *usb_ro_38aac = 0;
      *puVar6 = 0;
      rom_24F9C(usb_ro_38ac0,usb_ro_38ad0,0xe);
      uVar11 = 4;
      puVar12 = usb_ro_38ac0;
      uVar13 = 0xe;
    }
  }
  else {
    if ((*usb_ro_38aa4 == '\0') && (*usb_ro_38ac4 != '\0')) {
      return;
    }
    *usb_ro_38aa4 = 0;
    *puVar4 = 0;
    puVar12 = usb_ro_38ac8 + 1;
    *puVar5 = *usb_ro_38ac8;
    puVar5[1] = 0;
    rom_24F9C(puVar5 + 2,puVar12,6);
    uVar11 = 1;
    puVar12 = usb_ro_38ac0;
    uVar13 = 8;
  }
  usb_sub_37186(uVar11,puVar12,uVar13);
LAB_000387ce:
  rom_24FEC(usb_ro_38ac0,0x40);
  return;
}

/* ==========================================================================
 * usb_sub_38936   @ 0x00038936   (56 bytes)
 * called by : exist
 * calls     : rf24_sub_31784
 */

undefined4 usb_sub_38936(void)

{
  undefined *puVar1;
  char cVar2;
  byte bVar3;
  
  puVar1 = usb_ro_38b1c;
  bVar3 = 0;
  cVar2 = '\n';
  while (cVar2 != '\0') {
    if ((*(uint *)(puVar1 + 0x30) & 1) == 0) {
      bVar3 = bVar3 + 1;
    }
    rf24_sub_31784(500);
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
 * calls     : power_sub_2b128, usb_sub_2b382, power_sub_2bcac, usb_sub_31230, ble_sub_312aa, usb_sub_312de, ... (+22 more)
 * string    : "USB sleep_wakeup  f_usb_suspend=%x, f_usb_idle=%x,%x\r\n"
 * string    : "enter sleep........%x,%x,%x,%x,%x\r\n"
 * string    : "exist sleep........%x,%x,%x,%x,%x\r\n"
 */

void exist(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  byte bVar9;
  
  if (((*usb_ro_38a8c != '\0') && (iVar5 = power_sub_2b128(), iVar5 == 0)) && (*usb_ro_38b20 != '\0')) {
    *usb_ro_38b20 = 0;
    dbg_printf(str_USB_sleep_wakeup_f_usb_suspend_x_f_usb_idle,*usb_ro_38a98,*usb_ro_38b24,*usb_ro_38a9c,param_2
               ,param_3,param_4);
    usb_sub_3afa2(1);
    usb_sub_317c2(10);
    *usb_ro_38b08 = 0;
    ble_sub_312aa();
    usb_sub_312de();
    usb_sub_31230();
    power_sub_3297e();
    *usb_ro_38b60 = 1;
    if (usb_ro_38ab0[8] == '\0') {
      sensor_pwdn();
    }
    power_sub_33cfc();
    power_sub_3bf0a();
    usb_sub_3c286(1);
    usb_sub_3b528();
    *usb_ro_38b68 = *usb_ro_38b64;
    *usb_ro_38b6c = 0;
    do {
      puVar4 = usb_ro_38b64;
      puVar3 = usb_ro_38b24;
      puVar2 = usb_ro_38a98;
      puVar1 = usb_ro_38a68;
      dbg_printf(str_enter_sleep_x_x_x_x_x,*usb_ro_38b64,*usb_ro_38a98,*usb_ro_38b24,*usb_ro_38b70,*usb_ro_38a68);
      usb_sub_38296(0);
      *usb_ro_38b98 = 1;
      power_sub_2bcac();
      ble_sub_3af8a();
      power_sub_3bf0a();
      usb_sub_2b382();
      usb_sub_38296(1);
      dbg_printf(str_exist_sleep_x_x_x_x_x,*puVar4,*puVar2,*puVar3,*usb_ro_38b70,*puVar1);
      rf24_sub_31784(200);
      sVar8 = 400;
      uVar6 = usb_sub_3725e();
      puVar1 = usb_ro_38b6c;
      uVar6 = uVar6 & 0xffff;
      bVar9 = 0x97;
      while (sVar8 = sVar8 + -1, sVar8 != 0) {
        if (((*(int *)usb_ro_38f84 << 3 < 0) || ((*(uint *)(shared_ro_38f88 + 0x30) & 1) == 0)) &&
           (iVar5 = usb_sub_38936(), iVar5 != 0)) {
          rf24_sub_3b130();
        }
        if (*puVar1 != '\0') break;
        usb_sub_317c2(0x24);
        uVar7 = usb_sub_3725e();
        if (uVar7 == uVar6) {
          if (*usb_ro_38f90 != '\0') {
            if (bVar9 < 0x95) {
              sVar8 = 0;
              break;
            }
            usb_suspend_wakeup();
            *(undefined2 *)usb_ro_38f94 = 0x50;
            usb_sub_317c2(100);
            rom_24FEC(usb_ro_38f98,0x40);
            usb_sub_37186(2,usb_ro_38f98,7);
          }
        }
        else {
          uVar6 = usb_sub_3725e();
          bVar9 = bVar9 - 1;
          uVar6 = uVar6 & 0xffff;
          if ((bVar9 == 0) || ((*usb_ro_38f8c != '\0' && (bVar9 < 0x8d)))) break;
        }
      }
      if (*puVar1 != '\0') {
        *(undefined2 *)usb_ro_38f94 = 300;
        *(undefined2 *)usb_ro_38f9c = 200;
        break;
      }
    } while (sVar8 == 0);
    usb_sub_3afa2(5);
    usb_sub_317c2(5);
    *usb_ro_38fa0 = 0;
    flash_sub_3c2c6();
    usb_sub_317c2(1);
    led_sub_3beb4();
    ble_sub_3b538(usb_ro_38fa4);
    *usb_ro_38fa8 = 0;
    *usb_ro_38fac = 0;
    OLED_Init();
    *usb_ro_38fb0 = 8;
    puVar1 = usb_ro_38fb4;
    if (*usb_ro_38fb4 == '\0') {
      *usb_ro_38fb8 = 1;
      *usb_ro_38fbc = 1;
      *usb_ro_38fc0 = 1;
    }
    *puVar1 = 0;
  }
  return;
}

/* ==========================================================================
 * test   @ 0x00038cb6   (26 bytes)
 * called by : system_mode
 * calls     : rf24_sub_3b130, dbg_printf
 * string    : "test-zzl usb soft pull out then insert in\r\n"
 */

void test(void)

{
  if (*(short *)usb_ro_38f9c == 1) {
    *(undefined2 *)usb_ro_38f9c = 0;
    dbg_printf(str_test_zzl_usb_soft_pull_out_then_insert_in);
    rf24_sub_3b130();
  }
  return;
}

/* ==========================================================================
 * get_usb_insert_status   @ 0x00038cd0   (78 bytes)
 * called by : SLEEP, USNDP_status_2, enter_BLE_normal_app_mode, gpio
 * calls     : rf24_sub_31784, dbg_printf
 * string    : "get_usb_insert_status"
 * string    : "%s,USB_In =%x\r\n"
 */

undefined4 get_usb_insert_status(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = shared_ro_38f88;
  uVar2 = 0;
  *(undefined4 *)(shared_ro_38f88 + 0x30) = 0x2c;
  rf24_sub_31784(0xfa);
  if (((((*(uint *)(puVar1 + 0x30) & 1) != 0) &&
       (rf24_sub_31784(0xfa), (*(uint *)(puVar1 + 0x30) & 1) != 0)) &&
      (rf24_sub_31784(0xfa), (*(uint *)(puVar1 + 0x30) & 1) != 0)) &&
     (rf24_sub_31784(0xfa), (*(uint *)(puVar1 + 0x30) & 1) != 0)) {
    uVar2 = 1;
    dbg_printf(str_s_USB_In_x,shared_ro_38ff0,*(uint *)(puVar1 + 0x30) & 1);
  }
  return uVar2;
}

/* ==========================================================================
 * USNDP_status   @ 0x00038d1e   (134 bytes)
 * called by : SLEEP, USNDP_status_2, f_usb_isConnected
 * calls     : rf24_sub_31784, ble_sub_39a84, usb_sub_39ad8, dbg_printf
 * string    : "USBDN=:%x\r\n"
 * string    : "USNDP_status=:%x,USB_OTG_CFG=:%x,%x\r\n"
 */

undefined4 USNDP_status(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  byte bVar5;
  
  puVar1 = shared_ro_39004;
  bVar5 = 0;
  *shared_ro_39004 = 0;
  dbg_printf(str_USBDN_x);
  ble_sub_39a84(0,0);
  rf24_sub_31784(5);
  do {
    uVar2 = usb_sub_39ad8(0);
    puVar4 = (uint *)(shared_ro_38f88 + -0x40);
    if (((((*puVar4 & 1) == 0) || ((*puVar4 & 1) == 0)) || ((*puVar4 & 1) == 0)) ||
       ((*puVar4 & 1) == 0)) {
      uVar2 = 0;
      rf24_sub_31784(5);
    }
    rf24_sub_31784(5);
    uVar3 = *puVar4;
    dbg_printf(str_USNDP_status_x_USB_OTG_CFG_x_x,uVar2,*puVar1,bVar5);
    bVar5 = bVar5 + 1;
  } while ((uVar2 != (uVar3 & 1)) && (bVar5 < 10));
  ble_sub_39a84(0,0,1);
  if (uVar2 != 0) {
    return 1;
  }
  return 0;
}

/* ==========================================================================
 * usb_sub_39ad8   @ 0x00039ad8   (24 bytes)
 * called by : USNDP_status
 */

uint usb_sub_39ad8(uint param_1)

{
  return *(uint *)(shared_ro_39c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4) & 1;
}

/* ==========================================================================
 * usb_sub_39c84   @ 0x00039c84   (60 bytes)
 * called by : fn24main
 */

void usb_sub_39c84(void)

{
  undefined *puVar1;
  
  puVar1 = usb_ro_3a008;
  *(uint *)(usb_ro_3a008 + 8) = *(uint *)(usb_ro_3a008 + 8) & 0xf7ffffff;
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x4000;
  *(undefined4 *)(usb_ro_3a00c + 8) = *(undefined4 *)(puVar1 + 8);
  puVar1 = usb_ro_3a00c;
  *(undefined4 *)(usb_ro_3a00c + 0xb0) = usb_ro_3a010;
  *(undefined4 *)(puVar1 + 0xb4) = usb_ro_3a014;
  puVar1 = usb_ro_3a00c;
  *(uint *)(usb_ro_3a00c + 0xe8) = *(uint *)(usb_ro_3a00c + 0xe8) | 0x4000;
  *(uint *)(puVar1 + 0xec) = *(uint *)(puVar1 + 0xec) & 0xfffffff3;
  return;
}

/* ==========================================================================
 * usb_sub_39cfc   @ 0x00039cfc   (42 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, cal_data
 * calls     : ble_sub_3e552
 */

uint usb_sub_39cfc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),1);
  local_10 = param_3;
  iVar1 = ble_sub_3e552(10,&local_c,&local_10);
  uVar2 = 0x35;
  if ((iVar1 == 0) && ((local_10 & 0xff) - 0x16 < 0x3f)) {
    uVar2 = local_10 & 0xff;
  }
  return uVar2;
}

/* ==========================================================================
 * usb_sub_39d26   @ 0x00039d26   (22 bytes)
 * called by : TEST_SINGLE_WAVE
 * calls     : ble_sub_3e5f0
 */

void usb_sub_39d26(int param_1)

{
  if (param_1 - 0x16U < 0x3f) {
    ble_sub_3e5f0(10,1);
  }
  return;
}

/* ==========================================================================
 * usb_sub_39d3c   @ 0x00039d3c   (24 bytes)
 * called by : cal_data
 */

void usb_sub_39d3c(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = usb_ro_3a008;
  if (0x7f < param_1) {
    param_1 = 0x7f;
  }
  *(uint *)(usb_ro_3a008 + 0xc) = param_1 << 0xc | usb_ro_3a020;
  *(undefined4 *)(usb_ro_3a00c + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  return;
}

/* ==========================================================================
 * usb_sub_39dfe   @ 0x00039dfe   (40 bytes)
 * called by : cal_data
 * calls     : usb_sub_317c2
 */

void usb_sub_39dfe(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = usb_ro_3a008;
  *(uint *)(usb_ro_3a008 + 0x78) = *(uint *)(usb_ro_3a008 + 0x78) | 0x20000;
  puVar2 = usb_ro_3a00c;
  *(undefined4 *)(usb_ro_3a00c + 0x78) = *(undefined4 *)(puVar1 + 0x78);
  usb_sub_317c2(2);
  *(uint *)(puVar1 + 0x78) = *(uint *)(puVar1 + 0x78) & 0xfffdffff;
  *(undefined4 *)(puVar2 + 0x78) = *(undefined4 *)(puVar1 + 0x78);
  return;
}

/* ==========================================================================
 * value_kcal_result   @ 0x00039e26   (444 bytes)
 * called by : cal_data
 * calls     : usb_sub_317c2, KEY_piaring_cnt, dbg_printf, rom_24F24
 * string    : "value_kcal_result=%x\r\n"
 */

void value_kcal_result(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(usb_ro_3a00c + 0xc0);
  *puVar4 = *puVar4 & 0xfffffffc;
  *puVar4 = *puVar4 | 8;
  puVar2 = usb_ro_3a00c;
  *(uint *)(usb_ro_3a00c + 0x90) = *(uint *)(usb_ro_3a00c + 0x90) | 0x40000000;
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) | 0x80000000;
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) & 0xfffdffff;
  usb_sub_317c2(10);
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) & 0xffffff80;
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) | 2;
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) | 0x1000;
  usb_sub_317c2(10);
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) | 0x2000;
  usb_sub_317c2(10);
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) | 0x800;
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  puVar1 = usb_ro_3a008;
  *(uint *)(usb_ro_3a008 + 0xc) = *(uint *)(usb_ro_3a008 + 0xc) & 0xffffffbf;
  *(undefined4 *)(usb_ro_3a00c + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  usb_sub_317c2(10);
  *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) | 0x80;
  *(undefined4 *)(usb_ro_3a00c + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) | 0x10000;
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  uVar3 = rom_24F24(&rom_ro_1f400,(*(uint *)(usb_ro_3a00c + 0x48) & 0x1fffffff) >> 0x10);
  uVar3 = uVar3 & 0x1ff;
  dbg_printf(str_value_kcal_result_x,uVar3);
  *puVar4 = *puVar4 & usb_ro_3a05c;
  *puVar4 = *puVar4 | uVar3 << 8;
  *(uint *)usb_ro_3a060 = uVar3;
  usb_sub_317c2(10);
  usb_sub_317c2(10);
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) & 0xfffeffff;
  *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) & 0xffffff7f;
  *(undefined4 *)(usb_ro_3a00c + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  usb_sub_317c2(10);
  *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) | 0x40;
  *(undefined4 *)(usb_ro_3a00c + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) & 0xfffff7ff;
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) & 0xffffdfff;
  *(uint *)(puVar2 + 0x94) = *(uint *)(puVar2 + 0x94) & 0xffffefff;
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) | 0x20000;
  *puVar4 = *puVar4 | 1;
  *puVar4 = *puVar4 & 0xfffffff7;
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) & 0xbfffffff;
  *(uint *)(puVar2 + 0x90) = *(uint *)(puVar2 + 0x90) & 0x7fffffff;
  return;
}

/* ==========================================================================
 * cal_data   @ 0x00039fe2   (496 bytes)
 * called by : ble_sub_3a244
 * calls     : ble_sub_28c48, usb_sub_317c2, usb_sub_39cfc, usb_sub_39d3c, usb_sub_39dfe, KEY_piaring_cnt, ... (+3 more)
 * string    : "cal_data============================ %x\r\n"
 */

void cal_data(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  uVar7 = usb_ro_3a064;
  puVar2 = usb_ro_3a00c;
  *(undefined4 *)usb_ro_3a00c = usb_ro_3a064;
  puVar1 = usb_ro_3a008;
  *(undefined4 *)usb_ro_3a008 = uVar7;
  iVar6 = ble_sub_28c48();
  uVar7 = usb_ro_3a468;
  if (iVar6 != 1) {
    uVar7 = usb_ro_3a068;
  }
  *(undefined4 *)(puVar2 + 4) = uVar7;
  *(undefined4 *)(puVar1 + 4) = uVar7;
  uVar7 = usb_ro_3a46c;
  *(undefined4 *)(puVar2 + 8) = usb_ro_3a46c;
  *(undefined4 *)(puVar1 + 8) = uVar7;
  uVar7 = usb_ro_3a470;
  *(undefined4 *)(puVar2 + 0xc) = usb_ro_3a470;
  *(undefined4 *)(puVar1 + 0xc) = uVar7;
  iVar6 = ble_sub_28c48();
  uVar7 = usb_ro_3a478;
  if (iVar6 != 1) {
    uVar7 = usb_ro_3a474;
  }
  *(undefined4 *)(puVar2 + 0x10) = uVar7;
  *(undefined4 *)(puVar1 + 0x10) = uVar7;
  uVar7 = usb_ro_3a47c;
  *(undefined4 *)(puVar2 + 0x14) = usb_ro_3a47c;
  *(undefined4 *)(puVar1 + 0x14) = uVar7;
  uVar7 = usb_ro_3a480;
  *(undefined4 *)(puVar2 + 0x18) = usb_ro_3a480;
  *(undefined4 *)(puVar1 + 0x18) = uVar7;
  uVar7 = usb_ro_3a484;
  *(undefined4 *)(puVar2 + 0x1c) = usb_ro_3a484;
  *(undefined4 *)(puVar1 + 0x1c) = uVar7;
  uVar7 = usb_ro_3a488;
  *(undefined4 *)(puVar2 + 0x20) = usb_ro_3a488;
  *(undefined4 *)(puVar1 + 0x20) = uVar7;
  uVar7 = usb_ro_3a48c;
  *(undefined4 *)(puVar2 + 0x24) = usb_ro_3a48c;
  *(undefined4 *)(puVar1 + 0x24) = uVar7;
  uVar7 = usb_ro_3a490;
  *(undefined4 *)(puVar2 + 0x28) = usb_ro_3a490;
  *(undefined4 *)(puVar1 + 0x28) = uVar7;
  uVar7 = usb_ro_3a494;
  *(undefined4 *)(puVar2 + 0x2c) = usb_ro_3a494;
  *(undefined4 *)(puVar1 + 0x2c) = uVar7;
  uVar7 = usb_ro_3a498;
  *(undefined4 *)(puVar2 + 0x30) = usb_ro_3a498;
  *(undefined4 *)(puVar1 + 0x30) = uVar7;
  uVar7 = usb_ro_3a49c;
  *(undefined4 *)(puVar2 + 0x34) = usb_ro_3a49c;
  *(undefined4 *)(puVar1 + 0x34) = uVar7;
  uVar7 = usb_ro_3a4a0;
  *(undefined4 *)(puVar2 + 0x38) = usb_ro_3a4a0;
  *(undefined4 *)(puVar1 + 0x38) = uVar7;
  uVar7 = usb_ro_3a4a4;
  *(undefined4 *)(puVar2 + 0x3c) = usb_ro_3a4a4;
  *(undefined4 *)(puVar1 + 0x3c) = uVar7;
  puVar3 = usb_ro_3a4ac;
  uVar7 = usb_ro_3a4a8;
  *(undefined4 *)(usb_ro_3a4ac + 0x30) = usb_ro_3a4a8;
  *(undefined4 *)(puVar1 + 0x70) = uVar7;
  uVar7 = usb_ro_3a4b0;
  *(undefined4 *)(puVar3 + 0x34) = usb_ro_3a4b0;
  *(undefined4 *)(puVar1 + 0x74) = uVar7;
  uVar7 = usb_ro_3a4b4;
  *(undefined4 *)(puVar3 + 0x38) = usb_ro_3a4b4;
  *(undefined4 *)(puVar1 + 0x78) = uVar7;
  *(undefined4 *)(puVar3 + 0x3c) = 0;
  *(undefined4 *)(puVar1 + 0x7c) = 0;
  puVar4 = usb_ro_3a4ac;
  puVar8 = (undefined4 *)(usb_ro_3a4ac + 0x40);
  *puVar8 = usb_ro_3a4b8;
  *(undefined4 *)(puVar4 + 0x44) = 0x96000000;
  *(undefined4 *)(puVar4 + 0x48) = 0x78000000;
  *(int *)(puVar4 + 0x4c) = (int)puVar8 * 0x400000;
  *(undefined4 *)(puVar4 + 0x50) = usb_ro_3a4bc;
  *(undefined4 *)(puVar4 + 0x54) = 0x200000;
  *(undefined4 *)(puVar4 + 0x58) = usb_ro_3a4c0;
  *(undefined4 *)(puVar4 + 0x5c) = usb_ro_3a4c4;
  *(undefined4 *)(puVar4 + 0x60) = usb_ro_3a4c8;
  *(undefined4 *)(puVar4 + 100) = usb_ro_3a4cc;
  *(undefined4 *)(puVar4 + 0x68) = usb_ro_3a4d0;
  *(undefined4 *)(puVar4 + 0x6c) = 0x408;
  *(undefined4 *)(puVar4 + 0x74) = usb_ro_3a4d4;
  uVar9 = (int)puVar8 >> 0xf;
  *(uint *)(puVar4 + 0x78) = uVar9;
  *(undefined4 *)(puVar4 + 0x7c) = 0;
  puVar4 = usb_ro_3a4ac;
  *(undefined4 *)(usb_ro_3a4ac + 0x80) = usb_ro_3a4d8;
  *(undefined4 *)(puVar4 + 0x84) = 0;
  *(undefined4 *)(puVar4 + 0x88) = 0;
  *(undefined4 *)(puVar4 + 0x8c) = 0;
  *(undefined4 *)(puVar4 + 0x90) = 0;
  *(undefined4 *)(puVar4 + 0x94) = 0;
  *(undefined4 *)(puVar4 + 0x98) = 0;
  *(undefined4 *)(puVar4 + 0x9c) = 0;
  *(undefined4 *)(puVar4 + 0xa0) = 0;
  *(undefined4 *)(puVar4 + 0xa4) = 0;
  *(undefined4 *)(puVar4 + 0xa8) = 0x128000;
  *(undefined4 *)(puVar4 + 0xac) = usb_ro_3a4dc;
  *(undefined4 *)(puVar4 + 0xb0) = usb_ro_3a4e0;
  *(undefined4 *)(puVar4 + 0xb4) = 0;
  *(undefined4 *)(puVar4 + 0xb8) = usb_ro_3a4e4;
  *(undefined4 *)(puVar4 + 0xbc) = 0;
  puVar4 = usb_ro_3a4ac;
  *(uint *)(usb_ro_3a4ac + 0xc0) = uVar9 << 0x10;
  *(undefined4 *)(puVar4 + 0xc4) = usb_ro_3a4e8;
  *(undefined4 *)(puVar4 + 200) = usb_ro_3a4ec;
  *(undefined4 *)(puVar4 + 0xcc) = usb_ro_3a4f0;
  *(undefined4 *)(puVar4 + 0xd0) = usb_ro_3a4f4;
  *(undefined4 *)(puVar4 + 0xd4) = usb_ro_3a4f8;
  *(undefined4 *)(puVar4 + 0xd8) = usb_ro_3a4fc;
  *(undefined4 *)(puVar4 + 0xdc) = usb_ro_3a500;
  *(undefined4 *)(puVar4 + 0xe0) = usb_ro_3a504;
  *(undefined4 *)(puVar4 + 0xe4) = usb_ro_3a508;
  *(undefined4 *)(puVar4 + 0xe8) = usb_ro_3a50c;
  *(undefined4 *)(puVar4 + 0xec) = usb_ro_3a510;
  *(undefined4 *)(puVar4 + 0xf0) = usb_ro_3a514;
  *(undefined4 *)(puVar4 + 0xf4) = usb_ro_3a518;
  iVar6 = usb_ro_3a51c;
  *(int *)(puVar4 + 0xf8) = usb_ro_3a51c;
  *(int *)(puVar4 + 0xfc) = iVar6 >> 0x19;
  puVar4 = usb_ro_3a520;
  *(uint *)usb_ro_3a520 = *(uint *)usb_ro_3a520 | uVar9;
  *(uint *)(puVar4 + 8) = *(uint *)(puVar4 + 8) & ~uVar9;
  *(undefined4 *)(puVar4 + 0xc) = 0xffffff80;
  KEY_piaring_cnt();
  value_kcal_result();
  KEY_piaring_cnt();
  usb_sub_39dfe();
  *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) & 0xfbffffff;
  *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(puVar1 + 0x24);
  *(uint *)(puVar1 + 0x78) = *(uint *)(puVar1 + 0x78) | 0x80000000;
  *(undefined4 *)(puVar3 + 0x38) = *(undefined4 *)(puVar1 + 0x78);
  KEY_piaring_cnt();
  addPMU_Reg0x5();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  usb_sub_317c2(10);
  KEY_piaring_cnt();
  puVar1 = usb_ro_3a528;
  if (*usb_ro_3a524 == '\0') {
    uVar5 = usb_sub_39cfc();
    *puVar1 = uVar5;
  }
  usb_sub_39d3c(*puVar1);
  dbg_printf(str_cal_data_x,*puVar1);
  return;
}

/* ==========================================================================
 * kmod_calibration_2M   @ 0x0003a31e   (390 bytes)
 * calls     : usb_sub_317c2, dbg_printf, rom_24F24
 * string    : "kmod_calibration_2M"
 * string    : "read xvr_reg0x12:0x%x\r\n"
 * string    : "cal value:0x%x\r\n"
 * string    : "value_kcal_resulte:0x%x\r\n"
 */

void kmod_calibration_2M(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint *puVar4;
  uint uVar5;
  
  dbg_printf(&usb_ro_3a5b8,usb_ro_3a5b4,param_3,param_4,param_4);
  puVar4 = (uint *)(usb_ro_3a4ac + 0x80);
  *puVar4 = *puVar4 | 8;
  *puVar4 = *puVar4 & 0xfffffffc;
  *puVar4 = *puVar4 & usb_ro_3a5c0;
  *puVar4 = *puVar4 | 0x10000;
  *puVar4 = *puVar4 & usb_ro_3a5c4;
  *puVar4 = *puVar4 | 0x10000000;
  puVar1 = usb_ro_3a4ac;
  puVar3 = usb_ro_3a4ac + 0x40;
  *(uint *)(usb_ro_3a4ac + 0x50) = *(uint *)(usb_ro_3a4ac + 0x50) | 0x40000000;
  *(uint *)(puVar1 + 0x50) = *(uint *)(puVar1 + 0x50) | 0x80000000;
  *(uint *)(puVar1 + 0x50) = *(uint *)(puVar1 + 0x50) & 0xfffdffff;
  *(uint *)(puVar1 + 0x50) = *(uint *)(puVar1 + 0x50) & 0xffffff80;
  usb_sub_317c2(10);
  *(uint *)(puVar1 + 0x54) = *(uint *)(puVar1 + 0x54) | 0x1000;
  usb_sub_317c2(10);
  *(uint *)(puVar1 + 0x54) = *(uint *)(puVar1 + 0x54) | 0x2000;
  usb_sub_317c2(10);
  *(uint *)(puVar1 + 0x54) = *(uint *)(puVar1 + 0x54) | 0x800;
  usb_sub_317c2(10);
  puVar2 = usb_ro_3a5c8;
  *(uint *)(usb_ro_3a5c8 + 0xc) = *(uint *)(usb_ro_3a5c8 + 0xc) | 0x80;
  *(undefined4 *)(usb_ro_3a4ac + -0x34) = *(undefined4 *)(puVar2 + 0xc);
  usb_sub_317c2(10);
  *(uint *)(puVar2 + 0xc) = *(uint *)(puVar2 + 0xc) & 0xffffffbf;
  *(undefined4 *)(usb_ro_3a4ac + -0x34) = *(undefined4 *)(puVar2 + 0xc);
  usb_sub_317c2(10);
  *(uint *)(puVar1 + 0x54) = *(uint *)(puVar1 + 0x54) | 0x10000;
  usb_sub_317c2(200);
  uVar5 = *(uint *)(usb_ro_3a4ac + 8);
  dbg_printf(str_read_xvr_reg0x12_0x_x,uVar5);
  uVar5 = (uVar5 & 0x1fffffff) >> 0x10;
  dbg_printf(str_cal_value_0x_x,uVar5);
  uVar5 = rom_24F24(&rom_ro_1f400,uVar5);
  uVar5 = uVar5 & 0x1ff;
  *puVar4 = *puVar4 & usb_ro_3a5c0;
  *puVar4 = *puVar4 | uVar5 << 8;
  dbg_printf(str_value_kcal_resulte_0x_x,uVar5);
  *(uint *)(usb_ro_3a614 + 4) = uVar5;
  *(uint *)(puVar1 + 0x54) = *(uint *)(puVar1 + 0x54) & 0xfffeffff;
  *(uint *)(puVar1 + 0x54) = *(uint *)(puVar1 + 0x54) & 0xffffc7ff;
  *(uint *)(puVar2 + 0xc) = *(uint *)(puVar2 + 0xc) & 0xffffff7f;
  *(undefined4 *)(usb_ro_3a4ac + -0x34) = *(undefined4 *)(puVar2 + 0xc);
  *(uint *)(puVar2 + 0xc) = *(uint *)(puVar2 + 0xc) | 0x40;
  *(undefined4 *)(shared_ro_3a8e0 + 0xc) = *(undefined4 *)(puVar2 + 0xc);
  *puVar4 = *puVar4 & 0xfffffff7;
  *puVar4 = *puVar4 & 0xfffffffc;
  *puVar4 = *puVar4 | 1;
  *(uint *)(puVar1 + 0x50) = *(uint *)(puVar1 + 0x50) & ~((int)puVar3 * 0x800000);
  *(uint *)(puVar1 + 0x50) = *(uint *)(puVar1 + 0x50) & 0x7fffffff;
  *(uint *)(puVar1 + 0x50) = *(uint *)(puVar1 + 0x50) | 0x20000;
  return;
}

/* ==========================================================================
 * usb_sub_3aa42   @ 0x0003aa42   (70 bytes)
 * called by : usb_sub_33d2c, ble_sub_3443a
 */

void usb_sub_3aa42(undefined1 *param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = shared_ro_3ad08;
  do {
  } while (*(int *)(shared_ro_3ad08 + 8) << 0x1d < 0);
  *(uint *)(shared_ro_3ad08 + 4) = param_2 * 0x100000 + 2;
  uVar2 = usb_ro_3ad28;
  uVar3 = 0;
  do {
    while (*(int *)(puVar1 + 8) << 0x1d < 0) {
      param_2 = param_2 - 1 & 0xff;
      *param_1 = (char)*(undefined4 *)(puVar1 + 0xc);
      if (param_2 == 0) goto LAB_0003aa7a;
      param_1 = param_1 + 1;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 <= uVar2);
LAB_0003aa7a:
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & 0xfffffffd;
  return;
}

/* ==========================================================================
 * usb_sub_3afa2   @ 0x0003afa2   (86 bytes)
 * called by : USNDP_status_2, enter_BLE_normal_app_mode, exist, f_usb_isConnected
 * calls     : rom_25078
 */

void usb_sub_3afa2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
  cVar1 = shared_ro_3b258[1];
  puVar3 = shared_ro_3b258;
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
    puVar3[1] = (char)param_1;
    puVar3 = (undefined *)0x100000;
    uVar4 = rom_25078(param_1,shared_ro_3b264,0x100000,param_1,param_4);
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    param_1 = (int)uVar4;
    *(undefined4 *)(param_1 + 0x70) = 0x180;
    *(int *)(iVar2 + 0x74) = iVar2;
LAB_0003aff0:
  } while ((param_1 != 3) && (param_1 != 2));
  return;
}

/* ==========================================================================
 * usb_sub_3b528   @ 0x0003b528   (16 bytes)
 * called by : usb_sub_360aa, SLEEP, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, enter_BLE_normal_app_mode, exist, ... (+2 more)
 */

void usb_sub_3b528(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3b564;
  *(undefined4 *)(shared_ro_3b564 + 8) = 0;
  *(undefined4 *)(puVar1 + 4) = 0x5a;
  *(undefined4 *)(puVar1 + 4) = 0xa5;
  return;
}

/* ==========================================================================
 * usb_sub_3b54e   @ 0x0003b54e   (12 bytes)
 * called by : ble_sub_28c66, usb_sub_317c2, flash_sub_3c8b6, usb_sub_3c996, input_sub_3cd24, OLED_Clear, ... (+3 more)
 */

void usb_sub_3b54e(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3b564;
  *(undefined4 *)(shared_ro_3b564 + 4) = 0x5a;
  *(undefined4 *)(puVar1 + 4) = 0xa5;
  return;
}

/* ==========================================================================
 * usb_sub_3c21e   @ 0x0003c21e   (104 bytes)
 * called by : usb_sub_36024, flash_sub_3c2c6
 * calls     : rom_24F24
 */

void usb_sub_3c21e(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = rom_24F24(param_2,1000);
  puVar2 = shared_ro_3c4e4;
  puVar1 = shared_ro_3c4e0;
  if (param_1 == 0) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xfe;
    *(undefined4 *)puVar2 = uVar3;
    *(undefined4 *)(puVar1 + 0x1c) = uVar3;
    uVar4 = *(uint *)(puVar2 + 0xc);
    uVar5 = 1;
LAB_0003c266:
    uVar4 = uVar4 | uVar5;
  }
  else {
    if (param_1 == 1) {
      *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xfd;
      *(undefined4 *)(puVar2 + 4) = uVar3;
      *(undefined4 *)(puVar1 + 0x20) = uVar3;
      uVar4 = *(uint *)(puVar2 + 0xc);
      uVar5 = 2;
      goto LAB_0003c266;
    }
    if (param_1 != 2) goto LAB_0003c26a;
    *shared_ro_3c4e0 = *shared_ro_3c4e0 & 0xfb;
    *(undefined4 *)(puVar2 + 8) = uVar3;
    *(undefined4 *)(puVar1 + 0x2c) = uVar3;
    uVar4 = *(uint *)(puVar2 + 0xc) | 4;
  }
  *(uint *)(puVar2 + 0xc) = uVar4;
LAB_0003c26a:
  *(uint *)shared_ro_3c4ec = *(uint *)shared_ro_3c4ec | 4;
  return;
}

/* ==========================================================================
 * usb_sub_3c286   @ 0x0003c286   (64 bytes)
 * called by : usb_sub_36024, usb_sub_360aa, flash_sub_3c2c6, SLEEP, exist
 */

void usb_sub_3c286(int param_1)

{
  undefined *puVar1;
  byte bVar2;
  byte bVar3;
  
  puVar1 = shared_ro_3c4e0;
  if (param_1 == 0) {
    *(uint *)(shared_ro_3c4e4 + 0xc) = *(uint *)(shared_ro_3c4e4 + 0xc) & 0xfffffffe;
    bVar2 = *puVar1 & 0xfe;
  }
  else {
    if (param_1 == 1) {
      *(uint *)(shared_ro_3c4e4 + 0xc) = *(uint *)(shared_ro_3c4e4 + 0xc) & 0xfffffffd;
      bVar2 = *puVar1;
      bVar3 = 0xfd;
    }
    else {
      if (param_1 != 2) {
        return;
      }
      *(uint *)(shared_ro_3c4e4 + 0xc) = *(uint *)(shared_ro_3c4e4 + 0xc) & 0xfffffffb;
      bVar2 = *puVar1;
      bVar3 = 0xfb;
    }
    bVar2 = bVar2 & bVar3;
  }
  *puVar1 = bVar2;
  return;
}

/* ==========================================================================
 * usb_sub_3c6a8   @ 0x0003c6a8   (12 bytes)
 * called by : gpio
 */

void usb_sub_3c6a8(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3c804;
  *(undefined4 *)(shared_ro_3c804 + 0x10) = 1;
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}

/* ==========================================================================
 * usb_sub_3c818   @ 0x0003c818   (42 bytes)
 * called by : flash_sub_3c8b6
 * calls     : usb_sub_317c2
 */

void usb_sub_3c818(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3cc18;
  *(undefined4 *)(shared_ro_3cc18 + 8) = 2;
  usb_sub_317c2(1);
  *(undefined4 *)(puVar1 + 0xc) = 2;
  usb_sub_317c2(1);
  *(undefined4 *)(puVar1 + 0xc) = 0;
  usb_sub_317c2(1);
  *(undefined4 *)(puVar1 + 0xc) = 2;
  usb_sub_317c2(1);
  return;
}

/* ==========================================================================
 * usb_sub_3c996   @ 0x0003c996   (40 bytes)
 * called by : usb_sub_3c9be, led_sub_3d24a, usb_sub_3d55c
 * calls     : usb_sub_3b54e, led_sub_3c896
 */

void usb_sub_3c996(uint param_1,char param_2)

{
  led_sub_3c896(param_2 + -0x50);
  led_sub_3c896((param_1 >> 4) + 0x10);
  led_sub_3c896(param_1 & 0xf);
  usb_sub_3b54e();
  return;
}

/* ==========================================================================
 * usb_sub_3c9be   @ 0x0003c9be   (52 bytes)
 * called by : usb_sub_3c9f2, usb_sub_3cb9a, usb_sub_3ce5c, usb_sub_3d63a, usb_sub_3d7ee, usb_sub_3d8da, ... (+3 more)
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886, usb_sub_3c996
 */

void usb_sub_3c9be(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  usb_sub_3c996();
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    led_sub_3c852(*(undefined1 *)(param_4 + uVar1));
  }
  led_sub_3c842();
  return;
}

/* ==========================================================================
 * usb_sub_3c9f2   @ 0x0003c9f2   (422 bytes)
 * called by : input_sub_3cd24
 * calls     : usb_sub_3c9be
 */

void usb_sub_3c9f2(uint param_1,uint param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  byte local_38 [12];
  uint local_2c;
  uint local_28;
  uint local_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  puVar2 = usb_ro_3cc28;
  puVar1 = usb_ro_3cc20;
  uVar3 = 0;
  uVar6 = param_4 - 0x20U & 0xff;
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
        local_38[uVar3] = usb_ro_3cc24[uVar6 * 6 + uVar3];
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 6);
      uVar5 = 6;
      goto LAB_0003cb90;
    }
    if (param_3 == 1) {
      param_2 = param_2 + 2 & 0xff;
LAB_0003cb1a:
      iVar7 = uVar6 * 0x10;
      do {
        local_38[uVar3] = usb_ro_3cc28[iVar7 + uVar3] << 4;
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 8);
      usb_sub_3c9be(local_24,param_2,8,local_38);
      uVar3 = 0;
      do {
        local_38[uVar3] = (byte)puVar2[iVar7 + uVar3] >> 4 | puVar2[iVar7 + uVar3 + 8] << 4;
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 8);
      usb_sub_3c9be(local_24,param_2 + 1 & 0xff,8,local_38);
      uVar3 = 0;
      do {
        local_38[uVar3] = (byte)puVar2[iVar7 + uVar3 + 8] >> 4;
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 8);
      param_2 = param_2 + 2 & 0xff;
      uVar5 = 8;
      goto LAB_0003cb90;
    }
    if (param_3 != 2) {
      return;
    }
    param_2 = param_2 + 3 & 0xff;
  }
  iVar7 = uVar6 * 0x24;
  local_28 = 0;
  local_2c = 0;
  do {
    bVar4 = usb_ro_3cc20[iVar7 + uVar3 + 0x18];
    if (param_2 != 0) {
      if ((bVar4 & 1) != 0) {
        local_28 = 1 << uVar3 & 0xffffU | local_28;
      }
      bVar4 = bVar4 >> 1;
    }
    local_38[uVar3] = bVar4;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xc);
  usb_sub_3c9be(local_24,param_2 + 2 & 0xff,0xc,local_38);
  uVar3 = 0;
  do {
    bVar4 = puVar1[iVar7 + uVar3 + 0xc];
    if (param_2 != 0) {
      if ((bVar4 & 1) != 0) {
        local_2c = (1 << uVar3 | local_2c) & 0xffff;
      }
      bVar4 = bVar4 >> 1;
      if ((1 << uVar3 & local_28) != 0) {
        bVar4 = bVar4 | 0x80;
      }
    }
    local_38[uVar3] = bVar4;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xc);
  usb_sub_3c9be(local_24,param_2 + 1 & 0xff,0xc,local_38);
  uVar3 = 0;
  do {
    bVar4 = puVar1[iVar7 + uVar3];
    if ((param_2 != 0) && (bVar4 = bVar4 >> 1, (1 << uVar3 & local_2c) != 0)) {
      bVar4 = bVar4 | 0x80;
    }
    local_38[uVar3] = bVar4;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xc);
  uVar5 = 0xc;
LAB_0003cb90:
  usb_sub_3c9be(local_24,param_2,uVar5,local_38);
  return;
}

/* ==========================================================================
 * usb_sub_3cb9a   @ 0x0003cb9a   (370 bytes)
 * called by : input_sub_3cd24
 * calls     : usb_sub_3c9be
 */

void usb_sub_3cb9a(uint param_1,uint param_2,int param_3,int param_4)

{
  undefined *puVar1;
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
  
  puVar1 = usb_ro_3cc20;
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
        local_38[uVar2] = usb_ro_3d0ac[uVar5 * 6 + uVar2];
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 6);
      uVar4 = 6;
      goto LAB_0003cd1c;
    }
    if (param_3 == 1) {
      param_2 = param_2 + 2 & 0xff;
LAB_0003ccda:
      do {
        bVar3 = usb_ro_3d0b0[uVar5 * 0x10 + uVar2];
        local_38[uVar2] = bVar3;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 8);
      usb_sub_3c9be(local_24,param_2,8,local_38);
      uVar2 = 0;
      do {
        local_38[uVar2] = usb_ro_3d0b0[uVar5 * 0x10 + uVar2 + 8] | bVar3;
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
    bVar3 = usb_ro_3cc20[iVar6 + uVar2 + 0x18];
    if (param_2 != 0) {
      if ((bVar3 & 1) != 0) {
        local_28 = 1 << uVar2 & 0xffffU | local_28;
      }
      bVar3 = bVar3 >> 1;
    }
    local_38[uVar2] = bVar3;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0xc);
  usb_sub_3c9be(local_24,param_2 + 2 & 0xff,0xc,local_38);
  uVar2 = 0;
  do {
    bVar3 = puVar1[iVar6 + uVar2 + 0xc];
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
  usb_sub_3c9be(local_24,param_2 + 1 & 0xff,0xc,local_38);
  uVar2 = 0;
  do {
    bVar3 = puVar1[iVar6 + uVar2];
    if ((param_2 != 0) && (bVar3 = bVar3 >> 1, (1 << uVar2 & local_2c) != 0)) {
      bVar3 = bVar3 | 0x80;
    }
    local_38[uVar2] = bVar3;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0xc);
  uVar4 = 0xc;
LAB_0003cd1c:
  usb_sub_3c9be(local_24,param_2,uVar4,local_38);
  return;
}

/* ==========================================================================
 * usb_sub_3cdb6   @ 0x0003cdb6   (74 bytes)
 * called by : flash_sub_3cf7c, usb_sub_3d2b0, system_mode
 * calls     : input_sub_3cd24
 */

void usb_sub_3cdb6(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (*shared_ro_3d0bc == '\0') {
    cVar1 = *shared_ro_3d0c8;
    if (cVar1 == '\0') {
      input_sub_3cd24(0x4c,1,2,&usb_ro_3d0d4);
      uVar2 = 0x5e;
      puVar3 = &usb_ro_3d0d8;
      goto LAB_0003cddc;
    }
    if (cVar1 == '\x01') {
      puVar3 = &usb_ro_3d0dc;
    }
    else if (cVar1 == '\x02') {
      puVar3 = &usb_ro_3d0e4;
    }
    else {
      puVar3 = &shared_ro_3d0cc;
    }
  }
  else {
    puVar3 = &shared_ro_3d0c0;
  }
  uVar2 = 0x48;
LAB_0003cddc:
  input_sub_3cd24(uVar2,1,2,puVar3);
  return;
}

/* ==========================================================================
 * usb_sub_3ce5c   @ 0x0003ce5c   (200 bytes)
 * called by : flash_sub_3cf7c, usb_sub_3d2b0
 * calls     : usb_sub_3c9be, input_sub_3cd24, input_sub_429d4
 * string    : "  %d%%"
 * string    : " %d%%"
 */

void usb_sub_3ce5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar3 = 100 - (byte)*usb_ro_3d128 & 0xff;
  if (*usb_ro_3d12c == '\0') {
    uStack_18 = param_2;
    uStack_14 = param_3;
    uStack_10 = param_4;
    if (*shared_ro_3d130 == '\0') {
      if (uVar3 < 10) {
        pcVar1 = str_d_2;
      }
      else if (uVar3 < 100) {
        pcVar1 = str_d_3;
      }
      else {
        pcVar1 = &usb_ro_3d15c;
      }
      input_sub_429d4(&uStack_18,pcVar1,uVar3);
      input_sub_3cd24(0x4a,0,0,&uStack_18);
      if (uVar3 < 0x14) {
        puVar2 = usb_ro_46190;
      }
      else if (uVar3 - 0x14 < 0x14) {
        puVar2 = usb_ro_3d138 + 100;
      }
      else if (uVar3 - 0x28 < 0x14) {
        puVar2 = usb_ro_46168;
      }
      else if (uVar3 - 0x3c < 0x14) {
        puVar2 = usb_ro_46154;
      }
      else if (uVar3 - 0x50 < 0x14) {
        puVar2 = usb_ro_46140;
      }
      else {
        puVar2 = usb_ro_4612c;
      }
      usb_sub_3c9be(100,0,0x14,puVar2);
      return;
    }
    if (*shared_ro_3d134 == '\0') {
      usb_sub_3c9be(100,0,0x14,usb_ro_3d138);
      puVar2 = &usb_ro_3d144;
    }
    else {
      usb_sub_3c9be(100,0,0x14,usb_ro_3d138);
      puVar2 = &usb_ro_3d13c;
    }
    input_sub_3cd24(0x4a,0,0,puVar2);
  }
  return;
}

/* ==========================================================================
 * usb_sub_3cf24   @ 0x0003cf24   (88 bytes)
 * called by : flash_sub_31808, flash_sub_3cf7c
 * calls     : usb_sub_2b18e, input_sub_3cd24
 * string    : "125 Hz "
 * string    : "133 Hz "
 * string    : "1000 Hz"
 * string    : "500 Hz "
 * string    : "250 Hz "
 */

void usb_sub_3cf24(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = usb_sub_2b18e();
  if (iVar2 == 0) {
    pcVar3 = usb_ro_3d164;
  }
  else if (((*shared_ro_3d0c8 == '\x01') || (*shared_ro_3d0c8 == '\x02')) && (*shared_ro_3d0bc == '\0')) {
    pcVar3 = str_s133_Hz;
  }
  else {
    cVar1 = shared_ro_3d0ec[-10];
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
  input_sub_3cd24(0,0,0,pcVar3);
  return;
}

/* ==========================================================================
 * usb_sub_3d082   @ 0x0003d082   (42 bytes)
 * called by : usb_sub_3d2b0
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

void usb_sub_3d082(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if (*shared_ro_3d130 != '\0') {
    return;
  }
  if (*usb_ro_3d228 == '\0') {
    if (*usb_ro_3d238 == '\0') {
      return;
    }
    pcVar2 = str_BAT_LOW;
  }
  else {
    pcVar2 = str_BAT_OVER;
  }
  cVar1 = '\x01';
  bVar3 = 0;
  usb_sub_3b54e();
  *shared_ro_3d0b4 = 1;
  for (uVar4 = 0; pcVar2[uVar4] != '\0'; uVar4 = uVar4 + 1 & 0xff) {
    if (*input_ro_3d0b8 == '\0') {
      usb_sub_3c9f2(bVar3,cVar1,1);
    }
    else {
      usb_sub_3cb9a(bVar3,cVar1,1);
    }
    bVar3 = bVar3 + 8;
    if (0x70 < bVar3) {
      bVar3 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *input_ro_3d0b8 = 0;
  return;
}

/* ==========================================================================
 * usb_sub_3d2b0   @ 0x0003d2b0   (210 bytes)
 * called by : SLEEP, f_usb_isConnected
 * calls     : CHRG, Charging, usb_sub_3cdb6, input_sub_3ce00, led_sub_3ce52, usb_sub_3ce5c, ... (+7 more)
 */

void usb_sub_3d2b0(void)

{
  if ((*usb_ro_3d684 == '\0') && (*(short *)usb_ro_3d688 != 0)) {
    if (*usb_ro_3d68c != '\0') {
      *usb_ro_3d68c = 0;
      if (*usb_ro_3d690 != '\0') {
        *usb_ro_3d690 = 0;
        OLED_Clear();
      }
      *(undefined4 *)(shared_ro_3d694 + 8) = 2;
      flash_sub_3cf7c();
    }
    if (*usb_ro_3d698 != '\0') {
      *usb_ro_3d698 = 0;
      usb_sub_3ce5c();
    }
    if (*usb_ro_3d69c != '\0') {
      *usb_ro_3d69c = 0;
      input_sub_3ce00();
    }
    if (*usb_ro_3d6a0 != '\0') {
      *usb_ro_3d6a0 = 0;
      usb_sub_3d082();
    }
    if (*usb_ro_3d6a4 != '\0') {
      *usb_ro_3d6a4 = 0;
      led_sub_3ce52();
    }
    if (*usb_ro_3d6a8 != '\0') {
      *usb_ro_3d6a8 = 0;
      Charging();
    }
    if (*usb_ro_3d6ac != '\0') {
      *usb_ro_3d6ac = 0;
      Pairing();
    }
    if (*usb_ro_3d6b0 != '\0') {
      *usb_ro_3d6b0 = 0;
      ReLinking();
    }
    if (*usb_ro_3d6b4 != '\0') {
      *usb_ro_3d6b4 = 0;
      ReLink();
    }
    if (*usb_ro_3d6b8 != '\0') {
      *usb_ro_3d6b8 = 0;
      CHRG();
    }
    if (*usb_ro_3d6bc != '\0') {
      *usb_ro_3d6bc = 0;
      usb_sub_3cdb6();
    }
    if (*usb_ro_3d6c0 != '\0') {
      *usb_ro_3d6c0 = 0;
      delta_none();
    }
  }
  return;
}

/* ==========================================================================
 * usb_sub_3d55c   @ 0x0003d55c   (32 bytes)
 * calls     : led_sub_3c90c, usb_sub_3c996
 */

void usb_sub_3d55c(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  usb_sub_3c996();
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    led_sub_3c90c(*(undefined1 *)(param_4 + uVar1));
  }
  return;
}

/* ==========================================================================
 * usb_sub_3d63a   @ 0x0003d63a   (268 bytes)
 * calls     : usb_sub_3c9be, rom_24F9C, rom_24FEC
 */

void usb_sub_3d63a(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
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
  cVar1 = *usb_ro_3d708;
  puVar4 = usb_ro_3d70c;
  if ((*usb_ro_3d704 == '\0') && (puVar4 = usb_ro_3daf8, cVar1 != '\0')) {
    if (cVar1 == '\x01') {
      puVar4 = usb_ro_44f5b;
      goto LAB_0003d724;
    }
    if (cVar1 == '\x02') {
      puVar4 = usb_ro_44f85;
      goto LAB_0003d724;
    }
  }
  else {
LAB_0003d724:
    rom_24F9C(abStack_58,puVar4,0x15);
  }
  uVar2 = 0;
  do {
    acStack_98[uVar2] = abStack_58[uVar2] << 4;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x15);
  pbStack_2c = abStack_43;
  rom_24FEC();
  if (*usb_ro_3dafc == '\0') {
    if (cVar1 == '\0') {
      puVar4 = usb_ro_44f31;
    }
    else if (cVar1 == '\x01') {
      puVar4 = usb_ro_3daf8 + 0x54;
    }
    else {
      if (cVar1 != '\x02') goto LAB_0003d784;
      puVar4 = usb_ro_3daf8 + 0x7e;
    }
  }
  else {
    puVar4 = usb_ro_3daf8 + -0x15;
  }
  rom_24F9C(pbStack_2c,puVar4,0x15);
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
  usb_sub_3c9be(uStack_1c,param_2,0x15,acStack_98);
  usb_sub_3c9be(uStack_1c,param_2 + 1U & 0xff,0x15,abStack_83);
  usb_sub_3c9be(uStack_1c,param_2 + 2U & 0xff,0x15,abStack_6e);
  return;
}

/* ==========================================================================
 * usb_sub_3d7ee   @ 0x0003d7ee   (236 bytes)
 * calls     : usb_sub_3c9be, rom_24F9C, rom_24FEC
 */

void usb_sub_3d7ee(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
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
  cVar1 = *usb_ro_3db00;
  puVar4 = usb_ro_3daf8;
  if (cVar1 == '\0') {
LAB_0003d822:
    rom_24F9C(abStack_58,puVar4,0x15);
  }
  else {
    if (cVar1 == '\x01') {
      puVar4 = usb_ro_44f5b;
      goto LAB_0003d822;
    }
    if (cVar1 == '\x02') {
      puVar4 = usb_ro_44f85;
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
    puVar4 = usb_ro_44f31;
  }
  else if (cVar1 == '\x01') {
    puVar4 = usb_ro_3daf8 + 0x54;
  }
  else {
    if (cVar1 != '\x02') goto LAB_0003d872;
    puVar4 = usb_ro_3daf8 + 0x7e;
  }
  rom_24F9C(pbStack_2c,puVar4,0x15);
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
  usb_sub_3c9be(uStack_1c,param_2,0x15,acStack_98);
  usb_sub_3c9be(uStack_1c,param_2 + 1U & 0xff,0x15,abStack_83);
  usb_sub_3c9be(uStack_1c,param_2 + 2U & 0xff,0x15,abStack_6e);
  return;
}

/* ==========================================================================
 * usb_sub_3d8da   @ 0x0003d8da   (148 bytes)
 * called by : enter_BLE_normal_app_mode, f_usb_isConnected
 * calls     : usb_sub_3c9be, rom_24F9C, rom_24FEC
 */

void usb_sub_3d8da(int param_1)

{
  undefined1 *puVar1;
  undefined1 auStack_178 [120];
  undefined1 auStack_100 [240];
  
  *usb_ro_3db04 = 1;
  rom_24FEC(auStack_178,0x168);
  puVar1 = auStack_178 + param_1;
  rom_24F9C(puVar1,usb_ro_3db08,0x78);
  usb_sub_3c9be(0,0,0x78,auStack_100);
  rom_24FEC(auStack_178,0x168);
  rom_24F9C(puVar1,usb_ro_45f95,0x78);
  usb_sub_3c9be(0,1,0x78,auStack_100);
  rom_24FEC(auStack_178,0x168);
  rom_24F9C(puVar1,usb_ro_4600d,0x78);
  usb_sub_3c9be(0,2,0x78,auStack_100);
  rom_24FEC(auStack_178,0x168);
  rom_24F9C(puVar1,usb_ro_3db0c,0x78);
  usb_sub_3c9be(0,3,0x78,auStack_100);
  return;
}

/* ==========================================================================
 * usb_sub_3d96e   @ 0x0003d96e   (212 bytes)
 * calls     : usb_sub_3c9be, rom_24F9C, rom_24FEC
 */

void usb_sub_3d96e(int param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined1 auStack_134 [21];
  undefined1 auStack_11f [60];
  undefined1 auStack_e3 [207];
  
  rom_24FEC(auStack_134,0x11c);
  puVar2 = usb_ro_3db10;
  puVar4 = usb_ro_3dafc;
  if (*usb_ro_3dafc == '\0') {
    cVar1 = *usb_ro_3db10;
    puVar3 = usb_ro_3daf8;
    if (cVar1 == '\0') goto LAB_0003d9c0;
    if (cVar1 == '\x01') {
      puVar3 = usb_ro_44f5b;
      goto LAB_0003d9c0;
    }
    if (cVar1 == '\x02') {
      puVar3 = usb_ro_44f85;
      goto LAB_0003d9c0;
    }
  }
  else {
    puVar3 = usb_ro_3daf8 + -0x2a;
LAB_0003d9c0:
    rom_24F9C(auStack_134 + param_1,puVar3,0x15);
  }
  rom_24F9C(auStack_11f + param_1,usb_ro_3db14,0x3c);
  usb_sub_3c9be(0,1,0x78);
  rom_24FEC(auStack_134,0x11c);
  if (*puVar4 == '\0') {
    if (*puVar2 == '\0') {
      puVar4 = usb_ro_44f31;
    }
    else {
      if ((*usb_ro_3db00 != '\x01') && (*usb_ro_3db00 != '\x02')) goto LAB_0003da26;
      puVar4 = usb_ro_44f46;
    }
  }
  else {
    puVar4 = usb_ro_3daf8 + -0x15;
  }
  rom_24F9C(auStack_134 + param_1,puVar4,0x15);
LAB_0003da26:
  rom_24F9C(auStack_11f + param_1,usb_ro_4510d,0x3c);
  usb_sub_3c9be(0,2,0x78,auStack_e3);
  return;
}

/* ==========================================================================
 * usb_sub_3da42   @ 0x0003da42   (214 bytes)
 * calls     : usb_sub_3c9be, rom_24F9C, rom_24FEC
 */

void usb_sub_3da42(int param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined1 auStack_134 [21];
  undefined1 auStack_11f [60];
  undefined1 auStack_e3 [207];
  
  rom_24FEC(auStack_134,0x11c);
  puVar2 = usb_ro_3db10;
  puVar4 = usb_ro_3dafc;
  if (*usb_ro_3dafc == '\0') {
    cVar1 = *usb_ro_3db10;
    puVar3 = usb_ro_3daf8;
    if (cVar1 == '\0') goto LAB_0003da94;
    if (cVar1 == '\x01') {
      puVar3 = usb_ro_44f5b;
      goto LAB_0003da94;
    }
    if (cVar1 == '\x02') {
      puVar3 = usb_ro_44f85;
      goto LAB_0003da94;
    }
  }
  else {
    puVar3 = usb_ro_3daf8 + -0x2a;
LAB_0003da94:
    rom_24F9C(auStack_134 + param_1,puVar3,0x15);
  }
  rom_24F9C(auStack_11f + param_1,usb_ro_3db14 + 0x78,0x3c);
  usb_sub_3c9be(0,1,0x78);
  rom_24FEC(auStack_134,0x11c);
  if (*puVar4 == '\0') {
    cVar1 = *puVar2;
    if (cVar1 == '\0') {
      puVar4 = usb_ro_44f31;
    }
    else if (cVar1 == '\x01') {
      puVar4 = usb_ro_3daf8 + 0x54;
    }
    else {
      puVar4 = usb_ro_3dc18;
      if (cVar1 != '\x02') goto LAB_0003da3e;
    }
  }
  else {
    puVar4 = usb_ro_3daf8 + -0x15;
  }
  rom_24F9C(auStack_134 + param_1,puVar4,0x15);
LAB_0003da3e:
  rom_24F9C(auStack_11f + param_1,usb_ro_3dc1c,0x3c);
  usb_sub_3c9be(0,2,0x78,auStack_e3);
  return;
}

/* ==========================================================================
 * usb_sub_3db3a   @ 0x0003db3a   (82 bytes)
 * calls     : usb_sub_3c9be, input_sub_3cd24, rom_25078
 */

void usb_sub_3db3a(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int extraout_r1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined1 unaff_r7;
  
  puVar3 = usb_ro_3dc24;
  uVar2 = 1;
  if (param_1 < 5) {
    uVar1 = rom_25078(param_1,100 - (uint)(byte)*usb_ro_3dc20,100,param_1,param_2,param_3,param_4);
    puVar3 = puVar3 + -0x18;
    *(undefined2 *)(extraout_r1 * 2) = uVar1;
    uVar2 = unaff_r7;
  }
  usb_sub_3c9be(0x14,1,0x1d,usb_ro_3dc18 + 0x15);
  usb_sub_3c9be(0x14,2,0x1d,usb_ro_3dc18 + 0x32);
  *puVar3 = uVar2;
  input_sub_3cd24(0x32,1,1,usb_ro_3dc28);
  return;
}

/* ==========================================================================
 * usb_sub_4169a   @ 0x0004169a   (254 bytes)
 * called by : hogpd_report_upd_req_handler
 * calls     : ble_sub_3edee, ota_sub_3ee1a, ble_sub_41034, rom_06EF4, rom_06F26, rom_24F9C
 */

undefined4 usb_sub_4169a(int param_1,byte *param_2)

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
  
  iVar3 = ble_sub_3edee(0x26);
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
  iVar4 = ble_sub_41034(iVar3,*param_2,uVar7,param_2[4]);
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
      uVar7 = ota_sub_3ee1a(iVar3,param_1);
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
 * calls     : usb_sub_4169a, dbg_printf, rom_06EF4, rom_06F26, rom_07180, rom_071EA, ... (+1 more)
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
    if (iVar2 != usb_ro_41c48) {
      iVar2 = usb_sub_4169a(*param_2,param_2 + 2);
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
  pbVar3 = (byte *)rom_06EF4(shared_ro_41c4c + 2,param_4,param_3,2);
  *pbVar3 = *param_2;
  pbVar3[1] = (byte)iVar2;
  rom_06F26();
  dbg_printf(str_s_error_status_d,shared_ro_41c50,iVar2);
  return 0;
}

/* ==========================================================================
 * usb_sub_4245e   @ 0x0004245e   (20 bytes)
 * called by : usb_sub_37104, power_sub_37a94, usb_sub_38384, _USB_macro2, pcfg, usb_suspend
 */

uint usb_sub_4245e(int param_1,undefined4 param_2,uint param_3)

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
 * usb_sub_42472   @ 0x00042472   (18 bytes)
 * called by : usb_sub_37104, usb_sub_37ac6, usb_sub_38398, usb_suspend, usb_suspend_wakeup
 */

uint usb_sub_42472(uint param_1,undefined1 *param_2)

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
 * usb_sub_42a20   @ 0x00042a20   (80 bytes)
 * called by : usb_sub_37878, usb_sub_378ba
 */

void usb_sub_42a20(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 - 4);
    piVar1 = *(int **)usb_ro_42a70;
    piVar4 = (int *)0x0;
    while ((piVar3 = piVar1, piVar3 != (int *)0x0 && (piVar3 <= piVar2))) {
      piVar4 = piVar3;
      piVar1 = (int *)piVar3[1];
    }
    if (piVar4 == (int *)0x0) {
      *(int **)usb_ro_42a70 = piVar2;
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
 * usb_sub_42a74   @ 0x00042a74   (92 bytes)
 * called by : usb_sub_37878, usb_sub_378ba
 */

uint * usb_sub_42a74(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  
  puVar1 = usb_ro_42ad0;
  uVar4 = param_1 + 0xbU & 0xfffffff8;
  puVar5 = (uint *)usb_ro_42ad4;
  do {
    while (puVar3 = (uint *)*puVar5, puVar3 == (uint *)0x0) {
      puVar3 = (uint *)0x0;
LAB_00042aac:
      puVar2 = usb_ro_42ad8;
      if (puVar3 != (uint *)0x0) {
        return puVar3;
      }
      if (*(int *)puVar1 != 0) {
        return (uint *)0x0;
      }
      *(undefined **)usb_ro_42ad4 = usb_ro_42ad8;
      *(uint *)puVar2 = (int)usb_ro_42adc - (int)puVar2 & 0xfffffff8;
      *(undefined4 *)(puVar2 + 4) = 0;
      *(undefined4 *)puVar1 = 1;
      puVar5 = (uint *)usb_ro_42ad4;
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
