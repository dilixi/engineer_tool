#ifndef UTILS_LIB_H
#define UTILS_LIB_H

#define CONOFIG_USING_COMMAND    2

#ifdef __cplusplus
extern "C" {
#endif

#include <mbedtls/net_sockets.h>
#include <mbedtls/ssl.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>

#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define pointer_type uint64_t 
#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "rs_multilang.h"
#include "rs_manage.h" 
#include "ui.h" 
#include "com_decode.h"
#include "bambu_mqtt.h" 
#include "printer_group.h" 
#include "com_with_pwr.h" 


#if 1
#include "../tools/lv_i18n/lv_i18n.h"  
#else
#include "lv_i18n.h"  
#endif

#define LCD_BACKLIGHT_MIN                          10
#define LCD_BACKLIGHT_MAX                          100
#define CONFIG_HISTORY_FILE_CNT_MAX                12

typedef pthread_t TaskHandle_t;
typedef sem_t TaskNotificationSemaphore_t;

// 任务参数结构体
typedef struct {
    const char *task_name;
    TaskNotificationSemaphore_t *notification;
} TaskParameters_t;


extern int xTaskCreate(void *(*task_function)(void *), const char *task_name, TaskParameters_t *parameters, TaskHandle_t *task_handle, int priority);
extern void vTaskDelete(TaskHandle_t *task_handle);
extern void ulTaskNotifyTake(TaskNotificationSemaphore_t *notification);
extern void xTaskNotifyGive(TaskNotificationSemaphore_t *notification);

typedef struct
{  
    MLG_KEY_TYPE key;
    lv_event_cb_t translate_cb; 
}MLG_TRANSLATE_DATA_T;

#define MLG_TRANSLATE_EVENT_T_SKIP              rs_translate_cb_skip 

#define RS_TRANSLATE_ONCE_ONLY(KEY)             _(KEY)
//#define MLG_TRANSLATE_INIT_ONCE(KEY)            _(KEY)
#define RS_TRANSLATE_DEFAULT_CB        NULL

#define millis get_current_millis

//typedef uint64_t ui_type_t;
typedef enum{
    UI_TYPE_ERROR = 0,

    UI_TYPE_PANEL_LEFT,
    UI_TYPE_BTN_LEFT_HOME,
    UI_TYPE_BTN_LEFT_CTRL,
    UI_TYPE_BTN_LEFT_PRINT,
    UI_TYPE_BTN_LEFT_SETTING,
    UI_TYPE_BTN_LEFT_PRINTERS,

    UI_TYPE_PANEL_TOP,

    UI_TYPE_BTN_TOP_CTRL_AXIS,
    UI_TYPE_BTN_TOP_CTRL_FILAMENT,
    UI_TYPE_BTN_TOP_CTRL_POWER,

    UI_TYPE_BTN_TOP_PRINT_MICROSDCARD,
    UI_TYPE_BTN_TOP_PRINT_USB_FLASH_DRIVER,
    UI_TYPE_BTN_TOP_PRINT_HISTORY,

    UI_TYPE_BTN_TOP_SETTING_GENERAL,
    UI_TYPE_BTN_TOP_SETTING_NETWORK,
    
    UI_TYPE_KEYBOARD_LABEL_TITLE,
    UI_TYPE_KEYBOARD_TEXTAREA_TXT,
    UI_TYPE_KEYBOARD_BTN_PWD_MODE,
    UI_TYPE_KEYBOARD_BTN_OK,
    UI_TYPE_KEYBOARD_BTN_CANCEL,

    UI_TYPE_IMG_MODEL,
    UI_TYPE_TEXTAREA_PRINTER_IP,
    UI_TYPE_TEXTAREA_PRINTER_ACCESS_CODE,
    UI_TYPE_TEXTAREA_PRINTER_SN,
    UI_TYPE_TEXTAREA_PRINTER_NAME,
    UI_TYPE_TEXTAREA_PRINTER_MODEL,
    UI_TYPE_TEXTAREA_PRINTER_NOZZLE_DIA,
    UI_TYPE_TEXTAREA_PRINTER_NOZZLE_MATERIAL,
    UI_TYPE_TEXTAREA_PRINTER_FILAMENT_MATERIAL,
    UI_TYPE_TEXTAREA_PRINTER_FILAMENT_COLOR,
    UI_TYPE_TEXTAREA_ACCOUNT_USER,
    UI_TYPE_TEXTAREA_ACCOUNT_PASSWORD,
    UI_TYPE_ACCOUNT_TYPE,

    UI_TYPE_TIPS_INDEX_0,
    UI_TYPE_TIPS_INDEX_1,
    UI_TYPE_TIPS_INDEX_2,
    UI_TYPE_TIPS_INDEX_3,
    UI_TYPE_TIPS_INDEX_4,
    UI_TYPE_TIPS_LABEL_0,
    UI_TYPE_TIPS_LABEL_1,
    UI_TYPE_TIPS_LABEL_2,
    UI_TYPE_TIPS_LABEL_3,
    UI_TYPE_TIPS_LABEL_4,

    UI_TYPE_LABEL_GCODE,
    // UI_TYPE_LABEL_POPUP,

    UI_TYPE_SLIDER,
    UI_TYPE_SLIDER_LABEL_0,
    UI_TYPE_SLIDER_LABEL_1,
    UI_TYPE_SLIDER_LABEL_2,
    UI_TYPE_SLIDER_LABEL_3,

    UI_TYPE_INDEX_LABEL,
    UI_TYPE_INDEX_PANEL,
    UI_TYPE_BAR,
    UI_TYPE_SPEED,
    UI_TYPE_STATUS,

    UI_TYPE_PRINT_FROM_USB,
    UI_TYPE_PRINT_FROM_PRINTER,

    UI_TYPE_TOP_INDEX_PANEL_0,
    UI_TYPE_TOP_INDEX_PANEL_1,
    UI_TYPE_TOP_INDEX_PANEL_2,
    UI_TYPE_TOP_INDEX_PANEL_3,
    UI_TYPE_TOP_INDEX_PANEL_4,
    UI_TYPE_TOP_INDEX_PANEL_5,
    UI_TYPE_TOP_INDEX_PANEL_6,
    UI_TYPE_TOP_INDEX_PANEL_7,
    UI_TYPE_TOP_INDEX_PANEL_8,
    UI_TYPE_TOP_INDEX_PANEL_9,

    /*
    * Screen
    * bit 31: screen flag
    * bit 30~16: btn left flag
    * bit 15~0: btn top flag
    */
    UI_TYPE_SCREEN_HOME = (1 << 31) | (UI_TYPE_BTN_LEFT_HOME << 16),     
    UI_TYPE_SCREEN_CTRL = (1 << 31) | (UI_TYPE_BTN_LEFT_CTRL << 16),
    UI_TYPE_SCREEN_PRINT = (1 << 31) | (UI_TYPE_BTN_LEFT_PRINT << 16),
    UI_TYPE_SCREEN_SETTING = (1 << 31) | (UI_TYPE_BTN_LEFT_SETTING << 16),
    UI_TYPE_SCREEN_PRINTERS = (1 << 31) | (UI_TYPE_BTN_LEFT_PRINTERS << 16),

    UI_TYPE_SCREEN_CTRL_AXIS = UI_TYPE_SCREEN_CTRL | (UI_TYPE_BTN_TOP_CTRL_AXIS << 0),
    UI_TYPE_SCREEN_CTRL_FILAMENT = UI_TYPE_SCREEN_CTRL | (UI_TYPE_BTN_TOP_CTRL_FILAMENT << 0),    
    UI_TYPE_SCREEN_CTRL_POWER = UI_TYPE_SCREEN_CTRL | (UI_TYPE_BTN_TOP_CTRL_POWER << 0),
    UI_TYPE_SCREEN_PRINT_MICROSDCARD = UI_TYPE_SCREEN_PRINT | (UI_TYPE_BTN_TOP_PRINT_MICROSDCARD << 0),
    UI_TYPE_SCREEN_PRINT_USB_FLASH_DRIVER = UI_TYPE_SCREEN_PRINT | (UI_TYPE_BTN_TOP_PRINT_USB_FLASH_DRIVER << 0),
    UI_TYPE_SCREEN_PRINT_HISTORY = UI_TYPE_SCREEN_PRINT | (UI_TYPE_BTN_TOP_PRINT_HISTORY << 0),
    UI_TYPE_SCREEN_SETTING_GENERAL = UI_TYPE_SCREEN_SETTING | (UI_TYPE_BTN_TOP_SETTING_GENERAL << 0),
    UI_TYPE_SCREEN_SETTING_NETWORK = UI_TYPE_SCREEN_SETTING | (UI_TYPE_BTN_TOP_SETTING_NETWORK << 0),
}ui_type_t;




// #include "esp_timer.h"
// #include "esp_lcd_panel_ops.h"
// #include "esp_lcd_panel_rgb.h"
// #include "esp_partition.h"
// #include <esp_http_server.h>  

#include "lvgl.h"

extern uint8_t *font_img_buffer;



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

  



#define COLOR_WHITE             0xFFFF
#define COLOR_BLACK             0x0
#define LCD_PCLK_HZ_UPDATE      10000000
#define LCD_V_RES_UPDATE        480
#define LCD_H_RES_UPDATE        480
#define LCD_BACKLIGHT_MIN       10
#define LCD_BACKLIGHT_MAX       100

#define LENGTH_OF_ARRAY(A)       sizeof(A)/sizeof(A[0])
#define PARTITION_LABEL_LAST     "coredump"
#define PARTITION_LABEL_SPIFFS   "spiffs"
#define PARTITION_LABEL_FONT     "font"
#define RG_STORAGE_ROOT          "/spiffs"
#define NOTIFY_CODE_EXIT_TASK        0xFF
#define NOTIFY_CODE_REBOOT           0xF0
#define NOTIFY_CODE_GOTO_UPDATING    0xF1
#define NOTIFY_CODE_STOP_FTPS        0xF2
#define NOTIFY_CODE_STOP_SCAN        0xF3
#define NOTIFY_CODE_UPDATE_SCAN      0xF4
#define NOTIFY_CODE_UPDATE_PNG       0xF5
#define NOTIFY_CODE_CONTINUE_PRINT   0xF6
#define NOTIFY_CODE_UPLOAD_U16_IMG   0xF7
#define NOTIFY_CODE_REFRESH_HISTORY  0xF8

#define NOTIFY_CODE_MSG_MAGIC        0xFF5AA5 

#define MANUAL_URL "https://bigtreetech.github.io/docs/PandaTouch.html"
#define MANUAL_OTA MANUAL_URL"#firmware"
#define MANUAL_HMS MANUAL_URL"#connection-troubleshooting"
#define MANUAL_CONNECTION MANUAL_URL"#finding-your-connection-details"

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

/*RESOURCE_DEFINE_START*/
#define CONFIG_FILE_SYSTEM_CRC       0x93c5d90f 
#define CONFIG_EXT_FONT_OFFSET_FNAME 0x000e9543 
#define CONFIG_EXT_FONT_OFFSET_F24 (CONFIG_EXT_FONT_OFFSET_FNAME+0x00000000) 

#define FONT_RESOURCE \
{\
    {\
        .min=0x0000, \
        .max=0x0000, \
        .offset=0, \
    }, \
    {\
        .min=0x003f, \
        .max=0x003f, \
        .offset=CONFIG_EXT_FONT_OFFSET_F24, \
    }, \
}

#define PICTURE_RESOURCE \
{\
    {0x04008005,0x00000000,0x00000c04,BF_PNG,&ui_img_humidity_0_png}, \
    {0x02805005,0x00000c04,0x000004b4,BF_PNG,&ui_img_info_png}, \
    {0x0a836805,0x000010b8,0x0000d69c,BF_PNG,&ui_img_y_inc_10_png}, \
    {0x0180c405,0x0000e754,0x000006e8,BF_PNG,&ui_img_pointer_png}, \
    {0x05204c05,0x0000ee3c,0x00000925,BF_PNG,&ui_img_z_dec_png}, \
    {0x03e06c05,0x0000f761,0x000009d3,BF_PNG,&ui_img_usb_on_png}, \
    {0x03c07805,0x00010134,0x00000a90,BF_PNG,&ui_img_nozzle_png}, \
    {0x03c07805,0x00010bc4,0x00000a90,BF_PNG,&ui_img_ele_used_png}, \
    {0x04008005,0x00011654,0x00000c04,BF_PNG,&ui_img_humidity_1_png}, \
    {0x03c07805,0x00012258,0x00000a90,BF_PNG,&ui_img_current_png}, \
    {0x0aa40805,0x00012ce8,0x00010102,BF_PNG,&ui_img_guide_3_en_png}, \
    {0x03406805,0x00022dea,0x000007f0,BF_PNG,&ui_img_region_png}, \
    {0x1c020405,0x000235da,0x000152a4,BF_PNG,&ui_img_x1_series_png}, \
    {0x1682d005,0x0003887e,0x00017bb4,BF_PNG,&ui_img_p1s_ams_png}, \
    {0x1682d005,0x00050432,0x00017bb4,BF_PNG,&ui_img_p1p_png}, \
    {0x0640c805,0x00067fe6,0x00001d50,BF_PNG,&ui_img_ctl_home_png}, \
    {0x0a223805,0x00069d36,0x000086ce,BF_PNG,&ui_img_y_inc_1_png}, \
    {0x04008005,0x00072404,0x00000c04,BF_PNG,&ui_img_humidity_4_png}, \
    {0x1682d005,0x00073008,0x00017bb4,BF_PNG,&ui_img_x1c_ams_png}, \
    {0x1682d005,0x0008abbc,0x00017bb4,BF_PNG,&ui_img_a1_png}, \
    {0x01e02c05,0x000a2770,0x000001f3,BF_PNG,&ui_img_network_speed_png}, \
    {0x1682d005,0x000a2963,0x00017bb4,BF_PNG,&ui_img_x1c_png}, \
    {0x0aa40805,0x000ba517,0x00010102,BF_PNG,&ui_img_guide_5_en_png}, \
    {0x0aa40405,0x000ca619,0x00010003,BF_PNG,&ui_img_guide_4_cn_png}, \
    {0x04402c05,0x000da61c,0x00000466,BF_PNG,&ui_img_q1_png}, \
    {0x04608c05,0x000daa82,0x00000e5f,BF_PNG,&ui_img_account_png}, \
    {0x02604005,0x000db8e1,0x00000394,BF_PNG,&ui_img_edit_png}, \
    {0x03807005,0x000dbc75,0x00000934,BF_PNG,&ui_img_reset_pwr_usage_png}, \
    {0x12826405,0x000dc5a9,0x00010960,BF_PNG,&ui_img_start_btt_logo_png}, \
    {0x04008005,0x000ecf09,0x00000c04,BF_PNG,&ui_img_close_png}, \
    {0x11c14405,0x000edb0d,0x000086ce,BF_PNG,&ui_img_x_inc_1_png}, \
    {0x03c07805,0x000f61db,0x00000a90,BF_PNG,&ui_img_speed_png}, \
    {0x1c023005,0x000f6c6b,0x00016f84,BF_PNG,&ui_img_a1_series_png}, \
    {0x1682d005,0x0010dbef,0x00017bb4,BF_PNG,&ui_img_p1p_ams_png}, \
    {0x1682d005,0x001257a3,0x00017bb4,BF_PNG,&ui_img_a1_mini_png}, \
    {0x0640c805,0x0013d357,0x00001d50,BF_PNG,&ui_img_led_off_png}, \
    {0x0560ac05,0x0013f0a7,0x000015af,BF_PNG,&ui_img_home_png}, \
    {0x0640c805,0x00140656,0x00001d50,BF_PNG,&ui_img_ctl_setting_png}, \
    {0x1a239805,0x001423a6,0x00023356,BF_PNG,&ui_img_btt_logo_png}, \
    {0x05a0b405,0x001656fc,0x000017bf,BF_PNG,&ui_img_stop_png}, \
    {0x1682d005,0x00166ebb,0x00017bb4,BF_PNG,&ui_img_p1s_png}, \
    {0x0aa40405,0x0017ea6f,0x00010003,BF_PNG,&ui_img_guide_3_cn_png}, \
    {0x1840c805,0x0018ea72,0x000071b0,BF_PNG,&ui_img_retract_png}, \
    {0x02807005,0x00195c22,0x00000694,BF_PNG,&ui_img_bigger_png}, \
    {0x03206405,0x001962b6,0x00000757,BF_PNG,&ui_img_little_fan_png}, \
    {0x1c020405,0x00196a0d,0x000152a4,BF_PNG,&ui_img_p1_series_png}, \
    {0x0780f005,0x001abcb1,0x00002a34,BF_PNG,&ui_img_login_failed_png}, \
    {0x03c07805,0x001ae6e5,0x00000a90,BF_PNG,&ui_img_temperature_png}, \
    {0x02805005,0x001af175,0x000004b4,BF_PNG,&ui_img_power_is_on_png}, \
    {0x1b415005,0x001af629,0x0000d69c,BF_PNG,&ui_img_x_dec_10_png}, \
    {0x03c07805,0x001bccc5,0x00000a90,BF_PNG,&ui_img_countdown_png}, \
    {0x03c07805,0x001bd755,0x00000a90,BF_PNG,&ui_img_humidity_png}, \
    {0x0aa40805,0x001be1e5,0x00010102,BF_PNG,&ui_img_guide_4_en_png}, \
    {0x0aa40405,0x001ce2e7,0x00010003,BF_PNG,&ui_img_guide_1_cn_png}, \
    {0x0aa40805,0x001de2ea,0x00010102,BF_PNG,&ui_img_guide_1_en_png}, \
    {0x02605805,0x001ee3ec,0x000004ea,BF_PNG,&ui_img_e_inc_png}, \
    {0x02805005,0x001ee8d6,0x000004b4,BF_PNG,&ui_img_cloud_enable_png}, \
    {0x10c75405,0x001eed8a,0x0002e07e,BF_PNG,&ui_img_guide_bg_png}, \
    {0x03806005,0x0021ce08,0x000007e4,BF_PNG,&ui_img_unbind_png}, \
    {0x11c14405,0x0021d5ec,0x000086ce,BF_PNG,&ui_img_x_dec_1_png}, \
    {0x05204c05,0x00225cba,0x00000925,BF_PNG,&ui_img_z_inc_png}, \
    {0x04008005,0x002265df,0x00000c04,BF_PNG,&ui_img_humidity_3_png}, \
    {0x02807005,0x002271e3,0x00000694,BF_PNG,&ui_img_smaller_png}, \
    {0x0640c805,0x00227877,0x00001d50,BF_PNG,&ui_img_ctl_print_png}, \
    {0x02805005,0x002295c7,0x000004b4,BF_PNG,&ui_img_mqtt_connect_png}, \
    {0x02605805,0x00229a7b,0x000004ea,BF_PNG,&ui_img_e_dec_png}, \
    {0x03c07805,0x00229f65,0x00000a90,BF_PNG,&ui_img_volt_png}, \
    {0x04402c05,0x0022a9f5,0x00000466,BF_PNG,&ui_img_q3_png}, \
    {0x03406805,0x0022ae5b,0x000007f0,BF_PNG,&ui_img_power_ctl_png}, \
    {0x00000003,0x0022b64b,0x0000561f,BF_GIF,&gif_hello}, \
    {0x0aa40805,0x00230c6a,0x00010102,BF_PNG,&ui_img_guide_2_en_png}, \
    {0x0640c805,0x00240d6c,0x00001d50,BF_PNG,&ui_img_ctl_printers_png}, \
    {0x0462bc05,0x00242abc,0x000047cb,BF_PNG,&ui_img_icon_knob_png}, \
    {0x05807405,0x00247287,0x00000ef8,BF_PNG,&ui_img_extruder_png}, \
    {0x19432805,0x0024817f,0x0001de30,BF_PNG,&ui_img_icon_model_png}, \
    {0x0a836805,0x00265faf,0x0000d69c,BF_PNG,&ui_img_y_dec_10_png}, \
    {0x02805405,0x0027364b,0x000004f0,BF_PNG,&ui_img_mqtt_disconnect_png}, \
    {0x03c07805,0x00273b3b,0x00000a90,BF_PNG,&ui_img_temp_png}, \
    {0x02805405,0x002745cb,0x000004f0,BF_PNG,&ui_img_cloud_disable_png}, \
    {0x1682d005,0x00274abb,0x00017bb4,BF_PNG,&ui_img_a1_mini_ams_png}, \
    {0x1840c805,0x0028c66f,0x000071b0,BF_PNG,&ui_img_extrude_png}, \
    {0x1b415005,0x0029381f,0x0000d69c,BF_PNG,&ui_img_x_inc_10_png}, \
    {0x04809005,0x002a0ebb,0x00000f34,BF_PNG,&ui_img_menu_png}, \
    {0x0640c805,0x002a1def,0x00001d50,BF_PNG,&ui_img_led_on_png}, \
    {0x0640c805,0x002a3b3f,0x00001d50,BF_PNG,&ui_img_ctl_ctl_png}, \
    {0x0a223805,0x002a588f,0x000086ce,BF_PNG,&ui_img_y_dec_1_png}, \
    {0x02004005,0x002adf5d,0x00000304,BF_PNG,&ui_img_dot_png}, \
    {0x02805405,0x002ae261,0x000004f0,BF_PNG,&ui_img_power_is_off_png}, \
    {0x0aa40405,0x002ae751,0x00010003,BF_PNG,&ui_img_guide_2_cn_png}, \
    {0x0640c805,0x002be754,0x00001d50,BF_PNG,&ui_img_wifi_png}, \
    {0x04008005,0x002c04a4,0x00000c04,BF_PNG,&ui_img_power_ctl_big_png}, \
    {0x05a0b405,0x002c10a8,0x000017bf,BF_PNG,&ui_img_pause_png}, \
    {0x03c07805,0x002c2867,0x00000a90,BF_PNG,&ui_img_power_png}, \
    {0x03e06c05,0x002c32f7,0x000009d3,BF_PNG,&ui_img_usb_off_png}, \
    {0x04408805,0x002c3cca,0x00000d90,BF_PNG,&ui_img_q2_png}, \
    {0x05a0b405,0x002c4a5a,0x000017bf,BF_PNG,&ui_img_resume_png}, \
    {0x04008005,0x002c6219,0x00000c04,BF_PNG,&ui_img_humidity_2_png}, \
    {0x1682d005,0x002c6e1d,0x00017bb4,BF_PNG,&ui_img_a1_ams_png}, \
    {0x0aa40405,0x002de9d1,0x00010003,BF_PNG,&ui_img_guide_5_cn_png}, \
    {0x03c07805,0x002ee9d4,0x00000a90,BF_PNG,&ui_img_hotbed_png}, \
}

/*RESOURCE_DEFINE_END*/
#define UT_CONFIG_MAX_MMAP_SIZE                   0x400000
#define CONFIG_OFFSET_TTF_OPPO                    0
#define CONFIG_OFFSET_TTF_CALIBRA                 0x0012E7C4
#define CONFIG_OFFSET_TTF_YUGOTHM                 0x00131BE8
#define CONFIG_OFFSET_FAT_PARTITION               0x910000UL
#define CONFIG_PARTITION_SIZE_TOTAL               0x6E0000UL 
#define CONFIG_LAST_PARTITION_OFFSET              0x8000  
#define CONFIG_SECTOR_SIZE                        4096
#define CONFIG_ADD_FILE_MAGIC                     0xADDF5AA5
#define CONFIG_ADD_FILE_MAX_CNT                   3


typedef enum
{
    LANG_1=0,
    LANG_2,
    LANG_3,
    LANG_MAX,
}LANGUAGE_T;


#define CONFIG_REMIND_ERROR_FILESYSTEM            "Please update Filesystem"
typedef enum
{
    GD_UPDATE_CONNECT_TO_WIFI,
    GD_UPDATE_CONNECT_WIFI_FAILED,
    GD_UPDATE_OTA,
    GD_UPDATE_MAX=0,
}update_step_t; 

typedef struct{
    uint16_t min;
    uint16_t max;
    uint32_t offset;
}x_header_check_t;
  
typedef struct{
    uint16_t min;
    uint16_t max;
    uint8_t  bpp;
    uint8_t  reserved[3];
}x_header_t;

typedef struct{
    uint32_t pos;
}x_table_t;

// typedef struct{
//     uint8_t adv_w;
//     uint8_t box_w;
//     uint8_t box_h;
//     int8_t  ofs_x;
//     int8_t  ofs_y;
//     uint8_t r;
// }glyph_dsc_t;

typedef enum
{
    UT_RES_INVALID_TYPE=-127,
    UT_RES_INVALID_DATA,
    UT_RES_RESOURCE_HAS_BEED_LOADED,
    UT_RES_CALLBACK_EMPTY,
    UT_RES_INVALID_UP_FILE,
    UT_RES_INVALID_FAT_IMG,
    UT_RES_INVALID_FONT_IMG,
    UT_RES_INVALID_PARTITION,
    UT_RES_ERROR,
    UT_RES_OK=0,
}rs_res_t;

typedef enum {
    FT_LANGUAGE = 0xF1,  // 词条的 bin 文件
    FT_PANDA_PNG,          // PNG 的 bin 文件
    FT_CUSTOM_FONT,
    FT_MAX
} add_file_t;

#define UT_MIN(a, b)            \
({                          \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a < _b ? _a : _b;      \
})
#define UT_MAX(a, b)            \
({                          \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a > _b ? _a : _b;      \
})

extern const uint8_t UT_FONT_CNT;
extern uint8_t ut_str_split(char *src,const char *separator,char **dest);
extern uint8_t ut_str_not_blank(char *p_str);
extern uint32_t ut_strlen(const char *s);
extern char * ut_strlower(char * str);
 
extern void ut_lcd_put_str(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,const char *p);
extern void ut_lcd_put_point(uint16_t x,uint16_t y,uint16_t color);
extern void ut_lcd_clear(uint16_t color); 
extern int8_t ut_img_load_from_offset(lv_img_dsc_t * get_dsc_t, uint32_t offset); 
extern int8_t ut_lib_init(uint8_t *p_img_buf); 
extern void ut_lcd_update(void);
extern void ut_lcd_waitconfig(void);
extern void ut_lcd_setconfig(void);
extern void ut_lcd_printf(const char *fmt,...);
extern bool lvgl_port_lock(uint32_t timeout_ms);
extern void lvgl_port_unlock(void); 
extern void ui_screen_guide_update(lv_obj_t *parent);
extern lv_obj_t * ui_screen_main;
extern void lv_loop_guide_wifi_state_update(void);
extern void rs_set_local_update(void); 
extern volatile uint32_t font_data_offset;
extern uint8_t rs_check_lang_invalid(void);

extern void at_cmd_init(void);  
extern volatile uint8_t file_system_is_updating;
extern void ut_lcd_printf_at(uint16_t x, uint16_t y, const char *fmt,...);
extern void ut_goto_updating_filesystem(void); 
extern void lv_loop_guide_state_update(void);
extern void * ut_get_map_ptr(void); 
extern void update_ui_task(void * parameter);
extern void lvgl_hal_init(void);
extern void lvgl_hal_deinit(void);

extern lv_font_t * font_16_variable; 
extern lv_font_t * font_24_variable; 
extern lv_font_t * font_16_fname; 
extern lv_font_t opensansb16_fname; 
extern lv_font_t opensansb24_fname; 
#define LV_FONT_16_VARIABLE font_16_variable
#define LV_FONT_24_VARIABLE font_24_variable

extern void lvgl_hal_set_backlight(uint8_t percent,bool save);
extern uint8_t lvgl_hal_get_backlight(void);
extern uint8_t current_backlight_percent;
extern void ui_top_tile_refresh_require(void);
extern void ui_notification_refresh_require(void);
extern void ui_printers_set_refresh(void);

extern void hal_enter_sleep(void);
extern void hal_exit_sleep(void);

extern uint32_t ut_get_img_total_size(void);

#define  CONFIG_WORK_PATH_CACHE            "/cache/"
#define  CONFIG_WORK_PATH_ROOT             "/"
 
#define  CONFIG_DEFAULT_PATH_USB           CONFIG_WORK_PATH_ROOT
  
#define  CONFIG_3MF_THUMBNAIL_PATH         "/image/"
#define  CONFIG_3MF_THUMBNAIL_WIDTH         128
#define  CONFIG_3MF_THUMBNAIL_HEIGHT        128 
#define  CONFIG_3MF_PREVIEW_DATA_SIZE       CONFIG_3MF_THUMBNAIL_WIDTH*CONFIG_3MF_THUMBNAIL_HEIGHT*2
#define  CONFIG_HOME_3MF_THUMBNAIL_WIDTH    168  // 200 168
#define  CONFIG_HOME_3MF_THUMBNAIL_HEIGHT   168  // 200 168
#define  CONFIG_3MF_THUMBNAIL_BG_COLOR      0x575757

typedef enum
{
    WORK_DIR_CACHE=0,
    WORK_DIR_ROOT, 
    WORK_DIR_MAX,
}work_path_t;

#define GET_DEFAULT_WORK_DIRECTORY(IDX) ((WORK_DIR_CACHE == IDX)?(CONFIG_WORK_PATH_CACHE):(CONFIG_WORK_PATH_ROOT))

typedef enum
{
    FILE_TYPE_3MF=0,
    FILE_TYPE_DIR,
    FILE_TYPE_ROOT,  
    FILE_TYPE_PNG,
    FILE_TYPE_MAX,
}file_type_3mf_t;

typedef enum
{
    SORT_BY_DATA_NEW=0,
    SORT_BY_DATA_OLD,
    SORT_BY_NAME_A_Z,
    SORT_BY_NAME_Z_A,
    SORT_BY_NAME_MAX,
}ui_3mf_sorted_t;

typedef enum
{
    USB_REFRESH_NONE, 
    USB_REFRESH_ING,
    USB_REFRESH_OK_NORMAL,
    USB_REFRESH_OK_THUMBNAIL, 
    USB_REFRESH_MAX,
}ui_usb_refresh_t;

typedef enum
{
    HISTORY_REFRESH_NONE, 
    HISTORY_REFRESH_ING,
    HISTORY_REFRESH_OK_NORMAL,
    HISTORY_REFRESH_OK_THUMBNAIL=HISTORY_REFRESH_OK_NORMAL, 
    HISTORY_REFRESH_ONLY_CLOUD,
    HISTORY_REFRESH_MAX,
}ui_history_refresh_t;

typedef enum
{ 
    FILE_SHOW_TYPE_NORMAL=USB_REFRESH_OK_NORMAL,
    FILE_SHOW_TYPE_THUMBNAIL=USB_REFRESH_OK_THUMBNAIL, 
    UFILE_SHOW_TYPE_MAX,
}ui_usb_show_t;

typedef enum
{
    FILT_TASK_MSG_NONE,
    FILT_TASK_MSG_CHANGE_TO_NORMAL=1,
    FILT_TASK_MSG_CHANGE_TO_THUMBNAIL,
    FILT_TASK_MSG_SORT_BY_DATE_NEW,
    FILT_TASK_MSG_SORT_BY_DATE_OLD,
    FILT_TASK_MSG_SORT_BY_NAME_A_Z,
    FILT_TASK_MSG_SORT_BY_NAME_Z_A, 
    FILT_TASK_MSG_CHANGE_DIR,
    FILT_TASK_MSG_FILE_REFRESH,
    FILT_TASK_MSG_CONTINUE_PRINT,
    FILT_TASK_MSG_MAX,
}file_task_msg_id_t;

typedef struct 
{  
    uint32_t magic;
    uint8_t id;
    bool is_root;
    char data[256]; 
    TaskHandle_t task_handle;
    void *user_data;
}file_task_msg_t;

/*mqtt*/
typedef struct 
{
    uint8_t printer_index;
    uint8_t printer_cnt; 
}bambu_mqtt_sync_t;

typedef struct 
{
    uint8_t account_index; 
    uint8_t account_cnt;
}bambu_account_sync_t;


/*3MF FILE*/
typedef enum
{ 
    DECODE_3MF_RES_OPEN_FAILED=-127,  
    DECODE_3MF_RES_NOT_FIND_TAG,  
    DECODE_3MF_RES_MALLOC_ERR,
    DECODE_3MF_RES_READ_ERR,
    DECODE_PNG_ERR,
    DECODE_PNG_RESIZE_ERR,
    DECODE_3MF_RES_OK=0,
}usb_3mf_decode_res_t;

#define FILE_3MF_COUNT_MAX             255
#define FTPS_GCODES_WITH_THUMBNAIL_NUM 24 //20

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
} file_time_t;

