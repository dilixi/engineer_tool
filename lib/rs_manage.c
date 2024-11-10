
 
#include "string.h"
#include "stdio.h"
#include <ctype.h> 
 

#include "utils_lib.h"   

#define SW_PRINT_RS_MANAGER 0

#if SW_PRINT_RS_MANAGER && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "rs_manager"; 
#define PRINT_RS_MANAGER(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_RS_MANAGER(...)
#endif
 
extern const x_header_check_t partition_head_info[]; 
   
static volatile uint32_t WCRCIN = 0xFFFFFFFF;
static volatile uint32_t WCPOLY = 0x04C11DB7; 
 
uint32_t hardware_crc32(uint8_t *source,uint32_t length)
{
    for (int i =0; i < length; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            uint8_t bit = ((source[i] >> (7 - j) & 1) == 1);
            uint8_t c31 = ((WCRCIN >> 31 & 1) == 1);

            WCRCIN <<= 1;

            if (c31 ^ bit)
            {
                WCRCIN ^= WCPOLY;
            }
        }
    }

    return WCRCIN;
}

void hardware_crc32_reset(void)
{
    WCRCIN = 0xFFFFFFFF;
    WCPOLY = 0x04C11DB7; 
}

uint32_t hardware_crc32_all(uint8_t *source, uint32_t length)
{
	uint32_t wCRCin = 0xFFFFFFFF;
	uint32_t wCPoly = 0x04C11DB7;

	for (int i =0; i < length; i++)
	{
	    for (int j = 0; j < 8; j++)
	    {
	        uint8_t bit = ((source[i] >> (7 - j) & 1) == 1);
	        uint8_t c31 = ((wCRCin >> 31 & 1) == 1);

	        wCRCin <<= 1;

	        if (c31 ^ bit)
	        {
	            wCRCin ^= wCPoly;
	        }
	    }
	} 
    
	return wCRCin;
}

#if 0
void rs_notify_reboot(void)
{
    if (t_handle_wifi)
    {
        uint32_t get_val = NOTIFY_CODE_REBOOT;
 
        xTaskNotify((TaskHandle_t )  t_handle_wifi, //任务句柄，指明往哪个任务发送消息，很重要
                            (uint32_t )      get_val,    //发送的消息
                            (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
                            );
    }
}

void rs_notify_updating(uint8_t type)
{
    if (t_handle_wifi)
    {
        uint32_t set_val = NOTIFY_CODE_STOP_SCAN;

        /*notify exit wifi task*/
        xTaskNotify((TaskHandle_t )  t_handle_wifi, //任务句柄，指明往哪个任务发送消息，很重要
                            (uint32_t )      set_val,    //发送的消息
                            (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
                            );

        if (t_handle_mqtt)
        {
            uint32_t set_val = NOTIFY_CODE_EXIT_TASK;

            /*notify exit lvgl task*/
            xTaskNotify((TaskHandle_t )  t_handle_mqtt, //任务句柄，指明往哪个任务发送消息，很重要
                                (uint32_t )      set_val,    //发送的消息
                                (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
                                );
        }  

        if (t_handle_account)
        {
            uint32_t set_val = NOTIFY_CODE_EXIT_TASK;

            /*notify exit lvgl task*/
            xTaskNotify((TaskHandle_t )  t_handle_account, //任务句柄，指明往哪个任务发送消息，很重要
                                (uint32_t )      set_val,    //发送的消息
                                (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
                                );
        }

        esp_now_device_task_exit();   
    }   

    if (1 == type)
    {
        uint32_t get_val = NOTIFY_CODE_EXIT_TASK;
        
        if (t_handle_lvgl)
        {
            uint32_t set_val_lvgl = NOTIFY_CODE_GOTO_UPDATING;

            /*notify exit lvgl task*/
            xTaskNotify((TaskHandle_t )  t_handle_lvgl, //任务句柄，指明往哪个任务发送消息，很重要
                                (uint32_t )      set_val_lvgl,    //发送的消息
                                (eNotifyAction)  eSetValueWithOverwrite //消息发送方式
                                );
        }   
    }
} 

#endif