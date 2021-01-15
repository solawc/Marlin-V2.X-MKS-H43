/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "../DGUSDisplayDef.h"

#define LOGO_TIME_DELAY       1500

 //#define DGUS_MKS_RUNOUT_SENSOR
#if ENABLED(DGUS_MKS_RUNOUT_SENSOR)
 #define MT_DET_1_PIN P1_26
//#define MT_DET_2_PIN 2
    #define MT_DET_PIN_INVERTING false
#endif

#define MKS_FINSH
enum DGUSLCD_Screens : uint8_t {
  DGUSLCD_SCREEN_BOOT                 =   120,
  DGUSLCD_SCREEN_MAIN                 =   1,

  DGUSLCD_SCREEN_STATUS               =   1,
  DGUSLCD_SCREEN_STATUS2              =   1,
  DGUSLCD_SCREEN_PREHEAT              =  18,
  DGUSLCD_SCREEN_POWER_LOSS           = 100,
  DGUSLCD_SCREEN_MANUALMOVE           = 192,
  DGUSLCD_SCREEN_UTILITY              = 120,
  DGUSLCD_SCREEN_FILAMENT_UNLOADING   = 158,
  DGUSLCD_SCREEN_SDFILELIST           =  15,
  DGUSLCD_SCREEN_SDPRINTMANIPULATION  =  15,
  DGUSLCD_SCREEN_SDPRINTTUNE          =  17,


  MKSLCD_SCREEN_BOOT                  = 0,
  MKSLCD_SCREEN_HOME                  = 1,   // MKS main page
  MKSLCD_SCREEN_SETTING               = 2,   // MKS Setting page / no wifi whit
  MKSLCD_SCREEM_TOOL                  = 3,   // MKS Tool page
  MKSLCD_SCREEN_EXTRUDE_P1            = 4,
  MKSLCD_SCREEN_EXTRUDE_P2            = 11,
  MKSLCD_SCREEN_LEVEL                 = 5,
  MKSLCD_AUTO_LEVEL                   = 73,
  MKSLCD_SCREEN_LEVEL_PRESS           = 9,
  MKSLCD_SCREEN_MOVE                  = 6,
  MKSLCD_SCREEN_PRINT                 = 7,
  MKSLCD_SCREEN_PRINT_PRESS           = 13,
  MKSLCD_SCREEN_PAUSE                 = 26,
  MKSLCD_SCREEN_PAUSE_PRESS           = 26,
  MKSLCD_SCREEN_CHOOSE_FILE           = 15,
  MKSLCD_SCREEN_NO_CHOOSE_FILE        = 17,
  MKSLCD_SCREEN_Config                = 46,
  MKSLCD_SCREEN_Config_MOTOR          = 47,
  MKSLCD_SCREEN_MOTOR_PLUSE           = 51,
  MKSLCD_SCREEN_MOTOR_SPEED           = 55,
  MKSLCD_SCREEN_MOTOR_ACC_MAX         = 53,
  MKSLCD_SCREEN_PRINT_CONFIG          = 60,
  MKSLCD_SCREEN_LEVEL_DATA            = 48,
  MKSLCD_PrintPause_SET               = 49,
  MKSLCD_FILAMENT_DATA                = 50,
  MKSLCD_ABOUT                        = 36,
  MKSLCD_PID                          = 56,
  MKSLCD_PAUSE_SETTING_MOVE           = 58,
  MKSLCD_PAUSE_SETTING_EX             = 57,
  MKSLCD_PAUSE_SETTING_EX2            = 61,
  MKSLCD_SCREEN_NO_FILE               = 42,
  MKSLCD_SCREEN_PRINT_CONFIRM         = 43,
  MKSLCD_SCREEN_EX_CONFIG             = 65,
  MKSLCD_SCREEN_EEP_Config            = 20,
  MKSLCD_SCREEN_PrintDone             = 25,
  MKSLCD_SCREEN_TMC_Config            = 70,
  MKSLCD_Screen_Offset_Config         = 30,
  MKSLCD_Screen_PMove                 = 64,
  MKSLCD_Screen_Baby                  = 71,

  DGUSLCD_SCREEN_CONFIRM              = 240,
  DGUSLCD_SCREEN_KILL                 = 250, ///< Kill Screen. Must always be 250 (to be able to display "Error wrong LCD Version")
  DGUSLCD_SCREEN_WAITING              = 251,
  DGUSLCD_SCREEN_POPUP                = 252, ///< special target, popup screen will also return this code to say "return to previous screen"
  DGUSLDC_SCREEN_UNUSED               = 255,
};

// Display Memory layout used (T5UID)
// Except system variables this is arbitrary, just to organize stuff....

// 0x0000 .. 0x0FFF  -- System variables and reserved by the display
// 0x1000 .. 0x1FFF  -- Variables to never change location, regardless of UI Version
// 0x2000 .. 0x2FFF  -- Controls (VPs that will trigger some action)
// 0x3000 .. 0x4FFF  -- Marlin Data to be displayed
// 0x5000 ..         -- SPs (if we want to modify display elements, e.g change color or like) -- currently unused

// As there is plenty of space (at least most displays have >8k RAM), we do not pack them too tight,
// so that we can keep variables nicely together in the address space.

// UI Version always on 0x1000...0x1002 so that the firmware can check this and bail out.

// constexpr uint16_t VP_UI_VERSION_MAJOR = 0x1000;  // Major -- incremented when incompatible
// constexpr uint16_t VP_UI_VERSION_MINOR = 0x1001;  // Minor -- incremented on new features, but compatible
// constexpr uint16_t VP_UI_VERSION_PATCH = 0x1002;  // Patch -- fixed which do not change functionality.
// constexpr uint16_t VP_UI_FLAVOUR       = 0x1010;  // lets reserve 16 bytes here to determine if UI is suitable for this Marlin. tbd.

