

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>  
#include <dirent.h>
#include <sys/stat.h> 
#include <time.h>
#include <unistd.h>

#define LENGTH_OF_ARRAY(A) sizeof(A)/sizeof(A[0])

#define CONFIG_FN_LENGTH_MAX            60
#define CONFIG_CRC32_POLY               0x04C11DB7
#define CONFIG_CRC32_INIT_VALUE         0xFFFFFFFF
#define CONFIG_CRC32_OUT_XOR            0x00000000
#define CONFIG_CRC32_REFLECTION_IN      0
#define CONFIG_CRC32_REFLECTION_OUT     0 
#define CONFIG_SPI_FLASH_SEC_SIZE       4096
#define CONFIG_IMAGE_SIZE_MAX           (0x6E0000-8)

#define DEBUGE_SW_APP_MAIN 1

#define INPUT_PATH "inputfiles" 
  
typedef struct
{
    char dir_root[CONFIG_FN_LENGTH_MAX]; 
    uint8_t fn_fat[CONFIG_FN_LENGTH_MAX]; 
    uint8_t fn_font_fname[CONFIG_FN_LENGTH_MAX];/*enc+crc*/
    uint8_t dir_font_other[CONFIG_FN_LENGTH_MAX];/*app+crc*/
    uint8_t dir_spiffs[CONFIG_FN_LENGTH_MAX];
}combine_file_t;

static combine_file_t combine_file;
uint8_t get_debug_switch = 0;
FILE *file_debug = NULL;
FILE *file_out_copy = NULL;

uint32_t crc32_customized(uint32_t crc_poly,uint32_t crc_init_value,uint32_t out_xor_value,uint8_t *source,uint32_t length)
{
    uint32_t crc_value = crc_init_value;

    for (int i =0; i < length; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            uint8_t get_bit_value = ((source[i] >> (7 - j) & 1) == 1);
            uint8_t get_value = ((crc_value >> 31 & 1) == 1);

            crc_value <<= 1;

            if (get_value ^ get_bit_value)
            {
                crc_value ^= crc_poly;
            }
        }
    }

    crc_value &= 0xFFFFFFFF;

    return (crc_value ^= out_xor_value);
}

typedef struct{
    uint16_t min;
    uint16_t max;
    uint32_t offset;
}x_header_info_t;

#define CONFIG_MAX_CNT_FONT 5

x_header_info_t *get_head_info = NULL;

#if 1
typedef struct{
    uint16_t min;
    uint16_t max;
    uint8_t  bpp;
    uint8_t  reserved[3];
}x_header_t;

typedef struct{
    x_header_info_t info;
    char fname[32];
    uint32_t size;
    uint8_t data[];
}x_header_file_t;

x_header_file_t *head_other_fonts[CONFIG_MAX_CNT_FONT] = {0};
static uint16_t font_cnt_other = 0; 
static uint32_t font_fsize_offset = 0; 

uint8_t add_head_info(x_header_file_t *head_info)
{
    if (font_cnt_other < CONFIG_MAX_CNT_FONT)
    {
        head_other_fonts[font_cnt_other] = head_info;
        font_cnt_other++;  

        return 1;  
    }
    else
    {
        return 0;
    }
}

void list_head_info(void)
{
    x_header_file_t *head_file= NULL;

    for (uint8_t i=0; i<CONFIG_MAX_CNT_FONT; i++)
    {
        head_file = head_other_fonts[i];

        if (NULL != head_file)
        {
            printf("fname=%s,min=%x,max=%x,offset=%x\n",head_file->fname,head_file->info.min,head_file->info.max,head_file->info.offset); 
        }
    } 
}

uint32_t get_font_total_size(void)
{
    uint32_t get_size = 0;

    x_header_file_t *head_file= NULL;

    for (uint8_t i=0; i<font_cnt_other; i++)
    {
        head_file = head_other_fonts[i];

        if (NULL != head_file)
        {  
            get_size += head_file->size; 
        }
    }

    printf("font_fsize_total=%d\n",get_size);

    return get_size;
}

