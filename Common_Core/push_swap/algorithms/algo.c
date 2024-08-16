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

void	simple_algorithm(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		algo_3(stack_a, stack_b);
	else
        algo_4_5(stack_a, stack_b);
}

void    choose_algorithm(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) <= 5)
        simple_algorithm(stack_a, stack_b);
    // else huge algorithm
}