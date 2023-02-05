/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:31 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:02:07 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	paint_window(void)
{
	t_game	*game;
	t_img	*raycast;

	game = _game();
	raycast = new_image(game->raycast->w,
			game->raycast->height, game->raycast->width);
	mlx_destroy_image(game->raycast->w->mlx, game->raycast->img);
	free(game->raycast);
	game->raycast = raycast;
	my_raycast(game);
	mlx_put_image_to_window(game->raycast->w->mlx,
		game->raycast->w->window, raycast->img, 0, 0);
}
