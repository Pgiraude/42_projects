
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

char    *rest_save(char *all_line, size_t len, char *rest_line)
{
    size_t	i;
	
    i = 0;
    while (all_line[(len) + i])
	{
        rest_line[i] = all_line[(len) + i];
        i++;
    }
	rest_line[i] = '\0';
	return (rest_line);
}

char    *get_all_line(int fd, char *rest_line)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *all_line;
    size_t  size;

    all_line = malloc(sizeof(char) * 1);
    all_line[0] = '\0';
//    printf("%s\n", rest_line);
    if (rest_line[0] != '\0')
    {
//        if (ft_strchr(rest_line, '\n'))
//            return (ft_strjoin(all_line, rest_line));
//       all_line = ft_strjoin(all_line, rest_line);
    }
    size = 1;
    while (!ft_strchr(buffer, '\n') && size != 0)
    {
        size = read(fd, buffer, BUFFER_SIZE);
        buffer[size] ='\0';
        all_line = ft_strjoin(all_line, buffer);
    }
    return (all_line);
}

char    *get_next_line(int fd)
{
    char        *all_line;
    size_t      len;
    static char *rest_line;
    char        *line;

    printf("%s\n", rest_line);

    all_line = get_all_line(fd, rest_line);
    len = ft_buffer_len(all_line);
    line = malloc(sizeof(char) * len + 1);
    ft_strlcpy(line, all_line, len);
    
    rest_save(all_line, len, rest_line);
    return (line);
}