/* Power and battery
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * power_sub_2aa44   @ 0x0002aa44   (24 bytes)
 * called by : ble_sub_2aa5c, SLEEP, enter_BLE_normal_app_mode
 */

uint power_sub_2aa44(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(shared_ro_2adb4 + 0x18) & 1) != 0) {
    uVar1 = 0x40;
  }
  if ((*(uint *)(shared_ro_2adb4 + 0x1c) & 1) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  return uVar1;
}

/* ==========================================================================
 * power_sub_2b128   @ 0x0002b128   (62 bytes)
 * called by : power_sub_2bd48, SLEEP, exist, f_reconnect_24G
 * calls     : ble_sub_2abd4
 */

undefined1 power_sub_2b128(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = ble_sub_2abd4();
  if (((iVar2 != 0) ||
      (((*shared_ro_2b51c != '\0' && (*shared_ro_2b520 == '\0')) || ((*(uint *)(shared_ro_2b524 + 0x2c) & 1) == 0)))) ||
     (((*(short *)power_ro_2b528 != 0 || (*power_ro_2b52c != '\0')) || (uVar1 = 0, *shared_ro_2b530 != '\0')))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* ==========================================================================
 * power_sub_2b166   @ 0x0002b166   (40 bytes)
 * called by : power_sub_2bd48
 */

undefined4 power_sub_2b166(void)

{
  if ((((*power_ro_2b534 == '\0' && *power_ro_2b538 == '\0') && *power_ro_2b53c == '\0') && *power_ro_2b540 == '\0') &&
     (*shared_ro_2b544 != '\0')) {
    return 0;
  }
  return 1;
}

/* ==========================================================================
 * set_force_sleep   @ 0x0002b20e   (64 bytes)
 * called by : force_24g_sleep, force_ble_sleep_2
 * calls     : rf24_sub_32886, power_sub_3587a, power_sub_3bf0a, power_sub_3d508, power_sub_3d546, dbg_printf
 * string    : "set_force_sleep"
 * string    : "%s \r\n"
 */

void set_force_sleep(void)

{
  dbg_printf(str_s_3,str_set_force_sleep);
  *shared_ro_2b544 = 1;
  power_sub_3bf0a();
  power_sub_3d508();
  power_sub_3d546();
  rf24_sub_32886(0);
  power_sub_3587a();
  *power_ro_2b534 = 0;
  *power_ro_2b538 = 0;
  *power_ro_2b568 = 0;
  *power_ro_2b53c = 0;
  *power_ro_2b56c = 0;
  return;
}

/* ==========================================================================
 * power_sub_2bcac   @ 0x0002bcac   (156 bytes)
 * called by : power_sub_2be1c, usb_sub_360aa, SLEEP, exist
 */

void power_sub_2bcac(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar2 = power_ro_2be48;
  uVar6 = 0;
  *(undefined4 *)(power_ro_2be48 + 0x20) = 0;
  *(undefined4 *)(puVar2 + 0x24) = 0;
  *(undefined4 *)(puVar2 + 0x30) = 0x2c;
  uVar5 = power_ro_2be58;
  puVar4 = power_ro_2be4c;
  puVar3 = power_ro_2be48;
  if (*power_ro_2be4c != '\0') {
    uVar6 = 2;
  }
  uVar7 = power_ro_2be54;
  if ((*(uint *)(puVar2 + 0x1c) & 1) != 0) {
    uVar7 = power_ro_2be50;
  }
  if ((*(uint *)(puVar2 + 0x18) & 1) == 0) {
    uVar8 = 0x2000;
  }
  else {
    uVar8 = 0x3000;
  }
  if ((*(uint *)(puVar2 + 0x30) & 1) == 0) {
    uVar9 = 0x2000000;
  }
  else {
    uVar9 = 0x3000000;
  }
  uVar1 = power_ro_2be58;
  if ((*(uint *)(puVar2 + 0x10) & 1) != 0) {
    uVar1 = 0x300;
  }
  *(uint *)(power_ro_2be48 + 0x80) = uVar6 | 0xfc;
  *(uint *)(puVar3 + 0x84) = uVar7 | uVar8 | uVar9 | uVar1;
  *(undefined4 *)(puVar3 + 0x8c) = power_ro_2be5c;
  *(uint *)(puVar3 + 0x8c) = *(uint *)(puVar3 + 0x8c) | 0x10000000;
  if (*puVar4 != '\0') {
    *puVar4 = 0;
    *(uint *)(puVar3 + 0x8c) = *(uint *)(puVar3 + 0x8c) | 1;
  }
  *(undefined4 *)(power_ro_2be60 + 0xc) = *(undefined4 *)(puVar3 + 0x8c);
  *(undefined4 *)(puVar3 + 0x94) = 0xffffffff;
  *(uint *)power_ro_2be64 = *(uint *)power_ro_2be64 | uVar5;
  return;
}

/* ==========================================================================
 * power_sub_2bd48   @ 0x0002bd48   (26 bytes)
 * calls     : power_sub_2b128, power_sub_2b166
 */

undefined4 power_sub_2bd48(void)

{
  int iVar1;
  
  iVar1 = power_sub_2b128();
  if ((iVar1 == 0) && (iVar1 = power_sub_2b166(), iVar1 == 0)) {
    return 2;
  }
  return 1;
}

/* ==========================================================================
 * This   @ 0x0002bdd6   (34 bytes)
 * calls     : rf24_sub_3b130, dbg_printf
 * string    : "This is the function key wakeup,start cpu reset...\r\n"
 */

void This(void)

{
  if ((*power_ro_2be80 != '\0') && (*power_ro_2be80 = 0, *power_ro_2be84 == '\0')) {
    dbg_printf(str_This_is_the_function_key_wakeup_start_cpu_re);
    rf24_sub_3b130();
  }
  return;
}

/* ==========================================================================
 * power_sub_2be1c   @ 0x0002be1c   (44 bytes)
 * called by : ble_sub_2f31c
 * calls     : power_sub_2bcac, dbg_printf
 * string    : "key wakeup timeout, need key wakeconfig\r\n"
 */

void power_sub_2be1c(void)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  puVar2 = shared_ro_2be68;
  pcVar3 = shared_ro_2be68 + 0x10;
  if ((*pcVar3 != '\0') &&
     (cVar1 = shared_ro_2be68[0x11], shared_ro_2be68[0x11] = cVar1 + 1U, 100 < (byte)(cVar1 + 1U))) {
    *pcVar3 = '\0';
    puVar2[0x11] = 0;
    dbg_printf(str_key_wakeup_timeout_need_key_wakeconfig);
    power_sub_2bcac();
  }
  return;
}

/* ==========================================================================
 * power_sub_3297e   @ 0x0003297e   (30 bytes)
 * called by : SLEEP, exist
 * calls     : ble_sub_32620, flash_sub_32e82, flash_sub_32f16
 */

void power_sub_3297e(void)

{
  *shared_ro_329e4 = 0;
  flash_sub_32f16();
  flash_sub_32e82();
  ble_sub_32620();
  *shared_ro_32a98 = 0;
  *shared_ro_32a64 = 0;
  return;
}

/* ==========================================================================
 * power_sub_33cfc   @ 0x00033cfc   (2 bytes)
 * called by : SLEEP, exist, force_ble_sleep_2
 */

void power_sub_33cfc(void)

{
  return;
}

/* ==========================================================================
 * power_sub_33cfe   @ 0x00033cfe   (2 bytes)
 * called by : SLEEP, gpio
 */

void power_sub_33cfe(void)

{
  return;
}

/* ==========================================================================
 * SLEEP   @ 0x00034712   (1250 bytes)
 * calls     : power_sub_2aa44, power_sub_2b128, power_sub_2bcac, led_sub_314d2, usb_sub_317c2, ble_sub_32620, ... (+34 more)
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
  undefined *puVar2;
  undefined *puVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  undefined *puVar12;
  
  puVar2 = power_ro_34aa4;
  puVar12 = power_ro_34aa0;
  uVar11 = 0;
  if (*shared_ro_34a34 != '\0') {
    return;
  }
  if ((*(short *)shared_ro_34a94 == 0) && (*power_ro_34a9c == '\0')) {
    dbg_printf(str_Time_Entry_Sdeep_0_x_x,*power_ro_34aa0 ^ 1,*(undefined2 *)power_ro_34aa4,param_4,param_2,
               param_3,param_4);
    if (*puVar12 == '\0' && *(short *)puVar2 == 0) {
      dbg_printf(str_entry_force_24g_sleep_1);
      force_24g_sleep();
    }
    else {
      OLED_Init();
    }
  }
  puVar2 = power_ro_34afc;
  puVar12 = power_ro_34ae8;
  if (*power_ro_34ae4 != '\0') {
    *power_ro_34ae8 = 0;
    *power_ro_34aec = 2;
    return;
  }
  if (*power_ro_34af0 != '\0') {
    return;
  }
  if ((*power_ro_34af4 != '\0') || (*power_ro_34af8 != '\0')) {
LAB_00034804:
    *puVar12 = 0;
    return;
  }
  *power_ro_34afc = 0;
  if (*(int *)power_ro_34b00 << 0x19 < 0) {
    *power_ro_34aec = *power_ro_34aec + '\x01';
    *puVar2 = 1;
    return;
  }
  if (*power_ro_34b04 == '\0') {
    led_sub_36caa();
    *power_ro_34b08 = 1;
  }
  if (*puVar12 != '\0') {
    if (*power_ro_34b08 != '\0') {
      *power_ro_34b08 = 0;
      rf24_sub_36c8e();
    }
    led_sub_36d0e(8);
    *power_ro_34b04 = 6;
    *(undefined2 *)power_ro_34b0c = 500;
    *power_ro_34aec = *power_ro_34aec + '\x01';
    *power_ro_34b10 = 5;
    *power_ro_34b14 = 0;
    return;
  }
  if (((*power_ro_34b18 != '\0') && (*power_ro_34b1c == '\0')) && (puVar12 = shared_ro_34a98, *shared_ro_34a7c != '\0'))
  goto LAB_00034804;
  if ((*power_ro_34b1c != '\0') && (*power_ro_34a9c == '\0')) {
    force_24g_sleep();
  }
  puVar12 = shared_ro_34a88;
  cVar1 = *shared_ro_34a98;
  if (cVar1 == '\0') {
    iVar6 = power_sub_2aa44();
    do {
      ble_sub_3af8a();
      iVar9 = power_sub_2b128();
      if ((iVar9 != 0) || (iVar9 = power_sub_2aa44(), iVar9 != iVar6)) goto LAB_00034874;
    } while (*power_ro_34b3c == '\0');
    *power_ro_34b3c = 0;
LAB_00034874:
    if (*power_ro_34b40 == '\0') {
      return;
    }
    *power_ro_34b40 = 0;
    uVar4 = (ushort)((byte)puVar12[0xb] >> 4) << 4 | (ushort)((byte)puVar12[0xc] >> 4);
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    if ((ushort)(uVar4 * 0xef) < *(ushort *)shared_ro_34a94) {
      return;
    }
    if (*power_ro_34a9c != '\0') {
      return;
    }
    *(undefined2 *)shared_ro_34a8c = 0;
    flash_sub_32f16();
    flash_sub_32e82();
    puVar12 = shared_ro_34a64;
    *shared_ro_34a64 = 1;
    ble_sub_32620();
    power_sub_3d508();
    power_sub_3d546();
    *puVar12 = 1;
    dbg_printf(str_enter_24g_idle_status);
    *shared_ro_34a98 = 2;
    power_sub_33cfc();
    ble_sub_39a84(0x32,0);
    return;
  }
  if (cVar1 == '\x02') {
    flash_sub_32e82();
    iVar6 = power_sub_2aa44();
    uVar7 = *(uint *)(power_ro_34b38 + 0x10) & 1;
    flash_sub_32e82();
    usb_sub_3c286(1);
    do {
      do {
        iVar9 = power_sub_2b128();
        if (iVar9 == 0) {
          power_sub_2bcac();
          uVar11 = *(uint *)(power_ro_34b38 + 0x30) & 1;
          power_sub_3b3f2();
        }
        iVar9 = power_sub_2b128();
        if ((((iVar9 != 0) || (iVar9 = power_sub_2aa44(), iVar9 != iVar6)) ||
            ((*(uint *)(power_ro_34b38 + 0x30) & 1) != uVar11)) ||
           ((*(uint *)(power_ro_34b38 + 0x10) & 1) != uVar7)) {
          if ((*(uint *)(power_ro_34b38 + 0x10) & 1) != uVar7) {
            dbg_printf(str_cpu_reset_MODE_Switch);
            rf24_sub_3b130();
          }
          iVar6 = get_usb_insert_status();
          puVar12 = power_ro_34a9c;
          *power_ro_34a9c = iVar6 != 0;
          if (*puVar12 != '\0') {
            iVar6 = USNDP_status();
            puVar12 = power_ro_34b7c;
            *power_ro_34b7c = iVar6 != 0;
            if (*puVar12 == '\0') {
              dbg_printf(str_USNDP_status_usb_insert_x,*puVar12);
              rf24_sub_3b130();
            }
          }
          OLED_Init();
          *shared_ro_34a78 = 0;
          power_sub_33cfe();
          goto LAB_00034bba;
        }
      } while (*power_ro_34b40 == '\0');
      *power_ro_34b40 = 0;
      uVar5 = (uint)((byte)puVar12[0xb] >> 4) << 4 | (uint)((byte)puVar12[0xc] >> 4);
      if (uVar5 == 0) {
        uVar5 = 1;
      }
      if ((uVar5 * 0xef - (uint)*(ushort *)shared_ro_34a94 == 0) && (*power_ro_34a9c == '\0')) {
        power_sub_3d508();
        power_sub_3d546();
      }
      if (0x31 < (byte)*shared_ro_34a78) goto LAB_00034bba;
      if (*(ushort *)shared_ro_34a94 == 0) {
        force_24g_sleep();
        goto LAB_00034bba;
      }
    } while ((*(ushort *)shared_ro_34a94 & 1) == 0);
    usb_sub_3b54e();
    puVar2 = power_ro_34ba4;
    uVar4 = (ushort)((byte)puVar12[0xb] >> 4) << 4 | (ushort)((byte)puVar12[0xc] >> 4);
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    if ((ushort)(uVar4 * 0xef) < *(ushort *)shared_ro_34a94) {
      if (*power_ro_34ba4 == '\0') {
        led_sub_314d2(1);
        *puVar2 = 8;
      }
      set_Update_OLED_2();
    }
    else {
      if (*power_ro_34ba4 == '\0') {
        led_sub_314d2(1);
        *puVar2 = 0x10;
      }
      ble_sub_39a84(0x32,0);
    }
    goto LAB_00034bba;
  }
  if (cVar1 != '\x03') {
    return;
  }
  dbg_printf(str_in_sleep_status_d_d,3,*(undefined2 *)shared_ro_34a94);
  power_sub_3d508();
  power_sub_3d546();
  flash_sub_32e82();
  puVar12 = power_ro_34b38;
  if ((*(uint *)(power_ro_34b38 + 0x2c) & 1) == 0) {
    ble_sub_33dc2();
  }
  if (((power_ro_34fbc[8] == '\0') || (*power_ro_34fc0 != '\0')) || (*shared_ro_34fc4 != '\0')) {
    sensor_pwdn();
  }
  power_sub_33cfc();
  led_sub_32892();
  power_sub_3297e();
  *power_ro_34fc8 = 1;
  usb_sub_369ac();
  *(undefined4 *)(shared_ro_34fb8 + 0x14) = 0;
  power_sub_3bf0a();
  usb_sub_3b528();
  usb_sub_3c286(1);
  do {
    iVar6 = power_sub_2aa44();
    uVar7 = *(uint *)(puVar12 + 0x10);
    uVar8 = power_sub_2b128();
    dbg_printf(str_sleep_status_24G_d_d,uVar11,uVar8);
    iVar9 = power_sub_2b128();
    if (iVar9 == 0) {
      dbg_printf(str_enter_sleep_status);
      usb_sub_317c2(0x32);
      power_sub_2bcac();
      uVar11 = *(uint *)(puVar12 + 0x30) & 1;
      power_sub_3b3f2();
      dbg_printf(str_wake_form_sleep_status);
    }
    *power_ro_3501c = 0;
    usb_sub_369a0();
    iVar9 = power_sub_2b128();
  } while ((((iVar9 == 0) && (iVar9 = power_sub_2aa44(), iVar9 == iVar6)) &&
           ((*(uint *)(puVar12 + 0x30) & 1) == uVar11)) &&
          ((*(uint *)(puVar12 + 0x10) & 1) == (uVar7 & 1)));
  if ((*(uint *)(puVar12 + 0x10) & 1) != (uVar7 & 1)) {
    dbg_printf(power_ro_35020);
    rf24_sub_3b130();
  }
  iVar6 = get_usb_insert_status();
  puVar12 = shared_ro_35024;
  *shared_ro_35024 = iVar6 != 0;
  if (*puVar12 != '\0') {
    iVar6 = USNDP_status();
    puVar12 = power_ro_35028;
    *power_ro_35028 = iVar6 != 0;
    if (*puVar12 == '\0') {
      dbg_printf(str_USNDP_status_usb_insert_x,*puVar12);
      rf24_sub_3b130();
    }
  }
  uVar8 = power_sub_2aa44();
  dbg_printf(str_wakeup_Key_Mot_Activ_USB_d_d,*(uint *)(shared_ro_3502c + 0x30) & 1,uVar8);
  puVar2 = power_ro_35068;
  puVar12 = shared_ro_35064;
  *shared_ro_35064 = 0;
  if (*puVar2 == '\0') {
    *shared_ro_34fc4 = 1;
  }
  led_sub_3beb4();
  ble_sub_3b538(power_ro_3506c);
  puVar3 = shared_ro_35070;
  *puVar12 = 0;
  *puVar3 = 0;
  flash_sub_32f16();
  flash_sub_32e82();
  OLED_Init();
  if (*puVar2 == '\0') {
    if (((power_ro_34fbc[0x10] == '\x04') && (power_ro_34fbc[0x11] == '\x04')) && (power_ro_34fbc[0x12] == '\x04')) {
      *power_ro_350b0 = 2;
      pcVar10 = str_SLEEP_wakeup_id_code;
      goto LAB_00034d4c;
    }
    if ((*(uint *)(shared_ro_3502c + 0x30) & 1) == uVar11) {
      set_bonded_led_flash();
      *shared_ro_3508c = 1;
      pcVar10 = str_SLEEP_wakeup_RECONN;
      goto LAB_00034d4c;
    }
  }
  else {
    pcVar10 = str_SLEEP_wakeup_KEY_PAIR;
LAB_00034d4c:
    dbg_printf(pcVar10);
  }
  *power_ro_350a8 = 1;
  usb_sub_3d2b0();
  *power_ro_350ac = 1;
LAB_00034bba:
  usb_sub_369a0();
  *(undefined4 *)(shared_ro_34fb8 + 0x14) = 1;
  flash_sub_3c2c6();
  return;
}

/* ==========================================================================
 * power_sub_3587a   @ 0x0003587a   (60 bytes)
 * called by : set_force_sleep
 */

void power_sub_3587a(void)

{
  *power_ro_35b84 = 0;
  *power_ro_35b88 = 0;
  *shared_ro_35b5c = 0;
  *shared_ro_35b60 = 0;
  *shared_ro_35b64 = 0;
  *(undefined2 *)shared_ro_35b68 = 0;
  *shared_ro_35b6c = 0;
  *shared_ro_35b74 = 0;
  *(undefined2 *)power_ro_35b8c = 0;
  *shared_ro_35b78 = 0;
  *shared_ro_35b7c = 0;
  *shared_ro_35b80 = 0;
  *power_ro_35b90 = 0;
  *(undefined2 *)power_ro_35b94 = 0;
  return;
}

/* ==========================================================================
 * power_sub_35c9c   @ 0x00035c9c   (54 bytes)
 * called by : USNDP_status_2, fn24main
 * calls     : rf24_sub_32886, power_sub_3c174, power_sub_3c1c6, flash_sub_3c2c6
 */

void power_sub_35c9c(void)

{
  power_sub_3c1c6(0,1,0xf);
  power_sub_3c1c6(1,0);
  flash_sub_3c2c6();
  power_sub_3c174(0,1,power_ro_35e28);
  rf24_sub_32886(0);
  *(uint *)power_ro_35e2c = *(uint *)power_ro_35e2c | 0xb;
  return;
}

/* ==========================================================================
 * power_sub_36fa2   @ 0x00036fa2   (10 bytes)
 * called by : power_sub_371c2
 */

void power_sub_36fa2(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[9] = (char)param_1;
  puVar1[10] = (char)((uint)param_1 >> 8);
  return;
}

/* ==========================================================================
 * power_sub_36fc4   @ 0x00036fc4   (10 bytes)
 * called by : power_sub_371c2
 */

void power_sub_36fc4(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[7] = (char)param_1;
  puVar1[8] = (char)((uint)param_1 >> 8);
  return;
}

/* ==========================================================================
 * power_sub_371ac   @ 0x000371ac   (22 bytes)
 * called by : power_sub_371c2
 * calls     : power_sub_37a94, rom_24FEC
 */

void power_sub_371ac(void)

{
  rom_24FEC(shared_ro_37388,0x10);
  *power_ro_3738c = 0;
  power_sub_37a94();
  return;
}

/* ==========================================================================
 * power_sub_371c2   @ 0x000371c2   (124 bytes)
 * called by : USNDP_status_2, f_usb_isConnected
 * calls     : flash_sub_36f88, power_sub_36fa2, power_sub_36fc4, power_sub_371ac
 */

void power_sub_371c2(code *param_1,code *param_2)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  
  (*param_1)(1);
  puVar2 = shared_ro_37384;
  shared_ro_37384[0xb] = 0;
  power_sub_36fa2(0);
  power_sub_36fc4(0);
  pbVar3 = shared_ro_37384 + 0x80;
  shared_ro_37384[0x88] = shared_ro_37384[0x88] & 0x7f;
  power_sub_36fa2(7);
  power_sub_36fc4(7);
  puVar2[0xb] = 0x3f;
  pbVar3[4] = 0;
  *pbVar3 = 8;
  pbVar3[0x1c] = 0xf4;
  *pbVar3 = *pbVar3 | 1;
  flash_sub_36f88(500);
  bVar1 = pbVar3[0x14];
  flash_sub_36f88(500);
  pbVar3[0x14] = bVar1;
  flash_sub_36f88(500);
  pbVar3[0xc] = 0x77;
  power_sub_371ac();
  *puVar2 = 0;
  puVar2[0xf] = 1;
  (*param_2)();
  power_ro_37390[1] = 0;
  return;
}

