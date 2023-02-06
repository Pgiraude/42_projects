/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/06 19:32:21 by pgiraude         ###   ########.fr       */
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

char	*rest_buffer(char *buffer, size_t pos)
{
	size_t		i;
	char		*save;

	save = malloc(sizeof(char) * (ft_strlen(buffer + pos) + 1));
	if (!save)
		return (NULL);
	i = 0;
	while (buffer[i + pos])
	{
		save[i] = buffer[i + pos];
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
	char	*tpm;
	

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
	tpm = rest_buffer(buffer, i);
	ft_strlcpy(buffer, tpm, ft_strlen(tpm));
	return (end_line);
}
//retire la partie après le \n si str n'est pas un malloc?? 

char	*create_line(int fd, char *line, char* buffer)
{
	int		size;
	char	*end_line;
	
	if (line == NULL)
	{
		line = malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0 || (size == 0 && ft_strlen(line) == 0))
			return (free (line), NULL);
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
	char			*line;
	static char		*save;
	char	*buffer;

	if (fd == -1 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = NULL;
	if (save[0] != '\0')
	{
		line = process_buffer(save);
		if (ft_strchr(line, '\n'))
			return (line);
		free (save);
	}
	line = create_line(fd, line, buffer);
	save = ft_strdup(buffer);
	free (buffer);
	return (line);
}
//seg fault avec BUFFER_SIZE>12,000,000,0000
