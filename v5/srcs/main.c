#include "../include/header.h"
/* V4
Raycasting
map[yvector][xvector]
minimap
*/

int	gameloop(void) 
{
	ft_raycast();
	draw_mini_game();
	return (0);
}

/* 4 STEPS
1. GAME INIT- MLX WINDOW ect.
2. PARSE OF MAP
3. RAYCAST
4. LOOPS- MLX & KEYS
*/

// make run
int	main()
{
	t_game		*game;
	t_img		*game_img_map;
	t_img		*game_img_bellow;

	game = _game();
	game->w = rtn_window();
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");

	parse_map(NULL); //NULL because no argv is passed yet
	print_map();
	game_img_map = rtn_img(WWIDTH, WHEIGHT, game->w);
	game->img = game_img_map;

	//RAYCAST
	init_raycast();
	// ft_raycast(); //to put in the gameloop- but not working yet

	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

