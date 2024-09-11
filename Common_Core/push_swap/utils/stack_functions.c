/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:50:21 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 14:27:38 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_lowest_on_top(t_list **stack_a)
{
	t_list	*min_stack;

	min_stack = get_min_stack(stack_a);
	while (*stack_a != min_stack)
	{
		if (min_stack->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

t_list	*get_min_stack(t_list **stack)
{
	t_list		*tmp;
	t_list		*min_node;

	tmp = *stack;
	min_node = tmp;
	while (tmp)
	{
		if (tmp->value < min_node->value)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

t_list	*get_max_stack(t_list **stack)
{
	t_list		*tmp;
	t_list		*max_node;

	tmp = *stack;
	max_node = tmp;
	while (tmp)
	{
		if (tmp->value > max_node->value)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

int	get_cost(t_list *stack, int size)
{
	if (stack->above_median)
		return (stack->index);
	else
		return (size - stack->index);
}

t_list	*get_cheapest(t_list **stack)
{
	t_list	*head;
	t_list	*rslt;

	head = *stack;
	rslt = head;
	while (head)
	{
		if (rslt->push_cost > head->push_cost)
			rslt = head;
		head = head->next;
	}
	return (rslt);	
}

int	diff(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}
