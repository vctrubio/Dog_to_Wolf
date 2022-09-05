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

t_raycast	*_raycast(void)
{
	static	t_raycast	r;

	return (&r);
}

t_texture	*_texture(void)
{
	static	t_texture	t;
	if (!t.texture_count)
		t.texture_count = 0;

	return (&t);
}