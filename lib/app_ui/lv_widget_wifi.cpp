#include "lv_ui_overlay.h"

#define SW_PRINT_WIDGET_WIFI 0

#if SW_PRINT_WIDGET_WIFI && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "widget wifi"; 
#define PRINT_WIDGET_WIFI(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_WIDGET_WIFI(...)
#endif

static uint8_t retry_cnt_refresh = 0; 
wifi_data_t *g_wifi_data=NULL;

wifi_status_t wifi_get_connect_status(void)
{
    return WIFI_STATUS_MAX;
}

int wifiCalculateSignalLevel(int rssi, int numLevels) {
  if(rssi <= MIN_RSSI) {
    return 0;
  } else if (rssi >= MAX_RSSI) {
    return numLevels - 1;
  } else {
    float inputRange = (MAX_RSSI -MIN_RSSI);
    float outputRange = (numLevels - 1);
    return (int)((float)(rssi - MIN_RSSI) * outputRange / inputRange);
  }
}

void wifi_keyboard_cb_t(lv_obj_t * obj, const char * title, const char * text, void *user_data) {
    uint16_t require = WEB_POST_NULL;
 
    wifi_sync_lock(0);  
    if (obj)
    {
        uint8_t *bssi_check = (uint8_t *)user_data;//lv_obj_get_user_data(obj);
        if (bssi_check)
        {
            if (memcmp(g_wifi_data->nvs_wifi_config.bssid, bssi_check,6) != 0)
            {  
                //wifi_dump_bssid(bssi_check);

                memcpy(g_wifi_data->nvs_wifi_config.bssid, bssi_check, 6);
                require |= WEB_POST_WIFI_CONFIG_STA; 
            }
        }
    }

    if (strcmp(g_wifi_data->nvs_wifi_config.sta_ssid, title) != 0) 
    { 
        strlcpy(g_wifi_data->nvs_wifi_config.sta_ssid, title, sizeof(g_wifi_data->nvs_wifi_config.sta_ssid)); 
        require |= WEB_POST_WIFI_CONFIG_STA;
    }

    if (strcmp(g_wifi_data->nvs_wifi_config.sta_pwd, text) != 0) { 
        strlcpy(g_wifi_data->nvs_wifi_config.sta_pwd, text, sizeof(g_wifi_data->nvs_wifi_config.sta_pwd));
        require |= WEB_POST_WIFI_CONFIG_STA;
    }
    if (require == 0) { 
        wifi_status_t s = wifi_get_connect_status(); 
        if (s != WIFI_STATUS_CONNECTING && s != WIFI_STATUS_CONNECTED) {
            require |= WEB_POST_WIFI_CONFIG_STA; 
        }
    }
    if (require & WEB_POST_WIFI_CONFIG_STA) {
        //g_wifi_data->nvs_wifi_config.sta_auth = wifi_get_ahth_mode_from_scanned_list(); 
    }
    if (require) { 
        //screen_config_require_change(require); 
    }
    wifi_sync_unlock();  
}

static lv_keyboard_user_data_t wifi_keyboard_user_data_t = {
    .obj = NULL,
    .cb_t = wifi_keyboard_cb_t,
};

