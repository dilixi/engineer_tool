#include "bambu_ftps.h"
#include "panda_touch.h"
//#include "esp_psram.h"
#include "utils_lib.h"
#include "lv_ui_overlay.h"
//#include "freertos/idf_additions.h"

static const char * TAG = "bambu_ftps"; 

#define SW_PRINT_FTPS 1

#if SW_PRINT_FTPS && SW_PRINT_ALL
//#include "esp_log.h"

#define PRINT_FTPS printf//ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_FTPS(...)
#endif

//#define ftps_debug_printf(format, args...)    PRINT_FTPS(format, ##args)
#define ftps_debug_printf(format, args...)    ((void)0)

const char *pers = "ftps_client";
#define FTPS_PORT "990"
#define FTPS_USER "bblp"

typedef struct {
    mbedtls_net_context server_fd;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf; 
} ftps_client_t;

ftps_client_t client_ctrl;

volatile bool refresh_by_change_master=false; 
static bambu_mqtt_t * bambu_mqtt_leader = NULL;
static volatile bool need_stop_ftps = false;

int8_t ftps_check_stop(void)
{
    #if 0
    uint32_t notifyValue=0;
    BaseType_t err = xTaskNotifyWait((uint32_t )  0x00,       
                        (uint32_t)   0x00,   
                        (uint32_t*)  &notifyValue, 
                        (TickType_t) 0  
                        );
    if(err == pdTRUE)
    { 
        if (NOTIFY_CODE_STOP_FTPS == notifyValue)
        {  
            PRINT_FTPS("NOTIFY_CODE_STOP_FTPS\r\n");

            return 1;
        } 
        if (NOTIFY_CODE_STOP_FTPS_BY_UPDATE_THUMBNAIL == notifyValue)
        {  
            need_stop_ftps=true;

            return 2;
        } 
    }
    #endif

    return 0;
}

void notify_to_ftps_task(uint32_t set_val)
{ 
    #if 0
    if (t_handle_ftps)
    { 
        /*notify exit lvgl task*/
        xTaskNotify((TaskHandle_t )  t_handle_ftps, //任务句柄，指明往哪个任务发送消息，很重要
                            (uint32_t )      set_val,    //发送的消息
                            (eNotifyAction)  eSetValueWithOverwrite  
                            ); 
    }  
    #endif
} 

int32_t ftps_ssl_write(mbedtls_ssl_context * p_ssl, const uint8_t * w_buffer, uint32_t len) {
    int ret = 0;
    while ((ret = mbedtls_ssl_write(p_ssl, w_buffer, len)) <= 0) { 
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            refresh_by_change_master= (1 == res_check)?true:false;
            PRINT_FTPS("ftps_ssl_write goto retry ");
            return FTPS_NOTIFY_STOP;
        }
        if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) {
            return -1;
        } 
    }
    //ftps_debug_printf("len: %ld, Send: \"%.*s\"\r\n", len, (int)len, w_buffer);
    return ret;
}

int32_t ftps_ssl_read(mbedtls_ssl_context * p_ssl, uint8_t * r_buffer, uint32_t max_len) {
    uint32_t total_len = 0;
    uint32_t remain_len = 0;
    do { 
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            refresh_by_change_master= (1 == res_check)?true:false;
            PRINT_FTPS("ftps_ssl_write goto retry ");
            return FTPS_NOTIFY_STOP;
        }

        int ret = mbedtls_ssl_read(p_ssl, r_buffer + total_len, max_len - total_len);
        if (ret == MBEDTLS_ERR_SSL_WANT_READ || ret == MBEDTLS_ERR_SSL_WANT_WRITE) {
            continue;
        }
        if (ret <= 0) {
            return -1;
        }
        total_len += ret;
        remain_len = mbedtls_ssl_get_bytes_avail(p_ssl);
    } while (remain_len && (total_len < max_len));
    //PRINT_FTPS("len: %ld, Recv: \"%.*s\"\r\n", total_len, (int)total_len, r_buffer);
    return total_len;
}

void ftps_client_free(ftps_client_t * ftps_client) {
    ftps_debug_printf("ftps_client_free\r\n");
    mbedtls_ssl_close_notify(&ftps_client->ssl);

    mbedtls_net_free(&ftps_client->server_fd);
    //mbedtls_ssl_session_reset(&ftps_client->ssl); // Repeated calls can cause crash and restart
    mbedtls_ssl_free(&ftps_client->ssl);
    mbedtls_ssl_config_free(&ftps_client->conf);

    mbedtls_ctr_drbg_free(&ftps_client->ctr_drbg);
    mbedtls_entropy_free(&ftps_client->entropy); 
}

bool ftps_client_connect_tcp(ftps_client_t * client, const char * ip, const char * port) {
    ftps_debug_printf("socket connect to: %s/%s\r\n", ip, port);

    mbedtls_net_init(&client->server_fd);

    if (mbedtls_net_connect(&client->server_fd, ip,
                            port, MBEDTLS_NET_PROTO_TCP) != 0) {
        mbedtls_net_free(&client->server_fd);
        return false;
    } 

    return true;
}

#include "mbedtls/timing.h"
static mbedtls_timing_delay_context context_timer;

bool ftps_client_connect_ssl(ftps_client_t * client, const char * ip, const char * port, ftps_client_t * reuse_client) {
    ftps_debug_printf("ftps_client_connect_ssl ssl connect to: %s/%s\r\n", ip, port);
    int ret = 0;
     
    mbedtls_ssl_init(&client->ssl);
    mbedtls_ssl_config_init(&client->conf);
    mbedtls_ctr_drbg_init(&client->ctr_drbg);
    mbedtls_entropy_init(&client->entropy);

    if (mbedtls_ctr_drbg_seed(&client->ctr_drbg, mbedtls_entropy_func, &client->entropy,
                              (const unsigned char *) pers,
                              strlen(pers)) != 0) 
    { 
        goto err_end;
    }

    if (mbedtls_ssl_config_defaults(&client->conf,
                                    MBEDTLS_SSL_IS_CLIENT,
                                    MBEDTLS_SSL_TRANSPORT_STREAM,
                                    MBEDTLS_SSL_PRESET_DEFAULT) != 0) 
    {  
        goto err_end;
    }

    mbedtls_ssl_conf_authmode(&client->conf, MBEDTLS_SSL_VERIFY_OPTIONAL);
    mbedtls_ssl_conf_rng(&client->conf, mbedtls_ctr_drbg_random, &client->ctr_drbg);

    if (mbedtls_ssl_setup(&client->ssl, &client->conf) != 0) 
    { 
        goto err_end;
    }

    if (mbedtls_ssl_set_hostname(&client->ssl, ip) != 0) 
    { 
        goto err_end;
    }

    if (reuse_client) {
        // session reuse
        mbedtls_ssl_session session;
        mbedtls_ssl_session_init(&session);
        mbedtls_ssl_get_session(&(reuse_client->ssl), &session);
        mbedtls_ssl_set_session(&client->ssl, &session);
        //PRINT_FTPS("session reuse\r\n");
    }
     
    #if 1
    mbedtls_ssl_conf_read_timeout(&client->conf, CONFIG_MBEDTLS_READ_TIMEOUT_MS); 
    mbedtls_ssl_set_bio(&client->ssl, &client->server_fd, mbedtls_net_send, mbedtls_net_recv, mbedtls_net_recv_timeout);
    mbedtls_ssl_set_timer_cb(&client->ssl, &context_timer, mbedtls_timing_set_delay,
                            mbedtls_timing_get_delay);
    #else
    mbedtls_ssl_set_bio(&client->ssl, &client->server_fd, mbedtls_net_send, mbedtls_net_recv, NULL);
    #endif

    //PRINT_FTPS("mbedtls_ssl_handshake bf");
    while ((ret = mbedtls_ssl_handshake(&client->ssl)) != 0) 
    {
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            refresh_by_change_master= (1 == res_check)?true:false;
            PRINT_FTPS("ftps_ssl_write goto retry ");
            goto err_end;
        }
        if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) 
        {
            PRINT_FTPS("mbedtls_ssl_handshake error=%d",ret);
            goto err_end;
        }
    }
    //PRINT_FTPS("mbedtls_ssl_handshake af");
    return true;
err_end:
    //ftps_debug_printf("ftps_client_connect_ssl err_end");
    ftps_client_free(client);
    return false;
}

bool ftps_client_connect_ssl_without_shake_hand(ftps_client_t * client, const char * ip, const char * port, ftps_client_t * reuse_client) {
    ftps_debug_printf("ssl connect to: %s/%s\r\n", ip, port);
    int ret = 0;
     
    mbedtls_ssl_init(&client->ssl);
    mbedtls_ssl_config_init(&client->conf);
    mbedtls_ctr_drbg_init(&client->ctr_drbg);
    mbedtls_entropy_init(&client->entropy);

    if (mbedtls_ctr_drbg_seed(&client->ctr_drbg, mbedtls_entropy_func, &client->entropy,
                              (const unsigned char *) pers,
                              strlen(pers)) != 0) {
        goto err_end;
    }

    if (mbedtls_ssl_config_defaults(&client->conf,
                                    MBEDTLS_SSL_IS_CLIENT,
                                    MBEDTLS_SSL_TRANSPORT_STREAM,
                                    MBEDTLS_SSL_PRESET_DEFAULT) != 0) {
        goto err_end;
    }

    mbedtls_ssl_conf_authmode(&client->conf, MBEDTLS_SSL_VERIFY_OPTIONAL);
    mbedtls_ssl_conf_rng(&client->conf, mbedtls_ctr_drbg_random, &client->ctr_drbg);

    if (mbedtls_ssl_setup(&client->ssl, &client->conf) != 0) {
        goto err_end;
    }

    if (mbedtls_ssl_set_hostname(&client->ssl, ip) != 0) {
        goto err_end;
    }

    if (reuse_client) {
        // session reuse
        mbedtls_ssl_session session;
        mbedtls_ssl_session_init(&session);
        mbedtls_ssl_get_session(&(reuse_client->ssl), &session);
        mbedtls_ssl_set_session(&client->ssl, &session);
        PRINT_FTPS("session reuse\r\n");
    }
    
    #if 1
    mbedtls_ssl_conf_read_timeout(&client->conf, CONFIG_MBEDTLS_READ_TIMEOUT_MS); 
    mbedtls_ssl_set_bio(&client->ssl, &client->server_fd, mbedtls_net_send, mbedtls_net_recv, mbedtls_net_recv_timeout);
    mbedtls_ssl_set_timer_cb(&client->ssl, &context_timer, mbedtls_timing_set_delay,
                            mbedtls_timing_get_delay);
    #else
    mbedtls_ssl_set_bio(&client->ssl, &client->server_fd, mbedtls_net_send, mbedtls_net_recv, NULL);
    #endif
 
    //PRINT_FTPS("mbedtls_ssl_handshake af");
    return true;
err_end:
    //ftps_debug_printf("ftps_client_connect_ssl err_end");
    ftps_client_free(client);
    return false;
}

