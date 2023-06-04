#include "philo.h"

int	atoi_philo(char *number)
{
	int	i;

	while (number[i] == ' ' || number[i] == '	')
		i++;
	if (number[i] == 0 && number[i + 1] == 0 || )
}

int init_philo(int argc, char **argv, t_time data)
{
	if (argc < 5)
		return (error_manager(1));
	if (argc > 6)
		return (error_manager(2));

}