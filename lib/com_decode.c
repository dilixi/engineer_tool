
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>    
 
#include "com_decode.h"

#define SW_PRINT_COM_DECODE 0


#if SW_PRINT_COM_DECODE 
#include "esp_log.h"  
 static const char * TAG = "app_com_decode"; 
#define PRINT_COM_DECODE(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_COM_DECODE(...)
#endif

static rt_slist_t command_list;
volatile uint16_t index_command = 0;

static rt_slist_t command_list_web;
volatile uint16_t index_command_web = 0; 

int8_t com_decode_install_callback(receive_action_t *obj, uint8_t type)
{
    if (NULL == obj)
    {
        return 0;
    }   

    if (type >= ACTION_CMD_MAX)
    {
        return 0;
    }
    
    if (ACTION_CMD_ESP_NOW == type)
    {
        if (0 == index_command)
        {
            rt_slist_init(&command_list);

            index_command = 1;
        }

        rt_slist_append(&command_list, &obj->command_list);
    }
    else if (ACTION_CMD_WEB == type)
    {
        if (0 == index_command_web)
        {
            rt_slist_init(&command_list_web);

            index_command_web = 1;
        }

        rt_slist_append(&command_list_web, &obj->command_list);
    }

    return 0;
}

static const uint8_t table_crc_hi[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

/* Table of CRC values for low-order byte */
static const uint8_t table_crc_lo[] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

static uint16_t crc16(uint8_t *buffer, uint16_t buffer_length)
{
    uint8_t crc_hi = 0xFF; /* high CRC byte initialized */
    uint8_t crc_lo = 0xFF; /* low CRC byte initialized */
    unsigned int i; /* will index into CRC lookup */

    /* pass through message buffer */
    while (buffer_length--) 
    {
        i = crc_hi ^ *buffer++; /* calculate the CRC  */
        crc_hi = crc_lo ^ table_crc_hi[i];
        crc_lo = table_crc_lo[i];
    }

    return (crc_hi << 8 | crc_lo);
}
 
int8_t com_decode_generate_cmd(uint8_t cmd_code,uint8_t *buffer,void *parameter,uint8_t *get_length)
{ 
    uint8_t set_data_length = 1;
    buffer[0] = (uint8_t)(CMD_HEAD);
    buffer[1] = cmd_code;

    uint8_t check_crc_length = 2;
 
    switch (cmd_code)
    {
        case CMD_READ_STATE: 
        case CMD_READ_THRESHOLD:
        case CMD_RESET_POWER_USAGE:
        {
            //命令标识、 数据长度、 数据 内容的等内容的累加和， 低字节在前，高字节在后
            //AA 01 00 XX XX 5A A5
            //AA 02 00 XX XX 5A A5
            //AA 03 00 XX XX 5A A5
            set_data_length = 0;
        }
        break;

        case CMD_WRITE_SW_STATE:  
        case CMD_WRITE_TEMP_LIMIT:
        case CMD_WRITE_COUNTDOWN:
        case CMD_WRITE_THRESHOLD: 
        case CMD_CONFIG_NETWORK: 
        {
            //AA 04 02 80 00 XX XX 5A A5
            //AA 05 02 00 10 XX XX 5A A5
            //PRINT_COM_DECODE("parameter=%x\n", parameter);

            if (!parameter)
            {
                return -1;
            }

            pwr_cmd_parameter_t *get_parameter = (pwr_cmd_parameter_t *)parameter;

            memcpy(&buffer[3],get_parameter->data,get_parameter->data_len);

            set_data_length = get_parameter->data_len;  
        }
        break; 

        default:
        break;

    }

    *get_length = 1+1+1+set_data_length+2+2;

    check_crc_length += set_data_length;

    buffer[2] = set_data_length;

    uint16_t get_crc = crc16(&buffer[1],check_crc_length);

    buffer[*get_length - 4] = (uint8_t)(get_crc>>8);//
    buffer[*get_length - 3] =(uint8_t)(get_crc);

    buffer[*get_length - 2]= (uint8_t)(CMD_TAIL>>8);//0d;
    buffer[*get_length - 1] = (uint8_t)(CMD_TAIL);//0a;

    //PRINT_COM_DECODE("get_crc=%x\n", get_crc);
    return 0;
}

int8_t com_decode_generate_response(uint8_t cmd_code,uint8_t *buffer,void *parameter,uint8_t *get_length)
{
    uint8_t set_data_length = 1;
    buffer[0] = (uint8_t)(CMD_HEAD);
    buffer[1] = cmd_code;

    uint8_t check_crc_length = 2;
 
    switch (cmd_code)
    {
        case CMD_READ_STATE: 
        case CMD_READ_THRESHOLD:
        {
            //命令标识、 数据长度、 数据 内容的等内容的累加和， 低字节在前，高字节在后
   
            if (parameter)
            {
                pwr_cmd_parameter_t *get_parameter = (pwr_cmd_parameter_t *)parameter;

                memcpy(&buffer[3],get_parameter->data,get_parameter->data_len);

                set_data_length = get_parameter->data_len;
            } 
        }
        break; 

        default:
        break;

    }

    *get_length = 1+1+1+set_data_length+2+2;

    check_crc_length += set_data_length;

    buffer[2] = set_data_length;

    uint16_t get_crc = crc16(&buffer[1],check_crc_length);

    buffer[*get_length - 4] = (uint8_t)(get_crc>>8);//
    buffer[*get_length - 3] =(uint8_t)(get_crc);

    buffer[*get_length - 2]= (uint8_t)(CMD_TAIL>>8);//0d;
    buffer[*get_length - 1] = (uint8_t)(CMD_TAIL);//0a;

    //PRINT_COM_DECODE("get_sum=%x\n", get_sum); 
    #if 0 
    extern int32_t  esp_at_port_write_data(uint8_t *data, int32_t len);

    // uint8_t idx = 0;

    // for (idx=0; idx<*get_length; idx++)
    // {
    //     PRINT_COM_DECODE("{%02x}  ", buffer[idx]);
    // }

    //esp_at_port_write_data(buffer,*get_length);

    PRINT_COM_DECODE("response end \r\n");
    #endif

    return 0;

}

int8_t com_decode_handle(uint8_t *data, uint8_t total_len, void *user_data)
{ 
    if (0 == total_len)
    {
        return -1;
    }

    /*check head and tail*/
    if ((data[0] != CMD_HEAD)
        || (data[total_len-2] != (uint8_t)(CMD_TAIL>>8))
        || (data[total_len-1] != (uint8_t)(CMD_TAIL)))
    { 
        PRINT_COM_DECODE("check head and tail %02x,%02x,%02x",data[0],data[total_len-2],data[total_len-1]);

        return -1;
    }

    /*check cmd id*/
    uint8_t get_cmd = data[1];

    if (get_cmd >= CMD_MAX)
    {
        PRINT_COM_DECODE("invalid cmd id:%02x",get_cmd);

        return -1;
    }

    /*check length*/
    if (total_len<7)
    {
        PRINT_COM_DECODE("invalid cmd len:%02x",total_len);
        return -1;
    }

    /*{aa}  {01}  {00}  {00}  {20}  {5a}  {a5}*/
    uint8_t get_data_length = data[2];
    
    /*check crc*/
    uint16_t cal_crc = crc16(&data[1],2+get_data_length); 
    uint16_t get_crc = (data[3+get_data_length]<<8) | (data[3+get_data_length+1]);
 
    if (get_crc != cal_crc)
    {
        PRINT_COM_DECODE("get_crc:%04x != cal_crc:%04x",get_crc,cal_crc); 

        return -1;
    } 

    PRINT_COM_DECODE("get_cmd:%02x",get_cmd);

    rt_slist_t* node;
    receive_action_t* action;

    rt_slist_for_each(node, &command_list)
    {
        action = rt_slist_entry(node, receive_action_t, command_list);

        if (action)
        {
            if (action->function_code == get_cmd)
            { 
                if (action->p_action)
                {
                    return action->p_action(total_len,data,user_data); 
                }
            }
        }
    } 
    
    return -1;
}

int8_t com_decode_handle_web(uint8_t *data, uint8_t total_len, void *user_data)
{ 
    if (0 == total_len)
    {
        return -1;
    }

    /*check head and tail*/
    if ((data[0] != CMD_HEAD)
        || (data[total_len-2] != (uint8_t)(CMD_TAIL>>8))
        || (data[total_len-1] != (uint8_t)(CMD_TAIL)))
    { 
        PRINT_COM_DECODE("web check head and tail %02x,%02x,%02x",data[0],data[total_len-2],data[total_len-1]);

        return -1;
    }

    /*check cmd id*/
    uint8_t get_cmd = data[1];

    if (get_cmd >= CMD_MAX)
    {
        PRINT_COM_DECODE("web invalid cmd id:%02x",get_cmd);

        return -1;
    }

    /*check length*/
    if (total_len<7)
    {
        PRINT_COM_DECODE("web invalid cmd len:%02x",total_len);
        return -1;
    }

    /*{aa}  {01}  {00}  {00}  {20}  {5a}  {a5}*/
    uint8_t get_data_length = data[2];
    
    /*check crc*/
    uint16_t cal_crc = crc16(&data[1],2+get_data_length); 
    uint16_t get_crc = (data[3+get_data_length]<<8) | (data[3+get_data_length+1]);
 
    if (get_crc != cal_crc)
    {
        PRINT_COM_DECODE("web get_crc:%04x != cal_crc:%04x",get_crc,cal_crc); 

        return -1;
    } 

    PRINT_COM_DECODE("web get_cmd:%02x",get_cmd);

    rt_slist_t* node;
    receive_action_t* action;

    rt_slist_for_each(node, &command_list_web)
    {
        action = rt_slist_entry(node, receive_action_t, command_list);

        if (action)
        {
            if (action->function_code == get_cmd)
            { 
                if (action->p_action)
                {
                    return action->p_action(total_len,data,user_data); 
                }
            }
        }
    } 
    
    return -1;
}