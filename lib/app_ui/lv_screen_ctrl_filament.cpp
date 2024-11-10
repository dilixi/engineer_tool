#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"
#include "printer_group.h"
#include "utils_lib.h"

#define SW_PRINT_FILAMENT_CTL 0

#if SW_PRINT_FILAMENT_CTL && SW_PRINT_ALL
//#include "esp_log.h"
static const char * TAG = "filament_ctl"; 
#define PRINT_FILAMENT_CTL  printf  
#else
#define PRINT_FILAMENT_CTL(...)
#endif

typedef enum {
    UI_TIPS_TIPS = 0,
    UI_TIPS_LOAD,
    UI_TIPS_UNLOAD,
} ui_tips_t;

static ui_tips_t ui_tips = UI_TIPS_TIPS;

static lv_obj_t * ui_panel_printer = NULL;
static lv_obj_t * ui_btn_unload = NULL;
static lv_obj_t * ui_btn_load = NULL;
static lv_obj_t * ui_panel_tips = NULL;

static lv_obj_t * ui_panel_drying = NULL; 

static lv_obj_t * label_tips_index[4] = {NULL, NULL, NULL, NULL};
static lv_obj_t * label_tips_step[4] = {NULL, NULL, NULL, NULL};

static lv_obj_t * ui_img_printer = NULL;
bambu_mqtt_t * bambu_mqtt_master_filament = NULL;

#define BAMBU_DATA_MASTER_FILAMENT (bambu_mqtt_master_filament->bambu_data)


typedef enum {
    MLG_KEY_IDX_BTN_LOAD = 0,
    MLG_KEY_IDX_BTN_UNLOAD,
    MLG_KEY_IDX_BTN_RETRY,
    MLG_KEY_IDX_BTN_DRY,
    MLG_KEY_IDX_BTN_DRY_PREPARE,
    MLG_KEY_IDX_BTN_DRY_START,
    MLG_KEY_IDX_BTN_DRY_EXIT,
    MLG_KEY_IDX_T_TIP,
    MLG_KEY_IDX_TIP,
    MLG_KEY_IDX_TO_LOAD,
    MLG_KEY_IDX_TO_UNLOAD,
    MLG_KEY_IDX_H_NOZZLE_TEMP,
    MLG_KEY_IDX_P_N_FILAMENT,
    MLG_KEY_IDX_G_N_FILAMENT,
    MLG_KEY_IDX_P_O_FILAMENT,
    MLG_KEY_IDX_CUT_FILAMENT,
    MLG_KEY_IDX_P_B_FILAMENT, 
    MLG_KEY_IDX_PRINT_AMS,
    MLG_KEY_IDX_MAX,
} MLG_KEY_IDX_T;

typedef struct {
    uint32_t bg_c;
    lv_obj_t * panel;
    lv_obj_t * panel_index;
    lv_obj_t * label_text;

    lv_obj_t * btn_status;
    lv_obj_t *line_v;
    lv_obj_t *line_h; 
    lv_obj_t *line_arc;
    uint64_t tag_uid;
} ui_tray_data_t;

typedef struct {
    uint32_t bg_c;
    lv_obj_t * panel;
} ui_ams_tray_data_t;

typedef struct {
    lv_obj_t * panel; 
    uint8_t humidity_idx;
    ui_ams_tray_data_t data[TRAY_PER_AMS];
} ui_ams_data_t;

typedef struct {
    // ams_tray_id_t tray_id;
    uint8_t ams_id;
    uint32_t tray_now;
    // ams_tray_id_t ui_tray_id;

    // uint8_t ui_ams_id;
    // int32_t ui_tray_now;

    lv_obj_t * panel_spool_holder;
    ui_tray_data_t spool_holder;
    int32_t vt_tray_id;

    lv_obj_t *panel_main;
    lv_obj_t *panel_connection;
    lv_obj_t *img_humidity;
    lv_obj_t *line_bg_h;
    lv_obj_t *connection_line;
    lv_obj_t *nozzle_circle;
    lv_obj_t * img_printer;
    ui_tray_data_t ams_tray[TRAY_PER_AMS];
    int32_t tray_exist_bits;

    lv_obj_t * panel_ams_id;
    ui_ams_data_t ams[AMS_MAX_NUMBER];
} ui_filament_data_t;

static ui_filament_data_t ui_filament_data;
static ui_filament_data_t * ui_d = &ui_filament_data;
static const uint8_t set_id_spool_holder = 254; 

void ui_panel_tray_reset(ui_tray_data_t * ui_tray_d); 

static void event_handler_update_nozzle(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e); 
    
    if (code == LV_EVENT_REFRESH)
    {
        MLG_KEY_TYPE get_key = (MLG_KEY_TYPE)(pointer_type)lv_event_get_user_data(e);

        if (rs_lang_key_is_valid(get_key))
        {   
            char set_range_of_temp[64];

            lv_obj_t * label = lv_event_get_target(e);

            snprintf(set_range_of_temp, sizeof(set_range_of_temp), "%s (%ld℃ -> %ld℃)", RS_TRANSLATE(get_key), BAMBU_DATA_MASTER_FILAMENT.nozzle_temper, BAMBU_DATA_MASTER_FILAMENT.nozzle_target_temper);
 
            lv_label_set_text(label, set_range_of_temp); 
        }
    }
}

static MLG_TRANSLATE_DATA_T multi_lang_keys[] = 
{
    {K_BTN_LOAD,},
    {K_BTN_UNLOAD,},
    {K_BTN_RETRY,},
    {K_BTN_DRY,},
    {K_BTN_DRY_PREPARE,},
    {K_BTN_DRY_START,}, 
    {K_BTN_BACK,}, 
    {K_CTL_T_FILAMENT_T_TIP,},
    {K_CTL_T_FILAMENT_TIP,},
    {K_CTL_T_TO_LOAD,},
    {K_CTL_T_TO_UNLOAD,},
    {K_CTL_T_HEAT_NOZZLE_TEMP,event_handler_update_nozzle},
    {K_CTL_T_PUSH_NEW_FILAMENT,},
    {K_CTL_T_GRAB_NEW_FILAMENT,},
    {K_CTL_T_PURGE_OLD_FILAMENT,},
    {K_CTL_T_CUT_FILAMENT,},
    {K_CTL_T_BACK_FILAMENT,},
    {K_PRINT_AMS,},
    //{K_CONTENT_EMPTY,}, 
};
   
#define S_MULTI_LANG_KEYS multi_lang_keys

static void add_translate_event(lv_obj_t *p_obj, uint8_t set_idx)
{
    if (set_idx < MLG_KEY_IDX_MAX)
    {
        rs_add_translate_cb(p_obj,S_MULTI_LANG_KEYS[set_idx].translate_cb,(void *)S_MULTI_LANG_KEYS[set_idx].key,KEY_NUMBER);
    }
}

static void ui_panel_add_tips(lv_obj_t * parent) {
    if (parent == NULL) return;
    ui_tips = UI_TIPS_TIPS;
    lv_memset(label_tips_index, 0, sizeof(label_tips_index));
    lv_memset(label_tips_step, 0, sizeof(label_tips_step));
    lv_obj_clean(parent);
    lv_obj_t * label_title = lv_label_create(parent); 
    lv_obj_set_style_text_color(label_title, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_text_font(label_title, LV_FONT_16_VARIABLE, LV_PART_MAIN);

    add_translate_event(label_title,MLG_KEY_IDX_T_TIP);

    lv_obj_t * label_tips = lv_label_create(parent);
    lv_obj_set_size(label_tips, 195, 290);
    lv_obj_align(label_tips, LV_ALIGN_TOP_MID, 0, 30); 
    add_translate_event(label_tips,MLG_KEY_IDX_TIP);
}

static void ui_panel_add_label(lv_obj_t * parent, lv_coord_t y_ofs, uint8_t index, const char * text,uint8_t key_idx) {
    lv_obj_t * panel_index = ui_panel_create_index(parent, index, 18, lv_color_hex(LV_32BIT_BTT_RED));
    lv_obj_align(panel_index, LV_ALIGN_LEFT_MID, 0, y_ofs);
    label_tips_index[index] = ui_obj_get(panel_index, UI_TYPE_INDEX_LABEL);

    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_size(label, 175, LV_SIZE_CONTENT);
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, 0, y_ofs); 
    add_translate_event(label,key_idx);

    label_tips_step[index] = label;
}

