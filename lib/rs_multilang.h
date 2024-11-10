
#ifndef __RS_MULTILANG_H
#define __RS_MULTILANG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils_lib.h"

#define MLG_TRANSLATE_EVENT_T_SKIP              rs_translate_cb_skip 

#define RS_TRANSLATE_ONCE_ONLY(KEY)             _(KEY)
//#define MLG_TRANSLATE_INIT_ONCE(KEY)            _(KEY)
#define RS_TRANSLATE_DEFAULT_CB        NULL

#define MLG_TRANSLATE_NOT_CHANGE(KEY)            (KEY)
 




#include "core/lv_obj.h" 
#include "core/lv_event.h" 

#define LV_OBJ_FLAG_MULTI_LANG LV_OBJ_FLAG_USER_4






typedef enum
{
    KEY_NULL=0,
    KEY_STRING,
    KEY_NUMBER,
    KEY_CUSTOM, 
}MLG_KEY_DATA_T;



extern void rs_lang_init(void);
extern void rs_set_local(uint8_t set_lang);

extern void rs_translate(lv_obj_t *parent);
extern uint8_t rs_get_lang_cnt(void);
  


extern uint8_t rs_get_lang_type(void);
extern uint8_t rs_lang_type_is_valid(uint8_t check_type);

extern void rs_add_translate_cb(lv_obj_t *obj, lv_event_cb_t set_cb,void *set_key,uint8_t key_type); 
extern void rs_translate_cb_skip(lv_event_t * e);
extern uint8_t rs_lang_key_is_valid(pointer_type check_key);   


extern lv_obj_t * ui_label_language_value;
extern lv_obj_t * ui_label_auto_sleep_value;
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif










