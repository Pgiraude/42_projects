/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/01/31 20:12:14 by pgiraude         ###   ########.fr       */
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
	char		*str;

	len = len_buffer(buffer);
	str = malloc(sizeof(char) * (BUFFER_SIZE - len) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[(len) + i])
	{
		str[i] = buffer[(len) + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// seg fault si n'utilise pas un malloc??

char	*process_buffer(char *buffer)
{
	size_t	len;
	size_t	i;
	char	*str;
	char	*tmp;

	len = len_buffer(buffer);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		str[i] = buffer[i];
		i++;
		len--;
	}
	str[i] = '\0';
	tmp = rest_buffer(buffer);
	ft_strlcpy(buffer, tmp, (BUFFER_SIZE - len));
	free (tmp);
	return (str);
}
//retire la partie après le \n si str n'est pas un malloc?? 

char	*create_line(int fd, char *buffer, char *line)
{
	int		size;
	char	*tmp;

	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (!fd)
			return (NULL);
		if (size < 0 || (size == 0 && ft_strlen(line) == 0))
			return (free (line), NULL);
		buffer[size] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			tmp = process_buffer(buffer);
			line = ft_strjoin(line, tmp);
			free (tmp);
			return (line);
		}
		else
			line = ft_strjoin(line, buffer);
	}
	return (line);
}
//size doit etre un int et non size_t car on obtient -1 pour un invalid fd

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buffer[0] != '\0')
	{
		tmp = process_buffer(buffer);
		line = ft_strjoin(line, tmp);
		free (tmp);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	return (create_line(fd, buffer, line));
}
