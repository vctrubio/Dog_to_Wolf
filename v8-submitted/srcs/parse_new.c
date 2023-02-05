/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:04:24 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:38:52 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_border(char **map, int y, int x)
{
	int	len;
	int	height;

	height = _map()->max_y - 1;
	len = ft_strlen(map[y]);
	if ((y == 0 || y == height) && map[y][x] == '0')
		return (1);
	if (y > 0 && ! map[y - 1][x])
		return (1);
	if (y < height && !map[y + 1][x])
		return (1);
	if (x > 0 && ! map[y][x - 1])
		return (1);
	if (x < len && ! map[y][x + 1])
		return (1);
	return (0);
}

int	check_cord(char **map, int y, int x)
{
	if (map[y][x] == '0')
		return (1);
	return (0);
}

int	p_parse(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_cord(map, i, j))
			{
				if (is_border(map, i, j))
				{
					printf("CHECKING CORD: %d, %d = SHOULD BE BORDER;\n", i, j);
					ft_exit("GETOUTOFHERE");
				}
			}
			j++;
		}
	}
	return (1);
}
