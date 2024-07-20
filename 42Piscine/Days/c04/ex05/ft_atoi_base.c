/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:13:19 by akassous          #+#    #+#             */
/*   Updated: 2024/07/07 23:00:13 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	error(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (get_length(str) <= 1)
		return (1);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		if (str[i] == 43 || str[i] == 45)
			return (1);
		if ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}

int	dig(char c, char *base)
{
	int	j;

	j = 0;
	while (j < get_length(base))
	{	
		if (c == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	convert_base(char *str, char *base)
{
	int	i;
	int	b;
	int	val;

	i = 0;
	val = 0;
	b = get_length(base);
	while (dig(str[i], base) < b && dig(str[i], base) != -1 && str[i])
	{
	val *= b;
	val += dig(str[i], base);
	i++;
	}
	return (val);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;

	if (error(base) == 1)
		return (0);
	i = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	return (n * convert_base(&str[i], base));
}
/*
#include <stdio.h>
int	main()
{
	char base16[] = "0123456789ABCDEF";
	char integer[] = "-FF";
	printf("%d\n", ft_atoi_base(integer, base16));
			}*/
