/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:21:47 by amine             #+#    #+#             */
/*   Updated: 2024/08/14 02:34:15 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}
