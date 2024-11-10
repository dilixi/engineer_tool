#ifndef APP_H
#define APP_H

#define CONOFIG_USING_COMMAND    2

#ifdef __cplusplus
extern "C" {
#endif
 
#include "utils_lib.h"

#define DISP_HOR_RES 800
#define DISP_VER_RES 480

extern uint32_t get_current_millis();



/*mqtt*/

#define BAMBU_MQTT_PORT 8883
#define BAMBU_MQTT_ID   "Panda_Touch"
#define BAMBU_MQTT_USER "bblp"

#define BAMBU_PRINTER_MAX_NUM         10
#define BAMBU_PRINTER_INVALID_IDX     0xFF
#define SUBTASK_ID_MAX_LEN            64

#define PRINTER_HMS_CODE_LOGIN_FAILED      0XFFFFFFFF00000000
#define PRINTER_HMS_CODE_NEVER_CONNECTED   0XFFFFFFFF00000001 
#define PRINTER_HMS_CODE_SLAVER_ERROR      0XFFFFFFFF00000002
#define PRINTER_HMS_CODE_MASTER_ERROR      0XFFFFFFFF00000003

  
extern void ui_screen_main_init(void) ;



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*UTILS_LIB_H*/
