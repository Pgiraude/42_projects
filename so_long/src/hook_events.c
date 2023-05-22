
#include "../include/so_long.h"

int	ft_clean_mlx(t_vars *vars)
{
	// if (vars->mlx)
	

	if (vars->images.img_0)
		mlx_destroy_image(vars->mlx, vars->images.img_0);
	if (vars->images.img_1)
		mlx_destroy_image(vars->mlx, vars->images.img_1);
	if (vars->images.img_C)
		mlx_destroy_image(vars->mlx, vars->images.img_C);
	if (vars->images.img_E)
		mlx_destroy_image(vars->mlx, vars->images.img_E);
	if (vars->images.img_P)
		mlx_destroy_image(vars->mlx, vars->images.img_P);

	// if (vars->mlx && vars->window)
		
	// if (vars->mlx)
		
	return (0);
}

int close_window(t_vars *vars)
{
	// mlx_destroy_window(vars->mlx, vars->window);
	// mlx_loop_end(vars->mlx);

	ft_clean_mlx(vars);
		mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	// vars->window = 0;
	// mlx_destroy_display(vars->mlx);
	// free(vars->mlx);
	return (0);
}

int	player_move(t_vars *vars, t_pos cur_pos, t_pos next_pos)
{
	t_pos coord;

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
			ft_printf("You won whith %d moves!\n", vars->nbr_moves + 1);
			close_window(vars);
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
	t_pos   	current_pos;
	t_pos   	next_pos;


	if (keycode == 65307)
		close_window(vars);
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
	return (1);
}