#ifndef INCLUDES_H
# define INCLUDES_H

# define BUFFER_SIZE 100

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "ubuntu_keys.h"
#include "error_codes.h"

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_view
{
	char direction;
	int x;
	int y;
}				t_view;

typedef struct	s_session
{
	t_view view;
	t_list *map;
	int resolution[2];
	char *no;
	char *so;
	char *ea;
	char *we;
	char *s;
	int floor_color[3];
	int ceiling_color[3];

}				t_session;

typedef struct	s_game
{
	void *mlx;
	void *win;
	t_img img;

	t_list *map;
	int cols;
	int rows;
}	t_game;

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
t_session *init_session(void);
void print_session_info(t_session *session);
int is_session_valid(t_session *session);
void free_session(t_session *session);

#endif
