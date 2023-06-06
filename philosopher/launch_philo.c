#include "philo.h"

int	launch_philo(t_time *data)
{
	int	index_philo;
	

	index_philo = 0;
	while (index_philo < data->nbr_philo)
	{
		if (pthread_create(&th[index_philo], NULL, &routine, &(*cool)) != 0)
			return (-1);
		i++;
	}

}