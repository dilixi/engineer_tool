

#include "string.h"
#include "stdio.h" 
#include <ctype.h>  
 
#include "utils_lib.h"
#include "ui.h"
#include <stdarg.h> 
#include "config.h"
#include "bambu_api.h" 

#include <time.h> 

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
void s3_rgb565(uint8_t *pSrc, uint8_t *pDest, int iCount, bool bBigEndian);
//void s3_rgb565(uint8_t *pSrc, uint8_t *pDest, int iCount, bool bBigEndian, int input_width, int input_height, int output_width, int output_height);
#ifdef __cplusplus
};
#endif

#define SW_PRINT_PNG_DECODER 0

#if SW_PRINT_PNG_DECODER && SW_PRINT_ALL
#include "esp_log.h"
static const char * TAG = "lib_png_decoder"; 
#define PRINT_PNG_DECODER(fmt,args...) ESP_LOGW(TAG,fmt,##args)  
#else
#define PRINT_PNG_DECODER(...)
#endif

#include <PNGdec.h> 
 
/*时间大概87ms*/
static void png_draw_line_cb_resize(PNGDRAW *pDraw) 
{
    static uint8_t print_cnt = 0;
    
    if (!(pDraw->y % 4)) 
    {  
        resize_buffer_t *out_buffer = (resize_buffer_t *)pDraw->pUser;

        uint32_t r, g, b, a;
        uint32_t b_r, b_g, b_b;
        uint16_t usPixel;

        uint32_t get_bg_color = out_buffer->bg_color;
        b_r = get_bg_color & 0xff; b_g = (get_bg_color & 0xff00) >> 8;
        b_b = (get_bg_color >> 16) & 0xff;
        uint16_t u16Clr = (get_bg_color & 0xf8) << 8;
        u16Clr |= ((get_bg_color & 0xfc00) >> 5);
        u16Clr |= ((get_bg_color & 0xf80000) >> 19);  

        for (uint16_t i = 0; i < pDraw->iWidth; i += 4) 
        {
            if (!(i % 4)) 
            { 
                uint16_t new_width = out_buffer->width;

                uint16_t new_height = out_buffer->height; 

                uint16_t newY = (pDraw->y * new_height) / pDraw->iHeight;

                if (0 == print_cnt)
                {
                    print_cnt=1;

                    PRINT_PNG_DECODER("new_width [%d], new_height[%d], pDraw->iHeight[%d] pDraw->iWidth[%d]\n", new_width, new_height, pDraw->iHeight, pDraw->iWidth);
                } 

                // Calculate source pixel offset 
                // Extract RGBA components
                uint8_t r = pDraw->pPixels[i * 4];    // Red
                uint8_t g = pDraw->pPixels[i * 4 + 1]; // Green
                uint8_t b = pDraw->pPixels[i * 4 + 2]; // Blue
                uint8_t a = pDraw->pPixels[i * 4 + 3]; // Alpha

                if (a == 0)
                {
                    usPixel = u16Clr;
                } 
                else if (a == 255) 
                { // fully opaque
                    usPixel = (b >> 3); // blue
                    usPixel |= ((g >> 2) << 5); // green
                    usPixel |= ((r >> 3) << 11); // red
                } 
                else 
                { // mix the colors
                    r = ((r * a) + (b_r * (255-a))) >> 8;
                    g = ((g * a) + (b_g * (255-a))) >> 8;
                    b = ((b * a) + (b_b * (255-a))) >> 8;
                    usPixel = (b >> 3); // blue
                    usPixel |= ((g >> 2) << 5); // green
                    usPixel |= ((r >> 3) << 11); // red
                }
                
                // Calculate output buffer offset   
                out_buffer->u16_buffer[newY * new_width + (i / 4)] = usPixel;
            }
        } 
    }
} 

