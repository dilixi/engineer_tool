#include "utils_lib.h"  
#include "lv_ui_overlay.h"  

static lv_obj_t * ui_panel_printer_popup[BAMBU_PRINTER_MAX_NUM + 1]; 
static void user_popup_clicked(uint32_t btn_id, const void * cb_data, bambu_mqtt_t * mqtt) {
 
}

static void btn_popup_clicked(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * panel = lv_obj_get_parent(btn);
    ui_popup_t * popup = (ui_popup_t *)lv_obj_get_user_data(panel);
    lv_obj_t * panel_bg = lv_obj_get_parent(panel);
    bambu_mqtt_t * mqtt = (bambu_mqtt_t *)lv_obj_get_user_data(panel_bg);

    uint32_t btn_id = (uint32_t)(pointer_type)lv_event_get_user_data(e);
    if (popup->popup_cb) {
        popup->popup_cb(btn_id, popup->cb_data, mqtt);
    } else {
        user_popup_clicked(btn_id, popup->cb_data, mqtt);
    }

    lv_obj_del_async(panel_bg);
    uint8_t index = BAMBU_PRINTER_MAX_NUM;
    if (mqtt) { 
        index = bambu_get_mqtt_index(mqtt); 
        if (!bambu_printer_index_valid(index))
        {
            index=BAMBU_PRINTER_MAX_NUM;
        }
    }
    ui_panel_printer_popup[index] = NULL;
}

