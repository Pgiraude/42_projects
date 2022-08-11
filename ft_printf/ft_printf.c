/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/11 20:51:53 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_convert_hex_ptr(int flag)
{
	int len;

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

int ft_declen(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void ft_putnbr_u(unsigned int n)
{
	long unsigned int	l;

	l = n;
	if (l > 9)
	{
		ft_putnbr_u(l / 10);
	}
	ft_putchar_fd(((l % 10) + 48), 1);
}

int	ft_uputnbr_printf(unsigned int flag)
{
	int	len;

	len = ft_declen(flag);
	ft_putnbr_u(flag);
	return (len);
}

int	ft_putnbr_printf(int flag)
{
	int	len;

	len = ft_declen(flag);
	ft_putnbr_fd(flag, 1);
	return (len);
}

int ft_putstr_printf(char *str)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}


int	ft_select_format(va_list format, char flag)
{
	int		len;

	len = 0;
	if (flag == 'c')
	{
		ft_putchar_fd(va_arg(format, int), 1);
		len += 1;
	}
	else if (flag == 's')
		len += ft_putstr_printf(va_arg(format, char*));
	else if (flag == 'p')
		len += ft_convert_hex_ptr(va_arg(format, int));
	else if (flag == 'd')
		len += ft_putnbr_printf(va_arg(format, int));
	else if (flag == 'i')
		len += ft_putnbr_printf(va_arg(format, int));
	else if (flag == 'u')
		len += ft_uputnbr_printf(va_arg(format, int));
	else if (flag == 'x')
		len += ft_convert_hex_len(va_arg(format, int), 0);
	else if (flag == 'X')
		len += ft_convert_hex_len(va_arg(format, int), 1);
	else if (flag == '%')
	{
		ft_putchar_fd('%', 1);
		len += 1;
	}
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
	len = ft_printf("%%c");

	printf("\nprintf : %%c len = %d", len);
}