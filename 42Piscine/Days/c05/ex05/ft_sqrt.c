/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:59:04 by akassous          #+#    #+#             */
/*   Updated: 2024/07/09 07:13:19 by akassous         ###   ########.fr       */
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
