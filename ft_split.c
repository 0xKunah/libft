/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:05:15 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/11 10:27:51 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char sep)
{
	int		i;
	int		len;
	int		words;

	i = 0;
	words = 0;
	len = ft_strlen(s);
	if (!s[0])
		return (0);
	while (++i <= len)
		if ((s[i] == sep || s[i] == '\0') && s[i - 1] != sep)
			words++;
	return (words);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**null_ended_tab(char **t, int idx)
{
	t[idx] = NULL;
	return (t);
}

static void	init(const char *s, char c, int *words, int *i)
{
	*words = ft_count_words(s, c);
	*i = -1;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		words;
	char	*str;
	char	**tab;

	init(s, c, &words, &i);
	s = ft_strtrim((char *)s, &c);
	str = (char *)s;
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!s[0])
		return (null_ended_tab(tab, 0));
	while (++i < words)
	{
		len = ft_wordlen(str, c);
		tab[i] = malloc((len + 1) * sizeof(char));
		if (!tab[i])
			return (NULL);
		ft_strlcpy(tab[i], str, len + 1);
		str = ft_strtrim(str + len + 1, &c);
	}
	free((void *)s);
	return (null_ended_tab(tab, words));
}
