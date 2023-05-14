/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:13:37 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/08 17:28:52 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_lines(char **map, size_t map_height, size_t map_width)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map[x])
	{
		if (map_width != ft_strlen(map[x]))
			return (ft_free_strings(map), error_manager(NULL, 15));
		if (x == 0 || x == map_height - 1)
		{
			y = 0;
			while (map[x][y])
			{
				if (map[x][y] != '1')
					return (ft_free_strings(map), error_manager(NULL, 15));
				y++;
			}
		}
		x++;
	}
	if (map_width < 3 || x < 3 || map_width + x < 8)
		return (ft_free_strings(map), error_manager(NULL, 20));
	return (0);
}

int check_map_characters(char *line, t_map *count)
{
	int	i;

	if (line[0] != '1')
		return (free(line), error_manager(NULL, 15));
	i = 1;
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C' \
			|| line[i] == 'E' || line[i] == 'P' || line[i] == '\n'))
			return (free(line), error_manager(NULL, 12));
		if (line[i] == '\n' && line[i + 1] == '\0')
			return (free(line), error_manager(NULL, 19));
		if (line[i] == '\n' && (line[i + 1] == '\n'))
			return (free(line), error_manager(NULL, 16));
		if (line[i] == '\n' && !(line[i - 1] == '1' && line[i + 1] == '1'))
			return (free(line), error_manager(NULL, 17));
		if (line[i] == 'E')
			count->exit++;
		if (line[i] == 'P')
			count->pos++;
		if (line[i] == 'C')
			count->coin++;
		i++;
	}
	return (0);
}

int	check_number_characters(t_map *count)
{
	if (count->exit == 0)
		return (error_manager("exit", 14));
	if (count->pos == 0)
		return (error_manager("starting point", 14));
	if (count->coin == 0)
		return (error_manager("coin", 14));
	if (count->exit > 1)
		return (error_manager("exit", 13));
	if (count->pos > 1)
		return (error_manager("starting point", 13));
	return (0);
}

t_map	check_map_conformity(char *one_line_map)
{
	t_map	map_param;
	char	**map;

	if (one_line_map == NULL)
		error_manager(NULL, 11);
	map_param.exit = 0;
	map_param.pos = 0;
	map_param.coin = 0;
	check_map_characters(one_line_map, &map_param);
	check_number_characters(&map_param);
	map = ft_split(one_line_map, '\n');
	free (one_line_map);
	map_param.map_height = 0;
	while (map[map_param.map_height])
		map_param.map_height++;
	map_param.map_width = ft_strlen(map[0]);
	check_map_lines(map, map_param.map_height, map_param.map_width);
	check_map_paths(ft_dup_strings(map), &map_param);
	map_param.map = map;
	return (map_param);
}

t_map get_map(char *map_name)
{
	t_map	map_param;
	int     map_fd;
	char    *line;
	char	*one_line_map;
	char	*tmp;

	map_fd = open(map_name, O_RDONLY, 0644);
	if (map_fd < 0)
		error_manager(map_name, 10);
	line = get_next_line(map_fd);
	one_line_map = NULL;
	while (line)
	{
		tmp = one_line_map;
		one_line_map = ft_strjoin(tmp, line);
		free (tmp);
		free (line);
		line = get_next_line(map_fd);
	}
	ft_printf("%s|\n", one_line_map);
	map_param = check_map_conformity(one_line_map);
	return (map_param);
}