bool ftps_client_connect(ftps_client_t * client, const char * ip, const char * port) {
    if (!ftps_client_connect_tcp(client, ip, port)) {
        return false;
    }
    return ftps_client_connect_ssl(client, ip, port, NULL);
}

bool ftps_send_cmd(ftps_client_t * ftps, const uint8_t * cmd) 
{
    /*这里需要检查一下，可能会崩溃，这里也要检查一下*/
    if (!cmd)
    {
        return true;
    }

    if (ftps_ssl_write(&ftps->ssl, cmd, strlen((char *)cmd)) < 0)
        return false;
    return true;
}

bool ftps_wait_response(ftps_client_t * ftps, uint8_t * r_buffer, size_t max_resp_len) {
    if (ftps_ssl_read(&ftps->ssl, r_buffer, max_resp_len) < 0)
        return false;
    if (r_buffer[0] == '4' || r_buffer[0] == '5')
    {  
        return false;
    }
        
    return true;
}

bool ftps_send_cmd_wait_response(ftps_client_t * ftps, const uint8_t * cmd, uint8_t * r_buffer, size_t max_resp_len) {
    if (!ftps_send_cmd(ftps, cmd)) {
        return false;
    }
    return ftps_wait_response(ftps, r_buffer, max_resp_len);
}

//TODO: Verification of more return codes
bool ftps_login_printer(ftps_client_t * ctrl, const char * user, const char * password) {
    ftps_debug_printf("ftps_login_printer\r\n");
    uint8_t w_buffer[64];
    uint8_t r_buffer[128];
    const char * cmds[] = {"PBSZ 0\r\n",        // 200
                           "SYST\r\n",          // 215 UNIX Type: L8 : NAME system type. 
                           //"OPTS UTF8 ON\r\n",  // 200 
                           "PWD\r\n",           // 257 / : "PATHNAME" created.
                           "PROT P\r\n",
                          }; 
    // wait for "220"
    if (!ftps_wait_response(ctrl, r_buffer, sizeof(r_buffer)))
        return false;

    // wait for "332" Need account for login.
    if (!ftps_send_cmd_wait_response(ctrl, (uint8_t *)"PBSZ 0\r\n", r_buffer, sizeof(r_buffer)))
        return false;

    // wait for "331" User name okay, need password.
    snprintf((char *)w_buffer, sizeof(w_buffer), "USER %s\r\n", user);
    if (!ftps_send_cmd_wait_response(ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        return false;

    // wait for "230" User logged in, proceed.
    snprintf((char *)w_buffer, sizeof(w_buffer), "PASS %s\r\n", password);
    if (!ftps_send_cmd_wait_response(ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        return false;

    // common cmd
    for (int i = 0; i < ARRAY_SIZE(cmds); i++) {
        if (!ftps_send_cmd_wait_response(ctrl, (uint8_t *)cmds[i], r_buffer, sizeof(r_buffer)))
            return false;       
    }

    return true;
}

bool ftps_passive_mode(ftps_client_t * ctrl, char * get_ip, char * get_port) {
    uint8_t r_buffer[128];
    // wait for "227 (192,168,x,x,x,xxx)" Entering Passive Mode
    if (!ftps_send_cmd_wait_response(ctrl, (uint8_t *)"PASV\r\n", r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("pasv failed [%s]\r\n",r_buffer);
        
        return false;
    }
         
    uint8_t data_client[6];
    char * str = strtok((char *)r_buffer, "(,");
    for (uint8_t i = 0; i < 6; i++) {
        str = strtok(NULL, "(,");
        if (!str)
            return false;
        data_client[i] = strtoul(str, NULL, 10);
    }

    sprintf(get_ip, "%d.%d.%d.%d", data_client[0], data_client[1], data_client[2], data_client[3]);
    sprintf(get_port, "%d", (data_client[4] << 8) | (data_client[5]));

    return true;
}

uint8_t * ftps_list_dir_malloc(ftps_client_t * client_ctrl, const char * dir, bool reuse_session) 
{
    uint8_t w_buffer[64];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;

    if (!ftps_passive_mode(client_ctrl, ip_data, port_data))
    {
        PRINT_FTPS("ftps_passive_mode failed");
        return NULL;
    }
        
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
    {
        PRINT_FTPS("ftps_client_connect_tcp failed");
        return NULL;
    } 

    uint8_t retry_cnt = 0;

    try_again:
    // wait for "150" of "LIST xx" cmd
    snprintf((char *)w_buffer, sizeof(w_buffer), "LIST %s\r\n", dir);
    if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("LIST [%s] failed", dir);

        if (retry_cnt<1)
        {
            retry_cnt++;

            /*创建一个cache文件夹*/
            snprintf((char *)w_buffer, sizeof(w_buffer), "MKD %s\r\n", dir);
            if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
            { 
                PRINT_FTPS("mkdir [%s] error[%s]",dir, r_buffer); 

                return NULL; 
            } 

            goto try_again;
        }
        else
        {
            return NULL;
        } 
    }
        
    if (!ftps_client_connect_ssl(&client_data, ip_data, port_data, reuse_session?client_ctrl:NULL)) {
        ftps_debug_printf("client_data error\r\n");
        PRINT_FTPS("client_data error LIST dir[%s] error reuse_session=%02x",dir,reuse_session);
        return NULL;
    }

    // wait for list of dir
    #define F_BUFFER_BASE_SIZE (4096)
    uint32_t total_len = 0;
    int32_t ret = 0;
    uint8_t * f_buffer = (uint8_t *)esp_psram_malloc(F_BUFFER_BASE_SIZE);
    if (f_buffer == NULL)
    {
        PRINT_FTPS("esp_psram_malloc error");
        goto err_end;
    } 
    do {
        uint8_t * t_buffer = (uint8_t *)esp_psram_realloc((void *)f_buffer, F_BUFFER_BASE_SIZE + total_len);
        if (t_buffer == NULL) 
        {
            PRINT_FTPS("esp_psram_realloc error");
            goto err_end;
        }
        f_buffer = t_buffer;
        ret = ftps_ssl_read(&client_data.ssl, f_buffer + total_len, F_BUFFER_BASE_SIZE);
        if (ret <= 0) { 
            break;
        }        
        total_len += ret;
        //PRINT_FTPS("list total: %ld, ret:%ld\r\n", total_len, ret);
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            refresh_by_change_master= (1 == res_check)?true:false;
            PRINT_FTPS("ftps_ssl_write goto retry ");
            return NULL;
        }
    } while (1);
    f_buffer[total_len] = 0;

    ftps_client_free(&client_data);
    
    // wait for "226"
    //PRINT_FTPS("ftps_wait_response bf");
    if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) 
    {
        PRINT_FTPS("ftps_wait_response 226 error");
        if (!reuse_session)
        {
            refresh_by_change_master=true;
            PRINT_FTPS("tps_wait_response 226 error goto retry ");
        }

        goto err_end;
    } 

    return f_buffer;

err_end:
    if (f_buffer) {
        free(f_buffer);
        f_buffer = NULL;
    }
    return NULL;
}

uint8_t * ftps_list_dir_current_malloc(ftps_client_t * client_ctrl) {
    uint8_t w_buffer[64];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;
    int ret = 0;
    #define F_BUFFER_BASE_SIZE (4096)
    uint32_t total_len = 0; 
    uint8_t * f_buffer = NULL;
  
    // PRINT_FTPS("PROT P:[%s]",r_buffer);

    if (!ftps_passive_mode(client_ctrl, ip_data, port_data))
    {
        PRINT_FTPS("ftps_passive_mode failed");
        return NULL;
    } 
  
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
    {
        PRINT_FTPS("ftps_client_connect_tcp failed");
        return NULL;
    } 
   
    // wait for "150" of "LIST xx" cmd
    snprintf((char *)w_buffer, sizeof(w_buffer), "LIST -al\r\n");
    if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("ftps_send_cmd_wait_response failed");
        return NULL; 
    }
      
    if (!ftps_client_connect_ssl_without_shake_hand(&client_data, ip_data, port_data, client_ctrl)) {
        ftps_debug_printf("client_data error\r\n");
        PRINT_FTPS("client_data error");
        return NULL;
    } 

    while ((ret = mbedtls_ssl_handshake(&client_data.ssl)) != 0) 
    {
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            refresh_by_change_master= (1 == res_check)?true:false; 
            goto err_end;
        } 

        if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) 
        {
            PRINT_FTPS("mbedtls_ssl_handshake error ret=%d\r\n",ret);
            if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) 
            {
                PRINT_FTPS("ftps_wait_response 226 error [%s]",r_buffer); 
                //if (r_buffer)
                //goto err_end;
                if (r_buffer[0] == '1')
                {
                    PRINT_FTPS("ftps_wait_response break");

                    break;
                } 
            }  
        }
    } 

    // wait for list of dir
    #define F_BUFFER_BASE_SIZE (4096) 
    f_buffer = (uint8_t *)esp_psram_malloc(F_BUFFER_BASE_SIZE);
    if (f_buffer == NULL)
    {
        PRINT_FTPS("esp_psram_malloc error");
        goto err_end;
    }  
    do {
        uint8_t * t_buffer = (uint8_t *)esp_psram_realloc((void *)f_buffer, F_BUFFER_BASE_SIZE + total_len);
        if (t_buffer == NULL) 
        {
            PRINT_FTPS("esp_psram_realloc error");
            goto err_end;
        }
        f_buffer = t_buffer;
        ret = ftps_ssl_read(&client_data.ssl, f_buffer + total_len, F_BUFFER_BASE_SIZE);
        if (ret <= 0) { 
            break;
        }        
        total_len += ret;
        //PRINT_FTPS("list total: %ld, ret:%ld\r\n", total_len, ret); 
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            refresh_by_change_master= (1 == res_check)?true:false; 
            return NULL;
        } 
    } while (1);
    f_buffer[total_len] = 0;

    ftps_client_free(&client_data);
    
    // wait for "226"
    //PRINT_FTPS("ftps_wait_response bf");
    if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) 
    {
        //PRINT_FTPS("ftps_wait_response 226 error");
        refresh_by_change_master=true;
        PRINT_FTPS("ftps_list_dir_current_malloc ftps_wait_response 226 error goto need_retry");
        goto err_end;
    } 

    return f_buffer;

