/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:13:37 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/05 19:49:09 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_count
{
	int	exit;
	int	pos;
	int	coin;
}t_count;

typedef struct s_save
{
	int	x;
	int	y;
}t_save;

int	check_map_path(char **map, t_count *count)
{
	size_t	x;
	size_t	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'P')
				break;
		}
	}

	t_save	save;

	save.x = x;
	save.y = y;
	while (map[x][y] == '1')
	{
		
	}
	
}

int	check_map_lines(char **map, size_t map_height, size_t map_width)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map[x])
	{
		if (map_width != ft_strlen(map[x]))
			return (ft_freestrings(map), error_manager(NULL, 15));
		if (x == 0 || x == map_height - 1)
		{
			y = 0;
			while (map[x][y])
			{
				if (map[x][y] != '1')
					return (ft_freestrings(map), error_manager(NULL, 15));
				y++;
			}
		}
		x++;
	}
	if (map_width < 3 || x < 3 || map_width + x < 8)
		return (ft_freestrings(map), error_manager(NULL, 20));
	return (0);
}

int check_map_characters(char *line, t_count *count)
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

int	check_number_characters(t_count *count)
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

int	check_map(char *line, char ***map)
{
	t_count	count;
	size_t	map_height;
	size_t	map_width;

	*map = NULL;
	if (line == NULL)
		return (error_manager(NULL, 11));
	count.exit = 0;
	count.pos = 0;
	count.coin = 0;
	check_map_characters(line, &count);
	check_number_characters(&count);
	*map = ft_split(line, '\n');
	free (line);
	map_height = 0;
	ft_printf("test\n");
	while (map[map_height])
		map_height++;
	map_width = ft_strlen(*map[0]);
	check_map_lines(*map, map_height, map_width);
	return (0);
}

int get_map(char *map_name)
{
	int     map_fd;
	char    *line;
	char	*big_line;
	char	*tmp;
	char	**map;

	map_fd = open(map_name, O_RDONLY, 0644);
	if (map_fd < 0)
		return (error_manager(map_name, 10));
	line = get_next_line(map_fd);
	big_line = NULL;
	while (line)
	{
		tmp = big_line;
		big_line = ft_strjoin(tmp, line);
		free (tmp);
		free (line);
		line = get_next_line(map_fd);
	}
	ft_printf("%s|\n", big_line);
	check_map(big_line, &map);

	return (0);
}
