/* Bluetooth LE
 *
 * Recovered from the AQIRYS Zephyr 2 application image.
 * This is reverse-engineered reference source: it documents behaviour,
 * it is not a buildable translation unit. Types are Ghidra inference.
 */
#include "zephyr.h"
#include "firmware_globals.h"

/* ==========================================================================
 * rom_ro_1804c   @ 0x0001804c   (1 bytes)
 * called by : ble_sub_3c6ce, ble_sub_3dc3c, ble_sub_3e0bc, ble_sub_3e268, ble_sub_3e304, RC32K
 */

/* WARNING: Control flow encountered bad instruction data */

void rom_ro_1804c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ==========================================================================
 * ble_sub_28ac0   @ 0x00028ac0   (16 bytes)
 * calls     : ble_sub_3c008
 */

void ble_sub_28ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_lr;
  
  ble_sub_3c008();
                    /* WARNING: Could not recover jumptable at 0x00028acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + -4))(param_1,param_2,param_3,param_4);
  return;
}

/* ==========================================================================
 * ble_sub_28b00   @ 0x00028b00   (54 bytes)
 * called by : TEST_SINGLE_WAVE, enter_BLE_normal_app_mode
 * calls     : rom_24FEC
 */

void ble_sub_28b00(void)

{
  undefined *puVar1;
  
  rom_24FEC(ble_ro_28efc,0x28);
  puVar1 = ble_ro_28efc;
  *(undefined **)ble_ro_28efc = ble_ro_28f00;
  *(undefined **)(puVar1 + 4) = ble_ro_28f04;
  *(undefined **)(puVar1 + 8) = ble_ro_28f08;
  *(undefined **)(puVar1 + 0xc) = ble_ro_28f0c;
  *(undefined **)(puVar1 + 0x10) = ble_ro_28f10;
  *(undefined **)(puVar1 + 0x14) = ble_ro_28f14;
  *(undefined **)(puVar1 + 0x18) = ble_ro_28f18;
  *(undefined **)(puVar1 + 0x1c) = ble_ro_28f1c;
  *(undefined **)(puVar1 + 0x20) = ble_ro_28f20;
  *(undefined **)(puVar1 + 0x24) = ble_ro_28f24;
  return;
}

/* ==========================================================================
 * force_pair_en   @ 0x00028b36   (268 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : rf24_sub_29ed8, ble_sub_3948a, ble_sub_3e552, ble_sub_3e5f0, Get_MODE_Switch_status, app_ble_addr_tabl_init, ... (+7 more)
 * string    : "Rf mode  =  %x,\r\n"
 * string    : "flash7E000 mac addr:"
 * string    : "force_pair_en ========%x\r\n"
 * string    : "ble address set:"
 * string    : "flash7E100 SumAddr:"
 */

undefined8 force_pair_en(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 uVar3;
  int iVar4;
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
  iVar4 = Get_MODE_Switch_status();
  puVar1 = ble_ro_28f28;
  uVar3 = 0;
  if (iVar4 != 0) {
    *ble_ro_28f28 = 1;
    iVar4 = ble_sub_3e552(0x38,&local_18,&local_14);
    if (iVar4 != 0) {
      ble_sub_3e5f0(0x38,1,puVar1);
      goto LAB_00028b62;
    }
    uVar3 = (undefined1)local_14;
    if (((local_14 & 0xff) != 1) && ((local_14 & 0xff) != 2)) {
      *puVar1 = 1;
      goto LAB_00028b62;
    }
  }
  *puVar1 = uVar3;
LAB_00028b62:
  dbg_printf(str_Rf_mode_x,*puVar1);
  ble_sub_3948a(&local_20,0x7e000,6);
  if ((((local_20 != -1) || (local_1f != -1)) || (local_1e != -1)) ||
     (((local_1d != -1 || (local_1c != -1)) || (local_1b != -1)))) {
    rom_24F9C(ble_ro_28f40,&local_20,6);
  }
  dbg_printf_2(str_flash7E000_mac_addr,&local_20,6);
  app_ble_addr_tabl_init();
  app_bond_status_initial();
  puVar1 = ble_ro_28f5c;
  *(uint *)ble_ro_28f5c = *(uint *)ble_ro_28f5c & 0xfffffffa;
  puVar2 = ble_ro_28f60;
  *ble_ro_28f60 = *ble_ro_28f60 | 2;
  iVar4 = force();
  *ble_ro_28f64 = (char)iVar4;
  if (iVar4 == 0) {
    sys_flag();
  }
  else {
    dbg_printf(str_force_pair_en_x);
    rf24_sub_29ed8(0);
    rom_11550();
    *puVar2 = *puVar2 & 0xfd | 1;
    *ble_ro_28f84 = 1;
    *(uint *)puVar1 = *(uint *)puVar1 | 1;
    dbg_printf_2(str_ble_address_set,ble_ro_28f40,6);
  }
  ble_sub_3948a(ble_ro_28fa0,ble_ro_28f9c,4);
  dbg_printf_2(str_flash7E100_SumAddr,ble_ro_28fa0,4);
  return CONCAT26(uStack_1a,
                  CONCAT15(local_1b,CONCAT14(local_1c,CONCAT13(local_1d,CONCAT12(local_1e,CONCAT11(
                                                  local_1f,local_20))))));
}

/* ==========================================================================
 * ble_sub_28c48   @ 0x00028c48   (6 bytes)
 * called by : ble_sub_3b932, ble_sub_3bb38, cal_data, rwip_driver_init
 */

undefined1 ble_sub_28c48(void)

{
  return *ble_ro_28fb8;
}

/* ==========================================================================
 * ble_sub_28c4e   @ 0x00028c4e   (24 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : ble_sub_32686, ble_sub_3b932, ble_sub_3bde6, ble_sub_3e03e
 */

void ble_sub_28c4e(void)

{
  ble_sub_3b932(&rom_ro_1c200);
  ble_sub_32686(3);
  do {
    ble_sub_3e03e();
    ble_sub_3bde6();
  } while( true );
}

/* ==========================================================================
 * ble_sub_28c66   @ 0x00028c66   (242 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : BLE_PAIR, Default_Profile, FLASH_WR_Profile, FLASH_wr_Global, ble_sub_2aa5c, ble_sub_2f31c, ... (+16 more)
 */

void ble_sub_28c66(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  rf24_sub_32886(1);
  puVar3 = ble_ro_28fc0;
  puVar2 = ble_ro_28fbc;
  puVar1 = ble_ro_28f28;
  do {
    if ((((*puVar1 != '\x01') && (*puVar1 != '\x02')) || (*puVar3 != '\0')) || (*puVar3 != '\0')) {
      return;
    }
    ble_sub_3e03e();
    usb_sub_3b54e();
    ble_sub_405ae();
    BLE_PAIR();
    if ((*(uint *)(ble_ro_28fc4 + 0x2c) & 1) != 1 || *ble_ro_28fc8 != '\0') {
      ble_sub_2f31c();
    }
    there();
    iVar4 = rom_25024();
    iVar5 = rom_25038();
    if (*ble_ro_28fcc != '\0') {
      *ble_ro_28fcc = 0;
      FLASH_wr_Global();
    }
    if (*ble_ro_28fd0 != '\0') {
      *ble_ro_28fd0 = 0;
      FLASH_WR_Profile(*ble_ro_28fd4);
    }
    if (*puVar2 != '\0') {
      *puVar2 = 0;
      flash_erase(*ble_ro_28fd8);
    }
    if (*ble_ro_28fdc != '\0') {
      *ble_ro_28fdc = 0;
      Default_Profile();
    }
    iVar6 = rom_071EA(3);
    if (iVar6 == 3) {
      ble_sub_2aa5c();
    }
    if (*ble_ro_28fe0 == '\0' && *ble_ro_28fe4 == '\0') {
      iVar6 = ble_sub_3e304();
      if (iVar6 == 1) {
LAB_00028d24:
        ble_sub_3af8a();
      }
      else if (iVar6 == 2) {
        if (*ble_ro_28fe8 == '\0') goto LAB_00028d24;
        ble_sub_3ae82();
        ble_sub_3af2c();
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
 * calls     : ble_sub_28b00, ble_sub_28c4e, ble_sub_28c66, ble_sub_2a5e4, ble_sub_2a78c, power_sub_2aa44, ... (+36 more)
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
  undefined1 uVar5;
  short sVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined1 uVar11;
  int iVar12;
  char *pcVar13;
  byte bVar14;
  
  *ble_ro_28fec = 0;
  ble_sub_3ae40();
  ble_sub_311de();
  usb_sub_3b528();
  ble_sub_2a5e4();
  ble_sub_31334();
  ble_sub_3bfc2();
  puVar8 = ble_ro_28fb8;
  *ble_ro_28fb8 = 0;
  ble_sub_39428();
  ble_sub_3e516();
  KEY_piaring_cnt();
  iVar12 = get_usb_insert_status();
  *ble_ro_28ff0 = iVar12 != 0;
  force_pair_en();
  flash_sub_3262c();
  flash_sub_32658();
  rom_24F8A((uint)(byte)*ble_ro_28f40 + (uint)(byte)ble_ro_28f40[5]);
  ble_sub_28b00(ble_ro_28efc);
  KEY_piaring_cnt();
  rwip_driver_init(0);
  uVar11 = power_sub_2aa44();
  *ble_ro_28ff4 = uVar11;
  dbg_printf(str_OLED_Init_0);
  flash_sub_3c8b6();
  iVar12 = ble_sub_2a78c();
  puVar9 = ble_ro_29008;
  *ble_ro_29008 = (char)iVar12;
  if (iVar12 == 5) {
    usb_sub_3d8da(0x78);
    usb_sub_317c2(2000);
  }
  ble_sub_32620();
  rom_2504C();
  rom_2505C();
  dbg_printf(str_Mouse_reset_reason_x,*puVar9);
  puVar7 = ble_ro_28f28;
  if (*puVar9 == '\x05') {
    ble_sub_2ac0e();
    puVar9 = ble_ro_29040;
    dbg_printf(str_Key_CurrentStatus_x,*(undefined2 *)ble_ro_29040);
    sVar6 = *(short *)puVar9;
    if (sVar6 == 6) {
      *ble_ro_29060 = 1;
      *puVar7 = 0;
      *puVar8 = 0;
    }
    else if ((sVar6 == 7) || (sVar6 == 10)) {
      *puVar7 = 0;
      ble_sub_35cd2();
    }
  }
  dbg_printf(str_system_power_on_RF_MODE_x,*puVar7);
  OLED_Init();
  if ((*puVar8 & 1) != 0) {
    dbg_printf(str_enter_dut_fcc_mode);
    rom_2504C();
    rom_2505C();
    usb_sub_3afa2(3);
    ble_sub_28c4e();
  }
  profile_mem_init();
  flash_sub_3262c();
  *ble_ro_2909c = *puVar7;
  sensor_init();
  ble_sub_2b4c8();
  if (*ble_ro_28ff0 != '\0') {
    Linking();
    ble_sub_3b512(ble_ro_290a0);
    USNDP_status_2();
    usb_sub_3b528();
  }
  bVar14 = 0;
  do {
    *ble_ro_290a4 = 0;
    set_Update_OLED_2();
    usb_sub_317c2(10);
    bVar14 = bVar14 + 1;
  } while (bVar14 < 0x1e);
  OLED_Clear();
  flash_sub_3cf7c();
  puVar9 = ble_ro_28fc0;
  do {
    do {
      while ((cVar1 = *puVar7, cVar1 == '\0' || (*puVar9 != '\0'))) {
        if (*puVar9 == '\0') {
          usb_sub_3afa2(1);
          uVar11 = *ble_ro_291f4;
          uVar2 = *ble_ro_291f8;
          uVar5 = *puVar7;
          uVar3 = ble_ro_291fc[6];
          uVar4 = *ble_ro_29200;
          pcVar13 = str_RF_MODE_24G_x_x_x_x_x;
        }
        else {
          usb_sub_3afa2(5);
          uVar11 = *ble_ro_290a8;
          uVar2 = *ble_ro_290ac;
          uVar3 = ble_ro_290b0[6];
          uVar4 = *ble_ro_290b4;
          uVar5 = *puVar7;
          pcVar13 = str_f_usb_ena_x_x_x_x_x;
        }
        dbg_printf(pcVar13,uVar5,uVar3,uVar4,uVar2,uVar11);
        puVar10 = ble_ro_29234;
        reg_80000c = reg_80000c | 0x20000;
        *(uint *)ble_ro_29234 = *(uint *)ble_ro_29234 & ~((int)ble_ro_29234 << 0xe);
        *(uint *)puVar10 = *(uint *)puVar10 & ~((int)puVar10 << 0x10);
        *(uint *)puVar10 = *(uint *)puVar10 & ~((int)puVar10 << 0xf);
        ble_sub_3b512(ble_ro_29238);
        led_sub_3beb4();
        *ble_ro_2923c = 0;
        dbg_printf(str_system_mode0_RF_MODE_x_x_x,*puVar8,*puVar7,*ble_ro_29240);
        fn24main();
      }
    } while ((((cVar1 != '\x01') && (cVar1 != '\x02')) || (*puVar9 != '\0')) || (*puVar9 != '\0'));
    usb_sub_3afa2(1);
    dbg_printf(str_enter_BLE_normal_app_mode_RF_MODE_x,*puVar7);
    ble_sub_3b512(ble_ro_29238);
    led_sub_3beb4();
    KEY_piaring_cnt();
    *ble_ro_2923c = 0;
    ble_sub_28c66();
  } while( true );
}

/* ==========================================================================
 * ble_sub_29164   @ 0x00029164   (12 bytes)
 * called by : rwip_driver_init
 */

undefined * ble_sub_29164(int param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 == 0) {
    puVar1 = ble_ro_292a0;
  }
  return puVar1;
}

/* ==========================================================================
 * ble_sub_29392   @ 0x00029392   (46 bytes)
 * called by : ble_sub_29530, limit
 * calls     : rom_24F9C
 * string    : "AQIRYS Zephyr 2"
 * string    : "AQIRYS Zephyr"
 */

void ble_sub_29392(void)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  puVar1 = shared_ro_2977c;
  if (*ble_ro_29778 == '\x01') {
    rom_24F9C(shared_ro_2977c + 10,str_AQIRYS_Zephyr,0xe);
    uVar2 = 0xe;
  }
  else {
    if (*ble_ro_29778 != '\x02') {
      return;
    }
    rom_24F9C(shared_ro_2977c + 10,str_AQIRYS_Zephyr_2,0x10);
    uVar2 = 0x10;
  }
  puVar1[9] = uVar2;
  return;
}

/* ==========================================================================
 * limit   @ 0x000293c0   (164 bytes)
 * called by : adv_data
 * calls     : ble_sub_29392, dbg_printf, rom_24F9C
 * string    : "limit\r\n"
 * string    : "no limit\r\n"
 */

void limit(uint param_1,ushort *param_2,undefined1 *param_3)

{
  ushort uVar1;
  undefined *puVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  
  ble_sub_29392();
  *param_3 = 2;
  param_3[1] = 1;
  if ((*(uint *)ble_ro_297a0 & 1) == 0) {
    dbg_printf(str_no_limit);
    uVar3 = 4;
  }
  else {
    dbg_printf(str_limit);
    uVar3 = 5;
  }
  param_3[2] = uVar3;
  *param_2 = *param_2 + 3;
  rom_24F9C(param_3 + 3,&ble_ro_297b8,4);
  *param_2 = *param_2 + 4;
  rom_24F9C(param_3 + 7,&ble_ro_297c0,4);
  uVar1 = *param_2;
  *param_2 = (ushort)(uVar1 + 4);
  puVar2 = shared_ro_2977c;
  uVar4 = (param_1 & 0xff) - (uVar1 + 4) & 0xff;
  if (2 < uVar4) {
    uVar5 = (uint)(byte)shared_ro_2977c[9];
    if (uVar4 - 2 <= uVar5) {
      uVar5 = uVar4 - 2;
    }
    uVar4 = uVar5 & 0xff;
    param_3[0xb] = (char)uVar5 + '\x01';
    if ((byte)puVar2[9] == uVar4) {
      uVar3 = 9;
    }
    else {
      uVar3 = 8;
    }
    param_3[0xc] = uVar3;
    rom_24F9C(param_3 + 0xd,shared_ro_2977c + 10,uVar4);
    *param_2 = *param_2 + (short)uVar4 + 2;
  }
  return;
}

/* ==========================================================================
 * ble_sub_29490   @ 0x00029490   (38 bytes)
 * called by : app_ble_address_update, app_env, app_mutli_link_change, disconnect, force_ble_sleep_2
 * calls     : rom_06EF4, rom_06F26
 */

void ble_sub_29490(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(shared_ro_297c8 + 1,7,3,2);
  puVar1 = shared_ro_2977c;
  *puVar2 = 0xa5;
  puVar2[1] = puVar1[3];
  rom_06F26();
  puVar1[4] = 7;
  puVar1[5] = 0xa5;
  return;
}

/* ==========================================================================
 * adv_data   @ 0x000294b6   (66 bytes)
 * called by : ble_sub_2d53c
 * calls     : dbg_printf_2, limit, rom_06EF4, rom_06F26
 * string    : "adv_data--------"
 */

void adv_data(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)rom_06EF4(shared_ro_297c8 + 5,7,3,0x23);
  puVar1 = shared_ro_2977c;
  *puVar2 = 0xa9;
  puVar2[1] = puVar1[3];
  *(undefined2 *)(puVar2 + 2) = 0;
  limit(0x1f,puVar2 + 2,puVar2 + 4);
  dbg_printf_2(str_adv_data,puVar2 + 4,0x1f);
  rom_06F26(puVar2);
  puVar1[4] = 2;
  puVar1[5] = 0xa9;
  return;
}

/* ==========================================================================
 * ble_sub_29530   @ 0x00029530   (78 bytes)
 * called by : rwip_driver_init
 * calls     : ble_sub_29392, ble_sub_2bef8, ble_sub_2c044, ble_sub_2c378, ble_sub_2ca10, app_ancsc_init, ... (+6 more)
 */

void ble_sub_29530(void)

{
  undefined1 *puVar1;
  
  rom_24FEC(shared_ro_2977c,0x46);
  rom_07108(3,ble_ro_297f0);
  rom_07180(3,0);
  ble_sub_29392();
  app_sec_init();
  ble_sub_2c044();
  ble_sub_2c378();
  ble_sub_2bef8();
  app_ancsc_init();
  ble_sub_2ca10();
  puVar1 = (undefined1 *)rom_06EF4(shared_ro_297c8 + -0x9f,7,3,1);
  *puVar1 = 1;
  rom_06F26();
  return;
}

/* ==========================================================================
 * appm_add_svc   @ 0x0002957e   (44 bytes)
 * called by : ble_sub_2d53c
 * calls     : dbg_printf
 * string    : "appm_add_svc"
 * string    : "%s more_svc:%d\r\n"
 */

bool appm_add_svc(void)

{
  undefined *puVar1;
  bool bVar2;
  
  puVar1 = shared_ro_2977c;
  bVar2 = (byte)shared_ro_2977c[7] != 6;
  if (bVar2) {
    (**(code **)(ble_ro_297f4 + (uint)(byte)shared_ro_2977c[7] * 4))();
    puVar1[7] = puVar1[7] + '\x01';
  }
  dbg_printf(str_s_more_svc_d,str_appm_add_svc,bVar2);
  return bVar2;
}

/* ==========================================================================
 * ble_sub_295aa   @ 0x000295aa   (36 bytes)
 * called by : Disconnected, ble_sub_2b8a2, ble_sub_2d53c, app_env, app_mutli_link_change, disconnect, ... (+2 more)
 * calls     : rom_06EF4, rom_06F26
 */

void ble_sub_295aa(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(shared_ro_297c8 + 99,(uint)(byte)shared_ro_2977c[2] * 0x100 + 8,3,2);
  *puVar1 = 1;
  puVar1[1] = 0x13;
  rom_06F26();
  return;
}

/* ==========================================================================
 * appm_create_advertising   @ 0x000295ce   (198 bytes)
 * called by : ble_sub_2d53c, adv_state
 * calls     : ble_sub_3e552, dbg_printf, dbg_printf_2, rom_06EF4, rom_06F26, rom_24F9C
 * string    : "disc_mode  =%x,\r\n"
 * string    : "appm_create_advertising direct\r\n"
 * string    : "peeraddr2:"
 * string    : "appm_create_advertising nonderect \r\n"
 */

void appm_create_advertising(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 *local_1c;
  
  puVar1 = shared_ro_2977c;
  if (shared_ro_2977c[4] == '\0') {
    puVar2 = (undefined1 *)rom_06EF4(0xda0,7,3,0x2c);
    *puVar2 = 0xa0;
    puVar2[1] = 0;
    puVar2[4] = 0;
    *(undefined2 *)(puVar2 + 6) = 3;
    puVar2[9] = 0;
    puVar2[0x1c] = 7;
    puVar2[0x1d] = 1;
    if ((*(uint *)ble_ro_297a0 & 1) == 0) {
      puVar2[5] = 0;
    }
    else {
      puVar2[5] = 1;
    }
    *(undefined4 *)(puVar2 + 0x14) = 0x20;
    *(undefined4 *)(puVar2 + 0x18) = 0x20;
    dbg_printf(str_disc_mode_x,puVar2[5]);
    if (*(int *)ble_ro_297a0 << 0x1d < 0) {
      local_20[0] = 7;
      dbg_printf(str_appm_create_advertising_direct);
      if (*ble_ro_29778 == '\x02') {
        uVar3 = 0x3c;
      }
      else {
        uVar3 = 0x3b;
      }
      ble_sub_3e552(uVar3,local_20,auStack_28);
      local_1c = puVar2 + 10;
      rom_24F9C(local_1c,auStack_28,7);
      *(undefined4 *)(puVar2 + 0x14) = 0x20;
      *(undefined4 *)(puVar2 + 0x18) = 0x20;
      dbg_printf_2(str_peeraddr2,local_1c,6);
      dbg_printf_2(str_peeraddr2,auStack_28,6);
      puVar1[6] = 1;
      *(undefined2 *)(puVar2 + 6) = 5;
    }
    else {
      dbg_printf(str_appm_create_advertising_nonderect);
      puVar1[6] = 0;
    }
    rom_06F26(puVar2);
    puVar1[4] = 1;
    puVar1[5] = 0xa0;
  }
  return;
}

/* ==========================================================================
 * appm_delete_advertising   @ 0x00029694   (36 bytes)
 * called by : ble_sub_2d53c, app_ble_address_update, app_env
 * calls     : dbg_printf, rom_06EF4, rom_06F26
 * string    : "appm_delete_advertising \r\n"
 */

void appm_delete_advertising(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)rom_06EF4(shared_ro_297c8 + 2,7,3,2);
  *puVar1 = 0xa8;
  rom_06F26();
  dbg_printf(str_appm_delete_advertising);
  shared_ro_2977c[5] = 0xa8;
  return;
}

/* ==========================================================================
 * adv_state   @ 0x000296b8   (42 bytes)
 * calls     : usb_sub_317c2, appm_create_advertising, dbg_printf, rom_25078
 * string    : "adv_state:%x\r\n"
 */

void adv_state(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint extraout_r1;
  
  dbg_printf(str_adv_state_x,shared_ro_2977c[4]);
  usb_sub_317c2(2);
  rom_25078();
  appm_create_advertising(extraout_r1 >> 0xc,param_3 >> 0xc);
  return;
}

/* ==========================================================================
 * appm_update_param   @ 0x00029704   (96 bytes)
 * called by : ImgHdr_2, update
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
  
  puVar2 = (undefined1 *)rom_06EF4(shared_ro_297c8 + 0x6d,(uint)(byte)shared_ro_2977c[2] * 0x100 + 8,3,0xe);
  dbg_printf(str_s,str_appm_update_param);
  *puVar2 = 9;
  *(undefined2 *)(puVar2 + 2) = *param_1;
  *(undefined2 *)(puVar2 + 4) = param_1[1];
  *(undefined2 *)(puVar2 + 6) = param_1[2];
  *(undefined2 *)(puVar2 + 8) = param_1[3];
  dbg_printf(str_intv_min_d_d,*param_1,param_1[1]);
  dbg_printf(str_con_latency_d,param_1[2]);
  dbg_printf(str_time_out_d,param_1[3]);
  uVar1 = (undefined2)ble_ro_298e4;
  *(undefined2 *)(puVar2 + 10) = uVar1;
  *(undefined2 *)(puVar2 + 0xc) = uVar1;
  rom_06F26(puVar2);
  return;
}

/* ==========================================================================
 * app_ble_addr_tabl_init   @ 0x000298e8   (160 bytes)
 * called by : force_pair_en
 * calls     : ble_sub_3e552, ble_sub_3e5f0, dbg_printf, dbg_printf_2, rom_24F9C
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
  dbg_printf(shared_ro_29cdc,ble_ro_29cd8);
  ble_sub_3e552(0xa5,&local_10,&local_18);
  if ((char)local_18 != 'U') {
    local_18 = CONCAT31(local_18._1_3_,0x55);
    rom_24F9C((int)&local_18 + 1,ble_ro_29ce0,6);
    ble_sub_3e5f0(0xa5,7,&local_18);
    dbg_printf_2(str_wr_ble_1_addr,&local_18,7);
    local_14 = CONCAT31(local_14._1_3_,(char)local_14 + '\x01');
    ble_sub_3e5f0(0xa6,7,&local_18);
    dbg_printf_2(str_wr_ble_2_addr,&local_18,7);
    return;
  }
  if (*ble_ro_29d0c == '\x02') {
    ble_sub_3e552(0xa6,&local_10,&local_18);
    pcVar1 = str_NVDS_TAG_BLE_ADDRESS1;
  }
  else {
    ble_sub_3e552(0xa5,&local_10,&local_18);
    pcVar1 = str_NVDS_TAG_BLE_ADDRESS0;
  }
  dbg_printf_2(pcVar1,&local_18,7);
  rom_24F9C(ble_ro_29ce0,(int)&local_18 + 1,6);
  return;
}

/* ==========================================================================
 * save   @ 0x000299cc   (56 bytes)
 * calls     : ble_sub_3e5f0, dbg_printf_2, rom_24F9C
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
  rom_24F9C(&uStack_17,ble_ro_29ce0,6);
  if (param_1 == 1) {
    uVar1 = 0xa5;
  }
  else {
    uVar1 = 0xa6;
  }
  ble_sub_3e5f0(uVar1,7,&local_18);
  dbg_printf_2(str_save_co_default_bdaddr,ble_ro_29ce0,6);
  return;
}

/* ==========================================================================
 * ble_sub_29a42   @ 0x00029a42   (26 bytes)
 * called by : app_ble_address_update, app_env
 * calls     : rom_24F9C
 */

