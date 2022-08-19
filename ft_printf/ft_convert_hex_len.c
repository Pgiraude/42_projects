/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:44:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/19 21:34:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_hex(unsigned long int flag, int mode)
{
	char	*base;

	if (mode > 0)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (flag > 15)
	{
		ft_convert_hex((flag / 16), mode);
	}
	ft_putchar_fd(base[flag % 16], 1);
}

int	ft_convert_hex_len(unsigned long int flag, int mode)
{
	unsigned long int	len;

	len = ft_nbrconvert_len(flag, 16);
	ft_convert_hex(flag, mode);
	return (len);
}
