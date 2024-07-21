#include "ft_list.h"
#include <stdio.h>
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;

	if (size <= 0)
		return (0);
	list = ft_create_elem((void *)strs[size - 1]);
	list->next = ft_list_push_strs(size - 1, strs);
	return (list);
}