/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prgm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:01:57 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 21:56:42 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ajout_vals(char *str, char **values, int i, int j)
{
	int	idx;
	int	max;

	max = get_max_int(str);
	max /= 4;
	idx = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			values[i][j] = str[idx];
			j++;
			idx += 2;
		}
		values[i][j] = '\0';
		i++;
	}
}

void	init_vals(char *str, char **values)
{
	int	max;
	int	i;
	int	j;

	max = get_max_int(str);
	max /= 4;
	i = 0;
	j = 0;
	while (i < max)
	{
		values[i] = (char *) malloc (max * sizeof(char) + 1);
		if (!values)
		{
			free_tab(values);
			return ;
		}
		i++;
	}
	i = 0;
	ajout_vals(str, values, i, j);
}

void	init_tab(char *str, char **tab)
{	
	int	max;
	int	i;
	int	j;

	max = get_max_int(str) / 4;
	i = -1;
	while (++i < max)
	{
		tab[i] = (char *) malloc (max * sizeof(char) + 1);
		if (!tab)
		{
			free_tab(tab);
			return ;
		}
	}
	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
			tab[i][j] = '0';
	}
}
