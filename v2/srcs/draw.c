#include "../include/header.h"

void	draw_img_square(t_img *img, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			mpp(img, x, y, color);
	}

}
