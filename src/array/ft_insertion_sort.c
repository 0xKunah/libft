/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	**ft_insertion_sort(void **tab, int (*cmp)(void *, void *))
{
	int		i;
	int		j;
	void	*tmp;

	i = 1;
	while (tab[i])
	{
		j = i;
		while (j > 0 && cmp(tab[j - 1], tab[j]) > 0)
		{
			tmp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = tmp;
			j--;
		}
		i++;
	}
	return (tab);
}
