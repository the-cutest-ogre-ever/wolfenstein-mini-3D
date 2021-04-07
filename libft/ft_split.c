/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:23:42 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 21:22:26 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int counter;
	int prev_is_del;

	counter = 0;
	prev_is_del = 1;
	while (*s)
	{
		if (*s == c)
			prev_is_del = 1;
		else if (prev_is_del)
		{
			counter++;
			prev_is_del = 0;
		}
		s++;
	}
	return (counter);
}

static int	count_l(char const *s, char c)
{
	int counter;

	counter = 0;
	while (*s && *s != c)
	{
		counter++;
		s++;
	}
	return (counter);
}

static void	*free_array(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s || !(array = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			array[i] = (char *)malloc(sizeof(char) * (count_l(s, c) + 1));
			if (!array[i])
				return (free_array(array));
			while (*s && *s != c)
				array[i][j++] = *s++;
			array[i++][j] = '\0';
			j = 0;
		}
	}
	array[i] = NULL;
	return (array);
}
