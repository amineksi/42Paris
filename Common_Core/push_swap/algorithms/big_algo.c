/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:39:59 by amine             #+#    #+#             */
/*   Updated: 2024/08/21 03:45:22 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_insert_position(t_list *stack_b, int index)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = stack_b;
	while (current)
	{
		if (current->index > index)
			break ;
		pos++;
		current = current->next;
	}
	return (pos);
}

static void	bring_to_top_b(t_list **stack_b, int position)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (position <= size / 2)
	{
		while (position-- > 0)
			rb(stack_b);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(stack_b);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	pos;

	while (*stack_a)
	{
		index = (*stack_a)->index;
		pos = find_insert_position(*stack_b, index);
		bring_to_top_b(stack_b, pos);
		pb(stack_b, stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
