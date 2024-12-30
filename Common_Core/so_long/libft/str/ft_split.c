/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:43:48 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 17:19:14 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	rslt;

	i = 0;
	rslt = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			rslt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (rslt);
}

static int	word_length(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

static char	**free_rslt(char **rslt, int i)
{
	while (i >= 0)
		free(rslt[i--]);
	free(rslt);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**rslt;

	rslt = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!rslt)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (!s[j])
			break ;
		rslt[i++] = ft_substr(s, j, word_length(s, c, j));
		if (!rslt[i - 1])
			return (free_rslt(rslt, i - 2));
		while (s[j] && s[j] != c)
			j++;
	}
	rslt[i] = NULL;
	return (rslt);
}
