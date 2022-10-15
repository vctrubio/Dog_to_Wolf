#include "../include/header.h"

void	destroyImage()
{
	t_window	*window;

	window = _window();
	printf("DESTROY\n");
	printf("int check %d\n", _image()->check);
	mlx_destroy_image(window->mlx, _image()->img);
	//free(window->window);
}

void	freeFunction() //bool destroy
{
	int		i;
	t_map	*map;

	i = 0;
	map = _map();
	while (i < map->max_y)
	{
		printf("%s\n", map->map[i]);
		free(map->map[i]);
		map->map[i++] = NULL;

	}
	free(map->map);
	//destroyImage();
	printf("FREE FUNCTION\n");
	exit(0);
}

int		rightSide(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1')
	{
		printf("ERROR: Map open (find_next_line 1) y = %d x = %d\n", y, x);
		//freeFunction();
	}
	else if (x <= ft_strlen(map->map[y + 1]) && map->map[y + 1][x] == '1')
	{
		printf("Y = %d  --  X = %d\n", y, x);
		return (1);
	}
	else if (x <= ft_strlen(map->map[y + 1]))
		return (0);
	else
	{
		if (x > ft_strlen(map->map[y + 1]) - 1)
			return (0);
		printf("ERROR: Map open (find_next_line 2) y = %d x = %d\n", y, x);
		exit(1);
	}
	return (0);
}

int		find_next_line(t_map *map, int y, int x, char *side)
{
	if (!ft_strncmp(side, "U_R", 3))
		return (rightSide(map, y, x));	
	return (0);
}

void	vertical_iterate(int *y, int x, char *direction, char *side)
{
	t_map *map;

	map = _map();
	if (!ft_strncmp(direction, "DOWN", 4))
	{	
		while (find_next_line(map, *y, x, side))
		{
			(*y)++;
			if ( *y == map->max_y - 1)
				break;
		}
	}
	else
	{
		while (find_next_line(map, *y, x, side))
			(*y)--;
	}
}

void	horizontal_iterate(int y, int *x, char *side)
{
	t_map *map;

	map = _map();
	if (*x <= ft_strlen(map->map[y + 1]) - 1)
	{
		while (!find_next_line(map, y, *x, side))
		{
			printf("Para aqui0\n");
			(*x)++;
		}
	}
	else if (*x > ft_strlen(map->map[y + 1]) - 1)
	{
		while (!find_next_line(map, y, *x, side))
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
	if (map->map[y][x] == '1')			// Can be simplified != 1
		map->max_x = x;
	else
	{
		printf("ERROR: Map open\n");
		exit(1);
	}
	printf("Max x %d and  x %d\n", map->max_x, x);
	while (y < map->max_y - 1)
	{
		horizontal_iterate(y, &x, "U_R");
		vertical_iterate(&y, x, "DOWN", "U_R");
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
	t_map	*map;
	t_list	*current;
	int		lst_counter;
	
	map = _map();
	map->valid = true;
	lst_counter = map_divide(lst);
	map->max_y = ft_lstsize(lst) - lst_counter - 1;
	map->map = ft_calloc((map->max_y + 1), sizeof(char *));
	i = 0;
	while (lst)
	{
		if (lst_counter-- > -1)
		{
			current = lst;
			lst = lst->next;
			free(current->content);
			free(current);
		}
		else
		{
			current = lst;
			map->map[i++] = (char*)lst->content;
			lst = lst->next;
			free(current);
		}
	}
	free(lst);
	map->map[i] = NULL;
	pParse(map->map);
	if (!map->valid)
	{
		printf("ERROR\n");
		freeFunction();
	}
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
	while (get_next_line(fd, &line)) {
		ft_lstadd_back(&lst, ft_lstnew((void *)ft_strdup(line)));
		free(line);
	}
	free(line);
	close(fd);
	init_map(lst);
	find_p_on_map();
}
