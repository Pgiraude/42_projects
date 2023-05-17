/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:27:32 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/17 16:43:24 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (0);
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
	vars.mlx_win = mlx_new_window(vars.mlx, x, y, "so_long");
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
				image = mlx_xpm_file_to_image(vars.mlx, "./pictures/brick-50-50.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, image, x * 50, y * 50);
			}
            if (map_param.map[y][x] == 'P')
			{
				image = mlx_xpm_file_to_image(vars.mlx, "./pictures/chevalier.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, image, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
    mlx_loop_hook(vars.mlx_win, KeyPress, )
    mlx_hook(vars.mlx_win, 2, 1L<<0, close_window, &vars);

    mlx_loop(vars.mlx);
}