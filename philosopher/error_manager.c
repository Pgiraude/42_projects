/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:32:59 by pgiraude          #+#    #+#             */
/*   Updated: 2023/06/14 16:33:01 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_manager_init(int error_code)
{
	if (error_code == -3)
		printf("Error %d: Value is supperior too int max\n", error_code);
	if (error_code == -2)
		printf("Error %d: Incorrect value, need a positive decimal int\n", error_code);
	if (error_code == -1)
		printf("Error %d: No value, need a positive decimal int\n", error_code);
	if (error_code == 1)
		printf("Error %d: Need more arguments\n", error_code);
	if (error_code == 2)
		printf("Error %d: Need less arguments\n", error_code);
	if (error_code == 3)
		printf("Error %d: Malloc failde\n", error_code);
	return (error_code);
}

int	error_manager(int error_code)
{
	if (error_code == 0)
		return (error_code);
	if (error_code < 0)

	if (error_code < 20)
		return (error_manager_init(error_code));
	return (0);
}