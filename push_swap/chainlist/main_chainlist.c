/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chainlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 15:17:14 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainlist.h"

int main(void)
{

    List *test = create_List();

    test = addat_List(test, 10, 0);
    
    print_List(test);
    printf("\n");
    test = free_List(test);



    
    test = addat_List(test, 9, 0);
    test = addat_List(test, 7, 0);
    test = addat_List(test, 8, 1);
    setAt(test, 20, 1);
    test = freeAt(test, 2);
    print_List(test);
    printf("\n%d", getAt(test, 1));
    
    // test = addat_List(test, 8, 0);
    // printList(test);
    // test = addat_List(test, 9, 1);
    // printList(test);

    // test = freeList(test);
    // printList(test);
    // printf("%d", lenList(test));
}
    