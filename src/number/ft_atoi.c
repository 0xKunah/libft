/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:46:42 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/17 15:12:56 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

int	ft_atoi(const char *str)
{
	long		i;
	int			sign;
	char		*s;

	i = 0;
	sign = 1;
	s = (char *)str;
	while (ft_isspace(*s) && *s != '-' && *s != '+')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		i = (i * 10) + (*s - 48);
		s++;
	}
	return ((int)i * sign);
}
