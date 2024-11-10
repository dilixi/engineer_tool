#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#if !CONFIG_IMG_SRC_USING_FILE 
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_resume_png_png_data[] = {
};

const lv_img_dsc_t ui_img_resume_png_png = {
#else
lv_img_dsc_t ui_img_resume_png_png = {
#endif   
   .header.always_zero = 0, 
   .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
   #if !CONFIG_IMG_SRC_USING_FILE
   .data_size = sizeof(ui_img_resume_png_png_data),
   .data = ui_img_resume_png_png_data
   #else
   .data = NULL
   #endif
};
