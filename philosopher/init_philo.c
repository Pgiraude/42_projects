/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:33:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/22 13:32:11 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	parsing_values(int argc, char **argv, t_param *param)
{
	param->nbr_philo = atoi_philo(argv[1]);
	if (param->nbr_philo <= 0)
		return (error_manager(4, "Number of philo"));
	param->die_time = atoi_philo(argv[2]);
	if (param->die_time <= 0)
		return (error_manager(5, "Die time"));
	param->eat_time = atoi_philo(argv[3]);
	if (param->eat_time <= 0)
		return (error_manager(6, "Eat time"));
	param->sleep_time = atoi_philo(argv[4]);
	if (param->sleep_time <= 0)
		return (error_manager(7, "Sleep time"));
	if (argc == 6)
	{
		param->nbr_eat = atoi_philo(argv[5]);
		if (param->nbr_eat <= 0)
			return (error_manager(8, NULL));
	}
	else
		param->nbr_eat = -1;
	return (0);
}

int	init_threads(t_philo *philo, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nbr_philo)
	{
		if (i == param->nbr_philo - 1)
			philo[i].right_fork = &philo[0].left_fork;
		else
			philo[i].right_fork = &philo[i + 1].left_fork;
		philo[i].num_philo = i + 1;
		philo[i].last_meal = 0;
		philo[i].nbr_eat = 0;
		philo[i].param = param;
		i++;
	}
	return (0);
}

int	init_philo(int argc, char **argv, t_param *param, t_philo **philo)
{
	int	nbr;

	if (argc < 5)
		return (error_manager(1, NULL));
	if (argc > 6)
		return (error_manager(2, NULL));
	if (parsing_values(argc, argv, param) != 0)
		return (1);
	param->dead = FALSE;
	param->eat = FALSE;
	*philo = NULL;
	*philo = malloc(sizeof(t_philo) * (param->nbr_philo));
	if (!(*philo))
		return (error_manager(3, NULL));
	init_threads(*philo, param);
	pthread_mutex_init(&param->lock, NULL);
	return (0);
}
