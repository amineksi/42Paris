/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:37:47 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 17:08:02 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	length_1;
	size_t	length_2;

	length_1 = ft_strlen(s1);
	length_2 = ft_strlen(s2);
	new_str = malloc((length_1 + length_2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, length_1 + 1);
	ft_strlcat(new_str, s2, length_1 + length_2 + 1);
	return (new_str);
}
