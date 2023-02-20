/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chainlist_upgrade.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 13:47:25 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainlist_upgrade.h"

int main(void)
{
    // joueur t1 = {0, 0, 0};
    
    // create(&t1);
    // printf("Test Hp = %d Mp = %d\n", t1.Hp, t1.Mp);
    
    // t1.prenom.numero = 12;
    // printf("Test numero = %d\n", t1.prenom.numero);

    char *data;
    data = "salut";

    List *test = create_List();

    test = addat_List(test, data, 0);
    
    printList(test);
    printf("\n");



    
    test = addat_List(test, "oups", 0);
    printList(test);
    // printf("%s", (char *)getAt(test, 0));
    
    // test = addat_List(test, 8, 0);
    // printList(test);
    // test = addat_List(test, 9, 1);
    // printList(test);

    // test = freeList(test);
    // printList(test);
    // printf("%d", lenList(test));
}
    