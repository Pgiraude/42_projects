/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:44:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/11 19:48:20 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_hexlen(int nbr)
{
	int	len;

	len = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_convert_hex(int flag, int mode)
{
	char	*base;
	int		*len;

	len = 0;
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

int	ft_convert_hex_len(int flag, int mode)
{
	int	len;

	len = ft_hexlen(flag);
	ft_convert_hex(flag, mode);
	return (len);
}