/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:56:15 by akassous          #+#    #+#             */
/*   Updated: 2024/06/30 15:05:17 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8'))
	{
		write(1, ", ", 2);
	}
}

void	whileloop(char a, char b, char c, char d)
{
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = a;
			d = b + 1;
			while (c <= '9')
			{
				while (d <= '9')
				{
					print_combination(a, b, c, d);
					d++;
				}
				c++;
				d = '0';
			}
			b++;
		}
		a++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	whileloop(a, b, c, d);
}

int main(){ft_print_comb2();return 4;}
