

#include "string.h"
#include "stdio.h"
#include <ctype.h>
#include <stdlib.h> 

#include "app.h"

#include "utils_lib.h"


#include "ui.h" 

#include <stdarg.h>   

#include <time.h> 
#include "panda_touch.h"
 


#define SW_PRINT_UTILS 0

#if SW_PRINT_UTILS
static const char * TAG = "[utils_lib]"; 
#define PRINT_UTILS printf
#else
#define PRINT_UTILS(...)
#endif

extern lv_i18n_phrase_t *custom_singulars;
//extern void rs_lang_init(void);
/*nvs variable*/
uint8_t nvs_ftps_work_path_idx=0;

volatile uint32_t font_data_offset = 0; 
volatile uint8_t file_system_is_updating = 0; 

static volatile uint32_t get_total_size = 0;
 
lv_img_dsc_t ui_img_icon_model_png_bak = {0};
lv_img_dsc_t ui_img_icon_model_png_new = {0};

const resource_data_t resource_bin_files[] = PICTURE_RESOURCE;

const x_header_check_t partition_head_info[] = FONT_RESOURCE;

const uint8_t UT_FONT_CNT = LENGTH_OF_ARRAY(partition_head_info);

volatile uint32_t delay_tick_config;


file_list_3mf_t *usb_3mf_list=NULL;
file_list_3mf_t *printer_3mf_list=NULL; 

extern file_list_history_t *print_history_file_list;

int8_t file_3mf_list_init(file_list_3mf_t **p_3mf_list,const char *default_path, TaskHandle_t task_handle)
{
    *p_3mf_list = (file_list_3mf_t *)esp_psram_malloc(sizeof(file_list_3mf_t));
    if (!*p_3mf_list)
    { 
        return -1; // never here.
    }

    file_list_3mf_t *file_list = *p_3mf_list;
    memset(file_list,0,sizeof(file_list_3mf_t));
    
    for (uint32_t i = 0; i < FILE_3MF_COUNT_MAX; i++) 
    {
        file_list->files[i].name = NULL;
        file_list->files[i].png_file_data = NULL;
        file_list->files[i].img_data.data = NULL;
        file_list->files[i].img_data.header.w=CONFIG_3MF_THUMBNAIL_WIDTH;
        file_list->files[i].img_data.header.h=CONFIG_3MF_THUMBNAIL_HEIGHT; 
        file_list->files[i].img_data.header.cf=LV_IMG_CF_TRUE_COLOR; 
    }

    file_list->file_count=0;
    file_list->sort_type=SORT_BY_DATA_NEW; 
    file_list->refresh_type=USB_REFRESH_NONE; 
    file_list->show_type=FILE_SHOW_TYPE_NORMAL;

    
    memset(file_list->current_path,0,sizeof(file_list->current_path));  
 
    strlcpy(file_list->current_path,default_path,strlen(default_path)+1);  

    PRINT_UTILS("file_list->current_path=%s",file_list->current_path);

    memset(file_list->files, 0, sizeof(file_list->files));
    //file_list->file_task_msg.task_handle = task_handle; 
    file_list->file_task_msg.magic = NOTIFY_CODE_MSG_MAGIC;

    memset(&file_list->back_folder,0,sizeof(file_gcode_t));
    file_list->back_folder.type=FILE_TYPE_ROOT;
    file_list->back_folder.size=0;  
    file_list->file_3mf_count = 0;

    return 0;
}

void file_3mf_list_arrange(file_list_3mf_t *p_file_list)
{
    if (p_file_list->file_count <= 0)
    { 
        return;
    }

    PRINT_UTILS("sort_type=%02x",p_file_list->sort_type);

    if (SORT_BY_DATA_NEW==p_file_list->sort_type)
    {
        file_sort_by_timestamp(p_file_list->files,p_file_list->file_count,false);
    }
    else if (SORT_BY_DATA_OLD==p_file_list->sort_type)
    {
        file_sort_by_timestamp(p_file_list->files,p_file_list->file_count,true);
    }
    else if (SORT_BY_NAME_A_Z==p_file_list->sort_type)
    {
        file_sort_by_name(p_file_list->files,p_file_list->file_count,false);
    }
    else// if (SORT_BY_NAME_Z_A==p_file_list->sort_type)
    {
        file_sort_by_name(p_file_list->files,p_file_list->file_count,true);
    }
}

