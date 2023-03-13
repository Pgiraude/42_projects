/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:48:47 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "chainlist/chainlist.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef enum
{
    pa,
    pb,
    sa,
    sb,
    ss,
    ra,
    rra,
    rb,
    rrb,
    rr,
    rrr
}Move;

typedef struct DDList
{
    int max_len;
    struct DList *La;
    struct DList *Lb;
    struct DList *Solution;
    struct DList *Move;
}DDList;

Bool    is_error(int argc, char **argv);
void    ft_printpiles(DList *A, DList *B);
void    ft_printresult(DList *Move);
void    quick_sort(DList *A);
void    free_all_dlist(DList *L);

DList   *insert_cell_Dlist(DList *L, List *cell, int mode);
List    *isolate_cell_Dlist(DList *L, int Mode);

void    swap_move(DList *L);
void    rup_move(DList *L);
void    push_move(DList *src, DList *dest);
void    rdo_move(DList *L);
int     all_move(DList *La, DList * Lb, Move mode);


void    push_swap(DDList *ALL);


void    push_to_b(DDList *ALL);
int     get_pb_optimisation(DDList *ALL);

void    get_all_cost(DDList *ALL);
void    is_aligned(DDList *ALL);

void    push_to_a(DDList *ALL);


void    costa_getup_la(DList *ListA);


void    placeup_target_lista(DDList *ALL, List *target);
void    place_target_listb(DDList *ALL, List *target);


Bool    bigswap_optimisation(DDList *ALL);
Bool    swap_optimisation(DDList *ALL);

Bool    check_is_aligned(List *target, List *compare, int max_len, int mode);

int	get_score(List *target, List *compare, int max_len, int mode);

#endif