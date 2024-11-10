
#include "bambu_mqtt.h"    
#include "printer_group.h" 
#include "com_with_pwr.h"
#include "utils_lib.h"

#define SW_PRINT_MQTT 0

static const char * TAG = "bambu_mqtt"; 

#if SW_PRINT_MQTT && SW_PRINT_ALL
#include "esp_log.h" 
#define PRINT_MQTT(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_MQTT(...)
#endif

#define mqtt_debug_printf(format, args...)    ((void)0)


//do { __asm__ volatile ("nop"); } while (0)
extern volatile bool g_network_is_ok;

bambu_mqtt_t * bambu_mqtt_master = NULL;
static bambu_mqtt_t * bambu_mqtt[BAMBU_PRINTER_MAX_NUM]; 
static bool require_sort_by_name = true;/*上电后第一次要排序*/
static volatile uint8_t bambu_now_num = 0;

/*variable */
bambu_mqtt_sync_t mqtt_sync_data = 
{
    0
};  
 
bool mqtt_sync_lock(uint32_t timeout_ms)
{ 
    return false;
}

void mqtt_sync_unlock(void)
{ 
   
}
 
bool mqtt_tx_lock(uint32_t timeout_ms)
{ 
    return false;
}

void mqtt_tx_unlock(void)
{  
}

static void mqtt_bambu_data_reprint_set(bambu_data_t *data, const char *path, const char *fname,bool bed_leveling, bool flow_cali, bool timelapse, bool use_ams, bool clear_power_usage, bool auto_power_off);

void bambu_mqtt_memory_init(void) {
    for (uint8_t i = 0; i < ARRAY_SIZE(bambu_mqtt); i++) {
        if (!bambu_mqtt[i])
        {
            bambu_mqtt[i] = (bambu_mqtt_t *)esp_psram_malloc(sizeof(bambu_mqtt_t));
        }

        memset(bambu_mqtt[i], 0, sizeof(bambu_mqtt_t)); 
        memset(bambu_mqtt[i]->current_path,0,sizeof(bambu_mqtt[i]->current_path));  
        memset(bambu_mqtt[i]->ftps_path,0,sizeof(bambu_mqtt[i]->ftps_path)); 
         
        bambu_mqtt[i]->show_type=FILE_SHOW_TYPE_THUMBNAIL;
        bambu_mqtt[i]->preview_home_3mf=NULL;
        bambu_mqtt[i]->preview_home_3mf_size=0;
        //bambu_mqtt[i]->p_3mf_files_from_usb=NULL;
    }

    bambu_mqtt_master = bambu_mqtt[0]; 
    //printer_group_memory_init();
    //bambu_account_memory_init();
}

void bambu_mqtt_add_default_path(const char *default_path)
{
    if (nvs_ftps_work_path_idx>=WORK_DIR_MAX)
    {
        nvs_ftps_work_path_idx=WORK_DIR_CACHE;
    }

    for (uint8_t i = 0; i < ARRAY_SIZE(bambu_mqtt); i++) 
    {   
        strlcpy(bambu_mqtt[i]->ftps_path,default_path,strlen(default_path)+1);    

        //PRINT_MQTT("mqtt[%02x] add default path[%s]\r\n",i, bambu_mqtt[i]->ftps_path);
    }
}

bambu_mqtt_t * bambu_get_mqtt(uint8_t index) {
    return bambu_mqtt[index];
} 

bool bambu_mqtt_is_connected(bambu_mqtt_t * mqtt) {
    if (CONNECT_FLAG_DISCONNECTED == mqtt->nvs_config.connect_flag) return false;
    if (MQTT_CONNECTED != mqtt->status) return false;
    return true;
}

bambu_mqtt_t * bambu_get_mqtt_connected(void) {
    for (uint8_t i = 0; i < ARRAY_SIZE(bambu_mqtt); i++) {
        bambu_mqtt_t * mqtt = bambu_mqtt[i];
        if (!bambu_mqtt_is_connected(mqtt)) continue;
        return mqtt;
    }
    return NULL;
}

bool bambu_printer_index_valid(uint32_t idx_check)
{
    return (idx_check<BAMBU_PRINTER_MAX_NUM);
}

uint8_t bambu_get_mqtt_index(const bambu_mqtt_t * mqtt) 
{
    if (!mqtt)
    {
        return BAMBU_PRINTER_INVALID_IDX;
    }
    
    for (uint8_t i = 0; i < ARRAY_SIZE(bambu_mqtt); i++) 
    {
        if (mqtt != bambu_mqtt[i]) continue;
        return i;
    }
    return BAMBU_PRINTER_INVALID_IDX;
}

