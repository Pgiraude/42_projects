/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/01 16:58:50 by pgiraude         ###   ########.fr       */
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
void    free_all_Dlist(DList *L);

DList   *insert_cell_Dlist(DList *L, List *cell, int mode);
List    *isolate_cell_Dlist(DList *L, int Mode);

int    R_move(DList *La, DList *Lb, Move mode);
int    S_move(DList *La, DList *Lb, Move mode);
int    P_move(DList *La, DList *Lb, Move mode);
int    All_move(DList *La, DList * Lb, Move mode);

void    algo(DDList *ALL);
void    get_score_getup_La(DList *L);
void    push_to_b(DDList *ALL);
int    opti_pb(DDList *ALL);

void    push_swap(DDList *ALL);

void    algo_1step(DDList *ALL);

#endif