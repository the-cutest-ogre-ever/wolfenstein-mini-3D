#include "includes.h"

void count_sprite(char cell, t_session *session)
{

}

char get_map_elem(t_session *session, x, y)
{

}

char find_ray(int x, int y, t_session *session)
{
	if (x < 0 || y < 0)
		return ('1');
	if (session->ray->dir == 1 && y - 1 < session->max_y && x < session->max_x)
		return (get_map_elem(session, y - 1, x));
	if (session->ray->dir == 2 && y + 1 < session->max_y && x < session->max_x)
		return (get_map_elem(session, y + 1, x));
	if (session->ray->dir == 4 && y < session->max_y && x - 1 < session->max_x)
		return (get_map_elem(session, y, x - 1));
	if (session->ray->dir == 3 && y < session->max_y && x + 1 < session->max_x)
		return get_map_elem(session, y, x + 1);
	return ('1');

}

void set_dir(double x_dist, double y_dist, t_session *session)
{
	if (x_dist < y_dist)
	{
		if (session->ray->cos > 0)
		{
			session->ray->dir = 3;
			session->ray->x += (double)session->blk_x / 1000;
		}
		else
		{
			session->ray->dir = 4;
			session->ray->x -= (double)session->blk_x / 1000;
		}
	}
	else
	{
		if (session->ray->sin > 0)
		{
			session->ray->dir = 2;
			session->ray->x += (double)session->blk_y / 1000;
		}
		else
		{
			session->ray->dir = 1;
			session->ray->x -= (double)session->blk_y / 1000;
		}
	}
}

void find_cross(double x, double y, t_session *session)
{
	double x_dist;
	double y_dist;

	if (session->ray->cos > 0)
		x_dist = ((double)session->blk_x - x) / session->ray->cos;
	else
		x_dist = fabs(x / session->ray->cos);
	if (session->ray->sin > 0)
		y_dist = ((double)session->blk_y - y) / session->ray->sin;
	else
		y_dist = fabs(y / session->ray->sin);
	if (x_dist < y_dist)
	{
		session->ray->x += x_dist * session->ray->cos;
		session->ray->y += x_dist * session->ray->sin;
		set_dir(x_dist, y_dist, session);
	} else
	{
		session->ray->x += y_dist * session->ray->cos;
		session->ray->y += y_dist * session->ray->sin;
		set_dir(x_dist, y_dist, session);
	}
}

int check_next_cell(t_session *session)
{
	double x_cell;
	double y_cell;
	double x;
	double y;
	char cell;

	x_cell = -1;
	y_cell = -1;
	x = modf(session->ray->x / session->blk_x, &x_cell) * session->blk_x;
	y = modf(session->ray->y / session->blk_y, &x_cell) * session->blk_y;
	find_cross(x, y, session);
	cell = find_ray((int)x_cell, (int)y_cell, session);
	if (cell == '2')
		count_sprite(cell, session);
	if (is_map_symbol(cell) == 1 || is_map_symbol(cell) == 2)
		return (1);
	else
		return (0);
}

double pass_ray(t_session *session, double ang, double m_ang)
{
	int i;
	double wall_dist;

	i = 0;
	session->ray->x = session->view->x;
	session->ray->y = session->view->y;
	session->ray->sin = sin(ang);
	session->ray->cos = cos(ang);
	if (session->ray->sprite)
		free_sprites(&session->ray->sprite);
	while (check_next_cell(session) && i < 50)
		i++;
	wall_dist = sqrt(pow(session->ray->x - session->view->x, 2) +
							 pow(session->ray->y - session->view->y, 2));
	session->ray->dist = wall_dist;
	return (wall_dist * fabs(cos(fabs(m_ang - ang))));
}