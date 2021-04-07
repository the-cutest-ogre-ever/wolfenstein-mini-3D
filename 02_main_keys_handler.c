#include "includes.h"

typedef struct  s_vars {
	void        *mlx;
	void        *win;
}               t_vars;

int             close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int             key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook! %d\n", keycode);
	if (keycode == X_EVENT_KEY_EXIT || keycode == KEY_ESC)
	{
		printf("Exiting program...\n");
		close_window(keycode, vars);
		exit(0);
	}
}


int main(int argc, char **argv)
{
	/*
	t_session *session;

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
	 */

	t_vars      vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "wInDoW");
	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_hook(vars.win, 13, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}