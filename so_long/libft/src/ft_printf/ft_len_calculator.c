/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:04:32 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/22 20:44:18 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

size_t	ft_len_calculator(size_t nbr, size_t base)
{
	size_t	len;

	len = 1;
	while (nbr >= base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
