 
#include "app.h" 
 
#include "lv_ui_overlay.h" 

#define SW_PRINT_SCREEN 0

#if SW_PRINT_SCREEN && SW_PRINT_ALL
#include "esp_log.h" 
#include "esp_wifi.h"
static const char * TAG = "screen"; 
#define PRINT_SCREEN(fmt,args...) ESP_LOGW(TAG,fmt,##args)  

#else
#define PRINT_SCREEN(...)
#endif

lv_obj_t * ui_screen_main = NULL;
lv_obj_t * ui_panel_ctl_title = NULL;
lv_obj_t * ui_label_ctl_title = NULL;

static char s_printer_name[MAX_LEN_NAME]; 
static uint8_t s_printer_index = 0; 
static void event_handler_refresh_top_title(lv_event_t * e);
static uint8_t get_ctl_type_last = PRT_CTL_MAX;
static bambu_mqtt_t * bambu_mqtt_master_last = NULL;
static bool require_update = false;

void ui_top_tile_refresh_require(void)
{
    if (require_update)
    {
        return;
    }

    require_update=true;
}

/************* common ***************/
lv_obj_t * ui_panel_create(lv_obj_t * parent, lv_coord_t radius, lv_color_t bg_c) {
    lv_obj_t * panel = lv_obj_create(parent);
    // lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE );
    lv_obj_set_style_radius(panel, radius, LV_PART_MAIN);
    lv_obj_set_style_bg_color(panel, bg_c, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(panel, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(panel, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(panel, 0, LV_PART_MAIN);
    lv_obj_set_style_text_color(panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_opa(panel, 255, LV_PART_MAIN); 
    lv_obj_set_style_text_font(panel, LV_FONT_16_VARIABLE, LV_PART_MAIN);
    return panel;
}

lv_obj_t * ui_btn_img_create(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, lv_color_t bg_c, const void * bg_img_src) {
    lv_obj_t * btn = lv_btn_create(parent);
    lv_obj_set_size(btn, w, h);
    lv_obj_set_style_radius(btn, radius, LV_PART_MAIN);
    lv_obj_set_style_bg_color(btn, bg_c, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(btn, 255, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(btn, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(btn, 0, LV_PART_MAIN);
    lv_obj_set_style_text_color(btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_opa(btn, 255, LV_PART_MAIN);
    if (bg_img_src) {
        lv_obj_set_style_bg_img_src(btn, bg_img_src, LV_PART_MAIN);
        // lv_obj_set_style_bg_img_recolor(btn, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_PRESSED);
        // lv_obj_set_style_bg_img_recolor_opa(btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    }

    return btn;
}

lv_obj_t * ui_btn_label_create(lv_obj_t * parent, lv_coord_t w, lv_coord_t h, lv_coord_t radius, lv_color_t bg_c, const char * text) {
    lv_obj_t * btn = ui_btn_img_create(parent, w, h, radius, bg_c, NULL);

    lv_obj_t * label = lv_label_create(btn);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, text);
    lv_obj_set_width(label, w);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

    return btn;
}

lv_obj_t * ui_line_create(lv_obj_t * parent, const lv_point_t * points, uint16_t num, lv_coord_t w, lv_color_t color) {
    lv_obj_t * line = lv_line_create(parent);
    lv_line_set_points(line, points, num);
    lv_obj_set_style_line_width(line, w, LV_PART_MAIN);
    lv_obj_set_style_line_color(line, color, LV_PART_MAIN);
    lv_obj_set_style_line_opa(line, 255, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(line, false, LV_PART_MAIN);
    return line;
}

lv_obj_t * ui_panel_create_index(lv_obj_t * parent, uint8_t i, lv_coord_t size, lv_color_t bg_c) {
    lv_obj_t * panel = ui_panel_create(parent, LV_RADIUS_CIRCLE, bg_c);
    lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE );
    lv_obj_set_size(panel, size, size);
    lv_obj_t * label = lv_label_create(panel);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    char buf[10];
    snprintf(buf, sizeof(buf), "%d", i + 1);
    lv_obj_set_style_text_font(label, &opensansb16, 0);
    lv_label_set_text(label, buf); 
    ui_obj_set_type(label, UI_TYPE_INDEX_LABEL);

    return panel;
}

lv_obj_t * ui_panel_create_index_dot(lv_obj_t * parent, uint8_t i, lv_coord_t size, lv_color_t bg_c) {
    lv_obj_t * panel = ui_panel_create(parent, LV_RADIUS_CIRCLE, bg_c);
    lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE );
    lv_obj_set_size(panel, size, LV_SIZE_CONTENT);
    lv_obj_t * label = lv_label_create(panel);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    char buf[10];
    snprintf(buf, sizeof(buf), "%d.", i + 1);
    lv_obj_set_style_text_font(label, &opensansb16, 0);
    lv_label_set_text(label, buf); 
    ui_obj_set_type(label, UI_TYPE_INDEX_LABEL); 

    return panel;
}

void ui_del_myself_clicked(lv_event_t * e) {
    lv_obj_t * myself = lv_event_get_target(e);
    lv_obj_del_async(myself);
}

void ui_obj_set_type(lv_obj_t * obj, ui_type_t type) {
    uint32_t user_data = type;
    lv_obj_set_user_data(obj, (void *)user_data);
}

lv_obj_t * ui_obj_get(lv_obj_t * parent, ui_type_t type) {
    if (parent == NULL) return NULL;
    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) {
        lv_obj_t * obj = lv_obj_get_child(parent, i);
        if((ui_type_t)(pointer_type)obj->user_data == type) {
            return obj;
        }
    }
    return NULL;
}

/************* left widget ***************/
static void btn_left_clicked(lv_event_t * e) {
    lv_obj_t * btn = (lv_obj_t *)lv_event_get_user_data(e);
    ui_type_t btn_id = (ui_type_t)(pointer_type)(pointer_type)btn->user_data;
    ui_screen_select(UI_TYPE_BTN_LEFT_GET_SCREEN(btn_id));
}

static lv_obj_t * ui_btn_left_create(lv_obj_t * parent, const void * img, lv_coord_t y_ofs, ui_type_t type) {
    lv_obj_t * btn = ui_btn_img_create(parent, 96, 90, 0, lv_color_hex(0x363636), img);
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 0, y_ofs);
    lv_obj_set_style_bg_img_recolor(btn, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    lv_obj_set_style_bg_img_recolor_opa(btn, 0, LV_PART_MAIN);
    ui_obj_set_type(btn, type);
    lv_obj_add_event_cb(btn, btn_left_clicked, LV_EVENT_CLICKED, btn);

    return btn;
}

lv_obj_t * ui_panel_create_left(lv_obj_t * parent) {
    lv_obj_t * panel = ui_panel_create(parent, 0, lv_color_hex(0x363636));
    lv_obj_set_size(panel, 96, 452);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    ui_btn_left_create(panel, &ui_img_ctl_home_png, 1, UI_TYPE_BTN_LEFT_HOME);
    ui_btn_left_create(panel, &ui_img_ctl_ctl_png, 91, UI_TYPE_BTN_LEFT_CTRL);
    ui_btn_left_create(panel, &ui_img_ctl_print_png, 181, UI_TYPE_BTN_LEFT_PRINT);
    ui_btn_left_create(panel, &ui_img_ctl_setting_png, 271, UI_TYPE_BTN_LEFT_SETTING);
    ui_btn_left_create(panel, &ui_img_ctl_printers_png, 361, UI_TYPE_BTN_LEFT_PRINTERS);
    ui_obj_set_type(panel, UI_TYPE_PANEL_LEFT);

    return panel;
}

static void ui_btn_left_select(lv_obj_t * parent, ui_type_t type) {
    if (type == UI_TYPE_ERROR) return;

    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) {
        lv_obj_t * btn = lv_obj_get_child(parent, i);
        lv_opa_t opa = ((ui_type_t)(pointer_type)btn->user_data == type) ? 255 : 0;
        lv_obj_set_style_bg_img_recolor_opa(btn, opa, LV_PART_MAIN);
    }
}
 
/************* top widget ***************/
static void btn_top_clicked(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_current_target(e);
    lv_obj_t * parent = lv_obj_get_parent(btn);
    ui_type_t screen_type = (ui_type_t)(pointer_type)lv_event_get_user_data(e);
    ui_btn_top_select(parent, UI_TYPE_SCREEN_GET_BTN_TOP(screen_type));
    ui_screen_select(screen_type);
}

static lv_obj_t * ui_btn_top_create(lv_obj_t * parent, const char * text, ui_type_t type) {
    lv_obj_t * btn = lv_imgbtn_create(parent);
    lv_obj_set_size(btn, LV_SIZE_CONTENT, 34);
    lv_obj_set_style_text_color(btn, lv_color_hex(0xFFFFFF), (pointer_type)LV_PART_MAIN );
    lv_obj_set_style_text_opa(btn, 255, LV_PART_MAIN);
    ui_obj_set_type(btn, type); 
    lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, &ui_img_q1_png, &ui_img_q2_png, &ui_img_q3_png);
    lv_obj_set_style_img_opa(btn, 0, LV_PART_MAIN);

    lv_obj_t * label = lv_label_create(btn);
    lv_obj_set_size(label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_hor(label, 20, LV_PART_MAIN);
    lv_obj_set_style_pad_ver(label, 0, LV_PART_MAIN);
    lv_label_set_text(label, text);
    return btn;
}

void ui_btn_top_select(lv_obj_t * parent, ui_type_t type) {
    if (type == UI_TYPE_ERROR) return;

    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) {
        lv_obj_t * btn = lv_obj_get_child(parent, i);
        lv_opa_t opa = ((ui_type_t)(pointer_type)btn->user_data == type) ? 255 : 0;
        lv_obj_set_style_img_opa(btn, opa, LV_PART_MAIN);
    }
}

lv_obj_t * ui_panel_create_top(lv_obj_t * parent, const ui_btn_ctl_top_t * btns, uint8_t num) {
    lv_obj_t * panel = ui_panel_create(parent, 0, lv_color_hex(0x444444));
    lv_obj_set_size(panel, 704, 38);
    lv_obj_align(panel, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_pad_hor(panel, 20, LV_PART_MAIN);
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
    // create buttons
    for (uint8_t i = 0; i < num; i++) { 
        const char * text = NULL;

        if (K_INVALID_ID == btns[i].translate_data.key)
        {
            text = btns[i].text; 
        }
        else
        {
            text = RS_TRANSLATE(btns[i].translate_data.key);
        }
 
        lv_obj_t * btn = ui_btn_top_create(panel, text , UI_TYPE_SCREEN_GET_BTN_TOP(btns[i].target_screen));
        lv_obj_t *get_label = lv_obj_get_child(btn,0);
        if (get_label)
        {
            lv_obj_set_style_text_font(get_label,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT);
        }
        lv_obj_add_event_cb(btn, btn_top_clicked, LV_EVENT_CLICKED, (void *)btns[i].target_screen);
        rs_add_translate_cb(btn,btns[i].translate_data.translate_cb,(void *)btns[i].translate_data.key,KEY_NUMBER);
    }
    ui_obj_set_type(panel, UI_TYPE_PANEL_TOP);
    return panel;
}

lv_obj_t *g_lv_widget_screen_get_top_title(void)
{
    return ui_label_ctl_title;
}

/************* screen ***************/
void ui_screen_main_init(void) 
{
    ui_screen_main = lv_obj_create(NULL);
 
    ui_panel_ctl_title = ui_panel_create(ui_screen_main, 0, lv_color_hex(0x575757));
    lv_obj_set_style_pad_hor(ui_panel_ctl_title, 5, LV_PART_MAIN);
    lv_obj_set_size(ui_panel_ctl_title, 800, 28);
    lv_obj_align(ui_panel_ctl_title, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_flex_flow(ui_panel_ctl_title, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_panel_ctl_title, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(ui_panel_ctl_title, 5, LV_PART_MAIN);

    ui_label_ctl_title = lv_label_create(ui_panel_ctl_title);
    lv_obj_add_flag(ui_label_ctl_title, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_label_ctl_title, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_label_ctl_title, LV_FONT_DEFAULT_24, LV_PART_MAIN);
    lv_label_set_text(ui_label_ctl_title, "Panda Touch");
 

    lv_obj_add_event_cb(ui_label_ctl_title, event_handler_refresh_top_title , LV_EVENT_REFRESH, NULL);
    lv_obj_add_flag(ui_label_ctl_title,LV_OBJ_FLAG_MULTI_LANG);

    ui_panel_create_left(ui_screen_main);

    lv_disp_load_scr(ui_screen_main);
}

static lv_obj_t * ui_sub_screen_select(lv_obj_t * parent, ui_type_t type, bool * changed) {
    lv_obj_t * screen_need = NULL;
    if (type != UI_TYPE_ERROR) {
        for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) {
            lv_obj_t * screen = lv_obj_get_child(parent, i);
            ui_type_t screen_type = (ui_type_t)(pointer_type)screen->user_data;
            if (!UI_TYPE_IS_SCREEN(screen_type)) continue;

            bool hidden_now = lv_obj_has_flag_any(screen, LV_OBJ_FLAG_HIDDEN);
            bool hidden_need = (screen_type == type) ? false : true;
            if (!hidden_need) screen_need = screen;
            if (hidden_now == hidden_need) continue;
            *changed = true;
            if (!hidden_need)
                lv_obj_clear_flag(screen, LV_OBJ_FLAG_HIDDEN);
            else
                lv_obj_add_flag(screen, LV_OBJ_FLAG_HIDDEN);
        }
    }

    return screen_need;
}

void ui_screen_select(ui_type_t type) {
    if (type == UI_TYPE_ERROR) return;
    lv_obj_t * parent = ui_screen_main;

    bool changed = false;
    lv_obj_t * screen = ui_sub_screen_select(parent, UI_TYPE_SCREEN_GET_MAIN_SCREEN(type), &changed);

    if (changed) {
        lv_obj_t * panel_left = ui_obj_get(parent, UI_TYPE_PANEL_LEFT);
        if (panel_left) {
            ui_btn_left_select(panel_left, UI_TYPE_SCREEN_GET_BTN_LEFT(type));
        }
 
    }

    if (screen && UI_TYPE_SCREEN_GET_BTN_TOP(type) != UI_TYPE_ERROR) {
        lv_obj_t * panel_top = ui_obj_get(screen, UI_TYPE_PANEL_TOP);
        if (panel_top) {
            ui_sub_screen_select(screen, type, &changed);

            if (changed) {
 
                ui_btn_top_select(panel_top, UI_TYPE_SCREEN_GET_BTN_TOP(type));
            }
        }
    }
} 

#if 0
    MLG_KEY_TYPE  text;
    char *  text_str;
    const char * qr_url;

     // max 3 btn
    uint8_t btn_num;
    MLG_KEY_TYPE btn_text[3];
    uint32_t btn_id[3];
    lv_popup_cb_t popup_cb;
    lv_popup_account_cb_t pop_account_cb;
    const void * cb_data;
#endif

const ui_popup_t popup_wifi_error = {
    .text = K_TIP_WIFI_ERROR,
    .btn_num = 1,
    .btn_text = {K_BTN_CLOSE},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
};

const ui_popup_t popup_wifi_disconnet = {
    .text = K_TIP_WIFI_DISCONNECTED,
    .btn_num = 1,
    .btn_text = {K_BTN_CLOSE},
    .btn_id = {UI_POPUP_BTN_CANCEL},
    .popup_cb = NULL, // default popop call back funtion
     
};


static const lv_point_t line_points[] = {{0, 0}, {26, 20}};

typedef enum {
    // IDLE
    UI_TOP_TITLE_IDLE, //0, "PandaTouch", 0xFFFFFF, 
    // WiFi
    UI_TOP_TITLE_WIFI_CONNECTING, //1, "Connecting to WiFi %s", 0xFFFFFF, opensansb16
    UI_TOP_TITLE_WIFI_FAILED, //2, "Failed to connect to WiFi: %s", 0xFF9F09, opensansb16
    UI_TOP_TITLE_WIFI_DISCONNECT, //3, "Disconnected from WiFi: %s", 0xFF9F09, opensansb16
    // Printer
    UI_TOP_TITLE_PRINTER_CONNECTING, //4, "Connecting to Printer %d: %s", 0xFFFFFF, opensansb16
    UI_TOP_TITLE_PRINTER_CONNECTED, //5, "Printer %d: %s has successfully connected", 0x4CD112, opensansb16
    UI_TOP_TITLE_PRINTER_FAILED, //6, "Printer %d: %s has failed to connect", 0xFF9F09, opensansb16
    // Noting to do, Just a flag
    UI_TOP_TITLE_NOTING,
    UI_TOP_TITLE_REFRESH,
} ui_title_status_t;

typedef struct {
    MLG_KEY_TYPE context;
    const lv_font_t * font_size;
    const uint32_t font_color;
} ui_title_context_t;

const ui_title_context_t ui_title_context[] = {
    // IDLE
    {K_PANDA_TOUCH, &opensansb16_fname, 0xFFFFFF},
    // WiFi
    {K_TOP_WIFI_CONNECT, &opensansb16_fname, 0xFFFFFF},
    {K_TOP_WIFI_CONNECT_FAIL, &opensansb16_fname, 0xFF9F09},
    {K_TOP_WIFI_DISCONNECTED, &opensansb16_fname, 0xFF9F09},
    // Printer
    {K_TOP_PRINT_CONNECTING, &opensansb16_fname, 0xFFFFFF},
    {K_TOP_PRINT_CONNECTED, &opensansb16_fname, 0x4CD112},
    {K_TOP_PRINT_CONNECT_FAIL, &opensansb16_fname, 0xFF9F09},
    {K_PANDA_TOUCH, &opensansb16_fname, 0xFFFFFF},
};

ui_title_status_t title_get_status_from_wifi(wifi_status_t status) {
    switch (status) {
        case WIFI_STATUS_INIT:
        case WIFI_STATUS_CONNECTING:
            return UI_TOP_TITLE_WIFI_CONNECTING;
        case WIFI_STATUS_ERROR:
        case WIFI_STATUS_PASSWORD_ERROR:
            return UI_TOP_TITLE_WIFI_FAILED;
        case WIFI_STATUS_DISCONNECT:
            return UI_TOP_TITLE_WIFI_DISCONNECT;
        default:
            break;
    }
    return UI_TOP_TITLE_IDLE;
}

static ui_title_status_t s_title_status = UI_TOP_TITLE_IDLE;

static void event_handler_refresh_top_title(lv_event_t * e)
{
    #if 0
    lv_event_code_t code = lv_event_get_code(e);
 
    if (code == LV_EVENT_REFRESH)
    {
        lv_obj_t * obj = lv_event_get_target(e); 
  
        wifi_sync_lock(0);
        wifi_status_t wifi_status = wifi_get_connect_status();
        wifi_sync_unlock(); 
        ui_title_status_t title_status = s_title_status;//title_get_status_from_wifi(wifi_status);
        ui_title_context_t * context = (ui_title_context_t *)ui_title_context + title_status; 

        printer_group_sync_lock(0);
        uint8_t get_ctl_type = group_sync_data.control_type;
        printer_group_sync_unlock();

        lv_obj_set_style_text_font(obj, context->font_size, LV_PART_MAIN);
        lv_obj_set_style_text_color(obj, lv_color_hex(context->font_color), LV_PART_MAIN);
 
        switch (title_status) {
            case UI_TOP_TITLE_IDLE: 
                PRINT_SCREEN("get_ctl_type=%d\n",(int)get_ctl_type);

                if (PRT_CTL_SINGLE == get_ctl_type)
                {
                    lv_label_set_text_fmt(obj, "P-<%s>",bambu_mqtt_master->nvs_config.name);
                }
                else if (PRT_CTL_GROUP == get_ctl_type)
                {
                    printer_group_sync_lock(0);
                    printer_group_t *get_group_leader = printer_group_get_leader();
                    if (get_group_leader)
                    {
                        lv_label_set_text_fmt(obj, "G-<%s>\\<%s>",get_group_leader->nvs_config.name,bambu_mqtt_master->nvs_config.name);
                    }
                    printer_group_sync_unlock();
                }
                break; 

            case UI_TOP_TITLE_WIFI_CONNECTING:
                wifi_sync_lock(0);
                lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), g_wifi_data->nvs_wifi_config.sta_ssid);
                wifi_sync_unlock();
                break;
            case UI_TOP_TITLE_WIFI_FAILED:
                ui_panel_create_popup(&popup_wifi_error, NULL);
                wifi_sync_lock(0);
                lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), g_wifi_data->nvs_wifi_config.sta_ssid);
                wifi_sync_unlock();
                break;
            case UI_TOP_TITLE_WIFI_DISCONNECT:
                ui_panel_create_popup(&popup_wifi_disconnet, NULL);
                wifi_sync_lock(0);
                lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), g_wifi_data->nvs_wifi_config.sta_ssid);
                wifi_sync_unlock();
                break;
            case UI_TOP_TITLE_PRINTER_CONNECTED:
            case UI_TOP_TITLE_PRINTER_CONNECTING: 
            case UI_TOP_TITLE_PRINTER_FAILED:
                if (ut_str_not_blank(s_printer_name))
                {
                    lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), printer_nvs_idx_to_sorted_idx(s_printer_index) + 1, s_printer_name);
                }
                break;
            default:
                break;
        }
    }
    #endif
}

