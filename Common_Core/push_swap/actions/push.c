/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:31:53 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 01:54:32 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push_element(t_list **src, t_list **dst)
{
	t_list	*tmp;
	t_list	*src_head;
	t_list	*dst_head;

	if (!ft_lstsize(*src))
		return (0);
	src_head = *src;
	dst_head = *dst;
	tmp = src_head;
	src_head = src_head->next;
	*src = src_head;
	if (!dst)
	{
		dst_head = tmp;
		dst_head->next = NULL;
		*dst = dst_head;
	}
	else
	{
		tmp->next = dst_head;
		*dst = tmp;
	}
	return (1);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (!push_element(stack_b, stack_a))
		return (0);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_list **stack_b, t_list **stack_a)
{
	if (!push_element(stack_a, stack_b))
		return (0);
	write(1, "pb\n", 3);
	return (1);
}
