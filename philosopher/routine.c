#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo*)arg;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(&philo->right_fork);


		usleep(philo->param->eat_time);
		
		printf("Philo finish eating at %d", print_time(philo->start));

		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
	}
	printf("finish sleeping\n");
}