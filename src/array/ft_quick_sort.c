/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void    **ft_quick_sort(void **tab, int (*cmp)(void *, void *), int size)
{
    int     i;
    int     j;
    int     pivot;
    void    *tmp;

    i = 0;
    j = size - 1;
    pivot = size / 2;
    while (i < j)
    {
        while (cmp(tab[i], tab[pivot]) < 0)
            i++;
        while (cmp(tab[j], tab[pivot]) > 0)
            j--;
        if (i <= j)
        {
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;
            j--;
        }
    }
    if (j > 0)
        ft_quick_sort(tab, cmp, j + 1);
    if (i < size)
        ft_quick_sort(tab + i, cmp, size - i);
    return (tab);
}