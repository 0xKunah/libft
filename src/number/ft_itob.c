/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*ft_itob(int n, char *base)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(base);
	str = (char *)malloc(sizeof(char) * 33);
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i++] = base[n % len];
		n /= len;
	}
	str[i] = '\0';
	while (j < i / 2)
	{
		str[j] ^= str[i - j - 1];
		str[i - j - 1] ^= str[j];
		str[j] ^= str[i - j - 1];
		j++;
	}
	return (str);
}
