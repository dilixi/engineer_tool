#ifndef LV_I18N_H
#define LV_I18N_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

#define MLG_KEY_TYPE uint32_t

/*SAMPLE_START*/

/*SAMPLE_END*/

typedef struct {
    MLG_KEY_TYPE msg_id;
    const char * translation;
} lv_i18n_phrase_t;

typedef struct {
    const char * locale_name;
    lv_i18n_phrase_t * singulars; 
} lv_i18n_lang_t;

// Null-terminated list of languages. First one used as default.
typedef const lv_i18n_lang_t * lv_i18n_language_pack_t;


extern const lv_i18n_language_pack_t lv_i18n_language_pack[];


/**
 * Set the languages for internationalization
 * @param langs pointer to the array of languages. (Last element has to be `NULL`)
 */
int lv_i18n_init(const lv_i18n_language_pack_t * langs);

/**
 * Change the localization (language)
 * @param l_name name of the translation locale to use. E.g. "en_GB"
 */
int lv_i18n_set_locale(const char * l_name);

/**
 * Get the translation from a message ID
 * @param msg_id message ID
 * @return the translation of `msg_id` on the set local
 */
const char * lv_i18n_get_text(MLG_KEY_TYPE msg_id); 


void __lv_i18n_reset(void);


#define _(text) lv_i18n_get_text(text) 


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_LANG_H*/
