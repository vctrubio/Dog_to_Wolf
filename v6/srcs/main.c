#include "../include/header.h"
/* V6
Final NOBS
*/

void	_raycast_first_img()
{
	t_img	*img;
	
	img = _game()->raycast;
	img->img = mlx_new_image(_game()->w->mlx, 30, 30); //MAP GRID
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
	&img->endian);
}

int		gameloop() 
{
	t_game	*game;

	game = _game();
	new_calc_game();
	mlx_put_image_to_window(game->w->mlx, game->w->window, game->raycast->img, 0, 0);
	return (0);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = _game();
	game->w = _window();
	game->w->mlx = mlx_init();
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Doogy Style");
	game->raycast = ft_calloc(1, sizeof(t_img));
	return (game);
}

int	main()
{
	t_game	*game;

	game = init_game();
	if (!game)
		return (-1);
	parse_map(NULL);
	print_map();
	printf("OKFOR NOW--Printing Map\n");

	_raycast_first_img();
	

	//MLX LOOPING
	mlx_hook(game->w->window, 2, 1L<<0, test_key_code, &game); //key_down
	// mlx_loop_hook(game->w->mlx, &gameloop, NULL);
	mlx_loop(game->w->mlx);
	return (0);
}

