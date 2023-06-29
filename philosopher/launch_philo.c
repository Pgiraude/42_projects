/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/29 16:58:11 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	int	time;

	if (philo_sign(philo->param, FALSE) == FALSE)
	{
		pthread_mutex_lock(&philo->param->lock_print);
		get_time(philo->param->start, &time);
		printf("%d %d is eating\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
		pthread_mutex_lock(&philo->param->lock_value);
		philo->last_meal = time;
		philo->nbr_eat++;
		pthread_mutex_unlock(&philo->param->lock_value);
	}
	pthread_mutex_unlock(&philo->param->lock_dead);
}

void	take_forks(t_philo *philo)
{
	int	time;
	int	num_philo;

	num_philo = get_value(&philo->param->lock_value, &philo->num_philo);
	lock_unlock(philo, num_philo, TRUE);
	if (philo_sign(philo->param, FALSE) == FALSE)
	{
		pthread_mutex_lock(&philo->param->lock_print);
		get_time(philo->param->start, &time);
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		get_time(philo->param->start, &time);
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
	}
	pthread_mutex_unlock(&philo->param->lock_dead);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		num_philo;

	philo = (t_philo *)arg;
	num_philo = get_value(&philo->param->lock_value, &philo->num_philo);
	if (num_philo % 2 != 0)
	{
		print_status(THINKING, philo);
		usleep(2000);
	}
	while (philo_sign(philo->param, TRUE) == FALSE)
	{
		take_forks(philo);
		eating(philo);
		if (philo_sign(philo->param, TRUE) == FALSE)
			usleep(philo->param->eat_time * 1000);
		lock_unlock(philo, num_philo, FALSE);
		print_status(SLEEPING, philo);
		if (philo_sign(philo->param, TRUE) == FALSE)
			usleep(philo->param->sleep_time * 1000);
		print_status(THINKING, philo);
		if (philo_sign(philo->param, TRUE) == FALSE)
			usleep((philo->param->die_time - (philo->param->sleep_time + philo->param->eat_time)) / 2 * 1000);
	}
	return (0);
}

void	*one_routine(void *arg)
{
	t_philo	*philo;
	int		time;

	time = 0;
	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->param->lock_print);
	get_time(philo->param->start, &time);
	printf("%d %d has taken a fork\n", time, philo->num_philo);
	pthread_mutex_unlock(&philo->param->lock_print);
	pthread_mutex_unlock(&philo->left_fork);
	return (0);
}

int	launch_philo(t_param *param, t_philo *philo)
{
	int	index;

	index = 0;
	if (param->nbr_philo == 1)
	{
		if (pthread_create(&philo[index].thread, NULL, \
			&one_routine, &philo[index]) != 0)
			return (error_manager(20, NULL));
		return (0);
	}
	while (index < param->nbr_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, \
			&routine, &philo[index]) != 0)
			return (error_manager(20, NULL));
		index++;
	}
	return (0);
}
