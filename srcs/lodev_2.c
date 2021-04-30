#include "includes.h"

double	get_wall_x(t_session *session)
{
	double i_ptr;

	if (session->ray->dir == 3)
		return (1.0 - modf(session->ray->y / (double)session->blk_y, &i_ptr));
	if (session->ray->dir == 2)
		return (modf(session->ray->x / (double)session->blk_x, &i_ptr));
	if (session->ray->dir == 4)
		return (modf(session->ray->y / (double)session->blk_y, &i_ptr));
	return (1.0 - modf(session->ray->x / (double)session->blk_x, &i_ptr));
}

double	get_wall_y(double ang, double wall_dist, t_session *session)
{
	return ((session->view->z + wall_dist * tan(ang)) / session->blk_z);
}

unsigned int get_wall_pixel(double x, double y, t_session *session, int
is_sprite)
{
	t_img *text;

	if (is_sprite)
		return ((int *)session->s_text->img_data)[(int)((double)
		session->s_text->height * y) * session->s_text->width + (int)((double)
		session->s_text->width * x)];
	if (session->ray->dir == 1)
		text = session->no_text;
	else if (session->ray->dir == 2)
		text = session->so_text;
	else if (session->ray->dir == 4)
		text = session->we_text;
	else
		text = session->ea_text;
	return ((int *)text->img_data)[(int)((double)text->height * y)
								   * text->width + (int)((double)text->width * x)];
}

void add_sprite_to_frame_mini(int x_frame, double ang_d, t_sprite *sprites,
						 t_session *session)
{
	double ang_f;
	double ang_c;
	double ang;
	int y_frame;
	unsigned int pxl;

	ang_f = atan((-session->view->z) / sprites->sprite_dist);
	ang_c = atan((session->blk_z - session->view->z) / sprites->sprite_dist);
	ang = session->view->view_dir_p + session->view->view_ang_p / 2;
	y_frame = -1;
	while (sprites->sprite_x >= 0 && ++y_frame < session->win->y)
	{
		if (ang < ang_c && ang > ang_f)
		{
			pxl = get_wall_pixel(sprites->sprite_x, get_wall_y(ang,
													  sprites->sprite_dist,
													  session), session, 1);
			if (pxl != 0)
				((unsigned int *)session->img_0->img_data)[y_frame *
				session->win->x + x_frame] = pxl;
		}
		ang -= ang_d;
	}
}

void add_sprite_to_frame(int x_frame, t_session *session)
{
	double ang_d;
	t_sprite *sprites;

	ang_d = session->view->view_ang_p / session->win->y;
	sprites = get_last_sprite(session->ray->sprite);
	while (sprites)
	{
		add_sprite_to_frame_mini(x_frame, ang_d, sprites, session);
		if (sprites->prev)
		{
			sprites = sprites->prev;
			free(sprites->next);
			sprites->next = NULL;
		} else
		{
			free(sprites);
			sprites = NULL;
			session->ray->sprite = NULL;
		}
	}
}
