/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/10 21:08:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

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

int	ft_convert_hex_ptr(int flag)
{
	int len;

	len = 0;
	if (flag)
	{
		write(1, "0x", 2);
		ft_convert_hex(flag, 0);
	}
	else
	ft_putstr_fd("(nil)", 1);
	return (len);
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
	int		len;

	len = 0;
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
		len += ft_convert_hex_len(va_arg(format, int), 0);
	else if (flag == 'X')
		len += ft_convert_hex_len(va_arg(format, int), 1);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;

	int i;
	int	len;

	va_start(args, str);
	len = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == '%')
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

int	main()
{
	int len;

	len = 0;
	len = ft_printf("%x_%X_%x", 30, 71948916, 0);

	printf("\nprintf : %x %X %x len = %d", 30, 71, 0, len);
}