// Storage space for the Killscreen messages. 0x1100 - 0x1200 . Reused for the popup.
// constexpr uint16_t VP_MSGSTR1 = 0x1100;
// constexpr uint8_t VP_MSGSTR1_LEN = 0x20;  // might be more place for it...
// constexpr uint16_t VP_MSGSTR2 = 0x1140;
// constexpr uint8_t VP_MSGSTR2_LEN = 0x20;
// constexpr uint16_t VP_MSGSTR3 = 0x1180;
// constexpr uint8_t VP_MSGSTR3_LEN = 0x20;
// constexpr uint16_t VP_MSGSTR4 = 0x11C0;
// constexpr uint8_t VP_MSGSTR4_LEN = 0x20;

// Screenchange request for screens that only make sense when printer is idle.
// e.g movement is only allowed if printer is not printing.
// Marlin must confirm by setting the screen manually.
// constexpr uint16_t VP_SCREENCHANGE_ASK = 0x2000;
// constexpr uint16_t VP_SCREENCHANGE = 0x2001;   // Key-Return button to new menu pressed. Data contains target screen in low byte and info in high byte.
// constexpr uint16_t VP_TEMP_ALL_OFF = 0x2002;   // Turn all heaters off. Value arbitrary ;)=
// constexpr uint16_t VP_SCREENCHANGE_WHENSD = 0x2003; // "Print" Button touched -- go only there if there is an SD Card.
// constexpr uint16_t VP_CONFIRMED = 0x2010; // OK on confirm screen.

// // Buttons on the SD-Card File listing.
// constexpr uint16_t VP_SD_ScrollEvent = 0x2020; // Data: 0 for "up a directory", numbers are the amount to scroll, e.g -1 one up, 1 one down
// constexpr uint16_t VP_SD_FileSelected = 0x2022; // Number of file field selected.
// constexpr uint16_t VP_SD_FileSelectConfirm = 0x2024; // (This is a virtual VP and emulated by the Confirm Screen when a file has been confirmed)

// constexpr uint16_t VP_SD_ResumePauseAbort = 0x2026; // Resume(Data=0), Pause(Data=1), Abort(Data=2) SD Card prints
// constexpr uint16_t VP_SD_AbortPrintConfirmed = 0x2028; // Abort print confirmation (virtual, will be injected by the confirm dialog)
// constexpr uint16_t VP_SD_Print_Setting = 0x2040;
// constexpr uint16_t VP_SD_Print_LiveAdjustZ = 0x2050; // Data: 0 down, 1 up

// Controls for movement (we can't use the incremental / decremental feature of the display at this feature works only with 16 bit values
// (which would limit us to 655.35mm, which is likely not a problem for common setups, but i don't want to rule out hangprinters support)
// A word about the coding: The VP will be per axis and the return code will be an signed 16 bit value in 0.01 mm resolution, telling us
// the relative travel amount t he user wants to do. So eg. if the display sends us VP=2100 with value 100, the user wants us to move X by +1 mm.
// constexpr uint16_t VP_MOVE_X = 0x2100;
// constexpr uint16_t VP_MOVE_Y = 0x2102;
// constexpr uint16_t VP_MOVE_Z = 0x2104;
// constexpr uint16_t VP_MOVE_E0 = 0x2110;
// constexpr uint16_t VP_MOVE_E1 = 0x2112;
// //constexpr uint16_t VP_MOVE_E2 = 0x2114;
// //constexpr uint16_t VP_MOVE_E3 = 0x2116;
// //constexpr uint16_t VP_MOVE_E4 = 0x2118;
// //constexpr uint16_t VP_MOVE_E5 = 0x211A;
// constexpr uint16_t VP_HOME_ALL = 0x2120;
// constexpr uint16_t VP_MOTOR_LOCK_UNLOK = 0x2130;
// constexpr uint16_t VP_XYZ_HOME = 0X2132;

// Power loss recovery
// constexpr uint16_t VP_POWER_LOSS_RECOVERY = 0x2180;

// // Fan Control Buttons , switch between "off" and "on"
// constexpr uint16_t VP_FAN0_CONTROL = 0x2200;
// constexpr uint16_t VP_FAN1_CONTROL = 0x2202;
// constexpr uint16_t VP_FAN2_CONTROL = 0x2204;
// constexpr uint16_t VP_FAN3_CONTROL = 0x2206;

// // Heater Control Buttons , triged between "cool down" and "heat PLA" state
// constexpr uint16_t VP_E0_CONTROL = 0x2210;
// constexpr uint16_t VP_E1_CONTROL = 0x2212;
// //constexpr uint16_t VP_E2_CONTROL = 0x2214;
// //constexpr uint16_t VP_E3_CONTROL = 0x2216;
// //constexpr uint16_t VP_E4_CONTROL = 0x2218;
// //constexpr uint16_t VP_E5_CONTROL = 0x221A;
// constexpr uint16_t VP_BED_CONTROL = 0x221C;

// // Preheat
// constexpr uint16_t VP_E0_BED_PREHEAT = 0x2220;
// constexpr uint16_t VP_E1_BED_PREHEAT = 0x2222;
// //constexpr uint16_t VP_E2_BED_PREHEAT = 0x2224;
// //constexpr uint16_t VP_E3_BED_PREHEAT = 0x2226;
// //constexpr uint16_t VP_E4_BED_PREHEAT = 0x2228;
// //constexpr uint16_t VP_E5_BED_PREHEAT = 0x222A;

// // Filament load and unload
// // constexpr uint16_t VP_E0_FILAMENT_LOAD_UNLOAD = 0x2300;
// // constexpr uint16_t VP_E1_FILAMENT_LOAD_UNLOAD = 0x2302;

// // Settings store , reset


// // PID autotune
// constexpr uint16_t VP_PID_AUTOTUNE_E0 = 0x2410;
// constexpr uint16_t VP_PID_AUTOTUNE_E1 = 0x2412;
// //constexpr uint16_t VP_PID_AUTOTUNE_E2 = 0x2414;
// //constexpr uint16_t VP_PID_AUTOTUNE_E3 = 0x2416;
// //constexpr uint16_t VP_PID_AUTOTUNE_E4 = 0x2418;
// //constexpr uint16_t VP_PID_AUTOTUNE_E5 = 0x241A;
// constexpr uint16_t VP_PID_AUTOTUNE_BED = 0x2420;
// // Calibrate Z
// constexpr uint16_t VP_Z_CALIBRATE = 0x2430;

