/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:22:04 by amine             #+#    #+#             */
/*   Updated: 2024/08/06 01:22:56 by amine            ###   ########.fr       */
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

/*void	processing(const char *str, va_list args, int i)
{
	
}*/

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
		while (str[i] && str[i] != '%')
			write(1, &str[i++], 1);
		if (str[i] == '%')
			ft_printc(args);
		i++;
	}
	va_end(args);

	return (0);
}

int main()
{
	ft_printf("xddd%s", 'c');
}