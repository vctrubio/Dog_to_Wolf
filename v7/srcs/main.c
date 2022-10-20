#include "../include/header.h"
/* V7
Raycast inpiration from PulgaMecanic the real Mecanic
*/

int	gameloop(void) 
{
	
	//draw_img_square(_game()->raycast, MYBLUE);
	// draw();
	return (0);
}




int	main()
{
	t_game		*game;
	t_img		*t2;


	game = _game();
	game->w = rtn_window();
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");

	parse_map(NULL); //NULL because no argv is passed yet
	// print_map();

	
	//GOOD we init window, game, texture, map
	//!=  t_ray, s_pov
	init_game();

	printf("POV WIDTH%d. \n", _pov()->width);

	init_img_game(game);




	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

