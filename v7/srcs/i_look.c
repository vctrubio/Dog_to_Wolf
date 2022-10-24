
#include "../include/header.h"

static void	look_up(t_pov *pov)
{
	if ( pov->center >= WWIDTH - TILE_SIZE)
		return ;
	else
		 pov->center += 5;
}

static void	look_down(t_pov *pov)
{
	if ( pov->center <= 10)
		return ;
	else
		 pov->center -= 5;
}

static void	rotate_right(t_pov *pov)
{
	 pov->angle = ( pov->angle - r_angle(MAGNITUDE_ANGLE));
	if ( pov->angle < 0)
		 pov->angle = r_angle(360) + r_angle(360);
	if ( pov->angle > r_angle(360))
		 pov->angle =  pov->angle - r_angle(360);
}

static void	rotate_left(t_pov *pov)
{
	 pov->angle = ( pov->angle + r_angle(MAGNITUDE_ANGLE));
	if ( pov->angle > r_angle(360))
		 pov->angle =  pov->angle - r_angle(360);
	if ( pov->angle < 0)
		 pov->angle = r_angle(360) + r_angle(360);
}

void	rotate(int key_code, t_pov *pov)
{
	if (key_code == K_L)
		rotate_left(pov);
	else if (key_code == K_R)
		rotate_right(pov);
}
