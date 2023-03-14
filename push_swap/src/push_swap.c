/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 13:27:27 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    set_all_list(t_ctrl *all)
{
    t_list	*list_a;
	t_list	*list_b;
	t_list	*move;

    list_a = NULL;
	list_b = NULL;
	move = NULL;
	list_a = create_list(list_a);
	list_b = create_list(list_b);
    move = create_list(move);
	all->list_a = list_a;
	all->list_b = list_b;
	all->move = move;
}

static void    set_all_cell(t_ctrl *all)
{
    t_cell *cell_a;

    cell_a = all->list_a->first;
    all->max_len = all->list_a->len;
    while(cell_a != NULL)
    {
        cell_a->cost_a = 0;
        cell_a->cost_b = 0;
        cell_a->bonus_cost = 0;
        cell_a->final_pos = 0;
        cell_a->tag = false;
        cell_a->move_a = false;
        cell_a->move_b = false;
        cell_a->aligne_back = false;
        cell_a->aligne_next = false;
        cell_a = cell_a->next;
    }
}

static void    get_final_pos(t_ctrl *all)
{
    t_list  *list_s;
    t_cell  *cell_a;
    t_cell  *cell_s;
    int     final_pos;

    list_s = duplicate_list(all->list_a);
    quick_sort(list_s);
    cell_a = all->list_a->first;
    while (cell_a != NULL)
    {
        final_pos = 1;
        cell_s = list_s->first;
        while (cell_a->data != cell_s->data)
        {
            final_pos++;
            cell_s = cell_s->next;
        }
        cell_a->final_pos = final_pos;
        cell_a = cell_a->next;
    }
    ft_printf("------\nquicksort = ");
    printf_list(list_s);
    free_all_list(list_s);
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

void    push_swap(t_ctrl *all, int argc, char **argv)
{
    int     i;

    set_all_list(all);
    i = 1;
	while (i < argc)
	{
		all->list_a = insert_data_list(all->list_a, ft_atoi(argv[i]), 1);
		i++;
	}
    set_all_cell(all);
    get_final_pos(all);

    ft_printf("len A = %d le B = %d\n", all->list_a->len, all->list_b->len);
	ft_printpiles(all->list_a, all->list_b);
	ft_printf("\n------\n");

    push_to_b(all);
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