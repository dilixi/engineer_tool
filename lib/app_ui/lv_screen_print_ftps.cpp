#include "lv_ui_overlay.h"
#include "bambu_mqtt.h"
#include "printer_group.h"

static lv_obj_t * ui_panel_ftps = NULL;
static lv_obj_t * s_ui_label_not_insert = NULL;
static lv_obj_t * s_ui_panel_title = NULL; 

static void btn_gcode_clicked(lv_event_t * e) {
    #if 0
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * label = ui_obj_get(btn, UI_TYPE_LABEL_GCODE);
    ui_screen_create_print_task(lv_label_get_text(label), UI_TYPE_PRINT_FROM_PRINTER); 
    #else
    /*get file info from event user data*/
    file_gcode_t *file_info = (file_gcode_t *)lv_event_get_user_data(e);

    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * label = ui_obj_get(btn, UI_TYPE_LABEL_GCODE);  

    if (FILE_TYPE_3MF == file_info->type)
    {
        ui_screen_create_print_task(lv_label_get_text(label), UI_TYPE_PRINT_FROM_PRINTER); 
    }
    else if (FILE_TYPE_DIR == file_info->type)
    {
        printer_3mf_list->file_task_msg.id = FILT_TASK_MSG_CHANGE_DIR; 
        strlcpy(printer_3mf_list->file_task_msg.data, file_info->name, sizeof(printer_3mf_list->file_task_msg.data));
        printer_3mf_list->file_task_msg.is_root = false;

        // xTaskNotify((TaskHandle_t )  printer_3mf_list->file_task_msg.task_handle, //任务句柄，指明往哪个任务发送消息，很重要
        //                     (uint32_t )      &printer_3mf_list->file_task_msg,    //发送的消息
        //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
        //                     ); 
    } 
    else if (FILE_TYPE_ROOT == file_info->type)
    {
        printer_3mf_list->file_task_msg.id = FILT_TASK_MSG_CHANGE_DIR; 
        printer_3mf_list->file_task_msg.is_root = true;

        // xTaskNotify((TaskHandle_t )  printer_3mf_list->file_task_msg.task_handle, //任务句柄，指明往哪个任务发送消息，很重要
        //                     (uint32_t )      &printer_3mf_list->file_task_msg,    //发送的消息
        //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
        //                     ); 
    }
    #endif
}

static void btn_refresh_clicked(lv_event_t * e) {
    ftps_refresh_list_require();
}

lv_obj_t * ui_panel_create_ftps(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create_files_list(parent);
    ui_obj_set_type(panel, UI_TYPE_SCREEN_PRINT_MICROSDCARD);
    lv_obj_add_flag(panel, LV_OBJ_FLAG_HIDDEN);

    ui_panel_ftps = panel;

    return panel;
}


static volatile bool ftps_refresh = true;

void ui_files_list_ftps_refresh_require(void) {
    ftps_refresh = true;
}

static void btn_change_show_mode_clicked(lv_event_t * e) 
{ 
    printer_3mf_list->file_task_msg.id = (FILE_SHOW_TYPE_NORMAL == printer_3mf_list->show_type)?FILT_TASK_MSG_CHANGE_TO_THUMBNAIL:FILT_TASK_MSG_CHANGE_TO_NORMAL;
    
    // xTaskNotify((TaskHandle_t )  t_handle_ftps, //任务句柄，指明往哪个任务发送消息，很重要
    //                     (uint32_t )      &printer_3mf_list->file_task_msg,    //发送的消息
    //                     (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
    //                     ); 
}

static bambu_mqtt_t * mqtt = NULL; 

