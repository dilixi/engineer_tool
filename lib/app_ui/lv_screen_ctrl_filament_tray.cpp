#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"

#define SW_PRINT_FILAMENT_TRAY 0

#if SW_PRINT_FILAMENT_TRAY && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "filament_tray"; 
#define PRINT_FILAMENT_TRAY(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_FILAMENT_TRAY(...)
#endif

typedef struct {
    lv_obj_t * panel;
    lv_obj_t * dropdown_manuf;
    lv_obj_t * dropdown_filament_type;
    lv_obj_t * panel_color;
    lv_obj_t * label_temp_max;
    lv_obj_t * label_temp_min;
    tray_t * tray;
    uint8_t sel_opt_manuf;
    uint8_t sel_opt_filament_type;
    uint32_t tray_color;
} ui_tray_info_t;

static ui_tray_info_t ui_tray_info;
static ui_tray_info_t * ui_d = &ui_tray_info;

ams_tray_id_t ams_tray_get_index(tray_t * tray) {
    for (uint8_t ams_i = 0; ams_i < AMS_MAX_NUMBER; ams_i++) {
        for (uint8_t tray_i = 0; tray_i < TRAY_PER_AMS; tray_i++) {
            if (tray != &BAMBU_DATA_MASTER.ams.ams_tray[ams_i][tray_i]) continue;
            return {ams_i, tray_i};
        }
    }
    return {255, BAMBU_DATA_MASTER.vt_tray_id};
}

tray_t * ams_tray_get_tray(uint32_t tray_now) {
    if (tray_now < AMS_MAX_NUMBER * TRAY_PER_AMS) {
        uint8_t ams_i = (tray_now >> 2) & 0x03;
        uint8_t tray_i = (tray_now) & 0x03;
        return &BAMBU_DATA_MASTER.ams.ams_tray[ams_i][tray_i];
    } else {
        return &BAMBU_DATA_MASTER.vt_tray;
    }
}

static void btn_close_clicked(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * panel = lv_obj_get_parent(btn);
    lv_obj_del_async(panel);
}

void ui_label_temp_set_fmt(lv_obj_t * label, const char * id, uint32_t temp) {
    if (temp)
        lv_label_set_text_fmt(label, "%s  %ld℃", id, temp);
    else
        lv_label_set_text_fmt(label, "%s  --℃", id);
}
void ui_label_temp_min_set_fmt(lv_obj_t * label, uint32_t temp) {
    ui_label_temp_set_fmt(label, RS_TRANSLATE(K_FILAMENT_MINIMUM), temp);
}
void ui_label_temp_max_set_fmt(lv_obj_t * label, uint32_t temp) { 
    ui_label_temp_set_fmt(label, RS_TRANSLATE(K_FILAMENT_MAXIMUM), temp);
}

 
/* 
PPS/PPS-CF 90 12  
烘干温度
PA/PA-GF/PA-CF 90 12 
ABS/ASA 90 48  
PAHT-CF 90 12 
PC 90 12  
PET-CF 90 12  
PETG/PETG-CF 80 12 
PLA/PLA-CF 70 12
TPU 90 12
*/

const idx_data_t idx_data_empty =  {"", "", 0, 0};
const idx_data_t idx_data_bambu[] = {
    {"ABS", "GFB00", 240, 280, AMS_SUPPORTED},
    {"ABS-GF", "GFB50", 240, 280, AMS_SUPPORTED},
    {"ASA", "GFB01", 240, 280, AMS_SUPPORTED},
    {"ASA-Aero", "GFB02", 240, 280, AMS_SUPPORTED},
    {"ASA-CF", "GFB51", 250, 280, AMS_SUPPORTED},
    {"PA-CF", "GFN03", 260, 300, AMS_WARNING_CF_GF},
    {"PA6-CF", "GFN05", 260, 300, AMS_SUPPORTED},
    {"PA6-GF", "GFN08", 260, 300, AMS_SUPPORTED},
    {"PAHT-CF", "GFN04", 260, 300, AMS_WARNING_CF_GF},
    {"PC", "GFC00", 260, 290, AMS_SUPPORTED},
    {"PET-CF", "GFT01", 260, 290, AMS_SUPPORTED},
    {"PETG Basic", "GFG00", 240, 270, AMS_SUPPORTED},
    {"PETG-HF", "GFT02", 230, 270, AMS_SUPPORTED},
    {"PETG-Translucent", "GFG01", 230, 270, AMS_SUPPORTED},
    {"PETG-CF", "GFG50", 240, 270, AMS_SUPPORTED},
    {"PLA Aero", "GFA11", 210, 260, AMS_SUPPORTED},
    {"PLA Basic", "GFA00", 190, 240, AMS_SUPPORTED},
    {"PLA Dynamic", "GFA13", 190, 240, AMS_SUPPORTED},
    {"PLA Glow", "GFA12", 190, 240, AMS_SUPPORTED},
    {"PLA Marble", "GFA07", 190, 240, AMS_SUPPORTED},
    {"PLA Matte", "GFA01", 190, 240, AMS_SUPPORTED},
    {"PLA Metal", "GFA02", 190, 240, AMS_SUPPORTED},
    {"PLA Silk", "GFA05", 190, 240, AMS_SUPPORTED},
    {"PLA Sparkle", "GFA08", 190, 240, AMS_SUPPORTED},
    {"PLA Tough", "GFA09", 190, 240, AMS_SUPPORTED},
    {"PLA-CF", "GFA50", 210, 250, AMS_WARNING_CF_GF},
    {"PPA-CF", "GFN06", 280, 320, AMS_SUPPORTED},
    {"PVA", "GFS04", 210, 250, AMS_WARNING_PVA},
    {"Support For PA/PET", "GFS03", 260, 300, AMS_SUPPORTED},
    {"Support For PLA", "GFS02", 190, 240, AMS_SUPPORTED},
    {"Support For PLA/PETG", "GFS05", 190, 240, AMS_SUPPORTED},
    {"Support G", "GFS01", 260, 300, AMS_SUPPORTED},
    {"Support W", "GFS00", 190, 240, AMS_SUPPORTED},
    {"Support for ABS", "GFS06", 240, 270, AMS_SUPPORTED},
    {"TPU 95A", "GFU01", 200, 250, AMS_TNOT_SUPPORTED_TPU},
    {"TPU 95A HF", "GFU00", 200, 250, AMS_TNOT_SUPPORTED_TPU},
};

