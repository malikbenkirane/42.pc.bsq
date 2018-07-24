#include <fcntl.h>

int		main(int argc, char **argv)
{
	t_grid	*grid;
	int		index;	

	if (argc == 1)
	{
		read_map(stdin->_file);
		ft_putstr(solve_map(grid));
	}
	index = 1;
	while (index < argc)
	{
		grid = read_map(open(argv[index++]));
		ft_putstr(solve_map(grid));
	}
}
