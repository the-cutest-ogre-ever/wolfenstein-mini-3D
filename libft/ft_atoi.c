/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:20:02 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 23:23:56 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	while ((*nptr == ' ') || (*nptr == '\n') || (*nptr == '\v') || (*nptr ==
	'\t') || (*nptr == '\f') || (*nptr == '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}
