/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:50:21 by amine             #+#    #+#             */
/*   Updated: 2024/08/16 18:00:00 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_stack(t_list **stack)
{
	int		i;
	int		min;
	int		index;
	t_list	*copy;

	i = 0;
	index = 0;
	copy = *stack;
	min = copy->value;
	while (copy)
	{
		if (copy->value < min)
		{
			index = i;
			min = copy->value;
		}
		i++;
		copy = copy->next;
	}
	return (index);
}
