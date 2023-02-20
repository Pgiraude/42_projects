/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 19:16:14 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINLIST_H
# define CHAINLIST_H

# include <stdio.h>
# include <stdlib.h>



typedef struct DList
{
    int len;
    struct Cellule *first;
    struct Cellule *last;
}DList;

typedef struct Cellule
{
    int data;
    struct Cellule *next;
    struct Cellule *back;
}List;

typedef enum
{
    false,
    true
}Bool;

Bool    is_empty_Dlist(DList *L);
DList   *create_List(void);
int     len_Dlist(DList *L);
int     first_Dlist(DList *L);
int     last_Dlist(DList *L);
DList   *insert_last_Dlist(DList *L, int data);
DList   *insert_first_Dlist(DList *L, int data);
DList   *free_first_Dlist(DList *L);
DList   *free_last_Dlist(DList *L);
void    printf_Dlist(DList *L);


/* partie liste simple*/


List    *addat_List(List *L, int data, int pos);
Bool    is_empty_List(List *L);

void    print_List(List *L);
List    *free_List(List *L);
void    *getAt(List *L, int pos);
void    setAt(List *L, int data, int pos);
List    *freeAt(List *L, int pos);

#endif