static ui_title_status_t printer_status[BAMBU_PRINTER_MAX_NUM] = {
    UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH,
    UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH, UI_TOP_TITLE_REFRESH,
};

ui_title_status_t title_get_status_from_printer(mqtt_status_t status, uint8_t i) {
    status = (mqtt_status_t)(status & ~(uint32_t)MQTT_ERROR_BACKUP_BIT);
    switch (status) {
        case MQTT_INIT:
        case MQTT_CONNECTING:
            printer_status[i] = UI_TOP_TITLE_PRINTER_CONNECTING;
            return UI_TOP_TITLE_PRINTER_CONNECTING;
        case MQTT_CONNECTED:
            if (printer_status[i] != UI_TOP_TITLE_PRINTER_CONNECTED) {
                printer_status[i] = UI_TOP_TITLE_PRINTER_CONNECTED;
                return UI_TOP_TITLE_PRINTER_CONNECTED;
            }
            break;
        case MQTT_ERROR_PORT:
        case MQTT_ERROR_REFUSED:
        case MQTT_ERROR_OTHER:
        case MQTT_ERROR_TIMEOUT:
        case MQTT_ERROR_NOT_BIND_ACCOUNT:
        case MQTT_ERROR_NULL_ACCOUNT:
            printer_status[i] = UI_TOP_TITLE_PRINTER_FAILED;
            return UI_TOP_TITLE_PRINTER_FAILED;
        default:
            break;
    }
    return UI_TOP_TITLE_IDLE;
}

