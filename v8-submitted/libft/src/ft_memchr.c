/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:20:38 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/28 13:25:32 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*str;

	index = 0;
	str = (char *)s;
	while (index < n)
	{
		if ((unsigned char)str[index] == (unsigned char)c)
			return ((char *)s + index);
		index++;
	}
	return (NULL);
}
