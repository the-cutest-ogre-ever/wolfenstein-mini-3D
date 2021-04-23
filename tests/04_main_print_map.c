#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../srcs/includes.h"

# define TILE_SIZE 32
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

#include "../srcs/includes.h"

int get_col_count(t_list *map)
{
	int counter = 0;
	int max = 0;
	int i;
	while (map)
	{
		i = 0;
		counter = 0;
		while (map->content[i])
		{
			counter++;
			i++;
		}
		if (counter > max)
			max = counter;
		map = map->next;
	}
	return (max);
}

int get_rows_count(t_list *map)
{
	int counter = 0;
	while (map)
	{
		counter++;
		map = map->next;
	}
	return (0);
}

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->cols)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, game->cols * TILE_SIZE - 1, 0, game->cols * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < game->rows)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, game->rows * TILE_SIZE - 1, WIDTH, game->rows * TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y  + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i);
			j++;
		}
		i++;
	}
}

int		deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int 	close(t_game *game)
{
	exit(0);
}

void	game_init(t_game *game, t_session *session)
{
	game->map = session->map;
	game->rows = get_rows_count(game->map);
	game->cols  = get_col_count(game->map);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}


int main(int argc, char **argv)
{
	t_session *session;
	t_game game;

	session = init_session();
	if (argc > 1)
	{
		parse_setting_file(argv[1], session);
		if (session)
		{
			print_session_info(session);
			print_list(session->map);
			if (session->player)
				print_player_info(session->player);
			if (is_session_valid(session))
				printf(">>>>> SESSION IS VALID <<<<<\n");
			else
				printf(">>>>> SESSION IS INVALID <<<<<\n");
			free_session(session);
		}
	}
	game_init(&game, session);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}}