const idx_data_t idx_data_fiberon[] = {
    {"PA12-CF", "GFL52", 260, 300, AMS_WARNING_CF_GF},
    {"PA6-CF", "GFL50", 280, 300, AMS_SUPPORTED},
    {"PA6-GF", "GFL51", 280, 300, AMS_SUPPORTED},
    {"PA612-CF", "GFL53", 260, 300, AMS_SUPPORTED},
    {"PET-CF", "GFL54", 270, 300, AMS_SUPPORTED},
    {"PETG-ESD", "GFL06", 250, 290, AMS_SUPPORTED},
    {"PETG-rCF", "GFL55", 240, 270, AMS_SUPPORTED},
};

const idx_data_t idx_data_generic[] = {
    {"ABS", "GFB99", 240, 280, AMS_SUPPORTED}, 
    {"ASA", "GFB98", 240, 280, AMS_SUPPORTED},
    {"BVOH", "GFS97", 190, 240, AMS_SUPPORTED},
    {"EVA", "GFR99", 175, 220, AMS_SUPPORTED},
    {"HIPS", "GFS98", 220, 270, AMS_SUPPORTED},
    {"PA", "GFN99", 240, 280, AMS_SUPPORTED},
    {"PA-CF", "GFN98", 260, 300, AMS_WARNING_CF_GF},
    {"PC", "GFC99", 260, 290, AMS_SUPPORTED},
    {"PCTG", "GFG97", 240, 270, AMS_SUPPORTED},
    {"PE", "GFP99", 175, 220, AMS_SUPPORTED},
    {"PE-CF", "GFP98", 175, 220, AMS_SUPPORTED},
    {"PETG", "GFG99", 220, 270, AMS_SUPPORTED},
    {"PETG-CF", "GFG98", 240, 270, AMS_SUPPORTED},
    {"PLA", "GFL99", 190, 240, AMS_SUPPORTED},
    {"PLA High Speed", "GFL95", 190, 240, AMS_SUPPORTED},
    {"PLA Silk", "GFL96", 190, 240, AMS_SUPPORTED},
    {"PLA-CF", "GFL98", 190, 240, AMS_WARNING_CF_GF},
    {"PP", "GFP97", 220, 250, AMS_SUPPORTED},
    {"PP-CF", "GFP96", 220, 250, AMS_SUPPORTED},
    {"PP-GF", "GFP95", 220, 250, AMS_SUPPORTED}, 
    {"PPA-CF", "GFN97", 280, 320, AMS_SUPPORTED},
    {"PPA-GF", "GFN96", 280, 320, AMS_SUPPORTED},
    {"PVA", "GFS99", 190, 240, AMS_WARNING_PVA},
    {"TPU", "GFU99", 200, 250, AMS_TNOT_SUPPORTED_TPU},
    {"TPU for AMS", "GFU98", 200, 250, AMS_SUPPORTED},
};

const idx_data_t idx_data_overture[] = {
    {"Matte PLA", "GFL05", 190, 240, AMS_SUPPORTED},
    {"PLA", "GFL04", 190, 240, AMS_SUPPORTED},
};

const idx_data_t idx_data_polylite[] = {
    {"ABS", "GFB60", 240, 280, AMS_SUPPORTED},
    {"ASA", "GFB61", 240, 280, AMS_SUPPORTED},
    {"PETG", "GFG60", 220, 270, AMS_SUPPORTED},
    {"PLA", "GFL00", 190, 240, AMS_SUPPORTED},
};

const idx_data_t idx_data_polyterra[] = {
    {"PLA", "GFL01", 190, 240, AMS_SUPPORTED},
};

const idx_data_t idx_data_esun[] = {
    {"PLA+", "GFL03", 190, 240, AMS_SUPPORTED},
};

typedef struct {    
    const char * manuf;
    const idx_data_t * p_idx_data;
    const uint8_t p_idx_num;
} manuf_idx_data_t;

const manuf_idx_data_t manuf_idx_data[] = {
    {"Bambu", idx_data_bambu, ARRAY_SIZE(idx_data_bambu)},
    {"Fiberon", idx_data_fiberon, ARRAY_SIZE(idx_data_fiberon)},
    {"Generic", idx_data_generic, ARRAY_SIZE(idx_data_generic)},
    {"Overture", idx_data_overture, ARRAY_SIZE(idx_data_overture)},
    {"PolyLite", idx_data_polylite, ARRAY_SIZE(idx_data_polylite)},
    {"PolyTerra", idx_data_polyterra, ARRAY_SIZE(idx_data_polyterra)},
    {"eSUN", idx_data_esun, ARRAY_SIZE(idx_data_esun)},
};

