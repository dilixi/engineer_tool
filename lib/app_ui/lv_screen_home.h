#ifndef LV_SCREEN_HOME_H
#define LV_SCREEN_HOME_H
  
#include "bambu_mqtt.h"
//#include "bambu_account.h"

typedef enum {
    UI_TIPS_TYPE_ICON = 0,
    UI_TIPS_TYPE_PREPARE,
    UI_TIPS_TYPE_REFRESH,
} ui_tips_type_t;

typedef struct 
{     
    lv_obj_t * label_voltage_title;
    lv_obj_t * label_current_title;
    lv_obj_t * label_power_title;  
    lv_obj_t * label_ele_title;  
    lv_obj_t * label_voltage;
    lv_obj_t * label_current;
    lv_obj_t * label_power;  
    lv_obj_t * label_power_usage;   

    lv_obj_t * btn_power;
    lv_obj_t * btn_usb;
    lv_obj_t * btn_reset_pwr_usage;
    lv_obj_t * switch_auto_poweroff;  
 
    power_data_t source_data;  
    sw_state_t sw_state;  
} ui_home_pwr_data_t;

typedef struct {
    mqtt_status_t mqtt_status;
    uint8_t account_type;
    connect_flag_t connect_flag;
    uint32_t index;
    gcode_state_t gcode_state;
    ui_tips_type_t tips_type;
    int32_t nozzle_temper;
    int32_t bed_temper;
    int32_t chamber_temper;
    int32_t chamber_humidity;
    int32_t mc_percent;
    int32_t mc_remaining_time;
    int32_t layer_num;
    int32_t total_layer_num;
    int32_t stg_cur;
    bool paused;
    bool chamber_light;

    bool nozzle_heating;
    bool bed_heating;
	bool need_translate; 
    bool pwr_is_online;
    bool pwr_is_bind;
    lv_obj_t * mqtt_icon;
    lv_obj_t * cloud_icon;
    lv_obj_t * pwr_icon;
    lv_obj_t * panel_tips;
    lv_obj_t * img_printer;
    lv_obj_t * panel_connect_flag;
    lv_obj_t * label_nozzle;
    lv_obj_t * label_bed;
    lv_obj_t * label_chamber_temp;
    lv_obj_t * label_chamber_humidity;
    lv_obj_t * label_filename;
    lv_obj_t * label_progress;
    lv_obj_t * bar_progress;
    lv_obj_t * label_layer;
    lv_obj_t * label_time;
    lv_obj_t * label_pause_resume_symbol;
    lv_obj_t * label_pause_resume_text;
	lv_obj_t * label_stop_text;
    lv_obj_t * panel_status;
    lv_obj_t * panel_status_overlay;
    lv_obj_t * panel_status_overlay_status;
    lv_obj_t * panel_status_overlay_reprint;
    lv_obj_t * btn_led;

    lv_obj_t * img_nozzle;
    lv_obj_t * img_bed;
    lv_obj_t * label_index;
    lv_obj_t * img_panda;
    ui_home_pwr_data_t *home_pwr_data;
} ui_printing_data_t;

typedef struct {
    uint16_t chamber_light_bits;
    uint16_t printer_bits;
    uint16_t paused_bits;
    uint16_t printing_bits;
    uint16_t has_pwr_bits;
    lv_obj_t * panel_printers;
    lv_obj_t * panel_btn;
    lv_obj_t * btn_led_all;
    lv_obj_t * btn_stop_all;
    lv_obj_t * btn_pause_all;
    lv_obj_t * btn_power_all;
    lv_obj_t * btn_usb_all;
    lv_obj_t * btn_menu;
} ui_printing_multi_t;

extern const char * symbol_pause;
extern const char * symbol_resume;

const char * remaining_time_to_string(char * buf, uint32_t max_len, int32_t mc_remaining_time);
void ui_panel_add_ctrl_btns(lv_obj_t * parent, lv_coord_t x_ofs, ui_printing_data_t * ui_d);
void ui_panel_add_ctrl_btns_pwr(lv_obj_t * parent, lv_coord_t x_ofs, ui_home_pwr_data_t * home_pwr_data);
lv_obj_t * ui_panel_add_ctrl_pwr_data(lv_obj_t * parent, ui_home_pwr_data_t * home_pwr_data);
void lv_loop_home_printing_pwr_data(ui_home_pwr_data_t *ui_d, pwr_data_t *pwr_data, bool is_multi);

lv_obj_t * ui_panel_create_home_idle_screen(lv_obj_t * parent);
lv_obj_t * ui_panel_creat_home_printing_one_screen(lv_obj_t * parent, bambu_mqtt_t * mqtt, uint32_t index);
lv_obj_t * ui_panel_creat_home_printing_multi_screen(lv_obj_t * parent);
lv_obj_t * ui_panel_creat_home_printing_multi_one(lv_obj_t * parent, bambu_mqtt_t * mqtt, uint32_t index);
void lv_loop_home_printing_multi_data(ui_printing_multi_t * multi, bambu_data_t * d);

void btn_printing_pause_clicked(lv_event_t * e);
void btn_printing_stop_clicked(lv_event_t * e);

const lv_img_dsc_t * ui_img_src_get_printer_series(bambu_model_t model);
const lv_img_dsc_t * ui_img_src_get_printer_models(bambu_model_t model, bool with_ams);
bambu_model_t ui_get_model_from_img(const lv_img_dsc_t * img_src);
void home_reset_pwr_ui_data(ui_home_pwr_data_t *pwr_data);

#endif /*LV_SCREEN_HOME_H*/
