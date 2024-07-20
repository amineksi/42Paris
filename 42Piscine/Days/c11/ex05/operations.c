/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:32:48 by akassous          #+#    #+#             */
/*   Updated: 2024/07/16 12:41:44 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_putnbr(int nb);

void	addition(int nb1, int nb2)
{
	int		rslt;

	rslt = nb1 + nb2;
	ft_putnbr(rslt);
}

void	sub(int nb1, int nb2)
{
	int		rslt;

	rslt = nb1 - nb2;
	ft_putnbr(rslt);
}

void	mult(int nb1, int nb2)
{
	int		rslt;

	rslt = nb1 * nb2;
	ft_putnbr(rslt);
}

void	div(int nb1, int nb2)
{
	int		rslt;

	rslt = nb1 / nb2;
	ft_putnbr(rslt);
}

void	modulo(int nb1, int nb2)
{
	int		rslt;

	rslt = nb1 % nb2;
	ft_putnbr(rslt);
}
