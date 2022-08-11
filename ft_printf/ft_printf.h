/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:34:19 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/11 19:50:19 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#   define PRINTF_H

#include "libft/libft.h"

int ft_printf(const char *, ...);
int	ft_convert_hex_len(int flag, int mode);

#endif