/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 18:40:05 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int data;
    
    if (is_arg_error(argc, argv))
    {
        ft_printf("Error\n");
        return (EXIT_FAILURE);
    }
    
    DList *Pile_a;
    Pile_a = create_Dlist();

    i = 1;
    while (i < argc)
    {
        data = ft_atoi(argv[i]);
        Pile_a = insert_last_Dlist(Pile_a, data);
        i++;
    }
    printf_Dlist(Pile_a);

    // while (i <= argc)
    // {
    //     
    // }


}
    