void bambu_dump_mqtt_index(void)
{
    mqtt_sync_lock(0); 
    uint8_t get_printer_cnt = mqtt_sync_data.printer_cnt;

    for (uint8_t i = 0; i < get_printer_cnt; i++) 
    {
        bambu_mqtt_t * mqtt = bambu_mqtt[i]; 
    }
    mqtt_sync_unlock(); 
}

nvs_config_t * bambu_get_nvs_config(uint8_t index) {
    return &bambu_mqtt[index]->nvs_config;
}

uint8_t bambu_get_nvs_index(const nvs_config_t * nvs) {
    for (uint8_t i = 0; i < ARRAY_SIZE(bambu_mqtt); i++) {
        if (nvs != &bambu_mqtt[i]->nvs_config) continue;
        return i;
    }
    return BAMBU_PRINTER_INVALID_IDX;
}

bambu_mqtt_t * bambu_get_mqtt_by_sn(const char *find_sn)
{
    mqtt_sync_lock(0); 
    uint8_t get_printer_cnt = mqtt_sync_data.printer_cnt;
    mqtt_sync_unlock(); 

    for (uint8_t i = 0; i < get_printer_cnt; i++) 
    {
        bambu_mqtt_t * mqtt = bambu_get_mqtt(i);

        if (mqtt)
        {   
            nvs_config_t * nvs = &mqtt->nvs_config;
            if (nvs)
            {
                if (0 == strcmp(nvs->sn, find_sn))
                {
                    return mqtt;
                }
            }
        }
    } 

    return NULL;
}

#if 1
/*旧的替换为 bambu_mqtt_in_print_task*/
bool bambu_mqtt_in_print_task(const bambu_mqtt_t * mqtt) {
    if (mqtt->status != MQTT_CONNECTED) return false;
    if (mqtt->bambu_data.gcode_state == GCODE_STATE_PREPARE ||
      mqtt->bambu_data.gcode_state == GCODE_STATE_PAUSE ||
      mqtt->bambu_data.gcode_state == GCODE_STATE_RUNNING) {
        return true;   
    }
    return false;
}

/*加载和卸载使用 bambu_mqtt_is_printing*/
bool bambu_mqtt_is_printing(const bambu_mqtt_t * mqtt) {

    return false;
} 
#else 
#endif 

 
 

#define JSON_DOC_BUF_SIZE (512)
// pull all status for the initialization after startup
bool mqtt_one_client_pushall(bambu_mqtt_t * mqtt) {
   return false;
}
bool mqtt_one_client_pushall_cloud(bambu_mqtt_t * mqtt) 
{
   return false;
}

bool mqtt_one_client_get_access_code(bambu_mqtt_t * mqtt) {
    return false;
}

bool mqtt_one_client_get_version_cloud(bambu_mqtt_t * mqtt) 
{
    return false;
}


bool mqtt_one_client_pushing_cloud(bambu_mqtt_t * mqtt) 
{ 
    return false;
}

bool mqtt_one_client_pushing(bambu_mqtt_t * mqtt) 
{
    return false;
}


bool mqtt_one_client_ledctrl(bambu_mqtt_t * mqtt, const char *ctrl) { 
    return false;
}

bool mqtt_one_client_gcode_line(bambu_mqtt_t * mqtt, const char *gcodes) {
    return false;
}

bool mqtt_one_client_set_spd_lvl(bambu_mqtt_t * mqtt, const char * spd_lvl) {
    return false;
}

bool mqtt_one_client_ams_change_filament(bambu_mqtt_t * mqtt, uint32_t target_action) {
    return false;
}

// "resume" or "done"
bool mqtt_one_client_ams_ctrl(bambu_mqtt_t * mqtt, const char *v) 
{
    return false;
}

bool mqtt_one_client_clean_print_error(bambu_mqtt_t * mqtt) 
{
    return false;
}

bool mqtt_one_client_print_project_file_local(bambu_mqtt_t * mqtt, const char * path, const char * name, bool bed_leveling, bool flow_cali, bool timelapse, bool use_ams, bool clear_power_usage, bool auto_power_off) {
   return false;
}

static void mqtt_bambu_data_reprint_set(bambu_data_t *data, const char *path, const char *fname,bool bed_leveling, bool flow_cali, bool timelapse, bool use_ams,bool clear_power_usage, bool auto_power_off)
{
}

