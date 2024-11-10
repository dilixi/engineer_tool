#ifndef CONFIG_H
#define CONFIG_H

//#define SCREEN_SHOT_TO_SD  // Default: commented (disabled)
#define SW_PRINT_ALL 1
#define FW_VERSION  "V1.0.6 beta1"

#define wifi_auth_mode_t uint8_t 
 // default 80 for http
#define SERVER_PORT 80
#define SCAN_SSIDS_NUM 20     //  The max number of SSIDs that we will scan for.
#define CONFIG_REPLACE_BSSID_MIN_RSSI     10
#define CONFIG_WIFI_SSID_MS_IVT_REPLACE   60000UL
#define CONFIG_WIFI_MS_IVT_RECONNECT      10000UL
#define HOSTNAME "Panda-Touch"
 
#define WIFI_STA_TIMEOUT 15000  // 15s
#define CONFIG_ACCOUNT_DEVICES_UPDATE_IVT_MS  (1000*60*1UL)
#define CONFIG_MQTT_CLOUD_PUSHALL_IVT_MS      16000UL
#define CONFIG_MQTT_CLOUD_PUSHALL_PWR_IVT_MS  1000UL//1500UL
#define CONFIG_MBEDTLS_READ_TIMEOUT_MS        60000UL
#define CONFIG_TIMEOUT_MS_CLOUD_MQTT          20000UL   
#define CONFIG_IVT_MS_CHECK_ACCOUNT_ONLINE    10000UL
#define CONFIG_SYNC_TIMEOUT_MS                50000UL

//#define CONFIG_BAT_UPDATE_IVT_MS              (2000UL)
#define CONFIG_BAT_UPDATE_DELAY_MS            (2000UL)
#define CONFIG_MIN_CHANGE_VALUE               (15)
#define CONFIG_MAX_CHANGE_VALUE               (2000)
#define CONFIG_BAT_DRAW_IVT_MS                (500UL)

#define CONFIG_BAT_FIRMWARE_VERSION           0xEE01

//#define CONFIG_AHT20_UPDATE_IVT_MS            (2000UL)

// BTT red color for UI (RGB888)
//
#define LV_32BIT_BTT_RED        0xC02F30
#define LV_32BIT_BTT_BLUE       0x209ADE
#define LV_32BIT_BTT_PURPLE     0xA91DDA
#define LV_32BIT_BTT_GREEN      0x5DA910
#define LV_32BIT_BTT_GRAY       0x353835
#define LV_32BIT_BTT_GRAY_BG    0x575757
#define LV_32BIT_BIT_YELLOW     0xF9C326

#define LV_32BIT_BTT_GRAY_DISCONNECT    0x929292
#define LV_32BIT_BTT_BLUE_SYNC          0x1C8DE4
#define LV_32BIT_BTT_YELLOW_SLAVE       0xFBED13
#define LV_32BIT_BTT_RED_MASTER         0xCB3434
#define LV_32BIT_COLOR_PRINTER_TYPE_IMG 0x838383
#define LV_32BIT_COLOR_PRINTING         0x714444//0xFFC700 //0xAA5500 4D
#define LV_32BIT_COLOR_ADD_BUTTON       LV_32BIT_BTT_RED_MASTER
#define LV_32BIT_COLOR_REPRINT          0xff9f09
#define LV_32BIT_COLOR_STATUS           0x4cd112
#define LV_32BIT_COLOR_POP_BG           0x363636 
 

#define LV_DEFAULT_COLOR    LV_32BIT_BTT_RED

#define WIFI_SIGNAL_BACKGROUND 0x666666

#define MANUAL_URL "https://bigtreetech.github.io/docs/PandaTouch.html"
#define MANUAL_OTA MANUAL_URL"#firmware"
#define MANUAL_HMS MANUAL_URL"#connection-troubleshooting"
#define MANUAL_CONNECTION MANUAL_URL"#finding-your-connection-details"

#endif
