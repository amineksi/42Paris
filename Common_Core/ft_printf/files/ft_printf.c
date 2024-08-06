/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:22:04 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 03:09:25 by amine            ###   ########.fr       */
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

void	processing(const char *str, va_list args, int i)
{
	if (str[i] == 'c')
		ft_printc(va_arg(args, int));
	if (str[i] == 's')
		ft_prints(va_arg(args, char *));

}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			processing(str, args, i + 1);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);

	return (0);
}

int main()
{
	ft_printf("XD");
}