/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 13:37:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_all_cell(DDList *ALL)
{
    List *listA;

    listA = ALL->La->first;
    ALL->max_len = ALL->La->len;
    while(listA != NULL)
    {
        listA->costA = 0;
        listA->costB = 0;
        listA->bonus_cost = 0;
        listA->target_pos = 0;
        listA->tag = false;
        listA->moveA = false;
        listA->moveB = false;
        listA->aligne_back = false;
        listA->aligne_next = false;
        listA = listA->next;
    }
}

void    get_final_pos(DDList *ALL)
{
    List *listA;
    List *listS;
    int target_pos;

    listA = ALL->La->first;
    while (listA != NULL)
    {
        target_pos = 1;
        listS = ALL->Solution->first;
        while (listA->data != listS->data)
        {
            target_pos++;
            listS = listS->next;
        }
        listA->target_pos = target_pos;
        listA = listA->next;
    }
}

void    check_allvalue(DDList *ALL)
{
    List *list;

    list = ALL->La->first;
    ft_printf("ListA\n");
    while (list != NULL)
    {
        ft_printf("data=%d target_pos=%d costA=%d costB=%d", list->data, list->target_pos, list->costA, list->costB);
        ft_printf(" aligne_back=");
        if (list->aligne_back == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" aligne_next=");
        if (list->aligne_next == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" tag=");
        if (list->tag == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" moveA=");
        if (list->moveA == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" moveB=");
        if (list->moveB == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" bonus_cost=%d", list->bonus_cost);
        ft_printf("\n");
        list = list->next;
    }

    ft_printf("ListB\n");
    list = ALL->Lb->first;
    while (list != NULL)
    {
        ft_printf("data=%d target_pos=%d costA=%d costB=%d", list->data, list->target_pos, list->costA, list->costB);
        ft_printf(" aligne_back=");
        if (list->aligne_back == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" aligne_next=");
        if (list->aligne_next == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" tag=");
        if (list->tag == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" moveA=");
        if (list->moveA == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" moveB=");
        if (list->moveB == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" bonus_cost=%d", list->bonus_cost);
        ft_printf("\n");
        list = list->next;
        
    }
}

void    push_swap(DDList *ALL)
{


    set_all_cell(ALL);
    get_final_pos(ALL);
    push_to_B(ALL);

    // while (ALL->Lb->len > 0)
    // {
        get_all_cost(ALL);
        algo_3step(ALL);
    // }

    // List *first_pos;

    // first_pos = ALL->La->first;
    // cost_getup_La(ALL->La);
    // while (first_pos->target_pos != 1)
    //     first_pos = first_pos->next;
    // placeup_target_ListA(ALL, first_pos);

    
    check_allvalue(ALL);
}