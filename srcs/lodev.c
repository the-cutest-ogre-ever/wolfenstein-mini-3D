#include "includes.h"

int handle_game(t_session *session)
{
	t_img *temp;

	if (!session->img_0)
	{
		session->img_0 = init_frame(session->win->mlx_ptr, session->win->x,
							  session->win->y);
		session->img_1 = init_frame(session->win->mlx_ptr, session->win->x,
									session->win->y);
		if (!session->img_0 && !session->img_1)
			destroy_session(session, NULL);
	}
	key_handler(session);
	create_frame(session);
	mlx_put_image_to_window(session->win->mlx_ptr, session->win->win_ptr,
							session->img_0->img_ptr, 0, 0);
	temp = session->img_0;
	session->img_0 = session->img_1;
	session->img_1 = temp;
	return (0);
}

void	set_frame_column(int x, double wall_dist, t_session *session)
{
	int y;
	double ang;
	double ang_d;
	double ang_c;
	double ang_f;

	ang_f = atan((-session->view->z) / wall_dist);
	ang_c = atan((session->blk_z - session->view->z) / wall_dist);
	ang = session->view->view_dir_p + session->view->view_ang_p / 2;
	ang_d = session->view->view_ang_p / session->win->y;
	y = -1;
	while (++y < session->win->y)
	{
		if (ang > ang_c)
			((int*)session->img_0->img_data)[y * session->win->x + x] =
					session->ceil_color_code;
		else if (ang > ang_f)
			((unsigned int*)session->img_0->img_data)[y * session->win->x + x] =
					get_wall_pixel(1.0 - get_wall_x(session),
								   1.0 - get_wall_y(ang, wall_dist, session),
								   session, 0);
		else
			((int*)session->img_0->img_data)[y * session->win->x + x] =
					session->floor_color_code;
		ang -= ang_d;
	}
	if (session->ray->sprite)
		add_sprite_to_frame(x, session);
}

void	create_frame(t_session *session)
{
	int x_frame;
	double ang;
	double ang_d;

	ang = session->view->view_dir_y - session->view->view_ang_y / 2;
	ang_d = session->view->view_ang_y / session->win->x;
	x_frame = 0;
	while (x_frame < session->win->x)
	{
		set_frame_column(x_frame, pass_ray(session, ang,
									 session->view->view_dir_y), session);
		ang += ang_d;
		x_frame++;
	}
}

t_img	*init_frame(void *mlx_ptr, int x, int y)
{
	t_img *new_frame;

	new_frame = (t_img *) malloc(sizeof(t_img));
	if (!new_frame)
		return (NULL);
	new_frame->img_ptr = mlx_new_image(mlx_ptr, x, y);
	if (!new_frame->img_ptr)
	{
		free(new_frame);
		return (NULL);
	}
	new_frame->width = x;
	new_frame->height = y;
	new_frame->img_data = mlx_get_data_addr(new_frame->img_ptr, &
	(new_frame->bpp), &(new_frame->size_l), &(new_frame->endian));
	if (new_frame->img_data)
	{
		mlx_destroy_image(mlx_ptr, new_frame->img_ptr);
		free(new_frame);
		return (NULL);
	}
	return (new_frame);
}