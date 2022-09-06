#include "../include/header.h"

int		data_checker(t_texture *texture)
{
	if (texture->north_texture == NULL || texture->south_texture == NULL
		|| texture->west_texture == NULL || texture->east_texture == NULL
		|| texture->floor == NULL || texture->cealing == NULL)
		return (0);
	else 
		return (1);
}

int 	map_data_lvl1(t_texture *texture, char *str)
{
	if (!ft_strncmp("NO", str, 2) || !ft_strncmp("SO", str, 2)
		|| !ft_strncmp("WE", str, 2) || !ft_strncmp("EA", str, 2)
		|| !ft_strncmp("F", str, 1) || !ft_strncmp("C", str, 1))
	{
		map_data_lvl2(texture, str);
		return (data_checker(texture));
	}
	else
	{
		printf("ERROR: Wrong argument\n");
		exit(1);
	}
}

int		map_data(char *str)
{
	int			i;
	int			ret;
	char		*str_cp;
	t_texture	*texture;

	i = 0;
	if (*str == '\0')
		return (0);
	texture = _texture();
	while (str[i] == ' ')
		i++;
	str_cp = ft_substr(str, i, ft_strlen(str));
	ret = map_data_lvl1(texture, str_cp);
	free(str_cp);
	return (ret);
}

int		map_begin(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str == ' ')
		*str++;
	if (!ft_isdigit(*str))
	{
		printf("ERROR: Wrong format\n");
		exit(1);
	}
}

int		map_divide(t_list *lst)
{
	int i;

	i = 0;
	while (!map_data((char *)lst->content))
	{
		lst = lst->next;
		i++;
	}
	lst = lst->next;
	while (!map_begin((char *)lst->content))
	{
		lst = lst->next;
		i++;
	}
	return (i);
}