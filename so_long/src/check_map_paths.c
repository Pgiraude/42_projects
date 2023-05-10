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

int	check_all_paths(char **map, t_pos *current, t_count *count, t_list *track_path);

int	up(char **map, t_pos *current, t_list *track_path)
{
	if (map[current->y - 1][current->x] == '1')
		return (-1);
	current->y--;
	track_path = ft_add_cell_list(track_path, "U", 0);
	return (0);
}

int	right(char **map, t_pos *current, t_list *track_path)
{
	if (map[current->y][current->x + 1] == '1')
		return (-1);
	current->x++;
	track_path = ft_add_cell_list(track_path, "R", 0);
	return (0);
}

int	down(char **map, t_pos *current, t_list *track_path)
{
	if (map[current->y + 1][current->x] == '1')
		return (-1);
	current->y++;
	track_path = ft_add_cell_list(track_path, "D", 0);
	return (0);
}

int	left(char **map, t_pos *current, t_list *track_path)
{
	if (map[current->y + 1][current->x - 1] == '1')
		return (-1);
	current->x--;
	track_path = ft_add_cell_list(track_path, "L", 0);
	return (0);
}

int	back_track(char **map, t_pos *current, t_count *count, t_list *track_path)
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
	ft_printf("back track test1\n");
	moove = "R";
	if (track_path->data == moove)
		current->x--;
	ft_printf("back track test2\n");
	moove = "D";
	if (track_path->data == moove)
		current->y--;
	ft_printf("back track test3\n");
	moove = "L";
	if (track_path->data == moove)
		current->x++;
	ft_printf("back track test4\n");
	track_path = ft_suppr_cell_list(track_path, &data, 0);
	ft_printf("back track test5\n");
	if (track_path != NULL)
	{
		ft_printf("back track test6\n");
		return (check_all_paths(map, current, count, track_path));
	}
	return (0);
}

int	check_all_paths(char **map, t_pos *current, t_count *count, t_list *track_path)
{
	int	x = 0;
	while (map[x])
	{
		ft_printf("%s check path\n", map[x]);
		x++;
	}
	ft_printf("count pos=%d cur y=%d cur x=%d\n", count->pos, current->y, current->x);

	if (map[current->y][current->x] == 'P')
		count->pos--;
	if (map[current->y][current->x] == 'E')
		count->exit--;
	if (map[current->y][current->x] == 'C')
		count->coin--;
	map[current->y][current->x] = '1';

	
	if (count->coin == 0 && count->pos == 0 && count->exit == 0)
		return (0);
		
	if (up(map, current, track_path) != -1)
		return (check_all_paths(map, current, count, track_path));
	else if (right(map, current, track_path) != -1)
		return (check_all_paths(map, current, count, track_path));
	else if (down(map, current, track_path) != -1)
		return (check_all_paths(map, current, count, track_path));
	else if (left(map, current, track_path) != -1)
		return (check_all_paths(map, current, count, track_path));
	back_track(map, current, count, track_path);
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

int	check_map_paths(char **map, t_count *count)
{
	t_pos	current;
	t_list	*track_path;

	current.x = 0;
	current.y = 0;
	get_pos(map, 'P', &current);
	ft_printf("cur y=%d cur x=%d OUT\n", current.y, current.x);
	
	track_path = NULL;
	track_path = ft_add_cell_list(track_path, NULL, 0);
	if (!track_path)
		return (error_manager(NULL, 30));
	if (check_all_paths(map, &current, count, track_path) == -1)
		return (error_manager(NULL, 31));
	
	int	x = 0;
	while (map[x])
	{
		ft_printf("%s check path\n", map[x]);
		x++;
	}
	
	return (0);
}
