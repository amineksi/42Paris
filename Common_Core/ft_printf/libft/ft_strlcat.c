/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:02:32 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 00:03:25 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_init_l;

	dst_init_l = ft_strlen(dst);
	i = 0;
	j = dst_init_l;
	if (size == 0 || size <= dst_init_l)
		return (size + ft_strlen(src));
	while (src[i] && i < size - dst_init_l - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(src) + dst_init_l);
}
