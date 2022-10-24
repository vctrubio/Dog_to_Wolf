#include "../include/header.h"

int		convert_color(char *str)
{
	char	**color;
	int		c_number[3];

	color = ft_split(str, ',');
	c_number[0] = get_r(ft_atoi(color[0]));
	c_number[1] = get_g(ft_atoi(color[1]));
	c_number[2] = get_b(ft_atoi(color[2]));
	free(color);
	return (gen_trgb(255, c_number[0], c_number[1], c_number[2]));
}

void	texture_path(t_texture *texture, char *str, int data)
{
	if (data == 1)
		texture->north_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 2)
		texture->south_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 3)
		texture->west_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 4)
		texture->east_texture = ft_substr(str, my_strnstr(str, 0), ft_strlen(str));
	else if (data == 5)
		texture->floor = ft_substr(str, my_strnstr(str, 1), ft_strlen(str));
	else if (data == 6)
		texture->cealing = ft_substr(str, my_strnstr(str, 1), ft_strlen(str));
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
		ft_exit("Duplicate texture");
}