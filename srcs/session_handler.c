#include "includes.h"

t_session	*init_session(void)
{
	t_session	*session;

	session = (t_session *)malloc(sizeof(t_session));
	session->player = NULL;
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

void	parse_texture_path(t_session *session, char *line, char t, int t_size)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != t)
		i++;
	i += t_size;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (t == 'N')
			session->no = ft_substr(line, i, ft_strlen(line) - i);
		if (t == 'S' && t_size == 2)
			session->so = ft_substr(line, i, ft_strlen(line) - i);
		if (t == 'E')
			session->ea = ft_substr(line, i, ft_strlen(line) - i);
		if (t == 'W')
			session->we = ft_substr(line, i, ft_strlen(line) - i);
		if (t == 'S' && t_size == 1)
			session->s = ft_substr(line, i, ft_strlen(line) - i);
	}
}

void	free_session(t_session *session)
{
	free_map(&session->map);
	free_player(session->player);
	free(session->no);
	free(session->so);
	free(session->ea);
	free(session->we);
	free(session->s);
	free(session);
}
