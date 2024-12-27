/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:55:51 by amine             #+#    #+#             */
/*   Updated: 2024/12/26 18:48:22 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*get_next_line(int fd, int freeing)
{
	static char		*buffer;
	char			*line;

	if (freeing == 1)
		return (free_buffer(buffer));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	buffer = read_file_to_content(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_full_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = update_content(buffer, ft_strlen(line));
	return (line);
}
