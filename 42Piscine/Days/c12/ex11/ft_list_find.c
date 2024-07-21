#include "ft_list.h"

t_list	*ft_list_find(t_list *begin, void *data_ref, int (*cmp)())
{
	while (begin)
	{
		if ((*cmp)(begin->data, data_ref) == 0)
			return begin;
		begin = begin->next;
	}
	return 0;
}
