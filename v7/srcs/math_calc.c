#include "../include/header.h"

static int	edge_collide(t_game *game, t_point p)
{
	if (p.x < 0 || p.y < 0 || p.x / TILE_SIZE >= game->width
		|| p.y / TILE_SIZE >= game->height)
		return (1);
	return (0);
}

static int	wall_collide(t_game *game, t_point p, int angle)
{
	int	my_y;
	int	my_x;

	if (angle < r_angle(180))
		my_y = ceil((p.y)) / (TILE_SIZE);
	else
		my_y = floor((p.y)) / (TILE_SIZE);
	if (angle > r_angle(90) && angle < r_angle(270))
		my_x = ceil((p.x)) / (TILE_SIZE);
	else
		my_x = floor((p.x)) / (TILE_SIZE);
	if (_map()->map[my_y][my_x] == '1')
	{
		// printf("COLLIDE \n");
		return (1);
	}	
	return (0);
}

double	nearest_horizontal(t_game *game, int a)
{
	t_point	intersection;
	t_point	p_const;

	if (a < r_angle(180))
		intersection.y = floor(_pov()->p.y / TILE_SIZE) * TILE_SIZE - 1;
	else
		intersection.y = floor(_pov()->p.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	intersection.x = _pov()->p.x + (_pov()->p.y - intersection.y) / ftan(a);
	p_const = horizontal_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	if (intersection.x < 0 || intersection.y < 0 || intersection.x / TILE_SIZE
		> game->width || intersection.y / TILE_SIZE > game->height)
		return (INT_MAX);
	return (fabs(fabs(_pov()->p.y - intersection.y) / fsin(a)));
}

double	nearest_vertical(t_game *game, int a)
{
	t_point	intersection;
	t_point	p_const;

	if (a > r_angle(90) && a < r_angle(270))
		intersection.x = floor(_pov()->p.x / TILE_SIZE) * (TILE_SIZE) - 1;
	else
		intersection.x = floor(_pov()->p.x / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
	intersection.y = _pov()->p.y
		+ ((_pov()->p.x - intersection.x) * ftan(a));
	p_const = vertical_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	if (intersection.x < 0 || intersection.y < 0 || intersection.x / TILE_SIZE
		> game->width || intersection.y / TILE_SIZE > game->height)
		return (INT_MAX);
	return (fabs(fabs(_pov()->p.x - intersection.x) / fcos(a)));
}

double	magic_distance(t_game *game, int ray_angle)
{
	int		a;
	double	ph;
	double	pv;

	a = _pov()->angle + ray_angle;
	if (a < 0)
		a = r_angle(360) + a;
	if (a >= r_angle(360))
		a = a - r_angle(360);
	ph = nearest_horizontal(game, a);
	pv = nearest_vertical(game, a);
	if (ph < pv)
		return (ph);
	else
		return (pv);
}