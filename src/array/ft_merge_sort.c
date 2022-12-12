/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/array.h"
#include <stdlib.h>

void	**ft_merge_sort(void **tab, int (*cmp)(void *, void *))
{
	int		i;
	int		j;
	int		k;
	void	**tmp;

	i = 0;
	j = 0;
	k = 0;
	tmp = (void **)malloc(sizeof(void *) * (ft_array_len(tab) + 1));
	while (tab[i] && tab[j])
	{
		if (cmp(tab[i], tab[j]) < 0)
			tmp[k++] = tab[i++];
		else
			tmp[k++] = tab[j++];
	}
	while (tab[i])
		tmp[k++] = tab[i++];
	while (tab[j])
		tmp[k++] = tab[j++];
	tmp[k] = NULL;
	return (tmp);
}
