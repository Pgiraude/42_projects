/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/07 18:09:16 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rest_buffer(char *buffer)
{
	size_t		len;
	size_t		i;
	char		*save;

	len = ft_strlen(buffer);
	save = malloc(sizeof(char) * (len + 1));
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
//regarder si avec calcul exacte malloc ça passe niveau temps

char	*get_end_line(char *buffer)
{
	char	*end_line;
	char	*save;
	int		i;

	end_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	save = rest_buffer(buffer + i);
	ft_strlcpy(buffer, save, (BUFFER_SIZE - i));
	return (free (save), end_line);
}
//regarder si avec calcul exacte malloc ça passe niveau temps

char	*get_start_line(int fd, char *buffer, char *line)
{
	int		read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && ft_strlen(line) == 0))
			return (free (line), NULL);
		buffer[read_size] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (line);
		else
			line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*get_line(int fd, char *buffer, char *line)
{
	char	*end_line;

	if (line == NULL)
	{
		line = malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = get_start_line(fd, buffer, line);
	if (line == NULL)
		return (NULL);
	end_line = get_end_line(buffer);
	line = ft_strjoin(line, end_line);
	free (end_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer_fd[FOPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd == -1 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = NULL;
	if (buffer_fd[fd])
	{
		line = get_end_line(buffer_fd[fd]);
		// if (ft_strchr(line, '\n') && buffer_fd[fd] == '\0')
		// 	return (free (buffer), free (buffer_fd[fd]), line);
		if (ft_strchr(line, '\n'))
			return (free (buffer), line);
		free (buffer_fd[fd]);
	}
	line = get_line(fd, buffer, line);
	if (buffer[0] != '\0')
		buffer_fd[fd] = ft_strdup(buffer);
	return (free (buffer), line);
}

// int	main(void)
// {
//     int fd;
// 	// int	fd2;
//     char *result;
//     int     i;

//     fd = open("TEST.txt", O_RDONLY);
//     i = 1;
//     while (i <= 1)
//     {
//         result = get_next_line(fd);
//         printf("1N°%d =%s", (i), result);
//         free(result);
//         i++;
//     }

//     // fd2 = open("TEST2.txt", O_RDONLY);
//     // i = 1;
//     // while (i <= 1)
//     // {
//     //     result = get_next_line(fd2);
//     //     printf("2N°%d =%s", (i), result);
//     //     free(result);
//     //     i++;
//     // }

//     // i = 1;
//     // while (i <= 1)
//     // {
//     //     result = get_next_line(fd);
//     //     printf("1N°%d =%s", (i), result);
//     //     free(result);
//     //     i++;
//     // }

//     // i = 1;
//     // while (i <= 1)
//     // {
//     //     result = get_next_line(fd2);
//     //     printf("2N°%d =%s", (i), result);
//     //     free(result);
//     //     i++;
//     // }
// }