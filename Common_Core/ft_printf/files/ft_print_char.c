/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:51:20 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 18:56:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printc(int value)
{
	char		c;
	
	c = (char) value;
	write(1, &c, 1);
	return (1);
}

int	ft_printi(int value)
{
	char	*c;
	int		length;
	
	c = ft_itoa(value);
	ft_putstr(c);
	length = (int)ft_strlen(c);
	free(c);
	return (length);
}

int    ft_prints(char	*str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int		ft_printu(unsigned int value)
{
	char	*c;
	int		length;
	
	c = ft_utoa(value);
	ft_putstr(c);
	length = (int)ft_strlen(c);
	free(c);
	return (length);
}