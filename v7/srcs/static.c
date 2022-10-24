#include "../include/header.h"

t_window	*_window(void)
{
	static t_window	w;

	return (&w);
}

t_map	*_map(void)
{
	static t_map	m;

	return (&m);
}


t_texture	*_texture(void)
{
	static	t_texture	t;
	
	return (&t);
}

t_img	*_image()
{
	static	t_img	img;

	return (&img);
}

t_pov	*_pov()
{
	static t_pov	pov;

	return (&pov);
}