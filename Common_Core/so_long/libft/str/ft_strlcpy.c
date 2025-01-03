/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:43:54 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 17:09:02 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (count < size - 1 && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	if (size)
		dst[count] = '\0';
	return (ft_strlen(src));
}
