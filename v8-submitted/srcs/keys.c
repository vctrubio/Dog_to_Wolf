/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:41:57 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 17:52:48 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	keys_update(int key_code, void *_pov, int press)
{
	t_pov	*pov;

	pov = _pov;
	if (key_code == K_ESC)
		free_function();
	if ((key_code == K_W) && pov->w_down != press)
		pov->w_down = press;
	else if ((key_code == K_S) && pov->s_down != press)
		pov->s_down = press;
	else if ((key_code == K_D) && pov->d_down != press)
		pov->d_down = press;
	else if ((key_code == K_A) && pov->a_down != press)
		pov->a_down = press;
	else if ((key_code == K_L) && pov->l_down != press)
		pov->l_down = press;
	else if ((key_code == K_R) && pov->r_down != press)
		pov->r_down = press;
}

int	handle_key_up(int key_code, void *pov)
{
	keys_update(key_code, pov, 0);
	return (0);
}

int	handle_key_down(int key_code, void *pov)
{
	keys_update(key_code, pov, 1);
	return (0);
}

int	test_key_code(int keycode)
{
	if (keycode == K_D)
		move_player(0, 1);
	if (keycode == K_A)
		move_player(0, -1);
	if (keycode == K_S)
		move_player(1, 0);
	if (keycode == K_W)
		move_player(-1, 0);
	return (keycode);
}

void	key_listener(void)
{
	t_game	*g;

	g = _game();
	mlx_hook(g->w->window, 2, 1L << 0, test_key_code, &g);
}
