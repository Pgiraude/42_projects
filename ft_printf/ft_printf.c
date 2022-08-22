/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/22 21:10:04 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

size_t	ft_select_format(va_list format, char flag)
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
	size_t	len;
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


int main ()
{
	unsigned int a;
	unsigned long int b;
	unsigned long long int c;
	size_t d;

	printf("%p %p %d\n", -1, LONG_MIN, LONG_MIN);
	ft_printf("%p %p", -1, LONG_MIN);
	a = -1;
	b = -1;
	c = -1;
	d = -1;

	printf ("\n%u %u %u %u", a ,b ,c ,d);
}
