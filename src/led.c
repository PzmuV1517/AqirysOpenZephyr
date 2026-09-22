/* LED and OLED
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * led_sub_2a69e   @ 0x0002a69e   (112 bytes)
 * called by : tx_failed_cnt
 * calls     : dbg_printf
 * string    : "try high rate............%d ,%d\r\n"
 */

void led_sub_2a69e(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = *(ushort *)led_ro_2a970;
  if (uVar2 < 500) {
    uVar2 = uVar2 + 1;
    *(ushort *)led_ro_2a970 = uVar2;
  }
  if (uVar2 == 100) {
    cVar1 = ble_ro_2a8a4[4];
    if (cVar1 == '\x06') {
      iVar3 = shared_ro_2a94c + 0x54;
    }
    else if (cVar1 == '\a') {
      iVar3 = shared_ro_2a7cc + -0x9b;
    }
    else if (cVar1 == '\b') {
      iVar3 = 1000;
    }
    else if (cVar1 == '\t') {
      iVar3 = shared_ro_2a7cc + 0x5f;
    }
    else if (cVar1 == '\n') {
      iVar3 = shared_ro_2a7cc + 0xdc;
    }
    else {
      iVar3 = led_ro_2a9a0;
      if ((cVar1 != '\v') && (iVar3 = led_ro_2a978, cVar1 == '\f')) {
        iVar3 = led_ro_2a9a0 + 0x7d;
      }
    }
    *(int *)led_ro_2a974 = iVar3;
    dbg_printf(str_try_high_rate_d_d);
  }
  return;
}

/* ==========================================================================
 * set_Update_OLED_2   @ 0x0002ace0   (514 bytes)
 * called by : SLEEP, enter_BLE_normal_app_mode, f_usb_isConnected, system_mode
 * calls     : led_sub_328c2, power_sub_3b568, led_sub_3b5b6, power_sub_3b5f8, dbg_printf, force_24g_sleep, ... (+1 more)
 * string    : "set_Update_OLED--f_bat_low 1\r\n"
 * string    : "set_Update_OLED--f_bat_low 2\r\n"
 * string    : "f_bat_ll_low _ process ..\r\n"
 */

void set_Update_OLED_2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  
  if ((*led_ro_2ae0c != '\0') && (*led_ro_2ae10 == '\0')) {
    return;
  }
  *led_ro_2ae0c = 4;
  power_sub_3b568(2,1,param_3,param_4,param_4);
  iVar6 = power_sub_3b5f8(2,1);
  led_sub_3b5b6(2);
  puVar3 = led_ro_2ae1c;
  puVar2 = led_ro_2ae18;
  if (iVar6 == led_ro_2ae14) {
    iVar6 = 0;
  }
  uVar7 = (uint)*(ushort *)led_ro_2ae18 + iVar6 & 0xffff;
  *(short *)led_ro_2ae18 = (short)((uint)*(ushort *)led_ro_2ae18 + iVar6);
  cVar1 = *puVar3;
  if ((cVar1 != '\0') && (*led_ro_2ae1c = cVar1 + -1, cVar1 != '\x01')) {
    return;
  }
  puVar3 = led_ro_2ae20;
  uVar9 = (uint)*(ushort *)led_ro_2ae20;
  if (uVar9 < uVar7) {
    uVar10 = uVar7 - uVar9;
  }
  else {
    uVar10 = uVar9 - uVar7;
  }
  if ((uVar10 & 0xffff) < 0x1e) {
    uVar7 = (uVar7 + uVar9 & 0xffff) >> 1;
    *(short *)puVar2 = (short)uVar7;
  }
  puVar4 = led_ro_2ae24;
  puVar2 = shared_ro_2ade4;
  uVar9 = 0;
  *(short *)puVar3 = (short)uVar7;
  do {
    puVar5 = led_ro_2b050;
    puVar3 = led_ro_2ae28;
    if ((int)(*(ushort *)(puVar2 + uVar9 * 2 + -0xdc) - 0xf) <= (int)uVar7) {
      if (uVar9 < (byte)*puVar4) {
        *led_ro_2ae28 = 0;
      }
      else {
        *puVar4 = (char)uVar9;
        if (99 < uVar9) {
          *puVar4 = 100;
        }
        cVar1 = *puVar3;
        *puVar3 = cVar1 + 1U;
        if (2 < (byte)(cVar1 + 1U)) {
          *puVar3 = 0;
          *led_ro_2ae2c = 1;
          *led_ro_2ae30 = 0x14;
        }
        dbg_printf(str_pGUpdate_OLED_Batt_vol_d + 2,*puVar4);
        *led_ro_2b050 = 1;
      }
      break;
    }
    if ((uVar9 == 0x6e) && ((byte)*puVar4 < 0x6f)) {
      *puVar4 = 100;
      *puVar5 = 1;
    }
    uVar9 = uVar9 + 1 & 0xff;
  } while (uVar9 < 0x6f);
  puVar2 = led_ro_2b05c;
  if (*led_ro_2b054 == '\0') {
    if ((*led_ro_2b058 == '\0') && (0x4f < (byte)*puVar4)) {
      cVar1 = led_ro_2b05c[1];
      led_ro_2b05c[1] = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        led_sub_328c2();
        *led_ro_2b058 = 1;
        puVar3 = led_ro_2b064;
        puVar2[1] = 3;
        *puVar3 = 1;
        *led_ro_2b068 = 0x14;
        pcVar8 = str_set_Update_OLED_f_bat_low_1;
LAB_0002aee4:
        dbg_printf(pcVar8);
      }
    }
    else if ((*led_ro_2b058 == '\0') || (0x4f < (byte)*puVar4)) {
      led_ro_2b05c[1] = 3;
    }
    else {
      cVar1 = led_ro_2b05c[1];
      led_ro_2b05c[1] = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        led_sub_328c2();
        *led_ro_2b058 = 0;
        *led_ro_2b060 = 0;
        puVar3 = led_ro_2b064;
        puVar2[1] = 3;
        puVar2[2] = 3;
        *puVar3 = 1;
        *led_ro_2b068 = 0x14;
        pcVar8 = str_set_Update_OLED_f_bat_low_2;
        goto LAB_0002aee4;
      }
    }
    puVar3 = led_ro_2b060;
    if ((*led_ro_2b060 == '\0') && (99 < (byte)*puVar4)) {
      cVar1 = puVar2[2];
      puVar2[2] = cVar1 + -1;
      if ((char)(cVar1 + -1) != '\0') goto LAB_0002af36;
      led_sub_328c2();
      *led_ro_2b060 = 1;
      *led_ro_2b058 = 1;
      goto LAB_0002af14;
    }
    if ((*led_ro_2b060 != '\0') && ((byte)*puVar4 < 100)) {
      cVar1 = puVar2[2];
      puVar2[2] = cVar1 + -1;
      if ((char)(cVar1 + -1) != '\0') goto LAB_0002af36;
      *puVar3 = 0;
    }
  }
  else {
    *led_ro_2b058 = 0;
    *led_ro_2b060 = 0;
LAB_0002af14:
    puVar2[1] = 3;
  }
  puVar2[2] = 3;
