/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:37:51 by amine             #+#    #+#             */
/*   Updated: 2024/08/16 18:35:25 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate_elements(t_list **stack)
{
	t_list	*tmp;
	t_list	*new;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = *stack;
	new = ft_lstnew(tmp->value);
	if (!new)
		return (0);
	*stack = tmp->next;
	ft_lstadd_back(stack, new);
	free(tmp);
	return (1);
}

int	ra(t_list **stack)
{
	if (!rotate_elements(stack))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_list **stack)
{
	if (!rotate_elements(stack))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	rotate_elements(stack_a);
	rotate_elements(stack_b);
	write(1, "rr\n", 3);
	return (1);
}
