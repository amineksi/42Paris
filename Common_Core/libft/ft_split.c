/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:43:48 by amine             #+#    #+#             */
/*   Updated: 2024/08/05 04:20:03 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t		count;
	size_t		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	void	fill_tab(char *tab, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

static void	fill_rslt(char **rslt, char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while ((s[i + count]) && s[i + count] != c)
			count++;
		if (count > 0)
		{
			rslt[j] = malloc (sizeof(char) * (count + 1));
			if (!rslt[j])
				return ;
			fill_tab(rslt[j], &s[i], c);
			j++;
			i += count;
		}
		else
			i++;
	}
	rslt[j] = 0;
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**rslt;

	words = count_words(s, c);
	rslt = malloc(sizeof(char *) * (words + 1));
	if (!rslt)
		return (0);
	fill_rslt(rslt, s, c);
	return (rslt);
}
