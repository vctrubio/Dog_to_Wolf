#include "../include/header.h"
//Boilerplate for cube3d initialization

int main()
{
	t_img		*t1; //test image 1
	// t_img		*t2; //test image 2
	t_window	*w;

	//INITS
	w = rtn_window();
	t1 = rtn_img(10, 10);
	// t2 = rtn_img(20, 20);
	w->window = mlx_new_window(w->mlx, WWIDTH, WHEIGHT, "MyCubeBS");

	//DO
	draw_img_square(t1, MYRED);
	draw_img_square(t2, MYREDISH);

	mlx_put_image_to_window(w->mlx, w->window, t1->img, 0, 0);
	// mlx_put_image_to_window(w->mlx, w->window, t2->img, 20, 20);



	key_listener(w->window);
	mlx_loop(w->mlx);
	printf("hello_end_world\n");
}

