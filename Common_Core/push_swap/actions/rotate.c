/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:37:51 by amine             #+#    #+#             */
/*   Updated: 2024/09/10 00:07:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate_elements(t_list **stack)
{
	t_list	*last_node;

	if (!stack)
		return (0);
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;	
	return (1);
}


int	ra(t_list **stack)
{
	if (!rotate_elements(stack))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_list **stack)
{
	if (!rotate_elements(stack))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	rotate_elements(stack_a);
	rotate_elements(stack_b);
	write(1, "rr\n", 3);
	return (1);
}
