/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/26 21:37:31 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf.h"
#include <stdio.h>




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
		ft_putnbr_fd(va_arg(format, int))
	else if (flag == 'u')

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
	ft_printf("j'aime les %s, les %s et la %s surtout avec %d tomates %% %% ", "oeufs", "patates", "ratatouille", 81);
}