static void btn_wifi_list_clicked(lv_event_t * e) {
    lv_obj_t * obj = lv_event_get_target(e);
    const char * str = lv_list_get_btn_text(NULL, obj); 
    //PRINT_WIDGET_WIFI("click ssid =%s,btn=%x record count=%02x\n",str,(unsigned int)obj,g_wifi_data->record.count);
    uint8_t *bssi_check = (uint8_t *)lv_obj_get_user_data(obj);
    // if (NULL == bssi_check)
    // {
    //     PRINT_WIDGET_WIFI("warning bssi_check =%x\n",(unsigned int)bssi_check);
    // }  
    wifi_status_t get_wifi_state = wifi_get_connect_status();
    // if the ssid is connected, need not any action
    if ((strcmp(g_wifi_data->nvs_wifi_config.sta_ssid, str) == 0)
        && (memcmp(g_wifi_data->nvs_wifi_config.bssid, bssi_check,6) == 0)
        && (get_wifi_state == WIFI_STATUS_CONNECTED)) { 
        return;
    }

    //wifi_dump_bssid(bssi_check);   
    bool find_same_bssid = false;
    for (uint8_t i = 0; i < g_wifi_data->record.count; i++) 
    {   
        if ((strcmp(g_wifi_data->record.ssid[i], str) == 0)
              && (memcmp(g_wifi_data->record.bssid[i], bssi_check,6) == 0))
        { 
            // if (g_wifi_data->record.authmode[i] == WIFI_AUTH_OPEN) 
            // { 
            //     memcpy(wifi_keyboard_user_data_t.bssid,bssi_check,6);     
            //     wifi_keyboard_cb_t(obj, str, "",wifi_keyboard_user_data_t.bssid);    
            //     wifi_keyboard_user_data_t.obj = NULL; 
            // } 
            // else 
            { 
                //password min len = 8, max len = 64 
                memcpy(wifi_keyboard_user_data_t.bssid,bssi_check,6);
                wifi_keyboard_user_data_t.obj = obj; 
                lv_obj_t * keyboard = lv_widget_keyboard_create(ui_screen_main, LV_KEYBOARD_MODE_TEXT_LOWER, &wifi_keyboard_user_data_t,
                                                                str, NULL, RS_TRANSLATE(K_POP_TIP_INPUT_PASSWORD), true, 8, MEM_SIZE(nvs_wifi_config_t, sta_pwd) - 1);
            }

            find_same_bssid=true;
            break;
        }
        else if (strcmp(g_wifi_data->record.ssid[i], str) == 0)
        {
            //PRINT_WIDGET_WIFI("same ssid not same bssid =%x",(unsigned int)g_wifi_data->record.bssid[i]);

            //wifi_dump_bssid(g_wifi_data->record.bssid[i]); 
        }
    }
 
    if (0 == find_same_bssid)
    {
        //PRINT_WIDGET_WIFI("btn parent %x",(unsigned int)lv_obj_get_parent(obj));
    }
}

lv_obj_t * lv_wifi_rssi_icon_create(lv_obj_t * parent, int8_t level, lv_color_t c, lv_color_t bg_c) {
    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_set_size(obj, 26, 20);
    lv_obj_align(obj, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);

    uint8_t arc_dia[] = {7, 28, 40};
    uint8_t y_offset[] = {6, 10, 10};
    uint16_t ang_start[] = {360, 230, 230};
    uint16_t ang_end[] = {0, 310, 310};
    for (uint8_t i = 0; i < 3; i++) {
        lv_color_t now_c = (level > i) ? c : bg_c;
        lv_obj_t * arc = lv_arc_create(obj);
        lv_obj_set_size(arc, arc_dia[i], arc_dia[i]);
        lv_obj_align(arc, LV_ALIGN_CENTER, 0, y_offset[i]);
        lv_arc_set_bg_angles(arc, ang_start[i], ang_end[i]);
        lv_obj_set_style_arc_color(arc, now_c, LV_PART_MAIN);
        lv_obj_set_style_arc_opa(arc, 255, LV_PART_MAIN);
        lv_obj_set_style_arc_width(arc, 3, LV_PART_MAIN);

        lv_obj_set_style_arc_opa(arc, 0, LV_PART_INDICATOR);
        lv_obj_set_style_bg_opa(arc, 0, LV_PART_KNOB);
    }
    return obj;
}

