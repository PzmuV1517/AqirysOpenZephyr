/* Mouse input (sensor, keys)
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * KEY_piaring_cnt   @ 0x0002b492   (54 bytes)
 * called by : flash_sub_29a04, ble_sub_2b4c8, ble_sub_2d53c, ble_sub_3e5f0, app_24_to_ble_reset, app_ble_to_ble_mode, ... (+7 more)
 * calls     : dbg_printf
 * string    : "KEY_piaring_cnt :[ %x  to  %x ] %x\r\n"
 */

void KEY_piaring_cnt(void)

{
  undefined *puVar1;
  char cVar2;
  
  puVar1 = shared_ro_2b598;
  if (((*shared_ro_2b51c != '\0') && (*shared_ro_2b520 == '\0')) && (shared_ro_2b598[6] == '\0')) {
    cVar2 = *input_ro_2b698 + '\x01';
    *input_ro_2b698 = cVar2;
    puVar1[5] = cVar2;
    dbg_printf(str_KEY_piaring_cnt_x_to_x_x,*shared_ro_2b54c,cVar2);
  }
  return;
}

/* ==========================================================================
 * input_sub_311b4   @ 0x000311b4   (42 bytes)
 * called by : sensor_init, sensor_pwdn
 * calls     : ble_sub_39a84, input_sub_39af0, input_sub_3a900
 */

void input_sub_311b4(void)

{
  ble_sub_39a84(0x33,0);
  input_sub_3a900(0,5);
  ble_sub_39a84(7,1,2);
  input_sub_39af0(7,1);
  return;
}

/* ==========================================================================
 * set_Update_OLED   @ 0x0003299c   (366 bytes)
 * called by : system_mode
 * calls     : ble_sub_32620, flash_sub_32658, led_sub_3ce52, flash_sub_3cf7c, power_sub_3d508, power_sub_3d546, ... (+3 more)
 * string    : "Dpi_Indicat_process= %x\r\n"
 * string    : "set_Update_OLED--Set_Loop_process \r\n"
 * string    : "set_Update_OLED--Flash_Linking_process \r\n"
 * string    : "set_Update_OLED--Flash_Ind_Fast_process0 \r\n"
 * string    : "set_Update_OLED--Flash_Ind_Fast_process1 \r\n"
 */

