/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:20:51 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/15 18:32:18 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

static char	*ft_strncat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && j < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst && !dstsize)
		return (srclen + dstsize);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	else if (dstsize <= dstlen + srclen)
	{
		ft_strncat(dst, src, dstsize - dstlen - 1);
		return (dstlen + srclen);
	}
	ft_strncat(dst, src, srclen);
	return (dstlen + srclen);
}
