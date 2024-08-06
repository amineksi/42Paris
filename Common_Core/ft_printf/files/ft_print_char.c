/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:51:20 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 03:03:34 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include <stdio.h>

void	ft_printc(int value)
{
	char		c;
	
	c = (char) value;
	write(1, &c, 1);
}

void    ft_prints(char	*str)
{
	if (!ft_strlen(str))
	{
		write(1, "(null)", 6);
		return ;
	}
	write(1, str, ft_strlen(str));
}