/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:27:40 by amine             #+#    #+#             */
/*   Updated: 2024/08/21 02:43:11 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_list **stack, char **argv)
{
	int			i;
	t_list		*tmp;

	i = 0;
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoi(argv[i++]));
		ft_lstadd_back(stack, tmp);
	}
}
void print_list(t_list *head)
{
    t_list *current = head;
    
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}


int main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	if (argc < 2)
		return (-1);
	if (check_error(argc, argv) || is_sorted(argv))
		return (-1);
	stack_a = malloc (sizeof(t_list));
	if (!stack_a)
		return (-1);
	init_stack(stack_a, &argv[1]);
	stack_b = malloc(sizeof(t_list));
	*stack_b = NULL;
	choose_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
