/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:53:24 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:15:51 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	choose_angle(char c)
{
	if (c == 'N')
		_pov()->angle = r_angle(90);
	else if (c == 'S')
		_pov()->angle = r_angle(270);
	else if (c == 'E')
		_pov()->angle = r_angle(0);
	else if (c == 'W')
		_pov()->angle = r_angle(180);
}

void	init_game01(t_map *map, t_pov *pov)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (ft_strchr("NSWE", map->map[i][j]))
			{
				choose_angle(map->map[i][j]);
				pov->p.x = (j * TILE_SIZE) + TILE_SIZE / 2;
				pov->p.y = (i * TILE_SIZE) + TILE_SIZE / 2;
			}
		}
	}
}

void	init_game(void)
{
	t_map	*map;
	t_pov	*pov;

	map = _map();
	pov = _pov();
	pov->width = WWIDTH * TILE_SIZE;
	pov->height = WHEIGHT * TILE_SIZE;
	pov->mag = MAGNITUDE;
	pov->dtp = (WWIDTH / 2) / ftan(r_angle(30));
	pov->center = WHEIGHT / 2;
	init_game01(map, pov);
}
