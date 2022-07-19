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

t_img	*insert_sprite(int y, int x, int color)
{
	t_img	*sprite;
	t_img	*img;

	img = _game()->img;
	sprite = rtn_img(1, 1);	
	draw_img_square(sprite, color);
	printf("sprite created\n");

	return (sprite);
}

void	my_map(void)
{
	t_map	*map;
	int	y;
	int	x;

	y = -1;
	map = _map();
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			printf("eval %c at %d %d\n", map->map[y][x], y, x);
			insert_sprite(y, x, MYRED);	
		}
	}
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
	wnl_1();

	//PARSE
	// parse_map_to_img();	

//	my_map();	
//	t_img *sprite = insert_sprite(2, 2, MYRED);
//	mlx_put_image_to_window(_game()->w->mlx, _game()->w->window, _game()->img->img, 23, 25);

	//MOVING THE PLAYER
//	game->pos_x = 18;
//	game->pos_y = 8;

	// mlx_put_image_to_window(game->w->mlx, game->w->window, game->img->img, game->pos_x, game->pos_y);
	//MLX LOOP
	// mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	key_listener();
	mlx_loop(w->mlx); //This function never returns. It is an infinite loop  that  waits for an event
	return (0);
}

