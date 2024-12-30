/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:04:45 by amine             #+#    #+#             */
/*   Updated: 2024/08/05 04:20:14 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*new;
	size_t		i;

	if (size != 0 && nmemb > ((size_t) -1 / size))
		return (0);
	new = (void *) malloc(size * nmemb);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}