LAB_0002af36:
  puVar2 = led_ro_2b0b4;
  *led_ro_2b0ac = 3;
  *(undefined2 *)led_ro_2b0b0 = 0;
  *puVar2 = 4;
  if (*led_ro_2b060 != '\0') {
    dbg_printf(str_f_bat_ll_low_process);
    *led_ro_2b0d4 = 0;
    cVar1 = *led_ro_2b0d8;
    if (cVar1 == '\0') {
      force_24g_sleep();
      return;
    }
    if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
      force_ble_sleep_2();
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
  dbg_printf(str_s_3,shared_ro_2b554);
  OLED_Init();
  *led_ro_2b560 = 1;
  if (((*shared_ro_2b54c == '\x01') || (*shared_ro_2b54c == '\x02')) && (*shared_ro_2b520 == '\0')) {
    *shared_ro_2b530 = 0xfa;
    rom_07342(shared_ro_2b564,3,1);
  }
  return;
}

/* ==========================================================================
 * tx_failed_cnt   @ 0x0002b936   (402 bytes)
 * called by : ble_sub_2f31c
 * calls     : led_sub_2a69e, ble_sub_2b3ac, led_sub_31244, ble_sub_312aa, dbg_printf, rom_24F9C
 * string    : "tx_failed_cnt =%d,%d,Utc_Poll=%d,%d\r\n"
 */

void tx_failed_cnt(void)

{
  undefined2 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte bVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined *puVar8;
  int iVar9;
  
  if (*led_ro_2bc20 != '\0') {
    ble_sub_2b3ac();
    return;
  }
  if (*led_ro_2bc24 != '\0') {
    return;
  }
  bVar5 = *led_ro_2bc28;
  if ((bVar5 < 0x10) && (*led_ro_2bc28 = bVar5 + 1, (byte)(bVar5 + 1) < 0xb)) {
LAB_0002bca6:
    ble_sub_312aa();
  }
  else {
    puVar8 = led_ro_2bc34;
    puVar2 = shared_ro_2bbf0;
    if (((*led_ro_2bc2c == '\0') &&
        (((*led_ro_2bc30 == '\0' && (*led_ro_2bc38 == '\0')) && (*led_ro_2bc3c == '\0')))) &&
       (((*led_ro_2bc34 == '\0' && (*led_ro_2bc40 == '\0')) && (*led_ro_2bc44 == '\0')))) {
      shared_ro_2bbf0[10] = 0;
      bVar5 = puVar2[0xd];
      if (bVar5 != 0xff) {
        bVar5 = bVar5 + 1;
        puVar2[0xd] = bVar5;
      }
      if (3 < bVar5) {
        return;
      }
    }
    else {
      shared_ro_2bbf0[0xd] = 0;
    }
    puVar4 = led_ro_2bc54;
    puVar3 = led_ro_2bc4c;
    bVar5 = shared_ro_2bbf0[3];
    if (((*led_ro_2bc30 != '\0') && (5 < bVar5)) || (7 < bVar5)) {
      iVar9 = led_ro_2bc50;
      if (*led_ro_2bc48 == '\x01') {
        iVar9 = led_ro_2bc50 + 0xfa;
      }
      *(int *)led_ro_2bc4c = iVar9;
      dbg_printf(str_tx_failed_cnt_d_d_Utc_Poll_d_d,puVar2[10],bVar5,*(undefined4 *)puVar3,*puVar4);
      *puVar4 = 0;
      *(undefined2 *)(puVar2 + 0xe) = 0;
      puVar2[10] = 0;
      return;
    }
    led_sub_2a69e();
    puVar4 = led_ro_2bc80;
    puVar3 = shared_ro_2bbf0;
    if (*puVar8 == '\0') {
      if (*led_ro_2bc44 == '\0') {
        if ((((*led_ro_2bc2c == '\0') && (*led_ro_2bc30 == '\0')) && (*led_ro_2bc38 == '\0')) &&
           (*led_ro_2bc3c == '\0')) {
          return;
        }
        led_sub_31244();
        bVar5 = puVar2[1];
        iVar9 = (uint)bVar5 * 8;
        puVar4[iVar9] = *led_ro_2bc8c;
        uVar1 = *(undefined2 *)led_ro_2bc90;
        puVar4[iVar9 + 1] = (char)uVar1;
        puVar4[iVar9 + 2] = (char)((ushort)uVar1 >> 8);
        uVar1 = *(undefined2 *)led_ro_2bc94;
        puVar4[iVar9 + 3] = (char)uVar1;
        puVar4[iVar9 + 4] = (char)((ushort)uVar1 >> 8);
        puVar4[iVar9 + 5] = *led_ro_2bc98;
        puVar4[iVar9 + 6] = *led_ro_2bc9c;
        puVar3[bVar5 + 0x18] = 7;
        puVar2[1] = bVar5 + 1 & 7;
        puVar2[3] = puVar2[3] + '\x01';
        if ((byte)puVar2[10] < 0xfa) {
          puVar2[10] = puVar2[10] + 1;
        }
        goto LAB_0002bca6;
      }
      *led_ro_2bc44 = 0;
      puVar8 = led_ro_2bc88;
      uVar6 = (uint)(byte)puVar2[1];
      puVar4[uVar6 * 8] = *led_ro_2bc88;
      puVar4[uVar6 * 8 + 1] = puVar8[1];
      uVar7 = 2;
    }
    else {
      *puVar8 = 0;
      bVar5 = puVar2[1];
      puVar8 = led_ro_2bc84 + 1;
      puVar4[(uint)bVar5 * 8] = *led_ro_2bc84;
      rom_24F9C(puVar4 + (uint)bVar5 * 8 + 2,puVar8,6);
      uVar6 = (uint)(byte)puVar2[1];
      uVar7 = 8;
    }
    puVar3[uVar6 + 0x18] = uVar7;
    puVar2[3] = puVar2[3] + '\x01';
    puVar2[1] = (char)uVar6 + 1U & 7;
  }
  return;
}