typedef struct 
{
    uint8_t type;
    uint32_t size;
    file_time_t time;
    uint32_t timestamp;
    lv_img_dsc_t img_data;
    char dir[128]; 
    char print_need_time[32];
    char weight[32];
    uint32_t png_data_length; /*用于从usb发起打印时上传图片*/
    bool thumbnail_is_valid;
    char * name; 
    uint8_t *png_file_data; 
    lv_obj_t *btn;
    lv_obj_t *panel;
} file_gcode_t;

typedef struct 
{ 
    volatile uint8_t list_type;
    volatile bool is_inserted;
    volatile bool is_list_ok;
    volatile uint8_t refresh_type;
    volatile uint8_t sort_type;
    volatile uint8_t show_type; 
    volatile int32_t file_count;
    volatile int32_t file_3mf_count;
    volatile int32_t file_img_count;
    uint32_t thumbnail_valid_cnt;
    file_task_msg_t file_task_msg; 
    char current_path[256];
    char file_name[512];
    file_gcode_t back_folder;
    file_gcode_t files[FILE_3MF_COUNT_MAX]; 
    lv_obj_t *panel;
} file_list_3mf_t;



extern file_list_3mf_t *usb_3mf_list;
extern file_list_3mf_t *printer_3mf_list; 

extern void nvs_config_set_changed(void);
extern void nvs_config_pwr_set_changed(void);

