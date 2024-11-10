#ifndef PRINTER_GROUP_H
#define PRINTER_GROUP_H
 

#define PRINTER_GROUP_MAX_NUM 10
#define PRINTER_GROUP_INVALID_IDX  0xFF
#define MIN_LEN_NAME_GROUP    3
#define MAX_LEN_NAME_GROUP    16

#include "bambu_mqtt.h"

#ifdef __cplusplus
extern "C" {
#endif
 
#define CONFIG_MAX_GROUP_POP_BUF_SIZE 1024
#define LV_STATE_SELECTED             LV_STATE_USER_1
#define LV_STATE_PRINTING             LV_STATE_USER_2
#define LV_FLAG_PRINTING_BG           LV_OBJ_FLAG_USER_3

typedef enum 
{
    PRINTER_IDX=0,
    PRINTER_IDX_GROUP=0x80,
    PRINTER_IDX_INVALID=0xFF
}printer_idx_type;

typedef enum 
{
    GWK_IDLE=0,
    GWK_PRINTING,
}group_work_state;

typedef enum 
{
    PT_PRINTER=0,
    PT_GROUP,
}printer_type;

typedef enum
{
    PRT_CTL_SINGLE=0,
    PRT_CTL_GROUP,
    PRT_CTL_MAX,
} printer_control_t;
  
typedef struct 
{
    uint8_t cnt;
    uint8_t printers_nvs_idx[BAMBU_PRINTER_MAX_NUM];
    char pop_buf[CONFIG_MAX_GROUP_POP_BUF_SIZE];
    char printers_name[CONFIG_MAX_GROUP_POP_BUF_SIZE];
    uint16_t buf_len;
} printer_group_pwr_t;

typedef struct 
{
    char name[MAX_LEN_NAME];  
    uint8_t connect_flag;/*兼容旧的版本，如果是备选中时，值为Master*/
    uint8_t printers_cnt;
    uint8_t printers_nvs_idx[BAMBU_PRINTER_MAX_NUM];
} nvs_config_group_t;

typedef struct {
    //bool is_printing;                                    /*状态有IDLE和Printing*/
    //uint8_t printer_nvs_idx_sorted[BAMBU_PRINTER_MAX_NUM];
    nvs_config_group_t nvs_config;                         /*每个组都有打印机的数量，打印机所有名称和所有SN号用于上电时查询打印数据*/ 
    printer_group_pwr_t pwr_online_list; 
} printer_group_t;                                         /*一个组的数据结构定义*/

typedef struct 
{
    uint8_t group_index;
    uint8_t group_cnt;
    printer_control_t control_type;
    printer_group_t **p_groups;
} printer_group_sync_t;

/*variable */
extern printer_group_sync_t group_sync_data;  

/*functions*/
extern void printer_group_memory_init(void);
extern void printer_leader_init(void);
extern nvs_config_group_t * printer_group_get_nvs_config(uint8_t index);
extern bool printer_group_config(uint32_t index, const char * name, uint8_t printers_cnt, uint8_t *printers_nvs_idx);
extern bool printer_group_name_is_valid(uint8_t check_idx, const char *name);
extern printer_group_t * printer_group_get_data(uint8_t index);
extern bool printer_group_contains_index(printer_group_t *group, uint8_t idx_check); 
extern void printer_group_remove(uint8_t index);
extern printer_group_t * printer_group_get_leader(void);
extern void printer_group_set_as_leader(printer_group_t * group);
extern void printer_group_set_as_follow(printer_group_t * group);
extern bool printer_is_in_group(bambu_mqtt_t *mqtt_check); 
extern bool printer_group_sync_lock(uint32_t timeout_ms);
extern void printer_group_sync_unlock(void);
extern bambu_mqtt_t * printer_group_get_master_mqtt(printer_group_t * group);
extern bool printer_group_is_printing(printer_group_t *group);
extern bool printer_group_printers_cnt_is_valid(printer_group_t *group);
extern bool printer_group_is_valid(printer_group_t *group);
extern uint8_t printer_group_get_index(printer_group_t *group);
extern bool printer_group_mqtt_is_connected(printer_group_t * group);
extern void printer_group_mqtt_status_pop(printer_group_t * group);
extern void printer_group_dump_nvs_idx(printer_group_t * group);
extern void printer_group_update_printers_nvs_index(uint8_t idx_check);
extern bool printer_group_printer_temp_too_high_type(printer_group_t * group, uint8_t type, uint8_t limit_temp);
extern bool printer_group_printer_pwr_temp_too_high(printer_group_t * group, uint8_t limit_temp_chamber, uint8_t limit_temp_nozzle, uint8_t need_check_chamber, uint8_t need_check_nozzle);
extern bool printer_group_mqtt_is_connected_pwr(printer_group_t * group);
extern bool printer_group_is_printing_pwr(printer_group_t *group); 
extern uint8_t printer_group_get_online_pwr(printer_group_t * group);
extern bool printer_group_mqtt_check_connected_pwr(printer_group_t * group);
extern bool printer_group_mqtt_check_idle_pwr(printer_group_t * group);
extern bool printer_group_temp_normal_pwr(printer_group_t * group, uint8_t limit_temp);
extern void printer_group_pwr_add_pop_title(printer_group_t * group, const char *title); 
extern void printer_group_pwr_add_pop_title_to_printer_name(printer_group_t * group, const char *title);

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