err_end:
    if (f_buffer) {
        free(f_buffer);
        f_buffer = NULL;
    }
    return NULL;
}

//#include <esp_vfs_fat.h>

static ftps_upload_info_t ftps_upload_info;

ftps_upload_info_t * ftps_get_upload_info(void) {
    return &ftps_upload_info;
}

void ftps_upload_print_require(ftps_status_t status, const char * file_path, const char * filename) { 
    if (file_path)
    {
        ftps_upload_info.file_path = file_path;
    }
    
    if (filename)
    {
        ftps_upload_info.filename = filename;
    }
    
    ftps_upload_info.ftps_status = status;

    PRINT_FTPS("upload file_path[%s] filename[%s]",ftps_upload_info.file_path, ftps_upload_info.filename);
}

ftps_status_t ftps_upload(ftps_client_t * client_ctrl, ftps_upload_info_t * p_info) { 
    // files_max_len set to 4096 is the best speed, may be due to the sector size of FATFS is 4096 .
    uint8_t w_buffer[4096];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;
    ftps_status_t status = FTPS_OK;

    #if 0

    if (NULL == p_info->file_path)
    {
        PRINT_FTPS("invalid upload file path");

        return FTPS_ERR;
    }

    if (NULL == p_info->filename)
    {
        PRINT_FTPS("invalid upload file name");

        return FTPS_ERR;
    }

    if (!ftps_passive_mode(client_ctrl, ip_data, port_data))
        return FTPS_ERR;
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
        return FTPS_ERR;

    //snprintf((char *)w_buffer, sizeof(w_buffer), "STOR %s%s\r\n", CONFIG_3MF_THUMBNAIL_PATH, fname);

    // wait for "150" of "STOR xx" cmd
    //snprintf((char *)w_buffer, sizeof(w_buffer), "STOR %s\r\n", p_info->filename);
    snprintf((char *)w_buffer, sizeof(w_buffer), "STOR %s%s\r\n", p_info->file_path, p_info->filename);

    PRINT_FTPS("start upload [%s]",w_buffer);  

    if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        return FTPS_ERR;
    if (!ftps_client_connect_ssl(&client_data, ip_data, port_data, client_ctrl)) {
        ftps_debug_printf("client_data connect_ssl error\r\n");
        return FTPS_ERR;
    }

    ftps_debug_printf("\r\n----Upload:-----\r\n");
    p_info->size_cur = 0;
    p_info->size_total = 0;
    FIL file;
    UINT br;
    char file_name[512+4]={0};

    /*从当前选择的U盘目录获取文件*/
    sprintf(file_name,"%s%s",usb_3mf_list->current_path,p_info->filename); 
    if (f_open(&file, file_name, FA_OPEN_EXISTING | FA_READ) == FR_OK) {    
        p_info->size_total = f_size(&file); 
        while (!f_eof(&file)) {
            if (p_info->ftps_status == FTPS_UPLOAD_ABORT) {
                status = FTPS_UPLOAD_ABORT;
                break;
            } 
            if(f_read(&file, w_buffer, sizeof(w_buffer), &br) != FR_OK) {
                status = FTPS_ERR;
                break;
            }
            int32_t s = ftps_ssl_write(&client_data.ssl, w_buffer, br);
            if (s != br) {
                ftps_debug_printf("ERR: ftps_ssl_write: s: %ld, br: %d\r\n", s, br);
                status = FTPS_ERR;
                break;
            }
            p_info->size_cur += br;
            ftps_debug_printf("Total: %ld, br:%d\r\n", p_info->size_cur, br);
        }
        f_close(&file);
    } else {
        if (p_info->ftps_status == FTPS_UPLOAD_ABORT) {
            status = FTPS_UPLOAD_ABORT;
        } else {
            status = FTPS_ERR;
        }
    } 
    ftps_client_free(&client_data);

    // wait for "226"
    if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) {
        return FTPS_ERR;
    }
    #endif

    return status;
}

ftps_status_t ftps_upload_thumbnail(ftps_client_t * client_ctrl, ftps_upload_info_t * p_info, bool is_x1, const char *fname) 
{
    // files_max_len set to 4096 is the best speed, may be due to the sector size of FATFS is 4096 .
    #define DATA_LENGTH_WRITE 4096

    uint8_t w_buffer[DATA_LENGTH_WRITE];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;
    ftps_status_t status = FTPS_OK;

    if (!ftps_passive_mode(client_ctrl, ip_data, port_data))
        return FTPS_ERR;
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
        return FTPS_ERR;
     
    // 创建image目录
    if (is_x1)
    {
        snprintf((char *)w_buffer, sizeof(w_buffer), "MKD %s\r\n", CONFIG_3MF_THUMBNAIL_PATH);
        if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        { 
            PRINT_FTPS("mkdir [%s] error[%s]",CONFIG_3MF_THUMBNAIL_PATH, r_buffer);
            //return FTPS_ERR;
        }
    } 

    // wait for "150" of "STOR xx" cmd
    snprintf((char *)w_buffer, sizeof(w_buffer), "STOR %s%s\r\n", CONFIG_3MF_THUMBNAIL_PATH, fname);
    if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        return FTPS_ERR;
    if (!ftps_client_connect_ssl(&client_data, ip_data, port_data, client_ctrl)) {
        ftps_debug_printf("client_data connect_ssl error\r\n");
        return FTPS_ERR;
    }
 
    PRINT_FTPS("Upload file [%s]",w_buffer);

    uint8_t *png_data = NULL;
    uint32_t png_data_length = 0;
    uint32_t data_offset = 0;
    uint32_t data_left = 0;

    /*遍历查找文件*/
    if (!usb_3mf_list->is_inserted)
    {
        PRINT_FTPS("not find u-disk");
        goto upload_end;
    }
    #if 0
    for (uint8_t idx=0; idx<usb_3mf_list->file_3mf_count; idx++)
    {
        /*找到相同文件名下的PNG图片数据*/
        if (!strcmp(usb_3mf_list->files[idx].name,p_info->filename))
        {
            png_data = usb_3mf_list->files[idx].png_file_data;
            png_data_length = usb_3mf_list->files[idx].png_data_length;
            break;
        }
    }
    #else
    for (uint8_t idx=0; idx<usb_3mf_list->file_3mf_count; idx++)
    {
        /*找到相同文件名下的PNG图片数据*/
        if (!strcmp(usb_3mf_list->files[idx].name,p_info->filename))
        {
            png_data = (uint8_t *)usb_3mf_list->files[idx].img_data.data;
            png_data_length = usb_3mf_list->files[idx].img_data.data_size;
            break;
        }
    }
    #endif

    if ((0 == png_data_length) || (!png_data))
    {
        PRINT_FTPS("not find 3mf file png data");

        goto upload_end;
    }

    data_left = png_data_length;

    while (data_left>0) 
    {
        if (p_info->ftps_status == FTPS_UPLOAD_ABORT) {
            status = FTPS_UPLOAD_ABORT;
            break;
        } 

        uint32_t current_data_length = DATA_LENGTH_WRITE;

        if (data_left <= DATA_LENGTH_WRITE)
        {
            current_data_length = data_left;
        }

        memcpy(w_buffer,&png_data[data_offset],current_data_length);
         
        int32_t s = ftps_ssl_write(&client_data.ssl, w_buffer, current_data_length);
        if (s != current_data_length) 
        {
            ftps_debug_printf("ERR: ftps_ssl_write: s: %ld, br: %d\r\n", s, current_data_length);
            status = FTPS_ERR;
            goto upload_end;
        }

        data_left -= current_data_length;  
        data_offset += current_data_length;
        //ftps_debug_printf("Total: %ld, br:%d\r\n", p_info->size_cur, br);
    } 

    PRINT_FTPS("upload find 3mf png ok");

    upload_end:
    
    ftps_client_free(&client_data);

    // wait for "226"
    if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) {
        return FTPS_ERR;
    }

    return status;
}

ftps_status_t ftps_upload_thumbnail_from_panda_touch(ftps_client_t * client_ctrl, uint8_t *u16_img_data, uint32_t data_length, bool is_x1, const char *fname) 
{
    // files_max_len set to 4096 is the best speed, may be due to the sector size of FATFS is 4096 .
    #define DATA_LENGTH_WRITE 4096

    uint8_t w_buffer[DATA_LENGTH_WRITE];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;
    ftps_status_t status = FTPS_OK;

    if ((0 == data_length) || (!u16_img_data))
    {
        PRINT_FTPS("not find 3mf file png data data_length=%ld, u16_img_data=%x",data_length,u16_img_data);

        return FTPS_ERR;
    }

    if (!ftps_passive_mode(client_ctrl, ip_data, port_data))
        return FTPS_ERR;
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
        return FTPS_ERR;
     
    // X1需要创建image目录
    if (is_x1)
    {
        snprintf((char *)w_buffer, sizeof(w_buffer), "MKD %s\r\n", CONFIG_3MF_THUMBNAIL_PATH);
        if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        { 
            PRINT_FTPS("mkdir [%s] error[%s]",CONFIG_3MF_THUMBNAIL_PATH, r_buffer);
            //return FTPS_ERR;
        }
    } 

    // wait for "150" of "STOR xx" cmd
    snprintf((char *)w_buffer, sizeof(w_buffer), "STOR %s%s\r\n", CONFIG_3MF_THUMBNAIL_PATH, fname);
    if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        return FTPS_ERR;
    if (!ftps_client_connect_ssl(&client_data, ip_data, port_data, client_ctrl)) {
        ftps_debug_printf("client_data connect_ssl error\r\n");
        return FTPS_ERR;
    }
 
    PRINT_FTPS("Upload file [%s]",w_buffer);

    uint32_t data_offset = 0;
    uint32_t data_left = 0;  

    data_left = data_length;

    while (data_left>0) 
    {
        uint32_t current_data_length = DATA_LENGTH_WRITE;

        if (data_left <= DATA_LENGTH_WRITE)
        {
            current_data_length = data_left;
        }

        memcpy(w_buffer,&u16_img_data[data_offset],current_data_length);
         
        int32_t s = ftps_ssl_write(&client_data.ssl, w_buffer, current_data_length);
        if (s != current_data_length) 
        {
            ftps_debug_printf("ERR: ftps_ssl_write: s: %ld, br: %d\r\n", s, current_data_length);
            status = FTPS_ERR;
            goto upload_end;
        }

        data_left -= current_data_length;  
        data_offset += current_data_length;
        //ftps_debug_printf("Total: %ld, br:%d\r\n", p_info->size_cur, br);
    } 

    PRINT_FTPS("upload find 3mf u16 img ok");

    upload_end:
    
    ftps_client_free(&client_data);

    // wait for "226"
    if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) {
        return FTPS_ERR;
    }

    return status;
}

