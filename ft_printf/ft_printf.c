/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/21 21:18:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf.h"



int	ft_len(long long int n)
{
	int	len;

	len = 0;
	if (n < 10)
	{
		len = 1;
	}
	else
	{
		len = 1;
		while (n >= 10)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_convert(long long int n, int sign)
{
	char	*str;
	int		len;

	len = ft_len(n) + sign;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	if (sign > 0)
	{
		str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				sign;
	char			*str;
	long long int	p;

	p = n;
	sign = 0;
	if (p < 0)
	{
		sign = 1;
		p = p * -1;
	}
	str = ft_convert(p, sign);
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	ft_select_format(va_list format, char x)
{
	if (x == '%')
		ft_putchar_fd('%', 1);
	else if (x == 's')
		ft_putstr(va_arg(format, char*));
	else if (x == 'd')
		ft_putstr(ft_itoa(va_arg(format, int)));

}

int	ft_printf(const char *format, ...)
{
	va_list args;

	int i;
	va_start(args, format);

	i= 0;
	while(format[i])
	{
		if(format[i] == '%')
		{
			ft_select_format(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	
	va_end(args);
}

int	main()
{
	ft_printf("j'aime les %s, les %s et la %s surtout avc %d tomates %% %% ", "oeufs", "patates", "ratatouille", 8);
}