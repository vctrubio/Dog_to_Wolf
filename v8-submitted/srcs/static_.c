/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:34:03 by jmendes           #+#    #+#             */
/*   Updated: 2022/10/30 17:54:43 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_texture	*_texture(void)
{
	static t_texture	t;

	return (&t);
}

t_img	*_image(void)
{
	static t_img	img;

	return (&img);
}

t_pov	*_pov(void)
{
	static t_pov	pov;

	return (&pov);
}
