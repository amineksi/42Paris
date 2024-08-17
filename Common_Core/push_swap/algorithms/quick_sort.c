/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:46:21 by amine             #+#    #+#             */
/*   Updated: 2024/08/17 21:53:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = low;
	j = high;
	pivot = tab[low];
	while (i < j)
	{
		while (tab[i] <= pivot && i <= high - 1)
			i++;
		while (tab[j] > pivot && j >= low + 1)
			j--;
		if (i < j)
			swap(&tab[i], &tab[j]);
	}
	swap(&tab[low], &tab[j]);
	return (j);
}
void	quick_sort(int *tab, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition(tab, low, high);
		quick_sort(tab, low, i - 1);
		quick_sort(tab, i + 1, high);
	}
}

int	*copy_stack_values(t_list *stack)
{
	int		*tab;
	int		i;
	t_list *cpy;

	cpy = stack;
	i = 0;
	tab = malloc (sizeof(int) * ft_lstsize(cpy));
	if (!tab)
		return (0); //add error
	while (cpy)
	{
		tab[i++] = cpy->value;
		cpy = cpy->next;
	}
	return (tab);
}

void	add_index_to_stack(t_list *stack, int *tab)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (tab[i] != stack->value)
			i++;
		stack->index = i;
		stack = stack->next;
	}
}
