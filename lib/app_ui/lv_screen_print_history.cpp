#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"
#include "utils_lib.h"
//#include "usb_host_msc/usb_host_msc.h"

#define SW_PRINT_PRINTER_HISTORY 0

#if SW_PRINT_PRINTER_HISTORY && SW_PRINT_ALL 
#define PRINT_SCREEN_HISTORY printf
#else
#define PRINT_SCREEN_HISTORY(...)
#endif
     
enum {
    UI_POPUP_BTN_PRINT_CANCEL,
    UI_POPUP_BTN_PRINT_ABORT,
}; 
        
static lv_obj_t *ui_panel_history = NULL;
static lv_obj_t *panel_loading = NULL;
static lv_obj_t * s_ui_label_not_insert = NULL;
static lv_obj_t * s_ui_panel_title = NULL;



file_list_history_t *print_history_file_list=NULL;  

static void btn_refresh_clicked(lv_event_t * e) 
{ 
    PRINT_SCREEN_HISTORY("btn_refresh_clicked");
    /*发送获取历史记录的消息*/
} 

static void ui_panel_add_refresh_button(lv_obj_t *parent)
{
    lv_obj_t * btn_refresh = ui_btn_img_create(parent, 80, 80, LV_RADIUS_CIRCLE, lv_color_hex(LV_32BIT_BTT_RED), LV_SYMBOL_REFRESH);
    lv_obj_add_flag(btn_refresh, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(btn_refresh, LV_ALIGN_BOTTOM_RIGHT, -13, -13);
    lv_obj_set_style_text_font(btn_refresh, &opensansb24, 0);
    lv_obj_add_event_cb(btn_refresh, btn_refresh_clicked, LV_EVENT_CLICKED, NULL); 
}

static void ui_panel_create_not_exist(lv_obj_t *parent)
{
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, RS_TRANSLATE(K_T_HISTORY_NOT_FIND));
    s_ui_label_not_insert = label;
    rs_add_translate_cb(s_ui_label_not_insert,RS_TRANSLATE_DEFAULT_CB,(void *)K_T_HISTORY_NOT_FIND,KEY_NUMBER);  
}

static void ui_panel_create_only_cloud(lv_obj_t *parent)
{
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, RS_TRANSLATE(K_T_HISTORY_ONLY_CLOUD));
    s_ui_label_not_insert = label;
    rs_add_translate_cb(s_ui_label_not_insert,RS_TRANSLATE_DEFAULT_CB,(void *)K_T_HISTORY_ONLY_CLOUD,KEY_NUMBER);  
}

lv_obj_t * ui_panel_create_history(lv_obj_t * parent) 
{
    lv_obj_t * panel = ui_panel_create_files_list(parent);
    ui_obj_set_type(panel, UI_TYPE_SCREEN_PRINT_HISTORY);
    lv_obj_add_flag(panel, LV_OBJ_FLAG_HIDDEN);
    
    ui_panel_history = panel;
    s_ui_panel_title=NULL;

    ui_panel_create_not_exist(ui_panel_history);

    ui_panel_add_refresh_button(ui_panel_history);

    return panel;
}

