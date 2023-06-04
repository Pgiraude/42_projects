
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>


# define EATING 4
# define SLEEPING 5
# define THINKING 6

typedef struct s_time
{
	int nbr_philo;
	int die_time;
	int eat_time;
	int sleep_time;
	int nbr_eat;
	pthread_mutex_t lock;
}t_time;

void	*routine(void *arg);

#endif