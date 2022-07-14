#include "../include/header.h"

void	init_parse(t_game *game)
{
	printf("hi parses\n");
	//create
	int x = 0;
	int	y = 0;
	t_map	*map;

	map = game->map;
	printf("max_y %d max_x %d \n", map->max_y, map->max_x);
	// select_image(game, 10, 10);
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			x++;
		}
		y++;
	}
}