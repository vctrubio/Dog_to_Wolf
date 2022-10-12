#include "../include/header.h"

void	fill_map_color(int color)
{
	t_img	*map_image;

	map_image = _game()->img;
	draw_img_square(map_image, color);
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
	printf("height draw: %d & %d\n\n", img->height, img->width);
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			mpp(img, x, y, color);
	}
}

void	draw_mini_game(void)
{
	t_game	*game;

	game = _game();
	my_map_loop();
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->img->img, 0, 0); 
}

void	draw_gridline(void)
{
	t_img	*img;
	int	y;
	int	x;

	img = _game()->img;
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
