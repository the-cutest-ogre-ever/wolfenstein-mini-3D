#include "includes.h"

int		main(int argc, char **argv)
{
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
void	start(char *congif_file, int save)
{
	t_session *session;

	if (!(session = (t_session *)malloc(sizeof(t_session))))
		print_error(ERROR_MEMORY);
	init_session(session);
	if (!(session->win->mlx_ptr = mlx_init()))
		destroy_session(session, ERR_MEMORY);

	parse_setting_file(congif_file, session);
	find_player(session);

	//player_init(session);
	//config_parse(congif_file, session);
	if (!is_session_valid(session))
		destroy_session(session, NULL);

	if (save)
	{
		/*
		window_setup_save(cub);
		if (!cub->frm_0 && !(cub->frm_0 = frame_init(cub->win->mlx_ptr,
													 cub->win->x, cub->win->y)))
			cub_destroy(cub, ERR_NO_MEMORY);
		make_frame(cub);
		if (!create_bmp_img(cub->frm_0))
			cub_destroy(cub, NULL);
		cub_destroy(cub, ERR_NO_ERR);
		 */
	} else
	{
		set_window(session);
		init_hooks(session);
	}
}

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