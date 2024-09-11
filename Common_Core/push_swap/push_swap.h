/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:21:45 by amine             #+#    #+#             */
/*   Updated: 2024/09/11 14:47:22 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int					value;
	int					index;
	int					push_cost;
	int					above_median;
	struct s_list		*target_node;
	struct s_list		*next;
}			t_list;

// CHECKING STACKS 

int		check_error(int argc, char **argv);
int		is_sorted(char **argv);

// INITIALIZATION

void	init_stack_a(t_list **stack, char **argv);

// ALGORITHMS

void	choose_algorithm(t_list **stack_a, t_list **stack_b);

// STACK GETTER

t_list	*get_min_stack(t_list **stack);
t_list	*get_max_stack(t_list **stack);
t_list	*get_cheapest(t_list **stack);

void	free_stack(t_list **stack);

void	print_list(t_list *head);

void	init_nodes(t_list **stack_a, t_list **stack_b);
void    move_nodes(t_list **stack_a, t_list **stack_b);

void    current_index(t_list **stack);
void	put_lowest_on_top(t_list **stack_a);
int		get_cost(t_list *stack, int size);
int		diff(int a, int b);


//LIBFT
long	ft_atoi(char *str);
int		ft_isdigit(int c);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

//ACTIONS
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