/* ==========================================================================
 * power_sub_377fe   @ 0x000377fe   (16 bytes)
 * called by : USNDP_status_2, f_usb_isConnected
 */

void power_sub_377fe(int param_1,undefined4 param_2)

{
  if (param_1 < 6) {
    *(undefined4 *)(usb_ro_37bf0 + param_1 * 0x18 + 0x10) = param_2;
  }
  return;
}

/* ==========================================================================
 * power_sub_37a88   @ 0x00037a88   (12 bytes)
 * called by : power_sub_37a94
 */

void power_sub_37a88(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_37bf4;
  *(undefined2 *)(shared_ro_37bf4 + 2) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  return;
}

/* ==========================================================================
 * power_sub_37a94   @ 0x00037a94   (34 bytes)
 * called by : power_sub_371ac
 * calls     : power_sub_37a88, power_sub_3834c, usb_sub_4245e, rom_24FEC
 */

void power_sub_37a94(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = power_sub_3834c();
  uVar2 = (undefined4)uVar3;
  power_sub_37a88(uVar2,(int)((ulonglong)uVar3 >> 0x20),uVar2);
  iVar1 = usb_sub_4245e(uVar2);
  shared_ro_37bf4[1] = *(undefined1 *)(iVar1 + 7);
  rom_24FEC(usb_ro_37bf0,0x90);
  return;
}

