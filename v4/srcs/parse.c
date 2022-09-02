#include "../include/header.h"

void	map_verify()
{
	t_map	*map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map = _map();
	while (map->map[0][x] == ' ')

	while (y < map->max_y - 1)
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] != '1')
			{
				printf("E aqui que chega\n");
				printf("ERROR: map open on row %d of line %d \n", x, y);
				exit(1);
			}
			if (x == ft_strlen(map->map[y]) - 1)
			{
				printf("chega aqui0 -------------------------------------\n");
				if (x > ft_strlen(map->map[y + 1]) - 1)
				{
					while (x != ft_strlen(map->map[y + 1]) - 1)
					{
						if (map->map[y][x] != '1')
						{
							printf("ERROR: map open on row %d of line %d \n", x, y);
							exit(1);
						}
						x--;
					}
				}
				else if (x < ft_strlen(map->map[y + 1]) - 1)
				{
					while (x != ft_strlen(map->map[y + 1]) - 1)
					{
						printf("chega aqui2 -------------------------------------\n");
						if (map->map[y + 1][x] != '1')
						{
							printf("ERROR: map open on row %d of line %d \n", x, y);
							exit(1);
						}
						x++;
					}
				}
				y++;
			}
			x++;
		}
		x = ft_strlen(map->map[y]) - 1;
	}
	/*y = map->max_y - 1;
	while (y > 0)
	{
		if (map->map[y][x] != '1')
		{
			printf("ERROR: map open on row %d of line %d \n", x, y);
			exit(1);
		}
	}*/
}

int		find_x(char *str)
{
	int x;

	x = 0;
	while (!ft_isdigit(str[x]))
		x++;
	return (x);
}

void	texture_path(t_map *map, t_texture *texture, int y, int data)
{
	int	x;

	x = 0;
	if (data == 1)
		texture->north_texture = ft_substr(map->map[y],
			(int)ft_strnstr("./", map->map[y], ft_strlen(map->map[y])), ft_strlen(map->map[y]));
	if (data == 2)
		texture->south_texture = ft_substr(map->map[y],
			(int)ft_strnstr("./", map->map[y], ft_strlen(map->map[y])), ft_strlen(map->map[y]));
	if (data == 3)
		texture->west_texture = ft_substr(map->map[y],
			(int)ft_strnstr("./", map->map[y], ft_strlen(map->map[y])), ft_strlen(map->map[y]));
	if (data == 4)
		texture->east_texture = ft_substr(map->map[y],
			(int)ft_strnstr("./", map->map[y], ft_strlen(map->map[y])), ft_strlen(map->map[y]));
	if (data == 5)
	{
		x = find_x(map->map[y]);
		texture->floor = ft_substr(map->map[y], x, ft_strlen(map->map[y]));
	}
	if (data == 6)
	{
		x = find_x(map->map[y]);
		texture->cealing = ft_substr(map->map[y], x, ft_strlen(map->map[y]));
	}
}

void	map_data()
{
	int			y;
	t_map		*map;
	t_texture	*texture;

	y = 0;
	map = _map();
	texture = _texture();
	while (map->map[y])
	{
		if (!ft_strncmp("NO", map->map[y], 2))
			texture_path(map, texture, y, 1);
		else if (!ft_strncmp("SO", map->map[y], 2))
			texture_path(map, texture, y, 2);
		else if (!ft_strncmp("WE", map->map[y], 2))
			texture_path(map, texture, y, 3);
		else if (!ft_strncmp("EA", map->map[y], 2))
			texture_path(map, texture, y, 4);
		else if (!ft_strncmp("F", map->map[y], 1))
			texture_path(map, texture, y, 5);
		else if (!ft_strncmp("C", map->map[y], 1))
			texture_path(map, texture, y, 6);
		y++;
	}
	printf("#########################################%s\n", texture->north_texture);
	printf("#########################################%s\n", texture->south_texture);
	printf("#########################################%s\n", texture->west_texture);
	printf("#########################################%s\n", texture->east_texture);
	printf("#########################################%s\n", texture->floor);
	printf("#########################################%s\n", texture->cealing);
}

void	init_map(t_list *lst)
{
	t_map	*map;
	int		i;
	
	map = _map();
	map->max_y = ft_lstsize(lst);
	map->max_x = ft_strlen(lst->content); //assuming its even
	map->map = ft_calloc(map->max_y + 1, sizeof(char *));
	i = 0;
	while (lst)
	{
		map->map[i++] = (char*)lst->content;
		lst = lst->next;
	}
	map->map[i] = NULL;
	map_data();
	//map_verify();
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
	init_map(lst);
	find_p_on_map();
}
