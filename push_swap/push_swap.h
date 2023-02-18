/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:08 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/16 19:49:20 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

struct user
{
    int numero;
};

struct Test
{
    int Hp;
    int Mp;
    struct user prenom;
};

typedef struct Test joueur;


typedef struct Cellule
{
    long long int data;
    struct Cellule *next;
}List, Cell;

int     is_empty_List(List *List);
List    *create_List(void);
List    addat_List(List *List, int data, int pos);

#endif