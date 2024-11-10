/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> 
#include <time.h> 
  
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

// #include "esp_timer.h" 
// #include "esp_check.h"  
// #include "esp_system.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h" 
 
#include "mbedtls/base64.h"
#include "mbedtls/md.h"
#include "mbedtls/pk.h"
#include "mbedtls/platform.h"

#include "cJSON.h"
// #include "esp_http_client.h"
// #include "esp_crt_bundle.h"

#include "bambu_api.h"
// #include "esp_spiffs.h"
// #include "esp_partition.h"
// #include "esp_chip_info.h"
// #include "esp_timer.h"
// #include "esp_heap_caps.h"

// #include "esp_ping.h" 
// #include "ping/ping_sock.h"
// #include <netdb.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/semphr.h"
// #include "freertos/timers.h"
// #include "freertos/event_groups.h"

#include "utils_lib.h"

#define SW_PRINT_BAMBU_API 0
static const char *TAG = "bambu_api"; 

#if SW_PRINT_BAMBU_API 
#include "esp_log.h" 
#define PRINT_BAMBU_API(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_BAMBU_API(...)
#endif  

static void * s_esp_psram_malloc(size_t size) 
{
    return malloc(size);
}

static void * s_esp_psram_calloc(size_t n, size_t size) 
{
    return calloc(n, size);
}

static void * s_esp_psram_realloc(void *ptr, size_t size) 
{
    return realloc(ptr, size);
}
    
static int base64_url_decode(char *output, size_t dist_buffer_len, size_t *output_len, char *input, size_t input_len)
{
    for (size_t i = 0; i < input_len; i++) {
        if (input[i] == '-') {
            input[i] = '+';
        } else if (input[i] == '_') {
            input[i] = '/';
        }
    }

    size_t padding = (4 - (input_len % 4)) % 4;
    char *padded_input = s_esp_psram_malloc(input_len + padding + 1);
    if (!padded_input) {
        return -1;
    }
    memcpy(padded_input, input, input_len);
    for (size_t i = 0; i < padding; i++) {
        padded_input[input_len + i] = '=';
    }
    padded_input[input_len + padding] = '\0';

    int ret = mbedtls_base64_decode((unsigned char *)output, dist_buffer_len, output_len, (const unsigned char *)padded_input, input_len + padding);
    if (ret)
    {
        PRINT_BAMBU_API("base64_url_decode output_len=%u",*output_len);
    }

    free(padded_input);
    return ret;
}

static int8_t decode_jwt(const char *jwt_token, char *out_payload, size_t buffer_size)
{
    char *token_copy = strdup(jwt_token);
    if (!token_copy) {
        PRINT_BAMBU_API("Failed to allocate memory for token copy");
        return -1;
    }

    // 拆分JWT
    char *header = strtok(token_copy, ".");
    char *payload = strtok(NULL, ".");

    if (!header || !payload ) {
        PRINT_BAMBU_API("Invalid JWT token");
        free(token_copy);
        return -1;
    }

    // 解码Header和Payload  
    size_t payload_len;
    base64_url_decode(out_payload, buffer_size,&payload_len, payload, strlen(payload));
    out_payload[payload_len] = '\0';

    // 打印解码后的Header和Payload 
    //PRINT_BAMBU_API("Payload: %s", out_payload);

    free(token_copy);
    
    return 0;
}
 