const char * idx_data_get_manuf(uint8_t manuf_id) {
    return (manuf_id < ARRAY_SIZE(manuf_idx_data))
            ? manuf_idx_data[manuf_id].manuf : RS_TRANSLATE(K_FILAMENT_UNKNOWN_TYPE);
}

filament_id_t idx_data_get_index(const char * tray_info_idx) {
    for (uint8_t manuf_i = 0; manuf_i < ARRAY_SIZE(manuf_idx_data); manuf_i++) {
        const manuf_idx_data_t * d = &manuf_idx_data[manuf_i];
        for (uint8_t type_i = 0; type_i < d->p_idx_num; type_i++) {
            if (strcmp(tray_info_idx, d->p_idx_data[type_i].tray_info_idx) != 0) continue;
            return {manuf_i, type_i};
        }
    }
    return {0xff, 0xff};
}

const idx_data_t * idx_data_get_array(filament_id_t id) {
    if (id.manuf_id < ARRAY_SIZE(manuf_idx_data)) {
        const manuf_idx_data_t * d = &manuf_idx_data[id.manuf_id];
        if (id.type_id < d->p_idx_num) {
            return &d->p_idx_data[id.type_id];
        }
    }
    return &idx_data_empty;
}
 
static void translate_filament_min(lv_event_t * e) 
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_REFRESH)
    {
        ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
 
        const idx_data_t * p_idx = idx_data_get_array({ui_d->sel_opt_manuf, ui_d->sel_opt_filament_type});
        lv_obj_t * obj = lv_event_get_target(e);

        ui_label_temp_min_set_fmt(obj, p_idx->nozzle_temp_min);
    }
}

static void translate_filament_max(lv_event_t * e) 
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_REFRESH)
    {
        ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
 
        const idx_data_t * p_idx = idx_data_get_array({ui_d->sel_opt_manuf, ui_d->sel_opt_filament_type});
        lv_obj_t * obj = lv_event_get_target(e);

        ui_label_temp_max_set_fmt(obj, p_idx->nozzle_temp_max);
    }
}

lv_obj_t * ui_panel_create_tray_shown(lv_obj_t * parent, tray_t * tray) {
    lv_obj_t * panel = ui_panel_create(parent, 5, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 690, 400);
    lv_obj_set_align(panel, LV_ALIGN_CENTER);

    filament_id_t filament_id = idx_data_get_index(tray->tray_info_idx);
    const idx_data_t * p_idx = idx_data_get_array(filament_id);
    lv_obj_t * label_filament = lv_label_create(panel);
    lv_obj_align(label_filament, LV_ALIGN_LEFT_MID, 30, -150);
    lv_obj_set_width(label_filament, 120);
    lv_label_set_text_static(label_filament, RS_TRANSLATE(K_CTL_TOP_T_FILAMENT));
    rs_add_translate_cb(label_filament,NULL,(void *)K_CTL_TOP_T_FILAMENT,KEY_NUMBER);
    lv_obj_t * label_manuf = lv_label_create(panel);
    lv_obj_align(label_manuf, LV_ALIGN_LEFT_MID, 210, -150);
    lv_label_set_text_static(label_manuf, idx_data_get_manuf(filament_id.manuf_id));
    rs_add_translate_cb(label_manuf,NULL,(void *)K_FILAMENT_UNKNOWN_TYPE,KEY_NUMBER);
    lv_obj_t * label_filament_type = lv_label_create(panel);
    lv_obj_align(label_filament_type, LV_ALIGN_LEFT_MID, 400, -150);
    lv_label_set_text_static(label_filament_type, p_idx->filament_type);
    
    lv_obj_t * label_color = lv_label_create(panel);
    lv_obj_align(label_color, LV_ALIGN_LEFT_MID, 30, -75);
    lv_obj_set_width(label_color, 120);
    lv_label_set_text_static(label_color, RS_TRANSLATE(K_FILAMENT_T_COLOR));
    rs_add_translate_cb(label_color,NULL,(void *)K_FILAMENT_T_COLOR,KEY_NUMBER);
    lv_obj_t * panel_color = ui_panel_create_fliament_sel(panel, 40, 40, 5, tray->tray_color, 0x838383);
    lv_obj_align(panel_color, LV_ALIGN_LEFT_MID, 210, -75);
    
    lv_obj_t * label_nozzle = lv_label_create(panel);
    lv_obj_align(label_nozzle, LV_ALIGN_LEFT_MID, 30, 0);
    lv_obj_set_width(label_nozzle, 120);
    lv_label_set_text_static(label_nozzle, RS_TRANSLATE(K_NOZZLE_TEMPERATURE));
    rs_add_translate_cb(label_nozzle,NULL,(void *)K_NOZZLE_TEMPERATURE,KEY_NUMBER);
    lv_obj_t * label_temp_min = lv_label_create(panel);
    lv_obj_align(label_temp_min, LV_ALIGN_LEFT_MID, 210, 0);
    rs_add_translate_cb(label_temp_min,translate_filament_min,ui_d,KEY_CUSTOM);
    ui_label_temp_min_set_fmt(label_temp_min, tray->nozzle_temp_min);  
    lv_obj_t * label_temp_max = lv_label_create(panel);
    lv_obj_align(label_temp_max, LV_ALIGN_LEFT_MID, 400, 0); 
    rs_add_translate_cb(label_temp_max,translate_filament_max,ui_d,KEY_CUSTOM);
    ui_label_temp_max_set_fmt(label_temp_max, tray->nozzle_temp_max);   
    lv_obj_t * label_info = lv_label_create(panel);
    lv_obj_align(label_info, LV_ALIGN_LEFT_MID, 30, 150);
    lv_obj_set_width(label_info, 500);
    if (tray->tag_uid) {
        lv_obj_t * label_sn = lv_label_create(panel);
        lv_obj_align(label_sn, LV_ALIGN_LEFT_MID, 30, 75);
        lv_obj_set_width(label_sn, 120);
        lv_label_set_text_static(label_sn, "SN");
        lv_obj_t * label_tag_uid = lv_label_create(panel);
        lv_obj_align(label_tag_uid, LV_ALIGN_LEFT_MID, 210, 75);
        lv_label_set_text_fmt(label_tag_uid, "%llX", tray->tag_uid);
        lv_label_set_text_static(label_info, RS_TRANSLATE(K_BAMBU_INFO_READONLY));
        rs_add_translate_cb(label_info,NULL,(void *)K_BAMBU_INFO_READONLY,KEY_NUMBER);
    } else if (bambu_mqtt_is_printing(bambu_mqtt_master)) {
        lv_label_set_text_static(label_info, RS_TRANSLATE(K_SETTING_SLOT_NOT_SUP));
        rs_add_translate_cb(label_info,NULL,(void *)K_SETTING_SLOT_NOT_SUP,KEY_NUMBER);
    }

    lv_obj_t * btn_close = ui_btn_label_create(panel, 120, 50, 13, lv_color_hex(0x838383), RS_TRANSLATE(K_BTN_CLOSE));
    rs_add_translate_cb(btn_close,NULL,(void *)K_BTN_CLOSE,KEY_NUMBER);
    lv_obj_align(btn_close, LV_ALIGN_BOTTOM_RIGHT, -20, -20);
    lv_obj_add_event_cb(btn_close, btn_close_clicked, LV_EVENT_CLICKED, NULL);

    return panel;
}

