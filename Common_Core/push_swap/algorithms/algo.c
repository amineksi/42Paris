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

void	large_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	t_list *tmp;

	tab = copy_stack_values(*stack_a);
	quick_sort(tab, 0, ft_lstsize(*stack_a) - 1);
	add_index_to_stack(*stack_a, tab);
	tmp = *stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->index);
		tmp = tmp->next;
	}
	if (ft_lstsize(*stack_b))
		return ;
}
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
    else
		large_algorithm(stack_a, stack_b);
}