/* 2.4 GHz RF link
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * rf24_sub_28aa0   @ 0x00028aa0   (16 bytes)
 * calls     : rf24_sub_3c0a8
 */

void rf24_sub_28aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  rf24_sub_3c0a8();
                    /* WARNING: Could not recover jumptable at 0x00028aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + -4))(param_1,param_2,param_3,param_4);
  return;
}

/* ==========================================================================
 * rf24_sub_29ab0   @ 0x00029ab0   (28 bytes)
 * called by : app_24_to_ble_force_pair_reset, app_24_to_ble_reset, app_ble_address_update, app_ble_to_ble_mode
 * calls     : ble_sub_3e5f0
 */

void rf24_sub_29ab0(int param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_29d70;
  shared_ro_29d70[6] = param_1 != 1;
  ble_sub_3e5f0(0x80,1,puVar1 + 6);
  return;
}

/* ==========================================================================
 * rf24_sub_29ed8   @ 0x00029ed8   (26 bytes)
 * called by : app_24_to_ble_force_pair_reset, force_pair_en
 * calls     : ble_sub_3e5f0
 */

void rf24_sub_29ed8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = (undefined1)param_1;
  uStack_7 = (undefined3)((uint)param_4 >> 8);
  if (1 < param_1) {
    local_8 = 0;
  }
  ble_sub_3e5f0(0x39,1,&local_8);
  return;
}

/* ==========================================================================
 * rf24_sub_29ef2   @ 0x00029ef2   (38 bytes)
 * called by : app_24_to_ble_force_pair_reset, app_24_to_ble_reset
 * calls     : ble_sub_3e5f0
 */

void rf24_sub_29ef2(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_8;
  undefined3 uStack_7;
  
  _local_8 = CONCAT31((int3)((uint)param_4 >> 8),param_1);
  if (((*rf24_ro_2a2ec == '\x01') || (*rf24_ro_2a2ec == '\x02')) && (*rf24_ro_2a2f0 == '\0')) {
    ble_sub_3e5f0(0x38,1,&local_8);
  }
  return;
}

/* ==========================================================================
 * app_24_to_ble_force_pair_reset   @ 0x00029f18   (42 bytes)
 * called by : ble_sub_2b8a2, switch_rf_mode_loop
 * calls     : rf24_sub_29ab0, rf24_sub_29ed8, rf24_sub_29ef2, rf24_sub_3b130, rf24_sub_3b1de, dbg_printf
 * string    : "app_24_to_ble_force_pair_reset"
 * string    : "%s \r\n"
 */

void app_24_to_ble_force_pair_reset(void)

{
  undefined *puVar1;
  
  dbg_printf(rf24_ro_2a2f8,rf24_ro_2a2f4);
  puVar1 = rf24_ro_2a2ec;
  rf24_sub_29ab0(*rf24_ro_2a2ec);
  rf24_sub_29ef2(*puVar1);
  rf24_sub_29ed8(1);
  rf24_sub_3b1de(0);
  rf24_sub_3b130();
  return;
}

/* ==========================================================================
 * app_24_to_ble_reset   @ 0x00029f42   (84 bytes)
 * called by : switch_rf_mode_loop
 * calls     : rf24_sub_29ab0, rf24_sub_29ef2, rf24_sub_3b130, KEY_piaring_cnt, dbg_printf
 * string    : "%s \r\n"
 * string    : "app_24_to_ble_reset"
 * string    : "key press before cpu reset = %d,%d\r\n"
 */

undefined4 app_24_to_ble_reset(void)

{
  undefined1 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  dbg_printf(rf24_ro_2a2f8,rf24_ro_2a2f4 + -0x14);
  KEY_piaring_cnt();
  puVar2 = rf24_ro_2a2ec;
  rf24_sub_29ab0(*rf24_ro_2a2ec);
  KEY_piaring_cnt();
  rf24_sub_29ef2(*puVar2);
  KEY_piaring_cnt();
  puVar3 = rf24_ro_2a2fc;
  if ((byte)*rf24_ro_2a2fc < 5) {
    rf24_sub_3b130();
  }
  *puVar2 = 0;
  *shared_ro_2a300 = *shared_ro_2a300 & 0xfd;
  uVar1 = *puVar3;
  *rf24_ro_2a304 = uVar1;
  dbg_printf(str_key_press_before_cpu_reset_d_d,uVar1,*rf24_ro_2a308);
  return 1;
}

/* ==========================================================================
 * switch_rf_mode_loop   @ 0x00029f96   (226 bytes)
 * called by : Disconnected, app_mutli_link_change
 * calls     : ble_sub_2cbda, rf24_sub_32886, ble_sub_3e5f0, OLED_Clear, app_24_to_ble_force_pair_reset, app_24_to_ble_reset, ... (+4 more)
 * string    : "switch_rf_mode_loop"
 * string    : "%s : RF_MODE**********Simu_RF_MODE[%x to %x]\r\n"
 * string    : "force_pair_en 4========%x\r\n"
 * string    : "bonded0===========%x, bonded1========%x\r\n"
 * string    : " An error has occurred during access to the NVDS_TAG_RF_MODE \r\n"
 */

undefined4 switch_rf_mode_loop(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 local_18;
  
  puVar4 = rf24_ro_2a334;
  puVar2 = rf24_ro_2a2ec;
  local_18 = 0;
  dbg_printf(str_s_RF_MODE_Simu_RF_MODE_x_to_x,rf24_ro_2a2f4 + -0x28,*rf24_ro_2a2ec,*rf24_ro_2a334);
  puVar5 = shared_ro_2a388;
  puVar3 = rf24_ro_2a2f0;
  if (*rf24_ro_2a368 != '\0') {
    *rf24_ro_2a368 = 0;
    dbg_printf(str_force_pair_en_4_x,0);
    return 0;
  }
  *shared_ro_2a300 = *shared_ro_2a300 | 2;
  if (*puVar2 == '\0') {
    cVar1 = *puVar4;
    *puVar2 = cVar1;
    if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*puVar3 == '\0')) {
      *puVar5 = 200;
      app_24_to_ble_reset();
      local_18 = 1;
      goto LAB_0002a040;
    }
  }
  else {
    dbg_printf(str_bonded0_x_bonded1_x,*rf24_ro_2a38c,rf24_ro_2a38c[1]);
    cVar1 = *puVar4;
    *puVar2 = cVar1;
    if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*puVar3 == '\0')) {
      iVar6 = ble_sub_2cbda();
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
  rf24_sub_32886(0);
  fWorkModeInit();
LAB_0002a040:
  OLED_Clear();
  if (((*puVar2 == '\x01') || (*puVar2 == '\x02')) &&
     ((*puVar3 == '\0' && (iVar6 = ble_sub_3e5f0(0x38,1,rf24_ro_2a2ec), iVar6 != 0)))) {
    dbg_printf(str_An_error_has_occurred_during_access_to_the_N);
  }
  return local_18;
}

