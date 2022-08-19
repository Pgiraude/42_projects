/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:49:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/19 21:01:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hex_ptr(unsigned long int flag)
{
	unsigned long int	len;

	len = 0;
	if (flag)
	{
		write(1, "0x", 2);
		len = ft_convert_hex_len(flag, 0) + 2;
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		len = 5;
	}
	return (len);
}
