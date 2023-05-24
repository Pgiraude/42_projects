/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:25 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/24 18:50:02 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	moves(char **map, t_pos *current, char direction)
{
	if (direction == 'U')
	{
		if (map[current->y - 1][current->x] == '1')
			return (-1);
		current->y--;
	}
	else if (direction == 'R')
	{
		if (map[current->y][current->x + 1] == '1')
			return (-1);
		current->x++;
	}
	else if (direction == 'D')
	{
		if (map[current->y + 1][current->x] == '1')
			return (-1);
		current->y++;
	}
	else if (direction == 'L')
	{
		if (map[current->y][current->x - 1] == '1')
			return (-1);
		current->x--;
	}
	return (0);
}

int	back_track(char **map, t_pos *current, t_map *count, t_list **path)
{
	void	*data;
	void	*move;
	t_list	*info;

	info = *path;
	data = info->data;
	move = NULL;
	move = "U";
	if (info->data == move)
		current->y++;
	move = "R";
	if (info->data == move)
		current->x--;
	move = "D";
	if (info->data == move)
		current->y--;
	move = "L";
	if (info->data == move)
		current->x++;
	*path = ft_suppr_cell_list(*path, &data, 0);
	if (path != NULL)
		return (check_all_paths(map, current, count, path));
	return (-1);
}

int	check_all_paths(char **map, t_pos *cur, t_map *count, t_list **path)
{
	if (map[cur->y][cur->x] == 'P')
		count->pos--;
	if (map[cur->y][cur->x] == 'E')
		count->exit--;
	if (map[cur->y][cur->x] == 'C')
		count->coin--;
	map[cur->y][cur->x] = '1';
	if (count->coin == 0 && count->pos == 0 && count->exit == 0)
		return (0);
	if (moves(map, cur, 'U') != -1)
	{
		*path = ft_add_cell_list(*path, "U", 0);
		return (check_all_paths(map, cur, count, path));
	}
	else if (moves(map, cur, 'R') != -1)
	{
			*path = ft_add_cell_list(*path, "R", 0);
		return (check_all_paths(map, cur, count, path));
	}
	else if (moves(map, cur, 'D') != -1)
	{
			*path = ft_add_cell_list(*path, "D", 0);
		return (check_all_paths(map, cur, count, path));
	}
	else if (moves(map, cur, 'L') != -1)
	{
			*path = ft_add_cell_list(*path, "L", 0);
		return (check_all_paths(map, cur, count, path));
	}
	if (back_track(map, cur, count, path) == 0)
		return (0);
	return (-1);
}

int	get_pos(char **map, char letter, t_pos *pos)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
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

int	check_map_paths(char **map, t_map *count)
{
	t_pos	current;
	t_list	*path;
	t_list	*tmp;

	current.x = 0;
	current.y = 0;
	get_pos(map, 'P', &current);
	path = NULL;
	path = ft_add_cell_list(path, NULL, 0);
	if (!path)
		return (ft_free_strings(map), error_manager(NULL, 30));
	if (check_all_paths(map, &current, count, &path) == -1)
		return (ft_free_strings(map), error_manager(NULL, 31));
	while (path)
	{
		tmp = path;
		path = path->next;
		free (tmp);
	}
	ft_free_strings(map);
	return (0);
}
