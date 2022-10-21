#include "../include/header.h"

void    paint_window(void)
{
    t_game  *game;

    game = _game();
	t_img   *raycast;

	printf("BOOMBOOMBOOM\n");
	raycast = new_image(game->raycast->w, game->raycast->height,
			game->raycast->width);
	mlx_destroy_image(game->raycast->w->mlx, game->raycast->img);
	free(game->raycast);
	game->raycast = raycast;
	my_raycast(game);
	mlx_put_image_to_window(game->raycast->w->mlx,
		game->raycast->w->window, raycast->img, 0, 0);
}

