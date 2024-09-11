/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:04:42 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 17:59:45 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    get_on_top(t_list **stack, t_list *cheapest, int a)
{
	while (*stack != cheapest)
	{
		if (cheapest->above_median)
		{
			if (a)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (a)
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void    rotation_to_top(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
    if (cheapest->above_median == cheapest->target_node->above_median)
    {
        while (*stack_a != cheapest->target_node && *stack_b != cheapest)
        {
            if (cheapest->above_median && cheapest->target_node->above_median)
                rr(stack_a, stack_b);
            else if (!cheapest->above_median && !cheapest->target_node->above_median)
                rrr(stack_a, stack_b);
        }
    }
    get_on_top(stack_a, cheapest->target_node, 1);
    get_on_top(stack_b, cheapest, 0);
}

void    move_nodes(t_list **stack_a, t_list **stack_b)
{
    t_list  *cheapest;

    cheapest = get_cheapest(stack_b);
    rotation_to_top(stack_a, stack_b, cheapest);
    pa(stack_a, stack_b);
}