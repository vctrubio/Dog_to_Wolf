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

# define WHEIGHT 300 //WINDOW_HEIGHT x 10 of new.ber mapgrid
# define WWIDTH 300

# define SDHEIGHT 42 //STANDARD_HEIGHT
# define SDWIDTH 42
# define BUFFER_SIZE 1
# define M_UNIT 10  //MAP_UNIT- change it if you want, will resize the game



# define INT_MAX 2147483647
# define PI 3.1416
# define W_KEY 0x0077
# define S_KEY 0x0073
# define A_KEY 0x0061
# define D_KEY 0x0064
# define RIGHT_ARROW_KEY 0x00ff53
# define LEFT_ARROW_KEY 0x00ff51
# define M_KEY 0x006d
# define ESC_KEY 0x00ff1b
# define NORTH 4.71
# define SOUTH 1.57
# define EAST 0
# define WEST PI
# define HORZ 0
# define VERT 1
# define FALSE 0
# define TRUE 1
# define WALL_2D_COLOR 0x4d4d33
# define RAYS_2D_COLOR 0xffff66
# define FOV 1.1
# define WALL_WIDTH 1
# define MOVE_SPEED 25
# define ROTAT_SPEED 0.10
# define MAP2D_SCALE 0.1
# define TILE_SIZE 64
# define OFFSET 8




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

typedef struct	s_img
{
	t_window	*w;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img; //t_data

typedef struct	s_point {
	double		x;
	double		y;
	int			color;
}				t_point;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
	int			max_w;
	int			max_h;
	int			n_column;
	int			n_row;
	t_point		*init_posit;
	double		rotation_angle;
	int			num_rays;
	int			color_ceiling;
	int			color_floor;
	char		**path;
	int			n_sprites;
	t_point		**sprite_posit;
	bool		valid;
	char		player;
}				t_map;

typedef struct	s_player {
	t_point		*posit;
	int			turn_direction;
	int			walk_direction;
	double		rotation_angle;
	int			move_speed;
	double		rotation_speed;
	double		dist_proj_plane;
}				t_player;


typedef struct	s_texture
{
	char	*floor;
	char	*cealing;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}				t_texture;

typedef struct	s_ray {
	t_point		*collision;
	double		dist_wall;
	double		ray_angle;
	int			coord;
}				t_ray;

typedef struct	s_tex {
	t_img		*data;
	int			width;
	int			height;
}				t_tex;

typedef struct	s_game

{
	t_window	*w;
	t_img		*minimap;
	t_img		*raycast;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	double 		time;
	double		oldtime;
}				t_game;


/////NEW.c//////////////////

void new_calc_game(void);




////////////////////////////
int	test_key_code(int keycode);
///////////////////////////
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
t_ray	*_ray(void);
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
void	update_map_pos(int x, int y);

//pase_map
int pParse(char **);

#endif