/* ==========================================================================
 * power_sub_3834c   @ 0x0003834c   (4 bytes)
 * called by : power_sub_37a94
 */

undefined * power_sub_3834c(void)

{
  return shared_ro_38394;
}

/* ==========================================================================
 * USNDP_status_2   @ 0x00038df6   (344 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : usb_sub_317c2, power_sub_35c9c, power_sub_371c2, power_sub_377fe, usb_sub_3afa2, rf24_sub_3b130, ... (+6 more)
 * string    : "USNDP_status------charging   %x\r\n"
 * string    : "USNDP_status------usb insert  %x\r\n"
 * string    : "usb mode..................\r\n"
 * string    : "usb_init  wait_usb_time=%x, %x\r\n"
 * string    : "wait_usb_time=%d, USB_OTG_CFG=%d,Get_USBDN=%x\r\n"
 * string    : "usb_mode_check  RF_MODE USB %x, %x, %x\r\n"
 */

void USNDP_status_2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = power_ro_39058;
  iVar4 = USNDP_status();
  puVar1 = power_ro_3905c;
  *power_ro_3905c = iVar4 != 0;
  if (*puVar1 == '\0') {
    dbg_printf(str_USNDP_status_usb_insert_x_2,*puVar1);
  }
  else {
    iVar4 = USNDP_status();
    *puVar1 = iVar4 != 0;
    if (*puVar1 == '\0') {
      dbg_printf(str_USNDP_status_usb_insert_x_2,*puVar1);
      uVar5 = shared_ro_390a8;
    }
    else {
      dbg_printf(str_USNDP_status_charging_x,*puVar1);
      uVar5 = 0x1fe;
    }
  }
  if (*power_ro_390ac != '\0') {
    dbg_printf(str_usb_mode);
    *power_ro_390d0 = 1;
    power_sub_35c9c();
    puVar3 = power_ro_390d8;
    puVar1 = power_ro_390d4;
    do {
      uVar6 = 0;
      if (uVar5 == 0) goto LAB_00038f30;
      uVar6 = power_ro_39058 - 10;
      do {
        if ((((uVar5 == uVar6) || (uVar5 == power_ro_390dc)) || (uVar5 == power_ro_390e0)) ||
           (((uVar5 == 4000 || (uVar5 == power_ro_390e4)) || ((uVar5 == 2000 || (uVar5 == 1000)))))) {
          power_sub_371c2(shared_ro_390ec,shared_ro_390e8);
          power_sub_377fe(1,power_ro_390f0);
          power_sub_377fe(2,power_ro_390f4);
          power_sub_377fe(3,power_ro_390f8);
          power_sub_377fe(4,power_ro_390fc);
          uVar5 = uVar5 - 1 & 0xffff;
          dbg_printf(str_usb_init_wait_usb_time_x_x,uVar5,*puVar1);
        }
        usb_sub_3b54e();
        if (uVar5 == 0) {
          usb_sub_3afa2(1);
          uVar6 = 0;
          goto LAB_00038f30;
        }
      } while (*puVar3 == '\0');
      *puVar3 = 0;
      uVar6 = uVar5 - 1 & 0xffff;
      dbg_printf(str_wait_usb_time_d_USB_OTG_CFG_d_Get_USBDN_x,uVar6,*shared_ro_39004,
                 *(uint *)(shared_ro_38f88 + -0x40) & 1);
      if (*power_ro_39154 != '\0') {
        uVar6 = 0;
        *power_ro_39158 = 0;
        Success_led_2second_2();
        flash_sub_3cf7c();
        usb_sub_317c2(200);
        goto LAB_00038f30;
      }
      iVar4 = get_usb_insert_status();
      puVar2 = power_ro_390ac;
      *power_ro_390ac = iVar4 != 0;
      uVar5 = uVar6;
    } while (*puVar2 != '\0');
    rf24_sub_3b130();
LAB_00038f30:
    dbg_printf(str_usb_mode_check_RF_MODE_USB_x_x_x,uVar6,*puVar1,*power_ro_3915c);
  }
  return;
}

