/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:04:22 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/14 12:37:07 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!len && (!needle || !haystack))
		return (NULL);
	if ((int)len < 1)
	{
		if (!needle || !needle[0])
			return ((char *)haystack);
		len = (unsigned int)len;
	}
	i = 0;
	p = (char *) haystack;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return (p + i);
		i++;
	}
	return (NULL);
}
