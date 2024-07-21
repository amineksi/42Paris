#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;
	t_list	*previous;

	list = (*begin_list1);
	while (list)
	{
		previous = list;
		list = list->next;
	}
	previous->next = begin_list2;
}
