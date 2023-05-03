/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:49:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/09/06 20:07:49 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putchar_ptr(unsigned long int c)
{
	write(1, &c, 1);
}

void	ft_hexadecimal_ptr(unsigned long int value)
{
	char	*base;

	base = "0123456789abcdef";
	if (value > 15)
	{
		ft_hexadecimal_ptr((value / 16));
	}
	ft_putchar_ptr(base[value % 16]);
}

size_t	ft_convert_ptr(unsigned long int value)
{
	size_t	len;

	len = 0;
	if (value)
	{
		write(1, "0x", 2);
		len = ft_len_calculator((unsigned long int)value, 16) + 2;
		ft_hexadecimal_ptr((unsigned long int)value);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		len = 5;
	}
	return (len);
}