// First layer cal
// constexpr uint16_t VP_Z_FIRST_LAYER_CAL = 0x2500; // Data: 0 - Cancel first layer cal progress, >0 filament type have loaded

// Firmware version on the boot screen.
// constexpr uint16_t VP_MARLIN_VERSION = 0x3000;
// constexpr uint8_t VP_MARLIN_VERSION_LEN = 16;   // there is more space on the display, if needed.

// Place for status messages.
constexpr uint16_t VP_M117 = 0x7020;
constexpr uint8_t VP_M117_LEN = 0x20;

// // Temperatures.
// constexpr uint16_t VP_T_E0_Is = 0x3060;  // 4 Byte Integer
// constexpr uint16_t VP_T_E0_Set = 0x3062; // 2 Byte Integer
// constexpr uint16_t VP_T_E1_Is = 0x3064;  // 4 Byte Integer
// // reserved to support up to 6 Extruders:
// constexpr uint16_t VP_T_E1_Set = 0x3066; // 2 Byte Integer
// constexpr uint16_t VP_T_E2_Is = 0x3068;  // 4 Byte Integer
// constexpr uint16_t VP_T_E2_Set = 0x306A; // 2 Byte Integer
// constexpr uint16_t VP_T_E3_Is = 0x306C;  // 4 Byte Integer
// constexpr uint16_t VP_T_E3_Set = 0x306E; // 2 Byte Integer
// constexpr uint16_t VP_T_E4_Is = 0x3070;  // 4 Byte Integer
// constexpr uint16_t VP_T_E4_Set = 0x3072; // 2 Byte Integer
// constexpr uint16_t VP_T_E5_Is = 0x3074;  // 4 Byte Integer
// constexpr uint16_t VP_T_E5_Set = 0x3076; // 2 Byte Integer
// constexpr uint16_t VP_T_E6_Is = 0x3078;  // 4 Byte Integer
// constexpr uint16_t VP_T_E6_Set = 0x307A; // 2 Byte Integer
// constexpr uint16_t VP_T_E7_Is = 0x3078;  // 4 Byte Integer
// constexpr uint16_t VP_T_E7_Set = 0x307A; // 2 Byte Integer


// constexpr uint16_t VP_T_Bed_Is = 0x3080;  // 4 Byte Integer
// constexpr uint16_t VP_T_Bed_Set = 0x3082; // 2 Byte Integer

// constexpr uint16_t VP_Flowrate_E0 = 0x3090; // 2 Byte Integer
// constexpr uint16_t VP_Flowrate_E1 = 0x3092; // 2 Byte Integer
// // reserved for up to 6 Extruders:
// constexpr uint16_t VP_Flowrate_E2 = 0x3094;
// constexpr uint16_t VP_Flowrate_E3 = 0x3096;
// constexpr uint16_t VP_Flowrate_E4 = 0x3098;
// constexpr uint16_t VP_Flowrate_E5 = 0x309A;

// constexpr uint16_t VP_Fan0_Percentage = 0x3100;  // 2 Byte Integer (0..100)
// constexpr uint16_t VP_Fan1_Percentage = 0x3102;  // 2 Byte Integer (0..100)
// constexpr uint16_t VP_Fan2_Percentage = 0x3104;  // 2 Byte Integer (0..100)
// constexpr uint16_t VP_Fan3_Percentage = 0x3106;  // 2 Byte Integer (0..100)
// constexpr uint16_t VP_Feedrate_Percentage = 0x3108; // 2 Byte Integer (0..100)

// Actual Position
// constexpr uint16_t VP_XPos = 0x3110;  // 4 Byte Fixed point number; format xxx.yy
// constexpr uint16_t VP_YPos = 0x3112;  // 4 Byte Fixed point number; format xxx.yy
// constexpr uint16_t VP_ZPos = 0x3114;  // 4 Byte Fixed point number; format xxx.yy
// constexpr uint16_t VP_EPos = 0x3120;  // 4 Byte Fixed point number; format xxx.yy

// constexpr uint16_t VP_PrintProgress_Percentage = 0x3130; // 2 Byte Integer (0..100)

// constexpr uint16_t VP_PrintTime = 0x3140;
// constexpr uint16_t VP_PrintTime_LEN = 32;

// constexpr uint16_t VP_PrintAccTime = 0x3160;
// constexpr uint16_t VP_PrintAccTime_LEN = 32;

// constexpr uint16_t VP_PrintsTotal = 0x3180;
// constexpr uint16_t VP_PrintsTotal_LEN = 16;

// // SDCard File Listing
// constexpr uint16_t VP_SD_FileName_LEN = 32; // LEN is shared for all entries.
// constexpr uint16_t DGUS_SD_FILESPERSCREEN = 8; // FIXME move that info to the display and read it from there.
// constexpr uint16_t VP_SD_FileName0 = 0x3200;
// constexpr uint16_t VP_SD_FileName1 = 0x3220;
// constexpr uint16_t VP_SD_FileName2 = 0x3240;
// constexpr uint16_t VP_SD_FileName3 = 0x3260;
// constexpr uint16_t VP_SD_FileName4 = 0x3280;
// constexpr uint16_t VP_SD_FileName5 = 0x32A0;
// constexpr uint16_t VP_SD_FileName6 = 0x32C0;
// constexpr uint16_t VP_SD_FileName7 = 0x32E0;






// Heater status
constexpr uint16_t VP_E0_STATUS = 0x3410;
constexpr uint16_t VP_E1_STATUS = 0x3412;
//constexpr uint16_t VP_E2_STATUS = 0x3414;
//constexpr uint16_t VP_E3_STATUS = 0x3416;
//constexpr uint16_t VP_E4_STATUS = 0x3418;
//constexpr uint16_t VP_E5_STATUS = 0x341A;
constexpr uint16_t VP_MOVE_OPTION = 0x3500;

