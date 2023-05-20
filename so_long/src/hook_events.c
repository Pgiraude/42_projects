
#include "../include/so_long.h"


int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}

int	player_moov(t_vars *vars, t_pos cur_pos, t_pos next_pos)
{	
	if (vars->map[next_pos.y][next_pos.x] != '1')
	{
		vars->map[cur_pos.y][cur_pos.x] = '0';
		vars->map[next_pos.y][next_pos.x] = 'P';
	}
	return (0);
}

int	ft_hook_events(int keycode, t_vars *vars)
{
	t_pos   current_pos;
	t_pos   next_pos;

	if (keycode == 65307)
		close_window(vars);
	get_pos(vars->map, 'P', &current_pos);
	next_pos = current_pos;
	if (keycode == W_KEY || keycode == UP)
	{
		next_pos.y--;
		ft_printf("UP\n");
	}
	else if (keycode == D_KEY || keycode == RIGHT)
	{
		next_pos.x++;
	}
	else if (keycode == S_KEY || keycode == DOWN)
	{
		next_pos.y++;
	}
	else if (keycode == A_KEY || keycode == LEFT)
	{
		next_pos.x--;
	}
	player_moov(vars, current_pos, next_pos);
	return (1);
}