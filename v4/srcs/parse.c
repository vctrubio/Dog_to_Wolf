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

void	texture_path(t_texture *texture, char *str, int data)
{
	if (data == 1)
		texture->north_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 2)
		texture->south_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 3)
		texture->west_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 4)
		texture->east_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 5)
		texture->floor = ft_substr(str, my_strnstr(str, 1), ft_strlen(str));
	else if (data == 6)
		texture->cealing = ft_substr(str, my_strnstr(str, 1), ft_strlen(str));
}

int		map_data_lvl1(t_texture *texture, char *str)
{
	if (!ft_strncmp("NO", str, 2))
	{
		texture_path(texture, str, 1);
		texture->texture_count++;
	}
	else if (!ft_strncmp("SO", str, 2))
	{
		texture_path(texture, str, 2);
		texture->texture_count++;
	}
	else if (!ft_strncmp("WE", str, 2))
	{
		texture_path(texture, str, 3);
		texture->texture_count++;
	}
	else if (!ft_strncmp("EA", str, 2))
	{
		texture_path(texture, str, 4);
		texture->texture_count++;
	}
	else if (!ft_strncmp("F", str, 1))
	{
		texture_path(texture, str, 5);
		texture->texture_count++;
	}
	else if (!ft_strncmp("C", str, 1))
	{
		texture_path(texture, str, 6);
		texture->texture_count++;
	}
	return (0);
}

int		map_data(char *str)
{
	int			i;
	char		*str_cp;
	t_texture	*texture;

	if (str[0] == '\0')
		return (0);
	i = 0;
	texture = _texture();
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
		printf("%s\n", str);
	str_cp = ft_substr(str, i, ft_strlen(str));
	if (!ft_strncmp("NO", str_cp, 2) || !ft_strncmp("SO", str_cp, 2)
		|| !ft_strncmp("WE", str_cp, 2) || !ft_strncmp("EA", str_cp, 2)
		|| !ft_strncmp("F", str_cp, 1) || !ft_strncmp("C", str_cp, 1))
	{
		map_data_lvl1(texture, str_cp);
		if (texture->texture_count < 6)
		{
			free(str_cp);
			return (0);
		}
	}
	else
	{
		printf("ERROR: Wrong argument\n");
		exit(1);
	}
	free(str_cp);
	printf("#########################################%s\n", texture->north_texture);
	printf("#########################################%s\n", texture->south_texture);
	printf("#########################################%s\n", texture->west_texture);
	printf("#########################################%s\n", texture->east_texture);
	printf("#########################################%s\n", texture->floor);
	printf("#########################################%s\n", texture->cealing);
	return (1);
}

void	init_map(t_list *lst)
{
	t_map	*map;
	int		i;
	
	map = _map();
	i = 0;
	while (!map_data((char*)lst->content))
	{
		lst = lst->next;
		i++;
	}
	map->max_y = ft_lstsize(lst);
	//map->max_x = ft_strlen(lst->content); //assuming its even
	map->map = ft_calloc((map->max_y + 1), sizeof(char *));
	
	while (lst)
	{
		printf("Chega aqui %s\n", (char*)lst->content);
		map->map[i++] = (char*)lst->content;
		lst = lst->next;
	}
	map->map[i] = NULL;
	//map_data();
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
