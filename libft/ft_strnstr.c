/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:23:52 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 20:26:46 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	src_length;

	src_length = ft_strlen(little);
	if (src_length == 0)
		return ((char *)big);
	while (*big && (len >= src_length))
	{
		if (ft_memcmp(big, little, src_length) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
