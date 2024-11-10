#include "lv_ui_overlay.h"

#define SW_PRINT_HOME_PRINTING_ONE 0

#if SW_PRINT_HOME_PRINTING_ONE && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "home_printing_one"; 
#define PRINT_HOME_PRINTING_ONE(fmt,args...) ESP_LOGW(TAG,fmt,##args)   
#else
#define PRINT_HOME_PRINTING_ONE(...) 
#endif

static const lv_point_t v_line_points[] = { {0, 0}, {0, 30}};
static const lv_point_t h_line_points[] = { {0, 0}, {240, 0}};

static const lv_img_dsc_t * img_printer_series[] = {
    &ui_img_p1_series_png, &ui_img_p1_series_png, &ui_img_x1_series_png, &ui_img_a1_series_png, &ui_img_a1_series_png, NULL,
};

const lv_img_dsc_t * ui_img_src_get_printer_series(bambu_model_t model) {
    return img_printer_series[model];
}

static const lv_img_dsc_t * img_printer_models[][2] = {
    {&ui_img_p1p_png, &ui_img_p1p_ams_png},
    {&ui_img_p1s_png, &ui_img_p1s_ams_png},
    {&ui_img_x1c_png, &ui_img_x1c_ams_png},
    {&ui_img_a1_mini_png, &ui_img_a1_mini_ams_png},
    {&ui_img_a1_png, &ui_img_a1_ams_png},
    {NULL, NULL},
};

const lv_img_dsc_t * ui_img_src_get_printer_models(bambu_model_t model, bool with_ams) {
    return img_printer_models[model][with_ams];
}

bambu_model_t ui_get_model_from_img(const lv_img_dsc_t * img_src) {
    for (uint8_t i = 0; i < ARRAY_SIZE(img_printer_models); i++) {
        if (img_src == img_printer_models[i][0]
            || img_src == img_printer_models[i][1]) {
            return (bambu_model_t)i;
        }
    }
    return BAMBU_MODEL_UNKNOW;
}
 
