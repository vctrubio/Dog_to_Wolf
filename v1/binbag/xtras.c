#include "./include/header.h"

#define HEIGHT 800
#define WIDTH 400

/* NOTES
When you increment the pointer by one by one, you’re moving forward one byte in memory, so the final offset should be multiplied by 4.
(y * line_bytes) + (x * 4)
*/

<<<<<<< HEAD:xtras.c
void	init_mlx_window(t_window **w)
{
	(*w) = malloc(sizeof(t_window));
	(*w)->mlx_ptr = mlx_init();
	(*w)->height = HEIGHT; 
	(*w)->weight = WIDTH;
	(*w)->mlx_window = mlx_new_window((*w)->mlx_ptr, (*w)->weight, (*w)->height, "My notverygood Cube");
}

void	init_img_data(t_img **img, t_window **w)
{
	(*img) = malloc(sizeof(t_img));
	(*w)->img = *img;

	// void	*mlx_new_image(void *mlx_ptr,int width,int height);
	(*img)->img = mlx_new_image((*w)->mlx_ptr, WIDTH, HEIGHT);
	(*w)->img->img = mlx_get_data_addr((*w)->img->img, &(*w)->img->bits_per_pixel, &(*w)->img->line_length, &(*w)->img->endian);

}


// int offset = (y * img.line_length + x * (img.bits_per_pixel / 8));
//  index = line_len * y + x * (bpp / 8);
void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char *buffer;

	// buffer = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	// *(unsigned int*)buffer = color;

	// *(int *)(img->addr + ((x + y * WIDTH) * img->bits_per_pixel)) = color;
}

// }

// int main2()
// {
// 	init_prg();
// 	init_window(200, 400, "Title");

// 	mlx_hook((ft_window())->mlx_window, 2, 1, key_down, NULL); 
// 	mlx_hook((ft_window())->mlx_window, 3, 1, key_up, NULL);

// <<<<<<< HEAD:xtras.c
// 	int i; int j;
// 	i = 0; j = 5;
// 	while (i <= 10)
// 	{
// 		img_pixel_put(img, i, j, 0x000000);
// 		i++;
// 	}

// 	mlx_put_image_to_window(w->mlx_ptr, w->mlx_window, w->img->img, 0, 0);

// 	mlx_key_hook(w->mlx_window, ft_key_hook, w);
// 	mlx_loop(w->mlx_ptr);

// 	return (43);
// }

	// mlx_put_image_to_window(w->mlx_ptr, w->mlx_window, w->img->img, 0, 0);
	// printf("info: %dbbp %dline_length %dendian\n", img->bits_per_pixel, img->line_length, img->endian);
	// int i; int j;
	// i = 0; j = 5;
	// while (i <= 10)
	// {
	// 	img_pixel_put(img, i, j, 0xFF0000);
	// 	i++;
	// }


/* GOALS
1. draw shapes, and move with different keystrokes
2. draw a circle 
3. export a "".ber" map
4. make a player- that can move- wih xmp

*/
