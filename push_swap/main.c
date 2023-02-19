/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/16 19:49:29 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create(joueur *lol)
{
    (*lol).Hp = 12;
    lol->Mp = 50;
    
}


int main(void)
{
    // joueur t1 = {0, 0, 0};
    
    // create(&t1);
    // printf("Test Hp = %d Mp = %d\n", t1.Hp, t1.Mp);
    
    // t1.prenom.numero = 12;
    // printf("Test numero = %d\n", t1.prenom.numero);

    List *test = create_List();
    test = addat_List(test, 10, 0);
    printList(test);
    test = addat_List(test, 8, 0);
    printList(test);
    test = addat_List(test, 9, 1);
    printList(test);

    test = freeList(test);
    printList(test);
    printf("%d", lenList(test));
}
