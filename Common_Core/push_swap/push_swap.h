/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:21:45 by amine             #+#    #+#             */
/*   Updated: 2024/08/15 15:43:24 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int					value;
	struct s_list		*next;
}			t_list;

int		check_error(int argc, char **argv);
void	free_stack(t_list **stack);

long	ft_atoi(char *str);
int		ft_isdigit(int c);

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);

int		sa(t_list **stack);
int		sb(t_list **stack);
int		ss(t_list **stack_a, t_list **stack_b);

int		ra(t_list **stack);
int		rb(t_list **stack);
int		rr(t_list **stack_a, t_list **stack_b);

int		rra(t_list **stack);
int		rrb(t_list **stack);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif