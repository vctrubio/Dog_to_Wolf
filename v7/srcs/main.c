#include "../include/header.h"

t_game	*_game(void)
{
	static t_game game;

	return (&game);
}

int	gameloop(t_pov *pov) 
{
	static int	fps = 0;
	t_game		*game = _game();

	if (fps++ == 6) {
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
	return (0);
}

static void	rtn_window(t_game *game)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	game->w = window;
	game->w->width = WWIDTH;
	game->w->height = WHEIGHT;
	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");
}

int	main(int ac, char **ag)
{
	t_game		*game;

	if (ac == 2)
		parse_map(ag[1]);
	else
		ft_exit("Please provide a path/map.ber");
	game = _game();
	rtn_window(game);
	init_game();
	init_img_game(game);
    mlx_hook(game->w->window, 3, 1L<<1, handle_key_up, _pov());
	mlx_hook(game->w->window, 2, 1L<<0, handle_key_down, _pov());
	mlx_loop_hook(game->w->mlx, &gameloop, _pov());
	mlx_loop(game->w->mlx);
	return (0);
}

