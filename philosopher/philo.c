/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:19 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/29 14:08:02 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int status, t_philo *philo)
{
	int	time;

	if (philo_sign(philo->param) == FALSE)
	{
		if (status == SLEEPING)
		{
			pthread_mutex_lock(&philo->param->lock_print);
			get_time(philo->param->start, &time);
			printf("%d %d is sleeping\n", time, philo->num_philo);
			pthread_mutex_unlock(&philo->param->lock_print);
		}
		if (status == THINKING)
		{
			pthread_mutex_lock(&philo->param->lock_print);
			get_time(philo->param->start, &time);
			printf("%d %d is thinking\n", time, philo->num_philo);
			pthread_mutex_unlock(&philo->param->lock_print);
		}
	}
}

int	is_dead(t_philo *philo, t_param *param)
{
	int	time;
	int	last_meal;

	pthread_mutex_lock(&param->lock_value);
	get_time(param->start, &time);
	last_meal = philo->last_meal;
	if ((time - last_meal) > param->die_time)
	{
		pthread_mutex_unlock(&param->lock_value);
		pthread_mutex_lock(&param->lock_dead);
		param->dead = TRUE;
		pthread_mutex_lock(&param->lock_print);
		get_time(param->start, &time);
		printf("%d %d is dead\n", time, philo->num_philo);
		pthread_mutex_unlock(&param->lock_print);
		pthread_mutex_unlock(&param->lock_dead);
		return (TRUE);
	}
	pthread_mutex_unlock(&param->lock_value);
	return (FALSE);
}

int	philo_sign(t_param *param)
{
	int	value;

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
			if (is_dead(&philo[index], param) == TRUE)
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

int	main(int argc, char **argv)
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
	free (philo);
	free (param);
}
