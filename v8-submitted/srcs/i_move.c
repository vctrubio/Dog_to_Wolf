/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:08:08 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:02:59 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	move_right(t_pov *pov)
{
	t_point	p;

	p.x = pov->p.x;
	p.y = pov->p.y;
	p = add_vec(p, vec(pov->angle - r_angle(90), pov->mag));
	if (p.x > pov->width || p.x < 0 || p.y > pov->height || p.y < 0)
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

	p.x = pov->p.x;
	p.y = pov->p.y;
	p = add_vec(p, vec(pov->angle + r_angle(90), pov->mag));
	if (p.x > pov->width || p.x < 0 || p.y > pov->height || p.y < 0)
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

	p.x = pov->p.x;
	p.y = pov->p.y;
	p = add_vec(p, vec(pov->angle, pov->mag));
	if (p.x > pov->width || p.x < 0 || p.y > pov->height || p.y < 0)
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

	p.x = pov->p.x;
	p.y = pov->p.y;
	p = add_vec(p, vec(pov->angle, pov->mag * -1));
	if (p.x > pov->width || p.x < 0 || p.y > pov->height || p.y < 0)
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
		pov->w_down = 1;
	}
	else if (key_code == K_S)
	{
		move_down(pov);
		pov->s_down = 1;
	}
	else if (key_code == K_D)
	{
		move_right(pov);
		pov->d_down = 1;
	}
	else if (key_code == K_A)
	{
		move_left(pov);
		pov->a_down = 1;
	}
}
