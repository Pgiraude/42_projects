/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:34:19 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/22 20:50:38 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
size_t	ft_convert_hex_len(size_t flag, int mode);
size_t	ft_convert_hex_ptr(size_t flag);
size_t	ft_nbrconvert_len(size_t nbr, size_t base);
int		ft_putnbr_printf(int flag);
size_t	ft_putstr_printf(char *str);
int		ft_uputnbr_printf(unsigned int flag);

#endif