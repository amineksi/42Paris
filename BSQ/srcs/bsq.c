/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:25:43 by akassous          #+#    #+#             */
/*   Updated: 2024/07/16 19:25:43 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/point.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	case_stdin(void)
{
	t_map	*map;

	map = read_map_from_stdin();
	if (!map)
	{
		ft_puterror("error\n");
		exit(1);
	}
	find_biggest_square(map);
	write(1, "\n", 1);
	print_map(map);
	free_map(map);
}

void	case_other(int argc, char **argv)
{
	t_map	*map;
	int		i;

	i = 1;
	while (i < argc)
	{
		map = read_map_from_file(argv[i]);
		if (!map)
		{
			ft_puterror("map error\n");
			i++;
			continue ;
		}
		find_biggest_square(map);
		print_map(map);
		if (i != argc - 1)
			write(1, "\n", 1);
		free_map(map);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		case_stdin();
	else
		case_other(argc, argv);
	return (0);
}
