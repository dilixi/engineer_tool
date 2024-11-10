/* ESPNOW Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#ifndef COM_DECODE_H
#define COM_DECODE_H

#ifdef __cplusplus
extern "C" {
#endif
 
#include "rt_slist.h" 
#include "stdint.h" 
 
#define CMD_HEAD 0xAA
#define CMD_TAIL 0x5AA5 

typedef enum
{ 
    ACTION_CMD_ESP_NOW,
    ACTION_CMD_WEB, 
    ACTION_CMD_MAX
}action_cmd_t;

typedef enum
{
    CMD_READ_STATE = 0x01,
    CMD_WRITE_SW_STATE,
    CMD_WRITE_TEMP_LIMIT,  
    CMD_WRITE_COUNTDOWN,
    CMD_RESET_POWER_USAGE,
    CMD_READ_THRESHOLD,
    CMD_WRITE_THRESHOLD, 
    CMD_CONFIG_NETWORK, 
    CMD_MAX
}power_cmd_t;

typedef enum 
{
    COUNTDOWN_STATE_STOP=0x00,
    COUNTDOWN_STATE_STARTED,
    COUNTDOWN_STATE_PAUSE,
    COUNTDOWN_STATE_PAUSE_BY_WEB,
    COUNTDOWN_STATE_MAX,
}countdown_state_t; 

#define MAX_LEN_IP 16
typedef struct
{
    uint8_t error_state; 
    char ip[MAX_LEN_IP]; 
} dev_info_t;  

typedef struct
{ 
    float voltage;
    float current;
    float power; 
    float ele;  
    float fre_hz; 
}power_data_t;

typedef enum
{
    SW_POWER,
    SW_AUTO_POWER_OFF,
    SW_COUNTDOWN, 
    SW_USB, 
    SW_USB_FOLLOW, 
    SW_TYPE_MAX
}pwr_sw_t;

typedef struct
{
    uint16_t type:8;
    uint16_t value:8;
}pwr_sw_config_t;

typedef struct
{ 
    uint8_t power;
    uint8_t auto_power_off;
    uint8_t countdown;
    uint8_t usb;
    uint8_t usb_follow;
}sw_state_t;

typedef enum
{
    LIMIT_CHAMBER, 
    LIMIT_NOZZLE,
    LIMIT_MAX
}limit_t;

typedef struct
{
    uint8_t sw:1;
    uint8_t value:7;
}limit_config_t;

typedef struct 
{
    union
    {
        uint8_t val;
        limit_config_t config; 
    };
}temp_limit_t; 

typedef struct
{  
    temp_limit_t chamber;
    temp_limit_t nozzle; 
    uint32_t target_s;
    uint32_t current_s;
}auto_power_off_t; 

typedef struct
{  
    sw_state_t sw;
    auto_power_off_t auto_power_off;
}pwr_nvs_config_t; 

typedef struct 
{
    dev_info_t device_info; 
    power_data_t power_data;
    pwr_nvs_config_t nvs_config;
}pwr_state_t;

typedef struct 
{
    uint8_t is_online; 
    pwr_state_t state;
}pwr_data_t;

typedef struct
{
    volatile uint8_t data_len;
    volatile uint8_t *data;
}pwr_cmd_parameter_t;

typedef int8_t (*action_cb_t)(uint8_t, uint8_t *,void *user_data);

typedef struct
{
    uint8_t function_code;
    action_cb_t p_action;
    rt_slist_t command_list;
}receive_action_t;

extern int8_t com_decode_handle(uint8_t *data, uint8_t total_len, void *user_data);
extern int8_t com_decode_generate_cmd(uint8_t cmd_code,uint8_t *buffer,void *parameter,uint8_t *get_length);
extern int8_t com_decode_generate_response(uint8_t cmd_code,uint8_t *buffer,void *parameter,uint8_t *get_length);
extern int8_t com_decode_install_callback(receive_action_t *obj,uint8_t type); 
extern int8_t com_decode_handle_web(uint8_t *data, uint8_t total_len, void *user_data);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif//COM_DECODE_H
