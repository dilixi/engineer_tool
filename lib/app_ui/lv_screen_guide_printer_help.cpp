#include "app.h"

static lv_point_t line_points[] = { {0, 0}, {0, 50}};

#define LABLE_CONTEXT_PADDING   (15)
#define LABLE_CONTEXT_MAX_WIDTH (500 - LABLE_CONTEXT_PADDING * 2)

typedef struct {
   MLG_KEY_TYPE title;
   const void * img_src;
   MLG_KEY_TYPE context;
   const lv_align_t label_align;
   const lv_coord_t text_x_ofs;
   const lv_coord_t text_y_ofs;
   const lv_text_align_t text_align;
   const lv_coord_t line_x_ofs;
   const lv_coord_t line_height;
   bool qr_en;
} ui_help_t;

lv_img_dsc_t ui_img_guide_1_en_png={NULL};
lv_img_dsc_t ui_img_guide_2_en_png={NULL};
lv_img_dsc_t ui_img_guide_3_en_png={NULL};
lv_img_dsc_t ui_img_guide_4_en_png={NULL};
lv_img_dsc_t ui_img_guide_5_en_png={NULL};
lv_img_dsc_t ui_img_guide_1_cn_png={NULL};
lv_img_dsc_t ui_img_guide_2_cn_png={NULL};
lv_img_dsc_t ui_img_guide_3_cn_png={NULL};
lv_img_dsc_t ui_img_guide_4_cn_png={NULL};
lv_img_dsc_t ui_img_guide_5_cn_png={NULL};

lv_img_dsc_t *ui_img_guides_current[]= 
{
    &ui_img_guide_1_png,
    &ui_img_guide_2_png,
    &ui_img_guide_3_png,
    &ui_img_guide_4_png,
    &ui_img_guide_5_png,
};

static lv_img_dsc_t *ui_img_guides_en[]= 
{
    &ui_img_guide_1_en_png,
    &ui_img_guide_2_en_png,
    &ui_img_guide_3_en_png,
    &ui_img_guide_4_en_png,
    &ui_img_guide_5_en_png,
};

static lv_img_dsc_t *ui_img_guides_cn[]= 
{
    &ui_img_guide_1_cn_png,
    &ui_img_guide_2_cn_png,
    &ui_img_guide_3_cn_png,
    &ui_img_guide_4_cn_png,
    &ui_img_guide_5_cn_png,
};

const ui_help_t ui_help[] = {
    {K_GUID_T_START, ui_img_guides_current[0], K_GUID_C_START,
     LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 240, LV_TEXT_ALIGN_CENTER, 0, 0, false},
    {K_GUID_T_GET_IP_ACCESS, ui_img_guides_current[1],K_GUID_C_GET_IP_ACCESS_WLAN,
     LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 240, LV_TEXT_ALIGN_RIGHT, -105, 50, false},
    {K_GUID_T_GET_IP_ACCESS, ui_img_guides_current[2], K_GUID_C_GET_IP_ACCESS_ENTER,
     LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 240, LV_TEXT_ALIGN_CENTER, -235, 50, false},
    {K_GUID_T_GET_SN, ui_img_guides_current[1], K_GUID_C_GET_SN_RETURN,
     LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 240, LV_TEXT_ALIGN_RIGHT, -25, 50, false},
    {K_GUID_T_GET_SN, ui_img_guides_current[3], K_GUID_C_GET_SN_ENTER,
     LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 240, LV_TEXT_ALIGN_RIGHT, -105, 50, false}, 
	 {K_GUID_T_GET_SN, ui_img_guides_current[4], K_GUID_C_GET_SN_ENTER_CODE, 
	 LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 240, LV_TEXT_ALIGN_LEFT, -295, 90, false},
	 {K_GUID_T_COMPLETED, NULL,K_GUID_C_COMPLETED,
     LV_ALIGN_TOP_LEFT, LABLE_CONTEXT_PADDING, 220, LV_TEXT_ALIGN_LEFT, 0, 0, false},
    {K_GUID_UNABLE_FIND, NULL, K_TIP_SCAN_QRCODE,
     LV_ALIGN_BOTTOM_LEFT, LABLE_CONTEXT_PADDING * 2 + 160, -LABLE_CONTEXT_PADDING, LV_TEXT_ALIGN_LEFT, 0, 0, true},
};

