#include "philo.h"

int	error_manager_init(int error_code)
{
	if (error_code == 1)
		printf("Error %d: Need more arguments\n");
	if (error_code == 2)
		printf("Error %d: Need less arguments\n");
	return (error_code);
}

int	error_manager(int error_code)
{
	if (error_code < 0)
		return (error_code);
	if (error_code < 20)
		return (error_manager_init(error_code));
	return (0);
}