/* ==========================================================================
 * led_sub_2c124   @ 0x0002c124   (52 bytes)
 * called by : led_sub_31454, led_sub_31500, led_sub_31524
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26, rom_24F9C
 */

void led_sub_2c124(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ble_sub_3ee6e(0x47);
  iVar2 = rom_06EF4(shared_ro_2c2d0,uVar1,param_1 * 0x100 + 3,0x278);
  *(short *)(iVar2 + 2) = (short)param_2;
  rom_24F9C(iVar2 + 4,param_3,param_2);
  rom_06F26(iVar2);
  return;
}

/* ==========================================================================
 * Success_led_2second   @ 0x0002eaac   (212 bytes)
 * calls     : CHRG, flash_sub_3262c, flash_sub_32658, led_sub_32942, led_sub_3beb4, ReLink, ... (+4 more)
 * string    : "Success_led_2second 1=  %x,\r\n"
 * string    : "set_Update_OLED--Success_led_2second \r\n"
 */

undefined4 Success_led_2second(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = shared_ro_2ed1c;
  puVar3 = shared_ro_2ed1c + 5;
  if (*(int *)led_ro_2edd8 * 0x400000 < 0) {
    *(uint *)led_ro_2edd8 = *(uint *)led_ro_2edd8 & 0xfffffdff;
    dbg_printf(str_Success_led_2second_1_x,*led_ro_2eddc);
    rom_07342(puVar2 + 0xc,3,200);
    flash_sub_32658();
    rom_073D4(puVar3,3);
    if (*led_ro_2ee00 == '\0') {
      CHRG();
    }
    else {
      ReLink();
    }
    delta_none();
    dbg_printf(str_set_Update_OLED_Success_led_2second);
    *led_ro_2ee2c = 0;
    *shared_ro_2ee30 = 0;
    led_sub_3beb4();
    goto LAB_0002eb66;
  }
  rom_07342(puVar3,3,0x19);
  if (*led_ro_2ee34 != '\0' || *led_ro_2ee38 != '\0') {
    return 0;
  }
  flash_sub_3262c();
  puVar2 = led_ro_2ee44;
  if (*led_ro_2ee3c == '\x02') {
    cVar1 = *led_ro_2ee44;
    *led_ro_2ee44 = cVar1 + 1U;
    if ((byte)(cVar1 + 1U) < 2) goto LAB_0002eb66;
    *puVar2 = 0;
    puVar2 = led_ro_2ee48;
    cVar1 = led_ro_2ee48[2];
    led_ro_2ee48[2] = cVar1 + 1U;
    if ((byte)puVar2[3] < (byte)(cVar1 + 1U)) goto LAB_0002eb66;
  }
  else if (*led_ro_2ee40 != '\0') goto LAB_0002eb66;
  led_sub_32942();
LAB_0002eb66:
  if (*led_ro_2ee4c != '\0') {
    *led_ro_2ee50 = 0;
    rom_073D4(shared_ro_2ed1c + 6,3);
  }
  return 0;
}

/* ==========================================================================
 * RPT_STEP   @ 0x0002fa8e   (168 bytes)
 * calls     : rf24_sub_36c8e, led_sub_36caa, led_sub_36e88, OLED_Init, Set_Report_Data, dbg_printf_2, ... (+1 more)
 * string    : "RPT_STEP-9L:"
 * string    : "RPT_STEP-9S:"
 */

void RPT_STEP(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  uVar4 = *(uint *)shared_ro_2fc94;
  *(uint *)shared_ro_2fc94 = uVar4 & 0x70;
  puVar1 = rf24_ro_2fc9c;
  if (-1 < (int)((uVar4 & 0x70) << 0x19)) {
    if (*rf24_ro_2fc9c != '\0') {
      return;
    }
    led_sub_36caa();
    rf24_sub_36c8e();
    return;
  }
  led_sub_36e88();
  puVar2 = shared_ro_2fca4;
  *puVar1 = 6;
  puVar1 = shared_ro_2fcd4;
  if ((*puVar2 == '8') && ((uint)(byte)puVar2[1] == (byte)*shared_ro_2fcd8 + 1)) {
    *shared_ro_2fcd8 = (char)((byte)*shared_ro_2fcd8 + 1);
    puVar3 = shared_ro_2fcdc;
    if ((byte)*puVar1 < 0x1e) {
      rom_24F9C(*(undefined4 *)(shared_ro_2fcdc + 4),puVar2 + 2);
      dbg_printf_2(str_RPT_STEP_9S,shared_ro_2fca4,*puVar1 + '\x02');
      *puVar1 = 0;
    }
    else {
      rom_24F9C(*(undefined4 *)(shared_ro_2fcdc + 4),puVar2 + 2,0x1e);
      puVar2 = shared_ro_2fca4;
      *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + 0x1e;
      *puVar1 = *puVar1 + -0x1e;
      dbg_printf_2(str_RPT_STEP_9L,puVar2,0x20);
      if (*puVar1 != '\0') {
        return;
      }
    }
    OLED_Init();
    *shared_ro_2fd08 = puVar3[9];
    *(undefined **)(puVar3 + 4) = shared_ro_2fcdc + 9;
    Set_Report_Data();
    *rf24_ro_2fca0 = 10;
    return;
  }
  return;
}

/* ==========================================================================
 * led_sub_2ff18   @ 0x0002ff18   (380 bytes)
 * calls     : rf24_sub_31784, usb_sub_369a0, usb_sub_369ac, rf24_sub_36c8e, led_sub_36caa, led_sub_36d0e, ... (+5 more)
 */

