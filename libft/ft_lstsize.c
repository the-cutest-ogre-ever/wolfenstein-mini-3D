/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:09:13 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 13:16:53 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*temp;

	length = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	return (length);
}