extern bambu_mqtt_sync_t mqtt_sync_data;
extern bambu_account_sync_t account_sync_data;
extern bool mqtt_sync_lock(uint32_t timeout_ms);
extern void mqtt_sync_unlock(void);

extern void initial_uart(void);
extern void put_bytes(uint8_t *buff, uint32_t bytes);
extern uint32_t ftime_2_timestamp(file_time_t ftime) ;
extern void file_sort_by_timestamp(file_gcode_t *file, int32_t count, bool reversed);
extern void file_sort_by_name(file_gcode_t *file, int32_t count, bool reversed);


extern void btn_3mf_file_sorted_by_data_clicked(lv_event_t * e);
extern void btn_3mf_file_sorted_by_name_clicked(lv_event_t * e);
extern unsigned lodepng_decode32(unsigned char** out, unsigned* w, unsigned* h,
                          const unsigned char* in, size_t insize);
  
extern void file_3mf_list_arrange(file_list_3mf_t *file_list);
extern void file_3mf_list_free(file_gcode_t * dst, uint32_t max_file_num); 
extern bool file_3mf_list_at_root(file_list_3mf_t *file_list);
extern void ut_convert_color_depth(uint8_t * img, uint32_t px_cnt);
extern void ut_convert_color_depth_blend (uint8_t *out_img, uint8_t *img, uint16_t width, uint16_t height, uint32_t bg_color);

extern lv_obj_t * ui_gcodes_list_create(file_list_3mf_t *file_list, lv_obj_t * parent, lv_event_cb_t cb);

extern void wifi_init_data(void);
extern size_t strlcpy(char *dst, const char *src, size_t size) ;


#define esp_psram_malloc malloc
#define esp_psram_realloc realloc

#define BAT_REG_VERSION     0x10
#define BAT_REG_ADC_BAT     0x11
#define BAT_REG_ADC_5V      0x12

typedef enum
{
    COMP_T_PLUS=1,
    COMP_T_SUB, 
}bat_status_compensate_t;

typedef struct 
{
    volatile bool is_charging;
    volatile uint8_t percent;
    volatile uint16_t fw_version; 
    volatile uint8_t percent_change_times;
    volatile int compensate;
    volatile int compensate_plus;
    volatile int16_t bat_mv_5v;
    volatile int16_t bat_mv_source;
    volatile int16_t bat_mv;
    volatile int16_t bat_mv_change_backlight; 
    volatile int16_t source_mv_change_backlight; 
    volatile uint8_t compensate_type; 
    volatile uint8_t backlight_changed_before;
    volatile int64_t tick_update_bat;
    /*如果是背光调小了，则获取调节前后的ADC值差值，再使用这个差值作为补偿*/
}bat_status_t;

extern bat_status_t current_bat_status;
extern uint8_t bat_percent_to_level(uint8_t percent); 
extern uint32_t hardware_crc32_all(uint8_t *source, uint32_t length);
extern void i2c_master_init_stm32(void);
//extern uint8_t wifi_get_channel_from_scanned_list(void);

extern int rt_kprintf(const char *fmt, ...);


extern volatile uint32_t backlight_setting_tick;
extern volatile uint8_t backlight_setting;
 

typedef struct
{
    char name[32+1]; 
}multi_lang_name_t;
  
typedef struct
{
    bool is_valid;
    float temperature;
    float humidity;
}aht20_data_t;

typedef struct 
{  
    bool is_inserted;
    uint32_t tick_update;
    volatile uint8_t refresh_type;
    uint32_t file_count;
    file_task_msg_t file_task_msg; 
    bambu_print_history_t files[CONFIG_HISTORY_FILE_CNT_MAX]; 
} file_list_history_t;

extern aht20_data_t g_aht20_data; 
extern uint8_t g_language; 

extern void rs_set_local(uint8_t set_lang);
extern multi_lang_name_t lang_names[3];
extern void rs_set_local_only(uint8_t set_lang);

#define RS_TRANSLATE(KEY)            _(KEY)


#define pdMS_TO_TICKS(m) m

extern uint32_t xTaskGetTickCount(void);
extern volatile uint32_t delay_tick_config;
extern void notify_update_3mf_preview(void);
extern bool mac_address_is_valid(uint8_t *mac_address);
extern uint8_t bambu_get_nvs_index(const nvs_config_t * nvs);
extern uint8_t bambu_get_mqtt_index(const bambu_mqtt_t * mqtt);
extern void mqtt_bambu_data_reprint_get(bambu_data_t *data, print_continue_check_t *out_check);
extern bool mqtt_one_client_print_project_file_local(bambu_mqtt_t * mqtt, const char * path, const char * name, bool bed_leveling, bool flow_cali, bool timelapse, bool use_ams, bool clear_power_usage, bool auto_power_off);

extern bool mqtt_one_client_ledctrl(bambu_mqtt_t * mqtt, const char *ctrl);

extern void mqtt_bambu_data_reprint_reset(bambu_data_t *data);
extern bool mqtt_one_client_print_ctrl(bambu_mqtt_t * mqtt, const char * cmd);
extern bool mqtt_one_client_ams_ctrl(bambu_mqtt_t * mqtt, const char *v);
extern bool mqtt_one_client_clean_print_error(bambu_mqtt_t * mqtt);

extern bool mqtt_ledctrl(const char *ctrl);
extern bool mqtt_gcode_line(const char *gcodes);
extern bool mqtt_set_spd_lvl(const char * spd_lvl);
extern bool mqtt_ams_change_filament(uint32_t target, bool unload);
extern bool mqtt_ams_ctrl(const char * cmd);
extern bool mqtt_clean_print_error(void);

 
#define BAMBU_DATA_MASTER (bambu_mqtt_master->bambu_data)

