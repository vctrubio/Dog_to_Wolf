#include "../include/header.h"

void	init_map(t_list *lst)
{
	int		i;
	t_map	*map;
	t_list	*current;
	int		lst_counter;
	int		height = 0;
	int		width = 0;

	map = _map();
	map->valid = true;
	lst_counter = map_divide(lst);
	map->max_y = ft_lstsize(lst) - lst_counter - 1;
	map->map = ft_calloc((map->max_y + 1), sizeof(char *));
	i = 0;
	height = map->max_y;
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
			map->map[i++] = (char*)lst->content; // check for no trailing spaces at the end of map
			if (ft_strlen((char*)lst->content) > width)
				width = ft_strlen((char*)lst->content);
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
	else
	{
		_game()->height = height;
		_game()->width = width;
		map->max_x = width;
		printf("Valid map initialized: Height: %d Width: %d !GL\n", _game()->height, _game()->width);
	}
}

void	parse_map(char *file)
{
	int		fd;
	char	*line;
	t_list	*lst;

	lst = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("no map found");
	while (get_next_line(fd, &line)) {
		ft_lstadd_back(&lst, ft_lstnew((void *)ft_strdup(line)));
		free(line);
	}
	free(line);
	close(fd);
	init_map(lst);
	find_p_on_map();
}
