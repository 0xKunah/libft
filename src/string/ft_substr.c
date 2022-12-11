/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:42:39 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/17 16:50:16 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		size = 0;
	if (!size)
		return (ft_strdup(""));
	if (size > len)
		size = len;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