/* ==========================================================================
 * addPMU_Reg0x5   @ 0x00039d54   (170 bytes)
 * called by : cal_data
 * calls     : usb_sub_317c2, dbg_printf
 * string    : "addPMU_Reg0x5 = 0x%x\n"
 */

void addPMU_Reg0x5(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar1 = usb_ro_3a008;
  *(uint *)(usb_ro_3a008 + 0x24) = *(uint *)(usb_ro_3a008 + 0x24) & 0xffffffbf;
  puVar2 = usb_ro_3a00c;
  *(undefined4 *)(usb_ro_3a00c + 0x24) = *(undefined4 *)(puVar1 + 0x24);
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) & 0xffff7fff;
  *(undefined4 *)(puVar2 + 0x30) = *(undefined4 *)(puVar1 + 0x30);
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | 0x8000;
  *(undefined4 *)(puVar2 + 0x30) = *(undefined4 *)(puVar1 + 0x30);
  usb_sub_317c2(100);
  uVar3 = *(uint *)(power_ro_3a024 + 0x14);
  dbg_printf(str_addPMU_Reg0x5_0x_x,*(undefined4 *)(power_ro_3a024 + 0x14));
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) & power_ro_3a040;
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | ((uVar3 & 0x3ffff) >> 9) << 4;
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) & 0xfffffff0;
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | (uVar3 & 0x3fffff) >> 0x12;
  *(undefined4 *)(puVar2 + 0x30) = *(undefined4 *)(puVar1 + 0x30);
  *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) & 0xffffffc7;
  *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) | ((uVar3 & 0x1ffffff) >> 0x16) << 3;
  *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(puVar1 + 0x24);
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | 0x2000;
  *(undefined4 *)(puVar2 + 0x30) = *(undefined4 *)(puVar1 + 0x30);
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) & 0xffff7fff;
  *(undefined4 *)(puVar2 + 0x30) = *(undefined4 *)(puVar1 + 0x30);
  *(uint *)(puVar1 + 0x30) = *(uint *)(puVar1 + 0x30) | 0x8000;
  *(undefined4 *)(puVar2 + 0x30) = *(undefined4 *)(puVar1 + 0x30);
  return;
}