void led_sub_2ff18(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  char *pcVar8;
  
  puVar3 = shared_ro_301f8;
  puVar4 = shared_ro_301f0;
  iVar7 = *(int *)shared_ro_301f8;
  if (iVar7 * 0x2000000 < 0) {
    led_sub_36e88();
    puVar6 = led_ro_30204;
    pcVar8 = led_ro_30200;
    puVar5 = led_ro_301fc;
    if (*led_ro_301fc == '6') {
      *puVar4 = 5;
      *puVar5 = 0x46;
      cVar1 = puVar5[4];
    }
    else {
      if (*led_ro_301fc != '7') {
        if (*led_ro_30204 != '\0') {
          *puVar4 = 0;
          *puVar6 = 0;
        }
        *(undefined4 *)(shared_ro_301f8 + -0x28) = 0x80;
        *(undefined4 *)puVar3 = 0x40;
        goto LAB_0002ff56;
      }
      *puVar4 = 7;
      *puVar5 = 0x47;
      cVar1 = puVar5[4];
      *led_ro_3021c = cVar1;
    }
    if (cVar1 != '\0') {
      if (puVar5[1] != '\t') {
        *pcVar8 = 0;
        pcVar8 = led_ro_30210;
      }
      *pcVar8 = cVar1 + -1;
    }
    *led_ro_30214 = 8;
    rom_24FEC(puVar5 + 5,3);
    puVar4 = led_ro_30218;
    led_ro_30218[2] = puVar5[1];
    puVar4[3] = puVar5[2];
    puVar4[8] = puVar5[3];
    OLED_Init();
    *led_ro_3020c = 6;
    *shared_ro_30154 = 200;
    puVar4 = shared_ro_301f8;
    *(undefined4 *)(shared_ro_301f8 + -0x28) = 0x80;
    *(undefined4 *)puVar3 = 0x40;
    *shared_ro_30174 = 0;
    *led_ro_30204 = 0;
    *(undefined4 *)(puVar4 + -0x2c) = 1;
  }
  else {
LAB_0002ff56:
    puVar5 = shared_ro_301f8;
    if (iVar7 * 0x4000000 < 0) {
      *(undefined4 *)(shared_ro_301f8 + -0x28) = 0xa0;
      *(undefined4 *)puVar3 = 0x20;
      puVar3 = shared_ro_30174;
      *puVar4 = 0;
      *puVar3 = 0;
      *shared_ro_30144 = 0;
      puVar4 = led_ro_3020c;
      *led_ro_30208 = 0;
      *puVar4 = 6;
      return;
    }
    if (iVar7 << 0x1b < 0) {
      *(undefined4 *)(shared_ro_301f8 + -0x28) = 0x80;
      *(undefined4 *)(puVar5 + -0x28) = 0xa0;
      usb_sub_369ac();
      rf24_sub_31784(3);
      usb_sub_369a0();
      *(undefined4 *)puVar3 = 0x10;
      puVar3 = led_ro_30208;
      if (*(short *)shared_ro_30178 != 0) {
        if ((byte)*led_ro_30208 < 4) {
          if ((shared_ro_3012c[0x16] == '\x01') || (shared_ro_3012c[0x16] == '\x02')) {
            time_sensor_invalid();
          }
          if (*led_ro_30220 != '\0') {
            *led_ro_30220 = 0;
            puVar6 = led_ro_30228;
            puVar5 = led_ro_30224;
            puVar4 = led_ro_301fc;
            uVar2 = *(undefined2 *)led_ro_30224;
            led_ro_301fc[2] = (char)uVar2;
            puVar4[3] = (char)((ushort)uVar2 >> 8);
            uVar2 = *(undefined2 *)puVar6;
            puVar4[4] = (char)uVar2;
            puVar4[5] = (char)((ushort)uVar2 >> 8);
            *(undefined2 *)puVar5 = 0;
            *(undefined2 *)puVar6 = 0;
          }
        }
        cVar1 = *puVar3;
        if ((cVar1 == '\0') || (*puVar3 = cVar1 + -1, cVar1 == '\x01')) {
          led_sub_36caa();
          rf24_sub_36c8e();
        }
        rf24_sub_31784(0x14);
        led_sub_36d0e(8);
        return;
      }
      dbg_printf_2(str_RETR_fail,led_ro_301fc,8);
      *(undefined2 *)shared_ro_3017c = 0;
      puVar3 = shared_ro_30174;
      *puVar4 = 0;
      *puVar3 = 0;
      return;
    }
  }
  return;
}

/* ==========================================================================
 * led_sub_31244   @ 0x00031244   (102 bytes)
 * called by : usb_sub_358b6, usb_sub_3870a, tx_failed_cnt
 */

void led_sub_31244(void)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = shared_ro_31580;
  puVar4 = shared_ro_3157c;
  puVar3 = shared_ro_31574;
  sVar1 = *(short *)shared_ro_31580;
  if ((*(short *)shared_ro_3157c != 0 || sVar1 != 0) && (*shared_ro_31584 == '\0')) {
    iVar6 = (((int)*(short *)shared_ro_3157c + (uint)*(ushort *)shared_ro_3156c) - (uint)*(ushort *)shared_ro_31574) *
            0x10000;
    sVar2 = (short)((uint)iVar6 >> 0x10);
    *(short *)shared_ro_3156c = sVar2;
    iVar6 = (iVar6 >> 0x10) - (iVar6 >> 0x1f);
    sVar2 = (short)(iVar6 >> 1) + (sVar2 - ((ushort)iVar6 & 0xfffe));
    *(short *)puVar4 = sVar2;
    *(short *)puVar3 = sVar2;
    puVar3 = shared_ro_31578;
    iVar6 = (((int)sVar1 + (uint)*(ushort *)shared_ro_31570) - (uint)*(ushort *)shared_ro_31578) * 0x10000;
    sVar1 = (short)((uint)iVar6 >> 0x10);
    *(short *)shared_ro_31570 = sVar1;
    iVar6 = (iVar6 >> 0x10) - (iVar6 >> 0x1f);
    sVar1 = (short)(iVar6 >> 1) + (sVar1 - ((ushort)iVar6 & 0xfffe));
    *(short *)puVar5 = sVar1;
    *(short *)puVar3 = sVar1;
  }
  return;
}

/* ==========================================================================
 * led_sub_31454   @ 0x00031454   (62 bytes)
 * calls     : led_sub_2c124
 */

void led_sub_31454(undefined1 param_1,undefined1 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = led_ro_3168c;
  *led_ro_3168c = 0x10;
  puVar1[1] = 0x50;
  puVar1[2] = param_1;
  puVar2 = led_ro_31690;
  puVar1[3] = param_2;
  if ((*puVar2 == '\0') || (*shared_ro_31614 != '\0')) {
    *led_ro_31694 = 1;
    *led_ro_31698 = 1;
  }
  else {
    led_sub_2c124(0,4,led_ro_3168c);
  }
  *led_ro_3169c = 8;
  return;
}

/* ==========================================================================
 * led_sub_31492   @ 0x00031492   (64 bytes)
 * called by : Led_OLED
 */

