/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:25 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/10 18:49:47 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

int	check_all_paths(char **map, t_pos *current, t_map *count, t_list **track_path);

int	mooves(char **map, t_pos *current, char direction)
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

int	back_track(char **map, t_pos *current, t_map *count, t_list *track_path)
{
	void	*data;
	void	*moove;

	data = track_path->data;
	moove = NULL;

	if (track_path == NULL)
		ft_printf("track_path dont work\n");
	ft_printf("1=%s\n", track_path->data);
	moove = "U";
	if (track_path->data == moove)
		current->y++;
	moove = "R";
	if (track_path->data == moove)
		current->x--;
	moove = "D";
	if (track_path->data == moove)
		current->y--;
	moove = "L";
	if (track_path->data == moove)
		current->x++;
	track_path = ft_suppr_cell_list(track_path, &data, 0);
	if (track_path != NULL)
	{
		ft_printf("back track test6\n");
		return (check_all_paths(map, current, count, &track_path));
	}
	return (-1);
}

int	check_all_paths(char **map, t_pos *current, t_map *count, t_list **track_path)
{


	if (map[current->y][current->x] == 'P')
		count->pos--;
	if (map[current->y][current->x] == 'E')
		count->exit--;
	if (map[current->y][current->x] == 'C')
		count->coin--;
	map[current->y][current->x] = '1';

/*-----------------------*/
	int	x = 0;
	while (map[x])
	{
		ft_printf("%s check path\n", map[x]);
		x++;
	}
	ft_printf("count pos=%d cur y=%d cur x=%d\n", count->pos, current->y, current->x);
/*-----------------------*/
	
	if (count->coin == 0 && count->pos == 0 && count->exit == 0)
		return (0);
	if (mooves(map, current, 'U') != -1)
	{
		*track_path = ft_add_cell_list(*track_path, "U", 0);
		return (check_all_paths(map, current, count, track_path));
	}
	else if (mooves(map, current, 'R') != -1)
	{
			*track_path = ft_add_cell_list(*track_path, "R", 0);
		return (check_all_paths(map, current, count, track_path));
	}
	else if (mooves(map, current, 'D') != -1)
	{
			*track_path = ft_add_cell_list(*track_path, "D", 0);
		return (check_all_paths(map, current, count, track_path));
	}
	else if (mooves(map, current, 'L') != -1)
	{
			*track_path = ft_add_cell_list(*track_path, "L", 0);
		return (check_all_paths(map, current, count, track_path));
	}
	if (back_track(map, current, count, *track_path) == 0)
		return (0);
	return (-1);
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

int	check_map_paths(char **map, t_map *count)
{
	t_pos	current;
	t_list	*track_path;
	t_list	*tmp;

	current.x = 0;
	current.y = 0;
	get_pos(map, 'P', &current);
	ft_printf("cur y=%d cur x=%d OUT\n", current.y, current.x);
	
	track_path = NULL;
	track_path = ft_add_cell_list(track_path, NULL, 0);
	if (!track_path)
		return (error_manager(NULL, 30));
	if (check_all_paths(map, &current, count, &track_path) == -1)
		return (error_manager(NULL, 31));
	while (track_path)
	{
		tmp = track_path;
		track_path = track_path->next;
		free (tmp);
	}

	/*----------*/
	int	x = 0;
	while (map[x])
	{
		ft_printf("%s check path\n", map[x]);
		x++;
	}
	/*----------*/
	
	ft_free_strings(map);
	
	return (0);
}
