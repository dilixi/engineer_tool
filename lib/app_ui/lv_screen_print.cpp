#include "lv_ui_overlay.h"

#define SW_PRINT_SCREEN_PRINT 1

#if SW_PRINT_SCREEN_PRINT && SW_PRINT_ALL 
#define PRINT_SCREEN_PRINT printf
#else` 
#define PRINT_SCREEN_PRINT(...)
#endif 

const char * file_size_to_string(char * buf, uint32_t max_len, uint32_t size) {
    if (size < KB_SIZE)
        snprintf(buf, max_len, "%ldB", size);
    else if (size < MB_SIZE)
        snprintf(buf, max_len, "%.1fKB", (float)size / KB_SIZE);
    else if (size < GB_SIZE)
        snprintf(buf, max_len, "%.1fMB", (float)size / MB_SIZE);
    else
        snprintf(buf, max_len, "%.1fGB", (float)size / GB_SIZE);
    return buf;
}

void ui_gcode_list_add_file(lv_obj_t *parent, lv_color_t text_color,lv_color_t bg_color, file_gcode_t * file_info, lv_event_cb_t cb)
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

    if (FILE_TYPE_3MF == file_info->type)
    {
        lv_label_set_text(label_icon, LV_SYMBOL_FILE);
    }
    else if (FILE_TYPE_ROOT == file_info->type)
    {
        lv_label_set_text(label_icon, LV_SYMBOL_LEFT);
    }
    else
    {
        lv_label_set_text(label_icon, LV_SYMBOL_DIRECTORY);
    }  

    lv_obj_set_style_text_font(label_icon,&opensansb16,LV_STATE_DEFAULT); 
 
    lv_obj_t * label_name = lv_label_create(btn); 
    lv_obj_set_width(label_name, 365);
    // lv_obj_set_style_bg_color(label_name, lv_color_hex(0xFF0000), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(label_name, 255, LV_PART_MAIN);
    if (FILE_TYPE_ROOT == file_info->type)
    {
        lv_obj_align(label_name, LV_ALIGN_LEFT_MID, 34, 0);   
        lv_label_set_text(label_name, "");
    }
    else if (FILE_TYPE_DIR == file_info->type)
    {
        lv_obj_align(label_name, LV_ALIGN_LEFT_MID, 34, 0);
        lv_label_set_text_static(label_name, file_info->name);
    }
    else
    {
        lv_obj_align(label_name, LV_ALIGN_LEFT_MID, 27, 0);
        lv_label_set_text_static(label_name, file_info->name);
    } 

    lv_label_set_long_mode(label_name, LV_LABEL_LONG_SCROLL_CIRCULAR);
    ui_obj_set_type(label_name, UI_TYPE_LABEL_GCODE);
 
    lv_obj_t * label_data = lv_label_create(btn);
    lv_obj_align(label_data, LV_ALIGN_LEFT_MID, 404, 0);
    if (file_info->timestamp > 0)
    {
        if (file_info->time.hour == 0 &&
            file_info->time.min == 0 && 
            file_info->time.sec == 0)
            snprintf(buf, sizeof(buf), "%d/%d/%d", file_info->time.year, file_info->time.month, file_info->time.day);
        else if (file_info->time.year == 0)
            snprintf(buf, sizeof(buf), "----/%d/%d %d:%02d", file_info->time.month, file_info->time.day, file_info->time.hour, file_info->time.min);
        else            
            snprintf(buf, sizeof(buf), "%d/%d/%d %d:%02d", file_info->time.year, file_info->time.month, file_info->time.day, file_info->time.hour, file_info->time.min);
        lv_label_set_text(label_data, buf); 
    }
    else if (FILE_TYPE_ROOT == file_info->type)
    { 
        lv_label_set_text(label_data, ""); 
    }
    else
    { 
        snprintf(buf, sizeof(buf), "----/----/---- ----");
        lv_label_set_text(label_data, buf); 
    } 

    if (FILE_TYPE_3MF == file_info->type)
    {
        lv_obj_t * label_size = lv_label_create(btn);
        lv_obj_align(label_size, LV_ALIGN_LEFT_MID, 574, 0);
        file_size_to_string(buf, sizeof(buf), file_info->size);
        lv_label_set_text(label_size, buf);
    } 

    lv_obj_add_event_cb(btn, cb, LV_EVENT_CLICKED, (void *)file_info);  
}

