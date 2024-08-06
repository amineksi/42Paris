/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:51:20 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 01:20:36 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include <stdio.h>

void	ft_printc(va_list args)
{
	char		c;
	c = (char)va_arg(args, int);
	write(1, &c, 1);
}

void    ft_prints(va_list args)
{
    char	*str;
	char	*malloc_str;

	str = va_arg(args, char *);
	malloc_str = malloc (ft_strlen(str) + 1);
	if (!malloc_str)
		return ;
	ft_strlcpy(malloc_str, str, ft_strlen(str) + 1);
	ft_putstr(malloc_str);
	free(malloc_str);
}