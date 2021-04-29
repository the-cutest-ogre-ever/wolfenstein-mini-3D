#ifndef INCLUDES_H
# define INCLUDES_H

# define BUFFER_SIZE 100

#include <fcntl.h>
#include <unistd.h>
# include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "ubuntu_keys.h"
#include "error_codes.h"
# include <X11/keysymdef.h>

typedef struct	s_img
{
	void	*img_ptr;
	int		*img_data;
	int		width;
	int 	height;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_view
{
	char direction;
	double x;
	double y;
	double z;
	double view_ang_y;
	double view_ang_p;
	double view_dir_y;
	double view_dir_p;
	double wall_dist;
	double step;
}				t_view;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}				t_win;

typedef struct	s_sprite
{
	struct s_sprite	*next;
	struct s_sprite	*prev;
	t_img					*text;
	double				sprite_dist;
	double				sprite_x;
}				t_sprite;

typedef struct	s_ray
{
	double			x;
	double			y;
	double			sin;
	double			cos;
	int				dir;
	double			dist;
	t_sprite	*sprite;
}				t_ray;

typedef struct	s_session
{
	int key_w;
	int key_a;
	int key_s;
	int key_d;
	int key_left;
	int key_right;
	int key_esc;
	t_win  *win;
	t_view *view;
	t_list *map;
	t_ray		*ray;
	int		blk_x;
	int		blk_y;
	int		blk_z;
	int max_x;
	int max_y;
	char *no;
	char *so;
	char *ea;
	char *we;
	char *s;
	t_img	*no_text;
	t_img	*ea_text;
	t_img	*we_text;
	t_img	*so_text;
	t_img	*s_text;
	int floor_color_code;
	int ceil_color_code;
	int resolution[2];
	int floor_color[3];
	int ceiling_color[3];
	t_img		*img_0;
	t_img		*img_1;
}				t_session;

int print_error(char *error_code);
void save_map(int fd, t_session *session);
void	parse_color(t_session *session, char *line, char obj);
void	parse_texture_path(t_session *session, char *line, char t, int t_size);
void	parse_resolution(t_session *session, char *line);
void parse_setting_file(char *file_name, t_session *session);
void print_list(t_list *head);
void free_map(t_list **head);
int	is_map_symbol(char c);
int is_map_valid(t_session *session);
void	save_player(t_session *session, int x, int y, char direction);
int	find_player(t_session *session);
void	print_view(t_view view);
void init_session(t_session *session);
void	destroy_session(t_session *session, char *error_code);
void print_session_info(t_session *session);
int is_session_valid(t_session *session);
void free_session(t_session *session);
void	set_window(t_session *session);
void	init_hooks(t_session *session);
int esc_handler(t_session *session);
int		press_handler(int keycode, t_session *session);
int		release_handler(int keycode, t_session *session);
void movement_handler(double ang, t_session *session);
char get_map_elem(t_session *session, int x, int y);
void add_sprite(char val, t_session *session);

#endif
