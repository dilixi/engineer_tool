/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h> 

#ifdef __cplusplus
extern "C" {
#endif

#include "rt_slist.h"  
#include "com_decode.h"

#define CONFIG_USING_PSRAM_MALLOC           1
#define CONFIG_COM_ESPNOW_PMK               "pmk_panda_power"
#define CONFIG_COM_ESPNOW_LMK               "lmk_panda_power" 

#define CONFIG_USING_HTTP                   1
#define CONFIG_HTTP_RETRY_CNT_MAX           3

#define SEND_CB_OK                        BIT0
#define SEND_CB_FAIL                      BIT1

#define NVS_BIND_MAGIC_CODE               0x5AA5
#define ESP_NOW_NOTIFY_CODE_EXIT_TASK     0xFFEE

#define CONFIG_TIMEOUT_MS_SEND            (150)
#define CONFIG_DEFAULT_TIMEOUT_MS_BIND    (15*1000)
#define CONFIG_DEFAULT_QUEUE_SIZE         (10)
#define CONFIG_DEFAULT_QUEUE_MAX_DELAY    (512)

#define CONFIG_DEFAULT_HEARTBEAT_TIMEOUT  (3000) 
#define CONFIG_DEFAULT_BIND_TIMEOUT       (15000) 
#define CONFIG_MS_SEND_FAILED_DELAY       (5000UL)

#define CONFIG_ESPNOW_COM_TASK_PRIORITY   4
#define CONFIG_ESPNOW_RX_BUFFER_SIZE      230//espnow_data_t+payload<250字节

#define ESPNOW_CHANNEL_ALL                  0x0f  /**< All supported channels */
#define CONFIG_ESP_NOW_MAX_ENCRYPT_PEER_NUM 10

#define MAX_LEN_SSID 33
#define MAX_LEN_PWD 65
#define MAX_LEN_BSSID 6
#define LEN_MAC_ADDRESS MAX_LEN_BSSID
#define MAX_LEN_SN 16
#define MAX_LEN_IP 16
#define ESP_NOW_ETH_ALEN MAX_LEN_BSSID
#define wifi_auth_mode_t uint8_t

typedef void esp_now_device_queue_t;

typedef uint8_t espnow_addr_t[ESP_NOW_ETH_ALEN];  

typedef enum
{
    ESP_COM_DEV_ROLE_CONTROLLER,
    ESP_COM_DEV_ROLE_RESPONDER,
    ESP_COM_DEV_ROLE_MAX,
}esp_now_device_role;

typedef enum {     
    ESP_NOW_EVENT_BIND_REQUIRE,
    ESP_NOW_EVENT_HEARTBEAT_CB, 
    ESP_NOW_EVENT_WIFI_FORWARD,
    ESP_NOW_EVENT_CONTROL_UNBIND,
    ESP_NOW_EVENT_CONTROL_BIND,
    ESP_NOW_EVENT_WIFI_PROV, 
    ESP_NOW_EVENT_DATA_RECV, 
    ESP_NOW_EVENT_UPDATE_LEADER,
    ESP_NOW_EVENT_ACCEPT_BINDING,
    ESP_NOW_EVENT_REJECT_BINDING,
    ESP_NOW_EVENT_REMOVE_BIND,
    ESP_NOW_EVENT_SYNC_WIFI,
    ESP_NOW_EVENT_GROUP_CONTROL,
    ESP_NOW_EVENT_GROUP_ACK,
    ESP_NOW_EVENT_INVALID_ID, 
} esp_now_event_id_t;

typedef struct {
    uint8_t mac_addr[ESP_NOW_ETH_ALEN]; 
    int channel; 
    int data_len;
    uint8_t *data;
} com_event_cb_t;

typedef union {  
    com_event_cb_t event_cb;
} com_event_info_t;
 
typedef struct {
    esp_now_event_id_t id;
    com_event_info_t info;
} com_rx_queue_t;
 
typedef enum 
{
    ESP_NOW_DEVICE_INIT=0,
    ESP_NOW_DEVICE_SEARCH,
    ESP_NOW_DEVICE_ASK_WAITING,
    ESP_NOW_DEVICE_ACK_REJECT, 
    ESP_NOW_DEVICE_BINDING,
    ESP_NOW_DEVICE_BIND_OK, 
    ESP_NOW_DEVICE_SEARCH_TIMEOUT, 
    ESP_NOW_DEVICE_OTA,
    ESP_NOW_DEVICE_MAX,
}esp_com_device_state_t; 

typedef enum {
    COM_DATA_TYPE_ACK,            /**< For reliable data transmission */
    COM_DATA_TYPE_FORWARD,        /**< Set to forward packets */
    COM_DATA_TYPE_GROUP,          /**< Send a packet that sets the group type */
    COM_DATA_TYPE_PROV,           /**< Network configuration packet */
    COM_DATA_TYPE_CONTROL_BIND,   /**< Binding or unbinding packet */
    COM_DATA_TYPE_CONTROL_DATA,   /**< Control data packet */
    COM_DATA_TYPE_OTA_STATUS,     /**< Status packet for rapid upgrade of batch Device */
    COM_DATA_TYPE_OTA_DATA,       /**< Data packet for rapid upgrade of batch Device */
    COM_DATA_TYPE_HEARTBEAT,      /**< Equipment debugging log packet */
    COM_DATA_TYPE_DEBUG_COMMAND,  /**< Equipment debugging command packet */
    COM_DATA_TYPE_DATA,           /**< User-defined use */
    COM_DATA_TYPE_SECURITY_STATUS,/**< Security status packet */
    COM_DATA_TYPE_SECURITY,       /**< Security handshake packet */
    COM_DATA_TYPE_SECURITY_DATA,  /**< Security packet */
    COM_DATA_TYPE_RESERVED,       /**< Reserved for other function */
    COM_DATA_TYPE_MAX,
} com_data_type_t;

typedef enum
{
    ESPNOW_COM_EVENT_ERROR = 0, 
    ESPNOW_COM_EVENT_CONNECTED,
    ESPNOW_COM_EVENT_DISCONNECTED,  
    ESPNOW_COM_EVENT_ASK_BIND,  
    ESPNOW_COM_EVENT_GET_WIFI_DATA,
    ESPNOW_COM_EVENT_CHECK_WIFI_CONNECTED,
    ESPNOW_COM_EVENT_BIND_FINISH,
    ESPNOW_COM_EVENT_REMOVE_BIND, 
    ESPNOW_COM_EVENT_RESET_WIFI,
    ESPNOW_COM_EVENT_STATE_CHANGED,
    ESPNOW_COM_EVENT_BIND_SAME_MAC,
    ESPNOW_COM_EVENT_BIND_MAX_LIMIT,
    ESPNOW_COM_EVENT_DATA, 
    ESPNOW_COM_EVENT_DATA_HTTP, 
} esp_device_event_id_t;

typedef struct 
{
    uint8_t type;
    uint8_t state; 
    uint8_t dev_type;
    int8_t forward_rssi;
    uint8_t channel;
    uint8_t dest_addr[6]; 
    uint8_t size;  
    uint8_t payload[0];
} __attribute__((packed)) espnow_data_t;

typedef struct {
    char ssid[MAX_LEN_SSID];
    char pswd[MAX_LEN_PWD]; 
    wifi_auth_mode_t sta_auth; 
    uint8_t channel;
} __attribute__((packed)) wifi_config_com_t; 
 
typedef struct 
{
    uint8_t mac_addr[LEN_MAC_ADDRESS];
    wifi_config_com_t wifi_data;
} nvs_esp_now_wifi_config_t;

typedef struct 
{
    uint8_t data[CONFIG_ESPNOW_RX_BUFFER_SIZE];
    uint8_t length;
} com_tx_queue_t; 

#define MAX_NAC_ADDR_COUNT 10
typedef struct
{
    uint8_t cnt;
    espnow_addr_t addr[MAX_NAC_ADDR_COUNT]; 
    char ip[MAX_LEN_IP];
}esp_now_mac_list; 

typedef struct
{
    uint8_t cnt;
    espnow_addr_t addr[MAX_NAC_ADDR_COUNT]; 
    char ip[MAX_NAC_ADDR_COUNT][MAX_LEN_IP];
}esp_now_mac_group_list_t; 

typedef int8_t espnow_com_err_t;      

typedef espnow_com_err_t (*esp_now_device_event_handler_t)(void *handler_args,int32_t event_id, void *event_data);  

typedef bool (*espnow_wifi_connected_check_t)(void);  

/*单个实例的配置*/
typedef struct 
{  
    char *printer_sn;   
    char *ip;  
    uint8_t *bind_mac_addr;           /*在绑定的mac地址*/
    uint32_t timeout_ms_bind;         /*进行绑定时的超时时间*/
    uint32_t timeout_ms_heartbeat;    /*已绑定好的心跳检测*/
    uint16_t rx_queue_wait_ms;        /*接收队列时等待的ms*/
    uint16_t rx_queue_size;           /*队列长度*/
    uint16_t tx_queue_wait_ms;        /*发送队列时等待的ms*/
    uint16_t tx_queue_size;           /*队列长度*/ 
    bool enable_following_wifi;
} espnow_device_config_t;

typedef struct esp_now_device *esp_now_device_handle_t;
 
typedef struct espnow_com_event_t 
{
    esp_device_event_id_t event_id;
    esp_now_device_handle_t espnow_dev;   
    uint8_t *data;                   /*!< Data associated with this event */
    int data_len;                    /*!< Length of the data for this event */
    int total_data_len; 
    int current_data_offset;   
} espnow_com_event_t;

typedef espnow_com_event_t *espnow_com_event_handle_t; 

typedef struct 
{  
    uint8_t role;
    uint8_t dev_type;
    uint8_t dev_type_target; 
    int8_t bind_rssi_min;   
    uint32_t queue_wait_maxdelay;
    //wifi_country_t self_country; 
    volatile uint8_t channel_primary;
    //EventGroupHandle_t event_group;
    esp_now_device_queue_t *rx_queue;
    esp_now_device_queue_t *tx_queue;
    //SemaphoreHandle_t send_lock;  
    //SemaphoreHandle_t  instance_lock;
    esp_now_device_event_handler_t device_event_handle; 
    espnow_wifi_connected_check_t wifi_is_connected;
    uint32_t tick_config_wifi;
    bool is_following_wifi; 
    //TaskHandle_t task_handle;
    volatile esp_now_device_handle_t leader;
    uint8_t buf[CONFIG_ESPNOW_RX_BUFFER_SIZE];
} espnow_com_ctx_t; 

typedef void (*esp_now_com_task_t)(void *pv);

extern esp_now_device_handle_t esp_now_device_init(espnow_device_config_t *config);
extern espnow_com_err_t esp_now_device_destroy(esp_now_device_handle_t espnow_dev);  
extern void esp_now_device_update_leader(esp_now_device_handle_t espnow_dev);
extern void esp_now_device_accept_binding(esp_now_device_handle_t espnow_dev);
extern void esp_now_device_reject_binding(esp_now_device_handle_t espnow_dev);
extern void esp_now_device_remove_bind(esp_now_device_handle_t espnow_dev);
extern bool esp_now_device_write_data(esp_now_device_handle_t espnow_dev, uint8_t *data, uint8_t len);
extern bool esp_now_device_check_state(esp_now_device_handle_t espnow_dev, uint8_t *data, uint8_t len);
extern bool esp_now_device_sync_wifi(esp_now_device_handle_t espnow_dev, uint8_t channel);
extern void esp_now_device_update_ip(esp_now_device_handle_t espnow_dev, char *ip);
extern espnow_com_err_t esp_now_group_sync_wifi(esp_now_device_handle_t espnow_dev);

/*初始化时配置参数*/     
extern espnow_com_err_t espnow_com_init(uint8_t _role, uint8_t _type, uint8_t _type_target, int8_t _bind_rssi_min, esp_now_device_event_handler_t _com_event_handle);
extern espnow_com_err_t espnow_com_start(int8_t core_id);

#define ESPNOW_COM_LOCK(c)          xSemaphoreTakeRecursive(c.instance_lock, portMAX_DELAY)
#define ESPNOW_COM_UNLOCK(c)        xSemaphoreGiveRecursive(c.instance_lock)

extern bool espnow_ctx_lock(uint32_t timeout_ms);
extern void espnow_ctx_unlock(void);

#define ESPNOW_COM_LOCK_GLOBAL()          espnow_ctx_lock(0)
#define ESPNOW_COM_UNLOCK_GLOBAL()        espnow_ctx_unlock()

typedef void (*esp_now_recv_callback_t)(const void *recv_info, const uint8_t *data, int len);  

extern bool mac_address_is_valid(uint8_t *mac_addr);   
extern void esp_now_device_set_primary_channel(uint8_t set_val);   
  
extern bool esp_now_device_write_data_group(esp_now_mac_group_list_t *mac_list,uint8_t *data, uint8_t len); 
extern int8_t esp_now_device_bind_require(void);
extern void esp_now_device_dump(void); 
extern void esp_now_device_task_exit(void);

#ifdef __cplusplus
}
#endif
