#include "../include/header.h"

void	destroyImage()
{
	t_window	*window;

	window = _window();
	printf("DESTROY\n");
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