void lv_loop_files_list_ftps(void) {
    if (ui_panel_ftps == NULL) return;
    if (NULL == printer_3mf_list) return;

    if (mqtt != bambu_mqtt_master) 
    {
        mqtt = bambu_mqtt_master;
        printer_3mf_list->is_inserted = !mqtt->bambu_data.sdcard; // require a refresh
    }
 
    if (printer_3mf_list->is_inserted != mqtt->bambu_data.sdcard) {
        printer_3mf_list->is_inserted = mqtt->bambu_data.sdcard;
        if (printer_3mf_list->is_inserted) {
            ftps_refresh_list_require();
        } else {
            ftps_refresh = true;
        }
    }
    // if (strcmp(ui_top_get_target_printer(), mqtt->nvs_config.name) != 0) {
    //     ui_top_set_target_printer(mqtt->nvs_config.name);
    // }
    if (ftps_refresh == false) return;
    ftps_refresh = false;
    lv_obj_clean(ui_panel_ftps); 
 
    if (printer_3mf_list->is_inserted) 
    {
        s_ui_label_not_insert = NULL;

        switch (ftps_get_list_status()) 
        {
            case FTPS_REFRESH:
            {
                s_ui_panel_title=NULL;
                lv_scanning_spin_create(ui_panel_ftps, RS_TRANSLATE(K_LOADING));
                break;
            } 
            
            case FTPS_OK: 
            {
                /*云通信时，检查ftp的登录结果，如果登录失败则显示请检查IP*/
                bool ftp_is_ok=true;

                if (mqtt->nvs_config.account_type)
                {
                    /*因为本地模式时连接上MQTT了说明 ip和 accesscode 都正确*/
                    ftp_is_ok=(FTPS_LOGIN_OK == mqtt->ftp_res);
                } 

                /*如果遍历目录OK则显示，否则报错*/  
                printf("file_3mf_count=%d,show_type=%02x\r\n",printer_3mf_list->file_3mf_count, printer_3mf_list->show_type);

                if (ftp_is_ok)
                {
                    if (FILE_SHOW_TYPE_NORMAL == printer_3mf_list->show_type)
                    {
                        s_ui_panel_title = ui_gcodes_list_create(printer_3mf_list, ui_panel_ftps, btn_gcode_clicked);
                    }
                    else if (FILE_SHOW_TYPE_THUMBNAIL == printer_3mf_list->show_type)
                    {
                        s_ui_panel_title = ui_gcodes_list_create_thumbnail_card(printer_3mf_list, ui_panel_ftps, btn_gcode_clicked); 
                    } 

                    if (printer_3mf_list->file_3mf_count > 0)
                    {
                        lv_obj_t * btn_change_mode = ui_btn_img_create(ui_panel_ftps, 80, 80, LV_RADIUS_CIRCLE, lv_color_hex(LV_32BIT_BTT_RED), (FILE_SHOW_TYPE_NORMAL == printer_3mf_list->show_type)?LV_SYMBOL_IMAGE:LV_SYMBOL_FILE);
                        lv_obj_add_flag(btn_change_mode, LV_OBJ_FLAG_FLOATING);
                        lv_obj_align(btn_change_mode, LV_ALIGN_BOTTOM_RIGHT, -113, -13);
                        lv_obj_set_style_text_font(btn_change_mode, &opensansb24, 0);
                        lv_obj_add_event_cb(btn_change_mode, btn_change_show_mode_clicked, LV_EVENT_CLICKED, NULL);
                    }
                }
                else 
                { 
                    lv_obj_t * label = lv_label_create(ui_panel_ftps);
                    lv_obj_set_align(label, LV_ALIGN_CENTER);  
                    s_ui_label_not_insert = label;
                    rs_add_translate_cb(s_ui_label_not_insert,RS_TRANSLATE_DEFAULT_CB,(void *)K_TIP_FTP_IP_INVALID,KEY_NUMBER); 
                    s_ui_panel_title=NULL;  
                } 

                lv_obj_t * btn_refresh = ui_btn_img_create(ui_panel_ftps, 80, 80, LV_RADIUS_CIRCLE, lv_color_hex(LV_32BIT_BTT_RED), LV_SYMBOL_REFRESH);
                lv_obj_add_flag(btn_refresh, LV_OBJ_FLAG_FLOATING);
                lv_obj_align(btn_refresh, LV_ALIGN_BOTTOM_RIGHT, -13, -13);
                lv_obj_set_style_text_font(btn_refresh, &opensansb24, 0);
                lv_obj_add_event_cb(btn_refresh, btn_refresh_clicked, LV_EVENT_CLICKED, NULL);
                
                break;
            }

            default:
                break;
        } 
    } else {
        lv_obj_t * label = lv_label_create(ui_panel_ftps);
        lv_obj_set_align(label, LV_ALIGN_CENTER); 
        lv_label_set_text(label,RS_TRANSLATE(K_TIP_NOT_INSERT_SDCARD));
        s_ui_label_not_insert = label;
        rs_add_translate_cb(s_ui_label_not_insert,RS_TRANSLATE_DEFAULT_CB,(void *)K_TIP_NOT_INSERT_SDCARD,KEY_NUMBER); 
        s_ui_panel_title=NULL;
    }  
}
