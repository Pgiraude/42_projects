/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:41:03 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/27 21:27:58 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
