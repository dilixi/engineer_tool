/* ESPNOW Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

/*
   This example shows how to use ESPNOW.
   Prepare two device, one for sending ESPNOW data and another for receiving
   ESPNOW data.
*/
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
 
#include "com_with_pwr.h" 
#include "utils_lib.h"  
  
#include "bambu_mqtt.h" 
#include "printer_group.h" 


#define SW_PRINT_COM 0
static const char * TAG = "com_with_pwr"; 
#if SW_PRINT_COM 
#include "esp_log.h"

#define PRINT_COM(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_COM(...)
#endif 

static char *pop_buf_bind = NULL;

static int8_t s_get_pwr_state(uint8_t length, uint8_t *pbuf, void *pwr_state); 

static receive_action_t decode_action_list[] =
{
    {CMD_READ_STATE,s_get_pwr_state},  
};

static int8_t s_get_pwr_state(uint8_t length, uint8_t *pbuf, void *pwr_state)
{  
    //PRINT_COM("s_get_pwr_state length=%d",(int)length); 

    if (sizeof(pwr_state_t) != pbuf[2])
    {
        return -1;
    } 

    memcpy(pwr_state,&pbuf[3],sizeof(pwr_state_t));  

    pwr_state_t *get_pwr_state = (pwr_state_t *)pwr_state;
    if (get_pwr_state)
    {   
        static uint32_t last_tick = 0; 
        #if 0
        PRINT_COM("receive pwr state ivt tick[%ld]:",(xTaskGetTickCount()-last_tick));   
        
        PRINT_COM("ip:[%s]",get_pwr_state->device_info.ip); 
        PRINT_COM("voltage:[%d],current:[%d],power:[%d],ele:[%d],",(int)get_pwr_state->power_data.voltage,(int)get_pwr_state->power_data.current,(int)get_pwr_state->power_data.power,(int)get_pwr_state->power_data.ele);  
        PRINT_COM("sw power:[%02x],auto_power_off:[%02x],countdown:[%02x],usb:[%02x],usb_follow:[%02x]",get_pwr_state->nvs_config.sw.power,get_pwr_state->nvs_config.sw.auto_power_off,get_pwr_state->nvs_config.sw.countdown,get_pwr_state->nvs_config.sw.usb,get_pwr_state->nvs_config.sw.usb_follow);  
        PRINT_COM("auto chamber: sw[%02x] temp:[%02x],nozzle: sw[%02x] temp:[%02x]",get_pwr_state->nvs_config.auto_power_off.chamber.config.sw,
        get_pwr_state->nvs_config.auto_power_off.chamber.config.value,get_pwr_state->nvs_config.auto_power_off.nozzle.config.sw,
        get_pwr_state->nvs_config.auto_power_off.nozzle.config.value);  
        PRINT_COM("auto target_s [%ld] current_s:[%ld]",get_pwr_state->nvs_config.auto_power_off.target_s,get_pwr_state->nvs_config.auto_power_off.current_s);
        #endif
        last_tick=xTaskGetTickCount();
    }

    return 0;
} 

void espnow_update_channel(uint8_t set_channel)
{ 
    //esp_now_device_set_primary_channel(set_channel);  
}

void pwr_fmt_countdown(uint32_t time_s, char *out_buf, uint8_t max_buf_size)
{
    uint16_t hours = time_s / 3600;
    uint16_t minutes = (time_s % 3600) / 60;
    uint16_t seconds = time_s % 60;  

    snprintf(out_buf,max_buf_size,"%02d:%02d:%02d",hours, minutes, seconds);
}

void pwr_fmt_power_usage(float ele, char *out_buf, uint8_t max_buf_size, bool wrap)
{
    if (ele > 1)
    {
        snprintf(out_buf,max_buf_size,"%.1f%s KW/H",ele,wrap?"\n":"");
    }
    else
    {
        snprintf(out_buf,max_buf_size,"%.3f%s KW/H",ele,wrap?"\n":"");
    }
}


static espnow_com_err_t espnow_com_event_handler(void *handler_args, int32_t event_id, void *event_data)
{
   return -1;
}

static volatile bool task_is_start = false;

void panda_pwr_begin(bambu_mqtt_t *mqtt)
{  
    
}

bool panda_pwr_update_state(bambu_mqtt_t *mqtt)
{ 
    return false; 
}

bool panda_pwr_set_switch(bambu_mqtt_t *mqtt, uint8_t type, uint8_t sw)
{ 
    return false;
}

bool panda_pwr_set_countdown_value(bambu_mqtt_t *mqtt, uint32_t set_val)
{ 
    return false;
}

bool panda_pwr_set_temp_value(bambu_mqtt_t *mqtt, uint8_t type, uint8_t value)
{ 
    return false;
}

bool panda_pwr_set_temp_sw_and_value(bambu_mqtt_t *mqtt, uint8_t type, uint8_t sw, uint8_t value)
{ 
    return false;
}

bool panda_pwr_set_temp_sw(bambu_mqtt_t *mqtt, uint8_t type, uint8_t sw)
{ 
    return false;
}

bool panda_pwr_reset_power_usage(bambu_mqtt_t *mqtt)
{ 
    return false;
}

bool panda_pwr_config_network(bambu_mqtt_t *mqtt)
{ 
    return false;
}

static esp_now_mac_group_list_t *s_pwr_mac_list=NULL;

void panda_pwr_group_ctl_init(esp_now_mac_group_list_t *out_pwr_mac_list)
{
 
}

bool panda_pwr_group_set_switch(uint8_t type, uint8_t sw)
{ 
    return false;
} 

bool panda_pwr_group_reset_power_usage(void)
{ 
    return false;
}

bool panda_pwr_group_set_countdown_value(uint32_t set_val)
{ 
    return false;
}

bool panda_pwr_group_set_temp_value(bambu_mqtt_t *mqtt, uint8_t type, uint8_t value)
{ 
    return false;
}

bool panda_pwr_group_set_temp_sw_and_value(uint8_t type, uint8_t sw, uint8_t value)
{ 
    return false;
}

bool panda_pwr_group_set_temp_sw(bambu_mqtt_t *mqtt,uint8_t type, uint8_t sw)
{ 
    return false;
}

static void example_espnow_task(void *pvParameter)
{  

}

void panda_pwr_init(void)
{    

}
 
int8_t panda_pwr_save_file(nvs_config_pwr_t *pwr_data, uint8_t nvs_idx)
{
    return -1;
}

int8_t panda_pwr_get_data(nvs_config_pwr_t *pwr_data, uint8_t nvs_idx)
{
    int8_t res = -1;  

    return res;
}

void panda_pwr_nvs_init(void)
{    
   
} 
