#include "ft_list.h"

 int    ft_strcmp(void *data1, void *data2)
{
    return (*(int *)data1 - *(int *)data2);
}

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
