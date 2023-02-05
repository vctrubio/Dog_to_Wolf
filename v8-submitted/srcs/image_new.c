/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:01:39 by vrubio            #+#    #+#             */
/*   Updated: 2022/10/30 18:28:47 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_img	*new_image(t_window *win, int height, int width)
{
	t_img	*data;

	data = (t_img *)malloc(sizeof(t_img));
	if (!data)
		return (NULL);
	data->w = win;
	data->width = width;
	data->height = height;
	data->img = mlx_new_image(win->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &(data->bbp),
			&(data->line_length), &(data->endian));
	return (data);
}

void	init_img_game(t_game *game)
{
	game->raycast = new_image(game->w, WHEIGHT, WHEIGHT);
	init_walls(game, game->w);
	my_raycast(game);
	mlx_put_image_to_window(game->w->mlx,
		game->w->window, game->raycast->img, 0, 0);
}

int	convert_color(char *str)
{
	int		index;
	char	**color;
	int		color_n[3];

	index = 0;
	color = ft_split(str, ',');
	while (color[index])
	{
		if (3 < ft_strlen(color[index++]))
			ft_exit("Wrong color format");
	}
	color_n[0] = get_b(ft_atoi(color[0]));
	color_n[1] = get_b(ft_atoi(color[1]));
	color_n[2] = get_b(ft_atoi(color[2]));
	index = 0;
	while (color[index])
		free(color[index++]);
	free(color);
	return (gen_trgb(100, color_n[0], color_n[1], color_n[2]));
}
