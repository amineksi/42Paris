/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:34:09 by akassous          #+#    #+#             */
/*   Updated: 2024/07/18 10:59:36 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_atoi(char *str);
void		ft_putnbr(int nb);
void		addition(int nb1, int nb2);
void		sub(int nb1, int nb2);
void		mult(int nb1, int nb2);
void		div(int nb1, int nb2);
void		modulo(int nb1, int nb2);

int	get_number(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nbr *= 10;
			nbr += (str[i] - '0');
		}
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign * nbr);
}

int	is_sign(char *str)
{
	if (!(str[0] == 43 || str[0] == 45 || str[0] == 47
			|| str[0] == 37 || str[0] == 42) || str[1] != '\0')
	{
		write(1, "0", 1);
		return (0);
	}
	return (1);
}

int	conditions(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	if (!is_sign(argv[2]))
		return (0);
	if ((argv[2][0] == 37 || argv[2][0] == 47) && get_number(argv[3]) == 0)
	{
		if (argv[2][0] == 37)
			write(1, "Stop : modulo by zero", 21);
		else
			write(1, "Stop : division by zero", 23);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	void	(*op[5])(int, int);

	op[0] = addition;
	op[1] = sub;
	op[2] = modulo;
	op[3] = div;
	op[4] = mult;
	if (!conditions(argc, argv))
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[2][0] == '+')
		op[0](ft_atoi(argv[1]), ft_atoi(argv[3]));
	if (argv[2][0] == '-')
		op[1](ft_atoi(argv[1]), ft_atoi(argv[3]));
	if (argv[2][0] == '%')
		op[2](ft_atoi(argv[1]), ft_atoi(argv[3]));
	if (argv[2][0] == '/')
		op[3](ft_atoi(argv[1]), ft_atoi(argv[3]));
	if (argv[2][0] == '*')
		op[4](ft_atoi(argv[1]), ft_atoi(argv[3]));
	write(1, "\n", 1);
	return (1);
}
