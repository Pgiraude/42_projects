#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;


	philo = (t_philo*)arg;

	pthread_mutex_lock(&philo->left_fork);

	usleep(philo->param->eat_time * 1000);
	printf("Philo finish eating :");
	print_time(philo->param->start);

	pthread_mutex_unlock(&philo->left_fork);

	printf("finish sleeping\n");
}