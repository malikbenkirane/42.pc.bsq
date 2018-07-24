char		*solve_map(t_grid *grid)
{
	/*
	 ** XXX
	 */
}

t_dyn_int	get_opt_size(
		t_grid *grid,
		t_dyn_int posx, t_dyn_int posy);

void		set_opt_size(
		t_grid *grid,
		t_dyn_int posx, t_dyn_int posy, t_dyn_int val);

void		solve_bsq(
		t_grid *grid,
		t_dyn_int *size, t_dyn_int *posx, t_dyn_int *posy)
{
	t_dyn_int i;
	t_dyn_int j;

	i = 1;
	j = 1;
	while (i < grid->ncol && j <= grid->nline)
	{
		i = 1;
		while (i < grid->ncol)
		{
			size = get_min(grid, i, j);
			set_opt_size(grid, i, j, size);
			i++;
		}
		j++;
	}
}

t_dyn_int	get_min(t_grid *grid, t_dyn_int i, t_dyn_int j)
{
	t_dyn_int	left;
	t_dyn_int	above;
	t_dyn_int	diag;

	left = get_opt_square(grid, i - 1, j);
	above = get_opt_square(grid, i, j - 1);
	diag = get_opt_square(grid, i - 1, j - 1);
	return (MIN_3(left, above, diag));
}
