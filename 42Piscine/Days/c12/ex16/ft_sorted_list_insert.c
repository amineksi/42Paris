#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}
 
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem = ft_create_elem(data);
	t_list	*current;

	if (!elem)
		return ;
	if (!*begin_list || (*cmp)((*begin_list)->data, elem->data) > 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
	}
	else
	{
		current = *begin_list;
		while (current->next && cmp(current->next->data, elem->data) <= 0)
			current = current->next;
		elem->next = current->next;
		current->next = elem; 
	}
}
