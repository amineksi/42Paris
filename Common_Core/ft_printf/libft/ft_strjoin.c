/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:37:47 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 22:33:40 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(length * sizeof(char));
	if (!new_str)
		return (0);
	if (s1)
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcpy(&new_str[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (new_str);
}
