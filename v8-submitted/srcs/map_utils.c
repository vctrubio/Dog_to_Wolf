/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:44:39 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:20:18 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*line_loop(int width, char *old_map)
{
	int		index;
	char	*line;

	index = -1;
	line = ft_calloc(sizeof(char), width + 1);
	while (++index < width)
	{
		if (index < (int)ft_strlen(old_map))
		{
			if (old_map[index] == ' ')
				line[index] = '1';
			else
				line[index] = old_map[index];
		}
		else
			line[index] = '1';
	}
	return (line);
}

char	**map_fill(char **old_map)
{
	int		index;
	char	**map;
	int		height;

	height = _game()->height;
	map = ft_calloc(sizeof(char *), height + 1);
	index = -1;
	while (++index < height)
	{
		map[index] = line_loop(_game()->width, old_map[index]);
		free (old_map[index]);
	}
	free (old_map);
	return (map);
}

int	tile_size(void)
{
	return ((int)round((double)TILE_SIZE / (double)MAP_SCALE));
}
