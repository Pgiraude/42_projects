/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chainlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 14:21:05 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainlist.h"

int main(void)
{

    List *test = create_List();

    test = addat_List(test, 10, 0);
    
    printList(test);
    printf("\n");



    
    test = addat_List(test, 9, 0);
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
    