void led_sub_31492(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = led_ro_316a4;
  puVar3 = led_ro_316a0;
  puVar2 = shared_ro_315dc;
  cVar1 = *led_ro_316a0;
  *shared_ro_315dc = *led_ro_316a0;
  puVar2[1] = 0x31;
  if (cVar1 == '\0') {
    puVar2[2] = puVar4[3];
    puVar2[3] = puVar4[2];
    *puVar3 = 1;
  }
  else {
    puVar2[2] = puVar4[1];
    puVar2[3] = *puVar4;
    *puVar3 = 0;
  }
  *led_ro_3169c = 8;
  *shared_ro_315c0 = 1;
  *led_ro_31698 = 1;
  return;
}

/* ==========================================================================
 * led_sub_314d2   @ 0x000314d2   (46 bytes)
 * called by : Led_OLED, SLEEP
 */

void led_sub_314d2(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = led_ro_31694;
  puVar1 = led_ro_3168c;
  puVar3 = led_ro_3169c;
  if (*led_ro_31694 == '\0') {
    *led_ro_3168c = 0x10;
    puVar1[1] = 0x40;
    puVar1[2] = param_1;
    puVar1[3] = 'd' - *led_ro_316a8;
    *puVar2 = 1;
    puVar3 = led_ro_31698;
  }
  *puVar3 = 1;
  return;
}

/* ==========================================================================
 * led_sub_31500   @ 0x00031500   (36 bytes)
 * called by : Led_OLED
 * calls     : led_sub_2c124
 */

void led_sub_31500(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_315dc;
  *shared_ro_315dc = 0x10;
  puVar1[1] = 0x40;
  puVar1[2] = param_1;
  puVar1[3] = 'd' - *led_ro_316a8;
  led_sub_2c124(0,4,puVar1);
  return;
}

/* ==========================================================================
 * led_sub_31524   @ 0x00031524   (68 bytes)
 * calls     : led_sub_2c124
 */

void led_sub_31524(void)

{
  char cVar1;
  undefined *puVar2;
  
  puVar2 = shared_ro_315dc;
  *shared_ro_315dc = 0x10;
  puVar2[1] = 0x10;
  puVar2[2] = led_ro_316ac[0xd];
  puVar2[3] = 0;
  cVar1 = *led_ro_31690;
  if ((cVar1 == '\0') || (*shared_ro_31614 != '\0')) {
    *shared_ro_315c0 = 1;
  }
  else if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*shared_ro_31614 == '\0')) {
    led_sub_2c124(0,4,shared_ro_315dc);
    return;
  }
  return;
}

/* ==========================================================================
 * led_sub_32892   @ 0x00032892   (48 bytes)
 * called by : led_sub_328c2, ble_sub_35abc, ble_sub_35b08, LightUp_Mode_Led, SLEEP, Success_led_2second_2, ... (+2 more)
 * calls     : rf24_sub_32886
 */

void led_sub_32892(void)

{
  *shared_ro_329e4 = 0;
  rf24_sub_32886(0);
  *shared_ro_32a48 = 0;
  *(undefined2 *)led_ro_32a90 = 0;
  *(undefined2 *)shared_ro_32a58 = 0;
  *(undefined2 *)shared_ro_32a60 = 0;
  *led_ro_32a94 = 0;
  *shared_ro_32a98 = 0;
  *shared_ro_32a64 = 0;
  *led_ro_32a9c = 0;
  return;
}

/* ==========================================================================
 * led_sub_328c2   @ 0x000328c2   (46 bytes)
 * called by : set_Update_OLED_2
 * calls     : led_sub_32892, ble_alert_led_stop, dbg_printf
 * string    : "alert led stopping\r\n"
 */

void led_sub_328c2(void)

{
  if (((*shared_ro_329f0 == '\x01') || (*shared_ro_329f0 == '\x02')) && (*shared_ro_329ec == '\0')) {
    ble_alert_led_stop();
  }
  else {
    led_sub_32892();
  }
  *shared_ro_32a64 = 0;
  dbg_printf(str_alert_led_stopping);
  return;
}

/* ==========================================================================
 * Success_led_2second_2   @ 0x000328f0   (82 bytes)
 * called by : LightUp_Mode_Led, USNDP_status_2, f_reconnect_24G, f_usb_isConnected
 * calls     : flash_sub_3262c, flash_sub_32658, led_sub_32892, flash_sub_3c8b6, flash_sub_3cf7c, OLED_Clear, ... (+3 more)
 * string    : "Success_led_2second---Led_Mode\r\n"
 * string    : "set_Update_OLED--Success_led_2second \r\n"
 */

void Success_led_2second_2(void)

{
  led_sub_32892();
  *(undefined2 *)shared_ro_32a58 = 0;
  *shared_ro_32a5c = 0;
  *shared_ro_32a50 = 8;
  *shared_ro_32a54 = 8;
  flash_sub_3262c();
  flash_sub_32658();
  *shared_ro_32a64 = 0x3d;
  dbg_printf(str_Success_led_2second_Led_Mode);
  flash_sub_3c8b6();
  OLED_Clear();
  flash_sub_3cf7c();
  dbg_printf(str_set_Update_OLED_Success_led_2second_2);
  delta_none();
  *(undefined2 *)shared_ro_32b04 = 400;
  OLED_Init();
  return;
}

/* ==========================================================================
 * led_sub_32942   @ 0x00032942   (58 bytes)
 * called by : Success_led_2second
 * calls     : ble_sub_32620, flash_sub_32658, led_sub_3ce52, Pairing, ReLinking
 */

void led_sub_32942(void)

{
  byte bVar1;
  
  bVar1 = *shared_ro_32a8c;
  *shared_ro_32a8c = bVar1 ^ 1;
  *(undefined2 *)shared_ro_32b04 = 400;
  if (((bVar1 ^ 1) & 1) == 0) {
    ble_sub_32620();
    led_sub_3ce52();
    return;
  }
  flash_sub_32658();
  if (*led_ro_32b08 != '\x02') {
    Pairing();
    return;
  }
  ReLinking();
  return;
}

/* ==========================================================================
 * Led_OLED   @ 0x00032c34   (254 bytes)
 * called by : system_mode
 * calls     : led_sub_31492, led_sub_314d2, led_sub_31500, dbg_printf
 * string    : "Led_OLED ==5 !\r\n"
 * string    : "Led_OLED ==changing !\r\n"
 */

