/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:31:18 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/24 18:47:06 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_vars *vars, int status)
{
	mlx_loop_end(vars->mlx);
	if (vars->images.img_0)
		mlx_destroy_image(vars->mlx, vars->images.img_0);
	if (vars->images.img_1)
		mlx_destroy_image(vars->mlx, vars->images.img_1);
	if (vars->images.img_c)
		mlx_destroy_image(vars->mlx, vars->images.img_c);
	if (vars->images.img_e)
		mlx_destroy_image(vars->mlx, vars->images.img_e);
	if (vars->images.img_p)
		mlx_destroy_image(vars->mlx, vars->images.img_p);
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	ft_free_strings(vars->map);
	if (status == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (0);
}

int	player_move(t_vars *vars, t_pos cur_pos, t_pos next_pos)
{
	t_pos	coord;

	if (vars->map[next_pos.y][next_pos.x] == '1')
		return (0);
	else if (vars->map[next_pos.y][next_pos.x] == 'E')
	{
		if (get_pos(vars->map, 'C', &coord) == 0)
		{
			vars->map[cur_pos.y][cur_pos.x] = '0';
			vars->map[next_pos.y][next_pos.x] = 'X';
		}
		else
		{
			ft_printf("You won with %d moves!\n", vars->nbr_moves + 1);
			close_window(vars, EXIT_SUCCESS);
		}
	}
	else if (vars->map[cur_pos.y][cur_pos.x] == 'X')
	{
		vars->map[cur_pos.y][cur_pos.x] = 'E';
		vars->map[next_pos.y][next_pos.x] = 'P';
	}
	else
	{
		vars->map[cur_pos.y][cur_pos.x] = '0';
		vars->map[next_pos.y][next_pos.x] = 'P';
	}
	return (1);
}

int	ft_hook_events(int keycode, t_vars *vars)
{
	t_pos	current_pos;
	t_pos	next_pos;

	if (keycode == 65307)
		close_window(vars, EXIT_SUCCESS);
	if (get_pos(vars->map, 'P', &current_pos) == 0)
		;
	else
		get_pos(vars->map, 'X', &current_pos);
	next_pos = current_pos;
	if (keycode == W_KEY || keycode == UP)
		next_pos.y--;
	else if (keycode == D_KEY || keycode == RIGHT)
		next_pos.x++;
	else if (keycode == S_KEY || keycode == DOWN)
		next_pos.y++;
	else if (keycode == A_KEY || keycode == LEFT)
		next_pos.x--;
	vars->nbr_moves += player_move(vars, current_pos, next_pos);
	push_map_to_window(vars);
	return (1);
}

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