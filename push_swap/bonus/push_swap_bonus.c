/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:03 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:30:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int check_move(int argc, char **argv)
{
    if (ft_strncmp(test, "pa\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "pb\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "sa\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "sb\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "ss\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "ra\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "rra\n", 4) == 0)
        return (4);
    else if (ft_strncmp(test, "rb\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "rrb\n", 4) == 0)
        return (4);
    else if (ft_strncmp(test, "rr\n", 3) == 0)
        return (3);
    else if (ft_strncmp(test, "rrr\n", 4) == 0)
        return (4);
    else
        return (-1);
}

t_bool  check_error_bonus(int argc, char **argv)
{
    
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (EXIT_FAILURE);
    
}