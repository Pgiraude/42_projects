/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:19 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/21 17:54:12 by pgiraude         ###   ########.fr       */
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
		pthread_mutex_lock(&philo->param->lock);
		philo->param->dead++;
		pthread_mutex_unlock(&philo->param->lock);
		print_status(DEAD, philo);
		return (1);
	}
	return (0);
}

int	philo_sign(t_philo *philo)
{
	int value;

	pthread_mutex_lock(&philo->param->lock);
	value = philo->param->dead;
	pthread_mutex_unlock(&philo->param->lock);
	return (value);
}

int	check_life_philo(t_philo **philo)
{
	int	index;
	int	eat;

	eat = 0;
	index = 0;
	while (index < philo[index]->param->nbr_philo)
	{
		if (is_dead(philo[index]) == 1)
			return (1);
		if (philo[index]->nbr_eat >= philo[index]->param->nbr_eat)
			eat++;
	}
	if (eat == index)
		return (2);
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

	while (check_life_philo(&philo) == 0)
		;
	end_philo(philo, param);

	pthread_mutex_destroy(&param->lock);

	print_time(start);
}