// // PIDs
// constexpr uint16_t VP_E0_PID_P = 0x3700; // at the moment , 2 byte unsigned int , 0~1638.4
// constexpr uint16_t VP_E0_PID_I = 0x3702;
// constexpr uint16_t VP_E0_PID_D = 0x3704;
// constexpr uint16_t VP_E1_PID_P = 0x3706; // at the moment , 2 byte unsigned int , 0~1638.4
// constexpr uint16_t VP_E1_PID_I = 0x3708;
// constexpr uint16_t VP_E1_PID_D = 0x370A;
// constexpr uint16_t VP_BED_PID_P = 0x3710;
// constexpr uint16_t VP_BED_PID_I = 0x3712;
// constexpr uint16_t VP_BED_PID_D = 0x3714;

// Wating screen status
constexpr uint16_t VP_WAITING_STATUS = 0x3800;

// SPs for certain variables...
// located at 0x5000 and up
// Not used yet!
// This can be used e.g to make controls / data display invisible
constexpr uint16_t SP_T_E0_Is     = 0x5000;
constexpr uint16_t SP_T_E0_Set    = 0x5010;
constexpr uint16_t SP_T_E1_Is     = 0x5020;
constexpr uint16_t SP_T_Bed_Is    = 0x5030;
constexpr uint16_t SP_T_Bed_Set   = 0x5040;

/*************************************************************************************************************************
 *************************************************************************************************************************
 *                                                 DGUS for MKS Mem layout
 ************************************************************************************************************************
 ************************************************************************************************************************/

#if ENABLED(MKS_FINSH)
/* -------------------------------0x1000-0x1FFF------------------------------- */
constexpr uint16_t VP_MSGSTR1                       = 0x1100;
constexpr uint8_t  VP_MSGSTR1_LEN                   = 0x20;  // might be more place for it...
constexpr uint16_t VP_MSGSTR2                       = 0x1140;
constexpr uint8_t  VP_MSGSTR2_LEN                   = 0x20;
constexpr uint16_t VP_MSGSTR3                       = 0x1180;
constexpr uint8_t  VP_MSGSTR3_LEN                   = 0x20;
constexpr uint16_t VP_MSGSTR4                       = 0x11C0;
constexpr uint8_t  VP_MSGSTR4_LEN                   = 0x20;

constexpr uint16_t VP_MARLIN_VERSION                = 0x1A00;
constexpr uint8_t VP_MARLIN_VERSION_LEN             = 16;       // there is more space on the display, if needed.


constexpr uint16_t VP_SCREENCHANGE_ASK              = 0x1500;
constexpr uint16_t VP_SCREENCHANGE                  = 0x1501;   // Key-Return button to new menu pressed. Data contains target screen in low byte and info in high byte.
constexpr uint16_t VP_TEMP_ALL_OFF                  = 0x1502;   // Turn all heaters off. Value arbitrary ;)=
constexpr uint16_t VP_SCREENCHANGE_WHENSD           = 0x1503;   // "Print" Button touched -- go only there if there is an SD Card.
constexpr uint16_t VP_CONFIRMED                     = 0x1510;   // OK on confirm screen.

constexpr uint16_t VP_BACK_PAGE                     = 0x1600;
constexpr uint16_t VP_SETTINGS                      = 0x1620;
// Power loss recovery
constexpr uint16_t VP_POWER_LOSS_RECOVERY           = 0x1680;
/* -------------------------------0x2000-0x2FFF------------------------------- */
// Temperatures.
constexpr uint16_t VP_T_E0_Is                       = 0x2000;   // 4 Byte Integer
constexpr uint16_t VP_T_E0_Set                      = 0x2004;   // 2 Byte Integer
constexpr uint16_t VP_T_E1_Is                       = 0x2008;   // 4 Byte Integer
constexpr uint16_t VP_T_E1_Set                      = 0x200B;   // 2 Byte Integer
constexpr uint16_t VP_T_E2_Is                       = 0x2010;   // 4 Byte Integer
constexpr uint16_t VP_T_E2_Set                      = 0x2014;   // 2 Byte Integer
constexpr uint16_t VP_T_E3_Is                       = 0x2018;   // 4 Byte Integer
constexpr uint16_t VP_T_E3_Set                      = 0x201B;   // 2 Byte Integer
constexpr uint16_t VP_T_E4_Is                       = 0x2020;   // 4 Byte Integer
constexpr uint16_t VP_T_E4_Set                      = 0x2024;   // 2 Byte Integer
constexpr uint16_t VP_T_E5_Is                       = 0x2028;   // 4 Byte Integer
constexpr uint16_t VP_T_E5_Set                      = 0x202B;   // 2 Byte Integer
constexpr uint16_t VP_T_E6_Is                       = 0x2030;   // 4 Byte Integer
constexpr uint16_t VP_T_E6_Set                      = 0x2034;   // 2 Byte Integer
constexpr uint16_t VP_T_E7_Is                       = 0x2038;   // 4 Byte Integer
constexpr uint16_t VP_T_E7_Set                      = 0x203B;   // 2 Byte Integer

constexpr uint16_t VP_T_Bed_Is                      = 0x2040;   // 4 Byte Integer
constexpr uint16_t VP_T_Bed_Set                     = 0x2044;   // 2 Byte Integer

constexpr uint16_t VP_Min_EX_T_E                    = 0X2100;




constexpr uint16_t VP_Flowrate_E0                   = 0x2200;   // 2 Byte Integer
constexpr uint16_t VP_Flowrate_E1                   = 0x2202;   // 2 Byte Integer
constexpr uint16_t VP_Flowrate_E2                   = 0x2204;
constexpr uint16_t VP_Flowrate_E3                   = 0x2206;
constexpr uint16_t VP_Flowrate_E4                   = 0x2208;
constexpr uint16_t VP_Flowrate_E5                   = 0x220A;
constexpr uint16_t VP_Flowrate_E6                   = 0x220C;
constexpr uint16_t VP_Flowrate_E7                   = 0x220E;

