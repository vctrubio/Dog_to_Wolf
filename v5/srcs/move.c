#include "../include/header.h"

void	update_map_pos(int x, int y)
{
	_game()->pos_x = x;
	_game()->pos_y = y;
	// printf("UPDATEto %.1f, %.1f\n", _game()->pos_y, _game()->pos_x);
	// Add the direction var 
}

int	check_next_move(int y, int x)
{
	if (_map()->map[y][x] && _map()->map[y][x] == '0')
	{
		printf("IS FREE (%d, %d)\n", y, x);
		return (1);
	}
	else
		printf("IS NOT %c--at %d %d|\n", _map()->map[y][x], y, x);
	return (0);
}

void	move_player(int y, int x)
{
	char	player;
	int	pos_x;
	int	pos_y;

	player = _map()->player;
	pos_x = _game()->pos_x;
	pos_y = _game()->pos_y;
	printf("HELLO123 - POS is %d %d\n", pos_y, pos_x);
	if (check_next_move(pos_y + y, pos_x + x))
	{
		_map()->map[pos_y][pos_x] = '0';
		_map()->map[pos_y +y][pos_x + x] = player;
		update_map_pos(pos_x +x, pos_y + y);
		printf("completed update  NEW POS (%f,%f)\n", _game()->pos_y, _game()->pos_x);
	}
	print_map(); //for viewers eyes only
}