undefined * set_Update_OLED(void)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  short sVar8;
  
  bVar1 = *shared_ro_32a64;
  if (bVar1 == 0) {
    puVar6 = (undefined *)0x0;
    if (*shared_ro_32d5c != '\0') {
      return (undefined *)(uint)(byte)*shared_ro_32d60;
    }
  }
  else {
    *(undefined2 *)shared_ro_32b04 = 400;
    puVar5 = shared_ro_32d54;
    puVar4 = shared_ro_32a54;
    sVar3 = *(short *)shared_ro_32a58;
    puVar6 = (undefined *)(uint)(byte)*shared_ro_32a54;
    sVar8 = sVar3 + -1;
    uVar2 = *shared_ro_32a50;
    if (bVar1 == 0x3c) {
      if (puVar6 != (undefined *)0x0) {
        return puVar6;
      }
      *shared_ro_32a54 = uVar2;
      if (*puVar5 == '\0') {
        if (sVar3 == 0) {
          *shared_ro_32d58 = 0;
          puVar6 = input_ro_32d9c;
          *puVar4 = 0;
          *(undefined2 *)puVar6 = 0;
        }
        else {
          *(short *)shared_ro_32d98 = sVar8;
          *puVar5 = 1;
        }
        puVar6 = (undefined *)ble_sub_32620();
        return puVar6;
      }
      *puVar5 = 0;
      puVar6 = (undefined *)flash_sub_32658();
      return puVar6;
    }
    if (0x3c < bVar1) {
      if (bVar1 == 0x3d) {
        if (puVar6 != (undefined *)0x0) {
          return puVar6;
        }
        *shared_ro_32a54 = uVar2;
        puVar6 = shared_ro_32d50;
        if (*puVar5 == '\0') {
          if (sVar3 == 0) {
            *shared_ro_32d58 = 0;
            puVar6 = input_ro_32d9c;
            *puVar4 = 0;
            *(undefined2 *)puVar6 = 0;
            ble_sub_32620();
            puVar6 = (undefined *)flash_sub_3cf7c();
            return puVar6;
          }
          *(short *)shared_ro_32d98 = sVar8;
          *puVar5 = 1;
          ble_sub_32620();
          led_sub_3ce52();
          pcVar7 = str_set_Update_OLED_Flash_Ind_Fast_process0;
        }
        else {
          *puVar5 = 0;
          flash_sub_32658();
          if (*puVar6 == '\x01') {
            Pairing();
          }
          else if (*puVar6 == '\x02') {
            ReLinking();
          }
          pcVar7 = str_set_Update_OLED_Flash_Linking_process;
        }
      }
      else {
        if (bVar1 != 0x3e) {
          return puVar6;
        }
        if (puVar6 != (undefined *)0x0) {
          return puVar6;
        }
        if ((undefined *)(uint)(byte)*input_ro_32d64 != (undefined *)0x0) {
          return (undefined *)(uint)(byte)*input_ro_32d64;
        }
        *shared_ro_32a54 = uVar2;
        if (*puVar5 == '\0') {
          if (sVar3 == 0) {
            *shared_ro_32d58 = 0;
            puVar6 = input_ro_32d9c;
            *puVar4 = 0;
            *(undefined2 *)puVar6 = 0;
          }
          else {
            *(short *)shared_ro_32d98 = sVar8;
            *puVar5 = 1;
          }
          *input_ro_32dfc = 2;
          puVar6 = input_ro_32e2c;
          *input_ro_32e2c = 1;
          return puVar6;
        }
        *puVar5 = 0;
        puVar6 = input_ro_32df8;
        if (*input_ro_32d68 != '\0') {
          puVar6 = input_ro_32d6c;
        }
        *puVar6 = 1;
        *input_ro_32dfc = 2;
        pcVar7 = str_set_Update_OLED_Flash_Ind_Fast_process1;
      }
      puVar6 = (undefined *)dbg_printf(pcVar7);
      return puVar6;
    }
    if (bVar1 != 0) {
      if (bVar1 == 2) {
        if (puVar6 == (undefined *)0x0) {
          power_sub_3d508();
          power_sub_3d546();
          dbg_printf(str_set_Update_OLED_Set_Loop_process);
          puVar6 = shared_ro_32d58;
          *shared_ro_32d58 = 0;
          return puVar6;
        }
        return puVar6;
      }
      if (bVar1 == 0x32) {
        dbg_printf(str_Dpi_Indicat_process_x);
        *shared_ro_32d50 = 1;
        puVar6 = shared_ro_32d54;
        *puVar4 = 1;
        *puVar6 = 1;
        puVar6 = shared_ro_32d58;
        *shared_ro_32d58 = 0x3c;
      }
    }
  }
  return puVar6;
}

/* ==========================================================================
 * input_sub_33db8   @ 0x00033db8   (8 bytes)
 * calls     : input_sub_34426
 */

void input_sub_33db8(void)

{
  input_sub_34426();
  return;
}

/* ==========================================================================
 * sensor_pwdn   @ 0x00033dca   (36 bytes)
 * called by : usb_sub_360aa, SLEEP, exist, force_ble_sleep_2
 * calls     : input_sub_311b4, input_sub_34414, ble_sub_39a84, dbg_printf
 * string    : "sensor_pwdn"
 * string    : "%s \r\n"
 */

void sensor_pwdn(void)

{
  *shared_ro_33fb4 = 0;
  ble_sub_39a84(0x32,0,0);
  input_sub_311b4();
  input_sub_34414();
  dbg_printf(str_s_10,input_ro_33fb8);
  return;
}

/* ==========================================================================
 * sensor_init   @ 0x00033dee   (28 bytes)
 * called by : ble_sub_2f31c, enter_BLE_normal_app_mode, f_usb_isConnected, time_sensor_invalid
 * calls     : input_sub_311b4, usb_sub_345d2, dbg_printf
 * string    : "%s \r\n"
 * string    : "sensor_init"
 */

void sensor_init(void)

{
  input_sub_311b4();
  usb_sub_345d2();
  dbg_printf(str_s_11,str_sensor_init);
  *shared_ro_33fb4 = 1;
  return;
}

