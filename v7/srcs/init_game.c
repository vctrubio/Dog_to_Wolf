#include "../include/header.h"

static void	choose_angle(t_game *game, char c)
{
	if (c == 'N')
		_pov()->angle = r_angle(90);
	else if (c == 'S')
		_pov()->angle = r_angle(270);
	else if (c == 'E')
		_pov()->angle = r_angle(0);
	else if (c == 'W')
		_pov()->angle = r_angle(180);
}


void    init_game(void)
{
    t_game  *game;
    int     i;
    int     j;
    t_map   *map = _map();
    t_pov   *pov;


    pov = _pov();
    i = -1;
    pov->width = WWIDTH * TILE_SIZE;
	pov->height = WHEIGHT* TILE_SIZE;
	pov->mag = MAGNITUDE;
	pov->dtp = (WWIDTH / 2) / ftan(r_angle(30));
	pov->center = WHEIGHT / 2;

    while (_map()->map[++i])
	{
		j = -1;
		while (_map()->map[i][++j])
		{
			if (ft_strchr("NSWE", _map()->map[i][j]))
			{
				choose_angle(game, _map()->map[i][j]);
				_pov()->p.x = (j * TILE_SIZE) + TILE_SIZE / 2;
				_pov()->p.y = (i * TILE_SIZE) + TILE_SIZE / 2;

            }
		}
	}
}
