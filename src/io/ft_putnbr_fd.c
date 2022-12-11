/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:02:01 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/11 10:27:46 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/io.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < -2147483647)
	{
		write(fd, "-2147483648", 11);
		return ;
	}	
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(0.1 * nb, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48, fd);
}