/* ==========================================================================
 * app_start_led   @ 0x0002a0ec   (90 bytes)
 * called by : APP_PARAM_UPDATE_REQ_IN, APP_PARAM_UPDATE_REQ_IND, BLE_PAIR
 * calls     : rf24_sub_32886, dbg_printf, rom_07342, rom_25078
 * string    : "app_start_led"
 * string    : "%s RF_MODE[%d]\r\n"
 */

void app_start_led(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined1 extraout_r1;
  
  dbg_printf(str_s_RF_MODE_d,str_app_start_led,*rf24_ro_2a2ec);
  *rf24_ro_2a428 = 0;
  puVar1 = shared_ro_2a430;
  *(undefined2 *)rf24_ro_2a42c = 0;
  *puVar1 = 1;
  rf24_sub_32886(*rf24_ro_2a434 == '\0');
  puVar2 = (undefined1 *)rom_25078(shared_ro_2a430 + -0x10,0x13,shared_ro_2a430[-7],shared_ro_2a430[-7]);
  *(undefined1 *)(((uint)puVar2 >> 0x14) + 3) = extraout_r1;
  *(char *)(((uint)puVar2 >> 0x14) + 2) = (char)puVar2;
  *puVar2 = (char)puVar2;
  rom_07342(shared_ro_2a438,3,0x19);
  return;
}

/* ==========================================================================
 * force_24g_sleep   @ 0x0002b24e   (68 bytes)
 * called by : SLEEP, set_Update_OLED_2
 * calls     : usb_sub_3b528, dbg_printf, set_force_sleep
 * string    : "%s \r\n"
 * string    : "force_24g_sleep"
 */

void force_24g_sleep(void)

{
  undefined *puVar1;
  
  *shared_ro_2b570 = 1;
  dbg_printf(str_s_3,str_force_24g_sleep);
  puVar1 = rf24_ro_2b574;
  *(undefined4 *)(rf24_ro_2b574 + 0x18) = 0x80;
  *(undefined4 *)(puVar1 + 0x18) = 0xa0;
  *(undefined4 *)(rf24_ro_2b574 + 0x40) = 0x7e;
  set_force_sleep();
  *rf24_ro_2b578 = 200;
  *rf24_ro_2b57c = 0;
  *rf24_ro_2b580 = 0;
  *rf24_ro_2b584 = 3;
  usb_sub_3b528();
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
    dbg_printf(rf24_ro_2d3f8,*(undefined1 *)(unaff_r7 + unaff_r6));
    unaff_r6 = unaff_r6 + 1;
  } while (unaff_r6 < 0x10);
  dbg_printf(&rf24_ro_2d3fc);
  dbg_printf(str_encrypt_req_ind121);
  rom_06F26();
  *(uint *)rf24_ro_2d414 = *(uint *)rf24_ro_2d414 | 0x200;
  *rf24_ro_2d418 = 0;
  *rf24_ro_2d41c = unaff_r4;
  dbg_printf(&rf24_ro_2d420);
  *rf24_ro_2d434 = unaff_r4;
  rom_073D4(rf24_ro_2d3a4 + 0xf3,3);
  if ((*rf24_ro_2d438 == '\0') || (6 < (byte)*rf24_ro_2d43c)) {
    *rf24_ro_2d438 = unaff_r4;
    rom_07342(rf24_ro_2d3a4 + 0xea,3,2);
    dbg_printf(str_APP_PARAM_UPDATE_REQ_IN_1_need_update_param);
  }
  else {
    *rf24_ro_2d480 = unaff_r4;
  }
  if (*rf24_ro_2d484 == '\0') {
    app_start_led();
  }
  rom_07342(rf24_ro_2d3a4 + 0xf7,3,200);
  return 0;
}

/* ==========================================================================
 * rf24_sub_2f92a   @ 0x0002f92a   (186 bytes)
 * calls     : rf24_sub_36c8e, led_sub_36caa, rf24_sub_36d3a, dbg_printf_2, rom_24F9C, rom_24FEC
 */

void rf24_sub_2f92a(void)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  
  puVar3 = rf24_ro_2fc9c;
  if (*rf24_ro_2fc9c == '\0') {
    led_sub_36caa();
    *rf24_ro_2fcd0 = 1;
  }
  bVar1 = *shared_ro_2fcd4;
  if ((bVar1 != 0) && (*rf24_ro_2fccc == '\0')) {
    cVar2 = *shared_ro_2fcd8;
    *shared_ro_2fcd8 = cVar2 + '\x01';
    rom_24FEC(shared_ro_2fca4,0x20);
    puVar4 = shared_ro_2fca4;
    *shared_ro_2fca4 = 0x39;
    puVar6 = shared_ro_2fcdc;
    puVar4[1] = cVar2 + '\x01';
    puVar5 = shared_ro_2fcd4;
    if (bVar1 < 0x1e) {
      rom_24F9C(puVar4 + 2,*(undefined4 *)(puVar6 + 4),bVar1);
      dbg_printf_2(str_RPT_STEP_13S,shared_ro_2fca4,*puVar5 + '\x02');
      *puVar5 = 0;
    }
    else {
      iVar7 = *(int *)(puVar6 + 4);
      rom_24F9C(puVar4 + 2,iVar7,0x1e);
      *(int *)(shared_ro_2fcdc + 4) = iVar7 + 0x1e;
      *shared_ro_2fcd4 = bVar1 - 0x1e;
      dbg_printf_2(str_RPT_STEP_13L,shared_ro_2fca4,0x20);
    }
    if (*rf24_ro_2fcd0 != '\0') {
      *rf24_ro_2fcd0 = 0;
      rf24_sub_36c8e();
    }
    rf24_sub_36d3a(0x20);
    *(undefined2 *)rf24_ro_2fcb8 = 500;
    *puVar3 = 6;
    *rf24_ro_2fca0 = *rf24_ro_2fca0 + '\x01';
    return;
  }
  *puVar3 = 6;
  *rf24_ro_2fca0 = 0;
  return;
}

/* ==========================================================================
 * rf24_sub_2fa6c   @ 0x0002fa6c   (34 bytes)
 * calls     : rf24_sub_31784, usb_sub_369d8
 */

void rf24_sub_2fa6c(void)

{
  if (*shared_ro_2fd00 == '\0') {
    rf24_sub_31784(200);
    usb_sub_369d8();
    *rf24_ro_2fc9c = 6;
    *rf24_ro_2fca0 = 0;
  }
  return;
}