/* ==========================================================================
 * addPMU_Reg0x5_2   @ 0x0003a6cc   (132 bytes)
 * called by : RC32K
 * calls     : dbg_printf
 * string    : "addPMU_Reg0x5 = 0x%x\n"
 */

void addPMU_Reg0x5_2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(power_ro_3a8f0 + 0x14);
  dbg_printf(power_ro_3a8f4,*(undefined4 *)(power_ro_3a8f0 + 0x14));
  puVar2 = shared_ro_3a8ec;
  *(uint *)(shared_ro_3a8ec + 0x30) = *(uint *)(shared_ro_3a8ec + 0x30) & power_ro_3a8f8;
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) | ((uVar3 & 0x3ffff) >> 9) << 4;
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) & 0xfffffff0;
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) | (uVar3 & 0x3fffff) >> 0x12;
  *(uint *)(puVar2 + 0x24) = *(uint *)(puVar2 + 0x24) & 0xffffffc7;
  *(uint *)(puVar2 + 0x24) = *(uint *)(puVar2 + 0x24) | ((uVar3 & 0x1ffffff) >> 0x16) << 3;
  puVar1 = shared_ro_3a8e0;
  *(undefined4 *)(shared_ro_3a8e0 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  *(undefined4 *)(puVar1 + 0x24) = *(undefined4 *)(puVar2 + 0x24);
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) | 0x2000;
  *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) & 0xffff7fff;
  *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) | 0x8000;
  *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  return;
}

