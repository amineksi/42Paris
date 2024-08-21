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

#include <limits.h>

int find_position_of_smallest_index(t_list *stack) {
    int min_index = INT_MAX;
    int min_position = 0;
    int position = 0;

    t_list *current = stack;
    while (current) {
        if (current->index < min_index) {
            min_index = current->index;
            min_position = position;
        }
        position++;
        current = current->next;
    }
    return min_position;
}


// Rotate stack_a to bring the element at the given position to the top
void bring_to_top_a(t_list **stack_a, int position) {
    int size = ft_lstsize(*stack_a); // Assuming stack_size returns the number of elements in the stack

    if (position <= size / 2) {
        while (position-- > 0)
            ra(stack_a);  // Rotate up to bring it to the top
    } else {
        position = size - position;
        while (position-- > 0)
            rra(stack_a);  // Reverse rotate to bring it to the top
    }
}

// Sort stack_a using stack_b
void sort_stack(t_list **stack_a, t_list **stack_b) {
    int size = ft_lstsize(*stack_a);

    while (size-- > 0) {
        int pos = find_position_of_smallest_index(*stack_a);
        bring_to_top_a(stack_a, pos);
        pb(stack_b, stack_a);  // Push the smallest element to stack_b
    }
    // Now push everything back from stack_b to stack_a
    while (*stack_b) {
        pa(stack_a, stack_b);
    }
}

void	large_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	*tab;

	tab = copy_stack_values(*stack_a);
	quick_sort(tab, 0, ft_lstsize(*stack_a) - 1);
	add_index_to_stack(*stack_a, tab);
	sort_stack(stack_a, stack_b);
	free(tab);
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