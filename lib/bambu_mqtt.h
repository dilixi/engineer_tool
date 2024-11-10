#ifndef BAMBU_MQTT_H
#define BAMBU_MQTT_H


#include "stdint.h"
#include "com_decode.h"
#include "bambu_api.h"

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
#define PRINTER_STAGE_HEATING              2
#define PRINTER_STAGE_CLEAN_NOZZLE         14
#define PRINTER_STAGE_BED_LEVELING         1

typedef enum {
    GCODE_STATE_IDLE,
    GCODE_STATE_PREPARE,
    GCODE_STATE_PAUSE,
    GCODE_STATE_RUNNING,
    GCODE_STATE_FINISH,
    GCODE_STATE_FAILED,

    GCODE_STATE_FOR_USER,
    GCODE_STATE_CANCEL_IDLE,
    GCODE_STATE_FINISH_IDLE,
    GCODE_STATE_MAX,
} gcode_state_t;
   
#define HMS_MAX_NUMBER 10

#define AMS_MAX_NUMBER 4
#define TRAY_PER_AMS   4

typedef enum {
    PRINT_FROM_NONE,
    PRINT_FROM_HISTORY, 
    PRINT_FROM_TOUCH,
    PRINT_FROM_CACHE,  
} print_from_t;

typedef enum {
    HOME_PANDA_DEFAULT=0x11,
    HOME_PANDA_HISTORY,
    HOME_PANDA_USB, 
    HOME_PANDA_MAX,
} home_panda_t; 

typedef enum { 
    FLS_SPOOL_HOLDER,
    FLS_AMS, 
    FLS_MAX,
}filament_selected_t; 

typedef struct
{
    uint8_t type;
    uint8_t ams_id;
    uint8_t tray_id;    
}filament_tray_t; 

typedef struct {
    uint64_t tag_uid;
    char tray_info_idx[6];
    uint32_t tray_color;
    uint32_t nozzle_temp_max;
    uint32_t nozzle_temp_min;
    char tray_type[16]; 

} tray_t;

typedef struct {
    uint32_t ams_exist_bits;
    uint32_t tray_exist_bits;
    uint32_t tray_is_bbl_bits;
    uint32_t tray_read_done_bits;
    uint32_t tray_reading_bits;

    // uint8_t tray_tar;
    uint8_t tray_now;
    uint8_t humidity_idx[AMS_MAX_NUMBER];
    // uint8_t tray_pre;
    tray_t ams_tray[AMS_MAX_NUMBER][TRAY_PER_AMS];
} ams_t;

typedef struct {
    volatile uint8_t print_type;/*1:print by touch 2:print by cache*/
    char gcode_file[256];
    char path[256];
    bool bed_leveling;
    bool timelapse;
    bool flow_cali;
    bool use_ams; 
    bool clear_power_usage;
    bool auto_power_off; 
} print_continue_check_t;

typedef struct {
    int32_t nozzle_temper;
    int32_t nozzle_target_temper;
    int32_t bed_temper;
    int32_t bed_target_temper;
    int32_t chamber_temper;
    int32_t spd_mag;
    int32_t spd_lvl;
    int32_t ams_status;
    int32_t hw_switch_state;
    int32_t print_error;
    int32_t mc_percent;
    int32_t mc_remaining_time;
    int32_t layer_num;
    int32_t total_layer_num;
    int32_t stg_cur;

    ams_t ams;
    tray_t vt_tray;
    uint8_t vt_tray_id;

    bool sdcard;

    uint64_t hms[HMS_MAX_NUMBER];
    uint8_t hms_num;
    bool hms_updated;

    bool print_error_updated;
    int32_t chamber_humidity;
    print_continue_check_t reprint_check;
    gcode_state_t gcode_state;  
    gcode_state_t gcode_state_idle;  
    volatile gcode_state_t cloud_online_check;  
    char gcode_file[256]; // subtask_name
    char profile_id[32];
    char ftps_path[256]; // printer ftps path
    bool file_updated;
    volatile uint8_t print_type; 
    volatile bool can_reprint; 
    // char * gcode_state 

    bool chamber_light;
    bool chamber_light_last;
    uint8_t fan_speed[3]; // part, aux, chamber
    char start_print_time[128];
    //char gcode_start_time[128];
    volatile uint8_t update_3mf_preview;
} bambu_data_t;

