/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:17:48 by akassous          #+#    #+#             */
/*   Updated: 2024/06/27 13:20:22 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sub_whileloop(char t[10], int n, int i)
{
	while (i < n)
	{
		t[i] = t[i - 1] + 1;
		i++;
	}
	if (t[0] <= '9' - n)
	{
		t[n] = ',';
		t[n + 1] = ' ';
	}
	else
	{
		t[n] = '\0';
	}
}

void	whileloop(char t[10], int n)
{
	int	i;

	while (1)
	{
		if (t[n] == ',')
			write(1, t, n + 2);
		else
			write(1, t, n);
		i = n - 1;
		while (i >= 0 && t[i] == '9' - (n - 1 - i))
		{
			i--;
		}
		if (i < 0)
			break ;
		t[i]++;
		i++;
		sub_whileloop(t, n, i);
	}
}

void	ft_print_combn(int n)
{	
	char	t[10];
	int		i;

	i = 0;
	if (n < 1 || n > 9)
		return ;
	while (i < n)
	{
		t[i] = '0' + i;
		i++;
	}
	t[n] = ',';
	t[n + 1] = ' ';
	whileloop(t, n);
}
