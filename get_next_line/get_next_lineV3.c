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

char	*rest_buffer(char *buffer)
{
	size_t		len;
	size_t		i;
	char		*save;

	len = len_buffer(buffer);
	save = malloc(sizeof(char) * (ft_strlen(buffer + len) + 1));
	if (!save)
		return (NULL);
	i = 0;
	while (buffer[len + i])
	{
		save[i] = buffer[len + i];
		i++;
	}
	save[i] = '\0';
	return (save);
}
// seg fault si n'utilise pas un malloc??

char	*process_buffer(char *buffer)
{
	size_t	len;
	size_t	i;
	char	*end_line;
	char	*save;

	len = len_buffer(buffer);
	end_line = malloc(sizeof(char) * (len + 1));
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
	save = rest_buffer(buffer);
	ft_strlcpy(buffer, save, (BUFFER_SIZE - len));
	free (save);
	return (end_line);
}
//retire la partie après le \n si str n'est pas un malloc?? 

char	*create_line(int fd, char *buffer, char *line)
{
	int		size;
	char	*end_line;

	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0 || (size == 0 && ft_strlen(line) == 0))
			return (free (line), free(buffer), NULL);
		buffer[size] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			end_line = process_buffer(buffer);
			line = ft_strjoin(line, end_line);
			free (end_line);
			return (line);
		}
		else
			line = ft_strjoin(line, buffer);
	}
	return (line);
}
//size doit etre un int et non size_t car on obtient -1 pour un read invalid fd
//pas oublier de free line si le fichier read est vide

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	char			*tmp;

	if (fd == -1 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buffer == NULL)
	{	
    	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
	}
	else
	{
		tmp = process_buffer(buffer);
		line = ft_strjoin(line, tmp);
		free (tmp);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	return (create_line(fd, buffer, line));
}
//seg fault avec BUFFER_SIZE>12,000,000,0000