/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:21:29 by amine             #+#    #+#             */
/*   Updated: 2024/08/03 01:20:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	char	*s2;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i++], set))
			count++;
	}
	s2 = malloc (count + 1);
	if (!s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i++], set))
			s2[j++] = s1[i - 1];
	}
	s2[count] = '\0';
	return (s2);
}
