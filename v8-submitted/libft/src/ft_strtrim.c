/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:18:59 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/28 13:26:46 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_set(char c, const char *set)
{
	unsigned int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	unsigned int	ini;
	unsigned int	end;

	ini = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (is_set(s1[ini], set))
		ini++;
	if (ini == end)
		return (ft_strdup(""));
	while (is_set(s1[end - 1], set))
		end--;
	trim = ft_substr(s1, ini, (end - ini));
	return (trim);
}
