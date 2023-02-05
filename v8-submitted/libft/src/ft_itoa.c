/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:31 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/28 13:25:24 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	counter(int n)
{
	int	index;

	index = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		index++;
	}
	if (n < 0)
		index++;
	return (index);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nr;
	int		index;

	nr = n;
	index = counter(n);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[index] = '\0';
	if (n == 0)
		str[0] = '0';
	if (nr < 0)
	{
		str[0] = '-';
		nr = nr * -1;
	}
	while (nr)
	{
		str[--index] = nr % 10 + '0';
		nr = nr / 10;
	}
	return (str);
}
