/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:42:11 by amine             #+#    #+#             */
/*   Updated: 2024/08/04 00:33:47 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
