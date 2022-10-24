#include "../include/header.h"

int	shade(double distance, int color, t_game *game)
{
	double	factor;
	int		div;
	int		r;
	int		g;
	int		b;

	(void)div;
	if (_pov()->width < _pov()->height)
		div = _pov()->width;
	else
		div = _pov()->height;
	factor = fabs((distance / _pov()->width) - 1);
	if (factor > 1)
		factor = 1;
	r = get_r(color) * factor;
	g = get_g(color) * factor;
	b = get_b(color) * factor;
	if (r < 30)
		r = 30;
	if (g < 30)
		g = 30;
	if (b < 30)
		b = 30;
	return (gen_trgb(0, r, g, b));
}

t_img *new_image(t_window *win, int height, int width)
{
	t_img *data;

	data = (t_img *)malloc(sizeof(t_img));
	if (!data)
		return (NULL);
	data->w = win;
	data->width = width;
	data->height = height;
	data->img = mlx_new_image(win->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &(data->bbp), &(data->line_length), &(data->endian));
	return (data);
}

void init_img_game(t_game *game)
{
	game->raycast = new_image(game->w, WHEIGHT, WHEIGHT);
	init_walls(game, game->w);
	my_raycast(game);
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->raycast->img, 0, 0);
}