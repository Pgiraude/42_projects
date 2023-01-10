/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:10:21 by pgiraude          #+#    #+#             */
/*   Updated: 2023/01/10 16:39:58 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

size_t	len_test(char *test)
{
	size_t			len;
	static size_t	i = 0;
	
	len = 0;
	while (test[len + i] != 10  && test[len + i] != 0)
		len++;
	if (test[len + i] == '\n')
		len++;
	i = i + len;
	return (len);
}



int main(void)
{
	char	*test = "salut mec\nComment ca va?\noui";
	size_t	result;
	
	result = len_test(test);
	printf("%ld \n", result);

	result = len_test(test);
	printf("%ld \n", result);

	result = len_test(test);
	printf("%ld \n", result);
}



