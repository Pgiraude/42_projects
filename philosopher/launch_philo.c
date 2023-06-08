#include "philo.h"

int	launch_philo(t_param *param)
{
	t_philo	*philo;
	int		index;
	
	philo = NULL;
	philo = malloc(sizeof(t_philo) * (param->nbr_philo));
	if (!philo)
		return (error_manager(3));

	int	i;
	i = 0;
	while (i < param->nbr_philo)
	{
		if (i == param->nbr_philo - 1)
			philo[i].right_fork = philo[0].left_fork;
		else
			philo[i].right_fork = philo[i + 1].left_fork;
		philo[i].num_philo = i + 1;
		philo[i].param = param;
		i++;
	}

	index = 0;
	while (index < param->nbr_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &routine, &philo[index]) != 0)
			return (-1);
		index++;
	}
}