#include <stdlib.h>
#include "grid.h"
#include "ft.h"

int		main(void)
{
	t_grid_desc	*grid_desc;

	if ((grid_desc = read_description(0)) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}

	ft_putnbr(grid_desc->nline);
	ft_putchar(grid_desc->empty_c);
	ft_putchar(grid_desc->trap_c);
	ft_putchar(grid_desc->fill_c);
	return (0);
}
