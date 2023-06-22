/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/22 13:51:50 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int status, t_philo *philo)
{
	int	time;

	if (get_time(philo->param->start, &time) < 0)
		return ; 
	if (status == EATING)
	{
		printf("%d %d is eating\n", time, philo->num_philo);
		philo->last_meal = time;
		usleep(philo->param->eat_time * 1000);
		philo->nbr_eat++;
	}
	if (status == SLEEPING)
	{
		printf("%d %d is sleeping\n", time, philo->num_philo);
		usleep(philo->param->sleep_time * 1000);
	}
	if (status == THINKING)
		printf("%d %d is thinking\n", time, philo->num_philo);
	if (status == DEAD)
		printf("%d %d is dead\n", time, philo->num_philo);
}

void	take_forks(t_philo *philo)
{
	int	time;

	time = 0;
	if (philo->num_philo % 2 != 0)
	{
		if (philo_sign(philo) == TRUE)
			return ;
		pthread_mutex_lock(&philo->left_fork);
		if (philo_sign(philo) == TRUE)
			return ;
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		if (philo_sign(philo) == TRUE)
			return ;
		pthread_mutex_lock(philo->right_fork);
		if (philo_sign(philo) == TRUE)
			return ;
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
	}
	else
	{
		if (philo_sign(philo) == TRUE)
			return ;
		pthread_mutex_lock(philo->right_fork);
		if (philo_sign(philo) == TRUE)
			return ;
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
		if (philo_sign(philo) == TRUE)
			return ;
		pthread_mutex_lock(&philo->left_fork);
		if (philo_sign(philo) == TRUE)
			return ;
		if (get_time(philo->param->start, &time) < 0)
			return ; 
		printf("%d %d has taken a fork\n", time, philo->num_philo);
	}
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	
	while (philo->param->dead == 0)
	{
		if (philo_sign(philo) == TRUE)
			break ;
		take_forks(philo);
		if (philo_sign(philo) != 0)
		{
			pthread_mutex_unlock(&philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		print_status(EATING, philo);

		
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

		
		if (philo_sign(philo) == TRUE)
			break ;
		print_status(SLEEPING, philo);
		if (philo_sign(philo) == TRUE)
			break ;
		print_status(THINKING, philo);
	}
	return (0);
}

int	launch_philo(t_param *param, t_philo *philo)
{
	int		index;

	index = 0;
	while (index < param->nbr_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &routine, &philo[index]) != 0)
			return (error_manager(20, NULL));
		index++;
	}
	return (0);
}