#if 0
esp_err_t _http_event_handler(esp_http_client_event_t *evt) {
    static char *output_buffer; // Buffer to store response of http request from event handler
    static int output_len;      // Stores number of bytes read

    switch (evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            if (!esp_http_client_is_chunked_response(evt->client)) 
            {
                
                if (output_buffer == NULL) {
                    output_buffer = (char *) s_esp_psram_malloc(esp_http_client_get_content_length(evt->client));
                    output_len = 0;
                    if (output_buffer == NULL) {
                        PRINT_BAMBU_API("Failed to allocate memory for output buffer");
                        return ESP_FAIL;
                    }
                }
                memcpy(output_buffer + output_len, evt->data, evt->data_len);
            
                output_len += evt->data_len;
            }
            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
            if (output_buffer != NULL) {
                // Response is accumulated in output_buffer. Uncomment the below line to print the accumulated response
                // ESP_LOGI(TAG, "Output: %s", output_buffer);
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            int mbedtls_err = 0;
            esp_err_t err = esp_tls_get_and_clear_last_error(evt->data, &mbedtls_err, NULL);
            if (err != 0) {
                ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
                ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
            }
            if (output_buffer != NULL) {
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
    }
    return ESP_OK;
}
#else
typedef int8_t esp_err_t;

typedef struct {
    bool need_cookies;
    char *buffer;
    int buffer_len;
} http_response_t;
 
esp_err_t _http_event_handler(esp_http_client_event_t *evt) {
    #if 0
    http_response_t *response = (http_response_t *)evt->user_data;

    switch (evt->event_id) 
    {    
        case HTTP_EVENT_ON_HEADER: 
            //PRINT_BAMBU_API("HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            if (response->need_cookies)
            {
                if (strcasecmp(evt->header_key, "Set-Cookie") == 0) 
                {
                    char *cookie = strdup(evt->header_value);
                    if (cookie != NULL) 
                    {
                        char *token = strtok(cookie, ";");
                        while (token != NULL) 
                        {
                            if (strncmp(token, "token=", 6) == 0) 
                            { 
                                if (token)
                                {
                                    if (token[0])
                                    { 
                                        uint8_t token_start_len = strlen("token=");
                                        uint32_t set_len = strlen("{\"accessToken\":\"\"}")+strlen(token)+10-token_start_len;
                                        //PRINT_BAMBU_API("token:[%s],len:%ld", token, set_len);

                                        if (response->buffer == NULL) 
                                        {
                                            response->buffer = (char *)s_esp_psram_malloc(set_len + 1);
                                            response->buffer_len = set_len;
                                        } 
                                        snprintf(response->buffer,set_len,"{\"accessToken\":\"%s\"}",&token[token_start_len]); 
                                        //PRINT_BAMBU_API("response->buffer: [%s]", response->buffer);
                                    }
                                }
                            }
                            token = strtok(NULL, ";");
                        }
                        free(cookie);
                    }
                }
            } 
            break;
            
        case HTTP_EVENT_ON_DATA:
            //PRINT_BAMBU_API("HTTP_EVENT_ON_DATA, len=%d", evt->data_len); 
            if (!response->need_cookies)
            {
                // Copy data to response buffer
                if (response->buffer == NULL) {
                    response->buffer = (char *)s_esp_psram_malloc(evt->data_len + 1);
                    response->buffer_len = evt->data_len;
                } else {
                    response->buffer = (char *)s_esp_psram_realloc(response->buffer, response->buffer_len + evt->data_len + 1);
                    response->buffer_len += evt->data_len;
                }
                memcpy(response->buffer + response->buffer_len - evt->data_len, evt->data, evt->data_len);
                response->buffer[response->buffer_len] = 0; 
            }

            break;
        default:
        {
            break;
        } 

    }
    #endif
    return 0;
}
#endif

static int8_t bambu_api_request(bool is_china, const char *token, const char *endpoint, const char *content_type, esp_http_client_method_t method, uint8_t *data, size_t len, char **out_result)
{
    char url[1024]={0};
    int8_t res = RES_BAMBU_ERROR;
    //char *url = NULL;
    char *result = NULL; 
    int64_t start, test_duration=0;

    if (endpoint)
    { 
        sprintf(url, "%s%s", is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER, endpoint);
    }
    else
    {
        sprintf(url, "%s", is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER);
    } 

    //PRINT_BAMBU_API("url:\"%s\"", url); 
    #if 0
    esp_http_client_config_t config = 
    {
        .url = url,
        .method = method,
        .timeout_ms = CONFIG_HTTP_REQUEST_TIMEOUT_MS,
        //.is_async = true,
        //.crt_bundle_attach = esp_crt_bundle_attach,
        .buffer_size=MAX_LEN_HTTP_BUFFER,
        .buffer_size_tx=MAX_LEN_HTTP_BUFFER, 
    };
    
    start = esp_timer_get_time(); 
 
    esp_http_client_handle_t client = esp_http_client_init(&config);
    char *headers = NULL;

    asprintf(&headers, "%s", content_type);
 
    if (NULL == headers)
    {
        res=RES_BAMBU_HTTP_MALLOC_ERROR;
        PRINT_BAMBU_API("Failed to allocate headers!");
        goto end;
    }

    esp_http_client_set_header(client, "Content-Type", headers);
    free(headers);
    
    if (token)
    {
        //PRINT_BAMBU_API("set token:\"%s\"", token);
        asprintf(&headers, "Bearer %s", token); 

        if (NULL == headers)
        {
            res=RES_BAMBU_HTTP_MALLOC_ERROR;
            PRINT_BAMBU_API("Failed to allocate bearer headers!");
            goto end;
        }

        esp_http_client_set_header(client, "Authorization", headers);
        free(headers);
    } 
 
    esp_err_t err = esp_http_client_open(client, len);
    if (ESP_OK != err)
    {
        res=RES_BAMBU_HTTP_OPEN_ERROR;
        PRINT_BAMBU_API("Failed to open http client!");
        goto end;
    } 

    if (len > 0) {
        int wlen = esp_http_client_write(client, (const char *)data, len); 
        if (wlen < 0)
        {
            res=RES_BAMBU_HTTP_WRITE_ERROR;
            PRINT_BAMBU_API("Failed to write client!");
            goto end;
        }  
    }
    int content_length = esp_http_client_fetch_headers(client);
    if (esp_http_client_is_chunked_response(client)) {  
        esp_http_client_get_chunk_length(client, &content_length); 
    } 
    if (content_length < 0)
    {
        res=RES_BAMBU_HTTP_CHUNK_LENGTH_ERROR;
        PRINT_BAMBU_API("HTTP client fetch headers failed!");
        goto end;
    }   

    result = (char *)s_esp_psram_malloc(content_length + 1);
    int read = esp_http_client_read_response(client, result, content_length); 
    
    if (read != content_length) { 
        res=RES_BAMBU_HTTP_RESPONSE_INVALID;
        PRINT_BAMBU_API("HTTP_ERROR: read=%d, length=%d", read, content_length); 
        free(result);
        result = NULL;
    } else {
        /*如果返回的不是json也报错*/
        result[content_length] = 0; 
        res=RES_BAMBU_OK;
        *out_result = result;
    }

end:
    test_duration = esp_timer_get_time() - start;

    //PRINT_BAMBU_API("run takes %ld ms\n", (long int)(test_duration/1000));
 
    esp_http_client_close(client);
    esp_http_client_cleanup(client); 
    #endif
    
    return res;
}

static int8_t bambu_api_request_get_test(bool need_cookies,const char *host, const char *token, const char *endpoint, const char *content_type, esp_http_client_method_t method, uint8_t *data, size_t len, char **out_result)
{
    char url[1024]={0};
    int8_t res = RES_BAMBU_ERROR;
    //char *url = NULL; 
    int64_t start, test_duration=0;
    
    http_response_t response = {0};

    response.need_cookies=need_cookies;

    if (endpoint)
    { 
        sprintf(url, "%s%s", host, endpoint);
    }
    else
    {
        sprintf(url, "%s", host);
    } 

    //PRINT_BAMBU_API("url:\"%s\"", url); 
    #if 0
    esp_http_client_config_t config = 
    {
        .url = url,
        .method = method,
        .timeout_ms = CONFIG_HTTP_REQUEST_TIMEOUT_MS, 
        .buffer_size=MAX_LEN_HTTP_BUFFER,
        .buffer_size_tx=MAX_LEN_HTTP_BUFFER,
        .event_handler = _http_event_handler,
        .user_data = &response,
    };
    
    start = esp_timer_get_time(); 
 
    esp_http_client_handle_t client = esp_http_client_init(&config);
    char *headers = NULL;

    asprintf(&headers, "%s", content_type);
 
    if (NULL == headers)
    {
        res=RES_BAMBU_HTTP_MALLOC_ERROR;
        PRINT_BAMBU_API("Failed to allocate headers!");
        goto end;
    }

    esp_http_client_set_header(client, "Content-Type", headers);
    free(headers);
    
    if (token)
    {
        //PRINT_BAMBU_API("set token:\"%s\"", token);
        asprintf(&headers, "Bearer %s", token); 

        if (NULL == headers)
        {
            res=RES_BAMBU_HTTP_MALLOC_ERROR;
            PRINT_BAMBU_API("Failed to allocate bearer headers!");
            goto end;
        }

        esp_http_client_set_header(client, "Authorization", headers);
        free(headers);
    } 
    
    #if 0
    esp_err_t err = esp_http_client_open(client, len);
    if (ESP_OK != err)
    {
        res=RES_BAMBU_HTTP_OPEN_ERROR;
        PRINT_BAMBU_API("Failed to open http client!");
        goto end;
    } 

    if (len > 0) {
        int wlen = esp_http_client_write(client, (const char *)data, len); 
        if (wlen < 0)
        {
            res=RES_BAMBU_HTTP_WRITE_ERROR;
            PRINT_BAMBU_API("Failed to write client!");
            goto end;
        }  
    }
    int content_length = esp_http_client_fetch_headers(client);
    if (esp_http_client_is_chunked_response(client)) { 
        PRINT_BAMBU_API("is_chunked_response chunk_length=%d", content_length);
        esp_http_client_get_chunk_length(client, &content_length);
        PRINT_BAMBU_API("is_chunked_response chunk_length2=%d", content_length);
    }

    PRINT_BAMBU_API("chunk_length=%d", content_length);
    if (content_length < 0)
    {
        res=RES_BAMBU_HTTP_CHUNK_LENGTH_ERROR;
        PRINT_BAMBU_API("HTTP client fetch headers failed!");
        goto end;
    }   

    result = (char *)s_esp_psram_malloc(content_length + 1);
    int read = esp_http_client_read_response(client, result, content_length); 
    
    if (read != content_length) { 
        res=RES_BAMBU_HTTP_RESPONSE_INVALID;
        PRINT_BAMBU_API("HTTP_ERROR: read=%d, length=%d", read, content_length); 
        free(result);
        result = NULL;
    } else {
        /*如果返回的不是json也报错*/
        result[content_length] = 0; 
        res=RES_BAMBU_OK;
        *out_result = result;
    }
    #else
    
    if (HTTP_METHOD_POST == method)
    { 
        if (len > 0)
        {
            esp_http_client_set_post_field(client,  (const char *)data, len);
        } 
    }
    
    vTaskDelay(pdMS_TO_TICKS(500));
    // Perform the HTTP POST request
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) 
    {
        int status_code = esp_http_client_get_status_code(client);
        //PRINT_BAMBU_API("HTTP POST Status = %d, response->buffer_len = %d", status_code, response.buffer_len); 
        res=RES_BAMBU_OK; 
 
        if (200 != status_code)
        {
            int content_length =  esp_http_client_get_content_length(client); 

            if ((content_length <=0)
                || (response.buffer_len <=0)
                || (response.buffer_len != content_length))
            {
                res=RES_BAMBU_HTTP_RESPONSE_INVALID;
                PRINT_BAMBU_API("HTTP_ERROR: buffer_len=%d, length=%d", response.buffer_len, content_length);
            }
        }  
    } 
    else 
    {
        res=RES_BAMBU_HTTP_RESPONSE_INVALID;
        PRINT_BAMBU_API("HTTP request failed: %s", esp_err_to_name(err)); 
        PRINT_BAMBU_API("HTTP_ERROR: length=%d", response.buffer_len); 
    }
    #endif

    if (RES_BAMBU_OK != res)
    {
        if (response.buffer)
        {
            free(response.buffer);
            response.buffer = NULL;
        }
    }

    *out_result = response.buffer;

end:
    test_duration = esp_timer_get_time() - start;

    //PRINT_BAMBU_API("run takes %ld ms\n", (long int)(test_duration/1000));
 
    esp_http_client_close(client);
    esp_http_client_cleanup(client); 
    #endif

    return res;
}

static bool json_is_Valid(cJSON *json_check)
{
    if (!json_check)
    {
        return false;
    }

    if (!cJSON_IsObject(json_check))
    {
        return false;
    }

    return true;
}

static void bambu_mqtt_cloud_reset_devices(bambu_account_info_t *get_account_info)
{
    /*登录成功后，删除所有的device信息*/
    for (uint8_t i=0; i<MAX_COUNT_DEV; i++)
    {
        bambu_dev_t *get_dev = &get_account_info->printers[i]; 
        memset(get_dev->sn,0,MAX_LEN_SN);
        memset(get_dev->access_code,0,MAX_LEN_ACCESS_CODE);
        get_dev->user_data=NULL; 
    }
} 

void bambu_api_reset_account(bambu_account_info_t *get_account_info)
{  
    #if 0
    get_account_info->mqtt_status = 0;
    get_account_info->client=NULL;
    memset(get_account_info->username_mqtt,0,MAX_LEN_USER);
    memset(get_account_info->password_mqtt,0,MAX_LEN_TOKEN);
    memset(get_account_info->uid_str,0,MAX_LEN_UID);
    memset(get_account_info->username,0,MAX_LEN_USER);
    get_account_info->printer_cnt=0;
    bambu_mqtt_cloud_reset_devices(get_account_info);    
    #endif
}

void bambu_api_fat_init(void)
{
    #if 0
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = PARTITION_LABEL_SPIFFS_ACCOUNT,
      .max_files = 5,
      .format_if_mount_failed = true, 
    };

    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
 
    esp_err_t ret = esp_vfs_spiffs_register(&conf); 

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            PRINT_BAMBU_API("Failed to mount or format filesystem");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            PRINT_BAMBU_API("Failed to find SPIFFS partition");
        } else {
            PRINT_BAMBU_API("Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return;
    } 

    size_t total = 0, used = 0;
    ret = esp_spiffs_info(conf.partition_label, &total, &used);
    if (ret != ESP_OK) {
        PRINT_BAMBU_API("Failed to get SPIFFS partition information (%s). Formatting...", esp_err_to_name(ret));
        esp_spiffs_format(conf.partition_label);
        return;
    } else {
        PRINT_BAMBU_API("Partition size: total: %d, used: %d", total, used);
    }
    #endif
}

/*api 有
1 登录
2 获取已绑定打印机列表
3 获取文件列表
4 获取用户信息
*/

/*
1 登录 
传入参数有account 和 password 

返回结果有
登录超时
密码错误
登陆成功
登录成功后，填充token和u_xxxxx
u_xxxx用户登录mqtt和显示用户名
*/

