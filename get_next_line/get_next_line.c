/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:41:39 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/07 11:42:55 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*rest_line(char *line)
{
	size_t		len;
	size_t		i;
	char		*save;

	len = len_buffer(line);
	if (len == ft_strlen(line))
		return (NULL);
	save = malloc(sizeof(char) * (ft_strlen(line + len) + 1));
	if (!save)
		return (NULL);
	i = 0;
	while (line[len + i])
	{
		save[i] = line[len + i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*get_line(char *line)
{
	size_t	len;
	size_t	i;
	char	*new_line;

	len = len_buffer(line);
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
	return (free (line), new_line);
}

char	*create_line(int fd, char *line, int *found_nl)
{
	int		size;
	char	*buffer;

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
			line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			*found_nl = 1;
			break ;
		}
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*save;
	int				found_nl;

	found_nl = 0;
	if (fd == -1 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	if (save != NULL)
	{
		if (ft_strchr(save, '\n'))
		{
			line = ft_strdup(save);
			free (save);
			save = rest_line(line);
			line = get_line(line);
			return (line);
		}
		if (!ft_strchr(save, '\n'))
		{
			line = ft_strdup(save);
			free (save);
			save = NULL;
		}
	}
	line = create_line(fd, line, &found_nl);
	if (found_nl == 1)
	{
		save = rest_line(line);
		line = get_line(line);
		if (save)
			printf("%s\n", save);
	}
	return (line);
}
