/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/19 20:50:33 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_select_format(va_list format, char flag)
{
	if (flag == 'c')
	{
		ft_putchar_fd(va_arg(format, int), 1);
		return (1);
	}
	else if (flag == 's')
		return (ft_putstr_printf(va_arg(format, char *)));
	else if (flag == 'p')
		return (ft_convert_hex_ptr(va_arg(format, int)));
	else if (flag == 'd')
		return (ft_putnbr_printf(va_arg(format, int)));
	else if (flag == 'i')
		return (ft_putnbr_printf(va_arg(format, int)));
	else if (flag == 'u')
		return (ft_uputnbr_printf(va_arg(format, int)));
	else if (flag == 'x')
		return (ft_convert_hex_len(va_arg(format, int), 0));
	else if (flag == 'X')
		return (ft_convert_hex_len(va_arg(format, int), 1));
	else if (flag == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_select_format(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(args);
	return (len);
}
