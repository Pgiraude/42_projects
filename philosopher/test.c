
#include "philo.h"

int mail;

int print_time(struct timeval start)
{
	struct timeval	current;
	long int		begin;
	long int		finish;

	if (gettimeofday(&current, NULL) == -1)
		return (-1);
	begin = start.tv_sec * 1000 + (start.tv_usec / 1000);
	finish = current.tv_sec * 1000 + (current.tv_usec / 1000);
	printf("Time taken is : %ld milliseconds\n", (finish - begin));
	return (0);
}



void	*philo_fx(void *arg)
{
	int	i;
	t_time *lol;
	pthread_mutex_t mutex;

	lol = (t_time*)arg;
	lol->lock = mutex;
	i = 0;
	while (i < 100000)
	{
		pthread_mutex_lock(&mutex);
		mail++;
		i++;
		pthread_mutex_unlock(&mutex);
		
	}
	
}

int main(int argc, char **argv)
{
	struct timeval	start;
	pthread_t		th[4];
	t_time			*cool;


	cool = malloc(sizeof(t_time));
	mail = 0;
	pthread_mutex_init(&cool->lock, NULL);
	gettimeofday(&start, NULL);

	int	i;
	i = 0;
	while (th[i])
	{
		if (pthread_create(&th[i], NULL, &philo_fx, cool) != 0)
			return (-1);
		i++;
	}

	print_time(start);


	i = 0;
	while (th[i])
	{
		if (pthread_join(th[i], NULL) != 0)
			return (-1);
		i++;
	}

	pthread_mutex_destroy(&cool->lock);
	free(cool);
	printf("mail =%d\n", mail);

	print_time(start);
}