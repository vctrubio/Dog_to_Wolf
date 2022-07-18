#include "../include/header.h"

void	move_img(double x, double y)
{
	t_game	*g;

	g = _game();

	printf("PLAYER CORD BEFORE %.f, %.f\n",  g->pos_x,  g->pos_y);
	if (x)
		g->pos_x += x;
	if (y)
		g->pos_y += y;
	printf("PLAYER CORD %.f, %.f\n", g->pos_x, g->pos_y);
}