/* ==========================================================================
 * ch_frequency   @ 0x0002fb36   (232 bytes)
 * calls     : rf24_sub_31784, usb_sub_369a0, usb_sub_369ac, usb_sub_369b8, rf24_sub_36c8e, led_sub_36caa, ... (+2 more)
 * string    : "SEND_ACK57 ok  RF24_STEP=%d,%d,%d\r\n"
 * string    : "ch_frequency 10=%x\r\n"
 * string    : "retr_time 57 ACK %x\r\n"
 */

void ch_frequency(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 in_r3;
  
  uVar7 = *(uint *)shared_ro_2fc94 & 0x70;
  *(uint *)shared_ro_2fc94 = uVar7;
  puVar4 = shared_ro_2fcdc;
  puVar3 = rf24_ro_2fca0;
  puVar2 = shared_ro_2fc94;
  if ((int)(uVar7 * 0x4000000) < 0) {
    *(undefined **)(shared_ro_2fcdc + 4) = shared_ro_2fcdc + 9;
    *shared_ro_2fcd4 = puVar4[3] + -2;
    *shared_ro_2fcd8 = 0;
    *rf24_ro_2fccc = 0;
    puVar4 = shared_ro_2fd08;
    if (*puVar3 == '\x06') {
      usb_sub_369b8();
      rf24_sub_31784(200);
      uVar6 = 9;
    }
    else if (*shared_ro_2fd08 == '\0') {
      uVar6 = 0xc;
    }
    else {
      uVar6 = 0xb;
    }
    *puVar3 = uVar6;
    dbg_printf(str_SEND_ACK57_ok_RF24_STEP_d_d_d,*puVar3,*rf24_ro_2fd38,*puVar4,in_r3);
    *(undefined4 *)(puVar2 + -0x28) = 0xa0;
    *(undefined4 *)(puVar2 + -0x28) = 0x80;
  }
  else if ((int)(uVar7 << 0x1b) < 0) {
    *(undefined4 *)(shared_ro_2fc94 + -0x28) = 0xa0;
    *(undefined4 *)(puVar2 + -0x28) = 0x80;
    usb_sub_369ac();
    usb_sub_369a0();
    puVar5 = rf24_ro_2fd94;
    puVar4 = rf24_ro_2fcb8;
    puVar2 = rf24_ro_2fc98;
    if (*(short *)rf24_ro_2fcb8 == 0) {
      *puVar3 = 0;
      *puVar5 = 0;
      *rf24_ro_2fd98 = 200;
      *rf24_ro_2fccc = 1;
      *(undefined2 *)rf24_ro_2fd9c = 0;
      if (*rf24_ro_2fda0 == '\0') {
        *rf24_ro_2fda4 = 3;
        return;
      }
    }
    else {
      cVar1 = *rf24_ro_2fc98;
      *rf24_ro_2fc98 = cVar1 + 1U;
      if (3 < (byte)(cVar1 + 1U)) {
        *puVar2 = 0;
        led_sub_36caa();
        rf24_sub_36c8e();
        dbg_printf(str_ch_frequency_10_x,*rf24_ro_2fd60);
      }
      rf24_sub_31784(0x5a);
      rf24_sub_36d3a(8);
      dbg_printf(str_retr_time_57_ACK_x,*(undefined2 *)puVar4);
    }
    return;
  }
  return;
}

/* ==========================================================================
 * rf24_sub_2fc1e   @ 0x0002fc1e   (52 bytes)
 * calls     : rf24_sub_36c8e, led_sub_36caa, rf24_sub_36d3a, dbg_printf_2
 */

void rf24_sub_2fc1e(void)

{
  if (*rf24_ro_2fc9c == '\0') {
    led_sub_36caa();
    rf24_sub_36c8e();
  }
  rf24_sub_36d3a(8);
  dbg_printf_2(&rf24_ro_2fda8,shared_ro_2fca4,5);
  *(undefined2 *)rf24_ro_2fcb8 = 500;
  *rf24_ro_2fca0 = *rf24_ro_2fca0 + '\x01';
  return;
}

/* ==========================================================================
 * LightUp_Mode_Led   @ 0x0002fc52   (368 bytes)
 * calls     : CHRG, ble_sub_312aa, rf24_sub_3143c, rf24_sub_31784, usb_sub_317c2, led_sub_32892, ... (+10 more)
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
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  
  puVar5 = shared_ro_2fc94;
  if (*rf24_ro_2fdb8 != '\0') {
    *rf24_ro_2fdb8 = 0;
    *(undefined4 *)(puVar5 + -0x2c) = 1;
    usb_sub_317c2(4);
    uVar9 = *(uint *)shared_ro_2fc94;
    *(uint *)shared_ro_2fc94 = uVar9 & 0x70;
    puVar8 = rf24_ro_2fdbc;
    puVar6 = rf24_ro_2fca0;
    puVar5 = rf24_ro_2fc9c;
    if ((int)((uVar9 & 0x70) << 0x19) < 0) {
      led_sub_36e88();
      puVar7 = shared_ro_2fca4;
      if (*shared_ro_2fca4 == ';') {
        bVar1 = shared_ro_2fca4[1];
        *(uint *)puVar8 = (uint)bVar1;
        bVar2 = puVar7[2];
        *(uint *)(puVar8 + 4) = (uint)bVar2;
        bVar3 = puVar7[3];
        *(uint *)(puVar8 + 8) = (uint)bVar3;
        puVar8 = shared_ro_3012c;
        shared_ro_3012c[0x10] = bVar1;
        puVar8[0x11] = bVar2;
        puVar8[0x12] = bVar3;
        dbg_printf(&rf24_ro_30130);
        write();
        *shared_ro_30144 = 0;
        *rf24_ro_30148 = 0;
        *(undefined2 *)rf24_ro_3014c = 0;
        *rf24_ro_30150 = puVar8[0x12] & 3;
        rf24_sub_36c8e();
        rf24_sub_36cd2();
        rf24_sub_31784(200);
        usb_sub_369d8();
        *shared_ro_30154 = 200;
        rf24_sub_3143c();
        *puVar5 = 6;
        OLED_Init();
        puVar5 = rf24_ro_30158;
        *puVar6 = 0;
        *puVar5 = 0;
        *rf24_ro_3015c = 0;
        ble_sub_312aa();
        dbg_printf_2(str_RF24_piar_id_code,puVar8 + 0x10,3);
        uVar4 = *shared_ro_30174;
        *(undefined2 *)shared_ro_30178 = 500;
        dbg_printf(str_LightUp_Mode_Led_x_x_x_x_x,*rf24_ro_30184,*rf24_ro_30180,*(undefined2 *)shared_ro_3017c,500,
                   uVar4);
        led_sub_32892();
        *(undefined2 *)rf24_ro_301bc = 0;
        *rf24_ro_301c0 = 0;
        *rf24_ro_301c4 = 0;
        Success_led_2second_2();
        CHRG();
      }
    }
    else if (*(short *)rf24_ro_301bc == 0) {
      *rf24_ro_30150 = shared_ro_3012c[0x12] & 3;
      rf24_sub_36c8e();
      rf24_sub_36cd2();
      usb_sub_369d8();
      rf24_sub_3143c();
      *puVar5 = 6;
      puVar5 = rf24_ro_301c8;
      *puVar6 = 0;
      *(undefined2 *)puVar5 = 0;
      *rf24_ro_301c0 = 0;
      *rf24_ro_301cc = 0;
      puVar5 = rf24_ro_301d4;
      if (*rf24_ro_30158 == '\0') {
        if (*(short *)rf24_ro_3014c == 0) {
          if ((*rf24_ro_301d4 == '\0') && (*(undefined2 *)shared_ro_3017c = 0, *puVar5 == '\0')) {
            *rf24_ro_30180 = 3;
          }
        }
        else {
          *puVar6 = 2;
        }
      }
      else {
        *rf24_ro_30158 = 0;
        *shared_ro_30174 = 0;
        set_bonded_led_flash();
        *rf24_ro_301d0 = 1;
      }
      dbg_printf(str_NO_DONGLE_x_x_x,*(undefined4 *)puVar8,*(undefined4 *)(puVar8 + 4),
                 *(undefined4 *)(puVar8 + 8));
      return;
    }
  }
  return;
}

/* ==========================================================================
 * write   @ 0x0003046e   (46 bytes)
 * called by : LightUp_Mode_Led
 * calls     : dbg_printf_2, flash_write_some_data
 * string    : "write id_code:"
 */

