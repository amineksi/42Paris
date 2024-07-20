/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:19 by akassous          #+#    #+#             */
/*   Updated: 2024/07/10 20:28:09 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*tab2;

	i = 0;
	tab2 = (int *) malloc (sizeof(int) * length);
	if (tab2 == 0)
		return (0);
	while (i < length)
	{
		tab2[i] = f(tab[i]);
		i++;
	}
	return (tab2);
}

/*int addition(int x)
{
	
	return x + 5;
}

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
int	main()
{
	int tab[] = {5,2};
	int *x;
	x = ft_map(tab, 2, &addition);
	ft_putnbr(x[1]);
}*/