int8_t bambu_api_get_local_token(char *token_out, char *account, char *password, uint8_t nvs_idx)
{
    int8_t res = RES_BAMBU_ERROR;
    #if 0
    cJSON *result_json = NULL; 

    /*检查用户名和密码*/
    /*不能为空*/
    if ((!account[0])
        || (!password[0]))
    {
        return RES_BAMBU_ERROR;
    }

    if (nvs_idx >= BAMBU_ACCOUNT_CNT_MAX)
    {
        return RES_BAMBU_ERROR;
    }

    /*读取文件*/
    char file_name[64]={0};

    sprintf(file_name,"/spiffs/account_%02d.json",nvs_idx);
    
    ESP_LOGI(TAG, "Read file_name: '%s'", file_name);
    
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        PRINT_BAMBU_API("Failed to open file [%s]",file_name);
        return RES_BAMBU_ERROR;
    }

    /*文件存在 读取json内容*/
    char *account_json_str= NULL;
    /*改为动态申请内存*/
    fseek(f,0,SEEK_END);
    long file_size = ftell(f);
    if (!file_size)
    {
        goto read_token_err;
    }

    rewind(f);
    account_json_str = (char *)s_esp_psram_malloc(file_size);
    if (!account_json_str)
    {
        goto read_token_err;
    }

    int ret = fread(account_json_str, 1, file_size, f);
    ESP_LOGI(TAG, "Read res: '%d'", ret);
    if (ret <= 0)
    { 
        goto read_token_err;
    }
    result_json = cJSON_Parse(account_json_str); 
    if (!json_is_Valid(result_json))
    {
        goto read_token_err;
    }

    char *read_account = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "account"));
    if (!read_account)
    {
        goto read_token_err;
    }

    //ESP_LOGI(TAG, "get file read_account: [%s]", read_account);

    char *read_password = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "password"));
    if (!read_password)
    {
        goto read_token_err;
    }

    //ESP_LOGI(TAG, "get file read_password: [%s]", read_password);
    
    /*如果account 和 password都相同 则提取对用的token*/ 

    if (strcmp(read_account,account))
    {
        goto read_token_err;
    }

    if (strcmp(read_password,password))
    {
        goto read_token_err;
    }

    char *read_token = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "token"));
    if (!read_token)
    {
        goto read_token_err; 
    }
    
    //ESP_LOGI(TAG, "get file read_token: [%s]", read_token);
    strlcpy(token_out,read_token,MAX_LEN_TOKEN);
    
    res = RES_BAMBU_OK;
    read_token_err:
    if (account_json_str)
    {
        free(account_json_str);
    }
    
    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (f)
    {
        fclose(f);
    } 
    #endif

    return res;
}

int8_t bambu_api_token_is_valid(char *token, uint8_t region)
{
    /*长度限制*/
    bool is_china = (REGION_CHINA == region);

    
    int8_t res = RES_BAMBU_ERROR;
    #if 0
    cJSON *result_json = NULL; 
    char *result = NULL; 
    
    if ((!token)
        || (!token[0]))
    {
        return RES_BAMBU_ERROR;
    }
    
    int8_t res_request = bambu_api_request_get_test(false,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,token,BAMBU_API_ENDPOINT_BIND,"application/json",HTTP_METHOD_GET,NULL,NULL,&result);
    if ((res_request) || (!result))
    {
        res = RES_BAMBU_HTTP_RESPONSE_INVALID;
        PRINT_BAMBU_API("res_request:%d,result[%x]",res_request,(unsigned int)result); 
        goto check_token_err;
    } 
 
    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        res = RES_BAMBU_HTTP_RESPONSE_INVALID; 

        PRINT_BAMBU_API("invalid result json");
        goto check_token_err;
    } 

    char *message = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "message")); 
    if (!message)
    { 
        res = RES_BAMBU_ACCOUNT_ERROR;
        goto check_token_err;
    } 

    //PRINT_BAMBU_API("message[%s]",message);
    if (strcmp(message,"success"))
    {
        res = RES_BAMBU_ACCOUNT_ERROR;
        goto check_token_err;
    }

    res=RES_BAMBU_OK;

    check_token_err:
    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (result)
    {
        free(result);
    }
    #endif

    return res;
}

int8_t bambu_api_get_username(char *token, char *username)
{
    int8_t res = RES_BAMBU_ERROR;
    #if 0
    char *decoded_payload = NULL;
    cJSON *json_payload = NULL;

    if ((!token)
        || (!token[0]))
    {
        return RES_BAMBU_ERROR;
    }

    if (!username)
    {
        return RES_BAMBU_ERROR;
    }

    decoded_payload = (char *)s_esp_psram_malloc(MAX_LEN_PAYLOAD);
    if (!decoded_payload)
    {
        goto get_username_err;
    }
 
    memset(decoded_payload,0,MAX_LEN_PAYLOAD);

    if (0 != decode_jwt(token,decoded_payload,MAX_LEN_PAYLOAD))
    {
        goto get_username_err;
    }

    json_payload = cJSON_Parse(decoded_payload); 

    if (!json_is_Valid(json_payload))
    {
        goto get_username_err;
    }

    char *get_user_name = cJSON_GetStringValue(cJSON_GetObjectItem(json_payload, "username"));
    
    if (!get_user_name)
    {
        goto get_username_err;
    } 

    strlcpy(username,get_user_name,MAX_LEN_USER); 

    res=RES_BAMBU_OK;

    get_username_err:
    if (json_payload)
    {
        cJSON_Delete(json_payload); 
    }

    if (decoded_payload)
    {
        free(decoded_payload);
    }
    #endif

    return res;
}

int8_t bambu_api_save_account(char *set_account, char *set_password, char *set_token,uint8_t set_nvs_index)
{
    int8_t res = RES_BAMBU_ERROR;
    #if 0
    char *account_json_str = NULL;

    if ((!set_account)
        || (!set_account[0]))
    {
        PRINT_BAMBU_API("invalid account");

        return RES_BAMBU_ERROR;
    }

    if ((!set_password)
        || (!set_password[0]))
    {
        PRINT_BAMBU_API("invalid password");

        return RES_BAMBU_ERROR;
    }

    if ((!set_token)
        || (!set_token[0]))
    {
        PRINT_BAMBU_API("invalid token");

        return RES_BAMBU_ERROR;
    }

    if (set_nvs_index >= BAMBU_ACCOUNT_CNT_MAX)
    {
        PRINT_BAMBU_API("invalid nvs");

        return RES_BAMBU_ERROR;
    }

    char file_name[64]={0};
    sprintf(file_name,"/spiffs/account_%02d.json",set_nvs_index);

    //PRINT_BAMBU_API("Opening file [%s]",file_name);

    FILE* ff = fopen(file_name, "w");

    if (ff == NULL) 
    {
        PRINT_BAMBU_API("Failed to open file for writing");
        return -1;
    }

    cJSON *account_json = cJSON_CreateObject();  

    if (!account_json) 
    {
        PRINT_BAMBU_API("Failed to create json");
        goto save_account_err;
    }

    cJSON_AddItemToObject(account_json, "account", cJSON_CreateString(set_account));
    cJSON_AddItemToObject(account_json, "password", cJSON_CreateString(set_password));
    cJSON_AddItemToObject(account_json, "token", cJSON_CreateString(set_token));

    account_json_str = cJSON_Print(account_json); 
    if (!account_json_str)
    {
        PRINT_BAMBU_API("Failed to create account json str");
        goto save_account_err;
    }

    fwrite(account_json_str,1,strlen(account_json_str),ff);

    res = RES_BAMBU_OK;
 
    save_account_err:

    if (account_json_str)
    {
        free(account_json_str);
    }

    if (account_json)
    {
        cJSON_Delete(account_json); 
    }
     
    if (ff)
    {
        fclose(ff);
    }
    #endif

    return res;
}
 
