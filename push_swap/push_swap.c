/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/01 12:27:48 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    reset_Dlist(DList *La, DList *Lb, DList *Move)
// {
//     if (Move->len == 0)
//         return ;
//     if (Move->last->data == pa)
//         All_move(La, Lb, pb);
//     if (Move->last->data == pb)
//         All_move(La, Lb, pa);
//     if (Move->last->data == sa)
//         All_move(La, Lb, sa);
//     if (Move->last->data == ra)
//         All_move(La, Lb, rra);
//     if (Move->last->data == rb)
//         All_move(La, Lb, rrb);
// }

// Bool    check(DDList *ALL)
// {
//     List *A;
//     List *S;
//     int i;

//     A = ALL->La->first;
//     S = ALL->Solution->first;
//     if (ALL->La->len != ALL->Solution->len)
//         return (false);
//     i = 1;
//     while (i <= ALL->Solution->len)
//     {
//         if (A->data != S->data)
//             return (false);
//         A = A->next;
//         S = S->next;
//         i++;
//     }
//     ALL->found_sol = true;
//     return (true);
// }

// int pb_recursive(DDList *ALL)
// {
//     int move;

//     if (ALL->pa == true)
//     {
//         ALL->pa == false;
//         return (-1);
//     }
//     if (ALL->Lb->len == ALL->max_len)
//         return (-1);
//     move = All_move(ALL->La, ALL->Lb, pb);
//     if (move == -1)
//         return (-1);
//     ALL->sa = false;
//     ALL->sb = false;
//     ALL->ra = false;
//     ALL->rb = false;
//     ALL->rr = false;
//     ALL->rra = false;
//     ALL->rrb = false;
//     ALL->rrr = false;

//     ALL->pb = true;
//     ALL->Move = insert_data_Dlist(ALL->Move, pb, 1);
//     return (move);
// }

// int pa_recursive(DDList *ALL)
// {
//     int move;

//     if (ALL->pb == true)
//     {
//         ALL->pb == false;
//         return (-1);
//     }
//     if (ALL->La->len == ALL->max_len)
//         return (-1);
//     move = All_move(ALL->La, ALL->Lb, pa);
//     if (move == -1)
//         return (-1);
//     ALL->sa = false;
//     ALL->sb = false;
//     ALL->ra = false;
//     ALL->rb = false;
//     ALL->rr = false;
//     ALL->rra = false;
//     ALL->rrb = false;
//     ALL->rrr = false;

//     ALL->pa = true;

//     ALL->Move = insert_data_Dlist(ALL->Move, pa, 1);
//     check(ALL);
//     return (move);
// }

// int sa_recursive(DDList *ALL)
// {
//     int move;

//     if (ALL->sa == true)
//     {
//         ALL->sa == false;
//         return (-1);
//     }
//     move = All_move(ALL->La, ALL->Lb, sa);
//     if (move == -1)
//         return (-1);
//     ALL->pa = false;
//     ALL->pb = false;
//     ALL->ra = false;
//     ALL->rr = false;
//     ALL->rra = false;
//     ALL->rrr = false;

//     ALL->sa = true;

//     ALL->Move = insert_data_Dlist(ALL->Move, sa, 1);
//     check(ALL);
//     return (move);
// }

// int ra_recursive(DDList *ALL)
// {
//     int move;

//     if (ALL->rra == true)
//     {
//         ALL->rra == false;
//         return (-1);
//     }
//     move = All_move(ALL->La, ALL->Lb, ra);
//     if (move == -1)
//         return (-1);

//     ALL->pa = false;
//     ALL->pb = false;
//     ALL->sa = false;
//     ALL->rr = false;
//     ALL->rrr = false;


//     ALL->ra = true;
//     ALL->Move = insert_data_Dlist(ALL->Move, ra, 1);
//     check(ALL);
//     return (move);
// }

// int rb_recursive(DDList *ALL)
// {
//     int move;

//     if (ALL->rrb == true)
//     {
//         ALL->rra == false;
//         return (-1);
//     }
//     move = All_move(ALL->La, ALL->Lb, ra);
//     if (move == -1)
//         return (-1);

//     ALL->pa = false;
//     ALL->pb = false;
//     ALL->sb = false;
//     ALL->rr = false;
//     ALL->rrr = false;


//     ALL->ra = true;
//     ALL->Move = insert_data_Dlist(ALL->Move, ra, 1);
//     check(ALL);
//     return (move);
// }

// void    recursive(DDList * ALL, int max_profondeur)
// {
//     static int      profondeur;
//     static int      sol;
//     int             move;
//     List *tmp;

//     profondeur++;
//     if (profondeur <= max_profondeur)
//     {
//         // RA
//         if (ALL->found_sol == false)
//         {
//             move = ra_recursive(ALL);
//             if (ALL->found_sol == true)
//                 return ;
//             if (move != -1)
//             {
//                 // ft_printf("good here\n");
//                 recursive(ALL, max_profondeur);
//             }
//         }

//         // RB
//         if (ALL->found_sol == false)
//         {
//             move = rb_recursive(ALL);
//             if (ALL->found_sol == true)
//                 return ;
//             if (move != -1)
//             {
//                 // ft_printf("good here\n");
//                 recursive(ALL, max_profondeur);
//             }
//         }

//         // SA
//         // if (ALL->found_sol == false)
//         // {
//         //     move = sa_recursive(ALL);
//         //     if (ALL->found_sol == true)
//         //         return ;
//         //     if (move != -1)
//         //         recursive(ALL, max_profondeur);
//         // }

//         // PB
//         if (ALL->found_sol == false)
//         {
//             move = pb_recursive(ALL);
//             if (ALL->found_sol == true)
//                 return ;
//             if (move != -1)
//                 recursive(ALL, max_profondeur);
//         }

//         // PA
//         if (ALL->found_sol == false)
//         {
//             move = pa_recursive(ALL);
//             if (ALL->found_sol == true)
//                 return ;
//             if (move != -1)
//                 recursive(ALL, max_profondeur);
//         }
        
//     }

//     // Reset if not found sol
//     if (ALL->found_sol == false)
//     {
//         reset_Dlist(ALL->La, ALL->Lb, ALL->Move);
//         if (ALL->Move->len > 0)
//         {
//             tmp = isolate_cell_Dlist(ALL->Move, 1);
//             free (tmp);
//         }
//         profondeur--;
//     }
// }



// void    algo(DDList *ALL)
// {
//     int max_profondeur;

//     ALL->max_len = ALL->La->len;
//     ALL->pa = false;
//     ALL->pb = false;
//     ALL->sa = false;
//     ALL->sb = false;
//     ALL->ss = false;
//     ALL->ra = false;
//     ALL->rra = false;
//     ALL->rb = false;
//     ALL->rrb = false;
//     ALL->rr = false;
//     ALL->rrr = false;
//     ALL->found_sol = false;
//     if (check(ALL))
//         return ;
//     max_profondeur = 1;
//     while (ALL->Move->len == 0)
//     {
//         recursive(ALL, max_profondeur);
//         ft_printf("loop n°%d\n", max_profondeur);
//         max_profondeur++;
//     }
// }