/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:38:13 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 19:38:33 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINLIST_H
# define  CHAINLIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}t_list;

t_list	*ft_create_list(t_list *new_list, void *data);
t_list	*ft_add_cell_list(t_list *list, void *data, int pos);
int		ft_size_list(t_list *list);
t_list	*ft_suppr_cell_list(t_list *list, void **data_from_cell, int pos);

#endif