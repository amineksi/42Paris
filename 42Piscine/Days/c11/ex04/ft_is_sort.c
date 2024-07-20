/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:16:21 by akassous          #+#    #+#             */
/*   Updated: 2024/07/11 09:31:49 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	diff(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		decroi;

	decroi = 2;
	i = 0;
	while (i + 1 < length)
	{
		if (decroi == 2)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				decroi = 0;
			if (f(tab[i], tab[i + 1]) > 0)
				decroi = 1;
		}
		if (f(tab[i], tab[i + 1]) < 0 && decroi == 1)
			return (0);
		if (f(tab[i], tab[i + 1]) > 0 && decroi == 0)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main()
{
	int tab[] = {4,5,9,2};
	printf("%d",ft_is_sort(tab, 4, &diff));
}*/