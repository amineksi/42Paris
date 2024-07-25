#include "ft_cat.h"
#include <unistd.h>
#include <fcntl.h>

int ft_display_file(char *file)
{
	char buffer[2048];
	int length;
	int i;
	int fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	length = read(fd, buffer, 2048);
	if (length > 0)
	{
		buffer[length] = '\0';
		while (i < length)
			write(1, &buffer[i++], 1);
	}
	close (fd);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}