void ble_sub_29a42(undefined4 param_1)

{
  rom_24F9C(ble_ro_29dcc,param_1,6);
  rom_24F9C(ble_ro_29dd0,param_1,6);
  return;
}

/* ==========================================================================
 * app_env   @ 0x00029a5c   (84 bytes)
 * called by : app_ble_to_ble_mode
 * calls     : ble_sub_29490, ble_sub_295aa, ble_sub_29a42, appm_delete_advertising, dbg_printf, rom_071EA
 * string    : "appm disconn..................\r\n"
 * string    : "app_env.adv_state = %x \r\n"
 */

void app_env(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  ble_sub_29a42(ble_ro_29ce0);
  iVar3 = rom_071EA(3);
  puVar2 = shared_ro_29dd4;
  puVar1 = shared_ro_29d74;
  if ((iVar3 == 3) && (-1 < *(int *)shared_ro_29dd4 << 0x17)) {
    dbg_printf(str_appm_disconn);
    ble_sub_295aa();
  }
  else {
    dbg_printf(str_app_env_adv_state_x,shared_ro_29d74[-0x2a]);
    if (puVar1[-0x2a] == '\x06') {
      ble_sub_29490();
      *ble_ro_29e18 = 1;
    }
    else {
      appm_delete_advertising();
    }
  }
  *(uint *)puVar2 = *(uint *)puVar2 & 0xfffffeff;
  return;
}

/* ==========================================================================
 * app_ble_address_update   @ 0x00029acc   (84 bytes)
 * called by : ble_sub_2b8a2
 * calls     : ble_sub_29490, flash_sub_29988, ble_sub_29a42, rf24_sub_29ab0, appm_delete_advertising, dbg_printf, ... (+2 more)
 * string    : "app_ble_address_update"
 * string    : "app_sec_env.key_index = %x \r\n"
 * string    : "update ble addr:"
 */

void app_ble_address_update(void)

{
  undefined *puVar1;
  
  dbg_printf(&ble_ro_29e1c,str_app_ble_address_update);
  puVar1 = ble_ro_29e24;
  rf24_sub_29ab0(*ble_ro_29e24);
  dbg_printf(str_app_sec_env_key_index_x,shared_ro_29d70[6]);
  flash_sub_29988(*puVar1);
  rom_11550();
  ble_sub_29a42(ble_ro_29ce0);
  dbg_printf_2(str_update_ble_addr,ble_ro_29ce0,6);
  if (shared_ro_29d74[-0x2a] == '\x06') {
    ble_sub_29490();
    *ble_ro_29e18 = 1;
  }
  else {
    appm_delete_advertising();
  }
  return;
}

/* ==========================================================================
 * sys_flag   @ 0x00029b20   (264 bytes)
 * called by : app_ble_to_ble_mode, force_pair_en
 * calls     : ble_sub_3e552, dbg_printf
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
  undefined1 uVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  dbg_printf(shared_ro_29cdc,str_appm_get_peer_type);
  puVar4 = shared_ro_29dd4;
  *(uint *)shared_ro_29dd4 = *(uint *)shared_ro_29dd4 & 0xfffffffa;
  puVar3 = shared_ro_29d70;
  local_20 = CONCAT31(local_20._1_3_,1);
  if (*ble_ro_29d0c == '\x01') {
    iVar5 = ble_sub_3e552(0x35,&local_20,&local_1c);
    if (iVar5 == 0) {
      if ((local_1c & 0xff) < 2) {
        if ((local_1c & 0xff) == 0) goto LAB_00029b7a;
        bVar2 = true;
      }
      else {
        local_1c = local_1c & 0xffffff00;
LAB_00029b7a:
        bVar2 = false;
      }
      *puVar3 = bVar2;
      if (!bVar2) {
        *(uint *)puVar4 = *(uint *)puVar4 | 1;
        dbg_printf(str_sys_flag_x,*(undefined4 *)puVar4);
      }
    }
    local_20 = CONCAT31(local_20._1_3_,1);
    if (((*puVar3 != '\0') && (iVar5 = ble_sub_3e552(0xa2,&local_20,&local_18), iVar5 == 0)) &&
       ((local_18 & 0xff) == 0)) {
      *(uint *)puVar4 = *(uint *)puVar4 | 4;
      dbg_printf(str_peer_addr_type0_x);
    }
    uVar1 = *puVar3;
    pcVar6 = str_bond0_x;
    goto LAB_00029c22;
  }
  iVar5 = ble_sub_3e552(0x36,&local_20,&local_1c);
  if (iVar5 == 0) {
    if ((local_1c & 0xff) < 2) {
      if ((local_1c & 0xff) == 0) goto LAB_00029bda;
      bVar2 = true;
    }
    else {
      local_1c = local_1c & 0xffffff00;
LAB_00029bda:
      bVar2 = false;
    }
    puVar3[1] = bVar2;
    if (!bVar2) {
      *(uint *)puVar4 = *(uint *)puVar4 | 1;
      dbg_printf(str_sys_flag_x,*(undefined4 *)puVar4);
    }
  }
  local_20 = CONCAT31(local_20._1_3_,1);
  if (((puVar3[1] != '\0') && (iVar5 = ble_sub_3e552(0xa3,&local_20,&local_18), iVar5 == 0)) &&
     ((local_18 & 0xff) == 0)) {
    *(uint *)puVar4 = *(uint *)puVar4 | 4;
    dbg_printf(str_peer_addr_type1_is_PUBLIC_ADDR_x);
  }
  uVar1 = puVar3[1];
  pcVar6 = str_bond1_x;
LAB_00029c22:
  dbg_printf(pcVar6,uVar1);
  return;
}

/* ==========================================================================
 * app_ble_to_ble_mode   @ 0x00029c28   (68 bytes)
 * called by : switch_rf_mode_loop
 * calls     : flash_sub_29988, flash_sub_29a04, rf24_sub_29ab0, KEY_piaring_cnt, app_env, dbg_printf, ... (+1 more)
 * string    : "app_ble_to_ble_mode"
 */

bool app_ble_to_ble_mode(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  dbg_printf(&ble_ro_29e1c,str_app_ble_to_ble_mode);
  puVar1 = shared_ro_29ecc;
  puVar2 = ble_ro_29ec8;
  *ble_ro_29ec8 = 0;
  puVar1[9] = 2;
  KEY_piaring_cnt();
  puVar1 = ble_ro_29d0c;
  rf24_sub_29ab0(*ble_ro_29d0c);
  flash_sub_29988(*puVar1);
  flash_sub_29a04();
  sys_flag();
  app_env();
  return 5 < (byte)*puVar2;
}

/* ==========================================================================
 * force   @ 0x0002a078   (50 bytes)
 * called by : force_pair_en
 * calls     : ble_sub_3e552, dbg_printf
 * string    : "force pair mode : %d \r\n"
 */

uint force(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  local_10 = param_3 & 0xffffff00;
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),1);
  ble_sub_3e552(0x39,&local_c,&local_10);
  if (1 < (byte)local_10) {
    local_10 = local_10 & 0xffffff00;
  }
  dbg_printf(str_force_pair_mode_d,local_10 & 0xff);
  return local_10 & 0xff;
}

/* ==========================================================================
 * ble_sub_2a0aa   @ 0x0002a0aa   (22 bytes)
 * calls     : ble_sub_3e5f0
 */

void ble_sub_2a0aa(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  ble_sub_3e5f0(uVar1,2,&uStack_c,param_4,param_1);
  return;
}

/* ==========================================================================
 * ble_sub_2a0c0   @ 0x0002a0c0   (44 bytes)
 * calls     : ble_sub_3e552
 */

uint ble_sub_2a0c0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

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
  ble_sub_3e552(uVar1,&local_c,&local_10);
  return local_10 & 0xff;
}

/* ==========================================================================
 * BLE_PAIR   @ 0x0002a152   (484 bytes)
 * called by : ble_sub_28c66
 * calls     : ble_sub_2cbda, ble_sub_3b538, flash_sub_3c8b6, flash_sub_3cf7c, OLED_Clear, app_start_led, ... (+3 more)
 * string    : "app adv timer run.... %d\r\n"
 * string    : "BLE_PAIR OLED_Init 1\r\n"
 * string    : "start reconnect advertising = %d \r\n"
 * string    : "start nondir advertising = %d \r\n"
 * string    : "BLE_PAIR BLE_RECONNECTED OLED_Init 2\r\n"
 */

void BLE_PAIR(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  ushort uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  puVar1 = shared_ro_2a300;
  if ((*shared_ro_2a300 & 1) != 0) {
    ble_sub_3b538(ble_ro_2a43c);
  }
  puVar3 = ble_ro_2a444;
  puVar2 = shared_ro_2a430;
  if (*ble_ro_2a440 == '\0') {
    if ((*puVar1 & 1) != 0) {
      if (ble_ro_2a448[4] == '\x06') {
        *puVar1 = *puVar1 & 0xfe;
        dbg_printf(str_app_adv_timer_run_d,ble_ro_2a44c);
        puVar2[-0xb] = 1;
        *ble_ro_2a46c = 0;
        puVar4 = ble_ro_2a470;
        puVar2[-0xf] = 0;
        *puVar4 = 0;
        *shared_ro_2a388 = 0;
        app_start_led();
        puVar4 = ble_ro_2a474;
        *(uint *)ble_ro_2a474 = *(uint *)ble_ro_2a474 & 0xfffffdff;
        *(uint *)puVar4 = *(uint *)puVar4 | 1;
        rom_073D4(shared_ro_2a438 + 7,3);
        rom_073D4(shared_ro_2a438 + 4,3);
        rom_073D4(shared_ro_2a438 + 5,3);
        rom_073D4(shared_ro_2a438 + 8,3);
        uVar5 = (ushort)((byte)puVar3[0xb] >> 4) << 4 | (ushort)((byte)puVar3[0xc] >> 4);
        if (uVar5 == 0) {
          uVar5 = 1;
        }
        *(ushort *)ble_ro_2a478 = uVar5 * 0xef + (ushort)(byte)puVar3[0x10] * 0x7e;
        rom_07342(shared_ro_2a438 + 6,3,0x19);
        rom_07342(shared_ro_2a438 + 2,3,ble_ro_2a44c);
      }
      flash_sub_3c8b6();
      OLED_Clear();
      dbg_printf(str_BLE_PAIR_OLED_Init_1);
      flash_sub_3cf7c();
    }
    if (((*ble_ro_2a494 == '\0') && ((int)((uint)(byte)*puVar1 << 0x1e) < 0)) && (ble_ro_2a448[4] == '\x06')
       ) {
      *puVar1 = *puVar1 & 0xfd;
      *(uint *)ble_ro_2a474 = *(uint *)ble_ro_2a474 & 0xfffffdff;
      iVar6 = shared_ro_2a438;
      iVar8 = shared_ro_2a438 + 4;
      rom_073D4(iVar8,3);
      rom_073D4(iVar6 + 2,3);
      rom_073D4(iVar6 + 7,3);
      rom_073D4(iVar6 + 5,3);
      rom_073D4(iVar6 + 8,3);
      uVar5 = (ushort)((byte)puVar3[0xb] >> 4) << 4 | (ushort)((byte)puVar3[0xc] >> 4);
      if (uVar5 == 0) {
        uVar5 = 1;
      }
      *(ushort *)ble_ro_2a478 = uVar5 * 0xef + (ushort)(byte)puVar3[0x10] * 0x7e;
      rom_07342(shared_ro_2a438 + 6,3,0x19);
      iVar6 = ble_sub_2cbda();
      puVar3 = ble_ro_2a7d0;
      puVar1 = ble_ro_2a46c;
      if (iVar6 == 0) {
        puVar2[-0xf] = 0;
        *puVar3 = 0;
        *ble_ro_2a7d4 = 0;
        puVar2[-0xb] = 1;
        *ble_ro_2a7d8 = 0;
        uVar7 = ble_ro_2a7dc;
        rom_07342(ble_ro_2a7e0,3,ble_ro_2a7dc);
        dbg_printf(str_start_nondir_advertising_d,uVar7);
        app_start_led();
      }
      else {
        puVar2[-0xb] = 2;
        *puVar1 = 1;
        *ble_ro_2a470 = 0;
        *shared_ro_2a388 = 0;
        app_start_led();
        uVar7 = shared_ro_2a7cc;
        if (shared_ro_2a430[3] != '\x14') {
          uVar7 = 1000;
        }
        rom_07342(iVar8,3,uVar7);
        dbg_printf(str_start_reconnect_advertising_d,uVar7);
      }
      flash_sub_3c8b6();
      OLED_Clear();
      dbg_printf(str_BLE_PAIR_BLE_RECONNECTED_OLED_Init_2);
      flash_sub_3cf7c();
    }
  }
  return;
}

/* ==========================================================================
 * app_bond_status_initial   @ 0x0002a4e2   (152 bytes)
 * called by : force_pair_en
 * calls     : ble_sub_3e552, ble_sub_3e5f0, dbg_printf
 * string    : "app_bond_status_initial"
 * string    : "%s \r\n"
 * string    : "write error  NVDS_TAG_PERIPH_BONDED0= %x\r\n"
 * string    : "app_bond_status_initial  bonded0=%x, bonded1========%x\r\n"
 */

void app_bond_status_initial(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  uint local_18;
  undefined4 local_14;
  
  local_18 = param_3 & 0xffffff00;
  local_14 = param_4;
  dbg_printf(ble_ro_2a834,ble_ro_2a830);
  local_14 = CONCAT31(local_14._1_3_,1);
  iVar2 = ble_sub_3e552(0x35,&local_14,&local_18);
  if ((iVar2 != 0) || (1 < (byte)local_18)) {
    local_18 = local_18 & 0xffffff00;
    iVar2 = ble_sub_3e5f0(0x35,1,&local_18);
    if (iVar2 != 0) {
      dbg_printf(str_write_error_NVDS_TAG_PERIPH_BONDED0_x,local_18 & 0xff);
    }
  }
  puVar1 = ble_ro_2a864;
  *ble_ro_2a864 = (byte)local_18 != '\0';
  local_14 = CONCAT31(local_14._1_3_,1);
  iVar2 = ble_sub_3e552(0x36,&local_14,&local_18);
  if ((iVar2 != 0) || (1 < (byte)local_18)) {
    local_18 = local_18 & 0xffffff00;
    ble_sub_3e5f0(0x36,1,&local_18);
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
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = ble_ro_2a8a4;
  dbg_printf(str_s_ble_pairing_successed_cfm_d,str_app_ble_pair_successed,ble_ro_2a8a4[7]);
  puVar2 = ble_ro_2a8cc;
  if (puVar1[7] != '\0') {
    puVar1[7] = 0;
    puVar1[3] = 0;
    *(uint *)puVar2 = *(uint *)puVar2 | 0x200;
    puVar1[2] = 0;
    if (6 < (byte)puVar1[8]) {
      rom_07342(ble_ro_2a7e0 + -7,3,2);
      dbg_printf(str_APP_PARAM_UPDATE_REQ_IND_2_start_update_para);
    }
    puVar1[6] = 1;
    rom_07342(ble_ro_2a7e0 + 6,3,300);
    dbg_printf(str_pair_successed_start_led_on);
    if (ble_ro_2a8a4[0x10] == '\0') {
      app_start_led();
    }
  }
  return;
}

/* ==========================================================================
 * ble_sub_2a5e4   @ 0x0002a5e4   (20 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void ble_sub_2a5e4(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar1 = ble_ro_2a8a4;
  puVar2 = ble_ro_2a8a4 + 0x10;
  ble_ro_2a8a4[0x12] = 0;
  *puVar2 = 0;
  puVar1[0x13] = 0x14;
  *puVar1 = 0;
  return;
}

/* ==========================================================================
 * ble_sub_2a5f8   @ 0x0002a5f8   (28 bytes)
 * called by : there
 */

short ble_sub_2a5f8(int param_1)

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
 * called by : ble_sub_28c66
 * calls     : ble_sub_2a5f8, rf24_sub_3b130, dbg_printf
 * string    : "ble lost pkt sum:%d \r\n"
 * string    : "there is a serious lost pkt occur,need execute cpu reset!!!!!!!!\r\n"
 */

void there(void)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  
  puVar5 = ble_ro_2a92c;
  puVar4 = ble_ro_2a8a4;
  sVar3 = *(short *)ble_ro_2a928;
  if (sVar3 != 0) {
    if (sVar3 != *(short *)(ble_ro_2a8a4 + 0xe)) {
      bVar1 = ble_ro_2a8a4[0xd];
      if (bVar1 < 5) {
        *(short *)(ble_ro_2a92c + (uint)bVar1 * 2 + 4) = sVar3;
        puVar4[0xd] = bVar1 + 1;
      }
      *(short *)(puVar4 + 0xe) = sVar3;
    }
    if (4 < (byte)puVar4[0xd]) {
      uVar6 = ble_sub_2a5f8(puVar5 + 4);
      if (0x16 < uVar6) {
        dbg_printf(str_ble_lost_pkt_sum_d,uVar6);
        *puVar5 = 1;
        cVar2 = puVar5[1];
        puVar5[1] = cVar2 + 1U;
        if (4 < (byte)(cVar2 + 1U)) {
          dbg_printf(ble_ro_2a948);
          rf24_sub_3b130();
        }
      }
      puVar4[0xd] = 0;
    }
  }
  return;
}

/* ==========================================================================
 * ble_sub_2a674   @ 0x0002a674   (42 bytes)
 * called by : ble_sub_2f31c
 * calls     : dbg_printf
 * string    : "ble lost pkt accumulate free\r\n"
 */

void ble_sub_2a674(void)

{
  short sVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = shared_ro_2a94c;
  puVar2 = ble_ro_2a92c;
  if (*ble_ro_2a92c != '\0') {
    sVar1 = *(short *)(ble_ro_2a92c + 2);
    *(ushort *)(ble_ro_2a92c + 2) = sVar1 + 1U;
    if (uVar3 < (ushort)(sVar1 + 1U)) {
      *(undefined2 *)(puVar2 + 2) = 0;
      *puVar2 = 0;
      puVar2[1] = 0;
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
  undefined *puVar1;
  ushort uVar2;
  
  puVar1 = ble_ro_2a8a4;
  if ((*ble_ro_2a9a4 != '\0') && (*ble_ro_2a9a8 == '\0')) {
    uVar2 = (ushort)((byte)ble_ro_2a9ac[0xb] >> 4) << 4 | (ushort)((byte)ble_ro_2a9ac[0xc] >> 4);
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    if ((((ushort)(uVar2 * 0xef) < *(ushort *)ble_ro_2a9b0) && (*ble_ro_2a9b4 != '\0')) &&
       (ble_ro_2a8a4[10] == '\0')) {
      ble_ro_2a8a4[10] = 1;
      puVar1[0xb] = 0;
      puVar1[0xc] = 0;
      dbg_printf(ble_ro_2a834,str_ble_alert_led_start);
      rom_07342(ble_ro_2a7e0 + -1,3,10);
    }
  }
  return;
}

/* ==========================================================================
 * ble_alert_led_stop   @ 0x0002a770   (28 bytes)
 * called by : Disconnected, led_sub_328c2, app_mutli_link_change, disconnect, f_usb_isConnected
 * calls     : dbg_printf, rom_073D4
 * string    : "ble_alert_led_stop\r\n"
 */

void ble_alert_led_stop(void)

{
  undefined *puVar1;
  
  puVar1 = ble_ro_2a8a4;
  ble_ro_2a8a4[0xc] = 0;
  puVar1[10] = 0;
  rom_073D4(ble_ro_2a7e0 + -1,3);
  dbg_printf(str_ble_alert_led_stop);
  return;
}

/* ==========================================================================
 * ble_sub_2a78c   @ 0x0002a78c   (26 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : reset
 */

void ble_sub_2a78c(void)

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
  ble_ro_2a8a4[9] = uVar2;
  return;
}

/* ==========================================================================
 * ble_sub_2aa5c   @ 0x0002aa5c   (276 bytes)
 * called by : ble_sub_28c66, system_mode
 * calls     : power_sub_2aa44, ble_sub_319c0, ble_sub_31b3e, OLED_Init
 */

void ble_sub_2aa5c(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined1 uVar6;
  int iVar7;
  byte bVar8;
  
  puVar4 = ble_ro_2adc4;
  puVar3 = ble_ro_2adc0;
  puVar2 = ble_ro_2adbc;
  if (*ble_ro_2adb8 == '\0') {
    return;
  }
  if (*ble_ro_2adbc == '\f') {
    *ble_ro_2adbc = 0xb;
    if ((puVar3[4] != '\0') && (*puVar4 == '\x10')) {
      ble_sub_319c0();
    }
    if ((puVar3[7] != '\0') && (*puVar4 == '\x11')) {
      ble_sub_319c0();
    }
    *puVar4 = 0;
  }
  iVar7 = power_sub_2aa44();
  if (iVar7 == 0x40) {
    if (*ble_ro_2add4 == -0x40) {
      uVar6 = 0x81;
    }
    else {
      if (*ble_ro_2add4 != '\0') goto LAB_0002ab6a;
      uVar6 = 0x82;
    }
  }
  else {
    if (iVar7 != 0x80) {
      bVar1 = *ble_ro_2adc8;
      if (-1 < (int)((uint)bVar1 << 0x18)) goto LAB_0002ab6a;
      bVar8 = bVar1 & 0x7f;
      *ble_ro_2adc8 = bVar8;
      puVar5 = ble_ro_2add0;
      if ((bVar1 & 0x7f) == 0) {
        if (iVar7 != 0xc0) goto LAB_0002ab6a;
LAB_0002ab06:
        if (puVar3[4] == '\0') {
          *ble_ro_2adcc = *ble_ro_2adcc + '\x01';
          *puVar5 = 1;
        }
        else {
          ble_sub_31b3e(0x10);
        }
        *(undefined2 *)ble_ro_2add8 = 400;
        *ble_ro_2addc = 0xf;
        *puVar2 = 0xf;
        uVar6 = 0x10;
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
        if (puVar3[7] == '\0') {
          *ble_ro_2adcc = *ble_ro_2adcc + -1;
          *puVar5 = 1;
        }
        else {
          ble_sub_31b3e(0x11);
        }
        *(undefined2 *)ble_ro_2add8 = 400;
        *ble_ro_2addc = 0xf;
        *puVar2 = 0xf;
        uVar6 = 0x11;
      }
      *puVar4 = uVar6;
      OLED_Init();
      goto LAB_0002ab6a;
    }
    if (*ble_ro_2add4 == -0x40) {
      uVar6 = 0x83;
    }
    else {
      if (*ble_ro_2add4 != '\0') goto LAB_0002ab6a;
      uVar6 = 0x80;
    }
  }
  *ble_ro_2adc8 = uVar6;
LAB_0002ab6a:
  *ble_ro_2add4 = (char)iVar7;
  return;
}

/* ==========================================================================
 * ble_sub_2ab70   @ 0x0002ab70   (56 bytes)
 * called by : ble_sub_2ac0e
 */

undefined4 ble_sub_2ab70(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  
  uVar4 = 0;
  bVar3 = 0;
  while( true ) {
    pbVar1 = ble_ro_2ade0 + uVar4;
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
 * ble_sub_2abba   @ 0x0002abba   (14 bytes)
 * called by : ble_sub_2ac0e
 */

void ble_sub_2abba(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_2adb4;
  *(undefined4 *)(shared_ro_2adb4 + 0x20) = 0x3c;
  *(undefined4 *)(puVar1 + 0x24) = 0x3c;
  *(undefined4 *)(puVar1 + 0x30) = 0xc;
  return;
}

/* ==========================================================================
 * ble_sub_2abd4   @ 0x0002abd4   (58 bytes)
 * called by : ble_sub_2ac0e, power_sub_2b128, get_scan_Rvalue
 * calls     : rf24_sub_31784
 */

byte ble_sub_2abd4(void)

{
  byte bVar1;
  
  rf24_sub_31784(1);
  bVar1 = (*(uint *)(shared_ro_2adb4 + -0x3c) & 1) == 0;
  if ((*(uint *)(shared_ro_2adb4 + -0x38) & 1) == 0) {
    bVar1 = bVar1 | 2;
  }
  if ((*(uint *)(shared_ro_2adb4 + -0x34) & 1) == 0) {
    bVar1 = bVar1 | 4;
  }
  if ((*(uint *)(shared_ro_2adb4 + 0x3c) & 1) == 0) {
    bVar1 = bVar1 | 8;
  }
  return bVar1;
}

/* ==========================================================================
 * ble_sub_2ac0e   @ 0x0002ac0e   (210 bytes)
 * called by : TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, enter_BLE_normal_app_mode, system_mode
 * calls     : ble_sub_2ab70, ble_sub_2abba, ble_sub_2abd4, OLED_Init
 */

void ble_sub_2ac0e(void)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined1 uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  
  ble_sub_2abba();
  puVar4 = shared_ro_2ade4;
  puVar3 = ble_ro_2ade0;
  uVar11 = 0;
  do {
    **(undefined4 **)(puVar4 + uVar11 * 4) = 0;
    uVar8 = ble_sub_2abd4();
    puVar3[uVar11] = uVar8;
    **(undefined4 **)(puVar4 + uVar11 * 4) = 0xc;
    puVar7 = ble_ro_2adf4;
    puVar6 = ble_ro_2adf0;
    puVar5 = ble_ro_2adec;
    puVar2 = ble_ro_2adc0;
    uVar11 = uVar11 + 1 & 0xff;
  } while (uVar11 < 3);
  uVar12 = (ushort)(byte)puVar3[1] << 4 | (ushort)(byte)puVar3[2] << 8 | (ushort)(byte)*puVar3;
  if (uVar12 == *(ushort *)ble_ro_2ade8) {
    if (*ble_ro_2adf4 == '\0') {
      cVar1 = *ble_ro_2adec;
      *ble_ro_2adec = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        *puVar7 = 1;
        puVar3 = ble_ro_2addc;
        cVar1 = *puVar6;
        if ((((cVar1 == '\x01') || (cVar1 == '\x02')) && (*ble_ro_2adf8 == '\0')) ||
           (bVar9 = puVar2[-0x2f], bVar9 < 3)) {
          bVar9 = 2;
        }
        *puVar5 = bVar9;
        *puVar3 = 0xf;
        OLED_Init();
        puVar3 = ble_ro_2ae00;
        *(ushort *)ble_ro_2adfc = uVar12;
        *puVar3 = 1;
      }
      goto LAB_0002acd6;
    }
  }
  else {
    OLED_Init();
    iVar10 = ble_sub_2ab70();
    puVar3 = ble_ro_2adf4;
    if (iVar10 != 0) goto LAB_0002acd6;
    *(ushort *)ble_ro_2ade8 = uVar12;
    *puVar3 = 0;
  }
  cVar1 = *puVar6;
  if ((((cVar1 == '\x01') || (cVar1 == '\x02')) && (*ble_ro_2adf8 == '\0')) ||
     (bVar9 = puVar2[-0x2f], bVar9 < 3)) {
    bVar9 = 2;
  }
  *puVar5 = bVar9;
LAB_0002acd6:
  *ble_ro_2ae08 = *ble_ro_2ae04;
  return;
}

/* ==========================================================================
 * force_ble_sleep_2   @ 0x0002b292   (162 bytes)
 * called by : force_ble_sleep, set_Update_OLED_2
 * calls     : ble_sub_29490, ble_sub_295aa, power_sub_33cfc, ble_sub_33dc2, ble_sub_39a84, usb_sub_3b528, ... (+6 more)
 * string    : "force_ble_sleep"
 * string    : "%s \r\n"
 * string    : "app_env.adv_state...= %d\r\n"
 * string    : "disconnect start \r\n"
 * string    : "appm  need stop adv...\r\n"
 */

void force_ble_sleep_2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar1 = shared_ro_2b554;
  if (*shared_ro_2b588 == '\0') {
    *shared_ro_2b588 = 1;
    dbg_printf(str_s_3,puVar1 + 0x30);
    set_force_sleep();
    if ((*(uint *)(shared_ro_2b524 + 0x2c) & 1) == 0) {
      ble_sub_33dc2();
    }
    if ((ble_ro_2b58c[8] == '\0') || (*shared_ro_2b590 != '\0')) {
      sensor_pwdn();
      power_sub_33cfc();
    }
    rom_073D4(shared_ro_2b564 + 8,3);
    rom_07342(shared_ro_2b564,3,0x14);
    *(undefined2 *)ble_ro_2b594 = 0;
    ble_sub_39a84(0x32,0,0);
    iVar3 = rom_071EA(3);
    puVar2 = shared_ro_2b59c;
    puVar1 = shared_ro_2b598;
    if (iVar3 == 3) {
      dbg_printf(str_disconnect_start);
      ble_sub_295aa();
      puVar1[9] = 1;
    }
    else {
      dbg_printf(str_app_env_adv_state_d,shared_ro_2b59c[4]);
      if (puVar2[4] == '\x06') {
        dbg_printf(str_appm_need_stop_adv);
        ble_sub_29490();
        puVar1[8] = 0;
      }
    }
    usb_sub_3b528();
  }
  return;
}