/* ==========================================================================
 * power_sub_3b214   @ 0x0003b214   (54 bytes)
 * called by : ble_sub_3b34c, power_sub_3b3f2
 */

void power_sub_3b214(void)

{
  reg_80000c = reg_80000c & 0xfffdffff;
  reg_800034 = reg_800034 | 0x80;
  *(uint *)(shared_ro_3b24c + 0x38) = (*(uint *)(shared_ro_3b24c + 0x38) & 0xffffff) + 0xf000000;
  reg_820034 = 0;
  reg_82003c = power_ro_3b348;
  reg_820030 = 7;
  return;
}

/* ==========================================================================
 * power_sub_3b3f2   @ 0x0003b3f2   (140 bytes)
 * called by : SLEEP
 * calls     : ble_sub_39198, power_sub_3b214
 */

void power_sub_3b3f2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  
  ble_sub_39198(8);
  iVar3 = 0x800000;
  reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  power_sub_3b214();
  puVar1 = shared_ro_3b4f0;
  *(uint *)(shared_ro_3b4f0 + 0x1c) = *(uint *)(shared_ro_3b4f0 + 0x1c) | 0x80;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 2;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 4;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 1;
  uVar4 = *(uint *)(puVar1 + 0x1c);
  shared_ro_3b4fc[3] = 1;
  puVar2 = shared_ro_3b4f4;
  *(uint *)(shared_ro_3b4f4 + 0x10) = (*(uint *)(shared_ro_3b4f4 + 0x10) & 0xffff0fff) + 0x5000;
  *(uint *)(puVar2 + 0x10) = (*(uint *)(puVar2 + 0x10) & 0xffffff0f) + 0x50;
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffe7f;
  *(uint *)(puVar1 + 0x1c) = uVar4 | 8;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 1;
  *(undefined4 *)(puVar1 + 0x1c) = 0x80;
  *(undefined4 *)(puVar2 + 0x10) = shared_ro_3b4f8;
  *(uint *)(iVar3 + 8) = (*(uint *)(iVar3 + 8) & 0xfffffe7f) + 0x80;
  return;
}