/* ==========================================================================
 * set_dpi   @ 0x00033e0a   (26 bytes)
 * called by : Default_Profile, _saveC_GM_ProfileMax, f_usb_isConnected, time_sensor_invalid
 * calls     : rf24_sub_34538, dbg_printf
 * string    : "%s \r\n"
 * string    : "set_dpi"
 */

void set_dpi(void)

{
  if (*shared_ro_33fb4 != '\0') {
    rf24_sub_34538();
    dbg_printf(str_s_11,input_ro_33fb8 + -8);
  }
  return;
}

/* ==========================================================================
 * time_sensor_invalid   @ 0x00033e34   (264 bytes)
 * called by : ble_sub_2f31c, led_sub_2ff18, usb_sub_358b6, usb_sub_3870a
 * calls     : input_sub_34426, ble_sub_3443a, OLED_Init, dbg_printf, sensor_init, set_dpi
 * string    : "time_sensor_invalid=0\r\n"
 */

void time_sensor_invalid(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  byte bVar7;
  
  puVar2 = input_ro_33fd4;
  puVar1 = input_ro_33fd0;
  if (*input_ro_33fcc == '\0') {
    *(undefined2 *)input_ro_33fd0 = 0;
    *(undefined2 *)puVar2 = 0;
  }
  puVar2 = input_ro_33fec;
  if ((*shared_ro_33fd8 != '\0') &&
     ((((*(short *)input_ro_33fdc == 0 || (*input_ro_33fe0 == '\0')) && (*shared_ro_33fb4 != '\0')) &&
      ((*input_ro_33fe4 == '\0' || (*input_ro_33fe8 != '\0')))))) {
    if ((*(uint *)(shared_ro_33f70 + 0x6c) & 1) == 0) {
      ble_sub_3443a();
      puVar4 = shared_ro_33ff8;
      puVar3 = shared_ro_33ff4;
      if (*(short *)shared_ro_33ff4 != 0 || *(short *)shared_ro_33ff8 != 0) {
        *input_ro_33ffc = 1;
        OLED_Init();
        puVar5 = input_ro_34000;
        *puVar2 = 8;
        *puVar5 = 0xf;
        *input_ro_34004 = 0x14;
        if (*input_ro_34008 != '\0') {
          *(short *)puVar3 = *(short *)puVar3 << 1;
        }
        if (*input_ro_3400c != '\0') {
          *(short *)puVar4 = *(short *)puVar4 << 1;
        }
        puVar2 = input_ro_33fd4;
        *(short *)puVar1 = *(short *)puVar1 + *(short *)puVar3;
        *(short *)puVar2 = *(short *)puVar2 + *(short *)puVar4;
        if (*input_ro_34010 != '\0') {
          *(undefined2 *)puVar3 = 0;
          *(undefined2 *)puVar4 = 0;
          *(undefined2 *)puVar1 = 0;
          *(undefined2 *)puVar2 = 0;
          *input_ro_33ffc = 0;
          dbg_printf(str_time_sensor_invalid_0);
        }
        *(undefined2 *)input_ro_3402c = 400;
        return;
      }
    }
    else if ((*input_ro_33fec == '\0') && (*shared_ro_33fb4 == '\0')) {
      bVar7 = 0;
      *input_ro_33fec = 8;
      do {
        iVar6 = input_sub_34426();
        if (iVar6 != 0) {
          return;
        }
        bVar7 = bVar7 + 1;
      } while (bVar7 < 4);
      *input_ro_33ff0 = 1;
      sensor_init();
      set_dpi();
      *puVar2 = 2;
    }
  }
  return;
}

/* ==========================================================================
 * input_sub_34414   @ 0x00034414   (18 bytes)
 * called by : sensor_pwdn
 * calls     : usb_sub_317c2, rf24_sub_33d00
 */

void input_sub_34414(void)

{
  rf24_sub_33d00(0x3b,0xb6);
  usb_sub_317c2(0x3c);
  return;
}

/* ==========================================================================
 * input_sub_34426   @ 0x00034426   (20 bytes)
 * called by : input_sub_33db8, time_sensor_invalid
 * calls     : usb_sub_33d2c
 */

