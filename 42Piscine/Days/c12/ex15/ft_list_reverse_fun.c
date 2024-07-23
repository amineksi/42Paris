#include "ft_list.h"
#include <stdio.h>

void	swap(t_list *a, t_list *b)
{
	void *tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

int		list_length(t_list *list)
{
	int	i;

	i = 0;
	while(list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
void	ft_list_reverse_fun(t_list *begin_list)
{
    t_list  *current;
	t_list	*tmp;
	int	length;
	int	i;
	int	j;

	i = 0;
	length = list_length(begin_list);
    while(i < length / 2)
    {
		current = begin_list;
		j = 0;
		while (j < length - i)
		{
			if (j == i)
				tmp = current;
			else if (j == length - i - 1)
				swap(tmp, current);
			current = current->next;
			j++;
		}
	i++;
    }
    begin_list = current;
}

//TEST

#include "ft_list.h"
#include <stdio.h>

void	swap(t_list *a, t_list *b)
{
	void *tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

int		list_length(t_list *list)
{
	int	i;

	i = 0;
	while(list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
void	ft_list_reverse_fun(t_list *begin_list)
{
    t_list  *current;
	t_list	*tmp;
	int	length;
	int	i;
	int	j;

	i = 0;
	length = list_length(begin_list);
    while(i < length / 2)
    {
		current = begin_list;
		j = 0;
		while (j < length - i)
		{
			if (j == i)
				tmp = current;
			else if (j == length - i - 1)
				swap(tmp, current);
			current = current->next;
			j++;
		}
	i++;
    }
    begin_list = current;
}
