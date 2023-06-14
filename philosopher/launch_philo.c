/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/14 16:33:16 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_philo(t_param *param, t_philo **phil)
{
	int		index;
	t_philo *philo;

	*phil = NULL;
	*phil = malloc(sizeof(t_philo) * (param->nbr_philo));
	philo = *phil;
	if (!philo)
		return (error_manager(3));

	int	i;
	i = 0;
	while (i < param->nbr_philo)
	{
		if (i == param->nbr_philo - 1)
			philo[i].right_fork = philo[0].left_fork;
		else
			philo[i].right_fork = philo[i + 1].left_fork;
		philo[i].num_philo = i + 1;
		philo[i].param = param;
		i++;
	}

	usleep(100 *   1000);
	printf("2st time :");
	print_time(param->start);

	index = 0;
	while (index < param->nbr_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &routine, &philo[index]) != 0)
			return (-1);
		index++;
	}
	usleep(100 *   1000);
	printf("3st time :");
	print_time(param->start);
	return (0);
}