/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:58:32 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/22 20:43:18 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int flag)
{
	size_t	len;
	size_t	neg;

	neg = 0;
	ft_putnbr_fd(flag, 1);
	if (flag < 0)
	{
		neg++;
		flag *= -1;
	}
	len = ft_nbrconvert_len(flag, 10) + neg;
	return (len);
}
