#include "../include/header.h"

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