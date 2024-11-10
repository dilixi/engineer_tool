#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"
#include "printer_group.h"

#define SW_PRINT_CTRL_AXIS 0

#if SW_PRINT_CTRL_AXIS && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "printers"; 
#define PRINT_CTRL_AXIS(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_CTRL_AXIS(...)
#endif

// 3 obj for "Part", "Aux" and "Chamber"
ui_fan_obj_t ui_fan_obj[3] = 
{
    {
        .multi_lang_data = {K_CTL_T_PART},
    },
    {
        .multi_lang_data = {K_CTL_T_AUX},
    },
    {
        .multi_lang_data = {K_CTL_T_CHAMBER},
    }, 
};

typedef enum {
    MLG_KEY_IDX_SPEED=0,
    MLG_KEY_IDX_SPEED_SILENT,
    MLG_KEY_IDX_SPEED_STANDARD, 
    MLG_KEY_IDX_SPEED_SPORT, 
    MLG_KEY_IDX_SPEED_LUDICROUS, 
    MLG_KEY_IDX_MAX,
} MLG_KEY_idx_t;

static MLG_TRANSLATE_DATA_T multi_lang_keys_speed[] = 
{
    {K_CTL_T_SPEED,},
    {K_CTL_T_SPEED_SILENT,},
    {K_CTL_T_SPEED_STANDARD,},
    {K_CTL_T_SPEED_SPORT,},
    {K_CTL_T_SPEED_LUDICROUS,}, 
};
   
#define P_MULTI_LANG_KEYS multi_lang_keys_speed

static void add_translate_event(lv_obj_t *p_obj, uint8_t set_idx)
{
    if (set_idx < MLG_KEY_IDX_MAX)
    {
        rs_add_translate_cb(p_obj,P_MULTI_LANG_KEYS[set_idx].translate_cb,(void *)P_MULTI_LANG_KEYS[set_idx].key,KEY_NUMBER);
    }
}

lv_obj_t * ui_btn_nozzle = NULL;
lv_obj_t * ui_btn_bed = NULL;
lv_obj_t * ui_btn_chamber = NULL;
lv_obj_t * ui_btn_speed = NULL;
lv_obj_t * ui_btn_fan = NULL;
lv_obj_t * ui_panel_slider_speed = NULL;
static lv_obj_t * ui_img_nozzle = NULL;
static lv_obj_t * ui_img_bed = NULL;
static void update_translate_objs_fan(void)
{
    for (int i=0; i<LENGTH_OF_ARRAY(ui_fan_obj); i++)
    {
        lv_obj_t* get_sw = ui_fan_obj[i].sw;
        lv_obj_t* get_sw_labe = ui_fan_obj[i].sw_label;

        if ((get_sw) && (get_sw_labe))
        {
            if (lv_obj_has_state(get_sw,LV_STATE_CHECKED))
            {
                lv_label_set_text(get_sw_labe, RS_TRANSLATE(K_SW_T_ON));
            }
            else
            {
                lv_label_set_text(get_sw_labe, RS_TRANSLATE(K_SW_T_OFF));
            }
        }
    }
}

void ui_ctl_screen_translate_keys_speed(lv_obj_t *parent)
{
    uint8_t get_idx = 0; 

    if (!parent) return; 

    if (!lv_obj_is_valid(parent))
    {
        return;
    }

    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) 
    {
        lv_obj_t * obj = lv_obj_get_child(parent, i);
        
        if (obj)
        {
            if (lv_obj_check_type(obj, &lv_label_class))
            {
                if (lv_obj_has_flag(obj,LV_OBJ_FLAG_MULTI_LANG))
                {
                    lv_label_set_text(obj,RS_TRANSLATE(P_MULTI_LANG_KEYS[get_idx].key));

                    get_idx++;
                }
            }
        }
    }
} 

static MLG_TRANSLATE_DATA_T S_MLG_KEY_TITLES[] = 
{ 
    {K_CTL_T_EXTRUDER,},
};

static int32_t current_warning_max=0;
lv_obj_t * label_error = NULL;
 

static void ui_meter_fan_set_value_anim(void * obj, int32_t v) {
    ui_fan_obj_t * fan_obj = (ui_fan_obj_t *)obj;    
    lv_meter_set_indicator_value(fan_obj->meter, fan_obj->meter_indic_pointer, v);
    lv_meter_set_indicator_end_value(fan_obj->meter, fan_obj->meter_indic_start, v);
    lv_meter_set_indicator_start_value(fan_obj->meter, fan_obj->meter_indic_end, v);
}

void ui_meter_fan_set_value(ui_fan_obj_t * fan_obj, uint8_t v) {
    int32_t nv = fan_obj->meter_indic_pointer->end_value;
    uint32_t duration = LV_ABS(v - nv) / 10 * 50; // total 10 scale, and 50ms per scale
    /*Create an animation to set the value*/
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, ui_meter_fan_set_value_anim);
    lv_anim_set_var(&a, fan_obj);
    lv_anim_set_values(&a, nv, v);
    lv_anim_set_time(&a, duration);
    lv_anim_start(&a);

    lv_label_set_text_fmt(fan_obj->meter_label_speed, "%d%%", v);
}

static void btn_fan_dec_clicked(lv_event_t * e) {
    const uint32_t obj_index = (uint32_t)(pointer_type)lv_event_get_user_data(e);
    uint8_t v = BAMBU_DATA_MASTER.fan_speed[obj_index] > 10 ? 10 : BAMBU_DATA_MASTER.fan_speed[obj_index];
    if (v) {
        BAMBU_DATA_MASTER.fan_speed[obj_index] -= v;
        char buf[64];
        snprintf(buf, sizeof(buf), "M106 P%ld S%d\n", obj_index + 1, BAMBU_DATA_MASTER.fan_speed[obj_index] * 255 / 100);
        mqtt_gcode_line(buf);
    }
}

static void btn_fan_inc_clicked(lv_event_t * e) {
    const uint32_t obj_index = (uint32_t)(pointer_type)lv_event_get_user_data(e);
    uint8_t v = BAMBU_DATA_MASTER.fan_speed[obj_index] < 90 ? 10 : (100 - BAMBU_DATA_MASTER.fan_speed[obj_index]);
    if (v) {
        BAMBU_DATA_MASTER.fan_speed[obj_index] += v;
        char buf[64];
        snprintf(buf, sizeof(buf), "M106 P%ld S%d\n", obj_index + 1, BAMBU_DATA_MASTER.fan_speed[obj_index] * 255 / 100);
        mqtt_gcode_line(buf);
    }
}

static void btn_fan_switch_clicked(lv_event_t * e) {
    const uint32_t obj_index = (uint32_t)(pointer_type)lv_event_get_user_data(e);
    if (BAMBU_DATA_MASTER.fan_speed[obj_index]) {
        BAMBU_DATA_MASTER.fan_speed[obj_index] = 0;
        char buf[64];
        snprintf(buf, sizeof(buf), "M106 P%ld S0\n", obj_index + 1);
        mqtt_gcode_line(buf);
    } else {
        BAMBU_DATA_MASTER.fan_speed[obj_index] = 100;
        char buf[64];
        snprintf(buf, sizeof(buf), "M106 P%ld S255\n", obj_index + 1);
        mqtt_gcode_line(buf);
    }
}

