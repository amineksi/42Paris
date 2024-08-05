/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:59:37 by amine             #+#    #+#             */
/*   Updated: 2024/08/05 03:03:44 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_full_line(char **content)
{
	int		i;
	char	*cpy;
	char	*line;

	i = 0;
	cpy = *content;
	while (cpy[i] && cpy[i] != '\n')
		i++;
	if (cpy[i] == '\n')
		i++;
	line = malloc (i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, cpy, i + 1);
	return (line);
}

void	update_content(char **content, int line_length)
{
	char	*new_content;
	int		old_length;

	old_length = ft_strlen(*content);
	if (line_length < old_length)
		new_content = ft_strdup(*content + line_length);
	else
		new_content = ft_strdup("");
	free(*content);
	*content = new_content;
}

int	read_file_to_content(char **content, char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*new_content;

	while (!ft_strchr(*content, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == -1)
			{
				free(buffer);
				return (0);
			}
			break ;
		}
		buffer[bytes_read] = '\0';
		new_content = ft_strjoin(*content, buffer);
		if (*content)
			free(*content);
		*content = new_content;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*content[NB_FILES];
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!content[fd])
		content[fd] = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!read_file_to_content(&content[fd], buffer, fd))
		return (0);
	free(buffer);
	if (*content[fd] == '\0')
	{
		free(content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	line = get_full_line(&content[fd]);
	update_content(&content[fd], ft_strlen(line));
	return (line);
}
