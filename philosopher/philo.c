/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:19 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/20 14:08:44 by pgiraude         ###   ########.fr       */
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

int	is_dead(t_philo *philo)
{
	int time;

	get_time(philo->param->start, &time);
	if ((time - philo->last_meal) > philo->param->die_time)
	{
		print_status(DEAD, philo);
		return (1);
	}
	return (0);
}

int	check_life_philo(t_philo **philo)
{
	int	index;
	int	eat;
	
	while (1)
	{
		eat = 0;
		index = 0;
		while (index < philo[index]->param->nbr_philo)
		{
			if (is_dead(philo[index]) == 1)
				return (1);
			if (philo[index]->nbr_eat >= philo[index]->param->nbr_eat)
			{
				eat++;
			}
		}
		if (eat == index)
			return (2);
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


	pthread_mutex_init(&param->lock, NULL);

	/*--------------------------------*/
	init_philo(argc, argv, &(*param));
	/*--------------------------------*/

	print_time(param->start);

	launch_philo(param, &philo);

	check_life_philo(&philo);

	end_philo(philo, param);

	pthread_mutex_destroy(&param->lock);

	print_time(start);
}