/* ==========================================================================
 * power_sub_3b568   @ 0x0003b568   (78 bytes)
 * called by : referance_voltage, set_Update_OLED_2
 * calls     : ble_sub_39a84
 */

void power_sub_3b568(int param_1,uint param_2)

{
  undefined *puVar1;
  
  reg_80000c = reg_80000c & 0xfffffbff;
  ble_sub_39a84(param_1 + 0x30U & 0xff,2);
  puVar1 = shared_ro_3b6bc;
  *(uint *)shared_ro_3b6bc = param_1 << 3 | param_2 | power_ro_3b6b8;
  *(undefined4 *)(puVar1 + 8) = power_ro_3b6c0;
  *(undefined4 *)(puVar1 + 0xc) = 3;
  *(uint *)shared_ro_3b6c4 = *(uint *)shared_ro_3b6c4 | (int)puVar1 >> 0xf;
  if (param_2 == 3) {
    *(uint *)puVar1 = *(uint *)puVar1 | 4;
  }
  return;
}

/* ==========================================================================
 * power_sub_3b5f8   @ 0x0003b5f8   (88 bytes)
 * called by : referance_voltage, set_Update_OLED_2
 * calls     : rf24_sub_31784
 */

undefined2 power_sub_3b5f8(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  ushort uVar3;
  
  puVar2 = shared_ro_3b6c8;
  puVar1 = shared_ro_3b6bc;
  uVar3 = 0;
  *shared_ro_3b6c8 = 0;
  if ((~*(uint *)puVar1 & 3) == 0) {
    return 0;
  }
  *(uint *)puVar1 = *(uint *)puVar1 | param_1 * 8 + param_2 + 4U;
  do {
    uVar3 = uVar3 + 1;
    if (300 < uVar3) break;
    rf24_sub_31784(1);
  } while (*puVar2 == '\0');
  if (*puVar2 == '\x01') {
    *(short *)(puVar2 + 4) = (short)((*(uint *)(puVar1 + 0x10) & 0x3ffff) >> 2);
  }
  *(uint *)puVar1 = *(uint *)puVar1 & 0xffffff80;
  return *(undefined2 *)(puVar2 + 4);
}

/* ==========================================================================
 * referance_voltage   @ 0x0003b650   (102 bytes)
 * calls     : rf24_sub_31784, power_sub_3b568, power_sub_3b5f8, dbg_printf, rom_24F24
 * string    : "referance_voltage=%d\r\n"
 */

void referance_voltage(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  short sVar3;
  undefined4 uVar4;
  byte bVar5;
  
  puVar2 = power_ro_3b6cc;
  *(uint *)(power_ro_3b6cc + 0x1c) = *(uint *)(power_ro_3b6cc + 0x1c) | 0x80000;
  *(undefined4 *)(power_ro_3b6d0 + 0x1c) = *(undefined4 *)(puVar2 + 0x1c);
  power_sub_3b568(7,1,param_3,param_4,param_4);
  puVar1 = shared_ro_3b6c8;
  bVar5 = 0;
  do {
    sVar3 = power_sub_3b5f8(7,1);
    *(short *)(puVar1 + 2) = sVar3 + *(short *)(puVar1 + 2);
    rf24_sub_31784(power_ro_3b6d4);
    bVar5 = bVar5 + 1;
  } while (bVar5 < 6);
  uVar4 = rom_24F24(*(undefined2 *)(puVar1 + 2),6);
  uVar4 = rom_24F24(power_ro_3b6d8,uVar4);
  *(short *)(puVar1 + 6) = (short)uVar4;
  dbg_printf(str_referance_voltage_d,uVar4);
  *(uint *)(puVar2 + 0x1c) = *(uint *)(puVar2 + 0x1c) & 0xfff7ffff;
  *(undefined4 *)(power_ro_3b6d0 + 0x1c) = *(undefined4 *)(puVar2 + 0x1c);
  return;
}

/* ==========================================================================
 * power_sub_3bf0a   @ 0x0003bf0a   (54 bytes)
 * called by : SLEEP, app_mutli_link_change, exist, force_ble_sleep, set_force_sleep
 */

