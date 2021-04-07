/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:20:02 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 15:23:56 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_num(char *str, int n, int length)
{
	str[length] = '\0';
	length--;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		str[length--] = (n % 10) + '0';
		n /= 10;
	}
	str[length--] = (n % 10) + '0';
	if (length == 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		n_copy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = 1;
	n_copy = n;
	if (n_copy < 0)
	{
		length++;
		n_copy *= -1;
	}
	while (n_copy > 9)
	{
		length++;
		n_copy /= 10;
	}
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	str = set_num(str, n, length);
	return (str);
}
