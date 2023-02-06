/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/01 12:46:29 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rest_buffer(char *buffer)
{
	size_t		len;
	size_t		i;
	char		*save;

	len = ft_strlen(buffer);
	save = malloc(sizeof(char) * (len + 1)); //regarder si avec calcul exacte malloc ça passe niveau temps
	if (!save)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		save[i] = buffer[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*process_end_line(char *buffer)
{
	char	*end_line;
	char	*tmp;
	int		i;

	end_line = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //regarder si avec calcul exacte malloc ça passe niveau temps
	if (!end_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		end_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		end_line[i] = buffer[i];
		i++;
	}
	end_line[i] = '\0';
	tmp = rest_buffer(buffer + i);
	ft_strlcpy(buffer, tmp, (BUFFER_SIZE - i));
	return (free (tmp), end_line);
}

char	*get_line_fd(int fd, char *buffer, char *line)
{
	int		read_size;




	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		buffer[read_size] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (line);
		else
			line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer_fd[FOPEN_MAX];
	char		*buffer;
	char		*line;
	char		*end_line;
	char		*tmp;

	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (buffer_fd[fd])
		{
			tmp = process_end_line(buffer_fd[fd]);
			line = ft_strjoin(line, tmp);
			free (tmp);
			if (ft_strchr(line, '\n'))
				return (line);
		}

	line = get_line_fd(fd, buffer, line);
	end_line = process_end_line(buffer);
	line = ft_strjoin(line, end_line);
	buffer_fd[fd] = ft_strdup(buffer);
	free (buffer);

	return (line);
}

int main(void)
{
    int fd;
	int	fd2;
    char *result;
    int     i;

    fd = open("TEST.txt", O_RDONLY);
    i = 1;
    while (i <= 1)
    {
        result = get_next_line(fd);
        printf("1N°%d =%s", (i), result);
        free(result);
        i++;
    }

    fd2 = open("TEST2.txt", O_RDONLY);
    i = 1;
    while (i <= 1)
    {
        result = get_next_line(fd2);
        printf("2N°%d =%s", (i), result);
        free(result);
        i++;
    }

    i = 1;
    while (i <= 1)
    {
        result = get_next_line(fd);
        printf("1N°%d =%s", (i), result);
        free(result);
        i++;
    }

    i = 1;
    while (i <= 1)
    {
        result = get_next_line(fd2);
        printf("2N°%d =%s", (i), result);
        free(result);
        i++;
    }
}