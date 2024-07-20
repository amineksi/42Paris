/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:25:39 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 20:43:22 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row_left(char **tab, char **values, int row, int max)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = '0';
	visible = '0';
	i = 0;
	while (i < max)
	{
		if (tab[row][i] > max_height)
		{
			max_height = tab[row][i];
			visible++;
		}
		i++;
	}
	return (visible == values[2][row]);
}

int	check_row_right(char **tab, char **values, int row, int max)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = '0';
	visible = '0';
	i = max - 1;
	while (i >= 0)
	{
		if (tab[row][i] > max_height)
		{
			max_height = tab[row][i];
			visible++;
		}
		i--;
	}
	return (visible == values[3][row]);
}

int	check_col_up(char **tab, char **values, int col, int max)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = '0';
	visible = '0';
	i = 0;
	while (i < max)
	{
		if (tab[i][col] > max_height)
		{
			max_height = tab[i][col];
			visible++;
		}
		i++;
	}
	return (visible == values[0][col]);
}

int	check_col_down(char **tab, char **values, int col, int max)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = '0';
	visible = '0';
	i = max - 1;
	while (i >= 0)
	{
		if (tab[i][col] > max_height)
		{
			max_height = tab[i][col];
			visible++;
		}
		i--;
	}
	return (visible == values[1][col]);
}

int	is_valid(char **tab, char **values, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (!check_row_left(tab, values, i, max)
			|| !check_row_right(tab, values, i, max)
			|| !check_col_up(tab, values, i, max)
			|| !check_col_down(tab, values, i, max))
			return (0);
		i++;
	}
	return (1);
}
