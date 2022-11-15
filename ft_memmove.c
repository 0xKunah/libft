/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:49:37 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/15 18:33:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	if (dst <= src)
	{
		i = -1;
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	return (dst);
}
