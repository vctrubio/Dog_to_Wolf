#include "../include/header.h"

t_point	horizontal_step(int a)
{
	static t_point	h_step[WWIDTH * 6];
	int				i;

	if (h_step[0].x > 0 || h_step[0].y > 0)
		return (h_step[a]);
	i = 0;
	while (i < (int)r_angle(360))
	{
		if (i < (int)r_angle(180)) {
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE * -1);
			h_step[i].y = -64;
		}
		else
		{
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE);
			h_step[i].y = 64;
		}
		if (i > r_angle(90) && i < r_angle(270))
			h_step[i].x *= -1;
		i++;
	}
	return (h_step[a]);
}

t_point	vertical_step(int a)
{
	static t_point	v_step[360 * WWIDTH / 60];
	int				i;

	if (v_step[0].x > 0 || v_step[0].y > 0)
		return (v_step[a]);
	i = 0;
	while (i < r_angle(360))
	{
		if (i < r_angle(180))
			v_step[i] = p(TILE_SIZE, fabs(TILE_SIZE * ftan(i)) * -1);
		else
			v_step[i] = p(TILE_SIZE, fabs(TILE_SIZE * ftan(i)));
		if (i > r_angle(90) && i < r_angle(270))
			v_step[i].x *= -1;
		i++;
	}
	return (v_step[a]);
}
