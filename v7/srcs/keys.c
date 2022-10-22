#include "../include/header.h"


static void	keys_update(int key_code, void *_pov, int press)
{
	t_pov	*pov;

	printf("KEYCODE %d\n", key_code);
	pov = _pov;
	if (key_code == K_ESC)
		freeFunction();
	if ((key_code == K_W) && pov->n_down != press)
		pov->n_down = press;
	else if ((key_code == K_S) && pov->s_down != press)
		pov->s_down = press;
	else if ((key_code == K_D) && pov->e_down != press)
		pov->e_down = press;
	else if ((key_code == K_A ) && pov->w_down != press)
		pov->w_down = press;
}

int     handle_key_up(int key_code, void *pov)
{
        keys_update(key_code, pov, 0);
        return (0);
}

int     handle_key_down(int key_code, void *pov)
{
        keys_update(key_code, pov, 1);
        return (0);
}































int	test_key_code(int keycode)
{

	printf("hello from test_key_code %d\n", keycode);
	if (keycode == K_D)
		move_player(0, 1);
	if (keycode == K_A)
		move_player(0, -1);
	if (keycode == K_S)
		move_player(1, 0);
	if (keycode == K_W)
		move_player(-1, 0);
	print_map();
	return (keycode);
}

void	key_listener(void)
{
	t_game	*g;

	g = _game();
	mlx_hook(g->w->window, 2, 1L<<0, test_key_code, &g); //key_down
	//mlx_hook(g->w->window, 3, 0, test_key_code, NULL); //key_realesed
}