void mqtt_bambu_data_reprint_get(bambu_data_t *data, print_continue_check_t *out_check)
{
}

void mqtt_bambu_data_reprint_reset(bambu_data_t *data)
{
}

typedef struct
{
    char name[MAX_LEN_NAME];
    uint8_t idx_nvs;
}printer_sort_t;

static printer_sort_t s_printers_sorted[BAMBU_PRINTER_MAX_NUM] = {0};

uint8_t printer_sorted_idx_to_nvs_idx(uint8_t idx)
{
    return s_printers_sorted[idx].idx_nvs;
}

uint8_t printer_nvs_idx_to_sorted_idx(uint8_t nvs_index)
{
    mqtt_sync_lock(0); 
    uint8_t get_printer_cnt = mqtt_sync_data.printer_cnt;
    mqtt_sync_unlock(); 

    for (uint8_t i=0; i<get_printer_cnt; i++) 
    {
        if (nvs_index == s_printers_sorted[i].idx_nvs)
        {
            return i;
        }
    }

    return nvs_index;//
}

void mqtt_bubble_sort_by_name(printer_sort_t *printers_sorted, uint8_t len)
{
    for (uint8_t i=0; i<len; i++)
    {
        bambu_mqtt_t * check = bambu_get_mqtt(i);
        sprintf(printers_sorted[i].name,"%s",check->nvs_config.name);
        printers_sorted[i].idx_nvs = i; 
    }

    if (len > 1)
    {
        for (uint8_t i=0; i<len-1; i++)
        {
            for (uint8_t j=0; j<len-1-i; j++)
            { 
                if (strcmp(printers_sorted[j].name,printers_sorted[j+1].name) > 0)
                {
                    printer_sort_t temp = {0};
                    memcpy(&temp,&printers_sorted[j],sizeof(printer_sort_t));
                    memcpy(&printers_sorted[j],&printers_sorted[j+1],sizeof(printer_sort_t));
                    memcpy(&printers_sorted[j+1],&temp,sizeof(printer_sort_t));
                }
            }
        } 
    } 
}
/*在以下情况下需要重新排序*/
/*
新建
删除
改变名称
重新排列后需要保存数据
*/ 
void mqtt_loop_sort_by_name(void)
{
    if (require_sort_by_name)
    {
        require_sort_by_name=false;  
        mqtt_sync_lock(0);   
        //bambu_dump_mqtt_index(); 
        mqtt_bubble_sort_by_name(s_printers_sorted,mqtt_sync_data.printer_cnt); 
        //bambu_dump_mqtt_index(); 
        mqtt_sync_unlock();  
        ui_top_tile_refresh_require();
        //ui_notification_refresh_require();
    }
}

void loop_bambu_mqtt_cloud_status(bambu_mqtt_t * mqtt)
{
    
}

bool mqtt_one_client_print_ctrl(bambu_mqtt_t * mqtt, const char * cmd) 
{
    return false;
}

bool mqtt_one_client_ams_filament_setting(bambu_mqtt_t * mqtt, uint8_t ams_id, uint8_t tray_id, uint32_t color, const idx_data_t * p_idx) {
    return false;
}

typedef enum {
    MQTT_MULTI_STR,
    MQTT_MULTI_UINT32,
    MQTT_MULTI_NONE,
} mqtt_multi_t;

typedef bool (*mqtt_str_cb_t)(bambu_mqtt_t * mqtt, const char * str);
typedef bool (*mqtt_uint32_t_cb_t)(bambu_mqtt_t * mqtt, uint32_t v);
typedef bool (*mqtt_none_cb_t)(bambu_mqtt_t * mqtt);

/*所有打印机控制*/
bool mqtt_multi_client(const void * publish_cb, const void * v, mqtt_multi_t type) {
    return false;
}

bool mqtt_ledctrl(const char *ctrl) {
    return mqtt_multi_client((const void *)mqtt_one_client_ledctrl, (const void *)ctrl, MQTT_MULTI_STR);
}

bool mqtt_gcode_line(const char *gcodes) {
    return mqtt_multi_client((const void *)mqtt_one_client_gcode_line, (const void *)gcodes, MQTT_MULTI_STR);
}

bool mqtt_set_spd_lvl(const char * spd_lvl) {
    return mqtt_multi_client((const void *)mqtt_one_client_set_spd_lvl, (const void *)spd_lvl, MQTT_MULTI_STR);
}

