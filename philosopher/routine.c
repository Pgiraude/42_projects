#include "philo.h"

void	*routine(void *arg)
{
	t_time *lol;


	lol = (t_time*)arg;

	pthread_mutex_lock(&lol->lock);

	

	usleep(1000 * 3000);
	pthread_mutex_unlock(&lol->lock);
	printf("finish sleeping\n");
}