void file_3mf_list_free(file_gcode_t * dst, uint32_t max_file_num) {
    for (uint32_t i = 0; i < max_file_num; i++) {
        if (dst[i].name) {
            free(dst[i].name);
            dst[i].name = NULL;
        } 
        if (dst[i].img_data.data 
            //&& PTR_IN_SPIRAM(dst[i].img_data.data)
            )
        {
            free((void *)dst[i].img_data.data);
            dst[i].img_data.data=NULL;
        }
    }
}

bool file_3mf_list_at_root(file_list_3mf_t *p_file_list)
{
    /*如果当前的路径不为/则认为在根目录*/
    if (!strcmp(p_file_list->current_path,"/"))
    {
        return true;
    }

    return false;
}

void ui_screen_create_print_task(const char * filename, uint32_t type) 
{
    PRINT_UTILS("print file[%s] type[%02x]", filename, type);
}

void ui_img_cloud_status_icon_set(lv_obj_t * set_obj, bool set_en) 
{
    if (set_en)
    {
        lv_obj_set_style_bg_img_src(set_obj, &ui_img_cloud_enable_png, LV_PART_MAIN);
    }
    else
    {
        lv_obj_set_style_bg_img_src(set_obj, &ui_img_cloud_disable_png, LV_PART_MAIN);
    }
}

lv_obj_t * ui_panel_create_pwr_data_w(lv_obj_t * parent, const void *img_src, lv_coord_t w)
{
    return NULL;
}