void write(void)

{
  undefined *puVar1;
  
  puVar1 = flash_ro_30644;
  flash_ro_30644[0x13] = ~flash_ro_30644[0x10];
  puVar1[0x14] = ~puVar1[0x11];
  puVar1[0x15] = ~puVar1[0x12];
  flash_write_some_data(puVar1 + 0x10,shared_ro_306a4,6);
  dbg_printf_2(str_write_id_code,puVar1 + 0x10,3);
  return;
}

/* ==========================================================================
 * rf24_sub_3143c   @ 0x0003143c   (24 bytes)
 * called by : usb_sub_358b6, LightUp_Mode_Led, fWorkModeInit
 * calls     : rom_24FEC
 */

void rf24_sub_3143c(void)

{
  rom_24FEC(shared_ro_315c8,0x20);
  *shared_ro_315c8 = 0x3c;
  *shared_ro_315a8 = 1;
  return;
}

/* ==========================================================================
 * rf24_sub_31784   @ 0x00031784   (32 bytes)
 * called by : ble_sub_2abd4, rf24_sub_2fa6c, led_sub_2ff18, rf24_sub_33d00, usb_sub_33d2c, rf24_sub_34352, ... (+21 more)
 */

void rf24_sub_31784(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*shared_ro_31800 == '\x05') {
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
 * rf24_sub_326b0   @ 0x000326b0   (58 bytes)
 * calls     : dbg_printf
 * string    : "%s, Simu_RF_MODE=%x,Mode_Indicator_BIT=%x\r\n"
 */

void rf24_sub_326b0(void)

{
  char cVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
  puVar2 = shared_ro_329e4;
  *shared_ro_329e4 = 0;
  cVar1 = *shared_ro_329f4;
  if (*shared_ro_329ec == '\0') {
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
  dbg_printf(str_s_Simu_RF_MODE_x_Mode_Indicator_BIT_x,shared_ro_329f8,cVar1,*puVar2);
  return;
}

/* ==========================================================================
 * rf24_sub_32886   @ 0x00032886   (12 bytes)
 * called by : ble_sub_28c66, ble_sub_31172, led_sub_32892, power_sub_35c9c, app_start_led, set_force_sleep, ... (+1 more)
 */

void rf24_sub_32886(byte param_1)

{
  byte bVar1;
  undefined *puVar2;
  
  *shared_ro_32a8c = param_1;
  puVar2 = shared_ro_329e8;
  if ((param_1 & 1) == 0) {
    *(undefined4 *)(shared_ro_329e8 + 0x28) = 0;
    *(undefined4 *)(puVar2 + 0x24) = 0;
    *(undefined4 *)(puVar2 + 0x20) = 0;
    return;
  }
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
 * rf24_sub_33d00   @ 0x00033d00   (42 bytes)
 * called by : rf24_sub_342b4, rf24_sub_34352, rf24_sub_34408, input_sub_34414, rf24_sub_34490, rf24_sub_344b0, ... (+5 more)
 * calls     : rf24_sub_31784, rf24_sub_3aa1a
 */

void rf24_sub_33d00(byte param_1,undefined1 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = shared_ro_33f70;
  *(undefined4 *)(shared_ro_33f70 + 0x1c) = 0;
  puVar2 = shared_ro_33f74;
  *shared_ro_33f74 = param_1 | 0x80;
  puVar2[1] = param_2;
  rf24_sub_3aa1a(puVar2,2);
  rf24_sub_31784(0xc);
  *(undefined4 *)(puVar1 + 0x1c) = 2;
  rf24_sub_31784(5);
  return;
}

/* ==========================================================================
 * rf24_sub_33e24   @ 0x00033e24   (16 bytes)
 * calls     : rf24_sub_345a4
 */

void rf24_sub_33e24(void)

{
  if (*shared_ro_33fb4 != '\0') {
    rf24_sub_345a4();
  }
  return;
}

/* ==========================================================================
 * rf24_sub_342b4   @ 0x000342b4   (158 bytes)
 * called by : usb_sub_345d2
 * calls     : rf24_sub_33d00, usb_sub_33d2c
 */

void rf24_sub_342b4(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = rf24_ro_3460c;
  if (param_1 == 0) {
    uVar2 = 0;
    do {
      rf24_sub_33d00(puVar1[uVar2 * 2],puVar1[uVar2 * 2 + 1]);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 0x15);
  }
  else if (param_1 == 1) {
    uVar2 = 0;
    do {
      rf24_sub_33d00(puVar1[uVar2 * 2 + 0x2a],puVar1[uVar2 * 2 + 0x2b]);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 0x15);
  }
  else if (param_1 == 2) {
    uVar2 = 0;
    do {
      rf24_sub_33d00(puVar1[uVar2 * 2 + 0x54],puVar1[uVar2 * 2 + 0x55]);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 0x15);
  }
  else {
    if (param_1 == 3) {
      uVar2 = 0;
      do {
        rf24_sub_33d00(puVar1[uVar2 * 2 + 0x7e],puVar1[uVar2 * 2 + 0x7f]);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 0x14);
      return;
    }
    if (2 < param_1) {
      return;
    }
  }
  uVar2 = usb_sub_33d2c(0x40);
  rf24_sub_33d00(0x40,uVar2 & 0xfffffffc | param_1);
  return;
}

/* ==========================================================================
 * rf24_sub_34352   @ 0x00034352   (182 bytes)
 * called by : usb_sub_345d2
 * calls     : rf24_sub_31784, rf24_sub_33d00, usb_sub_33d2c
 */

void rf24_sub_34352(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  
  puVar1 = rf24_ro_34610;
  uVar5 = 0;
  do {
    rf24_sub_33d00(puVar1[uVar5 * 2],puVar1[uVar5 * 2 + 1]);
    iVar2 = rf24_ro_34614;
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 0x8c);
  rf24_sub_31784(rf24_ro_34614);
  bVar4 = 0;
  iVar6 = rf24_ro_34614 + 0xd;
  do {
    iVar3 = usb_sub_33d2c(0x6c);
    if (iVar3 == 0x80) break;
    rf24_sub_31784(iVar6);
    bVar4 = bVar4 + 1;
  } while (bVar4 < 0x3c);
  rf24_sub_31784(iVar2);
  if (bVar4 == 0x3c) {
    rf24_sub_33d00(0x7f,0x14);
    rf24_sub_33d00(0x6c,0);
    rf24_sub_33d00(0x7f,0);
  }
  rf24_sub_33d00(0x22,0);
  rf24_sub_33d00(0x55,0);
  rf24_sub_33d00(0x7f,7);
  rf24_sub_33d00(0x40);
  rf24_sub_33d00(0x7f,0);
  rf24_sub_33d00(0x68,1);
  usb_sub_33d2c(2);
  usb_sub_33d2c(3);
  usb_sub_33d2c(4);
  usb_sub_33d2c(5);
  usb_sub_33d2c(6);
  return;
}

/* ==========================================================================
 * rf24_sub_34408   @ 0x00034408   (12 bytes)
 * called by : usb_sub_345d2
 * calls     : rf24_sub_33d00
 */

void rf24_sub_34408(void)

{
  rf24_sub_33d00(0x3a,0x5a);
  return;
}

/* ==========================================================================
 * rf24_sub_34490   @ 0x00034490   (32 bytes)
 * calls     : rf24_sub_33d00
 */

void rf24_sub_34490(void)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = rf24_ro_3460c;
  uVar2 = 0;
  do {
    rf24_sub_33d00(puVar1[uVar2 * 2 + 0xa6],puVar1[uVar2 * 2 + 0xa7]);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x16);
  return;
}

/* ==========================================================================
 * rf24_sub_344b0   @ 0x000344b0   (40 bytes)
 * called by : rf24_sub_34538
 * calls     : rf24_sub_33d00
 */

void rf24_sub_344b0(void)

{
  undefined4 uVar1;
  
  rf24_sub_33d00(0x7f,0xc);
  if (rf24_ro_3462c[0x18] == '\0') {
    uVar1 = 8;
  }
  else {
    uVar1 = 10;
  }
  rf24_sub_33d00(0x4e,uVar1);
  rf24_sub_33d00(0x7f,0);
  return;
}

/* ==========================================================================
 * rf24_sub_344d8   @ 0x000344d8   (24 bytes)
 * called by : rf24_sub_34538
 * calls     : rf24_sub_33d00
 */

void rf24_sub_344d8(void)

{
  undefined4 uVar1;
  
  if (rf24_ro_3462c[0x19] == '\0') {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x90;
  }
  rf24_sub_33d00(0x5a,uVar1);
  return;
}

/* ==========================================================================
 * rf24_sub_344f0   @ 0x000344f0   (24 bytes)
 * called by : rf24_sub_34538
 * calls     : rf24_sub_33d00
 */

void rf24_sub_344f0(void)

{
  undefined4 uVar1;
  
  if (rf24_ro_3462c[0x1b] == '\0') {
    uVar1 = 0xd;
  }
  else {
    uVar1 = 0x8d;
  }
  rf24_sub_33d00(0x56,uVar1);
  return;
}

/* ==========================================================================
 * rf24_sub_34508   @ 0x00034508   (48 bytes)
 * called by : rf24_sub_34538
 * calls     : rf24_sub_33d00
 */

void rf24_sub_34508(void)

{
  undefined4 uVar1;
  
  if (rf24_ro_3462c[0x1c] == '\0') {
    rf24_sub_33d00(0x7f,0xd);
    uVar1 = 0xdc;
  }
  else {
    rf24_sub_33d00(0x7f,0xd);
    uVar1 = 0xdd;
  }
  rf24_sub_33d00(0x48,uVar1);
  rf24_sub_33d00(0x7f,0);
  return;
}

/* ==========================================================================
 * rf24_sub_34538   @ 0x00034538   (108 bytes)
 * called by : usb_sub_345d2, set_dpi
 * calls     : rf24_sub_33d00, rf24_sub_344b0, rf24_sub_344d8, rf24_sub_344f0, rf24_sub_34508
 */

void rf24_sub_34538(void)

{
  uint uVar1;
  
  *rf24_ro_34630 = 0;
  *rf24_ro_34634 = 0;
  uVar1 = (uint)CONCAT11(rf24_ro_3462c[(byte)rf24_ro_3462c[0x2d] + 0x24],rf24_ro_3462c[(byte)rf24_ro_3462c[0x2d] + 0x1c]
                        );
  if (1 < uVar1) {
    uVar1 = uVar1 - 2 & 0xffff;
  }
  rf24_sub_33d00(0x48,uVar1 & 0xff);
  rf24_sub_33d00(0x49,uVar1 >> 8);
  rf24_sub_33d00(0x4a,uVar1 & 0xff);
  rf24_sub_33d00(0x4b,uVar1 >> 8);
  rf24_sub_33d00(0x47,1);
  rf24_sub_344d8();
  rf24_sub_344b0();
  rf24_sub_344f0();
  rf24_sub_34508();
  return;
}

/* ==========================================================================
 * rf24_sub_345a4   @ 0x000345a4   (46 bytes)
 * called by : rf24_sub_33e24
 * calls     : rf24_sub_33d00
 */

void rf24_sub_345a4(undefined4 param_1)

{
  rf24_sub_33d00(0x48,param_1);
  rf24_sub_33d00(0x49,0);
  rf24_sub_33d00(0x4a,param_1);
  rf24_sub_33d00(0x4b,0);
  rf24_sub_33d00(0x47,1);
  return;
}

/* ==========================================================================
 * f_reconnect_24G   @ 0x00034d68   (228 bytes)
 * called by : system_mode
 * calls     : power_sub_2b128, rf24_sub_31784, ble_sub_33dc2, usb_sub_369a0, usb_sub_369ac, rf24_sub_36c8e, ... (+8 more)
 * string    : "24G reconnecting =%x \r\n"
 * string    : "f_reconnect_24G = OK \r\n"
 * string    : "f_reconnect_24G  overtime \r\n"
 * string    : "Time_24G_Piaring = 0 \r\n"
 */

void f_reconnect_24G(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  
  puVar2 = shared_ro_3508c;
  puVar1 = shared_ro_34fb8;
  if (*shared_ro_3508c != '\0') {
    *(undefined4 *)(shared_ro_34fb8 + 0x14) = 1;
    cVar5 = '\x04';
    do {
      *(undefined4 *)(puVar1 + 0x18) = 0x80;
      *(undefined4 *)(puVar1 + 0x18) = 0xa0;
      usb_sub_369ac();
      usb_sub_369a0();
      *(undefined4 *)(shared_ro_34fb8 + 0x40) = 0x10;
      led_sub_36caa();
      rf24_sub_36c8e();
      rf24_sub_31784(0x5a);
      rom_24FEC(rf24_ro_350cc,0x20);
      *rf24_ro_350cc = 0x3c;
      iVar4 = rf24_sub_36d3a(8);
      if (iVar4 != 0) break;
      bVar6 = cVar5 != '\0';
      cVar5 = cVar5 + -1;
    } while (bVar6);
    dbg_printf(str_s24G_reconnecting_x,*(undefined2 *)rf24_ro_350d0);
    puVar3 = rf24_ro_350ec;
    if (iVar4 == 0) {
      if (*(short *)rf24_ro_350d0 != 0) {
        *(undefined4 *)(puVar1 + 0x14) = 0;
        return;
      }
      *puVar2 = 0;
      dbg_printf(str_f_reconnect_24G_overtime);
      if (*(short *)puVar3 == 0) {
        *(undefined2 *)rf24_ro_3512c = 0;
        dbg_printf(str_Time_24G_Piaring_0);
        if (*shared_ro_35024 == '\0') {
          *rf24_ro_35148 = 3;
        }
        iVar4 = power_sub_2b128();
        if ((iVar4 != 0) && ((*(uint *)(shared_ro_3502c + 0x2c) & 1) == 0)) {
          ble_sub_33dc2();
          return;
        }
      }
      else {
        set_bonded_led_flash();
        *puVar2 = 1;
      }
      return;
    }
    dbg_printf(str_f_reconnect_24G_OK);
    Success_led_2second_2();
    ReLink();
    *puVar2 = 0;
    *shared_ro_34fc4 = 0;
    puVar1 = rf24_ro_35108;
    *(undefined2 *)puVar3 = 0;
    *puVar1 = 6;
    OLED_Init();
  }
  return;
}

/* ==========================================================================
 * mode_sw   @ 0x00034e4e   (156 bytes)
 * called by : system_mode
 * calls     : rf24_sub_3b130, ble_sub_3e552, dbg_printf
 * string    : " mode_sw to RF_24G_MODE\r\n"
 * string    : "mode_sw to RF_BLE_MODE1\r\n"
 */

void mode_sw(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  uint local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  puVar2 = shared_ro_3502c;
  if ((*shared_ro_35024 != '\0') && (*shared_ro_3514c != '\0')) {
    return;
  }
  *(undefined4 *)(shared_ro_3502c + 0x10) = 0xc;
  puVar4 = rf24_ro_35154;
  puVar3 = rf24_ro_35150;
  cVar5 = *rf24_ro_35150 + -1;
  cVar1 = *rf24_ro_35154;
  local_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  if (((*(uint *)(puVar2 + 0x10) & 1) == 0) &&
     (((cVar1 == '\x01' || (cVar1 == '\x02')) && (*shared_ro_3514c == '\0')))) {
    *rf24_ro_35150 = cVar5;
    puVar2 = shared_ro_35064;
    if (cVar5 != '\0') {
      return;
    }
    *puVar4 = 0;
    *puVar2 = 0;
    pcVar7 = str_mode_sw_to_RF_24G_MODE;
    *puVar3 = 5;
    goto LAB_00034edc;
  }
  if (((*(uint *)(puVar2 + 0x10) & 1) == 0) || (cVar1 != '\0')) {
    *rf24_ro_35150 = 5;
    return;
  }
  *rf24_ro_35150 = cVar5;
  if (cVar5 != '\0') {
    return;
  }
  iVar6 = ble_sub_3e552(0x38,&uStack_1c,&local_20);
  if (iVar6 == 0) {
    if (((local_20 & 0xff) != 1) && ((local_20 & 0xff) != 2)) goto LAB_00034ed2;
    *puVar4 = (undefined1)local_20;
  }
  else {
LAB_00034ed2:
    *puVar4 = 1;
  }
  *shared_ro_35064 = 0;
  pcVar7 = str_mode_sw_to_RF_BLE_MODE1;
  *puVar3 = 5;
LAB_00034edc:
  dbg_printf(pcVar7);
  rf24_sub_3b130();
  return;
}

/* ==========================================================================
 * fWorkModeInit   @ 0x00035cfe   (192 bytes)
 * called by : fn24main, switch_rf_mode_loop
 * calls     : rf24_sub_3143c, rf24_sub_31784, usb_sub_369a0, usb_sub_369d8, rf24_sub_36c8e, rf24_sub_36cd2, ... (+4 more)
 * string    : "RF24_STEP id:"
 * string    : "fWorkModeInit  RF24_STEP=%x, f_reconnect_24G=%x, Key_CurrentStatus=%x\r\n"
 */

void fWorkModeInit(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  *rf24_ro_35e48 = 0;
  *(undefined4 *)rf24_ro_35e4c = 0;
  usb_sub_369a0();
  puVar1 = rf24_ro_35e50;
  *(undefined4 *)(rf24_ro_35e50 + 0x18) = 0xa0;
  *(undefined4 *)(puVar1 + 0x18) = 0x80;
  usb_sub_369d8();
  puVar1 = shared_ro_35e54;
  if (*shared_ro_35e34 != '\0') {
    *shared_ro_35e34 = 0;
    *puVar1 = 4;
    return;
  }
  *shared_ro_35e54 = 0;
  usb_sub_36eee(8);
  puVar3 = rf24_ro_35e60;
  puVar2 = rf24_ro_35e5c;
  puVar1 = rf24_ro_35e58;
  if (*rf24_ro_35e58 == '\0') {
    if ((((*rf24_ro_35e64 == '\x05') || (*rf24_ro_35e6c != '\0')) || (rf24_ro_35e68[0x10] != '\x04')) ||
       ((rf24_ro_35e68[0x11] != '\0' || (rf24_ro_35e68[0x12] != '\0')))) {
      *rf24_ro_35e70 = rf24_ro_35e68[0x12] & 3;
      rf24_sub_36c8e();
      rf24_sub_36cd2();
      rf24_sub_31784(200);
      usb_sub_369d8();
      rf24_sub_3143c();
      *rf24_ro_35e74 = 6;
      *puVar2 = 0;
      set_bonded_led_flash();
      *puVar3 = 1;
    }
    else {
      *rf24_ro_35e5c = 2;
    }
  }
  else {
    *rf24_ro_35e5c = 2;
    *puVar1 = 0;
  }
  dbg_printf_2(str_RF24_STEP_id,rf24_ro_35e68 + 0x10,3);
  dbg_printf(rf24_ro_35e88,*puVar2,*puVar3,*(undefined2 *)shared_ro_35e38);
  return;
}

/* ==========================================================================
 * rgb_24g_test_cal   @ 0x00036234   (42 bytes)
 * called by : TEST_SINGLE_WAVE
 * calls     : ble_sub_32686, dbg_printf, rom_24F24, rom_25078
 * string    : "rgb_24g_test_cal:=%x\n"
 */

void rgb_24g_test_cal(undefined4 param_1)

{
  rom_24F24(param_1,3);
  dbg_printf(str_rgb_24g_test_cal_x);
  rom_25078();
  ble_sub_32686(1);
  return;
}

/* ==========================================================================
 * rf24_sub_36c8e   @ 0x00036c8e   (52 bytes)
 * called by : rf24_sub_2f92a, rf24_sub_2fc1e, led_sub_2ff18, LightUp_Mode_Led, RPT_STEP, SLEEP, ... (+3 more)
 */

void rf24_sub_36c8e(void)

{
  undefined *puVar1;
  
  *rf24_ro_36da0 = rf24_ro_36dac[((byte)rf24_ro_36da4[0x12] & 3) * 4 + (uint)(byte)*shared_ro_36da8 & 0xff];
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd4) = 0;
  *(uint *)(shared_ro_36d84 + 0x14) = (byte)*rf24_ro_36da0 + 0x80;
  *(undefined4 *)(puVar1 + 0xd4) = 1;
  return;
}

/* ==========================================================================
 * rf24_sub_36cd2   @ 0x00036cd2   (28 bytes)
 * called by : LightUp_Mode_Led, fWorkModeInit
 * calls     : usb_sub_369fa
 */

void rf24_sub_36cd2(void)

{
  usb_sub_369fa(shared_ro_36d84 + 0x1c,shared_ro_36d88,3);
  usb_sub_369fa(shared_ro_36d84 + 0x54,shared_ro_36d88,3);
  return;
}

/* ==========================================================================
 * rf24_sub_36d3a   @ 0x00036d3a   (78 bytes)
 * called by : rf24_sub_2f92a, rf24_sub_2fc1e, ch_frequency, f_reconnect_24G
 * calls     : rf24_sub_31784, led_sub_36ad0
 */

bool rf24_sub_36d3a(undefined4 param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  puVar1 = shared_ro_36db4;
  bVar2 = 0;
  *(undefined4 *)(shared_ro_36db4 + -0x28) = 0xa0;
  *(undefined4 *)(puVar1 + -0x28) = 0x80;
  puVar1 = shared_ro_36db4;
  *(undefined4 *)shared_ro_36db4 = 0x7e;
  led_sub_36ad0(shared_ro_36db8,param_1);
  rf24_sub_31784(0x15e);
  do {
    rf24_sub_31784(10);
    bVar2 = bVar2 + 1;
    if (5 < bVar2) break;
  } while ((*(uint *)puVar1 & 0x7f) >> 4 == 0);
  return (int)(*(uint *)puVar1 << 0x1a) < 0;
}

/* ==========================================================================
 * rf24_sub_36fb8   @ 0x00036fb8   (12 bytes)
 * called by : rf24_sub_375fe
 */

undefined2 rf24_sub_36fb8(void)

{
  return *(undefined2 *)(shared_ro_37384 + 4);
}

/* ==========================================================================
 * rf24_sub_36fce   @ 0x00036fce   (12 bytes)
 * called by : rf24_sub_375fe
 */

undefined2 rf24_sub_36fce(void)

{
  return *(undefined2 *)(shared_ro_37384 + 2);
}

/* ==========================================================================
 * rf24_sub_375fe   @ 0x000375fe   (54 bytes)
 * called by : ble_sub_3c008
 * calls     : rf24_sub_31784, rf24_sub_36fb8, rf24_sub_36fce, usb_sub_37534
 */

void rf24_sub_375fe(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  puVar3 = shared_ro_376a4;
  uVar1 = shared_ro_376a4[6];
  uVar2 = shared_ro_376a4[0xe];
  uVar4 = rf24_sub_36fce();
  uVar5 = rf24_sub_36fb8();
  if (*(short *)shared_ro_376a8 != 0) {
    rf24_sub_31784(0x3c);
  }
  usb_sub_37534(uVar5,uVar4,uVar1);
  puVar3[0xe] = uVar2;
  return;
}

/* ==========================================================================
 * rf24_sub_3aa1a   @ 0x0003aa1a   (40 bytes)
 * called by : rf24_sub_33d00, usb_sub_33d2c, ble_sub_3443a
 */

void rf24_sub_3aa1a(byte *param_1,uint param_2)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3ad08;
  do {
  } while (-1 < *(int *)(shared_ro_3ad08 + 8) << 0x1e);
  *(uint *)(shared_ro_3ad08 + 4) = param_2 << 8;
  for (; param_2 != 0; param_2 = param_2 - 1 & 0xff) {
    *(uint *)(puVar1 + 0xc) = (uint)*param_1;
    param_1 = param_1 + 1;
  }
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | 1;
  return;
}

