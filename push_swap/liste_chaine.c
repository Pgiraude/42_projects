/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chaine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/15 19:03:41 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Cell    *create_Cell(int data)
{
    Cell *cell = malloc(sizeof(Cell));
    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    return (cell);
}

List    *create_List(void)
{
    return (NULL);
}

int is_empty_List(List *List)
{
    if (List)
        return (1);
    else
        return (0);
}

List    addat_List(List *List, int data, int pos)
{
    //ft_strlen
    int *test;

    test = malloc(sizeof(data) * (1 + 1));
    if (!test)
        return (NULL);
    test[0] = data;
    test[1] = '\0';
    
    List->data = test;
}