void ui_img_pwr_status_icon_set(lv_obj_t * obj, bool is_online, bool is_valid_mac) 
{
    if (is_valid_mac)
    {
        lv_obj_clear_flag(obj,LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(obj,LV_OBJ_FLAG_HIDDEN);
    }

    if (is_online) 
    {
        lv_obj_set_style_bg_img_src(obj, &ui_img_power_is_on_png, LV_PART_MAIN); 
    }
    else
    {
        lv_obj_set_style_bg_img_src(obj, &ui_img_power_is_off_png, LV_PART_MAIN);
    }
}

void ui_img_mqtt_status_icon_set(lv_obj_t * parent, mqtt_status_t status) {
    switch (status) {
        case MQTT_CONNECTED:
            lv_obj_set_style_bg_img_src(parent, &ui_img_mqtt_connect_png, LV_PART_MAIN);
            break;
        default:
            lv_obj_set_style_bg_img_src(parent, &ui_img_mqtt_disconnect_png, LV_PART_MAIN);
            break;
    }
}

void refresh_udp_background(char *check_sn) 
{
   
}

void file_list_init(void)
{ 
    print_history_file_list = (file_list_history_t *)esp_psram_malloc(sizeof(file_list_history_t));
    memset(print_history_file_list,0,sizeof(file_list_history_t));
    
    print_history_file_list->refresh_type = HISTORY_REFRESH_MAX;
    print_history_file_list->file_count = 1;

    char title[256] = "ball.3mf";  

    strlcpy(print_history_file_list->files[0].title,title,sizeof(title));

    print_history_file_list->files[0].cost_time_s = 11892;
    print_history_file_list->files[0].weight = 3.14;

    print_history_file_list->refresh_type=HISTORY_REFRESH_OK_NORMAL;
}

bool mac_address_is_valid(uint8_t *mac_address)
{
    return false;
}
  
void btn_auto_power_off_clicked(lv_event_t * e)
{

}

void btn_power_off_clicked(lv_event_t * e)
{ 

}

void btn_usb_ctl_clicked(lv_event_t * e)
{

}

void btn_reset_pwr_usage_clicked(lv_event_t * e)
{

}

void notify_update_3mf_preview(void)
{

}

uint32_t xTaskGetTickCount(void)
{
    return get_current_millis();
}

void delay(uint32_t ms)
{
    if (0 == ms)
    {
        ms=1;
    }

    usleep(1000*ms);
}

bool wifi_sync_lock(uint32_t timeout_ms)
{ 
    return true;
}

void wifi_sync_unlock(void)
{ 
    
} 

// 模拟任务创建函数
int xTaskCreate(void *(*task_function)(void *), const char *task_name, TaskParameters_t *parameters, TaskHandle_t *task_handle, int sched_priority) {
    // 创建线程来模拟任务
    pthread_attr_t attr;
    struct sched_param sched_param;
 
    // 初始化线程属性
    pthread_attr_init(&attr);
 
    // 设置线程的调度策略为FIFO
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
 
    // 设置线程的优先级
    sched_param.sched_priority = sched_priority; // 设置为最高优先级
    pthread_attr_setschedparam(&attr, &sched_param);

    int result = pthread_create(task_handle, NULL, task_function, parameters);
    if (result != 0) {
        perror("Task creation failed");
        return -1;
    }
    printf("Task %s created successfully.\n", task_name);
    return 0;
}

// 模拟任务删除函数
void vTaskDelete(TaskHandle_t *task_handle) {
    // 等待线程结束
    pthread_join(*task_handle, NULL);
    printf("Task deleted.\n");
}


// 模拟任务通知等待函数
void ulTaskNotifyTake(TaskNotificationSemaphore_t *notification) {
    // 等待信号量通知
    sem_wait(notification);
}

// 模拟任务通知函数
void xTaskNotifyGive(TaskNotificationSemaphore_t *notification) {
    // 发送信号量通知
    sem_post(notification);
}

void notify_to_account_task(uint32_t set_val)
{ 
    
}

uint32_t ut_strlen(const char *s)
{
    const char *ss = s;

    while (*ss)
        ss++;

    return ss - s;
}

uint8_t ut_str_not_blank(char *p_str)
{
    if (!p_str)
    {
        return 0;
    }

    return (ut_strlen(p_str)?1:0);
} 

uint8_t ut_str_split(char *src,const char *separator,char **dest)
{
     char *p_next;
     uint8_t get_cnt = 0;

     if (src == 0 || ut_strlen(src) == 0)
        return 0;

     if (separator == 0 || ut_strlen(separator) == 0)
        return 0;

     p_next = (char *)strtok(src,separator);

     while(p_next != 0)
     {
         *dest++ = p_next;
         p_next = (char *)strtok(0,separator);
         get_cnt ++;
     }

    return get_cnt;
}

char * ut_strlower(char * str)
{
    int i,len=strlen(str);
    char *pstr=str;

    for(i=0;i<len;i++)
    {
        *pstr=tolower(*pstr);
        pstr++;
    }
    
    return str;
}

size_t strlcpy(char *dst, const char *src, size_t size) 
{
    size_t src_len = strlen(src);

    if (size > 0) {
        size_t copy_len = (src_len >= size) ? size - 1 : src_len;
        memcpy(dst, src, copy_len);
        dst[copy_len] = '\0';  // 确保以空字符结尾
    }

    return src_len;  // 返回源字符串长度
}

static const void *map_ptr = NULL;
//static esp_partition_mmap_handle_t map_handle= NULL;

void * ut_get_map_ptr(void)
{
    return map_ptr;
}

int8_t ut_img_load_from_offset(lv_img_dsc_t * get_dsc_t, uint32_t offset)
{
    if (!get_dsc_t)
    {
        return UT_RES_ERROR;
    }

    get_dsc_t->data = (const uint8_t *)(map_ptr+offset);

    return UT_RES_OK;
}

static int8_t ut_add_static_resource(resource_data_t *data)
{
    if (!data)
    {
        PRINT_UTILS("invalid name or data\r\n");

        return UT_RES_ERROR;
    }  

    if (data->type >= BF_MAX)
    {
        PRINT_UTILS("invalid bin type\r\n");

        return UT_RES_ERROR;
    }  

    lv_img_dsc_t * get_dsc = (lv_img_dsc_t *)data->img_dsc; 

    uint32_t get_offset_data = data->offset;

    memcpy(&get_dsc->header,&data->header,sizeof(lv_img_header_t));

    get_dsc->data_size = data->size;

    if (BF_PNG == data->type)
    { 
        get_offset_data = data->offset+4;
    }

    if (0 > ut_img_load_from_offset(get_dsc,get_offset_data))
    {
        PRINT_UTILS("ut_img_load_from_offset failed\r\n");

        return UT_RES_ERROR;
    } 

    return UT_RES_OK;
} 
 
//static SemaphoreHandle_t lvgl_mux;
extern pthread_mutex_t mutex;

bool lvgl_port_lock(uint32_t timeout_ms)
{  
    pthread_mutex_lock(&mutex);

    return true;
}

void lvgl_port_unlock(void)
{ 
    pthread_mutex_unlock(&mutex);
}

uint32_t ut_get_img_total_size(void)
{
    return get_total_size;
} 
 
bool lang3_is_valid = false;

aht20_data_t g_aht20_data;

// 解析 img 文件的函数
int parse_img_file(uint8_t *ptr_add_file) 
{ 
    // 申请内存来保存整个文件内容
    uint8_t *buffer = ptr_add_file; 
 
    // 检查 magic 值
    uint32_t magic = *(uint32_t *)buffer;
    if (magic != 0xADDF5AA5) {
        PRINT_UTILS("Magic error\n"); 
        return -1;
    }
 
    // 解析文件内容
    uint8_t *ptr = buffer + 4; // 跳过前4字节的 magic
    uint32_t total_files = *(uint32_t *)ptr;
    ptr += 4;

    /*词条总数不能超过现有的，只能少*/
    PRINT_UTILS("total file: %ld\n", total_files);

    // 逐个文件解析
    for (uint32_t i = 0; i < total_files; i++) {
        // 获取文件类型
        uint32_t file_type = *(uint32_t *)ptr;
        ptr += 4;

        // 获取文件大小
        uint32_t current_file_size = *(uint32_t *)ptr;
        ptr += 4;

        PRINT_UTILS("ftype: 0x%X, fsize: %ld\n", (unsigned int)file_type, current_file_size);

        if (file_type == FT_PANDA_PNG) {
            // 如果是 FT_PANDA_PNG，只是打印信息
            PRINT_UTILS(" PNG file\n");
            lv_img_dsc_t * get_dsc = (lv_img_dsc_t *)&ui_img_icon_model_png;  

            memcpy(&get_dsc->header, ptr, sizeof(lv_img_header_t));
            get_dsc->data_size = get_dsc->header.w * get_dsc->header.h * 3;
            PRINT_UTILS(" PNG data_size=%ld\n", get_dsc->data_size);
            get_dsc->data = ptr + sizeof(lv_img_header_t);  
        } else if (file_type == FT_LANGUAGE) {
            // 如果是 FT_LANGUAGE，解析词条 

            volatile uint8_t *lang_data = ptr; // 保存词条数据的位置

            // 第一个 4 字节是词条总数
            uint32_t num_entries = *(uint32_t *)lang_data;
            lang_data += 4;

            // 第二个 4 字节是语言名称的长度
            uint32_t length_language_name = *(uint32_t *)lang_data;
            lang_data += 4;

            // 第三个是语言名称内容
            char *language_name = (char *)esp_psram_malloc(length_language_name + 1);
            memset(language_name,0,length_language_name + 1);
            memcpy(language_name, lang_data, length_language_name);
            language_name[length_language_name] = '\0'; // 确保字符串以 '\0' 结尾
            lang_data += length_language_name;

            PRINT_UTILS("language_name: %s\n", language_name);
            PRINT_UTILS("num_entries: %ld\n", num_entries);

            // 申请存储词条的数组
            lv_i18n_phrase_t *phrases = (lv_i18n_phrase_t *)esp_psram_malloc(num_entries * sizeof(lv_i18n_phrase_t));
            memset(phrases,0,num_entries * sizeof(lv_i18n_phrase_t));

            uint32_t content_length = 0;  

            // 逐个解析词条
            for (uint32_t j = 0; j < num_entries; j++) 
            { 
                // 获取 msg_id
                phrases[j].msg_id = *(uint32_t *)lang_data;
                lang_data += 4;

                // 获取词条长度
                content_length = *(uint32_t *)lang_data;
                lang_data += 4; 

                /*有一些词条 直接在这里跳过 使用默认的英文*/
                if ((K_T_AUTO_OFF == phrases[j].msg_id)
                    || (K_T_POWER_OFF_AFTER_PRINTING == phrases[j].msg_id)
                    || (K_NEW_TIP_GET_INFO == phrases[j].msg_id)
                    || (K_CTL_T_PART == phrases[j].msg_id)
                    || (K_CTL_T_AUX == phrases[j].msg_id)
                    || (K_CTL_T_CHAMBER == phrases[j].msg_id)
                    || (K_NOTIFY_CNT_T == phrases[j].msg_id)
                    )
                { 
                    lang_data += content_length;
                    phrases[j].translation = NULL;  
                    continue; 
                }

                // 动态分配内存来保存翻译字符串 
                char *translation = (char *)esp_psram_malloc(content_length * 2 + 1); // 预留空间给转义字符
                memset(translation,0,content_length * 2 + 1);

                // 将词条内容拷贝到 translation，并处理转义字符
                uint32_t actual_length = 0;
                for (uint32_t k = 0; k < content_length; k++) {
                    if (lang_data[k] == '\\') {
                        // 遇到转义字符时进行处理
                        k++; // 跳过 '\'
                        if (k < content_length) {
                            switch (lang_data[k]) {
                                case 'n':
                                    translation[actual_length++] = '\n'; // 换行符
                                    break;
                                case 't':
                                    translation[actual_length++] = '\t'; // 制表符
                                    break;
                                case '\\':
                                    translation[actual_length++] = '\\'; // 反斜杠
                                    break;
                                case '\"':
                                    translation[actual_length++] = '\"'; // 双引号
                                    break;
                                default:
                                    // 其他情况直接复制字符
                                    translation[actual_length++] = lang_data[k - 1]; // 复制 '\'
                                    translation[actual_length++] = lang_data[k]; // 复制转义字符
                                    break;
                            }
                        }
                    } else {
                        translation[actual_length++] = lang_data[k];
                    }
                }
                
                if (actual_length != content_length)
                {
                    //PRINT_UTILS("actual_length:%ld,content_length:%ld\n",actual_length,content_length);
                }  

                uint32_t total_str_len = actual_length+1;

                translation[total_str_len] = '\0'; // 确保字符串以 '\0' 结尾 

                phrases[j].translation = (const char *)esp_psram_malloc(total_str_len);
                memset(phrases[j].translation,0,total_str_len);

                strlcpy(phrases[j].translation,translation,total_str_len);
                if (K_T_POWER == phrases[j].msg_id)
                {
                    PRINT_UTILS("translation:%s\n",translation);
                    PRINT_UTILS("phrases[j].translation:%s\n",phrases[j].translation);
                }

                free(translation);

                lang_data += content_length;
            }

            // 释放语言名称和 phrases 数组的内存 
            free(language_name);
            custom_singulars=phrases; 
            lang3_is_valid = true;
        }

        // 移动指针到下一个文件
        ptr += current_file_size;
    } 

    return 0;
}

multi_lang_name_t lang_names[3] = {0}; 

int8_t ut_lib_init(uint8_t *p_img_buf)
{
    #define ESP_OK 0

    int res = -1; 

    get_total_size = 0;
    
    PRINT_UTILS("p_img_buf[%x]\r\n",p_img_buf);

    memcpy(&get_total_size,p_img_buf,4);

    PRINT_UTILS("get_total_size[%ld]\r\n",get_total_size);

    if (get_total_size > (CONFIG_PARTITION_SIZE_TOTAL-8))
    {
        PRINT_UTILS("invalid total size[%ld]\r\n",get_total_size);

        return UT_RES_INVALID_FONT_IMG;
    }

    uint32_t get_font_offset = 0;

    memcpy(&get_font_offset,(void *)(p_img_buf+4),4);
  
    PRINT_UTILS("get_font_offset[%ld]\r\n",get_font_offset);

    if ((get_font_offset < 8)
        || (get_font_offset >= get_total_size))
    {
        PRINT_UTILS("invalid font offset[%ld]\r\n",get_font_offset);

        return UT_RES_INVALID_FONT_IMG;
    }

    /*镜像文件的字体在图片资源的后面，这里是获取图片资源的总大小，也就是字体数据的偏移量*/
    font_data_offset = get_font_offset;

    /*check the whole file magic*/
    uint32_t check_magic = 0; 
    
    memcpy(&check_magic,(void *)(p_img_buf+get_total_size+4),4);
   
    if (check_magic != CONFIG_FILE_MAGIC)
    { 
       PRINT_UTILS("invalid magic[%x]\r\n",(unsigned int)check_magic);

        return UT_RES_INVALID_FONT_IMG;
    }

    /*compare the crc32 (firmware's and partition size-8)*/
    uint32_t check_crc = 0; 
    
    memcpy(&check_crc,(void *)(p_img_buf+get_total_size),4); 
 
    if (CONFIG_FILE_SYSTEM_CRC != check_crc)
    {
        PRINT_UTILS("get check_crc[%x],CRC[%x]\r\n",(unsigned int)check_crc,(unsigned int)CONFIG_FILE_SYSTEM_CRC);

        return UT_RES_INVALID_FONT_IMG;
    }

    /*从0开始映射整个分区*/
    map_ptr = p_img_buf;
    PRINT_UTILS("map_ptr start[%x]\r\n",map_ptr);

    map_ptr+=8;
    
    /*图片资源从第8个字节开始*/
    // /*添加所有图片资源*/
    for (uint8_t idx=0; idx<LENGTH_OF_ARRAY(resource_bin_files); idx++)
    {
        if (UT_RES_ERROR == ut_add_static_resource(&resource_bin_files[idx]))
        {
            PRINT_UTILS("add resource error[%x]\r\n",(unsigned int)resource_bin_files[idx].offset);
        }
    } 

    rs_lang_init();
 
    const void *ptr_img_add_file = map_ptr-8;

    /*检查是否有附加文件*/
    /*附加文件一般在CRC32的后面一个扇区*/ 
    uint32_t page_index = (((ut_get_img_total_size()+4)/CONFIG_SECTOR_SIZE)+1);

    uint32_t get_pos_page = page_index*CONFIG_SECTOR_SIZE;

    PRINT_UTILS("get_pos_page[%x]\r\n",(unsigned int)get_pos_page);

    uint32_t add_file_magic = 0;
    uint32_t add_file_cnt = 0; 

    memcpy(&add_file_magic,(void *)(ptr_img_add_file+get_pos_page),4);
    memcpy(&add_file_cnt,(void *)(ptr_img_add_file+get_pos_page+4),4);

    PRINT_UTILS("add_file_magic[%x]\r\n",(unsigned int)add_file_magic); 
    PRINT_UTILS("add_file_cnt[%ld]\r\n",add_file_cnt); 

    if (CONFIG_ADD_FILE_MAGIC != add_file_magic)
    {
        return UT_RES_OK;
    } 

    if (add_file_cnt > CONFIG_ADD_FILE_MAX_CNT)
    {
        return UT_RES_OK;
    }

    parse_img_file((void *)(ptr_img_add_file+get_pos_page)); 

    if (false == lang3_is_valid)
    {
        if (LANG_3 == g_language)
        {
            /*暂时不保存设置*/
            g_language = LANG_1;

            rs_set_local(g_language);
        }

        PRINT_UTILS("not find custom language\r\n"); 
    }
    else
    {  
        /*填充各个语言名称*/ 
        rs_set_local_only(LANG_3); 
        sprintf(lang_names[2].name,"%s",RS_TRANSLATE(K_LANG_NAME_T));
        PRINT_UTILS("update lang2 name[%s]\r\n",lang_names[2].name);
        rs_set_local_only(g_language);
    }

    return UT_RES_OK;
}

extern lv_font_t * font_16_fname;
 
void file_sort_by_timestamp(file_gcode_t *file, int32_t count, bool reversed)
{
    if (count > 1)
    {
        for (uint8_t i=0; i<count-1; i++)
        {
            for (uint8_t j=0; j<count-1-i; j++)
            { 
                bool check_type = (file[j].timestamp < file[j+1].timestamp);
                if (reversed)
                {
                    check_type = (file[j].timestamp > file[j+1].timestamp);
                }
                if (check_type)
                {
                    file_gcode_t temp = {0};
                    memcpy(&temp,&file[j],sizeof(file_gcode_t));
                    memcpy(&file[j],&file[j+1],sizeof(file_gcode_t));
                    memcpy(&file[j+1],&temp,sizeof(file_gcode_t));
                }
            }
        } 
    } 
}

#define MAX_FILENAME_LEN 255

void utf8_to_lower(char *str) 
{
    while (*str) 
    {
        if ((*str & 0x80) == 0) 
        {
            // ASCII character
            *str = tolower(*str);
        }
        // Skip continuation bytes
        str++;
    }
}

int compare_ascending(const void *a, const void *b) 
{
    char lower_a[MAX_FILENAME_LEN];
    char lower_b[MAX_FILENAME_LEN];

    strlcpy(lower_a, ((file_gcode_t *)a)->name, MAX_FILENAME_LEN);
    strlcpy(lower_b, ((file_gcode_t *)b)->name, MAX_FILENAME_LEN);

    utf8_to_lower(lower_a);
    utf8_to_lower(lower_b);

    return strcmp(lower_a, lower_b);
}

int compare_descending(const void *a, const void *b) 
{
    char lower_a[MAX_FILENAME_LEN];
    char lower_b[MAX_FILENAME_LEN];

    strlcpy(lower_a, ((file_gcode_t *)a)->name, MAX_FILENAME_LEN);
    strlcpy(lower_b, ((file_gcode_t *)b)->name, MAX_FILENAME_LEN);

    utf8_to_lower(lower_a);
    utf8_to_lower(lower_b);

    return strcmp(lower_b, lower_a);
}


void file_sort_by_name(file_gcode_t *file, int32_t count, bool reversed)
{
    if (count > 1)
    {
        if (reversed) 
        {
            qsort(file, count, sizeof(file_gcode_t), compare_descending);
        } 
        else 
        {
            qsort(file, count, sizeof(file_gcode_t), compare_ascending);
        }
    } 
}

uint32_t ftime_2_timestamp(file_time_t ftime) 
{
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));
 
    tm.tm_year = ftime.year;
    tm.tm_mon = ftime.month;
    tm.tm_mday = ftime.day;
    tm.tm_hour = ftime.hour;
    tm.tm_min = ftime.min;
    tm.tm_sec = ftime.sec;

    // Adjust values to match the tm structure requirements
    if (tm.tm_year)
    {
        tm.tm_year -= 1900;//Year since 1900
    }
    else
    {
        tm.tm_year += 124+30;//由于无法获取到具体时间只能让其变成比较大的数 2024往后加30年
    }

    tm.tm_mon -= 1;     // Months are 0-11

    // Convert to time_t (timestamp)
    time_t timestamp = mktime(&tm);

    return (uint32_t)timestamp;
}