void power_sub_3bf0a(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3bf98;
  *(uint *)shared_ro_3bf98 = *(uint *)shared_ro_3bf98 & 0xffffffbf;
  *(uint *)puVar1 = *(uint *)puVar1 & 0xffffffef;
  *(uint *)puVar1 = *(uint *)puVar1 & 0xffffffdf;
  *(uint *)puVar1 = *(uint *)puVar1 & 0xfffffff7;
  *(uint *)puVar1 = *(uint *)puVar1 & 0xfffffffb;
  *(uint *)shared_ro_3bfa8 = *(uint *)shared_ro_3bfa8 & ~((int)shared_ro_3bfa8 >> 0xb);
  return;
}

/* ==========================================================================
 * power_sub_3c174   @ 0x0003c174   (82 bytes)
 * called by : power_sub_35c9c
 */

void power_sub_3c174(int param_1,int param_2,int param_3)

{
  if (param_1 != 0) {
    if (param_1 != 1) {
      return;
    }
    if (param_2 == 0) {
      if (param_3 == 0) {
        return;
      }
      *(int *)(shared_ro_3c4e0 + 0x10) = param_3;
    }
    else {
      if (param_2 != 1) {
        if (param_2 != 2) {
          return;
        }
        if (param_3 == 0) {
          return;
        }
        *(int *)(shared_ro_3c4e0 + 0x18) = param_3;
        return;
      }
      if (param_3 != 0) {
        *(int *)(shared_ro_3c4e0 + 0x14) = param_3;
        return;
      }
    }
    return;
  }
  if (param_2 == 0) {
    if (param_3 != 0) {
      *(int *)(shared_ro_3c4e0 + 4) = param_3;
      return;
    }
  }
  else {
    if (param_2 == 1) {
      if (param_3 == 0) {
        return;
      }
      *(int *)(shared_ro_3c4e0 + 8) = param_3;
      return;
    }
    if (param_2 != 2) {
      return;
    }
    if (param_3 == 0) {
      return;
    }
    *(int *)(shared_ro_3c4e0 + 0xc) = param_3;
  }
  return;
}

/* ==========================================================================
 * power_sub_3c1c6   @ 0x0003c1c6   (88 bytes)
 * called by : power_sub_35c9c
 */

void power_sub_3c1c6(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    uVar2 = 4;
    puVar1 = (undefined4 *)shared_ro_3c4e4;
    if (param_2 == 0) {
      reg_800010 = reg_800010 & 0xfffffffb;
    }
    else {
      reg_800010 = reg_800010 | 4;
    }
  }
  else {
    if (param_1 != 1) goto LAB_0003c214;
    uVar2 = 8;
    puVar1 = (undefined4 *)shared_ro_3c4e8;
    if (param_2 == 0) {
      reg_800010 = reg_800010 & 0xfffffff7;
    }
    else {
      reg_800010 = reg_800010 | 8;
    }
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[3] = puVar1[3] & 0xffffff87 | param_3 << 3;
  reg_80000c = reg_80000c & ~uVar2;
LAB_0003c214:
  *shared_ro_3c4e0 = 0;
  return;
}

/* ==========================================================================
 * Charging   @ 0x0003d062   (32 bytes)
 * called by : Detect_FULL_IN, usb_sub_3d2b0
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
  
  if (*shared_ro_3d130 == '\0') {
    return;
  }
  if (*shared_ro_3d134 == '\0') {
    pcVar2 = str_Charging;
  }
  else {
    pcVar2 = str_BAT_FULL;
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
 * power_sub_3d508   @ 0x0003d508   (22 bytes)
 * called by : SLEEP, force_ble_sleep, set_Update_OLED, set_force_sleep
 * calls     : OLED_Clear
 */

void power_sub_3d508(void)

{
  undefined *puVar1;
  
  OLED_Clear();
  puVar1 = shared_ro_3d694;
  *(undefined4 *)shared_ro_3d694 = 0x3c;
  *(undefined4 *)(puVar1 + 4) = 0x3c;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0x3c;
  return;
}

/* ==========================================================================
 * power_sub_3d546   @ 0x0003d546   (22 bytes)
 * called by : SLEEP, force_ble_sleep, set_Update_OLED, set_force_sleep
 * calls     : led_sub_3c896
 */

void power_sub_3d546(void)

{
  led_sub_3c896(0xae);
  led_sub_3c896(0x8d);
  led_sub_3c896(0x10);
  return;
}

/* ==========================================================================
 * RC32K   @ 0x0003e2ac   (88 bytes)
 * called by : ble_sub_3e304
 * calls     : addPMU_Reg0x5_2, dbg_printf, rom_ro_1804c
 * string    : "RC32K-Cali.Compl\n"
 * string    : "RC32K-Cali.End\n"
 */

undefined4 RC32K(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int local_18;
  undefined4 uStack_14;
  
  puVar1 = shared_ro_3e448;
  local_18 = param_3;
  uStack_14 = param_4;
  if (*shared_ro_3e448 == '\x02') {
    rom_ro_1804c(&local_18);
    iVar2 = local_18;
    if (99 < (uint)(local_18 - *(int *)(puVar1 + 4))) {
      dbg_printf(str_RC32K_Cali_Compl);
      addPMU_Reg0x5_2();
      *(int *)(puVar1 + 4) = iVar2;
      *puVar1 = 3;
    }
    return 0;
  }
  if (*shared_ro_3e448 == '\x03') {
    rom_ro_1804c(&local_18);
    iVar2 = local_18;
    if ((uint)(local_18 - *(int *)(puVar1 + 4)) < 100) {
      return 0;
    }
    *(int *)(puVar1 + 4) = local_18;
    dbg_printf(str_RC32K_Cali_End);
    *(int *)(puVar1 + 4) = iVar2;
  }
  *puVar1 = 0;
  return 1;
}
