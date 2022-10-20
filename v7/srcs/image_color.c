#include "../include/header.h"

int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (-1);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

int	get_opacity(int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}


int	shade(double distance, int color, t_game *game)
{
	double	factor;
	int		div;
	int		r;
	int		g;
	int		b;

	(void)div;
	if (_pov()->width < _pov()->height)
		div = _pov()->width;
	else
		div = _pov()->height;
	factor = fabs((distance / _pov()->width) - 1);
	if (factor > 1)
		factor = 1;
	r = get_r(color) * factor;
	g = get_g(color) * factor;
	b = get_b(color) * factor;
	if (r < 30)
		r = 30;
	if (g < 30)
		g = 30;
	if (b < 30)
		b = 30;
	return (gen_trgb(0, r, g, b));
}
