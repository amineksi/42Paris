/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:35:53 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 12:47:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_nodes(t_list **stack, int n)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = malloc (sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
	}
}

void	init_stack_a(t_list **stack, char **argv)
{
	int			i;

	i = 0;
	while (argv[i])
		append_nodes(stack, ft_atoi(argv[i++]));
}
