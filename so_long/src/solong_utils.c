/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:02:04 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 16:03:15 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_file_extension(char *file_name, char *extension)
{
	size_t	len_file;
	size_t	len_ext;

	len_file = ft_strlen(file_name);
	len_ext = ft_strlen(extension);
	if (len_file < len_ext)
		return (1);
	return (ft_strncmp(file_name + (len_file - len_ext), extension, len_ext));
}

int	get_pos(char **map, char letter, t_pos *pos)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == letter)
			{
				pos->x = x;
				pos->y = y;
				return (0);
			}
		}
		y++;
	}
	return (1);
}
