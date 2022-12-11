/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:35:21 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/15 15:58:13 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

static int	ft_get_start_trim(const char *s1, const char *set)
{
	int		start_trim;

	start_trim = -1;
	while (s1[++start_trim] && ft_strchr(set, s1[start_trim]))
		;
	return (start_trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		end_trim;
	char	*trimmed;

	if (!s1)
		return (NULL);
	s1 += ft_get_start_trim(s1, set);
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
	if (trimmed)
		ft_strlcpy(trimmed, s1, ft_strlen(s1) - end_trim + 1);
	return (trimmed);
}