bool mqtt_ams_change_filament(uint32_t target, bool unload) {
    uint32_t target_action = (unload << 16) | target;
    return mqtt_multi_client((const void *)mqtt_one_client_ams_change_filament, (const void *)target_action, MQTT_MULTI_UINT32);
}

bool mqtt_ams_ctrl(const char * cmd) {
    return mqtt_multi_client((const void *)mqtt_one_client_ams_ctrl, (const void *)cmd, MQTT_MULTI_STR);
}

bool mqtt_clean_print_error(void) {
    return mqtt_multi_client((const void *)mqtt_one_client_clean_print_error, NULL, MQTT_MULTI_NONE);
}

const char * parse_id [] = {
    "nozzle_temper",
    "nozzle_target_temper",
    "bed_temper",
    "bed_target_temper",
    "chamber_temper",
    "spd_mag",
    "spd_lvl",
    "ams_status",
    "hw_switch_state",
    "print_error",
    "mc_percent",
    "mc_remaining_time",
    "layer_num",
    "total_layer_num",
    "stg_cur",
};

const char * fan_id[] = {
    "cooling_fan_speed",
    "big_fan1_speed",
    "big_fan2_speed",
};
const char * ams_bits_id[] = {
    "ams_exist_bits",
    "tray_exist_bits",
    "tray_is_bbl_bits",
    "tray_read_done_bits",
    "tray_reading_bits",
};

gcode_state_t bambu_mqtt_gcode_state_update(bambu_data_t * target, gcode_state_t new_state)
{
    if (GCODE_STATE_FINISH == new_state)
    {
        if (GCODE_STATE_FINISH_IDLE == target->gcode_state_idle)
        {  
            return GCODE_STATE_IDLE; 
        }
        else
        {
            target->gcode_state_idle=GCODE_STATE_IDLE; 
        } 
    } 
    else if (GCODE_STATE_FAILED == new_state)
    {
        if (GCODE_STATE_CANCEL_IDLE == target->gcode_state_idle)
        {  
            return GCODE_STATE_IDLE; 
        }
        else
        {
            target->gcode_state_idle=GCODE_STATE_IDLE; 
        } 
    }
    else
    {
        target->gcode_state_idle=GCODE_STATE_IDLE; 
    }

    return new_state;
}

// int32_t fan_percentage(int speed)
// { 
//     if (speed == 0) {
//         return 0;
//     }
 
//     float percentage = ((float)speed / 15.0) * 100.0;
 
//     return (int)((ceil(percentage+3)));
// }

uint8_t speed_to_percentage(uint32_t speed)
{
    uint8_t percent = (((speed*100*1000/255) + 500)/1000);

    if ((percent>0) && (percent<10))
    {
        return 10;
    }

    if (percent % 10 != 0) 
    {
        percent = ((percent / 10) + 1) * 10;
    } 

    return percent;
}
 
void bambu_mqtt_rcv_decode(bambu_data_t * target, char * topic, int topic_len, char * data, int data_len) { 

}



bool bambu_mqtt_begin(bambu_mqtt_t * mqtt, const char *broker_ip, const char *client_password, const char *bambu_sn, uint16_t priority) {
   
    return true;
}

void bambu_mqtt_destroy(bambu_mqtt_t * mqtt) {
    
}

void bambu_mqtt_cloud_destroy(bambu_mqtt_t * mqtt) 
{
   
}

void bambu_mqtt_cloud_connect(bambu_mqtt_t * mqtt, void * set_client, bool is_online) 
{
    
}

//
void bambu_mqtt_remove(uint8_t index) {
    bambu_mqtt[index]->being = MQTT_BEING_DELETED;
}

void bambu_mqtt_printer_remove(uint8_t index) {

   
}

void mqtt_publish_loop(bambu_mqtt_t * mqtt) 
{
    
}
  

static bambu_mqtt_t * mqtt_leader_last = NULL;
void mqtt_task(void * parameter) 
{ 
    while (1) 
    {

    } 
}

bool bambu_printer_config_set(
    uint32_t i,
    const char * ip, const char * access_code, const char * sn,
    const char * name, const char * model, bambu_model_t model_num,
    const char * nozzle_dia, uint8_t account_type,
    const char * filament_material, const char * filament_color) {

    return true;
}
     
nvs_config_t * bambu_printer_find_mainly_ctrl(void) {

    return NULL;
}

bool bambu_printer_connect_status_set(nvs_config_t * nvs, connect_flag_t status, bool nvs_changed) {
   
    return true;
}
