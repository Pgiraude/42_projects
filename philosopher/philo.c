/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:19 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/28 19:33:47 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	is_dead(t_philo philo, t_param *param)
{
	int time;
	int last_meal;
	
	pthread_mutex_lock(&param->lock_value);
	get_time(param->start, &time);
	last_meal = philo.last_meal;
	if ((time - last_meal) > param->die_time)
	{
		pthread_mutex_unlock(&param->lock_value);
		pthread_mutex_lock(&param->lock_dead);
		param->dead = TRUE;
		pthread_mutex_unlock(&param->lock_dead);
		print_status(DEAD, &philo);
		return (TRUE);
	}
	pthread_mutex_unlock(&param->lock_value);
	return (FALSE);
}

int	philo_sign(t_philo *philo, t_param *param)
{
	int value;

	value = FALSE;
	pthread_mutex_lock(&param->lock_dead);
	if (philo->param->dead == TRUE)
		value = TRUE;
	pthread_mutex_unlock(&param->lock_dead);
	pthread_mutex_lock(&param->lock_value);
	if (philo->param->eat == TRUE)
	 	value = TRUE;
	pthread_mutex_unlock(&param->lock_value);
	return (value);
}

int	check_values(pthread_mutex_t *lock, t_bool *value)
{
	t_bool	tmp;

	pthread_mutex_lock(lock);
	tmp = *value;
	pthread_mutex_unlock(lock);
	return (tmp);
}

int change_values(pthread_mutex_t *lock, int *value, int new_value)
{
	pthread_mutex_lock(lock);
	*value = new_value;
	pthread_mutex_unlock(lock);
	return (0);
}

int	check_life_philo(t_philo *philo, t_param *param)
{
	int	index;
	int	eat;
	int	nbr_philo;
	int	nbr_eat;

	pthread_mutex_lock(&param->lock_value);
	nbr_philo = param->nbr_philo;
	nbr_eat = param->nbr_eat;
	pthread_mutex_unlock(&param->lock_value);

	while (1)
	{
		eat = 0;
		index = 0;
		while (index < nbr_philo)
		{
			if (is_dead(philo[index], param) == TRUE)
				return (0);
			pthread_mutex_lock(&param->lock_value);
			if (philo[index].nbr_eat >= nbr_eat)
				eat++;
			pthread_mutex_unlock(&param->lock_value);
			index++;
		}
		if (eat == index && nbr_eat > 0)
		{
			pthread_mutex_lock(&param->lock_value);
			param->eat = TRUE;
			pthread_mutex_unlock(&param->lock_value);
			return (0);
		}
		usleep(1000);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_philo			*philo;
	t_param			*param;

	param = malloc(sizeof(t_param));

	/*--------------------------------*/
	if (init_philo(argc, argv, param, &philo) != 0)
		return (free (param), 1);
	/*--------------------------------*/

	if (launch_philo(param, philo) != 0)
		return (free (param), free (philo), 2);
	
	check_life_philo(philo, param);
	exit_philo(philo, param);
	print_time(param->start);
}
