#include "../include/header.h"

t_point	p(double x, double y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point	horizontal_step(int a)
{
	static t_point	h_step[360 * WWIDTH / 60];
	int				i;

	if (h_step[0].x > 0 || h_step[0].y > 0)
		return (h_step[a]);
	i = 0;
	while (i < (int)r_angle(360))
	{
		if (i < (int)r_angle(180))
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE * -1);
		else
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE);
		if (i > r_angle(90) && i < r_angle(270))
			h_step[i].x *= -1;
		i++;
	}
	return (h_step[a]);
}


t_point	vertical_step(int a)
{
	static t_point	v_step[360 * WWIDTH / 60];
	int				i;

	if (v_step[0].x > 0 || v_step[0].y > 0)
		return (v_step[a]);
	i = 0;
	while (i < r_angle(360))
	{
		if (i < r_angle(180))
			v_step[i] = p(TILE_SIZE, fabs(TILE_SIZE * ftan(i)) * -1);
		else
			v_step[i] = p(TILE_SIZE, fabs(TILE_SIZE * ftan(i)));
		if (i > r_angle(90) && i < r_angle(270))
			v_step[i].x *= -1;
		i++;
	}
	return (v_step[a]);
}


double	nearest_horizontal(t_game *game, int a)
{
	t_point	intersection;
	t_point	p_const;

	if (a < r_angle(180))
		intersection.y = floor(game->pov->p.y / TILE_SIZE) * TILE_SIZE - 1;
	else
		intersection.y = floor(game->pov->p.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	
	intersection.x = game->pov->p.x + (game->pov->p.y - intersection.y) / ftan(a);
	p_const = horizontal_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	if (intersection.x < 0 || intersection.y < 0 || intersection.x / TILE_SIZE
		> game->width || intersection.y / TILE_SIZE > game->height)
		return (INT_MAX);
	return (fabs(fabs(game->pov->p.y - intersection.y) / fsin(a)));
}

double	nearest_vertical(t_game *game, int a)
{
	t_point	intersection;
	t_point	p_const;

	if (a > r_angle(90) && a < r_angle(270))
		intersection.x = floor(game->pov->p.x / TILE_SIZE) * (TILE_SIZE) - 1;
	else
		intersection.x = floor(game->pov->p.x / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
	intersection.y = game->pov->p.y
		+ ((game->pov->p.x - intersection.x) * ftan(a));
	p_const = vertical_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	if (intersection.x < 0 || intersection.y < 0 || intersection.x / TILE_SIZE
		> game->width || intersection.y / TILE_SIZE > game->height)
		return (INT_MAX);
	return (fabs(fabs(game->pov->p.x - intersection.x) / fcos(a)));
}

double	magic_distance(t_game *game, int ray_angle)
{
	int		a;
	double	ph;
	double	pv;

	a = game->pov->angle + ray_angle;
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