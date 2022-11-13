/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:35:21 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/11 17:15:52 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		start_trim;
	char	*trimmed;

	i = -1;
	len = ft_strlen(s1);
	start_trim = 0;
	while (s1[++i] && ft_strchr(set, s1[i]))
	{
		len--;
		start_trim++;
	}
	i = ft_strlen(s1);
	while (s1[--i] && ft_strchr(set, s1[i]))
		len--;
	if (start_trim == ft_strlen(s1))
		return ("");
	trimmed = ft_calloc(len + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed = ft_memcpy(trimmed, s1 + start_trim, (size_t)len);
	return (trimmed);
}