// Move
constexpr uint16_t VP_MOVE_X                        = 0x2300;
constexpr uint16_t VP_MOVE_Y                        = 0x2302;
constexpr uint16_t VP_MOVE_Z                        = 0x2304;
constexpr uint16_t VP_MOVE_E0                       = 0x2310;
constexpr uint16_t VP_MOVE_E1                       = 0x2312;
constexpr uint16_t VP_MOVE_E2                       = 0x2314;
constexpr uint16_t VP_MOVE_E3                       = 0x2316;
constexpr uint16_t VP_MOVE_E4                       = 0x2318;
constexpr uint16_t VP_MOVE_E5                       = 0x231A;
constexpr uint16_t VP_MOVE_E6                       = 0x231C;
constexpr uint16_t VP_MOVE_E7                       = 0x231E;
constexpr uint16_t VP_HOME_ALL                      = 0x2320;
constexpr uint16_t VP_MOTOR_LOCK_UNLOK              = 0x2330;
constexpr uint16_t VP_MOVE_DISTANCE                 = 0X2334;
constexpr uint16_t VP_X_HOME                        = 0X2336;
constexpr uint16_t VP_Y_HOME                        = 0X2338;
constexpr uint16_t VP_Z_HOME                        = 0X233A;




// Fan Control Buttons , switch between "off" and "on"
constexpr uint16_t VP_FAN0_CONTROL                  = 0x2350;
constexpr uint16_t VP_FAN1_CONTROL                  = 0x2352;
constexpr uint16_t VP_FAN2_CONTROL                  = 0x2354;
constexpr uint16_t VP_FAN3_CONTROL                  = 0x2356;
constexpr uint16_t VP_FAN4_CONTROL                  = 0x2358;
constexpr uint16_t VP_FAN5_CONTROL                  = 0x235A;

constexpr uint16_t VP_LANGUAGE_CHANGE               = 0X2380;
constexpr uint16_t VP_LANGUAGE_CHANGE1              = 0X2382;
constexpr uint16_t VP_LANGUAGE_CHANGE2              = 0X2384;
constexpr uint16_t VP_LANGUAGE_CHANGE3              = 0X2386;
constexpr uint16_t VP_LANGUAGE_CHANGE4              = 0X2388;
constexpr uint16_t VP_LANGUAGE_CHANGE5              = 0X238A;

// LEVEL
constexpr uint16_t VP_LEVEL_POINT                   = 0x2400;
constexpr uint16_t VP_MESH_LEVEL_POINT              = 0x2410;
constexpr uint16_t VP_MESH_LEVEL_ADJUST             = 0x2412;
constexpr uint16_t VP_MESH_LEVEL_DIP                = 0X2414;
constexpr uint16_t VP_MESH_LEVEL_POINT_X            = 0x2416;
constexpr uint16_t VP_MESH_LEVEL_POINT_Y            = 0x2418;
constexpr uint16_t VP_LEVEL_BUTTON                  = 0x2420;
constexpr uint16_t VP_MESH_LEVEL_POINT_DIS          = 0x2422;
constexpr uint16_t VP_MESH_LEVEL_BACK               = 0x2424;

constexpr uint16_t VP_E0_FILAMENT_LOAD_UNLOAD       = 0x2500;
constexpr uint16_t VP_E1_FILAMENT_LOAD_UNLOAD       = 0x2504;
constexpr uint16_t VP_LOAD_Filament                 = 0x2508;
// constexpr uint16_t VP_LOAD_UNLOAD_Cancle            = 0x250A;
constexpr uint16_t VP_UNLOAD_Filament               = 0x250B;
constexpr uint16_t VP_Filament_distance             = 0x2600;
constexpr uint16_t VP_Filament_speed                = 0x2604;
constexpr uint16_t VP_MIN_EX_T                      = 0X2606;

constexpr uint16_t VP_E1_Filament_distance          = 0x2614;
constexpr uint16_t VP_E1_Filament_speed             = 0x2616;
constexpr uint16_t VP_E1_MIN_EX_T                   = 0X2618;




constexpr uint16_t VP_Fan0_Percentage               = 0x2700;   // 2 Byte Integer (0..100)
constexpr uint16_t VP_Fan1_Percentage               = 0x2702;   // 2 Byte Integer (0..100)
constexpr uint16_t VP_Fan2_Percentage               = 0x2704;   // 2 Byte Integer (0..100)
constexpr uint16_t VP_Fan3_Percentage               = 0x2706;   // 2 Byte Integer (0..100)
constexpr uint16_t VP_Feedrate_Percentage           = 0x2708;   // 2 Byte Integer (0..100)

// Fan status
constexpr uint16_t VP_FAN0_STATUS                   = 0x2710;
constexpr uint16_t VP_FAN1_STATUS                   = 0x2712;
constexpr uint16_t VP_FAN2_STATUS                   = 0x2714;
constexpr uint16_t VP_FAN3_STATUS                   = 0x2716;

// Step per mm
constexpr uint16_t VP_X_STEP_PER_MM                 = 0x2900;   // at the moment , 2 byte unsigned int , 0~1638.4
constexpr uint16_t VP_Y_STEP_PER_MM                 = 0x2904;
constexpr uint16_t VP_Z_STEP_PER_MM                 = 0x2908;
constexpr uint16_t VP_E0_STEP_PER_MM                = 0x2910;
constexpr uint16_t VP_E1_STEP_PER_MM                = 0x2912;
constexpr uint16_t VP_E2_STEP_PER_MM                = 0x2914;
constexpr uint16_t VP_E3_STEP_PER_MM                = 0x2916;
constexpr uint16_t VP_E4_STEP_PER_MM                = 0x2918;
constexpr uint16_t VP_E5_STEP_PER_MM                = 0x291A;
constexpr uint16_t VP_E6_STEP_PER_MM                = 0x291C;
constexpr uint16_t VP_E7_STEP_PER_MM                = 0x291E;

constexpr uint16_t VP_X_MAX_SPEED                   = 0x2A00;
constexpr uint16_t VP_Y_MAX_SPEED                   = 0x2A04;
constexpr uint16_t VP_Z_MAX_SPEED                   = 0x2A08;
constexpr uint16_t VP_E0_MAX_SPEED                  = 0x2A0C;
constexpr uint16_t VP_E1_MAX_SPEED                  = 0x2A10;