typedef enum {
    BAMBU_MODEL_P1P,
    BAMBU_MODEL_P1S,
    BAMBU_MODEL_X1,
    BAMBU_MODEL_X1C = BAMBU_MODEL_X1,
    BAMBU_MODEL_X1E = BAMBU_MODEL_X1,
    BAMBU_MODEL_A1MINI,
    BAMBU_MODEL_A1,
    BAMBU_MODEL_UNKNOW,
} bambu_model_t;

// The value of the enum must correspond to "const char *mqtt_connect_status_id[]"
typedef enum {
    CONNECT_FLAG_DISCONNECTED = 0,
    CONNECT_FLAG_SYNC,
    CONNECT_FLAG_SLAVE,
    CONNECT_FLAG_MASTER, 
    CONNECT_FLAG_MAX,
} connect_flag_t;

#define MAX_LEN_IP 16
#define MAX_LEN_ACCESS_CODE 9
#define MAX_LEN_SN 16
#define MAX_LEN_NAME 16
#define MAX_LEN_MODEL 16
#define MAX_LEN_MISC 7

typedef struct {
    char ip[MAX_LEN_IP];
    char access_code[MAX_LEN_ACCESS_CODE];
    char sn[MAX_LEN_SN];
    char name[MAX_LEN_NAME];                /*名称是在UDP时扫描出来的，这里是指自定义名称，在mqtt连接时不需要这个参数*/
    char model[MAX_LEN_MODEL];  
    char nozzle_dia[MAX_LEN_MISC]; 
    uint8_t account_type;//0 is local 
    uint8_t pwr_mac_addr[6];// 
    char filament_material[MAX_LEN_MISC];
    char filament_color[MAX_LEN_MISC];
    bambu_model_t model_num;
    connect_flag_t connect_flag;
} nvs_config_t;

typedef struct 
{ 
    char ip[MAX_LEN_IP]; 
    uint32_t version;
    uint32_t crc32;
} nvs_config_pwr_t;

#define MQTT_ERROR_BACKUP_BIT (1 << 6)  // don't poup but title shown
#define MQTT_ERROR_IGNORE_BIT (1 << 7)  // title not shown & don't pop again

typedef enum {
    MQTT_INIT = 0,
    MQTT_CONNECTING,
    MQTT_CONNECTED,
    MQTT_ERROR_PORT,
    MQTT_ERROR_REFUSED,
    MQTT_ERROR_OTHER,
    MQTT_ERROR_TIMEOUT,
    MQTT_ERROR_NOT_BIND_ACCOUNT,
    MQTT_ERROR_NULL_ACCOUNT, 
    //MQTT_ERROR_ACCOUNT_NOT_LOGIN,  
    MQTT_ERROR_PORT_BACKUP = MQTT_ERROR_BACKUP_BIT | MQTT_ERROR_PORT,
    MQTT_ERROR_REFUSED_BACKUP = MQTT_ERROR_BACKUP_BIT | MQTT_ERROR_REFUSED,
    MQTT_ERROR_OTHER_BACKUP = MQTT_ERROR_BACKUP_BIT | MQTT_ERROR_OTHER,
} mqtt_status_t;

#define QUEUE_NUM 5
#define QUEUE_SIZE 512
typedef struct {
    char queue[QUEUE_NUM][QUEUE_SIZE];
    uint8_t index_r;  // Ring buffer read position
    uint8_t index_w;  // Ring buffer write position
    uint8_t count;    // Count of commands in the queue
} publish_queue_t;

