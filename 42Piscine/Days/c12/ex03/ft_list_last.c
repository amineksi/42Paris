#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*list;
	while (list)
	{
		if (!list->next)
			return (list);
		list = list->next;
	}
	return 0;
}