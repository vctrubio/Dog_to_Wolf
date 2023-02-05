/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:58:51 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:14:57 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	draw_line01(t_ray ray, t_game *game, t_img *tex, int norm[2])
{
	int			i;
	t_pov		*pov;
	t_texture	*colors;

	colors = _texture();
	pov = _pov();
	i = -1;
	while (++i < game->raycast->height)
	{		
		if (i >= pov->center - (ray.height / 2)
			&& i <= pov->center + (ray.height / 2))
		{
			ray.color = texture_pixel_color(p(norm[1],
						(double)i), ray, tex);
			ray.color = shade(ray.dist_wall, ray.color);
			mpp(game->raycast, norm[0], i, ray.color);
		}
		else if (i < pov->center)
			mpp(game->raycast, norm[0], i, colors->cealing_value);
		else
			mpp(game->raycast, norm[0], i, colors->floor_value);
	}
}

void	draw_line(t_game *game, t_ray ray, int col)
{
	t_img		*tex;
	t_texture	*colors;
	int			norm[2];
	int			x_texture_position;

	colors = _texture();
	tex = correct_texture(game, ray.color);
	colors->floor_value = convert_color(colors->floor);
	colors->cealing_value = convert_color(colors->cealing);
	if (ray.color == 1 || ray.color == 2)
		x_texture_position = (int)(floor(ray.end.x + 1)) % TILE_SIZE;
	else
		x_texture_position = (int)(floor(ray.end.y + 1)) % TILE_SIZE;
	norm[0] = col;
	norm[1] = x_texture_position;
	draw_line01(ray, game, tex, norm);
}
