/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   V2get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:41:39 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/04 17:31:36 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char    *process_line(int fd)
{
    char    *buffer;
    int     size_read;
    char *line;
    int     i;

    line = malloc(sizeof(char) * 1);
    if (!line)
        return (NULL);
    line[0] = '\0';

    buffer  = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    buffer[0] = '\0';
    i = 0;
    size_read = 1;
    while (size_read > 0 && !ft_strchr(buffer, '\n'))
    {
        size_read = read(fd, buffer, BUFFER_SIZE);
        buffer[size_read] = '\0';

        line = ft_strjoin(line, buffer);
        i++;
    }
    free (buffer);
    
    
    return (line);
}

char    *get_next_line(int fd)
{
    char    *line;


    line = process_line(fd);

    return (line);
}

int main(void)
{
    int fd;
    char *result;

    fd = open("TEST2.txt", O_RDONLY);

    result = get_next_line(fd);
    printf("%s", result);

}