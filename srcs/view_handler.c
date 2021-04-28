#include "includes.h"

void	save_player(t_session *session, int x, int y, char direction)
{
	session->view.x = x;
	session->view.y = y;
	session->view.direction = direction;
}

void	print_view(t_view view)
{
	printf("Player info:\n\tx: %d\n\ty: %d\n\tdir: %c\n", view.x, view.y,
		view.direction);
}

static int	check_pos(t_session *session, char *line, int max_x)
{
	int	y;

	y = 0;
	while (line[y])
	{
		if (is_map_symbol(line[y]) == 3)
		{
			if (session->view.direction == '0')
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
	printf("MAXIMUM: \n\tmax_x: %d\tmax_y: %d\n", max_x, max_y);
	return (1);
}
