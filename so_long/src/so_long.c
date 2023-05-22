/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:03:01 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/18 16:05:51 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_setup *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	initialise_images(t_vars *vars)
{
	int		img_width;
	int		img_height;

	vars->images.img_0 = 0;
	vars->images.img_1 = 0;
	vars->images.img_P = 0;
	vars->images.img_E = 0;
	vars->images.img_C = 0;
	vars->images.img_0 = mlx_xpm_file_to_image(vars->mlx, FLOOR, &img_width, &img_height);
	vars->images.img_1 = mlx_xpm_file_to_image(vars->mlx, WALLS, &img_width, &img_height);
	vars->images.img_P = mlx_xpm_file_to_image(vars->mlx, PLAYER, &img_width, &img_height);
	vars->images.img_E = mlx_xpm_file_to_image(vars->mlx, DOOR, &img_width, &img_height);
	vars->images.img_C = mlx_xpm_file_to_image(vars->mlx, COINS, &img_width, &img_height);
	if (!vars->images.img_0 || !vars->images.img_1 || !vars->images.img_P || !vars->images.img_E || !vars->images.img_C)
		return (error_manager(NULL, 50));
	return (0);
}

void	push_image_to_window(t_vars *vars, t_pos pos, char index_map)
{
	if (index_map == '0')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_0, pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == '1')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_1, pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_P, pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_E, pos.x * BLOCK, pos.y * BLOCK);
	if (index_map == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.img_C, pos.x * BLOCK, pos.y * BLOCK);
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
	return (0);
}

void	my_mlx_get_screen_size(t_map map_param, t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (map_param.map_height > 20 || map_param.map_width > 20)
		error_manager(NULL, 40);
	x = map_param.map_width * BLOCK;
	y = map_param.map_height * BLOCK;
	vars->window = mlx_new_window(vars->mlx, x, y, "so_long");
	vars->set_up.img = mlx_new_image(vars->mlx, x, y);
	vars->set_up.addr = mlx_get_data_addr(vars->set_up.img, &vars->set_up.bits_per_pixel, &vars->set_up.line_length,
	&vars->set_up.endian);
}

t_vars test(t_vars *a)
{
	t_vars b;

	b.map = NULL;
	a->map = b.map;
	b.map = NULL;
	return (b);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map_param;

	if (argc < 2)
		error_manager("few", 1);

	vars.nbr_moves = -1;

	map_param = check_map_conformity(argv[1]);
	check_map_paths(ft_dup_strings(map_param.map), &map_param);
	
	
	vars.map = map_param.map;

	
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (-1);

	my_mlx_get_screen_size(map_param, &vars);

	initialise_images(&vars);

    mlx_key_hook(vars.window, ft_hook_events, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);

	mlx_loop_hook(vars.mlx, push_map_to_window, &vars);

	mlx_loop(vars.mlx);
}
