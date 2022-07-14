/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/14 20:28:55 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int	i;
	char	*value;

	i = 0;
	while(format[i])
	{
		value = va_arg(args,char*);
		ft_putstr(value);
		ft_putchar('\n');
		i++;
	}
	
	va_end(args);
}

int	main()
{
	ft_printf("salut", "yes papa", "boloss", "stop");
}