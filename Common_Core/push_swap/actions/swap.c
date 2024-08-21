/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:54:15 by amine             #+#    #+#             */
/*   Updated: 2024/08/21 02:42:10 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap_elements(t_list **stack)
{
	t_list		*stack_next;
	int			tmp;
	int			tmp_idx;

	if (ft_lstsize(*stack) < 2)
		return (0);
	stack_next = *stack;
	tmp = stack_next->value;
	tmp_idx = stack_next->index;
	stack_next->index = stack_next->next->index;
	stack_next->value = stack_next->next->value;
	stack_next->next->index = tmp_idx;
	stack_next->next->value = tmp;
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
