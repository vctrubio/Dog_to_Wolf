/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:37:43 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/27 18:14:39 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	shade(double distance, int color)
{
	double	factor;
	int		div;
	int		r;
	int		g;
	int		b;

	(void)div;
	if (_pov()->width < _pov()->height)
		div = _pov()->width;
	else
		div = _pov()->height;
	factor = fabs((distance / _pov()->width) - 1);
	if (factor > 1)
		factor = 1;
	r = get_r(color) * factor;
	g = get_g(color) * factor;
	b = get_b(color) * factor;
	if (r < 30)
		r = 30;
	if (g < 30)
		g = 30;
	if (b < 30)
		b = 30;
	return (gen_trgb(0, r, g, b));
}
