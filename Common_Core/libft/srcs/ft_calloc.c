/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:04:45 by amine             #+#    #+#             */
/*   Updated: 2024/08/02 00:45:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rslt;

	rslt = malloc(nmemb * size);
	if (rslt)
		ft_bzero(rslt, nmemb * size);
	return (rslt);
}