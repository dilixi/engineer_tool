#include "utils_lib.h"
 
static x_header_t __g_xbf_hd = {
    .min = 0x0020,
    .max = 0xffe5,
    .bpp = 4,
};

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
	{.bitmap_index = 6465, .adv_w = 4, .box_h = 0, .box_w = 4, .ofs_x = 0, .ofs_y = 6},/*( )*/
	{.bitmap_index = 6465, .adv_w = 5, .box_h = 14, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(!)*/
	{.bitmap_index = 6493, .adv_w = 7, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 12},/*(")*/
	{.bitmap_index = 6514, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(#)*/
	{.bitmap_index = 6589, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*($)*/
	{.bitmap_index = 6703, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(%)*/
	{.bitmap_index = 6808, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(&)*/
	{.bitmap_index = 6913, .adv_w = 5, .box_h = 7, .box_w = 4, .ofs_x = 1, .ofs_y = 12},/*(')*/
	{.bitmap_index = 6927, .adv_w = 7, .box_h = 17, .box_w = 6, .ofs_x = 1, .ofs_y = 3},/*(()*/
	{.bitmap_index = 6978, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*())*/
	{.bitmap_index = 7029, .adv_w = 10, .box_h = 9, .box_w = 10, .ofs_x = 0, .ofs_y = 10},/*(*)*/
	{.bitmap_index = 7074, .adv_w = 11, .box_h = 9, .box_w = 10, .ofs_x = 1, .ofs_y = 7},/*(+)*/
	{.bitmap_index = 7119, .adv_w = 4, .box_h = 5, .box_w = 4, .ofs_x = 0, .ofs_y = 2},/*(,)*/
	{.bitmap_index = 7129, .adv_w = 6, .box_h = 2, .box_w = 6, .ofs_x = 0, .ofs_y = 10},/*(-)*/
	{.bitmap_index = 7135, .adv_w = 5, .box_h = 4, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(.)*/
	{.bitmap_index = 7143, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*(/)*/
	{.bitmap_index = 7194, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(0)*/
	{.bitmap_index = 7269, .adv_w = 6, .box_h = 14, .box_w = 6, .ofs_x = 0, .ofs_y = 4},/*(1)*/
	{.bitmap_index = 7311, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(2)*/
	{.bitmap_index = 7386, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(3)*/
	{.bitmap_index = 7456, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(4)*/
	{.bitmap_index = 7526, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(5)*/
	{.bitmap_index = 7596, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(6)*/
	{.bitmap_index = 7666, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(7)*/
	{.bitmap_index = 7736, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(8)*/
	{.bitmap_index = 7811, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(9)*/
	{.bitmap_index = 7886, .adv_w = 5, .box_h = 10, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(:)*/
	{.bitmap_index = 7906, .adv_w = 4, .box_h = 12, .box_w = 4, .ofs_x = 0, .ofs_y = 2},/*(;)*/
	{.bitmap_index = 7930, .adv_w = 11, .box_h = 9, .box_w = 10, .ofs_x = 1, .ofs_y = 7},/*(<)*/
	{.bitmap_index = 7975, .adv_w = 11, .box_h = 7, .box_w = 10, .ofs_x = 1, .ofs_y = 8},/*(=)*/
	{.bitmap_index = 8010, .adv_w = 11, .box_h = 9, .box_w = 10, .ofs_x = 1, .ofs_y = 7},/*(>)*/
	{.bitmap_index = 8055, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(?)*/
	{.bitmap_index = 8130, .adv_w = 18, .box_h = 17, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*(@)*/
	{.bitmap_index = 8283, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(A)*/
	{.bitmap_index = 8367, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(B)*/
	{.bitmap_index = 8437, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(C)*/
	{.bitmap_index = 8527, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(D)*/
	{.bitmap_index = 8611, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(E)*/
	{.bitmap_index = 8681, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(F)*/
	{.bitmap_index = 8737, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(G)*/
	{.bitmap_index = 8827, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(H)*/
	{.bitmap_index = 8911, .adv_w = 5, .box_h = 14, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(I)*/
	{.bitmap_index = 8939, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(J)*/
	{.bitmap_index = 8995, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(K)*/
	{.bitmap_index = 9079, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(L)*/
	{.bitmap_index = 9135, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(M)*/
	{.bitmap_index = 9233, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(N)*/
	{.bitmap_index = 9317, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(O)*/
	{.bitmap_index = 9422, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(P)*/
	{.bitmap_index = 9492, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*(Q)*/
	{.bitmap_index = 9604, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(R)*/
	{.bitmap_index = 9688, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(S)*/
	{.bitmap_index = 9763, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(T)*/
	{.bitmap_index = 9833, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(U)*/
	{.bitmap_index = 9917, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(V)*/
	{.bitmap_index = 10001, .adv_w = 18, .box_h = 14, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(W)*/
	{.bitmap_index = 10127, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(X)*/
	{.bitmap_index = 10211, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Y)*/
	{.bitmap_index = 10295, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Z)*/
	{.bitmap_index = 10379, .adv_w = 7, .box_h = 17, .box_w = 6, .ofs_x = 1, .ofs_y = 3},/*([)*/
	{.bitmap_index = 10430, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*(\)*/
	{.bitmap_index = 10481, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*(])*/
	{.bitmap_index = 10532, .adv_w = 11, .box_h = 9, .box_w = 10, .ofs_x = 1, .ofs_y = 10},/*(^)*/
	{.bitmap_index = 10577, .adv_w = 6, .box_h = 2, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(_)*/
	{.bitmap_index = 10583, .adv_w = 6, .box_h = 4, .box_w = 6, .ofs_x = 0, .ofs_y = 15},/*(`)*/
	{.bitmap_index = 10595, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(a)*/
	{.bitmap_index = 10650, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(b)*/
	{.bitmap_index = 10725, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(c)*/
	{.bitmap_index = 10780, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(d)*/
	{.bitmap_index = 10855, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(e)*/
	{.bitmap_index = 10910, .adv_w = 8, .box_h = 15, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(f)*/
	{.bitmap_index = 10970, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(g)*/
	{.bitmap_index = 11040, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(h)*/
	{.bitmap_index = 11115, .adv_w = 5, .box_h = 15, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(i)*/
	{.bitmap_index = 11145, .adv_w = 5, .box_h = 18, .box_w = 6, .ofs_x = -1, .ofs_y = 1},/*(j)*/
	{.bitmap_index = 11199, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(k)*/
	{.bitmap_index = 11274, .adv_w = 5, .box_h = 15, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(l)*/
	{.bitmap_index = 11304, .adv_w = 15, .box_h = 11, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(m)*/
	{.bitmap_index = 11381, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(n)*/
	{.bitmap_index = 11436, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(o)*/
	{.bitmap_index = 11491, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(p)*/
	{.bitmap_index = 11561, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(q)*/
	{.bitmap_index = 11631, .adv_w = 7, .box_h = 11, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(r)*/
	{.bitmap_index = 11664, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(s)*/
	{.bitmap_index = 11719, .adv_w = 8, .box_h = 13, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(t)*/
	{.bitmap_index = 11771, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(u)*/
	{.bitmap_index = 11826, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(v)*/
	{.bitmap_index = 11881, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(w)*/
	{.bitmap_index = 11969, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(x)*/
	{.bitmap_index = 12024, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(y)*/
	{.bitmap_index = 12094, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(z)*/
	{.bitmap_index = 12149, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*({)*/
	{.bitmap_index = 12200, .adv_w = 5, .box_h = 17, .box_w = 4, .ofs_x = 1, .ofs_y = 3},/*(|)*/
	{.bitmap_index = 12234, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*(})*/
	{.bitmap_index = 12285, .adv_w = 11, .box_h = 4, .box_w = 10, .ofs_x = 1, .ofs_y = 9},/*(~)*/
	{.bitmap_index = 12305, .adv_w = 5, .box_h = 14, .box_w = 4, .ofs_x = 1, .ofs_y = 1},/*(¡)*/
	{.bitmap_index = 12333, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 3},/*(¢)*/
	{.bitmap_index = 12403, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(£)*/
	{.bitmap_index = 12493, .adv_w = 12, .box_h = 12, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(¤)*/
	{.bitmap_index = 12565, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(¥)*/
	{.bitmap_index = 12649, .adv_w = 5, .box_h = 17, .box_w = 4, .ofs_x = 1, .ofs_y = 3},/*(¦)*/
	{.bitmap_index = 12683, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(§)*/
	{.bitmap_index = 12781, .adv_w = 8, .box_h = 4, .box_w = 8, .ofs_x = 0, .ofs_y = 15},/*(¨)*/
	{.bitmap_index = 12797, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(©)*/
	{.bitmap_index = 12917, .adv_w = 10, .box_h = 13, .box_w = 10, .ofs_x = 0, .ofs_y = 6},/*(ª)*/
	{.bitmap_index = 12982, .adv_w = 9, .box_h = 8, .box_w = 8, .ofs_x = 1, .ofs_y = 7},/*(«)*/
	{.bitmap_index = 13014, .adv_w = 8, .box_h = 5, .box_w = 8, .ofs_x = 0, .ofs_y = 7},/*(¬)*/
	{.bitmap_index = 13034, .adv_w = 6, .box_h = 2, .box_w = 6, .ofs_x = 0, .ofs_y = 10},/*(­)*/
	{.bitmap_index = 13040, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 10},/*(®)*/
	{.bitmap_index = 13090, .adv_w = 6, .box_h = 2, .box_w = 6, .ofs_x = 0, .ofs_y = 16},/*(¯)*/
	{.bitmap_index = 13096, .adv_w = 8, .box_h = 8, .box_w = 8, .ofs_x = 0, .ofs_y = 12},/*(°)*/
	{.bitmap_index = 13128, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 6},/*(±)*/
	{.bitmap_index = 13183, .adv_w = 6, .box_h = 8, .box_w = 6, .ofs_x = 0, .ofs_y = 11},/*(²)*/
	{.bitmap_index = 13207, .adv_w = 6, .box_h = 8, .box_w = 6, .ofs_x = 0, .ofs_y = 11},/*(³)*/
	{.bitmap_index = 13231, .adv_w = 6, .box_h = 4, .box_w = 6, .ofs_x = 0, .ofs_y = 15},/*(´)*/
	{.bitmap_index = 13243, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(µ)*/
	{.bitmap_index = 13341, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(¶)*/
	{.bitmap_index = 13439, .adv_w = 6, .box_h = 3, .box_w = 4, .ofs_x = 2, .ofs_y = 10},/*(·)*/
	{.bitmap_index = 13445, .adv_w = 6, .box_h = 4, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(¸)*/
	{.bitmap_index = 13457, .adv_w = 4, .box_h = 8, .box_w = 4, .ofs_x = 0, .ofs_y = 11},/*(¹)*/
	{.bitmap_index = 13473, .adv_w = 10, .box_h = 13, .box_w = 10, .ofs_x = 0, .ofs_y = 6},/*(º)*/
	{.bitmap_index = 13538, .adv_w = 9, .box_h = 8, .box_w = 8, .ofs_x = 1, .ofs_y = 7},/*(»)*/
	{.bitmap_index = 13570, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(¼)*/
	{.bitmap_index = 13668, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(½)*/
	{.bitmap_index = 13766, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(¾)*/
	{.bitmap_index = 13878, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(¿)*/
	{.bitmap_index = 13948, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(À)*/
	{.bitmap_index = 14062, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Á)*/
	{.bitmap_index = 14176, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Â)*/
	{.bitmap_index = 14290, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ã)*/
	{.bitmap_index = 14398, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ä)*/
	{.bitmap_index = 14506, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Å)*/
	{.bitmap_index = 14620, .adv_w = 18, .box_h = 14, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(Æ)*/
	{.bitmap_index = 14746, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*(Ç)*/
	{.bitmap_index = 14854, .adv_w = 11, .box_h = 19, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(È)*/
	{.bitmap_index = 14949, .adv_w = 11, .box_h = 19, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(É)*/
	{.bitmap_index = 15044, .adv_w = 11, .box_h = 19, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ê)*/
	{.bitmap_index = 15139, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ë)*/
	{.bitmap_index = 15229, .adv_w = 4, .box_h = 19, .box_w = 4, .ofs_x = 0, .ofs_y = 4},/*(Ì)*/
	{.bitmap_index = 15267, .adv_w = 5, .box_h = 19, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(Í)*/
	{.bitmap_index = 15305, .adv_w = 7, .box_h = 19, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(Î)*/
	{.bitmap_index = 15381, .adv_w = 7, .box_h = 18, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(Ï)*/
	{.bitmap_index = 15453, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ð)*/
	{.bitmap_index = 15551, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ñ)*/
	{.bitmap_index = 15659, .adv_w = 14, .box_h = 19, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ò)*/
	{.bitmap_index = 15792, .adv_w = 14, .box_h = 19, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ó)*/
	{.bitmap_index = 15925, .adv_w = 14, .box_h = 19, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ô)*/
	{.bitmap_index = 16058, .adv_w = 14, .box_h = 18, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Õ)*/
	{.bitmap_index = 16184, .adv_w = 14, .box_h = 18, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ö)*/
	{.bitmap_index = 16310, .adv_w = 11, .box_h = 9, .box_w = 10, .ofs_x = 1, .ofs_y = 7},/*(×)*/
	{.bitmap_index = 16355, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ø)*/
	{.bitmap_index = 16460, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ù)*/
	{.bitmap_index = 16574, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ú)*/
	{.bitmap_index = 16688, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Û)*/
	{.bitmap_index = 16802, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ü)*/
	{.bitmap_index = 16910, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ý)*/
	{.bitmap_index = 17024, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Þ)*/
	{.bitmap_index = 17094, .adv_w = 13, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(ß)*/
	{.bitmap_index = 17184, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(à)*/
	{.bitmap_index = 17259, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(á)*/
	{.bitmap_index = 17334, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(â)*/
	{.bitmap_index = 17409, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ã)*/
	{.bitmap_index = 17479, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ä)*/
	{.bitmap_index = 17549, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(å)*/
	{.bitmap_index = 17629, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(æ)*/
	{.bitmap_index = 17717, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ç)*/
	{.bitmap_index = 17787, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(è)*/
	{.bitmap_index = 17862, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(é)*/
	{.bitmap_index = 17937, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ê)*/
	{.bitmap_index = 18012, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ë)*/
	{.bitmap_index = 18082, .adv_w = 4, .box_h = 15, .box_w = 4, .ofs_x = 0, .ofs_y = 4},/*(ì)*/
	{.bitmap_index = 18112, .adv_w = 5, .box_h = 15, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(í)*/
	{.bitmap_index = 18142, .adv_w = 7, .box_h = 15, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(î)*/
	{.bitmap_index = 18202, .adv_w = 7, .box_h = 14, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(ï)*/
	{.bitmap_index = 18258, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ð)*/
	{.bitmap_index = 18333, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ñ)*/
	{.bitmap_index = 18403, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ò)*/
	{.bitmap_index = 18478, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ó)*/
	{.bitmap_index = 18553, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ô)*/
	{.bitmap_index = 18628, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(õ)*/
	{.bitmap_index = 18698, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ö)*/
	{.bitmap_index = 18768, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 6},/*(÷)*/
	{.bitmap_index = 18818, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ø)*/
	{.bitmap_index = 18873, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ù)*/
	{.bitmap_index = 18948, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ú)*/
	{.bitmap_index = 19023, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(û)*/
	{.bitmap_index = 19098, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ü)*/
	{.bitmap_index = 19168, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ý)*/
	{.bitmap_index = 19258, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(þ)*/
	{.bitmap_index = 19348, .adv_w = 10, .box_h = 17, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ÿ)*/
	{.bitmap_index = 19433, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ā)*/
	{.bitmap_index = 19541, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ā)*/
	{.bitmap_index = 19611, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ă)*/
	{.bitmap_index = 19725, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ă)*/
	{.bitmap_index = 19800, .adv_w = 14, .box_h = 17, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*(Ą)*/
	{.bitmap_index = 19919, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*(ą)*/
	{.bitmap_index = 20003, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ć)*/
	{.bitmap_index = 20117, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ć)*/
	{.bitmap_index = 20192, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ĉ)*/
	{.bitmap_index = 20306, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ĉ)*/
	{.bitmap_index = 20381, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ċ)*/
	{.bitmap_index = 20489, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ċ)*/
	{.bitmap_index = 20559, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Č)*/
	{.bitmap_index = 20673, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(č)*/
	{.bitmap_index = 20748, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ď)*/
	{.bitmap_index = 20862, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(ď)*/
	{.bitmap_index = 20967, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Đ)*/
	{.bitmap_index = 21065, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(đ)*/
	{.bitmap_index = 21155, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ē)*/
	{.bitmap_index = 21245, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ē)*/
	{.bitmap_index = 21315, .adv_w = 11, .box_h = 19, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ĕ)*/
	{.bitmap_index = 21410, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ĕ)*/
	{.bitmap_index = 21485, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ė)*/
	{.bitmap_index = 21575, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ė)*/
	{.bitmap_index = 21645, .adv_w = 11, .box_h = 17, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(Ę)*/
	{.bitmap_index = 21730, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ę)*/
	{.bitmap_index = 21800, .adv_w = 11, .box_h = 19, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ě)*/
	{.bitmap_index = 21895, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ě)*/
	{.bitmap_index = 21970, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ĝ)*/
	{.bitmap_index = 22084, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ĝ)*/
	{.bitmap_index = 22174, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ğ)*/
	{.bitmap_index = 22288, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ğ)*/
	{.bitmap_index = 22378, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ġ)*/
	{.bitmap_index = 22486, .adv_w = 10, .box_h = 17, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ġ)*/
	{.bitmap_index = 22571, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*(Ģ)*/
	{.bitmap_index = 22679, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ģ)*/
	{.bitmap_index = 22769, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ĥ)*/
	{.bitmap_index = 22883, .adv_w = 10, .box_h = 19, .box_w = 12, .ofs_x = -2, .ofs_y = 4},/*(ĥ)*/
	{.bitmap_index = 22997, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ħ)*/
	{.bitmap_index = 23095, .adv_w = 11, .box_h = 15, .box_w = 12, .ofs_x = -1, .ofs_y = 4},/*(ħ)*/
	{.bitmap_index = 23185, .adv_w = 7, .box_h = 18, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(Ĩ)*/
	{.bitmap_index = 23257, .adv_w = 7, .box_h = 14, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(ĩ)*/
	{.bitmap_index = 23313, .adv_w = 5, .box_h = 18, .box_w = 6, .ofs_x = -1, .ofs_y = 4},/*(Ī)*/
	{.bitmap_index = 23367, .adv_w = 5, .box_h = 14, .box_w = 6, .ofs_x = -1, .ofs_y = 4},/*(ī)*/
	{.bitmap_index = 23409, .adv_w = 7, .box_h = 19, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(Ĭ)*/
	{.bitmap_index = 23485, .adv_w = 7, .box_h = 15, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(ĭ)*/
	{.bitmap_index = 23545, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(Į)*/
	{.bitmap_index = 23596, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(į)*/
	{.bitmap_index = 23647, .adv_w = 5, .box_h = 18, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(İ)*/
	{.bitmap_index = 23683, .adv_w = 5, .box_h = 11, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(ı)*/
	{.bitmap_index = 23705, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ĳ)*/
	{.bitmap_index = 23789, .adv_w = 9, .box_h = 18, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(ĳ)*/
	{.bitmap_index = 23861, .adv_w = 10, .box_h = 19, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ĵ)*/
	{.bitmap_index = 23956, .adv_w = 7, .box_h = 18, .box_w = 8, .ofs_x = -1, .ofs_y = 1},/*(ĵ)*/
	{.bitmap_index = 24028, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(Ķ)*/
	{.bitmap_index = 24130, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(ķ)*/
	{.bitmap_index = 24220, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ĸ)*/
	{.bitmap_index = 24275, .adv_w = 9, .box_h = 18, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ĺ)*/
	{.bitmap_index = 24347, .adv_w = 5, .box_h = 19, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(ĺ)*/
	{.bitmap_index = 24385, .adv_w = 9, .box_h = 17, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(Ļ)*/
	{.bitmap_index = 24453, .adv_w = 5, .box_h = 18, .box_w = 4, .ofs_x = 1, .ofs_y = 1},/*(ļ)*/
	{.bitmap_index = 24489, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ľ)*/
	{.bitmap_index = 24545, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ľ)*/
	{.bitmap_index = 24590, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ŀ)*/
	{.bitmap_index = 24646, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ŀ)*/
	{.bitmap_index = 24691, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ł)*/
	{.bitmap_index = 24775, .adv_w = 8, .box_h = 15, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ł)*/
	{.bitmap_index = 24835, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ń)*/
	{.bitmap_index = 24949, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ń)*/
	{.bitmap_index = 25024, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(Ņ)*/
	{.bitmap_index = 25126, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(ņ)*/
	{.bitmap_index = 25196, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ň)*/
	{.bitmap_index = 25310, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ň)*/
	{.bitmap_index = 25385, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ŉ)*/
	{.bitmap_index = 25483, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(Ŋ)*/
	{.bitmap_index = 25585, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(ŋ)*/
	{.bitmap_index = 25655, .adv_w = 14, .box_h = 18, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ō)*/
	{.bitmap_index = 25781, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ō)*/
	{.bitmap_index = 25851, .adv_w = 14, .box_h = 19, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ŏ)*/
	{.bitmap_index = 25984, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ŏ)*/
	{.bitmap_index = 26059, .adv_w = 14, .box_h = 19, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ő)*/
	{.bitmap_index = 26192, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ő)*/
	{.bitmap_index = 26267, .adv_w = 18, .box_h = 14, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(Œ)*/
	{.bitmap_index = 26393, .adv_w = 18, .box_h = 11, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(œ)*/
	{.bitmap_index = 26492, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ŕ)*/
	{.bitmap_index = 26606, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ŕ)*/
	{.bitmap_index = 26651, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(Ŗ)*/
	{.bitmap_index = 26753, .adv_w = 7, .box_h = 14, .box_w = 6, .ofs_x = 1, .ofs_y = 1},/*(ŗ)*/
	{.bitmap_index = 26795, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ř)*/
	{.bitmap_index = 26909, .adv_w = 8, .box_h = 15, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ř)*/
	{.bitmap_index = 26969, .adv_w = 10, .box_h = 19, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ś)*/
	{.bitmap_index = 27064, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ś)*/
	{.bitmap_index = 27139, .adv_w = 10, .box_h = 19, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ŝ)*/
	{.bitmap_index = 27234, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ŝ)*/
	{.bitmap_index = 27309, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(Ş)*/
	{.bitmap_index = 27399, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ş)*/
	{.bitmap_index = 27469, .adv_w = 10, .box_h = 19, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Š)*/
	{.bitmap_index = 27564, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(š)*/
	{.bitmap_index = 27639, .adv_w = 10, .box_h = 17, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(Ţ)*/
	{.bitmap_index = 27724, .adv_w = 8, .box_h = 16, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ţ)*/
	{.bitmap_index = 27788, .adv_w = 10, .box_h = 19, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ť)*/
	{.bitmap_index = 27883, .adv_w = 8, .box_h = 15, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ť)*/
	{.bitmap_index = 27943, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ŧ)*/
	{.bitmap_index = 28013, .adv_w = 8, .box_h = 13, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ŧ)*/
	{.bitmap_index = 28065, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ũ)*/
	{.bitmap_index = 28173, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ũ)*/
	{.bitmap_index = 28243, .adv_w = 13, .box_h = 18, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ū)*/
	{.bitmap_index = 28351, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ū)*/
	{.bitmap_index = 28421, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ŭ)*/
	{.bitmap_index = 28535, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ŭ)*/
	{.bitmap_index = 28610, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ů)*/
	{.bitmap_index = 28724, .adv_w = 11, .box_h = 16, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ů)*/
	{.bitmap_index = 28804, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ű)*/
	{.bitmap_index = 28918, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ű)*/
	{.bitmap_index = 28993, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(Ų)*/
	{.bitmap_index = 29095, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(ų)*/
	{.bitmap_index = 29165, .adv_w = 18, .box_h = 19, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(Ŵ)*/
	{.bitmap_index = 29336, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(ŵ)*/
	{.bitmap_index = 29456, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ŷ)*/
	{.bitmap_index = 29570, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ŷ)*/
	{.bitmap_index = 29660, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ÿ)*/
	{.bitmap_index = 29768, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ź)*/
	{.bitmap_index = 29882, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ź)*/
	{.bitmap_index = 29957, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ż)*/
	{.bitmap_index = 30065, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ż)*/
	{.bitmap_index = 30135, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ž)*/
	{.bitmap_index = 30249, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ž)*/
	{.bitmap_index = 30324, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ſ)*/
	{.bitmap_index = 30422, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƀ)*/
	{.bitmap_index = 30520, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɓ)*/
	{.bitmap_index = 30618, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƃ)*/
	{.bitmap_index = 30716, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƃ)*/
	{.bitmap_index = 30814, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƅ)*/
	{.bitmap_index = 30912, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƅ)*/
	{.bitmap_index = 31010, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɔ)*/
	{.bitmap_index = 31108, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƈ)*/
	{.bitmap_index = 31206, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƈ)*/
	{.bitmap_index = 31304, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɖ)*/
	{.bitmap_index = 31402, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɗ)*/
	{.bitmap_index = 31500, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƌ)*/
	{.bitmap_index = 31598, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƌ)*/
	{.bitmap_index = 31696, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƍ)*/
	{.bitmap_index = 31794, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǝ)*/
	{.bitmap_index = 31892, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ə)*/
	{.bitmap_index = 31997, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɛ)*/
	{.bitmap_index = 32095, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƒ)*/
	{.bitmap_index = 32193, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*(ƒ)*/
	{.bitmap_index = 32301, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɠ)*/
	{.bitmap_index = 32399, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɣ)*/
	{.bitmap_index = 32497, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƕ)*/
	{.bitmap_index = 32595, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɩ)*/
	{.bitmap_index = 32693, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɨ)*/
	{.bitmap_index = 32791, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƙ)*/
	{.bitmap_index = 32889, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƙ)*/
	{.bitmap_index = 32987, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƚ)*/
	{.bitmap_index = 33085, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƛ)*/
	{.bitmap_index = 33183, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɯ)*/
	{.bitmap_index = 33281, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɲ)*/
	{.bitmap_index = 33379, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƞ)*/
	{.bitmap_index = 33477, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɵ)*/
	{.bitmap_index = 33575, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ơ)*/
	{.bitmap_index = 33673, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ơ)*/
	{.bitmap_index = 33771, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƣ)*/
	{.bitmap_index = 33869, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƣ)*/
	{.bitmap_index = 33967, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƥ)*/
	{.bitmap_index = 34065, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƥ)*/
	{.bitmap_index = 34163, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʀ)*/
	{.bitmap_index = 34261, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƨ)*/
	{.bitmap_index = 34359, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƨ)*/
	{.bitmap_index = 34457, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʃ)*/
	{.bitmap_index = 34555, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƪ)*/
	{.bitmap_index = 34653, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƫ)*/
	{.bitmap_index = 34751, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƭ)*/
	{.bitmap_index = 34849, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƭ)*/
	{.bitmap_index = 34947, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʈ)*/
	{.bitmap_index = 35045, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ư)*/
	{.bitmap_index = 35143, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ư)*/
	{.bitmap_index = 35241, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʊ)*/
	{.bitmap_index = 35339, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʋ)*/
	{.bitmap_index = 35437, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƴ)*/
	{.bitmap_index = 35535, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƴ)*/
	{.bitmap_index = 35633, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƶ)*/
	{.bitmap_index = 35731, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƶ)*/
	{.bitmap_index = 35829, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʒ)*/
	{.bitmap_index = 35927, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƹ)*/
	{.bitmap_index = 36025, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƹ)*/
	{.bitmap_index = 36123, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƺ)*/
	{.bitmap_index = 36221, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƻ)*/
	{.bitmap_index = 36319, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƽ)*/
	{.bitmap_index = 36417, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƽ)*/
	{.bitmap_index = 36515, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƾ)*/
	{.bitmap_index = 36613, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ƿ)*/
	{.bitmap_index = 36711, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǀ)*/
	{.bitmap_index = 36809, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǁ)*/
	{.bitmap_index = 36907, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǂ)*/
	{.bitmap_index = 37005, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǃ)*/
	{.bitmap_index = 37103, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǆ)*/
	{.bitmap_index = 37201, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǅ)*/
	{.bitmap_index = 37299, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǆ)*/
	{.bitmap_index = 37397, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǉ)*/
	{.bitmap_index = 37495, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǈ)*/
	{.bitmap_index = 37593, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǉ)*/
	{.bitmap_index = 37691, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǌ)*/
	{.bitmap_index = 37789, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǋ)*/
	{.bitmap_index = 37887, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǌ)*/
	{.bitmap_index = 37985, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ǎ)*/
	{.bitmap_index = 38099, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ǎ)*/
	{.bitmap_index = 38174, .adv_w = 7, .box_h = 19, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(Ǐ)*/
	{.bitmap_index = 38250, .adv_w = 7, .box_h = 15, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(ǐ)*/
	{.bitmap_index = 38310, .adv_w = 14, .box_h = 19, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ǒ)*/
	{.bitmap_index = 38443, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ǒ)*/
	{.bitmap_index = 38518, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ǔ)*/
	{.bitmap_index = 38632, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ǔ)*/
	{.bitmap_index = 38707, .adv_w = 13, .box_h = 21, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ǖ)*/
	{.bitmap_index = 38833, .adv_w = 11, .box_h = 17, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ǖ)*/
	{.bitmap_index = 38918, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ǘ)*/
	{.bitmap_index = 39050, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ǘ)*/
	{.bitmap_index = 39140, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ǚ)*/
	{.bitmap_index = 39272, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ǚ)*/
	{.bitmap_index = 39362, .adv_w = 13, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ǜ)*/
	{.bitmap_index = 39494, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ǜ)*/
	{.bitmap_index = 39584, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǝ)*/
	{.bitmap_index = 39682, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǟ)*/
	{.bitmap_index = 39780, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǟ)*/
	{.bitmap_index = 39878, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǡ)*/
	{.bitmap_index = 39976, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǡ)*/
	{.bitmap_index = 40074, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǣ)*/
	{.bitmap_index = 40172, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǣ)*/
	{.bitmap_index = 40270, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǥ)*/
	{.bitmap_index = 40368, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǥ)*/
	{.bitmap_index = 40466, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǧ)*/
	{.bitmap_index = 40564, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǧ)*/
	{.bitmap_index = 40662, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǩ)*/
	{.bitmap_index = 40760, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǩ)*/
	{.bitmap_index = 40858, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǫ)*/
	{.bitmap_index = 40956, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǫ)*/
	{.bitmap_index = 41054, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǭ)*/
	{.bitmap_index = 41152, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǭ)*/
	{.bitmap_index = 41250, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǯ)*/
	{.bitmap_index = 41348, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǯ)*/
	{.bitmap_index = 41446, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǰ)*/
	{.bitmap_index = 41544, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǳ)*/
	{.bitmap_index = 41642, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǲ)*/
	{.bitmap_index = 41740, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǳ)*/
	{.bitmap_index = 41838, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǵ)*/
	{.bitmap_index = 41936, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǵ)*/
	{.bitmap_index = 42034, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƕ)*/
	{.bitmap_index = 42132, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƿ)*/
	{.bitmap_index = 42230, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǹ)*/
	{.bitmap_index = 42328, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǹ)*/
	{.bitmap_index = 42426, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǻ)*/
	{.bitmap_index = 42524, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǻ)*/
	{.bitmap_index = 42622, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǽ)*/
	{.bitmap_index = 42720, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǽ)*/
	{.bitmap_index = 42818, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ǿ)*/
	{.bitmap_index = 42916, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ǿ)*/
	{.bitmap_index = 43014, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȁ)*/
	{.bitmap_index = 43112, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȁ)*/
	{.bitmap_index = 43210, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȃ)*/
	{.bitmap_index = 43308, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȃ)*/
	{.bitmap_index = 43406, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȅ)*/
	{.bitmap_index = 43504, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȅ)*/
	{.bitmap_index = 43602, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȇ)*/
	{.bitmap_index = 43700, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȇ)*/
	{.bitmap_index = 43798, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȉ)*/
	{.bitmap_index = 43896, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȉ)*/
	{.bitmap_index = 43994, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȋ)*/
	{.bitmap_index = 44092, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȋ)*/
	{.bitmap_index = 44190, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȍ)*/
	{.bitmap_index = 44288, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȍ)*/
	{.bitmap_index = 44386, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȏ)*/
	{.bitmap_index = 44484, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȏ)*/
	{.bitmap_index = 44582, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȑ)*/
	{.bitmap_index = 44680, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȑ)*/
	{.bitmap_index = 44778, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȓ)*/
	{.bitmap_index = 44876, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȓ)*/
	{.bitmap_index = 44974, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȕ)*/
	{.bitmap_index = 45072, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȕ)*/
	{.bitmap_index = 45170, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȗ)*/
	{.bitmap_index = 45268, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȗ)*/
	{.bitmap_index = 45366, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(Ș)*/
	{.bitmap_index = 45456, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ș)*/
	{.bitmap_index = 45526, .adv_w = 10, .box_h = 17, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(Ț)*/
	{.bitmap_index = 45611, .adv_w = 8, .box_h = 16, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ț)*/
	{.bitmap_index = 45675, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȝ)*/
	{.bitmap_index = 45773, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȝ)*/
	{.bitmap_index = 45871, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȟ)*/
	{.bitmap_index = 45969, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȟ)*/
	{.bitmap_index = 46067, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƞ)*/
	{.bitmap_index = 46165, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȡ)*/
	{.bitmap_index = 46263, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȣ)*/
	{.bitmap_index = 46361, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȣ)*/
	{.bitmap_index = 46459, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȥ)*/
	{.bitmap_index = 46557, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȥ)*/
	{.bitmap_index = 46655, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȧ)*/
	{.bitmap_index = 46753, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȧ)*/
	{.bitmap_index = 46851, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȩ)*/
	{.bitmap_index = 46949, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȩ)*/
	{.bitmap_index = 47047, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȫ)*/
	{.bitmap_index = 47145, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȫ)*/
	{.bitmap_index = 47243, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȭ)*/
	{.bitmap_index = 47341, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȭ)*/
	{.bitmap_index = 47439, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȯ)*/
	{.bitmap_index = 47537, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȯ)*/
	{.bitmap_index = 47635, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȱ)*/
	{.bitmap_index = 47733, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȱ)*/
	{.bitmap_index = 47831, .adv_w = 12, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ȳ)*/
	{.bitmap_index = 47939, .adv_w = 10, .box_h = 17, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ȳ)*/
	{.bitmap_index = 48024, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȴ)*/
	{.bitmap_index = 48122, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȵ)*/
	{.bitmap_index = 48220, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȶ)*/
	{.bitmap_index = 48318, .adv_w = 5, .box_h = 14, .box_w = 6, .ofs_x = -1, .ofs_y = 1},/*(ȷ)*/
	{.bitmap_index = 48360, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȸ)*/
	{.bitmap_index = 48458, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȹ)*/
	{.bitmap_index = 48556, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ⱥ)*/
	{.bitmap_index = 48654, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ȼ)*/
	{.bitmap_index = 48752, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȼ)*/
	{.bitmap_index = 48850, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƚ)*/
	{.bitmap_index = 48948, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ⱦ)*/
	{.bitmap_index = 49046, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ȿ)*/
	{.bitmap_index = 49144, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɀ)*/
	{.bitmap_index = 49242, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɂ)*/
	{.bitmap_index = 49340, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɂ)*/
	{.bitmap_index = 49438, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ƀ)*/
	{.bitmap_index = 49536, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʉ)*/
	{.bitmap_index = 49634, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ʌ)*/
	{.bitmap_index = 49732, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɇ)*/
	{.bitmap_index = 49830, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɇ)*/
	{.bitmap_index = 49928, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɉ)*/
	{.bitmap_index = 50026, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɉ)*/
	{.bitmap_index = 50124, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɋ)*/
	{.bitmap_index = 50222, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɋ)*/
	{.bitmap_index = 50320, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɍ)*/
	{.bitmap_index = 50418, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɍ)*/
	{.bitmap_index = 50516, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ɏ)*/
	{.bitmap_index = 50614, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ɏ)*/
	{.bitmap_index = 931286, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ͱ)*/
	{.bitmap_index = 931326, .adv_w = 7, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ͱ)*/
	{.bitmap_index = 931347, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ͳ)*/
	{.bitmap_index = 931387, .adv_w = 8, .box_h = 9, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ͳ)*/
	{.bitmap_index = 931423, .adv_w = 4, .box_h = 4, .box_w = 4, .ofs_x = 0, .ofs_y = 11},/*(ʹ)*/
	{.bitmap_index = 931431, .adv_w = 4, .box_h = 4, .box_w = 4, .ofs_x = 0, .ofs_y = 2},/*(͵)*/
	{.bitmap_index = 931439, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ͷ)*/
	{.bitmap_index = 931479, .adv_w = 9, .box_h = 8, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ͷ)*/
	{.bitmap_index = 931511, .adv_w = 5, .box_h = 2, .box_w = 4, .ofs_x = 1, .ofs_y = 1},/*(ͺ)*/
	{.bitmap_index = 931515, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ͻ)*/
	{.bitmap_index = 931543, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ͼ)*/
	{.bitmap_index = 931571, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ͽ)*/
	{.bitmap_index = 931599, .adv_w = 4, .box_h = 9, .box_w = 4, .ofs_x = 0, .ofs_y = 2},/*(;)*/
	{.bitmap_index = 931617, .adv_w = 4, .box_h = 10, .box_w = 4, .ofs_x = 0, .ofs_y = 4},/*(Ϳ)*/
	{.bitmap_index = 931637, .adv_w = 4, .box_h = 4, .box_w = 4, .ofs_x = 0, .ofs_y = 11},/*(΄)*/
	{.bitmap_index = 931645, .adv_w = 8, .box_h = 4, .box_w = 8, .ofs_x = 0, .ofs_y = 11},/*(΅)*/
	{.bitmap_index = 931661, .adv_w = 9, .box_h = 11, .box_w = 10, .ofs_x = -1, .ofs_y = 4},/*(Ά)*/
	{.bitmap_index = 931716, .adv_w = 3, .box_h = 2, .box_w = 2, .ofs_x = 1, .ofs_y = 11},/*(·)*/
	{.bitmap_index = 931718, .adv_w = 7, .box_h = 11, .box_w = 10, .ofs_x = -3, .ofs_y = 4},/*(Έ)*/
	{.bitmap_index = 931773, .adv_w = 9, .box_h = 11, .box_w = 12, .ofs_x = -3, .ofs_y = 4},/*(Ή)*/
	{.bitmap_index = 931839, .adv_w = 3, .box_h = 11, .box_w = 6, .ofs_x = -3, .ofs_y = 4},/*(Ί)*/
	{.bitmap_index = 931872, .adv_w = 10, .box_h = 11, .box_w = 12, .ofs_x = -2, .ofs_y = 4},/*(Ό)*/
	{.bitmap_index = 931938, .adv_w = 8, .box_h = 11, .box_w = 12, .ofs_x = -4, .ofs_y = 4},/*(Ύ)*/
	{.bitmap_index = 932004, .adv_w = 11, .box_h = 11, .box_w = 14, .ofs_x = -3, .ofs_y = 4},/*(Ώ)*/
	{.bitmap_index = 932081, .adv_w = 6, .box_h = 11, .box_w = 8, .ofs_x = -2, .ofs_y = 4},/*(ΐ)*/
	{.bitmap_index = 932125, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Α)*/
	{.bitmap_index = 932175, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Β)*/
	{.bitmap_index = 932215, .adv_w = 7, .box_h = 10, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(Γ)*/
	{.bitmap_index = 932245, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Δ)*/
	{.bitmap_index = 932295, .adv_w = 7, .box_h = 10, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(Ε)*/
	{.bitmap_index = 932325, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ζ)*/
	{.bitmap_index = 932365, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Η)*/
	{.bitmap_index = 932405, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Θ)*/
	{.bitmap_index = 932455, .adv_w = 3, .box_h = 10, .box_w = 2, .ofs_x = 1, .ofs_y = 4},/*(Ι)*/
	{.bitmap_index = 932465, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Κ)*/
	{.bitmap_index = 932505, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Λ)*/
	{.bitmap_index = 932555, .adv_w = 13, .box_h = 10, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Μ)*/
	{.bitmap_index = 932615, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ν)*/
	{.bitmap_index = 932655, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ξ)*/
	{.bitmap_index = 932695, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ο)*/
	{.bitmap_index = 932745, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Π)*/
	{.bitmap_index = 932785, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ρ)*/
	{.bitmap_index = 932825, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Σ)*/
	{.bitmap_index = 932865, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Τ)*/
	{.bitmap_index = 932905, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Υ)*/
	{.bitmap_index = 932945, .adv_w = 12, .box_h = 12, .box_w = 12, .ofs_x = 0, .ofs_y = 3},/*(Φ)*/
	{.bitmap_index = 933017, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Χ)*/
	{.bitmap_index = 933057, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ψ)*/
	{.bitmap_index = 933107, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ω)*/
	{.bitmap_index = 933157, .adv_w = 6, .box_h = 13, .box_w = 8, .ofs_x = -2, .ofs_y = 4},/*(Ϊ)*/
	{.bitmap_index = 933209, .adv_w = 8, .box_h = 13, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ϋ)*/
	{.bitmap_index = 933261, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ά)*/
	{.bitmap_index = 933316, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(έ)*/
	{.bitmap_index = 933360, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(ή)*/
	{.bitmap_index = 933416, .adv_w = 5, .box_h = 11, .box_w = 6, .ofs_x = -1, .ofs_y = 4},/*(ί)*/
	{.bitmap_index = 933449, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ΰ)*/
	{.bitmap_index = 933493, .adv_w = 10, .box_h = 7, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(α)*/
	{.bitmap_index = 933528, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(β)*/
	{.bitmap_index = 933584, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(γ)*/
	{.bitmap_index = 933624, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(δ)*/
	{.bitmap_index = 933668, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ε)*/
	{.bitmap_index = 933696, .adv_w = 6, .box_h = 13, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(ζ)*/
	{.bitmap_index = 933735, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(η)*/
	{.bitmap_index = 933775, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(θ)*/
	{.bitmap_index = 933819, .adv_w = 5, .box_h = 7, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(ι)*/
	{.bitmap_index = 933833, .adv_w = 7, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(κ)*/
	{.bitmap_index = 933854, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(λ)*/
	{.bitmap_index = 933898, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(μ)*/
	{.bitmap_index = 933938, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ν)*/
	{.bitmap_index = 933966, .adv_w = 6, .box_h = 14, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(ξ)*/
	{.bitmap_index = 934008, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ο)*/
	{.bitmap_index = 934036, .adv_w = 10, .box_h = 7, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(π)*/
	{.bitmap_index = 934071, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ρ)*/
	{.bitmap_index = 934111, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ς)*/
	{.bitmap_index = 934151, .adv_w = 10, .box_h = 7, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(σ)*/
	{.bitmap_index = 934186, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(τ)*/
	{.bitmap_index = 934214, .adv_w = 9, .box_h = 7, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(υ)*/
	{.bitmap_index = 934242, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(φ)*/
	{.bitmap_index = 934312, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(χ)*/
	{.bitmap_index = 934352, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(ψ)*/
	{.bitmap_index = 934422, .adv_w = 12, .box_h = 7, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(ω)*/
	{.bitmap_index = 934464, .adv_w = 6, .box_h = 10, .box_w = 8, .ofs_x = -2, .ofs_y = 4},/*(ϊ)*/
	{.bitmap_index = 934504, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϋ)*/
	{.bitmap_index = 934544, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ό)*/
	{.bitmap_index = 934588, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ύ)*/
	{.bitmap_index = 934632, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(ώ)*/
	{.bitmap_index = 934698, .adv_w = 9, .box_h = 12, .box_w = 8, .ofs_x = 1, .ofs_y = 2},/*(Ϗ)*/
	{.bitmap_index = 934746, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϐ)*/
	{.bitmap_index = 934790, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ϑ)*/
	{.bitmap_index = 934845, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϒ)*/
	{.bitmap_index = 934885, .adv_w = 9, .box_h = 11, .box_w = 12, .ofs_x = -3, .ofs_y = 4},/*(ϓ)*/
	{.bitmap_index = 934951, .adv_w = 8, .box_h = 13, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϔ)*/
	{.bitmap_index = 935003, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ϕ)*/
	{.bitmap_index = 935053, .adv_w = 14, .box_h = 8, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(ϖ)*/
	{.bitmap_index = 935109, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ϗ)*/
	{.bitmap_index = 935159, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ϙ)*/
	{.bitmap_index = 935209, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ϙ)*/
	{.bitmap_index = 935249, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(Ϛ)*/
	{.bitmap_index = 935319, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ϛ)*/
	{.bitmap_index = 935359, .adv_w = 7, .box_h = 10, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(Ϝ)*/
	{.bitmap_index = 935389, .adv_w = 7, .box_h = 10, .box_w = 6, .ofs_x = 1, .ofs_y = 1},/*(ϝ)*/
	{.bitmap_index = 935419, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ϟ)*/
	{.bitmap_index = 935469, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ϟ)*/
	{.bitmap_index = 935509, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ϡ)*/
	{.bitmap_index = 935559, .adv_w = 10, .box_h = 13, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ϡ)*/
	{.bitmap_index = 935624, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*(Ϣ)*/
	{.bitmap_index = 935708, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*(ϣ)*/
	{.bitmap_index = 935774, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ϥ)*/
	{.bitmap_index = 935814, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ϥ)*/
	{.bitmap_index = 935854, .adv_w = 9, .box_h = 15, .box_w = 8, .ofs_x = 1, .ofs_y = 0},/*(Ϧ)*/
	{.bitmap_index = 935914, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϧ)*/
	{.bitmap_index = 935942, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ϩ)*/
	{.bitmap_index = 935982, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϩ)*/
	{.bitmap_index = 936010, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ϫ)*/
	{.bitmap_index = 936060, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϫ)*/
	{.bitmap_index = 936088, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ϭ)*/
	{.bitmap_index = 936143, .adv_w = 8, .box_h = 12, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϭ)*/
	{.bitmap_index = 936191, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ϯ)*/
	{.bitmap_index = 936231, .adv_w = 8, .box_h = 12, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ϯ)*/
	{.bitmap_index = 936279, .adv_w = 10, .box_h = 7, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ϰ)*/
	{.bitmap_index = 936314, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(ϱ)*/
	{.bitmap_index = 936358, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϲ)*/
	{.bitmap_index = 936386, .adv_w = 3, .box_h = 13, .box_w = 4, .ofs_x = -1, .ofs_y = 1},/*(ϳ)*/
	{.bitmap_index = 936412, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ϴ)*/
	{.bitmap_index = 936462, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ϵ)*/
	{.bitmap_index = 936490, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(϶)*/
	{.bitmap_index = 936518, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ϸ)*/
	{.bitmap_index = 936558, .adv_w = 9, .box_h = 14, .box_w = 10, .ofs_x = -1, .ofs_y = 1},/*(ϸ)*/
	{.bitmap_index = 936628, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ϲ)*/
	{.bitmap_index = 936678, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ϻ)*/
	{.bitmap_index = 936728, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(ϻ)*/
	{.bitmap_index = 936768, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ϼ)*/
	{.bitmap_index = 936808, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ͻ)*/
	{.bitmap_index = 936848, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ͼ)*/
	{.bitmap_index = 936898, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ͽ)*/
	{.bitmap_index = 50712, .adv_w = 11, .box_h = 19, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ѐ)*/
	{.bitmap_index = 50807, .adv_w = 11, .box_h = 18, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ё)*/
	{.bitmap_index = 50897, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*(Ђ)*/
	{.bitmap_index = 51002, .adv_w = 9, .box_h = 19, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ѓ)*/
	{.bitmap_index = 51078, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Є)*/
	{.bitmap_index = 51168, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ѕ)*/
	{.bitmap_index = 51243, .adv_w = 5, .box_h = 14, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(І)*/
	{.bitmap_index = 51271, .adv_w = 7, .box_h = 18, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(Ї)*/
	{.bitmap_index = 51343, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Ј)*/
	{.bitmap_index = 51399, .adv_w = 20, .box_h = 14, .box_w = 20, .ofs_x = 0, .ofs_y = 4},/*(Љ)*/
	{.bitmap_index = 51539, .adv_w = 19, .box_h = 14, .box_w = 18, .ofs_x = 1, .ofs_y = 4},/*(Њ)*/
	{.bitmap_index = 51665, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ћ)*/
	{.bitmap_index = 51763, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ќ)*/
	{.bitmap_index = 51877, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Ѝ)*/
	{.bitmap_index = 51991, .adv_w = 12, .box_h = 19, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ў)*/
	{.bitmap_index = 52105, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 2},/*(Џ)*/
	{.bitmap_index = 52201, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(А)*/
	{.bitmap_index = 52285, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Б)*/
	{.bitmap_index = 52355, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(В)*/
	{.bitmap_index = 52425, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Г)*/
	{.bitmap_index = 52481, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 2},/*(Д)*/
	{.bitmap_index = 52593, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Е)*/
	{.bitmap_index = 52663, .adv_w = 18, .box_h = 14, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(Ж)*/
	{.bitmap_index = 52789, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(З)*/
	{.bitmap_index = 52879, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(И)*/
	{.bitmap_index = 52963, .adv_w = 13, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Й)*/
	{.bitmap_index = 53077, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(К)*/
	{.bitmap_index = 53161, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Л)*/
	{.bitmap_index = 53245, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(М)*/
	{.bitmap_index = 53343, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Н)*/
	{.bitmap_index = 53427, .adv_w = 14, .box_h = 15, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(О)*/
	{.bitmap_index = 53532, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(П)*/
	{.bitmap_index = 53616, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Р)*/
	{.bitmap_index = 53686, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(С)*/
	{.bitmap_index = 53776, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Т)*/
	{.bitmap_index = 53846, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(У)*/
	{.bitmap_index = 53930, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ф)*/
	{.bitmap_index = 54028, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Х)*/
	{.bitmap_index = 54112, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 2},/*(Ц)*/
	{.bitmap_index = 54224, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ч)*/
	{.bitmap_index = 54308, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(Ш)*/
	{.bitmap_index = 54420, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(Щ)*/
	{.bitmap_index = 54548, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(Ъ)*/
	{.bitmap_index = 54646, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ы)*/
	{.bitmap_index = 54744, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ь)*/
	{.bitmap_index = 54814, .adv_w = 12, .box_h = 15, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Э)*/
	{.bitmap_index = 54904, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(Ю)*/
	{.bitmap_index = 55024, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Я)*/
	{.bitmap_index = 55094, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(а)*/
	{.bitmap_index = 55149, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(б)*/
	{.bitmap_index = 55224, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(в)*/
	{.bitmap_index = 55279, .adv_w = 7, .box_h = 11, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(г)*/
	{.bitmap_index = 55312, .adv_w = 12, .box_h = 13, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*(д)*/
	{.bitmap_index = 55390, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(е)*/
	{.bitmap_index = 55445, .adv_w = 14, .box_h = 11, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(ж)*/
	{.bitmap_index = 55522, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(з)*/
	{.bitmap_index = 55566, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(и)*/
	{.bitmap_index = 55621, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(й)*/
	{.bitmap_index = 55696, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(к)*/
	{.bitmap_index = 55751, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(л)*/
	{.bitmap_index = 55806, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(м)*/
	{.bitmap_index = 55872, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(н)*/
	{.bitmap_index = 55927, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(о)*/
	{.bitmap_index = 55982, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(п)*/
	{.bitmap_index = 56037, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(р)*/
	{.bitmap_index = 56107, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(с)*/
	{.bitmap_index = 56162, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(т)*/
	{.bitmap_index = 56206, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(у)*/
	{.bitmap_index = 56276, .adv_w = 14, .box_h = 18, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*(ф)*/
	{.bitmap_index = 56402, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(х)*/
	{.bitmap_index = 56457, .adv_w = 11, .box_h = 13, .box_w = 10, .ofs_x = 1, .ofs_y = 2},/*(ц)*/
	{.bitmap_index = 56522, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ч)*/
	{.bitmap_index = 56577, .adv_w = 15, .box_h = 11, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ш)*/
	{.bitmap_index = 56654, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 2},/*(щ)*/
	{.bitmap_index = 56758, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(ъ)*/
	{.bitmap_index = 56824, .adv_w = 13, .box_h = 11, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(ы)*/
	{.bitmap_index = 56890, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ь)*/
	{.bitmap_index = 56934, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(э)*/
	{.bitmap_index = 56989, .adv_w = 15, .box_h = 11, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ю)*/
	{.bitmap_index = 57066, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(я)*/
	{.bitmap_index = 57121, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ѐ)*/
	{.bitmap_index = 57196, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ё)*/
	{.bitmap_index = 57266, .adv_w = 11, .box_h = 18, .box_w = 12, .ofs_x = -1, .ofs_y = 1},/*(ђ)*/
	{.bitmap_index = 57374, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ѓ)*/
	{.bitmap_index = 57419, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(є)*/
	{.bitmap_index = 57474, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ѕ)*/
	{.bitmap_index = 57529, .adv_w = 5, .box_h = 15, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(і)*/
	{.bitmap_index = 57559, .adv_w = 7, .box_h = 14, .box_w = 8, .ofs_x = -1, .ofs_y = 4},/*(ї)*/
	{.bitmap_index = 57615, .adv_w = 5, .box_h = 18, .box_w = 6, .ofs_x = -1, .ofs_y = 1},/*(ј)*/
	{.bitmap_index = 57669, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(љ)*/
	{.bitmap_index = 57757, .adv_w = 17, .box_h = 11, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(њ)*/
	{.bitmap_index = 57845, .adv_w = 11, .box_h = 15, .box_w = 12, .ofs_x = -1, .ofs_y = 4},/*(ћ)*/
	{.bitmap_index = 57935, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ќ)*/
	{.bitmap_index = 58010, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(ѝ)*/
	{.bitmap_index = 58085, .adv_w = 10, .box_h = 18, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ў)*/
	{.bitmap_index = 58175, .adv_w = 11, .box_h = 13, .box_w = 10, .ofs_x = 1, .ofs_y = 2},/*(џ)*/
	{.bitmap_index = 58240, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѡ)*/
	{.bitmap_index = 58338, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѡ)*/
	{.bitmap_index = 58436, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѣ)*/
	{.bitmap_index = 58534, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѣ)*/
	{.bitmap_index = 58632, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѥ)*/
	{.bitmap_index = 58730, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѥ)*/
	{.bitmap_index = 58828, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѧ)*/
	{.bitmap_index = 58926, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѧ)*/
	{.bitmap_index = 59024, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѩ)*/
	{.bitmap_index = 59122, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѩ)*/
	{.bitmap_index = 59220, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѫ)*/
	{.bitmap_index = 59318, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѫ)*/
	{.bitmap_index = 59416, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѭ)*/
	{.bitmap_index = 59514, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѭ)*/
	{.bitmap_index = 59612, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѯ)*/
	{.bitmap_index = 59710, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѯ)*/
	{.bitmap_index = 59808, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѱ)*/
	{.bitmap_index = 59906, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѱ)*/
	{.bitmap_index = 60004, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѳ)*/
	{.bitmap_index = 60102, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѳ)*/
	{.bitmap_index = 60200, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѵ)*/
	{.bitmap_index = 60298, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѵ)*/
	{.bitmap_index = 60396, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѷ)*/
	{.bitmap_index = 60494, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѷ)*/
	{.bitmap_index = 60592, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѹ)*/
	{.bitmap_index = 60690, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѹ)*/
	{.bitmap_index = 60788, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѻ)*/
	{.bitmap_index = 60886, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѻ)*/
	{.bitmap_index = 60984, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѽ)*/
	{.bitmap_index = 61082, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѽ)*/
	{.bitmap_index = 61180, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ѿ)*/
	{.bitmap_index = 61278, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ѿ)*/
	{.bitmap_index = 61376, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҁ)*/
	{.bitmap_index = 61474, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҁ)*/
	{.bitmap_index = 61572, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҂)*/
	{.bitmap_index = 61670, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҃)*/
	{.bitmap_index = 61768, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҄)*/
	{.bitmap_index = 61866, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҅)*/
	{.bitmap_index = 61964, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҆)*/
	{.bitmap_index = 62062, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҇)*/
	{.bitmap_index = 62160, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҈)*/
	{.bitmap_index = 62258, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(҉)*/
	{.bitmap_index = 62356, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҋ)*/
	{.bitmap_index = 62454, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҋ)*/
	{.bitmap_index = 62552, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҍ)*/
	{.bitmap_index = 62650, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҍ)*/
	{.bitmap_index = 62748, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҏ)*/
	{.bitmap_index = 62846, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҏ)*/
	{.bitmap_index = 62944, .adv_w = 11, .box_h = 16, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ґ)*/
	{.bitmap_index = 63024, .adv_w = 7, .box_h = 13, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ґ)*/
	{.bitmap_index = 63063, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ғ)*/
	{.bitmap_index = 63161, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ғ)*/
	{.bitmap_index = 63259, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҕ)*/
	{.bitmap_index = 63357, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҕ)*/
	{.bitmap_index = 63455, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Җ)*/
	{.bitmap_index = 63553, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(җ)*/
	{.bitmap_index = 63651, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҙ)*/
	{.bitmap_index = 63749, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҙ)*/
	{.bitmap_index = 63847, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Қ)*/
	{.bitmap_index = 63945, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(қ)*/
	{.bitmap_index = 64043, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҝ)*/
	{.bitmap_index = 64141, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҝ)*/
	{.bitmap_index = 64239, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҟ)*/
	{.bitmap_index = 64337, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҟ)*/
	{.bitmap_index = 64435, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҡ)*/
	{.bitmap_index = 64533, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҡ)*/
	{.bitmap_index = 64631, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ң)*/
	{.bitmap_index = 64729, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ң)*/
	{.bitmap_index = 64827, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҥ)*/
	{.bitmap_index = 64925, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҥ)*/
	{.bitmap_index = 65023, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҧ)*/
	{.bitmap_index = 65121, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҧ)*/
	{.bitmap_index = 65219, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҩ)*/
	{.bitmap_index = 65317, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҩ)*/
	{.bitmap_index = 65415, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҫ)*/
	{.bitmap_index = 65513, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҫ)*/
	{.bitmap_index = 65611, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҭ)*/
	{.bitmap_index = 65709, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҭ)*/
	{.bitmap_index = 65807, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ү)*/
	{.bitmap_index = 65905, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ү)*/
	{.bitmap_index = 66003, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ұ)*/
	{.bitmap_index = 66101, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ұ)*/
	{.bitmap_index = 66199, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҳ)*/
	{.bitmap_index = 66297, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҳ)*/
	{.bitmap_index = 66395, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҵ)*/
	{.bitmap_index = 66493, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҵ)*/
	{.bitmap_index = 66591, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҷ)*/
	{.bitmap_index = 66689, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҷ)*/
	{.bitmap_index = 66787, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҹ)*/
	{.bitmap_index = 66885, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҹ)*/
	{.bitmap_index = 66983, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Һ)*/
	{.bitmap_index = 67081, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(һ)*/
	{.bitmap_index = 67179, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҽ)*/
	{.bitmap_index = 67277, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҽ)*/
	{.bitmap_index = 67375, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ҿ)*/
	{.bitmap_index = 67473, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ҿ)*/
	{.bitmap_index = 67571, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӏ)*/
	{.bitmap_index = 67669, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӂ)*/
	{.bitmap_index = 67767, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӂ)*/
	{.bitmap_index = 67865, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӄ)*/
	{.bitmap_index = 67963, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӄ)*/
	{.bitmap_index = 68061, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӆ)*/
	{.bitmap_index = 68159, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӆ)*/
	{.bitmap_index = 68257, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӈ)*/
	{.bitmap_index = 68355, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӈ)*/
	{.bitmap_index = 68453, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӊ)*/
	{.bitmap_index = 68551, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӊ)*/
	{.bitmap_index = 68649, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӌ)*/
	{.bitmap_index = 68747, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӌ)*/
	{.bitmap_index = 68845, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӎ)*/
	{.bitmap_index = 68943, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӎ)*/
	{.bitmap_index = 69041, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӏ)*/
	{.bitmap_index = 69139, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӑ)*/
	{.bitmap_index = 69237, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӑ)*/
	{.bitmap_index = 69335, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӓ)*/
	{.bitmap_index = 69433, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӓ)*/
	{.bitmap_index = 69531, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӕ)*/
	{.bitmap_index = 69629, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӕ)*/
	{.bitmap_index = 69727, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӗ)*/
	{.bitmap_index = 69825, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӗ)*/
	{.bitmap_index = 69923, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ә)*/
	{.bitmap_index = 70021, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ә)*/
	{.bitmap_index = 70119, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӛ)*/
	{.bitmap_index = 70217, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӛ)*/
	{.bitmap_index = 70315, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӝ)*/
	{.bitmap_index = 70413, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӝ)*/
	{.bitmap_index = 70511, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӟ)*/
	{.bitmap_index = 70609, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӟ)*/
	{.bitmap_index = 70707, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӡ)*/
	{.bitmap_index = 70805, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӡ)*/
	{.bitmap_index = 70903, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӣ)*/
	{.bitmap_index = 71001, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӣ)*/
	{.bitmap_index = 71099, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӥ)*/
	{.bitmap_index = 71197, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӥ)*/
	{.bitmap_index = 71295, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӧ)*/
	{.bitmap_index = 71393, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӧ)*/
	{.bitmap_index = 71491, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ө)*/
	{.bitmap_index = 71589, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ө)*/
	{.bitmap_index = 71687, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӫ)*/
	{.bitmap_index = 71785, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӫ)*/
	{.bitmap_index = 71883, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӭ)*/
	{.bitmap_index = 71981, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӭ)*/
	{.bitmap_index = 72079, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӯ)*/
	{.bitmap_index = 72177, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӯ)*/
	{.bitmap_index = 72275, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӱ)*/
	{.bitmap_index = 72373, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӱ)*/
	{.bitmap_index = 72471, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӳ)*/
	{.bitmap_index = 72569, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӳ)*/
	{.bitmap_index = 72667, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӵ)*/
	{.bitmap_index = 72765, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӵ)*/
	{.bitmap_index = 72863, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӷ)*/
	{.bitmap_index = 72961, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӷ)*/
	{.bitmap_index = 73059, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӹ)*/
	{.bitmap_index = 73157, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӹ)*/
	{.bitmap_index = 73255, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӻ)*/
	{.bitmap_index = 73353, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӻ)*/
	{.bitmap_index = 73451, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӽ)*/
	{.bitmap_index = 73549, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӽ)*/
	{.bitmap_index = 73647, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(Ӿ)*/
	{.bitmap_index = 73745, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ӿ)*/
	{.bitmap_index = 936938, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 3},/*(Ա)*/
	{.bitmap_index = 936993, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Բ)*/
	{.bitmap_index = 937033, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Գ)*/
	{.bitmap_index = 937093, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Դ)*/
	{.bitmap_index = 937153, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ե)*/
	{.bitmap_index = 937193, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Զ)*/
	{.bitmap_index = 937243, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Է)*/
	{.bitmap_index = 937283, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ը)*/
	{.bitmap_index = 937323, .adv_w = 13, .box_h = 10, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Թ)*/
	{.bitmap_index = 937383, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ժ)*/
	{.bitmap_index = 937443, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ի)*/
	{.bitmap_index = 937483, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Լ)*/
	{.bitmap_index = 937523, .adv_w = 13, .box_h = 10, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(Խ)*/
	{.bitmap_index = 937583, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ծ)*/
	{.bitmap_index = 937633, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Կ)*/
	{.bitmap_index = 937673, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(Հ)*/
	{.bitmap_index = 937713, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ձ)*/
	{.bitmap_index = 937763, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ղ)*/
	{.bitmap_index = 937823, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ճ)*/
	{.bitmap_index = 937873, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Մ)*/
	{.bitmap_index = 937923, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Յ)*/
	{.bitmap_index = 937973, .adv_w = 11, .box_h = 10, .box_w = 12, .ofs_x = -1, .ofs_y = 4},/*(Ն)*/
	{.bitmap_index = 938033, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Շ)*/
	{.bitmap_index = 938083, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ո)*/
	{.bitmap_index = 938123, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Չ)*/
	{.bitmap_index = 938173, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Պ)*/
	{.bitmap_index = 938223, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ջ)*/
	{.bitmap_index = 938273, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ռ)*/
	{.bitmap_index = 938323, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ս)*/
	{.bitmap_index = 938363, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Վ)*/
	{.bitmap_index = 938423, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Տ)*/
	{.bitmap_index = 938473, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ր)*/
	{.bitmap_index = 938513, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(Ց)*/
	{.bitmap_index = 938563, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(Ւ)*/
	{.bitmap_index = 938603, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Փ)*/
	{.bitmap_index = 938663, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Ք)*/
	{.bitmap_index = 938713, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(Օ)*/
	{.bitmap_index = 938763, .adv_w = 12, .box_h = 10, .box_w = 12, .ofs_x = 0, .ofs_y = 4},/*(Ֆ)*/
	{.bitmap_index = 938823, .adv_w = 5, .box_h = 4, .box_w = 4, .ofs_x = 1, .ofs_y = 11},/*(ՙ)*/
	{.bitmap_index = 938831, .adv_w = 4, .box_h = 4, .box_w = 4, .ofs_x = 0, .ofs_y = 11},/*(՚)*/
	{.bitmap_index = 938839, .adv_w = 3, .box_h = 3, .box_w = 4, .ofs_x = -1, .ofs_y = 12},/*(՛)*/
	{.bitmap_index = 938845, .adv_w = 5, .box_h = 4, .box_w = 6, .ofs_x = -1, .ofs_y = 12},/*(՜)*/
	{.bitmap_index = 938857, .adv_w = 4, .box_h = 3, .box_w = 4, .ofs_x = 0, .ofs_y = 13},/*(՝)*/
	{.bitmap_index = 938863, .adv_w = 6, .box_h = 4, .box_w = 6, .ofs_x = 0, .ofs_y = 13},/*(՞)*/
	{.bitmap_index = 938875, .adv_w = 0, .box_h = 3, .box_w = 8, .ofs_x = -8, .ofs_y = 15},/*(՟)*/
	{.bitmap_index = 938887, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(ՠ)*/
	{.bitmap_index = 938943, .adv_w = 13, .box_h = 7, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(ա)*/
	{.bitmap_index = 938985, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(բ)*/
	{.bitmap_index = 939025, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(գ)*/
	{.bitmap_index = 939075, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(դ)*/
	{.bitmap_index = 939125, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ե)*/
	{.bitmap_index = 939169, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(զ)*/
	{.bitmap_index = 939219, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(է)*/
	{.bitmap_index = 939263, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(ը)*/
	{.bitmap_index = 939303, .adv_w = 13, .box_h = 10, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(թ)*/
	{.bitmap_index = 939363, .adv_w = 10, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(ժ)*/
	{.bitmap_index = 939418, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(ի)*/
	{.bitmap_index = 939474, .adv_w = 5, .box_h = 10, .box_w = 4, .ofs_x = 1, .ofs_y = 1},/*(լ)*/
	{.bitmap_index = 939494, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(խ)*/
	{.bitmap_index = 939578, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ծ)*/
	{.bitmap_index = 939622, .adv_w = 9, .box_h = 14, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(կ)*/
	{.bitmap_index = 939678, .adv_w = 9, .box_h = 11, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(հ)*/
	{.bitmap_index = 939722, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ձ)*/
	{.bitmap_index = 939766, .adv_w = 11, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(ղ)*/
	{.bitmap_index = 939816, .adv_w = 8, .box_h = 11, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(ճ)*/
	{.bitmap_index = 939860, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(մ)*/
	{.bitmap_index = 939915, .adv_w = 3, .box_h = 10, .box_w = 4, .ofs_x = -1, .ofs_y = 1},/*(յ)*/
	{.bitmap_index = 939935, .adv_w = 9, .box_h = 11, .box_w = 10, .ofs_x = -1, .ofs_y = 4},/*(ն)*/
	{.bitmap_index = 939990, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(շ)*/
	{.bitmap_index = 940030, .adv_w = 9, .box_h = 7, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ո)*/
	{.bitmap_index = 940058, .adv_w = 6, .box_h = 10, .box_w = 6, .ofs_x = 0, .ofs_y = 1},/*(չ)*/
	{.bitmap_index = 940088, .adv_w = 13, .box_h = 10, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(պ)*/
	{.bitmap_index = 940148, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ջ)*/
	{.bitmap_index = 940188, .adv_w = 9, .box_h = 7, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ռ)*/
	{.bitmap_index = 940216, .adv_w = 9, .box_h = 7, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(ս)*/
	{.bitmap_index = 940244, .adv_w = 11, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 1},/*(վ)*/
	{.bitmap_index = 940314, .adv_w = 13, .box_h = 7, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(տ)*/
	{.bitmap_index = 940356, .adv_w = 9, .box_h = 10, .box_w = 8, .ofs_x = 1, .ofs_y = 1},/*(ր)*/
	{.bitmap_index = 940396, .adv_w = 8, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*(ց)*/
	{.bitmap_index = 940436, .adv_w = 7, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(ւ)*/
	{.bitmap_index = 940457, .adv_w = 13, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 1},/*(փ)*/
	{.bitmap_index = 940541, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ք)*/
	{.bitmap_index = 940591, .adv_w = 8, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 4},/*(օ)*/
	{.bitmap_index = 940619, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*(ֆ)*/
	{.bitmap_index = 940689, .adv_w = 11, .box_h = 11, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(և)*/
	{.bitmap_index = 940744, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 0},/*(ֈ)*/
	{.bitmap_index = 940800, .adv_w = 5, .box_h = 7, .box_w = 4, .ofs_x = 1, .ofs_y = 4},/*(։)*/
	{.bitmap_index = 940814, .adv_w = 6, .box_h = 2, .box_w = 6, .ofs_x = 0, .ofs_y = 7},/*(֊)*/
	{.bitmap_index = 940820, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 1},/*(֍)*/
	{.bitmap_index = 940932, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 1},/*(֎)*/
	{.bitmap_index = 941044, .adv_w = 10, .box_h = 10, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(֏)*/
	{.bitmap_index = 73843, .adv_w = 4, .box_h = 6, .box_w = 4, .ofs_x = 0, .ofs_y = 13},/*(‘)*/
	{.bitmap_index = 73855, .adv_w = 4, .box_h = 6, .box_w = 4, .ofs_x = 0, .ofs_y = 13},/*(’)*/
	{.bitmap_index = 73867, .adv_w = 8, .box_h = 6, .box_w = 8, .ofs_x = 0, .ofs_y = 13},/*(“)*/
	{.bitmap_index = 73891, .adv_w = 8, .box_h = 6, .box_w = 8, .ofs_x = 0, .ofs_y = 13},/*(”)*/
	{.bitmap_index = 73915, .adv_w = 18, .box_h = 15, .box_w = 18, .ofs_x = 0, .ofs_y = 4},/*(℃)*/
	{.bitmap_index = 74050, .adv_w = 7, .box_h = 5, .box_w = 6, .ofs_x = 1, .ofs_y = 3},/*(、)*/
	{.bitmap_index = 74065, .adv_w = 7, .box_h = 5, .box_w = 6, .ofs_x = 1, .ofs_y = 3},/*(。)*/
	{.bitmap_index = 74080, .adv_w = 16, .box_h = 15, .box_w = 10, .ofs_x = 6, .ofs_y = 4},/*(《)*/
	{.bitmap_index = 74155, .adv_w = 11, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = 4},/*(》)*/
	{.bitmap_index = 74230, .adv_w = 16, .box_h = 15, .box_w = 6, .ofs_x = 10, .ofs_y = 4},/*(【)*/
	{.bitmap_index = 74275, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(】)*/
	{.bitmap_index = 941094, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ぁ)*/
	{.bitmap_index = 941144, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(あ)*/
	{.bitmap_index = 941235, .adv_w = 15, .box_h = 8, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ぃ)*/
	{.bitmap_index = 941283, .adv_w = 16, .box_h = 10, .box_w = 14, .ofs_x = 2, .ofs_y = 5},/*(い)*/
	{.bitmap_index = 941353, .adv_w = 12, .box_h = 10, .box_w = 8, .ofs_x = 4, .ofs_y = 4},/*(ぅ)*/
	{.bitmap_index = 941393, .adv_w = 13, .box_h = 12, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(う)*/
	{.bitmap_index = 941453, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ぇ)*/
	{.bitmap_index = 941503, .adv_w = 16, .box_h = 12, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(え)*/
	{.bitmap_index = 941587, .adv_w = 14, .box_h = 9, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ぉ)*/
	{.bitmap_index = 941641, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(お)*/
	{.bitmap_index = 941725, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(か)*/
	{.bitmap_index = 941809, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(が)*/
	{.bitmap_index = 941913, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(き)*/
	{.bitmap_index = 941991, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ぎ)*/
	{.bitmap_index = 942089, .adv_w = 13, .box_h = 13, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(く)*/
	{.bitmap_index = 942154, .adv_w = 15, .box_h = 13, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ぐ)*/
	{.bitmap_index = 942232, .adv_w = 16, .box_h = 13, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(け)*/
	{.bitmap_index = 942323, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(げ)*/
	{.bitmap_index = 942428, .adv_w = 15, .box_h = 11, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(こ)*/
	{.bitmap_index = 942494, .adv_w = 16, .box_h = 13, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ご)*/
	{.bitmap_index = 942585, .adv_w = 13, .box_h = 13, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(さ)*/
	{.bitmap_index = 942650, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ざ)*/
	{.bitmap_index = 942748, .adv_w = 14, .box_h = 13, .box_w = 10, .ofs_x = 4, .ofs_y = 4},/*(し)*/
	{.bitmap_index = 942813, .adv_w = 14, .box_h = 13, .box_w = 10, .ofs_x = 4, .ofs_y = 4},/*(じ)*/
	{.bitmap_index = 942878, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(す)*/
	{.bitmap_index = 942969, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ず)*/
	{.bitmap_index = 943089, .adv_w = 16, .box_h = 13, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(せ)*/
	{.bitmap_index = 943193, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(ぜ)*/
	{.bitmap_index = 943313, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(そ)*/
	{.bitmap_index = 943404, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぞ)*/
	{.bitmap_index = 943516, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(た)*/
	{.bitmap_index = 943607, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(だ)*/
	{.bitmap_index = 943711, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ち)*/
	{.bitmap_index = 943802, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ぢ)*/
	{.bitmap_index = 943900, .adv_w = 14, .box_h = 8, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(っ)*/
	{.bitmap_index = 943948, .adv_w = 15, .box_h = 9, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(つ)*/
	{.bitmap_index = 944011, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(づ)*/
	{.bitmap_index = 944123, .adv_w = 15, .box_h = 11, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(て)*/
	{.bitmap_index = 944200, .adv_w = 17, .box_h = 11, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(で)*/
	{.bitmap_index = 944288, .adv_w = 13, .box_h = 13, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(と)*/
	{.bitmap_index = 944353, .adv_w = 17, .box_h = 14, .box_w = 14, .ofs_x = 3, .ofs_y = 4},/*(ど)*/
	{.bitmap_index = 944451, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(な)*/
	{.bitmap_index = 944542, .adv_w = 16, .box_h = 12, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(に)*/
	{.bitmap_index = 944626, .adv_w = 17, .box_h = 12, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぬ)*/
	{.bitmap_index = 944722, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ね)*/
	{.bitmap_index = 944826, .adv_w = 15, .box_h = 11, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(の)*/
	{.bitmap_index = 944903, .adv_w = 16, .box_h = 12, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(は)*/
	{.bitmap_index = 944987, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ば)*/
	{.bitmap_index = 945085, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ぱ)*/
	{.bitmap_index = 945183, .adv_w = 17, .box_h = 11, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ひ)*/
	{.bitmap_index = 945271, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(び)*/
	{.bitmap_index = 945383, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぴ)*/
	{.bitmap_index = 945487, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ふ)*/
	{.bitmap_index = 945591, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぶ)*/
	{.bitmap_index = 945695, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぷ)*/
	{.bitmap_index = 945799, .adv_w = 17, .box_h = 8, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(へ)*/
	{.bitmap_index = 945863, .adv_w = 17, .box_h = 10, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(べ)*/
	{.bitmap_index = 945943, .adv_w = 17, .box_h = 10, .box_w = 16, .ofs_x = 1, .ofs_y = 6},/*(ぺ)*/
	{.bitmap_index = 946023, .adv_w = 16, .box_h = 12, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ほ)*/
	{.bitmap_index = 946107, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぼ)*/
	{.bitmap_index = 946219, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ぽ)*/
	{.bitmap_index = 946331, .adv_w = 15, .box_h = 13, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ま)*/
	{.bitmap_index = 946409, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(み)*/
	{.bitmap_index = 946493, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(む)*/
	{.bitmap_index = 946584, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(め)*/
	{.bitmap_index = 946668, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(も)*/
	{.bitmap_index = 946746, .adv_w = 14, .box_h = 11, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ゃ)*/
	{.bitmap_index = 946812, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(や)*/
	{.bitmap_index = 946903, .adv_w = 13, .box_h = 11, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ゅ)*/
	{.bitmap_index = 946958, .adv_w = 16, .box_h = 13, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ゆ)*/
	{.bitmap_index = 947049, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ょ)*/
	{.bitmap_index = 947099, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(よ)*/
	{.bitmap_index = 947177, .adv_w = 15, .box_h = 13, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ら)*/
	{.bitmap_index = 947255, .adv_w = 12, .box_h = 13, .box_w = 8, .ofs_x = 4, .ofs_y = 4},/*(り)*/
	{.bitmap_index = 947307, .adv_w = 14, .box_h = 12, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(る)*/
	{.bitmap_index = 947379, .adv_w = 17, .box_h = 13, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(れ)*/
	{.bitmap_index = 947483, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ろ)*/
	{.bitmap_index = 947561, .adv_w = 14, .box_h = 10, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ゎ)*/
	{.bitmap_index = 947621, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(わ)*/
	{.bitmap_index = 947712, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ゐ)*/
	{.bitmap_index = 947796, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ゑ)*/
	{.bitmap_index = 947887, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(を)*/
	{.bitmap_index = 947965, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ん)*/
	{.bitmap_index = 948049, .adv_w = 17, .box_h = 13, .box_w = 14, .ofs_x = 3, .ofs_y = 4},/*(ゔ)*/
	{.bitmap_index = 948140, .adv_w = 14, .box_h = 10, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ゕ)*/
	{.bitmap_index = 948200, .adv_w = 15, .box_h = 10, .box_w = 12, .ofs_x = 3, .ofs_y = 3},/*(ゖ)*/
	{.bitmap_index = 948260, .adv_w = 2, .box_h = 4, .box_w = 6, .ofs_x = -4, .ofs_y = 14},/*(゙)*/
	{.bitmap_index = 948272, .adv_w = 1, .box_h = 4, .box_w = 4, .ofs_x = -3, .ofs_y = 14},/*(゚)*/
	{.bitmap_index = 948280, .adv_w = 6, .box_h = 4, .box_w = 6, .ofs_x = 0, .ofs_y = 14},/*(゛)*/
	{.bitmap_index = 948292, .adv_w = 4, .box_h = 4, .box_w = 4, .ofs_x = 0, .ofs_y = 14},/*(゜)*/
	{.bitmap_index = 948300, .adv_w = 11, .box_h = 8, .box_w = 6, .ofs_x = 5, .ofs_y = 6},/*(ゝ)*/
	{.bitmap_index = 948324, .adv_w = 15, .box_h = 9, .box_w = 10, .ofs_x = 5, .ofs_y = 6},/*(ゞ)*/
	{.bitmap_index = 948369, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ゟ)*/
	{.bitmap_index = 948447, .adv_w = 12, .box_h = 4, .box_w = 8, .ofs_x = 4, .ofs_y = 8},/*(゠)*/
	{.bitmap_index = 948463, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ァ)*/
	{.bitmap_index = 948513, .adv_w = 16, .box_h = 12, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ア)*/
	{.bitmap_index = 948597, .adv_w = 12, .box_h = 10, .box_w = 10, .ofs_x = 2, .ofs_y = 4},/*(ィ)*/
	{.bitmap_index = 948647, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(イ)*/
	{.bitmap_index = 948725, .adv_w = 14, .box_h = 10, .box_w = 10, .ofs_x = 4, .ofs_y = 4},/*(ゥ)*/
	{.bitmap_index = 948775, .adv_w = 15, .box_h = 13, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ウ)*/
	{.bitmap_index = 948853, .adv_w = 13, .box_h = 8, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ェ)*/
	{.bitmap_index = 948893, .adv_w = 15, .box_h = 10, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(エ)*/
	{.bitmap_index = 948963, .adv_w = 14, .box_h = 10, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ォ)*/
	{.bitmap_index = 949023, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(オ)*/
	{.bitmap_index = 949107, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(カ)*/
	{.bitmap_index = 949191, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ガ)*/
	{.bitmap_index = 949303, .adv_w = 14, .box_h = 12, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(キ)*/
	{.bitmap_index = 949375, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ギ)*/
	{.bitmap_index = 949473, .adv_w = 14, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 3},/*(ク)*/
	{.bitmap_index = 949557, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 3},/*(グ)*/
	{.bitmap_index = 949662, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ケ)*/
	{.bitmap_index = 949753, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ゲ)*/
	{.bitmap_index = 949865, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 5},/*(コ)*/
	{.bitmap_index = 949915, .adv_w = 16, .box_h = 13, .box_w = 14, .ofs_x = 2, .ofs_y = 5},/*(ゴ)*/
	{.bitmap_index = 950006, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(サ)*/
	{.bitmap_index = 950097, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ザ)*/
	{.bitmap_index = 950209, .adv_w = 16, .box_h = 12, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(シ)*/
	{.bitmap_index = 950293, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ジ)*/
	{.bitmap_index = 950391, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ス)*/
	{.bitmap_index = 950475, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ズ)*/
	{.bitmap_index = 950587, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(セ)*/
	{.bitmap_index = 950671, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(ゼ)*/
	{.bitmap_index = 950783, .adv_w = 14, .box_h = 11, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ソ)*/
	{.bitmap_index = 950849, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ゾ)*/
	{.bitmap_index = 950954, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(タ)*/
	{.bitmap_index = 951032, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ダ)*/
	{.bitmap_index = 951152, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(チ)*/
	{.bitmap_index = 951236, .adv_w = 17, .box_h = 12, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ヂ)*/
	{.bitmap_index = 951332, .adv_w = 13, .box_h = 8, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ッ)*/
	{.bitmap_index = 951372, .adv_w = 14, .box_h = 11, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ツ)*/
	{.bitmap_index = 951438, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ヅ)*/
	{.bitmap_index = 951558, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(テ)*/
	{.bitmap_index = 951642, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(デ)*/
	{.bitmap_index = 951754, .adv_w = 13, .box_h = 13, .box_w = 8, .ofs_x = 5, .ofs_y = 4},/*(ト)*/
	{.bitmap_index = 951806, .adv_w = 15, .box_h = 14, .box_w = 10, .ofs_x = 5, .ofs_y = 4},/*(ド)*/
	{.bitmap_index = 951876, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ナ)*/
	{.bitmap_index = 951960, .adv_w = 15, .box_h = 10, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(ニ)*/
	{.bitmap_index = 952030, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ヌ)*/
	{.bitmap_index = 952114, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ネ)*/
	{.bitmap_index = 952205, .adv_w = 14, .box_h = 12, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ノ)*/
	{.bitmap_index = 952277, .adv_w = 15, .box_h = 8, .box_w = 14, .ofs_x = 1, .ofs_y = 6},/*(ハ)*/
	{.bitmap_index = 952333, .adv_w = 16, .box_h = 10, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(バ)*/
	{.bitmap_index = 952413, .adv_w = 16, .box_h = 10, .box_w = 16, .ofs_x = 0, .ofs_y = 6},/*(パ)*/
	{.bitmap_index = 952493, .adv_w = 13, .box_h = 11, .box_w = 10, .ofs_x = 3, .ofs_y = 5},/*(ヒ)*/
	{.bitmap_index = 952548, .adv_w = 17, .box_h = 13, .box_w = 14, .ofs_x = 3, .ofs_y = 5},/*(ビ)*/
	{.bitmap_index = 952639, .adv_w = 17, .box_h = 11, .box_w = 14, .ofs_x = 3, .ofs_y = 5},/*(ピ)*/
	{.bitmap_index = 952716, .adv_w = 14, .box_h = 11, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(フ)*/
	{.bitmap_index = 952782, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ブ)*/
	{.bitmap_index = 952880, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(プ)*/
	{.bitmap_index = 952978, .adv_w = 15, .box_h = 7, .box_w = 14, .ofs_x = 1, .ofs_y = 6},/*(ヘ)*/
	{.bitmap_index = 953027, .adv_w = 15, .box_h = 10, .box_w = 14, .ofs_x = 1, .ofs_y = 6},/*(ベ)*/
	{.bitmap_index = 953097, .adv_w = 15, .box_h = 9, .box_w = 14, .ofs_x = 1, .ofs_y = 6},/*(ペ)*/
	{.bitmap_index = 953160, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ホ)*/
	{.bitmap_index = 953244, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ボ)*/
	{.bitmap_index = 953356, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ポ)*/
	{.bitmap_index = 953454, .adv_w = 15, .box_h = 10, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(マ)*/
	{.bitmap_index = 953524, .adv_w = 13, .box_h = 13, .box_w = 10, .ofs_x = 3, .ofs_y = 3},/*(ミ)*/
	{.bitmap_index = 953589, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ム)*/
	{.bitmap_index = 953673, .adv_w = 13, .box_h = 12, .box_w = 12, .ofs_x = 1, .ofs_y = 4},/*(メ)*/
	{.bitmap_index = 953745, .adv_w = 15, .box_h = 11, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(モ)*/
	{.bitmap_index = 953822, .adv_w = 14, .box_h = 10, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ャ)*/
	{.bitmap_index = 953882, .adv_w = 15, .box_h = 12, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ヤ)*/
	{.bitmap_index = 953966, .adv_w = 14, .box_h = 8, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ュ)*/
	{.bitmap_index = 954014, .adv_w = 15, .box_h = 10, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(ユ)*/
	{.bitmap_index = 954084, .adv_w = 12, .box_h = 9, .box_w = 8, .ofs_x = 4, .ofs_y = 4},/*(ョ)*/
	{.bitmap_index = 954120, .adv_w = 13, .box_h = 12, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ヨ)*/
	{.bitmap_index = 954180, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ラ)*/
	{.bitmap_index = 954258, .adv_w = 12, .box_h = 12, .box_w = 8, .ofs_x = 4, .ofs_y = 4},/*(リ)*/
	{.bitmap_index = 954306, .adv_w = 17, .box_h = 10, .box_w = 16, .ofs_x = 1, .ofs_y = 5},/*(ル)*/
	{.bitmap_index = 954386, .adv_w = 15, .box_h = 10, .box_w = 12, .ofs_x = 3, .ofs_y = 5},/*(レ)*/
	{.bitmap_index = 954446, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 5},/*(ロ)*/
	{.bitmap_index = 954496, .adv_w = 14, .box_h = 10, .box_w = 10, .ofs_x = 4, .ofs_y = 4},/*(ヮ)*/
	{.bitmap_index = 954546, .adv_w = 15, .box_h = 12, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ワ)*/
	{.bitmap_index = 954618, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(ヰ)*/
	{.bitmap_index = 954709, .adv_w = 15, .box_h = 10, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(ヱ)*/
	{.bitmap_index = 954779, .adv_w = 15, .box_h = 12, .box_w = 12, .ofs_x = 3, .ofs_y = 4},/*(ヲ)*/
	{.bitmap_index = 954851, .adv_w = 16, .box_h = 11, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ン)*/
	{.bitmap_index = 954928, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ヴ)*/
	{.bitmap_index = 955026, .adv_w = 13, .box_h = 10, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ヵ)*/
	{.bitmap_index = 955076, .adv_w = 14, .box_h = 10, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(ヶ)*/
	{.bitmap_index = 955136, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ヷ)*/
	{.bitmap_index = 955234, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ヸ)*/
	{.bitmap_index = 955354, .adv_w = 17, .box_h = 14, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(ヹ)*/
	{.bitmap_index = 955466, .adv_w = 16, .box_h = 14, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(ヺ)*/
	{.bitmap_index = 955564, .adv_w = 10, .box_h = 3, .box_w = 4, .ofs_x = 6, .ofs_y = 9},/*(・)*/
	{.bitmap_index = 955570, .adv_w = 15, .box_h = 3, .box_w = 14, .ofs_x = 1, .ofs_y = 8},/*(ー)*/
	{.bitmap_index = 955591, .adv_w = 12, .box_h = 6, .box_w = 8, .ofs_x = 4, .ofs_y = 7},/*(ヽ)*/
	{.bitmap_index = 955615, .adv_w = 14, .box_h = 8, .box_w = 10, .ofs_x = 4, .ofs_y = 7},/*(ヾ)*/
	{.bitmap_index = 955655, .adv_w = 13, .box_h = 12, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(ヿ)*/
	{.bitmap_index = 74320, .adv_w = 16, .box_h = 3, .box_w = 16, .ofs_x = 0, .ofs_y = 11},/*(一)*/
	{.bitmap_index = 74344, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(丁)*/
	{.bitmap_index = 74449, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(七)*/
	{.bitmap_index = 74569, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(万)*/
	{.bitmap_index = 74689, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(丈)*/
	{.bitmap_index = 74825, .adv_w = 16, .box_h = 13, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(三)*/
	{.bitmap_index = 74929, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(上)*/
	{.bitmap_index = 75057, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(下)*/
	{.bitmap_index = 75177, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(丌)*/
	{.bitmap_index = 75297, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(不)*/
	{.bitmap_index = 75417, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(与)*/
	{.bitmap_index = 75537, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(丐)*/
	{.bitmap_index = 75642, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丑)*/
	{.bitmap_index = 75762, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(专)*/
	{.bitmap_index = 75898, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(且)*/
	{.bitmap_index = 76018, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丕)*/
	{.bitmap_index = 76138, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(世)*/
	{.bitmap_index = 76258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丘)*/
	{.bitmap_index = 76386, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丙)*/
	{.bitmap_index = 76506, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(业)*/
	{.bitmap_index = 76626, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丛)*/
	{.bitmap_index = 76746, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(东)*/
	{.bitmap_index = 76874, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丝)*/
	{.bitmap_index = 77002, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丞)*/
	{.bitmap_index = 77122, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(丢)*/
	{.bitmap_index = 77250, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(两)*/
	{.bitmap_index = 77370, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(严)*/
	{.bitmap_index = 77498, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(丧)*/
	{.bitmap_index = 77634, .adv_w = 10, .box_h = 15, .box_w = 4, .ofs_x = 6, .ofs_y = 4},/*(丨)*/
	{.bitmap_index = 77664, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(个)*/
	{.bitmap_index = 77792, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(丫)*/
	{.bitmap_index = 77904, .adv_w = 11, .box_h = 16, .box_w = 8, .ofs_x = 3, .ofs_y = 4},/*(丬)*/
	{.bitmap_index = 77968, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(中)*/
	{.bitmap_index = 78080, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丰)*/
	{.bitmap_index = 78200, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(串)*/
	{.bitmap_index = 78312, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(临)*/
	{.bitmap_index = 78440, .adv_w = 12, .box_h = 8, .box_w = 8, .ofs_x = 4, .ofs_y = 8},/*(丶)*/
	{.bitmap_index = 78472, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丸)*/
	{.bitmap_index = 78592, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(丹)*/
	{.bitmap_index = 78720, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(为)*/
	{.bitmap_index = 78848, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(主)*/
	{.bitmap_index = 78976, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(丽)*/
	{.bitmap_index = 79096, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(举)*/
	{.bitmap_index = 79224, .adv_w = 11, .box_h = 16, .box_w = 8, .ofs_x = 3, .ofs_y = 3},/*(丿)*/
	{.bitmap_index = 79288, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(乃)*/
	{.bitmap_index = 79416, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(久)*/
	{.bitmap_index = 79552, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乇)*/
	{.bitmap_index = 79672, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(么)*/
	{.bitmap_index = 79800, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(义)*/
	{.bitmap_index = 79936, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(之)*/
	{.bitmap_index = 80064, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(乌)*/
	{.bitmap_index = 80176, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乍)*/
	{.bitmap_index = 80304, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乎)*/
	{.bitmap_index = 80424, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乏)*/
	{.bitmap_index = 80544, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乐)*/
	{.bitmap_index = 80664, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(乒)*/
	{.bitmap_index = 80792, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(乓)*/
	{.bitmap_index = 80920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(乔)*/
	{.bitmap_index = 81048, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乖)*/
	{.bitmap_index = 81168, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乘)*/
	{.bitmap_index = 81288, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(乙)*/
	{.bitmap_index = 81408, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乜)*/
	{.bitmap_index = 81528, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(九)*/
	{.bitmap_index = 81656, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乞)*/
	{.bitmap_index = 81784, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(也)*/
	{.bitmap_index = 81904, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(习)*/
	{.bitmap_index = 82024, .adv_w = 14, .box_h = 17, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*(乡)*/
	{.bitmap_index = 82143, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(书)*/
	{.bitmap_index = 82271, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(乩)*/
	{.bitmap_index = 82391, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(买)*/
	{.bitmap_index = 82519, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乱)*/
	{.bitmap_index = 82639, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乳)*/
	{.bitmap_index = 82759, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(乾)*/
	{.bitmap_index = 82887, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(了)*/
	{.bitmap_index = 82992, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(予)*/
	{.bitmap_index = 83112, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(争)*/
	{.bitmap_index = 83240, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(事)*/
	{.bitmap_index = 83368, .adv_w = 16, .box_h = 13, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(二)*/
	{.bitmap_index = 83472, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(亍)*/
	{.bitmap_index = 83577, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(于)*/
	{.bitmap_index = 83697, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亏)*/
	{.bitmap_index = 83817, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(云)*/
	{.bitmap_index = 83922, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(互)*/
	{.bitmap_index = 84042, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(亓)*/
	{.bitmap_index = 84170, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(五)*/
	{.bitmap_index = 84282, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(井)*/
	{.bitmap_index = 84410, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亘)*/
	{.bitmap_index = 84530, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亚)*/
	{.bitmap_index = 84650, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(些)*/
	{.bitmap_index = 84770, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(亟)*/
	{.bitmap_index = 84890, .adv_w = 16, .box_h = 6, .box_w = 16, .ofs_x = 0, .ofs_y = 13},/*(亠)*/
	{.bitmap_index = 84938, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亡)*/
	{.bitmap_index = 85058, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(亢)*/
	{.bitmap_index = 85186, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(交)*/
	{.bitmap_index = 85322, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(亥)*/
	{.bitmap_index = 85458, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(亦)*/
	{.bitmap_index = 85594, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(产)*/
	{.bitmap_index = 85730, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(亨)*/
	{.bitmap_index = 85842, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(亩)*/
	{.bitmap_index = 85970, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(享)*/
	{.bitmap_index = 86090, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(京)*/
	{.bitmap_index = 86218, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(亭)*/
	{.bitmap_index = 86330, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(亮)*/
	{.bitmap_index = 86466, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亲)*/
	{.bitmap_index = 86594, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亳)*/
	{.bitmap_index = 86722, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(亵)*/
	{.bitmap_index = 86858, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(人)*/
	{.bitmap_index = 86986, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(亻)*/
	{.bitmap_index = 87066, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(亿)*/
	{.bitmap_index = 87194, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(什)*/
	{.bitmap_index = 87322, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仁)*/
	{.bitmap_index = 87450, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仂)*/
	{.bitmap_index = 87578, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仃)*/
	{.bitmap_index = 87706, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(仄)*/
	{.bitmap_index = 87834, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(仅)*/
	{.bitmap_index = 87970, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仆)*/
	{.bitmap_index = 88098, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仇)*/
	{.bitmap_index = 88226, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(仉)*/
	{.bitmap_index = 88354, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(今)*/
	{.bitmap_index = 88490, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(介)*/
	{.bitmap_index = 88626, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仍)*/
	{.bitmap_index = 88746, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(从)*/
	{.bitmap_index = 88874, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仑)*/
	{.bitmap_index = 89002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仓)*/
	{.bitmap_index = 89130, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仔)*/
	{.bitmap_index = 89258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仕)*/
	{.bitmap_index = 89386, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(他)*/
	{.bitmap_index = 89506, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仗)*/
	{.bitmap_index = 89634, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(付)*/
	{.bitmap_index = 89762, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仙)*/
	{.bitmap_index = 89890, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仝)*/
	{.bitmap_index = 90018, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(仞)*/
	{.bitmap_index = 90146, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仟)*/
	{.bitmap_index = 90274, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仡)*/
	{.bitmap_index = 90402, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(代)*/
	{.bitmap_index = 90530, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(令)*/
	{.bitmap_index = 90666, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(以)*/
	{.bitmap_index = 90794, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仨)*/
	{.bitmap_index = 90922, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(仪)*/
	{.bitmap_index = 91058, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仫)*/
	{.bitmap_index = 91186, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(们)*/
	{.bitmap_index = 91314, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仰)*/
	{.bitmap_index = 91442, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仲)*/
	{.bitmap_index = 91570, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仳)*/
	{.bitmap_index = 91698, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仵)*/
	{.bitmap_index = 91826, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(件)*/
	{.bitmap_index = 91954, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(价)*/
	{.bitmap_index = 92090, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(任)*/
	{.bitmap_index = 92218, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(份)*/
	{.bitmap_index = 92354, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(仿)*/
	{.bitmap_index = 92482, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(企)*/
	{.bitmap_index = 92610, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伉)*/
	{.bitmap_index = 92730, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(伊)*/
	{.bitmap_index = 92866, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伍)*/
	{.bitmap_index = 92994, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(伎)*/
	{.bitmap_index = 93130, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(伏)*/
	{.bitmap_index = 93266, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伐)*/
	{.bitmap_index = 93394, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(休)*/
	{.bitmap_index = 93522, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(众)*/
	{.bitmap_index = 93658, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(优)*/
	{.bitmap_index = 93786, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(伙)*/
	{.bitmap_index = 93914, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(会)*/
	{.bitmap_index = 94050, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伛)*/
	{.bitmap_index = 94178, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伞)*/
	{.bitmap_index = 94306, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伟)*/
	{.bitmap_index = 94434, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(传)*/
	{.bitmap_index = 94570, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伢)*/
	{.bitmap_index = 94698, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(伤)*/
	{.bitmap_index = 94834, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伥)*/
	{.bitmap_index = 94962, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伦)*/
	{.bitmap_index = 95090, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伧)*/
	{.bitmap_index = 95218, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伪)*/
	{.bitmap_index = 95338, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伫)*/
	{.bitmap_index = 95466, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伯)*/
	{.bitmap_index = 95594, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(估)*/
	{.bitmap_index = 95714, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伲)*/
	{.bitmap_index = 95834, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伴)*/
	{.bitmap_index = 95962, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(伶)*/
	{.bitmap_index = 96098, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伸)*/
	{.bitmap_index = 96226, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伺)*/
	{.bitmap_index = 96354, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(似)*/
	{.bitmap_index = 96490, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(伽)*/
	{.bitmap_index = 96618, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佃)*/
	{.bitmap_index = 96746, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(但)*/
	{.bitmap_index = 96866, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(位)*/
	{.bitmap_index = 96994, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(低)*/
	{.bitmap_index = 97130, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(住)*/
	{.bitmap_index = 97258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佐)*/
	{.bitmap_index = 97386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佑)*/
	{.bitmap_index = 97514, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(体)*/
	{.bitmap_index = 97642, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(何)*/
	{.bitmap_index = 97770, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佗)*/
	{.bitmap_index = 97898, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佘)*/
	{.bitmap_index = 98026, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(余)*/
	{.bitmap_index = 98154, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(佚)*/
	{.bitmap_index = 98290, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(佛)*/
	{.bitmap_index = 98426, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(作)*/
	{.bitmap_index = 98554, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佝)*/
	{.bitmap_index = 98682, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(佞)*/
	{.bitmap_index = 98818, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佟)*/
	{.bitmap_index = 98946, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(你)*/
	{.bitmap_index = 99074, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佣)*/
	{.bitmap_index = 99202, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佤)*/
	{.bitmap_index = 99330, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佥)*/
	{.bitmap_index = 99458, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佧)*/
	{.bitmap_index = 99586, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佩)*/
	{.bitmap_index = 99706, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佬)*/
	{.bitmap_index = 99834, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佯)*/
	{.bitmap_index = 99962, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佰)*/
	{.bitmap_index = 100090, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佳)*/
	{.bitmap_index = 100218, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佴)*/
	{.bitmap_index = 100346, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佶)*/
	{.bitmap_index = 100474, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佻)*/
	{.bitmap_index = 100602, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(佼)*/
	{.bitmap_index = 100730, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(佾)*/
	{.bitmap_index = 100858, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(使)*/
	{.bitmap_index = 100994, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侃)*/
	{.bitmap_index = 101114, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侄)*/
	{.bitmap_index = 101242, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侈)*/
	{.bitmap_index = 101378, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侉)*/
	{.bitmap_index = 101506, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(例)*/
	{.bitmap_index = 101642, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侍)*/
	{.bitmap_index = 101770, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侏)*/
	{.bitmap_index = 101898, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侑)*/
	{.bitmap_index = 102026, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侔)*/
	{.bitmap_index = 102154, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侗)*/
	{.bitmap_index = 102282, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(供)*/
	{.bitmap_index = 102410, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(依)*/
	{.bitmap_index = 102538, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侠)*/
	{.bitmap_index = 102666, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侣)*/
	{.bitmap_index = 102794, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侥)*/
	{.bitmap_index = 102930, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侦)*/
	{.bitmap_index = 103058, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侧)*/
	{.bitmap_index = 103186, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侨)*/
	{.bitmap_index = 103322, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侩)*/
	{.bitmap_index = 103450, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侪)*/
	{.bitmap_index = 103586, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侬)*/
	{.bitmap_index = 103714, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(侮)*/
	{.bitmap_index = 103842, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侯)*/
	{.bitmap_index = 103978, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(侵)*/
	{.bitmap_index = 104114, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(便)*/
	{.bitmap_index = 104250, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(促)*/
	{.bitmap_index = 104386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俄)*/
	{.bitmap_index = 104514, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俅)*/
	{.bitmap_index = 104642, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(俊)*/
	{.bitmap_index = 104778, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俎)*/
	{.bitmap_index = 104898, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俏)*/
	{.bitmap_index = 105026, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俐)*/
	{.bitmap_index = 105154, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俑)*/
	{.bitmap_index = 105282, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俗)*/
	{.bitmap_index = 105402, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俘)*/
	{.bitmap_index = 105530, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俚)*/
	{.bitmap_index = 105658, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俜)*/
	{.bitmap_index = 105786, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(保)*/
	{.bitmap_index = 105914, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俞)*/
	{.bitmap_index = 106042, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俟)*/
	{.bitmap_index = 106170, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(信)*/
	{.bitmap_index = 106298, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(俣)*/
	{.bitmap_index = 106426, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俦)*/
	{.bitmap_index = 106554, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(俨)*/
	{.bitmap_index = 106682, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俩)*/
	{.bitmap_index = 106810, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俪)*/
	{.bitmap_index = 106938, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俭)*/
	{.bitmap_index = 107066, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(修)*/
	{.bitmap_index = 107202, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俯)*/
	{.bitmap_index = 107330, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(俱)*/
	{.bitmap_index = 107458, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俳)*/
	{.bitmap_index = 107578, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(俸)*/
	{.bitmap_index = 107714, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俺)*/
	{.bitmap_index = 107842, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(俾)*/
	{.bitmap_index = 107970, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倌)*/
	{.bitmap_index = 108098, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倍)*/
	{.bitmap_index = 108226, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倏)*/
	{.bitmap_index = 108354, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倒)*/
	{.bitmap_index = 108482, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倔)*/
	{.bitmap_index = 108610, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倘)*/
	{.bitmap_index = 108730, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(候)*/
	{.bitmap_index = 108858, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倚)*/
	{.bitmap_index = 108986, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倜)*/
	{.bitmap_index = 109106, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(借)*/
	{.bitmap_index = 109234, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倡)*/
	{.bitmap_index = 109354, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倥)*/
	{.bitmap_index = 109482, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倦)*/
	{.bitmap_index = 109610, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倨)*/
	{.bitmap_index = 109738, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倩)*/
	{.bitmap_index = 109866, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(倪)*/
	{.bitmap_index = 110002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倬)*/
	{.bitmap_index = 110130, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(倭)*/
	{.bitmap_index = 110258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(倮)*/
	{.bitmap_index = 110386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(债)*/
	{.bitmap_index = 110514, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(值)*/
	{.bitmap_index = 110642, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(倾)*/
	{.bitmap_index = 110778, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(偃)*/
	{.bitmap_index = 110906, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(假)*/
	{.bitmap_index = 111034, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(偈)*/
	{.bitmap_index = 111162, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(偌)*/
	{.bitmap_index = 111282, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(偎)*/
	{.bitmap_index = 111410, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(偏)*/
	{.bitmap_index = 111538, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(偕)*/
	{.bitmap_index = 111666, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(做)*/
	{.bitmap_index = 111802, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(停)*/
	{.bitmap_index = 111930, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(健)*/
	{.bitmap_index = 112050, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(偬)*/
	{.bitmap_index = 112178, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(偶)*/
	{.bitmap_index = 112298, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(偷)*/
	{.bitmap_index = 112434, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(偻)*/
	{.bitmap_index = 112570, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(偾)*/
	{.bitmap_index = 112706, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(偿)*/
	{.bitmap_index = 112842, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(傀)*/
	{.bitmap_index = 112970, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(傅)*/
	{.bitmap_index = 113098, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(傈)*/
	{.bitmap_index = 113218, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(傍)*/
	{.bitmap_index = 113354, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(傣)*/
	{.bitmap_index = 113482, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(傥)*/
	{.bitmap_index = 113618, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(傧)*/
	{.bitmap_index = 113754, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(储)*/
	{.bitmap_index = 113882, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(傩)*/
	{.bitmap_index = 114010, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(催)*/
	{.bitmap_index = 114130, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(傲)*/
	{.bitmap_index = 114266, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(傺)*/
	{.bitmap_index = 114394, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(傻)*/
	{.bitmap_index = 114530, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(像)*/
	{.bitmap_index = 114658, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僖)*/
	{.bitmap_index = 114786, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僚)*/
	{.bitmap_index = 114914, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僦)*/
	{.bitmap_index = 115042, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僧)*/
	{.bitmap_index = 115170, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僬)*/
	{.bitmap_index = 115298, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僭)*/
	{.bitmap_index = 115418, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僮)*/
	{.bitmap_index = 115546, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僳)*/
	{.bitmap_index = 115666, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僵)*/
	{.bitmap_index = 115794, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(僻)*/
	{.bitmap_index = 115922, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(儆)*/
	{.bitmap_index = 116058, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(儇)*/
	{.bitmap_index = 116194, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(儋)*/
	{.bitmap_index = 116322, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(儒)*/
	{.bitmap_index = 116450, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(儡)*/
	{.bitmap_index = 116578, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(儿)*/
	{.bitmap_index = 116706, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兀)*/
	{.bitmap_index = 116834, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(允)*/
	{.bitmap_index = 116970, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(元)*/
	{.bitmap_index = 117098, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兄)*/
	{.bitmap_index = 117226, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(充)*/
	{.bitmap_index = 117362, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兆)*/
	{.bitmap_index = 117490, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(先)*/
	{.bitmap_index = 117626, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(光)*/
	{.bitmap_index = 117754, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(克)*/
	{.bitmap_index = 117882, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(免)*/
	{.bitmap_index = 118018, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兑)*/
	{.bitmap_index = 118154, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兔)*/
	{.bitmap_index = 118290, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兕)*/
	{.bitmap_index = 118410, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兖)*/
	{.bitmap_index = 118546, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(党)*/
	{.bitmap_index = 118682, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兜)*/
	{.bitmap_index = 118818, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兢)*/
	{.bitmap_index = 118954, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(入)*/
	{.bitmap_index = 119082, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(全)*/
	{.bitmap_index = 119210, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(八)*/
	{.bitmap_index = 119330, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(公)*/
	{.bitmap_index = 119450, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(六)*/
	{.bitmap_index = 119570, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兮)*/
	{.bitmap_index = 119698, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兰)*/
	{.bitmap_index = 119826, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(共)*/
	{.bitmap_index = 119954, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(关)*/
	{.bitmap_index = 120090, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兴)*/
	{.bitmap_index = 120210, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(兵)*/
	{.bitmap_index = 120338, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(其)*/
	{.bitmap_index = 120466, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(具)*/
	{.bitmap_index = 120594, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(典)*/
	{.bitmap_index = 120722, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兹)*/
	{.bitmap_index = 120850, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(养)*/
	{.bitmap_index = 120978, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兼)*/
	{.bitmap_index = 121106, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(兽)*/
	{.bitmap_index = 121234, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冀)*/
	{.bitmap_index = 121362, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冁)*/
	{.bitmap_index = 121498, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(冂)*/
	{.bitmap_index = 121603, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(内)*/
	{.bitmap_index = 121708, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(冈)*/
	{.bitmap_index = 121813, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冉)*/
	{.bitmap_index = 121933, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(册)*/
	{.bitmap_index = 122061, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(再)*/
	{.bitmap_index = 122181, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(冒)*/
	{.bitmap_index = 122286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冕)*/
	{.bitmap_index = 122414, .adv_w = 15, .box_h = 5, .box_w = 14, .ofs_x = 1, .ofs_y = 13},/*(冖)*/
	{.bitmap_index = 122449, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冗)*/
	{.bitmap_index = 122577, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(写)*/
	{.bitmap_index = 122682, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(军)*/
	{.bitmap_index = 122802, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(农)*/
	{.bitmap_index = 122938, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冠)*/
	{.bitmap_index = 123058, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冢)*/
	{.bitmap_index = 123178, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冤)*/
	{.bitmap_index = 123306, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冥)*/
	{.bitmap_index = 123434, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(冫)*/
	{.bitmap_index = 123479, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冬)*/
	{.bitmap_index = 123607, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冯)*/
	{.bitmap_index = 123727, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冰)*/
	{.bitmap_index = 123847, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冱)*/
	{.bitmap_index = 123967, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冲)*/
	{.bitmap_index = 124095, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(决)*/
	{.bitmap_index = 124231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(况)*/
	{.bitmap_index = 124359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冶)*/
	{.bitmap_index = 124487, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冷)*/
	{.bitmap_index = 124623, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冻)*/
	{.bitmap_index = 124751, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(冼)*/
	{.bitmap_index = 124879, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(冽)*/
	{.bitmap_index = 124999, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(净)*/
	{.bitmap_index = 125127, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凄)*/
	{.bitmap_index = 125263, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(准)*/
	{.bitmap_index = 125391, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(凇)*/
	{.bitmap_index = 125519, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(凉)*/
	{.bitmap_index = 125647, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凋)*/
	{.bitmap_index = 125775, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凌)*/
	{.bitmap_index = 125911, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(减)*/
	{.bitmap_index = 126047, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凑)*/
	{.bitmap_index = 126183, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(凛)*/
	{.bitmap_index = 126311, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凝)*/
	{.bitmap_index = 126439, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(几)*/
	{.bitmap_index = 126559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凡)*/
	{.bitmap_index = 126687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凤)*/
	{.bitmap_index = 126815, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凫)*/
	{.bitmap_index = 126951, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凭)*/
	{.bitmap_index = 127087, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(凯)*/
	{.bitmap_index = 127223, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(凰)*/
	{.bitmap_index = 127343, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(凳)*/
	{.bitmap_index = 127479, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(凵)*/
	{.bitmap_index = 127584, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(凶)*/
	{.bitmap_index = 127689, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(凸)*/
	{.bitmap_index = 127794, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(凹)*/
	{.bitmap_index = 127899, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(出)*/
	{.bitmap_index = 128011, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(击)*/
	{.bitmap_index = 128139, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(凼)*/
	{.bitmap_index = 128244, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(函)*/
	{.bitmap_index = 128349, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(凿)*/
	{.bitmap_index = 128469, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(刀)*/
	{.bitmap_index = 128597, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刁)*/
	{.bitmap_index = 128717, .adv_w = 16, .box_h = 15, .box_w = 8, .ofs_x = 8, .ofs_y = 4},/*(刂)*/
	{.bitmap_index = 128777, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(刃)*/
	{.bitmap_index = 128905, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(分)*/
	{.bitmap_index = 129041, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(切)*/
	{.bitmap_index = 129177, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刈)*/
	{.bitmap_index = 129297, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刊)*/
	{.bitmap_index = 129417, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 4},/*(刍)*/
	{.bitmap_index = 129529, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刎)*/
	{.bitmap_index = 129657, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(刑)*/
	{.bitmap_index = 129785, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(划)*/
	{.bitmap_index = 129905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(刖)*/
	{.bitmap_index = 130033, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(列)*/
	{.bitmap_index = 130161, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刘)*/
	{.bitmap_index = 130281, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(则)*/
	{.bitmap_index = 130401, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(刚)*/
	{.bitmap_index = 130506, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(创)*/
	{.bitmap_index = 130634, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(初)*/
	{.bitmap_index = 130770, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(删)*/
	{.bitmap_index = 130890, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(判)*/
	{.bitmap_index = 131018, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刨)*/
	{.bitmap_index = 131146, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(利)*/
	{.bitmap_index = 131266, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(别)*/
	{.bitmap_index = 131386, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刭)*/
	{.bitmap_index = 131506, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刮)*/
	{.bitmap_index = 131626, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(到)*/
	{.bitmap_index = 131746, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刳)*/
	{.bitmap_index = 131874, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(制)*/
	{.bitmap_index = 132002, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刷)*/
	{.bitmap_index = 132122, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(券)*/
	{.bitmap_index = 132258, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刹)*/
	{.bitmap_index = 132378, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刺)*/
	{.bitmap_index = 132498, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(刻)*/
	{.bitmap_index = 132626, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(刽)*/
	{.bitmap_index = 132754, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(刿)*/
	{.bitmap_index = 132890, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(剀)*/
	{.bitmap_index = 133002, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剁)*/
	{.bitmap_index = 133122, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(剂)*/
	{.bitmap_index = 133258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剃)*/
	{.bitmap_index = 133386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(削)*/
	{.bitmap_index = 133514, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剌)*/
	{.bitmap_index = 133634, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(前)*/
	{.bitmap_index = 133762, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(剐)*/
	{.bitmap_index = 133867, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剑)*/
	{.bitmap_index = 133995, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(剔)*/
	{.bitmap_index = 134123, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剖)*/
	{.bitmap_index = 134251, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剜)*/
	{.bitmap_index = 134379, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剞)*/
	{.bitmap_index = 134499, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(剡)*/
	{.bitmap_index = 134627, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剥)*/
	{.bitmap_index = 134747, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剧)*/
	{.bitmap_index = 134867, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剩)*/
	{.bitmap_index = 134987, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(剪)*/
	{.bitmap_index = 135123, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(副)*/
	{.bitmap_index = 135228, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(割)*/
	{.bitmap_index = 135348, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剽)*/
	{.bitmap_index = 135468, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(剿)*/
	{.bitmap_index = 135596, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(劁)*/
	{.bitmap_index = 135716, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(劂)*/
	{.bitmap_index = 135836, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劈)*/
	{.bitmap_index = 135972, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劐)*/
	{.bitmap_index = 136100, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劓)*/
	{.bitmap_index = 136236, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(力)*/
	{.bitmap_index = 136372, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劝)*/
	{.bitmap_index = 136500, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(办)*/
	{.bitmap_index = 136636, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(功)*/
	{.bitmap_index = 136772, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(加)*/
	{.bitmap_index = 136900, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(务)*/
	{.bitmap_index = 137036, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(劢)*/
	{.bitmap_index = 137164, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劣)*/
	{.bitmap_index = 137300, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(动)*/
	{.bitmap_index = 137436, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(助)*/
	{.bitmap_index = 137564, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(努)*/
	{.bitmap_index = 137700, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劫)*/
	{.bitmap_index = 137836, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(劬)*/
	{.bitmap_index = 137964, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劭)*/
	{.bitmap_index = 138092, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(励)*/
	{.bitmap_index = 138220, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劲)*/
	{.bitmap_index = 138356, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劳)*/
	{.bitmap_index = 138484, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(劾)*/
	{.bitmap_index = 138620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(势)*/
	{.bitmap_index = 138748, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(勃)*/
	{.bitmap_index = 138876, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(勇)*/
	{.bitmap_index = 138988, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(勉)*/
	{.bitmap_index = 139116, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(勋)*/
	{.bitmap_index = 139244, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(勐)*/
	{.bitmap_index = 139372, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(勒)*/
	{.bitmap_index = 139500, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(勖)*/
	{.bitmap_index = 139605, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(勘)*/
	{.bitmap_index = 139733, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(募)*/
	{.bitmap_index = 139869, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(勤)*/
	{.bitmap_index = 139997, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(勰)*/
	{.bitmap_index = 140117, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(勹)*/
	{.bitmap_index = 140245, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(勺)*/
	{.bitmap_index = 140373, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(勾)*/
	{.bitmap_index = 140501, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(勿)*/
	{.bitmap_index = 140637, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(匀)*/
	{.bitmap_index = 140765, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(包)*/
	{.bitmap_index = 140893, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(匆)*/
	{.bitmap_index = 141021, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(匈)*/
	{.bitmap_index = 141149, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(匍)*/
	{.bitmap_index = 141277, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(匏)*/
	{.bitmap_index = 141405, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(匐)*/
	{.bitmap_index = 141541, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(匕)*/
	{.bitmap_index = 141646, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(化)*/
	{.bitmap_index = 141774, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(北)*/
	{.bitmap_index = 141894, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(匙)*/
	{.bitmap_index = 142014, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(匚)*/
	{.bitmap_index = 142119, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(匝)*/
	{.bitmap_index = 142224, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匠)*/
	{.bitmap_index = 142344, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(匡)*/
	{.bitmap_index = 142449, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匣)*/
	{.bitmap_index = 142569, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匦)*/
	{.bitmap_index = 142689, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匪)*/
	{.bitmap_index = 142809, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(匮)*/
	{.bitmap_index = 142914, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匹)*/
	{.bitmap_index = 143034, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(区)*/
	{.bitmap_index = 143154, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(医)*/
	{.bitmap_index = 143274, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匾)*/
	{.bitmap_index = 143394, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(匿)*/
	{.bitmap_index = 143514, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(十)*/
	{.bitmap_index = 143634, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(千)*/
	{.bitmap_index = 143754, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卅)*/
	{.bitmap_index = 143874, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(升)*/
	{.bitmap_index = 144002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(午)*/
	{.bitmap_index = 144130, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(卉)*/
	{.bitmap_index = 144266, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(半)*/
	{.bitmap_index = 144386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(华)*/
	{.bitmap_index = 144514, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(协)*/
	{.bitmap_index = 144650, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卑)*/
	{.bitmap_index = 144778, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卒)*/
	{.bitmap_index = 144906, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卓)*/
	{.bitmap_index = 145034, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(单)*/
	{.bitmap_index = 145162, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(卖)*/
	{.bitmap_index = 145298, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(南)*/
	{.bitmap_index = 145426, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(博)*/
	{.bitmap_index = 145554, .adv_w = 15, .box_h = 15, .box_w = 10, .ofs_x = 5, .ofs_y = 4},/*(卜)*/
	{.bitmap_index = 145629, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卞)*/
	{.bitmap_index = 145757, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(卟)*/
	{.bitmap_index = 145877, .adv_w = 16, .box_h = 16, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(占)*/
	{.bitmap_index = 145989, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卡)*/
	{.bitmap_index = 146109, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(卢)*/
	{.bitmap_index = 146245, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(卣)*/
	{.bitmap_index = 146365, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(卤)*/
	{.bitmap_index = 146477, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卦)*/
	{.bitmap_index = 146605, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(卧)*/
	{.bitmap_index = 146725, .adv_w = 14, .box_h = 15, .box_w = 10, .ofs_x = 4, .ofs_y = 4},/*(卩)*/
	{.bitmap_index = 146800, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卫)*/
	{.bitmap_index = 146920, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卮)*/
	{.bitmap_index = 147040, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(卯)*/
	{.bitmap_index = 147159, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(印)*/
	{.bitmap_index = 147271, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(危)*/
	{.bitmap_index = 147407, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(即)*/
	{.bitmap_index = 147512, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(却)*/
	{.bitmap_index = 147640, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(卵)*/
	{.bitmap_index = 147759, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卷)*/
	{.bitmap_index = 147879, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卸)*/
	{.bitmap_index = 148007, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卺)*/
	{.bitmap_index = 148127, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(卿)*/
	{.bitmap_index = 148255, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厂)*/
	{.bitmap_index = 148383, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厄)*/
	{.bitmap_index = 148511, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厅)*/
	{.bitmap_index = 148639, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(历)*/
	{.bitmap_index = 148767, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厉)*/
	{.bitmap_index = 148895, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(压)*/
	{.bitmap_index = 149023, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厌)*/
	{.bitmap_index = 149151, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厍)*/
	{.bitmap_index = 149279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厕)*/
	{.bitmap_index = 149407, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(厘)*/
	{.bitmap_index = 149527, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(厚)*/
	{.bitmap_index = 149647, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(厝)*/
	{.bitmap_index = 149767, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(原)*/
	{.bitmap_index = 149895, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厢)*/
	{.bitmap_index = 150023, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(厣)*/
	{.bitmap_index = 150143, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厥)*/
	{.bitmap_index = 150271, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厦)*/
	{.bitmap_index = 150399, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(厨)*/
	{.bitmap_index = 150527, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(厩)*/
	{.bitmap_index = 150647, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(厮)*/
	{.bitmap_index = 150767, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(厶)*/
	{.bitmap_index = 150872, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(去)*/
	{.bitmap_index = 151000, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(县)*/
	{.bitmap_index = 151128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(叁)*/
	{.bitmap_index = 151256, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(参)*/
	{.bitmap_index = 151392, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(又)*/
	{.bitmap_index = 151520, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(叉)*/
	{.bitmap_index = 151648, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(及)*/
	{.bitmap_index = 151776, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(友)*/
	{.bitmap_index = 151912, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(双)*/
	{.bitmap_index = 152040, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(反)*/
	{.bitmap_index = 152168, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(发)*/
	{.bitmap_index = 152304, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(叔)*/
	{.bitmap_index = 152424, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(取)*/
	{.bitmap_index = 152544, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(受)*/
	{.bitmap_index = 152672, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(变)*/
	{.bitmap_index = 152808, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(叙)*/
	{.bitmap_index = 152944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(叛)*/
	{.bitmap_index = 153072, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(叟)*/
	{.bitmap_index = 153200, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(叠)*/
	{.bitmap_index = 153320, .adv_w = 14, .box_h = 13, .box_w = 12, .ofs_x = 2, .ofs_y = 5},/*(口)*/
	{.bitmap_index = 153398, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(古)*/
	{.bitmap_index = 153518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(句)*/
	{.bitmap_index = 153646, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(另)*/
	{.bitmap_index = 153774, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(叨)*/
	{.bitmap_index = 153886, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(叩)*/
	{.bitmap_index = 153991, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(只)*/
	{.bitmap_index = 154119, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(叫)*/
	{.bitmap_index = 154224, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(召)*/
	{.bitmap_index = 154344, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(叭)*/
	{.bitmap_index = 154464, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(叮)*/
	{.bitmap_index = 154584, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(可)*/
	{.bitmap_index = 154704, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(台)*/
	{.bitmap_index = 154816, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(叱)*/
	{.bitmap_index = 154936, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(史)*/
	{.bitmap_index = 155064, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(右)*/
	{.bitmap_index = 155192, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(叵)*/
	{.bitmap_index = 155312, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(叶)*/
	{.bitmap_index = 155432, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(号)*/
	{.bitmap_index = 155552, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(司)*/
	{.bitmap_index = 155657, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(叹)*/
	{.bitmap_index = 155785, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(叻)*/
	{.bitmap_index = 155897, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(叼)*/
	{.bitmap_index = 156002, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(叽)*/
	{.bitmap_index = 156130, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吁)*/
	{.bitmap_index = 156250, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吃)*/
	{.bitmap_index = 156378, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(各)*/
	{.bitmap_index = 156506, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吆)*/
	{.bitmap_index = 156634, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(合)*/
	{.bitmap_index = 156762, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(吉)*/
	{.bitmap_index = 156867, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(吊)*/
	{.bitmap_index = 156972, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(同)*/
	{.bitmap_index = 157077, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(名)*/
	{.bitmap_index = 157205, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(后)*/
	{.bitmap_index = 157325, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(吏)*/
	{.bitmap_index = 157453, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吐)*/
	{.bitmap_index = 157581, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(向)*/
	{.bitmap_index = 157693, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吒)*/
	{.bitmap_index = 157813, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吓)*/
	{.bitmap_index = 157933, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(吕)*/
	{.bitmap_index = 158038, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吖)*/
	{.bitmap_index = 158166, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(吗)*/
	{.bitmap_index = 158271, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(君)*/
	{.bitmap_index = 158391, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(吝)*/
	{.bitmap_index = 158519, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(吞)*/
	{.bitmap_index = 158639, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吟)*/
	{.bitmap_index = 158775, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吠)*/
	{.bitmap_index = 158903, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吡)*/
	{.bitmap_index = 159023, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吣)*/
	{.bitmap_index = 159143, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(否)*/
	{.bitmap_index = 159263, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吧)*/
	{.bitmap_index = 159383, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吨)*/
	{.bitmap_index = 159511, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吩)*/
	{.bitmap_index = 159647, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(含)*/
	{.bitmap_index = 159775, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(听)*/
	{.bitmap_index = 159903, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吭)*/
	{.bitmap_index = 160031, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吮)*/
	{.bitmap_index = 160167, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(启)*/
	{.bitmap_index = 160295, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吱)*/
	{.bitmap_index = 160431, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(吲)*/
	{.bitmap_index = 160536, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(吴)*/
	{.bitmap_index = 160664, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吵)*/
	{.bitmap_index = 160800, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吸)*/
	{.bitmap_index = 160928, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(吹)*/
	{.bitmap_index = 161064, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(吻)*/
	{.bitmap_index = 161176, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(吼)*/
	{.bitmap_index = 161296, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(吾)*/
	{.bitmap_index = 161416, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呀)*/
	{.bitmap_index = 161536, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呃)*/
	{.bitmap_index = 161664, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(呆)*/
	{.bitmap_index = 161784, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(呈)*/
	{.bitmap_index = 161889, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(告)*/
	{.bitmap_index = 162009, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呋)*/
	{.bitmap_index = 162145, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(呐)*/
	{.bitmap_index = 162250, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呒)*/
	{.bitmap_index = 162378, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呓)*/
	{.bitmap_index = 162498, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呔)*/
	{.bitmap_index = 162626, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呕)*/
	{.bitmap_index = 162746, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呖)*/
	{.bitmap_index = 162874, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呗)*/
	{.bitmap_index = 163002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(员)*/
	{.bitmap_index = 163130, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(呙)*/
	{.bitmap_index = 163235, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呛)*/
	{.bitmap_index = 163363, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(呜)*/
	{.bitmap_index = 163475, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呢)*/
	{.bitmap_index = 163603, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呤)*/
	{.bitmap_index = 163739, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(呦)*/
	{.bitmap_index = 163851, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(周)*/
	{.bitmap_index = 163979, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呱)*/
	{.bitmap_index = 164099, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呲)*/
	{.bitmap_index = 164219, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(味)*/
	{.bitmap_index = 164339, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呵)*/
	{.bitmap_index = 164459, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(呶)*/
	{.bitmap_index = 164595, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(呷)*/
	{.bitmap_index = 164700, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呸)*/
	{.bitmap_index = 164820, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(呻)*/
	{.bitmap_index = 164932, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(呼)*/
	{.bitmap_index = 165052, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(命)*/
	{.bitmap_index = 165180, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咀)*/
	{.bitmap_index = 165300, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咂)*/
	{.bitmap_index = 165420, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(咄)*/
	{.bitmap_index = 165532, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咆)*/
	{.bitmap_index = 165660, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咋)*/
	{.bitmap_index = 165788, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(和)*/
	{.bitmap_index = 165908, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(咎)*/
	{.bitmap_index = 166036, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咏)*/
	{.bitmap_index = 166164, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咐)*/
	{.bitmap_index = 166292, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(咒)*/
	{.bitmap_index = 166420, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咔)*/
	{.bitmap_index = 166540, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咕)*/
	{.bitmap_index = 166660, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(咖)*/
	{.bitmap_index = 166765, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咙)*/
	{.bitmap_index = 166893, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咚)*/
	{.bitmap_index = 167021, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咛)*/
	{.bitmap_index = 167141, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咝)*/
	{.bitmap_index = 167261, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咣)*/
	{.bitmap_index = 167389, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(咤)*/
	{.bitmap_index = 167501, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咦)*/
	{.bitmap_index = 167637, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(咧)*/
	{.bitmap_index = 167742, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(咨)*/
	{.bitmap_index = 167870, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咩)*/
	{.bitmap_index = 167998, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咪)*/
	{.bitmap_index = 168118, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(咫)*/
	{.bitmap_index = 168238, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咬)*/
	{.bitmap_index = 168366, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咭)*/
	{.bitmap_index = 168486, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咯)*/
	{.bitmap_index = 168614, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(咱)*/
	{.bitmap_index = 168726, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咳)*/
	{.bitmap_index = 168854, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咴)*/
	{.bitmap_index = 168982, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(咸)*/
	{.bitmap_index = 169110, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(咻)*/
	{.bitmap_index = 169238, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(咽)*/
	{.bitmap_index = 169343, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(咿)*/
	{.bitmap_index = 169479, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(哀)*/
	{.bitmap_index = 169615, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(品)*/
	{.bitmap_index = 169720, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哂)*/
	{.bitmap_index = 169840, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哄)*/
	{.bitmap_index = 169960, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哆)*/
	{.bitmap_index = 170096, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哇)*/
	{.bitmap_index = 170216, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哈)*/
	{.bitmap_index = 170344, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(哉)*/
	{.bitmap_index = 170480, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哌)*/
	{.bitmap_index = 170608, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(响)*/
	{.bitmap_index = 170720, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哎)*/
	{.bitmap_index = 170848, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哏)*/
	{.bitmap_index = 170976, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哐)*/
	{.bitmap_index = 171096, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哑)*/
	{.bitmap_index = 171216, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哒)*/
	{.bitmap_index = 171344, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哓)*/
	{.bitmap_index = 171480, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哔)*/
	{.bitmap_index = 171600, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(哕)*/
	{.bitmap_index = 171719, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哗)*/
	{.bitmap_index = 171847, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哙)*/
	{.bitmap_index = 171967, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哚)*/
	{.bitmap_index = 172087, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哜)*/
	{.bitmap_index = 172223, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哝)*/
	{.bitmap_index = 172351, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哞)*/
	{.bitmap_index = 172479, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(哟)*/
	{.bitmap_index = 172591, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(哥)*/
	{.bitmap_index = 172711, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哦)*/
	{.bitmap_index = 172847, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哧)*/
	{.bitmap_index = 172975, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哨)*/
	{.bitmap_index = 173103, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哩)*/
	{.bitmap_index = 173223, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哪)*/
	{.bitmap_index = 173343, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(哭)*/
	{.bitmap_index = 173471, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哮)*/
	{.bitmap_index = 173607, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(哲)*/
	{.bitmap_index = 173727, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哳)*/
	{.bitmap_index = 173855, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哺)*/
	{.bitmap_index = 173983, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(哼)*/
	{.bitmap_index = 174103, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(哽)*/
	{.bitmap_index = 174231, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(哿)*/
	{.bitmap_index = 174351, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唁)*/
	{.bitmap_index = 174471, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唆)*/
	{.bitmap_index = 174607, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(唇)*/
	{.bitmap_index = 174735, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唉)*/
	{.bitmap_index = 174871, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唏)*/
	{.bitmap_index = 174999, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(唐)*/
	{.bitmap_index = 175135, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唑)*/
	{.bitmap_index = 175255, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唔)*/
	{.bitmap_index = 175375, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唛)*/
	{.bitmap_index = 175503, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唠)*/
	{.bitmap_index = 175631, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唢)*/
	{.bitmap_index = 175767, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唣)*/
	{.bitmap_index = 175895, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唤)*/
	{.bitmap_index = 176031, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(唧)*/
	{.bitmap_index = 176136, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唪)*/
	{.bitmap_index = 176264, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唬)*/
	{.bitmap_index = 176400, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(售)*/
	{.bitmap_index = 176528, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唯)*/
	{.bitmap_index = 176656, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(唰)*/
	{.bitmap_index = 176761, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(唱)*/
	{.bitmap_index = 176866, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唳)*/
	{.bitmap_index = 177002, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唷)*/
	{.bitmap_index = 177130, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(唼)*/
	{.bitmap_index = 177266, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唾)*/
	{.bitmap_index = 177386, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(唿)*/
	{.bitmap_index = 177514, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(啁)*/
	{.bitmap_index = 177619, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啃)*/
	{.bitmap_index = 177739, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啄)*/
	{.bitmap_index = 177859, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(商)*/
	{.bitmap_index = 177987, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啉)*/
	{.bitmap_index = 178107, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啊)*/
	{.bitmap_index = 178227, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啐)*/
	{.bitmap_index = 178355, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(啕)*/
	{.bitmap_index = 178467, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(啖)*/
	{.bitmap_index = 178603, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啜)*/
	{.bitmap_index = 178723, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啡)*/
	{.bitmap_index = 178843, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啤)*/
	{.bitmap_index = 178971, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啥)*/
	{.bitmap_index = 179099, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啦)*/
	{.bitmap_index = 179219, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(啧)*/
	{.bitmap_index = 179347, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(啪)*/
	{.bitmap_index = 179459, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(啬)*/
	{.bitmap_index = 179587, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啭)*/
	{.bitmap_index = 179715, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啮)*/
	{.bitmap_index = 179835, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啵)*/
	{.bitmap_index = 179963, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(啶)*/
	{.bitmap_index = 180099, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啷)*/
	{.bitmap_index = 180227, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(啸)*/
	{.bitmap_index = 180355, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(啻)*/
	{.bitmap_index = 180467, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(啼)*/
	{.bitmap_index = 180579, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(啾)*/
	{.bitmap_index = 180699, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喀)*/
	{.bitmap_index = 180827, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(喁)*/
	{.bitmap_index = 180932, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(喂)*/
	{.bitmap_index = 181060, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(喃)*/
	{.bitmap_index = 181172, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(善)*/
	{.bitmap_index = 181300, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(喇)*/
	{.bitmap_index = 181412, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喈)*/
	{.bitmap_index = 181532, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喉)*/
	{.bitmap_index = 181660, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(喊)*/
	{.bitmap_index = 181796, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喋)*/
	{.bitmap_index = 181916, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喏)*/
	{.bitmap_index = 182036, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喑)*/
	{.bitmap_index = 182164, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(喔)*/
	{.bitmap_index = 182292, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喘)*/
	{.bitmap_index = 182420, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喙)*/
	{.bitmap_index = 182548, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(喜)*/
	{.bitmap_index = 182668, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(喝)*/
	{.bitmap_index = 182773, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(喟)*/
	{.bitmap_index = 182878, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喧)*/
	{.bitmap_index = 182998, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(喱)*/
	{.bitmap_index = 183126, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喳)*/
	{.bitmap_index = 183254, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喵)*/
	{.bitmap_index = 183374, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(喷)*/
	{.bitmap_index = 183510, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喹)*/
	{.bitmap_index = 183638, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(喻)*/
	{.bitmap_index = 183766, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(喽)*/
	{.bitmap_index = 183902, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(喾)*/
	{.bitmap_index = 184030, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗄)*/
	{.bitmap_index = 184158, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗅)*/
	{.bitmap_index = 184294, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗉)*/
	{.bitmap_index = 184422, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗌)*/
	{.bitmap_index = 184550, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(嗍)*/
	{.bitmap_index = 184662, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗑)*/
	{.bitmap_index = 184782, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗒)*/
	{.bitmap_index = 184910, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗓)*/
	{.bitmap_index = 185030, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗔)*/
	{.bitmap_index = 185158, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗖)*/
	{.bitmap_index = 185286, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗜)*/
	{.bitmap_index = 185406, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嗝)*/
	{.bitmap_index = 185511, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嗟)*/
	{.bitmap_index = 185623, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗡)*/
	{.bitmap_index = 185751, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嗣)*/
	{.bitmap_index = 185856, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗤)*/
	{.bitmap_index = 185992, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗥)*/
	{.bitmap_index = 186120, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗦)*/
	{.bitmap_index = 186248, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗨)*/
	{.bitmap_index = 186376, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗪)*/
	{.bitmap_index = 186496, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗫)*/
	{.bitmap_index = 186624, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗬)*/
	{.bitmap_index = 186744, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗯)*/
	{.bitmap_index = 186864, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗲)*/
	{.bitmap_index = 187000, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗳)*/
	{.bitmap_index = 187128, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗵)*/
	{.bitmap_index = 187248, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗷)*/
	{.bitmap_index = 187376, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嗽)*/
	{.bitmap_index = 187512, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嗾)*/
	{.bitmap_index = 187640, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘀)*/
	{.bitmap_index = 187768, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嘁)*/
	{.bitmap_index = 187904, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘈)*/
	{.bitmap_index = 188024, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嘉)*/
	{.bitmap_index = 188160, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘌)*/
	{.bitmap_index = 188280, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘎)*/
	{.bitmap_index = 188400, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嘏)*/
	{.bitmap_index = 188528, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘘)*/
	{.bitmap_index = 188656, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘛)*/
	{.bitmap_index = 188784, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嘞)*/
	{.bitmap_index = 188889, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘟)*/
	{.bitmap_index = 189009, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(嘣)*/
	{.bitmap_index = 189128, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嘤)*/
	{.bitmap_index = 189256, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘧)*/
	{.bitmap_index = 189384, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘬)*/
	{.bitmap_index = 189504, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嘭)*/
	{.bitmap_index = 189632, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嘱)*/
	{.bitmap_index = 189737, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嘲)*/
	{.bitmap_index = 189842, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嘴)*/
	{.bitmap_index = 189978, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嘶)*/
	{.bitmap_index = 190106, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘹)*/
	{.bitmap_index = 190226, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嘻)*/
	{.bitmap_index = 190346, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嘿)*/
	{.bitmap_index = 190474, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(噌)*/
	{.bitmap_index = 190586, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噍)*/
	{.bitmap_index = 190714, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噎)*/
	{.bitmap_index = 190842, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噔)*/
	{.bitmap_index = 190962, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(噗)*/
	{.bitmap_index = 191098, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(噘)*/
	{.bitmap_index = 191226, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噙)*/
	{.bitmap_index = 191354, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噜)*/
	{.bitmap_index = 191482, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(噢)*/
	{.bitmap_index = 191618, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噤)*/
	{.bitmap_index = 191738, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(器)*/
	{.bitmap_index = 191858, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(噩)*/
	{.bitmap_index = 191978, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噪)*/
	{.bitmap_index = 192098, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噫)*/
	{.bitmap_index = 192226, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噬)*/
	{.bitmap_index = 192354, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(噱)*/
	{.bitmap_index = 192490, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噶)*/
	{.bitmap_index = 192618, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噻)*/
	{.bitmap_index = 192746, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(噼)*/
	{.bitmap_index = 192874, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嚅)*/
	{.bitmap_index = 192979, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嚆)*/
	{.bitmap_index = 193107, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嚎)*/
	{.bitmap_index = 193235, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嚏)*/
	{.bitmap_index = 193371, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嚓)*/
	{.bitmap_index = 193499, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嚣)*/
	{.bitmap_index = 193619, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嚯)*/
	{.bitmap_index = 193739, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嚷)*/
	{.bitmap_index = 193875, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嚼)*/
	{.bitmap_index = 193995, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(囊)*/
	{.bitmap_index = 194131, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(囔)*/
	{.bitmap_index = 194267, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囗)*/
	{.bitmap_index = 194372, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囚)*/
	{.bitmap_index = 194477, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(四)*/
	{.bitmap_index = 194575, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囝)*/
	{.bitmap_index = 194680, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(回)*/
	{.bitmap_index = 194785, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囟)*/
	{.bitmap_index = 194897, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(因)*/
	{.bitmap_index = 195002, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囡)*/
	{.bitmap_index = 195107, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(团)*/
	{.bitmap_index = 195212, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囤)*/
	{.bitmap_index = 195317, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囫)*/
	{.bitmap_index = 195422, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(园)*/
	{.bitmap_index = 195527, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(困)*/
	{.bitmap_index = 195632, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囱)*/
	{.bitmap_index = 195744, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(围)*/
	{.bitmap_index = 195849, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囵)*/
	{.bitmap_index = 195954, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囹)*/
	{.bitmap_index = 196059, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(固)*/
	{.bitmap_index = 196164, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(国)*/
	{.bitmap_index = 196269, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(图)*/
	{.bitmap_index = 196374, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(囿)*/
	{.bitmap_index = 196479, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圃)*/
	{.bitmap_index = 196584, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圄)*/
	{.bitmap_index = 196689, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圆)*/
	{.bitmap_index = 196794, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圈)*/
	{.bitmap_index = 196899, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圉)*/
	{.bitmap_index = 197004, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圊)*/
	{.bitmap_index = 197109, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(圜)*/
	{.bitmap_index = 197214, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(土)*/
	{.bitmap_index = 197334, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圣)*/
	{.bitmap_index = 197454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(在)*/
	{.bitmap_index = 197582, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圩)*/
	{.bitmap_index = 197702, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圪)*/
	{.bitmap_index = 197830, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圬)*/
	{.bitmap_index = 197950, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圭)*/
	{.bitmap_index = 198070, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圮)*/
	{.bitmap_index = 198190, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(圯)*/
	{.bitmap_index = 198310, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(地)*/
	{.bitmap_index = 198430, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(圳)*/
	{.bitmap_index = 198558, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(圹)*/
	{.bitmap_index = 198694, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(场)*/
	{.bitmap_index = 198830, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(圻)*/
	{.bitmap_index = 198958, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(圾)*/
	{.bitmap_index = 199086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(址)*/
	{.bitmap_index = 199214, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坂)*/
	{.bitmap_index = 199334, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(均)*/
	{.bitmap_index = 199462, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坊)*/
	{.bitmap_index = 199590, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坌)*/
	{.bitmap_index = 199718, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坍)*/
	{.bitmap_index = 199846, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坎)*/
	{.bitmap_index = 199982, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坏)*/
	{.bitmap_index = 200102, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坐)*/
	{.bitmap_index = 200222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坑)*/
	{.bitmap_index = 200350, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(块)*/
	{.bitmap_index = 200478, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坚)*/
	{.bitmap_index = 200598, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坛)*/
	{.bitmap_index = 200718, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坜)*/
	{.bitmap_index = 200854, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坝)*/
	{.bitmap_index = 200982, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坞)*/
	{.bitmap_index = 201110, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坟)*/
	{.bitmap_index = 201238, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坠)*/
	{.bitmap_index = 201358, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坡)*/
	{.bitmap_index = 201494, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坤)*/
	{.bitmap_index = 201622, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坦)*/
	{.bitmap_index = 201742, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坨)*/
	{.bitmap_index = 201870, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坩)*/
	{.bitmap_index = 201990, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坪)*/
	{.bitmap_index = 202110, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坫)*/
	{.bitmap_index = 202230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坭)*/
	{.bitmap_index = 202358, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坯)*/
	{.bitmap_index = 202478, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坳)*/
	{.bitmap_index = 202606, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坶)*/
	{.bitmap_index = 202726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(坷)*/
	{.bitmap_index = 202846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坻)*/
	{.bitmap_index = 202974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(坼)*/
	{.bitmap_index = 203102, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垂)*/
	{.bitmap_index = 203222, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垃)*/
	{.bitmap_index = 203342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垄)*/
	{.bitmap_index = 203470, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(垅)*/
	{.bitmap_index = 203598, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(垆)*/
	{.bitmap_index = 203726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(型)*/
	{.bitmap_index = 203846, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垌)*/
	{.bitmap_index = 203966, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垒)*/
	{.bitmap_index = 204094, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(垓)*/
	{.bitmap_index = 204222, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垛)*/
	{.bitmap_index = 204342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(垠)*/
	{.bitmap_index = 204470, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垡)*/
	{.bitmap_index = 204598, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垢)*/
	{.bitmap_index = 204726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垣)*/
	{.bitmap_index = 204846, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垤)*/
	{.bitmap_index = 204966, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垦)*/
	{.bitmap_index = 205086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垧)*/
	{.bitmap_index = 205214, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垩)*/
	{.bitmap_index = 205334, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垫)*/
	{.bitmap_index = 205454, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垭)*/
	{.bitmap_index = 205574, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垮)*/
	{.bitmap_index = 205702, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垲)*/
	{.bitmap_index = 205822, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(垴)*/
	{.bitmap_index = 205950, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(垸)*/
	{.bitmap_index = 206086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(埂)*/
	{.bitmap_index = 206214, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(埃)*/
	{.bitmap_index = 206350, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埋)*/
	{.bitmap_index = 206470, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(城)*/
	{.bitmap_index = 206606, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埏)*/
	{.bitmap_index = 206726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埒)*/
	{.bitmap_index = 206846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埔)*/
	{.bitmap_index = 206974, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埕)*/
	{.bitmap_index = 207094, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埘)*/
	{.bitmap_index = 207214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(埙)*/
	{.bitmap_index = 207342, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埚)*/
	{.bitmap_index = 207462, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埝)*/
	{.bitmap_index = 207590, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(域)*/
	{.bitmap_index = 207718, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埠)*/
	{.bitmap_index = 207846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埤)*/
	{.bitmap_index = 207974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埭)*/
	{.bitmap_index = 208102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埯)*/
	{.bitmap_index = 208230, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埴)*/
	{.bitmap_index = 208350, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(埸)*/
	{.bitmap_index = 208478, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(培)*/
	{.bitmap_index = 208606, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(基)*/
	{.bitmap_index = 208726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(埽)*/
	{.bitmap_index = 208846, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堀)*/
	{.bitmap_index = 208966, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(堂)*/
	{.bitmap_index = 209078, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堆)*/
	{.bitmap_index = 209206, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堇)*/
	{.bitmap_index = 209326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(堋)*/
	{.bitmap_index = 209454, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(堍)*/
	{.bitmap_index = 209590, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堑)*/
	{.bitmap_index = 209718, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(堕)*/
	{.bitmap_index = 209846, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堙)*/
	{.bitmap_index = 209966, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堞)*/
	{.bitmap_index = 210086, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(堠)*/
	{.bitmap_index = 210222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堡)*/
	{.bitmap_index = 210350, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(堤)*/
	{.bitmap_index = 210478, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堪)*/
	{.bitmap_index = 210598, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堰)*/
	{.bitmap_index = 210718, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(堵)*/
	{.bitmap_index = 210838, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(塄)*/
	{.bitmap_index = 210966, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塌)*/
	{.bitmap_index = 211086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塍)*/
	{.bitmap_index = 211214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塑)*/
	{.bitmap_index = 211342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塔)*/
	{.bitmap_index = 211470, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(塘)*/
	{.bitmap_index = 211606, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塞)*/
	{.bitmap_index = 211734, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塥)*/
	{.bitmap_index = 211862, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(填)*/
	{.bitmap_index = 211990, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塬)*/
	{.bitmap_index = 212110, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(塾)*/
	{.bitmap_index = 212238, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墀)*/
	{.bitmap_index = 212358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(墁)*/
	{.bitmap_index = 212486, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(境)*/
	{.bitmap_index = 212622, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(墅)*/
	{.bitmap_index = 212742, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墉)*/
	{.bitmap_index = 212870, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墒)*/
	{.bitmap_index = 212990, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墓)*/
	{.bitmap_index = 213118, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墙)*/
	{.bitmap_index = 213238, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墚)*/
	{.bitmap_index = 213366, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(增)*/
	{.bitmap_index = 213494, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墟)*/
	{.bitmap_index = 213622, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墨)*/
	{.bitmap_index = 213742, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(墩)*/
	{.bitmap_index = 213878, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(墼)*/
	{.bitmap_index = 213998, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(壁)*/
	{.bitmap_index = 214126, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(壅)*/
	{.bitmap_index = 214254, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(壑)*/
	{.bitmap_index = 214382, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(壕)*/
	{.bitmap_index = 214510, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(壤)*/
	{.bitmap_index = 214646, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(士)*/
	{.bitmap_index = 214766, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(壬)*/
	{.bitmap_index = 214886, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(壮)*/
	{.bitmap_index = 215006, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(声)*/
	{.bitmap_index = 215142, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(壳)*/
	{.bitmap_index = 215278, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(壶)*/
	{.bitmap_index = 215390, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(壹)*/
	{.bitmap_index = 215502, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(夂)*/
	{.bitmap_index = 215630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(处)*/
	{.bitmap_index = 215758, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(备)*/
	{.bitmap_index = 215886, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(复)*/
	{.bitmap_index = 216022, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夏)*/
	{.bitmap_index = 216150, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夔)*/
	{.bitmap_index = 216286, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夕)*/
	{.bitmap_index = 216422, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(外)*/
	{.bitmap_index = 216550, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夙)*/
	{.bitmap_index = 216678, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(多)*/
	{.bitmap_index = 216797, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(夜)*/
	{.bitmap_index = 216925, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(够)*/
	{.bitmap_index = 217061, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(夤)*/
	{.bitmap_index = 217180, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夥)*/
	{.bitmap_index = 217316, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(大)*/
	{.bitmap_index = 217444, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(天)*/
	{.bitmap_index = 217572, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(太)*/
	{.bitmap_index = 217700, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夫)*/
	{.bitmap_index = 217828, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夭)*/
	{.bitmap_index = 217956, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(央)*/
	{.bitmap_index = 218084, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夯)*/
	{.bitmap_index = 218220, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(失)*/
	{.bitmap_index = 218348, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(头)*/
	{.bitmap_index = 218476, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(夷)*/
	{.bitmap_index = 218596, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(夸)*/
	{.bitmap_index = 218724, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夹)*/
	{.bitmap_index = 218860, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(夺)*/
	{.bitmap_index = 218988, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(夼)*/
	{.bitmap_index = 219124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奁)*/
	{.bitmap_index = 219252, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奂)*/
	{.bitmap_index = 219388, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奄)*/
	{.bitmap_index = 219516, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奇)*/
	{.bitmap_index = 219636, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奈)*/
	{.bitmap_index = 219756, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奉)*/
	{.bitmap_index = 219884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奋)*/
	{.bitmap_index = 220012, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奎)*/
	{.bitmap_index = 220140, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奏)*/
	{.bitmap_index = 220276, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(契)*/
	{.bitmap_index = 220412, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奔)*/
	{.bitmap_index = 220548, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奕)*/
	{.bitmap_index = 220684, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奖)*/
	{.bitmap_index = 220820, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(套)*/
	{.bitmap_index = 220956, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奘)*/
	{.bitmap_index = 221084, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奚)*/
	{.bitmap_index = 221212, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奠)*/
	{.bitmap_index = 221348, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(奢)*/
	{.bitmap_index = 221476, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奥)*/
	{.bitmap_index = 221612, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(女)*/
	{.bitmap_index = 221748, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奴)*/
	{.bitmap_index = 221884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奶)*/
	{.bitmap_index = 222012, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(奸)*/
	{.bitmap_index = 222140, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(她)*/
	{.bitmap_index = 222260, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(好)*/
	{.bitmap_index = 222388, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妁)*/
	{.bitmap_index = 222524, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(如)*/
	{.bitmap_index = 222660, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妃)*/
	{.bitmap_index = 222796, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妄)*/
	{.bitmap_index = 222924, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妆)*/
	{.bitmap_index = 223052, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妇)*/
	{.bitmap_index = 223172, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妈)*/
	{.bitmap_index = 223300, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妊)*/
	{.bitmap_index = 223428, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妍)*/
	{.bitmap_index = 223564, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妒)*/
	{.bitmap_index = 223700, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妓)*/
	{.bitmap_index = 223836, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妖)*/
	{.bitmap_index = 223972, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妗)*/
	{.bitmap_index = 224108, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妙)*/
	{.bitmap_index = 224244, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妞)*/
	{.bitmap_index = 224372, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妣)*/
	{.bitmap_index = 224500, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妤)*/
	{.bitmap_index = 224628, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妥)*/
	{.bitmap_index = 224756, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妨)*/
	{.bitmap_index = 224884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妩)*/
	{.bitmap_index = 225012, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妪)*/
	{.bitmap_index = 225132, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妫)*/
	{.bitmap_index = 225260, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妮)*/
	{.bitmap_index = 225380, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妯)*/
	{.bitmap_index = 225500, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(妲)*/
	{.bitmap_index = 225620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妹)*/
	{.bitmap_index = 225748, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妻)*/
	{.bitmap_index = 225884, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(妾)*/
	{.bitmap_index = 226020, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姆)*/
	{.bitmap_index = 226156, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(姊)*/
	{.bitmap_index = 226284, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(始)*/
	{.bitmap_index = 226420, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姐)*/
	{.bitmap_index = 226548, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姑)*/
	{.bitmap_index = 226676, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姒)*/
	{.bitmap_index = 226804, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姓)*/
	{.bitmap_index = 226940, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(委)*/
	{.bitmap_index = 227068, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姗)*/
	{.bitmap_index = 227196, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姘)*/
	{.bitmap_index = 227332, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姚)*/
	{.bitmap_index = 227468, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姜)*/
	{.bitmap_index = 227604, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(姝)*/
	{.bitmap_index = 227732, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姣)*/
	{.bitmap_index = 227860, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姥)*/
	{.bitmap_index = 227988, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姨)*/
	{.bitmap_index = 228124, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(姬)*/
	{.bitmap_index = 228244, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(姹)*/
	{.bitmap_index = 228372, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(姻)*/
	{.bitmap_index = 228492, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(姿)*/
	{.bitmap_index = 228628, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(威)*/
	{.bitmap_index = 228756, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娃)*/
	{.bitmap_index = 228876, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娄)*/
	{.bitmap_index = 229012, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娅)*/
	{.bitmap_index = 229132, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娆)*/
	{.bitmap_index = 229268, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娇)*/
	{.bitmap_index = 229404, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娈)*/
	{.bitmap_index = 229540, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娉)*/
	{.bitmap_index = 229668, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娌)*/
	{.bitmap_index = 229796, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(娑)*/
	{.bitmap_index = 229932, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娓)*/
	{.bitmap_index = 230060, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娘)*/
	{.bitmap_index = 230188, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娜)*/
	{.bitmap_index = 230316, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娟)*/
	{.bitmap_index = 230452, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娠)*/
	{.bitmap_index = 230588, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娣)*/
	{.bitmap_index = 230716, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娥)*/
	{.bitmap_index = 230844, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娩)*/
	{.bitmap_index = 230980, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娱)*/
	{.bitmap_index = 231108, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娲)*/
	{.bitmap_index = 231236, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(娴)*/
	{.bitmap_index = 231364, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娶)*/
	{.bitmap_index = 231492, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(娼)*/
	{.bitmap_index = 231620, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(婀)*/
	{.bitmap_index = 231740, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婆)*/
	{.bitmap_index = 231876, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婉)*/
	{.bitmap_index = 232012, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婊)*/
	{.bitmap_index = 232140, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婕)*/
	{.bitmap_index = 232276, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(婚)*/
	{.bitmap_index = 232396, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(婢)*/
	{.bitmap_index = 232524, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婧)*/
	{.bitmap_index = 232652, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婪)*/
	{.bitmap_index = 232788, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(婴)*/
	{.bitmap_index = 232900, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婵)*/
	{.bitmap_index = 233036, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(婶)*/
	{.bitmap_index = 233164, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(婷)*/
	{.bitmap_index = 233292, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婺)*/
	{.bitmap_index = 233428, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(婿)*/
	{.bitmap_index = 233556, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(媒)*/
	{.bitmap_index = 233684, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(媚)*/
	{.bitmap_index = 233812, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(媛)*/
	{.bitmap_index = 233940, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(媪)*/
	{.bitmap_index = 234068, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(媲)*/
	{.bitmap_index = 234204, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(媳)*/
	{.bitmap_index = 234332, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(媵)*/
	{.bitmap_index = 234468, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(媸)*/
	{.bitmap_index = 234604, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(媾)*/
	{.bitmap_index = 234732, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫁)*/
	{.bitmap_index = 234860, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫂)*/
	{.bitmap_index = 234988, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫉)*/
	{.bitmap_index = 235124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫌)*/
	{.bitmap_index = 235252, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫒)*/
	{.bitmap_index = 235380, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫔)*/
	{.bitmap_index = 235516, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫖)*/
	{.bitmap_index = 235644, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫘)*/
	{.bitmap_index = 235772, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫜)*/
	{.bitmap_index = 235900, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫠)*/
	{.bitmap_index = 236036, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫡)*/
	{.bitmap_index = 236164, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫣)*/
	{.bitmap_index = 236284, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嫦)*/
	{.bitmap_index = 236412, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫩)*/
	{.bitmap_index = 236548, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫫)*/
	{.bitmap_index = 236684, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嫱)*/
	{.bitmap_index = 236812, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嬉)*/
	{.bitmap_index = 236932, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嬖)*/
	{.bitmap_index = 237068, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嬗)*/
	{.bitmap_index = 237196, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嬲)*/
	{.bitmap_index = 237324, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嬴)*/
	{.bitmap_index = 237460, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嬷)*/
	{.bitmap_index = 237588, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孀)*/
	{.bitmap_index = 237708, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(子)*/
	{.bitmap_index = 237828, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孑)*/
	{.bitmap_index = 237948, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(孓)*/
	{.bitmap_index = 238068, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孔)*/
	{.bitmap_index = 238188, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孕)*/
	{.bitmap_index = 238308, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(字)*/
	{.bitmap_index = 238436, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(存)*/
	{.bitmap_index = 238564, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孙)*/
	{.bitmap_index = 238684, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孚)*/
	{.bitmap_index = 238804, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孛)*/
	{.bitmap_index = 238932, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(孜)*/
	{.bitmap_index = 239060, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孝)*/
	{.bitmap_index = 239188, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孟)*/
	{.bitmap_index = 239308, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孢)*/
	{.bitmap_index = 239436, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(季)*/
	{.bitmap_index = 239564, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孤)*/
	{.bitmap_index = 239684, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孥)*/
	{.bitmap_index = 239812, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(学)*/
	{.bitmap_index = 239924, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(孩)*/
	{.bitmap_index = 240052, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(孪)*/
	{.bitmap_index = 240188, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(孬)*/
	{.bitmap_index = 240316, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(孰)*/
	{.bitmap_index = 240452, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孱)*/
	{.bitmap_index = 240572, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孳)*/
	{.bitmap_index = 240700, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(孵)*/
	{.bitmap_index = 240836, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孺)*/
	{.bitmap_index = 240956, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(孽)*/
	{.bitmap_index = 241084, .adv_w = 15, .box_h = 7, .box_w = 14, .ofs_x = 1, .ofs_y = 12},/*(宀)*/
	{.bitmap_index = 241133, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宁)*/
	{.bitmap_index = 241245, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(它)*/
	{.bitmap_index = 241350, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(宄)*/
	{.bitmap_index = 241486, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宅)*/
	{.bitmap_index = 241606, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宇)*/
	{.bitmap_index = 241718, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(守)*/
	{.bitmap_index = 241846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(安)*/
	{.bitmap_index = 241974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宋)*/
	{.bitmap_index = 242102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(完)*/
	{.bitmap_index = 242230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宏)*/
	{.bitmap_index = 242358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宓)*/
	{.bitmap_index = 242486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宕)*/
	{.bitmap_index = 242614, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宗)*/
	{.bitmap_index = 242742, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(官)*/
	{.bitmap_index = 242847, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宙)*/
	{.bitmap_index = 242959, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(定)*/
	{.bitmap_index = 243095, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(宛)*/
	{.bitmap_index = 243231, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宜)*/
	{.bitmap_index = 243351, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宝)*/
	{.bitmap_index = 243463, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(实)*/
	{.bitmap_index = 243599, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宠)*/
	{.bitmap_index = 243727, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(审)*/
	{.bitmap_index = 243839, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(客)*/
	{.bitmap_index = 243967, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宣)*/
	{.bitmap_index = 244087, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(室)*/
	{.bitmap_index = 244215, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宥)*/
	{.bitmap_index = 244343, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宦)*/
	{.bitmap_index = 244455, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(宪)*/
	{.bitmap_index = 244591, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宫)*/
	{.bitmap_index = 244696, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宰)*/
	{.bitmap_index = 244824, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(害)*/
	{.bitmap_index = 244936, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(宴)*/
	{.bitmap_index = 245072, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(宵)*/
	{.bitmap_index = 245184, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(家)*/
	{.bitmap_index = 245312, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(宸)*/
	{.bitmap_index = 245448, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(容)*/
	{.bitmap_index = 245576, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(宽)*/
	{.bitmap_index = 245704, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(宾)*/
	{.bitmap_index = 245840, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(宿)*/
	{.bitmap_index = 245968, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寂)*/
	{.bitmap_index = 246104, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(寄)*/
	{.bitmap_index = 246232, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(寅)*/
	{.bitmap_index = 246344, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(密)*/
	{.bitmap_index = 246472, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寇)*/
	{.bitmap_index = 246608, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(富)*/
	{.bitmap_index = 246720, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寐)*/
	{.bitmap_index = 246856, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寒)*/
	{.bitmap_index = 246992, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(寓)*/
	{.bitmap_index = 247104, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寝)*/
	{.bitmap_index = 247240, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寞)*/
	{.bitmap_index = 247376, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(察)*/
	{.bitmap_index = 247504, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寡)*/
	{.bitmap_index = 247640, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寤)*/
	{.bitmap_index = 247776, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寥)*/
	{.bitmap_index = 247912, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寨)*/
	{.bitmap_index = 248048, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(寮)*/
	{.bitmap_index = 248176, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(寰)*/
	{.bitmap_index = 248312, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(寸)*/
	{.bitmap_index = 248440, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(对)*/
	{.bitmap_index = 248560, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(寺)*/
	{.bitmap_index = 248688, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(寻)*/
	{.bitmap_index = 248808, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(导)*/
	{.bitmap_index = 248928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(寿)*/
	{.bitmap_index = 249056, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(封)*/
	{.bitmap_index = 249176, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(射)*/
	{.bitmap_index = 249304, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(将)*/
	{.bitmap_index = 249432, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尉)*/
	{.bitmap_index = 249552, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尊)*/
	{.bitmap_index = 249680, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(小)*/
	{.bitmap_index = 249800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(少)*/
	{.bitmap_index = 249928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尔)*/
	{.bitmap_index = 250056, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尕)*/
	{.bitmap_index = 250176, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尖)*/
	{.bitmap_index = 250304, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尘)*/
	{.bitmap_index = 250424, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(尚)*/
	{.bitmap_index = 250529, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尜)*/
	{.bitmap_index = 250657, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(尝)*/
	{.bitmap_index = 250776, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尢)*/
	{.bitmap_index = 250904, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尤)*/
	{.bitmap_index = 251032, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尥)*/
	{.bitmap_index = 251168, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尧)*/
	{.bitmap_index = 251304, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尬)*/
	{.bitmap_index = 251432, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(就)*/
	{.bitmap_index = 251560, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(尴)*/
	{.bitmap_index = 251680, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尸)*/
	{.bitmap_index = 251808, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尹)*/
	{.bitmap_index = 251936, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尺)*/
	{.bitmap_index = 252064, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尻)*/
	{.bitmap_index = 252192, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尼)*/
	{.bitmap_index = 252320, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尽)*/
	{.bitmap_index = 252448, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尾)*/
	{.bitmap_index = 252576, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(尿)*/
	{.bitmap_index = 252704, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(局)*/
	{.bitmap_index = 252824, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(屁)*/
	{.bitmap_index = 252944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(层)*/
	{.bitmap_index = 253072, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(居)*/
	{.bitmap_index = 253192, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(屈)*/
	{.bitmap_index = 253312, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屉)*/
	{.bitmap_index = 253440, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(届)*/
	{.bitmap_index = 253560, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屋)*/
	{.bitmap_index = 253688, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屎)*/
	{.bitmap_index = 253816, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屏)*/
	{.bitmap_index = 253944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屐)*/
	{.bitmap_index = 254072, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(屑)*/
	{.bitmap_index = 254192, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(展)*/
	{.bitmap_index = 254320, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(屙)*/
	{.bitmap_index = 254440, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(属)*/
	{.bitmap_index = 254560, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(屠)*/
	{.bitmap_index = 254680, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屡)*/
	{.bitmap_index = 254808, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屣)*/
	{.bitmap_index = 254936, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(履)*/
	{.bitmap_index = 255064, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(屦)*/
	{.bitmap_index = 255192, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(屮)*/
	{.bitmap_index = 255282, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(屯)*/
	{.bitmap_index = 255402, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(山)*/
	{.bitmap_index = 255507, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(屹)*/
	{.bitmap_index = 255635, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(屺)*/
	{.bitmap_index = 255755, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(屿)*/
	{.bitmap_index = 255860, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(岁)*/
	{.bitmap_index = 255996, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(岂)*/
	{.bitmap_index = 256101, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(岈)*/
	{.bitmap_index = 256229, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(岌)*/
	{.bitmap_index = 256365, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(岍)*/
	{.bitmap_index = 256493, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(岐)*/
	{.bitmap_index = 256629, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(岑)*/
	{.bitmap_index = 256757, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岔)*/
	{.bitmap_index = 256885, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(岖)*/
	{.bitmap_index = 257005, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(岗)*/
	{.bitmap_index = 257117, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(岘)*/
	{.bitmap_index = 257245, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岙)*/
	{.bitmap_index = 257373, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(岚)*/
	{.bitmap_index = 257509, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(岛)*/
	{.bitmap_index = 257621, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(岜)*/
	{.bitmap_index = 257749, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岢)*/
	{.bitmap_index = 257869, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(岣)*/
	{.bitmap_index = 257981, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岩)*/
	{.bitmap_index = 258101, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(岫)*/
	{.bitmap_index = 258206, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(岬)*/
	{.bitmap_index = 258311, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(岭)*/
	{.bitmap_index = 258447, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岱)*/
	{.bitmap_index = 258575, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岳)*/
	{.bitmap_index = 258703, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(岵)*/
	{.bitmap_index = 258831, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(岷)*/
	{.bitmap_index = 258959, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(岸)*/
	{.bitmap_index = 259087, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(岽)*/
	{.bitmap_index = 259207, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(岿)*/
	{.bitmap_index = 259319, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(峁)*/
	{.bitmap_index = 259431, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(峄)*/
	{.bitmap_index = 259551, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(峋)*/
	{.bitmap_index = 259663, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(峒)*/
	{.bitmap_index = 259768, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(峙)*/
	{.bitmap_index = 259888, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(峡)*/
	{.bitmap_index = 260016, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(峤)*/
	{.bitmap_index = 260144, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(峥)*/
	{.bitmap_index = 260272, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(峦)*/
	{.bitmap_index = 260400, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(峨)*/
	{.bitmap_index = 260520, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(峪)*/
	{.bitmap_index = 260640, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(峭)*/
	{.bitmap_index = 260768, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(峰)*/
	{.bitmap_index = 260896, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(峻)*/
	{.bitmap_index = 261032, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(崂)*/
	{.bitmap_index = 261160, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(崃)*/
	{.bitmap_index = 261288, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(崆)*/
	{.bitmap_index = 261416, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(崇)*/
	{.bitmap_index = 261544, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(崎)*/
	{.bitmap_index = 261664, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(崔)*/
	{.bitmap_index = 261784, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(崖)*/
	{.bitmap_index = 261912, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(崛)*/
	{.bitmap_index = 262017, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(崞)*/
	{.bitmap_index = 262137, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(崤)*/
	{.bitmap_index = 262265, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(崦)*/
	{.bitmap_index = 262393, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(崧)*/
	{.bitmap_index = 262521, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(崩)*/
	{.bitmap_index = 262657, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(崭)*/
	{.bitmap_index = 262793, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(崮)*/
	{.bitmap_index = 262898, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(崴)*/
	{.bitmap_index = 263034, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(崽)*/
	{.bitmap_index = 263162, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(崾)*/
	{.bitmap_index = 263290, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嵇)*/
	{.bitmap_index = 263410, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嵊)*/
	{.bitmap_index = 263530, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嵋)*/
	{.bitmap_index = 263635, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嵌)*/
	{.bitmap_index = 263771, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嵘)*/
	{.bitmap_index = 263899, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嵛)*/
	{.bitmap_index = 264027, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嵝)*/
	{.bitmap_index = 264155, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(嵩)*/
	{.bitmap_index = 264267, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嵫)*/
	{.bitmap_index = 264395, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嵬)*/
	{.bitmap_index = 264523, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嵯)*/
	{.bitmap_index = 264651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嵴)*/
	{.bitmap_index = 264779, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(嶂)*/
	{.bitmap_index = 264907, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(嶙)*/
	{.bitmap_index = 265043, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(嶝)*/
	{.bitmap_index = 265163, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(嶷)*/
	{.bitmap_index = 265299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(巅)*/
	{.bitmap_index = 265427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巍)*/
	{.bitmap_index = 265555, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巛)*/
	{.bitmap_index = 265675, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(川)*/
	{.bitmap_index = 265803, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(州)*/
	{.bitmap_index = 265931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巡)*/
	{.bitmap_index = 266051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巢)*/
	{.bitmap_index = 266179, .adv_w = 16, .box_h = 13, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(工)*/
	{.bitmap_index = 266283, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(左)*/
	{.bitmap_index = 266411, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巧)*/
	{.bitmap_index = 266531, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(巨)*/
	{.bitmap_index = 266636, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(巩)*/
	{.bitmap_index = 266764, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巫)*/
	{.bitmap_index = 266884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(差)*/
	{.bitmap_index = 267012, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(巯)*/
	{.bitmap_index = 267148, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(己)*/
	{.bitmap_index = 267253, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(已)*/
	{.bitmap_index = 267358, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(巳)*/
	{.bitmap_index = 267463, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(巴)*/
	{.bitmap_index = 267583, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(巷)*/
	{.bitmap_index = 267703, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(巽)*/
	{.bitmap_index = 267831, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(巾)*/
	{.bitmap_index = 267936, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(币)*/
	{.bitmap_index = 268041, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(市)*/
	{.bitmap_index = 268169, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(布)*/
	{.bitmap_index = 268297, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(帅)*/
	{.bitmap_index = 268409, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(帆)*/
	{.bitmap_index = 268537, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(师)*/
	{.bitmap_index = 268665, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(希)*/
	{.bitmap_index = 268793, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帏)*/
	{.bitmap_index = 268905, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(帐)*/
	{.bitmap_index = 269025, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(帑)*/
	{.bitmap_index = 269153, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(帔)*/
	{.bitmap_index = 269289, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帕)*/
	{.bitmap_index = 269401, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(帖)*/
	{.bitmap_index = 269521, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(帘)*/
	{.bitmap_index = 269649, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(帙)*/
	{.bitmap_index = 269777, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帚)*/
	{.bitmap_index = 269882, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帛)*/
	{.bitmap_index = 269994, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(帜)*/
	{.bitmap_index = 270122, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帝)*/
	{.bitmap_index = 270234, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(带)*/
	{.bitmap_index = 270354, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(帧)*/
	{.bitmap_index = 270490, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(席)*/
	{.bitmap_index = 270626, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(帮)*/
	{.bitmap_index = 270746, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(帱)*/
	{.bitmap_index = 270874, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(帷)*/
	{.bitmap_index = 271002, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(常)*/
	{.bitmap_index = 271114, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(帻)*/
	{.bitmap_index = 271242, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帼)*/
	{.bitmap_index = 271347, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(帽)*/
	{.bitmap_index = 271452, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(幂)*/
	{.bitmap_index = 271572, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(幄)*/
	{.bitmap_index = 271700, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(幅)*/
	{.bitmap_index = 271820, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(幌)*/
	{.bitmap_index = 271956, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(幔)*/
	{.bitmap_index = 272092, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(幕)*/
	{.bitmap_index = 272220, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(幛)*/
	{.bitmap_index = 272348, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(幞)*/
	{.bitmap_index = 272484, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(幡)*/
	{.bitmap_index = 272612, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(幢)*/
	{.bitmap_index = 272740, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(干)*/
	{.bitmap_index = 272860, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(平)*/
	{.bitmap_index = 272980, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(年)*/
	{.bitmap_index = 273108, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(并)*/
	{.bitmap_index = 273244, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(幸)*/
	{.bitmap_index = 273364, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(幺)*/
	{.bitmap_index = 273476, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(幻)*/
	{.bitmap_index = 273596, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(幼)*/
	{.bitmap_index = 273732, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(幽)*/
	{.bitmap_index = 273837, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(广)*/
	{.bitmap_index = 273973, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(庀)*/
	{.bitmap_index = 274101, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庄)*/
	{.bitmap_index = 274237, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庆)*/
	{.bitmap_index = 274373, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(庇)*/
	{.bitmap_index = 274493, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(床)*/
	{.bitmap_index = 274629, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庋)*/
	{.bitmap_index = 274765, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(序)*/
	{.bitmap_index = 274901, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庐)*/
	{.bitmap_index = 275037, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庑)*/
	{.bitmap_index = 275173, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(库)*/
	{.bitmap_index = 275309, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(应)*/
	{.bitmap_index = 275445, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(底)*/
	{.bitmap_index = 275581, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(庖)*/
	{.bitmap_index = 275709, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(店)*/
	{.bitmap_index = 275837, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庙)*/
	{.bitmap_index = 275973, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庚)*/
	{.bitmap_index = 276109, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(府)*/
	{.bitmap_index = 276245, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庞)*/
	{.bitmap_index = 276381, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(废)*/
	{.bitmap_index = 276517, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庠)*/
	{.bitmap_index = 276653, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庥)*/
	{.bitmap_index = 276789, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(度)*/
	{.bitmap_index = 276925, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(座)*/
	{.bitmap_index = 277061, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庭)*/
	{.bitmap_index = 277197, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(庳)*/
	{.bitmap_index = 277325, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(庵)*/
	{.bitmap_index = 277453, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庶)*/
	{.bitmap_index = 277589, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(康)*/
	{.bitmap_index = 277717, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(庸)*/
	{.bitmap_index = 277845, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庹)*/
	{.bitmap_index = 277981, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(庾)*/
	{.bitmap_index = 278117, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廉)*/
	{.bitmap_index = 278245, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廊)*/
	{.bitmap_index = 278373, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廑)*/
	{.bitmap_index = 278501, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(廒)*/
	{.bitmap_index = 278637, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廓)*/
	{.bitmap_index = 278765, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(廖)*/
	{.bitmap_index = 278893, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廛)*/
	{.bitmap_index = 279021, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(廨)*/
	{.bitmap_index = 279157, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(廪)*/
	{.bitmap_index = 279293, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廴)*/
	{.bitmap_index = 279413, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(延)*/
	{.bitmap_index = 279541, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廷)*/
	{.bitmap_index = 279661, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(建)*/
	{.bitmap_index = 279797, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(廾)*/
	{.bitmap_index = 279925, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(廿)*/
	{.bitmap_index = 280045, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(开)*/
	{.bitmap_index = 280173, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(弁)*/
	{.bitmap_index = 280309, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(异)*/
	{.bitmap_index = 280437, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(弃)*/
	{.bitmap_index = 280573, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(弄)*/
	{.bitmap_index = 280701, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(弈)*/
	{.bitmap_index = 280837, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(弊)*/
	{.bitmap_index = 280973, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(弋)*/
	{.bitmap_index = 281101, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(式)*/
	{.bitmap_index = 281229, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弑)*/
	{.bitmap_index = 281357, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(弓)*/
	{.bitmap_index = 281462, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(引)*/
	{.bitmap_index = 281567, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(弗)*/
	{.bitmap_index = 281679, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(弘)*/
	{.bitmap_index = 281799, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(弛)*/
	{.bitmap_index = 281919, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弟)*/
	{.bitmap_index = 282047, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(张)*/
	{.bitmap_index = 282167, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弥)*/
	{.bitmap_index = 282295, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(弦)*/
	{.bitmap_index = 282423, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弧)*/
	{.bitmap_index = 282543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弩)*/
	{.bitmap_index = 282671, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(弪)*/
	{.bitmap_index = 282791, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弭)*/
	{.bitmap_index = 282911, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(弯)*/
	{.bitmap_index = 283047, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弱)*/
	{.bitmap_index = 283167, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(弹)*/
	{.bitmap_index = 283295, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(强)*/
	{.bitmap_index = 283423, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(弼)*/
	{.bitmap_index = 283543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(彀)*/
	{.bitmap_index = 283671, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(彐)*/
	{.bitmap_index = 283769, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(归)*/
	{.bitmap_index = 283881, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(当)*/
	{.bitmap_index = 283986, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(录)*/
	{.bitmap_index = 284106, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(彖)*/
	{.bitmap_index = 284234, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(彗)*/
	{.bitmap_index = 284339, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(彘)*/
	{.bitmap_index = 284459, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彝)*/
	{.bitmap_index = 284595, .adv_w = 14, .box_h = 16, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(彡)*/
	{.bitmap_index = 284691, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(形)*/
	{.bitmap_index = 284827, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彤)*/
	{.bitmap_index = 284955, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彦)*/
	{.bitmap_index = 285091, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彩)*/
	{.bitmap_index = 285219, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彪)*/
	{.bitmap_index = 285355, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(彬)*/
	{.bitmap_index = 285475, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彭)*/
	{.bitmap_index = 285603, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彰)*/
	{.bitmap_index = 285739, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(影)*/
	{.bitmap_index = 285867, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(彳)*/
	{.bitmap_index = 285947, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(彷)*/
	{.bitmap_index = 286075, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(役)*/
	{.bitmap_index = 286211, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彻)*/
	{.bitmap_index = 286339, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(彼)*/
	{.bitmap_index = 286475, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(往)*/
	{.bitmap_index = 286603, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(征)*/
	{.bitmap_index = 286731, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徂)*/
	{.bitmap_index = 286859, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(径)*/
	{.bitmap_index = 286987, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(待)*/
	{.bitmap_index = 287115, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徇)*/
	{.bitmap_index = 287243, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(很)*/
	{.bitmap_index = 287379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徉)*/
	{.bitmap_index = 287507, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徊)*/
	{.bitmap_index = 287627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(律)*/
	{.bitmap_index = 287755, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(後)*/
	{.bitmap_index = 287891, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徐)*/
	{.bitmap_index = 288019, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(徒)*/
	{.bitmap_index = 288155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徕)*/
	{.bitmap_index = 288283, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(得)*/
	{.bitmap_index = 288411, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徘)*/
	{.bitmap_index = 288531, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徙)*/
	{.bitmap_index = 288659, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徜)*/
	{.bitmap_index = 288787, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(御)*/
	{.bitmap_index = 288915, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徨)*/
	{.bitmap_index = 289043, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(循)*/
	{.bitmap_index = 289171, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徭)*/
	{.bitmap_index = 289291, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(微)*/
	{.bitmap_index = 289411, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徵)*/
	{.bitmap_index = 289539, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(德)*/
	{.bitmap_index = 289667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(徼)*/
	{.bitmap_index = 289795, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(徽)*/
	{.bitmap_index = 289931, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(心)*/
	{.bitmap_index = 290059, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(忄)*/
	{.bitmap_index = 290139, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(必)*/
	{.bitmap_index = 290267, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忆)*/
	{.bitmap_index = 290395, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忉)*/
	{.bitmap_index = 290523, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忌)*/
	{.bitmap_index = 290643, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忍)*/
	{.bitmap_index = 290763, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忏)*/
	{.bitmap_index = 290891, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忐)*/
	{.bitmap_index = 291019, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忑)*/
	{.bitmap_index = 291139, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忒)*/
	{.bitmap_index = 291267, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忖)*/
	{.bitmap_index = 291395, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(志)*/
	{.bitmap_index = 291523, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忘)*/
	{.bitmap_index = 291651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忙)*/
	{.bitmap_index = 291779, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忝)*/
	{.bitmap_index = 291899, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忠)*/
	{.bitmap_index = 292019, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忡)*/
	{.bitmap_index = 292147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忤)*/
	{.bitmap_index = 292275, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(忧)*/
	{.bitmap_index = 292403, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忪)*/
	{.bitmap_index = 292531, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(快)*/
	{.bitmap_index = 292667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忭)*/
	{.bitmap_index = 292795, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忮)*/
	{.bitmap_index = 292923, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忱)*/
	{.bitmap_index = 293051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(念)*/
	{.bitmap_index = 293179, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忸)*/
	{.bitmap_index = 293307, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(忻)*/
	{.bitmap_index = 293443, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忽)*/
	{.bitmap_index = 293571, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忾)*/
	{.bitmap_index = 293699, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(忿)*/
	{.bitmap_index = 293827, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怀)*/
	{.bitmap_index = 293955, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(态)*/
	{.bitmap_index = 294083, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怂)*/
	{.bitmap_index = 294211, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怃)*/
	{.bitmap_index = 294339, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怄)*/
	{.bitmap_index = 294467, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怅)*/
	{.bitmap_index = 294595, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怆)*/
	{.bitmap_index = 294723, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怊)*/
	{.bitmap_index = 294851, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怍)*/
	{.bitmap_index = 294979, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怎)*/
	{.bitmap_index = 295107, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(怏)*/
	{.bitmap_index = 295235, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怒)*/
	{.bitmap_index = 295363, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怔)*/
	{.bitmap_index = 295491, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怕)*/
	{.bitmap_index = 295619, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怖)*/
	{.bitmap_index = 295747, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怙)*/
	{.bitmap_index = 295875, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怛)*/
	{.bitmap_index = 296003, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(怜)*/
	{.bitmap_index = 296139, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(思)*/
	{.bitmap_index = 296259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怠)*/
	{.bitmap_index = 296387, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怡)*/
	{.bitmap_index = 296515, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(急)*/
	{.bitmap_index = 296643, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怦)*/
	{.bitmap_index = 296771, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(性)*/
	{.bitmap_index = 296899, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怨)*/
	{.bitmap_index = 297027, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怩)*/
	{.bitmap_index = 297155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怪)*/
	{.bitmap_index = 297283, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(怫)*/
	{.bitmap_index = 297419, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怯)*/
	{.bitmap_index = 297547, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怵)*/
	{.bitmap_index = 297675, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(总)*/
	{.bitmap_index = 297803, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怼)*/
	{.bitmap_index = 297931, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(怿)*/
	{.bitmap_index = 298059, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恁)*/
	{.bitmap_index = 298187, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恂)*/
	{.bitmap_index = 298315, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恃)*/
	{.bitmap_index = 298443, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恋)*/
	{.bitmap_index = 298571, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(恍)*/
	{.bitmap_index = 298707, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恐)*/
	{.bitmap_index = 298827, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恒)*/
	{.bitmap_index = 298955, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恕)*/
	{.bitmap_index = 299083, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恙)*/
	{.bitmap_index = 299211, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恚)*/
	{.bitmap_index = 299339, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恝)*/
	{.bitmap_index = 299467, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恢)*/
	{.bitmap_index = 299595, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恣)*/
	{.bitmap_index = 299723, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恤)*/
	{.bitmap_index = 299851, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恧)*/
	{.bitmap_index = 299971, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恨)*/
	{.bitmap_index = 300099, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恩)*/
	{.bitmap_index = 300219, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恪)*/
	{.bitmap_index = 300347, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恫)*/
	{.bitmap_index = 300475, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恬)*/
	{.bitmap_index = 300603, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恭)*/
	{.bitmap_index = 300731, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(息)*/
	{.bitmap_index = 300859, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恰)*/
	{.bitmap_index = 300987, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恳)*/
	{.bitmap_index = 301107, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恶)*/
	{.bitmap_index = 301227, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(恸)*/
	{.bitmap_index = 301363, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(恹)*/
	{.bitmap_index = 301499, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恺)*/
	{.bitmap_index = 301627, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恻)*/
	{.bitmap_index = 301747, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恼)*/
	{.bitmap_index = 301875, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恽)*/
	{.bitmap_index = 302003, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(恿)*/
	{.bitmap_index = 302123, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悃)*/
	{.bitmap_index = 302251, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悄)*/
	{.bitmap_index = 302379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悉)*/
	{.bitmap_index = 302507, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悌)*/
	{.bitmap_index = 302635, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悍)*/
	{.bitmap_index = 302763, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悒)*/
	{.bitmap_index = 302891, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悔)*/
	{.bitmap_index = 303019, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悖)*/
	{.bitmap_index = 303147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悚)*/
	{.bitmap_index = 303275, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(悛)*/
	{.bitmap_index = 303411, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悝)*/
	{.bitmap_index = 303539, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悟)*/
	{.bitmap_index = 303667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悠)*/
	{.bitmap_index = 303795, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(患)*/
	{.bitmap_index = 303923, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(悦)*/
	{.bitmap_index = 304059, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(您)*/
	{.bitmap_index = 304187, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悫)*/
	{.bitmap_index = 304315, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悬)*/
	{.bitmap_index = 304435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悭)*/
	{.bitmap_index = 304563, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悯)*/
	{.bitmap_index = 304691, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悱)*/
	{.bitmap_index = 304819, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悲)*/
	{.bitmap_index = 304939, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悴)*/
	{.bitmap_index = 305067, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悸)*/
	{.bitmap_index = 305195, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悻)*/
	{.bitmap_index = 305323, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(悼)*/
	{.bitmap_index = 305451, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(情)*/
	{.bitmap_index = 305579, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(惆)*/
	{.bitmap_index = 305707, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惊)*/
	{.bitmap_index = 305835, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惋)*/
	{.bitmap_index = 305963, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惑)*/
	{.bitmap_index = 306091, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(惕)*/
	{.bitmap_index = 306227, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惘)*/
	{.bitmap_index = 306355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惚)*/
	{.bitmap_index = 306483, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惜)*/
	{.bitmap_index = 306611, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惝)*/
	{.bitmap_index = 306739, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惟)*/
	{.bitmap_index = 306867, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惠)*/
	{.bitmap_index = 306995, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惦)*/
	{.bitmap_index = 307115, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惧)*/
	{.bitmap_index = 307243, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(惨)*/
	{.bitmap_index = 307379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惩)*/
	{.bitmap_index = 307507, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惫)*/
	{.bitmap_index = 307635, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惬)*/
	{.bitmap_index = 307763, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惭)*/
	{.bitmap_index = 307891, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惮)*/
	{.bitmap_index = 308019, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惯)*/
	{.bitmap_index = 308147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惰)*/
	{.bitmap_index = 308275, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(想)*/
	{.bitmap_index = 308403, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惴)*/
	{.bitmap_index = 308531, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惶)*/
	{.bitmap_index = 308659, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惹)*/
	{.bitmap_index = 308779, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(惺)*/
	{.bitmap_index = 308899, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愀)*/
	{.bitmap_index = 309027, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愁)*/
	{.bitmap_index = 309155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愆)*/
	{.bitmap_index = 309283, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愈)*/
	{.bitmap_index = 309411, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愉)*/
	{.bitmap_index = 309539, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愍)*/
	{.bitmap_index = 309667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愎)*/
	{.bitmap_index = 309795, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(意)*/
	{.bitmap_index = 309923, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愕)*/
	{.bitmap_index = 310051, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愚)*/
	{.bitmap_index = 310171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(感)*/
	{.bitmap_index = 310299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愠)*/
	{.bitmap_index = 310427, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(愣)*/
	{.bitmap_index = 310563, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(愤)*/
	{.bitmap_index = 310699, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愦)*/
	{.bitmap_index = 310827, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(愧)*/
	{.bitmap_index = 310963, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(愫)*/
	{.bitmap_index = 311091, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(愿)*/
	{.bitmap_index = 311219, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慈)*/
	{.bitmap_index = 311347, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慊)*/
	{.bitmap_index = 311475, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慌)*/
	{.bitmap_index = 311603, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(慎)*/
	{.bitmap_index = 311739, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(慑)*/
	{.bitmap_index = 311875, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慕)*/
	{.bitmap_index = 312003, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慝)*/
	{.bitmap_index = 312123, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(慢)*/
	{.bitmap_index = 312259, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慧)*/
	{.bitmap_index = 312379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慨)*/
	{.bitmap_index = 312507, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慰)*/
	{.bitmap_index = 312627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慵)*/
	{.bitmap_index = 312755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(慷)*/
	{.bitmap_index = 312883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憋)*/
	{.bitmap_index = 313011, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憎)*/
	{.bitmap_index = 313139, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憔)*/
	{.bitmap_index = 313267, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憝)*/
	{.bitmap_index = 313395, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憧)*/
	{.bitmap_index = 313523, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憨)*/
	{.bitmap_index = 313643, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憩)*/
	{.bitmap_index = 313771, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憬)*/
	{.bitmap_index = 313899, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憷)*/
	{.bitmap_index = 314027, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(憾)*/
	{.bitmap_index = 314155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懂)*/
	{.bitmap_index = 314283, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懈)*/
	{.bitmap_index = 314411, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(懊)*/
	{.bitmap_index = 314547, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懋)*/
	{.bitmap_index = 314667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懑)*/
	{.bitmap_index = 314795, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懒)*/
	{.bitmap_index = 314923, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懔)*/
	{.bitmap_index = 315051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懦)*/
	{.bitmap_index = 315179, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懵)*/
	{.bitmap_index = 315307, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(懿)*/
	{.bitmap_index = 315427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戆)*/
	{.bitmap_index = 315555, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戈)*/
	{.bitmap_index = 315683, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戊)*/
	{.bitmap_index = 315811, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戋)*/
	{.bitmap_index = 315939, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戌)*/
	{.bitmap_index = 316075, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戍)*/
	{.bitmap_index = 316203, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戎)*/
	{.bitmap_index = 316339, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戏)*/
	{.bitmap_index = 316459, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(成)*/
	{.bitmap_index = 316587, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(我)*/
	{.bitmap_index = 316715, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戒)*/
	{.bitmap_index = 316851, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戕)*/
	{.bitmap_index = 316979, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(或)*/
	{.bitmap_index = 317115, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戗)*/
	{.bitmap_index = 317243, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(战)*/
	{.bitmap_index = 317371, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戚)*/
	{.bitmap_index = 317499, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戛)*/
	{.bitmap_index = 317627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戟)*/
	{.bitmap_index = 317755, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戡)*/
	{.bitmap_index = 317875, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戢)*/
	{.bitmap_index = 318003, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戤)*/
	{.bitmap_index = 318131, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戥)*/
	{.bitmap_index = 318251, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(截)*/
	{.bitmap_index = 318379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戬)*/
	{.bitmap_index = 318507, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戮)*/
	{.bitmap_index = 318635, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(戳)*/
	{.bitmap_index = 318763, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戴)*/
	{.bitmap_index = 318891, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(户)*/
	{.bitmap_index = 319027, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戽)*/
	{.bitmap_index = 319163, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(戾)*/
	{.bitmap_index = 319299, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(房)*/
	{.bitmap_index = 319435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(所)*/
	{.bitmap_index = 319563, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扁)*/
	{.bitmap_index = 319691, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扃)*/
	{.bitmap_index = 319819, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扇)*/
	{.bitmap_index = 319947, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扈)*/
	{.bitmap_index = 320075, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扉)*/
	{.bitmap_index = 320203, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(手)*/
	{.bitmap_index = 320323, .adv_w = 9, .box_h = 16, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(扌)*/
	{.bitmap_index = 320387, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(才)*/
	{.bitmap_index = 320507, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扎)*/
	{.bitmap_index = 320635, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扑)*/
	{.bitmap_index = 320763, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扒)*/
	{.bitmap_index = 320883, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(打)*/
	{.bitmap_index = 321003, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扔)*/
	{.bitmap_index = 321139, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(托)*/
	{.bitmap_index = 321259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扛)*/
	{.bitmap_index = 321387, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扣)*/
	{.bitmap_index = 321507, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扦)*/
	{.bitmap_index = 321627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(执)*/
	{.bitmap_index = 321755, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扩)*/
	{.bitmap_index = 321891, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扪)*/
	{.bitmap_index = 322019, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扫)*/
	{.bitmap_index = 322147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扬)*/
	{.bitmap_index = 322275, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扭)*/
	{.bitmap_index = 322395, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扮)*/
	{.bitmap_index = 322531, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扯)*/
	{.bitmap_index = 322651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(扰)*/
	{.bitmap_index = 322779, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扳)*/
	{.bitmap_index = 322907, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扶)*/
	{.bitmap_index = 323043, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(批)*/
	{.bitmap_index = 323163, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(扼)*/
	{.bitmap_index = 323291, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(找)*/
	{.bitmap_index = 323411, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(承)*/
	{.bitmap_index = 323539, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(技)*/
	{.bitmap_index = 323675, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抄)*/
	{.bitmap_index = 323811, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抉)*/
	{.bitmap_index = 323947, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(把)*/
	{.bitmap_index = 324067, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抑)*/
	{.bitmap_index = 324195, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抒)*/
	{.bitmap_index = 324323, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抓)*/
	{.bitmap_index = 324443, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(投)*/
	{.bitmap_index = 324571, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抖)*/
	{.bitmap_index = 324691, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抗)*/
	{.bitmap_index = 324819, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(折)*/
	{.bitmap_index = 324947, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抚)*/
	{.bitmap_index = 325083, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抛)*/
	{.bitmap_index = 325211, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抟)*/
	{.bitmap_index = 325347, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抠)*/
	{.bitmap_index = 325467, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抡)*/
	{.bitmap_index = 325595, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抢)*/
	{.bitmap_index = 325723, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(护)*/
	{.bitmap_index = 325851, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(报)*/
	{.bitmap_index = 325979, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抨)*/
	{.bitmap_index = 326099, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(披)*/
	{.bitmap_index = 326227, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抬)*/
	{.bitmap_index = 326355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抱)*/
	{.bitmap_index = 326483, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抵)*/
	{.bitmap_index = 326619, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抹)*/
	{.bitmap_index = 326747, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抻)*/
	{.bitmap_index = 326875, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(押)*/
	{.bitmap_index = 326995, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(抽)*/
	{.bitmap_index = 327115, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(抿)*/
	{.bitmap_index = 327243, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拂)*/
	{.bitmap_index = 327379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拄)*/
	{.bitmap_index = 327507, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(担)*/
	{.bitmap_index = 327635, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拆)*/
	{.bitmap_index = 327763, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拇)*/
	{.bitmap_index = 327883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拈)*/
	{.bitmap_index = 328011, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拉)*/
	{.bitmap_index = 328131, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拊)*/
	{.bitmap_index = 328259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拌)*/
	{.bitmap_index = 328387, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拍)*/
	{.bitmap_index = 328515, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拎)*/
	{.bitmap_index = 328651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拐)*/
	{.bitmap_index = 328779, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拒)*/
	{.bitmap_index = 328899, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拓)*/
	{.bitmap_index = 329019, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拔)*/
	{.bitmap_index = 329155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拖)*/
	{.bitmap_index = 329283, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拗)*/
	{.bitmap_index = 329403, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拘)*/
	{.bitmap_index = 329531, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拙)*/
	{.bitmap_index = 329659, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拚)*/
	{.bitmap_index = 329795, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(招)*/
	{.bitmap_index = 329915, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拜)*/
	{.bitmap_index = 330043, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拟)*/
	{.bitmap_index = 330171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拢)*/
	{.bitmap_index = 330299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拣)*/
	{.bitmap_index = 330427, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拥)*/
	{.bitmap_index = 330547, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拦)*/
	{.bitmap_index = 330675, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拧)*/
	{.bitmap_index = 330803, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拨)*/
	{.bitmap_index = 330931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(择)*/
	{.bitmap_index = 331051, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(括)*/
	{.bitmap_index = 331171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拭)*/
	{.bitmap_index = 331299, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拮)*/
	{.bitmap_index = 331419, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拯)*/
	{.bitmap_index = 331539, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拱)*/
	{.bitmap_index = 331667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拳)*/
	{.bitmap_index = 331795, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拴)*/
	{.bitmap_index = 331923, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拶)*/
	{.bitmap_index = 332059, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拷)*/
	{.bitmap_index = 332179, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(拼)*/
	{.bitmap_index = 332315, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拽)*/
	{.bitmap_index = 332435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拾)*/
	{.bitmap_index = 332563, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(拿)*/
	{.bitmap_index = 332691, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(持)*/
	{.bitmap_index = 332811, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挂)*/
	{.bitmap_index = 332931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(指)*/
	{.bitmap_index = 333051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挈)*/
	{.bitmap_index = 333179, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(按)*/
	{.bitmap_index = 333315, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挎)*/
	{.bitmap_index = 333443, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(挑)*/
	{.bitmap_index = 333571, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挖)*/
	{.bitmap_index = 333699, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挚)*/
	{.bitmap_index = 333819, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挛)*/
	{.bitmap_index = 333947, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挝)*/
	{.bitmap_index = 334075, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挞)*/
	{.bitmap_index = 334203, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(挟)*/
	{.bitmap_index = 334339, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(挠)*/
	{.bitmap_index = 334475, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挡)*/
	{.bitmap_index = 334595, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(挢)*/
	{.bitmap_index = 334731, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挣)*/
	{.bitmap_index = 334859, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(挤)*/
	{.bitmap_index = 334995, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挥)*/
	{.bitmap_index = 335115, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(挨)*/
	{.bitmap_index = 335251, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挪)*/
	{.bitmap_index = 335379, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挫)*/
	{.bitmap_index = 335499, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(振)*/
	{.bitmap_index = 335627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挲)*/
	{.bitmap_index = 335755, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挹)*/
	{.bitmap_index = 335875, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挺)*/
	{.bitmap_index = 336003, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(挽)*/
	{.bitmap_index = 336131, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捂)*/
	{.bitmap_index = 336259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捃)*/
	{.bitmap_index = 336387, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捅)*/
	{.bitmap_index = 336507, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捆)*/
	{.bitmap_index = 336627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(捉)*/
	{.bitmap_index = 336755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捋)*/
	{.bitmap_index = 336883, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捌)*/
	{.bitmap_index = 337003, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捍)*/
	{.bitmap_index = 337123, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捎)*/
	{.bitmap_index = 337251, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捏)*/
	{.bitmap_index = 337371, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捐)*/
	{.bitmap_index = 337499, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捕)*/
	{.bitmap_index = 337627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(捞)*/
	{.bitmap_index = 337755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(损)*/
	{.bitmap_index = 337883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捡)*/
	{.bitmap_index = 338011, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(换)*/
	{.bitmap_index = 338147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捣)*/
	{.bitmap_index = 338275, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(捧)*/
	{.bitmap_index = 338403, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(捩)*/
	{.bitmap_index = 338539, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捭)*/
	{.bitmap_index = 338667, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(据)*/
	{.bitmap_index = 338787, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(捱)*/
	{.bitmap_index = 338915, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捶)*/
	{.bitmap_index = 339035, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(捷)*/
	{.bitmap_index = 339171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捺)*/
	{.bitmap_index = 339299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(捻)*/
	{.bitmap_index = 339427, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掀)*/
	{.bitmap_index = 339563, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掂)*/
	{.bitmap_index = 339691, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掇)*/
	{.bitmap_index = 339811, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(授)*/
	{.bitmap_index = 339939, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掉)*/
	{.bitmap_index = 340059, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掊)*/
	{.bitmap_index = 340187, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(掌)*/
	{.bitmap_index = 340299, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掎)*/
	{.bitmap_index = 340419, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掏)*/
	{.bitmap_index = 340555, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掐)*/
	{.bitmap_index = 340683, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(排)*/
	{.bitmap_index = 340803, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掖)*/
	{.bitmap_index = 340931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掘)*/
	{.bitmap_index = 341051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掠)*/
	{.bitmap_index = 341179, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(探)*/
	{.bitmap_index = 341299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掣)*/
	{.bitmap_index = 341427, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(接)*/
	{.bitmap_index = 341563, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(控)*/
	{.bitmap_index = 341691, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(推)*/
	{.bitmap_index = 341819, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掩)*/
	{.bitmap_index = 341947, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(措)*/
	{.bitmap_index = 342067, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掬)*/
	{.bitmap_index = 342195, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掭)*/
	{.bitmap_index = 342315, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掮)*/
	{.bitmap_index = 342443, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掰)*/
	{.bitmap_index = 342579, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掳)*/
	{.bitmap_index = 342715, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掴)*/
	{.bitmap_index = 342843, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掷)*/
	{.bitmap_index = 342963, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掸)*/
	{.bitmap_index = 343091, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掺)*/
	{.bitmap_index = 343227, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(掼)*/
	{.bitmap_index = 343355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(掾)*/
	{.bitmap_index = 343483, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揄)*/
	{.bitmap_index = 343611, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(揆)*/
	{.bitmap_index = 343739, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揉)*/
	{.bitmap_index = 343859, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(揍)*/
	{.bitmap_index = 343995, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揎)*/
	{.bitmap_index = 344123, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(描)*/
	{.bitmap_index = 344251, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(提)*/
	{.bitmap_index = 344379, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(插)*/
	{.bitmap_index = 344499, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揖)*/
	{.bitmap_index = 344619, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揞)*/
	{.bitmap_index = 344747, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揠)*/
	{.bitmap_index = 344867, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(握)*/
	{.bitmap_index = 344987, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揣)*/
	{.bitmap_index = 345115, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揩)*/
	{.bitmap_index = 345235, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揪)*/
	{.bitmap_index = 345355, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揭)*/
	{.bitmap_index = 345475, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揲)*/
	{.bitmap_index = 345595, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(援)*/
	{.bitmap_index = 345723, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揶)*/
	{.bitmap_index = 345843, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(揸)*/
	{.bitmap_index = 345971, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(揽)*/
	{.bitmap_index = 346107, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(揿)*/
	{.bitmap_index = 346243, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搀)*/
	{.bitmap_index = 346379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搁)*/
	{.bitmap_index = 346507, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搂)*/
	{.bitmap_index = 346643, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搅)*/
	{.bitmap_index = 346771, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搋)*/
	{.bitmap_index = 346891, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搌)*/
	{.bitmap_index = 347019, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搏)*/
	{.bitmap_index = 347147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搐)*/
	{.bitmap_index = 347275, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搓)*/
	{.bitmap_index = 347403, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搔)*/
	{.bitmap_index = 347523, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搛)*/
	{.bitmap_index = 347651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搜)*/
	{.bitmap_index = 347779, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搞)*/
	{.bitmap_index = 347899, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搠)*/
	{.bitmap_index = 348027, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搡)*/
	{.bitmap_index = 348147, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搦)*/
	{.bitmap_index = 348267, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搪)*/
	{.bitmap_index = 348395, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(搬)*/
	{.bitmap_index = 348531, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搭)*/
	{.bitmap_index = 348659, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搴)*/
	{.bitmap_index = 348787, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(携)*/
	{.bitmap_index = 348923, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搽)*/
	{.bitmap_index = 349051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(搿)*/
	{.bitmap_index = 349179, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摁)*/
	{.bitmap_index = 349299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(摄)*/
	{.bitmap_index = 349427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摅)*/
	{.bitmap_index = 349555, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摆)*/
	{.bitmap_index = 349675, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摇)*/
	{.bitmap_index = 349795, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(摈)*/
	{.bitmap_index = 349931, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摊)*/
	{.bitmap_index = 350059, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(摒)*/
	{.bitmap_index = 350187, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摔)*/
	{.bitmap_index = 350315, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摘)*/
	{.bitmap_index = 350443, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摞)*/
	{.bitmap_index = 350563, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摧)*/
	{.bitmap_index = 350683, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(摩)*/
	{.bitmap_index = 350819, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摭)*/
	{.bitmap_index = 350947, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(摸)*/
	{.bitmap_index = 351083, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摹)*/
	{.bitmap_index = 351211, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(摺)*/
	{.bitmap_index = 351331, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撂)*/
	{.bitmap_index = 351451, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撄)*/
	{.bitmap_index = 351579, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撅)*/
	{.bitmap_index = 351707, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撇)*/
	{.bitmap_index = 351835, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撑)*/
	{.bitmap_index = 351963, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撒)*/
	{.bitmap_index = 352091, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撕)*/
	{.bitmap_index = 352219, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撖)*/
	{.bitmap_index = 352339, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撙)*/
	{.bitmap_index = 352467, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撞)*/
	{.bitmap_index = 352587, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撤)*/
	{.bitmap_index = 352723, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撩)*/
	{.bitmap_index = 352851, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撬)*/
	{.bitmap_index = 352979, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(播)*/
	{.bitmap_index = 353107, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撮)*/
	{.bitmap_index = 353227, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撰)*/
	{.bitmap_index = 353355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撵)*/
	{.bitmap_index = 353483, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(撷)*/
	{.bitmap_index = 353611, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撸)*/
	{.bitmap_index = 353739, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撺)*/
	{.bitmap_index = 353867, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(撼)*/
	{.bitmap_index = 353995, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擀)*/
	{.bitmap_index = 354115, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擂)*/
	{.bitmap_index = 354235, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擅)*/
	{.bitmap_index = 354363, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(操)*/
	{.bitmap_index = 354483, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(擎)*/
	{.bitmap_index = 354619, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(擐)*/
	{.bitmap_index = 354755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擒)*/
	{.bitmap_index = 354883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擗)*/
	{.bitmap_index = 355011, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擘)*/
	{.bitmap_index = 355139, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(擞)*/
	{.bitmap_index = 355267, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擢)*/
	{.bitmap_index = 355387, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(擤)*/
	{.bitmap_index = 355523, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(擦)*/
	{.bitmap_index = 355651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(攀)*/
	{.bitmap_index = 355779, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(攉)*/
	{.bitmap_index = 355899, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攒)*/
	{.bitmap_index = 356035, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攘)*/
	{.bitmap_index = 356171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(攥)*/
	{.bitmap_index = 356299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攫)*/
	{.bitmap_index = 356427, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攮)*/
	{.bitmap_index = 356563, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(支)*/
	{.bitmap_index = 356699, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攴)*/
	{.bitmap_index = 356835, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攵)*/
	{.bitmap_index = 356971, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(收)*/
	{.bitmap_index = 357107, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(攸)*/
	{.bitmap_index = 357235, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(改)*/
	{.bitmap_index = 357371, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(攻)*/
	{.bitmap_index = 357507, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(放)*/
	{.bitmap_index = 357643, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(政)*/
	{.bitmap_index = 357779, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(故)*/
	{.bitmap_index = 357915, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(效)*/
	{.bitmap_index = 358051, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敉)*/
	{.bitmap_index = 358187, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敌)*/
	{.bitmap_index = 358323, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敏)*/
	{.bitmap_index = 358459, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(救)*/
	{.bitmap_index = 358595, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敕)*/
	{.bitmap_index = 358731, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敖)*/
	{.bitmap_index = 358867, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(教)*/
	{.bitmap_index = 359003, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敛)*/
	{.bitmap_index = 359139, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敝)*/
	{.bitmap_index = 359275, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敞)*/
	{.bitmap_index = 359411, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敢)*/
	{.bitmap_index = 359539, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(散)*/
	{.bitmap_index = 359675, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敦)*/
	{.bitmap_index = 359811, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敫)*/
	{.bitmap_index = 359947, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敬)*/
	{.bitmap_index = 360083, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(数)*/
	{.bitmap_index = 360219, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敲)*/
	{.bitmap_index = 360355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(整)*/
	{.bitmap_index = 360483, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(敷)*/
	{.bitmap_index = 360619, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(文)*/
	{.bitmap_index = 360755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斋)*/
	{.bitmap_index = 360883, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斌)*/
	{.bitmap_index = 361003, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斐)*/
	{.bitmap_index = 361139, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斑)*/
	{.bitmap_index = 361259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斓)*/
	{.bitmap_index = 361387, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斗)*/
	{.bitmap_index = 361507, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(料)*/
	{.bitmap_index = 361627, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斛)*/
	{.bitmap_index = 361763, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斜)*/
	{.bitmap_index = 361891, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斟)*/
	{.bitmap_index = 362011, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斡)*/
	{.bitmap_index = 362139, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(斤)*/
	{.bitmap_index = 362259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斥)*/
	{.bitmap_index = 362387, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斧)*/
	{.bitmap_index = 362523, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斩)*/
	{.bitmap_index = 362659, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斫)*/
	{.bitmap_index = 362787, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(断)*/
	{.bitmap_index = 362915, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(斯)*/
	{.bitmap_index = 363043, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(新)*/
	{.bitmap_index = 363179, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(方)*/
	{.bitmap_index = 363307, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(於)*/
	{.bitmap_index = 363435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(施)*/
	{.bitmap_index = 363563, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旁)*/
	{.bitmap_index = 363699, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旃)*/
	{.bitmap_index = 363835, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旄)*/
	{.bitmap_index = 363971, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旅)*/
	{.bitmap_index = 364099, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旆)*/
	{.bitmap_index = 364227, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旋)*/
	{.bitmap_index = 364355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旌)*/
	{.bitmap_index = 364483, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旎)*/
	{.bitmap_index = 364611, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(族)*/
	{.bitmap_index = 364747, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旒)*/
	{.bitmap_index = 364883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旖)*/
	{.bitmap_index = 365011, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旗)*/
	{.bitmap_index = 365147, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(无)*/
	{.bitmap_index = 365275, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(既)*/
	{.bitmap_index = 365395, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(日)*/
	{.bitmap_index = 365485, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旦)*/
	{.bitmap_index = 365605, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(旧)*/
	{.bitmap_index = 365710, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(旨)*/
	{.bitmap_index = 365815, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(早)*/
	{.bitmap_index = 365935, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旬)*/
	{.bitmap_index = 366063, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旭)*/
	{.bitmap_index = 366191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旮)*/
	{.bitmap_index = 366319, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(旯)*/
	{.bitmap_index = 366447, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(旰)*/
	{.bitmap_index = 366567, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(旱)*/
	{.bitmap_index = 366687, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(时)*/
	{.bitmap_index = 366807, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(旷)*/
	{.bitmap_index = 366943, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(旺)*/
	{.bitmap_index = 367063, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(昀)*/
	{.bitmap_index = 367175, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(昂)*/
	{.bitmap_index = 367280, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(昃)*/
	{.bitmap_index = 367408, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(昆)*/
	{.bitmap_index = 367528, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(昊)*/
	{.bitmap_index = 367656, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(昌)*/
	{.bitmap_index = 367761, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(明)*/
	{.bitmap_index = 367873, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(昏)*/
	{.bitmap_index = 367993, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(易)*/
	{.bitmap_index = 368121, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(昔)*/
	{.bitmap_index = 368241, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(昕)*/
	{.bitmap_index = 368369, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(昙)*/
	{.bitmap_index = 368474, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(昝)*/
	{.bitmap_index = 368602, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(星)*/
	{.bitmap_index = 368722, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(映)*/
	{.bitmap_index = 368850, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(春)*/
	{.bitmap_index = 368978, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(昧)*/
	{.bitmap_index = 369106, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(昨)*/
	{.bitmap_index = 369234, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(昭)*/
	{.bitmap_index = 369339, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(是)*/
	{.bitmap_index = 369467, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(昱)*/
	{.bitmap_index = 369587, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(昴)*/
	{.bitmap_index = 369699, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(昵)*/
	{.bitmap_index = 369819, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(昶)*/
	{.bitmap_index = 369955, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(昼)*/
	{.bitmap_index = 370075, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(显)*/
	{.bitmap_index = 370195, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(晁)*/
	{.bitmap_index = 370323, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(晃)*/
	{.bitmap_index = 370451, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(晋)*/
	{.bitmap_index = 370571, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(晌)*/
	{.bitmap_index = 370683, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(晏)*/
	{.bitmap_index = 370811, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晒)*/
	{.bitmap_index = 370931, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(晓)*/
	{.bitmap_index = 371067, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晔)*/
	{.bitmap_index = 371195, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(晕)*/
	{.bitmap_index = 371300, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晖)*/
	{.bitmap_index = 371420, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晗)*/
	{.bitmap_index = 371548, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(晚)*/
	{.bitmap_index = 371684, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(晟)*/
	{.bitmap_index = 371812, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晡)*/
	{.bitmap_index = 371940, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晤)*/
	{.bitmap_index = 372060, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晦)*/
	{.bitmap_index = 372188, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(晨)*/
	{.bitmap_index = 372316, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(普)*/
	{.bitmap_index = 372444, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(景)*/
	{.bitmap_index = 372564, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晰)*/
	{.bitmap_index = 372684, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晴)*/
	{.bitmap_index = 372804, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(晶)*/
	{.bitmap_index = 372909, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(晷)*/
	{.bitmap_index = 373029, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(智)*/
	{.bitmap_index = 373157, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(晾)*/
	{.bitmap_index = 373277, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(暂)*/
	{.bitmap_index = 373405, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(暄)*/
	{.bitmap_index = 373533, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(暇)*/
	{.bitmap_index = 373661, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(暌)*/
	{.bitmap_index = 373789, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(暑)*/
	{.bitmap_index = 373909, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(暖)*/
	{.bitmap_index = 374037, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(暗)*/
	{.bitmap_index = 374165, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(暝)*/
	{.bitmap_index = 374293, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(暧)*/
	{.bitmap_index = 374421, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(暨)*/
	{.bitmap_index = 374541, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(暮)*/
	{.bitmap_index = 374669, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(暴)*/
	{.bitmap_index = 374789, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(暹)*/
	{.bitmap_index = 374909, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(暾)*/
	{.bitmap_index = 375045, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(曙)*/
	{.bitmap_index = 375165, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(曛)*/
	{.bitmap_index = 375293, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(曜)*/
	{.bitmap_index = 375413, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(曝)*/
	{.bitmap_index = 375533, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(曦)*/
	{.bitmap_index = 375661, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(曩)*/
	{.bitmap_index = 375789, .adv_w = 15, .box_h = 13, .box_w = 14, .ofs_x = 1, .ofs_y = 5},/*(曰)*/
	{.bitmap_index = 375880, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(曲)*/
	{.bitmap_index = 375985, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(曳)*/
	{.bitmap_index = 376113, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(更)*/
	{.bitmap_index = 376241, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(曷)*/
	{.bitmap_index = 376361, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(曹)*/
	{.bitmap_index = 376473, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(曼)*/
	{.bitmap_index = 376601, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(曾)*/
	{.bitmap_index = 376713, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(替)*/
	{.bitmap_index = 376841, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(最)*/
	{.bitmap_index = 376969, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*(月)*/
	{.bitmap_index = 377081, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(有)*/
	{.bitmap_index = 377209, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朊)*/
	{.bitmap_index = 377329, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朋)*/
	{.bitmap_index = 377449, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(服)*/
	{.bitmap_index = 377577, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(朐)*/
	{.bitmap_index = 377713, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(朔)*/
	{.bitmap_index = 377849, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(朕)*/
	{.bitmap_index = 377985, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朗)*/
	{.bitmap_index = 378113, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(望)*/
	{.bitmap_index = 378241, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(朝)*/
	{.bitmap_index = 378369, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(期)*/
	{.bitmap_index = 378497, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朦)*/
	{.bitmap_index = 378625, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(木)*/
	{.bitmap_index = 378753, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(未)*/
	{.bitmap_index = 378881, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(末)*/
	{.bitmap_index = 379001, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(本)*/
	{.bitmap_index = 379121, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(札)*/
	{.bitmap_index = 379249, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(术)*/
	{.bitmap_index = 379377, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朱)*/
	{.bitmap_index = 379505, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朴)*/
	{.bitmap_index = 379633, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朵)*/
	{.bitmap_index = 379753, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(机)*/
	{.bitmap_index = 379873, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(朽)*/
	{.bitmap_index = 379993, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杀)*/
	{.bitmap_index = 380121, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杂)*/
	{.bitmap_index = 380249, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(权)*/
	{.bitmap_index = 380385, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杆)*/
	{.bitmap_index = 380505, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杈)*/
	{.bitmap_index = 380633, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杉)*/
	{.bitmap_index = 380761, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杌)*/
	{.bitmap_index = 380881, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(李)*/
	{.bitmap_index = 381009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杏)*/
	{.bitmap_index = 381137, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(材)*/
	{.bitmap_index = 381265, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(村)*/
	{.bitmap_index = 381393, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杓)*/
	{.bitmap_index = 381521, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(杖)*/
	{.bitmap_index = 381657, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杜)*/
	{.bitmap_index = 381785, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杞)*/
	{.bitmap_index = 381905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(束)*/
	{.bitmap_index = 382033, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杠)*/
	{.bitmap_index = 382161, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(条)*/
	{.bitmap_index = 382289, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(来)*/
	{.bitmap_index = 382417, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杨)*/
	{.bitmap_index = 382545, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杩)*/
	{.bitmap_index = 382665, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(杪)*/
	{.bitmap_index = 382801, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杭)*/
	{.bitmap_index = 382921, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杯)*/
	{.bitmap_index = 383049, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(杰)*/
	{.bitmap_index = 383185, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杲)*/
	{.bitmap_index = 383305, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杳)*/
	{.bitmap_index = 383433, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杵)*/
	{.bitmap_index = 383561, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杷)*/
	{.bitmap_index = 383681, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(杼)*/
	{.bitmap_index = 383809, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(松)*/
	{.bitmap_index = 383937, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(板)*/
	{.bitmap_index = 384065, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(极)*/
	{.bitmap_index = 384185, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(构)*/
	{.bitmap_index = 384313, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枇)*/
	{.bitmap_index = 384433, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枉)*/
	{.bitmap_index = 384561, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枋)*/
	{.bitmap_index = 384689, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(析)*/
	{.bitmap_index = 384817, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枕)*/
	{.bitmap_index = 384945, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(林)*/
	{.bitmap_index = 385065, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枘)*/
	{.bitmap_index = 385193, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(枚)*/
	{.bitmap_index = 385329, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(果)*/
	{.bitmap_index = 385449, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(枝)*/
	{.bitmap_index = 385585, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枞)*/
	{.bitmap_index = 385705, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枢)*/
	{.bitmap_index = 385825, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(枣)*/
	{.bitmap_index = 385961, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枥)*/
	{.bitmap_index = 386081, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(枧)*/
	{.bitmap_index = 386217, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枨)*/
	{.bitmap_index = 386345, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枪)*/
	{.bitmap_index = 386473, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枫)*/
	{.bitmap_index = 386593, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枭)*/
	{.bitmap_index = 386721, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枯)*/
	{.bitmap_index = 386841, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枰)*/
	{.bitmap_index = 386961, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(枳)*/
	{.bitmap_index = 387089, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枵)*/
	{.bitmap_index = 387209, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(架)*/
	{.bitmap_index = 387337, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枷)*/
	{.bitmap_index = 387457, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(枸)*/
	{.bitmap_index = 387585, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柁)*/
	{.bitmap_index = 387713, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柃)*/
	{.bitmap_index = 387841, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柄)*/
	{.bitmap_index = 387969, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柏)*/
	{.bitmap_index = 388097, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(某)*/
	{.bitmap_index = 388225, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柑)*/
	{.bitmap_index = 388345, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柒)*/
	{.bitmap_index = 388473, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(染)*/
	{.bitmap_index = 388601, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柔)*/
	{.bitmap_index = 388721, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柘)*/
	{.bitmap_index = 388849, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柙)*/
	{.bitmap_index = 388969, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柚)*/
	{.bitmap_index = 389089, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柜)*/
	{.bitmap_index = 389209, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(柝)*/
	{.bitmap_index = 389337, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柞)*/
	{.bitmap_index = 389465, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柠)*/
	{.bitmap_index = 389593, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(柢)*/
	{.bitmap_index = 389729, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(查)*/
	{.bitmap_index = 389857, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柩)*/
	{.bitmap_index = 389977, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柬)*/
	{.bitmap_index = 390105, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柯)*/
	{.bitmap_index = 390225, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柰)*/
	{.bitmap_index = 390353, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柱)*/
	{.bitmap_index = 390481, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(柳)*/
	{.bitmap_index = 390617, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柴)*/
	{.bitmap_index = 390745, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柽)*/
	{.bitmap_index = 390873, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(柿)*/
	{.bitmap_index = 391001, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栀)*/
	{.bitmap_index = 391121, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栅)*/
	{.bitmap_index = 391241, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(标)*/
	{.bitmap_index = 391369, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栈)*/
	{.bitmap_index = 391497, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栉)*/
	{.bitmap_index = 391625, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栊)*/
	{.bitmap_index = 391745, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栋)*/
	{.bitmap_index = 391873, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(栌)*/
	{.bitmap_index = 392009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栎)*/
	{.bitmap_index = 392137, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栏)*/
	{.bitmap_index = 392265, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(树)*/
	{.bitmap_index = 392385, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栓)*/
	{.bitmap_index = 392513, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栖)*/
	{.bitmap_index = 392641, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栗)*/
	{.bitmap_index = 392761, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栝)*/
	{.bitmap_index = 392881, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(校)*/
	{.bitmap_index = 393009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栩)*/
	{.bitmap_index = 393137, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(株)*/
	{.bitmap_index = 393265, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栲)*/
	{.bitmap_index = 393385, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栳)*/
	{.bitmap_index = 393505, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(样)*/
	{.bitmap_index = 393633, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(核)*/
	{.bitmap_index = 393761, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(根)*/
	{.bitmap_index = 393881, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(格)*/
	{.bitmap_index = 394009, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(栽)*/
	{.bitmap_index = 394145, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(栾)*/
	{.bitmap_index = 394273, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桀)*/
	{.bitmap_index = 394401, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桁)*/
	{.bitmap_index = 394529, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桂)*/
	{.bitmap_index = 394649, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桃)*/
	{.bitmap_index = 394777, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桄)*/
	{.bitmap_index = 394905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桅)*/
	{.bitmap_index = 395033, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(框)*/
	{.bitmap_index = 395153, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(案)*/
	{.bitmap_index = 395281, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桉)*/
	{.bitmap_index = 395409, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桊)*/
	{.bitmap_index = 395537, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桌)*/
	{.bitmap_index = 395665, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桎)*/
	{.bitmap_index = 395785, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桐)*/
	{.bitmap_index = 395905, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桑)*/
	{.bitmap_index = 396025, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桓)*/
	{.bitmap_index = 396145, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桔)*/
	{.bitmap_index = 396265, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桕)*/
	{.bitmap_index = 396393, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桠)*/
	{.bitmap_index = 396513, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桡)*/
	{.bitmap_index = 396641, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桢)*/
	{.bitmap_index = 396777, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(档)*/
	{.bitmap_index = 396897, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桤)*/
	{.bitmap_index = 397017, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桥)*/
	{.bitmap_index = 397153, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桦)*/
	{.bitmap_index = 397281, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桧)*/
	{.bitmap_index = 397409, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桨)*/
	{.bitmap_index = 397537, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桩)*/
	{.bitmap_index = 397673, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桫)*/
	{.bitmap_index = 397809, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桴)*/
	{.bitmap_index = 397929, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(桶)*/
	{.bitmap_index = 398049, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(桷)*/
	{.bitmap_index = 398185, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梁)*/
	{.bitmap_index = 398313, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梃)*/
	{.bitmap_index = 398441, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梅)*/
	{.bitmap_index = 398569, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(梆)*/
	{.bitmap_index = 398697, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梏)*/
	{.bitmap_index = 398817, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梓)*/
	{.bitmap_index = 398937, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(梗)*/
	{.bitmap_index = 399065, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梢)*/
	{.bitmap_index = 399193, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(梦)*/
	{.bitmap_index = 399329, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梧)*/
	{.bitmap_index = 399449, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梨)*/
	{.bitmap_index = 399569, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(梭)*/
	{.bitmap_index = 399705, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(梯)*/
	{.bitmap_index = 399833, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(械)*/
	{.bitmap_index = 399961, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(梳)*/
	{.bitmap_index = 400097, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(梵)*/
	{.bitmap_index = 400233, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(检)*/
	{.bitmap_index = 400361, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(棂)*/
	{.bitmap_index = 400497, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棉)*/
	{.bitmap_index = 400625, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(棋)*/
	{.bitmap_index = 400753, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棍)*/
	{.bitmap_index = 400873, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(棒)*/
	{.bitmap_index = 401009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(棕)*/
	{.bitmap_index = 401137, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棘)*/
	{.bitmap_index = 401257, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棚)*/
	{.bitmap_index = 401385, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棠)*/
	{.bitmap_index = 401513, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棣)*/
	{.bitmap_index = 401641, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(森)*/
	{.bitmap_index = 401769, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棰)*/
	{.bitmap_index = 401897, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(棱)*/
	{.bitmap_index = 402033, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棵)*/
	{.bitmap_index = 402153, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棹)*/
	{.bitmap_index = 402273, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(棺)*/
	{.bitmap_index = 402401, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(棼)*/
	{.bitmap_index = 402537, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椁)*/
	{.bitmap_index = 402665, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椅)*/
	{.bitmap_index = 402793, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椋)*/
	{.bitmap_index = 402921, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(植)*/
	{.bitmap_index = 403041, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椎)*/
	{.bitmap_index = 403169, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椐)*/
	{.bitmap_index = 403297, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椒)*/
	{.bitmap_index = 403417, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(椟)*/
	{.bitmap_index = 403553, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椠)*/
	{.bitmap_index = 403681, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(椤)*/
	{.bitmap_index = 403809, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椭)*/
	{.bitmap_index = 403929, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(椰)*/
	{.bitmap_index = 404057, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(椴)*/
	{.bitmap_index = 404185, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椹)*/
	{.bitmap_index = 404305, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椽)*/
	{.bitmap_index = 404433, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(椿)*/
	{.bitmap_index = 404561, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楂)*/
	{.bitmap_index = 404689, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(楔)*/
	{.bitmap_index = 404825, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楗)*/
	{.bitmap_index = 404953, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(楚)*/
	{.bitmap_index = 405089, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楝)*/
	{.bitmap_index = 405217, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(楞)*/
	{.bitmap_index = 405353, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楠)*/
	{.bitmap_index = 405481, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楣)*/
	{.bitmap_index = 405601, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楦)*/
	{.bitmap_index = 405729, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楫)*/
	{.bitmap_index = 405849, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楮)*/
	{.bitmap_index = 405969, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(楱)*/
	{.bitmap_index = 406105, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楷)*/
	{.bitmap_index = 406233, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楸)*/
	{.bitmap_index = 406361, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(楹)*/
	{.bitmap_index = 406489, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(楼)*/
	{.bitmap_index = 406625, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榀)*/
	{.bitmap_index = 406753, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(概)*/
	{.bitmap_index = 406881, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榄)*/
	{.bitmap_index = 407009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榆)*/
	{.bitmap_index = 407137, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(榇)*/
	{.bitmap_index = 407273, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榈)*/
	{.bitmap_index = 407401, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榉)*/
	{.bitmap_index = 407529, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榍)*/
	{.bitmap_index = 407657, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榔)*/
	{.bitmap_index = 407785, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榕)*/
	{.bitmap_index = 407913, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榘)*/
	{.bitmap_index = 408041, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榛)*/
	{.bitmap_index = 408161, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(榜)*/
	{.bitmap_index = 408297, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榧)*/
	{.bitmap_index = 408417, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榨)*/
	{.bitmap_index = 408545, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榫)*/
	{.bitmap_index = 408673, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榭)*/
	{.bitmap_index = 408801, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榱)*/
	{.bitmap_index = 408929, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榴)*/
	{.bitmap_index = 409057, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榷)*/
	{.bitmap_index = 409185, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(榻)*/
	{.bitmap_index = 409305, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槁)*/
	{.bitmap_index = 409433, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槊)*/
	{.bitmap_index = 409561, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槌)*/
	{.bitmap_index = 409689, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槎)*/
	{.bitmap_index = 409817, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(槐)*/
	{.bitmap_index = 409953, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槔)*/
	{.bitmap_index = 410081, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槛)*/
	{.bitmap_index = 410201, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(槟)*/
	{.bitmap_index = 410337, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槠)*/
	{.bitmap_index = 410457, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槭)*/
	{.bitmap_index = 410585, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槲)*/
	{.bitmap_index = 410713, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槽)*/
	{.bitmap_index = 410833, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(槿)*/
	{.bitmap_index = 410961, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(樊)*/
	{.bitmap_index = 411089, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樗)*/
	{.bitmap_index = 411209, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樘)*/
	{.bitmap_index = 411337, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樟)*/
	{.bitmap_index = 411465, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(模)*/
	{.bitmap_index = 411601, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樨)*/
	{.bitmap_index = 411721, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(横)*/
	{.bitmap_index = 411857, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樯)*/
	{.bitmap_index = 411977, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(樱)*/
	{.bitmap_index = 412105, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樵)*/
	{.bitmap_index = 412233, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樽)*/
	{.bitmap_index = 412361, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(樾)*/
	{.bitmap_index = 412489, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橄)*/
	{.bitmap_index = 412609, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橇)*/
	{.bitmap_index = 412737, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橐)*/
	{.bitmap_index = 412865, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橘)*/
	{.bitmap_index = 412985, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橙)*/
	{.bitmap_index = 413113, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(橛)*/
	{.bitmap_index = 413241, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橡)*/
	{.bitmap_index = 413369, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橥)*/
	{.bitmap_index = 413497, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橱)*/
	{.bitmap_index = 413617, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橹)*/
	{.bitmap_index = 413745, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(橼)*/
	{.bitmap_index = 413873, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檀)*/
	{.bitmap_index = 414001, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(檄)*/
	{.bitmap_index = 414137, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檎)*/
	{.bitmap_index = 414265, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檐)*/
	{.bitmap_index = 414393, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檑)*/
	{.bitmap_index = 414521, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檗)*/
	{.bitmap_index = 414649, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檠)*/
	{.bitmap_index = 414777, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檩)*/
	{.bitmap_index = 414905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(檫)*/
	{.bitmap_index = 415033, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(檬)*/
	{.bitmap_index = 415169, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欠)*/
	{.bitmap_index = 415305, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(次)*/
	{.bitmap_index = 415441, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欢)*/
	{.bitmap_index = 415577, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欣)*/
	{.bitmap_index = 415713, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欤)*/
	{.bitmap_index = 415849, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(欧)*/
	{.bitmap_index = 415985, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欲)*/
	{.bitmap_index = 416121, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(欷)*/
	{.bitmap_index = 416249, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欹)*/
	{.bitmap_index = 416385, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(欺)*/
	{.bitmap_index = 416521, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(款)*/
	{.bitmap_index = 416657, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(歃)*/
	{.bitmap_index = 416785, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(歆)*/
	{.bitmap_index = 416921, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(歇)*/
	{.bitmap_index = 417049, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(歉)*/
	{.bitmap_index = 417185, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(歌)*/
	{.bitmap_index = 417313, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(歙)*/
	{.bitmap_index = 417441, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(止)*/
	{.bitmap_index = 417569, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(正)*/
	{.bitmap_index = 417689, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(此)*/
	{.bitmap_index = 417809, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(步)*/
	{.bitmap_index = 417937, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(武)*/
	{.bitmap_index = 418057, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(歧)*/
	{.bitmap_index = 418193, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(歪)*/
	{.bitmap_index = 418313, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(歹)*/
	{.bitmap_index = 418441, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(死)*/
	{.bitmap_index = 418569, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(歼)*/
	{.bitmap_index = 418697, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殁)*/
	{.bitmap_index = 418825, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(殂)*/
	{.bitmap_index = 418945, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殃)*/
	{.bitmap_index = 419073, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殄)*/
	{.bitmap_index = 419209, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殆)*/
	{.bitmap_index = 419345, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殇)*/
	{.bitmap_index = 419481, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殉)*/
	{.bitmap_index = 419617, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(殊)*/
	{.bitmap_index = 419745, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(残)*/
	{.bitmap_index = 419881, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殍)*/
	{.bitmap_index = 420009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殒)*/
	{.bitmap_index = 420137, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(殓)*/
	{.bitmap_index = 420265, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(殖)*/
	{.bitmap_index = 420385, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(殚)*/
	{.bitmap_index = 420513, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殛)*/
	{.bitmap_index = 420641, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殡)*/
	{.bitmap_index = 420777, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殪)*/
	{.bitmap_index = 420913, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殳)*/
	{.bitmap_index = 421041, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(殴)*/
	{.bitmap_index = 421169, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(段)*/
	{.bitmap_index = 421297, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(殷)*/
	{.bitmap_index = 421425, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(殿)*/
	{.bitmap_index = 421545, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毁)*/
	{.bitmap_index = 421673, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毂)*/
	{.bitmap_index = 421801, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(毅)*/
	{.bitmap_index = 421937, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(毋)*/
	{.bitmap_index = 422065, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(母)*/
	{.bitmap_index = 422185, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(每)*/
	{.bitmap_index = 422313, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(毒)*/
	{.bitmap_index = 422441, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(毓)*/
	{.bitmap_index = 422569, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(比)*/
	{.bitmap_index = 422689, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毕)*/
	{.bitmap_index = 422809, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毖)*/
	{.bitmap_index = 422937, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(毗)*/
	{.bitmap_index = 423057, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毙)*/
	{.bitmap_index = 423185, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毛)*/
	{.bitmap_index = 423305, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毡)*/
	{.bitmap_index = 423425, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毪)*/
	{.bitmap_index = 423553, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毫)*/
	{.bitmap_index = 423681, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毯)*/
	{.bitmap_index = 423801, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毳)*/
	{.bitmap_index = 423921, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(毵)*/
	{.bitmap_index = 424057, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毹)*/
	{.bitmap_index = 424185, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(毽)*/
	{.bitmap_index = 424305, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氅)*/
	{.bitmap_index = 424433, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氆)*/
	{.bitmap_index = 424561, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氇)*/
	{.bitmap_index = 424689, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氍)*/
	{.bitmap_index = 424809, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(氏)*/
	{.bitmap_index = 424929, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(氐)*/
	{.bitmap_index = 425057, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(民)*/
	{.bitmap_index = 425185, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氓)*/
	{.bitmap_index = 425313, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(气)*/
	{.bitmap_index = 425449, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氕)*/
	{.bitmap_index = 425585, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氖)*/
	{.bitmap_index = 425721, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氘)*/
	{.bitmap_index = 425857, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氙)*/
	{.bitmap_index = 425993, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氚)*/
	{.bitmap_index = 426129, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氛)*/
	{.bitmap_index = 426265, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氟)*/
	{.bitmap_index = 426401, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氡)*/
	{.bitmap_index = 426537, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氢)*/
	{.bitmap_index = 426673, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氤)*/
	{.bitmap_index = 426801, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氦)*/
	{.bitmap_index = 426937, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氧)*/
	{.bitmap_index = 427073, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氨)*/
	{.bitmap_index = 427209, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氩)*/
	{.bitmap_index = 427337, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氪)*/
	{.bitmap_index = 427473, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氮)*/
	{.bitmap_index = 427609, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氯)*/
	{.bitmap_index = 427737, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氰)*/
	{.bitmap_index = 427873, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(氲)*/
	{.bitmap_index = 428009, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(水)*/
	{.bitmap_index = 428129, .adv_w = 7, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = 4},/*(氵)*/
	{.bitmap_index = 428174, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(永)*/
	{.bitmap_index = 428310, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(氽)*/
	{.bitmap_index = 428438, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汀)*/
	{.bitmap_index = 428566, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汁)*/
	{.bitmap_index = 428694, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(求)*/
	{.bitmap_index = 428822, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汆)*/
	{.bitmap_index = 428950, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汇)*/
	{.bitmap_index = 429078, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汉)*/
	{.bitmap_index = 429206, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汊)*/
	{.bitmap_index = 429334, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汐)*/
	{.bitmap_index = 429470, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汔)*/
	{.bitmap_index = 429598, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汕)*/
	{.bitmap_index = 429726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汗)*/
	{.bitmap_index = 429846, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汛)*/
	{.bitmap_index = 429966, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汜)*/
	{.bitmap_index = 430086, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汝)*/
	{.bitmap_index = 430222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汞)*/
	{.bitmap_index = 430350, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(江)*/
	{.bitmap_index = 430470, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(池)*/
	{.bitmap_index = 430590, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(污)*/
	{.bitmap_index = 430710, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汤)*/
	{.bitmap_index = 430838, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汨)*/
	{.bitmap_index = 430958, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汩)*/
	{.bitmap_index = 431078, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汪)*/
	{.bitmap_index = 431198, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汰)*/
	{.bitmap_index = 431326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汲)*/
	{.bitmap_index = 431454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汴)*/
	{.bitmap_index = 431582, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汶)*/
	{.bitmap_index = 431710, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(汹)*/
	{.bitmap_index = 431830, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汽)*/
	{.bitmap_index = 431966, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(汾)*/
	{.bitmap_index = 432102, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沁)*/
	{.bitmap_index = 432222, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沂)*/
	{.bitmap_index = 432358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沃)*/
	{.bitmap_index = 432486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沅)*/
	{.bitmap_index = 432614, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沆)*/
	{.bitmap_index = 432734, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沈)*/
	{.bitmap_index = 432862, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沉)*/
	{.bitmap_index = 432990, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沌)*/
	{.bitmap_index = 433118, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沏)*/
	{.bitmap_index = 433254, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沐)*/
	{.bitmap_index = 433382, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沓)*/
	{.bitmap_index = 433510, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沔)*/
	{.bitmap_index = 433630, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沙)*/
	{.bitmap_index = 433766, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沛)*/
	{.bitmap_index = 433886, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沟)*/
	{.bitmap_index = 434014, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(没)*/
	{.bitmap_index = 434142, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沣)*/
	{.bitmap_index = 434270, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沤)*/
	{.bitmap_index = 434390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沥)*/
	{.bitmap_index = 434518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沦)*/
	{.bitmap_index = 434646, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沧)*/
	{.bitmap_index = 434774, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(沩)*/
	{.bitmap_index = 434894, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沪)*/
	{.bitmap_index = 435030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沫)*/
	{.bitmap_index = 435158, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沭)*/
	{.bitmap_index = 435286, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沮)*/
	{.bitmap_index = 435406, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沱)*/
	{.bitmap_index = 435534, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沲)*/
	{.bitmap_index = 435662, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(河)*/
	{.bitmap_index = 435782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(沸)*/
	{.bitmap_index = 435910, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(油)*/
	{.bitmap_index = 436030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(治)*/
	{.bitmap_index = 436158, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沼)*/
	{.bitmap_index = 436278, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沽)*/
	{.bitmap_index = 436398, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沾)*/
	{.bitmap_index = 436518, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(沿)*/
	{.bitmap_index = 436638, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泄)*/
	{.bitmap_index = 436758, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泅)*/
	{.bitmap_index = 436878, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泉)*/
	{.bitmap_index = 437006, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泊)*/
	{.bitmap_index = 437134, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泌)*/
	{.bitmap_index = 437262, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泐)*/
	{.bitmap_index = 437390, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泓)*/
	{.bitmap_index = 437510, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泔)*/
	{.bitmap_index = 437630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(法)*/
	{.bitmap_index = 437758, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泖)*/
	{.bitmap_index = 437894, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泗)*/
	{.bitmap_index = 438014, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泛)*/
	{.bitmap_index = 438134, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泞)*/
	{.bitmap_index = 438262, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泠)*/
	{.bitmap_index = 438398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泡)*/
	{.bitmap_index = 438526, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(波)*/
	{.bitmap_index = 438662, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泣)*/
	{.bitmap_index = 438782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泥)*/
	{.bitmap_index = 438910, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(注)*/
	{.bitmap_index = 439038, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泪)*/
	{.bitmap_index = 439158, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泫)*/
	{.bitmap_index = 439278, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泮)*/
	{.bitmap_index = 439406, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泯)*/
	{.bitmap_index = 439534, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泰)*/
	{.bitmap_index = 439662, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泱)*/
	{.bitmap_index = 439790, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泳)*/
	{.bitmap_index = 439918, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泵)*/
	{.bitmap_index = 440046, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泶)*/
	{.bitmap_index = 440174, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泷)*/
	{.bitmap_index = 440294, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泸)*/
	{.bitmap_index = 440422, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泺)*/
	{.bitmap_index = 440542, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泻)*/
	{.bitmap_index = 440662, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(泼)*/
	{.bitmap_index = 440798, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泽)*/
	{.bitmap_index = 440918, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(泾)*/
	{.bitmap_index = 441038, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洁)*/
	{.bitmap_index = 441158, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洄)*/
	{.bitmap_index = 441278, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洇)*/
	{.bitmap_index = 441398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洋)*/
	{.bitmap_index = 441526, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(洌)*/
	{.bitmap_index = 441654, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洎)*/
	{.bitmap_index = 441782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洒)*/
	{.bitmap_index = 441910, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(洗)*/
	{.bitmap_index = 442038, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洙)*/
	{.bitmap_index = 442166, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洚)*/
	{.bitmap_index = 442294, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洛)*/
	{.bitmap_index = 442422, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洞)*/
	{.bitmap_index = 442542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(津)*/
	{.bitmap_index = 442670, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洧)*/
	{.bitmap_index = 442798, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洪)*/
	{.bitmap_index = 442918, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洫)*/
	{.bitmap_index = 443046, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洮)*/
	{.bitmap_index = 443166, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洱)*/
	{.bitmap_index = 443286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(洲)*/
	{.bitmap_index = 443414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(洳)*/
	{.bitmap_index = 443542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洵)*/
	{.bitmap_index = 443670, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洹)*/
	{.bitmap_index = 443790, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(活)*/
	{.bitmap_index = 443910, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洼)*/
	{.bitmap_index = 444030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(洽)*/
	{.bitmap_index = 444158, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(派)*/
	{.bitmap_index = 444286, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(流)*/
	{.bitmap_index = 444422, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浃)*/
	{.bitmap_index = 444558, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浅)*/
	{.bitmap_index = 444686, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浆)*/
	{.bitmap_index = 444822, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浇)*/
	{.bitmap_index = 444958, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浈)*/
	{.bitmap_index = 445094, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浊)*/
	{.bitmap_index = 445222, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(测)*/
	{.bitmap_index = 445342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浍)*/
	{.bitmap_index = 445470, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(济)*/
	{.bitmap_index = 445606, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浏)*/
	{.bitmap_index = 445726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浑)*/
	{.bitmap_index = 445846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浒)*/
	{.bitmap_index = 445974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浓)*/
	{.bitmap_index = 446102, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浔)*/
	{.bitmap_index = 446222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浙)*/
	{.bitmap_index = 446350, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浚)*/
	{.bitmap_index = 446486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浜)*/
	{.bitmap_index = 446614, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浞)*/
	{.bitmap_index = 446742, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浠)*/
	{.bitmap_index = 446870, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浣)*/
	{.bitmap_index = 447006, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浦)*/
	{.bitmap_index = 447134, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浩)*/
	{.bitmap_index = 447254, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浪)*/
	{.bitmap_index = 447390, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浮)*/
	{.bitmap_index = 447510, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浯)*/
	{.bitmap_index = 447630, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(浴)*/
	{.bitmap_index = 447750, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(海)*/
	{.bitmap_index = 447878, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浸)*/
	{.bitmap_index = 448006, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(浼)*/
	{.bitmap_index = 448142, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涂)*/
	{.bitmap_index = 448270, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涅)*/
	{.bitmap_index = 448390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(消)*/
	{.bitmap_index = 448518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(涉)*/
	{.bitmap_index = 448646, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涌)*/
	{.bitmap_index = 448766, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涎)*/
	{.bitmap_index = 448886, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涑)*/
	{.bitmap_index = 449014, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涓)*/
	{.bitmap_index = 449134, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(涔)*/
	{.bitmap_index = 449262, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涕)*/
	{.bitmap_index = 449390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涛)*/
	{.bitmap_index = 449518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(涝)*/
	{.bitmap_index = 449646, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涞)*/
	{.bitmap_index = 449774, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涟)*/
	{.bitmap_index = 449902, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涠)*/
	{.bitmap_index = 450022, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涡)*/
	{.bitmap_index = 450142, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(涣)*/
	{.bitmap_index = 450278, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涤)*/
	{.bitmap_index = 450406, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(润)*/
	{.bitmap_index = 450534, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涧)*/
	{.bitmap_index = 450662, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涨)*/
	{.bitmap_index = 450782, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涩)*/
	{.bitmap_index = 450902, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涪)*/
	{.bitmap_index = 451030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涫)*/
	{.bitmap_index = 451158, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涮)*/
	{.bitmap_index = 451278, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涯)*/
	{.bitmap_index = 451398, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(液)*/
	{.bitmap_index = 451534, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涵)*/
	{.bitmap_index = 451654, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涸)*/
	{.bitmap_index = 451774, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(涿)*/
	{.bitmap_index = 451894, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淀)*/
	{.bitmap_index = 452022, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淄)*/
	{.bitmap_index = 452150, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淅)*/
	{.bitmap_index = 452278, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淆)*/
	{.bitmap_index = 452406, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淇)*/
	{.bitmap_index = 452534, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淋)*/
	{.bitmap_index = 452654, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淌)*/
	{.bitmap_index = 452774, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淑)*/
	{.bitmap_index = 452902, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淖)*/
	{.bitmap_index = 453022, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淘)*/
	{.bitmap_index = 453150, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淙)*/
	{.bitmap_index = 453286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淝)*/
	{.bitmap_index = 453414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淞)*/
	{.bitmap_index = 453542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淠)*/
	{.bitmap_index = 453670, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(淡)*/
	{.bitmap_index = 453806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淤)*/
	{.bitmap_index = 453934, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淦)*/
	{.bitmap_index = 454062, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淫)*/
	{.bitmap_index = 454182, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淬)*/
	{.bitmap_index = 454310, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淮)*/
	{.bitmap_index = 454438, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(深)*/
	{.bitmap_index = 454558, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淳)*/
	{.bitmap_index = 454678, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(混)*/
	{.bitmap_index = 454798, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淹)*/
	{.bitmap_index = 454926, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(添)*/
	{.bitmap_index = 455046, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(淼)*/
	{.bitmap_index = 455174, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(清)*/
	{.bitmap_index = 455294, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渊)*/
	{.bitmap_index = 455422, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渌)*/
	{.bitmap_index = 455542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渍)*/
	{.bitmap_index = 455670, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渎)*/
	{.bitmap_index = 455806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渐)*/
	{.bitmap_index = 455934, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渑)*/
	{.bitmap_index = 456054, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渔)*/
	{.bitmap_index = 456182, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渖)*/
	{.bitmap_index = 456310, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渗)*/
	{.bitmap_index = 456446, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渚)*/
	{.bitmap_index = 456566, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渝)*/
	{.bitmap_index = 456694, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渠)*/
	{.bitmap_index = 456822, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渡)*/
	{.bitmap_index = 456958, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渣)*/
	{.bitmap_index = 457086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渤)*/
	{.bitmap_index = 457214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渥)*/
	{.bitmap_index = 457342, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(温)*/
	{.bitmap_index = 457462, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渫)*/
	{.bitmap_index = 457582, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渭)*/
	{.bitmap_index = 457702, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(港)*/
	{.bitmap_index = 457830, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渲)*/
	{.bitmap_index = 457958, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(渴)*/
	{.bitmap_index = 458078, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(游)*/
	{.bitmap_index = 458214, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(渺)*/
	{.bitmap_index = 458350, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(湃)*/
	{.bitmap_index = 458478, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湄)*/
	{.bitmap_index = 458598, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湍)*/
	{.bitmap_index = 458726, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湎)*/
	{.bitmap_index = 458846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湓)*/
	{.bitmap_index = 458974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湔)*/
	{.bitmap_index = 459102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(湖)*/
	{.bitmap_index = 459230, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湘)*/
	{.bitmap_index = 459350, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湛)*/
	{.bitmap_index = 459470, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湟)*/
	{.bitmap_index = 459598, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湫)*/
	{.bitmap_index = 459718, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湮)*/
	{.bitmap_index = 459838, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(湾)*/
	{.bitmap_index = 459966, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(湿)*/
	{.bitmap_index = 460086, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溃)*/
	{.bitmap_index = 460222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溅)*/
	{.bitmap_index = 460350, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溆)*/
	{.bitmap_index = 460486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溉)*/
	{.bitmap_index = 460614, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溏)*/
	{.bitmap_index = 460742, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(源)*/
	{.bitmap_index = 460870, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溘)*/
	{.bitmap_index = 460998, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溜)*/
	{.bitmap_index = 461126, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溟)*/
	{.bitmap_index = 461254, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溢)*/
	{.bitmap_index = 461382, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溥)*/
	{.bitmap_index = 461510, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溧)*/
	{.bitmap_index = 461630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溪)*/
	{.bitmap_index = 461758, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溯)*/
	{.bitmap_index = 461894, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溱)*/
	{.bitmap_index = 462014, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溲)*/
	{.bitmap_index = 462142, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(溴)*/
	{.bitmap_index = 462278, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溶)*/
	{.bitmap_index = 462406, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溷)*/
	{.bitmap_index = 462526, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溺)*/
	{.bitmap_index = 462646, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溻)*/
	{.bitmap_index = 462766, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(溽)*/
	{.bitmap_index = 462886, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滁)*/
	{.bitmap_index = 463006, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滂)*/
	{.bitmap_index = 463142, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滇)*/
	{.bitmap_index = 463270, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滋)*/
	{.bitmap_index = 463398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滏)*/
	{.bitmap_index = 463526, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滑)*/
	{.bitmap_index = 463646, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滓)*/
	{.bitmap_index = 463774, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滔)*/
	{.bitmap_index = 463902, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滕)*/
	{.bitmap_index = 464038, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滗)*/
	{.bitmap_index = 464166, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滚)*/
	{.bitmap_index = 464302, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滞)*/
	{.bitmap_index = 464422, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滟)*/
	{.bitmap_index = 464550, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滠)*/
	{.bitmap_index = 464678, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(满)*/
	{.bitmap_index = 464806, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滢)*/
	{.bitmap_index = 464926, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滤)*/
	{.bitmap_index = 465054, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滥)*/
	{.bitmap_index = 465174, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滦)*/
	{.bitmap_index = 465310, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(滨)*/
	{.bitmap_index = 465446, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滩)*/
	{.bitmap_index = 465574, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滴)*/
	{.bitmap_index = 465702, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(滹)*/
	{.bitmap_index = 465830, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漂)*/
	{.bitmap_index = 465950, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漆)*/
	{.bitmap_index = 466078, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漉)*/
	{.bitmap_index = 466206, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漏)*/
	{.bitmap_index = 466326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漓)*/
	{.bitmap_index = 466454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(演)*/
	{.bitmap_index = 466582, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漕)*/
	{.bitmap_index = 466702, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(漠)*/
	{.bitmap_index = 466838, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漤)*/
	{.bitmap_index = 466966, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(漩)*/
	{.bitmap_index = 467094, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漪)*/
	{.bitmap_index = 467214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(漫)*/
	{.bitmap_index = 467342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(漭)*/
	{.bitmap_index = 467470, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漯)*/
	{.bitmap_index = 467590, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(漱)*/
	{.bitmap_index = 467726, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(漳)*/
	{.bitmap_index = 467854, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漶)*/
	{.bitmap_index = 467982, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(漾)*/
	{.bitmap_index = 468110, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潆)*/
	{.bitmap_index = 468238, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(潇)*/
	{.bitmap_index = 468374, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潋)*/
	{.bitmap_index = 468502, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潍)*/
	{.bitmap_index = 468630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潘)*/
	{.bitmap_index = 468758, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潜)*/
	{.bitmap_index = 468886, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潞)*/
	{.bitmap_index = 469014, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(潢)*/
	{.bitmap_index = 469142, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潦)*/
	{.bitmap_index = 469270, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潭)*/
	{.bitmap_index = 469390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(潮)*/
	{.bitmap_index = 469518, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潲)*/
	{.bitmap_index = 469638, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潴)*/
	{.bitmap_index = 469758, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潸)*/
	{.bitmap_index = 469878, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潺)*/
	{.bitmap_index = 469998, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(潼)*/
	{.bitmap_index = 470126, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澄)*/
	{.bitmap_index = 470246, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(澈)*/
	{.bitmap_index = 470382, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澉)*/
	{.bitmap_index = 470502, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(澌)*/
	{.bitmap_index = 470630, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澍)*/
	{.bitmap_index = 470750, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澎)*/
	{.bitmap_index = 470870, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澜)*/
	{.bitmap_index = 470998, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澡)*/
	{.bitmap_index = 471118, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澧)*/
	{.bitmap_index = 471246, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(澳)*/
	{.bitmap_index = 471382, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澶)*/
	{.bitmap_index = 471510, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(澹)*/
	{.bitmap_index = 471638, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(激)*/
	{.bitmap_index = 471774, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濂)*/
	{.bitmap_index = 471902, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濉)*/
	{.bitmap_index = 472030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濑)*/
	{.bitmap_index = 472158, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濒)*/
	{.bitmap_index = 472278, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(濞)*/
	{.bitmap_index = 472414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濠)*/
	{.bitmap_index = 472542, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濡)*/
	{.bitmap_index = 472662, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濮)*/
	{.bitmap_index = 472790, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(濯)*/
	{.bitmap_index = 472910, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瀑)*/
	{.bitmap_index = 473030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瀚)*/
	{.bitmap_index = 473158, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瀛)*/
	{.bitmap_index = 473294, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瀣)*/
	{.bitmap_index = 473414, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瀵)*/
	{.bitmap_index = 473550, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瀹)*/
	{.bitmap_index = 473678, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灌)*/
	{.bitmap_index = 473806, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灏)*/
	{.bitmap_index = 473926, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(灞)*/
	{.bitmap_index = 474054, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(火)*/
	{.bitmap_index = 474182, .adv_w = 16, .box_h = 7, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灬)*/
	{.bitmap_index = 474238, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(灭)*/
	{.bitmap_index = 474366, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灯)*/
	{.bitmap_index = 474494, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灰)*/
	{.bitmap_index = 474622, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(灵)*/
	{.bitmap_index = 474750, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灶)*/
	{.bitmap_index = 474878, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(灸)*/
	{.bitmap_index = 475014, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灼)*/
	{.bitmap_index = 475142, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(灾)*/
	{.bitmap_index = 475270, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(灿)*/
	{.bitmap_index = 475390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炀)*/
	{.bitmap_index = 475518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炅)*/
	{.bitmap_index = 475646, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炉)*/
	{.bitmap_index = 475782, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炊)*/
	{.bitmap_index = 475918, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炎)*/
	{.bitmap_index = 476046, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炒)*/
	{.bitmap_index = 476182, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炔)*/
	{.bitmap_index = 476310, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炕)*/
	{.bitmap_index = 476438, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炖)*/
	{.bitmap_index = 476558, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炙)*/
	{.bitmap_index = 476694, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炜)*/
	{.bitmap_index = 476830, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炝)*/
	{.bitmap_index = 476958, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炫)*/
	{.bitmap_index = 477086, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炬)*/
	{.bitmap_index = 477206, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炭)*/
	{.bitmap_index = 477342, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炮)*/
	{.bitmap_index = 477478, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炯)*/
	{.bitmap_index = 477598, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炱)*/
	{.bitmap_index = 477734, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炳)*/
	{.bitmap_index = 477854, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炷)*/
	{.bitmap_index = 477982, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炸)*/
	{.bitmap_index = 478110, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(点)*/
	{.bitmap_index = 478238, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炻)*/
	{.bitmap_index = 478366, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(炼)*/
	{.bitmap_index = 478494, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(炽)*/
	{.bitmap_index = 478622, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烀)*/
	{.bitmap_index = 478742, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烁)*/
	{.bitmap_index = 478862, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烂)*/
	{.bitmap_index = 478990, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烃)*/
	{.bitmap_index = 479118, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烈)*/
	{.bitmap_index = 479246, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烊)*/
	{.bitmap_index = 479374, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烘)*/
	{.bitmap_index = 479502, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烙)*/
	{.bitmap_index = 479630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烛)*/
	{.bitmap_index = 479758, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烟)*/
	{.bitmap_index = 479878, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烤)*/
	{.bitmap_index = 479998, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烦)*/
	{.bitmap_index = 480134, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烧)*/
	{.bitmap_index = 480270, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烨)*/
	{.bitmap_index = 480398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烩)*/
	{.bitmap_index = 480526, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烫)*/
	{.bitmap_index = 480662, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烬)*/
	{.bitmap_index = 480790, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(热)*/
	{.bitmap_index = 480918, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烯)*/
	{.bitmap_index = 481054, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烷)*/
	{.bitmap_index = 481182, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(烹)*/
	{.bitmap_index = 481318, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(烽)*/
	{.bitmap_index = 481446, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(焉)*/
	{.bitmap_index = 481566, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焊)*/
	{.bitmap_index = 481694, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焐)*/
	{.bitmap_index = 481822, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焓)*/
	{.bitmap_index = 481958, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焕)*/
	{.bitmap_index = 482094, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(焖)*/
	{.bitmap_index = 482222, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焘)*/
	{.bitmap_index = 482358, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焙)*/
	{.bitmap_index = 482494, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焚)*/
	{.bitmap_index = 482630, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焦)*/
	{.bitmap_index = 482766, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焯)*/
	{.bitmap_index = 482894, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(焰)*/
	{.bitmap_index = 483022, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(焱)*/
	{.bitmap_index = 483158, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(然)*/
	{.bitmap_index = 483286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煅)*/
	{.bitmap_index = 483414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煊)*/
	{.bitmap_index = 483542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煌)*/
	{.bitmap_index = 483670, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煎)*/
	{.bitmap_index = 483806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煜)*/
	{.bitmap_index = 483934, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煞)*/
	{.bitmap_index = 484070, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煤)*/
	{.bitmap_index = 484190, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煦)*/
	{.bitmap_index = 484326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(照)*/
	{.bitmap_index = 484454, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煨)*/
	{.bitmap_index = 484574, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煮)*/
	{.bitmap_index = 484710, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煲)*/
	{.bitmap_index = 484846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(煳)*/
	{.bitmap_index = 484974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煸)*/
	{.bitmap_index = 485102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煺)*/
	{.bitmap_index = 485230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(煽)*/
	{.bitmap_index = 485358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(熄)*/
	{.bitmap_index = 485486, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熊)*/
	{.bitmap_index = 485622, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熏)*/
	{.bitmap_index = 485750, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熔)*/
	{.bitmap_index = 485886, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(熘)*/
	{.bitmap_index = 486014, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(熙)*/
	{.bitmap_index = 486134, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熟)*/
	{.bitmap_index = 486270, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(熠)*/
	{.bitmap_index = 486390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熨)*/
	{.bitmap_index = 486518, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熬)*/
	{.bitmap_index = 486654, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熳)*/
	{.bitmap_index = 486782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(熵)*/
	{.bitmap_index = 486910, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(熹)*/
	{.bitmap_index = 487038, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(燃)*/
	{.bitmap_index = 487158, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(燎)*/
	{.bitmap_index = 487286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(燔)*/
	{.bitmap_index = 487414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(燕)*/
	{.bitmap_index = 487542, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(燠)*/
	{.bitmap_index = 487678, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(燥)*/
	{.bitmap_index = 487798, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(燧)*/
	{.bitmap_index = 487926, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(燮)*/
	{.bitmap_index = 488054, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(燹)*/
	{.bitmap_index = 488182, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(爆)*/
	{.bitmap_index = 488302, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(爝)*/
	{.bitmap_index = 488422, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(爨)*/
	{.bitmap_index = 488558, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(爪)*/
	{.bitmap_index = 488678, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(爬)*/
	{.bitmap_index = 488806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(爰)*/
	{.bitmap_index = 488934, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(爱)*/
	{.bitmap_index = 489070, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(爵)*/
	{.bitmap_index = 489198, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(父)*/
	{.bitmap_index = 489326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(爷)*/
	{.bitmap_index = 489454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(爸)*/
	{.bitmap_index = 489582, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(爹)*/
	{.bitmap_index = 489718, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(爻)*/
	{.bitmap_index = 489854, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(爽)*/
	{.bitmap_index = 489990, .adv_w = 13, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = 3},/*(爿)*/
	{.bitmap_index = 490092, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(片)*/
	{.bitmap_index = 490220, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(版)*/
	{.bitmap_index = 490348, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(牌)*/
	{.bitmap_index = 490484, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(牍)*/
	{.bitmap_index = 490620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牒)*/
	{.bitmap_index = 490748, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牖)*/
	{.bitmap_index = 490876, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牙)*/
	{.bitmap_index = 490996, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牛)*/
	{.bitmap_index = 491116, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牝)*/
	{.bitmap_index = 491244, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牟)*/
	{.bitmap_index = 491372, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牡)*/
	{.bitmap_index = 491500, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(牢)*/
	{.bitmap_index = 491628, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牦)*/
	{.bitmap_index = 491748, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(牧)*/
	{.bitmap_index = 491884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(物)*/
	{.bitmap_index = 492012, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牮)*/
	{.bitmap_index = 492140, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牯)*/
	{.bitmap_index = 492260, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牲)*/
	{.bitmap_index = 492380, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牵)*/
	{.bitmap_index = 492500, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(特)*/
	{.bitmap_index = 492620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牺)*/
	{.bitmap_index = 492748, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牾)*/
	{.bitmap_index = 492876, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(牿)*/
	{.bitmap_index = 492996, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犀)*/
	{.bitmap_index = 493124, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犁)*/
	{.bitmap_index = 493244, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犄)*/
	{.bitmap_index = 493364, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犊)*/
	{.bitmap_index = 493500, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犋)*/
	{.bitmap_index = 493628, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犍)*/
	{.bitmap_index = 493756, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犏)*/
	{.bitmap_index = 493884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犒)*/
	{.bitmap_index = 494012, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犟)*/
	{.bitmap_index = 494132, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犬)*/
	{.bitmap_index = 494260, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(犭)*/
	{.bitmap_index = 494340, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犯)*/
	{.bitmap_index = 494460, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犰)*/
	{.bitmap_index = 494588, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犴)*/
	{.bitmap_index = 494708, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(状)*/
	{.bitmap_index = 494836, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犷)*/
	{.bitmap_index = 494972, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(犸)*/
	{.bitmap_index = 495092, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(犹)*/
	{.bitmap_index = 495228, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狁)*/
	{.bitmap_index = 495356, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狂)*/
	{.bitmap_index = 495476, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狃)*/
	{.bitmap_index = 495596, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狄)*/
	{.bitmap_index = 495724, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狈)*/
	{.bitmap_index = 495852, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狍)*/
	{.bitmap_index = 495980, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狎)*/
	{.bitmap_index = 496100, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狐)*/
	{.bitmap_index = 496220, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狒)*/
	{.bitmap_index = 496348, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狗)*/
	{.bitmap_index = 496476, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狙)*/
	{.bitmap_index = 496596, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狞)*/
	{.bitmap_index = 496724, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狠)*/
	{.bitmap_index = 496852, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狡)*/
	{.bitmap_index = 496980, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狨)*/
	{.bitmap_index = 497108, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狩)*/
	{.bitmap_index = 497236, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(独)*/
	{.bitmap_index = 497364, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狭)*/
	{.bitmap_index = 497492, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狮)*/
	{.bitmap_index = 497620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狯)*/
	{.bitmap_index = 497748, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狰)*/
	{.bitmap_index = 497876, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狱)*/
	{.bitmap_index = 498004, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狲)*/
	{.bitmap_index = 498124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狳)*/
	{.bitmap_index = 498252, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狴)*/
	{.bitmap_index = 498372, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狷)*/
	{.bitmap_index = 498492, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狸)*/
	{.bitmap_index = 498612, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(狺)*/
	{.bitmap_index = 498732, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狻)*/
	{.bitmap_index = 498868, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(狼)*/
	{.bitmap_index = 499004, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猁)*/
	{.bitmap_index = 499124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猃)*/
	{.bitmap_index = 499252, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(猊)*/
	{.bitmap_index = 499388, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猎)*/
	{.bitmap_index = 499508, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猓)*/
	{.bitmap_index = 499628, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猕)*/
	{.bitmap_index = 499748, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猖)*/
	{.bitmap_index = 499868, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猗)*/
	{.bitmap_index = 499988, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猛)*/
	{.bitmap_index = 500108, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猜)*/
	{.bitmap_index = 500228, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猝)*/
	{.bitmap_index = 500356, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猞)*/
	{.bitmap_index = 500484, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猡)*/
	{.bitmap_index = 500604, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猢)*/
	{.bitmap_index = 500724, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猥)*/
	{.bitmap_index = 500844, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猩)*/
	{.bitmap_index = 500964, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猪)*/
	{.bitmap_index = 501084, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猫)*/
	{.bitmap_index = 501212, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猬)*/
	{.bitmap_index = 501332, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(献)*/
	{.bitmap_index = 501460, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猱)*/
	{.bitmap_index = 501580, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(猴)*/
	{.bitmap_index = 501716, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猷)*/
	{.bitmap_index = 501844, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猸)*/
	{.bitmap_index = 501964, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猹)*/
	{.bitmap_index = 502092, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(猾)*/
	{.bitmap_index = 502212, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(猿)*/
	{.bitmap_index = 502348, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(獍)*/
	{.bitmap_index = 502484, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(獐)*/
	{.bitmap_index = 502620, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(獒)*/
	{.bitmap_index = 502756, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(獗)*/
	{.bitmap_index = 502884, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(獠)*/
	{.bitmap_index = 503012, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(獬)*/
	{.bitmap_index = 503140, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(獭)*/
	{.bitmap_index = 503276, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(獯)*/
	{.bitmap_index = 503404, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(獾)*/
	{.bitmap_index = 503532, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(玄)*/
	{.bitmap_index = 503644, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(率)*/
	{.bitmap_index = 503772, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玉)*/
	{.bitmap_index = 503892, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(王)*/
	{.bitmap_index = 503997, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玎)*/
	{.bitmap_index = 504117, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玑)*/
	{.bitmap_index = 504245, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玖)*/
	{.bitmap_index = 504381, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玛)*/
	{.bitmap_index = 504501, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玟)*/
	{.bitmap_index = 504629, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玢)*/
	{.bitmap_index = 504765, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玩)*/
	{.bitmap_index = 504893, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玫)*/
	{.bitmap_index = 505029, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玮)*/
	{.bitmap_index = 505157, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(环)*/
	{.bitmap_index = 505277, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(现)*/
	{.bitmap_index = 505405, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玲)*/
	{.bitmap_index = 505541, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玳)*/
	{.bitmap_index = 505669, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玷)*/
	{.bitmap_index = 505789, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(玺)*/
	{.bitmap_index = 505917, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(玻)*/
	{.bitmap_index = 506045, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珀)*/
	{.bitmap_index = 506173, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珂)*/
	{.bitmap_index = 506293, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珈)*/
	{.bitmap_index = 506413, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(珉)*/
	{.bitmap_index = 506541, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珊)*/
	{.bitmap_index = 506661, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(珍)*/
	{.bitmap_index = 506797, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珏)*/
	{.bitmap_index = 506917, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珐)*/
	{.bitmap_index = 507037, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(珑)*/
	{.bitmap_index = 507165, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珙)*/
	{.bitmap_index = 507285, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珞)*/
	{.bitmap_index = 507413, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珠)*/
	{.bitmap_index = 507541, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珥)*/
	{.bitmap_index = 507661, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珧)*/
	{.bitmap_index = 507781, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珩)*/
	{.bitmap_index = 507901, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(班)*/
	{.bitmap_index = 508029, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(珲)*/
	{.bitmap_index = 508149, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(球)*/
	{.bitmap_index = 508277, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琅)*/
	{.bitmap_index = 508413, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(理)*/
	{.bitmap_index = 508533, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琉)*/
	{.bitmap_index = 508669, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琊)*/
	{.bitmap_index = 508789, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琏)*/
	{.bitmap_index = 508909, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琐)*/
	{.bitmap_index = 509045, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琚)*/
	{.bitmap_index = 509165, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琛)*/
	{.bitmap_index = 509285, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琢)*/
	{.bitmap_index = 509405, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琥)*/
	{.bitmap_index = 509541, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琦)*/
	{.bitmap_index = 509661, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琨)*/
	{.bitmap_index = 509781, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琪)*/
	{.bitmap_index = 509909, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琬)*/
	{.bitmap_index = 510045, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琮)*/
	{.bitmap_index = 510173, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琰)*/
	{.bitmap_index = 510301, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琳)*/
	{.bitmap_index = 510421, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(琴)*/
	{.bitmap_index = 510549, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(琵)*/
	{.bitmap_index = 510669, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(琶)*/
	{.bitmap_index = 510789, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(琼)*/
	{.bitmap_index = 510909, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑁)*/
	{.bitmap_index = 511029, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑕)*/
	{.bitmap_index = 511149, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瑗)*/
	{.bitmap_index = 511277, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑙)*/
	{.bitmap_index = 511405, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瑚)*/
	{.bitmap_index = 511533, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瑛)*/
	{.bitmap_index = 511661, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑜)*/
	{.bitmap_index = 511789, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑞)*/
	{.bitmap_index = 511917, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑟)*/
	{.bitmap_index = 512037, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑭)*/
	{.bitmap_index = 512165, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瑰)*/
	{.bitmap_index = 512301, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑶)*/
	{.bitmap_index = 512421, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瑷)*/
	{.bitmap_index = 512549, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瑾)*/
	{.bitmap_index = 512669, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璀)*/
	{.bitmap_index = 512789, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璁)*/
	{.bitmap_index = 512917, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璃)*/
	{.bitmap_index = 513045, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(璇)*/
	{.bitmap_index = 513173, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璋)*/
	{.bitmap_index = 513301, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(璎)*/
	{.bitmap_index = 513429, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璐)*/
	{.bitmap_index = 513557, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(璜)*/
	{.bitmap_index = 513685, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(璞)*/
	{.bitmap_index = 513821, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璧)*/
	{.bitmap_index = 513949, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璨)*/
	{.bitmap_index = 514069, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(璩)*/
	{.bitmap_index = 514205, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(璺)*/
	{.bitmap_index = 514325, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瓒)*/
	{.bitmap_index = 514461, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓜)*/
	{.bitmap_index = 514581, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瓞)*/
	{.bitmap_index = 514709, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓠)*/
	{.bitmap_index = 514837, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瓢)*/
	{.bitmap_index = 514965, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瓣)*/
	{.bitmap_index = 515093, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瓤)*/
	{.bitmap_index = 515229, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瓦)*/
	{.bitmap_index = 515349, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓮)*/
	{.bitmap_index = 515477, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瓯)*/
	{.bitmap_index = 515597, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓴)*/
	{.bitmap_index = 515725, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓶)*/
	{.bitmap_index = 515853, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓷)*/
	{.bitmap_index = 515981, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瓿)*/
	{.bitmap_index = 516101, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甄)*/
	{.bitmap_index = 516221, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(甍)*/
	{.bitmap_index = 516349, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(甏)*/
	{.bitmap_index = 516477, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(甑)*/
	{.bitmap_index = 516605, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甓)*/
	{.bitmap_index = 516733, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甘)*/
	{.bitmap_index = 516853, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(甙)*/
	{.bitmap_index = 516989, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甚)*/
	{.bitmap_index = 517109, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甜)*/
	{.bitmap_index = 517229, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(生)*/
	{.bitmap_index = 517349, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(甥)*/
	{.bitmap_index = 517477, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(用)*/
	{.bitmap_index = 517605, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甩)*/
	{.bitmap_index = 517725, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(甫)*/
	{.bitmap_index = 517837, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(甬)*/
	{.bitmap_index = 517942, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(甭)*/
	{.bitmap_index = 518070, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(甯)*/
	{.bitmap_index = 518182, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(田)*/
	{.bitmap_index = 518287, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(由)*/
	{.bitmap_index = 518392, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(甲)*/
	{.bitmap_index = 518497, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(申)*/
	{.bitmap_index = 518609, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(电)*/
	{.bitmap_index = 518729, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(男)*/
	{.bitmap_index = 518857, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甸)*/
	{.bitmap_index = 518985, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(町)*/
	{.bitmap_index = 519105, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(画)*/
	{.bitmap_index = 519225, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(甾)*/
	{.bitmap_index = 519353, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(畀)*/
	{.bitmap_index = 519481, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(畅)*/
	{.bitmap_index = 519600, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(畈)*/
	{.bitmap_index = 519728, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(畋)*/
	{.bitmap_index = 519864, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(界)*/
	{.bitmap_index = 519992, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(畎)*/
	{.bitmap_index = 520120, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(畏)*/
	{.bitmap_index = 520248, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(畔)*/
	{.bitmap_index = 520376, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(留)*/
	{.bitmap_index = 520488, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(畚)*/
	{.bitmap_index = 520616, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(畛)*/
	{.bitmap_index = 520752, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(畜)*/
	{.bitmap_index = 520880, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(略)*/
	{.bitmap_index = 521008, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(畦)*/
	{.bitmap_index = 521128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(番)*/
	{.bitmap_index = 521256, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(畲)*/
	{.bitmap_index = 521384, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(畴)*/
	{.bitmap_index = 521512, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(畸)*/
	{.bitmap_index = 521632, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(畹)*/
	{.bitmap_index = 521760, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(畿)*/
	{.bitmap_index = 521896, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(疃)*/
	{.bitmap_index = 522024, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(疆)*/
	{.bitmap_index = 522144, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(疋)*/
	{.bitmap_index = 522264, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疏)*/
	{.bitmap_index = 522400, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疑)*/
	{.bitmap_index = 522536, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疒)*/
	{.bitmap_index = 522672, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疔)*/
	{.bitmap_index = 522808, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疖)*/
	{.bitmap_index = 522944, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疗)*/
	{.bitmap_index = 523080, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(疙)*/
	{.bitmap_index = 523208, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疚)*/
	{.bitmap_index = 523344, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(疝)*/
	{.bitmap_index = 523472, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疟)*/
	{.bitmap_index = 523608, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疠)*/
	{.bitmap_index = 523744, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疡)*/
	{.bitmap_index = 523880, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疣)*/
	{.bitmap_index = 524016, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疤)*/
	{.bitmap_index = 524152, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疥)*/
	{.bitmap_index = 524288, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疫)*/
	{.bitmap_index = 524424, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疬)*/
	{.bitmap_index = 524560, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疮)*/
	{.bitmap_index = 524696, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疯)*/
	{.bitmap_index = 524832, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疰)*/
	{.bitmap_index = 524968, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(疱)*/
	{.bitmap_index = 525096, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疲)*/
	{.bitmap_index = 525224, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疳)*/
	{.bitmap_index = 525360, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疴)*/
	{.bitmap_index = 525496, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疵)*/
	{.bitmap_index = 525632, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疸)*/
	{.bitmap_index = 525768, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疹)*/
	{.bitmap_index = 525904, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疼)*/
	{.bitmap_index = 526040, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疽)*/
	{.bitmap_index = 526176, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(疾)*/
	{.bitmap_index = 526312, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痂)*/
	{.bitmap_index = 526448, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(痃)*/
	{.bitmap_index = 526568, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痄)*/
	{.bitmap_index = 526704, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(病)*/
	{.bitmap_index = 526840, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(症)*/
	{.bitmap_index = 526976, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痈)*/
	{.bitmap_index = 527104, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痉)*/
	{.bitmap_index = 527232, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痊)*/
	{.bitmap_index = 527368, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痍)*/
	{.bitmap_index = 527504, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痒)*/
	{.bitmap_index = 527640, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痔)*/
	{.bitmap_index = 527776, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痕)*/
	{.bitmap_index = 527912, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痖)*/
	{.bitmap_index = 528048, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痘)*/
	{.bitmap_index = 528184, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痛)*/
	{.bitmap_index = 528320, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痞)*/
	{.bitmap_index = 528456, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痢)*/
	{.bitmap_index = 528592, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痣)*/
	{.bitmap_index = 528728, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痤)*/
	{.bitmap_index = 528864, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(痦)*/
	{.bitmap_index = 528992, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痧)*/
	{.bitmap_index = 529128, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痨)*/
	{.bitmap_index = 529264, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痪)*/
	{.bitmap_index = 529400, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痫)*/
	{.bitmap_index = 529528, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痰)*/
	{.bitmap_index = 529664, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痱)*/
	{.bitmap_index = 529800, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痴)*/
	{.bitmap_index = 529936, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痹)*/
	{.bitmap_index = 530072, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痼)*/
	{.bitmap_index = 530208, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(痿)*/
	{.bitmap_index = 530344, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘀)*/
	{.bitmap_index = 530480, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘁)*/
	{.bitmap_index = 530616, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘃)*/
	{.bitmap_index = 530752, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘅)*/
	{.bitmap_index = 530888, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘊)*/
	{.bitmap_index = 531024, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘌)*/
	{.bitmap_index = 531160, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘐)*/
	{.bitmap_index = 531296, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘕)*/
	{.bitmap_index = 531432, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘗)*/
	{.bitmap_index = 531568, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘘)*/
	{.bitmap_index = 531704, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘙)*/
	{.bitmap_index = 531840, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘛)*/
	{.bitmap_index = 531976, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瘟)*/
	{.bitmap_index = 532104, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘠)*/
	{.bitmap_index = 532240, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘢)*/
	{.bitmap_index = 532376, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瘤)*/
	{.bitmap_index = 532504, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘥)*/
	{.bitmap_index = 532640, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘦)*/
	{.bitmap_index = 532776, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瘩)*/
	{.bitmap_index = 532904, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘪)*/
	{.bitmap_index = 533040, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘫)*/
	{.bitmap_index = 533176, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘭)*/
	{.bitmap_index = 533312, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘰)*/
	{.bitmap_index = 533448, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘳)*/
	{.bitmap_index = 533584, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘴)*/
	{.bitmap_index = 533720, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瘵)*/
	{.bitmap_index = 533848, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘸)*/
	{.bitmap_index = 533984, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘼)*/
	{.bitmap_index = 534120, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘾)*/
	{.bitmap_index = 534256, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(瘿)*/
	{.bitmap_index = 534392, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癀)*/
	{.bitmap_index = 534528, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(癃)*/
	{.bitmap_index = 534656, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(癌)*/
	{.bitmap_index = 534784, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癍)*/
	{.bitmap_index = 534920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(癔)*/
	{.bitmap_index = 535048, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(癖)*/
	{.bitmap_index = 535176, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(癜)*/
	{.bitmap_index = 535304, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癞)*/
	{.bitmap_index = 535440, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癣)*/
	{.bitmap_index = 535576, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癫)*/
	{.bitmap_index = 535712, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癯)*/
	{.bitmap_index = 535848, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(癸)*/
	{.bitmap_index = 535984, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(登)*/
	{.bitmap_index = 536112, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(白)*/
	{.bitmap_index = 536224, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(百)*/
	{.bitmap_index = 536344, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(皂)*/
	{.bitmap_index = 536472, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(的)*/
	{.bitmap_index = 536584, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(皆)*/
	{.bitmap_index = 536696, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(皇)*/
	{.bitmap_index = 536824, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(皈)*/
	{.bitmap_index = 536960, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(皋)*/
	{.bitmap_index = 537088, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(皎)*/
	{.bitmap_index = 537216, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(皑)*/
	{.bitmap_index = 537344, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(皓)*/
	{.bitmap_index = 537472, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(皖)*/
	{.bitmap_index = 537608, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(皙)*/
	{.bitmap_index = 537736, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(皤)*/
	{.bitmap_index = 537864, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(皮)*/
	{.bitmap_index = 538000, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(皱)*/
	{.bitmap_index = 538136, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(皲)*/
	{.bitmap_index = 538264, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(皴)*/
	{.bitmap_index = 538400, .adv_w = 16, .box_h = 13, .box_w = 16, .ofs_x = 0, .ofs_y = 5},/*(皿)*/
	{.bitmap_index = 538504, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盂)*/
	{.bitmap_index = 538624, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盅)*/
	{.bitmap_index = 538744, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盆)*/
	{.bitmap_index = 538872, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盈)*/
	{.bitmap_index = 538992, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(益)*/
	{.bitmap_index = 539120, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盍)*/
	{.bitmap_index = 539248, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盎)*/
	{.bitmap_index = 539368, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盏)*/
	{.bitmap_index = 539496, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盐)*/
	{.bitmap_index = 539616, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(监)*/
	{.bitmap_index = 539744, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盒)*/
	{.bitmap_index = 539872, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盔)*/
	{.bitmap_index = 540000, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盖)*/
	{.bitmap_index = 540128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盗)*/
	{.bitmap_index = 540256, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盘)*/
	{.bitmap_index = 540384, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盛)*/
	{.bitmap_index = 540512, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盟)*/
	{.bitmap_index = 540632, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盥)*/
	{.bitmap_index = 540752, .adv_w = 14, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(目)*/
	{.bitmap_index = 540842, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(盯)*/
	{.bitmap_index = 540962, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(盱)*/
	{.bitmap_index = 541082, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(盲)*/
	{.bitmap_index = 541210, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(直)*/
	{.bitmap_index = 541338, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(相)*/
	{.bitmap_index = 541458, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(盹)*/
	{.bitmap_index = 541578, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(盼)*/
	{.bitmap_index = 541714, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(盾)*/
	{.bitmap_index = 541842, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(省)*/
	{.bitmap_index = 541970, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眄)*/
	{.bitmap_index = 542090, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(眇)*/
	{.bitmap_index = 542226, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(眈)*/
	{.bitmap_index = 542354, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(眉)*/
	{.bitmap_index = 542474, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(看)*/
	{.bitmap_index = 542594, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眍)*/
	{.bitmap_index = 542714, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眙)*/
	{.bitmap_index = 542842, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(眚)*/
	{.bitmap_index = 542970, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(真)*/
	{.bitmap_index = 543098, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(眠)*/
	{.bitmap_index = 543226, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(眢)*/
	{.bitmap_index = 543354, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眦)*/
	{.bitmap_index = 543474, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眨)*/
	{.bitmap_index = 543594, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眩)*/
	{.bitmap_index = 543722, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眭)*/
	{.bitmap_index = 543842, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眯)*/
	{.bitmap_index = 543962, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(眵)*/
	{.bitmap_index = 544098, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眶)*/
	{.bitmap_index = 544218, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(眷)*/
	{.bitmap_index = 544346, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(眸)*/
	{.bitmap_index = 544474, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(眺)*/
	{.bitmap_index = 544602, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(眼)*/
	{.bitmap_index = 544730, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(着)*/
	{.bitmap_index = 544858, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睁)*/
	{.bitmap_index = 544986, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(睃)*/
	{.bitmap_index = 545122, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(睇)*/
	{.bitmap_index = 545234, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睐)*/
	{.bitmap_index = 545362, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睑)*/
	{.bitmap_index = 545490, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(睚)*/
	{.bitmap_index = 545618, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睛)*/
	{.bitmap_index = 545738, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睡)*/
	{.bitmap_index = 545858, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睢)*/
	{.bitmap_index = 545986, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(督)*/
	{.bitmap_index = 546106, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睥)*/
	{.bitmap_index = 546234, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睦)*/
	{.bitmap_index = 546362, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(睨)*/
	{.bitmap_index = 546498, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(睫)*/
	{.bitmap_index = 546634, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睬)*/
	{.bitmap_index = 546754, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(睹)*/
	{.bitmap_index = 546874, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(睽)*/
	{.bitmap_index = 547002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(睾)*/
	{.bitmap_index = 547130, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(睿)*/
	{.bitmap_index = 547258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瞀)*/
	{.bitmap_index = 547386, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞄)*/
	{.bitmap_index = 547506, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞅)*/
	{.bitmap_index = 547626, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞌)*/
	{.bitmap_index = 547754, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(瞍)*/
	{.bitmap_index = 547882, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞎)*/
	{.bitmap_index = 548002, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(瞑)*/
	{.bitmap_index = 548130, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞒)*/
	{.bitmap_index = 548258, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞟)*/
	{.bitmap_index = 548378, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞠)*/
	{.bitmap_index = 548506, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(瞢)*/
	{.bitmap_index = 548618, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞥)*/
	{.bitmap_index = 548746, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞧)*/
	{.bitmap_index = 548874, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(瞩)*/
	{.bitmap_index = 548979, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞪)*/
	{.bitmap_index = 549099, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(瞬)*/
	{.bitmap_index = 549211, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞰)*/
	{.bitmap_index = 549331, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(瞳)*/
	{.bitmap_index = 549451, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(瞵)*/
	{.bitmap_index = 549587, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(瞻)*/
	{.bitmap_index = 549723, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瞽)*/
	{.bitmap_index = 549851, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(瞿)*/
	{.bitmap_index = 549971, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矍)*/
	{.bitmap_index = 550099, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矗)*/
	{.bitmap_index = 550227, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矛)*/
	{.bitmap_index = 550347, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矜)*/
	{.bitmap_index = 550475, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矢)*/
	{.bitmap_index = 550611, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矣)*/
	{.bitmap_index = 550747, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(知)*/
	{.bitmap_index = 550883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矧)*/
	{.bitmap_index = 551011, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矩)*/
	{.bitmap_index = 551139, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矫)*/
	{.bitmap_index = 551275, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矬)*/
	{.bitmap_index = 551403, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(短)*/
	{.bitmap_index = 551531, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矮)*/
	{.bitmap_index = 551659, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(石)*/
	{.bitmap_index = 551779, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矶)*/
	{.bitmap_index = 551899, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(矸)*/
	{.bitmap_index = 552019, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矽)*/
	{.bitmap_index = 552155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矾)*/
	{.bitmap_index = 552283, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(矿)*/
	{.bitmap_index = 552411, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砀)*/
	{.bitmap_index = 552539, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(码)*/
	{.bitmap_index = 552659, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砂)*/
	{.bitmap_index = 552795, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砉)*/
	{.bitmap_index = 552915, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砌)*/
	{.bitmap_index = 553051, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砍)*/
	{.bitmap_index = 553187, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砑)*/
	{.bitmap_index = 553307, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砒)*/
	{.bitmap_index = 553427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(研)*/
	{.bitmap_index = 553555, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砖)*/
	{.bitmap_index = 553691, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砗)*/
	{.bitmap_index = 553819, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砘)*/
	{.bitmap_index = 553939, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砚)*/
	{.bitmap_index = 554067, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砜)*/
	{.bitmap_index = 554187, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砝)*/
	{.bitmap_index = 554307, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砟)*/
	{.bitmap_index = 554435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砣)*/
	{.bitmap_index = 554563, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砥)*/
	{.bitmap_index = 554691, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砦)*/
	{.bitmap_index = 554819, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砧)*/
	{.bitmap_index = 554939, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砩)*/
	{.bitmap_index = 555067, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砬)*/
	{.bitmap_index = 555187, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砭)*/
	{.bitmap_index = 555307, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砰)*/
	{.bitmap_index = 555427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(破)*/
	{.bitmap_index = 555555, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砷)*/
	{.bitmap_index = 555683, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砸)*/
	{.bitmap_index = 555803, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(砹)*/
	{.bitmap_index = 555931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砺)*/
	{.bitmap_index = 556051, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砻)*/
	{.bitmap_index = 556179, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砼)*/
	{.bitmap_index = 556307, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(砾)*/
	{.bitmap_index = 556427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(础)*/
	{.bitmap_index = 556555, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硅)*/
	{.bitmap_index = 556675, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硇)*/
	{.bitmap_index = 556803, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硌)*/
	{.bitmap_index = 556931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硎)*/
	{.bitmap_index = 557051, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硐)*/
	{.bitmap_index = 557171, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硒)*/
	{.bitmap_index = 557291, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(硕)*/
	{.bitmap_index = 557419, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(硖)*/
	{.bitmap_index = 557547, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硗)*/
	{.bitmap_index = 557675, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硝)*/
	{.bitmap_index = 557803, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硪)*/
	{.bitmap_index = 557923, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(硫)*/
	{.bitmap_index = 558059, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(硬)*/
	{.bitmap_index = 558187, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硭)*/
	{.bitmap_index = 558307, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(确)*/
	{.bitmap_index = 558435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硷)*/
	{.bitmap_index = 558563, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(硼)*/
	{.bitmap_index = 558683, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碇)*/
	{.bitmap_index = 558819, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碉)*/
	{.bitmap_index = 558939, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碌)*/
	{.bitmap_index = 559059, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碍)*/
	{.bitmap_index = 559179, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碎)*/
	{.bitmap_index = 559307, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碑)*/
	{.bitmap_index = 559435, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碓)*/
	{.bitmap_index = 559563, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碗)*/
	{.bitmap_index = 559699, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碘)*/
	{.bitmap_index = 559827, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碚)*/
	{.bitmap_index = 559955, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碛)*/
	{.bitmap_index = 560083, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碜)*/
	{.bitmap_index = 560219, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碟)*/
	{.bitmap_index = 560339, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碡)*/
	{.bitmap_index = 560475, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碣)*/
	{.bitmap_index = 560595, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碥)*/
	{.bitmap_index = 560723, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碧)*/
	{.bitmap_index = 560851, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碰)*/
	{.bitmap_index = 560979, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碱)*/
	{.bitmap_index = 561115, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碲)*/
	{.bitmap_index = 561243, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碳)*/
	{.bitmap_index = 561379, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碴)*/
	{.bitmap_index = 561507, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(碹)*/
	{.bitmap_index = 561627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(碾)*/
	{.bitmap_index = 561755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磁)*/
	{.bitmap_index = 561883, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(磅)*/
	{.bitmap_index = 562019, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磉)*/
	{.bitmap_index = 562139, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磊)*/
	{.bitmap_index = 562259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磋)*/
	{.bitmap_index = 562387, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磐)*/
	{.bitmap_index = 562515, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磔)*/
	{.bitmap_index = 562643, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磕)*/
	{.bitmap_index = 562763, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(磙)*/
	{.bitmap_index = 562899, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磨)*/
	{.bitmap_index = 563027, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磬)*/
	{.bitmap_index = 563155, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磲)*/
	{.bitmap_index = 563283, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(磴)*/
	{.bitmap_index = 563403, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(磷)*/
	{.bitmap_index = 563539, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(磺)*/
	{.bitmap_index = 563667, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(礁)*/
	{.bitmap_index = 563795, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(礅)*/
	{.bitmap_index = 563931, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(礓)*/
	{.bitmap_index = 564051, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(礞)*/
	{.bitmap_index = 564187, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(礤)*/
	{.bitmap_index = 564307, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(礴)*/
	{.bitmap_index = 564427, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(示)*/
	{.bitmap_index = 564547, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(礻)*/
	{.bitmap_index = 564627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(礼)*/
	{.bitmap_index = 564755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(社)*/
	{.bitmap_index = 564883, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祀)*/
	{.bitmap_index = 565003, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祁)*/
	{.bitmap_index = 565131, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祆)*/
	{.bitmap_index = 565259, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(祈)*/
	{.bitmap_index = 565395, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祉)*/
	{.bitmap_index = 565515, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(祓)*/
	{.bitmap_index = 565651, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祖)*/
	{.bitmap_index = 565779, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(祗)*/
	{.bitmap_index = 565915, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祚)*/
	{.bitmap_index = 566043, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祛)*/
	{.bitmap_index = 566171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祜)*/
	{.bitmap_index = 566299, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(祝)*/
	{.bitmap_index = 566427, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(神)*/
	{.bitmap_index = 566555, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祟)*/
	{.bitmap_index = 566683, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祠)*/
	{.bitmap_index = 566811, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祢)*/
	{.bitmap_index = 566939, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祥)*/
	{.bitmap_index = 567067, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(祧)*/
	{.bitmap_index = 567195, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(票)*/
	{.bitmap_index = 567315, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祭)*/
	{.bitmap_index = 567443, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祯)*/
	{.bitmap_index = 567571, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祷)*/
	{.bitmap_index = 567699, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(祸)*/
	{.bitmap_index = 567819, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(祺)*/
	{.bitmap_index = 567955, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禀)*/
	{.bitmap_index = 568083, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禁)*/
	{.bitmap_index = 568203, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禄)*/
	{.bitmap_index = 568323, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禅)*/
	{.bitmap_index = 568451, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(禊)*/
	{.bitmap_index = 568579, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(福)*/
	{.bitmap_index = 568699, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禚)*/
	{.bitmap_index = 568827, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禧)*/
	{.bitmap_index = 568947, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(禳)*/
	{.bitmap_index = 569083, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(禹)*/
	{.bitmap_index = 569188, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(禺)*/
	{.bitmap_index = 569293, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(离)*/
	{.bitmap_index = 569405, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禽)*/
	{.bitmap_index = 569533, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(禾)*/
	{.bitmap_index = 569653, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秀)*/
	{.bitmap_index = 569781, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(私)*/
	{.bitmap_index = 569901, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秃)*/
	{.bitmap_index = 570029, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秆)*/
	{.bitmap_index = 570149, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秉)*/
	{.bitmap_index = 570269, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秋)*/
	{.bitmap_index = 570397, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(种)*/
	{.bitmap_index = 570525, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(科)*/
	{.bitmap_index = 570645, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秒)*/
	{.bitmap_index = 570781, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秕)*/
	{.bitmap_index = 570901, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秘)*/
	{.bitmap_index = 571029, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(租)*/
	{.bitmap_index = 571149, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秣)*/
	{.bitmap_index = 571277, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秤)*/
	{.bitmap_index = 571397, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秦)*/
	{.bitmap_index = 571525, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秧)*/
	{.bitmap_index = 571653, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秩)*/
	{.bitmap_index = 571781, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秫)*/
	{.bitmap_index = 571909, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秭)*/
	{.bitmap_index = 572037, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(积)*/
	{.bitmap_index = 572157, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(称)*/
	{.bitmap_index = 572285, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(秸)*/
	{.bitmap_index = 572405, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(移)*/
	{.bitmap_index = 572541, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(秽)*/
	{.bitmap_index = 572677, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稀)*/
	{.bitmap_index = 572805, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(稂)*/
	{.bitmap_index = 572941, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稃)*/
	{.bitmap_index = 573061, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稆)*/
	{.bitmap_index = 573181, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(程)*/
	{.bitmap_index = 573301, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稍)*/
	{.bitmap_index = 573429, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(税)*/
	{.bitmap_index = 573565, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稔)*/
	{.bitmap_index = 573693, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稗)*/
	{.bitmap_index = 573821, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稚)*/
	{.bitmap_index = 573949, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稞)*/
	{.bitmap_index = 574069, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稠)*/
	{.bitmap_index = 574189, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稣)*/
	{.bitmap_index = 574317, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稳)*/
	{.bitmap_index = 574445, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(稷)*/
	{.bitmap_index = 574573, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(稹)*/
	{.bitmap_index = 574701, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稻)*/
	{.bitmap_index = 574829, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稼)*/
	{.bitmap_index = 574957, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稽)*/
	{.bitmap_index = 575085, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(稿)*/
	{.bitmap_index = 575205, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(穆)*/
	{.bitmap_index = 575341, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(穑)*/
	{.bitmap_index = 575461, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(穗)*/
	{.bitmap_index = 575589, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(穰)*/
	{.bitmap_index = 575725, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(穴)*/
	{.bitmap_index = 575853, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(究)*/
	{.bitmap_index = 575989, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(穷)*/
	{.bitmap_index = 576125, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(穸)*/
	{.bitmap_index = 576253, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(穹)*/
	{.bitmap_index = 576381, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(空)*/
	{.bitmap_index = 576509, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(穿)*/
	{.bitmap_index = 576637, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(窀)*/
	{.bitmap_index = 576765, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(突)*/
	{.bitmap_index = 576901, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(窃)*/
	{.bitmap_index = 577037, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窄)*/
	{.bitmap_index = 577165, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窆)*/
	{.bitmap_index = 577285, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(窈)*/
	{.bitmap_index = 577397, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窍)*/
	{.bitmap_index = 577525, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(窑)*/
	{.bitmap_index = 577653, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窒)*/
	{.bitmap_index = 577781, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(窕)*/
	{.bitmap_index = 577917, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窖)*/
	{.bitmap_index = 578045, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(窗)*/
	{.bitmap_index = 578173, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窘)*/
	{.bitmap_index = 578301, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窜)*/
	{.bitmap_index = 578429, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(窝)*/
	{.bitmap_index = 578557, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窟)*/
	{.bitmap_index = 578685, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窠)*/
	{.bitmap_index = 578805, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(窥)*/
	{.bitmap_index = 578933, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(窦)*/
	{.bitmap_index = 579052, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窨)*/
	{.bitmap_index = 579180, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(窬)*/
	{.bitmap_index = 579308, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(窭)*/
	{.bitmap_index = 579444, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(窳)*/
	{.bitmap_index = 579580, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(窿)*/
	{.bitmap_index = 579700, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(立)*/
	{.bitmap_index = 579820, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竖)*/
	{.bitmap_index = 579940, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(站)*/
	{.bitmap_index = 580060, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(竞)*/
	{.bitmap_index = 580196, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(竟)*/
	{.bitmap_index = 580332, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(章)*/
	{.bitmap_index = 580468, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(竣)*/
	{.bitmap_index = 580604, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(童)*/
	{.bitmap_index = 580724, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竦)*/
	{.bitmap_index = 580852, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竭)*/
	{.bitmap_index = 580972, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(端)*/
	{.bitmap_index = 581100, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竹)*/
	{.bitmap_index = 581228, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竺)*/
	{.bitmap_index = 581356, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竽)*/
	{.bitmap_index = 581484, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(竿)*/
	{.bitmap_index = 581612, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笃)*/
	{.bitmap_index = 581740, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笄)*/
	{.bitmap_index = 581876, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笆)*/
	{.bitmap_index = 582004, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笈)*/
	{.bitmap_index = 582140, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笊)*/
	{.bitmap_index = 582276, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笋)*/
	{.bitmap_index = 582412, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笏)*/
	{.bitmap_index = 582548, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笑)*/
	{.bitmap_index = 582684, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笔)*/
	{.bitmap_index = 582812, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笕)*/
	{.bitmap_index = 582948, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笙)*/
	{.bitmap_index = 583076, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笛)*/
	{.bitmap_index = 583204, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笞)*/
	{.bitmap_index = 583332, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笠)*/
	{.bitmap_index = 583460, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笤)*/
	{.bitmap_index = 583588, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笥)*/
	{.bitmap_index = 583716, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(符)*/
	{.bitmap_index = 583844, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笨)*/
	{.bitmap_index = 583972, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笪)*/
	{.bitmap_index = 584100, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笫)*/
	{.bitmap_index = 584228, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(第)*/
	{.bitmap_index = 584356, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笮)*/
	{.bitmap_index = 584484, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笱)*/
	{.bitmap_index = 584612, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笳)*/
	{.bitmap_index = 584748, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笸)*/
	{.bitmap_index = 584876, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笺)*/
	{.bitmap_index = 585004, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(笼)*/
	{.bitmap_index = 585140, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(笾)*/
	{.bitmap_index = 585268, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筅)*/
	{.bitmap_index = 585404, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筇)*/
	{.bitmap_index = 585532, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(等)*/
	{.bitmap_index = 585660, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筋)*/
	{.bitmap_index = 585796, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筌)*/
	{.bitmap_index = 585924, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筏)*/
	{.bitmap_index = 586052, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筐)*/
	{.bitmap_index = 586180, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筑)*/
	{.bitmap_index = 586316, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筒)*/
	{.bitmap_index = 586444, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(答)*/
	{.bitmap_index = 586572, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(策)*/
	{.bitmap_index = 586700, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筘)*/
	{.bitmap_index = 586828, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筚)*/
	{.bitmap_index = 586956, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筛)*/
	{.bitmap_index = 587092, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筝)*/
	{.bitmap_index = 587220, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筠)*/
	{.bitmap_index = 587348, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筢)*/
	{.bitmap_index = 587476, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筮)*/
	{.bitmap_index = 587604, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筱)*/
	{.bitmap_index = 587740, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筲)*/
	{.bitmap_index = 587868, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筵)*/
	{.bitmap_index = 588004, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筷)*/
	{.bitmap_index = 588140, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(筹)*/
	{.bitmap_index = 588268, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(筻)*/
	{.bitmap_index = 588404, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(签)*/
	{.bitmap_index = 588532, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(简)*/
	{.bitmap_index = 588660, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箅)*/
	{.bitmap_index = 588796, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箍)*/
	{.bitmap_index = 588924, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箐)*/
	{.bitmap_index = 589052, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箔)*/
	{.bitmap_index = 589180, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箕)*/
	{.bitmap_index = 589316, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(算)*/
	{.bitmap_index = 589452, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箜)*/
	{.bitmap_index = 589580, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箝)*/
	{.bitmap_index = 589708, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(管)*/
	{.bitmap_index = 589836, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箢)*/
	{.bitmap_index = 589972, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箦)*/
	{.bitmap_index = 590108, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箧)*/
	{.bitmap_index = 590236, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箨)*/
	{.bitmap_index = 590364, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箩)*/
	{.bitmap_index = 590500, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箪)*/
	{.bitmap_index = 590636, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箫)*/
	{.bitmap_index = 590772, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箬)*/
	{.bitmap_index = 590900, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箭)*/
	{.bitmap_index = 591028, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箱)*/
	{.bitmap_index = 591156, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(箴)*/
	{.bitmap_index = 591292, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(箸)*/
	{.bitmap_index = 591420, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篁)*/
	{.bitmap_index = 591548, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篆)*/
	{.bitmap_index = 591676, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篇)*/
	{.bitmap_index = 591804, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篌)*/
	{.bitmap_index = 591940, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篑)*/
	{.bitmap_index = 592076, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篓)*/
	{.bitmap_index = 592212, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篙)*/
	{.bitmap_index = 592340, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篚)*/
	{.bitmap_index = 592468, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篝)*/
	{.bitmap_index = 592596, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篡)*/
	{.bitmap_index = 592732, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篥)*/
	{.bitmap_index = 592860, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篦)*/
	{.bitmap_index = 592988, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篪)*/
	{.bitmap_index = 593124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篮)*/
	{.bitmap_index = 593252, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篱)*/
	{.bitmap_index = 593380, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(篷)*/
	{.bitmap_index = 593508, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篼)*/
	{.bitmap_index = 593644, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(篾)*/
	{.bitmap_index = 593780, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(簇)*/
	{.bitmap_index = 593916, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(簋)*/
	{.bitmap_index = 594044, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(簌)*/
	{.bitmap_index = 594180, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(簏)*/
	{.bitmap_index = 594308, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(簖)*/
	{.bitmap_index = 594444, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(簟)*/
	{.bitmap_index = 594572, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(簦)*/
	{.bitmap_index = 594700, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(簧)*/
	{.bitmap_index = 594836, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(簪)*/
	{.bitmap_index = 594964, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(簸)*/
	{.bitmap_index = 595100, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(簿)*/
	{.bitmap_index = 595228, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(籀)*/
	{.bitmap_index = 595356, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(籁)*/
	{.bitmap_index = 595492, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(籍)*/
	{.bitmap_index = 595620, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(米)*/
	{.bitmap_index = 595740, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(籴)*/
	{.bitmap_index = 595868, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(类)*/
	{.bitmap_index = 595996, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(籼)*/
	{.bitmap_index = 596116, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(籽)*/
	{.bitmap_index = 596236, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(粉)*/
	{.bitmap_index = 596372, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粑)*/
	{.bitmap_index = 596500, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粒)*/
	{.bitmap_index = 596628, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粕)*/
	{.bitmap_index = 596756, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粗)*/
	{.bitmap_index = 596876, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粘)*/
	{.bitmap_index = 596996, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(粜)*/
	{.bitmap_index = 597132, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粝)*/
	{.bitmap_index = 597260, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粞)*/
	{.bitmap_index = 597388, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粟)*/
	{.bitmap_index = 597508, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粢)*/
	{.bitmap_index = 597636, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粤)*/
	{.bitmap_index = 597764, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(粥)*/
	{.bitmap_index = 597869, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(粪)*/
	{.bitmap_index = 598005, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(粮)*/
	{.bitmap_index = 598141, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粱)*/
	{.bitmap_index = 598269, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粲)*/
	{.bitmap_index = 598397, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(粳)*/
	{.bitmap_index = 598533, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粹)*/
	{.bitmap_index = 598653, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(粼)*/
	{.bitmap_index = 598789, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(粽)*/
	{.bitmap_index = 598917, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(精)*/
	{.bitmap_index = 599037, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(糁)*/
	{.bitmap_index = 599173, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糅)*/
	{.bitmap_index = 599293, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(糇)*/
	{.bitmap_index = 599429, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糈)*/
	{.bitmap_index = 599549, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(糊)*/
	{.bitmap_index = 599677, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糌)*/
	{.bitmap_index = 599805, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糍)*/
	{.bitmap_index = 599933, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糕)*/
	{.bitmap_index = 600053, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糖)*/
	{.bitmap_index = 600181, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(糗)*/
	{.bitmap_index = 600317, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糙)*/
	{.bitmap_index = 600445, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(糜)*/
	{.bitmap_index = 600581, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糟)*/
	{.bitmap_index = 600709, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糠)*/
	{.bitmap_index = 600837, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糨)*/
	{.bitmap_index = 600957, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糯)*/
	{.bitmap_index = 601077, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(糸)*/
	{.bitmap_index = 601205, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(系)*/
	{.bitmap_index = 601325, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(紊)*/
	{.bitmap_index = 601453, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(素)*/
	{.bitmap_index = 601581, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(索)*/
	{.bitmap_index = 601709, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(紧)*/
	{.bitmap_index = 601829, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(紫)*/
	{.bitmap_index = 601957, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(累)*/
	{.bitmap_index = 602077, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(絮)*/
	{.bitmap_index = 602205, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(絷)*/
	{.bitmap_index = 602333, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(綦)*/
	{.bitmap_index = 602453, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(綮)*/
	{.bitmap_index = 602581, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(縻)*/
	{.bitmap_index = 602709, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(繁)*/
	{.bitmap_index = 602837, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(繇)*/
	{.bitmap_index = 602957, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纂)*/
	{.bitmap_index = 603085, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纛)*/
	{.bitmap_index = 603221, .adv_w = 9, .box_h = 16, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(纟)*/
	{.bitmap_index = 603285, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纠)*/
	{.bitmap_index = 603413, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纡)*/
	{.bitmap_index = 603541, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(红)*/
	{.bitmap_index = 603669, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纣)*/
	{.bitmap_index = 603797, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纤)*/
	{.bitmap_index = 603925, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纥)*/
	{.bitmap_index = 604053, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(约)*/
	{.bitmap_index = 604181, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(级)*/
	{.bitmap_index = 604317, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纨)*/
	{.bitmap_index = 604453, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纩)*/
	{.bitmap_index = 604589, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纪)*/
	{.bitmap_index = 604717, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纫)*/
	{.bitmap_index = 604853, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纬)*/
	{.bitmap_index = 604981, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纭)*/
	{.bitmap_index = 605109, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纯)*/
	{.bitmap_index = 605237, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纰)*/
	{.bitmap_index = 605365, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纱)*/
	{.bitmap_index = 605501, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纲)*/
	{.bitmap_index = 605621, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纳)*/
	{.bitmap_index = 605741, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纵)*/
	{.bitmap_index = 605869, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纶)*/
	{.bitmap_index = 605997, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纷)*/
	{.bitmap_index = 606133, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纸)*/
	{.bitmap_index = 606253, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(纹)*/
	{.bitmap_index = 606381, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纺)*/
	{.bitmap_index = 606509, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纽)*/
	{.bitmap_index = 606637, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(纾)*/
	{.bitmap_index = 606765, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(线)*/
	{.bitmap_index = 606901, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绀)*/
	{.bitmap_index = 607021, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绁)*/
	{.bitmap_index = 607149, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绂)*/
	{.bitmap_index = 607285, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(练)*/
	{.bitmap_index = 607413, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(组)*/
	{.bitmap_index = 607541, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绅)*/
	{.bitmap_index = 607669, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(细)*/
	{.bitmap_index = 607789, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(织)*/
	{.bitmap_index = 607925, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(终)*/
	{.bitmap_index = 608061, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绉)*/
	{.bitmap_index = 608189, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绊)*/
	{.bitmap_index = 608317, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绋)*/
	{.bitmap_index = 608445, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绌)*/
	{.bitmap_index = 608573, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绍)*/
	{.bitmap_index = 608701, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绎)*/
	{.bitmap_index = 608829, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(经)*/
	{.bitmap_index = 608957, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绐)*/
	{.bitmap_index = 609085, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绑)*/
	{.bitmap_index = 609213, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绒)*/
	{.bitmap_index = 609349, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(结)*/
	{.bitmap_index = 609477, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绔)*/
	{.bitmap_index = 609605, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绕)*/
	{.bitmap_index = 609741, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绗)*/
	{.bitmap_index = 609869, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绘)*/
	{.bitmap_index = 609997, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(给)*/
	{.bitmap_index = 610125, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绚)*/
	{.bitmap_index = 610253, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绛)*/
	{.bitmap_index = 610381, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(络)*/
	{.bitmap_index = 610509, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绝)*/
	{.bitmap_index = 610637, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绞)*/
	{.bitmap_index = 610765, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(统)*/
	{.bitmap_index = 610901, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绠)*/
	{.bitmap_index = 611029, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绡)*/
	{.bitmap_index = 611157, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绢)*/
	{.bitmap_index = 611285, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绣)*/
	{.bitmap_index = 611413, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绥)*/
	{.bitmap_index = 611549, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绦)*/
	{.bitmap_index = 611677, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(继)*/
	{.bitmap_index = 611797, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绨)*/
	{.bitmap_index = 611925, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绩)*/
	{.bitmap_index = 612053, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绪)*/
	{.bitmap_index = 612181, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绫)*/
	{.bitmap_index = 612317, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(续)*/
	{.bitmap_index = 612453, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绮)*/
	{.bitmap_index = 612581, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绯)*/
	{.bitmap_index = 612709, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绰)*/
	{.bitmap_index = 612837, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绱)*/
	{.bitmap_index = 612965, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绲)*/
	{.bitmap_index = 613093, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绳)*/
	{.bitmap_index = 613221, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(维)*/
	{.bitmap_index = 613349, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绵)*/
	{.bitmap_index = 613477, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绶)*/
	{.bitmap_index = 613613, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绷)*/
	{.bitmap_index = 613741, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(绸)*/
	{.bitmap_index = 613869, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绺)*/
	{.bitmap_index = 613997, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绻)*/
	{.bitmap_index = 614125, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(综)*/
	{.bitmap_index = 614253, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绽)*/
	{.bitmap_index = 614381, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绾)*/
	{.bitmap_index = 614509, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(绿)*/
	{.bitmap_index = 614637, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缀)*/
	{.bitmap_index = 614765, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缁)*/
	{.bitmap_index = 614893, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缂)*/
	{.bitmap_index = 615021, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缃)*/
	{.bitmap_index = 615149, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缄)*/
	{.bitmap_index = 615285, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缅)*/
	{.bitmap_index = 615413, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缆)*/
	{.bitmap_index = 615549, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缇)*/
	{.bitmap_index = 615677, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缈)*/
	{.bitmap_index = 615813, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缉)*/
	{.bitmap_index = 615941, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缋)*/
	{.bitmap_index = 616077, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缌)*/
	{.bitmap_index = 616205, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缍)*/
	{.bitmap_index = 616333, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缎)*/
	{.bitmap_index = 616469, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缏)*/
	{.bitmap_index = 616597, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缑)*/
	{.bitmap_index = 616733, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缒)*/
	{.bitmap_index = 616861, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缓)*/
	{.bitmap_index = 616989, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缔)*/
	{.bitmap_index = 617117, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缕)*/
	{.bitmap_index = 617245, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(编)*/
	{.bitmap_index = 617373, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缗)*/
	{.bitmap_index = 617501, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缘)*/
	{.bitmap_index = 617629, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缙)*/
	{.bitmap_index = 617757, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缚)*/
	{.bitmap_index = 617885, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缛)*/
	{.bitmap_index = 618013, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缜)*/
	{.bitmap_index = 618141, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缝)*/
	{.bitmap_index = 618269, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缟)*/
	{.bitmap_index = 618397, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缠)*/
	{.bitmap_index = 618525, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缡)*/
	{.bitmap_index = 618653, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缢)*/
	{.bitmap_index = 618781, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缣)*/
	{.bitmap_index = 618909, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缤)*/
	{.bitmap_index = 619045, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缥)*/
	{.bitmap_index = 619173, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缦)*/
	{.bitmap_index = 619309, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缧)*/
	{.bitmap_index = 619437, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缨)*/
	{.bitmap_index = 619565, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缩)*/
	{.bitmap_index = 619693, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缪)*/
	{.bitmap_index = 619821, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缫)*/
	{.bitmap_index = 619949, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缬)*/
	{.bitmap_index = 620077, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缭)*/
	{.bitmap_index = 620205, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缮)*/
	{.bitmap_index = 620333, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缯)*/
	{.bitmap_index = 620461, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缰)*/
	{.bitmap_index = 620589, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缱)*/
	{.bitmap_index = 620717, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缲)*/
	{.bitmap_index = 620845, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缳)*/
	{.bitmap_index = 620981, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缴)*/
	{.bitmap_index = 621117, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缵)*/
	{.bitmap_index = 621253, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缶)*/
	{.bitmap_index = 621381, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(缸)*/
	{.bitmap_index = 621509, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(缺)*/
	{.bitmap_index = 621645, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罂)*/
	{.bitmap_index = 621765, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罄)*/
	{.bitmap_index = 621893, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罅)*/
	{.bitmap_index = 622021, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罐)*/
	{.bitmap_index = 622149, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(网)*/
	{.bitmap_index = 622254, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(罔)*/
	{.bitmap_index = 622359, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罕)*/
	{.bitmap_index = 622479, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(罗)*/
	{.bitmap_index = 622607, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罘)*/
	{.bitmap_index = 622727, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(罚)*/
	{.bitmap_index = 622832, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罟)*/
	{.bitmap_index = 622952, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罡)*/
	{.bitmap_index = 623072, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罢)*/
	{.bitmap_index = 623192, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罨)*/
	{.bitmap_index = 623312, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罩)*/
	{.bitmap_index = 623432, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罪)*/
	{.bitmap_index = 623552, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(置)*/
	{.bitmap_index = 623672, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罱)*/
	{.bitmap_index = 623792, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(署)*/
	{.bitmap_index = 623912, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(罴)*/
	{.bitmap_index = 624040, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(罹)*/
	{.bitmap_index = 624160, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(罾)*/
	{.bitmap_index = 624265, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(羁)*/
	{.bitmap_index = 624385, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(羊)*/
	{.bitmap_index = 624513, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羌)*/
	{.bitmap_index = 624649, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(美)*/
	{.bitmap_index = 624785, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羔)*/
	{.bitmap_index = 624921, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羚)*/
	{.bitmap_index = 625057, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羝)*/
	{.bitmap_index = 625193, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(羞)*/
	{.bitmap_index = 625321, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羟)*/
	{.bitmap_index = 625457, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羡)*/
	{.bitmap_index = 625593, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(群)*/
	{.bitmap_index = 625721, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羧)*/
	{.bitmap_index = 625857, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羯)*/
	{.bitmap_index = 625993, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羰)*/
	{.bitmap_index = 626129, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(羲)*/
	{.bitmap_index = 626257, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羸)*/
	{.bitmap_index = 626393, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羹)*/
	{.bitmap_index = 626529, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羼)*/
	{.bitmap_index = 626657, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(羽)*/
	{.bitmap_index = 626777, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(羿)*/
	{.bitmap_index = 626905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翁)*/
	{.bitmap_index = 627033, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翅)*/
	{.bitmap_index = 627153, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翊)*/
	{.bitmap_index = 627273, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翌)*/
	{.bitmap_index = 627393, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翎)*/
	{.bitmap_index = 627521, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(翔)*/
	{.bitmap_index = 627657, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翕)*/
	{.bitmap_index = 627785, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翘)*/
	{.bitmap_index = 627905, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翟)*/
	{.bitmap_index = 628025, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翠)*/
	{.bitmap_index = 628145, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翡)*/
	{.bitmap_index = 628273, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翥)*/
	{.bitmap_index = 628401, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翦)*/
	{.bitmap_index = 628529, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翩)*/
	{.bitmap_index = 628657, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(翮)*/
	{.bitmap_index = 628762, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翰)*/
	{.bitmap_index = 628890, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翱)*/
	{.bitmap_index = 629018, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(翳)*/
	{.bitmap_index = 629138, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(翻)*/
	{.bitmap_index = 629258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(翼)*/
	{.bitmap_index = 629386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耀)*/
	{.bitmap_index = 629514, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(老)*/
	{.bitmap_index = 629634, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(考)*/
	{.bitmap_index = 629754, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耄)*/
	{.bitmap_index = 629882, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(者)*/
	{.bitmap_index = 630002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耆)*/
	{.bitmap_index = 630130, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耋)*/
	{.bitmap_index = 630250, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(而)*/
	{.bitmap_index = 630355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(耍)*/
	{.bitmap_index = 630483, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(耐)*/
	{.bitmap_index = 630603, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耒)*/
	{.bitmap_index = 630731, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耔)*/
	{.bitmap_index = 630859, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(耕)*/
	{.bitmap_index = 630987, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(耖)*/
	{.bitmap_index = 631123, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耗)*/
	{.bitmap_index = 631243, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耘)*/
	{.bitmap_index = 631371, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耙)*/
	{.bitmap_index = 631499, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耜)*/
	{.bitmap_index = 631627, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耠)*/
	{.bitmap_index = 631755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(耢)*/
	{.bitmap_index = 631883, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耥)*/
	{.bitmap_index = 632003, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耦)*/
	{.bitmap_index = 632123, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(耧)*/
	{.bitmap_index = 632259, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耨)*/
	{.bitmap_index = 632379, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耩)*/
	{.bitmap_index = 632499, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(耪)*/
	{.bitmap_index = 632635, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耱)*/
	{.bitmap_index = 632763, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耳)*/
	{.bitmap_index = 632883, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耵)*/
	{.bitmap_index = 633003, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耶)*/
	{.bitmap_index = 633123, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耷)*/
	{.bitmap_index = 633251, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耸)*/
	{.bitmap_index = 633379, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耻)*/
	{.bitmap_index = 633499, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耽)*/
	{.bitmap_index = 633619, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(耿)*/
	{.bitmap_index = 633739, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(聂)*/
	{.bitmap_index = 633867, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聃)*/
	{.bitmap_index = 633987, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(聆)*/
	{.bitmap_index = 634123, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(聊)*/
	{.bitmap_index = 634259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聋)*/
	{.bitmap_index = 634387, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(职)*/
	{.bitmap_index = 634515, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聍)*/
	{.bitmap_index = 634635, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聒)*/
	{.bitmap_index = 634755, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(联)*/
	{.bitmap_index = 634883, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聘)*/
	{.bitmap_index = 635011, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聚)*/
	{.bitmap_index = 635131, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聩)*/
	{.bitmap_index = 635259, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聪)*/
	{.bitmap_index = 635387, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聱)*/
	{.bitmap_index = 635515, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(聿)*/
	{.bitmap_index = 635643, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肀)*/
	{.bitmap_index = 635771, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肃)*/
	{.bitmap_index = 635907, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肄)*/
	{.bitmap_index = 636043, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肆)*/
	{.bitmap_index = 636171, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肇)*/
	{.bitmap_index = 636299, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(肉)*/
	{.bitmap_index = 636404, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肋)*/
	{.bitmap_index = 636532, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肌)*/
	{.bitmap_index = 636660, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肓)*/
	{.bitmap_index = 636788, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(肖)*/
	{.bitmap_index = 636893, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肘)*/
	{.bitmap_index = 637021, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肚)*/
	{.bitmap_index = 637157, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肛)*/
	{.bitmap_index = 637285, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肜)*/
	{.bitmap_index = 637421, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肝)*/
	{.bitmap_index = 637541, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肟)*/
	{.bitmap_index = 637669, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肠)*/
	{.bitmap_index = 637797, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(股)*/
	{.bitmap_index = 637925, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肢)*/
	{.bitmap_index = 638061, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肤)*/
	{.bitmap_index = 638189, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肥)*/
	{.bitmap_index = 638309, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肩)*/
	{.bitmap_index = 638437, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肪)*/
	{.bitmap_index = 638565, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肫)*/
	{.bitmap_index = 638701, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肭)*/
	{.bitmap_index = 638821, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肮)*/
	{.bitmap_index = 638949, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肯)*/
	{.bitmap_index = 639069, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肱)*/
	{.bitmap_index = 639197, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(育)*/
	{.bitmap_index = 639325, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肴)*/
	{.bitmap_index = 639453, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肷)*/
	{.bitmap_index = 639589, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(肺)*/
	{.bitmap_index = 639709, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肼)*/
	{.bitmap_index = 639837, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肽)*/
	{.bitmap_index = 639965, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(肾)*/
	{.bitmap_index = 640085, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(肿)*/
	{.bitmap_index = 640221, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胀)*/
	{.bitmap_index = 640349, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胁)*/
	{.bitmap_index = 640477, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胂)*/
	{.bitmap_index = 640605, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(胃)*/
	{.bitmap_index = 640710, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(胄)*/
	{.bitmap_index = 640829, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胆)*/
	{.bitmap_index = 640957, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(背)*/
	{.bitmap_index = 641085, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胍)*/
	{.bitmap_index = 641205, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胎)*/
	{.bitmap_index = 641341, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胖)*/
	{.bitmap_index = 641477, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胗)*/
	{.bitmap_index = 641613, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胙)*/
	{.bitmap_index = 641749, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胚)*/
	{.bitmap_index = 641869, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胛)*/
	{.bitmap_index = 641997, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胜)*/
	{.bitmap_index = 642117, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胝)*/
	{.bitmap_index = 642245, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胞)*/
	{.bitmap_index = 642373, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胡)*/
	{.bitmap_index = 642501, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胤)*/
	{.bitmap_index = 642629, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胥)*/
	{.bitmap_index = 642749, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胧)*/
	{.bitmap_index = 642877, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胨)*/
	{.bitmap_index = 643005, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胩)*/
	{.bitmap_index = 643141, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胪)*/
	{.bitmap_index = 643269, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胫)*/
	{.bitmap_index = 643397, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胬)*/
	{.bitmap_index = 643533, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胭)*/
	{.bitmap_index = 643653, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胯)*/
	{.bitmap_index = 643789, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胰)*/
	{.bitmap_index = 643925, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胱)*/
	{.bitmap_index = 644053, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胲)*/
	{.bitmap_index = 644181, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胳)*/
	{.bitmap_index = 644309, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胴)*/
	{.bitmap_index = 644429, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胶)*/
	{.bitmap_index = 644557, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胸)*/
	{.bitmap_index = 644685, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(胺)*/
	{.bitmap_index = 644805, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(胼)*/
	{.bitmap_index = 644941, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(能)*/
	{.bitmap_index = 645069, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脂)*/
	{.bitmap_index = 645189, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脆)*/
	{.bitmap_index = 645325, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脉)*/
	{.bitmap_index = 645461, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脊)*/
	{.bitmap_index = 645589, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脍)*/
	{.bitmap_index = 645717, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脎)*/
	{.bitmap_index = 645845, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脏)*/
	{.bitmap_index = 645965, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脐)*/
	{.bitmap_index = 646101, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脑)*/
	{.bitmap_index = 646221, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脒)*/
	{.bitmap_index = 646341, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脓)*/
	{.bitmap_index = 646469, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脔)*/
	{.bitmap_index = 646605, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脖)*/
	{.bitmap_index = 646725, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脘)*/
	{.bitmap_index = 646861, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脚)*/
	{.bitmap_index = 646981, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脞)*/
	{.bitmap_index = 647101, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脬)*/
	{.bitmap_index = 647221, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脯)*/
	{.bitmap_index = 647357, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脱)*/
	{.bitmap_index = 647485, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(脲)*/
	{.bitmap_index = 647613, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脶)*/
	{.bitmap_index = 647733, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脸)*/
	{.bitmap_index = 647861, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(脾)*/
	{.bitmap_index = 647989, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腆)*/
	{.bitmap_index = 648117, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腈)*/
	{.bitmap_index = 648237, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腊)*/
	{.bitmap_index = 648357, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腋)*/
	{.bitmap_index = 648485, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腌)*/
	{.bitmap_index = 648613, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腐)*/
	{.bitmap_index = 648741, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腑)*/
	{.bitmap_index = 648869, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腓)*/
	{.bitmap_index = 648997, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腔)*/
	{.bitmap_index = 649125, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腕)*/
	{.bitmap_index = 649253, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腙)*/
	{.bitmap_index = 649389, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腚)*/
	{.bitmap_index = 649517, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腠)*/
	{.bitmap_index = 649645, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腥)*/
	{.bitmap_index = 649765, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腧)*/
	{.bitmap_index = 649893, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腩)*/
	{.bitmap_index = 650021, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腭)*/
	{.bitmap_index = 650141, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腮)*/
	{.bitmap_index = 650261, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腰)*/
	{.bitmap_index = 650389, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腱)*/
	{.bitmap_index = 650517, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腴)*/
	{.bitmap_index = 650645, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腹)*/
	{.bitmap_index = 650781, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腺)*/
	{.bitmap_index = 650909, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(腻)*/
	{.bitmap_index = 651037, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腼)*/
	{.bitmap_index = 651157, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腽)*/
	{.bitmap_index = 651277, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腾)*/
	{.bitmap_index = 651405, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(腿)*/
	{.bitmap_index = 651525, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膀)*/
	{.bitmap_index = 651661, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膂)*/
	{.bitmap_index = 651789, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膈)*/
	{.bitmap_index = 651909, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膊)*/
	{.bitmap_index = 652037, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膏)*/
	{.bitmap_index = 652165, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膑)*/
	{.bitmap_index = 652293, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膘)*/
	{.bitmap_index = 652413, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膛)*/
	{.bitmap_index = 652549, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膜)*/
	{.bitmap_index = 652685, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膝)*/
	{.bitmap_index = 652813, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膣)*/
	{.bitmap_index = 652941, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膦)*/
	{.bitmap_index = 653077, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膨)*/
	{.bitmap_index = 653205, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膪)*/
	{.bitmap_index = 653333, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(膳)*/
	{.bitmap_index = 653469, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膺)*/
	{.bitmap_index = 653597, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(膻)*/
	{.bitmap_index = 653725, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(臀)*/
	{.bitmap_index = 653845, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(臁)*/
	{.bitmap_index = 653981, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(臂)*/
	{.bitmap_index = 654109, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(臃)*/
	{.bitmap_index = 654237, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(臆)*/
	{.bitmap_index = 654365, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(臊)*/
	{.bitmap_index = 654485, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(臌)*/
	{.bitmap_index = 654613, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(臣)*/
	{.bitmap_index = 654718, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(臧)*/
	{.bitmap_index = 654854, .adv_w = 14, .box_h = 16, .box_w = 12, .ofs_x = 2, .ofs_y = 4},/*(自)*/
	{.bitmap_index = 654950, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(臬)*/
	{.bitmap_index = 655078, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(臭)*/
	{.bitmap_index = 655214, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(至)*/
	{.bitmap_index = 655334, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(致)*/
	{.bitmap_index = 655470, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(臻)*/
	{.bitmap_index = 655590, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(臼)*/
	{.bitmap_index = 655702, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(臾)*/
	{.bitmap_index = 655838, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(舀)*/
	{.bitmap_index = 655943, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舁)*/
	{.bitmap_index = 656079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舂)*/
	{.bitmap_index = 656207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舄)*/
	{.bitmap_index = 656335, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舅)*/
	{.bitmap_index = 656471, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舆)*/
	{.bitmap_index = 656607, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舌)*/
	{.bitmap_index = 656727, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舍)*/
	{.bitmap_index = 656855, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舐)*/
	{.bitmap_index = 656975, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舒)*/
	{.bitmap_index = 657103, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舔)*/
	{.bitmap_index = 657223, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舛)*/
	{.bitmap_index = 657351, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舜)*/
	{.bitmap_index = 657479, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舞)*/
	{.bitmap_index = 657615, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舟)*/
	{.bitmap_index = 657751, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舡)*/
	{.bitmap_index = 657887, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舢)*/
	{.bitmap_index = 658015, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舣)*/
	{.bitmap_index = 658151, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舨)*/
	{.bitmap_index = 658287, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(航)*/
	{.bitmap_index = 658415, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舫)*/
	{.bitmap_index = 658551, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(般)*/
	{.bitmap_index = 658687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舭)*/
	{.bitmap_index = 658815, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舯)*/
	{.bitmap_index = 658943, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舰)*/
	{.bitmap_index = 659079, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舱)*/
	{.bitmap_index = 659215, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舳)*/
	{.bitmap_index = 659351, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舴)*/
	{.bitmap_index = 659487, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舵)*/
	{.bitmap_index = 659615, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舶)*/
	{.bitmap_index = 659751, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舷)*/
	{.bitmap_index = 659887, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舸)*/
	{.bitmap_index = 660015, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(船)*/
	{.bitmap_index = 660143, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(舻)*/
	{.bitmap_index = 660279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(舾)*/
	{.bitmap_index = 660407, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艄)*/
	{.bitmap_index = 660543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艇)*/
	{.bitmap_index = 660671, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艉)*/
	{.bitmap_index = 660799, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艋)*/
	{.bitmap_index = 660935, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艏)*/
	{.bitmap_index = 661063, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艘)*/
	{.bitmap_index = 661199, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艚)*/
	{.bitmap_index = 661327, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艟)*/
	{.bitmap_index = 661455, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艨)*/
	{.bitmap_index = 661583, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(艮)*/
	{.bitmap_index = 661711, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(良)*/
	{.bitmap_index = 661847, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艰)*/
	{.bitmap_index = 661975, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(色)*/
	{.bitmap_index = 662103, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艳)*/
	{.bitmap_index = 662231, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艴)*/
	{.bitmap_index = 662367, .adv_w = 16, .box_h = 7, .box_w = 16, .ofs_x = 0, .ofs_y = 12},/*(艹)*/
	{.bitmap_index = 662423, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(艺)*/
	{.bitmap_index = 662551, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艽)*/
	{.bitmap_index = 662687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艾)*/
	{.bitmap_index = 662815, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(艿)*/
	{.bitmap_index = 662943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(节)*/
	{.bitmap_index = 663071, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芄)*/
	{.bitmap_index = 663199, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芈)*/
	{.bitmap_index = 663319, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芊)*/
	{.bitmap_index = 663447, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芋)*/
	{.bitmap_index = 663575, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芍)*/
	{.bitmap_index = 663703, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芎)*/
	{.bitmap_index = 663831, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(芏)*/
	{.bitmap_index = 663959, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芑)*/
	{.bitmap_index = 664079, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芒)*/
	{.bitmap_index = 664199, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芗)*/
	{.bitmap_index = 664335, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(芘)*/
	{.bitmap_index = 664455, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芙)*/
	{.bitmap_index = 664591, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芜)*/
	{.bitmap_index = 664727, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芝)*/
	{.bitmap_index = 664847, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芟)*/
	{.bitmap_index = 664983, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芡)*/
	{.bitmap_index = 665119, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芤)*/
	{.bitmap_index = 665247, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芥)*/
	{.bitmap_index = 665383, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芦)*/
	{.bitmap_index = 665511, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芨)*/
	{.bitmap_index = 665647, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芩)*/
	{.bitmap_index = 665783, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(芪)*/
	{.bitmap_index = 665911, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芫)*/
	{.bitmap_index = 666039, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芬)*/
	{.bitmap_index = 666175, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芭)*/
	{.bitmap_index = 666303, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芮)*/
	{.bitmap_index = 666431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芯)*/
	{.bitmap_index = 666559, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芰)*/
	{.bitmap_index = 666695, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(花)*/
	{.bitmap_index = 666823, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芳)*/
	{.bitmap_index = 666959, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芴)*/
	{.bitmap_index = 667095, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芷)*/
	{.bitmap_index = 667215, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芸)*/
	{.bitmap_index = 667343, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(芹)*/
	{.bitmap_index = 667479, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芽)*/
	{.bitmap_index = 667607, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(芾)*/
	{.bitmap_index = 667735, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苁)*/
	{.bitmap_index = 667855, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苄)*/
	{.bitmap_index = 667983, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苇)*/
	{.bitmap_index = 668111, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苈)*/
	{.bitmap_index = 668247, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苊)*/
	{.bitmap_index = 668375, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苋)*/
	{.bitmap_index = 668503, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苌)*/
	{.bitmap_index = 668639, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苍)*/
	{.bitmap_index = 668767, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苎)*/
	{.bitmap_index = 668895, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苏)*/
	{.bitmap_index = 669031, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苑)*/
	{.bitmap_index = 669167, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苒)*/
	{.bitmap_index = 669295, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苓)*/
	{.bitmap_index = 669431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苔)*/
	{.bitmap_index = 669559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苕)*/
	{.bitmap_index = 669687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苗)*/
	{.bitmap_index = 669815, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苘)*/
	{.bitmap_index = 669943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苛)*/
	{.bitmap_index = 670071, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苜)*/
	{.bitmap_index = 670199, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苞)*/
	{.bitmap_index = 670327, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苟)*/
	{.bitmap_index = 670455, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苠)*/
	{.bitmap_index = 670591, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(苡)*/
	{.bitmap_index = 670727, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苣)*/
	{.bitmap_index = 670847, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苤)*/
	{.bitmap_index = 670975, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(若)*/
	{.bitmap_index = 671095, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苦)*/
	{.bitmap_index = 671215, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苫)*/
	{.bitmap_index = 671335, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苯)*/
	{.bitmap_index = 671455, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(英)*/
	{.bitmap_index = 671583, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苴)*/
	{.bitmap_index = 671711, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苷)*/
	{.bitmap_index = 671831, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苹)*/
	{.bitmap_index = 671959, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(苻)*/
	{.bitmap_index = 672087, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茁)*/
	{.bitmap_index = 672215, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茂)*/
	{.bitmap_index = 672343, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(范)*/
	{.bitmap_index = 672471, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茄)*/
	{.bitmap_index = 672599, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茅)*/
	{.bitmap_index = 672727, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(茆)*/
	{.bitmap_index = 672846, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茇)*/
	{.bitmap_index = 672982, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茈)*/
	{.bitmap_index = 673102, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茉)*/
	{.bitmap_index = 673222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茌)*/
	{.bitmap_index = 673350, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茎)*/
	{.bitmap_index = 673478, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茏)*/
	{.bitmap_index = 673598, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茑)*/
	{.bitmap_index = 673726, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茔)*/
	{.bitmap_index = 673854, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茕)*/
	{.bitmap_index = 673982, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茗)*/
	{.bitmap_index = 674110, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茚)*/
	{.bitmap_index = 674238, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茛)*/
	{.bitmap_index = 674374, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(茜)*/
	{.bitmap_index = 674486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茧)*/
	{.bitmap_index = 674614, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茨)*/
	{.bitmap_index = 674750, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茫)*/
	{.bitmap_index = 674878, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茬)*/
	{.bitmap_index = 675006, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茭)*/
	{.bitmap_index = 675134, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茯)*/
	{.bitmap_index = 675270, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茱)*/
	{.bitmap_index = 675398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茳)*/
	{.bitmap_index = 675526, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茴)*/
	{.bitmap_index = 675654, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茵)*/
	{.bitmap_index = 675782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茶)*/
	{.bitmap_index = 675910, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茸)*/
	{.bitmap_index = 676030, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茹)*/
	{.bitmap_index = 676166, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(茺)*/
	{.bitmap_index = 676302, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(茼)*/
	{.bitmap_index = 676430, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荀)*/
	{.bitmap_index = 676558, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荃)*/
	{.bitmap_index = 676678, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荆)*/
	{.bitmap_index = 676806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荇)*/
	{.bitmap_index = 676934, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(草)*/
	{.bitmap_index = 677062, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荏)*/
	{.bitmap_index = 677190, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荐)*/
	{.bitmap_index = 677318, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荑)*/
	{.bitmap_index = 677454, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荒)*/
	{.bitmap_index = 677590, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荔)*/
	{.bitmap_index = 677726, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荚)*/
	{.bitmap_index = 677854, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荛)*/
	{.bitmap_index = 677990, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荜)*/
	{.bitmap_index = 678118, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荞)*/
	{.bitmap_index = 678254, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荟)*/
	{.bitmap_index = 678390, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荠)*/
	{.bitmap_index = 678526, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荡)*/
	{.bitmap_index = 678662, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荣)*/
	{.bitmap_index = 678790, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荤)*/
	{.bitmap_index = 678918, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荥)*/
	{.bitmap_index = 679046, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荦)*/
	{.bitmap_index = 679174, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荧)*/
	{.bitmap_index = 679302, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荨)*/
	{.bitmap_index = 679430, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荩)*/
	{.bitmap_index = 679566, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荪)*/
	{.bitmap_index = 679694, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荫)*/
	{.bitmap_index = 679830, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荬)*/
	{.bitmap_index = 679966, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荭)*/
	{.bitmap_index = 680086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荮)*/
	{.bitmap_index = 680214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(药)*/
	{.bitmap_index = 680342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荷)*/
	{.bitmap_index = 680470, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荸)*/
	{.bitmap_index = 680598, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荻)*/
	{.bitmap_index = 680734, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(荼)*/
	{.bitmap_index = 680862, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(荽)*/
	{.bitmap_index = 680998, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莅)*/
	{.bitmap_index = 681126, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莆)*/
	{.bitmap_index = 681254, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莉)*/
	{.bitmap_index = 681374, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莎)*/
	{.bitmap_index = 681510, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莒)*/
	{.bitmap_index = 681630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莓)*/
	{.bitmap_index = 681758, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莘)*/
	{.bitmap_index = 681878, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莛)*/
	{.bitmap_index = 682014, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莜)*/
	{.bitmap_index = 682150, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莞)*/
	{.bitmap_index = 682286, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莠)*/
	{.bitmap_index = 682422, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莨)*/
	{.bitmap_index = 682558, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莩)*/
	{.bitmap_index = 682686, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莪)*/
	{.bitmap_index = 682814, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莫)*/
	{.bitmap_index = 682950, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莰)*/
	{.bitmap_index = 683086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莱)*/
	{.bitmap_index = 683214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莲)*/
	{.bitmap_index = 683342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莳)*/
	{.bitmap_index = 683470, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(莴)*/
	{.bitmap_index = 683582, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莶)*/
	{.bitmap_index = 683710, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(获)*/
	{.bitmap_index = 683846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莸)*/
	{.bitmap_index = 683974, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莹)*/
	{.bitmap_index = 684094, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莺)*/
	{.bitmap_index = 684222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(莼)*/
	{.bitmap_index = 684350, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(莽)*/
	{.bitmap_index = 684486, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菀)*/
	{.bitmap_index = 684622, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菁)*/
	{.bitmap_index = 684742, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(菅)*/
	{.bitmap_index = 684854, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菇)*/
	{.bitmap_index = 684982, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菊)*/
	{.bitmap_index = 685110, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菌)*/
	{.bitmap_index = 685238, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菏)*/
	{.bitmap_index = 685366, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菔)*/
	{.bitmap_index = 685502, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菖)*/
	{.bitmap_index = 685630, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菘)*/
	{.bitmap_index = 685758, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菜)*/
	{.bitmap_index = 685886, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菝)*/
	{.bitmap_index = 686014, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菟)*/
	{.bitmap_index = 686150, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菠)*/
	{.bitmap_index = 686278, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(菡)*/
	{.bitmap_index = 686383, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菥)*/
	{.bitmap_index = 686519, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菩)*/
	{.bitmap_index = 686647, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菪)*/
	{.bitmap_index = 686775, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菰)*/
	{.bitmap_index = 686903, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菱)*/
	{.bitmap_index = 687031, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菲)*/
	{.bitmap_index = 687151, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菸)*/
	{.bitmap_index = 687287, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(菹)*/
	{.bitmap_index = 687415, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(菽)*/
	{.bitmap_index = 687543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萁)*/
	{.bitmap_index = 687671, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萃)*/
	{.bitmap_index = 687799, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萄)*/
	{.bitmap_index = 687927, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萆)*/
	{.bitmap_index = 688047, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萋)*/
	{.bitmap_index = 688175, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萌)*/
	{.bitmap_index = 688311, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萍)*/
	{.bitmap_index = 688439, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萎)*/
	{.bitmap_index = 688567, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萏)*/
	{.bitmap_index = 688695, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萑)*/
	{.bitmap_index = 688815, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萘)*/
	{.bitmap_index = 688943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萜)*/
	{.bitmap_index = 689071, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萝)*/
	{.bitmap_index = 689207, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(萤)*/
	{.bitmap_index = 689343, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(营)*/
	{.bitmap_index = 689471, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萦)*/
	{.bitmap_index = 689599, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萧)*/
	{.bitmap_index = 689735, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萨)*/
	{.bitmap_index = 689863, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萱)*/
	{.bitmap_index = 689991, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(萸)*/
	{.bitmap_index = 690127, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(萼)*/
	{.bitmap_index = 690255, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(落)*/
	{.bitmap_index = 690383, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葆)*/
	{.bitmap_index = 690511, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葑)*/
	{.bitmap_index = 690639, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(著)*/
	{.bitmap_index = 690767, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葙)*/
	{.bitmap_index = 690895, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葚)*/
	{.bitmap_index = 691015, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葛)*/
	{.bitmap_index = 691143, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(葜)*/
	{.bitmap_index = 691279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葡)*/
	{.bitmap_index = 691407, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(董)*/
	{.bitmap_index = 691527, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(葩)*/
	{.bitmap_index = 691655, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(葫)*/
	{.bitmap_index = 691791, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(葬)*/
	{.bitmap_index = 691927, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(葭)*/
	{.bitmap_index = 692055, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葱)*/
	{.bitmap_index = 692175, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(葳)*/
	{.bitmap_index = 692311, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(葵)*/
	{.bitmap_index = 692447, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葶)*/
	{.bitmap_index = 692575, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葸)*/
	{.bitmap_index = 692703, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(葺)*/
	{.bitmap_index = 692823, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒂)*/
	{.bitmap_index = 692951, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒇)*/
	{.bitmap_index = 693087, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒈)*/
	{.bitmap_index = 693215, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒉)*/
	{.bitmap_index = 693351, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒋)*/
	{.bitmap_index = 693479, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒌)*/
	{.bitmap_index = 693615, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒎)*/
	{.bitmap_index = 693743, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒗)*/
	{.bitmap_index = 693879, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒙)*/
	{.bitmap_index = 694015, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒜)*/
	{.bitmap_index = 694143, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒡)*/
	{.bitmap_index = 694279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒯)*/
	{.bitmap_index = 694407, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒲)*/
	{.bitmap_index = 694535, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒴)*/
	{.bitmap_index = 694671, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒸)*/
	{.bitmap_index = 694799, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒹)*/
	{.bitmap_index = 694927, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蒺)*/
	{.bitmap_index = 695063, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒽)*/
	{.bitmap_index = 695191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蒿)*/
	{.bitmap_index = 695319, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓁)*/
	{.bitmap_index = 695447, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓄)*/
	{.bitmap_index = 695575, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓉)*/
	{.bitmap_index = 695703, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓊)*/
	{.bitmap_index = 695831, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓍)*/
	{.bitmap_index = 695959, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓐)*/
	{.bitmap_index = 696087, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蓑)*/
	{.bitmap_index = 696223, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓓)*/
	{.bitmap_index = 696351, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓖)*/
	{.bitmap_index = 696479, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓝)*/
	{.bitmap_index = 696599, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓟)*/
	{.bitmap_index = 696727, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(蓠)*/
	{.bitmap_index = 696839, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蓣)*/
	{.bitmap_index = 696975, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓥)*/
	{.bitmap_index = 697103, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓦)*/
	{.bitmap_index = 697231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓬)*/
	{.bitmap_index = 697359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蓰)*/
	{.bitmap_index = 697487, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蓼)*/
	{.bitmap_index = 697615, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蓿)*/
	{.bitmap_index = 697743, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔌)*/
	{.bitmap_index = 697879, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔑)*/
	{.bitmap_index = 698015, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔓)*/
	{.bitmap_index = 698151, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔗)*/
	{.bitmap_index = 698287, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蔚)*/
	{.bitmap_index = 698415, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔟)*/
	{.bitmap_index = 698551, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蔡)*/
	{.bitmap_index = 698679, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蔫)*/
	{.bitmap_index = 698807, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔬)*/
	{.bitmap_index = 698943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蔷)*/
	{.bitmap_index = 699071, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔸)*/
	{.bitmap_index = 699199, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔹)*/
	{.bitmap_index = 699335, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蔺)*/
	{.bitmap_index = 699455, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蔻)*/
	{.bitmap_index = 699591, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蔼)*/
	{.bitmap_index = 699719, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(蔽)*/
	{.bitmap_index = 699855, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕃)*/
	{.bitmap_index = 699983, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕈)*/
	{.bitmap_index = 700111, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蕉)*/
	{.bitmap_index = 700247, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕊)*/
	{.bitmap_index = 700375, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕖)*/
	{.bitmap_index = 700503, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕙)*/
	{.bitmap_index = 700631, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕞)*/
	{.bitmap_index = 700759, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕤)*/
	{.bitmap_index = 700879, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蕨)*/
	{.bitmap_index = 701015, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蕲)*/
	{.bitmap_index = 701151, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕴)*/
	{.bitmap_index = 701279, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蕹)*/
	{.bitmap_index = 701415, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蕺)*/
	{.bitmap_index = 701535, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蕻)*/
	{.bitmap_index = 701671, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(蕾)*/
	{.bitmap_index = 701783, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薄)*/
	{.bitmap_index = 701911, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(薅)*/
	{.bitmap_index = 702039, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(薇)*/
	{.bitmap_index = 702175, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薏)*/
	{.bitmap_index = 702303, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薛)*/
	{.bitmap_index = 702431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薜)*/
	{.bitmap_index = 702559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(薤)*/
	{.bitmap_index = 702687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薨)*/
	{.bitmap_index = 702815, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(薪)*/
	{.bitmap_index = 702951, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(薮)*/
	{.bitmap_index = 703087, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薯)*/
	{.bitmap_index = 703215, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(薰)*/
	{.bitmap_index = 703351, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(薷)*/
	{.bitmap_index = 703479, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(薹)*/
	{.bitmap_index = 703591, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藁)*/
	{.bitmap_index = 703719, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藉)*/
	{.bitmap_index = 703847, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(藏)*/
	{.bitmap_index = 703983, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(藐)*/
	{.bitmap_index = 704119, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藓)*/
	{.bitmap_index = 704239, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藕)*/
	{.bitmap_index = 704367, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藜)*/
	{.bitmap_index = 704495, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藤)*/
	{.bitmap_index = 704615, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藩)*/
	{.bitmap_index = 704743, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藻)*/
	{.bitmap_index = 704871, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(藿)*/
	{.bitmap_index = 704999, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蘅)*/
	{.bitmap_index = 705127, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蘑)*/
	{.bitmap_index = 705247, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蘖)*/
	{.bitmap_index = 705375, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蘧)*/
	{.bitmap_index = 705503, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蘩)*/
	{.bitmap_index = 705631, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蘸)*/
	{.bitmap_index = 705767, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蘼)*/
	{.bitmap_index = 705895, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虍)*/
	{.bitmap_index = 706023, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虎)*/
	{.bitmap_index = 706159, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虏)*/
	{.bitmap_index = 706295, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虐)*/
	{.bitmap_index = 706431, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虑)*/
	{.bitmap_index = 706567, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虔)*/
	{.bitmap_index = 706703, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虚)*/
	{.bitmap_index = 706839, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虞)*/
	{.bitmap_index = 706975, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虢)*/
	{.bitmap_index = 707103, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(虫)*/
	{.bitmap_index = 707231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虬)*/
	{.bitmap_index = 707359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虮)*/
	{.bitmap_index = 707487, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虱)*/
	{.bitmap_index = 707615, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虹)*/
	{.bitmap_index = 707743, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虺)*/
	{.bitmap_index = 707871, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虻)*/
	{.bitmap_index = 707999, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虼)*/
	{.bitmap_index = 708127, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虽)*/
	{.bitmap_index = 708255, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(虾)*/
	{.bitmap_index = 708383, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(虿)*/
	{.bitmap_index = 708511, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚀)*/
	{.bitmap_index = 708639, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚁)*/
	{.bitmap_index = 708775, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚂)*/
	{.bitmap_index = 708895, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚊)*/
	{.bitmap_index = 709023, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚋)*/
	{.bitmap_index = 709143, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚌)*/
	{.bitmap_index = 709271, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚍)*/
	{.bitmap_index = 709399, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚓)*/
	{.bitmap_index = 709527, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚕)*/
	{.bitmap_index = 709655, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚜)*/
	{.bitmap_index = 709783, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚝)*/
	{.bitmap_index = 709911, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚣)*/
	{.bitmap_index = 710039, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚤)*/
	{.bitmap_index = 710167, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚧)*/
	{.bitmap_index = 710303, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚨)*/
	{.bitmap_index = 710439, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚩)*/
	{.bitmap_index = 710575, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚪)*/
	{.bitmap_index = 710703, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚬)*/
	{.bitmap_index = 710839, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚯)*/
	{.bitmap_index = 710967, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚰)*/
	{.bitmap_index = 711095, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚱)*/
	{.bitmap_index = 711223, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蚴)*/
	{.bitmap_index = 711351, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚵)*/
	{.bitmap_index = 711471, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚶)*/
	{.bitmap_index = 711591, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蚺)*/
	{.bitmap_index = 711711, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛀)*/
	{.bitmap_index = 711839, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛄)*/
	{.bitmap_index = 711959, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛆)*/
	{.bitmap_index = 712079, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛇)*/
	{.bitmap_index = 712199, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛉)*/
	{.bitmap_index = 712335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛊)*/
	{.bitmap_index = 712463, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛋)*/
	{.bitmap_index = 712591, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛎)*/
	{.bitmap_index = 712727, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛏)*/
	{.bitmap_index = 712855, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛐)*/
	{.bitmap_index = 712975, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛑)*/
	{.bitmap_index = 713103, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛔)*/
	{.bitmap_index = 713231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛘)*/
	{.bitmap_index = 713359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛙)*/
	{.bitmap_index = 713487, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛛)*/
	{.bitmap_index = 713615, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛞)*/
	{.bitmap_index = 713735, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛟)*/
	{.bitmap_index = 713863, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛤)*/
	{.bitmap_index = 713991, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛩)*/
	{.bitmap_index = 714119, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛭)*/
	{.bitmap_index = 714239, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛮)*/
	{.bitmap_index = 714367, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛰)*/
	{.bitmap_index = 714495, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛱)*/
	{.bitmap_index = 714623, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛲)*/
	{.bitmap_index = 714751, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛳)*/
	{.bitmap_index = 714879, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蛴)*/
	{.bitmap_index = 715015, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛸)*/
	{.bitmap_index = 715143, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛹)*/
	{.bitmap_index = 715271, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蛾)*/
	{.bitmap_index = 715399, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜀)*/
	{.bitmap_index = 715527, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜂)*/
	{.bitmap_index = 715655, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜃)*/
	{.bitmap_index = 715783, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜇)*/
	{.bitmap_index = 715911, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜈)*/
	{.bitmap_index = 716039, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜉)*/
	{.bitmap_index = 716167, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜊)*/
	{.bitmap_index = 716287, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜍)*/
	{.bitmap_index = 716415, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜒)*/
	{.bitmap_index = 716543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜓)*/
	{.bitmap_index = 716671, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜕)*/
	{.bitmap_index = 716807, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜗)*/
	{.bitmap_index = 716927, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜘)*/
	{.bitmap_index = 717055, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(蜚)*/
	{.bitmap_index = 717183, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜜)*/
	{.bitmap_index = 717319, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜞)*/
	{.bitmap_index = 717455, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜡)*/
	{.bitmap_index = 717575, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜢)*/
	{.bitmap_index = 717695, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜣)*/
	{.bitmap_index = 717831, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜥)*/
	{.bitmap_index = 717951, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜩)*/
	{.bitmap_index = 718071, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜮)*/
	{.bitmap_index = 718207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜱)*/
	{.bitmap_index = 718335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蜴)*/
	{.bitmap_index = 718463, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜷)*/
	{.bitmap_index = 718591, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜻)*/
	{.bitmap_index = 718711, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜾)*/
	{.bitmap_index = 718831, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蜿)*/
	{.bitmap_index = 718959, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝇)*/
	{.bitmap_index = 719079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝈)*/
	{.bitmap_index = 719207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝉)*/
	{.bitmap_index = 719335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝌)*/
	{.bitmap_index = 719463, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝎)*/
	{.bitmap_index = 719583, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝓)*/
	{.bitmap_index = 719711, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝗)*/
	{.bitmap_index = 719839, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝙)*/
	{.bitmap_index = 719967, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝠)*/
	{.bitmap_index = 720095, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蝣)*/
	{.bitmap_index = 720231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝤)*/
	{.bitmap_index = 720359, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蝥)*/
	{.bitmap_index = 720495, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蝮)*/
	{.bitmap_index = 720631, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝰)*/
	{.bitmap_index = 720759, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蝴)*/
	{.bitmap_index = 720887, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝶)*/
	{.bitmap_index = 721015, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝻)*/
	{.bitmap_index = 721143, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蝼)*/
	{.bitmap_index = 721279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝽)*/
	{.bitmap_index = 721407, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蝾)*/
	{.bitmap_index = 721535, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螂)*/
	{.bitmap_index = 721663, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(螃)*/
	{.bitmap_index = 721799, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螅)*/
	{.bitmap_index = 721927, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螈)*/
	{.bitmap_index = 722047, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(螋)*/
	{.bitmap_index = 722183, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(融)*/
	{.bitmap_index = 722303, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螓)*/
	{.bitmap_index = 722431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螗)*/
	{.bitmap_index = 722559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(螟)*/
	{.bitmap_index = 722687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螨)*/
	{.bitmap_index = 722815, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(螫)*/
	{.bitmap_index = 722951, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螬)*/
	{.bitmap_index = 723079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螭)*/
	{.bitmap_index = 723207, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(螯)*/
	{.bitmap_index = 723343, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螳)*/
	{.bitmap_index = 723471, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螵)*/
	{.bitmap_index = 723591, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(螺)*/
	{.bitmap_index = 723711, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(螽)*/
	{.bitmap_index = 723847, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟀)*/
	{.bitmap_index = 723975, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蟆)*/
	{.bitmap_index = 724111, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟊)*/
	{.bitmap_index = 724231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟋)*/
	{.bitmap_index = 724359, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蟑)*/
	{.bitmap_index = 724495, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蟒)*/
	{.bitmap_index = 724631, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟓)*/
	{.bitmap_index = 724759, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蟛)*/
	{.bitmap_index = 724895, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟠)*/
	{.bitmap_index = 725023, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蟥)*/
	{.bitmap_index = 725151, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟪)*/
	{.bitmap_index = 725279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟮)*/
	{.bitmap_index = 725407, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蟹)*/
	{.bitmap_index = 725543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蟾)*/
	{.bitmap_index = 725671, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠃)*/
	{.bitmap_index = 725807, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠊)*/
	{.bitmap_index = 725943, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠓)*/
	{.bitmap_index = 726079, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蠕)*/
	{.bitmap_index = 726199, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠖)*/
	{.bitmap_index = 726335, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠛)*/
	{.bitmap_index = 726471, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蠡)*/
	{.bitmap_index = 726599, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠢)*/
	{.bitmap_index = 726735, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蠲)*/
	{.bitmap_index = 726863, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠹)*/
	{.bitmap_index = 726999, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蠼)*/
	{.bitmap_index = 727135, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(血)*/
	{.bitmap_index = 727263, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衄)*/
	{.bitmap_index = 727391, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衅)*/
	{.bitmap_index = 727519, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(行)*/
	{.bitmap_index = 727639, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衍)*/
	{.bitmap_index = 727767, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衔)*/
	{.bitmap_index = 727895, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(街)*/
	{.bitmap_index = 728031, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衙)*/
	{.bitmap_index = 728159, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衡)*/
	{.bitmap_index = 728287, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衢)*/
	{.bitmap_index = 728415, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衣)*/
	{.bitmap_index = 728543, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(衤)*/
	{.bitmap_index = 728623, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(补)*/
	{.bitmap_index = 728743, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(表)*/
	{.bitmap_index = 728871, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衩)*/
	{.bitmap_index = 729007, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衫)*/
	{.bitmap_index = 729143, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衬)*/
	{.bitmap_index = 729263, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衮)*/
	{.bitmap_index = 729399, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衰)*/
	{.bitmap_index = 729527, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衲)*/
	{.bitmap_index = 729647, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衷)*/
	{.bitmap_index = 729783, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(衽)*/
	{.bitmap_index = 729911, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衾)*/
	{.bitmap_index = 730047, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(衿)*/
	{.bitmap_index = 730183, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袁)*/
	{.bitmap_index = 730319, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袂)*/
	{.bitmap_index = 730447, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袄)*/
	{.bitmap_index = 730583, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袅)*/
	{.bitmap_index = 730719, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袈)*/
	{.bitmap_index = 730855, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袋)*/
	{.bitmap_index = 730991, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袍)*/
	{.bitmap_index = 731119, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袒)*/
	{.bitmap_index = 731239, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袖)*/
	{.bitmap_index = 731367, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袜)*/
	{.bitmap_index = 731495, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袢)*/
	{.bitmap_index = 731623, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袤)*/
	{.bitmap_index = 731759, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(被)*/
	{.bitmap_index = 731887, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(袭)*/
	{.bitmap_index = 732023, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袱)*/
	{.bitmap_index = 732151, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袷)*/
	{.bitmap_index = 732279, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(袼)*/
	{.bitmap_index = 732407, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裁)*/
	{.bitmap_index = 732535, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裂)*/
	{.bitmap_index = 732663, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(装)*/
	{.bitmap_index = 732799, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裆)*/
	{.bitmap_index = 732919, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裉)*/
	{.bitmap_index = 733047, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裎)*/
	{.bitmap_index = 733175, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裒)*/
	{.bitmap_index = 733311, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裔)*/
	{.bitmap_index = 733439, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裕)*/
	{.bitmap_index = 733559, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裘)*/
	{.bitmap_index = 733695, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裙)*/
	{.bitmap_index = 733815, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裟)*/
	{.bitmap_index = 733951, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裢)*/
	{.bitmap_index = 734079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裣)*/
	{.bitmap_index = 734207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裤)*/
	{.bitmap_index = 734335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裥)*/
	{.bitmap_index = 734463, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裨)*/
	{.bitmap_index = 734591, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裰)*/
	{.bitmap_index = 734719, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裱)*/
	{.bitmap_index = 734855, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裳)*/
	{.bitmap_index = 734991, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裴)*/
	{.bitmap_index = 735119, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裸)*/
	{.bitmap_index = 735239, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裹)*/
	{.bitmap_index = 735375, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(裼)*/
	{.bitmap_index = 735503, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(裾)*/
	{.bitmap_index = 735623, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褂)*/
	{.bitmap_index = 735751, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褊)*/
	{.bitmap_index = 735879, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褐)*/
	{.bitmap_index = 735999, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(褒)*/
	{.bitmap_index = 736135, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褓)*/
	{.bitmap_index = 736263, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褙)*/
	{.bitmap_index = 736391, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褚)*/
	{.bitmap_index = 736519, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(褛)*/
	{.bitmap_index = 736655, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褡)*/
	{.bitmap_index = 736783, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褥)*/
	{.bitmap_index = 736903, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褪)*/
	{.bitmap_index = 737031, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褫)*/
	{.bitmap_index = 737159, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褰)*/
	{.bitmap_index = 737287, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褴)*/
	{.bitmap_index = 737415, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(褶)*/
	{.bitmap_index = 737543, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(襁)*/
	{.bitmap_index = 737671, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(襄)*/
	{.bitmap_index = 737807, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(襞)*/
	{.bitmap_index = 737943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(襟)*/
	{.bitmap_index = 738071, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(襦)*/
	{.bitmap_index = 738191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(襻)*/
	{.bitmap_index = 738319, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(西)*/
	{.bitmap_index = 738424, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(要)*/
	{.bitmap_index = 738552, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(覃)*/
	{.bitmap_index = 738672, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(覆)*/
	{.bitmap_index = 738800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(见)*/
	{.bitmap_index = 738928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(观)*/
	{.bitmap_index = 739056, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(规)*/
	{.bitmap_index = 739184, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觅)*/
	{.bitmap_index = 739312, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(视)*/
	{.bitmap_index = 739448, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(觇)*/
	{.bitmap_index = 739576, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(览)*/
	{.bitmap_index = 739712, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觉)*/
	{.bitmap_index = 739848, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(觊)*/
	{.bitmap_index = 739984, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觋)*/
	{.bitmap_index = 740112, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觌)*/
	{.bitmap_index = 740248, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觎)*/
	{.bitmap_index = 740376, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觏)*/
	{.bitmap_index = 740496, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觐)*/
	{.bitmap_index = 740616, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觑)*/
	{.bitmap_index = 740744, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(角)*/
	{.bitmap_index = 740880, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觖)*/
	{.bitmap_index = 741016, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觚)*/
	{.bitmap_index = 741144, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觜)*/
	{.bitmap_index = 741272, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觞)*/
	{.bitmap_index = 741408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(解)*/
	{.bitmap_index = 741536, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觥)*/
	{.bitmap_index = 741672, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(触)*/
	{.bitmap_index = 741800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觫)*/
	{.bitmap_index = 741928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(觯)*/
	{.bitmap_index = 742056, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(觳)*/
	{.bitmap_index = 742192, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(言)*/
	{.bitmap_index = 742312, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(訇)*/
	{.bitmap_index = 742424, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(訾)*/
	{.bitmap_index = 742544, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(詈)*/
	{.bitmap_index = 742664, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(詹)*/
	{.bitmap_index = 742800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(誉)*/
	{.bitmap_index = 742928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(誊)*/
	{.bitmap_index = 743056, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(誓)*/
	{.bitmap_index = 743184, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(謇)*/
	{.bitmap_index = 743312, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(謦)*/
	{.bitmap_index = 743440, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(警)*/
	{.bitmap_index = 743568, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(譬)*/
	{.bitmap_index = 743696, .adv_w = 9, .box_h = 16, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(讠)*/
	{.bitmap_index = 743760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(计)*/
	{.bitmap_index = 743888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(订)*/
	{.bitmap_index = 744016, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讣)*/
	{.bitmap_index = 744136, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(认)*/
	{.bitmap_index = 744264, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(讥)*/
	{.bitmap_index = 744392, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讦)*/
	{.bitmap_index = 744520, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讧)*/
	{.bitmap_index = 744640, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讨)*/
	{.bitmap_index = 744760, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(让)*/
	{.bitmap_index = 744880, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讪)*/
	{.bitmap_index = 745000, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讫)*/
	{.bitmap_index = 745128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(训)*/
	{.bitmap_index = 745256, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(议)*/
	{.bitmap_index = 745392, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讯)*/
	{.bitmap_index = 745512, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(记)*/
	{.bitmap_index = 745632, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(讲)*/
	{.bitmap_index = 745760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讳)*/
	{.bitmap_index = 745888, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讴)*/
	{.bitmap_index = 746008, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讵)*/
	{.bitmap_index = 746136, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讶)*/
	{.bitmap_index = 746256, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讷)*/
	{.bitmap_index = 746376, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(许)*/
	{.bitmap_index = 746504, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讹)*/
	{.bitmap_index = 746632, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(论)*/
	{.bitmap_index = 746760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讼)*/
	{.bitmap_index = 746888, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(讽)*/
	{.bitmap_index = 747008, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(设)*/
	{.bitmap_index = 747136, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(访)*/
	{.bitmap_index = 747256, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诀)*/
	{.bitmap_index = 747392, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(证)*/
	{.bitmap_index = 747512, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诂)*/
	{.bitmap_index = 747632, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诃)*/
	{.bitmap_index = 747752, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(评)*/
	{.bitmap_index = 747872, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诅)*/
	{.bitmap_index = 748000, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(识)*/
	{.bitmap_index = 748128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诈)*/
	{.bitmap_index = 748256, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诉)*/
	{.bitmap_index = 748376, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诊)*/
	{.bitmap_index = 748512, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诋)*/
	{.bitmap_index = 748640, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诌)*/
	{.bitmap_index = 748768, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(词)*/
	{.bitmap_index = 748896, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诎)*/
	{.bitmap_index = 749024, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诏)*/
	{.bitmap_index = 749144, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(译)*/
	{.bitmap_index = 749272, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诒)*/
	{.bitmap_index = 749400, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诓)*/
	{.bitmap_index = 749520, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诔)*/
	{.bitmap_index = 749648, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(试)*/
	{.bitmap_index = 749776, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诖)*/
	{.bitmap_index = 749896, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诗)*/
	{.bitmap_index = 750016, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诘)*/
	{.bitmap_index = 750136, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诙)*/
	{.bitmap_index = 750272, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诚)*/
	{.bitmap_index = 750408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诛)*/
	{.bitmap_index = 750536, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诜)*/
	{.bitmap_index = 750672, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(话)*/
	{.bitmap_index = 750792, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诞)*/
	{.bitmap_index = 750912, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诟)*/
	{.bitmap_index = 751040, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诠)*/
	{.bitmap_index = 751168, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诡)*/
	{.bitmap_index = 751304, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(询)*/
	{.bitmap_index = 751432, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诣)*/
	{.bitmap_index = 751560, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诤)*/
	{.bitmap_index = 751688, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(该)*/
	{.bitmap_index = 751816, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(详)*/
	{.bitmap_index = 751944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诧)*/
	{.bitmap_index = 752072, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诨)*/
	{.bitmap_index = 752192, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诩)*/
	{.bitmap_index = 752312, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诫)*/
	{.bitmap_index = 752440, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诬)*/
	{.bitmap_index = 752560, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(语)*/
	{.bitmap_index = 752680, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诮)*/
	{.bitmap_index = 752808, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(误)*/
	{.bitmap_index = 752936, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诰)*/
	{.bitmap_index = 753056, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诱)*/
	{.bitmap_index = 753184, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诲)*/
	{.bitmap_index = 753312, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诳)*/
	{.bitmap_index = 753432, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(说)*/
	{.bitmap_index = 753568, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诵)*/
	{.bitmap_index = 753688, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诶)*/
	{.bitmap_index = 753824, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(请)*/
	{.bitmap_index = 753944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诸)*/
	{.bitmap_index = 754072, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诹)*/
	{.bitmap_index = 754192, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诺)*/
	{.bitmap_index = 754320, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(读)*/
	{.bitmap_index = 754456, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诼)*/
	{.bitmap_index = 754576, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(诽)*/
	{.bitmap_index = 754696, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(课)*/
	{.bitmap_index = 754816, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(诿)*/
	{.bitmap_index = 754944, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谀)*/
	{.bitmap_index = 755080, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谁)*/
	{.bitmap_index = 755208, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谂)*/
	{.bitmap_index = 755336, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(调)*/
	{.bitmap_index = 755456, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谄)*/
	{.bitmap_index = 755584, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谅)*/
	{.bitmap_index = 755712, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谆)*/
	{.bitmap_index = 755832, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谇)*/
	{.bitmap_index = 755960, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谈)*/
	{.bitmap_index = 756088, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谊)*/
	{.bitmap_index = 756216, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谋)*/
	{.bitmap_index = 756336, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谌)*/
	{.bitmap_index = 756456, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谍)*/
	{.bitmap_index = 756584, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谎)*/
	{.bitmap_index = 756720, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谏)*/
	{.bitmap_index = 756840, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谐)*/
	{.bitmap_index = 756960, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谑)*/
	{.bitmap_index = 757096, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谒)*/
	{.bitmap_index = 757216, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谓)*/
	{.bitmap_index = 757336, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谔)*/
	{.bitmap_index = 757456, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谕)*/
	{.bitmap_index = 757584, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谖)*/
	{.bitmap_index = 757712, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谗)*/
	{.bitmap_index = 757848, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谘)*/
	{.bitmap_index = 757976, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谙)*/
	{.bitmap_index = 758104, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谚)*/
	{.bitmap_index = 758240, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谛)*/
	{.bitmap_index = 758368, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谜)*/
	{.bitmap_index = 758488, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谝)*/
	{.bitmap_index = 758616, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谟)*/
	{.bitmap_index = 758752, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谠)*/
	{.bitmap_index = 758888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谡)*/
	{.bitmap_index = 759016, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谢)*/
	{.bitmap_index = 759136, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谣)*/
	{.bitmap_index = 759256, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谤)*/
	{.bitmap_index = 759392, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谥)*/
	{.bitmap_index = 759520, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谦)*/
	{.bitmap_index = 759648, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谧)*/
	{.bitmap_index = 759776, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谨)*/
	{.bitmap_index = 759896, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谩)*/
	{.bitmap_index = 760024, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谪)*/
	{.bitmap_index = 760152, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谫)*/
	{.bitmap_index = 760288, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谬)*/
	{.bitmap_index = 760416, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谭)*/
	{.bitmap_index = 760536, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谮)*/
	{.bitmap_index = 760656, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谯)*/
	{.bitmap_index = 760784, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谰)*/
	{.bitmap_index = 760912, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谱)*/
	{.bitmap_index = 761040, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谲)*/
	{.bitmap_index = 761160, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谳)*/
	{.bitmap_index = 761288, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谴)*/
	{.bitmap_index = 761408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谵)*/
	{.bitmap_index = 761536, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(谶)*/
	{.bitmap_index = 761672, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(谷)*/
	{.bitmap_index = 761792, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豁)*/
	{.bitmap_index = 761920, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豆)*/
	{.bitmap_index = 762040, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豇)*/
	{.bitmap_index = 762160, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(豉)*/
	{.bitmap_index = 762296, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豌)*/
	{.bitmap_index = 762424, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豕)*/
	{.bitmap_index = 762544, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豚)*/
	{.bitmap_index = 762664, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(象)*/
	{.bitmap_index = 762792, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豢)*/
	{.bitmap_index = 762920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豪)*/
	{.bitmap_index = 763048, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豫)*/
	{.bitmap_index = 763176, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(豳)*/
	{.bitmap_index = 763281, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(豸)*/
	{.bitmap_index = 763393, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豹)*/
	{.bitmap_index = 763521, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(豺)*/
	{.bitmap_index = 763649, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(貂)*/
	{.bitmap_index = 763777, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(貅)*/
	{.bitmap_index = 763905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(貉)*/
	{.bitmap_index = 764033, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(貊)*/
	{.bitmap_index = 764161, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(貌)*/
	{.bitmap_index = 764297, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(貔)*/
	{.bitmap_index = 764425, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(貘)*/
	{.bitmap_index = 764561, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(贝)*/
	{.bitmap_index = 764673, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贞)*/
	{.bitmap_index = 764809, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(负)*/
	{.bitmap_index = 764945, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贡)*/
	{.bitmap_index = 765073, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(财)*/
	{.bitmap_index = 765193, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(责)*/
	{.bitmap_index = 765321, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(贤)*/
	{.bitmap_index = 765449, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(败)*/
	{.bitmap_index = 765585, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(账)*/
	{.bitmap_index = 765705, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(货)*/
	{.bitmap_index = 765841, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(质)*/
	{.bitmap_index = 765969, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贩)*/
	{.bitmap_index = 766097, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贪)*/
	{.bitmap_index = 766233, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贫)*/
	{.bitmap_index = 766369, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(贬)*/
	{.bitmap_index = 766489, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(购)*/
	{.bitmap_index = 766625, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贮)*/
	{.bitmap_index = 766761, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贯)*/
	{.bitmap_index = 766889, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贰)*/
	{.bitmap_index = 767025, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(贱)*/
	{.bitmap_index = 767153, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贲)*/
	{.bitmap_index = 767281, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贳)*/
	{.bitmap_index = 767417, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贴)*/
	{.bitmap_index = 767545, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贵)*/
	{.bitmap_index = 767681, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贶)*/
	{.bitmap_index = 767809, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贷)*/
	{.bitmap_index = 767945, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(贸)*/
	{.bitmap_index = 768064, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(费)*/
	{.bitmap_index = 768192, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贺)*/
	{.bitmap_index = 768328, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贻)*/
	{.bitmap_index = 768464, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(贼)*/
	{.bitmap_index = 768592, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贽)*/
	{.bitmap_index = 768720, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贾)*/
	{.bitmap_index = 768848, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(贿)*/
	{.bitmap_index = 768984, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赀)*/
	{.bitmap_index = 769120, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赁)*/
	{.bitmap_index = 769256, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赂)*/
	{.bitmap_index = 769384, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赃)*/
	{.bitmap_index = 769504, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(资)*/
	{.bitmap_index = 769640, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赅)*/
	{.bitmap_index = 769768, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赆)*/
	{.bitmap_index = 769888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赇)*/
	{.bitmap_index = 770016, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赈)*/
	{.bitmap_index = 770144, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赉)*/
	{.bitmap_index = 770280, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赊)*/
	{.bitmap_index = 770408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赋)*/
	{.bitmap_index = 770536, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赌)*/
	{.bitmap_index = 770664, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(赍)*/
	{.bitmap_index = 770776, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赎)*/
	{.bitmap_index = 770912, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(赏)*/
	{.bitmap_index = 771031, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赐)*/
	{.bitmap_index = 771159, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赓)*/
	{.bitmap_index = 771295, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赔)*/
	{.bitmap_index = 771431, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赕)*/
	{.bitmap_index = 771567, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赖)*/
	{.bitmap_index = 771703, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赘)*/
	{.bitmap_index = 771839, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赙)*/
	{.bitmap_index = 771975, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赚)*/
	{.bitmap_index = 772111, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赛)*/
	{.bitmap_index = 772247, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(赜)*/
	{.bitmap_index = 772375, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赝)*/
	{.bitmap_index = 772503, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赞)*/
	{.bitmap_index = 772639, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赠)*/
	{.bitmap_index = 772775, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赡)*/
	{.bitmap_index = 772911, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赢)*/
	{.bitmap_index = 773047, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赣)*/
	{.bitmap_index = 773183, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赤)*/
	{.bitmap_index = 773311, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赦)*/
	{.bitmap_index = 773447, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赧)*/
	{.bitmap_index = 773583, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赫)*/
	{.bitmap_index = 773711, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赭)*/
	{.bitmap_index = 773847, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(走)*/
	{.bitmap_index = 773983, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赳)*/
	{.bitmap_index = 774103, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赴)*/
	{.bitmap_index = 774239, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(赵)*/
	{.bitmap_index = 774359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(赶)*/
	{.bitmap_index = 774487, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(起)*/
	{.bitmap_index = 774607, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趁)*/
	{.bitmap_index = 774735, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趄)*/
	{.bitmap_index = 774863, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(超)*/
	{.bitmap_index = 774983, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(越)*/
	{.bitmap_index = 775103, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趋)*/
	{.bitmap_index = 775231, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趑)*/
	{.bitmap_index = 775359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趔)*/
	{.bitmap_index = 775487, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趟)*/
	{.bitmap_index = 775607, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趣)*/
	{.bitmap_index = 775735, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趱)*/
	{.bitmap_index = 775863, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(足)*/
	{.bitmap_index = 775991, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趴)*/
	{.bitmap_index = 776111, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趵)*/
	{.bitmap_index = 776239, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(趸)*/
	{.bitmap_index = 776367, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(趺)*/
	{.bitmap_index = 776495, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(趼)*/
	{.bitmap_index = 776623, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(趾)*/
	{.bitmap_index = 776743, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(趿)*/
	{.bitmap_index = 776871, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跃)*/
	{.bitmap_index = 776999, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跄)*/
	{.bitmap_index = 777127, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跆)*/
	{.bitmap_index = 777255, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跋)*/
	{.bitmap_index = 777391, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跌)*/
	{.bitmap_index = 777519, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跎)*/
	{.bitmap_index = 777647, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跏)*/
	{.bitmap_index = 777783, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跑)*/
	{.bitmap_index = 777911, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跖)*/
	{.bitmap_index = 778031, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跗)*/
	{.bitmap_index = 778159, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跚)*/
	{.bitmap_index = 778287, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跛)*/
	{.bitmap_index = 778423, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(距)*/
	{.bitmap_index = 778543, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跞)*/
	{.bitmap_index = 778663, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跟)*/
	{.bitmap_index = 778791, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跣)*/
	{.bitmap_index = 778919, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跤)*/
	{.bitmap_index = 779047, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跨)*/
	{.bitmap_index = 779175, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跪)*/
	{.bitmap_index = 779311, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跫)*/
	{.bitmap_index = 779439, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跬)*/
	{.bitmap_index = 779559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(路)*/
	{.bitmap_index = 779687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跳)*/
	{.bitmap_index = 779815, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(践)*/
	{.bitmap_index = 779943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跷)*/
	{.bitmap_index = 780071, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跸)*/
	{.bitmap_index = 780191, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跹)*/
	{.bitmap_index = 780311, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跺)*/
	{.bitmap_index = 780431, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(跻)*/
	{.bitmap_index = 780567, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(跽)*/
	{.bitmap_index = 780687, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(踅)*/
	{.bitmap_index = 780823, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(踉)*/
	{.bitmap_index = 780959, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踊)*/
	{.bitmap_index = 781079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踌)*/
	{.bitmap_index = 781207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踏)*/
	{.bitmap_index = 781335, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踔)*/
	{.bitmap_index = 781455, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踝)*/
	{.bitmap_index = 781575, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踞)*/
	{.bitmap_index = 781695, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踟)*/
	{.bitmap_index = 781823, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(踢)*/
	{.bitmap_index = 781951, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踣)*/
	{.bitmap_index = 782071, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踩)*/
	{.bitmap_index = 782191, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踪)*/
	{.bitmap_index = 782311, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踬)*/
	{.bitmap_index = 782431, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踮)*/
	{.bitmap_index = 782551, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踯)*/
	{.bitmap_index = 782671, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(踱)*/
	{.bitmap_index = 782807, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踵)*/
	{.bitmap_index = 782927, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踹)*/
	{.bitmap_index = 783055, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踺)*/
	{.bitmap_index = 783183, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(踽)*/
	{.bitmap_index = 783303, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹀)*/
	{.bitmap_index = 783423, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹁)*/
	{.bitmap_index = 783551, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹂)*/
	{.bitmap_index = 783671, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹄)*/
	{.bitmap_index = 783799, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹇)*/
	{.bitmap_index = 783935, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹈)*/
	{.bitmap_index = 784063, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹉)*/
	{.bitmap_index = 784191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹊)*/
	{.bitmap_index = 784319, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹋)*/
	{.bitmap_index = 784439, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹑)*/
	{.bitmap_index = 784567, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹒)*/
	{.bitmap_index = 784695, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹙)*/
	{.bitmap_index = 784831, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹦)*/
	{.bitmap_index = 784967, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹩)*/
	{.bitmap_index = 785103, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹬)*/
	{.bitmap_index = 785223, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹭)*/
	{.bitmap_index = 785351, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹯)*/
	{.bitmap_index = 785479, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹰)*/
	{.bitmap_index = 785599, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹲)*/
	{.bitmap_index = 785727, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹴)*/
	{.bitmap_index = 785855, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(蹶)*/
	{.bitmap_index = 785983, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹼)*/
	{.bitmap_index = 786103, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(蹿)*/
	{.bitmap_index = 786223, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躁)*/
	{.bitmap_index = 786343, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躅)*/
	{.bitmap_index = 786463, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躇)*/
	{.bitmap_index = 786591, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躏)*/
	{.bitmap_index = 786719, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(躐)*/
	{.bitmap_index = 786855, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躔)*/
	{.bitmap_index = 786983, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躜)*/
	{.bitmap_index = 787111, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躞)*/
	{.bitmap_index = 787239, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(身)*/
	{.bitmap_index = 787367, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躬)*/
	{.bitmap_index = 787495, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躯)*/
	{.bitmap_index = 787623, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躲)*/
	{.bitmap_index = 787751, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(躺)*/
	{.bitmap_index = 787879, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(軎)*/
	{.bitmap_index = 788007, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(车)*/
	{.bitmap_index = 788135, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轧)*/
	{.bitmap_index = 788263, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轨)*/
	{.bitmap_index = 788391, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轩)*/
	{.bitmap_index = 788519, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轫)*/
	{.bitmap_index = 788647, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(转)*/
	{.bitmap_index = 788783, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轭)*/
	{.bitmap_index = 788911, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轮)*/
	{.bitmap_index = 789039, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(软)*/
	{.bitmap_index = 789175, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(轰)*/
	{.bitmap_index = 789311, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轱)*/
	{.bitmap_index = 789439, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轲)*/
	{.bitmap_index = 789559, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(轳)*/
	{.bitmap_index = 789695, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轴)*/
	{.bitmap_index = 789823, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(轵)*/
	{.bitmap_index = 789959, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(轶)*/
	{.bitmap_index = 790095, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轷)*/
	{.bitmap_index = 790223, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(轸)*/
	{.bitmap_index = 790359, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轹)*/
	{.bitmap_index = 790487, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轺)*/
	{.bitmap_index = 790615, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轻)*/
	{.bitmap_index = 790743, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轼)*/
	{.bitmap_index = 790871, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(载)*/
	{.bitmap_index = 791007, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(轾)*/
	{.bitmap_index = 791135, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(轿)*/
	{.bitmap_index = 791271, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辁)*/
	{.bitmap_index = 791399, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辂)*/
	{.bitmap_index = 791527, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(较)*/
	{.bitmap_index = 791663, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辄)*/
	{.bitmap_index = 791791, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辅)*/
	{.bitmap_index = 791919, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辆)*/
	{.bitmap_index = 792047, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辇)*/
	{.bitmap_index = 792175, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辈)*/
	{.bitmap_index = 792295, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辉)*/
	{.bitmap_index = 792423, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辊)*/
	{.bitmap_index = 792551, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辋)*/
	{.bitmap_index = 792679, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辍)*/
	{.bitmap_index = 792807, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辎)*/
	{.bitmap_index = 792935, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辏)*/
	{.bitmap_index = 793063, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辐)*/
	{.bitmap_index = 793191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辑)*/
	{.bitmap_index = 793319, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(输)*/
	{.bitmap_index = 793455, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辔)*/
	{.bitmap_index = 793583, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辕)*/
	{.bitmap_index = 793719, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辖)*/
	{.bitmap_index = 793839, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辗)*/
	{.bitmap_index = 793967, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辘)*/
	{.bitmap_index = 794095, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辙)*/
	{.bitmap_index = 794231, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辚)*/
	{.bitmap_index = 794367, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辛)*/
	{.bitmap_index = 794495, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辜)*/
	{.bitmap_index = 794615, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辞)*/
	{.bitmap_index = 794735, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辟)*/
	{.bitmap_index = 794863, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辣)*/
	{.bitmap_index = 794999, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辨)*/
	{.bitmap_index = 795135, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辩)*/
	{.bitmap_index = 795271, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(辫)*/
	{.bitmap_index = 795407, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辰)*/
	{.bitmap_index = 795527, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辱)*/
	{.bitmap_index = 795647, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辶)*/
	{.bitmap_index = 795775, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(边)*/
	{.bitmap_index = 795895, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(辽)*/
	{.bitmap_index = 796015, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(达)*/
	{.bitmap_index = 796143, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迁)*/
	{.bitmap_index = 796263, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迂)*/
	{.bitmap_index = 796383, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迄)*/
	{.bitmap_index = 796511, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迅)*/
	{.bitmap_index = 796631, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(过)*/
	{.bitmap_index = 796751, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迈)*/
	{.bitmap_index = 796871, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迎)*/
	{.bitmap_index = 796999, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(运)*/
	{.bitmap_index = 797119, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(近)*/
	{.bitmap_index = 797239, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迓)*/
	{.bitmap_index = 797359, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(返)*/
	{.bitmap_index = 797479, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迕)*/
	{.bitmap_index = 797607, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(还)*/
	{.bitmap_index = 797727, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(这)*/
	{.bitmap_index = 797855, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(进)*/
	{.bitmap_index = 797975, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(远)*/
	{.bitmap_index = 798095, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(违)*/
	{.bitmap_index = 798215, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(连)*/
	{.bitmap_index = 798343, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迟)*/
	{.bitmap_index = 798463, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迢)*/
	{.bitmap_index = 798583, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迤)*/
	{.bitmap_index = 798711, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迥)*/
	{.bitmap_index = 798831, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迦)*/
	{.bitmap_index = 798951, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迨)*/
	{.bitmap_index = 799079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迩)*/
	{.bitmap_index = 799207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迪)*/
	{.bitmap_index = 799335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迫)*/
	{.bitmap_index = 799463, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迭)*/
	{.bitmap_index = 799591, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迮)*/
	{.bitmap_index = 799719, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(述)*/
	{.bitmap_index = 799839, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迳)*/
	{.bitmap_index = 799959, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迷)*/
	{.bitmap_index = 800079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迸)*/
	{.bitmap_index = 800207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(迹)*/
	{.bitmap_index = 800335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(追)*/
	{.bitmap_index = 800463, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(退)*/
	{.bitmap_index = 800591, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(送)*/
	{.bitmap_index = 800719, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(适)*/
	{.bitmap_index = 800839, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逃)*/
	{.bitmap_index = 800959, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逄)*/
	{.bitmap_index = 801087, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逅)*/
	{.bitmap_index = 801207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逆)*/
	{.bitmap_index = 801335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(选)*/
	{.bitmap_index = 801463, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逊)*/
	{.bitmap_index = 801583, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逋)*/
	{.bitmap_index = 801711, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逍)*/
	{.bitmap_index = 801839, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(透)*/
	{.bitmap_index = 801959, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逐)*/
	{.bitmap_index = 802079, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逑)*/
	{.bitmap_index = 802207, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(递)*/
	{.bitmap_index = 802335, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(途)*/
	{.bitmap_index = 802463, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逖)*/
	{.bitmap_index = 802583, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逗)*/
	{.bitmap_index = 802703, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(通)*/
	{.bitmap_index = 802823, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逛)*/
	{.bitmap_index = 802943, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逝)*/
	{.bitmap_index = 803063, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逞)*/
	{.bitmap_index = 803183, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(速)*/
	{.bitmap_index = 803303, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(造)*/
	{.bitmap_index = 803431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逡)*/
	{.bitmap_index = 803559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逢)*/
	{.bitmap_index = 803687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逦)*/
	{.bitmap_index = 803815, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逭)*/
	{.bitmap_index = 803943, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逮)*/
	{.bitmap_index = 804071, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逯)*/
	{.bitmap_index = 804191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逵)*/
	{.bitmap_index = 804319, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逶)*/
	{.bitmap_index = 804439, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逸)*/
	{.bitmap_index = 804567, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逻)*/
	{.bitmap_index = 804687, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逼)*/
	{.bitmap_index = 804807, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(逾)*/
	{.bitmap_index = 804935, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遁)*/
	{.bitmap_index = 805055, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遂)*/
	{.bitmap_index = 805183, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遄)*/
	{.bitmap_index = 805311, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遇)*/
	{.bitmap_index = 805431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遍)*/
	{.bitmap_index = 805559, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遏)*/
	{.bitmap_index = 805679, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遐)*/
	{.bitmap_index = 805799, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遑)*/
	{.bitmap_index = 805927, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遒)*/
	{.bitmap_index = 806055, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(道)*/
	{.bitmap_index = 806183, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遗)*/
	{.bitmap_index = 806311, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遘)*/
	{.bitmap_index = 806439, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遛)*/
	{.bitmap_index = 806567, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遢)*/
	{.bitmap_index = 806687, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遣)*/
	{.bitmap_index = 806815, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遥)*/
	{.bitmap_index = 806935, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遨)*/
	{.bitmap_index = 807055, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遭)*/
	{.bitmap_index = 807175, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遮)*/
	{.bitmap_index = 807303, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遴)*/
	{.bitmap_index = 807431, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遵)*/
	{.bitmap_index = 807559, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(遽)*/
	{.bitmap_index = 807687, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(避)*/
	{.bitmap_index = 807807, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邀)*/
	{.bitmap_index = 807935, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邂)*/
	{.bitmap_index = 808063, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邃)*/
	{.bitmap_index = 808191, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邈)*/
	{.bitmap_index = 808319, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邋)*/
	{.bitmap_index = 808447, .adv_w = 16, .box_h = 15, .box_w = 14, .ofs_x = 2, .ofs_y = 4},/*(邑)*/
	{.bitmap_index = 808552, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邓)*/
	{.bitmap_index = 808672, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(邕)*/
	{.bitmap_index = 808800, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邗)*/
	{.bitmap_index = 808920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邙)*/
	{.bitmap_index = 809048, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邛)*/
	{.bitmap_index = 809168, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邝)*/
	{.bitmap_index = 809296, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邡)*/
	{.bitmap_index = 809424, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(邢)*/
	{.bitmap_index = 809552, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(那)*/
	{.bitmap_index = 809672, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(邦)*/
	{.bitmap_index = 809800, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邪)*/
	{.bitmap_index = 809920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邬)*/
	{.bitmap_index = 810048, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(邮)*/
	{.bitmap_index = 810176, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邯)*/
	{.bitmap_index = 810296, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邰)*/
	{.bitmap_index = 810424, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邱)*/
	{.bitmap_index = 810544, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邳)*/
	{.bitmap_index = 810664, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(邴)*/
	{.bitmap_index = 810784, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邵)*/
	{.bitmap_index = 810904, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邶)*/
	{.bitmap_index = 811024, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邸)*/
	{.bitmap_index = 811152, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邹)*/
	{.bitmap_index = 811280, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邺)*/
	{.bitmap_index = 811400, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邻)*/
	{.bitmap_index = 811528, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(邾)*/
	{.bitmap_index = 811648, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郁)*/
	{.bitmap_index = 811776, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郄)*/
	{.bitmap_index = 811904, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郅)*/
	{.bitmap_index = 812024, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郇)*/
	{.bitmap_index = 812152, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(郊)*/
	{.bitmap_index = 812280, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郎)*/
	{.bitmap_index = 812408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(郏)*/
	{.bitmap_index = 812536, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郐)*/
	{.bitmap_index = 812664, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(郑)*/
	{.bitmap_index = 812800, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郓)*/
	{.bitmap_index = 812920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郗)*/
	{.bitmap_index = 813048, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郛)*/
	{.bitmap_index = 813168, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郜)*/
	{.bitmap_index = 813296, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(郝)*/
	{.bitmap_index = 813424, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郡)*/
	{.bitmap_index = 813544, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郢)*/
	{.bitmap_index = 813664, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郦)*/
	{.bitmap_index = 813784, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郧)*/
	{.bitmap_index = 813904, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(部)*/
	{.bitmap_index = 814032, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郫)*/
	{.bitmap_index = 814160, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郭)*/
	{.bitmap_index = 814288, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(郯)*/
	{.bitmap_index = 814416, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郴)*/
	{.bitmap_index = 814536, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(郸)*/
	{.bitmap_index = 814664, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(都)*/
	{.bitmap_index = 814784, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(郾)*/
	{.bitmap_index = 814904, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄂)*/
	{.bitmap_index = 815024, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄄)*/
	{.bitmap_index = 815144, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄙)*/
	{.bitmap_index = 815264, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄞)*/
	{.bitmap_index = 815384, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄢)*/
	{.bitmap_index = 815504, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄣)*/
	{.bitmap_index = 815632, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄯)*/
	{.bitmap_index = 815760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄱)*/
	{.bitmap_index = 815888, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鄹)*/
	{.bitmap_index = 816008, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酃)*/
	{.bitmap_index = 816128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酆)*/
	{.bitmap_index = 816256, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酉)*/
	{.bitmap_index = 816376, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酊)*/
	{.bitmap_index = 816496, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酋)*/
	{.bitmap_index = 816624, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酌)*/
	{.bitmap_index = 816752, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(配)*/
	{.bitmap_index = 816872, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酎)*/
	{.bitmap_index = 816992, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酏)*/
	{.bitmap_index = 817112, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酐)*/
	{.bitmap_index = 817232, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酒)*/
	{.bitmap_index = 817360, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酗)*/
	{.bitmap_index = 817480, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(酚)*/
	{.bitmap_index = 817616, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酝)*/
	{.bitmap_index = 817736, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(酞)*/
	{.bitmap_index = 817864, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酡)*/
	{.bitmap_index = 817992, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酢)*/
	{.bitmap_index = 818120, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酣)*/
	{.bitmap_index = 818240, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酤)*/
	{.bitmap_index = 818360, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酥)*/
	{.bitmap_index = 818480, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酩)*/
	{.bitmap_index = 818608, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酪)*/
	{.bitmap_index = 818736, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酬)*/
	{.bitmap_index = 818856, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酮)*/
	{.bitmap_index = 818976, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酯)*/
	{.bitmap_index = 819096, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酰)*/
	{.bitmap_index = 819216, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酱)*/
	{.bitmap_index = 819344, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酲)*/
	{.bitmap_index = 819464, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酴)*/
	{.bitmap_index = 819592, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酵)*/
	{.bitmap_index = 819720, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酶)*/
	{.bitmap_index = 819848, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酷)*/
	{.bitmap_index = 819976, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(酸)*/
	{.bitmap_index = 820112, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酹)*/
	{.bitmap_index = 820232, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(酽)*/
	{.bitmap_index = 820360, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酾)*/
	{.bitmap_index = 820480, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(酿)*/
	{.bitmap_index = 820608, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醅)*/
	{.bitmap_index = 820736, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醇)*/
	{.bitmap_index = 820856, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醉)*/
	{.bitmap_index = 820976, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醋)*/
	{.bitmap_index = 821096, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醌)*/
	{.bitmap_index = 821216, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(醍)*/
	{.bitmap_index = 821344, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醐)*/
	{.bitmap_index = 821464, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醑)*/
	{.bitmap_index = 821584, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醒)*/
	{.bitmap_index = 821704, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醚)*/
	{.bitmap_index = 821824, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醛)*/
	{.bitmap_index = 821944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醢)*/
	{.bitmap_index = 822072, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醣)*/
	{.bitmap_index = 822200, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(醪)*/
	{.bitmap_index = 822328, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醭)*/
	{.bitmap_index = 822448, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醮)*/
	{.bitmap_index = 822568, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醯)*/
	{.bitmap_index = 822696, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醴)*/
	{.bitmap_index = 822824, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(醵)*/
	{.bitmap_index = 822952, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(醺)*/
	{.bitmap_index = 823080, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(采)*/
	{.bitmap_index = 823200, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(釉)*/
	{.bitmap_index = 823320, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(释)*/
	{.bitmap_index = 823440, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(里)*/
	{.bitmap_index = 823560, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(重)*/
	{.bitmap_index = 823680, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(野)*/
	{.bitmap_index = 823800, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(量)*/
	{.bitmap_index = 823920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(金)*/
	{.bitmap_index = 824048, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(釜)*/
	{.bitmap_index = 824176, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鉴)*/
	{.bitmap_index = 824304, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(銎)*/
	{.bitmap_index = 824424, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(銮)*/
	{.bitmap_index = 824552, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鋈)*/
	{.bitmap_index = 824680, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(錾)*/
	{.bitmap_index = 824808, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鍪)*/
	{.bitmap_index = 824936, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鎏)*/
	{.bitmap_index = 825064, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鏊)*/
	{.bitmap_index = 825192, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鏖)*/
	{.bitmap_index = 825320, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鐾)*/
	{.bitmap_index = 825448, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鑫)*/
	{.bitmap_index = 825576, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(钅)*/
	{.bitmap_index = 825656, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钆)*/
	{.bitmap_index = 825784, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钇)*/
	{.bitmap_index = 825912, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(针)*/
	{.bitmap_index = 826040, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钉)*/
	{.bitmap_index = 826168, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钊)*/
	{.bitmap_index = 826296, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钋)*/
	{.bitmap_index = 826424, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钌)*/
	{.bitmap_index = 826552, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钍)*/
	{.bitmap_index = 826680, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钎)*/
	{.bitmap_index = 826808, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钏)*/
	{.bitmap_index = 826944, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钐)*/
	{.bitmap_index = 827072, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钒)*/
	{.bitmap_index = 827200, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钓)*/
	{.bitmap_index = 827328, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钔)*/
	{.bitmap_index = 827456, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钕)*/
	{.bitmap_index = 827592, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钗)*/
	{.bitmap_index = 827728, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钙)*/
	{.bitmap_index = 827856, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钚)*/
	{.bitmap_index = 827984, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钛)*/
	{.bitmap_index = 828120, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钜)*/
	{.bitmap_index = 828248, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钝)*/
	{.bitmap_index = 828376, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钞)*/
	{.bitmap_index = 828512, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钟)*/
	{.bitmap_index = 828640, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钠)*/
	{.bitmap_index = 828768, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钡)*/
	{.bitmap_index = 828904, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钢)*/
	{.bitmap_index = 829032, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钣)*/
	{.bitmap_index = 829168, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钤)*/
	{.bitmap_index = 829304, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钥)*/
	{.bitmap_index = 829440, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钦)*/
	{.bitmap_index = 829576, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钧)*/
	{.bitmap_index = 829704, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钨)*/
	{.bitmap_index = 829832, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钩)*/
	{.bitmap_index = 829960, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钪)*/
	{.bitmap_index = 830096, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钫)*/
	{.bitmap_index = 830232, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钬)*/
	{.bitmap_index = 830360, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钭)*/
	{.bitmap_index = 830488, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钮)*/
	{.bitmap_index = 830616, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钯)*/
	{.bitmap_index = 830744, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钰)*/
	{.bitmap_index = 830872, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钱)*/
	{.bitmap_index = 831000, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钲)*/
	{.bitmap_index = 831128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钳)*/
	{.bitmap_index = 831256, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钴)*/
	{.bitmap_index = 831384, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钵)*/
	{.bitmap_index = 831512, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钶)*/
	{.bitmap_index = 831640, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钷)*/
	{.bitmap_index = 831768, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钸)*/
	{.bitmap_index = 831896, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钹)*/
	{.bitmap_index = 832032, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(钺)*/
	{.bitmap_index = 832168, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钻)*/
	{.bitmap_index = 832296, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钼)*/
	{.bitmap_index = 832424, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钽)*/
	{.bitmap_index = 832552, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钾)*/
	{.bitmap_index = 832680, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(钿)*/
	{.bitmap_index = 832808, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铀)*/
	{.bitmap_index = 832936, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铁)*/
	{.bitmap_index = 833072, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铂)*/
	{.bitmap_index = 833200, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铃)*/
	{.bitmap_index = 833328, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铄)*/
	{.bitmap_index = 833456, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铅)*/
	{.bitmap_index = 833584, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铆)*/
	{.bitmap_index = 833720, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铈)*/
	{.bitmap_index = 833848, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铉)*/
	{.bitmap_index = 833976, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铊)*/
	{.bitmap_index = 834104, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铋)*/
	{.bitmap_index = 834232, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铌)*/
	{.bitmap_index = 834368, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铍)*/
	{.bitmap_index = 834504, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铎)*/
	{.bitmap_index = 834632, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铐)*/
	{.bitmap_index = 834760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铑)*/
	{.bitmap_index = 834888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铒)*/
	{.bitmap_index = 835016, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铕)*/
	{.bitmap_index = 835144, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铖)*/
	{.bitmap_index = 835280, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铗)*/
	{.bitmap_index = 835416, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铘)*/
	{.bitmap_index = 835544, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铙)*/
	{.bitmap_index = 835672, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铛)*/
	{.bitmap_index = 835800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铜)*/
	{.bitmap_index = 835928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铝)*/
	{.bitmap_index = 836056, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铞)*/
	{.bitmap_index = 836184, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铟)*/
	{.bitmap_index = 836312, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铠)*/
	{.bitmap_index = 836440, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铡)*/
	{.bitmap_index = 836568, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铢)*/
	{.bitmap_index = 836696, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铣)*/
	{.bitmap_index = 836832, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铤)*/
	{.bitmap_index = 836968, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铥)*/
	{.bitmap_index = 837096, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铧)*/
	{.bitmap_index = 837232, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铨)*/
	{.bitmap_index = 837360, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铩)*/
	{.bitmap_index = 837488, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铪)*/
	{.bitmap_index = 837616, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铫)*/
	{.bitmap_index = 837752, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铬)*/
	{.bitmap_index = 837880, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铭)*/
	{.bitmap_index = 838008, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铮)*/
	{.bitmap_index = 838136, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铯)*/
	{.bitmap_index = 838264, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铰)*/
	{.bitmap_index = 838400, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铱)*/
	{.bitmap_index = 838528, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铲)*/
	{.bitmap_index = 838664, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铳)*/
	{.bitmap_index = 838800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铴)*/
	{.bitmap_index = 838928, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铵)*/
	{.bitmap_index = 839064, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(银)*/
	{.bitmap_index = 839200, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铷)*/
	{.bitmap_index = 839336, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铸)*/
	{.bitmap_index = 839464, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(铹)*/
	{.bitmap_index = 839600, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铺)*/
	{.bitmap_index = 839728, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铼)*/
	{.bitmap_index = 839856, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铽)*/
	{.bitmap_index = 839984, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(链)*/
	{.bitmap_index = 840112, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(铿)*/
	{.bitmap_index = 840240, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(销)*/
	{.bitmap_index = 840368, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锁)*/
	{.bitmap_index = 840504, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锂)*/
	{.bitmap_index = 840632, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锃)*/
	{.bitmap_index = 840760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锄)*/
	{.bitmap_index = 840888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锅)*/
	{.bitmap_index = 841016, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锆)*/
	{.bitmap_index = 841144, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锇)*/
	{.bitmap_index = 841272, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锈)*/
	{.bitmap_index = 841408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锉)*/
	{.bitmap_index = 841536, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锊)*/
	{.bitmap_index = 841664, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锋)*/
	{.bitmap_index = 841792, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锌)*/
	{.bitmap_index = 841920, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锍)*/
	{.bitmap_index = 842048, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锎)*/
	{.bitmap_index = 842176, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锏)*/
	{.bitmap_index = 842304, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锐)*/
	{.bitmap_index = 842440, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锑)*/
	{.bitmap_index = 842568, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锒)*/
	{.bitmap_index = 842704, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锓)*/
	{.bitmap_index = 842840, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锔)*/
	{.bitmap_index = 842968, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锕)*/
	{.bitmap_index = 843088, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锖)*/
	{.bitmap_index = 843216, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锗)*/
	{.bitmap_index = 843344, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锘)*/
	{.bitmap_index = 843472, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(错)*/
	{.bitmap_index = 843600, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锚)*/
	{.bitmap_index = 843728, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锛)*/
	{.bitmap_index = 843864, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锝)*/
	{.bitmap_index = 843992, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锞)*/
	{.bitmap_index = 844112, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锟)*/
	{.bitmap_index = 844240, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锡)*/
	{.bitmap_index = 844376, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锢)*/
	{.bitmap_index = 844504, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锣)*/
	{.bitmap_index = 844632, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锤)*/
	{.bitmap_index = 844760, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锥)*/
	{.bitmap_index = 844888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锦)*/
	{.bitmap_index = 845016, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锨)*/
	{.bitmap_index = 845152, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锩)*/
	{.bitmap_index = 845280, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锪)*/
	{.bitmap_index = 845408, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锫)*/
	{.bitmap_index = 845536, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锬)*/
	{.bitmap_index = 845672, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锭)*/
	{.bitmap_index = 845800, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(键)*/
	{.bitmap_index = 845928, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锯)*/
	{.bitmap_index = 846056, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锰)*/
	{.bitmap_index = 846184, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锱)*/
	{.bitmap_index = 846312, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锲)*/
	{.bitmap_index = 846448, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锴)*/
	{.bitmap_index = 846576, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锵)*/
	{.bitmap_index = 846704, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锶)*/
	{.bitmap_index = 846832, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锷)*/
	{.bitmap_index = 846960, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锸)*/
	{.bitmap_index = 847088, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锹)*/
	{.bitmap_index = 847216, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(锺)*/
	{.bitmap_index = 847344, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锻)*/
	{.bitmap_index = 847480, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锼)*/
	{.bitmap_index = 847616, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锾)*/
	{.bitmap_index = 847752, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(锿)*/
	{.bitmap_index = 847888, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镀)*/
	{.bitmap_index = 848024, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镁)*/
	{.bitmap_index = 848160, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镂)*/
	{.bitmap_index = 848296, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镄)*/
	{.bitmap_index = 848432, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镅)*/
	{.bitmap_index = 848560, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镆)*/
	{.bitmap_index = 848696, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镇)*/
	{.bitmap_index = 848832, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镉)*/
	{.bitmap_index = 848960, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镊)*/
	{.bitmap_index = 849096, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镌)*/
	{.bitmap_index = 849232, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镍)*/
	{.bitmap_index = 849360, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镎)*/
	{.bitmap_index = 849488, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镏)*/
	{.bitmap_index = 849616, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镐)*/
	{.bitmap_index = 849744, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镑)*/
	{.bitmap_index = 849880, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镒)*/
	{.bitmap_index = 850008, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镓)*/
	{.bitmap_index = 850136, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镔)*/
	{.bitmap_index = 850272, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镖)*/
	{.bitmap_index = 850400, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镗)*/
	{.bitmap_index = 850528, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镘)*/
	{.bitmap_index = 850664, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镙)*/
	{.bitmap_index = 850792, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镛)*/
	{.bitmap_index = 850920, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镜)*/
	{.bitmap_index = 851056, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镝)*/
	{.bitmap_index = 851184, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镞)*/
	{.bitmap_index = 851320, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镟)*/
	{.bitmap_index = 851448, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镡)*/
	{.bitmap_index = 851576, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镢)*/
	{.bitmap_index = 851704, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镣)*/
	{.bitmap_index = 851832, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镤)*/
	{.bitmap_index = 851960, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镥)*/
	{.bitmap_index = 852088, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镦)*/
	{.bitmap_index = 852224, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镧)*/
	{.bitmap_index = 852352, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镨)*/
	{.bitmap_index = 852480, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镩)*/
	{.bitmap_index = 852608, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镪)*/
	{.bitmap_index = 852736, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镫)*/
	{.bitmap_index = 852864, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镬)*/
	{.bitmap_index = 853000, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镭)*/
	{.bitmap_index = 853128, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镯)*/
	{.bitmap_index = 853256, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镰)*/
	{.bitmap_index = 853392, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镱)*/
	{.bitmap_index = 853520, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镲)*/
	{.bitmap_index = 853648, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(镳)*/
	{.bitmap_index = 853776, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(镶)*/
	{.bitmap_index = 853912, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(长)*/
	{.bitmap_index = 854040, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(门)*/
	{.bitmap_index = 854152, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闩)*/
	{.bitmap_index = 854264, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闪)*/
	{.bitmap_index = 854376, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闫)*/
	{.bitmap_index = 854488, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闭)*/
	{.bitmap_index = 854600, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(问)*/
	{.bitmap_index = 854712, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闯)*/
	{.bitmap_index = 854824, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闰)*/
	{.bitmap_index = 854936, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闱)*/
	{.bitmap_index = 855048, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闲)*/
	{.bitmap_index = 855160, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闳)*/
	{.bitmap_index = 855272, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(间)*/
	{.bitmap_index = 855384, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闵)*/
	{.bitmap_index = 855496, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闶)*/
	{.bitmap_index = 855608, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闷)*/
	{.bitmap_index = 855720, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闸)*/
	{.bitmap_index = 855832, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闹)*/
	{.bitmap_index = 855944, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闺)*/
	{.bitmap_index = 856056, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闻)*/
	{.bitmap_index = 856168, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闼)*/
	{.bitmap_index = 856280, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闽)*/
	{.bitmap_index = 856392, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(闾)*/
	{.bitmap_index = 856504, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阀)*/
	{.bitmap_index = 856616, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阁)*/
	{.bitmap_index = 856728, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(阂)*/
	{.bitmap_index = 856847, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阃)*/
	{.bitmap_index = 856959, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阄)*/
	{.bitmap_index = 857071, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阅)*/
	{.bitmap_index = 857183, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阆)*/
	{.bitmap_index = 857295, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(阈)*/
	{.bitmap_index = 857414, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阉)*/
	{.bitmap_index = 857526, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阊)*/
	{.bitmap_index = 857638, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阋)*/
	{.bitmap_index = 857750, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阌)*/
	{.bitmap_index = 857862, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阍)*/
	{.bitmap_index = 857974, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阎)*/
	{.bitmap_index = 858086, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阏)*/
	{.bitmap_index = 858198, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阐)*/
	{.bitmap_index = 858310, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阑)*/
	{.bitmap_index = 858422, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阒)*/
	{.bitmap_index = 858534, .adv_w = 15, .box_h = 17, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(阔)*/
	{.bitmap_index = 858653, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阕)*/
	{.bitmap_index = 858765, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阖)*/
	{.bitmap_index = 858877, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阗)*/
	{.bitmap_index = 858989, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阙)*/
	{.bitmap_index = 859101, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阚)*/
	{.bitmap_index = 859213, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(阜)*/
	{.bitmap_index = 859341, .adv_w = 9, .box_h = 15, .box_w = 8, .ofs_x = 1, .ofs_y = 4},/*(阝)*/
	{.bitmap_index = 859401, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(队)*/
	{.bitmap_index = 859529, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阡)*/
	{.bitmap_index = 859649, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阢)*/
	{.bitmap_index = 859769, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(阪)*/
	{.bitmap_index = 859897, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(阮)*/
	{.bitmap_index = 860025, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(阱)*/
	{.bitmap_index = 860153, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(防)*/
	{.bitmap_index = 860281, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(阳)*/
	{.bitmap_index = 860386, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(阴)*/
	{.bitmap_index = 860498, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阵)*/
	{.bitmap_index = 860626, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(阶)*/
	{.bitmap_index = 860762, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阻)*/
	{.bitmap_index = 860882, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阼)*/
	{.bitmap_index = 861010, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阽)*/
	{.bitmap_index = 861130, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(阿)*/
	{.bitmap_index = 861250, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陀)*/
	{.bitmap_index = 861370, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陂)*/
	{.bitmap_index = 861498, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(附)*/
	{.bitmap_index = 861626, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(际)*/
	{.bitmap_index = 861746, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陆)*/
	{.bitmap_index = 861866, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陇)*/
	{.bitmap_index = 861994, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陈)*/
	{.bitmap_index = 862122, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陉)*/
	{.bitmap_index = 862242, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陋)*/
	{.bitmap_index = 862362, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陌)*/
	{.bitmap_index = 862482, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(降)*/
	{.bitmap_index = 862610, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(限)*/
	{.bitmap_index = 862738, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陔)*/
	{.bitmap_index = 862866, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陕)*/
	{.bitmap_index = 862994, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陛)*/
	{.bitmap_index = 863114, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陟)*/
	{.bitmap_index = 863234, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陡)*/
	{.bitmap_index = 863370, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(院)*/
	{.bitmap_index = 863498, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(除)*/
	{.bitmap_index = 863626, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陧)*/
	{.bitmap_index = 863746, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陨)*/
	{.bitmap_index = 863874, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(险)*/
	{.bitmap_index = 864002, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陪)*/
	{.bitmap_index = 864130, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陬)*/
	{.bitmap_index = 864250, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陲)*/
	{.bitmap_index = 864370, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(陴)*/
	{.bitmap_index = 864498, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(陵)*/
	{.bitmap_index = 864634, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(陶)*/
	{.bitmap_index = 864746, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(陷)*/
	{.bitmap_index = 864858, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(隅)*/
	{.bitmap_index = 864963, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隆)*/
	{.bitmap_index = 865091, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隈)*/
	{.bitmap_index = 865211, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(隋)*/
	{.bitmap_index = 865323, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隍)*/
	{.bitmap_index = 865451, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(随)*/
	{.bitmap_index = 865579, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隐)*/
	{.bitmap_index = 865707, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(隔)*/
	{.bitmap_index = 865812, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(隗)*/
	{.bitmap_index = 865948, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隘)*/
	{.bitmap_index = 866076, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隙)*/
	{.bitmap_index = 866196, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(障)*/
	{.bitmap_index = 866324, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隧)*/
	{.bitmap_index = 866452, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(隰)*/
	{.bitmap_index = 866572, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(隳)*/
	{.bitmap_index = 866700, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(隶)*/
	{.bitmap_index = 866820, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(隹)*/
	{.bitmap_index = 866948, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(隼)*/
	{.bitmap_index = 867076, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(隽)*/
	{.bitmap_index = 867212, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(难)*/
	{.bitmap_index = 867340, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雀)*/
	{.bitmap_index = 867468, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雁)*/
	{.bitmap_index = 867588, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雄)*/
	{.bitmap_index = 867716, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雅)*/
	{.bitmap_index = 867844, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(集)*/
	{.bitmap_index = 867972, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雇)*/
	{.bitmap_index = 868100, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雉)*/
	{.bitmap_index = 868228, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雌)*/
	{.bitmap_index = 868356, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(雍)*/
	{.bitmap_index = 868492, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雎)*/
	{.bitmap_index = 868620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雏)*/
	{.bitmap_index = 868748, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雒)*/
	{.bitmap_index = 868876, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雕)*/
	{.bitmap_index = 868996, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雠)*/
	{.bitmap_index = 869116, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(雨)*/
	{.bitmap_index = 869221, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雩)*/
	{.bitmap_index = 869341, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(雪)*/
	{.bitmap_index = 869446, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(雯)*/
	{.bitmap_index = 869574, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(雳)*/
	{.bitmap_index = 869702, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(零)*/
	{.bitmap_index = 869830, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(雷)*/
	{.bitmap_index = 869935, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(雹)*/
	{.bitmap_index = 870055, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(雾)*/
	{.bitmap_index = 870183, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(需)*/
	{.bitmap_index = 870288, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霁)*/
	{.bitmap_index = 870416, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(霄)*/
	{.bitmap_index = 870521, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霆)*/
	{.bitmap_index = 870649, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(震)*/
	{.bitmap_index = 870777, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霈)*/
	{.bitmap_index = 870905, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霉)*/
	{.bitmap_index = 871033, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霍)*/
	{.bitmap_index = 871153, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霎)*/
	{.bitmap_index = 871281, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霏)*/
	{.bitmap_index = 871401, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霓)*/
	{.bitmap_index = 871529, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霖)*/
	{.bitmap_index = 871649, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霜)*/
	{.bitmap_index = 871769, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(霞)*/
	{.bitmap_index = 871897, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霪)*/
	{.bitmap_index = 872025, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(霭)*/
	{.bitmap_index = 872153, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霰)*/
	{.bitmap_index = 872273, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(露)*/
	{.bitmap_index = 872393, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 3},/*(霸)*/
	{.bitmap_index = 872505, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霹)*/
	{.bitmap_index = 872625, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(霾)*/
	{.bitmap_index = 872745, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(青)*/
	{.bitmap_index = 872865, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(靓)*/
	{.bitmap_index = 872993, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靖)*/
	{.bitmap_index = 873113, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(静)*/
	{.bitmap_index = 873241, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靛)*/
	{.bitmap_index = 873369, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(非)*/
	{.bitmap_index = 873489, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靠)*/
	{.bitmap_index = 873617, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靡)*/
	{.bitmap_index = 873745, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(面)*/
	{.bitmap_index = 873850, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(靥)*/
	{.bitmap_index = 873978, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(革)*/
	{.bitmap_index = 874106, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(靳)*/
	{.bitmap_index = 874242, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靴)*/
	{.bitmap_index = 874370, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靶)*/
	{.bitmap_index = 874498, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(靼)*/
	{.bitmap_index = 874626, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鞅)*/
	{.bitmap_index = 874754, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞋)*/
	{.bitmap_index = 874874, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞍)*/
	{.bitmap_index = 874994, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞑)*/
	{.bitmap_index = 875122, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鞒)*/
	{.bitmap_index = 875250, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鞔)*/
	{.bitmap_index = 875386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞘)*/
	{.bitmap_index = 875514, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞠)*/
	{.bitmap_index = 875642, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞣)*/
	{.bitmap_index = 875762, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞫)*/
	{.bitmap_index = 875890, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞭)*/
	{.bitmap_index = 876018, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞯)*/
	{.bitmap_index = 876138, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞲)*/
	{.bitmap_index = 876258, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鞴)*/
	{.bitmap_index = 876378, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(韦)*/
	{.bitmap_index = 876490, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(韧)*/
	{.bitmap_index = 876626, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韩)*/
	{.bitmap_index = 876754, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韪)*/
	{.bitmap_index = 876874, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韫)*/
	{.bitmap_index = 877002, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韬)*/
	{.bitmap_index = 877130, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韭)*/
	{.bitmap_index = 877250, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(音)*/
	{.bitmap_index = 877378, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韵)*/
	{.bitmap_index = 877506, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(韶)*/
	{.bitmap_index = 877626, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(页)*/
	{.bitmap_index = 877754, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(顶)*/
	{.bitmap_index = 877874, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(顷)*/
	{.bitmap_index = 878002, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(顸)*/
	{.bitmap_index = 878122, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(项)*/
	{.bitmap_index = 878250, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(顺)*/
	{.bitmap_index = 878378, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(须)*/
	{.bitmap_index = 878506, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(顼)*/
	{.bitmap_index = 878634, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(顽)*/
	{.bitmap_index = 878762, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(顾)*/
	{.bitmap_index = 878890, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(顿)*/
	{.bitmap_index = 879018, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颀)*/
	{.bitmap_index = 879154, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颁)*/
	{.bitmap_index = 879282, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颂)*/
	{.bitmap_index = 879410, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颃)*/
	{.bitmap_index = 879538, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(预)*/
	{.bitmap_index = 879666, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颅)*/
	{.bitmap_index = 879794, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(领)*/
	{.bitmap_index = 879930, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颇)*/
	{.bitmap_index = 880058, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颈)*/
	{.bitmap_index = 880186, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颉)*/
	{.bitmap_index = 880314, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颊)*/
	{.bitmap_index = 880442, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颌)*/
	{.bitmap_index = 880578, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颍)*/
	{.bitmap_index = 880706, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颏)*/
	{.bitmap_index = 880834, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(颐)*/
	{.bitmap_index = 880962, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(频)*/
	{.bitmap_index = 881090, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颓)*/
	{.bitmap_index = 881218, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颔)*/
	{.bitmap_index = 881354, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颖)*/
	{.bitmap_index = 881490, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颗)*/
	{.bitmap_index = 881618, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(题)*/
	{.bitmap_index = 881738, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颚)*/
	{.bitmap_index = 881866, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(颛)*/
	{.bitmap_index = 881994, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颜)*/
	{.bitmap_index = 882130, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(额)*/
	{.bitmap_index = 882258, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颞)*/
	{.bitmap_index = 882386, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颟)*/
	{.bitmap_index = 882522, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颠)*/
	{.bitmap_index = 882650, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(颡)*/
	{.bitmap_index = 882770, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颢)*/
	{.bitmap_index = 882898, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颤)*/
	{.bitmap_index = 883034, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颥)*/
	{.bitmap_index = 883162, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(颦)*/
	{.bitmap_index = 883282, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(颧)*/
	{.bitmap_index = 883418, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(风)*/
	{.bitmap_index = 883538, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(飑)*/
	{.bitmap_index = 883666, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(飒)*/
	{.bitmap_index = 883802, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(飓)*/
	{.bitmap_index = 883922, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(飕)*/
	{.bitmap_index = 884042, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(飘)*/
	{.bitmap_index = 884162, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(飙)*/
	{.bitmap_index = 884282, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(飚)*/
	{.bitmap_index = 884402, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(飞)*/
	{.bitmap_index = 884522, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(食)*/
	{.bitmap_index = 884658, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(飧)*/
	{.bitmap_index = 884794, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(飨)*/
	{.bitmap_index = 884930, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(餍)*/
	{.bitmap_index = 885058, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(餐)*/
	{.bitmap_index = 885194, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(餮)*/
	{.bitmap_index = 885330, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饔)*/
	{.bitmap_index = 885466, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饕)*/
	{.bitmap_index = 885602, .adv_w = 10, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(饣)*/
	{.bitmap_index = 885682, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饥)*/
	{.bitmap_index = 885818, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饧)*/
	{.bitmap_index = 885954, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饨)*/
	{.bitmap_index = 886082, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饩)*/
	{.bitmap_index = 886218, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饪)*/
	{.bitmap_index = 886346, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饫)*/
	{.bitmap_index = 886482, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饬)*/
	{.bitmap_index = 886610, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饭)*/
	{.bitmap_index = 886746, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饮)*/
	{.bitmap_index = 886882, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饯)*/
	{.bitmap_index = 887010, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饰)*/
	{.bitmap_index = 887138, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饱)*/
	{.bitmap_index = 887266, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饲)*/
	{.bitmap_index = 887394, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饴)*/
	{.bitmap_index = 887522, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饵)*/
	{.bitmap_index = 887642, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饶)*/
	{.bitmap_index = 887778, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饷)*/
	{.bitmap_index = 887906, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饺)*/
	{.bitmap_index = 888034, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饼)*/
	{.bitmap_index = 888170, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(饽)*/
	{.bitmap_index = 888298, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(饿)*/
	{.bitmap_index = 888434, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馀)*/
	{.bitmap_index = 888562, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馁)*/
	{.bitmap_index = 888690, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馄)*/
	{.bitmap_index = 888818, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馅)*/
	{.bitmap_index = 888946, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馆)*/
	{.bitmap_index = 889066, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馇)*/
	{.bitmap_index = 889194, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馈)*/
	{.bitmap_index = 889330, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馊)*/
	{.bitmap_index = 889458, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馋)*/
	{.bitmap_index = 889594, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馍)*/
	{.bitmap_index = 889730, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馏)*/
	{.bitmap_index = 889858, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馐)*/
	{.bitmap_index = 889986, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馑)*/
	{.bitmap_index = 890114, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馒)*/
	{.bitmap_index = 890250, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馓)*/
	{.bitmap_index = 890386, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馔)*/
	{.bitmap_index = 890514, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馕)*/
	{.bitmap_index = 890650, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(首)*/
	{.bitmap_index = 890778, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馗)*/
	{.bitmap_index = 890906, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馘)*/
	{.bitmap_index = 891034, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(香)*/
	{.bitmap_index = 891154, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(馥)*/
	{.bitmap_index = 891290, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(馨)*/
	{.bitmap_index = 891418, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(马)*/
	{.bitmap_index = 891538, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(驭)*/
	{.bitmap_index = 891666, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(驮)*/
	{.bitmap_index = 891802, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(驯)*/
	{.bitmap_index = 891930, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驰)*/
	{.bitmap_index = 892050, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驱)*/
	{.bitmap_index = 892170, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(驳)*/
	{.bitmap_index = 892306, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(驴)*/
	{.bitmap_index = 892442, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驵)*/
	{.bitmap_index = 892562, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(驶)*/
	{.bitmap_index = 892690, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驷)*/
	{.bitmap_index = 892810, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驸)*/
	{.bitmap_index = 892938, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驹)*/
	{.bitmap_index = 893066, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驺)*/
	{.bitmap_index = 893194, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驻)*/
	{.bitmap_index = 893322, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驼)*/
	{.bitmap_index = 893450, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驽)*/
	{.bitmap_index = 893578, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驾)*/
	{.bitmap_index = 893698, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(驿)*/
	{.bitmap_index = 893818, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骀)*/
	{.bitmap_index = 893946, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骁)*/
	{.bitmap_index = 894074, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(骂)*/
	{.bitmap_index = 894179, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骄)*/
	{.bitmap_index = 894307, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骅)*/
	{.bitmap_index = 894443, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骆)*/
	{.bitmap_index = 894571, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骇)*/
	{.bitmap_index = 894699, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骈)*/
	{.bitmap_index = 894835, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骊)*/
	{.bitmap_index = 894955, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骋)*/
	{.bitmap_index = 895083, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(验)*/
	{.bitmap_index = 895211, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骏)*/
	{.bitmap_index = 895347, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骐)*/
	{.bitmap_index = 895475, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骑)*/
	{.bitmap_index = 895595, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骒)*/
	{.bitmap_index = 895715, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骓)*/
	{.bitmap_index = 895843, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骖)*/
	{.bitmap_index = 895979, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骗)*/
	{.bitmap_index = 896107, .adv_w = 17, .box_h = 16, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(骘)*/
	{.bitmap_index = 896235, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骚)*/
	{.bitmap_index = 896355, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骛)*/
	{.bitmap_index = 896483, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骜)*/
	{.bitmap_index = 896611, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骝)*/
	{.bitmap_index = 896731, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骞)*/
	{.bitmap_index = 896867, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骟)*/
	{.bitmap_index = 896995, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骠)*/
	{.bitmap_index = 897115, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骡)*/
	{.bitmap_index = 897235, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骢)*/
	{.bitmap_index = 897363, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骣)*/
	{.bitmap_index = 897483, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骤)*/
	{.bitmap_index = 897603, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骥)*/
	{.bitmap_index = 897731, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骧)*/
	{.bitmap_index = 897867, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(骨)*/
	{.bitmap_index = 897972, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骰)*/
	{.bitmap_index = 898100, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骱)*/
	{.bitmap_index = 898236, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骶)*/
	{.bitmap_index = 898364, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骷)*/
	{.bitmap_index = 898484, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(骸)*/
	{.bitmap_index = 898612, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骺)*/
	{.bitmap_index = 898732, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(骼)*/
	{.bitmap_index = 898860, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髀)*/
	{.bitmap_index = 898988, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髁)*/
	{.bitmap_index = 899108, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髂)*/
	{.bitmap_index = 899236, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(髅)*/
	{.bitmap_index = 899364, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(髋)*/
	{.bitmap_index = 899492, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髌)*/
	{.bitmap_index = 899620, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(髑)*/
	{.bitmap_index = 899748, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髓)*/
	{.bitmap_index = 899868, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(高)*/
	{.bitmap_index = 899996, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髟)*/
	{.bitmap_index = 900124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(髡)*/
	{.bitmap_index = 900252, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髦)*/
	{.bitmap_index = 900372, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髫)*/
	{.bitmap_index = 900492, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髭)*/
	{.bitmap_index = 900612, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髯)*/
	{.bitmap_index = 900732, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髹)*/
	{.bitmap_index = 900860, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(髻)*/
	{.bitmap_index = 900980, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鬃)*/
	{.bitmap_index = 901116, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鬈)*/
	{.bitmap_index = 901236, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鬏)*/
	{.bitmap_index = 901372, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鬓)*/
	{.bitmap_index = 901508, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鬟)*/
	{.bitmap_index = 901644, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鬣)*/
	{.bitmap_index = 901780, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鬯)*/
	{.bitmap_index = 901892, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鬲)*/
	{.bitmap_index = 901997, .adv_w = 15, .box_h = 15, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鬻)*/
	{.bitmap_index = 902102, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鬼)*/
	{.bitmap_index = 902238, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魁)*/
	{.bitmap_index = 902366, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(魂)*/
	{.bitmap_index = 902502, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魃)*/
	{.bitmap_index = 902630, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(魄)*/
	{.bitmap_index = 902766, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魅)*/
	{.bitmap_index = 902894, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(魇)*/
	{.bitmap_index = 903022, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魈)*/
	{.bitmap_index = 903150, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魉)*/
	{.bitmap_index = 903278, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魍)*/
	{.bitmap_index = 903406, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(魏)*/
	{.bitmap_index = 903542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(魑)*/
	{.bitmap_index = 903670, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(魔)*/
	{.bitmap_index = 903806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鱼)*/
	{.bitmap_index = 903934, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鱿)*/
	{.bitmap_index = 904062, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲁)*/
	{.bitmap_index = 904190, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲂)*/
	{.bitmap_index = 904318, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲅)*/
	{.bitmap_index = 904454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲆)*/
	{.bitmap_index = 904582, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲇)*/
	{.bitmap_index = 904710, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲈)*/
	{.bitmap_index = 904846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲋)*/
	{.bitmap_index = 904974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲍)*/
	{.bitmap_index = 905102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲎)*/
	{.bitmap_index = 905230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲐)*/
	{.bitmap_index = 905358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲑)*/
	{.bitmap_index = 905486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲒)*/
	{.bitmap_index = 905614, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲔)*/
	{.bitmap_index = 905742, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲕)*/
	{.bitmap_index = 905870, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲚)*/
	{.bitmap_index = 906006, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲛)*/
	{.bitmap_index = 906134, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲜)*/
	{.bitmap_index = 906262, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲞)*/
	{.bitmap_index = 906390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲟)*/
	{.bitmap_index = 906518, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲠)*/
	{.bitmap_index = 906654, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲡)*/
	{.bitmap_index = 906782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲢)*/
	{.bitmap_index = 906910, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲣)*/
	{.bitmap_index = 907030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲤)*/
	{.bitmap_index = 907158, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲥)*/
	{.bitmap_index = 907286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲦)*/
	{.bitmap_index = 907414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲧)*/
	{.bitmap_index = 907542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲨)*/
	{.bitmap_index = 907670, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲩)*/
	{.bitmap_index = 907806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲫)*/
	{.bitmap_index = 907934, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲭)*/
	{.bitmap_index = 908062, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲮)*/
	{.bitmap_index = 908198, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲰)*/
	{.bitmap_index = 908326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲱)*/
	{.bitmap_index = 908454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲲)*/
	{.bitmap_index = 908582, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲳)*/
	{.bitmap_index = 908710, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲴)*/
	{.bitmap_index = 908838, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲵)*/
	{.bitmap_index = 908974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲶)*/
	{.bitmap_index = 909102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲷)*/
	{.bitmap_index = 909230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲸)*/
	{.bitmap_index = 909358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲺)*/
	{.bitmap_index = 909486, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲻)*/
	{.bitmap_index = 909614, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鲼)*/
	{.bitmap_index = 909750, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鲽)*/
	{.bitmap_index = 909878, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳃)*/
	{.bitmap_index = 910006, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳄)*/
	{.bitmap_index = 910134, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳅)*/
	{.bitmap_index = 910262, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鳆)*/
	{.bitmap_index = 910398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳇)*/
	{.bitmap_index = 910526, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳊)*/
	{.bitmap_index = 910654, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳋)*/
	{.bitmap_index = 910782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳌)*/
	{.bitmap_index = 910910, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳍)*/
	{.bitmap_index = 911038, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳎)*/
	{.bitmap_index = 911158, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳏)*/
	{.bitmap_index = 911286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳐)*/
	{.bitmap_index = 911414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳓)*/
	{.bitmap_index = 911542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳔)*/
	{.bitmap_index = 911670, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳕)*/
	{.bitmap_index = 911798, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳖)*/
	{.bitmap_index = 911926, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鳗)*/
	{.bitmap_index = 912062, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳘)*/
	{.bitmap_index = 912190, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳙)*/
	{.bitmap_index = 912318, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鳜)*/
	{.bitmap_index = 912454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳝)*/
	{.bitmap_index = 912582, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鳞)*/
	{.bitmap_index = 912718, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳟)*/
	{.bitmap_index = 912846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鳢)*/
	{.bitmap_index = 912974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸟)*/
	{.bitmap_index = 913102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸠)*/
	{.bitmap_index = 913230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸡)*/
	{.bitmap_index = 913358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸢)*/
	{.bitmap_index = 913486, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鸣)*/
	{.bitmap_index = 913598, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鸥)*/
	{.bitmap_index = 913710, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸦)*/
	{.bitmap_index = 913838, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸨)*/
	{.bitmap_index = 913966, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸩)*/
	{.bitmap_index = 914094, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸪)*/
	{.bitmap_index = 914222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸫)*/
	{.bitmap_index = 914350, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸬)*/
	{.bitmap_index = 914478, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鸭)*/
	{.bitmap_index = 914590, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鸯)*/
	{.bitmap_index = 914718, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸱)*/
	{.bitmap_index = 914846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸲)*/
	{.bitmap_index = 914974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸳)*/
	{.bitmap_index = 915102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸵)*/
	{.bitmap_index = 915230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸶)*/
	{.bitmap_index = 915358, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鸷)*/
	{.bitmap_index = 915494, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸸)*/
	{.bitmap_index = 915622, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸹)*/
	{.bitmap_index = 915750, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸺)*/
	{.bitmap_index = 915878, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸽)*/
	{.bitmap_index = 916006, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鸾)*/
	{.bitmap_index = 916142, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鸿)*/
	{.bitmap_index = 916270, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹁)*/
	{.bitmap_index = 916398, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹂)*/
	{.bitmap_index = 916526, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鹃)*/
	{.bitmap_index = 916638, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹄)*/
	{.bitmap_index = 916766, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹅)*/
	{.bitmap_index = 916894, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹆)*/
	{.bitmap_index = 917022, .adv_w = 15, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*(鹇)*/
	{.bitmap_index = 917134, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹈)*/
	{.bitmap_index = 917262, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹉)*/
	{.bitmap_index = 917390, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹊)*/
	{.bitmap_index = 917518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹋)*/
	{.bitmap_index = 917646, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹌)*/
	{.bitmap_index = 917774, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹎)*/
	{.bitmap_index = 917902, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹏)*/
	{.bitmap_index = 918030, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹑)*/
	{.bitmap_index = 918158, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鹕)*/
	{.bitmap_index = 918294, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹗)*/
	{.bitmap_index = 918422, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鹘)*/
	{.bitmap_index = 918558, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹚)*/
	{.bitmap_index = 918686, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹛)*/
	{.bitmap_index = 918814, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹜)*/
	{.bitmap_index = 918942, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹞)*/
	{.bitmap_index = 919070, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹣)*/
	{.bitmap_index = 919198, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹤)*/
	{.bitmap_index = 919326, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹦)*/
	{.bitmap_index = 919454, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹧)*/
	{.bitmap_index = 919582, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鹨)*/
	{.bitmap_index = 919718, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹩)*/
	{.bitmap_index = 919846, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹪)*/
	{.bitmap_index = 919974, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹫)*/
	{.bitmap_index = 920102, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹬)*/
	{.bitmap_index = 920230, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹭)*/
	{.bitmap_index = 920358, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹰)*/
	{.bitmap_index = 920486, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鹱)*/
	{.bitmap_index = 920622, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹳)*/
	{.bitmap_index = 920750, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鹾)*/
	{.bitmap_index = 920878, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鹿)*/
	{.bitmap_index = 921014, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(麂)*/
	{.bitmap_index = 921150, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麇)*/
	{.bitmap_index = 921270, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麈)*/
	{.bitmap_index = 921398, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麋)*/
	{.bitmap_index = 921518, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麒)*/
	{.bitmap_index = 921646, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(麓)*/
	{.bitmap_index = 921782, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麝)*/
	{.bitmap_index = 921910, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(麟)*/
	{.bitmap_index = 922046, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(麦)*/
	{.bitmap_index = 922182, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麴)*/
	{.bitmap_index = 922310, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(麸)*/
	{.bitmap_index = 922446, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(麻)*/
	{.bitmap_index = 922582, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麽)*/
	{.bitmap_index = 922710, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(麾)*/
	{.bitmap_index = 922838, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黄)*/
	{.bitmap_index = 922966, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黉)*/
	{.bitmap_index = 923102, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黍)*/
	{.bitmap_index = 923222, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黎)*/
	{.bitmap_index = 923350, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黏)*/
	{.bitmap_index = 923470, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黑)*/
	{.bitmap_index = 923598, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黔)*/
	{.bitmap_index = 923734, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(默)*/
	{.bitmap_index = 923870, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黛)*/
	{.bitmap_index = 924006, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黜)*/
	{.bitmap_index = 924134, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黝)*/
	{.bitmap_index = 924254, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黟)*/
	{.bitmap_index = 924390, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黠)*/
	{.bitmap_index = 924510, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黢)*/
	{.bitmap_index = 924646, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黥)*/
	{.bitmap_index = 924766, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黧)*/
	{.bitmap_index = 924902, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黩)*/
	{.bitmap_index = 925038, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(黪)*/
	{.bitmap_index = 925174, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黯)*/
	{.bitmap_index = 925302, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黹)*/
	{.bitmap_index = 925430, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黻)*/
	{.bitmap_index = 925550, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(黼)*/
	{.bitmap_index = 925678, .adv_w = 17, .box_h = 15, .box_w = 16, .ofs_x = 1, .ofs_y = 4},/*(黾)*/
	{.bitmap_index = 925798, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鼋)*/
	{.bitmap_index = 925918, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鼍)*/
	{.bitmap_index = 926038, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼎)*/
	{.bitmap_index = 926166, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼐)*/
	{.bitmap_index = 926294, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼓)*/
	{.bitmap_index = 926422, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼗)*/
	{.bitmap_index = 926558, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鼙)*/
	{.bitmap_index = 926686, .adv_w = 17, .box_h = 17, .box_w = 16, .ofs_x = 1, .ofs_y = 3},/*(鼠)*/
	{.bitmap_index = 926822, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼢)*/
	{.bitmap_index = 926958, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(鼬)*/
	{.bitmap_index = 927086, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼯)*/
	{.bitmap_index = 927214, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼷)*/
	{.bitmap_index = 927342, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼹)*/
	{.bitmap_index = 927470, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼻)*/
	{.bitmap_index = 927606, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼽)*/
	{.bitmap_index = 927742, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(鼾)*/
	{.bitmap_index = 927878, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(齄)*/
	{.bitmap_index = 928014, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(齐)*/
	{.bitmap_index = 928150, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(齑)*/
	{.bitmap_index = 928286, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(齿)*/
	{.bitmap_index = 928414, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龀)*/
	{.bitmap_index = 928542, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龃)*/
	{.bitmap_index = 928670, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(龄)*/
	{.bitmap_index = 928806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龅)*/
	{.bitmap_index = 928934, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龆)*/
	{.bitmap_index = 929054, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龇)*/
	{.bitmap_index = 929182, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(龈)*/
	{.bitmap_index = 929310, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龉)*/
	{.bitmap_index = 929438, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龊)*/
	{.bitmap_index = 929558, .adv_w = 16, .box_h = 15, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龋)*/
	{.bitmap_index = 929678, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(龌)*/
	{.bitmap_index = 929806, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龙)*/
	{.bitmap_index = 929934, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(龚)*/
	{.bitmap_index = 930070, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*(龛)*/
	{.bitmap_index = 930206, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龟)*/
	{.bitmap_index = 930334, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 4},/*(龠)*/
	{.bitmap_index = 930462, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*()*/
	{.bitmap_index = 930560, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*()*/
	{.bitmap_index = 930658, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*()*/
	{.bitmap_index = 930756, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*()*/
	{.bitmap_index = 930854, .adv_w = 15, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = 4},/*()*/
	{.bitmap_index = 0, .adv_w = 16, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 136, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 232, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 344, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 440, .adv_w = 12, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 506, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 634, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 762, .adv_w = 18, .box_h = 14, .box_w = 18, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 888, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1016, .adv_w = 18, .box_h = 12, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1124, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1252, .adv_w = 8, .box_h = 14, .box_w = 8, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1308, .adv_w = 12, .box_h = 14, .box_w = 12, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 1392, .adv_w = 18, .box_h = 16, .box_w = 18, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1536, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 1632, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 1728, .adv_w = 12, .box_h = 16, .box_w = 10, .ofs_x = 2, .ofs_y = 0},/*()*/
	{.bitmap_index = 1808, .adv_w = 14, .box_h = 18, .box_w = 14, .ofs_x = 0, .ofs_y = -1},/*()*/
	{.bitmap_index = 1934, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 2032, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 2130, .adv_w = 12, .box_h = 16, .box_w = 10, .ofs_x = 2, .ofs_y = 0},/*()*/
	{.bitmap_index = 2210, .adv_w = 15, .box_h = 14, .box_w = 16, .ofs_x = -1, .ofs_y = 1},/*()*/
	{.bitmap_index = 2322, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 2392, .adv_w = 10, .box_h = 14, .box_w = 10, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 2462, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 2560, .adv_w = 14, .box_h = 3, .box_w = 14, .ofs_x = 0, .ofs_y = 6},/*()*/
	{.bitmap_index = 2581, .adv_w = 18, .box_h = 12, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 2689, .adv_w = 20, .box_h = 16, .box_w = 20, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 2849, .adv_w = 19, .box_h = 16, .box_w = 20, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 3009, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 3137, .adv_w = 14, .box_h = 10, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 3207, .adv_w = 14, .box_h = 10, .box_w = 14, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 3277, .adv_w = 20, .box_h = 14, .box_w = 20, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 3417, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 3513, .adv_w = 16, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 3641, .adv_w = 17, .box_h = 17, .box_w = 18, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 3794, .adv_w = 16, .box_h = 14, .box_w = 16, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 3906, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 4018, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4116, .adv_w = 14, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 4214, .adv_w = 16, .box_h = 12, .box_w = 16, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 4310, .adv_w = 11, .box_h = 16, .box_w = 12, .ofs_x = -1, .ofs_y = 0},/*()*/
	{.bitmap_index = 4406, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 4518, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 4630, .adv_w = 18, .box_h = 12, .box_w = 18, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 4738, .adv_w = 17, .box_h = 18, .box_w = 18, .ofs_x = -1, .ofs_y = -1},/*()*/
	{.bitmap_index = 4900, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 4996, .adv_w = 20, .box_h = 15, .box_w = 20, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 5146, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5246, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5346, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5446, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5546, .adv_w = 20, .box_h = 10, .box_w = 20, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 5646, .adv_w = 22, .box_h = 14, .box_w = 22, .ofs_x = 0, .ofs_y = 1},/*()*/
	{.bitmap_index = 5800, .adv_w = 13, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = 0},/*()*/
	{.bitmap_index = 5896, .adv_w = 14, .box_h = 16, .box_w = 14, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 6008, .adv_w = 17, .box_h = 17, .box_w = 18, .ofs_x = -1, .ofs_y = -1},/*()*/
	{.bitmap_index = 6161, .adv_w = 20, .box_h = 12, .box_w = 20, .ofs_x = 0, .ofs_y = 2},/*()*/
	{.bitmap_index = 6281, .adv_w = 12, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = 0},/*()*/
	{.bitmap_index = 6377, .adv_w = 16, .box_h = 11, .box_w = 16, .ofs_x = 0, .ofs_y = 3},/*()*/
	{.bitmap_index = 930952, .adv_w = 6, .box_h = 14, .box_w = 4, .ofs_x = 2, .ofs_y = 4},/*(！)*/
	{.bitmap_index = 930980, .adv_w = 16, .box_h = 17, .box_w = 6, .ofs_x = 10, .ofs_y = 3},/*(（)*/
	{.bitmap_index = 931031, .adv_w = 6, .box_h = 17, .box_w = 6, .ofs_x = 0, .ofs_y = 3},/*(）)*/
	{.bitmap_index = 931082, .adv_w = 6, .box_h = 5, .box_w = 4, .ofs_x = 2, .ofs_y = 2},/*(，)*/
	{.bitmap_index = 931092, .adv_w = 6, .box_h = 10, .box_w = 4, .ofs_x = 2, .ofs_y = 4},/*(：)*/
	{.bitmap_index = 931112, .adv_w = 6, .box_h = 12, .box_w = 4, .ofs_x = 2, .ofs_y = 2},/*(；)*/
	{.bitmap_index = 931136, .adv_w = 10, .box_h = 15, .box_w = 10, .ofs_x = 0, .ofs_y = 4},/*(？)*/
	{.bitmap_index = 931211, .adv_w = 13, .box_h = 15, .box_w = 10, .ofs_x = 3, .ofs_y = 4},/*(￥)*/

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


//static uint8_t __g_font_buf[171];
static uint32_t last_letter;
static uint32_t last_glyph_id;  

static bool __user_font_get_glyph_dsc(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next);
static const uint8_t * __user_font_get_bitmap(const lv_font_t * font, uint32_t unicode_letter);

#define FONT_NAME opensansb16_fname

//字体名称: my_font
//字模高度: 26
//外部bin文件,字体信息等级:Level0
lv_font_t opensansb16_fname = {
    .get_glyph_bitmap = __user_font_get_bitmap,
    .get_glyph_dsc = __user_font_get_glyph_dsc,
    .line_height = 26,
    .base_line = 0,
};

//fat_2024-09-12.img 
static volatile uint32_t offset_read=0;

static uint8_t *__user_font_getdata(uint32_t offset, int size){

    if (0 == offset_read)
    {
        offset_read = 0+(2+sizeof(x_header_check_t)*UT_FONT_CNT);
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
    
    if (((unicode_letter >= 0x370) && (unicode_letter <= 0x3FF))
             || ((unicode_letter >= 0x530) && (unicode_letter <= 0x58F))
             )
    { 
        FONT_NAME.line_height = 20; 
        FONT_NAME.base_line = 1;
    }
    else if (((unicode_letter >= 0x20) && (unicode_letter <= 0x24F))
             || ((unicode_letter >= 0x400) && (unicode_letter <= 0x4FF))
             || ((unicode_letter >= 0X4E00) && (unicode_letter <= 0x9FFF))
             || ((unicode_letter >= 0XFF00) && (unicode_letter <= 0xFFE5))
             )
    { 
        FONT_NAME.line_height = 21;  
        FONT_NAME.base_line = 0; 
    }
    else if ((unicode_letter >= 0x3041) && (unicode_letter <= 0x30FF))
    { 
        FONT_NAME.line_height = 26; 
        FONT_NAME.base_line = 5;
    } 

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


