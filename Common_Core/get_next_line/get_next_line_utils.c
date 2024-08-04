/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:42:11 by amine             #+#    #+#             */
/*   Updated: 2024/08/04 21:28:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_strlcpy(char *dst, const char *src, int size)
{
	int	count;

	count = 0;
	if (size)
	{
		while (count < size && src[count])
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (!c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		length;

	length = (int) ft_strlen(s);
	cpy = malloc(length + 1);
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, s, length + 1);
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(length * sizeof(char));
	if (!new_str)
		return (0);
	if (s1)
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcpy(&new_str[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (new_str);
}
