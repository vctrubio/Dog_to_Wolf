#include "../include/header.h"



int		find_next_line(t_map *map, int y, int x)
{
	if (x <= ft_strlen(map->map[y + 1]) && map->map[y][x] == '1'
		&& map->map[y + 1][x] == '0' && map->map[y][x + 1] == '\0')
	{
		printf("ERROR: Map open (find_next_line 1) y = %d x = %d\n", y + 1, x);
		exit(1);
	}
	else if (x <= ft_strlen(map->map[y + 1]) && map->map[y][x] == '1'
	 	&& (map->map[y + 1][x] == ' ' || map->map[y + 1][x] == '0'))
		return (0);
	else if (x <= ft_strlen(map->map[y + 1]) && map->map[y][x] == '1'
		&& map->map[y + 1][x] == '1')
	{
		printf("Y = %d  --  X = %d\n", y, x);
		return (1);
	}
	else
	{
		if (x > ft_strlen(map->map[y + 1]) - 1)
		{
			printf("Despiste de erro y = %d x = %d\n", y, x);
			return (0);
		}
		printf("ERROR: Map open (find_next_line 2) y = %d x = %d\n", y, x);
		exit(1);
	}
}

void	vertical_iterate(t_map *map, int *y, int x, int direction)
{
	if (direction == 0)
	{	
		while (find_next_line(map, *y, x))
		{
			(*y)++;
			if ( *y == map->max_y - 1)
				break;
		}
	}
	else
	{
		while (find_next_line(map, *y, x))
			(*y)--;
	}
}

void	horizontal_iterate(t_map *map, int y, int *x)
{
	if (*x < ft_strlen(map->map[y + 1]) - 1)
	{
		while (!find_next_line(map, y, *x))
		{
			printf("Para aqui0\n");
			(*x)++;
		}
	}
	else if (*x > ft_strlen(map->map[y + 1]) - 1)
	{
		while (!find_next_line(map, y, *x))
		{
			printf("Para aqui1\n");
			(*x)--;
		}
	}
}

void	map_verify_borders(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map->map[y][x] == ' ')
		x++;
	if (map->map[y][x] == '1')
		map->max_x = x++;
	else
	{
		printf("ERROR: Map open\n");
		exit(1);
	}
	printf("Max x %d and  x %d\n", map->max_x, x);
	while (y < map->max_y - 1)
	{
		horizontal_iterate(map, y, &x);
		vertical_iterate(map, &y, x, 0);
	}
		
}

int		find_x(char *str)
{
	int x;

	x = 0;
	while (!ft_isdigit(str[x]))
		x++;
	return (x);
}



void	init_map(t_list *lst)
{
	int		i;
	int		lst_counter;
	t_map	*map;
	
	map = _map();
	lst_counter = map_divide(lst);
	map->max_y = ft_lstsize(lst) - lst_counter - 1;
	map->map = ft_calloc((map->max_y + 1), sizeof(char *));
	i = 0;
	while (lst)
	{
		if (lst_counter-- > -1)
			lst = lst->next;
		else
		{
			map->map[i++] = (char*)lst->content;
			lst = lst->next;
		}
	}
	map->map[i] = NULL;
	map_verify_borders(map);
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
