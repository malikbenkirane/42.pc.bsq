#include "grid_lines.h"

void		solve_map(t_grid *grid, char *map_str, t_grid_desc *grid_desc)
{
	t_bsq_solution	*solution;
	int 			offset;
	int 			counter;
	char			*ptr;

	solution = solve_bsq(grid);
	counter = 0;
	ptr = map_str + solution->argopt;
	while (counter < solution->opt)
	{
		offset = 0;
		while (offset > -(solution->opt))
		{
			ptr[offset] = grid_desc->fill_c;
			offset--;
		}
		ptr = ptr - grid_desc->ncol;
		counter ++;
	}
}

t_bsq_solution	*solve_bsq(t_grid *grid)
{
	t_dyn_int 		i;
	t_dyn_int 		j;
	t_dyn_int 		*size;
	t_bsq_solution	*solution;

	i = 1;
	j = 1;
	if (solution = init_bsq_solution())
		return (NULL);
	while (i < grid->ncol && j <= grid->nline)
	{
		i = 1;
		while (i < grid->ncol)
		{
			size = get_min(grid, i, j);
			if (size > max)
			{
				solution->opt = size;
				solution->argopt = j * grid->ncol + i;
			}
			set_opt_size(grid, i, j, size);
			i++;
		}
		j++;
	}
	return (solution);
}

t_dyn_int		get_min(t_grid *grid, t_dyn_int i, t_dyn_int j)
{
	t_dyn_int	left;
	t_dyn_int	above;
	t_dyn_int	diag;

	left = get_opt_square(grid, i - 1, j);
	above = get_opt_square(grid, i, j - 1);
	diag = get_opt_square(grid, i - 1, j - 1);
	return (MIN_3(left, above, diag));
}

t_bsq_solution	*init_bsq_solution()
{
	t_bsq_solution *solution;

	if ((solution = (t_bsq_solution *)malloc(sizeof(t_bsq_solution))) == NULL)
		return (NULL);
	solution->opt = 0;
	solution->argopt = 0;
	return (solution);
}
