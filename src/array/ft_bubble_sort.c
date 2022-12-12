/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	**ft_bubble_sort(void **tab, int (*cmp)(void *, void *))
{
	int		i;
	int		j;
	void	*tmp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (cmp(tab[i], tab[j]) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
