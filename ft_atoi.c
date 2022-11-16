/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:46:42 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/16 16:50:36 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long		i;
	int			x;
	char		*s;

	i = 0;
	x = 1;
	s = (char *)str;
	while (ft_isspace(*s) && *s != '-' && *s != '+')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			x *= -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		i = (i * 10) + (*s - 48);
		s++;
	}
	if (i > LLONG_MAX && x)
		return (0);
	if (i > LLONG_MAX && !x)
		return (-1);
	return (i * x);
}
