/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:36:57 by akassous          #+#    #+#             */
/*   Updated: 2024/07/10 20:09:52 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length && tab[i])
	{
		f(tab[i]);
		i++;
	}
}

/*#include <unistd.h>

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
int	main()
{
	int tab[] = {};
	ft_foreach(tab, 2, &ft_putnbr);
}*/