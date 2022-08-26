#include "../include/header.h"

void	map_verify()
{
	t_map	*map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map = _map();
	while (x < ft_strlen(map->map[0]))
	{
		if (map->map[0][x] != '1')
		{
			printf("ERROR: Map open on parcel %d of line 0\n", x);
			exit(1);
		}
		x++;
	}
	x = 0;
	while (x < ft_strlen(map->map[map->max_y - 1]))
	{
		if (map->map[map->max_y - 1][x] != '1')
		{
			printf("ERROR: Map open on parcel %d of line %d\n", x, map->max_y - 1);
			exit(1);
		}
		x++;
	}
	x = 0;
	while (map->map[y])
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] != '1')
			{
				printf("ERROR: map open\n");
				exit(1);
			}
			if (x == ft_strlen(map->map[y]) - 1)
			{
				printf("chega aqui0 -------------------------------------\n");
				if (x > ft_strlen(map->map[y + 1]) - 1)
				{
					while (x > ft_strlen(map->map[y + 1]) - 1)
					{
						if (map->map[y][x] != '1')
						{
							printf("ERROR: map open on parcel %d of line %d \n", x, y);
							exit(1);
						}
						x--;
					}
				}
				else if (x < ft_strlen(map->map[y + 1]) - 1)
				{
					while (x < ft_strlen(map->map[y + 1]) - 1)
					{
						printf("chega aqui2 -------------------------------------\n");
						if (map->map[y + 1][x] != '1')
						{
							printf("ERROR: map open on parcel %d of line %d \n", x, y);
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
		if (y == map->max_y - 1)
			break;
	}
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
	map_verify();
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
