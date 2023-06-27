/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:19 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/27 19:23:35 by pgiraude         ###   ########.fr       */
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

int	is_dead(t_philo *philo, t_param *param)
{
	int time;
	
	pthread_mutex_lock(&param->lock_value);
	get_time(param->start, &time);
	pthread_mutex_unlock(&param->lock_value);
	if ((time - philo->last_meal) > param->die_time)
	{
		pthread_mutex_lock(&param->lock_dead);
		philo->param->dead = TRUE;
		pthread_mutex_unlock(&param->lock_dead);
		print_status(DEAD, philo);
		return (TRUE);
	}
	return (FALSE);
}

int	philo_sign(t_philo *philo, t_param *param)
{
	int value;

	pthread_mutex_lock(&param->lock_dead);
	value = FALSE;
	if (philo->param->dead == TRUE)
		value = TRUE;
	if (philo->param->eat == TRUE)
	 	value = TRUE;
	pthread_mutex_unlock(&param->lock_dead);
	return (value);
}

int	check_life_philo(t_philo *philo, t_param *param)
{
	int	index;
	int	eat;

	while (1)
	{
		eat = 0;
		index = 0;
		while (index < param->nbr_philo)
		{
			if (is_dead(&philo[index], param) == TRUE)
				return (0);
			pthread_mutex_lock(&param->lock_value);
			if (philo[index].nbr_eat >= param->nbr_eat)
				eat++;
			pthread_mutex_unlock(&param->lock_value);
			index++;
		}
		if (eat == index && param->nbr_eat > 0)
		{
			pthread_mutex_lock(&param->lock_value);
			param->eat = TRUE;
			pthread_mutex_unlock(&param->lock_value);
			return (0);
		}
	}

	return (0);
}

int main(int argc, char **argv)
{
	struct timeval	start;
	t_philo			*philo;
	t_param			*param;

	param = malloc(sizeof(t_param));
	gettimeofday(&start, NULL);
	param->start = start;

	/*--------------------------------*/
	if (init_philo(argc, argv, param, &philo) != 0)
		return (free (param), 1);
	/*--------------------------------*/

	if (launch_philo(param, philo) != 0)
		return (free (param), free (philo), 2);

	check_life_philo(philo, param);
	exit_philo(philo, param);
	print_time(start);
}
