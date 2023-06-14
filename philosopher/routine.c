/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:26 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/14 16:33:28 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;


	philo = (t_philo*)arg;

	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->right_fork);

	usleep(philo->param->eat_time * 1000);
	printf("Philo finish eating n %d:", philo->num_philo);
	print_time(philo->param->start);

	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);

	printf("finish sleeping\n");
	return (0);
}
