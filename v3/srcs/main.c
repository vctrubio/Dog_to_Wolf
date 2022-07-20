#include "../include/header.h"
/* V3
create map from map.ber
parse image
put image
move image
*/

int	gameloop(void) //infinite gameloop (always running)
{
	t_game	*game;

	game = _game();
	draw_game();
	return (0);
}


int	main()
{
	t_img		*game_img_map;
	t_window	*w;
	t_game		*game; //OUR MAIN DATA STRUCTURE FOR WOLF (AKA GLOBAL VARIABLE)

	//WINDOW
	w = rtn_window();
	//MAP
	parse_map(NULL);
	print_map();
	game_img_map = rtn_img(_map()->max_x, _map()->max_y);
	//GAME
	game = _game();
	game->img = game_img_map;
	game->w = w;
	//PROGRAM
	w->window = mlx_new_window(w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");



	//PARSE
	// printf("HEIGHT is %d|%d WIDHT is %d|%d\n", _game()->img->height, _map()->max_y * UNIT, _game()->img->width, _map()->max_x * UNIT);
	//fill_map_color(MYWHITE);
	my_map_init();



	//MLX LOOP
	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(w->mlx);
	return (0);
}

