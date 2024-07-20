/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:58:25 by akassous          #+#    #+#             */
/*   Updated: 2024/07/02 20:16:04 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	same_char(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < get_length(str))
	{
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	err(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	while_loop(unsigned int nbr, char *base, unsigned int len_base)
{
	if (nbr >= len_base)
	{
		while_loop(nbr / len_base, base, len_base);
		while_loop(nbr % len_base, base, len_base);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	len_base;

	if (get_length(base) <= 1 || same_char(base) == 0 || err(base) == 0)
		return ;
	else
	{
		len_base = get_length(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = -nbr;
		}
		else
			n = nbr;
		while_loop(n, base, len_base);
	}
}
