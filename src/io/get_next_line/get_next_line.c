/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:43:59 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/01 14:38:08 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_concat(char *str, char buf[BUFFER_SIZE])
{
	size_t	i;
	size_t	strlen;
	size_t	buflen;
	char	*s;

	strlen = ft_strlen(str);
	buflen = ft_strlen(buf);
	s = malloc((strlen + buflen + 1) * sizeof(char));
	if (!s)
		return (ft_free(str, NULL));
	i = 0;
	while (i < strlen + buflen)
	{
		if (i < strlen)
			s[i] = str[i];
		else
			s[i] = buf[i - strlen];
		i++;
	}
	s[i] = '\0';
	return (ft_free(str, s));
}

static char	*init_and_check(int *reading, char **str, int fd)
{
	*reading = 1;
	*str = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	return ("everything's fine");
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			reading;

	if (!init_and_check(&reading, &str, fd))
		return (NULL);
	while (reading > 0)
	{
		if (ft_indexof(buf[fd], '\n') > -1)
			return (ft_truncate(buf[fd], str, ft_indexof(buf[fd], '\n')));
		if (*buf[fd])
		{
			str = ft_concat(str, buf[fd]);
			if (!str)
				return (NULL);
		}
		reading = read(fd, buf[fd], BUFFER_SIZE);
		if (reading < 0)
			buf[fd][0] = '\0';
		else
			buf[fd][reading] = '\0';
	}
	if (!reading)
		return (str);
	return (ft_free(str, NULL));
}