void Led_OLED(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  
  if (*led_ro_32e30 != '\0') {
    return;
  }
  if ((*shared_ro_32d5c == '\0') || (*shared_ro_32d60 != '\0')) {
    uVar7 = 8;
  }
  else {
    uVar7 = 0x10;
  }
  *led_ro_32e30 = uVar7;
  puVar5 = led_ro_32e48;
  puVar4 = led_ro_32e40;
  puVar3 = led_ro_32e3c;
  puVar2 = led_ro_32e38;
  if (*led_ro_32e34 != '\0') {
    led_sub_31492();
    return;
  }
  if ((*led_ro_32e38 == '\0') && (*led_ro_32e44 == '\0')) {
    if (*led_ro_32e40 == '\0') {
      led_sub_314d2(1);
    }
    puVar2 = shared_ro_32d98;
    if (*shared_ro_32d5c == '\0') {
      return;
    }
    if (*shared_ro_32d60 != '\0') {
      return;
    }
    if (*led_ro_32e4c == '\0') {
      return;
    }
    if (*led_ro_32e50 == '\0') {
      return;
    }
    *shared_ro_32d50 = 1;
    *puVar3 = 0;
    *(undefined2 *)puVar2 = 3;
    *shared_ro_32d54 = 1;
    dbg_printf(str_Led_OLED_5);
    *shared_ro_32d58 = 0x3e;
    return;
  }
  if (*led_ro_32e3c != '\0') {
    return;
  }
  if (*led_ro_32e48 == '\0') {
    *shared_ro_32d50 = 3;
    *(undefined2 *)shared_ro_32d98 = 2;
    *shared_ro_32d54 = 1;
    dbg_printf(str_Led_OLED_changing);
    *shared_ro_32d58 = 0x3e;
    if (*puVar5 == '\0') {
      cVar1 = *puVar4;
      if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*puVar2 == '\0')) {
        uVar6 = 3;
        goto LAB_00032d2c;
      }
      uVar6 = 3;
      goto LAB_00032d24;
    }
  }
  cVar1 = *puVar4;
  if (((cVar1 == '\x01') || (cVar1 == '\x02')) && (*puVar2 == '\0')) {
    uVar6 = 2;
LAB_00032d2c:
    led_sub_31500(uVar6);
    return;
  }
  uVar6 = 2;
LAB_00032d24:
  led_sub_314d2(uVar6);
  return;
}

/* ==========================================================================
 * delta_none   @ 0x00033f3c   (52 bytes)
 * called by : flash_sub_3cf7c, usb_sub_3d2b0, Success_led_2second, Success_led_2second_2
 * calls     : ble_sub_3443a, dbg_printf
 * string    : "delta_none =%x\r\n"
 */

void delta_none(void)

{
  if ((*shared_ro_33fd8 != '\0') && (*shared_ro_33fb4 != '\0')) {
    if ((*(uint *)(shared_ro_33f70 + 0x6c) & 1) == 0) {
      ble_sub_3443a();
    }
    dbg_printf(str_delta_none_x);
    *(undefined2 *)shared_ro_33ff4 = 0;
    *(undefined2 *)shared_ro_33ff8 = 0;
  }
  return;
}

/* ==========================================================================
 * OLED_Init   @ 0x0003468c   (134 bytes)
 * called by : Detect_FULL_IN, ble_sub_2aa5c, ble_sub_2ac0e, led_sub_2ff18, flash_sub_333f0, HID_RQT_Get_Protocol, ... (+12 more)
 * calls     : ble_sub_39a84, led_sub_3beb4, flash_sub_3c8b6, flash_sub_3cf7c, OLED_Clear, dbg_printf
 * string    : "OLED_Init 3\r\n"
 */

void OLED_Init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  short sVar4;
  ushort uVar5;
  
  if (*shared_ro_34a64 != '\0') {
    *shared_ro_34a64 = 0;
    flash_sub_3c8b6();
    OLED_Clear();
    dbg_printf(str_OLED_Init_3);
    flash_sub_3cf7c();
    led_sub_3beb4();
    *shared_ro_34a78 = 0;
  }
  *shared_ro_34a7c = 0x78;
  *led_ro_34a80 = 5;
  *(undefined2 *)led_ro_34a84 = 400;
  ble_sub_39a84(0x32,2);
  puVar2 = shared_ro_34a8c;
  puVar1 = shared_ro_34a88;
  sVar4 = (ushort)(byte)shared_ro_34a88[0x10] * 0x7e;
  if (sVar4 == 0) {
    sVar4 = 2;
  }
  *(short *)shared_ro_34a8c = sVar4;
  puVar3 = shared_ro_34a94;
  if (*led_ro_34a90 == '\0') {
    *shared_ro_34a98 = 0;
  }
  uVar5 = (ushort)((byte)puVar1[0xb] >> 4) << 4 | (ushort)((byte)puVar1[0xc] >> 4);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  *(ushort *)puVar3 = uVar5 * 0xef + *(short *)puVar2;
  return;
}

/* ==========================================================================
 * led_sub_36aae   @ 0x00036aae   (34 bytes)
 * called by : led_sub_36e88, led_sub_36eb8
 */

void led_sub_36aae(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd8) = 0x40;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(char *)(param_1 + uVar2) = (char)*(undefined4 *)(puVar1 + 0xdc);
  }
  *(undefined4 *)(puVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * led_sub_36ad0   @ 0x00036ad0   (34 bytes)
 * called by : led_sub_36d0e, rf24_sub_36d3a, usb_sub_36e0c
 */

void led_sub_36ad0(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd8) = 0x60;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    *(uint *)(puVar1 + 0xdc) = (uint)*(byte *)(param_1 + uVar2);
  }
  *(undefined4 *)(puVar1 + 0xd8) = 0;
  return;
}

/* ==========================================================================
 * led_sub_36caa   @ 0x00036caa   (20 bytes)
 * called by : rf24_sub_2f92a, rf24_sub_2fc1e, led_sub_2ff18, RPT_STEP, SLEEP, ch_frequency, ... (+1 more)
 */

void led_sub_36caa(void)

{
  *shared_ro_36da8 = *shared_ro_36da8 + 1 & 3;
  *led_ro_36db0 = 6;
  return;
}

/* ==========================================================================
 * led_sub_36d0e   @ 0x00036d0e   (44 bytes)
 * called by : led_sub_2ff18, SLEEP
 * calls     : rf24_sub_31784, led_sub_36ad0
 */

