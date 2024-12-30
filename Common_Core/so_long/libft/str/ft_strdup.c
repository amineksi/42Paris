/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:57:53 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 18:30:16 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		length;

	if (!s)
		return (NULL);
	length = (int) ft_strlen(s);
	cpy = malloc((length + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s, length + 1);
	return (cpy);
}
