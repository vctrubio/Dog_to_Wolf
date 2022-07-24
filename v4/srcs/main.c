#include "../include/header.h"
/* V4
Raycasting
map[yvector][xvector]
*/

int	gameloop(void) 
{
	//ft_raycast();
	draw_mini_game();
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
	t_img		*game_img_map;

	game = _game();
	game->w = rtn_window();
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");

	parse_map(NULL);
	print_map();
	game_img_map = rtn_img(_map()->max_x, _map()->max_y, game->w);
	game->img = game_img_map;

	//RAYCAST
	ft_raycast(); //to put in the gameloop- but not working

	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