undefined4 input_sub_34426(void)

{
  int iVar1;
  
  iVar1 = usb_sub_33d2c(0);
  if (iVar1 != 0x51) {
    return 0;
  }
  return 1;
}

/* ==========================================================================
 * Disconnected   @ 0x0003463c   (80 bytes)
 * called by : ble_sub_3186e
 * calls     : ble_sub_295aa, ble_sub_312aa, Set_SIMU_mode_LightUp_Led, app_user_ke_timer_stop, ble_alert_led_stop, dbg_printf, ... (+2 more)
 * string    : "Disconnected by mouse...\r\n"
 */

void Disconnected(void)

{
  int iVar1;
  
  if (*shared_ro_34a34 == '\0') {
    app_user_ke_timer_stop();
    ble_alert_led_stop();
    ble_sub_312aa();
    *input_ro_34a38 = 0;
    iVar1 = rom_071EA(3);
    if (iVar1 == 3) {
      dbg_printf(str_Disconnected_by_mouse_2);
      *(uint *)input_ro_34a58 = *(uint *)input_ro_34a58 | 0x100;
      ble_sub_295aa();
    }
    *input_ro_34a5c = 0;
    Set_SIMU_mode_LightUp_Led();
    switch_rf_mode_loop();
    *input_ro_34a60 = 1;
  }
  return;
}

/* ==========================================================================
 * input_sub_39af0   @ 0x00039af0   (34 bytes)
 * called by : input_sub_311b4, input_sub_39bae
 */

void input_sub_39af0(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(shared_ro_39c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4);
  if (param_2 == 0) {
    uVar1 = uVar1 & 0xfffffffd;
  }
  else {
    uVar1 = uVar1 | 2;
  }
  *(uint *)(shared_ro_39c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4) = uVar1;
  return;
}

/* ==========================================================================
 * input_sub_39bae   @ 0x00039bae   (20 bytes)
 * calls     : input_sub_39af0
 */

void input_sub_39bae(undefined4 param_1)

{
  input_sub_39af0(param_1,1);
  input_sub_39af0(param_1,0);
  return;
}

/* ==========================================================================
 * input_sub_3a900   @ 0x0003a900   (114 bytes)
 * called by : input_sub_311b4
 * calls     : ble_sub_39a84
 */

void input_sub_3a900(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint uVar2;
  
  reg_80000c = reg_80000c & 0xffffdfff;
  *(undefined4 *)(input_ro_3ad04 + 0x1c) = 2;
  ble_sub_39a84(4,3,2,param_4,param_4);
  ble_sub_39a84(5,3,2);
  ble_sub_39a84(6,3,2);
  puVar1 = shared_ro_3ad08;
  *(uint *)shared_ro_3ad08 = param_3 << 0x12 | param_2 << 8 | 0xb00000;
  if (param_1 == 0) {
    uVar2 = 0x400000;
  }
  else {
    uVar2 = 0x10000;
  }
  *(uint *)puVar1 = *(uint *)puVar1 | uVar2;
  puVar1 = shared_ro_3ad0c;
  reg_800010 = reg_800010 & 0xfffff7ff;
  shared_ro_3ad0c[1] = 1;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}

/* ==========================================================================
 * input_sub_3cd24   @ 0x0003cd24   (146 bytes)
 * called by : usb_sub_3cdb6, input_sub_3ce00, usb_sub_3ce5c, usb_sub_3cf24, input_sub_3d57c, input_sub_3d5dc, ... (+3 more)
 * calls     : usb_sub_3b54e, usb_sub_3c9f2, usb_sub_3cb9a
 */

