/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:39:39 by amine             #+#    #+#             */
/*   Updated: 2024/08/16 18:17:50 by amine            ###   ########.fr       */
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

static	void	algo_3(t_list **stack_a, t_list **stack_b)
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

void	simple_algorithm(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		algo_3(stack_a, stack_b);
	else if (ft_lstsize(*stack_b))
		return ;
}