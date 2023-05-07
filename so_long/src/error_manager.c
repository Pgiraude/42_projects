/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:20:59 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/05 19:46:21 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_manager(char *msg, int key_error)
{
	if (key_error != 0)
		ft_printf("Error code %d", key_error);
	if (key_error == 1)
	{
		ft_printf(": Too %s arguments\n", msg);
		exit(EXIT_FAILURE);
		return (1);
	}
	else if (key_error == 10)
	{
		ft_printf(": '%s' ", msg);
		perror(NULL);
		exit(EXIT_FAILURE);
		return (10);
	}
	else if (key_error == 11)
	{
		ft_printf(": Map is empty\n");
		exit(EXIT_FAILURE);
		return (11);
	}
	else if (key_error == 12)
	{
		ft_printf(": Invalide character in map\n");
		exit(EXIT_FAILURE);
		return (12);
	}
	else if (key_error == 13)
	{
		ft_printf(": Too much %s in the map, only one is needed\n", msg);
		exit(EXIT_FAILURE);
		return (13);
	}
	else if (key_error == 14)
	{
		ft_printf(": Need at least one %s\n", msg);
		exit(EXIT_FAILURE);
		return (14);
	}
	else if (key_error == 15 || key_error == 16)
	{
		ft_printf(": Map incorrect design, need a rectangle surrounded by walls\n");
		exit(EXIT_FAILURE);
		return (15);
	}
	return (0);
}