void btn_3mf_file_sorted_by_name_clicked(lv_event_t * e) 
{
    file_list_3mf_t *file_3mf_list = (file_list_3mf_t *)lv_event_get_user_data(e); 

    if (file_3mf_list->sort_type <= SORT_BY_DATA_OLD) 
    { 
        file_3mf_list->file_task_msg.id = FILT_TASK_MSG_SORT_BY_NAME_A_Z;
    }
    else
    {
        file_3mf_list->file_task_msg.id =(SORT_BY_NAME_A_Z==file_3mf_list->sort_type)?FILT_TASK_MSG_SORT_BY_NAME_Z_A:FILT_TASK_MSG_SORT_BY_NAME_A_Z;
    }
 
    // xTaskNotify((TaskHandle_t )  file_3mf_list->file_task_msg.task_handle, //任务句柄，指明往哪个任务发送消息，很重要
    //                     (uint32_t )      &file_3mf_list->file_task_msg,    //发送的消息
    //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
    //                     ); 
} 

void btn_3mf_file_sorted_by_data_clicked(lv_event_t * e) 
{
    file_list_3mf_t *file_3mf_list = (file_list_3mf_t *)lv_event_get_user_data(e); 

    if (file_3mf_list->sort_type >= SORT_BY_NAME_A_Z) 
    { 
        file_3mf_list->file_task_msg.id = FILT_TASK_MSG_SORT_BY_DATE_NEW;
    }
    else
    {
        file_3mf_list->file_task_msg.id =(SORT_BY_DATA_NEW==file_3mf_list->sort_type)?FILT_TASK_MSG_SORT_BY_DATE_OLD:FILT_TASK_MSG_SORT_BY_DATE_NEW;
    }
  
    // xTaskNotify((TaskHandle_t )  file_3mf_list->file_task_msg.task_handle, //任务句柄，指明往哪个任务发送消息，很重要
    //                     (uint32_t )      &file_3mf_list->file_task_msg,    //发送的消息
    //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
    //                     ); 
}
 
lv_obj_t * ui_gcodes_list_create(file_list_3mf_t *file_3mf_list, lv_obj_t * parent, lv_event_cb_t cb)
{
    char buf[128]; 
    
    if (file_3mf_list->file_count<0)
    {
        file_3mf_list->file_count=0;
        /*如果文件为空则显示为空*/
    } 

    int32_t num = file_3mf_list->file_count;
    file_gcode_t * files = file_3mf_list->files;

    const lv_color_t text_c = lv_color_hex(0xFFFFFF);
    const int32_t w = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    const int32_t h = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_HEIGHT).num;
    const lv_color_t bg_c = lv_color_hex(0x575757); // lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_BG_COLOR).color;

    // lv_list_add_text(obj, "Name   Data  Size");
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
    lv_obj_t * label_sort = lv_label_create(label_box);
    lv_obj_set_style_text_font(label_sort, &opensansb16, 0);
    lv_label_set_text(label_sort,((SORT_BY_NAME_A_Z==file_3mf_list->sort_type)?LV_SYMBOL_UP:LV_SYMBOL_DOWN));
    if (file_3mf_list->sort_type <= SORT_BY_DATA_OLD)
    {
        lv_obj_add_flag(label_sort,LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_add_event_cb(label_box, btn_3mf_file_sorted_by_name_clicked, LV_EVENT_CLICKED, (void *)file_3mf_list); 

    lv_obj_t * label = lv_label_create(label_box);  
    rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_FILE_T_NAME,KEY_NUMBER); 
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0); 
    lv_obj_set_width(label_box, 150);  

    /* must be static not const*/
    static lv_point_t v_line_points[] = { {0, 0}, {0, 23}};
    lv_obj_t * v_line = ui_line_create(panel_title, v_line_points, 2, 1, text_c);
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 160, 0);  

    /*再创建一个目录名称*/  
    label = lv_label_create(panel_title);
    lv_label_set_text_static(label, file_3mf_list->current_path);
    PRINT_SCREEN_PRINT("create path_name[%s]",file_3mf_list->current_path);
    lv_obj_set_width(label, 250); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);    

    lv_obj_align(label, LV_ALIGN_LEFT_MID, 168, 0); 
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_LEFT, 0); 
    // lv_obj_set_style_text_color(label,lv_color_hex(0xFFFFFF),0);
    // lv_obj_set_style_bg_color(label,lv_color_hex(0xff4444),0);
    // lv_obj_set_style_bg_opa(label,LV_OPA_100,0);

    label_box = ui_panel_create(panel_title, 5, lv_color_hex(0x444444));
    lv_obj_set_size(label_box, 10, 35);
    lv_obj_set_style_bg_opa(label_box, 0, LV_PART_MAIN); 
    lv_obj_set_style_pad_all(label_box, 0, LV_PART_MAIN);
    lv_obj_set_flex_flow(label_box, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(label_box, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
 
    label_sort = lv_label_create(label_box); 
    lv_obj_set_style_text_font(label_sort, &opensansb16, 0);
    lv_label_set_text(label_sort,((SORT_BY_DATA_NEW==file_3mf_list->sort_type)?LV_SYMBOL_DOWN:LV_SYMBOL_UP));
    if (file_3mf_list->sort_type >= SORT_BY_NAME_A_Z)
    {
        lv_obj_add_flag(label_sort,LV_OBJ_FLAG_HIDDEN);
    }
 
    lv_obj_add_event_cb(label_box, btn_3mf_file_sorted_by_data_clicked, LV_EVENT_CLICKED, (void *)file_3mf_list);

    label = lv_label_create(label_box);

    v_line = ui_line_create(panel_title, v_line_points, 2, 1, text_c);
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 420, 0);  
    rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_FILE_T_DATE,KEY_NUMBER);
    lv_obj_align(label_box, LV_ALIGN_LEFT_MID, 430, 0); 
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_width(label_box, 100);

    /* must be static not const*/
    v_line = ui_line_create(panel_title, v_line_points, 2, 1, text_c);
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 590, 0);
    label = lv_label_create(panel_title); 
    rs_add_translate_cb(label,RS_TRANSLATE_DEFAULT_CB,(void *)K_FILE_T_SIZE,KEY_NUMBER); 
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
    
    /*如果不在根目录则显示 .. 在第一项*/ 
    if (!file_3mf_list_at_root(file_3mf_list))
    { 
        ui_gcode_list_add_file(list,text_c,bg_c,&file_3mf_list->back_folder,cb);
    }
    else
    {
        PRINT_SCREEN_PRINT("file_3mf_list is at root");
    }

    for (uint8_t i=0; i<num; i++) 
    {
        ui_gcode_list_add_file(list,text_c,bg_c,&files[i],cb);
    } 

    return panel_title;
}