void generate_head_info_c_array(void)
{
    x_header_info_t * p_head_info = get_head_info;

    for (uint8_t idx=0; idx<font_cnt_other; idx++)
    {
        x_header_file_t *head_other = head_other_fonts[idx];

        if (NULL != head_other)
        { 
            printf("#define CONFIG_EXT_FONT_OFFSET_%s (CONFIG_EXT_FONT_OFFSET_FNAME+0x%08x) \n",head_other->fname,(head_other->info.offset));
        } 
    }  
 
    printf("\n");
    //printf("const x_header_check_t partition_head_info[] = \n");
    printf("#define FONT_RESOURCE \\\n");
    printf("{\\\n");

    for (uint8_t idx=0; idx<1; idx++)
    {
        printf("    {\\\n");
        printf("        .min=0x%04x, \\\n",p_head_info->min);
        printf("        .max=0x%04x, \\\n",p_head_info->max); 
        printf("        .offset=%d, \\\n",0); 
        printf("    }, \\\n");
        p_head_info++;
    }
  
    for (uint8_t idx=0; idx<font_cnt_other; idx++)
    {
        x_header_file_t *head_other = head_other_fonts[idx];

        if (NULL != head_other)
        { 
            printf("    {\\\n");
            printf("        .min=0x%04x, \\\n",head_other->info.min);
            printf("        .max=0x%04x, \\\n",head_other->info.max); 
            printf("        .offset=CONFIG_EXT_FONT_OFFSET_%s, \\\n",head_other->fname);  
            printf("    }, \\\n"); 
        } 
    } 

    printf("}\n"); 
    
    //printf("const x_header_check_t partition_head_info[] = FONT_RESOURCE;\n"); 
}

void free_head_info(void)
{ 
    for (uint8_t i=0; i<CONFIG_MAX_CNT_FONT; i++)
    { 
        if (NULL != head_other_fonts[i])
        {
            free(head_other_fonts[i]);
        }
    } 
}

uint8_t min_max_is_valid(uint16_t min, uint16_t max)
{
    if (min < 0x20)
    {
        return 0;
    }

    if (max < min)
    {
        return 0;
    }

    return 1;
}

uint8_t bpp_is_valid(uint8_t bpp)
{
    if ((bpp != 1)
        || (bpp != 2)
        || (bpp != 4)
        || (bpp != 8))
    {
        return 0;
    }

    return 1;
}

void find_font(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    FILE *pf = NULL;
    x_header_file_t *new_header_file = NULL;

    // 打开目录
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("can not open dir\n");
        return;
    }

    // 循环读取目录
    while ((entry = readdir(dir)) != NULL)
    {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        if (stat(file_path, &statbuf) == -1)
        {
            continue;
        }
        
        if (S_ISREG(statbuf.st_mode))
        {
            const char *pFile = strrchr(entry->d_name, '.'); // 判断输入的文件名最后输出.的位置
            
            if (pFile != NULL)
            { 
                printf("font name=%s\n",entry->d_name);

                if (strcmp(pFile, ".bin") == 0)
                { 
                    pf = fopen(file_path,"r");
 
                    if (NULL != pf)
                    {
                        x_header_t check_data={0};

                        int br = fread(&check_data,1,sizeof(x_header_t),pf);
 
                        if (br != sizeof(x_header_t))
                        {
                            continue;
                        }

                        /*check the min and max*/
                        if (!min_max_is_valid(check_data.min,check_data.max))
                        {
                            printf("min=%x,max=%x\r\n",check_data.min,check_data.max);

                            continue;
                        }

                        /*check the bpp*/
                        if (bpp_is_valid(check_data.bpp))
                        {
                            printf("bpp=%d\r\n",check_data.bpp);

                            continue;
                        } 

                        fseek(pf, 0, SEEK_END);

                        uint32_t get_fsize= ftell(pf); 
 
                        rewind(pf);

                        new_header_file = (x_header_file_t *) malloc(sizeof(x_header_info_t) + sizeof(new_header_file->size) + (32) + get_fsize);

                        if (NULL == new_header_file)
                        {
                            goto err_handle;
                        }

                        new_header_file->size = get_fsize;

                        x_header_info_t *new_head_info = &new_header_file->info;

                        /*set head info*/ 
                        new_head_info->min = check_data.min;
                        new_head_info->max = check_data.max;
                        new_head_info->offset = font_fsize_offset;

                        char *get_fname =strtok(entry->d_name,".");

                        sprintf(new_header_file->fname,"%s",get_fname);
                        
                        int byte_read = fread(new_header_file->data,1,get_fsize,pf);

                        if (0 == add_head_info(new_header_file))
                        {
                            if (new_header_file)
                            {
                                free(new_header_file);
                            }
                            
                            fclose(pf);

                            goto err_handle;
                        }
 
                        font_fsize_offset += get_fsize; 

                        fclose(pf);

                        //printf("add file[%s] ok,byte_read=[%d]\r\n",file_path,byte_read);
                        if (get_debug_switch > 0)
                        {
                            for (int i=0; i<8; i++)
                            {
                                printf("%02x ",new_header_file->data[i]);
                            }
                        } 
                    }
                }
            }

            printf("\n");
        }
    }

    err_handle:
 
    closedir(dir);
}

