
#include "../../include/chainlist.h"

int	ft_size_list(t_list *list)
{
	int	size_list;

	size_list = 0;
	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		list = list->next;
		size_list++;
	}
	return (size_list);
}

t_list	*ft_create_list(t_list *new_list, void *data)
{
	if (!new_list)
	{
		new_list = malloc(sizeof(t_list));
		if (!new_list)
			return (NULL);
		new_list->next = NULL;
		new_list->data = data;
	}
	return (new_list);
}

t_list	*ft_add_cell_list(t_list *list, void *data, int	pos)
{
	t_list	*new_node;
	t_list	*tmp;

	if (list == NULL)
		list = ft_create_list(list, data);
	else
	{
		new_node = NULL;
		new_node = ft_create_list(new_node, data);
		if (pos == 0)
		{
			new_node->next = list;
			return (new_node);
		}
		else
		{
			tmp = list;
			while (tmp->next != NULL && pos-- != 0)
				tmp = tmp->next;
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}
	return (list);
}

t_list	*ft_suppr_cell_list(t_list *list, void **data_from_cell, int pos)
{
	t_list	*tmp;
	t_list	*tmp_b;

	if (list == NULL)
		return (list);
	tmp = list;
	if (pos == 0)
		list = list->next;
	else
	{
		tmp_b = list;
		while (tmp->next != NULL && pos-- != 0)
			tmp = tmp->next;
		while (tmp_b->next != tmp && tmp_b->next != NULL)
			tmp_b = tmp_b->next;
		tmp_b->next = tmp->next;
		if (ft_size_list(list) == 1)
			list = NULL;
	}
	*data_from_cell = tmp->data;
	tmp->next = NULL;
	free (tmp);
	return (list);
}
