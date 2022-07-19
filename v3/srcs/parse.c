#include "../include/header.h"

void	draw_img_square2(t_img *img, int color, int x, int y)
{
	int	x2;
	int	y2;

	x2 = 0;
	y2 = 0;
	if (x != 0)
		x *= UNIT;
	if (y != 0)
		y *= UNIT;
	while (y2++ < UNIT)
	{
		x2 = 0;
		while (x2++ < UNIT)
			mpp(img, x++, y, color);
	}
}


void	parse_map_to_img(void)
{
	t_map	*map;
	t_img	*img;
	int	x;
	int	y;
	
	img = _game()->img;
	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				draw_img_square2(img, MYGREEN, x, y);
			else
				draw_img_square2(img, MYRED, x, y);
		}
	}	

/*
	while (++y < img->height / UNIT - 1)
	{
		x = -1;
		while (++x < img->width / UNIT)
			fill_map_pos(img, map, x, y);
	}
*/
}


void	parse_map(char *file)
{
	int		fd;
	char	*line;
	t_list	*lst;

	lst = NULL;
	fd = open("./maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		printf("no map found\n");
		exit(1);
	}
	while (get_next_line(fd, &line))
		ft_lstadd_back(&lst, ft_lstnew((void *)ft_strdup(line)));
	close(fd);
	return (init_map(lst));
}
