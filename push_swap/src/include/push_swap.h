/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 13:23:44 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef enum e_move
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
}t_move;

typedef enum e_bool
{
	false,
	true
}t_bool;

typedef struct s_cell
{
	int				data;
	int				cost_a;
	int				cost_b;
	int				final_pos;
	int				bonus_cost;
	t_bool			tag;
	t_bool			move_a;
	t_bool			move_b;
	struct s_cell	*next;
	struct s_cell	*back;
}t_cell;

typedef struct s_list
{
	int				len;
	struct s_cell	*first;
	struct s_cell	*last;
}t_list;

typedef struct s_ctrl
{
	int				max_len;
	struct s_list	*list_a;
	struct s_list	*list_b;
	struct s_list	*move;
}t_ctrl;

t_bool	is_error(char **str_values);
void	ft_print_allmove(t_list *move);
void	quick_sort(t_list *A);

void	swap_move(t_list *list);
void	rup_move(t_list *list);
void	push_move(t_list *src, t_list *dest);
void	rdo_move(t_list *list);
int		all_move(t_list *list_a, t_list *list_b, t_move mode);

void	push_swap(t_ctrl *all, char **values);

void	push_to_b(t_ctrl *all);
int		push_to_b_optimisation(t_ctrl *all);
int		get_score(t_cell *target, t_cell *compare, int max_len, int mode);
void	costa_getup_la(t_list *ListA);
void	costb_getposition_la(t_list *list_a, t_list *list_b, t_ctrl *all);
void	get_all_cost(t_ctrl *all);
int		is_paire(int len);
void	calculate_bonus_cost(t_ctrl *all);
int		get_score(t_cell *target, t_cell *compare, int max_len, int mode);
t_bool	check_is_aligned(t_cell *targ, t_cell *comp, int max_len, int mode);
void	push_to_a(t_ctrl *all);

void	placeup_target_lista(t_ctrl *all, t_cell *target);
void	place_target_listb(t_ctrl *all, t_cell *target);

t_bool	bigswap_optimisation(t_ctrl *all);
t_bool	swap_optimisation(t_ctrl *all);

t_list	*create_list(t_list *list);
t_list	*duplicate_list(t_list *list);
t_list	*insert_data_list(t_list *list, int data, int mode);
t_bool	is_empty_list(t_list *list);
void	free_all_list(t_list *list);
t_cell	*isolate_cell_list(t_list *list, int Mode);
t_list	*insert_cell_list(t_list *list, t_cell *cell, int mode);

char	**get_values(int argc, char **argv);
void	free_str_values(char **values);

void	get_final_pos(t_ctrl *all);
void	set_all_cell(t_ctrl *all);
void	set_all_list(t_ctrl *all);

#endif