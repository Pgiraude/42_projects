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



typedef struct s_img
{
	void	*img_0;
	void	*img_1;
	void	*img_P;
	void	*img_E;
	void	*img_C;
}t_img;

int	find_image(t_img *img, t_vars vars)
{
	int		img_width;
	int		img_height;

	img->img_0 = mlx_xpm_file_to_image(vars.mlx, "./images/Dirt_06-50x50-clean.xpm", &img_width, &img_height);
	if (!img->img_0)
		return (1);
	img->img_1 = mlx_xpm_file_to_image(vars.mlx, "./images/brick-50-50.xpm", &img_width, &img_height);
	if (!img->img_1)
		return (1);
	img->img_P = mlx_xpm_file_to_image(vars.mlx, "./images/chevalier.xpm", &img_width, &img_height);
	if (!img->img_P)
		return (1);
	img->img_E = mlx_xpm_file_to_image(vars.mlx, "./images/door.xpm", &img_width, &img_height);
	if (!img->img_E)
		return (1);
	img->img_C = mlx_xpm_file_to_image(vars.mlx, "./images/crystal_01d.xpm", &img_width, &img_height);
	if (!img->img_C)
		return (1);
	return (0);
}

void	put_image(t_vars vars, t_img *img, t_pos pos, char index_map)
{
	if (index_map == '0')
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img->img_0, pos.x * 50, pos.y * 50);
	if (index_map == '1')
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img->img_1, pos.x * 50, pos.y * 50);
	if (index_map == 'P')
	{
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img->img_0, pos.x * 50, pos.y * 50);
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img->img_P, pos.x * 50, pos.y * 50);
	}
	if (index_map == 'E')
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img->img_E, pos.x * 50, pos.y * 50);
	if (index_map == 'C')
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img->img_C, pos.x * 50, pos.y * 50);
}

void	put_image_to_window(t_map map_param, t_vars vars)
{
	t_img	img;
	t_pos	pos;
	
	img.img_0 = 0;
	img.img_1 = 0;
	img.img_P = 0;
	img.img_E = 0;
	img.img_C = 0;

	pos.y = 0;
	find_image(&img, vars);
	ft_printf("img=%d\n", img.img_1);
	while (map_param.map[pos.y])
	{
		pos.x = 0;
		while (map_param.map[pos.y][pos.x])
		{
			put_image(vars, &img, pos, map_param.map[pos.y][pos.x]);
			pos.x++;
		}
		pos.y++;
	}
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
	
	put_image_to_window(map_param, vars);
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

	// mlx_hook(vars.mlx_win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
}

