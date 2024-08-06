/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:22:04 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 22:14:18 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	processing(const char *str, va_list args, int i)
{
	if (str[i] == 'c')
		return (ft_printc(va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_prints(va_arg(args, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_printi(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	else if (str[i] == '%')
		return (ft_printc('%'));
	else if (str[i] == 'x')
		return (ft_printx(va_arg(args, unsigned int)));
	else if (str[i] == 'X')
		return (ft_print_upperx(va_arg(args, unsigned int)));
	else if (str[i] == 'p')
		return (ft_printp(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	length = 0;
	if (!str)
		return (-1);
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += processing(str, args, i + 1);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			length++;
		}
	}
	va_end(args);
	return (length);
}
