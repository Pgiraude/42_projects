/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 15:18:01 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainlist.h"

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

Bool    is_empty_List(List *L)
{
    if (L)
        return (false);
    else
        return (true);
}

List    *addat_List(List *L, int data, int pos)
{
    List *prec = L;
    List *cur = L;
    int i;

    i = 0;
    Cell *cell = create_Cell(data);
    if (is_empty_List(L) == true)
        return (cell);
    else if (pos == 0)
    {
        cell->next = L;
        return (cell);
    }
    while (i < pos)
    {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cell;
    cell->next = cur;

    return (L); 
}

void print_List(List *L)
{
    while (is_empty_List(L) == false)
    {
        printf("[%d] ", L->data);
        L = L->next;
    }
}

List    *free_List(List *L)
{
    List *tmp = NULL;
    while (L)
    {
        tmp = L->next;
        free (L);
        L = tmp;
    }
    return (NULL);
}

int len_List(List *L)
{
    int i;

    i = 0;
    while (L != NULL)
    {
        i++;
        L = L->next;
    }
    return (i);
}

void    *getAt(List *L, int pos)
{
    int i;

    i = 0;
    if (is_empty_List(L) == true)
        return (NULL);
    while (i < pos)
    {
        i++;
        L = L->next; 
    }
    return (L->data);
}

void    setAt(List *L, int data, int pos)
{
    int i;

    i = 0;
    if (is_empty_List(L) == true)
        return (NULL);
    while (i < pos)
    {
        i++;
        L = L->next;
    }
    L->data = data;
}

List *freeAt(List *L, int pos)
{
    List *prec = L;
    List *cur = L;
    int i;

    i = 0;
    if (is_empty_List(L) == true)
        return (NULL);
    else if (pos == 0)
    {
        L = L->next;
        free (cur);
        return (L);
    }
    if (pos > len_List(L))// protection
        return (NULL);
    while (i < pos)
    {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cur->next;
    free (cur);

    return (L);
}