void input_sub_3cd24(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 local_20;
  
  uVar1 = 0;
  usb_sub_3b54e();
  *shared_ro_3d0b4 = 1;
  local_20 = param_2;
  do {
    if (*(char *)(param_4 + uVar1) == '\0') {
      *input_ro_3d0b8 = 0;
      return;
    }
    if (*input_ro_3d0b8 == '\0') {
      usb_sub_3c9f2(param_1,local_20,param_3);
    }
    else {
      usb_sub_3cb9a(param_1,local_20,param_3);
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
 * input_sub_3ce00   @ 0x0003ce00   (82 bytes)
 * called by : FLASH_WR_Profile, flash_sub_3cf7c, usb_sub_3d2b0, f_usb_isConnected
 * calls     : input_sub_3cd24, input_sub_429d4
 * string    : "%d dpi   "
 * string    : "%d dpi  "
 * string    : "%d dpi "
 * string    : "%d dpi"
 */

void input_sub_3ce00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar2 = ((uint)(byte)shared_ro_3d0ec[(byte)shared_ro_3d0ec[0xd] + 4] << 8 |
          (byte)shared_ro_3d0ec[(byte)shared_ro_3d0ec[0xd] - 4] + 1) * 0x32 & 0xffff;
  if (uVar2 < 100) {
    pcVar1 = str_d_dpi;
  }
  else if (uVar2 < 1000) {
    pcVar1 = str_d_dpi_2;
  }
  else if (uVar2 < input_ro_3d108) {
    pcVar1 = str_d_dpi_3;
  }
  else {
    pcVar1 = str_d_dpi_4;
  }
  uStack_10 = param_2;
  uStack_c = param_3;
  uStack_8 = param_4;
  input_sub_429d4(&uStack_10,pcVar1);
  input_sub_3cd24(0,1,1,&uStack_10);
  return;
}

/* ==========================================================================
 * input_sub_3d57c   @ 0x0003d57c   (66 bytes)
 * calls     : input_sub_3cd24
 */

void input_sub_3d57c(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  
  cVar1 = *input_ro_3d6c4;
  if (cVar1 == '\0') {
    input_sub_3cd24(0x4c,1,2,&input_ro_3d6cc);
    uVar2 = 0x5e;
    ppuVar3 = &input_ro_3d6d0;
  }
  else {
    if (cVar1 == '\x01') {
      ppuVar3 = (undefined **)(usb_ro_3d0dc);
    }
    else {
      ppuVar3 = (undefined **)shared_ro_3d6c8;
      if (cVar1 == '\x02') {
        ppuVar3 = (undefined **)(usb_ro_3d0e4);
      }
    }
    uVar2 = 0x48;
  }
  input_sub_3cd24(uVar2,1,2,ppuVar3);
  return;
}

/* ==========================================================================
 * input_sub_3d5dc   @ 0x0003d5dc   (94 bytes)
 * calls     : input_sub_3cd24, input_sub_429d4
 * string    : "%d   "
 * string    : "DPI        "
 */

void input_sub_3d5dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar2 = ((uint)(byte)input_ro_3d6d8[(byte)input_ro_3d6d8[0xd] + 4] << 8 |
          (byte)input_ro_3d6d8[(byte)input_ro_3d6d8[0xd] - 4] + 1) * 0x32 & 0xffff;
  if (uVar2 < 100) {
    pcVar1 = str_d_4;
  }
  else if (uVar2 < 1000) {
    pcVar1 = &input_ro_3d6e4;
  }
  else if (uVar2 < input_ro_3d6ec) {
    pcVar1 = &input_ro_3d6f0;
  }
  else {
    pcVar1 = &input_ro_3d6f4;
  }
  uStack_10 = param_2;
  uStack_c = param_3;
  uStack_8 = param_4;
  input_sub_429d4(&uStack_10,pcVar1);
  input_sub_3cd24(0,0,0,str_DPI);
  input_sub_3cd24(0x19,0,0,&uStack_10);
  return;
}

/* ==========================================================================
 * input_sub_42484   @ 0x00042484   (202 bytes)
 * called by : input_sub_42b18
 * calls     : input_sub_425ea
 */

void input_sub_42484(int param_1,uint param_2,int param_3,uint param_4)

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
    input_sub_425ea(local_30,local_2c,local_38,local_34,0,(param_2 ^ param_4) & 0x80000000,
                 ((param_2 & 0x7fffffff) >> 0x14) + ((param_4 & 0x7fffffff) >> 0x14) + input_ro_42550);
  }
  return;
}

/* ==========================================================================
 * input_sub_42554   @ 0x00042554   (24 bytes)
 * calls     : input_sub_425ea
 */

void input_sub_42554(undefined4 param_1)

{
  input_sub_425ea(param_1,0,0,0,0,0,input_ro_4256c);
  return;
}

