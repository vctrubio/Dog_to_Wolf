/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio < vrubio@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:00:41 by vrubio            #+#    #+#             */
/*   Updated: 2022/10/27 18:21:29 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	gameloop(t_pov *pov)
{
	static int	fps = 0;

	if (fps++ == 6)
	{
		if (pov->w_down)
			move(K_W, pov);
		else if (pov->s_down)
			move(K_S, pov);
		if (pov->a_down)
			move(K_A, pov);
		else if (pov->d_down)
			move(K_D, pov);
		else if (pov->l_down)
			rotate(K_L, pov);
		else if (pov->r_down)
			rotate(K_R, pov);
		if (pov->w_down || pov->s_down || pov->d_down
			|| pov->a_down || pov->l_down || pov->r_down)
			paint_window();
		fps = 0;
	}
	return (0);
}

int	destroy(void)
{
	free_function();
	exit(0);
}

int	main(int ac, char **argv)
{
	t_game	*game;

	if (ac != 2)
		ft_exit("Wrong arguments");
	game = _game();
	parse_map(argv[1]);
	game->w = rtn_window();
	game->w->width = WWIDTH;
	game->w->height = WHEIGHT;
	game->w->window = mlx_new_window(game->w->mlx,
			WWIDTH, WHEIGHT, "Dog_to_Wolf");
	init_game();
	init_img_game(game);
	mlx_hook(game->w->window, 3, 1L << 1, handle_key_up, _pov());
	mlx_hook(game->w->window, 2, 1L << 0, handle_key_down, _pov());
	mlx_hook(game->w->window, 17, 1L << 17, destroy, NULL);
	mlx_loop_hook(game->w->mlx, &gameloop, _pov());
	mlx_loop(game->w->mlx);
	free_function();
	destroy_image();
	return (0);
}
