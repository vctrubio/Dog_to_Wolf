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
	if (game->map[my_y][my_x] == '1')
		return (1);
	return (0);
}

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

t_point	horizontal_step(int a)
{
	static t_point	h_step[WWIDTH * 6];
	int				i;

	if (h_step[0].x > 0 || h_step[0].y > 0)
		return (h_step[a]);
	//printf("INITIALIZING!!!!!!!!!!!\n\n\n\n");
	i = 0;
	while (i < (int)r_angle(360))
	{
		if (i < (int)r_angle(180)) {
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE * -1);
			h_step[i].y = -64;
		}
		else
		{
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE);
			h_step[i].y = 64;
		}
		if (i > r_angle(90) && i < r_angle(270))
			h_step[i].x *= -1;
		//printf("COS(%d -> %d) point(%f, %f)\n", i / 6, i, h_step[i].x, h_step[i].y);
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

	// _pov()->p.y = 67.000;
	printf("....%f\n", _pov()->p.y);
	if (a < r_angle(180))
		intersection.y = floor(_pov()->p.y / TILE_SIZE) * TILE_SIZE - 1;
	else
		intersection.y = floor(_pov()->p.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	
	intersection.x = _pov()->p.x + (_pov()->p.y - intersection.y) / ftan(a);
	p_const = horizontal_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	printf("i.x i.y: %d (game height: %d) (game width: %d) CHECK x:%d y:%d\n", intersection.x, intersection.y, game->height, game->width, _map()->max_x, _map()->max_y);
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