lv_obj_t * lv_bat_percent_icon_create(lv_obj_t * parent, uint8_t level, lv_color_t c, lv_color_t bg_c, bool is_charging) 
{
    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);    /// Flags 
 
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);   
    lv_obj_t * bat_head = ui_panel_create(obj, 1, lv_color_hex(0xE1E4E5));
    lv_obj_set_size(bat_head, 7, 2);
    lv_obj_align(bat_head, LV_ALIGN_CENTER, 0, -7);

    lv_obj_t * bat_body = ui_panel_create(obj, 1, lv_color_hex(0xE1E4E5));
    lv_obj_set_size(bat_body, 11, 13);
    lv_obj_align(bat_body, LV_ALIGN_CENTER, 0, 1);

    lv_obj_t * bat_body_bg = ui_panel_create(bat_body, 1, lv_color_hex(0xC1C1C1));
    lv_obj_set_size(bat_body_bg, 9, 11);
    lv_obj_align(bat_body_bg, LV_ALIGN_CENTER, 0, 0);

    uint8_t y_offset[] = {8, 4, 0};
    if (!level)
    {
        level=1;
    } 
    for (uint8_t i = 0; i < 3; i++)
    {
        lv_color_t now_c = (level > i) ? c : lv_color_hex(0xC1C1C1);//bg_c
        if (!is_charging)
        {
            if (0 == i)
            {
                if (1 == level)
                {
                    now_c=lv_color_hex(0xFF9F09); 
                }
            }
        }
        lv_obj_t * bat_line = ui_panel_create(bat_body_bg, 1, now_c);
        lv_obj_set_size(bat_line, 9, 3);
        lv_obj_align(bat_line, LV_ALIGN_TOP_MID, 0, y_offset[i]);
    } 
    return obj;
}

