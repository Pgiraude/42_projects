/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:19 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/14 16:33:21 by pgiraude         ###   ########.fr       */
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
	printf("nbr philo=%d\n", param->nbr_philo);
	/*--------------------------------*/

	usleep(100 *   1000);
	printf("1st time :");
	print_time(param->start);

	launch_philo(param, &philo);




	end_philo(philo, param);

	pthread_mutex_destroy(&param->lock);

	print_time(start);
}
