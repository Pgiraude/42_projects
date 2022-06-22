/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:38:35 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/22 21:11:20 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set_check(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j] == s1[i])
	{
		j++;
		i++;
		if (!set[j])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len_s1;
	int		len_set;
	char	*str;
	int		i;

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_set = 0;
	while (set[len_set])
		len_set++;
	start = 0;
	if (ft_set_check(s1, set, 0))
		start = len_set;
	end = len_s1;
	if (ft_set_check(s1, set, (len_s1 - len_set)))
		end = len_s1 - len_set;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	char s[] = "cXc";
	char set[] = "c";

	char *str;

	str = ft_strtrim(s, set);
	printf(str);

}
*/