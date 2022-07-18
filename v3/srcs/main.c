#include "../include/header.h"
/* V2
move a simple img
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

	//MOVING THE PLAYER
	game->pos_x = 8;
	game->pos_y = 8;

	//MLX LOOP
	mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(w->mlx); //This function never returns. It is an infinite loop  that  waits for an event
	return (0);
}

