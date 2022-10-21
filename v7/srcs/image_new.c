#include "../include/header.h"

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

	printf("blablabla %d %d %s\n", win->height, win->width, data->addr);
	return (data);
}

void init_img_game(t_game *game)
{
	game->raycast = new_image(game->w, WHEIGHT, WHEIGHT);
	init_walls(game, game->w);
	my_raycast(game);
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->raycast->img, 0, 0);
}