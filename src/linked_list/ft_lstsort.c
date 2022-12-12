/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/linked_list.h"

t_list	*ft_lstsort(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (cmp(tmp, tmp2) > 0)
			{
				tmp3 = tmp2->next;
				tmp2->next = tmp;
				tmp->next = tmp3;
				tmp = tmp2;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (lst);
}