lv_obj_t * ui_panel_creat_home_printing_one_screen(lv_obj_t * parent, bambu_mqtt_t * mqtt, uint32_t index) {
    lv_obj_t * panel = ui_panel_create(parent, 0, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 704, 452);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    nvs_config_t * nvs = &mqtt->nvs_config;
    lv_obj_t * panel_model = ui_panel_create(panel, 12, lv_color_hex(0x575757));
    lv_obj_set_size(panel_model, 280, 306);
    lv_obj_align(panel_model, LV_ALIGN_TOP_LEFT, 20, 16);
    lv_obj_set_style_clip_corner(panel_model, true, LV_PART_MAIN);

    lv_obj_t * img_model = lv_img_create(panel_model);
    lv_img_set_src(img_model, &ui_img_icon_model_png); 
    lv_obj_set_align(img_model, LV_ALIGN_CENTER);
    
    lv_obj_t * panel_filename = ui_panel_create(panel_model, 0, lv_color_hex(0x363636));
    lv_obj_set_size(panel_filename, 280, 25);
    lv_obj_set_align(panel_filename, LV_ALIGN_BOTTOM_MID);

    lv_obj_t * filename = lv_label_create(panel_filename);
    lv_obj_set_width(filename, 265);
    lv_label_set_long_mode(filename, LV_LABEL_LONG_CLIP);
    lv_label_set_text_static(filename, "--.3mf");
    lv_obj_align(filename, LV_ALIGN_LEFT_MID, 15, 0);

    
    lv_obj_set_style_text_font(filename,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT); 

    lv_obj_t * panel_status = ui_panel_create(panel, 12, lv_color_hex(0x575757));
    lv_obj_set_size(panel_status, 280, 102);
    lv_obj_align(panel_status, LV_ALIGN_BOTTOM_LEFT, 20, -16);
    lv_obj_set_style_clip_corner(panel_status, true, LV_PART_MAIN);

    lv_obj_t * progress = lv_label_create(panel_status);
    lv_label_set_text_static(progress, "--%");
    lv_obj_align(progress, LV_ALIGN_TOP_LEFT, 20, 10);

    lv_obj_t * bar = lv_bar_create(panel_status);
    lv_obj_set_size(bar, 240, 10);
    lv_obj_align(bar, LV_ALIGN_TOP_MID, 0, 35);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(bar, 188, LV_PART_MAIN);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0x4CD112), LV_PART_INDICATOR);
    lv_bar_set_range(bar, 0, 100);
    lv_bar_set_value(bar, 0, LV_ANIM_OFF);

    lv_obj_t * layer = lv_label_create(panel_status);
    lv_label_set_text_static(layer, "--/--");
    lv_obj_align(layer, LV_ALIGN_TOP_MID, 0, 10);

    lv_obj_t * time = lv_label_create(panel_status);
    lv_label_set_text_static(time, "--m");
    lv_obj_align(time, LV_ALIGN_TOP_RIGHT, -20, 10);

    lv_obj_t * v_line_3 = ui_line_create(panel_status, v_line_points, 2, 1, lv_color_hex(0xFFFFFF));
    lv_obj_align(v_line_3, LV_ALIGN_BOTTOM_MID, 0, -7);
    lv_obj_t * h_line = ui_line_create(panel_status, h_line_points, 2, 1, lv_color_hex(0xFFFFFF));
    lv_obj_align(h_line, LV_ALIGN_BOTTOM_MID, 0, -45);

    lv_obj_t * btn_pause = ui_btn_img_create(panel_status, 125, 35, 5, lv_color_hex(0x575757), NULL);    
    lv_obj_set_flex_flow(btn_pause, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(btn_pause, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(btn_pause, 20, LV_PART_MAIN);
    lv_obj_t * label_pause_symbol = lv_label_create(btn_pause);
    lv_obj_set_style_text_color(label_pause_symbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_align(label_pause_symbol, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(label_pause_symbol,&opensansb16,0);
    lv_label_set_text_static(label_pause_symbol, LV_SYMBOL_PAUSE);
    lv_obj_t * label_pause_text = lv_label_create(btn_pause);
    lv_obj_set_align(label_pause_text, LV_ALIGN_CENTER);
    lv_label_set_text(label_pause_text, RS_TRANSLATE(K_BTN_PAUSE));
    lv_obj_align(btn_pause, LV_ALIGN_BOTTOM_LEFT, 10, -5);
 
    lv_obj_t * btn_stop = ui_btn_img_create(panel_status, 125, 35, 5, lv_color_hex(0x575757), NULL);    
    lv_obj_set_flex_flow(btn_stop, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(btn_stop, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(btn_stop, 20, LV_PART_MAIN);
    lv_obj_t * label_stop_symbol = lv_label_create(btn_stop);
    lv_obj_set_style_text_color(label_stop_symbol, lv_color_hex(0xFF9F09), LV_PART_MAIN);
    lv_obj_set_align(label_stop_symbol, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(label_stop_symbol,&opensansb16,0);
    lv_label_set_text_static(label_stop_symbol, LV_SYMBOL_STOP);
    lv_obj_t * label_stop_text = lv_label_create(btn_stop);
    lv_obj_set_align(label_stop_text, LV_ALIGN_CENTER);
    lv_label_set_text(label_stop_text, RS_TRANSLATE(K_BTN_STOP));
    lv_obj_align(btn_stop, LV_ALIGN_BOTTOM_RIGHT, -10, -5);

    lv_obj_t * panel_tips = ui_panel_create(panel, 12, lv_color_hex(0x575757));
    lv_obj_set_size(panel_tips, 280, 420);
    lv_obj_align(panel_tips, LV_ALIGN_RIGHT_MID, -20, 0);
    
    lv_obj_t * img_printer = lv_img_create(panel_tips);
    lv_img_set_src(img_printer, img_printer_series[nvs->model_num]);  

    if (panda_pwr_is_opened)
    {
        lv_obj_align(img_printer, LV_ALIGN_TOP_MID,0,-20);
        lv_img_set_zoom(img_printer,180); 
    }
    else
    { 
        lv_obj_set_align(img_printer, LV_ALIGN_CENTER);
    } 

    ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_mem_alloc(sizeof(ui_printing_data_t));
    if (!ui_d)
    {
        PRINT_HOME_PRINTING_ONE("malloc printing one ui_d failed");
        return NULL;
    }

    lv_memset_00(ui_d, sizeof(ui_printing_data_t));

    if (panda_pwr_is_opened)
    {
        ui_home_pwr_data_t * ui_d_pwr = (ui_home_pwr_data_t *)lv_mem_alloc(sizeof(ui_home_pwr_data_t));
        if (!ui_d_pwr)
        { 
            PRINT_HOME_PRINTING_ONE("malloc ui_d_pwr failed");
            return NULL;
        }

        lv_memset_00(ui_d_pwr, sizeof(ui_home_pwr_data_t));
        ui_d->pwr_icon = NULL; 
        
        home_reset_pwr_ui_data(ui_d_pwr);

        /*创建PWR相关*/
        lv_obj_t *panel_pwr_data = ui_panel_add_ctrl_pwr_data(panel_tips,ui_d_pwr); 
        lv_obj_align(panel_pwr_data,LV_ALIGN_TOP_MID,0,CONFIG_PWR_PANEL_Y_OFFSET);

        ui_d->home_pwr_data = ui_d_pwr;
    }
    else
    {
        ui_d->home_pwr_data = NULL;
    }

    lv_obj_add_event_cb(btn_pause, btn_printing_pause_clicked, LV_EVENT_CLICKED, ui_d);
    lv_obj_add_event_cb(btn_stop, btn_printing_stop_clicked, LV_EVENT_CLICKED, ui_d);
    
    ui_d->mqtt_status = mqtt->status;
    ui_d->connect_flag = nvs->connect_flag;
    ui_d->index = index;
    ui_d->gcode_state = GCODE_STATE_IDLE;
    ui_d->tips_type = UI_TIPS_TYPE_ICON;
    ui_d->nozzle_temper = -999;
    ui_d->bed_temper = -999;
    ui_d->chamber_temper = -999;
    ui_d->mc_percent = -999;
    ui_d->mc_remaining_time = -999;
    ui_d->layer_num = -999;
    ui_d->total_layer_num = -999;
    ui_d->stg_cur = -999;
    ui_d->paused = false;
    ui_d->nozzle_heating = false;
    ui_d->bed_heating = false;

    // ui_d->mqtt_icon = mqtt_icon;
    ui_d->panel_tips = panel_tips;
    ui_d->img_printer = img_printer;
    ui_d->img_panda = img_model; 
    ui_panel_add_ctrl_btns(panel, -312, ui_d);
    ui_d->panel_status = panel_status;
    ui_d->label_filename = filename;
    ui_d->label_progress = progress;
    ui_d->bar_progress = bar;
    ui_d->label_layer = layer;
    ui_d->label_time = time;
    ui_d->label_pause_resume_symbol = label_pause_symbol;
    ui_d->label_pause_resume_text = label_pause_text;
    ui_d->label_stop_text = label_stop_text;
    ui_d->panel_status_overlay = NULL;
    ui_d->panel_status_overlay_status = NULL;
    ui_d->panel_status_overlay_reprint = NULL;
    lv_obj_set_user_data(panel, ui_d);
 
    return panel;
}