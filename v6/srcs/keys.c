#include "../include/header.h"

int	test_key_code(int keycode)
{
	if (keycode == K_ESC)
		freeFunction();
	printf("hello from test_key_code %d\n", keycode);
	if (keycode == K_D)
		move_player(0, 1);
	if (keycode == K_A)
		move_player(0, -1);
	if (keycode == K_S)
		move_player(1, 0);
	if (keycode == K_W)
		move_player(-1, 0);
	print_map();
	return (keycode);
}
