#include "../include/header.h"
/* V4
Raycasting
*/

int	gameloop(void) 
{
	// t_game	*game;

	// game = _game();
	// print_map();
	// find_p_on_map();
	// draw_game();
	return (0);
}

/* 4 STEPS
1. GAME INIT- MLX WINDOW ect.
2. PARSE OF MAP
3. RAYCAST
4. LOOPS- MLX & KEYS
*/
int	main()
{
	t_game		*game;

	game = _game();
	game->w = rtn_window();
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");
	parse_map(NULL);

	print_map();
	//RAYCAST



	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

