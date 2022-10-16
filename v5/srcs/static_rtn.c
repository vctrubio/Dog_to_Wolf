#include "../include/header.h"

t_window	*rtn_window(void)
{
	t_window	*window;

	window = _window();
	window->mlx = mlx_init();
	window->window = NULL;
	return (window);
}

t_img	*rtn_img(int x, int y, t_window *w)
{
	t_img	*img;
	t_img	*img_bellow;

	img = _image();
	/*if (!x)
		x = SDWIDTH;
	if (!y)
		y = SDHEIGHT;*/

	img_bellow = _image_bellow();
	img_bellow->w = w;
	img->width = WWIDTH;
	img->height = WHEIGHT;
	img_bellow->img = mlx_new_image(img_bellow->w->mlx, img_bellow->width, img_bellow->height);
	img_bellow->addr = mlx_get_data_addr(img_bellow->img, &img_bellow->bbp, &img_bellow->line_length, &img_bellow->endian);



	img->w = w;
	img->width = x; //for mini_map view purposes
	img->height = y;
	printf("create img %d %d|\n", img->width, img->height);
	img->img = mlx_new_image(img->w->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->line_length, &img->endian);
	return (img);
}