void ut_convert_color_depth(uint8_t * img, uint32_t px_cnt)
{
    lv_color32_t * img_argb = (lv_color32_t *)img;
    lv_color_t c;
    uint32_t i;
    for(i = 0; i < px_cnt; i++) {
        c = lv_color_make(img_argb[i].ch.blue, img_argb[i].ch.green, img_argb[i].ch.red);
        img[i * 3 + 2] = img_argb[i].ch.alpha;
        img[i * 3 + 1] = c.full >> 8;
        img[i * 3 + 0] = c.full & 0xFF;
    }
}

void ut_convert_color_depth_blend(uint8_t *out_img, uint8_t *src_img, uint16_t width, uint16_t height, uint32_t bg_color)
{
    uint8_t *s = src_img; 
    uint32_t i;
    int x, j;
    uint16_t usPixel, *pDest = out_img;

    for(i = 0; i < height; i++) 
    {
        if (bg_color != 0xffffffff) 
        { // user wants to blend it with a background color
            uint32_t r, g, b, a;
            uint32_t b_r, b_g, b_b;
            b_r = bg_color & 0xff; b_g = (bg_color & 0xff00) >> 8;
            b_b = (bg_color >> 16) & 0xff;
            uint16_t u16Clr = (bg_color & 0xf8) << 8;
            u16Clr |= ((bg_color & 0xfc00) >> 5);
            u16Clr |= ((bg_color & 0xf80000) >> 19);

            for (uint16_t x=0; x<width; x++) 
            {
                r = s[0]; g = s[1]; b = s[2]; a = s[3];
                if (a == 0)
                    usPixel = u16Clr;
                else if (a == 255) { // fully opaque
                    usPixel = (s[2] >> 3); // blue
                    usPixel |= ((s[1] >> 2) << 5); // green
                    usPixel |= ((s[0] >> 3) << 11); // red
                } else { // mix the colors
                    r = ((r * a) + (b_r * (255-a))) >> 8;
                    g = ((g * a) + (b_g * (255-a))) >> 8;
                    b = ((b * a) + (b_b * (255-a))) >> 8;
                    usPixel = (b >> 3); // blue
                    usPixel |= ((g >> 2) << 5); // green
                    usPixel |= ((r >> 3) << 11); // red
                }
                
                *pDest++ = usPixel;
                s += 4; // skip alpha
            }
        }
    }
}

