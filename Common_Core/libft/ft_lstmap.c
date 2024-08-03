/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 02:19:55 by amine             #+#    #+#             */
/*   Updated: 2024/08/03 02:44:11 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rslt;
	t_list	*new_node;

	rslt = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&rslt, del);
			return (0);
		}
		if (!rslt)
			rslt = new_node;
		else
		{
			tmp = ft_lstlast(rslt);
			tmp->next = new_node;
		}
		lst = lst->next;
	}
	return (rslt);
}