static void ui_history_list_add_file(lv_obj_t *parent, lv_color_t text_color, lv_color_t bg_color, bambu_print_history_t * file_info, lv_event_cb_t cb)
{
    char buf[128]; 

    lv_obj_t * btn = lv_list_add_btn(parent, NULL, NULL); 
    lv_obj_set_style_radius(btn, 10, LV_PART_MAIN);
    // lv_obj_set_style_border_color(btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_border_width(btn, 0, LV_PART_MAIN);
    lv_obj_set_style_layout(btn, 0, LV_PART_MAIN); // clear flex
    lv_obj_set_style_bg_color(btn, bg_color, LV_PART_MAIN);
    lv_obj_set_style_text_color(btn, text_color, LV_PART_MAIN);
    lv_obj_set_style_pad_hor(btn, 0, LV_PART_MAIN);
    lv_obj_set_height(btn, 48);

    lv_obj_t * label_icon = lv_label_create(btn); 
    lv_obj_align(label_icon, LV_ALIGN_LEFT_MID, 10, 0);
    lv_obj_set_style_text_font(label_icon, &opensansb16, 0);

    lv_label_set_text(label_icon, LV_SYMBOL_FILE);  

    lv_obj_set_style_text_font(label_icon,&opensansb16,LV_STATE_DEFAULT); 
 
    lv_obj_t * label_name = lv_label_create(btn); 
    lv_obj_set_width(label_name, 365);
    // lv_obj_set_style_bg_color(label_name, lv_color_hex(0xFF0000), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(label_name, 255, LV_PART_MAIN);
    lv_obj_align(label_name, LV_ALIGN_LEFT_MID, 27, 0);
    lv_label_set_text_static(label_name, file_info->title);

    lv_label_set_long_mode(label_name, LV_LABEL_LONG_SCROLL_CIRCULAR);
    ui_obj_set_type(label_name, UI_TYPE_LABEL_GCODE);
 
    lv_obj_t * label_time = lv_label_create(btn);
    lv_obj_align(label_time, LV_ALIGN_LEFT_MID, 404, 0);
 
    snprintf(buf, sizeof(buf), "%.1f h", (float)(file_info->cost_time_s/3600.0));
    lv_label_set_text(label_time, buf); 

    lv_obj_t * label_weight = lv_label_create(btn);
    lv_obj_align(label_weight, LV_ALIGN_LEFT_MID, 574, 0); 
    snprintf(buf, sizeof(buf), "%.1f g", file_info->weight);
    lv_label_set_text(label_weight, buf);  

    lv_obj_add_event_cb(btn, cb, LV_EVENT_CLICKED, (void *)file_info);  
}

