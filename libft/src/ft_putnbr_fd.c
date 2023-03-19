/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:52:13 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/02 17:09:38 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putchar_putnbr(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		l = l * -1;
		ft_putchar_putnbr('-', fd);
	}
	if (l > 9)
	{
		ft_putnbr_fd((l / 10), fd);
	}
	ft_putchar_putnbr(((l % 10) + 48), fd);
}
