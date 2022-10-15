#include "../include/header.h"

//N,S,E and W will define the start direction
void	find_p_on_map(void) 
{
	t_map	*map;
	int	y;
	int	x;

	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S' 
				|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
				{
					map->player = map->map[y][x];
					update_map_pos(x, y);
				}
		}
	}
}

void	my_map_loop(void)
{
	t_map	*map;
	t_img	*img;
	int	y;
	int	x;

	img = _game()->img;
	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				fill_img_square(img, x, y, MYRED);
			else if (map->map[y][x] == map->player)
				fill_img_square(img, x, y, MYGREEN);
			else if (map->map[y][x] == '2')
				fill_img_square(img, x, y, MYREDISH);
			else if (map->map[y][x] == '0')
				fill_img_square(img, x, y, MYWHITE);
		}
	}
}

void	my_map_init(void)
{
	t_map	*map;
	t_img	*img;
	int	y;
	int	x;

	img = _game()->img;
	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				fill_img_square(img, x, y, MYRED);
			else if (map->map[y][x] == map->player)
			{
				fill_img_square(img, x, y, MYGREEN);
				update_map_pos(x, y);
			}
			else if (map->map[y][x] == '2')
				fill_img_square(img, x, y, MYREDISH);
		}
	}
	draw_gridline();
}
// printf("eval %c at %d %d\n", map->map[y][x], y, x);
// printf("\n");1015 b