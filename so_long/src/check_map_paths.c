/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:25 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 19:26:14 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*moves(char **map, t_pos *current)
{
	if (map[current->y - 1][current->x] != '1')
	{
		current->y--;
		return ("U");
	}
	else if (map[current->y][current->x + 1] != '1')
	{
		current->x++;
		return ("R");
	}
	else if (map[current->y + 1][current->x] != '1')
	{
		current->y++;
		return ("D");
	}
	else if (map[current->y][current->x - 1] != '1')
	{
		current->x--;
		return ("L");
	}
	return (NULL);
}

int	back_track(char **map, t_pos *current, t_map *count, t_list **path)
{
	void	*data;
	void	*move;
	t_list	*info;

	info = *path;
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
	data = NULL;
	*path = ft_suppr_cell_list(*path, &data, 0);
	if (data == NULL)
		return (-1);
	else
		return (check_all_paths(map, current, count, path));
}

int	check_all_paths(char **map, t_pos *cur, t_map *count, t_list **path)
{
	char	*direction;

	if (map[cur->y][cur->x] == 'P')
		count->pos--;
	if (map[cur->y][cur->x] == 'E')
		count->exit--;
	if (map[cur->y][cur->x] == 'C')
		count->coin--;
	map[cur->y][cur->x] = '1';
	if (count->coin == 0 && count->pos == 0 && count->exit == 0)
		return (0);
	direction = moves(map, cur);
	if (direction != NULL)
	{
		*path = ft_add_cell_list(*path, direction, 0);
		return (check_all_paths(map, cur, count, path));
	}
	if (back_track(map, cur, count, path) == 0)
		return (0);
	return (-1);
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
		return (ft_free_strings(map), error_manager(NULL, 70));
	if (check_all_paths(map, &current, count, &path) == -1)
		return (ft_free_strings(map), error_manager(NULL, 71));
	while (path)
	{
		tmp = path;
		path = path->next;
		free (tmp);
	}
	ft_free_strings(map);
	return (0);
}
