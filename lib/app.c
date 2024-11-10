

#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "lv_conf.h"
#include "lvgl.h"
#include "examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"

#include "display/fbdev.h" 
#include <unistd.h> 

#include "app.h"
#include "lv_ui_overlay.h"

#define BMP_HEADER_SIZE 54 

#define DISP_BUF_SIZE DISP_HOR_RES*DISP_VER_RES

extern lv_font_t font_bin_16; 

static uint16_t fb_buf_1[DISP_BUF_SIZE];
static uint16_t fb_buf_2[DISP_BUF_SIZE];
uint16_t fb_buf_active[DISP_BUF_SIZE];
uint16_t *p_fb_buf_active=NULL;

static lv_disp_draw_buf_t disp_buf;

static lv_disp_drv_t disp_drv;

static FILE *f_font_img = NULL; 
uint8_t *font_img_buffer = NULL;
uint8_t panda_pwr_is_opened=0;

uint32_t get_current_millis(void) 
{
    #if 0
    struct timeval tv;
    
    gettimeofday(&tv, NULL);

    long long millis = (long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000;
    return millis;
    #else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);  // 转换为毫秒
    #endif
}

uint64_t esp_timer_get_time(void)
{ 
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000);  // 转换为微秒 
}

static void lv_linux_disp_init(void)
{ 
    /*Linux frame buffer device init*/
    fbdev_init();
    
   /*A small buffer for LittlevGL to draw the screen's content*/
    lv_coord_t hor_res = DISP_HOR_RES;
    lv_coord_t ver_res = DISP_VER_RES;
    /*Initialize a descriptor for the buffer*/
    
    lv_disp_draw_buf_init(&disp_buf, fb_buf_1, fb_buf_2, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = hor_res;
    disp_drv.ver_res    = ver_res;
    disp_drv.direct_mode = 1;
    disp_drv.full_refresh = 1;

    lv_disp_drv_register(&disp_drv);

    p_fb_buf_active = fb_buf_active;
} 

typedef struct {
  volatile uint8_t state;
  uint16_t x;
  uint16_t y;
} gt911_point_t;
 
static gt911_point_t current_point={0};

static void usr_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) 
{ 
    //printf("usr_touchpad_read");

    if(current_point.state) 
    {
        data->state = LV_INDEV_STATE_PR;
        /*Set the coordinates*/
        data->point.x = current_point.x;
        data->point.y = current_point.y; 
    } else {
        data->state = LV_INDEV_STATE_REL; 
    }   
}

static void lv_linux_indev_init(void)
{ 
    static lv_indev_drv_t indev_drv; 
    static lv_indev_t * indev_default; 
    lv_indev_drv_init(&indev_drv);
    // indev_drv.gesture_limit = 30;
    // indev_drv.gesture_min_velocity = 3;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = usr_touchpad_read;
    indev_default = lv_indev_drv_register(&indev_drv);
} 

static pthread_t thread_lvgl; 
volatile bool need_exit=false;

