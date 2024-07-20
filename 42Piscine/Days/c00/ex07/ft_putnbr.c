/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:45:58 by akassous          #+#    #+#             */
/*   Updated: 2024/07/11 16:50:56 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	value;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		value = -nb;
	}
	else
	{
		value = nb;
	}
	if (value > 9)
	{
		ft_putnbr(value / 10);
		value = value % 10;
	}
	c = value + '0';
	write(1, &c, 1);
}
