#include "../include/header.h"

 //my_pixel_put
void	mpp(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > img->width)
	{
		printf("TOO LARGS x=%d>img->width\n", x);
		return ;
	}
	if (y > img->height)
	{
		printf("TOO LARGE y=%d>img->height\n", y);
		return ;
	}
	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}




// int	create_rgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }
