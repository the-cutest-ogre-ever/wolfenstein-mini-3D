#include "includes.h"

int esc_handler(t_session *session)
{
	destroy_session(session, NULL);
	return (0);
}

int		press_handler(int keycode, t_session *session)
{
	if (keycode == XK_w)
		session->key_w = 1;
	if (keycode == XK_a)
		session->key_a = 1;
	if (keycode == XK_s)
		session->key_s = 1;
	if (keycode == XK_d)
		session->key_d = 1;
	if (keycode == XK_Left)
		session->key_left = 1;
	if (keycode == XK_Right)
		session->key_right = 1;
	if (keycode == XK_Escape)
		session->key_esc = 1;
	return (0);
}

int		release_handler(int keycode, t_session *session)
{
	if (keycode == XK_w)
		session->key_w = 0;
	if (keycode == XK_a)
		session->key_a = 0;
	if (keycode == XK_s)
		session->key_s = 0;
	if (keycode == XK_d)
		session->key_d = 0;
	if (keycode == XK_Left)
		session->key_left = 0;
	if (keycode == XK_Right)
		session->key_right = 0;
	if (keycode == XK_Escape)
		session->key_esc = 0;
	return (0);
}

void	step_handler(t_session *session, char key)
{
	if (key == 'w')
		movement_handler(session->view->view_dir_y, session);
	if (key == 'a')
		movement_handler(session->view->view_dir_y - M_PI_2, session);
	if (key == 's')
		movement_handler(session->view->view_dir_y + M_PI, session);
	if (key == 'd')
		movement_handler(session->view->view_dir_y + M_PI_2, session);
}

void	key_handler(t_session *session)
{
	if (session->key_left)
		session->view->view_dir_y -= M_PI / 72;
	if (session->key_right)
		session->view->view_dir_y += M_PI / 72;
	if (session->key_w)
		step_handler(session, 'w');
	if (session->key_a)
		step_handler(session, 'a');
	if (session->key_s)
		step_handler(session, 's');
	if (session->key_d)
		step_handler(session, 'd');
	if (session->key_esc)
		esc_handler(session);
}