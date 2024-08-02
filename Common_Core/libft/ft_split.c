/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:43:48 by amine             #+#    #+#             */
/*   Updated: 2024/08/03 00:58:29 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

void	free_all(char **rslt, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(rslt[i++]);
	free(rslt);
}

void	splitting(char const *s, char **rslt, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		count = i;
		while (s[i] && s[i] != c)
			i++;
		if (count < i)
		{
			rslt[j] = malloc (sizeof(char) * (i - count + 1));
			if (!rslt[j])
			{
				free_all(rslt, j);
				rslt = NULL;
				return ;
			}
			ft_strncpy(rslt[j++], (char *)&s[count], i - count);
		}
	}
	rslt[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		length;
	int		count;
	char	**rslt;
	
	i = 0;
	length = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		count = i;
		while (s[i] && s[i] != c)
			i++;
		if (count < i)
			length++;
	}
	rslt = malloc (sizeof(char *) * (length + 1));
	if (!rslt)
		return (0);
	splitting(s, rslt, c);
	return (rslt);
}
