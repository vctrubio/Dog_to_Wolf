#include "../include/header.h"

static void	draw_line(t_game *game, t_ray ray, int col)
{
	int		i;
	int		x_texture_position;
	t_img	*tex;

	tex = correct_texture(game, ray.color);
	i = -1;
	if (ray.color == 1 || ray.color == 2)
		x_texture_position = (int)(floor(ray.end.x + 1)) % TILE_SIZE;
	else
		x_texture_position = (int)(floor(ray.end.y + 1)) % TILE_SIZE;
	while (++i < game->raycast->height)
	{		
		if (i >= _pov()->center - (ray.height / 2)
			&& i <= _pov()->center + (ray.height / 2))
		{
			ray.color = texture_pixel_color(game, p(x_texture_position, (double)i), ray, tex); //BUG
			ray.color = shade(ray.dist_wall, ray.color, game);
			mpp(game->raycast, col, i, ray.color);
		}
		else if (i < _pov()->center)
			mpp(game->raycast, col, i, game->ceiling);
		else
			mpp(game->raycast, col, i, game->floor);
	}
}

int	set_wall_color(double dist, int angle, t_game *game)
{
	if (angle < 0)
		angle = r_angle(360) + angle;
	else if (angle >= r_angle(360))
		angle = angle - r_angle(360);
	if (dist == nearest_horizontal(game, angle))
	{
		if (angle < r_angle(180))
			return (1);
		else
			return (2);
	}
	else
	{
		if (angle > r_angle(90) && angle < r_angle(270))
			return (3);
		else
			return (4);
	}
}


t_vector	vec(int angle, double mag)
{
	t_vector	vec;

	vec.angle = angle;
	if (vec.angle < 0)
		vec.angle = r_angle(360) + vec.angle;
	else if (vec.angle >= r_angle(360))
		vec.angle = vec.angle - r_angle(360);
	vec.mag = mag;
	return (vec);
}


t_point	add_vec(t_point p, t_vector v)
{
	t_point	res;

	res.x = p.x + (fcos(v.angle) * v.mag);
	res.y = p.y - (fsin(v.angle) * v.mag);
	return (res);
}


double	calc_dist(t_game *game, int ray_angle)
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

void	my_raycast(t_game *game)
{
	t_ray	ray;
	int		column;
	t_pov	*pov;

	pov = _pov();
	ray.angle = r_angle(30);
	column = 0;
	while (ray.angle > -r_angle(30) && column < WWIDTH)
	{
		ray.dist_wall = calc_dist(game, ray.angle);
		ray.end = add_vec(pov->p,
				vec((ray.angle + pov->angle), ray.dist_wall));
		ray.color = set_wall_color(ray.dist_wall,
				pov->angle + ray.angle, game);
		ray.height = ray.dist_wall * fcos(abs(ray.angle));
		ray.height = ((double)TILE_SIZE / ray.height) * pov->dtp;
		draw_line(game, ray, column);
		column++;
		ray.angle--;
	}
}
