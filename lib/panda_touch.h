#ifndef PANDA_TOUCH_H
#define PANDA_TOUCH_H

#include "config.h"
#include "rs_multilang.h"

typedef void (*p_function_t)(void);

// Macros for array numbers
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
// Macros to make a string from a macro
#define STRINGIFY_(M) #M
#define STRINGIFY(M)  STRINGIFY_(M)

#define MEM_SIZE(type, member)       sizeof(((type*)0)->member)
#define OFFSETOF(type, member)       ((size_t)(&(((type*)0)->member)))

#define MIN_TO_SEC(n)  ((n) * 60)
#define HOUR_TO_SEC(n) MIN_TO_SEC((n) * 60)
#define SEC_TO_MIN(n)  ((n) / 60)
#define SEC_TO_HOUR(n) SEC_TO_MIN((n) / 60)

//#include <WiFi.h>
#include "lvgl.h"

#define RSSI_LEVEL_NUM 4
#define MIN_RSSI -100
#define MAX_RSSI -55
int wifiCalculateSignalLevel(int rssi, int numLevels);

#define MAX_LEN_SSID 33
#define MAX_LEN_PWD 65

typedef struct {
    char sta_ssid[MAX_LEN_SSID];
    char sta_pwd[MAX_LEN_PWD];
    wifi_auth_mode_t sta_auth;
    uint8_t bssid[6];
    // char mode[6]; // "ap":WIFI_MODE_AP, "sta":WIFI_MODE_STA, "apsta":WIFI_MODE_APSTA 
} nvs_wifi_config_t;

typedef struct {
    int32_t rssi[SCAN_SSIDS_NUM]; // RSSI returned RSSI values
    char ssid[SCAN_SSIDS_NUM][65]; // SSIDs returned by the wifi scan.
    uint8_t bssid[SCAN_SSIDS_NUM][6];
    wifi_auth_mode_t authmode[SCAN_SSIDS_NUM]; // encryptionType 
    uint8_t connected[SCAN_SSIDS_NUM];
    //uint8_t channel[SCAN_SSIDS_NUM];
    uint8_t count; // Number of WiFi Scanned
} screen_wifi_scan_t;

typedef enum {
    WIFI_STATUS_ERROR, // no station ssid or connect failed
    WIFI_STATUS_CONNECTING,
    WIFI_STATUS_CONNECTED,
    WIFI_STATUS_DISCONNECT,
    WIFI_STATUS_INIT, 
    WIFI_STATUS_PASSWORD_ERROR,
    WIFI_STATUS_MAX, 
} wifi_status_t;

typedef struct {
    wifi_status_t connect_status;
    int32_t scan_status;
    screen_wifi_scan_t record;
    uint32_t connected_tick;
    nvs_wifi_config_t nvs_wifi_config;
} wifi_data_t;
 
//extern wifi_data_t wifi_data;
extern wifi_data_t *g_wifi_data;

#define WEB_POST_NULL                 (0)
// #define WEB_POST_LOCAL_HOSTNAME       BIT(0)
#define WEB_POST_WIFI_CONFIG_STA      BIT(0)
#define WEB_POST_WIFI_REFRESH         BIT(1)
#define WEB_POST_RESTART              BIT(2)

void screen_config_require_change(uint16_t require);
void wifi_scan_refresh_set_callback(p_function_t cb);
wifi_auth_mode_t wifi_get_ahth_mode_from_scanned_list(void);

wifi_status_t wifi_get_connect_status(void);

#define WIFI_SCAN_INIT 0
#define WIFI_SCAN_COMPLETED 1
int32_t wifi_get_scan_status(void);
bool wifi_sync_lock(uint32_t timeout_ms);
void wifi_sync_unlock(void);
bool wifi_bssid_is_valid(uint8_t *bssid);
void wifi_dump_bssid(uint8_t *bssid);  

#endif
