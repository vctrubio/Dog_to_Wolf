#include "../include/header.h"

void	draw_line(t_game *game, t_ray ray, int col)
{
	int		i;
	int		x_texture_position;
	t_img	*tex;

	tex = correct_texture(game, ray.color);
	i = -1;
	if (ray.color == 1 || ray.color == 2)
		x_texture_position = (int)(floor(ray.end.x + 1)) % TILE_SIZE;
	else
		x_texture_position = (int)(floor(ray.end.y + 1)) % TILE_SIZE;
	while (++i < game->raycast->height)
	{		
		if (i >= _pov()->center - (ray.height / 2)
			&& i <= _pov()->center + (ray.height / 2))
		{
			ray.color = texture_pixel_color(game, p(x_texture_position, (double)i), ray, tex); //BUG
			ray.color = shade(ray.dist_wall, ray.color, game);
			mpp(game->raycast, col, i, ray.color);
		}
		else if (i < _pov()->center)
			mpp(game->raycast, col, i, convert_color(_texture()->cealing));
		else
			mpp(game->raycast, col, i, convert_color(_texture()->floor));
	}
}

void    paint_window(void)
{
    t_game  *game;
	t_img   *raycast;

    game = _game();

	raycast = new_image(game->raycast->w, game->raycast->height, game->raycast->width);
	mlx_destroy_image(game->raycast->w->mlx, game->raycast->img);
	free(game->raycast);
	game->raycast = raycast;
	my_raycast(game);
	mlx_put_image_to_window(game->raycast->w->mlx, game->raycast->w->window, raycast->img, 0, 0);
}