/* ==========================================================================
 * rf24_sub_3ae7c   @ 0x0003ae7c   (6 bytes)
 * called by : rf24_sub_3ba88
 */

void rf24_sub_3ae7c(undefined1 param_1)

{
  *shared_ro_3b258 = param_1;
  return;
}

/* ==========================================================================
 * rf24_sub_3b130   @ 0x0003b130   (34 bytes)
 * called by : rf24_sub_3ba88, rf24_sub_3dc7e, SLEEP, This, USNDP_status_2, app_24_to_ble_force_pair_reset, ... (+7 more)
 * calls     : rf24_sub_31784
 */

void rf24_sub_3b130(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)(shared_ro_3b254 + -0x40);
  *(uint *)(shared_ro_3b254 + -0x3c) = *(uint *)(shared_ro_3b254 + -0x3c) | 0x8000;
  rf24_sub_31784(2000);
  *puVar1 = *puVar1 | 1;
  return;
}

/* ==========================================================================
 * rf24_sub_3b1de   @ 0x0003b1de   (26 bytes)
 * called by : app_24_to_ble_force_pair_reset
 * calls     : dbg_printf
 * string    : "set reset reason=%x\r\n"
 */

void rf24_sub_3b1de(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3b254;
  *(uint *)(shared_ro_3b254 + -0x3c) = *(uint *)(shared_ro_3b254 + -0x3c) | 8;
  *(undefined4 *)(puVar1 + -0x34) = param_1;
  dbg_printf(str_set_reset_reason_x,*(undefined4 *)(puVar1 + -0x34));
  return;
}

