/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:22:43 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 00:01:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	*str;

	str = (char *)s;
	last = 0;
	while (*str)
	{
		if (*str == c)
			last = str;
		str++;
	}
	return (last);
}
