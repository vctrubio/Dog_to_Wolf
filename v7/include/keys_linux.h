#ifndef KEYS_LINUX_H
# define	KEYS_LINUX_H


//KEYCODE
# define K_W	119
# define K_A	97
# define K_S	115
# define K_D	100
# define K_Q	113
# define K_ESC	65307
# define K_R	114
# define K_L	115 //i
# define K_G	103


//COLORCODE RBG
# define MYRED 0x00FF0011
# define MYREDISH 0x00911100
# define MYGREEN 0x0000F900
# define MYBLUE 0x00F90000
# define MYWHITE 0x00F0F0F0

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