int8_t bambu_api_login(bambu_account_info_t *_account, uint8_t region, char *account, char *password)
{
    int8_t res = RES_BAMBU_ERROR;

    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }
 
    /*检查用户名和密码*/
    /*不能为空*/
    if ((!account[0])
        || (!password[0]))
    {
        return RES_BAMBU_ERROR;
    }

    /*长度限制*/
    if (strlen(account) >= (MAX_LEN_ACCOUNT-1))
    {
        return RES_BAMBU_ERROR;
    }
    
    if (strlen(password) >= (MAX_LEN_PASSWORD-1))
    {
        return RES_BAMBU_ERROR;
    }

    // strlcpy(_account->nvs_config.account,account,MAX_LEN_ACCOUNT); 
    // strlcpy(_account->nvs_config.password,password,MAX_LEN_PASSWORD); 

    cJSON *account_json = cJSON_CreateObject();
    cJSON *result_json = NULL;
    cJSON *json_payload = NULL;
    char *account_json_str = NULL;
    char *result = NULL;
    char *decoded_payload = NULL; 
    if (!account_json)
    {
        goto login_err;
    }

    cJSON_AddItemToObject(account_json, "account", cJSON_CreateString(account));
    cJSON_AddItemToObject(account_json, "password", cJSON_CreateString(password));

    account_json_str = cJSON_Print(account_json); 
  
    //PRINT_BAMBU_API("account_json_str:%s",account_json_str);

    bool is_china = (REGION_CHINA == region);
    #ifdef USING_API_1
    int8_t res_request = bambu_api_request_get_test(false,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,NULL,BAMBU_API_ENDPOINT_LOGIN,"application/json",HTTP_METHOD_POST,(uint8_t *)account_json_str, strlen(account_json_str),&result);
    #else
    int8_t res_request = bambu_api_request_get_test(true,is_china?BAMBU_API_BASE_URL_CHINA_SIGN_IN:BAMBU_API_BASE_URL_OTHER_SIGN_IN,NULL,BAMBU_API_ENDPOINT_LOGIN,"application/json",HTTP_METHOD_POST,(uint8_t *)account_json_str, strlen(account_json_str),&result);
    #endif
    if ((res_request) || (!result))
    {
        res = res_request;
        //_account->network_ok=false;
        goto login_err;
    }
 
    #if 0
    {
        "code": 2,
        "error": "Incorrect password"
    }

    {
        "code": 1,
        "error": "This account is not registered."
    }
    #endif

    //_account->network_ok=true;
    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        if (strlen(result) > 0)
        {
            res = RES_BAMBU_HTTP_RESPONSE_INVALID; 
        } 

        goto login_err;
    }

    /*get the token*/
    char *token = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "accessToken"));
    if (!token)
    {
        /*check the code*/

        int e_code = cJSON_GetNumberValue(cJSON_GetObjectItem(result_json, "code"));

        if (1 == e_code)
        {
            /*account not registered*/
            res = RES_BAMBU_ACCOUNT_NOT_REG;
        }
        else if (2 == e_code)
        {
            res = RES_BAMBU_PASSWORD_INVALID;
        }

        goto login_err;
    }

    //PRINT_BAMBU_API("token:%s",token); 
    bambu_api_reset_account(_account);
    
    decoded_payload = (char *)s_esp_psram_malloc(MAX_LEN_PAYLOAD);
    if (!decoded_payload)
    {
        goto login_err;
    }

    strlcpy(_account->password_mqtt,token,MAX_LEN_TOKEN); 

    memset(decoded_payload,0,MAX_LEN_PAYLOAD);

    if (0 != decode_jwt(token,decoded_payload,MAX_LEN_PAYLOAD))
    {
        goto login_err;
    }

    json_payload = cJSON_Parse(decoded_payload); 

    if (!json_is_Valid(json_payload))
    {
        goto login_err;
    }

    char *get_user_name = cJSON_GetStringValue(cJSON_GetObjectItem(json_payload, "username"));
    
    if (!get_user_name)
    {
        goto login_err;
    } 

    strlcpy(_account->username_mqtt,get_user_name,MAX_LEN_USER); 

    cJSON_Delete(account_json); 
    cJSON_Delete(result_json); 
    cJSON_Delete(json_payload);   
 
    free(result);
    free(account_json_str); 
    free(decoded_payload);

    return 0;

    login_err:

    if (account_json)
    {
        cJSON_Delete(account_json); 
    }

    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (json_payload)
    {
        cJSON_Delete(json_payload); 
    }

    if (account_json_str)
    {
        free(account_json_str);
    }

    if (result)
    {
        free(result);
    }

    if (decoded_payload)
    {
        free(decoded_payload);
    }
    
    return res;
}

int8_t bambu_api_sign_in(bambu_account_info_t *_account, uint8_t region, char *account, char *password)
{
    int8_t res = RES_BAMBU_ERROR;

    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }
 
    /*检查用户名和密码*/
    /*不能为空*/
    if ((!account[0])
        || (!password[0]))
    {
        return RES_BAMBU_ERROR;
    }

    /*长度限制*/
    if (strlen(account) >= (MAX_LEN_ACCOUNT-1))
    {
        return RES_BAMBU_ERROR;
    }
    
    if (strlen(password) >= (MAX_LEN_PASSWORD-1))
    {
        return RES_BAMBU_ERROR;
    }

    // strlcpy(_account->nvs_config.account,account,MAX_LEN_ACCOUNT); 
    // strlcpy(_account->nvs_config.password,password,MAX_LEN_PASSWORD); 

    cJSON *account_json = cJSON_CreateObject();
    cJSON *result_json = NULL;
    cJSON *json_payload = NULL;
    char *account_json_str = NULL;
    char *result = NULL;
    char *decoded_payload = NULL;

    if (!account_json)
    {
        goto login_err;
    }

    cJSON_AddItemToObject(account_json, "account", cJSON_CreateString(account));
    cJSON_AddItemToObject(account_json, "password", cJSON_CreateString(password));

    account_json_str = cJSON_Print(account_json); 
  
    //PRINT_BAMBU_API("account_json_str:%s",account_json_str);

    bool is_china = (REGION_CHINA == region);
 
    int8_t res_request = bambu_api_request_get_test(true,is_china?BAMBU_API_BASE_URL_CHINA_SIGN_IN:BAMBU_API_BASE_URL_OTHER_SIGN_IN,NULL,BAMBU_API_ENDPOINT_LOGIN,"application/json",HTTP_METHOD_POST,(uint8_t *)account_json_str, strlen(account_json_str),&result);

    if ((res_request) || (!result))
    {
        res = res_request;
        //_account->network_ok=false;
        goto login_err;
    }
 
    #if 0
    {
        "code": 2,
        "error": "Incorrect password"
    }

    {
        "code": 1,
        "error": "This account is not registered."
    }
    #endif

    //_account->network_ok=true;
    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        if (strlen(result) > 0)
        {
            res = RES_BAMBU_HTTP_RESPONSE_INVALID; 
        } 

        goto login_err;
    }

    /*get the token*/
    char *token = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "accessToken"));
    if (!token)
    {
        /*check the code*/

        int e_code = cJSON_GetNumberValue(cJSON_GetObjectItem(result_json, "code"));

        if (1 == e_code)
        {
            /*account not registered*/
            res = RES_BAMBU_ACCOUNT_NOT_REG;
        }
        else if (2 == e_code)
        {
            res = RES_BAMBU_PASSWORD_INVALID;
        }

        goto login_err;
    }

    PRINT_BAMBU_API("token:%s",token); 
    bambu_api_reset_account(_account);
    
    decoded_payload = (char *)s_esp_psram_malloc(MAX_LEN_PAYLOAD);
    if (!decoded_payload)
    {
        goto login_err;
    }

    strlcpy(_account->password_mqtt,token,MAX_LEN_TOKEN); 

    memset(decoded_payload,0,MAX_LEN_PAYLOAD);

    if (0 != decode_jwt(token,decoded_payload,MAX_LEN_PAYLOAD))
    {
        goto login_err;
    }

    json_payload = cJSON_Parse(decoded_payload); 

    if (!json_is_Valid(json_payload))
    {
        goto login_err;
    }

    char *get_user_name = cJSON_GetStringValue(cJSON_GetObjectItem(json_payload, "username"));
    
    if (!get_user_name)
    {
        goto login_err;
    } 

    strlcpy(_account->username_mqtt,get_user_name,MAX_LEN_USER); 

    cJSON_Delete(account_json); 
    cJSON_Delete(result_json); 
    cJSON_Delete(json_payload);   
 
    free(result);
    free(account_json_str); 
    free(decoded_payload);

    return 0;

    login_err:

    if (account_json)
    {
        cJSON_Delete(account_json); 
    }

    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (json_payload)
    {
        cJSON_Delete(json_payload); 
    }

    if (account_json_str)
    {
        free(account_json_str);
    }

    if (result)
    {
        free(result);
    }

    if (decoded_payload)
    {
        free(decoded_payload);
    }
    
    return res;
}

/*2 获取已绑定打印机列表，调用时需要传入token*/
int8_t bambu_api_get_devices(bambu_account_info_t *_account)
{
    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }

    /*长度限制*/
    bool is_china = (REGION_CHINA == _account->nvs_config.region);

    cJSON *result_json = NULL; 
    int8_t res = RES_BAMBU_ERROR;
    char *result = NULL; 

    int8_t res_request = bambu_api_request_get_test(false,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,_account->password_mqtt,BAMBU_API_ENDPOINT_BIND,"application/json",HTTP_METHOD_GET,NULL,NULL,&result);
    if ((res_request) || (!result))
    {
        res = RES_BAMBU_HTTP_RESPONSE_INVALID;
        //PRINT_BAMBU_API("res_request:%d,result[%x]",res_request,(unsigned int)result);
        //_account->network_ok=false;
        goto get_bind_err;
    } 
 
    //_account->network_ok=true;
    
    //PRINT_BAMBU_API("connect_state=[%02x]",(int)_account->connect_state);

    /*检查token*/
    /*不能为空*/
    if ((!_account->username_mqtt[0])
        || (!_account->password_mqtt[0]))
    {
        /*如果为空说明没有登录*/
        if ((_account->connect_state & ~(uint32_t)ACCOUNT_ERROR_IGNORE_BIT) == AC_STATE_ERROR_PASSWORD)
        {
            return RES_BAMBU_PASSWORD_INVALID;
        }

        if ((_account->connect_state & ~(uint32_t)ACCOUNT_ERROR_IGNORE_BIT) == AC_STATE_ERROR_ACCOUNT)
        {
            return RES_BAMBU_ACCOUNT_NOT_REG;
        }
        
        return RES_BAMBU_ERROR;
    }

    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        res = RES_BAMBU_HTTP_RESPONSE_INVALID; 

        //PRINT_BAMBU_API("invalid result json");
        goto get_bind_err;
    }
