/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:39:39 by amine             #+#    #+#             */
/*   Updated: 2024/08/16 19:26:34 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	algo_31_min(t_list **stack_a)
{
	t_list	*cpy;

	cpy = *stack_a;
	if (cpy->value > cpy->next->next->value)
		ra(stack_a);
	else
		sa(stack_a);
}

static	void	algo_32_min(t_list **stack_a)
{
	t_list	*cpy;

	cpy = *stack_a;
	if (cpy->value > cpy->next->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
		rra(stack_a);
}

void	algo_3(t_list **stack_a, t_list **stack_b)
{
	if (!get_min_stack(stack_a))
	{
		pb(stack_b, stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
	else if (get_min_stack(stack_a) == 1)
		algo_31_min(stack_a);
	else
		algo_32_min(stack_a);
}

void	algo_4_5(t_list **stack_a, t_list **stack_b)
{
	int	min;

	while (ft_lstsize(*stack_b) != 2)
	{
		min = get_min_stack(stack_a);
		if (min < ft_lstsize(*stack_a) / 2)
		{
			while (get_min_stack(stack_a))
				ra(stack_a);
		}
		else
		{
			while (get_min_stack(stack_a))
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	simple_algorithm(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