/* ==========================================================================
 * rf24_sub_3ba88   @ 0x0003ba88   (78 bytes)
 * calls     : rf24_sub_3ae7c, rf24_sub_3b130
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rf24_sub_3ba88(char *param_1,int param_2)

{
  byte bVar1;
  
  if (*param_1 == '\0') {
    if (param_2 == 1) {
      bVar1 = shared_ro_3bd0c[2];
      shared_ro_3bd0c[2] = bVar1 + 1;
      if (2 < bVar1) {
        rf24_sub_3ae7c(0);
      }
      param_1[1] = '\0';
      return;
    }
  }
  else if ((*param_1 == -2) && (param_2 == 5)) {
    if (((uint)(byte)param_1[4] | (uint)(byte)param_1[1] << 0x18 |
        (uint)(byte)param_1[2] << 0x10 | (uint)(byte)param_1[3] << 8) == _ro_3bd1c) {
      rf24_sub_3b130();
    }
  }
  return;
}

/* ==========================================================================
 * rf24_sub_3c0a8   @ 0x0003c0a8   (50 bytes)
 * called by : rf24_sub_28aa0
 * calls     : rf24_sub_3c150, rf24_sub_3dc7e, rf24_sub_3e1ec
 */

void rf24_sub_3c0a8(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = shared_ro_3c0dc;
  uVar2 = 0;
  iVar3 = *(int *)(shared_ro_3c0dc + 8);
  if (iVar3 << 9 < 0) {
    uVar2 = (int)shared_ro_3c0dc << 0x10;
    rf24_sub_3e1ec();
  }
  if (iVar3 << 0xb < 0) {
    uVar2 = uVar2 | 0x100000;
    rf24_sub_3dc7e();
  }
  if (iVar3 << 0xd < 0) {
    uVar2 = uVar2 | 0x40000;
    rf24_sub_3c150();
  }
  *(uint *)(puVar1 + 8) = uVar2;
  return;
}

