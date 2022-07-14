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

# define SDHEIGHT 5 //STANDARD_HEIGHT
# define SDWIDTH 5
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

typedef struct	s_img
{
	t_window	*w;
	char		*addr;
	void		*img;
	int			line_length;
	int			endian;
	int			bbp;
	int			height;
	int			width;
	double		pos_x;
	double		pos_y;
}				t_img;

typedef struct	s_game
{
	t_window	*w; //window/mlx
}				t_game;

//static
t_game		*_game(void);
t_window	*_window(void);
//staticRTN
t_window	*rtn_window(void);
t_game		*rtn_game(void);
t_img		*rtn_img(int x, int y);

//draw
void		draw_img_square(t_img *img, int color);
//pixelManipulation
void		mpp(t_img *img, int x, int y, int color); //my_pixel_put

//keys
int			ft_key_hook(int keycode, t_window *w);
void		key_listener(void *w);


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
int		get_next_line(int fd, char **line);

#endif