#if 0
{
	"code": 4,
	"error": "Please login.",
	"message": ""
}

{
	"message": "success",
	"code": null,
	"error": null,
	"devices": [
		{
			"dev_id": "01P00A371400209",
			"name": "P1S--",
			"online": true,
			"print_status": "ACTIVE",
			"dev_model_name": "C12",
			"dev_product_name": "P1S",
			"dev_access_code": "39392609",
			"nozzle_diameter": 0.4
		}
	]
}
#endif
    char *message = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "message")); 
    if (!message)
    { 
        res = RES_BAMBU_ACCOUNT_ERROR;
        goto get_bind_err;
    } 

    //PRINT_BAMBU_API("message[%s]",message);
    if (strcmp(message,"success"))
    {
        res = RES_BAMBU_ACCOUNT_ERROR;
        goto get_bind_err;
    }

    cJSON *printer_array = cJSON_GetObjectItem(result_json, "devices");
    if (!cJSON_IsArray(printer_array))
    {
        res = RES_BAMBU_HTTP_RESPONSE_INVALID; 
        //PRINT_BAMBU_API("invalid devices json");
        goto get_bind_err;
    }

    /*获取code的值 如果不是null 是其他值则认为response报错*/
    /*或者message bu为success 为空则报错*/
 
    /*更新account 账户的绑定 sn列表*/
    size_t printer_cnt = cJSON_GetArraySize(printer_array);

    //PRINT_BAMBU_API("printer_cnt=[%02x]",printer_cnt);

    if (printer_cnt>MAX_COUNT_DEV)
    {
        printer_cnt=MAX_COUNT_DEV;
    }
    _account->printer_cnt = printer_cnt;

    for (uint8_t i = 0; i < printer_cnt; ++i)
    {
        cJSON *get_device = cJSON_GetArrayItem(printer_array, i);
        if (!json_is_Valid(get_device))
        {
            PRINT_BAMBU_API("invaid get_device [%02x]",i);
            continue;
        }
        
        char *dev_sn = cJSON_GetStringValue(cJSON_GetObjectItem(get_device, "dev_id")); 
        if (dev_sn)
        {
            strlcpy(_account->printers[i].sn,dev_sn,MAX_LEN_SN); 
            //PRINT_BAMBU_API("dev_sn [%s]",dev_sn);
        }

        char *dev_access_code = cJSON_GetStringValue(cJSON_GetObjectItem(get_device, "dev_access_code")); 
        if (dev_access_code)
        {
            strlcpy(_account->printers[i].access_code,dev_access_code,MAX_LEN_ACCESS_CODE); 
            //PRINT_BAMBU_API("dev_access_code [%s]",dev_access_code);
        } 

        char *dev_name = cJSON_GetStringValue(cJSON_GetObjectItem(get_device, "name")); 
        if (dev_name)
        {
            strlcpy(_account->printers[i].name,dev_name,MAX_LEN_PRINTER_NAME); 
            //PRINT_BAMBU_API("name [%s]",dev_name);
        } 

        char *dev_model_name = cJSON_GetStringValue(cJSON_GetObjectItem(get_device, "dev_model_name")); 
        if (dev_model_name)
        {
            strlcpy(_account->printers[i].dev_model_name,dev_model_name,MAX_LEN_MODEL_NAME); 
            //PRINT_BAMBU_API("dev_model_name [%s]",dev_model_name);
        }
        char *dev_product_name = cJSON_GetStringValue(cJSON_GetObjectItem(get_device, "dev_product_name")); 
        if (dev_product_name)
        {
            strlcpy(_account->printers[i].dev_product_name,dev_product_name,MAX_LEN_MODEL_NAME); 
            //PRINT_BAMBU_API("dev_product_name [%s]",dev_product_name);
        }
        cJSON *is_online = cJSON_GetObjectItemCaseSensitive(get_device, "online");
        if (cJSON_IsBool(is_online)) 
        {
            _account->printers[i].is_online=cJSON_IsTrue(is_online);
        }
    }     
    
    cJSON_Delete(result_json); 
    
    free(result);

    return 0;

    get_bind_err:

    PRINT_BAMBU_API("get_bind_err");

    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (result)
    {
        free(result);
    }
    
    return res;
}


/*3 获取用户信息*/
int8_t bambu_api_get_profile(bambu_account_info_t *_account)
{
    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }

    /*检查token*/
    /*不能为空*/
    if ((!_account->username_mqtt[0])
        || (!_account->password_mqtt[0]))
    {
        return RES_BAMBU_ERROR;
    }

    /*长度限制*/
    bool is_china = (REGION_CHINA == _account->nvs_config.region);
    int8_t res = RES_BAMBU_ERROR;
    char *result = NULL;
    int8_t res_request = bambu_api_request_get_test(false,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,_account->password_mqtt,BAMBU_API_ENDPOINT_PROFILE,"application/json",HTTP_METHOD_GET,NULL,NULL,&result);
    cJSON *result_json =NULL;
    if ((res_request) || (!result))
    {
        res = res_request;
        goto get_profile_err;
    }  

    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        goto get_profile_err;
    } 

#if 0
        "uid": 1192240223,
        "uidStr": "1192240223",
        "account": "18673363693",
        "name": "你好啊",  
#endif

    char *uidStr = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "uidStr")); 
    if (uidStr)
    {
        //PRINT_BAMBU_API("uidStr [%s]",uidStr);
        strlcpy(_account->uid_str,uidStr,MAX_LEN_UID);  
    } 

    // char *account = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "account")); 
    // if (account)
    // {
    //     PRINT_BAMBU_API("account [%s]",account); 
    // } 

    char *name = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "name")); 
    if (name)
    {
        //PRINT_BAMBU_API("name [%s]",name);
        strlcpy(_account->username,name,MAX_LEN_USER); 
    } 

    cJSON_Delete(result_json); 
    
    free(result);

    return 0;

    get_profile_err:

    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (result)
    {
        free(result);
    }
    
    return res;
}

#if 0 
{
  "modelId": "CNa4abc0b16a0efa",
  "title": "大话西游水帘洞夜灯",
  "cover": "https://model-file.bambulab.cn/private/CNa4abc0b16a0efa/25361933/3mf/Metadata/plate_1.png?x-oss-traffic-limit=25165824&OSSAccessKeyId=LTAI5tFANCnfNNPNSSLjG97f&Expires=1728550986&Signature=6AvVo%2FqfKsylqNTgEPlZ3BRj2tw%3D",
  "deviceId": "01S00C3A1600394", 
  "profileId": 25361933,
  "plateIndex": 1, 
  "mode": "auto_repeat"
}
#endif

int8_t bambu_api_print_by_history(bambu_account_info_t *_account, bambu_print_history_t *print_history)
{
    int8_t res = RES_BAMBU_ERROR;

    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }
 
    /*检查用户名和密码*/
    /*不能为空*/
    if ((!print_history->title[0])
        || (!print_history->deviceId[0])
        || (!print_history->modelId[0])
        )
    {
        PRINT_BAMBU_API("invalid parameter title=%s,deviceId=%s,modelId=%s",print_history->title,print_history->deviceId,print_history->modelId);

        return RES_BAMBU_ERROR;
    }
  
    cJSON *continue_print = cJSON_CreateObject();
    cJSON *result_json = NULL;
    char *post_json_str = NULL;
    char *result = NULL;
  
    if (!continue_print)
    {
        PRINT_BAMBU_API("create continue_print failed");

        goto continue_print_err;
    }

    cJSON_AddItemToObject(continue_print, "modelId", cJSON_CreateString(print_history->modelId));
    cJSON_AddItemToObject(continue_print, "title", cJSON_CreateString(print_history->title));
    cJSON_AddItemToObject(continue_print, "cover", cJSON_CreateString(print_history->cover));
    cJSON_AddItemToObject(continue_print, "deviceId", cJSON_CreateString(print_history->deviceId));
    cJSON_AddItemToObject(continue_print, "profileId", cJSON_CreateNumber(print_history->profileId));
    cJSON_AddItemToObject(continue_print, "nozzleDiameter", cJSON_CreateNumber(print_history->nozzleDiameter)); 
    cJSON_AddItemToObject(continue_print, "plateIndex", cJSON_CreateNumber((double)print_history->plateIndex)); 
    cJSON_AddItemToObject(continue_print, "mode", cJSON_CreateString(print_history->mode));
 
    cJSON_AddItemToObject(continue_print, "timelapse", print_history->timelapse?cJSON_CreateTrue():cJSON_CreateFalse());
    cJSON_AddItemToObject(continue_print, "bedLeveling", print_history->bedLeveling?cJSON_CreateTrue():cJSON_CreateFalse());
    cJSON_AddItemToObject(continue_print, "flowCali", print_history->flowCali?cJSON_CreateTrue():cJSON_CreateFalse());
    cJSON_AddItemToObject(continue_print, "useAms", print_history->useAms?cJSON_CreateTrue():cJSON_CreateFalse());
   
    post_json_str = cJSON_Print(continue_print); 
    if (!post_json_str)
    {
        res = -1; 
        PRINT_BAMBU_API("cJSON_Print post_json_str failed");
        goto continue_print_err;
    }

    PRINT_BAMBU_API("post_json_str:%s",post_json_str);

    bool is_china = (REGION_CHINA == _account->nvs_config.region);
     
    int8_t res_request = bambu_api_request_get_test(true,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,_account->password_mqtt,BAMBU_API_ENDPOINT_TASK,"application/json",HTTP_METHOD_POST,(uint8_t *)post_json_str, strlen(post_json_str),&result);

    PRINT_BAMBU_API("res_request=%d",(int)res_request);

    if ((res_request) || (!result))
    {
        res = res_request; 
        goto continue_print_err;
    } 
 
    result_json = cJSON_Parse(result);
    uint32_t history_id = 0;
    if (!json_is_Valid(result_json))
    {
        if (strlen(result) > 0)
        {
            res = RES_BAMBU_HTTP_RESPONSE_INVALID; 
        } 

        char *error = cJSON_GetStringValue(cJSON_GetObjectItem(result_json, "error")); 
        if (error)
        { 
            /*如果有错误信息则说明失败了*/
            res = -1;
            goto continue_print_err;
        } 
 
        history_id = cJSON_GetNumberValue(cJSON_GetObjectItem(result_json, "id")); 
        if (!history_id)
        { 
            /*如果没有返回ID则说明失败了*/
            res = -1;
            goto continue_print_err;
        }  
    }

    cJSON_Delete(continue_print); 
    cJSON_Delete(result_json); 
    if (post_json_str)
    {
        free(post_json_str);
    } 

    if (result)
    {
        free(result);
    }

    PRINT_BAMBU_API("start continue print by id:%ld",history_id);

    return 0;

    continue_print_err:
    if (continue_print)
    {
        cJSON_Delete(continue_print); 
    }
    
    if (result_json)
    {
        cJSON_Delete(result_json); 
    } 

    if (post_json_str)
    {
        free(post_json_str);
    }

    if (result)
    {
        free(result);
    } 
    
    return res;
}

