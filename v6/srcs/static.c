#include "../include/header.h"

t_game	*_game(void)
{
	static t_game game;

	return (&game);
}

t_window	*_window(void)
{
	static t_window	w;

	return (&w);
}

t_key	*_key(void)
{
	static t_key	k;

	return(&k);
}

t_map	*_map(void)
{
	static t_map	m;

	return (&m);
}

t_ray		*_ray(void)
{
	static	t_ray	r;

	return (&r);
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
