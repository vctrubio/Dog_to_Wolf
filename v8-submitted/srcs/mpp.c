/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:51:44 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 15:52:57 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	mpp(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > img->width)
		return ;
	if (y > img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}
