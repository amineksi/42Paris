/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:39:49 by amine             #+#    #+#             */
/*   Updated: 2024/07/31 23:41:49 by amine            ###   ########.fr       */
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