extern void bambu_mqtt_memory_init(void);

extern bool bambu_mqtt_is_printing(const bambu_mqtt_t * mqtt);
extern bool bambu_mqtt_in_print_task(const bambu_mqtt_t * mqtt);

extern bool bambu_mqtt_is_connected(bambu_mqtt_t * mqtt);
extern bambu_mqtt_t * bambu_get_mqtt_connected(void);
extern nvs_config_t * bambu_get_nvs_config(uint8_t index);
extern nvs_config_t * bambu_printer_find_mainly_ctrl(void);

extern bool bambu_printer_index_valid(uint32_t idx_check);
extern void ui_screen_create_home(void);
extern uint8_t printer_nvs_idx_to_sorted_idx(uint8_t nvs_index);
extern uint8_t printer_sorted_idx_to_nvs_idx(uint8_t idx);

extern uint32_t get_current_millis();

/*ui api*/
extern void lv_loop_home(void);

extern void ui_screen_start_init(void);

extern void lv_loop_start(void);

extern lv_obj_t * ui_panel_create_home_idle_screen(lv_obj_t * parent);

extern const lv_img_dsc_t * ui_img_src_get_printer_series(bambu_model_t model);

extern lv_img_dsc_t ui_img_icon_model_png_bak;
extern lv_img_dsc_t ui_img_icon_model_png_new;

