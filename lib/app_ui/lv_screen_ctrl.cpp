#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"
#include "utils_lib.h"

static void update_filament_tile_cb(lv_event_t * e)
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
                /*如果是AMS，则显示为AMS*/
                if (BAMBU_DATA_MASTER.ams.ams_exist_bits)
                {
                    lv_label_set_text(label, "AMS"); 
                }
                else
                {
                    lv_label_set_text(label, RS_TRANSLATE(get_key)); 
                } 
            }
        }
    }
}

const ui_btn_ctl_top_t btns[] {
    {"Temperature/Axis", UI_TYPE_SCREEN_CTRL_AXIS,{K_CTL_TOP_T_TEMP_AXIS,}},
    {"Filament", UI_TYPE_SCREEN_CTRL_FILAMENT,{K_CTL_TOP_T_FILAMENT,update_filament_tile_cb}},
    {"Panda PWR", UI_TYPE_SCREEN_CTRL_POWER,{K_INVALID_ID,}},
};

lv_obj_t * ui_panel_create_ctrl(lv_obj_t * screen) {
    lv_obj_t * panel = ui_panel_create(screen, 0, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 704, 452);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    uint8_t btn_cnt = panda_pwr_is_opened?ARRAY_SIZE(btns):ARRAY_SIZE(btns)-1;
    lv_obj_t * top = ui_panel_create_top(panel, btns, btn_cnt);

    lv_obj_t * panel_axis = ui_panel_create_axis(panel);
    lv_obj_t * panel_filament = ui_panel_create_filament(panel);
    
    /*如果打开了则创建相关UI*/
    if (panda_pwr_is_opened)
    {
        // lv_obj_t * panel_data = ui_panel_create_power(panel);
        
        // ui_obj_set_type(panel_data, UI_TYPE_SCREEN_CTRL_POWER);
        // lv_obj_add_flag(panel_data, LV_OBJ_FLAG_HIDDEN); 
    } 

    ui_btn_top_select(top, UI_TYPE_BTN_TOP_CTRL_AXIS);
    lv_obj_clear_flag(panel_axis, LV_OBJ_FLAG_HIDDEN);

    return panel;
}

void ui_screen_create_ctrl(void) {
    lv_obj_t * panel_ctrl = ui_panel_create_ctrl(ui_screen_main);
    ui_obj_set_type(panel_ctrl, UI_TYPE_SCREEN_CTRL);
    lv_obj_add_flag(panel_ctrl, LV_OBJ_FLAG_HIDDEN);
}