constexpr uint16_t VP_X_ACC_MAX_SPEED               = 0x2A28;
constexpr uint16_t VP_Y_ACC_MAX_SPEED               = 0x2A2C;
constexpr uint16_t VP_Z_ACC_MAX_SPEED               = 0x2A30;
constexpr uint16_t VP_E0_ACC_MAX_SPEED              = 0x2A34;
constexpr uint16_t VP_E1_ACC_MAX_SPEED              = 0x2A38;

constexpr uint16_t VP_TRAVEL_SPEED                  = 0x2A3C;
constexpr uint16_t VP_FEEDRATE_MIN_SPEED            = 0x2A40;
constexpr uint16_t VP_T_F_SPEED                     = 0x2A44;
constexpr uint16_t VP_ACC_SPEED                     = 0x2A48;


/* -------------------------------0x3000-0x3FFF------------------------------- */
// Buttons on the SD-Card File listing.
constexpr uint16_t VP_SD_ScrollEvent                = 0x3020; // Data: 0 for "up a directory", numbers are the amount to scroll, e.g -1 one up, 1 one down
constexpr uint16_t VP_SD_FileSelected               = 0x3022; // Number of file field selected.
constexpr uint16_t VP_SD_FileSelectConfirm          = 0x3024; // (This is a virtual VP and emulated by the Confirm Screen when a file has been confirmed)
constexpr uint16_t VP_SD_ResumePauseAbort           = 0x3026; // Resume(Data=0), Pause(Data=1), Abort(Data=2) SD Card prints
constexpr uint16_t VP_SD_AbortPrintConfirmed        = 0x3028; // Abort print confirmation (virtual, will be injected by the confirm dialog)
constexpr uint16_t VP_SD_Print_Setting              = 0x3040;
constexpr uint16_t VP_SD_Print_LiveAdjustZ          = 0x3050; // Data: 0 down, 1 up
constexpr uint16_t VP_SD_Print_LiveAdjustZ_Confirm  = 0x3060;
constexpr uint16_t VP_ZOffset_Distance              = 0x3070;
constexpr uint16_t VP_ZOffset_DE_DIS                = 0x3080;
// SDCard File Listing
constexpr uint16_t VP_SD_FileName_LEN = 32;                   // LEN is shared for all entries.
constexpr uint16_t DGUS_SD_FILESPERSCREEN = 10;               // FIXME move that info to the display and read it from there.
constexpr uint16_t VP_SD_FileName0                  = 0x3100;
constexpr uint16_t VP_SD_FileName1                  = 0x3120;
constexpr uint16_t VP_SD_FileName2                  = 0x3140;
constexpr uint16_t VP_SD_FileName3                  = 0x3160;
constexpr uint16_t VP_SD_FileName4                  = 0x3180;
constexpr uint16_t VP_SD_FileName5                  = 0x31A0;
constexpr uint16_t VP_SD_FileName6                  = 0x31C0;
constexpr uint16_t VP_SD_FileName7                  = 0x31E0;
constexpr uint16_t VP_SD_FileName8                  = 0x3200;
constexpr uint16_t VP_SD_FileName9                  = 0x3220;

constexpr uint16_t VP_SD_Print_ProbeOffsetZ         = 0x32A0;
constexpr uint16_t VP_SD_Print_Baby                 = 0x32B0;
constexpr uint16_t VP_SD_Print_Filename             = 0x32C0;

// X Y Z Point
constexpr uint16_t VP_XPos = 0x3300;  // 4 Byte Fixed point number; format xxx.yy
constexpr uint16_t VP_YPos = 0x3302;  // 4 Byte Fixed point number; format xxx.yy
constexpr uint16_t VP_ZPos = 0x3304;  // 4 Byte Fixed point number; format xxx.yy
constexpr uint16_t VP_EPos = 0x3306;  // 4 Byte Fixed point number; format xxx.yy

// Print
constexpr uint16_t VP_PrintProgress_Percentage      = 0x3330; // 2 Byte Integer (0..100)
constexpr uint16_t VP_PrintTime                     = 0x3340;
constexpr uint16_t VP_PrintTime_LEN                 = 32;
constexpr uint16_t VP_PrintAccTime                  = 0x3360;
constexpr uint16_t VP_PrintAccTime_LEN              = 32;
constexpr uint16_t VP_PrintsTotal                   = 0x3380;
constexpr uint16_t VP_PrintsTotal_LEN               = 16;

constexpr uint16_t VP_File_Pictutr0                 = 0x3400;
constexpr uint16_t VP_File_Pictutr1                 = 0x3402;
constexpr uint16_t VP_File_Pictutr2                 = 0x3404;
constexpr uint16_t VP_File_Pictutr3                 = 0x3406;
constexpr uint16_t VP_File_Pictutr4                 = 0x3408;
constexpr uint16_t VP_File_Pictutr5                 = 0x340A;
constexpr uint16_t VP_File_Pictutr6                 = 0x340C;
constexpr uint16_t VP_File_Pictutr7                 = 0x340E;
constexpr uint16_t VP_File_Pictutr8                 = 0x3410;
constexpr uint16_t VP_File_Pictutr9                 = 0x3412;

constexpr uint16_t VP_BED_STATUS                    = 0x341C;

constexpr uint16_t VP_TMC_X_STEP                    = 0x3430;
constexpr uint16_t VP_TMC_Y_STEP                    = 0x3432;
constexpr uint16_t VP_TMC_Z_STEP                    = 0x3434;

constexpr uint16_t VP_TMC_X1_Current                = 0x3436;
constexpr uint16_t VP_TMC_Y1_Current                = 0x3438;
constexpr uint16_t VP_TMC_X_Current                 = 0x343A;
constexpr uint16_t VP_TMC_Y_Current                 = 0x343C;
constexpr uint16_t VP_TMC_Z_Current                 = 0x343E;
constexpr uint16_t VP_TMC_E0_Current                = 0x3440;
constexpr uint16_t VP_TMC_E1_Current                = 0x3442;
constexpr uint16_t VP_TMC_Z1_Current                = 0x3444;


