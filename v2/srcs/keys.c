#include "../include/header.h"

void	init_keys(void)
{
	_key()->W = 0;
	_key()->A = 0;
	_key()->S = 0;
	_key()->D = 0;
	_key()->Q = 0;
	_key()->E = 0;
	_key()->ESC = 0;
}

void	move_img_1(double x, double y)
{
	t_game	*g;

	g = _game();

	printf("MOVE x=%.f y=%.f\n", x, y);
	printf("PLAYER CORD BEFORE %.f, %.f\n", g->p->pos_x, g->p->pos_y);
	if (x)
		g->p->pos_x += x;
	if (y)
		g->p->pos_y += y;
	printf("PLAYER CORD %.f, %.f\n", g->p->pos_x, g->p->pos_y);
}

static int	ft_key_(int keycode)
{
	if (keycode == K_Q)
	{
		printf("Key K_Q\n");
		exit(1);
	}
	if (keycode == K_D) //move right
	{
		move_img_1(1, 0);
	}
	if (keycode == K_A) //move left
	{
		move_img_1(-1, 0);
	}
	draw_game();
	return (0);
}

int	test_key_code(int keycode)
{
	printf("hello from test %d\n", keycode);
	move_img_1(1,0);
	draw_game();
	return (keycode);
}

int	test_key_exit(int keycode)
{
	if (keycode == K_ESC)
		exit(1);
	return (0);
}

void	key_listener(void)
{
	t_game	*g;

	g = _game();
	mlx_hook(g->w->window, 2, 0, test_key_code, NULL); //key_down
	mlx_hook(g->w->window, 2, 0, test_key_exit, NULL); //key_down
	mlx_hook(g->w->window, 3, 0, test_key_code, NULL); //key_realesed

}
