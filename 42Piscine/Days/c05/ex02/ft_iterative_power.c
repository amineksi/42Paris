/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:53:13 by akassous          #+#    #+#             */
/*   Updated: 2024/07/04 09:41:29 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	value;
	int	idx;

	value = 1;
	idx = power;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (idx != 0)
	{
		value *= nb;
		idx--;
	}
	return (value);
}
