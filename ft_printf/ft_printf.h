/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:34:19 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/23 21:07:48 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
size_t	ft_convert_hex(unsigned int flag, int mode);
size_t	ft_convert_ptr(unsigned long int flag);
size_t	ft_nbrconvert_len(size_t nbr, size_t base);
int		ft_putnbr_printf(int flag);
size_t	ft_putstr_printf(char *str);
int		ft_uputnbr_printf(unsigned int flag);

#endif