/* ==========================================================================
 * input_sub_42570   @ 0x00042570   (96 bytes)
 * called by : input_sub_42b18, input_sub_42c70
 * calls     : input_sub_4296c, input_sub_4298c
 */

longlong input_sub_42570(uint param_1,int param_2,uint param_3,uint param_4)

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
    uVar6 = input_sub_4298c(param_1,local_2c,iVar4);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = iVar4;
    if (param_4 < uVar2 || uVar2 - param_4 < (uint)(param_3 <= (uint)uVar6)) {
      uVar6 = input_sub_4296c(param_3,param_4,iVar4);
      bVar5 = param_1 < (uint)uVar6;
      param_1 = param_1 - (uint)uVar6;
      local_2c = (local_2c - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;
      lVar7 = input_sub_4296c(1,0,iVar4);
      lVar1 = lVar7 + lVar1;
    }
  }
  return lVar1;
}

/* ==========================================================================
 * input_sub_425d0   @ 0x000425d0   (26 bytes)
 * called by : input_sub_425ea, input_sub_42690, input_sub_427f4
 */

undefined8 input_sub_425d0(uint param_1,int param_2,uint param_3,int param_4)

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
 * input_sub_425ea   @ 0x000425ea   (164 bytes)
 * called by : input_sub_42484, input_sub_42554, input_sub_42690
 * calls     : input_sub_425d0, input_sub_4296c, input_sub_4298c, rom_2501C
 */

uint input_sub_425ea(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
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
  uVar4 = input_sub_4296c(param_1,param_2,iVar1);
  uVar2 = (uint)(uVar4 >> 0x20);
  uVar3 = (uint)uVar4;
  if ((uVar3 != 0 || param_3 != 0) || (uVar2 != 0 || param_4 != 0)) {
    if (param_3 != 0 || param_4 != 0) {
      uVar5 = input_sub_4298c(param_3,param_4,0x40 - iVar1);
      lVar6 = input_sub_4296c(param_3,param_4,iVar1);
      uVar4 = CONCAT44(uVar2 | (uint)((ulonglong)uVar5 >> 0x20),
                       uVar3 | (uint)uVar5 | (uint)(lVar6 != 0));
    }
    uVar3 = (uint)(uVar4 >> 0xb);
    iVar1 = (param_7 - iVar1) + 10;
    if (iVar1 < 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = input_sub_425d0(uVar3 + param_5,
                           iVar1 * 0x100000 + (int)((uVar4 >> 0xb) >> 0x20) + param_6 +
                           (uint)CARRY4(uVar3,param_5),0,(int)uVar4 << 0x15);
    }
  }
  return uVar3;
}

/* ==========================================================================
 * input_sub_42690   @ 0x00042690   (326 bytes)
 * called by : input_sub_42b18
 * calls     : input_sub_425d0, input_sub_425ea, input_sub_4296c, input_sub_429ae
 */

uint input_sub_42690(uint param_1,uint param_2,uint param_3,uint param_4)

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
      uVar8 = input_sub_4296c(uVar5,uVar3,0x40 - iVar2);
      uVar6 = (uint)(uVar8 >> 0x20);
      uVar4 = (uint)uVar8;
      lVar9 = input_sub_429ae(uVar5,uVar3,iVar2,&local_24);
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
            uVar5 = input_sub_425ea(uVar5,uVar3 + local_24 * -0x100000 + 0x100000,uVar4,uVar6,0,
                                 ((local_24 & 0xfff) >> 0xb) << 0x1f,local_1c);
            return uVar5;
          }
          lVar9 = CONCAT44(local_24 * -0x100000 + input_ro_427f0 +
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
    param_1 = input_sub_425d0((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),(int)uVar8,
                           (int)(uVar8 >> 0x20));
  }
  return param_1;
}

/* ==========================================================================
 * input_sub_427f4   @ 0x000427f4   (234 bytes)
 * called by : input_sub_42b18
 * calls     : input_sub_425d0
 */