void ui_dropdown_manuf_set_options(lv_obj_t * dropdown){
    lv_dropdown_clear_options(dropdown);
    for (uint8_t i = 0; i < ARRAY_SIZE(manuf_idx_data); i++) {
        lv_dropdown_add_option(dropdown, manuf_idx_data[i].manuf, i);
    }
}

void ui_dropdown_filament_type_set_options(lv_obj_t * dropdown, uint8_t manuf_i){
    lv_dropdown_clear_options(dropdown);
    if (manuf_i < ARRAY_SIZE(manuf_idx_data)){
        const manuf_idx_data_t * d = &manuf_idx_data[manuf_i];
        for (uint8_t i = 0; i < d->p_idx_num; i++) {
            lv_dropdown_add_option(dropdown, d->p_idx_data[i].filament_type, i);
        }
    } else {
        lv_dropdown_add_option(dropdown, "", 0);
    }
}





// list get from Bambu Handy APP
const uint32_t ams_colors_list[] = {
    0xffffffff, 0xfff144ff, 0xdcf478ff, 0x0acc38ff, 0x057748ff,
    0x0d6284ff, 0x0ee2a0ff, 0x76d9f4ff, 0x46a8f9ff, 0x2850e0ff,
    0x443089ff, 0xa03cf7ff, 0xf330f9ff, 0xd4b1ddff, 0xf95d73ff,
    0xf72323ff, 0x7c4b00ff, 0xf98c36ff, 0xfcecd6ff, 0xd3c5a3ff,
    0xaf7933ff, 0x898989ff, 0xbcbcbcff, 0x161616ff,
};

bool ams_color_exist_in_panel(lv_obj_t * parent, uint32_t c) {
    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) {
        lv_obj_t * p_exist = lv_obj_get_child(parent, i);
        uint32_t c_exist = (uint32_t)(pointer_type)lv_obj_get_user_data(p_exist);
        if (c_exist == c) return true;
    }
    return false;
}

static void color_item_clicked(lv_event_t * e) {    
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
    lv_obj_t * item = lv_event_get_target(e);
    ui_d->tray_color = (uint32_t)(pointer_type)lv_obj_get_user_data(item);
    ui_panel_filament_bg_color_set(ui_d->panel_color, ui_d->tray_color);

    lv_obj_t * panel_c = lv_obj_get_parent(item);
    lv_obj_t * panel = lv_obj_get_parent(panel_c);
    lv_obj_t * panel_bg = lv_obj_get_parent(panel);
    lv_obj_del_async(panel_bg);
}

