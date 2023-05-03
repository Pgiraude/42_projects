/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:41:39 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/10 09:47:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	len_line(char *buffer)
{
	size_t			len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\n')
		len++;
	return (len);
}

char	*rest_line(char *line)
{
	size_t		i;
	char		*save;

	if (ft_strlen(line) == 0)
		return (NULL);
	save = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!save)
		return (NULL);
	i = 0;
	while (line[i])
	{
		save[i] = line[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*get_line(char *line, char **save)
{
	size_t	len;
	size_t	i;
	char	*new_line;

	len = len_line(line);
	new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		new_line[i] = line[i];
		i++;
		len--;
	}
	new_line[i] = '\0';
	if (len != ft_strlen(line))
		*save = rest_line(line + i);
	else
		*save = NULL;
	return (free (line), new_line);
}

char	*generate_line(int fd, char *line, int *found_nl)
{
	ssize_t		size;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0 || (size == 0 && line == NULL))
			return (free(buffer), NULL);
		buffer[size] = '\0';
		if (line == NULL)
			line = ft_strdup(buffer);
		else if (buffer[0] != '\0')
			line = ft_strjoin_gnl(line, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
		{
			*found_nl = 1;
			break ;
		}
	}
	return (free(buffer), line);
}

char	*get_next_line_multi(int fd)
{
	char			*line;
	static char		*tab_save[FOPEN_MAX];
	int				found_nl;

	found_nl = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	if (tab_save[fd] != NULL)
	{
		line = ft_strdup(tab_save[fd]);
		free (tab_save[fd]);
		tab_save[fd] = NULL;
		line = get_line(line, &tab_save[fd]);
		if (ft_strchr_gnl(line, '\n'))
			return (line);
	}
	line = generate_line(fd, line, &found_nl);
	if (found_nl == 1)
		line = get_line(line, &tab_save[fd]);
	return (line);
}
