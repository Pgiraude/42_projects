/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:58:32 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/23 19:57:41 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int flag)
{
	size_t			neg;
	long long int	convert;

	neg = 0;
	convert = flag;
	ft_putnbr_fd(convert, 1);
	if (convert < 0)
	{
		neg++;
		convert *= -1;
	}
	return (ft_nbrconvert_len(convert, 10) + neg);
}
