/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:51:32 by amine             #+#    #+#             */
/*   Updated: 2024/08/15 04:18:44 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	delete_last_element(t_list **head)
{
	t_list	*current;

	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	free(current->next);
	current->next = NULL;
}

static int	rrotate_elements(t_list **stack)
{
	t_list	*tmp;
	t_list	*new;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = *stack;
	new = ft_lstnew(ft_lstlast(tmp)->value);
	ft_lstadd_front(stack, new);
	delete_last_element(stack);
	return (1);
}

int	rra(t_list **stack)
{
	if (!rrotate_elements(stack))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **stack)
{
	if (!rrotate_elements(stack))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	rrotate_elements(stack_a);
	rrotate_elements(stack_b);
	write(1, "rrr\n", 4);
	return (1);
}
