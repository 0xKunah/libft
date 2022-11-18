/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:03:27 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/18 19:22:30 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	t_list	*list;

	if (!lst || !f || !del)
		return (NULL);
	node = lst->next;
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (NULL);
	head = list;
	while (node)
	{
		list->next = ft_lstnew(f(node->content));
		if (!(list->next))
			ft_lstclear(&head, del);
		list = list->next;
		node = node->next;
	}
	return (head);
}
