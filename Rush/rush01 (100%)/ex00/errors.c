/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:55:39 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 21:20:43 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_max_int(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			j++;
		i++;
	}
	return (j);
}

int	error(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (!(len == 71 || len == 63 || len == 55 || len == 47
			|| len == 39 || len == 31 || len == 23))
		return (0);
	while (str[i])
	{
		if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '9'))
			return (0);
		else if (i % 2 == 1 && !(str[i] == ' '))
			return (0);
		i++;
	}
	if (str[i - 1] < '1' && str[i + 1] > '9')
		return (0);
	return (1);
}
