/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/09 21:01:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_convert_hex_ptr(int flag)
{
	if (flag)
	{
		write(1, "0x", 2);
		ft_convert_hex(flag, 0);
	}
	else
	ft_putchar_fd("(nil)", 1);
}

void	ft_convert_hex(int flag, int mode)
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


void	ft_putchar_putnbr_u(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_u(unsigned int flag)
{
	if (flag > 9)
	{
		ft_putnbr_u(flag / 10);
	}
	ft_putchar_putnbr_u(((flag % 10) + 48));
}


int	ft_select_format(va_list format, char flag)
{
	char *temp;

	if (flag == 'c')
		ft_putchar_fd(va_arg(format, int), 1);
	else if (flag == 's')
		ft_putstr_fd(va_arg(format, char*), 1);
	else if (flag == 'p')
		ft_convert_hex_ptr(va_arg(format, int));
	else if (flag == 'd')
		ft_putnbr_fd(va_arg(format, int), 1);
	else if (flag == 'i')
		ft_putnbr_fd(va_arg(format, int), 1);
	else if (flag == 'u')
		ft_putnbr_u(va_arg(format, int));
	else if (flag == 'x')
		ft_convert_hex(va_arg(format, int), 0);
	else if (flag == 'X')
		ft_convert_hex(va_arg(format, int), 1);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;

	int i;
	va_start(args, str);

	i= 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
			ft_select_format(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	
	va_end(args);
}

int	main()
{
	ft_printf("%u %i %c %x %X %p", 0, 10, 'b', 30, 30, 71);
	printf("\nprintf : %u %i %c %x %X %p", 0, 10, 'b', 30, 30, 71);
}