/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:47:13 by akassous          #+#    #+#             */
/*   Updated: 2024/07/10 18:25:50 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		l;
	int		*tab;

	l = max - min;
	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = (int *) malloc (l * sizeof(int));
	if (tab == 0)
	{
		*range = 0;
		return (-1);
	}
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (l);
}
