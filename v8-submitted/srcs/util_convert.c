/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:36:54 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 17:53:41 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	unit_nb(int x)
{
	return (x * M_UNIT);
}

int	my_strnstr(char *str, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		while (str[i])
		{
			if (str[i] == '.')
				return (i);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				return (i);
			i++;
		}
	}
	return (0);
}