int http_url_encode(const char* in_str, int in_len, char *out_str, int out_max_len) 
{
  int idx_out=0;
  for (int i = 0; i < in_len; i++) 
  {
    char c = in_str[i];
    if (idx_out >=out_max_len)
    {
        return -1;
    }
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '-' || c == '_' || c == '.' || c == '~') {
      out_str[idx_out++]= c;
    } else if (c == ' ') {
      out_str[idx_out++]= '+';
    } else {
      out_str[idx_out++]= '%';
      char hex[4];
      sprintf(hex, "%02X", (unsigned char)c);
      out_str[idx_out++]= hex;
    }
  }
  return idx_out;
}

typedef struct {
    bool need_cookies;
    uint8_t *buffer;
    uint32_t buffer_len;
} http_download_response_t;

static esp_err_t download_http_event_handler(esp_http_client_event_t *evt) 
{
    #if 0
    http_download_response_t *response = (http_download_response_t *)evt->user_data;
    
    switch (evt->event_id) 
    {       
        case HTTP_EVENT_ON_DATA:
            //PRINT_PWR_API("HTTP_EVENT_ON_DATA, len=%d", evt->data_len); 
            if (!response->need_cookies)
            {
                // Copy data to response buffer
                if (response->buffer == NULL) 
                {
                    response->buffer = (uint8_t *)s_esp_psram_malloc(evt->data_len + 1);
                    memset(response->buffer,0,evt->data_len + 1);
                    response->buffer_len = evt->data_len;
                } 
                else 
                {
                    response->buffer = (uint8_t *)s_esp_psram_realloc(response->buffer, response->buffer_len + evt->data_len + 1);
                    response->buffer_len += evt->data_len;
                }
                memcpy(response->buffer + response->buffer_len - evt->data_len, evt->data, evt->data_len);
                response->buffer[response->buffer_len] = 0; 
            }

            break;
        default:
        {
            break;
        } 

    }
    #endif
    return 0;
}

#define CONFIG_DOWNLOAD_TIMEOUT_MS (4000UL) 

static int8_t bambu_api_download(const char *host, const char *content_type, esp_http_client_method_t method, uint8_t *data, size_t len, uint8_t **out_result, uint32_t *out_len)
{ 
    int8_t res = -1; 
    int64_t start, test_duration=0;

    http_download_response_t response = {0}; 
    
    #if 0
    esp_http_client_config_t config = 
    {
        .url = host,
        .method = method,
        .timeout_ms = CONFIG_DOWNLOAD_TIMEOUT_MS,  
        .event_handler = download_http_event_handler,
        .user_data = &response,
    };
    
    start = esp_timer_get_time(); 
 
    esp_http_client_handle_t client = esp_http_client_init(&config);
    char *headers = NULL;

    asprintf(&headers, "%s", content_type);
 
    if (NULL == headers)
    {
        res=RES_BAMBU_HTTP_MALLOC_ERROR;
        PRINT_BAMBU_API("Failed to allocate headers!");
        goto end;
    }  

    esp_http_client_set_header(client, "Content-Type", headers);
    free(headers); 
      
    if (HTTP_METHOD_POST == method)
    { 
        if (len > 0)
        {
            esp_http_client_set_post_field(client,  (const char *)data, len);
        } 
    }
    
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) 
    {
        int status_code = esp_http_client_get_status_code(client); 
        res=RES_BAMBU_OK; 
 
        if (200 != status_code)
        {
            int content_length =  esp_http_client_get_content_length(client); 

            if ((content_length <=0)
                || (response.buffer_len <=0)
                || (response.buffer_len != content_length))
            {
                res=RES_BAMBU_HTTP_RESPONSE_INVALID;
                PRINT_BAMBU_API("HTTP_ERROR: buffer_len=%ld, length=%d", response.buffer_len, content_length);
            }
        }  
    } 
    else 
    {
        res=RES_BAMBU_HTTP_RESPONSE_INVALID;
        PRINT_BAMBU_API("HTTP request failed: %s", esp_err_to_name(err)); 
        PRINT_BAMBU_API("HTTP_ERROR: length=%ld", response.buffer_len); 
    } 

    if (RES_BAMBU_OK != res)
    {
        if (response.buffer)
        {
            free(response.buffer);
            response.buffer = NULL;
        }
    }

    *out_result = response.buffer;
    if (out_len)
    {
        *out_len = response.buffer_len;

        // PRINT_BAMBU_API("buffer start"); 

        // for (uint8_t i=0; i<response.buffer_len; i++)
        // {
        //     PRINT_BAMBU_API("%02x ", response.buffer[i]);
        // }

        // PRINT_BAMBU_API("buffer end"); 
    }

end:
    test_duration = esp_timer_get_time() - start;

    //PRINT_BAMBU_API("run takes %ld ms\n", (long int)(test_duration/1000));
 
    esp_http_client_close(client);
    esp_http_client_cleanup(client); 
    #endif
    
    return res;
}

bool bambu_api_title_is_same(const char *title_a, const char *title_b)
{
    if ((!title_a) || (!title_b))
    {
        return false;
    }

    uint8_t title_len_a = strlen(title_a);
    uint8_t title_len_b = strlen(title_b);

    if ((!title_len_a) || (!title_len_b))
    {
        return false;
    }

    bool different_length = false; 
    if (title_len_a>title_len_b)
    {
        //current:Wilson airless BIQU.STL.3mf history:Wilson airless BIQU.STL
        if ((title_len_a > 4) && (!strcasecmp(title_a + title_len_a - 4, ".3mf")))
        {
            PRINT_BAMBU_API("title a end with .3mf"); 
            different_length=true;

            if (!strncmp(title_b,title_a,title_len_a - 4))
            { 
                return true;
            } 
        }
    }
    else if (title_len_a<title_len_b)
    {
        //current:Wilson airless BIQU.STL history:Wilson airless BIQU.STL.3mf 
        if ((title_len_b > 4) && (!strcasecmp(title_b + title_len_b - 4, ".3mf")))
        {
            PRINT_BAMBU_API("title b end with .3mf"); 

            different_length=true;

            if (!strncmp(title_b,title_a,title_len_b - 4))
            { 
                return true;
            }
        } 
    }

    if (false == different_length)
    {
        if (!strcmp(title_b,title_a))
        { 
            return true;
        }
    }

    return false;
}

