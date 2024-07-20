/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:23 by akassous          #+#    #+#             */
/*   Updated: 2024/07/16 12:41:43 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	n;
	unsigned char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = -1 * nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	c = n + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	final_result;

	i = 0;
	n = 1;
	final_result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final_result *= 10;
		final_result += str[i] - '0';
		i++;
	}
	return (n * final_result);
}