lv_obj_t * ui_panel_create_files_list(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 5, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 690, 400);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 19);
    lv_obj_set_style_clip_corner(panel, true, LV_PART_MAIN);

    return panel;
}

static lv_obj_t * top = NULL;

lv_obj_t * ui_top_get_label_target_printer(void) {
    lv_obj_t * btn = lv_obj_get_child(top, 0);
    return lv_obj_get_child(btn, 0);
}

lv_obj_t * ui_top_get_label_u_disk(void) {
    if (!top)
    {
        return NULL;
    }

    lv_obj_t * btn = lv_obj_get_child(top, 1);
    return lv_obj_get_child(btn, 0); 
}

const char * ui_top_get_target_printer(void) {
    return lv_label_get_text(ui_top_get_label_target_printer());
}
// "text" must be static
void ui_top_set_target_printer(const char * text) { 
    if (!ut_str_not_blank((char *)text))
    { 
        lv_label_set_text(ui_top_get_label_target_printer(), "MicroSD Card");/*恢复出厂访问码错误时会变成空的*/
        return;
    }
    lv_label_set_text(ui_top_get_label_target_printer(), text);
}

const ui_btn_ctl_top_t btns[] {
    {"MicroSD Card", UI_TYPE_SCREEN_PRINT_MICROSDCARD,{K_INVALID_ID,}},
    {"USB Flash Drive", UI_TYPE_SCREEN_PRINT_USB_FLASH_DRIVER,{K_FILE_T_USB_FLASH_DRIVER,}},
    {"Print history", UI_TYPE_SCREEN_PRINT_HISTORY,{K_T_FILE_T_HISTORY,}},
};

lv_obj_t * ui_panel_create_print(lv_obj_t * screen) {
    lv_obj_t * panel = ui_panel_create(screen, 0, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 704, 452);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    top = ui_panel_create_top(panel, btns, ARRAY_SIZE(btns));

    lv_obj_t * panel_ftps = ui_panel_create_ftps(panel);
    lv_obj_t * panel_usb = ui_panel_create_usb(panel);
    lv_obj_t * panel_history = ui_panel_create_history(panel);

    ui_btn_top_select(top, UI_TYPE_BTN_TOP_PRINT_MICROSDCARD);
    lv_obj_clear_flag(panel_ftps, LV_OBJ_FLAG_HIDDEN);

    return panel;
}

void ui_screen_create_print(void) {
    lv_obj_t * panel_print = ui_panel_create_print(ui_screen_main);
    ui_obj_set_type(panel_print, UI_TYPE_SCREEN_PRINT);
    lv_obj_add_flag(panel_print, LV_OBJ_FLAG_HIDDEN);
}