lv_obj_t * ui_history_list_create(file_list_history_t *file_list, lv_obj_t * parent, lv_event_cb_t cb)
{
    char buf[128]; 
    
    if (file_list->file_count<0)
    {
        file_list->file_count=0;
        /*如果文件为空则显示为空*/
    } 

    int32_t num = file_list->file_count;
    bambu_print_history_t * files = file_list->files;

    const lv_color_t text_c = lv_color_hex(0xFFFFFF);
    const int32_t w = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    const int32_t h = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_HEIGHT).num;
    const lv_color_t bg_c = lv_color_hex(0x575757); // lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_BG_COLOR).color;

    // lv_list_add_text(obj, "Name   Data  Size");
    /*标题*/
    lv_obj_t * panel_title = ui_panel_create(parent, 5, lv_color_hex(0x444444));
    lv_obj_set_style_bg_opa(panel_title, 0, LV_PART_MAIN);
    lv_obj_set_size(panel_title, w, 35);
    lv_obj_align(panel_title, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t * label_box = ui_panel_create(panel_title, 5, lv_color_hex(0x444444));
    lv_obj_set_size(label_box, 10, 35);
    lv_obj_set_style_bg_opa(label_box, 0, LV_PART_MAIN);
    lv_obj_align(label_box, LV_ALIGN_LEFT_MID, 25, 0); 
    lv_obj_set_style_pad_all(label_box, 0, LV_PART_MAIN);
    lv_obj_set_flex_flow(label_box, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(label_box, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);  
        
    lv_obj_t * label = lv_label_create(label_box);  
    rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_FILE_T_NAME,KEY_NUMBER); 
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0); 
    lv_obj_set_width(label_box, 150);  

    /* must be static not const*/
    static lv_point_t v_line_points[] = { {0, 0}, {0, 23}};
    lv_obj_t * v_line = NULL;
  
    label_box = ui_panel_create(panel_title, 5, lv_color_hex(0x444444));
    lv_obj_set_size(label_box, 10, 35);
    lv_obj_set_style_bg_opa(label_box, 0, LV_PART_MAIN); 
    lv_obj_set_style_pad_all(label_box, 0, LV_PART_MAIN);
    lv_obj_set_flex_flow(label_box, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(label_box, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
   
    /*所需时间*/
    label = lv_label_create(label_box);
    
    v_line = ui_line_create(panel_title, v_line_points, 2, 1, text_c);
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 420, 0);  
    rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_T_HISTORY_COST_TIME,KEY_NUMBER);
    lv_obj_align(label_box, LV_ALIGN_LEFT_MID, 430, 0); 
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_width(label_box, 100);

    /* must be static not const*/
    /*重量*/
    v_line = ui_line_create(panel_title, v_line_points, 2, 1, text_c);
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 590, 0);
    
    label = lv_label_create(panel_title); 
    rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_T_HISTORY_WEIGHT,KEY_NUMBER); 
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 600, 0);

    lv_obj_t * list = lv_list_create(parent);
    lv_obj_set_size(list, w, h - 35);
    lv_obj_align(list, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_opa(list, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(list, 5, LV_PART_MAIN);
    lv_obj_set_style_border_width(list, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_hor(list, 16, LV_PART_MAIN);
    lv_obj_set_style_pad_row(list, 8, LV_PART_MAIN);
    
    lv_obj_set_style_text_font(list,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT);  
      
    for (uint8_t i=0; i<num; i++) 
    {
        ui_history_list_add_file(list,text_c,bg_c,&files[i],cb);
    } 

    return panel_title;
}

static void btn_gcode_clicked(lv_event_t * e) 
{
    PRINT_SCREEN_HISTORY("btn_gcode_clicked");
}

void lv_loop_files_list_history(void) 
{
    if (print_history_file_list == NULL) return; 

    if (ui_panel_history == NULL) return;

    /*如果不是云模式就显示文件为0*/

    static uint8_t time_cnt = 0;
    static uint32_t check_clear_loading = 0; 

    if (check_clear_loading < millis())
    {
        check_clear_loading = millis()+1000; 

        if (panel_loading)
        { 
            /*防止一直转圈圈*/
            time_cnt++; 
            if (time_cnt>=40)
            {
                time_cnt=0;
                lv_obj_del(panel_loading);
                panel_loading=NULL;
                print_history_file_list->refresh_type=HISTORY_REFRESH_NONE;
            }
        }
        else
        {
            time_cnt=0;
        }
    } 

    if (print_history_file_list->refresh_type == HISTORY_REFRESH_NONE) return;
    
    panel_loading = NULL;
    lv_obj_clean(ui_panel_history);

    if (print_history_file_list->file_count > 0) 
    { 
        s_ui_label_not_insert = NULL;
        
        switch (print_history_file_list->refresh_type) 
        {
            case HISTORY_REFRESH_ING:
            {
                PRINT_SCREEN_HISTORY("HISTORY_REFRESH_ING");
                s_ui_panel_title=NULL;
                panel_loading = lv_scanning_spin_create(ui_panel_history, RS_TRANSLATE(K_LOADING)); 
            }
            break; 

            case HISTORY_REFRESH_OK_NORMAL:
            {
                PRINT_SCREEN_HISTORY("HISTORY_REFRESH_OK_NORMAL");

                s_ui_panel_title = ui_history_list_create(print_history_file_list, ui_panel_history, btn_gcode_clicked);  
            } 
            break; 

            default:
                break;
        }   

        if (HISTORY_REFRESH_ING != print_history_file_list->refresh_type)
        {
            ui_panel_add_refresh_button(ui_panel_history);
        }  

        PRINT_SCREEN_HISTORY("print_history_file_list->refresh_type=%02x",print_history_file_list->refresh_type);
        
        print_history_file_list->refresh_type=HISTORY_REFRESH_NONE;
    } else { 
        s_ui_panel_title=NULL; 
        if (HISTORY_REFRESH_ONLY_CLOUD == print_history_file_list->refresh_type)
        {
            ui_panel_create_only_cloud(ui_panel_history);
            
            print_history_file_list->refresh_type=HISTORY_REFRESH_NONE;
        }
        else
        {
            ui_panel_create_not_exist(ui_panel_history);

            ui_panel_add_refresh_button(ui_panel_history);
        }
    } 
}
