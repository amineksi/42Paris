#include "ft_cat.h"
# include <errno.h>
# include <string.h>

int	case_stdin()
{
	char	buffer[4096];
	int		length;

	length = read(STDIN_FILENO, buffer, 4096);
	while (length > 0)
	{
		if (write(STDOUT_FILENO, buffer, length) != length)
		{
			write(2, strerror(errno), get_length(strerror(errno)));
			return (0);
		}
		length = read(STDIN_FILENO, buffer, 4096);
	}
	return (0);
}

int case_files(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 0)
		return (0);
	while (i < argc)
	{
		if (ft_display_file(argv[i]) == 0)
		{
			write(2, "ft_cat: ", 8);
			ft_putstr(argv[i]);
			write(2, ": ", 2);
			write(2, strerror(errno), get_length(strerror(errno)));
			write(2, "\n", 1);
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (case_stdin());
	else
		return (case_files(argc, argv));
}