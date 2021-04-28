#include "includes.h"

void	parse_resolution(t_session *session, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'R')
		i++;
	while (line[i] && !ft_isdigit(line[i]) && line[i] == ' ')
		i++;
	session->resolution[0] = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]) && line[i] == ' ')
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

int	find_params(t_session *session, char *line, int i)
{
	if (line[i] == 'R' || line[i] == 'N' || (line[i] == 'S' && line[i + 1]
			!= 'O') || line[i] == 'E' || line[i] == 'W' || line[i] == 'C'
		|| line[i] == 'F' || (line[i] == 'S' && line[i + 1] == 'O'))
	{
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
		return (1);
	}
	return (0);
}

void	parse_setting_file(char *file_name, t_session *session)
{
	int		fd;
	int		i;
	int		n;
	char	*line;

	n = 0;
	fd = open(file_name, O_RDONLY);
	while (n < 8 && get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] && ft_strlen(line) > 0)
		{
			if (find_params(session, line, i) == 1)
			{
				n++;
				break ;
			}
			i++;
		}
		free(line);
		line = NULL;
	}
	save_map(fd, session);
}