enum {
    LV_IMG_CF_UNKNOWN = 0,

    LV_IMG_CF_RAW,              /**< Contains the file as it is. Needs custom decoder function*/
    LV_IMG_CF_RAW_ALPHA,        /**< Contains the file as it is. The image has alpha. Needs custom decoder
                                   function*/
    LV_IMG_CF_RAW_CHROMA_KEYED, /**< Contains the file as it is. The image is chroma keyed. Needs
                                   custom decoder function*/

    LV_IMG_CF_TRUE_COLOR,              /**< Color format and depth should match with LV_COLOR settings*/
    LV_IMG_CF_TRUE_COLOR_ALPHA,        /**< Same as `LV_IMG_CF_TRUE_COLOR` but every pixel has an alpha byte*/
    LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED, /**< Same as `LV_IMG_CF_TRUE_COLOR` but LV_COLOR_TRANSP pixels
                                          will be transparent*/

    LV_IMG_CF_INDEXED_1BIT, /**< Can have 2 different colors in a palette (can't be chroma keyed)*/
    LV_IMG_CF_INDEXED_2BIT, /**< Can have 4 different colors in a palette (can't be chroma keyed)*/
    LV_IMG_CF_INDEXED_4BIT, /**< Can have 16 different colors in a palette (can't be chroma keyed)*/
    LV_IMG_CF_INDEXED_8BIT, /**< Can have 256 different colors in a palette (can't be chroma keyed)*/

    LV_IMG_CF_ALPHA_1BIT, /**< Can have one color and it can be drawn or not*/
    LV_IMG_CF_ALPHA_2BIT, /**< Can have one color but 4 different alpha value*/
    LV_IMG_CF_ALPHA_4BIT, /**< Can have one color but 16 different alpha value*/
    LV_IMG_CF_ALPHA_8BIT, /**< Can have one color but 256 different alpha value*/

    LV_IMG_CF_RGB888,
    LV_IMG_CF_RGBA8888,
    LV_IMG_CF_RGBX8888,
    LV_IMG_CF_RGB565,
    LV_IMG_CF_RGBA5658,
    LV_IMG_CF_RGB565A8,

    LV_IMG_CF_RESERVED_15,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_16,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_17,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_18,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_19,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_20,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_21,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_22,              /**< Reserved for further use.*/
    LV_IMG_CF_RESERVED_23,              /**< Reserved for further use.*/

    LV_IMG_CF_USER_ENCODED_0,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_1,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_2,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_3,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_4,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_5,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_6,          /**< User holder encoding format.*/
    LV_IMG_CF_USER_ENCODED_7,          /**< User holder encoding format.*/
};

typedef struct {

    uint32_t cf : 5;          /*Color format: See `lv_img_color_format_t`*/
    uint32_t always_zero : 3; /*It the upper bits of the first byte. Always zero to look like a
                                 non-printable character*/

    uint32_t reserved : 2; /*Reserved to be used later*/

    uint32_t w : 11; /*Width of the image map*/
    uint32_t h : 11; /*Height of the image map*/
} lv_img_header_t;

#define CONFIG_MAX_CNT_RS_FILE 100

typedef enum
{
    BF_PNG,
    BF_GIF,
    BF_MAX,
}bin_file_t;

typedef struct
{
    char fname[32];
    uint8_t type;
    uint32_t offset;
    uint32_t size;
    lv_img_header_t header;
}rs_file_info_t;

typedef struct
{ 
    rs_file_info_t info;
    uint8_t data[];
}rs_file_t;

rs_file_t *rs_files[CONFIG_MAX_CNT_RS_FILE] = {0};
static uint16_t rs_file_cnt = 0; 
static uint32_t rs_file_offset = 0; 

uint8_t rs_file_add(rs_file_t *p_rs_file)
{
    if (rs_file_cnt < CONFIG_MAX_CNT_RS_FILE)
    {
        rs_files[rs_file_cnt] = p_rs_file;
        rs_file_cnt++;  

        return 1;  
    }
    else
    {
        return 0;
    }
}

void rs_file_list(void)
{
    rs_file_t *p_rs_file = NULL;

    for (uint8_t i=0; i<CONFIG_MAX_CNT_RS_FILE; i++)
    {
        p_rs_file = rs_files[i];

        if (NULL != p_rs_file)
        {
            printf("fname=%s,ftype=%d,offset=0x%08x\n",p_rs_file->info.fname,p_rs_file->info.type,p_rs_file->info.offset); 
        }
    } 
}

