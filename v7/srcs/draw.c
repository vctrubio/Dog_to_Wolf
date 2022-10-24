#include "../include/header.h"

int		unit_nb(int x)
{
		return (x * M_UNIT);
}

void	fill_img_square(t_img *img, int cord_x, int cord_y, int color)
{
	int	x;
	int	y;
	int	i;

	cord_x = unit_nb(cord_x);
	cord_y = unit_nb(cord_y);
	i = cord_x;
	y = -1;

	while (++y < M_UNIT)
	{
		x = -1;
		cord_x = i;
		while (++x < M_UNIT)
			mpp(img, cord_x++, cord_y, color);
		cord_y++;
	}
}

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

void	draw_gridline(t_img *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < img->height)
	{
		if (y % M_UNIT == 0)
		{
			x = -1;
			while (++x < img->width)
				mpp(img, x, y, MYWHITE);
		}
		x = -1;
		while (++x < img->width)
			if (x % M_UNIT == 0)
				mpp(img, x, y, MYWHITE);
	}	
}
