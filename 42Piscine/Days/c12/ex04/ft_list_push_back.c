#include "ft_list.h"
#include <stdlib.h>

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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
}
