/* ESPNOW Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#ifndef COM_WITH_PWR_H
#define COM_WITH_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "esp_now_device.h" 
#include "bambu_mqtt.h"


#define CONFIG_PWR_DATA_VERSION                 (0x5AA50001)

#define CONFIG_BIND_RSSI_MIN                    (-40)
#define CONFIG_MIN_VAL_COUNTDOWN_SECOND         60 
#define CONFIG_MIN_VAL_TARGET_CHAMBER_TEMP      25  
#define CONFIG_MIN_VAL_TARGET_NOZZLE_TEMP       31 
#define CONFIG_DEFAULT_VAL_TARGET_NOZZLE_TEMP   50 
#define CONFIG_MIN_VAL_TARGET_BED_TEMP          10  
//#define CONFIG_DELAY_UPDATE_MS                  1500 
#define CONFIG_DELAY_UPDATE_MS                  3000 
#define CONFIG_PANDA_PWR_MAX_CNT                10
#define CONFIG_DELAY_UPDATE_MS_GROUP            3000

#define CONFIG_PWR_GROUP_POP_BUF_SIZE           256 

typedef enum 
{
    PANDA_TOUCH=0xE0,
    PANDA_POWER,
    PANDA_MAX,
}panda_device_t; 
 
#define PANDA_DEVICE_TYPE  PANDA_TOUCH   

typedef struct
{
    uint8_t over_current:1;
    uint8_t over_voltage:1;
    uint8_t over_power_load:1;
    uint8_t less_voltage:1;
    uint8_t leakage:1;
    uint8_t reserved:3; 
} __attribute__((packed)) error_state;  

#define MAX_LEN_SN 16 

typedef enum 
{
    SW_OFF,
    SW_ON,
    SW_MAX,
}sw_value_t;

typedef enum 
{
    COUNT_DOWN_START=0xE0,
    COUNT_DOWN_PAUSE,
    COUNT_DOWN_STOP,
    COUNT_DOWN_MAX,
}countdown_ctl_t;  
 
typedef struct
{ 
    float over_current;
    float over_voltage;
    float over_power_load;
    float under_voltage; 
}__attribute__((packed)) nvs_power_threshold_t;

typedef enum
{
    CNS_INIT,
    CNS_CONNECTING,
    CNS_CONNECTED,
    CNS_CONNECT_FAILED, 
    CNS_CONNECT_MAX, 
}power_connect_state_t; 
  
extern volatile uint32_t delay_tick_config;

extern void panda_pwr_init(void); 
extern void panda_pwr_nvs_init(void);

extern void espnow_update_channel(uint8_t set_channel);   
 
extern void ui_power_set_refresh(void);  
extern void require_pop_bind(const char *);

extern void lv_loop_power(void);

extern void panda_pwr_begin(bambu_mqtt_t *mqtt); 
extern bool panda_pwr_update_state(bambu_mqtt_t *mqtt);
extern bool panda_pwr_set_switch(bambu_mqtt_t *mqtt, uint8_t type, uint8_t sw);
extern bool panda_pwr_set_countdown_value(bambu_mqtt_t *mqtt, uint32_t set_val); 
extern bool panda_pwr_set_temp_sw(bambu_mqtt_t *mqtt, uint8_t type, uint8_t sw);
extern bool panda_pwr_set_temp_value(bambu_mqtt_t *mqtt, uint8_t type, uint8_t value);
extern bool panda_pwr_reset_power_usage(bambu_mqtt_t *mqtt);
extern bool panda_pwr_set_temp_sw_and_value(bambu_mqtt_t *mqtt, uint8_t type, uint8_t sw, uint8_t value);

extern void btn_auto_power_off_clicked(lv_event_t * e);
extern bool panda_pwr_group_set_switch(uint8_t type, uint8_t sw);
extern bool panda_pwr_group_reset_power_usage(void);
extern bool panda_pwr_group_set_temp_sw(bambu_mqtt_t *mqtt,uint8_t type, uint8_t sw);
extern bool panda_pwr_group_set_temp_sw_and_value(uint8_t type, uint8_t sw, uint8_t value);
extern bool panda_pwr_group_set_temp_value(bambu_mqtt_t *mqtt, uint8_t type, uint8_t value);
extern bool panda_pwr_group_set_countdown_value(uint32_t set_val);  
extern void pwr_fmt_countdown(uint32_t time_s, char *out_buf, uint8_t max_buf_size);
extern void pwr_fmt_power_usage(float ele, char *out_buf, uint8_t max_buf_size, bool wrap);

extern int8_t panda_pwr_save_file(nvs_config_pwr_t *pwr_data, uint8_t set_nvs_index);

/*ui*/
extern void btn_power_off_clicked(lv_event_t * e);
extern void btn_usb_ctl_clicked(lv_event_t * e);
extern void btn_reset_pwr_usage_clicked(lv_event_t * e);
extern bool panda_pwr_config_network(bambu_mqtt_t *mqtt);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif//COM_WITH_PWR_H
