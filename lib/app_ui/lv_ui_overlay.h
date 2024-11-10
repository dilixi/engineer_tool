#ifndef LV_UI_OVERLAY_H
#define LV_UI_OVERLAY_H

#include "core/lv_obj.h"
#include "lvgl.h"
#include "../ui.h" 
#include "utils_lib.h"
#include "panda_touch.h"

#include "lv_screen_home.h"
#include "lv_screen_ctrl.h"
#include "lv_screen_print.h"
#include "printer_group.h"

#define CONFIG_PWR_PANEL_Y_OFFSET             170

//void ui_screen_start_init(void);
void ui_img_mqtt_status_icon_set(lv_obj_t * parent, mqtt_status_t status);
void ui_context_mqtt_connect_flag_set(lv_obj_t * parent, connect_flag_t flag);

extern lv_obj_t * ui_screen_main;
extern lv_obj_t * ui_panel_ctl_title;

void ui_screen_create_notification(void);
// lv_screen_notification.cpp

// lv_screen_home.cpp
void ui_screen_create_home(void);

// lv_screen_ctrl.cpp


void ui_screen_create_power(void);

// lv_screen_ctrl_axis.cpp
typedef struct {
    MLG_TRANSLATE_DATA_T multi_lang_data;
    lv_obj_t * btn_img;
    lv_obj_t * btn_label_speed;
    lv_obj_t * img;
    lv_obj_t * meter;
    lv_meter_indicator_t * meter_indic_start;
    lv_meter_indicator_t * meter_indic_end;
    lv_meter_indicator_t * meter_indic_pointer;
    lv_obj_t * meter_label_speed;
    lv_obj_t * sw;
    lv_obj_t * sw_label;
} ui_fan_obj_t;

extern ui_fan_obj_t ui_fan_obj[3];

void ui_meter_fan_set_value(ui_fan_obj_t * fan_obj, uint8_t v);
lv_obj_t * ui_panel_create_axis(lv_obj_t * parent); 
lv_obj_t * ui_slider_list_create(lv_obj_t * parent, MLG_KEY_TYPE title, MLG_TRANSLATE_DATA_T * multi_lang_key, uint8_t min, uint8_t max);
void ui_slider_list_sel(lv_obj_t * parent, uint8_t sel);

// lv_screen_ctrl_filament.cpp
lv_obj_t * ui_panel_create_filament(lv_obj_t * parent);

// lv_screen_print.cpp
//void ui_screen_create_print(void);

// lv_screen_printers.cpp
void lv_loop_printers_create_printer(void);
void panel_mqtt_icon_clicked(lv_event_t * e);

void ui_panel_create_guide_printer_help(void);
void ui_screen_scan_printers_init(void);
void ui_screen_sel_model_init(void);

// lv_screen_setting.cpp
typedef struct {
    int32_t scan_state;
    int32_t connect_state;
    char connect_ssid[33];
    uint8_t bssid[6]; 
    lv_obj_t * connect_obj;
} lv_wifi_state_t;

void ui_screen_create_setting(void);
void lv_loop_setting_wifi_state(int32_t scan_state, wifi_status_t connect_state, bool need_update);
void btn_wifi_refresh_clicked(lv_event_t * e);

// lv_screen_printers.cpp
void ui_screen_create_printers(void);

// lv_widget_wifi.cpp
lv_obj_t * lv_wifi_rssi_icon_create(lv_obj_t * parent, int8_t level, lv_color_t c, lv_color_t bg_c);
lv_obj_t * lv_wifi_auth_icon_create(lv_obj_t * parent, lv_color_t c);
lv_obj_t * lv_wifi_connected_icon_create(lv_obj_t * parent);
lv_obj_t * lv_wifi_connecting_spin_create(lv_obj_t * parent);
lv_obj_t * lv_scanning_spin_create(lv_obj_t * parent, const char * text);
lv_obj_t * lv_wifi_scanned_list_create(lv_obj_t * parent);
lv_obj_t * lv_wifi_scan_create(lv_obj_t * parent, int32_t state);
int32_t lv_wifi_get_scan_state(lv_obj_t * panel);
lv_obj_t * lv_wifi_connect_create(lv_obj_t * parent, int32_t state);
int32_t lv_wifi_get_connect_state(lv_obj_t * panel);

// lv_widget_keyboard.cpp
typedef void (*lv_keyboard_ok_cb_t)(lv_obj_t * obj, const char * title, const char * text, void *user_data);

typedef struct {
    lv_obj_t * obj;
    lv_keyboard_ok_cb_t cb_t;
    uint8_t bssid[6];
} lv_keyboard_user_data_t;

lv_obj_t * lv_widget_keyboard_create(lv_obj_t * parent, const lv_keyboard_mode_t mode, const lv_keyboard_user_data_t * d,
                                    const char * title, const char * text, const char * placeholde, bool pwd_mode,
                                    uint32_t min_len, uint32_t max_len);

//typedef uint64_t ui_type_t;

// lv_widget_screen.cpp
//typedef enum : uint32_t {


#define UI_TYPE_IS_SCREEN(type) (((type) >> 31) & 0x1)
#define UI_TYPE_SCREEN_GET_MAIN_SCREEN(type) (ui_type_t)((uint32_t)(type) & 0xFFFF0000)
#define UI_TYPE_SCREEN_GET_BTN_LEFT(type) (ui_type_t)(((uint32_t)(type) >> 16) & 0x7F)
#define UI_TYPE_SCREEN_GET_BTN_TOP(type) (ui_type_t)((uint32_t)(type) & 0xFF)
#define UI_TYPE_BTN_LEFT_GET_SCREEN(type) (ui_type_t)((1 << 31) | ((uint32_t)(type) << 16))