void ut_convert_color_depth_blend_resize(uint8_t *out_img, uint8_t *src_img, uint16_t width, uint16_t height, uint16_t new_width, uint16_t new_height, uint32_t bg_color)
{
    uint8_t *s = src_img; 
    uint32_t i;
    int x, j;
    uint16_t usPixel, *pDest = out_img;
  
    uint32_t r, g, b, a;
    uint32_t b_r, b_g, b_b;
    b_r = bg_color & 0xff; b_g = (bg_color & 0xff00) >> 8;
    b_b = (bg_color >> 16) & 0xff;
    uint16_t u16Clr = (bg_color & 0xf8) << 8;
    u16Clr |= ((bg_color & 0xfc00) >> 5);
    u16Clr |= ((bg_color & 0xf80000) >> 19); 

    int x_ratio = (width << 16) / new_width + 1;
    int y_ratio = (height << 16) / new_height + 1;
  
    for (int j = 0; j < new_height; j++) 
    { 
        for (int i = 0; i < new_width; i++)
        {
            int x = (i * x_ratio) >> 16;
            int y = (j * y_ratio) >> 16;
 
            uint8_t r = src_img[(y * width + x) * 4 + 0];
            uint8_t g = src_img[(y * width + x) * 4 + 1];
            uint8_t b = src_img[(y * width + x) * 4 + 2];
            uint8_t a = src_img[(y * width + x) * 4 + 3]; 

            if (a == 0)
                usPixel = u16Clr;
            else if (a == 255) { // fully opaque
                usPixel = (b >> 3); // blue
                usPixel |= ((g >> 2) << 5); // green
                usPixel |= ((r >> 3) << 11); // red
            } else { // mix the colors
                r = ((r * a) + (b_r * (255-a))) >> 8;
                g = ((g * a) + (b_g * (255-a))) >> 8;
                b = ((b * a) + (b_b * (255-a))) >> 8;
                usPixel = (b >> 3); // blue
                usPixel |= ((g >> 2) << 5); // green
                usPixel |= ((r >> 3) << 11); // red
            }
            
            //*pDest++ = usPixel;

            //s += 4; // skip alpha
 
            out_img[(j * new_width + i) * 2 + 0] = usPixel & 0xFF;        
            out_img[(j * new_width + i) * 2 + 1] = (usPixel >> 8) & 0xFF;  
        } 
    }
}

void resize_rgb565(uint8_t *input, uint8_t *output, int orig_width, int orig_height, int new_width, int new_height) 
{ 
    // Resize the input image to the output image
    for (int y = 0; y < new_height; y++) 
    {
        for (int x = 0; x < new_width; x++) 
        {
            // Calculate the corresponding pixel in the source image
            int srcX = x * orig_width / new_width;
            int srcY = y * orig_height / new_height;

            // Get the source pixel index
            int srcIndex = (srcY * orig_width + srcX) * 2; // 2 bytes per pixel

            // Copy the pixel from the source to the destination
            output[(y * new_width + x) * 2 + 0] = input[srcIndex + 0]; // 
            output[(y * new_width + x) * 2 + 1] = input[srcIndex + 1]; // 
        }
    } 
}