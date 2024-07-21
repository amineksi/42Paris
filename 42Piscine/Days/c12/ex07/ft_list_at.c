#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (count < nbr && begin_list->next)
	{
			begin_list = begin_list->next;
			count++;
	}
	if (count == nbr)
		return begin_list;
}
