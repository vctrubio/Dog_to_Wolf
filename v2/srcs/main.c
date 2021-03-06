#include "../include/header.h"
/* V2
move a simple img
*/

int	gameloop(void) //infinite gameloop (always running)
{
	t_game	*game;

	game = _game();
	game->pos_x = game->p->pos_x;
	game->pos_y = game->p->pos_y;
	draw_game();
	return (0);
}

int	main()
{
	t_img		*img;
	t_window	*w;
	t_game		*game; //OUR MAIN DATA STRUCTURE FOR WOLF (AKA GLOBAL VARIABLE)

	//INITS
	w = rtn_window();
	img = rtn_img(5, 5);
	game = _game();
	game->p = img;
	game->w = w;

	//PROGRAM
	w->window = mlx_new_window(w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");
	draw_img_square(game->p, MYRED);
	init_img_pos(img, 45, 45);

	//MLX LOOP
	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(w->mlx); //This function never returns. It is an infinite loop  that  waits for an event
	return (0);
}

