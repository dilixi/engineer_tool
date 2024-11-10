
#include "utils_lib.h"  
#include "printer_group.h"
#include "com_with_pwr.h"
#include "stdio.h"
#include "stdlib.h"

#define SW_PRINT_PRINTER_GROUP 0

#if SW_PRINT_PRINTER_GROUP && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "printer_group"; 
#define PRINT_PRINTER_GROUP(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#define PRINT_PRINTER_GROUPW(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#define PRINT_PRINTER_GROUPE(fmt,args...) ESP_LOGE(TAG,fmt,##args)  
#else
#define PRINT_PRINTER_GROUP(...)
#define PRINT_PRINTER_GROUPW(...) 
#define PRINT_PRINTER_GROUPE(...) 
#endif 

static void printer_groups_sort_by_name(void);

static printer_group_t * printer_group[PRINTER_GROUP_MAX_NUM];

printer_group_sync_t group_sync_data = 
{
    0,
    0,
    PRT_CTL_SINGLE,
    printer_group
};
 
bool printer_group_sync_lock(uint32_t timeout_ms)
{ 
    return false;
}

void printer_group_sync_unlock(void)
{ 
    
}

/*申请10个组的内存*/
void printer_group_memory_init(void) 
{
    for (uint8_t i = 0; i < LENGTH_OF_ARRAY(printer_group); i++) 
    {
        group_sync_data.p_groups[i] = (printer_group_t *)malloc(sizeof(printer_group_t));
        memset(group_sync_data.p_groups[i], 0, sizeof(printer_group_t));
    } 
}

static void printer_group_dump(void)
{
    // for (uint8_t i=0; i<group_sync_data.group_cnt; i++)
    // {
    //     printer_group_t *check_group = group_sync_data.p_groups[i];
    //     if (!printer_group_is_valid(check_group))
    //     {
    //         PRINT_PRINTER_GROUPE("delete invalid group idx[%d]\n",i);
    //         printer_group_remove(i);
    //     }

    //     nvs_config_group_t *nvs_group = &check_group->nvs_config; 

    //     PRINT_PRINTER_GROUP("dump group [%s] info:\n",check_group->nvs_config.name);

    //     PRINT_PRINTER_GROUP("printers_cnt:%d,flag=%d\n",(int)nvs_group->printers_cnt,(int)nvs_group->connect_flag);

    //     for (uint8_t j=0; j<nvs_group->printers_cnt; j++)
    //     {
    //         bambu_mqtt_t * mqtt = bambu_get_mqtt(nvs_group->printers_nvs_idx[j]);

    //         PRINT_PRINTER_GROUP("printer_[%d]'s idx=%d, name[%s]\n", i, nvs_group->printers_nvs_idx[i], mqtt->nvs_config.name);
    //     }
    // }
}

/*上电检查哪个组被选中*/
/*如果没有组被选中，则检查哪个打印机的状态是Master*/
void printer_leader_init(void)
{ 
   
}
 
// uint8_t printer_group_get_sorted_mqtt_index(printer_group_t * group, bambu_mqtt_t *check_mqtt)
// {
//     nvs_config_group_t * nvs_group = &group->nvs_config;  
//     for (uint8_t i=0; i<nvs_group->printers_cnt; i++)
//     { 
//         uint8_t nvs_idx_sorted = printer_nvs_idx_sorted[i];
        
//         if (bambu_get_mqtt(nvs_idx_sorted))
//         {
            
//         }
        
//         if (bambu_mqtt_in_print_task(mqtt_check))
//         {  
//             return true;
//         }
//     } 
// }

void printer_group_invalid_data(printer_group_t * group)
{
    nvs_config_group_t *nvs = &group->nvs_config; 

    memset(nvs->name,0,sizeof(nvs->name));
    memset(nvs->printers_nvs_idx,0xff,sizeof(nvs->printers_nvs_idx));
    nvs->connect_flag = CONNECT_FLAG_DISCONNECTED;
    nvs->printers_cnt = 0;
}

