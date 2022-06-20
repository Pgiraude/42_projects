/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:52:13 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/20 21:54:15 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int fd)
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
		ft_putchar('-', fd);
	}
	if (l > 9)
	{
		ft_putnbr_fd((l / 10), fd);
	}
	ft_putchar(((l % 10) + 48), fd);
}
