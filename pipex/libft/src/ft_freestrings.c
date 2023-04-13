
#include "../include/libft.h"

void	ft_freestrings(char **tab_str)
{
	int	i;

	i = 0;
	if (!tab_str)
		return ;
	while (tab_str[i])
	{
		free (tab_str[i]);
		i++;
	}
    if (tab_str)
	    free (tab_str);
}