typedef struct {
   lv_obj_t * panel_parent;
   lv_obj_t * title;
   lv_obj_t * img_bg;
   lv_obj_t * img;
   lv_obj_t * context;
   lv_obj_t * line;
   lv_obj_t * qr;
   lv_obj_t * index;
   uint8_t step;
} ui_help_obj_t;

void translate_guid_img(uint8_t set_lang)
{ 
    uint8_t guide_cnt = LENGTH_OF_ARRAY(ui_img_guides_current);
    
    if (LANG_2 == set_lang)
    {
        for (uint8_t guide_idx=0; guide_idx<guide_cnt; guide_idx++)
        {
            lv_img_dsc_t *get_img_cur = ui_img_guides_current[guide_idx];
            lv_img_dsc_t *get_img_cn = ui_img_guides_cn[guide_idx]; 

            memcpy(get_img_cur,get_img_cn,sizeof(lv_img_dsc_t));
        }
    }
    else //if(LANG_2 == set_lang)
    {
        /*其他语言暂时不支持翻译*/
        for (uint8_t guide_idx=0; guide_idx<guide_cnt; guide_idx++)
        {
            lv_img_dsc_t *get_img_cur = ui_img_guides_current[guide_idx];
            lv_img_dsc_t *get_img_en = ui_img_guides_en[guide_idx]; 
            memcpy(get_img_cur,get_img_en,sizeof(lv_img_dsc_t));
        }
    }
}

