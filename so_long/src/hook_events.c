/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:31:18 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 19:33:13 by pgiraude         ###   ########.fr       */
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
	if (vars->images.img_x)
		mlx_destroy_image(vars->mlx, vars->images.img_x);
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

int	player_move_exit(t_vars *vars, t_pos cur_pos, t_pos next_pos)
{
	t_pos	coord;

	if (get_pos(vars->map, 'C', &coord) == 0)
	{
		vars->map[cur_pos.y][cur_pos.x] = '0';
		vars->map[next_pos.y][next_pos.x] = 'X';
		ft_printf("Nbr of moves=%d\n", vars->nbr_moves + 1);
	}
	else
	{
		ft_printf("You won with %d moves!\n", vars->nbr_moves + 1);
		close_window(vars, EXIT_SUCCESS);
	}
	return (0);
}

int	player_move(t_vars *vars, t_pos cur_pos, t_pos next_pos)
{
	if (vars->map[next_pos.y][next_pos.x] == '1')
		return (0);
	else if (vars->map[next_pos.y][next_pos.x] == 'E')
	{
		player_move_exit(vars, cur_pos, next_pos);
		return (1);
	}
	else if (vars->map[cur_pos.y][cur_pos.x] == 'X')
	{
		vars->map[cur_pos.y][cur_pos.x] = 'E';
		vars->map[next_pos.y][next_pos.x] = 'P';
		ft_printf("Nbr of moves=%d\n", vars->nbr_moves + 1);
		return (1);
	}
	else if (vars->map[next_pos.y][next_pos.x] == '0'
		|| vars->map[next_pos.y][next_pos.x] == 'C')
	{
		vars->map[cur_pos.y][cur_pos.x] = '0';
		vars->map[next_pos.y][next_pos.x] = 'P';
		ft_printf("Nbr of moves=%d\n", vars->nbr_moves + 1);
		return (1);
	}
	return (0);
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
