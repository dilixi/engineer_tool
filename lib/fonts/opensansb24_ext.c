

#include "utils_lib.h"
 
static x_header_t __g_xbf_hd = {
    .min = 0x0020,
    .max = 0xffe5,
    .bpp = 2,
};

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
	{.bitmap_index = 0, .adv_w = 6, .box_h = 0, .box_w = 6, .ofs_x = 0, .ofs_y = 8},/*( )*/
	{.bitmap_index = 0, .adv_w = 9, .box_h = 20, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(!)*/
	{.bitmap_index = 40, .adv_w = 13, .box_h = 9, .box_w = 12, .ofs_x = 1, .ofs_y = 18},/*(")*/
	{.bitmap_index = 67, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(#)*/
	{.bitmap_index = 151, .adv_w = 17, .box_h = 29, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*($)*/
	{.bitmap_index = 267, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(%)*/
	{.bitmap_index = 393, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(&)*/
	{.bitmap_index = 503, .adv_w = 9, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 18},/*(')*/
	{.bitmap_index = 521, .adv_w = 10, .box_h = 25, .box_w = 8, .ofs_x = 2, .ofs_y = 3},/*(()*/
	{.bitmap_index = 571, .adv_w = 8, .box_h = 25, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*())*/
	{.bitmap_index = 621, .adv_w = 16, .box_h = 13, .box_w = 16, .ofs_x = 0, .ofs_y = 14},/*(*)*/
	{.bitmap_index = 673, .adv_w = 14, .box_h = 12, .box_w = 12, .ofs_x = 2, .ofs_y = 10},/*(+)*/
	{.bitmap_index = 709, .adv_w = 9, .box_h = 8, .box_w = 8, .ofs_x = 1, .ofs_y = 2},/*(,)*/
	{.bitmap_index = 725, .adv_w = 9, .box_h = 3, .box_w = 8, .ofs_x = 1, .ofs_y = 14},/*(-)*/
	{.bitmap_index = 731, .adv_w = 9, .box_h = 4, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(.)*/
	{.bitmap_index = 739, .adv_w = 12, .box_h = 25, .box_w = 12, .ofs_x = 0, .ofs_y = 3},/*(/)*/
	{.bitmap_index = 814, .adv_w = 16, .box_h = 22, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(0)*/
	{.bitmap_index = 902, .adv_w = 9, .box_h = 20, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(1)*/
	{.bitmap_index = 942, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(2)*/
	{.bitmap_index = 1026, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(3)*/
	{.bitmap_index = 1110, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(4)*/
	{.bitmap_index = 1190, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(5)*/
	{.bitmap_index = 1274, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(6)*/
	{.bitmap_index = 1358, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(7)*/
	{.bitmap_index = 1438, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(8)*/
	{.bitmap_index = 1526, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(9)*/
	{.bitmap_index = 1610, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(:)*/
	{.bitmap_index = 1638, .adv_w = 9, .box_h = 18, .box_w = 8, .ofs_x = 1, .ofs_y = 2},/*(;)*/
	{.bitmap_index = 1674, .adv_w = 14, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 9},/*(<)*/
	{.bitmap_index = 1716, .adv_w = 14, .box_h = 9, .box_w = 12, .ofs_x = 2, .ofs_y = 12},/*(=)*/
	{.bitmap_index = 1743, .adv_w = 14, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 9},/*(>)*/
	{.bitmap_index = 1785, .adv_w = 13, .box_h = 21, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(?)*/
	{.bitmap_index = 1848, .adv_w = 29, .box_h = 25, .box_w = 28, .ofs_x = 1, .ofs_y = 2},/*(@)*/
	{.bitmap_index = 2023, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(A)*/
	{.bitmap_index = 2123, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(B)*/
	{.bitmap_index = 2203, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(C)*/
	{.bitmap_index = 2291, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(D)*/
	{.bitmap_index = 2391, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(E)*/
	{.bitmap_index = 2471, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(F)*/
	{.bitmap_index = 2551, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(G)*/
	{.bitmap_index = 2661, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(H)*/
	{.bitmap_index = 2761, .adv_w = 6, .box_h = 20, .box_w = 4, .ofs_x = 2, .ofs_y = 6},/*(I)*/
	{.bitmap_index = 2781, .adv_w = 12, .box_h = 21, .box_w = 12, .ofs_x = 0, .ofs_y = 5},/*(J)*/
	{.bitmap_index = 2844, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(K)*/
	{.bitmap_index = 2924, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(L)*/
	{.bitmap_index = 3004, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(M)*/
	{.bitmap_index = 3124, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(N)*/
	{.bitmap_index = 3224, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(O)*/
	{.bitmap_index = 3334, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(P)*/
	{.bitmap_index = 3414, .adv_w = 21, .box_h = 24, .box_w = 20, .ofs_x = 1, .ofs_y = 3},/*(Q)*/
	{.bitmap_index = 3534, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(R)*/
	{.bitmap_index = 3614, .adv_w = 16, .box_h = 22, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(S)*/
	{.bitmap_index = 3702, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(T)*/
	{.bitmap_index = 3782, .adv_w = 21, .box_h = 21, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(U)*/
	{.bitmap_index = 3887, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(V)*/
	{.bitmap_index = 3987, .adv_w = 28, .box_h = 20, .box_w = 28, .ofs_x = 0, .ofs_y = 6},/*(W)*/
	{.bitmap_index = 4127, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(X)*/
	{.bitmap_index = 4227, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Y)*/
	{.bitmap_index = 4327, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Z)*/
	{.bitmap_index = 4407, .adv_w = 10, .box_h = 25, .box_w = 8, .ofs_x = 2, .ofs_y = 3},/*([)*/
	{.bitmap_index = 4457, .adv_w = 12, .box_h = 25, .box_w = 12, .ofs_x = 0, .ofs_y = 3},/*(\)*/
	{.bitmap_index = 4532, .adv_w = 8, .box_h = 25, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(])*/
	{.bitmap_index = 4582, .adv_w = 17, .box_h = 12, .box_w = 16, .ofs_x = 1, .ofs_y = 15},/*(^)*/
	{.bitmap_index = 4630, .adv_w = 8, .box_h = 4, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(_)*/
	{.bitmap_index = 4638, .adv_w = 9, .box_h = 6, .box_w = 8, .ofs_x = 1, .ofs_y = 22},/*(`)*/
	{.bitmap_index = 4650, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(a)*/
	{.bitmap_index = 4718, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(b)*/
	{.bitmap_index = 4806, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(c)*/
	{.bitmap_index = 4874, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(d)*/
	{.bitmap_index = 4962, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(e)*/
	{.bitmap_index = 5030, .adv_w = 12, .box_h = 22, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(f)*/
	{.bitmap_index = 5096, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(g)*/
	{.bitmap_index = 5184, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(h)*/
	{.bitmap_index = 5268, .adv_w = 9, .box_h = 21, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(i)*/
	{.bitmap_index = 5310, .adv_w = 6, .box_h = 27, .box_w = 8, .ofs_x = -2, .ofs_y = 0},/*(j)*/
	{.bitmap_index = 5364, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(k)*/
	{.bitmap_index = 5448, .adv_w = 5, .box_h = 21, .box_w = 4, .ofs_x = 1, .ofs_y = 6},/*(l)*/
	{.bitmap_index = 5469, .adv_w = 25, .box_h = 16, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(m)*/
	{.bitmap_index = 5565, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(n)*/
	{.bitmap_index = 5629, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(o)*/
	{.bitmap_index = 5697, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(p)*/
	{.bitmap_index = 5785, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(q)*/
	{.bitmap_index = 5873, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(r)*/
	{.bitmap_index = 5921, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(s)*/
	{.bitmap_index = 5989, .adv_w = 12, .box_h = 20, .box_w = 12, .ofs_x = 0, .ofs_y = 5},/*(t)*/
	{.bitmap_index = 6049, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(u)*/
	{.bitmap_index = 6113, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(v)*/
	{.bitmap_index = 6173, .adv_w = 24, .box_h = 15, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(w)*/
	{.bitmap_index = 6263, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(x)*/
	{.bitmap_index = 6323, .adv_w = 16, .box_h = 21, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(y)*/
	{.bitmap_index = 6407, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(z)*/
	{.bitmap_index = 6467, .adv_w = 12, .box_h = 25, .box_w = 12, .ofs_x = 0, .ofs_y = 3},/*({)*/
	{.bitmap_index = 6542, .adv_w = 6, .box_h = 25, .box_w = 4, .ofs_x = 2, .ofs_y = 3},/*(|)*/
	{.bitmap_index = 6567, .adv_w = 9, .box_h = 25, .box_w = 8, .ofs_x = 1, .ofs_y = 3},/*(})*/
	{.bitmap_index = 6617, .adv_w = 17, .box_h = 6, .box_w = 16, .ofs_x = 1, .ofs_y = 13},/*(~)*/
	{.bitmap_index = 6641, .adv_w = 9, .box_h = 22, .box_w = 8, .ofs_x = 1, .ofs_y = 0},/*(¡)*/
	{.bitmap_index = 6685, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(¢)*/
	{.bitmap_index = 6769, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(£)*/
	{.bitmap_index = 6853, .adv_w = 20, .box_h = 17, .box_w = 20, .ofs_x = 0, .ofs_y = 5},/*(¤)*/
	{.bitmap_index = 6938, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(¥)*/
	{.bitmap_index = 7018, .adv_w = 6, .box_h = 25, .box_w = 4, .ofs_x = 2, .ofs_y = 3},/*(¦)*/
	{.bitmap_index = 7043, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(§)*/
	{.bitmap_index = 7148, .adv_w = 13, .box_h = 5, .box_w = 12, .ofs_x = 1, .ofs_y = 22},/*(¨)*/
	{.bitmap_index = 7163, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(©)*/
	{.bitmap_index = 7295, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 9},/*(ª)*/
	{.bitmap_index = 7349, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 10},/*(«)*/
	{.bitmap_index = 7382, .adv_w = 13, .box_h = 7, .box_w = 12, .ofs_x = 1, .ofs_y = 10},/*(¬)*/
	{.bitmap_index = 7403, .adv_w = 9, .box_h = 3, .box_w = 8, .ofs_x = 1, .ofs_y = 14},/*(­)*/
	{.bitmap_index = 7409, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 14},/*(®)*/
	{.bitmap_index = 7469, .adv_w = 9, .box_h = 3, .box_w = 8, .ofs_x = 1, .ofs_y = 23},/*(¯)*/
	{.bitmap_index = 7475, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 17},/*(°)*/
	{.bitmap_index = 7508, .adv_w = 14, .box_h = 16, .box_w = 12, .ofs_x = 2, .ofs_y = 8},/*(±)*/
	{.bitmap_index = 7556, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 16},/*(²)*/
	{.bitmap_index = 7578, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 16},/*(³)*/
	{.bitmap_index = 7600, .adv_w = 9, .box_h = 6, .box_w = 8, .ofs_x = 1, .ofs_y = 22},/*(´)*/
	{.bitmap_index = 7612, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(µ)*/
	{.bitmap_index = 7717, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(¶)*/
	{.bitmap_index = 7822, .adv_w = 8, .box_h = 5, .box_w = 4, .ofs_x = 4, .ofs_y = 14},/*(·)*/
	{.bitmap_index = 7827, .adv_w = 9, .box_h = 7, .box_w = 8, .ofs_x = 1, .ofs_y = 0},/*(¸)*/
	{.bitmap_index = 7841, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 16},/*(¹)*/
	{.bitmap_index = 7863, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 9},/*(º)*/
	{.bitmap_index = 7917, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 10},/*(»)*/
	{.bitmap_index = 7950, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(¼)*/
	{.bitmap_index = 8050, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(½)*/
	{.bitmap_index = 8150, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(¾)*/
	{.bitmap_index = 8270, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*(¿)*/
	{.bitmap_index = 8336, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(À)*/
	{.bitmap_index = 8471, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Á)*/
	{.bitmap_index = 8606, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Â)*/
	{.bitmap_index = 8741, .adv_w = 20, .box_h = 26, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ã)*/
	{.bitmap_index = 8871, .adv_w = 20, .box_h = 26, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ä)*/
	{.bitmap_index = 9001, .adv_w = 20, .box_h = 28, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Å)*/
	{.bitmap_index = 9141, .adv_w = 28, .box_h = 20, .box_w = 28, .ofs_x = 0, .ofs_y = 6},/*(Æ)*/
	{.bitmap_index = 9281, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(Ç)*/
	{.bitmap_index = 9389, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(È)*/
	{.bitmap_index = 9497, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(É)*/
	{.bitmap_index = 9605, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ê)*/
	{.bitmap_index = 9713, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ë)*/
	{.bitmap_index = 9817, .adv_w = 8, .box_h = 27, .box_w = 8, .ofs_x = 0, .ofs_y = 6},/*(Ì)*/
	{.bitmap_index = 9871, .adv_w = 10, .box_h = 27, .box_w = 8, .ofs_x = 2, .ofs_y = 6},/*(Í)*/
	{.bitmap_index = 9925, .adv_w = 10, .box_h = 27, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(Î)*/
	{.bitmap_index = 10006, .adv_w = 11, .box_h = 26, .box_w = 12, .ofs_x = -1, .ofs_y = 6},/*(Ï)*/
	{.bitmap_index = 10084, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ð)*/
	{.bitmap_index = 10184, .adv_w = 21, .box_h = 26, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ñ)*/
	{.bitmap_index = 10314, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ò)*/
	{.bitmap_index = 10454, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ó)*/
	{.bitmap_index = 10594, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ô)*/
	{.bitmap_index = 10734, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Õ)*/
	{.bitmap_index = 10869, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ö)*/
	{.bitmap_index = 11004, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 9},/*(×)*/
	{.bitmap_index = 11060, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ø)*/
	{.bitmap_index = 11170, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ù)*/
	{.bitmap_index = 11310, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ú)*/
	{.bitmap_index = 11450, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Û)*/
	{.bitmap_index = 11590, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ü)*/
	{.bitmap_index = 11725, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ý)*/
	{.bitmap_index = 11860, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Þ)*/
	{.bitmap_index = 11940, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ß)*/
	{.bitmap_index = 12032, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(à)*/
	{.bitmap_index = 12124, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(á)*/
	{.bitmap_index = 12216, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(â)*/
	{.bitmap_index = 12308, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ã)*/
	{.bitmap_index = 12392, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ä)*/
	{.bitmap_index = 12476, .adv_w = 17, .box_h = 24, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(å)*/
	{.bitmap_index = 12572, .adv_w = 25, .box_h = 17, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(æ)*/
	{.bitmap_index = 12674, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ç)*/
	{.bitmap_index = 12762, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(è)*/
	{.bitmap_index = 12854, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(é)*/
	{.bitmap_index = 12946, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ê)*/
	{.bitmap_index = 13038, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ë)*/
	{.bitmap_index = 13122, .adv_w = 8, .box_h = 22, .box_w = 8, .ofs_x = 0, .ofs_y = 6},/*(ì)*/
	{.bitmap_index = 13166, .adv_w = 9, .box_h = 22, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(í)*/
	{.bitmap_index = 13210, .adv_w = 10, .box_h = 22, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(î)*/
	{.bitmap_index = 13276, .adv_w = 10, .box_h = 20, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(ï)*/
	{.bitmap_index = 13336, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ð)*/
	{.bitmap_index = 13428, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ñ)*/
	{.bitmap_index = 13508, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ò)*/
	{.bitmap_index = 13600, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ó)*/
	{.bitmap_index = 13692, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ô)*/
	{.bitmap_index = 13784, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(õ)*/
	{.bitmap_index = 13868, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ö)*/
	{.bitmap_index = 13952, .adv_w = 14, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 9},/*(÷)*/
	{.bitmap_index = 13994, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ø)*/
	{.bitmap_index = 14062, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ù)*/
	{.bitmap_index = 14154, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ú)*/
	{.bitmap_index = 14246, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(û)*/
	{.bitmap_index = 14338, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ü)*/
	{.bitmap_index = 14422, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ý)*/
	{.bitmap_index = 14534, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(þ)*/
	{.bitmap_index = 14642, .adv_w = 16, .box_h = 26, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ÿ)*/
	{.bitmap_index = 14746, .adv_w = 20, .box_h = 25, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ā)*/
	{.bitmap_index = 14871, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ā)*/
	{.bitmap_index = 14955, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ă)*/
	{.bitmap_index = 15090, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ă)*/
	{.bitmap_index = 15182, .adv_w = 20, .box_h = 26, .box_w = 20, .ofs_x = 0, .ofs_y = 0},/*(Ą)*/
	{.bitmap_index = 15312, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ą)*/
	{.bitmap_index = 15400, .adv_w = 17, .box_h = 28, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(Ć)*/
	{.bitmap_index = 15512, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ć)*/
	{.bitmap_index = 15604, .adv_w = 17, .box_h = 28, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(Ĉ)*/
	{.bitmap_index = 15716, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ĉ)*/
	{.bitmap_index = 15808, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(Ċ)*/
	{.bitmap_index = 15916, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ċ)*/
	{.bitmap_index = 16000, .adv_w = 17, .box_h = 28, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(Č)*/
	{.bitmap_index = 16112, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(č)*/
	{.bitmap_index = 16204, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ď)*/
	{.bitmap_index = 16339, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(ď)*/
	{.bitmap_index = 16449, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Đ)*/
	{.bitmap_index = 16549, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(đ)*/
	{.bitmap_index = 16637, .adv_w = 17, .box_h = 25, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ē)*/
	{.bitmap_index = 16737, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ē)*/
	{.bitmap_index = 16821, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ĕ)*/
	{.bitmap_index = 16929, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ĕ)*/
	{.bitmap_index = 17021, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ė)*/
	{.bitmap_index = 17125, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ė)*/
	{.bitmap_index = 17209, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(Ę)*/
	{.bitmap_index = 17313, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ę)*/
	{.bitmap_index = 17401, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ě)*/
	{.bitmap_index = 17509, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ě)*/
	{.bitmap_index = 17601, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ĝ)*/
	{.bitmap_index = 17741, .adv_w = 17, .box_h = 28, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ĝ)*/
	{.bitmap_index = 17853, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ğ)*/
	{.bitmap_index = 17993, .adv_w = 17, .box_h = 28, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ğ)*/
	{.bitmap_index = 18105, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ġ)*/
	{.bitmap_index = 18240, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ġ)*/
	{.bitmap_index = 18344, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 0},/*(Ģ)*/
	{.bitmap_index = 18479, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ģ)*/
	{.bitmap_index = 18587, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ĥ)*/
	{.bitmap_index = 18722, .adv_w = 18, .box_h = 27, .box_w = 20, .ofs_x = -2, .ofs_y = 6},/*(ĥ)*/
	{.bitmap_index = 18857, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ħ)*/
	{.bitmap_index = 18957, .adv_w = 15, .box_h = 21, .box_w = 16, .ofs_x = -1, .ofs_y = 6},/*(ħ)*/
	{.bitmap_index = 19041, .adv_w = 11, .box_h = 26, .box_w = 12, .ofs_x = -1, .ofs_y = 6},/*(Ĩ)*/
	{.bitmap_index = 19119, .adv_w = 10, .box_h = 20, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(ĩ)*/
	{.bitmap_index = 19179, .adv_w = 11, .box_h = 25, .box_w = 12, .ofs_x = -1, .ofs_y = 6},/*(Ī)*/
	{.bitmap_index = 19254, .adv_w = 11, .box_h = 20, .box_w = 12, .ofs_x = -1, .ofs_y = 6},/*(ī)*/
	{.bitmap_index = 19314, .adv_w = 11, .box_h = 27, .box_w = 12, .ofs_x = -1, .ofs_y = 6},/*(Ĭ)*/
	{.bitmap_index = 19395, .adv_w = 10, .box_h = 22, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(ĭ)*/
	{.bitmap_index = 19461, .adv_w = 8, .box_h = 26, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(Į)*/
	{.bitmap_index = 19513, .adv_w = 8, .box_h = 26, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(į)*/
	{.bitmap_index = 19565, .adv_w = 9, .box_h = 26, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(İ)*/
	{.bitmap_index = 19617, .adv_w = 5, .box_h = 15, .box_w = 4, .ofs_x = 1, .ofs_y = 6},/*(ı)*/
	{.bitmap_index = 19632, .adv_w = 18, .box_h = 21, .box_w = 16, .ofs_x = 2, .ofs_y = 5},/*(Ĳ)*/
	{.bitmap_index = 19716, .adv_w = 13, .box_h = 27, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*(ĳ)*/
	{.bitmap_index = 19797, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(Ĵ)*/
	{.bitmap_index = 19909, .adv_w = 10, .box_h = 28, .box_w = 12, .ofs_x = -2, .ofs_y = 0},/*(ĵ)*/
	{.bitmap_index = 19993, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(Ķ)*/
	{.bitmap_index = 20097, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ķ)*/
	{.bitmap_index = 20205, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ĸ)*/
	{.bitmap_index = 20265, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ĺ)*/
	{.bitmap_index = 20369, .adv_w = 9, .box_h = 27, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(ĺ)*/
	{.bitmap_index = 20423, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(Ļ)*/
	{.bitmap_index = 20527, .adv_w = 5, .box_h = 27, .box_w = 4, .ofs_x = 1, .ofs_y = 0},/*(ļ)*/
	{.bitmap_index = 20554, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ľ)*/
	{.bitmap_index = 20634, .adv_w = 9, .box_h = 21, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(ľ)*/
	{.bitmap_index = 20676, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ŀ)*/
	{.bitmap_index = 20756, .adv_w = 13, .box_h = 21, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ŀ)*/
	{.bitmap_index = 20819, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ł)*/
	{.bitmap_index = 20899, .adv_w = 12, .box_h = 21, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ł)*/
	{.bitmap_index = 20962, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ń)*/
	{.bitmap_index = 21097, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ń)*/
	{.bitmap_index = 21185, .adv_w = 21, .box_h = 26, .box_w = 20, .ofs_x = 1, .ofs_y = 0},/*(Ņ)*/
	{.bitmap_index = 21315, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ņ)*/
	{.bitmap_index = 21403, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ň)*/
	{.bitmap_index = 21538, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ň)*/
	{.bitmap_index = 21626, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ŉ)*/
	{.bitmap_index = 21731, .adv_w = 21, .box_h = 26, .box_w = 20, .ofs_x = 1, .ofs_y = 0},/*(Ŋ)*/
	{.bitmap_index = 21861, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ŋ)*/
	{.bitmap_index = 21949, .adv_w = 21, .box_h = 26, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ō)*/
	{.bitmap_index = 22079, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ō)*/
	{.bitmap_index = 22163, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ŏ)*/
	{.bitmap_index = 22303, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ŏ)*/
	{.bitmap_index = 22395, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ő)*/
	{.bitmap_index = 22535, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ő)*/
	{.bitmap_index = 22627, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(Œ)*/
	{.bitmap_index = 22747, .adv_w = 25, .box_h = 17, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(œ)*/
	{.bitmap_index = 22849, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ŕ)*/
	{.bitmap_index = 22957, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ŕ)*/
	{.bitmap_index = 23023, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(Ŗ)*/
	{.bitmap_index = 23127, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*(ŗ)*/
	{.bitmap_index = 23193, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ř)*/
	{.bitmap_index = 23301, .adv_w = 12, .box_h = 22, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ř)*/
	{.bitmap_index = 23367, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(Ś)*/
	{.bitmap_index = 23479, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(ś)*/
	{.bitmap_index = 23571, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(Ŝ)*/
	{.bitmap_index = 23683, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(ŝ)*/
	{.bitmap_index = 23775, .adv_w = 16, .box_h = 27, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(Ş)*/
	{.bitmap_index = 23883, .adv_w = 16, .box_h = 22, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ş)*/
	{.bitmap_index = 23971, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(Š)*/
	{.bitmap_index = 24083, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(š)*/
	{.bitmap_index = 24175, .adv_w = 16, .box_h = 26, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(Ţ)*/
	{.bitmap_index = 24279, .adv_w = 12, .box_h = 25, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*(ţ)*/
	{.bitmap_index = 24354, .adv_w = 16, .box_h = 27, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ť)*/
	{.bitmap_index = 24462, .adv_w = 12, .box_h = 22, .box_w = 12, .ofs_x = 0, .ofs_y = 5},/*(ť)*/
	{.bitmap_index = 24528, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ŧ)*/
	{.bitmap_index = 24608, .adv_w = 12, .box_h = 20, .box_w = 12, .ofs_x = 0, .ofs_y = 5},/*(ŧ)*/
	{.bitmap_index = 24668, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ũ)*/
	{.bitmap_index = 24803, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ũ)*/
	{.bitmap_index = 24887, .adv_w = 21, .box_h = 26, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ū)*/
	{.bitmap_index = 25017, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ū)*/
	{.bitmap_index = 25101, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ŭ)*/
	{.bitmap_index = 25241, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ŭ)*/
	{.bitmap_index = 25333, .adv_w = 21, .box_h = 29, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ů)*/
	{.bitmap_index = 25478, .adv_w = 17, .box_h = 24, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ů)*/
	{.bitmap_index = 25574, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ű)*/
	{.bitmap_index = 25714, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ű)*/
	{.bitmap_index = 25806, .adv_w = 21, .box_h = 26, .box_w = 20, .ofs_x = 1, .ofs_y = 0},/*(Ų)*/
	{.bitmap_index = 25936, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(ų)*/
	{.bitmap_index = 26020, .adv_w = 28, .box_h = 27, .box_w = 28, .ofs_x = 0, .ofs_y = 6},/*(Ŵ)*/
	{.bitmap_index = 26209, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(ŵ)*/
	{.bitmap_index = 26341, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ŷ)*/
	{.bitmap_index = 26476, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ŷ)*/
	{.bitmap_index = 26588, .adv_w = 20, .box_h = 26, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ÿ)*/
	{.bitmap_index = 26718, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ź)*/
	{.bitmap_index = 26826, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ź)*/
	{.bitmap_index = 26914, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ż)*/
	{.bitmap_index = 27018, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ż)*/
	{.bitmap_index = 27098, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ž)*/
	{.bitmap_index = 27206, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ž)*/
	{.bitmap_index = 27294, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ſ)*/
	{.bitmap_index = 27399, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƀ)*/
	{.bitmap_index = 27504, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɓ)*/
	{.bitmap_index = 27609, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƃ)*/
	{.bitmap_index = 27714, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƃ)*/
	{.bitmap_index = 27819, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƅ)*/
	{.bitmap_index = 27924, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƅ)*/
	{.bitmap_index = 28029, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɔ)*/
	{.bitmap_index = 28134, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƈ)*/
	{.bitmap_index = 28239, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƈ)*/
	{.bitmap_index = 28344, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɖ)*/
	{.bitmap_index = 28449, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɗ)*/
	{.bitmap_index = 28554, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƌ)*/
	{.bitmap_index = 28659, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƌ)*/
	{.bitmap_index = 28764, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƍ)*/
	{.bitmap_index = 28869, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǝ)*/
	{.bitmap_index = 28974, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ə)*/
	{.bitmap_index = 29084, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɛ)*/
	{.bitmap_index = 29189, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƒ)*/
	{.bitmap_index = 29294, .adv_w = 16, .box_h = 27, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ƒ)*/
	{.bitmap_index = 29402, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɠ)*/
	{.bitmap_index = 29507, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɣ)*/
	{.bitmap_index = 29612, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƕ)*/
	{.bitmap_index = 29717, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɩ)*/
	{.bitmap_index = 29822, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɨ)*/
	{.bitmap_index = 29927, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƙ)*/
	{.bitmap_index = 30032, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƙ)*/
	{.bitmap_index = 30137, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƚ)*/
	{.bitmap_index = 30242, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƛ)*/
	{.bitmap_index = 30347, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɯ)*/
	{.bitmap_index = 30452, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɲ)*/
	{.bitmap_index = 30557, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƞ)*/
	{.bitmap_index = 30662, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɵ)*/
	{.bitmap_index = 30767, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ơ)*/
	{.bitmap_index = 30872, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ơ)*/
	{.bitmap_index = 30977, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƣ)*/
	{.bitmap_index = 31082, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƣ)*/
	{.bitmap_index = 31187, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƥ)*/
	{.bitmap_index = 31292, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƥ)*/
	{.bitmap_index = 31397, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʀ)*/
	{.bitmap_index = 31502, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƨ)*/
	{.bitmap_index = 31607, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƨ)*/
	{.bitmap_index = 31712, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʃ)*/
	{.bitmap_index = 31817, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƪ)*/
	{.bitmap_index = 31922, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƫ)*/
	{.bitmap_index = 32027, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƭ)*/
	{.bitmap_index = 32132, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƭ)*/
	{.bitmap_index = 32237, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʈ)*/
	{.bitmap_index = 32342, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ư)*/
	{.bitmap_index = 32447, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ư)*/
	{.bitmap_index = 32552, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʊ)*/
	{.bitmap_index = 32657, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʋ)*/
	{.bitmap_index = 32762, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƴ)*/
	{.bitmap_index = 32867, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƴ)*/
	{.bitmap_index = 32972, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƶ)*/
	{.bitmap_index = 33077, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƶ)*/
	{.bitmap_index = 33182, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʒ)*/
	{.bitmap_index = 33287, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƹ)*/
	{.bitmap_index = 33392, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƹ)*/
	{.bitmap_index = 33497, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƺ)*/
	{.bitmap_index = 33602, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƻ)*/
	{.bitmap_index = 33707, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƽ)*/
	{.bitmap_index = 33812, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƽ)*/
	{.bitmap_index = 33917, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƾ)*/
	{.bitmap_index = 34022, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ƿ)*/
	{.bitmap_index = 34127, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǀ)*/
	{.bitmap_index = 34232, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǁ)*/
	{.bitmap_index = 34337, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǂ)*/
	{.bitmap_index = 34442, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǃ)*/
	{.bitmap_index = 34547, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǆ)*/
	{.bitmap_index = 34652, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǅ)*/
	{.bitmap_index = 34757, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǆ)*/
	{.bitmap_index = 34862, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǉ)*/
	{.bitmap_index = 34967, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǈ)*/
	{.bitmap_index = 35072, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǉ)*/
	{.bitmap_index = 35177, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǌ)*/
	{.bitmap_index = 35282, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǋ)*/
	{.bitmap_index = 35387, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǌ)*/
	{.bitmap_index = 35492, .adv_w = 20, .box_h = 27, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ǎ)*/
	{.bitmap_index = 35627, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǎ)*/
	{.bitmap_index = 35719, .adv_w = 10, .box_h = 27, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(Ǐ)*/
	{.bitmap_index = 35800, .adv_w = 10, .box_h = 22, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(ǐ)*/
	{.bitmap_index = 35866, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ǒ)*/
	{.bitmap_index = 36006, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǒ)*/
	{.bitmap_index = 36098, .adv_w = 21, .box_h = 28, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ǔ)*/
	{.bitmap_index = 36238, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǔ)*/
	{.bitmap_index = 36330, .adv_w = 21, .box_h = 31, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ǖ)*/
	{.bitmap_index = 36485, .adv_w = 17, .box_h = 25, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǖ)*/
	{.bitmap_index = 36585, .adv_w = 21, .box_h = 32, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ǘ)*/
	{.bitmap_index = 36745, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǘ)*/
	{.bitmap_index = 36853, .adv_w = 21, .box_h = 32, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ǚ)*/
	{.bitmap_index = 37013, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǚ)*/
	{.bitmap_index = 37121, .adv_w = 21, .box_h = 32, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(Ǜ)*/
	{.bitmap_index = 37281, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ǜ)*/
	{.bitmap_index = 37389, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǝ)*/
	{.bitmap_index = 37494, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǟ)*/
	{.bitmap_index = 37599, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǟ)*/
	{.bitmap_index = 37704, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǡ)*/
	{.bitmap_index = 37809, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǡ)*/
	{.bitmap_index = 37914, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǣ)*/
	{.bitmap_index = 38019, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǣ)*/
	{.bitmap_index = 38124, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǥ)*/
	{.bitmap_index = 38229, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǥ)*/
	{.bitmap_index = 38334, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǧ)*/
	{.bitmap_index = 38439, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǧ)*/
	{.bitmap_index = 38544, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǩ)*/
	{.bitmap_index = 38649, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǩ)*/
	{.bitmap_index = 38754, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǫ)*/
	{.bitmap_index = 38859, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǫ)*/
	{.bitmap_index = 38964, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǭ)*/
	{.bitmap_index = 39069, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǭ)*/
	{.bitmap_index = 39174, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǯ)*/
	{.bitmap_index = 39279, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǯ)*/
	{.bitmap_index = 39384, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǰ)*/
	{.bitmap_index = 39489, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǳ)*/
	{.bitmap_index = 39594, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǲ)*/
	{.bitmap_index = 39699, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǳ)*/
	{.bitmap_index = 39804, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǵ)*/
	{.bitmap_index = 39909, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǵ)*/
	{.bitmap_index = 40014, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƕ)*/
	{.bitmap_index = 40119, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƿ)*/
	{.bitmap_index = 40224, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǹ)*/
	{.bitmap_index = 40329, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǹ)*/
	{.bitmap_index = 40434, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǻ)*/
	{.bitmap_index = 40539, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǻ)*/
	{.bitmap_index = 40644, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǽ)*/
	{.bitmap_index = 40749, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǽ)*/
	{.bitmap_index = 40854, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ǿ)*/
	{.bitmap_index = 40959, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ǿ)*/
	{.bitmap_index = 41064, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȁ)*/
	{.bitmap_index = 41169, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȁ)*/
	{.bitmap_index = 41274, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȃ)*/
	{.bitmap_index = 41379, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȃ)*/
	{.bitmap_index = 41484, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȅ)*/
	{.bitmap_index = 41589, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȅ)*/
	{.bitmap_index = 41694, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȇ)*/
	{.bitmap_index = 41799, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȇ)*/
	{.bitmap_index = 41904, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȉ)*/
	{.bitmap_index = 42009, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȉ)*/
	{.bitmap_index = 42114, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȋ)*/
	{.bitmap_index = 42219, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȋ)*/
	{.bitmap_index = 42324, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȍ)*/
	{.bitmap_index = 42429, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȍ)*/
	{.bitmap_index = 42534, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȏ)*/
	{.bitmap_index = 42639, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȏ)*/
	{.bitmap_index = 42744, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȑ)*/
	{.bitmap_index = 42849, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȑ)*/
	{.bitmap_index = 42954, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȓ)*/
	{.bitmap_index = 43059, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȓ)*/
	{.bitmap_index = 43164, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȕ)*/
	{.bitmap_index = 43269, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȕ)*/
	{.bitmap_index = 43374, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȗ)*/
	{.bitmap_index = 43479, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȗ)*/
	{.bitmap_index = 43584, .adv_w = 16, .box_h = 27, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(Ș)*/
	{.bitmap_index = 43692, .adv_w = 16, .box_h = 22, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ș)*/
	{.bitmap_index = 43780, .adv_w = 16, .box_h = 26, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(Ț)*/
	{.bitmap_index = 43884, .adv_w = 12, .box_h = 25, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*(ț)*/
	{.bitmap_index = 43959, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȝ)*/
	{.bitmap_index = 44064, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȝ)*/
	{.bitmap_index = 44169, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȟ)*/
	{.bitmap_index = 44274, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȟ)*/
	{.bitmap_index = 44379, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƞ)*/
	{.bitmap_index = 44484, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȡ)*/
	{.bitmap_index = 44589, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȣ)*/
	{.bitmap_index = 44694, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȣ)*/
	{.bitmap_index = 44799, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȥ)*/
	{.bitmap_index = 44904, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȥ)*/
	{.bitmap_index = 45009, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȧ)*/
	{.bitmap_index = 45114, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȧ)*/
	{.bitmap_index = 45219, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȩ)*/
	{.bitmap_index = 45324, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȩ)*/
	{.bitmap_index = 45429, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȫ)*/
	{.bitmap_index = 45534, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȫ)*/
	{.bitmap_index = 45639, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȭ)*/
	{.bitmap_index = 45744, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȭ)*/
	{.bitmap_index = 45849, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȯ)*/
	{.bitmap_index = 45954, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȯ)*/
	{.bitmap_index = 46059, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȱ)*/
	{.bitmap_index = 46164, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȱ)*/
	{.bitmap_index = 46269, .adv_w = 20, .box_h = 25, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ȳ)*/
	{.bitmap_index = 46394, .adv_w = 16, .box_h = 26, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ȳ)*/
	{.bitmap_index = 46498, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȴ)*/
	{.bitmap_index = 46603, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȵ)*/
	{.bitmap_index = 46708, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȶ)*/
	{.bitmap_index = 46813, .adv_w = 6, .box_h = 21, .box_w = 8, .ofs_x = -2, .ofs_y = 0},/*(ȷ)*/
	{.bitmap_index = 46855, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȸ)*/
	{.bitmap_index = 46960, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȹ)*/
	{.bitmap_index = 47065, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ⱥ)*/
	{.bitmap_index = 47170, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ȼ)*/
	{.bitmap_index = 47275, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȼ)*/
	{.bitmap_index = 47380, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƚ)*/
	{.bitmap_index = 47485, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ⱦ)*/
	{.bitmap_index = 47590, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ȿ)*/
	{.bitmap_index = 47695, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɀ)*/
	{.bitmap_index = 47800, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɂ)*/
	{.bitmap_index = 47905, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɂ)*/
	{.bitmap_index = 48010, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ƀ)*/
	{.bitmap_index = 48115, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʉ)*/
	{.bitmap_index = 48220, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ʌ)*/
	{.bitmap_index = 48325, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɇ)*/
	{.bitmap_index = 48430, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɇ)*/
	{.bitmap_index = 48535, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɉ)*/
	{.bitmap_index = 48640, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɉ)*/
	{.bitmap_index = 48745, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɋ)*/
	{.bitmap_index = 48850, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɋ)*/
	{.bitmap_index = 48955, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɍ)*/
	{.bitmap_index = 49060, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɍ)*/
	{.bitmap_index = 49165, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ɏ)*/
	{.bitmap_index = 49270, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ɏ)*/
	{.bitmap_index = 1038490, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ͱ)*/
	{.bitmap_index = 1038535, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ͱ)*/
	{.bitmap_index = 1038568, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ͳ)*/
	{.bitmap_index = 1038613, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ͳ)*/
	{.bitmap_index = 1038655, .adv_w = 5, .box_h = 6, .box_w = 4, .ofs_x = 1, .ofs_y = 16},/*(ʹ)*/
	{.bitmap_index = 1038661, .adv_w = 5, .box_h = 6, .box_w = 4, .ofs_x = 1, .ofs_y = 3},/*(͵)*/
	{.bitmap_index = 1038667, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ͷ)*/
	{.bitmap_index = 1038712, .adv_w = 13, .box_h = 12, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ͷ)*/
	{.bitmap_index = 1038748, .adv_w = 6, .box_h = 3, .box_w = 4, .ofs_x = 2, .ofs_y = 2},/*(ͺ)*/
	{.bitmap_index = 1038751, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ͻ)*/
	{.bitmap_index = 1038784, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ͼ)*/
	{.bitmap_index = 1038817, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ͽ)*/
	{.bitmap_index = 1038850, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 3},/*(;)*/
	{.bitmap_index = 1038878, .adv_w = 8, .box_h = 15, .box_w = 8, .ofs_x = 0, .ofs_y = 6},/*(Ϳ)*/
	{.bitmap_index = 1038908, .adv_w = 8, .box_h = 6, .box_w = 8, .ofs_x = 0, .ofs_y = 17},/*(΄)*/
	{.bitmap_index = 1038920, .adv_w = 12, .box_h = 6, .box_w = 12, .ofs_x = 0, .ofs_y = 17},/*(΅)*/
	{.bitmap_index = 1038938, .adv_w = 14, .box_h = 17, .box_w = 16, .ofs_x = -2, .ofs_y = 6},/*(Ά)*/
	{.bitmap_index = 1039006, .adv_w = 5, .box_h = 3, .box_w = 4, .ofs_x = 1, .ofs_y = 15},/*(·)*/
	{.bitmap_index = 1039009, .adv_w = 12, .box_h = 17, .box_w = 16, .ofs_x = -4, .ofs_y = 6},/*(Έ)*/
	{.bitmap_index = 1039077, .adv_w = 15, .box_h = 17, .box_w = 20, .ofs_x = -5, .ofs_y = 6},/*(Ή)*/
	{.bitmap_index = 1039162, .adv_w = 8, .box_h = 17, .box_w = 12, .ofs_x = -4, .ofs_y = 6},/*(Ί)*/
	{.bitmap_index = 1039213, .adv_w = 17, .box_h = 17, .box_w = 20, .ofs_x = -3, .ofs_y = 6},/*(Ό)*/
	{.bitmap_index = 1039298, .adv_w = 15, .box_h = 17, .box_w = 20, .ofs_x = -5, .ofs_y = 6},/*(Ύ)*/
	{.bitmap_index = 1039383, .adv_w = 16, .box_h = 17, .box_w = 20, .ofs_x = -4, .ofs_y = 6},/*(Ώ)*/
	{.bitmap_index = 1039468, .adv_w = 9, .box_h = 17, .box_w = 12, .ofs_x = -3, .ofs_y = 6},/*(ΐ)*/
	{.bitmap_index = 1039519, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Α)*/
	{.bitmap_index = 1039579, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Β)*/
	{.bitmap_index = 1039624, .adv_w = 10, .box_h = 15, .box_w = 8, .ofs_x = 2, .ofs_y = 6},/*(Γ)*/
	{.bitmap_index = 1039654, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Δ)*/
	{.bitmap_index = 1039714, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ε)*/
	{.bitmap_index = 1039759, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ζ)*/
	{.bitmap_index = 1039804, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Η)*/
	{.bitmap_index = 1039849, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Θ)*/
	{.bitmap_index = 1039909, .adv_w = 6, .box_h = 15, .box_w = 4, .ofs_x = 2, .ofs_y = 6},/*(Ι)*/
	{.bitmap_index = 1039924, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Κ)*/
	{.bitmap_index = 1039969, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Λ)*/
	{.bitmap_index = 1040029, .adv_w = 22, .box_h = 15, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(Μ)*/
	{.bitmap_index = 1040104, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ν)*/
	{.bitmap_index = 1040149, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ξ)*/
	{.bitmap_index = 1040194, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ο)*/
	{.bitmap_index = 1040254, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Π)*/
	{.bitmap_index = 1040299, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ρ)*/
	{.bitmap_index = 1040344, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Σ)*/
	{.bitmap_index = 1040389, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Τ)*/
	{.bitmap_index = 1040434, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Υ)*/
	{.bitmap_index = 1040479, .adv_w = 20, .box_h = 18, .box_w = 20, .ofs_x = 0, .ofs_y = 4},/*(Φ)*/
	{.bitmap_index = 1040569, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Χ)*/
	{.bitmap_index = 1040614, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ψ)*/
	{.bitmap_index = 1040674, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ω)*/
	{.bitmap_index = 1040734, .adv_w = 9, .box_h = 19, .box_w = 12, .ofs_x = -3, .ofs_y = 6},/*(Ϊ)*/
	{.bitmap_index = 1040791, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ϋ)*/
	{.bitmap_index = 1040848, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ά)*/
	{.bitmap_index = 1040916, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(έ)*/
	{.bitmap_index = 1040967, .adv_w = 13, .box_h = 21, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ή)*/
	{.bitmap_index = 1041030, .adv_w = 7, .box_h = 17, .box_w = 8, .ofs_x = -1, .ofs_y = 6},/*(ί)*/
	{.bitmap_index = 1041064, .adv_w = 12, .box_h = 17, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ΰ)*/
	{.bitmap_index = 1041115, .adv_w = 17, .box_h = 11, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(α)*/
	{.bitmap_index = 1041159, .adv_w = 13, .box_h = 20, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(β)*/
	{.bitmap_index = 1041219, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(γ)*/
	{.bitmap_index = 1041264, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(δ)*/
	{.bitmap_index = 1041312, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ε)*/
	{.bitmap_index = 1041345, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(ζ)*/
	{.bitmap_index = 1041402, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(η)*/
	{.bitmap_index = 1041447, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(θ)*/
	{.bitmap_index = 1041495, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(ι)*/
	{.bitmap_index = 1041517, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(κ)*/
	{.bitmap_index = 1041550, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(λ)*/
	{.bitmap_index = 1041598, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(μ)*/
	{.bitmap_index = 1041643, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ν)*/
	{.bitmap_index = 1041676, .adv_w = 12, .box_h = 20, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(ξ)*/
	{.bitmap_index = 1041736, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ο)*/
	{.bitmap_index = 1041769, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(π)*/
	{.bitmap_index = 1041813, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ρ)*/
	{.bitmap_index = 1041858, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ς)*/
	{.bitmap_index = 1041903, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(σ)*/
	{.bitmap_index = 1041936, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(τ)*/
	{.bitmap_index = 1041969, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(υ)*/
	{.bitmap_index = 1042002, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(φ)*/
	{.bitmap_index = 1042082, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(χ)*/
	{.bitmap_index = 1042127, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(ψ)*/
	{.bitmap_index = 1042207, .adv_w = 17, .box_h = 11, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ω)*/
	{.bitmap_index = 1042251, .adv_w = 10, .box_h = 16, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(ϊ)*/
	{.bitmap_index = 1042299, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ϋ)*/
	{.bitmap_index = 1042347, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ό)*/
	{.bitmap_index = 1042398, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ύ)*/
	{.bitmap_index = 1042449, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ώ)*/
	{.bitmap_index = 1042517, .adv_w = 14, .box_h = 19, .box_w = 12, .ofs_x = 2, .ofs_y = 2},/*(Ϗ)*/
	{.bitmap_index = 1042574, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ϐ)*/
	{.bitmap_index = 1042622, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(ϑ)*/
	{.bitmap_index = 1042686, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ϒ)*/
	{.bitmap_index = 1042731, .adv_w = 16, .box_h = 17, .box_w = 20, .ofs_x = -4, .ofs_y = 6},/*(ϓ)*/
	{.bitmap_index = 1042816, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ϔ)*/
	{.bitmap_index = 1042873, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(ϕ)*/
	{.bitmap_index = 1042933, .adv_w = 20, .box_h = 12, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(ϖ)*/
	{.bitmap_index = 1042993, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*(ϗ)*/
	{.bitmap_index = 1043053, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ϙ)*/
	{.bitmap_index = 1043113, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ϙ)*/
	{.bitmap_index = 1043158, .adv_w = 13, .box_h = 20, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(Ϛ)*/
	{.bitmap_index = 1043218, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ϛ)*/
	{.bitmap_index = 1043263, .adv_w = 10, .box_h = 15, .box_w = 8, .ofs_x = 2, .ofs_y = 6},/*(Ϝ)*/
	{.bitmap_index = 1043293, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ϝ)*/
	{.bitmap_index = 1043338, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ϟ)*/
	{.bitmap_index = 1043398, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(ϟ)*/
	{.bitmap_index = 1043443, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ϡ)*/
	{.bitmap_index = 1043503, .adv_w = 16, .box_h = 19, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*(ϡ)*/
	{.bitmap_index = 1043579, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 1},/*(Ϣ)*/
	{.bitmap_index = 1043679, .adv_w = 21, .box_h = 16, .box_w = 20, .ofs_x = 1, .ofs_y = 1},/*(ϣ)*/
	{.bitmap_index = 1043759, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(Ϥ)*/
	{.bitmap_index = 1043804, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ϥ)*/
	{.bitmap_index = 1043849, .adv_w = 14, .box_h = 21, .box_w = 12, .ofs_x = 2, .ofs_y = 1},/*(Ϧ)*/
	{.bitmap_index = 1043912, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ϧ)*/
	{.bitmap_index = 1043945, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(Ϩ)*/
	{.bitmap_index = 1043990, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ϩ)*/
	{.bitmap_index = 1044023, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ϫ)*/
	{.bitmap_index = 1044083, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ϫ)*/
	{.bitmap_index = 1044116, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ϭ)*/
	{.bitmap_index = 1044180, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ϭ)*/
	{.bitmap_index = 1044231, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ϯ)*/
	{.bitmap_index = 1044276, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(ϯ)*/
	{.bitmap_index = 1044330, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(ϰ)*/
	{.bitmap_index = 1044374, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(ϱ)*/
	{.bitmap_index = 1044422, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ϲ)*/
	{.bitmap_index = 1044455, .adv_w = 7, .box_h = 20, .box_w = 8, .ofs_x = -1, .ofs_y = 2},/*(ϳ)*/
	{.bitmap_index = 1044495, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ϴ)*/
	{.bitmap_index = 1044555, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ϵ)*/
	{.bitmap_index = 1044588, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(϶)*/
	{.bitmap_index = 1044621, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ϸ)*/
	{.bitmap_index = 1044666, .adv_w = 15, .box_h = 20, .box_w = 16, .ofs_x = -1, .ofs_y = 2},/*(ϸ)*/
	{.bitmap_index = 1044746, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(Ϲ)*/
	{.bitmap_index = 1044791, .adv_w = 18, .box_h = 15, .box_w = 16, .ofs_x = 2, .ofs_y = 6},/*(Ϻ)*/
	{.bitmap_index = 1044851, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ϻ)*/
	{.bitmap_index = 1044896, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(ϼ)*/
	{.bitmap_index = 1044941, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ͻ)*/
	{.bitmap_index = 1044986, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(Ͼ)*/
	{.bitmap_index = 1045031, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Ͽ)*/
	{.bitmap_index = 49375, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ѐ)*/
	{.bitmap_index = 49483, .adv_w = 17, .box_h = 26, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ё)*/
	{.bitmap_index = 49587, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(Ђ)*/
	{.bitmap_index = 49719, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ѓ)*/
	{.bitmap_index = 49827, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(Є)*/
	{.bitmap_index = 49915, .adv_w = 16, .box_h = 22, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(Ѕ)*/
	{.bitmap_index = 50003, .adv_w = 6, .box_h = 20, .box_w = 4, .ofs_x = 2, .ofs_y = 6},/*(І)*/
	{.bitmap_index = 50023, .adv_w = 11, .box_h = 26, .box_w = 12, .ofs_x = -1, .ofs_y = 6},/*(Ї)*/
	{.bitmap_index = 50101, .adv_w = 12, .box_h = 21, .box_w = 12, .ofs_x = 0, .ofs_y = 5},/*(Ј)*/
	{.bitmap_index = 50164, .adv_w = 28, .box_h = 21, .box_w = 28, .ofs_x = 0, .ofs_y = 5},/*(Љ)*/
	{.bitmap_index = 50311, .adv_w = 29, .box_h = 20, .box_w = 28, .ofs_x = 1, .ofs_y = 6},/*(Њ)*/
	{.bitmap_index = 50451, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ћ)*/
	{.bitmap_index = 50551, .adv_w = 17, .box_h = 27, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ќ)*/
	{.bitmap_index = 50659, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ѝ)*/
	{.bitmap_index = 50794, .adv_w = 20, .box_h = 28, .box_w = 20, .ofs_x = 0, .ofs_y = 5},/*(Ў)*/
	{.bitmap_index = 50934, .adv_w = 21, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = 3},/*(Џ)*/
	{.bitmap_index = 51049, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(А)*/
	{.bitmap_index = 51149, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Б)*/
	{.bitmap_index = 51229, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(В)*/
	{.bitmap_index = 51309, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Г)*/
	{.bitmap_index = 51389, .adv_w = 21, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = 3},/*(Д)*/
	{.bitmap_index = 51504, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Е)*/
	{.bitmap_index = 51584, .adv_w = 28, .box_h = 20, .box_w = 28, .ofs_x = 0, .ofs_y = 6},/*(Ж)*/
	{.bitmap_index = 51724, .adv_w = 16, .box_h = 22, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(З)*/
	{.bitmap_index = 51812, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(И)*/
	{.bitmap_index = 51912, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Й)*/
	{.bitmap_index = 52047, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(К)*/
	{.bitmap_index = 52127, .adv_w = 20, .box_h = 21, .box_w = 20, .ofs_x = 0, .ofs_y = 5},/*(Л)*/
	{.bitmap_index = 52232, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(М)*/
	{.bitmap_index = 52352, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Н)*/
	{.bitmap_index = 52452, .adv_w = 21, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(О)*/
	{.bitmap_index = 52562, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(П)*/
	{.bitmap_index = 52662, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Р)*/
	{.bitmap_index = 52742, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(С)*/
	{.bitmap_index = 52830, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Т)*/
	{.bitmap_index = 52910, .adv_w = 20, .box_h = 21, .box_w = 20, .ofs_x = 0, .ofs_y = 5},/*(У)*/
	{.bitmap_index = 53015, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ф)*/
	{.bitmap_index = 53115, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Х)*/
	{.bitmap_index = 53215, .adv_w = 21, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = 3},/*(Ц)*/
	{.bitmap_index = 53330, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ч)*/
	{.bitmap_index = 53410, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(Ш)*/
	{.bitmap_index = 53530, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 3},/*(Щ)*/
	{.bitmap_index = 53668, .adv_w = 20, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = 6},/*(Ъ)*/
	{.bitmap_index = 53768, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(Ы)*/
	{.bitmap_index = 53868, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ь)*/
	{.bitmap_index = 53948, .adv_w = 20, .box_h = 22, .box_w = 20, .ofs_x = 0, .ofs_y = 5},/*(Э)*/
	{.bitmap_index = 54058, .adv_w = 29, .box_h = 22, .box_w = 28, .ofs_x = 1, .ofs_y = 5},/*(Ю)*/
	{.bitmap_index = 54212, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Я)*/
	{.bitmap_index = 54292, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(а)*/
	{.bitmap_index = 54360, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(б)*/
	{.bitmap_index = 54452, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(в)*/
	{.bitmap_index = 54512, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(г)*/
	{.bitmap_index = 54557, .adv_w = 20, .box_h = 18, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*(д)*/
	{.bitmap_index = 54647, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(е)*/
	{.bitmap_index = 54715, .adv_w = 24, .box_h = 15, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(ж)*/
	{.bitmap_index = 54805, .adv_w = 12, .box_h = 17, .box_w = 12, .ofs_x = 0, .ofs_y = 5},/*(з)*/
	{.bitmap_index = 54856, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(и)*/
	{.bitmap_index = 54916, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(й)*/
	{.bitmap_index = 55004, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(к)*/
	{.bitmap_index = 55064, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(л)*/
	{.bitmap_index = 55128, .adv_w = 21, .box_h = 15, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(м)*/
	{.bitmap_index = 55203, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(н)*/
	{.bitmap_index = 55263, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(о)*/
	{.bitmap_index = 55331, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(п)*/
	{.bitmap_index = 55391, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 0},/*(р)*/
	{.bitmap_index = 55479, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(с)*/
	{.bitmap_index = 55547, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(т)*/
	{.bitmap_index = 55592, .adv_w = 16, .box_h = 21, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(у)*/
	{.bitmap_index = 55676, .adv_w = 21, .box_h = 27, .box_w = 20, .ofs_x = 1, .ofs_y = 0},/*(ф)*/
	{.bitmap_index = 55811, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(х)*/
	{.bitmap_index = 55871, .adv_w = 17, .box_h = 18, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(ц)*/
	{.bitmap_index = 55943, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ч)*/
	{.bitmap_index = 56003, .adv_w = 21, .box_h = 15, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(ш)*/
	{.bitmap_index = 56078, .adv_w = 25, .box_h = 18, .box_w = 24, .ofs_x = 1, .ofs_y = 3},/*(щ)*/
	{.bitmap_index = 56186, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(ъ)*/
	{.bitmap_index = 56246, .adv_w = 21, .box_h = 15, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(ы)*/
	{.bitmap_index = 56321, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ь)*/
	{.bitmap_index = 56381, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(э)*/
	{.bitmap_index = 56449, .adv_w = 21, .box_h = 17, .box_w = 20, .ofs_x = 1, .ofs_y = 5},/*(ю)*/
	{.bitmap_index = 56534, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(я)*/
	{.bitmap_index = 56594, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ѐ)*/
	{.bitmap_index = 56686, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ё)*/
	{.bitmap_index = 56770, .adv_w = 15, .box_h = 27, .box_w = 16, .ofs_x = -1, .ofs_y = 0},/*(ђ)*/
	{.bitmap_index = 56878, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ѓ)*/
	{.bitmap_index = 56944, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(є)*/
	{.bitmap_index = 57012, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(ѕ)*/
	{.bitmap_index = 57080, .adv_w = 9, .box_h = 21, .box_w = 8, .ofs_x = 1, .ofs_y = 6},/*(і)*/
	{.bitmap_index = 57122, .adv_w = 10, .box_h = 20, .box_w = 12, .ofs_x = -2, .ofs_y = 6},/*(ї)*/
	{.bitmap_index = 57182, .adv_w = 6, .box_h = 27, .box_w = 8, .ofs_x = -2, .ofs_y = 0},/*(ј)*/
	{.bitmap_index = 57236, .adv_w = 24, .box_h = 16, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(љ)*/
	{.bitmap_index = 57332, .adv_w = 25, .box_h = 15, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(њ)*/
	{.bitmap_index = 57422, .adv_w = 15, .box_h = 21, .box_w = 16, .ofs_x = -1, .ofs_y = 6},/*(ћ)*/
	{.bitmap_index = 57506, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ќ)*/
	{.bitmap_index = 57594, .adv_w = 17, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ѝ)*/
	{.bitmap_index = 57678, .adv_w = 16, .box_h = 28, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*(ў)*/
	{.bitmap_index = 57790, .adv_w = 17, .box_h = 18, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(џ)*/
	{.bitmap_index = 57862, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѡ)*/
	{.bitmap_index = 57967, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѡ)*/
	{.bitmap_index = 58072, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѣ)*/
	{.bitmap_index = 58177, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѣ)*/
	{.bitmap_index = 58282, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѥ)*/
	{.bitmap_index = 58387, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѥ)*/
	{.bitmap_index = 58492, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѧ)*/
	{.bitmap_index = 58597, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѧ)*/
	{.bitmap_index = 58702, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѩ)*/
	{.bitmap_index = 58807, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѩ)*/
	{.bitmap_index = 58912, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѫ)*/
	{.bitmap_index = 59017, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѫ)*/
	{.bitmap_index = 59122, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѭ)*/
	{.bitmap_index = 59227, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѭ)*/
	{.bitmap_index = 59332, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѯ)*/
	{.bitmap_index = 59437, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѯ)*/
	{.bitmap_index = 59542, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѱ)*/
	{.bitmap_index = 59647, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѱ)*/
	{.bitmap_index = 59752, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѳ)*/
	{.bitmap_index = 59857, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѳ)*/
	{.bitmap_index = 59962, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѵ)*/
	{.bitmap_index = 60067, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѵ)*/
	{.bitmap_index = 60172, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѷ)*/
	{.bitmap_index = 60277, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѷ)*/
	{.bitmap_index = 60382, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѹ)*/
	{.bitmap_index = 60487, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѹ)*/
	{.bitmap_index = 60592, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѻ)*/
	{.bitmap_index = 60697, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѻ)*/
	{.bitmap_index = 60802, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѽ)*/
	{.bitmap_index = 60907, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѽ)*/
	{.bitmap_index = 61012, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ѿ)*/
	{.bitmap_index = 61117, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ѿ)*/
	{.bitmap_index = 61222, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҁ)*/
	{.bitmap_index = 61327, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҁ)*/
	{.bitmap_index = 61432, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҂)*/
	{.bitmap_index = 61537, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҃)*/
	{.bitmap_index = 61642, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҄)*/
	{.bitmap_index = 61747, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҅)*/
	{.bitmap_index = 61852, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҆)*/
	{.bitmap_index = 61957, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҇)*/
	{.bitmap_index = 62062, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҈)*/
	{.bitmap_index = 62167, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(҉)*/
	{.bitmap_index = 62272, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҋ)*/
	{.bitmap_index = 62377, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҋ)*/
	{.bitmap_index = 62482, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҍ)*/
	{.bitmap_index = 62587, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҍ)*/
	{.bitmap_index = 62692, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҏ)*/
	{.bitmap_index = 62797, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҏ)*/
	{.bitmap_index = 62902, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ґ)*/
	{.bitmap_index = 62994, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ґ)*/
	{.bitmap_index = 63048, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ғ)*/
	{.bitmap_index = 63153, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ғ)*/
	{.bitmap_index = 63258, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҕ)*/
	{.bitmap_index = 63363, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҕ)*/
	{.bitmap_index = 63468, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Җ)*/
	{.bitmap_index = 63573, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(җ)*/
	{.bitmap_index = 63678, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҙ)*/
	{.bitmap_index = 63783, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҙ)*/
	{.bitmap_index = 63888, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Қ)*/
	{.bitmap_index = 63993, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(қ)*/
	{.bitmap_index = 64098, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҝ)*/
	{.bitmap_index = 64203, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҝ)*/
	{.bitmap_index = 64308, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҟ)*/
	{.bitmap_index = 64413, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҟ)*/
	{.bitmap_index = 64518, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҡ)*/
	{.bitmap_index = 64623, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҡ)*/
	{.bitmap_index = 64728, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ң)*/
	{.bitmap_index = 64833, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ң)*/
	{.bitmap_index = 64938, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҥ)*/
	{.bitmap_index = 65043, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҥ)*/
	{.bitmap_index = 65148, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҧ)*/
	{.bitmap_index = 65253, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҧ)*/
	{.bitmap_index = 65358, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҩ)*/
	{.bitmap_index = 65463, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҩ)*/
	{.bitmap_index = 65568, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҫ)*/
	{.bitmap_index = 65673, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҫ)*/
	{.bitmap_index = 65778, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҭ)*/
	{.bitmap_index = 65883, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҭ)*/
	{.bitmap_index = 65988, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ү)*/
	{.bitmap_index = 66093, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ү)*/
	{.bitmap_index = 66198, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ұ)*/
	{.bitmap_index = 66303, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ұ)*/
	{.bitmap_index = 66408, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҳ)*/
	{.bitmap_index = 66513, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҳ)*/
	{.bitmap_index = 66618, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҵ)*/
	{.bitmap_index = 66723, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҵ)*/
	{.bitmap_index = 66828, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҷ)*/
	{.bitmap_index = 66933, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҷ)*/
	{.bitmap_index = 67038, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҹ)*/
	{.bitmap_index = 67143, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҹ)*/
	{.bitmap_index = 67248, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Һ)*/
	{.bitmap_index = 67353, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(һ)*/
	{.bitmap_index = 67458, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҽ)*/
	{.bitmap_index = 67563, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҽ)*/
	{.bitmap_index = 67668, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ҿ)*/
	{.bitmap_index = 67773, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ҿ)*/
	{.bitmap_index = 67878, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӏ)*/
	{.bitmap_index = 67983, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӂ)*/
	{.bitmap_index = 68088, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӂ)*/
	{.bitmap_index = 68193, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӄ)*/
	{.bitmap_index = 68298, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӄ)*/
	{.bitmap_index = 68403, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӆ)*/
	{.bitmap_index = 68508, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӆ)*/
	{.bitmap_index = 68613, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӈ)*/
	{.bitmap_index = 68718, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӈ)*/
	{.bitmap_index = 68823, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӊ)*/
	{.bitmap_index = 68928, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӊ)*/
	{.bitmap_index = 69033, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӌ)*/
	{.bitmap_index = 69138, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӌ)*/
	{.bitmap_index = 69243, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӎ)*/
	{.bitmap_index = 69348, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӎ)*/
	{.bitmap_index = 69453, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӏ)*/
	{.bitmap_index = 69558, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӑ)*/
	{.bitmap_index = 69663, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӑ)*/
	{.bitmap_index = 69768, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӓ)*/
	{.bitmap_index = 69873, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӓ)*/
	{.bitmap_index = 69978, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӕ)*/
	{.bitmap_index = 70083, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӕ)*/
	{.bitmap_index = 70188, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӗ)*/
	{.bitmap_index = 70293, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӗ)*/
	{.bitmap_index = 70398, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ә)*/
	{.bitmap_index = 70503, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ә)*/
	{.bitmap_index = 70608, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӛ)*/
	{.bitmap_index = 70713, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӛ)*/
	{.bitmap_index = 70818, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӝ)*/
	{.bitmap_index = 70923, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӝ)*/
	{.bitmap_index = 71028, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӟ)*/
	{.bitmap_index = 71133, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӟ)*/
	{.bitmap_index = 71238, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӡ)*/
	{.bitmap_index = 71343, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӡ)*/
	{.bitmap_index = 71448, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӣ)*/
	{.bitmap_index = 71553, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӣ)*/
	{.bitmap_index = 71658, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӥ)*/
	{.bitmap_index = 71763, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӥ)*/
	{.bitmap_index = 71868, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӧ)*/
	{.bitmap_index = 71973, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӧ)*/
	{.bitmap_index = 72078, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ө)*/
	{.bitmap_index = 72183, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ө)*/
	{.bitmap_index = 72288, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӫ)*/
	{.bitmap_index = 72393, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӫ)*/
	{.bitmap_index = 72498, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӭ)*/
	{.bitmap_index = 72603, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӭ)*/
	{.bitmap_index = 72708, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӯ)*/
	{.bitmap_index = 72813, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӯ)*/
	{.bitmap_index = 72918, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӱ)*/
	{.bitmap_index = 73023, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӱ)*/
	{.bitmap_index = 73128, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӳ)*/
	{.bitmap_index = 73233, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӳ)*/
	{.bitmap_index = 73338, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӵ)*/
	{.bitmap_index = 73443, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӵ)*/
	{.bitmap_index = 73548, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӷ)*/
	{.bitmap_index = 73653, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӷ)*/
	{.bitmap_index = 73758, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӹ)*/
	{.bitmap_index = 73863, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӹ)*/
	{.bitmap_index = 73968, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӻ)*/
	{.bitmap_index = 74073, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӻ)*/
	{.bitmap_index = 74178, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӽ)*/
	{.bitmap_index = 74283, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӽ)*/
	{.bitmap_index = 74388, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(Ӿ)*/
	{.bitmap_index = 74493, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ӿ)*/
	{.bitmap_index = 1045076, .adv_w = 18, .box_h = 16, .box_w = 16, .ofs_x = 2, .ofs_y = 5},/*(Ա)*/
	{.bitmap_index = 1045140, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Բ)*/
	{.bitmap_index = 1045185, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Գ)*/
	{.bitmap_index = 1045245, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Դ)*/
	{.bitmap_index = 1045305, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ե)*/
	{.bitmap_index = 1045350, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Զ)*/
	{.bitmap_index = 1045410, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Է)*/
	{.bitmap_index = 1045455, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ը)*/
	{.bitmap_index = 1045500, .adv_w = 22, .box_h = 15, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(Թ)*/
	{.bitmap_index = 1045575, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ժ)*/
	{.bitmap_index = 1045635, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ի)*/
	{.bitmap_index = 1045680, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Լ)*/
	{.bitmap_index = 1045725, .adv_w = 18, .box_h = 15, .box_w = 16, .ofs_x = 2, .ofs_y = 6},/*(Խ)*/
	{.bitmap_index = 1045785, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ծ)*/
	{.bitmap_index = 1045845, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(Կ)*/
	{.bitmap_index = 1045890, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(Հ)*/
	{.bitmap_index = 1045935, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ձ)*/
	{.bitmap_index = 1045995, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ղ)*/
	{.bitmap_index = 1046055, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ճ)*/
	{.bitmap_index = 1046115, .adv_w = 18, .box_h = 15, .box_w = 16, .ofs_x = 2, .ofs_y = 6},/*(Մ)*/
	{.bitmap_index = 1046175, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Յ)*/
	{.bitmap_index = 1046235, .adv_w = 15, .box_h = 15, .box_w = 16, .ofs_x = -1, .ofs_y = 6},/*(Ն)*/
	{.bitmap_index = 1046295, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Շ)*/
	{.bitmap_index = 1046355, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ո)*/
	{.bitmap_index = 1046400, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(Չ)*/
	{.bitmap_index = 1046464, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Պ)*/
	{.bitmap_index = 1046524, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ջ)*/
	{.bitmap_index = 1046584, .adv_w = 18, .box_h = 15, .box_w = 16, .ofs_x = 2, .ofs_y = 6},/*(Ռ)*/
	{.bitmap_index = 1046644, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ս)*/
	{.bitmap_index = 1046689, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Վ)*/
	{.bitmap_index = 1046749, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Տ)*/
	{.bitmap_index = 1046809, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ր)*/
	{.bitmap_index = 1046854, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ց)*/
	{.bitmap_index = 1046914, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 6},/*(Ւ)*/
	{.bitmap_index = 1046959, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Փ)*/
	{.bitmap_index = 1047019, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(Ք)*/
	{.bitmap_index = 1047079, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Օ)*/
	{.bitmap_index = 1047139, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(Ֆ)*/
	{.bitmap_index = 1047199, .adv_w = 9, .box_h = 6, .box_w = 8, .ofs_x = 1, .ofs_y = 16},/*(ՙ)*/
	{.bitmap_index = 1047211, .adv_w = 8, .box_h = 6, .box_w = 8, .ofs_x = 0, .ofs_y = 16},/*(՚)*/
	{.bitmap_index = 1047223, .adv_w = 7, .box_h = 5, .box_w = 8, .ofs_x = -1, .ofs_y = 18},/*(՛)*/
	{.bitmap_index = 1047233, .adv_w = 7, .box_h = 6, .box_w = 8, .ofs_x = -1, .ofs_y = 18},/*(՜)*/
	{.bitmap_index = 1047245, .adv_w = 8, .box_h = 5, .box_w = 8, .ofs_x = 0, .ofs_y = 19},/*(՝)*/
	{.bitmap_index = 1047255, .adv_w = 8, .box_h = 6, .box_w = 8, .ofs_x = 0, .ofs_y = 19},/*(՞)*/
	{.bitmap_index = 1047267, .adv_w = 0, .box_h = 4, .box_w = 12, .ofs_x = -12, .ofs_y = 22},/*(՟)*/
	{.bitmap_index = 1047279, .adv_w = 12, .box_h = 20, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*(ՠ)*/
	{.bitmap_index = 1047339, .adv_w = 21, .box_h = 11, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(ա)*/
	{.bitmap_index = 1047394, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(բ)*/
	{.bitmap_index = 1047439, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(գ)*/
	{.bitmap_index = 1047499, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(դ)*/
	{.bitmap_index = 1047559, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ե)*/
	{.bitmap_index = 1047607, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(զ)*/
	{.bitmap_index = 1047667, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(է)*/
	{.bitmap_index = 1047715, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ը)*/
	{.bitmap_index = 1047760, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(թ)*/
	{.bitmap_index = 1047820, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ժ)*/
	{.bitmap_index = 1047884, .adv_w = 13, .box_h = 20, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ի)*/
	{.bitmap_index = 1047944, .adv_w = 9, .box_h = 15, .box_w = 8, .ofs_x = 1, .ofs_y = 2},/*(լ)*/
	{.bitmap_index = 1047974, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 2},/*(խ)*/
	{.bitmap_index = 1048074, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ծ)*/
	{.bitmap_index = 1048122, .adv_w = 13, .box_h = 20, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(կ)*/
	{.bitmap_index = 1048182, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(հ)*/
	{.bitmap_index = 1048230, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ձ)*/
	{.bitmap_index = 1048278, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(ղ)*/
	{.bitmap_index = 1048338, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 6},/*(ճ)*/
	{.bitmap_index = 1048386, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(մ)*/
	{.bitmap_index = 1048450, .adv_w = 7, .box_h = 15, .box_w = 8, .ofs_x = -1, .ofs_y = 2},/*(յ)*/
	{.bitmap_index = 1048480, .adv_w = 14, .box_h = 16, .box_w = 16, .ofs_x = -2, .ofs_y = 6},/*(ն)*/
	{.bitmap_index = 1048544, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(շ)*/
	{.bitmap_index = 1048589, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ո)*/
	{.bitmap_index = 1048622, .adv_w = 8, .box_h = 15, .box_w = 8, .ofs_x = 0, .ofs_y = 2},/*(չ)*/
	{.bitmap_index = 1048652, .adv_w = 21, .box_h = 15, .box_w = 20, .ofs_x = 1, .ofs_y = 2},/*(պ)*/
	{.bitmap_index = 1048727, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ջ)*/
	{.bitmap_index = 1048772, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ռ)*/
	{.bitmap_index = 1048805, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ս)*/
	{.bitmap_index = 1048838, .adv_w = 17, .box_h = 20, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(վ)*/
	{.bitmap_index = 1048918, .adv_w = 21, .box_h = 11, .box_w = 20, .ofs_x = 1, .ofs_y = 6},/*(տ)*/
	{.bitmap_index = 1048973, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ր)*/
	{.bitmap_index = 1049018, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(ց)*/
	{.bitmap_index = 1049063, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(ւ)*/
	{.bitmap_index = 1049096, .adv_w = 21, .box_h = 20, .box_w = 20, .ofs_x = 1, .ofs_y = 2},/*(փ)*/
	{.bitmap_index = 1049196, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*(ք)*/
	{.bitmap_index = 1049256, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 6},/*(օ)*/
	{.bitmap_index = 1049289, .adv_w = 16, .box_h = 20, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*(ֆ)*/
	{.bitmap_index = 1049369, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(և)*/
	{.bitmap_index = 1049433, .adv_w = 12, .box_h = 20, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*(ֈ)*/
	{.bitmap_index = 1049493, .adv_w = 6, .box_h = 11, .box_w = 4, .ofs_x = 2, .ofs_y = 6},/*(։)*/
	{.bitmap_index = 1049504, .adv_w = 8, .box_h = 2, .box_w = 8, .ofs_x = 0, .ofs_y = 11},/*(֊)*/
	{.bitmap_index = 1049508, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 2},/*(֍)*/
	{.bitmap_index = 1049634, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 2},/*(֎)*/
	{.bitmap_index = 1049760, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(֏)*/
	{.bitmap_index = 74598, .adv_w = 9, .box_h = 8, .box_w = 8, .ofs_x = 1, .ofs_y = 19},/*(‘)*/
	{.bitmap_index = 74614, .adv_w = 9, .box_h = 8, .box_w = 8, .ofs_x = 1, .ofs_y = 19},/*(’)*/
	{.bitmap_index = 74630, .adv_w = 13, .box_h = 8, .box_w = 12, .ofs_x = 1, .ofs_y = 19},/*(“)*/
	{.bitmap_index = 74654, .adv_w = 13, .box_h = 8, .box_w = 12, .ofs_x = 1, .ofs_y = 19},/*(”)*/
	{.bitmap_index = 74678, .adv_w = 28, .box_h = 23, .box_w = 28, .ofs_x = 0, .ofs_y = 5},/*(℃)*/
	{.bitmap_index = 74839, .adv_w = 10, .box_h = 8, .box_w = 8, .ofs_x = 2, .ofs_y = 3},/*(、)*/
	{.bitmap_index = 74855, .adv_w = 10, .box_h = 8, .box_w = 8, .ofs_x = 2, .ofs_y = 3},/*(。)*/
	{.bitmap_index = 74871, .adv_w = 25, .box_h = 23, .box_w = 16, .ofs_x = 9, .ofs_y = 5},/*(《)*/
	{.bitmap_index = 74963, .adv_w = 18, .box_h = 23, .box_w = 16, .ofs_x = 2, .ofs_y = 5},/*(》)*/
	{.bitmap_index = 75055, .adv_w = 23, .box_h = 23, .box_w = 8, .ofs_x = 15, .ofs_y = 5},/*(【)*/
	{.bitmap_index = 75101, .adv_w = 10, .box_h = 23, .box_w = 8, .ofs_x = 2, .ofs_y = 5},/*(】)*/
	{.bitmap_index = 1021483, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ぁ)*/
	{.bitmap_index = 1021547, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(あ)*/
	{.bitmap_index = 1021647, .adv_w = 21, .box_h = 12, .box_w = 16, .ofs_x = 5, .ofs_y = 6},/*(ぃ)*/
	{.bitmap_index = 1021695, .adv_w = 23, .box_h = 15, .box_w = 20, .ofs_x = 3, .ofs_y = 7},/*(い)*/
	{.bitmap_index = 1021770, .adv_w = 18, .box_h = 17, .box_w = 12, .ofs_x = 6, .ofs_y = 5},/*(ぅ)*/
	{.bitmap_index = 1021821, .adv_w = 21, .box_h = 19, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(う)*/
	{.bitmap_index = 1021897, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ぇ)*/
	{.bitmap_index = 1021961, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(え)*/
	{.bitmap_index = 1022061, .adv_w = 20, .box_h = 15, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ぉ)*/
	{.bitmap_index = 1022121, .adv_w = 26, .box_h = 19, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(お)*/
	{.bitmap_index = 1022235, .adv_w = 26, .box_h = 19, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(か)*/
	{.bitmap_index = 1022349, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(が)*/
	{.bitmap_index = 1022469, .adv_w = 20, .box_h = 20, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(き)*/
	{.bitmap_index = 1022549, .adv_w = 24, .box_h = 22, .box_w = 20, .ofs_x = 4, .ofs_y = 5},/*(ぎ)*/
	{.bitmap_index = 1022659, .adv_w = 21, .box_h = 20, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(く)*/
	{.bitmap_index = 1022739, .adv_w = 25, .box_h = 20, .box_w = 20, .ofs_x = 5, .ofs_y = 5},/*(ぐ)*/
	{.bitmap_index = 1022839, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(け)*/
	{.bitmap_index = 1022939, .adv_w = 27, .box_h = 22, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(げ)*/
	{.bitmap_index = 1023071, .adv_w = 20, .box_h = 17, .box_w = 16, .ofs_x = 4, .ofs_y = 6},/*(こ)*/
	{.bitmap_index = 1023139, .adv_w = 24, .box_h = 21, .box_w = 20, .ofs_x = 4, .ofs_y = 6},/*(ご)*/
	{.bitmap_index = 1023244, .adv_w = 20, .box_h = 20, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(さ)*/
	{.bitmap_index = 1023324, .adv_w = 24, .box_h = 21, .box_w = 20, .ofs_x = 4, .ofs_y = 5},/*(ざ)*/
	{.bitmap_index = 1023429, .adv_w = 22, .box_h = 20, .box_w = 16, .ofs_x = 6, .ofs_y = 5},/*(し)*/
	{.bitmap_index = 1023509, .adv_w = 22, .box_h = 20, .box_w = 16, .ofs_x = 6, .ofs_y = 5},/*(じ)*/
	{.bitmap_index = 1023589, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(す)*/
	{.bitmap_index = 1023709, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(ず)*/
	{.bitmap_index = 1023841, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(せ)*/
	{.bitmap_index = 1023961, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(ぜ)*/
	{.bitmap_index = 1024093, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(そ)*/
	{.bitmap_index = 1024193, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ぞ)*/
	{.bitmap_index = 1024313, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(た)*/
	{.bitmap_index = 1024413, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(だ)*/
	{.bitmap_index = 1024533, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ち)*/
	{.bitmap_index = 1024633, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ぢ)*/
	{.bitmap_index = 1024765, .adv_w = 20, .box_h = 11, .box_w = 16, .ofs_x = 4, .ofs_y = 6},/*(っ)*/
	{.bitmap_index = 1024809, .adv_w = 25, .box_h = 14, .box_w = 24, .ofs_x = 1, .ofs_y = 7},/*(つ)*/
	{.bitmap_index = 1024893, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(づ)*/
	{.bitmap_index = 1025013, .adv_w = 22, .box_h = 17, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(て)*/
	{.bitmap_index = 1025098, .adv_w = 26, .box_h = 17, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(で)*/
	{.bitmap_index = 1025200, .adv_w = 21, .box_h = 19, .box_w = 16, .ofs_x = 5, .ofs_y = 6},/*(と)*/
	{.bitmap_index = 1025276, .adv_w = 24, .box_h = 20, .box_w = 20, .ofs_x = 4, .ofs_y = 6},/*(ど)*/
	{.bitmap_index = 1025376, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(な)*/
	{.bitmap_index = 1025476, .adv_w = 23, .box_h = 19, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(に)*/
	{.bitmap_index = 1025571, .adv_w = 26, .box_h = 18, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(ぬ)*/
	{.bitmap_index = 1025679, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ね)*/
	{.bitmap_index = 1025799, .adv_w = 22, .box_h = 17, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(の)*/
	{.bitmap_index = 1025884, .adv_w = 23, .box_h = 19, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(は)*/
	{.bitmap_index = 1025979, .adv_w = 27, .box_h = 21, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ば)*/
	{.bitmap_index = 1026105, .adv_w = 27, .box_h = 21, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ぱ)*/
	{.bitmap_index = 1026231, .adv_w = 26, .box_h = 18, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ひ)*/
	{.bitmap_index = 1026339, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(び)*/
	{.bitmap_index = 1026471, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ぴ)*/
	{.bitmap_index = 1026597, .adv_w = 25, .box_h = 19, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(ふ)*/
	{.bitmap_index = 1026711, .adv_w = 25, .box_h = 19, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(ぶ)*/
	{.bitmap_index = 1026825, .adv_w = 25, .box_h = 19, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(ぷ)*/
	{.bitmap_index = 1026939, .adv_w = 25, .box_h = 11, .box_w = 24, .ofs_x = 1, .ofs_y = 9},/*(へ)*/
	{.bitmap_index = 1027005, .adv_w = 25, .box_h = 15, .box_w = 24, .ofs_x = 1, .ofs_y = 9},/*(べ)*/
	{.bitmap_index = 1027095, .adv_w = 25, .box_h = 14, .box_w = 24, .ofs_x = 1, .ofs_y = 9},/*(ぺ)*/
	{.bitmap_index = 1027179, .adv_w = 23, .box_h = 19, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ほ)*/
	{.bitmap_index = 1027274, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ぼ)*/
	{.bitmap_index = 1027406, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ぽ)*/
	{.bitmap_index = 1027538, .adv_w = 20, .box_h = 20, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ま)*/
	{.bitmap_index = 1027618, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(み)*/
	{.bitmap_index = 1027738, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(む)*/
	{.bitmap_index = 1027858, .adv_w = 22, .box_h = 19, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(め)*/
	{.bitmap_index = 1027953, .adv_w = 20, .box_h = 20, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(も)*/
	{.bitmap_index = 1028033, .adv_w = 23, .box_h = 17, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ゃ)*/
	{.bitmap_index = 1028118, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(や)*/
	{.bitmap_index = 1028244, .adv_w = 21, .box_h = 17, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(ゅ)*/
	{.bitmap_index = 1028312, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ゆ)*/
	{.bitmap_index = 1028412, .adv_w = 21, .box_h = 16, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(ょ)*/
	{.bitmap_index = 1028476, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(よ)*/
	{.bitmap_index = 1028576, .adv_w = 21, .box_h = 20, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(ら)*/
	{.bitmap_index = 1028656, .adv_w = 18, .box_h = 20, .box_w = 12, .ofs_x = 6, .ofs_y = 5},/*(り)*/
	{.bitmap_index = 1028716, .adv_w = 23, .box_h = 19, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(る)*/
	{.bitmap_index = 1028811, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(れ)*/
	{.bitmap_index = 1028931, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ろ)*/
	{.bitmap_index = 1029031, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ゎ)*/
	{.bitmap_index = 1029095, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(わ)*/
	{.bitmap_index = 1029215, .adv_w = 22, .box_h = 19, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ゐ)*/
	{.bitmap_index = 1029310, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ゑ)*/
	{.bitmap_index = 1029410, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(を)*/
	{.bitmap_index = 1029510, .adv_w = 22, .box_h = 18, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(ん)*/
	{.bitmap_index = 1029600, .adv_w = 24, .box_h = 20, .box_w = 20, .ofs_x = 4, .ofs_y = 5},/*(ゔ)*/
	{.bitmap_index = 1029700, .adv_w = 24, .box_h = 15, .box_w = 20, .ofs_x = 4, .ofs_y = 5},/*(ゕ)*/
	{.bitmap_index = 1029775, .adv_w = 21, .box_h = 15, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(ゖ)*/
	{.bitmap_index = 1029835, .adv_w = 2, .box_h = 6, .box_w = 8, .ofs_x = -6, .ofs_y = 21},/*(゙)*/
	{.bitmap_index = 1029847, .adv_w = 3, .box_h = 5, .box_w = 8, .ofs_x = -5, .ofs_y = 22},/*(゚)*/
	{.bitmap_index = 1029857, .adv_w = 8, .box_h = 6, .box_w = 8, .ofs_x = 0, .ofs_y = 21},/*(゛)*/
	{.bitmap_index = 1029869, .adv_w = 8, .box_h = 5, .box_w = 8, .ofs_x = 0, .ofs_y = 22},/*(゜)*/
	{.bitmap_index = 1029879, .adv_w = 16, .box_h = 11, .box_w = 8, .ofs_x = 8, .ofs_y = 9},/*(ゝ)*/
	{.bitmap_index = 1029901, .adv_w = 23, .box_h = 14, .box_w = 16, .ofs_x = 7, .ofs_y = 9},/*(ゞ)*/
	{.bitmap_index = 1029957, .adv_w = 23, .box_h = 21, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ゟ)*/
	{.bitmap_index = 1030062, .adv_w = 19, .box_h = 5, .box_w = 12, .ofs_x = 7, .ofs_y = 13},/*(゠)*/
	{.bitmap_index = 1030077, .adv_w = 21, .box_h = 15, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(ァ)*/
	{.bitmap_index = 1030137, .adv_w = 23, .box_h = 18, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ア)*/
	{.bitmap_index = 1030227, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ィ)*/
	{.bitmap_index = 1030291, .adv_w = 19, .box_h = 20, .box_w = 16, .ofs_x = 3, .ofs_y = 5},/*(イ)*/
	{.bitmap_index = 1030371, .adv_w = 22, .box_h = 16, .box_w = 16, .ofs_x = 6, .ofs_y = 5},/*(ゥ)*/
	{.bitmap_index = 1030435, .adv_w = 24, .box_h = 20, .box_w = 20, .ofs_x = 4, .ofs_y = 5},/*(ウ)*/
	{.bitmap_index = 1030535, .adv_w = 20, .box_h = 12, .box_w = 16, .ofs_x = 4, .ofs_y = 6},/*(ェ)*/
	{.bitmap_index = 1030583, .adv_w = 22, .box_h = 14, .box_w = 20, .ofs_x = 2, .ofs_y = 8},/*(エ)*/
	{.bitmap_index = 1030653, .adv_w = 20, .box_h = 15, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ォ)*/
	{.bitmap_index = 1030713, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(オ)*/
	{.bitmap_index = 1030813, .adv_w = 22, .box_h = 19, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(カ)*/
	{.bitmap_index = 1030908, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(ガ)*/
	{.bitmap_index = 1031034, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(キ)*/
	{.bitmap_index = 1031134, .adv_w = 27, .box_h = 21, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ギ)*/
	{.bitmap_index = 1031260, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ク)*/
	{.bitmap_index = 1031360, .adv_w = 27, .box_h = 22, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(グ)*/
	{.bitmap_index = 1031492, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ケ)*/
	{.bitmap_index = 1031592, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(ゲ)*/
	{.bitmap_index = 1031718, .adv_w = 20, .box_h = 14, .box_w = 16, .ofs_x = 4, .ofs_y = 8},/*(コ)*/
	{.bitmap_index = 1031774, .adv_w = 24, .box_h = 19, .box_w = 20, .ofs_x = 4, .ofs_y = 8},/*(ゴ)*/
	{.bitmap_index = 1031869, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(サ)*/
	{.bitmap_index = 1031969, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(ザ)*/
	{.bitmap_index = 1032095, .adv_w = 23, .box_h = 18, .box_w = 20, .ofs_x = 3, .ofs_y = 6},/*(シ)*/
	{.bitmap_index = 1032185, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(ジ)*/
	{.bitmap_index = 1032305, .adv_w = 22, .box_h = 16, .box_w = 20, .ofs_x = 2, .ofs_y = 7},/*(ス)*/
	{.bitmap_index = 1032385, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(ズ)*/
	{.bitmap_index = 1032511, .adv_w = 21, .box_h = 17, .box_w = 20, .ofs_x = 1, .ofs_y = 7},/*(セ)*/
	{.bitmap_index = 1032596, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 7},/*(ゼ)*/
	{.bitmap_index = 1032716, .adv_w = 23, .box_h = 17, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ソ)*/
	{.bitmap_index = 1032801, .adv_w = 27, .box_h = 22, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ゾ)*/
	{.bitmap_index = 1032933, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(タ)*/
	{.bitmap_index = 1033033, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ダ)*/
	{.bitmap_index = 1033165, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(チ)*/
	{.bitmap_index = 1033265, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ヂ)*/
	{.bitmap_index = 1033385, .adv_w = 20, .box_h = 14, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ッ)*/
	{.bitmap_index = 1033441, .adv_w = 23, .box_h = 18, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(ツ)*/
	{.bitmap_index = 1033531, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ヅ)*/
	{.bitmap_index = 1033663, .adv_w = 22, .box_h = 19, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(テ)*/
	{.bitmap_index = 1033758, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(デ)*/
	{.bitmap_index = 1033890, .adv_w = 20, .box_h = 20, .box_w = 12, .ofs_x = 8, .ofs_y = 5},/*(ト)*/
	{.bitmap_index = 1033950, .adv_w = 24, .box_h = 21, .box_w = 16, .ofs_x = 8, .ofs_y = 5},/*(ド)*/
	{.bitmap_index = 1034034, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ナ)*/
	{.bitmap_index = 1034134, .adv_w = 22, .box_h = 14, .box_w = 20, .ofs_x = 2, .ofs_y = 8},/*(ニ)*/
	{.bitmap_index = 1034204, .adv_w = 22, .box_h = 18, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(ヌ)*/
	{.bitmap_index = 1034294, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(ネ)*/
	{.bitmap_index = 1034414, .adv_w = 19, .box_h = 18, .box_w = 16, .ofs_x = 3, .ofs_y = 6},/*(ノ)*/
	{.bitmap_index = 1034486, .adv_w = 25, .box_h = 11, .box_w = 24, .ofs_x = 1, .ofs_y = 9},/*(ハ)*/
	{.bitmap_index = 1034552, .adv_w = 25, .box_h = 16, .box_w = 24, .ofs_x = 1, .ofs_y = 9},/*(バ)*/
	{.bitmap_index = 1034648, .adv_w = 25, .box_h = 15, .box_w = 24, .ofs_x = 1, .ofs_y = 9},/*(パ)*/
	{.bitmap_index = 1034738, .adv_w = 21, .box_h = 17, .box_w = 16, .ofs_x = 5, .ofs_y = 7},/*(ヒ)*/
	{.bitmap_index = 1034806, .adv_w = 25, .box_h = 19, .box_w = 20, .ofs_x = 5, .ofs_y = 7},/*(ビ)*/
	{.bitmap_index = 1034901, .adv_w = 25, .box_h = 17, .box_w = 20, .ofs_x = 5, .ofs_y = 7},/*(ピ)*/
	{.bitmap_index = 1034986, .adv_w = 24, .box_h = 17, .box_w = 20, .ofs_x = 4, .ofs_y = 6},/*(フ)*/
	{.bitmap_index = 1035071, .adv_w = 27, .box_h = 21, .box_w = 24, .ofs_x = 3, .ofs_y = 6},/*(ブ)*/
	{.bitmap_index = 1035197, .adv_w = 27, .box_h = 21, .box_w = 24, .ofs_x = 3, .ofs_y = 6},/*(プ)*/
	{.bitmap_index = 1035323, .adv_w = 26, .box_h = 11, .box_w = 24, .ofs_x = 2, .ofs_y = 9},/*(ヘ)*/
	{.bitmap_index = 1035389, .adv_w = 26, .box_h = 15, .box_w = 24, .ofs_x = 2, .ofs_y = 9},/*(ベ)*/
	{.bitmap_index = 1035479, .adv_w = 26, .box_h = 14, .box_w = 24, .ofs_x = 2, .ofs_y = 9},/*(ペ)*/
	{.bitmap_index = 1035563, .adv_w = 22, .box_h = 19, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ホ)*/
	{.bitmap_index = 1035658, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ボ)*/
	{.bitmap_index = 1035784, .adv_w = 26, .box_h = 20, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ポ)*/
	{.bitmap_index = 1035904, .adv_w = 22, .box_h = 14, .box_w = 20, .ofs_x = 2, .ofs_y = 7},/*(マ)*/
	{.bitmap_index = 1035974, .adv_w = 21, .box_h = 19, .box_w = 16, .ofs_x = 5, .ofs_y = 5},/*(ミ)*/
	{.bitmap_index = 1036050, .adv_w = 22, .box_h = 17, .box_w = 20, .ofs_x = 2, .ofs_y = 7},/*(ム)*/
	{.bitmap_index = 1036135, .adv_w = 22, .box_h = 18, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(メ)*/
	{.bitmap_index = 1036225, .adv_w = 22, .box_h = 16, .box_w = 20, .ofs_x = 2, .ofs_y = 7},/*(モ)*/
	{.bitmap_index = 1036305, .adv_w = 20, .box_h = 15, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ャ)*/
	{.bitmap_index = 1036365, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(ヤ)*/
	{.bitmap_index = 1036485, .adv_w = 20, .box_h = 12, .box_w = 16, .ofs_x = 4, .ofs_y = 6},/*(ュ)*/
	{.bitmap_index = 1036533, .adv_w = 22, .box_h = 14, .box_w = 20, .ofs_x = 2, .ofs_y = 8},/*(ユ)*/
	{.bitmap_index = 1036603, .adv_w = 18, .box_h = 12, .box_w = 12, .ofs_x = 6, .ofs_y = 6},/*(ョ)*/
	{.bitmap_index = 1036639, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 7},/*(ヨ)*/
	{.bitmap_index = 1036703, .adv_w = 20, .box_h = 19, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ラ)*/
	{.bitmap_index = 1036779, .adv_w = 18, .box_h = 19, .box_w = 12, .ofs_x = 6, .ofs_y = 5},/*(リ)*/
	{.bitmap_index = 1036836, .adv_w = 25, .box_h = 15, .box_w = 24, .ofs_x = 1, .ofs_y = 8},/*(ル)*/
	{.bitmap_index = 1036926, .adv_w = 21, .box_h = 16, .box_w = 16, .ofs_x = 5, .ofs_y = 7},/*(レ)*/
	{.bitmap_index = 1036990, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 7},/*(ロ)*/
	{.bitmap_index = 1037054, .adv_w = 22, .box_h = 15, .box_w = 16, .ofs_x = 6, .ofs_y = 5},/*(ヮ)*/
	{.bitmap_index = 1037114, .adv_w = 24, .box_h = 19, .box_w = 20, .ofs_x = 4, .ofs_y = 5},/*(ワ)*/
	{.bitmap_index = 1037209, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(ヰ)*/
	{.bitmap_index = 1037309, .adv_w = 22, .box_h = 14, .box_w = 20, .ofs_x = 2, .ofs_y = 8},/*(ヱ)*/
	{.bitmap_index = 1037379, .adv_w = 20, .box_h = 19, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ヲ)*/
	{.bitmap_index = 1037455, .adv_w = 24, .box_h = 15, .box_w = 20, .ofs_x = 4, .ofs_y = 7},/*(ン)*/
	{.bitmap_index = 1037530, .adv_w = 27, .box_h = 22, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ヴ)*/
	{.bitmap_index = 1037662, .adv_w = 20, .box_h = 15, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ヵ)*/
	{.bitmap_index = 1037722, .adv_w = 20, .box_h = 16, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ヶ)*/
	{.bitmap_index = 1037786, .adv_w = 27, .box_h = 23, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ヷ)*/
	{.bitmap_index = 1037924, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(ヸ)*/
	{.bitmap_index = 1038056, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 7},/*(ヹ)*/
	{.bitmap_index = 1038176, .adv_w = 27, .box_h = 23, .box_w = 24, .ofs_x = 3, .ofs_y = 5},/*(ヺ)*/
	{.bitmap_index = 1038314, .adv_w = 14, .box_h = 4, .box_w = 4, .ofs_x = 10, .ofs_y = 13},/*(・)*/
	{.bitmap_index = 1038318, .adv_w = 22, .box_h = 4, .box_w = 20, .ofs_x = 2, .ofs_y = 13},/*(ー)*/
	{.bitmap_index = 1038338, .adv_w = 19, .box_h = 8, .box_w = 12, .ofs_x = 7, .ofs_y = 11},/*(ヽ)*/
	{.bitmap_index = 1038362, .adv_w = 23, .box_h = 13, .box_w = 16, .ofs_x = 7, .ofs_y = 10},/*(ヾ)*/
	{.bitmap_index = 1038414, .adv_w = 20, .box_h = 19, .box_w = 16, .ofs_x = 4, .ofs_y = 5},/*(ヿ)*/
	{.bitmap_index = 75147, .adv_w = 25, .box_h = 4, .box_w = 24, .ofs_x = 1, .ofs_y = 15},/*(一)*/
	{.bitmap_index = 75171, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(丁)*/
	{.bitmap_index = 75303, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(七)*/
	{.bitmap_index = 75441, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(万)*/
	{.bitmap_index = 75573, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(丈)*/
	{.bitmap_index = 75717, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(三)*/
	{.bitmap_index = 75837, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(上)*/
	{.bitmap_index = 75969, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(下)*/
	{.bitmap_index = 76101, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(丌)*/
	{.bitmap_index = 76233, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(不)*/
	{.bitmap_index = 76365, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(与)*/
	{.bitmap_index = 76503, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(丐)*/
	{.bitmap_index = 76635, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(丑)*/
	{.bitmap_index = 76761, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(专)*/
	{.bitmap_index = 76905, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(且)*/
	{.bitmap_index = 77037, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(丕)*/
	{.bitmap_index = 77163, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(世)*/
	{.bitmap_index = 77295, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(丘)*/
	{.bitmap_index = 77427, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(丙)*/
	{.bitmap_index = 77559, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(业)*/
	{.bitmap_index = 77691, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(丛)*/
	{.bitmap_index = 77823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(东)*/
	{.bitmap_index = 77961, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(丝)*/
	{.bitmap_index = 78099, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(丞)*/
	{.bitmap_index = 78231, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(丢)*/
	{.bitmap_index = 78369, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(两)*/
	{.bitmap_index = 78501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(严)*/
	{.bitmap_index = 78639, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(丧)*/
	{.bitmap_index = 78783, .adv_w = 14, .box_h = 23, .box_w = 4, .ofs_x = 10, .ofs_y = 5},/*(丨)*/
	{.bitmap_index = 78806, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(个)*/
	{.bitmap_index = 78944, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(丫)*/
	{.bitmap_index = 79059, .adv_w = 17, .box_h = 23, .box_w = 12, .ofs_x = 5, .ofs_y = 5},/*(丬)*/
	{.bitmap_index = 79128, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(中)*/
	{.bitmap_index = 79243, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(丰)*/
	{.bitmap_index = 79381, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(串)*/
	{.bitmap_index = 79496, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(临)*/
	{.bitmap_index = 79634, .adv_w = 19, .box_h = 11, .box_w = 12, .ofs_x = 7, .ofs_y = 11},/*(丶)*/
	{.bitmap_index = 79667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(丸)*/
	{.bitmap_index = 79805, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(丹)*/
	{.bitmap_index = 79943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(为)*/
	{.bitmap_index = 80081, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(主)*/
	{.bitmap_index = 80213, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(丽)*/
	{.bitmap_index = 80345, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(举)*/
	{.bitmap_index = 80483, .adv_w = 16, .box_h = 24, .box_w = 12, .ofs_x = 4, .ofs_y = 4},/*(丿)*/
	{.bitmap_index = 80555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(乃)*/
	{.bitmap_index = 80693, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(久)*/
	{.bitmap_index = 80837, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乇)*/
	{.bitmap_index = 80975, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(么)*/
	{.bitmap_index = 81113, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(义)*/
	{.bitmap_index = 81257, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(之)*/
	{.bitmap_index = 81389, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乌)*/
	{.bitmap_index = 81527, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(乍)*/
	{.bitmap_index = 81665, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乎)*/
	{.bitmap_index = 81803, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(乏)*/
	{.bitmap_index = 81941, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(乐)*/
	{.bitmap_index = 82079, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(乒)*/
	{.bitmap_index = 82223, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(乓)*/
	{.bitmap_index = 82367, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(乔)*/
	{.bitmap_index = 82511, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(乖)*/
	{.bitmap_index = 82649, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(乘)*/
	{.bitmap_index = 82787, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(乙)*/
	{.bitmap_index = 82913, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乜)*/
	{.bitmap_index = 83051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(九)*/
	{.bitmap_index = 83195, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乞)*/
	{.bitmap_index = 83339, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(也)*/
	{.bitmap_index = 83477, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(习)*/
	{.bitmap_index = 83609, .adv_w = 21, .box_h = 24, .box_w = 20, .ofs_x = 1, .ofs_y = 4},/*(乡)*/
	{.bitmap_index = 83729, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(书)*/
	{.bitmap_index = 83873, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(乩)*/
	{.bitmap_index = 84011, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(买)*/
	{.bitmap_index = 84149, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乱)*/
	{.bitmap_index = 84287, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(乳)*/
	{.bitmap_index = 84425, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(乾)*/
	{.bitmap_index = 84563, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(了)*/
	{.bitmap_index = 84673, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(予)*/
	{.bitmap_index = 84805, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(争)*/
	{.bitmap_index = 84943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(事)*/
	{.bitmap_index = 85081, .adv_w = 25, .box_h = 19, .box_w = 24, .ofs_x = 1, .ofs_y = 7},/*(二)*/
	{.bitmap_index = 85195, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(亍)*/
	{.bitmap_index = 85327, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(于)*/
	{.bitmap_index = 85459, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(亏)*/
	{.bitmap_index = 85591, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(云)*/
	{.bitmap_index = 85723, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(互)*/
	{.bitmap_index = 85849, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(亓)*/
	{.bitmap_index = 85987, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(五)*/
	{.bitmap_index = 86113, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(井)*/
	{.bitmap_index = 86257, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(亘)*/
	{.bitmap_index = 86383, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(亚)*/
	{.bitmap_index = 86509, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(些)*/
	{.bitmap_index = 86641, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(亟)*/
	{.bitmap_index = 86767, .adv_w = 25, .box_h = 9, .box_w = 24, .ofs_x = 1, .ofs_y = 19},/*(亠)*/
	{.bitmap_index = 86821, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(亡)*/
	{.bitmap_index = 86953, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(亢)*/
	{.bitmap_index = 87097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(交)*/
	{.bitmap_index = 87241, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(亥)*/
	{.bitmap_index = 87385, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(亦)*/
	{.bitmap_index = 87529, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(产)*/
	{.bitmap_index = 87673, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(亨)*/
	{.bitmap_index = 87811, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(亩)*/
	{.bitmap_index = 87943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(享)*/
	{.bitmap_index = 88081, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(京)*/
	{.bitmap_index = 88219, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(亭)*/
	{.bitmap_index = 88357, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(亮)*/
	{.bitmap_index = 88501, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(亲)*/
	{.bitmap_index = 88639, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(亳)*/
	{.bitmap_index = 88777, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(亵)*/
	{.bitmap_index = 88921, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(人)*/
	{.bitmap_index = 89065, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(亻)*/
	{.bitmap_index = 89157, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(亿)*/
	{.bitmap_index = 89295, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(什)*/
	{.bitmap_index = 89433, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仁)*/
	{.bitmap_index = 89571, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仂)*/
	{.bitmap_index = 89709, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仃)*/
	{.bitmap_index = 89847, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(仄)*/
	{.bitmap_index = 89985, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(仅)*/
	{.bitmap_index = 90129, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仆)*/
	{.bitmap_index = 90267, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仇)*/
	{.bitmap_index = 90405, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(仉)*/
	{.bitmap_index = 90549, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(今)*/
	{.bitmap_index = 90699, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(介)*/
	{.bitmap_index = 90843, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仍)*/
	{.bitmap_index = 90981, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(从)*/
	{.bitmap_index = 91125, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仑)*/
	{.bitmap_index = 91263, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仓)*/
	{.bitmap_index = 91407, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仔)*/
	{.bitmap_index = 91545, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仕)*/
	{.bitmap_index = 91683, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(他)*/
	{.bitmap_index = 91821, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仗)*/
	{.bitmap_index = 91959, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(付)*/
	{.bitmap_index = 92097, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仙)*/
	{.bitmap_index = 92235, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(仝)*/
	{.bitmap_index = 92367, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(仞)*/
	{.bitmap_index = 92511, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仟)*/
	{.bitmap_index = 92649, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仡)*/
	{.bitmap_index = 92787, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(代)*/
	{.bitmap_index = 92925, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(令)*/
	{.bitmap_index = 93069, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(以)*/
	{.bitmap_index = 93213, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仨)*/
	{.bitmap_index = 93351, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(仪)*/
	{.bitmap_index = 93495, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仫)*/
	{.bitmap_index = 93633, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(们)*/
	{.bitmap_index = 93771, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仰)*/
	{.bitmap_index = 93909, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仲)*/
	{.bitmap_index = 94047, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仳)*/
	{.bitmap_index = 94185, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仵)*/
	{.bitmap_index = 94323, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(件)*/
	{.bitmap_index = 94461, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(价)*/
	{.bitmap_index = 94605, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(任)*/
	{.bitmap_index = 94743, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(份)*/
	{.bitmap_index = 94887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(仿)*/
	{.bitmap_index = 95025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(企)*/
	{.bitmap_index = 95163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伉)*/
	{.bitmap_index = 95301, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(伊)*/
	{.bitmap_index = 95445, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伍)*/
	{.bitmap_index = 95583, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(伎)*/
	{.bitmap_index = 95727, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(伏)*/
	{.bitmap_index = 95871, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伐)*/
	{.bitmap_index = 96009, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(休)*/
	{.bitmap_index = 96147, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(众)*/
	{.bitmap_index = 96291, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(优)*/
	{.bitmap_index = 96429, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(伙)*/
	{.bitmap_index = 96573, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(会)*/
	{.bitmap_index = 96717, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伛)*/
	{.bitmap_index = 96855, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伞)*/
	{.bitmap_index = 96993, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伟)*/
	{.bitmap_index = 97131, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(传)*/
	{.bitmap_index = 97275, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伢)*/
	{.bitmap_index = 97413, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(伤)*/
	{.bitmap_index = 97557, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伥)*/
	{.bitmap_index = 97695, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伦)*/
	{.bitmap_index = 97833, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伧)*/
	{.bitmap_index = 97971, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伪)*/
	{.bitmap_index = 98109, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伫)*/
	{.bitmap_index = 98247, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伯)*/
	{.bitmap_index = 98385, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(估)*/
	{.bitmap_index = 98523, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伲)*/
	{.bitmap_index = 98661, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伴)*/
	{.bitmap_index = 98799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(伶)*/
	{.bitmap_index = 98943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伸)*/
	{.bitmap_index = 99081, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伺)*/
	{.bitmap_index = 99219, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(似)*/
	{.bitmap_index = 99363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(伽)*/
	{.bitmap_index = 99501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佃)*/
	{.bitmap_index = 99639, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(但)*/
	{.bitmap_index = 99777, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(位)*/
	{.bitmap_index = 99915, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(低)*/
	{.bitmap_index = 100059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(住)*/
	{.bitmap_index = 100197, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佐)*/
	{.bitmap_index = 100335, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佑)*/
	{.bitmap_index = 100473, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(体)*/
	{.bitmap_index = 100611, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(何)*/
	{.bitmap_index = 100749, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佗)*/
	{.bitmap_index = 100887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佘)*/
	{.bitmap_index = 101025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(余)*/
	{.bitmap_index = 101163, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(佚)*/
	{.bitmap_index = 101307, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(佛)*/
	{.bitmap_index = 101451, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(作)*/
	{.bitmap_index = 101589, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佝)*/
	{.bitmap_index = 101727, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(佞)*/
	{.bitmap_index = 101871, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佟)*/
	{.bitmap_index = 102009, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(你)*/
	{.bitmap_index = 102147, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佣)*/
	{.bitmap_index = 102285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佤)*/
	{.bitmap_index = 102423, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佥)*/
	{.bitmap_index = 102561, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佧)*/
	{.bitmap_index = 102699, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佩)*/
	{.bitmap_index = 102837, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佬)*/
	{.bitmap_index = 102975, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佯)*/
	{.bitmap_index = 103113, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佰)*/
	{.bitmap_index = 103251, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佳)*/
	{.bitmap_index = 103389, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佴)*/
	{.bitmap_index = 103527, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佶)*/
	{.bitmap_index = 103665, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佻)*/
	{.bitmap_index = 103803, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(佼)*/
	{.bitmap_index = 103947, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(佾)*/
	{.bitmap_index = 104085, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(使)*/
	{.bitmap_index = 104229, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侃)*/
	{.bitmap_index = 104367, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侄)*/
	{.bitmap_index = 104505, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侈)*/
	{.bitmap_index = 104649, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侉)*/
	{.bitmap_index = 104787, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(例)*/
	{.bitmap_index = 104931, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侍)*/
	{.bitmap_index = 105069, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侏)*/
	{.bitmap_index = 105207, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侑)*/
	{.bitmap_index = 105345, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侔)*/
	{.bitmap_index = 105483, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侗)*/
	{.bitmap_index = 105621, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(供)*/
	{.bitmap_index = 105759, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(依)*/
	{.bitmap_index = 105897, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侠)*/
	{.bitmap_index = 106041, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侣)*/
	{.bitmap_index = 106179, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侥)*/
	{.bitmap_index = 106323, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侦)*/
	{.bitmap_index = 106461, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侧)*/
	{.bitmap_index = 106599, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侨)*/
	{.bitmap_index = 106743, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侩)*/
	{.bitmap_index = 106881, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侪)*/
	{.bitmap_index = 107025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侬)*/
	{.bitmap_index = 107163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(侮)*/
	{.bitmap_index = 107301, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侯)*/
	{.bitmap_index = 107445, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(侵)*/
	{.bitmap_index = 107589, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(便)*/
	{.bitmap_index = 107733, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(促)*/
	{.bitmap_index = 107877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俄)*/
	{.bitmap_index = 108015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俅)*/
	{.bitmap_index = 108153, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(俊)*/
	{.bitmap_index = 108297, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俎)*/
	{.bitmap_index = 108435, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俏)*/
	{.bitmap_index = 108573, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俐)*/
	{.bitmap_index = 108711, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俑)*/
	{.bitmap_index = 108849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俗)*/
	{.bitmap_index = 108987, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俘)*/
	{.bitmap_index = 109125, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俚)*/
	{.bitmap_index = 109263, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俜)*/
	{.bitmap_index = 109401, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(保)*/
	{.bitmap_index = 109539, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俞)*/
	{.bitmap_index = 109677, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俟)*/
	{.bitmap_index = 109821, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(信)*/
	{.bitmap_index = 109959, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(俣)*/
	{.bitmap_index = 110103, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俦)*/
	{.bitmap_index = 110241, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(俨)*/
	{.bitmap_index = 110385, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俩)*/
	{.bitmap_index = 110523, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俪)*/
	{.bitmap_index = 110661, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俭)*/
	{.bitmap_index = 110799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(修)*/
	{.bitmap_index = 110943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俯)*/
	{.bitmap_index = 111081, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(俱)*/
	{.bitmap_index = 111225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俳)*/
	{.bitmap_index = 111363, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(俸)*/
	{.bitmap_index = 111507, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俺)*/
	{.bitmap_index = 111645, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(俾)*/
	{.bitmap_index = 111783, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倌)*/
	{.bitmap_index = 111921, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倍)*/
	{.bitmap_index = 112059, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倏)*/
	{.bitmap_index = 112203, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倒)*/
	{.bitmap_index = 112341, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倔)*/
	{.bitmap_index = 112479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倘)*/
	{.bitmap_index = 112617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(候)*/
	{.bitmap_index = 112755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倚)*/
	{.bitmap_index = 112893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倜)*/
	{.bitmap_index = 113031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(借)*/
	{.bitmap_index = 113169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倡)*/
	{.bitmap_index = 113307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倥)*/
	{.bitmap_index = 113445, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倦)*/
	{.bitmap_index = 113583, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倨)*/
	{.bitmap_index = 113721, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倩)*/
	{.bitmap_index = 113859, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(倪)*/
	{.bitmap_index = 114003, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倬)*/
	{.bitmap_index = 114141, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(倭)*/
	{.bitmap_index = 114285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(倮)*/
	{.bitmap_index = 114423, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(债)*/
	{.bitmap_index = 114567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(值)*/
	{.bitmap_index = 114705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(倾)*/
	{.bitmap_index = 114849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(偃)*/
	{.bitmap_index = 114987, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(假)*/
	{.bitmap_index = 115131, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(偈)*/
	{.bitmap_index = 115275, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(偌)*/
	{.bitmap_index = 115413, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(偎)*/
	{.bitmap_index = 115557, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(偏)*/
	{.bitmap_index = 115695, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(偕)*/
	{.bitmap_index = 115833, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(做)*/
	{.bitmap_index = 115977, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(停)*/
	{.bitmap_index = 116115, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(健)*/
	{.bitmap_index = 116253, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(偬)*/
	{.bitmap_index = 116391, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(偶)*/
	{.bitmap_index = 116529, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(偷)*/
	{.bitmap_index = 116673, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(偻)*/
	{.bitmap_index = 116817, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(偾)*/
	{.bitmap_index = 116961, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(偿)*/
	{.bitmap_index = 117105, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(傀)*/
	{.bitmap_index = 117243, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(傅)*/
	{.bitmap_index = 117381, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(傈)*/
	{.bitmap_index = 117519, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(傍)*/
	{.bitmap_index = 117663, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(傣)*/
	{.bitmap_index = 117801, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(傥)*/
	{.bitmap_index = 117945, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(傧)*/
	{.bitmap_index = 118089, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(储)*/
	{.bitmap_index = 118227, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(傩)*/
	{.bitmap_index = 118365, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(催)*/
	{.bitmap_index = 118503, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(傲)*/
	{.bitmap_index = 118647, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(傺)*/
	{.bitmap_index = 118785, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(傻)*/
	{.bitmap_index = 118929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(像)*/
	{.bitmap_index = 119067, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僖)*/
	{.bitmap_index = 119205, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僚)*/
	{.bitmap_index = 119343, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僦)*/
	{.bitmap_index = 119481, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僧)*/
	{.bitmap_index = 119619, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僬)*/
	{.bitmap_index = 119757, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僭)*/
	{.bitmap_index = 119895, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僮)*/
	{.bitmap_index = 120033, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僳)*/
	{.bitmap_index = 120171, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僵)*/
	{.bitmap_index = 120309, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(僻)*/
	{.bitmap_index = 120447, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(儆)*/
	{.bitmap_index = 120591, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(儇)*/
	{.bitmap_index = 120735, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(儋)*/
	{.bitmap_index = 120879, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(儒)*/
	{.bitmap_index = 121017, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(儡)*/
	{.bitmap_index = 121155, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(儿)*/
	{.bitmap_index = 121299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(兀)*/
	{.bitmap_index = 121437, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(允)*/
	{.bitmap_index = 121587, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(元)*/
	{.bitmap_index = 121725, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(兄)*/
	{.bitmap_index = 121863, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(充)*/
	{.bitmap_index = 122007, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(兆)*/
	{.bitmap_index = 122151, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(先)*/
	{.bitmap_index = 122295, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(光)*/
	{.bitmap_index = 122439, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(克)*/
	{.bitmap_index = 122583, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(免)*/
	{.bitmap_index = 122727, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(兑)*/
	{.bitmap_index = 122871, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(兔)*/
	{.bitmap_index = 123021, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(兕)*/
	{.bitmap_index = 123153, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(兖)*/
	{.bitmap_index = 123297, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(党)*/
	{.bitmap_index = 123441, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(兜)*/
	{.bitmap_index = 123585, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(兢)*/
	{.bitmap_index = 123729, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(入)*/
	{.bitmap_index = 123867, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(全)*/
	{.bitmap_index = 124005, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(八)*/
	{.bitmap_index = 124143, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(公)*/
	{.bitmap_index = 124281, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(六)*/
	{.bitmap_index = 124419, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(兮)*/
	{.bitmap_index = 124557, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(兰)*/
	{.bitmap_index = 124695, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(共)*/
	{.bitmap_index = 124833, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(关)*/
	{.bitmap_index = 124983, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(兴)*/
	{.bitmap_index = 125121, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(兵)*/
	{.bitmap_index = 125265, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(其)*/
	{.bitmap_index = 125409, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(具)*/
	{.bitmap_index = 125547, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(典)*/
	{.bitmap_index = 125691, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(兹)*/
	{.bitmap_index = 125829, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(养)*/
	{.bitmap_index = 125973, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(兼)*/
	{.bitmap_index = 126111, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(兽)*/
	{.bitmap_index = 126249, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冀)*/
	{.bitmap_index = 126393, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冁)*/
	{.bitmap_index = 126537, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(冂)*/
	{.bitmap_index = 126647, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(内)*/
	{.bitmap_index = 126762, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(冈)*/
	{.bitmap_index = 126872, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(冉)*/
	{.bitmap_index = 127010, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(册)*/
	{.bitmap_index = 127148, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(再)*/
	{.bitmap_index = 127280, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(冒)*/
	{.bitmap_index = 127390, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冕)*/
	{.bitmap_index = 127534, .adv_w = 25, .box_h = 7, .box_w = 24, .ofs_x = 1, .ofs_y = 19},/*(冖)*/
	{.bitmap_index = 127576, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(冗)*/
	{.bitmap_index = 127714, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(写)*/
	{.bitmap_index = 127846, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(军)*/
	{.bitmap_index = 127978, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(农)*/
	{.bitmap_index = 128122, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冠)*/
	{.bitmap_index = 128254, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冢)*/
	{.bitmap_index = 128386, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冤)*/
	{.bitmap_index = 128524, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冥)*/
	{.bitmap_index = 128662, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 5},/*(冫)*/
	{.bitmap_index = 128728, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冬)*/
	{.bitmap_index = 128866, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冯)*/
	{.bitmap_index = 128998, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冰)*/
	{.bitmap_index = 129136, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(冱)*/
	{.bitmap_index = 129262, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(冲)*/
	{.bitmap_index = 129400, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(决)*/
	{.bitmap_index = 129544, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(况)*/
	{.bitmap_index = 129682, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(冶)*/
	{.bitmap_index = 129820, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冷)*/
	{.bitmap_index = 129964, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冻)*/
	{.bitmap_index = 130102, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(冼)*/
	{.bitmap_index = 130246, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(冽)*/
	{.bitmap_index = 130384, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(净)*/
	{.bitmap_index = 130522, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凄)*/
	{.bitmap_index = 130666, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(准)*/
	{.bitmap_index = 130804, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(凇)*/
	{.bitmap_index = 130942, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(凉)*/
	{.bitmap_index = 131080, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凋)*/
	{.bitmap_index = 131218, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(凌)*/
	{.bitmap_index = 131362, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(减)*/
	{.bitmap_index = 131506, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凑)*/
	{.bitmap_index = 131650, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(凛)*/
	{.bitmap_index = 131788, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凝)*/
	{.bitmap_index = 131932, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(几)*/
	{.bitmap_index = 132064, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凡)*/
	{.bitmap_index = 132202, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凤)*/
	{.bitmap_index = 132340, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凫)*/
	{.bitmap_index = 132484, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凭)*/
	{.bitmap_index = 132628, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(凯)*/
	{.bitmap_index = 132772, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(凰)*/
	{.bitmap_index = 132904, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(凳)*/
	{.bitmap_index = 133048, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(凵)*/
	{.bitmap_index = 133153, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(凶)*/
	{.bitmap_index = 133268, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(凸)*/
	{.bitmap_index = 133378, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(凹)*/
	{.bitmap_index = 133483, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(出)*/
	{.bitmap_index = 133598, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(击)*/
	{.bitmap_index = 133736, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(凼)*/
	{.bitmap_index = 133851, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(函)*/
	{.bitmap_index = 133961, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(凿)*/
	{.bitmap_index = 134099, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(刀)*/
	{.bitmap_index = 134237, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刁)*/
	{.bitmap_index = 134369, .adv_w = 24, .box_h = 23, .box_w = 12, .ofs_x = 12, .ofs_y = 5},/*(刂)*/
	{.bitmap_index = 134438, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(刃)*/
	{.bitmap_index = 134576, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(分)*/
	{.bitmap_index = 134720, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(切)*/
	{.bitmap_index = 134864, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刈)*/
	{.bitmap_index = 135002, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(刊)*/
	{.bitmap_index = 135140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(刍)*/
	{.bitmap_index = 135278, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刎)*/
	{.bitmap_index = 135416, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(刑)*/
	{.bitmap_index = 135560, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(划)*/
	{.bitmap_index = 135698, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(刖)*/
	{.bitmap_index = 135842, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(列)*/
	{.bitmap_index = 135986, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刘)*/
	{.bitmap_index = 136124, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(则)*/
	{.bitmap_index = 136262, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(刚)*/
	{.bitmap_index = 136377, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(创)*/
	{.bitmap_index = 136521, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(初)*/
	{.bitmap_index = 136665, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(删)*/
	{.bitmap_index = 136803, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(判)*/
	{.bitmap_index = 136947, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刨)*/
	{.bitmap_index = 137085, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(利)*/
	{.bitmap_index = 137223, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(别)*/
	{.bitmap_index = 137361, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刭)*/
	{.bitmap_index = 137499, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(刮)*/
	{.bitmap_index = 137637, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(到)*/
	{.bitmap_index = 137775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刳)*/
	{.bitmap_index = 137913, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(制)*/
	{.bitmap_index = 138057, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刷)*/
	{.bitmap_index = 138195, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(券)*/
	{.bitmap_index = 138339, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刹)*/
	{.bitmap_index = 138477, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刺)*/
	{.bitmap_index = 138615, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(刻)*/
	{.bitmap_index = 138759, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(刽)*/
	{.bitmap_index = 138903, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(刿)*/
	{.bitmap_index = 139047, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(剀)*/
	{.bitmap_index = 139185, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剁)*/
	{.bitmap_index = 139323, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(剂)*/
	{.bitmap_index = 139467, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剃)*/
	{.bitmap_index = 139605, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(削)*/
	{.bitmap_index = 139743, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剌)*/
	{.bitmap_index = 139881, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(前)*/
	{.bitmap_index = 140019, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(剐)*/
	{.bitmap_index = 140157, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剑)*/
	{.bitmap_index = 140295, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(剔)*/
	{.bitmap_index = 140439, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(剖)*/
	{.bitmap_index = 140577, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剜)*/
	{.bitmap_index = 140715, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(剞)*/
	{.bitmap_index = 140853, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(剡)*/
	{.bitmap_index = 140997, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剥)*/
	{.bitmap_index = 141135, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剧)*/
	{.bitmap_index = 141273, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剩)*/
	{.bitmap_index = 141411, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(剪)*/
	{.bitmap_index = 141555, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(副)*/
	{.bitmap_index = 141693, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(割)*/
	{.bitmap_index = 141831, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剽)*/
	{.bitmap_index = 141969, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(剿)*/
	{.bitmap_index = 142107, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(劁)*/
	{.bitmap_index = 142245, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(劂)*/
	{.bitmap_index = 142377, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劈)*/
	{.bitmap_index = 142521, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劐)*/
	{.bitmap_index = 142665, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(劓)*/
	{.bitmap_index = 142809, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(力)*/
	{.bitmap_index = 142953, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劝)*/
	{.bitmap_index = 143097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(办)*/
	{.bitmap_index = 143241, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(功)*/
	{.bitmap_index = 143385, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(加)*/
	{.bitmap_index = 143523, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(务)*/
	{.bitmap_index = 143667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(劢)*/
	{.bitmap_index = 143805, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(劣)*/
	{.bitmap_index = 143949, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(动)*/
	{.bitmap_index = 144093, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(助)*/
	{.bitmap_index = 144237, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(努)*/
	{.bitmap_index = 144381, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(劫)*/
	{.bitmap_index = 144525, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(劬)*/
	{.bitmap_index = 144663, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劭)*/
	{.bitmap_index = 144807, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(励)*/
	{.bitmap_index = 144945, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劲)*/
	{.bitmap_index = 145089, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劳)*/
	{.bitmap_index = 145233, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(劾)*/
	{.bitmap_index = 145377, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(势)*/
	{.bitmap_index = 145521, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(勃)*/
	{.bitmap_index = 145659, .adv_w = 21, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = 4},/*(勇)*/
	{.bitmap_index = 145774, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(勉)*/
	{.bitmap_index = 145912, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(勋)*/
	{.bitmap_index = 146056, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(勐)*/
	{.bitmap_index = 146200, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(勒)*/
	{.bitmap_index = 146344, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(勖)*/
	{.bitmap_index = 146482, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(勘)*/
	{.bitmap_index = 146626, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(募)*/
	{.bitmap_index = 146770, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(勤)*/
	{.bitmap_index = 146914, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(勰)*/
	{.bitmap_index = 147052, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(勹)*/
	{.bitmap_index = 147190, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(勺)*/
	{.bitmap_index = 147328, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(勾)*/
	{.bitmap_index = 147466, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(勿)*/
	{.bitmap_index = 147610, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(匀)*/
	{.bitmap_index = 147754, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(包)*/
	{.bitmap_index = 147892, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(匆)*/
	{.bitmap_index = 148030, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(匈)*/
	{.bitmap_index = 148168, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(匍)*/
	{.bitmap_index = 148306, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(匏)*/
	{.bitmap_index = 148444, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(匐)*/
	{.bitmap_index = 148588, .adv_w = 24, .box_h = 22, .box_w = 20, .ofs_x = 4, .ofs_y = 6},/*(匕)*/
	{.bitmap_index = 148698, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(化)*/
	{.bitmap_index = 148836, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(北)*/
	{.bitmap_index = 148974, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(匙)*/
	{.bitmap_index = 149106, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(匚)*/
	{.bitmap_index = 149216, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(匝)*/
	{.bitmap_index = 149342, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匠)*/
	{.bitmap_index = 149474, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匡)*/
	{.bitmap_index = 149606, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匣)*/
	{.bitmap_index = 149738, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匦)*/
	{.bitmap_index = 149870, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匪)*/
	{.bitmap_index = 150002, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匮)*/
	{.bitmap_index = 150134, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匹)*/
	{.bitmap_index = 150266, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(区)*/
	{.bitmap_index = 150398, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(医)*/
	{.bitmap_index = 150530, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匾)*/
	{.bitmap_index = 150662, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(匿)*/
	{.bitmap_index = 150794, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(十)*/
	{.bitmap_index = 150932, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(千)*/
	{.bitmap_index = 151070, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卅)*/
	{.bitmap_index = 151208, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(升)*/
	{.bitmap_index = 151352, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(午)*/
	{.bitmap_index = 151496, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(卉)*/
	{.bitmap_index = 151640, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(半)*/
	{.bitmap_index = 151778, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(华)*/
	{.bitmap_index = 151916, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(协)*/
	{.bitmap_index = 152060, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卑)*/
	{.bitmap_index = 152198, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卒)*/
	{.bitmap_index = 152336, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卓)*/
	{.bitmap_index = 152474, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(单)*/
	{.bitmap_index = 152618, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(卖)*/
	{.bitmap_index = 152762, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(南)*/
	{.bitmap_index = 152900, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(博)*/
	{.bitmap_index = 153038, .adv_w = 24, .box_h = 23, .box_w = 16, .ofs_x = 8, .ofs_y = 5},/*(卜)*/
	{.bitmap_index = 153130, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卞)*/
	{.bitmap_index = 153268, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(卟)*/
	{.bitmap_index = 153406, .adv_w = 23, .box_h = 23, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(占)*/
	{.bitmap_index = 153521, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卡)*/
	{.bitmap_index = 153659, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(卢)*/
	{.bitmap_index = 153803, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(卣)*/
	{.bitmap_index = 153941, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(卤)*/
	{.bitmap_index = 154079, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卦)*/
	{.bitmap_index = 154217, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卧)*/
	{.bitmap_index = 154355, .adv_w = 22, .box_h = 22, .box_w = 16, .ofs_x = 6, .ofs_y = 5},/*(卩)*/
	{.bitmap_index = 154443, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(卫)*/
	{.bitmap_index = 154569, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(卮)*/
	{.bitmap_index = 154707, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(卯)*/
	{.bitmap_index = 154851, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(印)*/
	{.bitmap_index = 154966, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(危)*/
	{.bitmap_index = 155116, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(即)*/
	{.bitmap_index = 155248, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(却)*/
	{.bitmap_index = 155386, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(卵)*/
	{.bitmap_index = 155506, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(卷)*/
	{.bitmap_index = 155644, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(卸)*/
	{.bitmap_index = 155782, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(卺)*/
	{.bitmap_index = 155914, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(卿)*/
	{.bitmap_index = 156052, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厂)*/
	{.bitmap_index = 156190, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厄)*/
	{.bitmap_index = 156328, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厅)*/
	{.bitmap_index = 156466, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(历)*/
	{.bitmap_index = 156604, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厉)*/
	{.bitmap_index = 156742, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(压)*/
	{.bitmap_index = 156880, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厌)*/
	{.bitmap_index = 157018, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厍)*/
	{.bitmap_index = 157156, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厕)*/
	{.bitmap_index = 157294, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(厘)*/
	{.bitmap_index = 157426, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(厚)*/
	{.bitmap_index = 157558, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(厝)*/
	{.bitmap_index = 157690, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(原)*/
	{.bitmap_index = 157828, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厢)*/
	{.bitmap_index = 157966, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(厣)*/
	{.bitmap_index = 158098, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厥)*/
	{.bitmap_index = 158236, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厦)*/
	{.bitmap_index = 158374, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(厨)*/
	{.bitmap_index = 158512, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(厩)*/
	{.bitmap_index = 158644, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(厮)*/
	{.bitmap_index = 158776, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(厶)*/
	{.bitmap_index = 158914, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(去)*/
	{.bitmap_index = 159052, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(县)*/
	{.bitmap_index = 159190, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(叁)*/
	{.bitmap_index = 159328, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(参)*/
	{.bitmap_index = 159478, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(又)*/
	{.bitmap_index = 159616, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(叉)*/
	{.bitmap_index = 159754, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(及)*/
	{.bitmap_index = 159892, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(友)*/
	{.bitmap_index = 160036, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(双)*/
	{.bitmap_index = 160174, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(反)*/
	{.bitmap_index = 160318, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(发)*/
	{.bitmap_index = 160462, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(叔)*/
	{.bitmap_index = 160600, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(取)*/
	{.bitmap_index = 160732, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(受)*/
	{.bitmap_index = 160876, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(变)*/
	{.bitmap_index = 161020, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(叙)*/
	{.bitmap_index = 161170, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(叛)*/
	{.bitmap_index = 161314, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(叟)*/
	{.bitmap_index = 161458, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(叠)*/
	{.bitmap_index = 161596, .adv_w = 23, .box_h = 20, .box_w = 20, .ofs_x = 3, .ofs_y = 6},/*(口)*/
	{.bitmap_index = 161696, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(古)*/
	{.bitmap_index = 161834, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(句)*/
	{.bitmap_index = 161972, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(另)*/
	{.bitmap_index = 162110, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(叨)*/
	{.bitmap_index = 162225, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(叩)*/
	{.bitmap_index = 162335, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(只)*/
	{.bitmap_index = 162473, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(叫)*/
	{.bitmap_index = 162588, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(召)*/
	{.bitmap_index = 162720, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(叭)*/
	{.bitmap_index = 162858, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(叮)*/
	{.bitmap_index = 162990, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(可)*/
	{.bitmap_index = 163122, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(台)*/
	{.bitmap_index = 163260, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(叱)*/
	{.bitmap_index = 163398, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(史)*/
	{.bitmap_index = 163542, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(右)*/
	{.bitmap_index = 163674, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(叵)*/
	{.bitmap_index = 163806, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(叶)*/
	{.bitmap_index = 163944, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(号)*/
	{.bitmap_index = 164076, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(司)*/
	{.bitmap_index = 164208, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(叹)*/
	{.bitmap_index = 164346, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(叻)*/
	{.bitmap_index = 164466, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(叼)*/
	{.bitmap_index = 164598, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(叽)*/
	{.bitmap_index = 164736, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吁)*/
	{.bitmap_index = 164868, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吃)*/
	{.bitmap_index = 165006, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(各)*/
	{.bitmap_index = 165150, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吆)*/
	{.bitmap_index = 165288, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(合)*/
	{.bitmap_index = 165426, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(吉)*/
	{.bitmap_index = 165564, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(吊)*/
	{.bitmap_index = 165679, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(同)*/
	{.bitmap_index = 165789, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(名)*/
	{.bitmap_index = 165927, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(后)*/
	{.bitmap_index = 166065, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(吏)*/
	{.bitmap_index = 166209, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(吐)*/
	{.bitmap_index = 166341, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(向)*/
	{.bitmap_index = 166456, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吒)*/
	{.bitmap_index = 166594, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吓)*/
	{.bitmap_index = 166726, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(吕)*/
	{.bitmap_index = 166831, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(吖)*/
	{.bitmap_index = 166969, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吗)*/
	{.bitmap_index = 167101, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(君)*/
	{.bitmap_index = 167233, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(吝)*/
	{.bitmap_index = 167371, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(吞)*/
	{.bitmap_index = 167503, .adv_w = 26, .box_h = 25, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(吟)*/
	{.bitmap_index = 167653, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(吠)*/
	{.bitmap_index = 167797, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吡)*/
	{.bitmap_index = 167935, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吣)*/
	{.bitmap_index = 168073, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(否)*/
	{.bitmap_index = 168199, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(吧)*/
	{.bitmap_index = 168331, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吨)*/
	{.bitmap_index = 168469, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(吩)*/
	{.bitmap_index = 168613, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(含)*/
	{.bitmap_index = 168745, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(听)*/
	{.bitmap_index = 168889, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(吭)*/
	{.bitmap_index = 169033, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(吮)*/
	{.bitmap_index = 169177, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(启)*/
	{.bitmap_index = 169315, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(吱)*/
	{.bitmap_index = 169459, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(吲)*/
	{.bitmap_index = 169597, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(吴)*/
	{.bitmap_index = 169735, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(吵)*/
	{.bitmap_index = 169879, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(吸)*/
	{.bitmap_index = 170017, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(吹)*/
	{.bitmap_index = 170161, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(吻)*/
	{.bitmap_index = 170299, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(吼)*/
	{.bitmap_index = 170437, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(吾)*/
	{.bitmap_index = 170569, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呀)*/
	{.bitmap_index = 170701, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(呃)*/
	{.bitmap_index = 170839, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(呆)*/
	{.bitmap_index = 170971, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呈)*/
	{.bitmap_index = 171103, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(告)*/
	{.bitmap_index = 171241, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(呋)*/
	{.bitmap_index = 171385, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(呐)*/
	{.bitmap_index = 171500, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(呒)*/
	{.bitmap_index = 171638, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呓)*/
	{.bitmap_index = 171776, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(呔)*/
	{.bitmap_index = 171920, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呕)*/
	{.bitmap_index = 172052, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(呖)*/
	{.bitmap_index = 172190, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(呗)*/
	{.bitmap_index = 172328, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(员)*/
	{.bitmap_index = 172466, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(呙)*/
	{.bitmap_index = 172576, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(呛)*/
	{.bitmap_index = 172714, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(呜)*/
	{.bitmap_index = 172852, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(呢)*/
	{.bitmap_index = 172990, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(呤)*/
	{.bitmap_index = 173134, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(呦)*/
	{.bitmap_index = 173278, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(周)*/
	{.bitmap_index = 173416, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呱)*/
	{.bitmap_index = 173548, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呲)*/
	{.bitmap_index = 173686, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(味)*/
	{.bitmap_index = 173824, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(呵)*/
	{.bitmap_index = 173956, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(呶)*/
	{.bitmap_index = 174100, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(呷)*/
	{.bitmap_index = 174210, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(呸)*/
	{.bitmap_index = 174336, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呻)*/
	{.bitmap_index = 174474, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(呼)*/
	{.bitmap_index = 174612, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(命)*/
	{.bitmap_index = 174750, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咀)*/
	{.bitmap_index = 174882, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咂)*/
	{.bitmap_index = 175014, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咄)*/
	{.bitmap_index = 175152, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咆)*/
	{.bitmap_index = 175290, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咋)*/
	{.bitmap_index = 175428, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(和)*/
	{.bitmap_index = 175566, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(咎)*/
	{.bitmap_index = 175704, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咏)*/
	{.bitmap_index = 175848, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咐)*/
	{.bitmap_index = 175986, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(咒)*/
	{.bitmap_index = 176124, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咔)*/
	{.bitmap_index = 176262, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咕)*/
	{.bitmap_index = 176400, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咖)*/
	{.bitmap_index = 176538, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(咙)*/
	{.bitmap_index = 176682, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(咚)*/
	{.bitmap_index = 176826, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咛)*/
	{.bitmap_index = 176964, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咝)*/
	{.bitmap_index = 177102, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(咣)*/
	{.bitmap_index = 177246, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咤)*/
	{.bitmap_index = 177384, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(咦)*/
	{.bitmap_index = 177528, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咧)*/
	{.bitmap_index = 177660, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咨)*/
	{.bitmap_index = 177798, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咩)*/
	{.bitmap_index = 177936, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咪)*/
	{.bitmap_index = 178074, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(咫)*/
	{.bitmap_index = 178206, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(咬)*/
	{.bitmap_index = 178350, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咭)*/
	{.bitmap_index = 178488, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咯)*/
	{.bitmap_index = 178626, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(咱)*/
	{.bitmap_index = 178736, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(咳)*/
	{.bitmap_index = 178880, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(咴)*/
	{.bitmap_index = 179018, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(咸)*/
	{.bitmap_index = 179156, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咻)*/
	{.bitmap_index = 179294, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(咽)*/
	{.bitmap_index = 179426, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(咿)*/
	{.bitmap_index = 179570, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(哀)*/
	{.bitmap_index = 179714, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(品)*/
	{.bitmap_index = 179840, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(哂)*/
	{.bitmap_index = 179966, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哄)*/
	{.bitmap_index = 180104, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哆)*/
	{.bitmap_index = 180248, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(哇)*/
	{.bitmap_index = 180386, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哈)*/
	{.bitmap_index = 180524, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哉)*/
	{.bitmap_index = 180668, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哌)*/
	{.bitmap_index = 180806, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(响)*/
	{.bitmap_index = 180944, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哎)*/
	{.bitmap_index = 181088, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哏)*/
	{.bitmap_index = 181226, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哐)*/
	{.bitmap_index = 181358, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哑)*/
	{.bitmap_index = 181490, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哒)*/
	{.bitmap_index = 181628, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哓)*/
	{.bitmap_index = 181772, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(哔)*/
	{.bitmap_index = 181910, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哕)*/
	{.bitmap_index = 182054, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哗)*/
	{.bitmap_index = 182192, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(哙)*/
	{.bitmap_index = 182330, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哚)*/
	{.bitmap_index = 182462, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哜)*/
	{.bitmap_index = 182606, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哝)*/
	{.bitmap_index = 182744, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哞)*/
	{.bitmap_index = 182882, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哟)*/
	{.bitmap_index = 183020, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哥)*/
	{.bitmap_index = 183152, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哦)*/
	{.bitmap_index = 183296, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哧)*/
	{.bitmap_index = 183440, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哨)*/
	{.bitmap_index = 183578, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哩)*/
	{.bitmap_index = 183710, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哪)*/
	{.bitmap_index = 183842, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(哭)*/
	{.bitmap_index = 183980, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哮)*/
	{.bitmap_index = 184124, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(哲)*/
	{.bitmap_index = 184262, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哳)*/
	{.bitmap_index = 184406, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(哺)*/
	{.bitmap_index = 184544, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(哼)*/
	{.bitmap_index = 184682, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(哽)*/
	{.bitmap_index = 184820, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(哿)*/
	{.bitmap_index = 184958, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唁)*/
	{.bitmap_index = 185096, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(唆)*/
	{.bitmap_index = 185240, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(唇)*/
	{.bitmap_index = 185378, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(唉)*/
	{.bitmap_index = 185528, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唏)*/
	{.bitmap_index = 185666, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(唐)*/
	{.bitmap_index = 185810, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唑)*/
	{.bitmap_index = 185948, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唔)*/
	{.bitmap_index = 186080, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(唛)*/
	{.bitmap_index = 186224, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(唠)*/
	{.bitmap_index = 186368, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(唢)*/
	{.bitmap_index = 186512, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唣)*/
	{.bitmap_index = 186650, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(唤)*/
	{.bitmap_index = 186794, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(唧)*/
	{.bitmap_index = 186926, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(唪)*/
	{.bitmap_index = 187070, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(唬)*/
	{.bitmap_index = 187214, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(售)*/
	{.bitmap_index = 187352, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唯)*/
	{.bitmap_index = 187490, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(唰)*/
	{.bitmap_index = 187628, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唱)*/
	{.bitmap_index = 187760, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(唳)*/
	{.bitmap_index = 187904, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(唷)*/
	{.bitmap_index = 188042, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(唼)*/
	{.bitmap_index = 188186, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(唾)*/
	{.bitmap_index = 188324, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(唿)*/
	{.bitmap_index = 188462, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(啁)*/
	{.bitmap_index = 188572, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啃)*/
	{.bitmap_index = 188710, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啄)*/
	{.bitmap_index = 188842, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(商)*/
	{.bitmap_index = 188980, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啉)*/
	{.bitmap_index = 189118, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啊)*/
	{.bitmap_index = 189250, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(啐)*/
	{.bitmap_index = 189388, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(啕)*/
	{.bitmap_index = 189526, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(啖)*/
	{.bitmap_index = 189670, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啜)*/
	{.bitmap_index = 189802, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啡)*/
	{.bitmap_index = 189940, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(啤)*/
	{.bitmap_index = 190078, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啥)*/
	{.bitmap_index = 190216, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啦)*/
	{.bitmap_index = 190354, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(啧)*/
	{.bitmap_index = 190498, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啪)*/
	{.bitmap_index = 190636, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啬)*/
	{.bitmap_index = 190774, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啭)*/
	{.bitmap_index = 190912, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啮)*/
	{.bitmap_index = 191050, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啵)*/
	{.bitmap_index = 191188, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(啶)*/
	{.bitmap_index = 191332, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啷)*/
	{.bitmap_index = 191470, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(啸)*/
	{.bitmap_index = 191614, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啻)*/
	{.bitmap_index = 191752, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啼)*/
	{.bitmap_index = 191890, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(啾)*/
	{.bitmap_index = 192028, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喀)*/
	{.bitmap_index = 192166, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喁)*/
	{.bitmap_index = 192298, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(喂)*/
	{.bitmap_index = 192436, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喃)*/
	{.bitmap_index = 192574, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(善)*/
	{.bitmap_index = 192712, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喇)*/
	{.bitmap_index = 192850, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喈)*/
	{.bitmap_index = 192988, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喉)*/
	{.bitmap_index = 193126, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(喊)*/
	{.bitmap_index = 193270, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喋)*/
	{.bitmap_index = 193408, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(喏)*/
	{.bitmap_index = 193546, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(喑)*/
	{.bitmap_index = 193684, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(喔)*/
	{.bitmap_index = 193822, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喘)*/
	{.bitmap_index = 193960, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喙)*/
	{.bitmap_index = 194098, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喜)*/
	{.bitmap_index = 194236, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喝)*/
	{.bitmap_index = 194368, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喟)*/
	{.bitmap_index = 194500, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喧)*/
	{.bitmap_index = 194638, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(喱)*/
	{.bitmap_index = 194776, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喳)*/
	{.bitmap_index = 194914, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(喵)*/
	{.bitmap_index = 195052, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(喷)*/
	{.bitmap_index = 195196, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喹)*/
	{.bitmap_index = 195334, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喻)*/
	{.bitmap_index = 195472, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(喽)*/
	{.bitmap_index = 195616, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(喾)*/
	{.bitmap_index = 195754, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗄)*/
	{.bitmap_index = 195892, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗅)*/
	{.bitmap_index = 196036, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗉)*/
	{.bitmap_index = 196174, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗌)*/
	{.bitmap_index = 196312, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗍)*/
	{.bitmap_index = 196456, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗑)*/
	{.bitmap_index = 196594, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗒)*/
	{.bitmap_index = 196732, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗓)*/
	{.bitmap_index = 196864, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(嗔)*/
	{.bitmap_index = 197008, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗖)*/
	{.bitmap_index = 197152, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗜)*/
	{.bitmap_index = 197290, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗝)*/
	{.bitmap_index = 197422, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗟)*/
	{.bitmap_index = 197560, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗡)*/
	{.bitmap_index = 197698, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗣)*/
	{.bitmap_index = 197830, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗤)*/
	{.bitmap_index = 197974, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗥)*/
	{.bitmap_index = 198112, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗦)*/
	{.bitmap_index = 198250, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗨)*/
	{.bitmap_index = 198388, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗪)*/
	{.bitmap_index = 198526, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗫)*/
	{.bitmap_index = 198664, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗬)*/
	{.bitmap_index = 198802, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗯)*/
	{.bitmap_index = 198934, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗲)*/
	{.bitmap_index = 199078, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗳)*/
	{.bitmap_index = 199222, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗵)*/
	{.bitmap_index = 199360, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗷)*/
	{.bitmap_index = 199498, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嗽)*/
	{.bitmap_index = 199642, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嗾)*/
	{.bitmap_index = 199780, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘀)*/
	{.bitmap_index = 199918, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘁)*/
	{.bitmap_index = 200062, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘈)*/
	{.bitmap_index = 200200, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嘉)*/
	{.bitmap_index = 200344, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘌)*/
	{.bitmap_index = 200476, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘎)*/
	{.bitmap_index = 200608, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘏)*/
	{.bitmap_index = 200752, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘘)*/
	{.bitmap_index = 200890, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘛)*/
	{.bitmap_index = 201028, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘞)*/
	{.bitmap_index = 201166, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘟)*/
	{.bitmap_index = 201304, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘣)*/
	{.bitmap_index = 201448, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘤)*/
	{.bitmap_index = 201586, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘧)*/
	{.bitmap_index = 201724, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘬)*/
	{.bitmap_index = 201862, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘭)*/
	{.bitmap_index = 202006, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘱)*/
	{.bitmap_index = 202138, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘲)*/
	{.bitmap_index = 202276, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘴)*/
	{.bitmap_index = 202420, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘶)*/
	{.bitmap_index = 202564, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘹)*/
	{.bitmap_index = 202702, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嘻)*/
	{.bitmap_index = 202840, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嘿)*/
	{.bitmap_index = 202978, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噌)*/
	{.bitmap_index = 203116, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(噍)*/
	{.bitmap_index = 203254, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噎)*/
	{.bitmap_index = 203392, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噔)*/
	{.bitmap_index = 203530, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(噗)*/
	{.bitmap_index = 203674, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(噘)*/
	{.bitmap_index = 203812, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噙)*/
	{.bitmap_index = 203950, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噜)*/
	{.bitmap_index = 204088, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(噢)*/
	{.bitmap_index = 204232, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噤)*/
	{.bitmap_index = 204370, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(器)*/
	{.bitmap_index = 204502, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(噩)*/
	{.bitmap_index = 204634, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噪)*/
	{.bitmap_index = 204766, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(噫)*/
	{.bitmap_index = 204904, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(噬)*/
	{.bitmap_index = 205042, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(噱)*/
	{.bitmap_index = 205186, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噶)*/
	{.bitmap_index = 205324, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噻)*/
	{.bitmap_index = 205462, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(噼)*/
	{.bitmap_index = 205600, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚅)*/
	{.bitmap_index = 205732, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚆)*/
	{.bitmap_index = 205870, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚎)*/
	{.bitmap_index = 206008, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嚏)*/
	{.bitmap_index = 206152, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚓)*/
	{.bitmap_index = 206290, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚣)*/
	{.bitmap_index = 206428, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚯)*/
	{.bitmap_index = 206560, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嚷)*/
	{.bitmap_index = 206704, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嚼)*/
	{.bitmap_index = 206842, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(囊)*/
	{.bitmap_index = 206986, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(囔)*/
	{.bitmap_index = 207130, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囗)*/
	{.bitmap_index = 207240, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囚)*/
	{.bitmap_index = 207350, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(四)*/
	{.bitmap_index = 207450, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囝)*/
	{.bitmap_index = 207560, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(回)*/
	{.bitmap_index = 207665, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囟)*/
	{.bitmap_index = 207780, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(因)*/
	{.bitmap_index = 207890, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囡)*/
	{.bitmap_index = 208000, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(团)*/
	{.bitmap_index = 208110, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囤)*/
	{.bitmap_index = 208220, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囫)*/
	{.bitmap_index = 208330, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(园)*/
	{.bitmap_index = 208440, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(困)*/
	{.bitmap_index = 208550, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囱)*/
	{.bitmap_index = 208670, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(围)*/
	{.bitmap_index = 208780, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囵)*/
	{.bitmap_index = 208890, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囹)*/
	{.bitmap_index = 209000, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(固)*/
	{.bitmap_index = 209110, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(国)*/
	{.bitmap_index = 209220, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(图)*/
	{.bitmap_index = 209330, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(囿)*/
	{.bitmap_index = 209440, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圃)*/
	{.bitmap_index = 209550, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圄)*/
	{.bitmap_index = 209660, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圆)*/
	{.bitmap_index = 209770, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圈)*/
	{.bitmap_index = 209880, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圉)*/
	{.bitmap_index = 209990, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圊)*/
	{.bitmap_index = 210100, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(圜)*/
	{.bitmap_index = 210210, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(土)*/
	{.bitmap_index = 210342, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(圣)*/
	{.bitmap_index = 210474, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(在)*/
	{.bitmap_index = 210612, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(圩)*/
	{.bitmap_index = 210750, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(圪)*/
	{.bitmap_index = 210888, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(圬)*/
	{.bitmap_index = 211026, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(圭)*/
	{.bitmap_index = 211164, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(圮)*/
	{.bitmap_index = 211302, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(圯)*/
	{.bitmap_index = 211440, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(地)*/
	{.bitmap_index = 211578, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(圳)*/
	{.bitmap_index = 211722, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(圹)*/
	{.bitmap_index = 211866, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(场)*/
	{.bitmap_index = 212010, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(圻)*/
	{.bitmap_index = 212154, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(圾)*/
	{.bitmap_index = 212298, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(址)*/
	{.bitmap_index = 212430, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坂)*/
	{.bitmap_index = 212568, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(均)*/
	{.bitmap_index = 212706, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坊)*/
	{.bitmap_index = 212844, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坌)*/
	{.bitmap_index = 212982, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坍)*/
	{.bitmap_index = 213126, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坎)*/
	{.bitmap_index = 213270, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坏)*/
	{.bitmap_index = 213408, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(坐)*/
	{.bitmap_index = 213546, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坑)*/
	{.bitmap_index = 213690, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(块)*/
	{.bitmap_index = 213834, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(坚)*/
	{.bitmap_index = 213972, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坛)*/
	{.bitmap_index = 214110, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坜)*/
	{.bitmap_index = 214254, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坝)*/
	{.bitmap_index = 214398, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坞)*/
	{.bitmap_index = 214536, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坟)*/
	{.bitmap_index = 214680, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(坠)*/
	{.bitmap_index = 214818, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坡)*/
	{.bitmap_index = 214962, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坤)*/
	{.bitmap_index = 215100, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(坦)*/
	{.bitmap_index = 215232, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坨)*/
	{.bitmap_index = 215370, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坩)*/
	{.bitmap_index = 215508, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(坪)*/
	{.bitmap_index = 215646, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坫)*/
	{.bitmap_index = 215784, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坭)*/
	{.bitmap_index = 215928, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(坯)*/
	{.bitmap_index = 216060, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坳)*/
	{.bitmap_index = 216204, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坶)*/
	{.bitmap_index = 216342, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(坷)*/
	{.bitmap_index = 216480, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坻)*/
	{.bitmap_index = 216624, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(坼)*/
	{.bitmap_index = 216768, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(垂)*/
	{.bitmap_index = 216906, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(垃)*/
	{.bitmap_index = 217038, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(垄)*/
	{.bitmap_index = 217170, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(垅)*/
	{.bitmap_index = 217314, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(垆)*/
	{.bitmap_index = 217458, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(型)*/
	{.bitmap_index = 217596, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垌)*/
	{.bitmap_index = 217734, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(垒)*/
	{.bitmap_index = 217878, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(垓)*/
	{.bitmap_index = 218022, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垛)*/
	{.bitmap_index = 218160, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(垠)*/
	{.bitmap_index = 218304, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垡)*/
	{.bitmap_index = 218448, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垢)*/
	{.bitmap_index = 218586, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(垣)*/
	{.bitmap_index = 218718, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垤)*/
	{.bitmap_index = 218856, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(垦)*/
	{.bitmap_index = 218988, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垧)*/
	{.bitmap_index = 219126, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(垩)*/
	{.bitmap_index = 219258, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(垫)*/
	{.bitmap_index = 219396, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垭)*/
	{.bitmap_index = 219534, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垮)*/
	{.bitmap_index = 219672, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垲)*/
	{.bitmap_index = 219810, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(垴)*/
	{.bitmap_index = 219948, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(垸)*/
	{.bitmap_index = 220092, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(埂)*/
	{.bitmap_index = 220236, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(埃)*/
	{.bitmap_index = 220386, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埋)*/
	{.bitmap_index = 220524, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(城)*/
	{.bitmap_index = 220668, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埏)*/
	{.bitmap_index = 220806, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埒)*/
	{.bitmap_index = 220944, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埔)*/
	{.bitmap_index = 221082, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(埕)*/
	{.bitmap_index = 221214, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埘)*/
	{.bitmap_index = 221352, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(埙)*/
	{.bitmap_index = 221496, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埚)*/
	{.bitmap_index = 221634, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埝)*/
	{.bitmap_index = 221772, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(域)*/
	{.bitmap_index = 221910, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埠)*/
	{.bitmap_index = 222048, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埤)*/
	{.bitmap_index = 222186, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埭)*/
	{.bitmap_index = 222324, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埯)*/
	{.bitmap_index = 222462, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(埴)*/
	{.bitmap_index = 222594, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(埸)*/
	{.bitmap_index = 222738, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(培)*/
	{.bitmap_index = 222876, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(基)*/
	{.bitmap_index = 223014, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(埽)*/
	{.bitmap_index = 223152, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堀)*/
	{.bitmap_index = 223290, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(堂)*/
	{.bitmap_index = 223428, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堆)*/
	{.bitmap_index = 223566, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(堇)*/
	{.bitmap_index = 223704, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(堋)*/
	{.bitmap_index = 223848, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(堍)*/
	{.bitmap_index = 223992, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(堑)*/
	{.bitmap_index = 224130, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(堕)*/
	{.bitmap_index = 224268, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堙)*/
	{.bitmap_index = 224406, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堞)*/
	{.bitmap_index = 224544, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(堠)*/
	{.bitmap_index = 224688, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堡)*/
	{.bitmap_index = 224832, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(堤)*/
	{.bitmap_index = 224976, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堪)*/
	{.bitmap_index = 225114, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(堰)*/
	{.bitmap_index = 225252, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(堵)*/
	{.bitmap_index = 225390, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(塄)*/
	{.bitmap_index = 225534, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(塌)*/
	{.bitmap_index = 225672, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(塍)*/
	{.bitmap_index = 225810, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(塑)*/
	{.bitmap_index = 225948, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(塔)*/
	{.bitmap_index = 226086, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(塘)*/
	{.bitmap_index = 226230, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(塞)*/
	{.bitmap_index = 226368, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(塥)*/
	{.bitmap_index = 226506, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(填)*/
	{.bitmap_index = 226650, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(塬)*/
	{.bitmap_index = 226788, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(塾)*/
	{.bitmap_index = 226926, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墀)*/
	{.bitmap_index = 227064, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(墁)*/
	{.bitmap_index = 227208, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(境)*/
	{.bitmap_index = 227352, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(墅)*/
	{.bitmap_index = 227484, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墉)*/
	{.bitmap_index = 227622, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墒)*/
	{.bitmap_index = 227760, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墓)*/
	{.bitmap_index = 227898, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墙)*/
	{.bitmap_index = 228036, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墚)*/
	{.bitmap_index = 228174, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(增)*/
	{.bitmap_index = 228312, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(墟)*/
	{.bitmap_index = 228450, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(墨)*/
	{.bitmap_index = 228582, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(墩)*/
	{.bitmap_index = 228726, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(墼)*/
	{.bitmap_index = 228864, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(壁)*/
	{.bitmap_index = 229002, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(壅)*/
	{.bitmap_index = 229140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(壑)*/
	{.bitmap_index = 229278, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(壕)*/
	{.bitmap_index = 229416, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(壤)*/
	{.bitmap_index = 229560, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(士)*/
	{.bitmap_index = 229692, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(壬)*/
	{.bitmap_index = 229824, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(壮)*/
	{.bitmap_index = 229962, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(声)*/
	{.bitmap_index = 230106, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(壳)*/
	{.bitmap_index = 230250, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(壶)*/
	{.bitmap_index = 230388, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(壹)*/
	{.bitmap_index = 230526, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(夂)*/
	{.bitmap_index = 230664, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(处)*/
	{.bitmap_index = 230808, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(备)*/
	{.bitmap_index = 230952, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(复)*/
	{.bitmap_index = 231096, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夏)*/
	{.bitmap_index = 231234, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(夔)*/
	{.bitmap_index = 231384, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夕)*/
	{.bitmap_index = 231528, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(外)*/
	{.bitmap_index = 231666, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夙)*/
	{.bitmap_index = 231804, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(多)*/
	{.bitmap_index = 231948, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(夜)*/
	{.bitmap_index = 232086, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(够)*/
	{.bitmap_index = 232230, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(夤)*/
	{.bitmap_index = 232380, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夥)*/
	{.bitmap_index = 232524, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(大)*/
	{.bitmap_index = 232668, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(天)*/
	{.bitmap_index = 232806, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(太)*/
	{.bitmap_index = 232950, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夫)*/
	{.bitmap_index = 233094, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夭)*/
	{.bitmap_index = 233232, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(央)*/
	{.bitmap_index = 233376, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夯)*/
	{.bitmap_index = 233520, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(失)*/
	{.bitmap_index = 233664, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(头)*/
	{.bitmap_index = 233808, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(夷)*/
	{.bitmap_index = 233946, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(夸)*/
	{.bitmap_index = 234084, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(夹)*/
	{.bitmap_index = 234228, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(夺)*/
	{.bitmap_index = 234366, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(夼)*/
	{.bitmap_index = 234510, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奁)*/
	{.bitmap_index = 234648, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奂)*/
	{.bitmap_index = 234792, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奄)*/
	{.bitmap_index = 234930, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(奇)*/
	{.bitmap_index = 235068, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奈)*/
	{.bitmap_index = 235206, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奉)*/
	{.bitmap_index = 235344, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奋)*/
	{.bitmap_index = 235482, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奎)*/
	{.bitmap_index = 235620, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奏)*/
	{.bitmap_index = 235764, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(契)*/
	{.bitmap_index = 235908, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奔)*/
	{.bitmap_index = 236052, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奕)*/
	{.bitmap_index = 236196, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奖)*/
	{.bitmap_index = 236340, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(套)*/
	{.bitmap_index = 236484, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(奘)*/
	{.bitmap_index = 236628, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奚)*/
	{.bitmap_index = 236772, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(奠)*/
	{.bitmap_index = 236922, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(奢)*/
	{.bitmap_index = 237060, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(奥)*/
	{.bitmap_index = 237204, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(女)*/
	{.bitmap_index = 237348, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奴)*/
	{.bitmap_index = 237492, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奶)*/
	{.bitmap_index = 237636, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(奸)*/
	{.bitmap_index = 237780, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(她)*/
	{.bitmap_index = 237918, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(好)*/
	{.bitmap_index = 238056, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妁)*/
	{.bitmap_index = 238200, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(如)*/
	{.bitmap_index = 238344, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妃)*/
	{.bitmap_index = 238488, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(妄)*/
	{.bitmap_index = 238632, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妆)*/
	{.bitmap_index = 238770, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(妇)*/
	{.bitmap_index = 238908, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妈)*/
	{.bitmap_index = 239052, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妊)*/
	{.bitmap_index = 239196, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妍)*/
	{.bitmap_index = 239340, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妒)*/
	{.bitmap_index = 239484, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妓)*/
	{.bitmap_index = 239628, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妖)*/
	{.bitmap_index = 239772, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妗)*/
	{.bitmap_index = 239922, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妙)*/
	{.bitmap_index = 240066, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妞)*/
	{.bitmap_index = 240204, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妣)*/
	{.bitmap_index = 240348, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妤)*/
	{.bitmap_index = 240486, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(妥)*/
	{.bitmap_index = 240630, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妨)*/
	{.bitmap_index = 240768, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妩)*/
	{.bitmap_index = 240906, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妪)*/
	{.bitmap_index = 241044, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妫)*/
	{.bitmap_index = 241188, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妮)*/
	{.bitmap_index = 241326, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妯)*/
	{.bitmap_index = 241464, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(妲)*/
	{.bitmap_index = 241602, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(妹)*/
	{.bitmap_index = 241746, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(妻)*/
	{.bitmap_index = 241890, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(妾)*/
	{.bitmap_index = 242034, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姆)*/
	{.bitmap_index = 242178, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(姊)*/
	{.bitmap_index = 242316, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(始)*/
	{.bitmap_index = 242460, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姐)*/
	{.bitmap_index = 242604, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姑)*/
	{.bitmap_index = 242748, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姒)*/
	{.bitmap_index = 242892, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姓)*/
	{.bitmap_index = 243036, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(委)*/
	{.bitmap_index = 243180, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姗)*/
	{.bitmap_index = 243324, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姘)*/
	{.bitmap_index = 243468, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姚)*/
	{.bitmap_index = 243612, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(姜)*/
	{.bitmap_index = 243756, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(姝)*/
	{.bitmap_index = 243894, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姣)*/
	{.bitmap_index = 244038, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姥)*/
	{.bitmap_index = 244182, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(姨)*/
	{.bitmap_index = 244326, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(姬)*/
	{.bitmap_index = 244464, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(姹)*/
	{.bitmap_index = 244602, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(姻)*/
	{.bitmap_index = 244740, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(姿)*/
	{.bitmap_index = 244884, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(威)*/
	{.bitmap_index = 245022, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娃)*/
	{.bitmap_index = 245160, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(娄)*/
	{.bitmap_index = 245304, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娅)*/
	{.bitmap_index = 245442, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娆)*/
	{.bitmap_index = 245586, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娇)*/
	{.bitmap_index = 245730, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娈)*/
	{.bitmap_index = 245874, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娉)*/
	{.bitmap_index = 246012, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娌)*/
	{.bitmap_index = 246156, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(娑)*/
	{.bitmap_index = 246300, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娓)*/
	{.bitmap_index = 246444, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娘)*/
	{.bitmap_index = 246582, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娜)*/
	{.bitmap_index = 246720, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娟)*/
	{.bitmap_index = 246864, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娠)*/
	{.bitmap_index = 247008, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娣)*/
	{.bitmap_index = 247146, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娥)*/
	{.bitmap_index = 247290, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娩)*/
	{.bitmap_index = 247434, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娱)*/
	{.bitmap_index = 247578, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娲)*/
	{.bitmap_index = 247716, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(娴)*/
	{.bitmap_index = 247854, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(娶)*/
	{.bitmap_index = 247992, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(娼)*/
	{.bitmap_index = 248136, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(婀)*/
	{.bitmap_index = 248274, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(婆)*/
	{.bitmap_index = 248418, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婉)*/
	{.bitmap_index = 248562, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婊)*/
	{.bitmap_index = 248706, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婕)*/
	{.bitmap_index = 248850, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(婚)*/
	{.bitmap_index = 248988, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(婢)*/
	{.bitmap_index = 249126, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婧)*/
	{.bitmap_index = 249270, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婪)*/
	{.bitmap_index = 249414, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(婴)*/
	{.bitmap_index = 249552, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婵)*/
	{.bitmap_index = 249696, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(婶)*/
	{.bitmap_index = 249834, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(婷)*/
	{.bitmap_index = 249972, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婺)*/
	{.bitmap_index = 250116, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(婿)*/
	{.bitmap_index = 250260, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(媒)*/
	{.bitmap_index = 250398, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(媚)*/
	{.bitmap_index = 250536, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(媛)*/
	{.bitmap_index = 250680, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(媪)*/
	{.bitmap_index = 250818, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(媲)*/
	{.bitmap_index = 250962, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(媳)*/
	{.bitmap_index = 251100, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(媵)*/
	{.bitmap_index = 251244, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(媸)*/
	{.bitmap_index = 251388, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(媾)*/
	{.bitmap_index = 251526, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫁)*/
	{.bitmap_index = 251664, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫂)*/
	{.bitmap_index = 251808, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫉)*/
	{.bitmap_index = 251952, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫌)*/
	{.bitmap_index = 252090, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫒)*/
	{.bitmap_index = 252234, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫔)*/
	{.bitmap_index = 252378, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫖)*/
	{.bitmap_index = 252522, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫘)*/
	{.bitmap_index = 252660, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫜)*/
	{.bitmap_index = 252798, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫠)*/
	{.bitmap_index = 252942, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫡)*/
	{.bitmap_index = 253080, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫣)*/
	{.bitmap_index = 253218, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嫦)*/
	{.bitmap_index = 253356, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫩)*/
	{.bitmap_index = 253500, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫫)*/
	{.bitmap_index = 253644, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嫱)*/
	{.bitmap_index = 253788, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嬉)*/
	{.bitmap_index = 253926, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嬖)*/
	{.bitmap_index = 254070, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嬗)*/
	{.bitmap_index = 254208, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嬲)*/
	{.bitmap_index = 254352, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(嬴)*/
	{.bitmap_index = 254496, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嬷)*/
	{.bitmap_index = 254634, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孀)*/
	{.bitmap_index = 254772, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(子)*/
	{.bitmap_index = 254904, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孑)*/
	{.bitmap_index = 255036, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孓)*/
	{.bitmap_index = 255168, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孔)*/
	{.bitmap_index = 255306, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孕)*/
	{.bitmap_index = 255438, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(字)*/
	{.bitmap_index = 255576, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(存)*/
	{.bitmap_index = 255714, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孙)*/
	{.bitmap_index = 255852, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孚)*/
	{.bitmap_index = 255990, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孛)*/
	{.bitmap_index = 256128, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(孜)*/
	{.bitmap_index = 256272, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孝)*/
	{.bitmap_index = 256410, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孟)*/
	{.bitmap_index = 256542, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孢)*/
	{.bitmap_index = 256680, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(季)*/
	{.bitmap_index = 256818, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孤)*/
	{.bitmap_index = 256956, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孥)*/
	{.bitmap_index = 257094, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(学)*/
	{.bitmap_index = 257232, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(孩)*/
	{.bitmap_index = 257376, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(孪)*/
	{.bitmap_index = 257520, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(孬)*/
	{.bitmap_index = 257658, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(孰)*/
	{.bitmap_index = 257802, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孱)*/
	{.bitmap_index = 257934, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孳)*/
	{.bitmap_index = 258078, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(孵)*/
	{.bitmap_index = 258222, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(孺)*/
	{.bitmap_index = 258354, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(孽)*/
	{.bitmap_index = 258492, .adv_w = 26, .box_h = 11, .box_w = 24, .ofs_x = 2, .ofs_y = 17},/*(宀)*/
	{.bitmap_index = 258558, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宁)*/
	{.bitmap_index = 258696, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(它)*/
	{.bitmap_index = 258834, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(宄)*/
	{.bitmap_index = 258978, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宅)*/
	{.bitmap_index = 259116, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宇)*/
	{.bitmap_index = 259254, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(守)*/
	{.bitmap_index = 259392, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(安)*/
	{.bitmap_index = 259536, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宋)*/
	{.bitmap_index = 259674, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(完)*/
	{.bitmap_index = 259818, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宏)*/
	{.bitmap_index = 259956, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宓)*/
	{.bitmap_index = 260094, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宕)*/
	{.bitmap_index = 260232, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宗)*/
	{.bitmap_index = 260370, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(官)*/
	{.bitmap_index = 260508, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宙)*/
	{.bitmap_index = 260646, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(定)*/
	{.bitmap_index = 260790, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(宛)*/
	{.bitmap_index = 260934, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宜)*/
	{.bitmap_index = 261072, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宝)*/
	{.bitmap_index = 261210, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(实)*/
	{.bitmap_index = 261354, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宠)*/
	{.bitmap_index = 261492, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(审)*/
	{.bitmap_index = 261630, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(客)*/
	{.bitmap_index = 261768, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宣)*/
	{.bitmap_index = 261906, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(室)*/
	{.bitmap_index = 262044, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宥)*/
	{.bitmap_index = 262182, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(宦)*/
	{.bitmap_index = 262314, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(宪)*/
	{.bitmap_index = 262458, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宫)*/
	{.bitmap_index = 262596, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宰)*/
	{.bitmap_index = 262734, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(害)*/
	{.bitmap_index = 262872, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(宴)*/
	{.bitmap_index = 263016, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(宵)*/
	{.bitmap_index = 263154, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(家)*/
	{.bitmap_index = 263292, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(宸)*/
	{.bitmap_index = 263436, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(容)*/
	{.bitmap_index = 263574, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(宽)*/
	{.bitmap_index = 263718, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(宾)*/
	{.bitmap_index = 263862, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(宿)*/
	{.bitmap_index = 264000, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寂)*/
	{.bitmap_index = 264144, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(寄)*/
	{.bitmap_index = 264282, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(寅)*/
	{.bitmap_index = 264426, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(密)*/
	{.bitmap_index = 264564, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寇)*/
	{.bitmap_index = 264708, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(富)*/
	{.bitmap_index = 264846, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寐)*/
	{.bitmap_index = 264990, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寒)*/
	{.bitmap_index = 265134, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(寓)*/
	{.bitmap_index = 265272, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寝)*/
	{.bitmap_index = 265416, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(寞)*/
	{.bitmap_index = 265560, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(察)*/
	{.bitmap_index = 265698, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寡)*/
	{.bitmap_index = 265842, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寤)*/
	{.bitmap_index = 265986, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寥)*/
	{.bitmap_index = 266130, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寨)*/
	{.bitmap_index = 266274, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(寮)*/
	{.bitmap_index = 266412, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(寰)*/
	{.bitmap_index = 266556, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(寸)*/
	{.bitmap_index = 266694, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(对)*/
	{.bitmap_index = 266832, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(寺)*/
	{.bitmap_index = 266970, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(寻)*/
	{.bitmap_index = 267102, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(导)*/
	{.bitmap_index = 267234, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(寿)*/
	{.bitmap_index = 267372, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(封)*/
	{.bitmap_index = 267510, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(射)*/
	{.bitmap_index = 267648, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(将)*/
	{.bitmap_index = 267792, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尉)*/
	{.bitmap_index = 267930, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(尊)*/
	{.bitmap_index = 268074, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(小)*/
	{.bitmap_index = 268212, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(少)*/
	{.bitmap_index = 268356, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尔)*/
	{.bitmap_index = 268494, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尕)*/
	{.bitmap_index = 268626, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(尖)*/
	{.bitmap_index = 268770, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(尘)*/
	{.bitmap_index = 268908, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(尚)*/
	{.bitmap_index = 269023, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尜)*/
	{.bitmap_index = 269167, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(尝)*/
	{.bitmap_index = 269311, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尢)*/
	{.bitmap_index = 269449, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尤)*/
	{.bitmap_index = 269587, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尥)*/
	{.bitmap_index = 269731, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(尧)*/
	{.bitmap_index = 269875, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尬)*/
	{.bitmap_index = 270013, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(就)*/
	{.bitmap_index = 270151, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(尴)*/
	{.bitmap_index = 270289, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尸)*/
	{.bitmap_index = 270427, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(尹)*/
	{.bitmap_index = 270565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尺)*/
	{.bitmap_index = 270703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尻)*/
	{.bitmap_index = 270841, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尼)*/
	{.bitmap_index = 270979, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尽)*/
	{.bitmap_index = 271117, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尾)*/
	{.bitmap_index = 271255, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(尿)*/
	{.bitmap_index = 271393, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(局)*/
	{.bitmap_index = 271525, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(屁)*/
	{.bitmap_index = 271657, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(层)*/
	{.bitmap_index = 271795, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(居)*/
	{.bitmap_index = 271927, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(屈)*/
	{.bitmap_index = 272059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屉)*/
	{.bitmap_index = 272197, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(届)*/
	{.bitmap_index = 272329, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屋)*/
	{.bitmap_index = 272467, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屎)*/
	{.bitmap_index = 272605, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屏)*/
	{.bitmap_index = 272743, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屐)*/
	{.bitmap_index = 272881, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(屑)*/
	{.bitmap_index = 273013, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(展)*/
	{.bitmap_index = 273151, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(屙)*/
	{.bitmap_index = 273283, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(属)*/
	{.bitmap_index = 273415, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(屠)*/
	{.bitmap_index = 273547, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屡)*/
	{.bitmap_index = 273685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屣)*/
	{.bitmap_index = 273823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(履)*/
	{.bitmap_index = 273961, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(屦)*/
	{.bitmap_index = 274099, .adv_w = 23, .box_h = 23, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(屮)*/
	{.bitmap_index = 274214, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(屯)*/
	{.bitmap_index = 274352, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(山)*/
	{.bitmap_index = 274462, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(屹)*/
	{.bitmap_index = 274600, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(屺)*/
	{.bitmap_index = 274738, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(屿)*/
	{.bitmap_index = 274876, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岁)*/
	{.bitmap_index = 275020, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(岂)*/
	{.bitmap_index = 275158, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岈)*/
	{.bitmap_index = 275296, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(岌)*/
	{.bitmap_index = 275440, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岍)*/
	{.bitmap_index = 275584, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岐)*/
	{.bitmap_index = 275728, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(岑)*/
	{.bitmap_index = 275872, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(岔)*/
	{.bitmap_index = 276010, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岖)*/
	{.bitmap_index = 276148, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(岗)*/
	{.bitmap_index = 276263, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岘)*/
	{.bitmap_index = 276407, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(岙)*/
	{.bitmap_index = 276545, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岚)*/
	{.bitmap_index = 276689, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(岛)*/
	{.bitmap_index = 276827, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(岜)*/
	{.bitmap_index = 276965, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岢)*/
	{.bitmap_index = 277103, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岣)*/
	{.bitmap_index = 277241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(岩)*/
	{.bitmap_index = 277379, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岫)*/
	{.bitmap_index = 277517, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岬)*/
	{.bitmap_index = 277655, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岭)*/
	{.bitmap_index = 277805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(岱)*/
	{.bitmap_index = 277943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(岳)*/
	{.bitmap_index = 278081, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(岵)*/
	{.bitmap_index = 278213, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(岷)*/
	{.bitmap_index = 278357, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(岸)*/
	{.bitmap_index = 278501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(岽)*/
	{.bitmap_index = 278639, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(岿)*/
	{.bitmap_index = 278759, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(峁)*/
	{.bitmap_index = 278903, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峄)*/
	{.bitmap_index = 279041, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峋)*/
	{.bitmap_index = 279179, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峒)*/
	{.bitmap_index = 279317, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峙)*/
	{.bitmap_index = 279455, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(峡)*/
	{.bitmap_index = 279599, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(峤)*/
	{.bitmap_index = 279743, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峥)*/
	{.bitmap_index = 279881, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(峦)*/
	{.bitmap_index = 280019, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峨)*/
	{.bitmap_index = 280157, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峪)*/
	{.bitmap_index = 280295, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峭)*/
	{.bitmap_index = 280433, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(峰)*/
	{.bitmap_index = 280571, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(峻)*/
	{.bitmap_index = 280715, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(崂)*/
	{.bitmap_index = 280859, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(崃)*/
	{.bitmap_index = 280997, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(崆)*/
	{.bitmap_index = 281129, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(崇)*/
	{.bitmap_index = 281273, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(崎)*/
	{.bitmap_index = 281411, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(崔)*/
	{.bitmap_index = 281549, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(崖)*/
	{.bitmap_index = 281693, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(崛)*/
	{.bitmap_index = 281831, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(崞)*/
	{.bitmap_index = 281969, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(崤)*/
	{.bitmap_index = 282107, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(崦)*/
	{.bitmap_index = 282245, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(崧)*/
	{.bitmap_index = 282383, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(崩)*/
	{.bitmap_index = 282527, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(崭)*/
	{.bitmap_index = 282671, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(崮)*/
	{.bitmap_index = 282786, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(崴)*/
	{.bitmap_index = 282930, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(崽)*/
	{.bitmap_index = 283068, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(崾)*/
	{.bitmap_index = 283212, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嵇)*/
	{.bitmap_index = 283350, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵊)*/
	{.bitmap_index = 283488, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵋)*/
	{.bitmap_index = 283626, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嵌)*/
	{.bitmap_index = 283770, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵘)*/
	{.bitmap_index = 283908, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(嵛)*/
	{.bitmap_index = 284046, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵝)*/
	{.bitmap_index = 284184, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵩)*/
	{.bitmap_index = 284322, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵫)*/
	{.bitmap_index = 284460, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嵬)*/
	{.bitmap_index = 284604, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵯)*/
	{.bitmap_index = 284742, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嵴)*/
	{.bitmap_index = 284880, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嶂)*/
	{.bitmap_index = 285018, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嶙)*/
	{.bitmap_index = 285162, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(嶝)*/
	{.bitmap_index = 285300, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(嶷)*/
	{.bitmap_index = 285444, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(巅)*/
	{.bitmap_index = 285588, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(巍)*/
	{.bitmap_index = 285726, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(巛)*/
	{.bitmap_index = 285858, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(川)*/
	{.bitmap_index = 286002, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(州)*/
	{.bitmap_index = 286146, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(巡)*/
	{.bitmap_index = 286284, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(巢)*/
	{.bitmap_index = 286428, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(工)*/
	{.bitmap_index = 286548, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(左)*/
	{.bitmap_index = 286680, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(巧)*/
	{.bitmap_index = 286812, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(巨)*/
	{.bitmap_index = 286944, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(巩)*/
	{.bitmap_index = 287082, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(巫)*/
	{.bitmap_index = 287208, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(差)*/
	{.bitmap_index = 287352, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(巯)*/
	{.bitmap_index = 287496, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(己)*/
	{.bitmap_index = 287628, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(已)*/
	{.bitmap_index = 287760, .adv_w = 23, .box_h = 22, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(巳)*/
	{.bitmap_index = 287870, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(巴)*/
	{.bitmap_index = 288002, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(巷)*/
	{.bitmap_index = 288140, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(巽)*/
	{.bitmap_index = 288278, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(巾)*/
	{.bitmap_index = 288393, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(币)*/
	{.bitmap_index = 288508, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(市)*/
	{.bitmap_index = 288646, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(布)*/
	{.bitmap_index = 288784, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(帅)*/
	{.bitmap_index = 288928, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帆)*/
	{.bitmap_index = 289066, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(师)*/
	{.bitmap_index = 289210, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(希)*/
	{.bitmap_index = 289348, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帏)*/
	{.bitmap_index = 289486, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帐)*/
	{.bitmap_index = 289624, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(帑)*/
	{.bitmap_index = 289762, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(帔)*/
	{.bitmap_index = 289906, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帕)*/
	{.bitmap_index = 290044, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帖)*/
	{.bitmap_index = 290182, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帘)*/
	{.bitmap_index = 290320, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(帙)*/
	{.bitmap_index = 290464, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帚)*/
	{.bitmap_index = 290596, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(帛)*/
	{.bitmap_index = 290711, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(帜)*/
	{.bitmap_index = 290855, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帝)*/
	{.bitmap_index = 290993, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(带)*/
	{.bitmap_index = 291131, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(帧)*/
	{.bitmap_index = 291275, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(席)*/
	{.bitmap_index = 291419, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(帮)*/
	{.bitmap_index = 291557, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帱)*/
	{.bitmap_index = 291695, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帷)*/
	{.bitmap_index = 291833, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(常)*/
	{.bitmap_index = 291971, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(帻)*/
	{.bitmap_index = 292115, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帼)*/
	{.bitmap_index = 292253, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(帽)*/
	{.bitmap_index = 292391, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(幂)*/
	{.bitmap_index = 292523, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(幄)*/
	{.bitmap_index = 292667, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幅)*/
	{.bitmap_index = 292805, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(幌)*/
	{.bitmap_index = 292949, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(幔)*/
	{.bitmap_index = 293093, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(幕)*/
	{.bitmap_index = 293231, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幛)*/
	{.bitmap_index = 293369, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(幞)*/
	{.bitmap_index = 293513, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幡)*/
	{.bitmap_index = 293651, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幢)*/
	{.bitmap_index = 293789, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(干)*/
	{.bitmap_index = 293921, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(平)*/
	{.bitmap_index = 294053, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(年)*/
	{.bitmap_index = 294197, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(并)*/
	{.bitmap_index = 294347, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幸)*/
	{.bitmap_index = 294485, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(幺)*/
	{.bitmap_index = 294623, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幻)*/
	{.bitmap_index = 294761, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(幼)*/
	{.bitmap_index = 294905, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(幽)*/
	{.bitmap_index = 295043, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(广)*/
	{.bitmap_index = 295187, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(庀)*/
	{.bitmap_index = 295325, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庄)*/
	{.bitmap_index = 295469, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庆)*/
	{.bitmap_index = 295613, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(庇)*/
	{.bitmap_index = 295751, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(床)*/
	{.bitmap_index = 295895, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庋)*/
	{.bitmap_index = 296039, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(序)*/
	{.bitmap_index = 296183, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庐)*/
	{.bitmap_index = 296327, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庑)*/
	{.bitmap_index = 296471, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(库)*/
	{.bitmap_index = 296615, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(应)*/
	{.bitmap_index = 296759, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(底)*/
	{.bitmap_index = 296903, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(庖)*/
	{.bitmap_index = 297041, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(店)*/
	{.bitmap_index = 297179, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庙)*/
	{.bitmap_index = 297323, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庚)*/
	{.bitmap_index = 297467, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(府)*/
	{.bitmap_index = 297611, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庞)*/
	{.bitmap_index = 297755, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(废)*/
	{.bitmap_index = 297899, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庠)*/
	{.bitmap_index = 298043, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庥)*/
	{.bitmap_index = 298187, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(度)*/
	{.bitmap_index = 298331, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(座)*/
	{.bitmap_index = 298475, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庭)*/
	{.bitmap_index = 298619, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(庳)*/
	{.bitmap_index = 298757, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(庵)*/
	{.bitmap_index = 298895, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庶)*/
	{.bitmap_index = 299039, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(康)*/
	{.bitmap_index = 299177, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(庸)*/
	{.bitmap_index = 299315, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庹)*/
	{.bitmap_index = 299459, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(庾)*/
	{.bitmap_index = 299603, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廉)*/
	{.bitmap_index = 299741, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廊)*/
	{.bitmap_index = 299879, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廑)*/
	{.bitmap_index = 300017, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(廒)*/
	{.bitmap_index = 300161, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廓)*/
	{.bitmap_index = 300299, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(廖)*/
	{.bitmap_index = 300443, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廛)*/
	{.bitmap_index = 300581, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(廨)*/
	{.bitmap_index = 300725, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(廪)*/
	{.bitmap_index = 300869, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廴)*/
	{.bitmap_index = 301001, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(延)*/
	{.bitmap_index = 301145, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(廷)*/
	{.bitmap_index = 301277, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(建)*/
	{.bitmap_index = 301421, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(廾)*/
	{.bitmap_index = 301559, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(廿)*/
	{.bitmap_index = 301691, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(开)*/
	{.bitmap_index = 301829, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(弁)*/
	{.bitmap_index = 301973, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(异)*/
	{.bitmap_index = 302111, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(弃)*/
	{.bitmap_index = 302261, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(弄)*/
	{.bitmap_index = 302399, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(弈)*/
	{.bitmap_index = 302543, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(弊)*/
	{.bitmap_index = 302687, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弋)*/
	{.bitmap_index = 302825, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(式)*/
	{.bitmap_index = 302963, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(弑)*/
	{.bitmap_index = 303101, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(弓)*/
	{.bitmap_index = 303211, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(引)*/
	{.bitmap_index = 303326, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(弗)*/
	{.bitmap_index = 303470, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弘)*/
	{.bitmap_index = 303608, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弛)*/
	{.bitmap_index = 303746, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(弟)*/
	{.bitmap_index = 303890, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(张)*/
	{.bitmap_index = 304028, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弥)*/
	{.bitmap_index = 304166, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弦)*/
	{.bitmap_index = 304304, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弧)*/
	{.bitmap_index = 304442, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(弩)*/
	{.bitmap_index = 304580, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弪)*/
	{.bitmap_index = 304712, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弭)*/
	{.bitmap_index = 304844, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(弯)*/
	{.bitmap_index = 304988, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弱)*/
	{.bitmap_index = 305120, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弹)*/
	{.bitmap_index = 305258, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(强)*/
	{.bitmap_index = 305396, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(弼)*/
	{.bitmap_index = 305528, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(彀)*/
	{.bitmap_index = 305666, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(彐)*/
	{.bitmap_index = 305766, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(归)*/
	{.bitmap_index = 305886, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(当)*/
	{.bitmap_index = 306018, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(录)*/
	{.bitmap_index = 306150, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(彖)*/
	{.bitmap_index = 306288, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(彗)*/
	{.bitmap_index = 306426, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(彘)*/
	{.bitmap_index = 306564, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(彝)*/
	{.bitmap_index = 306708, .adv_w = 23, .box_h = 23, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(彡)*/
	{.bitmap_index = 306823, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(形)*/
	{.bitmap_index = 306967, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(彤)*/
	{.bitmap_index = 307111, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(彦)*/
	{.bitmap_index = 307255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(彩)*/
	{.bitmap_index = 307399, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(彪)*/
	{.bitmap_index = 307543, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(彬)*/
	{.bitmap_index = 307681, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(彭)*/
	{.bitmap_index = 307825, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(彰)*/
	{.bitmap_index = 307969, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(影)*/
	{.bitmap_index = 308113, .adv_w = 17, .box_h = 24, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(彳)*/
	{.bitmap_index = 308209, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(彷)*/
	{.bitmap_index = 308347, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(役)*/
	{.bitmap_index = 308491, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(彻)*/
	{.bitmap_index = 308635, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(彼)*/
	{.bitmap_index = 308779, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(往)*/
	{.bitmap_index = 308917, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(征)*/
	{.bitmap_index = 309055, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徂)*/
	{.bitmap_index = 309193, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(径)*/
	{.bitmap_index = 309331, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(待)*/
	{.bitmap_index = 309469, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徇)*/
	{.bitmap_index = 309607, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(很)*/
	{.bitmap_index = 309751, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徉)*/
	{.bitmap_index = 309889, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徊)*/
	{.bitmap_index = 310027, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(律)*/
	{.bitmap_index = 310165, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(後)*/
	{.bitmap_index = 310309, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徐)*/
	{.bitmap_index = 310447, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(徒)*/
	{.bitmap_index = 310591, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徕)*/
	{.bitmap_index = 310729, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(得)*/
	{.bitmap_index = 310867, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徘)*/
	{.bitmap_index = 311005, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徙)*/
	{.bitmap_index = 311143, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徜)*/
	{.bitmap_index = 311281, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(御)*/
	{.bitmap_index = 311419, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徨)*/
	{.bitmap_index = 311557, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(循)*/
	{.bitmap_index = 311695, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徭)*/
	{.bitmap_index = 311833, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(微)*/
	{.bitmap_index = 311971, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徵)*/
	{.bitmap_index = 312109, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(德)*/
	{.bitmap_index = 312247, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(徼)*/
	{.bitmap_index = 312385, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(徽)*/
	{.bitmap_index = 312529, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(心)*/
	{.bitmap_index = 312667, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(忄)*/
	{.bitmap_index = 312759, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(必)*/
	{.bitmap_index = 312897, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忆)*/
	{.bitmap_index = 313035, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忉)*/
	{.bitmap_index = 313173, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忌)*/
	{.bitmap_index = 313305, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忍)*/
	{.bitmap_index = 313437, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忏)*/
	{.bitmap_index = 313575, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忐)*/
	{.bitmap_index = 313713, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忑)*/
	{.bitmap_index = 313845, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忒)*/
	{.bitmap_index = 313983, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忖)*/
	{.bitmap_index = 314121, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(志)*/
	{.bitmap_index = 314259, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忘)*/
	{.bitmap_index = 314397, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忙)*/
	{.bitmap_index = 314535, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忝)*/
	{.bitmap_index = 314667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忠)*/
	{.bitmap_index = 314805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忡)*/
	{.bitmap_index = 314943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忤)*/
	{.bitmap_index = 315081, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(忧)*/
	{.bitmap_index = 315225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忪)*/
	{.bitmap_index = 315363, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(快)*/
	{.bitmap_index = 315507, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忭)*/
	{.bitmap_index = 315645, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忮)*/
	{.bitmap_index = 315783, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忱)*/
	{.bitmap_index = 315921, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(念)*/
	{.bitmap_index = 316059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忸)*/
	{.bitmap_index = 316197, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(忻)*/
	{.bitmap_index = 316341, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忽)*/
	{.bitmap_index = 316479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忾)*/
	{.bitmap_index = 316617, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(忿)*/
	{.bitmap_index = 316761, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怀)*/
	{.bitmap_index = 316899, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(态)*/
	{.bitmap_index = 317037, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怂)*/
	{.bitmap_index = 317175, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怃)*/
	{.bitmap_index = 317313, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怄)*/
	{.bitmap_index = 317451, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怅)*/
	{.bitmap_index = 317589, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怆)*/
	{.bitmap_index = 317727, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怊)*/
	{.bitmap_index = 317865, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怍)*/
	{.bitmap_index = 318003, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怎)*/
	{.bitmap_index = 318141, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(怏)*/
	{.bitmap_index = 318285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怒)*/
	{.bitmap_index = 318423, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怔)*/
	{.bitmap_index = 318561, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怕)*/
	{.bitmap_index = 318699, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怖)*/
	{.bitmap_index = 318837, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怙)*/
	{.bitmap_index = 318975, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怛)*/
	{.bitmap_index = 319113, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(怜)*/
	{.bitmap_index = 319257, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(思)*/
	{.bitmap_index = 319389, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怠)*/
	{.bitmap_index = 319533, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怡)*/
	{.bitmap_index = 319671, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(急)*/
	{.bitmap_index = 319815, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怦)*/
	{.bitmap_index = 319953, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(性)*/
	{.bitmap_index = 320091, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怨)*/
	{.bitmap_index = 320235, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怩)*/
	{.bitmap_index = 320373, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怪)*/
	{.bitmap_index = 320511, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(怫)*/
	{.bitmap_index = 320655, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怯)*/
	{.bitmap_index = 320793, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怵)*/
	{.bitmap_index = 320931, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(总)*/
	{.bitmap_index = 321069, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怼)*/
	{.bitmap_index = 321207, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(怿)*/
	{.bitmap_index = 321345, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恁)*/
	{.bitmap_index = 321483, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恂)*/
	{.bitmap_index = 321621, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恃)*/
	{.bitmap_index = 321759, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恋)*/
	{.bitmap_index = 321897, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(恍)*/
	{.bitmap_index = 322041, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恐)*/
	{.bitmap_index = 322173, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恒)*/
	{.bitmap_index = 322311, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恕)*/
	{.bitmap_index = 322449, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恙)*/
	{.bitmap_index = 322593, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恚)*/
	{.bitmap_index = 322731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恝)*/
	{.bitmap_index = 322869, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恢)*/
	{.bitmap_index = 323007, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恣)*/
	{.bitmap_index = 323145, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恤)*/
	{.bitmap_index = 323283, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恧)*/
	{.bitmap_index = 323415, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恨)*/
	{.bitmap_index = 323553, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恩)*/
	{.bitmap_index = 323685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恪)*/
	{.bitmap_index = 323823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恫)*/
	{.bitmap_index = 323961, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恬)*/
	{.bitmap_index = 324099, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恭)*/
	{.bitmap_index = 324237, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(息)*/
	{.bitmap_index = 324375, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恰)*/
	{.bitmap_index = 324513, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恳)*/
	{.bitmap_index = 324645, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恶)*/
	{.bitmap_index = 324777, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(恸)*/
	{.bitmap_index = 324921, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(恹)*/
	{.bitmap_index = 325065, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恺)*/
	{.bitmap_index = 325203, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恻)*/
	{.bitmap_index = 325341, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恼)*/
	{.bitmap_index = 325479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恽)*/
	{.bitmap_index = 325617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(恿)*/
	{.bitmap_index = 325755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悃)*/
	{.bitmap_index = 325893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悄)*/
	{.bitmap_index = 326031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悉)*/
	{.bitmap_index = 326169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悌)*/
	{.bitmap_index = 326307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悍)*/
	{.bitmap_index = 326445, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悒)*/
	{.bitmap_index = 326583, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悔)*/
	{.bitmap_index = 326721, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悖)*/
	{.bitmap_index = 326859, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悚)*/
	{.bitmap_index = 326997, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(悛)*/
	{.bitmap_index = 327141, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悝)*/
	{.bitmap_index = 327279, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悟)*/
	{.bitmap_index = 327417, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悠)*/
	{.bitmap_index = 327555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(患)*/
	{.bitmap_index = 327693, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(悦)*/
	{.bitmap_index = 327837, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(您)*/
	{.bitmap_index = 327975, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(悫)*/
	{.bitmap_index = 328113, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悬)*/
	{.bitmap_index = 328245, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悭)*/
	{.bitmap_index = 328383, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悯)*/
	{.bitmap_index = 328521, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悱)*/
	{.bitmap_index = 328659, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悲)*/
	{.bitmap_index = 328797, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悴)*/
	{.bitmap_index = 328935, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悸)*/
	{.bitmap_index = 329073, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悻)*/
	{.bitmap_index = 329211, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(悼)*/
	{.bitmap_index = 329349, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(情)*/
	{.bitmap_index = 329487, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(惆)*/
	{.bitmap_index = 329631, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惊)*/
	{.bitmap_index = 329769, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惋)*/
	{.bitmap_index = 329907, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惑)*/
	{.bitmap_index = 330051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(惕)*/
	{.bitmap_index = 330195, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惘)*/
	{.bitmap_index = 330333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惚)*/
	{.bitmap_index = 330471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惜)*/
	{.bitmap_index = 330609, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惝)*/
	{.bitmap_index = 330747, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惟)*/
	{.bitmap_index = 330885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惠)*/
	{.bitmap_index = 331023, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惦)*/
	{.bitmap_index = 331161, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惧)*/
	{.bitmap_index = 331299, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(惨)*/
	{.bitmap_index = 331443, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惩)*/
	{.bitmap_index = 331581, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惫)*/
	{.bitmap_index = 331725, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惬)*/
	{.bitmap_index = 331863, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惭)*/
	{.bitmap_index = 332001, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惮)*/
	{.bitmap_index = 332139, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惯)*/
	{.bitmap_index = 332277, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惰)*/
	{.bitmap_index = 332415, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(想)*/
	{.bitmap_index = 332553, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惴)*/
	{.bitmap_index = 332691, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惶)*/
	{.bitmap_index = 332829, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惹)*/
	{.bitmap_index = 332967, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(惺)*/
	{.bitmap_index = 333105, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愀)*/
	{.bitmap_index = 333243, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愁)*/
	{.bitmap_index = 333381, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愆)*/
	{.bitmap_index = 333519, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愈)*/
	{.bitmap_index = 333657, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愉)*/
	{.bitmap_index = 333795, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愍)*/
	{.bitmap_index = 333933, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愎)*/
	{.bitmap_index = 334071, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(意)*/
	{.bitmap_index = 334209, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愕)*/
	{.bitmap_index = 334347, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愚)*/
	{.bitmap_index = 334479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(感)*/
	{.bitmap_index = 334617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愠)*/
	{.bitmap_index = 334755, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(愣)*/
	{.bitmap_index = 334899, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(愤)*/
	{.bitmap_index = 335043, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愦)*/
	{.bitmap_index = 335181, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(愧)*/
	{.bitmap_index = 335325, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(愫)*/
	{.bitmap_index = 335463, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(愿)*/
	{.bitmap_index = 335601, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慈)*/
	{.bitmap_index = 335745, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慊)*/
	{.bitmap_index = 335889, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慌)*/
	{.bitmap_index = 336027, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(慎)*/
	{.bitmap_index = 336171, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(慑)*/
	{.bitmap_index = 336315, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慕)*/
	{.bitmap_index = 336453, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(慝)*/
	{.bitmap_index = 336591, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(慢)*/
	{.bitmap_index = 336735, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(慧)*/
	{.bitmap_index = 336873, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慨)*/
	{.bitmap_index = 337011, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慰)*/
	{.bitmap_index = 337149, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慵)*/
	{.bitmap_index = 337287, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(慷)*/
	{.bitmap_index = 337425, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憋)*/
	{.bitmap_index = 337563, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憎)*/
	{.bitmap_index = 337701, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憔)*/
	{.bitmap_index = 337839, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(憝)*/
	{.bitmap_index = 337977, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憧)*/
	{.bitmap_index = 338115, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憨)*/
	{.bitmap_index = 338253, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憩)*/
	{.bitmap_index = 338391, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憬)*/
	{.bitmap_index = 338529, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憷)*/
	{.bitmap_index = 338667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(憾)*/
	{.bitmap_index = 338805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懂)*/
	{.bitmap_index = 338943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懈)*/
	{.bitmap_index = 339081, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(懊)*/
	{.bitmap_index = 339225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懋)*/
	{.bitmap_index = 339363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懑)*/
	{.bitmap_index = 339501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懒)*/
	{.bitmap_index = 339639, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懔)*/
	{.bitmap_index = 339777, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懦)*/
	{.bitmap_index = 339915, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(懵)*/
	{.bitmap_index = 340053, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(懿)*/
	{.bitmap_index = 340191, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(戆)*/
	{.bitmap_index = 340329, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(戈)*/
	{.bitmap_index = 340467, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戊)*/
	{.bitmap_index = 340605, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(戋)*/
	{.bitmap_index = 340743, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(戌)*/
	{.bitmap_index = 340887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戍)*/
	{.bitmap_index = 341025, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(戎)*/
	{.bitmap_index = 341169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戏)*/
	{.bitmap_index = 341307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(成)*/
	{.bitmap_index = 341445, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(我)*/
	{.bitmap_index = 341589, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(戒)*/
	{.bitmap_index = 341733, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戕)*/
	{.bitmap_index = 341871, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(或)*/
	{.bitmap_index = 342015, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戗)*/
	{.bitmap_index = 342159, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(战)*/
	{.bitmap_index = 342297, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戚)*/
	{.bitmap_index = 342435, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(戛)*/
	{.bitmap_index = 342573, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(戟)*/
	{.bitmap_index = 342711, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戡)*/
	{.bitmap_index = 342849, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(戢)*/
	{.bitmap_index = 342993, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戤)*/
	{.bitmap_index = 343131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戥)*/
	{.bitmap_index = 343269, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(截)*/
	{.bitmap_index = 343407, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(戬)*/
	{.bitmap_index = 343545, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(戮)*/
	{.bitmap_index = 343689, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(戳)*/
	{.bitmap_index = 343827, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(戴)*/
	{.bitmap_index = 343971, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(户)*/
	{.bitmap_index = 344115, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(戽)*/
	{.bitmap_index = 344259, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(戾)*/
	{.bitmap_index = 344403, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(房)*/
	{.bitmap_index = 344547, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(所)*/
	{.bitmap_index = 344691, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扁)*/
	{.bitmap_index = 344829, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扃)*/
	{.bitmap_index = 344967, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扇)*/
	{.bitmap_index = 345111, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扈)*/
	{.bitmap_index = 345255, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扉)*/
	{.bitmap_index = 345393, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(手)*/
	{.bitmap_index = 345531, .adv_w = 17, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(扌)*/
	{.bitmap_index = 345623, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(才)*/
	{.bitmap_index = 345761, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扎)*/
	{.bitmap_index = 345899, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扑)*/
	{.bitmap_index = 346037, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扒)*/
	{.bitmap_index = 346175, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(打)*/
	{.bitmap_index = 346313, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扔)*/
	{.bitmap_index = 346457, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(托)*/
	{.bitmap_index = 346595, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扛)*/
	{.bitmap_index = 346733, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扣)*/
	{.bitmap_index = 346871, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扦)*/
	{.bitmap_index = 347003, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(执)*/
	{.bitmap_index = 347141, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扩)*/
	{.bitmap_index = 347285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扪)*/
	{.bitmap_index = 347423, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扫)*/
	{.bitmap_index = 347561, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扬)*/
	{.bitmap_index = 347699, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扭)*/
	{.bitmap_index = 347837, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扮)*/
	{.bitmap_index = 347981, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扯)*/
	{.bitmap_index = 348119, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(扰)*/
	{.bitmap_index = 348257, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扳)*/
	{.bitmap_index = 348401, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扶)*/
	{.bitmap_index = 348545, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(批)*/
	{.bitmap_index = 348683, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(扼)*/
	{.bitmap_index = 348827, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(找)*/
	{.bitmap_index = 348965, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(承)*/
	{.bitmap_index = 349103, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(技)*/
	{.bitmap_index = 349247, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抄)*/
	{.bitmap_index = 349391, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抉)*/
	{.bitmap_index = 349535, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(把)*/
	{.bitmap_index = 349673, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抑)*/
	{.bitmap_index = 349811, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抒)*/
	{.bitmap_index = 349949, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抓)*/
	{.bitmap_index = 350087, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(投)*/
	{.bitmap_index = 350231, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抖)*/
	{.bitmap_index = 350369, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抗)*/
	{.bitmap_index = 350513, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(折)*/
	{.bitmap_index = 350657, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抚)*/
	{.bitmap_index = 350801, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抛)*/
	{.bitmap_index = 350939, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抟)*/
	{.bitmap_index = 351083, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抠)*/
	{.bitmap_index = 351221, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抡)*/
	{.bitmap_index = 351359, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抢)*/
	{.bitmap_index = 351497, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(护)*/
	{.bitmap_index = 351641, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(报)*/
	{.bitmap_index = 351785, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抨)*/
	{.bitmap_index = 351923, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(披)*/
	{.bitmap_index = 352067, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抬)*/
	{.bitmap_index = 352205, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抱)*/
	{.bitmap_index = 352343, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抵)*/
	{.bitmap_index = 352487, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抹)*/
	{.bitmap_index = 352625, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抻)*/
	{.bitmap_index = 352763, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(押)*/
	{.bitmap_index = 352901, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(抽)*/
	{.bitmap_index = 353039, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(抿)*/
	{.bitmap_index = 353183, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拂)*/
	{.bitmap_index = 353327, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拄)*/
	{.bitmap_index = 353465, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(担)*/
	{.bitmap_index = 353603, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拆)*/
	{.bitmap_index = 353747, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拇)*/
	{.bitmap_index = 353885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拈)*/
	{.bitmap_index = 354023, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拉)*/
	{.bitmap_index = 354161, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拊)*/
	{.bitmap_index = 354299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拌)*/
	{.bitmap_index = 354437, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拍)*/
	{.bitmap_index = 354575, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拎)*/
	{.bitmap_index = 354719, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拐)*/
	{.bitmap_index = 354863, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拒)*/
	{.bitmap_index = 355001, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拓)*/
	{.bitmap_index = 355139, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拔)*/
	{.bitmap_index = 355283, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拖)*/
	{.bitmap_index = 355421, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拗)*/
	{.bitmap_index = 355559, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拘)*/
	{.bitmap_index = 355697, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拙)*/
	{.bitmap_index = 355835, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拚)*/
	{.bitmap_index = 355985, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(招)*/
	{.bitmap_index = 356123, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(拜)*/
	{.bitmap_index = 356267, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拟)*/
	{.bitmap_index = 356411, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拢)*/
	{.bitmap_index = 356549, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拣)*/
	{.bitmap_index = 356687, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拥)*/
	{.bitmap_index = 356825, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拦)*/
	{.bitmap_index = 356963, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拧)*/
	{.bitmap_index = 357101, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拨)*/
	{.bitmap_index = 357245, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(择)*/
	{.bitmap_index = 357383, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(括)*/
	{.bitmap_index = 357521, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拭)*/
	{.bitmap_index = 357659, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拮)*/
	{.bitmap_index = 357797, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拯)*/
	{.bitmap_index = 357935, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拱)*/
	{.bitmap_index = 358073, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拳)*/
	{.bitmap_index = 358211, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拴)*/
	{.bitmap_index = 358349, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拶)*/
	{.bitmap_index = 358493, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拷)*/
	{.bitmap_index = 358631, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(拼)*/
	{.bitmap_index = 358775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拽)*/
	{.bitmap_index = 358913, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拾)*/
	{.bitmap_index = 359051, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(拿)*/
	{.bitmap_index = 359189, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(持)*/
	{.bitmap_index = 359327, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挂)*/
	{.bitmap_index = 359465, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(指)*/
	{.bitmap_index = 359603, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挈)*/
	{.bitmap_index = 359741, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(按)*/
	{.bitmap_index = 359885, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挎)*/
	{.bitmap_index = 360023, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(挑)*/
	{.bitmap_index = 360167, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挖)*/
	{.bitmap_index = 360305, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挚)*/
	{.bitmap_index = 360443, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挛)*/
	{.bitmap_index = 360581, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挝)*/
	{.bitmap_index = 360719, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挞)*/
	{.bitmap_index = 360857, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(挟)*/
	{.bitmap_index = 361001, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(挠)*/
	{.bitmap_index = 361145, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挡)*/
	{.bitmap_index = 361283, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(挢)*/
	{.bitmap_index = 361427, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挣)*/
	{.bitmap_index = 361565, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(挤)*/
	{.bitmap_index = 361709, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挥)*/
	{.bitmap_index = 361847, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(挨)*/
	{.bitmap_index = 361997, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挪)*/
	{.bitmap_index = 362135, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挫)*/
	{.bitmap_index = 362273, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(振)*/
	{.bitmap_index = 362417, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(挲)*/
	{.bitmap_index = 362555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挹)*/
	{.bitmap_index = 362693, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挺)*/
	{.bitmap_index = 362831, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(挽)*/
	{.bitmap_index = 362969, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捂)*/
	{.bitmap_index = 363107, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捃)*/
	{.bitmap_index = 363245, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捅)*/
	{.bitmap_index = 363383, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捆)*/
	{.bitmap_index = 363521, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(捉)*/
	{.bitmap_index = 363665, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捋)*/
	{.bitmap_index = 363803, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捌)*/
	{.bitmap_index = 363941, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捍)*/
	{.bitmap_index = 364079, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(捎)*/
	{.bitmap_index = 364217, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捏)*/
	{.bitmap_index = 364355, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捐)*/
	{.bitmap_index = 364493, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捕)*/
	{.bitmap_index = 364631, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(捞)*/
	{.bitmap_index = 364775, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(损)*/
	{.bitmap_index = 364919, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捡)*/
	{.bitmap_index = 365057, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(换)*/
	{.bitmap_index = 365201, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捣)*/
	{.bitmap_index = 365339, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(捧)*/
	{.bitmap_index = 365483, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(捩)*/
	{.bitmap_index = 365627, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捭)*/
	{.bitmap_index = 365765, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(据)*/
	{.bitmap_index = 365903, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(捱)*/
	{.bitmap_index = 366047, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捶)*/
	{.bitmap_index = 366185, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(捷)*/
	{.bitmap_index = 366329, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捺)*/
	{.bitmap_index = 366467, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(捻)*/
	{.bitmap_index = 366605, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(掀)*/
	{.bitmap_index = 366749, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掂)*/
	{.bitmap_index = 366887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掇)*/
	{.bitmap_index = 367025, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(授)*/
	{.bitmap_index = 367169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掉)*/
	{.bitmap_index = 367307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掊)*/
	{.bitmap_index = 367445, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(掌)*/
	{.bitmap_index = 367583, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掎)*/
	{.bitmap_index = 367721, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(掏)*/
	{.bitmap_index = 367865, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掐)*/
	{.bitmap_index = 368003, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(排)*/
	{.bitmap_index = 368141, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掖)*/
	{.bitmap_index = 368279, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掘)*/
	{.bitmap_index = 368417, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掠)*/
	{.bitmap_index = 368555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(探)*/
	{.bitmap_index = 368693, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(掣)*/
	{.bitmap_index = 368837, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(接)*/
	{.bitmap_index = 368981, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(控)*/
	{.bitmap_index = 369119, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(推)*/
	{.bitmap_index = 369257, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掩)*/
	{.bitmap_index = 369395, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(措)*/
	{.bitmap_index = 369533, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(掬)*/
	{.bitmap_index = 369677, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掭)*/
	{.bitmap_index = 369815, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掮)*/
	{.bitmap_index = 369953, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(掰)*/
	{.bitmap_index = 370097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(掳)*/
	{.bitmap_index = 370241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掴)*/
	{.bitmap_index = 370379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掷)*/
	{.bitmap_index = 370517, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掸)*/
	{.bitmap_index = 370655, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(掺)*/
	{.bitmap_index = 370799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(掼)*/
	{.bitmap_index = 370943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(掾)*/
	{.bitmap_index = 371081, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揄)*/
	{.bitmap_index = 371219, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(揆)*/
	{.bitmap_index = 371363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揉)*/
	{.bitmap_index = 371501, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(揍)*/
	{.bitmap_index = 371645, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揎)*/
	{.bitmap_index = 371783, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(描)*/
	{.bitmap_index = 371921, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(提)*/
	{.bitmap_index = 372065, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(插)*/
	{.bitmap_index = 372203, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(揖)*/
	{.bitmap_index = 372341, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揞)*/
	{.bitmap_index = 372479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揠)*/
	{.bitmap_index = 372617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(握)*/
	{.bitmap_index = 372755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揣)*/
	{.bitmap_index = 372893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揩)*/
	{.bitmap_index = 373031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揪)*/
	{.bitmap_index = 373169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揭)*/
	{.bitmap_index = 373307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揲)*/
	{.bitmap_index = 373445, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(援)*/
	{.bitmap_index = 373589, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揶)*/
	{.bitmap_index = 373727, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(揸)*/
	{.bitmap_index = 373865, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(揽)*/
	{.bitmap_index = 374009, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(揿)*/
	{.bitmap_index = 374153, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搀)*/
	{.bitmap_index = 374297, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搁)*/
	{.bitmap_index = 374435, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搂)*/
	{.bitmap_index = 374579, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搅)*/
	{.bitmap_index = 374723, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搋)*/
	{.bitmap_index = 374861, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搌)*/
	{.bitmap_index = 375005, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搏)*/
	{.bitmap_index = 375143, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搐)*/
	{.bitmap_index = 375281, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搓)*/
	{.bitmap_index = 375419, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搔)*/
	{.bitmap_index = 375557, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搛)*/
	{.bitmap_index = 375701, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搜)*/
	{.bitmap_index = 375845, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搞)*/
	{.bitmap_index = 375983, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搠)*/
	{.bitmap_index = 376127, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搡)*/
	{.bitmap_index = 376265, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搦)*/
	{.bitmap_index = 376403, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搪)*/
	{.bitmap_index = 376541, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(搬)*/
	{.bitmap_index = 376685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搭)*/
	{.bitmap_index = 376823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搴)*/
	{.bitmap_index = 376961, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(携)*/
	{.bitmap_index = 377105, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搽)*/
	{.bitmap_index = 377243, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(搿)*/
	{.bitmap_index = 377381, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摁)*/
	{.bitmap_index = 377519, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(摄)*/
	{.bitmap_index = 377663, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摅)*/
	{.bitmap_index = 377801, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摆)*/
	{.bitmap_index = 377939, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摇)*/
	{.bitmap_index = 378077, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(摈)*/
	{.bitmap_index = 378221, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摊)*/
	{.bitmap_index = 378359, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(摒)*/
	{.bitmap_index = 378503, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摔)*/
	{.bitmap_index = 378641, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摘)*/
	{.bitmap_index = 378779, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摞)*/
	{.bitmap_index = 378917, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摧)*/
	{.bitmap_index = 379055, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(摩)*/
	{.bitmap_index = 379199, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摭)*/
	{.bitmap_index = 379337, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(摸)*/
	{.bitmap_index = 379481, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摹)*/
	{.bitmap_index = 379619, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(摺)*/
	{.bitmap_index = 379757, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撂)*/
	{.bitmap_index = 379895, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撄)*/
	{.bitmap_index = 380039, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撅)*/
	{.bitmap_index = 380183, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撇)*/
	{.bitmap_index = 380327, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撑)*/
	{.bitmap_index = 380465, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撒)*/
	{.bitmap_index = 380609, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撕)*/
	{.bitmap_index = 380753, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撖)*/
	{.bitmap_index = 380891, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撙)*/
	{.bitmap_index = 381035, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撞)*/
	{.bitmap_index = 381173, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撤)*/
	{.bitmap_index = 381317, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撩)*/
	{.bitmap_index = 381455, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撬)*/
	{.bitmap_index = 381593, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(播)*/
	{.bitmap_index = 381731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撮)*/
	{.bitmap_index = 381869, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(撰)*/
	{.bitmap_index = 382013, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撵)*/
	{.bitmap_index = 382151, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(撷)*/
	{.bitmap_index = 382295, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撸)*/
	{.bitmap_index = 382439, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撺)*/
	{.bitmap_index = 382577, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(撼)*/
	{.bitmap_index = 382715, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擀)*/
	{.bitmap_index = 382853, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擂)*/
	{.bitmap_index = 382991, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擅)*/
	{.bitmap_index = 383129, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(操)*/
	{.bitmap_index = 383267, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(擎)*/
	{.bitmap_index = 383411, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(擐)*/
	{.bitmap_index = 383555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擒)*/
	{.bitmap_index = 383693, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擗)*/
	{.bitmap_index = 383831, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擘)*/
	{.bitmap_index = 383969, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(擞)*/
	{.bitmap_index = 384113, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擢)*/
	{.bitmap_index = 384251, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(擤)*/
	{.bitmap_index = 384395, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(擦)*/
	{.bitmap_index = 384533, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(攀)*/
	{.bitmap_index = 384671, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(攉)*/
	{.bitmap_index = 384809, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(攒)*/
	{.bitmap_index = 384953, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(攘)*/
	{.bitmap_index = 385097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(攥)*/
	{.bitmap_index = 385241, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(攫)*/
	{.bitmap_index = 385385, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(攮)*/
	{.bitmap_index = 385529, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(支)*/
	{.bitmap_index = 385673, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(攴)*/
	{.bitmap_index = 385817, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(攵)*/
	{.bitmap_index = 385961, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(收)*/
	{.bitmap_index = 386105, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(攸)*/
	{.bitmap_index = 386243, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(改)*/
	{.bitmap_index = 386387, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(攻)*/
	{.bitmap_index = 386531, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(放)*/
	{.bitmap_index = 386675, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(政)*/
	{.bitmap_index = 386819, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(故)*/
	{.bitmap_index = 386963, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(效)*/
	{.bitmap_index = 387107, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敉)*/
	{.bitmap_index = 387251, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(敌)*/
	{.bitmap_index = 387395, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敏)*/
	{.bitmap_index = 387539, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(救)*/
	{.bitmap_index = 387683, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敕)*/
	{.bitmap_index = 387827, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敖)*/
	{.bitmap_index = 387971, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(教)*/
	{.bitmap_index = 388115, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敛)*/
	{.bitmap_index = 388259, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(敝)*/
	{.bitmap_index = 388403, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(敞)*/
	{.bitmap_index = 388547, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(敢)*/
	{.bitmap_index = 388691, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(散)*/
	{.bitmap_index = 388835, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(敦)*/
	{.bitmap_index = 388979, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敫)*/
	{.bitmap_index = 389123, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敬)*/
	{.bitmap_index = 389267, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(数)*/
	{.bitmap_index = 389411, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(敲)*/
	{.bitmap_index = 389555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(整)*/
	{.bitmap_index = 389693, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(敷)*/
	{.bitmap_index = 389837, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(文)*/
	{.bitmap_index = 389981, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(斋)*/
	{.bitmap_index = 390119, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(斌)*/
	{.bitmap_index = 390257, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(斐)*/
	{.bitmap_index = 390401, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(斑)*/
	{.bitmap_index = 390539, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(斓)*/
	{.bitmap_index = 390677, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(斗)*/
	{.bitmap_index = 390815, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(料)*/
	{.bitmap_index = 390953, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(斛)*/
	{.bitmap_index = 391097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(斜)*/
	{.bitmap_index = 391241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(斟)*/
	{.bitmap_index = 391379, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(斡)*/
	{.bitmap_index = 391517, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(斤)*/
	{.bitmap_index = 391655, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(斥)*/
	{.bitmap_index = 391799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(斧)*/
	{.bitmap_index = 391943, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(斩)*/
	{.bitmap_index = 392087, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(斫)*/
	{.bitmap_index = 392231, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(断)*/
	{.bitmap_index = 392375, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(斯)*/
	{.bitmap_index = 392519, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(新)*/
	{.bitmap_index = 392663, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(方)*/
	{.bitmap_index = 392807, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(於)*/
	{.bitmap_index = 392945, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(施)*/
	{.bitmap_index = 393083, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(旁)*/
	{.bitmap_index = 393227, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(旃)*/
	{.bitmap_index = 393371, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(旄)*/
	{.bitmap_index = 393515, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旅)*/
	{.bitmap_index = 393653, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旆)*/
	{.bitmap_index = 393791, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旋)*/
	{.bitmap_index = 393929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旌)*/
	{.bitmap_index = 394067, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旎)*/
	{.bitmap_index = 394211, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(族)*/
	{.bitmap_index = 394355, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(旒)*/
	{.bitmap_index = 394505, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旖)*/
	{.bitmap_index = 394649, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(旗)*/
	{.bitmap_index = 394793, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(无)*/
	{.bitmap_index = 394931, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(既)*/
	{.bitmap_index = 395063, .adv_w = 23, .box_h = 21, .box_w = 20, .ofs_x = 3, .ofs_y = 6},/*(日)*/
	{.bitmap_index = 395168, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(旦)*/
	{.bitmap_index = 395300, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(旧)*/
	{.bitmap_index = 395410, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(旨)*/
	{.bitmap_index = 395525, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(早)*/
	{.bitmap_index = 395657, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旬)*/
	{.bitmap_index = 395795, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(旭)*/
	{.bitmap_index = 395939, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(旮)*/
	{.bitmap_index = 396077, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(旯)*/
	{.bitmap_index = 396215, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(旰)*/
	{.bitmap_index = 396347, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(旱)*/
	{.bitmap_index = 396479, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(时)*/
	{.bitmap_index = 396617, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(旷)*/
	{.bitmap_index = 396761, .adv_w = 26, .box_h = 21, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(旺)*/
	{.bitmap_index = 396887, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(昀)*/
	{.bitmap_index = 397002, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昂)*/
	{.bitmap_index = 397140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(昃)*/
	{.bitmap_index = 397278, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(昆)*/
	{.bitmap_index = 397410, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(昊)*/
	{.bitmap_index = 397548, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(昌)*/
	{.bitmap_index = 397658, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(明)*/
	{.bitmap_index = 397773, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(昏)*/
	{.bitmap_index = 397911, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(易)*/
	{.bitmap_index = 398049, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昔)*/
	{.bitmap_index = 398187, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(昕)*/
	{.bitmap_index = 398331, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昙)*/
	{.bitmap_index = 398463, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(昝)*/
	{.bitmap_index = 398601, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(星)*/
	{.bitmap_index = 398733, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(映)*/
	{.bitmap_index = 398877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(春)*/
	{.bitmap_index = 399015, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昧)*/
	{.bitmap_index = 399153, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昨)*/
	{.bitmap_index = 399291, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昭)*/
	{.bitmap_index = 399423, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(是)*/
	{.bitmap_index = 399561, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(昱)*/
	{.bitmap_index = 399693, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(昴)*/
	{.bitmap_index = 399831, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(昵)*/
	{.bitmap_index = 399963, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(昶)*/
	{.bitmap_index = 400113, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(昼)*/
	{.bitmap_index = 400239, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(显)*/
	{.bitmap_index = 400371, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(晁)*/
	{.bitmap_index = 400509, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(晃)*/
	{.bitmap_index = 400647, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晋)*/
	{.bitmap_index = 400779, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晌)*/
	{.bitmap_index = 400917, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(晏)*/
	{.bitmap_index = 401061, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(晒)*/
	{.bitmap_index = 401187, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(晓)*/
	{.bitmap_index = 401331, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晔)*/
	{.bitmap_index = 401469, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晕)*/
	{.bitmap_index = 401601, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(晖)*/
	{.bitmap_index = 401733, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晗)*/
	{.bitmap_index = 401871, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(晚)*/
	{.bitmap_index = 402015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(晟)*/
	{.bitmap_index = 402153, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(晡)*/
	{.bitmap_index = 402291, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(晤)*/
	{.bitmap_index = 402423, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晦)*/
	{.bitmap_index = 402561, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(晨)*/
	{.bitmap_index = 402699, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(普)*/
	{.bitmap_index = 402843, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(景)*/
	{.bitmap_index = 402975, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晰)*/
	{.bitmap_index = 403113, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(晴)*/
	{.bitmap_index = 403251, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(晶)*/
	{.bitmap_index = 403361, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(晷)*/
	{.bitmap_index = 403493, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(智)*/
	{.bitmap_index = 403637, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(晾)*/
	{.bitmap_index = 403775, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(暂)*/
	{.bitmap_index = 403913, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(暄)*/
	{.bitmap_index = 404051, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(暇)*/
	{.bitmap_index = 404189, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(暌)*/
	{.bitmap_index = 404333, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(暑)*/
	{.bitmap_index = 404465, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(暖)*/
	{.bitmap_index = 404609, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(暗)*/
	{.bitmap_index = 404747, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(暝)*/
	{.bitmap_index = 404885, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(暧)*/
	{.bitmap_index = 405029, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(暨)*/
	{.bitmap_index = 405167, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(暮)*/
	{.bitmap_index = 405305, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(暴)*/
	{.bitmap_index = 405443, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(暹)*/
	{.bitmap_index = 405581, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(暾)*/
	{.bitmap_index = 405725, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(曙)*/
	{.bitmap_index = 405857, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(曛)*/
	{.bitmap_index = 406001, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(曜)*/
	{.bitmap_index = 406133, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(曝)*/
	{.bitmap_index = 406265, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(曦)*/
	{.bitmap_index = 406409, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(曩)*/
	{.bitmap_index = 406547, .adv_w = 22, .box_h = 20, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(曰)*/
	{.bitmap_index = 406647, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(曲)*/
	{.bitmap_index = 406762, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(曳)*/
	{.bitmap_index = 406906, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(更)*/
	{.bitmap_index = 407044, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(曷)*/
	{.bitmap_index = 407176, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(曹)*/
	{.bitmap_index = 407314, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(曼)*/
	{.bitmap_index = 407452, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(曾)*/
	{.bitmap_index = 407567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(替)*/
	{.bitmap_index = 407705, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(最)*/
	{.bitmap_index = 407849, .adv_w = 21, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = 4},/*(月)*/
	{.bitmap_index = 407964, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(有)*/
	{.bitmap_index = 408102, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朊)*/
	{.bitmap_index = 408234, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朋)*/
	{.bitmap_index = 408366, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(服)*/
	{.bitmap_index = 408504, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(朐)*/
	{.bitmap_index = 408648, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(朔)*/
	{.bitmap_index = 408792, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(朕)*/
	{.bitmap_index = 408936, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(朗)*/
	{.bitmap_index = 409074, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(望)*/
	{.bitmap_index = 409212, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(朝)*/
	{.bitmap_index = 409356, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(期)*/
	{.bitmap_index = 409500, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朦)*/
	{.bitmap_index = 409638, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(木)*/
	{.bitmap_index = 409776, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(未)*/
	{.bitmap_index = 409914, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(末)*/
	{.bitmap_index = 410052, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(本)*/
	{.bitmap_index = 410190, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(札)*/
	{.bitmap_index = 410328, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(术)*/
	{.bitmap_index = 410466, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朱)*/
	{.bitmap_index = 410604, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朴)*/
	{.bitmap_index = 410742, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朵)*/
	{.bitmap_index = 410874, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(机)*/
	{.bitmap_index = 411012, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(朽)*/
	{.bitmap_index = 411150, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杀)*/
	{.bitmap_index = 411288, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(杂)*/
	{.bitmap_index = 411426, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(权)*/
	{.bitmap_index = 411570, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杆)*/
	{.bitmap_index = 411708, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杈)*/
	{.bitmap_index = 411846, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杉)*/
	{.bitmap_index = 411984, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杌)*/
	{.bitmap_index = 412122, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(李)*/
	{.bitmap_index = 412260, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杏)*/
	{.bitmap_index = 412398, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(材)*/
	{.bitmap_index = 412536, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(村)*/
	{.bitmap_index = 412674, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杓)*/
	{.bitmap_index = 412812, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(杖)*/
	{.bitmap_index = 412956, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杜)*/
	{.bitmap_index = 413094, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杞)*/
	{.bitmap_index = 413232, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(束)*/
	{.bitmap_index = 413370, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杠)*/
	{.bitmap_index = 413508, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(条)*/
	{.bitmap_index = 413646, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(来)*/
	{.bitmap_index = 413784, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杨)*/
	{.bitmap_index = 413922, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杩)*/
	{.bitmap_index = 414060, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(杪)*/
	{.bitmap_index = 414204, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杭)*/
	{.bitmap_index = 414342, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杯)*/
	{.bitmap_index = 414480, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(杰)*/
	{.bitmap_index = 414624, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杲)*/
	{.bitmap_index = 414756, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杳)*/
	{.bitmap_index = 414894, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杵)*/
	{.bitmap_index = 415032, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杷)*/
	{.bitmap_index = 415170, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(杼)*/
	{.bitmap_index = 415308, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(松)*/
	{.bitmap_index = 415446, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(板)*/
	{.bitmap_index = 415590, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(极)*/
	{.bitmap_index = 415728, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(构)*/
	{.bitmap_index = 415866, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枇)*/
	{.bitmap_index = 416004, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枉)*/
	{.bitmap_index = 416142, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枋)*/
	{.bitmap_index = 416280, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(析)*/
	{.bitmap_index = 416424, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枕)*/
	{.bitmap_index = 416562, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(林)*/
	{.bitmap_index = 416700, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枘)*/
	{.bitmap_index = 416838, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(枚)*/
	{.bitmap_index = 416982, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(果)*/
	{.bitmap_index = 417114, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(枝)*/
	{.bitmap_index = 417258, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枞)*/
	{.bitmap_index = 417396, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枢)*/
	{.bitmap_index = 417534, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(枣)*/
	{.bitmap_index = 417678, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枥)*/
	{.bitmap_index = 417816, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(枧)*/
	{.bitmap_index = 417960, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枨)*/
	{.bitmap_index = 418098, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枪)*/
	{.bitmap_index = 418236, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枫)*/
	{.bitmap_index = 418374, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枭)*/
	{.bitmap_index = 418518, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枯)*/
	{.bitmap_index = 418656, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枰)*/
	{.bitmap_index = 418794, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(枳)*/
	{.bitmap_index = 418938, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枵)*/
	{.bitmap_index = 419076, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(架)*/
	{.bitmap_index = 419214, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枷)*/
	{.bitmap_index = 419352, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(枸)*/
	{.bitmap_index = 419490, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柁)*/
	{.bitmap_index = 419628, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柃)*/
	{.bitmap_index = 419766, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柄)*/
	{.bitmap_index = 419904, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柏)*/
	{.bitmap_index = 420042, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(某)*/
	{.bitmap_index = 420180, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柑)*/
	{.bitmap_index = 420318, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柒)*/
	{.bitmap_index = 420456, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(染)*/
	{.bitmap_index = 420594, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柔)*/
	{.bitmap_index = 420726, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柘)*/
	{.bitmap_index = 420864, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柙)*/
	{.bitmap_index = 421002, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柚)*/
	{.bitmap_index = 421140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柜)*/
	{.bitmap_index = 421278, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(柝)*/
	{.bitmap_index = 421422, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柞)*/
	{.bitmap_index = 421560, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柠)*/
	{.bitmap_index = 421698, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(柢)*/
	{.bitmap_index = 421842, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(查)*/
	{.bitmap_index = 421980, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柩)*/
	{.bitmap_index = 422118, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柬)*/
	{.bitmap_index = 422256, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柯)*/
	{.bitmap_index = 422394, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柰)*/
	{.bitmap_index = 422532, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柱)*/
	{.bitmap_index = 422670, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(柳)*/
	{.bitmap_index = 422814, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柴)*/
	{.bitmap_index = 422952, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柽)*/
	{.bitmap_index = 423090, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(柿)*/
	{.bitmap_index = 423228, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栀)*/
	{.bitmap_index = 423366, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栅)*/
	{.bitmap_index = 423504, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(标)*/
	{.bitmap_index = 423648, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栈)*/
	{.bitmap_index = 423786, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栉)*/
	{.bitmap_index = 423924, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栊)*/
	{.bitmap_index = 424062, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栋)*/
	{.bitmap_index = 424200, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(栌)*/
	{.bitmap_index = 424344, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栎)*/
	{.bitmap_index = 424482, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栏)*/
	{.bitmap_index = 424620, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(树)*/
	{.bitmap_index = 424758, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栓)*/
	{.bitmap_index = 424896, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栖)*/
	{.bitmap_index = 425034, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栗)*/
	{.bitmap_index = 425166, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栝)*/
	{.bitmap_index = 425304, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(校)*/
	{.bitmap_index = 425448, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栩)*/
	{.bitmap_index = 425586, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(株)*/
	{.bitmap_index = 425724, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栲)*/
	{.bitmap_index = 425862, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栳)*/
	{.bitmap_index = 426000, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(样)*/
	{.bitmap_index = 426138, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(核)*/
	{.bitmap_index = 426282, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(根)*/
	{.bitmap_index = 426420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(格)*/
	{.bitmap_index = 426558, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(栽)*/
	{.bitmap_index = 426702, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(栾)*/
	{.bitmap_index = 426840, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桀)*/
	{.bitmap_index = 426978, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桁)*/
	{.bitmap_index = 427116, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桂)*/
	{.bitmap_index = 427254, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桃)*/
	{.bitmap_index = 427398, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桄)*/
	{.bitmap_index = 427542, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桅)*/
	{.bitmap_index = 427680, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(框)*/
	{.bitmap_index = 427818, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(案)*/
	{.bitmap_index = 427956, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桉)*/
	{.bitmap_index = 428094, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桊)*/
	{.bitmap_index = 428232, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桌)*/
	{.bitmap_index = 428370, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桎)*/
	{.bitmap_index = 428508, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桐)*/
	{.bitmap_index = 428646, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桑)*/
	{.bitmap_index = 428778, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桓)*/
	{.bitmap_index = 428916, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桔)*/
	{.bitmap_index = 429054, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桕)*/
	{.bitmap_index = 429192, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桠)*/
	{.bitmap_index = 429330, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桡)*/
	{.bitmap_index = 429474, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桢)*/
	{.bitmap_index = 429618, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(档)*/
	{.bitmap_index = 429756, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桤)*/
	{.bitmap_index = 429894, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桥)*/
	{.bitmap_index = 430038, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桦)*/
	{.bitmap_index = 430176, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桧)*/
	{.bitmap_index = 430314, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桨)*/
	{.bitmap_index = 430452, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桩)*/
	{.bitmap_index = 430596, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桫)*/
	{.bitmap_index = 430740, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桴)*/
	{.bitmap_index = 430878, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(桶)*/
	{.bitmap_index = 431016, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(桷)*/
	{.bitmap_index = 431160, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梁)*/
	{.bitmap_index = 431298, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梃)*/
	{.bitmap_index = 431436, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梅)*/
	{.bitmap_index = 431574, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(梆)*/
	{.bitmap_index = 431718, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梏)*/
	{.bitmap_index = 431856, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梓)*/
	{.bitmap_index = 431994, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(梗)*/
	{.bitmap_index = 432138, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梢)*/
	{.bitmap_index = 432276, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(梦)*/
	{.bitmap_index = 432420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梧)*/
	{.bitmap_index = 432558, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梨)*/
	{.bitmap_index = 432696, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(梭)*/
	{.bitmap_index = 432840, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(梯)*/
	{.bitmap_index = 432978, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(械)*/
	{.bitmap_index = 433116, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(梳)*/
	{.bitmap_index = 433260, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(梵)*/
	{.bitmap_index = 433404, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(检)*/
	{.bitmap_index = 433542, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(棂)*/
	{.bitmap_index = 433686, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棉)*/
	{.bitmap_index = 433824, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(棋)*/
	{.bitmap_index = 433968, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棍)*/
	{.bitmap_index = 434106, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(棒)*/
	{.bitmap_index = 434250, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(棕)*/
	{.bitmap_index = 434394, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棘)*/
	{.bitmap_index = 434532, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棚)*/
	{.bitmap_index = 434670, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棠)*/
	{.bitmap_index = 434808, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棣)*/
	{.bitmap_index = 434946, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(森)*/
	{.bitmap_index = 435084, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棰)*/
	{.bitmap_index = 435222, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(棱)*/
	{.bitmap_index = 435366, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棵)*/
	{.bitmap_index = 435504, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棹)*/
	{.bitmap_index = 435642, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(棺)*/
	{.bitmap_index = 435780, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(棼)*/
	{.bitmap_index = 435924, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椁)*/
	{.bitmap_index = 436062, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椅)*/
	{.bitmap_index = 436200, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椋)*/
	{.bitmap_index = 436338, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(植)*/
	{.bitmap_index = 436476, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椎)*/
	{.bitmap_index = 436614, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椐)*/
	{.bitmap_index = 436752, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椒)*/
	{.bitmap_index = 436890, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(椟)*/
	{.bitmap_index = 437034, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椠)*/
	{.bitmap_index = 437172, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(椤)*/
	{.bitmap_index = 437316, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椭)*/
	{.bitmap_index = 437454, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(椰)*/
	{.bitmap_index = 437598, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(椴)*/
	{.bitmap_index = 437742, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椹)*/
	{.bitmap_index = 437880, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椽)*/
	{.bitmap_index = 438018, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(椿)*/
	{.bitmap_index = 438156, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楂)*/
	{.bitmap_index = 438294, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(楔)*/
	{.bitmap_index = 438438, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楗)*/
	{.bitmap_index = 438576, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(楚)*/
	{.bitmap_index = 438720, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楝)*/
	{.bitmap_index = 438858, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(楞)*/
	{.bitmap_index = 439002, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楠)*/
	{.bitmap_index = 439140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楣)*/
	{.bitmap_index = 439278, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楦)*/
	{.bitmap_index = 439416, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楫)*/
	{.bitmap_index = 439554, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楮)*/
	{.bitmap_index = 439692, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(楱)*/
	{.bitmap_index = 439836, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楷)*/
	{.bitmap_index = 439974, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楸)*/
	{.bitmap_index = 440112, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(楹)*/
	{.bitmap_index = 440250, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(楼)*/
	{.bitmap_index = 440394, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榀)*/
	{.bitmap_index = 440532, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(概)*/
	{.bitmap_index = 440670, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榄)*/
	{.bitmap_index = 440808, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榆)*/
	{.bitmap_index = 440946, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(榇)*/
	{.bitmap_index = 441090, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榈)*/
	{.bitmap_index = 441228, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榉)*/
	{.bitmap_index = 441366, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榍)*/
	{.bitmap_index = 441504, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榔)*/
	{.bitmap_index = 441642, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榕)*/
	{.bitmap_index = 441780, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榘)*/
	{.bitmap_index = 441918, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榛)*/
	{.bitmap_index = 442056, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(榜)*/
	{.bitmap_index = 442200, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榧)*/
	{.bitmap_index = 442338, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榨)*/
	{.bitmap_index = 442476, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榫)*/
	{.bitmap_index = 442614, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榭)*/
	{.bitmap_index = 442752, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榱)*/
	{.bitmap_index = 442890, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榴)*/
	{.bitmap_index = 443028, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榷)*/
	{.bitmap_index = 443166, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(榻)*/
	{.bitmap_index = 443304, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槁)*/
	{.bitmap_index = 443442, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槊)*/
	{.bitmap_index = 443580, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槌)*/
	{.bitmap_index = 443718, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槎)*/
	{.bitmap_index = 443856, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(槐)*/
	{.bitmap_index = 444000, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槔)*/
	{.bitmap_index = 444138, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槛)*/
	{.bitmap_index = 444276, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(槟)*/
	{.bitmap_index = 444420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槠)*/
	{.bitmap_index = 444558, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槭)*/
	{.bitmap_index = 444696, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槲)*/
	{.bitmap_index = 444834, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槽)*/
	{.bitmap_index = 444972, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(槿)*/
	{.bitmap_index = 445110, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(樊)*/
	{.bitmap_index = 445254, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樗)*/
	{.bitmap_index = 445392, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樘)*/
	{.bitmap_index = 445530, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樟)*/
	{.bitmap_index = 445668, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(模)*/
	{.bitmap_index = 445812, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樨)*/
	{.bitmap_index = 445950, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(横)*/
	{.bitmap_index = 446094, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樯)*/
	{.bitmap_index = 446232, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(樱)*/
	{.bitmap_index = 446376, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樵)*/
	{.bitmap_index = 446514, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樽)*/
	{.bitmap_index = 446658, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(樾)*/
	{.bitmap_index = 446796, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橄)*/
	{.bitmap_index = 446934, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橇)*/
	{.bitmap_index = 447072, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(橐)*/
	{.bitmap_index = 447210, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橘)*/
	{.bitmap_index = 447348, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橙)*/
	{.bitmap_index = 447486, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(橛)*/
	{.bitmap_index = 447630, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橡)*/
	{.bitmap_index = 447774, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橥)*/
	{.bitmap_index = 447912, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橱)*/
	{.bitmap_index = 448050, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橹)*/
	{.bitmap_index = 448194, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(橼)*/
	{.bitmap_index = 448332, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檀)*/
	{.bitmap_index = 448470, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(檄)*/
	{.bitmap_index = 448614, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檎)*/
	{.bitmap_index = 448752, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檐)*/
	{.bitmap_index = 448896, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檑)*/
	{.bitmap_index = 449034, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檗)*/
	{.bitmap_index = 449172, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檠)*/
	{.bitmap_index = 449310, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檩)*/
	{.bitmap_index = 449448, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(檫)*/
	{.bitmap_index = 449586, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(檬)*/
	{.bitmap_index = 449730, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(欠)*/
	{.bitmap_index = 449874, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(次)*/
	{.bitmap_index = 450018, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(欢)*/
	{.bitmap_index = 450162, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(欣)*/
	{.bitmap_index = 450306, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(欤)*/
	{.bitmap_index = 450450, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(欧)*/
	{.bitmap_index = 450594, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(欲)*/
	{.bitmap_index = 450738, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(欷)*/
	{.bitmap_index = 450876, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(欹)*/
	{.bitmap_index = 451020, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(欺)*/
	{.bitmap_index = 451164, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(款)*/
	{.bitmap_index = 451308, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(歃)*/
	{.bitmap_index = 451446, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(歆)*/
	{.bitmap_index = 451590, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(歇)*/
	{.bitmap_index = 451734, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(歉)*/
	{.bitmap_index = 451878, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(歌)*/
	{.bitmap_index = 452016, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(歙)*/
	{.bitmap_index = 452160, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(止)*/
	{.bitmap_index = 452292, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(正)*/
	{.bitmap_index = 452418, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(此)*/
	{.bitmap_index = 452556, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(步)*/
	{.bitmap_index = 452700, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(武)*/
	{.bitmap_index = 452838, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(歧)*/
	{.bitmap_index = 452982, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(歪)*/
	{.bitmap_index = 453108, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(歹)*/
	{.bitmap_index = 453246, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(死)*/
	{.bitmap_index = 453384, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(歼)*/
	{.bitmap_index = 453528, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殁)*/
	{.bitmap_index = 453666, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(殂)*/
	{.bitmap_index = 453798, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殃)*/
	{.bitmap_index = 453942, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殄)*/
	{.bitmap_index = 454086, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殆)*/
	{.bitmap_index = 454230, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殇)*/
	{.bitmap_index = 454374, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殉)*/
	{.bitmap_index = 454518, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(殊)*/
	{.bitmap_index = 454656, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(残)*/
	{.bitmap_index = 454800, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殍)*/
	{.bitmap_index = 454944, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殒)*/
	{.bitmap_index = 455082, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(殓)*/
	{.bitmap_index = 455220, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(殖)*/
	{.bitmap_index = 455358, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(殚)*/
	{.bitmap_index = 455496, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殛)*/
	{.bitmap_index = 455634, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殡)*/
	{.bitmap_index = 455778, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殪)*/
	{.bitmap_index = 455922, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殳)*/
	{.bitmap_index = 456060, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(殴)*/
	{.bitmap_index = 456198, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(段)*/
	{.bitmap_index = 456342, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(殷)*/
	{.bitmap_index = 456486, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(殿)*/
	{.bitmap_index = 456618, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毁)*/
	{.bitmap_index = 456756, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毂)*/
	{.bitmap_index = 456894, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(毅)*/
	{.bitmap_index = 457038, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(毋)*/
	{.bitmap_index = 457176, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(母)*/
	{.bitmap_index = 457308, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(每)*/
	{.bitmap_index = 457446, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(毒)*/
	{.bitmap_index = 457590, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(毓)*/
	{.bitmap_index = 457734, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(比)*/
	{.bitmap_index = 457872, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毕)*/
	{.bitmap_index = 458010, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(毖)*/
	{.bitmap_index = 458148, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毗)*/
	{.bitmap_index = 458286, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(毙)*/
	{.bitmap_index = 458424, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毛)*/
	{.bitmap_index = 458562, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毡)*/
	{.bitmap_index = 458700, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(毪)*/
	{.bitmap_index = 458844, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毫)*/
	{.bitmap_index = 458982, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毯)*/
	{.bitmap_index = 459120, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(毳)*/
	{.bitmap_index = 459258, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(毵)*/
	{.bitmap_index = 459402, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(毹)*/
	{.bitmap_index = 459546, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(毽)*/
	{.bitmap_index = 459684, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(氅)*/
	{.bitmap_index = 459822, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(氆)*/
	{.bitmap_index = 459966, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(氇)*/
	{.bitmap_index = 460104, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(氍)*/
	{.bitmap_index = 460242, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(氏)*/
	{.bitmap_index = 460380, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(氐)*/
	{.bitmap_index = 460524, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(民)*/
	{.bitmap_index = 460662, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(氓)*/
	{.bitmap_index = 460806, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(气)*/
	{.bitmap_index = 460956, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氕)*/
	{.bitmap_index = 461100, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氖)*/
	{.bitmap_index = 461250, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氘)*/
	{.bitmap_index = 461394, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氙)*/
	{.bitmap_index = 461538, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氚)*/
	{.bitmap_index = 461682, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氛)*/
	{.bitmap_index = 461826, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氟)*/
	{.bitmap_index = 461970, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氡)*/
	{.bitmap_index = 462114, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氢)*/
	{.bitmap_index = 462264, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(氤)*/
	{.bitmap_index = 462402, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氦)*/
	{.bitmap_index = 462546, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氧)*/
	{.bitmap_index = 462696, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氨)*/
	{.bitmap_index = 462846, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(氩)*/
	{.bitmap_index = 462984, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氪)*/
	{.bitmap_index = 463128, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氮)*/
	{.bitmap_index = 463278, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(氯)*/
	{.bitmap_index = 463416, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氰)*/
	{.bitmap_index = 463560, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(氲)*/
	{.bitmap_index = 463704, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(水)*/
	{.bitmap_index = 463842, .adv_w = 13, .box_h = 23, .box_w = 12, .ofs_x = 1, .ofs_y = 5},/*(氵)*/
	{.bitmap_index = 463911, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(永)*/
	{.bitmap_index = 464061, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(氽)*/
	{.bitmap_index = 464199, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(汀)*/
	{.bitmap_index = 464337, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(汁)*/
	{.bitmap_index = 464475, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(求)*/
	{.bitmap_index = 464613, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汆)*/
	{.bitmap_index = 464751, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汇)*/
	{.bitmap_index = 464889, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(汉)*/
	{.bitmap_index = 465033, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(汊)*/
	{.bitmap_index = 465177, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(汐)*/
	{.bitmap_index = 465321, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(汔)*/
	{.bitmap_index = 465459, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汕)*/
	{.bitmap_index = 465597, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(汗)*/
	{.bitmap_index = 465735, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汛)*/
	{.bitmap_index = 465873, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(汜)*/
	{.bitmap_index = 466011, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(汝)*/
	{.bitmap_index = 466155, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(汞)*/
	{.bitmap_index = 466293, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(江)*/
	{.bitmap_index = 466431, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(池)*/
	{.bitmap_index = 466569, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(污)*/
	{.bitmap_index = 466707, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(汤)*/
	{.bitmap_index = 466851, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(汨)*/
	{.bitmap_index = 466989, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汩)*/
	{.bitmap_index = 467127, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汪)*/
	{.bitmap_index = 467265, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(汰)*/
	{.bitmap_index = 467409, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(汲)*/
	{.bitmap_index = 467553, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汴)*/
	{.bitmap_index = 467691, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(汶)*/
	{.bitmap_index = 467835, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(汹)*/
	{.bitmap_index = 467973, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(汽)*/
	{.bitmap_index = 468123, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(汾)*/
	{.bitmap_index = 468267, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沁)*/
	{.bitmap_index = 468405, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沂)*/
	{.bitmap_index = 468549, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沃)*/
	{.bitmap_index = 468693, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沅)*/
	{.bitmap_index = 468837, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沆)*/
	{.bitmap_index = 468975, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沈)*/
	{.bitmap_index = 469119, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沉)*/
	{.bitmap_index = 469263, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沌)*/
	{.bitmap_index = 469401, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沏)*/
	{.bitmap_index = 469545, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沐)*/
	{.bitmap_index = 469683, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沓)*/
	{.bitmap_index = 469821, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沔)*/
	{.bitmap_index = 469959, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沙)*/
	{.bitmap_index = 470103, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沛)*/
	{.bitmap_index = 470241, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沟)*/
	{.bitmap_index = 470379, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(没)*/
	{.bitmap_index = 470523, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沣)*/
	{.bitmap_index = 470661, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沤)*/
	{.bitmap_index = 470799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沥)*/
	{.bitmap_index = 470943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沦)*/
	{.bitmap_index = 471081, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沧)*/
	{.bitmap_index = 471219, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(沩)*/
	{.bitmap_index = 471357, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(沪)*/
	{.bitmap_index = 471501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沫)*/
	{.bitmap_index = 471639, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沭)*/
	{.bitmap_index = 471777, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沮)*/
	{.bitmap_index = 471915, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沱)*/
	{.bitmap_index = 472053, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沲)*/
	{.bitmap_index = 472191, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(河)*/
	{.bitmap_index = 472329, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(沸)*/
	{.bitmap_index = 472473, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(油)*/
	{.bitmap_index = 472611, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(治)*/
	{.bitmap_index = 472749, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沼)*/
	{.bitmap_index = 472887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沽)*/
	{.bitmap_index = 473025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沾)*/
	{.bitmap_index = 473163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(沿)*/
	{.bitmap_index = 473301, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泄)*/
	{.bitmap_index = 473439, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泅)*/
	{.bitmap_index = 473577, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泉)*/
	{.bitmap_index = 473715, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泊)*/
	{.bitmap_index = 473853, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泌)*/
	{.bitmap_index = 473991, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泐)*/
	{.bitmap_index = 474135, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泓)*/
	{.bitmap_index = 474273, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泔)*/
	{.bitmap_index = 474411, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(法)*/
	{.bitmap_index = 474555, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泖)*/
	{.bitmap_index = 474699, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泗)*/
	{.bitmap_index = 474837, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(泛)*/
	{.bitmap_index = 474975, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泞)*/
	{.bitmap_index = 475113, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泠)*/
	{.bitmap_index = 475257, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泡)*/
	{.bitmap_index = 475395, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(波)*/
	{.bitmap_index = 475539, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泣)*/
	{.bitmap_index = 475677, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泥)*/
	{.bitmap_index = 475821, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(注)*/
	{.bitmap_index = 475959, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泪)*/
	{.bitmap_index = 476097, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(泫)*/
	{.bitmap_index = 476235, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泮)*/
	{.bitmap_index = 476373, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泯)*/
	{.bitmap_index = 476517, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泰)*/
	{.bitmap_index = 476655, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泱)*/
	{.bitmap_index = 476799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泳)*/
	{.bitmap_index = 476943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泵)*/
	{.bitmap_index = 477081, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泶)*/
	{.bitmap_index = 477219, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泷)*/
	{.bitmap_index = 477357, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(泸)*/
	{.bitmap_index = 477501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泺)*/
	{.bitmap_index = 477639, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(泻)*/
	{.bitmap_index = 477777, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(泼)*/
	{.bitmap_index = 477921, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泽)*/
	{.bitmap_index = 478059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(泾)*/
	{.bitmap_index = 478197, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洁)*/
	{.bitmap_index = 478335, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洄)*/
	{.bitmap_index = 478473, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洇)*/
	{.bitmap_index = 478611, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洋)*/
	{.bitmap_index = 478749, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(洌)*/
	{.bitmap_index = 478893, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(洎)*/
	{.bitmap_index = 479031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洒)*/
	{.bitmap_index = 479169, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(洗)*/
	{.bitmap_index = 479313, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洙)*/
	{.bitmap_index = 479451, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洚)*/
	{.bitmap_index = 479595, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洛)*/
	{.bitmap_index = 479739, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洞)*/
	{.bitmap_index = 479877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(津)*/
	{.bitmap_index = 480015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洧)*/
	{.bitmap_index = 480153, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洪)*/
	{.bitmap_index = 480291, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洫)*/
	{.bitmap_index = 480429, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洮)*/
	{.bitmap_index = 480567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洱)*/
	{.bitmap_index = 480705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(洲)*/
	{.bitmap_index = 480849, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(洳)*/
	{.bitmap_index = 480993, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洵)*/
	{.bitmap_index = 481131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洹)*/
	{.bitmap_index = 481269, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(活)*/
	{.bitmap_index = 481407, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洼)*/
	{.bitmap_index = 481545, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(洽)*/
	{.bitmap_index = 481683, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(派)*/
	{.bitmap_index = 481821, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(流)*/
	{.bitmap_index = 481965, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(浃)*/
	{.bitmap_index = 482109, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浅)*/
	{.bitmap_index = 482247, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浆)*/
	{.bitmap_index = 482397, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浇)*/
	{.bitmap_index = 482541, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浈)*/
	{.bitmap_index = 482685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浊)*/
	{.bitmap_index = 482823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(测)*/
	{.bitmap_index = 482961, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浍)*/
	{.bitmap_index = 483099, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(济)*/
	{.bitmap_index = 483243, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浏)*/
	{.bitmap_index = 483381, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浑)*/
	{.bitmap_index = 483519, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浒)*/
	{.bitmap_index = 483657, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浓)*/
	{.bitmap_index = 483795, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浔)*/
	{.bitmap_index = 483933, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浙)*/
	{.bitmap_index = 484077, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浚)*/
	{.bitmap_index = 484221, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浜)*/
	{.bitmap_index = 484365, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浞)*/
	{.bitmap_index = 484509, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浠)*/
	{.bitmap_index = 484647, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浣)*/
	{.bitmap_index = 484791, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浦)*/
	{.bitmap_index = 484929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浩)*/
	{.bitmap_index = 485067, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浪)*/
	{.bitmap_index = 485211, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浮)*/
	{.bitmap_index = 485349, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浯)*/
	{.bitmap_index = 485487, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(浴)*/
	{.bitmap_index = 485625, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(海)*/
	{.bitmap_index = 485763, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浸)*/
	{.bitmap_index = 485907, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(浼)*/
	{.bitmap_index = 486051, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涂)*/
	{.bitmap_index = 486189, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涅)*/
	{.bitmap_index = 486327, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(消)*/
	{.bitmap_index = 486465, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(涉)*/
	{.bitmap_index = 486609, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涌)*/
	{.bitmap_index = 486747, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涎)*/
	{.bitmap_index = 486885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涑)*/
	{.bitmap_index = 487023, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涓)*/
	{.bitmap_index = 487161, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(涔)*/
	{.bitmap_index = 487305, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涕)*/
	{.bitmap_index = 487449, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涛)*/
	{.bitmap_index = 487587, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(涝)*/
	{.bitmap_index = 487731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涞)*/
	{.bitmap_index = 487869, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涟)*/
	{.bitmap_index = 488007, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涠)*/
	{.bitmap_index = 488145, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涡)*/
	{.bitmap_index = 488283, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(涣)*/
	{.bitmap_index = 488427, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涤)*/
	{.bitmap_index = 488565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(润)*/
	{.bitmap_index = 488703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涧)*/
	{.bitmap_index = 488841, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涨)*/
	{.bitmap_index = 488979, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涩)*/
	{.bitmap_index = 489117, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涪)*/
	{.bitmap_index = 489255, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涫)*/
	{.bitmap_index = 489393, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涮)*/
	{.bitmap_index = 489531, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涯)*/
	{.bitmap_index = 489669, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(液)*/
	{.bitmap_index = 489813, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涵)*/
	{.bitmap_index = 489951, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涸)*/
	{.bitmap_index = 490089, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(涿)*/
	{.bitmap_index = 490227, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淀)*/
	{.bitmap_index = 490365, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淄)*/
	{.bitmap_index = 490503, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淅)*/
	{.bitmap_index = 490647, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淆)*/
	{.bitmap_index = 490785, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淇)*/
	{.bitmap_index = 490929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淋)*/
	{.bitmap_index = 491067, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淌)*/
	{.bitmap_index = 491205, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淑)*/
	{.bitmap_index = 491349, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淖)*/
	{.bitmap_index = 491487, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(淘)*/
	{.bitmap_index = 491625, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淙)*/
	{.bitmap_index = 491769, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淝)*/
	{.bitmap_index = 491913, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淞)*/
	{.bitmap_index = 492051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淠)*/
	{.bitmap_index = 492195, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(淡)*/
	{.bitmap_index = 492339, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淤)*/
	{.bitmap_index = 492477, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淦)*/
	{.bitmap_index = 492615, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淫)*/
	{.bitmap_index = 492753, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淬)*/
	{.bitmap_index = 492891, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淮)*/
	{.bitmap_index = 493029, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(深)*/
	{.bitmap_index = 493161, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淳)*/
	{.bitmap_index = 493299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(混)*/
	{.bitmap_index = 493437, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淹)*/
	{.bitmap_index = 493575, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(添)*/
	{.bitmap_index = 493713, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(淼)*/
	{.bitmap_index = 493851, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(清)*/
	{.bitmap_index = 493989, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渊)*/
	{.bitmap_index = 494133, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渌)*/
	{.bitmap_index = 494271, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渍)*/
	{.bitmap_index = 494415, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渎)*/
	{.bitmap_index = 494559, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渐)*/
	{.bitmap_index = 494697, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渑)*/
	{.bitmap_index = 494835, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渔)*/
	{.bitmap_index = 494973, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渖)*/
	{.bitmap_index = 495111, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渗)*/
	{.bitmap_index = 495261, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(渚)*/
	{.bitmap_index = 495399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渝)*/
	{.bitmap_index = 495537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渠)*/
	{.bitmap_index = 495675, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渡)*/
	{.bitmap_index = 495819, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渣)*/
	{.bitmap_index = 495957, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渤)*/
	{.bitmap_index = 496095, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渥)*/
	{.bitmap_index = 496239, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(温)*/
	{.bitmap_index = 496377, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(渫)*/
	{.bitmap_index = 496515, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渭)*/
	{.bitmap_index = 496653, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(港)*/
	{.bitmap_index = 496791, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渲)*/
	{.bitmap_index = 496929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(渴)*/
	{.bitmap_index = 497067, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(游)*/
	{.bitmap_index = 497211, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(渺)*/
	{.bitmap_index = 497355, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(湃)*/
	{.bitmap_index = 497499, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湄)*/
	{.bitmap_index = 497637, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湍)*/
	{.bitmap_index = 497775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湎)*/
	{.bitmap_index = 497913, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湓)*/
	{.bitmap_index = 498051, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湔)*/
	{.bitmap_index = 498189, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(湖)*/
	{.bitmap_index = 498333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湘)*/
	{.bitmap_index = 498471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湛)*/
	{.bitmap_index = 498609, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湟)*/
	{.bitmap_index = 498747, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湫)*/
	{.bitmap_index = 498885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湮)*/
	{.bitmap_index = 499023, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(湾)*/
	{.bitmap_index = 499167, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(湿)*/
	{.bitmap_index = 499305, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溃)*/
	{.bitmap_index = 499449, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溅)*/
	{.bitmap_index = 499587, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溆)*/
	{.bitmap_index = 499731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溉)*/
	{.bitmap_index = 499869, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溏)*/
	{.bitmap_index = 500007, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(源)*/
	{.bitmap_index = 500151, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溘)*/
	{.bitmap_index = 500289, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溜)*/
	{.bitmap_index = 500427, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溟)*/
	{.bitmap_index = 500571, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溢)*/
	{.bitmap_index = 500709, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溥)*/
	{.bitmap_index = 500847, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溧)*/
	{.bitmap_index = 500985, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溪)*/
	{.bitmap_index = 501129, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溯)*/
	{.bitmap_index = 501273, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溱)*/
	{.bitmap_index = 501411, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溲)*/
	{.bitmap_index = 501555, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(溴)*/
	{.bitmap_index = 501699, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溶)*/
	{.bitmap_index = 501837, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溷)*/
	{.bitmap_index = 501975, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溺)*/
	{.bitmap_index = 502113, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(溻)*/
	{.bitmap_index = 502251, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(溽)*/
	{.bitmap_index = 502389, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滁)*/
	{.bitmap_index = 502527, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滂)*/
	{.bitmap_index = 502671, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滇)*/
	{.bitmap_index = 502815, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滋)*/
	{.bitmap_index = 502953, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滏)*/
	{.bitmap_index = 503091, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滑)*/
	{.bitmap_index = 503229, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滓)*/
	{.bitmap_index = 503367, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滔)*/
	{.bitmap_index = 503505, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滕)*/
	{.bitmap_index = 503649, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滗)*/
	{.bitmap_index = 503787, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滚)*/
	{.bitmap_index = 503931, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滞)*/
	{.bitmap_index = 504069, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滟)*/
	{.bitmap_index = 504207, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滠)*/
	{.bitmap_index = 504345, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(满)*/
	{.bitmap_index = 504483, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滢)*/
	{.bitmap_index = 504621, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滤)*/
	{.bitmap_index = 504759, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滥)*/
	{.bitmap_index = 504897, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滦)*/
	{.bitmap_index = 505041, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(滨)*/
	{.bitmap_index = 505185, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滩)*/
	{.bitmap_index = 505323, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滴)*/
	{.bitmap_index = 505461, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(滹)*/
	{.bitmap_index = 505599, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漂)*/
	{.bitmap_index = 505737, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(漆)*/
	{.bitmap_index = 505875, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漉)*/
	{.bitmap_index = 506013, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漏)*/
	{.bitmap_index = 506151, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漓)*/
	{.bitmap_index = 506289, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(演)*/
	{.bitmap_index = 506433, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漕)*/
	{.bitmap_index = 506571, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(漠)*/
	{.bitmap_index = 506715, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漤)*/
	{.bitmap_index = 506853, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(漩)*/
	{.bitmap_index = 506997, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漪)*/
	{.bitmap_index = 507135, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(漫)*/
	{.bitmap_index = 507279, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(漭)*/
	{.bitmap_index = 507423, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漯)*/
	{.bitmap_index = 507561, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(漱)*/
	{.bitmap_index = 507705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(漳)*/
	{.bitmap_index = 507849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漶)*/
	{.bitmap_index = 507987, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(漾)*/
	{.bitmap_index = 508131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潆)*/
	{.bitmap_index = 508269, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(潇)*/
	{.bitmap_index = 508413, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潋)*/
	{.bitmap_index = 508551, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潍)*/
	{.bitmap_index = 508689, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潘)*/
	{.bitmap_index = 508827, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潜)*/
	{.bitmap_index = 508965, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潞)*/
	{.bitmap_index = 509103, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(潢)*/
	{.bitmap_index = 509247, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潦)*/
	{.bitmap_index = 509385, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潭)*/
	{.bitmap_index = 509523, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(潮)*/
	{.bitmap_index = 509667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潲)*/
	{.bitmap_index = 509805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潴)*/
	{.bitmap_index = 509943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潸)*/
	{.bitmap_index = 510081, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潺)*/
	{.bitmap_index = 510219, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(潼)*/
	{.bitmap_index = 510357, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澄)*/
	{.bitmap_index = 510495, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(澈)*/
	{.bitmap_index = 510639, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澉)*/
	{.bitmap_index = 510777, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(澌)*/
	{.bitmap_index = 510921, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澍)*/
	{.bitmap_index = 511059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澎)*/
	{.bitmap_index = 511197, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澜)*/
	{.bitmap_index = 511335, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澡)*/
	{.bitmap_index = 511473, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澧)*/
	{.bitmap_index = 511611, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(澳)*/
	{.bitmap_index = 511755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澶)*/
	{.bitmap_index = 511893, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(澹)*/
	{.bitmap_index = 512037, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(激)*/
	{.bitmap_index = 512181, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濂)*/
	{.bitmap_index = 512319, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濉)*/
	{.bitmap_index = 512457, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濑)*/
	{.bitmap_index = 512595, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濒)*/
	{.bitmap_index = 512733, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(濞)*/
	{.bitmap_index = 512877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濠)*/
	{.bitmap_index = 513015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濡)*/
	{.bitmap_index = 513153, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濮)*/
	{.bitmap_index = 513291, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(濯)*/
	{.bitmap_index = 513429, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瀑)*/
	{.bitmap_index = 513567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瀚)*/
	{.bitmap_index = 513705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瀛)*/
	{.bitmap_index = 513849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瀣)*/
	{.bitmap_index = 513987, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瀵)*/
	{.bitmap_index = 514131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瀹)*/
	{.bitmap_index = 514269, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灌)*/
	{.bitmap_index = 514407, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灏)*/
	{.bitmap_index = 514545, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(灞)*/
	{.bitmap_index = 514689, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(火)*/
	{.bitmap_index = 514833, .adv_w = 24, .box_h = 10, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灬)*/
	{.bitmap_index = 514893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(灭)*/
	{.bitmap_index = 515031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灯)*/
	{.bitmap_index = 515169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灰)*/
	{.bitmap_index = 515307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(灵)*/
	{.bitmap_index = 515445, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灶)*/
	{.bitmap_index = 515583, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(灸)*/
	{.bitmap_index = 515733, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灼)*/
	{.bitmap_index = 515871, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(灾)*/
	{.bitmap_index = 516015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(灿)*/
	{.bitmap_index = 516153, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炀)*/
	{.bitmap_index = 516297, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(炅)*/
	{.bitmap_index = 516435, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炉)*/
	{.bitmap_index = 516579, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炊)*/
	{.bitmap_index = 516723, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(炎)*/
	{.bitmap_index = 516867, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炒)*/
	{.bitmap_index = 517011, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炔)*/
	{.bitmap_index = 517155, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炕)*/
	{.bitmap_index = 517299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炖)*/
	{.bitmap_index = 517437, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炙)*/
	{.bitmap_index = 517587, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炜)*/
	{.bitmap_index = 517731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炝)*/
	{.bitmap_index = 517869, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炫)*/
	{.bitmap_index = 518013, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炬)*/
	{.bitmap_index = 518151, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炭)*/
	{.bitmap_index = 518295, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炮)*/
	{.bitmap_index = 518439, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炯)*/
	{.bitmap_index = 518577, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(炱)*/
	{.bitmap_index = 518727, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炳)*/
	{.bitmap_index = 518865, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炷)*/
	{.bitmap_index = 519003, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炸)*/
	{.bitmap_index = 519141, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(点)*/
	{.bitmap_index = 519285, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炻)*/
	{.bitmap_index = 519429, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(炼)*/
	{.bitmap_index = 519567, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(炽)*/
	{.bitmap_index = 519711, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烀)*/
	{.bitmap_index = 519849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烁)*/
	{.bitmap_index = 519987, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烂)*/
	{.bitmap_index = 520125, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烃)*/
	{.bitmap_index = 520269, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烈)*/
	{.bitmap_index = 520413, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烊)*/
	{.bitmap_index = 520551, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烘)*/
	{.bitmap_index = 520689, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烙)*/
	{.bitmap_index = 520833, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烛)*/
	{.bitmap_index = 520971, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烟)*/
	{.bitmap_index = 521109, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烤)*/
	{.bitmap_index = 521247, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烦)*/
	{.bitmap_index = 521391, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烧)*/
	{.bitmap_index = 521535, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烨)*/
	{.bitmap_index = 521673, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烩)*/
	{.bitmap_index = 521817, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(烫)*/
	{.bitmap_index = 521961, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烬)*/
	{.bitmap_index = 522105, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(热)*/
	{.bitmap_index = 522249, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烯)*/
	{.bitmap_index = 522393, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(烷)*/
	{.bitmap_index = 522537, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(烹)*/
	{.bitmap_index = 522681, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(烽)*/
	{.bitmap_index = 522819, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(焉)*/
	{.bitmap_index = 522951, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焊)*/
	{.bitmap_index = 523095, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焐)*/
	{.bitmap_index = 523239, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焓)*/
	{.bitmap_index = 523383, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焕)*/
	{.bitmap_index = 523527, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(焖)*/
	{.bitmap_index = 523665, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焘)*/
	{.bitmap_index = 523809, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焙)*/
	{.bitmap_index = 523953, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焚)*/
	{.bitmap_index = 524097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焦)*/
	{.bitmap_index = 524241, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焯)*/
	{.bitmap_index = 524385, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(焰)*/
	{.bitmap_index = 524523, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(焱)*/
	{.bitmap_index = 524667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(然)*/
	{.bitmap_index = 524805, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(煅)*/
	{.bitmap_index = 524949, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煊)*/
	{.bitmap_index = 525087, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煌)*/
	{.bitmap_index = 525225, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(煎)*/
	{.bitmap_index = 525369, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(煜)*/
	{.bitmap_index = 525513, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(煞)*/
	{.bitmap_index = 525657, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煤)*/
	{.bitmap_index = 525795, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(煦)*/
	{.bitmap_index = 525939, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(照)*/
	{.bitmap_index = 526077, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煨)*/
	{.bitmap_index = 526215, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(煮)*/
	{.bitmap_index = 526359, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(煲)*/
	{.bitmap_index = 526503, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(煳)*/
	{.bitmap_index = 526647, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煸)*/
	{.bitmap_index = 526785, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煺)*/
	{.bitmap_index = 526923, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(煽)*/
	{.bitmap_index = 527061, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(熄)*/
	{.bitmap_index = 527199, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(熊)*/
	{.bitmap_index = 527349, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(熏)*/
	{.bitmap_index = 527493, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(熔)*/
	{.bitmap_index = 527637, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(熘)*/
	{.bitmap_index = 527775, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(熙)*/
	{.bitmap_index = 527907, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(熟)*/
	{.bitmap_index = 528051, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(熠)*/
	{.bitmap_index = 528189, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(熨)*/
	{.bitmap_index = 528333, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(熬)*/
	{.bitmap_index = 528477, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(熳)*/
	{.bitmap_index = 528621, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(熵)*/
	{.bitmap_index = 528759, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(熹)*/
	{.bitmap_index = 528903, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(燃)*/
	{.bitmap_index = 529041, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(燎)*/
	{.bitmap_index = 529179, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(燔)*/
	{.bitmap_index = 529317, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(燕)*/
	{.bitmap_index = 529455, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(燠)*/
	{.bitmap_index = 529599, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(燥)*/
	{.bitmap_index = 529737, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(燧)*/
	{.bitmap_index = 529881, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(燮)*/
	{.bitmap_index = 530025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(燹)*/
	{.bitmap_index = 530163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(爆)*/
	{.bitmap_index = 530301, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(爝)*/
	{.bitmap_index = 530439, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(爨)*/
	{.bitmap_index = 530583, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(爪)*/
	{.bitmap_index = 530721, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(爬)*/
	{.bitmap_index = 530859, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(爰)*/
	{.bitmap_index = 531003, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(爱)*/
	{.bitmap_index = 531147, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(爵)*/
	{.bitmap_index = 531285, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(父)*/
	{.bitmap_index = 531429, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(爷)*/
	{.bitmap_index = 531567, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(爸)*/
	{.bitmap_index = 531705, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(爹)*/
	{.bitmap_index = 531849, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(爻)*/
	{.bitmap_index = 531993, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(爽)*/
	{.bitmap_index = 532137, .adv_w = 21, .box_h = 24, .box_w = 20, .ofs_x = 1, .ofs_y = 4},/*(爿)*/
	{.bitmap_index = 532257, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(片)*/
	{.bitmap_index = 532401, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(版)*/
	{.bitmap_index = 532545, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(牌)*/
	{.bitmap_index = 532689, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(牍)*/
	{.bitmap_index = 532833, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牒)*/
	{.bitmap_index = 532971, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牖)*/
	{.bitmap_index = 533109, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牙)*/
	{.bitmap_index = 533241, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(牛)*/
	{.bitmap_index = 533379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牝)*/
	{.bitmap_index = 533517, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(牟)*/
	{.bitmap_index = 533661, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牡)*/
	{.bitmap_index = 533799, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(牢)*/
	{.bitmap_index = 533937, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牦)*/
	{.bitmap_index = 534075, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(牧)*/
	{.bitmap_index = 534219, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(物)*/
	{.bitmap_index = 534357, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牮)*/
	{.bitmap_index = 534495, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牯)*/
	{.bitmap_index = 534633, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牲)*/
	{.bitmap_index = 534771, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(牵)*/
	{.bitmap_index = 534909, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(特)*/
	{.bitmap_index = 535047, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牺)*/
	{.bitmap_index = 535185, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牾)*/
	{.bitmap_index = 535323, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(牿)*/
	{.bitmap_index = 535461, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犀)*/
	{.bitmap_index = 535599, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犁)*/
	{.bitmap_index = 535737, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犄)*/
	{.bitmap_index = 535875, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犊)*/
	{.bitmap_index = 536019, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犋)*/
	{.bitmap_index = 536163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犍)*/
	{.bitmap_index = 536301, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犏)*/
	{.bitmap_index = 536439, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犒)*/
	{.bitmap_index = 536577, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(犟)*/
	{.bitmap_index = 536709, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犬)*/
	{.bitmap_index = 536853, .adv_w = 13, .box_h = 23, .box_w = 12, .ofs_x = 1, .ofs_y = 5},/*(犭)*/
	{.bitmap_index = 536922, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犯)*/
	{.bitmap_index = 537060, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犰)*/
	{.bitmap_index = 537204, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犴)*/
	{.bitmap_index = 537342, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(状)*/
	{.bitmap_index = 537486, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犷)*/
	{.bitmap_index = 537630, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(犸)*/
	{.bitmap_index = 537762, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(犹)*/
	{.bitmap_index = 537906, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狁)*/
	{.bitmap_index = 538044, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狂)*/
	{.bitmap_index = 538182, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狃)*/
	{.bitmap_index = 538320, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狄)*/
	{.bitmap_index = 538464, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狈)*/
	{.bitmap_index = 538608, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狍)*/
	{.bitmap_index = 538746, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狎)*/
	{.bitmap_index = 538884, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狐)*/
	{.bitmap_index = 539022, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狒)*/
	{.bitmap_index = 539166, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狗)*/
	{.bitmap_index = 539304, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狙)*/
	{.bitmap_index = 539442, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狞)*/
	{.bitmap_index = 539580, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狠)*/
	{.bitmap_index = 539724, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狡)*/
	{.bitmap_index = 539868, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狨)*/
	{.bitmap_index = 540006, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狩)*/
	{.bitmap_index = 540144, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(独)*/
	{.bitmap_index = 540282, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狭)*/
	{.bitmap_index = 540426, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狮)*/
	{.bitmap_index = 540570, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狯)*/
	{.bitmap_index = 540708, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狰)*/
	{.bitmap_index = 540846, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狱)*/
	{.bitmap_index = 540990, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狲)*/
	{.bitmap_index = 541128, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狳)*/
	{.bitmap_index = 541266, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狴)*/
	{.bitmap_index = 541404, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狷)*/
	{.bitmap_index = 541542, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狸)*/
	{.bitmap_index = 541680, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(狺)*/
	{.bitmap_index = 541818, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狻)*/
	{.bitmap_index = 541962, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(狼)*/
	{.bitmap_index = 542106, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猁)*/
	{.bitmap_index = 542244, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猃)*/
	{.bitmap_index = 542382, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(猊)*/
	{.bitmap_index = 542526, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猎)*/
	{.bitmap_index = 542664, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猓)*/
	{.bitmap_index = 542802, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猕)*/
	{.bitmap_index = 542940, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猖)*/
	{.bitmap_index = 543078, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猗)*/
	{.bitmap_index = 543216, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猛)*/
	{.bitmap_index = 543354, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猜)*/
	{.bitmap_index = 543492, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猝)*/
	{.bitmap_index = 543630, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猞)*/
	{.bitmap_index = 543768, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猡)*/
	{.bitmap_index = 543906, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猢)*/
	{.bitmap_index = 544044, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猥)*/
	{.bitmap_index = 544182, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猩)*/
	{.bitmap_index = 544320, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猪)*/
	{.bitmap_index = 544458, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猫)*/
	{.bitmap_index = 544596, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猬)*/
	{.bitmap_index = 544734, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(献)*/
	{.bitmap_index = 544872, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猱)*/
	{.bitmap_index = 545010, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(猴)*/
	{.bitmap_index = 545154, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(猷)*/
	{.bitmap_index = 545292, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猸)*/
	{.bitmap_index = 545430, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猹)*/
	{.bitmap_index = 545568, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(猾)*/
	{.bitmap_index = 545706, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(猿)*/
	{.bitmap_index = 545850, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(獍)*/
	{.bitmap_index = 545994, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(獐)*/
	{.bitmap_index = 546138, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(獒)*/
	{.bitmap_index = 546282, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(獗)*/
	{.bitmap_index = 546426, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(獠)*/
	{.bitmap_index = 546564, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(獬)*/
	{.bitmap_index = 546702, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(獭)*/
	{.bitmap_index = 546846, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(獯)*/
	{.bitmap_index = 546990, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(獾)*/
	{.bitmap_index = 547128, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(玄)*/
	{.bitmap_index = 547266, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(率)*/
	{.bitmap_index = 547404, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(玉)*/
	{.bitmap_index = 547530, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(王)*/
	{.bitmap_index = 547656, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(玎)*/
	{.bitmap_index = 547788, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玑)*/
	{.bitmap_index = 547926, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玖)*/
	{.bitmap_index = 548070, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(玛)*/
	{.bitmap_index = 548202, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玟)*/
	{.bitmap_index = 548346, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玢)*/
	{.bitmap_index = 548490, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玩)*/
	{.bitmap_index = 548628, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玫)*/
	{.bitmap_index = 548772, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(玮)*/
	{.bitmap_index = 548910, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(环)*/
	{.bitmap_index = 549042, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(现)*/
	{.bitmap_index = 549180, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玲)*/
	{.bitmap_index = 549324, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(玳)*/
	{.bitmap_index = 549462, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(玷)*/
	{.bitmap_index = 549600, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(玺)*/
	{.bitmap_index = 549738, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(玻)*/
	{.bitmap_index = 549882, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珀)*/
	{.bitmap_index = 550020, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(珂)*/
	{.bitmap_index = 550152, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珈)*/
	{.bitmap_index = 550290, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(珉)*/
	{.bitmap_index = 550428, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珊)*/
	{.bitmap_index = 550560, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(珍)*/
	{.bitmap_index = 550704, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(珏)*/
	{.bitmap_index = 550830, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(珐)*/
	{.bitmap_index = 550968, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(珑)*/
	{.bitmap_index = 551112, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珙)*/
	{.bitmap_index = 551250, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珞)*/
	{.bitmap_index = 551388, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(珠)*/
	{.bitmap_index = 551526, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(珥)*/
	{.bitmap_index = 551658, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珧)*/
	{.bitmap_index = 551796, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(珩)*/
	{.bitmap_index = 551934, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(班)*/
	{.bitmap_index = 552078, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(珲)*/
	{.bitmap_index = 552210, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(球)*/
	{.bitmap_index = 552348, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(琅)*/
	{.bitmap_index = 552492, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(理)*/
	{.bitmap_index = 552624, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(琉)*/
	{.bitmap_index = 552768, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琊)*/
	{.bitmap_index = 552900, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琏)*/
	{.bitmap_index = 553038, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(琐)*/
	{.bitmap_index = 553182, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琚)*/
	{.bitmap_index = 553314, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琛)*/
	{.bitmap_index = 553446, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琢)*/
	{.bitmap_index = 553578, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(琥)*/
	{.bitmap_index = 553722, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琦)*/
	{.bitmap_index = 553860, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琨)*/
	{.bitmap_index = 553992, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(琪)*/
	{.bitmap_index = 554136, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(琬)*/
	{.bitmap_index = 554280, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琮)*/
	{.bitmap_index = 554418, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(琰)*/
	{.bitmap_index = 554562, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(琳)*/
	{.bitmap_index = 554700, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(琴)*/
	{.bitmap_index = 554838, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(琵)*/
	{.bitmap_index = 554970, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(琶)*/
	{.bitmap_index = 555102, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(琼)*/
	{.bitmap_index = 555240, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑁)*/
	{.bitmap_index = 555372, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑕)*/
	{.bitmap_index = 555504, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瑗)*/
	{.bitmap_index = 555648, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瑙)*/
	{.bitmap_index = 555786, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瑚)*/
	{.bitmap_index = 555930, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瑛)*/
	{.bitmap_index = 556074, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑜)*/
	{.bitmap_index = 556212, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑞)*/
	{.bitmap_index = 556350, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑟)*/
	{.bitmap_index = 556482, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑭)*/
	{.bitmap_index = 556620, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瑰)*/
	{.bitmap_index = 556764, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑶)*/
	{.bitmap_index = 556902, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瑷)*/
	{.bitmap_index = 557046, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瑾)*/
	{.bitmap_index = 557184, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(璀)*/
	{.bitmap_index = 557322, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(璁)*/
	{.bitmap_index = 557460, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(璃)*/
	{.bitmap_index = 557598, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(璇)*/
	{.bitmap_index = 557742, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(璋)*/
	{.bitmap_index = 557880, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(璎)*/
	{.bitmap_index = 558018, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(璐)*/
	{.bitmap_index = 558150, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(璜)*/
	{.bitmap_index = 558294, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(璞)*/
	{.bitmap_index = 558438, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(璧)*/
	{.bitmap_index = 558576, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(璨)*/
	{.bitmap_index = 558714, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(璩)*/
	{.bitmap_index = 558858, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(璺)*/
	{.bitmap_index = 558996, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瓒)*/
	{.bitmap_index = 559140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瓜)*/
	{.bitmap_index = 559278, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瓞)*/
	{.bitmap_index = 559422, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瓠)*/
	{.bitmap_index = 559560, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瓢)*/
	{.bitmap_index = 559698, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(瓣)*/
	{.bitmap_index = 559842, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瓤)*/
	{.bitmap_index = 559986, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瓦)*/
	{.bitmap_index = 560118, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瓮)*/
	{.bitmap_index = 560256, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(瓯)*/
	{.bitmap_index = 560388, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瓴)*/
	{.bitmap_index = 560526, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瓶)*/
	{.bitmap_index = 560664, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瓷)*/
	{.bitmap_index = 560802, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瓿)*/
	{.bitmap_index = 560940, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(甄)*/
	{.bitmap_index = 561072, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甍)*/
	{.bitmap_index = 561210, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甏)*/
	{.bitmap_index = 561348, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甑)*/
	{.bitmap_index = 561486, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(甓)*/
	{.bitmap_index = 561624, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甘)*/
	{.bitmap_index = 561762, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(甙)*/
	{.bitmap_index = 561906, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甚)*/
	{.bitmap_index = 562044, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甜)*/
	{.bitmap_index = 562182, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(生)*/
	{.bitmap_index = 562314, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(甥)*/
	{.bitmap_index = 562458, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(用)*/
	{.bitmap_index = 562596, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(甩)*/
	{.bitmap_index = 562728, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甫)*/
	{.bitmap_index = 562872, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(甬)*/
	{.bitmap_index = 562982, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(甭)*/
	{.bitmap_index = 563120, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甯)*/
	{.bitmap_index = 563258, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(田)*/
	{.bitmap_index = 563363, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(由)*/
	{.bitmap_index = 563478, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(甲)*/
	{.bitmap_index = 563588, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(申)*/
	{.bitmap_index = 563703, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(电)*/
	{.bitmap_index = 563841, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(男)*/
	{.bitmap_index = 563979, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(甸)*/
	{.bitmap_index = 564117, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(町)*/
	{.bitmap_index = 564249, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(画)*/
	{.bitmap_index = 564381, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(甾)*/
	{.bitmap_index = 564519, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(畀)*/
	{.bitmap_index = 564657, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(畅)*/
	{.bitmap_index = 564801, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(畈)*/
	{.bitmap_index = 564945, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(畋)*/
	{.bitmap_index = 565089, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(界)*/
	{.bitmap_index = 565233, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(畎)*/
	{.bitmap_index = 565377, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(畏)*/
	{.bitmap_index = 565515, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(畔)*/
	{.bitmap_index = 565653, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(留)*/
	{.bitmap_index = 565791, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(畚)*/
	{.bitmap_index = 565935, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(畛)*/
	{.bitmap_index = 566079, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(畜)*/
	{.bitmap_index = 566217, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(略)*/
	{.bitmap_index = 566355, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(畦)*/
	{.bitmap_index = 566493, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(番)*/
	{.bitmap_index = 566631, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(畲)*/
	{.bitmap_index = 566769, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(畴)*/
	{.bitmap_index = 566907, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(畸)*/
	{.bitmap_index = 567045, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(畹)*/
	{.bitmap_index = 567183, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(畿)*/
	{.bitmap_index = 567327, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(疃)*/
	{.bitmap_index = 567465, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(疆)*/
	{.bitmap_index = 567597, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(疋)*/
	{.bitmap_index = 567729, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疏)*/
	{.bitmap_index = 567873, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(疑)*/
	{.bitmap_index = 568017, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疒)*/
	{.bitmap_index = 568161, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疔)*/
	{.bitmap_index = 568305, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疖)*/
	{.bitmap_index = 568449, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疗)*/
	{.bitmap_index = 568593, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(疙)*/
	{.bitmap_index = 568731, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疚)*/
	{.bitmap_index = 568875, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(疝)*/
	{.bitmap_index = 569013, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疟)*/
	{.bitmap_index = 569157, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疠)*/
	{.bitmap_index = 569301, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疡)*/
	{.bitmap_index = 569445, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疣)*/
	{.bitmap_index = 569589, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疤)*/
	{.bitmap_index = 569733, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疥)*/
	{.bitmap_index = 569877, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疫)*/
	{.bitmap_index = 570021, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疬)*/
	{.bitmap_index = 570165, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疮)*/
	{.bitmap_index = 570309, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疯)*/
	{.bitmap_index = 570453, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疰)*/
	{.bitmap_index = 570597, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(疱)*/
	{.bitmap_index = 570735, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疲)*/
	{.bitmap_index = 570879, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疳)*/
	{.bitmap_index = 571023, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疴)*/
	{.bitmap_index = 571167, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疵)*/
	{.bitmap_index = 571311, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疸)*/
	{.bitmap_index = 571455, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疹)*/
	{.bitmap_index = 571599, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疼)*/
	{.bitmap_index = 571743, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疽)*/
	{.bitmap_index = 571887, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(疾)*/
	{.bitmap_index = 572031, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痂)*/
	{.bitmap_index = 572175, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(痃)*/
	{.bitmap_index = 572313, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痄)*/
	{.bitmap_index = 572457, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(病)*/
	{.bitmap_index = 572601, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(症)*/
	{.bitmap_index = 572745, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痈)*/
	{.bitmap_index = 572889, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痉)*/
	{.bitmap_index = 573033, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痊)*/
	{.bitmap_index = 573177, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痍)*/
	{.bitmap_index = 573321, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痒)*/
	{.bitmap_index = 573465, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痔)*/
	{.bitmap_index = 573609, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痕)*/
	{.bitmap_index = 573753, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痖)*/
	{.bitmap_index = 573897, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痘)*/
	{.bitmap_index = 574041, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痛)*/
	{.bitmap_index = 574185, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痞)*/
	{.bitmap_index = 574329, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痢)*/
	{.bitmap_index = 574473, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痣)*/
	{.bitmap_index = 574617, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痤)*/
	{.bitmap_index = 574761, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(痦)*/
	{.bitmap_index = 574899, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痧)*/
	{.bitmap_index = 575043, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痨)*/
	{.bitmap_index = 575187, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痪)*/
	{.bitmap_index = 575331, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痫)*/
	{.bitmap_index = 575475, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痰)*/
	{.bitmap_index = 575619, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痱)*/
	{.bitmap_index = 575763, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痴)*/
	{.bitmap_index = 575907, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痹)*/
	{.bitmap_index = 576051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痼)*/
	{.bitmap_index = 576195, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(痿)*/
	{.bitmap_index = 576339, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘀)*/
	{.bitmap_index = 576483, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘁)*/
	{.bitmap_index = 576627, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘃)*/
	{.bitmap_index = 576771, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘅)*/
	{.bitmap_index = 576915, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘊)*/
	{.bitmap_index = 577059, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘌)*/
	{.bitmap_index = 577203, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘐)*/
	{.bitmap_index = 577347, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘕)*/
	{.bitmap_index = 577491, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘗)*/
	{.bitmap_index = 577635, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘘)*/
	{.bitmap_index = 577779, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘙)*/
	{.bitmap_index = 577923, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘛)*/
	{.bitmap_index = 578067, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瘟)*/
	{.bitmap_index = 578205, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘠)*/
	{.bitmap_index = 578349, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘢)*/
	{.bitmap_index = 578493, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瘤)*/
	{.bitmap_index = 578631, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘥)*/
	{.bitmap_index = 578775, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘦)*/
	{.bitmap_index = 578919, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瘩)*/
	{.bitmap_index = 579057, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘪)*/
	{.bitmap_index = 579201, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘫)*/
	{.bitmap_index = 579345, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘭)*/
	{.bitmap_index = 579489, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘰)*/
	{.bitmap_index = 579633, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘳)*/
	{.bitmap_index = 579777, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘴)*/
	{.bitmap_index = 579921, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瘵)*/
	{.bitmap_index = 580059, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘸)*/
	{.bitmap_index = 580203, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘼)*/
	{.bitmap_index = 580347, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘾)*/
	{.bitmap_index = 580491, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(瘿)*/
	{.bitmap_index = 580635, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癀)*/
	{.bitmap_index = 580779, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(癃)*/
	{.bitmap_index = 580917, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(癌)*/
	{.bitmap_index = 581055, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癍)*/
	{.bitmap_index = 581199, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(癔)*/
	{.bitmap_index = 581337, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(癖)*/
	{.bitmap_index = 581475, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(癜)*/
	{.bitmap_index = 581613, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癞)*/
	{.bitmap_index = 581757, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癣)*/
	{.bitmap_index = 581901, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癫)*/
	{.bitmap_index = 582045, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癯)*/
	{.bitmap_index = 582189, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(癸)*/
	{.bitmap_index = 582333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(登)*/
	{.bitmap_index = 582471, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(白)*/
	{.bitmap_index = 582586, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(百)*/
	{.bitmap_index = 582718, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(皂)*/
	{.bitmap_index = 582856, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(的)*/
	{.bitmap_index = 583000, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(皆)*/
	{.bitmap_index = 583138, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(皇)*/
	{.bitmap_index = 583276, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(皈)*/
	{.bitmap_index = 583420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(皋)*/
	{.bitmap_index = 583558, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(皎)*/
	{.bitmap_index = 583702, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(皑)*/
	{.bitmap_index = 583840, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(皓)*/
	{.bitmap_index = 583978, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(皖)*/
	{.bitmap_index = 584122, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(皙)*/
	{.bitmap_index = 584260, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(皤)*/
	{.bitmap_index = 584398, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(皮)*/
	{.bitmap_index = 584542, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(皱)*/
	{.bitmap_index = 584686, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(皲)*/
	{.bitmap_index = 584830, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(皴)*/
	{.bitmap_index = 584974, .adv_w = 25, .box_h = 20, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(皿)*/
	{.bitmap_index = 585094, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盂)*/
	{.bitmap_index = 585226, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盅)*/
	{.bitmap_index = 585364, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(盆)*/
	{.bitmap_index = 585508, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(盈)*/
	{.bitmap_index = 585640, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(益)*/
	{.bitmap_index = 585772, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盍)*/
	{.bitmap_index = 585910, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盎)*/
	{.bitmap_index = 586048, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盏)*/
	{.bitmap_index = 586192, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盐)*/
	{.bitmap_index = 586330, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(监)*/
	{.bitmap_index = 586468, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(盒)*/
	{.bitmap_index = 586606, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(盔)*/
	{.bitmap_index = 586744, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盖)*/
	{.bitmap_index = 586888, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盗)*/
	{.bitmap_index = 587026, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盘)*/
	{.bitmap_index = 587164, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(盛)*/
	{.bitmap_index = 587302, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盟)*/
	{.bitmap_index = 587434, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盥)*/
	{.bitmap_index = 587572, .adv_w = 23, .box_h = 22, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(目)*/
	{.bitmap_index = 587682, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(盯)*/
	{.bitmap_index = 587814, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(盱)*/
	{.bitmap_index = 587946, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(盲)*/
	{.bitmap_index = 588084, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(直)*/
	{.bitmap_index = 588222, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(相)*/
	{.bitmap_index = 588360, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(盹)*/
	{.bitmap_index = 588498, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(盼)*/
	{.bitmap_index = 588642, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(盾)*/
	{.bitmap_index = 588786, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(省)*/
	{.bitmap_index = 588924, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(眄)*/
	{.bitmap_index = 589056, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(眇)*/
	{.bitmap_index = 589200, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(眈)*/
	{.bitmap_index = 589344, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(眉)*/
	{.bitmap_index = 589476, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(看)*/
	{.bitmap_index = 589614, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(眍)*/
	{.bitmap_index = 589746, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(眙)*/
	{.bitmap_index = 589884, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(眚)*/
	{.bitmap_index = 590022, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(真)*/
	{.bitmap_index = 590166, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(眠)*/
	{.bitmap_index = 590304, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(眢)*/
	{.bitmap_index = 590442, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(眦)*/
	{.bitmap_index = 590580, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(眨)*/
	{.bitmap_index = 590718, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(眩)*/
	{.bitmap_index = 590856, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(眭)*/
	{.bitmap_index = 590994, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(眯)*/
	{.bitmap_index = 591132, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(眵)*/
	{.bitmap_index = 591276, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(眶)*/
	{.bitmap_index = 591408, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(眷)*/
	{.bitmap_index = 591546, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(眸)*/
	{.bitmap_index = 591684, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(眺)*/
	{.bitmap_index = 591828, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(眼)*/
	{.bitmap_index = 591966, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(着)*/
	{.bitmap_index = 592110, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(睁)*/
	{.bitmap_index = 592248, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(睃)*/
	{.bitmap_index = 592392, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睇)*/
	{.bitmap_index = 592530, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(睐)*/
	{.bitmap_index = 592668, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 6},/*(睑)*/
	{.bitmap_index = 592800, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(睚)*/
	{.bitmap_index = 592938, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睛)*/
	{.bitmap_index = 593076, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(睡)*/
	{.bitmap_index = 593208, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睢)*/
	{.bitmap_index = 593346, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(督)*/
	{.bitmap_index = 593484, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睥)*/
	{.bitmap_index = 593622, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睦)*/
	{.bitmap_index = 593760, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(睨)*/
	{.bitmap_index = 593904, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(睫)*/
	{.bitmap_index = 594048, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睬)*/
	{.bitmap_index = 594186, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(睹)*/
	{.bitmap_index = 594324, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(睽)*/
	{.bitmap_index = 594468, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(睾)*/
	{.bitmap_index = 594606, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(睿)*/
	{.bitmap_index = 594744, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瞀)*/
	{.bitmap_index = 594882, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞄)*/
	{.bitmap_index = 595020, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞅)*/
	{.bitmap_index = 595158, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞌)*/
	{.bitmap_index = 595296, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(瞍)*/
	{.bitmap_index = 595440, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(瞎)*/
	{.bitmap_index = 595578, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(瞑)*/
	{.bitmap_index = 595716, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞒)*/
	{.bitmap_index = 595854, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞟)*/
	{.bitmap_index = 595986, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞠)*/
	{.bitmap_index = 596124, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞢)*/
	{.bitmap_index = 596262, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(瞥)*/
	{.bitmap_index = 596400, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(瞧)*/
	{.bitmap_index = 596538, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞩)*/
	{.bitmap_index = 596670, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞪)*/
	{.bitmap_index = 596808, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(瞬)*/
	{.bitmap_index = 596952, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(瞰)*/
	{.bitmap_index = 597090, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞳)*/
	{.bitmap_index = 597228, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(瞵)*/
	{.bitmap_index = 597372, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(瞻)*/
	{.bitmap_index = 597522, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(瞽)*/
	{.bitmap_index = 597660, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(瞿)*/
	{.bitmap_index = 597798, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矍)*/
	{.bitmap_index = 597936, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(矗)*/
	{.bitmap_index = 598074, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矛)*/
	{.bitmap_index = 598206, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矜)*/
	{.bitmap_index = 598344, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矢)*/
	{.bitmap_index = 598488, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(矣)*/
	{.bitmap_index = 598638, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(知)*/
	{.bitmap_index = 598782, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矧)*/
	{.bitmap_index = 598920, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矩)*/
	{.bitmap_index = 599058, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矫)*/
	{.bitmap_index = 599202, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矬)*/
	{.bitmap_index = 599346, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(短)*/
	{.bitmap_index = 599484, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矮)*/
	{.bitmap_index = 599622, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(石)*/
	{.bitmap_index = 599748, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矶)*/
	{.bitmap_index = 599880, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(矸)*/
	{.bitmap_index = 600012, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矽)*/
	{.bitmap_index = 600156, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矾)*/
	{.bitmap_index = 600294, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(矿)*/
	{.bitmap_index = 600438, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砀)*/
	{.bitmap_index = 600576, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(码)*/
	{.bitmap_index = 600708, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砂)*/
	{.bitmap_index = 600852, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砉)*/
	{.bitmap_index = 600990, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砌)*/
	{.bitmap_index = 601134, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砍)*/
	{.bitmap_index = 601278, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砑)*/
	{.bitmap_index = 601410, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砒)*/
	{.bitmap_index = 601548, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(研)*/
	{.bitmap_index = 601686, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砖)*/
	{.bitmap_index = 601830, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砗)*/
	{.bitmap_index = 601968, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砘)*/
	{.bitmap_index = 602106, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砚)*/
	{.bitmap_index = 602244, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砜)*/
	{.bitmap_index = 602376, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砝)*/
	{.bitmap_index = 602514, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砟)*/
	{.bitmap_index = 602652, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砣)*/
	{.bitmap_index = 602790, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砥)*/
	{.bitmap_index = 602934, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砦)*/
	{.bitmap_index = 603072, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砧)*/
	{.bitmap_index = 603210, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砩)*/
	{.bitmap_index = 603354, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(砬)*/
	{.bitmap_index = 603486, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砭)*/
	{.bitmap_index = 603624, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砰)*/
	{.bitmap_index = 603756, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(破)*/
	{.bitmap_index = 603900, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砷)*/
	{.bitmap_index = 604038, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砸)*/
	{.bitmap_index = 604170, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(砹)*/
	{.bitmap_index = 604314, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砺)*/
	{.bitmap_index = 604446, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砻)*/
	{.bitmap_index = 604584, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(砼)*/
	{.bitmap_index = 604716, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(砾)*/
	{.bitmap_index = 604854, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(础)*/
	{.bitmap_index = 604992, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硅)*/
	{.bitmap_index = 605130, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硇)*/
	{.bitmap_index = 605268, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硌)*/
	{.bitmap_index = 605406, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硎)*/
	{.bitmap_index = 605544, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硐)*/
	{.bitmap_index = 605676, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(硒)*/
	{.bitmap_index = 605802, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(硕)*/
	{.bitmap_index = 605940, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(硖)*/
	{.bitmap_index = 606084, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硗)*/
	{.bitmap_index = 606222, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硝)*/
	{.bitmap_index = 606360, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硪)*/
	{.bitmap_index = 606498, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(硫)*/
	{.bitmap_index = 606642, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(硬)*/
	{.bitmap_index = 606780, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硭)*/
	{.bitmap_index = 606918, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(确)*/
	{.bitmap_index = 607056, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(硷)*/
	{.bitmap_index = 607188, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(硼)*/
	{.bitmap_index = 607320, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碇)*/
	{.bitmap_index = 607464, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碉)*/
	{.bitmap_index = 607596, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碌)*/
	{.bitmap_index = 607728, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碍)*/
	{.bitmap_index = 607860, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碎)*/
	{.bitmap_index = 607998, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碑)*/
	{.bitmap_index = 608136, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碓)*/
	{.bitmap_index = 608274, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碗)*/
	{.bitmap_index = 608418, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碘)*/
	{.bitmap_index = 608562, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碚)*/
	{.bitmap_index = 608700, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碛)*/
	{.bitmap_index = 608844, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碜)*/
	{.bitmap_index = 608988, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碟)*/
	{.bitmap_index = 609126, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碡)*/
	{.bitmap_index = 609270, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碣)*/
	{.bitmap_index = 609402, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碥)*/
	{.bitmap_index = 609540, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碧)*/
	{.bitmap_index = 609678, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碰)*/
	{.bitmap_index = 609816, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碱)*/
	{.bitmap_index = 609960, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碲)*/
	{.bitmap_index = 610098, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碳)*/
	{.bitmap_index = 610242, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碴)*/
	{.bitmap_index = 610380, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(碹)*/
	{.bitmap_index = 610518, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(碾)*/
	{.bitmap_index = 610656, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磁)*/
	{.bitmap_index = 610794, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(磅)*/
	{.bitmap_index = 610938, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磉)*/
	{.bitmap_index = 611070, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磊)*/
	{.bitmap_index = 611202, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磋)*/
	{.bitmap_index = 611340, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磐)*/
	{.bitmap_index = 611478, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磔)*/
	{.bitmap_index = 611616, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磕)*/
	{.bitmap_index = 611754, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(磙)*/
	{.bitmap_index = 611898, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磨)*/
	{.bitmap_index = 612036, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磬)*/
	{.bitmap_index = 612174, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磲)*/
	{.bitmap_index = 612312, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(磴)*/
	{.bitmap_index = 612450, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(磷)*/
	{.bitmap_index = 612594, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(磺)*/
	{.bitmap_index = 612738, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(礁)*/
	{.bitmap_index = 612876, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(礅)*/
	{.bitmap_index = 613020, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(礓)*/
	{.bitmap_index = 613152, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(礞)*/
	{.bitmap_index = 613296, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(礤)*/
	{.bitmap_index = 613434, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(礴)*/
	{.bitmap_index = 613572, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(示)*/
	{.bitmap_index = 613704, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(礻)*/
	{.bitmap_index = 613796, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(礼)*/
	{.bitmap_index = 613934, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(社)*/
	{.bitmap_index = 614072, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祀)*/
	{.bitmap_index = 614210, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祁)*/
	{.bitmap_index = 614348, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祆)*/
	{.bitmap_index = 614486, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(祈)*/
	{.bitmap_index = 614630, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祉)*/
	{.bitmap_index = 614768, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(祓)*/
	{.bitmap_index = 614912, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祖)*/
	{.bitmap_index = 615050, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(祗)*/
	{.bitmap_index = 615194, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祚)*/
	{.bitmap_index = 615332, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祛)*/
	{.bitmap_index = 615470, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祜)*/
	{.bitmap_index = 615608, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(祝)*/
	{.bitmap_index = 615752, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(神)*/
	{.bitmap_index = 615890, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祟)*/
	{.bitmap_index = 616028, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祠)*/
	{.bitmap_index = 616166, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祢)*/
	{.bitmap_index = 616304, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祥)*/
	{.bitmap_index = 616442, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(祧)*/
	{.bitmap_index = 616586, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(票)*/
	{.bitmap_index = 616718, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祭)*/
	{.bitmap_index = 616856, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祯)*/
	{.bitmap_index = 616994, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祷)*/
	{.bitmap_index = 617132, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(祸)*/
	{.bitmap_index = 617270, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(祺)*/
	{.bitmap_index = 617414, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(禀)*/
	{.bitmap_index = 617552, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禁)*/
	{.bitmap_index = 617690, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禄)*/
	{.bitmap_index = 617828, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禅)*/
	{.bitmap_index = 617966, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(禊)*/
	{.bitmap_index = 618110, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(福)*/
	{.bitmap_index = 618248, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禚)*/
	{.bitmap_index = 618392, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禧)*/
	{.bitmap_index = 618530, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(禳)*/
	{.bitmap_index = 618674, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(禹)*/
	{.bitmap_index = 618789, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(禺)*/
	{.bitmap_index = 618899, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(离)*/
	{.bitmap_index = 619037, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禽)*/
	{.bitmap_index = 619175, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(禾)*/
	{.bitmap_index = 619313, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秀)*/
	{.bitmap_index = 619457, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(私)*/
	{.bitmap_index = 619595, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秃)*/
	{.bitmap_index = 619739, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秆)*/
	{.bitmap_index = 619877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秉)*/
	{.bitmap_index = 620015, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秋)*/
	{.bitmap_index = 620159, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(种)*/
	{.bitmap_index = 620297, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(科)*/
	{.bitmap_index = 620435, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秒)*/
	{.bitmap_index = 620579, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秕)*/
	{.bitmap_index = 620717, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秘)*/
	{.bitmap_index = 620855, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(租)*/
	{.bitmap_index = 620993, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秣)*/
	{.bitmap_index = 621131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秤)*/
	{.bitmap_index = 621269, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秦)*/
	{.bitmap_index = 621407, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秧)*/
	{.bitmap_index = 621551, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秩)*/
	{.bitmap_index = 621695, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秫)*/
	{.bitmap_index = 621833, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秭)*/
	{.bitmap_index = 621971, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(积)*/
	{.bitmap_index = 622103, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(称)*/
	{.bitmap_index = 622241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(秸)*/
	{.bitmap_index = 622379, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(移)*/
	{.bitmap_index = 622523, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(秽)*/
	{.bitmap_index = 622667, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稀)*/
	{.bitmap_index = 622811, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(稂)*/
	{.bitmap_index = 622955, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稃)*/
	{.bitmap_index = 623093, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稆)*/
	{.bitmap_index = 623231, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(程)*/
	{.bitmap_index = 623369, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稍)*/
	{.bitmap_index = 623507, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(税)*/
	{.bitmap_index = 623651, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稔)*/
	{.bitmap_index = 623789, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稗)*/
	{.bitmap_index = 623927, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稚)*/
	{.bitmap_index = 624065, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稞)*/
	{.bitmap_index = 624203, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稠)*/
	{.bitmap_index = 624341, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稣)*/
	{.bitmap_index = 624479, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稳)*/
	{.bitmap_index = 624623, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(稷)*/
	{.bitmap_index = 624761, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(稹)*/
	{.bitmap_index = 624905, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稻)*/
	{.bitmap_index = 625043, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稼)*/
	{.bitmap_index = 625181, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稽)*/
	{.bitmap_index = 625319, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(稿)*/
	{.bitmap_index = 625457, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(穆)*/
	{.bitmap_index = 625601, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(穑)*/
	{.bitmap_index = 625739, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(穗)*/
	{.bitmap_index = 625877, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(穰)*/
	{.bitmap_index = 626021, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(穴)*/
	{.bitmap_index = 626165, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(究)*/
	{.bitmap_index = 626309, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(穷)*/
	{.bitmap_index = 626453, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(穸)*/
	{.bitmap_index = 626597, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(穹)*/
	{.bitmap_index = 626735, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(空)*/
	{.bitmap_index = 626873, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(穿)*/
	{.bitmap_index = 627011, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窀)*/
	{.bitmap_index = 627149, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(突)*/
	{.bitmap_index = 627293, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(窃)*/
	{.bitmap_index = 627437, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窄)*/
	{.bitmap_index = 627575, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(窆)*/
	{.bitmap_index = 627713, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窈)*/
	{.bitmap_index = 627851, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窍)*/
	{.bitmap_index = 627989, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窑)*/
	{.bitmap_index = 628127, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窒)*/
	{.bitmap_index = 628265, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(窕)*/
	{.bitmap_index = 628409, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窖)*/
	{.bitmap_index = 628547, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窗)*/
	{.bitmap_index = 628685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(窘)*/
	{.bitmap_index = 628823, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窜)*/
	{.bitmap_index = 628961, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窝)*/
	{.bitmap_index = 629099, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(窟)*/
	{.bitmap_index = 629237, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窠)*/
	{.bitmap_index = 629375, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(窥)*/
	{.bitmap_index = 629519, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(窦)*/
	{.bitmap_index = 629663, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窨)*/
	{.bitmap_index = 629801, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(窬)*/
	{.bitmap_index = 629939, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(窭)*/
	{.bitmap_index = 630083, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(窳)*/
	{.bitmap_index = 630227, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(窿)*/
	{.bitmap_index = 630365, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(立)*/
	{.bitmap_index = 630497, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(竖)*/
	{.bitmap_index = 630635, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(站)*/
	{.bitmap_index = 630773, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(竞)*/
	{.bitmap_index = 630917, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(竟)*/
	{.bitmap_index = 631061, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(章)*/
	{.bitmap_index = 631205, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(竣)*/
	{.bitmap_index = 631349, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(童)*/
	{.bitmap_index = 631487, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(竦)*/
	{.bitmap_index = 631625, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(竭)*/
	{.bitmap_index = 631763, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(端)*/
	{.bitmap_index = 631901, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(竹)*/
	{.bitmap_index = 632039, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(竺)*/
	{.bitmap_index = 632171, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(竽)*/
	{.bitmap_index = 632309, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(竿)*/
	{.bitmap_index = 632447, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笃)*/
	{.bitmap_index = 632585, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(笄)*/
	{.bitmap_index = 632729, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笆)*/
	{.bitmap_index = 632867, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笈)*/
	{.bitmap_index = 633011, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笊)*/
	{.bitmap_index = 633155, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(笋)*/
	{.bitmap_index = 633299, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笏)*/
	{.bitmap_index = 633443, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笑)*/
	{.bitmap_index = 633593, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笔)*/
	{.bitmap_index = 633731, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笕)*/
	{.bitmap_index = 633875, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笙)*/
	{.bitmap_index = 634013, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(笛)*/
	{.bitmap_index = 634151, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笞)*/
	{.bitmap_index = 634289, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笠)*/
	{.bitmap_index = 634427, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笤)*/
	{.bitmap_index = 634565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笥)*/
	{.bitmap_index = 634703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(符)*/
	{.bitmap_index = 634841, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笨)*/
	{.bitmap_index = 634979, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笪)*/
	{.bitmap_index = 635117, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笫)*/
	{.bitmap_index = 635255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(第)*/
	{.bitmap_index = 635399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笮)*/
	{.bitmap_index = 635537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笱)*/
	{.bitmap_index = 635675, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笳)*/
	{.bitmap_index = 635819, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笸)*/
	{.bitmap_index = 635957, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笺)*/
	{.bitmap_index = 636095, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(笼)*/
	{.bitmap_index = 636239, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(笾)*/
	{.bitmap_index = 636377, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(筅)*/
	{.bitmap_index = 636521, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筇)*/
	{.bitmap_index = 636659, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(等)*/
	{.bitmap_index = 636797, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(筋)*/
	{.bitmap_index = 636941, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筌)*/
	{.bitmap_index = 637079, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筏)*/
	{.bitmap_index = 637217, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(筐)*/
	{.bitmap_index = 637355, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(筑)*/
	{.bitmap_index = 637499, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筒)*/
	{.bitmap_index = 637637, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(答)*/
	{.bitmap_index = 637775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(策)*/
	{.bitmap_index = 637913, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(筘)*/
	{.bitmap_index = 638051, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筚)*/
	{.bitmap_index = 638189, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(筛)*/
	{.bitmap_index = 638333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筝)*/
	{.bitmap_index = 638471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筠)*/
	{.bitmap_index = 638609, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(筢)*/
	{.bitmap_index = 638747, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(筮)*/
	{.bitmap_index = 638885, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(筱)*/
	{.bitmap_index = 639029, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(筲)*/
	{.bitmap_index = 639167, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(筵)*/
	{.bitmap_index = 639317, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(筷)*/
	{.bitmap_index = 639461, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(筹)*/
	{.bitmap_index = 639605, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(筻)*/
	{.bitmap_index = 639749, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(签)*/
	{.bitmap_index = 639887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(简)*/
	{.bitmap_index = 640025, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(箅)*/
	{.bitmap_index = 640169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箍)*/
	{.bitmap_index = 640307, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(箐)*/
	{.bitmap_index = 640445, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(箔)*/
	{.bitmap_index = 640589, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(箕)*/
	{.bitmap_index = 640733, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(算)*/
	{.bitmap_index = 640877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箜)*/
	{.bitmap_index = 641015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箝)*/
	{.bitmap_index = 641153, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(管)*/
	{.bitmap_index = 641297, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(箢)*/
	{.bitmap_index = 641441, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(箦)*/
	{.bitmap_index = 641585, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(箧)*/
	{.bitmap_index = 641723, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箨)*/
	{.bitmap_index = 641867, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(箩)*/
	{.bitmap_index = 642011, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(箪)*/
	{.bitmap_index = 642155, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(箫)*/
	{.bitmap_index = 642299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箬)*/
	{.bitmap_index = 642437, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箭)*/
	{.bitmap_index = 642575, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箱)*/
	{.bitmap_index = 642713, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(箴)*/
	{.bitmap_index = 642857, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(箸)*/
	{.bitmap_index = 642995, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(篁)*/
	{.bitmap_index = 643133, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(篆)*/
	{.bitmap_index = 643271, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(篇)*/
	{.bitmap_index = 643409, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篌)*/
	{.bitmap_index = 643553, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篑)*/
	{.bitmap_index = 643703, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篓)*/
	{.bitmap_index = 643847, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(篙)*/
	{.bitmap_index = 643991, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(篚)*/
	{.bitmap_index = 644129, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(篝)*/
	{.bitmap_index = 644273, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篡)*/
	{.bitmap_index = 644423, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(篥)*/
	{.bitmap_index = 644567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(篦)*/
	{.bitmap_index = 644705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篪)*/
	{.bitmap_index = 644849, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(篮)*/
	{.bitmap_index = 644987, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(篱)*/
	{.bitmap_index = 645131, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(篷)*/
	{.bitmap_index = 645275, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篼)*/
	{.bitmap_index = 645419, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(篾)*/
	{.bitmap_index = 645563, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(簇)*/
	{.bitmap_index = 645713, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(簋)*/
	{.bitmap_index = 645851, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(簌)*/
	{.bitmap_index = 645995, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(簏)*/
	{.bitmap_index = 646139, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(簖)*/
	{.bitmap_index = 646283, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(簟)*/
	{.bitmap_index = 646421, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(簦)*/
	{.bitmap_index = 646559, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(簧)*/
	{.bitmap_index = 646709, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(簪)*/
	{.bitmap_index = 646847, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(簸)*/
	{.bitmap_index = 646991, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(簿)*/
	{.bitmap_index = 647129, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(籀)*/
	{.bitmap_index = 647273, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(籁)*/
	{.bitmap_index = 647423, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(籍)*/
	{.bitmap_index = 647567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(米)*/
	{.bitmap_index = 647705, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(籴)*/
	{.bitmap_index = 647843, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(类)*/
	{.bitmap_index = 647987, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(籼)*/
	{.bitmap_index = 648125, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(籽)*/
	{.bitmap_index = 648263, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(粉)*/
	{.bitmap_index = 648407, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粑)*/
	{.bitmap_index = 648545, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粒)*/
	{.bitmap_index = 648683, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粕)*/
	{.bitmap_index = 648821, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粗)*/
	{.bitmap_index = 648959, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粘)*/
	{.bitmap_index = 649097, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(粜)*/
	{.bitmap_index = 649241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粝)*/
	{.bitmap_index = 649379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粞)*/
	{.bitmap_index = 649517, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粟)*/
	{.bitmap_index = 649649, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粢)*/
	{.bitmap_index = 649787, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(粤)*/
	{.bitmap_index = 649925, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(粥)*/
	{.bitmap_index = 650063, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(粪)*/
	{.bitmap_index = 650213, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(粮)*/
	{.bitmap_index = 650357, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粱)*/
	{.bitmap_index = 650495, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粲)*/
	{.bitmap_index = 650633, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(粳)*/
	{.bitmap_index = 650777, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粹)*/
	{.bitmap_index = 650915, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(粼)*/
	{.bitmap_index = 651059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(粽)*/
	{.bitmap_index = 651197, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(精)*/
	{.bitmap_index = 651335, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(糁)*/
	{.bitmap_index = 651479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糅)*/
	{.bitmap_index = 651617, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(糇)*/
	{.bitmap_index = 651761, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糈)*/
	{.bitmap_index = 651899, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(糊)*/
	{.bitmap_index = 652043, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糌)*/
	{.bitmap_index = 652181, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糍)*/
	{.bitmap_index = 652319, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糕)*/
	{.bitmap_index = 652457, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糖)*/
	{.bitmap_index = 652595, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(糗)*/
	{.bitmap_index = 652739, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糙)*/
	{.bitmap_index = 652877, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(糜)*/
	{.bitmap_index = 653021, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糟)*/
	{.bitmap_index = 653159, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糠)*/
	{.bitmap_index = 653297, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糨)*/
	{.bitmap_index = 653435, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糯)*/
	{.bitmap_index = 653573, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(糸)*/
	{.bitmap_index = 653711, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(系)*/
	{.bitmap_index = 653849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(紊)*/
	{.bitmap_index = 653987, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(素)*/
	{.bitmap_index = 654125, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(索)*/
	{.bitmap_index = 654263, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(紧)*/
	{.bitmap_index = 654401, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(紫)*/
	{.bitmap_index = 654539, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(累)*/
	{.bitmap_index = 654671, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(絮)*/
	{.bitmap_index = 654809, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(絷)*/
	{.bitmap_index = 654953, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(綦)*/
	{.bitmap_index = 655091, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(綮)*/
	{.bitmap_index = 655229, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(縻)*/
	{.bitmap_index = 655367, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(繁)*/
	{.bitmap_index = 655505, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(繇)*/
	{.bitmap_index = 655643, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纂)*/
	{.bitmap_index = 655787, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(纛)*/
	{.bitmap_index = 655931, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(纟)*/
	{.bitmap_index = 656019, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纠)*/
	{.bitmap_index = 656157, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纡)*/
	{.bitmap_index = 656295, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(红)*/
	{.bitmap_index = 656427, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纣)*/
	{.bitmap_index = 656565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纤)*/
	{.bitmap_index = 656703, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纥)*/
	{.bitmap_index = 656841, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(约)*/
	{.bitmap_index = 656979, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(级)*/
	{.bitmap_index = 657123, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(纨)*/
	{.bitmap_index = 657267, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(纩)*/
	{.bitmap_index = 657411, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纪)*/
	{.bitmap_index = 657549, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(纫)*/
	{.bitmap_index = 657693, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纬)*/
	{.bitmap_index = 657831, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纭)*/
	{.bitmap_index = 657969, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纯)*/
	{.bitmap_index = 658107, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纰)*/
	{.bitmap_index = 658245, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(纱)*/
	{.bitmap_index = 658389, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纲)*/
	{.bitmap_index = 658527, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纳)*/
	{.bitmap_index = 658665, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纵)*/
	{.bitmap_index = 658803, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纶)*/
	{.bitmap_index = 658941, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(纷)*/
	{.bitmap_index = 659085, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纸)*/
	{.bitmap_index = 659223, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(纹)*/
	{.bitmap_index = 659367, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(纺)*/
	{.bitmap_index = 659505, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纽)*/
	{.bitmap_index = 659643, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(纾)*/
	{.bitmap_index = 659781, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(线)*/
	{.bitmap_index = 659925, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绀)*/
	{.bitmap_index = 660063, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(绁)*/
	{.bitmap_index = 660195, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绂)*/
	{.bitmap_index = 660339, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(练)*/
	{.bitmap_index = 660477, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(组)*/
	{.bitmap_index = 660615, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(绅)*/
	{.bitmap_index = 660753, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(细)*/
	{.bitmap_index = 660885, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(织)*/
	{.bitmap_index = 661029, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(终)*/
	{.bitmap_index = 661173, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绉)*/
	{.bitmap_index = 661311, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绊)*/
	{.bitmap_index = 661449, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绋)*/
	{.bitmap_index = 661593, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绌)*/
	{.bitmap_index = 661731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绍)*/
	{.bitmap_index = 661869, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绎)*/
	{.bitmap_index = 662007, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(经)*/
	{.bitmap_index = 662139, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绐)*/
	{.bitmap_index = 662277, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绑)*/
	{.bitmap_index = 662421, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绒)*/
	{.bitmap_index = 662565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(结)*/
	{.bitmap_index = 662703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绔)*/
	{.bitmap_index = 662841, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绕)*/
	{.bitmap_index = 662985, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绗)*/
	{.bitmap_index = 663123, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绘)*/
	{.bitmap_index = 663261, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(给)*/
	{.bitmap_index = 663399, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(绚)*/
	{.bitmap_index = 663537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绛)*/
	{.bitmap_index = 663675, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(络)*/
	{.bitmap_index = 663819, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绝)*/
	{.bitmap_index = 663957, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(绞)*/
	{.bitmap_index = 664101, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(统)*/
	{.bitmap_index = 664245, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绠)*/
	{.bitmap_index = 664389, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(绡)*/
	{.bitmap_index = 664527, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绢)*/
	{.bitmap_index = 664665, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绣)*/
	{.bitmap_index = 664809, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绥)*/
	{.bitmap_index = 664953, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(绦)*/
	{.bitmap_index = 665091, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(继)*/
	{.bitmap_index = 665229, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绨)*/
	{.bitmap_index = 665367, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绩)*/
	{.bitmap_index = 665511, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绪)*/
	{.bitmap_index = 665649, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绫)*/
	{.bitmap_index = 665793, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(续)*/
	{.bitmap_index = 665937, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绮)*/
	{.bitmap_index = 666075, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绯)*/
	{.bitmap_index = 666213, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(绰)*/
	{.bitmap_index = 666351, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绱)*/
	{.bitmap_index = 666489, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绲)*/
	{.bitmap_index = 666627, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绳)*/
	{.bitmap_index = 666765, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(维)*/
	{.bitmap_index = 666903, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(绵)*/
	{.bitmap_index = 667041, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绶)*/
	{.bitmap_index = 667185, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绷)*/
	{.bitmap_index = 667323, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(绸)*/
	{.bitmap_index = 667467, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绺)*/
	{.bitmap_index = 667605, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绻)*/
	{.bitmap_index = 667743, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(综)*/
	{.bitmap_index = 667881, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绽)*/
	{.bitmap_index = 668019, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绾)*/
	{.bitmap_index = 668157, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(绿)*/
	{.bitmap_index = 668295, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缀)*/
	{.bitmap_index = 668433, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缁)*/
	{.bitmap_index = 668571, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缂)*/
	{.bitmap_index = 668709, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(缃)*/
	{.bitmap_index = 668847, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缄)*/
	{.bitmap_index = 668991, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缅)*/
	{.bitmap_index = 669129, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缆)*/
	{.bitmap_index = 669273, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缇)*/
	{.bitmap_index = 669417, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缈)*/
	{.bitmap_index = 669561, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(缉)*/
	{.bitmap_index = 669699, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缋)*/
	{.bitmap_index = 669843, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缌)*/
	{.bitmap_index = 669981, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缍)*/
	{.bitmap_index = 670119, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缎)*/
	{.bitmap_index = 670263, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缏)*/
	{.bitmap_index = 670401, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缑)*/
	{.bitmap_index = 670545, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缒)*/
	{.bitmap_index = 670683, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缓)*/
	{.bitmap_index = 670827, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缔)*/
	{.bitmap_index = 670965, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缕)*/
	{.bitmap_index = 671103, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(编)*/
	{.bitmap_index = 671241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缗)*/
	{.bitmap_index = 671379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缘)*/
	{.bitmap_index = 671517, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缙)*/
	{.bitmap_index = 671655, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缚)*/
	{.bitmap_index = 671793, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缛)*/
	{.bitmap_index = 671931, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缜)*/
	{.bitmap_index = 672075, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缝)*/
	{.bitmap_index = 672213, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(缟)*/
	{.bitmap_index = 672351, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缠)*/
	{.bitmap_index = 672489, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缡)*/
	{.bitmap_index = 672627, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(缢)*/
	{.bitmap_index = 672759, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缣)*/
	{.bitmap_index = 672897, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缤)*/
	{.bitmap_index = 673041, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缥)*/
	{.bitmap_index = 673179, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缦)*/
	{.bitmap_index = 673323, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缧)*/
	{.bitmap_index = 673461, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缨)*/
	{.bitmap_index = 673605, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缩)*/
	{.bitmap_index = 673743, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(缪)*/
	{.bitmap_index = 673887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缫)*/
	{.bitmap_index = 674025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缬)*/
	{.bitmap_index = 674163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缭)*/
	{.bitmap_index = 674301, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缮)*/
	{.bitmap_index = 674439, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缯)*/
	{.bitmap_index = 674577, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缰)*/
	{.bitmap_index = 674715, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缱)*/
	{.bitmap_index = 674853, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(缲)*/
	{.bitmap_index = 674991, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缳)*/
	{.bitmap_index = 675135, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缴)*/
	{.bitmap_index = 675279, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缵)*/
	{.bitmap_index = 675423, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(缶)*/
	{.bitmap_index = 675567, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(缸)*/
	{.bitmap_index = 675699, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(缺)*/
	{.bitmap_index = 675843, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罂)*/
	{.bitmap_index = 675981, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(罄)*/
	{.bitmap_index = 676119, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(罅)*/
	{.bitmap_index = 676257, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(罐)*/
	{.bitmap_index = 676395, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(网)*/
	{.bitmap_index = 676505, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(罔)*/
	{.bitmap_index = 676615, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罕)*/
	{.bitmap_index = 676747, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(罗)*/
	{.bitmap_index = 676885, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(罘)*/
	{.bitmap_index = 677017, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罚)*/
	{.bitmap_index = 677149, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罟)*/
	{.bitmap_index = 677281, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罡)*/
	{.bitmap_index = 677413, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罢)*/
	{.bitmap_index = 677545, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(罨)*/
	{.bitmap_index = 677677, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罩)*/
	{.bitmap_index = 677809, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罪)*/
	{.bitmap_index = 677941, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(置)*/
	{.bitmap_index = 678073, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(罱)*/
	{.bitmap_index = 678205, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(署)*/
	{.bitmap_index = 678343, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(罴)*/
	{.bitmap_index = 678481, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(罹)*/
	{.bitmap_index = 678613, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(罾)*/
	{.bitmap_index = 678723, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(羁)*/
	{.bitmap_index = 678855, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(羊)*/
	{.bitmap_index = 678999, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(羌)*/
	{.bitmap_index = 679149, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(美)*/
	{.bitmap_index = 679299, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羔)*/
	{.bitmap_index = 679443, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羚)*/
	{.bitmap_index = 679593, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羝)*/
	{.bitmap_index = 679737, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(羞)*/
	{.bitmap_index = 679875, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羟)*/
	{.bitmap_index = 680019, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羡)*/
	{.bitmap_index = 680169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(群)*/
	{.bitmap_index = 680307, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羧)*/
	{.bitmap_index = 680451, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羯)*/
	{.bitmap_index = 680595, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羰)*/
	{.bitmap_index = 680739, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(羲)*/
	{.bitmap_index = 680883, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(羸)*/
	{.bitmap_index = 681027, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羹)*/
	{.bitmap_index = 681177, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(羼)*/
	{.bitmap_index = 681315, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(羽)*/
	{.bitmap_index = 681447, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(羿)*/
	{.bitmap_index = 681585, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翁)*/
	{.bitmap_index = 681729, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翅)*/
	{.bitmap_index = 681867, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翊)*/
	{.bitmap_index = 682005, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翌)*/
	{.bitmap_index = 682137, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翎)*/
	{.bitmap_index = 682275, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(翔)*/
	{.bitmap_index = 682419, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翕)*/
	{.bitmap_index = 682557, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翘)*/
	{.bitmap_index = 682695, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翟)*/
	{.bitmap_index = 682827, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翠)*/
	{.bitmap_index = 682959, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翡)*/
	{.bitmap_index = 683097, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翥)*/
	{.bitmap_index = 683235, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翦)*/
	{.bitmap_index = 683379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翩)*/
	{.bitmap_index = 683517, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翮)*/
	{.bitmap_index = 683649, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翰)*/
	{.bitmap_index = 683787, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翱)*/
	{.bitmap_index = 683925, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(翳)*/
	{.bitmap_index = 684057, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(翻)*/
	{.bitmap_index = 684195, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(翼)*/
	{.bitmap_index = 684333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耀)*/
	{.bitmap_index = 684471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(老)*/
	{.bitmap_index = 684609, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(考)*/
	{.bitmap_index = 684747, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耄)*/
	{.bitmap_index = 684885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(者)*/
	{.bitmap_index = 685023, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耆)*/
	{.bitmap_index = 685161, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耋)*/
	{.bitmap_index = 685299, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(而)*/
	{.bitmap_index = 685431, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(耍)*/
	{.bitmap_index = 685569, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耐)*/
	{.bitmap_index = 685707, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耒)*/
	{.bitmap_index = 685845, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耔)*/
	{.bitmap_index = 685983, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(耕)*/
	{.bitmap_index = 686127, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(耖)*/
	{.bitmap_index = 686271, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耗)*/
	{.bitmap_index = 686409, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耘)*/
	{.bitmap_index = 686547, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耙)*/
	{.bitmap_index = 686685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耜)*/
	{.bitmap_index = 686823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耠)*/
	{.bitmap_index = 686961, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(耢)*/
	{.bitmap_index = 687105, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耥)*/
	{.bitmap_index = 687243, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耦)*/
	{.bitmap_index = 687381, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(耧)*/
	{.bitmap_index = 687525, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耨)*/
	{.bitmap_index = 687663, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耩)*/
	{.bitmap_index = 687801, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(耪)*/
	{.bitmap_index = 687945, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耱)*/
	{.bitmap_index = 688083, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耳)*/
	{.bitmap_index = 688215, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耵)*/
	{.bitmap_index = 688347, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(耶)*/
	{.bitmap_index = 688479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耷)*/
	{.bitmap_index = 688617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耸)*/
	{.bitmap_index = 688755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耻)*/
	{.bitmap_index = 688893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耽)*/
	{.bitmap_index = 689031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(耿)*/
	{.bitmap_index = 689169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(聂)*/
	{.bitmap_index = 689307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聃)*/
	{.bitmap_index = 689445, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(聆)*/
	{.bitmap_index = 689589, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(聊)*/
	{.bitmap_index = 689733, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(聋)*/
	{.bitmap_index = 689871, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(职)*/
	{.bitmap_index = 690009, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聍)*/
	{.bitmap_index = 690147, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聒)*/
	{.bitmap_index = 690285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(联)*/
	{.bitmap_index = 690423, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(聘)*/
	{.bitmap_index = 690561, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聚)*/
	{.bitmap_index = 690693, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聩)*/
	{.bitmap_index = 690831, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聪)*/
	{.bitmap_index = 690969, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(聱)*/
	{.bitmap_index = 691107, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(聿)*/
	{.bitmap_index = 691245, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(肀)*/
	{.bitmap_index = 691383, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肃)*/
	{.bitmap_index = 691527, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肄)*/
	{.bitmap_index = 691671, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肆)*/
	{.bitmap_index = 691809, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肇)*/
	{.bitmap_index = 691953, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(肉)*/
	{.bitmap_index = 692068, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肋)*/
	{.bitmap_index = 692206, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肌)*/
	{.bitmap_index = 692344, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(肓)*/
	{.bitmap_index = 692482, .adv_w = 23, .box_h = 23, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(肖)*/
	{.bitmap_index = 692597, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肘)*/
	{.bitmap_index = 692741, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肚)*/
	{.bitmap_index = 692885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肛)*/
	{.bitmap_index = 693023, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肜)*/
	{.bitmap_index = 693167, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肝)*/
	{.bitmap_index = 693299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肟)*/
	{.bitmap_index = 693437, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肠)*/
	{.bitmap_index = 693575, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(股)*/
	{.bitmap_index = 693713, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肢)*/
	{.bitmap_index = 693857, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肤)*/
	{.bitmap_index = 694001, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肥)*/
	{.bitmap_index = 694133, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肩)*/
	{.bitmap_index = 694271, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肪)*/
	{.bitmap_index = 694415, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肫)*/
	{.bitmap_index = 694559, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肭)*/
	{.bitmap_index = 694697, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肮)*/
	{.bitmap_index = 694841, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(肯)*/
	{.bitmap_index = 694979, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肱)*/
	{.bitmap_index = 695117, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(育)*/
	{.bitmap_index = 695255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肴)*/
	{.bitmap_index = 695399, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肷)*/
	{.bitmap_index = 695543, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(肺)*/
	{.bitmap_index = 695681, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肼)*/
	{.bitmap_index = 695825, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肽)*/
	{.bitmap_index = 695969, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(肾)*/
	{.bitmap_index = 696107, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(肿)*/
	{.bitmap_index = 696251, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胀)*/
	{.bitmap_index = 696395, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胁)*/
	{.bitmap_index = 696533, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胂)*/
	{.bitmap_index = 696671, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(胃)*/
	{.bitmap_index = 696781, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(胄)*/
	{.bitmap_index = 696901, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胆)*/
	{.bitmap_index = 697039, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(背)*/
	{.bitmap_index = 697177, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胍)*/
	{.bitmap_index = 697315, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胎)*/
	{.bitmap_index = 697459, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胖)*/
	{.bitmap_index = 697603, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胗)*/
	{.bitmap_index = 697747, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胙)*/
	{.bitmap_index = 697891, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胚)*/
	{.bitmap_index = 698023, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胛)*/
	{.bitmap_index = 698161, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胜)*/
	{.bitmap_index = 698299, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胝)*/
	{.bitmap_index = 698443, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胞)*/
	{.bitmap_index = 698581, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(胡)*/
	{.bitmap_index = 698725, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胤)*/
	{.bitmap_index = 698863, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胥)*/
	{.bitmap_index = 698995, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胧)*/
	{.bitmap_index = 699139, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胨)*/
	{.bitmap_index = 699277, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胩)*/
	{.bitmap_index = 699421, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胪)*/
	{.bitmap_index = 699565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胫)*/
	{.bitmap_index = 699703, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胬)*/
	{.bitmap_index = 699847, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胭)*/
	{.bitmap_index = 699979, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胯)*/
	{.bitmap_index = 700123, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胰)*/
	{.bitmap_index = 700267, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胱)*/
	{.bitmap_index = 700411, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胲)*/
	{.bitmap_index = 700555, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胳)*/
	{.bitmap_index = 700693, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胴)*/
	{.bitmap_index = 700825, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胶)*/
	{.bitmap_index = 700969, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胸)*/
	{.bitmap_index = 701107, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(胺)*/
	{.bitmap_index = 701245, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(胼)*/
	{.bitmap_index = 701389, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(能)*/
	{.bitmap_index = 701527, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脂)*/
	{.bitmap_index = 701665, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脆)*/
	{.bitmap_index = 701809, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脉)*/
	{.bitmap_index = 701959, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脊)*/
	{.bitmap_index = 702097, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脍)*/
	{.bitmap_index = 702235, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脎)*/
	{.bitmap_index = 702373, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脏)*/
	{.bitmap_index = 702511, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脐)*/
	{.bitmap_index = 702655, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脑)*/
	{.bitmap_index = 702793, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脒)*/
	{.bitmap_index = 702931, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脓)*/
	{.bitmap_index = 703069, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脔)*/
	{.bitmap_index = 703213, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脖)*/
	{.bitmap_index = 703351, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脘)*/
	{.bitmap_index = 703495, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脚)*/
	{.bitmap_index = 703633, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脞)*/
	{.bitmap_index = 703771, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脬)*/
	{.bitmap_index = 703909, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脯)*/
	{.bitmap_index = 704053, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脱)*/
	{.bitmap_index = 704191, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(脲)*/
	{.bitmap_index = 704329, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脶)*/
	{.bitmap_index = 704461, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脸)*/
	{.bitmap_index = 704599, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(脾)*/
	{.bitmap_index = 704737, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腆)*/
	{.bitmap_index = 704881, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腈)*/
	{.bitmap_index = 705019, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腊)*/
	{.bitmap_index = 705157, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腋)*/
	{.bitmap_index = 705301, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腌)*/
	{.bitmap_index = 705439, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腐)*/
	{.bitmap_index = 705577, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腑)*/
	{.bitmap_index = 705715, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腓)*/
	{.bitmap_index = 705859, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腔)*/
	{.bitmap_index = 705997, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腕)*/
	{.bitmap_index = 706135, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腙)*/
	{.bitmap_index = 706279, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腚)*/
	{.bitmap_index = 706417, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腠)*/
	{.bitmap_index = 706555, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腥)*/
	{.bitmap_index = 706687, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腧)*/
	{.bitmap_index = 706825, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腩)*/
	{.bitmap_index = 706963, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腭)*/
	{.bitmap_index = 707095, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腮)*/
	{.bitmap_index = 707227, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腰)*/
	{.bitmap_index = 707365, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腱)*/
	{.bitmap_index = 707503, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腴)*/
	{.bitmap_index = 707641, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腹)*/
	{.bitmap_index = 707785, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腺)*/
	{.bitmap_index = 707923, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(腻)*/
	{.bitmap_index = 708067, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腼)*/
	{.bitmap_index = 708199, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腽)*/
	{.bitmap_index = 708331, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腾)*/
	{.bitmap_index = 708469, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(腿)*/
	{.bitmap_index = 708607, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膀)*/
	{.bitmap_index = 708751, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膂)*/
	{.bitmap_index = 708889, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膈)*/
	{.bitmap_index = 709021, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膊)*/
	{.bitmap_index = 709159, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(膏)*/
	{.bitmap_index = 709297, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膑)*/
	{.bitmap_index = 709435, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膘)*/
	{.bitmap_index = 709567, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膛)*/
	{.bitmap_index = 709711, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膜)*/
	{.bitmap_index = 709855, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膝)*/
	{.bitmap_index = 709993, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膣)*/
	{.bitmap_index = 710137, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膦)*/
	{.bitmap_index = 710281, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膨)*/
	{.bitmap_index = 710425, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膪)*/
	{.bitmap_index = 710563, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(膳)*/
	{.bitmap_index = 710707, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膺)*/
	{.bitmap_index = 710845, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(膻)*/
	{.bitmap_index = 710983, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(臀)*/
	{.bitmap_index = 711121, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(臁)*/
	{.bitmap_index = 711265, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(臂)*/
	{.bitmap_index = 711403, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(臃)*/
	{.bitmap_index = 711547, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(臆)*/
	{.bitmap_index = 711685, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(臊)*/
	{.bitmap_index = 711817, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(臌)*/
	{.bitmap_index = 711961, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(臣)*/
	{.bitmap_index = 712093, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(臧)*/
	{.bitmap_index = 712237, .adv_w = 23, .box_h = 23, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(自)*/
	{.bitmap_index = 712352, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(臬)*/
	{.bitmap_index = 712490, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(臭)*/
	{.bitmap_index = 712634, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(至)*/
	{.bitmap_index = 712766, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(致)*/
	{.bitmap_index = 712910, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(臻)*/
	{.bitmap_index = 713048, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 6},/*(臼)*/
	{.bitmap_index = 713158, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(臾)*/
	{.bitmap_index = 713302, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(舀)*/
	{.bitmap_index = 713417, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(舁)*/
	{.bitmap_index = 713567, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舂)*/
	{.bitmap_index = 713705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舄)*/
	{.bitmap_index = 713849, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(舅)*/
	{.bitmap_index = 713993, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(舆)*/
	{.bitmap_index = 714137, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(舌)*/
	{.bitmap_index = 714275, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舍)*/
	{.bitmap_index = 714413, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(舐)*/
	{.bitmap_index = 714551, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舒)*/
	{.bitmap_index = 714689, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(舔)*/
	{.bitmap_index = 714821, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舛)*/
	{.bitmap_index = 714965, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舜)*/
	{.bitmap_index = 715109, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舞)*/
	{.bitmap_index = 715259, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(舟)*/
	{.bitmap_index = 715403, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舡)*/
	{.bitmap_index = 715547, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舢)*/
	{.bitmap_index = 715685, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舣)*/
	{.bitmap_index = 715829, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舨)*/
	{.bitmap_index = 715973, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(航)*/
	{.bitmap_index = 716111, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舫)*/
	{.bitmap_index = 716255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(般)*/
	{.bitmap_index = 716399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舭)*/
	{.bitmap_index = 716537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舯)*/
	{.bitmap_index = 716675, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舰)*/
	{.bitmap_index = 716819, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舱)*/
	{.bitmap_index = 716963, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舳)*/
	{.bitmap_index = 717107, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舴)*/
	{.bitmap_index = 717251, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舵)*/
	{.bitmap_index = 717389, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舶)*/
	{.bitmap_index = 717533, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舷)*/
	{.bitmap_index = 717677, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舸)*/
	{.bitmap_index = 717815, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(船)*/
	{.bitmap_index = 717953, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(舻)*/
	{.bitmap_index = 718097, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(舾)*/
	{.bitmap_index = 718235, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(艄)*/
	{.bitmap_index = 718379, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艇)*/
	{.bitmap_index = 718523, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艉)*/
	{.bitmap_index = 718661, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(艋)*/
	{.bitmap_index = 718805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艏)*/
	{.bitmap_index = 718943, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(艘)*/
	{.bitmap_index = 719087, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艚)*/
	{.bitmap_index = 719225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艟)*/
	{.bitmap_index = 719363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艨)*/
	{.bitmap_index = 719501, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(艮)*/
	{.bitmap_index = 719639, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(良)*/
	{.bitmap_index = 719783, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(艰)*/
	{.bitmap_index = 719921, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(色)*/
	{.bitmap_index = 720065, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(艳)*/
	{.bitmap_index = 720209, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(艴)*/
	{.bitmap_index = 720353, .adv_w = 25, .box_h = 9, .box_w = 24, .ofs_x = 1, .ofs_y = 18},/*(艹)*/
	{.bitmap_index = 720407, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(艺)*/
	{.bitmap_index = 720545, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(艽)*/
	{.bitmap_index = 720689, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(艾)*/
	{.bitmap_index = 720833, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(艿)*/
	{.bitmap_index = 720977, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(节)*/
	{.bitmap_index = 721115, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芄)*/
	{.bitmap_index = 721253, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芈)*/
	{.bitmap_index = 721391, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芊)*/
	{.bitmap_index = 721529, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芋)*/
	{.bitmap_index = 721667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(芍)*/
	{.bitmap_index = 721805, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芎)*/
	{.bitmap_index = 721943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芏)*/
	{.bitmap_index = 722081, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芑)*/
	{.bitmap_index = 722219, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芒)*/
	{.bitmap_index = 722357, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芗)*/
	{.bitmap_index = 722501, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芘)*/
	{.bitmap_index = 722639, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芙)*/
	{.bitmap_index = 722783, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芜)*/
	{.bitmap_index = 722927, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(芝)*/
	{.bitmap_index = 723065, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芟)*/
	{.bitmap_index = 723209, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芡)*/
	{.bitmap_index = 723353, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芤)*/
	{.bitmap_index = 723491, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芥)*/
	{.bitmap_index = 723635, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芦)*/
	{.bitmap_index = 723779, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芨)*/
	{.bitmap_index = 723923, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芩)*/
	{.bitmap_index = 724067, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芪)*/
	{.bitmap_index = 724205, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芫)*/
	{.bitmap_index = 724349, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芬)*/
	{.bitmap_index = 724493, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芭)*/
	{.bitmap_index = 724631, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芮)*/
	{.bitmap_index = 724769, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(芯)*/
	{.bitmap_index = 724907, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芰)*/
	{.bitmap_index = 725051, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(花)*/
	{.bitmap_index = 725189, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芳)*/
	{.bitmap_index = 725333, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(芴)*/
	{.bitmap_index = 725477, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芷)*/
	{.bitmap_index = 725615, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芸)*/
	{.bitmap_index = 725759, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(芹)*/
	{.bitmap_index = 725903, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(芽)*/
	{.bitmap_index = 726041, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(芾)*/
	{.bitmap_index = 726179, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苁)*/
	{.bitmap_index = 726317, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苄)*/
	{.bitmap_index = 726455, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苇)*/
	{.bitmap_index = 726593, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(苈)*/
	{.bitmap_index = 726737, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(苊)*/
	{.bitmap_index = 726881, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苋)*/
	{.bitmap_index = 727019, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(苌)*/
	{.bitmap_index = 727163, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苍)*/
	{.bitmap_index = 727301, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(苎)*/
	{.bitmap_index = 727433, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(苏)*/
	{.bitmap_index = 727577, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(苑)*/
	{.bitmap_index = 727721, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苒)*/
	{.bitmap_index = 727859, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(苓)*/
	{.bitmap_index = 728003, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苔)*/
	{.bitmap_index = 728141, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苕)*/
	{.bitmap_index = 728279, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(苗)*/
	{.bitmap_index = 728411, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苘)*/
	{.bitmap_index = 728549, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苛)*/
	{.bitmap_index = 728687, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苜)*/
	{.bitmap_index = 728825, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苞)*/
	{.bitmap_index = 728963, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苟)*/
	{.bitmap_index = 729101, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(苠)*/
	{.bitmap_index = 729245, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(苡)*/
	{.bitmap_index = 729389, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苣)*/
	{.bitmap_index = 729527, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苤)*/
	{.bitmap_index = 729665, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(若)*/
	{.bitmap_index = 729803, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苦)*/
	{.bitmap_index = 729941, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苫)*/
	{.bitmap_index = 730079, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苯)*/
	{.bitmap_index = 730217, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(英)*/
	{.bitmap_index = 730361, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苴)*/
	{.bitmap_index = 730499, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苷)*/
	{.bitmap_index = 730637, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(苹)*/
	{.bitmap_index = 730775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(苻)*/
	{.bitmap_index = 730913, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茁)*/
	{.bitmap_index = 731051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(茂)*/
	{.bitmap_index = 731195, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(范)*/
	{.bitmap_index = 731333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茄)*/
	{.bitmap_index = 731471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茅)*/
	{.bitmap_index = 731609, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(茆)*/
	{.bitmap_index = 731753, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(茇)*/
	{.bitmap_index = 731897, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茈)*/
	{.bitmap_index = 732035, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茉)*/
	{.bitmap_index = 732173, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茌)*/
	{.bitmap_index = 732311, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茎)*/
	{.bitmap_index = 732449, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茏)*/
	{.bitmap_index = 732587, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茑)*/
	{.bitmap_index = 732725, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茔)*/
	{.bitmap_index = 732863, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茕)*/
	{.bitmap_index = 733001, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茗)*/
	{.bitmap_index = 733139, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茚)*/
	{.bitmap_index = 733277, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(茛)*/
	{.bitmap_index = 733421, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茜)*/
	{.bitmap_index = 733559, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茧)*/
	{.bitmap_index = 733697, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(茨)*/
	{.bitmap_index = 733841, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茫)*/
	{.bitmap_index = 733979, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茬)*/
	{.bitmap_index = 734117, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(茭)*/
	{.bitmap_index = 734261, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(茯)*/
	{.bitmap_index = 734405, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茱)*/
	{.bitmap_index = 734543, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茳)*/
	{.bitmap_index = 734681, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茴)*/
	{.bitmap_index = 734819, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茵)*/
	{.bitmap_index = 734957, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(茶)*/
	{.bitmap_index = 735095, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茸)*/
	{.bitmap_index = 735233, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(茹)*/
	{.bitmap_index = 735377, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(茺)*/
	{.bitmap_index = 735521, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(茼)*/
	{.bitmap_index = 735659, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荀)*/
	{.bitmap_index = 735797, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荃)*/
	{.bitmap_index = 735935, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荆)*/
	{.bitmap_index = 736079, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荇)*/
	{.bitmap_index = 736217, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(草)*/
	{.bitmap_index = 736361, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荏)*/
	{.bitmap_index = 736499, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荐)*/
	{.bitmap_index = 736637, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荑)*/
	{.bitmap_index = 736781, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荒)*/
	{.bitmap_index = 736925, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荔)*/
	{.bitmap_index = 737069, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荚)*/
	{.bitmap_index = 737213, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荛)*/
	{.bitmap_index = 737357, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荜)*/
	{.bitmap_index = 737495, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荞)*/
	{.bitmap_index = 737639, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荟)*/
	{.bitmap_index = 737783, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荠)*/
	{.bitmap_index = 737927, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荡)*/
	{.bitmap_index = 738071, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荣)*/
	{.bitmap_index = 738209, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荤)*/
	{.bitmap_index = 738347, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荥)*/
	{.bitmap_index = 738485, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荦)*/
	{.bitmap_index = 738623, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荧)*/
	{.bitmap_index = 738767, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荨)*/
	{.bitmap_index = 738905, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荩)*/
	{.bitmap_index = 739049, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荪)*/
	{.bitmap_index = 739187, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荫)*/
	{.bitmap_index = 739331, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荬)*/
	{.bitmap_index = 739475, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荭)*/
	{.bitmap_index = 739613, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荮)*/
	{.bitmap_index = 739751, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(药)*/
	{.bitmap_index = 739889, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荷)*/
	{.bitmap_index = 740027, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(荸)*/
	{.bitmap_index = 740165, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(荻)*/
	{.bitmap_index = 740309, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(荼)*/
	{.bitmap_index = 740447, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(荽)*/
	{.bitmap_index = 740591, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(莅)*/
	{.bitmap_index = 740729, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莆)*/
	{.bitmap_index = 740867, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(莉)*/
	{.bitmap_index = 741005, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(莎)*/
	{.bitmap_index = 741149, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莒)*/
	{.bitmap_index = 741287, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莓)*/
	{.bitmap_index = 741425, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莘)*/
	{.bitmap_index = 741563, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(莛)*/
	{.bitmap_index = 741707, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(莜)*/
	{.bitmap_index = 741851, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(莞)*/
	{.bitmap_index = 741995, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(莠)*/
	{.bitmap_index = 742139, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(莨)*/
	{.bitmap_index = 742283, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莩)*/
	{.bitmap_index = 742421, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莪)*/
	{.bitmap_index = 742559, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(莫)*/
	{.bitmap_index = 742703, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(莰)*/
	{.bitmap_index = 742847, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(莱)*/
	{.bitmap_index = 742985, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(莲)*/
	{.bitmap_index = 743123, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莳)*/
	{.bitmap_index = 743261, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莴)*/
	{.bitmap_index = 743399, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(莶)*/
	{.bitmap_index = 743531, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(获)*/
	{.bitmap_index = 743675, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(莸)*/
	{.bitmap_index = 743813, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莹)*/
	{.bitmap_index = 743951, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莺)*/
	{.bitmap_index = 744089, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(莼)*/
	{.bitmap_index = 744227, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(莽)*/
	{.bitmap_index = 744371, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(菀)*/
	{.bitmap_index = 744515, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菁)*/
	{.bitmap_index = 744653, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菅)*/
	{.bitmap_index = 744791, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(菇)*/
	{.bitmap_index = 744935, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(菊)*/
	{.bitmap_index = 745073, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菌)*/
	{.bitmap_index = 745211, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(菏)*/
	{.bitmap_index = 745349, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(菔)*/
	{.bitmap_index = 745493, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菖)*/
	{.bitmap_index = 745631, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(菘)*/
	{.bitmap_index = 745769, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(菜)*/
	{.bitmap_index = 745907, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菝)*/
	{.bitmap_index = 746045, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(菟)*/
	{.bitmap_index = 746189, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(菠)*/
	{.bitmap_index = 746333, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菡)*/
	{.bitmap_index = 746471, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(菥)*/
	{.bitmap_index = 746615, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菩)*/
	{.bitmap_index = 746753, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(菪)*/
	{.bitmap_index = 746891, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菰)*/
	{.bitmap_index = 747029, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(菱)*/
	{.bitmap_index = 747173, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(菲)*/
	{.bitmap_index = 747311, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(菸)*/
	{.bitmap_index = 747455, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(菹)*/
	{.bitmap_index = 747593, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(菽)*/
	{.bitmap_index = 747737, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萁)*/
	{.bitmap_index = 747881, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(萃)*/
	{.bitmap_index = 748019, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(萄)*/
	{.bitmap_index = 748157, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(萆)*/
	{.bitmap_index = 748295, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萋)*/
	{.bitmap_index = 748439, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萌)*/
	{.bitmap_index = 748583, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(萍)*/
	{.bitmap_index = 748721, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萎)*/
	{.bitmap_index = 748865, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(萏)*/
	{.bitmap_index = 749003, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(萑)*/
	{.bitmap_index = 749141, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(萘)*/
	{.bitmap_index = 749279, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萜)*/
	{.bitmap_index = 749423, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萝)*/
	{.bitmap_index = 749567, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萤)*/
	{.bitmap_index = 749711, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(营)*/
	{.bitmap_index = 749849, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(萦)*/
	{.bitmap_index = 749987, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(萧)*/
	{.bitmap_index = 750131, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萨)*/
	{.bitmap_index = 750275, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(萱)*/
	{.bitmap_index = 750413, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(萸)*/
	{.bitmap_index = 750557, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(萼)*/
	{.bitmap_index = 750695, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(落)*/
	{.bitmap_index = 750833, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(葆)*/
	{.bitmap_index = 750971, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(葑)*/
	{.bitmap_index = 751109, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(著)*/
	{.bitmap_index = 751247, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(葙)*/
	{.bitmap_index = 751385, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(葚)*/
	{.bitmap_index = 751523, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(葛)*/
	{.bitmap_index = 751661, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(葜)*/
	{.bitmap_index = 751805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(葡)*/
	{.bitmap_index = 751943, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(董)*/
	{.bitmap_index = 752081, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(葩)*/
	{.bitmap_index = 752219, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(葫)*/
	{.bitmap_index = 752363, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(葬)*/
	{.bitmap_index = 752513, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(葭)*/
	{.bitmap_index = 752657, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(葱)*/
	{.bitmap_index = 752795, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(葳)*/
	{.bitmap_index = 752939, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(葵)*/
	{.bitmap_index = 753083, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(葶)*/
	{.bitmap_index = 753221, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(葸)*/
	{.bitmap_index = 753359, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(葺)*/
	{.bitmap_index = 753497, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蒂)*/
	{.bitmap_index = 753635, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蒇)*/
	{.bitmap_index = 753779, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蒈)*/
	{.bitmap_index = 753917, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蒉)*/
	{.bitmap_index = 754061, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蒋)*/
	{.bitmap_index = 754199, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蒌)*/
	{.bitmap_index = 754343, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蒎)*/
	{.bitmap_index = 754481, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蒗)*/
	{.bitmap_index = 754625, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蒙)*/
	{.bitmap_index = 754769, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蒜)*/
	{.bitmap_index = 754913, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蒡)*/
	{.bitmap_index = 755057, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蒯)*/
	{.bitmap_index = 755195, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蒲)*/
	{.bitmap_index = 755333, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蒴)*/
	{.bitmap_index = 755477, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蒸)*/
	{.bitmap_index = 755621, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蒹)*/
	{.bitmap_index = 755759, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蒺)*/
	{.bitmap_index = 755903, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蒽)*/
	{.bitmap_index = 756041, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蒿)*/
	{.bitmap_index = 756179, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓁)*/
	{.bitmap_index = 756317, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蓄)*/
	{.bitmap_index = 756455, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓉)*/
	{.bitmap_index = 756593, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蓊)*/
	{.bitmap_index = 756731, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓍)*/
	{.bitmap_index = 756869, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓐)*/
	{.bitmap_index = 757007, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蓑)*/
	{.bitmap_index = 757151, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓓)*/
	{.bitmap_index = 757289, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蓖)*/
	{.bitmap_index = 757427, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蓝)*/
	{.bitmap_index = 757565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓟)*/
	{.bitmap_index = 757703, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蓠)*/
	{.bitmap_index = 757841, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蓣)*/
	{.bitmap_index = 757985, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓥)*/
	{.bitmap_index = 758123, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓦)*/
	{.bitmap_index = 758261, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓬)*/
	{.bitmap_index = 758399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蓰)*/
	{.bitmap_index = 758537, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蓼)*/
	{.bitmap_index = 758681, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蓿)*/
	{.bitmap_index = 758825, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔌)*/
	{.bitmap_index = 758969, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔑)*/
	{.bitmap_index = 759113, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蔓)*/
	{.bitmap_index = 759257, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔗)*/
	{.bitmap_index = 759401, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蔚)*/
	{.bitmap_index = 759539, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔟)*/
	{.bitmap_index = 759683, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蔡)*/
	{.bitmap_index = 759821, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蔫)*/
	{.bitmap_index = 759959, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔬)*/
	{.bitmap_index = 760103, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蔷)*/
	{.bitmap_index = 760241, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蔸)*/
	{.bitmap_index = 760385, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔹)*/
	{.bitmap_index = 760529, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蔺)*/
	{.bitmap_index = 760667, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蔻)*/
	{.bitmap_index = 760811, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蔼)*/
	{.bitmap_index = 760949, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蔽)*/
	{.bitmap_index = 761093, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蕃)*/
	{.bitmap_index = 761231, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蕈)*/
	{.bitmap_index = 761369, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蕉)*/
	{.bitmap_index = 761513, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蕊)*/
	{.bitmap_index = 761651, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蕖)*/
	{.bitmap_index = 761789, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蕙)*/
	{.bitmap_index = 761927, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蕞)*/
	{.bitmap_index = 762065, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蕤)*/
	{.bitmap_index = 762203, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蕨)*/
	{.bitmap_index = 762347, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蕲)*/
	{.bitmap_index = 762491, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蕴)*/
	{.bitmap_index = 762629, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蕹)*/
	{.bitmap_index = 762773, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蕺)*/
	{.bitmap_index = 762911, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蕻)*/
	{.bitmap_index = 763055, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蕾)*/
	{.bitmap_index = 763193, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(薄)*/
	{.bitmap_index = 763331, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(薅)*/
	{.bitmap_index = 763475, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(薇)*/
	{.bitmap_index = 763619, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(薏)*/
	{.bitmap_index = 763757, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(薛)*/
	{.bitmap_index = 763895, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(薜)*/
	{.bitmap_index = 764033, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(薤)*/
	{.bitmap_index = 764177, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(薨)*/
	{.bitmap_index = 764321, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(薪)*/
	{.bitmap_index = 764465, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(薮)*/
	{.bitmap_index = 764609, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(薯)*/
	{.bitmap_index = 764747, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(薰)*/
	{.bitmap_index = 764891, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(薷)*/
	{.bitmap_index = 765029, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(薹)*/
	{.bitmap_index = 765167, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(藁)*/
	{.bitmap_index = 765305, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藉)*/
	{.bitmap_index = 765443, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(藏)*/
	{.bitmap_index = 765587, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(藐)*/
	{.bitmap_index = 765731, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(藓)*/
	{.bitmap_index = 765869, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藕)*/
	{.bitmap_index = 766007, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藜)*/
	{.bitmap_index = 766145, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藤)*/
	{.bitmap_index = 766283, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藩)*/
	{.bitmap_index = 766421, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藻)*/
	{.bitmap_index = 766559, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(藿)*/
	{.bitmap_index = 766697, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蘅)*/
	{.bitmap_index = 766835, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蘑)*/
	{.bitmap_index = 766973, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蘖)*/
	{.bitmap_index = 767111, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蘧)*/
	{.bitmap_index = 767249, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蘩)*/
	{.bitmap_index = 767387, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蘸)*/
	{.bitmap_index = 767531, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蘼)*/
	{.bitmap_index = 767669, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(虍)*/
	{.bitmap_index = 767807, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虎)*/
	{.bitmap_index = 767951, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虏)*/
	{.bitmap_index = 768095, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虐)*/
	{.bitmap_index = 768239, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虑)*/
	{.bitmap_index = 768383, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虔)*/
	{.bitmap_index = 768527, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虚)*/
	{.bitmap_index = 768671, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虞)*/
	{.bitmap_index = 768815, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(虢)*/
	{.bitmap_index = 768953, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(虫)*/
	{.bitmap_index = 769091, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(虬)*/
	{.bitmap_index = 769229, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虮)*/
	{.bitmap_index = 769373, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(虱)*/
	{.bitmap_index = 769511, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(虹)*/
	{.bitmap_index = 769643, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(虺)*/
	{.bitmap_index = 769781, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(虻)*/
	{.bitmap_index = 769919, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(虼)*/
	{.bitmap_index = 770057, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(虽)*/
	{.bitmap_index = 770195, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(虾)*/
	{.bitmap_index = 770333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(虿)*/
	{.bitmap_index = 770471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚀)*/
	{.bitmap_index = 770609, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蚁)*/
	{.bitmap_index = 770753, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚂)*/
	{.bitmap_index = 770891, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚊)*/
	{.bitmap_index = 771035, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚋)*/
	{.bitmap_index = 771173, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蚌)*/
	{.bitmap_index = 771311, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚍)*/
	{.bitmap_index = 771449, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚓)*/
	{.bitmap_index = 771587, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚕)*/
	{.bitmap_index = 771725, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚜)*/
	{.bitmap_index = 771863, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚝)*/
	{.bitmap_index = 772001, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚣)*/
	{.bitmap_index = 772139, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚤)*/
	{.bitmap_index = 772277, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚧)*/
	{.bitmap_index = 772421, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚨)*/
	{.bitmap_index = 772565, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蚩)*/
	{.bitmap_index = 772709, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蚪)*/
	{.bitmap_index = 772847, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚬)*/
	{.bitmap_index = 772991, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚯)*/
	{.bitmap_index = 773129, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚰)*/
	{.bitmap_index = 773267, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚱)*/
	{.bitmap_index = 773405, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蚴)*/
	{.bitmap_index = 773549, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蚵)*/
	{.bitmap_index = 773687, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚶)*/
	{.bitmap_index = 773825, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蚺)*/
	{.bitmap_index = 773963, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(蛀)*/
	{.bitmap_index = 774095, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛄)*/
	{.bitmap_index = 774233, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛆)*/
	{.bitmap_index = 774371, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛇)*/
	{.bitmap_index = 774509, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛉)*/
	{.bitmap_index = 774653, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(蛊)*/
	{.bitmap_index = 774785, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛋)*/
	{.bitmap_index = 774923, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛎)*/
	{.bitmap_index = 775067, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛏)*/
	{.bitmap_index = 775205, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛐)*/
	{.bitmap_index = 775343, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛑)*/
	{.bitmap_index = 775481, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛔)*/
	{.bitmap_index = 775619, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛘)*/
	{.bitmap_index = 775757, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛙)*/
	{.bitmap_index = 775895, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛛)*/
	{.bitmap_index = 776033, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛞)*/
	{.bitmap_index = 776171, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛟)*/
	{.bitmap_index = 776315, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(蛤)*/
	{.bitmap_index = 776447, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蛩)*/
	{.bitmap_index = 776585, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛭)*/
	{.bitmap_index = 776723, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛮)*/
	{.bitmap_index = 776867, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蛰)*/
	{.bitmap_index = 777011, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛱)*/
	{.bitmap_index = 777149, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蛲)*/
	{.bitmap_index = 777287, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛳)*/
	{.bitmap_index = 777431, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蛴)*/
	{.bitmap_index = 777575, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蛸)*/
	{.bitmap_index = 777713, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蛹)*/
	{.bitmap_index = 777851, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蛾)*/
	{.bitmap_index = 777989, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜀)*/
	{.bitmap_index = 778127, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜂)*/
	{.bitmap_index = 778265, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜃)*/
	{.bitmap_index = 778403, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蜇)*/
	{.bitmap_index = 778547, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜈)*/
	{.bitmap_index = 778691, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜉)*/
	{.bitmap_index = 778829, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜊)*/
	{.bitmap_index = 778967, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜍)*/
	{.bitmap_index = 779105, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜒)*/
	{.bitmap_index = 779243, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜓)*/
	{.bitmap_index = 779387, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜕)*/
	{.bitmap_index = 779531, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜗)*/
	{.bitmap_index = 779669, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜘)*/
	{.bitmap_index = 779807, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蜚)*/
	{.bitmap_index = 779951, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蜜)*/
	{.bitmap_index = 780095, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蜞)*/
	{.bitmap_index = 780239, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜡)*/
	{.bitmap_index = 780377, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜢)*/
	{.bitmap_index = 780515, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜣)*/
	{.bitmap_index = 780659, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜥)*/
	{.bitmap_index = 780797, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜩)*/
	{.bitmap_index = 780935, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜮)*/
	{.bitmap_index = 781079, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜱)*/
	{.bitmap_index = 781217, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蜴)*/
	{.bitmap_index = 781361, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜷)*/
	{.bitmap_index = 781499, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜻)*/
	{.bitmap_index = 781637, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜾)*/
	{.bitmap_index = 781775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蜿)*/
	{.bitmap_index = 781913, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝇)*/
	{.bitmap_index = 782051, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蝈)*/
	{.bitmap_index = 782189, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝉)*/
	{.bitmap_index = 782327, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝌)*/
	{.bitmap_index = 782465, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝎)*/
	{.bitmap_index = 782603, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝓)*/
	{.bitmap_index = 782741, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝗)*/
	{.bitmap_index = 782879, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝙)*/
	{.bitmap_index = 783017, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝠)*/
	{.bitmap_index = 783155, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蝣)*/
	{.bitmap_index = 783299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝤)*/
	{.bitmap_index = 783437, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蝥)*/
	{.bitmap_index = 783581, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蝮)*/
	{.bitmap_index = 783725, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝰)*/
	{.bitmap_index = 783863, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蝴)*/
	{.bitmap_index = 784007, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝶)*/
	{.bitmap_index = 784145, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝻)*/
	{.bitmap_index = 784283, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蝼)*/
	{.bitmap_index = 784427, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝽)*/
	{.bitmap_index = 784565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蝾)*/
	{.bitmap_index = 784703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螂)*/
	{.bitmap_index = 784841, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(螃)*/
	{.bitmap_index = 784985, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螅)*/
	{.bitmap_index = 785123, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螈)*/
	{.bitmap_index = 785261, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(螋)*/
	{.bitmap_index = 785405, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(融)*/
	{.bitmap_index = 785543, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螓)*/
	{.bitmap_index = 785681, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螗)*/
	{.bitmap_index = 785819, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(螟)*/
	{.bitmap_index = 785963, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螨)*/
	{.bitmap_index = 786101, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(螫)*/
	{.bitmap_index = 786245, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螬)*/
	{.bitmap_index = 786383, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螭)*/
	{.bitmap_index = 786521, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(螯)*/
	{.bitmap_index = 786671, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(螳)*/
	{.bitmap_index = 786809, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螵)*/
	{.bitmap_index = 786947, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(螺)*/
	{.bitmap_index = 787085, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(螽)*/
	{.bitmap_index = 787235, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟀)*/
	{.bitmap_index = 787373, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蟆)*/
	{.bitmap_index = 787517, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟊)*/
	{.bitmap_index = 787649, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟋)*/
	{.bitmap_index = 787787, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蟑)*/
	{.bitmap_index = 787931, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蟒)*/
	{.bitmap_index = 788075, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟓)*/
	{.bitmap_index = 788213, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蟛)*/
	{.bitmap_index = 788357, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟠)*/
	{.bitmap_index = 788495, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蟥)*/
	{.bitmap_index = 788639, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟪)*/
	{.bitmap_index = 788777, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟮)*/
	{.bitmap_index = 788915, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蟹)*/
	{.bitmap_index = 789059, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蟾)*/
	{.bitmap_index = 789203, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠃)*/
	{.bitmap_index = 789353, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠊)*/
	{.bitmap_index = 789497, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠓)*/
	{.bitmap_index = 789641, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蠕)*/
	{.bitmap_index = 789779, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠖)*/
	{.bitmap_index = 789923, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠛)*/
	{.bitmap_index = 790067, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蠡)*/
	{.bitmap_index = 790205, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠢)*/
	{.bitmap_index = 790349, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蠲)*/
	{.bitmap_index = 790487, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(蠹)*/
	{.bitmap_index = 790631, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蠼)*/
	{.bitmap_index = 790775, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(血)*/
	{.bitmap_index = 790907, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衄)*/
	{.bitmap_index = 791045, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衅)*/
	{.bitmap_index = 791183, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(行)*/
	{.bitmap_index = 791321, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衍)*/
	{.bitmap_index = 791459, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衔)*/
	{.bitmap_index = 791597, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(街)*/
	{.bitmap_index = 791741, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衙)*/
	{.bitmap_index = 791879, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衡)*/
	{.bitmap_index = 792017, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衢)*/
	{.bitmap_index = 792155, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衣)*/
	{.bitmap_index = 792293, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(衤)*/
	{.bitmap_index = 792385, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(补)*/
	{.bitmap_index = 792523, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(表)*/
	{.bitmap_index = 792667, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衩)*/
	{.bitmap_index = 792811, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衫)*/
	{.bitmap_index = 792955, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衬)*/
	{.bitmap_index = 793093, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衮)*/
	{.bitmap_index = 793237, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衰)*/
	{.bitmap_index = 793381, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衲)*/
	{.bitmap_index = 793519, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衷)*/
	{.bitmap_index = 793663, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(衽)*/
	{.bitmap_index = 793801, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衾)*/
	{.bitmap_index = 793951, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(衿)*/
	{.bitmap_index = 794101, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袁)*/
	{.bitmap_index = 794245, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袂)*/
	{.bitmap_index = 794389, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袄)*/
	{.bitmap_index = 794533, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袅)*/
	{.bitmap_index = 794677, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袈)*/
	{.bitmap_index = 794821, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袋)*/
	{.bitmap_index = 794965, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袍)*/
	{.bitmap_index = 795103, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袒)*/
	{.bitmap_index = 795241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袖)*/
	{.bitmap_index = 795379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袜)*/
	{.bitmap_index = 795517, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袢)*/
	{.bitmap_index = 795655, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袤)*/
	{.bitmap_index = 795799, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(被)*/
	{.bitmap_index = 795943, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(袭)*/
	{.bitmap_index = 796087, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袱)*/
	{.bitmap_index = 796225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袷)*/
	{.bitmap_index = 796363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(袼)*/
	{.bitmap_index = 796501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裁)*/
	{.bitmap_index = 796639, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裂)*/
	{.bitmap_index = 796783, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(装)*/
	{.bitmap_index = 796927, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裆)*/
	{.bitmap_index = 797065, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裉)*/
	{.bitmap_index = 797209, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裎)*/
	{.bitmap_index = 797347, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裒)*/
	{.bitmap_index = 797491, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裔)*/
	{.bitmap_index = 797635, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裕)*/
	{.bitmap_index = 797773, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裘)*/
	{.bitmap_index = 797923, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裙)*/
	{.bitmap_index = 798061, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裟)*/
	{.bitmap_index = 798205, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裢)*/
	{.bitmap_index = 798343, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裣)*/
	{.bitmap_index = 798481, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裤)*/
	{.bitmap_index = 798619, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裥)*/
	{.bitmap_index = 798757, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裨)*/
	{.bitmap_index = 798895, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裰)*/
	{.bitmap_index = 799033, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裱)*/
	{.bitmap_index = 799177, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裳)*/
	{.bitmap_index = 799321, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裴)*/
	{.bitmap_index = 799465, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裸)*/
	{.bitmap_index = 799603, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裹)*/
	{.bitmap_index = 799747, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(裼)*/
	{.bitmap_index = 799891, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(裾)*/
	{.bitmap_index = 800029, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褂)*/
	{.bitmap_index = 800167, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褊)*/
	{.bitmap_index = 800305, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褐)*/
	{.bitmap_index = 800443, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(褒)*/
	{.bitmap_index = 800587, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褓)*/
	{.bitmap_index = 800725, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褙)*/
	{.bitmap_index = 800863, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褚)*/
	{.bitmap_index = 801001, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(褛)*/
	{.bitmap_index = 801145, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褡)*/
	{.bitmap_index = 801283, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褥)*/
	{.bitmap_index = 801421, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褪)*/
	{.bitmap_index = 801559, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褫)*/
	{.bitmap_index = 801697, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褰)*/
	{.bitmap_index = 801835, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褴)*/
	{.bitmap_index = 801973, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(褶)*/
	{.bitmap_index = 802111, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(襁)*/
	{.bitmap_index = 802249, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(襄)*/
	{.bitmap_index = 802393, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(襞)*/
	{.bitmap_index = 802537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(襟)*/
	{.bitmap_index = 802675, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(襦)*/
	{.bitmap_index = 802813, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(襻)*/
	{.bitmap_index = 802951, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(西)*/
	{.bitmap_index = 803077, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(要)*/
	{.bitmap_index = 803215, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(覃)*/
	{.bitmap_index = 803347, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(覆)*/
	{.bitmap_index = 803485, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(见)*/
	{.bitmap_index = 803623, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(观)*/
	{.bitmap_index = 803761, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(规)*/
	{.bitmap_index = 803905, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(觅)*/
	{.bitmap_index = 804049, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(视)*/
	{.bitmap_index = 804193, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(觇)*/
	{.bitmap_index = 804337, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(览)*/
	{.bitmap_index = 804481, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(觉)*/
	{.bitmap_index = 804625, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(觊)*/
	{.bitmap_index = 804769, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(觋)*/
	{.bitmap_index = 804907, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(觌)*/
	{.bitmap_index = 805051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(觎)*/
	{.bitmap_index = 805195, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(觏)*/
	{.bitmap_index = 805333, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(觐)*/
	{.bitmap_index = 805471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(觑)*/
	{.bitmap_index = 805609, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(角)*/
	{.bitmap_index = 805759, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(觖)*/
	{.bitmap_index = 805909, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(觚)*/
	{.bitmap_index = 806047, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(觜)*/
	{.bitmap_index = 806191, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(觞)*/
	{.bitmap_index = 806335, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(解)*/
	{.bitmap_index = 806473, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(觥)*/
	{.bitmap_index = 806617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(触)*/
	{.bitmap_index = 806755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(觫)*/
	{.bitmap_index = 806893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(觯)*/
	{.bitmap_index = 807031, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(觳)*/
	{.bitmap_index = 807175, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(言)*/
	{.bitmap_index = 807313, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(訇)*/
	{.bitmap_index = 807451, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(訾)*/
	{.bitmap_index = 807589, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(詈)*/
	{.bitmap_index = 807721, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(詹)*/
	{.bitmap_index = 807871, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(誉)*/
	{.bitmap_index = 808009, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(誊)*/
	{.bitmap_index = 808147, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(誓)*/
	{.bitmap_index = 808285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(謇)*/
	{.bitmap_index = 808423, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(謦)*/
	{.bitmap_index = 808561, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(警)*/
	{.bitmap_index = 808699, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(譬)*/
	{.bitmap_index = 808837, .adv_w = 14, .box_h = 23, .box_w = 12, .ofs_x = 2, .ofs_y = 5},/*(讠)*/
	{.bitmap_index = 808906, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(计)*/
	{.bitmap_index = 809044, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(订)*/
	{.bitmap_index = 809182, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讣)*/
	{.bitmap_index = 809320, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(认)*/
	{.bitmap_index = 809464, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(讥)*/
	{.bitmap_index = 809608, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讦)*/
	{.bitmap_index = 809746, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讧)*/
	{.bitmap_index = 809884, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讨)*/
	{.bitmap_index = 810022, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(让)*/
	{.bitmap_index = 810160, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讪)*/
	{.bitmap_index = 810298, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讫)*/
	{.bitmap_index = 810436, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(训)*/
	{.bitmap_index = 810580, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(议)*/
	{.bitmap_index = 810724, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讯)*/
	{.bitmap_index = 810862, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(记)*/
	{.bitmap_index = 811000, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(讲)*/
	{.bitmap_index = 811144, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讳)*/
	{.bitmap_index = 811282, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讴)*/
	{.bitmap_index = 811420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(讵)*/
	{.bitmap_index = 811558, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讶)*/
	{.bitmap_index = 811696, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讷)*/
	{.bitmap_index = 811834, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(许)*/
	{.bitmap_index = 811972, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讹)*/
	{.bitmap_index = 812110, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(论)*/
	{.bitmap_index = 812248, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(讼)*/
	{.bitmap_index = 812386, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(讽)*/
	{.bitmap_index = 812524, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(设)*/
	{.bitmap_index = 812668, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(访)*/
	{.bitmap_index = 812806, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诀)*/
	{.bitmap_index = 812950, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(证)*/
	{.bitmap_index = 813082, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诂)*/
	{.bitmap_index = 813220, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诃)*/
	{.bitmap_index = 813358, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(评)*/
	{.bitmap_index = 813496, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诅)*/
	{.bitmap_index = 813634, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(识)*/
	{.bitmap_index = 813778, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诈)*/
	{.bitmap_index = 813916, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诉)*/
	{.bitmap_index = 814054, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诊)*/
	{.bitmap_index = 814198, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诋)*/
	{.bitmap_index = 814342, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诌)*/
	{.bitmap_index = 814480, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(词)*/
	{.bitmap_index = 814618, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诎)*/
	{.bitmap_index = 814756, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诏)*/
	{.bitmap_index = 814894, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(译)*/
	{.bitmap_index = 815032, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诒)*/
	{.bitmap_index = 815170, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(诓)*/
	{.bitmap_index = 815308, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诔)*/
	{.bitmap_index = 815446, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(试)*/
	{.bitmap_index = 815584, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诖)*/
	{.bitmap_index = 815722, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(诗)*/
	{.bitmap_index = 815860, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诘)*/
	{.bitmap_index = 815998, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诙)*/
	{.bitmap_index = 816142, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(诚)*/
	{.bitmap_index = 816286, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诛)*/
	{.bitmap_index = 816424, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诜)*/
	{.bitmap_index = 816568, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(话)*/
	{.bitmap_index = 816706, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(诞)*/
	{.bitmap_index = 816844, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诟)*/
	{.bitmap_index = 816982, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(诠)*/
	{.bitmap_index = 817114, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诡)*/
	{.bitmap_index = 817264, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(询)*/
	{.bitmap_index = 817402, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诣)*/
	{.bitmap_index = 817540, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诤)*/
	{.bitmap_index = 817678, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(该)*/
	{.bitmap_index = 817822, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(详)*/
	{.bitmap_index = 817960, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诧)*/
	{.bitmap_index = 818098, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诨)*/
	{.bitmap_index = 818236, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诩)*/
	{.bitmap_index = 818374, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诫)*/
	{.bitmap_index = 818512, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诬)*/
	{.bitmap_index = 818650, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(语)*/
	{.bitmap_index = 818788, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诮)*/
	{.bitmap_index = 818926, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(误)*/
	{.bitmap_index = 819070, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诰)*/
	{.bitmap_index = 819208, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诱)*/
	{.bitmap_index = 819352, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诲)*/
	{.bitmap_index = 819490, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诳)*/
	{.bitmap_index = 819628, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(说)*/
	{.bitmap_index = 819772, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诵)*/
	{.bitmap_index = 819910, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诶)*/
	{.bitmap_index = 820060, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(请)*/
	{.bitmap_index = 820198, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诸)*/
	{.bitmap_index = 820336, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诹)*/
	{.bitmap_index = 820474, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诺)*/
	{.bitmap_index = 820612, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(读)*/
	{.bitmap_index = 820756, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诼)*/
	{.bitmap_index = 820894, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(诽)*/
	{.bitmap_index = 821032, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(课)*/
	{.bitmap_index = 821170, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(诿)*/
	{.bitmap_index = 821314, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谀)*/
	{.bitmap_index = 821458, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谁)*/
	{.bitmap_index = 821596, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谂)*/
	{.bitmap_index = 821734, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(调)*/
	{.bitmap_index = 821872, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谄)*/
	{.bitmap_index = 822016, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谅)*/
	{.bitmap_index = 822154, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谆)*/
	{.bitmap_index = 822292, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谇)*/
	{.bitmap_index = 822430, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谈)*/
	{.bitmap_index = 822574, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谊)*/
	{.bitmap_index = 822712, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谋)*/
	{.bitmap_index = 822850, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谌)*/
	{.bitmap_index = 822988, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谍)*/
	{.bitmap_index = 823126, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谎)*/
	{.bitmap_index = 823270, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谏)*/
	{.bitmap_index = 823408, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谐)*/
	{.bitmap_index = 823546, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谑)*/
	{.bitmap_index = 823690, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谒)*/
	{.bitmap_index = 823828, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谓)*/
	{.bitmap_index = 823966, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谔)*/
	{.bitmap_index = 824104, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谕)*/
	{.bitmap_index = 824242, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谖)*/
	{.bitmap_index = 824386, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谗)*/
	{.bitmap_index = 824536, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谘)*/
	{.bitmap_index = 824674, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谙)*/
	{.bitmap_index = 824812, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谚)*/
	{.bitmap_index = 824956, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谛)*/
	{.bitmap_index = 825094, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谜)*/
	{.bitmap_index = 825232, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谝)*/
	{.bitmap_index = 825370, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谟)*/
	{.bitmap_index = 825514, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谠)*/
	{.bitmap_index = 825658, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谡)*/
	{.bitmap_index = 825802, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谢)*/
	{.bitmap_index = 825940, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谣)*/
	{.bitmap_index = 826078, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(谤)*/
	{.bitmap_index = 826222, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谥)*/
	{.bitmap_index = 826360, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谦)*/
	{.bitmap_index = 826498, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谧)*/
	{.bitmap_index = 826642, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谨)*/
	{.bitmap_index = 826780, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谩)*/
	{.bitmap_index = 826924, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谪)*/
	{.bitmap_index = 827062, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谫)*/
	{.bitmap_index = 827206, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谬)*/
	{.bitmap_index = 827350, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谭)*/
	{.bitmap_index = 827488, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谮)*/
	{.bitmap_index = 827626, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谯)*/
	{.bitmap_index = 827764, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谰)*/
	{.bitmap_index = 827902, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谱)*/
	{.bitmap_index = 828040, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谲)*/
	{.bitmap_index = 828178, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谳)*/
	{.bitmap_index = 828316, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谴)*/
	{.bitmap_index = 828454, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(谵)*/
	{.bitmap_index = 828598, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(谶)*/
	{.bitmap_index = 828742, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(谷)*/
	{.bitmap_index = 828880, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(豁)*/
	{.bitmap_index = 829018, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(豆)*/
	{.bitmap_index = 829144, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(豇)*/
	{.bitmap_index = 829276, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(豉)*/
	{.bitmap_index = 829420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(豌)*/
	{.bitmap_index = 829558, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(豕)*/
	{.bitmap_index = 829690, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(豚)*/
	{.bitmap_index = 829822, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(象)*/
	{.bitmap_index = 829966, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(豢)*/
	{.bitmap_index = 830104, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(豪)*/
	{.bitmap_index = 830242, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(豫)*/
	{.bitmap_index = 830380, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(豳)*/
	{.bitmap_index = 830518, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(豸)*/
	{.bitmap_index = 830633, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(豹)*/
	{.bitmap_index = 830771, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(豺)*/
	{.bitmap_index = 830909, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(貂)*/
	{.bitmap_index = 831047, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(貅)*/
	{.bitmap_index = 831185, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(貉)*/
	{.bitmap_index = 831323, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(貊)*/
	{.bitmap_index = 831461, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(貌)*/
	{.bitmap_index = 831605, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(貔)*/
	{.bitmap_index = 831743, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(貘)*/
	{.bitmap_index = 831887, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贝)*/
	{.bitmap_index = 832025, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贞)*/
	{.bitmap_index = 832169, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(负)*/
	{.bitmap_index = 832319, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贡)*/
	{.bitmap_index = 832457, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(财)*/
	{.bitmap_index = 832595, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(责)*/
	{.bitmap_index = 832739, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贤)*/
	{.bitmap_index = 832883, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(败)*/
	{.bitmap_index = 833027, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(账)*/
	{.bitmap_index = 833165, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(货)*/
	{.bitmap_index = 833315, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(质)*/
	{.bitmap_index = 833459, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贩)*/
	{.bitmap_index = 833603, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贪)*/
	{.bitmap_index = 833753, .adv_w = 25, .box_h = 25, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贫)*/
	{.bitmap_index = 833903, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(贬)*/
	{.bitmap_index = 834041, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(购)*/
	{.bitmap_index = 834185, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贮)*/
	{.bitmap_index = 834329, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贯)*/
	{.bitmap_index = 834467, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贰)*/
	{.bitmap_index = 834611, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(贱)*/
	{.bitmap_index = 834749, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贲)*/
	{.bitmap_index = 834893, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贳)*/
	{.bitmap_index = 835037, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贴)*/
	{.bitmap_index = 835181, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贵)*/
	{.bitmap_index = 835325, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贶)*/
	{.bitmap_index = 835463, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贷)*/
	{.bitmap_index = 835613, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贸)*/
	{.bitmap_index = 835757, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(费)*/
	{.bitmap_index = 835901, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贺)*/
	{.bitmap_index = 836045, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贻)*/
	{.bitmap_index = 836189, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(贼)*/
	{.bitmap_index = 836327, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贽)*/
	{.bitmap_index = 836471, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(贾)*/
	{.bitmap_index = 836609, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(贿)*/
	{.bitmap_index = 836753, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(赀)*/
	{.bitmap_index = 836897, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赁)*/
	{.bitmap_index = 837041, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赂)*/
	{.bitmap_index = 837179, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赃)*/
	{.bitmap_index = 837317, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(资)*/
	{.bitmap_index = 837461, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赅)*/
	{.bitmap_index = 837605, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赆)*/
	{.bitmap_index = 837737, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赇)*/
	{.bitmap_index = 837875, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赈)*/
	{.bitmap_index = 838013, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赉)*/
	{.bitmap_index = 838157, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赊)*/
	{.bitmap_index = 838295, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赋)*/
	{.bitmap_index = 838439, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赌)*/
	{.bitmap_index = 838583, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(赍)*/
	{.bitmap_index = 838727, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赎)*/
	{.bitmap_index = 838871, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(赏)*/
	{.bitmap_index = 839015, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赐)*/
	{.bitmap_index = 839159, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赓)*/
	{.bitmap_index = 839303, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赔)*/
	{.bitmap_index = 839447, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赕)*/
	{.bitmap_index = 839591, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赖)*/
	{.bitmap_index = 839735, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赘)*/
	{.bitmap_index = 839879, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赙)*/
	{.bitmap_index = 840023, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赚)*/
	{.bitmap_index = 840167, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赛)*/
	{.bitmap_index = 840311, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(赜)*/
	{.bitmap_index = 840455, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赝)*/
	{.bitmap_index = 840593, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(赞)*/
	{.bitmap_index = 840737, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赠)*/
	{.bitmap_index = 840881, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赡)*/
	{.bitmap_index = 841031, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赢)*/
	{.bitmap_index = 841175, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(赣)*/
	{.bitmap_index = 841319, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赤)*/
	{.bitmap_index = 841463, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赦)*/
	{.bitmap_index = 841607, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赧)*/
	{.bitmap_index = 841751, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赫)*/
	{.bitmap_index = 841895, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赭)*/
	{.bitmap_index = 842039, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(走)*/
	{.bitmap_index = 842183, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赳)*/
	{.bitmap_index = 842321, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赴)*/
	{.bitmap_index = 842465, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(赵)*/
	{.bitmap_index = 842603, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(赶)*/
	{.bitmap_index = 842747, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(起)*/
	{.bitmap_index = 842885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趁)*/
	{.bitmap_index = 843023, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趄)*/
	{.bitmap_index = 843161, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(超)*/
	{.bitmap_index = 843299, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(越)*/
	{.bitmap_index = 843437, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趋)*/
	{.bitmap_index = 843575, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趑)*/
	{.bitmap_index = 843713, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趔)*/
	{.bitmap_index = 843851, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趟)*/
	{.bitmap_index = 843989, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趣)*/
	{.bitmap_index = 844127, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趱)*/
	{.bitmap_index = 844265, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(足)*/
	{.bitmap_index = 844403, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(趴)*/
	{.bitmap_index = 844541, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(趵)*/
	{.bitmap_index = 844679, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(趸)*/
	{.bitmap_index = 844817, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(趺)*/
	{.bitmap_index = 844961, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(趼)*/
	{.bitmap_index = 845099, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(趾)*/
	{.bitmap_index = 845231, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(趿)*/
	{.bitmap_index = 845369, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(跃)*/
	{.bitmap_index = 845513, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跄)*/
	{.bitmap_index = 845651, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跆)*/
	{.bitmap_index = 845789, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(跋)*/
	{.bitmap_index = 845933, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跌)*/
	{.bitmap_index = 846077, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跎)*/
	{.bitmap_index = 846215, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跏)*/
	{.bitmap_index = 846359, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跑)*/
	{.bitmap_index = 846497, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跖)*/
	{.bitmap_index = 846629, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跗)*/
	{.bitmap_index = 846767, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跚)*/
	{.bitmap_index = 846905, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跛)*/
	{.bitmap_index = 847049, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(距)*/
	{.bitmap_index = 847181, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跞)*/
	{.bitmap_index = 847319, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跟)*/
	{.bitmap_index = 847457, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(跣)*/
	{.bitmap_index = 847601, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跤)*/
	{.bitmap_index = 847745, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(跨)*/
	{.bitmap_index = 847883, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跪)*/
	{.bitmap_index = 848027, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跫)*/
	{.bitmap_index = 848165, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跬)*/
	{.bitmap_index = 848303, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(路)*/
	{.bitmap_index = 848441, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跳)*/
	{.bitmap_index = 848585, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(践)*/
	{.bitmap_index = 848723, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跷)*/
	{.bitmap_index = 848861, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跸)*/
	{.bitmap_index = 848999, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跹)*/
	{.bitmap_index = 849137, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跺)*/
	{.bitmap_index = 849269, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(跻)*/
	{.bitmap_index = 849413, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(跽)*/
	{.bitmap_index = 849545, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(踅)*/
	{.bitmap_index = 849689, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(踉)*/
	{.bitmap_index = 849833, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踊)*/
	{.bitmap_index = 849965, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踌)*/
	{.bitmap_index = 850103, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(踏)*/
	{.bitmap_index = 850241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踔)*/
	{.bitmap_index = 850379, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踝)*/
	{.bitmap_index = 850511, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(踞)*/
	{.bitmap_index = 850643, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踟)*/
	{.bitmap_index = 850781, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(踢)*/
	{.bitmap_index = 850919, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踣)*/
	{.bitmap_index = 851057, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踩)*/
	{.bitmap_index = 851195, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踪)*/
	{.bitmap_index = 851333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踬)*/
	{.bitmap_index = 851471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踮)*/
	{.bitmap_index = 851609, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踯)*/
	{.bitmap_index = 851747, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(踱)*/
	{.bitmap_index = 851891, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踵)*/
	{.bitmap_index = 852029, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踹)*/
	{.bitmap_index = 852167, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踺)*/
	{.bitmap_index = 852305, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(踽)*/
	{.bitmap_index = 852443, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹀)*/
	{.bitmap_index = 852581, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹁)*/
	{.bitmap_index = 852719, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹂)*/
	{.bitmap_index = 852851, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹄)*/
	{.bitmap_index = 852989, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹇)*/
	{.bitmap_index = 853133, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹈)*/
	{.bitmap_index = 853271, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹉)*/
	{.bitmap_index = 853409, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹊)*/
	{.bitmap_index = 853553, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹋)*/
	{.bitmap_index = 853685, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹑)*/
	{.bitmap_index = 853823, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹒)*/
	{.bitmap_index = 853961, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹙)*/
	{.bitmap_index = 854111, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹦)*/
	{.bitmap_index = 854255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹩)*/
	{.bitmap_index = 854399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹬)*/
	{.bitmap_index = 854537, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蹭)*/
	{.bitmap_index = 854675, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹯)*/
	{.bitmap_index = 854813, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹰)*/
	{.bitmap_index = 854945, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹲)*/
	{.bitmap_index = 855083, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹴)*/
	{.bitmap_index = 855221, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(蹶)*/
	{.bitmap_index = 855359, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(蹼)*/
	{.bitmap_index = 855497, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(蹿)*/
	{.bitmap_index = 855635, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躁)*/
	{.bitmap_index = 855767, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躅)*/
	{.bitmap_index = 855899, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躇)*/
	{.bitmap_index = 856037, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躏)*/
	{.bitmap_index = 856175, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(躐)*/
	{.bitmap_index = 856319, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躔)*/
	{.bitmap_index = 856457, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躜)*/
	{.bitmap_index = 856595, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(躞)*/
	{.bitmap_index = 856733, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(身)*/
	{.bitmap_index = 856871, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躬)*/
	{.bitmap_index = 857009, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躯)*/
	{.bitmap_index = 857147, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躲)*/
	{.bitmap_index = 857285, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(躺)*/
	{.bitmap_index = 857423, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(軎)*/
	{.bitmap_index = 857561, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(车)*/
	{.bitmap_index = 857699, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(轧)*/
	{.bitmap_index = 857837, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轨)*/
	{.bitmap_index = 857975, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轩)*/
	{.bitmap_index = 858113, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轫)*/
	{.bitmap_index = 858251, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(转)*/
	{.bitmap_index = 858395, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(轭)*/
	{.bitmap_index = 858533, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轮)*/
	{.bitmap_index = 858671, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(软)*/
	{.bitmap_index = 858815, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(轰)*/
	{.bitmap_index = 858959, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(轱)*/
	{.bitmap_index = 859097, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轲)*/
	{.bitmap_index = 859235, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(轳)*/
	{.bitmap_index = 859379, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轴)*/
	{.bitmap_index = 859517, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(轵)*/
	{.bitmap_index = 859661, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(轶)*/
	{.bitmap_index = 859805, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轷)*/
	{.bitmap_index = 859943, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(轸)*/
	{.bitmap_index = 860087, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轹)*/
	{.bitmap_index = 860225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轺)*/
	{.bitmap_index = 860363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轻)*/
	{.bitmap_index = 860501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轼)*/
	{.bitmap_index = 860639, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(载)*/
	{.bitmap_index = 860783, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(轾)*/
	{.bitmap_index = 860921, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(轿)*/
	{.bitmap_index = 861065, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辁)*/
	{.bitmap_index = 861203, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辂)*/
	{.bitmap_index = 861347, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(较)*/
	{.bitmap_index = 861491, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辄)*/
	{.bitmap_index = 861629, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辅)*/
	{.bitmap_index = 861767, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辆)*/
	{.bitmap_index = 861905, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辇)*/
	{.bitmap_index = 862043, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辈)*/
	{.bitmap_index = 862181, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(辉)*/
	{.bitmap_index = 862325, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辊)*/
	{.bitmap_index = 862463, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辋)*/
	{.bitmap_index = 862601, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辍)*/
	{.bitmap_index = 862739, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辎)*/
	{.bitmap_index = 862877, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辏)*/
	{.bitmap_index = 863015, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辐)*/
	{.bitmap_index = 863153, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辑)*/
	{.bitmap_index = 863291, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(输)*/
	{.bitmap_index = 863435, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辔)*/
	{.bitmap_index = 863573, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(辕)*/
	{.bitmap_index = 863717, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辖)*/
	{.bitmap_index = 863855, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(辗)*/
	{.bitmap_index = 863999, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辘)*/
	{.bitmap_index = 864137, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(辙)*/
	{.bitmap_index = 864281, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(辚)*/
	{.bitmap_index = 864425, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辛)*/
	{.bitmap_index = 864563, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辜)*/
	{.bitmap_index = 864701, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(辞)*/
	{.bitmap_index = 864839, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辟)*/
	{.bitmap_index = 864977, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(辣)*/
	{.bitmap_index = 865121, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(辨)*/
	{.bitmap_index = 865265, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(辩)*/
	{.bitmap_index = 865409, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(辫)*/
	{.bitmap_index = 865553, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辰)*/
	{.bitmap_index = 865685, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辱)*/
	{.bitmap_index = 865817, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辶)*/
	{.bitmap_index = 865955, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(边)*/
	{.bitmap_index = 866093, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(辽)*/
	{.bitmap_index = 866231, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(达)*/
	{.bitmap_index = 866369, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迁)*/
	{.bitmap_index = 866507, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迂)*/
	{.bitmap_index = 866645, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迄)*/
	{.bitmap_index = 866789, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迅)*/
	{.bitmap_index = 866927, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(过)*/
	{.bitmap_index = 867065, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迈)*/
	{.bitmap_index = 867203, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迎)*/
	{.bitmap_index = 867341, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(运)*/
	{.bitmap_index = 867479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(近)*/
	{.bitmap_index = 867617, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迓)*/
	{.bitmap_index = 867755, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(返)*/
	{.bitmap_index = 867893, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迕)*/
	{.bitmap_index = 868031, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(还)*/
	{.bitmap_index = 868169, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(这)*/
	{.bitmap_index = 868307, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(进)*/
	{.bitmap_index = 868445, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(远)*/
	{.bitmap_index = 868583, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(违)*/
	{.bitmap_index = 868721, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(连)*/
	{.bitmap_index = 868859, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迟)*/
	{.bitmap_index = 868997, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迢)*/
	{.bitmap_index = 869135, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迤)*/
	{.bitmap_index = 869273, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迥)*/
	{.bitmap_index = 869411, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迦)*/
	{.bitmap_index = 869549, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迨)*/
	{.bitmap_index = 869687, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迩)*/
	{.bitmap_index = 869825, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迪)*/
	{.bitmap_index = 869963, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迫)*/
	{.bitmap_index = 870101, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迭)*/
	{.bitmap_index = 870239, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迮)*/
	{.bitmap_index = 870377, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(述)*/
	{.bitmap_index = 870515, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迳)*/
	{.bitmap_index = 870653, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迷)*/
	{.bitmap_index = 870791, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迸)*/
	{.bitmap_index = 870929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(迹)*/
	{.bitmap_index = 871067, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(追)*/
	{.bitmap_index = 871205, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(退)*/
	{.bitmap_index = 871343, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(送)*/
	{.bitmap_index = 871487, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(适)*/
	{.bitmap_index = 871625, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逃)*/
	{.bitmap_index = 871763, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逄)*/
	{.bitmap_index = 871907, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逅)*/
	{.bitmap_index = 872045, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逆)*/
	{.bitmap_index = 872183, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(选)*/
	{.bitmap_index = 872321, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逊)*/
	{.bitmap_index = 872459, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逋)*/
	{.bitmap_index = 872597, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逍)*/
	{.bitmap_index = 872735, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(透)*/
	{.bitmap_index = 872873, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逐)*/
	{.bitmap_index = 873011, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逑)*/
	{.bitmap_index = 873149, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(递)*/
	{.bitmap_index = 873287, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(途)*/
	{.bitmap_index = 873425, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逖)*/
	{.bitmap_index = 873563, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逗)*/
	{.bitmap_index = 873701, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(通)*/
	{.bitmap_index = 873839, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逛)*/
	{.bitmap_index = 873977, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逝)*/
	{.bitmap_index = 874115, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逞)*/
	{.bitmap_index = 874253, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(速)*/
	{.bitmap_index = 874391, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(造)*/
	{.bitmap_index = 874529, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逡)*/
	{.bitmap_index = 874667, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逢)*/
	{.bitmap_index = 874811, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逦)*/
	{.bitmap_index = 874949, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逭)*/
	{.bitmap_index = 875087, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逮)*/
	{.bitmap_index = 875225, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逯)*/
	{.bitmap_index = 875363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逵)*/
	{.bitmap_index = 875501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逶)*/
	{.bitmap_index = 875639, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逸)*/
	{.bitmap_index = 875783, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逻)*/
	{.bitmap_index = 875921, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逼)*/
	{.bitmap_index = 876059, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(逾)*/
	{.bitmap_index = 876197, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遁)*/
	{.bitmap_index = 876335, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遂)*/
	{.bitmap_index = 876473, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遄)*/
	{.bitmap_index = 876611, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遇)*/
	{.bitmap_index = 876749, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遍)*/
	{.bitmap_index = 876887, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遏)*/
	{.bitmap_index = 877025, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遐)*/
	{.bitmap_index = 877157, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遑)*/
	{.bitmap_index = 877295, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遒)*/
	{.bitmap_index = 877433, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(道)*/
	{.bitmap_index = 877571, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遗)*/
	{.bitmap_index = 877709, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遘)*/
	{.bitmap_index = 877847, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遛)*/
	{.bitmap_index = 877985, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遢)*/
	{.bitmap_index = 878123, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遣)*/
	{.bitmap_index = 878261, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遥)*/
	{.bitmap_index = 878399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遨)*/
	{.bitmap_index = 878537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遭)*/
	{.bitmap_index = 878675, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遮)*/
	{.bitmap_index = 878813, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遴)*/
	{.bitmap_index = 878951, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遵)*/
	{.bitmap_index = 879089, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(遽)*/
	{.bitmap_index = 879227, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(避)*/
	{.bitmap_index = 879365, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邀)*/
	{.bitmap_index = 879503, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邂)*/
	{.bitmap_index = 879641, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邃)*/
	{.bitmap_index = 879779, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邈)*/
	{.bitmap_index = 879917, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邋)*/
	{.bitmap_index = 880055, .adv_w = 23, .box_h = 22, .box_w = 20, .ofs_x = 3, .ofs_y = 5},/*(邑)*/
	{.bitmap_index = 880165, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邓)*/
	{.bitmap_index = 880297, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邕)*/
	{.bitmap_index = 880435, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邗)*/
	{.bitmap_index = 880567, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邙)*/
	{.bitmap_index = 880705, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邛)*/
	{.bitmap_index = 880837, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邝)*/
	{.bitmap_index = 880975, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邡)*/
	{.bitmap_index = 881113, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(邢)*/
	{.bitmap_index = 881251, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(那)*/
	{.bitmap_index = 881383, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(邦)*/
	{.bitmap_index = 881527, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邪)*/
	{.bitmap_index = 881659, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邬)*/
	{.bitmap_index = 881803, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(邮)*/
	{.bitmap_index = 881941, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邯)*/
	{.bitmap_index = 882079, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邰)*/
	{.bitmap_index = 882217, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邱)*/
	{.bitmap_index = 882355, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邳)*/
	{.bitmap_index = 882487, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邴)*/
	{.bitmap_index = 882619, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邵)*/
	{.bitmap_index = 882751, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邶)*/
	{.bitmap_index = 882889, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邸)*/
	{.bitmap_index = 883027, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邹)*/
	{.bitmap_index = 883165, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(邺)*/
	{.bitmap_index = 883303, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邻)*/
	{.bitmap_index = 883441, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(邾)*/
	{.bitmap_index = 883579, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郁)*/
	{.bitmap_index = 883717, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郄)*/
	{.bitmap_index = 883855, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郅)*/
	{.bitmap_index = 883987, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郇)*/
	{.bitmap_index = 884125, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(郊)*/
	{.bitmap_index = 884269, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郎)*/
	{.bitmap_index = 884407, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(郏)*/
	{.bitmap_index = 884551, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郐)*/
	{.bitmap_index = 884689, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(郑)*/
	{.bitmap_index = 884833, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郓)*/
	{.bitmap_index = 884965, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郗)*/
	{.bitmap_index = 885103, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郛)*/
	{.bitmap_index = 885241, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郜)*/
	{.bitmap_index = 885379, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(郝)*/
	{.bitmap_index = 885523, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郡)*/
	{.bitmap_index = 885655, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郢)*/
	{.bitmap_index = 885787, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郦)*/
	{.bitmap_index = 885919, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郧)*/
	{.bitmap_index = 886051, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(部)*/
	{.bitmap_index = 886189, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郫)*/
	{.bitmap_index = 886327, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郭)*/
	{.bitmap_index = 886465, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(郯)*/
	{.bitmap_index = 886609, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(郴)*/
	{.bitmap_index = 886747, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郸)*/
	{.bitmap_index = 886885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(都)*/
	{.bitmap_index = 887023, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(郾)*/
	{.bitmap_index = 887155, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鄂)*/
	{.bitmap_index = 887287, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鄄)*/
	{.bitmap_index = 887419, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鄙)*/
	{.bitmap_index = 887551, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鄞)*/
	{.bitmap_index = 887689, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鄢)*/
	{.bitmap_index = 887821, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鄣)*/
	{.bitmap_index = 887959, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鄯)*/
	{.bitmap_index = 888097, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鄱)*/
	{.bitmap_index = 888235, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鄹)*/
	{.bitmap_index = 888367, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酃)*/
	{.bitmap_index = 888499, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酆)*/
	{.bitmap_index = 888637, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酉)*/
	{.bitmap_index = 888769, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酊)*/
	{.bitmap_index = 888901, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酋)*/
	{.bitmap_index = 889039, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酌)*/
	{.bitmap_index = 889177, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(配)*/
	{.bitmap_index = 889309, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酎)*/
	{.bitmap_index = 889447, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酏)*/
	{.bitmap_index = 889585, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酐)*/
	{.bitmap_index = 889717, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(酒)*/
	{.bitmap_index = 889855, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酗)*/
	{.bitmap_index = 889993, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(酚)*/
	{.bitmap_index = 890137, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酝)*/
	{.bitmap_index = 890269, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(酞)*/
	{.bitmap_index = 890413, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酡)*/
	{.bitmap_index = 890551, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酢)*/
	{.bitmap_index = 890689, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酣)*/
	{.bitmap_index = 890827, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酤)*/
	{.bitmap_index = 890965, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酥)*/
	{.bitmap_index = 891103, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(酩)*/
	{.bitmap_index = 891235, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酪)*/
	{.bitmap_index = 891373, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酬)*/
	{.bitmap_index = 891511, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酮)*/
	{.bitmap_index = 891643, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酯)*/
	{.bitmap_index = 891781, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酰)*/
	{.bitmap_index = 891919, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酱)*/
	{.bitmap_index = 892057, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酲)*/
	{.bitmap_index = 892189, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酴)*/
	{.bitmap_index = 892327, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酵)*/
	{.bitmap_index = 892465, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酶)*/
	{.bitmap_index = 892603, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酷)*/
	{.bitmap_index = 892741, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(酸)*/
	{.bitmap_index = 892885, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(酹)*/
	{.bitmap_index = 893023, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(酽)*/
	{.bitmap_index = 893161, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酾)*/
	{.bitmap_index = 893293, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(酿)*/
	{.bitmap_index = 893431, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醅)*/
	{.bitmap_index = 893569, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醇)*/
	{.bitmap_index = 893707, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醉)*/
	{.bitmap_index = 893845, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醋)*/
	{.bitmap_index = 893983, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醌)*/
	{.bitmap_index = 894115, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(醍)*/
	{.bitmap_index = 894253, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醐)*/
	{.bitmap_index = 894391, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醑)*/
	{.bitmap_index = 894523, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醒)*/
	{.bitmap_index = 894655, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醚)*/
	{.bitmap_index = 894793, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醛)*/
	{.bitmap_index = 894931, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醢)*/
	{.bitmap_index = 895069, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醣)*/
	{.bitmap_index = 895207, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(醪)*/
	{.bitmap_index = 895345, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醭)*/
	{.bitmap_index = 895483, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醮)*/
	{.bitmap_index = 895621, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醯)*/
	{.bitmap_index = 895759, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醴)*/
	{.bitmap_index = 895897, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(醵)*/
	{.bitmap_index = 896035, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(醺)*/
	{.bitmap_index = 896179, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(采)*/
	{.bitmap_index = 896317, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(釉)*/
	{.bitmap_index = 896455, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(释)*/
	{.bitmap_index = 896593, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(里)*/
	{.bitmap_index = 896725, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(重)*/
	{.bitmap_index = 896863, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(野)*/
	{.bitmap_index = 896995, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(量)*/
	{.bitmap_index = 897127, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(金)*/
	{.bitmap_index = 897265, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(釜)*/
	{.bitmap_index = 897397, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鉴)*/
	{.bitmap_index = 897535, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(銎)*/
	{.bitmap_index = 897667, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(銮)*/
	{.bitmap_index = 897805, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鋈)*/
	{.bitmap_index = 897943, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(錾)*/
	{.bitmap_index = 898081, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鍪)*/
	{.bitmap_index = 898219, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鎏)*/
	{.bitmap_index = 898363, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鏊)*/
	{.bitmap_index = 898501, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鏖)*/
	{.bitmap_index = 898639, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鐾)*/
	{.bitmap_index = 898777, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鑫)*/
	{.bitmap_index = 898915, .adv_w = 13, .box_h = 23, .box_w = 12, .ofs_x = 1, .ofs_y = 5},/*(钅)*/
	{.bitmap_index = 898984, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钆)*/
	{.bitmap_index = 899122, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钇)*/
	{.bitmap_index = 899260, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(针)*/
	{.bitmap_index = 899398, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钉)*/
	{.bitmap_index = 899536, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钊)*/
	{.bitmap_index = 899674, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钋)*/
	{.bitmap_index = 899812, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钌)*/
	{.bitmap_index = 899950, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钍)*/
	{.bitmap_index = 900088, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钎)*/
	{.bitmap_index = 900226, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钏)*/
	{.bitmap_index = 900370, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钐)*/
	{.bitmap_index = 900508, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钒)*/
	{.bitmap_index = 900646, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钓)*/
	{.bitmap_index = 900784, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钔)*/
	{.bitmap_index = 900922, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钕)*/
	{.bitmap_index = 901066, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钗)*/
	{.bitmap_index = 901216, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钙)*/
	{.bitmap_index = 901354, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钚)*/
	{.bitmap_index = 901492, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钛)*/
	{.bitmap_index = 901636, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钜)*/
	{.bitmap_index = 901774, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钝)*/
	{.bitmap_index = 901912, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钞)*/
	{.bitmap_index = 902056, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钟)*/
	{.bitmap_index = 902194, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钠)*/
	{.bitmap_index = 902332, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钡)*/
	{.bitmap_index = 902476, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钢)*/
	{.bitmap_index = 902614, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钣)*/
	{.bitmap_index = 902758, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钤)*/
	{.bitmap_index = 902908, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钥)*/
	{.bitmap_index = 903052, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钦)*/
	{.bitmap_index = 903196, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钧)*/
	{.bitmap_index = 903334, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钨)*/
	{.bitmap_index = 903472, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钩)*/
	{.bitmap_index = 903610, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钪)*/
	{.bitmap_index = 903754, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钫)*/
	{.bitmap_index = 903898, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钬)*/
	{.bitmap_index = 904036, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钭)*/
	{.bitmap_index = 904174, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钮)*/
	{.bitmap_index = 904312, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钯)*/
	{.bitmap_index = 904450, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钰)*/
	{.bitmap_index = 904588, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钱)*/
	{.bitmap_index = 904726, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钲)*/
	{.bitmap_index = 904864, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钳)*/
	{.bitmap_index = 905002, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钴)*/
	{.bitmap_index = 905140, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钵)*/
	{.bitmap_index = 905278, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钶)*/
	{.bitmap_index = 905416, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钷)*/
	{.bitmap_index = 905554, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钸)*/
	{.bitmap_index = 905692, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钹)*/
	{.bitmap_index = 905836, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(钺)*/
	{.bitmap_index = 905980, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钻)*/
	{.bitmap_index = 906118, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钼)*/
	{.bitmap_index = 906262, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钽)*/
	{.bitmap_index = 906400, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钾)*/
	{.bitmap_index = 906544, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(钿)*/
	{.bitmap_index = 906682, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铀)*/
	{.bitmap_index = 906826, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铁)*/
	{.bitmap_index = 906970, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铂)*/
	{.bitmap_index = 907108, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铃)*/
	{.bitmap_index = 907246, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铄)*/
	{.bitmap_index = 907384, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铅)*/
	{.bitmap_index = 907522, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铆)*/
	{.bitmap_index = 907666, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铈)*/
	{.bitmap_index = 907804, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铉)*/
	{.bitmap_index = 907948, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铊)*/
	{.bitmap_index = 908086, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铋)*/
	{.bitmap_index = 908224, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铌)*/
	{.bitmap_index = 908368, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铍)*/
	{.bitmap_index = 908512, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铎)*/
	{.bitmap_index = 908650, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铐)*/
	{.bitmap_index = 908788, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铑)*/
	{.bitmap_index = 908926, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铒)*/
	{.bitmap_index = 909064, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铕)*/
	{.bitmap_index = 909202, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铖)*/
	{.bitmap_index = 909346, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铗)*/
	{.bitmap_index = 909490, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铘)*/
	{.bitmap_index = 909628, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铙)*/
	{.bitmap_index = 909766, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铛)*/
	{.bitmap_index = 909904, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铜)*/
	{.bitmap_index = 910042, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铝)*/
	{.bitmap_index = 910180, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铞)*/
	{.bitmap_index = 910318, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铟)*/
	{.bitmap_index = 910456, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铠)*/
	{.bitmap_index = 910594, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铡)*/
	{.bitmap_index = 910732, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铢)*/
	{.bitmap_index = 910870, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铣)*/
	{.bitmap_index = 911014, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铤)*/
	{.bitmap_index = 911158, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铥)*/
	{.bitmap_index = 911296, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铧)*/
	{.bitmap_index = 911440, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铨)*/
	{.bitmap_index = 911578, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铩)*/
	{.bitmap_index = 911716, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铪)*/
	{.bitmap_index = 911854, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铫)*/
	{.bitmap_index = 911998, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铬)*/
	{.bitmap_index = 912142, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铭)*/
	{.bitmap_index = 912280, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铮)*/
	{.bitmap_index = 912418, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铯)*/
	{.bitmap_index = 912562, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铰)*/
	{.bitmap_index = 912706, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铱)*/
	{.bitmap_index = 912844, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铲)*/
	{.bitmap_index = 912988, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铳)*/
	{.bitmap_index = 913132, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铴)*/
	{.bitmap_index = 913270, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铵)*/
	{.bitmap_index = 913414, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(银)*/
	{.bitmap_index = 913558, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铷)*/
	{.bitmap_index = 913702, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铸)*/
	{.bitmap_index = 913840, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(铹)*/
	{.bitmap_index = 913984, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铺)*/
	{.bitmap_index = 914122, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铼)*/
	{.bitmap_index = 914260, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铽)*/
	{.bitmap_index = 914398, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(链)*/
	{.bitmap_index = 914536, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(铿)*/
	{.bitmap_index = 914674, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(销)*/
	{.bitmap_index = 914812, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锁)*/
	{.bitmap_index = 914956, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锂)*/
	{.bitmap_index = 915094, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锃)*/
	{.bitmap_index = 915232, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锄)*/
	{.bitmap_index = 915370, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锅)*/
	{.bitmap_index = 915508, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锆)*/
	{.bitmap_index = 915646, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锇)*/
	{.bitmap_index = 915784, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锈)*/
	{.bitmap_index = 915928, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锉)*/
	{.bitmap_index = 916066, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锊)*/
	{.bitmap_index = 916204, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锋)*/
	{.bitmap_index = 916342, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锌)*/
	{.bitmap_index = 916486, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锍)*/
	{.bitmap_index = 916624, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锎)*/
	{.bitmap_index = 916762, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锏)*/
	{.bitmap_index = 916900, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锐)*/
	{.bitmap_index = 917044, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锑)*/
	{.bitmap_index = 917182, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锒)*/
	{.bitmap_index = 917326, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锓)*/
	{.bitmap_index = 917470, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锔)*/
	{.bitmap_index = 917608, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锕)*/
	{.bitmap_index = 917746, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锖)*/
	{.bitmap_index = 917884, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锗)*/
	{.bitmap_index = 918022, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锘)*/
	{.bitmap_index = 918160, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(错)*/
	{.bitmap_index = 918298, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锚)*/
	{.bitmap_index = 918442, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锛)*/
	{.bitmap_index = 918586, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锝)*/
	{.bitmap_index = 918724, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锞)*/
	{.bitmap_index = 918862, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锟)*/
	{.bitmap_index = 919000, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锡)*/
	{.bitmap_index = 919144, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锢)*/
	{.bitmap_index = 919282, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锣)*/
	{.bitmap_index = 919420, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锤)*/
	{.bitmap_index = 919558, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锥)*/
	{.bitmap_index = 919696, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锦)*/
	{.bitmap_index = 919834, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锨)*/
	{.bitmap_index = 919978, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锩)*/
	{.bitmap_index = 920116, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锪)*/
	{.bitmap_index = 920254, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锫)*/
	{.bitmap_index = 920392, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锬)*/
	{.bitmap_index = 920536, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锭)*/
	{.bitmap_index = 920674, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(键)*/
	{.bitmap_index = 920812, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锯)*/
	{.bitmap_index = 920950, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锰)*/
	{.bitmap_index = 921088, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锱)*/
	{.bitmap_index = 921226, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锲)*/
	{.bitmap_index = 921370, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锴)*/
	{.bitmap_index = 921508, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锵)*/
	{.bitmap_index = 921646, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锶)*/
	{.bitmap_index = 921784, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锷)*/
	{.bitmap_index = 921922, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(锸)*/
	{.bitmap_index = 922060, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锹)*/
	{.bitmap_index = 922198, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(锺)*/
	{.bitmap_index = 922336, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锻)*/
	{.bitmap_index = 922480, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锼)*/
	{.bitmap_index = 922624, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锾)*/
	{.bitmap_index = 922768, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(锿)*/
	{.bitmap_index = 922912, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镀)*/
	{.bitmap_index = 923056, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镁)*/
	{.bitmap_index = 923206, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镂)*/
	{.bitmap_index = 923350, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镄)*/
	{.bitmap_index = 923494, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镅)*/
	{.bitmap_index = 923632, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镆)*/
	{.bitmap_index = 923776, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镇)*/
	{.bitmap_index = 923920, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镉)*/
	{.bitmap_index = 924058, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镊)*/
	{.bitmap_index = 924202, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镌)*/
	{.bitmap_index = 924346, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镍)*/
	{.bitmap_index = 924484, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镎)*/
	{.bitmap_index = 924622, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镏)*/
	{.bitmap_index = 924760, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镐)*/
	{.bitmap_index = 924898, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镑)*/
	{.bitmap_index = 925042, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镒)*/
	{.bitmap_index = 925180, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镓)*/
	{.bitmap_index = 925318, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镔)*/
	{.bitmap_index = 925462, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镖)*/
	{.bitmap_index = 925600, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镗)*/
	{.bitmap_index = 925738, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镘)*/
	{.bitmap_index = 925882, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镙)*/
	{.bitmap_index = 926020, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镛)*/
	{.bitmap_index = 926158, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镜)*/
	{.bitmap_index = 926302, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镝)*/
	{.bitmap_index = 926440, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镞)*/
	{.bitmap_index = 926584, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镟)*/
	{.bitmap_index = 926728, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镡)*/
	{.bitmap_index = 926866, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镢)*/
	{.bitmap_index = 927010, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镣)*/
	{.bitmap_index = 927148, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镤)*/
	{.bitmap_index = 927286, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镥)*/
	{.bitmap_index = 927424, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镦)*/
	{.bitmap_index = 927568, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镧)*/
	{.bitmap_index = 927706, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镨)*/
	{.bitmap_index = 927844, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镩)*/
	{.bitmap_index = 927982, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镪)*/
	{.bitmap_index = 928120, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镫)*/
	{.bitmap_index = 928258, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镬)*/
	{.bitmap_index = 928402, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镭)*/
	{.bitmap_index = 928540, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镯)*/
	{.bitmap_index = 928678, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镰)*/
	{.bitmap_index = 928822, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镱)*/
	{.bitmap_index = 928960, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镲)*/
	{.bitmap_index = 929098, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(镳)*/
	{.bitmap_index = 929236, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(镶)*/
	{.bitmap_index = 929386, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(长)*/
	{.bitmap_index = 929530, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(门)*/
	{.bitmap_index = 929645, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闩)*/
	{.bitmap_index = 929760, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闪)*/
	{.bitmap_index = 929875, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闫)*/
	{.bitmap_index = 929990, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闭)*/
	{.bitmap_index = 930105, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(问)*/
	{.bitmap_index = 930220, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闯)*/
	{.bitmap_index = 930335, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闰)*/
	{.bitmap_index = 930450, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闱)*/
	{.bitmap_index = 930565, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闲)*/
	{.bitmap_index = 930680, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(闳)*/
	{.bitmap_index = 930818, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(间)*/
	{.bitmap_index = 930933, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闵)*/
	{.bitmap_index = 931048, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闶)*/
	{.bitmap_index = 931163, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闷)*/
	{.bitmap_index = 931278, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闸)*/
	{.bitmap_index = 931393, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闹)*/
	{.bitmap_index = 931508, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闺)*/
	{.bitmap_index = 931623, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闻)*/
	{.bitmap_index = 931738, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闼)*/
	{.bitmap_index = 931853, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闽)*/
	{.bitmap_index = 931968, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(闾)*/
	{.bitmap_index = 932088, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阀)*/
	{.bitmap_index = 932203, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阁)*/
	{.bitmap_index = 932341, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(阂)*/
	{.bitmap_index = 932461, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阃)*/
	{.bitmap_index = 932576, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阄)*/
	{.bitmap_index = 932696, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(阅)*/
	{.bitmap_index = 932834, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阆)*/
	{.bitmap_index = 932972, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(阈)*/
	{.bitmap_index = 933092, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(阉)*/
	{.bitmap_index = 933230, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阊)*/
	{.bitmap_index = 933345, .adv_w = 22, .box_h = 24, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阋)*/
	{.bitmap_index = 933465, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阌)*/
	{.bitmap_index = 933580, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阍)*/
	{.bitmap_index = 933695, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阎)*/
	{.bitmap_index = 933810, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阏)*/
	{.bitmap_index = 933925, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阐)*/
	{.bitmap_index = 934040, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阑)*/
	{.bitmap_index = 934155, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阒)*/
	{.bitmap_index = 934293, .adv_w = 22, .box_h = 25, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(阔)*/
	{.bitmap_index = 934418, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阕)*/
	{.bitmap_index = 934556, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阖)*/
	{.bitmap_index = 934671, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阗)*/
	{.bitmap_index = 934786, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阙)*/
	{.bitmap_index = 934924, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阚)*/
	{.bitmap_index = 935039, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阜)*/
	{.bitmap_index = 935177, .adv_w = 14, .box_h = 22, .box_w = 12, .ofs_x = 2, .ofs_y = 5},/*(阝)*/
	{.bitmap_index = 935243, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(队)*/
	{.bitmap_index = 935387, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(阡)*/
	{.bitmap_index = 935519, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(阢)*/
	{.bitmap_index = 935651, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(阪)*/
	{.bitmap_index = 935795, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(阮)*/
	{.bitmap_index = 935933, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(阱)*/
	{.bitmap_index = 936077, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(防)*/
	{.bitmap_index = 936221, .adv_w = 22, .box_h = 22, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(阳)*/
	{.bitmap_index = 936331, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 4},/*(阴)*/
	{.bitmap_index = 936446, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(阵)*/
	{.bitmap_index = 936584, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(阶)*/
	{.bitmap_index = 936728, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阻)*/
	{.bitmap_index = 936860, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阼)*/
	{.bitmap_index = 936998, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(阽)*/
	{.bitmap_index = 937136, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(阿)*/
	{.bitmap_index = 937268, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陀)*/
	{.bitmap_index = 937406, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(陂)*/
	{.bitmap_index = 937550, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(附)*/
	{.bitmap_index = 937688, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(际)*/
	{.bitmap_index = 937820, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陆)*/
	{.bitmap_index = 937958, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(陇)*/
	{.bitmap_index = 938102, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陈)*/
	{.bitmap_index = 938240, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(陉)*/
	{.bitmap_index = 938372, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陋)*/
	{.bitmap_index = 938504, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陌)*/
	{.bitmap_index = 938636, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(降)*/
	{.bitmap_index = 938780, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(限)*/
	{.bitmap_index = 938918, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(陔)*/
	{.bitmap_index = 939062, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(陕)*/
	{.bitmap_index = 939206, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陛)*/
	{.bitmap_index = 939344, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陟)*/
	{.bitmap_index = 939482, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(陡)*/
	{.bitmap_index = 939626, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(院)*/
	{.bitmap_index = 939770, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(除)*/
	{.bitmap_index = 939908, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陧)*/
	{.bitmap_index = 940040, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(陨)*/
	{.bitmap_index = 940178, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(险)*/
	{.bitmap_index = 940316, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陪)*/
	{.bitmap_index = 940454, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(陬)*/
	{.bitmap_index = 940586, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(陲)*/
	{.bitmap_index = 940718, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(陴)*/
	{.bitmap_index = 940856, .adv_w = 26, .box_h = 24, .box_w = 24, .ofs_x = 2, .ofs_y = 4},/*(陵)*/
	{.bitmap_index = 941000, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(陶)*/
	{.bitmap_index = 941138, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(陷)*/
	{.bitmap_index = 941253, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隅)*/
	{.bitmap_index = 941385, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隆)*/
	{.bitmap_index = 941529, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隈)*/
	{.bitmap_index = 941661, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隋)*/
	{.bitmap_index = 941799, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隍)*/
	{.bitmap_index = 941937, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(随)*/
	{.bitmap_index = 942075, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隐)*/
	{.bitmap_index = 942219, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隔)*/
	{.bitmap_index = 942351, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(隗)*/
	{.bitmap_index = 942495, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隘)*/
	{.bitmap_index = 942633, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隙)*/
	{.bitmap_index = 942771, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(障)*/
	{.bitmap_index = 942909, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隧)*/
	{.bitmap_index = 943047, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隰)*/
	{.bitmap_index = 943179, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(隳)*/
	{.bitmap_index = 943317, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(隶)*/
	{.bitmap_index = 943455, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(隹)*/
	{.bitmap_index = 943593, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(隼)*/
	{.bitmap_index = 943731, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(隽)*/
	{.bitmap_index = 943875, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(难)*/
	{.bitmap_index = 944013, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雀)*/
	{.bitmap_index = 944151, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雁)*/
	{.bitmap_index = 944283, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雄)*/
	{.bitmap_index = 944421, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雅)*/
	{.bitmap_index = 944559, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(集)*/
	{.bitmap_index = 944697, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雇)*/
	{.bitmap_index = 944835, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雉)*/
	{.bitmap_index = 944973, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雌)*/
	{.bitmap_index = 945111, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(雍)*/
	{.bitmap_index = 945255, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雎)*/
	{.bitmap_index = 945393, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雏)*/
	{.bitmap_index = 945531, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雒)*/
	{.bitmap_index = 945669, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雕)*/
	{.bitmap_index = 945807, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雠)*/
	{.bitmap_index = 945945, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(雨)*/
	{.bitmap_index = 946077, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(雩)*/
	{.bitmap_index = 946209, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(雪)*/
	{.bitmap_index = 946341, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(雯)*/
	{.bitmap_index = 946479, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(雳)*/
	{.bitmap_index = 946617, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(零)*/
	{.bitmap_index = 946761, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(雷)*/
	{.bitmap_index = 946893, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(雹)*/
	{.bitmap_index = 947025, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(雾)*/
	{.bitmap_index = 947163, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(需)*/
	{.bitmap_index = 947295, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(霁)*/
	{.bitmap_index = 947433, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(霄)*/
	{.bitmap_index = 947565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(霆)*/
	{.bitmap_index = 947703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(震)*/
	{.bitmap_index = 947841, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霈)*/
	{.bitmap_index = 947979, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霉)*/
	{.bitmap_index = 948117, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(霍)*/
	{.bitmap_index = 948249, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霎)*/
	{.bitmap_index = 948393, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(霏)*/
	{.bitmap_index = 948525, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霓)*/
	{.bitmap_index = 948669, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(霖)*/
	{.bitmap_index = 948801, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(霜)*/
	{.bitmap_index = 948933, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霞)*/
	{.bitmap_index = 949077, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霪)*/
	{.bitmap_index = 949221, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霭)*/
	{.bitmap_index = 949365, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(霰)*/
	{.bitmap_index = 949497, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(露)*/
	{.bitmap_index = 949635, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(霸)*/
	{.bitmap_index = 949779, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(霹)*/
	{.bitmap_index = 949917, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(霾)*/
	{.bitmap_index = 950055, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(青)*/
	{.bitmap_index = 950193, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(靓)*/
	{.bitmap_index = 950337, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(靖)*/
	{.bitmap_index = 950475, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(静)*/
	{.bitmap_index = 950613, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(靛)*/
	{.bitmap_index = 950751, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(非)*/
	{.bitmap_index = 950889, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(靠)*/
	{.bitmap_index = 951027, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(靡)*/
	{.bitmap_index = 951165, .adv_w = 25, .box_h = 21, .box_w = 24, .ofs_x = 1, .ofs_y = 6},/*(面)*/
	{.bitmap_index = 951291, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(靥)*/
	{.bitmap_index = 951429, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(革)*/
	{.bitmap_index = 951567, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(靳)*/
	{.bitmap_index = 951711, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(靴)*/
	{.bitmap_index = 951849, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(靶)*/
	{.bitmap_index = 951987, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(靼)*/
	{.bitmap_index = 952125, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鞅)*/
	{.bitmap_index = 952269, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞋)*/
	{.bitmap_index = 952407, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞍)*/
	{.bitmap_index = 952545, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞑)*/
	{.bitmap_index = 952683, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鞒)*/
	{.bitmap_index = 952827, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鞔)*/
	{.bitmap_index = 952971, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞘)*/
	{.bitmap_index = 953109, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞠)*/
	{.bitmap_index = 953247, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞣)*/
	{.bitmap_index = 953385, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞫)*/
	{.bitmap_index = 953523, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞭)*/
	{.bitmap_index = 953661, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞯)*/
	{.bitmap_index = 953799, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞲)*/
	{.bitmap_index = 953937, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鞴)*/
	{.bitmap_index = 954075, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(韦)*/
	{.bitmap_index = 954213, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(韧)*/
	{.bitmap_index = 954357, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(韩)*/
	{.bitmap_index = 954495, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(韪)*/
	{.bitmap_index = 954633, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(韫)*/
	{.bitmap_index = 954771, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(韬)*/
	{.bitmap_index = 954909, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(韭)*/
	{.bitmap_index = 955047, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(音)*/
	{.bitmap_index = 955185, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(韵)*/
	{.bitmap_index = 955323, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(韶)*/
	{.bitmap_index = 955461, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(页)*/
	{.bitmap_index = 955599, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(顶)*/
	{.bitmap_index = 955731, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(顷)*/
	{.bitmap_index = 955875, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(顸)*/
	{.bitmap_index = 956007, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(项)*/
	{.bitmap_index = 956145, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(顺)*/
	{.bitmap_index = 956283, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(须)*/
	{.bitmap_index = 956427, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(顼)*/
	{.bitmap_index = 956565, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(顽)*/
	{.bitmap_index = 956703, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(顾)*/
	{.bitmap_index = 956841, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(顿)*/
	{.bitmap_index = 956985, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颀)*/
	{.bitmap_index = 957129, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颁)*/
	{.bitmap_index = 957273, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颂)*/
	{.bitmap_index = 957417, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颃)*/
	{.bitmap_index = 957561, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(预)*/
	{.bitmap_index = 957699, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颅)*/
	{.bitmap_index = 957843, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(领)*/
	{.bitmap_index = 957987, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颇)*/
	{.bitmap_index = 958131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颈)*/
	{.bitmap_index = 958269, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(颉)*/
	{.bitmap_index = 958413, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颊)*/
	{.bitmap_index = 958557, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颌)*/
	{.bitmap_index = 958701, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颍)*/
	{.bitmap_index = 958845, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颏)*/
	{.bitmap_index = 958989, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(颐)*/
	{.bitmap_index = 959127, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(频)*/
	{.bitmap_index = 959271, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颓)*/
	{.bitmap_index = 959415, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颔)*/
	{.bitmap_index = 959565, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颖)*/
	{.bitmap_index = 959709, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颗)*/
	{.bitmap_index = 959847, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(题)*/
	{.bitmap_index = 959979, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(颚)*/
	{.bitmap_index = 960117, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(颛)*/
	{.bitmap_index = 960255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颜)*/
	{.bitmap_index = 960399, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(额)*/
	{.bitmap_index = 960537, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颞)*/
	{.bitmap_index = 960675, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(颟)*/
	{.bitmap_index = 960819, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颠)*/
	{.bitmap_index = 960963, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(颡)*/
	{.bitmap_index = 961095, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颢)*/
	{.bitmap_index = 961233, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(颤)*/
	{.bitmap_index = 961377, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(颥)*/
	{.bitmap_index = 961515, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(颦)*/
	{.bitmap_index = 961653, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(颧)*/
	{.bitmap_index = 961797, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(风)*/
	{.bitmap_index = 961929, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(飑)*/
	{.bitmap_index = 962067, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(飒)*/
	{.bitmap_index = 962211, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(飓)*/
	{.bitmap_index = 962349, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(飕)*/
	{.bitmap_index = 962487, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(飘)*/
	{.bitmap_index = 962619, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(飙)*/
	{.bitmap_index = 962757, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(飚)*/
	{.bitmap_index = 962895, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(飞)*/
	{.bitmap_index = 963027, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(食)*/
	{.bitmap_index = 963171, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(飧)*/
	{.bitmap_index = 963315, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(飨)*/
	{.bitmap_index = 963459, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(餍)*/
	{.bitmap_index = 963597, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(餐)*/
	{.bitmap_index = 963741, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(餮)*/
	{.bitmap_index = 963885, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饔)*/
	{.bitmap_index = 964029, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饕)*/
	{.bitmap_index = 964173, .adv_w = 16, .box_h = 23, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(饣)*/
	{.bitmap_index = 964265, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饥)*/
	{.bitmap_index = 964409, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饧)*/
	{.bitmap_index = 964553, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饨)*/
	{.bitmap_index = 964691, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饩)*/
	{.bitmap_index = 964835, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饪)*/
	{.bitmap_index = 964973, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饫)*/
	{.bitmap_index = 965117, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饬)*/
	{.bitmap_index = 965255, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饭)*/
	{.bitmap_index = 965399, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饮)*/
	{.bitmap_index = 965543, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饯)*/
	{.bitmap_index = 965681, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饰)*/
	{.bitmap_index = 965819, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饱)*/
	{.bitmap_index = 965957, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饲)*/
	{.bitmap_index = 966095, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饴)*/
	{.bitmap_index = 966233, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饵)*/
	{.bitmap_index = 966371, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饶)*/
	{.bitmap_index = 966515, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饷)*/
	{.bitmap_index = 966653, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饺)*/
	{.bitmap_index = 966797, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饼)*/
	{.bitmap_index = 966941, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(饽)*/
	{.bitmap_index = 967079, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(饿)*/
	{.bitmap_index = 967223, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馀)*/
	{.bitmap_index = 967361, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馁)*/
	{.bitmap_index = 967499, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馄)*/
	{.bitmap_index = 967637, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馅)*/
	{.bitmap_index = 967775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馆)*/
	{.bitmap_index = 967913, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馇)*/
	{.bitmap_index = 968051, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馈)*/
	{.bitmap_index = 968195, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馊)*/
	{.bitmap_index = 968339, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馋)*/
	{.bitmap_index = 968489, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馍)*/
	{.bitmap_index = 968633, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馏)*/
	{.bitmap_index = 968771, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馐)*/
	{.bitmap_index = 968909, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馑)*/
	{.bitmap_index = 969047, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馒)*/
	{.bitmap_index = 969191, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馓)*/
	{.bitmap_index = 969335, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馔)*/
	{.bitmap_index = 969479, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馕)*/
	{.bitmap_index = 969623, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(首)*/
	{.bitmap_index = 969761, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馗)*/
	{.bitmap_index = 969899, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(馘)*/
	{.bitmap_index = 970037, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(香)*/
	{.bitmap_index = 970175, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(馥)*/
	{.bitmap_index = 970319, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(馨)*/
	{.bitmap_index = 970457, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(马)*/
	{.bitmap_index = 970589, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(驭)*/
	{.bitmap_index = 970727, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(驮)*/
	{.bitmap_index = 970871, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(驯)*/
	{.bitmap_index = 971015, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驰)*/
	{.bitmap_index = 971153, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驱)*/
	{.bitmap_index = 971285, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(驳)*/
	{.bitmap_index = 971429, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(驴)*/
	{.bitmap_index = 971573, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驵)*/
	{.bitmap_index = 971705, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(驶)*/
	{.bitmap_index = 971849, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驷)*/
	{.bitmap_index = 971981, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驸)*/
	{.bitmap_index = 972119, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驹)*/
	{.bitmap_index = 972257, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驺)*/
	{.bitmap_index = 972395, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驻)*/
	{.bitmap_index = 972533, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驼)*/
	{.bitmap_index = 972671, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驽)*/
	{.bitmap_index = 972809, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驾)*/
	{.bitmap_index = 972947, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(驿)*/
	{.bitmap_index = 973079, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骀)*/
	{.bitmap_index = 973217, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骁)*/
	{.bitmap_index = 973355, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骂)*/
	{.bitmap_index = 973487, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骄)*/
	{.bitmap_index = 973631, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骅)*/
	{.bitmap_index = 973775, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骆)*/
	{.bitmap_index = 973913, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骇)*/
	{.bitmap_index = 974057, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骈)*/
	{.bitmap_index = 974201, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骊)*/
	{.bitmap_index = 974333, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骋)*/
	{.bitmap_index = 974471, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(验)*/
	{.bitmap_index = 974609, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(骏)*/
	{.bitmap_index = 974753, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骐)*/
	{.bitmap_index = 974897, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骑)*/
	{.bitmap_index = 975035, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骒)*/
	{.bitmap_index = 975167, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骓)*/
	{.bitmap_index = 975305, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骖)*/
	{.bitmap_index = 975449, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骗)*/
	{.bitmap_index = 975587, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骘)*/
	{.bitmap_index = 975725, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骚)*/
	{.bitmap_index = 975857, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骛)*/
	{.bitmap_index = 975995, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骜)*/
	{.bitmap_index = 976133, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骝)*/
	{.bitmap_index = 976271, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骞)*/
	{.bitmap_index = 976415, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骟)*/
	{.bitmap_index = 976553, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骠)*/
	{.bitmap_index = 976685, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骡)*/
	{.bitmap_index = 976817, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骢)*/
	{.bitmap_index = 976955, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(骣)*/
	{.bitmap_index = 977087, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骤)*/
	{.bitmap_index = 977219, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骥)*/
	{.bitmap_index = 977363, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(骧)*/
	{.bitmap_index = 977507, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骨)*/
	{.bitmap_index = 977645, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(骰)*/
	{.bitmap_index = 977783, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(骱)*/
	{.bitmap_index = 977927, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(骶)*/
	{.bitmap_index = 978071, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骷)*/
	{.bitmap_index = 978209, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(骸)*/
	{.bitmap_index = 978353, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骺)*/
	{.bitmap_index = 978491, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(骼)*/
	{.bitmap_index = 978629, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髀)*/
	{.bitmap_index = 978767, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髁)*/
	{.bitmap_index = 978899, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髂)*/
	{.bitmap_index = 979037, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(髅)*/
	{.bitmap_index = 979181, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(髋)*/
	{.bitmap_index = 979325, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髌)*/
	{.bitmap_index = 979463, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(髑)*/
	{.bitmap_index = 979601, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(髓)*/
	{.bitmap_index = 979739, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(高)*/
	{.bitmap_index = 979877, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髟)*/
	{.bitmap_index = 980015, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(髡)*/
	{.bitmap_index = 980159, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髦)*/
	{.bitmap_index = 980297, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髫)*/
	{.bitmap_index = 980435, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髭)*/
	{.bitmap_index = 980573, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髯)*/
	{.bitmap_index = 980711, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(髹)*/
	{.bitmap_index = 980849, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(髻)*/
	{.bitmap_index = 980987, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鬃)*/
	{.bitmap_index = 981131, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鬈)*/
	{.bitmap_index = 981269, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鬏)*/
	{.bitmap_index = 981413, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鬓)*/
	{.bitmap_index = 981557, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鬟)*/
	{.bitmap_index = 981701, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鬣)*/
	{.bitmap_index = 981845, .adv_w = 22, .box_h = 23, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*(鬯)*/
	{.bitmap_index = 981960, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鬲)*/
	{.bitmap_index = 982092, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鬻)*/
	{.bitmap_index = 982230, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鬼)*/
	{.bitmap_index = 982374, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魁)*/
	{.bitmap_index = 982512, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(魂)*/
	{.bitmap_index = 982656, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魃)*/
	{.bitmap_index = 982794, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(魄)*/
	{.bitmap_index = 982938, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魅)*/
	{.bitmap_index = 983076, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(魇)*/
	{.bitmap_index = 983214, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魈)*/
	{.bitmap_index = 983352, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魉)*/
	{.bitmap_index = 983490, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魍)*/
	{.bitmap_index = 983628, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(魏)*/
	{.bitmap_index = 983772, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(魑)*/
	{.bitmap_index = 983910, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(魔)*/
	{.bitmap_index = 984054, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 6},/*(鱼)*/
	{.bitmap_index = 984186, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鱿)*/
	{.bitmap_index = 984324, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲁)*/
	{.bitmap_index = 984468, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲂)*/
	{.bitmap_index = 984606, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲅)*/
	{.bitmap_index = 984750, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲆)*/
	{.bitmap_index = 984888, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲇)*/
	{.bitmap_index = 985026, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲈)*/
	{.bitmap_index = 985170, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲋)*/
	{.bitmap_index = 985308, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲍)*/
	{.bitmap_index = 985446, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鲎)*/
	{.bitmap_index = 985584, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲐)*/
	{.bitmap_index = 985722, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲑)*/
	{.bitmap_index = 985860, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲒)*/
	{.bitmap_index = 985998, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲔)*/
	{.bitmap_index = 986136, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲕)*/
	{.bitmap_index = 986274, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲚)*/
	{.bitmap_index = 986424, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲛)*/
	{.bitmap_index = 986568, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲜)*/
	{.bitmap_index = 986706, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲞)*/
	{.bitmap_index = 986844, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲟)*/
	{.bitmap_index = 986982, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲠)*/
	{.bitmap_index = 987126, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲡)*/
	{.bitmap_index = 987264, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲢)*/
	{.bitmap_index = 987402, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲣)*/
	{.bitmap_index = 987540, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲤)*/
	{.bitmap_index = 987678, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲥)*/
	{.bitmap_index = 987816, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲦)*/
	{.bitmap_index = 987954, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲧)*/
	{.bitmap_index = 988092, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鲨)*/
	{.bitmap_index = 988230, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲩)*/
	{.bitmap_index = 988374, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲫)*/
	{.bitmap_index = 988512, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲭)*/
	{.bitmap_index = 988650, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲮)*/
	{.bitmap_index = 988794, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲰)*/
	{.bitmap_index = 988932, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲱)*/
	{.bitmap_index = 989070, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲲)*/
	{.bitmap_index = 989208, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲳)*/
	{.bitmap_index = 989346, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲴)*/
	{.bitmap_index = 989484, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲵)*/
	{.bitmap_index = 989628, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲶)*/
	{.bitmap_index = 989766, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲷)*/
	{.bitmap_index = 989904, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲸)*/
	{.bitmap_index = 990042, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲺)*/
	{.bitmap_index = 990180, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲻)*/
	{.bitmap_index = 990318, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鲼)*/
	{.bitmap_index = 990462, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鲽)*/
	{.bitmap_index = 990600, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳃)*/
	{.bitmap_index = 990738, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳄)*/
	{.bitmap_index = 990876, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳅)*/
	{.bitmap_index = 991014, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鳆)*/
	{.bitmap_index = 991158, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳇)*/
	{.bitmap_index = 991296, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳊)*/
	{.bitmap_index = 991434, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳋)*/
	{.bitmap_index = 991572, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳌)*/
	{.bitmap_index = 991716, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳍)*/
	{.bitmap_index = 991854, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳎)*/
	{.bitmap_index = 991992, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳏)*/
	{.bitmap_index = 992130, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳐)*/
	{.bitmap_index = 992268, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳓)*/
	{.bitmap_index = 992406, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳔)*/
	{.bitmap_index = 992544, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳕)*/
	{.bitmap_index = 992682, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鳖)*/
	{.bitmap_index = 992820, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鳗)*/
	{.bitmap_index = 992964, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鳘)*/
	{.bitmap_index = 993102, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳙)*/
	{.bitmap_index = 993240, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鳜)*/
	{.bitmap_index = 993384, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳝)*/
	{.bitmap_index = 993522, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鳞)*/
	{.bitmap_index = 993666, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳟)*/
	{.bitmap_index = 993804, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鳢)*/
	{.bitmap_index = 993942, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸟)*/
	{.bitmap_index = 994080, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸠)*/
	{.bitmap_index = 994218, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸡)*/
	{.bitmap_index = 994356, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸢)*/
	{.bitmap_index = 994500, .adv_w = 26, .box_h = 23, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(鸣)*/
	{.bitmap_index = 994638, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸥)*/
	{.bitmap_index = 994776, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸦)*/
	{.bitmap_index = 994914, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸨)*/
	{.bitmap_index = 995052, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸩)*/
	{.bitmap_index = 995190, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸪)*/
	{.bitmap_index = 995328, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸫)*/
	{.bitmap_index = 995466, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸬)*/
	{.bitmap_index = 995604, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸭)*/
	{.bitmap_index = 995742, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鸯)*/
	{.bitmap_index = 995886, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸱)*/
	{.bitmap_index = 996024, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸲)*/
	{.bitmap_index = 996162, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸳)*/
	{.bitmap_index = 996300, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸵)*/
	{.bitmap_index = 996438, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸶)*/
	{.bitmap_index = 996582, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鸷)*/
	{.bitmap_index = 996726, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸸)*/
	{.bitmap_index = 996864, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鸹)*/
	{.bitmap_index = 997002, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸺)*/
	{.bitmap_index = 997140, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸽)*/
	{.bitmap_index = 997284, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鸾)*/
	{.bitmap_index = 997428, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鸿)*/
	{.bitmap_index = 997566, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹁)*/
	{.bitmap_index = 997704, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹂)*/
	{.bitmap_index = 997842, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹃)*/
	{.bitmap_index = 997980, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹄)*/
	{.bitmap_index = 998118, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹅)*/
	{.bitmap_index = 998256, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹆)*/
	{.bitmap_index = 998394, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹇)*/
	{.bitmap_index = 998532, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹈)*/
	{.bitmap_index = 998670, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹉)*/
	{.bitmap_index = 998808, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹊)*/
	{.bitmap_index = 998946, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹋)*/
	{.bitmap_index = 999084, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹌)*/
	{.bitmap_index = 999222, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹎)*/
	{.bitmap_index = 999360, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹏)*/
	{.bitmap_index = 999498, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹑)*/
	{.bitmap_index = 999636, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鹕)*/
	{.bitmap_index = 999780, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹗)*/
	{.bitmap_index = 999918, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鹘)*/
	{.bitmap_index = 1000062, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹚)*/
	{.bitmap_index = 1000200, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹛)*/
	{.bitmap_index = 1000338, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹜)*/
	{.bitmap_index = 1000476, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹞)*/
	{.bitmap_index = 1000614, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹣)*/
	{.bitmap_index = 1000752, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹤)*/
	{.bitmap_index = 1000890, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹦)*/
	{.bitmap_index = 1001028, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹧)*/
	{.bitmap_index = 1001166, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鹨)*/
	{.bitmap_index = 1001310, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹩)*/
	{.bitmap_index = 1001448, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹪)*/
	{.bitmap_index = 1001586, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹫)*/
	{.bitmap_index = 1001724, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹬)*/
	{.bitmap_index = 1001862, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹭)*/
	{.bitmap_index = 1002006, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹰)*/
	{.bitmap_index = 1002144, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鹱)*/
	{.bitmap_index = 1002288, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(鹳)*/
	{.bitmap_index = 1002426, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鹾)*/
	{.bitmap_index = 1002564, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鹿)*/
	{.bitmap_index = 1002708, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(麂)*/
	{.bitmap_index = 1002852, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麇)*/
	{.bitmap_index = 1002990, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麈)*/
	{.bitmap_index = 1003128, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麋)*/
	{.bitmap_index = 1003266, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麒)*/
	{.bitmap_index = 1003404, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(麓)*/
	{.bitmap_index = 1003548, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麝)*/
	{.bitmap_index = 1003686, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(麟)*/
	{.bitmap_index = 1003830, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(麦)*/
	{.bitmap_index = 1003974, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麴)*/
	{.bitmap_index = 1004112, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(麸)*/
	{.bitmap_index = 1004256, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(麻)*/
	{.bitmap_index = 1004400, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麽)*/
	{.bitmap_index = 1004544, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(麾)*/
	{.bitmap_index = 1004682, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(黄)*/
	{.bitmap_index = 1004826, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(黉)*/
	{.bitmap_index = 1004970, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黍)*/
	{.bitmap_index = 1005108, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黎)*/
	{.bitmap_index = 1005246, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黏)*/
	{.bitmap_index = 1005384, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(黑)*/
	{.bitmap_index = 1005522, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(黔)*/
	{.bitmap_index = 1005672, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(默)*/
	{.bitmap_index = 1005816, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(黛)*/
	{.bitmap_index = 1005966, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黜)*/
	{.bitmap_index = 1006104, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黝)*/
	{.bitmap_index = 1006242, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(黟)*/
	{.bitmap_index = 1006386, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黠)*/
	{.bitmap_index = 1006524, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(黢)*/
	{.bitmap_index = 1006668, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黥)*/
	{.bitmap_index = 1006806, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(黧)*/
	{.bitmap_index = 1006950, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(黩)*/
	{.bitmap_index = 1007094, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(黪)*/
	{.bitmap_index = 1007238, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(黯)*/
	{.bitmap_index = 1007376, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(黹)*/
	{.bitmap_index = 1007514, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(黻)*/
	{.bitmap_index = 1007652, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(黼)*/
	{.bitmap_index = 1007790, .adv_w = 26, .box_h = 22, .box_w = 24, .ofs_x = 2, .ofs_y = 5},/*(黾)*/
	{.bitmap_index = 1007922, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鼋)*/
	{.bitmap_index = 1008054, .adv_w = 25, .box_h = 22, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鼍)*/
	{.bitmap_index = 1008186, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鼎)*/
	{.bitmap_index = 1008330, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鼐)*/
	{.bitmap_index = 1008468, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(鼓)*/
	{.bitmap_index = 1008612, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼗)*/
	{.bitmap_index = 1008756, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鼙)*/
	{.bitmap_index = 1008894, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼠)*/
	{.bitmap_index = 1009038, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼢)*/
	{.bitmap_index = 1009182, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(鼬)*/
	{.bitmap_index = 1009320, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼯)*/
	{.bitmap_index = 1009464, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼷)*/
	{.bitmap_index = 1009608, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼹)*/
	{.bitmap_index = 1009752, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼻)*/
	{.bitmap_index = 1009896, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼽)*/
	{.bitmap_index = 1010040, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(鼾)*/
	{.bitmap_index = 1010184, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(齄)*/
	{.bitmap_index = 1010328, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(齐)*/
	{.bitmap_index = 1010472, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(齑)*/
	{.bitmap_index = 1010616, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(齿)*/
	{.bitmap_index = 1010754, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龀)*/
	{.bitmap_index = 1010892, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龃)*/
	{.bitmap_index = 1011030, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(龄)*/
	{.bitmap_index = 1011174, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龅)*/
	{.bitmap_index = 1011312, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龆)*/
	{.bitmap_index = 1011450, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龇)*/
	{.bitmap_index = 1011588, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(龈)*/
	{.bitmap_index = 1011732, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龉)*/
	{.bitmap_index = 1011870, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龊)*/
	{.bitmap_index = 1012008, .adv_w = 25, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = 5},/*(龋)*/
	{.bitmap_index = 1012146, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(龌)*/
	{.bitmap_index = 1012290, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(龙)*/
	{.bitmap_index = 1012428, .adv_w = 25, .box_h = 24, .box_w = 24, .ofs_x = 1, .ofs_y = 4},/*(龚)*/
	{.bitmap_index = 1012572, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*(龛)*/
	{.bitmap_index = 1012716, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(龟)*/
	{.bitmap_index = 1012860, .adv_w = 24, .box_h = 23, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*(龠)*/
	{.bitmap_index = 1012998, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*()*/
	{.bitmap_index = 1013103, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*()*/
	{.bitmap_index = 1013208, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*()*/
	{.bitmap_index = 1013313, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*()*/
	{.bitmap_index = 1013418, .adv_w = 22, .box_h = 21, .box_w = 20, .ofs_x = 2, .ofs_y = 5},/*()*/
	{.bitmap_index = 1013873, .adv_w = 24, .box_h = 25, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1014023, .adv_w = 24, .box_h = 18, .box_w = 24, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1014131, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1014257, .adv_w = 24, .box_h = 18, .box_w = 24, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1014365, .adv_w = 20, .box_h = 17, .box_w = 20, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1014450, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1014594, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1014738, .adv_w = 28, .box_h = 21, .box_w = 28, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1014885, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1015029, .adv_w = 28, .box_h = 18, .box_w = 28, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1015155, .adv_w = 24, .box_h = 26, .box_w = 24, .ofs_x = 0, .ofs_y = -1},/*()*/
	{.bitmap_index = 1015311, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1015368, .adv_w = 20, .box_h = 19, .box_w = 20, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1015463, .adv_w = 28, .box_h = 24, .box_w = 28, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1015631, .adv_w = 24, .box_h = 18, .box_w = 24, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1015739, .adv_w = 16, .box_h = 24, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1015835, .adv_w = 19, .box_h = 23, .box_w = 16, .ofs_x = 3, .ofs_y = 0},/*()*/
	{.bitmap_index = 1015927, .adv_w = 24, .box_h = 26, .box_w = 24, .ofs_x = 0, .ofs_y = -1},/*()*/
	{.bitmap_index = 1016083, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1016209, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1016335, .adv_w = 19, .box_h = 23, .box_w = 16, .ofs_x = 3, .ofs_y = 0},/*()*/
	{.bitmap_index = 1016427, .adv_w = 23, .box_h = 22, .box_w = 24, .ofs_x = -1, .ofs_y = 1},/*()*/
	{.bitmap_index = 1016559, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 1},/*()*/
	{.bitmap_index = 1016647, .adv_w = 17, .box_h = 22, .box_w = 16, .ofs_x = 1, .ofs_y = 1},/*()*/
	{.bitmap_index = 1016735, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1016861, .adv_w = 24, .box_h = 5, .box_w = 24, .ofs_x = 0, .ofs_y = 10},/*()*/
	{.bitmap_index = 1016891, .adv_w = 28, .box_h = 18, .box_w = 28, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1017017, .adv_w = 31, .box_h = 24, .box_w = 32, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 1017209, .adv_w = 31, .box_h = 24, .box_w = 32, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 1017401, .adv_w = 24, .box_h = 22, .box_w = 24, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1017533, .adv_w = 24, .box_h = 14, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*()*/
	{.bitmap_index = 1017617, .adv_w = 24, .box_h = 14, .box_w = 24, .ofs_x = 0, .ofs_y = 5},/*()*/
	{.bitmap_index = 1017701, .adv_w = 31, .box_h = 19, .box_w = 32, .ofs_x = -1, .ofs_y = 2},/*()*/
	{.bitmap_index = 1017853, .adv_w = 24, .box_h = 18, .box_w = 24, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1017961, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1018105, .adv_w = 27, .box_h = 25, .box_w = 28, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 1018280, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1018406, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1018550, .adv_w = 24, .box_h = 21, .box_w = 24, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1018676, .adv_w = 24, .box_h = 20, .box_w = 24, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1018796, .adv_w = 24, .box_h = 18, .box_w = 24, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1018904, .adv_w = 19, .box_h = 24, .box_w = 20, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 1019024, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1019168, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1019312, .adv_w = 28, .box_h = 18, .box_w = 28, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1019438, .adv_w = 27, .box_h = 26, .box_w = 28, .ofs_x = -1, .ofs_y = -1},/*()*/
	{.bitmap_index = 1019620, .adv_w = 20, .box_h = 24, .box_w = 20, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1019740, .adv_w = 32, .box_h = 23, .box_w = 32, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1019924, .adv_w = 32, .box_h = 15, .box_w = 32, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1020044, .adv_w = 32, .box_h = 15, .box_w = 32, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1020164, .adv_w = 32, .box_h = 15, .box_w = 32, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1020284, .adv_w = 32, .box_h = 15, .box_w = 32, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1020404, .adv_w = 32, .box_h = 15, .box_w = 32, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1020524, .adv_w = 32, .box_h = 20, .box_w = 32, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1020684, .adv_w = 21, .box_h = 24, .box_w = 20, .ofs_x = 1, .ofs_y = 0},/*()*/
	{.bitmap_index = 1020804, .adv_w = 24, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1020948, .adv_w = 27, .box_h = 25, .box_w = 28, .ofs_x = -1, .ofs_y = -1},/*()*/
	{.bitmap_index = 1021123, .adv_w = 32, .box_h = 18, .box_w = 32, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 1021267, .adv_w = 20, .box_h = 24, .box_w = 20, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1021387, .adv_w = 24, .box_h = 16, .box_w = 24, .ofs_x = 0, .ofs_y = 4},/*()*/
	{.bitmap_index = 1013523, .adv_w = 8, .box_h = 20, .box_w = 4, .ofs_x = 4, .ofs_y = 6},/*(！)*/
	{.bitmap_index = 1013543, .adv_w = 23, .box_h = 24, .box_w = 8, .ofs_x = 15, .ofs_y = 4},/*(（)*/
	{.bitmap_index = 1013591, .adv_w = 9, .box_h = 24, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(）)*/
	{.bitmap_index = 1013639, .adv_w = 11, .box_h = 8, .box_w = 8, .ofs_x = 3, .ofs_y = 2},/*(，)*/
	{.bitmap_index = 1013655, .adv_w = 8, .box_h = 14, .box_w = 4, .ofs_x = 4, .ofs_y = 6},/*(：)*/
	{.bitmap_index = 1013669, .adv_w = 11, .box_h = 18, .box_w = 8, .ofs_x = 3, .ofs_y = 2},/*(；)*/
	{.bitmap_index = 1013705, .adv_w = 16, .box_h = 21, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(？)*/
	{.bitmap_index = 1013789, .adv_w = 20, .box_h = 21, .box_w = 16, .ofs_x = 4, .ofs_y = 6},/*(￥)*/

};


static const uint16_t unicode_list[] = {
	0x0020,	/*( )*/
	0x0021,	/*(!)*/
	0x0022,	/*(")*/
	0x0023,	/*(#)*/
	0x0024,	/*($)*/
	0x0025,	/*(%)*/
	0x0026,	/*(&)*/
	0x0027,	/*(')*/
	0x0028,	/*(()*/
	0x0029,	/*())*/
	0x002a,	/*(*)*/
	0x002b,	/*(+)*/
	0x002c,	/*(,)*/
	0x002d,	/*(-)*/
	0x002e,	/*(.)*/
	0x002f,	/*(/)*/
	0x0030,	/*(0)*/
	0x0031,	/*(1)*/
	0x0032,	/*(2)*/
	0x0033,	/*(3)*/
	0x0034,	/*(4)*/
	0x0035,	/*(5)*/
	0x0036,	/*(6)*/
	0x0037,	/*(7)*/
	0x0038,	/*(8)*/
	0x0039,	/*(9)*/
	0x003a,	/*(:)*/
	0x003b,	/*(;)*/
	0x003c,	/*(<)*/
	0x003d,	/*(=)*/
	0x003e,	/*(>)*/
	0x003f,	/*(?)*/
	0x0040,	/*(@)*/
	0x0041,	/*(A)*/
	0x0042,	/*(B)*/
	0x0043,	/*(C)*/
	0x0044,	/*(D)*/
	0x0045,	/*(E)*/
	0x0046,	/*(F)*/
	0x0047,	/*(G)*/
	0x0048,	/*(H)*/
	0x0049,	/*(I)*/
	0x004a,	/*(J)*/
	0x004b,	/*(K)*/
	0x004c,	/*(L)*/
	0x004d,	/*(M)*/
	0x004e,	/*(N)*/
	0x004f,	/*(O)*/
	0x0050,	/*(P)*/
	0x0051,	/*(Q)*/
	0x0052,	/*(R)*/
	0x0053,	/*(S)*/
	0x0054,	/*(T)*/
	0x0055,	/*(U)*/
	0x0056,	/*(V)*/
	0x0057,	/*(W)*/
	0x0058,	/*(X)*/
	0x0059,	/*(Y)*/
	0x005a,	/*(Z)*/
	0x005b,	/*([)*/
	0x005c,	/*(\)*/
	0x005d,	/*(])*/
	0x005e,	/*(^)*/
	0x005f,	/*(_)*/
	0x0060,	/*(`)*/
	0x0061,	/*(a)*/
	0x0062,	/*(b)*/
	0x0063,	/*(c)*/
	0x0064,	/*(d)*/
	0x0065,	/*(e)*/
	0x0066,	/*(f)*/
	0x0067,	/*(g)*/
	0x0068,	/*(h)*/
	0x0069,	/*(i)*/
	0x006a,	/*(j)*/
	0x006b,	/*(k)*/
	0x006c,	/*(l)*/
	0x006d,	/*(m)*/
	0x006e,	/*(n)*/
	0x006f,	/*(o)*/
	0x0070,	/*(p)*/
	0x0071,	/*(q)*/
	0x0072,	/*(r)*/
	0x0073,	/*(s)*/
	0x0074,	/*(t)*/
	0x0075,	/*(u)*/
	0x0076,	/*(v)*/
	0x0077,	/*(w)*/
	0x0078,	/*(x)*/
	0x0079,	/*(y)*/
	0x007a,	/*(z)*/
	0x007b,	/*({)*/
	0x007c,	/*(|)*/
	0x007d,	/*(})*/
	0x007e,	/*(~)*/
	0x00a1,	/*(¡)*/
	0x00a2,	/*(¢)*/
	0x00a3,	/*(£)*/
	0x00a4,	/*(¤)*/
	0x00a5,	/*(¥)*/
	0x00a6,	/*(¦)*/
	0x00a7,	/*(§)*/
	0x00a8,	/*(¨)*/
	0x00a9,	/*(©)*/
	0x00aa,	/*(ª)*/
	0x00ab,	/*(«)*/
	0x00ac,	/*(¬)*/
	0x00ad,	/*(­)*/
	0x00ae,	/*(®)*/
	0x00af,	/*(¯)*/
	0x00b0,	/*(°)*/
	0x00b1,	/*(±)*/
	0x00b2,	/*(²)*/
	0x00b3,	/*(³)*/
	0x00b4,	/*(´)*/
	0x00b5,	/*(µ)*/
	0x00b6,	/*(¶)*/
	0x00b7,	/*(·)*/
	0x00b8,	/*(¸)*/
	0x00b9,	/*(¹)*/
	0x00ba,	/*(º)*/
	0x00bb,	/*(»)*/
	0x00bc,	/*(¼)*/
	0x00bd,	/*(½)*/
	0x00be,	/*(¾)*/
	0x00bf,	/*(¿)*/
	0x00c0,	/*(À)*/
	0x00c1,	/*(Á)*/
	0x00c2,	/*(Â)*/
	0x00c3,	/*(Ã)*/
	0x00c4,	/*(Ä)*/
	0x00c5,	/*(Å)*/
	0x00c6,	/*(Æ)*/
	0x00c7,	/*(Ç)*/
	0x00c8,	/*(È)*/
	0x00c9,	/*(É)*/
	0x00ca,	/*(Ê)*/
	0x00cb,	/*(Ë)*/
	0x00cc,	/*(Ì)*/
	0x00cd,	/*(Í)*/
	0x00ce,	/*(Î)*/
	0x00cf,	/*(Ï)*/
	0x00d0,	/*(Ð)*/
	0x00d1,	/*(Ñ)*/
	0x00d2,	/*(Ò)*/
	0x00d3,	/*(Ó)*/
	0x00d4,	/*(Ô)*/
	0x00d5,	/*(Õ)*/
	0x00d6,	/*(Ö)*/
	0x00d7,	/*(×)*/
	0x00d8,	/*(Ø)*/
	0x00d9,	/*(Ù)*/
	0x00da,	/*(Ú)*/
	0x00db,	/*(Û)*/
	0x00dc,	/*(Ü)*/
	0x00dd,	/*(Ý)*/
	0x00de,	/*(Þ)*/
	0x00df,	/*(ß)*/
	0x00e0,	/*(à)*/
	0x00e1,	/*(á)*/
	0x00e2,	/*(â)*/
	0x00e3,	/*(ã)*/
	0x00e4,	/*(ä)*/
	0x00e5,	/*(å)*/
	0x00e6,	/*(æ)*/
	0x00e7,	/*(ç)*/
	0x00e8,	/*(è)*/
	0x00e9,	/*(é)*/
	0x00ea,	/*(ê)*/
	0x00eb,	/*(ë)*/
	0x00ec,	/*(ì)*/
	0x00ed,	/*(í)*/
	0x00ee,	/*(î)*/
	0x00ef,	/*(ï)*/
	0x00f0,	/*(ð)*/
	0x00f1,	/*(ñ)*/
	0x00f2,	/*(ò)*/
	0x00f3,	/*(ó)*/
	0x00f4,	/*(ô)*/
	0x00f5,	/*(õ)*/
	0x00f6,	/*(ö)*/
	0x00f7,	/*(÷)*/
	0x00f8,	/*(ø)*/
	0x00f9,	/*(ù)*/
	0x00fa,	/*(ú)*/
	0x00fb,	/*(û)*/
	0x00fc,	/*(ü)*/
	0x00fd,	/*(ý)*/
	0x00fe,	/*(þ)*/
	0x00ff,	/*(ÿ)*/
	0x0100,	/*(Ā)*/
	0x0101,	/*(ā)*/
	0x0102,	/*(Ă)*/
	0x0103,	/*(ă)*/
	0x0104,	/*(Ą)*/
	0x0105,	/*(ą)*/
	0x0106,	/*(Ć)*/
	0x0107,	/*(ć)*/
	0x0108,	/*(Ĉ)*/
	0x0109,	/*(ĉ)*/
	0x010a,	/*(Ċ)*/
	0x010b,	/*(ċ)*/
	0x010c,	/*(Č)*/
	0x010d,	/*(č)*/
	0x010e,	/*(Ď)*/
	0x010f,	/*(ď)*/
	0x0110,	/*(Đ)*/
	0x0111,	/*(đ)*/
	0x0112,	/*(Ē)*/
	0x0113,	/*(ē)*/
	0x0114,	/*(Ĕ)*/
	0x0115,	/*(ĕ)*/
	0x0116,	/*(Ė)*/
	0x0117,	/*(ė)*/
	0x0118,	/*(Ę)*/
	0x0119,	/*(ę)*/
	0x011a,	/*(Ě)*/
	0x011b,	/*(ě)*/
	0x011c,	/*(Ĝ)*/
	0x011d,	/*(ĝ)*/
	0x011e,	/*(Ğ)*/
	0x011f,	/*(ğ)*/
	0x0120,	/*(Ġ)*/
	0x0121,	/*(ġ)*/
	0x0122,	/*(Ģ)*/
	0x0123,	/*(ģ)*/
	0x0124,	/*(Ĥ)*/
	0x0125,	/*(ĥ)*/
	0x0126,	/*(Ħ)*/
	0x0127,	/*(ħ)*/
	0x0128,	/*(Ĩ)*/
	0x0129,	/*(ĩ)*/
	0x012a,	/*(Ī)*/
	0x012b,	/*(ī)*/
	0x012c,	/*(Ĭ)*/
	0x012d,	/*(ĭ)*/
	0x012e,	/*(Į)*/
	0x012f,	/*(į)*/
	0x0130,	/*(İ)*/
	0x0131,	/*(ı)*/
	0x0132,	/*(Ĳ)*/
	0x0133,	/*(ĳ)*/
	0x0134,	/*(Ĵ)*/
	0x0135,	/*(ĵ)*/
	0x0136,	/*(Ķ)*/
	0x0137,	/*(ķ)*/
	0x0138,	/*(ĸ)*/
	0x0139,	/*(Ĺ)*/
	0x013a,	/*(ĺ)*/
	0x013b,	/*(Ļ)*/
	0x013c,	/*(ļ)*/
	0x013d,	/*(Ľ)*/
	0x013e,	/*(ľ)*/
	0x013f,	/*(Ŀ)*/
	0x0140,	/*(ŀ)*/
	0x0141,	/*(Ł)*/
	0x0142,	/*(ł)*/
	0x0143,	/*(Ń)*/
	0x0144,	/*(ń)*/
	0x0145,	/*(Ņ)*/
	0x0146,	/*(ņ)*/
	0x0147,	/*(Ň)*/
	0x0148,	/*(ň)*/
	0x0149,	/*(ŉ)*/
	0x014a,	/*(Ŋ)*/
	0x014b,	/*(ŋ)*/
	0x014c,	/*(Ō)*/
	0x014d,	/*(ō)*/
	0x014e,	/*(Ŏ)*/
	0x014f,	/*(ŏ)*/
	0x0150,	/*(Ő)*/
	0x0151,	/*(ő)*/
	0x0152,	/*(Œ)*/
	0x0153,	/*(œ)*/
	0x0154,	/*(Ŕ)*/
	0x0155,	/*(ŕ)*/
	0x0156,	/*(Ŗ)*/
	0x0157,	/*(ŗ)*/
	0x0158,	/*(Ř)*/
	0x0159,	/*(ř)*/
	0x015a,	/*(Ś)*/
	0x015b,	/*(ś)*/
	0x015c,	/*(Ŝ)*/
	0x015d,	/*(ŝ)*/
	0x015e,	/*(Ş)*/
	0x015f,	/*(ş)*/
	0x0160,	/*(Š)*/
	0x0161,	/*(š)*/
	0x0162,	/*(Ţ)*/
	0x0163,	/*(ţ)*/
	0x0164,	/*(Ť)*/
	0x0165,	/*(ť)*/
	0x0166,	/*(Ŧ)*/
	0x0167,	/*(ŧ)*/
	0x0168,	/*(Ũ)*/
	0x0169,	/*(ũ)*/
	0x016a,	/*(Ū)*/
	0x016b,	/*(ū)*/
	0x016c,	/*(Ŭ)*/
	0x016d,	/*(ŭ)*/
	0x016e,	/*(Ů)*/
	0x016f,	/*(ů)*/
	0x0170,	/*(Ű)*/
	0x0171,	/*(ű)*/
	0x0172,	/*(Ų)*/
	0x0173,	/*(ų)*/
	0x0174,	/*(Ŵ)*/
	0x0175,	/*(ŵ)*/
	0x0176,	/*(Ŷ)*/
	0x0177,	/*(ŷ)*/
	0x0178,	/*(Ÿ)*/
	0x0179,	/*(Ź)*/
	0x017a,	/*(ź)*/
	0x017b,	/*(Ż)*/
	0x017c,	/*(ż)*/
	0x017d,	/*(Ž)*/
	0x017e,	/*(ž)*/
	0x017f,	/*(ſ)*/
	0x0180,	/*(ƀ)*/
	0x0181,	/*(Ɓ)*/
	0x0182,	/*(Ƃ)*/
	0x0183,	/*(ƃ)*/
	0x0184,	/*(Ƅ)*/
	0x0185,	/*(ƅ)*/
	0x0186,	/*(Ɔ)*/
	0x0187,	/*(Ƈ)*/
	0x0188,	/*(ƈ)*/
	0x0189,	/*(Ɖ)*/
	0x018a,	/*(Ɗ)*/
	0x018b,	/*(Ƌ)*/
	0x018c,	/*(ƌ)*/
	0x018d,	/*(ƍ)*/
	0x018e,	/*(Ǝ)*/
	0x018f,	/*(Ə)*/
	0x0190,	/*(Ɛ)*/
	0x0191,	/*(Ƒ)*/
	0x0192,	/*(ƒ)*/
	0x0193,	/*(Ɠ)*/
	0x0194,	/*(Ɣ)*/
	0x0195,	/*(ƕ)*/
	0x0196,	/*(Ɩ)*/
	0x0197,	/*(Ɨ)*/
	0x0198,	/*(Ƙ)*/
	0x0199,	/*(ƙ)*/
	0x019a,	/*(ƚ)*/
	0x019b,	/*(ƛ)*/
	0x019c,	/*(Ɯ)*/
	0x019d,	/*(Ɲ)*/
	0x019e,	/*(ƞ)*/
	0x019f,	/*(Ɵ)*/
	0x01a0,	/*(Ơ)*/
	0x01a1,	/*(ơ)*/
	0x01a2,	/*(Ƣ)*/
	0x01a3,	/*(ƣ)*/
	0x01a4,	/*(Ƥ)*/
	0x01a5,	/*(ƥ)*/
	0x01a6,	/*(Ʀ)*/
	0x01a7,	/*(Ƨ)*/
	0x01a8,	/*(ƨ)*/
	0x01a9,	/*(Ʃ)*/
	0x01aa,	/*(ƪ)*/
	0x01ab,	/*(ƫ)*/
	0x01ac,	/*(Ƭ)*/
	0x01ad,	/*(ƭ)*/
	0x01ae,	/*(Ʈ)*/
	0x01af,	/*(Ư)*/
	0x01b0,	/*(ư)*/
	0x01b1,	/*(Ʊ)*/
	0x01b2,	/*(Ʋ)*/
	0x01b3,	/*(Ƴ)*/
	0x01b4,	/*(ƴ)*/
	0x01b5,	/*(Ƶ)*/
	0x01b6,	/*(ƶ)*/
	0x01b7,	/*(Ʒ)*/
	0x01b8,	/*(Ƹ)*/
	0x01b9,	/*(ƹ)*/
	0x01ba,	/*(ƺ)*/
	0x01bb,	/*(ƻ)*/
	0x01bc,	/*(Ƽ)*/
	0x01bd,	/*(ƽ)*/
	0x01be,	/*(ƾ)*/
	0x01bf,	/*(ƿ)*/
	0x01c0,	/*(ǀ)*/
	0x01c1,	/*(ǁ)*/
	0x01c2,	/*(ǂ)*/
	0x01c3,	/*(ǃ)*/
	0x01c4,	/*(Ǆ)*/
	0x01c5,	/*(ǅ)*/
	0x01c6,	/*(ǆ)*/
	0x01c7,	/*(Ǉ)*/
	0x01c8,	/*(ǈ)*/
	0x01c9,	/*(ǉ)*/
	0x01ca,	/*(Ǌ)*/
	0x01cb,	/*(ǋ)*/
	0x01cc,	/*(ǌ)*/
	0x01cd,	/*(Ǎ)*/
	0x01ce,	/*(ǎ)*/
	0x01cf,	/*(Ǐ)*/
	0x01d0,	/*(ǐ)*/
	0x01d1,	/*(Ǒ)*/
	0x01d2,	/*(ǒ)*/
	0x01d3,	/*(Ǔ)*/
	0x01d4,	/*(ǔ)*/
	0x01d5,	/*(Ǖ)*/
	0x01d6,	/*(ǖ)*/
	0x01d7,	/*(Ǘ)*/
	0x01d8,	/*(ǘ)*/
	0x01d9,	/*(Ǚ)*/
	0x01da,	/*(ǚ)*/
	0x01db,	/*(Ǜ)*/
	0x01dc,	/*(ǜ)*/
	0x01dd,	/*(ǝ)*/
	0x01de,	/*(Ǟ)*/
	0x01df,	/*(ǟ)*/
	0x01e0,	/*(Ǡ)*/
	0x01e1,	/*(ǡ)*/
	0x01e2,	/*(Ǣ)*/
	0x01e3,	/*(ǣ)*/
	0x01e4,	/*(Ǥ)*/
	0x01e5,	/*(ǥ)*/
	0x01e6,	/*(Ǧ)*/
	0x01e7,	/*(ǧ)*/
	0x01e8,	/*(Ǩ)*/
	0x01e9,	/*(ǩ)*/
	0x01ea,	/*(Ǫ)*/
	0x01eb,	/*(ǫ)*/
	0x01ec,	/*(Ǭ)*/
	0x01ed,	/*(ǭ)*/
	0x01ee,	/*(Ǯ)*/
	0x01ef,	/*(ǯ)*/
	0x01f0,	/*(ǰ)*/
	0x01f1,	/*(Ǳ)*/
	0x01f2,	/*(ǲ)*/
	0x01f3,	/*(ǳ)*/
	0x01f4,	/*(Ǵ)*/
	0x01f5,	/*(ǵ)*/
	0x01f6,	/*(Ƕ)*/
	0x01f7,	/*(Ƿ)*/
	0x01f8,	/*(Ǹ)*/
	0x01f9,	/*(ǹ)*/
	0x01fa,	/*(Ǻ)*/
	0x01fb,	/*(ǻ)*/
	0x01fc,	/*(Ǽ)*/
	0x01fd,	/*(ǽ)*/
	0x01fe,	/*(Ǿ)*/
	0x01ff,	/*(ǿ)*/
	0x0200,	/*(Ȁ)*/
	0x0201,	/*(ȁ)*/
	0x0202,	/*(Ȃ)*/
	0x0203,	/*(ȃ)*/
	0x0204,	/*(Ȅ)*/
	0x0205,	/*(ȅ)*/
	0x0206,	/*(Ȇ)*/
	0x0207,	/*(ȇ)*/
	0x0208,	/*(Ȉ)*/
	0x0209,	/*(ȉ)*/
	0x020a,	/*(Ȋ)*/
	0x020b,	/*(ȋ)*/
	0x020c,	/*(Ȍ)*/
	0x020d,	/*(ȍ)*/
	0x020e,	/*(Ȏ)*/
	0x020f,	/*(ȏ)*/
	0x0210,	/*(Ȑ)*/
	0x0211,	/*(ȑ)*/
	0x0212,	/*(Ȓ)*/
	0x0213,	/*(ȓ)*/
	0x0214,	/*(Ȕ)*/
	0x0215,	/*(ȕ)*/
	0x0216,	/*(Ȗ)*/
	0x0217,	/*(ȗ)*/
	0x0218,	/*(Ș)*/
	0x0219,	/*(ș)*/
	0x021a,	/*(Ț)*/
	0x021b,	/*(ț)*/
	0x021c,	/*(Ȝ)*/
	0x021d,	/*(ȝ)*/
	0x021e,	/*(Ȟ)*/
	0x021f,	/*(ȟ)*/
	0x0220,	/*(Ƞ)*/
	0x0221,	/*(ȡ)*/
	0x0222,	/*(Ȣ)*/
	0x0223,	/*(ȣ)*/
	0x0224,	/*(Ȥ)*/
	0x0225,	/*(ȥ)*/
	0x0226,	/*(Ȧ)*/
	0x0227,	/*(ȧ)*/
	0x0228,	/*(Ȩ)*/
	0x0229,	/*(ȩ)*/
	0x022a,	/*(Ȫ)*/
	0x022b,	/*(ȫ)*/
	0x022c,	/*(Ȭ)*/
	0x022d,	/*(ȭ)*/
	0x022e,	/*(Ȯ)*/
	0x022f,	/*(ȯ)*/
	0x0230,	/*(Ȱ)*/
	0x0231,	/*(ȱ)*/
	0x0232,	/*(Ȳ)*/
	0x0233,	/*(ȳ)*/
	0x0234,	/*(ȴ)*/
	0x0235,	/*(ȵ)*/
	0x0236,	/*(ȶ)*/
	0x0237,	/*(ȷ)*/
	0x0238,	/*(ȸ)*/
	0x0239,	/*(ȹ)*/
	0x023a,	/*(Ⱥ)*/
	0x023b,	/*(Ȼ)*/
	0x023c,	/*(ȼ)*/
	0x023d,	/*(Ƚ)*/
	0x023e,	/*(Ⱦ)*/
	0x023f,	/*(ȿ)*/
	0x0240,	/*(ɀ)*/
	0x0241,	/*(Ɂ)*/
	0x0242,	/*(ɂ)*/
	0x0243,	/*(Ƀ)*/
	0x0244,	/*(Ʉ)*/
	0x0245,	/*(Ʌ)*/
	0x0246,	/*(Ɇ)*/
	0x0247,	/*(ɇ)*/
	0x0248,	/*(Ɉ)*/
	0x0249,	/*(ɉ)*/
	0x024a,	/*(Ɋ)*/
	0x024b,	/*(ɋ)*/
	0x024c,	/*(Ɍ)*/
	0x024d,	/*(ɍ)*/
	0x024e,	/*(Ɏ)*/
	0x024f,	/*(ɏ)*/
	0x0370,	/*(Ͱ)*/
	0x0371,	/*(ͱ)*/
	0x0372,	/*(Ͳ)*/
	0x0373,	/*(ͳ)*/
	0x0374,	/*(ʹ)*/
	0x0375,	/*(͵)*/
	0x0376,	/*(Ͷ)*/
	0x0377,	/*(ͷ)*/
	0x037a,	/*(ͺ)*/
	0x037b,	/*(ͻ)*/
	0x037c,	/*(ͼ)*/
	0x037d,	/*(ͽ)*/
	0x037e,	/*(;)*/
	0x037f,	/*(Ϳ)*/
	0x0384,	/*(΄)*/
	0x0385,	/*(΅)*/
	0x0386,	/*(Ά)*/
	0x0387,	/*(·)*/
	0x0388,	/*(Έ)*/
	0x0389,	/*(Ή)*/
	0x038a,	/*(Ί)*/
	0x038c,	/*(Ό)*/
	0x038e,	/*(Ύ)*/
	0x038f,	/*(Ώ)*/
	0x0390,	/*(ΐ)*/
	0x0391,	/*(Α)*/
	0x0392,	/*(Β)*/
	0x0393,	/*(Γ)*/
	0x0394,	/*(Δ)*/
	0x0395,	/*(Ε)*/
	0x0396,	/*(Ζ)*/
	0x0397,	/*(Η)*/
	0x0398,	/*(Θ)*/
	0x0399,	/*(Ι)*/
	0x039a,	/*(Κ)*/
	0x039b,	/*(Λ)*/
	0x039c,	/*(Μ)*/
	0x039d,	/*(Ν)*/
	0x039e,	/*(Ξ)*/
	0x039f,	/*(Ο)*/
	0x03a0,	/*(Π)*/
	0x03a1,	/*(Ρ)*/
	0x03a3,	/*(Σ)*/
	0x03a4,	/*(Τ)*/
	0x03a5,	/*(Υ)*/
	0x03a6,	/*(Φ)*/
	0x03a7,	/*(Χ)*/
	0x03a8,	/*(Ψ)*/
	0x03a9,	/*(Ω)*/
	0x03aa,	/*(Ϊ)*/
	0x03ab,	/*(Ϋ)*/
	0x03ac,	/*(ά)*/
	0x03ad,	/*(έ)*/
	0x03ae,	/*(ή)*/
	0x03af,	/*(ί)*/
	0x03b0,	/*(ΰ)*/
	0x03b1,	/*(α)*/
	0x03b2,	/*(β)*/
	0x03b3,	/*(γ)*/
	0x03b4,	/*(δ)*/
	0x03b5,	/*(ε)*/
	0x03b6,	/*(ζ)*/
	0x03b7,	/*(η)*/
	0x03b8,	/*(θ)*/
	0x03b9,	/*(ι)*/
	0x03ba,	/*(κ)*/
	0x03bb,	/*(λ)*/
	0x03bc,	/*(μ)*/
	0x03bd,	/*(ν)*/
	0x03be,	/*(ξ)*/
	0x03bf,	/*(ο)*/
	0x03c0,	/*(π)*/
	0x03c1,	/*(ρ)*/
	0x03c2,	/*(ς)*/
	0x03c3,	/*(σ)*/
	0x03c4,	/*(τ)*/
	0x03c5,	/*(υ)*/
	0x03c6,	/*(φ)*/
	0x03c7,	/*(χ)*/
	0x03c8,	/*(ψ)*/
	0x03c9,	/*(ω)*/
	0x03ca,	/*(ϊ)*/
	0x03cb,	/*(ϋ)*/
	0x03cc,	/*(ό)*/
	0x03cd,	/*(ύ)*/
	0x03ce,	/*(ώ)*/
	0x03cf,	/*(Ϗ)*/
	0x03d0,	/*(ϐ)*/
	0x03d1,	/*(ϑ)*/
	0x03d2,	/*(ϒ)*/
	0x03d3,	/*(ϓ)*/
	0x03d4,	/*(ϔ)*/
	0x03d5,	/*(ϕ)*/
	0x03d6,	/*(ϖ)*/
	0x03d7,	/*(ϗ)*/
	0x03d8,	/*(Ϙ)*/
	0x03d9,	/*(ϙ)*/
	0x03da,	/*(Ϛ)*/
	0x03db,	/*(ϛ)*/
	0x03dc,	/*(Ϝ)*/
	0x03dd,	/*(ϝ)*/
	0x03de,	/*(Ϟ)*/
	0x03df,	/*(ϟ)*/
	0x03e0,	/*(Ϡ)*/
	0x03e1,	/*(ϡ)*/
	0x03e2,	/*(Ϣ)*/
	0x03e3,	/*(ϣ)*/
	0x03e4,	/*(Ϥ)*/
	0x03e5,	/*(ϥ)*/
	0x03e6,	/*(Ϧ)*/
	0x03e7,	/*(ϧ)*/
	0x03e8,	/*(Ϩ)*/
	0x03e9,	/*(ϩ)*/
	0x03ea,	/*(Ϫ)*/
	0x03eb,	/*(ϫ)*/
	0x03ec,	/*(Ϭ)*/
	0x03ed,	/*(ϭ)*/
	0x03ee,	/*(Ϯ)*/
	0x03ef,	/*(ϯ)*/
	0x03f0,	/*(ϰ)*/
	0x03f1,	/*(ϱ)*/
	0x03f2,	/*(ϲ)*/
	0x03f3,	/*(ϳ)*/
	0x03f4,	/*(ϴ)*/
	0x03f5,	/*(ϵ)*/
	0x03f6,	/*(϶)*/
	0x03f7,	/*(Ϸ)*/
	0x03f8,	/*(ϸ)*/
	0x03f9,	/*(Ϲ)*/
	0x03fa,	/*(Ϻ)*/
	0x03fb,	/*(ϻ)*/
	0x03fc,	/*(ϼ)*/
	0x03fd,	/*(Ͻ)*/
	0x03fe,	/*(Ͼ)*/
	0x03ff,	/*(Ͽ)*/
	0x0400,	/*(Ѐ)*/
	0x0401,	/*(Ё)*/
	0x0402,	/*(Ђ)*/
	0x0403,	/*(Ѓ)*/
	0x0404,	/*(Є)*/
	0x0405,	/*(Ѕ)*/
	0x0406,	/*(І)*/
	0x0407,	/*(Ї)*/
	0x0408,	/*(Ј)*/
	0x0409,	/*(Љ)*/
	0x040a,	/*(Њ)*/
	0x040b,	/*(Ћ)*/
	0x040c,	/*(Ќ)*/
	0x040d,	/*(Ѝ)*/
	0x040e,	/*(Ў)*/
	0x040f,	/*(Џ)*/
	0x0410,	/*(А)*/
	0x0411,	/*(Б)*/
	0x0412,	/*(В)*/
	0x0413,	/*(Г)*/
	0x0414,	/*(Д)*/
	0x0415,	/*(Е)*/
	0x0416,	/*(Ж)*/
	0x0417,	/*(З)*/
	0x0418,	/*(И)*/
	0x0419,	/*(Й)*/
	0x041a,	/*(К)*/
	0x041b,	/*(Л)*/
	0x041c,	/*(М)*/
	0x041d,	/*(Н)*/
	0x041e,	/*(О)*/
	0x041f,	/*(П)*/
	0x0420,	/*(Р)*/
	0x0421,	/*(С)*/
	0x0422,	/*(Т)*/
	0x0423,	/*(У)*/
	0x0424,	/*(Ф)*/
	0x0425,	/*(Х)*/
	0x0426,	/*(Ц)*/
	0x0427,	/*(Ч)*/
	0x0428,	/*(Ш)*/
	0x0429,	/*(Щ)*/
	0x042a,	/*(Ъ)*/
	0x042b,	/*(Ы)*/
	0x042c,	/*(Ь)*/
	0x042d,	/*(Э)*/
	0x042e,	/*(Ю)*/
	0x042f,	/*(Я)*/
	0x0430,	/*(а)*/
	0x0431,	/*(б)*/
	0x0432,	/*(в)*/
	0x0433,	/*(г)*/
	0x0434,	/*(д)*/
	0x0435,	/*(е)*/
	0x0436,	/*(ж)*/
	0x0437,	/*(з)*/
	0x0438,	/*(и)*/
	0x0439,	/*(й)*/
	0x043a,	/*(к)*/
	0x043b,	/*(л)*/
	0x043c,	/*(м)*/
	0x043d,	/*(н)*/
	0x043e,	/*(о)*/
	0x043f,	/*(п)*/
	0x0440,	/*(р)*/
	0x0441,	/*(с)*/
	0x0442,	/*(т)*/
	0x0443,	/*(у)*/
	0x0444,	/*(ф)*/
	0x0445,	/*(х)*/
	0x0446,	/*(ц)*/
	0x0447,	/*(ч)*/
	0x0448,	/*(ш)*/
	0x0449,	/*(щ)*/
	0x044a,	/*(ъ)*/
	0x044b,	/*(ы)*/
	0x044c,	/*(ь)*/
	0x044d,	/*(э)*/
	0x044e,	/*(ю)*/
	0x044f,	/*(я)*/
	0x0450,	/*(ѐ)*/
	0x0451,	/*(ё)*/
	0x0452,	/*(ђ)*/
	0x0453,	/*(ѓ)*/
	0x0454,	/*(є)*/
	0x0455,	/*(ѕ)*/
	0x0456,	/*(і)*/
	0x0457,	/*(ї)*/
	0x0458,	/*(ј)*/
	0x0459,	/*(љ)*/
	0x045a,	/*(њ)*/
	0x045b,	/*(ћ)*/
	0x045c,	/*(ќ)*/
	0x045d,	/*(ѝ)*/
	0x045e,	/*(ў)*/
	0x045f,	/*(џ)*/
	0x0460,	/*(Ѡ)*/
	0x0461,	/*(ѡ)*/
	0x0462,	/*(Ѣ)*/
	0x0463,	/*(ѣ)*/
	0x0464,	/*(Ѥ)*/
	0x0465,	/*(ѥ)*/
	0x0466,	/*(Ѧ)*/
	0x0467,	/*(ѧ)*/
	0x0468,	/*(Ѩ)*/
	0x0469,	/*(ѩ)*/
	0x046a,	/*(Ѫ)*/
	0x046b,	/*(ѫ)*/
	0x046c,	/*(Ѭ)*/
	0x046d,	/*(ѭ)*/
	0x046e,	/*(Ѯ)*/
	0x046f,	/*(ѯ)*/
	0x0470,	/*(Ѱ)*/
	0x0471,	/*(ѱ)*/
	0x0472,	/*(Ѳ)*/
	0x0473,	/*(ѳ)*/
	0x0474,	/*(Ѵ)*/
	0x0475,	/*(ѵ)*/
	0x0476,	/*(Ѷ)*/
	0x0477,	/*(ѷ)*/
	0x0478,	/*(Ѹ)*/
	0x0479,	/*(ѹ)*/
	0x047a,	/*(Ѻ)*/
	0x047b,	/*(ѻ)*/
	0x047c,	/*(Ѽ)*/
	0x047d,	/*(ѽ)*/
	0x047e,	/*(Ѿ)*/
	0x047f,	/*(ѿ)*/
	0x0480,	/*(Ҁ)*/
	0x0481,	/*(ҁ)*/
	0x0482,	/*(҂)*/
	0x0483,	/*(҃)*/
	0x0484,	/*(҄)*/
	0x0485,	/*(҅)*/
	0x0486,	/*(҆)*/
	0x0487,	/*(҇)*/
	0x0488,	/*(҈)*/
	0x0489,	/*(҉)*/
	0x048a,	/*(Ҋ)*/
	0x048b,	/*(ҋ)*/
	0x048c,	/*(Ҍ)*/
	0x048d,	/*(ҍ)*/
	0x048e,	/*(Ҏ)*/
	0x048f,	/*(ҏ)*/
	0x0490,	/*(Ґ)*/
	0x0491,	/*(ґ)*/
	0x0492,	/*(Ғ)*/
	0x0493,	/*(ғ)*/
	0x0494,	/*(Ҕ)*/
	0x0495,	/*(ҕ)*/
	0x0496,	/*(Җ)*/
	0x0497,	/*(җ)*/
	0x0498,	/*(Ҙ)*/
	0x0499,	/*(ҙ)*/
	0x049a,	/*(Қ)*/
	0x049b,	/*(қ)*/
	0x049c,	/*(Ҝ)*/
	0x049d,	/*(ҝ)*/
	0x049e,	/*(Ҟ)*/
	0x049f,	/*(ҟ)*/
	0x04a0,	/*(Ҡ)*/
	0x04a1,	/*(ҡ)*/
	0x04a2,	/*(Ң)*/
	0x04a3,	/*(ң)*/
	0x04a4,	/*(Ҥ)*/
	0x04a5,	/*(ҥ)*/
	0x04a6,	/*(Ҧ)*/
	0x04a7,	/*(ҧ)*/
	0x04a8,	/*(Ҩ)*/
	0x04a9,	/*(ҩ)*/
	0x04aa,	/*(Ҫ)*/
	0x04ab,	/*(ҫ)*/
	0x04ac,	/*(Ҭ)*/
	0x04ad,	/*(ҭ)*/
	0x04ae,	/*(Ү)*/
	0x04af,	/*(ү)*/
	0x04b0,	/*(Ұ)*/
	0x04b1,	/*(ұ)*/
	0x04b2,	/*(Ҳ)*/
	0x04b3,	/*(ҳ)*/
	0x04b4,	/*(Ҵ)*/
	0x04b5,	/*(ҵ)*/
	0x04b6,	/*(Ҷ)*/
	0x04b7,	/*(ҷ)*/
	0x04b8,	/*(Ҹ)*/
	0x04b9,	/*(ҹ)*/
	0x04ba,	/*(Һ)*/
	0x04bb,	/*(һ)*/
	0x04bc,	/*(Ҽ)*/
	0x04bd,	/*(ҽ)*/
	0x04be,	/*(Ҿ)*/
	0x04bf,	/*(ҿ)*/
	0x04c0,	/*(Ӏ)*/
	0x04c1,	/*(Ӂ)*/
	0x04c2,	/*(ӂ)*/
	0x04c3,	/*(Ӄ)*/
	0x04c4,	/*(ӄ)*/
	0x04c5,	/*(Ӆ)*/
	0x04c6,	/*(ӆ)*/
	0x04c7,	/*(Ӈ)*/
	0x04c8,	/*(ӈ)*/
	0x04c9,	/*(Ӊ)*/
	0x04ca,	/*(ӊ)*/
	0x04cb,	/*(Ӌ)*/
	0x04cc,	/*(ӌ)*/
	0x04cd,	/*(Ӎ)*/
	0x04ce,	/*(ӎ)*/
	0x04cf,	/*(ӏ)*/
	0x04d0,	/*(Ӑ)*/
	0x04d1,	/*(ӑ)*/
	0x04d2,	/*(Ӓ)*/
	0x04d3,	/*(ӓ)*/
	0x04d4,	/*(Ӕ)*/
	0x04d5,	/*(ӕ)*/
	0x04d6,	/*(Ӗ)*/
	0x04d7,	/*(ӗ)*/
	0x04d8,	/*(Ә)*/
	0x04d9,	/*(ә)*/
	0x04da,	/*(Ӛ)*/
	0x04db,	/*(ӛ)*/
	0x04dc,	/*(Ӝ)*/
	0x04dd,	/*(ӝ)*/
	0x04de,	/*(Ӟ)*/
	0x04df,	/*(ӟ)*/
	0x04e0,	/*(Ӡ)*/
	0x04e1,	/*(ӡ)*/
	0x04e2,	/*(Ӣ)*/
	0x04e3,	/*(ӣ)*/
	0x04e4,	/*(Ӥ)*/
	0x04e5,	/*(ӥ)*/
	0x04e6,	/*(Ӧ)*/
	0x04e7,	/*(ӧ)*/
	0x04e8,	/*(Ө)*/
	0x04e9,	/*(ө)*/
	0x04ea,	/*(Ӫ)*/
	0x04eb,	/*(ӫ)*/
	0x04ec,	/*(Ӭ)*/
	0x04ed,	/*(ӭ)*/
	0x04ee,	/*(Ӯ)*/
	0x04ef,	/*(ӯ)*/
	0x04f0,	/*(Ӱ)*/
	0x04f1,	/*(ӱ)*/
	0x04f2,	/*(Ӳ)*/
	0x04f3,	/*(ӳ)*/
	0x04f4,	/*(Ӵ)*/
	0x04f5,	/*(ӵ)*/
	0x04f6,	/*(Ӷ)*/
	0x04f7,	/*(ӷ)*/
	0x04f8,	/*(Ӹ)*/
	0x04f9,	/*(ӹ)*/
	0x04fa,	/*(Ӻ)*/
	0x04fb,	/*(ӻ)*/
	0x04fc,	/*(Ӽ)*/
	0x04fd,	/*(ӽ)*/
	0x04fe,	/*(Ӿ)*/
	0x04ff,	/*(ӿ)*/
	0x0531,	/*(Ա)*/
	0x0532,	/*(Բ)*/
	0x0533,	/*(Գ)*/
	0x0534,	/*(Դ)*/
	0x0535,	/*(Ե)*/
	0x0536,	/*(Զ)*/
	0x0537,	/*(Է)*/
	0x0538,	/*(Ը)*/
	0x0539,	/*(Թ)*/
	0x053a,	/*(Ժ)*/
	0x053b,	/*(Ի)*/
	0x053c,	/*(Լ)*/
	0x053d,	/*(Խ)*/
	0x053e,	/*(Ծ)*/
	0x053f,	/*(Կ)*/
	0x0540,	/*(Հ)*/
	0x0541,	/*(Ձ)*/
	0x0542,	/*(Ղ)*/
	0x0543,	/*(Ճ)*/
	0x0544,	/*(Մ)*/
	0x0545,	/*(Յ)*/
	0x0546,	/*(Ն)*/
	0x0547,	/*(Շ)*/
	0x0548,	/*(Ո)*/
	0x0549,	/*(Չ)*/
	0x054a,	/*(Պ)*/
	0x054b,	/*(Ջ)*/
	0x054c,	/*(Ռ)*/
	0x054d,	/*(Ս)*/
	0x054e,	/*(Վ)*/
	0x054f,	/*(Տ)*/
	0x0550,	/*(Ր)*/
	0x0551,	/*(Ց)*/
	0x0552,	/*(Ւ)*/
	0x0553,	/*(Փ)*/
	0x0554,	/*(Ք)*/
	0x0555,	/*(Օ)*/
	0x0556,	/*(Ֆ)*/
	0x0559,	/*(ՙ)*/
	0x055a,	/*(՚)*/
	0x055b,	/*(՛)*/
	0x055c,	/*(՜)*/
	0x055d,	/*(՝)*/
	0x055e,	/*(՞)*/
	0x055f,	/*(՟)*/
	0x0560,	/*(ՠ)*/
	0x0561,	/*(ա)*/
	0x0562,	/*(բ)*/
	0x0563,	/*(գ)*/
	0x0564,	/*(դ)*/
	0x0565,	/*(ե)*/
	0x0566,	/*(զ)*/
	0x0567,	/*(է)*/
	0x0568,	/*(ը)*/
	0x0569,	/*(թ)*/
	0x056a,	/*(ժ)*/
	0x056b,	/*(ի)*/
	0x056c,	/*(լ)*/
	0x056d,	/*(խ)*/
	0x056e,	/*(ծ)*/
	0x056f,	/*(կ)*/
	0x0570,	/*(հ)*/
	0x0571,	/*(ձ)*/
	0x0572,	/*(ղ)*/
	0x0573,	/*(ճ)*/
	0x0574,	/*(մ)*/
	0x0575,	/*(յ)*/
	0x0576,	/*(ն)*/
	0x0577,	/*(շ)*/
	0x0578,	/*(ո)*/
	0x0579,	/*(չ)*/
	0x057a,	/*(պ)*/
	0x057b,	/*(ջ)*/
	0x057c,	/*(ռ)*/
	0x057d,	/*(ս)*/
	0x057e,	/*(վ)*/
	0x057f,	/*(տ)*/
	0x0580,	/*(ր)*/
	0x0581,	/*(ց)*/
	0x0582,	/*(ւ)*/
	0x0583,	/*(փ)*/
	0x0584,	/*(ք)*/
	0x0585,	/*(օ)*/
	0x0586,	/*(ֆ)*/
	0x0587,	/*(և)*/
	0x0588,	/*(ֈ)*/
	0x0589,	/*(։)*/
	0x058a,	/*(֊)*/
	0x058d,	/*(֍)*/
	0x058e,	/*(֎)*/
	0x058f,	/*(֏)*/
	0x2018,	/*(‘)*/
	0x2019,	/*(’)*/
	0x201c,	/*(“)*/
	0x201d,	/*(”)*/
	0x2103,	/*(℃)*/
	0x3001,	/*(、)*/
	0x3002,	/*(。)*/
	0x300a,	/*(《)*/
	0x300b,	/*(》)*/
	0x3010,	/*(【)*/
	0x3011,	/*(】)*/
	0x3041,	/*(ぁ)*/
	0x3042,	/*(あ)*/
	0x3043,	/*(ぃ)*/
	0x3044,	/*(い)*/
	0x3045,	/*(ぅ)*/
	0x3046,	/*(う)*/
	0x3047,	/*(ぇ)*/
	0x3048,	/*(え)*/
	0x3049,	/*(ぉ)*/
	0x304a,	/*(お)*/
	0x304b,	/*(か)*/
	0x304c,	/*(が)*/
	0x304d,	/*(き)*/
	0x304e,	/*(ぎ)*/
	0x304f,	/*(く)*/
	0x3050,	/*(ぐ)*/
	0x3051,	/*(け)*/
	0x3052,	/*(げ)*/
	0x3053,	/*(こ)*/
	0x3054,	/*(ご)*/
	0x3055,	/*(さ)*/
	0x3056,	/*(ざ)*/
	0x3057,	/*(し)*/
	0x3058,	/*(じ)*/
	0x3059,	/*(す)*/
	0x305a,	/*(ず)*/
	0x305b,	/*(せ)*/
	0x305c,	/*(ぜ)*/
	0x305d,	/*(そ)*/
	0x305e,	/*(ぞ)*/
	0x305f,	/*(た)*/
	0x3060,	/*(だ)*/
	0x3061,	/*(ち)*/
	0x3062,	/*(ぢ)*/
	0x3063,	/*(っ)*/
	0x3064,	/*(つ)*/
	0x3065,	/*(づ)*/
	0x3066,	/*(て)*/
	0x3067,	/*(で)*/
	0x3068,	/*(と)*/
	0x3069,	/*(ど)*/
	0x306a,	/*(な)*/
	0x306b,	/*(に)*/
	0x306c,	/*(ぬ)*/
	0x306d,	/*(ね)*/
	0x306e,	/*(の)*/
	0x306f,	/*(は)*/
	0x3070,	/*(ば)*/
	0x3071,	/*(ぱ)*/
	0x3072,	/*(ひ)*/
	0x3073,	/*(び)*/
	0x3074,	/*(ぴ)*/
	0x3075,	/*(ふ)*/
	0x3076,	/*(ぶ)*/
	0x3077,	/*(ぷ)*/
	0x3078,	/*(へ)*/
	0x3079,	/*(べ)*/
	0x307a,	/*(ぺ)*/
	0x307b,	/*(ほ)*/
	0x307c,	/*(ぼ)*/
	0x307d,	/*(ぽ)*/
	0x307e,	/*(ま)*/
	0x307f,	/*(み)*/
	0x3080,	/*(む)*/
	0x3081,	/*(め)*/
	0x3082,	/*(も)*/
	0x3083,	/*(ゃ)*/
	0x3084,	/*(や)*/
	0x3085,	/*(ゅ)*/
	0x3086,	/*(ゆ)*/
	0x3087,	/*(ょ)*/
	0x3088,	/*(よ)*/
	0x3089,	/*(ら)*/
	0x308a,	/*(り)*/
	0x308b,	/*(る)*/
	0x308c,	/*(れ)*/
	0x308d,	/*(ろ)*/
	0x308e,	/*(ゎ)*/
	0x308f,	/*(わ)*/
	0x3090,	/*(ゐ)*/
	0x3091,	/*(ゑ)*/
	0x3092,	/*(を)*/
	0x3093,	/*(ん)*/
	0x3094,	/*(ゔ)*/
	0x3095,	/*(ゕ)*/
	0x3096,	/*(ゖ)*/
	0x3099,	/*(゙)*/
	0x309a,	/*(゚)*/
	0x309b,	/*(゛)*/
	0x309c,	/*(゜)*/
	0x309d,	/*(ゝ)*/
	0x309e,	/*(ゞ)*/
	0x309f,	/*(ゟ)*/
	0x30a0,	/*(゠)*/
	0x30a1,	/*(ァ)*/
	0x30a2,	/*(ア)*/
	0x30a3,	/*(ィ)*/
	0x30a4,	/*(イ)*/
	0x30a5,	/*(ゥ)*/
	0x30a6,	/*(ウ)*/
	0x30a7,	/*(ェ)*/
	0x30a8,	/*(エ)*/
	0x30a9,	/*(ォ)*/
	0x30aa,	/*(オ)*/
	0x30ab,	/*(カ)*/
	0x30ac,	/*(ガ)*/
	0x30ad,	/*(キ)*/
	0x30ae,	/*(ギ)*/
	0x30af,	/*(ク)*/
	0x30b0,	/*(グ)*/
	0x30b1,	/*(ケ)*/
	0x30b2,	/*(ゲ)*/
	0x30b3,	/*(コ)*/
	0x30b4,	/*(ゴ)*/
	0x30b5,	/*(サ)*/
	0x30b6,	/*(ザ)*/
	0x30b7,	/*(シ)*/
	0x30b8,	/*(ジ)*/
	0x30b9,	/*(ス)*/
	0x30ba,	/*(ズ)*/
	0x30bb,	/*(セ)*/
	0x30bc,	/*(ゼ)*/
	0x30bd,	/*(ソ)*/
	0x30be,	/*(ゾ)*/
	0x30bf,	/*(タ)*/
	0x30c0,	/*(ダ)*/
	0x30c1,	/*(チ)*/
	0x30c2,	/*(ヂ)*/
	0x30c3,	/*(ッ)*/
	0x30c4,	/*(ツ)*/
	0x30c5,	/*(ヅ)*/
	0x30c6,	/*(テ)*/
	0x30c7,	/*(デ)*/
	0x30c8,	/*(ト)*/
	0x30c9,	/*(ド)*/
	0x30ca,	/*(ナ)*/
	0x30cb,	/*(ニ)*/
	0x30cc,	/*(ヌ)*/
	0x30cd,	/*(ネ)*/
	0x30ce,	/*(ノ)*/
	0x30cf,	/*(ハ)*/
	0x30d0,	/*(バ)*/
	0x30d1,	/*(パ)*/
	0x30d2,	/*(ヒ)*/
	0x30d3,	/*(ビ)*/
	0x30d4,	/*(ピ)*/
	0x30d5,	/*(フ)*/
	0x30d6,	/*(ブ)*/
	0x30d7,	/*(プ)*/
	0x30d8,	/*(ヘ)*/
	0x30d9,	/*(ベ)*/
	0x30da,	/*(ペ)*/
	0x30db,	/*(ホ)*/
	0x30dc,	/*(ボ)*/
	0x30dd,	/*(ポ)*/
	0x30de,	/*(マ)*/
	0x30df,	/*(ミ)*/
	0x30e0,	/*(ム)*/
	0x30e1,	/*(メ)*/
	0x30e2,	/*(モ)*/
	0x30e3,	/*(ャ)*/
	0x30e4,	/*(ヤ)*/
	0x30e5,	/*(ュ)*/
	0x30e6,	/*(ユ)*/
	0x30e7,	/*(ョ)*/
	0x30e8,	/*(ヨ)*/
	0x30e9,	/*(ラ)*/
	0x30ea,	/*(リ)*/
	0x30eb,	/*(ル)*/
	0x30ec,	/*(レ)*/
	0x30ed,	/*(ロ)*/
	0x30ee,	/*(ヮ)*/
	0x30ef,	/*(ワ)*/
	0x30f0,	/*(ヰ)*/
	0x30f1,	/*(ヱ)*/
	0x30f2,	/*(ヲ)*/
	0x30f3,	/*(ン)*/
	0x30f4,	/*(ヴ)*/
	0x30f5,	/*(ヵ)*/
	0x30f6,	/*(ヶ)*/
	0x30f7,	/*(ヷ)*/
	0x30f8,	/*(ヸ)*/
	0x30f9,	/*(ヹ)*/
	0x30fa,	/*(ヺ)*/
	0x30fb,	/*(・)*/
	0x30fc,	/*(ー)*/
	0x30fd,	/*(ヽ)*/
	0x30fe,	/*(ヾ)*/
	0x30ff,	/*(ヿ)*/
	0x4e00,	/*(一)*/
	0x4e01,	/*(丁)*/
	0x4e03,	/*(七)*/
	0x4e07,	/*(万)*/
	0x4e08,	/*(丈)*/
	0x4e09,	/*(三)*/
	0x4e0a,	/*(上)*/
	0x4e0b,	/*(下)*/
	0x4e0c,	/*(丌)*/
	0x4e0d,	/*(不)*/
	0x4e0e,	/*(与)*/
	0x4e10,	/*(丐)*/
	0x4e11,	/*(丑)*/
	0x4e13,	/*(专)*/
	0x4e14,	/*(且)*/
	0x4e15,	/*(丕)*/
	0x4e16,	/*(世)*/
	0x4e18,	/*(丘)*/
	0x4e19,	/*(丙)*/
	0x4e1a,	/*(业)*/
	0x4e1b,	/*(丛)*/
	0x4e1c,	/*(东)*/
	0x4e1d,	/*(丝)*/
	0x4e1e,	/*(丞)*/
	0x4e22,	/*(丢)*/
	0x4e24,	/*(两)*/
	0x4e25,	/*(严)*/
	0x4e27,	/*(丧)*/
	0x4e28,	/*(丨)*/
	0x4e2a,	/*(个)*/
	0x4e2b,	/*(丫)*/
	0x4e2c,	/*(丬)*/
	0x4e2d,	/*(中)*/
	0x4e30,	/*(丰)*/
	0x4e32,	/*(串)*/
	0x4e34,	/*(临)*/
	0x4e36,	/*(丶)*/
	0x4e38,	/*(丸)*/
	0x4e39,	/*(丹)*/
	0x4e3a,	/*(为)*/
	0x4e3b,	/*(主)*/
	0x4e3d,	/*(丽)*/
	0x4e3e,	/*(举)*/
	0x4e3f,	/*(丿)*/
	0x4e43,	/*(乃)*/
	0x4e45,	/*(久)*/
	0x4e47,	/*(乇)*/
	0x4e48,	/*(么)*/
	0x4e49,	/*(义)*/
	0x4e4b,	/*(之)*/
	0x4e4c,	/*(乌)*/
	0x4e4d,	/*(乍)*/
	0x4e4e,	/*(乎)*/
	0x4e4f,	/*(乏)*/
	0x4e50,	/*(乐)*/
	0x4e52,	/*(乒)*/
	0x4e53,	/*(乓)*/
	0x4e54,	/*(乔)*/
	0x4e56,	/*(乖)*/
	0x4e58,	/*(乘)*/
	0x4e59,	/*(乙)*/
	0x4e5c,	/*(乜)*/
	0x4e5d,	/*(九)*/
	0x4e5e,	/*(乞)*/
	0x4e5f,	/*(也)*/
	0x4e60,	/*(习)*/
	0x4e61,	/*(乡)*/
	0x4e66,	/*(书)*/
	0x4e69,	/*(乩)*/
	0x4e70,	/*(买)*/
	0x4e71,	/*(乱)*/
	0x4e73,	/*(乳)*/
	0x4e7e,	/*(乾)*/
	0x4e86,	/*(了)*/
	0x4e88,	/*(予)*/
	0x4e89,	/*(争)*/
	0x4e8b,	/*(事)*/
	0x4e8c,	/*(二)*/
	0x4e8d,	/*(亍)*/
	0x4e8e,	/*(于)*/
	0x4e8f,	/*(亏)*/
	0x4e91,	/*(云)*/
	0x4e92,	/*(互)*/
	0x4e93,	/*(亓)*/
	0x4e94,	/*(五)*/
	0x4e95,	/*(井)*/
	0x4e98,	/*(亘)*/
	0x4e9a,	/*(亚)*/
	0x4e9b,	/*(些)*/
	0x4e9f,	/*(亟)*/
	0x4ea0,	/*(亠)*/
	0x4ea1,	/*(亡)*/
	0x4ea2,	/*(亢)*/
	0x4ea4,	/*(交)*/
	0x4ea5,	/*(亥)*/
	0x4ea6,	/*(亦)*/
	0x4ea7,	/*(产)*/
	0x4ea8,	/*(亨)*/
	0x4ea9,	/*(亩)*/
	0x4eab,	/*(享)*/
	0x4eac,	/*(京)*/
	0x4ead,	/*(亭)*/
	0x4eae,	/*(亮)*/
	0x4eb2,	/*(亲)*/
	0x4eb3,	/*(亳)*/
	0x4eb5,	/*(亵)*/
	0x4eba,	/*(人)*/
	0x4ebb,	/*(亻)*/
	0x4ebf,	/*(亿)*/
	0x4ec0,	/*(什)*/
	0x4ec1,	/*(仁)*/
	0x4ec2,	/*(仂)*/
	0x4ec3,	/*(仃)*/
	0x4ec4,	/*(仄)*/
	0x4ec5,	/*(仅)*/
	0x4ec6,	/*(仆)*/
	0x4ec7,	/*(仇)*/
	0x4ec9,	/*(仉)*/
	0x4eca,	/*(今)*/
	0x4ecb,	/*(介)*/
	0x4ecd,	/*(仍)*/
	0x4ece,	/*(从)*/
	0x4ed1,	/*(仑)*/
	0x4ed3,	/*(仓)*/
	0x4ed4,	/*(仔)*/
	0x4ed5,	/*(仕)*/
	0x4ed6,	/*(他)*/
	0x4ed7,	/*(仗)*/
	0x4ed8,	/*(付)*/
	0x4ed9,	/*(仙)*/
	0x4edd,	/*(仝)*/
	0x4ede,	/*(仞)*/
	0x4edf,	/*(仟)*/
	0x4ee1,	/*(仡)*/
	0x4ee3,	/*(代)*/
	0x4ee4,	/*(令)*/
	0x4ee5,	/*(以)*/
	0x4ee8,	/*(仨)*/
	0x4eea,	/*(仪)*/
	0x4eeb,	/*(仫)*/
	0x4eec,	/*(们)*/
	0x4ef0,	/*(仰)*/
	0x4ef2,	/*(仲)*/
	0x4ef3,	/*(仳)*/
	0x4ef5,	/*(仵)*/
	0x4ef6,	/*(件)*/
	0x4ef7,	/*(价)*/
	0x4efb,	/*(任)*/
	0x4efd,	/*(份)*/
	0x4eff,	/*(仿)*/
	0x4f01,	/*(企)*/
	0x4f09,	/*(伉)*/
	0x4f0a,	/*(伊)*/
	0x4f0d,	/*(伍)*/
	0x4f0e,	/*(伎)*/
	0x4f0f,	/*(伏)*/
	0x4f10,	/*(伐)*/
	0x4f11,	/*(休)*/
	0x4f17,	/*(众)*/
	0x4f18,	/*(优)*/
	0x4f19,	/*(伙)*/
	0x4f1a,	/*(会)*/
	0x4f1b,	/*(伛)*/
	0x4f1e,	/*(伞)*/
	0x4f1f,	/*(伟)*/
	0x4f20,	/*(传)*/
	0x4f22,	/*(伢)*/
	0x4f24,	/*(伤)*/
	0x4f25,	/*(伥)*/
	0x4f26,	/*(伦)*/
	0x4f27,	/*(伧)*/
	0x4f2a,	/*(伪)*/
	0x4f2b,	/*(伫)*/
	0x4f2f,	/*(伯)*/
	0x4f30,	/*(估)*/
	0x4f32,	/*(伲)*/
	0x4f34,	/*(伴)*/
	0x4f36,	/*(伶)*/
	0x4f38,	/*(伸)*/
	0x4f3a,	/*(伺)*/
	0x4f3c,	/*(似)*/
	0x4f3d,	/*(伽)*/
	0x4f43,	/*(佃)*/
	0x4f46,	/*(但)*/
	0x4f4d,	/*(位)*/
	0x4f4e,	/*(低)*/
	0x4f4f,	/*(住)*/
	0x4f50,	/*(佐)*/
	0x4f51,	/*(佑)*/
	0x4f53,	/*(体)*/
	0x4f55,	/*(何)*/
	0x4f57,	/*(佗)*/
	0x4f58,	/*(佘)*/
	0x4f59,	/*(余)*/
	0x4f5a,	/*(佚)*/
	0x4f5b,	/*(佛)*/
	0x4f5c,	/*(作)*/
	0x4f5d,	/*(佝)*/
	0x4f5e,	/*(佞)*/
	0x4f5f,	/*(佟)*/
	0x4f60,	/*(你)*/
	0x4f63,	/*(佣)*/
	0x4f64,	/*(佤)*/
	0x4f65,	/*(佥)*/
	0x4f67,	/*(佧)*/
	0x4f69,	/*(佩)*/
	0x4f6c,	/*(佬)*/
	0x4f6f,	/*(佯)*/
	0x4f70,	/*(佰)*/
	0x4f73,	/*(佳)*/
	0x4f74,	/*(佴)*/
	0x4f76,	/*(佶)*/
	0x4f7b,	/*(佻)*/
	0x4f7c,	/*(佼)*/
	0x4f7e,	/*(佾)*/
	0x4f7f,	/*(使)*/
	0x4f83,	/*(侃)*/
	0x4f84,	/*(侄)*/
	0x4f88,	/*(侈)*/
	0x4f89,	/*(侉)*/
	0x4f8b,	/*(例)*/
	0x4f8d,	/*(侍)*/
	0x4f8f,	/*(侏)*/
	0x4f91,	/*(侑)*/
	0x4f94,	/*(侔)*/
	0x4f97,	/*(侗)*/
	0x4f9b,	/*(供)*/
	0x4f9d,	/*(依)*/
	0x4fa0,	/*(侠)*/
	0x4fa3,	/*(侣)*/
	0x4fa5,	/*(侥)*/
	0x4fa6,	/*(侦)*/
	0x4fa7,	/*(侧)*/
	0x4fa8,	/*(侨)*/
	0x4fa9,	/*(侩)*/
	0x4faa,	/*(侪)*/
	0x4fac,	/*(侬)*/
	0x4fae,	/*(侮)*/
	0x4faf,	/*(侯)*/
	0x4fb5,	/*(侵)*/
	0x4fbf,	/*(便)*/
	0x4fc3,	/*(促)*/
	0x4fc4,	/*(俄)*/
	0x4fc5,	/*(俅)*/
	0x4fca,	/*(俊)*/
	0x4fce,	/*(俎)*/
	0x4fcf,	/*(俏)*/
	0x4fd0,	/*(俐)*/
	0x4fd1,	/*(俑)*/
	0x4fd7,	/*(俗)*/
	0x4fd8,	/*(俘)*/
	0x4fda,	/*(俚)*/
	0x4fdc,	/*(俜)*/
	0x4fdd,	/*(保)*/
	0x4fde,	/*(俞)*/
	0x4fdf,	/*(俟)*/
	0x4fe1,	/*(信)*/
	0x4fe3,	/*(俣)*/
	0x4fe6,	/*(俦)*/
	0x4fe8,	/*(俨)*/
	0x4fe9,	/*(俩)*/
	0x4fea,	/*(俪)*/
	0x4fed,	/*(俭)*/
	0x4fee,	/*(修)*/
	0x4fef,	/*(俯)*/
	0x4ff1,	/*(俱)*/
	0x4ff3,	/*(俳)*/
	0x4ff8,	/*(俸)*/
	0x4ffa,	/*(俺)*/
	0x4ffe,	/*(俾)*/
	0x500c,	/*(倌)*/
	0x500d,	/*(倍)*/
	0x500f,	/*(倏)*/
	0x5012,	/*(倒)*/
	0x5014,	/*(倔)*/
	0x5018,	/*(倘)*/
	0x5019,	/*(候)*/
	0x501a,	/*(倚)*/
	0x501c,	/*(倜)*/
	0x501f,	/*(借)*/
	0x5021,	/*(倡)*/
	0x5025,	/*(倥)*/
	0x5026,	/*(倦)*/
	0x5028,	/*(倨)*/
	0x5029,	/*(倩)*/
	0x502a,	/*(倪)*/
	0x502c,	/*(倬)*/
	0x502d,	/*(倭)*/
	0x502e,	/*(倮)*/
	0x503a,	/*(债)*/
	0x503c,	/*(值)*/
	0x503e,	/*(倾)*/
	0x5043,	/*(偃)*/
	0x5047,	/*(假)*/
	0x5048,	/*(偈)*/
	0x504c,	/*(偌)*/
	0x504e,	/*(偎)*/
	0x504f,	/*(偏)*/
	0x5055,	/*(偕)*/
	0x505a,	/*(做)*/
	0x505c,	/*(停)*/
	0x5065,	/*(健)*/
	0x506c,	/*(偬)*/
	0x5076,	/*(偶)*/
	0x5077,	/*(偷)*/
	0x507b,	/*(偻)*/
	0x507e,	/*(偾)*/
	0x507f,	/*(偿)*/
	0x5080,	/*(傀)*/
	0x5085,	/*(傅)*/
	0x5088,	/*(傈)*/
	0x508d,	/*(傍)*/
	0x50a3,	/*(傣)*/
	0x50a5,	/*(傥)*/
	0x50a7,	/*(傧)*/
	0x50a8,	/*(储)*/
	0x50a9,	/*(傩)*/
	0x50ac,	/*(催)*/
	0x50b2,	/*(傲)*/
	0x50ba,	/*(傺)*/
	0x50bb,	/*(傻)*/
	0x50cf,	/*(像)*/
	0x50d6,	/*(僖)*/
	0x50da,	/*(僚)*/
	0x50e6,	/*(僦)*/
	0x50e7,	/*(僧)*/
	0x50ec,	/*(僬)*/
	0x50ed,	/*(僭)*/
	0x50ee,	/*(僮)*/
	0x50f3,	/*(僳)*/
	0x50f5,	/*(僵)*/
	0x50fb,	/*(僻)*/
	0x5106,	/*(儆)*/
	0x5107,	/*(儇)*/
	0x510b,	/*(儋)*/
	0x5112,	/*(儒)*/
	0x5121,	/*(儡)*/
	0x513f,	/*(儿)*/
	0x5140,	/*(兀)*/
	0x5141,	/*(允)*/
	0x5143,	/*(元)*/
	0x5144,	/*(兄)*/
	0x5145,	/*(充)*/
	0x5146,	/*(兆)*/
	0x5148,	/*(先)*/
	0x5149,	/*(光)*/
	0x514b,	/*(克)*/
	0x514d,	/*(免)*/
	0x5151,	/*(兑)*/
	0x5154,	/*(兔)*/
	0x5155,	/*(兕)*/
	0x5156,	/*(兖)*/
	0x515a,	/*(党)*/
	0x515c,	/*(兜)*/
	0x5162,	/*(兢)*/
	0x5165,	/*(入)*/
	0x5168,	/*(全)*/
	0x516b,	/*(八)*/
	0x516c,	/*(公)*/
	0x516d,	/*(六)*/
	0x516e,	/*(兮)*/
	0x5170,	/*(兰)*/
	0x5171,	/*(共)*/
	0x5173,	/*(关)*/
	0x5174,	/*(兴)*/
	0x5175,	/*(兵)*/
	0x5176,	/*(其)*/
	0x5177,	/*(具)*/
	0x5178,	/*(典)*/
	0x5179,	/*(兹)*/
	0x517b,	/*(养)*/
	0x517c,	/*(兼)*/
	0x517d,	/*(兽)*/
	0x5180,	/*(冀)*/
	0x5181,	/*(冁)*/
	0x5182,	/*(冂)*/
	0x5185,	/*(内)*/
	0x5188,	/*(冈)*/
	0x5189,	/*(冉)*/
	0x518c,	/*(册)*/
	0x518d,	/*(再)*/
	0x5192,	/*(冒)*/
	0x5195,	/*(冕)*/
	0x5196,	/*(冖)*/
	0x5197,	/*(冗)*/
	0x5199,	/*(写)*/
	0x519b,	/*(军)*/
	0x519c,	/*(农)*/
	0x51a0,	/*(冠)*/
	0x51a2,	/*(冢)*/
	0x51a4,	/*(冤)*/
	0x51a5,	/*(冥)*/
	0x51ab,	/*(冫)*/
	0x51ac,	/*(冬)*/
	0x51af,	/*(冯)*/
	0x51b0,	/*(冰)*/
	0x51b1,	/*(冱)*/
	0x51b2,	/*(冲)*/
	0x51b3,	/*(决)*/
	0x51b5,	/*(况)*/
	0x51b6,	/*(冶)*/
	0x51b7,	/*(冷)*/
	0x51bb,	/*(冻)*/
	0x51bc,	/*(冼)*/
	0x51bd,	/*(冽)*/
	0x51c0,	/*(净)*/
	0x51c4,	/*(凄)*/
	0x51c6,	/*(准)*/
	0x51c7,	/*(凇)*/
	0x51c9,	/*(凉)*/
	0x51cb,	/*(凋)*/
	0x51cc,	/*(凌)*/
	0x51cf,	/*(减)*/
	0x51d1,	/*(凑)*/
	0x51db,	/*(凛)*/
	0x51dd,	/*(凝)*/
	0x51e0,	/*(几)*/
	0x51e1,	/*(凡)*/
	0x51e4,	/*(凤)*/
	0x51eb,	/*(凫)*/
	0x51ed,	/*(凭)*/
	0x51ef,	/*(凯)*/
	0x51f0,	/*(凰)*/
	0x51f3,	/*(凳)*/
	0x51f5,	/*(凵)*/
	0x51f6,	/*(凶)*/
	0x51f8,	/*(凸)*/
	0x51f9,	/*(凹)*/
	0x51fa,	/*(出)*/
	0x51fb,	/*(击)*/
	0x51fc,	/*(凼)*/
	0x51fd,	/*(函)*/
	0x51ff,	/*(凿)*/
	0x5200,	/*(刀)*/
	0x5201,	/*(刁)*/
	0x5202,	/*(刂)*/
	0x5203,	/*(刃)*/
	0x5206,	/*(分)*/
	0x5207,	/*(切)*/
	0x5208,	/*(刈)*/
	0x520a,	/*(刊)*/
	0x520d,	/*(刍)*/
	0x520e,	/*(刎)*/
	0x5211,	/*(刑)*/
	0x5212,	/*(划)*/
	0x5216,	/*(刖)*/
	0x5217,	/*(列)*/
	0x5218,	/*(刘)*/
	0x5219,	/*(则)*/
	0x521a,	/*(刚)*/
	0x521b,	/*(创)*/
	0x521d,	/*(初)*/
	0x5220,	/*(删)*/
	0x5224,	/*(判)*/
	0x5228,	/*(刨)*/
	0x5229,	/*(利)*/
	0x522b,	/*(别)*/
	0x522d,	/*(刭)*/
	0x522e,	/*(刮)*/
	0x5230,	/*(到)*/
	0x5233,	/*(刳)*/
	0x5236,	/*(制)*/
	0x5237,	/*(刷)*/
	0x5238,	/*(券)*/
	0x5239,	/*(刹)*/
	0x523a,	/*(刺)*/
	0x523b,	/*(刻)*/
	0x523d,	/*(刽)*/
	0x523f,	/*(刿)*/
	0x5240,	/*(剀)*/
	0x5241,	/*(剁)*/
	0x5242,	/*(剂)*/
	0x5243,	/*(剃)*/
	0x524a,	/*(削)*/
	0x524c,	/*(剌)*/
	0x524d,	/*(前)*/
	0x5250,	/*(剐)*/
	0x5251,	/*(剑)*/
	0x5254,	/*(剔)*/
	0x5256,	/*(剖)*/
	0x525c,	/*(剜)*/
	0x525e,	/*(剞)*/
	0x5261,	/*(剡)*/
	0x5265,	/*(剥)*/
	0x5267,	/*(剧)*/
	0x5269,	/*(剩)*/
	0x526a,	/*(剪)*/
	0x526f,	/*(副)*/
	0x5272,	/*(割)*/
	0x527d,	/*(剽)*/
	0x527f,	/*(剿)*/
	0x5281,	/*(劁)*/
	0x5282,	/*(劂)*/
	0x5288,	/*(劈)*/
	0x5290,	/*(劐)*/
	0x5293,	/*(劓)*/
	0x529b,	/*(力)*/
	0x529d,	/*(劝)*/
	0x529e,	/*(办)*/
	0x529f,	/*(功)*/
	0x52a0,	/*(加)*/
	0x52a1,	/*(务)*/
	0x52a2,	/*(劢)*/
	0x52a3,	/*(劣)*/
	0x52a8,	/*(动)*/
	0x52a9,	/*(助)*/
	0x52aa,	/*(努)*/
	0x52ab,	/*(劫)*/
	0x52ac,	/*(劬)*/
	0x52ad,	/*(劭)*/
	0x52b1,	/*(励)*/
	0x52b2,	/*(劲)*/
	0x52b3,	/*(劳)*/
	0x52be,	/*(劾)*/
	0x52bf,	/*(势)*/
	0x52c3,	/*(勃)*/
	0x52c7,	/*(勇)*/
	0x52c9,	/*(勉)*/
	0x52cb,	/*(勋)*/
	0x52d0,	/*(勐)*/
	0x52d2,	/*(勒)*/
	0x52d6,	/*(勖)*/
	0x52d8,	/*(勘)*/
	0x52df,	/*(募)*/
	0x52e4,	/*(勤)*/
	0x52f0,	/*(勰)*/
	0x52f9,	/*(勹)*/
	0x52fa,	/*(勺)*/
	0x52fe,	/*(勾)*/
	0x52ff,	/*(勿)*/
	0x5300,	/*(匀)*/
	0x5305,	/*(包)*/
	0x5306,	/*(匆)*/
	0x5308,	/*(匈)*/
	0x530d,	/*(匍)*/
	0x530f,	/*(匏)*/
	0x5310,	/*(匐)*/
	0x5315,	/*(匕)*/
	0x5316,	/*(化)*/
	0x5317,	/*(北)*/
	0x5319,	/*(匙)*/
	0x531a,	/*(匚)*/
	0x531d,	/*(匝)*/
	0x5320,	/*(匠)*/
	0x5321,	/*(匡)*/
	0x5323,	/*(匣)*/
	0x5326,	/*(匦)*/
	0x532a,	/*(匪)*/
	0x532e,	/*(匮)*/
	0x5339,	/*(匹)*/
	0x533a,	/*(区)*/
	0x533b,	/*(医)*/
	0x533e,	/*(匾)*/
	0x533f,	/*(匿)*/
	0x5341,	/*(十)*/
	0x5343,	/*(千)*/
	0x5345,	/*(卅)*/
	0x5347,	/*(升)*/
	0x5348,	/*(午)*/
	0x5349,	/*(卉)*/
	0x534a,	/*(半)*/
	0x534e,	/*(华)*/
	0x534f,	/*(协)*/
	0x5351,	/*(卑)*/
	0x5352,	/*(卒)*/
	0x5353,	/*(卓)*/
	0x5355,	/*(单)*/
	0x5356,	/*(卖)*/
	0x5357,	/*(南)*/
	0x535a,	/*(博)*/
	0x535c,	/*(卜)*/
	0x535e,	/*(卞)*/
	0x535f,	/*(卟)*/
	0x5360,	/*(占)*/
	0x5361,	/*(卡)*/
	0x5362,	/*(卢)*/
	0x5363,	/*(卣)*/
	0x5364,	/*(卤)*/
	0x5366,	/*(卦)*/
	0x5367,	/*(卧)*/
	0x5369,	/*(卩)*/
	0x536b,	/*(卫)*/
	0x536e,	/*(卮)*/
	0x536f,	/*(卯)*/
	0x5370,	/*(印)*/
	0x5371,	/*(危)*/
	0x5373,	/*(即)*/
	0x5374,	/*(却)*/
	0x5375,	/*(卵)*/
	0x5377,	/*(卷)*/
	0x5378,	/*(卸)*/
	0x537a,	/*(卺)*/
	0x537f,	/*(卿)*/
	0x5382,	/*(厂)*/
	0x5384,	/*(厄)*/
	0x5385,	/*(厅)*/
	0x5386,	/*(历)*/
	0x5389,	/*(厉)*/
	0x538b,	/*(压)*/
	0x538c,	/*(厌)*/
	0x538d,	/*(厍)*/
	0x5395,	/*(厕)*/
	0x5398,	/*(厘)*/
	0x539a,	/*(厚)*/
	0x539d,	/*(厝)*/
	0x539f,	/*(原)*/
	0x53a2,	/*(厢)*/
	0x53a3,	/*(厣)*/
	0x53a5,	/*(厥)*/
	0x53a6,	/*(厦)*/
	0x53a8,	/*(厨)*/
	0x53a9,	/*(厩)*/
	0x53ae,	/*(厮)*/
	0x53b6,	/*(厶)*/
	0x53bb,	/*(去)*/
	0x53bf,	/*(县)*/
	0x53c1,	/*(叁)*/
	0x53c2,	/*(参)*/
	0x53c8,	/*(又)*/
	0x53c9,	/*(叉)*/
	0x53ca,	/*(及)*/
	0x53cb,	/*(友)*/
	0x53cc,	/*(双)*/
	0x53cd,	/*(反)*/
	0x53d1,	/*(发)*/
	0x53d4,	/*(叔)*/
	0x53d6,	/*(取)*/
	0x53d7,	/*(受)*/
	0x53d8,	/*(变)*/
	0x53d9,	/*(叙)*/
	0x53db,	/*(叛)*/
	0x53df,	/*(叟)*/
	0x53e0,	/*(叠)*/
	0x53e3,	/*(口)*/
	0x53e4,	/*(古)*/
	0x53e5,	/*(句)*/
	0x53e6,	/*(另)*/
	0x53e8,	/*(叨)*/
	0x53e9,	/*(叩)*/
	0x53ea,	/*(只)*/
	0x53eb,	/*(叫)*/
	0x53ec,	/*(召)*/
	0x53ed,	/*(叭)*/
	0x53ee,	/*(叮)*/
	0x53ef,	/*(可)*/
	0x53f0,	/*(台)*/
	0x53f1,	/*(叱)*/
	0x53f2,	/*(史)*/
	0x53f3,	/*(右)*/
	0x53f5,	/*(叵)*/
	0x53f6,	/*(叶)*/
	0x53f7,	/*(号)*/
	0x53f8,	/*(司)*/
	0x53f9,	/*(叹)*/
	0x53fb,	/*(叻)*/
	0x53fc,	/*(叼)*/
	0x53fd,	/*(叽)*/
	0x5401,	/*(吁)*/
	0x5403,	/*(吃)*/
	0x5404,	/*(各)*/
	0x5406,	/*(吆)*/
	0x5408,	/*(合)*/
	0x5409,	/*(吉)*/
	0x540a,	/*(吊)*/
	0x540c,	/*(同)*/
	0x540d,	/*(名)*/
	0x540e,	/*(后)*/
	0x540f,	/*(吏)*/
	0x5410,	/*(吐)*/
	0x5411,	/*(向)*/
	0x5412,	/*(吒)*/
	0x5413,	/*(吓)*/
	0x5415,	/*(吕)*/
	0x5416,	/*(吖)*/
	0x5417,	/*(吗)*/
	0x541b,	/*(君)*/
	0x541d,	/*(吝)*/
	0x541e,	/*(吞)*/
	0x541f,	/*(吟)*/
	0x5420,	/*(吠)*/
	0x5421,	/*(吡)*/
	0x5423,	/*(吣)*/
	0x5426,	/*(否)*/
	0x5427,	/*(吧)*/
	0x5428,	/*(吨)*/
	0x5429,	/*(吩)*/
	0x542b,	/*(含)*/
	0x542c,	/*(听)*/
	0x542d,	/*(吭)*/
	0x542e,	/*(吮)*/
	0x542f,	/*(启)*/
	0x5431,	/*(吱)*/
	0x5432,	/*(吲)*/
	0x5434,	/*(吴)*/
	0x5435,	/*(吵)*/
	0x5438,	/*(吸)*/
	0x5439,	/*(吹)*/
	0x543b,	/*(吻)*/
	0x543c,	/*(吼)*/
	0x543e,	/*(吾)*/
	0x5440,	/*(呀)*/
	0x5443,	/*(呃)*/
	0x5446,	/*(呆)*/
	0x5448,	/*(呈)*/
	0x544a,	/*(告)*/
	0x544b,	/*(呋)*/
	0x5450,	/*(呐)*/
	0x5452,	/*(呒)*/
	0x5453,	/*(呓)*/
	0x5454,	/*(呔)*/
	0x5455,	/*(呕)*/
	0x5456,	/*(呖)*/
	0x5457,	/*(呗)*/
	0x5458,	/*(员)*/
	0x5459,	/*(呙)*/
	0x545b,	/*(呛)*/
	0x545c,	/*(呜)*/
	0x5462,	/*(呢)*/
	0x5464,	/*(呤)*/
	0x5466,	/*(呦)*/
	0x5468,	/*(周)*/
	0x5471,	/*(呱)*/
	0x5472,	/*(呲)*/
	0x5473,	/*(味)*/
	0x5475,	/*(呵)*/
	0x5476,	/*(呶)*/
	0x5477,	/*(呷)*/
	0x5478,	/*(呸)*/
	0x547b,	/*(呻)*/
	0x547c,	/*(呼)*/
	0x547d,	/*(命)*/
	0x5480,	/*(咀)*/
	0x5482,	/*(咂)*/
	0x5484,	/*(咄)*/
	0x5486,	/*(咆)*/
	0x548b,	/*(咋)*/
	0x548c,	/*(和)*/
	0x548e,	/*(咎)*/
	0x548f,	/*(咏)*/
	0x5490,	/*(咐)*/
	0x5492,	/*(咒)*/
	0x5494,	/*(咔)*/
	0x5495,	/*(咕)*/
	0x5496,	/*(咖)*/
	0x5499,	/*(咙)*/
	0x549a,	/*(咚)*/
	0x549b,	/*(咛)*/
	0x549d,	/*(咝)*/
	0x54a3,	/*(咣)*/
	0x54a4,	/*(咤)*/
	0x54a6,	/*(咦)*/
	0x54a7,	/*(咧)*/
	0x54a8,	/*(咨)*/
	0x54a9,	/*(咩)*/
	0x54aa,	/*(咪)*/
	0x54ab,	/*(咫)*/
	0x54ac,	/*(咬)*/
	0x54ad,	/*(咭)*/
	0x54af,	/*(咯)*/
	0x54b1,	/*(咱)*/
	0x54b3,	/*(咳)*/
	0x54b4,	/*(咴)*/
	0x54b8,	/*(咸)*/
	0x54bb,	/*(咻)*/
	0x54bd,	/*(咽)*/
	0x54bf,	/*(咿)*/
	0x54c0,	/*(哀)*/
	0x54c1,	/*(品)*/
	0x54c2,	/*(哂)*/
	0x54c4,	/*(哄)*/
	0x54c6,	/*(哆)*/
	0x54c7,	/*(哇)*/
	0x54c8,	/*(哈)*/
	0x54c9,	/*(哉)*/
	0x54cc,	/*(哌)*/
	0x54cd,	/*(响)*/
	0x54ce,	/*(哎)*/
	0x54cf,	/*(哏)*/
	0x54d0,	/*(哐)*/
	0x54d1,	/*(哑)*/
	0x54d2,	/*(哒)*/
	0x54d3,	/*(哓)*/
	0x54d4,	/*(哔)*/
	0x54d5,	/*(哕)*/
	0x54d7,	/*(哗)*/
	0x54d9,	/*(哙)*/
	0x54da,	/*(哚)*/
	0x54dc,	/*(哜)*/
	0x54dd,	/*(哝)*/
	0x54de,	/*(哞)*/
	0x54df,	/*(哟)*/
	0x54e5,	/*(哥)*/
	0x54e6,	/*(哦)*/
	0x54e7,	/*(哧)*/
	0x54e8,	/*(哨)*/
	0x54e9,	/*(哩)*/
	0x54ea,	/*(哪)*/
	0x54ed,	/*(哭)*/
	0x54ee,	/*(哮)*/
	0x54f2,	/*(哲)*/
	0x54f3,	/*(哳)*/
	0x54fa,	/*(哺)*/
	0x54fc,	/*(哼)*/
	0x54fd,	/*(哽)*/
	0x54ff,	/*(哿)*/
	0x5501,	/*(唁)*/
	0x5506,	/*(唆)*/
	0x5507,	/*(唇)*/
	0x5509,	/*(唉)*/
	0x550f,	/*(唏)*/
	0x5510,	/*(唐)*/
	0x5511,	/*(唑)*/
	0x5514,	/*(唔)*/
	0x551b,	/*(唛)*/
	0x5520,	/*(唠)*/
	0x5522,	/*(唢)*/
	0x5523,	/*(唣)*/
	0x5524,	/*(唤)*/
	0x5527,	/*(唧)*/
	0x552a,	/*(唪)*/
	0x552c,	/*(唬)*/
	0x552e,	/*(售)*/
	0x552f,	/*(唯)*/
	0x5530,	/*(唰)*/
	0x5531,	/*(唱)*/
	0x5533,	/*(唳)*/
	0x5537,	/*(唷)*/
	0x553c,	/*(唼)*/
	0x553e,	/*(唾)*/
	0x553f,	/*(唿)*/
	0x5541,	/*(啁)*/
	0x5543,	/*(啃)*/
	0x5544,	/*(啄)*/
	0x5546,	/*(商)*/
	0x5549,	/*(啉)*/
	0x554a,	/*(啊)*/
	0x5550,	/*(啐)*/
	0x5555,	/*(啕)*/
	0x5556,	/*(啖)*/
	0x555c,	/*(啜)*/
	0x5561,	/*(啡)*/
	0x5564,	/*(啤)*/
	0x5565,	/*(啥)*/
	0x5566,	/*(啦)*/
	0x5567,	/*(啧)*/
	0x556a,	/*(啪)*/
	0x556c,	/*(啬)*/
	0x556d,	/*(啭)*/
	0x556e,	/*(啮)*/
	0x5575,	/*(啵)*/
	0x5576,	/*(啶)*/
	0x5577,	/*(啷)*/
	0x5578,	/*(啸)*/
	0x557b,	/*(啻)*/
	0x557c,	/*(啼)*/
	0x557e,	/*(啾)*/
	0x5580,	/*(喀)*/
	0x5581,	/*(喁)*/
	0x5582,	/*(喂)*/
	0x5583,	/*(喃)*/
	0x5584,	/*(善)*/
	0x5587,	/*(喇)*/
	0x5588,	/*(喈)*/
	0x5589,	/*(喉)*/
	0x558a,	/*(喊)*/
	0x558b,	/*(喋)*/
	0x558f,	/*(喏)*/
	0x5591,	/*(喑)*/
	0x5594,	/*(喔)*/
	0x5598,	/*(喘)*/
	0x5599,	/*(喙)*/
	0x559c,	/*(喜)*/
	0x559d,	/*(喝)*/
	0x559f,	/*(喟)*/
	0x55a7,	/*(喧)*/
	0x55b1,	/*(喱)*/
	0x55b3,	/*(喳)*/
	0x55b5,	/*(喵)*/
	0x55b7,	/*(喷)*/
	0x55b9,	/*(喹)*/
	0x55bb,	/*(喻)*/
	0x55bd,	/*(喽)*/
	0x55be,	/*(喾)*/
	0x55c4,	/*(嗄)*/
	0x55c5,	/*(嗅)*/
	0x55c9,	/*(嗉)*/
	0x55cc,	/*(嗌)*/
	0x55cd,	/*(嗍)*/
	0x55d1,	/*(嗑)*/
	0x55d2,	/*(嗒)*/
	0x55d3,	/*(嗓)*/
	0x55d4,	/*(嗔)*/
	0x55d6,	/*(嗖)*/
	0x55dc,	/*(嗜)*/
	0x55dd,	/*(嗝)*/
	0x55df,	/*(嗟)*/
	0x55e1,	/*(嗡)*/
	0x55e3,	/*(嗣)*/
	0x55e4,	/*(嗤)*/
	0x55e5,	/*(嗥)*/
	0x55e6,	/*(嗦)*/
	0x55e8,	/*(嗨)*/
	0x55ea,	/*(嗪)*/
	0x55eb,	/*(嗫)*/
	0x55ec,	/*(嗬)*/
	0x55ef,	/*(嗯)*/
	0x55f2,	/*(嗲)*/
	0x55f3,	/*(嗳)*/
	0x55f5,	/*(嗵)*/
	0x55f7,	/*(嗷)*/
	0x55fd,	/*(嗽)*/
	0x55fe,	/*(嗾)*/
	0x5600,	/*(嘀)*/
	0x5601,	/*(嘁)*/
	0x5608,	/*(嘈)*/
	0x5609,	/*(嘉)*/
	0x560c,	/*(嘌)*/
	0x560e,	/*(嘎)*/
	0x560f,	/*(嘏)*/
	0x5618,	/*(嘘)*/
	0x561b,	/*(嘛)*/
	0x561e,	/*(嘞)*/
	0x561f,	/*(嘟)*/
	0x5623,	/*(嘣)*/
	0x5624,	/*(嘤)*/
	0x5627,	/*(嘧)*/
	0x562c,	/*(嘬)*/
	0x562d,	/*(嘭)*/
	0x5631,	/*(嘱)*/
	0x5632,	/*(嘲)*/
	0x5634,	/*(嘴)*/
	0x5636,	/*(嘶)*/
	0x5639,	/*(嘹)*/
	0x563b,	/*(嘻)*/
	0x563f,	/*(嘿)*/
	0x564c,	/*(噌)*/
	0x564d,	/*(噍)*/
	0x564e,	/*(噎)*/
	0x5654,	/*(噔)*/
	0x5657,	/*(噗)*/
	0x5658,	/*(噘)*/
	0x5659,	/*(噙)*/
	0x565c,	/*(噜)*/
	0x5662,	/*(噢)*/
	0x5664,	/*(噤)*/
	0x5668,	/*(器)*/
	0x5669,	/*(噩)*/
	0x566a,	/*(噪)*/
	0x566b,	/*(噫)*/
	0x566c,	/*(噬)*/
	0x5671,	/*(噱)*/
	0x5676,	/*(噶)*/
	0x567b,	/*(噻)*/
	0x567c,	/*(噼)*/
	0x5685,	/*(嚅)*/
	0x5686,	/*(嚆)*/
	0x568e,	/*(嚎)*/
	0x568f,	/*(嚏)*/
	0x5693,	/*(嚓)*/
	0x56a3,	/*(嚣)*/
	0x56af,	/*(嚯)*/
	0x56b7,	/*(嚷)*/
	0x56bc,	/*(嚼)*/
	0x56ca,	/*(囊)*/
	0x56d4,	/*(囔)*/
	0x56d7,	/*(囗)*/
	0x56da,	/*(囚)*/
	0x56db,	/*(四)*/
	0x56dd,	/*(囝)*/
	0x56de,	/*(回)*/
	0x56df,	/*(囟)*/
	0x56e0,	/*(因)*/
	0x56e1,	/*(囡)*/
	0x56e2,	/*(团)*/
	0x56e4,	/*(囤)*/
	0x56eb,	/*(囫)*/
	0x56ed,	/*(园)*/
	0x56f0,	/*(困)*/
	0x56f1,	/*(囱)*/
	0x56f4,	/*(围)*/
	0x56f5,	/*(囵)*/
	0x56f9,	/*(囹)*/
	0x56fa,	/*(固)*/
	0x56fd,	/*(国)*/
	0x56fe,	/*(图)*/
	0x56ff,	/*(囿)*/
	0x5703,	/*(圃)*/
	0x5704,	/*(圄)*/
	0x5706,	/*(圆)*/
	0x5708,	/*(圈)*/
	0x5709,	/*(圉)*/
	0x570a,	/*(圊)*/
	0x571c,	/*(圜)*/
	0x571f,	/*(土)*/
	0x5723,	/*(圣)*/
	0x5728,	/*(在)*/
	0x5729,	/*(圩)*/
	0x572a,	/*(圪)*/
	0x572c,	/*(圬)*/
	0x572d,	/*(圭)*/
	0x572e,	/*(圮)*/
	0x572f,	/*(圯)*/
	0x5730,	/*(地)*/
	0x5733,	/*(圳)*/
	0x5739,	/*(圹)*/
	0x573a,	/*(场)*/
	0x573b,	/*(圻)*/
	0x573e,	/*(圾)*/
	0x5740,	/*(址)*/
	0x5742,	/*(坂)*/
	0x5747,	/*(均)*/
	0x574a,	/*(坊)*/
	0x574c,	/*(坌)*/
	0x574d,	/*(坍)*/
	0x574e,	/*(坎)*/
	0x574f,	/*(坏)*/
	0x5750,	/*(坐)*/
	0x5751,	/*(坑)*/
	0x5757,	/*(块)*/
	0x575a,	/*(坚)*/
	0x575b,	/*(坛)*/
	0x575c,	/*(坜)*/
	0x575d,	/*(坝)*/
	0x575e,	/*(坞)*/
	0x575f,	/*(坟)*/
	0x5760,	/*(坠)*/
	0x5761,	/*(坡)*/
	0x5764,	/*(坤)*/
	0x5766,	/*(坦)*/
	0x5768,	/*(坨)*/
	0x5769,	/*(坩)*/
	0x576a,	/*(坪)*/
	0x576b,	/*(坫)*/
	0x576d,	/*(坭)*/
	0x576f,	/*(坯)*/
	0x5773,	/*(坳)*/
	0x5776,	/*(坶)*/
	0x5777,	/*(坷)*/
	0x577b,	/*(坻)*/
	0x577c,	/*(坼)*/
	0x5782,	/*(垂)*/
	0x5783,	/*(垃)*/
	0x5784,	/*(垄)*/
	0x5785,	/*(垅)*/
	0x5786,	/*(垆)*/
	0x578b,	/*(型)*/
	0x578c,	/*(垌)*/
	0x5792,	/*(垒)*/
	0x5793,	/*(垓)*/
	0x579b,	/*(垛)*/
	0x57a0,	/*(垠)*/
	0x57a1,	/*(垡)*/
	0x57a2,	/*(垢)*/
	0x57a3,	/*(垣)*/
	0x57a4,	/*(垤)*/
	0x57a6,	/*(垦)*/
	0x57a7,	/*(垧)*/
	0x57a9,	/*(垩)*/
	0x57ab,	/*(垫)*/
	0x57ad,	/*(垭)*/
	0x57ae,	/*(垮)*/
	0x57b2,	/*(垲)*/
	0x57b4,	/*(垴)*/
	0x57b8,	/*(垸)*/
	0x57c2,	/*(埂)*/
	0x57c3,	/*(埃)*/
	0x57cb,	/*(埋)*/
	0x57ce,	/*(城)*/
	0x57cf,	/*(埏)*/
	0x57d2,	/*(埒)*/
	0x57d4,	/*(埔)*/
	0x57d5,	/*(埕)*/
	0x57d8,	/*(埘)*/
	0x57d9,	/*(埙)*/
	0x57da,	/*(埚)*/
	0x57dd,	/*(埝)*/
	0x57df,	/*(域)*/
	0x57e0,	/*(埠)*/
	0x57e4,	/*(埤)*/
	0x57ed,	/*(埭)*/
	0x57ef,	/*(埯)*/
	0x57f4,	/*(埴)*/
	0x57f8,	/*(埸)*/
	0x57f9,	/*(培)*/
	0x57fa,	/*(基)*/
	0x57fd,	/*(埽)*/
	0x5800,	/*(堀)*/
	0x5802,	/*(堂)*/
	0x5806,	/*(堆)*/
	0x5807,	/*(堇)*/
	0x580b,	/*(堋)*/
	0x580d,	/*(堍)*/
	0x5811,	/*(堑)*/
	0x5815,	/*(堕)*/
	0x5819,	/*(堙)*/
	0x581e,	/*(堞)*/
	0x5820,	/*(堠)*/
	0x5821,	/*(堡)*/
	0x5824,	/*(堤)*/
	0x582a,	/*(堪)*/
	0x5830,	/*(堰)*/
	0x5835,	/*(堵)*/
	0x5844,	/*(塄)*/
	0x584c,	/*(塌)*/
	0x584d,	/*(塍)*/
	0x5851,	/*(塑)*/
	0x5854,	/*(塔)*/
	0x5858,	/*(塘)*/
	0x585e,	/*(塞)*/
	0x5865,	/*(塥)*/
	0x586b,	/*(填)*/
	0x586c,	/*(塬)*/
	0x587e,	/*(塾)*/
	0x5880,	/*(墀)*/
	0x5881,	/*(墁)*/
	0x5883,	/*(境)*/
	0x5885,	/*(墅)*/
	0x5889,	/*(墉)*/
	0x5892,	/*(墒)*/
	0x5893,	/*(墓)*/
	0x5899,	/*(墙)*/
	0x589a,	/*(墚)*/
	0x589e,	/*(增)*/
	0x589f,	/*(墟)*/
	0x58a8,	/*(墨)*/
	0x58a9,	/*(墩)*/
	0x58bc,	/*(墼)*/
	0x58c1,	/*(壁)*/
	0x58c5,	/*(壅)*/
	0x58d1,	/*(壑)*/
	0x58d5,	/*(壕)*/
	0x58e4,	/*(壤)*/
	0x58eb,	/*(士)*/
	0x58ec,	/*(壬)*/
	0x58ee,	/*(壮)*/
	0x58f0,	/*(声)*/
	0x58f3,	/*(壳)*/
	0x58f6,	/*(壶)*/
	0x58f9,	/*(壹)*/
	0x5902,	/*(夂)*/
	0x5904,	/*(处)*/
	0x5907,	/*(备)*/
	0x590d,	/*(复)*/
	0x590f,	/*(夏)*/
	0x5914,	/*(夔)*/
	0x5915,	/*(夕)*/
	0x5916,	/*(外)*/
	0x5919,	/*(夙)*/
	0x591a,	/*(多)*/
	0x591c,	/*(夜)*/
	0x591f,	/*(够)*/
	0x5924,	/*(夤)*/
	0x5925,	/*(夥)*/
	0x5927,	/*(大)*/
	0x5929,	/*(天)*/
	0x592a,	/*(太)*/
	0x592b,	/*(夫)*/
	0x592d,	/*(夭)*/
	0x592e,	/*(央)*/
	0x592f,	/*(夯)*/
	0x5931,	/*(失)*/
	0x5934,	/*(头)*/
	0x5937,	/*(夷)*/
	0x5938,	/*(夸)*/
	0x5939,	/*(夹)*/
	0x593a,	/*(夺)*/
	0x593c,	/*(夼)*/
	0x5941,	/*(奁)*/
	0x5942,	/*(奂)*/
	0x5944,	/*(奄)*/
	0x5947,	/*(奇)*/
	0x5948,	/*(奈)*/
	0x5949,	/*(奉)*/
	0x594b,	/*(奋)*/
	0x594e,	/*(奎)*/
	0x594f,	/*(奏)*/
	0x5951,	/*(契)*/
	0x5954,	/*(奔)*/
	0x5955,	/*(奕)*/
	0x5956,	/*(奖)*/
	0x5957,	/*(套)*/
	0x5958,	/*(奘)*/
	0x595a,	/*(奚)*/
	0x5960,	/*(奠)*/
	0x5962,	/*(奢)*/
	0x5965,	/*(奥)*/
	0x5973,	/*(女)*/
	0x5974,	/*(奴)*/
	0x5976,	/*(奶)*/
	0x5978,	/*(奸)*/
	0x5979,	/*(她)*/
	0x597d,	/*(好)*/
	0x5981,	/*(妁)*/
	0x5982,	/*(如)*/
	0x5983,	/*(妃)*/
	0x5984,	/*(妄)*/
	0x5986,	/*(妆)*/
	0x5987,	/*(妇)*/
	0x5988,	/*(妈)*/
	0x598a,	/*(妊)*/
	0x598d,	/*(妍)*/
	0x5992,	/*(妒)*/
	0x5993,	/*(妓)*/
	0x5996,	/*(妖)*/
	0x5997,	/*(妗)*/
	0x5999,	/*(妙)*/
	0x599e,	/*(妞)*/
	0x59a3,	/*(妣)*/
	0x59a4,	/*(妤)*/
	0x59a5,	/*(妥)*/
	0x59a8,	/*(妨)*/
	0x59a9,	/*(妩)*/
	0x59aa,	/*(妪)*/
	0x59ab,	/*(妫)*/
	0x59ae,	/*(妮)*/
	0x59af,	/*(妯)*/
	0x59b2,	/*(妲)*/
	0x59b9,	/*(妹)*/
	0x59bb,	/*(妻)*/
	0x59be,	/*(妾)*/
	0x59c6,	/*(姆)*/
	0x59ca,	/*(姊)*/
	0x59cb,	/*(始)*/
	0x59d0,	/*(姐)*/
	0x59d1,	/*(姑)*/
	0x59d2,	/*(姒)*/
	0x59d3,	/*(姓)*/
	0x59d4,	/*(委)*/
	0x59d7,	/*(姗)*/
	0x59d8,	/*(姘)*/
	0x59da,	/*(姚)*/
	0x59dc,	/*(姜)*/
	0x59dd,	/*(姝)*/
	0x59e3,	/*(姣)*/
	0x59e5,	/*(姥)*/
	0x59e8,	/*(姨)*/
	0x59ec,	/*(姬)*/
	0x59f9,	/*(姹)*/
	0x59fb,	/*(姻)*/
	0x59ff,	/*(姿)*/
	0x5a01,	/*(威)*/
	0x5a03,	/*(娃)*/
	0x5a04,	/*(娄)*/
	0x5a05,	/*(娅)*/
	0x5a06,	/*(娆)*/
	0x5a07,	/*(娇)*/
	0x5a08,	/*(娈)*/
	0x5a09,	/*(娉)*/
	0x5a0c,	/*(娌)*/
	0x5a11,	/*(娑)*/
	0x5a13,	/*(娓)*/
	0x5a18,	/*(娘)*/
	0x5a1c,	/*(娜)*/
	0x5a1f,	/*(娟)*/
	0x5a20,	/*(娠)*/
	0x5a23,	/*(娣)*/
	0x5a25,	/*(娥)*/
	0x5a29,	/*(娩)*/
	0x5a31,	/*(娱)*/
	0x5a32,	/*(娲)*/
	0x5a34,	/*(娴)*/
	0x5a36,	/*(娶)*/
	0x5a3c,	/*(娼)*/
	0x5a40,	/*(婀)*/
	0x5a46,	/*(婆)*/
	0x5a49,	/*(婉)*/
	0x5a4a,	/*(婊)*/
	0x5a55,	/*(婕)*/
	0x5a5a,	/*(婚)*/
	0x5a62,	/*(婢)*/
	0x5a67,	/*(婧)*/
	0x5a6a,	/*(婪)*/
	0x5a74,	/*(婴)*/
	0x5a75,	/*(婵)*/
	0x5a76,	/*(婶)*/
	0x5a77,	/*(婷)*/
	0x5a7a,	/*(婺)*/
	0x5a7f,	/*(婿)*/
	0x5a92,	/*(媒)*/
	0x5a9a,	/*(媚)*/
	0x5a9b,	/*(媛)*/
	0x5aaa,	/*(媪)*/
	0x5ab2,	/*(媲)*/
	0x5ab3,	/*(媳)*/
	0x5ab5,	/*(媵)*/
	0x5ab8,	/*(媸)*/
	0x5abe,	/*(媾)*/
	0x5ac1,	/*(嫁)*/
	0x5ac2,	/*(嫂)*/
	0x5ac9,	/*(嫉)*/
	0x5acc,	/*(嫌)*/
	0x5ad2,	/*(嫒)*/
	0x5ad4,	/*(嫔)*/
	0x5ad6,	/*(嫖)*/
	0x5ad8,	/*(嫘)*/
	0x5adc,	/*(嫜)*/
	0x5ae0,	/*(嫠)*/
	0x5ae1,	/*(嫡)*/
	0x5ae3,	/*(嫣)*/
	0x5ae6,	/*(嫦)*/
	0x5ae9,	/*(嫩)*/
	0x5aeb,	/*(嫫)*/
	0x5af1,	/*(嫱)*/
	0x5b09,	/*(嬉)*/
	0x5b16,	/*(嬖)*/
	0x5b17,	/*(嬗)*/
	0x5b32,	/*(嬲)*/
	0x5b34,	/*(嬴)*/
	0x5b37,	/*(嬷)*/
	0x5b40,	/*(孀)*/
	0x5b50,	/*(子)*/
	0x5b51,	/*(孑)*/
	0x5b53,	/*(孓)*/
	0x5b54,	/*(孔)*/
	0x5b55,	/*(孕)*/
	0x5b57,	/*(字)*/
	0x5b58,	/*(存)*/
	0x5b59,	/*(孙)*/
	0x5b5a,	/*(孚)*/
	0x5b5b,	/*(孛)*/
	0x5b5c,	/*(孜)*/
	0x5b5d,	/*(孝)*/
	0x5b5f,	/*(孟)*/
	0x5b62,	/*(孢)*/
	0x5b63,	/*(季)*/
	0x5b64,	/*(孤)*/
	0x5b65,	/*(孥)*/
	0x5b66,	/*(学)*/
	0x5b69,	/*(孩)*/
	0x5b6a,	/*(孪)*/
	0x5b6c,	/*(孬)*/
	0x5b70,	/*(孰)*/
	0x5b71,	/*(孱)*/
	0x5b73,	/*(孳)*/
	0x5b75,	/*(孵)*/
	0x5b7a,	/*(孺)*/
	0x5b7d,	/*(孽)*/
	0x5b80,	/*(宀)*/
	0x5b81,	/*(宁)*/
	0x5b83,	/*(它)*/
	0x5b84,	/*(宄)*/
	0x5b85,	/*(宅)*/
	0x5b87,	/*(宇)*/
	0x5b88,	/*(守)*/
	0x5b89,	/*(安)*/
	0x5b8b,	/*(宋)*/
	0x5b8c,	/*(完)*/
	0x5b8f,	/*(宏)*/
	0x5b93,	/*(宓)*/
	0x5b95,	/*(宕)*/
	0x5b97,	/*(宗)*/
	0x5b98,	/*(官)*/
	0x5b99,	/*(宙)*/
	0x5b9a,	/*(定)*/
	0x5b9b,	/*(宛)*/
	0x5b9c,	/*(宜)*/
	0x5b9d,	/*(宝)*/
	0x5b9e,	/*(实)*/
	0x5ba0,	/*(宠)*/
	0x5ba1,	/*(审)*/
	0x5ba2,	/*(客)*/
	0x5ba3,	/*(宣)*/
	0x5ba4,	/*(室)*/
	0x5ba5,	/*(宥)*/
	0x5ba6,	/*(宦)*/
	0x5baa,	/*(宪)*/
	0x5bab,	/*(宫)*/
	0x5bb0,	/*(宰)*/
	0x5bb3,	/*(害)*/
	0x5bb4,	/*(宴)*/
	0x5bb5,	/*(宵)*/
	0x5bb6,	/*(家)*/
	0x5bb8,	/*(宸)*/
	0x5bb9,	/*(容)*/
	0x5bbd,	/*(宽)*/
	0x5bbe,	/*(宾)*/
	0x5bbf,	/*(宿)*/
	0x5bc2,	/*(寂)*/
	0x5bc4,	/*(寄)*/
	0x5bc5,	/*(寅)*/
	0x5bc6,	/*(密)*/
	0x5bc7,	/*(寇)*/
	0x5bcc,	/*(富)*/
	0x5bd0,	/*(寐)*/
	0x5bd2,	/*(寒)*/
	0x5bd3,	/*(寓)*/
	0x5bdd,	/*(寝)*/
	0x5bde,	/*(寞)*/
	0x5bdf,	/*(察)*/
	0x5be1,	/*(寡)*/
	0x5be4,	/*(寤)*/
	0x5be5,	/*(寥)*/
	0x5be8,	/*(寨)*/
	0x5bee,	/*(寮)*/
	0x5bf0,	/*(寰)*/
	0x5bf8,	/*(寸)*/
	0x5bf9,	/*(对)*/
	0x5bfa,	/*(寺)*/
	0x5bfb,	/*(寻)*/
	0x5bfc,	/*(导)*/
	0x5bff,	/*(寿)*/
	0x5c01,	/*(封)*/
	0x5c04,	/*(射)*/
	0x5c06,	/*(将)*/
	0x5c09,	/*(尉)*/
	0x5c0a,	/*(尊)*/
	0x5c0f,	/*(小)*/
	0x5c11,	/*(少)*/
	0x5c14,	/*(尔)*/
	0x5c15,	/*(尕)*/
	0x5c16,	/*(尖)*/
	0x5c18,	/*(尘)*/
	0x5c1a,	/*(尚)*/
	0x5c1c,	/*(尜)*/
	0x5c1d,	/*(尝)*/
	0x5c22,	/*(尢)*/
	0x5c24,	/*(尤)*/
	0x5c25,	/*(尥)*/
	0x5c27,	/*(尧)*/
	0x5c2c,	/*(尬)*/
	0x5c31,	/*(就)*/
	0x5c34,	/*(尴)*/
	0x5c38,	/*(尸)*/
	0x5c39,	/*(尹)*/
	0x5c3a,	/*(尺)*/
	0x5c3b,	/*(尻)*/
	0x5c3c,	/*(尼)*/
	0x5c3d,	/*(尽)*/
	0x5c3e,	/*(尾)*/
	0x5c3f,	/*(尿)*/
	0x5c40,	/*(局)*/
	0x5c41,	/*(屁)*/
	0x5c42,	/*(层)*/
	0x5c45,	/*(居)*/
	0x5c48,	/*(屈)*/
	0x5c49,	/*(屉)*/
	0x5c4a,	/*(届)*/
	0x5c4b,	/*(屋)*/
	0x5c4e,	/*(屎)*/
	0x5c4f,	/*(屏)*/
	0x5c50,	/*(屐)*/
	0x5c51,	/*(屑)*/
	0x5c55,	/*(展)*/
	0x5c59,	/*(屙)*/
	0x5c5e,	/*(属)*/
	0x5c60,	/*(屠)*/
	0x5c61,	/*(屡)*/
	0x5c63,	/*(屣)*/
	0x5c65,	/*(履)*/
	0x5c66,	/*(屦)*/
	0x5c6e,	/*(屮)*/
	0x5c6f,	/*(屯)*/
	0x5c71,	/*(山)*/
	0x5c79,	/*(屹)*/
	0x5c7a,	/*(屺)*/
	0x5c7f,	/*(屿)*/
	0x5c81,	/*(岁)*/
	0x5c82,	/*(岂)*/
	0x5c88,	/*(岈)*/
	0x5c8c,	/*(岌)*/
	0x5c8d,	/*(岍)*/
	0x5c90,	/*(岐)*/
	0x5c91,	/*(岑)*/
	0x5c94,	/*(岔)*/
	0x5c96,	/*(岖)*/
	0x5c97,	/*(岗)*/
	0x5c98,	/*(岘)*/
	0x5c99,	/*(岙)*/
	0x5c9a,	/*(岚)*/
	0x5c9b,	/*(岛)*/
	0x5c9c,	/*(岜)*/
	0x5ca2,	/*(岢)*/
	0x5ca3,	/*(岣)*/
	0x5ca9,	/*(岩)*/
	0x5cab,	/*(岫)*/
	0x5cac,	/*(岬)*/
	0x5cad,	/*(岭)*/
	0x5cb1,	/*(岱)*/
	0x5cb3,	/*(岳)*/
	0x5cb5,	/*(岵)*/
	0x5cb7,	/*(岷)*/
	0x5cb8,	/*(岸)*/
	0x5cbd,	/*(岽)*/
	0x5cbf,	/*(岿)*/
	0x5cc1,	/*(峁)*/
	0x5cc4,	/*(峄)*/
	0x5ccb,	/*(峋)*/
	0x5cd2,	/*(峒)*/
	0x5cd9,	/*(峙)*/
	0x5ce1,	/*(峡)*/
	0x5ce4,	/*(峤)*/
	0x5ce5,	/*(峥)*/
	0x5ce6,	/*(峦)*/
	0x5ce8,	/*(峨)*/
	0x5cea,	/*(峪)*/
	0x5ced,	/*(峭)*/
	0x5cf0,	/*(峰)*/
	0x5cfb,	/*(峻)*/
	0x5d02,	/*(崂)*/
	0x5d03,	/*(崃)*/
	0x5d06,	/*(崆)*/
	0x5d07,	/*(崇)*/
	0x5d0e,	/*(崎)*/
	0x5d14,	/*(崔)*/
	0x5d16,	/*(崖)*/
	0x5d1b,	/*(崛)*/
	0x5d1e,	/*(崞)*/
	0x5d24,	/*(崤)*/
	0x5d26,	/*(崦)*/
	0x5d27,	/*(崧)*/
	0x5d29,	/*(崩)*/
	0x5d2d,	/*(崭)*/
	0x5d2e,	/*(崮)*/
	0x5d34,	/*(崴)*/
	0x5d3d,	/*(崽)*/
	0x5d3e,	/*(崾)*/
	0x5d47,	/*(嵇)*/
	0x5d4a,	/*(嵊)*/
	0x5d4b,	/*(嵋)*/
	0x5d4c,	/*(嵌)*/
	0x5d58,	/*(嵘)*/
	0x5d5b,	/*(嵛)*/
	0x5d5d,	/*(嵝)*/
	0x5d69,	/*(嵩)*/
	0x5d6b,	/*(嵫)*/
	0x5d6c,	/*(嵬)*/
	0x5d6f,	/*(嵯)*/
	0x5d74,	/*(嵴)*/
	0x5d82,	/*(嶂)*/
	0x5d99,	/*(嶙)*/
	0x5d9d,	/*(嶝)*/
	0x5db7,	/*(嶷)*/
	0x5dc5,	/*(巅)*/
	0x5dcd,	/*(巍)*/
	0x5ddb,	/*(巛)*/
	0x5ddd,	/*(川)*/
	0x5dde,	/*(州)*/
	0x5de1,	/*(巡)*/
	0x5de2,	/*(巢)*/
	0x5de5,	/*(工)*/
	0x5de6,	/*(左)*/
	0x5de7,	/*(巧)*/
	0x5de8,	/*(巨)*/
	0x5de9,	/*(巩)*/
	0x5deb,	/*(巫)*/
	0x5dee,	/*(差)*/
	0x5def,	/*(巯)*/
	0x5df1,	/*(己)*/
	0x5df2,	/*(已)*/
	0x5df3,	/*(巳)*/
	0x5df4,	/*(巴)*/
	0x5df7,	/*(巷)*/
	0x5dfd,	/*(巽)*/
	0x5dfe,	/*(巾)*/
	0x5e01,	/*(币)*/
	0x5e02,	/*(市)*/
	0x5e03,	/*(布)*/
	0x5e05,	/*(帅)*/
	0x5e06,	/*(帆)*/
	0x5e08,	/*(师)*/
	0x5e0c,	/*(希)*/
	0x5e0f,	/*(帏)*/
	0x5e10,	/*(帐)*/
	0x5e11,	/*(帑)*/
	0x5e14,	/*(帔)*/
	0x5e15,	/*(帕)*/
	0x5e16,	/*(帖)*/
	0x5e18,	/*(帘)*/
	0x5e19,	/*(帙)*/
	0x5e1a,	/*(帚)*/
	0x5e1b,	/*(帛)*/
	0x5e1c,	/*(帜)*/
	0x5e1d,	/*(帝)*/
	0x5e26,	/*(带)*/
	0x5e27,	/*(帧)*/
	0x5e2d,	/*(席)*/
	0x5e2e,	/*(帮)*/
	0x5e31,	/*(帱)*/
	0x5e37,	/*(帷)*/
	0x5e38,	/*(常)*/
	0x5e3b,	/*(帻)*/
	0x5e3c,	/*(帼)*/
	0x5e3d,	/*(帽)*/
	0x5e42,	/*(幂)*/
	0x5e44,	/*(幄)*/
	0x5e45,	/*(幅)*/
	0x5e4c,	/*(幌)*/
	0x5e54,	/*(幔)*/
	0x5e55,	/*(幕)*/
	0x5e5b,	/*(幛)*/
	0x5e5e,	/*(幞)*/
	0x5e61,	/*(幡)*/
	0x5e62,	/*(幢)*/
	0x5e72,	/*(干)*/
	0x5e73,	/*(平)*/
	0x5e74,	/*(年)*/
	0x5e76,	/*(并)*/
	0x5e78,	/*(幸)*/
	0x5e7a,	/*(幺)*/
	0x5e7b,	/*(幻)*/
	0x5e7c,	/*(幼)*/
	0x5e7d,	/*(幽)*/
	0x5e7f,	/*(广)*/
	0x5e80,	/*(庀)*/
	0x5e84,	/*(庄)*/
	0x5e86,	/*(庆)*/
	0x5e87,	/*(庇)*/
	0x5e8a,	/*(床)*/
	0x5e8b,	/*(庋)*/
	0x5e8f,	/*(序)*/
	0x5e90,	/*(庐)*/
	0x5e91,	/*(庑)*/
	0x5e93,	/*(库)*/
	0x5e94,	/*(应)*/
	0x5e95,	/*(底)*/
	0x5e96,	/*(庖)*/
	0x5e97,	/*(店)*/
	0x5e99,	/*(庙)*/
	0x5e9a,	/*(庚)*/
	0x5e9c,	/*(府)*/
	0x5e9e,	/*(庞)*/
	0x5e9f,	/*(废)*/
	0x5ea0,	/*(庠)*/
	0x5ea5,	/*(庥)*/
	0x5ea6,	/*(度)*/
	0x5ea7,	/*(座)*/
	0x5ead,	/*(庭)*/
	0x5eb3,	/*(庳)*/
	0x5eb5,	/*(庵)*/
	0x5eb6,	/*(庶)*/
	0x5eb7,	/*(康)*/
	0x5eb8,	/*(庸)*/
	0x5eb9,	/*(庹)*/
	0x5ebe,	/*(庾)*/
	0x5ec9,	/*(廉)*/
	0x5eca,	/*(廊)*/
	0x5ed1,	/*(廑)*/
	0x5ed2,	/*(廒)*/
	0x5ed3,	/*(廓)*/
	0x5ed6,	/*(廖)*/
	0x5edb,	/*(廛)*/
	0x5ee8,	/*(廨)*/
	0x5eea,	/*(廪)*/
	0x5ef4,	/*(廴)*/
	0x5ef6,	/*(延)*/
	0x5ef7,	/*(廷)*/
	0x5efa,	/*(建)*/
	0x5efe,	/*(廾)*/
	0x5eff,	/*(廿)*/
	0x5f00,	/*(开)*/
	0x5f01,	/*(弁)*/
	0x5f02,	/*(异)*/
	0x5f03,	/*(弃)*/
	0x5f04,	/*(弄)*/
	0x5f08,	/*(弈)*/
	0x5f0a,	/*(弊)*/
	0x5f0b,	/*(弋)*/
	0x5f0f,	/*(式)*/
	0x5f11,	/*(弑)*/
	0x5f13,	/*(弓)*/
	0x5f15,	/*(引)*/
	0x5f17,	/*(弗)*/
	0x5f18,	/*(弘)*/
	0x5f1b,	/*(弛)*/
	0x5f1f,	/*(弟)*/
	0x5f20,	/*(张)*/
	0x5f25,	/*(弥)*/
	0x5f26,	/*(弦)*/
	0x5f27,	/*(弧)*/
	0x5f29,	/*(弩)*/
	0x5f2a,	/*(弪)*/
	0x5f2d,	/*(弭)*/
	0x5f2f,	/*(弯)*/
	0x5f31,	/*(弱)*/
	0x5f39,	/*(弹)*/
	0x5f3a,	/*(强)*/
	0x5f3c,	/*(弼)*/
	0x5f40,	/*(彀)*/
	0x5f50,	/*(彐)*/
	0x5f52,	/*(归)*/
	0x5f53,	/*(当)*/
	0x5f55,	/*(录)*/
	0x5f56,	/*(彖)*/
	0x5f57,	/*(彗)*/
	0x5f58,	/*(彘)*/
	0x5f5d,	/*(彝)*/
	0x5f61,	/*(彡)*/
	0x5f62,	/*(形)*/
	0x5f64,	/*(彤)*/
	0x5f66,	/*(彦)*/
	0x5f69,	/*(彩)*/
	0x5f6a,	/*(彪)*/
	0x5f6c,	/*(彬)*/
	0x5f6d,	/*(彭)*/
	0x5f70,	/*(彰)*/
	0x5f71,	/*(影)*/
	0x5f73,	/*(彳)*/
	0x5f77,	/*(彷)*/
	0x5f79,	/*(役)*/
	0x5f7b,	/*(彻)*/
	0x5f7c,	/*(彼)*/
	0x5f80,	/*(往)*/
	0x5f81,	/*(征)*/
	0x5f82,	/*(徂)*/
	0x5f84,	/*(径)*/
	0x5f85,	/*(待)*/
	0x5f87,	/*(徇)*/
	0x5f88,	/*(很)*/
	0x5f89,	/*(徉)*/
	0x5f8a,	/*(徊)*/
	0x5f8b,	/*(律)*/
	0x5f8c,	/*(後)*/
	0x5f90,	/*(徐)*/
	0x5f92,	/*(徒)*/
	0x5f95,	/*(徕)*/
	0x5f97,	/*(得)*/
	0x5f98,	/*(徘)*/
	0x5f99,	/*(徙)*/
	0x5f9c,	/*(徜)*/
	0x5fa1,	/*(御)*/
	0x5fa8,	/*(徨)*/
	0x5faa,	/*(循)*/
	0x5fad,	/*(徭)*/
	0x5fae,	/*(微)*/
	0x5fb5,	/*(徵)*/
	0x5fb7,	/*(德)*/
	0x5fbc,	/*(徼)*/
	0x5fbd,	/*(徽)*/
	0x5fc3,	/*(心)*/
	0x5fc4,	/*(忄)*/
	0x5fc5,	/*(必)*/
	0x5fc6,	/*(忆)*/
	0x5fc9,	/*(忉)*/
	0x5fcc,	/*(忌)*/
	0x5fcd,	/*(忍)*/
	0x5fcf,	/*(忏)*/
	0x5fd0,	/*(忐)*/
	0x5fd1,	/*(忑)*/
	0x5fd2,	/*(忒)*/
	0x5fd6,	/*(忖)*/
	0x5fd7,	/*(志)*/
	0x5fd8,	/*(忘)*/
	0x5fd9,	/*(忙)*/
	0x5fdd,	/*(忝)*/
	0x5fe0,	/*(忠)*/
	0x5fe1,	/*(忡)*/
	0x5fe4,	/*(忤)*/
	0x5fe7,	/*(忧)*/
	0x5fea,	/*(忪)*/
	0x5feb,	/*(快)*/
	0x5fed,	/*(忭)*/
	0x5fee,	/*(忮)*/
	0x5ff1,	/*(忱)*/
	0x5ff5,	/*(念)*/
	0x5ff8,	/*(忸)*/
	0x5ffb,	/*(忻)*/
	0x5ffd,	/*(忽)*/
	0x5ffe,	/*(忾)*/
	0x5fff,	/*(忿)*/
	0x6000,	/*(怀)*/
	0x6001,	/*(态)*/
	0x6002,	/*(怂)*/
	0x6003,	/*(怃)*/
	0x6004,	/*(怄)*/
	0x6005,	/*(怅)*/
	0x6006,	/*(怆)*/
	0x600a,	/*(怊)*/
	0x600d,	/*(怍)*/
	0x600e,	/*(怎)*/
	0x600f,	/*(怏)*/
	0x6012,	/*(怒)*/
	0x6014,	/*(怔)*/
	0x6015,	/*(怕)*/
	0x6016,	/*(怖)*/
	0x6019,	/*(怙)*/
	0x601b,	/*(怛)*/
	0x601c,	/*(怜)*/
	0x601d,	/*(思)*/
	0x6020,	/*(怠)*/
	0x6021,	/*(怡)*/
	0x6025,	/*(急)*/
	0x6026,	/*(怦)*/
	0x6027,	/*(性)*/
	0x6028,	/*(怨)*/
	0x6029,	/*(怩)*/
	0x602a,	/*(怪)*/
	0x602b,	/*(怫)*/
	0x602f,	/*(怯)*/
	0x6035,	/*(怵)*/
	0x603b,	/*(总)*/
	0x603c,	/*(怼)*/
	0x603f,	/*(怿)*/
	0x6041,	/*(恁)*/
	0x6042,	/*(恂)*/
	0x6043,	/*(恃)*/
	0x604b,	/*(恋)*/
	0x604d,	/*(恍)*/
	0x6050,	/*(恐)*/
	0x6052,	/*(恒)*/
	0x6055,	/*(恕)*/
	0x6059,	/*(恙)*/
	0x605a,	/*(恚)*/
	0x605d,	/*(恝)*/
	0x6062,	/*(恢)*/
	0x6063,	/*(恣)*/
	0x6064,	/*(恤)*/
	0x6067,	/*(恧)*/
	0x6068,	/*(恨)*/
	0x6069,	/*(恩)*/
	0x606a,	/*(恪)*/
	0x606b,	/*(恫)*/
	0x606c,	/*(恬)*/
	0x606d,	/*(恭)*/
	0x606f,	/*(息)*/
	0x6070,	/*(恰)*/
	0x6073,	/*(恳)*/
	0x6076,	/*(恶)*/
	0x6078,	/*(恸)*/
	0x6079,	/*(恹)*/
	0x607a,	/*(恺)*/
	0x607b,	/*(恻)*/
	0x607c,	/*(恼)*/
	0x607d,	/*(恽)*/
	0x607f,	/*(恿)*/
	0x6083,	/*(悃)*/
	0x6084,	/*(悄)*/
	0x6089,	/*(悉)*/
	0x608c,	/*(悌)*/
	0x608d,	/*(悍)*/
	0x6092,	/*(悒)*/
	0x6094,	/*(悔)*/
	0x6096,	/*(悖)*/
	0x609a,	/*(悚)*/
	0x609b,	/*(悛)*/
	0x609d,	/*(悝)*/
	0x609f,	/*(悟)*/
	0x60a0,	/*(悠)*/
	0x60a3,	/*(患)*/
	0x60a6,	/*(悦)*/
	0x60a8,	/*(您)*/
	0x60ab,	/*(悫)*/
	0x60ac,	/*(悬)*/
	0x60ad,	/*(悭)*/
	0x60af,	/*(悯)*/
	0x60b1,	/*(悱)*/
	0x60b2,	/*(悲)*/
	0x60b4,	/*(悴)*/
	0x60b8,	/*(悸)*/
	0x60bb,	/*(悻)*/
	0x60bc,	/*(悼)*/
	0x60c5,	/*(情)*/
	0x60c6,	/*(惆)*/
	0x60ca,	/*(惊)*/
	0x60cb,	/*(惋)*/
	0x60d1,	/*(惑)*/
	0x60d5,	/*(惕)*/
	0x60d8,	/*(惘)*/
	0x60da,	/*(惚)*/
	0x60dc,	/*(惜)*/
	0x60dd,	/*(惝)*/
	0x60df,	/*(惟)*/
	0x60e0,	/*(惠)*/
	0x60e6,	/*(惦)*/
	0x60e7,	/*(惧)*/
	0x60e8,	/*(惨)*/
	0x60e9,	/*(惩)*/
	0x60eb,	/*(惫)*/
	0x60ec,	/*(惬)*/
	0x60ed,	/*(惭)*/
	0x60ee,	/*(惮)*/
	0x60ef,	/*(惯)*/
	0x60f0,	/*(惰)*/
	0x60f3,	/*(想)*/
	0x60f4,	/*(惴)*/
	0x60f6,	/*(惶)*/
	0x60f9,	/*(惹)*/
	0x60fa,	/*(惺)*/
	0x6100,	/*(愀)*/
	0x6101,	/*(愁)*/
	0x6106,	/*(愆)*/
	0x6108,	/*(愈)*/
	0x6109,	/*(愉)*/
	0x610d,	/*(愍)*/
	0x610e,	/*(愎)*/
	0x610f,	/*(意)*/
	0x6115,	/*(愕)*/
	0x611a,	/*(愚)*/
	0x611f,	/*(感)*/
	0x6120,	/*(愠)*/
	0x6123,	/*(愣)*/
	0x6124,	/*(愤)*/
	0x6126,	/*(愦)*/
	0x6127,	/*(愧)*/
	0x612b,	/*(愫)*/
	0x613f,	/*(愿)*/
	0x6148,	/*(慈)*/
	0x614a,	/*(慊)*/
	0x614c,	/*(慌)*/
	0x614e,	/*(慎)*/
	0x6151,	/*(慑)*/
	0x6155,	/*(慕)*/
	0x615d,	/*(慝)*/
	0x6162,	/*(慢)*/
	0x6167,	/*(慧)*/
	0x6168,	/*(慨)*/
	0x6170,	/*(慰)*/
	0x6175,	/*(慵)*/
	0x6177,	/*(慷)*/
	0x618b,	/*(憋)*/
	0x618e,	/*(憎)*/
	0x6194,	/*(憔)*/
	0x619d,	/*(憝)*/
	0x61a7,	/*(憧)*/
	0x61a8,	/*(憨)*/
	0x61a9,	/*(憩)*/
	0x61ac,	/*(憬)*/
	0x61b7,	/*(憷)*/
	0x61be,	/*(憾)*/
	0x61c2,	/*(懂)*/
	0x61c8,	/*(懈)*/
	0x61ca,	/*(懊)*/
	0x61cb,	/*(懋)*/
	0x61d1,	/*(懑)*/
	0x61d2,	/*(懒)*/
	0x61d4,	/*(懔)*/
	0x61e6,	/*(懦)*/
	0x61f5,	/*(懵)*/
	0x61ff,	/*(懿)*/
	0x6206,	/*(戆)*/
	0x6208,	/*(戈)*/
	0x620a,	/*(戊)*/
	0x620b,	/*(戋)*/
	0x620c,	/*(戌)*/
	0x620d,	/*(戍)*/
	0x620e,	/*(戎)*/
	0x620f,	/*(戏)*/
	0x6210,	/*(成)*/
	0x6211,	/*(我)*/
	0x6212,	/*(戒)*/
	0x6215,	/*(戕)*/
	0x6216,	/*(或)*/
	0x6217,	/*(戗)*/
	0x6218,	/*(战)*/
	0x621a,	/*(戚)*/
	0x621b,	/*(戛)*/
	0x621f,	/*(戟)*/
	0x6221,	/*(戡)*/
	0x6222,	/*(戢)*/
	0x6224,	/*(戤)*/
	0x6225,	/*(戥)*/
	0x622a,	/*(截)*/
	0x622c,	/*(戬)*/
	0x622e,	/*(戮)*/
	0x6233,	/*(戳)*/
	0x6234,	/*(戴)*/
	0x6237,	/*(户)*/
	0x623d,	/*(戽)*/
	0x623e,	/*(戾)*/
	0x623f,	/*(房)*/
	0x6240,	/*(所)*/
	0x6241,	/*(扁)*/
	0x6243,	/*(扃)*/
	0x6247,	/*(扇)*/
	0x6248,	/*(扈)*/
	0x6249,	/*(扉)*/
	0x624b,	/*(手)*/
	0x624c,	/*(扌)*/
	0x624d,	/*(才)*/
	0x624e,	/*(扎)*/
	0x6251,	/*(扑)*/
	0x6252,	/*(扒)*/
	0x6253,	/*(打)*/
	0x6254,	/*(扔)*/
	0x6258,	/*(托)*/
	0x625b,	/*(扛)*/
	0x6263,	/*(扣)*/
	0x6266,	/*(扦)*/
	0x6267,	/*(执)*/
	0x6269,	/*(扩)*/
	0x626a,	/*(扪)*/
	0x626b,	/*(扫)*/
	0x626c,	/*(扬)*/
	0x626d,	/*(扭)*/
	0x626e,	/*(扮)*/
	0x626f,	/*(扯)*/
	0x6270,	/*(扰)*/
	0x6273,	/*(扳)*/
	0x6276,	/*(扶)*/
	0x6279,	/*(批)*/
	0x627c,	/*(扼)*/
	0x627e,	/*(找)*/
	0x627f,	/*(承)*/
	0x6280,	/*(技)*/
	0x6284,	/*(抄)*/
	0x6289,	/*(抉)*/
	0x628a,	/*(把)*/
	0x6291,	/*(抑)*/
	0x6292,	/*(抒)*/
	0x6293,	/*(抓)*/
	0x6295,	/*(投)*/
	0x6296,	/*(抖)*/
	0x6297,	/*(抗)*/
	0x6298,	/*(折)*/
	0x629a,	/*(抚)*/
	0x629b,	/*(抛)*/
	0x629f,	/*(抟)*/
	0x62a0,	/*(抠)*/
	0x62a1,	/*(抡)*/
	0x62a2,	/*(抢)*/
	0x62a4,	/*(护)*/
	0x62a5,	/*(报)*/
	0x62a8,	/*(抨)*/
	0x62ab,	/*(披)*/
	0x62ac,	/*(抬)*/
	0x62b1,	/*(抱)*/
	0x62b5,	/*(抵)*/
	0x62b9,	/*(抹)*/
	0x62bb,	/*(抻)*/
	0x62bc,	/*(押)*/
	0x62bd,	/*(抽)*/
	0x62bf,	/*(抿)*/
	0x62c2,	/*(拂)*/
	0x62c4,	/*(拄)*/
	0x62c5,	/*(担)*/
	0x62c6,	/*(拆)*/
	0x62c7,	/*(拇)*/
	0x62c8,	/*(拈)*/
	0x62c9,	/*(拉)*/
	0x62ca,	/*(拊)*/
	0x62cc,	/*(拌)*/
	0x62cd,	/*(拍)*/
	0x62ce,	/*(拎)*/
	0x62d0,	/*(拐)*/
	0x62d2,	/*(拒)*/
	0x62d3,	/*(拓)*/
	0x62d4,	/*(拔)*/
	0x62d6,	/*(拖)*/
	0x62d7,	/*(拗)*/
	0x62d8,	/*(拘)*/
	0x62d9,	/*(拙)*/
	0x62da,	/*(拚)*/
	0x62db,	/*(招)*/
	0x62dc,	/*(拜)*/
	0x62df,	/*(拟)*/
	0x62e2,	/*(拢)*/
	0x62e3,	/*(拣)*/
	0x62e5,	/*(拥)*/
	0x62e6,	/*(拦)*/
	0x62e7,	/*(拧)*/
	0x62e8,	/*(拨)*/
	0x62e9,	/*(择)*/
	0x62ec,	/*(括)*/
	0x62ed,	/*(拭)*/
	0x62ee,	/*(拮)*/
	0x62ef,	/*(拯)*/
	0x62f1,	/*(拱)*/
	0x62f3,	/*(拳)*/
	0x62f4,	/*(拴)*/
	0x62f6,	/*(拶)*/
	0x62f7,	/*(拷)*/
	0x62fc,	/*(拼)*/
	0x62fd,	/*(拽)*/
	0x62fe,	/*(拾)*/
	0x62ff,	/*(拿)*/
	0x6301,	/*(持)*/
	0x6302,	/*(挂)*/
	0x6307,	/*(指)*/
	0x6308,	/*(挈)*/
	0x6309,	/*(按)*/
	0x630e,	/*(挎)*/
	0x6311,	/*(挑)*/
	0x6316,	/*(挖)*/
	0x631a,	/*(挚)*/
	0x631b,	/*(挛)*/
	0x631d,	/*(挝)*/
	0x631e,	/*(挞)*/
	0x631f,	/*(挟)*/
	0x6320,	/*(挠)*/
	0x6321,	/*(挡)*/
	0x6322,	/*(挢)*/
	0x6323,	/*(挣)*/
	0x6324,	/*(挤)*/
	0x6325,	/*(挥)*/
	0x6328,	/*(挨)*/
	0x632a,	/*(挪)*/
	0x632b,	/*(挫)*/
	0x632f,	/*(振)*/
	0x6332,	/*(挲)*/
	0x6339,	/*(挹)*/
	0x633a,	/*(挺)*/
	0x633d,	/*(挽)*/
	0x6342,	/*(捂)*/
	0x6343,	/*(捃)*/
	0x6345,	/*(捅)*/
	0x6346,	/*(捆)*/
	0x6349,	/*(捉)*/
	0x634b,	/*(捋)*/
	0x634c,	/*(捌)*/
	0x634d,	/*(捍)*/
	0x634e,	/*(捎)*/
	0x634f,	/*(捏)*/
	0x6350,	/*(捐)*/
	0x6355,	/*(捕)*/
	0x635e,	/*(捞)*/
	0x635f,	/*(损)*/
	0x6361,	/*(捡)*/
	0x6362,	/*(换)*/
	0x6363,	/*(捣)*/
	0x6367,	/*(捧)*/
	0x6369,	/*(捩)*/
	0x636d,	/*(捭)*/
	0x636e,	/*(据)*/
	0x6371,	/*(捱)*/
	0x6376,	/*(捶)*/
	0x6377,	/*(捷)*/
	0x637a,	/*(捺)*/
	0x637b,	/*(捻)*/
	0x6380,	/*(掀)*/
	0x6382,	/*(掂)*/
	0x6387,	/*(掇)*/
	0x6388,	/*(授)*/
	0x6389,	/*(掉)*/
	0x638a,	/*(掊)*/
	0x638c,	/*(掌)*/
	0x638e,	/*(掎)*/
	0x638f,	/*(掏)*/
	0x6390,	/*(掐)*/
	0x6392,	/*(排)*/
	0x6396,	/*(掖)*/
	0x6398,	/*(掘)*/
	0x63a0,	/*(掠)*/
	0x63a2,	/*(探)*/
	0x63a3,	/*(掣)*/
	0x63a5,	/*(接)*/
	0x63a7,	/*(控)*/
	0x63a8,	/*(推)*/
	0x63a9,	/*(掩)*/
	0x63aa,	/*(措)*/
	0x63ac,	/*(掬)*/
	0x63ad,	/*(掭)*/
	0x63ae,	/*(掮)*/
	0x63b0,	/*(掰)*/
	0x63b3,	/*(掳)*/
	0x63b4,	/*(掴)*/
	0x63b7,	/*(掷)*/
	0x63b8,	/*(掸)*/
	0x63ba,	/*(掺)*/
	0x63bc,	/*(掼)*/
	0x63be,	/*(掾)*/
	0x63c4,	/*(揄)*/
	0x63c6,	/*(揆)*/
	0x63c9,	/*(揉)*/
	0x63cd,	/*(揍)*/
	0x63ce,	/*(揎)*/
	0x63cf,	/*(描)*/
	0x63d0,	/*(提)*/
	0x63d2,	/*(插)*/
	0x63d6,	/*(揖)*/
	0x63de,	/*(揞)*/
	0x63e0,	/*(揠)*/
	0x63e1,	/*(握)*/
	0x63e3,	/*(揣)*/
	0x63e9,	/*(揩)*/
	0x63ea,	/*(揪)*/
	0x63ed,	/*(揭)*/
	0x63f2,	/*(揲)*/
	0x63f4,	/*(援)*/
	0x63f6,	/*(揶)*/
	0x63f8,	/*(揸)*/
	0x63fd,	/*(揽)*/
	0x63ff,	/*(揿)*/
	0x6400,	/*(搀)*/
	0x6401,	/*(搁)*/
	0x6402,	/*(搂)*/
	0x6405,	/*(搅)*/
	0x640b,	/*(搋)*/
	0x640c,	/*(搌)*/
	0x640f,	/*(搏)*/
	0x6410,	/*(搐)*/
	0x6413,	/*(搓)*/
	0x6414,	/*(搔)*/
	0x641b,	/*(搛)*/
	0x641c,	/*(搜)*/
	0x641e,	/*(搞)*/
	0x6420,	/*(搠)*/
	0x6421,	/*(搡)*/
	0x6426,	/*(搦)*/
	0x642a,	/*(搪)*/
	0x642c,	/*(搬)*/
	0x642d,	/*(搭)*/
	0x6434,	/*(搴)*/
	0x643a,	/*(携)*/
	0x643d,	/*(搽)*/
	0x643f,	/*(搿)*/
	0x6441,	/*(摁)*/
	0x6444,	/*(摄)*/
	0x6445,	/*(摅)*/
	0x6446,	/*(摆)*/
	0x6447,	/*(摇)*/
	0x6448,	/*(摈)*/
	0x644a,	/*(摊)*/
	0x6452,	/*(摒)*/
	0x6454,	/*(摔)*/
	0x6458,	/*(摘)*/
	0x645e,	/*(摞)*/
	0x6467,	/*(摧)*/
	0x6469,	/*(摩)*/
	0x646d,	/*(摭)*/
	0x6478,	/*(摸)*/
	0x6479,	/*(摹)*/
	0x647a,	/*(摺)*/
	0x6482,	/*(撂)*/
	0x6484,	/*(撄)*/
	0x6485,	/*(撅)*/
	0x6487,	/*(撇)*/
	0x6491,	/*(撑)*/
	0x6492,	/*(撒)*/
	0x6495,	/*(撕)*/
	0x6496,	/*(撖)*/
	0x6499,	/*(撙)*/
	0x649e,	/*(撞)*/
	0x64a4,	/*(撤)*/
	0x64a9,	/*(撩)*/
	0x64ac,	/*(撬)*/
	0x64ad,	/*(播)*/
	0x64ae,	/*(撮)*/
	0x64b0,	/*(撰)*/
	0x64b5,	/*(撵)*/
	0x64b7,	/*(撷)*/
	0x64b8,	/*(撸)*/
	0x64ba,	/*(撺)*/
	0x64bc,	/*(撼)*/
	0x64c0,	/*(擀)*/
	0x64c2,	/*(擂)*/
	0x64c5,	/*(擅)*/
	0x64cd,	/*(操)*/
	0x64ce,	/*(擎)*/
	0x64d0,	/*(擐)*/
	0x64d2,	/*(擒)*/
	0x64d7,	/*(擗)*/
	0x64d8,	/*(擘)*/
	0x64de,	/*(擞)*/
	0x64e2,	/*(擢)*/
	0x64e4,	/*(擤)*/
	0x64e6,	/*(擦)*/
	0x6500,	/*(攀)*/
	0x6509,	/*(攉)*/
	0x6512,	/*(攒)*/
	0x6518,	/*(攘)*/
	0x6525,	/*(攥)*/
	0x652b,	/*(攫)*/
	0x652e,	/*(攮)*/
	0x652f,	/*(支)*/
	0x6534,	/*(攴)*/
	0x6535,	/*(攵)*/
	0x6536,	/*(收)*/
	0x6538,	/*(攸)*/
	0x6539,	/*(改)*/
	0x653b,	/*(攻)*/
	0x653e,	/*(放)*/
	0x653f,	/*(政)*/
	0x6545,	/*(故)*/
	0x6548,	/*(效)*/
	0x6549,	/*(敉)*/
	0x654c,	/*(敌)*/
	0x654f,	/*(敏)*/
	0x6551,	/*(救)*/
	0x6555,	/*(敕)*/
	0x6556,	/*(敖)*/
	0x6559,	/*(教)*/
	0x655b,	/*(敛)*/
	0x655d,	/*(敝)*/
	0x655e,	/*(敞)*/
	0x6562,	/*(敢)*/
	0x6563,	/*(散)*/
	0x6566,	/*(敦)*/
	0x656b,	/*(敫)*/
	0x656c,	/*(敬)*/
	0x6570,	/*(数)*/
	0x6572,	/*(敲)*/
	0x6574,	/*(整)*/
	0x6577,	/*(敷)*/
	0x6587,	/*(文)*/
	0x658b,	/*(斋)*/
	0x658c,	/*(斌)*/
	0x6590,	/*(斐)*/
	0x6591,	/*(斑)*/
	0x6593,	/*(斓)*/
	0x6597,	/*(斗)*/
	0x6599,	/*(料)*/
	0x659b,	/*(斛)*/
	0x659c,	/*(斜)*/
	0x659f,	/*(斟)*/
	0x65a1,	/*(斡)*/
	0x65a4,	/*(斤)*/
	0x65a5,	/*(斥)*/
	0x65a7,	/*(斧)*/
	0x65a9,	/*(斩)*/
	0x65ab,	/*(斫)*/
	0x65ad,	/*(断)*/
	0x65af,	/*(斯)*/
	0x65b0,	/*(新)*/
	0x65b9,	/*(方)*/
	0x65bc,	/*(於)*/
	0x65bd,	/*(施)*/
	0x65c1,	/*(旁)*/
	0x65c3,	/*(旃)*/
	0x65c4,	/*(旄)*/
	0x65c5,	/*(旅)*/
	0x65c6,	/*(旆)*/
	0x65cb,	/*(旋)*/
	0x65cc,	/*(旌)*/
	0x65ce,	/*(旎)*/
	0x65cf,	/*(族)*/
	0x65d2,	/*(旒)*/
	0x65d6,	/*(旖)*/
	0x65d7,	/*(旗)*/
	0x65e0,	/*(无)*/
	0x65e2,	/*(既)*/
	0x65e5,	/*(日)*/
	0x65e6,	/*(旦)*/
	0x65e7,	/*(旧)*/
	0x65e8,	/*(旨)*/
	0x65e9,	/*(早)*/
	0x65ec,	/*(旬)*/
	0x65ed,	/*(旭)*/
	0x65ee,	/*(旮)*/
	0x65ef,	/*(旯)*/
	0x65f0,	/*(旰)*/
	0x65f1,	/*(旱)*/
	0x65f6,	/*(时)*/
	0x65f7,	/*(旷)*/
	0x65fa,	/*(旺)*/
	0x6600,	/*(昀)*/
	0x6602,	/*(昂)*/
	0x6603,	/*(昃)*/
	0x6606,	/*(昆)*/
	0x660a,	/*(昊)*/
	0x660c,	/*(昌)*/
	0x660e,	/*(明)*/
	0x660f,	/*(昏)*/
	0x6613,	/*(易)*/
	0x6614,	/*(昔)*/
	0x6615,	/*(昕)*/
	0x6619,	/*(昙)*/
	0x661d,	/*(昝)*/
	0x661f,	/*(星)*/
	0x6620,	/*(映)*/
	0x6625,	/*(春)*/
	0x6627,	/*(昧)*/
	0x6628,	/*(昨)*/
	0x662d,	/*(昭)*/
	0x662f,	/*(是)*/
	0x6631,	/*(昱)*/
	0x6634,	/*(昴)*/
	0x6635,	/*(昵)*/
	0x6636,	/*(昶)*/
	0x663c,	/*(昼)*/
	0x663e,	/*(显)*/
	0x6641,	/*(晁)*/
	0x6643,	/*(晃)*/
	0x664b,	/*(晋)*/
	0x664c,	/*(晌)*/
	0x664f,	/*(晏)*/
	0x6652,	/*(晒)*/
	0x6653,	/*(晓)*/
	0x6654,	/*(晔)*/
	0x6655,	/*(晕)*/
	0x6656,	/*(晖)*/
	0x6657,	/*(晗)*/
	0x665a,	/*(晚)*/
	0x665f,	/*(晟)*/
	0x6661,	/*(晡)*/
	0x6664,	/*(晤)*/
	0x6666,	/*(晦)*/
	0x6668,	/*(晨)*/
	0x666e,	/*(普)*/
	0x666f,	/*(景)*/
	0x6670,	/*(晰)*/
	0x6674,	/*(晴)*/
	0x6676,	/*(晶)*/
	0x6677,	/*(晷)*/
	0x667a,	/*(智)*/
	0x667e,	/*(晾)*/
	0x6682,	/*(暂)*/
	0x6684,	/*(暄)*/
	0x6687,	/*(暇)*/
	0x668c,	/*(暌)*/
	0x6691,	/*(暑)*/
	0x6696,	/*(暖)*/
	0x6697,	/*(暗)*/
	0x669d,	/*(暝)*/
	0x66a7,	/*(暧)*/
	0x66a8,	/*(暨)*/
	0x66ae,	/*(暮)*/
	0x66b4,	/*(暴)*/
	0x66b9,	/*(暹)*/
	0x66be,	/*(暾)*/
	0x66d9,	/*(曙)*/
	0x66db,	/*(曛)*/
	0x66dc,	/*(曜)*/
	0x66dd,	/*(曝)*/
	0x66e6,	/*(曦)*/
	0x66e9,	/*(曩)*/
	0x66f0,	/*(曰)*/
	0x66f2,	/*(曲)*/
	0x66f3,	/*(曳)*/
	0x66f4,	/*(更)*/
	0x66f7,	/*(曷)*/
	0x66f9,	/*(曹)*/
	0x66fc,	/*(曼)*/
	0x66fe,	/*(曾)*/
	0x66ff,	/*(替)*/
	0x6700,	/*(最)*/
	0x6708,	/*(月)*/
	0x6709,	/*(有)*/
	0x670a,	/*(朊)*/
	0x670b,	/*(朋)*/
	0x670d,	/*(服)*/
	0x6710,	/*(朐)*/
	0x6714,	/*(朔)*/
	0x6715,	/*(朕)*/
	0x6717,	/*(朗)*/
	0x671b,	/*(望)*/
	0x671d,	/*(朝)*/
	0x671f,	/*(期)*/
	0x6726,	/*(朦)*/
	0x6728,	/*(木)*/
	0x672a,	/*(未)*/
	0x672b,	/*(末)*/
	0x672c,	/*(本)*/
	0x672d,	/*(札)*/
	0x672f,	/*(术)*/
	0x6731,	/*(朱)*/
	0x6734,	/*(朴)*/
	0x6735,	/*(朵)*/
	0x673a,	/*(机)*/
	0x673d,	/*(朽)*/
	0x6740,	/*(杀)*/
	0x6742,	/*(杂)*/
	0x6743,	/*(权)*/
	0x6746,	/*(杆)*/
	0x6748,	/*(杈)*/
	0x6749,	/*(杉)*/
	0x674c,	/*(杌)*/
	0x674e,	/*(李)*/
	0x674f,	/*(杏)*/
	0x6750,	/*(材)*/
	0x6751,	/*(村)*/
	0x6753,	/*(杓)*/
	0x6756,	/*(杖)*/
	0x675c,	/*(杜)*/
	0x675e,	/*(杞)*/
	0x675f,	/*(束)*/
	0x6760,	/*(杠)*/
	0x6761,	/*(条)*/
	0x6765,	/*(来)*/
	0x6768,	/*(杨)*/
	0x6769,	/*(杩)*/
	0x676a,	/*(杪)*/
	0x676d,	/*(杭)*/
	0x676f,	/*(杯)*/
	0x6770,	/*(杰)*/
	0x6772,	/*(杲)*/
	0x6773,	/*(杳)*/
	0x6775,	/*(杵)*/
	0x6777,	/*(杷)*/
	0x677c,	/*(杼)*/
	0x677e,	/*(松)*/
	0x677f,	/*(板)*/
	0x6781,	/*(极)*/
	0x6784,	/*(构)*/
	0x6787,	/*(枇)*/
	0x6789,	/*(枉)*/
	0x678b,	/*(枋)*/
	0x6790,	/*(析)*/
	0x6795,	/*(枕)*/
	0x6797,	/*(林)*/
	0x6798,	/*(枘)*/
	0x679a,	/*(枚)*/
	0x679c,	/*(果)*/
	0x679d,	/*(枝)*/
	0x679e,	/*(枞)*/
	0x67a2,	/*(枢)*/
	0x67a3,	/*(枣)*/
	0x67a5,	/*(枥)*/
	0x67a7,	/*(枧)*/
	0x67a8,	/*(枨)*/
	0x67aa,	/*(枪)*/
	0x67ab,	/*(枫)*/
	0x67ad,	/*(枭)*/
	0x67af,	/*(枯)*/
	0x67b0,	/*(枰)*/
	0x67b3,	/*(枳)*/
	0x67b5,	/*(枵)*/
	0x67b6,	/*(架)*/
	0x67b7,	/*(枷)*/
	0x67b8,	/*(枸)*/
	0x67c1,	/*(柁)*/
	0x67c3,	/*(柃)*/
	0x67c4,	/*(柄)*/
	0x67cf,	/*(柏)*/
	0x67d0,	/*(某)*/
	0x67d1,	/*(柑)*/
	0x67d2,	/*(柒)*/
	0x67d3,	/*(染)*/
	0x67d4,	/*(柔)*/
	0x67d8,	/*(柘)*/
	0x67d9,	/*(柙)*/
	0x67da,	/*(柚)*/
	0x67dc,	/*(柜)*/
	0x67dd,	/*(柝)*/
	0x67de,	/*(柞)*/
	0x67e0,	/*(柠)*/
	0x67e2,	/*(柢)*/
	0x67e5,	/*(查)*/
	0x67e9,	/*(柩)*/
	0x67ec,	/*(柬)*/
	0x67ef,	/*(柯)*/
	0x67f0,	/*(柰)*/
	0x67f1,	/*(柱)*/
	0x67f3,	/*(柳)*/
	0x67f4,	/*(柴)*/
	0x67fd,	/*(柽)*/
	0x67ff,	/*(柿)*/
	0x6800,	/*(栀)*/
	0x6805,	/*(栅)*/
	0x6807,	/*(标)*/
	0x6808,	/*(栈)*/
	0x6809,	/*(栉)*/
	0x680a,	/*(栊)*/
	0x680b,	/*(栋)*/
	0x680c,	/*(栌)*/
	0x680e,	/*(栎)*/
	0x680f,	/*(栏)*/
	0x6811,	/*(树)*/
	0x6813,	/*(栓)*/
	0x6816,	/*(栖)*/
	0x6817,	/*(栗)*/
	0x681d,	/*(栝)*/
	0x6821,	/*(校)*/
	0x6829,	/*(栩)*/
	0x682a,	/*(株)*/
	0x6832,	/*(栲)*/
	0x6833,	/*(栳)*/
	0x6837,	/*(样)*/
	0x6838,	/*(核)*/
	0x6839,	/*(根)*/
	0x683c,	/*(格)*/
	0x683d,	/*(栽)*/
	0x683e,	/*(栾)*/
	0x6840,	/*(桀)*/
	0x6841,	/*(桁)*/
	0x6842,	/*(桂)*/
	0x6843,	/*(桃)*/
	0x6844,	/*(桄)*/
	0x6845,	/*(桅)*/
	0x6846,	/*(框)*/
	0x6848,	/*(案)*/
	0x6849,	/*(桉)*/
	0x684a,	/*(桊)*/
	0x684c,	/*(桌)*/
	0x684e,	/*(桎)*/
	0x6850,	/*(桐)*/
	0x6851,	/*(桑)*/
	0x6853,	/*(桓)*/
	0x6854,	/*(桔)*/
	0x6855,	/*(桕)*/
	0x6860,	/*(桠)*/
	0x6861,	/*(桡)*/
	0x6862,	/*(桢)*/
	0x6863,	/*(档)*/
	0x6864,	/*(桤)*/
	0x6865,	/*(桥)*/
	0x6866,	/*(桦)*/
	0x6867,	/*(桧)*/
	0x6868,	/*(桨)*/
	0x6869,	/*(桩)*/
	0x686b,	/*(桫)*/
	0x6874,	/*(桴)*/
	0x6876,	/*(桶)*/
	0x6877,	/*(桷)*/
	0x6881,	/*(梁)*/
	0x6883,	/*(梃)*/
	0x6885,	/*(梅)*/
	0x6886,	/*(梆)*/
	0x688f,	/*(梏)*/
	0x6893,	/*(梓)*/
	0x6897,	/*(梗)*/
	0x68a2,	/*(梢)*/
	0x68a6,	/*(梦)*/
	0x68a7,	/*(梧)*/
	0x68a8,	/*(梨)*/
	0x68ad,	/*(梭)*/
	0x68af,	/*(梯)*/
	0x68b0,	/*(械)*/
	0x68b3,	/*(梳)*/
	0x68b5,	/*(梵)*/
	0x68c0,	/*(检)*/
	0x68c2,	/*(棂)*/
	0x68c9,	/*(棉)*/
	0x68cb,	/*(棋)*/
	0x68cd,	/*(棍)*/
	0x68d2,	/*(棒)*/
	0x68d5,	/*(棕)*/
	0x68d8,	/*(棘)*/
	0x68da,	/*(棚)*/
	0x68e0,	/*(棠)*/
	0x68e3,	/*(棣)*/
	0x68ee,	/*(森)*/
	0x68f0,	/*(棰)*/
	0x68f1,	/*(棱)*/
	0x68f5,	/*(棵)*/
	0x68f9,	/*(棹)*/
	0x68fa,	/*(棺)*/
	0x68fc,	/*(棼)*/
	0x6901,	/*(椁)*/
	0x6905,	/*(椅)*/
	0x690b,	/*(椋)*/
	0x690d,	/*(植)*/
	0x690e,	/*(椎)*/
	0x6910,	/*(椐)*/
	0x6912,	/*(椒)*/
	0x691f,	/*(椟)*/
	0x6920,	/*(椠)*/
	0x6924,	/*(椤)*/
	0x692d,	/*(椭)*/
	0x6930,	/*(椰)*/
	0x6934,	/*(椴)*/
	0x6939,	/*(椹)*/
	0x693d,	/*(椽)*/
	0x693f,	/*(椿)*/
	0x6942,	/*(楂)*/
	0x6954,	/*(楔)*/
	0x6957,	/*(楗)*/
	0x695a,	/*(楚)*/
	0x695d,	/*(楝)*/
	0x695e,	/*(楞)*/
	0x6960,	/*(楠)*/
	0x6963,	/*(楣)*/
	0x6966,	/*(楦)*/
	0x696b,	/*(楫)*/
	0x696e,	/*(楮)*/
	0x6971,	/*(楱)*/
	0x6977,	/*(楷)*/
	0x6978,	/*(楸)*/
	0x6979,	/*(楹)*/
	0x697c,	/*(楼)*/
	0x6980,	/*(榀)*/
	0x6982,	/*(概)*/
	0x6984,	/*(榄)*/
	0x6986,	/*(榆)*/
	0x6987,	/*(榇)*/
	0x6988,	/*(榈)*/
	0x6989,	/*(榉)*/
	0x698d,	/*(榍)*/
	0x6994,	/*(榔)*/
	0x6995,	/*(榕)*/
	0x6998,	/*(榘)*/
	0x699b,	/*(榛)*/
	0x699c,	/*(榜)*/
	0x69a7,	/*(榧)*/
	0x69a8,	/*(榨)*/
	0x69ab,	/*(榫)*/
	0x69ad,	/*(榭)*/
	0x69b1,	/*(榱)*/
	0x69b4,	/*(榴)*/
	0x69b7,	/*(榷)*/
	0x69bb,	/*(榻)*/
	0x69c1,	/*(槁)*/
	0x69ca,	/*(槊)*/
	0x69cc,	/*(槌)*/
	0x69ce,	/*(槎)*/
	0x69d0,	/*(槐)*/
	0x69d4,	/*(槔)*/
	0x69db,	/*(槛)*/
	0x69df,	/*(槟)*/
	0x69e0,	/*(槠)*/
	0x69ed,	/*(槭)*/
	0x69f2,	/*(槲)*/
	0x69fd,	/*(槽)*/
	0x69ff,	/*(槿)*/
	0x6a0a,	/*(樊)*/
	0x6a17,	/*(樗)*/
	0x6a18,	/*(樘)*/
	0x6a1f,	/*(樟)*/
	0x6a21,	/*(模)*/
	0x6a28,	/*(樨)*/
	0x6a2a,	/*(横)*/
	0x6a2f,	/*(樯)*/
	0x6a31,	/*(樱)*/
	0x6a35,	/*(樵)*/
	0x6a3d,	/*(樽)*/
	0x6a3e,	/*(樾)*/
	0x6a44,	/*(橄)*/
	0x6a47,	/*(橇)*/
	0x6a50,	/*(橐)*/
	0x6a58,	/*(橘)*/
	0x6a59,	/*(橙)*/
	0x6a5b,	/*(橛)*/
	0x6a61,	/*(橡)*/
	0x6a65,	/*(橥)*/
	0x6a71,	/*(橱)*/
	0x6a79,	/*(橹)*/
	0x6a7c,	/*(橼)*/
	0x6a80,	/*(檀)*/
	0x6a84,	/*(檄)*/
	0x6a8e,	/*(檎)*/
	0x6a90,	/*(檐)*/
	0x6a91,	/*(檑)*/
	0x6a97,	/*(檗)*/
	0x6aa0,	/*(檠)*/
	0x6aa9,	/*(檩)*/
	0x6aab,	/*(檫)*/
	0x6aac,	/*(檬)*/
	0x6b20,	/*(欠)*/
	0x6b21,	/*(次)*/
	0x6b22,	/*(欢)*/
	0x6b23,	/*(欣)*/
	0x6b24,	/*(欤)*/
	0x6b27,	/*(欧)*/
	0x6b32,	/*(欲)*/
	0x6b37,	/*(欷)*/
	0x6b39,	/*(欹)*/
	0x6b3a,	/*(欺)*/
	0x6b3e,	/*(款)*/
	0x6b43,	/*(歃)*/
	0x6b46,	/*(歆)*/
	0x6b47,	/*(歇)*/
	0x6b49,	/*(歉)*/
	0x6b4c,	/*(歌)*/
	0x6b59,	/*(歙)*/
	0x6b62,	/*(止)*/
	0x6b63,	/*(正)*/
	0x6b64,	/*(此)*/
	0x6b65,	/*(步)*/
	0x6b66,	/*(武)*/
	0x6b67,	/*(歧)*/
	0x6b6a,	/*(歪)*/
	0x6b79,	/*(歹)*/
	0x6b7b,	/*(死)*/
	0x6b7c,	/*(歼)*/
	0x6b81,	/*(殁)*/
	0x6b82,	/*(殂)*/
	0x6b83,	/*(殃)*/
	0x6b84,	/*(殄)*/
	0x6b86,	/*(殆)*/
	0x6b87,	/*(殇)*/
	0x6b89,	/*(殉)*/
	0x6b8a,	/*(殊)*/
	0x6b8b,	/*(残)*/
	0x6b8d,	/*(殍)*/
	0x6b92,	/*(殒)*/
	0x6b93,	/*(殓)*/
	0x6b96,	/*(殖)*/
	0x6b9a,	/*(殚)*/
	0x6b9b,	/*(殛)*/
	0x6ba1,	/*(殡)*/
	0x6baa,	/*(殪)*/
	0x6bb3,	/*(殳)*/
	0x6bb4,	/*(殴)*/
	0x6bb5,	/*(段)*/
	0x6bb7,	/*(殷)*/
	0x6bbf,	/*(殿)*/
	0x6bc1,	/*(毁)*/
	0x6bc2,	/*(毂)*/
	0x6bc5,	/*(毅)*/
	0x6bcb,	/*(毋)*/
	0x6bcd,	/*(母)*/
	0x6bcf,	/*(每)*/
	0x6bd2,	/*(毒)*/
	0x6bd3,	/*(毓)*/
	0x6bd4,	/*(比)*/
	0x6bd5,	/*(毕)*/
	0x6bd6,	/*(毖)*/
	0x6bd7,	/*(毗)*/
	0x6bd9,	/*(毙)*/
	0x6bdb,	/*(毛)*/
	0x6be1,	/*(毡)*/
	0x6bea,	/*(毪)*/
	0x6beb,	/*(毫)*/
	0x6bef,	/*(毯)*/
	0x6bf3,	/*(毳)*/
	0x6bf5,	/*(毵)*/
	0x6bf9,	/*(毹)*/
	0x6bfd,	/*(毽)*/
	0x6c05,	/*(氅)*/
	0x6c06,	/*(氆)*/
	0x6c07,	/*(氇)*/
	0x6c0d,	/*(氍)*/
	0x6c0f,	/*(氏)*/
	0x6c10,	/*(氐)*/
	0x6c11,	/*(民)*/
	0x6c13,	/*(氓)*/
	0x6c14,	/*(气)*/
	0x6c15,	/*(氕)*/
	0x6c16,	/*(氖)*/
	0x6c18,	/*(氘)*/
	0x6c19,	/*(氙)*/
	0x6c1a,	/*(氚)*/
	0x6c1b,	/*(氛)*/
	0x6c1f,	/*(氟)*/
	0x6c21,	/*(氡)*/
	0x6c22,	/*(氢)*/
	0x6c24,	/*(氤)*/
	0x6c26,	/*(氦)*/
	0x6c27,	/*(氧)*/
	0x6c28,	/*(氨)*/
	0x6c29,	/*(氩)*/
	0x6c2a,	/*(氪)*/
	0x6c2e,	/*(氮)*/
	0x6c2f,	/*(氯)*/
	0x6c30,	/*(氰)*/
	0x6c32,	/*(氲)*/
	0x6c34,	/*(水)*/
	0x6c35,	/*(氵)*/
	0x6c38,	/*(永)*/
	0x6c3d,	/*(氽)*/
	0x6c40,	/*(汀)*/
	0x6c41,	/*(汁)*/
	0x6c42,	/*(求)*/
	0x6c46,	/*(汆)*/
	0x6c47,	/*(汇)*/
	0x6c49,	/*(汉)*/
	0x6c4a,	/*(汊)*/
	0x6c50,	/*(汐)*/
	0x6c54,	/*(汔)*/
	0x6c55,	/*(汕)*/
	0x6c57,	/*(汗)*/
	0x6c5b,	/*(汛)*/
	0x6c5c,	/*(汜)*/
	0x6c5d,	/*(汝)*/
	0x6c5e,	/*(汞)*/
	0x6c5f,	/*(江)*/
	0x6c60,	/*(池)*/
	0x6c61,	/*(污)*/
	0x6c64,	/*(汤)*/
	0x6c68,	/*(汨)*/
	0x6c69,	/*(汩)*/
	0x6c6a,	/*(汪)*/
	0x6c70,	/*(汰)*/
	0x6c72,	/*(汲)*/
	0x6c74,	/*(汴)*/
	0x6c76,	/*(汶)*/
	0x6c79,	/*(汹)*/
	0x6c7d,	/*(汽)*/
	0x6c7e,	/*(汾)*/
	0x6c81,	/*(沁)*/
	0x6c82,	/*(沂)*/
	0x6c83,	/*(沃)*/
	0x6c85,	/*(沅)*/
	0x6c86,	/*(沆)*/
	0x6c88,	/*(沈)*/
	0x6c89,	/*(沉)*/
	0x6c8c,	/*(沌)*/
	0x6c8f,	/*(沏)*/
	0x6c90,	/*(沐)*/
	0x6c93,	/*(沓)*/
	0x6c94,	/*(沔)*/
	0x6c99,	/*(沙)*/
	0x6c9b,	/*(沛)*/
	0x6c9f,	/*(沟)*/
	0x6ca1,	/*(没)*/
	0x6ca3,	/*(沣)*/
	0x6ca4,	/*(沤)*/
	0x6ca5,	/*(沥)*/
	0x6ca6,	/*(沦)*/
	0x6ca7,	/*(沧)*/
	0x6ca9,	/*(沩)*/
	0x6caa,	/*(沪)*/
	0x6cab,	/*(沫)*/
	0x6cad,	/*(沭)*/
	0x6cae,	/*(沮)*/
	0x6cb1,	/*(沱)*/
	0x6cb2,	/*(沲)*/
	0x6cb3,	/*(河)*/
	0x6cb8,	/*(沸)*/
	0x6cb9,	/*(油)*/
	0x6cbb,	/*(治)*/
	0x6cbc,	/*(沼)*/
	0x6cbd,	/*(沽)*/
	0x6cbe,	/*(沾)*/
	0x6cbf,	/*(沿)*/
	0x6cc4,	/*(泄)*/
	0x6cc5,	/*(泅)*/
	0x6cc9,	/*(泉)*/
	0x6cca,	/*(泊)*/
	0x6ccc,	/*(泌)*/
	0x6cd0,	/*(泐)*/
	0x6cd3,	/*(泓)*/
	0x6cd4,	/*(泔)*/
	0x6cd5,	/*(法)*/
	0x6cd6,	/*(泖)*/
	0x6cd7,	/*(泗)*/
	0x6cdb,	/*(泛)*/
	0x6cde,	/*(泞)*/
	0x6ce0,	/*(泠)*/
	0x6ce1,	/*(泡)*/
	0x6ce2,	/*(波)*/
	0x6ce3,	/*(泣)*/
	0x6ce5,	/*(泥)*/
	0x6ce8,	/*(注)*/
	0x6cea,	/*(泪)*/
	0x6ceb,	/*(泫)*/
	0x6cee,	/*(泮)*/
	0x6cef,	/*(泯)*/
	0x6cf0,	/*(泰)*/
	0x6cf1,	/*(泱)*/
	0x6cf3,	/*(泳)*/
	0x6cf5,	/*(泵)*/
	0x6cf6,	/*(泶)*/
	0x6cf7,	/*(泷)*/
	0x6cf8,	/*(泸)*/
	0x6cfa,	/*(泺)*/
	0x6cfb,	/*(泻)*/
	0x6cfc,	/*(泼)*/
	0x6cfd,	/*(泽)*/
	0x6cfe,	/*(泾)*/
	0x6d01,	/*(洁)*/
	0x6d04,	/*(洄)*/
	0x6d07,	/*(洇)*/
	0x6d0b,	/*(洋)*/
	0x6d0c,	/*(洌)*/
	0x6d0e,	/*(洎)*/
	0x6d12,	/*(洒)*/
	0x6d17,	/*(洗)*/
	0x6d19,	/*(洙)*/
	0x6d1a,	/*(洚)*/
	0x6d1b,	/*(洛)*/
	0x6d1e,	/*(洞)*/
	0x6d25,	/*(津)*/
	0x6d27,	/*(洧)*/
	0x6d2a,	/*(洪)*/
	0x6d2b,	/*(洫)*/
	0x6d2e,	/*(洮)*/
	0x6d31,	/*(洱)*/
	0x6d32,	/*(洲)*/
	0x6d33,	/*(洳)*/
	0x6d35,	/*(洵)*/
	0x6d39,	/*(洹)*/
	0x6d3b,	/*(活)*/
	0x6d3c,	/*(洼)*/
	0x6d3d,	/*(洽)*/
	0x6d3e,	/*(派)*/
	0x6d41,	/*(流)*/
	0x6d43,	/*(浃)*/
	0x6d45,	/*(浅)*/
	0x6d46,	/*(浆)*/
	0x6d47,	/*(浇)*/
	0x6d48,	/*(浈)*/
	0x6d4a,	/*(浊)*/
	0x6d4b,	/*(测)*/
	0x6d4d,	/*(浍)*/
	0x6d4e,	/*(济)*/
	0x6d4f,	/*(浏)*/
	0x6d51,	/*(浑)*/
	0x6d52,	/*(浒)*/
	0x6d53,	/*(浓)*/
	0x6d54,	/*(浔)*/
	0x6d59,	/*(浙)*/
	0x6d5a,	/*(浚)*/
	0x6d5c,	/*(浜)*/
	0x6d5e,	/*(浞)*/
	0x6d60,	/*(浠)*/
	0x6d63,	/*(浣)*/
	0x6d66,	/*(浦)*/
	0x6d69,	/*(浩)*/
	0x6d6a,	/*(浪)*/
	0x6d6e,	/*(浮)*/
	0x6d6f,	/*(浯)*/
	0x6d74,	/*(浴)*/
	0x6d77,	/*(海)*/
	0x6d78,	/*(浸)*/
	0x6d7c,	/*(浼)*/
	0x6d82,	/*(涂)*/
	0x6d85,	/*(涅)*/
	0x6d88,	/*(消)*/
	0x6d89,	/*(涉)*/
	0x6d8c,	/*(涌)*/
	0x6d8e,	/*(涎)*/
	0x6d91,	/*(涑)*/
	0x6d93,	/*(涓)*/
	0x6d94,	/*(涔)*/
	0x6d95,	/*(涕)*/
	0x6d9b,	/*(涛)*/
	0x6d9d,	/*(涝)*/
	0x6d9e,	/*(涞)*/
	0x6d9f,	/*(涟)*/
	0x6da0,	/*(涠)*/
	0x6da1,	/*(涡)*/
	0x6da3,	/*(涣)*/
	0x6da4,	/*(涤)*/
	0x6da6,	/*(润)*/
	0x6da7,	/*(涧)*/
	0x6da8,	/*(涨)*/
	0x6da9,	/*(涩)*/
	0x6daa,	/*(涪)*/
	0x6dab,	/*(涫)*/
	0x6dae,	/*(涮)*/
	0x6daf,	/*(涯)*/
	0x6db2,	/*(液)*/
	0x6db5,	/*(涵)*/
	0x6db8,	/*(涸)*/
	0x6dbf,	/*(涿)*/
	0x6dc0,	/*(淀)*/
	0x6dc4,	/*(淄)*/
	0x6dc5,	/*(淅)*/
	0x6dc6,	/*(淆)*/
	0x6dc7,	/*(淇)*/
	0x6dcb,	/*(淋)*/
	0x6dcc,	/*(淌)*/
	0x6dd1,	/*(淑)*/
	0x6dd6,	/*(淖)*/
	0x6dd8,	/*(淘)*/
	0x6dd9,	/*(淙)*/
	0x6ddd,	/*(淝)*/
	0x6dde,	/*(淞)*/
	0x6de0,	/*(淠)*/
	0x6de1,	/*(淡)*/
	0x6de4,	/*(淤)*/
	0x6de6,	/*(淦)*/
	0x6deb,	/*(淫)*/
	0x6dec,	/*(淬)*/
	0x6dee,	/*(淮)*/
	0x6df1,	/*(深)*/
	0x6df3,	/*(淳)*/
	0x6df7,	/*(混)*/
	0x6df9,	/*(淹)*/
	0x6dfb,	/*(添)*/
	0x6dfc,	/*(淼)*/
	0x6e05,	/*(清)*/
	0x6e0a,	/*(渊)*/
	0x6e0c,	/*(渌)*/
	0x6e0d,	/*(渍)*/
	0x6e0e,	/*(渎)*/
	0x6e10,	/*(渐)*/
	0x6e11,	/*(渑)*/
	0x6e14,	/*(渔)*/
	0x6e16,	/*(渖)*/
	0x6e17,	/*(渗)*/
	0x6e1a,	/*(渚)*/
	0x6e1d,	/*(渝)*/
	0x6e20,	/*(渠)*/
	0x6e21,	/*(渡)*/
	0x6e23,	/*(渣)*/
	0x6e24,	/*(渤)*/
	0x6e25,	/*(渥)*/
	0x6e29,	/*(温)*/
	0x6e2b,	/*(渫)*/
	0x6e2d,	/*(渭)*/
	0x6e2f,	/*(港)*/
	0x6e32,	/*(渲)*/
	0x6e34,	/*(渴)*/
	0x6e38,	/*(游)*/
	0x6e3a,	/*(渺)*/
	0x6e43,	/*(湃)*/
	0x6e44,	/*(湄)*/
	0x6e4d,	/*(湍)*/
	0x6e4e,	/*(湎)*/
	0x6e53,	/*(湓)*/
	0x6e54,	/*(湔)*/
	0x6e56,	/*(湖)*/
	0x6e58,	/*(湘)*/
	0x6e5b,	/*(湛)*/
	0x6e5f,	/*(湟)*/
	0x6e6b,	/*(湫)*/
	0x6e6e,	/*(湮)*/
	0x6e7e,	/*(湾)*/
	0x6e7f,	/*(湿)*/
	0x6e83,	/*(溃)*/
	0x6e85,	/*(溅)*/
	0x6e86,	/*(溆)*/
	0x6e89,	/*(溉)*/
	0x6e8f,	/*(溏)*/
	0x6e90,	/*(源)*/
	0x6e98,	/*(溘)*/
	0x6e9c,	/*(溜)*/
	0x6e9f,	/*(溟)*/
	0x6ea2,	/*(溢)*/
	0x6ea5,	/*(溥)*/
	0x6ea7,	/*(溧)*/
	0x6eaa,	/*(溪)*/
	0x6eaf,	/*(溯)*/
	0x6eb1,	/*(溱)*/
	0x6eb2,	/*(溲)*/
	0x6eb4,	/*(溴)*/
	0x6eb6,	/*(溶)*/
	0x6eb7,	/*(溷)*/
	0x6eba,	/*(溺)*/
	0x6ebb,	/*(溻)*/
	0x6ebd,	/*(溽)*/
	0x6ec1,	/*(滁)*/
	0x6ec2,	/*(滂)*/
	0x6ec7,	/*(滇)*/
	0x6ecb,	/*(滋)*/
	0x6ecf,	/*(滏)*/
	0x6ed1,	/*(滑)*/
	0x6ed3,	/*(滓)*/
	0x6ed4,	/*(滔)*/
	0x6ed5,	/*(滕)*/
	0x6ed7,	/*(滗)*/
	0x6eda,	/*(滚)*/
	0x6ede,	/*(滞)*/
	0x6edf,	/*(滟)*/
	0x6ee0,	/*(滠)*/
	0x6ee1,	/*(满)*/
	0x6ee2,	/*(滢)*/
	0x6ee4,	/*(滤)*/
	0x6ee5,	/*(滥)*/
	0x6ee6,	/*(滦)*/
	0x6ee8,	/*(滨)*/
	0x6ee9,	/*(滩)*/
	0x6ef4,	/*(滴)*/
	0x6ef9,	/*(滹)*/
	0x6f02,	/*(漂)*/
	0x6f06,	/*(漆)*/
	0x6f09,	/*(漉)*/
	0x6f0f,	/*(漏)*/
	0x6f13,	/*(漓)*/
	0x6f14,	/*(演)*/
	0x6f15,	/*(漕)*/
	0x6f20,	/*(漠)*/
	0x6f24,	/*(漤)*/
	0x6f29,	/*(漩)*/
	0x6f2a,	/*(漪)*/
	0x6f2b,	/*(漫)*/
	0x6f2d,	/*(漭)*/
	0x6f2f,	/*(漯)*/
	0x6f31,	/*(漱)*/
	0x6f33,	/*(漳)*/
	0x6f36,	/*(漶)*/
	0x6f3e,	/*(漾)*/
	0x6f46,	/*(潆)*/
	0x6f47,	/*(潇)*/
	0x6f4b,	/*(潋)*/
	0x6f4d,	/*(潍)*/
	0x6f58,	/*(潘)*/
	0x6f5c,	/*(潜)*/
	0x6f5e,	/*(潞)*/
	0x6f62,	/*(潢)*/
	0x6f66,	/*(潦)*/
	0x6f6d,	/*(潭)*/
	0x6f6e,	/*(潮)*/
	0x6f72,	/*(潲)*/
	0x6f74,	/*(潴)*/
	0x6f78,	/*(潸)*/
	0x6f7a,	/*(潺)*/
	0x6f7c,	/*(潼)*/
	0x6f84,	/*(澄)*/
	0x6f88,	/*(澈)*/
	0x6f89,	/*(澉)*/
	0x6f8c,	/*(澌)*/
	0x6f8d,	/*(澍)*/
	0x6f8e,	/*(澎)*/
	0x6f9c,	/*(澜)*/
	0x6fa1,	/*(澡)*/
	0x6fa7,	/*(澧)*/
	0x6fb3,	/*(澳)*/
	0x6fb6,	/*(澶)*/
	0x6fb9,	/*(澹)*/
	0x6fc0,	/*(激)*/
	0x6fc2,	/*(濂)*/
	0x6fc9,	/*(濉)*/
	0x6fd1,	/*(濑)*/
	0x6fd2,	/*(濒)*/
	0x6fde,	/*(濞)*/
	0x6fe0,	/*(濠)*/
	0x6fe1,	/*(濡)*/
	0x6fee,	/*(濮)*/
	0x6fef,	/*(濯)*/
	0x7011,	/*(瀑)*/
	0x701a,	/*(瀚)*/
	0x701b,	/*(瀛)*/
	0x7023,	/*(瀣)*/
	0x7035,	/*(瀵)*/
	0x7039,	/*(瀹)*/
	0x704c,	/*(灌)*/
	0x704f,	/*(灏)*/
	0x705e,	/*(灞)*/
	0x706b,	/*(火)*/
	0x706c,	/*(灬)*/
	0x706d,	/*(灭)*/
	0x706f,	/*(灯)*/
	0x7070,	/*(灰)*/
	0x7075,	/*(灵)*/
	0x7076,	/*(灶)*/
	0x7078,	/*(灸)*/
	0x707c,	/*(灼)*/
	0x707e,	/*(灾)*/
	0x707f,	/*(灿)*/
	0x7080,	/*(炀)*/
	0x7085,	/*(炅)*/
	0x7089,	/*(炉)*/
	0x708a,	/*(炊)*/
	0x708e,	/*(炎)*/
	0x7092,	/*(炒)*/
	0x7094,	/*(炔)*/
	0x7095,	/*(炕)*/
	0x7096,	/*(炖)*/
	0x7099,	/*(炙)*/
	0x709c,	/*(炜)*/
	0x709d,	/*(炝)*/
	0x70ab,	/*(炫)*/
	0x70ac,	/*(炬)*/
	0x70ad,	/*(炭)*/
	0x70ae,	/*(炮)*/
	0x70af,	/*(炯)*/
	0x70b1,	/*(炱)*/
	0x70b3,	/*(炳)*/
	0x70b7,	/*(炷)*/
	0x70b8,	/*(炸)*/
	0x70b9,	/*(点)*/
	0x70bb,	/*(炻)*/
	0x70bc,	/*(炼)*/
	0x70bd,	/*(炽)*/
	0x70c0,	/*(烀)*/
	0x70c1,	/*(烁)*/
	0x70c2,	/*(烂)*/
	0x70c3,	/*(烃)*/
	0x70c8,	/*(烈)*/
	0x70ca,	/*(烊)*/
	0x70d8,	/*(烘)*/
	0x70d9,	/*(烙)*/
	0x70db,	/*(烛)*/
	0x70df,	/*(烟)*/
	0x70e4,	/*(烤)*/
	0x70e6,	/*(烦)*/
	0x70e7,	/*(烧)*/
	0x70e8,	/*(烨)*/
	0x70e9,	/*(烩)*/
	0x70eb,	/*(烫)*/
	0x70ec,	/*(烬)*/
	0x70ed,	/*(热)*/
	0x70ef,	/*(烯)*/
	0x70f7,	/*(烷)*/
	0x70f9,	/*(烹)*/
	0x70fd,	/*(烽)*/
	0x7109,	/*(焉)*/
	0x710a,	/*(焊)*/
	0x7110,	/*(焐)*/
	0x7113,	/*(焓)*/
	0x7115,	/*(焕)*/
	0x7116,	/*(焖)*/
	0x7118,	/*(焘)*/
	0x7119,	/*(焙)*/
	0x711a,	/*(焚)*/
	0x7126,	/*(焦)*/
	0x712f,	/*(焯)*/
	0x7130,	/*(焰)*/
	0x7131,	/*(焱)*/
	0x7136,	/*(然)*/
	0x7145,	/*(煅)*/
	0x714a,	/*(煊)*/
	0x714c,	/*(煌)*/
	0x714e,	/*(煎)*/
	0x715c,	/*(煜)*/
	0x715e,	/*(煞)*/
	0x7164,	/*(煤)*/
	0x7166,	/*(煦)*/
	0x7167,	/*(照)*/
	0x7168,	/*(煨)*/
	0x716e,	/*(煮)*/
	0x7172,	/*(煲)*/
	0x7173,	/*(煳)*/
	0x7178,	/*(煸)*/
	0x717a,	/*(煺)*/
	0x717d,	/*(煽)*/
	0x7184,	/*(熄)*/
	0x718a,	/*(熊)*/
	0x718f,	/*(熏)*/
	0x7194,	/*(熔)*/
	0x7198,	/*(熘)*/
	0x7199,	/*(熙)*/
	0x719f,	/*(熟)*/
	0x71a0,	/*(熠)*/
	0x71a8,	/*(熨)*/
	0x71ac,	/*(熬)*/
	0x71b3,	/*(熳)*/
	0x71b5,	/*(熵)*/
	0x71b9,	/*(熹)*/
	0x71c3,	/*(燃)*/
	0x71ce,	/*(燎)*/
	0x71d4,	/*(燔)*/
	0x71d5,	/*(燕)*/
	0x71e0,	/*(燠)*/
	0x71e5,	/*(燥)*/
	0x71e7,	/*(燧)*/
	0x71ee,	/*(燮)*/
	0x71f9,	/*(燹)*/
	0x7206,	/*(爆)*/
	0x721d,	/*(爝)*/
	0x7228,	/*(爨)*/
	0x722a,	/*(爪)*/
	0x722c,	/*(爬)*/
	0x7230,	/*(爰)*/
	0x7231,	/*(爱)*/
	0x7235,	/*(爵)*/
	0x7236,	/*(父)*/
	0x7237,	/*(爷)*/
	0x7238,	/*(爸)*/
	0x7239,	/*(爹)*/
	0x723b,	/*(爻)*/
	0x723d,	/*(爽)*/
	0x723f,	/*(爿)*/
	0x7247,	/*(片)*/
	0x7248,	/*(版)*/
	0x724c,	/*(牌)*/
	0x724d,	/*(牍)*/
	0x7252,	/*(牒)*/
	0x7256,	/*(牖)*/
	0x7259,	/*(牙)*/
	0x725b,	/*(牛)*/
	0x725d,	/*(牝)*/
	0x725f,	/*(牟)*/
	0x7261,	/*(牡)*/
	0x7262,	/*(牢)*/
	0x7266,	/*(牦)*/
	0x7267,	/*(牧)*/
	0x7269,	/*(物)*/
	0x726e,	/*(牮)*/
	0x726f,	/*(牯)*/
	0x7272,	/*(牲)*/
	0x7275,	/*(牵)*/
	0x7279,	/*(特)*/
	0x727a,	/*(牺)*/
	0x727e,	/*(牾)*/
	0x727f,	/*(牿)*/
	0x7280,	/*(犀)*/
	0x7281,	/*(犁)*/
	0x7284,	/*(犄)*/
	0x728a,	/*(犊)*/
	0x728b,	/*(犋)*/
	0x728d,	/*(犍)*/
	0x728f,	/*(犏)*/
	0x7292,	/*(犒)*/
	0x729f,	/*(犟)*/
	0x72ac,	/*(犬)*/
	0x72ad,	/*(犭)*/
	0x72af,	/*(犯)*/
	0x72b0,	/*(犰)*/
	0x72b4,	/*(犴)*/
	0x72b6,	/*(状)*/
	0x72b7,	/*(犷)*/
	0x72b8,	/*(犸)*/
	0x72b9,	/*(犹)*/
	0x72c1,	/*(狁)*/
	0x72c2,	/*(狂)*/
	0x72c3,	/*(狃)*/
	0x72c4,	/*(狄)*/
	0x72c8,	/*(狈)*/
	0x72cd,	/*(狍)*/
	0x72ce,	/*(狎)*/
	0x72d0,	/*(狐)*/
	0x72d2,	/*(狒)*/
	0x72d7,	/*(狗)*/
	0x72d9,	/*(狙)*/
	0x72de,	/*(狞)*/
	0x72e0,	/*(狠)*/
	0x72e1,	/*(狡)*/
	0x72e8,	/*(狨)*/
	0x72e9,	/*(狩)*/
	0x72ec,	/*(独)*/
	0x72ed,	/*(狭)*/
	0x72ee,	/*(狮)*/
	0x72ef,	/*(狯)*/
	0x72f0,	/*(狰)*/
	0x72f1,	/*(狱)*/
	0x72f2,	/*(狲)*/
	0x72f3,	/*(狳)*/
	0x72f4,	/*(狴)*/
	0x72f7,	/*(狷)*/
	0x72f8,	/*(狸)*/
	0x72fa,	/*(狺)*/
	0x72fb,	/*(狻)*/
	0x72fc,	/*(狼)*/
	0x7301,	/*(猁)*/
	0x7303,	/*(猃)*/
	0x730a,	/*(猊)*/
	0x730e,	/*(猎)*/
	0x7313,	/*(猓)*/
	0x7315,	/*(猕)*/
	0x7316,	/*(猖)*/
	0x7317,	/*(猗)*/
	0x731b,	/*(猛)*/
	0x731c,	/*(猜)*/
	0x731d,	/*(猝)*/
	0x731e,	/*(猞)*/
	0x7321,	/*(猡)*/
	0x7322,	/*(猢)*/
	0x7325,	/*(猥)*/
	0x7329,	/*(猩)*/
	0x732a,	/*(猪)*/
	0x732b,	/*(猫)*/
	0x732c,	/*(猬)*/
	0x732e,	/*(献)*/
	0x7331,	/*(猱)*/
	0x7334,	/*(猴)*/
	0x7337,	/*(猷)*/
	0x7338,	/*(猸)*/
	0x7339,	/*(猹)*/
	0x733e,	/*(猾)*/
	0x733f,	/*(猿)*/
	0x734d,	/*(獍)*/
	0x7350,	/*(獐)*/
	0x7352,	/*(獒)*/
	0x7357,	/*(獗)*/
	0x7360,	/*(獠)*/
	0x736c,	/*(獬)*/
	0x736d,	/*(獭)*/
	0x736f,	/*(獯)*/
	0x737e,	/*(獾)*/
	0x7384,	/*(玄)*/
	0x7387,	/*(率)*/
	0x7389,	/*(玉)*/
	0x738b,	/*(王)*/
	0x738e,	/*(玎)*/
	0x7391,	/*(玑)*/
	0x7396,	/*(玖)*/
	0x739b,	/*(玛)*/
	0x739f,	/*(玟)*/
	0x73a2,	/*(玢)*/
	0x73a9,	/*(玩)*/
	0x73ab,	/*(玫)*/
	0x73ae,	/*(玮)*/
	0x73af,	/*(环)*/
	0x73b0,	/*(现)*/
	0x73b2,	/*(玲)*/
	0x73b3,	/*(玳)*/
	0x73b7,	/*(玷)*/
	0x73ba,	/*(玺)*/
	0x73bb,	/*(玻)*/
	0x73c0,	/*(珀)*/
	0x73c2,	/*(珂)*/
	0x73c8,	/*(珈)*/
	0x73c9,	/*(珉)*/
	0x73ca,	/*(珊)*/
	0x73cd,	/*(珍)*/
	0x73cf,	/*(珏)*/
	0x73d0,	/*(珐)*/
	0x73d1,	/*(珑)*/
	0x73d9,	/*(珙)*/
	0x73de,	/*(珞)*/
	0x73e0,	/*(珠)*/
	0x73e5,	/*(珥)*/
	0x73e7,	/*(珧)*/
	0x73e9,	/*(珩)*/
	0x73ed,	/*(班)*/
	0x73f2,	/*(珲)*/
	0x7403,	/*(球)*/
	0x7405,	/*(琅)*/
	0x7406,	/*(理)*/
	0x7409,	/*(琉)*/
	0x740a,	/*(琊)*/
	0x740f,	/*(琏)*/
	0x7410,	/*(琐)*/
	0x741a,	/*(琚)*/
	0x741b,	/*(琛)*/
	0x7422,	/*(琢)*/
	0x7425,	/*(琥)*/
	0x7426,	/*(琦)*/
	0x7428,	/*(琨)*/
	0x742a,	/*(琪)*/
	0x742c,	/*(琬)*/
	0x742e,	/*(琮)*/
	0x7430,	/*(琰)*/
	0x7433,	/*(琳)*/
	0x7434,	/*(琴)*/
	0x7435,	/*(琵)*/
	0x7436,	/*(琶)*/
	0x743c,	/*(琼)*/
	0x7441,	/*(瑁)*/
	0x7455,	/*(瑕)*/
	0x7457,	/*(瑗)*/
	0x7459,	/*(瑙)*/
	0x745a,	/*(瑚)*/
	0x745b,	/*(瑛)*/
	0x745c,	/*(瑜)*/
	0x745e,	/*(瑞)*/
	0x745f,	/*(瑟)*/
	0x746d,	/*(瑭)*/
	0x7470,	/*(瑰)*/
	0x7476,	/*(瑶)*/
	0x7477,	/*(瑷)*/
	0x747e,	/*(瑾)*/
	0x7480,	/*(璀)*/
	0x7481,	/*(璁)*/
	0x7483,	/*(璃)*/
	0x7487,	/*(璇)*/
	0x748b,	/*(璋)*/
	0x748e,	/*(璎)*/
	0x7490,	/*(璐)*/
	0x749c,	/*(璜)*/
	0x749e,	/*(璞)*/
	0x74a7,	/*(璧)*/
	0x74a8,	/*(璨)*/
	0x74a9,	/*(璩)*/
	0x74ba,	/*(璺)*/
	0x74d2,	/*(瓒)*/
	0x74dc,	/*(瓜)*/
	0x74de,	/*(瓞)*/
	0x74e0,	/*(瓠)*/
	0x74e2,	/*(瓢)*/
	0x74e3,	/*(瓣)*/
	0x74e4,	/*(瓤)*/
	0x74e6,	/*(瓦)*/
	0x74ee,	/*(瓮)*/
	0x74ef,	/*(瓯)*/
	0x74f4,	/*(瓴)*/
	0x74f6,	/*(瓶)*/
	0x74f7,	/*(瓷)*/
	0x74ff,	/*(瓿)*/
	0x7504,	/*(甄)*/
	0x750d,	/*(甍)*/
	0x750f,	/*(甏)*/
	0x7511,	/*(甑)*/
	0x7513,	/*(甓)*/
	0x7518,	/*(甘)*/
	0x7519,	/*(甙)*/
	0x751a,	/*(甚)*/
	0x751c,	/*(甜)*/
	0x751f,	/*(生)*/
	0x7525,	/*(甥)*/
	0x7528,	/*(用)*/
	0x7529,	/*(甩)*/
	0x752b,	/*(甫)*/
	0x752c,	/*(甬)*/
	0x752d,	/*(甭)*/
	0x752f,	/*(甯)*/
	0x7530,	/*(田)*/
	0x7531,	/*(由)*/
	0x7532,	/*(甲)*/
	0x7533,	/*(申)*/
	0x7535,	/*(电)*/
	0x7537,	/*(男)*/
	0x7538,	/*(甸)*/
	0x753a,	/*(町)*/
	0x753b,	/*(画)*/
	0x753e,	/*(甾)*/
	0x7540,	/*(畀)*/
	0x7545,	/*(畅)*/
	0x7548,	/*(畈)*/
	0x754b,	/*(畋)*/
	0x754c,	/*(界)*/
	0x754e,	/*(畎)*/
	0x754f,	/*(畏)*/
	0x7554,	/*(畔)*/
	0x7559,	/*(留)*/
	0x755a,	/*(畚)*/
	0x755b,	/*(畛)*/
	0x755c,	/*(畜)*/
	0x7565,	/*(略)*/
	0x7566,	/*(畦)*/
	0x756a,	/*(番)*/
	0x7572,	/*(畲)*/
	0x7574,	/*(畴)*/
	0x7578,	/*(畸)*/
	0x7579,	/*(畹)*/
	0x757f,	/*(畿)*/
	0x7583,	/*(疃)*/
	0x7586,	/*(疆)*/
	0x758b,	/*(疋)*/
	0x758f,	/*(疏)*/
	0x7591,	/*(疑)*/
	0x7592,	/*(疒)*/
	0x7594,	/*(疔)*/
	0x7596,	/*(疖)*/
	0x7597,	/*(疗)*/
	0x7599,	/*(疙)*/
	0x759a,	/*(疚)*/
	0x759d,	/*(疝)*/
	0x759f,	/*(疟)*/
	0x75a0,	/*(疠)*/
	0x75a1,	/*(疡)*/
	0x75a3,	/*(疣)*/
	0x75a4,	/*(疤)*/
	0x75a5,	/*(疥)*/
	0x75ab,	/*(疫)*/
	0x75ac,	/*(疬)*/
	0x75ae,	/*(疮)*/
	0x75af,	/*(疯)*/
	0x75b0,	/*(疰)*/
	0x75b1,	/*(疱)*/
	0x75b2,	/*(疲)*/
	0x75b3,	/*(疳)*/
	0x75b4,	/*(疴)*/
	0x75b5,	/*(疵)*/
	0x75b8,	/*(疸)*/
	0x75b9,	/*(疹)*/
	0x75bc,	/*(疼)*/
	0x75bd,	/*(疽)*/
	0x75be,	/*(疾)*/
	0x75c2,	/*(痂)*/
	0x75c3,	/*(痃)*/
	0x75c4,	/*(痄)*/
	0x75c5,	/*(病)*/
	0x75c7,	/*(症)*/
	0x75c8,	/*(痈)*/
	0x75c9,	/*(痉)*/
	0x75ca,	/*(痊)*/
	0x75cd,	/*(痍)*/
	0x75d2,	/*(痒)*/
	0x75d4,	/*(痔)*/
	0x75d5,	/*(痕)*/
	0x75d6,	/*(痖)*/
	0x75d8,	/*(痘)*/
	0x75db,	/*(痛)*/
	0x75de,	/*(痞)*/
	0x75e2,	/*(痢)*/
	0x75e3,	/*(痣)*/
	0x75e4,	/*(痤)*/
	0x75e6,	/*(痦)*/
	0x75e7,	/*(痧)*/
	0x75e8,	/*(痨)*/
	0x75ea,	/*(痪)*/
	0x75eb,	/*(痫)*/
	0x75f0,	/*(痰)*/
	0x75f1,	/*(痱)*/
	0x75f4,	/*(痴)*/
	0x75f9,	/*(痹)*/
	0x75fc,	/*(痼)*/
	0x75ff,	/*(痿)*/
	0x7600,	/*(瘀)*/
	0x7601,	/*(瘁)*/
	0x7603,	/*(瘃)*/
	0x7605,	/*(瘅)*/
	0x760a,	/*(瘊)*/
	0x760c,	/*(瘌)*/
	0x7610,	/*(瘐)*/
	0x7615,	/*(瘕)*/
	0x7617,	/*(瘗)*/
	0x7618,	/*(瘘)*/
	0x7619,	/*(瘙)*/
	0x761b,	/*(瘛)*/
	0x761f,	/*(瘟)*/
	0x7620,	/*(瘠)*/
	0x7622,	/*(瘢)*/
	0x7624,	/*(瘤)*/
	0x7625,	/*(瘥)*/
	0x7626,	/*(瘦)*/
	0x7629,	/*(瘩)*/
	0x762a,	/*(瘪)*/
	0x762b,	/*(瘫)*/
	0x762d,	/*(瘭)*/
	0x7630,	/*(瘰)*/
	0x7633,	/*(瘳)*/
	0x7634,	/*(瘴)*/
	0x7635,	/*(瘵)*/
	0x7638,	/*(瘸)*/
	0x763c,	/*(瘼)*/
	0x763e,	/*(瘾)*/
	0x763f,	/*(瘿)*/
	0x7640,	/*(癀)*/
	0x7643,	/*(癃)*/
	0x764c,	/*(癌)*/
	0x764d,	/*(癍)*/
	0x7654,	/*(癔)*/
	0x7656,	/*(癖)*/
	0x765c,	/*(癜)*/
	0x765e,	/*(癞)*/
	0x7663,	/*(癣)*/
	0x766b,	/*(癫)*/
	0x766f,	/*(癯)*/
	0x7678,	/*(癸)*/
	0x767b,	/*(登)*/
	0x767d,	/*(白)*/
	0x767e,	/*(百)*/
	0x7682,	/*(皂)*/
	0x7684,	/*(的)*/
	0x7686,	/*(皆)*/
	0x7687,	/*(皇)*/
	0x7688,	/*(皈)*/
	0x768b,	/*(皋)*/
	0x768e,	/*(皎)*/
	0x7691,	/*(皑)*/
	0x7693,	/*(皓)*/
	0x7696,	/*(皖)*/
	0x7699,	/*(皙)*/
	0x76a4,	/*(皤)*/
	0x76ae,	/*(皮)*/
	0x76b1,	/*(皱)*/
	0x76b2,	/*(皲)*/
	0x76b4,	/*(皴)*/
	0x76bf,	/*(皿)*/
	0x76c2,	/*(盂)*/
	0x76c5,	/*(盅)*/
	0x76c6,	/*(盆)*/
	0x76c8,	/*(盈)*/
	0x76ca,	/*(益)*/
	0x76cd,	/*(盍)*/
	0x76ce,	/*(盎)*/
	0x76cf,	/*(盏)*/
	0x76d0,	/*(盐)*/
	0x76d1,	/*(监)*/
	0x76d2,	/*(盒)*/
	0x76d4,	/*(盔)*/
	0x76d6,	/*(盖)*/
	0x76d7,	/*(盗)*/
	0x76d8,	/*(盘)*/
	0x76db,	/*(盛)*/
	0x76df,	/*(盟)*/
	0x76e5,	/*(盥)*/
	0x76ee,	/*(目)*/
	0x76ef,	/*(盯)*/
	0x76f1,	/*(盱)*/
	0x76f2,	/*(盲)*/
	0x76f4,	/*(直)*/
	0x76f8,	/*(相)*/
	0x76f9,	/*(盹)*/
	0x76fc,	/*(盼)*/
	0x76fe,	/*(盾)*/
	0x7701,	/*(省)*/
	0x7704,	/*(眄)*/
	0x7707,	/*(眇)*/
	0x7708,	/*(眈)*/
	0x7709,	/*(眉)*/
	0x770b,	/*(看)*/
	0x770d,	/*(眍)*/
	0x7719,	/*(眙)*/
	0x771a,	/*(眚)*/
	0x771f,	/*(真)*/
	0x7720,	/*(眠)*/
	0x7722,	/*(眢)*/
	0x7726,	/*(眦)*/
	0x7728,	/*(眨)*/
	0x7729,	/*(眩)*/
	0x772d,	/*(眭)*/
	0x772f,	/*(眯)*/
	0x7735,	/*(眵)*/
	0x7736,	/*(眶)*/
	0x7737,	/*(眷)*/
	0x7738,	/*(眸)*/
	0x773a,	/*(眺)*/
	0x773c,	/*(眼)*/
	0x7740,	/*(着)*/
	0x7741,	/*(睁)*/
	0x7743,	/*(睃)*/
	0x7747,	/*(睇)*/
	0x7750,	/*(睐)*/
	0x7751,	/*(睑)*/
	0x775a,	/*(睚)*/
	0x775b,	/*(睛)*/
	0x7761,	/*(睡)*/
	0x7762,	/*(睢)*/
	0x7763,	/*(督)*/
	0x7765,	/*(睥)*/
	0x7766,	/*(睦)*/
	0x7768,	/*(睨)*/
	0x776b,	/*(睫)*/
	0x776c,	/*(睬)*/
	0x7779,	/*(睹)*/
	0x777d,	/*(睽)*/
	0x777e,	/*(睾)*/
	0x777f,	/*(睿)*/
	0x7780,	/*(瞀)*/
	0x7784,	/*(瞄)*/
	0x7785,	/*(瞅)*/
	0x778c,	/*(瞌)*/
	0x778d,	/*(瞍)*/
	0x778e,	/*(瞎)*/
	0x7791,	/*(瞑)*/
	0x7792,	/*(瞒)*/
	0x779f,	/*(瞟)*/
	0x77a0,	/*(瞠)*/
	0x77a2,	/*(瞢)*/
	0x77a5,	/*(瞥)*/
	0x77a7,	/*(瞧)*/
	0x77a9,	/*(瞩)*/
	0x77aa,	/*(瞪)*/
	0x77ac,	/*(瞬)*/
	0x77b0,	/*(瞰)*/
	0x77b3,	/*(瞳)*/
	0x77b5,	/*(瞵)*/
	0x77bb,	/*(瞻)*/
	0x77bd,	/*(瞽)*/
	0x77bf,	/*(瞿)*/
	0x77cd,	/*(矍)*/
	0x77d7,	/*(矗)*/
	0x77db,	/*(矛)*/
	0x77dc,	/*(矜)*/
	0x77e2,	/*(矢)*/
	0x77e3,	/*(矣)*/
	0x77e5,	/*(知)*/
	0x77e7,	/*(矧)*/
	0x77e9,	/*(矩)*/
	0x77eb,	/*(矫)*/
	0x77ec,	/*(矬)*/
	0x77ed,	/*(短)*/
	0x77ee,	/*(矮)*/
	0x77f3,	/*(石)*/
	0x77f6,	/*(矶)*/
	0x77f8,	/*(矸)*/
	0x77fd,	/*(矽)*/
	0x77fe,	/*(矾)*/
	0x77ff,	/*(矿)*/
	0x7800,	/*(砀)*/
	0x7801,	/*(码)*/
	0x7802,	/*(砂)*/
	0x7809,	/*(砉)*/
	0x780c,	/*(砌)*/
	0x780d,	/*(砍)*/
	0x7811,	/*(砑)*/
	0x7812,	/*(砒)*/
	0x7814,	/*(研)*/
	0x7816,	/*(砖)*/
	0x7817,	/*(砗)*/
	0x7818,	/*(砘)*/
	0x781a,	/*(砚)*/
	0x781c,	/*(砜)*/
	0x781d,	/*(砝)*/
	0x781f,	/*(砟)*/
	0x7823,	/*(砣)*/
	0x7825,	/*(砥)*/
	0x7826,	/*(砦)*/
	0x7827,	/*(砧)*/
	0x7829,	/*(砩)*/
	0x782c,	/*(砬)*/
	0x782d,	/*(砭)*/
	0x7830,	/*(砰)*/
	0x7834,	/*(破)*/
	0x7837,	/*(砷)*/
	0x7838,	/*(砸)*/
	0x7839,	/*(砹)*/
	0x783a,	/*(砺)*/
	0x783b,	/*(砻)*/
	0x783c,	/*(砼)*/
	0x783e,	/*(砾)*/
	0x7840,	/*(础)*/
	0x7845,	/*(硅)*/
	0x7847,	/*(硇)*/
	0x784c,	/*(硌)*/
	0x784e,	/*(硎)*/
	0x7850,	/*(硐)*/
	0x7852,	/*(硒)*/
	0x7855,	/*(硕)*/
	0x7856,	/*(硖)*/
	0x7857,	/*(硗)*/
	0x785d,	/*(硝)*/
	0x786a,	/*(硪)*/
	0x786b,	/*(硫)*/
	0x786c,	/*(硬)*/
	0x786d,	/*(硭)*/
	0x786e,	/*(确)*/
	0x7877,	/*(硷)*/
	0x787c,	/*(硼)*/
	0x7887,	/*(碇)*/
	0x7889,	/*(碉)*/
	0x788c,	/*(碌)*/
	0x788d,	/*(碍)*/
	0x788e,	/*(碎)*/
	0x7891,	/*(碑)*/
	0x7893,	/*(碓)*/
	0x7897,	/*(碗)*/
	0x7898,	/*(碘)*/
	0x789a,	/*(碚)*/
	0x789b,	/*(碛)*/
	0x789c,	/*(碜)*/
	0x789f,	/*(碟)*/
	0x78a1,	/*(碡)*/
	0x78a3,	/*(碣)*/
	0x78a5,	/*(碥)*/
	0x78a7,	/*(碧)*/
	0x78b0,	/*(碰)*/
	0x78b1,	/*(碱)*/
	0x78b2,	/*(碲)*/
	0x78b3,	/*(碳)*/
	0x78b4,	/*(碴)*/
	0x78b9,	/*(碹)*/
	0x78be,	/*(碾)*/
	0x78c1,	/*(磁)*/
	0x78c5,	/*(磅)*/
	0x78c9,	/*(磉)*/
	0x78ca,	/*(磊)*/
	0x78cb,	/*(磋)*/
	0x78d0,	/*(磐)*/
	0x78d4,	/*(磔)*/
	0x78d5,	/*(磕)*/
	0x78d9,	/*(磙)*/
	0x78e8,	/*(磨)*/
	0x78ec,	/*(磬)*/
	0x78f2,	/*(磲)*/
	0x78f4,	/*(磴)*/
	0x78f7,	/*(磷)*/
	0x78fa,	/*(磺)*/
	0x7901,	/*(礁)*/
	0x7905,	/*(礅)*/
	0x7913,	/*(礓)*/
	0x791e,	/*(礞)*/
	0x7924,	/*(礤)*/
	0x7934,	/*(礴)*/
	0x793a,	/*(示)*/
	0x793b,	/*(礻)*/
	0x793c,	/*(礼)*/
	0x793e,	/*(社)*/
	0x7940,	/*(祀)*/
	0x7941,	/*(祁)*/
	0x7946,	/*(祆)*/
	0x7948,	/*(祈)*/
	0x7949,	/*(祉)*/
	0x7953,	/*(祓)*/
	0x7956,	/*(祖)*/
	0x7957,	/*(祗)*/
	0x795a,	/*(祚)*/
	0x795b,	/*(祛)*/
	0x795c,	/*(祜)*/
	0x795d,	/*(祝)*/
	0x795e,	/*(神)*/
	0x795f,	/*(祟)*/
	0x7960,	/*(祠)*/
	0x7962,	/*(祢)*/
	0x7965,	/*(祥)*/
	0x7967,	/*(祧)*/
	0x7968,	/*(票)*/
	0x796d,	/*(祭)*/
	0x796f,	/*(祯)*/
	0x7977,	/*(祷)*/
	0x7978,	/*(祸)*/
	0x797a,	/*(祺)*/
	0x7980,	/*(禀)*/
	0x7981,	/*(禁)*/
	0x7984,	/*(禄)*/
	0x7985,	/*(禅)*/
	0x798a,	/*(禊)*/
	0x798f,	/*(福)*/
	0x799a,	/*(禚)*/
	0x79a7,	/*(禧)*/
	0x79b3,	/*(禳)*/
	0x79b9,	/*(禹)*/
	0x79ba,	/*(禺)*/
	0x79bb,	/*(离)*/
	0x79bd,	/*(禽)*/
	0x79be,	/*(禾)*/
	0x79c0,	/*(秀)*/
	0x79c1,	/*(私)*/
	0x79c3,	/*(秃)*/
	0x79c6,	/*(秆)*/
	0x79c9,	/*(秉)*/
	0x79cb,	/*(秋)*/
	0x79cd,	/*(种)*/
	0x79d1,	/*(科)*/
	0x79d2,	/*(秒)*/
	0x79d5,	/*(秕)*/
	0x79d8,	/*(秘)*/
	0x79df,	/*(租)*/
	0x79e3,	/*(秣)*/
	0x79e4,	/*(秤)*/
	0x79e6,	/*(秦)*/
	0x79e7,	/*(秧)*/
	0x79e9,	/*(秩)*/
	0x79eb,	/*(秫)*/
	0x79ed,	/*(秭)*/
	0x79ef,	/*(积)*/
	0x79f0,	/*(称)*/
	0x79f8,	/*(秸)*/
	0x79fb,	/*(移)*/
	0x79fd,	/*(秽)*/
	0x7a00,	/*(稀)*/
	0x7a02,	/*(稂)*/
	0x7a03,	/*(稃)*/
	0x7a06,	/*(稆)*/
	0x7a0b,	/*(程)*/
	0x7a0d,	/*(稍)*/
	0x7a0e,	/*(税)*/
	0x7a14,	/*(稔)*/
	0x7a17,	/*(稗)*/
	0x7a1a,	/*(稚)*/
	0x7a1e,	/*(稞)*/
	0x7a20,	/*(稠)*/
	0x7a23,	/*(稣)*/
	0x7a33,	/*(稳)*/
	0x7a37,	/*(稷)*/
	0x7a39,	/*(稹)*/
	0x7a3b,	/*(稻)*/
	0x7a3c,	/*(稼)*/
	0x7a3d,	/*(稽)*/
	0x7a3f,	/*(稿)*/
	0x7a46,	/*(穆)*/
	0x7a51,	/*(穑)*/
	0x7a57,	/*(穗)*/
	0x7a70,	/*(穰)*/
	0x7a74,	/*(穴)*/
	0x7a76,	/*(究)*/
	0x7a77,	/*(穷)*/
	0x7a78,	/*(穸)*/
	0x7a79,	/*(穹)*/
	0x7a7a,	/*(空)*/
	0x7a7f,	/*(穿)*/
	0x7a80,	/*(窀)*/
	0x7a81,	/*(突)*/
	0x7a83,	/*(窃)*/
	0x7a84,	/*(窄)*/
	0x7a86,	/*(窆)*/
	0x7a88,	/*(窈)*/
	0x7a8d,	/*(窍)*/
	0x7a91,	/*(窑)*/
	0x7a92,	/*(窒)*/
	0x7a95,	/*(窕)*/
	0x7a96,	/*(窖)*/
	0x7a97,	/*(窗)*/
	0x7a98,	/*(窘)*/
	0x7a9c,	/*(窜)*/
	0x7a9d,	/*(窝)*/
	0x7a9f,	/*(窟)*/
	0x7aa0,	/*(窠)*/
	0x7aa5,	/*(窥)*/
	0x7aa6,	/*(窦)*/
	0x7aa8,	/*(窨)*/
	0x7aac,	/*(窬)*/
	0x7aad,	/*(窭)*/
	0x7ab3,	/*(窳)*/
	0x7abf,	/*(窿)*/
	0x7acb,	/*(立)*/
	0x7ad6,	/*(竖)*/
	0x7ad9,	/*(站)*/
	0x7ade,	/*(竞)*/
	0x7adf,	/*(竟)*/
	0x7ae0,	/*(章)*/
	0x7ae3,	/*(竣)*/
	0x7ae5,	/*(童)*/
	0x7ae6,	/*(竦)*/
	0x7aed,	/*(竭)*/
	0x7aef,	/*(端)*/
	0x7af9,	/*(竹)*/
	0x7afa,	/*(竺)*/
	0x7afd,	/*(竽)*/
	0x7aff,	/*(竿)*/
	0x7b03,	/*(笃)*/
	0x7b04,	/*(笄)*/
	0x7b06,	/*(笆)*/
	0x7b08,	/*(笈)*/
	0x7b0a,	/*(笊)*/
	0x7b0b,	/*(笋)*/
	0x7b0f,	/*(笏)*/
	0x7b11,	/*(笑)*/
	0x7b14,	/*(笔)*/
	0x7b15,	/*(笕)*/
	0x7b19,	/*(笙)*/
	0x7b1b,	/*(笛)*/
	0x7b1e,	/*(笞)*/
	0x7b20,	/*(笠)*/
	0x7b24,	/*(笤)*/
	0x7b25,	/*(笥)*/
	0x7b26,	/*(符)*/
	0x7b28,	/*(笨)*/
	0x7b2a,	/*(笪)*/
	0x7b2b,	/*(笫)*/
	0x7b2c,	/*(第)*/
	0x7b2e,	/*(笮)*/
	0x7b31,	/*(笱)*/
	0x7b33,	/*(笳)*/
	0x7b38,	/*(笸)*/
	0x7b3a,	/*(笺)*/
	0x7b3c,	/*(笼)*/
	0x7b3e,	/*(笾)*/
	0x7b45,	/*(筅)*/
	0x7b47,	/*(筇)*/
	0x7b49,	/*(等)*/
	0x7b4b,	/*(筋)*/
	0x7b4c,	/*(筌)*/
	0x7b4f,	/*(筏)*/
	0x7b50,	/*(筐)*/
	0x7b51,	/*(筑)*/
	0x7b52,	/*(筒)*/
	0x7b54,	/*(答)*/
	0x7b56,	/*(策)*/
	0x7b58,	/*(筘)*/
	0x7b5a,	/*(筚)*/
	0x7b5b,	/*(筛)*/
	0x7b5d,	/*(筝)*/
	0x7b60,	/*(筠)*/
	0x7b62,	/*(筢)*/
	0x7b6e,	/*(筮)*/
	0x7b71,	/*(筱)*/
	0x7b72,	/*(筲)*/
	0x7b75,	/*(筵)*/
	0x7b77,	/*(筷)*/
	0x7b79,	/*(筹)*/
	0x7b7b,	/*(筻)*/
	0x7b7e,	/*(签)*/
	0x7b80,	/*(简)*/
	0x7b85,	/*(箅)*/
	0x7b8d,	/*(箍)*/
	0x7b90,	/*(箐)*/
	0x7b94,	/*(箔)*/
	0x7b95,	/*(箕)*/
	0x7b97,	/*(算)*/
	0x7b9c,	/*(箜)*/
	0x7b9d,	/*(箝)*/
	0x7ba1,	/*(管)*/
	0x7ba2,	/*(箢)*/
	0x7ba6,	/*(箦)*/
	0x7ba7,	/*(箧)*/
	0x7ba8,	/*(箨)*/
	0x7ba9,	/*(箩)*/
	0x7baa,	/*(箪)*/
	0x7bab,	/*(箫)*/
	0x7bac,	/*(箬)*/
	0x7bad,	/*(箭)*/
	0x7bb1,	/*(箱)*/
	0x7bb4,	/*(箴)*/
	0x7bb8,	/*(箸)*/
	0x7bc1,	/*(篁)*/
	0x7bc6,	/*(篆)*/
	0x7bc7,	/*(篇)*/
	0x7bcc,	/*(篌)*/
	0x7bd1,	/*(篑)*/
	0x7bd3,	/*(篓)*/
	0x7bd9,	/*(篙)*/
	0x7bda,	/*(篚)*/
	0x7bdd,	/*(篝)*/
	0x7be1,	/*(篡)*/
	0x7be5,	/*(篥)*/
	0x7be6,	/*(篦)*/
	0x7bea,	/*(篪)*/
	0x7bee,	/*(篮)*/
	0x7bf1,	/*(篱)*/
	0x7bf7,	/*(篷)*/
	0x7bfc,	/*(篼)*/
	0x7bfe,	/*(篾)*/
	0x7c07,	/*(簇)*/
	0x7c0b,	/*(簋)*/
	0x7c0c,	/*(簌)*/
	0x7c0f,	/*(簏)*/
	0x7c16,	/*(簖)*/
	0x7c1f,	/*(簟)*/
	0x7c26,	/*(簦)*/
	0x7c27,	/*(簧)*/
	0x7c2a,	/*(簪)*/
	0x7c38,	/*(簸)*/
	0x7c3f,	/*(簿)*/
	0x7c40,	/*(籀)*/
	0x7c41,	/*(籁)*/
	0x7c4d,	/*(籍)*/
	0x7c73,	/*(米)*/
	0x7c74,	/*(籴)*/
	0x7c7b,	/*(类)*/
	0x7c7c,	/*(籼)*/
	0x7c7d,	/*(籽)*/
	0x7c89,	/*(粉)*/
	0x7c91,	/*(粑)*/
	0x7c92,	/*(粒)*/
	0x7c95,	/*(粕)*/
	0x7c97,	/*(粗)*/
	0x7c98,	/*(粘)*/
	0x7c9c,	/*(粜)*/
	0x7c9d,	/*(粝)*/
	0x7c9e,	/*(粞)*/
	0x7c9f,	/*(粟)*/
	0x7ca2,	/*(粢)*/
	0x7ca4,	/*(粤)*/
	0x7ca5,	/*(粥)*/
	0x7caa,	/*(粪)*/
	0x7cae,	/*(粮)*/
	0x7cb1,	/*(粱)*/
	0x7cb2,	/*(粲)*/
	0x7cb3,	/*(粳)*/
	0x7cb9,	/*(粹)*/
	0x7cbc,	/*(粼)*/
	0x7cbd,	/*(粽)*/
	0x7cbe,	/*(精)*/
	0x7cc1,	/*(糁)*/
	0x7cc5,	/*(糅)*/
	0x7cc7,	/*(糇)*/
	0x7cc8,	/*(糈)*/
	0x7cca,	/*(糊)*/
	0x7ccc,	/*(糌)*/
	0x7ccd,	/*(糍)*/
	0x7cd5,	/*(糕)*/
	0x7cd6,	/*(糖)*/
	0x7cd7,	/*(糗)*/
	0x7cd9,	/*(糙)*/
	0x7cdc,	/*(糜)*/
	0x7cdf,	/*(糟)*/
	0x7ce0,	/*(糠)*/
	0x7ce8,	/*(糨)*/
	0x7cef,	/*(糯)*/
	0x7cf8,	/*(糸)*/
	0x7cfb,	/*(系)*/
	0x7d0a,	/*(紊)*/
	0x7d20,	/*(素)*/
	0x7d22,	/*(索)*/
	0x7d27,	/*(紧)*/
	0x7d2b,	/*(紫)*/
	0x7d2f,	/*(累)*/
	0x7d6e,	/*(絮)*/
	0x7d77,	/*(絷)*/
	0x7da6,	/*(綦)*/
	0x7dae,	/*(綮)*/
	0x7e3b,	/*(縻)*/
	0x7e41,	/*(繁)*/
	0x7e47,	/*(繇)*/
	0x7e82,	/*(纂)*/
	0x7e9b,	/*(纛)*/
	0x7e9f,	/*(纟)*/
	0x7ea0,	/*(纠)*/
	0x7ea1,	/*(纡)*/
	0x7ea2,	/*(红)*/
	0x7ea3,	/*(纣)*/
	0x7ea4,	/*(纤)*/
	0x7ea5,	/*(纥)*/
	0x7ea6,	/*(约)*/
	0x7ea7,	/*(级)*/
	0x7ea8,	/*(纨)*/
	0x7ea9,	/*(纩)*/
	0x7eaa,	/*(纪)*/
	0x7eab,	/*(纫)*/
	0x7eac,	/*(纬)*/
	0x7ead,	/*(纭)*/
	0x7eaf,	/*(纯)*/
	0x7eb0,	/*(纰)*/
	0x7eb1,	/*(纱)*/
	0x7eb2,	/*(纲)*/
	0x7eb3,	/*(纳)*/
	0x7eb5,	/*(纵)*/
	0x7eb6,	/*(纶)*/
	0x7eb7,	/*(纷)*/
	0x7eb8,	/*(纸)*/
	0x7eb9,	/*(纹)*/
	0x7eba,	/*(纺)*/
	0x7ebd,	/*(纽)*/
	0x7ebe,	/*(纾)*/
	0x7ebf,	/*(线)*/
	0x7ec0,	/*(绀)*/
	0x7ec1,	/*(绁)*/
	0x7ec2,	/*(绂)*/
	0x7ec3,	/*(练)*/
	0x7ec4,	/*(组)*/
	0x7ec5,	/*(绅)*/
	0x7ec6,	/*(细)*/
	0x7ec7,	/*(织)*/
	0x7ec8,	/*(终)*/
	0x7ec9,	/*(绉)*/
	0x7eca,	/*(绊)*/
	0x7ecb,	/*(绋)*/
	0x7ecc,	/*(绌)*/
	0x7ecd,	/*(绍)*/
	0x7ece,	/*(绎)*/
	0x7ecf,	/*(经)*/
	0x7ed0,	/*(绐)*/
	0x7ed1,	/*(绑)*/
	0x7ed2,	/*(绒)*/
	0x7ed3,	/*(结)*/
	0x7ed4,	/*(绔)*/
	0x7ed5,	/*(绕)*/
	0x7ed7,	/*(绗)*/
	0x7ed8,	/*(绘)*/
	0x7ed9,	/*(给)*/
	0x7eda,	/*(绚)*/
	0x7edb,	/*(绛)*/
	0x7edc,	/*(络)*/
	0x7edd,	/*(绝)*/
	0x7ede,	/*(绞)*/
	0x7edf,	/*(统)*/
	0x7ee0,	/*(绠)*/
	0x7ee1,	/*(绡)*/
	0x7ee2,	/*(绢)*/
	0x7ee3,	/*(绣)*/
	0x7ee5,	/*(绥)*/
	0x7ee6,	/*(绦)*/
	0x7ee7,	/*(继)*/
	0x7ee8,	/*(绨)*/
	0x7ee9,	/*(绩)*/
	0x7eea,	/*(绪)*/
	0x7eeb,	/*(绫)*/
	0x7eed,	/*(续)*/
	0x7eee,	/*(绮)*/
	0x7eef,	/*(绯)*/
	0x7ef0,	/*(绰)*/
	0x7ef1,	/*(绱)*/
	0x7ef2,	/*(绲)*/
	0x7ef3,	/*(绳)*/
	0x7ef4,	/*(维)*/
	0x7ef5,	/*(绵)*/
	0x7ef6,	/*(绶)*/
	0x7ef7,	/*(绷)*/
	0x7ef8,	/*(绸)*/
	0x7efa,	/*(绺)*/
	0x7efb,	/*(绻)*/
	0x7efc,	/*(综)*/
	0x7efd,	/*(绽)*/
	0x7efe,	/*(绾)*/
	0x7eff,	/*(绿)*/
	0x7f00,	/*(缀)*/
	0x7f01,	/*(缁)*/
	0x7f02,	/*(缂)*/
	0x7f03,	/*(缃)*/
	0x7f04,	/*(缄)*/
	0x7f05,	/*(缅)*/
	0x7f06,	/*(缆)*/
	0x7f07,	/*(缇)*/
	0x7f08,	/*(缈)*/
	0x7f09,	/*(缉)*/
	0x7f0b,	/*(缋)*/
	0x7f0c,	/*(缌)*/
	0x7f0d,	/*(缍)*/
	0x7f0e,	/*(缎)*/
	0x7f0f,	/*(缏)*/
	0x7f11,	/*(缑)*/
	0x7f12,	/*(缒)*/
	0x7f13,	/*(缓)*/
	0x7f14,	/*(缔)*/
	0x7f15,	/*(缕)*/
	0x7f16,	/*(编)*/
	0x7f17,	/*(缗)*/
	0x7f18,	/*(缘)*/
	0x7f19,	/*(缙)*/
	0x7f1a,	/*(缚)*/
	0x7f1b,	/*(缛)*/
	0x7f1c,	/*(缜)*/
	0x7f1d,	/*(缝)*/
	0x7f1f,	/*(缟)*/
	0x7f20,	/*(缠)*/
	0x7f21,	/*(缡)*/
	0x7f22,	/*(缢)*/
	0x7f23,	/*(缣)*/
	0x7f24,	/*(缤)*/
	0x7f25,	/*(缥)*/
	0x7f26,	/*(缦)*/
	0x7f27,	/*(缧)*/
	0x7f28,	/*(缨)*/
	0x7f29,	/*(缩)*/
	0x7f2a,	/*(缪)*/
	0x7f2b,	/*(缫)*/
	0x7f2c,	/*(缬)*/
	0x7f2d,	/*(缭)*/
	0x7f2e,	/*(缮)*/
	0x7f2f,	/*(缯)*/
	0x7f30,	/*(缰)*/
	0x7f31,	/*(缱)*/
	0x7f32,	/*(缲)*/
	0x7f33,	/*(缳)*/
	0x7f34,	/*(缴)*/
	0x7f35,	/*(缵)*/
	0x7f36,	/*(缶)*/
	0x7f38,	/*(缸)*/
	0x7f3a,	/*(缺)*/
	0x7f42,	/*(罂)*/
	0x7f44,	/*(罄)*/
	0x7f45,	/*(罅)*/
	0x7f50,	/*(罐)*/
	0x7f51,	/*(网)*/
	0x7f54,	/*(罔)*/
	0x7f55,	/*(罕)*/
	0x7f57,	/*(罗)*/
	0x7f58,	/*(罘)*/
	0x7f5a,	/*(罚)*/
	0x7f5f,	/*(罟)*/
	0x7f61,	/*(罡)*/
	0x7f62,	/*(罢)*/
	0x7f68,	/*(罨)*/
	0x7f69,	/*(罩)*/
	0x7f6a,	/*(罪)*/
	0x7f6e,	/*(置)*/
	0x7f71,	/*(罱)*/
	0x7f72,	/*(署)*/
	0x7f74,	/*(罴)*/
	0x7f79,	/*(罹)*/
	0x7f7e,	/*(罾)*/
	0x7f81,	/*(羁)*/
	0x7f8a,	/*(羊)*/
	0x7f8c,	/*(羌)*/
	0x7f8e,	/*(美)*/
	0x7f94,	/*(羔)*/
	0x7f9a,	/*(羚)*/
	0x7f9d,	/*(羝)*/
	0x7f9e,	/*(羞)*/
	0x7f9f,	/*(羟)*/
	0x7fa1,	/*(羡)*/
	0x7fa4,	/*(群)*/
	0x7fa7,	/*(羧)*/
	0x7faf,	/*(羯)*/
	0x7fb0,	/*(羰)*/
	0x7fb2,	/*(羲)*/
	0x7fb8,	/*(羸)*/
	0x7fb9,	/*(羹)*/
	0x7fbc,	/*(羼)*/
	0x7fbd,	/*(羽)*/
	0x7fbf,	/*(羿)*/
	0x7fc1,	/*(翁)*/
	0x7fc5,	/*(翅)*/
	0x7fca,	/*(翊)*/
	0x7fcc,	/*(翌)*/
	0x7fce,	/*(翎)*/
	0x7fd4,	/*(翔)*/
	0x7fd5,	/*(翕)*/
	0x7fd8,	/*(翘)*/
	0x7fdf,	/*(翟)*/
	0x7fe0,	/*(翠)*/
	0x7fe1,	/*(翡)*/
	0x7fe5,	/*(翥)*/
	0x7fe6,	/*(翦)*/
	0x7fe9,	/*(翩)*/
	0x7fee,	/*(翮)*/
	0x7ff0,	/*(翰)*/
	0x7ff1,	/*(翱)*/
	0x7ff3,	/*(翳)*/
	0x7ffb,	/*(翻)*/
	0x7ffc,	/*(翼)*/
	0x8000,	/*(耀)*/
	0x8001,	/*(老)*/
	0x8003,	/*(考)*/
	0x8004,	/*(耄)*/
	0x8005,	/*(者)*/
	0x8006,	/*(耆)*/
	0x800b,	/*(耋)*/
	0x800c,	/*(而)*/
	0x800d,	/*(耍)*/
	0x8010,	/*(耐)*/
	0x8012,	/*(耒)*/
	0x8014,	/*(耔)*/
	0x8015,	/*(耕)*/
	0x8016,	/*(耖)*/
	0x8017,	/*(耗)*/
	0x8018,	/*(耘)*/
	0x8019,	/*(耙)*/
	0x801c,	/*(耜)*/
	0x8020,	/*(耠)*/
	0x8022,	/*(耢)*/
	0x8025,	/*(耥)*/
	0x8026,	/*(耦)*/
	0x8027,	/*(耧)*/
	0x8028,	/*(耨)*/
	0x8029,	/*(耩)*/
	0x802a,	/*(耪)*/
	0x8031,	/*(耱)*/
	0x8033,	/*(耳)*/
	0x8035,	/*(耵)*/
	0x8036,	/*(耶)*/
	0x8037,	/*(耷)*/
	0x8038,	/*(耸)*/
	0x803b,	/*(耻)*/
	0x803d,	/*(耽)*/
	0x803f,	/*(耿)*/
	0x8042,	/*(聂)*/
	0x8043,	/*(聃)*/
	0x8046,	/*(聆)*/
	0x804a,	/*(聊)*/
	0x804b,	/*(聋)*/
	0x804c,	/*(职)*/
	0x804d,	/*(聍)*/
	0x8052,	/*(聒)*/
	0x8054,	/*(联)*/
	0x8058,	/*(聘)*/
	0x805a,	/*(聚)*/
	0x8069,	/*(聩)*/
	0x806a,	/*(聪)*/
	0x8071,	/*(聱)*/
	0x807f,	/*(聿)*/
	0x8080,	/*(肀)*/
	0x8083,	/*(肃)*/
	0x8084,	/*(肄)*/
	0x8086,	/*(肆)*/
	0x8087,	/*(肇)*/
	0x8089,	/*(肉)*/
	0x808b,	/*(肋)*/
	0x808c,	/*(肌)*/
	0x8093,	/*(肓)*/
	0x8096,	/*(肖)*/
	0x8098,	/*(肘)*/
	0x809a,	/*(肚)*/
	0x809b,	/*(肛)*/
	0x809c,	/*(肜)*/
	0x809d,	/*(肝)*/
	0x809f,	/*(肟)*/
	0x80a0,	/*(肠)*/
	0x80a1,	/*(股)*/
	0x80a2,	/*(肢)*/
	0x80a4,	/*(肤)*/
	0x80a5,	/*(肥)*/
	0x80a9,	/*(肩)*/
	0x80aa,	/*(肪)*/
	0x80ab,	/*(肫)*/
	0x80ad,	/*(肭)*/
	0x80ae,	/*(肮)*/
	0x80af,	/*(肯)*/
	0x80b1,	/*(肱)*/
	0x80b2,	/*(育)*/
	0x80b4,	/*(肴)*/
	0x80b7,	/*(肷)*/
	0x80ba,	/*(肺)*/
	0x80bc,	/*(肼)*/
	0x80bd,	/*(肽)*/
	0x80be,	/*(肾)*/
	0x80bf,	/*(肿)*/
	0x80c0,	/*(胀)*/
	0x80c1,	/*(胁)*/
	0x80c2,	/*(胂)*/
	0x80c3,	/*(胃)*/
	0x80c4,	/*(胄)*/
	0x80c6,	/*(胆)*/
	0x80cc,	/*(背)*/
	0x80cd,	/*(胍)*/
	0x80ce,	/*(胎)*/
	0x80d6,	/*(胖)*/
	0x80d7,	/*(胗)*/
	0x80d9,	/*(胙)*/
	0x80da,	/*(胚)*/
	0x80db,	/*(胛)*/
	0x80dc,	/*(胜)*/
	0x80dd,	/*(胝)*/
	0x80de,	/*(胞)*/
	0x80e1,	/*(胡)*/
	0x80e4,	/*(胤)*/
	0x80e5,	/*(胥)*/
	0x80e7,	/*(胧)*/
	0x80e8,	/*(胨)*/
	0x80e9,	/*(胩)*/
	0x80ea,	/*(胪)*/
	0x80eb,	/*(胫)*/
	0x80ec,	/*(胬)*/
	0x80ed,	/*(胭)*/
	0x80ef,	/*(胯)*/
	0x80f0,	/*(胰)*/
	0x80f1,	/*(胱)*/
	0x80f2,	/*(胲)*/
	0x80f3,	/*(胳)*/
	0x80f4,	/*(胴)*/
	0x80f6,	/*(胶)*/
	0x80f8,	/*(胸)*/
	0x80fa,	/*(胺)*/
	0x80fc,	/*(胼)*/
	0x80fd,	/*(能)*/
	0x8102,	/*(脂)*/
	0x8106,	/*(脆)*/
	0x8109,	/*(脉)*/
	0x810a,	/*(脊)*/
	0x810d,	/*(脍)*/
	0x810e,	/*(脎)*/
	0x810f,	/*(脏)*/
	0x8110,	/*(脐)*/
	0x8111,	/*(脑)*/
	0x8112,	/*(脒)*/
	0x8113,	/*(脓)*/
	0x8114,	/*(脔)*/
	0x8116,	/*(脖)*/
	0x8118,	/*(脘)*/
	0x811a,	/*(脚)*/
	0x811e,	/*(脞)*/
	0x812c,	/*(脬)*/
	0x812f,	/*(脯)*/
	0x8131,	/*(脱)*/
	0x8132,	/*(脲)*/
	0x8136,	/*(脶)*/
	0x8138,	/*(脸)*/
	0x813e,	/*(脾)*/
	0x8146,	/*(腆)*/
	0x8148,	/*(腈)*/
	0x814a,	/*(腊)*/
	0x814b,	/*(腋)*/
	0x814c,	/*(腌)*/
	0x8150,	/*(腐)*/
	0x8151,	/*(腑)*/
	0x8153,	/*(腓)*/
	0x8154,	/*(腔)*/
	0x8155,	/*(腕)*/
	0x8159,	/*(腙)*/
	0x815a,	/*(腚)*/
	0x8160,	/*(腠)*/
	0x8165,	/*(腥)*/
	0x8167,	/*(腧)*/
	0x8169,	/*(腩)*/
	0x816d,	/*(腭)*/
	0x816e,	/*(腮)*/
	0x8170,	/*(腰)*/
	0x8171,	/*(腱)*/
	0x8174,	/*(腴)*/
	0x8179,	/*(腹)*/
	0x817a,	/*(腺)*/
	0x817b,	/*(腻)*/
	0x817c,	/*(腼)*/
	0x817d,	/*(腽)*/
	0x817e,	/*(腾)*/
	0x817f,	/*(腿)*/
	0x8180,	/*(膀)*/
	0x8182,	/*(膂)*/
	0x8188,	/*(膈)*/
	0x818a,	/*(膊)*/
	0x818f,	/*(膏)*/
	0x8191,	/*(膑)*/
	0x8198,	/*(膘)*/
	0x819b,	/*(膛)*/
	0x819c,	/*(膜)*/
	0x819d,	/*(膝)*/
	0x81a3,	/*(膣)*/
	0x81a6,	/*(膦)*/
	0x81a8,	/*(膨)*/
	0x81aa,	/*(膪)*/
	0x81b3,	/*(膳)*/
	0x81ba,	/*(膺)*/
	0x81bb,	/*(膻)*/
	0x81c0,	/*(臀)*/
	0x81c1,	/*(臁)*/
	0x81c2,	/*(臂)*/
	0x81c3,	/*(臃)*/
	0x81c6,	/*(臆)*/
	0x81ca,	/*(臊)*/
	0x81cc,	/*(臌)*/
	0x81e3,	/*(臣)*/
	0x81e7,	/*(臧)*/
	0x81ea,	/*(自)*/
	0x81ec,	/*(臬)*/
	0x81ed,	/*(臭)*/
	0x81f3,	/*(至)*/
	0x81f4,	/*(致)*/
	0x81fb,	/*(臻)*/
	0x81fc,	/*(臼)*/
	0x81fe,	/*(臾)*/
	0x8200,	/*(舀)*/
	0x8201,	/*(舁)*/
	0x8202,	/*(舂)*/
	0x8204,	/*(舄)*/
	0x8205,	/*(舅)*/
	0x8206,	/*(舆)*/
	0x820c,	/*(舌)*/
	0x820d,	/*(舍)*/
	0x8210,	/*(舐)*/
	0x8212,	/*(舒)*/
	0x8214,	/*(舔)*/
	0x821b,	/*(舛)*/
	0x821c,	/*(舜)*/
	0x821e,	/*(舞)*/
	0x821f,	/*(舟)*/
	0x8221,	/*(舡)*/
	0x8222,	/*(舢)*/
	0x8223,	/*(舣)*/
	0x8228,	/*(舨)*/
	0x822a,	/*(航)*/
	0x822b,	/*(舫)*/
	0x822c,	/*(般)*/
	0x822d,	/*(舭)*/
	0x822f,	/*(舯)*/
	0x8230,	/*(舰)*/
	0x8231,	/*(舱)*/
	0x8233,	/*(舳)*/
	0x8234,	/*(舴)*/
	0x8235,	/*(舵)*/
	0x8236,	/*(舶)*/
	0x8237,	/*(舷)*/
	0x8238,	/*(舸)*/
	0x8239,	/*(船)*/
	0x823b,	/*(舻)*/
	0x823e,	/*(舾)*/
	0x8244,	/*(艄)*/
	0x8247,	/*(艇)*/
	0x8249,	/*(艉)*/
	0x824b,	/*(艋)*/
	0x824f,	/*(艏)*/
	0x8258,	/*(艘)*/
	0x825a,	/*(艚)*/
	0x825f,	/*(艟)*/
	0x8268,	/*(艨)*/
	0x826e,	/*(艮)*/
	0x826f,	/*(良)*/
	0x8270,	/*(艰)*/
	0x8272,	/*(色)*/
	0x8273,	/*(艳)*/
	0x8274,	/*(艴)*/
	0x8279,	/*(艹)*/
	0x827a,	/*(艺)*/
	0x827d,	/*(艽)*/
	0x827e,	/*(艾)*/
	0x827f,	/*(艿)*/
	0x8282,	/*(节)*/
	0x8284,	/*(芄)*/
	0x8288,	/*(芈)*/
	0x828a,	/*(芊)*/
	0x828b,	/*(芋)*/
	0x828d,	/*(芍)*/
	0x828e,	/*(芎)*/
	0x828f,	/*(芏)*/
	0x8291,	/*(芑)*/
	0x8292,	/*(芒)*/
	0x8297,	/*(芗)*/
	0x8298,	/*(芘)*/
	0x8299,	/*(芙)*/
	0x829c,	/*(芜)*/
	0x829d,	/*(芝)*/
	0x829f,	/*(芟)*/
	0x82a1,	/*(芡)*/
	0x82a4,	/*(芤)*/
	0x82a5,	/*(芥)*/
	0x82a6,	/*(芦)*/
	0x82a8,	/*(芨)*/
	0x82a9,	/*(芩)*/
	0x82aa,	/*(芪)*/
	0x82ab,	/*(芫)*/
	0x82ac,	/*(芬)*/
	0x82ad,	/*(芭)*/
	0x82ae,	/*(芮)*/
	0x82af,	/*(芯)*/
	0x82b0,	/*(芰)*/
	0x82b1,	/*(花)*/
	0x82b3,	/*(芳)*/
	0x82b4,	/*(芴)*/
	0x82b7,	/*(芷)*/
	0x82b8,	/*(芸)*/
	0x82b9,	/*(芹)*/
	0x82bd,	/*(芽)*/
	0x82be,	/*(芾)*/
	0x82c1,	/*(苁)*/
	0x82c4,	/*(苄)*/
	0x82c7,	/*(苇)*/
	0x82c8,	/*(苈)*/
	0x82ca,	/*(苊)*/
	0x82cb,	/*(苋)*/
	0x82cc,	/*(苌)*/
	0x82cd,	/*(苍)*/
	0x82ce,	/*(苎)*/
	0x82cf,	/*(苏)*/
	0x82d1,	/*(苑)*/
	0x82d2,	/*(苒)*/
	0x82d3,	/*(苓)*/
	0x82d4,	/*(苔)*/
	0x82d5,	/*(苕)*/
	0x82d7,	/*(苗)*/
	0x82d8,	/*(苘)*/
	0x82db,	/*(苛)*/
	0x82dc,	/*(苜)*/
	0x82de,	/*(苞)*/
	0x82df,	/*(苟)*/
	0x82e0,	/*(苠)*/
	0x82e1,	/*(苡)*/
	0x82e3,	/*(苣)*/
	0x82e4,	/*(苤)*/
	0x82e5,	/*(若)*/
	0x82e6,	/*(苦)*/
	0x82eb,	/*(苫)*/
	0x82ef,	/*(苯)*/
	0x82f1,	/*(英)*/
	0x82f4,	/*(苴)*/
	0x82f7,	/*(苷)*/
	0x82f9,	/*(苹)*/
	0x82fb,	/*(苻)*/
	0x8301,	/*(茁)*/
	0x8302,	/*(茂)*/
	0x8303,	/*(范)*/
	0x8304,	/*(茄)*/
	0x8305,	/*(茅)*/
	0x8306,	/*(茆)*/
	0x8307,	/*(茇)*/
	0x8308,	/*(茈)*/
	0x8309,	/*(茉)*/
	0x830c,	/*(茌)*/
	0x830e,	/*(茎)*/
	0x830f,	/*(茏)*/
	0x8311,	/*(茑)*/
	0x8314,	/*(茔)*/
	0x8315,	/*(茕)*/
	0x8317,	/*(茗)*/
	0x831a,	/*(茚)*/
	0x831b,	/*(茛)*/
	0x831c,	/*(茜)*/
	0x8327,	/*(茧)*/
	0x8328,	/*(茨)*/
	0x832b,	/*(茫)*/
	0x832c,	/*(茬)*/
	0x832d,	/*(茭)*/
	0x832f,	/*(茯)*/
	0x8331,	/*(茱)*/
	0x8333,	/*(茳)*/
	0x8334,	/*(茴)*/
	0x8335,	/*(茵)*/
	0x8336,	/*(茶)*/
	0x8338,	/*(茸)*/
	0x8339,	/*(茹)*/
	0x833a,	/*(茺)*/
	0x833c,	/*(茼)*/
	0x8340,	/*(荀)*/
	0x8343,	/*(荃)*/
	0x8346,	/*(荆)*/
	0x8347,	/*(荇)*/
	0x8349,	/*(草)*/
	0x834f,	/*(荏)*/
	0x8350,	/*(荐)*/
	0x8351,	/*(荑)*/
	0x8352,	/*(荒)*/
	0x8354,	/*(荔)*/
	0x835a,	/*(荚)*/
	0x835b,	/*(荛)*/
	0x835c,	/*(荜)*/
	0x835e,	/*(荞)*/
	0x835f,	/*(荟)*/
	0x8360,	/*(荠)*/
	0x8361,	/*(荡)*/
	0x8363,	/*(荣)*/
	0x8364,	/*(荤)*/
	0x8365,	/*(荥)*/
	0x8366,	/*(荦)*/
	0x8367,	/*(荧)*/
	0x8368,	/*(荨)*/
	0x8369,	/*(荩)*/
	0x836a,	/*(荪)*/
	0x836b,	/*(荫)*/
	0x836c,	/*(荬)*/
	0x836d,	/*(荭)*/
	0x836e,	/*(荮)*/
	0x836f,	/*(药)*/
	0x8377,	/*(荷)*/
	0x8378,	/*(荸)*/
	0x837b,	/*(荻)*/
	0x837c,	/*(荼)*/
	0x837d,	/*(荽)*/
	0x8385,	/*(莅)*/
	0x8386,	/*(莆)*/
	0x8389,	/*(莉)*/
	0x838e,	/*(莎)*/
	0x8392,	/*(莒)*/
	0x8393,	/*(莓)*/
	0x8398,	/*(莘)*/
	0x839b,	/*(莛)*/
	0x839c,	/*(莜)*/
	0x839e,	/*(莞)*/
	0x83a0,	/*(莠)*/
	0x83a8,	/*(莨)*/
	0x83a9,	/*(莩)*/
	0x83aa,	/*(莪)*/
	0x83ab,	/*(莫)*/
	0x83b0,	/*(莰)*/
	0x83b1,	/*(莱)*/
	0x83b2,	/*(莲)*/
	0x83b3,	/*(莳)*/
	0x83b4,	/*(莴)*/
	0x83b6,	/*(莶)*/
	0x83b7,	/*(获)*/
	0x83b8,	/*(莸)*/
	0x83b9,	/*(莹)*/
	0x83ba,	/*(莺)*/
	0x83bc,	/*(莼)*/
	0x83bd,	/*(莽)*/
	0x83c0,	/*(菀)*/
	0x83c1,	/*(菁)*/
	0x83c5,	/*(菅)*/
	0x83c7,	/*(菇)*/
	0x83ca,	/*(菊)*/
	0x83cc,	/*(菌)*/
	0x83cf,	/*(菏)*/
	0x83d4,	/*(菔)*/
	0x83d6,	/*(菖)*/
	0x83d8,	/*(菘)*/
	0x83dc,	/*(菜)*/
	0x83dd,	/*(菝)*/
	0x83df,	/*(菟)*/
	0x83e0,	/*(菠)*/
	0x83e1,	/*(菡)*/
	0x83e5,	/*(菥)*/
	0x83e9,	/*(菩)*/
	0x83ea,	/*(菪)*/
	0x83f0,	/*(菰)*/
	0x83f1,	/*(菱)*/
	0x83f2,	/*(菲)*/
	0x83f8,	/*(菸)*/
	0x83f9,	/*(菹)*/
	0x83fd,	/*(菽)*/
	0x8401,	/*(萁)*/
	0x8403,	/*(萃)*/
	0x8404,	/*(萄)*/
	0x8406,	/*(萆)*/
	0x840b,	/*(萋)*/
	0x840c,	/*(萌)*/
	0x840d,	/*(萍)*/
	0x840e,	/*(萎)*/
	0x840f,	/*(萏)*/
	0x8411,	/*(萑)*/
	0x8418,	/*(萘)*/
	0x841c,	/*(萜)*/
	0x841d,	/*(萝)*/
	0x8424,	/*(萤)*/
	0x8425,	/*(营)*/
	0x8426,	/*(萦)*/
	0x8427,	/*(萧)*/
	0x8428,	/*(萨)*/
	0x8431,	/*(萱)*/
	0x8438,	/*(萸)*/
	0x843c,	/*(萼)*/
	0x843d,	/*(落)*/
	0x8446,	/*(葆)*/
	0x8451,	/*(葑)*/
	0x8457,	/*(著)*/
	0x8459,	/*(葙)*/
	0x845a,	/*(葚)*/
	0x845b,	/*(葛)*/
	0x845c,	/*(葜)*/
	0x8461,	/*(葡)*/
	0x8463,	/*(董)*/
	0x8469,	/*(葩)*/
	0x846b,	/*(葫)*/
	0x846c,	/*(葬)*/
	0x846d,	/*(葭)*/
	0x8471,	/*(葱)*/
	0x8473,	/*(葳)*/
	0x8475,	/*(葵)*/
	0x8476,	/*(葶)*/
	0x8478,	/*(葸)*/
	0x847a,	/*(葺)*/
	0x8482,	/*(蒂)*/
	0x8487,	/*(蒇)*/
	0x8488,	/*(蒈)*/
	0x8489,	/*(蒉)*/
	0x848b,	/*(蒋)*/
	0x848c,	/*(蒌)*/
	0x848e,	/*(蒎)*/
	0x8497,	/*(蒗)*/
	0x8499,	/*(蒙)*/
	0x849c,	/*(蒜)*/
	0x84a1,	/*(蒡)*/
	0x84af,	/*(蒯)*/
	0x84b2,	/*(蒲)*/
	0x84b4,	/*(蒴)*/
	0x84b8,	/*(蒸)*/
	0x84b9,	/*(蒹)*/
	0x84ba,	/*(蒺)*/
	0x84bd,	/*(蒽)*/
	0x84bf,	/*(蒿)*/
	0x84c1,	/*(蓁)*/
	0x84c4,	/*(蓄)*/
	0x84c9,	/*(蓉)*/
	0x84ca,	/*(蓊)*/
	0x84cd,	/*(蓍)*/
	0x84d0,	/*(蓐)*/
	0x84d1,	/*(蓑)*/
	0x84d3,	/*(蓓)*/
	0x84d6,	/*(蓖)*/
	0x84dd,	/*(蓝)*/
	0x84df,	/*(蓟)*/
	0x84e0,	/*(蓠)*/
	0x84e3,	/*(蓣)*/
	0x84e5,	/*(蓥)*/
	0x84e6,	/*(蓦)*/
	0x84ec,	/*(蓬)*/
	0x84f0,	/*(蓰)*/
	0x84fc,	/*(蓼)*/
	0x84ff,	/*(蓿)*/
	0x850c,	/*(蔌)*/
	0x8511,	/*(蔑)*/
	0x8513,	/*(蔓)*/
	0x8517,	/*(蔗)*/
	0x851a,	/*(蔚)*/
	0x851f,	/*(蔟)*/
	0x8521,	/*(蔡)*/
	0x852b,	/*(蔫)*/
	0x852c,	/*(蔬)*/
	0x8537,	/*(蔷)*/
	0x8538,	/*(蔸)*/
	0x8539,	/*(蔹)*/
	0x853a,	/*(蔺)*/
	0x853b,	/*(蔻)*/
	0x853c,	/*(蔼)*/
	0x853d,	/*(蔽)*/
	0x8543,	/*(蕃)*/
	0x8548,	/*(蕈)*/
	0x8549,	/*(蕉)*/
	0x854a,	/*(蕊)*/
	0x8556,	/*(蕖)*/
	0x8559,	/*(蕙)*/
	0x855e,	/*(蕞)*/
	0x8564,	/*(蕤)*/
	0x8568,	/*(蕨)*/
	0x8572,	/*(蕲)*/
	0x8574,	/*(蕴)*/
	0x8579,	/*(蕹)*/
	0x857a,	/*(蕺)*/
	0x857b,	/*(蕻)*/
	0x857e,	/*(蕾)*/
	0x8584,	/*(薄)*/
	0x8585,	/*(薅)*/
	0x8587,	/*(薇)*/
	0x858f,	/*(薏)*/
	0x859b,	/*(薛)*/
	0x859c,	/*(薜)*/
	0x85a4,	/*(薤)*/
	0x85a8,	/*(薨)*/
	0x85aa,	/*(薪)*/
	0x85ae,	/*(薮)*/
	0x85af,	/*(薯)*/
	0x85b0,	/*(薰)*/
	0x85b7,	/*(薷)*/
	0x85b9,	/*(薹)*/
	0x85c1,	/*(藁)*/
	0x85c9,	/*(藉)*/
	0x85cf,	/*(藏)*/
	0x85d0,	/*(藐)*/
	0x85d3,	/*(藓)*/
	0x85d5,	/*(藕)*/
	0x85dc,	/*(藜)*/
	0x85e4,	/*(藤)*/
	0x85e9,	/*(藩)*/
	0x85fb,	/*(藻)*/
	0x85ff,	/*(藿)*/
	0x8605,	/*(蘅)*/
	0x8611,	/*(蘑)*/
	0x8616,	/*(蘖)*/
	0x8627,	/*(蘧)*/
	0x8629,	/*(蘩)*/
	0x8638,	/*(蘸)*/
	0x863c,	/*(蘼)*/
	0x864d,	/*(虍)*/
	0x864e,	/*(虎)*/
	0x864f,	/*(虏)*/
	0x8650,	/*(虐)*/
	0x8651,	/*(虑)*/
	0x8654,	/*(虔)*/
	0x865a,	/*(虚)*/
	0x865e,	/*(虞)*/
	0x8662,	/*(虢)*/
	0x866b,	/*(虫)*/
	0x866c,	/*(虬)*/
	0x866e,	/*(虮)*/
	0x8671,	/*(虱)*/
	0x8679,	/*(虹)*/
	0x867a,	/*(虺)*/
	0x867b,	/*(虻)*/
	0x867c,	/*(虼)*/
	0x867d,	/*(虽)*/
	0x867e,	/*(虾)*/
	0x867f,	/*(虿)*/
	0x8680,	/*(蚀)*/
	0x8681,	/*(蚁)*/
	0x8682,	/*(蚂)*/
	0x868a,	/*(蚊)*/
	0x868b,	/*(蚋)*/
	0x868c,	/*(蚌)*/
	0x868d,	/*(蚍)*/
	0x8693,	/*(蚓)*/
	0x8695,	/*(蚕)*/
	0x869c,	/*(蚜)*/
	0x869d,	/*(蚝)*/
	0x86a3,	/*(蚣)*/
	0x86a4,	/*(蚤)*/
	0x86a7,	/*(蚧)*/
	0x86a8,	/*(蚨)*/
	0x86a9,	/*(蚩)*/
	0x86aa,	/*(蚪)*/
	0x86ac,	/*(蚬)*/
	0x86af,	/*(蚯)*/
	0x86b0,	/*(蚰)*/
	0x86b1,	/*(蚱)*/
	0x86b4,	/*(蚴)*/
	0x86b5,	/*(蚵)*/
	0x86b6,	/*(蚶)*/
	0x86ba,	/*(蚺)*/
	0x86c0,	/*(蛀)*/
	0x86c4,	/*(蛄)*/
	0x86c6,	/*(蛆)*/
	0x86c7,	/*(蛇)*/
	0x86c9,	/*(蛉)*/
	0x86ca,	/*(蛊)*/
	0x86cb,	/*(蛋)*/
	0x86ce,	/*(蛎)*/
	0x86cf,	/*(蛏)*/
	0x86d0,	/*(蛐)*/
	0x86d1,	/*(蛑)*/
	0x86d4,	/*(蛔)*/
	0x86d8,	/*(蛘)*/
	0x86d9,	/*(蛙)*/
	0x86db,	/*(蛛)*/
	0x86de,	/*(蛞)*/
	0x86df,	/*(蛟)*/
	0x86e4,	/*(蛤)*/
	0x86e9,	/*(蛩)*/
	0x86ed,	/*(蛭)*/
	0x86ee,	/*(蛮)*/
	0x86f0,	/*(蛰)*/
	0x86f1,	/*(蛱)*/
	0x86f2,	/*(蛲)*/
	0x86f3,	/*(蛳)*/
	0x86f4,	/*(蛴)*/
	0x86f8,	/*(蛸)*/
	0x86f9,	/*(蛹)*/
	0x86fe,	/*(蛾)*/
	0x8700,	/*(蜀)*/
	0x8702,	/*(蜂)*/
	0x8703,	/*(蜃)*/
	0x8707,	/*(蜇)*/
	0x8708,	/*(蜈)*/
	0x8709,	/*(蜉)*/
	0x870a,	/*(蜊)*/
	0x870d,	/*(蜍)*/
	0x8712,	/*(蜒)*/
	0x8713,	/*(蜓)*/
	0x8715,	/*(蜕)*/
	0x8717,	/*(蜗)*/
	0x8718,	/*(蜘)*/
	0x871a,	/*(蜚)*/
	0x871c,	/*(蜜)*/
	0x871e,	/*(蜞)*/
	0x8721,	/*(蜡)*/
	0x8722,	/*(蜢)*/
	0x8723,	/*(蜣)*/
	0x8725,	/*(蜥)*/
	0x8729,	/*(蜩)*/
	0x872e,	/*(蜮)*/
	0x8731,	/*(蜱)*/
	0x8734,	/*(蜴)*/
	0x8737,	/*(蜷)*/
	0x873b,	/*(蜻)*/
	0x873e,	/*(蜾)*/
	0x873f,	/*(蜿)*/
	0x8747,	/*(蝇)*/
	0x8748,	/*(蝈)*/
	0x8749,	/*(蝉)*/
	0x874c,	/*(蝌)*/
	0x874e,	/*(蝎)*/
	0x8753,	/*(蝓)*/
	0x8757,	/*(蝗)*/
	0x8759,	/*(蝙)*/
	0x8760,	/*(蝠)*/
	0x8763,	/*(蝣)*/
	0x8764,	/*(蝤)*/
	0x8765,	/*(蝥)*/
	0x876e,	/*(蝮)*/
	0x8770,	/*(蝰)*/
	0x8774,	/*(蝴)*/
	0x8776,	/*(蝶)*/
	0x877b,	/*(蝻)*/
	0x877c,	/*(蝼)*/
	0x877d,	/*(蝽)*/
	0x877e,	/*(蝾)*/
	0x8782,	/*(螂)*/
	0x8783,	/*(螃)*/
	0x8785,	/*(螅)*/
	0x8788,	/*(螈)*/
	0x878b,	/*(螋)*/
	0x878d,	/*(融)*/
	0x8793,	/*(螓)*/
	0x8797,	/*(螗)*/
	0x879f,	/*(螟)*/
	0x87a8,	/*(螨)*/
	0x87ab,	/*(螫)*/
	0x87ac,	/*(螬)*/
	0x87ad,	/*(螭)*/
	0x87af,	/*(螯)*/
	0x87b3,	/*(螳)*/
	0x87b5,	/*(螵)*/
	0x87ba,	/*(螺)*/
	0x87bd,	/*(螽)*/
	0x87c0,	/*(蟀)*/
	0x87c6,	/*(蟆)*/
	0x87ca,	/*(蟊)*/
	0x87cb,	/*(蟋)*/
	0x87d1,	/*(蟑)*/
	0x87d2,	/*(蟒)*/
	0x87d3,	/*(蟓)*/
	0x87db,	/*(蟛)*/
	0x87e0,	/*(蟠)*/
	0x87e5,	/*(蟥)*/
	0x87ea,	/*(蟪)*/
	0x87ee,	/*(蟮)*/
	0x87f9,	/*(蟹)*/
	0x87fe,	/*(蟾)*/
	0x8803,	/*(蠃)*/
	0x880a,	/*(蠊)*/
	0x8813,	/*(蠓)*/
	0x8815,	/*(蠕)*/
	0x8816,	/*(蠖)*/
	0x881b,	/*(蠛)*/
	0x8821,	/*(蠡)*/
	0x8822,	/*(蠢)*/
	0x8832,	/*(蠲)*/
	0x8839,	/*(蠹)*/
	0x883c,	/*(蠼)*/
	0x8840,	/*(血)*/
	0x8844,	/*(衄)*/
	0x8845,	/*(衅)*/
	0x884c,	/*(行)*/
	0x884d,	/*(衍)*/
	0x8854,	/*(衔)*/
	0x8857,	/*(街)*/
	0x8859,	/*(衙)*/
	0x8861,	/*(衡)*/
	0x8862,	/*(衢)*/
	0x8863,	/*(衣)*/
	0x8864,	/*(衤)*/
	0x8865,	/*(补)*/
	0x8868,	/*(表)*/
	0x8869,	/*(衩)*/
	0x886b,	/*(衫)*/
	0x886c,	/*(衬)*/
	0x886e,	/*(衮)*/
	0x8870,	/*(衰)*/
	0x8872,	/*(衲)*/
	0x8877,	/*(衷)*/
	0x887d,	/*(衽)*/
	0x887e,	/*(衾)*/
	0x887f,	/*(衿)*/
	0x8881,	/*(袁)*/
	0x8882,	/*(袂)*/
	0x8884,	/*(袄)*/
	0x8885,	/*(袅)*/
	0x8888,	/*(袈)*/
	0x888b,	/*(袋)*/
	0x888d,	/*(袍)*/
	0x8892,	/*(袒)*/
	0x8896,	/*(袖)*/
	0x889c,	/*(袜)*/
	0x88a2,	/*(袢)*/
	0x88a4,	/*(袤)*/
	0x88ab,	/*(被)*/
	0x88ad,	/*(袭)*/
	0x88b1,	/*(袱)*/
	0x88b7,	/*(袷)*/
	0x88bc,	/*(袼)*/
	0x88c1,	/*(裁)*/
	0x88c2,	/*(裂)*/
	0x88c5,	/*(装)*/
	0x88c6,	/*(裆)*/
	0x88c9,	/*(裉)*/
	0x88ce,	/*(裎)*/
	0x88d2,	/*(裒)*/
	0x88d4,	/*(裔)*/
	0x88d5,	/*(裕)*/
	0x88d8,	/*(裘)*/
	0x88d9,	/*(裙)*/
	0x88df,	/*(裟)*/
	0x88e2,	/*(裢)*/
	0x88e3,	/*(裣)*/
	0x88e4,	/*(裤)*/
	0x88e5,	/*(裥)*/
	0x88e8,	/*(裨)*/
	0x88f0,	/*(裰)*/
	0x88f1,	/*(裱)*/
	0x88f3,	/*(裳)*/
	0x88f4,	/*(裴)*/
	0x88f8,	/*(裸)*/
	0x88f9,	/*(裹)*/
	0x88fc,	/*(裼)*/
	0x88fe,	/*(裾)*/
	0x8902,	/*(褂)*/
	0x890a,	/*(褊)*/
	0x8910,	/*(褐)*/
	0x8912,	/*(褒)*/
	0x8913,	/*(褓)*/
	0x8919,	/*(褙)*/
	0x891a,	/*(褚)*/
	0x891b,	/*(褛)*/
	0x8921,	/*(褡)*/
	0x8925,	/*(褥)*/
	0x892a,	/*(褪)*/
	0x892b,	/*(褫)*/
	0x8930,	/*(褰)*/
	0x8934,	/*(褴)*/
	0x8936,	/*(褶)*/
	0x8941,	/*(襁)*/
	0x8944,	/*(襄)*/
	0x895e,	/*(襞)*/
	0x895f,	/*(襟)*/
	0x8966,	/*(襦)*/
	0x897b,	/*(襻)*/
	0x897f,	/*(西)*/
	0x8981,	/*(要)*/
	0x8983,	/*(覃)*/
	0x8986,	/*(覆)*/
	0x89c1,	/*(见)*/
	0x89c2,	/*(观)*/
	0x89c4,	/*(规)*/
	0x89c5,	/*(觅)*/
	0x89c6,	/*(视)*/
	0x89c7,	/*(觇)*/
	0x89c8,	/*(览)*/
	0x89c9,	/*(觉)*/
	0x89ca,	/*(觊)*/
	0x89cb,	/*(觋)*/
	0x89cc,	/*(觌)*/
	0x89ce,	/*(觎)*/
	0x89cf,	/*(觏)*/
	0x89d0,	/*(觐)*/
	0x89d1,	/*(觑)*/
	0x89d2,	/*(角)*/
	0x89d6,	/*(觖)*/
	0x89da,	/*(觚)*/
	0x89dc,	/*(觜)*/
	0x89de,	/*(觞)*/
	0x89e3,	/*(解)*/
	0x89e5,	/*(觥)*/
	0x89e6,	/*(触)*/
	0x89eb,	/*(觫)*/
	0x89ef,	/*(觯)*/
	0x89f3,	/*(觳)*/
	0x8a00,	/*(言)*/
	0x8a07,	/*(訇)*/
	0x8a3e,	/*(訾)*/
	0x8a48,	/*(詈)*/
	0x8a79,	/*(詹)*/
	0x8a89,	/*(誉)*/
	0x8a8a,	/*(誊)*/
	0x8a93,	/*(誓)*/
	0x8b07,	/*(謇)*/
	0x8b26,	/*(謦)*/
	0x8b66,	/*(警)*/
	0x8b6c,	/*(譬)*/
	0x8ba0,	/*(讠)*/
	0x8ba1,	/*(计)*/
	0x8ba2,	/*(订)*/
	0x8ba3,	/*(讣)*/
	0x8ba4,	/*(认)*/
	0x8ba5,	/*(讥)*/
	0x8ba6,	/*(讦)*/
	0x8ba7,	/*(讧)*/
	0x8ba8,	/*(讨)*/
	0x8ba9,	/*(让)*/
	0x8baa,	/*(讪)*/
	0x8bab,	/*(讫)*/
	0x8bad,	/*(训)*/
	0x8bae,	/*(议)*/
	0x8baf,	/*(讯)*/
	0x8bb0,	/*(记)*/
	0x8bb2,	/*(讲)*/
	0x8bb3,	/*(讳)*/
	0x8bb4,	/*(讴)*/
	0x8bb5,	/*(讵)*/
	0x8bb6,	/*(讶)*/
	0x8bb7,	/*(讷)*/
	0x8bb8,	/*(许)*/
	0x8bb9,	/*(讹)*/
	0x8bba,	/*(论)*/
	0x8bbc,	/*(讼)*/
	0x8bbd,	/*(讽)*/
	0x8bbe,	/*(设)*/
	0x8bbf,	/*(访)*/
	0x8bc0,	/*(诀)*/
	0x8bc1,	/*(证)*/
	0x8bc2,	/*(诂)*/
	0x8bc3,	/*(诃)*/
	0x8bc4,	/*(评)*/
	0x8bc5,	/*(诅)*/
	0x8bc6,	/*(识)*/
	0x8bc8,	/*(诈)*/
	0x8bc9,	/*(诉)*/
	0x8bca,	/*(诊)*/
	0x8bcb,	/*(诋)*/
	0x8bcc,	/*(诌)*/
	0x8bcd,	/*(词)*/
	0x8bce,	/*(诎)*/
	0x8bcf,	/*(诏)*/
	0x8bd1,	/*(译)*/
	0x8bd2,	/*(诒)*/
	0x8bd3,	/*(诓)*/
	0x8bd4,	/*(诔)*/
	0x8bd5,	/*(试)*/
	0x8bd6,	/*(诖)*/
	0x8bd7,	/*(诗)*/
	0x8bd8,	/*(诘)*/
	0x8bd9,	/*(诙)*/
	0x8bda,	/*(诚)*/
	0x8bdb,	/*(诛)*/
	0x8bdc,	/*(诜)*/
	0x8bdd,	/*(话)*/
	0x8bde,	/*(诞)*/
	0x8bdf,	/*(诟)*/
	0x8be0,	/*(诠)*/
	0x8be1,	/*(诡)*/
	0x8be2,	/*(询)*/
	0x8be3,	/*(诣)*/
	0x8be4,	/*(诤)*/
	0x8be5,	/*(该)*/
	0x8be6,	/*(详)*/
	0x8be7,	/*(诧)*/
	0x8be8,	/*(诨)*/
	0x8be9,	/*(诩)*/
	0x8beb,	/*(诫)*/
	0x8bec,	/*(诬)*/
	0x8bed,	/*(语)*/
	0x8bee,	/*(诮)*/
	0x8bef,	/*(误)*/
	0x8bf0,	/*(诰)*/
	0x8bf1,	/*(诱)*/
	0x8bf2,	/*(诲)*/
	0x8bf3,	/*(诳)*/
	0x8bf4,	/*(说)*/
	0x8bf5,	/*(诵)*/
	0x8bf6,	/*(诶)*/
	0x8bf7,	/*(请)*/
	0x8bf8,	/*(诸)*/
	0x8bf9,	/*(诹)*/
	0x8bfa,	/*(诺)*/
	0x8bfb,	/*(读)*/
	0x8bfc,	/*(诼)*/
	0x8bfd,	/*(诽)*/
	0x8bfe,	/*(课)*/
	0x8bff,	/*(诿)*/
	0x8c00,	/*(谀)*/
	0x8c01,	/*(谁)*/
	0x8c02,	/*(谂)*/
	0x8c03,	/*(调)*/
	0x8c04,	/*(谄)*/
	0x8c05,	/*(谅)*/
	0x8c06,	/*(谆)*/
	0x8c07,	/*(谇)*/
	0x8c08,	/*(谈)*/
	0x8c0a,	/*(谊)*/
	0x8c0b,	/*(谋)*/
	0x8c0c,	/*(谌)*/
	0x8c0d,	/*(谍)*/
	0x8c0e,	/*(谎)*/
	0x8c0f,	/*(谏)*/
	0x8c10,	/*(谐)*/
	0x8c11,	/*(谑)*/
	0x8c12,	/*(谒)*/
	0x8c13,	/*(谓)*/
	0x8c14,	/*(谔)*/
	0x8c15,	/*(谕)*/
	0x8c16,	/*(谖)*/
	0x8c17,	/*(谗)*/
	0x8c18,	/*(谘)*/
	0x8c19,	/*(谙)*/
	0x8c1a,	/*(谚)*/
	0x8c1b,	/*(谛)*/
	0x8c1c,	/*(谜)*/
	0x8c1d,	/*(谝)*/
	0x8c1f,	/*(谟)*/
	0x8c20,	/*(谠)*/
	0x8c21,	/*(谡)*/
	0x8c22,	/*(谢)*/
	0x8c23,	/*(谣)*/
	0x8c24,	/*(谤)*/
	0x8c25,	/*(谥)*/
	0x8c26,	/*(谦)*/
	0x8c27,	/*(谧)*/
	0x8c28,	/*(谨)*/
	0x8c29,	/*(谩)*/
	0x8c2a,	/*(谪)*/
	0x8c2b,	/*(谫)*/
	0x8c2c,	/*(谬)*/
	0x8c2d,	/*(谭)*/
	0x8c2e,	/*(谮)*/
	0x8c2f,	/*(谯)*/
	0x8c30,	/*(谰)*/
	0x8c31,	/*(谱)*/
	0x8c32,	/*(谲)*/
	0x8c33,	/*(谳)*/
	0x8c34,	/*(谴)*/
	0x8c35,	/*(谵)*/
	0x8c36,	/*(谶)*/
	0x8c37,	/*(谷)*/
	0x8c41,	/*(豁)*/
	0x8c46,	/*(豆)*/
	0x8c47,	/*(豇)*/
	0x8c49,	/*(豉)*/
	0x8c4c,	/*(豌)*/
	0x8c55,	/*(豕)*/
	0x8c5a,	/*(豚)*/
	0x8c61,	/*(象)*/
	0x8c62,	/*(豢)*/
	0x8c6a,	/*(豪)*/
	0x8c6b,	/*(豫)*/
	0x8c73,	/*(豳)*/
	0x8c78,	/*(豸)*/
	0x8c79,	/*(豹)*/
	0x8c7a,	/*(豺)*/
	0x8c82,	/*(貂)*/
	0x8c85,	/*(貅)*/
	0x8c89,	/*(貉)*/
	0x8c8a,	/*(貊)*/
	0x8c8c,	/*(貌)*/
	0x8c94,	/*(貔)*/
	0x8c98,	/*(貘)*/
	0x8d1d,	/*(贝)*/
	0x8d1e,	/*(贞)*/
	0x8d1f,	/*(负)*/
	0x8d21,	/*(贡)*/
	0x8d22,	/*(财)*/
	0x8d23,	/*(责)*/
	0x8d24,	/*(贤)*/
	0x8d25,	/*(败)*/
	0x8d26,	/*(账)*/
	0x8d27,	/*(货)*/
	0x8d28,	/*(质)*/
	0x8d29,	/*(贩)*/
	0x8d2a,	/*(贪)*/
	0x8d2b,	/*(贫)*/
	0x8d2c,	/*(贬)*/
	0x8d2d,	/*(购)*/
	0x8d2e,	/*(贮)*/
	0x8d2f,	/*(贯)*/
	0x8d30,	/*(贰)*/
	0x8d31,	/*(贱)*/
	0x8d32,	/*(贲)*/
	0x8d33,	/*(贳)*/
	0x8d34,	/*(贴)*/
	0x8d35,	/*(贵)*/
	0x8d36,	/*(贶)*/
	0x8d37,	/*(贷)*/
	0x8d38,	/*(贸)*/
	0x8d39,	/*(费)*/
	0x8d3a,	/*(贺)*/
	0x8d3b,	/*(贻)*/
	0x8d3c,	/*(贼)*/
	0x8d3d,	/*(贽)*/
	0x8d3e,	/*(贾)*/
	0x8d3f,	/*(贿)*/
	0x8d40,	/*(赀)*/
	0x8d41,	/*(赁)*/
	0x8d42,	/*(赂)*/
	0x8d43,	/*(赃)*/
	0x8d44,	/*(资)*/
	0x8d45,	/*(赅)*/
	0x8d46,	/*(赆)*/
	0x8d47,	/*(赇)*/
	0x8d48,	/*(赈)*/
	0x8d49,	/*(赉)*/
	0x8d4a,	/*(赊)*/
	0x8d4b,	/*(赋)*/
	0x8d4c,	/*(赌)*/
	0x8d4d,	/*(赍)*/
	0x8d4e,	/*(赎)*/
	0x8d4f,	/*(赏)*/
	0x8d50,	/*(赐)*/
	0x8d53,	/*(赓)*/
	0x8d54,	/*(赔)*/
	0x8d55,	/*(赕)*/
	0x8d56,	/*(赖)*/
	0x8d58,	/*(赘)*/
	0x8d59,	/*(赙)*/
	0x8d5a,	/*(赚)*/
	0x8d5b,	/*(赛)*/
	0x8d5c,	/*(赜)*/
	0x8d5d,	/*(赝)*/
	0x8d5e,	/*(赞)*/
	0x8d60,	/*(赠)*/
	0x8d61,	/*(赡)*/
	0x8d62,	/*(赢)*/
	0x8d63,	/*(赣)*/
	0x8d64,	/*(赤)*/
	0x8d66,	/*(赦)*/
	0x8d67,	/*(赧)*/
	0x8d6b,	/*(赫)*/
	0x8d6d,	/*(赭)*/
	0x8d70,	/*(走)*/
	0x8d73,	/*(赳)*/
	0x8d74,	/*(赴)*/
	0x8d75,	/*(赵)*/
	0x8d76,	/*(赶)*/
	0x8d77,	/*(起)*/
	0x8d81,	/*(趁)*/
	0x8d84,	/*(趄)*/
	0x8d85,	/*(超)*/
	0x8d8a,	/*(越)*/
	0x8d8b,	/*(趋)*/
	0x8d91,	/*(趑)*/
	0x8d94,	/*(趔)*/
	0x8d9f,	/*(趟)*/
	0x8da3,	/*(趣)*/
	0x8db1,	/*(趱)*/
	0x8db3,	/*(足)*/
	0x8db4,	/*(趴)*/
	0x8db5,	/*(趵)*/
	0x8db8,	/*(趸)*/
	0x8dba,	/*(趺)*/
	0x8dbc,	/*(趼)*/
	0x8dbe,	/*(趾)*/
	0x8dbf,	/*(趿)*/
	0x8dc3,	/*(跃)*/
	0x8dc4,	/*(跄)*/
	0x8dc6,	/*(跆)*/
	0x8dcb,	/*(跋)*/
	0x8dcc,	/*(跌)*/
	0x8dce,	/*(跎)*/
	0x8dcf,	/*(跏)*/
	0x8dd1,	/*(跑)*/
	0x8dd6,	/*(跖)*/
	0x8dd7,	/*(跗)*/
	0x8dda,	/*(跚)*/
	0x8ddb,	/*(跛)*/
	0x8ddd,	/*(距)*/
	0x8dde,	/*(跞)*/
	0x8ddf,	/*(跟)*/
	0x8de3,	/*(跣)*/
	0x8de4,	/*(跤)*/
	0x8de8,	/*(跨)*/
	0x8dea,	/*(跪)*/
	0x8deb,	/*(跫)*/
	0x8dec,	/*(跬)*/
	0x8def,	/*(路)*/
	0x8df3,	/*(跳)*/
	0x8df5,	/*(践)*/
	0x8df7,	/*(跷)*/
	0x8df8,	/*(跸)*/
	0x8df9,	/*(跹)*/
	0x8dfa,	/*(跺)*/
	0x8dfb,	/*(跻)*/
	0x8dfd,	/*(跽)*/
	0x8e05,	/*(踅)*/
	0x8e09,	/*(踉)*/
	0x8e0a,	/*(踊)*/
	0x8e0c,	/*(踌)*/
	0x8e0f,	/*(踏)*/
	0x8e14,	/*(踔)*/
	0x8e1d,	/*(踝)*/
	0x8e1e,	/*(踞)*/
	0x8e1f,	/*(踟)*/
	0x8e22,	/*(踢)*/
	0x8e23,	/*(踣)*/
	0x8e29,	/*(踩)*/
	0x8e2a,	/*(踪)*/
	0x8e2c,	/*(踬)*/
	0x8e2e,	/*(踮)*/
	0x8e2f,	/*(踯)*/
	0x8e31,	/*(踱)*/
	0x8e35,	/*(踵)*/
	0x8e39,	/*(踹)*/
	0x8e3a,	/*(踺)*/
	0x8e3d,	/*(踽)*/
	0x8e40,	/*(蹀)*/
	0x8e41,	/*(蹁)*/
	0x8e42,	/*(蹂)*/
	0x8e44,	/*(蹄)*/
	0x8e47,	/*(蹇)*/
	0x8e48,	/*(蹈)*/
	0x8e49,	/*(蹉)*/
	0x8e4a,	/*(蹊)*/
	0x8e4b,	/*(蹋)*/
	0x8e51,	/*(蹑)*/
	0x8e52,	/*(蹒)*/
	0x8e59,	/*(蹙)*/
	0x8e66,	/*(蹦)*/
	0x8e69,	/*(蹩)*/
	0x8e6c,	/*(蹬)*/
	0x8e6d,	/*(蹭)*/
	0x8e6f,	/*(蹯)*/
	0x8e70,	/*(蹰)*/
	0x8e72,	/*(蹲)*/
	0x8e74,	/*(蹴)*/
	0x8e76,	/*(蹶)*/
	0x8e7c,	/*(蹼)*/
	0x8e7f,	/*(蹿)*/
	0x8e81,	/*(躁)*/
	0x8e85,	/*(躅)*/
	0x8e87,	/*(躇)*/
	0x8e8f,	/*(躏)*/
	0x8e90,	/*(躐)*/
	0x8e94,	/*(躔)*/
	0x8e9c,	/*(躜)*/
	0x8e9e,	/*(躞)*/
	0x8eab,	/*(身)*/
	0x8eac,	/*(躬)*/
	0x8eaf,	/*(躯)*/
	0x8eb2,	/*(躲)*/
	0x8eba,	/*(躺)*/
	0x8ece,	/*(軎)*/
	0x8f66,	/*(车)*/
	0x8f67,	/*(轧)*/
	0x8f68,	/*(轨)*/
	0x8f69,	/*(轩)*/
	0x8f6b,	/*(轫)*/
	0x8f6c,	/*(转)*/
	0x8f6d,	/*(轭)*/
	0x8f6e,	/*(轮)*/
	0x8f6f,	/*(软)*/
	0x8f70,	/*(轰)*/
	0x8f71,	/*(轱)*/
	0x8f72,	/*(轲)*/
	0x8f73,	/*(轳)*/
	0x8f74,	/*(轴)*/
	0x8f75,	/*(轵)*/
	0x8f76,	/*(轶)*/
	0x8f77,	/*(轷)*/
	0x8f78,	/*(轸)*/
	0x8f79,	/*(轹)*/
	0x8f7a,	/*(轺)*/
	0x8f7b,	/*(轻)*/
	0x8f7c,	/*(轼)*/
	0x8f7d,	/*(载)*/
	0x8f7e,	/*(轾)*/
	0x8f7f,	/*(轿)*/
	0x8f81,	/*(辁)*/
	0x8f82,	/*(辂)*/
	0x8f83,	/*(较)*/
	0x8f84,	/*(辄)*/
	0x8f85,	/*(辅)*/
	0x8f86,	/*(辆)*/
	0x8f87,	/*(辇)*/
	0x8f88,	/*(辈)*/
	0x8f89,	/*(辉)*/
	0x8f8a,	/*(辊)*/
	0x8f8b,	/*(辋)*/
	0x8f8d,	/*(辍)*/
	0x8f8e,	/*(辎)*/
	0x8f8f,	/*(辏)*/
	0x8f90,	/*(辐)*/
	0x8f91,	/*(辑)*/
	0x8f93,	/*(输)*/
	0x8f94,	/*(辔)*/
	0x8f95,	/*(辕)*/
	0x8f96,	/*(辖)*/
	0x8f97,	/*(辗)*/
	0x8f98,	/*(辘)*/
	0x8f99,	/*(辙)*/
	0x8f9a,	/*(辚)*/
	0x8f9b,	/*(辛)*/
	0x8f9c,	/*(辜)*/
	0x8f9e,	/*(辞)*/
	0x8f9f,	/*(辟)*/
	0x8fa3,	/*(辣)*/
	0x8fa8,	/*(辨)*/
	0x8fa9,	/*(辩)*/
	0x8fab,	/*(辫)*/
	0x8fb0,	/*(辰)*/
	0x8fb1,	/*(辱)*/
	0x8fb6,	/*(辶)*/
	0x8fb9,	/*(边)*/
	0x8fbd,	/*(辽)*/
	0x8fbe,	/*(达)*/
	0x8fc1,	/*(迁)*/
	0x8fc2,	/*(迂)*/
	0x8fc4,	/*(迄)*/
	0x8fc5,	/*(迅)*/
	0x8fc7,	/*(过)*/
	0x8fc8,	/*(迈)*/
	0x8fce,	/*(迎)*/
	0x8fd0,	/*(运)*/
	0x8fd1,	/*(近)*/
	0x8fd3,	/*(迓)*/
	0x8fd4,	/*(返)*/
	0x8fd5,	/*(迕)*/
	0x8fd8,	/*(还)*/
	0x8fd9,	/*(这)*/
	0x8fdb,	/*(进)*/
	0x8fdc,	/*(远)*/
	0x8fdd,	/*(违)*/
	0x8fde,	/*(连)*/
	0x8fdf,	/*(迟)*/
	0x8fe2,	/*(迢)*/
	0x8fe4,	/*(迤)*/
	0x8fe5,	/*(迥)*/
	0x8fe6,	/*(迦)*/
	0x8fe8,	/*(迨)*/
	0x8fe9,	/*(迩)*/
	0x8fea,	/*(迪)*/
	0x8feb,	/*(迫)*/
	0x8fed,	/*(迭)*/
	0x8fee,	/*(迮)*/
	0x8ff0,	/*(述)*/
	0x8ff3,	/*(迳)*/
	0x8ff7,	/*(迷)*/
	0x8ff8,	/*(迸)*/
	0x8ff9,	/*(迹)*/
	0x8ffd,	/*(追)*/
	0x9000,	/*(退)*/
	0x9001,	/*(送)*/
	0x9002,	/*(适)*/
	0x9003,	/*(逃)*/
	0x9004,	/*(逄)*/
	0x9005,	/*(逅)*/
	0x9006,	/*(逆)*/
	0x9009,	/*(选)*/
	0x900a,	/*(逊)*/
	0x900b,	/*(逋)*/
	0x900d,	/*(逍)*/
	0x900f,	/*(透)*/
	0x9010,	/*(逐)*/
	0x9011,	/*(逑)*/
	0x9012,	/*(递)*/
	0x9014,	/*(途)*/
	0x9016,	/*(逖)*/
	0x9017,	/*(逗)*/
	0x901a,	/*(通)*/
	0x901b,	/*(逛)*/
	0x901d,	/*(逝)*/
	0x901e,	/*(逞)*/
	0x901f,	/*(速)*/
	0x9020,	/*(造)*/
	0x9021,	/*(逡)*/
	0x9022,	/*(逢)*/
	0x9026,	/*(逦)*/
	0x902d,	/*(逭)*/
	0x902e,	/*(逮)*/
	0x902f,	/*(逯)*/
	0x9035,	/*(逵)*/
	0x9036,	/*(逶)*/
	0x9038,	/*(逸)*/
	0x903b,	/*(逻)*/
	0x903c,	/*(逼)*/
	0x903e,	/*(逾)*/
	0x9041,	/*(遁)*/
	0x9042,	/*(遂)*/
	0x9044,	/*(遄)*/
	0x9047,	/*(遇)*/
	0x904d,	/*(遍)*/
	0x904f,	/*(遏)*/
	0x9050,	/*(遐)*/
	0x9051,	/*(遑)*/
	0x9052,	/*(遒)*/
	0x9053,	/*(道)*/
	0x9057,	/*(遗)*/
	0x9058,	/*(遘)*/
	0x905b,	/*(遛)*/
	0x9062,	/*(遢)*/
	0x9063,	/*(遣)*/
	0x9065,	/*(遥)*/
	0x9068,	/*(遨)*/
	0x906d,	/*(遭)*/
	0x906e,	/*(遮)*/
	0x9074,	/*(遴)*/
	0x9075,	/*(遵)*/
	0x907d,	/*(遽)*/
	0x907f,	/*(避)*/
	0x9080,	/*(邀)*/
	0x9082,	/*(邂)*/
	0x9083,	/*(邃)*/
	0x9088,	/*(邈)*/
	0x908b,	/*(邋)*/
	0x9091,	/*(邑)*/
	0x9093,	/*(邓)*/
	0x9095,	/*(邕)*/
	0x9097,	/*(邗)*/
	0x9099,	/*(邙)*/
	0x909b,	/*(邛)*/
	0x909d,	/*(邝)*/
	0x90a1,	/*(邡)*/
	0x90a2,	/*(邢)*/
	0x90a3,	/*(那)*/
	0x90a6,	/*(邦)*/
	0x90aa,	/*(邪)*/
	0x90ac,	/*(邬)*/
	0x90ae,	/*(邮)*/
	0x90af,	/*(邯)*/
	0x90b0,	/*(邰)*/
	0x90b1,	/*(邱)*/
	0x90b3,	/*(邳)*/
	0x90b4,	/*(邴)*/
	0x90b5,	/*(邵)*/
	0x90b6,	/*(邶)*/
	0x90b8,	/*(邸)*/
	0x90b9,	/*(邹)*/
	0x90ba,	/*(邺)*/
	0x90bb,	/*(邻)*/
	0x90be,	/*(邾)*/
	0x90c1,	/*(郁)*/
	0x90c4,	/*(郄)*/
	0x90c5,	/*(郅)*/
	0x90c7,	/*(郇)*/
	0x90ca,	/*(郊)*/
	0x90ce,	/*(郎)*/
	0x90cf,	/*(郏)*/
	0x90d0,	/*(郐)*/
	0x90d1,	/*(郑)*/
	0x90d3,	/*(郓)*/
	0x90d7,	/*(郗)*/
	0x90db,	/*(郛)*/
	0x90dc,	/*(郜)*/
	0x90dd,	/*(郝)*/
	0x90e1,	/*(郡)*/
	0x90e2,	/*(郢)*/
	0x90e6,	/*(郦)*/
	0x90e7,	/*(郧)*/
	0x90e8,	/*(部)*/
	0x90eb,	/*(郫)*/
	0x90ed,	/*(郭)*/
	0x90ef,	/*(郯)*/
	0x90f4,	/*(郴)*/
	0x90f8,	/*(郸)*/
	0x90fd,	/*(都)*/
	0x90fe,	/*(郾)*/
	0x9102,	/*(鄂)*/
	0x9104,	/*(鄄)*/
	0x9119,	/*(鄙)*/
	0x911e,	/*(鄞)*/
	0x9122,	/*(鄢)*/
	0x9123,	/*(鄣)*/
	0x912f,	/*(鄯)*/
	0x9131,	/*(鄱)*/
	0x9139,	/*(鄹)*/
	0x9143,	/*(酃)*/
	0x9146,	/*(酆)*/
	0x9149,	/*(酉)*/
	0x914a,	/*(酊)*/
	0x914b,	/*(酋)*/
	0x914c,	/*(酌)*/
	0x914d,	/*(配)*/
	0x914e,	/*(酎)*/
	0x914f,	/*(酏)*/
	0x9150,	/*(酐)*/
	0x9152,	/*(酒)*/
	0x9157,	/*(酗)*/
	0x915a,	/*(酚)*/
	0x915d,	/*(酝)*/
	0x915e,	/*(酞)*/
	0x9161,	/*(酡)*/
	0x9162,	/*(酢)*/
	0x9163,	/*(酣)*/
	0x9164,	/*(酤)*/
	0x9165,	/*(酥)*/
	0x9169,	/*(酩)*/
	0x916a,	/*(酪)*/
	0x916c,	/*(酬)*/
	0x916e,	/*(酮)*/
	0x916f,	/*(酯)*/
	0x9170,	/*(酰)*/
	0x9171,	/*(酱)*/
	0x9172,	/*(酲)*/
	0x9174,	/*(酴)*/
	0x9175,	/*(酵)*/
	0x9176,	/*(酶)*/
	0x9177,	/*(酷)*/
	0x9178,	/*(酸)*/
	0x9179,	/*(酹)*/
	0x917d,	/*(酽)*/
	0x917e,	/*(酾)*/
	0x917f,	/*(酿)*/
	0x9185,	/*(醅)*/
	0x9187,	/*(醇)*/
	0x9189,	/*(醉)*/
	0x918b,	/*(醋)*/
	0x918c,	/*(醌)*/
	0x918d,	/*(醍)*/
	0x9190,	/*(醐)*/
	0x9191,	/*(醑)*/
	0x9192,	/*(醒)*/
	0x919a,	/*(醚)*/
	0x919b,	/*(醛)*/
	0x91a2,	/*(醢)*/
	0x91a3,	/*(醣)*/
	0x91aa,	/*(醪)*/
	0x91ad,	/*(醭)*/
	0x91ae,	/*(醮)*/
	0x91af,	/*(醯)*/
	0x91b4,	/*(醴)*/
	0x91b5,	/*(醵)*/
	0x91ba,	/*(醺)*/
	0x91c7,	/*(采)*/
	0x91c9,	/*(釉)*/
	0x91ca,	/*(释)*/
	0x91cc,	/*(里)*/
	0x91cd,	/*(重)*/
	0x91ce,	/*(野)*/
	0x91cf,	/*(量)*/
	0x91d1,	/*(金)*/
	0x91dc,	/*(釜)*/
	0x9274,	/*(鉴)*/
	0x928e,	/*(銎)*/
	0x92ae,	/*(銮)*/
	0x92c8,	/*(鋈)*/
	0x933e,	/*(錾)*/
	0x936a,	/*(鍪)*/
	0x938f,	/*(鎏)*/
	0x93ca,	/*(鏊)*/
	0x93d6,	/*(鏖)*/
	0x943e,	/*(鐾)*/
	0x946b,	/*(鑫)*/
	0x9485,	/*(钅)*/
	0x9486,	/*(钆)*/
	0x9487,	/*(钇)*/
	0x9488,	/*(针)*/
	0x9489,	/*(钉)*/
	0x948a,	/*(钊)*/
	0x948b,	/*(钋)*/
	0x948c,	/*(钌)*/
	0x948d,	/*(钍)*/
	0x948e,	/*(钎)*/
	0x948f,	/*(钏)*/
	0x9490,	/*(钐)*/
	0x9492,	/*(钒)*/
	0x9493,	/*(钓)*/
	0x9494,	/*(钔)*/
	0x9495,	/*(钕)*/
	0x9497,	/*(钗)*/
	0x9499,	/*(钙)*/
	0x949a,	/*(钚)*/
	0x949b,	/*(钛)*/
	0x949c,	/*(钜)*/
	0x949d,	/*(钝)*/
	0x949e,	/*(钞)*/
	0x949f,	/*(钟)*/
	0x94a0,	/*(钠)*/
	0x94a1,	/*(钡)*/
	0x94a2,	/*(钢)*/
	0x94a3,	/*(钣)*/
	0x94a4,	/*(钤)*/
	0x94a5,	/*(钥)*/
	0x94a6,	/*(钦)*/
	0x94a7,	/*(钧)*/
	0x94a8,	/*(钨)*/
	0x94a9,	/*(钩)*/
	0x94aa,	/*(钪)*/
	0x94ab,	/*(钫)*/
	0x94ac,	/*(钬)*/
	0x94ad,	/*(钭)*/
	0x94ae,	/*(钮)*/
	0x94af,	/*(钯)*/
	0x94b0,	/*(钰)*/
	0x94b1,	/*(钱)*/
	0x94b2,	/*(钲)*/
	0x94b3,	/*(钳)*/
	0x94b4,	/*(钴)*/
	0x94b5,	/*(钵)*/
	0x94b6,	/*(钶)*/
	0x94b7,	/*(钷)*/
	0x94b8,	/*(钸)*/
	0x94b9,	/*(钹)*/
	0x94ba,	/*(钺)*/
	0x94bb,	/*(钻)*/
	0x94bc,	/*(钼)*/
	0x94bd,	/*(钽)*/
	0x94be,	/*(钾)*/
	0x94bf,	/*(钿)*/
	0x94c0,	/*(铀)*/
	0x94c1,	/*(铁)*/
	0x94c2,	/*(铂)*/
	0x94c3,	/*(铃)*/
	0x94c4,	/*(铄)*/
	0x94c5,	/*(铅)*/
	0x94c6,	/*(铆)*/
	0x94c8,	/*(铈)*/
	0x94c9,	/*(铉)*/
	0x94ca,	/*(铊)*/
	0x94cb,	/*(铋)*/
	0x94cc,	/*(铌)*/
	0x94cd,	/*(铍)*/
	0x94ce,	/*(铎)*/
	0x94d0,	/*(铐)*/
	0x94d1,	/*(铑)*/
	0x94d2,	/*(铒)*/
	0x94d5,	/*(铕)*/
	0x94d6,	/*(铖)*/
	0x94d7,	/*(铗)*/
	0x94d8,	/*(铘)*/
	0x94d9,	/*(铙)*/
	0x94db,	/*(铛)*/
	0x94dc,	/*(铜)*/
	0x94dd,	/*(铝)*/
	0x94de,	/*(铞)*/
	0x94df,	/*(铟)*/
	0x94e0,	/*(铠)*/
	0x94e1,	/*(铡)*/
	0x94e2,	/*(铢)*/
	0x94e3,	/*(铣)*/
	0x94e4,	/*(铤)*/
	0x94e5,	/*(铥)*/
	0x94e7,	/*(铧)*/
	0x94e8,	/*(铨)*/
	0x94e9,	/*(铩)*/
	0x94ea,	/*(铪)*/
	0x94eb,	/*(铫)*/
	0x94ec,	/*(铬)*/
	0x94ed,	/*(铭)*/
	0x94ee,	/*(铮)*/
	0x94ef,	/*(铯)*/
	0x94f0,	/*(铰)*/
	0x94f1,	/*(铱)*/
	0x94f2,	/*(铲)*/
	0x94f3,	/*(铳)*/
	0x94f4,	/*(铴)*/
	0x94f5,	/*(铵)*/
	0x94f6,	/*(银)*/
	0x94f7,	/*(铷)*/
	0x94f8,	/*(铸)*/
	0x94f9,	/*(铹)*/
	0x94fa,	/*(铺)*/
	0x94fc,	/*(铼)*/
	0x94fd,	/*(铽)*/
	0x94fe,	/*(链)*/
	0x94ff,	/*(铿)*/
	0x9500,	/*(销)*/
	0x9501,	/*(锁)*/
	0x9502,	/*(锂)*/
	0x9503,	/*(锃)*/
	0x9504,	/*(锄)*/
	0x9505,	/*(锅)*/
	0x9506,	/*(锆)*/
	0x9507,	/*(锇)*/
	0x9508,	/*(锈)*/
	0x9509,	/*(锉)*/
	0x950a,	/*(锊)*/
	0x950b,	/*(锋)*/
	0x950c,	/*(锌)*/
	0x950d,	/*(锍)*/
	0x950e,	/*(锎)*/
	0x950f,	/*(锏)*/
	0x9510,	/*(锐)*/
	0x9511,	/*(锑)*/
	0x9512,	/*(锒)*/
	0x9513,	/*(锓)*/
	0x9514,	/*(锔)*/
	0x9515,	/*(锕)*/
	0x9516,	/*(锖)*/
	0x9517,	/*(锗)*/
	0x9518,	/*(锘)*/
	0x9519,	/*(错)*/
	0x951a,	/*(锚)*/
	0x951b,	/*(锛)*/
	0x951d,	/*(锝)*/
	0x951e,	/*(锞)*/
	0x951f,	/*(锟)*/
	0x9521,	/*(锡)*/
	0x9522,	/*(锢)*/
	0x9523,	/*(锣)*/
	0x9524,	/*(锤)*/
	0x9525,	/*(锥)*/
	0x9526,	/*(锦)*/
	0x9528,	/*(锨)*/
	0x9529,	/*(锩)*/
	0x952a,	/*(锪)*/
	0x952b,	/*(锫)*/
	0x952c,	/*(锬)*/
	0x952d,	/*(锭)*/
	0x952e,	/*(键)*/
	0x952f,	/*(锯)*/
	0x9530,	/*(锰)*/
	0x9531,	/*(锱)*/
	0x9532,	/*(锲)*/
	0x9534,	/*(锴)*/
	0x9535,	/*(锵)*/
	0x9536,	/*(锶)*/
	0x9537,	/*(锷)*/
	0x9538,	/*(锸)*/
	0x9539,	/*(锹)*/
	0x953a,	/*(锺)*/
	0x953b,	/*(锻)*/
	0x953c,	/*(锼)*/
	0x953e,	/*(锾)*/
	0x953f,	/*(锿)*/
	0x9540,	/*(镀)*/
	0x9541,	/*(镁)*/
	0x9542,	/*(镂)*/
	0x9544,	/*(镄)*/
	0x9545,	/*(镅)*/
	0x9546,	/*(镆)*/
	0x9547,	/*(镇)*/
	0x9549,	/*(镉)*/
	0x954a,	/*(镊)*/
	0x954c,	/*(镌)*/
	0x954d,	/*(镍)*/
	0x954e,	/*(镎)*/
	0x954f,	/*(镏)*/
	0x9550,	/*(镐)*/
	0x9551,	/*(镑)*/
	0x9552,	/*(镒)*/
	0x9553,	/*(镓)*/
	0x9554,	/*(镔)*/
	0x9556,	/*(镖)*/
	0x9557,	/*(镗)*/
	0x9558,	/*(镘)*/
	0x9559,	/*(镙)*/
	0x955b,	/*(镛)*/
	0x955c,	/*(镜)*/
	0x955d,	/*(镝)*/
	0x955e,	/*(镞)*/
	0x955f,	/*(镟)*/
	0x9561,	/*(镡)*/
	0x9562,	/*(镢)*/
	0x9563,	/*(镣)*/
	0x9564,	/*(镤)*/
	0x9565,	/*(镥)*/
	0x9566,	/*(镦)*/
	0x9567,	/*(镧)*/
	0x9568,	/*(镨)*/
	0x9569,	/*(镩)*/
	0x956a,	/*(镪)*/
	0x956b,	/*(镫)*/
	0x956c,	/*(镬)*/
	0x956d,	/*(镭)*/
	0x956f,	/*(镯)*/
	0x9570,	/*(镰)*/
	0x9571,	/*(镱)*/
	0x9572,	/*(镲)*/
	0x9573,	/*(镳)*/
	0x9576,	/*(镶)*/
	0x957f,	/*(长)*/
	0x95e8,	/*(门)*/
	0x95e9,	/*(闩)*/
	0x95ea,	/*(闪)*/
	0x95eb,	/*(闫)*/
	0x95ed,	/*(闭)*/
	0x95ee,	/*(问)*/
	0x95ef,	/*(闯)*/
	0x95f0,	/*(闰)*/
	0x95f1,	/*(闱)*/
	0x95f2,	/*(闲)*/
	0x95f3,	/*(闳)*/
	0x95f4,	/*(间)*/
	0x95f5,	/*(闵)*/
	0x95f6,	/*(闶)*/
	0x95f7,	/*(闷)*/
	0x95f8,	/*(闸)*/
	0x95f9,	/*(闹)*/
	0x95fa,	/*(闺)*/
	0x95fb,	/*(闻)*/
	0x95fc,	/*(闼)*/
	0x95fd,	/*(闽)*/
	0x95fe,	/*(闾)*/
	0x9600,	/*(阀)*/
	0x9601,	/*(阁)*/
	0x9602,	/*(阂)*/
	0x9603,	/*(阃)*/
	0x9604,	/*(阄)*/
	0x9605,	/*(阅)*/
	0x9606,	/*(阆)*/
	0x9608,	/*(阈)*/
	0x9609,	/*(阉)*/
	0x960a,	/*(阊)*/
	0x960b,	/*(阋)*/
	0x960c,	/*(阌)*/
	0x960d,	/*(阍)*/
	0x960e,	/*(阎)*/
	0x960f,	/*(阏)*/
	0x9610,	/*(阐)*/
	0x9611,	/*(阑)*/
	0x9612,	/*(阒)*/
	0x9614,	/*(阔)*/
	0x9615,	/*(阕)*/
	0x9616,	/*(阖)*/
	0x9617,	/*(阗)*/
	0x9619,	/*(阙)*/
	0x961a,	/*(阚)*/
	0x961c,	/*(阜)*/
	0x961d,	/*(阝)*/
	0x961f,	/*(队)*/
	0x9621,	/*(阡)*/
	0x9622,	/*(阢)*/
	0x962a,	/*(阪)*/
	0x962e,	/*(阮)*/
	0x9631,	/*(阱)*/
	0x9632,	/*(防)*/
	0x9633,	/*(阳)*/
	0x9634,	/*(阴)*/
	0x9635,	/*(阵)*/
	0x9636,	/*(阶)*/
	0x963b,	/*(阻)*/
	0x963c,	/*(阼)*/
	0x963d,	/*(阽)*/
	0x963f,	/*(阿)*/
	0x9640,	/*(陀)*/
	0x9642,	/*(陂)*/
	0x9644,	/*(附)*/
	0x9645,	/*(际)*/
	0x9646,	/*(陆)*/
	0x9647,	/*(陇)*/
	0x9648,	/*(陈)*/
	0x9649,	/*(陉)*/
	0x964b,	/*(陋)*/
	0x964c,	/*(陌)*/
	0x964d,	/*(降)*/
	0x9650,	/*(限)*/
	0x9654,	/*(陔)*/
	0x9655,	/*(陕)*/
	0x965b,	/*(陛)*/
	0x965f,	/*(陟)*/
	0x9661,	/*(陡)*/
	0x9662,	/*(院)*/
	0x9664,	/*(除)*/
	0x9667,	/*(陧)*/
	0x9668,	/*(陨)*/
	0x9669,	/*(险)*/
	0x966a,	/*(陪)*/
	0x966c,	/*(陬)*/
	0x9672,	/*(陲)*/
	0x9674,	/*(陴)*/
	0x9675,	/*(陵)*/
	0x9676,	/*(陶)*/
	0x9677,	/*(陷)*/
	0x9685,	/*(隅)*/
	0x9686,	/*(隆)*/
	0x9688,	/*(隈)*/
	0x968b,	/*(隋)*/
	0x968d,	/*(隍)*/
	0x968f,	/*(随)*/
	0x9690,	/*(隐)*/
	0x9694,	/*(隔)*/
	0x9697,	/*(隗)*/
	0x9698,	/*(隘)*/
	0x9699,	/*(隙)*/
	0x969c,	/*(障)*/
	0x96a7,	/*(隧)*/
	0x96b0,	/*(隰)*/
	0x96b3,	/*(隳)*/
	0x96b6,	/*(隶)*/
	0x96b9,	/*(隹)*/
	0x96bc,	/*(隼)*/
	0x96bd,	/*(隽)*/
	0x96be,	/*(难)*/
	0x96c0,	/*(雀)*/
	0x96c1,	/*(雁)*/
	0x96c4,	/*(雄)*/
	0x96c5,	/*(雅)*/
	0x96c6,	/*(集)*/
	0x96c7,	/*(雇)*/
	0x96c9,	/*(雉)*/
	0x96cc,	/*(雌)*/
	0x96cd,	/*(雍)*/
	0x96ce,	/*(雎)*/
	0x96cf,	/*(雏)*/
	0x96d2,	/*(雒)*/
	0x96d5,	/*(雕)*/
	0x96e0,	/*(雠)*/
	0x96e8,	/*(雨)*/
	0x96e9,	/*(雩)*/
	0x96ea,	/*(雪)*/
	0x96ef,	/*(雯)*/
	0x96f3,	/*(雳)*/
	0x96f6,	/*(零)*/
	0x96f7,	/*(雷)*/
	0x96f9,	/*(雹)*/
	0x96fe,	/*(雾)*/
	0x9700,	/*(需)*/
	0x9701,	/*(霁)*/
	0x9704,	/*(霄)*/
	0x9706,	/*(霆)*/
	0x9707,	/*(震)*/
	0x9708,	/*(霈)*/
	0x9709,	/*(霉)*/
	0x970d,	/*(霍)*/
	0x970e,	/*(霎)*/
	0x970f,	/*(霏)*/
	0x9713,	/*(霓)*/
	0x9716,	/*(霖)*/
	0x971c,	/*(霜)*/
	0x971e,	/*(霞)*/
	0x972a,	/*(霪)*/
	0x972d,	/*(霭)*/
	0x9730,	/*(霰)*/
	0x9732,	/*(露)*/
	0x9738,	/*(霸)*/
	0x9739,	/*(霹)*/
	0x973e,	/*(霾)*/
	0x9752,	/*(青)*/
	0x9753,	/*(靓)*/
	0x9756,	/*(靖)*/
	0x9759,	/*(静)*/
	0x975b,	/*(靛)*/
	0x975e,	/*(非)*/
	0x9760,	/*(靠)*/
	0x9761,	/*(靡)*/
	0x9762,	/*(面)*/
	0x9765,	/*(靥)*/
	0x9769,	/*(革)*/
	0x9773,	/*(靳)*/
	0x9774,	/*(靴)*/
	0x9776,	/*(靶)*/
	0x977c,	/*(靼)*/
	0x9785,	/*(鞅)*/
	0x978b,	/*(鞋)*/
	0x978d,	/*(鞍)*/
	0x9791,	/*(鞑)*/
	0x9792,	/*(鞒)*/
	0x9794,	/*(鞔)*/
	0x9798,	/*(鞘)*/
	0x97a0,	/*(鞠)*/
	0x97a3,	/*(鞣)*/
	0x97ab,	/*(鞫)*/
	0x97ad,	/*(鞭)*/
	0x97af,	/*(鞯)*/
	0x97b2,	/*(鞲)*/
	0x97b4,	/*(鞴)*/
	0x97e6,	/*(韦)*/
	0x97e7,	/*(韧)*/
	0x97e9,	/*(韩)*/
	0x97ea,	/*(韪)*/
	0x97eb,	/*(韫)*/
	0x97ec,	/*(韬)*/
	0x97ed,	/*(韭)*/
	0x97f3,	/*(音)*/
	0x97f5,	/*(韵)*/
	0x97f6,	/*(韶)*/
	0x9875,	/*(页)*/
	0x9876,	/*(顶)*/
	0x9877,	/*(顷)*/
	0x9878,	/*(顸)*/
	0x9879,	/*(项)*/
	0x987a,	/*(顺)*/
	0x987b,	/*(须)*/
	0x987c,	/*(顼)*/
	0x987d,	/*(顽)*/
	0x987e,	/*(顾)*/
	0x987f,	/*(顿)*/
	0x9880,	/*(颀)*/
	0x9881,	/*(颁)*/
	0x9882,	/*(颂)*/
	0x9883,	/*(颃)*/
	0x9884,	/*(预)*/
	0x9885,	/*(颅)*/
	0x9886,	/*(领)*/
	0x9887,	/*(颇)*/
	0x9888,	/*(颈)*/
	0x9889,	/*(颉)*/
	0x988a,	/*(颊)*/
	0x988c,	/*(颌)*/
	0x988d,	/*(颍)*/
	0x988f,	/*(颏)*/
	0x9890,	/*(颐)*/
	0x9891,	/*(频)*/
	0x9893,	/*(颓)*/
	0x9894,	/*(颔)*/
	0x9896,	/*(颖)*/
	0x9897,	/*(颗)*/
	0x9898,	/*(题)*/
	0x989a,	/*(颚)*/
	0x989b,	/*(颛)*/
	0x989c,	/*(颜)*/
	0x989d,	/*(额)*/
	0x989e,	/*(颞)*/
	0x989f,	/*(颟)*/
	0x98a0,	/*(颠)*/
	0x98a1,	/*(颡)*/
	0x98a2,	/*(颢)*/
	0x98a4,	/*(颤)*/
	0x98a5,	/*(颥)*/
	0x98a6,	/*(颦)*/
	0x98a7,	/*(颧)*/
	0x98ce,	/*(风)*/
	0x98d1,	/*(飑)*/
	0x98d2,	/*(飒)*/
	0x98d3,	/*(飓)*/
	0x98d5,	/*(飕)*/
	0x98d8,	/*(飘)*/
	0x98d9,	/*(飙)*/
	0x98da,	/*(飚)*/
	0x98de,	/*(飞)*/
	0x98df,	/*(食)*/
	0x98e7,	/*(飧)*/
	0x98e8,	/*(飨)*/
	0x990d,	/*(餍)*/
	0x9910,	/*(餐)*/
	0x992e,	/*(餮)*/
	0x9954,	/*(饔)*/
	0x9955,	/*(饕)*/
	0x9963,	/*(饣)*/
	0x9965,	/*(饥)*/
	0x9967,	/*(饧)*/
	0x9968,	/*(饨)*/
	0x9969,	/*(饩)*/
	0x996a,	/*(饪)*/
	0x996b,	/*(饫)*/
	0x996c,	/*(饬)*/
	0x996d,	/*(饭)*/
	0x996e,	/*(饮)*/
	0x996f,	/*(饯)*/
	0x9970,	/*(饰)*/
	0x9971,	/*(饱)*/
	0x9972,	/*(饲)*/
	0x9974,	/*(饴)*/
	0x9975,	/*(饵)*/
	0x9976,	/*(饶)*/
	0x9977,	/*(饷)*/
	0x997a,	/*(饺)*/
	0x997c,	/*(饼)*/
	0x997d,	/*(饽)*/
	0x997f,	/*(饿)*/
	0x9980,	/*(馀)*/
	0x9981,	/*(馁)*/
	0x9984,	/*(馄)*/
	0x9985,	/*(馅)*/
	0x9986,	/*(馆)*/
	0x9987,	/*(馇)*/
	0x9988,	/*(馈)*/
	0x998a,	/*(馊)*/
	0x998b,	/*(馋)*/
	0x998d,	/*(馍)*/
	0x998f,	/*(馏)*/
	0x9990,	/*(馐)*/
	0x9991,	/*(馑)*/
	0x9992,	/*(馒)*/
	0x9993,	/*(馓)*/
	0x9994,	/*(馔)*/
	0x9995,	/*(馕)*/
	0x9996,	/*(首)*/
	0x9997,	/*(馗)*/
	0x9998,	/*(馘)*/
	0x9999,	/*(香)*/
	0x99a5,	/*(馥)*/
	0x99a8,	/*(馨)*/
	0x9a6c,	/*(马)*/
	0x9a6d,	/*(驭)*/
	0x9a6e,	/*(驮)*/
	0x9a6f,	/*(驯)*/
	0x9a70,	/*(驰)*/
	0x9a71,	/*(驱)*/
	0x9a73,	/*(驳)*/
	0x9a74,	/*(驴)*/
	0x9a75,	/*(驵)*/
	0x9a76,	/*(驶)*/
	0x9a77,	/*(驷)*/
	0x9a78,	/*(驸)*/
	0x9a79,	/*(驹)*/
	0x9a7a,	/*(驺)*/
	0x9a7b,	/*(驻)*/
	0x9a7c,	/*(驼)*/
	0x9a7d,	/*(驽)*/
	0x9a7e,	/*(驾)*/
	0x9a7f,	/*(驿)*/
	0x9a80,	/*(骀)*/
	0x9a81,	/*(骁)*/
	0x9a82,	/*(骂)*/
	0x9a84,	/*(骄)*/
	0x9a85,	/*(骅)*/
	0x9a86,	/*(骆)*/
	0x9a87,	/*(骇)*/
	0x9a88,	/*(骈)*/
	0x9a8a,	/*(骊)*/
	0x9a8b,	/*(骋)*/
	0x9a8c,	/*(验)*/
	0x9a8f,	/*(骏)*/
	0x9a90,	/*(骐)*/
	0x9a91,	/*(骑)*/
	0x9a92,	/*(骒)*/
	0x9a93,	/*(骓)*/
	0x9a96,	/*(骖)*/
	0x9a97,	/*(骗)*/
	0x9a98,	/*(骘)*/
	0x9a9a,	/*(骚)*/
	0x9a9b,	/*(骛)*/
	0x9a9c,	/*(骜)*/
	0x9a9d,	/*(骝)*/
	0x9a9e,	/*(骞)*/
	0x9a9f,	/*(骟)*/
	0x9aa0,	/*(骠)*/
	0x9aa1,	/*(骡)*/
	0x9aa2,	/*(骢)*/
	0x9aa3,	/*(骣)*/
	0x9aa4,	/*(骤)*/
	0x9aa5,	/*(骥)*/
	0x9aa7,	/*(骧)*/
	0x9aa8,	/*(骨)*/
	0x9ab0,	/*(骰)*/
	0x9ab1,	/*(骱)*/
	0x9ab6,	/*(骶)*/
	0x9ab7,	/*(骷)*/
	0x9ab8,	/*(骸)*/
	0x9aba,	/*(骺)*/
	0x9abc,	/*(骼)*/
	0x9ac0,	/*(髀)*/
	0x9ac1,	/*(髁)*/
	0x9ac2,	/*(髂)*/
	0x9ac5,	/*(髅)*/
	0x9acb,	/*(髋)*/
	0x9acc,	/*(髌)*/
	0x9ad1,	/*(髑)*/
	0x9ad3,	/*(髓)*/
	0x9ad8,	/*(高)*/
	0x9adf,	/*(髟)*/
	0x9ae1,	/*(髡)*/
	0x9ae6,	/*(髦)*/
	0x9aeb,	/*(髫)*/
	0x9aed,	/*(髭)*/
	0x9aef,	/*(髯)*/
	0x9af9,	/*(髹)*/
	0x9afb,	/*(髻)*/
	0x9b03,	/*(鬃)*/
	0x9b08,	/*(鬈)*/
	0x9b0f,	/*(鬏)*/
	0x9b13,	/*(鬓)*/
	0x9b1f,	/*(鬟)*/
	0x9b23,	/*(鬣)*/
	0x9b2f,	/*(鬯)*/
	0x9b32,	/*(鬲)*/
	0x9b3b,	/*(鬻)*/
	0x9b3c,	/*(鬼)*/
	0x9b41,	/*(魁)*/
	0x9b42,	/*(魂)*/
	0x9b43,	/*(魃)*/
	0x9b44,	/*(魄)*/
	0x9b45,	/*(魅)*/
	0x9b47,	/*(魇)*/
	0x9b48,	/*(魈)*/
	0x9b49,	/*(魉)*/
	0x9b4d,	/*(魍)*/
	0x9b4f,	/*(魏)*/
	0x9b51,	/*(魑)*/
	0x9b54,	/*(魔)*/
	0x9c7c,	/*(鱼)*/
	0x9c7f,	/*(鱿)*/
	0x9c81,	/*(鲁)*/
	0x9c82,	/*(鲂)*/
	0x9c85,	/*(鲅)*/
	0x9c86,	/*(鲆)*/
	0x9c87,	/*(鲇)*/
	0x9c88,	/*(鲈)*/
	0x9c8b,	/*(鲋)*/
	0x9c8d,	/*(鲍)*/
	0x9c8e,	/*(鲎)*/
	0x9c90,	/*(鲐)*/
	0x9c91,	/*(鲑)*/
	0x9c92,	/*(鲒)*/
	0x9c94,	/*(鲔)*/
	0x9c95,	/*(鲕)*/
	0x9c9a,	/*(鲚)*/
	0x9c9b,	/*(鲛)*/
	0x9c9c,	/*(鲜)*/
	0x9c9e,	/*(鲞)*/
	0x9c9f,	/*(鲟)*/
	0x9ca0,	/*(鲠)*/
	0x9ca1,	/*(鲡)*/
	0x9ca2,	/*(鲢)*/
	0x9ca3,	/*(鲣)*/
	0x9ca4,	/*(鲤)*/
	0x9ca5,	/*(鲥)*/
	0x9ca6,	/*(鲦)*/
	0x9ca7,	/*(鲧)*/
	0x9ca8,	/*(鲨)*/
	0x9ca9,	/*(鲩)*/
	0x9cab,	/*(鲫)*/
	0x9cad,	/*(鲭)*/
	0x9cae,	/*(鲮)*/
	0x9cb0,	/*(鲰)*/
	0x9cb1,	/*(鲱)*/
	0x9cb2,	/*(鲲)*/
	0x9cb3,	/*(鲳)*/
	0x9cb4,	/*(鲴)*/
	0x9cb5,	/*(鲵)*/
	0x9cb6,	/*(鲶)*/
	0x9cb7,	/*(鲷)*/
	0x9cb8,	/*(鲸)*/
	0x9cba,	/*(鲺)*/
	0x9cbb,	/*(鲻)*/
	0x9cbc,	/*(鲼)*/
	0x9cbd,	/*(鲽)*/
	0x9cc3,	/*(鳃)*/
	0x9cc4,	/*(鳄)*/
	0x9cc5,	/*(鳅)*/
	0x9cc6,	/*(鳆)*/
	0x9cc7,	/*(鳇)*/
	0x9cca,	/*(鳊)*/
	0x9ccb,	/*(鳋)*/
	0x9ccc,	/*(鳌)*/
	0x9ccd,	/*(鳍)*/
	0x9cce,	/*(鳎)*/
	0x9ccf,	/*(鳏)*/
	0x9cd0,	/*(鳐)*/
	0x9cd3,	/*(鳓)*/
	0x9cd4,	/*(鳔)*/
	0x9cd5,	/*(鳕)*/
	0x9cd6,	/*(鳖)*/
	0x9cd7,	/*(鳗)*/
	0x9cd8,	/*(鳘)*/
	0x9cd9,	/*(鳙)*/
	0x9cdc,	/*(鳜)*/
	0x9cdd,	/*(鳝)*/
	0x9cde,	/*(鳞)*/
	0x9cdf,	/*(鳟)*/
	0x9ce2,	/*(鳢)*/
	0x9e1f,	/*(鸟)*/
	0x9e20,	/*(鸠)*/
	0x9e21,	/*(鸡)*/
	0x9e22,	/*(鸢)*/
	0x9e23,	/*(鸣)*/
	0x9e25,	/*(鸥)*/
	0x9e26,	/*(鸦)*/
	0x9e28,	/*(鸨)*/
	0x9e29,	/*(鸩)*/
	0x9e2a,	/*(鸪)*/
	0x9e2b,	/*(鸫)*/
	0x9e2c,	/*(鸬)*/
	0x9e2d,	/*(鸭)*/
	0x9e2f,	/*(鸯)*/
	0x9e31,	/*(鸱)*/
	0x9e32,	/*(鸲)*/
	0x9e33,	/*(鸳)*/
	0x9e35,	/*(鸵)*/
	0x9e36,	/*(鸶)*/
	0x9e37,	/*(鸷)*/
	0x9e38,	/*(鸸)*/
	0x9e39,	/*(鸹)*/
	0x9e3a,	/*(鸺)*/
	0x9e3d,	/*(鸽)*/
	0x9e3e,	/*(鸾)*/
	0x9e3f,	/*(鸿)*/
	0x9e41,	/*(鹁)*/
	0x9e42,	/*(鹂)*/
	0x9e43,	/*(鹃)*/
	0x9e44,	/*(鹄)*/
	0x9e45,	/*(鹅)*/
	0x9e46,	/*(鹆)*/
	0x9e47,	/*(鹇)*/
	0x9e48,	/*(鹈)*/
	0x9e49,	/*(鹉)*/
	0x9e4a,	/*(鹊)*/
	0x9e4b,	/*(鹋)*/
	0x9e4c,	/*(鹌)*/
	0x9e4e,	/*(鹎)*/
	0x9e4f,	/*(鹏)*/
	0x9e51,	/*(鹑)*/
	0x9e55,	/*(鹕)*/
	0x9e57,	/*(鹗)*/
	0x9e58,	/*(鹘)*/
	0x9e5a,	/*(鹚)*/
	0x9e5b,	/*(鹛)*/
	0x9e5c,	/*(鹜)*/
	0x9e5e,	/*(鹞)*/
	0x9e63,	/*(鹣)*/
	0x9e64,	/*(鹤)*/
	0x9e66,	/*(鹦)*/
	0x9e67,	/*(鹧)*/
	0x9e68,	/*(鹨)*/
	0x9e69,	/*(鹩)*/
	0x9e6a,	/*(鹪)*/
	0x9e6b,	/*(鹫)*/
	0x9e6c,	/*(鹬)*/
	0x9e6d,	/*(鹭)*/
	0x9e70,	/*(鹰)*/
	0x9e71,	/*(鹱)*/
	0x9e73,	/*(鹳)*/
	0x9e7e,	/*(鹾)*/
	0x9e7f,	/*(鹿)*/
	0x9e82,	/*(麂)*/
	0x9e87,	/*(麇)*/
	0x9e88,	/*(麈)*/
	0x9e8b,	/*(麋)*/
	0x9e92,	/*(麒)*/
	0x9e93,	/*(麓)*/
	0x9e9d,	/*(麝)*/
	0x9e9f,	/*(麟)*/
	0x9ea6,	/*(麦)*/
	0x9eb4,	/*(麴)*/
	0x9eb8,	/*(麸)*/
	0x9ebb,	/*(麻)*/
	0x9ebd,	/*(麽)*/
	0x9ebe,	/*(麾)*/
	0x9ec4,	/*(黄)*/
	0x9ec9,	/*(黉)*/
	0x9ecd,	/*(黍)*/
	0x9ece,	/*(黎)*/
	0x9ecf,	/*(黏)*/
	0x9ed1,	/*(黑)*/
	0x9ed4,	/*(黔)*/
	0x9ed8,	/*(默)*/
	0x9edb,	/*(黛)*/
	0x9edc,	/*(黜)*/
	0x9edd,	/*(黝)*/
	0x9edf,	/*(黟)*/
	0x9ee0,	/*(黠)*/
	0x9ee2,	/*(黢)*/
	0x9ee5,	/*(黥)*/
	0x9ee7,	/*(黧)*/
	0x9ee9,	/*(黩)*/
	0x9eea,	/*(黪)*/
	0x9eef,	/*(黯)*/
	0x9ef9,	/*(黹)*/
	0x9efb,	/*(黻)*/
	0x9efc,	/*(黼)*/
	0x9efe,	/*(黾)*/
	0x9f0b,	/*(鼋)*/
	0x9f0d,	/*(鼍)*/
	0x9f0e,	/*(鼎)*/
	0x9f10,	/*(鼐)*/
	0x9f13,	/*(鼓)*/
	0x9f17,	/*(鼗)*/
	0x9f19,	/*(鼙)*/
	0x9f20,	/*(鼠)*/
	0x9f22,	/*(鼢)*/
	0x9f2c,	/*(鼬)*/
	0x9f2f,	/*(鼯)*/
	0x9f37,	/*(鼷)*/
	0x9f39,	/*(鼹)*/
	0x9f3b,	/*(鼻)*/
	0x9f3d,	/*(鼽)*/
	0x9f3e,	/*(鼾)*/
	0x9f44,	/*(齄)*/
	0x9f50,	/*(齐)*/
	0x9f51,	/*(齑)*/
	0x9f7f,	/*(齿)*/
	0x9f80,	/*(龀)*/
	0x9f83,	/*(龃)*/
	0x9f84,	/*(龄)*/
	0x9f85,	/*(龅)*/
	0x9f86,	/*(龆)*/
	0x9f87,	/*(龇)*/
	0x9f88,	/*(龈)*/
	0x9f89,	/*(龉)*/
	0x9f8a,	/*(龊)*/
	0x9f8b,	/*(龋)*/
	0x9f8c,	/*(龌)*/
	0x9f99,	/*(龙)*/
	0x9f9a,	/*(龚)*/
	0x9f9b,	/*(龛)*/
	0x9f9f,	/*(龟)*/
	0x9fa0,	/*(龠)*/
	0xe810,	/*()*/
	0xe811,	/*()*/
	0xe812,	/*()*/
	0xe813,	/*()*/
	0xe814,	/*()*/
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
	0xff01,	/*(！)*/
	0xff08,	/*(（)*/
	0xff09,	/*(）)*/
	0xff0c,	/*(，)*/
	0xff1a,	/*(：)*/
	0xff1b,	/*(；)*/
	0xff1f,	/*(？)*/
	0xffe5,	/*(￥)*/
	0x0000,	/*(list end)*/

};




static bool __user_font_get_glyph_dsc(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next);
static const uint8_t * __user_font_get_bitmap(const lv_font_t * font, uint32_t unicode_letter);


//字体名称: my_font
//字模高度: 38
//外部bin文件,字体信息等级:Level0
lv_font_t opensansb24_fname = {
    .get_glyph_bitmap = __user_font_get_bitmap,
    .get_glyph_dsc = __user_font_get_glyph_dsc,
    .line_height = 38,
    .base_line = 0,
}; 

#define FONT_NAME opensansb24_fname

//static uint8_t __g_font_buf[192];
static uint32_t last_letter;
static uint32_t last_glyph_id;

static volatile uint32_t offset_read=0;

static uint8_t *__user_font_getdata(uint32_t offset, int size)
{

    if (0 == offset_read)
    {
        offset_read =CONFIG_EXT_FONT_OFFSET_F24+(2+sizeof(x_header_check_t)*UT_FONT_CNT); 
    }

    /*实际的字体数据在 2字节字体数量、24所有字体头部信息*/ 
    return (ut_get_map_ptr()+font_data_offset+offset+offset_read); 
}

//二分法查找字符id
static int64_t binsearch(const uint16_t *sortedSeq, int64_t seqLength, uint16_t keyData) {
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
    if (((unicode_letter >= 0x370) && (unicode_letter <= 0x3FF))
             || ((unicode_letter >= 0x530) && (unicode_letter <= 0x58F))
             )
    { 
        FONT_NAME.line_height = 28; 
        FONT_NAME.base_line = 2;
    }
    else if (((unicode_letter >= 0x20) && (unicode_letter <= 0x24F))
             || ((unicode_letter >= 0x400) && (unicode_letter <= 0x4FF))
             || ((unicode_letter >= 0X4E00) && (unicode_letter <= 0x9FFF))
             || ((unicode_letter >= 0XFF00) && (unicode_letter <= 0xFFE5))
             )
    { 
        FONT_NAME.line_height = 30;  
        FONT_NAME.base_line = 0; 
    }
    else if ((unicode_letter >= 0x3041) && (unicode_letter <= 0x30FF))
    { 
        FONT_NAME.line_height = 38; 
        FONT_NAME.base_line = 8;
    } 

    if( unicode_letter>__g_xbf_hd.max || unicode_letter<__g_xbf_hd.min ) {
        return NULL;
    }
       int64_t i;
    i = binsearch(unicode_list, sizeof(unicode_list)/sizeof(unicode_list[0]), unicode_letter);
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
        dsc_out->ofs_x = (glyph_dsc[i].ofs_x+1);
        dsc_out->ofs_y = glyph_dsc[i].ofs_y;
        dsc_out->bpp   = __g_xbf_hd.bpp;
        return true;
    }
    return false;
}

