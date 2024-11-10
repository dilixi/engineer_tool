#ifndef LV_SCREEN_PRINT_H
#define LV_SCREEN_PRINT_H

#include "lvgl.h"
#include "bambu_ftps.h" // file_gcode_t

#define KB_SIZE (1024)
#define MB_SIZE (1024 * KB_SIZE)
#define GB_SIZE (1024 * MB_SIZE)

// lv_screen_print.cpp
void ui_top_set_target_printer(const char * text);
const char * ui_top_get_target_printer(void);
lv_obj_t * ui_panel_create_files_list(lv_obj_t * parent);

const char * file_size_to_string(char * buf, uint32_t max_len, uint32_t size);

// lv_screen_print_ftps.cpp
lv_obj_t * ui_panel_create_ftps(lv_obj_t * parent);
//void lv_loop_files_list_ftps(void);
void ui_files_list_ftps_refresh_require(void);


// lv_screen_print_usb.cpp
typedef enum {
    UI_FTPS_UPLOAD_INIT,
    UI_FTPS_UPLOAD_CREATE,
    UI_FTPS_UPLOAD_CREATE_OK,
    UI_FTPS_UPLOADED_ONE_TASK,
} ui_ftps_t;

ui_ftps_t ui_get_ftps_status(void);
void ui_set_ftps_status(ui_ftps_t status);
lv_obj_t * ui_panel_create_usb(lv_obj_t * parent);
lv_obj_t * ui_panel_create_history(lv_obj_t * parent);

//void lv_loop_files_list_usb(void);
void ui_files_list_usb_refresh_require(uint8_t); 
void ui_panel_create_uploading(void);

// lv_screen_print_sel_printer.cpp
void ui_screen_create_print_task(const char * filename, uint32_t type);

#endif /*LV_SCREEN_PRINT_H*/