void ui_guide_printer_help_set_step(ui_help_obj_t * p_help_obj, uint8_t step) {
    const ui_help_t * p_help = &ui_help[step];
    lv_label_set_text_static(p_help_obj->title, RS_TRANSLATE(p_help->title));
    if (p_help->img_src == NULL) {
        if (!lv_obj_has_flag_any(p_help_obj->img, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_add_flag(p_help_obj->img, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(p_help_obj->img_bg, LV_OBJ_FLAG_HIDDEN);
        }
    } else { 
        lv_img_set_src(p_help_obj->img, p_help->img_src);
        if (lv_obj_has_flag_any(p_help_obj->img, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_clear_flag(p_help_obj->img, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(p_help_obj->img_bg, LV_OBJ_FLAG_HIDDEN);
        }
    }
    if (p_help->line_x_ofs == 0) {
        if (!lv_obj_has_flag_any(p_help_obj->line, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_add_flag(p_help_obj->line, LV_OBJ_FLAG_HIDDEN);
        }
    } else {
        line_points[1].y = p_help->line_height;
        lv_obj_set_x(p_help_obj->line, p_help->line_x_ofs);
        if (lv_obj_has_flag_any(p_help_obj->line, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_clear_flag(p_help_obj->line, LV_OBJ_FLAG_HIDDEN);
        }
    }
    lv_label_set_text_static(p_help_obj->context, RS_TRANSLATE(p_help->context));
    lv_obj_set_style_text_align(p_help_obj->context, p_help->text_align, LV_PART_MAIN);
    lv_obj_align(p_help_obj->context, p_help->label_align, p_help->text_x_ofs, p_help->text_y_ofs);
    lv_obj_set_width(p_help_obj->context, LABLE_CONTEXT_MAX_WIDTH - p_help->text_x_ofs);

    if (p_help->qr_en) {
        if (lv_obj_has_flag_any(p_help_obj->qr, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_clear_flag(p_help_obj->qr, LV_OBJ_FLAG_HIDDEN);
        }
    } else {
        if (!lv_obj_has_flag_any(p_help_obj->qr, LV_OBJ_FLAG_HIDDEN)) {
            lv_obj_add_flag(p_help_obj->qr, LV_OBJ_FLAG_HIDDEN);
        }
    }

    lv_label_set_text_fmt(p_help_obj->index, "%d/%d", step + 1, ARRAY_SIZE(ui_help));
    p_help_obj->step = step;
}

void panel_info_gesture(lv_event_t * e) {
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    ui_help_obj_t * p_help_obj = (ui_help_obj_t *)lv_event_get_user_data(e);
    uint32_t step = p_help_obj->step;

    if(dir == LV_DIR_LEFT && step < ARRAY_SIZE(ui_help) - 1) {
        ui_guide_printer_help_set_step(p_help_obj, step + 1);
    } else if(dir == LV_DIR_RIGHT && step > 0) {
        ui_guide_printer_help_set_step(p_help_obj, step - 1);
    }
}

ui_help_obj_t ui_help_obj;
ui_help_obj_t * p_help_obj = &ui_help_obj;
void ui_panel_create_guide_printer_help(void) {
    // lv_obj_t * panel_bg = ui_panel_create(ui_screen_main, 15, lv_color_hex(0x444444));
    lv_obj_t * panel_bg = ui_panel_create(ui_screen_main, 0, lv_color_hex(0x000000));
    lv_obj_set_style_bg_opa(panel_bg, 100, LV_PART_MAIN);
    lv_obj_set_size(panel_bg, 800, 480);
    lv_obj_set_align(panel_bg, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(panel_bg, ui_del_myself_clicked, LV_EVENT_CLICKED, panel_bg);

    lv_obj_t * panel = ui_panel_create(panel_bg, 15, lv_color_hex(0x575757));
    lv_obj_set_size(panel, 550, 400);
    lv_obj_set_align(panel, LV_ALIGN_CENTER);

    // ui_help_obj_t * p_help_obj = (ui_help_obj_t *)lv_mem_alloc(sizeof(ui_help_obj_t));

    lv_obj_t * panel_info = ui_panel_create(panel, 15, lv_color_hex(0x838383));
    lv_obj_set_size(panel_info, 500, 300);
    lv_obj_set_align(panel_info, LV_ALIGN_CENTER);    
    lv_obj_clear_flag(panel_info, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(panel_info, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t * title = lv_label_create(panel_info);
    lv_obj_align(title, LV_ALIGN_TOP_LEFT, 20, 20);
    lv_obj_set_width(title, LABLE_CONTEXT_MAX_WIDTH);
    lv_obj_set_style_text_font(title, LV_FONT_DEFAULT_24, LV_PART_MAIN);

    lv_obj_t * img_bg = lv_img_create(panel_info); 
    lv_img_set_src(img_bg, &ui_img_guide_bg_png);
    lv_obj_set_align(img_bg, LV_ALIGN_CENTER);
    
    lv_obj_t * img = lv_img_create(img_bg);
    lv_obj_align(img, LV_ALIGN_LEFT_MID, 22, 0);

    lv_obj_t * line = ui_line_create(panel_info, line_points, 2, 1, lv_color_hex(0xFFFFFF));
    lv_obj_align(line, LV_ALIGN_BOTTOM_RIGHT, 0, -60);

    lv_obj_t * context = lv_label_create(panel_info);

    lv_obj_t * qr = lv_qrcode_create(panel_info, 160, LV_COLOR_MAKE(0, 0, 0), LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_qrcode_update(qr, MANUAL_CONNECTION, strlen(MANUAL_CONNECTION));
    lv_obj_align(qr, LV_ALIGN_BOTTOM_LEFT, LABLE_CONTEXT_PADDING, -LABLE_CONTEXT_PADDING);

    lv_obj_t * index = lv_label_create(panel);
    lv_obj_align(index, LV_ALIGN_BOTTOM_MID, 0, -15);

    p_help_obj->panel_parent = panel_bg;
    p_help_obj->title = title;
    p_help_obj->img_bg = img_bg;
    p_help_obj->img = img;
    p_help_obj->context = context;
    p_help_obj->line = line;
    p_help_obj->qr = qr;
    p_help_obj->index = index;
    ui_guide_printer_help_set_step(p_help_obj, 0);

    lv_obj_add_event_cb(panel_info, panel_info_gesture, LV_EVENT_GESTURE, p_help_obj);
}
