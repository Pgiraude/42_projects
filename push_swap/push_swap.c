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

// void    algo(DList *La, DList *Lb, DList *solution, DList *test)
// {
//     static int      profondeur;
//     static int     saveA;
//     static int     saveB;
//     static int      sol;
//     List *tmp;

//     profondeur++;
//     if (sol == 0 || profondeur <= 3)
//     {
//         if (La->len > 0 && saveB == 0)
//         {
//             saveA = 1;
//             P_move(La, Lb, 0);
//             insertlast_data_Dlist(test, 0);
//             algo(La, Lb, solution);
//             // ne peut pas etre la solution final
//         }
//         if (profondeur == 1)
//         {
//             tmp = isolate_cell_Dlist(test, 0);
//             free (tmp);
//         }


//         if (Lb->len > 0 && saveA == 0)
//         {
//             saveB = 1;
//             P_move(La, Lb, 1);
//             test = insertlast_data_Dlist(test, 1);
//             if (check(La, solution))
//             {
//                 sol = 1;
//                 ft_printf("Pb_move\n");
//                 return ;
//             }
//             algo(La, Lb, solution);
//         }
//         if (profondeur == 1)
//         {
//             tmp = isolate_cell_Dlist(test, 0);
//             free (tmp);
//         }


//         if (La->len > 1)
//         {
//             saveA = 0;
//             saveB = 0;
//             R_move(La, Lb, 0);
//             test = insertlast_data_Dlist(test, 2);
//             if (check(La, solution))
//             {
//                 sol = 1;
//                 ft_printf("R_move\n");
//                 return ;
//             }
//             algo(La, Lb, solution);
//         }
//     }

//     if (sol == 0)
//     {
//         reset_Dlist(La, test);
//         tmp = isolate_cell_Dlist(test, 1);
//         free (tmp);
//         profondeur--;
//     }

    
// }