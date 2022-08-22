/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:49:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/22 20:36:18 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_hex_ptr(size_t flag)
{
	size_t	len;

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
