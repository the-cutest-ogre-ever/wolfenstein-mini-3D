/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:23:13 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 23:43:54 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] && i != size)
		i++;
	while (src[k] && i + k + 1 < size)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i < size)
		dst[i + k] = '\0';
	return (ft_strlen(src) + i);
}
