/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:28:07 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 16:10:19 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return (8);
	else if (c >= 'a' && c <= 'z')
		return (8);
	else if (c >= 'A' && c <= 'Z')
		return (8);
	else
		return (0);
}
