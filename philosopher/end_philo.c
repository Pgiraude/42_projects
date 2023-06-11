#include "philo.h"

int end_philo(t_philo *philo, t_param *param)
{
	int index;

	index = 0;
	while (index < param->nbr_philo)
	{
		if (pthread_join(philo[index].thread, NULL) != 0)
			return (-1);
		pthread_mutex_destroy(&philo[index].left_fork);
		index++;
	}
}
