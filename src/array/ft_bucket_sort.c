/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	**ft_bucket_sort(void **tab, int size, int (*f)(void *))
{
	int		i;
	int		j;
	int		k;
	int		*bucket;
	void	**ret;

	i = 0;
	j = 0;
	k = -1;
	bucket = (int *)malloc(sizeof(int) * size);
	ret = (void **)malloc(sizeof(void *) * size);
	while (i < size)
		bucket[i++] = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			if (f(tab[i]) > f(tab[j++]))
				bucket[i]++;
		i++;
	}
	while (++k < size)
		ret[bucket[k]] = tab[k];
	return (ret);
}
