/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:38:39 by amine             #+#    #+#             */
/*   Updated: 2024/08/15 21:58:18 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	algo_3(t_list **stack)
{
	t_list		*biggest_node;

	if (ft_lstsize(*stack) == 2)
		sa(stack);
	else if (ft_lstsize(*stack) == 3)
	{
	biggest_node = get_max_stack(stack);
	if (biggest_node == *stack)
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	}
}

static void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*max_node;

	max_node = get_max_stack(stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (*stack_a != max_node)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
}

static void	large_algorithm(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3)
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3)
		pb(stack_b, stack_a);
	push_to_b(stack_a, stack_b);
	algo_3(stack_a);
	while (ft_lstsize(*stack_b))
	{
		init_nodes(stack_a, stack_b);
		move_nodes(stack_a, stack_b);
	}
	put_lowest_on_top(stack_a);
}

void	choose_algorithm(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		algo_3(stack_a);
	else
		large_algorithm(stack_a, stack_b);
}
