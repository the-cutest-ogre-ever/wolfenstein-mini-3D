/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 22:22:22 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 23:24:44 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	while (n)
	{
		--n;
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
