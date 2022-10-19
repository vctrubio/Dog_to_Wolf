#include "../include/header.h"
/* V4
Raycasting
map[yvector][xvector]
minimap
*/

int	gameloop(void) 
{
	
	ft_raycast();






	//draw_img_square(_game()->raycast, MYBLUE);
	draw();
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
	t_img		*t2;


	game = _game();
	game->w = rtn_window();
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");

	parse_map(NULL); //NULL because no argv is passed yet
	print_map();

	//game->minimap = rtn_img(224*2, 224);

	game->raycast = rtn_img(WWIDTH, WHEIGHT);

	//draw_gridline(game->raycast);

	//RAYCAST
	init_raycast();

	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

