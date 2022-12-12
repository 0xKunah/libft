/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	**selection_sort(void **tab, int (*cmp)(void *, void *))
{
	int		i;
	int		j;
	int		min;
	void	*tmp;

	i = 0;
	while (tab[i])
	{
		min = i;
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[j], tab[min]) < 0)
				min = j;
			j++;
		}
		tmp = tab[i];
		tab[i] = tab[min];
		tab[min] = tmp;
		i++;
	}
	return (tab);
}