/* ==========================================================================
 * rf24_sub_3c150   @ 0x0003c150   (20 bytes)
 * called by : rf24_sub_3c0a8
 */

void rf24_sub_3c150(void)

{
  *(undefined4 *)(rf24_ro_3c16c + 4) = 0xffffffff;
  if (*(code **)(rf24_ro_3c170 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0003c160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(rf24_ro_3c170 + 8))();
    return;
  }
  return;
}

/* ==========================================================================
 * rf24_sub_3dc7e   @ 0x0003dc7e   (50 bytes)
 * called by : rf24_sub_3c0a8
 * calls     : rf24_sub_3b130, dbg_printf
 * string    : "%s irq_stat(%x) \r\n"
 * string    : "err:%x \r\n"
 */

void rf24_sub_3dc7e(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = shared_ro_3dccc;
  while( true ) {
    iVar2 = *(int *)(puVar1 + 0x10);
    dbg_printf(str_s_irq_stat_x,rf24_ro_3dcd0,iVar2);
    if (iVar2 == 0) break;
    if (iVar2 << 0xf < 0) {
      *(undefined4 *)(puVar1 + 0x14) = 0x10000;
      dbg_printf(str_err_x,*(undefined4 *)(puVar1 + 0x60));
      rf24_sub_3b130();
    }
  }
  return;
}

