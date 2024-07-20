/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:57:41 by akassous          #+#    #+#             */
/*   Updated: 2024/07/06 11:40:35 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa_mem(unsigned long addr)
{
	int		i;
	char	*base;
	char	tab[16];

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		tab[i] = '0';
		i++;
	}
	while (addr > 0)
	{
		tab[i] = base[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, tab, 16);
	write(1, " :", 2);
}

void	print16impr(unsigned char *tab, unsigned int i, unsigned int size)
{
	int		j;
	char	*base;

	base = "0123456789abcdef";
	j = 0;
	while (j < 16 && i + j < size)
	{
		write(1, &base[tab[i + j] / 16], 1);
		write(1, &base[tab[i + j] % 16], 1);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
}

void	print_10_value(unsigned char *tab, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (tab[i + j] >= 32 && tab[i + j] <= 126)
			write(1, &tab[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)addr;
	while (i < size)
	{
		print_hexa_mem((unsigned long)addr + i);
		print16impr(tab, i, size);
		print_10_value(tab, i, size);
		write(1, "\n", 1);
		i += 16;
	}
}
/*
int		main(void)
{
	char str[] = "Ceci est un test d'affichage de print memory!\nSegFault";
	ft_print_memory(str, 54);
}*/
