/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:32:50 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/27 16:11:50 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int exit_philo(t_philo *philo, t_param *param)
{
	int index;

	index = 0;
	while (index < param->nbr_philo)
	{
		if (pthread_join(philo[index].thread, NULL) != 0)
			error_manager(40, NULL);
		if (pthread_mutex_destroy(&philo[index].left_fork) != 0)
		{
			printf("index = %d :", index);
			error_manager(41, NULL);
		}
		index++;
	}
	if (pthread_mutex_destroy(&param->lock_value) != 0)
		error_manager(42, NULL);
	if (pthread_mutex_destroy(&param->lock_print) != 0)
		error_manager(42, NULL);
	free (philo);
	free (param);
	return (0);
}
