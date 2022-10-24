#include "../include/header.h"

int isBorder(char **map, int y, int x)
{
    int     len = ft_strlen(map[y]);
    int     height = _map()->max_y - 1;
    //NOTE- 1 and should test for empty lines after that

    if ((y == 0  || y == height) && map[y][x] == '0')
        return (1);

    if (y > 0 && !map[y - 1][x])
        return (1);
    if (y < height && !map[y + 1][x]) //Notechecker
        return (1);
    if (x > 0 && !map[y][x - 1])
        return (1);
    if (x < len && !map[y][x + 1])
        return (1);
    return (0);
}


int checkCord(char **map, int y, int x)
{
    if (map[y][x] == '0')
	    return (1);
    return (0);
}


int    pParse(char **map)
{
    int i;
    int j;

    i = -1;
    j = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (checkCord(map, i, j))
            {
				if (isBorder(map, i, j))
                {
					printf("CORD: %d, %d = SHOULD BE BORDER;\n", i, j);
                    ft_exit("check map");
                }
            }
			j++;
		}
	}
    return (1);
}
