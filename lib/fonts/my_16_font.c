#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "utils_lib.h"
 
typedef struct{
    uint32_t bitmap_index;
    uint8_t adv_w;
    uint8_t box_w;
    uint8_t box_h;
    int8_t  ofs_x;
    int8_t  ofs_y;
}glyph_dsc_t;

static x_header_t __g_xbf_hd = {
    .min = 0x0020,
    .max = 0xff0c,
    .bpp = 4,
};

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
	{.bitmap_index = 0, .adv_w = 4, .box_h = 0, .box_w = 4, .ofs_x = 0, .ofs_y = 3},/*( )*/
	{.bitmap_index = 0, .adv_w = 6, .box_h = 5, .box_w = 4, .ofs_x = 2, .ofs_y = 10},/*(')*/
	{.bitmap_index = 10, .adv_w = 3, .box_h = 4, .box_w = 2, .ofs_x = 1, .ofs_y = 1},/*(,)*/
	{.bitmap_index = 14, .adv_w = 8, .box_h = 2, .box_w = 8, .ofs_x = 0, .ofs_y = 8},/*(-)*/
	{.bitmap_index = 22, .adv_w = 3, .box_h = 2, .box_w = 2, .ofs_x = 1, .ofs_y = 3},/*(.)*/
	{.bitmap_index = 24, .adv_w = 5, .box_h = 8, .box_w = 2, .ofs_x = 3, .ofs_y = 3},/*(:)*/
	{.bitmap_index = 32, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(B)*/
	{.bitmap_index = 76, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(D)*/
	{.bitmap_index = 120, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(E)*/
	{.bitmap_index = 164, .adv_w = 8, .box_h = 12, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(G)*/
	{.bitmap_index = 212, .adv_w = 5, .box_h = 11, .box_w = 2, .ofs_x = 3, .ofs_y = 3},/*(I)*/
	{.bitmap_index = 223, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(L)*/
	{.bitmap_index = 267, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(M)*/
	{.bitmap_index = 311, .adv_w = 8, .box_h = 2, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(_)*/
	{.bitmap_index = 319, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(a)*/
	{.bitmap_index = 351, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(b)*/
	{.bitmap_index = 395, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(c)*/
	{.bitmap_index = 427, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(d)*/
	{.bitmap_index = 471, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(e)*/
	{.bitmap_index = 503, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(g)*/
	{.bitmap_index = 543, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(h)*/
	{.bitmap_index = 587, .adv_w = 5, .box_h = 11, .box_w = 2, .ofs_x = 3, .ofs_y = 3},/*(i)*/
	{.bitmap_index = 598, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(k)*/
	{.bitmap_index = 642, .adv_w = 5, .box_h = 11, .box_w = 2, .ofs_x = 3, .ofs_y = 3},/*(l)*/
	{.bitmap_index = 653, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(m)*/
	{.bitmap_index = 685, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(n)*/
	{.bitmap_index = 717, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(o)*/
	{.bitmap_index = 749, .adv_w = 7, .box_h = 8, .box_w = 6, .ofs_x = 1, .ofs_y = 3},/*(r)*/
	{.bitmap_index = 773, .adv_w = 7, .box_h = 8, .box_w = 6, .ofs_x = 1, .ofs_y = 3},/*(s)*/
	{.bitmap_index = 797, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(t)*/
	{.bitmap_index = 837, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(u)*/
	{.bitmap_index = 869, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(v)*/
	{.bitmap_index = 901, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(y)*/
	{.bitmap_index = 941, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(z)*/
	{.bitmap_index = 973, .adv_w = 5, .box_h = 17, .box_w = 2, .ofs_x = 3, .ofs_y = 0},/*(|)*/
	{.bitmap_index = 990, .adv_w = 6, .box_h = 5, .box_w = 4, .ofs_x = 2, .ofs_y = 2},/*(。)*/
	{.bitmap_index = 1000, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 1},/*(中)*/
	{.bitmap_index = 1105, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(你)*/
	{.bitmap_index = 1233, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 1},/*(国)*/
	{.bitmap_index = 1338, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(妈)*/
	{.bitmap_index = 1458, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(我)*/
	{.bitmap_index = 1578, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(文)*/
	{.bitmap_index = 1706, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(爱)*/
	{.bitmap_index = 1826, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 1},/*(的)*/
	{.bitmap_index = 1931, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(祖)*/
	{.bitmap_index = 2059, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*(谢)*/
	{.bitmap_index = 2191, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 2327, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 2423, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 2535, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 2631, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 2697, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 2825, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 2953, .adv_w = 18, .box_h = 14, .box_w = 18, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 3079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 3207, .adv_w = 18, .box_h = 12, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 3315, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 3443, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 3499, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 3583, .adv_w = 18, .box_h = 16, .box_w = 18, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 3727, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 3823, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 3919, .adv_w = 12, .box_h = 16, .box_w = 10, .ofs_x = 2, .ofs_y = 0},/*()*/
	{.bitmap_index = 3999, .adv_w = 14, .box_h = 18, .box_w = 14, .ofs_x = 0, .ofs_y = -1},/*()*/
	{.bitmap_index = 4125, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4223, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4321, .adv_w = 12, .box_h = 16, .box_w = 10, .ofs_x = 2, .ofs_y = 0},/*()*/
	{.bitmap_index = 4401, .adv_w = 15, .box_h = 14, .box_w = 16, .ofs_x = -1, .ofs_y = 1},/*()*/
	{.bitmap_index = 4513, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4583, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4653, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4751, .adv_w = 14, .box_h = 3, .box_w = 14, .ofs_x = 0, .ofs_y = 6},/*()*/
	{.bitmap_index = 4772, .adv_w = 18, .box_h = 12, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 4880, .adv_w = 20, .box_h = 16, .box_w = 20, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 5040, .adv_w = 19, .box_h = 16, .box_w = 20, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 5200, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 5328, .adv_w = 14, .box_h = 10, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5398, .adv_w = 14, .box_h = 10, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5468, .adv_w = 20, .box_h = 14, .box_w = 20, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 5608, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 5704, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 5832, .adv_w = 17, .box_h = 17, .box_w = 18, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 5985, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 6097, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 6209, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 6307, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 6405, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 6501, .adv_w = 11, .box_h = 16, .box_w = 12, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 6597, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 6709, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 6821, .adv_w = 18, .box_h = 12, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 6929, .adv_w = 17, .box_h = 18, .box_w = 18, .ofs_x = -1, .ofs_y = -1},/*()*/
	{.bitmap_index = 7091, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 7187, .adv_w = 20, .box_h = 15, .box_w = 20, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 7337, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 7437, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 7537, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 7637, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 7737, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 7837, .adv_w = 22, .box_h = 14, .box_w = 22, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 7991, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*()*/
	{.bitmap_index = 8087, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 8199, .adv_w = 17, .box_h = 17, .box_w = 18, .ofs_x = -1, .ofs_y = -1},/*()*/
	{.bitmap_index = 8352, .adv_w = 20, .box_h = 12, .box_w = 20, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 8472, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 8568, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 2179, .adv_w = 6, .box_h = 6, .box_w = 4, .ofs_x = 2, .ofs_y = 0},/*(，)*/

};


static const uint16_t unicode_list[] = {
	0x0020,	/*( )*/
	0x0027,	/*(')*/
	0x002c,	/*(,)*/
	0x002d,	/*(-)*/
	0x002e,	/*(.)*/
	0x003a,	/*(:)*/
	0x0042,	/*(B)*/
	0x0044,	/*(D)*/
	0x0045,	/*(E)*/
	0x0047,	/*(G)*/
	0x0049,	/*(I)*/
	0x004c,	/*(L)*/
	0x004d,	/*(M)*/
	0x005f,	/*(_)*/
	0x0061,	/*(a)*/
	0x0062,	/*(b)*/
	0x0063,	/*(c)*/
	0x0064,	/*(d)*/
	0x0065,	/*(e)*/
	0x0067,	/*(g)*/
	0x0068,	/*(h)*/
	0x0069,	/*(i)*/
	0x006b,	/*(k)*/
	0x006c,	/*(l)*/
	0x006d,	/*(m)*/
	0x006e,	/*(n)*/
	0x006f,	/*(o)*/
	0x0072,	/*(r)*/
	0x0073,	/*(s)*/
	0x0074,	/*(t)*/
	0x0075,	/*(u)*/
	0x0076,	/*(v)*/
	0x0079,	/*(y)*/
	0x007a,	/*(z)*/
	0x007c,	/*(|)*/
	0x3002,	/*(。)*/
	0x4e2d,	/*(中)*/
	0x4f60,	/*(你)*/
	0x56fd,	/*(国)*/
	0x5988,	/*(妈)*/
	0x6211,	/*(我)*/
	0x6587,	/*(文)*/
	0x7231,	/*(爱)*/
	0x7684,	/*(的)*/
	0x7956,	/*(祖)*/
	0x8c22,	/*(谢)*/
	0xf001,	/*()*/
	0xf008,	/*()*/
	0xf00b,	/*()*/
	0xf00c,	/*()*/
	0xf00d,	/*()*/
	0xf011,	/*()*/
	0xf013,	/*()*/
	0xf015,	/*()*/
	0xf019,	/*()*/
	0xf01c,	/*()*/
	0xf021,	/*()*/
	0xf026,	/*()*/
	0xf027,	/*()*/
	0xf028,	/*()*/
	0xf03e,	/*()*/
	0xf043,	/*()*/
	0xf048,	/*()*/
	0xf04b,	/*()*/
	0xf04c,	/*()*/
	0xf04d,	/*()*/
	0xf051,	/*()*/
	0xf052,	/*()*/
	0xf053,	/*()*/
	0xf054,	/*()*/
	0xf067,	/*()*/
	0xf068,	/*()*/
	0xf06e,	/*()*/
	0xf070,	/*()*/
	0xf071,	/*()*/
	0xf074,	/*()*/
	0xf077,	/*()*/
	0xf078,	/*()*/
	0xf079,	/*()*/
	0xf07b,	/*()*/
	0xf093,	/*()*/
	0xf095,	/*()*/
	0xf0c4,	/*()*/
	0xf0c5,	/*()*/
	0xf0c7,	/*()*/
	0xf0c9,	/*()*/
	0xf0e0,	/*()*/
	0xf0e7,	/*()*/
	0xf0ea,	/*()*/
	0xf0f3,	/*()*/
	0xf11c,	/*()*/
	0xf124,	/*()*/
	0xf15b,	/*()*/
	0xf1eb,	/*()*/
	0xf240,	/*()*/
	0xf241,	/*()*/
	0xf242,	/*()*/
	0xf243,	/*()*/
	0xf244,	/*()*/
	0xf287,	/*()*/
	0xf293,	/*()*/
	0xf2ed,	/*()*/
	0xf304,	/*()*/
	0xf55a,	/*()*/
	0xf7c2,	/*()*/
	0xf8a2,	/*()*/
	0xff0c,	/*(，)*/
	0x0000,	/*(list end)*/

};


//static uint8_t __g_font_buf[162];
static uint32_t last_letter;
static uint32_t last_glyph_id;

static uint8_t *__user_font_getdata(int offset, int size){

    return font_img_buffer + offset;
}

//二分法查找字符id
static int64_t binsearch(const uint16_t *sortedSeq, uint32_t seqLength, uint16_t keyData) {
    int64_t low = 0, mid, high = seqLength - 1;
    while (low <= high) {
        mid = (low + high)>>1;//右移1位等于是/2, 奇数, 无论奇偶, 有个值就行
        if (keyData < sortedSeq[mid]) {
            high = mid - 1;//是mid-1, 因为mid已经比较过了
        }
        else if (keyData > sortedSeq[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

static const uint8_t * __user_font_get_bitmap(const lv_font_t * font, uint32_t unicode_letter) {
    if( unicode_letter>__g_xbf_hd.max || unicode_letter<__g_xbf_hd.min ) {
        return NULL;
    }
       int64_t i = binsearch(unicode_list, sizeof(unicode_list)/sizeof(unicode_list[0]), unicode_letter);
    if( i != -1 ) {
        last_glyph_id = i;
        last_letter = unicode_letter;

        return __user_font_getdata(glyph_dsc[i].bitmap_index, glyph_dsc[i].box_w*glyph_dsc[i].box_h*__g_xbf_hd.bpp/8);
    }
    return NULL;
}


static bool __user_font_get_glyph_dsc(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next) {
    if( unicode_letter>__g_xbf_hd.max || unicode_letter<__g_xbf_hd.min ) {
        return NULL;
    }
    int i;
    if( unicode_letter==last_letter ){
        i = last_glyph_id;
    }
    else{
        i = binsearch(unicode_list, sizeof(unicode_list)/sizeof(unicode_list[0]), unicode_letter);
    }
    if( i != -1 ) {
        last_glyph_id = i;
        last_letter = unicode_letter;

        dsc_out->adv_w = glyph_dsc[i].adv_w;
        dsc_out->box_h = glyph_dsc[i].box_h;
        dsc_out->box_w = glyph_dsc[i].box_w;
        dsc_out->ofs_x = glyph_dsc[i].ofs_x;
        dsc_out->ofs_y = glyph_dsc[i].ofs_y;
        dsc_out->bpp   = __g_xbf_hd.bpp;
        return true;
    }
    return false;
}

//字体名称: my_16_font
//字模高度: 18
//外部bin文件,字体信息等级:Level1
lv_font_t font_bin_16 = {
    .get_glyph_bitmap = __user_font_get_bitmap,
    .get_glyph_dsc = __user_font_get_glyph_dsc,
    .line_height = 18,
    .base_line = 0,
};
