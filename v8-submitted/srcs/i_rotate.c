/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:08:21 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/26 17:12:07 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	rotate_right(t_pov *pov)
{
	pov->angle = (pov->angle - r_angle(MAGNITUDE_ANGLE));
	if (pov->angle < 0)
		pov->angle = r_angle(360) + r_angle(360);
	if (pov->angle > r_angle(360))
		pov->angle = pov->angle - r_angle(360);
}

static void	rotate_left(t_pov *pov)
{
	pov->angle = (pov->angle + r_angle(MAGNITUDE_ANGLE));
	if (pov->angle > r_angle(360))
		pov->angle = pov->angle - r_angle(360);
	if (pov->angle < 0)
		pov->angle = r_angle(360) + r_angle(360);
}

void	rotate(int key_code, t_pov *pov)
{
	if (key_code == K_L)
		rotate_left(pov);
	else if (key_code == K_R)
		rotate_right(pov);
}
