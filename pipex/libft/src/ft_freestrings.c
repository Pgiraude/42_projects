
#include "../include/libft.h"

void	ft_freestrings(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free (tab_str[i]);
		i++;
	}
    if (tab_str)
	    free (tab_str);
}