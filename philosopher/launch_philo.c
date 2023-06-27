/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/27 18:56:23 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	int	time;
	
	pthread_mutex_lock(&philo->param->lock_print);
	time = 0;
	get_time(philo->param->start, &time);
	printf("%d %d is eating\n", time, philo->num_philo);
	philo->last_meal = time;
	pthread_mutex_unlock(&philo->param->lock_print);
	usleep(philo->param->eat_time * 1000);
	philo->nbr_eat++;
}

void	print_status(int status, t_philo *philo)
{
	int	time;

	if (status == SLEEPING)
	{
		pthread_mutex_lock(&philo->param->lock_print);
		time = 0;
		get_time(philo->param->start, &time);
		printf("%d %d is sleeping\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
		
		usleep(philo->param->sleep_time * 1000);
	}


	if (status == THINKING)
	{
		pthread_mutex_lock(&philo->param->lock_print);
		time = 0;
		get_time(philo->param->start, &time);
		printf("%d %d is thinking\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
	}


	if (status == DEAD)
	{
		pthread_mutex_lock(&philo->param->lock_print);
		time = 0;
		get_time(philo->param->start, &time);
		printf("%d %d is dead\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
	}

}

void	take_forks(t_philo *philo)
{
	int	time;

	time = 0;
	if (philo->num_philo % 2 != 0)
	{
			
			
		pthread_mutex_lock(&philo->left_fork);

	
		pthread_mutex_lock(&philo->param->lock_print);
		get_time(philo->param->start, &time);
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);

		pthread_mutex_lock(philo->right_fork);
		
		pthread_mutex_lock(&philo->param->lock_print);
		get_time(philo->param->start, &time);
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
	}
	else
	{
			
		pthread_mutex_lock(philo->right_fork);
		
		pthread_mutex_lock(&philo->param->lock_print);
		get_time(philo->param->start, &time);
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
			
		pthread_mutex_lock(&philo->left_fork);

		pthread_mutex_lock(&philo->param->lock_print);
		get_time(philo->param->start, &time);
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_unlock(&philo->param->lock_print);
	}
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	
	while (philo_sign(philo, philo->param) == FALSE)
	{
		
		take_forks(philo);

		eating(philo);

		
		if (philo->num_philo % 2 != 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(&philo->left_fork);
		}
		else
		{
			pthread_mutex_unlock(&philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}

		print_status(SLEEPING, philo);

		print_status(THINKING, philo);
	}
	return (0);
}

void	*one_routine(void *arg)
{
	t_philo *philo;
	int	time;

	time = 0;
	philo = (t_philo*)arg;
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
	int		index;

	index = 0;
	if (param->nbr_philo == 1)
	{
		if (pthread_create(&philo[index].thread, NULL, &one_routine, &philo[index]) != 0)
			return (error_manager(20, NULL));
		return (0);
	}
	while (index < param->nbr_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &routine, &philo[index]) != 0)
			return (error_manager(20, NULL));
		index++;
	}
	return (0);
}
