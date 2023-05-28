/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:46:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 19:48:52 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_images	setup_images(t_vars *vars)
{
	t_images	images;

	images.img_0 = 0;
	images.img_1 = 0;
	images.img_p = 0;
	images.img_e = 0;
	images.img_c = 0;
	images.img_x = 0;
	if (check_file_extension(FLOOR, ".xpm") != 0
		|| check_file_extension(WALLS, ".xpm") != 0
		|| check_file_extension(PLAYER, ".xpm") != 0
		|| check_file_extension(DOOR, ".xpm") != 0
		|| check_file_extension(COINS, ".xpm") != 0
		|| check_file_extension(DOORCL, ".xpm") != 0)
	{
		error_manager(NULL, 61);
		vars->images = images;
		close_window(vars, EXIT_FAILURE);
	}
	return (images);
}

int	initialize_images(t_vars *vars)
{
	int		img_width;
	int		img_height;

	vars->images = setup_images(vars);
	vars->images.img_0 = mlx_xpm_file_to_image(vars->mlx, FLOOR, \
		&img_width, &img_height);
	vars->images.img_1 = mlx_xpm_file_to_image(vars->mlx, WALLS, \
		&img_width, &img_height);
	vars->images.img_p = mlx_xpm_file_to_image(vars->mlx, PLAYER, \
		&img_width, &img_height);
	vars->images.img_e = mlx_xpm_file_to_image(vars->mlx, DOOR, \
		&img_width, &img_height);
	vars->images.img_c = mlx_xpm_file_to_image(vars->mlx, COINS, \
		&img_width, &img_height);
	vars->images.img_x = mlx_xpm_file_to_image(vars->mlx, DOORCL, \
		&img_width, &img_height);
	if (!vars->images.img_0 || !vars->images.img_1 || !vars->images.img_p
		|| !vars->images.img_e || !vars->images.img_c)
	{
		error_manager(NULL, 60);
		close_window(vars, EXIT_FAILURE);
	}
	return (0);
}

void	push_image_to_window(t_vars *vars, t_pos pos, char index_map)
{
	if (index_map == '0')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_0, \
			pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == '1')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_1, \
			pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_p, \
			pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_e, \
			pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_c, \
			pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'X')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_x, \
			pos.x * BLOCK, pos.y * BLOCK);
}

int	push_map_to_window(t_vars *vars)
{
	t_pos	pos;
	char	*nbr_moves;

	pos.y = 0;
	while (vars->map[pos.y])
	{
		pos.x = 0;
		while (vars->map[pos.y][pos.x])
		{
			push_image_to_window(vars, pos, vars->map[pos.y][pos.x]);
			pos.x++;
		}
		pos.y++;
	}
	nbr_moves = ft_itoa(vars->nbr_moves);
	mlx_string_put(vars->mlx, vars->window, 32, 32, 0xFFFFFF, "moves: ");
	mlx_string_put(vars->mlx, vars->window, 75, 32, 0xFFFFFF, nbr_moves);
	free (nbr_moves);
	return (0);
}