// 线程的入口函数
void lvgl_app_task(void* arg) 
{
    static uint64_t run_cnt = 0;
 
    //ui_screen_start_init();   
    BAMBU_DATA_MASTER.ams.tray_exist_bits=0xf;
    BAMBU_DATA_MASTER.ams.ams_exist_bits=true;
    bambu_mqtt_master->status = MQTT_CONNECTED; 
    bambu_mqtt_master->nvs_config.connect_flag = CONNECT_FLAG_MASTER; 

    BAMBU_DATA_MASTER.ams.tray_now = 0x01; 
     
    for (uint8_t i=0; i<TRAY_PER_AMS; i++)
    {
        sprintf(BAMBU_DATA_MASTER.ams.ams_tray[0][i].tray_type,"%s","PLA"); 
    }

    BAMBU_DATA_MASTER.ams.ams_tray[0][0].tray_color=0x368CF9FF; //0x368CF9FF 0x37BCF9FF
    BAMBU_DATA_MASTER.ams.ams_tray[0][1].tray_color=0xF931F3FF; 
    BAMBU_DATA_MASTER.ams.ams_tray[0][2].tray_color=0xFFFF0EFF;
    BAMBU_DATA_MASTER.ams.ams_tray[0][3].tray_color=0xFFFFFFFF;
    
    BAMBU_DATA_MASTER.vt_tray.tray_color = 0xbcbcbcff;//0xbcbcbcff; 

    BAMBU_DATA_MASTER.ams.humidity_idx[0] = 1;
    BAMBU_DATA_MASTER.ams.humidity_idx[1] = 0;
    BAMBU_DATA_MASTER.ams.humidity_idx[2] = 0;
    BAMBU_DATA_MASTER.ams.humidity_idx[3] = 0;

    BAMBU_DATA_MASTER.sdcard=true;

    /*填充mqtt数据*/
    #if 1
    strlcpy(bambu_mqtt_master->nvs_config.ip,"192.168.0.182",sizeof(bambu_mqtt_master->nvs_config.ip));
    strlcpy(bambu_mqtt_master->nvs_config.access_code,"37039488",sizeof(bambu_mqtt_master->nvs_config.access_code));
    strlcpy(bambu_mqtt_master->nvs_config.sn,"01P00A3C0500468",sizeof(bambu_mqtt_master->nvs_config.sn));
    strlcpy(bambu_mqtt_master->nvs_config.name,"TEST",sizeof(bambu_mqtt_master->nvs_config.name));
    #elif 1
    strlcpy(bambu_mqtt_master->nvs_config.ip,"192.168.3.16",sizeof(bambu_mqtt_master->nvs_config.ip));
    strlcpy(bambu_mqtt_master->nvs_config.access_code,"35682002",sizeof(bambu_mqtt_master->nvs_config.access_code));
    strlcpy(bambu_mqtt_master->nvs_config.sn,"01S00C3A1600394",sizeof(bambu_mqtt_master->nvs_config.sn));
    strlcpy(bambu_mqtt_master->nvs_config.name,"NODE",sizeof(bambu_mqtt_master->nvs_config.name));
    #else
    strlcpy(bambu_mqtt_master->nvs_config.ip,"192.168.3.68",sizeof(bambu_mqtt_master->nvs_config.ip));
    strlcpy(bambu_mqtt_master->nvs_config.access_code,"40475625",sizeof(bambu_mqtt_master->nvs_config.access_code));
    strlcpy(bambu_mqtt_master->nvs_config.sn,"01P00A3C0300514",sizeof(bambu_mqtt_master->nvs_config.sn));
    strlcpy(bambu_mqtt_master->nvs_config.name,"Jeff 3DP",sizeof(bambu_mqtt_master->nvs_config.name));
    #endif
    
    printf("mqtt ip[%s]\r\n",bambu_mqtt_master->nvs_config.ip);
    printf("mqtt access_code[%s]\r\n",bambu_mqtt_master->nvs_config.access_code);
    printf("mqtt sn[%s]\r\n",bambu_mqtt_master->nvs_config.sn);
    printf("mqtt name[%s]\r\n",bambu_mqtt_master->nvs_config.name);

    #if 0
    {"print":{"upgrade_state":{"sequence_id":0,"progress":"","status":"",
    "consistency_request":false,"dis_state":0,"err_code":0,
    "force_upgrade":false,"message":"0%, 0B/s","module":"",
    "new_version_state":2,"cur_state_code":0,"new_ver_list":[]},
    "ipcam":{"ipcam_dev":"1","ipcam_record":"enable","timelapse":"disable",
    "resolution":"","tutk_server":"disable","mode_bits":3},
    "upload":{"status":"idle","progress":0,"message":""},"nozzle_temper":30.25,
    "nozzle_target_temper":0,"bed_temper":27.09375,"bed_target_temper":0,
    "chamber_temper":5,"mc_print_stage":"1","heatbreak_fan_speed":"0",
    "cooling_fan_speed":"0","big_fan1_speed":"0","big_fan2_speed":"0",
    "mc_percent":0,"mc_remaining_time":165,"ams_status":0,"ams_rfid_status":6,
    "hw_switch_state":1,"spd_mag":100,"spd_lvl":2,"print_error":0,
    "lifecycle":"product","wifi_signal":"-55dBm","gcode_state":"FAILED",
    "gcode_file_prepare_percent":"0","queue_number":0,"queue_total":0,
    "queue_est":0,"queue_sts":0,"project_id":"0","profile_id":"0",
    "task_id":"0","subtask_id":"55930209","subtask_name":"0.4mm-0.18-GEN13 ball.3mf",
    "gcode_file":"","stg":[],"stg_cur":0,"print_type":"idle",
    "home_flag":23086360,"mc_print_line_number":"9926172",
    "mc_print_sub_stage":0,"sdcard":true,"force_upgrade":false,
    "mess_production_state":"active","layer_num":1304,"total_layer_num":1405,"s_obj":[],"filam_bak":[],
    "fan_gear":0,"nozzle_diameter":"0.6","nozzle_type":"hardened_steel",
    "cali_version":0,"hms":[],"online":{"ahb":false,"rfid":false,"version":260407862},
    "ams":{"ams":[{"id":"0","humidity":"1","temp":"0.0","tray":[{"id":"0","remain":-1,"k":0.019999999552965164,
    "n":1,"cali_idx":-1,"tag_uid":"0000000000000000","tray_id_name":"","tray_info_idx":"GFL99",
    "tray_type":"PLA","tray_sub_brands":"","tray_color":"368CF9FF","tray_weight":"0",
    "tray_diameter":"0.00","tray_temp":"0","tray_time":"0","bed_temp_type":"0","bed_temp":"0","nozzle_temp_max":"240","nozzle_temp_min":"190","xcam_info":"000000000000000000000000","tray_uuid":"00000000000000000000000000000000","ctype":0,"cols":["368CF9FF"]},{"id":"1","remain":-1,"k":0.019999999552965164,"n":1,"cali_idx":-1,"tag_uid":"0000000000000000","tray_id_name":"","tray_info_idx":"GFL99","tray_type":"PLA","tray_sub_brands":"","tray_color":"F930F3FF","tray_weight":"0","tray_diameter":"0.00","tray_temp":"0","tray_time":"0","bed_temp_type":"0","bed_temp":"0","nozzle_temp_max":"240","nozzle_temp_min":"190","xcam_info":"000000000000000000000000","tray_uuid":"00000000000000000000000000000000","ctype":0,"cols":["F930F3FF"]},{"id":"2","remain":-1,"k":0.019999999552965164,"n":1,"cali_idx":-1,"tag_uid":"0000000000000000","tray_id_name":"","tray_info_idx":"GFL99","tray_type":"PLA","tray_sub_brands":"","tray_color":"FFFF00FF","tray_weight":"0","tray_diameter":"0.00","tray_temp":"0","tray_time":"0","bed_temp_type":"0","bed_temp":"0","nozzle_temp_max":"240","nozzle_temp_min":"190","xcam_info":"000000000000000000000000","tray_uuid":"00000000000000000000000000000000","ctype":0,"cols":["FFFF00FF"]},{"id":"3"}]}],"ams_exist_bits":"1","tray_exist_bits":"7","tray_is_bbl_bits":"7","tray_tar":"255","tray_now":"254","tray_pre":"254","tray_read_done_bits":"7","tray_reading_bits":"0","version":5,"insert_flag":true,"power_on_flag":false},"vt_tray":{"id":"254","tag_uid":"0000000000000000","tray_id_name":"","tray_info_idx":"GFL99","tray_type":"PLA","tray_sub_brands":"","tray_color":"BCBCBCFF","tray_weight":"0","tray_diameter":"0.00","tray_temp":"0","tray_time":"0","bed_temp_type":"0","bed_temp":"0","nozzle_temp_max":"240","nozzle_temp_min":"190","xcam_info":"000000000000000000000000","tray_uuid":"00000000000000000000000000000000","remain":0,"k":0.019999999552965164,"n":1,"cali_idx":-1},"lights_report":[{"node":"chamber_light","mode":"on"}],"command":"push_status","msg":0,"sequence_id":"4327"}}
    #endif 
    
    sprintf(BAMBU_DATA_MASTER.vt_tray.tray_info_idx,"%s","GFL99"); 
    sprintf(BAMBU_DATA_MASTER.vt_tray.tray_type,"%s","PLA"); 
    BAMBU_DATA_MASTER.vt_tray_id=254;
    
    ui_screen_select(UI_TYPE_SCREEN_CTRL_FILAMENT);//UI_TYPE_SCREEN_CTRL_FILAMENT UI_TYPE_SCREEN_PRINT_HISTORY UI_TYPE_SCREEN_CTRL UI_TYPE_SCREEN_CTRL_FILAMENT UI_TYPE_SCREEN_HOME

    while(1)
    { 
        // if (!(run_cnt%100))
        // {
        //     printf("lv_timer_handler run_cnt=%d\r\n",run_cnt);
        // }
 
        run_cnt++; 

        usleep(20000);    
        lvgl_port_lock(0);
        lv_timer_handler();
        lvgl_port_unlock();

        lv_loop_home();
        lv_loop_ctrl_axis();
        lv_loop_filament();

        lv_loop_files_list_usb();
        lv_loop_files_list_ftps();
        lv_loop_files_list_history();
        //lv_loop_start();  
  
        if (need_exit)
        {
            need_exit=false;
            pthread_exit(NULL);
            break;
        }
    }
}

