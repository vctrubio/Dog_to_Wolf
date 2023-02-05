/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:44:39 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/30 17:50:56 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	**list_loop(t_list *lst, int lst_counter, int *width, int index)
{
	char	**map;
	t_list	*current;

	map = ft_calloc((_map()->max_y + 1), sizeof(char *));
	while (lst)
	{
		if (lst_counter-- > -1)
		{
			current = lst;
			lst = lst->next;
			free(current->content);
		}
		else
		{
			current = lst;
			map[index++] = (char *)lst->content;
			if ((int)ft_strlen((char *)lst->content) > *width)
				*width = ft_strlen((char *)lst->content);
			lst = lst->next;
		}
		free(current);
	}
	map[index] = NULL;
	free(lst);
	return (map);
}

void	init_map(t_list *lst)
{
	t_map	*map;
	int		lst_counter;
	int		height;
	int		width;

	width = 0;
	map = _map();
	map->valid = true;
	lst_counter = map_divide(lst);
	map->max_y = ft_lstsize(lst) - lst_counter - 1;
	height = map->max_y;
	map->map = list_loop(lst, lst_counter, &width, 0);
	p_parse(map->map);
	if (!map->valid)
		ft_exit("Invalid map");
	else
	{
		_game()->height = height;
		_game()->width = width;
		map->max_x = width;
	}
}

bool	check_end_name(char *str, char *name)
{
	int	len;

	if (!str || !name)
		return (NULL);
	len = ft_strlen(name);
	if (len > (int)ft_strlen(str))
		return (false);
	while (*str)
		str++;
	str -= len;
	while (*str)
	{
		if (*str != *name)
			return (false);
		str++;
		name++;
	}
	return (true);
}

void	parse_map(char *file)
{
	int		fd;
	t_list	*lst;
	char	*line;

	lst = NULL;
	if (!check_end_name(file, ".cub"))
		ft_exit("Invalid map extension '.cub'");
	if (!ft_strnstr(file, ".cub", ft_strlen(file)))
		ft_exit("Wrong file format");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("No map found");
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&lst, ft_lstnew((void *)ft_strdup(line)));
		free(line);
	}
	free(line);
	close(fd);
	init_map(lst);
	_map()->map = map_fill(_map()->map);
	find_p_on_map(-1);
}
