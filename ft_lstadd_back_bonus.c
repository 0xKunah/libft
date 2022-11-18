/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:50:30 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/18 19:21:12 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (lst && new)
	{
		head = *lst;
		while ((*lst) && (*lst)->next)
			(*lst) = (*lst)->next;
		if (*lst)
		{
			(*lst)->next = new;
			*lst = head;
		}
		else
			*lst = new;
	}
}
