/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 17:47:47 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainlist.h"

Bool    is_empty_Dlist(DList *L)
{
    if (L)
        return (false);
    else
        return (true);
}

int first_Dlist(DList *L)
{
    if (is_empty_Dlist(L))
        return (0); //modifier -> pour l instant evite error
    return (L->first->data);
}

int last_Dlist(DList *L)
{
    if (is_empty_Dlist(L))
        return (0); //modifier -> pour l instant evite error
    return (L->last->data);
}

DList   *create_Dlist(DList *List)
{
    DList *L;

    if (is_empty_Dlist(List))
    {
        L = malloc(sizeof(*L));
        if (!L)
            return (NULL);
        L->len = 0;
        L->first = NULL;
        L->last = NULL;
        return (L);
    }
    return (List);
}

DList   *insertlast_data_Dlist(DList *L, int data)
{
    List *cell;
    cell = malloc(sizeof(*cell));
    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    cell->back = NULL;
    if (is_empty_Dlist(L))
    {

        L = create_Dlist(L);
        L->first = cell;
        L->last = cell;
    }
    else
    {
        L->last->next = cell;
        cell->back = L->last;
        L->last = cell;
    }
    L->len++;
    return (L);
}

DList   *insertfirst_data_Dlist(DList *L, int data)
{
    List *cell;

    cell = malloc(sizeof(*cell));
    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    cell->back = NULL;
    if (is_empty_Dlist(L) || L->len == 0)
    {
        L = create_Dlist(L);
        L->first = cell;
        L->last = cell;
    }
    else
    {
        L->first->back = cell;
        cell->next = L->first;
        L->first = cell;
    }
    L->len++;
    return (L);
}


DList   *insert_data_Dlist(DList *L, int data, int mode)
{
    if (mode == 0)
        return(insertfirst_data_Dlist(L, data));
    else
        return(insertlast_data_Dlist(L, data));
}



DList   *free_first_Dlist(DList *L)
{
    List *tmp = L->first;
    
    if (is_empty_Dlist(L))
        return (NULL);
    if (L->first == L->last)
    {
        free(L);
        L = NULL;
        return (NULL);
    }
    
    L->first = L->first->next;
    L->first->back = NULL;
    tmp->next = NULL;
    free (tmp);
    tmp = NULL;
    L->len--;
    return (L);
}

DList   *free_last_Dlist(DList *L)
{
    List *tmp = L->last;
    
    if (is_empty_Dlist(L))
        return (NULL);
    if (L->first == L->last)
    {
        free(L);
        L = NULL;
        return (NULL);
    }
    
    L->last = L->last->back;
    L->last->next = NULL;
    tmp->back = NULL;
    free (tmp);
    tmp = NULL;
    L->len--;
    return (L);
}

void    printf_Dlist(DList *L)
{
    if (is_empty_Dlist(L))
        return ;
    List *tmp = L->first;

    while(tmp != NULL)
    {
        ft_printf("[%d] ", tmp->data);
        tmp = tmp->next;
    }
}

int len_Dlist(DList *L)
{
    if (is_empty_Dlist(L))
        return (0);
    return (L->len);
}


/* partie sans double chainage */

// Bool    is_empty_List(List *L)
// {
//     if (L)
//         return (false);
//     else
//         return (true);
// }

// List    *create_Cell(int data)
// {
//     List *cell;
//     cell = malloc(sizeof(*cell));
//     if (!cell)
//         return (NULL);
//     cell->data = data;
//     cell->next = NULL;
//     cell->back = NULL;
//     return (cell);
// }

// DList    *addat_List(DList *L, int data, int pos)
// {
//     List *prec = L;
//     List *cur = L;
//     List *suiv = L;
//     int i;

//     i = 0;
//     List *cell = create_Cell(data);
//     if (is_empty_List(L) == true)
//         return (cell);
//     else if (pos == 0)
//     {
//         cell->next = L;
//         return (cell);
//     }
//     while (i < pos)
//     {
//         i++;
//         prec = cur;
//         cur = cur->next;
//     }
//     prec->next = cell;
//     cell->next = cur;

//     return (L); 
// }


// List    *addat_List(List *L, int data, int pos)
// {
//     List *prec = L;
//     List *cur = L;
//     int i;

//     i = 0;
//     List *cell = create_Cell(data);
//     if (is_empty_List(L) == true)
//         return (cell);
//     else if (pos == 0)
//     {
//         cell->next = L;
//         return (cell);
//     }
//     while (i < pos)
//     {
//         i++;
//         prec = cur;
//         cur = cur->next;
//     }
//     prec->next = cell;
//     cell->next = cur;

//     return (L); 
// }

// void print_List(List *L)
// {
//     while (is_empty_List(L) == false)
//     {
//         printf("[%d] ", L->data);
//         L = L->next;
//     }
// }

// List    *free_List(List *L)
// {
//     List *tmp = NULL;
//     while (L)
//     {
//         tmp = L->next;
//         free (L);
//         L = tmp;
//     }
//     return (NULL);
// }



// void    *getAt(List *L, int pos)
// {
//     int i;

//     i = 0;
//     if (is_empty_List(L) == true)
//         return (NULL);
//     while (i < pos)
//     {
//         i++;
//         L = L->next; 
//     }
//     return (L->data);
// }

// void    setAt(List *L, int data, int pos)
// {
//     int i;

//     i = 0;
//     if (is_empty_List(L) == true)
//         return (NULL);
//     while (i < pos)
//     {
//         i++;
//         L = L->next;
//     }
//     L->data = data;
// }

// List *freeAt(List *L, int pos)
// {
//     List *prec = L;
//     List *cur = L;
//     int i;

//     i = 0;
//     if (is_empty_List(L) == true)
//         return (NULL);
//     else if (pos == 0)
//     {
//         L = L->next;
//         free (cur);
//         return (L);
//     }
//     if (pos > len_List(L))// protection
//         return (NULL);
//     while (i < pos)
//     {
//         i++;
//         prec = cur;
//         cur = cur->next;
//     }
//     prec->next = cur->next;
//     free (cur);

//     return (L);
// }