typedef enum {
    MQTT_ACCOUNT_NOT_CHANGE = 0,
    MQTT_ACCOUNT_CHANGE_TO_CLOUD,
    MQTT_ACCOUNT_CHANGE_TO_LOCAL,
} mqtt_account_change_t;

typedef enum {
    MQTT_BEING_INIT = 0,
    MQTT_BEING_DELETED,
    MQTT_BEING_RECONNECT,
    MQTT_BEING_RECONNECT_TO_CLOUD,
    MQTT_BEING_RECONNECT_TO_LOCAL,
    MQTT_BEING_DISCONNECT,
    MQTT_BEING_CONNECT,
} mqtt_being_t;

typedef struct {
    // esp_mqtt_client_handle_t client;
    // esp_mqtt_client_handle_t client_cloud;
    // esp_now_device_handle_t espnow_device;
    
    mqtt_status_t status; 
    // const char * _broker_ip;
    // const char * _client_password;
    char topic_report[128];
    char topic_request[128];
    uint32_t sequence_id;
    publish_queue_t publish_queue;
    bambu_data_t bambu_data;
    pwr_data_t pwr_data;
    volatile mqtt_being_t being; 
    nvs_config_t nvs_config;
    nvs_config_pwr_t nvs_config_pwr;
    bool never_connected;
    uint32_t tick_pushall;
    uint32_t tick_heartbeat;
    uint32_t tick_pushall_pwr;
    uint32_t tick_failed_delay;
    uint32_t tick_get_history_retry_delay;

    int8_t ftp_res;
    char user_id[32];
    char client_id[32];
    uint8_t show_type;
    char ftps_path[256];
    char current_path[256]; 
    uint8_t preview_from_ftp_retry_cnt;
    uint32_t preview_home_3mf_size;
    uint8_t *preview_home_3mf;  
    uint8_t *p_3mf_files_from_cache;
} bambu_mqtt_t;



/*variable */
  
#include "lv_screen_ctrl.h"
//bool mqtt_one_client_ams_filament_setting(bambu_mqtt_t * mqtt, uint8_t ams_id, uint8_t tray_id, uint32_t color, const idx_data_t * p_idx);


void bambu_mqtt_remove(uint8_t index); 
extern bambu_mqtt_t * bambu_mqtt_master;
#define BAMBU_DATA_MASTER (bambu_mqtt_master->bambu_data)

  
extern bool bambu_account_index_valid(uint32_t idx_check);
void mqtt_loop_sort_by_name(void);
void mqtt_bubble_sort_by(uint8_t *buffer, uint8_t len);

bool bambu_printer_config_set(
    uint32_t i,
    const char * ip, const char * access_code, const char * sn,
    const char * name, const char * model, bambu_model_t model_num,
    const char * nozzle_dia, uint8_t account_type,
    const char * filament_material, const char * filament_color);
bool bambu_printer_connect_status_set(nvs_config_t * cfg, connect_flag_t status, bool nvs_changed);
void bambu_dump_mqtt_index(void); 
 
extern bambu_mqtt_t * bambu_get_mqtt_by_sn(const char *find_sn);
//extern void bambu_mqtt_cloud_connect(bambu_mqtt_t * mqtt, esp_mqtt_client_handle_t set_client, bool is_online);

void bambu_mqtt_rcv_decode(bambu_data_t * target, char * topic, int topic_len, char * data, int data_len);
bool mqtt_one_client_pushall(bambu_mqtt_t * mqtt); 
bool mqtt_one_client_pushing(bambu_mqtt_t * mqtt);
bool mqtt_one_client_pushall_cloud(bambu_mqtt_t * mqtt);




#ifdef __cplusplus
extern "C" {
#endif
extern bambu_mqtt_t * bambu_get_mqtt(uint8_t index);
extern void test_ftps_img(bambu_mqtt_t *mqtt);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif
