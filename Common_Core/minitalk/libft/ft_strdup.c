/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:57:53 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 19:10:24 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
