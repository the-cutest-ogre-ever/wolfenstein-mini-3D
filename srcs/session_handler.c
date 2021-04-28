#include "includes.h"

t_session	*init_session(void)
{
	t_session	*session;

	session = (t_session *)malloc(sizeof(t_session));
	session->view.direction = '0';
	session->resolution[0] = -1;
	session->resolution[1] = -1;
	session->map = NULL;
	session->no = NULL;
	session->so = NULL;
	session->ea = NULL;
	session->we = NULL;
	session->s = NULL;
	session->ceiling_color[0] = -1;
	session->ceiling_color[1] = -1;
	session->ceiling_color[2] = -1;
	session->floor_color[0] = -1;
	session->floor_color[1] = -1;
	session->floor_color[2] = -1;
	return (session);
}

void print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

void	print_session_info(t_session *session)
{
	printf("Resolution: %d %d\n", session->resolution[0],
		session->resolution[1]);
	printf("NO texture path: %s\n", session->no);
	printf("SO texture path: %s\n", session->so);
	printf("EA texture path: %s\n", session->ea);
	printf("WE texture path: %s\n", session->we);
	printf("S texture path: %s\n", session->s);
	printf("Ceiling color: %d,%d,%d\n", session->ceiling_color[0],
		session->ceiling_color[1], session->ceiling_color[2]);
	printf("Floor color: %d,%d,%d\n", session->floor_color[0],
		   session->floor_color[1], session->floor_color[2]);
}

void	free_session(t_session *session)
{
	free_map(&session->map);
	free(session->no);
	free(session->so);
	free(session->ea);
	free(session->we);
	free(session->s);
	free(session);
}
