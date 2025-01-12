/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:03:25 by akassous          #+#    #+#             */
/*   Updated: 2025/01/12 12:56:25 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	matching_size(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (!map[i + 1])
		{
			if ((int) ft_strlen(map[i++]) + 1 != size)
				return (0);
		}
		else if ((int) ft_strlen(map[i++]) != size)
			return (0);
	}
	return (1);
}
