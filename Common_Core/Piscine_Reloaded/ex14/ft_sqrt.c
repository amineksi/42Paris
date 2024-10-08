/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:48:02 by amine             #+#    #+#             */
/*   Updated: 2024/07/31 23:49:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	n;

	if (nb < 1)
		return (0);
	n = 1;
	while (n * n < (unsigned int) nb)
		n++;
	if (n * n == (unsigned int) nb)
		return (n);
	return (0);
}
