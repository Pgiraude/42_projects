
#include "get_next_line.h"
#include <stdio.h>


size_t	ft_buffer_len(char *buffer)
{
	size_t			len;
	
	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\n')
		len++;
	return (len);
}



char    *get_next_line(int fd)
{
    char    *buffer[BUFFER_SIZE + 1];
    char    *line;
    int     size;
    int     found_newline;
    int     pos_newline;
    int     i;
    int     j;

    line = malloc(sizof(char) * 1);
    if (!line)
        return (NULL);
    line[0] = '\0';

    found_newline = 0;

    size = 1;

    while (size > 0)
    {
        while (j < )
            size = read(fd, buffer, BUFFER_SIZE);
            buffer[size] = '\0';

            i = 0;
            while (buffer[i])
            {
                if (buffer[i] == '\n')
                {
                    found_newline = 1;
                    pos_newline = (i + j);
                }
                line[i + j] = buffer[i];
                i++;
            }

    }

    return (line);
}