constexpr uint16_t VP_PrintTime_H                   = 0x3500;
constexpr uint16_t VP_PrintTime_M                   = 0x3502;
constexpr uint16_t VP_PrintTime_S                   = 0x3504;

// PIDs
constexpr uint16_t VP_E0_PID_P = 0x3700; // at the moment , 2 byte unsigned int , 0~1638.4
constexpr uint16_t VP_E0_PID_I = 0x3702;
constexpr uint16_t VP_E0_PID_D = 0x3704;
constexpr uint16_t VP_E1_PID_P = 0x3706; // at the moment , 2 byte unsigned int , 0~1638.4
constexpr uint16_t VP_E1_PID_I = 0x3708;
constexpr uint16_t VP_E1_PID_D = 0x370A;
constexpr uint16_t VP_BED_PID_P = 0x3710;
constexpr uint16_t VP_BED_PID_I = 0x3712;
constexpr uint16_t VP_BED_PID_D = 0x3714;

constexpr uint16_t VP_EEPROM_CTRL = 0X3720;

constexpr uint16_t VP_OFFSET_X = 0X3724;
constexpr uint16_t VP_OFFSET_Y = 0X3728;
constexpr uint16_t VP_OFFSET_Z = 0X372B;

// PID autotune
constexpr uint16_t VP_PID_AUTOTUNE_E0 = 0x3800;
constexpr uint16_t VP_PID_AUTOTUNE_E1 = 0x3802;
constexpr uint16_t VP_PID_AUTOTUNE_E2 = 0x3804;
constexpr uint16_t VP_PID_AUTOTUNE_E3 = 0x3806;
constexpr uint16_t VP_PID_AUTOTUNE_E4 = 0x3808;
constexpr uint16_t VP_PID_AUTOTUNE_E5 = 0x380A;
constexpr uint16_t VP_PID_AUTOTUNE_BED = 0x380C;
// Calibrate Z
constexpr uint16_t VP_Z_CALIBRATE = 0x3810;

constexpr uint16_t VP_AutoTurnOffSw = 0x3812;


constexpr uint16_t VP_X_PARK_POS = 0x3900;
constexpr uint16_t VP_Y_PARK_POS = 0x3902;
constexpr uint16_t VP_Z_PARK_POS = 0x3904;




/* -------------------------------0x4000-0x4FFF------------------------------- */
// Heater Control Buttons , triged between "cool down" and "heat PLA" state
constexpr uint16_t VP_E0_CONTROL = 0x4010;
constexpr uint16_t VP_E1_CONTROL = 0x4012;
//constexpr uint16_t VP_E2_CONTROL = 0x2214;
//constexpr uint16_t VP_E3_CONTROL = 0x2216;
//constexpr uint16_t VP_E4_CONTROL = 0x2218;
//constexpr uint16_t VP_E5_CONTROL = 0x221A;
constexpr uint16_t VP_BED_CONTROL = 0x401C;

// Preheat
constexpr uint16_t VP_E0_BED_PREHEAT = 0x4020;
constexpr uint16_t VP_E1_BED_PREHEAT = 0x4022;
//constexpr uint16_t VP_E2_BED_PREHEAT = 0x4024;
//constexpr uint16_t VP_E3_BED_PREHEAT = 0x4026;
//constexpr uint16_t VP_E4_BED_PREHEAT = 0x4028;
//constexpr uint16_t VP_E5_BED_PREHEAT = 0x402A;

// Filament load and unload
// constexpr uint16_t VP_E0_FILAMENT_LOAD_UNLOAD = 0x4030;
// constexpr uint16_t VP_E1_FILAMENT_LOAD_UNLOAD = 0x4032;

// Settings store , reset


// Level data
constexpr uint16_t VP_Level_Point_One_X              = 0x4100;
constexpr uint16_t VP_Level_Point_One_Y              = 0x4102;
constexpr uint16_t VP_Level_Point_Two_X              = 0x4104;
constexpr uint16_t VP_Level_Point_Two_Y              = 0x4106;
constexpr uint16_t VP_Level_Point_Three_X            = 0x4108;
constexpr uint16_t VP_Level_Point_Three_Y            = 0x410A;
constexpr uint16_t VP_Level_Point_Four_X             = 0x410C;
constexpr uint16_t VP_Level_Point_Four_Y             = 0x410E;
constexpr uint16_t VP_Level_Point_Five_X             = 0x4110;
constexpr uint16_t VP_Level_Point_Five_Y             = 0x4112;


/* H43 Version */
constexpr uint16_t VP_MKS_H43_VERSION                = 0x4A00;   // MKS H43 V1.0.0
constexpr uint16_t VP_MKS_H43_VERSION_LEN            = 16;
constexpr uint16_t VP_MKS_H43_UpdataVERSION          = 0x4A10;   // MKS H43 V1.0.0
constexpr uint16_t VP_MKS_H43_UpdataVERSION_LEN      = 16;

/* -------------------------------0x5000-0xFFFF------------------------------- */
constexpr uint16_t VP_HOME_Dis                      = 0x5000;
constexpr uint16_t VP_Setting_Dis                   = 0x5010;
constexpr uint16_t VP_Tool_Dis                      = 0x5020;
constexpr uint16_t VP_Printing_Dis                  = 0x5030;

constexpr uint16_t VP_Language_Dis                  = 0x5080;
constexpr uint16_t VP_LossPoint_Dis                 = 0x5090;

constexpr uint16_t VP_PrintPauseConfig_Dis          = 0X5120;
constexpr uint16_t VP_MotorPluse_Dis                = 0x5140;
constexpr uint16_t VP_MotorMaxSpeed_Dis             = 0x5150;
constexpr uint16_t VP_MotorMaxAcc_Dis               = 0x5160;

