/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:44:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/23 20:37:52 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_hexadecimal(unsigned int value, int mode)
{
	char	*base;

	if (mode > 0)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (value > 15)
	{
		ft_hexadecimal((value / 16), mode);
	}
	ft_putchar_fd(base[value % 16], 1);
}

size_t	ft_convert_hex(unsigned int value, int mode)
{
	size_t	len;

	len = ft_len_calculator(value, 16);
	ft_hexadecimal(value, mode);
	return (len);
}
