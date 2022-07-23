#include "../include/header.h"
/* V4
Raycast
*/

int	gameloop(void) 
{
	// t_game	*game;

	// game = _game();
	// draw_game();
	return (0);
}


int	main()
{
	t_game		*game;

	//GAME
	game = _game();
	game->w = rtn_window();
	//PROGRAM
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");
	//MAP
	parse_map(NULL); //need to update pos_x pos_y
	print_map();

	//RAYCAST


	//MLX LOOP
	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

