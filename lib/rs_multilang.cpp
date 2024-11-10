 
#include <stdio.h> // sprin 
#include "ui.h"
#include "rs_multilang.h" 
#include "utils_lib.h" 

#define SW_PRINT_MULTILANG 0

#if SW_PRINT_MULTILANG && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "rs_language"; 
#define PRINT_RS_LANG(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_RS_LANG(...)
#endif
       
extern void translate_guid_img(uint8_t);  

uint8_t g_language = LANG_MAX; 

const char * language_local_types[LANG_MAX+1] = 
{
    "en-GB","zh-cn","custom",NULL,
};

char * language_name_types[LANG_MAX+1] = 
{
    "English","简体中文","custom",NULL,
};

uint8_t rs_get_lang_cnt(void)
{
    return LANG_MAX;
} 
 
uint8_t rs_lang_type_is_valid(uint8_t check_type)
{
    if (check_type < LANG_MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t rs_lang_key_is_valid(pointer_type check_key)
{
    if (check_key > K_INVALID_ID)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t rs_get_lang_type(void)
{
    return g_language;
}

uint8_t rs_check_lang_invalid(void)
{
    return (g_language>=LANG_MAX);
}
 
void rs_set_local(uint8_t set_lang)
{
    PRINT_RS_LANG("set_lang[%d]\n",(int)set_lang);
    const char *l_name = language_local_types[set_lang];

    if (set_lang >= LANG_MAX)
    {
        const char *l_name = language_local_types[LANG_1];
        lv_i18n_set_locale(l_name);
        translate_guid_img(LANG_1); 
        return;
    }
 
    if (g_language != set_lang)
    {
        //nvs_config_set_changed(NVS_CONFIG_CHANGED);
    } 
    g_language = set_lang; 

    lv_i18n_set_locale(l_name); 
    translate_guid_img(set_lang); 
}

lv_font_t * font_16_fname = NULL;
lv_font_t * font_16_variable = NULL;
lv_font_t * font_24_variable = NULL;
 
void rs_lang_init(void)
{
    lv_i18n_init(lv_i18n_language_pack);
    #if CONFIG_USING_EXT_FONT
    font_16_fname = (lv_font_t *)&opensansb16_fname;// 
    font_24_variable = (lv_font_t *)&opensansb24_fname;  
    font_16_variable = (lv_font_t *)&opensansb16_fname;  
    #else
    font_16_fname = (lv_font_t *)&opensansb16;// 
    //font_24_variable = (lv_font_t *)&opensansb24;  
    font_24_variable = (lv_font_t *)&opensansb16;  
    font_16_variable = (lv_font_t *)&opensansb16;
    #endif  
    rs_set_local(g_language);

    sprintf(lang_names[0].name,"%s",language_name_types[0]);
    sprintf(lang_names[1].name,"%s",language_name_types[1]);
    sprintf(lang_names[2].name,"%s",language_name_types[2]);
}

void rs_set_local_update(void)
{
    lv_i18n_init(lv_i18n_language_pack);
    font_16_fname = (lv_font_t *)&opensansb16;   
    font_24_variable = (lv_font_t *)&opensansb16;  
    font_16_variable = (lv_font_t *)&opensansb16;  
    if (g_language >= LANG_MAX)
    {
        lv_i18n_set_locale(language_local_types[LANG_1]);
        return;
    }
    lv_i18n_set_locale(language_local_types[g_language]);
} 

void rs_set_local_only(uint8_t set_lang)
{ 
    lv_i18n_set_locale(language_local_types[set_lang]); 
}

void rs_translate(lv_obj_t *parent)
{
    if (!parent) 
    {
        PRINT_RS_LANG("parent null\n");
        return;
    } 
    for (uint32_t i = 0; i < lv_obj_get_child_cnt(parent); i++) 
    {
        lv_obj_t * obj = lv_obj_get_child(parent, i);
        
        if (obj)
        {
            if (lv_obj_has_flag(obj,LV_OBJ_FLAG_MULTI_LANG))
            {
                if (lv_obj_check_type(obj, &lv_label_class))
                { 
                    char * get_text = lv_label_get_text(obj);
 
                    lv_event_send(obj, LV_EVENT_REFRESH, NULL);
                }
                else if (lv_obj_check_type(obj, &lv_textarea_class))
                {
                    const char * get_text = lv_textarea_get_text(obj);
                    
                    //PRINT_RS_LANG("get_text =[%s]\n",get_text);

                    lv_event_send(obj, LV_EVENT_REFRESH, NULL);
                }
                else if (lv_obj_check_type(obj, &lv_checkbox_class))
                {
                    const char * get_text = lv_checkbox_get_text(obj);
                    
                    //PRINT_RS_LANG("get_text =[%s]\n",get_text);

                    lv_event_send(obj, LV_EVENT_REFRESH, NULL);
                } 
            }

            if (lv_obj_get_child_cnt(obj) > 0)
            {
                rs_translate(obj);
            }
        }
    }
}
 
static void event_handler_translate_default(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_REFRESH)
    {
        MLG_KEY_TYPE  get_key = (MLG_KEY_TYPE)(pointer_type)lv_event_get_user_data(e);

        if (rs_lang_key_is_valid(get_key))
        {
            lv_obj_t * obj = lv_event_get_target(e);

            if (lv_obj_has_flag(obj,LV_OBJ_FLAG_MULTI_LANG))
            {
                const char *set_text = RS_TRANSLATE(get_key);

                //PRINT_RS_LANG("refresh event with key[%ld] text[%s]\n",get_key,set_text);

                if (set_text)
                {
                    if (lv_obj_check_type(obj, &lv_checkbox_class))
                    {
                        lv_checkbox_set_text(obj, set_text);
                    }
                    else if (lv_obj_check_type(obj, &lv_textarea_class))
                    {
                        //lv_textarea_set_text(checkbox_account_type, set_text);
                    }
                    else
                    {
                        lv_label_set_text(obj, set_text);
                    } 
                }
            }
        }
    }
}

void rs_translate_cb_skip(lv_event_t * e)
{
    
}

void rs_add_translate_cb(lv_obj_t *obj, lv_event_cb_t set_cb,void * set_key, uint8_t key_type)
{
    #if 1
    if (!obj)
    {
        PRINT_RS_LANG("rs_add_translate_cb invalid obj\n");

        return;
    }

    if (MLG_TRANSLATE_EVENT_T_SKIP == set_cb)
    {
        PRINT_RS_LANG("MLG_TRANSLATE_EVENT_T_SKIP\n");

        return;
    }

    if (NULL == set_cb)
    {
        /*bind to a default event*/
        set_cb = event_handler_translate_default;
    }

    if (!rs_lang_key_is_valid((MLG_KEY_TYPE)(pointer_type)set_key))
    {
        PRINT_RS_LANG("invalid key\n");

        return;
    }

    if (lv_obj_check_type(obj,&lv_label_class))
    {
        //char * get_text = lv_label_get_text(obj);
        lv_obj_remove_event_cb(obj,set_cb);
        lv_obj_add_event_cb(obj, set_cb , LV_EVENT_REFRESH, set_key);
        lv_obj_add_flag(obj,LV_OBJ_FLAG_MULTI_LANG);

        if (KEY_STRING == key_type)
        {
            if (set_key)
            {
                /*need translate for first time*/
                //PRINT_RS_LANG("add event with label [%s],with key[%s]\n",get_text,(char *)set_key);
                
                //lv_label_set_text(obj, (const char *)RS_TRANSLATE((char *)set_key));
            }
        }
        else if (KEY_NUMBER == key_type)
        {
            lv_label_set_text(obj, (const char *)RS_TRANSLATE((MLG_KEY_TYPE)(pointer_type)set_key));
        }
        else if (KEY_CUSTOM == key_type)
        {
            //PRINT_RS_LANG("add event with label [%s] with [%x]\n",get_text,(unsigned int)set_key);
        }
    }
    else if ((lv_obj_check_type(obj,&lv_btn_class))
                || (lv_obj_check_type(obj,&lv_list_btn_class))
                || (lv_obj_check_type(obj,&lv_imgbtn_class)))
    {
        lv_obj_t *get_child = lv_obj_get_child(obj,0);

        if (get_child)
        {
            char * get_text = lv_label_get_text(get_child);

            if (KEY_STRING == key_type)
            {
                if (set_key)
                {
                    /*need translate for first time*/
                    //PRINT_RS_LANG("add event with btn [%s],with key[%s]\n",get_text,(char *)set_key); 
                }
            }
            else if (KEY_NUMBER == key_type)
            {
                if (NULL != RS_TRANSLATE((MLG_KEY_TYPE)(pointer_type)set_key))
                { 
                    /*这里必须使用label对象，不能使用obj*/
                    lv_label_set_text(get_child, (const char *)RS_TRANSLATE((MLG_KEY_TYPE)(pointer_type)set_key));
                }
            }

            lv_obj_remove_event_cb(get_child,set_cb);
            lv_obj_add_event_cb(get_child, set_cb , LV_EVENT_REFRESH, set_key);
            lv_obj_add_flag(get_child,LV_OBJ_FLAG_MULTI_LANG); 
        }
    }   
    else if (lv_obj_check_type(obj,&lv_textarea_class))
    { 
        lv_obj_remove_event_cb(obj,set_cb);
        lv_obj_add_event_cb(obj, set_cb , LV_EVENT_REFRESH, set_key);
        lv_obj_add_flag(obj,LV_OBJ_FLAG_MULTI_LANG);
        lv_textarea_set_placeholder_text(obj, (const char *)RS_TRANSLATE((MLG_KEY_TYPE)(pointer_type)set_key));
    }
    else if (lv_obj_check_type(obj,&lv_checkbox_class))
    { 
        lv_obj_remove_event_cb(obj,set_cb);
        lv_obj_add_event_cb(obj, set_cb , LV_EVENT_REFRESH, set_key);
        lv_obj_add_flag(obj,LV_OBJ_FLAG_MULTI_LANG);
        lv_checkbox_set_text(obj, (const char *)RS_TRANSLATE((MLG_KEY_TYPE)(pointer_type)set_key));
    } 
    else
    {
        PRINT_RS_LANG("not support for this obj type\n"); 

        return ;
    }
    #endif
}


