/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:24:53 by akassous          #+#    #+#             */
/*   Updated: 2024/07/09 06:58:49 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	value;

	value = 0;
	if (nb == 0)
		return (1);
	if (nb > 0)
		value = nb;
	while (nb > 1)
	{
		value *= nb - 1;
		nb--;
	}
	return (value);
}
