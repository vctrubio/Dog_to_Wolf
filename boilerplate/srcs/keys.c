#include "../include/header.h"

static int	ft_key_(int keycode)
{
	if (keycode == K_Q)
	{
		printf("Key K_Q\n");
		exit(1);
	}
	if (keycode == K_D)
	{
		printf("Key02\n");
	}
	return (0);
}


void	key_listener(void *w)
{
	printf("init_key_listnener\n");
	mlx_key_hook(w, ft_key_, w);
}
