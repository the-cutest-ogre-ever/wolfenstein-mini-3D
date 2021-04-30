#include "includes.h"

void	save_player(t_session *session, int x, int y, char direction)
{
	session->view->x = session->blk_x * x + session->blk_x / 2;
	session->view->y = session->blk_y * y + session->blk_y / 2;
	session->view->wall_dist = (double)session->blk_x / 6;
	session->view->step = sqrt(2 * (double)session->blk_x / 10);
	session->view->direction = direction;
	if (direction == 'N')
		session->view->view_dir_y = -M_PI_2;
	if (direction == 'W')
		session->view->view_dir_y = M_PI;
	if (direction == 'S')
		session->view->view_dir_y = M_PI_2;
	if (direction == 'E')
		session->view->view_dir_y = 0;
}

static int	check_pos(t_session *session, char *line, int max_x)
{
	int	y;

	y = 0;
	while (line[y])
	{
		if (is_map_symbol(line[y]) == 3)
		{
			if (session->view->direction == '0')
				save_player(session, max_x, y, line[y]);
			else
				return (print_error(ERROR_MAP_PLAYER_TOO));
		}
		y++;
	}
	return (y);
}

int	find_player(t_session *session)
{
	int		max_x;
	int		max_y;
	int		y;
	t_list	*head;
	char	*line;

	max_x = 0;
	max_y = 0;
	head = session->map;
	while (head && ft_strlen(head->content))
	{
		line = (char *)head->content;
		y = check_pos(session, line, max_x);
		head = head->next;
		if (y > max_y)
			max_y = y;
		max_x++;
	}
	if (max_x && max_y)
	{
		session->max_x = max_x;
		session->max_y = max_y;
	}
	return (1);
}
