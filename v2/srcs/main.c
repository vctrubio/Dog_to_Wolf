#include "../include/header.h"
/* V2
move a simple img
*/

void	init_img_pos(t_img *img, double x, double y) //double because I think it will be move convinient in the future, but idfn
{
	img->pos_x = x;
	img->pos_y = y;
}

void	draw_game(void)
{
	t_game	*game;
	t_img	*img;

	game = _game();
	img = game->p;
	printf("draw_game\n");
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->p->img, img->pos_x, img->pos_y);
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
	draw_img_square(img, MYRED);
	init_img_pos(img, 0, 0);
	draw_game();

	//MLX LOOP
	key_listener();
	mlx_loop(w->mlx); //This function never returns. It is an infinite loop  that  waits for an event
	return (0);
}

