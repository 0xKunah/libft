/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:43:20 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/13 19:43:20 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/linked_list.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		i;

	i = 0;
	node = lst;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}
