
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_printf("variable d'environnement =%s\n", envp[i]);
		i++;
	}
}