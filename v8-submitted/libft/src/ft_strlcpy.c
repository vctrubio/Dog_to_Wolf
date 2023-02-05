/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:23:28 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/28 13:26:28 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	index;

	index = 0;
	if (!dest || !src)
		return (0);
	if (size == 0)
	{
		index = ft_strlen(src);
		return (index);
	}
	while (src[index] && index < (size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	if (index < size)
		dest[index] = '\0';
	while (src[index])
		index++;
	return (index);
}
