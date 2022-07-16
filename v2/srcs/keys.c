#include "../include/header.h"

int	test_key_code(int keycode)
{
	if (keycode == K_ESC)
		exit(1);
	printf("hello from test_key_code %d\n", keycode);
	if (keycode == K_D)
		move_img(1,0);
	if (keycode == K_A)
		move_img(-1,0);
	if (keycode == K_S)
		move_img(0,1);
	if (keycode == K_W)
		move_img(0,-1);
	return (keycode);
}

int	test_no_event(int key)
{
	printf("test_n_event\n");
	return (0);
}

void	key_listener(void)
{
	t_game	*g;

	g = _game();
	mlx_hook(g->w->window, 2, 0, test_key_code, NULL); //key_down
	mlx_hook(g->w->window, 3, 0, test_key_code, NULL); //key_realesed
}
