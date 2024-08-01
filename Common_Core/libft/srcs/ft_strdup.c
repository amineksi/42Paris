/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:57:53 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 01:05:13 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;
	int		length;

	length = (int) ft_strlen(s);
	cpy = malloc(length);
	if (!cpy)
		return (0);
	while (i < ft_strlen(s))
	{
		cpy[i] = s[i];
		i++;
	}
	return (cpy);
}