/*4 获取打印历史记录*/
int8_t bambu_api_get_print_history(bambu_account_info_t *_account, bambu_print_history_t *check_state, uint8_t **out_png_data, uint32_t *out_png_data_length)
{ 
    if (!check_state)
    {
        return RES_BAMBU_ERROR;
    } 

    if (!out_png_data)
    {
        return RES_BAMBU_ERROR;
    }

    if (!out_png_data_length)
    {
        return RES_BAMBU_ERROR;
    } 

    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }

    /*检查token*/
    /*不能为空*/
    if ((!_account->username_mqtt[0])
        || (!_account->password_mqtt[0]))
    {
        return RES_BAMBU_ERROR;
    }

    /*长度限制*/
    bool is_china = (REGION_CHINA == _account->nvs_config.region);
    int8_t res = RES_BAMBU_ERROR;
    char *result = NULL;
     
    //https://api.bambulab.cn/v1/user-service/my/tasks?limit=10&deviceId=01S00C3A1600394
    #define GET_HISTORY_END_POINT "%s?limit=%d&deviceId=%s"
 
    char *url_endpoint = s_esp_psram_malloc(1024);

    if (url_endpoint == NULL) 
    {
        printf("Failed to allocate memory for url_endpoint");
        return RES_BAMBU_HTTP_MALLOC_ERROR;
    }

    int limit_cnt=1;

    snprintf(url_endpoint, 1024, GET_HISTORY_END_POINT, BAMBU_API_ENDPOINT_TASKS, limit_cnt, check_state->deviceId);

    //PRINT_BAMBU_API("NEW url_endpoint: %s", url_endpoint);

    int8_t res_request = bambu_api_request_get_test(false,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,_account->password_mqtt,url_endpoint,"application/json",HTTP_METHOD_GET,NULL,NULL,&result);
    free(url_endpoint);

    cJSON *result_json =NULL;
    if ((res_request) || (!result))
    {
        res = res_request;
        goto get_history_err;
    }  

    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        goto get_history_err;
    } 
    
    /*解析总个数*/
    int total_cnt = cJSON_GetNumberValue(cJSON_GetObjectItem(result_json, "total")); 
    if ((!total_cnt) || (total_cnt<limit_cnt))
    { 
        res = RES_BAMBU_HISTORY_ERR_PARAMETER;
        goto get_history_err;
    }   
    
    /*获取数组*/
    cJSON *hits_array = cJSON_GetObjectItem(result_json, "hits");
    if (!cJSON_IsArray(hits_array))
    {
        res = RES_BAMBU_HISTORY_ERR_PARAMETER;  
        goto get_history_err;
    }

    int hits_array_cnt = cJSON_GetArraySize(hits_array);

    //PRINT_BAMBU_API("hits_array_cnt=[%02x]",hits_array_cnt); 

    if (hits_array_cnt != limit_cnt)
    {
        res = RES_BAMBU_HISTORY_ERR_PARAMETER;  
        goto get_history_err;
    }

    for (uint8_t i = 0; i < hits_array_cnt; ++i)
    {
        cJSON *get_task = cJSON_GetArrayItem(hits_array, i);
        if (!json_is_Valid(get_task))
        {
            PRINT_BAMBU_API("invaid get_task [%02x]",i);
            continue;
        }
        
        /*deviceId*/
        char *deviceId = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "deviceId")); 
        if (deviceId)
        {
            //PRINT_BAMBU_API("deviceId=[%s]",deviceId);
            if (strcmp(deviceId,check_state->deviceId))
            {
                /*设备ID相同才进行PNG数据获取*/
                PRINT_BAMBU_API("different device id"); 

                res = RES_BAMBU_HISTORY_DIFFERENT_DEVICE_ID;  
                goto get_history_err;
            }
        }   
    
        #if 0
        char *startTime = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "startTime")); 
        if (startTime)
        {
            PRINT_BAMBU_API("startTime=[%s]",startTime);

            if (!strcmp(startTime,check_state->start_print_time))
            {
                /*开始时间相同的则不更新*/
                res = RES_BAMBU_HISTORY_DIFFERENT_START_TIME;  
                goto get_history_err;
            }
            
            strlcpy(check_state->start_print_time,startTime,CONFIG_LENGTH_STR_START_TIME);
        } 
        #endif

        check_state->status = cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "status")); 

        /*填充model id等以支持从历史记录继续打印*/
        char *modelId = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "modelId"));
        if (modelId)
        {
            strlcpy(check_state->modelId,modelId,strlen(modelId)+1);
        }

        uint32_t profile_id_check = cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "profileId")); 
        
        check_state->plateIndex = (uint8_t)cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "plateIndex"));

        // check_state->cost_time_s = (uint32_t)cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "costTime"));

        // check_state->weight = (float)cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "weight"));
  
        char *title = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "title")); 
        if (title)
        {
            PRINT_BAMBU_API("title =[%s]",title); 

            /*如果包含后缀则不判断后缀*/  
            bool title_is_same = bambu_api_title_is_same(title,check_state->title);
            if (!title_is_same)
            {
                /*如果标题不一样，但是profile ID 一样时则认为任务相同*/
                bool is_same_profile_id = false;

                if (check_state->profileId>0)
                {
                    if (profile_id_check == check_state->profileId)
                    {
                        is_same_profile_id=true;
                        PRINT_BAMBU_API("different title but same profile id[%ld]",profile_id_check); 
                    }
                }

                if (!is_same_profile_id)
                {
                    res = RES_BAMBU_HISTORY_DIFFERENT_TITLE;  
                    goto get_history_err; 
                }  
            } 

            /*既然相同则保留标题*/
            //strlcpy(check_state->title,title,sizeof(check_state->title));
        }

        check_state->profileId = profile_id_check;

        char *cover = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "cover")); 
        if (cover)
        {
            //PRINT_BAMBU_API("cover link=[%s]",cover); 
            
            //vTaskDelay(pdMS_TO_TICKS(500));
            bambu_api_download(cover,"image/png",HTTP_METHOD_GET,NULL,0,out_png_data,out_png_data_length); 
            
            strlcpy(check_state->cover,cover,sizeof(check_state->cover));

            break;
        }   
    }     

    if (!check_state->title[0])
    {
        res = RES_BAMBU_HISTORY_DIFFERENT_TITLE;  
        
        goto get_history_err;
    }

    cJSON_Delete(result_json); 
    
    free(result); 

    return 0;

    get_history_err:

    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (result)
    {
        free(result);
    }
 
    return res;
}

int8_t bambu_api_get_print_history_file_list(bambu_account_info_t *_account, uint8_t limit_cnt, const char *device_id, bambu_print_history_t *out_history_file, uint32_t *file_count)
{
    if (!limit_cnt)
    {
        return RES_BAMBU_ERROR;
    } 

    if (!out_history_file)
    {
        return RES_BAMBU_ERROR;
    }  

    if (!_account)
    {
        return RES_BAMBU_ERROR;
    }

    /*检查token*/
    /*不能为空*/
    if ((!_account->username_mqtt[0])
        || (!_account->password_mqtt[0]))
    {
        return RES_BAMBU_ERROR;
    }

    /*长度限制*/
    bool is_china = (REGION_CHINA == _account->nvs_config.region);
    int8_t res = RES_BAMBU_ERROR;
    char *result = NULL;
     
    //https://api.bambulab.cn/v1/user-service/my/tasks?limit=10&deviceId=01S00C3A1600394
    #define GET_HISTORY_END_POINT "%s?limit=%d&deviceId=%s"
 
    char *url_endpoint = s_esp_psram_malloc(1024);

    if (url_endpoint == NULL) 
    {
        printf("Failed to allocate memory for url_endpoint");
        return RES_BAMBU_HTTP_MALLOC_ERROR;
    }

    snprintf(url_endpoint, 1024, GET_HISTORY_END_POINT, BAMBU_API_ENDPOINT_TASKS, (int)limit_cnt, device_id);

    PRINT_BAMBU_API("NEW url_endpoint: %s", url_endpoint);

    int8_t res_request = bambu_api_request_get_test(false,is_china?BAMBU_API_BASE_URL_CHINA:BAMBU_API_BASE_URL_OTHER,_account->password_mqtt,url_endpoint,"application/json",HTTP_METHOD_GET,NULL,NULL,&result);
    free(url_endpoint);

    cJSON *result_json =NULL;
    if ((res_request) || (!result))
    {
        res = res_request;
        goto get_history_err;
    } 

    PRINT_BAMBU_API("result:%s",result);

    result_json = cJSON_Parse(result);
    if (!json_is_Valid(result_json))
    {
        goto get_history_err;
    } 
    
    /*解析总个数*/
    int total_cnt = cJSON_GetNumberValue(cJSON_GetObjectItem(result_json, "total")); 
    if ((!total_cnt) || (total_cnt<limit_cnt))
    { 
        res = RES_BAMBU_HISTORY_ERR_PARAMETER;
        goto get_history_err;
    }   
    
    /*获取数组*/
    cJSON *hits_array = cJSON_GetObjectItem(result_json, "hits");
    if (!cJSON_IsArray(hits_array))
    {
        res = RES_BAMBU_HISTORY_ERR_PARAMETER;  
        goto get_history_err;
    }

    int hits_array_cnt = cJSON_GetArraySize(hits_array);

    PRINT_BAMBU_API("hits_array_cnt=[%02x]",hits_array_cnt); 

    if (hits_array_cnt > limit_cnt)
    {
        res = RES_BAMBU_HISTORY_ERR_INVALID_CNT;  
        goto get_history_err;
    }

    for (uint8_t i=0; i<hits_array_cnt; ++i)
    {
        cJSON *get_task = cJSON_GetArrayItem(hits_array, i);
        if (!json_is_Valid(get_task))
        {
            PRINT_BAMBU_API("invaid get_task [%02x]",i);
            continue;
        }
         
        char *title = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "title")); 
        if (title)
        {
            PRINT_BAMBU_API("title=[%s]",title);  

            strlcpy(out_history_file[i].title,title,sizeof(out_history_file[i].title));
        }

        char *modelId = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "modelId"));
        if (modelId)
        {
            strlcpy(out_history_file[i].modelId,modelId,strlen(modelId)+1);
        }

        out_history_file[i].profileId = cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "profileId")); 

        strlcpy(out_history_file[i].deviceId,device_id,MAX_LEN_SN);

        out_history_file[i].cost_time_s = (uint32_t)cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "costTime"));

        out_history_file[i].weight = (float)cJSON_GetNumberValue(cJSON_GetObjectItem(get_task, "weight"));
  
        char *cover = cJSON_GetStringValue(cJSON_GetObjectItem(get_task, "cover")); 
        if (cover)
        { 
            strlcpy(out_history_file[i].cover,cover,sizeof(out_history_file[i].cover));  
            #if CONFIG_HISTORY_USING_THUMBNAIL
            //vTaskDelay(pdMS_TO_TICKS(500));
            bambu_api_download(cover,"image/png",HTTP_METHOD_GET,NULL,0,&out_history_file[i].out_png_data,&out_history_file[i].out_png_data_length);  
            #endif
        }    
    }      

    cJSON_Delete(result_json); 
    
    free(result); 

    *file_count = hits_array_cnt;

    return 0;

    get_history_err:

    if (result_json)
    {
        cJSON_Delete(result_json); 
    }

    if (result)
    {
        free(result);
    }

    return res;
}
 