uint32_t rs_file_get_total_size(void)
{
    uint32_t get_size = 0;

    rs_file_t *p_rs_file= NULL;

    for (uint8_t i=0; i<rs_file_cnt; i++)
    {
        p_rs_file = rs_files[i];

        if (NULL != p_rs_file)
        {  
            get_size += p_rs_file->info.size; 
        }
    }

    printf("rs_file_total=%d\n",get_size);

    return get_size;
}

void rs_file_free(void)
{ 
    for (uint8_t i=0; i<CONFIG_MAX_CNT_RS_FILE; i++)
    { 
        if (NULL != rs_files[i])
        {
            free(rs_files[i]);
        }
    } 
}

int8_t rs_file_combine(const char *fname, uint32_t fsize)
{
    if (!fname)
    {
        return -1;
    } 
    
    uint8_t *data_buffer = NULL; 
      
    FILE *p_file_out = fopen(fname,"wb+");

    if (!p_file_out)
    { 
        printf("open src file [%s] error \r\n",fname);

        goto error_file_combine;
    }

    data_buffer = (uint8_t *)malloc(fsize);

    if (!data_buffer)
    {
        printf("buffer malloc error\r\n");

        goto error_file_combine;
    }
 
    rs_file_t *p_rs_file = NULL;

    for (uint8_t i=0; i<CONFIG_MAX_CNT_RS_FILE; i++)
    {
        p_rs_file = rs_files[i];

        if (NULL != p_rs_file)
        { 
            memcpy(&data_buffer[p_rs_file->info.offset],p_rs_file->data,p_rs_file->info.size); 
        }
    } 

    fwrite(data_buffer,1,fsize,p_file_out);
 
    fclose(p_file_out); 
 
    return 0;

    error_file_combine:

    if (data_buffer)
    {
        free(data_buffer);
    } 

    if (p_file_out)
    {
        fclose(p_file_out);
    }

    return -1;
}

void rs_file_search(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    FILE *pf = NULL;
    rs_file_t *new_rs_file = NULL;

    // 打开目录
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("can not open dir [%s]\n",path);
        return;
    }

    // 循环读取目录
    while ((entry = readdir(dir)) != NULL)
    {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        if (stat(file_path, &statbuf) == -1)
        {
            continue;
        }
        
        if (S_ISREG(statbuf.st_mode))
        {
            const char *pFile = strrchr(entry->d_name, '.'); // 判断输入的文件名最后输出.的位置
            
            if (pFile != NULL)
            { 
                printf("rs file name=%s\n",entry->d_name);

                if ((strcmp(pFile, ".bin") == 0)
                    || (strcmp(pFile, ".gif") == 0))
                { 
                    uint8_t get_ftype = BF_PNG;

                    if (0 == strcmp(pFile, ".gif"))
                    {
                        get_ftype = BF_GIF;
                    } 

                    pf = fopen(file_path,"r");
 
                    if (NULL != pf)
                    {
                        lv_img_header_t check_header={0};

                        if (BF_PNG == get_ftype)
                        {
                            int br = fread(&check_header,1,sizeof(lv_img_header_t),pf);
    
                            if (br != sizeof(lv_img_header_t))
                            {
                                printf("png file check failed[%s]\n",entry->d_name);

                                continue;
                            } 

                            if (LV_IMG_CF_TRUE_COLOR_ALPHA != check_header.cf)
                            {
                                printf("png file check failed[%s]\n",entry->d_name);

                                continue;
                            }
                        }
                        else if (BF_GIF== get_ftype)
                        { 
                            char GIF_HEAD_INFO[]="GIF8";

                            char check_data[5]={0};

                            int br = fread(check_data,1,sizeof(check_data),pf);

                            if (br != sizeof(check_data))
                            {
                                printf("gif file check failed read size[%s]\n",entry->d_name);

                                continue;
                            }

                            if (0 != strncmp(check_data,GIF_HEAD_INFO,strlen(GIF_HEAD_INFO)))
                            {
                                printf("gif file check failed compare data[%s],data[%s]\n",entry->d_name,check_data);

                                continue;
                            }

                            check_header.cf = LV_IMG_CF_RAW_CHROMA_KEYED;
                        }

                        fseek(pf, 0, SEEK_END);

                        uint32_t get_fsize = ftell(pf); 
 
                        rewind(pf);

                        new_rs_file = (rs_file_t *) malloc(sizeof(rs_file_info_t) + get_fsize);

                        if (NULL == new_rs_file)
                        {
                            goto err_handle_rs_file;
                        } 

                        rs_file_info_t *new_info = &new_rs_file->info;

                        char *get_fname =strtok(entry->d_name,".");

                        sprintf(new_info->fname,"%s",get_fname);

                        new_info->type = get_ftype;
                        new_info->size = get_fsize;
                        memcpy(&new_info->header,&check_header,sizeof(lv_img_header_t));
                        /*set head info*/  
                        new_info->offset = rs_file_offset;
                        
                        int byte_read = fread(new_rs_file->data,1,get_fsize,pf);

                        if (0 == rs_file_add(new_rs_file))
                        {
                            if (new_rs_file)
                            {
                                free(new_rs_file);
                            }
                            
                            fclose(pf);

                            goto err_handle_rs_file;
                        }
 
                        rs_file_offset += get_fsize; 

                        fclose(pf);

                        printf("add file[%s] ok,byte_read=[%d]\r\n",file_path,byte_read);

                        if (get_debug_switch > 0)
                        {
                            for (int i=0; i<8; i++)
                            {
                                printf("%02x ",new_rs_file->data[i]);
                            }
                        } 
                    }
                }
            }

            printf("\n");
        }
    }

    err_handle_rs_file:
 
    closedir(dir);
}

