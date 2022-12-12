/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:59:22 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/01 14:39:05 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_ret(char *to_free, char *retval)
{
	if (to_free)
		free(to_free);
	return (retval);
}

ssize_t	ft_indexof(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	if (i == ft_strlen(s))
		return (-1);
	return (i);
}

static char	*initializer(size_t *i, char **copy, size_t c_idx, char *str)
{
	*i = 0;
	*copy = malloc((ft_strlen(str) + c_idx + 2) * sizeof(char));
	if (!*copy)
		return (NULL);
	return ("everything's fine");
}

char	*ft_truncate(char buf[BUFFER_SIZE], char *str, size_t c_idx)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*copy;

	if (!initializer(&i, &copy, c_idx, str))
		return (ft_free_ret(str, NULL));
	while (str && str[i])
	{
		copy[i] = str[i];
		i++;
	}
	k = 0;
	j = 0;
	while (buf[k])
	{
		if (k <= c_idx)
			copy[i++] = buf[k];
		else
			buf[j++] = buf[k];
		k++;
	}
	buf[j] = '\0';
	copy[i] = '\0';
	return (ft_free_ret(str, copy));
}
