#ifndef HEADER_H
# define	HEADER_H

# include "../lmlx/mlx.h"
# include "keys.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

# define WHEIGHT 600 //WINDOW_HEIGHT
# define WWIDTH 900

# define SDHEIGHT 2 //STANDARD_HEIGHT
# define SDWIDTH 2
# define BUFFER_SIZE 1
# define UNIT 64  //MAP_UNIT

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_window
{
	void	*mlx;
	void	*window;
}				t_window;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_map
{
	char	**map;
	int		max_y;
	int		max_x;
}				t_map;

typedef struct	s_img
{

}				t_img;



typedef struct	s_game
{
	t_window	*w;
	t_map		*map;
	double		pos_x; //Position of payer
	double		pos_y;
	double		d_x;   //distance to x intersection
	double		d_y;
	double		plane_x; //distance of plane (player view of ray)
	double		plane_y;
	double		moveSpeed;
	double		rotSpeed;
}				t_game;

//static
t_game		*_game(void);
t_window	*_window(void);
//inits
void	init_play_pov(void);
void	init_window(void);








//map
void	print_map(t_map *map);
t_map	*rtn_map(void);
//parser

//keys
int		ft_key_hook(int keycode, t_window *w);
void	key_listener(void *w);


//calloc
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
//utilList
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
//utilStr
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//utilGNL
int	get_next_line(int fd, char **line);

#endif