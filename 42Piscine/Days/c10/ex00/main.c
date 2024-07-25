#include "ft.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		if (ft_display_file(argv[1]) == 0)
			write(2, "Cannot read file.\n", 18);
	}
	return 0;
}