/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:27:32 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/18 17:30:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}

int update_screen(t_vars *vars)
{
	int		img_width;
	int		img_height;
	int		*image;
	int x;
	int y;
	y = 0;

	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
			{
				image = mlx_xpm_file_to_image(vars->mlx, WALLS, &img_width, &img_height);
				mlx_put_image_to_window(vars->mlx, vars->window, image, x * 50, y * 50);
			}
            if (vars->map[y][x] == 'P')
			{
				image = mlx_xpm_file_to_image(vars->mlx, PLAYER, &img_width, &img_height);
				mlx_put_image_to_window(vars->mlx, vars->window, image, x * 50, y * 50);
			}
			if (vars->map[y][x] == '0')
			{
				image = mlx_xpm_file_to_image(vars->mlx, FLOOR, &img_width, &img_height);
				mlx_put_image_to_window(vars->mlx, vars->window, image, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	moov_up(t_vars *vars)
{
	t_pos	pos;
	// int		img_width;
	// int		img_height;
	// int		*image;

	get_pos(vars->map, 'P', &pos);
	if (vars->map[pos.y - 1][pos.x] != '1')
	{
		// image = mlx_xpm_file_to_image(vars->mlx, FLOOR, &img_width, &img_height);
		// mlx_put_image_to_window(vars->mlx, vars->window, image, pos.x * 50, pos.y * 50);
		// image = mlx_xpm_file_to_image(vars->mlx, PLAYER, &img_width, &img_height);
		// mlx_put_image_to_window(vars->mlx, vars->window, image, pos.x * 50, (pos.y - 1) * 50);
		vars->map[pos.y][pos.x] = '0';
		vars->map[pos.y - 1][pos.x] = 'P';
	}
	return (0);
}

int	ft_hook_events(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	else if (keycode == W_KEY || keycode == UP)
	{
		ft_printf("UP\n");
		moov_up(vars);
		ft_printf("chr=%c", vars->map[2][2]);
		return (0);
	}
	else if (keycode == D_KEY || keycode == RIGHT)
		return (0);
	else if (keycode == S_KEY || keycode == DOWN)
		return (0);
	else if (keycode == A_KEY || keycode == LEFT)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
    t_vars	vars;
	t_data	img;
	t_map	map_param;

	if (argc < 2)
		error_manager("few", 1);
    map_param = get_map(argv[1]);

    vars.mlx = mlx_init();
	if (!vars.mlx)
		return (-1);


    size_t	x;
	size_t	y;

    x = map_param.map_width * 50;
	y = map_param.map_height * 50;
	vars.window = mlx_new_window(vars.mlx, x, y, "so_long");
	img.img = mlx_new_image(vars.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    
    int		img_width;
	int		img_height;
	int		*image;
	
	y = 0;

	while (map_param.map[y])
	{
		x = 0;
		while (map_param.map[y][x])
		{
			if (map_param.map[y][x] == '1')
			{
				image = mlx_xpm_file_to_image(vars.mlx, WALLS, &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.window, image, x * 50, y * 50);
			}
            if (map_param.map[y][x] == 'P')
			{
				image = mlx_xpm_file_to_image(vars.mlx, PLAYER, &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.window, image, x * 50, y * 50);
			}
			if (map_param.map[y][x] == '0')
			{
				image = mlx_xpm_file_to_image(vars.mlx, FLOOR, &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.window, image, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}

	// int	*hook_event;
	
	// hook_event = NULL;

	vars.map = map_param.map;
	
    mlx_key_hook(vars.window, ft_hook_events, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);

	mlx_loop_hook(vars.mlx, update_screen, &vars);
		ft_printf("chr final=%c", vars.map[2][2]);
    mlx_loop(vars.mlx);
}