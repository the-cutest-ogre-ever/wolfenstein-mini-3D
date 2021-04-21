/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 01:20:02 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 23:43:16 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 && !s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	if (s1)
	{
		k = 0;
		while (s1[k])
			str[i++] = s1[k++];
	}
	if (s2)
	{
		k = 0;
		while (s2[k])
			str[i++] = s2[k++];
	}
	str[i] = '\0';
	return (str);
}
