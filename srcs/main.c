#include "includes.h"

static void is_path_valid(char *file_name)
{
	int length;

	length = ft_strlen(file_name);
	if (length > 4 && (ft_strncmp((file_name + length - 4), ".cub", 4) != 0))
		print_error(ERROR_CUB);
}

static void	start(char *congif_file, int save)
{
	t_session *session;
	if (!(session = (t_session *)malloc(sizeof(t_session))))
		print_error(ERROR_MEMORY);
	printf("border 0\n");
	init_session(session);
	printf("border 1\n");
	session->win->mlx_ptr = mlx_init();
	printf("border 2\n");
	if (!session->win->mlx_ptr)
		destroy_session(session, ERROR_MEMORY);
	printf("border 3\n");
	parse_setting_file(congif_file, session);
	printf("border 4\n");
	find_player(session);
	printf("border 5\n");
	if (!is_session_valid(session))
		destroy_session(session, NULL);
	printf("border 6\n");
	if (save)
	{
		printf("got \"--save\" argument\n");
	} else
	{
		printf("border 7\n");
		set_window(session);
		printf("border 8\n");
		init_hooks(session);
	}
}


int		main(int argc, char **argv)
{
	if (argc > 1)
		is_path_valid(argv[1]);
	if (argc == 2)
		start(argv[1], 0);
	else if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 7))
			start(argv[1], 1);
		else
			print_error(ERROR_ARG);
	}
	else
		print_error(ERROR_ARG);
	return (0);
}
/*
void	session_exit(void)
{
	exit(0);
}
*/

/*
void	save_frame(char *path_to_conf)
{
	t_session *session;

	if (!(cub = (t_cub*)malloc(sizeof(t_cub))))
		ft_exit(ERR_NO_MEMORY);
	cub_init(cub);
	if (!(cub->win->mlx_ptr = mlx_init()))
		cub_destroy(cub, ERR_NO_MEMORY);
	player_init(cub);
	config_parse(path_to_conf, cub);
	window_setup_save(cub);
	if (!cub->frm_0 && !(cub->frm_0 = frame_init(cub->win->mlx_ptr,
												 cub->win->x, cub->win->y)))
		cub_destroy(cub, ERR_NO_MEMORY);
	make_frame(cub);
	if (!create_bmp_img(cub->frm_0))
		cub_destroy(cub, NULL);
	cub_destroy(cub, ERR_NO_ERR);
}
*/