/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:35:21 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/14 12:15:01 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start_trim;
	int		end_trim;
	char	*trimmed;

	start_trim = -1;
	while (s1[++start_trim] && ft_strchr(set, s1[start_trim]))
		;
	s1 += start_trim;
	i = ft_strlen(s1);
	if (!i)
	{
		trimmed = malloc(1 * sizeof(char));
		if (trimmed)
			ft_strlcpy(trimmed, s1, 1);
		return (trimmed);
	}
	end_trim = 0;
	while (s1[--i] && ft_strrchr(set, s1[i]))
		end_trim++;
	trimmed = malloc((ft_strlen(s1) - end_trim + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1, ft_strlen(s1) - end_trim + 1);
	return (trimmed);
}
