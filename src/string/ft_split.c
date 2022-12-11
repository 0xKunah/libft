/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:05:15 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/17 15:08:47 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

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

static char	*ft_remove_sep(const char *str, char sep)
{
	while (*str == sep)
		str++;
	return ((char *)str);
}

static char	**free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		words_count;
	char	**tab;

	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	s = ft_remove_sep(s, c);
	i = -1;
	tab = malloc((words_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (++i < words_count)
	{
		len = ft_wordlen(s, c);
		tab[i] = malloc((len + 1) * sizeof(char));
		if (!tab[i])
			return (free_tab(tab));
		ft_strlcpy(tab[i], s, len + 1);
		s = ft_remove_sep(s + len, c);
	}
	tab[i] = NULL;
	return (tab);
}
