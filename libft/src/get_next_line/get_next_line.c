/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 10:51:42 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	len_buffer(char *buffer)
{
	size_t			len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\n')
		len++;
	return (len);
}

char	*rest_buffer(char *buffer)
{
	size_t		len;
	size_t		i;
	char		*save;

	len = len_buffer(buffer);
	save = malloc(sizeof(char) * (BUFFER_SIZE - len) + 1);
	if (!save)
		return (NULL);
	i = 0;
	while (buffer[(len) + i])
	{
		save[i] = buffer[(len) + i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*process_buffer(char *buffer)
{
	size_t	len;
	size_t	i;
	char	*end_line;
	char	*tmp;

	len = len_buffer(buffer);
	end_line = malloc(sizeof(char) * len + 1);
	if (!end_line)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		end_line[i] = buffer[i];
		i++;
		len--;
	}
	end_line[i] = '\0';
	tmp = rest_buffer(buffer);
	ft_strlcpy_gnl(buffer, tmp, (BUFFER_SIZE - len));
	free (tmp);
	return (end_line);
}

char	*create_line(int fd, char *buffer, char *line)
{
	ssize_t		size;
	char		*end_line;

	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0 || (size == 0 && ft_strlen(line) == 0))
			return (free (line), NULL);
		buffer[size] = '\0';
		if (ft_strchr_gnl(buffer, '\n'))
		{
			end_line = process_buffer(buffer);
			line = ft_strjoin_gnl(line, end_line);
			free (end_line);
			return (line);
		}
		else
			line = ft_strjoin_gnl(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buffer[0] != '\0')
	{
		tmp = process_buffer(buffer);
		line = ft_strjoin_gnl(line, tmp);
		free (tmp);
		if (ft_strchr_gnl(line, '\n'))
			return (line);
	}
	return (create_line(fd, buffer, line));
}
