/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:42:11 by amine             #+#    #+#             */
/*   Updated: 2024/08/05 02:30:59 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size)
	{
		while (count < size - 1 && src[count])
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	length;

	length = ft_strlen(s);
	cpy = malloc(length + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s, length + 1);
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	length;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(length);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new_str);
}
