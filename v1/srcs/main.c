#include "../include/header.h"
/* V1
create a simple img
*/

int main()
{
	t_img		*t1; //test image 1
	t_window	*w;

	//INITS
	w = rtn_window();
	t1 = rtn_img(10, 10); //return an image- and can that can be manipulated

	//PROGRAM
	w->window = mlx_new_window(w->mlx, WWIDTH, WHEIGHT, "Dog_to_Wolf");
	draw_img_square(t1, MYRED);
	mlx_put_image_to_window(w->mlx, w->window, t1->img, 42, 42);

	//MLX LOOP
	key_listener(w->window);
	mlx_loop(w->mlx);
	printf("Safe EXIT");
	return (0);
}

