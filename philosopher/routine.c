/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:26 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/15 17:58:51 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int status, t_philo *philo)
{
	if (status == EATING)
	{
		
	}
}

void	take_forks(t_philo *philo)
{
	int	time;

	time = 0;
	if (philo->num_philo % 2 != 0)
	{
		pthread_mutex_lock(&philo->left_fork);
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_lock(philo->right_fork);
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		pthread_mutex_lock(&philo->left_fork);
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
	}
}

void	*routine(void *arg)
{
	t_philo *philo;
	int		time1;

	time1 = 0;
	philo = (t_philo*)arg;
	
	take_forks(philo);

	// if (get_time(philo->param->start, &time) < 0)
	// 	return (NULL); 
	// printf("%d %d is eating\n", time, philo->num_philo);

	usleep(philo->param->eat_time * 1000);

	// if (get_time(philo->param->start, &time) < 0)
	// 	return (NULL); 
	// philo->last_meal = time;

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

	// if (get_time(philo->param->start, &time) < 0)
	// 	return (NULL); 
	// printf("%d %d is sleeping\n", time, philo->num_philo);

	// usleep(philo->param->sleep_time * 1000);
	printf("end routine \n");
	return (0);
}
