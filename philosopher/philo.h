
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_time
{
	int nbr_philo;
	int die_time;
	int eat_time;
	int sleep_time;
	int nbr_eat;
	pthread_mutex_t lock;
}t_time;


#endif