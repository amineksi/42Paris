/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:30:34 by amine             #+#    #+#             */
/*   Updated: 2024/08/01 23:49:52 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && little[j] && big[i + j]
			&& big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
