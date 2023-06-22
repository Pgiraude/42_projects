/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:32:50 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/22 13:33:10 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int end_philo(t_philo *philo, t_param *param)
{
	int index;

	index = 0;
	while (index < param->nbr_philo)
	{
		if (pthread_join(philo[index].thread, NULL) != 0)
			return (-1);
		pthread_mutex_destroy(&philo[index].left_fork);
		index++;
	}
	pthread_mutex_destroy(&param->lock);
	free (philo);
	free (param);
	return (0);
}
