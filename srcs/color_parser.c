#include "includes.h"

static void	check_color(t_session *session, char *line, int i, char obj)
{
	if (line[i] && line[i] != ',' && line[i] != ' ')
	{
		if (line[i] && obj == 'C')
			session->ceiling_color[2] = -1;
		if (line[i] && obj == 'F')
			session->floor_color[2] = -1;
	}
}

static int	parse_color_mini(t_session *session, char *line, int i, char obj)
{
	int	k;

	k = 0;
	while (k < 3 && line[i])
	{
		while (line[i] && !ft_isdigit(line[i]) && line[i] == ' ' )
			i++;
		if (line[i] && ft_isdigit(line[i]) && obj == 'C')
			session->ceiling_color[k] = ft_atoi(line + i);
		if (line[i] && ft_isdigit(line[i]) && obj == 'F')
			session->floor_color[k] = ft_atoi(line + i);
		while (ft_isdigit(line[i]))
			i++;
		check_color(session, line, i, obj);
		if (k < 2)
		{
			while (line[i] && line[i] != ',')
				i++;
			if (line[i])
				i++;
		}
		k++;
	}
	return (i);
}

void	parse_color(t_session *session, char *line, char obj)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != obj)
	{
		if (line[i] != ' ')
			return;
		i++;
	}
	i++;
	i = parse_color_mini(session, line, i, obj);
	while (line[i++])
		check_color(session, line, i, obj);
	if (obj == 'F')
		session->floor_color_code = 0 | (session->floor_color[0] << 16) |
				(session->floor_color[1] << 8) | (session->floor_color[2] <<
				0);
	if (obj == 'C')
		session->ceil_color_code = 0 | (session->ceiling_color[0] << 16) |
									(session->ceiling_color[1] << 8) | (session->ceiling_color[2] <<
																							  0);
}
