/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:51:19 by akassous          #+#    #+#             */
/*   Updated: 2024/06/27 14:39:12 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	c;
	
	c = 0;
	c = *a;
	*a = *b;
	*b = c;
	char x = c + '\0';
	write(1, &x, 1);
}

int main(){
int a = 5; int b = 10;
int *x = &a;int *y = &b;

ft_swap(x, y);
}
