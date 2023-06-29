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
		pthread_mutex_lock(&param->lock_print);
		time = 0;
		get_time(param->start, &time);
		printf("%d %d is dead\n", time, philo.num_philo);
		pthread_mutex_unlock(&param->lock_print);
		return (TRUE);
	}
	pthread_mutex_unlock(&param->lock_value);
	return (FALSE);
}

int	philo_sign(t_param *param)
{
	int value;

	value = FALSE;
	pthread_mutex_lock(&param->lock_dead);
	if (param->dead == TRUE)
		value = TRUE;
	pthread_mutex_unlock(&param->lock_dead);
	pthread_mutex_lock(&param->lock_value);
	if (param->eat == TRUE)
	 	value = TRUE;
	pthread_mutex_unlock(&param->lock_value);
	return (value);
}

int	check_life_philo(t_philo *philo, t_param *param)
{
	int	index;
	int	eat;
	int	nbr_philo;
	int	nbr_eat;

	nbr_philo = get_value(&param->lock_value, &param->nbr_philo);
	nbr_eat = get_value(&param->lock_value, &param->nbr_eat);
	while (philo_sign(param) == FALSE)
	{
		eat = 0;
		index = 0;
		while (index < nbr_philo)
		{
			if (is_dead(philo[index], param) == TRUE)
				return (0);
			if (get_value(&param->lock_value, &philo[index].nbr_eat) >= nbr_eat)
				eat++;
			index++;
		}
		if (eat == index && nbr_eat > 0)
			change_value(&param->lock_value, &param->eat, TRUE);
		usleep(1000);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_philo			*philo;
	t_param			*param;

	param = malloc(sizeof(t_param));

	if (init_philo(argc, argv, param, &philo) != 0)
		return (free (param), 1);

	if (launch_philo(param, philo) != 0)
		return (free (param), free (philo), 2);
	
	check_life_philo(philo, param);
	exit_philo(philo, param);
	print_time(param->start);
}
