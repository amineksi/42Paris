/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:34:18 by akassous          #+#    #+#             */
/*   Updated: 2024/07/15 11:51:05 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*init_tab(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*tab;

	if (size == 0)
	{
		tab = (char *)malloc(1);
		if (tab == 0)
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	i = 0;
	length = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
		{
			length += get_length(strs[i]);
			i++;
		}
	}
	length += (size - 1) * get_length(sep);
	tab = (char *)malloc(sizeof(char) * (length) + 1);
	return (tab);
}

void	add_values(char *tab, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
		{
			j = 0;
			while (strs[i][j])
				tab[idx++] = strs[i][j++];
			if (i < size - 1)
			{
				j = 0;
				while (j < get_length(sep))
					tab[idx++] = sep[j++];
			}
		}
		i++;
	}
	tab[idx] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;

	tab = init_tab(size, strs, sep);
	if (!tab)
		return (NULL);
	add_values(tab, strs, sep, size);
	return (tab);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%s\n",  ft_strjoin(argc, argv, "___x"));
}*/
