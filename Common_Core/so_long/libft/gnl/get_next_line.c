/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:55:51 by amine             #+#    #+#             */
/*   Updated: 2024/12/30 02:20:04 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_to_buff(int fd, char *str)
{
	char	*buffer;
	int		rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = ft_strjoin_modified(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (str);
}

char	*get_line_buff(char *buff)
{
	int		i;
	char	*result;

	i = 0;
	if (!buff || !buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	result = malloc((i + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		result[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*update_buff(char *buff)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	result = malloc((ft_strlen(buff) - i + 1) * sizeof(char));
	if (!result)
	{
		free(buff);
		return (NULL);
	}
	i++;
	j = 0;
	while (buff[i])
		result[j++] = buff[i++];
	result[j] = '\0';
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_to_buff(fd, buff);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	result = get_line_buff(buff);
	buff = update_buff(buff);
	return (result);
}