void generate_rs_file_c_array(void)
{
    printf("\n");
    printf("#define PICTURE_RESOURCE \\\n");
    printf("{\\\n");
 
    for (uint8_t idx=0; idx<rs_file_cnt; idx++)
    {
        rs_file_t *p_rs_file = rs_files[idx];
 
        if (NULL != p_rs_file)
        { 
            printf("    {");
            uint32_t get_header = 0;

            memcpy(&get_header,&p_rs_file->info.header,sizeof(lv_img_header_t));
            
            printf("0x%08x,",get_header);
 
            printf("0x%08x,",p_rs_file->info.offset);

            printf("0x%08x,",p_rs_file->info.size);

            if (BF_PNG == p_rs_file->info.type)
            {
                printf("BF_PNG,");
                printf("&ui_img_%s_png",p_rs_file->info.fname);
            }
            else if (BF_GIF == p_rs_file->info.type)
            {
                printf("BF_GIF,");
                printf("&gif_%s",p_rs_file->info.fname);
            }

            printf("}, \\\n"); 
        } 
    } 

    printf("}\n"); 
 
    //printf("const resource_data_t resource_bin_files[] = PICTURE_RESOURCE;\n");  
}

int8_t file_to_buffer(char *fname, uint32_t *out_fsize, uint8_t **out_buffer)
{
    if (!fname)
    {
        return -1;
    } 
    
    uint8_t *data_buffer = NULL;
       
    FILE *p_file_input = fopen(fname,"rb+");

    if (!p_file_input)
    { 
        printf("open src file [%s] error \r\n",fname);

        goto error_file_to_buffer;
    }

    fseek(p_file_input, 0, SEEK_END);

    uint32_t fsize = ftell(p_file_input);

    if (get_debug_switch > 0)
    {
        printf("file size=%d\r\n",fsize);
    } 

    if (0 == fsize)
    {
        printf("file size invalid=%d\r\n",fsize);

        goto error_file_to_buffer;
    }

    data_buffer = (uint8_t *)malloc(sizeof(uint8_t)*fsize);

    if (!data_buffer)
    {
        printf("buffer malloc error\r\n");

        goto error_file_to_buffer;
    }

    fseek(p_file_input, 0L, SEEK_SET);

    fread(data_buffer,1,fsize,p_file_input);
 
    fclose(p_file_input); 

    if (out_fsize)
    {
        *out_fsize = (fsize);
    }  

    *out_buffer = data_buffer;

    return 0;

    error_file_to_buffer:

    if (data_buffer)
    {
        free(data_buffer);
    } 

    if (p_file_input)
    {
        fclose(p_file_input);
    }

    return -1;
}



