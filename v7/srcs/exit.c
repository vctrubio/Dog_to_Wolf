#include "../include/header.h"

//THIS file needs most cleaning. shit can go in ft_exit


void	destroyImage()
{
	t_window	*window;

	window = _window();
	printf("DESTROY\n");
	mlx_destroy_image(window->mlx, _image()->img);
	//free(window->window);
}

void	freeFunction() //bool destroy //THIS NEED TO GO INTO FT_EXIT
{
	int		i;
	t_map	*map;

	i = 0;
	map = _map();
	while (i < map->max_y)
	{
		printf("%s\n", map->map[i]);
		free(map->map[i]);
		map->map[i++] = NULL;

	}
	free(map->map);
	//destroyImage();
	printf("FREE FUNCTION\n");
	exit(0);
}

void	ft_exit(char *msg)
{
	printf("Error: ");
	printf("%s", msg);
	printf("\n");
	//freefunction CALL;
	exit(1);
};
