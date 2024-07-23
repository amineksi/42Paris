#include "ft_list.h"
#include <stdio.h>

void	swap(t_list *a, t_list *b)
{
	void *tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*next_node;
	int sorted;

	if (!begin_list || !*begin_list)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		current = *begin_list;
		while (current->next)
		{
			next_node = current->next;
			if (cmp(current->data, next_node->data) > 0)
			{
				swap(current, next_node);
				sorted = 0;	
			}
			current = current->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;

	if (!*begin_list1)
		*begin_list1 = begin_list2;
	
	else
	{
		current = *begin_list1;
		while (current->next)
			current = current->next;
		if (begin_list2)
		{
			current->next = begin_list2;
			ft_list_sort(begin_list1, cmp);
		}
	}
}
