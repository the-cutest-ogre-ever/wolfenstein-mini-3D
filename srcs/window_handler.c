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
	mlx_loop_hook(session->win->mlx_ptr, process_game, session);
	mlx_hook(session->win->win_ptr, 2, 1L << 0, key_press, session);
	mlx_hook(session->win->win_ptr, 3, 1L << 1, key_release, session);
	mlx_hook(session->win->win_ptr, 17, 1L << 17, esc_press, session);
	mlx_loop(session->win->mlx_ptr);
}

void movement_handler(double ang, t_session *session)
{
	
}

float movement_length(float ang, t_session *session)
{

}