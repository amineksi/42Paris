/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:06:46 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 20:43:38 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	placeable(char **tab, int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < get_max_int(tab[0]))
	{
		if (tab[row][i] == height + '0'
				|| tab[i][col] == height + '0')
			return (0);
		i++;
	}
	return (1);
}

int	base_algorithm(char **tab, char **values, int row, int col)
{
	int	height;

	if (row == get_max_int(tab[0]))
		return (is_valid(tab, values, get_max_int(tab[0])));
	if (col == get_max_int(tab[0]))
		return ((base_algorithm(tab, values, row + 1, 0)));
	height = 1;
	while (height <= get_max_int(tab[0]))
	{
		if (placeable(tab, row, col, height))
		{
			tab[row][col] = height + '0';
			if (base_algorithm(tab, values, row, col + 1))
				return (1);
			tab[row][col] = '0';
		}
		height++;
	}
	return (0);
}
