/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/27 20:59:16 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf.h"
#include <stdio.h>


void	ft_convert_hex(int flag)
{
	char	*base;

	base = "0123456789abcdef";
	if (flag > 15)
	{
		ft_convert_hex(flag / 16);
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

	if (flag == '%')
		ft_putchar_fd('%', 1);
	else if (flag == 'd')
		ft_putnbr_fd(va_arg(format, int), 1);
	else if (flag == 's')
		ft_putstr_fd(va_arg(format, char*), 1);
	else if (flag == 'i')
		ft_putnbr_fd(va_arg(format, int), 1);
	else if (flag == 'u')
		ft_putnbr_u(va_arg(format, int));
	else if(flag == 'c')
		ft_putchar_fd(va_arg(format, int), 1);
	else if (flag == 'x')
	{
		ft_convert_hex(va_arg(format, int));
	}

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
	ft_printf("j'aime les %s, les %s et la %s surtout avec %d tomates %% %% la on est %u %i %c %x", "oeufs", "patates", "ratatouille", 81, -1, 10, 'b', 18);
	printf("\n%u %i %c %X", -1, 10, 'b', 18);
}