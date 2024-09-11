/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:56:55 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 14:47:12 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    current_index(t_list **stack)
{
    int     i;
    int     len;
    t_list  *head;
    
    i = 0;
    len = ft_lstsize(*stack);
    head = *stack;
    while (head)
	{
		head->index = i;
		if (i <= len /2 )
			head->above_median = 1;
		else
			head->above_median = 0;
		head = head->next;
		i++;
	}
}

void    get_target(t_list **stack_a, t_list *head_b)
{
    t_list  *head_a;
    t_list  *target;

    head_a = *stack_a;
    target = get_max_stack(stack_a);
    while (head_a)
    {
        if (head_a->value < target->value && head_a->value >= head_b->value)
            target = head_a;
        head_a = head_a->next;
    }
    head_b->target_node = target;
}

void    set_targets(t_list **stack_a, t_list **stack_b)
{
    t_list  *head_b;

    head_b = *stack_b;
    while (head_b)
    {
        get_target(stack_a, head_b);
        head_b = head_b->next;
    }
}

void    set_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	head_b = *stack_b;
	while (head_b)
	{
		head_b->push_cost = get_cost(head_b, size_b);
		if (head_b->target_node->above_median == head_b->above_median)
			head_b->push_cost += diff(get_cost(head_b, size_b), get_cost(head_b->target_node, size_a));
		else
			head_b->push_cost += get_cost(head_b->target_node, size_a);
		head_b = head_b->next;
	}
}

void init_nodes(t_list **stack_a, t_list **stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_targets(stack_a, stack_b);
    set_costs(stack_a, stack_b);
}