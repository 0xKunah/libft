/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itox(int n)
{
    char *hex;
    int i;
    int tmp;

    i = 0;
    tmp = n;
    while (tmp > 0)
    {
        tmp /= 16;
        i++;
    }
    hex = malloc(sizeof(char) * (i + 1));
    if (!hex)
        return (NULL);
    hex[i] = '\0';
    while (i > 0)
    {
        tmp = n % 16;
        if (tmp < 10)
            hex[i - 1] = tmp + 48;
        else
            hex[i - 1] = tmp + 87;
        n /= 16;
        i--;
    }
    return (hex);
}