/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:13:07 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
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
}e_move;

typedef enum
{
    false,
    true
}e_bool;

typedef struct s_cell
{
    int data;
    int cost_a;
    int cost_b;
    int final_pos;
    int bonus_cost;
    e_bool aligne_back;
    e_bool aligne_next;
    e_bool tag;
    e_bool move_a;
    e_bool move_b;
    struct s_cell *next;
    struct s_cell *back;
}t_cell;

typedef struct s_list
{
    int len;
    struct s_cell *first;
    struct s_cell *last;
}t_list;

typedef struct s_ctrl
{
    int max_len;
    struct s_list *list_a;
    struct s_list *list_b;
    struct s_list *move;
}t_ctrl;

e_bool    is_error(int argc, char **argv);
void    ft_printpiles(t_list *A, t_list *B);
void    ft_print_allmove(t_list *move);
void    quick_sort(t_list *A);

void    swap_move(t_list *list);
void    rup_move(t_list *list);
void    push_move(t_list *src, t_list *dest);
void    rdo_move(t_list *list);
int     all_move(t_list *list_a, t_list * list_b, e_move mode);


void    push_swap(t_ctrl *all, int argc, char **argv);


void    push_to_b(t_ctrl *all);
int     push_to_b_optimisation(t_ctrl *all);
int     get_score(t_cell *target, t_cell *compare, int max_len, int mode);
void    costa_getup_la(t_list *ListA);
void    get_all_cost(t_ctrl *all);
void    is_aligned(t_ctrl *all);
e_bool    check_is_aligned(t_cell *target, t_cell *compare, int max_len, int mode);
void    push_to_a(t_ctrl *all);

void    placeup_target_lista(t_ctrl *all, t_cell *target);
void    place_target_listb(t_ctrl *all, t_cell *target);

e_bool    bigswap_optimisation(t_ctrl *all);
e_bool    swap_optimisation(t_ctrl *all);


/*------------------*/
t_list  *create_list(t_list *list);
t_list	*duplicate_list(t_list *list);
t_list	*insert_data_list(t_list *list, int data, int mode);
e_bool	is_empty_list(t_list *list);
void	free_all_list(t_list *list);
t_cell	*isolate_cell_list(t_list *list, int Mode);
t_list	*insert_cell_list(t_list *list, t_cell *cell, int mode);



void    printf_list(t_list *list);

#endif