lv_obj_t * lv_wifi_auth_icon_create(lv_obj_t * parent, lv_color_t c) {
    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_set_size(obj, 20, 20);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag( obj, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);

    lv_obj_t * arc = lv_arc_create(obj);
    lv_obj_set_size(arc, 12, 12);
    lv_obj_align(arc, LV_ALIGN_CENTER, 0, -3);
    lv_arc_set_bg_angles(arc, 180, 0);
    lv_obj_set_style_arc_color(arc, c, LV_PART_MAIN);
    lv_obj_set_style_arc_opa(arc, 255, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc, 3, LV_PART_MAIN);
    lv_obj_set_style_arc_opa(arc, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(arc, 0, LV_PART_KNOB);

    lv_obj_t * rec = lv_obj_create(obj);
    lv_obj_set_size(rec, 16, 11);
    lv_obj_align(rec, LV_ALIGN_CENTER, 0, 3);
    lv_obj_clear_flag(rec, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_radius(rec, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(rec, c, LV_PART_MAIN );
    lv_obj_set_style_bg_opa(rec, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(rec, 0, LV_PART_MAIN);

    return obj;
}

lv_obj_t * lv_wifi_connected_icon_create(lv_obj_t * parent) {
    const lv_color_t c = lv_color_hex(0xFFFFFF);
    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_move_to_index(obj, 1);
    lv_obj_set_size(obj, 20, 20);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag( obj, LV_OBJ_FLAG_SCROLLABLE );
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
    /* must be static not const*/
    static lv_point_t line_points[] = { {2, 8}, {8, 14}, {20, 2} };
    lv_obj_t * line = ui_line_create(obj, line_points, 3, 2, c);
    lv_obj_center(line);
    return obj;
}

lv_obj_t * lv_connecting_spin_create(lv_obj_t * parent) {
    const lv_color_t c = lv_color_hex(0xFFFFFF);
    const lv_color_t bg_c = lv_color_hex(0x666666);
    lv_obj_t * spin = lv_spinner_create(parent, 500, 180);

    lv_obj_set_size(spin, 20, 20);
    lv_obj_align(spin, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag(spin, LV_OBJ_FLAG_CLICKABLE );    /// Flags
    lv_obj_set_style_arc_width(spin, 3, LV_PART_MAIN);
    lv_obj_set_style_arc_width(spin, 3, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(spin, bg_c, LV_PART_MAIN);
    lv_obj_set_style_arc_color(spin, c, LV_PART_INDICATOR);

    return spin;
}

lv_obj_t * lv_wifi_connecting_spin_create(lv_obj_t * parent) {
    lv_obj_t * spin = lv_connecting_spin_create(parent);
    lv_obj_move_to_index(spin, 1);

    return spin;
}

static void set_value(void * label, int32_t v) {
    char buf[10];
    snprintf(buf, sizeof(buf), "%ld", v);
    lv_label_set_text((lv_obj_t *)label, buf);
}

lv_obj_t * lv_scanning_spin_create(lv_obj_t * parent, const char * text) {
    const int32_t w = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    const lv_color_t c = lv_color_hex(0xFFFFFF);
    const lv_color_t bg_c = lv_color_hex(0x666666);    
    lv_obj_t * panel = ui_panel_create(parent, 0, bg_c);
    lv_obj_set_size(panel, w, 165);
    lv_obj_set_style_bg_opa(panel, 0, LV_PART_MAIN);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * spin = lv_spinner_create(panel, 1000, 90);
    lv_obj_set_size(spin, 120, 120);
    lv_obj_align(spin, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_clear_flag(spin, LV_OBJ_FLAG_CLICKABLE );
    // lv_obj_set_style_arc_width(spin, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_arc_width(spin, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(spin, bg_c, LV_PART_MAIN );
    lv_obj_set_style_arc_color(spin, c, LV_PART_INDICATOR);

    lv_obj_t * label = lv_label_create(spin);
    lv_label_set_text(label, "");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label, LV_FONT_24_VARIABLE, LV_PART_MAIN);

    lv_obj_t * label_info = lv_label_create(panel);
    lv_label_set_text(label_info, text);
    lv_obj_align(label_info, LV_ALIGN_BOTTOM_MID, 0, 0);

    /*Create an animation to set the value*/
    #define ANIM_MAX_VALUE 999
    #define ANIM_MIN_VALUE 1
    lv_anim_t a; 
    lv_anim_init(&a); 
    lv_anim_set_exec_cb(&a, set_value);
    lv_anim_set_var(&a, label);
    lv_anim_set_time(&a, 1000 * (ANIM_MAX_VALUE - ANIM_MIN_VALUE));
    lv_anim_set_values(&a, ANIM_MIN_VALUE, ANIM_MAX_VALUE);
    lv_anim_start(&a); 
    return panel;
}

lv_obj_t * lv_wifi_scanned_list_create(lv_obj_t * parent) { 
    lv_obj_t * obj = lv_list_create(parent);
    const lv_color_t text_c = lv_color_hex(0xFFFFFF);
    const int32_t w = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_WIDTH).num;
    const int32_t h = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_HEIGHT).num;
    const lv_color_t bg_c = lv_obj_get_style_prop(parent, LV_PART_MAIN, LV_STYLE_BG_COLOR).color;

    lv_obj_set_size(obj, w, h);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(obj, 5, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_hor(obj, 10, LV_PART_MAIN);
    lv_obj_set_style_text_font(obj,LV_FONT_16_VARIABLE,0);

    /*Add buttons to the list*/
    wifi_sync_lock(0);  
    for (uint8_t i = 0; i < g_wifi_data->record.count; i++) {
        lv_obj_t * btn = lv_list_add_btn(obj, NULL, g_wifi_data->record.ssid[i]); 
        
        lv_obj_set_style_border_color(btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
        
        lv_obj_set_style_bg_color(btn, bg_c, LV_PART_MAIN);
        lv_obj_set_style_text_color(btn, text_c, LV_PART_MAIN);
        lv_obj_set_style_pad_hor(btn, 10, LV_PART_MAIN);
        // lv_obj_set_style_pad_top(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_pad_bottom(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // if (g_wifi_data->record.authmode[i] != WIFI_AUTH_OPEN) {
        //     lv_wifi_auth_icon_create(btn, text_c);
        // }
        lv_obj_set_user_data(btn,(void *)g_wifi_data->record.bssid[i]);
        //PRINT_WIDGET_WIFI("create ssid =%s,btn=%x  bssid =%x\n",g_wifi_data->record.ssid[i],(unsigned int)btn,(unsigned int)g_wifi_data->record.bssid[i]);
        lv_wifi_rssi_icon_create(btn, wifiCalculateSignalLevel(g_wifi_data->record.rssi[i], RSSI_LEVEL_NUM), lv_color_hex(LV_DEFAULT_COLOR), lv_color_hex(WIFI_SIGNAL_BACKGROUND));
        lv_obj_add_event_cb(btn, btn_wifi_list_clicked, LV_EVENT_CLICKED, NULL);
    }
    wifi_sync_unlock();

    return obj;
}

int32_t lv_wifi_get_scan_state(lv_obj_t * panel) {
    lv_wifi_state_t * p_state = (lv_wifi_state_t *)panel->user_data;
    if (p_state == NULL) return WIFI_SCAN_INIT;
    return p_state->scan_state;
}

int32_t lv_wifi_get_connect_state(lv_obj_t * panel) {
    lv_wifi_state_t * p_state = (lv_wifi_state_t *)panel->user_data;
    if (p_state == NULL) return WIFI_STATUS_INIT;
    switch (p_state->connect_state) {
        case WIFI_STATUS_CONNECTING:
        case WIFI_STATUS_CONNECTED:
        // wifi_dump_bssid(p_state->bssid); 
        // wifi_dump_bssid(g_wifi_data->nvs_wifi_config.bssid);
            // if (!ut_str_not_blank(p_state->connect_ssid))
            // {
            //     PRINT_WIDGET_WIFI("p_state connect_ssid not valid");
            // }
            // if (!wifi_bssid_is_valid(p_state->bssid))
            // {
            //     PRINT_WIDGET_WIFI("p_state bssid not valid");
            // }
            wifi_sync_lock(0);  
            if ((strcmp(p_state->connect_ssid, g_wifi_data->nvs_wifi_config.sta_ssid) == 0) 
                && (memcmp(p_state->bssid, g_wifi_data->nvs_wifi_config.bssid,6) == 0))
            {
                wifi_sync_unlock();  
                return p_state->connect_state;
            } else {
                wifi_sync_unlock();    
                //wifi_dump_bssid(p_state->bssid); 
                //wifi_dump_bssid(g_wifi_data->nvs_wifi_config.bssid);
                return WIFI_STATUS_INIT;
            }
            break;
        default:
            break;
    }
    return p_state->connect_state;
}

lv_obj_t * lv_wifi_scan_create(lv_obj_t * parent, int32_t state) {
    lv_wifi_state_t * p_state = (lv_wifi_state_t *)parent->user_data;
    if (p_state == NULL) return NULL;
    // if spinner or list exists, delete it first
    lv_obj_t * obj = lv_obj_get_child(parent, 0);
    if (obj) {
        //PRINT_WIDGET_WIFI("del scan list[%x]",(unsigned int)obj);
        lv_obj_del(obj);
    }
    // create spinner or list according to current status of WiFi
    obj = NULL;
    switch (state) {
        // case WIFI_SCAN_RUNNING: 
        //     obj = lv_scanning_spin_create(parent, RS_TRANSLATE(K_LOADING));  
        //     break;
        // case WIFI_SCAN_COMPLETED:
        //     obj = lv_wifi_scanned_list_create(parent); 
        //     break;
        default:
        {
            break;
        }
    }

    p_state->scan_state = state;
    p_state->connect_state = WIFI_STATUS_INIT;
    p_state->connect_ssid[0] = '\0';
    memset(p_state->bssid,0,6);
    p_state->connect_obj = NULL;

    return obj;
}



lv_obj_t * lv_wifi_connect_create(lv_obj_t * parent, int32_t state) {
    // find the list widget on target panel 
    
    lv_obj_t * list = lv_obj_get_child(parent, 0);
    if (list == NULL) return NULL;
    if (!lv_obj_check_type(list, &lv_list_class)) return NULL;

    lv_wifi_state_t * p_state = (lv_wifi_state_t *)parent->user_data;
    if (p_state == NULL) return NULL;
    if (p_state->connect_obj) {
        lv_obj_del(p_state->connect_obj);
        p_state->connect_obj = NULL; 
    }
    // find the actived wifi btn if it exists
    lv_obj_t * act_btn = NULL;
    wifi_sync_lock(0);   
    for (uint32_t i = 0; i < lv_obj_get_child_cnt(list); i++) {
        lv_obj_t * btn = lv_obj_get_child(list, i);
        const char * str = lv_list_get_btn_text(list, btn); 
        
        uint8_t *check_bssid = (uint8_t *)lv_obj_get_user_data(btn);
        if (check_bssid)
        {
            if ((strcmp(g_wifi_data->nvs_wifi_config.sta_ssid, str) == 0)
                && (memcmp(g_wifi_data->nvs_wifi_config.bssid, check_bssid,6) == 0)) { 
                act_btn = btn;
            } 
        }
        else
        { 
            if (strcmp(g_wifi_data->nvs_wifi_config.sta_ssid, str) == 0) 
            {
                act_btn = btn;
            } 
        }
    }
    wifi_sync_unlock();

    if ((WIFI_STATUS_CONNECTED == state)
         && (NULL == act_btn))
    {  
        if (retry_cnt_refresh<5)
        {
            retry_cnt_refresh++; 
            //screen_config_require_change(WEB_POST_WIFI_REFRESH); 
            return NULL;
        }  
    }
    
    if (WIFI_STATUS_CONNECTED != state)
    {
        retry_cnt_refresh=0;
    } 

    if (act_btn) {
        switch (state) {
            case WIFI_STATUS_CONNECTING:  
                p_state->connect_obj = lv_wifi_connecting_spin_create(act_btn);  
                break;
            case WIFI_STATUS_CONNECTED:
                p_state->connect_obj = lv_wifi_connected_icon_create(act_btn);
                break;
            case WIFI_STATUS_ERROR:
                break;
            case WIFI_STATUS_DISCONNECT:
                PRINT_WIDGET_WIFI("wifi disconnected!");
                break;
            case WIFI_STATUS_PASSWORD_ERROR:
                PRINT_WIDGET_WIFI("wifi password error");
                break;
            case WIFI_STATUS_INIT:
                break;
            default:break;
        }
    }

    wifi_sync_lock(0);
    strlcpy(p_state->connect_ssid, g_wifi_data->nvs_wifi_config.sta_ssid, sizeof(p_state->connect_ssid)); 
    memcpy(p_state->bssid, g_wifi_data->nvs_wifi_config.bssid, 6);  
    wifi_sync_unlock();
    p_state->connect_state = state; 
    return p_state->connect_obj;
}