const int PING_SUCCEED = BIT0;
const int PING_TIMEOUT = BIT1;  
#if 0
static esp_ping_handle_t s_ping=NULL;  
static EventGroupHandle_t s_ping_event_group=NULL; 

static void ping_success(esp_ping_handle_t hdl, void *args)
{ 
    //PRINT_BAMBU_API("ping_success\r\n");
    xEventGroupSetBits(s_ping_event_group, PING_SUCCEED);
}

static void ping_timeout(esp_ping_handle_t hdl, void *args)
{
    //PRINT_BAMBU_API("ping_timeout\r\n");
    xEventGroupSetBits(s_ping_event_group, PING_TIMEOUT);
}

bool bambu_api_check_online(uint8_t is_china)
{
    uint64_t start = esp_timer_get_time();  
    #define PING_HOST_BAMBULAB   "www.bambulab.com"
    #define PING_HOST_BAIDU      "www.baidu.com" //           67ms
    #define PING_HOST_CLOUDFLARE "1.1.1.1"       //Cloudflare 300ms
    #define PING_HOST_ALI        "223.5.5.5"     //           16ms  
    #define PING_HOST_ALI_YUN    "www.aliyun.com"

    char *ping_address = is_china?PING_HOST_ALI_YUN:PING_HOST_BAMBULAB;
    esp_ping_config_t ping_config = ESP_PING_DEFAULT_CONFIG();
    ping_config.timeout_ms = PING_TIMEOUT_MS;  
    ip_addr_t target_addr;    
    memset(&target_addr, 0, sizeof(target_addr)); 
    #if 1
    struct addrinfo hint;
    struct addrinfo *res = NULL;
    memset(&hint, 0, sizeof(hint)); 
    /* convert URL to IP */
    if (0 != getaddrinfo(ping_address, NULL, &hint, &res))
    {
        printf("ping_address[%s] invalid",ping_address);
        return false;
    }  
    //PRINT_BAMBU_API("ping [%s]",ping_address); 
    struct in_addr addr4 = ((struct sockaddr_in *)(res->ai_addr))->sin_addr;
    inet_addr_to_ip4addr(ip_2_ip4(&target_addr), &addr4);
    freeaddrinfo(res);  
    #else   
    u32_t ip_u32 = esp_ip4addr_aton(PING_HOST_IP); 
    ip4_addr_set_u32(ip_2_ip4(&target_addr),ip_u32);   
    #endif 
    ping_config.target_addr = target_addr; 
    ping_config.count = 0; // ping in infinite mode

    /* set callback functions */
    esp_ping_callbacks_t cbs = {
        .cb_args = NULL,
        .on_ping_success = ping_success,
        .on_ping_timeout = ping_timeout,
        .on_ping_end = NULL
    };

    if (NULL == s_ping_event_group)
    {
        s_ping_event_group = xEventGroupCreate();
    } 
    xEventGroupClearBits(s_ping_event_group, PING_SUCCEED);
    xEventGroupClearBits(s_ping_event_group, PING_TIMEOUT);
    bool network_is_ok=false;
    esp_ping_new_session(&ping_config, &cbs, &s_ping);
    if (NULL == s_ping)
    {
        //PRINT_BAMBU_API("esp_ping_new_session failed\r\n");
        return false;
    }
    esp_ping_start(s_ping);  
    vTaskDelay(pdMS_TO_TICKS(200));
    //EventBits_t bits = xEventGroupWaitBits(s_ping_event_group, PING_SUCCEED | PING_TIMEOUT, pdFALSE, pdFALSE, portMAX_DELAY);
	EventBits_t bits = xEventGroupWaitBits(s_ping_event_group, PING_SUCCEED | PING_TIMEOUT, pdFALSE, pdFALSE, pdMS_TO_TICKS(1000));
    if (bits & PING_SUCCEED) 
    {
        xEventGroupClearBits(s_ping_event_group, PING_SUCCEED); 
        network_is_ok=true;
    }
    else// if (bits & PING_TIMEOUT) 
    {
        xEventGroupClearBits(s_ping_event_group, PING_TIMEOUT); 
        network_is_ok=false;
    }

    uint64_t test_duration = esp_timer_get_time() - start;

    //PRINT_BAMBU_API("ping run takes [%ld] ms\n", (long int)(test_duration/1000));

    esp_ping_stop(s_ping);  
    esp_ping_delete_session(s_ping);
    s_ping=NULL;  

    return network_is_ok;
}
#endif

bool bambu_api_is_valid_phone(const char *phone) 
{
    // 检查长度是否为11
    if (strlen(phone) != 11) {
        return false;
    }

    // 检查是否以1开头
    if (phone[0] != '1') {
        return false;
    }

    // 检查每个字符是否为数字
    for (int i = 1; i < 11; i++) 
    {
        int check_num = phone[i];
        if (!isdigit(check_num)) 
        {
            return false;
        }
    }

    return true;
}

bool bambu_api_is_valid_email(const char *email) 
{
    int at_index = -1;
    int dot_index = -1;
    int len = strlen(email);

    // 查找 '@' 和 '.' 的位置
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            at_index = i;
        } else if (email[i] == '.') {
            dot_index = i;
        }
    }

    // 检查 '@' 和 '.' 是否存在且顺序正确
    if (at_index == -1 || dot_index == -1 || at_index > dot_index) {
        return false;
    }

    // 检查 '@' 前后是否有内容
    if (at_index == 0 || at_index == len - 1) {
        return false;
    }

    // 检查 '.' 前后是否有内容
    if (dot_index == at_index + 1 || dot_index == len - 1) {
        return false;
    }

    return true;
}

void bambu_api_generate_rand(char *out_rand_str)
{
    #define CONFIG_LENGTH_RAND  11
    if (!out_rand_str)
    {
        return;
    }
    #if 0
    char a[27]="abcdefghijklmnopqrstuvwxyz";
    char name_rand[CONFIG_LENGTH_RAND+1]={0};
    
    int i,j;
    uint32_t id = 0;
    #if 0 
    get_chip_id(&id);
    #else
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    id=chip_info.model;
    #endif  
    uint32_t get_tick = esp_timer_get_time();
                
    uint32_t get_time = get_tick +id;
    
    srand(get_time);
    
    for(i=0;i<CONFIG_LENGTH_RAND;i++)
    {
        j= rand()%26;
        
        if ((a[j] >= 'a') && (a[j] <= 'z'))
        {
            a[j] = a[j]-32;
        }
        
        name_rand[i]=a[j];
    }
    
    name_rand[CONFIG_LENGTH_RAND] = '\0';
    
    sprintf(out_rand_str,"bbl_%s",name_rand);
    #endif
}

static void bambu_api_str_rand(char *out_rand_str)
{
    #define CONFIG_LENGTH_RAND_TEMP  6
    if (!out_rand_str)
    {
        return;
    }
    #if 0
    char a[27]="abcdefghijklmnopqrstuvwxyz";
    char name_rand[CONFIG_LENGTH_RAND_TEMP+1]={0};
    
    int i,j;
    uint32_t id = 0;
    #if 0 
    get_chip_id(&id);
    #else
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    id=chip_info.model;
    #endif  
    uint32_t get_tick = esp_timer_get_time();
                
    uint32_t get_time = get_tick +id;
    
    srand(get_time);
    
    for(i=0;i<CONFIG_LENGTH_RAND_TEMP;i++)
    {
        j= rand()%26;
        
        if ((a[j] >= 'a') && (a[j] <= 'z'))
        {
            a[j] = a[j]-32;
        }
        
        name_rand[i]=a[j];
    }
    
    name_rand[CONFIG_LENGTH_RAND] = '\0';
    
    sprintf(out_rand_str,"%s",name_rand);
    #endif
}

void bambu_api_generate_unique(uint8_t *mac_addr, char *out_str)
{ 
    if (!out_str)
    {
        return;
    } 

    char rand_id[7]={0};
    bambu_api_str_rand(rand_id);
    
    snprintf(out_str,MAX_LEN_CLIENT_ID,"bbl_%02x%02x%02x%02x%02x%02x_%s", mac_addr[5],mac_addr[4],mac_addr[3],mac_addr[2],mac_addr[1],mac_addr[0],rand_id);

    PRINT_BAMBU_API("out_str[%s]",out_str);
}

void bambu_api_generate_unique_fname(char *out_str)
{ 
    if (!out_str)
    {
        return;
    } 

    char rand_id[7]={0};
    bambu_api_str_rand(rand_id);
     
    snprintf(out_str,MAX_LEN_CLIENT_ID,"png_%s",rand_id);

    PRINT_BAMBU_API("out_str[%s]",out_str);
}