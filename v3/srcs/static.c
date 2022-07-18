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
