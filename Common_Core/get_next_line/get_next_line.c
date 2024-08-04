/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:55:51 by amine             #+#    #+#             */
/*   Updated: 2024/08/04 03:26:40 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_buffer(char *buffer, int *place, int bytes_in_buffer)
{
	int		i;
	int		init_place;
	int		len;
	char	*line;

	i = *place;
	init_place = *place;
	len = 0;
	while (i < bytes_in_buffer && buffer[i] != '\n')
	{
		i++;
		len++;
	}
	if (i < bytes_in_buffer && buffer[i] == '\n')
	{
		len++;
		i++;
	}
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	ft_strlcpy(line, &buffer[init_place], len);
	*place = i;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static int		place;
	static int		bytes_read;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
			return (0);
	if (place >= bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		place = 0;
	}
	line = read_from_buffer(buffer, &place, bytes_read);
	return (line);
}
