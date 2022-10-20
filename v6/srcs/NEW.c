#include "../include/header.h"

double	ft_normalize_angle(double angle);


static void	assign_ray(t_ray *ray, t_point *collis, double dist_wall, int coord)
{
	ray->collision->x = collis->x;
	ray->collision->y = collis->y;
	ray->dist_wall = dist_wall;
	ray->coord = coord;
}


void		cast_ray(t_game *vars, double ray_angle, int coord,
							t_point *next)
{
	t_point	step;
	double	x_chk;
	double	y_chk;

	(coord == HORZ) ?
		horz_inter(vars, next, ray_angle, &step) :
		vert_inter(vars, next, ray_angle, &step);
	while (!is_end_window(vars->map, next->x, next->y))
	{
		x_chk = next->x + ((ray_facing(ray_angle, ray_left) && coord == VERT) ?
					-1 : 0);
		x_chk += ((ray_facing(ray_angle, ray_right) && coord == VERT) ? 1 : 0);
		y_chk = next->y + ((ray_facing(ray_angle, ray_down) && coord == HORZ) ?
				1 : 0);
		y_chk += ((ray_facing(ray_angle, ray_up) && coord == HORZ) ? -1 : 0);
		if (is_wall(vars->map, x_chk, y_chk, '1'))
			break ;
		else
		{
			next->x += step.x;
			next->y += step.y;
		}
	}
}


void	check_closest_wall(t_game *vars, t_ray *ray, double ray_angle)
{
	t_point	horz_intercept;
	t_point	vert_intercept;
	double	dist_horz;
	double	dist_vert;

	cast_ray(vars, ray_angle, HORZ, &horz_intercept);
	cast_ray(vars, ray_angle, VERT, &vert_intercept);
	dist_horz = is_end_window(vars->map, horz_intercept.x, horz_intercept.y) ?
	INT_MAX : dist_btw_points(vars->player->posit->x, vars->player->posit->y,
	horz_intercept.x, horz_intercept.y);
	dist_vert = is_end_window(vars->map, vert_intercept.x, vert_intercept.y) ?
	INT_MAX : dist_btw_points(vars->player->posit->x, vars->player->posit->y,
	vert_intercept.x, vert_intercept.y);
	if (dist_horz < dist_vert)
		assign_ray(ray, &horz_intercept, dist_horz, HORZ);
	else
		assign_ray(ray, &vert_intercept, dist_vert, VERT);
}


void new_calc_game(void)
{
	int i;

	i = 0;
	vars->player->dist_proj_plane = (vars->map->width / 2) / (tan(FOV / 2));
	while (i < vars->map->num_rays)
	{
		vars->ray[i]->ray_angle = vars->player->rotation_angle +
								  atan2(i - vars->map->num_rays / 2, vars->player->dist_proj_plane);
		vars->ray[i]->ray_angle = ft_normalize_angle(vars->ray[i]->ray_angle);
		check_closest_wall(vars, vars->ray[i], vars->ray[i]->ray_angle);
		i++;
	}
}



//math;
double	ft_normalize_angle(double angle)
{
	angle = remainder(angle, 2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}
