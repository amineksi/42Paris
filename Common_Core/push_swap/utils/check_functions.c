/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:53:37 by amine             #+#    #+#             */
/*   Updated: 2024/09/08 21:42:53 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_duplicate(int tmp, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i++]) == tmp)
		{
			printf("double");
			return (1);
		}
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if ((num[0] == '+' || num[0] == '-') && !num[1])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i++]))
			return (0);
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (is_duplicate(tmp, argv, i) || !ft_isnum(argv[i])
			|| tmp > 2147483647 || tmp < -2147483648 || argv[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (argc == 2)
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(char **argv)
{
	int	i;

	i = 2;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= ft_atoi(argv[i - 1]))
			return (0);
		i++;
	}
	return (1);
}
