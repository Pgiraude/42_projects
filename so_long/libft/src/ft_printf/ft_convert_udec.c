/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_udec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:01:34 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/23 19:16:46 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	long unsigned int	l;

	l = n;
	if (l > 9)
	{
		ft_putnbr_u(l / 10);
	}
	ft_putchar_fd(((l % 10) + 48), 1);
}

size_t	ft_convert_udec(unsigned int value)
{
	size_t	len;

	len = ft_len_calculator(value, 10);
	ft_putnbr_u(value);
	return (len);
}
