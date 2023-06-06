
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


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

typedef struct s_philo
{
	pthread_t		philo;
	int 			nbr_eat;
	struct timeval	start;
	pthread_mutex_t right_lock;
	pthread_mutex_t left_lock;
}t_philo;

void	*routine(void *arg);

int		init_philo(int argc, char **argv, t_time *data);

int		error_manager(int error_code);

#endif