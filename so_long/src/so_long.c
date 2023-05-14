/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:03:01 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/05 17:29:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(t_vars *vars)
{
		ft_printf("test\n"); //segfault mlx_destroy
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_loop_end(vars->mlx);


	// mlx_destroy_display(vars->mlx);

	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_get_screen_size(t_map map_param, t_vars vars , t_data img)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (map_param.map_height > 20 || map_param.map_width > 20)
		error_manager(NULL, 40);
	x = map_param.map_width * 50;
	y = map_param.map_height * 50;
	vars.mlx_win = mlx_new_window(vars.mlx, x, y, "so_long");
	img.img = mlx_new_image(vars.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	t_map	map_param;

	if (argc < 2)
		error_manager("few", 1);
	// else if (argc > 2)
	// 	error_manager("much", 1);
	map_param = get_map(argv[1]);

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (-1);
	
	my_mlx_get_screen_size(map_param, vars, img);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 5, 0x00FF0000);

	my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);

	char	*path;
	int		img_width;
	int		img_height;
	int		*image;
	
	path = argv[2];
	
	image = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);

	ft_printf("image val=%d\n", image);

	mlx_put_image_to_window(vars.mlx, vars.mlx_win, image, 300, 300);


	ft_printf("image width=%d height=%d\n", img_width, img_height);
	// mlx_hook(vars.mlx_win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
}