lv_obj_t * ui_panel_add_fan(lv_obj_t * parent, const char * name, lv_align_t align, ui_fan_obj_t * fan_obj, uint32_t obj_index) {
    const lv_color_t bg_c = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_BG_COLOR).color;
    lv_obj_t * panel = ui_panel_create(parent, 0, bg_c);
    lv_obj_set_size(panel, 163, 400);
    lv_obj_set_align(panel, align);
    const int32_t w = lv_obj_get_style_prop(panel, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    const int32_t h = lv_obj_get_style_prop(panel, LV_PART_MAIN, LV_STYLE_HEIGHT).num;

    lv_obj_t * panel_name = ui_panel_create(panel, 0, bg_c);
    lv_obj_set_size(panel_name, w, 25);
    lv_obj_align(panel_name, LV_ALIGN_TOP_MID, 0, 35);
    lv_obj_set_flex_flow(panel_name, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(panel_name, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_t * img = lv_img_create(panel_name);
    lv_img_set_src(img, &ui_img_little_fan_png);
    lv_obj_set_style_img_recolor(img, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_img_recolor_opa(img, 0, LV_PART_MAIN);
    lv_obj_t * label_name = lv_label_create(panel_name);
    rs_add_translate_cb(label_name,fan_obj->multi_lang_data.translate_cb,(void *)fan_obj->multi_lang_data.key,KEY_NUMBER);
 

    

    fan_obj->img = img;

    lv_obj_t * meter = lv_meter_create(panel);
    lv_obj_align(meter, LV_ALIGN_TOP_MID, 0, 70);
    lv_obj_set_size(meter, 130, 130);
    /*Remove the circle from the middle*/
    lv_obj_remove_style(meter, NULL, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(meter, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(meter, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(meter, 6, LV_PART_MAIN);
    /*Add a scale first*/
    lv_meter_scale_t * scale = lv_meter_add_scale(meter);
    lv_meter_set_scale_ticks(meter, scale, 11, 3, 6, bg_c);
    lv_meter_set_scale_range(meter, scale, 0, 100, 300, 120);
    fan_obj->meter = meter;

    /*Add a three arc indicator*/
    lv_meter_indicator_t * indic_arc = lv_meter_add_arc(meter, scale, 3, lv_color_hex(0xFFFFFF), 5);
    lv_meter_set_indicator_end_value(meter, indic_arc, 100);
    lv_meter_indicator_t * indic_start = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_RED), -1);    
    lv_meter_indicator_t * indic_end = lv_meter_add_arc(meter, scale, 3, lv_color_hex(0x888888), -1);
    lv_meter_set_indicator_end_value(meter, indic_end, 100);
    lv_meter_indicator_t * indic_pointer = lv_meter_add_needle_img(meter, scale, &ui_img_pointer_png, 5, 5);
    fan_obj->meter_indic_start = indic_start;
    fan_obj->meter_indic_end = indic_end;
    fan_obj->meter_indic_pointer = indic_pointer;

    lv_obj_t * label_speed = lv_label_create(meter);
    lv_obj_align(label_speed, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_label_set_text(label_speed, "0%");
    // lv_obj_set_style_text_font(label_speed, &lv_font_montserrat_20, LV_PART_MAIN);
    lv_obj_set_style_text_color(label_speed, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    fan_obj->meter_label_speed = label_speed;

    lv_obj_t * panel_btn = ui_panel_create(panel, 5, bg_c);
    lv_obj_set_style_clip_corner(panel_btn, true, LV_PART_MAIN);
    lv_obj_set_size(panel_btn, 103, 42);
    lv_obj_align(panel_btn, LV_ALIGN_TOP_MID, 0, 261);
    lv_obj_set_style_border_width(panel_btn, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(panel_btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    lv_obj_t * btn_dec = ui_btn_img_create(panel_btn, 50, 40, 5, bg_c, NULL);
    lv_obj_align(btn_dec, LV_ALIGN_LEFT_MID, 0, 0);
    /* must be static not const*/
    static lv_point_t h_line_points[] = { {0, 0}, {17, 0}};
    lv_obj_t * dec_h_line = ui_line_create(btn_dec, h_line_points, ARRAY_SIZE(h_line_points), 3, lv_color_hex(0xFFFFFF));
    lv_obj_center(dec_h_line);
    lv_obj_add_event_cb(btn_dec, btn_fan_dec_clicked, LV_EVENT_CLICKED, (void *)obj_index);

    lv_obj_t * btn_inc = ui_btn_img_create(panel_btn, 50, 40, 5, bg_c, NULL);
    lv_obj_align(btn_inc, LV_ALIGN_RIGHT_MID, 0, 0);
    /* must be static not const*/
    lv_obj_t * inc_h_line = ui_line_create(btn_inc, h_line_points, ARRAY_SIZE(h_line_points), 3, lv_color_hex(0xFFFFFF));
    lv_obj_center(inc_h_line);
    static lv_point_t v_line_points[] = { {0, 0}, {0, 17}};
    lv_obj_t * inc_v_line = ui_line_create(btn_inc, v_line_points, ARRAY_SIZE(v_line_points), 3, lv_color_hex(0xFFFFFF));
    lv_obj_align(inc_v_line, LV_ALIGN_CENTER, -1, 1);
    lv_obj_add_event_cb(btn_inc, btn_fan_inc_clicked, LV_EVENT_CLICKED, (void *)obj_index);

    /* must be static not const*/
    static lv_point_t line_points[] = { {0, 0}, {0, 30}};
    lv_obj_t * line = ui_line_create(panel_btn, line_points, ARRAY_SIZE(line_points), 1, lv_color_hex(0xFFFFFF));
    lv_obj_center(line);

    lv_obj_t * panel_switch = ui_panel_create(panel, 0, bg_c);  
    lv_obj_set_size(panel_switch, w, 25);  
    lv_obj_align(panel_switch, LV_ALIGN_TOP_MID, 0, 333);
    lv_obj_set_flex_flow(panel_switch, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(panel_switch, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_t * sw = lv_switch_create(panel_switch);
    lv_obj_set_size(sw, 40, 22);
    lv_obj_set_style_bg_color(sw, lv_color_hex(0xC9C9C9), LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(sw, lv_color_hex(0xC9C9C9), LV_PART_MAIN);
    lv_obj_set_style_bg_color(sw, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(sw, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_event_cb(sw, btn_fan_switch_clicked, LV_EVENT_CLICKED, (void *)obj_index);
    lv_obj_t * label_sw = lv_label_create(panel_switch);

    lv_label_set_text(label_sw, RS_TRANSLATE(K_SW_T_OFF));
    fan_obj->sw = sw;
    fan_obj->sw_label = label_sw;

    return panel;
}

lv_obj_t * ui_panel_create_axis_fan(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 8, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 489, 400);
    lv_obj_align(panel, LV_ALIGN_TOP_RIGHT, 0, 0);

    ui_panel_add_fan(panel, "Part", LV_ALIGN_LEFT_MID, &ui_fan_obj[0], 0);
    ui_panel_add_fan(panel, "Aux.", LV_ALIGN_CENTER, &ui_fan_obj[1], 1);
    ui_panel_add_fan(panel, "Chamber", LV_ALIGN_RIGHT_MID, &ui_fan_obj[2], 2);

    return panel;
}

static lv_obj_t * label_ctrl_nozzle_temper = NULL;
static lv_obj_t * label_ctrl_nozzle_target_temper = NULL;
static lv_obj_t * label_ctrl_bed_temper = NULL;
static lv_obj_t * label_ctrl_bed_target_temper = NULL;
static lv_obj_t * label_ctrl_chamber_temper = NULL;
static lv_obj_t * label_ctrl_chamber_humidity = NULL;
static lv_obj_t * label_ctrl_speed = NULL;

/************* temperature ***************/
lv_obj_t * ui_btn_create_ctrl_temperature(lv_obj_t * parent, lv_coord_t y_ofs, const void * img_src) {    
    lv_coord_t r = lv_obj_get_style_radius(parent, LV_PART_MAIN);
    lv_color_t bg_c = lv_obj_get_style_bg_color(parent, LV_PART_MAIN);
    lv_obj_t * btn = ui_btn_img_create(parent, 193, 77, r, bg_c, NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 0, y_ofs);
    lv_obj_set_style_border_color(btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_border_opa(btn, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(btn, 1, LV_PART_MAIN);
    lv_obj_set_style_border_side(btn, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN);
    // lv_obj_set_style_pad_hor(btn, 10, LV_PART_MAIN);
    // lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_ROW);
    // lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // lv_obj_set_style_pad_column(btn, 5, LV_PART_MAIN);

    if (img_src) {
        lv_obj_t * img = lv_img_create(btn);
        lv_img_set_src(img, img_src);
        lv_obj_align(img, LV_ALIGN_LEFT_MID, 10, 0);
        lv_obj_set_style_img_recolor(img, lv_color_hex(0xFF9F09), LV_PART_MAIN);
        lv_obj_set_style_img_recolor_opa(img, 0, LV_PART_MAIN);
    }

    return btn;
}

lv_obj_t * ui_btn_add_ctrl_temperature_fan(lv_obj_t * parent, lv_coord_t x_ofs, const char * name, ui_fan_obj_t * fan_obj) {
    lv_obj_t * label_name = lv_label_create(parent);
    lv_obj_align(label_name, LV_ALIGN_TOP_MID, x_ofs, 15);
    
    rs_add_translate_cb(label_name,fan_obj->multi_lang_data.translate_cb,(void *)fan_obj->multi_lang_data.key,KEY_NUMBER);
    
    lv_obj_t * img = lv_img_create(parent);
    lv_img_set_src(img, &ui_img_little_fan_png);
    lv_obj_set_style_img_recolor(img, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_img_recolor_opa(img, 0, LV_PART_MAIN);
    lv_obj_align(img, LV_ALIGN_CENTER, x_ofs, 0);
    fan_obj->btn_img = img;

    lv_obj_t * label_speed = lv_label_create(parent);
    lv_obj_align(label_speed, LV_ALIGN_BOTTOM_MID, x_ofs, -15);
    lv_label_set_text(label_speed, "0%");
    fan_obj->btn_label_speed = label_speed;

    return NULL;
}

enum {
    KEYBOARD_TYPE_NOZZLE = 0,
    KEYBOARD_TYPE_BED,
};

void ui_panel_btnm_keyboard_del(lv_obj_t * target);

const int32_t target_max[] = {300, 100};

static void btnm_clicked(lv_event_t * e) {
    lv_obj_t * keyboard = (lv_obj_t * )lv_event_get_target(e);
    const char * text_keyboard = lv_btnmatrix_get_btn_text(keyboard, lv_btnmatrix_get_selected_btn(keyboard));
    if (text_keyboard == NULL) return;
    lv_obj_t * label_edit = (lv_obj_t * )lv_event_get_user_data(e);
    lv_obj_t * label_target = lv_obj_get_parent(label_edit);
    label_error = (lv_obj_t *)lv_obj_get_user_data(label_target);
    lv_obj_t * btn_target = lv_obj_get_parent(label_target);
    const char * text_edit = lv_label_get_text(label_edit);
    uint32_t type = (uint32_t)(pointer_type)lv_obj_get_user_data(label_edit);
    int32_t edit_max = target_max[type];
    if (BAMBU_MODEL_X1 == bambu_mqtt_master->nvs_config.model_num)
    {
        /*
        Living in germany with 240V / 50Hz we are able to get up to 110°C with the X1-series.
        In countrys with 120V / 60Hz you're allowed to get up to 120°C with the X1-series.
        */
        edit_max=120;
    }
    current_warning_max = edit_max;
    bool del = false;

    int num = atoi(text_edit);

    if(strcmp(text_keyboard, LV_SYMBOL_BACKSPACE) == 0){
        lv_label_cut_text(label_edit,  strlen(text_edit) - 1, 1);
    }
    else if(strcmp(text_keyboard, "OK") == 0) {
        if (num <= edit_max && strlen(text_edit)) {
            del = true;
            char buf[10];
            switch (type) {
                case KEYBOARD_TYPE_NOZZLE:            
                    BAMBU_DATA_MASTER.nozzle_target_temper = num;
                    snprintf(buf, size_t(buf), "M104 S%d\n", num);
                    break;
                case KEYBOARD_TYPE_BED:            
                    BAMBU_DATA_MASTER.bed_target_temper = num;
                    snprintf(buf, size_t(buf), "M140 S%d\n", num);
                    break;
                default:
                    break;
            }
            mqtt_gcode_line(buf);
        }
    }
    else {
        if (num < edit_max) {
            if (num == 0) {
                lv_label_cut_text(label_edit,  strlen(text_edit) - 1, 1);
            }
            lv_label_ins_text(label_edit, LV_LABEL_POS_LAST, text_keyboard);
        }
    }

    num = atoi(text_edit);
    if (num > edit_max) {
        lv_obj_set_style_text_color(label_edit, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
        if (label_error == NULL) {
            label_error = lv_label_create(btn_target);
            lv_label_set_text_fmt(label_error, RS_TRANSLATE(K_CTL_T_TEMP_HIGH), edit_max);
            lv_obj_set_style_text_color(label_error, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
            lv_obj_add_flag(label_error, LV_OBJ_FLAG_FLOATING);
            lv_obj_align(label_error, LV_ALIGN_BOTTOM_MID, 0, 0);
            lv_obj_set_user_data(label_target, label_error);
        }
    } else {
        lv_obj_set_style_text_color(label_edit, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
        if (label_error) {
            current_warning_max=0;
            lv_obj_del(label_error);
            lv_obj_set_user_data(label_target, (void *)0);
        }
    }

    if (del) {
        ui_panel_btnm_keyboard_del(lv_obj_get_parent(label_edit));
    }
}


lv_obj_t * ui_btnm_keyboard_create(lv_obj_t * parent, lv_obj_t * ta, uint32_t type) {        
    lv_obj_t * label_edit = lv_label_create(ta);
    lv_label_set_text(label_edit, "");
    lv_obj_set_size(label_edit, 45, LV_SIZE_CONTENT);
    lv_obj_set_style_bg_color(label_edit, lv_color_hex(0x838383), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(label_edit, 255, LV_PART_MAIN);
    lv_obj_set_user_data(label_edit, (void *)type);

    static const char * btnm_map[] = {"1", "2", "3", "\n",
                                      "4", "5", "6", "\n",
                                      "7", "8", "9", "\n",
                                      "0", LV_SYMBOL_BACKSPACE, "OK", ""
                                     };

    lv_obj_t * btnm = lv_btnmatrix_create(parent);
    lv_obj_set_size(btnm, 450, 380);
    lv_obj_align(btnm, LV_ALIGN_RIGHT_MID, -21, 0);
    lv_btnmatrix_set_map(btnm, btnm_map);

    lv_obj_set_style_bg_opa(btnm, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(btnm, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(btnm, 0, LV_PART_ITEMS);
    lv_obj_set_style_bg_color(btnm, lv_color_hex(0x838383), LV_PART_ITEMS);
    lv_obj_set_style_bg_opa(btnm, 255, LV_PART_ITEMS);
    lv_obj_set_style_text_font(btnm, LV_FONT_DEFAULT_24, LV_PART_ITEMS);
    lv_obj_set_style_text_color(btnm, lv_color_hex(0xFFFFFF), LV_PART_ITEMS);

    lv_obj_add_event_cb(btnm, btnm_clicked, LV_EVENT_CLICKED, label_edit);

    return btnm;
}

void ui_panel_hidden_ctrl(lv_obj_t * btn) {
    if (btn == NULL) return;
    lv_obj_t * panel = (lv_obj_t *)lv_obj_get_user_data(btn);
    if (panel == NULL) return;
    if (lv_obj_has_flag_any(panel, LV_OBJ_FLAG_HIDDEN)) return;

    lv_obj_add_flag(panel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_state(btn, LV_STATE_PRESSED);
}

void ui_panel_btnm_keyboard_del(lv_obj_t * target) {
    if (target == NULL) return;
    lv_obj_t * btn = lv_obj_get_parent(target);
    if (btn == NULL) return;
    lv_obj_t * panel_keyboard = (lv_obj_t *)lv_obj_get_user_data(btn);
    if (panel_keyboard == NULL) return;

    lv_obj_clear_state(btn, LV_STATE_PRESSED);
    lv_obj_del_async(panel_keyboard);
    lv_obj_set_user_data(btn, (void *)0);

    label_error = (lv_obj_t *)lv_obj_get_user_data(target);
    if (label_error) {
        current_warning_max=0;
        lv_obj_del(label_error);
        lv_obj_set_user_data(target, (void *)0);
    }

    lv_obj_t * label_edit = (lv_obj_t *)lv_obj_get_child(target, 0);
    if (label_edit) {
        lv_obj_del(label_edit);
    }
}

lv_obj_t * ui_panel_btnm_keyboard_create(lv_obj_t * parent, lv_obj_t * target, uint32_t type) {
    lv_obj_t * panel = ui_panel_create(parent, 8, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 489, 400);
    lv_obj_align(panel, LV_ALIGN_TOP_RIGHT, 0, 0);

    ui_btnm_keyboard_create(panel, target, type);

    return panel;
}


lv_obj_t * ui_slider_list_create(lv_obj_t * parent, MLG_KEY_TYPE title, MLG_TRANSLATE_DATA_T* multi_lang_data, uint8_t min, uint8_t max) {
    uint8_t num = max - min;//3-0=3
    lv_coord_t y_start = -120;
    lv_coord_t y_end = 150;
    lv_coord_t y_total = (y_end - y_start);
    lv_coord_t y_inc = y_total / num;

    lv_obj_t * panel = ui_panel_create(parent, 10, lv_color_hex(0x838383));
    lv_obj_set_size(panel, 300, 380);

    lv_obj_t * label_title = lv_label_create(panel); 
    lv_label_set_text(label_title,RS_TRANSLATE(title)); 
    lv_obj_add_flag(label_title,LV_OBJ_FLAG_MULTI_LANG);
    lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, 20, 10);
    
    /* must be static not const*/
    static lv_point_t v_line_points[] = { {0, 0}, {0, 270}};
    lv_obj_t * v_line = ui_line_create(panel, v_line_points, 2, 2, lv_color_hex(0x444444));
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 95, 15);

    for (uint8_t i = 0; i <= num; i++) {
        lv_coord_t y_ofs = y_end - (y_inc * i);
        lv_obj_t * p = ui_panel_create(panel, LV_RADIUS_CIRCLE, lv_color_hex(0x444444));
        lv_obj_set_size(p, 20, 20);
        lv_obj_align(p, LV_ALIGN_LEFT_MID, 85, y_ofs);

        lv_obj_t * label = lv_label_create(panel);
        lv_label_set_text(label, RS_TRANSLATE(multi_lang_data[i].key));  
        lv_obj_add_flag(label,LV_OBJ_FLAG_MULTI_LANG);
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 120, y_ofs);
        ui_obj_set_type(label, (ui_type_t)(UI_TYPE_SLIDER_LABEL_0 + i));
    }

    lv_obj_t * slider = lv_slider_create(panel);
    lv_slider_set_range(slider, min, max);
    lv_obj_set_size(slider, 200, y_total);
    lv_obj_align(slider, LV_ALIGN_LEFT_MID, 65, 15);
    lv_obj_set_style_radius(slider, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(slider, 0, LV_PART_INDICATOR);
    lv_obj_set_style_radius(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_bg_opa(slider, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(slider, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_bg_img_src(slider, &ui_img_icon_knob_png, LV_PART_KNOB); 
    ui_obj_set_type(slider, UI_TYPE_SLIDER);

    return panel;
}


void ui_slider_list_sel(lv_obj_t * parent, uint8_t sel) {
    if (parent == NULL) return;
    lv_obj_t * slider = ui_obj_get(parent, UI_TYPE_SLIDER);
    uint8_t min = lv_slider_get_min_value(slider);
    uint8_t max = lv_slider_get_max_value(slider);
    if (sel > max || sel < min) return;
    uint8_t num = max - min;
    uint8_t label_sel = sel - min;
    for (uint8_t i = 0; i <= num; i++) {        
        lv_obj_t * label = ui_obj_get(parent, (ui_type_t)(UI_TYPE_SLIDER_LABEL_0 + i));
        lv_obj_set_style_text_color(label, lv_color_hex((i == label_sel) ? LV_32BIT_BTT_RED : 0xFFFFFF), LV_PART_MAIN);
    }
    lv_slider_set_value(slider, sel, LV_ANIM_OFF);
}


static uint32_t send_spd_lvl = 0;
static void slider_speed_changed(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    int32_t index = lv_slider_get_value(slider);
    ui_slider_list_sel(ui_panel_slider_speed, index);
    send_spd_lvl = index;
}

lv_obj_t * ui_panel_create_speed(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 8, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 489, 400);
    lv_obj_align(panel, LV_ALIGN_TOP_RIGHT, 0, 0);
 
    ui_panel_slider_speed = ui_slider_list_create(panel, P_MULTI_LANG_KEYS[MLG_KEY_IDX_SPEED].key, &P_MULTI_LANG_KEYS[MLG_KEY_IDX_SPEED_SILENT], MLG_KEY_IDX_SPEED_SILENT, MLG_KEY_IDX_MAX-1);
    lv_obj_align(ui_panel_slider_speed, LV_ALIGN_RIGHT_MID, -60, 0);
    lv_obj_add_event_cb(ui_obj_get(ui_panel_slider_speed, UI_TYPE_SLIDER), slider_speed_changed, LV_EVENT_VALUE_CHANGED, NULL);
    
    ui_slider_list_sel(ui_panel_slider_speed, 2); // Standard

    return panel;
}


static void btn_nozzle_clicked(lv_event_t * e) {
    ui_panel_btnm_keyboard_del(label_ctrl_bed_target_temper);
    ui_panel_hidden_ctrl(ui_btn_fan);
    ui_panel_hidden_ctrl(ui_btn_speed);

    // lv_obj_t * btn = (lv_obj_t *)lv_event_get_target(e);
    lv_obj_t * parent = lv_obj_get_parent(lv_obj_get_parent(ui_btn_nozzle));

    lv_obj_t * panel = (lv_obj_t *)lv_obj_get_user_data(ui_btn_nozzle);
    if (!panel) {
        lv_obj_add_state(ui_btn_nozzle, LV_STATE_PRESSED);
        lv_obj_t * panel_btnm = ui_panel_btnm_keyboard_create(parent, label_ctrl_nozzle_target_temper, KEYBOARD_TYPE_NOZZLE);
        lv_obj_set_user_data(ui_btn_nozzle, panel_btnm);
    } else {
        ui_panel_btnm_keyboard_del(label_ctrl_nozzle_target_temper);
    }
}

static void btn_bed_clicked(lv_event_t * e) {
    ui_panel_btnm_keyboard_del(label_ctrl_nozzle_target_temper);
    ui_panel_hidden_ctrl(ui_btn_fan);
    ui_panel_hidden_ctrl(ui_btn_speed);

    // lv_obj_t * btn = (lv_obj_t *)lv_event_get_target(e);
    lv_obj_t * parent = lv_obj_get_parent(lv_obj_get_parent(ui_btn_bed));
    
    lv_obj_t * panel = (lv_obj_t *)lv_obj_get_user_data(ui_btn_bed);
    if (!panel) {
        lv_obj_add_state(ui_btn_bed, LV_STATE_PRESSED);
        lv_obj_t * panel_btnm = ui_panel_btnm_keyboard_create(parent, label_ctrl_bed_target_temper, KEYBOARD_TYPE_BED);
        lv_obj_set_user_data(ui_btn_bed, panel_btnm);
    } else {
        ui_panel_btnm_keyboard_del(label_ctrl_bed_target_temper);
    }
}

static void btn_chamber_clicked(lv_event_t * e) {
    ui_panel_btnm_keyboard_del(label_ctrl_nozzle_target_temper);
    ui_panel_btnm_keyboard_del(label_ctrl_bed_target_temper);
    ui_panel_hidden_ctrl(ui_btn_fan);
    ui_panel_hidden_ctrl(ui_btn_speed);
}

static void btn_speed_clicked(lv_event_t * e) {
    ui_panel_btnm_keyboard_del(label_ctrl_nozzle_target_temper);
    ui_panel_btnm_keyboard_del(label_ctrl_bed_target_temper);
    ui_panel_hidden_ctrl(ui_btn_fan);

    lv_obj_t * panel = (lv_obj_t *)lv_obj_get_user_data(ui_btn_speed);
    if (panel) {
        if (lv_obj_has_flag_any(panel, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_clear_flag(panel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_state(ui_btn_speed, LV_STATE_PRESSED);
        } else {
            ui_panel_hidden_ctrl(ui_btn_speed);
        }
    }
}

static void btn_fan_clicked(lv_event_t * e) {
    ui_panel_btnm_keyboard_del(label_ctrl_nozzle_target_temper);
    ui_panel_btnm_keyboard_del(label_ctrl_bed_target_temper);
    ui_panel_hidden_ctrl(ui_btn_speed);

    lv_obj_t * panel = (lv_obj_t *)lv_obj_get_user_data(ui_btn_fan);
    if (panel) {
        if (lv_obj_has_flag_any(panel, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_clear_flag(panel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_state(ui_btn_fan, LV_STATE_PRESSED);
        } else {
            ui_panel_hidden_ctrl(ui_btn_fan);
        }
    }
}

void ui_panel_add_ctrl_temperature(lv_obj_t * parent) {
    lv_coord_t r = lv_obj_get_style_radius(parent, LV_PART_MAIN);
    lv_obj_t * panel_left = ui_panel_create(parent, r, lv_color_hex(0x838383));
    lv_obj_set_size(panel_left, 197, 400);
    lv_obj_align(panel_left, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_clip_corner(panel_left, true, LV_PART_MAIN);

    ui_btn_fan = ui_btn_img_create(panel_left, 193, 92, r, lv_color_hex(0x838383), NULL);
    lv_obj_align(ui_btn_fan, LV_ALIGN_TOP_MID, 0, 308);
    lv_obj_set_style_text_font(ui_btn_fan, &opensansb12, LV_PART_MAIN);

    ui_btn_add_ctrl_temperature_fan(ui_btn_fan, -65, "Part", &ui_fan_obj[0]);
    ui_btn_add_ctrl_temperature_fan(ui_btn_fan, 0, "Aux.", &ui_fan_obj[1]);
    ui_btn_add_ctrl_temperature_fan(ui_btn_fan, 65, "Chamber", &ui_fan_obj[2]);

    lv_obj_t * label = NULL;

    ui_btn_speed = ui_btn_create_ctrl_temperature(panel_left, 231, &ui_img_speed_png);
    label_ctrl_speed = lv_label_create(ui_btn_speed);
    lv_label_set_text(label_ctrl_speed, "0");
    lv_obj_set_style_text_font(label_ctrl_speed, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_obj_align(label_ctrl_speed, LV_ALIGN_CENTER, -25, 0);
    label = lv_label_create(ui_btn_speed);
    lv_label_set_text(label, "%");
    lv_obj_align(label, LV_ALIGN_CENTER, 10, 0);

    ui_btn_chamber = ui_btn_create_ctrl_temperature(panel_left, 154, NULL);

    lv_obj_t * icon_chamber = lv_img_create(ui_btn_chamber);
    lv_img_set_src(icon_chamber,&ui_img_temperature_png);
    lv_obj_align(icon_chamber, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_t * icon_humidity = lv_img_create(ui_btn_chamber);
    lv_img_set_src(icon_humidity,&ui_img_humidity_png);
    lv_obj_align(icon_humidity, LV_ALIGN_LEFT_MID, 20, 0);

    label_ctrl_chamber_temper = lv_label_create(ui_btn_chamber);
    lv_label_set_text(label_ctrl_chamber_temper, "0");
    lv_obj_set_style_text_font(label_ctrl_chamber_temper, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_obj_align(label_ctrl_chamber_temper, LV_ALIGN_CENTER, -24, 0);
    lv_obj_set_style_text_align(label_ctrl_chamber_temper,LV_TEXT_ALIGN_RIGHT,0);

    label = lv_label_create(ui_btn_chamber);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_CENTER, 8, 0);

    label = lv_label_create(ui_btn_chamber);
    lv_label_set_text(label, "/");
    lv_obj_align(label, LV_ALIGN_CENTER, 26, 0);
    //lv_obj_set_style_text_align(label,LV_TEXT_ALIGN_CENTER,0);

    label_ctrl_chamber_humidity = lv_label_create(ui_btn_chamber);
    lv_label_set_text(label_ctrl_chamber_humidity, "65");
    lv_obj_set_style_text_font(label_ctrl_chamber_humidity, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_obj_align(label_ctrl_chamber_humidity, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_set_style_text_align(label_ctrl_chamber_humidity,LV_TEXT_ALIGN_RIGHT,0);
    label = lv_label_create(ui_btn_chamber);
    lv_label_set_text(label, "%");
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, -4, 0);
     
    lv_obj_add_event_cb(ui_btn_chamber, btn_chamber_clicked, LV_EVENT_CLICKED, NULL);

    ui_btn_bed = ui_btn_create_ctrl_temperature(panel_left, 77, &ui_img_hotbed_png);
    label_ctrl_bed_temper = lv_label_create(ui_btn_bed);
    lv_label_set_text(label_ctrl_bed_temper, "0");
    lv_obj_set_style_text_font(label_ctrl_bed_temper, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_obj_align(label_ctrl_bed_temper, LV_ALIGN_CENTER, -25, 0);
    label = lv_label_create(ui_btn_bed);
    lv_label_set_text(label, "/"); 
    lv_obj_align(label, LV_ALIGN_CENTER, 10, 0);

    label_ctrl_bed_target_temper = lv_label_create(ui_btn_bed);
    lv_label_set_text(label_ctrl_bed_target_temper, "0");
    lv_obj_align(label_ctrl_bed_target_temper, LV_ALIGN_LEFT_MID, 115, 0);
    label = lv_label_create(ui_btn_bed);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_event_cb(ui_btn_bed, btn_bed_clicked, LV_EVENT_CLICKED, NULL);
    ui_img_bed = lv_obj_get_child(ui_btn_bed, 0);

    ui_btn_nozzle = ui_btn_create_ctrl_temperature(panel_left, 0, &ui_img_nozzle_png);
    label_ctrl_nozzle_temper = lv_label_create(ui_btn_nozzle);
    lv_label_set_text(label_ctrl_nozzle_temper, "0");
    lv_obj_set_style_text_font(label_ctrl_nozzle_temper, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_obj_align(label_ctrl_nozzle_temper, LV_ALIGN_CENTER, -25, 0);
    label = lv_label_create(ui_btn_nozzle);
    lv_label_set_text(label, "/");
    lv_obj_align(label, LV_ALIGN_CENTER, 10, 0);
    label_ctrl_nozzle_target_temper = lv_label_create(ui_btn_nozzle);
    lv_label_set_text(label_ctrl_nozzle_target_temper, "0");
    lv_obj_align(label_ctrl_nozzle_target_temper, LV_ALIGN_LEFT_MID, 115, 0);
    label = lv_label_create(ui_btn_nozzle);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_event_cb(ui_btn_nozzle, btn_nozzle_clicked, LV_EVENT_CLICKED, NULL);
    ui_img_nozzle = lv_obj_get_child(ui_btn_nozzle, 0);
}


static const ui_popup_t popup_printer_move = {
    .text = K_TIP_MOVE_CONFIRM,
    .btn_num = 1,
    .btn_text = {K_BTN_CANCEL},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
};

static void btn_home_clicked(lv_event_t * e) {
    bool is_printing = false;
    
    printer_group_sync_lock(0);
    printer_control_t get_control_type = group_sync_data.control_type;
    printer_group_t *get_leader_group = printer_group_get_leader();
    printer_group_sync_unlock();

    if (PRT_CTL_SINGLE == get_control_type)
    {
        is_printing = bambu_mqtt_in_print_task(bambu_mqtt_master);
    }
    else
    { 
        if (get_leader_group)
        {   
            is_printing = printer_group_is_printing(get_leader_group);
        }
    }
 
    if (is_printing)
    { 
        ui_panel_create_popup(&popup_printer_move, NULL);
        return;
    }

    mqtt_gcode_line("G28\n");
}
 
static void btn_xyz_move_clicked(lv_event_t * e) {
    /*检查是否正在打印中，正在打印提示一下是否要移动轴*/ 
    const char * axis_dis = (const char *)lv_event_get_user_data(e);   
    bool is_printing = false;
    
    printer_group_sync_lock(0);
    printer_control_t get_control_type = group_sync_data.control_type;
    printer_group_t *get_leader_group = printer_group_get_leader();
    printer_group_sync_unlock();

    if (PRT_CTL_SINGLE == get_control_type)
    {
        is_printing = bambu_mqtt_in_print_task(bambu_mqtt_master);
    }
    else
    { 
        if (get_leader_group)
        {   
            is_printing = printer_group_is_printing(get_leader_group);
        }
    }
    
    if (is_printing)
    { 
        ui_panel_create_popup(&popup_printer_move, NULL);
        return;
    }

    char gcode[256];
    sprintf(gcode, "M211 S\nM211 X1 Y1 Z1\nM1002 push_ref_mode\nG91\nG1 %s F9000\nM1002 pop_ref_mode\nM211 R\n", axis_dis);
    mqtt_gcode_line(gcode);
}

typedef struct {
    const lv_img_dsc_t * img;
    const char * axis_dis;
} ui_extrude_t;

static void btn_e_move_clicked(lv_event_t * e) {    
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * img_extruder = (lv_obj_t *)lv_obj_get_user_data(btn);
    lv_img_dsc_t * img = (lv_img_dsc_t *)lv_img_get_src(img_extruder);
    ui_extrude_t * data = (ui_extrude_t *)lv_event_get_user_data(e);
    if (img != data->img) {
        lv_img_set_src(img_extruder, data->img); 
    }

    char gcode[256];
    sprintf(gcode, "M211 S\nM211 X1 Y1 Z1\nM1002 push_ref_mode\nM83\nG1 %s F150\nM1002 pop_ref_mode\nM211 R\n", data->axis_dis);
    mqtt_gcode_line(gcode);
}

/************* move axis x&y ***************/
lv_obj_t * ui_btn_create_ctrl_xy(lv_obj_t * parent,
                                lv_coord_t w, lv_coord_t h, lv_coord_t x_ofs, lv_coord_t y_ofs,
                                const void * img_src,
                                const char * axis_dis) {
    lv_obj_t * btn = lv_imgbtn_create(parent);
    lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, img_src, NULL);
    // lv_obj_set_style_img_recolor(btn, lv_color_hex(LV_32BIT_BTT_RED), LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(btn, 180, LV_STATE_PRESSED);
    lv_obj_set_size(btn, w, h);
    lv_obj_align(btn, LV_ALIGN_CENTER, x_ofs, y_ofs);

    lv_obj_add_event_cb(btn, btn_xyz_move_clicked, LV_EVENT_CLICKED, (void *)axis_dis);

    return btn;
}

lv_obj_t * ui_btn_add_ctrl_xy_label(lv_obj_t * parent, lv_coord_t x_ofs, lv_coord_t y_ofs, const char * text) {
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_size(label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(label, LV_ALIGN_CENTER, x_ofs, y_ofs);
    lv_label_set_text(label, text);

    return label;
}

void ui_panel_add_ctrl_xy(lv_obj_t * parent) {
    lv_obj_t * btn_x_dec_10 = ui_btn_create_ctrl_xy(parent, 84, 218, -95, 0, &ui_img_x_dec_10_png, "X-10");
    lv_obj_t * btn_x_inc_10 = ui_btn_create_ctrl_xy(parent, 84, 218, 137, 0, &ui_img_x_inc_10_png, "X10");
    lv_obj_t * btn_x_dec_1 = ui_btn_create_ctrl_xy(parent, 81, 142, -44, 0, &ui_img_x_dec_1_png, "X-1");
    lv_obj_t * btn_x_inc_1 = ui_btn_create_ctrl_xy(parent, 81, 142, 86, 0, &ui_img_x_inc_1_png, "X1");
    lv_obj_t * btn_y_dec_10 = ui_btn_create_ctrl_xy(parent, 218, 84, 21, 116, &ui_img_y_dec_10_png, "Y-10");
    lv_obj_t * btn_y_inc_10 = ui_btn_create_ctrl_xy(parent, 218, 84, 21, -116, &ui_img_y_inc_10_png, "Y10");
    lv_obj_t * btn_y_dec_1 = ui_btn_create_ctrl_xy(parent, 142, 81, 21, 65, &ui_img_y_dec_1_png, "Y-1");
    lv_obj_t * btn_y_inc_1 = ui_btn_create_ctrl_xy(parent, 142, 81, 21, -65, &ui_img_y_inc_1_png, "Y1");

    lv_obj_t * btn_home = ui_btn_img_create(parent, 65, 65, LV_RADIUS_CIRCLE, lv_color_hex(0x838383), &ui_img_home_png);
    lv_obj_align(btn_home, LV_ALIGN_CENTER, 21, 0);
    lv_obj_add_event_cb(btn_home, btn_home_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * label = ui_btn_add_ctrl_xy_label(btn_x_dec_10, 20, 70, "-10");    
    lv_obj_set_style_transform_angle(label, 450, LV_PART_MAIN);
    ui_btn_add_ctrl_xy_label(btn_x_dec_10, -10, 0, "-X");
    label = ui_btn_add_ctrl_xy_label(btn_x_dec_1, 10, 40, "-1");
    lv_obj_set_style_transform_angle(label, 450, LV_PART_MAIN);
    label = ui_btn_add_ctrl_xy_label(btn_x_inc_1, 0, -35, "+1");
    lv_obj_set_style_transform_angle(label, 450, LV_PART_MAIN);
    label = ui_btn_add_ctrl_xy_label(btn_x_inc_10, 0, -80, "+10");
    lv_obj_set_style_transform_angle(label, 450, LV_PART_MAIN);
    ui_btn_add_ctrl_xy_label(btn_x_inc_10, 10, 0, "X");
    ui_btn_add_ctrl_xy_label(btn_y_dec_10, 0, 10, "-Y");
    ui_btn_add_ctrl_xy_label(btn_y_inc_10, 0, -10, "Y");
}

/************* bed ***************/
lv_obj_t * ui_btn_create_ctrl_bed(lv_obj_t * parent, lv_coord_t y_ofs, lv_color_t bg_c, const void * img_src, const char * text, const char * axis_dis) {
    lv_obj_t * btn = ui_btn_img_create(parent, 65, 85, 0, bg_c, NULL);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, y_ofs);

    lv_obj_t * img = lv_img_create(btn);
    lv_img_set_src(img, img_src);
    lv_obj_align(img, LV_ALIGN_LEFT_MID, 15, 0);

    lv_obj_t * label = lv_label_create(btn);
    lv_obj_set_size(label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 40, 0);
    lv_label_set_text(label, text);

    lv_obj_add_event_cb(btn, btn_xyz_move_clicked, LV_EVENT_CLICKED, (void *)axis_dis);

    return btn;
}

void ui_panel_add_ctrl_bed(lv_obj_t * parent) {
    lv_obj_t * ui_panel_bed = ui_panel_create(parent, 8, lv_color_hex(0x444444));
    lv_obj_set_size(ui_panel_bed, 65, 345);
    lv_obj_align(ui_panel_bed, LV_ALIGN_TOP_MID, 221, 45);
    lv_obj_set_style_clip_corner(ui_panel_bed, true, LV_PART_MAIN);

    lv_obj_t * label = lv_label_create(parent);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 221, 20);
    lv_label_set_text_static(label, "Z"); 

    lv_obj_t * btn_z_inc_10 = ui_btn_create_ctrl_bed(ui_panel_bed, 130, lv_color_hex(0x838383), &ui_img_z_inc_png, "10", "Z10");
    lv_obj_t * btn_z_inc_1 = ui_btn_create_ctrl_bed(ui_panel_bed, 45, lv_color_hex(0x575757), &ui_img_z_inc_png, "1", "Z1");
    lv_obj_t * btn_z_dec_1 = ui_btn_create_ctrl_bed(ui_panel_bed, -45, lv_color_hex(0x575757), &ui_img_z_dec_png, "1", "Z-1");
    lv_obj_t * btn_z_dec_10 = ui_btn_create_ctrl_bed(ui_panel_bed, -130, lv_color_hex(0x838383), &ui_img_z_dec_png, "10", "Z-10");
}

/************* extruder ***************/
lv_obj_t * ui_btn_create_ctrl_e(lv_obj_t * parent, lv_coord_t y_ofs, const void * img_src, const ui_extrude_t * data) {
    lv_obj_t * btn = ui_btn_img_create(parent, 45, 45, 6, lv_color_hex(0x838383), img_src);
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 299, y_ofs);
    
    lv_obj_add_event_cb(btn, btn_e_move_clicked, LV_EVENT_CLICKED, (void *)data);

    return btn;
}

const ui_extrude_t dec_data = {
    .img = &ui_img_retract_png,
    .axis_dis = "E-10",
};
const ui_extrude_t inc_data = {
    .img = &ui_img_extrude_png,
    .axis_dis = "E10",
};

void ui_panel_add_ctrl_e(lv_obj_t * parent) {
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 299, 20);
    
	rs_add_translate_cb(label,S_MLG_KEY_TITLES[0].translate_cb,(void*)S_MLG_KEY_TITLES[0].key,KEY_NUMBER);

    lv_obj_t * img_extruder = lv_img_create(parent);
    lv_img_set_src(img_extruder, &ui_img_extrude_png);
    lv_obj_align(img_extruder, LV_ALIGN_TOP_MID, 299, 115);
    lv_obj_t * btn_e_dec = ui_btn_create_ctrl_e(parent, 45, &ui_img_e_dec_png, &dec_data);
    lv_obj_set_user_data(btn_e_dec, img_extruder);
    lv_obj_t * btn_e_inc = ui_btn_create_ctrl_e(parent, 345, &ui_img_e_inc_png, &inc_data);
    lv_obj_set_user_data(btn_e_inc, img_extruder);
}

lv_obj_t * ui_panel_create_axis(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 8, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 690, 400);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 19);
    // lv_obj_set_style_text_font(panel, &lv_font_montserrat_14, LV_PART_MAIN);
    ui_obj_set_type(panel, UI_TYPE_SCREEN_CTRL_AXIS);
    lv_obj_add_flag(panel, LV_OBJ_FLAG_HIDDEN);

    ui_panel_add_ctrl_temperature(panel);
    ui_panel_add_ctrl_xy(panel);
    ui_panel_add_ctrl_bed(panel);
    ui_panel_add_ctrl_e(panel);
    
    lv_obj_t * panel_speed = ui_panel_create_speed(panel);
    lv_obj_add_flag(panel_speed, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_btn_speed, btn_speed_clicked, LV_EVENT_CLICKED, NULL);    
    lv_obj_set_user_data(ui_btn_speed, panel_speed);

    lv_obj_t * panel_fan = ui_panel_create_axis_fan(panel);
    lv_obj_add_flag(panel_fan, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_btn_fan, btn_fan_clicked, LV_EVENT_CLICKED, NULL);    
    lv_obj_set_user_data(ui_btn_fan, panel_fan);

    return panel;
}

bool heater_is_heating(int32_t current, int32_t target, int32_t range) {
    if (target == 0) return false;
    if (current > target + range) return true;
    if (target > current + range) return true;
    return false;
}

void lv_loop_ctrl_axis(void) {
    static int32_t nozzle_temper = -999;
    if (nozzle_temper != BAMBU_DATA_MASTER.nozzle_temper) {
        nozzle_temper = BAMBU_DATA_MASTER.nozzle_temper;
        lv_label_set_text_fmt(label_ctrl_nozzle_temper, "%ld", nozzle_temper);
    }
    static int32_t bed_temper = -999;
    if (bed_temper != BAMBU_DATA_MASTER.bed_temper) {
        bed_temper = BAMBU_DATA_MASTER.bed_temper;
        lv_label_set_text_fmt(label_ctrl_bed_temper, "%ld", bed_temper);
    }
    static int32_t chamber_temper = -999;
    if (chamber_temper != BAMBU_DATA_MASTER.chamber_temper) 
    {
        chamber_temper = BAMBU_DATA_MASTER.chamber_temper;
        if (chamber_temper == 5)
            lv_label_set_text(label_ctrl_chamber_temper, "N/A");
        else
            lv_label_set_text_fmt(label_ctrl_chamber_temper, "%ld", chamber_temper);
    }

    static int32_t chamber_humidity = -999;
    if (chamber_humidity != BAMBU_DATA_MASTER.chamber_humidity) 
    {
        chamber_humidity = BAMBU_DATA_MASTER.chamber_humidity;
        if (chamber_humidity == 5)
            lv_label_set_text(label_ctrl_chamber_humidity, "N/A");
        else
            lv_label_set_text_fmt(label_ctrl_chamber_humidity, "%ld", chamber_humidity);
    }

    static int32_t nozzle_target_temper = -999;
    if (nozzle_target_temper != BAMBU_DATA_MASTER.nozzle_target_temper) {
        nozzle_target_temper = BAMBU_DATA_MASTER.nozzle_target_temper;
        lv_label_set_text_fmt(label_ctrl_nozzle_target_temper, "%ld", nozzle_target_temper);
    }
    static int32_t bed_target_temper = -999;
    if (bed_target_temper != BAMBU_DATA_MASTER.bed_target_temper) {
        bed_target_temper = BAMBU_DATA_MASTER.bed_target_temper;
        lv_label_set_text_fmt(label_ctrl_bed_target_temper, "%ld", bed_target_temper);
    }

    static bool nozzle_heating = false;
    bool n_heating = heater_is_heating(BAMBU_DATA_MASTER.nozzle_temper, BAMBU_DATA_MASTER.nozzle_target_temper, 2);
    if (nozzle_heating != n_heating) {
        nozzle_heating = n_heating;
        lv_obj_set_style_img_recolor_opa(ui_img_nozzle, nozzle_heating ? 255 : 0, LV_PART_MAIN);
    }
    static bool bed_heating = false;
    bool b_heating = heater_is_heating(BAMBU_DATA_MASTER.bed_temper, BAMBU_DATA_MASTER.bed_target_temper, 2);
    if (bed_heating != b_heating) {
        bed_heating = b_heating;
        lv_obj_set_style_img_recolor_opa(ui_img_bed, bed_heating ? 255 : 0, LV_PART_MAIN);
    }

    static uint8_t fan_speed[3] = {0xff, 0xff, 0xff};
    for (uint8_t i = 0; i < ARRAY_SIZE(fan_speed); i++) {
        if (fan_speed[i] != BAMBU_DATA_MASTER.fan_speed[i]) {
            fan_speed[i] = BAMBU_DATA_MASTER.fan_speed[i];
            lv_label_set_text_fmt(ui_fan_obj[i].btn_label_speed, "%d%%", fan_speed[i]);
            ui_meter_fan_set_value(&ui_fan_obj[i], fan_speed[i]);
            if (fan_speed[i]) {
                lv_obj_set_style_img_recolor_opa(ui_fan_obj[i].btn_img, 255, LV_PART_MAIN);
                lv_obj_set_style_img_recolor_opa(ui_fan_obj[i].img, 255, LV_PART_MAIN);
                lv_obj_add_state(ui_fan_obj[i].sw, LV_STATE_CHECKED);
                lv_label_set_text(ui_fan_obj[i].sw_label, RS_TRANSLATE(K_SW_T_ON));
            } else {
                lv_obj_set_style_img_recolor_opa(ui_fan_obj[i].btn_img, 0, LV_PART_MAIN);
                lv_obj_set_style_img_recolor_opa(ui_fan_obj[i].img, 0, LV_PART_MAIN);
                lv_obj_clear_state(ui_fan_obj[i].sw, LV_STATE_CHECKED);
                lv_label_set_text(ui_fan_obj[i].sw_label, RS_TRANSLATE(K_SW_T_OFF));
            }
        }
    }

    static int32_t spd_mag = -999;
    if (spd_mag != BAMBU_DATA_MASTER.spd_mag) {
        spd_mag = BAMBU_DATA_MASTER.spd_mag;
        lv_label_set_text_fmt(label_ctrl_speed, "%ld", spd_mag);
    }

    static int32_t spd_lvl = -999;
    if (spd_lvl != BAMBU_DATA_MASTER.spd_lvl) {
        spd_lvl = BAMBU_DATA_MASTER.spd_lvl;
        ui_slider_list_sel(ui_panel_slider_speed, spd_lvl);
    }

    // since speed is a slider, and it can be changed very quickly
    // so we set a time cycle to avoid unnecessary blocking of mqtt task
    static uint32_t ms = 0;
    if (send_spd_lvl) {
        if (ms < millis()) {
            ms = millis() + 2000; // 2 sec
            char temp[10];
            snprintf(temp, sizeof(temp), "%ld", send_spd_lvl);
            mqtt_set_spd_lvl(temp);
            send_spd_lvl = 0;
        }
    }
}
