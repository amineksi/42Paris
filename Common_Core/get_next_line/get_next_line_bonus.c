/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:59:37 by amine             #+#    #+#             */
/*   Updated: 2024/11/25 03:02:08 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_all(char *tmp, char *buffer)
{
	free(tmp);
	free(buffer);
	return (NULL);
}

char	*get_full_line(char *content)
{
	int		i;
	char	*line;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = malloc ((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, content, i + 1);
	return (line);
}

char	*update_content(char *content, int line_length)
{
	char	*new_content;
	int		old_length;

	old_length = ft_strlen(content);
	if (line_length < old_length)
		new_content = ft_strdup(content + line_length);
	else
		new_content = ft_strdup("");
	free(content);
	content = new_content;
	return (content);
}

char	*read_file_to_content(char *buffer, int fd)
{
	char	*new_content;
	char	*tmp;
	int		bytes_read;

	tmp = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read <= 0 && !buffer[0]))
			return (free_all(tmp, buffer));
		tmp[bytes_read] = '\0';
		new_content = ft_strjoin(buffer, tmp);
		free(buffer);
		buffer = new_content;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[NB_FILES];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_file_to_content(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = get_full_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = update_content(buffer[fd], ft_strlen(line));
	return (line);
}
