/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:58:51 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/24 16:31:35 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	update_map_pos(int x, int y)
{
	_game()->pos_x = x;
	_game()->pos_y = y;
}

int	check_next_move(int y, int x)
{
	if (_map()->map[y][x] && _map()->map[y][x] == '0')
		return (1);
	return (0);
}

void	move_player(int y, int x)
{
	t_map	*map;
	t_game	*game;

	map = _map();
	game = _game();
	if (check_next_move(game->pos_y + y, game->pos_x + x))
	{
		map->map[(int)game->pos_y][(int)game->pos_x] = '0';
		map->map[(int)game->pos_y + y][(int)game->pos_x + x] = map->player;
		update_map_pos((int)game->pos_x + x, (int)game->pos_y + y);
	}
}
