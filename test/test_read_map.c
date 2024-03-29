#include <stdlib.h>
#include "error.h"
#include "grid.h"
#include "read.h"
#include "ft.h"

int		main(void)
{
	t_grid_desc	*grid_desc;
	t_grid		*grid;
	t_read_cue	*r_cue;

	if ((r_cue = read_map(0, &grid_desc, &grid)) == NULL)
		exit_with_map_error();

	ft_putnbr(grid_desc->nline);
	ft_putchar(grid_desc->empty_c);
	ft_putchar(grid_desc->trap_c);
	ft_putchar(grid_desc->fill_c);

	write(1, r_cue->head, ft_strlen(r_cue->head));

	return (0);
}
