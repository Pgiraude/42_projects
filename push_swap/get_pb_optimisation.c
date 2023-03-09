/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pb_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:51:38 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 20:33:26 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    costa_getup_la(DList *ListA)
{
    List *cell;
    int paire;
    int i;

    paire = 0;
    if (ListA->len % 2 == 0)
        paire = 1;
    cell = ListA->first;
    i = 0;
    while (cell != NULL)
    {
        cell->moveA = false;
        if (i <= ListA->len / 2)
            cell->costA = i;
        if (i == ListA->len / 2 && paire == 1)
            cell->moveA = true;
        if (i > ListA->len / 2)
            cell->costA = i - ListA->len;
        i++;
        cell = cell->next;
    }
}

int    get_pb_tag(List *pivot, DDList *ALL)
{
    int last_pos;
    int i;
    int nbr_pb;

    i = 1;
    nbr_pb = 0;
    ft_printf("yes\n");
    if (pivot == NULL)
        return (nbr_pb);
    
    last_pos = pivot->target_pos;
    while (i++ < ALL->La->len)
    {
        if (pivot->next == NULL)
            pivot = ALL->La->first;
        else
            pivot = pivot->next;
        if (pivot->target_pos == (last_pos + 1)
            || (last_pos == ALL->La->len && pivot->target_pos == 1))
            last_pos = pivot->target_pos;
        else
        {
            nbr_pb++;
            pivot->tag = true;
        }
    }
    if (pivot->next == NULL)
        pivot = ALL->La->first;
    else
        pivot = pivot->next;
    ft_printf("pivot = %d\n", pivot->data);
    return (nbr_pb);
}

int get_pb_score(List *pivot, DDList *ALL)
{
    int i;
    int score;
    int save_target_pos;

    i = 1;
    score = 0;
    save_target_pos = pivot->target_pos;
    while (i++ <= ALL->La->len)
    {
        if (pivot->next == NULL)
            pivot = ALL->La->first;
        else
            pivot = pivot->next;
        if (pivot->target_pos == (save_target_pos + 1)
            || (save_target_pos == ALL->La->len && pivot->target_pos == 1))
        {
            save_target_pos = pivot->target_pos;
            score++;
        }
    }
    return (score);
}

int    get_pb_optimisation(DDList *ALL)
{
    List *cell;
    List *pivot;
    int best_score;
    int score;

    pivot = NULL;
    best_score = 0;
    cell = ALL->La->first;
    while (cell != NULL)
    {   
        score = get_pb_score(cell, ALL);
        if (score > best_score)
        {
            best_score = score;
            pivot = cell;
        }
        cell = cell->next;        
    }
    if (best_score == ALL->max_len)
        return (0);
    return (get_pb_tag(pivot, ALL));
}