typedef struct {
    const char *text;
    ui_type_t target_screen;
    MLG_TRANSLATE_DATA_T translate_data;
} ui_btn_ctl_top_t;

// lv_obj_t * ui_panel_create(lv_obj_t * parent, lv_coord_t radius, lv_color_t bg_c);
// lv_obj_t * ui_btn_img_create(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, lv_color_t bg_c, const void * img_src);
// lv_obj_t * ui_btn_label_create(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, lv_color_t bg_c, const char* text);
// lv_obj_t * ui_line_create(lv_obj_t * parent, const lv_point_t * points, uint16_t num, lv_coord_t w, lv_color_t color);
// lv_obj_t * ui_panel_create_index(lv_obj_t * parent, uint8_t i, lv_coord_t size, lv_color_t bg_c);
// lv_obj_t * ui_panel_create_index_dot(lv_obj_t * parent, uint8_t i, lv_coord_t size, lv_color_t bg_c);
//void ui_del_myself_clicked(lv_event_t * e);

// void ui_obj_set_type(lv_obj_t * obj, ui_type_t type);
// lv_obj_t * ui_obj_get(lv_obj_t * parent, ui_type_t type);

// lv_obj_t * ui_panel_create_left(lv_obj_t * parent);
lv_obj_t * ui_panel_create_top(lv_obj_t * parent, const ui_btn_ctl_top_t * btns, uint8_t num);
// void ui_btn_top_select(lv_obj_t * parent, ui_type_t type);
// void ui_screen_main_init(void);
// void ui_screen_select(ui_type_t type);


// lv_widget_popup.cpp
enum {
    UI_POPUP_BTN_RETRY,
    UI_POPUP_BTN_DONE,
    UI_POPUP_BTN_CLOSE,
    UI_POPUP_BTN_CANCEL,
    UI_POPUP_BTN_PAUSE,
    UI_POPUP_BTN_RESUME,
    UI_POPUP_BTN_STOP,    
    UI_POPUP_BTN_GOTO_FILAMENT,
    UI_POPUP_BTN_RESTART,
    UI_POPUP_BTN_FACTORY_RESTART,
    UI_POPUP_BTN_PRINTER_REMOVE,
    UI_POPUP_BTN_GROUP_REMOVE,
    UI_POPUP_BTN_CHANGE_MQTT_FLAG,
    UI_POPUP_BTN_REPRINT, 
    UI_POPUP_BTN_PRINT_REMIND,  
    UI_POPUP_BTN_MOVE, 
    UI_POPUP_BTN_HOME, 
};

typedef void (*lv_popup_cb_t)(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt);
typedef void (*lv_popup_account_cb_t)(uint32_t btn_id, const void * cb_data, void * account_info);

typedef struct {
    MLG_KEY_TYPE  text;
    const char *  text_str;
    //const char * qr_url;

     // max 3 btn
    uint8_t btn_num;
    MLG_KEY_TYPE btn_text[3];
    uint32_t btn_id[3];
    lv_popup_cb_t popup_cb;
    //lv_popup_account_cb_t pop_account_cb;
    const void * cb_data;
} ui_popup_t;


lv_obj_t * ui_panel_create_popup(const ui_popup_t * data, bambu_mqtt_t * mqtt);
lv_obj_t * ui_panel_create_popup_account(const ui_popup_t * data, bambu_account_info_t * account_info);
void ui_panel_del_popup(bambu_mqtt_t * mqtt);

// lv_screen_guide_wifi.cpp
void ui_screen_guide_wifi_init(void);
void ui_screen_guide_language_init(void);
void lv_loop_guide_wifi_state(int32_t scan_state, wifi_status_t connect_state);
void lv_loop_panel_account(void);

// lv_screen_guide_printer.cpp
typedef struct {
    MLG_KEY_TYPE name;
    MLG_KEY_TYPE placeholder;
    ui_type_t type;
    uint32_t cfg_offset;
    uint32_t min_len;
    uint32_t max_len;
    lv_event_cb_t translate_cb;
    lv_keyboard_mode_t keyboard_mode;
} lv_printer_config_t;
extern const lv_printer_config_t lv_printer_config[];

void ui_screen_guide_printer_init(uint32_t printer);

// lv_screen_notification.cpp
void panel_ctl_title_clicked(lv_event_t * e);
lv_obj_t * ui_panel_create_account(lv_obj_t * parent);
void ui_panel_del_popup_account(bambu_account_info_t * account_info);
void ui_img_cloud_status_icon_set(lv_obj_t * set_obj, bool set_en);
void ui_img_mqtt_status_icon_set(lv_obj_t * parent, mqtt_status_t status);
void panel_cloud_icon_clicked(lv_event_t * e);
void ui_img_pwr_status_icon_set(lv_obj_t * parent, bool is_online, bool is_bind_pwr);

lv_obj_t * ui_panel_create_power(lv_obj_t * parent);
lv_obj_t * ui_panel_create_pwr_data(lv_obj_t * parent, const void *img_src);  
lv_obj_t * ui_panel_create_pwr_data_w(lv_obj_t * parent, const void *img_src, lv_coord_t w);
lv_obj_t * ui_panel_create_popup_group(const ui_popup_t * data, printer_group_t * group);
void panda_pwr_group_control_pop(printer_group_t * group, ui_popup_t * data);
#endif /*LV_UI_OVERLAY_H*/