TaskHandle_t t_handle_wifi = NULL;
TaskHandle_t t_handle_lvgl = NULL; 
TaskHandle_t t_handle_mqtt = NULL; 
TaskHandle_t t_handle_account = NULL; 
TaskHandle_t t_handle_ftps = NULL;
TaskHandle_t t_handle_usb = NULL;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
#include <MQTTClient.h>

#define ADDRESS     "ssl://mqtt.example.com:8883"  // 使用 TLS 的 MQTT broker 地址
#define CLIENTID    "ExampleClientTLS"
#define TOPIC       "test/topic"
#define PAYLOAD     "Hello MQTT with TLS"
#define QOS         1
#define TIMEOUT     10000L
#endif
 
pthread_mutex_t mutex;


void lvgl_init(char *font_img_name)
{ 
    /*上电加载字体文件*/
    f_font_img = fopen(font_img_name,"rb+");
    
    if (!f_font_img)
    {
        printf("warning can not load the font img[%s]\r\n",font_img_name);

        return;
    }

    fseek(f_font_img, 0, SEEK_END);
    uint32_t font_img_size = ftell(f_font_img);
    fseek(f_font_img, 0, SEEK_SET);

    font_img_buffer = (uint8_t *)malloc(font_img_size);
    if (!font_img_buffer)
    {
        printf("warning can not malloc font img buffer\r\n");
        return;
    }

    fread(font_img_buffer,1,font_img_size,f_font_img);
    fclose(f_font_img); 

    printf("load the font img[%s] ok size[%d]\r\n",font_img_name, font_img_size);

    g_language = LANG_1;

    int8_t res_lib = ut_lib_init(font_img_buffer);

    printf("res_lib=%d\r\n",res_lib);
    if (0 != res_lib)
    {
        return;
    }

    if (file_3mf_list_init(&usb_3mf_list, CONFIG_DEFAULT_PATH_USB, t_handle_usb) < 0)
    {
        
    }

    pthread_mutexattr_t attr_lock;
    pthread_mutexattr_init(&attr_lock);
    pthread_mutexattr_settype(&attr_lock, PTHREAD_MUTEX_RECURSIVE);

    file_list_init();

    lv_init();

    /*Linux display device init*/
    lv_linux_disp_init();

    lv_linux_indev_init(); 
    
    bambu_mqtt_memory_init();
    bambu_mqtt_add_default_path(GET_DEFAULT_WORK_DIRECTORY(nvs_ftps_work_path_idx));

    ui_screen_main_init();
    ui_screen_create_home();
    ui_screen_create_ctrl();
    ui_screen_create_print();

    pthread_attr_t attr;
    struct sched_param sched_param;
 
    // 初始化线程属性
    pthread_attr_init(&attr);
 
    // 设置线程的调度策略为FIFO
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
 
    // 设置线程的优先级
    sched_param.sched_priority = 10; // 设置为最高优先级
    pthread_attr_setschedparam(&attr, &sched_param);

    // 创建线程
    int ret = pthread_create(&thread_lvgl, &attr, lvgl_app_task, NULL);
    if (ret != 0) {
        printf("Error: pthread_create failed\n");
        return;
    } 

    xTaskCreate(ftps_task, "ftps", NULL, &t_handle_ftps, 20); 

    #if 0
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_SSLOptions ssl_opts = MQTTClient_SSLOptions_initializer;
    int rc;

    // 初始化 MQTT 客户端
    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

    // 配置连接选项
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    // 配置 SSL 选项
    ssl_opts.enableServerCertAuth = 1;
    ssl_opts.trustStore = "/path/to/ca-cert.pem"; // 指定 CA 证书文件路径
    conn_opts.ssl = &ssl_opts;

    // 建立连接
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        return -1;
    }

    // 发布消息
    printf("Publishing message: %s\n", PAYLOAD);
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = (void*)PAYLOAD;
    pubmsg.payloadlen = (int)strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for publication...\n");
    MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);

    // 断开连接并清理
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    #endif
}

uint8_t lvgl_update_fb(uint16_t *get_fb)
{ 
    if (!disp_drv.draw_buf->flushing)
    {
        memcpy(get_fb, p_fb_buf_active, DISP_BUF_SIZE*2);
        
        return 1;
    }
 
    printf("lvgl_update_fb is busy\r\n"); 

    return 0;
}

void update_mouse_state(uint16_t x, uint16_t y, uint8_t state)
{
    current_point.state = state;
    current_point.x = x;
    current_point.y = y; 
}

void app_restart(const char *task_name)
{ 
    need_exit=true;
    pthread_join(thread_lvgl, NULL);
    printf("thread_lvgl has exited.\n");

    // 创建线程
    int ret = pthread_create(&thread_lvgl, NULL, lvgl_app_task, NULL);
    if (ret != 0) {
        printf("Error: pthread_create failed\n");
        return;
    } 
}