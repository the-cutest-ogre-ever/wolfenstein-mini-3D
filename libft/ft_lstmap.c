/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:12:02 by ijose             #+#    #+#             */
/*   Updated: 2020/11/25 21:16:56 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *temp;

	if (!lst || !f || !del)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!(temp->next))
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (head);
}
