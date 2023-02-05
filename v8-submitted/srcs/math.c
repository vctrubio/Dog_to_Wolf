/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:00:27 by vrubio            #+#    #+#             */
/*   Updated: 2022/10/27 18:12:00 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	r_angle(int angle)
{
	if (angle == 0)
		return (0);
	return ((angle * WWIDTH) / 60);
}

double	fcos(int angle)
{
	static double	fcos[360 * WWIDTH / 60];
	int				i;

	if (angle < r_angle(0) || angle >= r_angle(360))
		return (0.0);
	if (fcos[r_angle(0)] > 1.0)
		return (fcos[angle]);
	i = 0;
	while (i < r_angle(360))
	{
		fcos[i] = cos(i * PI / r_angle(180)) + 0.00001;
		i++;
	}
	return (fcos[angle]);
}

double	fsin(int angle)
{
	static double	fsin[360 * WWIDTH / 60];
	int				i;

	if (angle < r_angle(0) || angle >= r_angle(360))
		return (0.0);
	if (fsin[r_angle(90)] > 1.0)
		return (fsin[angle]);
	i = 0;
	while (i < r_angle(360))
	{
		fsin[i] = sin(i * PI / r_angle(180)) + 0.00001;
		i++;
	}
	return (fsin[angle]);
}

double	ftan(int angle)
{
	static double	ftan[360 * WWIDTH / 60];
	int				i;

	if (angle < r_angle(0) || angle >= r_angle(360))
		return (0.0);
	if (ftan[r_angle(45)] > 1.0)
		return (ftan[angle]);
	i = 0;
	while (i < r_angle(360))
	{
		ftan[i] = tan(i * PI / r_angle(180)) + 0.00001;
		i++;
	}
	return (ftan[angle]);
}

double	norm(int xx, int yy)
{
	return (sqrt(pow((_pov()->p.x / MAP_SCALE) - (xx), 2)
			+ pow((_pov()->p.y / MAP_SCALE) - (yy), 2))
		<= sqrt(tile_size()));
}
