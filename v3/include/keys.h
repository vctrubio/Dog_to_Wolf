#ifndef KEYS_H
# define	KEYS_H


//KEYCODE
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_Q 12
# define K_ESC 53
# define K_R 15
# define K_G 5


//COLORCODE RBG
# define MYRED 0x00FF0011
# define MYREDISH 0x00911100
# define MYGREEN 0x0000F900

typedef struct	s_key
{
	int	W;
	int	S;
	int	A;
	int	D;
	int	Q;
	int	E;
	int	ESC;
}		t_key;

#endif
