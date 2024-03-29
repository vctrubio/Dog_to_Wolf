#ifndef HEADER_H
# define	HEADER_H

#ifndef __unix
	# include "../lmlx/mlx.h"
	# include "keys.h"
#else
	# include "../mlx_linux/mlx.h"
	# include <mlx.h>
	# include "keys_linux.h"
#endif

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
# define M_UNIT 10  //MAP_UNIT- change it if you want, will resize the game
``
typedef struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

typedef struct	s_window
{
	void	*mlx;
	void	*window;
}				t_window;

typedef struct	s_map
{
	int		max_y;
	int		max_x;
	char	**map;
	char	player;
	int		map_start_y;
	int		map_start_x;
	bool	valid;
	
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

typedef struct	s_texture
{
	char	*floor;
	char	*cealing;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}				t_texture;

typedef struct	s_game
{
	t_window	*w;
	t_img		*minimap;
	t_img		*raycast;
	double		pos_x; //for minimap sake
	double		pos_y; //minimap sake
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	double 		time;
	double		oldtime;
}				t_game;



t_img	*_image_bellow();
void	freeFunction();
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst);
void	del(void *content);

//static (AKA GLOBAL_fts)
t_key		*_key(void);
t_map		*_map(void);
t_game		*_game(void);
t_img		*_image(void);
t_window	*_window(void);
t_raycast	*_raycast(void);
t_texture	*_texture(void);
//staticRTN
t_window	*rtn_window(void);
int			map_divide(t_list *lst);
void		map_data_lvl2(t_texture *texture, char *str);
//parse (PROGRAM)
void		init_map(t_list *lst);
void		parse_map(char *file);
//pixelManipulation
void		mpp(t_img *img, int x, int y, int color);
//draw
void		draw_gridline(t_img *img); 
void		draw(void);
void		draw_img_square(t_img *img, int color);
void		fill_img_square(t_img *img, int cord_x, int cord_y, int color);
void		draw_raycast(void);
//map 
void		my_map_init(void);
void		my_map_loop(void);
void		find_p_on_map(void);
//movefreeFunction
void		init_keys(void);
//raycast
void		ft_raycast(void);
void		init_raycast(void);
//exit
void		ft_exit(void);

//utilCalloc (EXTRAS/MYLIBFT)
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *s, int c, size_t n);
//utilList
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
//utilStr
int		my_strnstr(char *str, int type);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strnstr(const char *big, const char *little, size_t len);
//utilGNL
int		get_next_line(int fd, char **line);
//utilPRINT
void	print_map(void);
//utilCONVERT
int		unit_nb(int x);
//XTRA
void	move_player(int y, int x);
t_img	*rtn_img(int x, int y);
void	key_listener(void);
void	update_map_pos(int x, int y);

//pase_map
int pParse(char **);

typedef struct	s_raycast
{
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	int		map_x;
	int		map_y;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perp_walldist;
	int		draw_end;
	int		draw_start;
	int		lineheight;
	int		text_y;
	int		**matrix;
	double	wall_x;
	int		text_x;
	double	text_pos;
	int	step_x;
	int	step_y;
	int step;
	int	hit;
	int	side;
	int y;

}		t_raycast;

#endif
