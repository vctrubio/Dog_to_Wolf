#include "../include/header.h"

static void	move_right(t_pov *pov)
{
	t_point	p;

	p.x =  pov->p.x;
	p.y =  pov->p.y;	
    p = add_vec(p, vec( pov->angle - r_angle(90),  pov->mag));
	if (p.x >  pov->width || p.x < 0 || p.y >  pov->height || p.y < 0)
		return ;
	if (_map()->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		 pov->p.y = round(p.y);
		 pov->p.x = round(p.x);
	}
}

static void	move_left(t_pov *pov)
{
	t_point	p;

	p.x =  pov->p.x;
	p.y =  pov->p.y;
	p = add_vec(p, vec( pov->angle + r_angle(90),  pov->mag));
	if (p.x >  pov->width || p.x < 0 || p.y >  pov->height || p.y < 0)
		return ;
	if (_map()->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		 pov->p.y = round(p.y);
		 pov->p.x = round(p.x);
	}
}

static void	move_up(t_pov *pov)
{
	t_point	p;

	p.x =  pov->p.x;
	p.y =  pov->p.y;
	p = add_vec(p, vec( pov->angle,  pov->mag));
	if (p.x >  pov->width || p.x < 0 || p.y >  pov->height || p.y < 0)
		return ;
	if (_map()->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		 pov->p.y = round(p.y);
		 pov->p.x = round(p.x);
	}
}

static void	move_down(t_pov *pov)
{
	t_point	p;

	p.x =  pov->p.x;
	p.y =  pov->p.y;
	p = add_vec(p, vec( pov->angle,  pov->mag * -1));
	if (p.x >  pov->width || p.x < 0 || p.y >  pov->height || p.y < 0)
		return ;
	if (_map()->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		 pov->p.y = round(p.y);
		 pov->p.x = round(p.x);
	}
}

void	move(int key_code, t_pov *pov)
{
	if (key_code == K_W)
	{
		move_up(pov);
		 pov->n_down = 1;
	}
	else if (key_code == K_S)
	{
		move_down(pov);
		 pov->s_down = 1;
	}
	else if (key_code == K_D)
	{
		move_right(pov);
		 pov->e_down = 1;
	}
	else if (key_code == K_A)
	{
		move_left(pov);
		 pov->w_down = 1;
	}
}

static void	look_up(t_pov *pov)
{
	if ( pov->center >= WWIDTH - TILE_SIZE)
		return ;
	else
		 pov->center += 5;
}

static void	look_down(t_pov *pov)
{
	if ( pov->center <= 10)
		return ;
	else
		 pov->center -= 5;
}

static void	rotate_right(t_pov *pov)
{
	 pov->angle = ( pov->angle - r_angle(MAGNITUDE_ANGLE));
	if ( pov->angle < 0)
		 pov->angle = r_angle(360) + r_angle(360);
	if ( pov->angle > r_angle(360))
		 pov->angle =  pov->angle - r_angle(360);
}

static void	rotate_left(t_pov *pov)
{
	 pov->angle = ( pov->angle + r_angle(MAGNITUDE_ANGLE));
	if ( pov->angle > r_angle(360))
		 pov->angle =  pov->angle - r_angle(360);
	if ( pov->angle < 0)
		 pov->angle = r_angle(360) + r_angle(360);
}

void	rotate(int key_code, t_pov *pov)
{
	if (key_code == K_L)
		rotate_left(pov);
	else if (key_code == K_R)
		rotate_right(pov);
}
