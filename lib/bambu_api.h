/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h> 
//#include "mqtt_client.h"
#ifdef __cplusplus
extern "C" {
#endif 


#ifndef BIT0

#define BIT0   0x00000001  /**< preprocessor alias for 32-bit value with bit 0 set, used to specify this single bit */
#define BIT1   0x00000002  /**< preprocessor alias for 32-bit value with bit 1 set, used to specify this single bit */
#define BIT2   0x00000004  /**< preprocessor alias for 32-bit value with bit 2 set, used to specify this single bit */
#define BIT3   0x00000008  /**< preprocessor alias for 32-bit value with bit 3 set, used to specify this single bit */
#define BIT4   0x00000010  /**< preprocessor alias for 32-bit value with bit 4 set, used to specify this single bit */
#define BIT5   0x00000020  /**< preprocessor alias for 32-bit value with bit 5 set, used to specify this single bit */
#define BIT6   0x00000040  /**< preprocessor alias for 32-bit value with bit 6 set, used to specify this single bit */
#define BIT7   0x00000080  /**< preprocessor alias for 32-bit value with bit 7 set, used to specify this single bit */
#define BIT8   0x00000100  /**< preprocessor alias for 32-bit value with bit 8 set, used to specify this single bit */
#define BIT9   0x00000200  /**< preprocessor alias for 32-bit value with bit 9 set, used to specify this single bit */
#define BIT10  0x00000400  /**< preprocessor alias for 32-bit value with bit 10 set, used to specify this single bit */
#define BIT11  0x00000800  /**< preprocessor alias for 32-bit value with bit 11 set, used to specify this single bit */
#define BIT12  0x00001000  /**< preprocessor alias for 32-bit value with bit 12 set, used to specify this single bit */
#define BIT13  0x00002000  /**< preprocessor alias for 32-bit value with bit 13 set, used to specify this single bit */
#define BIT14  0x00004000  /**< preprocessor alias for 32-bit value with bit 14 set, used to specify this single bit */
#define BIT15  0x00008000  /**< preprocessor alias for 32-bit value with bit 15 set, used to specify this single bit */
#define BIT16  0x00010000  /**< preprocessor alias for 32-bit value with bit 16 set, used to specify this single bit */
#define BIT17  0x00020000  /**< preprocessor alias for 32-bit value with bit 17 set, used to specify this single bit */
#define BIT18  0x00040000  /**< preprocessor alias for 32-bit value with bit 18 set, used to specify this single bit */
#define BIT19  0x00080000  /**< preprocessor alias for 32-bit value with bit 19 set, used to specify this single bit */
#define BIT20  0x00100000  /**< preprocessor alias for 32-bit value with bit 20 set, used to specify this single bit */
#define BIT21  0x00200000  /**< preprocessor alias for 32-bit value with bit 21 set, used to specify this single bit */
#define BIT22  0x00400000  /**< preprocessor alias for 32-bit value with bit 22 set, used to specify this single bit */
#define BIT23  0x00800000  /**< preprocessor alias for 32-bit value with bit 23 set, used to specify this single bit */
#define BIT24  0x01000000  /**< preprocessor alias for 32-bit value with bit 24 set, used to specify this single bit */
#define BIT25  0x02000000  /**< preprocessor alias for 32-bit value with bit 25 set, used to specify this single bit */
#define BIT26  0x04000000  /**< preprocessor alias for 32-bit value with bit 26 set, used to specify this single bit */
#define BIT27  0x08000000  /**< preprocessor alias for 32-bit value with bit 27 set, used to specify this single bit */
#define BIT28  0x10000000  /**< preprocessor alias for 32-bit value with bit 28 set, used to specify this single bit */
#define BIT29  0x20000000  /**< preprocessor alias for 32-bit value with bit 29 set, used to specify this single bit */
#define BIT30  0x40000000  /**< preprocessor alias for 32-bit value with bit 30 set, used to specify this single bit */
#define BIT31  0x80000000  /**< preprocessor alias for 32-bit value with bit 31 set, used to specify this single bit */

#endif  /* BIT0 et al */

typedef void esp_http_client_event_t;
typedef void esp_mqtt_client_handle_t;

#define CONFIG_HISTORY_USING_THUMBNAIL   1
#define BAMBU_ACCOUNT_CNT_MAX            1
#define PARTITION_LABEL_SPIFFS_ACCOUNT   "coredump"
#define ACCOUNT_ERROR_BACKUP_BIT (1 << 6)  // don't poup but title shown
#define ACCOUNT_ERROR_IGNORE_BIT (1 << 7)  // title not shown & don't pop again
#define CONFIG_HTTP_RETRY_CNT_MAX      3
#define CONFIG_HTTP_REQUEST_TIMEOUT_MS (4000UL)  //4000UL
#define MAX_LEN_HTTP_BUFFER            2048
#define PING_TIMEOUT_MS                (5000UL)
#define CONFIG_LENGTH_STR_START_TIME   128


typedef enum 
{
    RES_BAMBU_ACCOUNT_NOT_REG=-100,
    RES_BAMBU_PASSWORD_INVALID, //99
    RES_BAMBU_ACCOUNT_ERROR,//98
    RES_BAMBU_HTTP_MALLOC_ERROR,//97
    RES_BAMBU_HTTP_OPEN_ERROR,  //
    RES_BAMBU_HTTP_WRITE_ERROR, //
    RES_BAMBU_HTTP_CHUNK_LENGTH_ERROR, //
    RES_BAMBU_HTTP_RESPONSE_INVALID,   //93
    RES_BAMBU_ERROR,
    RES_BAMBU_HISTORY_ERR_PARAMETER,
    RES_BAMBU_HISTORY_ERR_INVALID_CNT,//90
    RES_BAMBU_HISTORY_DIFFERENT_TITLE,
    RES_BAMBU_HISTORY_DIFFERENT_DEVICE_ID,
    RES_BAMBU_HISTORY_DIFFERENT_START_TIME,
    RES_BAMBU_ERROR_END=-1,
    RES_BAMBU_OK=0, 
}bambu_res_t;

#define MIN_LEN_ACCOUNT         7
#define MAX_LEN_ACCOUNT         128
#define MIN_LEN_PASSWORD        1
#define MAX_LEN_PASSWORD        128

#define MAX_LEN_USER            32
#define MAX_LEN_CLIENT_ID       24
#define MAX_LEN_TOKEN           2048
#define MAX_LEN_SN              16
#define MAX_LEN_ACCESS_CODE     9   //16字节超过了长度
#define MAX_COUNT_DEV           20
#define MAX_LEN_UID             16
#define MAX_LEN_PRINTER_NAME    16
#define MAX_LEN_IP              16
#define MAX_LEN_MODEL_NAME      64 
#define MAX_LEN_MODEL_ID        20

#define MAX_LEN_PAYLOAD         4096



#define USING_API_1             

typedef enum 
{
    REGION_CHINA=0,
    REGION_OTHER,
    REGION_MAX,
}bambu_api_region_t;
  
typedef enum 
{
    AC_BEING_INIT=1,
    AC_BEING_LOGIN, 
    AC_BEING_DELETE,
    AC_BEING_CONNECT_MQTT,  
    AC_BEING_SYNC_PRINTER,   /*只有在登录的时候会做同步的操作*/ 
    AC_BEING_LOGOUT,
    AC_BEING_MAX
}bambu_account_behave_t;

typedef enum 
{
    AC_STATE_INIT=1,
    AC_STATE_ING, 
    AC_STATE_ERROR_HTTP,
    AC_STATE_ERROR_ACCOUNT,
    AC_STATE_ERROR_PASSWORD, 
    AC_STATE_OK,
    AC_STATE_SYNC_ING,
    AC_STATE_ERROR_SYNC_ZERO_COUNT, 
    AC_STATE_ERROR_SYNC,             /*网络异常、临时被修改密码*/ 
    AC_STATE_SYNC_OK, 
    AC_STATE_MAX
}bambu_account_state_t;

/*账户有邮箱和手机号，需要限制长度*/ 
typedef struct
{
    uint8_t region;
    char account[MAX_LEN_ACCOUNT];  /*有手机号 邮箱*/
    char password[MAX_LEN_PASSWORD]; /*密码*/
}nvs_config_account_t;

typedef struct
{ 
    char name[MAX_LEN_PRINTER_NAME];
    char sn[MAX_LEN_SN];
    char access_code[MAX_LEN_ACCESS_CODE]; 
    char dev_model_name[MAX_LEN_MODEL_NAME];
    char dev_product_name[MAX_LEN_MODEL_NAME];
    char ip[MAX_LEN_IP];
    uint8_t model_num;
    bool is_online;
    uint32_t subscribe_msg_id; 
    volatile void *user_data;  
}bambu_dev_t;

typedef struct { 
    uint32_t cf : 5;          /*Color format: See `lv_img_color_format_t`*/
    uint32_t always_zero : 3; /*It the upper bits of the first byte. Always zero to look like a
                                 non-printable character*/ 
    uint32_t reserved : 2; /*Reserved to be used later*/ 
    uint32_t w : 11; /*Width of the image map*/
    uint32_t h : 11; /*Height of the image map*/
} lv_img_header_copy_t;
  
typedef struct {
    lv_img_header_copy_t header; /**< A header describing the basics of the image*/
    uint32_t data_size;     /**< Size of the image in bytes*/
    const uint8_t * data;   /**< Pointer to the data of the image*/
} lv_img_dsc_copy_t;
  
typedef enum {
    HTTP_METHOD_GET = 0,    /*!< HTTP GET Method */
    HTTP_METHOD_POST,       /*!< HTTP POST Method */
    HTTP_METHOD_PUT,        /*!< HTTP PUT Method */
    HTTP_METHOD_PATCH,      /*!< HTTP PATCH Method */
    HTTP_METHOD_DELETE,     /*!< HTTP DELETE Method */
    HTTP_METHOD_HEAD,       /*!< HTTP HEAD Method */
    HTTP_METHOD_NOTIFY,     /*!< HTTP NOTIFY Method */
    HTTP_METHOD_SUBSCRIBE,  /*!< HTTP SUBSCRIBE Method */
    HTTP_METHOD_UNSUBSCRIBE,/*!< HTTP UNSUBSCRIBE Method */
    HTTP_METHOD_OPTIONS,    /*!< HTTP OPTIONS Method */
    HTTP_METHOD_COPY,       /*!< HTTP COPY Method */
    HTTP_METHOD_MOVE,       /*!< HTTP MOVE Method */
    HTTP_METHOD_LOCK,       /*!< HTTP LOCK Method */
    HTTP_METHOD_UNLOCK,     /*!< HTTP UNLOCK Method */
    HTTP_METHOD_PROPFIND,   /*!< HTTP PROPFIND Method */
    HTTP_METHOD_PROPPATCH,  /*!< HTTP PROPPATCH Method */
    HTTP_METHOD_MKCOL,      /*!< HTTP MKCOL Method */
    HTTP_METHOD_MAX,
} esp_http_client_method_t;


typedef struct
{ 
    char title[256];
    char cover[2048];
    uint32_t cost_time_s;/*所需时间*/
    float weight;/*重量*/
    char start_print_time[MAX_LEN_ACCOUNT];
    char deviceId[MAX_LEN_SN]; 
    uint32_t profileId;
    char modelId[MAX_LEN_MODEL_ID];  
    uint8_t plateIndex;  
    int status;
    char mode[MAX_LEN_MODEL_ID]; //"auto_repeat","cloud_file","mode": "" 
    double nozzleDiameter; //nozzleDiameter
    bool timelapse;  
    bool bedLeveling; 
    bool flowCali;
    bool useAms;  
    
    #if CONFIG_HISTORY_USING_THUMBNAIL
    uint8_t *out_png_data;
    uint32_t out_png_data_length;
    lv_img_dsc_copy_t img_data;
    uint8_t u16_img[8192]; //64*64*2
    #endif
}bambu_print_history_t;  

typedef struct
{
    nvs_config_account_t nvs_config; 
    volatile uint8_t behave; 
    uint8_t printer_cnt;  
    volatile uint8_t mqtt_status;
    volatile uint8_t connect_state;
    bool is_login_ok; 
    uint8_t region_config;
    uint32_t tick_update; 
    //bool network_ok;
    char username_mqtt[MAX_LEN_USER];       
    char password_mqtt[MAX_LEN_TOKEN];    
    char uid_str[MAX_LEN_UID];
    char username[MAX_LEN_USER]; 
    char client_id[MAX_LEN_CLIENT_ID];
    //esp_mqtt_client_handle_t client; 
    bambu_dev_t printers[MAX_COUNT_DEV];   
}bambu_account_info_t;

typedef int8_t (*bambu_fail_cb_t)(int8_t reason);
typedef int8_t (*bambu_success_cb_t)(void *user_data, uint8_t set_nvs_idx);

typedef struct 
{
    uint8_t nvs_idx;
    bambu_account_info_t account;
    bambu_fail_cb_t cb_failed;
    bambu_success_cb_t cb_succeed;
}bambu_api_callback_t;
 
#define BAMBU_API_BASE_URL_CHINA           "https://api.bambulab.cn"
#define BAMBU_API_BASE_URL_OTHER           "https://api.bambulab.com" 

#define BAMBU_API_BASE_URL_CHINA_SIGN_IN    "https://bambulab.cn"
#define BAMBU_API_BASE_URL_OTHER_SIGN_IN    "https://bambulab.com"

#define BAMBU_CLOUD_MQTT_HOSTNAME_CHINA    "cn.mqtt.bambulab.com"
#define BAMBU_CLOUD_MQTT_HOSTNAME_OTHER    "us.mqtt.bambulab.com"

#ifdef USING_API_1
#define BAMBU_API_ENDPOINT_LOGIN           "/v1/user-service/user/login"
#else
#define BAMBU_API_ENDPOINT_LOGIN           "/api/sign-in/form"
#endif

#define BAMBU_API_ENDPOINT_BIND            "/v1/iot-service/api/user/bind"
#define BAMBU_API_ENDPOINT_PROFILE         "/v1/user-service/my/profile"
#define BAMBU_API_ENDPOINT_TASKS           "/v1/user-service/my/tasks"
#define BAMBU_API_ENDPOINT_TASK            "/v1/user-service/my/task" 

extern int8_t bambu_api_login(bambu_account_info_t *_account, uint8_t region, char *account, char *password);
extern int8_t bambu_api_sign_in(bambu_account_info_t *_account, uint8_t region, char *account, char *password);
extern int8_t bambu_api_get_devices(bambu_account_info_t *_account);
extern int8_t bambu_api_get_profile(bambu_account_info_t *_account);
 

extern bool bambu_api_is_valid_phone(const char *phone); 
extern bool bambu_api_is_valid_email(const char *email); 
extern void bambu_api_reset_account(bambu_account_info_t *get_account_info);
extern void bambu_api_fat_init(void);
extern int8_t bambu_api_get_local_token(char *token_out, char *account, char *password, uint8_t nvs_idx);
extern int8_t bambu_api_token_is_valid(char *token, uint8_t region);
extern int8_t bambu_api_get_username(char *token, char *username);
extern int8_t bambu_api_save_account(char *set_account, char *set_password, char *set_token,uint8_t set_nvs_index);
extern void bambu_api_generate_rand(char *out_rand_str);
extern void bambu_api_generate_unique(uint8_t *mac_addr, char *out_str);
extern bool bambu_api_check_online(uint8_t is_china); 

extern int8_t bambu_api_get_print_history(bambu_account_info_t *_account, bambu_print_history_t *check_state, uint8_t **out_png_data, uint32_t *out_png_data_length);
extern void bambu_api_generate_unique_fname(char *out_str);
extern int8_t bambu_api_print_by_history(bambu_account_info_t *_account, bambu_print_history_t *print_history);
extern bool bambu_api_title_is_same(const char *title_a, const char *title_b);




#ifdef __cplusplus
}
#endif
