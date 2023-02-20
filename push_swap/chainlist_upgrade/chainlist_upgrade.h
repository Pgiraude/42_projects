/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist_upgrade.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/20 13:41:22 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINLIST_UPGRADE_H
# define CHAINLIST_UPGRADE_H

# include <stdio.h>
# include <stdlib.h>

typedef struct Cellule
{
    void *data;
    struct Cellule *next;
}List, Cell;

typedef enum
{
    false,
    true
}Bool;

Bool    is_empty_List(List *L);
List    *create_List(void);
List    *addat_List(List *L, void *data, int pos);
void    printList(List *L);
int     lenList(List *L);
List    *freeList(List *L);

#endif