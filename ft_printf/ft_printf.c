/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/19 21:32:28 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>




int	type_convert(va_list args, int type)
{
}


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

int	ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int	i;
	char	*value;

	int x;
	x = 0;
	i = 0;
	while(i < format)
	{
		value = va_arg(args, char*);
		ft_putstr(value);
		ft_putchar('\n');
		ft_putchar('A');
		i++;
	}
	
	va_end(args);
}

int	main()
{
	ft_printf("salut", "yes papa", "boloss", "stop");
}