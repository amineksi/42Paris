/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:26:11 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 22:14:33 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_length_long(unsigned long num)
{
	int	length;

	length = 1;
	while (num > 15)
	{
		num /= 16;
		length++;
	}
	return (length);
}

char	*print_hexa_mem(unsigned long addr)
{
	char	*hex_str;
	char	hex_chars[17];
	int		i;
	int		length;

	ft_strlcpy(hex_chars, "0123456789abcdef", 17);
	hex_str = malloc(get_length_long(addr) + 1);
	if (!hex_str)
		return (0);
	length = get_length_long(addr);
	hex_str[length] = '\0';
	i = length - 1;
	while (i >= 0)
	{
		hex_str[i] = hex_chars[addr % 16];
		addr /= 16;
		i--;
	}
	return (hex_str);
}

int	ft_printp(void *addr)
{
	char	*hex_str;
	int		length;

	if (!addr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex_str = print_hexa_mem((unsigned long)addr);
	write(1, "0x", 2);
	ft_putstr(hex_str);
	length = (int) ft_strlen(hex_str) + 2;
	free(hex_str);
	return (length);
}
