#include "../include/header.h"

t_window	*rtn_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->window = NULL;
	return (window);
}



t_img	*rtn_img(int x, int y)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->w = rtn_window();
	img->width = x;
	img->height = y;
	img->img = mlx_new_image(img->w->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->line_length, &img->endian);
	return (img);
}
