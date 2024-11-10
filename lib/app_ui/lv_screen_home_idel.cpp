#include "utils_lib.h"
#include "lv_screen_home.h"

lv_obj_t * ui_panel_create_home_idle_screen(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 0, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 704, 452);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_t * panel_icon = ui_panel_create(panel, 12, lv_color_hex(0x575757));
    lv_obj_set_size(panel_icon, panda_pwr_is_opened?484:564, 420);
    lv_obj_align(panel_icon, LV_ALIGN_LEFT_MID, 20, 0);

    lv_obj_t * img_btt = lv_img_create(panel_icon);
    lv_img_set_src(img_btt, &ui_img_btt_logo_png);
    lv_obj_set_align(img_btt, LV_ALIGN_CENTER);

    ui_printing_data_t * ui_d = (ui_printing_data_t *)lv_mem_alloc(sizeof(ui_printing_data_t));
    lv_memset_00(ui_d, sizeof(ui_printing_data_t));
    ui_panel_add_ctrl_btns(panel, panda_pwr_is_opened?-105:-20, ui_d); 
    
    ui_d->pwr_icon = NULL;

    if (panda_pwr_is_opened)
    {
        ui_home_pwr_data_t * ui_d_pwr = (ui_home_pwr_data_t *)lv_mem_alloc(sizeof(ui_home_pwr_data_t));
        lv_memset_00(ui_d_pwr, sizeof(ui_home_pwr_data_t));
        
        ui_d_pwr->label_voltage_title = NULL;
        ui_d_pwr->label_current_title = NULL;
        ui_d_pwr->label_power_title = NULL; 
        ui_d_pwr->label_ele_title = NULL;  
        ui_d_pwr->label_voltage = NULL;
        ui_d_pwr->label_current = NULL;
        ui_d_pwr->switch_auto_poweroff = NULL;  
        
        ui_d->home_pwr_data = ui_d_pwr;
        
        home_reset_pwr_ui_data(ui_d_pwr);
    
        ui_panel_add_ctrl_btns_pwr(panel,-10,ui_d_pwr);
    }
    else
    {
        ui_d->home_pwr_data=NULL;
    }

    lv_obj_set_user_data(panel, ui_d);

    return panel;
}
