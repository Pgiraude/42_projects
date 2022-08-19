/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:34:19 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/19 21:34:51 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_convert_hex_len(unsigned long int flag, int mode);
int	ft_convert_hex_ptr(unsigned long int flag);
int	ft_nbrconvert_len(long int nbr, int base);
int	ft_putnbr_printf(int flag);
int	ft_putstr_printf(char *str);
int	ft_uputnbr_printf(unsigned int flag);

#endif