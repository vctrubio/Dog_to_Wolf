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
# include <limits.h>
# include "../libft/include/libft.h"

# define WHEIGHT 800 //WINDOW_HEIGHT
# define WWIDTH 800

# define SDHEIGHT 42 //STANDARD_HEIGHT
# define SDWIDTH 42
# define BUFFER_SIZE 1
# define M_UNIT 10  //MAP_UNIT- change it if you want, will resize the game

# define PI 3.14159265
# define TILE_SIZE	64
# define MAGNITUDE_ANGLE	3
# define MAGNITUDE		10
# define MAP_SCALE	16
# define TILE_SIZE	64

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vector
{
	int		angle;
	double	mag;
}	t_vector;

typedef struct s_pov
{
	t_point		p;
	int			dtp;
	int			center;
	int			width;
	int			height;
	int			angle;
	int			mag;
	int			w_down;
	int			s_down;
	int			d_down;
	int			a_down;
	int			l_down;
	int			r_down;
}		t_pov;

typedef struct s_ray
{
	int		angle;
	double	height;
	double	dist_wall;
	int		color;
	t_point	end;
}				t_ray;

typedef struct	s_window
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
}				t_window;

typedef struct	s_map
{
	int		max_y;
	int		max_x;
	char	**map;
	bool	valid;
	char	player;
	int		biggest_len;
	int		map_start_y;
	int		map_start_x;
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
	int		floor_value;
	int		cealing_value;
	char	*floor;
	char	*cealing;
	char	*north_texture;
	t_img	*north_img;
	char	*south_texture;
	t_img	*south_img;
	char	*west_texture;
	t_img	*east_img;
	char	*east_texture;
	t_img	*west_img;
}				t_texture;

typedef struct	s_game
{
	t_window		*w;
	t_img			*minimap;
	t_img			*raycast;
	int				width;
	int				height;
	char			**map;
	t_texture		walls;
	//
        double          pos_x; //minimap
        double          pos_y; //minimap
        double          dir_x;
        double          dir_y;
        double          plane_x;
        double          plane_y;
        double          move_speed;
        double          rot_speed;
        double          time;
        double          oldtime;
}				t_game;


bool	ft_strexact(char *s1, char *s2);


int		tile_size(void);
void	destroy_image(void);
int		convert_color(char *str);
int     handle_key_up(int key_code, void *pov);
int     handle_key_down(int key_code, void *pov);
void	draw_line(t_game *game, t_ray ray, int col);

//MATH
int	r_angle(int angle);
double	fcos(int angle);
double	fsin(int angle);
double	ftan(int angle);
double	norm(int xx, int yy);


double	nearest_horizontal(t_game *game, int a);
double	nearest_vertical(t_game *game, int a);

t_point	horizontal_step(int a);
t_point	vertical_step(int a);
t_point	p(double x, double y);
t_point	add_point(t_point p1, t_point p2);
int		collide(t_game *game, t_point p, int angle);

//new image
void	init_img_game(t_game *game);
t_img	*new_image(t_window *win, int height, int width);

//raycast
void	paint_window(void);
void	my_raycast(t_game *game);


//img tex
void	init_walls(t_game *game, t_window *win);

t_img			*correct_texture(t_game *game, int i);
unsigned int	texture_pixel_color(t_point p, t_ray ray, t_img *texture);
unsigned int	get_texture_color(t_img *texture, int pixel_x, int pixel_y);

//img color
int	shade(double distance, int color);
int	gen_trgb(int opacity, int red, int green, int blue);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
int	get_opacity(int trgb);

//ifind
void	move(int key_code, t_pov *pov);
void	rotate(int key_code, t_pov *pov);
t_point		add_vec(t_point p, t_vector v);
t_vector	vec(int angle, double mag);

//initGame
void	init_game(void);

///
void	free_function();
void	del(void *content);
char	**map_fill(char **old_map);
void	ft_lstdelone(t_list *lst, void (*del)(void*));

//static (AKA GLOBAL_fts)
t_map		*_map(void);
t_game		*_game(void);
t_img		*_image(void);
t_window	*_window(void);
t_pov		*_pov();
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
//map 
void		my_map_init(void);
void		my_map_loop(void);



void		find_p_on_map(int y);

void		ft_exit(char *msg);

//utilCalloc (EXTRAS/MYLIBFT)
//utilList
//utilStr
int		my_strnstr(char *str, int type);
//utilGNL
int		get_next_line(int fd, char **line);
//utilPRINT
//utilCONVERT
int		unit_nb(int x);
//XTRA
void	move_player(int y, int x);
t_img	*rtn_img(int x, int y);
void	key_listener(void);
void	update_map_pos(int x, int y);

//pase_map
int p_parse(char **);

#endif