lv_obj_t * ui_panel_create_popup(const ui_popup_t * data, bambu_mqtt_t * mqtt) {
    uint8_t index = BAMBU_PRINTER_MAX_NUM;
    if (mqtt) { 
        index = bambu_get_mqtt_index(mqtt); 
        if (!bambu_printer_index_valid(index))
        {
            index=BAMBU_PRINTER_MAX_NUM;
        }
    }
    if (ui_panel_printer_popup[index]) {
        lv_obj_del(ui_panel_printer_popup[index]);
        ui_panel_printer_popup[index] = NULL;
    }
    ui_panel_printer_popup[index] = ui_panel_create(lv_layer_top(), 0, lv_color_hex(0x000000));
    lv_obj_set_user_data(ui_panel_printer_popup[index], mqtt);
    lv_obj_set_style_bg_opa(ui_panel_printer_popup[index], 100, LV_PART_MAIN);
    lv_obj_set_size(ui_panel_printer_popup[index], 800, 480);

    lv_obj_t * panel = ui_panel_create(ui_panel_printer_popup[index], 8, lv_color_hex(0x575757));
    lv_obj_set_user_data(panel, (void *)data);
    lv_obj_set_size(panel, 480, 280);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_hor(panel, 20, LV_PART_MAIN);
    lv_obj_set_style_pad_ver(panel, 10, LV_PART_MAIN);
    //index
    lv_coord_t y_context_start = 0;
    lv_coord_t y_context_size = (280 - 20);
    if (mqtt) {
        /*如果是组控制模式下，这里的序号会被排序影响*/
        lv_obj_t * sequence = ui_panel_create_index(panel, printer_nvs_idx_to_sorted_idx(index), 20, lv_color_hex(0x444444));
        lv_obj_align(sequence, LV_ALIGN_TOP_LEFT, 0, 0);
        const lv_font_t * font = lv_obj_get_style_text_font(panel, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);
        lv_obj_t * label_title = lv_label_create(panel);
        lv_obj_set_size(label_title, 400, LV_SIZE_CONTENT);
        lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, 25, 10 - font_h / 2);
        lv_label_set_text_static(label_title, mqtt->nvs_config.name);
        lv_obj_set_style_text_font(label_title,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT); 

        // lv_obj_set_style_bg_color(label_title, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
        // lv_obj_set_style_bg_opa(label_title, 255, LV_PART_MAIN);
        y_context_start = 30;
        y_context_size -= y_context_start;
    }
    if (data->btn_num) {
        y_context_size -= 70;
        /* must be static not const*/
        static lv_point_t h_line_points[] = { {0, 0}, {430, 0}};
        lv_obj_t * h_line = ui_line_create(panel, h_line_points, 2, 1, lv_color_hex(0x838383));
        lv_obj_align(h_line, LV_ALIGN_BOTTOM_MID, 0, -60);

        static lv_point_t v_line_points[] = { {0, 0}, {0, 50}};

        lv_coord_t btn_space = 5;
        lv_coord_t btn_total_width = 440 / data->btn_num;
        lv_coord_t btn_width = btn_total_width - btn_space * 2;

        for (uint8_t i = 0; i < data->btn_num - 1; i++) {
            lv_obj_t * v_line = ui_line_create(panel, v_line_points, 2, 1, lv_color_hex(0x838383));
            lv_obj_align(v_line, LV_ALIGN_BOTTOM_LEFT, btn_total_width * (i + 1), 0);
        }

        for (uint8_t i = 0; i < data->btn_num; i++) {
            lv_obj_t * btn = ui_btn_label_create(panel, btn_width, 50, 13, lv_color_hex(0x575757), RS_TRANSLATE(data->btn_text[i]));
            lv_obj_align(btn, LV_ALIGN_BOTTOM_LEFT, btn_space + btn_total_width * i, 0);
            lv_obj_add_event_cb(btn, btn_popup_clicked, LV_EVENT_CLICKED, (void *)data->btn_id[i]);
        }
    }

    lv_coord_t x_qr_occupy = 0;
    lv_coord_t width_panel = 440 - x_qr_occupy;
    lv_obj_t * panel_label = ui_panel_create(panel, 0, lv_color_hex(0x000000));
    lv_obj_set_style_bg_opa(panel_label, 0, LV_PART_MAIN);
    lv_obj_set_size(panel_label, width_panel, y_context_size);
    lv_obj_align(panel_label, LV_ALIGN_TOP_RIGHT, 0, y_context_start);

    lv_obj_t * label_context = lv_label_create(panel_label);

    // if ((K_INVALID_ID == data->text)
    //     && ut_str_not_blank(data->text_str))
    // {
    //     /*在外面翻译好了*/
    //     lv_label_set_text_static(label_context, data->text_str);
    // }
    // else
    // {
    //     lv_label_set_text_static(label_context, RS_TRANSLATE(data->text));
    // }

    if (LANG_2 == rs_get_lang_type()) 
    {
        if (strlen(lv_label_get_text(label_context)) < 16)
        {
            /*中文时 如果字数长度小于某个阈值就改为居中对齐*/
            lv_obj_set_style_text_align(label_context,LV_TEXT_ALIGN_CENTER,0);
        }
    }
    lv_obj_update_layout(label_context);
    lv_coord_t w_context = lv_obj_get_width(label_context);
    lv_obj_set_width(label_context, (w_context > width_panel) ? width_panel : LV_SIZE_CONTENT);
    lv_obj_update_layout(label_context);
    lv_coord_t h_context = lv_obj_get_height(label_context);
    lv_obj_align(label_context, (h_context > (y_context_size)) ? LV_ALIGN_TOP_MID : LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label_context,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT); 
    // lv_obj_set_style_bg_color(label_context, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(label_context, 255, LV_PART_MAIN);

    return ui_panel_printer_popup[index];
}

void ui_panel_del_popup(bambu_mqtt_t * mqtt) {
    uint8_t index = BAMBU_PRINTER_MAX_NUM;
    if (mqtt) { 
        index = bambu_get_mqtt_index(mqtt); 
        if (!bambu_printer_index_valid(index))
        {
            index=BAMBU_PRINTER_MAX_NUM;
        }
    }
    if (ui_panel_printer_popup[index] == NULL) return;

    lv_obj_del(ui_panel_printer_popup[index]);
    ui_panel_printer_popup[index] = NULL;
}

static void user_popup_account_clicked(uint32_t btn_id, const void * cb_data, void * account_info) {
    switch (btn_id) {      
        case UI_POPUP_BTN_CANCEL:
            break;
        default:
            break;
    }
}

static void btn_popup_account_clicked(lv_event_t * e) {
  
}
 
  