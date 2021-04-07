#include "includes.h"

t_session *init_session(void)
{
	t_session *session;

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

void print_session_info(t_session *session)
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

int is_session_valid(t_session *session)
{
	return (session->map && session->no &&
	session->so && session->ea && session->we && session->s &&
	session->resolution[0] >= 0 && session->resolution[1] >= 0 &&
	session->ceiling_color[0] >= 0 && session->ceiling_color[1] >= 0 &&
	session->ceiling_color[2] >= 0 && session->floor_color[0] >= 0 &&
	session->floor_color[1] >= 0 && session->floor_color[2] >= 0 &&
	session->ceiling_color[0] < 256 && session->ceiling_color[1] < 256 &&
	session->ceiling_color[2] < 256 && session->floor_color[0] < 256 &&
	session->floor_color[1] < 256 && session->floor_color[2] < 256 &&
	is_map_valid(session));
}

void parse_resolution(t_session *session, char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t') && line[i] != 'R')
		i++;
	i++;
	while (line[i] && !ft_isdigit(line[i]) && (line[i] == ' ' || line[i] ==
	'\t'))
		i++;
	session->resolution[0] = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]) && (line[i] == ' ' || line[i] ==
	'\t'))
		i++;
	if (line[i])
		session->resolution[1] = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			session->resolution[1] = -1;
		i++;
	}

}

void parse_texture_path(t_session *session, char *line, char t, int t_size)
{
	int i;

	i = 0;
	while (line[i] && line[i] != t)
		i++;
	i += t_size;
	if (line[i] == ' ' || line[i] == '\t')
	{
		while (line[i] == ' ' || line[i] == '\t')
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

void parse_color(t_session *session, char *line, char obj)
{
	int i, k;

	i = 0;
	k = 0;
	while (line[i] && line[i] != obj)
		i++;
	i++;
	while (k < 3 && line[i])
	{
		while (line[i] && !ft_isdigit(line[i]) && (line[i] == ' ' || line[i]
		== '\t'))
			i++;
		if (line[i] && ft_isdigit(line[i]) && obj == 'C')
			session->ceiling_color[k] = ft_atoi(line + i);
		if (line[i] && ft_isdigit(line[i]) && obj == 'F')
			session->floor_color[k] = ft_atoi(line + i);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] && line[i] != ',' && line[i] != ' ' && line[i] != '\t')
		{
			if (line[i] && obj == 'C')
				session->ceiling_color[k] = -1;
			if (line[i] && obj == 'F')
				session->floor_color[k] = -1;
		}
		if (k < 2)
		{
			while (line[i] && line[i] != ',')
				i++;
			if (line[i])
				i++;
		}
		k++;
	}
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			if (line[i] && obj == 'C')
				session->ceiling_color[2] = -1;
			if (line[i] && obj == 'F')
				session->floor_color[2] = -1;
		}
		i++;
	}
}

void parse_setting_file(char *file_name, t_session *session)
{
	int fd, n, i;
	char *line;

	n = 0;
	fd = open(file_name, O_RDONLY);
	while (n < 8 && get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] && ft_strlen(line) > 0)
		{
			if (line[i] == 'R' || line[i] == 'N' || (line[i] == 'S' && line[i
			+ 1] != 'O') || line[i] == 'E' || line[i] == 'W' || line[i] ==
			'C' || line[i] == 'F' || (line[i] == 'S' && line[i + 1] == 'O'))
			{
				n++;
				if (line[i] == 'R')
					parse_resolution(session, line);
				if (line[i] == 'N' && line[i + 1] == 'O')
					parse_texture_path(session, line, 'N', 2);
				if (line[i] == 'S' && line[i + 1] == 'O')
					parse_texture_path(session, line, 'S', 2);
				if (line[i] == 'E' && line[i + 1] == 'A')
					parse_texture_path(session, line, 'E', 2);
				if (line[i] == 'W' && line[i + 1] == 'E')
					parse_texture_path(session, line, 'W', 2);
				if (line[i] == 'S' && line[i + 1] != 'O')
					parse_texture_path(session, line, 'S', 1);
				if (line[i] == 'C')
					parse_color(session, line, 'C');
				if (line[i] == 'F')
					parse_color(session, line, 'F');
				break;
			}
			i++;
		}
		free(line);
		line = NULL;
	}
	save_map(fd, session);
}

void free_session(t_session *session)
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