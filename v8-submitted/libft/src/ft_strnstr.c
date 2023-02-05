/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:52:09 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/28 13:26:40 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	i_l;

	index = 0;
	i_l = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (big == little)
		return ((char *)big);
	while (big[index] && index < len)
	{
		i_l = 0;
		while (big[index + i_l] == little[i_l] && (index + i_l) < len)
		{
			if (little[i_l + 1] == '\0')
				return ((char *)big + index);
			i_l++;
		}
		index++;
	}
	return (NULL);
}