static void ui_panel_add_load(lv_obj_t * parent) {
    if (parent == NULL) return;
    ui_tips = UI_TIPS_LOAD;
    lv_memset(label_tips_index, 0, sizeof(label_tips_index));
    lv_memset(label_tips_step, 0, sizeof(label_tips_step));
    lv_obj_clean(parent);
    lv_obj_t * label_title = lv_label_create(parent);
    
    lv_obj_set_style_text_color(label_title, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_text_font(label_title, LV_FONT_16_VARIABLE, LV_PART_MAIN);
    add_translate_event(label_title,MLG_KEY_IDX_TO_LOAD);

    /* must be static not const*/
    static lv_point_t line_points[] = { {0, 0}, {0, 150}};
    lv_obj_t * line = ui_line_create(parent, line_points, 2, 2, lv_color_hex(LV_32BIT_BTT_RED));
    lv_obj_align(line, LV_ALIGN_TOP_LEFT, 8, 40);

    char buf[128];
    snprintf(buf, sizeof(buf), "%s (%ld℃ -> %ld℃)", RS_TRANSLATE(K_CTL_T_HEAT_NOZZLE_TEMP), BAMBU_DATA_MASTER_FILAMENT.nozzle_temper, BAMBU_DATA_MASTER_FILAMENT.nozzle_target_temper);
    ui_panel_add_label(parent, -120, 0, buf,MLG_KEY_IDX_H_NOZZLE_TEMP);/*add in the future*/

    ui_panel_add_label(parent, -70, 1, "Push new filament into the extruder",MLG_KEY_IDX_P_N_FILAMENT);
    ui_panel_add_label(parent, -20, 2, "Grab new filament",MLG_KEY_IDX_G_N_FILAMENT);
    ui_panel_add_label(parent, 30, 3, "Purge old filament",MLG_KEY_IDX_P_O_FILAMENT);
}

static void ui_panel_add_unload(lv_obj_t * parent) {
    if (parent == NULL) return;
    ui_tips = UI_TIPS_UNLOAD;
    lv_memset(label_tips_index, 0, sizeof(label_tips_index));
    lv_memset(label_tips_step, 0, sizeof(label_tips_step));
    lv_obj_clean(parent);
    lv_obj_t * label_title = lv_label_create(parent);
    add_translate_event(label_title,MLG_KEY_IDX_TO_UNLOAD);
     
    lv_obj_set_style_text_color(label_title, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_text_font(label_title, LV_FONT_16_VARIABLE, LV_PART_MAIN);

    /* must be static not const*/
    static lv_point_t line_points[] = { {0, 0}, {0, 100}};
    lv_obj_t * line = ui_line_create(parent, line_points, 2, 2, lv_color_hex(LV_32BIT_BTT_RED));
    lv_obj_align(line, LV_ALIGN_TOP_LEFT, 8, 40);

    char buf[128];
    snprintf(buf, sizeof(buf), "%s (%ld℃ -> %ld℃)", RS_TRANSLATE(K_CTL_T_HEAT_NOZZLE_TEMP), BAMBU_DATA_MASTER_FILAMENT.nozzle_temper, BAMBU_DATA_MASTER_FILAMENT.nozzle_target_temper);
    ui_panel_add_label(parent, -120, 0, buf,MLG_KEY_IDX_MAX);/*add in the future*/
  
    ui_panel_add_label(parent, -70, 1, "Cut filament",MLG_KEY_IDX_CUT_FILAMENT);
    ui_panel_add_label(parent, -20, 2, "Pull back current filament",MLG_KEY_IDX_P_B_FILAMENT);
}



enum {
    UI_AMS_POPUP_BTN_NO,
    UI_AMS_POPUP_BTN_YES,
};

static void ams_change_popup_clicked(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt) {
    switch (btn_id) {
        case UI_AMS_POPUP_BTN_YES: {
            ui_panel_create_tray_edit(lv_obj_get_parent(ui_panel_printer), (tray_t *)cb_data);
            break;
        }
        default:
            break;
    }
}

ui_popup_t popup_filament_unknown = {
    .text = K_FILAMENT_UNKNOWN,
    .btn_num = 2,
    .btn_text = {K_BTN_NO, K_BTN_YES},
    .btn_id = {UI_AMS_POPUP_BTN_NO, UI_AMS_POPUP_BTN_YES},
    .popup_cb = ams_change_popup_clicked,
};

bool ui_ams_change_filament(uint32_t target, bool unload) {
    tray_t * tray = ams_tray_get_tray(target);
    filament_id_t filament_id = idx_data_get_index(tray->tray_info_idx);
    const idx_data_t * p_idx = idx_data_get_array(filament_id);
    if (p_idx->tray_info_idx[0] == '\0') {
        popup_filament_unknown.cb_data = tray;
        ui_panel_create_popup(&popup_filament_unknown, NULL);
        return false;
    } else {
        return mqtt_ams_change_filament(target, unload);
    }
}

static void ui_panel_tips_goto(ui_tips_t type);
static void btn_unload_clicked(lv_event_t * e) {
    if (ui_ams_change_filament(ui_d->tray_now, true)) {
        // ui_panel_tips_goto(UI_TIPS_UNLOAD);
    }
}

static void btn_load_clicked(lv_event_t * e) {
    if (ui_ams_change_filament(ui_d->tray_now, false)) {
        // ui_panel_tips_goto(UI_TIPS_LOAD);
    }
}

static void btn_retry_clicked(lv_event_t * e) {
    mqtt_ams_ctrl("resume");
}

static void btn_prepare_clicked(lv_event_t * e) 
{
    PRINT_FILAMENT_CTL("btn_prepare_clicked\r\n");
    mqtt_gcode_line("G28 Z\n");
    //mqtt_gcode_line("G28 X\n");
    //mqtt_gcode_line("G0 Z10\n"); 
}

static void btn_start_clicked(lv_event_t * e) 
{
    PRINT_FILAMENT_CTL("btn_start_clicked\r\n"); 

}

static void btn_back_clicked(lv_event_t * e) 
{
    PRINT_FILAMENT_CTL("btn_back_clicked\r\n");
    /*删除所有面板，后面再重新创建*/
    if (ui_panel_drying)
    {
        lv_obj_del_async(ui_panel_drying);
        ui_panel_drying=NULL;
    }
}

typedef struct {
    //lv_obj_t * panel;
    lv_obj_t * dropdown_manuf;
    lv_obj_t * dropdown_filament_type; 
    //tray_t * tray;
    uint8_t sel_opt_manuf;
    uint8_t sel_opt_filament_type; 
} ui_tray_info_t;

static ui_tray_info_t ui_tray_info;
static ui_tray_info_t * ui_d_filament_type = &ui_tray_info;
 
static const uint8_t dry_hours[] = {3, 6, 12, 24, 48};
static const uint8_t dry_temps[] = {70, 80, 90}; 
 
static uint8_t dry_temp = 90;
static uint8_t dry_hour = 12;

void ui_dropdown_manuf_set_options(lv_obj_t * dropdown);
void ui_dropdown_filament_type_set_options(lv_obj_t * dropdown, uint8_t manuf_i);
void ui_dropdown_set_style(lv_obj_t * dropdown);

static void dropdown_manuf_changed(lv_event_t * e) 
{
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
    uint16_t sel_opt_manuf = lv_dropdown_get_selected(ui_d->dropdown_manuf);
    if (ui_d->sel_opt_manuf != sel_opt_manuf) {
        ui_d->sel_opt_manuf = sel_opt_manuf;
        ui_dropdown_filament_type_set_options(ui_d->dropdown_filament_type, ui_d->sel_opt_manuf);
        lv_dropdown_t * dropdown = (lv_dropdown_t *)ui_d->dropdown_filament_type;
        //dropdown->sel_opt_id_orig = dropdown->sel_opt_id = 0xffff;
        dropdown->sel_opt_id_orig = dropdown->sel_opt_id = 0;
        lv_event_send(ui_d->dropdown_filament_type, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void update_filament_dry_config(filament_id_t id)
{
    const idx_data_t * get_filament_data = idx_data_get_array(id);

    if (!get_filament_data->nozzle_temp_min)
    {
        return;
    }

    //PRINT_FILAMENT_CTL("filament[%s] dry temp[%d] time[%d]\r\n",get_filament_data->filament_type, (int)get_filament_data->dry_temp, (int)get_filament_data->dry_time);
}

static void dropdown_filament_type_changed(lv_event_t * e) 
{
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);

    uint16_t sel_opt_filament_type = lv_dropdown_get_selected(ui_d->dropdown_filament_type);
    
    if (ui_d->sel_opt_filament_type != sel_opt_filament_type) 
    {
        ui_d->sel_opt_filament_type = sel_opt_filament_type;  
    
        /*根据选择的不同类型保存好烘干温度和时间变量*/ 
        update_filament_dry_config({ui_d->sel_opt_manuf, ui_d->sel_opt_filament_type});
    }
}

static void btn_bed_temp_clicked(lv_event_t * e) 
{
    /*设置烘干温度变量*/
    /*弹出选项*/
} 

static void btn_drying_filament_clicked(lv_event_t * e) {
    PRINT_FILAMENT_CTL("dry filament\r\n");

    /*判断如果不是X1C或者P1S 弹出提示仅支持P1S和X1C*/ 

    /*在整个面板基础上再创建一个用于烘干逻辑的面板*/
    lv_obj_t * panel = lv_obj_get_parent(ui_panel_printer);

    ui_panel_drying = ui_panel_create(panel, 8, lv_color_hex(0x575757));
    lv_obj_set_size(ui_panel_drying, 690, 400);
    lv_obj_align(ui_panel_drying, LV_ALIGN_LEFT_MID, 0, 0);
 
    /*左边是示意图*/
    lv_obj_t *panel_img = ui_panel_create(ui_panel_drying, 8, lv_color_hex(0x444444));
    lv_obj_set_size(panel_img, 200, 220);
    lv_obj_align(panel_img, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_t *img_place_filament = lv_img_create(panel_img); 
    lv_img_set_src(img_place_filament,&ui_img_x1c_drying_png); 
    lv_obj_align(img_place_filament,LV_ALIGN_CENTER, 0, 0);  
 
     lv_obj_t * btn_back= ui_btn_label_create(ui_panel_drying, 200, 50, 8, lv_color_hex(0x0AE42), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_DRY_EXIT].key));
    lv_obj_align(btn_back, LV_ALIGN_BOTTOM_LEFT, 0, -120);
    lv_obj_add_event_cb(btn_back, btn_back_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * btn_prepare= ui_btn_label_create(ui_panel_drying, 200, 50, 8, lv_color_hex(0x0AE42), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_DRY_PREPARE].key));
    lv_obj_align(btn_prepare, LV_ALIGN_BOTTOM_LEFT, 0, -60);
    lv_obj_add_event_cb(btn_prepare, btn_prepare_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * btn_start= ui_btn_label_create(ui_panel_drying, 200, 50, 8, lv_color_hex(0x0AE42), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_DRY_START].key));
    lv_obj_align(btn_start, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_obj_add_event_cb(btn_start, btn_start_clicked, LV_EVENT_CLICKED, NULL);
 
    /*需要创建耗材选择下拉框，与X1C拍照的相同*/
     
    lv_obj_t *panel_right = ui_panel_create(ui_panel_drying, 8, lv_color_hex(0x444444));
    lv_obj_set_size(panel_right, 480, 400);
    lv_obj_align(panel_right, LV_ALIGN_RIGHT_MID, 0, 0);
 
    filament_id_t filament_id = idx_data_get_index(BAMBU_DATA_MASTER_FILAMENT.vt_tray.tray_info_idx);
   
    lv_obj_t * dropdown_manuf = lv_dropdown_create(panel_right);
    ui_dropdown_manuf_set_options(dropdown_manuf);
    lv_obj_align(dropdown_manuf, LV_ALIGN_TOP_LEFT, 75, 10);
    lv_obj_set_width(dropdown_manuf, 130);
    ui_dropdown_set_style(dropdown_manuf);
    lv_dropdown_t * dropdown = (lv_dropdown_t *)dropdown_manuf;
    dropdown->sel_opt_id_orig = dropdown->sel_opt_id = filament_id.manuf_id;

    lv_obj_t * dropdown_filament_type = lv_dropdown_create(panel_right);
    ui_dropdown_filament_type_set_options(dropdown_filament_type, filament_id.manuf_id);
    lv_obj_align(dropdown_filament_type, LV_ALIGN_TOP_LEFT, 75+140, 10);
    lv_obj_set_width(dropdown_filament_type, 220);
    dropdown = (lv_dropdown_t *)dropdown_filament_type;
    ui_dropdown_set_style(dropdown_filament_type);
    dropdown->sel_opt_id_orig = dropdown->sel_opt_id = filament_id.type_id;
  
    lv_obj_add_event_cb(dropdown_manuf, dropdown_manuf_changed, LV_EVENT_VALUE_CHANGED, ui_d_filament_type);
    lv_obj_add_event_cb(dropdown_filament_type, dropdown_filament_type_changed, LV_EVENT_VALUE_CHANGED, ui_d_filament_type);
 
    ui_d_filament_type->dropdown_manuf = dropdown_manuf;
    ui_d_filament_type->dropdown_filament_type = dropdown_filament_type;  
    ui_d_filament_type->sel_opt_manuf = filament_id.manuf_id;
    ui_d_filament_type->sel_opt_filament_type = filament_id.type_id; 
 
    update_filament_dry_config(filament_id); 
 
    lv_obj_t *bed_temp_panel = ui_panel_create(panel_right, 8, lv_color_hex(0x444444));
    lv_obj_set_size(bed_temp_panel, 180, 40);
    lv_obj_align(bed_temp_panel, LV_ALIGN_LEFT_MID, 75, -120); 
    lv_obj_set_style_bg_opa(bed_temp_panel,LV_OPA_COVER,0);

    lv_obj_t *ui_img_bed = lv_img_create(bed_temp_panel);
    lv_img_set_src(ui_img_bed,&ui_img_hotbed_png); 
    lv_obj_align(ui_img_bed, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_t *label_ctrl_bed_temper = lv_label_create(bed_temp_panel);
    lv_label_set_text(label_ctrl_bed_temper, "100");
    lv_obj_set_style_text_font(label_ctrl_bed_temper, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_obj_align(label_ctrl_bed_temper, LV_ALIGN_LEFT_MID, 40, 0);
    lv_obj_t *label = lv_label_create(bed_temp_panel);
    lv_label_set_text(label, "/"); 
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 96, 0);

    lv_obj_t *label_ctrl_bed_target_temper = lv_label_create(bed_temp_panel);
    lv_label_set_text(label_ctrl_bed_target_temper, "190");
    lv_obj_align(label_ctrl_bed_target_temper, LV_ALIGN_LEFT_MID, 110, 0);
    
    lv_obj_set_style_pad_bottom(label_ctrl_bed_target_temper,2, 0);
    lv_obj_set_style_border_width(label_ctrl_bed_target_temper,2, 0);
    lv_obj_set_style_border_color(label_ctrl_bed_target_temper,lv_color_white(), 0);
    lv_obj_set_style_border_side(label_ctrl_bed_target_temper,LV_BORDER_SIDE_BOTTOM, 0);

    label = lv_label_create(bed_temp_panel);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 110+40, 0);
    
    lv_obj_add_event_cb(bed_temp_panel, btn_bed_temp_clicked, LV_EVENT_CLICKED, NULL); 

    /*创建倒计时图标和时间*/ 
    lv_obj_t *countdown_panel = ui_panel_create(panel_right, 8, lv_color_hex(0x444444));
    lv_obj_set_size(countdown_panel, 100, 40);
    lv_obj_align(countdown_panel, LV_ALIGN_RIGHT_MID, -20, -120); 
    lv_obj_set_style_bg_opa(countdown_panel,LV_OPA_COVER,0);
    
    lv_obj_t *ui_img_countdown = lv_img_create(countdown_panel);
    lv_img_set_src(ui_img_countdown,&ui_img_countdown_png); 
    lv_obj_align(ui_img_countdown, LV_ALIGN_LEFT_MID, 0, 0); 

    /*时间*/
    lv_obj_t *label_ctrl_target_countdown = lv_label_create(countdown_panel);
    lv_label_set_text(label_ctrl_target_countdown, "12");
    lv_obj_align(label_ctrl_target_countdown, LV_ALIGN_LEFT_MID, 40, 0);
    
    lv_obj_set_style_pad_bottom(label_ctrl_target_countdown,2, 0);
    lv_obj_set_style_border_width(label_ctrl_target_countdown,2, 0);
    lv_obj_set_style_border_color(label_ctrl_target_countdown,lv_color_white(), 0);
    lv_obj_set_style_border_side(label_ctrl_target_countdown,LV_BORDER_SIDE_BOTTOM, 0);
    
    /*单位*/
    label = lv_label_create(countdown_panel);
    lv_label_set_text(label, "h");
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 40+40, 0);
    
    static const lv_point_t h_line_points[] = { {0, 0}, {470, 0}};
    lv_obj_t *split_line = ui_line_create(panel_right, h_line_points, 2, 2, lv_color_hex(0x767676));

    lv_obj_align(split_line, LV_ALIGN_TOP_MID, 0, 100);

    /*创建说明步骤*/
    /*创建面板*/ 
    lv_obj_t *step_panel = ui_panel_create(panel_right, 8, lv_color_hex(0x444444));
    lv_obj_set_size(step_panel, 480, 290);
    lv_obj_align(step_panel, LV_ALIGN_BOTTOM_MID, 0, 0); 
    lv_obj_set_style_bg_opa(step_panel,LV_OPA_COVER,0);

    label = lv_label_create(step_panel);
    lv_label_set_text_static(label, RS_TRANSLATE(K_T_DRY_FILAMENT_STEPS));
    lv_obj_align(label, LV_ALIGN_TOP_MID, 4, 0); 
    //lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_width(label,460); 
    // lv_label_set_long_mode(label,LV_LABEL_LONG_WRAP);
}

// https://en.wikipedia.org/wiki/YCbCr#ITU-R_BT.601_conversion
uint8_t RGB_to_YCbCr(uint32_t color) {
    uint8_t r = (color >> 16) & 0xff;
    uint8_t g = (color >> 8) & 0xff;
    uint8_t b = (color >> 0) & 0xff;
    return 0.299f*r + 0.587f*g + 0.114f*b;
}

void ui_panel_filament_bg_color_set(lv_obj_t * obj, uint32_t c) {
    lv_color_t bg_c = lv_color_hex((c >> 8) & 0xffffff);
    lv_opa_t bg_opa = c & 0xff;
    const lv_color_t p_bc_c = lv_obj_get_style_prop(lv_obj_get_parent(obj), LV_PART_MAIN, LV_STYLE_BG_COLOR).color;
    lv_opa_t border_opa = ((bg_opa == 0) || (bg_c.full == p_bc_c.full)) ? 255 : 0;
    lv_obj_set_style_bg_color(obj, bg_c, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, bg_opa, LV_PART_MAIN);
    lv_obj_set_style_border_opa(obj, border_opa, LV_PART_MAIN);
}

uint32_t ui_panel_tray_color_set(ui_tray_data_t * ui_tray_d) {
    uint32_t bg_c_32 = (ui_tray_d->bg_c >> 8) & 0xffffff;
    uint32_t font_c = RGB_to_YCbCr(bg_c_32) >= 128 ? 0x0 : 0xffffff;
    ui_panel_filament_bg_color_set(ui_tray_d->panel, ui_tray_d->bg_c);
    lv_obj_set_style_text_color(ui_tray_d->label_text, lv_color_hex(font_c), LV_PART_MAIN);
    return font_c;
}

lv_obj_t * ui_panel_create_fliament_sel(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, uint32_t c, uint32_t border_c) {
    lv_color_t bg_c = lv_color_hex((c >> 8) & 0xffffff);
    lv_obj_t * panel = ui_panel_create(parent, radius, bg_c);
    lv_obj_set_size(panel, w, h);
    lv_obj_set_style_border_width(panel, 2, LV_PART_MAIN);
    lv_obj_set_style_border_color(panel, lv_color_hex(border_c), LV_PART_MAIN);
    lv_obj_set_style_outline_color(panel, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_outline_opa(panel, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_pad(panel, 2, LV_PART_MAIN);
    lv_obj_set_style_outline_width(panel, 2, LV_PART_MAIN);
    ui_panel_filament_bg_color_set(panel, c);
    return panel;
}

lv_obj_t * ui_panel_create_ams_id(lv_obj_t * parent, ui_ams_data_t * p_ams) {
    lv_obj_t * panel = ui_panel_create_fliament_sel(parent, 80, 40, 3, 0x838383FF, 0x575757);

    for (uint8_t i = 0; i < TRAY_PER_AMS; i++) {
        lv_obj_t * panel_tray = ui_panel_create_fliament_sel(panel, 15, 15, 3, 0xFFFFFFFF, 0x575757);
        lv_obj_align(panel_tray, LV_ALIGN_LEFT_MID, 3 + 19 * i, 0);
        p_ams->data[i].panel = panel_tray;
        p_ams->data[i].bg_c = 0xffffffff;
    }
    p_ams->panel = panel;
    return panel;
}

lv_obj_t * ui_panel_get_tray_now(void) {
    if (ui_d->tray_now < AMS_MAX_NUMBER * TRAY_PER_AMS) {
        uint8_t tray_bit = ui_d->tray_now & 0x3;
        return ui_d->ams_tray[tray_bit].panel;
    } else {
        return ui_d->spool_holder.panel;
    }
}

void ui_panel_reset_tray_now(void) {
    lv_obj_t * panel_pre = ui_panel_get_tray_now();
    if (panel_pre)
        lv_obj_set_style_outline_opa(panel_pre, 0, LV_PART_MAIN);
    ui_d->tray_now = 0xffffffff;
}

static void tray_now_set(lv_obj_t * panel, uint8_t index)
{
    uint8_t tray_now = index;
    PRINT_FILAMENT_CTL("tray_now_set index=%d\n",(int)index);
    // Empty tray is unclickable
    if (index < TRAY_PER_AMS) {
        tray_now = (ui_d->ams_id << 2) | index;
        if ((ui_d->tray_exist_bits & (1 << tray_now)) == 0)
            return;
    }
    lv_obj_t * panel_pre = ui_panel_get_tray_now();
    //PRINT_FILAMENT_CTL("panel_pre=%x\n",(unsigned int)panel_pre);
    if (panel_pre)
    {
        lv_obj_set_style_outline_opa(panel_pre, 0, LV_PART_MAIN);
    } 
    ui_d->tray_now = tray_now;
    lv_obj_set_style_outline_opa(panel, 255, LV_PART_MAIN);

    char buf[16];
    snprintf(buf, sizeof(buf), "M620 P%ld\n", ui_d->tray_now);
    //mqtt_gcode_line(buf);
    if (bambu_mqtt_master_filament)
    {
        BAMBU_DATA_MASTER_FILAMENT.ams.tray_now = ui_d->tray_now;
    } 
}

static void panel_tray_clicked(lv_event_t * e) {
    if (bambu_mqtt_is_printing(bambu_mqtt_master_filament)) return;
    lv_obj_t * panel = lv_event_get_target(e);
    pointer_type index = (pointer_type)lv_event_get_user_data(e); 
    PRINT_FILAMENT_CTL("panel_tray_clicked index=%d\n",(int)index);

    uint8_t tray_now = index;
    tray_now_set(panel, tray_now);
}

static void event_handler_check_empty(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e); 
    
    if (code == LV_EVENT_REFRESH)
    {
        MLG_KEY_TYPE get_key = (MLG_KEY_TYPE)(pointer_type)lv_event_get_user_data(e);
        
        if (rs_lang_key_is_valid(get_key))
        {    
            lv_obj_t * label = lv_event_get_target(e);

            if (label)
            {
                char *get_text = lv_label_get_text(label);
                /*maybe need check language type and 'empty'*/
                lv_label_set_text(label, RS_TRANSLATE(get_key)); 
            }
        }
    }
}

void ui_panel_tray_reset(ui_tray_data_t * ui_tray_d) {
    ui_tray_d->bg_c = 0xffffffff;
    ui_panel_tray_color_set(ui_tray_d); 
    rs_add_translate_cb(ui_tray_d->label_text,event_handler_check_empty,(void *)K_CONTENT_EMPTY,KEY_NUMBER);
    if (ui_tray_d->btn_status) {
        // label text align
        lv_obj_align(ui_tray_d->label_text, LV_ALIGN_CENTER, 0, 0);
        // delete img btn
        lv_obj_del(ui_tray_d->btn_status);
        ui_tray_d->btn_status = NULL;
    }
}

static void img_status_clicked(lv_event_t * e) {
    lv_obj_t * img = lv_event_get_target(e);
    tray_t * tray = (tray_t *)lv_event_get_user_data(e);
    lv_obj_t * base = lv_obj_get_parent(ui_panel_printer);
    if (tray->tag_uid || bambu_mqtt_is_printing(bambu_mqtt_master_filament))
        ui_panel_create_tray_shown(base, tray);
    else
        ui_panel_create_tray_edit(base, tray);
}

void ui_panel_tray_update(ui_tray_data_t * ui_tray_d, tray_t * tray) {
    const char * text = tray->tray_type[0] ? tray->tray_type : "?";
    const char * text_label = lv_label_get_text(ui_tray_d->label_text);
    if (strcmp(text_label, text)) {
        lv_label_set_text(ui_tray_d->label_text, text);
    }
    if (ui_tray_d->btn_status == NULL) {
        // label text align
        lv_obj_align(ui_tray_d->label_text, LV_ALIGN_CENTER, 0, -15);
        // create img btn
        lv_obj_t * btn = ui_btn_img_create(ui_tray_d->panel, 40, 40, 0, lv_color_hex(LV_32BIT_BTT_RED), UI_TRAY_EDIT_IMG);
        lv_obj_set_style_bg_opa(btn, 0, LV_PART_MAIN);
        lv_obj_set_align(btn, LV_ALIGN_BOTTOM_MID);
        uint32_t font_c = RGB_to_YCbCr((ui_tray_d->bg_c >> 8) & 0xffffff) >= 128 ? 0x0 : 0xffffff;
        lv_obj_set_style_bg_img_recolor(btn, lv_color_hex(font_c), LV_PART_MAIN);
        lv_obj_set_style_bg_img_recolor_opa(btn, 255, LV_PART_MAIN);
        lv_obj_add_event_cb(btn, img_status_clicked, LV_EVENT_CLICKED, tray);
        ui_tray_d->btn_status = btn;
        ui_tray_d->tag_uid = 0;
    } else {
        lv_obj_t * btn = ui_tray_d->btn_status;
        if (lv_obj_get_event_user_data(btn, img_status_clicked) != tray) {
            lv_obj_remove_event_cb(btn, img_status_clicked);
            lv_obj_add_event_cb(btn, img_status_clicked, LV_EVENT_CLICKED, tray);
        }
    }
    if (ui_tray_d->tag_uid != tray->tag_uid) {
        ui_tray_d->tag_uid = tray->tag_uid;
        lv_obj_set_style_bg_img_src(ui_tray_d->btn_status, ui_tray_d->tag_uid ? UI_TRAY_SHOWN_IMG : UI_TRAY_EDIT_IMG, LV_PART_MAIN);
    }

    uint32_t filament_color = (tray->tray_color >> 8) & 0xffffff;

    if (ui_tray_d->bg_c != tray->tray_color) {
        ui_tray_d->bg_c = tray->tray_color;
 
        uint32_t font_c = ui_panel_tray_color_set(ui_tray_d); 

        lv_obj_set_style_bg_img_recolor(ui_tray_d->btn_status, lv_color_hex(font_c), LV_PART_MAIN);

        ui_tray_data_t * ui_tray_d_check = &ui_d->spool_holder;
 
        if (ui_tray_d == ui_tray_d_check)
        {
            if (ui_tray_d->line_v)
            { 
                lv_obj_set_style_line_color(ui_tray_d->line_v, lv_color_hex(filament_color), LV_PART_MAIN);
            }

            if (ui_tray_d->line_h)
            {
                lv_obj_set_style_line_color(ui_tray_d->line_h, lv_color_hex(filament_color), LV_PART_MAIN);
            }

            uint32_t filament_color = (ui_tray_d->bg_c >> 8) & 0xffffff;

            if (ui_d->nozzle_circle)
            {
                //PRINT_FILAMENT_CTL("update circle color=%x\n",(unsigned int)filament_color);

                lv_obj_set_style_bg_color(ui_d->nozzle_circle, lv_color_hex(filament_color), LV_PART_MAIN);
            }
        }
    }
}

void ui_panel_tray_loop(ui_tray_data_t * ui_tray_d, tray_t * tray, bool exist) {
    if (exist) {
        // update ui
        ui_panel_tray_update(ui_tray_d, tray);
    } else {
        // reset ui
        if (ui_tray_d->btn_status) {
            ui_panel_tray_reset(ui_tray_d);
        }
    }
}

const ui_popup_t popup_ams_busy = {
    .text = K_TIP_AMS_BUSY,
    .btn_num = 1,
    .btn_text = {K_BTN_CONFIRM},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_ams_reading = {
    .text = K_TIP_AMS_READING,
    .btn_num = 1,
    .btn_text = {K_BTN_CONFIRM},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_ams_tray_empty = {
    .text = K_TIP_AMS_TRAY_EMPTY,
    .btn_num = 1,
    .btn_text = {K_BTN_CONFIRM},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
     
};

static void panel_index_clicked(lv_event_t * e) {
    lv_obj_t * panel = lv_event_get_target(e);
    pointer_type index = (pointer_type)lv_event_get_user_data(e);
    uint8_t tray_now = (ui_d->ams_id << 2) | index; 

    if (bambu_mqtt_is_printing(bambu_mqtt_master)
        || BAMBU_DATA_MASTER.hw_switch_state
        || ui_tips != UI_TIPS_TIPS) {
        ui_panel_create_popup(&popup_ams_busy, NULL);
    } else if (BAMBU_DATA_MASTER.ams.tray_reading_bits) {
        ui_panel_create_popup(&popup_ams_reading, NULL);
    } else if ((ui_d->tray_exist_bits & (1 << tray_now)) == 0){
        ui_panel_create_popup(&popup_ams_tray_empty, NULL);
    } else {
        char buf[16];
        snprintf(buf, sizeof(buf), "M620 R%d\n", tray_now);
        mqtt_gcode_line(buf);
        BAMBU_DATA_MASTER_FILAMENT.ams.tray_reading_bits |= 1 << tray_now;
    }
}
lv_obj_t * lv_connecting_spin_create(lv_obj_t * parent);

uint8_t ui_ams_id = 0;
lv_obj_t * ui_label_create_text_index(lv_obj_t * parent, uint8_t ams_id, uint8_t tray_id) {
    ui_ams_id = ams_id;
    lv_obj_clean(parent);
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_width(label, 70);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    if (tray_id < TRAY_PER_AMS)
        lv_label_set_text_fmt(label, "%c%d", 'A' + ams_id, tray_id + 1);
    else
    {
        lv_label_set_text(label, RS_TRANSLATE(K_PRINT_AMS));
        rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_PRINT_AMS,KEY_NUMBER);
    }
        
    return label;
}

void ui_panel_create_tray(lv_obj_t * parent, ui_tray_data_t * ui_tray_d, lv_coord_t x_ofs, int32_t index) {
    lv_obj_t * panel = ui_panel_create_fliament_sel(parent, 70, 120, 8, 0x838383, 0x575757);
    lv_obj_align(panel, LV_ALIGN_CENTER, x_ofs, 0);

    lv_obj_t * panel_index = ui_panel_create(parent, 0, lv_color_hex(0x838383));
    lv_obj_set_style_bg_opa(panel_index, 0, LV_PART_MAIN);
    lv_obj_set_size(panel_index, 70, 45);
    lv_obj_align(panel_index, LV_ALIGN_CENTER, x_ofs, -85);
    if (index < TRAY_PER_AMS)
        lv_obj_add_event_cb(panel_index, panel_index_clicked, LV_EVENT_CLICKED, (void *)index);
    lv_obj_t * label_index = ui_label_create_text_index(panel_index, 0, index); 
    lv_obj_t * label_text = lv_label_create(panel);
    lv_obj_set_width(label_text, 60);
    lv_obj_set_align(label_text, LV_ALIGN_CENTER);
    lv_obj_set_style_text_align(label_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

    lv_obj_add_event_cb(panel, panel_tray_clicked, LV_EVENT_CLICKED, (void *)index);

    ui_tray_d->panel = panel;
    ui_tray_d->panel_index = panel_index;
    ui_tray_d->label_text = label_text;
    ui_panel_tray_reset(ui_tray_d);
}


static void panel_ams_id_clicked(lv_event_t * e) {
    lv_obj_t * panel = lv_event_get_target(e);
    pointer_type index = (pointer_type)lv_event_get_user_data(e);

    lv_obj_t * panel_pre = ui_d->ams[ui_d->ams_id].panel;
    lv_obj_set_style_outline_opa(panel_pre, 0, LV_PART_MAIN);
    ui_d->ams_id = index;
    lv_obj_set_style_outline_opa(panel, 255, LV_PART_MAIN);
}

void ui_panel_ams_id_update(uint32_t now_bits, uint32_t target_bits) {
    if (now_bits == target_bits) return;

    bool now_ams_id_exist = false;
    bool first = true;
    uint8_t first_exist_index = 0;
    uint8_t ams_num = 0;
    for (uint8_t i = 0; i < AMS_MAX_NUMBER; i++) {
        bool now = (now_bits >> i) & 0x01;
        bool target = (target_bits >> i) & 0x01;

        if (target) {
            ams_num++;
            if (first) {
                first = false;
                first_exist_index = i;
            }
            if(i == ui_d->ams_id) {
                now_ams_id_exist = true;
            }
        }

        if (now == target) continue;

        if (now) {
            // exist -> not exist, so delete ams_tray
            if (ui_d->ams[i].panel)
            {
                lv_obj_del(ui_d->ams[i].panel);
            }
            ui_d->ams[i].panel = NULL;
        } else {
            // not exist -> exist, so add ams_tray
            lv_obj_t * ams_id = ui_panel_create_ams_id(ui_d->panel_ams_id, &ui_d->ams[i]);
            lv_obj_set_user_data(ams_id, (void *)i);
            lv_obj_add_event_cb(ams_id, panel_ams_id_clicked, LV_EVENT_CLICKED, (void *)i);
            // reorder
            for (uint32_t t_i = 0; t_i < lv_obj_get_child_cnt(ui_d->panel_ams_id); t_i++) {     
                lv_obj_t * ams_id_temp = lv_obj_get_child(ui_d->panel_ams_id, t_i);
                uint8_t index_temp = (uint8_t)(pointer_type)lv_obj_get_user_data(ams_id_temp);
                if (i > index_temp) continue;
                lv_obj_move_to_index(ams_id, t_i);
                break;
            }
        }
    }

    if (ams_num < 2) {
        if(!lv_obj_has_flag_any(ui_d->panel_ams_id, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_add_flag(ui_d->panel_ams_id, LV_OBJ_FLAG_HIDDEN);
        }
    } else {
        if(lv_obj_has_flag_any(ui_d->panel_ams_id, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_clear_flag(ui_d->panel_ams_id, LV_OBJ_FLAG_HIDDEN);
        }
    }
    if (!now_ams_id_exist) {
        // un seleted pre
        if (ui_d->ams[ui_d->ams_id].panel) {
            lv_obj_set_style_outline_opa(ui_d->ams[ui_d->ams_id].panel, 0, LV_PART_MAIN);
        }
        ui_d->ams_id = first_exist_index;
    }
    // seleted now
    if (ui_d->ams[ui_d->ams_id].panel) {
        lv_obj_set_style_outline_opa(ui_d->ams[ui_d->ams_id].panel, 255, LV_PART_MAIN);
    }
}

static lv_obj_t *create_line_arc(lv_obj_t *parent, lv_coord_t w, lv_coord_t h, uint16_t set_rotation)
{
    lv_obj_t *arc = lv_arc_create(parent);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
    lv_obj_remove_style(arc, NULL, LV_PART_INDICATOR);

    lv_obj_set_size(arc, w, h);                 // 设置弧线大小
    lv_obj_set_style_arc_width(arc, 4, 0);        // 设置弧线宽度
    lv_obj_set_style_arc_color(arc, lv_color_hex(0xFFFFFF), 0); // 设置弧线颜色
    lv_arc_set_bg_angles(arc, 0, 90);
    lv_arc_set_rotation(arc, set_rotation);

    return arc;
}

void ui_panel_goto_ams(void) {
    lv_obj_clean(ui_d->panel_main); 
    ui_d->panel_connection=NULL;
    ui_d->img_humidity=NULL;
    ui_d->line_bg_h=NULL;
    if (ui_d->connection_line)
    {
        lv_obj_del_async(ui_d->connection_line); 
        ui_d->connection_line=NULL;
    } 
    
    ui_d->img_printer = NULL;

    ui_panel_reset_tray_now();
    ui_d->ams_id = 0;

    static const lv_point_t v_line_points[] = { {0, 0}, {0, 36}};
    static const lv_point_t h_line_points[] = { {0, 0}, {218, 0}};
    static const lv_point_t v_line_points_connection[] = { {0, 0}, {0, 29}};


    for (uint8_t i = 0; i < TRAY_PER_AMS; i++) {
        ui_panel_create_tray(ui_d->panel_main, &ui_d->ams_tray[i], -123 + 82 * i, i);
        ui_d->ams_tray[i].line_h=NULL;
        ui_d->ams_tray[i].line_v=NULL;
        ui_d->ams_tray[i].line_arc=NULL;
    }

    static const lv_point_t h_line_points_ams[] = 
    {
         {0, 0}, {0, 0},{0, 0}, {55, 0}, {0, 0}, {137, 0}, {0, 0}, {219, 0}, 
    };
 
    for (uint8_t i = 0; i < TRAY_PER_AMS; i++) 
    { 
        lv_obj_t *panel = ui_d->ams_tray[i].panel;

        if (panel)
        { 
            ui_d->ams_tray[i].line_v = ui_line_create(ui_d->panel_main, v_line_points, 2, 2, lv_color_hex(0xFFFFFF));
            lv_obj_align_to(ui_d->ams_tray[i].line_v, panel, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
   
            if (0 == i)
            { 
                lv_color_t bg_c = lv_color_hex(0xACACAC);

                if (!ui_d->panel_connection)
                {
                    ui_d->panel_connection = ui_panel_create(ui_d->panel_main, 4, lv_color_hex(0xd0d0d0));
                    lv_obj_set_size(ui_d->panel_connection, 56, 30);
                    lv_obj_set_style_border_width(ui_d->panel_connection, 0, LV_PART_MAIN);
                    lv_obj_align_to(ui_d->panel_connection, ui_d->ams_tray[i].line_v, LV_ALIGN_OUT_BOTTOM_MID, 0, -15);

                    ui_d->ams_tray[i].line_h=NULL;
                }
                
                if (!ui_d->line_bg_h)
                {
                    ui_d->line_bg_h = ui_line_create(ui_d->panel_main, h_line_points, 2, 2, lv_color_hex(0xFFFFFF));
                    
                    lv_obj_align_to(ui_d->line_bg_h, ui_d->panel_connection, LV_ALIGN_OUT_RIGHT_MID, 0, 0); 
                } 

                ui_d->ams_tray[i].line_arc=NULL;
            }
            else
            { 
                /*画横线，到时候进行隐藏或者显示切换*/
                uint8_t idx = i*2; 
                ui_d->ams_tray[i].line_h = ui_line_create(ui_d->panel_main, &h_line_points_ams[idx], 2, 2, lv_color_hex(0xFFFFFF)); 
                lv_obj_align_to(ui_d->ams_tray[i].line_h, ui_d->panel_connection, LV_ALIGN_OUT_RIGHT_MID, 0, 0); 

                lv_obj_add_flag(ui_d->ams_tray[i].line_h,LV_OBJ_FLAG_HIDDEN);

                #if 0
                lv_obj_t *arc = create_line_arc(ui_d->panel_main, 18, 20, 90); 
                lv_obj_align_to(arc, ui_d->ams_tray[i].line_h, LV_ALIGN_OUT_RIGHT_MID, 0, 0); 
                ui_d->ams_tray[i].line_arc = arc; 
                #endif
            }
            
            if (!ui_d->connection_line)
            {   
                ui_d->connection_line = ui_line_create(ui_panel_printer, v_line_points_connection, 2, 2, lv_color_hex(0xFFFFFF));
                lv_obj_align_to(ui_d->connection_line, ui_d->panel_connection, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            } 
       } 
    }

    /*创建湿度传感器*/  

    ui_d->img_humidity = lv_img_create(ui_d->panel_main); 
    lv_img_set_src(ui_d->img_humidity,&ui_img_humidity_0_png); 
    lv_obj_align(ui_d->img_humidity,LV_ALIGN_BOTTOM_RIGHT, -10, -10);   
}

void ui_panel_goto_icon(void) {
    lv_obj_clean(ui_d->panel_main);
    lv_memset_00(ui_d->ams_tray, sizeof(ui_d->ams_tray));
    lv_obj_clean(ui_d->panel_ams_id);
    lv_memset_00(ui_d->ams, sizeof(ui_d->ams));

    ui_panel_reset_tray_now();
    ui_d->ams_id = 0;
    ui_tray_data_t * ui_tray_d = &ui_d->spool_holder;
    ui_d->img_printer = lv_img_create(ui_d->panel_main);
    lv_obj_set_align(ui_d->img_printer, LV_ALIGN_CENTER);   
    tray_now_set(ui_tray_d->panel, set_id_spool_holder); 
}

lv_obj_t * ui_panel_create_filament(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 8, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 690, 400);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 19);
    lv_obj_set_style_bg_opa(panel, 0, LV_PART_MAIN);
    ui_obj_set_type(panel, UI_TYPE_SCREEN_CTRL_FILAMENT);
    lv_obj_add_flag(panel, LV_OBJ_FLAG_HIDDEN);

    ui_panel_printer = ui_panel_create(panel, 8, lv_color_hex(0x444444));
    lv_obj_set_size(ui_panel_printer, 470, 400);
    lv_obj_align(ui_panel_printer, LV_ALIGN_LEFT_MID, 0, 0);

    ui_d->panel_spool_holder = ui_panel_create(ui_panel_printer, 8, lv_color_hex(0x838383));
    lv_obj_set_size(ui_d->panel_spool_holder, 84, 250);
    lv_obj_align(ui_d->panel_spool_holder, LV_ALIGN_TOP_LEFT, 20, 60);
    ui_panel_create_tray(ui_d->panel_spool_holder, &ui_d->spool_holder, 0, set_id_spool_holder); //BAMBU_DATA_MASTER_FILAMENT.vt_tray_id);

    ui_d->panel_ams_id = ui_panel_create(ui_panel_printer, 0, lv_color_hex(0xffffff));
    lv_obj_set_style_bg_opa(ui_d->panel_ams_id, 0, LV_PART_MAIN);
    lv_obj_set_size(ui_d->panel_ams_id, 358, 48);
    lv_obj_set_style_pad_all(ui_d->panel_ams_id, 4, LV_PART_MAIN);
    lv_obj_align(ui_d->panel_ams_id, LV_ALIGN_TOP_LEFT, 100, 10);
    lv_obj_set_flex_flow(ui_d->panel_ams_id, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(ui_d->panel_ams_id, 10, LV_PART_MAIN);

    ui_d->panel_main = ui_panel_create(ui_panel_printer, 8, lv_color_hex(0xa3a3a3));
    lv_obj_set_size(ui_d->panel_main, 336, 250);
    lv_obj_align(ui_d->panel_main, LV_ALIGN_TOP_LEFT, 114, 60);

    lv_obj_t *img_filament_nozzle = lv_img_create(ui_panel_printer);
    
    lv_img_set_src(img_filament_nozzle,&ui_img_extruder_png); 
    lv_obj_align(img_filament_nozzle,LV_ALIGN_BOTTOM_LEFT, 144, -30); 

    /*在这里覆盖一个圆圈表示耗材颜色*/
    ui_d->nozzle_circle = ui_panel_create(ui_panel_printer, LV_RADIUS_CIRCLE, lv_color_hex(0xFFFFFF));
    lv_obj_set_size(ui_d->nozzle_circle, 22, 22);
    lv_obj_align_to(ui_d->nozzle_circle, img_filament_nozzle, LV_ALIGN_CENTER, 0, 1);

    ui_panel_goto_icon();

    ui_btn_unload = ui_btn_label_create(ui_panel_printer, 100, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_UNLOAD].key));
    lv_obj_align(ui_btn_unload, LV_ALIGN_BOTTOM_RIGHT, -20, -20);
    lv_obj_add_event_cb(ui_btn_unload, btn_unload_clicked, LV_EVENT_CLICKED, NULL);

    add_translate_event(ui_btn_unload,MLG_KEY_IDX_BTN_UNLOAD);

    ui_btn_load = ui_btn_label_create(ui_panel_printer, 100, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_LOAD].key));
    lv_obj_align(ui_btn_load, LV_ALIGN_BOTTOM_RIGHT, -140, -20);
    lv_obj_add_event_cb(ui_btn_load, btn_load_clicked, LV_EVENT_CLICKED, NULL);

    add_translate_event(ui_btn_load,MLG_KEY_IDX_BTN_LOAD);

    ui_panel_tips = ui_panel_create(panel, 8, lv_color_hex(0x838383));
    lv_obj_set_size(ui_panel_tips, 215, 340);
    lv_obj_align(ui_panel_tips, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_pad_all(ui_panel_tips, 5, LV_PART_MAIN);

    ui_panel_add_tips(ui_panel_tips);

    lv_obj_t * btn_dry = ui_btn_label_create(panel, 100, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_DRY].key));
    lv_obj_align(btn_dry, LV_ALIGN_BOTTOM_RIGHT, -116, 0);
    lv_obj_add_event_cb(btn_dry, btn_drying_filament_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * btn_retry = ui_btn_label_create(panel, 100, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(S_MULTI_LANG_KEYS[MLG_KEY_IDX_BTN_RETRY].key));
    lv_obj_align(btn_retry, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_add_event_cb(btn_retry, btn_retry_clicked, LV_EVENT_CLICKED, NULL);

    add_translate_event(btn_retry,MLG_KEY_IDX_BTN_RETRY);

    ui_d->panel_connection=NULL; 
    ui_d->img_humidity=NULL;

    return panel;
}

static void ui_panel_tips_goto(ui_tips_t type) {
    if (type == ui_tips) return;
    switch (type) {
        case UI_TIPS_TIPS:
            ui_panel_add_tips(ui_panel_tips);
            break;
        case UI_TIPS_UNLOAD:
            ui_panel_add_unload(ui_panel_tips);
            break;
        case UI_TIPS_LOAD:
            ui_panel_add_load(ui_panel_tips);
            break;
        default:
            break;
    }
}

static void ui_panel_tips_change(int32_t status_code) {
    switch (status_code) {
        case 0:
        case 768:
            ui_panel_tips_goto(UI_TIPS_TIPS);
            break;
        case 258:
            if (BAMBU_DATA_MASTER_FILAMENT.stg_cur == 22) {
                ui_panel_tips_goto(UI_TIPS_UNLOAD);
            } else if (BAMBU_DATA_MASTER_FILAMENT.stg_cur == 24) {
                ui_panel_tips_goto(UI_TIPS_LOAD);
            }
            break;
        case 259:
        case 260:
            ui_panel_tips_goto(UI_TIPS_UNLOAD);
            break;
        case 261:
        case 262:
        case 263:
            ui_panel_tips_goto(UI_TIPS_LOAD);
            break;
        default:
            break;
    }
}

static void ui_tips_step_set(uint8_t sel) {
    for (uint8_t i = 0; i < ARRAY_SIZE(label_tips_index); i++) {
        lv_obj_t * index = label_tips_index[i];
        lv_obj_t * step = label_tips_step[i];

        if (index) {
            if (i < sel){
                lv_label_set_text(index, LV_SYMBOL_OK);
            } else {
                lv_label_set_text_fmt(index, "%d", i + 1);
            }
        }

        if (step) {
            lv_obj_set_style_text_color(step, lv_color_hex((i == sel) ? LV_32BIT_BTT_RED : 0xFFFFFF), LV_PART_MAIN);
        }
    }
}

const ui_popup_t popup_unload_has_filament = {
    .text = K_TIP_UNLOAD_HAS_FILAMENT,
    .btn_num = 1,
    .btn_text = {K_BTN_CLOSE},
    .btn_id = {UI_POPUP_BTN_CLOSE},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_unload_has_filament_long = {
    .text = K_TIP_UNLOAD_HAS_FILAMENT_L,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_load_no_filament = {
    .text = K_TIP_LOAD_NO_FILAMENT,
    .btn_num = 1,
    .btn_text = {K_BTN_CLOSE},
    .btn_id = {UI_POPUP_BTN_CLOSE},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_load_no_filament_long = {
    .text = K_TIP_LOAD_NO_FILAMENT_L,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_load = {
    .text = K_TIP_LOAD_FILAMENT,
    .btn_num = 3,
    .btn_text = {K_BTN_RETRY, K_BTN_DONE, K_BTN_CLOSE},
    .btn_id = {UI_POPUP_BTN_RETRY, UI_POPUP_BTN_DONE, UI_POPUP_BTN_CLOSE,},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_heatbreak_fan = {
    .text = K_TIP_HEATBREAK_FAN,
    .btn_num = 3,
    .btn_text = {K_BTN_CLOSE, K_BTN_STOP, K_BTN_RESUME},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_STOP, UI_POPUP_BTN_RETRY,},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_parsing_gcode = {
    .text = K_TIP_PARSING_GCODE,
    .btn_num = 1,
    .btn_text = {K_BTN_CONFIRM},
    .btn_id = {UI_POPUP_BTN_CLOSE,},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_nozzle_temperature_malfunction = {
    .text = K_TIP_NOZZLE_TEMP_MALF,
    .btn_num = 3,
    .btn_text = {K_BTN_CLOSE, K_BTN_STOP, K_BTN_RESUME},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_STOP, UI_POPUP_BTN_RESUME},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_front_cover = {
    .text = K_TIP_FRONT_COVER,
    .btn_num = 3,
    .btn_text = {K_BTN_CLOSE, K_BTN_STOP, K_BTN_RESUME},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_STOP, UI_POPUP_BTN_RESUME},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_filament_runout = {
    .text = K_TIP_FILAMENT_RUNOUT,
    .btn_num = 3,
    .btn_text = {K_BTN_CLOSE, K_BTN_STOP, K_BTN_FILAMENT},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_STOP, UI_POPUP_BTN_GOTO_FILAMENT},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_ams_runout = {
    .text = K_TIP_AMS_RUNOUT,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_ams_overload = {
    .text = K_TIP_AMS_OVERLOAD,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_failed_feed = {
    .text = K_TIP_AMS_OVERLOAD,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_failed_pull = {
    .text = K_TIP_FAILED_PULL,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
     
};

const ui_popup_t popup_failed_extrude = {
    .text = K_TIP_FAILED_EXTRUDE,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
	 
};

const ui_popup_t popup_failed_feed_outside = {
    .text = K_TIP_FAILED_FEED_OUTSIDE,
    .btn_num = 2,
    .btn_text = {K_BTN_CLOSE, K_BTN_RETRY},
    .btn_id = {UI_POPUP_BTN_CLOSE, UI_POPUP_BTN_RETRY},
    .popup_cb = NULL, // default popop call back funtion
	 
};

typedef void (* btn_state_cb_t)(lv_obj_t * obj, lv_state_t state);
  
void loop_filament_selected(uint8_t tray_now, ui_tray_data_t * ui_tray_d_spool_holder, ui_tray_data_t *ui_tray_d_ams, bool ams_exist)
{ 
    uint8_t selected_type = (AMS_MAX_NUMBER * TRAY_PER_AMS <= tray_now)?FLS_SPOOL_HOLDER:FLS_AMS; 
  
    PRINT_FILAMENT_CTL("filament_type=%02x,tray_now=%02x\r\n",selected_type,tray_now);  

    /*在这里刷新耗材选择的显示*/    
    #define CLEAR_COLOR 0xffffff

    if (FLS_SPOOL_HOLDER == selected_type)
    {  
        tray_now_set(ui_tray_d_spool_holder->panel, tray_now); 

        uint32_t font_c =  (ui_tray_d_spool_holder->bg_c >> 8) & CLEAR_COLOR;
        
        PRINT_FILAMENT_CTL("FLS_SPOOL_HOLDER font_c=%x\r\n",(unsigned int)font_c);

        /*清除AMS的选中*/
        if (ams_exist)
        {
            for (uint8_t i=0; i<TRAY_PER_AMS; i++) 
            {  
                ui_tray_data_t * ui_tray_d = &ui_tray_d_ams[i];  
                lv_obj_set_style_line_width(ui_tray_d->line_v, 2, LV_PART_MAIN);
                lv_obj_set_style_line_color(ui_tray_d->line_v, lv_color_hex(CLEAR_COLOR), LV_PART_MAIN);

                if (ui_tray_d->line_h)
                {
                    lv_obj_set_style_line_width(ui_tray_d->line_h, 2, LV_PART_MAIN); 
                    lv_obj_set_style_line_color(ui_tray_d->line_h, lv_color_hex(CLEAR_COLOR), LV_PART_MAIN); 
                } 

                if (ui_tray_d->line_arc)
                { 
                    lv_obj_add_flag(ui_tray_d->line_arc,LV_OBJ_FLAG_HIDDEN); 
                }
            }
        }
        else
        {
            /*如果不存在AMS删除线段*/
            if (ui_d->connection_line)
            {
                lv_obj_del_async(ui_d->connection_line); 
                ui_d->connection_line=NULL;
            }
        }

        /*如果是外挂料卷就加粗和设置对应颜色*/  
        if (ui_tray_d_spool_holder->line_v)
        { 
            lv_obj_set_style_line_color(ui_tray_d_spool_holder->line_v, lv_color_hex(font_c), LV_PART_MAIN);
        } 

        if (ui_tray_d_spool_holder->line_h)
        { 
            lv_obj_set_style_line_color(ui_tray_d_spool_holder->line_h, lv_color_hex(font_c), LV_PART_MAIN);
        }

        if (ui_tray_d_spool_holder->line_arc)
        { 
            lv_obj_set_style_arc_color(ui_tray_d_spool_holder->line_arc, lv_color_hex(font_c), LV_PART_MAIN);
        }

        if (ui_d->connection_line)
        {
            lv_obj_set_style_line_width(ui_d->connection_line, 2, LV_PART_MAIN); 
            lv_obj_set_style_line_color(ui_d->connection_line, lv_color_hex(CLEAR_COLOR), LV_PART_MAIN); 
        } 

        if (ui_d->nozzle_circle)
        {
            lv_obj_set_style_bg_color(ui_d->nozzle_circle, lv_color_hex(font_c), LV_PART_MAIN);
        } 
    }
    else
    {
        if (ui_tray_d_spool_holder->line_v)
        { 
            lv_obj_set_style_line_color(ui_tray_d_spool_holder->line_v, lv_color_hex(CLEAR_COLOR), LV_PART_MAIN); 
        }

        if (ui_tray_d_spool_holder->line_h)
        { 
            lv_obj_set_style_line_color(ui_tray_d_spool_holder->line_h, lv_color_hex(CLEAR_COLOR), LV_PART_MAIN); 
        }

        if (ui_tray_d_spool_holder->line_arc)
        {
            lv_obj_set_style_arc_color(ui_tray_d_spool_holder->line_arc, lv_color_hex(CLEAR_COLOR), LV_PART_MAIN); 
        }

        PRINT_FILAMENT_CTL("ams_exist=%02x\r\n",ams_exist);

        if (ams_exist)
        { 
            for (uint8_t i=0; i<TRAY_PER_AMS; i++) 
            {  
                ui_tray_data_t * ui_tray_d = &ui_tray_d_ams[i]; 
                bool selected = false;
                if (tray_now < AMS_MAX_NUMBER * TRAY_PER_AMS
                    && (((tray_now >> 2) & 0x3) == ui_d->ams_id)
                    && ((tray_now & 0x3) == i)) {
                    selected = true;
                }  

                uint32_t font_c = (ui_tray_d->bg_c >> 8) & CLEAR_COLOR;

                uint32_t config_color = selected?font_c:CLEAR_COLOR; 
                
                if (ui_tray_d->line_v)
                {
                    lv_obj_set_style_line_width(ui_tray_d->line_v, selected?4:2, LV_PART_MAIN);
                    lv_obj_set_style_line_color(ui_tray_d->line_v, lv_color_hex(config_color), LV_PART_MAIN);
                }
                 
                if (ui_tray_d->line_h)
                {
                    lv_obj_set_style_line_width(ui_tray_d->line_h, selected?4:2, LV_PART_MAIN); 
                    lv_obj_set_style_line_color(ui_tray_d->line_h, lv_color_hex(config_color), LV_PART_MAIN); 

                    /*横线隐藏或者显示*/
                    if (selected)
                    {
                        lv_obj_clear_flag(ui_tray_d->line_h,LV_OBJ_FLAG_HIDDEN);
                    }
                    else
                    {
                        lv_obj_add_flag(ui_tray_d->line_h,LV_OBJ_FLAG_HIDDEN);
                    }  
                } 

                if (ui_tray_d->line_arc)
                { 
                    lv_obj_set_style_arc_color(ui_tray_d->line_arc, lv_color_hex(config_color), LV_PART_MAIN); 
                     
                    /*横线隐藏或者显示*/
                    if (selected)
                    { 
                        lv_obj_clear_flag(ui_tray_d->line_arc,LV_OBJ_FLAG_HIDDEN);
                    }
                    else
                    { 
                        lv_obj_add_flag(ui_tray_d->line_arc,LV_OBJ_FLAG_HIDDEN);
                    }  
                } 

                if (ui_tray_d->panel)
                {
                    lv_obj_set_style_outline_opa(ui_tray_d->panel, selected ? 255 : 0, LV_PART_MAIN); 
                } 
 
                if (selected)
                { 
                    PRINT_FILAMENT_CTL("ams selected with[%02x]\r\n",i); 

                    /*AMS中如果选中了则设置为选中的颜色*/
                    if (ui_d->connection_line)
                    {
                        lv_obj_set_style_line_width(ui_d->connection_line, 4, LV_PART_MAIN); 
                        lv_obj_set_style_line_color(ui_d->connection_line, lv_color_hex(font_c), LV_PART_MAIN); 
                    } 

                    if (ui_d->nozzle_circle)
                    {
                        lv_obj_set_style_bg_color(ui_d->nozzle_circle, lv_color_hex(font_c), LV_PART_MAIN);
                    } 
                }
            } 
        }
    }

    //lv_event_send(ui_top_get_label_filament(),LV_EVENT_REFRESH,(void *)selected_type); 
}

static uint8_t humidity_to_idx(float humidity)
{ 
    if ((humidity>0) && (humidity<20))
    {
        return 1;
    }
    else if ((humidity>21) && (humidity<40))
    {
        return 2;
    }
    else if ((humidity>41) && (humidity<60))
    {
        return 3;
    }
    else if ((humidity>61) && (humidity<80))
    {
        return 4;
    }
    else// if ((humidity>81) && (humidity<100))
    {
        return 5;
    }
}

static const lv_img_dsc_t * img_humidity_src[] = {
    &ui_img_humidity_0_png,
    &ui_img_humidity_1_png,
    &ui_img_humidity_2_png,
    &ui_img_humidity_3_png, 
    &ui_img_humidity_4_png
};

static void update_ams_humidity(uint8_t humidity_idx)
{
    /*根据 humidity 更新 湿度图片*/ 
    /*
    湿度值为 '1' ， 则对应为 (5-1+1) 5 (81-100) 4 
    湿度值为 '2' ， 则对应为 (5-2+1) 4 (61-80)  3
    湿度值为 '3' ， 则对应为 (5-3+1) 3 (41-60)  2
    湿度值为 '4' ， 则对应为 (5-4+1) 2 (21-40)  1
    湿度值为 '5' ， 则对应为 (5-5+1) 1 (0-20)  0
    */ 
    uint8_t img_idx = (5 - humidity_idx + 1) -1;
    
    PRINT_FILAMENT_CTL("img_idx=%02x,ui_d->img_humidity=%x\r\n",img_idx,ui_d->img_humidity);

    if (ui_d->img_humidity)
    {
        if (img_idx<5)
        { 
            lv_img_set_src(ui_d->img_humidity,img_humidity_src[img_idx]); 
        } 
    } 
}

static void loop_ams_humidity(uint8_t ams_id)
{
    /*如果AMS的湿度传感器有效 则检查该值是否有效，为0时无效*/
    /*不在线也无效*/  
    /*如果无效时 使用panda sense的值*/ 
    bool ams_humidity_is_valid = (MQTT_CONNECTED == bambu_mqtt_master_filament->status);
    bool humidity_data_valid = false;  

    ui_ams_data_t * p_ams = &ui_d->ams[ams_id];
    uint8_t humidity_ams = BAMBU_DATA_MASTER_FILAMENT.ams.humidity_idx[ams_id];

    if (ams_humidity_is_valid)
    {
        if (humidity_ams>0 && humidity_ams<6)
        { 
            if (p_ams->humidity_idx != humidity_ams)
            { 
                p_ams->humidity_idx = humidity_ams;   
                update_ams_humidity(p_ams->humidity_idx);
            }

            humidity_data_valid=true;
        } 
    }
    else
    {
        if (g_aht20_data.is_valid)
        {
            /*湿度转成适度序号*/
            p_ams->humidity_idx = humidity_to_idx(g_aht20_data.humidity);

            humidity_data_valid=true;
        } 
    } 

    if (humidity_data_valid)
    {  
        if (lv_obj_has_flag(ui_d->img_humidity,LV_OBJ_FLAG_HIDDEN))
        { 
            lv_obj_clear_flag(ui_d->img_humidity,LV_OBJ_FLAG_HIDDEN); 
        } 
    }
    else
    {
        /*隐藏不显示*/ 
        if (!lv_obj_has_flag(ui_d->img_humidity,LV_OBJ_FLAG_HIDDEN))
        {  
            lv_obj_add_flag(ui_d->img_humidity,LV_OBJ_FLAG_HIDDEN);
        }
    }
}

static bool need_update_filament_selection=false;

void lv_loop_filament(void) {
    static uint16_t s_tray_now = 0x100; 
    static uint32_t ams_exist_bits = 0;

    if (bambu_mqtt_master_filament != bambu_mqtt_master)
    {
        bambu_mqtt_master_filament = bambu_mqtt_master;
        s_tray_now = 0x100;
        ui_panel_reset_tray_now(); 
        need_update_filament_selection=true; 
        //ams_exist_bits = 0;
    }
 
    btn_state_cb_t btn_state_load = lv_obj_clear_state;
    btn_state_cb_t btn_state_unload = lv_obj_clear_state;
    if (bambu_mqtt_is_printing(bambu_mqtt_master_filament) || ui_tips != UI_TIPS_TIPS || ui_d->tray_now == 0xffffffff) {
        btn_state_load = btn_state_unload = lv_obj_add_state;
    } else {
        if (BAMBU_DATA_MASTER_FILAMENT.hw_switch_state) {
            if (ui_d->tray_now == BAMBU_DATA_MASTER_FILAMENT.ams.tray_now) {
                if (ui_d->tray_now != BAMBU_DATA_MASTER_FILAMENT.vt_tray_id) {
                    btn_state_load = lv_obj_add_state;
                }
            }
        } else {
            btn_state_unload = lv_obj_add_state;
        }
    }
    btn_state_load(ui_btn_load, LV_STATE_DISABLED);
    btn_state_unload(ui_btn_unload, LV_STATE_DISABLED);

    
    if (ams_exist_bits != BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits) 
    {
        if (BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits == 0) 
        {
            ui_panel_goto_icon();
        } 
        else 
        {
            if (ams_exist_bits == 0) 
            {
                ui_panel_goto_ams();
            }
            ui_panel_ams_id_update(ams_exist_bits, BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits);
        } 

        ams_exist_bits = BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits;

        need_update_filament_selection=true;

        //PRINT_FILAMENT_CTL("ams_exist_bits=%x",(unsigned int)ams_exist_bits);
    }

    // if (ui_d->vt_tray_id != BAMBU_DATA_MASTER_FILAMENT.vt_tray_id) {
        ui_d->vt_tray_id = BAMBU_DATA_MASTER_FILAMENT.vt_tray_id;
    //     ui_tray_data_t * ui_tray_d = &ui_d->spool_holder;
    //     ui_label_create_text_index(ui_tray_d->panel_index, ui_d->ams_id, ui_d->vt_tray_id);
    //     lv_obj_remove_event_cb(ui_tray_d->panel, panel_tray_clicked);
    //     lv_obj_add_event_cb(ui_tray_d->panel, panel_tray_clicked, LV_EVENT_CLICKED, (void *)ui_d->vt_tray_id);
    // }
    
    static const lv_point_t v_line_points_spool_holder[] = { {0, 0}, {0, 76}};
    static const lv_point_t h_line_points_spool_holder[] = { {0, 0}, {90, 0}};

    ui_tray_data_t * ui_tray_d_spool_holder = &ui_d->spool_holder;
    if (!ui_tray_d_spool_holder->line_v)
    {
        ui_tray_d_spool_holder->line_v = ui_line_create(ui_panel_printer, v_line_points_spool_holder, 2, 4, lv_color_hex(0xFFFFFF));
        lv_obj_align_to(ui_tray_d_spool_holder->line_v, ui_tray_d_spool_holder->panel, LV_ALIGN_OUT_BOTTOM_MID, -2, 0);
    }

    if (!ui_tray_d_spool_holder->line_h)
    {
        ui_tray_d_spool_holder->line_h = ui_line_create(ui_panel_printer, h_line_points_spool_holder, 2, 4, lv_color_hex(0xFFFFFF));
        lv_obj_align_to(ui_tray_d_spool_holder->line_h, ui_tray_d_spool_holder->panel, LV_ALIGN_OUT_BOTTOM_LEFT, 38, 84);
    }

    if (!ui_tray_d_spool_holder->line_arc)
    { 
        lv_obj_t *arc = create_line_arc(ui_panel_printer, 18, 20, 90);

        lv_obj_align_to(arc, ui_tray_d_spool_holder->panel, LV_ALIGN_OUT_BOTTOM_LEFT, 29, 68); 
        
        ui_tray_d_spool_holder->line_arc = arc;
    } 

    ui_panel_tray_loop(&ui_d->spool_holder, &BAMBU_DATA_MASTER_FILAMENT.vt_tray, ui_d->vt_tray_id);

    // have not ams
    if (ui_d->img_printer != NULL) {
        const void * img_src = ui_img_src_get_printer_models(bambu_mqtt_master_filament->nvs_config.model_num,
                                                                BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits);
        if (lv_img_get_src(ui_d->img_printer) != img_src) {
            lv_img_set_src(ui_d->img_printer, img_src);
        }
        
        if (ui_d->connection_line)
        {
            lv_obj_del_async(ui_d->connection_line); 
            ui_d->connection_line=NULL;
        } 
    } else {
    // ams exist
        //PRINT_FILAMENT_CTL("ams exist\r\n");

        ui_d->tray_exist_bits = BAMBU_DATA_MASTER_FILAMENT.ams.tray_exist_bits;
        if (ui_d->tray_now < AMS_MAX_NUMBER * TRAY_PER_AMS) {
            if ((ui_d->tray_exist_bits & (1 << ui_d->tray_now)) == 0) {
                ui_panel_reset_tray_now();
            }
        }
        for (uint8_t i = 0; i < TRAY_PER_AMS; i++) {
            ui_panel_tray_loop(&ui_d->ams_tray[i], &BAMBU_DATA_MASTER_FILAMENT.ams.ams_tray[ui_d->ams_id][i], (ui_d->tray_exist_bits & (1 << (ui_d->ams_id << 2 | i))) != 0);
        }
        static uint32_t tray_reading_bits = 0;
 
        if (ui_ams_id != ui_d->ams_id) {

            PRINT_FILAMENT_CTL("ui_d->ams_id=%02x,ui_ams_id=%02x",ui_d->ams_id,ui_ams_id); 

            for (uint8_t i = 0; i < TRAY_PER_AMS; i++) {
                ui_tray_data_t * ui_tray_d = &ui_d->ams_tray[i];
                ui_label_create_text_index(ui_tray_d->panel_index, ui_d->ams_id, i);
                bool selected = false;
                if (ui_d->tray_now < AMS_MAX_NUMBER * TRAY_PER_AMS
                    && (((ui_d->tray_now >> 2) & 0x3) == ui_d->ams_id)
                    && ((ui_d->tray_now & 0x3) == i)) {
                    selected = true;
                }

                if (selected)
                {
                    PRINT_FILAMENT_CTL("selected with[%02x]",i);
                } 
                tray_reading_bits = 0;
                lv_obj_set_style_outline_opa(ui_tray_d->panel, selected ? 255 : 0, LV_PART_MAIN); 
            }
        }
 
        /*设置按钮背景色*/
        for (uint8_t ams_i = 0; ams_i < AMS_MAX_NUMBER; ams_i++) {
            ui_ams_data_t * p_ams = &ui_d->ams[ams_i];
            if (p_ams->panel == NULL) continue;
            for (uint8_t tray_i = 0; tray_i < TRAY_PER_AMS; tray_i++) {
                ui_ams_tray_data_t * d = &p_ams->data[tray_i];
                tray_t * tray = &BAMBU_DATA_MASTER_FILAMENT.ams.ams_tray[ams_i][tray_i];
                if (d->bg_c != tray->tray_color) {
                    d->bg_c = tray->tray_color;
                    ui_panel_filament_bg_color_set(d->panel, d->bg_c);
                }
            }
        }

        if (tray_reading_bits != BAMBU_DATA_MASTER_FILAMENT.ams.tray_reading_bits) {
            for (uint8_t i = 0; i < TRAY_PER_AMS; i++) {
                uint8_t bit = (ui_d->ams_id << 2) | i;
                bool now = (tray_reading_bits >> bit) & 0x01;
                bool target = (BAMBU_DATA_MASTER_FILAMENT.ams.tray_reading_bits >> bit) & 0x01;
                if (now == target) continue;
                ui_tray_data_t * ui_tray_d = &ui_d->ams_tray[i];
                if (now) {
                    // reading -> done
                    tray_reading_bits &= ~(uint32_t)(1 << bit);
                    ui_label_create_text_index(ui_tray_d->panel_index, ui_d->ams_id, i);
                } else {
                    // done -> reading
                    tray_reading_bits |= 1 << bit;
                    lv_obj_clean(ui_tray_d->panel_index);
                    lv_connecting_spin_create(ui_tray_d->panel_index);
                }
            }
        }

        loop_ams_humidity(ui_d->ams_id);
    }

    
    /*以上更新好了bg_c才调用这里显示选择的耗材*/
    bool is_connected = bambu_mqtt_is_connected(bambu_mqtt_master_filament);
 
    if (is_connected)
    { 
        if ((s_tray_now != BAMBU_DATA_MASTER_FILAMENT.ams.tray_now)
            //|| (ui_d->tray_now != BAMBU_DATA_MASTER_FILAMENT.ams.tray_now)
            || (need_update_filament_selection)
            )
        {
            need_update_filament_selection=false;
            
            PRINT_FILAMENT_CTL("s_tray_now=%x,tray_now=%x,exist[%x]",
                    (unsigned int)s_tray_now,
                    (unsigned int)BAMBU_DATA_MASTER_FILAMENT.ams.tray_now,
                    (unsigned int)BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits);

            s_tray_now = BAMBU_DATA_MASTER_FILAMENT.ams.tray_now;
 
            loop_filament_selected(s_tray_now, ui_tray_d_spool_holder, ui_d->ams_tray, BAMBU_DATA_MASTER_FILAMENT.ams.ams_exist_bits>0); 

            ui_d->tray_now = s_tray_now;
        } 
    }

    static int32_t ams_status = -999;
    if (ams_status != BAMBU_DATA_MASTER_FILAMENT.ams_status) {
        ams_status = BAMBU_DATA_MASTER_FILAMENT.ams_status;
        ui_panel_tips_change(ams_status);
        switch (ams_status) {
            case 258:
                ui_tips_step_set(0);
                break;
            case 259:
                ui_tips_step_set(1);
                break;
            case 260:
                ui_tips_step_set(2);
                break;
            case 261:
                ui_tips_step_set(1);
                break;
            case 262:
                ui_tips_step_set(2);
                break;
            case 263:
                ui_tips_step_set(3);
                break;
            
            default:
                break;
        }
    }

    if (label_tips_step[0]) {
        static int32_t nozzle_temper = -999;
        static int32_t nozzle_target_temper = -999;
        if (nozzle_temper != BAMBU_DATA_MASTER_FILAMENT.nozzle_temper ||
            nozzle_target_temper != BAMBU_DATA_MASTER_FILAMENT.nozzle_target_temper) {
            nozzle_temper = BAMBU_DATA_MASTER_FILAMENT.nozzle_temper;
            nozzle_target_temper = BAMBU_DATA_MASTER_FILAMENT.nozzle_target_temper;
            lv_label_set_text_fmt(label_tips_step[0], "%s (%ld℃ -> %ld℃)", RS_TRANSLATE(K_CTL_T_HEAT_NOZZLE_TEMP), nozzle_temper, nozzle_target_temper);
        }
    }
 
    /*使用旧的方式，应该是根据所有打印机的状态报错*/
   
    mqtt_sync_lock(0);
    uint8_t get_printer_cnt = mqtt_sync_data.printer_cnt;
    mqtt_sync_unlock(); 

    static int32_t print_error[BAMBU_PRINTER_MAX_NUM];
    for (uint8_t i = 0; i < get_printer_cnt; i++) 
    {
        bambu_mqtt_t * mqtt = bambu_get_mqtt(i); 
        
        // if (!mqtt->bambu_data.print_error_updated) continue;
        // mqtt->bambu_data.print_error_updated = false;
        // int32_t print_error = mqtt->bambu_data.print_error;
        
        if (print_error[i] == mqtt->bambu_data.print_error) continue;
        print_error[i] = mqtt->bambu_data.print_error;

        switch (print_error[i]) {
            case 134201347: // filament is still detect after unload
                ui_panel_create_popup(&popup_unload_has_filament, mqtt);
                break;
            case 134184963: // filament is still detect after unload long time
                ui_panel_create_popup(&popup_unload_has_filament_long, mqtt);
                break;
            case 134201350: // filament is not detect after load
                ui_panel_create_popup(&popup_load_no_filament, mqtt);
                break;
            case 134184966: // filament is not detect after load long time
                ui_panel_create_popup(&popup_load_no_filament_long, mqtt);
                break;
            case 134184967:
                ui_panel_create_popup(&popup_load, mqtt);
                break;
            case 50364432:
                ui_panel_create_popup(&popup_heatbreak_fan, mqtt);
                break;
            case 83902467:
                ui_panel_create_popup(&popup_parsing_gcode, mqtt);
                // Reset gcode_state, when PandaTouch start a printing failed
                if (mqtt->bambu_data.gcode_state == GCODE_STATE_PREPARE) {
                    mqtt->bambu_data.gcode_state = GCODE_STATE_IDLE;
                }
                break;
            case 50364424:
                ui_panel_create_popup(&popup_nozzle_temperature_malfunction, mqtt);
                break;
            case 50364421:
                ui_panel_create_popup(&popup_front_cover, mqtt);
                break;
            case 50364420:
                ui_panel_create_popup(&popup_filament_runout, mqtt);
                break;
            case 302022673:
                ui_panel_create_popup(&popup_ams_runout, mqtt);
                break;
            case 117473296:
                ui_panel_create_popup(&popup_ams_overload, mqtt);
                break;
            case 117604358:
            case 117473286:
                ui_panel_create_popup(&popup_failed_feed, mqtt);
                break;
            case 117473283:
                ui_panel_create_popup(&popup_failed_pull, mqtt);
                break;
            case 117473287:
                ui_panel_create_popup(&popup_failed_extrude, mqtt);
                break;
            case 117473285:
                ui_panel_create_popup(&popup_failed_feed_outside, mqtt);
                break;
            case 0:
                ui_panel_del_popup(mqtt);
                break;

            default:
                break;
        }
    }  
}
// 退料：258 - 259 - 260 - 0 ： hw_switch_state: 0， print_error: 134201347
// 进料：258 - 261 - 262 - 263 - 768 ： hw_switch_state: 0， print_error: 134201347
