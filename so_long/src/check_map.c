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


int check_map_character(char *line, int map_width, t_count *count)
{
	int	len_line;
	int	i;

	i = 0;
	len_line = ft_strlen(line);
	if (!(line[0] == '1' || ft_strlen(line) + 1 == map_width))
		return (free(line), error_manager(NULL, 16));
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C' \
			|| line[i] == 'E' || line[i] == 'P' || (line[i] == '\n' && i + 1 == len_line)))
			return (free(line), error_manager(line, 12));
		else if (line[i] == 'E')
			count->exit++;
		else if (line[i] == 'P')
			count->pos++;
		else if (line[i] == 'C')
			count->coin++;
		i++;
	}
	return (0);
}

int	check_number_character(t_count *count)
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

int	first_line_check(char *line, int *map_width, int mode)
{
	int i;

	if (line == NULL)
		return (error_manager(NULL, 11));
	if (mode == 0)
		*map_width = ft_strlen(line) - 1;
	i = -1;
	while (line[++i])
	{
		if (!(line[i] == '1' || (line[i] == '\n' && i == ft_strlen(line))))
			return (free(line), error_manager(NULL, 15));
	}
	return (0);
}

int get_map(char *argv)
{
	t_count	count;
	int     map_fd;
	char    *line;
	int 	*map_width;
	int		i;

	count.exit = 0;
	count.pos = 0;
	count.coin = 0;
	map_fd = open(argv, O_RDONLY, 0644);
	if (map_fd < 0)
		return (error_manager(argv, 10));
	line = get_next_line(map_fd);
	first_line_check(line, &map_width, 0);
	i = 0;
	ft_printf("%s", line);
	while (line)
	{
		i++;
		check_map_character(line, map_width, &count);
		free(line);
		line = get_next_line(map_fd);
		ft_printf("%s", line);
	}
	check_number_character(&count);
	return (0);
}
