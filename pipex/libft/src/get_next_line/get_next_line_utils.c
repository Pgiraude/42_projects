/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:10:21 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 12:58:16 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;
	int		x;

	if (!s1 && !s2)
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
			str[i + j] = s2[j];
	str[i + j] = '\0';
	free (s1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	const char		*ptr;
	size_t			i;
	size_t			n;

	n = ft_strlen(s) + 1;
	if (!s)
		return (NULL);
	ptr = s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ptr[i])
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}

int	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i <= (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (len_src);
}
