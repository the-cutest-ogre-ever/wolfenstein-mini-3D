#include "libft.h"

int	has_eol(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	find_eol(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*strjoin_wrapper(char *str, char *buffer)
{
	char	*res_str;

	res_str = ft_strjoin(str, buffer);
	free(str);
	return (res_str);
}

char	*substr_wrapper(char *str, int is_line)
{
	char	*res_str;

	if (!str)
		return (0);
	if (is_line)
	{
		res_str = ft_substr(str, 0, find_eol(str));
		if (!res_str)
		{
			free(str);
			return (0);
		}
	}
	else
	{
		if (!str[find_eol(str)])
		{
			free(str);
			return (0);
		}
		res_str = ft_substr(str, find_eol(str) + 1, ft_strlen(str)
				- find_eol(str) - 1);
		free(str);
	}
	return (res_str);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest_buffer;
	char		*buffer;
	int			bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0
		|| !buffer)
		return (-1);
	bytes = 1;
	while (!has_eol(rest_buffer) && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes] = '\0';
		rest_buffer = strjoin_wrapper(rest_buffer, buffer);
	}
	free(buffer);
	*line = substr_wrapper(rest_buffer, 1);
	rest_buffer = substr_wrapper(rest_buffer, 0);
	return (bytes);
}
