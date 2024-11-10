#include "lv_ui_overlay.h"

enum {
    LV_LABEL_TITLE = 1,
    LV_TEXTAREA_TXT,
    LV_BTN_PWD_MODE,
    LV_BTN_OK,
    LV_BTN_CANCEL,
};

static uint32_t textarea_min_len = 0;

static void lv_widget_keyboard_ok(lv_event_t * e) {
    lv_obj_t * btn_ok = lv_event_get_target(e);
    lv_obj_t * panel_context = lv_obj_get_parent(btn_ok);
    lv_obj_t * panel_kerboard = lv_obj_get_parent(panel_context);
    lv_obj_t * label_title = ui_obj_get(panel_context, UI_TYPE_KEYBOARD_LABEL_TITLE);
    lv_obj_t * textarea = ui_obj_get(panel_context, UI_TYPE_KEYBOARD_TEXTAREA_TXT);

    lv_keyboard_user_data_t * d = (lv_keyboard_user_data_t * )panel_kerboard->user_data;

    if (d) {
        d->cb_t(d->obj, lv_label_get_text(label_title), lv_textarea_get_text(textarea),d->bssid);
    }

    lv_obj_del_async(panel_kerboard);
}

static void lv_widget_keyboard_remove(lv_event_t * e) {
    lv_obj_t * btn_cancel = lv_event_get_target(e);
    lv_obj_t * panel_context = lv_obj_get_parent(btn_cancel);
    lv_obj_del_async(lv_obj_get_parent(panel_context));
}

static void lv_widget_keyboard_textarea_changed(lv_event_t * e) {
    lv_obj_t * text_context = lv_event_get_target(e);
    lv_obj_t * panel_context = lv_obj_get_parent(text_context);
    lv_obj_t * btn_ok = ui_obj_get(panel_context, UI_TYPE_KEYBOARD_BTN_OK);

    const char *str = lv_textarea_get_text(text_context);
    uint16_t len = strlen(str);

    if (len < textarea_min_len) {
        lv_obj_add_state(btn_ok, LV_STATE_DISABLED);
    }
    else {
        lv_obj_clear_state(btn_ok, LV_STATE_DISABLED);
    }
}

static void lv_widget_keyboard_password_mode(lv_event_t * e) {
    lv_obj_t * btn_pwd = lv_event_get_target(e);
    lv_obj_t * textarea = lv_obj_get_parent(btn_pwd);

    bool pwd_mode = !lv_textarea_get_password_mode(textarea);
    lv_textarea_set_password_mode(textarea, pwd_mode);    
    lv_obj_set_style_img_recolor_opa(btn_pwd, pwd_mode ? 0 : 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}

static const char * btnm_num_map[] = {
    "1", "2", "3", LV_SYMBOL_BACKSPACE, "\n",
    "4", "5", "6", ".", "\n",
    "7", "8", "9", " ", "\n",
    LV_SYMBOL_LEFT, "0", LV_SYMBOL_RIGHT, LV_SYMBOL_KEYBOARD, ""
};
static const lv_btnmatrix_ctrl_t ctrl_btnm_num_map[] = {
    1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    LV_BTNMATRIX_CTRL_CHECKED | 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1, LV_KEYBOARD_CTRL_BTN_FLAGS | 1
};

static const char * btnm_123_abc_map[] = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
    " ", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", " ", "\n",
    LV_SYMBOL_LEFT, "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_RIGHT, "\n",
    "ABC", "...", "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_KEYBOARD, ""
};

static const char * btnm_123_ABC_map[] = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
    " ", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", " ", "\n",
    LV_SYMBOL_LEFT, "A", "S", "D", "F", "G", "H", "J", "K", "L", LV_SYMBOL_RIGHT, "\n",
    "abc", "...", "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_KEYBOARD, ""
};

static const lv_btnmatrix_ctrl_t ctrl_btnm_123_text_map[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1,
    LV_BTNMATRIX_CTRL_HIDDEN | 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, LV_BTNMATRIX_CTRL_HIDDEN | 1,
    LV_BTNMATRIX_CTRL_CHECKED | 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1,
    LV_KEYBOARD_CTRL_BTN_FLAGS | 1, LV_KEYBOARD_CTRL_BTN_FLAGS | 1, 1, 1, 1, 1, 1, 1, 1, LV_KEYBOARD_CTRL_BTN_FLAGS | 2,
};

