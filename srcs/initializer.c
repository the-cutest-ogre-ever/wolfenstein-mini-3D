#include "includes.h"

void init_view(t_session *session)
{
	session->view->direction = '0';
	session->view->x = 0;
	session->view->y = 0;
	session->view->z = 0;
	session->view->step = 0;
	session->view->view_ang_p = 0;
	session->view->view_ang_y = 0;
	session->view->view_dir_p = 0;
	session->view->view_dir_y = 0;
}

void init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->img_data = NULL;
	img->width = 0;
	img->height = 0;
	img->bpp = 0;
	img->size_l = 0;
	img->endian = 0;
}

void init_win(t_session *session)
{
	session->win->mlx_ptr = NULL;
	session->win->win_ptr = NULL;
	session->win->x = 0;
	session->win->y = 0;
}

void init_ray(t_session *session)
{
	session->ray->cos = 0;
	session->ray->sin = 0;
	session->ray->x = 0;
	session->ray->y = 0;
	session->ray->dir = 0;
	session->ray->sprite = NULL;
}

void init_textures(t_session *session)
{
	session->no_text = (t_img *) malloc(sizeof (t_img));
	if (!session->no_text)
		destroy_session(session, ERROR_MEMORY);
	session->no_text = NULL;
	session->no = NULL;

	session->so_text = (t_img *) malloc(sizeof (t_img));
	if (!session->so_text)
		destroy_session(session, ERROR_MEMORY);
	session->so_text = NULL;
	session->so = NULL;

	session->we_text = (t_img *) malloc(sizeof (t_img));
	if (!session->we_text)
		destroy_session(session, ERROR_MEMORY);
	session->we_text = NULL;
	session->we = NULL;

	session->ea_text = (t_img *) malloc(sizeof (t_img));
	if (!session->ea_text)
		destroy_session(session, ERROR_MEMORY);
	session->ea_text = NULL;
	session->ea = NULL;

	session->s_text = (t_img *) malloc(sizeof (t_img));
	if (!session->s_text)
		destroy_session(session, ERROR_MEMORY);
	session->s_text = NULL;
	session->s = NULL;
}

void init_session(t_session *session)
{
	session->win = (t_win *) malloc(sizeof (t_win));
	if (!session->win)
		destroy_session(session, ERROR_MEMORY);
	else
		init_win(session);
	session->view = (t_view *) malloc(sizeof (t_view));
	if (!session->view)
		destroy_session(session, ERROR_MEMORY);
	else
		init_view(session);
	session->ray = (t_ray *) malloc(sizeof (t_ray));
	if (!session->ray)
		destroy_session(session, ERROR_MEMORY);
	else
		init_ray(session);
	session->map = (t_list *) malloc(sizeof (t_list));
	if (!session->map)
		destroy_session(session, ERROR_MEMORY);
	init_textures(session);
	session->map = NULL;
	session->floor_color_code = 0;
	session->ceil_color_code = 0;
	session->resolution[0] = -1;
	session->resolution[1] = -1;
	session->ceiling_color[0] = -1;
	session->ceiling_color[1] = -1;
	session->ceiling_color[2] = -1;
	session->floor_color[0] = -1;
	session->floor_color[1] = -1;
	session->floor_color[2] = -1;
	session->blk_x = 0;
	session->blk_y = 0;
	session->blk_z = 0;
	session->key_d = 0;
	session->key_s = 0;
	session->key_a = 0;
	session->key_w = 0;
	session->key_esc = 0;
	session->key_left = 0;
	session->key_right = 0;
	session->max_x = 0;
	session->max_y = 0;
	session->img_0 = NULL;
	session->img_1 = NULL;
}
