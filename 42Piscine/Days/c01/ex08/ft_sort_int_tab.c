/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:56:29 by akassous          #+#    #+#             */
/*   Updated: 2024/06/28 14:55:24 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min_i = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_i])
			{
				min_i = j;
			}
			j++;
		}
		tmp = tab[min_i];
		tab[min_i] = tab[i];
		tab[i] = tmp;
		i++;
	}	
}
