#include "../include/header.h"

void	print_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		printf("%s\n", map->map[i]);
	printf("map...finished\n");
}

t_map	*init_map(t_list *lst)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	map->max_y = ft_lstsize(lst) - 1;
	map->max_x = ft_strlen(lst->content); //assuming its even
	map->map = ft_calloc(map->max_y + 1, sizeof(char *));
	i = 0;
	while (lst->next)
	{
		map->map[i++] = lst->content;
		lst = lst->next;
	}
	map->map[i] = NULL;
	return (map);
}

t_map	*rtn_map(void)
{
	int		fd;
	char	*line;
	t_list	*lst;

	lst = NULL;
	fd = open("./maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		printf("no map found\n"); exit(1);
	}
	while (get_next_line(fd, &line))
		ft_lstadd_back(&lst, ft_lstnew((void *)ft_strdup(line)));
	close(fd);
	return (init_map(lst));
}