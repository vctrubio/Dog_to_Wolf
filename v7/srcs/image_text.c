#include "../include/header.h"

t_img	*correct_texture(t_game *game, int i)
{
	if (i == 1)
		return (game->walls.north_img);
	else if (i == 2)
		return (game->walls.south_img);
	else if (i == 3)
		return (game->walls.west_img);
	else
		return (game->walls.east_img);
}

unsigned int	get_texture_color(t_img *texture, int pixel_x, int pixel_y)
{
	// printf("print text addres %s\n", texture->addr);
	return MYGREEN;
	return (*(unsigned int *)((texture->addr + (pixel_y * texture->line_length) + (pixel_x * texture->bbp / 8))));
}

unsigned int	texture_pixel_color(t_game *game, t_point p, t_ray ray,
		t_img *texture)
{
	double	pixel_x;
	double	pixel_y;
	int		top;

	top = (_pov()->center) - (ray.height / 2);
	pixel_x = p.x / TILE_SIZE * texture->width;
	pixel_y = (p.y - top) / ray.height;
	pixel_y = pixel_y * texture->height;
	// printf("YESSSSSS\n");
	return (get_texture_color(texture, pixel_x, pixel_y));
}
