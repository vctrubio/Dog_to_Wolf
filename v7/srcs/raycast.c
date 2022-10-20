#include "../include/header.h"

void	init_raycast(void)
{
	t_game	*game;

	game = _game();
	game->dir_x = -1 ; // general idea (looking down) // if (_map()->player == 'N')
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66; 
	game->pos_x = _game()->pos_x;
	game->pos_y = _game()->pos_y;
	game->time = 0;
	game->oldtime = 0;
}

void	wall_init(int x) //OK
{
	t_raycast	*r;

	r = _raycast();
	r->side = -1; //N,E,S,W CHANGE LATER

	r->camera_x = 2 * x / (double)_map()->max_x - 1;
	r->ray_dirx = _game()->dir_x + _game()->plane_x * r->camera_x;
	r->ray_diry = _game()->dir_y + _game()->plane_y * r->camera_x;
	r->map_x = (int)_game()->pos_x;
	r->map_y = (int)_game()->pos_y;


	r->delta_distx = fabs(1 / r->ray_dirx);
	r->delta_disty = fabs(1 / r->ray_diry);
	r->hit = 0;
}

void	ray_walking(void) //OK
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
		r->step_y = -1;
		r->side_disty = (_game()->pos_y - r->map_y) * r->delta_disty;
	}
	else
	{
		r->step_y = 1;
		r->side_disty = (r->map_y + 1.0 - _game()->pos_y) * r->delta_disty;
	}
}

//DDA
void	dda(void)
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
			if (r->step_x == 1)
				r->side = 0;
			else if (r->step_x == -1)
				r->side = 1;
		}
		else
		{
			r->side_disty += r->delta_disty;
			r->map_y += r->step_y;
			r->side = 1;
			if (r->step_y == 1)
				r->side = 2;
			else if (r->step_y == -1)
				r->side = 3;
		}
		if (m->map[(int)r->map_y][(int)r->map_x] == '1')
			r->hit = 1;
	}
}


void	wall_calc(void)
{
	t_raycast	*r;

	r = _raycast();

	if (r->side == 0) //or other sides
	{
		r->perp_walldist = (r->map_x - _game()->pos_x + (1 - r->step_x) / 2) / r->ray_dirx;
		//  r->perp_walldist = (r->side_distx - r->delta_distx);
	}	
	else
	{
		r->perp_walldist = (r->map_y - _game()->pos_y + (1 - r->step_y) / 2) / r->ray_diry;
		//  r->perp_walldist = (r->side_disty - r->delta_disty);
	}

	r->lineheight = (int)(WHEIGHT / r->perp_walldist); 

	r->draw_start = -abs(r->lineheight / 2 + WHEIGHT / 2); 
	if (r->draw_start < 0)
		r->draw_start = 0;
	//printf("TIRATEIMAS %d\n", r->draw_start);
	
	r->draw_end = r->lineheight / 2 + WHEIGHT / 2;

	if (r->draw_end >= WHEIGHT)
		r->draw_end = WHEIGHT - 1;
		printf("AQUI %f\n", r->perp_walldist);
}



void	wall_text() 
{
	double	norm;
	t_raycast	*r;

	r = _raycast();
	norm = (r->draw_start - WHEIGHT/ 2 + r->lineheight / 2);
	if (r->side == 0 || r->side == 1)
		r->wall_x = _game()->pos_y + r->perp_walldist * r->ray_diry;
	else
		r->wall_x = _game()->pos_x  + r->perp_walldist * r->ray_dirx;

	r->wall_x -= floor(r->wall_x);
	r->text_x = (int)(r->wall_x * (double)(SDHEIGHT));


	r->y = r->draw_start;
	if (r->side == 0 && r->ray_dirx > 0) //make || statement
		r->text_x == SDHEIGHT - r->text_x - 1;
	if (r->side == 1 && r->ray_diry < 0)
		r->text_x == SDHEIGHT - r->text_x - 1;

	r->step = 1.0 * SDHEIGHT / r->lineheight;
	r->text_pos = norm * r->step; // i dont have step
	r->y = r->draw_start;
}

// void	text_calc(void)
// {
	// t_raycast	*r;
	// int			norm;

	// r = _raycast();
	// while(r->y < r->draw_end)
	// {
	// 	r->text_y = (int)r->text_pos & (SDHEIGHT - 1);
	// 	r->text_pos += r->step;
	// 	norm = SDHEIGHT * r->text_y + r->text_x;
	// 	r->color = _texture()-> ;
		
	// 	r->y++;
	// }	
// }

// void	text_calc(t_info *info)
// {
// 	int	norminette;

// 	while (info->rc.y < info->rc.drawEnd)
// 	{
// 		info->rc.textY = (int)info->rc.textPos & (TEXTHEIGHT - 1);
// 		info->rc.textPos += info->rc.step;
// 		norminette = TEXTHEIGHT * info->rc.textY + info->rc.textX;
// 		if (info->rc.side == 0)
// 			info->rc.color = info->texture[0][norminette];
// 		else if (info->rc.side == 1)
// 			info->rc.color = info->texture[1][norminette];
// 		else if (info->rc.side == 2)
// 			info->rc.color = info->texture[2][norminette];
// 		else if (info->rc.side == 3)
// 			info->rc.color = info->texture[3][norminette];
// 		info->buff[info->rc.y][info->rc.x] = info->rc.color;
// 		info->rc.y++;void	text_calc(void)
// {


void	init_floor()
{
	/*int i;

	_raycast()->matrix = ft_calloc(WHEIGHT, sizeof(int**));
	while (i < WHEIGHT)
		_raycast()->matrix[i++] = ft_calloc(WWIDTH, sizeof(int*));*/

	_raycast()->draw_start = 0;
}

void	ft_raycast(void)
{
	int	x;
	int y = 0;

	x = 0;
	init_floor();
	while (x++ <= WWIDTH)
	{
		printf("test X = %d\n", x);
		wall_init(x);
		ray_walking();
		dda();
		wall_calc();
		// wall_text();
		for (int i = 0; i < _raycast()->draw_end; i++)
			mpp(_game()->raycast, x + i, y, 255);
		y++;
			
			// fill_img_square(_game()->raycast->img, x, i, MYRED); //getCOLORCORD();
	 }
	//dprint
}
