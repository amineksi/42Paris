/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:50:15 by amine             #+#    #+#             */
/*   Updated: 2024/08/11 13:28:14 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(char *str)
{
	long	i;
	long	min;
	long	rslt;

	i = 0;
	min = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rslt *= 10;
		rslt += str[i++] - '0';
	}
	return (rslt * min);
}
