#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"
//#include "usb_host_msc/usb_host_msc.h"

#define SW_PRINT_PRINTER_USB 0

#if SW_PRINT_PRINTER_USB && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "ui_u-disk"; 
#define PRINT_PRINTER_USB(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_PRINTER_USB(...)
#endif
 
static lv_obj_t * ui_panel_usb = NULL;
static lv_obj_t * ui_panel_uploading = NULL;
static lv_obj_t * ui_panel_tasks = NULL;
static lv_obj_t * ui_label_task = NULL;
static lv_obj_t * ui_label_title = NULL;
static lv_obj_t * ui_label_speed = NULL;
static lv_obj_t * ui_panel_task_info[BAMBU_PRINTER_MAX_NUM];
static ui_ftps_t ui_ftps = UI_FTPS_UPLOAD_INIT;

static lv_obj_t * s_ui_label_not_insert = NULL;
static lv_obj_t * s_ui_panel_title = NULL;
extern lv_obj_t * ui_top_get_label_u_disk(void);
 

ui_ftps_t ui_get_ftps_status(void) {
    return ui_ftps;
}

void ui_set_ftps_status(ui_ftps_t status) {
    ui_ftps = status;
}

void ui_panel_del_uploading(void) {
    lv_obj_del(ui_panel_uploading);
    ui_panel_uploading = NULL;
    ui_panel_tasks = NULL;
    ui_label_task = NULL;
    ui_label_title = NULL;
    ui_label_speed = NULL;
    memset(ui_panel_task_info, 0, sizeof(ui_panel_task_info));
    ui_ftps = UI_FTPS_UPLOAD_INIT;
}


enum {
    UI_POPUP_BTN_PRINT_CANCEL,
    UI_POPUP_BTN_PRINT_ABORT,
};

static void btn_popup_abort_clicked(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt) {
    switch (btn_id) {
        case UI_POPUP_BTN_PRINT_ABORT:            
            if (ui_panel_uploading != NULL) { 
                ftps_upload_print_require(FTPS_UPLOAD_ABORT, NULL, NULL);  
                lv_obj_t * panel = ui_panel_create(ui_panel_uploading, 15, lv_color_hex(0x575757)); 
                PRINT_PRINTER_USB("panel=%x",(unsigned int)panel);
                lv_obj_set_size(panel, 600, 380);
                lv_obj_set_align(panel, LV_ALIGN_CENTER);
                lv_scanning_spin_create(panel, RS_TRANSLATE(K_WIFI_C_WAIT_CANCEL));
            } 
            break;

        default:
            break;
    }
}

static ui_popup_t popup_abort = {
    .text = K_POP_TIP_PRINT_ABORT,
    .btn_num = 2,
    .btn_text = {K_BTN_CANCEL, K_BTN_ABORT},
    .btn_id = {UI_POPUP_BTN_PRINT_CANCEL, UI_POPUP_BTN_PRINT_ABORT},
    .popup_cb = btn_popup_abort_clicked,
     
};

static void btn_abort_clicked(lv_event_t * e) {
    ui_panel_create_popup(&popup_abort, NULL);
}


lv_obj_t * ui_panel_add_one_task(lv_obj_t * parent, uint8_t index) {
    lv_obj_t * panel = ui_panel_create(parent, 15, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 560, 60);

    lv_obj_t * panel_index = ui_panel_create_index(panel, index, 20, lv_color_hex(0xFFFFFF));
    lv_obj_set_style_text_color(panel_index, lv_color_hex(0x575757), LV_PART_MAIN);
    lv_obj_align(panel_index, LV_ALIGN_LEFT_MID, 20, -13); 
    nvs_config_t * nvs = bambu_get_nvs_config(index); 
    lv_obj_t * label_printer = lv_label_create(panel);
    lv_obj_align(label_printer, LV_ALIGN_LEFT_MID, 48, -13);
    lv_label_set_text_static(label_printer, nvs->name);
    lv_obj_set_width(label_printer, 160);
    lv_obj_set_style_text_font(label_printer,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT);

    lv_obj_t * label_status = lv_label_create(panel);
    lv_obj_align(label_status, LV_ALIGN_CENTER, 0, -13);
    lv_label_set_text(label_status, RS_TRANSLATE(K_FILE_S_WAITING));
    ui_obj_set_type(label_status, UI_TYPE_STATUS);

    lv_obj_t * bar = lv_bar_create(panel);
    lv_obj_set_size(bar, 528, 16);
    lv_obj_align(bar, LV_ALIGN_BOTTOM_MID, 0, -13);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(bar, 188, LV_PART_MAIN);
    lv_obj_set_style_bg_color(bar, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_INDICATOR);
    lv_bar_set_range(bar, 0, 100);
    lv_bar_set_value(bar, 0, LV_ANIM_OFF);
    ui_obj_set_type(bar, UI_TYPE_BAR);

    lv_obj_t * label_speed = lv_label_create(panel);
    lv_obj_align(label_speed, LV_ALIGN_RIGHT_MID, -20, -13);
    lv_label_set_text(label_speed, "--/--");
    ui_obj_set_type(label_speed, UI_TYPE_SPEED);

    return panel;
}

