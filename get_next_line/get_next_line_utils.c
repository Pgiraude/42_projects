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

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
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

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	size_t					i;

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

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;
	int		i;

	len = 0;
	while (s[len])
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlcpy(char *dst, const char *src, size_t size)
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