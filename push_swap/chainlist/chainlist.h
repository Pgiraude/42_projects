/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 15:17:40 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINLIST_H
# define CHAINLIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct Cellule
{
    int data;
    struct Cellule *next;
}List, Cell;

typedef enum
{
    false,
    true
}Bool;

Bool    is_empty_List(List *L);
List    *create_List(void);
List    *addat_List(List *L, int data, int pos);
void    print_List(List *L);
int     len_List(List *L);
List    *free_List(List *L);
void    *getAt(List *L, int pos);
void    setAt(List *L, int data, int pos);
List    *freeAt(List *L, int pos);

#endif