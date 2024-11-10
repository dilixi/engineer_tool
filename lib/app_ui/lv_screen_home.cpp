
#include "utils_lib.h"
#include "ui.h" 
#include "lv_screen_home.h"

#include "stdlib.h"
#include "lv_ui_overlay.h"

#define SW_PRINT_SCREEN_HOME 1

#if SW_PRINT_SCREEN_HOME && SW_PRINT_ALL
//#include "esp_log.h"
static const char * TAG = "screen_home"; 
#define PRINT_SCREEN_HOME(fmt,args...) printf(TAG,fmt,##args)  
#define PRINT_SCREEN_HOMEW(fmt,args...) printf(TAG,fmt,##args)  
#else
#define PRINT_SCREEN_HOME(...)
#define PRINT_SCREEN_HOMEW(...)
#endif

static lv_obj_t * ui_panel_home = NULL;
static lv_obj_t * ui_panel_home_idle = NULL;
static lv_obj_t * ui_panel_home_printing_one = NULL;
static lv_obj_t * ui_panel_home_printing_multi = NULL;
static bambu_mqtt_t * bambu_mqtt_master_last = NULL;

static void ui_panel_status_no_printing(ui_printing_data_t * ui_d, lv_color_t bg_c, MLG_KEY_TYPE text, bambu_data_t * d);
gcode_state_t lv_loop_home_printing_data(ui_printing_data_t * ui_d, bambu_data_t * d, const lv_img_dsc_t *img_src);


const char * symbol_pause = LV_SYMBOL_PAUSE;
const char * symbol_resume = LV_SYMBOL_PLAY;
 
static const ui_popup_t popup_pause = {
    .text = K_TIP_PAUSE_PRINT,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_PAUSE},
    .btn_id = {UI_POPUP_BTN_CANCEL, UI_POPUP_BTN_PAUSE},
    .popup_cb = NULL, // default popop call back funtion
     
};


void btn_printing_pause_clicked(lv_event_t * e) {
    ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_event_get_user_data(e);
    const char * text = lv_label_get_text(ui_d->label_pause_resume_symbol);  
    bambu_mqtt_t * mqtt = bambu_get_mqtt(ui_d->index); 
    if (text == symbol_pause) { 
        ui_panel_create_popup(&popup_pause, mqtt);
    } else {
        mqtt->bambu_data.gcode_state = GCODE_STATE_RUNNING;
        mqtt_one_client_print_ctrl(mqtt, "resume");
    }
}

static const ui_popup_t popup_stop = {
    .text = K_TIP_STOP_PRINT,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_STOP},
    .btn_id = {UI_POPUP_BTN_CANCEL, UI_POPUP_BTN_STOP},
    .popup_cb = NULL, // default popop call back funtion
     
};

static void lv_ui_home_translate_printer(ui_printing_data_t * ui_d)
{ 
    bambu_mqtt_t * mqtt = bambu_get_mqtt(ui_d->index); 
    bambu_data_t * d = &mqtt->bambu_data;

    if (lv_obj_is_valid(ui_d->label_pause_resume_text))
    {
        bool printer_paused = (d->gcode_state == GCODE_STATE_PAUSE);

        if (printer_paused) {  
            lv_label_set_text(ui_d->label_pause_resume_text, RS_TRANSLATE(K_BTN_RESUME));
        } else { 
            lv_label_set_text(ui_d->label_pause_resume_text, RS_TRANSLATE(K_BTN_PAUSE));
        }
    }

    if (lv_obj_is_valid(ui_d->label_stop_text))
    {
        lv_label_set_text(ui_d->label_stop_text, RS_TRANSLATE(K_BTN_STOP));
    }

    if (lv_obj_is_valid(ui_d->panel_status_overlay))
    {
        lv_obj_t *get_text_obj = lv_obj_get_child(ui_d->panel_status_overlay,0);

        switch (d->gcode_state) 
        { 
            case GCODE_STATE_FAILED:
            { 
                if (ui_d->panel_status_overlay_status)
                {
                    lv_label_set_text(ui_d->panel_status_overlay_status,RS_TRANSLATE(K_PRINT_CANCELED)); 
                }
 
                if (ui_d->panel_status_overlay_reprint)
                {
                    lv_label_set_text(ui_d->panel_status_overlay_reprint,RS_TRANSLATE(K_PRINT_REPRINT)); 
                }
            }
            break;

            case GCODE_STATE_FINISH:
            { 
                if (ui_d->panel_status_overlay_status)
                {
                    lv_label_set_text(ui_d->panel_status_overlay_status,RS_TRANSLATE(K_PRINT_FINISHED)); 
                }
 
                if (ui_d->panel_status_overlay_reprint)
                {
                    lv_label_set_text(ui_d->panel_status_overlay_reprint,RS_TRANSLATE(K_PRINT_REPRINT)); 
                }

                //lv_label_set_text(get_text_obj,RS_TRANSLATE(K_FILE_S_PRINTING)); 
            }
            break;

            default:
                break;
        }
    }

    ui_d->tips_type = UI_TIPS_TYPE_REFRESH;

    ui_d->need_translate = true;
} 

void btn_printing_stop_clicked(lv_event_t * e) {
    ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_event_get_user_data(e); 
    bambu_mqtt_t * mqtt = bambu_get_mqtt(ui_d->index);     
    ui_panel_create_popup(&popup_stop, mqtt);
}

const char * remaining_time_to_string(char * buf, uint32_t max_len, int32_t mc_remaining_time) {
    if (mc_remaining_time < 60)
        snprintf(buf, max_len, "-%ldm", mc_remaining_time);
    else if (mc_remaining_time < 60 * 24)
        snprintf(buf, max_len, "-%ldh%ldm", mc_remaining_time / 60, mc_remaining_time % 60);
    else
        snprintf(buf, max_len, "-%ldd%ldh%ldm", mc_remaining_time / 60 / 24, (mc_remaining_time / 60) % 24, mc_remaining_time % 60);
    return buf;
}

void btn_led_clicked(lv_event_t * e) {

    BAMBU_DATA_MASTER.chamber_light = !BAMBU_DATA_MASTER.chamber_light;
    mqtt_ledctrl(BAMBU_DATA_MASTER.chamber_light ? "on" : "off");
    
}

void btn_home_ctrl_clicked(lv_event_t * e) {
    ui_type_t type = (ui_type_t)(pointer_type)lv_event_get_user_data(e);
    ui_screen_select(type);
}

void btn_home_pwr_panel_ctrl_clicked(lv_event_t * e) { 
    ui_screen_select(UI_TYPE_SCREEN_CTRL_POWER);
}

