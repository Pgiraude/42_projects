/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:58:32 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/23 19:57:41 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

size_t	ft_convert_dec(int value)
{
	size_t			neg;
	long long int	convert;

	neg = 0;
	convert = value;
	ft_putnbr_fd(convert, 1);
	if (convert < 0)
	{
		neg++;
		convert *= -1;
	}
	return (ft_len_calculator(convert, 10) + neg);
}
