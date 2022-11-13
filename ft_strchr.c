/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:54:09 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/11 10:27:53 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (str[++i] && str[i] != c)
		;
	if (i == (size_t)ft_strlen(s) && c != 0)
		return (NULL);
	return (str + i);
}
