/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:20:59 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/24 18:35:02 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_conformity_errors(char *msg, int key_error)
{
	if (key_error == 10)
	{
		ft_printf(": '%s' ", msg);
		perror(NULL);
	}
	else if (key_error == 11)
		ft_printf(": Map is empty\n");
	else if (key_error == 12)
		ft_printf(": Invalide character in map\n");
	else if (key_error == 13)
		ft_printf(": Too much %s in the map, only one is needed\n", msg);
	else if (key_error == 14)
		ft_printf(": Need at least one %s\n", msg);
	else if (key_error == 15 || key_error == 16
		|| key_error == 17 || key_error == 18)
		ft_printf(": Map incorrect design, \
			need a rectangle surrounded by walls\n");
	else if (key_error == 19)
		ft_printf(": Map incorrect design, should not end with '\\n'\n");
	else if (key_error == 20)
		ft_printf(": Map is too small\n");
	else if (key_error == 21)
		ft_printf(": Map file need to end with '%s' extension\n", msg);
	return (0);
}

int	error_manager(char *msg, int key_error)
{
	if (key_error >= 0)
		ft_printf("Error\nError code %d", key_error);
	if (key_error == -1)
		exit(EXIT_FAILURE);
	else if (key_error == 1)
		ft_printf(": Too %s arguments\n", msg);
	else if (key_error >= 10 && key_error <= 29)
		map_conformity_errors(msg, key_error);
	else if (key_error == 30)
		ft_printf(": Malloc failed\n");
	else if (key_error == 31)
		ft_printf(": Map incorrect path\n");
	else if (key_error == 40)
		ft_printf(": Map is too big\n");
	else if (key_error == 50)
		ft_printf(": mlx_init didn't work\n");
	else if (key_error == 60)
		ft_printf(": Couldn't found images path\n");
	else if (key_error == 61)
		ft_printf(": Images extension invalid, need '.xpm'\n");
	if (key_error >= 60)
		return (-1);
	exit(EXIT_FAILURE);
	return (0);
}
