#include "includes.h"

void	window_setup(t_session *session)
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
