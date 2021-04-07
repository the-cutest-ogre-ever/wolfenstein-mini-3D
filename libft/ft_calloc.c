/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:21:02 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 23:22:56 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *buffer;

	buffer = (void *)malloc(nmemb * size);
	if (!buffer)
		return (0);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
}
