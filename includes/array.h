/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:35:18 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/11 00:36:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stddef.h>

size_t	ft_array_len(void **tab);
void	**ft_bubble_sort(void **tab, int (*cmp)(void *, void *));
void	**ft_bucket_sort(void **tab, int size, int (*f)(void *));
void	**ft_insertion_sort(void **tab, int (*cmp)(void *, void *));
void	**ft_merge_sort(void **tab, int (*cmp)(void *, void *));
void	**ft_quick_sort(void **tab, int (*cmp)(void *, void *), int size);
void	**ft_selection_sort(void **tab, int (*cmp)(void *, void *));

#endif
