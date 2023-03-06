/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 17:34:18 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINLIST_H
# define CHAINLIST_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>



typedef struct DList
{
    int len;
    struct Cellule *first;
    struct Cellule *last;
}DList;

typedef enum
{
    false,
    true
}Bool;

typedef struct Cellule
{
    int data;
    int costA;
    int costB;
    int target_pos;
    Bool aligne_back;
    Bool aligne_next;
    Bool get_pb;
    Bool move;
    struct Cellule *next;
    struct Cellule *back;
}List;



Bool    is_empty_Dlist(DList *L);
DList   *create_Dlist(DList *L);
int     len_Dlist(DList *L);
int     first_Dlist(DList *L);
int     last_Dlist(DList *L);
DList   *insert_last_Dlist(DList *L, int data);
DList   *insert_first_Dlist(DList *L, int data);
DList   *free_first_Dlist(DList *L);
DList   *free_last_Dlist(DList *L);
void    printf_Dlist(DList *L);

DList   *insert_data_Dlist(DList *L, int data, int mode);

/* partie liste simple*/


List    *addat_List(List *L, int data, int pos);
Bool    is_empty_List(List *L);

void    print_List(List *L);
List    *free_List(List *L);
void    *getAt(List *L, int pos);
void    setAt(List *L, int data, int pos);
List    *freeAt(List *L, int pos);

#endif