#include "../include/header.h"

static t_img	*new_texture_image(t_window *win, char *filename)
{
	t_img	*data;

	data = (t_img *)malloc(sizeof(t_img));
	if (!data)
		return (NULL);
	data->w = win;
	data->img = mlx_xpm_file_to_image(win->mlx, filename, &data->width, &data->height);
	if (!data->img)
		printf("Error: Could not load image from xpm file\n");
	
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length, &data->endian);
	return (data);
}


void	init_walls(t_game *game, t_window *win)
{
	game->walls.east_img = new_texture_image(win, _texture()->east_texture);
	game->walls.west_img = new_texture_image(win, _texture()->west_texture);
	game->walls.north_img = new_texture_image(win, _texture()->north_texture);
	game->walls.south_img = new_texture_image(win, _texture()->south_texture);
}