static const lv_btnmatrix_ctrl_t ctrl_btnm_spec_map[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1,
    LV_BTNMATRIX_CTRL_HIDDEN | 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, LV_BTNMATRIX_CTRL_HIDDEN | 1,
    LV_BTNMATRIX_CTRL_CHECKED | 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1,
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, 1, 5, 1, LV_KEYBOARD_CTRL_BTN_FLAGS | 2,
};

static const char * btnm_num_spec_map[] = {
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", LV_SYMBOL_BACKSPACE, "\n",
    " ", "_", "+", "-", "=", "{", "}", "[", "]", "\\", ":", " ", "\n",
    LV_SYMBOL_LEFT, "\"", ";", "'", "<", ">", "?", ",", ".", "/", LV_SYMBOL_RIGHT, "\n",
    "Back", "~", " ", "`", LV_SYMBOL_KEYBOARD, ""
};


lv_obj_t * lv_widget_keyboard_create(lv_obj_t * parent, const lv_keyboard_mode_t mode, const lv_keyboard_user_data_t * d,
                                    const char * title, const char * text, const char * placeholde, bool pwd_mode,
                                    uint32_t min_len, uint32_t max_len) {
    lv_obj_t * panel_kerboard = ui_panel_create(parent, 0, lv_color_hex(0x000000)); 
    /*这里使用内部的16号字体*/ 
    lv_obj_set_size(panel_kerboard, 800, 480);
    lv_obj_align(panel_kerboard, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_opa(panel_kerboard, 100, LV_PART_MAIN);
    lv_obj_set_user_data(panel_kerboard, (void *)d);
    lv_obj_add_event_cb(panel_kerboard, ui_del_myself_clicked, LV_EVENT_CLICKED, NULL);

    lv_obj_t * panel_context = ui_panel_create(panel_kerboard, 15, lv_color_hex(0x838383));
    lv_obj_set_size(panel_context, 500, 185);
    lv_obj_align(panel_context, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_style_text_font(panel_kerboard, &opensansb16, LV_PART_MAIN);

    lv_obj_t * label_title = lv_label_create(panel_context);
    ui_obj_set_type(label_title, UI_TYPE_KEYBOARD_LABEL_TITLE);
    lv_obj_set_size(label_title, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(label_title, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_set_style_text_font(label_title,LV_FONT_16_VARIABLE,0);
    if (title)
        lv_label_set_text(label_title, title);

    lv_obj_t * text_context = lv_textarea_create(panel_context);
    ui_obj_set_type(text_context, UI_TYPE_KEYBOARD_TEXTAREA_TXT);
    lv_obj_set_size(text_context, 450, LV_SIZE_CONTENT);
    lv_obj_align(text_context, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_style_text_font(text_context,LV_FONT_16_VARIABLE,LV_STATE_DEFAULT);

    lv_textarea_set_one_line(text_context, true);
    if (text)
        lv_textarea_set_text(text_context, text);
    if (placeholde)
        lv_textarea_set_placeholder_text(text_context, placeholde);
    lv_textarea_set_max_length(text_context, max_len);
    // lv_obj_clear_flag(text_context, LV_OBJ_FLAG_SCROLLABLE);
    textarea_min_len = min_len;

    if (pwd_mode) {
        lv_textarea_set_password_mode(text_context, true);
        lv_obj_t * btn_pwd = lv_imgbtn_create(text_context);
        ui_obj_set_type(btn_pwd, UI_TYPE_KEYBOARD_BTN_PWD_MODE);
        lv_imgbtn_set_src(btn_pwd, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_pwd_mode_png, NULL);
        lv_obj_set_size(btn_pwd, 20, 20);
        lv_obj_align(btn_pwd, LV_ALIGN_RIGHT_MID, 0, 0);
        lv_obj_set_style_img_recolor(btn_pwd, lv_color_hex(LV_32BIT_BTT_RED), LV_PART_MAIN| LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor_opa(btn_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_event_cb(btn_pwd, lv_widget_keyboard_password_mode, LV_EVENT_CLICKED, NULL);
        lv_obj_add_flag(btn_pwd, LV_OBJ_FLAG_FLOATING);
    }

    lv_obj_t * btn_cancel = ui_btn_label_create(panel_context, 220, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(K_BTN_CANCEL));

    ui_obj_set_type(btn_cancel, UI_TYPE_KEYBOARD_BTN_CANCEL);
    lv_obj_align(btn_cancel, LV_ALIGN_BOTTOM_LEFT, 20, -20);
        
    lv_obj_t * btn_ok = ui_btn_label_create(panel_context, 220, 50, 13, lv_color_hex(LV_32BIT_BTT_RED), RS_TRANSLATE(K_BTN_OK));

    ui_obj_set_type(btn_ok, UI_TYPE_KEYBOARD_BTN_OK);
    lv_obj_align(btn_ok, LV_ALIGN_BOTTOM_RIGHT, -20, -20);
    if (min_len)
        lv_obj_add_state(btn_ok, LV_STATE_DISABLED);

    lv_obj_t * keyboard = lv_keyboard_create(panel_kerboard);
    lv_obj_set_style_text_font(keyboard, &opensansb16, LV_PART_MAIN);
    lv_obj_set_size(keyboard, (mode == LV_KEYBOARD_MODE_NUMBER) ? 500 : 800, 275);
    lv_keyboard_set_mode(keyboard, mode);

    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_NUMBER, btnm_num_map, ctrl_btnm_num_map);
    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER, btnm_123_abc_map, ctrl_btnm_123_text_map);
    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_TEXT_UPPER, btnm_123_ABC_map, ctrl_btnm_123_text_map);
    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_SPECIAL, btnm_num_spec_map, ctrl_btnm_spec_map);
    void ui_keyboard_event_cb(lv_event_t * e);
    lv_obj_remove_event_cb(keyboard, lv_keyboard_def_event_cb);
    lv_obj_add_event_cb(keyboard, ui_keyboard_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_align(keyboard, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(keyboard, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_event_send(text_context, LV_EVENT_FOCUSED, NULL);
    lv_keyboard_set_textarea(keyboard, text_context);

    lv_obj_add_event_cb(btn_cancel, lv_widget_keyboard_remove, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(btn_ok, lv_widget_keyboard_ok, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(text_context, lv_widget_keyboard_textarea_changed, LV_EVENT_VALUE_CHANGED, NULL);

    return panel_kerboard;
}

void ui_keyboard_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    static lv_keyboard_mode_t keyboard_mode = LV_KEYBOARD_MODE_TEXT_LOWER;
    static lv_keyboard_mode_t mode = LV_KEYBOARD_MODE_TEXT_LOWER;

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_keyboard_t * keyboard = (lv_keyboard_t *)obj;
    uint16_t btn_id   = lv_btnmatrix_get_selected_btn(obj);
    if(btn_id == LV_BTNMATRIX_BTN_NONE) return;

    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if(txt == NULL) return;

    if(strcmp(txt, "abc") == 0) {
        lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_LOWER);
        return;
    }
    else if(strcmp(txt, "ABC") == 0) {
        lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_UPPER);
        return;
    }
    else if(strcmp(txt, "...") == 0) {
        mode = lv_keyboard_get_mode(obj);
        lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_SPECIAL);
        return;
    } else if (strcmp(txt, "Back") == 0) {
        lv_keyboard_set_mode(obj, mode);
        return;
    }
    else if(strcmp(txt, LV_SYMBOL_KEYBOARD) == 0) {
        lv_keyboard_mode_t now = lv_keyboard_get_mode(obj);
        if (now == LV_KEYBOARD_MODE_NUMBER) {
            lv_keyboard_set_mode(obj, keyboard_mode);
            lv_obj_set_width(obj, 800);
        } else {
            keyboard_mode = now;
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_set_width(obj, 500);
        }
        return;
    }

    /*Add the characters to the text area if set*/
    if(keyboard->ta == NULL) return;

    if(strcmp(txt, LV_SYMBOL_LEFT) == 0) {
        lv_textarea_cursor_left(keyboard->ta);
    }
    else if(strcmp(txt, LV_SYMBOL_RIGHT) == 0) {
        lv_textarea_cursor_right(keyboard->ta);
    }
    else if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        lv_textarea_del_char(keyboard->ta);
    }
    else {
        lv_textarea_add_text(keyboard->ta, txt);
    }
}

