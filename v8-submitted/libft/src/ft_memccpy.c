/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:20:06 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/28 13:25:28 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dest;
	unsigned int	index;

	str_src = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		str_dest[index] = str_src[index];
		if ((unsigned char)str_src[index] == (unsigned char)c)
			return (str_dest + index + 1);
		index++;
	}
	return (NULL);
}
