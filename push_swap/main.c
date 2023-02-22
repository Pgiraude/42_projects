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
    
    if (is_error(argc, argv))
    {
        ft_printf("Error\n");
        return (EXIT_FAILURE);
    }
    
    DList *Pile_a;
    DList *Pile_b;
    Pile_a = create_Dlist();
    Pile_b = create_Dlist();

    i = 1;
    while (i < argc)
    {
        data = ft_atoi(argv[i]);
        Pile_a = insert_last_Dlist(Pile_a, data);
        i++;
    }
    printf_Dlist(Pile_a);
    Pile_b = insert_last_Dlist(Pile_b, NULL);
    printf_Dlist(Pile_b);
}
    