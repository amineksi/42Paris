#include "ft_list.h"

void	add(t_list **prev, t_list **current)
{
	*prev = *current;
	*current = (*current)->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, 
int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*before;
	t_list	*current;

	before = 0;
	current = *begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (before)
				before->next = current->next;
			else
				*begin_list = current->next;
			if (free_fct)
				free_fct(current->data);
			free(current);
			if (before)
				current = before->next;
			else
				current = *begin_list;
		}
		else
			add(&before, &current);
	}
}
