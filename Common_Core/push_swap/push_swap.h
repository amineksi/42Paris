/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:21:45 by amine             #+#    #+#             */
/*   Updated: 2024/08/17 21:48:23 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
}			t_list;

int		check_error(int argc, char **argv);
int		is_sorted(char **argv);
void	free_stack(t_list **stack);

void    choose_algorithm(t_list **stack_a, t_list **stack_b);
void	simple_algorithm(t_list **stack_a, t_list **stack_b);
void	algo_3(t_list **stack_a, t_list **stack_b);
void	algo_4_5(t_list **stack_a, t_list **stack_b);

void	quick_sort(int *tab, int low, int high);
int		*copy_stack_values(t_list *stack);
void	add_index_to_stack(t_list *stack, int *tab);

int		get_min_stack(t_list **stack);

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