void input_sub_427f4(uint param_1,uint param_2,uint param_3,uint param_4)

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
    iVar1 = (((param_2 & 0x7fffffff) >> 0x14) - ((param_4 & 0x7fffffff) >> 0x14)) + input_ro_428e0;
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
      input_sub_425d0(uVar7,iVar1 * 0x100000 + uVar8 + ((param_2 ^ param_4) & 0x80000000),param_1,uVar4
                  );
    }
  }
  return;
}

/* ==========================================================================
 * input_sub_428e4   @ 0x000428e4   (54 bytes)
 * called by : input_sub_42b18
 * calls     : input_sub_4296c, input_sub_4298c
 */

void input_sub_428e4(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 & 0xfffff | 0x100000;
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  if ((int)uVar2 < input_ro_4291c) {
    return;
  }
  if ((int)uVar2 <= input_ro_4291c + 0x34) {
    input_sub_4298c(param_1,uVar1,(input_ro_4291c + 0x34) - uVar2);
    return;
  }
  input_sub_4296c(param_1,uVar1,uVar2 + input_ro_42920);
  return;
}

/* ==========================================================================
 * input_sub_42924   @ 0x00042924   (38 bytes)
 * called by : input_sub_42b18
 */

int input_sub_42924(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}

/* ==========================================================================
 * input_sub_4296c   @ 0x0004296c   (32 bytes)
 * called by : input_sub_42570, input_sub_425ea, input_sub_42690, input_sub_428e4
 */

longlong input_sub_4296c(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}

/* ==========================================================================
 * input_sub_4298c   @ 0x0004298c   (34 bytes)
 * called by : input_sub_42570, input_sub_425ea, input_sub_428e4
 */

ulonglong input_sub_4298c(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}

/* ==========================================================================
 * input_sub_429ae   @ 0x000429ae   (38 bytes)
 * called by : input_sub_42690
 */

undefined8 input_sub_429ae(uint param_1,uint param_2,uint param_3)

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
 * input_sub_429d4   @ 0x000429d4   (36 bytes)
 * called by : input_sub_3ce00, usb_sub_3ce5c, input_sub_3d5dc
 * calls     : input_sub_42c70, input_sub_433b0
 */

undefined4 input_sub_429d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  uVar1 = input_sub_42c70(param_2,&uStack_8,&uStack_10,input_ro_429f8);
  input_sub_433b0(0,&uStack_10);
  return uVar1;
}

/* ==========================================================================
 * input_sub_42b18   @ 0x00042b18   (316 bytes)
 * called by : input_sub_42c70
 * calls     : input_sub_42484, input_sub_42570, input_sub_42690, input_sub_427f4, input_sub_428e4, input_sub_42924
 */

int * input_sub_42b18(int *param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6)

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
    *param_1 = (int)&input_ro_42c64;
    param_1[3] = param_6;
    param_1[1] = param_5;
  }
  else {
    iVar5 = (int)(input_ro_42c58 * ((param_4 >> 0x14) + input_ro_42c54)) >> 0x10;
    do {
      while( true ) {
        if (param_6 == 1) {
          uVar1 = -param_5;
        }
        else {
          uVar1 = (iVar5 - param_5) + 1;
        }
        lVar10 = (ulonglong)input_ro_42c5c << 0x20;
        lVar12 = (ulonglong)input_ro_42c60 << 0x20;
        uVar7 = uVar1;
        if ((int)uVar1 < 0) {
          uVar7 = -uVar1;
          lVar12 = (ulonglong)input_ro_42c60 << 0x20;
          lVar10 = (ulonglong)input_ro_42c5c << 0x20;
        }
        while( true ) {
          uVar6 = (undefined4)((ulonglong)lVar10 >> 0x20);
          local_34 = (undefined4)((ulonglong)lVar12 >> 0x20);
          local_38 = (undefined4)lVar12;
          if (uVar7 == 0) break;
          if ((uVar7 & 1) != 0) {
            lVar12 = input_sub_42484(local_38,local_34,(int)lVar10,uVar6);
          }
          lVar10 = input_sub_42484((int)lVar10,uVar6);
          uVar7 = (int)uVar7 >> 1;
        }
        uVar8 = 1;
        if ((int)uVar1 < 0) {
          uVar11 = input_sub_42484();
        }
        else {
          uVar11 = input_sub_427f4(param_3,param_4,local_38,local_34);
        }
        bVar9 = true;
        input_sub_42924();
        if ((bool)uVar8 && !bVar9) {
          input_sub_42690((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,input_ro_42c6c);
          lVar12 = input_sub_428e4();
        }
        else {
          lVar12 = -1;
        }
        for (iVar4 = 0x10; (lVar12 != 0 && (-1 < iVar4)); iVar4 = iVar4 + -1) {
          cVar2 = '\n';
          lVar12 = input_sub_42570();
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
 * input_sub_42c70   @ 0x00042c70   (1720 bytes)
 * called by : input_sub_429d4, ble_sub_429fc
 * calls     : input_sub_42570, input_sub_42b18, input_sub_43364, input_sub_43384, rom_24F24
 * string    : "0123456789abcdef"
 * string    : "0123456789ABCDEF"
 */

/* WARNING: Type propagation algorithm not settling */

int input_sub_42c70(byte *param_1,uint *param_2,undefined4 param_3,code *param_4)

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
      if ((uVar5 & input_ro_43064) == 0) break;
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
          lVar24 = input_sub_42570((int)lVar24,(int)((ulonglong)lVar24 >> 0x20),iVar6,uVar13);
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
          iVar6 = input_sub_43384(local_70,uVar15,local_1c,local_18);
          iVar16 = iVar6 + iVar16;
        }
        for (iVar6 = 0; iVar6 < (int)local_78; iVar6 = iVar6 + 1) {
          (*local_18)(*(undefined1 *)((int)&local_74 + iVar6),local_1c);
          iVar16 = iVar16 + 1;
        }
        if ((int)(uVar15 << 0xf) < 0) {
          iVar6 = input_sub_43384(local_70,uVar15,local_1c,local_18);
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
          iVar6 = input_sub_43384(uVar5,uVar15,local_1c,local_18);
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
    puVar18 = &rom_ro_6;
  }
  puVar11 = (undefined4 *)((uint)((int)local_20 + 7) & 0xfffffff8);
  uVar13 = *puVar11;
  local_20 = puVar11 + 2;
  if ((puVar11[1] & 0x80000000) == 0) {
    if ((int)(uVar15 << 0x14) < 0) {
      local_40 = &input_ro_43358;
    }
    else if ((uVar15 & 1) == 0) {
      local_40 = &input_ro_43360;
    }
    else {
      local_40 = &input_ro_4335c;
    }
  }
  else {
    local_40 = &input_ro_43354;
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
    input_sub_42b18(&local_3c,local_63 + 3,uVar13,uVar14,puVar12,0);
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
      input_sub_42b18(&local_3c,local_63 + 3,uVar13,uVar14,puVar12,0);
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
    input_sub_42b18(&local_3c,local_63 + 3,uVar13,uVar14,puVar18,1);
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
    iVar6 = input_sub_43384(local_70,uVar15,local_1c,local_18);
    iVar16 = iVar6 + iVar16;
  }
  if (*local_40 != '\0') {
    (*local_18)(*local_40,local_1c);
    iVar16 = iVar16 + 1;
  }
  iVar6 = iVar16;
  puVar18 = in_stack_ffffff84;
  if ((int)(uVar15 << 0xf) < 0) {
    iVar6 = input_sub_43384(local_70,uVar15,local_1c,local_18);
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
  iVar6 = input_sub_43364(uVar5,uVar15,local_1c,local_18);
  iVar16 = iVar6 + iVar16;
LAB_000430b4:
  param_1 = param_1 + 1;
  goto LAB_000430b6;
}

/* ==========================================================================
 * input_sub_43364   @ 0x00043364   (32 bytes)
 * called by : input_sub_42c70
 */

int input_sub_43364(int param_1,int param_2,undefined4 param_3,code *param_4)

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
 * input_sub_43384   @ 0x00043384   (44 bytes)
 * called by : input_sub_42c70
 */

int input_sub_43384(int param_1,int param_2,undefined4 param_3,code *param_4)

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
 * input_sub_433b0   @ 0x000433b0   (10 bytes)
 * called by : input_sub_429d4, ble_sub_429fc
 */

void input_sub_433b0(undefined1 param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *param_2 = puVar1 + 1;
  *puVar1 = param_1;
  return;
}