void led_sub_36d0e(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_36d84;
  *(undefined4 *)(shared_ro_36d84 + 0xd4) = 1;
  *(undefined4 *)(puVar1 + 0xd8) = 0xa0;
  *(undefined4 *)(puVar1 + 0xd8) = 0x80;
  *(undefined4 *)shared_ro_36db4 = 0x7e;
  led_sub_36ad0(shared_ro_36db8,param_1);
  rf24_sub_31784(10);
  *(undefined4 *)(puVar1 + 0xd4) = 0;
  return;
}

/* ==========================================================================
 * led_sub_36e88   @ 0x00036e88   (48 bytes)
 * called by : led_sub_2ff18, LightUp_Mode_Led, RPT_STEP
 * calls     : led_sub_36aae
 */

void led_sub_36e88(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar1 = shared_ro_36f1c;
  puVar3 = (uint *)(shared_ro_36f1c + 0x40);
  do {
    if (0x20 < (*(uint *)(puVar1 + 0x50) & 0xff)) {
      *(undefined4 *)(shared_ro_36f1c + 0x18) = 0x80;
      break;
    }
    led_sub_36aae(shared_ro_36f20);
    uVar2 = *puVar3;
    param_1 = uVar2 & 0xff;
  } while ((uVar2 & 0xf) >> 1 != 7);
  *puVar3 = param_1;
  return;
}

/* ==========================================================================
 * led_sub_36eb8   @ 0x00036eb8   (54 bytes)
 * calls     : led_sub_36aae
 */

void led_sub_36eb8(uint param_1)

{
  undefined *puVar1;
  uint *puVar2;
  
  puVar1 = shared_ro_36f1c;
  puVar2 = (uint *)(shared_ro_36f1c + 0x40);
  if ((int)(*puVar2 << 0x19) < 0) {
    do {
      if (0x20 < (*(uint *)(puVar1 + 0x50) & 0xff)) {
        *(undefined4 *)(shared_ro_36f1c + 0x18) = 0x80;
        break;
      }
      led_sub_36aae(shared_ro_36f20);
      param_1 = *puVar2 & 0xff;
    } while ((*puVar2 & 0xf) >> 1 != 7);
    *puVar2 = param_1;
  }
  return;
}

/* ==========================================================================
 * led_sub_3b5b6   @ 0x0003b5b6   (48 bytes)
 * called by : set_Update_OLED_2
 * calls     : ble_sub_39a84
 */

void led_sub_3b5b6(char param_1)

{
  undefined *puVar1;
  int iVar2;
  
  ble_sub_39a84(param_1 + '0',0,2);
  *(uint *)shared_ro_3b6bc = *(uint *)shared_ro_3b6bc & 0xfffffff8;
  puVar1 = shared_ro_3b6c4;
  *(uint *)shared_ro_3b6c4 = *(uint *)shared_ro_3b6c4 & ~((int)shared_ro_3b6c4 >> 0xf);
  iVar2 = (int)puVar1 * 0x20000;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | iVar2 >> 0xd;
  return;
}

/* ==========================================================================
 * led_sub_3beb4   @ 0x0003beb4   (86 bytes)
 * called by : OLED_Init, SLEEP, Success_led_2second, enter_BLE_normal_app_mode, exist
 */

void led_sub_3beb4(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = shared_ro_3bf98;
  *(uint *)shared_ro_3bf98 = *(uint *)shared_ro_3bf98 | 0x40;
  if ((((*shared_ro_3bf9c != '\x01') && (*shared_ro_3bf9c != '\x02')) || (*shared_ro_3bfa0 != '\0')) ||
     (uVar2 = 0x40, *shared_ro_3bfa0 != '\0')) {
    uVar2 = led_ro_3bfa4;
  }
  *(undefined4 *)(puVar1 + 4) = uVar2;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
  *(uint *)puVar1 = *(uint *)puVar1 | 0x20;
  *(uint *)puVar1 = *(uint *)puVar1 | 8;
  *(uint *)puVar1 = *(uint *)puVar1 | 4;
  *(uint *)shared_ro_3bfa8 = *(uint *)shared_ro_3bfa8 | (int)shared_ro_3bfa8 >> 0xb;
  return;
}

/* ==========================================================================
 * led_sub_3c842   @ 0x0003c842   (16 bytes)
 * called by : led_sub_3c896, led_sub_3c90c, led_sub_3c92c, usb_sub_3c9be, led_sub_3d24a, led_sub_3d382, ... (+1 more)
 */

void led_sub_3c842(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3cc18;
  *(undefined4 *)(shared_ro_3cc18 + 4) = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)(puVar1 + 4) = 2;
  *(undefined4 *)puVar1 = 2;
  return;
}

/* ==========================================================================
 * led_sub_3c852   @ 0x0003c852   (52 bytes)
 * called by : led_sub_3c896, led_sub_3c90c, led_sub_3c92c, usb_sub_3c9be, led_sub_3d24a, led_sub_3d382, ... (+1 more)
 */

void led_sub_3c852(uint param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  puVar1 = shared_ro_3cc18;
  bVar2 = 0;
  do {
    *(undefined4 *)(puVar1 + 4) = 0;
    if ((param_1 & 0xffffff80) == 0x80) {
      *(undefined4 *)puVar1 = 2;
    }
    else {
      *(undefined4 *)puVar1 = 0;
    }
    *(undefined4 *)(puVar1 + 4) = 2;
    *(undefined4 *)(puVar1 + 4) = 0;
    bVar2 = bVar2 + 1;
    param_1 = (param_1 & 0x7f) << 1;
  } while (bVar2 < 8);
  *(undefined4 *)puVar1 = 2;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 4) = 2;
  return;
}

/* ==========================================================================
 * led_sub_3c886   @ 0x0003c886   (16 bytes)
 * called by : led_sub_3c896, led_sub_3c90c, led_sub_3c92c, usb_sub_3c9be, led_sub_3d24a, led_sub_3d382, ... (+1 more)
 */

void led_sub_3c886(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3cc18;
  *(undefined4 *)(shared_ro_3cc18 + 4) = 2;
  *(undefined4 *)puVar1 = 2;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  return;
}

/* ==========================================================================
 * led_sub_3c896   @ 0x0003c896   (32 bytes)
 * called by : flash_sub_3c8b6, led_sub_3c8dc, led_sub_3c92c, usb_sub_3c996, led_sub_3d382, led_sub_3d3f4, ... (+4 more)
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886
 */

void led_sub_3c896(undefined4 param_1)

{
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0);
  led_sub_3c852(param_1);
  led_sub_3c842();
  return;
}

/* ==========================================================================
 * led_sub_3c8dc   @ 0x0003c8dc   (34 bytes)
 * calls     : led_sub_3c896, rom_25078
 */

