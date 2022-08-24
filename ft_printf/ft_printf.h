/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:34:19 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/24 20:11:46 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
size_t	ft_convert_hex(unsigned int value, int mode);
size_t	ft_convert_ptr(unsigned long int value);
size_t	ft_len_calculator(size_t nbr, size_t base);
size_t	ft_convert_dec(int value);
size_t	ft_convert_str(char *str);
size_t	ft_convert_udec(unsigned int value);

#endif