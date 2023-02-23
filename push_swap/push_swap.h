/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 18:17:38 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "chainlist/chainlist.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

Bool    is_error(int argc, char **argv);
void    ft_printpiles(DList *A, DList *B);
void    quick_sort(DList *A);
void    free_all_Dlist(DList *L);

DList   *insert_cell_Dlist(DList *L, List *cell, int mode);
List    *isolate_cell_Dlist(DList *L, int Mode);

void    p_move(DList *src, DList *dest);

#endif