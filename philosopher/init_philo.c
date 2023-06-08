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

int init_philo(int argc, char **argv, t_param *data)
{
	int	nbr;

	// if (argc < 5)
	// 	return (error_manager(1));
	// if (argc > 6)
	// 	return (error_manager(2));
	data->nbr_philo = atoi_philo(argv[1]);
	if (data->nbr_philo <= 0)
		return (error_manager(data->nbr_philo));

	data->die_time = atoi_philo(argv[2]);
	if (data->die_time <= 0)
		return (error_manager(data->die_time));
	
	data->eat_time = atoi_philo(argv[3]);
	if (data->eat_time <= 0)
		return (error_manager(data->eat_time));
	
	data->sleep_time = atoi_philo(argv[4]);
	if (data->sleep_time <= 0)
		return (error_manager(data->sleep_time));

	data->nbr_eat = atoi_philo(argv[5]);
	if (data->nbr_eat <= 0)
		return (error_manager(data->nbr_eat));

	
}
