#include "includes.h"

int is_map_symbol(char c)
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

int is_map_valid(t_session *session)
{
	int x;
	int y;
	char *line;
	char *prev;
	char *next;
	t_list *head = session->map;

	x = 0;
	prev = NULL;
	next = NULL;
	while (head && ft_strlen(head->content))
	{
		y = 0;
		line = (char *)head->content;
		if (head->next)
			next = (char *)head->next->content;
		else
			next = NULL;
		while (line[y])
		{
			if (!is_map_symbol(line[y]))
				return (0);
			if (is_map_symbol(line[y]) == 3)
			{
				if (!session->player)
				{

				} else
				{
					printf("ERROR: Player already exists!\n");
					return (0);
				}
			}
			if (is_map_symbol(line[y]) == 2 || is_map_symbol(line[y]) == 3)
			{
				if (!prev || !next || !line[y - 1] || !line[y + 1])
					return (0);
				else if (is_map_symbol(line[y - 1]) < 2 || is_map_symbol
				(line[y + 1]) < 2 || is_map_symbol(prev[y]) < 2 ||
				is_map_symbol(next[y] < 2) || is_map_symbol(prev[y - 1]) < 2
				|| is_map_symbol(prev[y + 1]) < 2 || is_map_symbol(next[y - 1])
				< 2 || is_map_symbol(next[y + 1]) < 2)
				return (0);
			}
			y++;
		}
		prev = line;
		head = head->next;
		x++;
	}
	if (head && ft_strlen(head->content) == 0)
	{
		printf("empty lines in a map\n");
		return (0);
	}

	return (1);
}

void print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}


void save_map(int fd, t_session *session)
{
	char *line;
	int empty = 1;

	line = NULL;
	while (empty && get_next_line(fd, &line))
	{
		if (ft_strlen(line) > 0)
		{
			ft_lstadd_back(&session->map, ft_lstnew(line));
			empty = 0;
		}
		else
			free(line);
		line = NULL;
	}
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&session->map, ft_lstnew(line));
		line = NULL;
	}
	ft_lstadd_back(&session->map, ft_lstnew(line));
}


void free_map(t_list **head)
{
	t_list *current;
	t_list *next;

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