lv_obj_t * ui_btn_create_home_ctrl(lv_obj_t * parent, lv_coord_t y_ofs, const void * img_src) {
    lv_obj_t * btn = ui_btn_img_create(parent, 80, 87, 12, lv_color_hex(0x575757), NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 0, y_ofs);
    lv_obj_set_style_border_color(btn, lv_color_hex(0x929292), LV_PART_MAIN);
    lv_obj_set_style_border_opa(btn, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(btn, 1, LV_PART_MAIN);
    lv_obj_set_style_border_side(btn, LV_BORDER_SIDE_TOP, LV_PART_MAIN);
    if (img_src) {
        lv_obj_t * img = lv_img_create(btn);
        lv_img_set_src(img, img_src);
        lv_obj_align(img, LV_ALIGN_TOP_MID, 0, 10);
        lv_obj_set_style_img_recolor(img, lv_color_hex(0xFF9F09), LV_PART_MAIN);
        lv_obj_set_style_img_recolor_opa(img, 0, LV_PART_MAIN);
    }

    lv_obj_add_event_cb(btn, btn_home_ctrl_clicked, LV_EVENT_CLICKED, (void *)UI_TYPE_SCREEN_CTRL_AXIS);

    return btn;
}

lv_obj_t * ui_btn_create_home_pwr_ctrl(lv_obj_t * parent, lv_coord_t y_ofs, const void * img_src, lv_event_cb_t event_cb) {
    lv_obj_t * btn = ui_btn_img_create(parent, 80, 87, 12, lv_color_hex(0x575757), NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 0, y_ofs);
    lv_obj_set_style_border_color(btn, lv_color_hex(0x929292), LV_PART_MAIN);
    lv_obj_set_style_border_opa(btn, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(btn, 1, LV_PART_MAIN);
    lv_obj_set_style_border_side(btn, LV_BORDER_SIDE_TOP, LV_PART_MAIN);
    if (img_src) {
        lv_obj_t * img = lv_img_create(btn);
        lv_img_set_src(img, img_src);
        lv_obj_align(img, LV_ALIGN_TOP_MID, 0, 10);
        lv_obj_set_style_img_recolor(img, lv_color_hex(0xFF9F09), LV_PART_MAIN);
        lv_obj_set_style_img_recolor_opa(img, 0, LV_PART_MAIN);
    }

    if (NULL == event_cb)
    {
        lv_obj_add_event_cb(btn, btn_home_ctrl_clicked, LV_EVENT_CLICKED, (void *)UI_TYPE_SCREEN_CTRL_POWER);
    } 
    else
    {
        lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);
    }

    return btn;
}

void ui_panel_add_ctrl_btns(lv_obj_t * parent, lv_coord_t x_ofs, ui_printing_data_t * ui_d) {
    lv_obj_t * btn_led = ui_btn_img_create(parent, 80, 65, 12, lv_color_hex(0x929292), &ui_img_led_off_png);
    lv_obj_align(btn_led, LV_ALIGN_TOP_RIGHT, x_ofs, 16);
    lv_obj_set_style_bg_img_recolor(btn_led, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_bg_img_recolor_opa(btn_led, 0, LV_PART_MAIN);
    lv_obj_add_event_cb(btn_led, btn_led_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * panel_btn = ui_panel_create(parent, 12, lv_color_hex(0x575757));
    lv_obj_set_size(panel_btn, 80, 347);
    lv_obj_align(panel_btn, LV_ALIGN_BOTTOM_RIGHT, x_ofs, -16);
    lv_obj_set_style_clip_corner(panel_btn, true, LV_PART_MAIN);

    lv_obj_t * btn_wifi = ui_btn_img_create(panel_btn, 80, 86, 12, lv_color_hex(0x575757), &ui_img_wifi_png);
    lv_obj_add_event_cb(btn_wifi, btn_home_ctrl_clicked, LV_EVENT_CLICKED, (void *)UI_TYPE_SCREEN_SETTING_NETWORK);
    lv_obj_align(btn_wifi, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t * btn_nozzle = ui_btn_create_home_ctrl(panel_btn, 86, &ui_img_nozzle_png);
    lv_obj_t * nozzle = lv_label_create(btn_nozzle);
    lv_label_set_text(nozzle, "--");
    lv_obj_align(nozzle, LV_ALIGN_BOTTOM_MID, -8, -5);
    lv_obj_set_style_text_font(nozzle, &opensansb20, LV_PART_MAIN);
    lv_obj_t * label = lv_label_create(btn_nozzle);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_BOTTOM_RIGHT, -5, -5);
    lv_obj_set_style_text_font(label, LV_FONT_DEFAULT, LV_PART_MAIN);

    lv_obj_t * btn_bed = ui_btn_create_home_ctrl(panel_btn, 173, &ui_img_hotbed_png);
    lv_obj_t * bed = lv_label_create(btn_bed);
    lv_label_set_text(bed, "--");
    lv_obj_align(bed, LV_ALIGN_BOTTOM_MID, -8, -5);
    lv_obj_set_style_text_font(bed, &opensansb20, LV_PART_MAIN);
    label = lv_label_create(btn_bed);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_BOTTOM_RIGHT, -5, -5);
    lv_obj_set_style_text_font(label, LV_FONT_DEFAULT, LV_PART_MAIN);

    lv_obj_t * btn_chamber = ui_btn_create_home_ctrl(panel_btn, 260, NULL); 
    lv_obj_t * icon_chamber = lv_img_create(btn_chamber);
    lv_img_set_src(icon_chamber,&ui_img_temperature_png);
    lv_obj_align(icon_chamber, LV_ALIGN_TOP_LEFT, -5, 8);

    lv_obj_t * label_chamber_temp = lv_label_create(btn_chamber);
    lv_label_set_text(label_chamber_temp, "190");
    lv_obj_align(label_chamber_temp, LV_ALIGN_TOP_RIGHT, -20, 12);
    lv_obj_set_style_text_font(label_chamber_temp, &opensansb20, LV_PART_MAIN); 
    lv_obj_set_style_text_align(label_chamber_temp, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_width(label_chamber_temp,40); 

    label = lv_label_create(btn_chamber);
    lv_label_set_text(label, "℃");
    lv_obj_align(label, LV_ALIGN_TOP_RIGHT, -2, 16); 

    lv_obj_t * icon_humidity = lv_img_create(btn_chamber);
    lv_img_set_src(icon_humidity,&ui_img_humidity_png);
    lv_obj_align(icon_humidity, LV_ALIGN_BOTTOM_LEFT, -5, -8);

    lv_obj_t * label_chamber_humidity = lv_label_create(btn_chamber);
    lv_label_set_text(label_chamber_humidity, "123");
    lv_obj_align(label_chamber_humidity, LV_ALIGN_BOTTOM_RIGHT, -20, -10);
    lv_obj_set_style_text_font(label_chamber_humidity, &opensansb20, LV_PART_MAIN); 
    lv_obj_set_style_text_align(label_chamber_humidity, LV_TEXT_ALIGN_CENTER, 0); 
    lv_obj_set_width(label_chamber_humidity,40);

    label = lv_label_create(btn_chamber);
    lv_label_set_text(label, "%");
    lv_obj_align(label, LV_ALIGN_BOTTOM_RIGHT, -4, -10); 

    ui_d->btn_led = btn_led;
    ui_d->label_nozzle = nozzle;
    ui_d->label_bed = bed;
    ui_d->label_chamber_temp = label_chamber_temp;
    ui_d->label_chamber_humidity = label_chamber_humidity;
    ui_d->img_nozzle = lv_obj_get_child(btn_nozzle, 0);
    ui_d->img_bed = lv_obj_get_child(btn_bed, 0);
}

enum {
    UI_BTN_SELECT_CANCEL=0xE0,
    UI_BTN_SELECT_CONFIRM,
}; 

static void s_btn_power_off_clicked(lv_event_t * e)
{ 
    lv_obj_t *checkbox = lv_event_get_target(e);
 
    if (lv_obj_has_state(checkbox,LV_STATE_CHECKED))
    {
        lv_obj_clear_state(checkbox,LV_STATE_CHECKED); 
    }
    else
    {
        lv_obj_add_state(checkbox,LV_STATE_CHECKED);
    }

    btn_power_off_clicked(e);
} 

#if 0
static void btn_usb_ctl_clicked(lv_event_t * e)
{
    /*如果PWR不在线则不处理*/
    bool pwr_is_online = bambu_mqtt_master->pwr_data.is_online;
    if (!pwr_is_online)
    {
        return;
    }

    lv_obj_t *checkbox = lv_event_get_target(e);
 
    if (checkbox)
    {
        if (lv_obj_has_state(checkbox,LV_STATE_CHECKED))
        {  
            panda_pwr_set_switch(bambu_mqtt_master,SW_USB,SW_OFF);
        }
        else
        {  
            panda_pwr_set_switch(bambu_mqtt_master,SW_USB,SW_ON);
        }

        delay_tick_config=xTaskGetTickCount();  
    }
}


static void popup_reset_power_usage_clicked(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt) 
{ 
    switch (btn_id) {
        case UI_BTN_SELECT_CONFIRM: 
        {  
            panda_pwr_reset_power_usage(mqtt);
        
            break;
        } 
        default:
            break;
    }  
}

static const ui_popup_t popup_confirm_reset_power_usage = {
    .text = K_TIP_CONFIRM_RESET_POWER_USAGE,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_CONFIRM},
    .btn_id = {UI_BTN_SELECT_CANCEL, UI_BTN_SELECT_CONFIRM},
    .popup_cb = popup_reset_power_usage_clicked, 
};  

static void btn_reset_pwr_usage_clicked(lv_event_t * e)
{ 
    bool pwr_is_online = bambu_mqtt_master->pwr_data.is_online;
    if (!pwr_is_online)
    {
        return;
    }

    ui_panel_create_popup(&popup_confirm_reset_power_usage, bambu_mqtt_master); 
}
#endif

void ui_panel_add_ctrl_btns_pwr(lv_obj_t * parent, lv_coord_t x_ofs, ui_home_pwr_data_t * ui_d)
{
    ui_d->btn_power = ui_btn_img_create(parent, 80, 65, 12, lv_color_hex(0x929292), &ui_img_power_ctl_big_png);
    lv_obj_align(ui_d->btn_power, LV_ALIGN_TOP_RIGHT, x_ofs, 16);

    lv_obj_set_style_bg_color(ui_d->btn_power,lv_color_hex(0x929292),LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_img_recolor(ui_d->btn_power, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_img_recolor(ui_d->btn_power, lv_color_hex(0x4CD112), LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_img_recolor_opa(ui_d->btn_power, 255, LV_PART_MAIN);
    lv_obj_set_style_bg_img_recolor_opa(ui_d->btn_power, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_add_event_cb(ui_d->btn_power, s_btn_power_off_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * panel_btn = ui_panel_create(parent, 12, lv_color_hex(0x575757));
    lv_obj_set_size(panel_btn, 80, 347);
    lv_obj_align(panel_btn, LV_ALIGN_BOTTOM_RIGHT, x_ofs, -16);
    lv_obj_set_style_clip_corner(panel_btn, true, LV_PART_MAIN);

    ui_d->btn_usb = ui_btn_img_create(panel_btn, 80, 86, 12, lv_color_hex(0x575757), &ui_img_usb_on_png);
    lv_obj_align(ui_d->btn_usb, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_bg_color(ui_d->btn_usb,lv_color_hex(0x575757),LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_img_src(ui_d->btn_usb, &ui_img_usb_off_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_d->btn_usb, &ui_img_usb_on_png, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_add_event_cb(ui_d->btn_usb, btn_usb_ctl_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * btn_power_value = ui_btn_create_home_pwr_ctrl(panel_btn, 86, &ui_img_power_png,NULL);
    ui_d->label_power = lv_label_create(btn_power_value);
    lv_label_set_text(ui_d->label_power, "----");
    lv_obj_align(ui_d->label_power, LV_ALIGN_BOTTOM_MID, 0, -5); 

    lv_obj_t * btn_power_usage = ui_btn_create_home_pwr_ctrl(panel_btn, 173, &ui_img_ele_used_png,NULL);
    ui_d->label_power_usage = lv_label_create(btn_power_usage);
    lv_label_set_text(ui_d->label_power_usage, "----");
    lv_obj_align(ui_d->label_power_usage, LV_ALIGN_BOTTOM_MID, 0, -3); 

    #if 1
    ui_d->btn_reset_pwr_usage = ui_btn_create_home_pwr_ctrl(panel_btn, 260, &ui_img_reset_pwr_usage_png,btn_reset_pwr_usage_clicked);
    lv_obj_set_style_bg_color(ui_d->btn_reset_pwr_usage,lv_color_hex(0x575757),LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t *get_btn_img = lv_obj_get_child(ui_d->btn_reset_pwr_usage,0);
    if (get_btn_img)
    {
        lv_obj_align(get_btn_img, LV_ALIGN_CENTER, 0, 0);
    }
    #else
    ui_d->btn_usb = ui_btn_img_create(panel_btn, 80, 86, 12, lv_color_hex(0x575757), &ui_img_usb_on_png);
    lv_obj_align(ui_d->btn_usb, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_bg_color(ui_d->btn_usb,lv_color_hex(0x575757),LV_PART_MAIN | LV_STATE_CHECKED);
    #endif 
}

static void s_btn_auto_power_off_clicked(lv_event_t * e)
{
    delay_tick_config=xTaskGetTickCount();  
    btn_auto_power_off_clicked(e); 
}

lv_obj_t * ui_panel_add_ctrl_pwr_data(lv_obj_t * parent, ui_home_pwr_data_t * ui_d)
{  
    return NULL;
}

static void pwr_usb_follow_printer_light(sw_state_t *sw, bambu_data_t *bambu_data)
{
    if ((!sw) || (!bambu_data))
    {
        return;
    }

    if (bambu_data->chamber_light_last != bambu_data->chamber_light)
    { 
        if (sw->usb_follow)
        {
            if (sw->usb != bambu_data->chamber_light)
            { 
                sw->usb = bambu_data->chamber_light;
 
                printer_group_sync_lock(0);
                printer_control_t get_control_type = group_sync_data.control_type;  
                printer_group_sync_unlock();  
                if (PRT_CTL_GROUP == get_control_type)
                {      
                    panda_pwr_group_set_switch(SW_USB,sw->usb);
                }
                else  
                {
                    panda_pwr_set_switch(bambu_mqtt_master,SW_USB,sw->usb);
                }   
            }
        }

        bambu_data->chamber_light_last = bambu_data->chamber_light;
    } 
}

void home_reset_pwr_ui_data(ui_home_pwr_data_t *pwr_data)
{
    memset(&pwr_data->sw_state,0,sizeof(sw_state_t));

    /*设置一些特殊值，便于刷新最新的显示*/  
    pwr_data->source_data.voltage=1.001;
    pwr_data->source_data.current=1.001;
    pwr_data->source_data.power=1.001;
    pwr_data->source_data.ele=100.001; 

    pwr_data->sw_state.power=0xff; 
    pwr_data->sw_state.auto_power_off=0xff; 
    pwr_data->sw_state.countdown=0xff; 
    pwr_data->sw_state.usb=0xff; 
    pwr_data->sw_state.usb_follow=0xff; 
}

static void ui_prepre_set_index(ui_printing_data_t * ui_d, uint8_t sel) {
    lv_obj_t * parent = ui_d->panel_tips;
    for (uint8_t i = 0; i < 3; i++) {
        lv_obj_t * panle_index = ui_obj_get(parent, (ui_type_t)(UI_TYPE_TIPS_INDEX_0 + i));
        lv_obj_t * index = ui_obj_get(panle_index, UI_TYPE_INDEX_LABEL);
        lv_obj_t * label = ui_obj_get(parent, (ui_type_t)(UI_TYPE_TIPS_LABEL_0 + i));
        
        if (i < sel){
            lv_label_set_text(index, LV_SYMBOL_OK);
        } else {       
            char buf[10];         
            snprintf(buf, sizeof(buf), "%d", i + 1);
            lv_label_set_text(index, buf);
        }
        lv_obj_set_style_text_color(label, lv_color_hex((i == sel) ? LV_32BIT_BTT_RED : 0xFFFFFF), LV_PART_MAIN);
    }
}

static lv_obj_t * ui_panel_add_prepare_label(lv_obj_t * parent, lv_coord_t y_ofs, uint8_t index, const char * text) {
    lv_obj_t * panel_index = ui_panel_create_index(parent, index, 20, lv_color_hex(LV_32BIT_BTT_RED));
    lv_obj_align(panel_index, LV_ALIGN_TOP_LEFT, 20, y_ofs);
    ui_obj_set_type(panel_index, (ui_type_t)(UI_TYPE_TIPS_INDEX_0 + index));

    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_size(label, 175, LV_SIZE_CONTENT);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 50, y_ofs);
    lv_label_set_text(label, text);
    ui_obj_set_type(label, (ui_type_t)(UI_TYPE_TIPS_LABEL_0 + index));

    return label;
}

static void ui_panel_printing_goto_prepare(ui_printing_data_t * ui_d) {
    if (ui_d->tips_type == UI_TIPS_TYPE_PREPARE) return;
    ui_d->tips_type = UI_TIPS_TYPE_PREPARE;
    lv_obj_t * parent = ui_d->panel_tips;
    lv_obj_clean(parent);
    ui_d->img_printer = NULL;

    /* must be static not const*/
    static lv_point_t v_line_points[] = { {0, 0}, {0, 100}};
    lv_obj_t * v_line = ui_line_create(parent, v_line_points, 2, 2, lv_color_hex(LV_32BIT_BTT_RED));
    lv_obj_align(v_line, LV_ALIGN_TOP_LEFT, 30, 50);
 
    lv_obj_t* add_bed_preheating = ui_panel_add_prepare_label(parent, 50, 0, RS_TRANSLATE(K_BED_PREHEATING));
    rs_add_translate_cb(add_bed_preheating,RS_TRANSLATE_DEFAULT_CB,(void *)K_BED_PREHEATING,KEY_NUMBER);
    lv_obj_t* add_nozzle_clean = ui_panel_add_prepare_label(parent, 100, 1, RS_TRANSLATE(K_NOZZLE_CLEAN));
    rs_add_translate_cb(add_nozzle_clean,RS_TRANSLATE_DEFAULT_CB,(void *)K_NOZZLE_CLEAN,KEY_NUMBER);
    lv_obj_t* add_auto_leveing = ui_panel_add_prepare_label(parent, 150, 2, RS_TRANSLATE(K_BED_AUTO_LEVEING));
    rs_add_translate_cb(add_auto_leveing,RS_TRANSLATE_DEFAULT_CB,(void *)K_BED_AUTO_LEVEING,KEY_NUMBER);

    lv_obj_t * label_title = lv_label_create(parent);
    lv_label_set_text(label_title,RS_TRANSLATE(K_PRINT_PREPARING));
    rs_add_translate_cb(label_title,RS_TRANSLATE_DEFAULT_CB,(void *)K_PRINT_PREPARING,KEY_NUMBER);
    lv_obj_set_style_text_color(label_title, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, 10, 10);
    // lv_obj_set_style_text_font(label_title, &lv_font_montserrat_20, LV_PART_MAIN);

    /* must be static not const*/
    const int32_t w = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    static lv_point_t h_line_points[] = { {0, 0}, {(lv_coord_t)(w - 20), 0}};
    lv_obj_t * h_line = ui_line_create(parent, h_line_points, 2, 1, lv_color_hex(LV_32BIT_BTT_RED));
    lv_obj_align(h_line, LV_ALIGN_TOP_LEFT, 10, 35);

    //PRINT_SCREEN_HOMEW("ui_panel_printing_goto_prepare ui_panel_home_printing_one=[%x]",(unsigned int)ui_panel_home_printing_one);

    if (ui_panel_home_printing_one)
    { 
        if (ui_d->home_pwr_data)
        { 
            lv_memset_00(ui_d->home_pwr_data, sizeof(ui_home_pwr_data_t)); 
            home_reset_pwr_ui_data(ui_d->home_pwr_data);

            //lv_obj_t *panel_pwr_data = ui_panel_add_ctrl_pwr_data(ui_d->panel_tips,ui_d->home_pwr_data);
            //lv_obj_align(panel_pwr_data,LV_ALIGN_TOP_MID,0,CONFIG_PWR_PANEL_Y_OFFSET);
        }
    }
}

static void ui_panel_printing_goto_icon(ui_printing_data_t * ui_d, const lv_img_dsc_t * img_src) 
{  
    if (ui_d->tips_type == UI_TIPS_TYPE_ICON) return;
    ui_d->tips_type = UI_TIPS_TYPE_ICON;
    lv_obj_clean(ui_d->panel_tips);
    ui_d->img_printer = lv_img_create(ui_d->panel_tips); 
    lv_img_set_src(ui_d->img_printer, img_src);

    //PRINT_SCREEN_HOMEW("ui_panel_printing_goto_icon ui_panel_home_printing_one=[%x]",(unsigned int)ui_panel_home_printing_one);

    if (ui_panel_home_printing_one)
    {
        lv_obj_align(ui_d->img_printer, LV_ALIGN_TOP_MID,0,-20);
        lv_img_set_zoom(ui_d->img_printer,180); 

        if (ui_d->home_pwr_data)
        { 
            lv_memset_00(ui_d->home_pwr_data, sizeof(ui_home_pwr_data_t)); 
            home_reset_pwr_ui_data(ui_d->home_pwr_data);

            //lv_obj_t *panel_pwr_data = ui_panel_add_ctrl_pwr_data(ui_d->panel_tips,ui_d->home_pwr_data); 
            //lv_obj_align(panel_pwr_data,LV_ALIGN_TOP_MID,0,CONFIG_PWR_PANEL_Y_OFFSET);
        }
    }
    else
    {
        lv_obj_set_align(ui_d->img_printer, LV_ALIGN_CENTER);
    }
}

static void panel_clear_clicked_cancel(lv_event_t * e) {
    bambu_data_t * d = (bambu_data_t *)lv_event_get_user_data(e);
    mqtt_bambu_data_reprint_reset(d);
    // set to "GCODE_STATE_IDLE", this printer progress will be deleted in loop
    d->gcode_state = GCODE_STATE_IDLE;
    d->gcode_state_idle = GCODE_STATE_CANCEL_IDLE;
}

static void panel_clear_clicked_finish(lv_event_t * e) {
    bambu_data_t * d = (bambu_data_t *)lv_event_get_user_data(e);
    mqtt_bambu_data_reprint_reset(d);
    // set to "GCODE_STATE_IDLE", this printer progress will be deleted in loop
    d->gcode_state = GCODE_STATE_IDLE;
    d->gcode_state_idle = GCODE_STATE_FINISH_IDLE;
}
void reprint_popup_clicked(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt) {
    ui_printing_data_t * ui_d = (ui_printing_data_t *)cb_data;  
    bambu_mqtt_t * mqtt_print = bambu_get_mqtt(ui_d->index); 
    bambu_data_t *d = &mqtt_print->bambu_data;
    print_continue_check_t reprint_check={0};
  
    switch (btn_id) {
        case UI_POPUP_BTN_REPRINT:  
            /*需要知道上一次的打印配置和文件名*/
            mqtt_bambu_data_reprint_get(d, &reprint_check); 
            if (!reprint_check.path[0])
            {
                reprint_check.path[0]='/';
                reprint_check.path[1]='\0';
            }

            mqtt_one_client_print_project_file_local(mqtt_print, reprint_check.path, reprint_check.gcode_file,
                                                reprint_check.bed_leveling,
                                                reprint_check.flow_cali,
                                                reprint_check.timelapse,
                                                reprint_check.use_ams,
                                                reprint_check.clear_power_usage,
                                                reprint_check.auto_power_off
                                                );
            d->gcode_state = GCODE_STATE_PREPARE;
            break;
        default:
            break;
    }
} 

ui_popup_t popup_remind_reprint= {
    .text = K_TIP_REPRINT_GROUP_PRINTER,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_CONFIRM},
    .btn_id = {UI_POPUP_BTN_CANCEL, UI_POPUP_BTN_REPRINT},
    .popup_cb = reprint_popup_clicked,
};

static void panel_reprint_clicked(lv_event_t * e) {
    ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_event_get_user_data(e);
    /*弹窗提醒*/ 
    printer_group_sync_lock(0);
    printer_control_t get_control_type = group_sync_data.control_type;
    printer_group_sync_unlock(); 

    popup_remind_reprint.cb_data=ui_d;

    if (PRT_CTL_GROUP == get_control_type)
    {
        popup_remind_reprint.text = K_TIP_REPRINT_GROUP_PRINTER;
        
        ui_panel_create_popup(&popup_remind_reprint, NULL);
    }
    else
    {
        popup_remind_reprint.text = K_TIP_REPRINT_PRINTER;

        ui_panel_create_popup(&popup_remind_reprint, NULL);
    }
}

static void ui_panel_status_no_printing(ui_printing_data_t * ui_d, lv_color_t bg_c, MLG_KEY_TYPE text, bambu_data_t * d) {
    lv_obj_t * parent = ui_d->panel_status;
    const int32_t w = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    const int32_t h = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_HEIGHT).num;

    if (K_PRINT_CANCELED == text)
    {
        const int32_t bar_y = lv_obj_get_style_prop(ui_d->bar_progress, LV_PART_MAIN, LV_STYLE_Y).num;
        lv_obj_t * btn_status = ui_btn_label_create(parent, w, h - bar_y, 0, bg_c, RS_TRANSLATE(text));
        lv_obj_set_align(btn_status, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_style_text_font(btn_status, LV_FONT_DEFAULT_24, LV_PART_MAIN);
        lv_obj_add_event_cb(btn_status, panel_clear_clicked_cancel, LV_EVENT_CLICKED, d);
        ui_d->panel_status_overlay = btn_status;
        ui_d->panel_status_overlay_status = lv_obj_get_child(btn_status,0);
        ui_d->panel_status_overlay_reprint = NULL;
    }
    else if (K_PRINT_FINISHED == text)
    {
        /*如果当前的是Panda touch 发起的打印才支持继续打印*/
        #if 0
        if (d->is_print_by_panda_touch)
        {
            /*这个时候才创建继续打印按钮*/
            lv_obj_t * panel = ui_panel_create(parent, 12, lv_color_hex(LV_32BIT_BTT_BLUE));  
            lv_obj_set_size(panel,w,h);
            lv_obj_set_style_bg_opa(panel,LV_OPA_TRANSP,LV_STATE_DEFAULT);  
            lv_obj_t * btn_status = ui_btn_label_create(panel, 90, 32, 5, lv_color_hex(LV_32BIT_COLOR_STATUS), RS_TRANSLATE(text));  
            lv_obj_align(btn_status, LV_ALIGN_BOTTOM_LEFT, 28, -4);
            lv_obj_t * btn_reprint = ui_btn_label_create(panel, 90, 32, 5, lv_color_hex(LV_32BIT_COLOR_REPRINT), RS_TRANSLATE(K_PRINT_REPRINT)); 
            lv_obj_align(btn_reprint, LV_ALIGN_BOTTOM_RIGHT, -28, -4); 
            lv_obj_add_event_cb(btn_status, panel_clear_clicked_finish, LV_EVENT_CLICKED, d);
            lv_obj_add_event_cb(btn_reprint, panel_reprint_clicked, LV_EVENT_CLICKED, ui_d);
            ui_d->panel_status_overlay = panel;
            ui_d->panel_status_overlay_status = lv_obj_get_child(btn_status,0);
            ui_d->panel_status_overlay_reprint = lv_obj_get_child(btn_reprint,0);
        }
        else
        {
            const int32_t bar_y = lv_obj_get_style_prop(ui_d->bar_progress, LV_PART_MAIN, LV_STYLE_Y).num;
            lv_obj_t * btn_status = ui_btn_label_create(parent, w, h - bar_y, 0, bg_c, RS_TRANSLATE(text));
            lv_obj_set_align(btn_status, LV_ALIGN_BOTTOM_MID);
            lv_obj_set_style_text_font(btn_status, LV_FONT_DEFAULT_24, LV_PART_MAIN);
            lv_obj_add_event_cb(btn_status, panel_clear_clicked_finish, LV_EVENT_CLICKED, d);
            ui_d->panel_status_overlay = btn_status;
            ui_d->panel_status_overlay_status = lv_obj_get_child(btn_status,0);
            ui_d->panel_status_overlay_reprint = NULL;
        }
        #endif
    }
}

extern bool heater_is_heating(int32_t current, int32_t target, int32_t range);
void lv_loop_home_temperatures(ui_printing_data_t * ui_d, bambu_data_t * d) {
    if (ui_d->btn_led) {
        if (ui_d->chamber_light != d->chamber_light) {
            ui_d->chamber_light = d->chamber_light;
            if (ui_d->chamber_light) {
                lv_obj_set_style_bg_img_src(ui_d->btn_led, &ui_img_led_on_png, LV_PART_MAIN);
                lv_obj_set_style_bg_img_recolor_opa(ui_d->btn_led, 255, LV_PART_MAIN);
            } else {
                lv_obj_set_style_bg_img_src(ui_d->btn_led, &ui_img_led_off_png, LV_PART_MAIN);
                lv_obj_set_style_bg_img_recolor_opa(ui_d->btn_led, 0, LV_PART_MAIN);
            } 
        }
    }
    if (ui_d->nozzle_temper != d->nozzle_temper) {
        ui_d->nozzle_temper = d->nozzle_temper;
        lv_label_set_text_fmt(ui_d->label_nozzle, "%ld", ui_d->nozzle_temper);
    }
    if (ui_d->bed_temper != d->bed_temper) {
        ui_d->bed_temper = d->bed_temper;
        lv_label_set_text_fmt(ui_d->label_bed, "%ld", ui_d->bed_temper);
    }
    #if 0
    if (ui_d->chamber_temper != d->chamber_temper) 
    {
        ui_d->chamber_temper = d->chamber_temper;

        bool temper_is_valid = true;

        // if (ui_d->chamber_temper == 5)
        // {
        //     if (!g_aht20_data.is_valid)
        //     {
        //         temper_is_valid=false;
        //     } 
        // } 
        
        if (!temper_is_valid)
        { 
            /*如果传感器有效则显示传感器数值*/
            lv_label_set_text(ui_d->label_chamber_temp, "N/A");
        }
        else
        {
            #if 1
            lv_label_set_text_fmt(ui_d->label_chamber_temp, "%ld", ui_d->chamber_temper);
            #else
            lv_label_set_text_fmt(ui_d->label_chamber_temp, "%ld", (int32_t)101);
            #endif
        }   
    }
    #else
    lv_label_set_text(ui_d->label_chamber_temp, "N/A");
    #endif
    #if 0
    if (ui_d->label_chamber_humidity)
    {
        if (ui_d->chamber_humidity != d->chamber_humidity) 
        {
            ui_d->chamber_humidity = d->chamber_humidity;
    
            if (!g_aht20_data.is_valid)
            { 
                lv_label_set_text(ui_d->label_chamber_humidity, "N/A");
            }
            else
            { 
                #if 1
                lv_label_set_text_fmt(ui_d->label_chamber_humidity, "%ld", ui_d->chamber_humidity);
                #else
                lv_label_set_text_fmt(ui_d->label_chamber_humidity, "%ld", (int32_t)123);
                #endif
            }   
        } 
    }
    #else
    lv_label_set_text(ui_d->label_chamber_humidity, "N/A");
    #endif

    // bool n_heating = heater_is_heating(d->nozzle_temper, d->nozzle_target_temper, 2);
    // if (ui_d->nozzle_heating != n_heating) {
    //     ui_d->nozzle_heating = n_heating;
    //     lv_obj_set_style_img_recolor_opa(ui_d->img_nozzle, ui_d->nozzle_heating ? 255 : 0, LV_PART_MAIN);
    // }
    // bool b_heating = heater_is_heating(d->bed_temper, d->bed_target_temper, 2);
    // if (ui_d->bed_heating != b_heating) {
    //     ui_d->bed_heating = b_heating;
    //     lv_obj_set_style_img_recolor_opa(ui_d->img_bed, ui_d->bed_heating ? 255 : 0, LV_PART_MAIN);
    // }
}

void lv_loop_home_pwr_idle_data(ui_home_pwr_data_t *ui_d, pwr_data_t *pwr_data) 
{
    sw_state_t *ui_sw = &ui_d->sw_state;
    sw_state_t *sw = &pwr_data->state.nvs_config.sw;

    power_data_t *ui_source_data = &ui_d->source_data; 
    power_data_t *source_data = &pwr_data->state.power_data;

    /*刷新电源开关的状态*/
    if (ui_d->btn_power) 
    { 
        bool need_update = false;

        if ((!sw->power)
            && (lv_obj_has_state(ui_d->btn_power,LV_STATE_CHECKED)))
        {
            need_update = true;
        }

        if ((sw->power)
            && (!lv_obj_has_state(ui_d->btn_power,LV_STATE_CHECKED)))
        {
            need_update = true;
        }

        if (ui_sw->power != sw->power)
        {
            need_update = true;
        }

        if ((xTaskGetTickCount() - delay_tick_config) >= pdMS_TO_TICKS(CONFIG_DELAY_UPDATE_MS))
        {
            /*sw_power*/
            if (need_update)
            { 
                if (sw->power)
                {
                    lv_obj_add_state(ui_d->btn_power,LV_STATE_CHECKED);
                } 
                else
                {
                    lv_obj_clear_state(ui_d->btn_power,LV_STATE_CHECKED);
                }

                ui_sw->power=sw->power; 
            }
        }
    }

    /*刷新USB的状态*/
    if (ui_d->btn_usb) 
    { 
        bool need_update = false;

        if ((!ui_sw->usb)
            && (lv_obj_has_state(ui_d->btn_usb,LV_STATE_CHECKED)))
        {
            need_update = true;
        }

        if ((ui_sw->usb)
            && (!lv_obj_has_state(ui_d->btn_usb,LV_STATE_CHECKED)))
        {
            need_update = true;
        }

        if (ui_sw->usb != sw->usb)
        {
            need_update = true;
        }

        /*sw_power*/
        if (need_update)
        { 
            if (sw->usb)
            {
                lv_obj_add_state(ui_d->btn_usb,LV_STATE_CHECKED);
            } 
            else
            {
                lv_obj_clear_state(ui_d->btn_usb,LV_STATE_CHECKED);
            }

            ui_sw->usb=sw->usb; 
        }
    }

    char buf[32]={0};

    /*刷新功率和用电量*/
    if (ui_d->label_power)
    { 
        if (ui_source_data->power != source_data->power)
        {
            //PRINT_SCREEN_HOMEW("update ui_d->power=%f\n",ui_source_data->power); 
            ui_source_data->power=source_data->power;
            sprintf(buf,"%.1f W",source_data->power);
            lv_label_set_text(ui_d->label_power,buf);
        }
    } 

    if (ui_d->label_power_usage)
    { 
        if (ui_source_data->ele != source_data->ele)
        { 
            ui_source_data->ele=source_data->ele;

            pwr_fmt_power_usage(source_data->ele,buf,sizeof(buf),true);

            lv_label_set_text(ui_d->label_power_usage,buf);
        }
    } 
}

void lv_loop_home_printing_pwr_data(ui_home_pwr_data_t *ui_d, pwr_data_t *pwr_data, bool is_multi) 
{
    sw_state_t *ui_sw = &ui_d->sw_state;
    sw_state_t *sw = &pwr_data->state.nvs_config.sw;

    power_data_t *ui_source_data = &ui_d->source_data; 
    power_data_t *source_data = &pwr_data->state.power_data; 
    
    /*刷新电源数据*/
    char buf[32]={0};

    /*刷新功率和用电量*/
    if (ui_d->label_voltage)
    {    
        if (!lv_obj_is_valid(ui_d->label_voltage))
        { 
            return;
        }

        if (ui_source_data->voltage != source_data->voltage)
        {    
            ui_source_data->voltage=source_data->voltage;  
            sprintf(buf,"%.1f V",source_data->voltage); 
            if (ut_str_not_blank(buf))
            { 
                lv_label_set_text(ui_d->label_voltage,buf); 
            } 
        }
    }

    if (ui_d->label_current)
    {  
        if (ui_source_data->current != source_data->current)
        {
            //PRINT_SCREEN_HOMEW("update ui_d->current=%f\n",ui_source_data->current);  

            ui_source_data->current=source_data->current;
            sprintf(buf,"%.2f A",source_data->current);
            lv_label_set_text(ui_d->label_current,buf);
        }
    }

    if (ui_d->label_power)
    {  
        if (ui_source_data->power != source_data->power)
        {
            //PRINT_SCREEN_HOMEW("update ui_d->power=%f\n",ui_source_data->power); 
             
            ui_source_data->power=source_data->power;
            if (is_multi)
            {
                sprintf(buf,"%.1fW",source_data->power);
            }
            else
            {
                sprintf(buf,"%.1f W",source_data->power);
            }
            lv_label_set_text(ui_d->label_power,buf);
        }
    } 

    if (ui_d->label_power_usage)
    {  
        if (ui_source_data->ele != source_data->ele)
        {   
            ui_source_data->ele=source_data->ele;
            if (is_multi)
            {
                pwr_fmt_power_usage(source_data->ele,buf,sizeof(buf),false);
            } 
            else
            {
                sprintf(buf,"%.3f KW/H",source_data->ele);
            } 
            lv_label_set_text(ui_d->label_power_usage,buf);
        }
    } 
    
    /*刷新自动断电开关*/
    auto_power_off_t *auto_power_off = &pwr_data->state.nvs_config.auto_power_off;

    if (ui_d->switch_auto_poweroff)
    {   
        bool need_update = false;

        if ((xTaskGetTickCount() - delay_tick_config) >= pdMS_TO_TICKS(CONFIG_DELAY_UPDATE_MS))
        { 
            if ((!sw->auto_power_off)
                && (lv_obj_has_state(ui_d->switch_auto_poweroff,LV_STATE_CHECKED)))
            {
                need_update = true; 
            }

            if ((sw->auto_power_off)
                && (!lv_obj_has_state(ui_d->switch_auto_poweroff,LV_STATE_CHECKED)))
            {
                need_update = true;
            }

            if (ui_sw->auto_power_off != sw->auto_power_off)
            {
                need_update = true;
            }
        }
        
        /*sw_auto_power_off*/
        if (need_update)
        { 
            //PRINT_SCREEN_HOMEW("update sw_auto_power_off=%02x\n",sw->auto_power_off);  

            if (sw->auto_power_off)
            {
                lv_obj_add_state(ui_d->switch_auto_poweroff,LV_STATE_CHECKED);
            } 
            else
            {
                lv_obj_clear_state(ui_d->switch_auto_poweroff,LV_STATE_CHECKED);
            }

            /*need hide buttons*/  
            ui_sw->auto_power_off=sw->auto_power_off; 
        }
    }

    /*刷新USB开关*/
    if (ui_d->btn_usb) 
    { 
        bool need_update = false;

        if ((!ui_sw->usb)
            && (lv_obj_has_state(ui_d->btn_usb,LV_STATE_CHECKED)))
        {
            need_update = true;
        }

        if ((ui_sw->usb)
            && (!lv_obj_has_state(ui_d->btn_usb,LV_STATE_CHECKED)))
        {
            need_update = true;
        }

        if (ui_sw->usb != sw->usb)
        {
            need_update = true;
        }

        /*sw_power*/
        if (need_update)
        {
            //PRINT_SCREEN_HOMEW("update sw_power=%02x\n",sw->usb);   

            if (sw->usb)
            {
                lv_obj_add_state(ui_d->btn_usb,LV_STATE_CHECKED);
            } 
            else
            {
                lv_obj_clear_state(ui_d->btn_usb,LV_STATE_CHECKED);
            }

            ui_sw->usb=sw->usb; 
        }
    } 
}

void lv_loop_home_pwr_data(ui_printing_data_t * ui_d, bambu_mqtt_t *mqtt)
{
    bool pwr_is_bind = mac_address_is_valid(mqtt->nvs_config.pwr_mac_addr);

    if ((ui_d->pwr_is_online != mqtt->pwr_data.is_online) 
        || (ui_d->pwr_is_bind != pwr_is_bind))
    {
        ui_d->pwr_is_online = mqtt->pwr_data.is_online;
        ui_d->pwr_is_bind = pwr_is_bind; 
        if (ui_d->pwr_icon)
        {
            ui_img_pwr_status_icon_set(ui_d->pwr_icon, ui_d->pwr_is_online,pwr_is_bind);
        } 
    }

    if (!pwr_is_bind)
    {
        ui_d->pwr_is_online=false;
    }

    if (!ui_d->pwr_is_online)
    {
        return;
    }
     
    if (mqtt == bambu_mqtt_master)
    { 
        pwr_usb_follow_printer_light(&mqtt->pwr_data.state.nvs_config.sw,&mqtt->bambu_data); 
    }
 
    pwr_data_t * pwr_d = &mqtt->pwr_data;
    
    if (ui_panel_home_idle)
    {
        lv_loop_home_pwr_idle_data(ui_d->home_pwr_data,pwr_d);
    } 

    if (ui_panel_home_printing_one)
    {
        lv_loop_home_printing_pwr_data(ui_d->home_pwr_data,pwr_d,false);
    }  

    if (ui_panel_home_printing_multi)
    {
        lv_loop_home_printing_pwr_data(ui_d->home_pwr_data,pwr_d,true);
    }
}

gcode_state_t lv_loop_home_printing_data(ui_printing_data_t * ui_d, bambu_data_t * d, const lv_img_dsc_t *img_src) {
    if ((ui_d->mc_percent != d->mc_percent) 
        || (bambu_mqtt_master_last != bambu_mqtt_master))
    {
        ui_d->mc_percent = d->mc_percent;
        lv_bar_set_value(ui_d->bar_progress, ui_d->mc_percent, LV_ANIM_OFF);
        lv_label_set_text_fmt(ui_d->label_progress,"%ld%%", ui_d->mc_percent);
    }
    if ((ui_d->layer_num != d->layer_num) 
        || (ui_d->total_layer_num != d->total_layer_num)
        || (bambu_mqtt_master_last != bambu_mqtt_master)
        ) 
    {
        ui_d->layer_num = d->layer_num;
        ui_d->total_layer_num = d->total_layer_num;
        lv_label_set_text_fmt(ui_d->label_layer, "%ld/%ld", ui_d->layer_num, ui_d->total_layer_num);
    }

    if ((ui_d->mc_remaining_time != d->mc_remaining_time)
        || (bambu_mqtt_master_last != bambu_mqtt_master))
    {
        ui_d->mc_remaining_time = d->mc_remaining_time;
        char buf[32];
        remaining_time_to_string(buf, sizeof(buf), ui_d->mc_remaining_time);
        lv_label_set_text(ui_d->label_time, buf);
    } 
      
    if (d->file_updated 
        || (strcmp(lv_label_get_text(ui_d->label_filename), d->gcode_file) != 0)) 
    {
        d->file_updated = false;
        lv_label_set_text(ui_d->label_filename, d->gcode_file);
    }

    if (ui_d->label_index)
    {
        if (ut_str_not_blank(lv_label_get_text(ui_d->label_index)))
        {
            uint32_t check_index = atoi(lv_label_get_text(ui_d->label_index));
            uint32_t current_index = printer_nvs_idx_to_sorted_idx(ui_d->index)+1;
            if (current_index != check_index)
            {
                lv_label_set_text_fmt(ui_d->label_index,"%ld",current_index);
            }
        }
    }
    
    bool printer_paused = (d->gcode_state == GCODE_STATE_PAUSE);
    if (ui_d->paused != printer_paused) {
        ui_d->paused = printer_paused;
        if (ui_d->paused) {
            lv_obj_set_style_text_color(ui_d->label_pause_resume_symbol, lv_color_hex(0x4CD112), LV_PART_MAIN);
            lv_label_set_text_static(ui_d->label_pause_resume_symbol, symbol_resume);
            lv_label_set_text(ui_d->label_pause_resume_text, RS_TRANSLATE(K_BTN_RESUME));
        } else {
            lv_obj_set_style_text_color(ui_d->label_pause_resume_symbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
            lv_label_set_text_static(ui_d->label_pause_resume_symbol, symbol_pause);
            lv_label_set_text(ui_d->label_pause_resume_text, RS_TRANSLATE(K_BTN_PAUSE));
        }
    }

    /*翻译实时状态*/
    if ((ui_d->stg_cur != d->stg_cur)
        || (true == ui_d->need_translate))
    {
        ui_d->stg_cur = d->stg_cur;

        switch (ui_d->stg_cur) 
        {
            case 2:
                ui_panel_printing_goto_prepare(ui_d);
                ui_prepre_set_index(ui_d, 0);
                break;
            case 14:
                ui_panel_printing_goto_prepare(ui_d);
                ui_prepre_set_index(ui_d, 1);
                break;
            case 1:
                ui_panel_printing_goto_prepare(ui_d);
                ui_prepre_set_index(ui_d, 2);
                break;
            case 0:
                ui_panel_printing_goto_icon(ui_d, img_src);
                break;
            default:
                break;
        }

        ui_d->need_translate = false;
    }
    if (ui_d->img_printer) {
        const void * img_now_src = lv_img_get_src(ui_d->img_printer);
        if (img_now_src != img_src) {
            lv_img_set_src(ui_d->img_printer, img_src);
        }
    }
    gcode_state_t state = GCODE_STATE_FOR_USER;
    if (ui_d->gcode_state != d->gcode_state) {
 
        /*状态发生变化时需要更新主页Panda*/ 
        if ((GCODE_STATE_PREPARE == d->gcode_state)
            || (GCODE_STATE_FAILED == d->gcode_state))
        {
            notify_update_3mf_preview();
        }

        state = ui_d->gcode_state = d->gcode_state;
         
        if (ui_d->panel_status_overlay != NULL) {
            lv_obj_del(ui_d->panel_status_overlay);
            ui_d->panel_status_overlay = NULL;
        } 
        switch (d->gcode_state) {
            case GCODE_STATE_PREPARE:
                PRINT_SCREEN_HOMEW("GCODE_STATE_PREPARE need check reprint\n");  
                PRINT_SCREEN_HOMEW("is_print_by_panda_touch false\r\n"); 
                #if 0
                if (d->reprint_check.is_print_by_panda_touch)
                {
                    if (ut_str_not_blank(d->reprint_check.gcode_file))
                    {
                        d->is_print_by_panda_touch = true; 
                        PRINT_SCREEN_HOMEW("print the file[%s] from panda touch\n",d->reprint_check.gcode_file); 
                        memset(d->reprint_check.gcode_file,0,sizeof(d->reprint_check.gcode_file));
                    }

                    d->reprint_check.is_print_by_panda_touch=false;
                }  
                #endif
                ui_screen_select(UI_TYPE_SCREEN_HOME);
                break;
            case GCODE_STATE_FAILED: 
                ui_panel_status_no_printing(ui_d, lv_color_hex(0xFF9F09), K_PRINT_CANCELED, d);
                break;
            case GCODE_STATE_FINISH: 
                ui_panel_status_no_printing(ui_d, lv_color_hex(0x4CD112), K_PRINT_FINISHED, d);
                break;
            case GCODE_STATE_RUNNING:
            { 
            }
            break;

            default:
                break;
        }
    }

    return state;
}




void ui_screen_create_home(void) {
    ui_panel_home = ui_panel_create(ui_screen_main, 0, lv_color_hex(0x444444));
    lv_obj_set_size(ui_panel_home, 704, 452);
    lv_obj_align(ui_panel_home, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    ui_panel_home_idle = ui_panel_create_home_idle_screen(ui_panel_home);
    // ui_panel_home_printing_one = ui_panel_creat_home_printing_one_screen(ui_panel_home, bambu_mqtt_master, 0);

    ui_obj_set_type(ui_panel_home, UI_TYPE_SCREEN_HOME);
    lv_obj_add_flag(ui_panel_home, LV_OBJ_FLAG_HIDDEN);
}

static printer_group_t *get_leader_group_last = NULL;


void lv_loop_home(void) {
    if (ui_panel_home == NULL) return;

    printer_group_sync_lock(0);
    printer_control_t get_control_type = group_sync_data.control_type;
    printer_group_sync_unlock(); 

    if (ui_panel_home_idle != NULL) {
        bool exit_home_idle = false; 
        ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_obj_get_user_data(ui_panel_home_idle); 
        bambu_data_t * d = &bambu_mqtt_master->bambu_data;
        nvs_config_t * nvs = &bambu_mqtt_master->nvs_config; 

        #if 0
        if (ui_d)
        {
            if (bambu_mqtt_master_last != bambu_mqtt_master)
            { 
                //home_reset_pwr_ui_data(ui_d->home_pwr_data);  
            }

            lv_loop_home_temperatures(ui_d, d); 
            lv_loop_home_pwr_data(ui_d,bambu_mqtt_master); 
        }
        
        
        /*在空闲页面，如果是单台打印，检查该打印机是否正在打印*/ 
        if (PRT_CTL_SINGLE == get_control_type)
        {
            /*如果是连接上了，并且不是空闲则进去*/
            if ((MQTT_CONNECTED == bambu_mqtt_master->status) 
                && (GCODE_STATE_IDLE != bambu_mqtt_master->bambu_data.gcode_state))
            { 
                uint8_t index = bambu_get_nvs_index(nvs); 
                if (bambu_printer_index_valid(index))
                {
                    exit_home_idle = true;  
                    ui_panel_home_printing_one = ui_panel_creat_home_printing_one_screen(ui_panel_home, bambu_mqtt_master, index);
                    //PRINT_SCREEN_HOMEW("ui_panel_creat_home_printing_one_screen\n");
                }
            }
        }
        else
        {
            uint8_t printing_cnt = 0; 

            printer_group_sync_lock(0);

            printer_group_t *get_leader_group = printer_group_get_leader();

            if (get_leader_group)
            {   
                /*遍历整个组有没有正在打印的打印机*/
                nvs_config_group_t *nvs_group = &get_leader_group->nvs_config; 
                for (uint8_t i = 0; i < nvs_group->printers_cnt; i++) 
                {
                    bambu_mqtt_t * mqtt = bambu_get_mqtt(nvs_group->printers_nvs_idx[i]);
                    
                    if (mqtt->status != MQTT_CONNECTED) continue;
                    if (mqtt->bambu_data.gcode_state == GCODE_STATE_IDLE) continue;
                    printing_cnt++; 
                } 
            }

            printer_group_sync_unlock();

            if (printing_cnt>0)
            {
                ui_panel_home_printing_multi = ui_panel_creat_home_printing_multi_screen(ui_panel_home);
                exit_home_idle = true;
            }   
        } 
        
        #endif
        
        if (exit_home_idle) 
        {
            if (ui_d->home_pwr_data)
            {  
                free(ui_d->home_pwr_data); 
            }
            free(ui_d);
            lv_obj_del(ui_panel_home_idle);
            ui_panel_home_idle = NULL; 
            //PRINT_SCREEN_HOMEW("exit home idle,ui_panel_home_printing_one=[%x]\n",(unsigned int)ui_panel_home_printing_one);
        }
    } 

    #if 0
    if (ui_panel_home_printing_one != NULL) {
        bool go_home_idle = false; 
        ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_obj_get_user_data(ui_panel_home_printing_one);
       
        uint8_t get_master_nvs_idx = bambu_get_mqtt_index(bambu_mqtt_master);
        if (!bambu_printer_index_valid(get_master_nvs_idx))
        {
            //PRINT_SCREEN_HOMEW("invalid mqtt index end_printing_one\n");
            go_home_idle=true;
            goto end_printing_one;
        }

        //PRINT_SCREEN_HOMEW("index=%d,name[%s]\n",(int)ui_d->index,bambu_mqtt_master->nvs_config.name);

        if (get_master_nvs_idx == ui_d->index)
        { 
            bambu_data_t * d = &bambu_mqtt_master->bambu_data;  
            pwr_data_t * pwr_d = &bambu_mqtt_master->pwr_data;
            
            bool pwr_is_bind = mac_address_is_valid(bambu_mqtt_master->nvs_config.pwr_mac_addr);

            if ((ui_d->pwr_is_online != bambu_mqtt_master->pwr_data.is_online) 
                || (ui_d->pwr_is_bind != pwr_is_bind))
            {
                ui_d->pwr_is_online = bambu_mqtt_master->pwr_data.is_online;
                ui_d->pwr_is_bind = pwr_is_bind; 
            }

            if (!pwr_is_bind)
            {
                ui_d->pwr_is_online=false;
            }

            lv_loop_home_temperatures(ui_d, d); 
            
            gcode_state_t state = lv_loop_home_printing_data(ui_d, d, ui_img_src_get_printer_series(bambu_mqtt_master->nvs_config.model_num));
            
            /*goto icon时面板会被删除*/
            lv_loop_home_pwr_data(ui_d,bambu_mqtt_master);

            if (state != GCODE_STATE_FOR_USER) {
                //PRINT_SCREEN_HOMEW("ui_screen_select(UI_TYPE_SCREEN_HOME)\n");
                //ui_screen_select(UI_TYPE_SCREEN_HOME);
            }
            if (ui_d->connect_flag != bambu_mqtt_master->nvs_config.connect_flag) {
                ui_d->connect_flag = bambu_mqtt_master->nvs_config.connect_flag;
                if (ui_d->connect_flag == CONNECT_FLAG_SYNC) {
                    // delete 
                    go_home_idle = true;
                }
            } 

            switch (d->update_3mf_preview)
            {
                case HOME_PANDA_DEFAULT:
                {
                    PRINT_SCREEN_HOMEW("HOME_PANDA_DEFAULT");

                    memcpy(&ui_img_icon_model_png, &ui_img_icon_model_png_bak,sizeof(lv_img_dsc_t));

                    d->update_3mf_preview=HOME_PANDA_MAX; 
                    //go_home_idle = true; 

                    lv_img_set_src(ui_d->img_panda,&ui_img_icon_model_png); 
                    break;
                }

                case HOME_PANDA_HISTORY: 
                case HOME_PANDA_USB:
                {
                    PRINT_SCREEN_HOMEW("HOME_PANDA_HISTORY or HOME_PANDA_USB");

                    memcpy(&ui_img_icon_model_png, &ui_img_icon_model_png_new,sizeof(lv_img_dsc_t));

                    d->update_3mf_preview=HOME_PANDA_MAX;

                    lv_img_set_src(ui_d->img_panda,&ui_img_icon_model_png);
                    //go_home_idle = true; 

                    break;
                }

                default:
                {
                    break;
                }
            } 
        }
        else
        {
            go_home_idle=true;
            /*主机发生变化后删除界面后重置*/
        }
        
        if (PRT_CTL_GROUP == get_control_type)
        {
            go_home_idle = true;
        }
        else
        {
            /*如果是该单台打印机停止打印了或者断开连接了，跳转到空闲页面*/
            /*获取当前是Master的打印机*/ 
            if ((MQTT_CONNECTED != bambu_mqtt_master->status)
                || (GCODE_STATE_IDLE == bambu_mqtt_master->bambu_data.gcode_state))
            {
                go_home_idle = true;
                //PRINT_SCREEN_HOMEW("go_home_idle = true\n");
            }
        }

        end_printing_one:
        if (go_home_idle)
        {
            if (ui_d->home_pwr_data)
            { 
                free(ui_d->home_pwr_data);
            }
            free(ui_d);
            lv_obj_del(ui_panel_home_printing_one);
            ui_panel_home_printing_one = NULL;
            // goto idle screen
            ui_panel_home_idle = ui_panel_create_home_idle_screen(ui_panel_home);  
            //PRINT_SCREEN_HOMEW("goto idle screen at printing one\n");
        }
    }

    if (ui_panel_home_printing_multi != NULL) 
    {
        bool go_home_idle = false;
        ui_printing_multi_t * multi = (ui_printing_multi_t *)lv_obj_get_user_data(ui_panel_home_printing_multi);
        printer_group_sync_lock(0);
        printer_group_t *get_leader_group = printer_group_get_leader();
        printer_group_sync_unlock(); 

        bool printer_in_list[BAMBU_PRINTER_MAX_NUM];
        lv_memset_00(printer_in_list, sizeof(printer_in_list));
        lv_obj_t * panel_printer_changed = NULL;
         
        uint8_t get_printers_cnt = 0;
        nvs_config_group_t *nvs_group = NULL;
 
        if ((PRT_CTL_SINGLE == get_control_type)
            || (!get_leader_group)
            || (get_leader_group_last && (get_leader_group_last != get_leader_group)))
        { 
            go_home_idle = true;  
            /*多台打印时, 如果控制方式变成单台控制, 删除上下文后 跳转到空闲面板*/
            //PRINT_SCREEN_HOMEW("control type change or leader change need goto home idle panel\n");
            goto home_idle;
        } 

        if (get_leader_group)
        {
            get_printers_cnt = get_leader_group->nvs_config.printers_cnt;
            nvs_group = &get_leader_group->nvs_config;
        }

        // Traverse the status of printers that are already in the display panel list
        for (uint8_t i = 0; i < lv_obj_get_child_cnt(multi->panel_printers);) {
            lv_obj_t * panel = lv_obj_get_child(multi->panel_printers, i);
            ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_obj_get_user_data(panel);
            /*获取创建的卡片上下文，获取nvs序号对应的打印机*/ 
            bambu_mqtt_t * mqtt = bambu_get_mqtt(ui_d->index);  
            bambu_data_t * d = &mqtt->bambu_data;
            pwr_data_t * pwr_d = &mqtt->pwr_data;

            lv_loop_home_temperatures(ui_d, d);  
            
            gcode_state_t state = lv_loop_home_printing_data(ui_d, d, ui_img_src_get_printer_models(mqtt->nvs_config.model_num, d->ams.ams_exist_bits));

            /*goto icon时面板会被删除*/
            lv_loop_home_pwr_data(ui_d,mqtt);

            switch (state) {
                case GCODE_STATE_FOR_USER: // no action
                    break;
                case GCODE_STATE_FAILED:
                case GCODE_STATE_FINISH:
                    multi->paused_bits &= ~(1 << (ui_d->index));
                    multi->printing_bits &= ~(1 << (ui_d->index)); 
                    break;
                case GCODE_STATE_PAUSE:
                    multi->paused_bits |= (1 << (ui_d->index));
                    multi->printing_bits |= (1 << (ui_d->index)); 
                    break;
                case GCODE_STATE_PREPARE:
                case GCODE_STATE_RUNNING:
                    multi->paused_bits &= ~(1 << (ui_d->index));
                    multi->printing_bits |= (1 << (ui_d->index));  
                    break;
                default:
                    break;
            }
            if (d->chamber_light) {
                multi->chamber_light_bits |= (1 << (ui_d->index));
            } else {
                multi->chamber_light_bits &= ~(1 << (ui_d->index));
            }

            if (ui_d->mqtt_status != mqtt->status) {
                ui_d->mqtt_status = mqtt->status;
                ui_img_mqtt_status_icon_set(ui_d->mqtt_icon, ui_d->mqtt_status);
            }

            if (ui_d->account_type != mqtt->nvs_config.account_type) {
                ui_d->account_type = mqtt->nvs_config.account_type;
                ui_img_cloud_status_icon_set(ui_d->cloud_icon, ui_d->account_type>0);
            }

            if (ui_d->pwr_is_online)
            {
                multi->has_pwr_bits |= (1 << (ui_d->index));
            }
            else
            {
                multi->has_pwr_bits &= ~(1 << (ui_d->index));
            }
            
            //PRINT_SCREEN_HOMEW("ui_d->connect_flag=%d,mqtt->nvs_config.connect_flag=[%d]\n",(int)ui_d->connect_flag,mqtt->nvs_config.connect_flag);
            if (ui_d->connect_flag != mqtt->nvs_config.connect_flag) {
                ui_d->connect_flag = mqtt->nvs_config.connect_flag;
                //ui_context_mqtt_connect_flag_set(ui_d->panel_connect_flag, ui_d->connect_flag);
                panel_printer_changed = panel;
            }

            /*更新多台打印的数据*/
            lv_loop_home_printing_multi_data(multi, d);

            /*如果打印机被移除了或者停止打印了，不再显示在多台打印面板*/
            //PRINT_SCREEN_HOMEW("ui_d->index=%d,get_printers_cnt=[%d]\n",(int)ui_d->index,(int)get_printers_cnt);
            /*刚开始是序号大于当前打印机的数量则进来，表示删除了打印机*/
            //PRINT_SCREEN_HOMEW("printer_group_contains_index=[%d]\n",(int)printer_group_contains_index(get_leader_group,ui_d->index));
            //PRINT_SCREEN_HOMEW("state=%d\n",(int)state);
            /*可以判断如果序号不在打印机列表序号内则删除它*/
            if ((state == GCODE_STATE_IDLE) || (!printer_group_contains_index(get_leader_group,ui_d->index))) {
                multi->chamber_light_bits &=  ~(1 << (ui_d->index));
                multi->paused_bits &=  ~(1 << (ui_d->index));
                multi->printing_bits &=  ~(1 << (ui_d->index));
                multi->printer_bits &= ~(1 << (ui_d->index));
                multi->has_pwr_bits &= ~(1 << (ui_d->index));
 
                if (ui_d->home_pwr_data)
                { 
                    free(ui_d->home_pwr_data); 
                }
                free(ui_d);
                lv_obj_del(panel);
            } else {
                printer_in_list[ui_d->index] = true; 
                i++;
            }
        }
         
        /*遍历组获取打印机数据*/ 
        /*第一个是主机，序号不一定是1*/
        // printers that not in the display panel list
        for (uint8_t i=0; i < get_printers_cnt; i++) 
        {
            /*遍历组获取组NVS序号对应的打印机*/
            uint8_t get_nvs_index = nvs_group->printers_nvs_idx[i];

            /*如果不在面板里面则创建它*/
            if (printer_in_list[get_nvs_index]) continue;

            
            bambu_mqtt_t * mqtt = bambu_get_mqtt(get_nvs_index);
            bambu_data_t * d = &mqtt->bambu_data;
            
            if (d->gcode_state == GCODE_STATE_IDLE) continue;

            //PRINT_SCREEN_HOMEW("get_nvs_index[%d] printing printer not in list\n",(int)get_nvs_index);

            /*创建一个新的打印机卡片*/
            panel_printer_changed = ui_panel_creat_home_printing_multi_one(multi->panel_printers, mqtt, i);

            /*标记多台打印的上下文*/
            multi->printer_bits |= (1 << get_nvs_index);
 
            //ui_screen_select(UI_TYPE_SCREEN_HOME);
        } 

        /*在连接发生变化，或者新建了打印机卡片时*/
        if (panel_printer_changed) 
        {
            PRINT_SCREEN_HOMEW("panel_printer_changed lv_obj_move_to_index\n");

            ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_obj_get_user_data(panel_printer_changed);
            for (uint32_t i = 0; i < lv_obj_get_child_cnt(multi->panel_printers); i++) {     
                lv_obj_t * panel_exist = lv_obj_get_child(multi->panel_printers, i);
                ui_printing_data_t * ui_d_exist = (ui_printing_data_t *)lv_obj_get_user_data(panel_exist);
                /*刚刚新建的卡片, 如果连接权限大于存在的打印机, 替换位置*/
                if (ui_d->connect_flag <= ui_d_exist->connect_flag) continue; 
                lv_obj_move_to_index(panel_printer_changed, i);
                break;
            }
        }
         
        if (false == go_home_idle)
        { 
            //PRINT_SCREEN_HOMEW("get_printers_cnt=%d\n",(int)get_printers_cnt);
            if ((0 == get_printers_cnt) 
                || (lv_obj_get_child_cnt(multi->panel_printers) == 0))
            {            
                /*如果时没有一台了，直接释放所有上下文，跳转到空闲面板*/
                /*如果组内打印机的个数变成0个了，删除多台打印面板 跳转到空闲面板*/  
                /*在mqtt状态变为空闲时，会被删除，全部被删除后会变成空闲面板，这个时候只显示主机的数据*/ 
                go_home_idle=true; 
            }
        }

        home_idle: 
        if (get_leader_group_last != get_leader_group)
        {
            get_leader_group_last = get_leader_group;
        }

        if (go_home_idle)
        {
            /*如果控制模式发生变化，则释放所有的上下文，跳转到空闲面板*/
            // Traverse the status of printers that are already in the display panel list
            for (uint8_t i = 0; i < lv_obj_get_child_cnt(multi->panel_printers); i++) 
            {
                lv_obj_t * panel = lv_obj_get_child(multi->panel_printers, i);
                if (panel)
                {
                    ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_obj_get_user_data(panel);
                    if (ui_d)
                    { 
                        if (ui_d->home_pwr_data)
                        {  
                            free(ui_d->home_pwr_data); 
                        }
                        free(ui_d); 
                    }

                    lv_obj_del(panel);
                }
            }

            free(multi);
            lv_obj_del(ui_panel_home_printing_multi);
            ui_panel_home_printing_multi = NULL;

            // goto idle screen
            ui_panel_home_idle = ui_panel_create_home_idle_screen(ui_panel_home); 

            //PRINT_SCREEN_HOMEW("goto idle screen at multi\n");
        }
    } 
    #endif


    if (bambu_mqtt_master_last != bambu_mqtt_master)
    {
        bambu_mqtt_master_last=bambu_mqtt_master; 
    }
}
