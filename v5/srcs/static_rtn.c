#include "../include/header.h"

t_window	*rtn_window(void)
{
	t_window	*window;

	window = _window();
	//window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->window = NULL;
	return (window);
}

t_img	*rtn_img(int x, int y, t_window *w)
{
	t_img	*img;

	img = _image();
	//img = malloc(sizeof(t_img));
	img->check = 8;
	if (!x)
		x = SDWIDTH;
	if (!y)
		y = SDHEIGHT;
	img->w = w;
	img->width = x * M_UNIT; //for mini_map view purposes
	img->height = y * M_UNIT;
	printf("create img %d %d|\n", img->width, img->height);
	img->img = mlx_new_image(img->w->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->line_length, &img->endian);
	return (img);
}
