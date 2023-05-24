/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:03:01 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/24 18:47:06 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	initialise_images(t_vars *vars)
{
	int		img_width;
	int		img_height;

	vars->images.img_0 = 0;
	vars->images.img_1 = 0;
	vars->images.img_p = 0;
	vars->images.img_e = 0;
	vars->images.img_c = 0;
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
	if (check_file_extension(FLOOR, ".xpm") != 0
		|| check_file_extension(WALLS, ".xpm") != 0
		|| check_file_extension(PLAYER, ".xpm") != 0
		|| check_file_extension(DOOR, ".xpm") != 0
		|| check_file_extension(COINS, ".xpm") != 0)
	{
		error_manager(NULL, 61);
		close_window(vars, EXIT_FAILURE);
	}
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

int	my_mlx_get_screen_size(t_map map_param, t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (map_param.map_height > 20 || map_param.map_width > 20)
		return (free(vars->mlx), ft_free_strings(map_param.map), \
			error_manager(NULL, 40));
	x = map_param.map_width * BLOCK;
	y = map_param.map_height * BLOCK;
	vars->window = mlx_new_window(vars->mlx, x, y, "so_long");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map_param;

	if (argc < 2)
		error_manager("few", 1);
	vars.nbr_moves = 0;
	map_param = check_map_conformity(argv[1]);
	if (check_map_paths(ft_dup_strings(map_param.map), &map_param) != 0)
		return (ft_free_strings(map_param.map), error_manager(NULL, -1));
	vars.map = map_param.map;
	vars.mlx = NULL;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (ft_free_strings(map_param.map), error_manager(NULL, 50));
	my_mlx_get_screen_size(map_param, &vars);
	initialise_images(&vars);
	push_map_to_window(&vars);
	mlx_key_hook(vars.window, ft_hook_events, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
}