int main(int argc,char *argv[])
{
    printf("argc=%d\n",argc);

    /*
    debug switch 
    fname font size,if size is 0 then size set the real size
    fat input fname such as spiffs.bin
    font-fname's name such fname.bin
    other-font's name such 16_24_font.bin 
    */
    if (argc == 7)
    {   
        get_debug_switch = atoi(argv[1]);
        sprintf(combine_file.dir_root,"%s",argv[2]);
        sprintf(combine_file.fn_fat,"%s",argv[3]);
        sprintf(combine_file.fn_font_fname,"%s",argv[4]);
        sprintf(combine_file.dir_font_other,"%s",argv[5]); 
        sprintf(combine_file.dir_spiffs,"%s",argv[6]);
        
        for (int i=1; i<argc; i++)
        {
            printf("arg[%d]=%s\n",i,argv[i]);
        }

        if (1 == get_debug_switch)
        { 
            file_debug = freopen("log.txt", "w",stdout); 
        }
    }
    else
    {
        printf("arg cnt error\n");

        return -1;
    } 
     
    FILE *p_src_font_fname=NULL;/*font_fname.bin*/  
    FILE *p_out_font_crc=NULL;/*font-xxxx.img*/
    FILE *p_out_filesystem_img=NULL;/*fat_font.img*/ 

    uint32_t get_fat_size = 0; 
    uint32_t get_partition_img_size = 0; 
    uint8_t *out_buffer_fat=NULL;
    char out_fname_partition_img[32]={0}; 

    time_t t = time(NULL);
    struct tm* timeinfo = localtime(&t);

    if (!combine_file.dir_root)
    {
        printf("please set a root path\n");

        return -1;
    }

    chdir(combine_file.dir_root);

    rs_file_search(combine_file.dir_spiffs);
    rs_file_list();
    uint32_t get_total_size_spiffs = rs_file_get_total_size();

    /*生成fat.bin文件*/
    rs_file_combine(combine_file.fn_fat,get_total_size_spiffs);

    /*1 打开fat.bin文件*/ 
    if (0 > file_to_buffer(combine_file.fn_fat,&get_fat_size,&out_buffer_fat))
    {
        printf("file [%s] add crc error\n",combine_file.fn_fat);

        goto error;
    } 
  
    /*先扫描字库文件夹,获取字库的数量、字库的头部信息*/
    find_font(combine_file.dir_font_other);
    list_head_info(); 
  
    uint8_t *font_img_buffer = NULL;
    uint8_t *filesystem_img_buffer = NULL;
     
    /*4 导出 font-xxxx.img*/ 
    /*创建一个缓存用于存储字体镜像*/
    uint32_t config_size_font_fname = 0;
    uint32_t get_fsize_other_font = get_font_total_size(); 
    
    /*先打开fname字体，如果get_fname_font_size为0 则使用改文件大小*/
    p_src_font_fname = fopen(combine_file.fn_font_fname,"rb+");

    if (!p_src_font_fname)
    {
        printf("open fname font [%s] error\r\n",combine_file.fn_font_fname);

        goto error;
    }

    fseek(p_src_font_fname, 0, SEEK_END);
    uint32_t real_size_font_fname = ftell(p_src_font_fname);

    if (0 == real_size_font_fname)
    {
        printf("fname font size invalid\r\n");

        goto error;
    }

    rewind(p_src_font_fname);

    if (get_debug_switch > 0)
    {
        printf("real_size_font_fname = %x\r\n",real_size_font_fname);
    }

    config_size_font_fname = real_size_font_fname;

    if (get_debug_switch > 0)
    {
        printf("reset tconfig_size_font_fname = %x\r\n",config_size_font_fname);
    }

    uint32_t get_font_cnt_total = (1+font_cnt_other);

    printf("get_font_cnt_total=%d\r\n",get_font_cnt_total);

    /*字体文件头的大小等于2字节+头部信息*(字体总数)*/
    uint32_t get_head_info_size = (sizeof(x_header_info_t)*get_font_cnt_total);

    /*合并fname和其他字体合并加入CRC32*/
    get_head_info = (x_header_info_t *)malloc(get_head_info_size);

    if (!get_head_info)
    {
        printf("malloc font head info error\r\n");
    }

    /*总大小是由2字节的字体数量+所有字体头部信息+fname字体大小+其他字体大小*/
    uint32_t font_img_size = 2+get_head_info_size+config_size_font_fname+get_fsize_other_font;
    if (get_debug_switch > 0)
    {
        printf("font_img_size = %x\r\n",font_img_size);
    }

    font_img_buffer = (uint8_t *)malloc(font_img_size);
    
    if (!font_img_buffer)
    {
        printf("font img buffer malloc error\r\n");

        goto error;
    }
    memset(font_img_buffer,0xff,font_img_size);

    /*填充字体数量-2字节*/
    memcpy(font_img_buffer,&get_font_cnt_total,2);
     
    /*填充fname字体的head info*/ 
    x_header_info_t *p_head_info = get_head_info;
    fread(p_head_info,1,4,p_src_font_fname);
    p_head_info->offset = 0;
    p_head_info++;

    rewind(p_src_font_fname);

    if (get_fsize_other_font > 0)
    { 
        for (uint8_t idx=0; idx<font_cnt_other; idx++)
        { 
            /*获取其他字体的每个min和max，并设置新的offfset*/   
            x_header_file_t *head_other = head_other_fonts[idx];

            if (NULL != head_other)
            {
                memcpy(p_head_info,&head_other->info,sizeof(x_header_info_t));

                p_head_info->offset += config_size_font_fname;
 
                p_head_info++;
            }
        }

        /*填充所有字体head info*/
        memcpy(&font_img_buffer[2],get_head_info,get_head_info_size);
        
        /*填充fname字体的数据*/
        fread(&font_img_buffer[2+get_head_info_size],1,real_size_font_fname,p_src_font_fname);

        /*填充其他字体的数据*/
        for (uint8_t idx=0; idx<CONFIG_MAX_CNT_FONT; idx++)
        { 
            /*获取其他字体的每个min和max，并设置新的offfset*/   
            x_header_file_t *head_other = head_other_fonts[idx];

            if (NULL != head_other)
            {
                //printf("head_other->fname=%s\r\n",head_other->fname);
                //printf("head_other->info.offset=%x\r\n",head_other->info.offset);
                memcpy(&font_img_buffer[2+get_head_info_size+config_size_font_fname+head_other->info.offset],head_other->data,head_other->size);
            }
        }
    }
    else
    {
        /*如果没有其他字体则只把fname字体加入镜像*/
        /*填充字体 head info*/
        memcpy(&font_img_buffer[2],get_head_info,get_head_info_size);

        /*填充fname 字体数据*/
        fread(&font_img_buffer[2+get_head_info_size],1,real_size_font_fname,p_src_font_fname);
    }

    /*输出字体镜像 font-xxxx.img*/
    char out_font_crc_fname[32]={0};

    sprintf(out_font_crc_fname, "font_%04d-%02d-%02d.img", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
    
    p_out_font_crc = fopen(out_font_crc_fname,"wb+");

    if (!p_out_font_crc)
    {
        printf("open p_out_font_crc file error[%s]\r\n",out_font_crc_fname);

        goto error;
    } 

    fwrite(font_img_buffer,1,font_img_size,p_out_font_crc);

    uint32_t get_crc_value_font = crc32_customized(CONFIG_CRC32_POLY,CONFIG_CRC32_INIT_VALUE,CONFIG_CRC32_OUT_XOR,font_img_buffer,font_img_size);

    if (get_debug_switch > 0)
    {
        printf("get_crc_value_font = %x\r\n",get_crc_value_font);
    }

    fwrite(&get_crc_value_font,1,4,p_out_font_crc);

    /*5 导出 filesystem.img*/ 
    char out_filesystem_img_name[32]={0};

    sprintf(out_filesystem_img_name, "fat_%04d-%02d-%02d.img", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
 
    /*先获取两个文件的大小*/  
    uint32_t image_size = 4+4+get_fat_size+(font_img_size+4);

    printf("image_size=%x\r\n",image_size);
    uint32_t cnt_sec = (image_size/CONFIG_SPI_FLASH_SEC_SIZE);

    printf("cnt_sec=%d\r\n",cnt_sec);

    if ((CONFIG_SPI_FLASH_SEC_SIZE % image_size) != 0)
    { 
        cnt_sec +=1;
        image_size = cnt_sec*CONFIG_SPI_FLASH_SEC_SIZE;
        printf("fix image_size=[%x]\r\n",image_size);
        printf("fix sec cnt =[%x]\r\n",cnt_sec);
    }

    if (image_size > CONFIG_IMAGE_SIZE_MAX)
    {
        printf("WARNING arrived out of range size[%x]\r\n",CONFIG_IMAGE_SIZE_MAX);
        image_size = CONFIG_IMAGE_SIZE_MAX;
    }

    filesystem_img_buffer = (uint8_t *)malloc(image_size);
    
    if (!filesystem_img_buffer)
    {
        printf("font img buffer malloc error\r\n");

        goto error;
    } 
 
    p_out_filesystem_img = fopen(out_filesystem_img_name,"wb+");

    if (!p_out_filesystem_img)
    {
        printf("open p_out_filesystem_img file error\r\n");

        goto error;
    }

    memset(filesystem_img_buffer,0xff,image_size);  

    /*整个镜像文件的输出*/
    /*填充4字节总大小*/
    memcpy(filesystem_img_buffer,&image_size,4);

    /*填充4字节图片总大小*/
    memcpy(&filesystem_img_buffer[4],&get_fat_size,4);

    /*填充fat镜像*/
    memcpy(&filesystem_img_buffer[8],out_buffer_fat,get_fat_size);

    /*填充font镜像*/
    fclose(p_out_font_crc);

    p_out_font_crc = fopen(out_font_crc_fname,"r");
    if (!p_out_font_crc)
    {
        goto error;
    }
    
    fseek(p_out_font_crc,0,SEEK_END);

    uint32_t get_out_font_file_size = ftell(p_out_font_crc)-4;

    rewind(p_out_font_crc);
    
    fread(&filesystem_img_buffer[8+get_fat_size],1,get_out_font_file_size,p_out_font_crc);

    /*写入filesystem.img*/
    fwrite(filesystem_img_buffer,1,image_size,p_out_filesystem_img); 

    uint32_t get_crc_value_filesystem = crc32_customized(CONFIG_CRC32_POLY,CONFIG_CRC32_INIT_VALUE,CONFIG_CRC32_OUT_XOR,filesystem_img_buffer,image_size);

    if (get_debug_switch > 0)
    {
        printf("get_crc_value_filesystem = %x\r\n",get_crc_value_filesystem);
    }

    /*写入 合并后的crc32*/
    fwrite(&get_crc_value_filesystem,1,4,p_out_filesystem_img);
    
    FILE *p_out_img_product = fopen("fat_product.img","wb+");

    if (!p_out_img_product)
    {
        printf("open p_out_img_product file error\r\n");

        goto error;
    }

    uint32_t set_magic = 0X5AA5;
    fwrite(filesystem_img_buffer,1,image_size,p_out_img_product); 
    fwrite(&get_crc_value_filesystem,1,4,p_out_img_product);
    fwrite(&set_magic,1,4,p_out_img_product);
    if (p_out_img_product)
    {
        fclose(p_out_img_product);  
    }

    /*输出文件*/
    if (file_debug)
    {
        fclose(file_debug);  
    }

    file_out_copy = freopen("copy_to_project.txt", "w",stdout); 

    printf("#define CONFIG_FILE_SYSTEM_CRC       0x%08x \n",get_crc_value_filesystem);

    printf("#define CONFIG_EXT_FONT_OFFSET_FNAME 0x%08x \n",config_size_font_fname);

    generate_head_info_c_array();

    generate_rs_file_c_array();
 
    error:
    
    if (file_debug)
    {
        fclose(file_debug);
    }

    if (p_src_font_fname)
    {
        fclose(p_src_font_fname);
    }  

    if (p_out_filesystem_img)
    {
        fclose(p_out_filesystem_img);
    }

    if (font_img_buffer)
    {
        free(font_img_buffer); 
    }

    if (filesystem_img_buffer)
    {
        free(filesystem_img_buffer); 
    } 

    if (get_head_info)
    {
        free(get_head_info);
    }

    if (file_out_copy)
    {
        fclose(file_out_copy);
    } 
 
    free_head_info();
    
    return 0;
}
#elif 0
#include <stdio.h>
#include <stdlib.h.>
#include <ft2build.h>
#include FT_FREETYPE_H
 #include <freetype/ftglyph.h>

#define FONT_FILE "OPPOSans-B.ttf"
int main() {
    FT_Library  m_pFTLib;
    FT_Face     m_pFTFace;

    FT_Error result = FT_Init_FreeType(&m_pFTLib);
    if(FT_New_Face(m_pFTLib, FONT_FILE, 0, &m_pFTFace))
     {
        printf("FT_New_Face error!\n");
        return;
     }

    //FT_ENCODING_GB2312, FT_ENCODING_UNICODE
    FT_Select_Charmap(m_pFTFace, FT_ENCODING_UNICODE);
    //FT_Set_Char_Size(m_pFTFace, 0, 12<<6, 200, 200);
    //FT_Set_Char_Size( m_pFTFace, 0, 16*64,200, 200 );
   // FT_Set_Char_Size(m_pFTFace, 16 * 64, 0, 100, 0);
    FT_Set_Pixel_Sizes(m_pFTFace, 16, 0);
    result = FT_Load_Glyph(m_pFTFace, FT_Get_Char_Index(m_pFTFace, 0x31), FT_LOAD_DEFAULT);
     // 第二个参数为渲染模式
    result = FT_Render_Glyph(m_pFTFace->glyph,  FT_RENDER_MODE_NORMAL);
    printf("result=%d\n", result);
    FT_Bitmap bmp = m_pFTFace->glyph->bitmap;
    int h = bmp.rows;
    int w = bmp.width;
    int change_line = 0;
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            printf(((bmp.buffer[i * w  + j]) == 0 ) ? "0" : "1");
        }

        printf("\n");
    }

    return 0;
}
#else
#include <stdio.h>
#include <stdlib.h> 

int main() {
    
    FILE *pf_test =fopen("inputfiles/fat.bin","r");

    if (!pf_test)
    {
        printf("open file error\n");
    }

    printf("pf_test=%p\n",pf_test);

    fseek(pf_test,0,SEEK_END);

    uint32_t get_fsize = ftell(pf_test);
    rewind(pf_test);

    printf("get_fsize=%d\r\n",get_fsize);

    return 0;
}
#endif
