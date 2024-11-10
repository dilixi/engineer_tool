/*
*---------------------------------------------------------------
*                        Lvgl Img Tool                          
*                                                               
* 注:使用UTF8编码                                                 
* 注:本字体文件由Lvgl Img Tool V0.1 生成                           
* 作者:阿里(qq:617622104)                                         
*---------------------------------------------------------------
*/


#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#if !CONFIG_IMG_SRC_USING_FILE

const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_usb_on_png_data[] = {
};

const lv_img_dsc_t ui_img_usb_on_png = {
#else
lv_img_dsc_t ui_img_usb_on_png = {
#endif        
   .header.always_zero = 0,
   .header.w = 30,
   .header.h = 28, 
   .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
   #if !CONFIG_IMG_SRC_USING_FILE
   .data_size = sizeof(ui_img_usb_on_png_data),
   .data = ui_img_usb_on_png_data
   #else
   .data = NULL
   #endif
};

//end of file