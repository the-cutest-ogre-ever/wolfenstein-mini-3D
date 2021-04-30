#include "includes.h"

void	set_window(t_session *session)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_get_screen_size(session->win->mlx_ptr, &x, &y);
	if (x && y)
	{
		if (x < session->resolution[0])
			session->win->x = x;
		else
			session->win->x = session->resolution[0];
		if (y < session->resolution[1])
			session->win->y = y;
		else
			session->win->y = session->resolution[1];
	}
	session->win->win_ptr = mlx_new_window(session->win->mlx_ptr,
									   session->win->x, session->win->y,
									   "swamp of cuties");
	if (!session->win->win_ptr)
		destroy_session(session, ERROR_MEMORY);
}

void	init_hooks(t_session *session)
{
	mlx_loop_hook(session->win->mlx_ptr, handle_game, session);
	mlx_hook(session->win->win_ptr, 2, 1L << 0, press_handler, session);
	mlx_hook(session->win->win_ptr, 3, 1L << 1, release_handler, session);
	mlx_hook(session->win->win_ptr, 17, 1L << 17, esc_handler, session);
	mlx_loop(session->win->mlx_ptr);
}

float movement_length(float ang, t_session *session)
{
	float len;

	pass_ray(session, ang, ang);
	len = session->ray->dist - session->view->wall_dist;
	return (len);
}

void movement_handler(double ang, t_session *session)
{
	float sin;
	float cos;
	float wall_dist_x;
	float wall_dist_y;
	float wall_dist_dir;

	sin = sinf(ang);
	cos = cosf(ang);
	if (sin > 0)
		wall_dist_y = movement_length(M_PI_2, session);
	else
		wall_dist_y = movement_length(-M_PI_2, session);
	if (cos > 0)
		wall_dist_x = movement_length(0, session);
	else
		wall_dist_x = movement_length(M_PI, session);
	wall_dist_dir = pass_ray(session, ang, ang);
	if (wall_dist_dir < session->view->step)
		return ;
	if (wall_dist_y > fabs(session->view->step * sin))
		session->view->y += session->view->step * sin;
	else
		session->view->y += wall_dist_y * sin;
	if (wall_dist_x > fabs(session->view->step * cos))
		session->view->x += session->view->step * cos;
	else
		session->view->x += wall_dist_x * cos;
}
