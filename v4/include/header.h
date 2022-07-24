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

# define SDHEIGHT 42 //STANDARD_HEIGHT
# define SDWIDTH 42
# define BUFFER_SIZE 1
# define UNIT 10  //MAP_UNIT- change it if you want, will resize the game

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

typedef struct	s_map
{
	char	**map;
	int	max_y;
	int	max_x;
}				t_map;

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
	int			color;
}				t_img;

typedef struct	s_raycast
{
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	
	double	map_x;
	double	map_y;
	
	double	side_distx;
	double	side_disty;
	
	double	delta_distx;
	double	delta_disty;
	double	perp_walldist;


	int	step_x;
	int	step_y;
	int	hit;
	int	side;
}		t_raycast;

typedef struct	s_game
{
	t_window	*w; //window/mlx
	t_img		*img; //imaginePlayer
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
//	double		time; DONT possiblyneedthis
//	double		old_time;
	double		move_speed;
	double		rot_speed;
}				t_game;

//static (AKA GLOBAL_fts)
t_game		*_game(void);
t_window	*_window(void);
t_key		*_key(void);
t_map		*_map(void);
t_raycast	*_raycast(void);
//staticRTN
t_window	*rtn_window(void);
t_img		*rtn_img(int x, int y, t_window *w);
//parse (PROGRAM)
void		init_map(t_list *lst);
void		parse_map(char *file);
//pixelManipulation
void		mpp(t_img *img, int x, int y, int color);
//draw
void		fill_map_color(int color);
void		fill_img_square(t_img *img, int cord_x, int cord_y, int color);
void		draw_game(void);
void		draw_img_square(t_img *img, int color);
void		draw_gridline(void); 
//map 
void		find_p_on_map(void);
void		my_map_init(void);
void		my_map_loop(void);
//move
void		update_map_pos(int x, int y);
void		move_player(int y, int x);
int			check_next_move(int y, int x);
//keys
int			ft_key_hook(int keycode, t_window *w);
void		key_listener(void);
//inits
void		init_keys(void);
//raycast
void		ft_raycast(void);
void		init_raycast(void);

//calloc (EXTRAS/MYLIBFT)
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
//utilList
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
//utilStr
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//utilGNL
int		get_next_line(int fd, char **line);
//utilPRINT
void	print_map(void);
//utilCONVERT
int		unit_nb(int x);
//XTRA
void wnl_1(void); //test
#endif
