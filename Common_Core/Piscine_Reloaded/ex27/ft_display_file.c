/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:35:42 by amine             #+#    #+#             */
/*   Updated: 2024/08/01 02:06:38 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_display_file(char *file)
{
	char	buffer[4096];
	int		length;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	length = read(fd, buffer, 4096);
	if (length > 0)
	{
		buffer[length] = '\0';
		while (buffer[i])
			write(1, &buffer[i++], 1);
		write(1, "\n", 1);
	}
	close(fd);
	return (1);
}
