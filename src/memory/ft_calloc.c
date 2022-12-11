/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:52:17 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/17 16:12:34 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;

	if (size && count != (count * size) / size)
		return (NULL);
	t = malloc(count * size);
	if (!t)
		return (NULL);
	ft_bzero(t, count * size);
	return ((void *)t);
}
