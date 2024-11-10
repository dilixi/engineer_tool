#include "utils_lib.h" 

static lv_obj_t * ui_panel_start = NULL;
static uint32_t ms = 0;


/************* screen ***************/
void ui_screen_start_init(void) {
    ui_panel_start = ui_panel_create(ui_screen_main, 0, lv_color_hex(0x444444));    
    lv_obj_set_size(ui_panel_start, 800, 480);
    lv_obj_set_align(ui_panel_start, LV_ALIGN_CENTER);

    lv_obj_t * img_logo = lv_img_create(ui_panel_start);
 
    lv_img_set_src(img_logo, &ui_img_start_btt_logo_png);
    lv_obj_set_align(img_logo, LV_ALIGN_CENTER);

    ms = get_current_millis() + 800;

    printf("ui_panel_start=%x\r\n",ui_panel_start);
    //lv_obj_del_async(ui_panel_start);
}

void lv_loop_start(void) {
    if (ui_panel_start == NULL) return;
    uint32_t cur_ms = get_current_millis();
 
    if (ms < get_current_millis()) 
    {
        lv_obj_del(ui_panel_start);  
        ui_panel_start = NULL; 
        printf("start screen del\r\n");
    }
}