lv_obj_t * ui_panel_color_create(ui_tray_info_t * ui_d) {
    // ui_screen_main
    lv_obj_t * panel_bg = ui_panel_create(ui_d->panel, 5, lv_color_hex(0x000000));
    lv_obj_set_style_bg_opa(panel_bg, 100, LV_PART_MAIN);
    lv_obj_set_size(panel_bg, 690, 400);

    lv_obj_t * panel = ui_panel_create(panel_bg, 8, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 620, 350);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 0);
    const lv_font_t * font = lv_obj_get_style_text_font(panel, LV_PART_MAIN);
    lv_coord_t font_h = lv_font_get_line_height(font);

    lv_obj_t * label_ams = lv_label_create(panel);
    lv_label_set_text_static(label_ams, "AMS");
    lv_obj_align(label_ams, LV_ALIGN_TOP_LEFT, 20, 20 - font_h / 2);

    lv_obj_t * panel_ams = ui_panel_create(panel, 8, lv_color_hex(0x575757));
    lv_obj_set_style_bg_opa(panel_ams, 0, LV_PART_MAIN);
    lv_obj_set_style_max_width(panel_ams, 560, LV_PART_MAIN);
    lv_obj_set_size(panel_ams, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(panel_ams, LV_ALIGN_TOP_LEFT, 30, 40);
    lv_obj_set_flex_flow(panel_ams, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_pad_hor(panel_ams, 8, LV_PART_MAIN);
    lv_obj_set_style_pad_ver(panel_ams, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_gap(panel_ams, 16, LV_PART_MAIN);
    for (uint8_t ams_i = 0; ams_i < AMS_MAX_NUMBER; ams_i++) {
        bool exist_bit = (BAMBU_DATA_MASTER.ams.ams_exist_bits >> ams_i) & 0x01;
        if (!exist_bit) continue;
        for (uint8_t tray_i = 0; tray_i < TRAY_PER_AMS; tray_i++) {
            tray_t * t = &BAMBU_DATA_MASTER.ams.ams_tray[ams_i][tray_i];
            if (ams_color_exist_in_panel(panel_ams, t->tray_color)) continue;
            lv_obj_t * color_item = ui_panel_create_fliament_sel(panel_ams, 40, 40, 5, t->tray_color, 0x838383);
            lv_obj_set_user_data(color_item, (void *)t->tray_color);
            lv_obj_add_event_cb(color_item, color_item_clicked, LV_EVENT_CLICKED, ui_d);
        }
    }
    lv_obj_update_layout(panel_ams);
    lv_obj_set_width(panel_ams, lv_obj_get_width(panel_ams));
    lv_obj_update_layout(panel_ams);
    lv_coord_t panel_ams_end_x = lv_obj_get_width(panel_ams) + lv_obj_get_x(panel_ams);
    lv_coord_t panel_ams_end_y = lv_obj_get_height(panel_ams) + lv_obj_get_y(panel_ams);

    lv_obj_update_layout(label_ams);
    lv_coord_t label_ams_end_x = lv_obj_get_width(label_ams) + lv_obj_get_x(label_ams);
    static lv_point_t ams_line_points[] = { {0, 0}, {0, 0}};
    ams_line_points[1].x = panel_ams_end_x - label_ams_end_x - 10;
    lv_obj_t * line_ams = ui_line_create(panel, ams_line_points, ARRAY_SIZE(ams_line_points), 1, lv_color_hex(0xFFFFFF));
    lv_obj_align(line_ams, LV_ALIGN_TOP_LEFT, 10 + label_ams_end_x, 20);
    lv_obj_set_style_line_color(line_ams, lv_color_hex(0x838383), LV_PART_MAIN);

    lv_obj_t * label_colors = lv_label_create(panel);
    lv_label_set_text_static(label_colors, RS_TRANSLATE(K_FILAMENT_T_COLOR));
    rs_add_translate_cb(label_colors,NULL,(void *)K_FILAMENT_T_COLOR,KEY_NUMBER);
    lv_obj_align(label_colors, LV_ALIGN_TOP_LEFT, 20, panel_ams_end_y + 20 - font_h / 2);

    lv_obj_t * panel_colors = ui_panel_create(panel, 8, lv_color_hex(0x575757));
    lv_obj_set_style_bg_opa(panel_colors, 0, LV_PART_MAIN);
    lv_obj_set_style_max_width(panel_colors, 560, LV_PART_MAIN);
    lv_obj_set_style_max_height(panel_colors, 350 - panel_ams_end_y - 40 - 20, LV_PART_MAIN);
    lv_obj_set_size(panel_colors, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(panel_colors, LV_ALIGN_TOP_LEFT, 30, panel_ams_end_y + 40);
    lv_obj_set_flex_flow(panel_colors, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_pad_all(panel_colors, 8, LV_PART_MAIN);
    lv_obj_set_style_pad_gap(panel_colors, 16, LV_PART_MAIN);
    for (uint8_t i = 0; i < ARRAY_SIZE(ams_colors_list); i++) {
        lv_obj_t * color_item = ui_panel_create_fliament_sel(panel_colors, 40, 40, 5, ams_colors_list[i], 0x838383);
        lv_obj_set_user_data(color_item, (void *)ams_colors_list[i]);
        lv_obj_add_event_cb(color_item, color_item_clicked, LV_EVENT_CLICKED, ui_d);
    }
    lv_obj_update_layout(panel_colors);
    lv_obj_set_width(panel_colors, lv_obj_get_width(panel_colors));
    lv_obj_update_layout(panel_colors);
    lv_coord_t panel_colors_end_x = lv_obj_get_width(panel_colors) + lv_obj_get_x(panel_colors);
    lv_coord_t panel_colors_end_y = lv_obj_get_height(panel_colors) + lv_obj_get_y(panel_colors);

    lv_obj_update_layout(label_colors);
    lv_coord_t label_colors_end_x = lv_obj_get_width(label_colors) + lv_obj_get_x(label_colors);
    static lv_point_t colors_line_points[] = { {0, 0}, {0, 0}};
    colors_line_points[1].x = panel_colors_end_x - label_colors_end_x - 10;
    lv_obj_t * line_colors = ui_line_create(panel, colors_line_points, ARRAY_SIZE(colors_line_points), 1, lv_color_hex(0xFFFFFF));
    lv_obj_align(line_colors, LV_ALIGN_TOP_LEFT, 10 + label_colors_end_x, panel_ams_end_y + 20);
    lv_obj_set_style_line_color(line_colors, lv_color_hex(0x838383), LV_PART_MAIN);

    lv_obj_set_size(panel, LV_MAX(panel_ams_end_x, panel_colors_end_x) + 30, panel_colors_end_y + 20);

    lv_obj_add_event_cb(panel_bg, ui_del_myself_clicked, LV_EVENT_CLICKED, NULL);
    return panel_bg;
}

static void btn_color_clicked(lv_event_t * e) {
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
    ui_panel_color_create(ui_d);
}

static void btn_reset_clicked(lv_event_t * e) {
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
    ui_dropdown_manuf_set_options(ui_d->dropdown_manuf);
    lv_dropdown_t * dropdown = (lv_dropdown_t *)ui_d->dropdown_manuf;
    dropdown->sel_opt_id_orig = dropdown->sel_opt_id = 0xffff;
    lv_event_send(ui_d->dropdown_manuf, LV_EVENT_VALUE_CHANGED, NULL);
    ui_d->tray_color = 0x0;
    ui_panel_filament_bg_color_set(ui_d->panel_color, ui_d->tray_color);
}

enum {
    UI_AMS_POPUP_BTN_CANCEL,
    UI_AMS_POPUP_BTN_CONFIRM,
};

typedef struct {
    ui_tray_info_t * ui_d;
    const idx_data_t * p_idx;
    lv_obj_t * parent;
    ams_tray_id_t id;
} popup_ams_data_t;

popup_ams_data_t popup_ams_data;
ui_popup_t popup_ams = 
{
    0
};

void ui_set_mqtt_tray_now(ui_tray_info_t * ui_d, const idx_data_t * p_idx) {
    tray_t * tray = ui_d->tray;        
    strlcpy(tray->tray_info_idx, p_idx->tray_info_idx, sizeof(tray->tray_info_idx));
    tray->tray_color = ui_d->tray_color;
    tray->nozzle_temp_max = p_idx->nozzle_temp_max;
    tray->nozzle_temp_min = p_idx->nozzle_temp_min;
    strlcpy(tray->tray_type, p_idx->filament_type, sizeof(tray->tray_type));
}

static void ams_popup_clicked(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt) {
    switch (btn_id) {
        case UI_AMS_POPUP_BTN_CONFIRM: {
            popup_ams_data_t * p_data = (popup_ams_data_t *)cb_data;
            mqtt_one_client_ams_filament_setting(bambu_mqtt_master, p_data->id.ams_id, p_data->id.tray_id, p_data->ui_d->tray_color, p_data->p_idx);
            ui_set_mqtt_tray_now(p_data->ui_d, p_data->p_idx);
            lv_obj_del(p_data->parent);
            break;
        }
        default:
            break;
    }
}

/*text_str 没有空间，局部变量被释放就会显示空白*/
static char buf_pop_warning[256]={0};
const ui_popup_t popup_tpu_not_supported = {
    .text =  K_TPU_NOT_SUPPORTED,
    .btn_num = 1,
    .btn_text = {K_BTN_CONFIRM},
    .btn_id = {UI_AMS_POPUP_BTN_CANCEL, UI_AMS_POPUP_BTN_CONFIRM},
    .popup_cb = ams_popup_clicked, 
};

const ui_popup_t popup_cf_gf_warning = {
    .text = K_CF_GF_WARNING,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_CONFIRM},
    .btn_id = {UI_AMS_POPUP_BTN_CANCEL, UI_AMS_POPUP_BTN_CONFIRM},
    .popup_cb = ams_popup_clicked, 
};

const ui_popup_t popup_pva_warning = {
    .text = K_PVA_WARNING,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_CONFIRM},
    .btn_id = {UI_AMS_POPUP_BTN_CANCEL, UI_AMS_POPUP_BTN_CONFIRM},
    .popup_cb = ams_popup_clicked, 
};

static void btn_confirm_clicked(lv_event_t * e) {
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
    const idx_data_t * p_idx = idx_data_get_array({ui_d->sel_opt_manuf, ui_d->sel_opt_filament_type});
    ams_tray_id_t id = ams_tray_get_index(ui_d->tray);
    // "Spool holder" or AMS_SUPPORTED filament send settings directly.
     if (id.ams_id == 255 || p_idx->ams_support == AMS_SUPPORTED) {
         mqtt_one_client_ams_filament_setting(bambu_mqtt_master, id.ams_id, id.tray_id, ui_d->tray_color, p_idx);
         ui_set_mqtt_tray_now(ui_d, p_idx);
         btn_close_clicked(e);
     } else 
    { 
        const ui_popup_t * p_popup_ams = NULL;
        switch (p_idx->ams_support) {
            case AMS_TNOT_SUPPORTED_TPU:
                p_popup_ams = &popup_tpu_not_supported;
                break;
            case AMS_WARNING_CF_GF:
                p_popup_ams = &popup_cf_gf_warning;
                break;
            case AMS_WARNING_PVA:
                p_popup_ams = &popup_pva_warning;
                break;
            default:
                break;
        }
        if (p_popup_ams)  {
            
            popup_ams_data.ui_d = ui_d;
            popup_ams_data.p_idx = p_idx;
            popup_ams_data.parent = lv_obj_get_parent(lv_event_get_target(e));
            memcpy(&popup_ams_data.id, &id, sizeof(popup_ams_data.id));
            memcpy(&popup_ams, p_popup_ams, sizeof(popup_ams));
            memset(buf_pop_warning,0,sizeof(buf_pop_warning));
            snprintf(buf_pop_warning, sizeof(buf_pop_warning), RS_TRANSLATE(p_popup_ams->text), idx_data_get_manuf(ui_d->sel_opt_manuf), p_idx->filament_type);
            popup_ams.text = K_INVALID_ID;
            popup_ams.text_str = buf_pop_warning;
            popup_ams.cb_data = &popup_ams_data;
            ui_panel_create_popup(&popup_ams, NULL);
        }
    }
}

static void dropdown_manuf_changed(lv_event_t * e) {
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);
    uint16_t sel_opt_manuf = lv_dropdown_get_selected(ui_d->dropdown_manuf);
    if (ui_d->sel_opt_manuf != sel_opt_manuf) {
        ui_d->sel_opt_manuf = sel_opt_manuf;
        ui_dropdown_filament_type_set_options(ui_d->dropdown_filament_type, ui_d->sel_opt_manuf);
        lv_dropdown_t * dropdown = (lv_dropdown_t *)ui_d->dropdown_filament_type;
        dropdown->sel_opt_id_orig = dropdown->sel_opt_id = 0xffff;
        lv_event_send(ui_d->dropdown_filament_type, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void dropdown_filament_type_changed(lv_event_t * e) {
    ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e);

    uint16_t sel_opt_filament_type = lv_dropdown_get_selected(ui_d->dropdown_filament_type);
    if (ui_d->sel_opt_filament_type != sel_opt_filament_type) {
        ui_d->sel_opt_filament_type = sel_opt_filament_type;
        const idx_data_t * p_idx = idx_data_get_array({ui_d->sel_opt_manuf, ui_d->sel_opt_filament_type});
        ui_label_temp_min_set_fmt(ui_d->label_temp_min, p_idx->nozzle_temp_min);
        ui_label_temp_max_set_fmt(ui_d->label_temp_max, p_idx->nozzle_temp_max);
    }
}

static void translate_filament_max_min_edit(lv_event_t * e) 
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_REFRESH)
    {
        ui_tray_info_t * ui_d = (ui_tray_info_t *)lv_event_get_user_data(e); 

        const idx_data_t * p_idx = idx_data_get_array({ui_d->sel_opt_manuf, ui_d->sel_opt_filament_type});

        ui_label_temp_min_set_fmt(ui_d->label_temp_min, p_idx->nozzle_temp_min);
        ui_label_temp_max_set_fmt(ui_d->label_temp_max, p_idx->nozzle_temp_max);
    }
}

void ui_dropdown_set_style(lv_obj_t * dropdown) {
    lv_obj_t * list = lv_dropdown_get_list(dropdown);
    lv_obj_set_style_bg_color(dropdown, lv_color_hex(0x838383), LV_PART_MAIN);
    lv_obj_set_style_border_width(dropdown, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(list, lv_color_hex(0x838383), LV_PART_MAIN);
    lv_obj_set_style_border_width(list, 0, LV_PART_MAIN);
    lv_obj_set_style_max_height(list, 250, LV_PART_MAIN);
    lv_obj_set_style_bg_color(list, lv_color_hex(0x838383),  LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(list, 180,  LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(list, lv_color_hex(LV_32BIT_BTT_RED),  LV_PART_SELECTED | LV_STATE_CHECKED);
}

lv_obj_t * ui_panel_create_tray_edit(lv_obj_t * parent, tray_t * tray) {
    lv_obj_t * panel = ui_panel_create(parent, 5, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 690, 400);
    lv_obj_set_align(panel, LV_ALIGN_CENTER); 
    filament_id_t filament_id = idx_data_get_index(tray->tray_info_idx);

    lv_obj_t * label_filament = lv_label_create(panel);
    lv_obj_align(label_filament, LV_ALIGN_LEFT_MID, 30, -150);
    lv_obj_set_width(label_filament, 120);
    lv_label_set_text_static(label_filament, RS_TRANSLATE(K_CTL_TOP_T_FILAMENT));
    rs_add_translate_cb(label_filament,RS_TRANSLATE_DEFAULT_CB,(void *)K_CTL_TOP_T_FILAMENT,KEY_NUMBER);
    lv_obj_t * dropdown_manuf = lv_dropdown_create(panel);
    ui_dropdown_manuf_set_options(dropdown_manuf);
    lv_obj_align(dropdown_manuf, LV_ALIGN_LEFT_MID, 210, -150);
    lv_obj_set_width(dropdown_manuf, 130);
    ui_dropdown_set_style(dropdown_manuf);
    lv_dropdown_t * dropdown = (lv_dropdown_t *)dropdown_manuf;
    dropdown->sel_opt_id_orig = dropdown->sel_opt_id = filament_id.manuf_id;

    lv_obj_t * dropdown_filament_type = lv_dropdown_create(panel);
    ui_dropdown_filament_type_set_options(dropdown_filament_type, filament_id.manuf_id);
    lv_obj_align(dropdown_filament_type, LV_ALIGN_LEFT_MID, 400, -150);
    lv_obj_set_width(dropdown_filament_type, 220);
    dropdown = (lv_dropdown_t *)dropdown_filament_type;
    ui_dropdown_set_style(dropdown_filament_type);
    dropdown->sel_opt_id_orig = dropdown->sel_opt_id = filament_id.type_id;
    
    lv_obj_t * label_color = lv_label_create(panel);
    lv_obj_align(label_color, LV_ALIGN_LEFT_MID, 30, -75);
    lv_obj_set_width(label_color, 120);
    lv_label_set_text_static(label_color, RS_TRANSLATE(K_FILAMENT_T_COLOR));
    rs_add_translate_cb(label_color,RS_TRANSLATE_DEFAULT_CB,(void *)K_FILAMENT_T_COLOR,KEY_NUMBER);
    lv_obj_t * panel_color = ui_panel_create_fliament_sel(panel, 40, 40, 5, tray->tray_color, 0x838383);
    lv_obj_align(panel_color, LV_ALIGN_LEFT_MID, 210, -75);
    lv_obj_t * btn_color = ui_btn_img_create(panel, 40, 40, 0, lv_color_hex(LV_32BIT_BTT_RED), UI_TRAY_EDIT_IMG);
    lv_obj_set_style_bg_opa(btn_color, 0, LV_PART_MAIN);
    lv_obj_align(btn_color, LV_ALIGN_LEFT_MID, 260, -75);
    
    lv_obj_t * label_nozzle = lv_label_create(panel);
    lv_obj_align(label_nozzle, LV_ALIGN_LEFT_MID, 30, 0);
    lv_obj_set_width(label_nozzle, 120);
    lv_label_set_text_static(label_nozzle, RS_TRANSLATE(K_NOZZLE_TEMPERATURE));
    rs_add_translate_cb(label_nozzle,RS_TRANSLATE_DEFAULT_CB,(void *)K_NOZZLE_TEMPERATURE,KEY_NUMBER);
    lv_obj_t * label_temp_min = lv_label_create(panel);
    lv_obj_align(label_temp_min, LV_ALIGN_LEFT_MID, 210, 0);
    rs_add_translate_cb(label_temp_min,translate_filament_max_min_edit,ui_d,KEY_CUSTOM);
    ui_label_temp_min_set_fmt(label_temp_min, tray->nozzle_temp_min);
    lv_obj_t * label_temp_max = lv_label_create(panel);
    lv_obj_align(label_temp_max, LV_ALIGN_LEFT_MID, 400, 0);
    rs_add_translate_cb(label_temp_min,translate_filament_max_min_edit,ui_d,KEY_CUSTOM);
    ui_label_temp_max_set_fmt(label_temp_max, tray->nozzle_temp_max);

    lv_obj_t * btn_close = ui_btn_label_create(panel, 120, 50, 13, lv_color_hex(0x838383), RS_TRANSLATE(K_BTN_CLOSE));
    lv_obj_align(btn_close, LV_ALIGN_BOTTOM_RIGHT, -300, -20);
    lv_obj_add_event_cb(btn_close, btn_close_clicked, LV_EVENT_CLICKED, NULL);
    rs_add_translate_cb(btn_close,RS_TRANSLATE_DEFAULT_CB,(void *)K_BTN_CLOSE,KEY_NUMBER);

    lv_obj_t * btn_reset = ui_btn_label_create(panel, 120, 50, 13, lv_color_hex(0x838383), RS_TRANSLATE(K_BTN_RESET));
    lv_obj_align(btn_reset, LV_ALIGN_BOTTOM_RIGHT, -160, -20);
    rs_add_translate_cb(btn_reset,RS_TRANSLATE_DEFAULT_CB,(void *)K_BTN_RESET,KEY_NUMBER);

    lv_obj_t * btn_confirm = ui_btn_label_create(panel, 120, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(K_BTN_CONFIRM));
    lv_obj_align(btn_confirm, LV_ALIGN_BOTTOM_RIGHT, -20, -20);
    rs_add_translate_cb(btn_confirm,RS_TRANSLATE_DEFAULT_CB,(void *)K_BTN_CONFIRM,KEY_NUMBER);

    ui_d->panel = panel;
    ui_d->dropdown_manuf = dropdown_manuf;
    ui_d->dropdown_filament_type = dropdown_filament_type;
    ui_d->panel_color = panel_color;
    ui_d->label_temp_max = label_temp_max;
    ui_d->label_temp_min = label_temp_min;
    ui_d->tray = tray;
    ui_d->sel_opt_manuf = filament_id.manuf_id;
    ui_d->sel_opt_filament_type = filament_id.type_id;
    ui_d->tray_color = tray->tray_color;

    lv_obj_add_event_cb(btn_color, btn_color_clicked, LV_EVENT_CLICKED, ui_d);
    lv_obj_add_event_cb(btn_reset, btn_reset_clicked, LV_EVENT_CLICKED, ui_d);
    lv_obj_add_event_cb(btn_confirm, btn_confirm_clicked, LV_EVENT_CLICKED, ui_d);
    lv_obj_add_event_cb(dropdown_manuf, dropdown_manuf_changed, LV_EVENT_VALUE_CHANGED, ui_d);
    lv_obj_add_event_cb(dropdown_filament_type, dropdown_filament_type_changed, LV_EVENT_VALUE_CHANGED, ui_d);

    return panel;
}