constexpr uint16_t VP_X_Pluse_Dis                   = 0X5170;
constexpr uint16_t VP_Y_Pluse_Dis                   = 0X5180;
constexpr uint16_t VP_Z_Pluse_Dis                   = 0X5190;
constexpr uint16_t VP_E0_Pluse_Dis                  = 0X51A0;
constexpr uint16_t VP_E1_Pluse_Dis                  = 0X51B0;

constexpr uint16_t VP_X_Max_Speed_Dis               = 0X5280;
constexpr uint16_t VP_Y_Max_Speed_Dis               = 0X5290;
constexpr uint16_t VP_Z_Max_Speed_Dis               = 0X52A0;
constexpr uint16_t VP_E0_Max_Speed_Dis              = 0X52B0;
constexpr uint16_t VP_E1_Max_Speed_Dis              = 0X52C0;

constexpr uint16_t VP_X_Max_Acc_Speed_Dis           = 0X51E0;
constexpr uint16_t VP_Y_Max_Acc_Speed_Dis           = 0X51F0;
constexpr uint16_t VP_Z_Max_Acc_Speed_Dis           = 0X5200;
constexpr uint16_t VP_E0_Max_Acc_Speed_Dis          = 0X5210;
constexpr uint16_t VP_E1_Max_Acc_Speed_Dis          = 0X5220;


constexpr uint16_t VP_PrintTime_Dis                 = 0x5470;
constexpr uint16_t VP_E0_Temp_Dis                   = 0x5310;
constexpr uint16_t VP_E1_Temp_Dis                   = 0x5320;
constexpr uint16_t VP_HB_Temp_Dis                   = 0x5330;
constexpr uint16_t VP_Feedrate_Dis                  = 0x5350;
constexpr uint16_t VP_PrintAcc_Dis                  = 0x5340;
constexpr uint16_t VP_FAN_Speed_Dis                 = 0x5360;

constexpr uint16_t VP_Min_Ex_Temp_Dis               = 0x5380;


constexpr uint16_t VP_X_PARK_POS_Dis                = 0x53E0;
constexpr uint16_t VP_Y_PARK_POS_Dis                = 0X53F0;
constexpr uint16_t VP_Z_PARK_POS_Dis                = 0X5400;


constexpr uint16_t VP_TravelAcc_Dis                 = 0x5440;
constexpr uint16_t VP_FeedRateMin_Dis               = 0x5450;
constexpr uint16_t VP_TravelFeeRateMin_Dis          = 0x5460;
constexpr uint16_t VP_ACC_Dis                       = 0x5480;

constexpr uint16_t VP_Extrusion_Dis                 = 0x5230;
constexpr uint16_t VP_HeatBed_Dis                   = 0x5240;

constexpr uint16_t VP_Printting_Dis                 = 0x5430;
constexpr uint16_t VP_FactoryDefaults_Dis           = 0x54C0;
constexpr uint16_t VP_StoreSetting_Dis              = 0x54B0;
constexpr uint16_t VP_Info_EEPROM_2_Dis             = 0x54D0;
constexpr uint16_t VP_Info_EEPROM_1_Dis             = 0x54E0;

constexpr uint16_t VP_AutoLevel_1_Dis               = 0x55F0;

constexpr uint16_t VP_TMC_X_Step_Dis                = 0x5530;
constexpr uint16_t VP_TMC_Y_Step_Dis                = 0x5540;
constexpr uint16_t VP_TMC_Z_Step_Dis                = 0x5550;
constexpr uint16_t VP_TMC_X1_Current_Dis            = 0x5560;
constexpr uint16_t VP_TMC_Y1_Current_Dis            = 0x5570;
constexpr uint16_t VP_TMC_X_Current_Dis             = 0x5580;
constexpr uint16_t VP_TMC_Y_Current_Dis             = 0x5590;
constexpr uint16_t VP_TMC_Z_Current_Dis             = 0x55A0;
constexpr uint16_t VP_TMC_E0_Current_Dis            = 0x55B0;
constexpr uint16_t VP_TMC_E1_Current_Dis            = 0x55C0;
constexpr uint16_t VP_TMC_Z1_Current_Dis            = 0x55E0;

constexpr uint16_t VP_AutoLEVEL_INFO1               = 0x5600;
constexpr uint16_t VP_EX_TEMP_INFO1_Dis             = 0x5610;
constexpr uint16_t VP_EX_TEMP_INFO2_Dis             = 0x5620;
constexpr uint16_t VP_EX_TEMP_INFO3_Dis             = 0x5630;

constexpr uint16_t VP_Info_PrinfFinsh_1_Dis         = 0x5C00;
constexpr uint16_t VP_Info_PrinfFinsh_2_Dis         = 0x5C10;

constexpr uint16_t VP_Length_Dis                    = 0x5B00;

constexpr uint16_t VP_PrintConfrim_Info_Dis         = 0x5B90;
constexpr uint16_t VP_StopPrintConfrim_Info_Dis     = 0x5B80;

constexpr uint16_t VP_Point_One_Dis                 = 0x5BA0;
constexpr uint16_t VP_Point_Two_Dis                 = 0X5BB0;
constexpr uint16_t VP_Point_Three_Dis               = 0X5BC0;
constexpr uint16_t VP_Point_Four_Dis                = 0X5BD0;
constexpr uint16_t VP_Point_Five_Dis                = 0x5BE0;

constexpr uint16_t VP_Print_Dis                     = 0x5250;

constexpr uint16_t VP_About_Dis                     = 0x5A00;
constexpr uint16_t VP_Config_Dis                    = 0x5A10;
constexpr uint16_t VP_Filament_Dis                  = 0x5A20;
constexpr uint16_t VP_Move_Dis                      = 0x5A30;
constexpr uint16_t VP_Level_Dis                     = 0x5A50;
constexpr uint16_t VP_Speed_Dis                     = 0X5A70;
constexpr uint16_t VP_InOut_Dis                     = 0X5A80;

constexpr uint16_t VP_MotorConfig_Dis               = 0x5100;
constexpr uint16_t VP_LevelConfig_Dis               = 0x5110;
constexpr uint16_t VP_Advance_Dis                   = 0x5130;
constexpr uint16_t VP_TemperatureConfig_Dis         = 0x5390;

#endif