void led_sub_3c8dc(void)

{
  rom_25078();
  led_sub_3c896(0x81);
  led_sub_3c896(5);
  return;
}

/* ==========================================================================
 * led_sub_3c90c   @ 0x0003c90c   (32 bytes)
 * called by : led_sub_3d3f4, led_sub_3d51e, usb_sub_3d55c
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886
 */

void led_sub_3c90c(undefined4 param_1)

{
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  led_sub_3c852(param_1);
  led_sub_3c842();
  return;
}

/* ==========================================================================
 * led_sub_3c92c   @ 0x0003c92c   (106 bytes)
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886, led_sub_3c896
 */

void led_sub_3c92c(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  led_sub_3c896(0xb0);
  bVar1 = 3;
  do {
    led_sub_3c896(0);
    led_sub_3c896(0x10);
    led_sub_3c896(bVar1 + 0xb0);
    led_sub_3c886();
    led_sub_3c852(0x78);
    led_sub_3c852(0x40);
    bVar2 = 0;
    do {
      led_sub_3c852(param_1);
      led_sub_3c852(param_2);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x3c);
    led_sub_3c842();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

/* ==========================================================================
 * led_sub_3ce52   @ 0x0003ce52   (10 bytes)
 * called by : led_sub_32942, flash_sub_3cf7c, usb_sub_3d2b0, set_Update_OLED
 */

/* WARNING: Removing unreachable block (ram,0x0003cd84) */
/* WARNING: Removing unreachable block (ram,0x0003cd88) */
/* WARNING: Removing unreachable block (ram,0x0003cd96) */
/* WARNING: Removing unreachable block (ram,0x0003cd68) */
/* WARNING: Removing unreachable block (ram,0x0003cd62) */
/* WARNING: Removing unreachable block (ram,0x0003cd70) */
/* WARNING: Removing unreachable block (ram,0x0003cd66) */
/* WARNING: Removing unreachable block (ram,0x0003cd8a) */

void led_sub_3ce52(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  
  cVar1 = '\x01';
  bVar2 = 0;
  usb_sub_3b54e();
  *shared_ro_3d0b4 = 1;
  for (uVar3 = 0; led_ro_3d11c[uVar3] != '\0'; uVar3 = uVar3 + 1 & 0xff) {
    if (*input_ro_3d0b8 == '\0') {
      usb_sub_3c9f2(bVar2,cVar1,1);
    }
    else {
      usb_sub_3cb9a(bVar2,cVar1,1);
    }
    bVar2 = bVar2 + 8;
    if (0x70 < bVar2) {
      bVar2 = 0;
      cVar1 = cVar1 + '\x02';
    }
  }
  *input_ro_3d0b8 = 0;
  return;
}

/* ==========================================================================
 * led_sub_3d24a   @ 0x0003d24a   (52 bytes)
 * called by : OLED_Clear
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886, usb_sub_3c996
 */

void led_sub_3d24a(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  usb_sub_3c996();
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    led_sub_3c852(param_4);
  }
  led_sub_3c842();
  return;
}

/* ==========================================================================
 * OLED_Clear   @ 0x0003d27e   (50 bytes)
 * called by : BLE_PAIR, Default_Profile, usb_sub_3d2b0, power_sub_3d508, OLED_Init, Success_led_2second_2, ... (+6 more)
 * calls     : usb_sub_3b54e, led_sub_3c896, led_sub_3d24a, dbg_printf
 * string    : "OLED_Clear---------------\r\n"
 */

void OLED_Clear(void)

{
  byte bVar1;
  
  dbg_printf(str_OLED_Clear);
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  bVar1 = 0;
  do {
    usb_sub_3b54e();
    led_sub_3d24a(0,bVar1,0x78);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

/* ==========================================================================
 * led_sub_3d382   @ 0x0003d382   (114 bytes)
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886, led_sub_3c896
 */

void led_sub_3d382(void)

{
  byte bVar1;
  byte bVar2;
  
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  led_sub_3c896(0xb0);
  bVar1 = 0;
  do {
    led_sub_3c896(0);
    led_sub_3c896(0x10);
    led_sub_3c896(bVar1 + 0xb0);
    led_sub_3c886();
    led_sub_3c852(0x78);
    led_sub_3c852(0x40);
    bVar2 = 0;
    do {
      led_sub_3c852(0);
      led_sub_3c852(0);
      led_sub_3c852(0);
      led_sub_3c852(0);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x1e);
    led_sub_3c842();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

/* ==========================================================================
 * led_sub_3d3f4   @ 0x0003d3f4   (276 bytes)
 * calls     : led_sub_3c842, led_sub_3c852, led_sub_3c886, led_sub_3c896, led_sub_3c90c
 */

void led_sub_3d3f4(void)

{
  byte bVar1;
  
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  led_sub_3c896(0xb0);
  led_sub_3c90c(0xff);
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  bVar1 = 0;
  do {
    led_sub_3c852(1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  led_sub_3c842();
  led_sub_3c90c(0xff);
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  led_sub_3c896(0xb0);
  led_sub_3c90c(0xff);
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  bVar1 = 0;
  do {
    led_sub_3c852(0);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  led_sub_3c842();
  led_sub_3c90c(0xff);
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  led_sub_3c896(0xb0);
  led_sub_3c90c(0xff);
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  bVar1 = 0;
  do {
    led_sub_3c852(0);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  led_sub_3c842();
  led_sub_3c90c(0xff);
  led_sub_3c896(0);
  led_sub_3c896(0x10);
  led_sub_3c896(0xb1);
  led_sub_3c90c(0xf);
  led_sub_3c886();
  led_sub_3c852(0x78);
  led_sub_3c852(0x40);
  bVar1 = 0;
  do {
    led_sub_3c852(8);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x76);
  led_sub_3c842();
  led_sub_3c90c(0xf);
  return;
}

/* ==========================================================================
 * led_sub_3d51e   @ 0x0003d51e   (18 bytes)
 * calls     : led_sub_3c896, led_sub_3c90c
 */

void led_sub_3d51e(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    led_sub_3c90c();
    return;
  }
  led_sub_3c896();
  return;
}

/* ==========================================================================
 * led_sub_3d530   @ 0x0003d530   (22 bytes)
 * calls     : led_sub_3c896
 */

void led_sub_3d530(void)

{
  led_sub_3c896(0x8d);
  led_sub_3c896(0x72);
  led_sub_3c896(0xaf);
  return;
}
