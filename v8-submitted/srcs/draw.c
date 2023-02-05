/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:41:49 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 17:42:31 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	fill_img_square(t_img *img, int cord_x, int cord_y, int color)
{
	int	x;
	int	y;
	int	i;

	i = cord_x;
	y = -1;
	while (++y < M_UNIT)
	{
		x = -1;
		cord_x = i;
		while (++x < M_UNIT)
		{
			printf("COLOR --> %d\n", color);
			mpp(img, cord_x++, cord_y, color);
		}
		cord_y++;
	}
}

void	draw_img_square(t_img *img, int color)
{
	int	x;
	int	y;

	y = -1;
	printf("height draw: %d & %d\n\n", img->height, img->width);
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			mpp(img, x, y, color);
	}
}

void	draw(void)
{
	t_game	*game;

	game = _game();
	mlx_put_image_to_window(game->w->mlx,
		game->w->window, game->raycast->img, 0, 0);
}

void	draw_gridline(t_img *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < img->height)
	{
		if (y % M_UNIT == 0)
		{
			x = -1;
			while (++x < img->width)
				mpp(img, x, y, MYWHITE);
		}
		x = -1;
		while (++x < img->width)
			if (x % M_UNIT == 0)
				mpp(img, x, y, MYWHITE);
	}	
}

void	draw_raycast(void)
{
	t_game	*game;

	game = _game();
	mlx_put_image_to_window(game->w->mlx, game->w->window,
		game->raycast->img, 0, 0);
}
