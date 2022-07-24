#include "../include/header.h"

void	init_raycast(void)
{
	t_game	*game;

	game = _game();
	game->dir_x = -1; // general idea (looking down)
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66; //first-person shooter POV
	//game-rot_speed IDK
	//game->move_speed IDK
	//game->time = 0;
	//game->old_time = 0;
}

void	raycast_first_loop(int x, int y)
{
	t_raycast	*r;

	r = _raycast();
	r->hit = 0;
	r->side = -1; //N,E,S,W
	r->camera_x = 2 * x / (double)_map()->max_x - 1;
	r->ray_dirx = _game()->dir_x + _game()->plane_x * r->camera_x;
	r->ray_diry = _game()->dir_y + _game()->plane_y * r->camera_x;
	r->map_x = _game()->pos_x;
	r->map_y = _game()->pos_y;
	r->delta_distx = fabs(1 / r->ray_dirx);
	r->delta_disty = fabs(1 / r->ray_diry);
}

void	raycast_second_loop(void)
{
	t_raycast	*r;

	r = _raycast();
	if (r->ray_dirx < 0)
	{
		r->step_x = -1;
		r->side_distx = (_game()->pos_x - r->map_x) * r->delta_distx;
	}
	else
	{
		r->step_x = 1;
		r->side_distx = (r->map_x + 1.0 - _game()->pos_x) * r->delta_distx;
	}
	if (r->ray_diry < 0)
	{
		r->step_y = -1,
		r->side_disty = (_game()->pos_y - r->map_y) * r->delta_disty;
	}
	else
	{
		r->step_y = 1,
		r->side_disty = (r->map_y + 1.0 - _game()->pos_y) * r->delta_disty;
	}
}

//DDA
void	raycast_calc_to_wall(void)
{
	t_raycast	*r;
	t_map		*m;

	r = _raycast();
	m = _map();
	while (r->hit == 0)
	{
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			r->map_x += r->step_x;
			r->side = 0;
			//if (r->step_x == 1)
			//	r->side = 0;
			//else if (r->step_x == -1)
			//	r->side = 1;
		}
		else
		{
			r->side_disty += r->delta_disty;
			r->map_y += r->step_y;
			r->side = 1;
			//if (r->step_y == 1)
			//	r->side = 2;
			//else if (r->step_y == -1)
			//	r->side = 3;
		}
		if (m->map[(int)r->map_y][(int)r->map_x] == '1') //later != 0
		{
			printf("wallhit return at (y:%.f, x:%.f)\n", r->map_y, r->map_x);
			r->hit = 1;
		}
		else
			printf("NOhit return at (y:%.f, x:%.f)\n", r->map_y, r->map_x);
	}
}


void	raycast_aftermath(void)
{
	t_raycast	*r;
	int		cube_height;

	r = _raycast();
	if (r->side == 0)
		r->perp_walldist = (r->map_x - _game()->pos_x + (1 - r->step_x) / 2) / r->ray_dirx;
	else
		r->perp_walldist = (r->map_y - _game()->pos_y + (1 - r->step_y) / 2) / r->ray_diry;
	cube_height = SDHEIGHT; //WTF IDK- IS it THE MAP->HEIGHT? MAP PENIS?
	r->lineheight = (int)(cube_height / r->perp_walldist); 
	r->draw_start = - r->lineheight / 2 + cube_height / 2; 
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->lineheight / 2 + cube_height / 2;
	if (r->draw_end >= cube_height)
		r->draw_end = cube_height - 1;
	//TBC
	
}

void	raycast_draw_texture(int pos)
{

}


void	ft_raycast(void)
{
	int	x;
	int	y;

	y = 0;
	x = -1;
	printf("ft_raycast---\n");
	while (++x <= _map()->max_x)
	{
		printf("test X = %d\n", x);
		raycast_first_loop(x, y);
		raycast_second_loop();
		raycast_calc_to_wall();
		raycast_aftermath();
		raycast_draw_texture(x);
	}
}
