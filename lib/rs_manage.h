#ifndef RS_MANAGE_H
#define RS_MANAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>   
     
#define CONFIG_UPDATE_FILE_SUFFIX                       ".img"  
#define CONFIG_FAT_FILE_PRE_FIX                         "fat"   
#define CONFIG_PARTITION_SUBTYPE_DATA_FONT              0x40
#define CONFIG_FILE_READ_BUFFER_SIZE                    4096
#define CONFIG_FILE_MAGIC                               0X5AA5
 
typedef enum
{
    UFILE_FAT=0,
    UFILE_FONT,
    UFILE_TABLE,
    UFILE_MAX,
}update_file_type_t; 

typedef enum
{
    RS_TYPE_IMAGE,
    RS_TYPE_FONT,
    RS_TYPE_MAX,
}resource_idx_t;
  
  
typedef enum
{
    BF_PNG,
    BF_GIF,
    BF_MAX,
}bin_file_t;

typedef struct 
{ 
    uint32_t header;
    uint32_t offset;
    uint32_t size;
    uint8_t type;
    const lv_img_dsc_t *img_dsc; 
}resource_data_t;

typedef struct
{
    lv_img_dsc_t dsc;
    lv_obj_t *p_obj;
}img_data_t;

typedef struct
{
    uint32_t draw_cnt;
    uint16_t x0;
    uint16_t y0;
    uint16_t x;
    uint16_t y;
    uint16_t color;
}lcd_draw_t;
  
  
extern int8_t rs_add_static_resource(resource_data_t *data);
   
extern void rs_update_file_task(void *pvParameters);
   

extern void rs_notify_reboot(void); 
extern void rs_notify_exit_task(void); 
extern void rs_notify_updating(uint8_t); 

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*RS_RESOURCE_H*/