void strcpy_delimiter(char* dst, const char* src, const char delimiter) {
    while (src) {
        if (*src == delimiter)
            break;
        *dst++ = *src++;
    }
    *dst = 0;
}

uint8_t month_str_to_num(const char* src) {
    const char* table[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (uint8_t i = 0; i < ARRAY_SIZE(table); i++) {
        if (strcmp(src, table[i]) == 0)
            return i + 1;
    }
    return 0;
}

bool ftps_parse_one_line(file_list_3mf_t *p_3mf_list, file_gcode_t *dst, const char* one_line, bool check_png) {
    char buf[24];
    char* hour_delimiter = NULL;
    char* src = (char*)one_line;
    bool is_dir = (one_line[0] == 'd');   

    for (uint8_t i = 0; i < 8; i++) {
        while (*src != ' ') {
            if (*src == 0)
                goto err_end;
            src++;
        }
        while (*src == ' ') {
            if (*src == 0)
                goto err_end;
            src++;
        }
        switch (i) {
            case 3: // size
                dst->size = strtoul(src, NULL, 10);
                // Ignoring empty files
                if (dst->size == 0) {
                    if (!is_dir)
                    {
                        goto err_end;
                    } 
                }
                break;
            case 4: // month
                strcpy_delimiter(buf, src, ' ');
                dst->time.month = month_str_to_num(buf);
                break;
            case 5: // day
                dst->time.day = (uint8_t)strtoul(src, NULL, 10);
                break;
            case 6: // year or hour:min
                strcpy_delimiter(buf, src, ' ');
                hour_delimiter = strchr(buf, ':');
                if (hour_delimiter) {
                    dst->time.hour = (uint8_t)strtoul(src, NULL, 10);
                    dst->time.min = (uint8_t)strtoul(hour_delimiter + 1, NULL, 10);
                    dst->time.year = 0;
                }
                else {
                    dst->time.hour = 0;
                    dst->time.min = 0;
                    dst->time.year = (uint16_t)strtoul(src, NULL, 10);
                }
                break;
            case 7: // name
                uint32_t len = strlen(src);
                dst->name = (char *)esp_psram_malloc(len + 1);
                if (dst->name) 
                {
                    strlcpy(dst->name, src, len + 1);
                    // files starting with '.' on macos mean hidden files

                    if (dst->name[0] == '.')
                        goto err_end;

                    if (check_png)
                    { 
                        // if (len > 4 && (!strcasecmp(dst->name + len - 4, ".png")))
                        // {
                        //     dst->type = FILE_TYPE_PNG;
                        // }
                        if (FILE_TYPE_DIR == dst->type)
                        {
                            goto err_end;
                        }
                    }
                    else
                    { 
                        if (len <= 4 || strcasecmp(dst->name + len - 4, ".3mf") != 0)
                        { 
                            if (!is_dir)
                            {
                                goto err_end;
                            }
                            else
                            {
                                dst->type = FILE_TYPE_DIR;
                            }  
                        }
                        else
                        {  
                            dst->type = FILE_TYPE_3MF;
                            if (p_3mf_list) 
                            {
                                p_3mf_list->file_3mf_count++;
                            } 
                        }   
                    }  
                } 
                else 
                {
                    goto err_end;
                }
                break;
        }
    }
    dst->timestamp = ftime_2_timestamp(dst->time); 
    return true;
err_end:
    if (dst->name) {
        free(dst->name);
        dst->name = NULL;
    }
    return false;
}
 
uint32_t ftps_parse_file(file_list_3mf_t *p_3mf_list, file_gcode_t *files, char* src, uint32_t max_file_num, bool check_png) {
    char one_line[1024];
    uint32_t i = 0;
    const char* delimiter = "\r\n"; 
    char* line = strtok(src, delimiter);
    file_gcode_t *dst = files;

    if (p_3mf_list)
    {
        dst = p_3mf_list->files;
        //file_3mf_list_free(dst, max_file_num);
        p_3mf_list->file_3mf_count=0;
    }
    
    while (line != NULL && (i < max_file_num)) {
        strlcpy(one_line, line, sizeof(one_line));
        if (ftps_parse_one_line(p_3mf_list, dst + i, one_line,  check_png))
            i++;

        line = strtok(NULL, delimiter);
    }
    return i;
}   
#define BUFFER_SIZE 4096

// PNG header and end marker
const unsigned char png_header[] = "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A";
const unsigned char png_end_marker[] = "\x49\x45\x4E\x44\xAE\x42\x60\x82";
const size_t png_header_len = sizeof(png_header) - 1;
const size_t png_end_marker_len = sizeof(png_end_marker) - 1;

// Function to find the position of a tag in the buffer
long find_tag_position(const unsigned char *buffer, long size, const unsigned char *tag, size_t tag_len) {
    for (long i = 0; i <= size - tag_len; ++i) {
        if (memcmp(buffer + i, tag, tag_len) == 0) {
            return i + tag_len;
        }
    }
    return -1;
}

// Function to find the position of the PNG header in the buffer
long find_png_position(const unsigned char *buffer, long size, long start_pos) {
    for (long i = start_pos; i <= size - png_header_len; ++i) {
        if (memcmp(buffer + i, png_header, png_header_len) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to calculate the length of the PNG file by finding the end marker
long calculate_png_length(const unsigned char *buffer, long size, long start_pos) {
    for (long i = start_pos; i <= size - png_end_marker_len; ++i) {
        if (memcmp(buffer + i, png_end_marker, png_end_marker_len) == 0) {
            return i + png_end_marker_len - start_pos;
        }
    }
    return -1;
}

int download_png_thumbnail_via_ftps(ftps_client_t *client, file_gcode_t *file_entry) 
{
    int res=-1; 
    nvs_config_t * nvs = &bambu_mqtt_leader->nvs_config;
    bool is_x1 = (BAMBU_MODEL_X1 == nvs->model_num); 

    uint8_t buffer[BUFFER_SIZE];
    size_t bytes_read; 
    const unsigned char tag[] = "Metadata/plate_1.png";
    const size_t tag_len = sizeof(tag) - 1;
    long file_offset = 0;
    long tag_pos = -1;
    long png_pos = -1; 

    uint8_t *buffer_png_data = NULL;
    uint32_t size_png_data = 0;

    unsigned int png_width;
    unsigned int png_height; 
    unsigned error = 0;
    
    uint8_t w_buffer[512];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;  
    //uint8_t *img_data = NULL;   
    uint8_t *u16_img_data = NULL;
    int8_t res_decode = NULL;

    buffer_png_data = (uint8_t *)esp_psram_malloc(BUFFER_SIZE);
    if (!buffer_png_data)
    {
        return res;
    }

    if (!ftps_passive_mode(client, ip_data, port_data))
    {
        PRINT_FTPS("ftps_passive_mode failed\r\n");
        return res;
    }
        
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
    {
        PRINT_FTPS("ftps_client_connect_tcp failedr\n");
        return res;
    } 

    //PRINT_FTPS("ip_data=%s,port_data=%s\r\n",ip_data,port_data);
    
    snprintf((char *)w_buffer, sizeof(w_buffer), "RETR %s%s\r\n", printer_3mf_list->current_path, file_entry->name); 
    if (!ftps_send_cmd_wait_response(client, w_buffer, r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("ftps_download failed with[%s] r_buffer[%s]\r\n",file_entry->name, r_buffer);
        return res; 
    } 
 
    if (!ftps_client_connect_ssl(&client_data, ip_data, port_data, is_x1?client:NULL)) {
        ftps_debug_printf("client_data error\r\n"); 
        return res;
    } 

    PRINT_FTPS("start download with[%s]\r\n",file_entry->name);
     
// 1. Search for the Metadata/plate_1_small.png tag and PNG header in the .3mf file.
    while (1) {
        int bytes_read = ftps_ssl_read(&client_data.ssl, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            PRINT_FTPS("Read error or end of file reached\n");
            break;
        }

        // Find the tag if not found yet
        if (tag_pos == -1) {
            tag_pos = find_tag_position(buffer, bytes_read, tag, tag_len);
            if (tag_pos != -1) 
            {
                tag_pos += file_offset;
            }
        }

        // Find PNG header position if tag found
        if (tag_pos != -1 && png_pos == -1) {
            long local_png_pos = find_png_position(buffer, bytes_read, (tag_pos > file_offset) ? tag_pos - file_offset : 0);
            if (local_png_pos != -1) {
                png_pos = local_png_pos + file_offset; 
 
                uint32_t png_valid_size = bytes_read-local_png_pos; 

                memcpy(buffer_png_data,&buffer[local_png_pos],png_valid_size);

                size_png_data = png_valid_size;
                break;
            }
        }

        file_offset += bytes_read;  
    }
 
    if (png_pos != -1) 
    { 
        // 2. Seek to PNG header position and start reading PNG data until the end marker is found.
        file_offset = png_pos;  
        while (1) 
        { 
            int bytes_read = ftps_ssl_read(&client_data.ssl, buffer, BUFFER_SIZE);

            if (bytes_read <= 0) {
                PRINT_FTPS("Read error or end of file reached\n");
                break;
            }

            long local_end_pos = calculate_png_length(buffer, bytes_read, 0);

            long data_len_read = bytes_read;

            if (local_end_pos != -1)
            {
                data_len_read=local_end_pos;
            }
    
            buffer_png_data = (uint8_t *)esp_psram_realloc(buffer_png_data, size_png_data + data_len_read + 1);
            size_png_data += data_len_read; 

            memcpy(buffer_png_data + size_png_data - data_len_read, buffer, data_len_read);

            if (local_end_pos != -1) 
            {  
                break;
            } 
        } 
    } 

    PRINT_FTPS("ABOR TRANSLATE\r\n"); 

    #if 1
    if (!ftps_send_cmd_wait_response(client, (uint8_t *)"ABOR\r\n", r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("ABOR failed with[%s] r_buffer[%s]\r\n",file_entry->name, r_buffer); 
    } 

    ftps_client_free(&client_data);  
 
    if (!ftps_send_cmd_wait_response(client, (uint8_t *)"QUIT\r\n", r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("QUIT failed with[%s] r_buffer[%s]\r\n",file_entry->name, r_buffer); 
    } 
    #else

    if (!ftps_send_cmd_wait_response(client, (uint8_t *)"QUIT\r\n", r_buffer, sizeof(r_buffer)))
    {
        PRINT_FTPS("QUIT failed with[%s] r_buffer[%s]\r\n",file_entry->name, r_buffer); 
    } 

    ftps_client_free(&client_data);
    #endif

    if (file_entry->png_file_data)
    {
        free(file_entry->png_file_data);  /*Free the loaded file*/
        file_entry->png_file_data=NULL;
    }
  
    if (!buffer_png_data)
    {
        goto err_end;
    }

    file_entry->png_file_data = buffer_png_data;
    
    png_width = CONFIG_3MF_THUMBNAIL_WIDTH;       
    png_height = CONFIG_3MF_THUMBNAIL_HEIGHT;   

    u16_img_data = (uint8_t *)esp_psram_malloc(CONFIG_3MF_PREVIEW_DATA_SIZE);
    if (!u16_img_data)
    { 
        PRINT_FTPS("u16_img_data malloc error");
        goto err_end;
    }
    res_decode = png_decoder_and_resize(file_entry->png_file_data, size_png_data, png_width, png_height, u16_img_data, CONFIG_3MF_THUMBNAIL_BG_COLOR);
    if (0 != res_decode)
    { 
        goto err_end;
    }
    
    file_entry->png_file_data=NULL;
    file_entry->img_data.header.w=CONFIG_3MF_THUMBNAIL_WIDTH;
    file_entry->img_data.header.h=CONFIG_3MF_THUMBNAIL_HEIGHT; 
    file_entry->img_data.header.cf=LV_IMG_CF_TRUE_COLOR; 
    file_entry->img_data.data_size = CONFIG_3MF_PREVIEW_DATA_SIZE; 
    file_entry->img_data.data=u16_img_data; 
    PRINT_FTPS("download thumbnail ok with[%s]\r\n", file_entry->name);

    res=0;

    err_end: 

    if (buffer_png_data)
    {
        free(buffer_png_data);
    } 

    PRINT_FTPS("res=%d\n",res); 
    
    return res;
}

static file_gcode_t *img_files = NULL;

uint8_t *ftps_download(ftps_client_t * client_ctrl, const char * filename, bool is_x1) {
    uint8_t w_buffer[256];
    uint8_t r_buffer[128]; 
    char ip_data[32];
    char port_data[16];
    ftps_client_t client_data;  

    if (!ftps_passive_mode(client_ctrl, ip_data, port_data))
    {
        PRINT_FTPS("ftps_passive_mode failed");
        return NULL;
    }
        
    if (!ftps_client_connect_tcp(&client_data, ip_data, port_data))
    {
        PRINT_FTPS("ftps_client_connect_tcp failed");
        return NULL;
    } 
  
    if (is_x1)
    {
        snprintf((char *)w_buffer, sizeof(w_buffer), "RETR %s%s\r\n", CONFIG_3MF_THUMBNAIL_PATH, filename);
 
        if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        {
            PRINT_FTPS("ftps_download failed with[%s]",filename);
            return NULL; 
        }
    }
    else
    {
        snprintf((char *)w_buffer, sizeof(w_buffer), "RETR %s\r\n", filename);
        
        if (!ftps_send_cmd_wait_response(client_ctrl, w_buffer, r_buffer, sizeof(r_buffer)))
        {
            PRINT_FTPS("ftps_download failed with[%s]",filename);
            return NULL; 
        }
    }
 
    if (!ftps_client_connect_ssl(&client_data, ip_data, port_data, is_x1?client_ctrl:NULL)) {
        ftps_debug_printf("client_data error\r\n");
        PRINT_FTPS("client_data error");
        return NULL;
    } 
    
    /*获取大小后，直接下载*/ 
    //SIZE

    // wait for list of dir
    #define F_BUFFER_BASE_SIZE_DOWNLOAD (4096)
    uint32_t total_len = 0;
    int32_t ret = 0;
    uint8_t * f_buffer = (uint8_t *)esp_psram_malloc(F_BUFFER_BASE_SIZE_DOWNLOAD);
    if (f_buffer == NULL)
    {
        PRINT_FTPS("esp_psram_malloc error");
        goto err_end;
    } 
    do {
        uint8_t * t_buffer = (uint8_t *)esp_psram_realloc((void *)f_buffer, F_BUFFER_BASE_SIZE_DOWNLOAD + total_len);
        if (t_buffer == NULL) 
        {
            PRINT_FTPS("esp_psram_realloc error");
            goto err_end;
        }
        f_buffer = t_buffer;
        ret = ftps_ssl_read(&client_data.ssl, f_buffer + total_len, F_BUFFER_BASE_SIZE_DOWNLOAD);
        if (ret <= 0) { 
            break;
        }        
        total_len += ret; 
        int8_t res_check = ftps_check_stop();
        if (res_check>0)
        {
            need_stop_ftps=true; 
            return NULL;
        } 
        //delay(1);
    } while (1);
    f_buffer[total_len] = 0;

    ftps_client_free(&client_data);
    
    // wait for "226"
    //PRINT_FTPS("ftps_wait_response bf");
    if (!ftps_wait_response(client_ctrl, r_buffer, sizeof(r_buffer))) 
    {
        PRINT_FTPS("ftps_wait_response 226 error"); 
        need_stop_ftps=true;
        goto err_end;
    } 

    return f_buffer;

err_end:
    if (f_buffer) {
        free(f_buffer);
        f_buffer = NULL;
    }
    return NULL;
}

int printer_3mf_list_get_thumbnails(file_list_3mf_t *p_3mf_list) 
{
    uint32_t i = 0;  
    uint8_t w_buffer[64];
    uint8_t r_buffer[128]; 
    int32_t png_file_cnt = 0;
    uint8_t * response = NULL;
    int8_t res = -1;
    char img_fname[256+4]={0}; 

    ftps_client_t *client = &client_ctrl; 
    nvs_config_t * nvs = &bambu_mqtt_leader->nvs_config;
    bool is_x1 = (BAMBU_MODEL_X1 == nvs->model_num); 
    
    response = ftps_list_dir_malloc(client, CONFIG_3MF_THUMBNAIL_PATH, is_x1);
    if(response == NULL)
    {
        PRINT_FTPS("thumbnails ftps_list_dir_malloc null");
        goto err_end;
    }    

    file_3mf_list_free(img_files, FILE_3MF_COUNT_MAX);
    png_file_cnt = ftps_parse_file(NULL, img_files, (char *)response, FILE_3MF_COUNT_MAX, true);

    PRINT_FTPS("png_file_cnt=%ld",png_file_cnt);

    /*切换到/image*/ 
    snprintf((char *)w_buffer, sizeof(w_buffer), "CWD %s\r\n",CONFIG_3MF_THUMBNAIL_PATH);
    if (!ftps_send_cmd_wait_response(client, w_buffer, r_buffer, sizeof(r_buffer)))
    { 
        goto err_end;
    }  

    if (is_x1)
    {
        ftps_client_free(client);

        if(!ftps_client_connect(client, nvs->ip, FTPS_PORT))
        { 
            goto err_end;
        } 
        
        if(!ftps_login_printer(client, FTPS_USER, nvs->access_code))
        { 
            goto err_end;
        }  
    }
    
    for (int i = 0; i < png_file_cnt; i++) 
    { 
        file_gcode_t* img_file = &img_files[i];  
 
        //PRINT_FTPS("img_file[%s] year[%d],m[%02x],d[%02x],h[%02x],min[%02x]",img_file->name, img_file->time.year,img_file->time.month,img_file->time.day,img_file->time.hour,img_file->time.min); 
  
        for (int j=0; j<p_3mf_list->file_count; j++) 
        {
            file_gcode_t *file_entry = &p_3mf_list->files[j];
             
            if (FILE_TYPE_3MF != file_entry->type)
            {
                //PRINT_FTPS("file_entry[%s] not FILE_TYPE_3MF, type[%02x]",file_entry->name,file_entry->type);

                continue;
            }
 
            int8_t res_check = ftps_check_stop();
            if (res_check>0)
            {
                PRINT_FTPS("ftps_download error goto need_retry");

                goto err_end;
            } 

            int distance_seconds = file_entry->timestamp-img_file->timestamp; 
 
            #define CONFIG_SAME_TIME_SECONDS 65

            bool is_same_timestamp = (distance_seconds>=0)?(distance_seconds<=CONFIG_SAME_TIME_SECONDS):(distance_seconds>-CONFIG_SAME_TIME_SECONDS);

            //PRINT_FTPS("distance_seconds[%d] file[%s], png[%s]",distance_seconds,file_entry->name,img_file->name); 
 
            bool is_u16_img = false;
 
            snprintf(img_fname,sizeof(img_fname),"%s_img",file_entry->name);
            
            if ((CONFIG_3MF_PREVIEW_DATA_SIZE == img_file->size) 
                && (!strcmp(img_fname, img_file->name)))
            {  
                PRINT_FTPS("find a u16 img [%s] 3mf_name[%s]\r\n",img_file->name, file_entry->name);  
                is_u16_img=true;  
            }
            else
            {
                if ((CONFIG_3MF_PREVIEW_DATA_SIZE == img_file->size) 
                    && is_same_timestamp)
                {
                    is_u16_img=true;
                    PRINT_FTPS("is_same_timestamp and u16 img size\r\n");
                }
            } 

            /*如果得到了PNG 则创建一个thumbnail的.bin图片*/
            #if 0
            if (is_same_timestamp || is_u16_img) 
            #else
            if (is_same_timestamp) 
            #endif
            {    
                if (need_stop_ftps)
                {
                    PRINT_FTPS("need_stop_ftps goto err_end;\r\n");

                    goto err_end;
                }

                if (FTPS_UPLOAD_START == ftps_upload_info.ftps_status)
                {
                    PRINT_FTPS("FTPS_UPLOAD_START need stop");

                    goto err_end;
                }
 
                file_entry->png_file_data = ftps_download(client, img_file->name, is_x1);
                if (file_entry->png_file_data)
                {
                    bool thumbnail_is_valid = false;
                    /*拿到图片后理解解码放进对应的数据里面*/
                    if (p_3mf_list->thumbnail_valid_cnt < FTPS_GCODES_WITH_THUMBNAIL_NUM)
                    {  
                        if (file_entry->img_data.data)
                        {  
                            if (CONFIG_3MF_PREVIEW_DATA_SIZE == file_entry->img_data.data_size)
                            {
                                PRINT_FTPS("same thumbnail\r\n");

                                continue;
                            } 
 
                            free((void *)file_entry->img_data.data);
                            file_entry->img_data.data=NULL;
                        } 

                        lvgl_port_lock(0);
                        lv_obj_t *loading_panel = lv_scanning_spin_create(file_entry->btn, RS_TRANSLATE(K_LOADING));

                        lv_obj_align(loading_panel, LV_ALIGN_CENTER, 0, 20);
                        lvgl_port_unlock();

                        file_entry->img_data.header.w=CONFIG_3MF_THUMBNAIL_WIDTH;
                        file_entry->img_data.header.h=CONFIG_3MF_THUMBNAIL_HEIGHT; 
                        file_entry->img_data.header.cf=LV_IMG_CF_TRUE_COLOR; 
                        
                        if (!is_u16_img)
                        {
                            unsigned error = 1;
                            unsigned int png_width;             /*Will be the width of the decoded image*/
                            unsigned int png_height;            /*Will be the height of the decoded image*/

                            uint8_t *img_data = NULL;   
                            uint8_t *u16_img_data = NULL;
  
                            /*Decode the loaded image in ARGB8888 */
                            //hal_protect_display_enter();
                            error = lodepng_decode32(&img_data, &png_width, &png_height, file_entry->png_file_data, img_file->size);  
                            //hal_protect_display_exit();

                            free(file_entry->png_file_data);  /*Free the loaded file*/
                            file_entry->png_file_data=NULL;

                            if (error)
                            {
                                if(img_data != NULL)
                                {
                                    free(img_data);
                                }
                            }
                            else
                            { 
                                u16_img_data = (uint8_t *)esp_psram_malloc(CONFIG_3MF_PREVIEW_DATA_SIZE);
                                if (!u16_img_data)
                                { 
                                    PRINT_FTPS("u16_img_data malloc error\r\n");
                                    goto err_end;
                                }

                                ut_convert_color_depth_blend(u16_img_data, img_data, png_width, png_height, CONFIG_3MF_THUMBNAIL_BG_COLOR);
                                if (img_data)
                                {
                                    free(img_data);
                                    img_data=NULL;
                                }

                                file_entry->img_data.data_size = CONFIG_3MF_PREVIEW_DATA_SIZE; 
                                file_entry->img_data.data=u16_img_data;  
                                thumbnail_is_valid=true;
                                //PRINT_FTPS("download ok with[%s] for 3mf [%s]",img_file->name,file_entry->name);

                                /*如果home的名字与该3mf文件相同并且当前预览图为默认熊猫预览图
                                则需要更新主页预览图*/  
                                if (bambu_api_title_is_same(file_entry->name,bambu_mqtt_leader->bambu_data.gcode_file))
                                {  
                                    char img_fname_upload[256+4]={0}; 

                                    if (ui_img_icon_model_png.data == ui_img_icon_model_png_bak.data)
                                    {
                                        notify_to_account_task(NOTIFY_CODE_UPDATE_PNG); 
                                    } 
                                } 
                            }
                        }
                        else
                        {
                            file_entry->img_data.data_size = img_file->size; 
                            file_entry->img_data.data = file_entry->png_file_data;  
                            thumbnail_is_valid=true;
                            //PRINT_FTPS("download ok with[%s] for 3mf [%s] by panda touch u16 img",img_file->name,file_entry->name); 

                            if (bambu_api_title_is_same(file_entry->name,bambu_mqtt_leader->bambu_data.gcode_file)) 
                            {  
                                if (ui_img_icon_model_png.data == ui_img_icon_model_png_bak.data)
                                {
                                    notify_to_account_task(NOTIFY_CODE_UPDATE_PNG);

                                    PRINT_FTPS("is_u16_img need notify update history by this 3mf file\r\n");
                                } 
                            } 
                        } 

                        if (thumbnail_is_valid)
                        {
                            file_entry->thumbnail_is_valid=true;
                            p_3mf_list->thumbnail_valid_cnt++; 
                        }

                        lvgl_port_lock(0);

                        if (file_entry->thumbnail_is_valid)
                        { 
                            lv_obj_set_style_bg_img_src(file_entry->btn, &file_entry->img_data, LV_PART_MAIN);  
                            lv_obj_scroll_to_view(file_entry->panel, LV_ANIM_OFF);
                        } 

                        if (loading_panel)
                        {
                            lv_obj_del_async(loading_panel);
                        }

                        lvgl_port_unlock();

                        PRINT_FTPS("thumbnail++ cnt=%ld\r\n",p_3mf_list->thumbnail_valid_cnt);
                    }
                    else
                    {
                        PRINT_FTPS("goto err_end;");

                        goto err_end;
                    }
                } 
                else
                {
                    PRINT_FTPS("ftps_download failed [%s]\r\n", img_file->name);
                }
            }
            else
            {
                //PRINT_FTPS("file_entry->timestamp=%lu,img_file->timestamp=%lu\r\n",file_entry->timestamp,img_file->timestamp);

                //PRINT_FTPS("file_entry[%s], png_file[%s]",file_entry->name, img_file->name);  
                if (NULL == file_entry->img_data.data)
                {
                   // PRINT_FTPS("file_entry[%s] year[%d],m[%02x],d[%02x],h[%02x],min[%02x]",file_entry->name, file_entry->time.year,file_entry->time.month,file_entry->time.day,file_entry->time.hour,file_entry->time.min);
                }
            }  
        } 
    }    

    res=0;
    
    err_end: 
    file_3mf_list_free(img_files, FILE_3MF_COUNT_MAX);
    need_stop_ftps=false;
    if (response)
    {
        free(response);
    }  

    //ftps_client_free(client);

    return res;
}

 
static int8_t ftps_list_gcodes(ftps_client_t *client, nvs_config_t * nvs, file_list_3mf_t *p_3mf_list);

void test_ftps_img(bambu_mqtt_t *mqtt)  
{  
   ftps_list_gcodes(&client_ctrl, &mqtt->nvs_config, printer_3mf_list); 
} 

static void ftps_get_thumbnails_from_3mf(ftps_client_t *client, nvs_config_t * nvs, file_list_3mf_t *p_3mf_list)
{
    for (int j=0; j<p_3mf_list->file_count; j++) 
    {
        file_gcode_t *file_entry = &p_3mf_list->files[j];
        
        file_entry->thumbnail_is_valid=false;
    }

    #if 1 
    if(!ftps_client_connect(client, nvs->ip, FTPS_PORT))
    {
        PRINT_FTPS("ftps_client_connect failed\r\n"); 
    } 
    
    if(!ftps_login_printer(client, FTPS_USER, nvs->access_code))
    {
        PRINT_FTPS("ftps_login_printer failed\r\n");
    }  
    #endif
                
    /*先查找缩略图png*/
    printer_3mf_list_get_thumbnails(p_3mf_list);
 
    for (int j=0; j<p_3mf_list->file_count; j++) 
    { 
        file_gcode_t *file_entry = &p_3mf_list->files[j];

         lv_obj_t *loading_panel = NULL;

        if (!file_entry->thumbnail_is_valid)
        {
            if (p_3mf_list->thumbnail_valid_cnt < FTPS_GCODES_WITH_THUMBNAIL_NUM)
            {    
                #if 1 
                if(!ftps_client_connect(client, nvs->ip, FTPS_PORT))
                {
                    PRINT_FTPS("ftps_client_connect failed\r\n"); 
                } 
                
                if(!ftps_login_printer(client, FTPS_USER, nvs->access_code))
                {
                    PRINT_FTPS("ftps_login_printer failed\r\n");
                    
                }  
                #endif

                lvgl_port_lock(0);
                loading_panel = lv_scanning_spin_create(file_entry->btn, RS_TRANSLATE(K_LOADING));

                lv_obj_align(loading_panel, LV_ALIGN_CENTER, 0, 20);
                lvgl_port_unlock();

                int res_download = download_png_thumbnail_via_ftps(client, file_entry);
                if (0 == res_download)
                {
                    p_3mf_list->thumbnail_valid_cnt++;
                    file_entry->thumbnail_is_valid=true;
                }

                ftps_client_free(client);
            }
            else
            {
                break;
            }
        }

        lvgl_port_lock(0);

        if (file_entry->thumbnail_is_valid)
        { 
            lv_obj_set_style_bg_img_src(file_entry->btn, &file_entry->img_data, LV_PART_MAIN);  
            lv_obj_scroll_to_view(file_entry->panel, LV_ANIM_OFF);
        } 

        if (loading_panel)
        {
            lv_obj_del_async(loading_panel);
        }

        lvgl_port_unlock();
    } 

    PRINT_FTPS("ftps_get_thumbnails_from_3mf end\r\n"); 
}
// #define GCODE_CACHE_SIZE 256
int8_t ftps_list_gcodes(ftps_client_t *client, nvs_config_t * nvs, file_list_3mf_t *p_3mf_list)
{
    uint8_t r_buffer[128]; 
    uint8_t * gcode = NULL;
    int8_t res = -1; 
 
    if(!ftps_client_connect(client, nvs->ip, FTPS_PORT))
    {
        PRINT_FTPS("ftps_client_connect failed\r\n");
        return FTPS_CONNECT_ERROR;
    } 
    
    if(!ftps_login_printer(client, FTPS_USER, nvs->access_code))
    {
        PRINT_FTPS("ftps_login_printer failed\r\n");
        res=FTPS_LOGIN_ERROR;
        goto list_res;
    }  
 
    gcode = ftps_list_dir_malloc(client, p_3mf_list->current_path, true);
    if(gcode == NULL)
    {
        PRINT_FTPS("ftps_list_dir_malloc null");
        res=FTPS_TIMEOUT;
        goto list_res;
    }  
 
    p_3mf_list->file_count = 0; 
    p_3mf_list->file_count = ftps_parse_file(p_3mf_list, p_3mf_list->files, (char *)gcode, FILE_3MF_COUNT_MAX, false);
    free(gcode);
 
    if (p_3mf_list->file_count)
    { 
        p_3mf_list->thumbnail_valid_cnt=0;

        file_3mf_list_arrange(p_3mf_list); 

        PRINT_FTPS("file_count=%ld\r\n",p_3mf_list->file_count);  
    }

    #if 0
    for (uint32_t i = 0; i < p_3mf_list.file_count; i++) {
        file_gcode_t* dst = &p_3mf_list.files[i];
        if (dst->time.year)
            ftps_debug_printf("Name:%s\r\n, Data: %d/%d/%d\r\n", dst->name, dst->time.year, dst->time.month, dst->time.day);
        else
            ftps_debug_printf("Name:%s\r\n, Data: This year/%d/%d %d:%02d\r\n", dst->name, dst->time.month, dst->time.day, dst->time.hour, dst->time.min);
    }
    #endif
 

    res = FTPS_LOGIN_OK;
list_res:
    ftps_client_free(client);

    return res;
}

ftps_status_t ftps_upload_gcode(nvs_config_t * nvs, ftps_upload_info_t * p_info){
    ftps_status_t status = FTPS_INIT;
    char img_fname[256+4]={0}; 

    if(!ftps_client_connect(&client_ctrl, nvs->ip, FTPS_PORT)) return FTPS_ERR;
    if(!ftps_login_printer(&client_ctrl, FTPS_USER, nvs->access_code)) 
    {
        status = FTPS_ERR;
    } 
    else 
    {
        status = ftps_upload(&client_ctrl, p_info); 
    } 

    /*上传的时候需要多次登录*/ 
    ftps_client_free(&client_ctrl);

    /*上传3mf文件的同时也上传png图片到image目录*/ 
    if(!ftps_client_connect(&client_ctrl, nvs->ip, FTPS_PORT)) return FTPS_ERR;
    if(!ftps_login_printer(&client_ctrl, FTPS_USER, nvs->access_code)) 
    {
        status = FTPS_ERR;
        goto upload_end; 
    }  

    if (FTPS_ERR == status)
    {
        goto upload_end; 
    }  

    PRINT_FTPS("status=%02x start upload image",status);  
    snprintf(img_fname,sizeof(img_fname),"%s_img",bambu_mqtt_leader->bambu_data.gcode_file);

    ftps_upload_thumbnail(&client_ctrl, p_info, (BAMBU_MODEL_X1 == nvs->model_num), img_fname); 
    
    upload_end:
    ftps_client_free(&client_ctrl); 

    return status;
}

ftps_status_t ftps_upload_png(const char *fname)
{
    nvs_config_t * nvs = &bambu_mqtt_master->nvs_config;

    ftps_status_t status = FTPS_INIT;
    if(!ftps_client_connect(&client_ctrl, nvs->ip, FTPS_PORT)) return FTPS_ERR;
    if(!ftps_login_printer(&client_ctrl, FTPS_USER, nvs->access_code)) {
        status = FTPS_ERR;
    } else { 
        /*上传3mf文件的同时也上传png图片到image目录*/ 
        PRINT_FTPS("start upload image by 3mf[%s]",fname); 
        ftps_upload_info.filename = fname;
        ftps_upload_thumbnail(&client_ctrl, &ftps_upload_info, (BAMBU_MODEL_X1 == nvs->model_num), "test_png"); 
    }
    ftps_client_free(&client_ctrl);
    return status;
}

static volatile ftps_status_t ftps_list_status = FTPS_INIT;

void ftps_refresh_list_require(void) {
    ftps_list_status = FTPS_REFRESH;
}

ftps_status_t ftps_get_list_status(void) {
    return ftps_list_status;
}

static int8_t file_3mf_list_handle_msg(file_list_3mf_t *p_file_list, file_task_msg_t *msg)
{
    char old_path[1024]={0};

    PRINT_FTPS("msg id=%02x",msg->id);
    #if 0

    switch (msg->id)
    { 
        case FILT_TASK_MSG_CHANGE_DIR:
        { 
            strlcpy(old_path,p_file_list->current_path,sizeof(old_path));

            /*还需要测试中文目录是否有问题*/
            const char *dest_path = (const char *)msg->data;
            if (msg->is_root)
            {
                PRINT_FTPS("back the path before[%s]",p_file_list->current_path); 
                file_3mf_list_back_directory(p_file_list->current_path);
                PRINT_FTPS("back the path after[%s]",p_file_list->current_path);
            }
            else
            {
                /*拼接新的目录*/  
                strcat(p_file_list->current_path, dest_path); 
                strcat(p_file_list->current_path, "/"); 
                PRINT_FTPS("change dir");  
            } 
            ftps_list_status=FTPS_REFRESH;   
        }
        break;  

        case FILT_TASK_MSG_CHANGE_TO_THUMBNAIL:
        {
            p_file_list->show_type=FILE_SHOW_TYPE_THUMBNAIL; 
            ui_files_list_ftps_refresh_require(); 
        }
        break;

        case FILT_TASK_MSG_CHANGE_TO_NORMAL:
        {
            p_file_list->show_type=FILE_SHOW_TYPE_NORMAL; 
            ui_files_list_ftps_refresh_require();
        }
        break;  

        case FILT_TASK_MSG_SORT_BY_DATE_NEW:
        case FILT_TASK_MSG_SORT_BY_DATE_OLD:
        case FILT_TASK_MSG_SORT_BY_NAME_A_Z:
        case FILT_TASK_MSG_SORT_BY_NAME_Z_A:
        {
            p_file_list->sort_type=msg->id-FILT_TASK_MSG_SORT_BY_DATE_NEW; 
            file_3mf_list_arrange(p_file_list);  
            ui_files_list_ftps_refresh_require();
        }
        break;  

        default:
        return -1;
        break;
    }

    p_file_list->file_task_msg.id = FILT_TASK_MSG_NONE;   
    #endif

    return 0;     
}

TaskHandle_t t_handle_update_thumbnail = NULL;

void notify_to_thumbnail_task(uint32_t set_val)
{ 
    #if 0
    if (t_handle_update_thumbnail)
    { 
        /*notify exit lvgl task*/
        xTaskNotify((TaskHandle_t )  t_handle_update_thumbnail, //任务句柄，指明往哪个任务发送消息，很重要
                            (uint32_t )      set_val,    //发送的消息
                            (eNotifyAction)  eSetValueWithOverwrite  
                            ); 
    }  
    #endif
} 

void ftps_task(void * parameter) 
{  
    const char *default_path = GET_DEFAULT_WORK_DIRECTORY(nvs_ftps_work_path_idx);

    if (file_3mf_list_init(&printer_3mf_list, default_path, t_handle_ftps) < 0)
    {
        vTaskDelete(NULL);
        
        return;
    } 

    img_files = (file_gcode_t *)esp_psram_malloc(sizeof(file_gcode_t)*FILE_3MF_COUNT_MAX);
    if (!img_files)
    { 
        vTaskDelete(NULL);
        
        return;
    } 
    memset(img_files,0,sizeof(file_gcode_t)*FILE_3MF_COUNT_MAX);

    PRINT_FTPS("start ftps loop\r\n");

    while (1) {  
        delay(1000);
        // has not wifi connection
        // wifi_sync_lock(0);
        // wifi_status_t get_wifi_status = wifi_get_connect_status();
        // wifi_sync_unlock();
        
        // if (get_wifi_status != WIFI_STATUS_CONNECTED) continue;
   
        if (bambu_mqtt_leader != bambu_mqtt_master)
        { 
            bambu_mqtt_leader=bambu_mqtt_master;
            strlcpy(printer_3mf_list->current_path,bambu_mqtt_leader->ftps_path,sizeof(printer_3mf_list->current_path));
            printer_3mf_list->show_type = bambu_mqtt_leader->show_type;
            ftps_list_status=FTPS_REFRESH;    

            PRINT_FTPS("master change FTPS_REFRESH\r\n");
        }

        if (MQTT_CONNECTED != bambu_mqtt_leader->status)
        {
            continue;
        }

        uint32_t notifyValue=0;
        bool have_change_path = false;
        #if 0
        BaseType_t err = xTaskNotifyWait((uint32_t )  0x00,       
                            (uint32_t)   0xffffffff,   
                            (uint32_t*)  &notifyValue, 
                            (TickType_t) 0  
                            );
        if(err == pdTRUE)
        {     
            PRINT_FTPS("xTaskNotifyWait true\r\n");

            if (NOTIFY_CODE_STOP_FTPS == notifyValue)
            {   
                ftps_list_status=FTPS_REFRESH; 
            }
            else if (NOTIFY_CODE_UPLOAD_U16_IMG == notifyValue)
            {  
                PRINT_FTPS("upload a img to printer\r\n");
                /*上传3mf文件的同时也上传png图片到image目录*/ 
                if(ftps_client_connect(&client_ctrl, bambu_mqtt_leader->nvs_config.ip, FTPS_PORT))
                {
                    if(ftps_login_printer(&client_ctrl, FTPS_USER, bambu_mqtt_leader->nvs_config.access_code)) 
                    {
                        char img_fname[256+4]={0}; 
                        snprintf(img_fname,sizeof(img_fname),"%s_img",bambu_mqtt_leader->bambu_data.gcode_file);
                        ftps_upload_thumbnail_from_panda_touch(&client_ctrl, bambu_mqtt_leader->preview_home_3mf,
                                                            bambu_mqtt_leader->preview_home_3mf_size, (BAMBU_MODEL_X1 == bambu_mqtt_leader->nvs_config.model_num), img_fname);
                    } 
                } 
            } 
            else
            {
                file_task_msg_t *get_msg = (file_task_msg_t *)notifyValue;

                int8_t list_res = file_3mf_list_handle_msg(printer_3mf_list, get_msg);  
                
                if ((0== list_res) && (FILT_TASK_MSG_CHANGE_DIR == get_msg->id))
                {
                    have_change_path=true;
                }
            }
        }
        #endif 

        if (ftps_list_status == FTPS_REFRESH) 
        {   
            /*每次刷新的时候提前释放掉*/
            file_3mf_list_free(printer_3mf_list->files, FILE_3MF_COUNT_MAX);

            //notify_to_thumbnail_task(NOTIFY_CODE_STOP_FTPS_BY_UPDATE_THUMBNAIL);
            
            PRINT_FTPS("refresh path[%s]\r\n",printer_3mf_list->current_path);
            PRINT_FTPS("mqtt current path[%s]\r\n",bambu_mqtt_leader->ftps_path);
 
            uint64_t start = get_current_millis();   
            ui_files_list_ftps_refresh_require(); 
            bambu_mqtt_leader->ftp_res = ftps_list_gcodes(&client_ctrl, &bambu_mqtt_leader->nvs_config, printer_3mf_list); 
            PRINT_FTPS("FTPS_REFRESH res=%d takes[%ld]ms\r\n",(int)bambu_mqtt_leader->ftp_res,((get_current_millis() - start)));
            if (FTPS_CONNECT_ERROR == bambu_mqtt_leader->ftp_res)
            { 
                refresh_udp_background(bambu_mqtt_leader->nvs_config.sn); 
            }
            else
            { 
                strlcpy(bambu_mqtt_leader->ftps_path,printer_3mf_list->current_path,sizeof(printer_3mf_list->current_path));
                bambu_mqtt_leader->show_type = printer_3mf_list->show_type; 
                bambu_mqtt_master->preview_from_ftp_retry_cnt=0;
            }

            if (refresh_by_change_master)
            {
                ftps_list_status = FTPS_REFRESH; 
                refresh_by_change_master=false;
                PRINT_FTPS("refresh_by_change_master\r\n"); 
            }
            else
            {
                ftps_list_status = FTPS_OK;  
            } 

            PRINT_FTPS("current path[%s]\n",bambu_mqtt_leader->ftps_path);
 
            if ((FTPS_LOGIN_OK != bambu_mqtt_leader->ftp_res)
                && have_change_path)
            { 
                PRINT_FTPS("to reset ftp current_path to [%s]\n",printer_3mf_list->current_path);

                strlcpy(printer_3mf_list->current_path,bambu_mqtt_leader->ftps_path,sizeof(printer_3mf_list->current_path));
            }
             
            ui_files_list_ftps_refresh_require();   

            if (FTPS_OK == ftps_list_status)
            {
                ftps_get_thumbnails_from_3mf(&client_ctrl, &bambu_mqtt_leader->nvs_config, printer_3mf_list);
            }
        }
        ftps_upload_info_t * p_info = &ftps_upload_info;
        if (p_info->ftps_status == FTPS_UPLOAD_START) {
            // // mainly control
            // p_info->task_total = 0;
            // if (bambu_mqtt_leader->status == MQTT_CONNECTED) {
            //     p_info->task_queue[p_info->task_total++] = bambu_get_mqtt_index(bambu_mqtt_leader);
            // }
            // // sync control
            // if (p_info->ftps_status == FTPS_UPLOAD_SYNC) {
            //     for (uint8_t i = 0; i < bambu_printer_cnt; i++) {
            //         bambu_mqtt_t * mqtt = bambu_get_mqtt(i);
            //         if (mqtt->nvs_config.connect_flag != CONNECT_FLAG_SLAVE) continue;
            //         if (mqtt->status != MQTT_CONNECTED) continue;
            //         p_info->task_queue[p_info->task_total++] = i;
            //     }
            // }
            // require and wait ui refresh to create upload task list
            ui_set_ftps_status(UI_FTPS_UPLOAD_CREATE);
            while(ui_get_ftps_status() == UI_FTPS_UPLOAD_CREATE) 
            {
                delay(10);
            }

            for (p_info->task_cur = 0; (p_info->task_cur < p_info->task_total) && (p_info->ftps_status != FTPS_UPLOAD_ABORT); p_info->task_cur++) 
            {
                p_info->size_cur = 0;
                p_info->size_total = 0;
                bambu_mqtt_t * mqtt = bambu_get_mqtt(p_info->task[p_info->task_cur].index);
                /*直接跳过断开连接的打印机*/
                if (mqtt->status != MQTT_CONNECTED) continue;
                ftps_debug_printf("Start[%d]: ftps_upload_gcode\r\n", p_info->task_cur);
                p_info->task[p_info->task_cur].status = ftps_upload_gcode(&mqtt->nvs_config, p_info);
                /*这里是从根目录发起打印，因为U盘是发送到根目录下*/

                ftps_debug_printf("ftps_upload_gcode[%d], status: %d\r\n",
                                  p_info->task_cur,
                                  p_info->task[p_info->task_cur].status);

                // require and wait ui refresh the last task
                ui_set_ftps_status(UI_FTPS_UPLOADED_ONE_TASK);
                while(ui_get_ftps_status() == UI_FTPS_UPLOADED_ONE_TASK) {
                    delay(10);
                }
            }
            // require and wait ui refresh the last task
            ui_set_ftps_status(UI_FTPS_UPLOADED_ONE_TASK);
            while(ui_get_ftps_status() == UI_FTPS_UPLOADED_ONE_TASK) {
                delay(10);
            }
            delay(1000);
            p_info->ftps_status = FTPS_END;

            #if 0
            /*刷新一下*/
            ftps_list_status = FTPS_REFRESH; 

            uint8_t get_printers_cnt = 0;

            printer_group_sync_lock(0);
            printer_control_t get_control_type = group_sync_data.control_type;   
            printer_group_t *get_leader_group = printer_group_get_leader();
            printer_group_sync_unlock(); 

            if (get_leader_group)
            {
                get_printers_cnt = get_leader_group->nvs_config.printers_cnt; 
            } 
        
            /*当组中的打印机大于1台时 在这里创建任务用于延时发起打印*/
            if ((p_info->task_total > 1) 
                && (PRT_CTL_GROUP == get_control_type)
                && (get_printers_cnt > 1)
                )
            {
                for (p_info->task_cur = 0; 
                        (p_info->task_cur < p_info->task_total) && (p_info->ftps_status != FTPS_UPLOAD_ABORT); 
                        p_info->task_cur++) 
                { 
                    bambu_mqtt_t * mqtt = bambu_get_mqtt(p_info->task[p_info->task_cur].index); 
                    if (mqtt->status != MQTT_CONNECTED) continue;  

                    if (p_info->task[p_info->task_cur].status == FTPS_OK) 
                    {  
                        mqtt->bambu_data.print_type = PRINT_FROM_TOUCH;
                        const char *default_path = GET_DEFAULT_WORK_DIRECTORY(nvs_ftps_work_path_idx);

                        mqtt_one_client_print_project_file_local(mqtt, default_path ,p_info->filename,
                                                        p_info->task[p_info->task_cur].bed_leveling,
                                                        p_info->task[p_info->task_cur].flow_cali,
                                                        p_info->task[p_info->task_cur].timelapse,
                                                        p_info->task[p_info->task_cur].use_ams,
                                                        p_info->task[p_info->task_cur].clear_power_usage,
                                                        p_info->task[p_info->task_cur].auto_power_off);

                        /*从U盘发起打印的在这里等待一下*/ 
                        mqtt->bambu_data.gcode_state = GCODE_STATE_PREPARE;

                        /*如果是最后一个就不需要等了*/
                        if (p_info->task_cur == (p_info->task_total-1))
                        {
                            break;
                        }

                        uint32_t tick_start_wait = xTaskGetTickCount();
                        uint32_t config_heat_delay = heat_delay_values[nvs_heat_delay_idx]*60*1000;

                        //PRINT_FTPS("start waiting for heating about [%ld]ms\r\n",config_heat_delay);

                        while (1)
                        {
                            /*取消了打印就不等了*/
                            if ((GCODE_STATE_PREPARE != mqtt->bambu_data.gcode_state)
                                && (GCODE_STATE_RUNNING != mqtt->bambu_data.gcode_state)
                                //&& (GCODE_STATE_PAUSE != mqtt->bambu_data.gcode_state)
                                )
                            {
                                //PRINT_FTPS("stop waiting heat by state[%02x]\r\n",mqtt->bambu_data.gcode_state);

                                break;
                            } 

                            if (mqtt->status != MQTT_CONNECTED)
                            {
                                break;
                            } 
  
                            if (PRINTER_STAGE_CLEAN_NOZZLE == mqtt->bambu_data.stg_cur)
                            {
                                break;
                            }
 
                            if ((xTaskGetTickCount() - tick_start_wait) >= pdMS_TO_TICKS(config_heat_delay))
                            {
                                //PRINT_FTPS("time out waiting for heating with [%s]\r\n",mqtt->nvs_config.name);

                                break;
                            }  

                            delay(1000);
                        } 

                        //PRINT_FTPS("wait ticks about ms: %ld\r\n",xTaskGetTickCount() - tick_start_wait+1);
                    }
                }
            }
            else
            {
                for (p_info->task_cur = 0; 
                        (p_info->task_cur < p_info->task_total) && (p_info->ftps_status != FTPS_UPLOAD_ABORT); 
                        p_info->task_cur++) 
                { 
                    bambu_mqtt_t * mqtt = bambu_get_mqtt(p_info->task[p_info->task_cur].index); 
                    if (mqtt->status != MQTT_CONNECTED) continue;  

                    if (p_info->task[p_info->task_cur].status == FTPS_OK) 
                    {  
                        mqtt->bambu_data.print_type = PRINT_FROM_TOUCH;

                        const char *default_path = GET_DEFAULT_WORK_DIRECTORY(nvs_ftps_work_path_idx);

                        mqtt_one_client_print_project_file_local(mqtt, default_path ,p_info->filename,
                                                        p_info->task[p_info->task_cur].bed_leveling,
                                                        p_info->task[p_info->task_cur].flow_cali,
                                                        p_info->task[p_info->task_cur].timelapse,
                                                        p_info->task[p_info->task_cur].use_ams,
                                                        p_info->task[p_info->task_cur].clear_power_usage,
                                                        p_info->task[p_info->task_cur].auto_power_off);

                        /*从U盘发起打印的在这里等待一下*/ 
                        mqtt->bambu_data.gcode_state = GCODE_STATE_PREPARE; 
                    }
                }
            }
            #endif
        }

        /*如果到这里来了说明中途点了终止需要重置一下，不然一直在转圈圈*/
        if (FTPS_UPLOAD_ABORT == p_info->ftps_status)
        {
            PRINT_FTPS("reset FTPS_UPLOAD_ABORT\r\n");
            p_info->ftps_status = FTPS_END;
        } 
    } 
}
