#include "../include/header.h"

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
