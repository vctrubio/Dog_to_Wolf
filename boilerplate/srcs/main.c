#include "../include/header.h"
//Boilerplate for cube3d initialization
t_window	*rtn_window(void);
t_game		*rtn_game(void);

int main()
{
	t_game	*game;

	game = rtn_game();
	game->w = rtn_window();
	game->w->mlx = mlx_init();

	game->w->window = mlx_new_window(game->w->mlx, WWIDTH, WHEIGHT, "MyCubeBS");

	key_listener(game->w->window);
	mlx_loop(game->w->mlx);
	printf("hello_end_world\n");
}

















t_window	*rtn_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->window = NULL;
	return (window);
}

t_game	*rtn_game(void)
{
	t_game	*game;

	game = _game();
	return (game);
}
