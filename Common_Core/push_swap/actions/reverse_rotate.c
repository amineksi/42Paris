/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:51:32 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 14:37:45 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



static int	rrotate_elements(t_list **stack)
{
	t_list	*last_stack;
	t_list	*prev_last_stack;

	if (!*stack || !(*stack)->next)
		return (0);
	prev_last_stack = *stack;
	last_stack = prev_last_stack->next;
	while (last_stack->next)
	{
		prev_last_stack = prev_last_stack->next;
		last_stack = last_stack->next;
	}
	prev_last_stack->next = NULL;
	last_stack->next = *stack;
	*stack = last_stack;
	return (1);
}

int	rra(t_list **stack)
{
	if (!rrotate_elements(stack))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **stack)
{
	if (!rrotate_elements(stack))
		return (0);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	rrotate_elements(stack_a);
	rrotate_elements(stack_b);
	write(1, "rrr\n", 4);
	return (1);
}
