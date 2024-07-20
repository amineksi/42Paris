/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:19:09 by akassous          #+#    #+#             */
/*   Updated: 2024/07/11 15:46:54 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	get_length(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == 43 || str[i] == 45
			|| ((str[i]) >= 9 && str[i] <= 13) || str[i] == ' ')
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

unsigned int	from_to_10(char *nbr, char *base_from)
{
	unsigned int	n;
	unsigned int	nb;
	unsigned int	i;
	int				val;

	nb = 0;
	i = 0;
	while (nbr[i])
	{
		n = 0;
		while (base_from[n] != 0 && base_from[n] != nbr[i])
			n++;
		if (base_from[n] == nbr[i])
			val = n;
		else
			val = -1;
		if (val == -1 || val >= get_length(base_from))
			return (nb);
		nb = (get_length(base_from) * nb) + val;
		i++;
	}
	return (nb);
}

char	*base10_to_to(unsigned int nbr, char *base_to, int n)
{
	unsigned int	l;
	unsigned int	tmp;
	char			*str;
	int				zero;

	zero = (nbr == 0);
	l = 1 + (n == -1 && zero != 1);
	tmp = nbr / get_length(base_to);
	while (tmp != 0)
	{
		l++;
		tmp /= get_length(base_to);
	}
	str = (char *) malloc (l + 1);
	if (str == 0)
		return (0);
	str[l] = '\0';
	while (l--)
	{
		str[l] = base_to[nbr % get_length(base_to)];
		nbr /= get_length(base_to);
	}
	if (n == -1 && zero != 1)
		str[0] = '-';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	base_f_l;
	unsigned int	base_f_to;
	unsigned int	n;
	unsigned int	i;
	unsigned int	nb;

	n = 1;
	i = 0;
	base_f_l = get_length(base_from);
	base_f_to = get_length(base_to);
	if (base_f_l == 0 || base_f_to == 0)
		return (0);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			n *= -1;
		i++;
	}
	nb = from_to_10(&nbr[i], base_from);
	return (base10_to_to(nb, base_to, n));
}

/*#include <stdio.h>

int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}*/