extern lv_obj_t * ui_obj_get(lv_obj_t * parent, ui_type_t type);

extern void btn_auto_power_off_clicked(lv_event_t * e);
extern lv_obj_t * ui_btn_label_create(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, lv_color_t bg_c, const char * text);
extern lv_obj_t * ui_panel_create_index(lv_obj_t * parent, uint8_t i, lv_coord_t size, lv_color_t bg_c);

extern void btn_power_off_clicked(lv_event_t * e);
extern void btn_usb_ctl_clicked(lv_event_t * e);
extern void btn_reset_pwr_usage_clicked(lv_event_t * e);

extern void ui_screen_select(ui_type_t type);
//extern lv_obj_t * ui_panel_create_popup(const ui_popup_t * data, bambu_mqtt_t * mqtt);
extern lv_obj_t * ui_btn_img_create(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, lv_color_t bg_c, const void * bg_img_src);
extern lv_obj_t * ui_panel_create(lv_obj_t * parent, lv_coord_t radius, lv_color_t bg_c);
extern void ui_obj_set_type(lv_obj_t * obj, ui_type_t type); 
extern void ui_btn_top_select(lv_obj_t * parent, ui_type_t type);
extern void ui_del_myself_clicked(lv_event_t * e) ;
extern lv_obj_t * ui_line_create(lv_obj_t * parent, const lv_point_t * points, uint16_t num, lv_coord_t w, lv_color_t color);

extern void ui_img_cloud_status_icon_set(lv_obj_t * set_obj, bool set_en);

extern void ui_img_mqtt_status_icon_set(lv_obj_t * parent, mqtt_status_t status);
extern void ui_img_pwr_status_icon_set(lv_obj_t * obj, bool is_online, bool is_valid_mac);



extern uint8_t panda_pwr_is_opened;

extern void ui_screen_create_ctrl(void);
#define BIT(n) (1UL << (n)) 

extern void wifi_sync_unlock(void);
extern bool wifi_sync_lock(uint32_t timeout_ms);

extern bool mqtt_one_client_ams_filament_setting(bambu_mqtt_t * mqtt, uint8_t ams_id, uint8_t tray_id, uint32_t color, const idx_data_t * p_idx);

extern void lv_loop_home(void);
extern void lv_loop_filament(void);
extern void lv_loop_ctrl_axis(void);
 

//typedef void* TaskHandle_t;
extern int8_t file_3mf_list_init(file_list_3mf_t **p_3mf_list,const char *default_path, TaskHandle_t task_handle);


extern TaskHandle_t t_handle_wifi;
extern TaskHandle_t t_handle_lvgl; 
extern TaskHandle_t t_handle_mqtt; 
extern TaskHandle_t t_handle_account; 
extern TaskHandle_t t_handle_ftps;
extern TaskHandle_t t_handle_usb;


extern void ui_screen_create_print_task(const char * filename, uint32_t type);
extern void ui_screen_create_print(void);
extern void lv_loop_files_list_history(void);
extern void lv_loop_files_list_usb(void);
extern void lv_loop_files_list_ftps(void);
extern void file_list_init(void);

/*task*/
extern void ftps_task(void * parameter);

extern void delay(uint32_t ms);

extern uint64_t esp_timer_get_time(void);

extern void notify_to_account_task(uint32_t set_val);


/*nvs variable*/
extern uint8_t nvs_ftps_work_path_idx;


extern void refresh_udp_background(char *check_sn);

extern void bambu_mqtt_add_default_path(const char *);


extern lv_obj_t * ui_gcodes_list_create_thumbnail_card(file_list_3mf_t *file_3mf_list, lv_obj_t * parent, lv_event_cb_t cb);

extern int8_t png_decoder_and_resize(uint8_t *input_png_data, uint32_t input_png_size, uint16_t new_width, uint16_t new_height, uint8_t *out_buffer, uint32_t bg_color);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*UTILS_LIB_H*/
