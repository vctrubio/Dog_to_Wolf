/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:03 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/30 18:28:22 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	path_verify02(char *str, int index)
{
	int	counter;

	counter = 0;
	while (str[++index])
	{
		if (str[index] != ',' && (str[index] < '0' || str[index] > '9'))
		{
			ft_exit("Wrong color format");
		}
		if (str[index] == ',')
			counter++;
		if (counter > 2)
			ft_exit("Wrong color format");
	}
}

void	path_verfy01(char *str)
{
	int	index;

	if (!ft_strncmp("NO", str, 2) || !ft_strncmp("SO", str, 2)
		|| !ft_strncmp("WE", str, 2) || !ft_strncmp("EA", str, 2))
	{
		index = 2;
		while (str[index] == ' ')
			index++;
		if (str[index] != '.')
			ft_exit("Wrong texture format");
	}
	if (!ft_strncmp("F", str, 1) || !ft_strncmp("C", str, 1))
	{
		index = 1;
		while (str[index] == ' ')
			index++;
		if (str[index] < '0' || str[index] > '9')
			ft_exit("Wrong color format");
		path_verify02(str, index);
	}
}

void	path_verify(char *str)
{
	if (!ft_strncmp("NO", str, 2) || !ft_strncmp("SO", str, 2)
		|| !ft_strncmp("WE", str, 2) || !ft_strncmp("EA", str, 2))
	{
		if (str[2] != ' ')
			ft_exit("Wrong texture format");
	}
	if (!ft_strncmp("F", str, 1) || !ft_strncmp("C", str, 1))
	{
		if (str[1] != ' ')
			ft_exit("Wrong color format");
	}
	path_verfy01(str);
}

void	texture_path(t_texture *texture, char *str, int data)
{
	path_verify(str);
	if (data == 1)
		texture->north_texture
			= ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 2)
		texture->south_texture
			= ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 3)
		texture->west_texture
			= ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 4)
		texture->east_texture
			= ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 5)
		texture->floor
			= ft_substr(str, my_strnstr(str, 1), ft_strlen(str));
	else if (data == 6)
		texture->cealing
			= ft_substr(str, my_strnstr(str, 1), ft_strlen(str));
}

void	map_data_lvl2(t_texture *texture, char *str)
{
	if (!ft_strncmp("NO", str, 2) && texture->north_texture == NULL)
		texture_path(texture, str, 1);
	else if (!ft_strncmp("SO", str, 2) && texture->south_texture == NULL)
		texture_path(texture, str, 2);
	else if (!ft_strncmp("WE", str, 2) && texture->west_texture == NULL)
		texture_path(texture, str, 3);
	else if (!ft_strncmp("EA", str, 2) && texture->east_texture == NULL)
		texture_path(texture, str, 4);
	else if (!ft_strncmp("F", str, 1) && texture->floor == NULL)
		texture_path(texture, str, 5);
	else if (!ft_strncmp("C", str, 1) && texture->cealing == NULL)
		texture_path(texture, str, 6);
	else
	{
		printf("ERROR: Duplicate texture\n");
		exit(1);
	}
}
