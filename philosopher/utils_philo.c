/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:51:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/29 12:08:26 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(struct timeval start, int *time)
{
	struct timeval	current;
	long int		begin;
	long int		finish;

	if (gettimeofday(&current, NULL) == -1)
		return (-1);
	begin = start.tv_sec * 1000 + (start.tv_usec / 1000);
	finish = current.tv_sec * 1000 + (current.tv_usec / 1000);
	if ((finish - begin) > INT_MAX)
		return (-2);
	*time = 0;
	*time = finish - begin;
	return (0);
}

int	atoi_philo(char *str_nbr)
{
	int			i;
	long int	nbr;

	nbr = 0;
	i = 0;
	if (!str_nbr)
		return (-1);
	while (str_nbr[i] == ' ' || str_nbr[i] == '	')
		i++;
	if (str_nbr[i] == '\0')
		return (-1);
	if (str_nbr[i] == '0')
		return (-2);
	while (str_nbr[i] >= '0' && str_nbr[i] <= '9')
	{
		nbr = nbr * 10 + (str_nbr[i] - 48);
		i++;
	}
	while (str_nbr[i] == ' ' || str_nbr[i] == '	')
		i++;
	if (str_nbr[i] != '\0' || nbr == 0)
		return (-2);
	else if (nbr > INT_MAX)
		return (-3);
	return (nbr);
}

int	get_value(pthread_mutex_t *lock, int *value)
{
	int	tmp;

	pthread_mutex_lock(lock);
	tmp = *value;
	pthread_mutex_unlock(lock);
	return (tmp);
}

int	change_value(pthread_mutex_t *lock, int *value, int new_value)
{
	pthread_mutex_lock(lock);
	*value = new_value;
	pthread_mutex_unlock(lock);
	return (0);
}