static void png_draw_line_cb_resize_div_8(PNGDRAW *pDraw) 
{
    static uint8_t print_cnt = 0;
    
    #define CONFIG_DIV 8

    if (!(pDraw->y % CONFIG_DIV)) 
    {  
        resize_buffer_t *out_buffer = (resize_buffer_t *)pDraw->pUser;

        uint32_t r, g, b, a;
        uint32_t b_r, b_g, b_b;
        uint16_t usPixel;

        uint32_t get_bg_color = out_buffer->bg_color;
        b_r = get_bg_color & 0xff; 
        b_g = (get_bg_color & 0xff00) >> 8;
        b_b = (get_bg_color >> 16) & 0xff;
        
        uint16_t u16Clr = (get_bg_color & 0xf8) << 8;
        u16Clr |= ((get_bg_color & 0xfc00) >> 5);
        u16Clr |= ((get_bg_color & 0xf80000) >> 19);  

        for (uint16_t i = 0; i < pDraw->iWidth; i += CONFIG_DIV) 
        {
            if (!(i % CONFIG_DIV)) 
            { 
                uint16_t new_width = out_buffer->width;

                uint16_t new_height = out_buffer->height; 

                uint16_t newY = (pDraw->y * new_height) / pDraw->iHeight;

                if (0 == print_cnt)
                {
                    print_cnt=1;

                    PRINT_PNG_DECODER("new_width [%d], new_height[%d], pDraw->iHeight[%d] pDraw->iWidth[%d]\n", new_width, new_height, pDraw->iHeight, pDraw->iWidth);
                } 

                // Calculate source pixel offset 
                // Extract RGBA components
                uint8_t r = pDraw->pPixels[i * 4];    // Red
                uint8_t g = pDraw->pPixels[i * 4 + 1]; // Green
                uint8_t b = pDraw->pPixels[i * 4 + 2]; // Blue
                uint8_t a = pDraw->pPixels[i * 4 + 3]; // Alpha

                if (a == 0)
                {
                    usPixel = u16Clr;
                } 
                else if (a == 255) 
                { // fully opaque
                    usPixel = (b >> 3); // blue
                    usPixel |= ((g >> 2) << 5); // green
                    usPixel |= ((r >> 3) << 11); // red
                } 
                else 
                { // mix the colors
                    r = ((r * a) + (b_r * (255-a))) >> 8;
                    g = ((g * a) + (b_g * (255-a))) >> 8;
                    b = ((b * a) + (b_b * (255-a))) >> 8;
                    usPixel = (b >> 3); // blue
                    usPixel |= ((g >> 2) << 5); // green
                    usPixel |= ((r >> 3) << 11); // red
                }
                
                // Calculate output buffer offset   
                out_buffer->u16_buffer[newY * new_width + (i / CONFIG_DIV)] = usPixel;
            }
        } 
    }
} 

int8_t png_decoder_and_resize(uint8_t *input_png_data, uint32_t input_png_size, uint16_t new_width, uint16_t new_height, uint8_t *out_buffer, uint32_t bg_color)
{
    int8_t res = -1;  
    uint64_t cal_time_start = xTaskGetTickCount();
    uint64_t cal_duration = 0;

    if ((!input_png_data) || (!input_png_size))
    {
        return -1;
    }

    //hal_protect_display_enter();
     
    #if 1 
    int rc = -1; 

    resize_buffer_t buffer_out_resize={
        .width = new_width,
        .height = new_height, 
        .bg_color = bg_color,
        .u16_buffer = (uint16_t *)out_buffer
    };   

    //PNG *png_decoder_tool = (PNG *)esp_psram_malloc(sizeof(PNG));
    PNG *png_decoder_tool = (PNG *)esp_psram_malloc(sizeof(PNG));
    if (!png_decoder_tool)
    {
        PRINT_PNG_DECODER("png_decoder_tool esp_psram_malloc error\n");

        goto png_decode_error;
    } 
    
    rc = png_decoder_tool->openFLASH((uint8_t *)input_png_data, input_png_size, (64 == new_width)?png_draw_line_cb_resize_div_8:png_draw_line_cb_resize);
    if (PNG_SUCCESS != rc) 
    {
        PRINT_PNG_DECODER("openFLASH error rc=%d\n",rc);

        goto png_decode_error;
    }   

    rc = png_decoder_tool->decode(&buffer_out_resize, 0); //PNG_FAST_PALETTE PNG_CHECK_CRC);
    if (PNG_SUCCESS != rc) 
    {
        PRINT_PNG_DECODER("decode error rc=%d\n",rc);

        goto png_decode_error;
    }    

    cal_duration = xTaskGetTickCount() - cal_time_start;

    PRINT_PNG_DECODER("decode png takes [%ld] ms\n", (long int)(cal_duration));
  
    res = 0;

    png_decode_error: 
 
    png_decoder_tool->close();   
    if (png_decoder_tool)
    {
        free(png_decoder_tool);
    }

    #else /*时间大概180ms*/
    
    unsigned error = 0;
    unsigned int png_width;             /*Will be the width of the decoded image*/
    unsigned int png_height;            /*Will be the height of the decoded image*/
 
    uint8_t * img_data = NULL;  
    
    error = lodepng_decode32(&img_data, &png_width, &png_height, input_png_data, input_png_size); 

    PRINT_PNG_DECODER("lodepng_decode32 error=%d",error);

    if (!error) 
    {  
        PRINT_PNG_DECODER("blend_resize png_width=%d,png_height=%d, new_width=%d, new_height=%d",png_width, png_height, new_width, new_height);

        ut_convert_color_depth_blend_resize(out_buffer, img_data, png_width, png_height, new_width, new_height, bg_color); 
        
        res = 0;
    } 

    cal_duration = xTaskGetTickCount() - cal_time_start;

    PRINT_PNG_DECODER("decode png takes [%ld] ms\n", (long int)(cal_duration));
    if(img_data)
    {
        free(img_data);
    }
    #endif  

    //hal_protect_display_exit();
  
    return res;
}


