#ifndef LV_I18N_H
#define LV_I18N_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

#define MLG_KEY_TYPE uint32_t


typedef enum
{ 
  K_INVALID_ID=0,
  K_LANG_NAME_T=0x0001,
  K_MIN_TIME_T_1=0x0002,
  K_MIN_TIME_T_2=0x0003,
  K_MIN_TIME_T_3=0x0004,
  K_MIN_TIME_T_5=0x0005,
  K_MIN_TIME_T_10=0x0006,
  K_MIN_TIME_T_15=0x0007,
  K_MIN_TIME_T_60=0x0008,
  K_SLEEP_TIME_T_ALWAYS=0x0009,
  K_SETTING_GEN_T=0x000A,
  K_SETTING_NET_T=0x000B,
  K_SETTING_GEN_T_DEV=0x000C,
  K_SETTING_GEN_T_MAN=0x000D,
  K_SETTING_GEN_T_LANG=0x000E,
  K_SETTING_GEN_T_FW=0x000F,
  K_SETTING_GEN_T_SLP=0x0010,
  K_SETTING_GEN_T_BACKLIGHT=0x0011,
  K_SETTING_GEN_T_REB=0x0012,
  K_SETTING_GEN_T_RST=0x0013,
  K_BTN_CANCEL=0x0014,
  K_BTN_OK=0x0015,
  K_BTN_RESTART=0x0016,
  K_BTN_REFRESH=0x0017,
  K_BTN_CONFIRM=0x0018,
  K_BTN_NEXT=0x0019,
  K_BTN_BACK=0x001A,
  K_BTN_DEL=0x001B,
  K_BTN_SCAN=0x001C,
  K_BTN_FACTORY=0x001D,
  K_BTN_CLOSE=0x001E,
  K_BTN_IGNORE_ALL=0x001F,
  K_BTN_LOAD=0x0020,
  K_BTN_UNLOAD=0x0021,
  K_BTN_RETRY=0x0022,
  K_BTN_ABORT=0x0023,
  K_BTN_PRINT=0x0024,
  K_BTN_REMOVE=0x0025,
  K_BTN_STOP=0x0026,
  K_BTN_PAUSE=0x0027,
  K_BTN_RESUME=0x0028,
  K_BTN_FILAMENT=0x0029,
  K_BTN_DONE=0x002A,
  K_BTN_STOP_ALL=0x002B,
  K_BTN_FORMAT=0x002C,
  K_BTN_DISCONNECT=0x002D,
  K_BTN_EDIT=0x002E,
  K_BTN_YES=0x002F,
  K_BTN_NO=0x0030,
  K_BTN_RESET=0x0031,
  K_BTN_ADD_PRINTER=0x0032,
  K_BTN_ADD_GROUP=0x0033,
  K_BTN_GOTO_PRINTERS=0x0034,
  K_BTN_GOTO_WIFI=0x0035,
  K_BTN_IGNORE=0x0036,
  K_BTN_GOTO_LOGIN=0x0037,
  K_BTN_DRY=0x0038,
  K_BTN_DRY_PREPARE=0x0039,
  K_BTN_DRY_START=0x003A,
  K_SET_NET_WIFI_SCANED=0x003B,
  K_WELCOME_TIP=0x003C,
  K_TIP_SCAN_QRCODE=0x003D,
  K_LOADING=0x003E,
  K_TOP_WIFI_CONNECT=0x003F,
  K_TOP_WIFI_CONNECT_FAIL=0x0040,
  K_TOP_WIFI_DISCONNECTED=0x0041,
  K_TOP_PRINT_CONNECTING=0x0042,
  K_TOP_PRINT_CONNECTED=0x0043,
  K_TOP_PRINT_CONNECT_FAIL=0x0044,
  K_PANDA_TOUCH=0x0045,
  K_PRINTER_MODEL=0x0046,
  K_PRINTER_NAME=0x0047,
  K_SCAN_PRINT_T_ACESCD=0x0048,
  K_SCAN_PRINT_T_IP=0x0049,
  K_FILAMENT_T_COLOR=0x004A,
  K_FILAMENT_T_MATRL=0x004B,
  K_NOZZLE_T_DIAMETER=0x004C,
  K_NOZZLE_T_MATRL=0x004D,
  K_WIFI_C_WAIT_CANCEL=0x004E,
  K_PRINT_BED_LEVELING=0x004F,
  K_PRINT_FLOW_CALIBRATION=0x0050,
  K_PRINT_TIMELAPSE=0x0051,
  K_PRINTS_IN_SYNC=0x0052,
  K_START_PRINT_CONFIRM=0x0053,
  K_PRINT_USING_AMS=0x0054,
  K_PRINT_AMS=0x0055,
  K_PRINT_CANCELED=0x0056,
  K_PRINT_FINISHED=0x0057,
  K_PRINT_REPRINT=0x0058,
  K_BED_PREHEATING=0x0059,
  K_NOZZLE_CLEAN=0x005A,
  K_BED_AUTO_LEVEING=0x005B,
  K_PRINT_PREPARING=0x005C,
  K_PRINT_T=0x005D,
  K_PRINT_NOT_FIND=0x005E,
  K_FILAMENT_UNKNOWN=0x005F,
  K_PRINTER_ADD_REPEAT=0x0060,
  K_PRINTER_HAS_ADD=0x0061,
  K_PRINTER_BUSY=0x0062,
  K_NOZZLE_TEMPERATURE=0x0063,
  K_BAMBU_INFO_READONLY=0x0064,
  K_SETTING_SLOT_NOT_SUP=0x0065,
  K_FILAMENT_MINIMUM=0x0066,
  K_FILAMENT_MAXIMUM=0x0067,
  K_FILAMENT_UNKNOWN_TYPE=0x0068,
  K_TIP_INPUT_OPTIONAL=0x0069,
  K_TIP_INPUT_NAME=0x006A,
  K_TIP_INPUT_IP=0x006B,
  K_TIP_INPUT_ACESCD=0x006C,
  K_TIP_INPUT_SN=0x006D,
  K_POP_TIP_ADD_DEV=0x006E,
  K_POP_TIP_RESTART=0x006F,
  K_POP_TIP_INPUT_PASSWORD=0x0070,
  K_POP_TIP_FACTORY=0x0071,
  K_NEW_TIP_GET_INFO=0x0072,
  K_POP_TIP_PRINT_ABORT=0x0073,
  K_TIP_NOT_INSERT_SDCARD=0x0074,
  K_TIP_NOT_INSERT_USB_FLASH=0x0075,
  K_TIP_NOT_SELECT_PRINT=0x0076,
  K_TIP_REMOVE_REFUSE=0x0077,
  K_TIP_REMOVE_CONFIRM=0x0078,
  K_TIP_MASTER_MUST=0x0079,
  K_TIP_MAINLY_QUERY=0x007A,
  K_TIP_PRINTER_MAX=0x007B,
  K_TIP_PAUSE_ALL=0x007C,
  K_TIP_STOP_ALL=0x007D,
  K_TIP_FAILD_UPLOAD=0x007E,
  K_TIP_WIFI_DISCONNECTED=0x007F,
  K_TIP_WIFI_ERROR=0x0080,
  K_TIP_UNLOAD_HAS_FILAMENT=0x0081,
  K_TIP_UNLOAD_HAS_FILAMENT_L=0x0082,
  K_TIP_LOAD_NO_FILAMENT=0x0083,
  K_TIP_LOAD_NO_FILAMENT_L=0x0084,
  K_TIP_LOAD_FILAMENT=0x0085,
  K_TIP_HEATBREAK_FAN=0x0086,
  K_TIP_PARSING_GCODE=0x0087,
  K_TIP_NOZZLE_TEMP_MALF=0x0088,
  K_TIP_FRONT_COVER=0x0089,
  K_TIP_FILAMENT_RUNOUT=0x008A,
  K_TIP_PAUSE_PRINT=0x008B,
  K_TIP_STOP_PRINT=0x008C,
  K_TIP_AMS_RUNOUT=0x008D,
  K_TIP_AMS_OVERLOAD=0x008E,
  K_TIP_FAILED_FEED=0x008F,
  K_TIP_FAILED_PULL=0x0090,
  K_TIP_FAILED_EXTRUDE=0x0091,
  K_TIP_FAILED_FEED_OUTSIDE=0x0092,
  K_TIP_SELECT_MODEL=0x0093,
  K_TIP_AMS_BUSY=0x0094,
  K_TIP_AMS_READING=0x0095,
  K_TIP_AMS_TRAY_EMPTY=0x0096,
  K_TIP_FIRMWARE=0x0097,
  K_NOTIFY_CENTER_T=0x0098,
  K_NOTIFY_CNT_T=0x0099,
  K_NOTIFY_REMIND=0x009A,
  K_NOTIFY_REMIND_GO_PRINT=0x009B,
  K_NOTIFY_UNKNOW_STATE=0x009C,
  K_00X0300100000020001=0x009D,
  K_00X0300100000020002=0x009E,
  K_00X03000F0000010001=0x009F,
  K_00X03000D000001000B=0x00A0,
  K_00X03000D0000010003=0x00A1,
  K_00X03000D0000010004=0x00A2,
  K_00X03000D0000010005=0x00A3,
  K_00X03000D0000010006=0x00A4,
  K_00X03000D0000010007=0x00A5,
  K_00X03000D0000010008=0x00A6,
  K_00X03000D0000010009=0x00A7,
  K_00X03000D000001000A=0x00A8,
  K_00X03000D0000020001=0x00A9,
  K_00X03000A0000010005=0x00AA,
  K_00X03000A0000010004=0x00AB,
  K_00X03000A0000010003=0x00AC,
  K_00X03000A0000010002=0x00AD,
  K_00X03000A0000010001=0x00AE,
  K_00X0300040000020001=0x00AF,
  K_00X0300030000020002=0x00B0,
  K_00X0300030000010001=0x00B1,
  K_00X0300060000010001=0x00B2,
  K_00X0300060000010002=0x00B3,
  K_00X0300060000010003=0x00B4,
  K_00X0300010000010007=0x00B5,
  K_00X0300130000010001=0x00B6,
  K_00X0300180000010005=0x00B7,
  K_00X0300190000010001=0x00B8,
  K_00X0300190000020002=0x00B9,
  K_00X0300400000020001=0x00BA,
  K_00X0300410000010001=0x00BB,
  K_00X0300020000010001=0x00BC,
  K_00X0300020000010002=0x00BD,
  K_00X0300020000010003=0x00BE,
  K_00X0300020000010006=0x00BF,
  K_00X0300020000010007=0x00C0,
  K_00X0300120000020001=0x00C1,
  K_00X0300180000010001=0x00C2,
  K_00X0300180000010002=0x00C3,
  K_00X0300180000010003=0x00C4,
  K_00X0300180000010004=0x00C5,
  K_00X03001A0000020001=0x00C6,
  K_00X03001A0000020002=0x00C7,
  K_00X0C00010000010001=0x00C8,
  K_00X0C00010000020002=0x00C9,
  K_00X0C00010000010003=0x00CA,
  K_00X0C00010000010004=0x00CB,
  K_00X0C00010000010005=0x00CC,
  K_00X0C00010000020006=0x00CD,
  K_00X0C00010000020007=0x00CE,
  K_00X0C00010000020008=0x00CF,
  K_00X0C00010000010009=0x00D0,
  K_00X0C0001000001000A=0x00D1,
  K_00X0C0001000002000B=0x00D2,
  K_00X0C00020000010001=0x00D3,
  K_00X0C00020000020002=0x00D4,
  K_00X0C00020000020003=0x00D5,
  K_00X0C00020000020004=0x00D6,
  K_00X0C00020000010005=0x00D7,
  K_00X0C00020000020006=0x00D8,
  K_00X0C00030000020001=0x00D9,
  K_00X0C00030000020002=0x00DA,
  K_00X0C00030000020004=0x00DB,
  K_00X0C00030000020005=0x00DC,
  K_00X0C00030000030006=0x00DD,
  K_00X0C00030000030007=0x00DE,
  K_00X0C00030000030008=0x00DF,
  K_00X0C00030000010009=0x00E0,
  K_00X0C0003000003000B=0x00E1,
  K_00X0C0003000002000C=0x00E2,
  K_00X0500010000020001=0x00E3,
  K_00X0500010000020002=0x00E4,
  K_00X0500010000020003=0x00E5,
  K_00X0500010000030004=0x00E6,
  K_00X0500010000030005=0x00E7,
  K_00X0500010000030006=0x00E8,
  K_00X0500020000020001=0x00E9,
  K_00X0500020000020005=0x00EA,
  K_00X0500020000020002=0x00EB,
  K_00X0500020000020004=0x00EC,
  K_00X0500020000020006=0x00ED,
  K_00X0500030000010001=0x00EE,
  K_00X0500030000010002=0x00EF,
  K_00X0500030000010003=0x00F0,
  K_00X050003000001000A=0x00F1,
  K_00X050003000001000B=0x00F2,
  K_00X050003000002000C=0x00F3,
  K_00X0500040000010001=0x00F4,
  K_00X0500040000010002=0x00F5,
  K_00X0500040000010003=0x00F6,
  K_00X0500040000010004=0x00F7,
  K_00X0500040000010006=0x00F8,
  K_00X0500040000020007=0x00F9,
  K_00X0700010000010001=0x00FA,
  K_00X0700010000010003=0x00FB,
  K_00X0700010000010004=0x00FC,
  K_00X0700010000020002=0x00FD,
  K_00X0700020000010001=0x00FE,
  K_00X0700100000010001=0x00FF,
  K_00X0700100000010003=0x0100,
  K_00X0700100000020002=0x0101,
  K_00X0700200000020001=0x0102,
  K_00X1200200000020001=0x0103,
  K_00X0700200000020002=0x0104,
  K_00X0700200000020003=0x0105,
  K_00X0700200000020004=0x0106,
  K_00X0700200000020005=0x0107,
  K_00X0700200000030001=0x0108,
  K_00X0700200000030002=0x0109,
  K_00X0700400000020001=0x010A,
  K_00X0700400000020002=0x010B,
  K_00X0700400000020003=0x010C,
  K_00X0700400000020004=0x010D,
  K_00X0700450000020001=0x010E,
  K_00X0700450000020002=0x010F,
  K_00X0700450000020003=0x0110,
  K_00X0700510000030001=0x0111,
  K_00X0700500000020001=0x0112,
  K_00X0700600000020001=0x0113,
  K_00X1200100000020002=0x0114,
  K_00X1200800000020001=0x0115,
  K_00X07FF200000020001=0x0116,
  K_00X07FF200000020002=0x0117,
  K_00X07FF200000020004=0x0118,
  K_00X12FF200000020007=0x0119,
  K_00X1200200000020006=0x011A,
  K_CTL_TOP_T_TEMP_AXIS=0x011B,
  K_CTL_TOP_T_FILAMENT=0x011C,
  K_CTL_T_PART=0x011D,
  K_CTL_T_AUX=0x011E,
  K_CTL_T_CHAMBER=0x011F,
  K_SW_T_ON=0x0120,
  K_SW_T_OFF=0x0121,
  K_CTL_T_SPEED=0x0122,
  K_CTL_T_SPEED_SILENT=0x0123,
  K_CTL_T_SPEED_STANDARD=0x0124,
  K_CTL_T_SPEED_SPORT=0x0125,
  K_CTL_T_SPEED_LUDICROUS=0x0126,
  K_CTL_T_EXTRUDER=0x0127,
  K_CTL_T_TEMP_HIGH=0x0128,
  K_CTL_T_FILAMENT_T_TIP=0x0129,
  K_CTL_T_FILAMENT_TIP=0x012A,
  K_CTL_T_TO_LOAD=0x012B,
  K_CTL_T_TO_UNLOAD=0x012C,
  K_CTL_T_HEAT_NOZZLE_TEMP=0x012D,
  K_CTL_T_PUSH_NEW_FILAMENT=0x012E,
  K_CTL_T_GRAB_NEW_FILAMENT=0x012F,
  K_CTL_T_PURGE_OLD_FILAMENT=0x0130,
  K_CTL_T_CUT_FILAMENT=0x0131,
  K_CTL_T_BACK_FILAMENT=0x0132,
  K_CONTENT_EMPTY=0x0133,
  K_TPU_NOT_SUPPORTED=0x0134,
  K_CF_GF_WARNING=0x0135,
  K_PVA_WARNING=0x0136,
  K_CTL_T_MQTT_CTL_MODE=0x0137,
  K_CTL_T_MQTT_STATU_MASTER=0x0138,
  K_CTL_T_MQTT_STATU_SLAVE=0x0139,
  K_CTL_T_MQTT_STATUS_SYNC=0x013A,
  K_CTL_T_MQTT_DISCONECTED=0x013B,
  K_PRINTER_CONNECTING=0x013C,
  K_PRINTER_DISCONNECTED=0x013D,
  K_PRINTER_CONNECTED=0x013E,
  K_MQTT_LOGIN_FAILED=0x013F,
  K_MQTT_NEVER_CONNECTED=0x0140,
  K_MQTT_MASTER_CHANGED=0x0141,
  K_MQTT_MASTER_ERROR=0x0142,
  K_MQTT_SLAVE=0x0143,
  K_MQTT_NOT_ONLINE=0x0144,
  K_FILE_T_USB_FLASH_DRIVER=0x0145,
  K_FILE_T_NAME=0x0146,
  K_FILE_T_DATE=0x0147,
  K_FILE_T_SIZE=0x0148,
  K_FILE_S_TRANSMITTING=0x0149,
  K_FILE_S_PRINTERS_IN_SYNC=0x014A,
  K_FILE_S_FAILED=0x014B,
  K_FILE_S_PRINTING=0x014C,
  K_FILE_S_WAITING=0x014D,
  K_GUID_T_START=0x014E,
  K_GUID_C_START=0x014F,
  K_GUID_T_GET_IP_ACCESS=0x0150,
  K_GUID_C_GET_IP_ACCESS_WLAN=0x0151,
  K_GUID_C_GET_IP_ACCESS_ENTER=0x0152,
  K_GUID_T_GET_SN=0x0153,
  K_GUID_C_GET_SN_RETURN=0x0154,
  K_GUID_C_GET_SN_ENTER=0x0155,
  K_GUID_C_GET_SN_ENTER_CODE=0x0156,
  K_GUID_T_COMPLETED=0x0157,
  K_GUID_C_COMPLETED=0x0158,
  K_SN=0x0159,
  K_GUID_UNABLE_FIND=0x015A,
  K_GUIDE_SELECT_LANG=0x015B,
  K_GUIDE_OTA_NOT_FINISHED=0x015C,
  K_GUIDE_OTA_REMIND=0x015D,
  K_GUID_OTA_CONNECT_WIFI=0x015E,
  K_TIP_ABOUT_REGION=0x015F,
  K_TIP_DEL_ACCOUNT=0x0160,
  K_TIP_INPUT_PHONE=0x0161,
  K_TIP_INPUT_EMAIL=0x0162,
  K_T_REGION=0x0163,
  K_T_ACCOUNT=0x0164,
  K_T_PASSWORD=0x0165,
  K_T_REGION_CHINA=0x0166,
  K_T_REGION_GLOBAL=0x0167,
  K_TIP_PHONE_INCORRECT=0x0168,
  K_TIP_EMAIL_INCORRECT=0x0169,
  K_TIP_ACCOUNT_NOT_REG=0x016A,
  K_TIP_PASSWORD_INCORRECT=0x016B,
  K_TIP_NETWORK_ERROR=0x016C,
  K_TIP_LOGIN_OK=0x016D,
  K_TIP_ACCOUNT_SYNC_OK=0x016E,
  K_TIP_ACCOUNT_SYNC_ERROR=0x016F,
  K_TIP_ACCOUNT_SYNC_ZERO=0x0170,
  K_TIP_PRINTER_WITHOUT_CLOUD=0x0171,
  K_TIP_PRINTER_LOGIN_ACCOUNT=0x0172,
  K_TIP_ACCOUNT_ERROR=0x0173,
  K_TIP_ACCOUNT_NETWORK_ERROR=0x0174,
  K_T_LOGIN_BAMBU=0x0175,
  K_TIP_CONVERT_TO_CLOUD=0x0176,
  K_T_ENABLE_COULD=0x0177,
  K_TIP_WIFI_NOT_CONNECTED=0x0178,
  K_TIP_PRINTER_WORK_IN_CLOUD=0x0179,
  K_TIP_PRINTER_WORK_IN_LOCAL=0x017A,
  K_TIP_FTP_IP_INVALID=0x017B,
  K_TIP_FTP_NOT_FIND=0x017C,
  K_TIP_GROUP_PRINTER_CLOUD_MODE=0x017D,
  K_TIP_GROUP_PRINTER_LOCAL_MODE=0x017E,
  K_TIP_GROUP_WORK_IN_CLOUD=0x017F,
  K_TIP_GROUP_WORK_IN_LOCAL=0x0180,
  K_TIP_PRINTER_GROUP_MAX=0x0181,
  K_TIP_ONE_MASTER_AT_LEAST=0x0182,
  K_TIP_ONE_SELECT_AT_LEAST=0x0183,
  K_TIP_REMOVE_GROUP_CONFIRM=0x0184,
  K_TIP_GROUP_SAME_NAME=0x0185,
  K_TIP_PRINTER_IN_GROUP=0x0186,
  K_TIP_REPRINT_GROUP_PRINTER=0x0187,
  K_TIP_REPRINT_PRINTER=0x0188,
  K_TIP_WAITING_PRINT_FINISHED=0x0189,
  K_TIP_GROUP_CONNECTED=0x018A,
  K_TIP_GROUP_PRINTER_DISCONNECTED=0x018B,
  K_TIP_GROUP_PRINTER_CONNECTING=0x018C,
  K_TIP_GROUP_PRINTER_PRINTING=0x018D,
  K_TIP_GROUP_PRINTER_TEMP_TOO_HIGH=0x018E,
  K_TIP_GROUP_PRINTER_FILE_CONFIG=0x018F,
  K_TIP_GROUP_POWER_OFF=0x0190,
  K_TIP_GROUP_RESET_POWER_USAGE=0x0191,
  K_TIP_GROUP_POWER_OFF_NOT_ONLINE=0x0192,
  K_TIP_GROUP_PRINTING_NOT_IDLE=0x0193,
  K_TIP_GROUP_TEMP_TOO_HIGH_CONFIRM=0x0194,
  K_T_IS_PRINTING=0x0195,
  K_T_IS_IDLE=0x0196,
  K_TIP_ENTER_GROUP_NAME=0x0197,
  K_TIP_MOVE_CONFIRM=0x0198,
  K_TIP_ALWAYS_SLEEP=0x0199,
  K_TIP_BIND_POWER=0x019A,
  K_TIP_REMOVE_KEEP_ONE=0x019B,
  K_TIP_REMOVE_PRINTER_WITH_POWER=0x019C,
  K_TIP_ABOUT_POWER=0x019D,
  K_TIP_POWER_OFF_NOT_ONLINE_CONFIRM=0x019E,
  K_TIP_POWER_OFF_TEMP_TOO_HIGH_CONFIRM=0x019F,
  K_TIP_POWER_OFF_CONFIRM=0x01A0,
  K_TIP_AUTO_POWER_OFF_CONFIRM=0x01A1,
  K_T_AUTO_POWER_OFF=0x01A2,
  K_T_MIN=0x01A3,
  K_T_COUNTDOWN=0x01A4,
  K_T_POWER=0x01A5,
  K_TIP_KNOW_POWER=0x01A6,
  K_TIP_ADD_POWER=0x01A7,
  K_T_VOLTAGE=0x01A8,
  K_T_CURRENT=0x01A9,
  K_T_POWER_2=0x01AA,
  K_T_POWER_USAGE=0x01AB,
  K_T_PRINTER=0x01AC,
  K_T_POWER_WIFI=0x01AD,
  K_T_POWER_USB_FOLLOW=0x01AE,
  K_T_USB_CONFIG_OFF=0x01AF,
  K_T_USB_CONFIG_ON=0x01B0,
  K_T_MUST_HIGH=0x01B1,
  K_T_MUST_LESS=0x01B2,
  K_T_POWER_PRINTER_NO=0x01B3,
  K_TIP_CONFIRM_BIND_POWER=0x01B4,
  K_TIP_CONFIRM_UNBIND_POWER=0x01B5,
  K_T_RESET_POWER_USAGE=0x01B6,
  K_T_RESET_POWER_USAGE_PRINT=0x01B7,
  K_TIP_CONFIRM_RESET_POWER_USAGE=0x01B8,
  K_T_AUTO_OFF=0x01B9,
  K_T_POWER_OFF_ALL=0x01BA,
  K_T_PWR_HAS_BEEN_BIND=0x01BB,
  K_TIP_PWR_MAX=0x01BC,
  K_T_POWER_OFF_AFTER_PRINTING=0x01BD,
  K_TIP_CHANGE_REBOOT=0x01BE,
  K_T_MULTI_PRINT_HEAT_DELAY=0x01BF,
  K_T_FILE_T_HISTORY=0x01C0,
  K_T_HISTORY_COST_TIME=0x01C1,
  K_T_HISTORY_WEIGHT=0x01C2,
  K_T_HISTORY_ONLY_CLOUD=0x01C3,
  K_T_HISTORY_NOT_FIND=0x01C4,
  K_T_DRY_FILAMENT_STEPS=0x01C5,
}singulars_idx_t;

////////////////////////////////////////////////////////////////////////////////

typedef struct {
    MLG_KEY_TYPE msg_id;
    const char * translation;
} lv_i18n_phrase_t;

typedef struct {
    const char * locale_name;
    lv_i18n_phrase_t * singulars; 
} lv_i18n_lang_t;

// Null-terminated list of languages. First one used as default.
typedef const lv_i18n_lang_t * lv_i18n_language_pack_t;


extern const lv_i18n_language_pack_t lv_i18n_language_pack[];


/**
 * Set the languages for internationalization
 * @param langs pointer to the array of languages. (Last element has to be `NULL`)
 */
int lv_i18n_init(const lv_i18n_language_pack_t * langs);

/**
 * Change the localization (language)
 * @param l_name name of the translation locale to use. E.g. "en_GB"
 */
int lv_i18n_set_locale(const char * l_name);

/**
 * Get the translation from a message ID
 * @param msg_id message ID
 * @return the translation of `msg_id` on the set local
 */
const char * lv_i18n_get_text(MLG_KEY_TYPE msg_id); 


void __lv_i18n_reset(void);


#define _(text) lv_i18n_get_text(text) 


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_LANG_H*/