static const connect_flag_t connect_flags[] = {CONNECT_FLAG_MASTER, CONNECT_FLAG_SLAVE};
extern bat_status_t current_bat_status;

void lv_loop_top_label(void) {
    #if 0
    static int wifi_level = 0;
    static lv_obj_t * panel_wifi_icon = NULL;
    static wifi_status_t s_wifi_status = (wifi_status_t)0xFF;/*s_wifi_status = WIFI_STATUS_INIT 强制让其创建wifi图标*/
    static wifi_status_t s_wifi_status_error = WIFI_STATUS_INIT;
    static lv_obj_t *master_icon_panel = NULL;
    static lv_obj_t *master_icon_cloud = NULL;
    static lv_obj_t *master_icon_mqtt = NULL;
    static lv_obj_t *master_icon_pwr = NULL;
    static uint8_t s_master_account_type;
    static mqtt_status_t s_master_status = MQTT_INIT;
    static lv_obj_t * panel_battery_icon = NULL;

    static uint32_t ms_wifi = 0;
    #ifdef CONFIG_BAT_UPDATE_IVT_MS
    static bat_status_t last_bat_status={false,100};
    static uint8_t animation_bat_charging_level=1;
    static uint32_t ms_bat_charging = 0;
    static uint32_t ms_bat_first_update = 0;
	#endif
    wifi_sync_lock(0);
    wifi_status_t wifi_status = wifi_get_connect_status();
    wifi_sync_unlock(); 
    
    if (s_wifi_status_error != wifi_status)
    {
        /*如果WIFI状态发生变化，如果上一次是连接失败或者已断开，这一次是已连接则删除最后一个弹窗*/
        if ((WIFI_STATUS_DISCONNECT == s_wifi_status) 
            || (WIFI_STATUS_ERROR == s_wifi_status)
            || (WIFI_STATUS_CONNECTED == s_wifi_status))
        {
            if (WIFI_STATUS_CONNECTED == wifi_status)
            {
                PRINT_SCREEN("remove wifi pop");
                ui_panel_del_popup(NULL);
            }

            s_wifi_status_error=wifi_status;
        } 
    }

    if (s_wifi_status != wifi_status) { 
        s_wifi_status = wifi_status;
        if (panel_wifi_icon) lv_obj_del(panel_wifi_icon);
        panel_wifi_icon = lv_wifi_rssi_icon_create(ui_panel_ctl_title, 0, lv_color_hex(LV_DEFAULT_COLOR), lv_color_hex(0xffffff));
        lv_obj_add_flag(panel_wifi_icon, LV_OBJ_FLAG_FLOATING);
        wifi_level = 0;
        if (s_wifi_status != WIFI_STATUS_CONNECTED) {
            lv_obj_t * line = ui_line_create(panel_wifi_icon, line_points, 2, 3, lv_color_hex(LV_DEFAULT_COLOR));
            lv_obj_center(line);
        }
    }
    if (s_wifi_status == WIFI_STATUS_CONNECTED) {
        if (ms_wifi < millis()) {
            ms_wifi = millis() + 1000; // 1s
            wifi_ap_record_t info;
            esp_wifi_sta_get_ap_info(&info);
            int level = wifiCalculateSignalLevel(info.rssi, RSSI_LEVEL_NUM);
            if (wifi_level != level) {
                wifi_level = level;
                if (panel_wifi_icon) lv_obj_del(panel_wifi_icon);
                panel_wifi_icon = lv_wifi_rssi_icon_create(ui_panel_ctl_title, wifi_level, lv_color_hex(LV_DEFAULT_COLOR), lv_color_hex(WIFI_SIGNAL_BACKGROUND));
                lv_obj_add_flag(panel_wifi_icon, LV_OBJ_FLAG_FLOATING);
            }
        }
    }
    
    if (NULL != bambu_mqtt_master)
    {
        if (NULL == master_icon_panel)
        {
            master_icon_panel = ui_panel_create(ui_panel_ctl_title, 12, lv_color_hex(0x575757));
            lv_obj_set_size(master_icon_panel, 120, 28);
            lv_obj_add_flag(master_icon_panel, LV_OBJ_FLAG_FLOATING);
            //lv_obj_align_to(master_icon_panel,panel_battery_icon,LV_ALIGN_OUT_LEFT_MID,0,0);
            lv_obj_align_to(master_icon_panel,panel_wifi_icon,LV_ALIGN_OUT_LEFT_MID,0,0);
            lv_obj_set_scroll_dir(master_icon_panel,LV_DIR_NONE);

            lv_obj_set_flex_flow(master_icon_panel, LV_FLEX_FLOW_ROW);
            lv_obj_set_flex_align(master_icon_panel, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
            lv_obj_set_style_pad_right(master_icon_panel,6,0);
            lv_obj_set_style_pad_column(master_icon_panel, 6, LV_PART_MAIN);

            master_icon_pwr = ui_panel_create(master_icon_panel, LV_RADIUS_CIRCLE, lv_color_hex(0x575757));
            lv_obj_set_size(master_icon_pwr, 20, 28); 
            ui_img_pwr_status_icon_set(master_icon_pwr, bambu_mqtt_master->pwr_data.is_online, false);
            
            master_icon_cloud = ui_panel_create(master_icon_panel, LV_RADIUS_CIRCLE, lv_color_hex(0x575757));
            lv_obj_set_size(master_icon_cloud, 20, 28); 
            ui_img_cloud_status_icon_set(master_icon_cloud,bambu_mqtt_master->nvs_config.account_type);

            master_icon_mqtt = ui_panel_create(master_icon_panel, LV_RADIUS_CIRCLE, lv_color_hex(0x575757));
            lv_obj_set_size(master_icon_mqtt, 20, 28); 
            ui_img_mqtt_status_icon_set(master_icon_mqtt, bambu_mqtt_master->status);

            panel_battery_icon = lv_bat_percent_icon_create(master_icon_panel, 3, lv_color_hex(LV_32BIT_COLOR_STATUS), lv_color_hex(LV_32BIT_BTT_GRAY_BG),false);
            
            lv_obj_add_flag(panel_battery_icon,LV_OBJ_FLAG_HIDDEN);

            ms_bat_first_update = millis() + 5000;
            ms_bat_charging = millis() + 5000; 
        }
        else
        {   
            /*刷新顶部图标*/
            if ((s_master_account_type != bambu_mqtt_master->nvs_config.account_type)
                || (bambu_mqtt_master_last != bambu_mqtt_master))
            {
                s_master_account_type = bambu_mqtt_master->nvs_config.account_type;
                ui_img_cloud_status_icon_set(master_icon_cloud,bambu_mqtt_master->nvs_config.account_type);
            }

            printer_group_sync_lock(0);
            printer_control_t get_control_type = group_sync_data.control_type; 
            printer_group_sync_unlock();
 
            mqtt_status_t state = bambu_mqtt_master->status;

            if (PRT_CTL_GROUP == get_control_type)
            {
                printer_group_t *get_group_leader =  printer_group_get_leader(); 
                if (get_group_leader)
                {
                    state = printer_group_mqtt_is_connected(get_group_leader)?MQTT_CONNECTED:MQTT_INIT;
                } 
            }

            if ((s_master_status != state)
                || (bambu_mqtt_master_last != bambu_mqtt_master))
            { 
                s_master_status = state;  
                ui_img_mqtt_status_icon_set(master_icon_mqtt, state);
            }

            if (WIFI_STATUS_CONNECTED != wifi_status)
            {
                ui_img_mqtt_status_icon_set(master_icon_mqtt, MQTT_INIT);
            }

            /*刷新PWR状态*/
            bool is_bind_pwr = mac_address_is_valid(bambu_mqtt_master->nvs_config.pwr_mac_addr); 
            ui_img_pwr_status_icon_set(master_icon_pwr,bambu_mqtt_master->pwr_data.is_online,is_bind_pwr);
 
            #ifdef CONFIG_BAT_UPDATE_IVT_MS
            if (CONFIG_BAT_FIRMWARE_VERSION == current_bat_status.fw_version)
            {
                if (last_bat_status.is_charging != current_bat_status.is_charging)
                {  
                    if (0 == last_bat_status.is_charging)
                    {
                        animation_bat_charging_level=1;
                    } 

                    last_bat_status.is_charging=current_bat_status.is_charging;
                    last_bat_status.percent=0;
                }
                
                //if (master_icon_panel)
                {
                    #if 0
                    extern lv_obj_t * ui_label_backlight_percent;
                    extern lv_obj_t * ui_label_language_value;

                    lv_label_set_text_fmt(ui_label_auto_sleep_value,"%d",current_bat_status.bat_mv_5v); 
                    lv_label_set_text_fmt(ui_label_backlight_percent, "%d",(int)current_bat_status.compensate);
                    lv_label_set_text_fmt(ui_label_language_value, "%d",(int)current_bat_status.bat_mv);
                    #endif 

                    if (current_bat_status.is_charging)
                    {
                        if (ms_bat_charging < millis()) 
                        {
                            ms_bat_charging = millis() + 1000; // 1s

                            if (panel_battery_icon) lv_obj_del(panel_battery_icon);
                            panel_battery_icon = lv_bat_percent_icon_create(master_icon_panel, animation_bat_charging_level, lv_color_hex(LV_32BIT_COLOR_STATUS), lv_color_hex(LV_32BIT_BTT_GRAY_BG),true);
                            lv_obj_set_size(panel_battery_icon, 18, 20);  
                            animation_bat_charging_level++;
                            if (animation_bat_charging_level>3)
                            {
                                animation_bat_charging_level=1;
                            }
                        }
                    }
                    else
                    { 
                        if (ms_bat_charging < millis()) 
                        {
                            ms_bat_charging = millis() + CONFIG_BAT_DRAW_IVT_MS; // 1s
                            
                            int change_distance = abs(last_bat_status.percent - current_bat_status.percent);

                            if (change_distance > CONFIG_MIN_CHANGE_VALUE)
                            {
                                if (change_distance > CONFIG_MAX_CHANGE_VALUE)
                                {
                                    current_bat_status.percent_change_times=0;
                                }

                                current_bat_status.percent_change_times++;
                                if (current_bat_status.percent_change_times>=3)
                                {
                                    current_bat_status.percent_change_times=0;

                                    uint8_t bat_level = bat_percent_to_level(current_bat_status.percent);

                                    if (panel_battery_icon) lv_obj_del(panel_battery_icon);
                                    panel_battery_icon = lv_bat_percent_icon_create(master_icon_panel, bat_level, lv_color_hex(LV_32BIT_COLOR_STATUS), lv_color_hex(LV_32BIT_BTT_GRAY_BG),false);
                                    lv_obj_set_size(panel_battery_icon, 18, 20);  
                                    last_bat_status.percent=current_bat_status.percent;  
                                }
                            }
                            else
                            {
                                current_bat_status.percent_change_times=0;
                            }
                        }
                    } 
                }
            }
            
            // if (panel_battery_icon)
            // {
            //     if (ms_bat_first_update < millis()) 
            //     {
            //         ms_bat_first_update = millis() + 5000; 

            //         if (CONFIG_BAT_FIRMWARE_VERSION != current_bat_status.fw_version)
            //         {
            //             if (!lv_obj_has_flag(panel_battery_icon,LV_OBJ_FLAG_HIDDEN))
            //             {
            //                 lv_obj_add_flag(panel_battery_icon,LV_OBJ_FLAG_HIDDEN);
            //             }
            //         }
            //         else
            //         {
            //             if (lv_obj_has_flag(panel_battery_icon,LV_OBJ_FLAG_HIDDEN))
            //             {
            //                 lv_obj_clear_flag(panel_battery_icon,LV_OBJ_FLAG_HIDDEN); 
            //             }
            //         }
            //     }
            // }
            
            #endif
        }
    }

    ui_title_status_t title_status = title_get_status_from_wifi(wifi_status);

    static char s_sta_ssid[MAX_LEN_SSID];
    wifi_sync_lock(0);
    if (UI_TOP_TITLE_IDLE != title_status && strcmp(s_sta_ssid, g_wifi_data->nvs_wifi_config.sta_ssid) != 0) {
        strlcpy(s_sta_ssid, g_wifi_data->nvs_wifi_config.sta_ssid, sizeof(s_sta_ssid));
        s_title_status = UI_TOP_TITLE_REFRESH; // refresh
    }
    wifi_sync_unlock();
    
    static uint32_t next_ms = 0;
    if (next_ms > millis()) return;

    printer_group_sync_lock(0);
    uint8_t get_ctl_type = group_sync_data.control_type;
    printer_group_sync_unlock();
    
    mqtt_sync_lock(0);
    uint8_t get_printer_cnt = mqtt_sync_data.printer_cnt; 
    mqtt_sync_unlock();

    if (UI_TOP_TITLE_IDLE != title_status)
        goto end;
        
    //priter status when wifi is connected
    for (uint8_t c_i = 0; c_i < ARRAY_SIZE(connect_flags); c_i++) {
        for (uint8_t i = 0; i < get_printer_cnt; i++) {
            // The connection status will only be displayed after a normal WiFi connection 
            bambu_mqtt_t * mqtt = bambu_get_mqtt(i); 
            if (mqtt->nvs_config.connect_flag != connect_flags[c_i]) continue;
            title_status = title_get_status_from_printer(mqtt->status, i);
            if (UI_TOP_TITLE_IDLE == title_status)  continue;
            /*如果显示的标题名字发生变化，需要更新*/
            if (strcmp(s_printer_name, mqtt->nvs_config.name) != 0) {
                strlcpy(s_printer_name, mqtt->nvs_config.name, sizeof(s_printer_name));
                s_title_status = UI_TOP_TITLE_REFRESH; // refresh 
            }
            /*如果序号发生变化，需要更新*/
            if (s_printer_index != i) {
                s_printer_index = i; 
                s_title_status = UI_TOP_TITLE_REFRESH; // refresh
            }
            goto end;
        }
    }

end:
    if ((s_title_status != title_status) 
        || (get_ctl_type_last != get_ctl_type)
        || (bambu_mqtt_master_last != bambu_mqtt_master)
        || (require_update))
    {
        if (bambu_mqtt_master_last != bambu_mqtt_master)
        {
            /*master发生变化时 重置忽略FINISH和CANCEL*/
            if (bambu_mqtt_master_last)
            {
                bambu_mqtt_master_last->bambu_data.gcode_state_idle=GCODE_STATE_IDLE;
            } 
        }

        require_update=false;
        get_ctl_type_last = get_ctl_type;
        bambu_mqtt_master_last = bambu_mqtt_master;
        s_title_status = title_status;
        lv_obj_t * obj = ui_label_ctl_title;
        ui_title_context_t * context = (ui_title_context_t *)ui_title_context + title_status;

        lv_obj_set_style_text_font(obj, context->font_size, LV_PART_MAIN);
        lv_obj_set_style_text_color(obj, lv_color_hex(context->font_color), LV_PART_MAIN);
 
        switch (s_title_status) {
            case UI_TOP_TITLE_IDLE:  
                if (PRT_CTL_SINGLE == get_ctl_type)
                {
                    lv_label_set_text_fmt(obj, "P-<%s>",bambu_mqtt_master->nvs_config.name);
                }
                else if (PRT_CTL_GROUP == get_ctl_type)
                {
                    printer_group_sync_lock(0);
                    printer_group_t *get_group_leader = printer_group_get_leader();
                    if (get_group_leader)
                    {
                        lv_label_set_text_fmt(obj, "G-<%s>\\<%s>",get_group_leader->nvs_config.name,bambu_mqtt_master->nvs_config.name);
                    }
                    printer_group_sync_unlock();
                } 
                break;
            case UI_TOP_TITLE_WIFI_CONNECTING:
                lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), s_sta_ssid);
                break;
            case UI_TOP_TITLE_WIFI_FAILED:
                ui_panel_create_popup(&popup_wifi_error, NULL);
                lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), s_sta_ssid);
                break;
            case UI_TOP_TITLE_WIFI_DISCONNECT:
                ui_panel_create_popup(&popup_wifi_disconnet, NULL);
                lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), s_sta_ssid);
                break;
            case UI_TOP_TITLE_PRINTER_CONNECTED:
                next_ms = millis() + 2000; // 2s
            case UI_TOP_TITLE_PRINTER_CONNECTING:
            case UI_TOP_TITLE_PRINTER_FAILED:
                if (ut_str_not_blank(s_printer_name))
                {
                    lv_label_set_text_fmt(obj, RS_TRANSLATE(context->context), printer_nvs_idx_to_sorted_idx(s_printer_index) + 1, s_printer_name);
                }
                break;
            default:
                break;
        }
    }
    #endif
}