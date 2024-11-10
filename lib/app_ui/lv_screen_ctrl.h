#ifndef LV_SCREEN_CTRL_H
#define LV_SCREEN_CTRL_H

#include "lvgl.h"
#include "bambu_mqtt.h"

typedef enum {
    AMS_SUPPORTED,
    AMS_TNOT_SUPPORTED_TPU,
    AMS_WARNING_CF_GF,
    AMS_WARNING_PVA,
} ams_support_status_t;

typedef struct {    
    const char * filament_type;
    // const char * tray_type;
    const char * tray_info_idx;
    const uint32_t nozzle_temp_min;
    const uint32_t nozzle_temp_max;
    ams_support_status_t ams_support; 
    // uint8_t dry_temp;
    // uint8_t dry_time;
} idx_data_t;

// typedef struct {
//     uint8_t ams_id;
//     uint8_t tray_id;
// } ams_tray_id_t;

typedef union {
    struct {
        uint8_t ams_id;
        uint8_t tray_id;
    };
    uint16_t full;
} ams_tray_id_t;

typedef struct {
    uint8_t manuf_id;
    uint8_t type_id;
} filament_id_t;

#define UI_TRAY_SHOWN_IMG &ui_img_pwd_mode_png
#define UI_TRAY_EDIT_IMG &ui_img_edit_png

// lv_screen_ctrl_filament.cpp
void ui_panel_filament_bg_color_set(lv_obj_t * obj, uint32_t c);
lv_obj_t * ui_panel_create_fliament_sel(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, uint32_t c, uint32_t border_c);

// lv_screen_ctrl_filament_tray.cpp
filament_id_t idx_data_get_index(const char * tray_info_idx);
const idx_data_t * idx_data_get_array(filament_id_t id);
tray_t * ams_tray_get_tray(uint32_t tray_now);
lv_obj_t * ui_panel_create_tray_shown(lv_obj_t * parent, tray_t * tray);
lv_obj_t * ui_panel_create_tray_edit(lv_obj_t * parent, tray_t * tray);

#endif /*LV_SCREEN_CTRL_H*/
