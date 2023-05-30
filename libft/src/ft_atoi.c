/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:23:33 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/28 21:19:55 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long long int	get_nbr(const char *nptr)
{
	int				i;
	long long int	nb;

	i = 0;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nptr[i] - 48) + nb * 10;
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long int	nb;

	sign = 1;
	i = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	nb = get_nbr(nptr + i);
	if (nb * sign > INT_MAX || nb * sign < INT_MIN)
		return (EXIT_FAILURE);
	return (nb * sign);
}
