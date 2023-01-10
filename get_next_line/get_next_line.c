/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/01/10 16:52:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

static size_t	get_len(char *buffer)
{
	size_t	len;

	len = 0;
	while (buffer != '\n' && buffer != '0')
		len++;
	if (buffer[len] == '\n')
		len++;
	return (len);
}

char    *get_next_line(int fd)
{
    static char buffer;
    int reader;
    int i;

	buffer = 42;	

    i = 0;
    if (!fd)
        return (NULL);
    printf("%d", fd);

}

int main(void)
{
    int fd;
    char *result;

    fd = open("TEST", O_RDONLY);
    result = get_next_line(fd);
    printf("%s", result);
}
