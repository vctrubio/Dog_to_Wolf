#include "../include/header.h"

void	fill_img_square(t_img *img, int cord_x, int cord_y, int color)
{
	int	x;
	int	y;
	int	i;

	cord_x = unit_nb(cord_x);
	cord_y = unit_nb(cord_y);
	i = cord_x;
	y = -1;
	while (++y < UNIT)
	{
		x = -1;
		cord_x = i;
		while (++x < UNIT)
		{
			// printf("%dentering X(%d)Y(%d) %d %d:\n", UNIT, x, y, cord_x, cord_y);
			mpp(img, cord_x++, cord_y, color);
		}
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


void	draw_game(void)
{
	t_game	*game;
	t_img	*img;

	game = _game();
	img = game->img;
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->img->img, game->pos_x, game->pos_y);
}
