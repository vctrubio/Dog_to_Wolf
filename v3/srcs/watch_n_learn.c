#include "../include/header.h"



void	wnl_1(void)
{
	t_img		*i1;
	t_img		*i2;

	i1 = rtn_img2(1, 1, _game()->w);
	i2 = rtn_img2(1, 1, _game()->w);
	draw_img_square(i1, MYGREEN);
	draw_img_square(i2, MYRED);
	mlx_put_image_to_window(_game()->w->mlx, _game()->w->window, i1->img, 0, 0);
	mlx_put_image_to_window(_game()->w->mlx, _game()->w->window, i2->img, 0, 65);
	mlx_put_image_to_window(_game()->w->mlx, _game()->w->window, i2->img, 65, 65);
	mlx_put_image_to_window(_game()->w->mlx, _game()->w->window, i1->img, 65, 0);

}