#include <stdio.h>
#include <stdlib.h>
#include "./include/so_long.h"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}t_list;

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

t_list	*ft_add_data_list(t_list *list, void *data, int	pos)
{
	t_list	*new_node;
	t_list	*tmp;

	if (!list)
		list = ft_create_list(list, data);
	else
	{
		new_node = ft_create_list(list, data);
		if (pos == 0)
		{
			new_node->next = list;
			return (new_node);
		}
		else
		{
			tmp = list;
			while (tmp->next != NULL || pos-- == 0)
				tmp = tmp->next;
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}
	return (list);
}

t_list	*ft_suppr_data_list(t_list *list, void **data, int pos)
{
	t_list	*tmp;
	t_list	*tmp_b;

	if (!list)
		return (list);
	else
	{
		tmp = list;
		if (pos == 0)
		{
			list = list->next;
			*data = tmp->data;
			tmp->next = NULL;
			free (tmp);
		}
		else
		{
			tmp_b = list;
			while (tmp->next != NULL || (pos-- - 1) == 0)
				tmp = tmp->next;
			while (tmp_b->next != tmp)
				tmp_b = tmp_b->next;
			tmp_b->next = tmp->next;
		}
	}
	return (list);
}

int	main(void)
{
	t_list *OK;
	int	*x;
	int z;

	x = malloc(sizeof(int) * 1);
	z = 6;
	OK = NULL;
	OK = ft_create_list(OK, NULL);
	OK->data = x;

	free (OK->data);
	free (OK);
	if (!x)
		printf("END\n");

}