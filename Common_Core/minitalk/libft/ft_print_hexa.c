/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:38:44 by amine             #+#    #+#             */
/*   Updated: 2024/09/21 20:41:57 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length_uint(unsigned int num)
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

char	*int_to_hex_min(unsigned int num)
{
	char	*hex_str;
	char	hex_chars[17];
	int		i;
	int		length;

	ft_strlcpy(hex_chars, "0123456789abcdef", 17);
	hex_str = malloc(get_length_uint(num) + 1);
	if (!hex_str)
		return (0);
	length = get_length_uint(num);
	hex_str[length] = '\0';
	i = length - 1;
	while (i >= 0)
	{
		hex_str[i] = hex_chars[num % 16];
		num /= 16;
		i--;
	}
	return (hex_str);
}

char	*int_to_hex_max(unsigned int num)
{
	char	*hex_str;
	char	hex_chars[17];
	int		i;
	int		length;

	ft_strlcpy(hex_chars, "0123456789ABCDEF", 17);
	hex_str = malloc(get_length_uint(num) + 1);
	if (!hex_str)
		return (0);
	length = get_length_uint(num);
	hex_str[length] = '\0';
	i = length - 1;
	while (i >= 0)
	{
		hex_str[i] = hex_chars[num % 16];
		num /= 16;
		i--;
	}
	return (hex_str);
}

int	ft_printx(unsigned int value)
{
	char	*c;
	int		length;

	c = int_to_hex_min(value);
	ft_putstr(c);
	length = (int) ft_strlen(c);
	free(c);
	return (length);
}

int	ft_print_upperx(unsigned int value)
{
	char	*c;
	int		length;

	c = int_to_hex_max(value);
	ft_putstr(c);
	length = (int) ft_strlen(c);
	free(c);
	return (length);
}
