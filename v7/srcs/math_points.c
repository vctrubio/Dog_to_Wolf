#include "../include/header.h"

int	collide(t_game *game, t_point p, int angle)
{	
	return (edge_collide(game, p) || wall_collide(game, p, angle));
}

t_point	p(double x, double y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point	add_point(t_point p1, t_point p2)
{
	return (p(p1.x + p2.x, p1.y + p2.y));
}
