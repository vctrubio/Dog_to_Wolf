#include "../include/header.h"
/* V7
Raycast inpiration from PulgaMecanic the real Mecanic
*/

int	gameloop(t_pov *pov) 
{
	static int	fps = 0;
	t_game		*game = _game();

	//my_raycast(_game());
	if (pov->w_down || pov->n_down || pov->s_down || pov->e_down)
	{
		printf("%c", pov->w_down ? '<' : ' ');
		printf("%c", pov->n_down ? 'N' : ' ');
		printf("%c", pov->s_down ? 'v' : ' ');
		printf("%c", pov->e_down ? '>' : ' ');
		printf("\n");
	}
	if (fps++ == 5) {
		if (pov->n_down)
			move(K_W, pov);
		else if (pov->s_down)
			move(K_S, pov);
		if (pov->w_down)
			rotate(K_L, pov);
		else if (pov->e_down)
			rotate(K_R, pov);
		if (pov->n_down || pov->s_down || pov->e_down || pov->w_down)
			paint_window();
		fps = 0;
	}
	//mlx_put_image_to_window(game->w->mlx, game->w->window, game->raycast->img, 0, 0);

	// printf("whynot\n");
	// paint_window();
	return (0);
}


int	main()
{
	t_game		*game;
	t_img		*t2;


	game = _game();
	game->w = rtn_window();
	game->w->width = WWIDTH;
	game->w->height = WHEIGHT;
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");

	parse_map("./maps/map.ber");
	// print_map();
	
	//GOOD we init window, game, texture, map
	//!=  t_ray, s_pov
	init_game();
	init_img_game(game);

	printf("POV WIDTH%d. \n", _pov()->width);


	mlx_loop_hook(game->w->mlx, &gameloop, _pov());


	key_listener();
	mlx_loop(game->w->mlx);
	return (0);
}

