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


void	draw_game(void)
{
	t_game	*game;
	t_img	*img;

	game = _game();
	img = game->img;
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->img->img, game->pos_x, game->pos_y);
}
