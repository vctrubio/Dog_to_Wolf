#include "../include/header.h"

void	move_img(double x, double y)
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
