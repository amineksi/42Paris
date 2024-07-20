/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:50:49 by akassous          #+#    #+#             */
/*   Updated: 2024/07/03 12:25:06 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

unsigned int	length_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_l;
	unsigned int	size_returned;

	i = 0;
	size_returned = length_str(src);
	dest_l = length_str(dest);
	j = dest_l;
	if (size == 0 || size <= dest_l)
		return (size_returned += size);
	while (src[i] && i < size - dest_l - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (size_returned += dest_l);
}
