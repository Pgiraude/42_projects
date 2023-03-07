/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/16 13:52:40 by pgiraude         ###   ########.fr       */
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
        listA->target_pos = 0;
        listA->get_pb = false;
        listA->move = false;
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
        ft_printf(" get_pb=");
        if (list->get_pb == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" move=");
        if (list->move == true)
            ft_printf("true");
        else
            ft_printf("false");
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
        ft_printf(" get_pb=");
        if (list->get_pb == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" move=");
        if (list->move == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf("\n");
        list = list->next;
    }
}

void    push_swap(DDList *ALL)
{
    

    set_all_cell(ALL);
    get_final_pos(ALL);
    algo_1step(ALL);
    // algo_2step(ALL);
    
    check_allvalue(ALL);
}