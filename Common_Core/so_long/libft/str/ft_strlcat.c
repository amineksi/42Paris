/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:02:32 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 17:11:00 by amine            ###   ########.fr       */
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
	j = 0;
	if (!size)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	if (i < size)
		dst[i] = '\0';
	if (dst_init_l > size)
		return (size + ft_strlen(src));
	else
		return (dst_init_l + ft_strlen(src));
}