bool printer_group_mqtt_is_connected(printer_group_t * group)
{ 
    return false;
}

bool printer_group_mqtt_is_connected_pwr(printer_group_t * group)
{ 
    bool has_connected = false; 


    return has_connected;
}

void printer_group_pwr_add_pop_title(printer_group_t * group, const char *title)
{
}

void printer_group_pwr_add_pop_title_to_printer_name(printer_group_t * group, const char *title)
{
}

bool printer_group_mqtt_check_connected_pwr(printer_group_t * group)
{ 
    return false;
}

bool printer_group_mqtt_check_idle_pwr(printer_group_t * group)
{ 
   return false;
}

bool printer_group_temp_normal_pwr(printer_group_t * group, uint8_t limit_temp)
{ 
    return false;
}

uint8_t printer_group_get_online_pwr(printer_group_t * group)
{  
    return false;
} 

bool printer_group_printer_pwr_temp_too_high(printer_group_t * group, uint8_t limit_temp_chamber, uint8_t limit_temp_nozzle, uint8_t need_check_chamber, uint8_t need_check_nozzle)
{ 
    return false;
}

bool printer_group_printer_temp_too_high_type(printer_group_t * group, uint8_t type, uint8_t limit_temp)
{ 
    return false;
}

/*内部互斥*/
void printer_group_remove(uint8_t index) 
{
    
}

/*调用时需要使用外部互斥*/
nvs_config_group_t * printer_group_get_nvs_config(uint8_t index) 
{
    return &group_sync_data.p_groups[index]->nvs_config;
}

/*调用时需要使用外部互斥*/
printer_group_t * printer_group_get_data(uint8_t index) 
{
    return group_sync_data.p_groups[index];
}

void printer_group_dump_nvs_idx(printer_group_t *group)
{
}

/*调用时需要使用外部互斥*/
bool printer_group_name_is_valid(uint8_t check_idx, const char *name)
{
    return true;
}

bool printer_is_in_group(bambu_mqtt_t *mqtt_check)
{
    return false;
}

/*判断组内有没有该序号*/
bool printer_group_contains_index(printer_group_t *group, uint8_t idx_check)
{
    return false;
}

printer_group_t * printer_group_get_leader(void) 
{  
    return NULL;
}

bool printer_group_is_printing(printer_group_t *group) 
{
    return false;
}

bool printer_group_is_printing_pwr(printer_group_t *group) 
{
    return false;
}

void printer_group_set_as_leader(printer_group_t * group) 
{
    
}

void printer_group_set_as_follow(printer_group_t * group) 
{

}

bambu_mqtt_t * printer_group_get_master_mqtt(printer_group_t * group) 
{ 
    nvs_config_group_t * nvs_group = &group->nvs_config;  
    bambu_mqtt_t *mqtt = bambu_get_mqtt(nvs_group->printers_nvs_idx[0]); 
    if (!mqtt)
    {
        PRINT_PRINTER_GROUP("error get idx[0] is null mqtt\n");
        return NULL;
    }

    // if (CONNECT_FLAG_MASTER != mqtt->nvs_config.connect_flag)
    // {
    //     /*如果第一个不是master设置为Master*/
    //     mqtt->nvs_config.connect_flag = CONNECT_FLAG_MASTER;
    // }

    return mqtt;  
}

void printer_group_update_printers_nvs_index(uint8_t idx_check)
{
    
}

bool printer_group_config(uint32_t index, const char * name, uint8_t printers_cnt, uint8_t *printers_nvs_idx)
{
    return true;
}

bool printer_group_printers_cnt_is_valid(printer_group_t *group)
{
    return false;
} 

uint8_t printer_group_get_index(printer_group_t *group)
{
    return false;
} 
 

bool printer_group_is_valid(printer_group_t *group)
{
    return true;
}

static void printer_groups_sort_by_name(void)
{
}