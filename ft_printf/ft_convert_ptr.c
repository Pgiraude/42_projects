/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:49:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/23 21:10:16 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal_ptr(unsigned int flag)
{
	char	*base;

	base = "0123456789abcdef";
	if (flag > 15)
	{
		ft_hexadecimal_ptr((flag / 16));
	}
	ft_putchar_fd(base[flag % 16], 1);
}

size_t	ft_convert_ptr(unsigned long int flag)
{
	size_t	len;

	len = 0;
	if (flag)
	{
		write(1, "0x", 2);
		len = ft_nbrconvert_len(flag, 16) + 2;
		ft_hexadecimal_ptr(flag);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		len = 5;
	}
	return (len);
}
