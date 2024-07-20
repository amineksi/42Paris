/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:56:28 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 21:55:12 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_all(char **values, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(values[i]);
		free(tab[i]);
		i++;
	}
	free(values);
	free(tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	char	**tab;
	char	**values;
	int		max;

	if (argc != 2 || error(argv[1]) == 0)
		write(2, "Error\n", 6);
	else
	{
		max = get_max_int(argv[1]) / 4;
		tab = (char **) malloc (max * sizeof(char *) + 1);
		if (!tab)
			return (free(tab), 1);
		values = (char **) malloc (4 * sizeof(char *) + 1);
		if (!values)
			return (free(values), 1);
		init_vals(argv[1], values);
		init_tab(argv[1], tab);
		if (base_algorithm(tab, values, 0, 0))
			ft_print(tab, get_max_int(tab[0]));
		else
			write(2, "Error\n", 6);
		free_all(values, tab);
	}
	return (0);
}
