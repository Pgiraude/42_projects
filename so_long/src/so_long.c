/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:03:01 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 20:19:31 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	my_mlx_get_screen_size(t_map map_param, t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (map_param.map_height > 27 || map_param.map_width > 51)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_free_strings(map_param.map);
		return (error_manager(NULL, 40));
	}
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
	if (argc > 2)
		error_manager("much", 1);
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
	initialize_images(&vars);
	push_map_to_window(&vars);
	mlx_key_hook(vars.window, ft_hook_events, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
}
