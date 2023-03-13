/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 21:55:37 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    set_all_cell(t_ctrl *all)
{
    t_cell *listA;

    listA = all->list_a->first;
    all->max_len = all->list_a->len;
    while(listA != NULL)
    {
        listA->cost_a = 0;
        listA->cost_b = 0;
        listA->bonus_cost = 0;
        listA->final_pos = 0;
        listA->tag = false;
        listA->move_a = false;
        listA->move_b = false;
        listA->aligne_back = false;
        listA->aligne_next = false;
        listA = listA->next;
    }
}

static void    get_final_pos(t_ctrl *all)
{
    t_cell *listA;
    t_cell *listS;
    int final_pos;

    listA = all->list_a->first;
    while (listA != NULL)
    {
        final_pos = 1;
        listS = all->Solution->first;
        while (listA->data != listS->data)
        {
            final_pos++;
            listS = listS->next;
        }
        listA->final_pos = final_pos;
        listA = listA->next;
    }
}

static void    check_allvalue(t_ctrl *all)
{
    t_cell *list;

    list = all->list_a->first;
    ft_printf("ListA\n");
    while (list != NULL)
    {
        ft_printf("data=%d final_pos=%d cost_a=%d cost_b=%d", list->data, list->final_pos, list->cost_a, list->cost_b);
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
        ft_printf(" move_a=");
        if (list->move_a == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" move_b=");
        if (list->move_b == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" bonus_cost=%d", list->bonus_cost);
        ft_printf("\n");
        list = list->next;
    }

    ft_printf("ListB\n");
    list = all->list_b->first;
    while (list != NULL)
    {
        ft_printf("data=%d final_pos=%d cost_a=%d cost_b=%d", list->data, list->final_pos, list->cost_a, list->cost_b);
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
        ft_printf(" move_a=");
        if (list->move_a == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" move_b=");
        if (list->move_b == true)
            ft_printf("true");
        else
            ft_printf("false");
        ft_printf(" bonus_cost=%d", list->bonus_cost);
        ft_printf("\n");
        list = list->next;
        
    }
}

void    push_swap(t_ctrl *all)
{


    set_all_cell(all);
    get_final_pos(all);
    push_to_b(all);


        get_all_cost(all);
        push_to_a(all);
        get_all_cost(all);
        push_to_a(all);


    // while (all->list_b->len > 0)
    // {
    //     get_all_cost(all);
    //     push_to_a(all);
    // }

    // t_cell *first_pos;

    // first_pos = all->list_a->first;
    // costa_getup_la(all->list_a);
    // while (first_pos->final_pos != 1)
    //     first_pos = first_pos->next;
    // placeup_target_lista(all, first_pos);

    
    check_allvalue(all);
}