/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:55:51 by amine             #+#    #+#             */
/*   Updated: 2024/08/04 22:00:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fill_buffer(char *content, char *buffer)
{
	ft_bzero(buffer, BUFFER_SIZE);
	ft_strlcpy(buffer, content, BUFFER_SIZE);
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
		return (0);
	ft_strlcpy(line, cpy, i);
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

char	*get_next_line(int fd)
{
	static char		*content;
	char			*buffer;
	char			*line;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!content)
		content = ft_strdup("");
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(content, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		content = ft_strjoin(content, buffer);
	}
	free(buffer);
	if (*content == '\0')
	{
		free(content);
		return (0);
	}
	line = get_full_line(&content);
	update_content(&content, ft_strlen(line));
	return (line);
}


int main(int argc, char **argv) {
    int fd;
    char *line;

    if (argc < 2) {
        while ((line = get_next_line(STDIN_FILENO)) != NULL) {
        printf("%s", line);
        free(line);
    }
    return 0;
	}

    fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
		free(line);
    }
	free(line);
    close(fd);
    return 0;
}

/*
int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	
	return (argc);
}*/