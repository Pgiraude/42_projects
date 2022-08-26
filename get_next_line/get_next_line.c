/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:12:47 by pgiraude          #+#    #+#             */
/*   Updated: 2022/08/26 21:05:54 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd)
{
    
}

int main(void)
{
    int fd;
    char *result;

    fd = open("TEXT", O_RDONLY);
    result = get_next_line(fd);
    printf("%s", result);
}