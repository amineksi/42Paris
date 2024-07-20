/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:01:46 by akassous          #+#    #+#             */
/*   Updated: 2024/07/02 16:24:47 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	tab[2];

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] > 126)
		{
			write(1, "\\", 1);
			tab[0] = "0123456789abcdef"[(unsigned char)str[i] / 16];
			tab[1] = "0123456789abcdef"[(unsigned char)str[i] % 16];
			write(1, tab, 2);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*int		main()
{
	char c[] = "Coucou\ntu vas bien ?";
	ft_putstr("Coucou\\0atu vas bien ?:");
	ft_putstr_non_printable(c);
	char d[] = "\x81\xbe";
	ft_putstr("\n\\81\\be:");
	ft_putstr_non_printable(d);
}*/