/* ==========================================================================
 * rf24_sub_3dd72   @ 0x0003dd72   (28 bytes)
 * called by : rf24_sub_3e1ec
 * calls     : rom_06B28, rom_1809E
 */

void rf24_sub_3dd72(void)

{
  rom_1809E(0x10);
  reg_820018 = reg_820018 & 0xfffffffb;
  rom_06B28(1);
  return;
}

/* ==========================================================================
 * rf24_sub_3e04e   @ 0x0003e04e   (110 bytes)
 * called by : rf24_sub_3e1ec
 * calls     : rom_069C4, rom_18074, rom_24F24
 */

void rf24_sub_3e04e(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = reg_820038;
  rom_18074(1);
  reg_820030 = reg_820030 & 0x7fffffff;
  uVar4 = *(int *)(ble_ro_3e100 + 0xc) + iVar3;
  uVar2 = uVar4 >> 1;
  *(uint *)(ble_ro_3e100 + 0xc) = uVar4 + uVar2 * -2;
  iVar5 = iVar3 * 0x3e + uVar2;
  uVar2 = rom_24F24(iVar5,rf24_ro_3e1c4);
  puVar1 = rf24_ro_3e1c8;
  iVar3 = uVar2 * rf24_ro_3e1c4;
  *(uint *)(rf24_ro_3e1c8 + 4) = uVar2 | 0x80000000;
  *(uint *)puVar1 = 0x270U - (iVar5 - iVar3) & 0xffff;
  reg_820030 = reg_820030 & 0xfffffff7 | 8;
  reg_820018 = 1;
  reg_820020 = 0xffffffff;
  rom_069C4();
  return;
}

/* ==========================================================================
 * rf24_sub_3e1ec   @ 0x0003e1ec   (124 bytes)
 * called by : rf24_sub_3c0a8
 * calls     : ble_sub_3dd00, ble_sub_3dd1c, ble_sub_3dd3a, rf24_sub_3dd72, rf24_sub_3e04e, ble_sub_3e0bc, ... (+3 more)
 */

void rf24_sub_3e1ec(void)

{
  uint uVar1;
  
  uVar1 = reg_82001c;
  if ((int)(reg_82001c << 0x1b) < 0) {
    reg_820020 = 0x10;
    ble_sub_3dd00();
  }
  if ((int)(uVar1 << 0x1a) < 0) {
    reg_820020 = 0x20;
    ble_sub_3dd3a();
  }
  if ((uVar1 & 1) != 0) {
    reg_820020 = 1;
    if ((shared_ro_3e444[0x16] & 1) != 0) {
      ble_sub_3e0bc();
    }
  }
  if ((int)(uVar1 << 0x10) < 0) {
    rom_1695E();
    reg_820020 = 0x8000;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    reg_820020 = 2;
    rf24_sub_3e04e();
    rom_1809E(0x1000);
  }
  if ((int)(uVar1 << 0x19) < 0) {
    reg_820020 = 0x40;
    ble_sub_3dd1c();
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    reg_820020 = 4;
    rf24_sub_3dd72();
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    reg_820020 = 8;
    rom_18038();
  }
  return;
}
