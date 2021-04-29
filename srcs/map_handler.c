#include "includes.h"

int	is_map_symbol(char c)
{
	if (c == ' ')
		return (1);
	if (c == '2' || c == '0')
		return (2);
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (3);
	if (c == '1')
		return (4);
	return (0);
}

char get_map_elem(t_session *session, int x, int y)
{
	char	*line;
	t_list	*head;
	int x_local;

	x_local = 0;
	head = session->map;
	while (head && x_local < x)
	{
		x_local++;
		head = head->next;
	}
	line = (char *)head->content;
	return (line[y]);
}

static int	check_surround(char *line, char *next, char *prev)
{
	int	y;

	y = 0;
	while (line[y])
	{
		if (!is_map_symbol(line[y]))
			return (print_error(ERROR_MAP));
		if (is_map_symbol(line[y]) == 2 || is_map_symbol(line[y]) == 3)
		{
			if (!prev || !next || !line[y - 1] || !line[y + 1])
				return (0);
			else if (is_map_symbol(line[y - 1]) < 2
				|| is_map_symbol(line[y + 1]) < 2
				|| is_map_symbol(prev[y]) < 2
				|| is_map_symbol(next[y] < 2)
				|| is_map_symbol(prev[y - 1]) < 2
				|| is_map_symbol(prev[y + 1]) < 2
				|| is_map_symbol(next[y - 1]) < 2
				|| is_map_symbol(next[y + 1]) < 2)
				return (print_error(ERROR_MAP));
		}
		y++;
	}
	return (1);
}

int	is_map_valid(t_session *session)
{
	char	*line;
	char	*prev;
	char	*next;
	t_list	*head;

	prev = NULL;
	next = NULL;
	head = session->map;
	while (head && ft_strlen(head->content))
	{
		line = (char *)head->content;
		if (head->next)
			next = (char *)head->next->content;
		else
			next = NULL;
		if (!check_surround(line, next, prev))
			return (0);
		prev = line;
		head = head->next;
	}
	if (head && ft_strlen(head->content) == 0)
		return (print_error(ERROR_MAP_EMPTY_LINES));
	return (1);
}

void	free_map(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head = NULL;
}
