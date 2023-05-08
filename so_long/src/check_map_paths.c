/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:25 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/08 19:29:44 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

int	down(char **map, t_pos *current)
{
	if (map[current->y + 1][current->x] == '1')
		return (-1);
	current->y++;
	return (0);
}

int	up(char **map, t_pos *current)
{
	if (map[current->y - 1][current->x] == '1')
		return (-1);
	current->y--;
	return (0);
}

int	right(char **map, t_pos *current)
{
	if (map[current->y][current->x + 1] == '1')
		return (-1);
	current->x++;
	return (0);
}

int	left(char **map, t_pos *current)
{
	if (map[current->y + 1][current->x - 1] == '1')
		return (-1);
	current->x--;
	return (0);
}

int	check_all_paths(char **map, t_pos *current, t_count *count)
{
	int	x = 0;
	while (map[x])
	{
		ft_printf("%s check path\n", map[x]);
		x++;
	}
	ft_printf("count pos=%d cur y=%d cur x=%d\n", count->pos, current->y, current->x);

	
	if (map[current->y][current->x] == 'P')
	{
		ft_printf("test1\n");
		count->pos--;
		ft_printf("test2\n");
	}
	if (map[current->y][current->x] == 'E')
		count->exit--;
	if (map[current->y][current->x] == 'C')
		count->coin--;
	ft_printf("test\n");
	map[current->y][current->x] = '1';

	
	if (count->coin == 0 && count->pos == 0 && count->exit == 0)
		return (0);
		
	if (up(map, current) != -1)
		return (check_all_paths(map, current, count));
	else if (right(map, current) != -1)
		return (check_all_paths(map, current, count));
	else if (down(map, current) != -1)
		return (check_all_paths(map, current, count));
	else if (left(map, current) != -1)
		return (check_all_paths(map, current, count));

	
	return (0);
}


int	get_pos(char **map, char letter, t_pos *pos)
{
	static int	y;
	static int	x;

	if (letter != 'C')
		y = 0;
	while (map[y])
	{
		if (!(letter == 'C' && x != 0))
			x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == letter)
			{
				pos->x = x;
				pos->y = y;
				return (0);
			}
		}
		y++;
	}
	return (1);
}

int	check_map_paths(char **map, t_count *count)
{
	t_pos	current;

	current.x = 0;
	current.y = 0;
	get_pos(map, 'P', &current);
	ft_printf("cur y=%d cur x=%d OUT\n", current.y, current.x);
	check_all_paths(map, &current, count);
	
	int	x = 0;
	while (map[x])
	{
		ft_printf("%s check path\n", map[x]);
		x++;
	}
	
	return (0);
}