void ui_panel_create_uploading(void) {
    if (ui_panel_uploading != NULL) return;

    ui_panel_uploading = ui_panel_create(ui_screen_main, 0, lv_color_hex(0x000000));
    lv_obj_set_style_bg_opa(ui_panel_uploading, 100, LV_PART_MAIN);
    lv_obj_set_size(ui_panel_uploading, 800, 480);

    lv_obj_t * panel = ui_panel_create(ui_panel_uploading, 15, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 600, 380);
    lv_obj_set_align(panel, LV_ALIGN_CENTER);

    ui_panel_tasks = ui_panel_create(panel, 15, lv_color_hex(0x838383));
    lv_obj_set_style_pad_ver(ui_panel_tasks, 10, LV_PART_MAIN);
    lv_obj_set_size(ui_panel_tasks, 580, 290);
    lv_obj_align(ui_panel_tasks, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_set_flex_flow(ui_panel_tasks, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_panel_tasks, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(ui_panel_tasks, 10, LV_PART_MAIN);
    ui_ftps = UI_FTPS_UPLOAD_INIT;

    ui_label_title = lv_label_create(panel);
    lv_obj_align(ui_label_title, LV_ALIGN_LEFT_MID, 20, -170);
    lv_label_set_text(ui_label_title, "");
    lv_obj_set_width(ui_label_title, 430);
    lv_obj_set_style_text_font(ui_label_title,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT);

    ui_label_task = lv_label_create(panel);
    lv_obj_align(ui_label_task, LV_ALIGN_LEFT_MID, 20, -135);
    lv_label_set_text(ui_label_task, "");

    lv_obj_t * panel_network = ui_panel_create(panel, 0, lv_color_hex(0x575757));
    lv_obj_set_size(panel_network, 120, LV_SIZE_CONTENT);
    lv_obj_align(panel_network, LV_ALIGN_RIGHT_MID, -20, -170);
    lv_obj_set_flex_flow(panel_network, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(panel_network, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_t * img_network = lv_img_create(panel_network);
    lv_img_set_src(img_network, &ui_img_network_speed_png);
    ui_label_speed = lv_label_create(panel_network);
    lv_label_set_text(ui_label_speed, "--KB/s");

    lv_obj_t * btn = ui_btn_label_create(panel, 90, 35, 5, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(K_BTN_STOP_ALL));
    lv_obj_align(btn, LV_ALIGN_RIGHT_MID, -20, -135);    
    lv_obj_add_event_cb(btn, btn_abort_clicked, LV_EVENT_CLICKED, NULL);
}

static void btn_gcode_clicked(lv_event_t * e) 
{
    /*get file info from event user data*/
    file_gcode_t *file_info = (file_gcode_t *)lv_event_get_user_data(e);

    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * label = ui_obj_get(btn, UI_TYPE_LABEL_GCODE); 

    PRINT_PRINTER_USB("file_info->type=%02x,label=%x",file_info->type,(unsigned int)label);

    if (FILE_TYPE_3MF == file_info->type)
    {
        ui_screen_create_print_task(lv_label_get_text(label), UI_TYPE_PRINT_FROM_USB); 
    }
    else if (FILE_TYPE_DIR == file_info->type)
    {
        usb_3mf_list->file_task_msg.id = FILT_TASK_MSG_CHANGE_DIR; 
        strlcpy(usb_3mf_list->file_task_msg.data, file_info->name, sizeof(usb_3mf_list->file_task_msg.data));
        usb_3mf_list->file_task_msg.is_root = false;

        // xTaskNotify((TaskHandle_t )  usb_3mf_list->file_task_msg.task_handle, //任务句柄，指明往哪个任务发送消息，很重要
        //                     (uint32_t )      &usb_3mf_list->file_task_msg,    //发送的消息
        //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
        //                     ); 
    } 
    else if (FILE_TYPE_ROOT == file_info->type)
    {
        usb_3mf_list->file_task_msg.id = FILT_TASK_MSG_CHANGE_DIR; 
        usb_3mf_list->file_task_msg.is_root = true;

        // xTaskNotify((TaskHandle_t )  usb_3mf_list->file_task_msg.task_handle, //任务句柄，指明往哪个任务发送消息，很重要
        //                     (uint32_t )      &usb_3mf_list->file_task_msg,    //发送的消息
        //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
        //                     ); 
    }
}

static void ui_usb_panel_create_not_insert(lv_obj_t *parent)
{
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, RS_TRANSLATE(K_TIP_NOT_INSERT_USB_FLASH));
    s_ui_label_not_insert = label;
    rs_add_translate_cb(s_ui_label_not_insert,RS_TRANSLATE_DEFAULT_CB,(void *)K_TIP_NOT_INSERT_USB_FLASH,KEY_NUMBER);  
}

lv_obj_t * ui_panel_create_usb(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create_files_list(parent);
    ui_obj_set_type(panel, UI_TYPE_SCREEN_PRINT_USB_FLASH_DRIVER);
    lv_obj_add_flag(panel, LV_OBJ_FLAG_HIDDEN);
    
    ui_panel_usb = panel;
    s_ui_panel_title=NULL;
    ui_usb_panel_create_not_insert(ui_panel_usb);

    return panel;
}
 
void ui_files_list_usb_refresh_require(uint8_t type) 
{
    if (type>=USB_REFRESH_MAX)
    {
        return;
    }
    
    usb_3mf_list->refresh_type = type; 
    
    PRINT_PRINTER_USB("ui_files_list_usb_refresh_require usb_refresh=%02x",usb_3mf_list->refresh_type);
}

static const ui_popup_t popup_error = {
    .text = K_TIP_FAILD_UPLOAD,
    .btn_num = 1,
    .btn_text = {K_BTN_CLOSE},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
     
};

void lv_loop_files_upload_usb(void) {
    if (ui_panel_uploading == NULL) return;
    ftps_upload_info_t * p_info = ftps_get_upload_info();
    static uint8_t task_cur = 0;
    if (p_info->ftps_status == FTPS_END) {
        ui_panel_del_uploading();
        return;
    }
    if (ui_ftps == UI_FTPS_UPLOAD_INIT)
        return;

    if (ui_ftps == UI_FTPS_UPLOAD_CREATE) {
        task_cur = 0;
        for (uint8_t i = 0; i < p_info->task_total; i++) {
            ui_panel_task_info[i] = ui_panel_add_one_task(ui_panel_tasks, p_info->task[i].index);
        }
        lv_obj_t * label_status = ui_obj_get(ui_panel_task_info[task_cur], UI_TYPE_STATUS);
        lv_label_set_text_static(label_status, RS_TRANSLATE(K_FILE_S_TRANSMITTING));
        lv_label_set_text_fmt(ui_label_task, RS_TRANSLATE(K_FILE_S_PRINTERS_IN_SYNC), task_cur + 1, p_info->task_total);
    }

    if (lv_label_get_text(ui_label_title) != p_info->filename) {
        lv_label_set_text_static(ui_label_title, p_info->filename);
    }
    if (task_cur != p_info->task_cur) {
        lv_obj_t * label_status = ui_obj_get(ui_panel_task_info[task_cur], UI_TYPE_STATUS);
        if (p_info->task[task_cur].status == FTPS_ERR) { 
            ui_panel_create_popup(&popup_error, bambu_get_mqtt(p_info->task[task_cur].index)); 
        }
        if (p_info->task[task_cur].status != FTPS_OK) {
            lv_label_set_text_static(label_status, RS_TRANSLATE(K_FILE_S_FAILED));
        } else {            
            lv_label_set_text_static(label_status, RS_TRANSLATE(K_FILE_S_PRINTING));
        }
        if (p_info->task_cur < p_info->task_total) {
            task_cur = p_info->task_cur;
            label_status = ui_obj_get(ui_panel_task_info[task_cur], UI_TYPE_STATUS);
            lv_label_set_text_static(label_status, RS_TRANSLATE(K_FILE_S_TRANSMITTING));
            lv_obj_scroll_to_view(ui_panel_task_info[task_cur], LV_ANIM_ON);
            lv_label_set_text_fmt(ui_label_task, RS_TRANSLATE(K_FILE_S_PRINTERS_IN_SYNC), task_cur + 1, p_info->task_total);
        }
    }

    static uint32_t ms = 0;
    if (ms < millis() || ui_ftps == UI_FTPS_UPLOADED_ONE_TASK) {
        ms = millis() + 1000; // 1s
        static uint32_t size_cur = 0;
        static uint32_t diff_cur = 0;

        uint32_t diff = (p_info->size_cur > size_cur) ? (p_info->size_cur - size_cur) : 0;
        if (diff_cur != diff) {
            diff_cur = diff;
            char buf_size[10];
            file_size_to_string(buf_size, sizeof(buf_size), diff_cur);
            lv_label_set_text_fmt(ui_label_speed, "%s/s", buf_size);
        }

        static uint32_t size_total = 0;
        if (size_cur != p_info->size_cur ||
            size_total != p_info->size_total) {
            size_cur = p_info->size_cur;
            size_total = p_info->size_total;
            char buf_cur[10];
            char buf_total[10];
            file_size_to_string(buf_cur, sizeof(buf_cur), size_cur);
            file_size_to_string(buf_total, sizeof(buf_total), size_total);
            lv_obj_t * label = ui_obj_get(ui_panel_task_info[p_info->task_cur], UI_TYPE_SPEED);
            lv_label_set_text_fmt(label, "%s/%s", buf_cur, buf_total);
            if (size_total != 0) {
                lv_obj_t * bar = ui_obj_get(ui_panel_task_info[p_info->task_cur], UI_TYPE_BAR);
                // (uint64_t) to prevent overflow after * 100
                lv_bar_set_value(bar, (uint64_t)size_cur * 100 / size_total, LV_ANIM_OFF);
            }
        }
    }
    ui_ftps = UI_FTPS_UPLOAD_CREATE_OK;
}
 
lv_obj_t * ui_gcodes_list_create_thumbnail_card(file_list_3mf_t *file_3mf_list, lv_obj_t * parent, lv_event_cb_t cb)  
{
    char buf[128]; 
    if (file_3mf_list->file_count<0)
    {
        file_3mf_list->file_count=0;
        /*如果文件为空则显示为空*/
    } 

    file_3mf_list->panel = NULL;

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
    //lv_obj_set_style_bg_color(label,lv_color_hex(0xff00),LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(label,LV_OPA_COVER,LV_STATE_DEFAULT);

    /* must be static not const*/
    static lv_point_t v_line_points[] = { {0, 0}, {0, 23}};
    lv_obj_t * v_line = ui_line_create(panel_title, v_line_points, 2, 1, text_c);
    lv_obj_align(v_line, LV_ALIGN_LEFT_MID, 160, 0);  

    /*再创建一个目录名称*/  
    label = lv_label_create(panel_title);
    lv_label_set_text_static(label, file_3mf_list->current_path);
    PRINT_PRINTER_USB("create path_name[%s]",file_3mf_list->current_path);
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
 
    lv_obj_t *list = ui_panel_create(parent, 5, lv_color_hex(0x444444));//0x687588 0x505050
    lv_obj_set_size(list, w, h - 35);
    //lv_obj_align(list, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(list, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_clip_corner(list, true, LV_PART_MAIN);
    //lv_obj_set_style_pad_top(list,10,0);

    lv_obj_set_flex_flow(list, LV_FLEX_FLOW_ROW_WRAP);//直接可以时间反序，LV_FLEX_FLOW_ROW_WRAP_REVERSE
    lv_obj_set_flex_align(list, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_row(list, 8, LV_PART_MAIN);
    lv_obj_set_style_pad_column(list, 26, LV_PART_MAIN);
    //lv_obj_set_style_bg_opa(list, LV_OPA_TRANSP , LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(list,16,0);
    lv_obj_set_style_pad_left(list,36,0); 
    
    //lv_obj_set_style_bg_color(list, lv_color_hex(0xff4444) , LV_STATE_DEFAULT);

    for (uint8_t i = 0; i < num; i++)
    {
        if (FILE_TYPE_3MF != files[i].type)
        {
            continue;
        }

        lv_obj_t *panel_finfo = ui_panel_create(list, 5, lv_color_hex(0x808080));
        lv_obj_set_size(panel_finfo, 134, (134+40));
        lv_obj_set_style_pad_top(panel_finfo,4,0);
        lv_obj_set_flex_flow(panel_finfo, LV_FLEX_FLOW_COLUMN);//直接可以时间反序，LV_FLEX_FLOW_ROW_WRAP_REVERSE
        lv_obj_set_flex_align(panel_finfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_style_pad_row(panel_finfo, 0, LV_PART_MAIN);
        lv_obj_set_style_pad_column(panel_finfo, 0, LV_PART_MAIN);
        lv_obj_set_scroll_dir(panel_finfo,LV_DIR_NONE);
        //lv_obj_set_style_bg_opa(panel_finfo, LV_OPA_TRANSP , LV_STATE_DEFAULT);
        //SCREEN_PRINT("ui_btn_img_create [%x],w=%d,h=%d",(unsigned int)files[i].img_data.data,(int)files[i].img_data.header.w,(int)files[i].img_data.header.h);
        lv_obj_t * btn = ui_btn_img_create(panel_finfo,128,128,5,lv_color_hex(CONFIG_3MF_THUMBNAIL_BG_COLOR),&files[i].img_data);
        lv_obj_clear_flag(btn,LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(btn,LV_OBJ_FLAG_EVENT_BUBBLE);
        //lv_obj_set_style_bg_opa(btn, LV_OPA_TRANSP , LV_STATE_DEFAULT);
        //lv_obj_align(btn, LV_ALIGN_TOP_MID, 0, 0);
        lv_obj_t * label_name = lv_label_create(panel_finfo);
        //lv_obj_align_to(label_name, btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0); 
 
        /*如所需时间 和果重量 有效 则使用，无效则不使用*/
        #if 0
        if (ut_str_not_blank(files[i].print_need_time))
        {
            snprintf(buf, sizeof(buf), "%s min", files[i].print_need_time); 

            lv_label_set_text(label_name, buf);
        }
        else 
        #endif
        {
            lv_label_set_text_static(label_name, files[i].name);
        }
        
        lv_obj_set_width(label_name, 128);
        lv_label_set_long_mode(label_name, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(label_name,LV_TEXT_ALIGN_CENTER,0);
        ui_obj_set_type(label_name, UI_TYPE_LABEL_GCODE);
        lv_obj_set_style_text_font(label_name,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT); 

        lv_obj_t * label_data = lv_label_create(panel_finfo);
        //lv_obj_align(label_data, LV_ALIGN_LEFT_MID, 404-128, 0);
        #if 0
        if (ut_str_not_blank(files[i].weight))
        {
            snprintf(buf, sizeof(buf), "%s g", files[i].weight); 
        } 
        else
        #endif
        {
            if (files[i].time.hour == 0 &&
                files[i].time.min == 0 &&
                files[i].time.sec == 0)
                snprintf(buf, sizeof(buf), "%d/%d/%d", files[i].time.year, files[i].time.month, files[i].time.day);
            else if (files[i].time.year == 0)
                snprintf(buf, sizeof(buf), "----/%d/%d %d:%02d", files[i].time.month, files[i].time.day, files[i].time.hour, files[i].time.min);
            else
                snprintf(buf, sizeof(buf), "%d/%d/%d %d:%02d", files[i].time.year, files[i].time.month, files[i].time.day, files[i].time.hour, files[i].time.min);
        } 
        
        lv_label_set_text(label_data, buf);
        lv_obj_set_width(label_data, 128);
        lv_label_set_long_mode(label_data, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(label_data,LV_TEXT_ALIGN_CENTER,0);
        lv_obj_add_event_cb(panel_finfo, cb, LV_EVENT_CLICKED, (void *)&files[i]);

        files[i].btn = btn; 
        files[i].panel = panel_finfo;
    }  
    
    file_3mf_list->panel = list;

    return panel_title;
}

static void btn_change_show_mode_clicked(lv_event_t * e) 
{ 
    usb_3mf_list->file_task_msg.id = (FILE_SHOW_TYPE_NORMAL == usb_3mf_list->show_type)?FILT_TASK_MSG_CHANGE_TO_THUMBNAIL:FILT_TASK_MSG_CHANGE_TO_NORMAL;
    
    // xTaskNotify((TaskHandle_t )  t_handle_usb, //任务句柄，指明往哪个任务发送消息，很重要
    //                     (uint32_t )      &usb_3mf_list->file_task_msg,    //发送的消息
    //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
    //                     ); 
}

static lv_obj_t *panel_loading = NULL;

static void btn_refresh_clicked(lv_event_t * e) 
{ 
    usb_3mf_list->file_task_msg.id = FILT_TASK_MSG_FILE_REFRESH;
    
    // xTaskNotify((TaskHandle_t )  t_handle_usb, //任务句柄，指明往哪个任务发送消息，很重要
    //                     (uint32_t )      &usb_3mf_list->file_task_msg,    //发送的消息
    //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
    //                     ); 
}

void lv_loop_files_list_usb(void) {
    if (usb_3mf_list == NULL) return;
    lv_loop_files_upload_usb();

    if (ui_panel_usb == NULL) return;

    static uint32_t check_clear_loading = 0; 

    if (check_clear_loading < millis())
    {
        check_clear_loading = millis()+1000;

        PRINT_PRINTER_USB("lv_loop_files_list_usb refresh_type=%02x",usb_3mf_list->refresh_type);
        if (panel_loading)
        {
            /*如果USB那边加载完成了，但是这边刚好清除了导致了不同步，然后一直显示加载中*/
            if ((USB_REFRESH_NONE == usb_3mf_list->refresh_type)
                && (true == usb_3mf_list->is_list_ok))
            {
                PRINT_PRINTER_USB("fix the refresh type");
                usb_3mf_list->refresh_type = usb_3mf_list->show_type;
            }

            /*如果一直处于*/
        }
    }
 
    if (usb_3mf_list->refresh_type == USB_REFRESH_NONE) return;
    
    panel_loading = NULL;
    lv_obj_clean(ui_panel_usb);

    if (usb_3mf_list->is_inserted) 
    { 
        s_ui_label_not_insert = NULL;
        
        switch (usb_3mf_list->refresh_type) 
        {
            case USB_REFRESH_ING:
            {
                PRINT_PRINTER_USB("USB_REFRESH_ING");
                s_ui_panel_title=NULL;
                panel_loading = lv_scanning_spin_create(ui_panel_usb, RS_TRANSLATE(K_LOADING)); 
            }
            break; 

            case USB_REFRESH_OK_NORMAL:
            {
                s_ui_panel_title = ui_gcodes_list_create(usb_3mf_list, ui_panel_usb, btn_gcode_clicked);  
            } 
            break;

            case USB_REFRESH_OK_THUMBNAIL:
            {
                s_ui_panel_title = ui_gcodes_list_create_thumbnail_card(usb_3mf_list, ui_panel_usb, btn_gcode_clicked); 
            } 
            break;

            default:
                break;
        }   

        if (USB_REFRESH_ING != usb_3mf_list->refresh_type)
        {
            lv_obj_t * btn_refresh = ui_btn_img_create(ui_panel_usb, 80, 80, LV_RADIUS_CIRCLE, lv_color_hex(LV_32BIT_BTT_RED), LV_SYMBOL_REFRESH);
            lv_obj_add_flag(btn_refresh, LV_OBJ_FLAG_FLOATING);
            lv_obj_align(btn_refresh, LV_ALIGN_BOTTOM_RIGHT, -13, -13);
            lv_obj_set_style_text_font(btn_refresh, &opensansb24, 0);
            lv_obj_add_event_cb(btn_refresh, btn_refresh_clicked, LV_EVENT_CLICKED, NULL);

            if (usb_3mf_list->file_3mf_count > 0)
            {
                lv_obj_t * btn_change_mode = ui_btn_img_create(ui_panel_usb, 80, 80, LV_RADIUS_CIRCLE, lv_color_hex(LV_32BIT_BTT_RED), (FILE_SHOW_TYPE_NORMAL == usb_3mf_list->show_type)?LV_SYMBOL_IMAGE:LV_SYMBOL_FILE);
                lv_obj_add_flag(btn_change_mode, LV_OBJ_FLAG_FLOATING);
                lv_obj_align(btn_change_mode, LV_ALIGN_BOTTOM_RIGHT, -113, -13);
                lv_obj_set_style_text_font(btn_change_mode, &opensansb24, 0);
                lv_obj_add_event_cb(btn_change_mode, btn_change_show_mode_clicked, LV_EVENT_CLICKED, NULL);
            }
        }  

        PRINT_PRINTER_USB("usb_3mf_list->refresh_type=%02x",usb_3mf_list->refresh_type);
        
        usb_3mf_list->refresh_type=USB_REFRESH_NONE;
    } else { 
        s_ui_panel_title=NULL;
        ui_usb_panel_create_not_insert(ui_panel_usb);
    } 
}
