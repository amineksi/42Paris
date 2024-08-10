/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:04:32 by amine             #+#    #+#             */
/*   Updated: 2024/08/03 01:59:01 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(unsigned int n, int sign)
{
	int	i;

	i = 1;
	if (sign == -1 && n != 0)
		i++;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*convert_str(unsigned int nbr, char *number, int sign, int length)
{
	number[length--] = '\0';
	while (nbr > 9)
	{
		number[length--] = nbr % 10 + '0';
		nbr /= 10;
	}
	number[length] = nbr + '0';
	if (sign == -1 && nbr != 0)
		number[0] = '-';
	return (number);
}

char	*ft_itoa(int n)
{
	int				length;
	int				sign;
	unsigned int	cpy;
	unsigned int	nbr;
	char			*number;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nbr = -n;
	}
	else
		nbr = n;
	cpy = nbr;
	length = get_length(cpy, sign);
	number = malloc (length + 1);
	if (!number)
		return (0);
	convert_str(nbr, number, sign, length);
	return (number);
}
