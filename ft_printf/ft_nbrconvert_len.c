/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrconvert_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:04:32 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/19 21:11:18 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrconvert_len(long int nbr, int base)
{
	unsigned long int	len;

	len = 1;
	while (nbr >= base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
