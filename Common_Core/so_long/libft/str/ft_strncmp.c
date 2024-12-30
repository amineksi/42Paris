/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:27:14 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 19:47:17 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	if (!length)
		return (0);
	i = 0;
	while (i < length && first[i] && second[i])
	{
		if (first[i] != second[i] || i == length - 1)
			return (first[i] - second[i]);
		i++;
	}
	return (first[i] - second[i]);
}