/* ==========================================================================
 * ble_sub_2b3ac   @ 0x0002b3ac   (22 bytes)
 * called by : ble_sub_2bdc4, app_mutli_link_change, gpio, tx_failed_cnt
 * calls     : rom_24FEC
 */

void ble_sub_2b3ac(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_2b598;
  shared_ro_2b598[3] = 0;
  puVar1[2] = 0;
  puVar1[1] = 0;
  rom_24FEC(ble_ro_2b668,0x40);
  return;
}

/* ==========================================================================
 * ble_sub_2b4c8   @ 0x0002b4c8   (22 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : usb_sub_2b382, ble_sub_311de, ble_sub_39bc2, KEY_piaring_cnt
 */

void ble_sub_2b4c8(void)

{
  ble_sub_39bc2(ble_ro_2b6c4);
  ble_sub_311de();
  usb_sub_2b382();
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * ble_sub_2b4de   @ 0x0002b4de   (16 bytes)
 * called by : app_mutli_link_change
 * calls     : ble_sub_31406, rom_24FEC
 */

void ble_sub_2b4de(void)

{
  rom_24FEC(ble_ro_2b668,0x40);
  ble_sub_31406();
  return;
}

/* ==========================================================================
 * app_mutli_link_change   @ 0x0002b4ee   (516 bytes)
 * called by : system_mode
 * calls     : ble_sub_29490, ble_sub_295aa, ble_sub_2b3ac, ble_sub_2b4de, ble_sub_312aa, led_sub_32892, ... (+9 more)
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
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 in_r3;
  
  puVar5 = ble_ro_2bb18;
  puVar4 = ble_ro_2b6c8;
  puVar3 = shared_ro_2b598;
  pcVar1 = shared_ro_2b598 + 6;
  cVar2 = *shared_ro_2b54c;
  uVar7 = (uint)(byte)shared_ro_2b598[5];
  if ((*shared_ro_2b51c != '\0') && (*shared_ro_2b520 == '\0')) {
    if (uVar7 < 0xff) {
      uVar7 = uVar7 + 1;
      shared_ro_2b598[5] = (char)uVar7;
    }
    puVar5 = ble_ro_2babc;
    if ((0xfa < (uVar7 & 0xff)) && (*pcVar1 == '\0')) {
      puVar3[6] = 1;
      dbg_printf(str_long_press_Rmode_d_Smode_d,cVar2,*puVar5,0,in_r3);
      if (*ble_ro_2bae8 == '\0') {
        flash_sub_32f16();
        flash_sub_32e82();
        *ble_ro_2bae8 = 1;
        dbg_printf(str_s_RF_MODE_x,ble_ro_2baf0,*ble_ro_2baec);
      }
      ble_alert_led_stop();
      puVar5 = ble_ro_2bb10;
      cVar2 = *ble_ro_2baec;
      if ((cVar2 == *ble_ro_2babc) && (cVar2 == '\0')) {
        puVar3[7] = 0;
        *puVar5 = 0;
        *ble_ro_2bb14 = 1;
      }
      else {
        puVar3[7] = 1;
        if (cVar2 != '\0') {
          ble_sub_2b3ac();
          ble_sub_2b4de();
        }
      }
      puVar3 = ble_ro_2bb04;
      *puVar4 = 0;
      *puVar3 = 0;
      if (*ble_ro_2bb08 != '\0') {
        *ble_ro_2bb0c = 5;
      }
    }
    return;
  }
  if (((cVar2 == '\x01') || (cVar2 == '\x02')) && (*ble_ro_2bb18 == '\0')) {
    if (*pcVar1 == '\0') {
      if ((uVar7 - 5 < 0xc3) && (shared_ro_2b598[0xc] == '\0')) {
        shared_ro_2b598[0xc] = 1;
        if (*ble_ro_2bb38 != '\0') {
          *ble_ro_2bb38 = 0;
          dbg_printf(str_force_pair_en_5_x,0,uVar7 - 5,0,in_r3);
          puVar3[5] = 0;
        }
        *ble_ro_2bb08 = 1;
        dbg_printf(str_s_RF_MODE_x,ble_ro_2baf0,*ble_ro_2baec);
        if (*ble_ro_2bae8 == '\0') {
          flash_sub_32f16();
          flash_sub_32e82();
          *ble_ro_2bae8 = 1;
          power_sub_3bf0a();
        }
        if (((*ble_ro_2baec == '\x01') || (*ble_ro_2baec == '\x02')) && (*puVar5 == '\0')) {
          app_user_ke_timer_stop();
        }
        led_sub_32892();
        ble_alert_led_stop();
        ble_sub_312aa();
        *ble_ro_2bb58 = 0;
        Set_SIMU_mode_LightUp_Led();
        dbg_printf(str_short_press_Rmode_d_Smode_d,*ble_ro_2baec,*ble_ro_2babc);
        if ((*puVar4 == '\0') &&
           (((*ble_ro_2baec == '\x01' || (*ble_ro_2baec == '\x02')) && (*puVar5 == '\0')))) {
          iVar6 = rom_071EA(3);
          if (iVar6 == 3) {
            dbg_printf(str_Disconnected_by_mouse);
            *(uint *)(puVar3 + 0x14) = *(uint *)(puVar3 + 0x14) | 0x100;
            ble_sub_295aa();
          }
          else if (ble_ro_2bb84[4] == '\x06') {
            dbg_printf(ble_ro_2bba4);
            ble_sub_29490();
            puVar3[8] = 0;
          }
        }
        *puVar4 = 0x50;
      }
      if (puVar3[5] != '\0') {
        dbg_printf(str_short_press_time_d);
      }
      if (*ble_ro_2bb04 != '\0') {
        *ble_ro_2bb04 = *ble_ro_2bb04 + -1;
      }
      puVar5 = ble_ro_2bb0c;
      cVar2 = *puVar4;
      if (cVar2 != '\0') {
        *puVar4 = cVar2 + -1;
        *puVar5 = cVar2 + -1;
        dbg_printf(str_time_Simu_mode_d_d,cVar2 + -1,cVar2 + -1);
        if (*puVar4 == '\0') {
          *ble_ro_2bb08 = 0;
          *puVar3 = *puVar3 + '\x01';
          dbg_printf(str_sw_num_d);
          iVar6 = switch_rf_mode_loop();
          if (iVar6 != 0) {
            return;
          }
        }
      }
    }
    else {
      dbg_printf(str_key_free_LongPress);
    }
  }
  puVar4 = ble_ro_2bb34;
  puVar3[6] = 0;
  puVar3[5] = 0;
  *puVar4 = 0;
  puVar3[0xc] = 0;
  return;
}

/* ==========================================================================
 * ble_sub_2b8a2   @ 0x0002b8a2   (148 bytes)
 * called by : ble_sub_3186e, system_mode
 * calls     : ble_sub_295aa, flash_sub_3cf7c, ble_sub_3e5f0, app_24_to_ble_force_pair_reset, app_ble_address_update, dbg_printf, ... (+1 more)
 * string    : "Entry pair mode---RFMODE :[ %x  to  %x ]\r\n"
 */

void ble_sub_2b8a2(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 in_r3;
  
  puVar5 = shared_ro_2bbf0;
  puVar4 = ble_ro_2baec;
  puVar3 = ble_ro_2babc;
  if (shared_ro_2bbf0[7] != '\0') {
    shared_ro_2bbf0[7] = 0;
    dbg_printf(str_Entry_pair_mode_RFMODE_x_to_x,*puVar4,*puVar3,in_r3,in_r3);
    cVar1 = *puVar3;
    if (cVar1 == '\0') {
      *puVar4 = 0;
      *ble_ro_2bb10 = 0;
      *ble_ro_2bb14 = 1;
    }
    else {
      cVar2 = *puVar4;
      *puVar4 = cVar1;
      if (cVar2 == '\0') {
        app_24_to_ble_force_pair_reset();
      }
      else {
        *(uint *)(puVar5 + 0x14) = *(uint *)(puVar5 + 0x14) & 0xfffffffb;
        *(uint *)(puVar5 + 0x14) = *(uint *)(puVar5 + 0x14) | 1;
        iVar6 = rom_071EA(3);
        if (iVar6 == 3) {
          *(uint *)(puVar5 + 0x14) = *(uint *)(puVar5 + 0x14) | 0x40;
          ble_sub_295aa();
        }
        else {
          app_ble_address_update();
        }
        puVar5[4] = puVar5[4] & 0xfd | 1;
      }
    }
    flash_sub_3cf7c();
    if (((*puVar4 == '\x01') || (*puVar4 == '\x02')) && (*ble_ro_2bb18 == '\0')) {
      ble_sub_3e5f0(0x38,1,ble_ro_2baec);
    }
  }
  return;
}

/* ==========================================================================
 * ble_sub_2bdc4   @ 0x0002bdc4   (18 bytes)
 * calls     : ble_sub_2b3ac
 */

void ble_sub_2bdc4(void)

{
  ble_sub_2b3ac();
  *ble_ro_2be78 = 0;
  *ble_ro_2be7c = 0;
  return;
}

/* ==========================================================================
 * ble_sub_2bef8   @ 0x0002bef8   (12 bytes)
 * called by : ble_sub_29530
 */

void ble_sub_2bef8(void)

{
  undefined *puVar1;
  
  puVar1 = ble_ro_2bfbc;
  *ble_ro_2bfbc = 0;
  puVar1[1] = 100;
  return;
}

/* ==========================================================================
 * ble_sub_2bf30   @ 0x0002bf30   (44 bytes)
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26
 */

void ble_sub_2bf30(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  *ble_ro_2bfbc = param_1;
  uVar1 = ble_sub_3ee6e(0x24);
  puVar2 = (undefined1 *)rom_06EF4(&rom_ro_2400,uVar1,3,4);
  *puVar2 = param_1;
  puVar2[1] = 0;
  puVar2[2] = 0x32;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2bf5c   @ 0x0002bf5c   (44 bytes)
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26
 */

void ble_sub_2bf5c(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  *ble_ro_2bfbc = param_1;
  uVar1 = ble_sub_3ee6e(0x24);
  puVar2 = (undefined1 *)rom_06EF4(&rom_ro_2400,uVar1,3,4);
  *puVar2 = param_1;
  puVar2[1] = 1;
  puVar2[2] = 0x32;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2bf88   @ 0x0002bf88   (34 bytes)
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26
 */

void ble_sub_2bf88(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = ble_sub_3ee6e(0x24);
  puVar2 = (undefined1 *)rom_06EF4(ble_ro_2bfc4,uVar1,3,2);
  *puVar2 = 0;
  puVar2[1] = param_1;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2c044   @ 0x0002c044   (2 bytes)
 * called by : ble_sub_29530
 */

void ble_sub_2c044(void)

{
  return;
}

/* ==========================================================================
 * ble_sub_2c158   @ 0x0002c158   (54 bytes)
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26, rom_24F9C
 */

void ble_sub_2c158(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ble_sub_3ee6e(0x47);
  iVar2 = rom_06EF4(shared_ro_2c2d0 + 3,uVar1,param_1 * 0x100 + 3,0x278);
  *(short *)(iVar2 + 2) = (short)param_2;
  rom_24F9C(iVar2 + 4,param_3,param_2);
  rom_06F26(iVar2);
  return;
}

/* ==========================================================================
 * ble_sub_2c378   @ 0x0002c378   (44 bytes)
 * called by : ble_sub_29530
 * calls     : ble_sub_3e552, rom_24FEC
 */

void ble_sub_2c378(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_r3;
  undefined1 local_10;
  undefined3 uStack_f;
  
  _local_10 = CONCAT31((int3)((uint)in_r3 >> 8),2);
  rom_24FEC(shared_ro_2c77c,8);
  puVar1 = shared_ro_2c77c;
  shared_ro_2c77c[6] = 10;
  iVar2 = ble_sub_3e552(0x3a,&local_10,puVar1 + 2);
  if (iVar2 != 0) {
    *(undefined2 *)(puVar1 + 2) = 2000;
  }
  return;
}

/* ==========================================================================
 * hogpd_ctnl_pt_ind_handler   @ 0x0002c5e8   (80 bytes)
 * calls     : ble_sub_3ee6e, dbg_printf, rom_06EF4, rom_06F26
 * string    : "hogpd_ctnl_pt_ind_handler"
 * string    : "%s,(%d) \r\n"
 */

undefined4 hogpd_ctnl_pt_ind_handler(undefined4 param_1,char *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  dbg_printf(str_s_d,str_hogpd_ctnl_pt_ind_handler,0x2e4);
  puVar1 = shared_ro_2c77c;
  if (*param_2 == *shared_ro_2c77c) {
    uVar2 = ble_sub_3ee6e(0x26);
    pcVar3 = (char *)rom_06EF4(shared_ro_2c7d4 + 3,uVar2,3,0x1e);
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
  
  dbg_printf(str_s_d,str_hogpd_ntf_cfg_ind_handler,ble_ro_2c848);
  *ble_ro_2c84c = 1;
  dbg_printf(&ble_ro_2c850);
  if ((uint)(byte)*shared_ro_2c77c == (uint)*param_2) {
    if ((int)((uint)param_2[(uint)*param_2 * 2 + 2] << 0x19) < 0) {
      shared_ro_2c77c[4] = 3;
      bVar1 = *ble_ro_2c864;
      if (bVar1 < 10) {
        bVar1 = bVar1 + 1;
        *ble_ro_2c864 = bVar1;
      }
      if (bVar1 == 6) {
        APP_PARAM_UPDATE_REQ_IND();
      }
    }
    else if (shared_ro_2c77c[4] == '\x03') {
      shared_ro_2c77c[4] = 2;
    }
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_2ca10   @ 0x0002ca10   (8 bytes)
 * called by : ble_sub_29530
 */

void ble_sub_2ca10(void)

{
  *ble_ro_2cb4c = 0;
  return;
}

/* ==========================================================================
 * ble_sub_2ca56   @ 0x0002ca56   (42 bytes)
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26
 */

void ble_sub_2ca56(undefined1 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  *ble_ro_2cb4c = param_1;
  uVar1 = ble_sub_3ee6e(0x49);
  puVar2 = (undefined1 *)rom_06EF4(&rom_ro_4900,uVar1,3,6);
  *puVar2 = param_1;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined2 *)(puVar2 + 4) = 0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2cad2   @ 0x0002cad2   (42 bytes)
 * calls     : ble_sub_3ee6e, dbg_printf, rom_06EF4, rom_06F26
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_sub_2cad2(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  dbg_printf(&ro_2cb90,param_2 + 0x52);
  uVar1 = ble_sub_3ee6e(0x49);
  iVar2 = rom_06EF4(_ro_2cbc4,uVar1,3,0x1b);
  *(undefined1 *)(iVar2 + 1) = 0x14;
  *(undefined1 *)(iVar2 + 2) = 100;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2cafe   @ 0x0002cafe   (44 bytes)
 * calls     : ble_sub_3ee6e, dbg_printf, rom_06EF4, rom_06F26
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_sub_2cafe(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  dbg_printf(&ro_2cb90,param_2 + 99);
  uVar1 = ble_sub_3ee6e(0x49);
  iVar2 = rom_06EF4(_ro_2cbc4 + 4,uVar1,3,0x1b);
  *(undefined1 *)(iVar2 + 1) = 0x14;
  *(undefined1 *)(iVar2 + 2) = 0x32;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2cbda   @ 0x0002cbda   (18 bytes)
 * called by : BLE_PAIR, ble_sub_2d53c, app_sec_init, switch_rf_mode_loop
 */

undefined1 ble_sub_2cbda(void)

{
  if (*shared_ro_2cfc4 != '\x01') {
    return shared_ro_2cfc8[1];
  }
  return *shared_ro_2cfc8;
}

/* ==========================================================================
 * app_sec_init   @ 0x0002cbec   (148 bytes)
 * called by : ble_sub_29530
 * calls     : flash_sub_2cbc8, ble_sub_2cbda, ble_sub_3e552, dbg_printf
 * string    : "app_sec_init().   bonded0=%x, bonded1========%x\r\n"
 * string    : "not NVDS_TAG_IRK = %x\r\n"
 * string    : "get NVDS_TAG_IRK ok= %x\r\n"
 */

void app_sec_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined1 local_18;
  undefined3 uStack_17;
  undefined1 local_14;
  undefined3 uStack_13;
  undefined4 local_10;
  
  puVar1 = shared_ro_2cfc8;
  _local_18 = CONCAT31((int3)((uint)param_2 >> 8),1);
  _local_14 = CONCAT31((int3)((uint)param_3 >> 8),0x17);
  uVar2 = 0x35;
  if (*shared_ro_2cfc4 == '\x02') {
    uVar2 = 0x36;
  }
  puVar5 = shared_ro_2cfc8;
  if (*shared_ro_2cfc4 != '\x01') {
    puVar5 = shared_ro_2cfc8 + 1;
  }
  local_10 = param_4;
  iVar3 = ble_sub_3e552(uVar2,&local_18,puVar5);
  if (iVar3 != 0) {
    flash_sub_2cbc8(0);
  }
  iVar3 = ble_sub_2cbda();
  if ((iVar3 == 0) && (iVar3 = ble_sub_2cbda(), iVar3 != 0)) {
    flash_sub_2cbc8(0);
  }
  dbg_printf(str_app_sec_init_bonded0_x_bonded1_x,*puVar1,puVar1[1]);
  local_10 = CONCAT31(local_10._1_3_,1);
  iVar3 = ble_sub_3e552(0x80,&local_10,puVar1 + 6);
  if (iVar3 != 0) {
    puVar1[6] = 0;
  }
  iVar3 = ble_sub_3e552(puVar1[6] + 'C',&local_14,ble_ro_2d000);
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
  
  dbg_printf(&ble_ro_2d03c,ble_ro_2d038);
  if ((shared_ro_2cfc8[3] == '\0') && (shared_ro_2cfc8[2] == '\0')) {
    puVar1 = (undefined1 *)rom_06EF4(ble_ro_2d044 + -0xe9,param_1 * 0x100 + 8,3,2);
    *puVar1 = 0xc;
    puVar1[1] = 1;
    rom_06F26();
    return;
  }
  rom_073D4(ble_ro_2d044,3);
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
  
  puVar1 = ble_ro_2d8ac;
  if (ble_ro_2d8a8[4] == '\x01') {
    ble_ro_2d8a8[3] = *param_2;
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
  
  puVar1 = ble_ro_2d8a8;
  dbg_printf(str_s_app_env_adv_state_x,str_gapm_activity_stopped_ind_handler,ble_ro_2d8a8[4]);
  if (puVar1[4] == '\x06') {
    puVar1[4] = 4;
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_2d53c   @ 0x0002d53c   (530 bytes)
 * calls     : ble_sub_295aa, ble_sub_2cbda, ble_sub_3e552, ble_sub_3e5f0, KEY_piaring_cnt, adv_data, ... (+11 more)
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong ble_sub_2d53c(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  bool bVar7;
  byte *pbStack_20;
  undefined1 uStack_1c;
  undefined3 uStack_1b;
  undefined4 uStack_18;
  
  _uStack_1c = CONCAT31((int3)((uint)param_3 >> 8),0x10);
  uStack_18 = param_4;
  dbg_printf(str_s_operation_x_status_x,ble_ro_2d8ac + 99,*param_2,param_2[1]);
  puVar2 = ble_ro_2d8a8;
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
  pbStack_20 = ble_ro_2d8a8 + 0x1c;
  if (bVar1 == 0x1a) {
    if (ble_ro_2d8a8[0x2d] == '\x01') {
      ble_ro_2d8a8[0x2d] = 2;
      puVar6 = (undefined1 *)rom_06EF4(ble_ro_2d940 + 0x15,7,3,1);
      *puVar6 = 0x1a;
    }
    else {
      puVar6 = (undefined1 *)rom_06EF4(ble_ro_2d940 + 0x1f,7,3,0x11);
      puVar2[0x2d] = 0;
      *puVar6 = 0x28;
      rom_24F9C(puVar6 + 1,pbStack_20,0x10);
    }
    goto LAB_0002d706;
  }
  if (bVar1 < 0x1b) {
    if (bVar1 == 1) {
      bVar7 = param_2[1] == 0;
      if (!bVar7) goto LAB_0002d57a;
      puVar6 = (undefined1 *)rom_06EF4(ble_ro_2d940,7,3,0x34);
      *puVar6 = 3;
      puVar6[1] = 10;
      puVar6[0x1b] = 1;
      *(undefined2 *)(puVar6 + 0x22) = 0xfb;
      puVar2 = ble_ro_2d94c;
      *(short *)(puVar6 + 0x24) = (short)ble_ro_2d944;
      *(short *)(puVar6 + 0x26) = (short)_ro_2d948;
      *(undefined2 *)(puVar6 + 0x20) = 0x40;
      puVar6[0x1a] = 0;
      rom_24F9C(puVar6 + 4,puVar2,6);
      if ((byte)puVar6[9] >> 6 == 3) {
        puVar6[0x1a] = puVar6[0x1a] | 1;
      }
      iVar4 = ble_sub_2cbda();
      if ((iVar4 != 0) && (iVar4 = ble_sub_3e552(0xa0,&uStack_1c,pbStack_20), iVar4 == 0)) {
        puVar5 = puVar6 + 10;
        goto LAB_0002d6ea;
      }
      rom_24FEC(puVar6 + 10,0x10);
    }
    else {
      if (bVar1 != 3) {
        bVar7 = bVar1 == 0x17;
        goto LAB_0002d57a;
      }
      iVar4 = ble_sub_2cbda();
      if (iVar4 == 0) {
        puVar6 = (undefined1 *)rom_06EF4(ble_ro_2d940 + 0x15,7,3,1);
        *puVar6 = 0x1a;
        puVar2[0x2d] = 1;
      }
      else {
        iVar4 = ble_sub_3e552(0xa0,&uStack_1c,pbStack_20);
        if (iVar4 != 0) goto LAB_0002d7ca;
        puVar6 = (undefined1 *)rom_06EF4(ble_ro_2d940 + 0x1f,7,3,0x11);
        *puVar6 = 0x28;
        puVar5 = puVar6 + 1;
LAB_0002d6ea:
        rom_24F9C(puVar5,pbStack_20,0x10);
      }
    }
  }
  else {
    if (bVar1 == 0x1b) {
      iVar4 = appm_add_svc();
      bVar7 = false;
      if (iVar4 == 0) {
        rom_07180(3,2);
        dbg_printf(0x2d950,puVar2[4]);
        if (puVar2[4] == '\0') {
          appm_create_advertising();
        }
        else {
          appm_delete_advertising();
        }
        KEY_piaring_cnt();
        rom_07342(ble_ro_2d958,3,1);
        goto LAB_0002d7ca;
      }
    }
    else {
      bVar7 = false;
      if (bVar1 == 0x28) {
        iVar4 = ble_sub_3e552(0xa0,&uStack_1c,pbStack_20);
        if (iVar4 != 0) {
          ble_sub_3e5f0(0xa0,0x10,pbStack_20);
        }
        puVar2[0x2d] = 0;
        rom_07180(3,1);
        appm_add_svc();
        goto LAB_0002d7ca;
      }
    }
LAB_0002d57a:
    if (!bVar7) goto LAB_0002d7ca;
    dbg_printf(str_GAPM_RESOLV_ADDR_CMP_STATUS_x,param_2[1]);
    if (param_2[1] != 0) {
      dbg_printf(str_appm_disconnect_1_1);
      ble_sub_295aa();
      goto LAB_0002d7ca;
    }
    puVar6 = (undefined1 *)rom_06EF4(ble_ro_2d940 + 0xfe,(uint)(byte)puVar2[2] * 0x100 + 8,3,0x34);
    uVar3 = ble_sub_2cbda();
    puVar6[0x28] = uVar3;
  }
LAB_0002d706:
  rom_06F26(puVar6);
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
  undefined *puVar2;
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
        if (*ble_ro_2dfa0 == '\0') {
          dbg_printf(str_ble_app_hogpd_report_ready_not_ready);
        }
        *unaff_r7 = '\x01';
        puVar2 = ble_ro_2dfc4;
        *unaff_r4 = unaff_r5;
        *puVar2 = unaff_r5;
        app_hid_enable_prf(ble_ro_2de7c[2]);
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
  
  puVar1 = ble_ro_2e6f8;
  dbg_printf(str_s_app_env_rand_cnt_x,ble_ro_2e6fc,ble_ro_2e6f8[0xd]);
  if (puVar1[0xd] == '\x01') {
    puVar1 = ble_ro_2e6f8 + -4;
    rom_24F9C(puVar1,param_2,8);
    pcVar2 = str_loc_irk_0;
  }
  else {
    if (puVar1[0xd] != '\x02') {
      return 0;
    }
    puVar1 = ble_ro_2e6f8 + 4;
    rom_24F9C(puVar1,param_2,8);
    pcVar2 = str_loc_irk_8;
  }
  dbg_printf_2(pcVar2,puVar1,8);
  return 0;
}

/* ==========================================================================
 * force_ble_sleep   @ 0x0002ebf8   (150 bytes)
 * calls     : ble_sub_3186e, ble_sub_32620, flash_sub_32e82, flash_sub_32f16, ble_sub_35800, ble_sub_39a84, ... (+6 more)
 * string    : "force_ble_sleep....3  Time_Entry_Sdeep =0\r\n"
 */

undefined4 force_ble_sleep(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = ble_ro_2ee68;
  puVar1 = ble_ro_2eda8;
  if (*(short *)ble_ro_2ee68 == 0) {
    if (*ble_ro_2eda8 == '\0') {
      force_ble_sleep_2();
      dbg_printf(str_force_ble_sleep_3_Time_Entry_Sdeep_0);
    }
  }
  else {
    *(short *)ble_ro_2ee68 = *(short *)ble_ro_2ee68 + -1;
    ble_sub_35800();
    ble_sub_3186e();
    uVar3 = (uint)((byte)ble_ro_2ee6c[0xb] >> 4) << 4 | (uint)((byte)ble_ro_2ee6c[0xc] >> 4);
    if (uVar3 == 0) {
      uVar3 = 1;
    }
    if (((uVar3 * 0xef - (uint)*(ushort *)puVar2 == 0) && (*ble_ro_2ee70 != '\0')) && (*puVar1 == '\0'))
    {
      *(undefined2 *)ble_ro_2ee74 = 0;
      flash_sub_32f16();
      flash_sub_32e82();
      puVar1 = shared_ro_2ee30;
      *shared_ro_2ee30 = 1;
      power_sub_3bf0a();
      power_sub_3d508();
      power_sub_3d546();
      *puVar1 = 1;
      ble_sub_32620();
      ble_sub_39a84(0x32,0);
    }
    rom_07342(shared_ro_2ed1c + 0xb,3,0x19);
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_2f31c   @ 0x0002f31c   (84 bytes)
 * called by : ble_sub_28c66
 * calls     : ble_sub_2a674, usb_sub_2bd62, power_sub_2be1c, ble_sub_33dc2, ble_sub_3c52e, ble_sub_3c574, ... (+4 more)
 */

void ble_sub_2f31c(void)

{
  int iVar1;
  
  ble_sub_3c6ce();
  iVar1 = ble_sub_3c574();
  if (iVar1 != 0) {
    ble_sub_3c52e(0);
    ble_sub_2a674();
    power_sub_2be1c();
    if ((*ble_ro_2f3c4 == '\0') && (*ble_ro_2f3c8 != '\0')) {
      if (*ble_ro_2f3cc == '\0') {
        sensor_init();
      }
      time_sensor_invalid();
      tx_failed_cnt();
      usb_sub_2bd62();
    }
    else if ((*(uint *)(ble_ro_2f3d0 + 0x2c) & 1) == 0) {
      ble_sub_33dc2();
      return;
    }
  }
  return;
}

/* ==========================================================================
 * app_ancsc_init   @ 0x0002f3f4   (18 bytes)
 * called by : ble_sub_29530
 * calls     : dbg_printf
 * string    : "app_ancsc_init"
 * string    : "%s \r\n"
 */

void app_ancsc_init(void)

{
  dbg_printf(str_s_8,ble_ro_2f69c);
  *(undefined2 *)ble_ro_2f6a8 = 0;
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
  
  dbg_printf(str_s_8,str_app_ancs_add_ancsc);
  puVar1 = (undefined1 *)rom_06EF4(ble_ro_2f6ac,7,3,0xc);
  *puVar1 = 0x1b;
  puVar1[1] = 4;
  *(undefined2 *)(puVar1 + 2) = 0x4b;
  *(undefined2 *)(puVar1 + 4) = 3;
  *(undefined2 *)(puVar1 + 6) = 0;
  rom_06F26();
  return;
}

/* ==========================================================================
 * ble_sub_2f438   @ 0x0002f438   (40 bytes)
 * calls     : ble_sub_3ee6e, rom_06EF4, rom_06F26
 */

void ble_sub_2f438(undefined2 param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  *(undefined2 *)ble_ro_2f6a8 = param_1;
  uVar1 = ble_sub_3ee6e(0x4b);
  puVar2 = (undefined2 *)rom_06EF4(&rom_ro_4b00,uVar1,3,0x8c);
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
  dbg_printf(str_s_8,str_app_ancsc_msg_dflt_handler);
  return 0;
}

/* ==========================================================================
 * app_ancsc_delete_call   @ 0x0002f58a   (74 bytes)
 * calls     : ble_sub_3ee6e, dbg_printf, rom_06EF4, rom_06F26
 * string    : "app_ancsc_delete_call"
 */

void app_ancsc_delete_call(undefined4 param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  dbg_printf(&ble_ro_2f80c,str_app_ancsc_delete_call);
  uVar1 = ble_sub_3ee6e(0x4b);
  puVar2 = (undefined2 *)rom_06EF4(ble_ro_2f6b0 + 4,uVar1,3,10);
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
 * ble_sub_2f5d4   @ 0x0002f5d4   (72 bytes)
 * calls     : ble_sub_3ee6e, dbg_printf, rom_06EF4, rom_06F26
 */

void ble_sub_2f5d4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  dbg_printf(0x2f814,str_app_ancsc_get_Socialmsg);
  uVar1 = ble_sub_3ee6e(0x4b);
  iVar2 = rom_06EF4(ble_ro_2f6b0 + 4,uVar1,3,10);
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
 * ble_sub_31114   @ 0x00031114   (94 bytes)
 * called by : ble_sub_311de, ble_sub_31210
 * calls     : ble_sub_39a84
 */

void ble_sub_31114(void)

{
  ble_sub_39a84(0x26,0,2);
  ble_sub_39a84(0x27,0,2);
  ble_sub_39a84(1,0);
  ble_sub_39a84(2,0);
  ble_sub_39a84(3,0);
  ble_sub_39a84(0x37,0);
  ble_sub_39a84(0x30,1,2);
  ble_sub_39a84(0x31,1,2);
  ble_sub_39a84(0x34,1,2);
  return;
}

/* ==========================================================================
 * ble_sub_31172   @ 0x00031172   (66 bytes)
 * called by : ble_sub_311de, ble_sub_31210
 * calls     : rf24_sub_32886, ble_sub_39a84
 */

void ble_sub_31172(void)

{
  undefined *puVar1;
  
  ble_sub_39a84(0x12,1,2);
  puVar1 = ble_ro_31568;
  *(undefined4 *)(ble_ro_31568 + 0x28) = 0;
  ble_sub_39a84(0x11,1,2);
  *(undefined4 *)(puVar1 + 0x24) = 0;
  ble_sub_39a84(0x10,1,2);
  *(undefined4 *)(puVar1 + 0x20) = 0;
  ble_sub_39a84(0x22,1,2);
  *(undefined4 *)(ble_ro_31568 + 0x48) = 0;
  rf24_sub_32886(0);
  return;
}

/* ==========================================================================
 * ble_sub_311de   @ 0x000311de   (50 bytes)
 * called by : ble_sub_2b4c8, enter_BLE_normal_app_mode
 * calls     : ble_sub_31114, ble_sub_31172, ble_sub_39a84
 */

void ble_sub_311de(void)

{
  ble_sub_31114();
  ble_sub_31172();
  ble_sub_39a84(0x34,0,1);
  ble_sub_39a84(0x24,0,2);
  *(undefined4 *)(ble_ro_31568 + 0x54) = 0x3c;
  ble_sub_39a84(0,0,1);
  return;
}

/* ==========================================================================
 * ble_sub_31210   @ 0x00031210   (32 bytes)
 * calls     : ble_sub_31114, ble_sub_31172, ble_sub_39a84
 */

void ble_sub_31210(void)

{
  ble_sub_31114();
  ble_sub_39a84(0x34,0,1);
  ble_sub_39a84(0x24,0,2);
  ble_sub_31172();
  return;
}

/* ==========================================================================
 * ble_sub_312aa   @ 0x000312aa   (52 bytes)
 * called by : Disconnected, ble_sub_31334, ble_sub_31406, usb_sub_358b6, ble_sub_35abc, ble_sub_35b08, ... (+7 more)
 */

void ble_sub_312aa(void)

{
  *ble_ro_31588 = 0;
  *ble_ro_3158c = 0;
  *ble_ro_31590 = 0;
  *ble_ro_31594 = 0;
  *(undefined2 *)ble_ro_31598 = 0;
  *(undefined2 *)ble_ro_3159c = 0;
  *(undefined2 *)shared_ro_3157c = 0;
  *(undefined2 *)shared_ro_31580 = 0;
  *ble_ro_315a0 = 0;
  *ble_ro_315a4 = 0;
  *shared_ro_315a8 = 0;
  *ble_ro_315ac = 0;
  return;
}

/* ==========================================================================
 * ble_sub_31334   @ 0x00031334   (210 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : usb_sub_31230, ble_sub_312aa, usb_sub_312de, rom_24FEC
 */

void ble_sub_31334(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  *ble_ro_315e4 = 0;
  *ble_ro_315e8 = 0;
  *ble_ro_315ec = 0;
  *ble_ro_315f0 = 0;
  *shared_ro_31584 = 0;
  *ble_ro_315f4 = 0;
  *ble_ro_315f8 = 0;
  *ble_ro_315fc = 0;
  *ble_ro_31600 = 0;
  *ble_ro_31604 = 0;
  ble_sub_312aa();
  usb_sub_312de();
  usb_sub_31230();
  rom_24FEC(ble_ro_31608,0x7e);
  rom_24FEC(ble_ro_3160c,0x91);
  *ble_ro_31610 = 0;
  *shared_ro_31614 = 0;
  *ble_ro_31618 = 0;
  *ble_ro_3161c = 0;
  *ble_ro_31620 = 0;
  *ble_ro_31624 = 0;
  *ble_ro_31628 = 1;
  *ble_ro_3162c = 0;
  *ble_ro_31630 = 0;
  *shared_ro_315a8 = 0;
  *ble_ro_31634 = 1;
  *ble_ro_31638 = 0;
  *ble_ro_3163c = 0;
  *ble_ro_31640 = 0;
  *ble_ro_31644 = 0;
  *ble_ro_31648 = 0;
  *ble_ro_3164c = 0;
  *ble_ro_31650 = 0;
  puVar1 = ble_ro_3165c;
  *ble_ro_31654 = 0;
  puVar2 = ble_ro_31660;
  *ble_ro_31658 = 0;
  *puVar1 = 5;
  *puVar2 = 4;
  *ble_ro_31664 = 5;
  *ble_ro_31668 = 5;
  *ble_ro_3166c = 5;
  *ble_ro_31670 = 8;
  *ble_ro_31674 = 0;
  *ble_ro_31678 = 0;
  *ble_ro_3167c = 0;
  *ble_ro_31680 = 0;
  *ble_ro_31684 = 0;
  *ble_ro_31688 = 0;
  return;
}

/* ==========================================================================
 * ble_sub_31406   @ 0x00031406   (54 bytes)
 * called by : Default_Profile, ble_sub_2b4de
 * calls     : usb_sub_31230, ble_sub_312aa, usb_sub_312de, rom_24FEC
 */

void ble_sub_31406(void)

{
  *shared_ro_31584 = 0;
  *ble_ro_31654 = 0;
  *ble_ro_315f0 = 0;
  *ble_ro_315ec = 0;
  *ble_ro_31604 = 0;
  ble_sub_312aa();
  usb_sub_31230();
  usb_sub_312de();
  rom_24FEC(ble_ro_31608,0x7e);
  *ble_ro_31684 = 0;
  *ble_ro_31688 = 0;
  return;
}

/* ==========================================================================
 * ble_sub_3186e   @ 0x0003186e   (262 bytes)
 * called by : force_ble_sleep, system_mode
 * calls     : Disconnected, ble_sub_2b8a2, dbg_printf
 * string    : "RB +MB  f_k_pair------------  f_hld=%x f_k_pair=%d\r\n"
 * string    : "RB +MB  f_k_pair------------  RF_MODE=%x\r\n"
 */

void ble_sub_3186e(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined *puVar8;
  uint uVar9;
  undefined4 in_r3;
  
  puVar6 = ble_ro_31ca8;
  puVar5 = ble_ro_31ca4;
  puVar8 = ble_ro_31c9c;
  puVar4 = ble_ro_31c20;
  puVar3 = ble_ro_31c1c;
  if (*ble_ro_31c1c != '\0') {
    dbg_printf(str_RB_MB_f_k_pair_f_hld_x_f_k_pair_d,*ble_ro_31c20,*ble_ro_31c1c,in_r3,in_r3);
    if (*puVar4 == '\0') {
      *puVar3 = 0;
      return;
    }
    if (*ble_ro_31c5c == '\0') {
      *puVar3 = 0;
      *ble_ro_31c60 = 0;
      *ble_ro_31c64 = 1;
      puVar3 = shared_ro_31c04;
      *ble_ro_31c68 = 1;
      *ble_ro_31c6c = *puVar3;
      ble_sub_2b8a2();
      dbg_printf(str_RB_MB_f_k_pair_RF_MODE_x,*puVar3);
    }
    return;
  }
  if (*ble_ro_31c9c == '\0') {
    if (*ble_ro_31ca4 == '\0') {
      if (*ble_ro_31cb0 == '\0') {
        return;
      }
      *ble_ro_31cb0 = 0;
      puVar3 = ble_ro_31cb4;
      uVar1 = *(ushort *)ble_ro_31cb4;
      if ((uVar1 == 0x83) && (*puVar6 != '\0')) {
        *puVar5 = 1;
        *ble_ro_31c5c = 0x14;
      }
      uVar2 = *(ushort *)ble_ro_31cb8;
      *(ushort *)ble_ro_31cb8 = uVar1;
      puVar4 = ble_ro_31cbc;
      uVar9 = (uint)(uVar2 ^ uVar1);
      uVar7 = 0;
      do {
        if ((uVar9 & 1) != 0) {
          if ((*puVar3 & 1) == 0) {
            puVar4[uVar7] = puVar4[uVar7] & 0xfe | 2;
          }
          else {
            puVar4[uVar7] = 3;
          }
        }
        uVar9 = uVar9 >> 1;
        uVar7 = uVar7 + 1 & 0xff;
        *(ushort *)puVar3 = *(ushort *)puVar3 >> 1;
      } while (uVar7 < 0xc);
      return;
    }
    puVar8 = ble_ro_31ca4;
    if (*ble_ro_31c20 != '\0') {
      if (*ble_ro_31c5c != '\0') {
        return;
      }
      *ble_ro_31ca4 = 0;
      *ble_ro_31c60 = 0;
      *ble_ro_31c64 = 1;
      if (1 < (byte)*ble_ro_31cac) {
        return;
      }
      if (*puVar6 == '\0') {
        return;
      }
      *shared_ro_31c0c = 2;
      return;
    }
  }
  else {
    if (*ble_ro_31c20 != '\0') {
      if (*ble_ro_31c5c != '\0') {
        return;
      }
      *ble_ro_31c9c = 0;
      Disconnected();
      return;
    }
    *ble_ro_31ca0 = 0;
  }
  *puVar8 = 0;
  return;
}

/* ==========================================================================
 * ble_sub_31974   @ 0x00031974   (12 bytes)
 * called by : ble_sub_319c0
 */

void ble_sub_31974(int param_1)

{
  ble_ro_31cbc[param_1] = ble_ro_31cbc[param_1] & 0xfd;
  return;
}

/* ==========================================================================
 * ble_sub_31980   @ 0x00031980   (64 bytes)
 * called by : ble_sub_332be
 */

undefined4 ble_sub_31980(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = ble_ro_31cc0;
  uVar2 = 1;
  while( true ) {
    if ((byte)ble_ro_31cc0[uVar2] == 0) {
      return 0;
    }
    if ((byte)ble_ro_31cc0[uVar2] == param_1) break;
    uVar2 = uVar2 + 1 & 0xff;
    if (6 < uVar2) {
LAB_000319a2:
      if (uVar2 == 7) {
        return 0;
      }
      for (; uVar2 < 6; uVar2 = uVar2 + 1 & 0xff) {
        puVar1[uVar2] = puVar1[uVar2 + 1];
        puVar1[uVar2 + 1] = 0;
      }
      return 1;
    }
  }
  ble_ro_31cc0[uVar2] = 0;
  goto LAB_000319a2;
}

/* ==========================================================================
 * ble_sub_319c0   @ 0x000319c0   (194 bytes)
 * called by : ble_sub_2aa5c, usb_sub_3236a
 * calls     : ble_sub_31974, ble_sub_332be, rom_25078
 */

void ble_sub_319c0(int param_1)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  puVar4 = ble_ro_31c64;
  cVar1 = *ble_ro_31cc4;
  uVar5 = (uint)(byte)shared_ro_31c00[param_1 * 3 + 0x54];
  bVar2 = *ble_ro_31c60;
  uVar6 = uVar5;
  rom_25078();
  pcVar7 = puVar4 + -99;
  pcVar7[0] = '\x01';
  pcVar7[1] = '\0';
  cVar3 = *(char *)(uVar6 + 0x1d);
  uRam0000003c = 0;
  if (*ble_ro_31cc8 == '\0') {
    if ((*ble_ro_31ccc == '\0') || (param_1 != 0)) {
      Reset = bVar2 & 0xfe;
      *pcVar7 = cVar3;
    }
    else if (cVar1 == '\x02') {
      ble_sub_332be();
      *ble_ro_31cd8 = 5;
    }
  }
  if ((*shared_ro_31c04 == '\0') && (*pcVar7 != '\0')) {
    *ble_ro_31d04 = cVar3;
  }
  if ((uVar5 & 0x3fffffff) != 0) {
    ble_sub_31974(param_1);
  }
  return;
}

/* ==========================================================================
 * ble_sub_31b3e   @ 0x00031b3e   (112 bytes)
 * called by : ble_sub_2aa5c, usb_sub_3236a
 * calls     : ble_sub_31f7c, rom_25078
 */

/* WARNING: Removing unreachable block (ram,0x00031ba6) */

void ble_sub_31b3e(void)

{
  do {
    rom_25078(*shared_ro_31c04);
  } while( true );
}

/* ==========================================================================
 * ble_sub_31f7c   @ 0x00031f7c   (24 bytes)
 * called by : ble_sub_31b3e
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00031f84) */

void ble_sub_31f7c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
 * ble_sub_32620   @ 0x00032620   (12 bytes)
 * called by : ble_sub_326ea, led_sub_32942, power_sub_3297e, SLEEP, enter_BLE_normal_app_mode, force_ble_sleep, ... (+1 more)
 */

void ble_sub_32620(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_329e8;
  *(undefined4 *)(shared_ro_329e8 + 0x28) = 0;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *(undefined4 *)(puVar1 + 0x20) = 0;
  return;
}

/* ==========================================================================
 * ble_sub_32686   @ 0x00032686   (42 bytes)
 * called by : ble_sub_28c4e, TEST_SINGLE_WAVE, TEST_SINGLE_WAVE_2, rgb_24g_test_cal
 */

void ble_sub_32686(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_329e8;
  if ((param_1 & 1) == 0) {
    *(undefined4 *)(shared_ro_329e8 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(shared_ro_329e8 + 0x20) = 2;
  }
  if ((int)(param_1 << 0x1e) < 0) {
    *(undefined4 *)(puVar1 + 0x24) = 2;
  }
  else {
    *(undefined4 *)(puVar1 + 0x24) = 0;
  }
  if ((int)(param_1 << 0x1d) < 0) {
    *(undefined4 *)(puVar1 + 0x28) = 2;
    return;
  }
  *(undefined4 *)(puVar1 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * ble_sub_326ea   @ 0x000326ea   (48 bytes)
 * calls     : ble_sub_32620
 */

void ble_sub_326ea(void)

{
  char cVar1;
  undefined *puVar2;
  
  ble_sub_32620();
  puVar2 = shared_ro_329e8;
  cVar1 = *shared_ro_329f4;
  if (cVar1 == '\0') {
    *(undefined4 *)(shared_ro_329e8 + 0x20) = 2;
  }
  else {
    *(undefined4 *)(shared_ro_329e8 + 0x20) = 0;
    if (cVar1 == '\x01') {
      *(undefined4 *)(puVar2 + 0x24) = 2;
      goto LAB_00032712;
    }
  }
  *(undefined4 *)(puVar2 + 0x24) = 0;
  if (cVar1 == '\x02') {
    *(undefined4 *)(puVar2 + 0x28) = 2;
    return;
  }
LAB_00032712:
  *(undefined4 *)(puVar2 + 0x28) = 0;
  return;
}

/* ==========================================================================
 * ble_sub_332be   @ 0x000332be   (156 bytes)
 * called by : ble_sub_319c0, usb_sub_3236a
 * calls     : ble_sub_31980, rom_24FEC
 */

undefined4 ble_sub_332be(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  puVar4 = ble_ro_333c4;
  puVar3 = shared_ro_33380;
  puVar2 = shared_ro_33368;
  if (*shared_ro_33368 == 0) {
    return 1;
  }
  if (((byte)*shared_ro_33368 < 3) || (*ble_ro_333c4 == '\0')) {
    rom_24FEC(ble_ro_333e8,8,param_3,param_4,param_4);
    *puVar3 = 1;
    *puVar2 = 0;
  }
  else {
    *shared_ro_33368 = 0;
    for (uVar9 = 0; puVar2 = ble_ro_333b0, uVar9 < (byte)*puVar4; uVar9 = uVar9 + 1 & 0xff) {
      bVar1 = ble_ro_333b0[uVar9 * 2 + 0x1a];
      *ble_ro_333d4 = bVar1;
      puVar5 = ble_ro_333d8;
      uVar7 = (uint)(byte)puVar2[uVar9 * 2 + 0x1b];
      *ble_ro_333d8 = puVar2[uVar9 * 2 + 0x1b];
      puVar6 = ble_ro_333e8;
      puVar2 = ble_ro_333dc;
      if ((uVar7 - 4 < 0xf2) && (-1 < (int)((uint)bVar1 << 0x18))) {
        if (uVar7 < 0xf1) {
          if (uVar7 < 0xe0) {
            iVar8 = ble_sub_31980();
            if (iVar8 == 0) goto LAB_0003334a;
          }
          else {
            bVar1 = (byte)(1 << (uVar7 - 0xe0 & 0xff));
            *puVar5 = bVar1;
            *puVar6 = *puVar6 & ~bVar1;
          }
          *puVar3 = 1;
        }
        else {
          bVar1 = (byte)(1 << (uVar7 - 0xf1 & 0xff));
          *puVar5 = bVar1;
          *puVar2 = *puVar2 & ~bVar1;
          *shared_ro_33388 = 1;
        }
      }
LAB_0003334a:
    }
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_33dc2   @ 0x00033dc2   (8 bytes)
 * called by : ble_sub_2f31c, SLEEP, f_reconnect_24G, force_ble_sleep_2
 * calls     : ble_sub_3443a
 */

void ble_sub_33dc2(void)

{
  ble_sub_3443a();
  return;
}

/* ==========================================================================
 * ble_sub_3443a   @ 0x0003443a   (86 bytes)
 * called by : ble_sub_33dc2, delta_none, time_sensor_invalid
 * calls     : rf24_sub_31784, rf24_sub_3aa1a, usb_sub_3aa42
 */

void ble_sub_3443a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined *puVar2;
  
  puVar2 = shared_ro_34618;
  *(undefined4 *)(shared_ro_34618 + 0x1c) = 0;
  *ble_ro_3461c = 0x16;
  rf24_sub_3aa1a(ble_ro_3461c,1,param_3,param_4,param_4);
  rf24_sub_31784(3);
  usb_sub_3aa42(ble_ro_34620,6);
  rf24_sub_31784(1);
  *(undefined4 *)(puVar2 + 0x1c) = 2;
  puVar2 = ble_ro_34628;
  uVar1 = *(undefined2 *)(ble_ro_34620 + 4);
  if ((char)*ble_ro_34620 < '\0') {
    *(undefined2 *)ble_ro_34624 = *(undefined2 *)(ble_ro_34620 + 2);
    *(undefined2 *)puVar2 = uVar1;
    return;
  }
  *(undefined2 *)ble_ro_34624 = 0;
  *(undefined2 *)puVar2 = 0;
  return;
}

/* ==========================================================================
 * ble_sub_35800   @ 0x00035800   (122 bytes)
 * called by : ble_sub_3bf40, force_ble_sleep
 */

void ble_sub_35800(void)

{
  if (*shared_ro_35b5c != '\0') {
    *shared_ro_35b5c = *shared_ro_35b5c + -1;
  }
  if (*shared_ro_35b60 != '\0') {
    *shared_ro_35b60 = *shared_ro_35b60 + -1;
  }
  if (*shared_ro_35b64 != '\0') {
    *shared_ro_35b64 = *shared_ro_35b64 + -1;
  }
  if (*(short *)shared_ro_35b68 != 0) {
    *(short *)shared_ro_35b68 = *(short *)shared_ro_35b68 + -1;
  }
  if (*shared_ro_35b6c != '\0') {
    *shared_ro_35b6c = *shared_ro_35b6c + -1;
  }
  if (*ble_ro_35b70 != '\0') {
    *ble_ro_35b70 = *ble_ro_35b70 + -1;
  }
  if (*shared_ro_35b74 != '\0') {
    *shared_ro_35b74 = *shared_ro_35b74 + -1;
  }
  if (*shared_ro_35b78 != '\0') {
    *shared_ro_35b78 = *shared_ro_35b78 + -1;
  }
  if (*shared_ro_35b7c != '\0') {
    *shared_ro_35b7c = *shared_ro_35b7c + -1;
  }
  if (*shared_ro_35b80 != '\0') {
    *shared_ro_35b80 = *shared_ro_35b80 + -1;
  }
  return;
}

/* ==========================================================================
 * disconnect   @ 0x00035a5e   (94 bytes)
 * calls     : ble_sub_29490, ble_sub_295aa, ble_sub_312aa, app_user_ke_timer_stop, ble_alert_led_stop, dbg_printf, ... (+1 more)
 * string    : "app_env.adv_state...= %d\r\n"
 * string    : "disconnect start \r\n"
 * string    : "appm  need stop adv...\r\n"
 */

void disconnect(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = rom_071EA(3);
  puVar1 = ble_ro_35c10;
  if (iVar2 == 3) {
    dbg_printf(str_disconnect_start_2);
    *(uint *)ble_ro_35c44 = *(uint *)ble_ro_35c44 | 0x100;
    ble_sub_295aa();
    *ble_ro_35c48 = 1;
  }
  else {
    dbg_printf(str_app_env_adv_state_d_3,ble_ro_35c10[4]);
    if (puVar1[4] == '\x06') {
      dbg_printf(str_appm_need_stop_adv_2);
      ble_sub_29490();
      *ble_ro_35c68 = 0;
    }
  }
  app_user_ke_timer_stop();
  ble_alert_led_stop();
  ble_sub_312aa();
  *ble_ro_35c6c = 0;
  return;
}

/* ==========================================================================
 * ble_sub_35abc   @ 0x00035abc   (76 bytes)
 * calls     : ble_sub_312aa, led_sub_32892
 */

void ble_sub_35abc(void)

{
  led_sub_32892();
  *shared_ro_35ba4 = 1;
  *(undefined2 *)ble_ro_35c70 = 0;
  *ble_ro_35c74 = 0;
  *ble_ro_35b70 = 0;
  *ble_ro_35c78 = 0;
  *ble_ro_35c7c = 0;
  *(undefined2 *)shared_ro_35b68 = 0;
  *ble_ro_35c80 = 0;
  *shared_ro_35b6c = 0;
  *ble_ro_35c84 = 0;
  *shared_ro_35b9c = 0;
  *shared_ro_35b98 = 0;
  *ble_ro_35c88 = 0;
  *ble_ro_35c8c = 0;
  ble_sub_312aa();
  *ble_ro_35c6c = 0;
  return;
}

/* ==========================================================================
 * ble_sub_35b08   @ 0x00035b08   (74 bytes)
 * calls     : ble_sub_312aa, led_sub_32892, ble_sub_3723e
 */

void ble_sub_35b08(void)

{
  ble_sub_3723e(ble_ro_35c94,ble_ro_35c90);
  led_sub_32892();
  *ble_ro_35c98 = 0;
  *(undefined2 *)ble_ro_35c70 = 0;
  *ble_ro_35c74 = 0;
  *ble_ro_35b70 = 0;
  *ble_ro_35c78 = 0;
  *ble_ro_35c7c = 0;
  *(undefined2 *)shared_ro_35b68 = 0;
  *ble_ro_35c80 = 0;
  *shared_ro_35b6c = 0;
  *ble_ro_35c84 = 0;
  *shared_ro_35b9c = 0;
  *shared_ro_35b98 = 0;
  ble_sub_312aa();
  *ble_ro_35c6c = 0;
  return;
}

/* ==========================================================================
 * ble_sub_35cd2   @ 0x00035cd2   (44 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : usb_sub_317c2, dbg_printf
 * string    : "in 24 \r\n"
 */

void ble_sub_35cd2(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_35e34;
  if (*shared_ro_35e30 == '\0') {
    *shared_ro_35e34 = 0;
    if ((*(short *)shared_ro_35e38 == 7) || (*(short *)shared_ro_35e38 == 10)) {
      dbg_printf(str_in_24);
      *puVar1 = 1;
      usb_sub_317c2(5);
    }
  }
  return;
}

/* ==========================================================================
 * ble_sub_3723e   @ 0x0003723e   (32 bytes)
 * called by : ble_sub_35b08, ble_sub_38f4e
 */

void ble_sub_3723e(code *param_1,code *param_2)

{
  undefined *puVar1;
  undefined1 *puVar2;
  
  puVar1 = shared_ro_37384;
  shared_ro_37384[9] = 0;
  puVar1[7] = 0;
  puVar1[0xb] = 0;
  (*param_2)(0);
  puVar2 = shared_ro_37384 + 0x80;
  shared_ro_37384[0x8c] = 0;
  *puVar2 = 0;
  (*param_1)(0);
  return;
}

/* ==========================================================================
 * Get_MODE_Switch_status   @ 0x00038da4   (82 bytes)
 * called by : force_pair_en
 * calls     : rf24_sub_31784, dbg_printf
 * string    : "Get_MODE_Switch_status"
 * string    : "%s,Get_MODE_Switch=:%x\r\n"
 */

undefined4 Get_MODE_Switch_status(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_38f88;
  *(undefined4 *)(shared_ro_38f88 + 0x10) = 0xc;
  rf24_sub_31784(0xfa);
  dbg_printf(str_s_Get_MODE_Switch_x,str_Get_MODE_Switch_status,*(uint *)(puVar1 + 0x10) & 1);
  if (((((*(uint *)(puVar1 + 0x10) & 1) == 0) &&
       (rf24_sub_31784(0xfa), (*(uint *)(puVar1 + 0x10) & 1) == 0)) &&
      (rf24_sub_31784(0xfa), (*(uint *)(puVar1 + 0x10) & 1) == 0)) &&
     (rf24_sub_31784(0xfa), (*(uint *)(puVar1 + 0x10) & 1) == 0)) {
    return 0;
  }
  return 1;
}

/* ==========================================================================
 * ble_sub_38f4e   @ 0x00038f4e   (12 bytes)
 * calls     : ble_sub_3723e
 */

void ble_sub_38f4e(void)

{
  ble_sub_3723e(shared_ro_390ec,shared_ro_390e8);
  return;
}

/* ==========================================================================
 * ble_sub_39198   @ 0x00039198   (40 bytes)
 * called by : ble_sub_39428, ble_sub_3b34c, power_sub_3b3f2, ble_sub_3b47e
 */

void ble_sub_39198(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = shared_ro_3958c;
  uVar2 = *(uint *)(shared_ro_3958c + 0x1c);
  *(uint *)(shared_ro_3958c + 0x1c) =
       uVar2 & 0x1f0 | param_1 | (int)shared_ro_3958c >> 0xe & uVar2 | ble_ro_39590 & uVar2 |
       uVar2 & (int)shared_ro_3958c << 0xd;
  do {
  } while (*(int *)puVar1 < 0);
  return;
}

/* ==========================================================================
 * ble_sub_393bc   @ 0x000393bc   (76 bytes)
 * called by : ble_sub_39408
 */

void ble_sub_393bc(void)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  puVar1 = shared_ro_3958c;
  uVar2 = *(uint *)(shared_ro_3958c + 0x1c);
  do {
  } while (*(int *)shared_ro_3958c < 0);
  *(uint *)(shared_ro_3958c + 0x1c) =
       uVar2 & 0xf | uVar2 & 0xc0 | 0x10 | uVar2 & 0x200 | ble_ro_39590 & uVar2 | uVar2 & 0x4000000;
  uVar3 = ble_ro_395e8;
  if (*(int *)(flash_ro_3959c + 8) == -shared_ro_395c8) {
    uVar3 = ble_ro_395e4;
  }
  *(undefined4 *)puVar1 = uVar3;
  do {
  } while (*(int *)puVar1 < 0);
  return;
}

/* ==========================================================================
 * ble_sub_39408   @ 0x00039408   (32 bytes)
 * called by : ble_sub_39428
 * calls     : ble_sub_393bc
 */

void ble_sub_39408(void)

{
  undefined *puVar1;
  
  ble_sub_393bc();
  puVar1 = shared_ro_3958c;
  *(uint *)(shared_ro_3958c + 0x1c) = *(uint *)(shared_ro_3958c + 0x1c) & 0xffffff8f;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 0x10;
  do {
  } while (*(int *)puVar1 < 0);
  return;
}

/* ==========================================================================
 * ble_sub_39428   @ 0x00039428   (18 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : ble_sub_39198, ble_sub_39408, flash_mid
 */

void ble_sub_39428(void)

{
  flash_mid();
  ble_sub_39408();
  ble_sub_39198(8);
  return;
}

/* ==========================================================================
 * ble_sub_3948a   @ 0x0003948a   (156 bytes)
 * called by : flash_sub_39526, flash_sub_396da, force_pair_en
 * calls     : rom_25024, rom_25038, rom_2504C, rom_2505C
 */

void ble_sub_3948a(undefined1 *param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_44 [8];
  undefined4 *local_24;
  int local_1c;
  int local_18;
  
  uVar4 = param_2 & 0xffffffe0;
  local_24 = local_44;
  if (param_3 != 0) {
    local_18 = rom_25024();
    local_1c = rom_25038();
    do {
    } while (*(int *)shared_ro_3958c < 0);
    while (puVar1 = shared_ro_3958c, param_3 != 0) {
      *(uint *)shared_ro_3958c = uVar4 | 0x25000000;
      do {
      } while (*(int *)puVar1 < 0);
      uVar4 = uVar4 + 0x20;
      uVar3 = 0;
      do {
        uVar2 = uVar3 + 1;
        local_44[uVar3] = *(undefined4 *)(shared_ro_3958c + 8);
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
    puVar1 = shared_ro_3958c;
    *(undefined4 *)shared_ro_3958c = 0x7d000;
    uVar4 = 0;
    do {
      *(undefined4 *)(puVar1 + 4) = 0xffffffff;
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
 * ble_sub_39a84   @ 0x00039a84   (84 bytes)
 * called by : ble_sub_31114, ble_sub_31172, input_sub_311b4, ble_sub_311de, ble_sub_31210, ble_sub_39b82, ... (+13 more)
 */

void ble_sub_39a84(uint param_1,int param_2,int param_3)

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
  *(uint *)(shared_ro_39c04 + ((param_1 >> 4) * 8 + (param_1 & 0xf)) * 4) = uVar1;
  return;
}

/* ==========================================================================
 * ble_sub_39b82   @ 0x00039b82   (44 bytes)
 * calls     : ble_sub_39a84
 */

void ble_sub_39b82(void)

{
  ble_sub_39a84(4,1,2);
  ble_sub_39a84(5,1,2);
  ble_sub_39a84(6,1,2);
  ble_sub_39a84(7,1,2);
  return;
}

/* ==========================================================================
 * ble_sub_39bc2   @ 0x00039bc2   (10 bytes)
 * called by : ble_sub_2b4c8
 */

void ble_sub_39bc2(int param_1)

{
  if (param_1 != 0) {
    *(int *)ble_ro_39c0c = param_1;
  }
  return;
}

/* ==========================================================================
 * ble_sub_39bcc   @ 0x00039bcc   (22 bytes)
 * called by : ble_sub_3c008
 */

void ble_sub_39bcc(void)

{
  *(uint *)ble_ro_39c10 = *(uint *)ble_ro_39c10 & ~((int)ble_ro_39c10 >> 0xe);
  if (*(code **)ble_ro_39c0c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00039bde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)ble_ro_39c0c)();
    return;
  }
  return;
}

/* ==========================================================================
 * ble_sub_39c02   @ 0x00039c02   (2 bytes)
 * called by : ble_sub_3c008
 */

void ble_sub_39c02(void)

{
  return;
}

/* ==========================================================================
 * ble_sub_3a244   @ 0x0003a244   (218 bytes)
 * called by : rwip_driver_init
 * calls     : cal_data, rom_24F9C
 */

void ble_sub_3a244(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 local_30 [48];
  
  param_1[8] = ble_ro_3a558;
  param_1[9] = ble_ro_3a55c;
  param_1[5] = ble_ro_3a560;
  *(undefined1 *)(param_1 + 0xb) = 1;
  *(undefined1 *)((int)param_1 + 0x2d) = 0xc;
  param_1[10] = ble_ro_3a564;
  *param_1 = ble_ro_3a568;
  param_1[1] = ble_ro_3a56c;
  param_1[7] = ble_ro_3a570;
  param_1[6] = ble_ro_3a574;
  uVar6 = 0;
  do {
    local_30[uVar6] = (char)(uVar6 << 1);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0x28);
  rom_24F9C(ble_ro_3a578,local_30,0x28);
  cal_data();
  puVar1 = ble_ro_3a57c;
  *(undefined4 *)(ble_ro_3a57c + 0x34) = 0x20;
  *(undefined4 *)(puVar1 + 0x34) = 0x20;
  *(undefined4 *)(ble_ro_3a57c + 0xa0) = ble_ro_3a580;
  puVar1 = ble_ro_3a588;
  *(undefined4 *)(ble_ro_3a588 + 0x38) = ble_ro_3a584;
  *(undefined4 *)(puVar1 + 0x38) = ble_ro_3a58c;
  uVar3 = ble_ro_3a590;
  *(undefined4 *)(ble_ro_3a588 + 0x40) = ble_ro_3a590;
  uVar4 = ble_ro_3a594;
  *(undefined4 *)(ble_ro_3a588 + 0x40) = ble_ro_3a594;
  uVar5 = ble_ro_3a598;
  puVar1 = ble_ro_3a588;
  *(undefined4 *)(ble_ro_3a588 + 0x44) = ble_ro_3a598;
  *(undefined4 *)(puVar1 + 0x44) = uVar5;
  *(undefined4 *)(puVar1 + 0x48) = uVar3;
  *(undefined4 *)(puVar1 + 0x48) = uVar4;
  *(undefined4 *)(puVar1 + 0x4c) = ble_ro_3a59c;
  *(undefined4 *)(puVar1 + 0x4c) = 0x65;
  uVar3 = ble_ro_3a5a0;
  *(undefined4 *)(puVar1 + 0x50) = ble_ro_3a5a0;
  *(undefined4 *)(puVar1 + 0x50) = uVar3;
  uVar3 = ble_ro_3a5a4;
  *(undefined4 *)(puVar1 + 0x54) = ble_ro_3a5a4;
  *(undefined4 *)(puVar1 + 0x54) = uVar3;
  *(undefined4 *)(puVar1 + 0x58) = ble_ro_3a5a8;
  *(undefined4 *)(puVar1 + 0x58) = ble_ro_3a5ac;
  *(undefined4 *)(puVar1 + 0x5c) = ble_ro_3a5b0;
  *(undefined4 *)(puVar1 + 0x5c) = 0x20;
  puVar1 = ble_ro_3a57c;
  uVar6 = (int)ble_ro_3a57c << 0x18;
  *(uint *)(ble_ro_3a57c + 0x34) = *(uint *)(ble_ro_3a57c + 0x34) & ~uVar6 | uVar6;
  puVar2 = ble_ro_3a57c;
  *(uint *)(ble_ro_3a57c + 0x34) = *(uint *)(puVar1 + 0x34) & ~((int)uVar6 >> 0x11);
  *(uint *)(puVar2 + 0x34) = *(uint *)(puVar2 + 0x34) & ~uVar6 | uVar6;
  return;
}

/* ==========================================================================
 * ble_sub_3a688   @ 0x0003a688   (68 bytes)
 * called by : RC32K_2
 */

void ble_sub_3a688(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = shared_ro_3a8ec;
  *(uint *)(shared_ro_3a8ec + 0x30) = *(uint *)(shared_ro_3a8ec + 0x30) & 0xffffdfff;
  puVar1 = shared_ro_3a8e0;
  *(undefined4 *)(shared_ro_3a8e0 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) & 0xffff7fff;
  *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  *(uint *)(puVar2 + 0x24) = *(uint *)(puVar2 + 0x24) & 0xffffffbf;
  *(undefined4 *)(puVar1 + 0x24) = *(undefined4 *)(puVar2 + 0x24);
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) & 0xffff7fff;
  *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  *(uint *)(puVar2 + 0x30) = *(uint *)(puVar2 + 0x30) | 0x8000;
  *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar2 + 0x30);
  return;
}

/* ==========================================================================
 * ble_sub_3aad4   @ 0x0003aad4   (92 bytes)
 * called by : ble_sub_3c008
 */

void ble_sub_3aad4(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  *(uint *)shared_ro_3ad24 = *(uint *)shared_ro_3ad24 & 0xffffffbf;
  puVar2 = shared_ro_3ad0c;
  shared_ro_3ad0c[1] = 1;
  puVar1 = shared_ro_3ad08;
  if (*(int *)(shared_ro_3ad08 + 8) << 0x12 < 0) {
    *(uint *)(shared_ro_3ad08 + 8) = *(uint *)(shared_ro_3ad08 + 8) | 0x2000;
    if (*(code **)(puVar2 + 4) != (code *)0x0) {
      (**(code **)(puVar2 + 4))();
    }
  }
  if (*(int *)(puVar1 + 8) << 0x11 < 0) {
    *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x4000;
  }
  if (*(int *)(puVar1 + 8) << 0x13 < 0) {
    *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x1000;
  }
  if (*(int *)(puVar1 + 8) << 0x16 < 0) {
    *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x200;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3abf2   @ 0x0003abf2   (132 bytes)
 * calls     : ble_sub_39a84, dbg_printf
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_sub_3abf2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  byte *pbVar4;
  
  reg_80000c = reg_80000c & 0xffffdfff;
  *(uint *)shared_ro_3ad24 = *(uint *)shared_ro_3ad24 | 0x40;
  ble_sub_39a84(4,3,2);
  ble_sub_39a84(5,3,2);
  ble_sub_39a84(6,3,2);
  ble_sub_39a84(7,3,2);
  puVar1 = shared_ro_3ad08;
  *(undefined4 *)shared_ro_3ad08 = 0;
  *(undefined4 *)puVar1 = _ro_3ad6c;
  *(undefined4 *)(puVar1 + 4) = 0xf;
  reg_800010 = reg_800010 | 0x800;
  *(uint *)puVar1 = *(uint *)puVar1 | 0x800000;
  *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) | 0x30000;
  puVar2 = shared_ro_3ad54;
  iVar3 = 0;
  do {
    pbVar4 = *(byte **)(puVar2 + 4);
    *(uint *)(puVar1 + 0xc) = (uint)*pbVar4;
    iVar3 = iVar3 + 1;
    *(byte **)(puVar2 + 4) = pbVar4 + 1;
  } while (iVar3 < 10);
  dbg_printf(str_SPI_CTRL_1_slave_x,*(undefined4 *)puVar1);
  return;
}

/* ==========================================================================
 * ble_sub_3ae40   @ 0x0003ae40   (54 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void ble_sub_3ae40(void)

{
  reg_800000 = reg_800000 & 0xfffffdff;
  reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  *(undefined4 *)(shared_ro_3b24c + 0x1c) = 0x80;
  reg_800034 = reg_800034 | 0x40;
  *(undefined4 *)(shared_ro_3b254 + 0x10) = ble_ro_3b250;
  return;
}

/* ==========================================================================
 * ble_sub_3ae82   @ 0x0003ae82   (170 bytes)
 * called by : ble_sub_28c66, usb_sub_360aa
 */

void ble_sub_3ae82(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  
  puVar4 = shared_ro_3b260;
  uVar3 = ble_ro_3b25c;
  reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  *(undefined4 *)(shared_ro_3b260 + 0x18) = ble_ro_3b25c;
  puVar5 = shared_ro_3b264;
  *(undefined4 *)(shared_ro_3b264 + 0x18) = uVar3;
  iVar6 = ble_ro_3b268;
  *(int *)(puVar4 + 0x28) = ble_ro_3b268;
  *(int *)(puVar5 + 0x28) = iVar6;
  puVar1 = shared_ro_3b24c;
  *(uint *)(shared_ro_3b24c + 0x1c) = *(uint *)(shared_ro_3b24c + 0x1c) | 0x80;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 2;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 4;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 1;
  shared_ro_3b258[2] = 1;
  puVar2 = shared_ro_3b254;
  uVar7 = *(uint *)(puVar1 + 0x1c);
  *(uint *)(shared_ro_3b254 + 0x10) = (*(uint *)(shared_ro_3b254 + 0x10) & 0xffff0fff) + 0x7000;
  *(uint *)(puVar2 + 0x10) = (*(uint *)(puVar2 + 0x10) & 0xffffff0f) + 0x70;
  reg_800008 = reg_800008 & 0xfffffe7f;
  *(uint *)(puVar1 + 0x1c) = uVar7 | 8;
  reg_800004 = reg_800004 | 1;
  *(undefined4 *)(puVar1 + 0x1c) = 0x80;
  *(undefined4 *)(puVar2 + 0x10) = ble_ro_3b26c;
  uVar3 = ble_ro_3b270;
  reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80;
  *(undefined4 *)(puVar4 + 0x18) = ble_ro_3b270;
  *(undefined4 *)(puVar5 + 0x18) = uVar3;
  iVar6 = ble_ro_3b268 + 4;
  *(int *)(puVar4 + 0x28) = iVar6;
  *(int *)(puVar5 + 0x28) = iVar6;
  return;
}

/* ==========================================================================
 * ble_sub_3af2c   @ 0x0003af2c   (64 bytes)
 * called by : ble_sub_28c66, ble_sub_3c008
 * calls     : rom_25078
 */

void ble_sub_3af2c(void)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  puVar1 = shared_ro_3b24c;
  if (shared_ro_3b258[2] != '\0') {
    *(undefined4 *)(shared_ro_3b24c + 0x1c) = 0x80;
    iVar2 = (int)puVar1 * 0x20000;
    uVar3 = rom_25078();
    *(uint *)(iVar2 + 8) = (*(uint *)(iVar2 + 8) & 0xffffff80) + 2;
    *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | (uint)((longlong)uVar3 >> 0x34);
    *(undefined1 *)(((int)uVar3 >> 0x14) + 2) = 0;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3af8a   @ 0x0003af8a   (24 bytes)
 * called by : ble_sub_28c66, SLEEP, exist
 */

void ble_sub_3af8a(void)

{
  *(uint *)(shared_ro_3b254 + 0x10) = *(uint *)(shared_ro_3b254 + 0x10) & 0xfffeffff;
  reg_800004 = reg_800004 | 1;
  return;
}

/* ==========================================================================
 * ble_sub_3b0b8   @ 0x0003b0b8   (102 bytes)
 * calls     : ble_sub_39a84
 */

void ble_sub_3b0b8(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  ble_sub_39a84(param_1,0);
  uVar2 = (param_1 >> 4) * 8 + (param_1 & 0xf);
  *(uint *)(shared_ro_3b254 + -0x34) = 1 << (uVar2 & 0xff) | *(uint *)(shared_ro_3b254 + -0x34);
  puVar1 = ble_ro_3b274;
  if (0xf < uVar2) {
    *(uint *)(ble_ro_3b274 + 4) = 3 << (uVar2 * 2 - 0x20 & 0xff) | *(uint *)(ble_ro_3b274 + 4);
  }
  else {
    *(uint *)ble_ro_3b274 = 3 << (uVar2 * 2 & 0xff) | *(uint *)ble_ro_3b274;
  }
  *(uint *)(puVar1 + 0xc) = 1 << (uint)(0xf >= uVar2) | *(uint *)(puVar1 + 0xc);
  *(uint *)(puVar1 + 0x14) = 1 << (uint)(uVar2 < 0x10) | *(uint *)(puVar1 + 0x14);
  return;
}

/* ==========================================================================
 * reset   @ 0x0003b152   (140 bytes)
 * called by : ble_sub_2a78c
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
  undefined *puVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar1 = shared_ro_3b254;
  puVar5 = (uint *)(shared_ro_3b254 + -0x40);
  dbg_printf(str_s36reset_reason_x_x + 2,*puVar5,*(undefined4 *)(shared_ro_3b254 + -0x34));
  uVar4 = (*puVar5 & 0x7ff) >> 8;
  uVar2 = *(uint *)(puVar1 + -0x34) & 0xffff;
  *puVar5 = *puVar5 & 0xfffff8ff;
  if (uVar4 == 1) {
    if (uVar2 == 0) {
      dbg_printf(str_force_all_reset);
      return 2;
    }
    if (uVar2 + ble_ro_3b2a4 == 0) {
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
    if (uVar2 + ble_ro_3b2d8 == 0) {
      dbg_printf(str_deep_sleep_reset);
      return 3;
    }
    if (uVar2 + ble_ro_3b2d8 + ble_ro_3b2dc == 0) {
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
 * ble_sub_3b34c   @ 0x0003b34c   (166 bytes)
 * calls     : ble_sub_39198, power_sub_3b214
 */

void ble_sub_3b34c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  ble_sub_39198(8);
  puVar1 = ble_ro_3b4e8;
  *(uint *)(ble_ro_3b4e8 + 0xc) = *(uint *)(ble_ro_3b4e8 + 0xc) | 0x80000000;
  *(undefined4 *)(ble_ro_3b4ec + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  power_sub_3b214();
  puVar1 = shared_ro_3b4f0;
  reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
  *(uint *)(shared_ro_3b4f0 + 0x1c) = *(uint *)(shared_ro_3b4f0 + 0x1c) | 0x80;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 2;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 4;
  *(uint *)(puVar1 + 0x1c) = *(uint *)(puVar1 + 0x1c) | 1;
  puVar2 = shared_ro_3b4f4;
  uVar3 = *(uint *)(puVar1 + 0x1c);
  *(uint *)(shared_ro_3b4f4 + 0x10) = (*(uint *)(shared_ro_3b4f4 + 0x10) & 0xffff0fff) + 0x5000;
  *(uint *)(puVar2 + 0x10) = (*(uint *)(puVar2 + 0x10) & 0xffffff0f) + 0x50;
  reg_800008 = reg_800008 & 0xfffffe7f;
  *(uint *)(puVar1 + 0x1c) = uVar3 | 8;
  reg_800004 = reg_800004 | 1;
  *(undefined4 *)(puVar1 + 0x1c) = 0x80;
  *(undefined4 *)(puVar2 + 0x10) = shared_ro_3b4f8;
  reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80;
  return;
}

/* ==========================================================================
 * ble_sub_3b47e   @ 0x0003b47e   (106 bytes)
 * called by : ble_sub_3c008
 * calls     : ble_sub_39198
 */

void ble_sub_3b47e(void)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = shared_ro_3b4fc;
  if (shared_ro_3b4fc[3] != '\x01') {
    return;
  }
  *(undefined4 *)(shared_ro_3b4f0 + 0x1c) = 0x80;
  *(undefined4 *)(shared_ro_3b4f4 + 0x10) = shared_ro_3b4f8;
  cVar1 = puVar2[1];
  if (cVar1 == '\x01') {
    reg_800008 = (reg_800008 & 0xfffffe7f) + 0x80 & 0xffffff80;
    goto LAB_0003b4d2;
  }
  if (cVar1 == '\x03') {
LAB_0003b4de:
    uVar3 = (reg_800008 & 0xffffff80) + 1;
  }
  else {
    if (cVar1 != '\x04') {
      if (cVar1 != '\x05') goto LAB_0003b4d2;
      goto LAB_0003b4de;
    }
    uVar3 = (reg_800008 & 0xffffff80) + 2;
  }
  reg_800008 = uVar3 | 0x180;
LAB_0003b4d2:
  ble_sub_39198(8);
  puVar2[3] = 0;
  return;
}

/* ==========================================================================
 * ble_sub_3b512   @ 0x0003b512   (22 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void ble_sub_3b512(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3b564;
  *(undefined4 *)shared_ro_3b564 = 3;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 8) = param_1;
  *(undefined4 *)(puVar1 + 4) = 0x5a;
  *(undefined4 *)(puVar1 + 4) = 0xa5;
  return;
}

/* ==========================================================================
 * ble_sub_3b538   @ 0x0003b538   (22 bytes)
 * called by : BLE_PAIR, ble_sub_3bb38, ble_sub_405ae, SLEEP, exist
 */

void ble_sub_3b538(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3b564;
  *(undefined4 *)shared_ro_3b564 = 3;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 8) = param_1;
  *(undefined4 *)(puVar1 + 4) = 0x5a;
  *(undefined4 *)(puVar1 + 4) = 0xa5;
  return;
}

/* ==========================================================================
 * ble_sub_3b5e6   @ 0x0003b5e6   (18 bytes)
 * called by : ble_sub_3c008
 */

void ble_sub_3b5e6(void)

{
  *(uint *)shared_ro_3b6bc = *(uint *)shared_ro_3b6bc | (int)shared_ro_3b6bc >> 0xf;
  *shared_ro_3b6c8 = 1;
  return;
}

/* ==========================================================================
 * ble_sub_3b6f6   @ 0x0003b6f6   (72 bytes)
 * calls     : ble_sub_39a84, rom_24F24
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_sub_3b6f6(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  
  *(uint *)(param_3 * 0x800000 + 0xc) = *(uint *)(param_3 * 0x800000 + 0xc) & 0xfffffffd;
  iVar2 = rom_24F24(_ro_3b8bc,param_1);
  ble_sub_39a84(0x16,3,0);
  ble_sub_39a84(0x17,3,0);
  puVar1 = shared_ro_3b8c0;
  *(int *)shared_ro_3b8c0 = (iVar2 + -1) * 0x100 + 0x19;
  *(undefined4 *)(puVar1 + 4) = _ro_3b8c4;
  *(undefined4 *)(puVar1 + 0x10) = 0x42;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  puVar1 = shared_ro_3b8c8;
  *shared_ro_3b8c8 = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}

/* ==========================================================================
 * ble_sub_3b8e0   @ 0x0003b8e0   (30 bytes)
 * called by : ble_sub_3ba0a, ble_sub_3bb38, ble_sub_3bd90
 * calls     : ble_sub_3be98
 */

void ble_sub_3b8e0(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  
  while (param_2 != 0) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    ble_sub_3be98(uVar1);
    param_2 = param_2 - 1 & 0xffff;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3b904   @ 0x0003b904   (46 bytes)
 * called by : ble_sub_3b932, ble_sub_3bdca, ble_sub_3bde6
 * calls     : rom_24FEC
 */

void ble_sub_3b904(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = ble_ro_3bcf8;
  if ((param_1 & 1) != 0) {
    *(undefined4 *)(ble_ro_3bcf8 + -0x48) = 0;
    rom_24FEC(puVar1 + -0x44,0x40);
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  puVar1 = ble_ro_3bcf8;
  if ((int)(param_1 << 0x1e) < 0) {
    rom_24FEC(ble_ro_3bcf8 + 4,0x40);
    *(undefined4 *)(puVar1 + 0x44) = 0;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3b932   @ 0x0003b932   (124 bytes)
 * called by : ble_sub_28c4e
 * calls     : ble_sub_28c48, ble_sub_39a84, ble_sub_3b904, rom_24F24
 */

void ble_sub_3b932(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  
  reg_80000c = reg_80000c & 0xfffffffe;
  iVar2 = rom_24F24(ble_ro_3bcfc,param_1);
  ble_sub_39a84(0,3);
  ble_sub_39a84(1,3,0);
  puVar1 = ble_ro_3bd00;
  *(int *)ble_ro_3bd00 = (iVar2 + -1) * 0x100 + 0x1b;
  *(undefined4 *)(puVar1 + 4) = ble_ro_3bd04;
  *(undefined4 *)(puVar1 + 0x10) = 0x42;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  *(uint *)ble_ro_3bd08 = *(uint *)ble_ro_3bd08 | 0x10;
  puVar1 = shared_ro_3bd0c;
  *shared_ro_3bd0c = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  puVar1 = shared_ro_3bd10;
  *(undefined4 *)(shared_ro_3bd10 + 8) = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)(puVar1 + 0x14) = 0;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  *(undefined4 *)(puVar1 + 0x20) = 0;
  puVar1[0x24] = 0;
  puVar1[0x25] = 0;
  iVar2 = ble_sub_28c48();
  if (iVar2 == 1) {
    ble_sub_3b904(3);
    *(undefined **)ble_ro_3bcf8 = ble_ro_3bd14;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3ba0a   @ 0x0003ba0a   (40 bytes)
 * calls     : ble_sub_3b8e0, ble_sub_429fc
 */

uint ble_sub_3ba0a(void)

{
  uint uVar1;
  undefined4 in_stack_00000000;
  undefined1 auStack_88 [128];
  
  uVar1 = ble_sub_429fc(auStack_88,in_stack_00000000,&stack0x00000004);
  ble_sub_3b8e0(auStack_88,uVar1 & 0xffff);
  return uVar1;
}

/* ==========================================================================
 * ble_sub_3ba28   @ 0x0003ba28   (30 bytes)
 * calls     : ble_sub_3be98
 */

char ble_sub_3ba28(char *param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    ble_sub_3be98();
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}

/* ==========================================================================
 * ble_sub_3ba46   @ 0x0003ba46   (40 bytes)
 * called by : ble_sub_3bb38
 */

void ble_sub_3ba46(undefined1 *param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = ble_ro_3bd18;
  for (uVar2 = 3; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xff) {
    *param_1 = puVar1[*(byte *)(param_2 + uVar2) >> 4];
    param_1[1] = puVar1[*(byte *)(param_2 + uVar2) & 0xf];
    param_1 = param_1 + 2;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3ba6e   @ 0x0003ba6e   (26 bytes)
 * called by : ble_sub_3bb38
 * calls     : rom_24F9C
 */

void ble_sub_3ba6e(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = ble_ro_3bcf8;
  *(undefined4 *)(ble_ro_3bcf8 + -0x48) = 0;
  rom_24F9C(puVar1 + -0x44,param_1,param_2);
  *(undefined4 *)(puVar1 + -4) = param_2;
  return;
}

/* ==========================================================================
 * ble_sub_3bad6   @ 0x0003bad6   (32 bytes)
 * called by : ble_sub_3bb38
 * calls     : rom_25078
 */

void ble_sub_3bad6(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = shared_ro_3bd0c;
  iVar2 = rom_25078();
  if (iVar2 != 1) {
    return;
  }
  puVar1[3] = 1;
  return;
}

/* ==========================================================================
 * ble_sub_3bb38   @ 0x0003bb38   (498 bytes)
 * calls     : ble_sub_28c48, ble_sub_3b538, ble_sub_3b8e0, ble_sub_3ba46, ble_sub_3ba6e, ble_sub_3bad6, ... (+2 more)
 */

void ble_sub_3bb38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  puVar3 = shared_ro_3bd10;
  puVar2 = shared_ro_3bd0c;
  uVar8 = *(uint *)(ble_ro_3bd00 + 0x14);
  if ((uVar8 & 0x42) == 0) goto LAB_0003bd7a;
  *ble_ro_3bd20 = 1;
  while (*(int *)(ble_ro_3bd00 + 8) << 10 < 0) {
    puVar3[*(int *)(puVar2 + 8) + 0x28] = (char)((uint)*(undefined4 *)(ble_ro_3bd00 + 0xc) >> 8);
    ble_sub_3bad6(puVar3[*(int *)(puVar2 + 8) + 0x28]);
    *(int *)(puVar2 + 8) = *(int *)(puVar2 + 8) + 1;
    if (*(int *)(puVar2 + 8) == 0x80) {
      *(undefined4 *)(puVar2 + 8) = 0;
    }
  }
  if (-1 < (int)(uVar8 << 0x19)) goto LAB_0003bd7a;
  iVar5 = ble_sub_28c48();
  puVar3 = shared_ro_3bd10;
  if (iVar5 == 1) {
    if (shared_ro_3bd10[0x28] == '\x01') {
      if ((byte)shared_ro_3bd10[0x2b] + 4 == *(int *)(puVar2 + 8)) {
        cVar1 = shared_ro_3bd10[0x29];
        if ((cVar1 == -0x20) || (shared_ro_3bd10[0x2a] == -4)) {
          if ((puVar2[1] != '\x01') ||
             ((((cVar1 != -0x20 || (shared_ro_3bd10[0x2a] != -4)) || ((byte)shared_ro_3bd10[0x2b] != 2)) ||
              ((shared_ro_3bd10[0x2c] != '\x0e' || (shared_ro_3bd10[0x2d] != -0x60)))))) goto LAB_0003bc5e;
          uVar4 = ble_sub_42450(shared_ro_3bd0c + 0x33);
          ble_sub_3b8e0(shared_ro_3bd0c + 0x33,uVar4);
        }
        else {
          if ((cVar1 == '\x1e') && (puVar2[1] == '\x01')) {
            puVar7 = shared_ro_3bd10 + 0xa8;
            *puVar7 = 0x73;
            puVar3[0xa9] = 0x65;
            puVar3[0xaa] = 0x74;
            puVar3[0xab] = 0x20;
            puVar3[0xac] = 0x70;
            puVar3[0xad] = 0x77;
            puVar3[0xae] = 0x72;
            puVar3[0xaf] = 0x3a;
            puVar3[0xb0] = 0x39;
            puVar3[0xb1] = 0x20;
            puVar3[0xb2] = 0x2d;
            puVar3[0xb3] = 0x20;
            puVar3[0xb4] = 99;
            puVar3[0xb5] = 0x3a;
            ble_sub_3ba46(puVar3 + 0xb6,puVar3 + 0x2c,1,0x2d,param_2,param_3,param_4);
            puVar3[0xb8] = 0xd;
            puVar3[0xb9] = 10;
            ble_sub_3b8e0(puVar7,0x12);
          }
          ble_sub_3ba6e(shared_ro_3bd10 + 0x28,*(uint *)(puVar2 + 8) & 0xffff);
        }
        goto LAB_0003bc4e;
      }
LAB_0003bc5e:
      uVar6 = ble_sub_42450(shared_ro_3bd0c + 0xc);
      iVar5 = rom_25002(shared_ro_3bd10 + 0x28,shared_ro_3bd0c + 0xc,uVar6);
      if (iVar5 == 0) {
        func_0x0003ba08(0x3bd34,*ble_ro_3bd30,ble_ro_3bd30[1],ble_ro_3bd30[2],ble_ro_3bd30[3],ble_ro_3bd30[4],
                        ble_ro_3bd30[5]);
        func_0x0003ba08(0x3bd24);
        *(undefined4 *)(puVar2 + 8) = 0;
      }
      else {
        uVar6 = ble_sub_42450(shared_ro_3bd0c + 0x19);
        iVar5 = rom_25002(shared_ro_3bd10 + 0x28,shared_ro_3bd0c + 0x19,uVar6);
        if (iVar5 == 0) {
          uVar4 = ble_sub_42450(ble_ro_3bea4);
          ble_sub_3b8e0(ble_ro_3bea4,uVar4);
          *(undefined4 *)(puVar2 + 8) = 0;
          goto LAB_0003bd6e;
        }
        uVar6 = ble_sub_42450(shared_ro_3bd0c + 0x42);
        iVar5 = rom_25002(shared_ro_3bd10 + 0x28,shared_ro_3bd0c + 0x42,uVar6);
        if (iVar5 == 0) {
          ble_sub_3b538(0x10);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uVar6 = ble_sub_42450(shared_ro_3bd0c + 0x4b);
        iVar5 = rom_25002(shared_ro_3bd10 + 0x28,shared_ro_3bd0c + 0x4b,uVar6);
        if (iVar5 == 0) {
          ble_sub_3b538(0x10);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
    }
    else {
LAB_0003bc4e:
      if ((shared_ro_3bd10[0x28] != '\r') || (shared_ro_3bd10[0x29] != '\n')) goto LAB_0003bc5e;
      func_0x0003ba08(0x3bd24);
LAB_0003bd6e:
      puVar2[1] = 1;
    }
  }
  *(undefined4 *)(puVar2 + 8) = 0;
  *puVar2 = 1;
LAB_0003bd7a:
  *(uint *)(ble_ro_3bea8 + 0x14) = uVar8;
  return;
}

/* ==========================================================================
 * ble_sub_3bd90   @ 0x0003bd90   (58 bytes)
 * calls     : ble_sub_3b8e0, rom_24F9C
 */

void ble_sub_3bd90(undefined4 param_1,int param_2)

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
  ble_sub_3b8e0(&uStack_28,param_2 + 7);
  return;
}

/* ==========================================================================
 * ble_sub_3bdca   @ 0x0003bdca   (28 bytes)
 * called by : ble_sub_3bde6
 * calls     : ble_sub_3b904
 */

void ble_sub_3bdca(void)

{
  if (*(int *)ble_ro_3beac != 0) {
    (**(code **)ble_ro_3beac)(ble_ro_3beac + 4,*(uint *)(ble_ro_3beac + 0x44) & 0xffff);
  }
  ble_sub_3b904(2);
  return;
}

/* ==========================================================================
 * ble_sub_3bde6   @ 0x0003bde6   (178 bytes)
 * called by : ble_sub_28c4e
 * calls     : ble_sub_3b904, ble_sub_3bdca, rom_24F9C
 */

void ble_sub_3bde6(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  
  puVar1 = ble_ro_3beb0;
  uVar3 = 0;
  while (puVar1[0x24] == '\x01') {
    pcVar4 = *(code **)puVar1;
    uVar2 = *(undefined4 *)(puVar1 + 4);
    puVar1[0x24] = 0;
    rom_24F9C(ble_ro_3beac + uVar3 + 4,*(undefined4 *)(puVar1 + 0x14),*(undefined4 *)(puVar1 + 0x1c));
    uVar3 = *(int *)(puVar1 + 0x1c) + uVar3 & 0xffff;
    *(int *)(ble_ro_3beac + 0x44) = *(int *)(ble_ro_3beac + 0x44) + *(int *)(puVar1 + 0x1c);
    if (pcVar4 != (code *)0x0) {
      *(undefined4 *)puVar1 = 0;
      *(undefined4 *)(puVar1 + 4) = 0;
      (*pcVar4)(uVar2,0);
    }
  }
  if (*(int *)(ble_ro_3beac + 0x44) != 0) {
    ble_sub_3bdca();
  }
  uVar3 = 0;
  if (*(int *)(ble_ro_3beac + -4) == 0) {
    return;
  }
  do {
    if (puVar1[0x25] != '\x01') break;
    pcVar4 = *(code **)(puVar1 + 8);
    uVar2 = *(undefined4 *)(puVar1 + 0xc);
    puVar1[0x25] = 0;
    rom_24F9C(*(undefined4 *)(puVar1 + 0x18),ble_ro_3beac + (uVar3 - 0x44),
              *(undefined4 *)(puVar1 + 0x20));
    uVar3 = *(int *)(puVar1 + 0x20) + uVar3 & 0xffff;
    if (pcVar4 != (code *)0x0) {
      *(undefined4 *)(puVar1 + 8) = 0;
      *(undefined4 *)(puVar1 + 0xc) = 0;
      (*pcVar4)(uVar2,0);
    }
  } while (uVar3 < *(uint *)(ble_ro_3beac + -4));
  ble_sub_3b904(1);
  return;
}

/* ==========================================================================
 * ble_sub_3be98   @ 0x0003be98   (12 bytes)
 * called by : ble_sub_3b8e0, ble_sub_3ba28
 */

void ble_sub_3be98(undefined4 param_1)

{
  do {
  } while (-1 < *(int *)(ble_ro_3bea8 + 8) << 0xb);
  *(undefined4 *)(ble_ro_3bea8 + 0xc) = param_1;
  return;
}

/* ==========================================================================
 * ble_sub_3bf40   @ 0x0003bf40   (88 bytes)
 * called by : ble_sub_3c008
 * calls     : ble_sub_35800
 */

void ble_sub_3bf40(void)

{
  *(uint *)shared_ro_3bf98 = *(uint *)shared_ro_3bf98 | 0x20;
  if ((((*shared_ro_3bf9c != '\x01') && (*shared_ro_3bf9c != '\x02')) || (*shared_ro_3bfa0 != '\0')) ||
     (*shared_ro_3bfa0 != '\0')) {
    if (*(short *)ble_ro_3bfac == 0) {
      if ((*ble_ro_3bfb0 == '\0') && (*shared_ro_3bfa0 == '\0')) {
        *ble_ro_3bfb4 = 3;
      }
    }
    else {
      *(short *)ble_ro_3bfac = *(short *)ble_ro_3bfac + -1;
    }
    *ble_ro_3bfb8 = 1;
    *ble_ro_3bfbc = 1;
    ble_sub_35800();
  }
  return;
}

/* ==========================================================================
 * ble_sub_3bfc2   @ 0x0003bfc2   (70 bytes)
 * called by : enter_BLE_normal_app_mode
 */

void ble_sub_3bfc2(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3c0dc;
  *(undefined4 *)shared_ro_3c0dc = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(uint *)puVar1 = *(uint *)puVar1 & 0xfffffffb;
  *(uint *)puVar1 = *(uint *)puVar1 | (int)puVar1 << 0xe;
  *(uint *)puVar1 = *(uint *)puVar1 | (int)puVar1 << 0x10;
  *(uint *)puVar1 = *(uint *)puVar1 | (int)puVar1 << 0xf;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | (int)puVar1 << 0xe;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | (int)puVar1 << 0x10;
  *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) | (int)puVar1 << 0xf;
  *(uint *)puVar1 = *(uint *)puVar1 | (int)puVar1 << 0xc;
  return;
}

/* ==========================================================================
 * ble_sub_3c008   @ 0x0003c008   (160 bytes)
 * called by : ble_sub_28ac0
 * calls     : rf24_sub_375fe, ble_sub_39bcc, ble_sub_39c02, ble_sub_3aad4, ble_sub_3af2c, ble_sub_3b47e, ... (+5 more)
 */

void ble_sub_3c008(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (*ble_ro_3c0e0 == '\0') {
    ble_sub_3b47e();
  }
  else {
    ble_sub_3af2c();
  }
  puVar1 = shared_ro_3c0dc;
  uVar3 = *(uint *)(shared_ro_3c0dc + 8);
  ble_sub_39c02(0x13);
  if ((int)(uVar3 << 0x1d) < 0) {
    uVar2 = 4;
    ble_sub_3c438();
  }
  if ((int)(uVar3 << 0x1c) < 0) {
    uVar2 = uVar2 | 8;
    ble_sub_3c48c();
  }
  if ((int)(uVar3 << 0x1a) < 0) {
    uVar2 = uVar2 | 0x20;
    uart2_isr();
  }
  if ((int)(uVar3 << 0x17) < 0) {
    uVar2 = uVar2 | 0x100;
    ble_sub_3b5e6();
  }
  if ((int)(uVar3 << 0x13) < 0) {
    uVar2 = uVar2 | 0x1000;
    ble_sub_3bf40();
  }
  if ((int)(uVar3 << 0x16) < 0) {
    uVar2 = uVar2 | 0x200;
    ble_sub_39bcc();
  }
  if ((int)(uVar3 << 0x19) < 0) {
    uVar2 = uVar2 | 0x40;
    ble_sub_3aad4();
  }
  if ((uVar3 & 1) != 0) {
    uVar2 = uVar2 | 1;
  }
  if ((int)(uVar3 << 0x1e) < 0) {
    uVar2 = uVar2 | 2;
  }
  if ((int)(uVar3 << 0xe) < 0) {
    uVar2 = uVar2 | 0x20000;
    rf24_sub_375fe();
  }
  *(uint *)(puVar1 + 8) = uVar2;
  ble_sub_39c02(0x14);
  return;
}

/* ==========================================================================
 * ble_sub_3c438   @ 0x0003c438   (84 bytes)
 * called by : ble_sub_3c008
 */

void ble_sub_3c438(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = shared_ro_3c4e4;
  puVar1 = shared_ro_3c4e0;
  iVar3 = *(int *)(shared_ro_3c4e4 + 0xc);
  if (iVar3 << 0x18 < 0) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 | 1;
    *(undefined4 *)puVar2 = *(undefined4 *)(puVar1 + 0x1c);
    if (*(code **)(puVar1 + 4) != (code *)0x0) {
      (**(code **)(puVar1 + 4))();
    }
  }
  if (iVar3 << 0x17 < 0) {
    *puVar1 = *puVar1 | 2;
    *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(puVar1 + 0x20);
    if (*(code **)(puVar1 + 8) != (code *)0x0) {
      (**(code **)(puVar1 + 8))();
    }
  }
  if (iVar3 << 0x16 < 0) {
    *puVar1 = *puVar1 | 4;
    *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar1 + 0x2c);
    if (*(code **)(puVar1 + 0xc) != (code *)0x0) {
      (**(code **)(puVar1 + 0xc))();
    }
  }
  *(int *)(puVar2 + 0xc) = iVar3;
  return;
}

/* ==========================================================================
 * ble_sub_3c48c   @ 0x0003c48c   (84 bytes)
 * called by : ble_sub_3c008
 */

void ble_sub_3c48c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = shared_ro_3c4e8;
  puVar1 = shared_ro_3c4e0;
  iVar3 = *(int *)(shared_ro_3c4e8 + 0xc);
  if (iVar3 << 0x18 < 0) {
    *shared_ro_3c4e0 = *shared_ro_3c4e0 | 0x10;
    *(undefined4 *)puVar2 = *(undefined4 *)(puVar1 + 0x24);
    if (*(code **)(puVar1 + 0x10) != (code *)0x0) {
      (**(code **)(puVar1 + 0x10))();
    }
  }
  if (iVar3 << 0x17 < 0) {
    *puVar1 = *puVar1 | 0x20;
    *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(puVar1 + 0x28);
    if (*(code **)(puVar1 + 0x14) != (code *)0x0) {
      (**(code **)(puVar1 + 0x14))();
    }
  }
  if (iVar3 << 0x16 < 0) {
    *puVar1 = *puVar1 | 0x40;
    *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar1 + 0x30);
    if (*(code **)(puVar1 + 0x18) != (code *)0x0) {
      (**(code **)(puVar1 + 0x18))();
    }
  }
  *(int *)(puVar2 + 0xc) = iVar3;
  return;
}

/* ==========================================================================
 * ble_sub_3c52e   @ 0x0003c52e   (6 bytes)
 * called by : ble_sub_2f31c
 */

void ble_sub_3c52e(undefined4 param_1)

{
  *(undefined4 *)(shared_ro_3c804 + 0x10) = param_1;
  return;
}

/* ==========================================================================
 * ble_sub_3c574   @ 0x0003c574   (6 bytes)
 * called by : ble_sub_2f31c
 */

undefined4 ble_sub_3c574(void)

{
  return *(undefined4 *)(shared_ro_3c804 + 0x10);
}

/* ==========================================================================
 * ble_sub_3c6ce   @ 0x0003c6ce   (106 bytes)
 * called by : ble_sub_2f31c
 * calls     : rom_24F24, rom_ro_1804c
 */

void ble_sub_3c6ce(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined *puVar1;
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
  rom_ro_1804c(&local_18);
  iVar2 = ble_ro_3c810;
  puVar1 = shared_ro_3c804;
  uVar4 = local_18 >> 1;
  uVar3 = *(uint *)shared_ro_3c804;
  if (uVar4 != uVar3) {
    if (uVar3 < uVar4) {
      uVar3 = uVar4 - uVar3;
    }
    else {
      uVar3 = (uVar4 - uVar3) + ble_ro_3c80c;
    }
    *(uint *)shared_ro_3c804 = uVar4;
    for (; (uint)-iVar2 < uVar3; uVar3 = uVar3 + iVar2) {
      iVar5 = iVar5 + ble_ro_3c814;
    }
    uVar3 = uVar3 * 5 + *(int *)(puVar1 + 4);
    iVar5 = (uVar3 >> 3) + iVar5;
    *(uint *)(puVar1 + 4) = uVar3 & 7;
    if (iVar5 != 0) {
      uVar3 = iVar5 * 100 + *(int *)(puVar1 + 8);
      *(uint *)(puVar1 + 8) = uVar3;
      if (*(uint *)(puVar1 + 0x14) <= uVar3) {
        uVar6 = rom_24F24();
        *(int *)(puVar1 + 8) = (int)((ulonglong)uVar6 >> 0x20);
        *(int *)(puVar1 + 0x10) = (int)uVar6 + *(int *)(puVar1 + 0x10);
      }
    }
  }
  return;
}

/* ==========================================================================
 * CHRG   @ 0x0003cfb8   (46 bytes)
 * called by : usb_sub_3d2b0, LightUp_Mode_Led, Success_led_2second, f_usb_isConnected
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
  
  if (*shared_ro_3d0bc == '\0') {
    cVar1 = *shared_ro_3d0c8;
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
 * ReLink   @ 0x0003cfe6   (38 bytes)
 * called by : usb_sub_3d2b0, Success_led_2second, f_reconnect_24G
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
  
  if ((((*shared_ro_3d0bc == '\0') && (cVar1 = *shared_ro_3d0c8, cVar1 != '\0')) && (cVar1 != '\x01')) &&
     (cVar1 != '\x02')) {
    pcVar2 = str_CHRG_2;
  }
  else {
    pcVar2 = str_ReLink_OK;
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
 * ReLinking   @ 0x0003d00c   (38 bytes)
 * called by : led_sub_32942, usb_sub_3d2b0, set_Update_OLED
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
  
  if ((((*shared_ro_3d0bc == '\0') && (cVar1 = *shared_ro_3d0c8, cVar1 != '\0')) && (cVar1 != '\x01')) &&
     (cVar1 != '\x02')) {
    pcVar2 = str_CHRG;
  }
  else {
    pcVar2 = str_ReLinking;
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
 * Pairing   @ 0x0003d032   (48 bytes)
 * called by : led_sub_32942, usb_sub_3d2b0, set_Update_OLED
 * calls     : input_sub_3cd24
 * string    : "CHRG     "
 * string    : "Pairing  "
 * string    : "Linking  "
 */

void Pairing(void)

{
  char cVar1;
  char *pcVar2;
  
  if (*shared_ro_3d0bc == '\0') {
    cVar1 = *shared_ro_3d0c8;
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
  input_sub_3cd24(0,1,1,pcVar2);
  return;
}

/* ==========================================================================
 * Linking   @ 0x0003d5be   (30 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : input_sub_3cd24
 * string    : "Linking  "
 */

void Linking(void)

{
  input_sub_3cd24(0x48,1,2,shared_ro_3d6c8 + -0xc);
  input_sub_3cd24(0,1,1,ble_ro_3d6d4);
  return;
}

/* ==========================================================================
 * ble_sub_3dc3c   @ 0x0003dc3c   (66 bytes)
 * called by : ble_sub_3dfd2, rwip_driver_init
 * calls     : rom_074A0, rom_07806, rom_0C1CA, rom_1169A, rom_24F8A, rom_ro_1804c
 */

void ble_sub_3dc3c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int local_10;
  int local_c;
  
  local_10 = param_3;
  local_c = param_4;
  if (param_1 == 0) {
    rom_ro_1804c(&local_10);
    rom_24F8A(local_c + local_10);
  }
  rom_074A0(param_1);
  rom_0C1CA(param_1);
  rom_07806(param_1);
  rom_1169A(param_1);
  if (param_1 != 0) {
    *(uint *)shared_ro_3dccc = *(uint *)shared_ro_3dccc & 0xfffffeff | 0x100;
  }
  return;
}

/* ==========================================================================
 * ble_sub_3dcb0   @ 0x0003dcb0   (18 bytes)
 * called by : ble_sub_3e304
 */

void ble_sub_3dcb0(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3dccc;
  *(undefined4 *)ble_ro_3dcf4 = *(undefined4 *)(shared_ro_3dccc + 0xc);
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x14) = 0xffffffff;
  return;
}

/* ==========================================================================
 * ble_sub_3dcf8   @ 0x0003dcf8   (8 bytes)
 * called by : ble_sub_3e304
 */

int ble_sub_3dcf8(int param_1)

{
  return param_1 * 10 + -1;
}

/* ==========================================================================
 * ble_sub_3dd00   @ 0x0003dd00   (28 bytes)
 * called by : ble_sub_3e0bc, rf24_sub_3e1ec
 * calls     : rom_15C40
 */

void ble_sub_3dd00(void)

{
  *(undefined4 *)ble_ro_3e100 = 0xffffffff;
  reg_820018 = reg_820018 & 0xffffffef;
  rom_15C40();
  return;
}

/* ==========================================================================
 * ble_sub_3dd1c   @ 0x0003dd1c   (30 bytes)
 * called by : ble_sub_3e0bc, rf24_sub_3e1ec
 * calls     : rom_06B28
 */

void ble_sub_3dd1c(void)

{
  *(undefined4 *)(ble_ro_3e100 + 8) = 0xffffffff;
  reg_820018 = reg_820018 & 0xffffffbf;
  rom_06B28(3);
  return;
}

/* ==========================================================================
 * ble_sub_3dd3a   @ 0x0003dd3a   (28 bytes)
 * called by : ble_sub_3e0bc, rf24_sub_3e1ec
 * calls     : rom_16216
 */

void ble_sub_3dd3a(void)

{
  *(undefined4 *)(ble_ro_3e100 + 4) = 0xffffffff;
  reg_820018 = reg_820018 & 0xffffffdf;
  rom_16216();
  return;
}

/* ==========================================================================
 * ble_sub_3dd8e   @ 0x0003dd8e   (350 bytes)
 * called by : ble_sub_3dfd2, rwip_driver_init
 * calls     : ble_sub_3e432, rom_06B14, rom_18074
 */

/* WARNING: Removing unreachable block (ram,0x0003dee4) */
/* WARNING: Removing unreachable block (ram,0x0003ddde) */

void ble_sub_3dd8e(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
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
    rom_06B14(1,ble_ro_3e108);
  }
  puVar1 = ble_ro_3e100;
  *(undefined2 *)(ble_ro_3e100 + 0x16) = 0;
  *(undefined4 *)(puVar1 + 8) = 0xffffffff;
  *(undefined4 *)puVar1 = 0xffffffff;
  *(undefined4 *)(puVar1 + 4) = 0xffffffff;
  puVar1 = ble_ro_3e110;
  if (param_1 != 0) {
    do {
    } while( true );
  }
  local_2c[0] = 1;
  reg_820018 = ble_ro_3e10c;
  local_28 = 1;
  (**(code **)ble_ro_3e110)(0x12,local_2c,local_24);
  puVar2 = ble_ro_3e100;
  local_24[0] = 1;
  ble_ro_3e100[0x18] = 1;
  local_2c[0] = 2;
  iVar3 = (**(code **)puVar1)(0x2e,local_2c,puVar2 + 0x14);
  if (iVar3 != 0) {
    *(undefined2 *)(puVar2 + 0x14) = 400;
  }
  *(undefined4 *)(puVar2 + 0xc) = 0;
  local_2c[0] = 2;
  iVar3 = (**(code **)puVar1)(0xf,local_2c,local_34);
  if (iVar3 != 0) {
    local_34[0] = (ushort)ble_ro_3e114;
  }
  local_2c[0] = 2;
  iVar3 = (**(code **)puVar1)(0xe,local_2c,local_1c);
  if (iVar3 != 0) {
    local_1c[0] = 2000;
  }
  local_2c[0] = 2;
  iVar3 = (**(code **)puVar1)(0xd,local_2c,local_40);
  if (iVar3 != 0) {
    local_40[0] = (undefined2)ble_ro_3e114;
  }
  local_34[0] = ble_sub_3e432(local_34[0]);
  local_1c[0] = ble_sub_3e432(local_1c[0]);
  uVar4 = ble_sub_3e432(local_40[0]);
  uVar5 = uVar4 & 0xffff;
  uVar6 = (uint)local_1c[0];
  reg_82003c = uVar4 << 0x15 | uVar6 << 10 | uVar5;
  if (uVar5 <= local_34[0]) {
    uVar5 = (uint)local_34[0];
  }
  if (uVar6 < uVar5) {
    uVar6 = uVar5;
  }
  *(uint *)(puVar2 + 0x10) = uVar6;
  reg_820030 = reg_820030 & 0x7fffffff | (uint)(puVar2[0x18] == '\0') << 0x1f;
  return;
}

/* ==========================================================================
 * rwip_driver_init   @ 0x0003deee   (228 bytes)
 * called by : TEST_SINGLE_WAVE, enter_BLE_normal_app_mode
 * calls     : ble_sub_28c48, ble_sub_29164, ble_sub_29530, ble_sub_3a244, ble_sub_3dc3c, ble_sub_3dd8e, ... (+14 more)
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
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  reg_80000c = reg_80000c & 0xfffdffff;
  ble_ro_3e118[1] = 0;
  puVar1 = ble_ro_3e110;
  *(undefined **)ble_ro_3e110 = ble_ro_3e11c;
  *(undefined **)(puVar1 + 4) = ble_ro_3e120;
  *(undefined **)(puVar1 + 8) = ble_ro_3e124;
  rom_06A88();
  rom_06BF8(0,ble_ro_3e128,0x314);
  rom_06BF8(1,ble_ro_3e130,ble_ro_3e12c);
  rom_06BF8(2,ble_ro_3e138,ble_ro_3e134);
  rom_06BF8(3,ble_ro_3e13c,0x29c);
  ble_sub_3a244(ble_ro_3e140);
  rom_0626C(0);
  uVar2 = ble_sub_29164(0);
  rom_0692C(0,uVar2);
  dbg_printf(str_h4tl_init_1_ok);
  rom_1477C(0);
  dbg_printf(str_hci_init_ok);
  rom_24F08(0);
  dbg_printf(str_rwble_hl_init_ok);
  ble_sub_3dc3c(0);
  dbg_printf(str_rwble_init_ok);
  rom_16CAC(0);
  dbg_printf(str_aes_init_ok);
  rom_15F90(0);
  rom_16930(0);
  rom_16508(0);
  rom_15C36(0);
  rom_16BCE(0);
  ble_sub_3dd8e(0);
  dbg_printf(str_rwip_driver_init_ok);
  iVar3 = ble_sub_28c48();
  if (iVar3 == 0) {
    ble_sub_29530();
    dbg_printf(str_appm_init_ok);
  }
  KEY_piaring_cnt();
  return;
}

/* ==========================================================================
 * ble_sub_3dfd2   @ 0x0003dfd2   (108 bytes)
 * calls     : ble_sub_3dc3c, ble_sub_3dd8e, rom_0626C, rom_06AB4, rom_1477C, rom_15C36, ... (+10 more)
 */

void ble_sub_3dfd2(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = rom_25024();
  iVar2 = rom_25038();
  rom_06AB4();
  rom_0626C(1);
  rom_1477C(1);
  rom_24F08(1);
  ble_sub_3dc3c(1);
  rom_16CAC(1);
  rom_15F90(1);
  rom_16930(1);
  rom_16508(1);
  rom_15C36(1);
  rom_16BCE(1);
  ble_sub_3dd8e(1);
  (**(code **)ble_ro_3e140)();
  if (iVar1 == 0) {
    rom_2504C();
  }
  if (iVar2 == 0) {
    rom_2505C();
  }
  return;
}

/* ==========================================================================
 * ble_sub_3e03e   @ 0x0003e03e   (16 bytes)
 * called by : ble_sub_28c4e, ble_sub_28c66
 * calls     : rom_06BCE
 */

void ble_sub_3e03e(void)

{
  if ((ble_ro_3e100[0x16] & 1) == 0) {
    rom_06BCE();
  }
  return;
}

/* ==========================================================================
 * ble_sub_3e0bc   @ 0x0003e0bc   (94 bytes)
 * called by : rf24_sub_3e1ec
 * calls     : ble_sub_3dd00, ble_sub_3dd1c, ble_sub_3dd3a, rom_1809E, rom_ro_1804c
 */

void ble_sub_3e0bc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint uVar2;
  uint local_18;
  undefined4 uStack_14;
  
  local_18 = param_3;
  uStack_14 = param_4;
  rom_ro_1804c(&local_18);
  reg_820018 = reg_820018 & 0xfffffffe;
  if (*(code **)(ble_ro_3e1cc + 0x20) != (code *)0x0) {
    (**(code **)(ble_ro_3e1cc + 0x20))();
  }
  puVar1 = ble_ro_3e100;
  reg_820018 = ble_ro_3e10c;
  if (*(int *)ble_ro_3e100 != -1) {
    ble_sub_3dd00();
  }
  if (*(int *)(puVar1 + 4) != -1) {
    ble_sub_3dd3a();
  }
  uVar2 = *(uint *)(puVar1 + 8);
  if (uVar2 != 0xffffffff) {
    if (local_18 < uVar2) {
      reg_820018 = reg_820018 & 0xffffffbf | 0x40;
    }
    else {
      ble_sub_3dd1c();
    }
  }
  rom_1809E(1);
  return;
}

/* ==========================================================================
 * ble_sub_3e268   @ 0x0003e268   (44 bytes)
 * called by : ble_sub_3e304
 * calls     : rom_ro_1804c
 */

undefined4 ble_sub_3e268(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint local_10;
  undefined4 uStack_c;
  
  local_10 = param_3;
  uStack_c = param_4;
  rom_ro_1804c(&local_10);
  uVar1 = *(uint *)(shared_ro_3e448 + 4);
  if (uVar1 < local_10) {
    if (&rom_ro_4b00 < (undefined *)(local_10 - uVar1)) {
      *(uint *)(shared_ro_3e448 + 4) = local_10;
      return 1;
    }
  }
  else if (local_10 < uVar1) {
    *(uint *)(shared_ro_3e448 + 4) = local_10;
  }
  return 0;
}

/* ==========================================================================
 * RC32K_2   @ 0x0003e294   (24 bytes)
 * called by : ble_sub_3e304
 * calls     : ble_sub_3a688, dbg_printf
 * string    : "RC32K-Cali.Start\n"
 */

void RC32K_2(void)

{
  undefined *puVar1;
  
  puVar1 = shared_ro_3e448;
  *shared_ro_3e448 = 1;
  dbg_printf(str_RC32K_Cali_Start);
  ble_sub_3a688();
  *puVar1 = 2;
  return;
}

/* ==========================================================================
 * ble_sub_3e304   @ 0x0003e304   (300 bytes)
 * called by : ble_sub_28c66
 * calls     : ble_sub_3dcb0, ble_sub_3dcf8, ble_sub_3e268, RC32K, RC32K_2, rom_069DC, ... (+3 more)
 */

undefined8 ble_sub_3e304(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int local_20;
  int local_1c;
  undefined4 uStack_18;
  
  puVar2 = shared_ro_3e444;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  if (((shared_ro_3e444[0x16] & 1) == 0) && (iVar3 = rom_06AF0(), iVar3 == 0)) {
LAB_0003e3e6:
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
    uVar1 = (ushort)ble_ro_3e484;
    if ((int)((uint)*(ushort *)(puVar2 + 0x16) << 0x12) < 0) {
      iVar3 = RC32K();
      if (iVar3 != 0) {
        *(ushort *)(puVar2 + 0x16) = *(ushort *)(puVar2 + 0x16) & ~uVar1;
        goto LAB_0003e330;
      }
    }
    else {
LAB_0003e330:
      if (*(short *)(puVar2 + 0x16) != 0) goto LAB_0003e42e;
      rom_ro_1804c(&local_20);
      uVar4 = local_20 + 1;
      if (0x270U - local_1c < (uint)*(ushort *)(puVar2 + 0x14)) {
        uVar4 = local_20 + 2;
      }
      uVar4 = uVar4 & 0xfffffff;
      puVar5 = ble_ro_3e488;
      if (puVar2[0x18] == '\0') {
        puVar5 = (undefined *)0x12c0;
      }
      iVar3 = *(int *)(puVar2 + 8);
      if (iVar3 != -1) {
        puVar6 = (undefined *)(iVar3 - uVar4 & 0xfffffff);
        if (ble_ro_3e48c < puVar6) {
          puVar6 = (undefined *)-(uVar4 - iVar3 & 0xfffffff);
        }
        if ((int)puVar6 <= (int)puVar5) {
          puVar5 = puVar6;
        }
      }
      iVar3 = *(int *)puVar2;
      if (iVar3 != -1) {
        puVar6 = (undefined *)(iVar3 - uVar4 & 0xfffffff);
        if (ble_ro_3e48c < puVar6) {
          puVar6 = (undefined *)-(uVar4 - iVar3 & 0xfffffff);
        }
        if ((int)puVar6 <= (int)puVar5) {
          puVar5 = puVar6;
        }
      }
      iVar3 = *(int *)(puVar2 + 4);
      if (iVar3 != -1) {
        puVar6 = (undefined *)(iVar3 - uVar4 & 0xfffffff);
        if (ble_ro_3e48c < puVar6) {
          puVar6 = (undefined *)-(uVar4 - iVar3 & 0xfffffff);
        }
        if ((int)puVar6 <= (int)puVar5) {
          puVar5 = puVar6;
        }
      }
      if (((int)puVar5 < 9) ||
         (uVar4 = ble_sub_3dcf8(puVar5 + -8),
         uVar4 <= (uint)(*(int *)(puVar2 + 0x10) * 2) && *(int *)(puVar2 + 0x10) * 2 - uVar4 != 0))
      goto LAB_0003e42e;
      iVar3 = ble_sub_3e268();
      if (iVar3 != 0) {
        *(ushort *)(puVar2 + 0x16) = *(ushort *)(puVar2 + 0x16) | uVar1;
        RC32K_2();
        goto LAB_0003e3e6;
      }
      iVar3 = rom_069DC();
      if (iVar3 != 0) {
        uVar7 = 2;
        ble_sub_3dcb0();
        reg_820018 = 2;
        reg_820020 = 0xffffffff;
        if (puVar2[0x18] == '\0') {
          reg_820030 = reg_820030 & 0x7fffffff | 0x80000000;
        }
        reg_820034 = uVar4;
        (**(code **)(ble_ro_3e490 + 0x28))();
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
 * ble_sub_3e432   @ 0x0003e432   (16 bytes)
 * called by : ble_sub_3dd8e
 * calls     : rom_24F24
 */

void ble_sub_3e432(int param_1)

{
  rom_24F24(param_1 * 0x20 + ble_ro_3e494,ble_ro_3e494 + 1);
  return;
}

/* ==========================================================================
 * ble_sub_3e498   @ 0x0003e498   (58 bytes)
 * called by : ble_sub_3e5f0, ble_sub_3e6e2, ble_sub_3e732
 */

undefined8 ble_sub_3e498(int param_1,char *param_2,int *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = ble_ro_3e794;
  uVar3 = 0;
  iVar4 = param_1;
  (**(code **)ble_ro_3e794)(param_1,3,param_2,*(code **)ble_ro_3e794,param_1,param_2);
  if (*param_2 == -1) {
    uVar3 = 2;
  }
  else {
    iVar2 = (uint)(byte)param_2[2] + param_1 + 3;
    *param_3 = iVar2;
    if (*(int *)(puVar1 + 0x10) - 1U < iVar2 - 0x7f000U) {
      uVar3 = 6;
    }
  }
  return CONCAT44(iVar4,uVar3);
}

/* ==========================================================================
 * ble_sub_3e516   @ 0x0003e516   (60 bytes)
 * called by : enter_BLE_normal_app_mode
 * calls     : flash_sub_3e4d2, ble_sub_3e716, rom_25002
 */

undefined4 ble_sub_3e516(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 in_r3;
  undefined4 uStack_10;
  
  puVar2 = ble_ro_3e798;
  puVar1 = ble_ro_3e794;
  *(undefined4 *)(ble_ro_3e794 + 0xc) = 0;
  *(undefined **)puVar1 = puVar2;
  *(undefined **)(puVar1 + 4) = ble_ro_3e79c;
  *(undefined **)(puVar1 + 8) = ble_ro_3e7a0;
  *(undefined4 *)(puVar1 + 0x10) = 0x438;
  uStack_10 = in_r3;
  flash_sub_3e4d2(0x7f000,4,&uStack_10);
  iVar3 = rom_25002(&uStack_10,ble_ro_3e7a4,4);
  if (iVar3 != 0) {
    ble_sub_3e716();
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_3e552   @ 0x0003e552   (62 bytes)
 * called by : flash_sub_29988, flash_sub_29a04, ble_sub_2a0c0, ble_sub_2c378, ble_sub_2d53c, usb_sub_39cfc, ... (+9 more)
 * calls     : ble_sub_3e6e2
 */

int ble_sub_3e552(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  int local_28 [3];
  undefined1 auStack_1c [2];
  byte local_1a;
  
  iVar1 = ble_sub_3e6e2(param_1,auStack_1c,local_28);
  if (iVar1 == 0) {
    if (*param_2 < local_1a) {
      return 4;
    }
    (**(code **)ble_ro_3e794)(local_28[0] + 3,local_1a,param_3);
  }
  else {
    local_1a = 0;
  }
  *param_2 = local_1a;
  return iVar1;
}

/* ==========================================================================
 * ble_sub_3e590   @ 0x0003e590   (52 bytes)
 * calls     : ble_sub_3e6e2
 */

undefined8 ble_sub_3e590(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uStack_18;
  int local_14;
  uint local_10;
  
  uStack_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  iVar1 = ble_sub_3e6e2(param_1,&uStack_18,&local_14);
  if (iVar1 == 0) {
    if ((int)((uint)uStack_18._1_1_ << 0x1e) < 0) {
      local_10 = CONCAT31(local_10._1_3_,uStack_18._1_1_) & 0xfffffffb;
      (**(code **)(ble_ro_3e794 + 4))(local_14 + 1,1,&local_10);
    }
    else {
      iVar1 = 5;
    }
  }
  return CONCAT44(uStack_18,iVar1);
}

/* ==========================================================================
 * ble_sub_3e5c4   @ 0x0003e5c4   (44 bytes)
 * calls     : ble_sub_3e6e2
 */

undefined8 ble_sub_3e5c4(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  
  uStack_18 = param_2;
  iStack_14 = param_3;
  uStack_10 = param_4;
  iVar1 = ble_sub_3e6e2(param_1,&uStack_18,&iStack_14);
  if (iVar1 == 0) {
    uStack_10 = CONCAT31(uStack_10._1_3_,uStack_18._1_1_) & 0xfffffffd;
    (**(code **)(ble_ro_3e794 + 4))(iStack_14 + 1,1,&uStack_10);
  }
  return CONCAT44(uStack_18,iVar1);
}

/* ==========================================================================
 * ble_sub_3e5f0   @ 0x0003e5f0   (242 bytes)
 * called by : rf24_sub_29ab0, rf24_sub_29ed8, rf24_sub_29ef2, ble_sub_2a0aa, ble_sub_2b8a2, ble_sub_2d53c, ... (+7 more)
 * calls     : ble_sub_3e498, ble_sub_3e732, KEY_piaring_cnt, rom_25002
 */

undefined4 ble_sub_3e5f0(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined *puVar1;
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
  
  puVar1 = ble_ro_3e794;
  iVar4 = 0;
  local_564 = ble_ro_3e7a8;
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  while( true ) {
    while( true ) {
      do {
        KEY_piaring_cnt();
        iVar3 = local_564;
        iVar2 = ble_sub_3e498(local_564,&local_568,&local_564);
        if (iVar2 != 0) {
          if (*(int *)(puVar1 + 0x10) - 1U < iVar3 + param_2 + ble_ro_3e7ac) {
            ble_sub_3e732(iVar4,auStack_55c);
            iVar3 = iVar4 + ble_ro_3e7a8;
            if (*(int *)(puVar1 + 0x10) - 1U < iVar3 + param_2 + ble_ro_3e7ac + -3) {
              return 3;
            }
          }
          (**(code **)(puVar1 + 4))
                    (iVar3 + 3,param_2,*(undefined4 *)((int)auStack_520 + ble_ro_3e7b0 + 8));
          local_568 = (byte)*(undefined4 *)((int)auStack_520 + ble_ro_3e7b0);
          local_567 = 6;
          local_566 = (byte)param_2;
          (**(code **)(puVar1 + 4))(iVar3,3,&local_568);
          return 0;
        }
      } while ((local_567 & 5) != 4);
      if ((uint)local_568 == *(uint *)((int)auStack_520 + ble_ro_3e7b0)) break;
      iVar4 = (uint)local_566 + iVar4 + 3;
    }
    if (-1 < (int)((uint)local_567 << 0x1e)) break;
    (**(code **)puVar1)(iVar3 + 3,local_566,auStack_124);
    if ((local_566 == param_2) && (iVar2 = rom_25002(local_18), iVar2 == 0)) {
      return 0;
    }
    local_560[0] = local_567 & 0xfb;
    (**(code **)(puVar1 + 4))(iVar3 + 1,1,local_560);
  }
  return 5;
}

/* ==========================================================================
 * ble_sub_3e6e2   @ 0x0003e6e2   (52 bytes)
 * called by : ble_sub_3e552, ble_sub_3e590, ble_sub_3e5c4
 * calls     : ble_sub_3e498
 */

void ble_sub_3e6e2(uint param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28 [2];
  uint uStack_20;
  byte *pbStack_1c;
  undefined4 *local_18;
  
  local_28[0] = ble_ro_3e7a8;
  uStack_20 = param_1;
  pbStack_1c = param_2;
  local_18 = param_3;
  do {
    uVar1 = local_28[0];
    iVar2 = ble_sub_3e498(local_28[0],param_2,local_28);
    if (iVar2 != 0) break;
  } while ((*param_2 != param_1) || ((param_2[1] & 5) != 4));
  *local_18 = uVar1;
  return;
}

/* ==========================================================================
 * ble_sub_3e716   @ 0x0003e716   (28 bytes)
 * called by : ble_sub_3e516, ble_sub_3e732
 */

void ble_sub_3e716(void)

{
  undefined *puVar1;
  
  puVar1 = ble_ro_3e794;
  (**(code **)(ble_ro_3e794 + 8))(0x7f000,*(undefined4 *)(ble_ro_3e794 + 0x10));
  (**(code **)(puVar1 + 4))(0x7f000,4,ble_ro_3e7a4);
  return;
}

/* ==========================================================================
 * ble_sub_3e732   @ 0x0003e732   (96 bytes)
 * called by : ble_sub_3e5f0
 * calls     : ble_sub_3e498, ble_sub_3e716, rom_24F9C
 */

void ble_sub_3e732(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack_28;
  byte local_27;
  byte local_26;
  int local_24 [2];
  undefined4 uStack_1c;
  int local_18;
  
  puVar1 = ble_ro_3e794;
  iVar4 = 0;
  local_24[0] = ble_ro_3e7a8;
  uStack_1c = param_1;
  local_18 = param_2;
  while( true ) {
    iVar2 = local_24[0];
    iVar3 = ble_sub_3e498(local_24[0],&uStack_28,local_24);
    if (iVar3 != 0) break;
    if ((local_27 & 5) == 4) {
      iVar4 = (uint)local_26 + iVar4 + 3;
      rom_24F9C(param_2,&uStack_28,3);
      (**(code **)puVar1)(iVar2 + 3,local_26,param_2 + 3);
      param_2 = (uint)local_26 + param_2 + 3;
    }
  }
  ble_sub_3e716();
  (**(code **)(puVar1 + 4))(ble_ro_3e7a8,iVar4,local_18);
  return;
}

/* ==========================================================================
 * prf_register_atthdl2gatt   @ 0x0003e800   (84 bytes)
 * called by : ota_sub_41f62
 * calls     : ota_sub_3ee1a, dbg_printf, rom_06EF4, rom_06F26
 * string    : "prf_register_atthdl2gatt,svc->shdl=%x,%x\n"
 * string    : "~~~~~~~~~dest=%x,~~~~~~~~~src=%x,%x\n"
 */

void prf_register_atthdl2gatt(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  dbg_printf(str_prf_register_atthdl2gatt_svc_shdl_x_x,*(undefined2 *)(param_3 + 0x14),
             *(undefined2 *)(param_3 + 0x16),param_4,param_4);
  uVar1 = ota_sub_3ee1a(param_1,param_2);
  dbg_printf(str_dest_x_src_x_x,param_2 * 0x100 + 6,uVar1);
  if (*(short *)(param_3 + 0x14) != 0) {
    uVar1 = ota_sub_3ee1a(param_1,param_2);
    puVar2 = (undefined1 *)rom_06EF4(ota_ro_3ebc0 + 7,param_2 * 0x100 + 6,uVar1,8);
    *puVar2 = 0x10;
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(param_3 + 0x14);
    *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_3 + 0x16);
    rom_06F26();
  }
  return;
}

/* ==========================================================================
 * ble_sub_3e958   @ 0x0003e958   (30 bytes)
 * called by : ble_sub_420ee, ble_sub_42132
 * calls     : ota_sub_3e902
 */

undefined8 ble_sub_3e958(void)

{
  ota_sub_3e902();
  return 0xc00000002;
}

/* ==========================================================================
 * ble_sub_3edee   @ 0x0003edee   (44 bytes)
 * called by : ble_sub_3f25e, ble_sub_3f3b0, ble_sub_3f46a, ble_sub_3f86c, ble_sub_3faaa, ble_sub_3fb6a, ... (+16 more)
 */

undefined4 ble_sub_3edee(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(ushort *)(shared_ro_3eeb8 + uVar1 * 0x18 + 0x12) == param_1) {
      return *(undefined4 *)(shared_ro_3eeb8 + uVar1 * 0x18 + 0xc);
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return 0;
}

/* ==========================================================================
 * ble_sub_3ee6e   @ 0x0003ee6e   (52 bytes)
 * called by : ble_sub_2bf30, ble_sub_2bf5c, ble_sub_2bf88, led_sub_2c124, ble_sub_2c158, ble_sub_2ca56, ... (+8 more)
 */

uint ble_sub_3ee6e(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  uVar1 = 0;
  do {
    if ((uint)*(ushort *)(shared_ro_3eeb8 + uVar1 * 0x18 + 0x12) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(shared_ro_3eeb8 + uVar1 * 0x18 + 0x10);
      break;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return param_1 & 0xffffff00 | uVar2;
}

/* ==========================================================================
 * ble_sub_3ef20   @ 0x0003ef20   (40 bytes)
 * called by : ble_sub_3ef48
 */

uint ble_sub_3ef20(uint param_1)

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
 * ble_sub_3ef48   @ 0x0003ef48   (126 bytes)
 * calls     : ble_sub_3ef20, ble_sub_3f25e, rom_06D2C, rom_07180, rom_179A0, rom_1F06A
 */

int ble_sub_3ef48(int param_1,ushort *param_2,undefined4 param_3,uint param_4,ushort *param_5)

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
  local_28 = ble_sub_3ef20(*param_5);
  iVar2 = rom_1F06A(local_20,ble_ro_3f094,&local_28,0x13,0,*(undefined2 *)(param_1 + 0x10),shared_ro_3f090,
                    param_4 & 0x1e);
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
    ble_sub_3f25e(param_1);
    rom_179A0(puVar3 + 2);
    rom_07180(*(undefined2 *)(param_1 + 0x10),0);
  }
  return iVar2;
}

/* ==========================================================================
 * ble_sub_3f25e   @ 0x0003f25e   (26 bytes)
 * called by : ble_sub_3ef48
 * calls     : ble_sub_3edee
 */

void ble_sub_3f25e(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x14);
  *param_1 = ble_ro_3f284;
  *(undefined2 *)((int)param_1 + 10) = 3;
  param_1[1] = iVar1 + 0x12;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_3f3b0   @ 0x0003f3b0   (28 bytes)
 * called by : ota_sub_3f3cc, ota_sub_3f418
 * calls     : ble_sub_3edee
 */

uint ble_sub_3f3b0(uint param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x47);
  if (param_1 < 0xe) {
    return *(ushort *)(iVar1 + 0x10) + param_1 & 0xffff;
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_3f46a   @ 0x0003f46a   (32 bytes)
 * called by : gattc_att_info_req_ind_handler_2
 * calls     : ble_sub_3edee
 */

undefined4 ble_sub_3f46a(uint param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ble_sub_3edee(0x47);
  uVar2 = 0x80;
  if (param_1 <= *(ushort *)(iVar1 + 0x10) + 0xd) {
    *param_2 = (char)param_1 - (char)*(ushort *)(iVar1 + 0x10);
    uVar2 = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * gattc_att_info_req_ind_handler_2   @ 0x0003f53a   (106 bytes)
 * calls     : ble_sub_3f46a, dbg_printf, rom_06EF4, rom_06F26
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
  iVar1 = ble_sub_3f46a(*param_2,local_28);
  dbg_printf(str_s_conidx_d_3,str_gattc_att_info_req_ind_handler,param_4 >> 8);
  puVar2 = (undefined2 *)rom_06EF4(ble_ro_3f8a0,local_18,local_1c,6);
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
 * ble_sub_3f86c   @ 0x0003f86c   (32 bytes)
 * calls     : ble_sub_3edee
 */

void ble_sub_3f86c(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x47);
  *param_1 = ble_ro_3f88c + -0x30;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + ble_ro_3f920;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_3f9a0   @ 0x0003f9a0   (286 bytes)
 * calls     : ble_sub_3ff92, rom_06DF6, rom_07180, rom_1F06A, rom_1F61C, rom_24F9C
 */

int ble_sub_3f9a0(void)

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
    puStack00000008 = shared_ro_3fce8;
    iVar2 = rom_1F06A(&stack0x00000024 + unaff_r5,ble_ro_3fcec,&stack0x00000018,5);
    if ((iVar2 == 0) &&
       (*in_stack_00000030 =
             (*(short *)((int)&stack0x00000024 + iStack0000001c) -
             (ushort)(in_stack_00000014[1] != 1)) + 5, in_stack_00000014[1] == 1)) {
      rom_1F61C(*(short *)((int)&stack0x00000024 + iStack0000001c) + 2,&rom_ro_1200,0);
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
    ble_sub_3ff92(in_stack_0000002c);
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
 * ble_sub_3faaa   @ 0x0003faaa   (122 bytes)
 * called by : ota_sub_3fb24
 * calls     : ble_sub_3edee
 */

uint ble_sub_3faaa(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = ble_sub_3edee(0x24);
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
 * ble_sub_3fb6a   @ 0x0003fb6a   (112 bytes)
 * called by : ble_sub_3fdd4
 * calls     : ble_sub_3edee
 */

undefined4 ble_sub_3fb6a(uint param_1,undefined1 *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = ble_sub_3edee(0x24);
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
 * ble_sub_3fd6e   @ 0x0003fd6e   (102 bytes)
 * calls     : ble_sub_3edee, ota_sub_3fbda, rom_06EF4, rom_06F26, rom_07180, rom_071EA
 */

undefined4 ble_sub_3fd6e(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 2;
  iVar1 = rom_071EA(param_3);
  if (iVar1 == 0) {
    iVar1 = ble_sub_3edee(0x24);
    if (((uint)*param_2 < (uint)*(byte *)(iVar1 + 0x1f)) && (param_2[1] < 0x65)) {
      *(byte *)((uint)*param_2 + iVar1 + 0x1a) = param_2[1];
      uVar3 = 1;
      rom_07180(param_3,1);
      *(byte **)(iVar1 + 0x14) = param_2 + -0xc;
      *(undefined1 *)(iVar1 + 0x20) = 0;
      ota_sub_3fbda();
    }
    else {
      puVar2 = (undefined1 *)rom_06EF4(ble_ro_3ffb4 + 2,param_4,param_3,1);
      *puVar2 = 0x81;
      rom_06F26();
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ==========================================================================
 * ble_sub_3fdd4   @ 0x0003fdd4   (78 bytes)
 * calls     : ble_sub_3fb6a, rom_06EF4, rom_06F26
 */

undefined4
ble_sub_3fdd4(undefined4 param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = ble_sub_3fb6a(*param_2,local_2c,local_30);
  puVar2 = (undefined2 *)rom_06EF4(ble_ro_3ffb8,local_18,param_3,6);
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
 * ble_sub_3ff92   @ 0x0003ff92   (26 bytes)
 * called by : ble_sub_3f9a0
 * calls     : ble_sub_3edee
 */

void ble_sub_3ff92(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x24);
  *param_1 = ble_ro_3ffbc;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + 0x1c;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_400c6   @ 0x000400c6   (28 bytes)
 * called by : ota_sub_400e2
 * calls     : ble_sub_3edee
 */

uint ble_sub_400c6(uint param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x48);
  if (param_1 < 6) {
    return *(ushort *)(iVar1 + 0x10) + param_1 & 0xffff;
  }
  return 0;
}

/* ==========================================================================
 * ble_sub_40134   @ 0x00040134   (30 bytes)
 * called by : gattc_att_info_req_ind_handler
 * calls     : ble_sub_3edee
 */

undefined4 ble_sub_40134(uint param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ble_sub_3edee(0x48);
  uVar2 = 0x80;
  if (param_1 <= *(ushort *)(iVar1 + 0x10) + 5) {
    *param_2 = (char)param_1 - (char)*(ushort *)(iVar1 + 0x10);
    uVar2 = 0;
  }
  return uVar2;
}

/* ==========================================================================
 * gattc_att_info_req_ind_handler   @ 0x000401aa   (98 bytes)
 * calls     : ble_sub_40134, dbg_printf, rom_06EF4, rom_06F26
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
  iVar1 = ble_sub_40134(*param_2,local_28);
  dbg_printf(str_s_conidx_d_4,str_gattc_att_info_req_ind_handler_2,param_4 >> 8);
  puVar2 = (undefined2 *)rom_06EF4(ble_ro_40434,local_18,local_1c,6);
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
 * ble_sub_40400   @ 0x00040400   (32 bytes)
 * calls     : ble_sub_3edee
 */

void ble_sub_40400(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x48);
  *param_1 = ble_ro_40420 + -0x28;
  *(undefined2 *)((int)param_1 + 10) = 5;
  param_1[1] = iVar1 + 0x112;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_405ae   @ 0x000405ae   (274 bytes)
 * called by : ble_sub_28c66
 * calls     : flash_sub_39708, ble_sub_3b538, dbg_printf, rom_24F24
 * string    : "BBBBwait for reset!!!\r\n"
 */

longlong ble_sub_405ae(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  
  puVar1 = shared_ro_40884;
  pcVar7 = (char *)(*(int *)(shared_ro_40884 + 0x14) + 0x52000);
  uVar5 = 0;
  iVar3 = *(int *)(shared_ro_40884 + 0x18) * 0x10;
  if (shared_ro_40884[0x1c] == '\x01') {
    pcVar6 = str_Img_Identify + *(int *)(shared_ro_40884 + 0x14) + 4;
    if (*(int *)(shared_ro_40890 + 0xc) == str_BBBBwait_for_reset._0_4_) {
      pcVar6 = pcVar7;
    }
    uVar8 = rom_24F24(iVar3,0x60);
    iVar4 = (int)((ulonglong)uVar8 >> 0x20);
    for (; uVar5 < (uint)uVar8; uVar5 = uVar5 + 1 & 0xff) {
      param_2 = 0;
      flash_sub_39708(0,pcVar6 + uVar5 * 0x60,0x60,puVar1 + uVar5 * 0x60 + 0x1e);
    }
    if (iVar4 != 0) {
      param_2 = 0;
      flash_sub_39708(0,pcVar6 + uVar5 * 0x60,iVar4,puVar1 + uVar5 * 0x60 + 0x1e);
    }
    puVar2 = shared_ro_40884;
    *(int *)(puVar1 + 0x14) = *(int *)(puVar1 + 0x14) + iVar3;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    puVar2[0x1c] = 0;
  }
  else if (shared_ro_40884[0x1c] == '\x02') {
    pcVar6 = str_Img_Identify + *(int *)(shared_ro_40884 + 0x14) + 4;
    if (*(int *)(shared_ro_40890 + 0xc) == str_BBBBwait_for_reset._0_4_) {
      pcVar6 = pcVar7;
    }
    uVar8 = rom_24F24(iVar3,0x60);
    iVar4 = (int)((ulonglong)uVar8 >> 0x20);
    for (uVar5 = 0; uVar5 < (uint)uVar8; uVar5 = uVar5 + 1 & 0xff) {
      flash_sub_39708(0,pcVar6 + uVar5 * 0x60,0x60,puVar1 + uVar5 * 0x60 + 0x1e,0);
    }
    if (iVar4 != 0) {
      flash_sub_39708(0,pcVar6 + uVar5 * 0x60,iVar4,puVar1 + uVar5 * 0x60 + 0x1e,0);
    }
    *(undefined4 *)(puVar1 + 0x18) = 0;
    *(int *)(puVar1 + 0x14) = *(int *)(puVar1 + 0x14) + iVar3;
    iVar3 = 0;
    do {
      dbg_printf(str_BBBBwait_for_reset + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    shared_ro_40884[0x1c] = 0;
    ble_sub_3b538(10);
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
  dbg_printf(&ble_ro_4102c,str_gattc_cmp_evt_handler_3);
  return 0;
}

/* ==========================================================================
 * ble_sub_40f74   @ 0x00040f74   (30 bytes)
 * calls     : ble_sub_3edee
 */

void ble_sub_40f74(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x49);
  *param_1 = ble_ro_40f94 + -0x30;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + 0x3c;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_41034   @ 0x00041034   (244 bytes)
 * called by : ble_sub_41160, usb_sub_4169a, ble_sub_41922, hogpd_proto_mode_cfm_handler
 */

uint ble_sub_41034(int param_1,uint param_2,uint param_3,uint param_4)

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
 * ble_sub_41160   @ 0x00041160   (992 bytes)
 * calls     : ble_sub_41034, ble_sub_41e78, rom_06D2C, rom_06DF6, rom_07180, rom_1F06A, ... (+3 more)
 */

int ble_sub_41160(void)

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
    rom_24F9C(*(undefined4 *)(&stack0x00000044 + iVar8),shared_ro_415b0,0x98);
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
                ble_ro_46720,0x20);
      bVar6 = in_stack_00000030[uVar10 + 4] & 3;
      if (bVar6 == 1) {
        if (*ble_ro_415b4 == '\0') {
          puVar7 = &rom_ro_1200;
        }
        else {
          puVar7 = &rom_ro_1a00;
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
    unaff_r5 = rom_1F06A(&stack0x00000024,ble_ro_415b8,&stack0x00000014 + uVar3 * 8,0x33);
    puVar1 = in_stack_00000028;
    in_stack_00000024 = (byte)in_stack_00000028[uVar3 * 4 + 4] + in_stack_00000024;
    if (unaff_r5 == 0) {
      uVar5 = ble_sub_41034(in_stack_00000028,uVar3,3,0);
      unaff_r5 = rom_1F3F6(uVar5,4,0,unaff_r7 + uVar3 * 0x1a + 0x14);
      if (unaff_r5 == 0) {
        if (-1 < (int)((uint)unaff_r7[uVar3 * 0x1a + 2] << 0x1c)) {
          uVar10 = 0;
          goto LAB_000414b6;
        }
        uVar5 = ble_sub_41034(in_stack_00000028,uVar3,8,0);
        unaff_r5 = rom_1F3F6(uVar5,2,0,unaff_r7 + uVar3 * 0x1a + 0x1a);
      }
    }
    uVar10 = 0;
    while (unaff_r5 == 0) {
LAB_000414b6:
      if (unaff_r7[uVar3 * 0x1a + 3] <= uVar10) break;
      bStack00000010 = unaff_r7[uVar10 + 0xc + uVar3 * 0x1a];
      bStack00000011 = unaff_r7[uVar10 + 4 + uVar3 * 0x1a] & 3;
      uVar5 = ble_sub_41034(in_stack_00000028,uVar3,0x15,uVar10);
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
    ble_sub_41e78(in_stack_0000005c);
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
 * ble_sub_41798   @ 0x00041798   (164 bytes)
 * calls     : ble_sub_3edee, ota_sub_3ee1a, ota_sub_3ee2a, rom_06EF4, rom_06F26
 */

undefined4 ble_sub_41798(int param_1,int param_2,int param_3,uint param_4,int param_5)

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
  iVar1 = ble_sub_3edee(0x26);
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
  uVar3 = ota_sub_3ee1a(iVar1,param_1);
  uVar4 = ota_sub_3ee2a(iVar1,param_1);
  puVar5 = (undefined1 *)rom_06EF4(ble_ro_4183c,uVar4,uVar3,6,uVar11,iVar8,param_2,iVar9);
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
 * ble_sub_41922   @ 0x00041922   (224 bytes)
 * calls     : ble_sub_3edee, ble_sub_41034, rom_06EF4, rom_06F26, rom_07180, rom_071EA, ... (+2 more)
 */

undefined4 ble_sub_41922(undefined4 param_1,char *param_2,undefined4 param_3)

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
  iVar4 = ble_sub_3edee(0x26);
  cVar7 = param_2[2];
  if (cVar7 == '\0') {
    cVar1 = *(char *)(iVar4 + 0x17);
    if ((param_2[1] != cVar1) || (*param_2 != *(char *)(iVar4 + 0x16))) goto LAB_00041998;
    rom_25078(param_2[5],*param_2,0,param_2[5]);
    cVar7 = '\0';
    uVar5 = ble_sub_41034(iVar4,extraout_r1[4],0x14,extraout_r1[8]);
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
               rom_06EF4(ble_ro_41c6c + -2,(uint)*(byte *)(iVar4 + 0x16) * 0x100 + 6,param_3,sVar2 + 6);
      *puVar6 = *(undefined2 *)(iVar4 + 0x18);
      *(char *)(puVar6 + 2) = cVar8;
      puVar6[1] = sVar2;
      if (cVar8 == '\0') {
        rom_24F9C((int)puVar6 + 5,param_2 + 9,sVar2);
      }
      goto LAB_000419f0;
    }
  }
  puVar6 = (undefined2 *)rom_06EF4(ble_ro_41c6c,(uint)*(byte *)(iVar4 + 0x16) * 0x100 + 6,param_3,4);
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
 * calls     : ble_sub_3edee, ble_sub_41034, dbg_printf, rom_06EF4, rom_06F26, rom_07180, ... (+1 more)
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
  dbg_printf(&ble_ro_41c70,str_hogpd_proto_mode_cfm_handler);
  if (-1 < (int)(uVar2 << 0x1e)) {
    return 0;
  }
  cVar6 = -0x80;
  iVar3 = ble_sub_3edee(0x26);
  cVar1 = param_2[1];
  if ((param_2[1] == '\0') && (cVar1 = -0x80, *(char *)(iVar3 + 0x17) == '\x03')) {
    if (*param_2 == *(char *)(iVar3 + 0x16)) {
      uVar4 = ble_sub_41034(iVar3,param_2[2],10,0);
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
               rom_06EF4(ble_ro_41c6c + -2,(uint)*(byte *)(iVar3 + 0x16) * 0x100 + 6,param_3,6);
      *puVar5 = *(undefined2 *)(iVar3 + 0x18);
      *(char *)(puVar5 + 2) = cVar6;
      goto LAB_00041a88;
    }
  }
  puVar5 = (undefined2 *)rom_06EF4(ble_ro_41c6c,(uint)*(byte *)(iVar3 + 0x16) * 0x100 + 6,param_3,4);
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
 * ble_sub_41e78   @ 0x00041e78   (28 bytes)
 * called by : ble_sub_41160
 * calls     : ble_sub_3edee
 */

void ble_sub_41e78(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x26);
  *param_1 = ble_ro_41e9c;
  *(undefined2 *)((int)param_1 + 10) = 8;
  param_1[1] = iVar1 + 0x1a;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_420ee   @ 0x000420ee   (64 bytes)
 * calls     : ble_sub_3e958, rom_06EF4, rom_06F26, rom_07180
 */

undefined4 ble_sub_420ee(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  int unaff_r4;
  undefined4 unaff_r6;
  int in_stack_00000004;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  
  if (*(short *)(param_2 + 0x76) == 0) {
    puVar1 = (undefined1 *)rom_06EF4(ble_ro_423d4,in_stack_00000018,in_stack_00000014,1);
    *puVar1 = 0x82;
    rom_06F26();
  }
  else {
    ble_sub_3e958();
    **(int **)(in_stack_00000004 + 4) = unaff_r4 + -0xc;
    rom_07180(in_stack_00000014,5);
    unaff_r6 = 1;
  }
  return unaff_r6;
}

/* ==========================================================================
 * ble_sub_42132   @ 0x00042132   (130 bytes)
 * calls     : ble_sub_3e958, ble_sub_3edee, rom_06EF4, rom_06F26, rom_07180, rom_071EA
 */

undefined4 ble_sub_42132(undefined4 param_1,ushort *param_2,uint param_3,undefined4 param_4)

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
    iVar2 = ble_sub_3edee(0x4b);
    iVar4 = (param_3 >> 8) * 4 + iVar2;
    iVar5 = *(int *)(iVar4 + 4);
    if (iVar5 == 0) {
      uVar6 = 0x80;
    }
    else if (*param_2 < 2) {
      sVar1 = *(short *)(iVar5 + 0x8a);
      uVar6 = 0x82;
      if (sVar1 != 0) {
        ble_sub_3e958(iVar2,param_3 >> 8,sVar1,*param_2,0);
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
  puVar3 = (undefined1 *)rom_06EF4(ble_ro_423d4 + 2,param_4,param_3,1);
  *puVar3 = uVar6;
  rom_06F26();
  return 0;
}

/* ==========================================================================
 * ble_sub_42430   @ 0x00042430   (28 bytes)
 * calls     : ble_sub_3edee
 */

void ble_sub_42430(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = ble_sub_3edee(0x4b);
  *param_1 = ble_ro_4244c;
  *(undefined2 *)((int)param_1 + 10) = 8;
  param_1[1] = iVar1 + 8;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

/* ==========================================================================
 * ble_sub_42450   @ 0x00042450   (14 bytes)
 * called by : ble_sub_3bb38
 */

int ble_sub_42450(char *param_1)

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
 * ble_sub_429fc   @ 0x000429fc   (28 bytes)
 * called by : ble_sub_3ba0a
 * calls     : input_sub_42c70, input_sub_433b0
 */

undefined8 ble_sub_429fc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uVar1 = input_sub_42c70(param_2,param_3,&uStack_18,ble_ro_42a1c);
  input_sub_433b0(0,&uStack_18);
  return CONCAT44(uStack_18,uVar1);
}
