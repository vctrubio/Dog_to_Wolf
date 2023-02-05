/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_rtn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:50:49 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 15:51:29 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_window	*rtn_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->window = NULL;
	return (window);
}

t_img	*rtn_img(int x, int y)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->w = rtn_window();
	img->width = x;
	img->height = y;
	img->img = mlx_new_image(img->w->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bbp,
			&img->line_length, &img->endian);
	return (img);
}
