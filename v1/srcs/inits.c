#include "../include/header.h"

void	init_play_pov(void)
{
	t_game	*game;

	game = _game();
	game->d_x = -1;
	game->d_y = 0.0;
	game->plane_x = 0.0;
	game->plane_y = 0.66;
}
