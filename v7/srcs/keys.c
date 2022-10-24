#include "../include/header.h"

static void	keys_update(int key_code, void *_pov, int press)
{
	t_pov	*pov;

	printf("KEYCODE %d\n", key_code); //this will go too.
	pov = _pov;
	if (key_code == K_ESC)
		freeFunction();
	if ((key_code == K_W) && pov->n_down != press)
		pov->n_down = press;
	else if ((key_code == K_S) && pov->s_down != press)
		pov->s_down = press;
	else if ((key_code == K_D) && pov->e_down != press)
		pov->e_down = press;
	else if ((key_code == K_A ) && pov->w_down != press)
		pov->w_down = press;
}

int     handle_key_up(int key_code, void *pov)
{
        keys_update(key_code, pov, 0);
        return (0);
}

int     handle_key_down(int key_code, void *pov)
{
        keys_update(key_code, pov, 1);
        return (0);
}
