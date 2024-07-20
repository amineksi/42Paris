/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:48:22 by akassous          #+#    #+#             */
/*   Updated: 2024/07/10 10:56:03 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int	char_detected(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	add_tab(char **tab, char *str, char *charset)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && char_detected(str[i], charset))
			i++;
		count = i;
		while (str[i] && !char_detected(str[i], charset))
			i++;
		if (i > count)
		{
			tab[j] = (char *) malloc (sizeof(char) * (i - count + 1));
			if (tab[j] == 0)
				return ;
			ft_strncpy(tab[j], &str[count], i - count);			
			j++;
		}
	}
	tab[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;
	int		count;
	int		length;

	i = 0;
	length = 0;
	while (str[i])
	{
		while (str[i] && char_detected(str[i], charset))
			i++;
		count = i;
		while (str[i] && !char_detected(str[i], charset))
			i++;
		if (i > count)
			length++;
	}
	tab = (char **) malloc (sizeof(char *) * (length + 1));
	if (tab == 0)
		return (0);
	add_tab(tab, str, charset);
	return (tab);
}

int    main(int ac, char **av)
{
    int i;
    char **bat;

	i = 0;
    bat = ft_split(av[1], av[2]);
    while (bat[i])
    {
        printf("%s", bat[i++]);
		printf("\n");		
    }
	return (ac);
}