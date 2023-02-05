/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:48:19 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 17:51:45 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	destroy_image(void)
{
	t_window	*window;

	window = _window();
	printf("DESTROY\n");
	mlx_destroy_image(window->mlx, _image()->img);
	free(window->window);
}

void	free_function(void)
{
	int		i;
	t_map	*map;

	i = 0;
	map = _map();
	while (i < map->max_y)
	{
		free(map->map[i]);
		map->map[i++] = NULL;
	}
	free(map->map);
	exit(0);
}

void	ft_exit(char *msg)
{
	printf("ERROR: %s\n", msg);
	free_function();
}
