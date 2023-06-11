
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

typedef struct s_param
{
	int				nbr_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nbr_eat;
	struct timeval	start;
	pthread_mutex_t	lock;
}t_param;

typedef struct s_philo
{	
	pthread_t		thread;
	int				num_philo;
	int 			nbr_eat;
	struct timeval	start;
	pthread_mutex_t right_fork;
	pthread_mutex_t left_fork;
	struct s_param	*param;
}t_philo;

int		print_time(struct timeval start);

void	*routine(void *arg);

int		init_philo(int argc, char **argv, t_param *data);

int		error_manager(int error_code);

int		end_philo(t_philo *philo, t_param *param);

int		launch_philo(t_param *param, t_philo **philo);

#endif