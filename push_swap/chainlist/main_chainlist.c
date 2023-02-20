/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chainlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 18:56:53 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainlist.h"

int main(void)
{

    DList *test = create_List();
    test = insert_first_Dlist(test, 100);
    test = insert_first_Dlist(test, 50);
    test = insert_last_Dlist(test, 200);
    test = insert_last_Dlist(test, 400);

    test = free_first_Dlist(test);
    test = free_last_Dlist(test);

    test = insert_last_Dlist(test, 500);
    
    if (is_empty_Dlist(test))
        printf("Empty List\n");
    else
    {
        printf_Dlist(test);   
    }
    printf("\nTaille de la liste = %d\n", len_Dlist(test));

    
    // test = addat_List(test, 10, 0);
    
    // print_List(test);
    // test = free_List(test);



    
    // test = addat_List(test, 9, 0);
    // test = addat_List(test, 7, 0);
    // test = addat_List(test, 8, 1);
    // setAt(test, 20, 1);
    // test = freeAt(test, 2);
    // print_List(test);
    // printf("\n%d", getAt(test, 1));
    
    // test = addat_List(test, 8, 0);
    // printList(test);
    // test = addat_List(test, 9, 1);
    // printList(test);

    // test = freeList(test);
    // printList(test);
    // printf("%d", lenList(test));
}
    