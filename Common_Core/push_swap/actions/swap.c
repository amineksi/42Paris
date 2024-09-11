/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:54:15 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 01:42:43 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap_elements(t_list **stack)
{
	t_list		*first_stack;
	t_list		*stack_next;
	int			tmp;

	first_stack = *stack;
	stack_next = first_stack->next;
	if (!first_stack || !stack_next)
		return (0);
	tmp = first_stack->value;
	first_stack->value = stack_next->value;
	stack_next->value = tmp;
	return (1);
}

int	sa(t_list **stack)
{
	if (!swap_elements(stack))
		return (0);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list **stack)
{
	if (!swap_elements(stack))
		return (0);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	swap_elements(stack_a);
	swap_elements(stack_b);
	write(1, "ss\n", 3);
	return (1);
}
